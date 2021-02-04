/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CHN0_CHAIN_BIAS_REG_CSR_H_
#define _CHN0_CHAIN_BIAS_REG_CSR_H_


#ifndef __CHN0_CHAIN_BIAS_REG_CSR_BASE_ADDRESS
#define __CHN0_CHAIN_BIAS_REG_CSR_BASE_ADDRESS (0x481c0)
#endif


// 0x0 (CHN0_CH_BIAS0)
#define CHN0_CH_BIAS0_EN_BIAS_OVR_LSB                                          31
#define CHN0_CH_BIAS0_EN_BIAS_OVR_MSB                                          31
#define CHN0_CH_BIAS0_EN_BIAS_OVR_MASK                                         0x80000000
#define CHN0_CH_BIAS0_EN_BIAS_OVR_GET(x)                                       (((x) & CHN0_CH_BIAS0_EN_BIAS_OVR_MASK) >> CHN0_CH_BIAS0_EN_BIAS_OVR_LSB)
#define CHN0_CH_BIAS0_EN_BIAS_OVR_SET(x)                                       (((0 | (x)) << CHN0_CH_BIAS0_EN_BIAS_OVR_LSB) & CHN0_CH_BIAS0_EN_BIAS_OVR_MASK)
#define CHN0_CH_BIAS0_EN_BIAS_OVR_RESET                                        0x0
#define CHN0_CH_BIAS0_EN_CHAIN_BIAS_LS_LSB                                     30
#define CHN0_CH_BIAS0_EN_CHAIN_BIAS_LS_MSB                                     30
#define CHN0_CH_BIAS0_EN_CHAIN_BIAS_LS_MASK                                    0x40000000
#define CHN0_CH_BIAS0_EN_CHAIN_BIAS_LS_GET(x)                                  (((x) & CHN0_CH_BIAS0_EN_CHAIN_BIAS_LS_MASK) >> CHN0_CH_BIAS0_EN_CHAIN_BIAS_LS_LSB)
#define CHN0_CH_BIAS0_EN_CHAIN_BIAS_LS_SET(x)                                  (((0 | (x)) << CHN0_CH_BIAS0_EN_CHAIN_BIAS_LS_LSB) & CHN0_CH_BIAS0_EN_CHAIN_BIAS_LS_MASK)
#define CHN0_CH_BIAS0_EN_CHAIN_BIAS_LS_RESET                                   0x0
#define CHN0_CH_BIAS0_EN_LO_BIAS_LS_LSB                                        29
#define CHN0_CH_BIAS0_EN_LO_BIAS_LS_MSB                                        29
#define CHN0_CH_BIAS0_EN_LO_BIAS_LS_MASK                                       0x20000000
#define CHN0_CH_BIAS0_EN_LO_BIAS_LS_GET(x)                                     (((x) & CHN0_CH_BIAS0_EN_LO_BIAS_LS_MASK) >> CHN0_CH_BIAS0_EN_LO_BIAS_LS_LSB)
#define CHN0_CH_BIAS0_EN_LO_BIAS_LS_SET(x)                                     (((0 | (x)) << CHN0_CH_BIAS0_EN_LO_BIAS_LS_LSB) & CHN0_CH_BIAS0_EN_LO_BIAS_LS_MASK)
#define CHN0_CH_BIAS0_EN_LO_BIAS_LS_RESET                                      0x0
#define CHN0_CH_BIAS0_EN_CLKDRV_BIAS_LS_LSB                                    28
#define CHN0_CH_BIAS0_EN_CLKDRV_BIAS_LS_MSB                                    28
#define CHN0_CH_BIAS0_EN_CLKDRV_BIAS_LS_MASK                                   0x10000000
#define CHN0_CH_BIAS0_EN_CLKDRV_BIAS_LS_GET(x)                                 (((x) & CHN0_CH_BIAS0_EN_CLKDRV_BIAS_LS_MASK) >> CHN0_CH_BIAS0_EN_CLKDRV_BIAS_LS_LSB)
#define CHN0_CH_BIAS0_EN_CLKDRV_BIAS_LS_SET(x)                                 (((0 | (x)) << CHN0_CH_BIAS0_EN_CLKDRV_BIAS_LS_LSB) & CHN0_CH_BIAS0_EN_CLKDRV_BIAS_LS_MASK)
#define CHN0_CH_BIAS0_EN_CLKDRV_BIAS_LS_RESET                                  0x0
#define CHN0_CH_BIAS0_ISEL_IC_LSB                                              25
#define CHN0_CH_BIAS0_ISEL_IC_MSB                                              27
#define CHN0_CH_BIAS0_ISEL_IC_MASK                                             0xe000000
#define CHN0_CH_BIAS0_ISEL_IC_GET(x)                                           (((x) & CHN0_CH_BIAS0_ISEL_IC_MASK) >> CHN0_CH_BIAS0_ISEL_IC_LSB)
#define CHN0_CH_BIAS0_ISEL_IC_SET(x)                                           (((0 | (x)) << CHN0_CH_BIAS0_ISEL_IC_LSB) & CHN0_CH_BIAS0_ISEL_IC_MASK)
#define CHN0_CH_BIAS0_ISEL_IC_RESET                                            0x3
#define CHN0_CH_BIAS0_ISEL_IR_LSB                                              22
#define CHN0_CH_BIAS0_ISEL_IR_MSB                                              24
#define CHN0_CH_BIAS0_ISEL_IR_MASK                                             0x1c00000
#define CHN0_CH_BIAS0_ISEL_IR_GET(x)                                           (((x) & CHN0_CH_BIAS0_ISEL_IR_MASK) >> CHN0_CH_BIAS0_ISEL_IR_LSB)
#define CHN0_CH_BIAS0_ISEL_IR_SET(x)                                           (((0 | (x)) << CHN0_CH_BIAS0_ISEL_IR_LSB) & CHN0_CH_BIAS0_ISEL_IR_MASK)
#define CHN0_CH_BIAS0_ISEL_IR_RESET                                            0x3
#define CHN0_CH_BIAS0_ISEL_IPTAT_LSB                                           19
#define CHN0_CH_BIAS0_ISEL_IPTAT_MSB                                           21
#define CHN0_CH_BIAS0_ISEL_IPTAT_MASK                                          0x380000
#define CHN0_CH_BIAS0_ISEL_IPTAT_GET(x)                                        (((x) & CHN0_CH_BIAS0_ISEL_IPTAT_MASK) >> CHN0_CH_BIAS0_ISEL_IPTAT_LSB)
#define CHN0_CH_BIAS0_ISEL_IPTAT_SET(x)                                        (((0 | (x)) << CHN0_CH_BIAS0_ISEL_IPTAT_LSB) & CHN0_CH_BIAS0_ISEL_IPTAT_MASK)
#define CHN0_CH_BIAS0_ISEL_IPTAT_RESET                                         0x3
#define CHN0_CH_BIAS0_ISEL_ATBSEL_LSB                                          16
#define CHN0_CH_BIAS0_ISEL_ATBSEL_MSB                                          18
#define CHN0_CH_BIAS0_ISEL_ATBSEL_MASK                                         0x70000
#define CHN0_CH_BIAS0_ISEL_ATBSEL_GET(x)                                       (((x) & CHN0_CH_BIAS0_ISEL_ATBSEL_MASK) >> CHN0_CH_BIAS0_ISEL_ATBSEL_LSB)
#define CHN0_CH_BIAS0_ISEL_ATBSEL_SET(x)                                       (((0 | (x)) << CHN0_CH_BIAS0_ISEL_ATBSEL_LSB) & CHN0_CH_BIAS0_ISEL_ATBSEL_MASK)
#define CHN0_CH_BIAS0_ISEL_ATBSEL_RESET                                        0x0
#define CHN0_CH_BIAS0_ISEL_IPT25_TPC_LSB                                       13
#define CHN0_CH_BIAS0_ISEL_IPT25_TPC_MSB                                       15
#define CHN0_CH_BIAS0_ISEL_IPT25_TPC_MASK                                      0xe000
#define CHN0_CH_BIAS0_ISEL_IPT25_TPC_GET(x)                                    (((x) & CHN0_CH_BIAS0_ISEL_IPT25_TPC_MASK) >> CHN0_CH_BIAS0_ISEL_IPT25_TPC_LSB)
#define CHN0_CH_BIAS0_ISEL_IPT25_TPC_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS0_ISEL_IPT25_TPC_LSB) & CHN0_CH_BIAS0_ISEL_IPT25_TPC_MASK)
#define CHN0_CH_BIAS0_ISEL_IPT25_TPC_RESET                                     0x3
#define CHN0_CH_BIAS0_ISEL_IPT25_RXBB_LSB                                      10
#define CHN0_CH_BIAS0_ISEL_IPT25_RXBB_MSB                                      12
#define CHN0_CH_BIAS0_ISEL_IPT25_RXBB_MASK                                     0x1c00
#define CHN0_CH_BIAS0_ISEL_IPT25_RXBB_GET(x)                                   (((x) & CHN0_CH_BIAS0_ISEL_IPT25_RXBB_MASK) >> CHN0_CH_BIAS0_ISEL_IPT25_RXBB_LSB)
#define CHN0_CH_BIAS0_ISEL_IPT25_RXBB_SET(x)                                   (((0 | (x)) << CHN0_CH_BIAS0_ISEL_IPT25_RXBB_LSB) & CHN0_CH_BIAS0_ISEL_IPT25_RXBB_MASK)
#define CHN0_CH_BIAS0_ISEL_IPT25_RXBB_RESET                                    0x3
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA5_NGM_LSB                                  7
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA5_NGM_MSB                                  9
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA5_NGM_MASK                                 0x380
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA5_NGM_GET(x)                               (((x) & CHN0_CH_BIAS0_ISEL_IPT25_LNA5_NGM_MASK) >> CHN0_CH_BIAS0_ISEL_IPT25_LNA5_NGM_LSB)
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA5_NGM_SET(x)                               (((0 | (x)) << CHN0_CH_BIAS0_ISEL_IPT25_LNA5_NGM_LSB) & CHN0_CH_BIAS0_ISEL_IPT25_LNA5_NGM_MASK)
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA5_NGM_RESET                                0x3
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA2_NGM_LSB                                  4
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA2_NGM_MSB                                  6
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA2_NGM_MASK                                 0x70
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA2_NGM_GET(x)                               (((x) & CHN0_CH_BIAS0_ISEL_IPT25_LNA2_NGM_MASK) >> CHN0_CH_BIAS0_ISEL_IPT25_LNA2_NGM_LSB)
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA2_NGM_SET(x)                               (((0 | (x)) << CHN0_CH_BIAS0_ISEL_IPT25_LNA2_NGM_LSB) & CHN0_CH_BIAS0_ISEL_IPT25_LNA2_NGM_MASK)
#define CHN0_CH_BIAS0_ISEL_IPT25_LNA2_NGM_RESET                                0x3
#define CHN0_CH_BIAS0_CHAIN_BIAS_SPARE_0_LSB                                   0
#define CHN0_CH_BIAS0_CHAIN_BIAS_SPARE_0_MSB                                   3
#define CHN0_CH_BIAS0_CHAIN_BIAS_SPARE_0_MASK                                  0xf
#define CHN0_CH_BIAS0_CHAIN_BIAS_SPARE_0_GET(x)                                (((x) & CHN0_CH_BIAS0_CHAIN_BIAS_SPARE_0_MASK) >> CHN0_CH_BIAS0_CHAIN_BIAS_SPARE_0_LSB)
#define CHN0_CH_BIAS0_CHAIN_BIAS_SPARE_0_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS0_CHAIN_BIAS_SPARE_0_LSB) & CHN0_CH_BIAS0_CHAIN_BIAS_SPARE_0_MASK)
#define CHN0_CH_BIAS0_CHAIN_BIAS_SPARE_0_RESET                                 0x0
#define CHN0_CH_BIAS0_ADDRESS                                                  (0x0 + __CHN0_CHAIN_BIAS_REG_CSR_BASE_ADDRESS)
#define CHN0_CH_BIAS0_RSTMASK                                                  0xffffffff
#define CHN0_CH_BIAS0_RESET                                                    0x6d86db0

