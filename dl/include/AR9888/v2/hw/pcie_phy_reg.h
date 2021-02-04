//                                                                             
// File:       ./pcie_phy_reg_csr.vrh                                          
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:45:50 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             pcie_phy_reg_csr.rdl                                            
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/pcie_phy_ebu/rtl/blueprint/pcie_phy_reg_csr.rdl
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    sjod-chinghwa                                                   
// OS:         Linux 2.6.18-308.8.2.el5                                        
// Description:                                                                
//                                                                             
// No Description Provided                                                     
/*
 * Copyright (c) 2012-14 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */


#ifndef _PCIE_PHY_REG_CSR_H_
#define _PCIE_PHY_REG_CSR_H_
// 0x0000 (PCIE_PHY_REG_1)
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_MSB                          31
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_LSB                          31
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_MASK                         0x80000000
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_GET(x)                       (((x) & PCIE_PHY_REG_1_SERDES_DIS_RXIMP_MASK) >> PCIE_PHY_REG_1_SERDES_DIS_RXIMP_LSB)
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_SET(x)                       (((0 | (x)) << PCIE_PHY_REG_1_SERDES_DIS_RXIMP_LSB) & PCIE_PHY_REG_1_SERDES_DIS_RXIMP_MASK)
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_RESET                        0
#define PCIE_PHY_REG_1_SERDES_TXDR_CTRL_MSB                          30
#define PCIE_PHY_REG_1_SERDES_TXDR_CTRL_LSB                          29
#define PCIE_PHY_REG_1_SERDES_TXDR_CTRL_MASK                         0x60000000
#define PCIE_PHY_REG_1_SERDES_TXDR_CTRL_GET(x)                       (((x) & PCIE_PHY_REG_1_SERDES_TXDR_CTRL_MASK) >> PCIE_PHY_REG_1_SERDES_TXDR_CTRL_LSB)
#define PCIE_PHY_REG_1_SERDES_TXDR_CTRL_SET(x)                       (((0 | (x)) << PCIE_PHY_REG_1_SERDES_TXDR_CTRL_LSB) & PCIE_PHY_REG_1_SERDES_TXDR_CTRL_MASK)
#define PCIE_PHY_REG_1_SERDES_TXDR_CTRL_RESET                        0
#define PCIE_PHY_REG_1_PERSTDELAY_MSB                                28
#define PCIE_PHY_REG_1_PERSTDELAY_LSB                                27
#define PCIE_PHY_REG_1_PERSTDELAY_MASK                               0x18000000
#define PCIE_PHY_REG_1_PERSTDELAY_GET(x)                             (((x) & PCIE_PHY_REG_1_PERSTDELAY_MASK) >> PCIE_PHY_REG_1_PERSTDELAY_LSB)
#define PCIE_PHY_REG_1_PERSTDELAY_SET(x)                             (((0 | (x)) << PCIE_PHY_REG_1_PERSTDELAY_LSB) & PCIE_PHY_REG_1_PERSTDELAY_MASK)
#define PCIE_PHY_REG_1_PERSTDELAY_RESET                              2
#define PCIE_PHY_REG_1_CLKOBSSEL_MSB                                 26
#define PCIE_PHY_REG_1_CLKOBSSEL_LSB                                 25
#define PCIE_PHY_REG_1_CLKOBSSEL_MASK                                0x06000000
#define PCIE_PHY_REG_1_CLKOBSSEL_GET(x)                              (((x) & PCIE_PHY_REG_1_CLKOBSSEL_MASK) >> PCIE_PHY_REG_1_CLKOBSSEL_LSB)
#define PCIE_PHY_REG_1_CLKOBSSEL_SET(x)                              (((0 | (x)) << PCIE_PHY_REG_1_CLKOBSSEL_LSB) & PCIE_PHY_REG_1_CLKOBSSEL_MASK)
#define PCIE_PHY_REG_1_CLKOBSSEL_RESET                               0
#define PCIE_PHY_REG_1_DATAOBSEN_MSB                                 24
#define PCIE_PHY_REG_1_DATAOBSEN_LSB                                 24
#define PCIE_PHY_REG_1_DATAOBSEN_MASK                                0x01000000
#define PCIE_PHY_REG_1_DATAOBSEN_GET(x)                              (((x) & PCIE_PHY_REG_1_DATAOBSEN_MASK) >> PCIE_PHY_REG_1_DATAOBSEN_LSB)
#define PCIE_PHY_REG_1_DATAOBSEN_SET(x)                              (((0 | (x)) << PCIE_PHY_REG_1_DATAOBSEN_LSB) & PCIE_PHY_REG_1_DATAOBSEN_MASK)
#define PCIE_PHY_REG_1_DATAOBSEN_RESET                               0
#define PCIE_PHY_REG_1_FUNCTESTEN_MSB                                23
#define PCIE_PHY_REG_1_FUNCTESTEN_LSB                                23
#define PCIE_PHY_REG_1_FUNCTESTEN_MASK                               0x00800000
#define PCIE_PHY_REG_1_FUNCTESTEN_GET(x)                             (((x) & PCIE_PHY_REG_1_FUNCTESTEN_MASK) >> PCIE_PHY_REG_1_FUNCTESTEN_LSB)
#define PCIE_PHY_REG_1_FUNCTESTEN_SET(x)                             (((0 | (x)) << PCIE_PHY_REG_1_FUNCTESTEN_LSB) & PCIE_PHY_REG_1_FUNCTESTEN_MASK)
#define PCIE_PHY_REG_1_FUNCTESTEN_RESET                              0
#define PCIE_PHY_REG_1_SERDES_DISABLE_MSB                            22
#define PCIE_PHY_REG_1_SERDES_DISABLE_LSB                            22
#define PCIE_PHY_REG_1_SERDES_DISABLE_MASK                           0x00400000
#define PCIE_PHY_REG_1_SERDES_DISABLE_GET(x)                         (((x) & PCIE_PHY_REG_1_SERDES_DISABLE_MASK) >> PCIE_PHY_REG_1_SERDES_DISABLE_LSB)
#define PCIE_PHY_REG_1_SERDES_DISABLE_SET(x)                         (((0 | (x)) << PCIE_PHY_REG_1_SERDES_DISABLE_LSB) & PCIE_PHY_REG_1_SERDES_DISABLE_MASK)
#define PCIE_PHY_REG_1_SERDES_DISABLE_RESET                          0
#define PCIE_PHY_REG_1_RXCLKINV_MSB                                  21
#define PCIE_PHY_REG_1_RXCLKINV_LSB                                  21
#define PCIE_PHY_REG_1_RXCLKINV_MASK                                 0x00200000
#define PCIE_PHY_REG_1_RXCLKINV_GET(x)                               (((x) & PCIE_PHY_REG_1_RXCLKINV_MASK) >> PCIE_PHY_REG_1_RXCLKINV_LSB)
#define PCIE_PHY_REG_1_RXCLKINV_SET(x)                               (((0 | (x)) << PCIE_PHY_REG_1_RXCLKINV_LSB) & PCIE_PHY_REG_1_RXCLKINV_MASK)
#define PCIE_PHY_REG_1_RXCLKINV_RESET                                1
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_MSB                          20
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_LSB                          20
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_MASK                         0x00100000
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_GET(x)                       (((x) & PCIE_PHY_REG_1_FUNCTESTRXCLKINV_MASK) >> PCIE_PHY_REG_1_FUNCTESTRXCLKINV_LSB)
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_SET(x)                       (((0 | (x)) << PCIE_PHY_REG_1_FUNCTESTRXCLKINV_LSB) & PCIE_PHY_REG_1_FUNCTESTRXCLKINV_MASK)
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_RESET                        0
#define PCIE_PHY_REG_1_FUNCTESTTXCLKINV_MSB                          19
#define PCIE_PHY_REG_1_FUNCTESTTXCLKINV_LSB                          19
#define PCIE_PHY_REG_1_FUNCTESTTXCLKINV_MASK                         0x00080000
#define PCIE_PHY_REG_1_FUNCTESTTXCLKINV_GET(x)                       (((x) & PCIE_PHY_REG_1_FUNCTESTTXCLKINV_MASK) >> PCIE_PHY_REG_1_FUNCTESTTXCLKINV_LSB)
#define PCIE_PHY_REG_1_FUNCTESTTXCLKINV_SET(x)                       (((0 | (x)) << PCIE_PHY_REG_1_FUNCTESTTXCLKINV_LSB) & PCIE_PHY_REG_1_FUNCTESTTXCLKINV_MASK)
#define PCIE_PHY_REG_1_FUNCTESTTXCLKINV_RESET                        0
#define PCIE_PHY_REG_1_ENABLECLKREQ_MSB                              18
#define PCIE_PHY_REG_1_ENABLECLKREQ_LSB                              18
#define PCIE_PHY_REG_1_ENABLECLKREQ_MASK                             0x00040000
#define PCIE_PHY_REG_1_ENABLECLKREQ_GET(x)                           (((x) & PCIE_PHY_REG_1_ENABLECLKREQ_MASK) >> PCIE_PHY_REG_1_ENABLECLKREQ_LSB)
#define PCIE_PHY_REG_1_ENABLECLKREQ_SET(x)                           (((0 | (x)) << PCIE_PHY_REG_1_ENABLECLKREQ_LSB) & PCIE_PHY_REG_1_ENABLECLKREQ_MASK)
#define PCIE_PHY_REG_1_ENABLECLKREQ_RESET                            0
#define PCIE_PHY_REG_1_FORCELOOPBACK_MSB                             17
#define PCIE_PHY_REG_1_FORCELOOPBACK_LSB                             17
#define PCIE_PHY_REG_1_FORCELOOPBACK_MASK                            0x00020000
#define PCIE_PHY_REG_1_FORCELOOPBACK_GET(x)                          (((x) & PCIE_PHY_REG_1_FORCELOOPBACK_MASK) >> PCIE_PHY_REG_1_FORCELOOPBACK_LSB)
#define PCIE_PHY_REG_1_FORCELOOPBACK_SET(x)                          (((0 | (x)) << PCIE_PHY_REG_1_FORCELOOPBACK_LSB) & PCIE_PHY_REG_1_FORCELOOPBACK_MASK)
#define PCIE_PHY_REG_1_FORCELOOPBACK_RESET                           0
#define PCIE_PHY_REG_1_SEL_CLK_MSB                                   16
#define PCIE_PHY_REG_1_SEL_CLK_LSB                                   15
#define PCIE_PHY_REG_1_SEL_CLK_MASK                                  0x00018000
#define PCIE_PHY_REG_1_SEL_CLK_GET(x)                                (((x) & PCIE_PHY_REG_1_SEL_CLK_MASK) >> PCIE_PHY_REG_1_SEL_CLK_LSB)
#define PCIE_PHY_REG_1_SEL_CLK_SET(x)                                (((0 | (x)) << PCIE_PHY_REG_1_SEL_CLK_LSB) & PCIE_PHY_REG_1_SEL_CLK_MASK)
#define PCIE_PHY_REG_1_SEL_CLK_RESET                                 2
#define PCIE_PHY_REG_1_SERDES_RX_EQ_MSB                              14
#define PCIE_PHY_REG_1_SERDES_RX_EQ_LSB                              14
#define PCIE_PHY_REG_1_SERDES_RX_EQ_MASK                             0x00004000
#define PCIE_PHY_REG_1_SERDES_RX_EQ_GET(x)                           (((x) & PCIE_PHY_REG_1_SERDES_RX_EQ_MASK) >> PCIE_PHY_REG_1_SERDES_RX_EQ_LSB)
#define PCIE_PHY_REG_1_SERDES_RX_EQ_SET(x)                           (((0 | (x)) << PCIE_PHY_REG_1_SERDES_RX_EQ_LSB) & PCIE_PHY_REG_1_SERDES_RX_EQ_MASK)
#define PCIE_PHY_REG_1_SERDES_RX_EQ_RESET                            0
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_MSB                           13
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_LSB                           13
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_MASK                          0x00002000
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_GET(x)                        (((x) & PCIE_PHY_REG_1_SERDES_EN_LCKDT_MASK) >> PCIE_PHY_REG_1_SERDES_EN_LCKDT_LSB)
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_SET(x)                        (((0 | (x)) << PCIE_PHY_REG_1_SERDES_EN_LCKDT_LSB) & PCIE_PHY_REG_1_SERDES_EN_LCKDT_MASK)
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_RESET                         1
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_MSB                     12
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_LSB                     12
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_MASK                    0x00001000
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_GET(x)                  (((x) & PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_MASK) >> PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_LSB)
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_SET(x)                  (((0 | (x)) << PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_LSB) & PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_MASK)
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_RESET                   0
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_MSB                         11
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_LSB                         11
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_MASK                        0x00000800
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_GET(x)                      (((x) & PCIE_PHY_REG_1_SERDES_POWER_SAVE_MASK) >> PCIE_PHY_REG_1_SERDES_POWER_SAVE_LSB)
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_SET(x)                      (((0 | (x)) << PCIE_PHY_REG_1_SERDES_POWER_SAVE_LSB) & PCIE_PHY_REG_1_SERDES_POWER_SAVE_MASK)
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_RESET                       0
#define PCIE_PHY_REG_1_SERDES_CDR_BW_MSB                             10
#define PCIE_PHY_REG_1_SERDES_CDR_BW_LSB                             9
#define PCIE_PHY_REG_1_SERDES_CDR_BW_MASK                            0x00000600
#define PCIE_PHY_REG_1_SERDES_CDR_BW_GET(x)                          (((x) & PCIE_PHY_REG_1_SERDES_CDR_BW_MASK) >> PCIE_PHY_REG_1_SERDES_CDR_BW_LSB)
#define PCIE_PHY_REG_1_SERDES_CDR_BW_SET(x)                          (((0 | (x)) << PCIE_PHY_REG_1_SERDES_CDR_BW_LSB) & PCIE_PHY_REG_1_SERDES_CDR_BW_MASK)
#define PCIE_PHY_REG_1_SERDES_CDR_BW_RESET                           3
#define PCIE_PHY_REG_1_SERDES_TH_LOS_MSB                             8
#define PCIE_PHY_REG_1_SERDES_TH_LOS_LSB                             7
#define PCIE_PHY_REG_1_SERDES_TH_LOS_MASK                            0x00000180
#define PCIE_PHY_REG_1_SERDES_TH_LOS_GET(x)                          (((x) & PCIE_PHY_REG_1_SERDES_TH_LOS_MASK) >> PCIE_PHY_REG_1_SERDES_TH_LOS_LSB)
#define PCIE_PHY_REG_1_SERDES_TH_LOS_SET(x)                          (((0 | (x)) << PCIE_PHY_REG_1_SERDES_TH_LOS_LSB) & PCIE_PHY_REG_1_SERDES_TH_LOS_MASK)
#define PCIE_PHY_REG_1_SERDES_TH_LOS_RESET                           0
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_MSB                           6
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_LSB                           6
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_MASK                          0x00000040
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_GET(x)                        (((x) & PCIE_PHY_REG_1_SERDES_EN_DEEMP_MASK) >> PCIE_PHY_REG_1_SERDES_EN_DEEMP_LSB)
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_SET(x)                        (((0 | (x)) << PCIE_PHY_REG_1_SERDES_EN_DEEMP_LSB) & PCIE_PHY_REG_1_SERDES_EN_DEEMP_MASK)
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_RESET                         1
#define PCIE_PHY_REG_1_SERDES_HALFTXDR_MSB                           5
#define PCIE_PHY_REG_1_SERDES_HALFTXDR_LSB                           5
#define PCIE_PHY_REG_1_SERDES_HALFTXDR_MASK                          0x00000020
#define PCIE_PHY_REG_1_SERDES_HALFTXDR_GET(x)                        (((x) & PCIE_PHY_REG_1_SERDES_HALFTXDR_MASK) >> PCIE_PHY_REG_1_SERDES_HALFTXDR_LSB)
#define PCIE_PHY_REG_1_SERDES_HALFTXDR_SET(x)                        (((0 | (x)) << PCIE_PHY_REG_1_SERDES_HALFTXDR_LSB) & PCIE_PHY_REG_1_SERDES_HALFTXDR_MASK)
#define PCIE_PHY_REG_1_SERDES_HALFTXDR_RESET                         0
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_MSB                            4
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_LSB                            4
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_MASK                           0x00000010
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_GET(x)                         (((x) & PCIE_PHY_REG_1_SERDES_SEL_HSP_MASK) >> PCIE_PHY_REG_1_SERDES_SEL_HSP_LSB)
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_SET(x)                         (((0 | (x)) << PCIE_PHY_REG_1_SERDES_SEL_HSP_LSB) & PCIE_PHY_REG_1_SERDES_SEL_HSP_MASK)
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_RESET                          1
#define PCIE_PHY_REG_1_S_MSB                                         3
#define PCIE_PHY_REG_1_S_LSB                                         0
#define PCIE_PHY_REG_1_S_MASK                                        0x0000000f
#define PCIE_PHY_REG_1_S_GET(x)                                      (((x) & PCIE_PHY_REG_1_S_MASK) >> PCIE_PHY_REG_1_S_LSB)
#define PCIE_PHY_REG_1_S_SET(x)                                      (((0 | (x)) << PCIE_PHY_REG_1_S_LSB) & PCIE_PHY_REG_1_S_MASK)
#define PCIE_PHY_REG_1_S_RESET                                       14
#define PCIE_PHY_REG_1_ADDRESS                                       0x0000
#define PCIE_PHY_REG_1_HW_MASK                                       0xffffffff
#define PCIE_PHY_REG_1_SW_MASK                                       0xffffffff
#define PCIE_PHY_REG_1_HW_WRITE_MASK                                 0x00000000
#define PCIE_PHY_REG_1_SW_WRITE_MASK                                 0xffffffff
#define PCIE_PHY_REG_1_RSTMASK                                       0xffffffff
#define PCIE_PHY_REG_1_RESET                                         0x1021265e