// 0x4 (CHN0_CH_BIAS1)
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_2_LSB                                   29
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_2_MSB                                   31
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_2_MASK                                  0xe0000000
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_2_GET(x)                                (((x) & CHN0_CH_BIAS1_ISEL_IC25_LOGM75_2_MASK) >> CHN0_CH_BIAS1_ISEL_IC25_LOGM75_2_LSB)
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_2_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS1_ISEL_IC25_LOGM75_2_LSB) & CHN0_CH_BIAS1_ISEL_IC25_LOGM75_2_MASK)
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_2_RESET                                 0x3
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_1_LSB                                   26
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_1_MSB                                   28
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_1_MASK                                  0x1c000000
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_1_GET(x)                                (((x) & CHN0_CH_BIAS1_ISEL_IC25_LOGM75_1_MASK) >> CHN0_CH_BIAS1_ISEL_IC25_LOGM75_1_LSB)
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_1_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS1_ISEL_IC25_LOGM75_1_LSB) & CHN0_CH_BIAS1_ISEL_IC25_LOGM75_1_MASK)
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_1_RESET                                 0x3
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_0_LSB                                   23
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_0_MSB                                   25
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_0_MASK                                  0x3800000
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_0_GET(x)                                (((x) & CHN0_CH_BIAS1_ISEL_IC25_LOGM75_0_MASK) >> CHN0_CH_BIAS1_ISEL_IC25_LOGM75_0_LSB)
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_0_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS1_ISEL_IC25_LOGM75_0_LSB) & CHN0_CH_BIAS1_ISEL_IC25_LOGM75_0_MASK)
#define CHN0_CH_BIAS1_ISEL_IC25_LOGM75_0_RESET                                 0x3
#define CHN0_CH_BIAS1_ISEL_IC25_CASBIAS_DA2_LSB                                20
#define CHN0_CH_BIAS1_ISEL_IC25_CASBIAS_DA2_MSB                                22
#define CHN0_CH_BIAS1_ISEL_IC25_CASBIAS_DA2_MASK                               0x700000
#define CHN0_CH_BIAS1_ISEL_IC25_CASBIAS_DA2_GET(x)                             (((x) & CHN0_CH_BIAS1_ISEL_IC25_CASBIAS_DA2_MASK) >> CHN0_CH_BIAS1_ISEL_IC25_CASBIAS_DA2_LSB)
#define CHN0_CH_BIAS1_ISEL_IC25_CASBIAS_DA2_SET(x)                             (((0 | (x)) << CHN0_CH_BIAS1_ISEL_IC25_CASBIAS_DA2_LSB) & CHN0_CH_BIAS1_ISEL_IC25_CASBIAS_DA2_MASK)
#define CHN0_CH_BIAS1_ISEL_IC25_CASBIAS_DA2_RESET                              0x3
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_1_LSB                               17
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_1_MSB                               19
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_1_MASK                              0xe0000
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_1_GET(x)                            (((x) & CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_1_MASK) >> CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_1_LSB)
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_1_SET(x)                            (((0 | (x)) << CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_1_LSB) & CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_1_MASK)
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_1_RESET                             0x3
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_0_LSB                               14
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_0_MSB                               16
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_0_MASK                              0x1c000
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_0_GET(x)                            (((x) & CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_0_MASK) >> CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_0_LSB)
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_0_SET(x)                            (((0 | (x)) << CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_0_LSB) & CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_0_MASK)
#define CHN0_CH_BIAS1_ISEL_IC25_CGMGEN_DA2_0_RESET                             0x3
#define CHN0_CH_BIAS1_ISEL_IC25_IM2CAL2_LSB                                    11
#define CHN0_CH_BIAS1_ISEL_IC25_IM2CAL2_MSB                                    13
#define CHN0_CH_BIAS1_ISEL_IC25_IM2CAL2_MASK                                   0x3800
#define CHN0_CH_BIAS1_ISEL_IC25_IM2CAL2_GET(x)                                 (((x) & CHN0_CH_BIAS1_ISEL_IC25_IM2CAL2_MASK) >> CHN0_CH_BIAS1_ISEL_IC25_IM2CAL2_LSB)
#define CHN0_CH_BIAS1_ISEL_IC25_IM2CAL2_SET(x)                                 (((0 | (x)) << CHN0_CH_BIAS1_ISEL_IC25_IM2CAL2_LSB) & CHN0_CH_BIAS1_ISEL_IC25_IM2CAL2_MASK)
#define CHN0_CH_BIAS1_ISEL_IC25_IM2CAL2_RESET                                  0x3
#define CHN0_CH_BIAS1_ISEL_IC25_RXGM2_LSB                                      8
#define CHN0_CH_BIAS1_ISEL_IC25_RXGM2_MSB                                      10
#define CHN0_CH_BIAS1_ISEL_IC25_RXGM2_MASK                                     0x700
#define CHN0_CH_BIAS1_ISEL_IC25_RXGM2_GET(x)                                   (((x) & CHN0_CH_BIAS1_ISEL_IC25_RXGM2_MASK) >> CHN0_CH_BIAS1_ISEL_IC25_RXGM2_LSB)
#define CHN0_CH_BIAS1_ISEL_IC25_RXGM2_SET(x)                                   (((0 | (x)) << CHN0_CH_BIAS1_ISEL_IC25_RXGM2_LSB) & CHN0_CH_BIAS1_ISEL_IC25_RXGM2_MASK)
#define CHN0_CH_BIAS1_ISEL_IC25_RXGM2_RESET                                    0x3
#define CHN0_CH_BIAS1_ISEL_IC25_TPC_LSB                                        5
#define CHN0_CH_BIAS1_ISEL_IC25_TPC_MSB                                        7
#define CHN0_CH_BIAS1_ISEL_IC25_TPC_MASK                                       0xe0
#define CHN0_CH_BIAS1_ISEL_IC25_TPC_GET(x)                                     (((x) & CHN0_CH_BIAS1_ISEL_IC25_TPC_MASK) >> CHN0_CH_BIAS1_ISEL_IC25_TPC_LSB)
#define CHN0_CH_BIAS1_ISEL_IC25_TPC_SET(x)                                     (((0 | (x)) << CHN0_CH_BIAS1_ISEL_IC25_TPC_LSB) & CHN0_CH_BIAS1_ISEL_IC25_TPC_MASK)
#define CHN0_CH_BIAS1_ISEL_IC25_TPC_RESET                                      0x3
#define CHN0_CH_BIAS1_ISEL_IC50_TPCDPD_LSB                                     2
#define CHN0_CH_BIAS1_ISEL_IC50_TPCDPD_MSB                                     4
#define CHN0_CH_BIAS1_ISEL_IC50_TPCDPD_MASK                                    0x1c
#define CHN0_CH_BIAS1_ISEL_IC50_TPCDPD_GET(x)                                  (((x) & CHN0_CH_BIAS1_ISEL_IC50_TPCDPD_MASK) >> CHN0_CH_BIAS1_ISEL_IC50_TPCDPD_LSB)
#define CHN0_CH_BIAS1_ISEL_IC50_TPCDPD_SET(x)                                  (((0 | (x)) << CHN0_CH_BIAS1_ISEL_IC50_TPCDPD_LSB) & CHN0_CH_BIAS1_ISEL_IC50_TPCDPD_MASK)
#define CHN0_CH_BIAS1_ISEL_IC50_TPCDPD_RESET                                   0x3
#define CHN0_CH_BIAS1_CHAIN_BIAS_SPARE_1_LSB                                   0
#define CHN0_CH_BIAS1_CHAIN_BIAS_SPARE_1_MSB                                   1
#define CHN0_CH_BIAS1_CHAIN_BIAS_SPARE_1_MASK                                  0x3
#define CHN0_CH_BIAS1_CHAIN_BIAS_SPARE_1_GET(x)                                (((x) & CHN0_CH_BIAS1_CHAIN_BIAS_SPARE_1_MASK) >> CHN0_CH_BIAS1_CHAIN_BIAS_SPARE_1_LSB)
#define CHN0_CH_BIAS1_CHAIN_BIAS_SPARE_1_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS1_CHAIN_BIAS_SPARE_1_LSB) & CHN0_CH_BIAS1_CHAIN_BIAS_SPARE_1_MASK)
#define CHN0_CH_BIAS1_CHAIN_BIAS_SPARE_1_RESET                                 0x0
#define CHN0_CH_BIAS1_ADDRESS                                                  (0x4 + __CHN0_CHAIN_BIAS_REG_CSR_BASE_ADDRESS)
#define CHN0_CH_BIAS1_RSTMASK                                                  0xffffffff
#define CHN0_CH_BIAS1_RESET                                                    0x6db6db6c