// 0x0004 (PCIE_PHY_REG_2)
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_MSB                          31
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_LSB                          24
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_MASK                         0xff000000
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_GET(x)                       (((x) & PCIE_PHY_REG_2_PRBS_ERROR_COUNT_MASK) >> PCIE_PHY_REG_2_PRBS_ERROR_COUNT_LSB)
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_SET(x)                       (((0 | (x)) << PCIE_PHY_REG_2_PRBS_ERROR_COUNT_LSB) & PCIE_PHY_REG_2_PRBS_ERROR_COUNT_MASK)
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_RESET                        0
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_MSB                        23
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_LSB                        23
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_MASK                       0x00800000
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_GET(x)                     (((x) & PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_MASK) >> PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_LSB)
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_SET(x)                     (((0 | (x)) << PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_LSB) & PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_MASK)
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_RESET                      0
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_MSB                        22
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_LSB                        22
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_MASK                       0x00400000
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_GET(x)                     (((x) & PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_MASK) >> PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_LSB)
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_SET(x)                     (((0 | (x)) << PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_LSB) & PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_MASK)
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_RESET                      0
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_MSB                             21
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_LSB                             21
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_MASK                            0x00200000
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_GET(x)                          (((x) & PCIE_PHY_REG_2_PRBS_SCRAMBLE_MASK) >> PCIE_PHY_REG_2_PRBS_SCRAMBLE_LSB)
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_SET(x)                          (((0 | (x)) << PCIE_PHY_REG_2_PRBS_SCRAMBLE_LSB) & PCIE_PHY_REG_2_PRBS_SCRAMBLE_MASK)
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_RESET                           0
#define PCIE_PHY_REG_2_PRBS_START_MSB                                20
#define PCIE_PHY_REG_2_PRBS_START_LSB                                20
#define PCIE_PHY_REG_2_PRBS_START_MASK                               0x00100000
#define PCIE_PHY_REG_2_PRBS_START_GET(x)                             (((x) & PCIE_PHY_REG_2_PRBS_START_MASK) >> PCIE_PHY_REG_2_PRBS_START_LSB)
#define PCIE_PHY_REG_2_PRBS_START_SET(x)                             (((0 | (x)) << PCIE_PHY_REG_2_PRBS_START_LSB) & PCIE_PHY_REG_2_PRBS_START_MASK)
#define PCIE_PHY_REG_2_PRBS_START_RESET                              0
#define PCIE_PHY_REG_2_PRBS_TS_NUM_MSB                               19
#define PCIE_PHY_REG_2_PRBS_TS_NUM_LSB                               13
#define PCIE_PHY_REG_2_PRBS_TS_NUM_MASK                              0x000fe000
#define PCIE_PHY_REG_2_PRBS_TS_NUM_GET(x)                            (((x) & PCIE_PHY_REG_2_PRBS_TS_NUM_MASK) >> PCIE_PHY_REG_2_PRBS_TS_NUM_LSB)
#define PCIE_PHY_REG_2_PRBS_TS_NUM_SET(x)                            (((0 | (x)) << PCIE_PHY_REG_2_PRBS_TS_NUM_LSB) & PCIE_PHY_REG_2_PRBS_TS_NUM_MASK)
#define PCIE_PHY_REG_2_PRBS_TS_NUM_RESET                             64
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_MSB                           12
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_LSB                           12
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_MASK                          0x00001000
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_GET(x)                        (((x) & PCIE_PHY_REG_2_TXDETRXOVRVALUE_MASK) >> PCIE_PHY_REG_2_TXDETRXOVRVALUE_LSB)
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_SET(x)                        (((0 | (x)) << PCIE_PHY_REG_2_TXDETRXOVRVALUE_LSB) & PCIE_PHY_REG_2_TXDETRXOVRVALUE_MASK)
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_RESET                         0
#define PCIE_PHY_REG_2_TXDETRXOVREN_MSB                              11
#define PCIE_PHY_REG_2_TXDETRXOVREN_LSB                              11
#define PCIE_PHY_REG_2_TXDETRXOVREN_MASK                             0x00000800
#define PCIE_PHY_REG_2_TXDETRXOVREN_GET(x)                           (((x) & PCIE_PHY_REG_2_TXDETRXOVREN_MASK) >> PCIE_PHY_REG_2_TXDETRXOVREN_LSB)
#define PCIE_PHY_REG_2_TXDETRXOVREN_SET(x)                           (((0 | (x)) << PCIE_PHY_REG_2_TXDETRXOVREN_LSB) & PCIE_PHY_REG_2_TXDETRXOVREN_MASK)
#define PCIE_PHY_REG_2_TXDETRXOVREN_RESET                            0
#define PCIE_PHY_REG_2_DATAOBSPRBSERR_MSB                            10
#define PCIE_PHY_REG_2_DATAOBSPRBSERR_LSB                            10
#define PCIE_PHY_REG_2_DATAOBSPRBSERR_MASK                           0x00000400
#define PCIE_PHY_REG_2_DATAOBSPRBSERR_GET(x)                         (((x) & PCIE_PHY_REG_2_DATAOBSPRBSERR_MASK) >> PCIE_PHY_REG_2_DATAOBSPRBSERR_LSB)
#define PCIE_PHY_REG_2_DATAOBSPRBSERR_SET(x)                         (((0 | (x)) << PCIE_PHY_REG_2_DATAOBSPRBSERR_LSB) & PCIE_PHY_REG_2_DATAOBSPRBSERR_MASK)
#define PCIE_PHY_REG_2_DATAOBSPRBSERR_RESET                          0
#define PCIE_PHY_REG_2_CDRREADYTIMER_MSB                             9
#define PCIE_PHY_REG_2_CDRREADYTIMER_LSB                             6
#define PCIE_PHY_REG_2_CDRREADYTIMER_MASK                            0x000003c0
#define PCIE_PHY_REG_2_CDRREADYTIMER_GET(x)                          (((x) & PCIE_PHY_REG_2_CDRREADYTIMER_MASK) >> PCIE_PHY_REG_2_CDRREADYTIMER_LSB)
#define PCIE_PHY_REG_2_CDRREADYTIMER_SET(x)                          (((0 | (x)) << PCIE_PHY_REG_2_CDRREADYTIMER_LSB) & PCIE_PHY_REG_2_CDRREADYTIMER_MASK)
#define PCIE_PHY_REG_2_CDRREADYTIMER_RESET                           7
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_MSB                        5
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_LSB                        1
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_MASK                       0x0000003e
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_GET(x)                     (((x) & PCIE_PHY_REG_2_TXDETRXTARGETDELAY_MASK) >> PCIE_PHY_REG_2_TXDETRXTARGETDELAY_LSB)
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_SET(x)                     (((0 | (x)) << PCIE_PHY_REG_2_TXDETRXTARGETDELAY_LSB) & PCIE_PHY_REG_2_TXDETRXTARGETDELAY_MASK)
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_RESET                      12
#define PCIE_PHY_REG_2_FORCEDETECT_MSB                               0
#define PCIE_PHY_REG_2_FORCEDETECT_LSB                               0
#define PCIE_PHY_REG_2_FORCEDETECT_MASK                              0x00000001
#define PCIE_PHY_REG_2_FORCEDETECT_GET(x)                            (((x) & PCIE_PHY_REG_2_FORCEDETECT_MASK) >> PCIE_PHY_REG_2_FORCEDETECT_LSB)
#define PCIE_PHY_REG_2_FORCEDETECT_SET(x)                            (((0 | (x)) << PCIE_PHY_REG_2_FORCEDETECT_LSB) & PCIE_PHY_REG_2_FORCEDETECT_MASK)
#define PCIE_PHY_REG_2_FORCEDETECT_RESET                             0
#define PCIE_PHY_REG_2_ADDRESS                                       0x0004
#define PCIE_PHY_REG_2_HW_MASK                                       0xffffffff
#define PCIE_PHY_REG_2_SW_MASK                                       0xffffffff
#define PCIE_PHY_REG_2_HW_WRITE_MASK                                 0xffc00000
#define PCIE_PHY_REG_2_SW_WRITE_MASK                                 0x003fffff
#define PCIE_PHY_REG_2_RSTMASK                                       0xffffffff
#define PCIE_PHY_REG_2_RESET                                         0x000801d8