// 0x8 (CHN0_CH_BIAS2)
#define CHN0_CH_BIAS2_ISEL_IC25_CASBIAS_DA5_LSB                                29
#define CHN0_CH_BIAS2_ISEL_IC25_CASBIAS_DA5_MSB                                31
#define CHN0_CH_BIAS2_ISEL_IC25_CASBIAS_DA5_MASK                               0xe0000000
#define CHN0_CH_BIAS2_ISEL_IC25_CASBIAS_DA5_GET(x)                             (((x) & CHN0_CH_BIAS2_ISEL_IC25_CASBIAS_DA5_MASK) >> CHN0_CH_BIAS2_ISEL_IC25_CASBIAS_DA5_LSB)
#define CHN0_CH_BIAS2_ISEL_IC25_CASBIAS_DA5_SET(x)                             (((0 | (x)) << CHN0_CH_BIAS2_ISEL_IC25_CASBIAS_DA5_LSB) & CHN0_CH_BIAS2_ISEL_IC25_CASBIAS_DA5_MASK)
#define CHN0_CH_BIAS2_ISEL_IC25_CASBIAS_DA5_RESET                              0x3
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_1_LSB                               26
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_1_MSB                               28
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_1_MASK                              0x1c000000
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_1_GET(x)                            (((x) & CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_1_MASK) >> CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_1_LSB)
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_1_SET(x)                            (((0 | (x)) << CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_1_LSB) & CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_1_MASK)
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_1_RESET                             0x3
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_0_LSB                               23
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_0_MSB                               25
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_0_MASK                              0x3800000
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_0_GET(x)                            (((x) & CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_0_MASK) >> CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_0_LSB)
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_0_SET(x)                            (((0 | (x)) << CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_0_LSB) & CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_0_MASK)
#define CHN0_CH_BIAS2_ISEL_IC25_CGMFIT_DA5_0_RESET                             0x3
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_1_LSB                               20
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_1_MSB                               22
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_1_MASK                              0x700000
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_1_GET(x)                            (((x) & CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_1_MASK) >> CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_1_LSB)
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_1_SET(x)                            (((0 | (x)) << CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_1_LSB) & CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_1_MASK)
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_1_RESET                             0x3
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_0_LSB                               17
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_0_MSB                               19
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_0_MASK                              0xe0000
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_0_GET(x)                            (((x) & CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_0_MASK) >> CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_0_LSB)
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_0_SET(x)                            (((0 | (x)) << CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_0_LSB) & CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_0_MASK)
#define CHN0_CH_BIAS2_ISEL_IC25_CGMGEN_DA5_0_RESET                             0x3
#define CHN0_CH_BIAS2_ISEL_IC25_IM2CAL5_LSB                                    14
#define CHN0_CH_BIAS2_ISEL_IC25_IM2CAL5_MSB                                    16
#define CHN0_CH_BIAS2_ISEL_IC25_IM2CAL5_MASK                                   0x1c000
#define CHN0_CH_BIAS2_ISEL_IC25_IM2CAL5_GET(x)                                 (((x) & CHN0_CH_BIAS2_ISEL_IC25_IM2CAL5_MASK) >> CHN0_CH_BIAS2_ISEL_IC25_IM2CAL5_LSB)
#define CHN0_CH_BIAS2_ISEL_IC25_IM2CAL5_SET(x)                                 (((0 | (x)) << CHN0_CH_BIAS2_ISEL_IC25_IM2CAL5_LSB) & CHN0_CH_BIAS2_ISEL_IC25_IM2CAL5_MASK)
#define CHN0_CH_BIAS2_ISEL_IC25_IM2CAL5_RESET                                  0x3
#define CHN0_CH_BIAS2_ISEL_IC25_RXGM5_LSB                                      11
#define CHN0_CH_BIAS2_ISEL_IC25_RXGM5_MSB                                      13
#define CHN0_CH_BIAS2_ISEL_IC25_RXGM5_MASK                                     0x3800
#define CHN0_CH_BIAS2_ISEL_IC25_RXGM5_GET(x)                                   (((x) & CHN0_CH_BIAS2_ISEL_IC25_RXGM5_MASK) >> CHN0_CH_BIAS2_ISEL_IC25_RXGM5_LSB)
#define CHN0_CH_BIAS2_ISEL_IC25_RXGM5_SET(x)                                   (((0 | (x)) << CHN0_CH_BIAS2_ISEL_IC25_RXGM5_LSB) & CHN0_CH_BIAS2_ISEL_IC25_RXGM5_MASK)
#define CHN0_CH_BIAS2_ISEL_IC25_RXGM5_RESET                                    0x3
#define CHN0_CH_BIAS2_ISEL_IC25_TEMP_LSB                                       8
#define CHN0_CH_BIAS2_ISEL_IC25_TEMP_MSB                                       10
#define CHN0_CH_BIAS2_ISEL_IC25_TEMP_MASK                                      0x700
#define CHN0_CH_BIAS2_ISEL_IC25_TEMP_GET(x)                                    (((x) & CHN0_CH_BIAS2_ISEL_IC25_TEMP_MASK) >> CHN0_CH_BIAS2_ISEL_IC25_TEMP_LSB)
#define CHN0_CH_BIAS2_ISEL_IC25_TEMP_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS2_ISEL_IC25_TEMP_LSB) & CHN0_CH_BIAS2_ISEL_IC25_TEMP_MASK)
#define CHN0_CH_BIAS2_ISEL_IC25_TEMP_RESET                                     0x3
#define CHN0_CH_BIAS2_CHAIN_BIAS_SPARE_2_LSB                                   0
#define CHN0_CH_BIAS2_CHAIN_BIAS_SPARE_2_MSB                                   7
#define CHN0_CH_BIAS2_CHAIN_BIAS_SPARE_2_MASK                                  0xff
#define CHN0_CH_BIAS2_CHAIN_BIAS_SPARE_2_GET(x)                                (((x) & CHN0_CH_BIAS2_CHAIN_BIAS_SPARE_2_MASK) >> CHN0_CH_BIAS2_CHAIN_BIAS_SPARE_2_LSB)
#define CHN0_CH_BIAS2_CHAIN_BIAS_SPARE_2_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS2_CHAIN_BIAS_SPARE_2_LSB) & CHN0_CH_BIAS2_CHAIN_BIAS_SPARE_2_MASK)
#define CHN0_CH_BIAS2_CHAIN_BIAS_SPARE_2_RESET                                 0x0
#define CHN0_CH_BIAS2_ADDRESS                                                  (0x8 + __CHN0_CHAIN_BIAS_REG_CSR_BASE_ADDRESS)
#define CHN0_CH_BIAS2_RSTMASK                                                  0xffffffff
#define CHN0_CH_BIAS2_RESET                                                    0x6db6db00

// 0xc (CHN0_CH_BIAS3)
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_1_LSB                                     29
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_1_MSB                                     31
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_1_MASK                                    0xe0000000
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_1_GET(x)                                  (((x) & CHN0_CH_BIAS3_ISEL_IC25_V2II_1_MASK) >> CHN0_CH_BIAS3_ISEL_IC25_V2II_1_LSB)
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_1_SET(x)                                  (((0 | (x)) << CHN0_CH_BIAS3_ISEL_IC25_V2II_1_LSB) & CHN0_CH_BIAS3_ISEL_IC25_V2II_1_MASK)
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_1_RESET                                   0x3
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_0_LSB                                     26
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_0_MSB                                     28
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_0_MASK                                    0x1c000000
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_0_GET(x)                                  (((x) & CHN0_CH_BIAS3_ISEL_IC25_V2II_0_MASK) >> CHN0_CH_BIAS3_ISEL_IC25_V2II_0_LSB)
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_0_SET(x)                                  (((0 | (x)) << CHN0_CH_BIAS3_ISEL_IC25_V2II_0_LSB) & CHN0_CH_BIAS3_ISEL_IC25_V2II_0_MASK)
#define CHN0_CH_BIAS3_ISEL_IC25_V2II_0_RESET                                   0x3
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_1_LSB                                     23
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_1_MSB                                     25
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_1_MASK                                    0x3800000
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_1_GET(x)                                  (((x) & CHN0_CH_BIAS3_ISEL_IC25_V2IQ_1_MASK) >> CHN0_CH_BIAS3_ISEL_IC25_V2IQ_1_LSB)
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_1_SET(x)                                  (((0 | (x)) << CHN0_CH_BIAS3_ISEL_IC25_V2IQ_1_LSB) & CHN0_CH_BIAS3_ISEL_IC25_V2IQ_1_MASK)
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_1_RESET                                   0x3
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_0_LSB                                     20
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_0_MSB                                     22
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_0_MASK                                    0x700000
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_0_GET(x)                                  (((x) & CHN0_CH_BIAS3_ISEL_IC25_V2IQ_0_MASK) >> CHN0_CH_BIAS3_ISEL_IC25_V2IQ_0_LSB)
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_0_SET(x)                                  (((0 | (x)) << CHN0_CH_BIAS3_ISEL_IC25_V2IQ_0_LSB) & CHN0_CH_BIAS3_ISEL_IC25_V2IQ_0_MASK)
#define CHN0_CH_BIAS3_ISEL_IC25_V2IQ_0_RESET                                   0x3
#define CHN0_CH_BIAS3_ISEL_IC25_TXBB_LSB                                       17
#define CHN0_CH_BIAS3_ISEL_IC25_TXBB_MSB                                       19
#define CHN0_CH_BIAS3_ISEL_IC25_TXBB_MASK                                      0xe0000
#define CHN0_CH_BIAS3_ISEL_IC25_TXBB_GET(x)                                    (((x) & CHN0_CH_BIAS3_ISEL_IC25_TXBB_MASK) >> CHN0_CH_BIAS3_ISEL_IC25_TXBB_LSB)
#define CHN0_CH_BIAS3_ISEL_IC25_TXBB_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS3_ISEL_IC25_TXBB_LSB) & CHN0_CH_BIAS3_ISEL_IC25_TXBB_MASK)
#define CHN0_CH_BIAS3_ISEL_IC25_TXBB_RESET                                     0x3
#define CHN0_CH_BIAS3_ISEL_IC25_RXBB_LSB                                       14
#define CHN0_CH_BIAS3_ISEL_IC25_RXBB_MSB                                       16
#define CHN0_CH_BIAS3_ISEL_IC25_RXBB_MASK                                      0x1c000
#define CHN0_CH_BIAS3_ISEL_IC25_RXBB_GET(x)                                    (((x) & CHN0_CH_BIAS3_ISEL_IC25_RXBB_MASK) >> CHN0_CH_BIAS3_ISEL_IC25_RXBB_LSB)
#define CHN0_CH_BIAS3_ISEL_IC25_RXBB_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS3_ISEL_IC25_RXBB_LSB) & CHN0_CH_BIAS3_ISEL_IC25_RXBB_MASK)
#define CHN0_CH_BIAS3_ISEL_IC25_RXBB_RESET                                     0x3
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_1_LSB                                      11
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_1_MSB                                      13
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_1_MASK                                     0x3800
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_1_GET(x)                                   (((x) & CHN0_CH_BIAS3_ISEL_IC25_DAC_1_MASK) >> CHN0_CH_BIAS3_ISEL_IC25_DAC_1_LSB)
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_1_SET(x)                                   (((0 | (x)) << CHN0_CH_BIAS3_ISEL_IC25_DAC_1_LSB) & CHN0_CH_BIAS3_ISEL_IC25_DAC_1_MASK)
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_1_RESET                                    0x3
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_0_LSB                                      8
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_0_MSB                                      10
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_0_MASK                                     0x700
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_0_GET(x)                                   (((x) & CHN0_CH_BIAS3_ISEL_IC25_DAC_0_MASK) >> CHN0_CH_BIAS3_ISEL_IC25_DAC_0_LSB)
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_0_SET(x)                                   (((0 | (x)) << CHN0_CH_BIAS3_ISEL_IC25_DAC_0_LSB) & CHN0_CH_BIAS3_ISEL_IC25_DAC_0_MASK)
#define CHN0_CH_BIAS3_ISEL_IC25_DAC_0_RESET                                    0x3
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_COMP_LSB                                   5
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_COMP_MSB                                   7
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_COMP_MASK                                  0xe0
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_COMP_GET(x)                                (((x) & CHN0_CH_BIAS3_ISEL_IC25_ADC_COMP_MASK) >> CHN0_CH_BIAS3_ISEL_IC25_ADC_COMP_LSB)
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_COMP_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS3_ISEL_IC25_ADC_COMP_LSB) & CHN0_CH_BIAS3_ISEL_IC25_ADC_COMP_MASK)
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_COMP_RESET                                 0x3
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_REF_LSB                                    2
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_REF_MSB                                    4
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_REF_MASK                                   0x1c
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_REF_GET(x)                                 (((x) & CHN0_CH_BIAS3_ISEL_IC25_ADC_REF_MASK) >> CHN0_CH_BIAS3_ISEL_IC25_ADC_REF_LSB)
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_REF_SET(x)                                 (((0 | (x)) << CHN0_CH_BIAS3_ISEL_IC25_ADC_REF_LSB) & CHN0_CH_BIAS3_ISEL_IC25_ADC_REF_MASK)
#define CHN0_CH_BIAS3_ISEL_IC25_ADC_REF_RESET                                  0x3
#define CHN0_CH_BIAS3_CHAIN_BIAS_SPARE_3_LSB                                   0
#define CHN0_CH_BIAS3_CHAIN_BIAS_SPARE_3_MSB                                   1
#define CHN0_CH_BIAS3_CHAIN_BIAS_SPARE_3_MASK                                  0x3
#define CHN0_CH_BIAS3_CHAIN_BIAS_SPARE_3_GET(x)                                (((x) & CHN0_CH_BIAS3_CHAIN_BIAS_SPARE_3_MASK) >> CHN0_CH_BIAS3_CHAIN_BIAS_SPARE_3_LSB)
#define CHN0_CH_BIAS3_CHAIN_BIAS_SPARE_3_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS3_CHAIN_BIAS_SPARE_3_LSB) & CHN0_CH_BIAS3_CHAIN_BIAS_SPARE_3_MASK)
#define CHN0_CH_BIAS3_CHAIN_BIAS_SPARE_3_RESET                                 0x0
#define CHN0_CH_BIAS3_ADDRESS                                                  (0xc + __CHN0_CHAIN_BIAS_REG_CSR_BASE_ADDRESS)
#define CHN0_CH_BIAS3_RSTMASK                                                  0xffffffff
#define CHN0_CH_BIAS3_RESET                                                    0x6db6db6c