// 0x0008 (PCIE_PHY_REG_3)
#define PCIE_PHY_REG_3_SERDES_REG_MSB                                20
#define PCIE_PHY_REG_3_SERDES_REG_LSB                                16
#define PCIE_PHY_REG_3_SERDES_REG_MASK                               0x001f0000
#define PCIE_PHY_REG_3_SERDES_REG_GET(x)                             (((x) & PCIE_PHY_REG_3_SERDES_REG_MASK) >> PCIE_PHY_REG_3_SERDES_REG_LSB)
#define PCIE_PHY_REG_3_SERDES_REG_SET(x)                             (((0 | (x)) << PCIE_PHY_REG_3_SERDES_REG_LSB) & PCIE_PHY_REG_3_SERDES_REG_MASK)
#define PCIE_PHY_REG_3_SERDES_REG_RESET                              0
#define PCIE_PHY_REG_3_SPARE_MSB                                     15
#define PCIE_PHY_REG_3_SPARE_LSB                                     11
#define PCIE_PHY_REG_3_SPARE_MASK                                    0x0000f800
#define PCIE_PHY_REG_3_SPARE_GET(x)                                  (((x) & PCIE_PHY_REG_3_SPARE_MASK) >> PCIE_PHY_REG_3_SPARE_LSB)
#define PCIE_PHY_REG_3_SPARE_SET(x)                                  (((0 | (x)) << PCIE_PHY_REG_3_SPARE_LSB) & PCIE_PHY_REG_3_SPARE_MASK)
#define PCIE_PHY_REG_3_SPARE_RESET                                   15
#define PCIE_PHY_REG_3_SEL_CLK100_MSB                                10
#define PCIE_PHY_REG_3_SEL_CLK100_LSB                                10
#define PCIE_PHY_REG_3_SEL_CLK100_MASK                               0x00000400
#define PCIE_PHY_REG_3_SEL_CLK100_GET(x)                             (((x) & PCIE_PHY_REG_3_SEL_CLK100_MASK) >> PCIE_PHY_REG_3_SEL_CLK100_LSB)
#define PCIE_PHY_REG_3_SEL_CLK100_SET(x)                             (((0 | (x)) << PCIE_PHY_REG_3_SEL_CLK100_LSB) & PCIE_PHY_REG_3_SEL_CLK100_MASK)
#define PCIE_PHY_REG_3_SEL_CLK100_RESET                              0
#define PCIE_PHY_REG_3_EN_BEACONGEN_MSB                              9
#define PCIE_PHY_REG_3_EN_BEACONGEN_LSB                              9
#define PCIE_PHY_REG_3_EN_BEACONGEN_MASK                             0x00000200
#define PCIE_PHY_REG_3_EN_BEACONGEN_GET(x)                           (((x) & PCIE_PHY_REG_3_EN_BEACONGEN_MASK) >> PCIE_PHY_REG_3_EN_BEACONGEN_LSB)
#define PCIE_PHY_REG_3_EN_BEACONGEN_SET(x)                           (((0 | (x)) << PCIE_PHY_REG_3_EN_BEACONGEN_LSB) & PCIE_PHY_REG_3_EN_BEACONGEN_MASK)
#define PCIE_PHY_REG_3_EN_BEACONGEN_RESET                            0
#define PCIE_PHY_REG_3_TXELECIDLE_MSB                                8
#define PCIE_PHY_REG_3_TXELECIDLE_LSB                                8
#define PCIE_PHY_REG_3_TXELECIDLE_MASK                               0x00000100
#define PCIE_PHY_REG_3_TXELECIDLE_GET(x)                             (((x) & PCIE_PHY_REG_3_TXELECIDLE_MASK) >> PCIE_PHY_REG_3_TXELECIDLE_LSB)
#define PCIE_PHY_REG_3_TXELECIDLE_SET(x)                             (((0 | (x)) << PCIE_PHY_REG_3_TXELECIDLE_LSB) & PCIE_PHY_REG_3_TXELECIDLE_MASK)
#define PCIE_PHY_REG_3_TXELECIDLE_RESET                              0
#define PCIE_PHY_REG_3_SEL_CLK_MSB                                   7
#define PCIE_PHY_REG_3_SEL_CLK_LSB                                   6
#define PCIE_PHY_REG_3_SEL_CLK_MASK                                  0x000000c0
#define PCIE_PHY_REG_3_SEL_CLK_GET(x)                                (((x) & PCIE_PHY_REG_3_SEL_CLK_MASK) >> PCIE_PHY_REG_3_SEL_CLK_LSB)
#define PCIE_PHY_REG_3_SEL_CLK_SET(x)                                (((0 | (x)) << PCIE_PHY_REG_3_SEL_CLK_LSB) & PCIE_PHY_REG_3_SEL_CLK_MASK)
#define PCIE_PHY_REG_3_SEL_CLK_RESET                                 0
#define PCIE_PHY_REG_3_RX_DET_REQ_MSB                                5
#define PCIE_PHY_REG_3_RX_DET_REQ_LSB                                5
#define PCIE_PHY_REG_3_RX_DET_REQ_MASK                               0x00000020
#define PCIE_PHY_REG_3_RX_DET_REQ_GET(x)                             (((x) & PCIE_PHY_REG_3_RX_DET_REQ_MASK) >> PCIE_PHY_REG_3_RX_DET_REQ_LSB)
#define PCIE_PHY_REG_3_RX_DET_REQ_SET(x)                             (((0 | (x)) << PCIE_PHY_REG_3_RX_DET_REQ_LSB) & PCIE_PHY_REG_3_RX_DET_REQ_MASK)
#define PCIE_PHY_REG_3_RX_DET_REQ_RESET                              0
#define PCIE_PHY_REG_3_MODE_OCLK_IN_MSB                              4
#define PCIE_PHY_REG_3_MODE_OCLK_IN_LSB                              4
#define PCIE_PHY_REG_3_MODE_OCLK_IN_MASK                             0x00000010
#define PCIE_PHY_REG_3_MODE_OCLK_IN_GET(x)                           (((x) & PCIE_PHY_REG_3_MODE_OCLK_IN_MASK) >> PCIE_PHY_REG_3_MODE_OCLK_IN_LSB)
#define PCIE_PHY_REG_3_MODE_OCLK_IN_SET(x)                           (((0 | (x)) << PCIE_PHY_REG_3_MODE_OCLK_IN_LSB) & PCIE_PHY_REG_3_MODE_OCLK_IN_MASK)
#define PCIE_PHY_REG_3_MODE_OCLK_IN_RESET                            0
#define PCIE_PHY_REG_3_EN_PLL_MSB                                    3
#define PCIE_PHY_REG_3_EN_PLL_LSB                                    3
#define PCIE_PHY_REG_3_EN_PLL_MASK                                   0x00000008
#define PCIE_PHY_REG_3_EN_PLL_GET(x)                                 (((x) & PCIE_PHY_REG_3_EN_PLL_MASK) >> PCIE_PHY_REG_3_EN_PLL_LSB)
#define PCIE_PHY_REG_3_EN_PLL_SET(x)                                 (((0 | (x)) << PCIE_PHY_REG_3_EN_PLL_LSB) & PCIE_PHY_REG_3_EN_PLL_MASK)
#define PCIE_PHY_REG_3_EN_PLL_RESET                                  1
#define PCIE_PHY_REG_3_EN_LCKDT_MSB                                  2
#define PCIE_PHY_REG_3_EN_LCKDT_LSB                                  2
#define PCIE_PHY_REG_3_EN_LCKDT_MASK                                 0x00000004
#define PCIE_PHY_REG_3_EN_LCKDT_GET(x)                               (((x) & PCIE_PHY_REG_3_EN_LCKDT_MASK) >> PCIE_PHY_REG_3_EN_LCKDT_LSB)
#define PCIE_PHY_REG_3_EN_LCKDT_SET(x)                               (((0 | (x)) << PCIE_PHY_REG_3_EN_LCKDT_LSB) & PCIE_PHY_REG_3_EN_LCKDT_MASK)
#define PCIE_PHY_REG_3_EN_LCKDT_RESET                                1
#define PCIE_PHY_REG_3_EN_BUFS_RX_MSB                                1
#define PCIE_PHY_REG_3_EN_BUFS_RX_LSB                                1
#define PCIE_PHY_REG_3_EN_BUFS_RX_MASK                               0x00000002
#define PCIE_PHY_REG_3_EN_BUFS_RX_GET(x)                             (((x) & PCIE_PHY_REG_3_EN_BUFS_RX_MASK) >> PCIE_PHY_REG_3_EN_BUFS_RX_LSB)
#define PCIE_PHY_REG_3_EN_BUFS_RX_SET(x)                             (((0 | (x)) << PCIE_PHY_REG_3_EN_BUFS_RX_LSB) & PCIE_PHY_REG_3_EN_BUFS_RX_MASK)
#define PCIE_PHY_REG_3_EN_BUFS_RX_RESET                              0
#define PCIE_PHY_REG_3_EN_MSB                                        0
#define PCIE_PHY_REG_3_EN_LSB                                        0
#define PCIE_PHY_REG_3_EN_MASK                                       0x00000001
#define PCIE_PHY_REG_3_EN_GET(x)                                     (((x) & PCIE_PHY_REG_3_EN_MASK) >> PCIE_PHY_REG_3_EN_LSB)
#define PCIE_PHY_REG_3_EN_SET(x)                                     (((0 | (x)) << PCIE_PHY_REG_3_EN_LSB) & PCIE_PHY_REG_3_EN_MASK)
#define PCIE_PHY_REG_3_EN_RESET                                      0
#define PCIE_PHY_REG_3_ADDRESS                                       0x0008
#define PCIE_PHY_REG_3_HW_MASK                                       0x001fffff
#define PCIE_PHY_REG_3_SW_MASK                                       0x001fffff
#define PCIE_PHY_REG_3_HW_WRITE_MASK                                 0x00000000
#define PCIE_PHY_REG_3_SW_WRITE_MASK                                 0x001fffff
#define PCIE_PHY_REG_3_RSTMASK                                       0xffffffff
#define PCIE_PHY_REG_3_RESET                                         0x0000780c


#endif /* _PCIE_PHY_REG_CSR_H_ */