// 0x10 (CHN0_CH_BIAS4)
#define CHN0_CH_BIAS4_ISEL_IC25_PDADC_LSB                                      29
#define CHN0_CH_BIAS4_ISEL_IC25_PDADC_MSB                                      31
#define CHN0_CH_BIAS4_ISEL_IC25_PDADC_MASK                                     0xe0000000
#define CHN0_CH_BIAS4_ISEL_IC25_PDADC_GET(x)                                   (((x) & CHN0_CH_BIAS4_ISEL_IC25_PDADC_MASK) >> CHN0_CH_BIAS4_ISEL_IC25_PDADC_LSB)
#define CHN0_CH_BIAS4_ISEL_IC25_PDADC_SET(x)                                   (((0 | (x)) << CHN0_CH_BIAS4_ISEL_IC25_PDADC_LSB) & CHN0_CH_BIAS4_ISEL_IC25_PDADC_MASK)
#define CHN0_CH_BIAS4_ISEL_IC25_PDADC_RESET                                    0x3
#define CHN0_CH_BIAS4_ISEL_IC25_CLKDRV_LSB                                     26
#define CHN0_CH_BIAS4_ISEL_IC25_CLKDRV_MSB                                     28
#define CHN0_CH_BIAS4_ISEL_IC25_CLKDRV_MASK                                    0x1c000000
#define CHN0_CH_BIAS4_ISEL_IC25_CLKDRV_GET(x)                                  (((x) & CHN0_CH_BIAS4_ISEL_IC25_CLKDRV_MASK) >> CHN0_CH_BIAS4_ISEL_IC25_CLKDRV_LSB)
#define CHN0_CH_BIAS4_ISEL_IC25_CLKDRV_SET(x)                                  (((0 | (x)) << CHN0_CH_BIAS4_ISEL_IC25_CLKDRV_LSB) & CHN0_CH_BIAS4_ISEL_IC25_CLKDRV_MASK)
#define CHN0_CH_BIAS4_ISEL_IC25_CLKDRV_RESET                                   0x3
#define CHN0_CH_BIAS4_ISEL_IC25_LO_2_LSB                                       23
#define CHN0_CH_BIAS4_ISEL_IC25_LO_2_MSB                                       25
#define CHN0_CH_BIAS4_ISEL_IC25_LO_2_MASK                                      0x3800000
#define CHN0_CH_BIAS4_ISEL_IC25_LO_2_GET(x)                                    (((x) & CHN0_CH_BIAS4_ISEL_IC25_LO_2_MASK) >> CHN0_CH_BIAS4_ISEL_IC25_LO_2_LSB)
#define CHN0_CH_BIAS4_ISEL_IC25_LO_2_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS4_ISEL_IC25_LO_2_LSB) & CHN0_CH_BIAS4_ISEL_IC25_LO_2_MASK)
#define CHN0_CH_BIAS4_ISEL_IC25_LO_2_RESET                                     0x3
#define CHN0_CH_BIAS4_ISEL_IC25_LO_1_LSB                                       20
#define CHN0_CH_BIAS4_ISEL_IC25_LO_1_MSB                                       22
#define CHN0_CH_BIAS4_ISEL_IC25_LO_1_MASK                                      0x700000
#define CHN0_CH_BIAS4_ISEL_IC25_LO_1_GET(x)                                    (((x) & CHN0_CH_BIAS4_ISEL_IC25_LO_1_MASK) >> CHN0_CH_BIAS4_ISEL_IC25_LO_1_LSB)
#define CHN0_CH_BIAS4_ISEL_IC25_LO_1_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS4_ISEL_IC25_LO_1_LSB) & CHN0_CH_BIAS4_ISEL_IC25_LO_1_MASK)
#define CHN0_CH_BIAS4_ISEL_IC25_LO_1_RESET                                     0x3
#define CHN0_CH_BIAS4_ISEL_IC25_LO_0_LSB                                       17
#define CHN0_CH_BIAS4_ISEL_IC25_LO_0_MSB                                       19
#define CHN0_CH_BIAS4_ISEL_IC25_LO_0_MASK                                      0xe0000
#define CHN0_CH_BIAS4_ISEL_IC25_LO_0_GET(x)                                    (((x) & CHN0_CH_BIAS4_ISEL_IC25_LO_0_MASK) >> CHN0_CH_BIAS4_ISEL_IC25_LO_0_LSB)
#define CHN0_CH_BIAS4_ISEL_IC25_LO_0_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS4_ISEL_IC25_LO_0_LSB) & CHN0_CH_BIAS4_ISEL_IC25_LO_0_MASK)
#define CHN0_CH_BIAS4_ISEL_IC25_LO_0_RESET                                     0x3
#define CHN0_CH_BIAS4_CHAIN_BIAS_SPARE_4_LSB                                   0
#define CHN0_CH_BIAS4_CHAIN_BIAS_SPARE_4_MSB                                   16
#define CHN0_CH_BIAS4_CHAIN_BIAS_SPARE_4_MASK                                  0x1ffff
#define CHN0_CH_BIAS4_CHAIN_BIAS_SPARE_4_GET(x)                                (((x) & CHN0_CH_BIAS4_CHAIN_BIAS_SPARE_4_MASK) >> CHN0_CH_BIAS4_CHAIN_BIAS_SPARE_4_LSB)
#define CHN0_CH_BIAS4_CHAIN_BIAS_SPARE_4_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS4_CHAIN_BIAS_SPARE_4_LSB) & CHN0_CH_BIAS4_CHAIN_BIAS_SPARE_4_MASK)
#define CHN0_CH_BIAS4_CHAIN_BIAS_SPARE_4_RESET                                 0x0
#define CHN0_CH_BIAS4_ADDRESS                                                  (0x10 + __CHN0_CHAIN_BIAS_REG_CSR_BASE_ADDRESS)
#define CHN0_CH_BIAS4_RSTMASK                                                  0xffffffff
#define CHN0_CH_BIAS4_RESET                                                    0x6db60000

// 0x14 (CHN0_CH_BIAS5)
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_1_LSB                                29
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_1_MSB                                31
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_1_MASK                               0xe0000000
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_1_GET(x)                             (((x) & CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_1_MASK) >> CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_1_LSB)
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_1_SET(x)                             (((0 | (x)) << CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_1_LSB) & CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_1_MASK)
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_1_RESET                              0x3
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_0_LSB                                26
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_0_MSB                                28
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_0_MASK                               0x1c000000
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_0_GET(x)                             (((x) & CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_0_MASK) >> CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_0_LSB)
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_0_SET(x)                             (((0 | (x)) << CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_0_LSB) & CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_0_MASK)
#define CHN0_CH_BIAS5_ISEL_IR25_2NMOS_DA2_0_RESET                              0x3
#define CHN0_CH_BIAS5_ISEL_IR25_CGMGEN_DA2_LSB                                 23
#define CHN0_CH_BIAS5_ISEL_IR25_CGMGEN_DA2_MSB                                 25
#define CHN0_CH_BIAS5_ISEL_IR25_CGMGEN_DA2_MASK                                0x3800000
#define CHN0_CH_BIAS5_ISEL_IR25_CGMGEN_DA2_GET(x)                              (((x) & CHN0_CH_BIAS5_ISEL_IR25_CGMGEN_DA2_MASK) >> CHN0_CH_BIAS5_ISEL_IR25_CGMGEN_DA2_LSB)
#define CHN0_CH_BIAS5_ISEL_IR25_CGMGEN_DA2_SET(x)                              (((0 | (x)) << CHN0_CH_BIAS5_ISEL_IR25_CGMGEN_DA2_LSB) & CHN0_CH_BIAS5_ISEL_IR25_CGMGEN_DA2_MASK)
#define CHN0_CH_BIAS5_ISEL_IR25_CGMGEN_DA2_RESET                               0x3
#define CHN0_CH_BIAS5_ISEL_IR25_AGC2_LSB                                       20
#define CHN0_CH_BIAS5_ISEL_IR25_AGC2_MSB                                       22
#define CHN0_CH_BIAS5_ISEL_IR25_AGC2_MASK                                      0x700000
#define CHN0_CH_BIAS5_ISEL_IR25_AGC2_GET(x)                                    (((x) & CHN0_CH_BIAS5_ISEL_IR25_AGC2_MASK) >> CHN0_CH_BIAS5_ISEL_IR25_AGC2_LSB)
#define CHN0_CH_BIAS5_ISEL_IR25_AGC2_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS5_ISEL_IR25_AGC2_LSB) & CHN0_CH_BIAS5_ISEL_IR25_AGC2_MASK)
#define CHN0_CH_BIAS5_ISEL_IR25_AGC2_RESET                                     0x3
#define CHN0_CH_BIAS5_ISEL_IR25_IM2CAL2_LSB                                    17
#define CHN0_CH_BIAS5_ISEL_IR25_IM2CAL2_MSB                                    19
#define CHN0_CH_BIAS5_ISEL_IR25_IM2CAL2_MASK                                   0xe0000
#define CHN0_CH_BIAS5_ISEL_IR25_IM2CAL2_GET(x)                                 (((x) & CHN0_CH_BIAS5_ISEL_IR25_IM2CAL2_MASK) >> CHN0_CH_BIAS5_ISEL_IR25_IM2CAL2_LSB)
#define CHN0_CH_BIAS5_ISEL_IR25_IM2CAL2_SET(x)                                 (((0 | (x)) << CHN0_CH_BIAS5_ISEL_IR25_IM2CAL2_LSB) & CHN0_CH_BIAS5_ISEL_IR25_IM2CAL2_MASK)
#define CHN0_CH_BIAS5_ISEL_IR25_IM2CAL2_RESET                                  0x3
#define CHN0_CH_BIAS5_ISEL_IR25_CASBIAS_DA2_LSB                                14
#define CHN0_CH_BIAS5_ISEL_IR25_CASBIAS_DA2_MSB                                16
#define CHN0_CH_BIAS5_ISEL_IR25_CASBIAS_DA2_MASK                               0x1c000
#define CHN0_CH_BIAS5_ISEL_IR25_CASBIAS_DA2_GET(x)                             (((x) & CHN0_CH_BIAS5_ISEL_IR25_CASBIAS_DA2_MASK) >> CHN0_CH_BIAS5_ISEL_IR25_CASBIAS_DA2_LSB)
#define CHN0_CH_BIAS5_ISEL_IR25_CASBIAS_DA2_SET(x)                             (((0 | (x)) << CHN0_CH_BIAS5_ISEL_IR25_CASBIAS_DA2_LSB) & CHN0_CH_BIAS5_ISEL_IR25_CASBIAS_DA2_MASK)
#define CHN0_CH_BIAS5_ISEL_IR25_CASBIAS_DA2_RESET                              0x3
#define CHN0_CH_BIAS5_ISEL_IR25_UPC2_LSB                                       11
#define CHN0_CH_BIAS5_ISEL_IR25_UPC2_MSB                                       13
#define CHN0_CH_BIAS5_ISEL_IR25_UPC2_MASK                                      0x3800
#define CHN0_CH_BIAS5_ISEL_IR25_UPC2_GET(x)                                    (((x) & CHN0_CH_BIAS5_ISEL_IR25_UPC2_MASK) >> CHN0_CH_BIAS5_ISEL_IR25_UPC2_LSB)
#define CHN0_CH_BIAS5_ISEL_IR25_UPC2_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS5_ISEL_IR25_UPC2_LSB) & CHN0_CH_BIAS5_ISEL_IR25_UPC2_MASK)
#define CHN0_CH_BIAS5_ISEL_IR25_UPC2_RESET                                     0x3
#define CHN0_CH_BIAS5_ISEL_IR25_TPC_LSB                                        8
#define CHN0_CH_BIAS5_ISEL_IR25_TPC_MSB                                        10
#define CHN0_CH_BIAS5_ISEL_IR25_TPC_MASK                                       0x700
#define CHN0_CH_BIAS5_ISEL_IR25_TPC_GET(x)                                     (((x) & CHN0_CH_BIAS5_ISEL_IR25_TPC_MASK) >> CHN0_CH_BIAS5_ISEL_IR25_TPC_LSB)
#define CHN0_CH_BIAS5_ISEL_IR25_TPC_SET(x)                                     (((0 | (x)) << CHN0_CH_BIAS5_ISEL_IR25_TPC_LSB) & CHN0_CH_BIAS5_ISEL_IR25_TPC_MASK)
#define CHN0_CH_BIAS5_ISEL_IR25_TPC_RESET                                      0x3
#define CHN0_CH_BIAS5_CHAIN_BIAS_SPARE_5_LSB                                   0
#define CHN0_CH_BIAS5_CHAIN_BIAS_SPARE_5_MSB                                   7
#define CHN0_CH_BIAS5_CHAIN_BIAS_SPARE_5_MASK                                  0xff
#define CHN0_CH_BIAS5_CHAIN_BIAS_SPARE_5_GET(x)                                (((x) & CHN0_CH_BIAS5_CHAIN_BIAS_SPARE_5_MASK) >> CHN0_CH_BIAS5_CHAIN_BIAS_SPARE_5_LSB)
#define CHN0_CH_BIAS5_CHAIN_BIAS_SPARE_5_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS5_CHAIN_BIAS_SPARE_5_LSB) & CHN0_CH_BIAS5_CHAIN_BIAS_SPARE_5_MASK)
#define CHN0_CH_BIAS5_CHAIN_BIAS_SPARE_5_RESET                                 0x0
#define CHN0_CH_BIAS5_ADDRESS                                                  (0x14 + __CHN0_CHAIN_BIAS_REG_CSR_BASE_ADDRESS)
#define CHN0_CH_BIAS5_RSTMASK                                                  0xffffffff
#define CHN0_CH_BIAS5_RESET                                                    0x6db6db00

// 0x18 (CHN0_CH_BIAS6)
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_1_LSB                                29
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_1_MSB                                31
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_1_MASK                               0xe0000000
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_1_GET(x)                             (((x) & CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_1_MASK) >> CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_1_LSB)
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_1_SET(x)                             (((0 | (x)) << CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_1_LSB) & CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_1_MASK)
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_1_RESET                              0x3
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_0_LSB                                26
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_0_MSB                                28
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_0_MASK                               0x1c000000
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_0_GET(x)                             (((x) & CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_0_MASK) >> CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_0_LSB)
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_0_SET(x)                             (((0 | (x)) << CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_0_LSB) & CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_0_MASK)
#define CHN0_CH_BIAS6_ISEL_IR25_2NMOS_DA5_0_RESET                              0x3
#define CHN0_CH_BIAS6_ISEL_IR25_CGMGEN_DA5_LSB                                 23
#define CHN0_CH_BIAS6_ISEL_IR25_CGMGEN_DA5_MSB                                 25
#define CHN0_CH_BIAS6_ISEL_IR25_CGMGEN_DA5_MASK                                0x3800000
#define CHN0_CH_BIAS6_ISEL_IR25_CGMGEN_DA5_GET(x)                              (((x) & CHN0_CH_BIAS6_ISEL_IR25_CGMGEN_DA5_MASK) >> CHN0_CH_BIAS6_ISEL_IR25_CGMGEN_DA5_LSB)
#define CHN0_CH_BIAS6_ISEL_IR25_CGMGEN_DA5_SET(x)                              (((0 | (x)) << CHN0_CH_BIAS6_ISEL_IR25_CGMGEN_DA5_LSB) & CHN0_CH_BIAS6_ISEL_IR25_CGMGEN_DA5_MASK)
#define CHN0_CH_BIAS6_ISEL_IR25_CGMGEN_DA5_RESET                               0x3
#define CHN0_CH_BIAS6_ISEL_IR25_AGC5_LSB                                       20
#define CHN0_CH_BIAS6_ISEL_IR25_AGC5_MSB                                       22
#define CHN0_CH_BIAS6_ISEL_IR25_AGC5_MASK                                      0x700000
#define CHN0_CH_BIAS6_ISEL_IR25_AGC5_GET(x)                                    (((x) & CHN0_CH_BIAS6_ISEL_IR25_AGC5_MASK) >> CHN0_CH_BIAS6_ISEL_IR25_AGC5_LSB)
#define CHN0_CH_BIAS6_ISEL_IR25_AGC5_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS6_ISEL_IR25_AGC5_LSB) & CHN0_CH_BIAS6_ISEL_IR25_AGC5_MASK)
#define CHN0_CH_BIAS6_ISEL_IR25_AGC5_RESET                                     0x3
#define CHN0_CH_BIAS6_ISEL_IR25_IM2CAL5_LSB                                    17
#define CHN0_CH_BIAS6_ISEL_IR25_IM2CAL5_MSB                                    19
#define CHN0_CH_BIAS6_ISEL_IR25_IM2CAL5_MASK                                   0xe0000
#define CHN0_CH_BIAS6_ISEL_IR25_IM2CAL5_GET(x)                                 (((x) & CHN0_CH_BIAS6_ISEL_IR25_IM2CAL5_MASK) >> CHN0_CH_BIAS6_ISEL_IR25_IM2CAL5_LSB)
#define CHN0_CH_BIAS6_ISEL_IR25_IM2CAL5_SET(x)                                 (((0 | (x)) << CHN0_CH_BIAS6_ISEL_IR25_IM2CAL5_LSB) & CHN0_CH_BIAS6_ISEL_IR25_IM2CAL5_MASK)
#define CHN0_CH_BIAS6_ISEL_IR25_IM2CAL5_RESET                                  0x3
#define CHN0_CH_BIAS6_ISEL_IR25_CASBIAS_DA5_LSB                                14
#define CHN0_CH_BIAS6_ISEL_IR25_CASBIAS_DA5_MSB                                16
#define CHN0_CH_BIAS6_ISEL_IR25_CASBIAS_DA5_MASK                               0x1c000
#define CHN0_CH_BIAS6_ISEL_IR25_CASBIAS_DA5_GET(x)                             (((x) & CHN0_CH_BIAS6_ISEL_IR25_CASBIAS_DA5_MASK) >> CHN0_CH_BIAS6_ISEL_IR25_CASBIAS_DA5_LSB)
#define CHN0_CH_BIAS6_ISEL_IR25_CASBIAS_DA5_SET(x)                             (((0 | (x)) << CHN0_CH_BIAS6_ISEL_IR25_CASBIAS_DA5_LSB) & CHN0_CH_BIAS6_ISEL_IR25_CASBIAS_DA5_MASK)
#define CHN0_CH_BIAS6_ISEL_IR25_CASBIAS_DA5_RESET                              0x3
#define CHN0_CH_BIAS6_ISEL_IR25_UPC5_LSB                                       11
#define CHN0_CH_BIAS6_ISEL_IR25_UPC5_MSB                                       13
#define CHN0_CH_BIAS6_ISEL_IR25_UPC5_MASK                                      0x3800
#define CHN0_CH_BIAS6_ISEL_IR25_UPC5_GET(x)                                    (((x) & CHN0_CH_BIAS6_ISEL_IR25_UPC5_MASK) >> CHN0_CH_BIAS6_ISEL_IR25_UPC5_LSB)
#define CHN0_CH_BIAS6_ISEL_IR25_UPC5_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS6_ISEL_IR25_UPC5_LSB) & CHN0_CH_BIAS6_ISEL_IR25_UPC5_MASK)
#define CHN0_CH_BIAS6_ISEL_IR25_UPC5_RESET                                     0x3
#define CHN0_CH_BIAS6_CHAIN_BIAS_SPARE_6_LSB                                   0
#define CHN0_CH_BIAS6_CHAIN_BIAS_SPARE_6_MSB                                   10
#define CHN0_CH_BIAS6_CHAIN_BIAS_SPARE_6_MASK                                  0x7ff
#define CHN0_CH_BIAS6_CHAIN_BIAS_SPARE_6_GET(x)                                (((x) & CHN0_CH_BIAS6_CHAIN_BIAS_SPARE_6_MASK) >> CHN0_CH_BIAS6_CHAIN_BIAS_SPARE_6_LSB)
#define CHN0_CH_BIAS6_CHAIN_BIAS_SPARE_6_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS6_CHAIN_BIAS_SPARE_6_LSB) & CHN0_CH_BIAS6_CHAIN_BIAS_SPARE_6_MASK)
#define CHN0_CH_BIAS6_CHAIN_BIAS_SPARE_6_RESET                                 0x0
#define CHN0_CH_BIAS6_ADDRESS                                                  (0x18 + __CHN0_CHAIN_BIAS_REG_CSR_BASE_ADDRESS)
#define CHN0_CH_BIAS6_RSTMASK                                                  0xffffffff
#define CHN0_CH_BIAS6_RESET                                                    0x6db6d800

// 0x1c (CHN0_CH_BIAS7)
#define CHN0_CH_BIAS7_ISEL_IR25_TXBB_LSB                                       29
#define CHN0_CH_BIAS7_ISEL_IR25_TXBB_MSB                                       31
#define CHN0_CH_BIAS7_ISEL_IR25_TXBB_MASK                                      0xe0000000
#define CHN0_CH_BIAS7_ISEL_IR25_TXBB_GET(x)                                    (((x) & CHN0_CH_BIAS7_ISEL_IR25_TXBB_MASK) >> CHN0_CH_BIAS7_ISEL_IR25_TXBB_LSB)
#define CHN0_CH_BIAS7_ISEL_IR25_TXBB_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS7_ISEL_IR25_TXBB_LSB) & CHN0_CH_BIAS7_ISEL_IR25_TXBB_MASK)
#define CHN0_CH_BIAS7_ISEL_IR25_TXBB_RESET                                     0x3
#define CHN0_CH_BIAS7_ISEL_IR25_RXBB_LSB                                       26
#define CHN0_CH_BIAS7_ISEL_IR25_RXBB_MSB                                       28
#define CHN0_CH_BIAS7_ISEL_IR25_RXBB_MASK                                      0x1c000000
#define CHN0_CH_BIAS7_ISEL_IR25_RXBB_GET(x)                                    (((x) & CHN0_CH_BIAS7_ISEL_IR25_RXBB_MASK) >> CHN0_CH_BIAS7_ISEL_IR25_RXBB_LSB)
#define CHN0_CH_BIAS7_ISEL_IR25_RXBB_SET(x)                                    (((0 | (x)) << CHN0_CH_BIAS7_ISEL_IR25_RXBB_LSB) & CHN0_CH_BIAS7_ISEL_IR25_RXBB_MASK)
#define CHN0_CH_BIAS7_ISEL_IR25_RXBB_RESET                                     0x3
#define CHN0_CH_BIAS7_ISEL_IR25_ADC_LSB                                        23
#define CHN0_CH_BIAS7_ISEL_IR25_ADC_MSB                                        25
#define CHN0_CH_BIAS7_ISEL_IR25_ADC_MASK                                       0x3800000
#define CHN0_CH_BIAS7_ISEL_IR25_ADC_GET(x)                                     (((x) & CHN0_CH_BIAS7_ISEL_IR25_ADC_MASK) >> CHN0_CH_BIAS7_ISEL_IR25_ADC_LSB)
#define CHN0_CH_BIAS7_ISEL_IR25_ADC_SET(x)                                     (((0 | (x)) << CHN0_CH_BIAS7_ISEL_IR25_ADC_LSB) & CHN0_CH_BIAS7_ISEL_IR25_ADC_MASK)
#define CHN0_CH_BIAS7_ISEL_IR25_ADC_RESET                                      0x3
#define CHN0_CH_BIAS7_ISEL_IR25_PDADC_LSB                                      20
#define CHN0_CH_BIAS7_ISEL_IR25_PDADC_MSB                                      22
#define CHN0_CH_BIAS7_ISEL_IR25_PDADC_MASK                                     0x700000
#define CHN0_CH_BIAS7_ISEL_IR25_PDADC_GET(x)                                   (((x) & CHN0_CH_BIAS7_ISEL_IR25_PDADC_MASK) >> CHN0_CH_BIAS7_ISEL_IR25_PDADC_LSB)
#define CHN0_CH_BIAS7_ISEL_IR25_PDADC_SET(x)                                   (((0 | (x)) << CHN0_CH_BIAS7_ISEL_IR25_PDADC_LSB) & CHN0_CH_BIAS7_ISEL_IR25_PDADC_MASK)
#define CHN0_CH_BIAS7_ISEL_IR25_PDADC_RESET                                    0x3
#define CHN0_CH_BIAS7_ISEL_IR25_CLKDRV_LSB                                     17
#define CHN0_CH_BIAS7_ISEL_IR25_CLKDRV_MSB                                     19
#define CHN0_CH_BIAS7_ISEL_IR25_CLKDRV_MASK                                    0xe0000
#define CHN0_CH_BIAS7_ISEL_IR25_CLKDRV_GET(x)                                  (((x) & CHN0_CH_BIAS7_ISEL_IR25_CLKDRV_MASK) >> CHN0_CH_BIAS7_ISEL_IR25_CLKDRV_LSB)
#define CHN0_CH_BIAS7_ISEL_IR25_CLKDRV_SET(x)                                  (((0 | (x)) << CHN0_CH_BIAS7_ISEL_IR25_CLKDRV_LSB) & CHN0_CH_BIAS7_ISEL_IR25_CLKDRV_MASK)
#define CHN0_CH_BIAS7_ISEL_IR25_CLKDRV_RESET                                   0x3
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE1_LSB                                     14
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE1_MSB                                     16
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE1_MASK                                    0x1c000
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE1_GET(x)                                  (((x) & CHN0_CH_BIAS7_ISEL_IR25_SPARE1_MASK) >> CHN0_CH_BIAS7_ISEL_IR25_SPARE1_LSB)
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE1_SET(x)                                  (((0 | (x)) << CHN0_CH_BIAS7_ISEL_IR25_SPARE1_LSB) & CHN0_CH_BIAS7_ISEL_IR25_SPARE1_MASK)
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE1_RESET                                   0x3
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE0_LSB                                     11
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE0_MSB                                     13
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE0_MASK                                    0x3800
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE0_GET(x)                                  (((x) & CHN0_CH_BIAS7_ISEL_IR25_SPARE0_MASK) >> CHN0_CH_BIAS7_ISEL_IR25_SPARE0_LSB)
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE0_SET(x)                                  (((0 | (x)) << CHN0_CH_BIAS7_ISEL_IR25_SPARE0_LSB) & CHN0_CH_BIAS7_ISEL_IR25_SPARE0_MASK)
#define CHN0_CH_BIAS7_ISEL_IR25_SPARE0_RESET                                   0x3
#define CHN0_CH_BIAS7_CHAIN_BIAS_SPARE_7_LSB                                   0
#define CHN0_CH_BIAS7_CHAIN_BIAS_SPARE_7_MSB                                   10
#define CHN0_CH_BIAS7_CHAIN_BIAS_SPARE_7_MASK                                  0x7ff
#define CHN0_CH_BIAS7_CHAIN_BIAS_SPARE_7_GET(x)                                (((x) & CHN0_CH_BIAS7_CHAIN_BIAS_SPARE_7_MASK) >> CHN0_CH_BIAS7_CHAIN_BIAS_SPARE_7_LSB)
#define CHN0_CH_BIAS7_CHAIN_BIAS_SPARE_7_SET(x)                                (((0 | (x)) << CHN0_CH_BIAS7_CHAIN_BIAS_SPARE_7_LSB) & CHN0_CH_BIAS7_CHAIN_BIAS_SPARE_7_MASK)
#define CHN0_CH_BIAS7_CHAIN_BIAS_SPARE_7_RESET                                 0x0
#define CHN0_CH_BIAS7_ADDRESS                                                  (0x1c + __CHN0_CHAIN_BIAS_REG_CSR_BASE_ADDRESS)
#define CHN0_CH_BIAS7_RSTMASK                                                  0xffffffff
#define CHN0_CH_BIAS7_RESET                                                    0x6db6d800



#endif /* _CHN0_CHAIN_BIAS_REG_CSR_H_ */
