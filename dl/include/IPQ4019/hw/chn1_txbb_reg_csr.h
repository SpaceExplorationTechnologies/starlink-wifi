/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CHN1_TXBB_REG_CSR_H_
#define _CHN1_TXBB_REG_CSR_H_


#ifndef __CHN1_TXBB_REG_CSR_BASE_ADDRESS
#define __CHN1_TXBB_REG_CSR_BASE_ADDRESS (0x48540)
#endif


// 0x0 (CHN1_TXBB_0)
#define CHN1_TXBB_0_TX_BQ2V2I_EN_LSB                                           31
#define CHN1_TXBB_0_TX_BQ2V2I_EN_MSB                                           31
#define CHN1_TXBB_0_TX_BQ2V2I_EN_MASK                                          0x80000000
#define CHN1_TXBB_0_TX_BQ2V2I_EN_GET(x)                                        (((x) & CHN1_TXBB_0_TX_BQ2V2I_EN_MASK) >> CHN1_TXBB_0_TX_BQ2V2I_EN_LSB)
#define CHN1_TXBB_0_TX_BQ2V2I_EN_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_TX_BQ2V2I_EN_LSB) & CHN1_TXBB_0_TX_BQ2V2I_EN_MASK)
#define CHN1_TXBB_0_TX_BQ2V2I_EN_RESET                                         0x1
#define CHN1_TXBB_0_TX_DAC2V2I_EN_LSB                                          30
#define CHN1_TXBB_0_TX_DAC2V2I_EN_MSB                                          30
#define CHN1_TXBB_0_TX_DAC2V2I_EN_MASK                                         0x40000000
#define CHN1_TXBB_0_TX_DAC2V2I_EN_GET(x)                                       (((x) & CHN1_TXBB_0_TX_DAC2V2I_EN_MASK) >> CHN1_TXBB_0_TX_DAC2V2I_EN_LSB)
#define CHN1_TXBB_0_TX_DAC2V2I_EN_SET(x)                                       (((0 | (x)) << CHN1_TXBB_0_TX_DAC2V2I_EN_LSB) & CHN1_TXBB_0_TX_DAC2V2I_EN_MASK)
#define CHN1_TXBB_0_TX_DAC2V2I_EN_RESET                                        0x0
#define CHN1_TXBB_0_TX_TX2RXOUT_EN_LSB                                         29
#define CHN1_TXBB_0_TX_TX2RXOUT_EN_MSB                                         29
#define CHN1_TXBB_0_TX_TX2RXOUT_EN_MASK                                        0x20000000
#define CHN1_TXBB_0_TX_TX2RXOUT_EN_GET(x)                                      (((x) & CHN1_TXBB_0_TX_TX2RXOUT_EN_MASK) >> CHN1_TXBB_0_TX_TX2RXOUT_EN_LSB)
#define CHN1_TXBB_0_TX_TX2RXOUT_EN_SET(x)                                      (((0 | (x)) << CHN1_TXBB_0_TX_TX2RXOUT_EN_LSB) & CHN1_TXBB_0_TX_TX2RXOUT_EN_MASK)
#define CHN1_TXBB_0_TX_TX2RXOUT_EN_RESET                                       0x0
#define CHN1_TXBB_0_TX_NOTCHON_LSB                                             28
#define CHN1_TXBB_0_TX_NOTCHON_MSB                                             28
#define CHN1_TXBB_0_TX_NOTCHON_MASK                                            0x10000000
#define CHN1_TXBB_0_TX_NOTCHON_GET(x)                                          (((x) & CHN1_TXBB_0_TX_NOTCHON_MASK) >> CHN1_TXBB_0_TX_NOTCHON_LSB)
#define CHN1_TXBB_0_TX_NOTCHON_SET(x)                                          (((0 | (x)) << CHN1_TXBB_0_TX_NOTCHON_LSB) & CHN1_TXBB_0_TX_NOTCHON_MASK)
#define CHN1_TXBB_0_TX_NOTCHON_RESET                                           0x1
#define CHN1_TXBB_0_TX_EN_PGA_LSB                                              27
#define CHN1_TXBB_0_TX_EN_PGA_MSB                                              27
#define CHN1_TXBB_0_TX_EN_PGA_MASK                                             0x8000000
#define CHN1_TXBB_0_TX_EN_PGA_GET(x)                                           (((x) & CHN1_TXBB_0_TX_EN_PGA_MASK) >> CHN1_TXBB_0_TX_EN_PGA_LSB)
#define CHN1_TXBB_0_TX_EN_PGA_SET(x)                                           (((0 | (x)) << CHN1_TXBB_0_TX_EN_PGA_LSB) & CHN1_TXBB_0_TX_EN_PGA_MASK)
#define CHN1_TXBB_0_TX_EN_PGA_RESET                                            0x1
#define CHN1_TXBB_0_TX_EN_BQ1_LSB                                              26
#define CHN1_TXBB_0_TX_EN_BQ1_MSB                                              26
#define CHN1_TXBB_0_TX_EN_BQ1_MASK                                             0x4000000
#define CHN1_TXBB_0_TX_EN_BQ1_GET(x)                                           (((x) & CHN1_TXBB_0_TX_EN_BQ1_MASK) >> CHN1_TXBB_0_TX_EN_BQ1_LSB)
#define CHN1_TXBB_0_TX_EN_BQ1_SET(x)                                           (((0 | (x)) << CHN1_TXBB_0_TX_EN_BQ1_LSB) & CHN1_TXBB_0_TX_EN_BQ1_MASK)
#define CHN1_TXBB_0_TX_EN_BQ1_RESET                                            0x1
#define CHN1_TXBB_0_TX_EN_BQ2_LSB                                              25
#define CHN1_TXBB_0_TX_EN_BQ2_MSB                                              25
#define CHN1_TXBB_0_TX_EN_BQ2_MASK                                             0x2000000
#define CHN1_TXBB_0_TX_EN_BQ2_GET(x)                                           (((x) & CHN1_TXBB_0_TX_EN_BQ2_MASK) >> CHN1_TXBB_0_TX_EN_BQ2_LSB)
#define CHN1_TXBB_0_TX_EN_BQ2_SET(x)                                           (((0 | (x)) << CHN1_TXBB_0_TX_EN_BQ2_LSB) & CHN1_TXBB_0_TX_EN_BQ2_MASK)
#define CHN1_TXBB_0_TX_EN_BQ2_RESET                                            0x1
#define CHN1_TXBB_0_TX_EN_V2I_LSB                                              24
#define CHN1_TXBB_0_TX_EN_V2I_MSB                                              24
#define CHN1_TXBB_0_TX_EN_V2I_MASK                                             0x1000000
#define CHN1_TXBB_0_TX_EN_V2I_GET(x)                                           (((x) & CHN1_TXBB_0_TX_EN_V2I_MASK) >> CHN1_TXBB_0_TX_EN_V2I_LSB)
#define CHN1_TXBB_0_TX_EN_V2I_SET(x)                                           (((0 | (x)) << CHN1_TXBB_0_TX_EN_V2I_LSB) & CHN1_TXBB_0_TX_EN_V2I_MASK)
#define CHN1_TXBB_0_TX_EN_V2I_RESET                                            0x1
#define CHN1_TXBB_0_CALFC_BQ2V2I_EN_LSB                                        23
#define CHN1_TXBB_0_CALFC_BQ2V2I_EN_MSB                                        23
#define CHN1_TXBB_0_CALFC_BQ2V2I_EN_MASK                                       0x800000
#define CHN1_TXBB_0_CALFC_BQ2V2I_EN_GET(x)                                     (((x) & CHN1_TXBB_0_CALFC_BQ2V2I_EN_MASK) >> CHN1_TXBB_0_CALFC_BQ2V2I_EN_LSB)
#define CHN1_TXBB_0_CALFC_BQ2V2I_EN_SET(x)                                     (((0 | (x)) << CHN1_TXBB_0_CALFC_BQ2V2I_EN_LSB) & CHN1_TXBB_0_CALFC_BQ2V2I_EN_MASK)
#define CHN1_TXBB_0_CALFC_BQ2V2I_EN_RESET                                      0x0
#define CHN1_TXBB_0_CALFC_DAC2V2I_EN_LSB                                       22
#define CHN1_TXBB_0_CALFC_DAC2V2I_EN_MSB                                       22
#define CHN1_TXBB_0_CALFC_DAC2V2I_EN_MASK                                      0x400000
#define CHN1_TXBB_0_CALFC_DAC2V2I_EN_GET(x)                                    (((x) & CHN1_TXBB_0_CALFC_DAC2V2I_EN_MASK) >> CHN1_TXBB_0_CALFC_DAC2V2I_EN_LSB)
#define CHN1_TXBB_0_CALFC_DAC2V2I_EN_SET(x)                                    (((0 | (x)) << CHN1_TXBB_0_CALFC_DAC2V2I_EN_LSB) & CHN1_TXBB_0_CALFC_DAC2V2I_EN_MASK)
#define CHN1_TXBB_0_CALFC_DAC2V2I_EN_RESET                                     0x0
#define CHN1_TXBB_0_CALFC_TX2RXOUT_EN_LSB                                      21
#define CHN1_TXBB_0_CALFC_TX2RXOUT_EN_MSB                                      21
#define CHN1_TXBB_0_CALFC_TX2RXOUT_EN_MASK                                     0x200000
#define CHN1_TXBB_0_CALFC_TX2RXOUT_EN_GET(x)                                   (((x) & CHN1_TXBB_0_CALFC_TX2RXOUT_EN_MASK) >> CHN1_TXBB_0_CALFC_TX2RXOUT_EN_LSB)
#define CHN1_TXBB_0_CALFC_TX2RXOUT_EN_SET(x)                                   (((0 | (x)) << CHN1_TXBB_0_CALFC_TX2RXOUT_EN_LSB) & CHN1_TXBB_0_CALFC_TX2RXOUT_EN_MASK)
#define CHN1_TXBB_0_CALFC_TX2RXOUT_EN_RESET                                    0x1
#define CHN1_TXBB_0_CALFC_NOTCHON_LSB                                          20
#define CHN1_TXBB_0_CALFC_NOTCHON_MSB                                          20
#define CHN1_TXBB_0_CALFC_NOTCHON_MASK                                         0x100000
#define CHN1_TXBB_0_CALFC_NOTCHON_GET(x)                                       (((x) & CHN1_TXBB_0_CALFC_NOTCHON_MASK) >> CHN1_TXBB_0_CALFC_NOTCHON_LSB)
#define CHN1_TXBB_0_CALFC_NOTCHON_SET(x)                                       (((0 | (x)) << CHN1_TXBB_0_CALFC_NOTCHON_LSB) & CHN1_TXBB_0_CALFC_NOTCHON_MASK)
#define CHN1_TXBB_0_CALFC_NOTCHON_RESET                                        0x0
#define CHN1_TXBB_0_CALFC_EN_PGA_LSB                                           19
#define CHN1_TXBB_0_CALFC_EN_PGA_MSB                                           19
#define CHN1_TXBB_0_CALFC_EN_PGA_MASK                                          0x80000
#define CHN1_TXBB_0_CALFC_EN_PGA_GET(x)                                        (((x) & CHN1_TXBB_0_CALFC_EN_PGA_MASK) >> CHN1_TXBB_0_CALFC_EN_PGA_LSB)
#define CHN1_TXBB_0_CALFC_EN_PGA_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALFC_EN_PGA_LSB) & CHN1_TXBB_0_CALFC_EN_PGA_MASK)
#define CHN1_TXBB_0_CALFC_EN_PGA_RESET                                         0x1
#define CHN1_TXBB_0_CALFC_EN_BQ1_LSB                                           18
#define CHN1_TXBB_0_CALFC_EN_BQ1_MSB                                           18
#define CHN1_TXBB_0_CALFC_EN_BQ1_MASK                                          0x40000
#define CHN1_TXBB_0_CALFC_EN_BQ1_GET(x)                                        (((x) & CHN1_TXBB_0_CALFC_EN_BQ1_MASK) >> CHN1_TXBB_0_CALFC_EN_BQ1_LSB)
#define CHN1_TXBB_0_CALFC_EN_BQ1_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALFC_EN_BQ1_LSB) & CHN1_TXBB_0_CALFC_EN_BQ1_MASK)
#define CHN1_TXBB_0_CALFC_EN_BQ1_RESET                                         0x1
#define CHN1_TXBB_0_CALFC_EN_BQ2_LSB                                           17
#define CHN1_TXBB_0_CALFC_EN_BQ2_MSB                                           17
#define CHN1_TXBB_0_CALFC_EN_BQ2_MASK                                          0x20000
#define CHN1_TXBB_0_CALFC_EN_BQ2_GET(x)                                        (((x) & CHN1_TXBB_0_CALFC_EN_BQ2_MASK) >> CHN1_TXBB_0_CALFC_EN_BQ2_LSB)
#define CHN1_TXBB_0_CALFC_EN_BQ2_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALFC_EN_BQ2_LSB) & CHN1_TXBB_0_CALFC_EN_BQ2_MASK)
#define CHN1_TXBB_0_CALFC_EN_BQ2_RESET                                         0x1
#define CHN1_TXBB_0_CALFC_EN_V2I_LSB                                           16
#define CHN1_TXBB_0_CALFC_EN_V2I_MSB                                           16
#define CHN1_TXBB_0_CALFC_EN_V2I_MASK                                          0x10000
#define CHN1_TXBB_0_CALFC_EN_V2I_GET(x)                                        (((x) & CHN1_TXBB_0_CALFC_EN_V2I_MASK) >> CHN1_TXBB_0_CALFC_EN_V2I_LSB)
#define CHN1_TXBB_0_CALFC_EN_V2I_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALFC_EN_V2I_LSB) & CHN1_TXBB_0_CALFC_EN_V2I_MASK)
#define CHN1_TXBB_0_CALFC_EN_V2I_RESET                                         0x0
#define CHN1_TXBB_0_CALTX_BQ2V2I_EN_LSB                                        15
#define CHN1_TXBB_0_CALTX_BQ2V2I_EN_MSB                                        15
#define CHN1_TXBB_0_CALTX_BQ2V2I_EN_MASK                                       0x8000
#define CHN1_TXBB_0_CALTX_BQ2V2I_EN_GET(x)                                     (((x) & CHN1_TXBB_0_CALTX_BQ2V2I_EN_MASK) >> CHN1_TXBB_0_CALTX_BQ2V2I_EN_LSB)
#define CHN1_TXBB_0_CALTX_BQ2V2I_EN_SET(x)                                     (((0 | (x)) << CHN1_TXBB_0_CALTX_BQ2V2I_EN_LSB) & CHN1_TXBB_0_CALTX_BQ2V2I_EN_MASK)
#define CHN1_TXBB_0_CALTX_BQ2V2I_EN_RESET                                      0x1
#define CHN1_TXBB_0_CALTX_DAC2V2I_EN_LSB                                       14
#define CHN1_TXBB_0_CALTX_DAC2V2I_EN_MSB                                       14
#define CHN1_TXBB_0_CALTX_DAC2V2I_EN_MASK                                      0x4000
#define CHN1_TXBB_0_CALTX_DAC2V2I_EN_GET(x)                                    (((x) & CHN1_TXBB_0_CALTX_DAC2V2I_EN_MASK) >> CHN1_TXBB_0_CALTX_DAC2V2I_EN_LSB)
#define CHN1_TXBB_0_CALTX_DAC2V2I_EN_SET(x)                                    (((0 | (x)) << CHN1_TXBB_0_CALTX_DAC2V2I_EN_LSB) & CHN1_TXBB_0_CALTX_DAC2V2I_EN_MASK)
#define CHN1_TXBB_0_CALTX_DAC2V2I_EN_RESET                                     0x0
#define CHN1_TXBB_0_CALTX_TX2RXOUT_EN_LSB                                      13
#define CHN1_TXBB_0_CALTX_TX2RXOUT_EN_MSB                                      13
#define CHN1_TXBB_0_CALTX_TX2RXOUT_EN_MASK                                     0x2000
#define CHN1_TXBB_0_CALTX_TX2RXOUT_EN_GET(x)                                   (((x) & CHN1_TXBB_0_CALTX_TX2RXOUT_EN_MASK) >> CHN1_TXBB_0_CALTX_TX2RXOUT_EN_LSB)
#define CHN1_TXBB_0_CALTX_TX2RXOUT_EN_SET(x)                                   (((0 | (x)) << CHN1_TXBB_0_CALTX_TX2RXOUT_EN_LSB) & CHN1_TXBB_0_CALTX_TX2RXOUT_EN_MASK)
#define CHN1_TXBB_0_CALTX_TX2RXOUT_EN_RESET                                    0x0
#define CHN1_TXBB_0_CALTX_NOTCHON_LSB                                          12
#define CHN1_TXBB_0_CALTX_NOTCHON_MSB                                          12
#define CHN1_TXBB_0_CALTX_NOTCHON_MASK                                         0x1000
#define CHN1_TXBB_0_CALTX_NOTCHON_GET(x)                                       (((x) & CHN1_TXBB_0_CALTX_NOTCHON_MASK) >> CHN1_TXBB_0_CALTX_NOTCHON_LSB)
#define CHN1_TXBB_0_CALTX_NOTCHON_SET(x)                                       (((0 | (x)) << CHN1_TXBB_0_CALTX_NOTCHON_LSB) & CHN1_TXBB_0_CALTX_NOTCHON_MASK)
#define CHN1_TXBB_0_CALTX_NOTCHON_RESET                                        0x1
#define CHN1_TXBB_0_CALTX_EN_PGA_LSB                                           11
#define CHN1_TXBB_0_CALTX_EN_PGA_MSB                                           11
#define CHN1_TXBB_0_CALTX_EN_PGA_MASK                                          0x800
#define CHN1_TXBB_0_CALTX_EN_PGA_GET(x)                                        (((x) & CHN1_TXBB_0_CALTX_EN_PGA_MASK) >> CHN1_TXBB_0_CALTX_EN_PGA_LSB)
#define CHN1_TXBB_0_CALTX_EN_PGA_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALTX_EN_PGA_LSB) & CHN1_TXBB_0_CALTX_EN_PGA_MASK)
#define CHN1_TXBB_0_CALTX_EN_PGA_RESET                                         0x1
#define CHN1_TXBB_0_CALTX_EN_BQ1_LSB                                           10
#define CHN1_TXBB_0_CALTX_EN_BQ1_MSB                                           10
#define CHN1_TXBB_0_CALTX_EN_BQ1_MASK                                          0x400
#define CHN1_TXBB_0_CALTX_EN_BQ1_GET(x)                                        (((x) & CHN1_TXBB_0_CALTX_EN_BQ1_MASK) >> CHN1_TXBB_0_CALTX_EN_BQ1_LSB)
#define CHN1_TXBB_0_CALTX_EN_BQ1_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALTX_EN_BQ1_LSB) & CHN1_TXBB_0_CALTX_EN_BQ1_MASK)
#define CHN1_TXBB_0_CALTX_EN_BQ1_RESET                                         0x1
#define CHN1_TXBB_0_CALTX_EN_BQ2_LSB                                           9
#define CHN1_TXBB_0_CALTX_EN_BQ2_MSB                                           9
#define CHN1_TXBB_0_CALTX_EN_BQ2_MASK                                          0x200
#define CHN1_TXBB_0_CALTX_EN_BQ2_GET(x)                                        (((x) & CHN1_TXBB_0_CALTX_EN_BQ2_MASK) >> CHN1_TXBB_0_CALTX_EN_BQ2_LSB)
#define CHN1_TXBB_0_CALTX_EN_BQ2_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALTX_EN_BQ2_LSB) & CHN1_TXBB_0_CALTX_EN_BQ2_MASK)
#define CHN1_TXBB_0_CALTX_EN_BQ2_RESET                                         0x1
#define CHN1_TXBB_0_CALTX_EN_V2I_LSB                                           8
#define CHN1_TXBB_0_CALTX_EN_V2I_MSB                                           8
#define CHN1_TXBB_0_CALTX_EN_V2I_MASK                                          0x100
#define CHN1_TXBB_0_CALTX_EN_V2I_GET(x)                                        (((x) & CHN1_TXBB_0_CALTX_EN_V2I_MASK) >> CHN1_TXBB_0_CALTX_EN_V2I_LSB)
#define CHN1_TXBB_0_CALTX_EN_V2I_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALTX_EN_V2I_LSB) & CHN1_TXBB_0_CALTX_EN_V2I_MASK)
#define CHN1_TXBB_0_CALTX_EN_V2I_RESET                                         0x1
#define CHN1_TXBB_0_CALRX_BQ2V2I_EN_LSB                                        7
#define CHN1_TXBB_0_CALRX_BQ2V2I_EN_MSB                                        7
#define CHN1_TXBB_0_CALRX_BQ2V2I_EN_MASK                                       0x80
#define CHN1_TXBB_0_CALRX_BQ2V2I_EN_GET(x)                                     (((x) & CHN1_TXBB_0_CALRX_BQ2V2I_EN_MASK) >> CHN1_TXBB_0_CALRX_BQ2V2I_EN_LSB)
#define CHN1_TXBB_0_CALRX_BQ2V2I_EN_SET(x)                                     (((0 | (x)) << CHN1_TXBB_0_CALRX_BQ2V2I_EN_LSB) & CHN1_TXBB_0_CALRX_BQ2V2I_EN_MASK)
#define CHN1_TXBB_0_CALRX_BQ2V2I_EN_RESET                                      0x1
#define CHN1_TXBB_0_CALRX_DAC2V2I_EN_LSB                                       6
#define CHN1_TXBB_0_CALRX_DAC2V2I_EN_MSB                                       6
#define CHN1_TXBB_0_CALRX_DAC2V2I_EN_MASK                                      0x40
#define CHN1_TXBB_0_CALRX_DAC2V2I_EN_GET(x)                                    (((x) & CHN1_TXBB_0_CALRX_DAC2V2I_EN_MASK) >> CHN1_TXBB_0_CALRX_DAC2V2I_EN_LSB)
#define CHN1_TXBB_0_CALRX_DAC2V2I_EN_SET(x)                                    (((0 | (x)) << CHN1_TXBB_0_CALRX_DAC2V2I_EN_LSB) & CHN1_TXBB_0_CALRX_DAC2V2I_EN_MASK)
#define CHN1_TXBB_0_CALRX_DAC2V2I_EN_RESET                                     0x0
#define CHN1_TXBB_0_CALRX_TX2RXOUT_EN_LSB                                      5
#define CHN1_TXBB_0_CALRX_TX2RXOUT_EN_MSB                                      5
#define CHN1_TXBB_0_CALRX_TX2RXOUT_EN_MASK                                     0x20
#define CHN1_TXBB_0_CALRX_TX2RXOUT_EN_GET(x)                                   (((x) & CHN1_TXBB_0_CALRX_TX2RXOUT_EN_MASK) >> CHN1_TXBB_0_CALRX_TX2RXOUT_EN_LSB)
#define CHN1_TXBB_0_CALRX_TX2RXOUT_EN_SET(x)                                   (((0 | (x)) << CHN1_TXBB_0_CALRX_TX2RXOUT_EN_LSB) & CHN1_TXBB_0_CALRX_TX2RXOUT_EN_MASK)
#define CHN1_TXBB_0_CALRX_TX2RXOUT_EN_RESET                                    0x0
#define CHN1_TXBB_0_CALRX_NOTCHON_LSB                                          4
#define CHN1_TXBB_0_CALRX_NOTCHON_MSB                                          4
#define CHN1_TXBB_0_CALRX_NOTCHON_MASK                                         0x10
#define CHN1_TXBB_0_CALRX_NOTCHON_GET(x)                                       (((x) & CHN1_TXBB_0_CALRX_NOTCHON_MASK) >> CHN1_TXBB_0_CALRX_NOTCHON_LSB)
#define CHN1_TXBB_0_CALRX_NOTCHON_SET(x)                                       (((0 | (x)) << CHN1_TXBB_0_CALRX_NOTCHON_LSB) & CHN1_TXBB_0_CALRX_NOTCHON_MASK)
#define CHN1_TXBB_0_CALRX_NOTCHON_RESET                                        0x1
#define CHN1_TXBB_0_CALRX_EN_PGA_LSB                                           3
#define CHN1_TXBB_0_CALRX_EN_PGA_MSB                                           3
#define CHN1_TXBB_0_CALRX_EN_PGA_MASK                                          0x8
#define CHN1_TXBB_0_CALRX_EN_PGA_GET(x)                                        (((x) & CHN1_TXBB_0_CALRX_EN_PGA_MASK) >> CHN1_TXBB_0_CALRX_EN_PGA_LSB)
#define CHN1_TXBB_0_CALRX_EN_PGA_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALRX_EN_PGA_LSB) & CHN1_TXBB_0_CALRX_EN_PGA_MASK)
#define CHN1_TXBB_0_CALRX_EN_PGA_RESET                                         0x1
#define CHN1_TXBB_0_CALRX_EN_BQ1_LSB                                           2
#define CHN1_TXBB_0_CALRX_EN_BQ1_MSB                                           2
#define CHN1_TXBB_0_CALRX_EN_BQ1_MASK                                          0x4
#define CHN1_TXBB_0_CALRX_EN_BQ1_GET(x)                                        (((x) & CHN1_TXBB_0_CALRX_EN_BQ1_MASK) >> CHN1_TXBB_0_CALRX_EN_BQ1_LSB)
#define CHN1_TXBB_0_CALRX_EN_BQ1_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALRX_EN_BQ1_LSB) & CHN1_TXBB_0_CALRX_EN_BQ1_MASK)
#define CHN1_TXBB_0_CALRX_EN_BQ1_RESET                                         0x1
#define CHN1_TXBB_0_CALRX_EN_BQ2_LSB                                           1
#define CHN1_TXBB_0_CALRX_EN_BQ2_MSB                                           1
#define CHN1_TXBB_0_CALRX_EN_BQ2_MASK                                          0x2
#define CHN1_TXBB_0_CALRX_EN_BQ2_GET(x)                                        (((x) & CHN1_TXBB_0_CALRX_EN_BQ2_MASK) >> CHN1_TXBB_0_CALRX_EN_BQ2_LSB)
#define CHN1_TXBB_0_CALRX_EN_BQ2_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALRX_EN_BQ2_LSB) & CHN1_TXBB_0_CALRX_EN_BQ2_MASK)
#define CHN1_TXBB_0_CALRX_EN_BQ2_RESET                                         0x1
#define CHN1_TXBB_0_CALRX_EN_V2I_LSB                                           0
#define CHN1_TXBB_0_CALRX_EN_V2I_MSB                                           0
#define CHN1_TXBB_0_CALRX_EN_V2I_MASK                                          0x1
#define CHN1_TXBB_0_CALRX_EN_V2I_GET(x)                                        (((x) & CHN1_TXBB_0_CALRX_EN_V2I_MASK) >> CHN1_TXBB_0_CALRX_EN_V2I_LSB)
#define CHN1_TXBB_0_CALRX_EN_V2I_SET(x)                                        (((0 | (x)) << CHN1_TXBB_0_CALRX_EN_V2I_LSB) & CHN1_TXBB_0_CALRX_EN_V2I_MASK)
#define CHN1_TXBB_0_CALRX_EN_V2I_RESET                                         0x1
#define CHN1_TXBB_0_ADDRESS                                                    (0x0 + __CHN1_TXBB_REG_CSR_BASE_ADDRESS)
#define CHN1_TXBB_0_RSTMASK                                                    0xffffffff
#define CHN1_TXBB_0_RESET                                                      0x9f2e9f9f

// 0x4 (CHN1_TXBB_1)
#define CHN1_TXBB_1_CALXPA_BQ2V2I_EN_LSB                                       31
#define CHN1_TXBB_1_CALXPA_BQ2V2I_EN_MSB                                       31
#define CHN1_TXBB_1_CALXPA_BQ2V2I_EN_MASK                                      0x80000000
#define CHN1_TXBB_1_CALXPA_BQ2V2I_EN_GET(x)                                    (((x) & CHN1_TXBB_1_CALXPA_BQ2V2I_EN_MASK) >> CHN1_TXBB_1_CALXPA_BQ2V2I_EN_LSB)
#define CHN1_TXBB_1_CALXPA_BQ2V2I_EN_SET(x)                                    (((0 | (x)) << CHN1_TXBB_1_CALXPA_BQ2V2I_EN_LSB) & CHN1_TXBB_1_CALXPA_BQ2V2I_EN_MASK)
#define CHN1_TXBB_1_CALXPA_BQ2V2I_EN_RESET                                     0x1
#define CHN1_TXBB_1_CALXPA_DAC2V2I_EN_LSB                                      30
#define CHN1_TXBB_1_CALXPA_DAC2V2I_EN_MSB                                      30
#define CHN1_TXBB_1_CALXPA_DAC2V2I_EN_MASK                                     0x40000000
#define CHN1_TXBB_1_CALXPA_DAC2V2I_EN_GET(x)                                   (((x) & CHN1_TXBB_1_CALXPA_DAC2V2I_EN_MASK) >> CHN1_TXBB_1_CALXPA_DAC2V2I_EN_LSB)
#define CHN1_TXBB_1_CALXPA_DAC2V2I_EN_SET(x)                                   (((0 | (x)) << CHN1_TXBB_1_CALXPA_DAC2V2I_EN_LSB) & CHN1_TXBB_1_CALXPA_DAC2V2I_EN_MASK)
#define CHN1_TXBB_1_CALXPA_DAC2V2I_EN_RESET                                    0x0
#define CHN1_TXBB_1_CALXPA_TX2RXOUT_EN_LSB                                     29
#define CHN1_TXBB_1_CALXPA_TX2RXOUT_EN_MSB                                     29
#define CHN1_TXBB_1_CALXPA_TX2RXOUT_EN_MASK                                    0x20000000
#define CHN1_TXBB_1_CALXPA_TX2RXOUT_EN_GET(x)                                  (((x) & CHN1_TXBB_1_CALXPA_TX2RXOUT_EN_MASK) >> CHN1_TXBB_1_CALXPA_TX2RXOUT_EN_LSB)
#define CHN1_TXBB_1_CALXPA_TX2RXOUT_EN_SET(x)                                  (((0 | (x)) << CHN1_TXBB_1_CALXPA_TX2RXOUT_EN_LSB) & CHN1_TXBB_1_CALXPA_TX2RXOUT_EN_MASK)
#define CHN1_TXBB_1_CALXPA_TX2RXOUT_EN_RESET                                   0x0
#define CHN1_TXBB_1_CALXPA_NOTCHON_LSB                                         28
#define CHN1_TXBB_1_CALXPA_NOTCHON_MSB                                         28
#define CHN1_TXBB_1_CALXPA_NOTCHON_MASK                                        0x10000000
#define CHN1_TXBB_1_CALXPA_NOTCHON_GET(x)                                      (((x) & CHN1_TXBB_1_CALXPA_NOTCHON_MASK) >> CHN1_TXBB_1_CALXPA_NOTCHON_LSB)
#define CHN1_TXBB_1_CALXPA_NOTCHON_SET(x)                                      (((0 | (x)) << CHN1_TXBB_1_CALXPA_NOTCHON_LSB) & CHN1_TXBB_1_CALXPA_NOTCHON_MASK)
#define CHN1_TXBB_1_CALXPA_NOTCHON_RESET                                       0x1
#define CHN1_TXBB_1_CALXPA_EN_PGA_LSB                                          27
#define CHN1_TXBB_1_CALXPA_EN_PGA_MSB                                          27
#define CHN1_TXBB_1_CALXPA_EN_PGA_MASK                                         0x8000000
#define CHN1_TXBB_1_CALXPA_EN_PGA_GET(x)                                       (((x) & CHN1_TXBB_1_CALXPA_EN_PGA_MASK) >> CHN1_TXBB_1_CALXPA_EN_PGA_LSB)
#define CHN1_TXBB_1_CALXPA_EN_PGA_SET(x)                                       (((0 | (x)) << CHN1_TXBB_1_CALXPA_EN_PGA_LSB) & CHN1_TXBB_1_CALXPA_EN_PGA_MASK)
#define CHN1_TXBB_1_CALXPA_EN_PGA_RESET                                        0x1
#define CHN1_TXBB_1_CALXPA_EN_BQ1_LSB                                          26
#define CHN1_TXBB_1_CALXPA_EN_BQ1_MSB                                          26
#define CHN1_TXBB_1_CALXPA_EN_BQ1_MASK                                         0x4000000
#define CHN1_TXBB_1_CALXPA_EN_BQ1_GET(x)                                       (((x) & CHN1_TXBB_1_CALXPA_EN_BQ1_MASK) >> CHN1_TXBB_1_CALXPA_EN_BQ1_LSB)
#define CHN1_TXBB_1_CALXPA_EN_BQ1_SET(x)                                       (((0 | (x)) << CHN1_TXBB_1_CALXPA_EN_BQ1_LSB) & CHN1_TXBB_1_CALXPA_EN_BQ1_MASK)
#define CHN1_TXBB_1_CALXPA_EN_BQ1_RESET                                        0x1
#define CHN1_TXBB_1_CALXPA_EN_BQ2_LSB                                          25
#define CHN1_TXBB_1_CALXPA_EN_BQ2_MSB                                          25
#define CHN1_TXBB_1_CALXPA_EN_BQ2_MASK                                         0x2000000
#define CHN1_TXBB_1_CALXPA_EN_BQ2_GET(x)                                       (((x) & CHN1_TXBB_1_CALXPA_EN_BQ2_MASK) >> CHN1_TXBB_1_CALXPA_EN_BQ2_LSB)
#define CHN1_TXBB_1_CALXPA_EN_BQ2_SET(x)                                       (((0 | (x)) << CHN1_TXBB_1_CALXPA_EN_BQ2_LSB) & CHN1_TXBB_1_CALXPA_EN_BQ2_MASK)
#define CHN1_TXBB_1_CALXPA_EN_BQ2_RESET                                        0x1
#define CHN1_TXBB_1_CALXPA_EN_V2I_LSB                                          24
#define CHN1_TXBB_1_CALXPA_EN_V2I_MSB                                          24
#define CHN1_TXBB_1_CALXPA_EN_V2I_MASK                                         0x1000000
#define CHN1_TXBB_1_CALXPA_EN_V2I_GET(x)                                       (((x) & CHN1_TXBB_1_CALXPA_EN_V2I_MASK) >> CHN1_TXBB_1_CALXPA_EN_V2I_LSB)
#define CHN1_TXBB_1_CALXPA_EN_V2I_SET(x)                                       (((0 | (x)) << CHN1_TXBB_1_CALXPA_EN_V2I_LSB) & CHN1_TXBB_1_CALXPA_EN_V2I_MASK)
#define CHN1_TXBB_1_CALXPA_EN_V2I_RESET                                        0x1
#define CHN1_TXBB_1_CALTX_EN_DA_RF_LSB                                         23
#define CHN1_TXBB_1_CALTX_EN_DA_RF_MSB                                         23
#define CHN1_TXBB_1_CALTX_EN_DA_RF_MASK                                        0x800000
#define CHN1_TXBB_1_CALTX_EN_DA_RF_GET(x)                                      (((x) & CHN1_TXBB_1_CALTX_EN_DA_RF_MASK) >> CHN1_TXBB_1_CALTX_EN_DA_RF_LSB)
#define CHN1_TXBB_1_CALTX_EN_DA_RF_SET(x)                                      (((0 | (x)) << CHN1_TXBB_1_CALTX_EN_DA_RF_LSB) & CHN1_TXBB_1_CALTX_EN_DA_RF_MASK)
#define CHN1_TXBB_1_CALTX_EN_DA_RF_RESET                                       0x1
#define CHN1_TXBB_1_CALRX_EN_DA_RF_LSB                                         22
#define CHN1_TXBB_1_CALRX_EN_DA_RF_MSB                                         22
#define CHN1_TXBB_1_CALRX_EN_DA_RF_MASK                                        0x400000
#define CHN1_TXBB_1_CALRX_EN_DA_RF_GET(x)                                      (((x) & CHN1_TXBB_1_CALRX_EN_DA_RF_MASK) >> CHN1_TXBB_1_CALRX_EN_DA_RF_LSB)
#define CHN1_TXBB_1_CALRX_EN_DA_RF_SET(x)                                      (((0 | (x)) << CHN1_TXBB_1_CALRX_EN_DA_RF_LSB) & CHN1_TXBB_1_CALRX_EN_DA_RF_MASK)
#define CHN1_TXBB_1_CALRX_EN_DA_RF_RESET                                       0x1
#define CHN1_TXBB_1_EN_DA_RF_OVR_LSB                                           20
#define CHN1_TXBB_1_EN_DA_RF_OVR_MSB                                           21
#define CHN1_TXBB_1_EN_DA_RF_OVR_MASK                                          0x300000
#define CHN1_TXBB_1_EN_DA_RF_OVR_GET(x)                                        (((x) & CHN1_TXBB_1_EN_DA_RF_OVR_MASK) >> CHN1_TXBB_1_EN_DA_RF_OVR_LSB)
#define CHN1_TXBB_1_EN_DA_RF_OVR_SET(x)                                        (((0 | (x)) << CHN1_TXBB_1_EN_DA_RF_OVR_LSB) & CHN1_TXBB_1_EN_DA_RF_OVR_MASK)
#define CHN1_TXBB_1_EN_DA_RF_OVR_RESET                                         0x0
#define CHN1_TXBB_1_EN_PGA_OVR_LSB                                             18
#define CHN1_TXBB_1_EN_PGA_OVR_MSB                                             19
#define CHN1_TXBB_1_EN_PGA_OVR_MASK                                            0xc0000
#define CHN1_TXBB_1_EN_PGA_OVR_GET(x)                                          (((x) & CHN1_TXBB_1_EN_PGA_OVR_MASK) >> CHN1_TXBB_1_EN_PGA_OVR_LSB)
#define CHN1_TXBB_1_EN_PGA_OVR_SET(x)                                          (((0 | (x)) << CHN1_TXBB_1_EN_PGA_OVR_LSB) & CHN1_TXBB_1_EN_PGA_OVR_MASK)
#define CHN1_TXBB_1_EN_PGA_OVR_RESET                                           0x0
#define CHN1_TXBB_1_EN_BQ1_OVR_LSB                                             16
#define CHN1_TXBB_1_EN_BQ1_OVR_MSB                                             17
#define CHN1_TXBB_1_EN_BQ1_OVR_MASK                                            0x30000
#define CHN1_TXBB_1_EN_BQ1_OVR_GET(x)                                          (((x) & CHN1_TXBB_1_EN_BQ1_OVR_MASK) >> CHN1_TXBB_1_EN_BQ1_OVR_LSB)
#define CHN1_TXBB_1_EN_BQ1_OVR_SET(x)                                          (((0 | (x)) << CHN1_TXBB_1_EN_BQ1_OVR_LSB) & CHN1_TXBB_1_EN_BQ1_OVR_MASK)
#define CHN1_TXBB_1_EN_BQ1_OVR_RESET                                           0x0
#define CHN1_TXBB_1_EN_BQ2_OVR_LSB                                             14
#define CHN1_TXBB_1_EN_BQ2_OVR_MSB                                             15
#define CHN1_TXBB_1_EN_BQ2_OVR_MASK                                            0xc000
#define CHN1_TXBB_1_EN_BQ2_OVR_GET(x)                                          (((x) & CHN1_TXBB_1_EN_BQ2_OVR_MASK) >> CHN1_TXBB_1_EN_BQ2_OVR_LSB)
#define CHN1_TXBB_1_EN_BQ2_OVR_SET(x)                                          (((0 | (x)) << CHN1_TXBB_1_EN_BQ2_OVR_LSB) & CHN1_TXBB_1_EN_BQ2_OVR_MASK)
#define CHN1_TXBB_1_EN_BQ2_OVR_RESET                                           0x0
#define CHN1_TXBB_1_EN_V2I_OVR_LSB                                             12
#define CHN1_TXBB_1_EN_V2I_OVR_MSB                                             13
#define CHN1_TXBB_1_EN_V2I_OVR_MASK                                            0x3000
#define CHN1_TXBB_1_EN_V2I_OVR_GET(x)                                          (((x) & CHN1_TXBB_1_EN_V2I_OVR_MASK) >> CHN1_TXBB_1_EN_V2I_OVR_LSB)
#define CHN1_TXBB_1_EN_V2I_OVR_SET(x)                                          (((0 | (x)) << CHN1_TXBB_1_EN_V2I_OVR_LSB) & CHN1_TXBB_1_EN_V2I_OVR_MASK)
#define CHN1_TXBB_1_EN_V2I_OVR_RESET                                           0x0
#define CHN1_TXBB_1_EN_BIAS_OVR_LSB                                            10
#define CHN1_TXBB_1_EN_BIAS_OVR_MSB                                            11
#define CHN1_TXBB_1_EN_BIAS_OVR_MASK                                           0xc00
#define CHN1_TXBB_1_EN_BIAS_OVR_GET(x)                                         (((x) & CHN1_TXBB_1_EN_BIAS_OVR_MASK) >> CHN1_TXBB_1_EN_BIAS_OVR_LSB)
#define CHN1_TXBB_1_EN_BIAS_OVR_SET(x)                                         (((0 | (x)) << CHN1_TXBB_1_EN_BIAS_OVR_LSB) & CHN1_TXBB_1_EN_BIAS_OVR_MASK)
#define CHN1_TXBB_1_EN_BIAS_OVR_RESET                                          0x0
#define CHN1_TXBB_1_SWITCH_OVERRIDE_LSB                                        9
#define CHN1_TXBB_1_SWITCH_OVERRIDE_MSB                                        9
#define CHN1_TXBB_1_SWITCH_OVERRIDE_MASK                                       0x200
#define CHN1_TXBB_1_SWITCH_OVERRIDE_GET(x)                                     (((x) & CHN1_TXBB_1_SWITCH_OVERRIDE_MASK) >> CHN1_TXBB_1_SWITCH_OVERRIDE_LSB)
#define CHN1_TXBB_1_SWITCH_OVERRIDE_SET(x)                                     (((0 | (x)) << CHN1_TXBB_1_SWITCH_OVERRIDE_LSB) & CHN1_TXBB_1_SWITCH_OVERRIDE_MASK)
#define CHN1_TXBB_1_SWITCH_OVERRIDE_RESET                                      0x0
#define CHN1_TXBB_1_BQ2V2I_EN_LS_LSB                                           8
#define CHN1_TXBB_1_BQ2V2I_EN_LS_MSB                                           8
#define CHN1_TXBB_1_BQ2V2I_EN_LS_MASK                                          0x100
#define CHN1_TXBB_1_BQ2V2I_EN_LS_GET(x)                                        (((x) & CHN1_TXBB_1_BQ2V2I_EN_LS_MASK) >> CHN1_TXBB_1_BQ2V2I_EN_LS_LSB)
#define CHN1_TXBB_1_BQ2V2I_EN_LS_SET(x)                                        (((0 | (x)) << CHN1_TXBB_1_BQ2V2I_EN_LS_LSB) & CHN1_TXBB_1_BQ2V2I_EN_LS_MASK)
#define CHN1_TXBB_1_BQ2V2I_EN_LS_RESET                                         0x1
#define CHN1_TXBB_1_DAC2V2I_EN_LS_LSB                                          7
#define CHN1_TXBB_1_DAC2V2I_EN_LS_MSB                                          7
#define CHN1_TXBB_1_DAC2V2I_EN_LS_MASK                                         0x80
#define CHN1_TXBB_1_DAC2V2I_EN_LS_GET(x)                                       (((x) & CHN1_TXBB_1_DAC2V2I_EN_LS_MASK) >> CHN1_TXBB_1_DAC2V2I_EN_LS_LSB)
#define CHN1_TXBB_1_DAC2V2I_EN_LS_SET(x)                                       (((0 | (x)) << CHN1_TXBB_1_DAC2V2I_EN_LS_LSB) & CHN1_TXBB_1_DAC2V2I_EN_LS_MASK)
#define CHN1_TXBB_1_DAC2V2I_EN_LS_RESET                                        0x0
#define CHN1_TXBB_1_TX2RXOUT_EN_LS_LSB                                         6
#define CHN1_TXBB_1_TX2RXOUT_EN_LS_MSB                                         6
#define CHN1_TXBB_1_TX2RXOUT_EN_LS_MASK                                        0x40
#define CHN1_TXBB_1_TX2RXOUT_EN_LS_GET(x)                                      (((x) & CHN1_TXBB_1_TX2RXOUT_EN_LS_MASK) >> CHN1_TXBB_1_TX2RXOUT_EN_LS_LSB)
#define CHN1_TXBB_1_TX2RXOUT_EN_LS_SET(x)                                      (((0 | (x)) << CHN1_TXBB_1_TX2RXOUT_EN_LS_LSB) & CHN1_TXBB_1_TX2RXOUT_EN_LS_MASK)
#define CHN1_TXBB_1_TX2RXOUT_EN_LS_RESET                                       0x0
#define CHN1_TXBB_1_NOTCHON_LS_LSB                                             5
#define CHN1_TXBB_1_NOTCHON_LS_MSB                                             5
#define CHN1_TXBB_1_NOTCHON_LS_MASK                                            0x20
#define CHN1_TXBB_1_NOTCHON_LS_GET(x)                                          (((x) & CHN1_TXBB_1_NOTCHON_LS_MASK) >> CHN1_TXBB_1_NOTCHON_LS_LSB)
#define CHN1_TXBB_1_NOTCHON_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_1_NOTCHON_LS_LSB) & CHN1_TXBB_1_NOTCHON_LS_MASK)
#define CHN1_TXBB_1_NOTCHON_LS_RESET                                           0x1
#define CHN1_TXBB_1_RESERVED_0_LSB                                             0
#define CHN1_TXBB_1_RESERVED_0_MSB                                             4
#define CHN1_TXBB_1_RESERVED_0_MASK                                            0x1f
#define CHN1_TXBB_1_RESERVED_0_GET(x)                                          (((x) & CHN1_TXBB_1_RESERVED_0_MASK) >> CHN1_TXBB_1_RESERVED_0_LSB)
#define CHN1_TXBB_1_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN1_TXBB_1_RESERVED_0_LSB) & CHN1_TXBB_1_RESERVED_0_MASK)
#define CHN1_TXBB_1_RESERVED_0_RESET                                           0x0
#define CHN1_TXBB_1_ADDRESS                                                    (0x4 + __CHN1_TXBB_REG_CSR_BASE_ADDRESS)
#define CHN1_TXBB_1_RSTMASK                                                    0xffffffff
#define CHN1_TXBB_1_RESET                                                      0x9fc00120

// 0x8 (CHN1_TXBB_2)
#define CHN1_TXBB_2_MANTXGAIN_LSB                                              31
#define CHN1_TXBB_2_MANTXGAIN_MSB                                              31
#define CHN1_TXBB_2_MANTXGAIN_MASK                                             0x80000000
#define CHN1_TXBB_2_MANTXGAIN_GET(x)                                           (((x) & CHN1_TXBB_2_MANTXGAIN_MASK) >> CHN1_TXBB_2_MANTXGAIN_LSB)
#define CHN1_TXBB_2_MANTXGAIN_SET(x)                                           (((0 | (x)) << CHN1_TXBB_2_MANTXGAIN_LSB) & CHN1_TXBB_2_MANTXGAIN_MASK)
#define CHN1_TXBB_2_MANTXGAIN_RESET                                            0x0
#define CHN1_TXBB_2_V2IGAIN_2X_LS_LSB                                          30
#define CHN1_TXBB_2_V2IGAIN_2X_LS_MSB                                          30
#define CHN1_TXBB_2_V2IGAIN_2X_LS_MASK                                         0x40000000
#define CHN1_TXBB_2_V2IGAIN_2X_LS_GET(x)                                       (((x) & CHN1_TXBB_2_V2IGAIN_2X_LS_MASK) >> CHN1_TXBB_2_V2IGAIN_2X_LS_LSB)
#define CHN1_TXBB_2_V2IGAIN_2X_LS_SET(x)                                       (((0 | (x)) << CHN1_TXBB_2_V2IGAIN_2X_LS_LSB) & CHN1_TXBB_2_V2IGAIN_2X_LS_MASK)
#define CHN1_TXBB_2_V2IGAIN_2X_LS_RESET                                        0x1
#define CHN1_TXBB_2_TX_BQ1_LS_LSB                                              29
#define CHN1_TXBB_2_TX_BQ1_LS_MSB                                              29
#define CHN1_TXBB_2_TX_BQ1_LS_MASK                                             0x20000000
#define CHN1_TXBB_2_TX_BQ1_LS_GET(x)                                           (((x) & CHN1_TXBB_2_TX_BQ1_LS_MASK) >> CHN1_TXBB_2_TX_BQ1_LS_LSB)
#define CHN1_TXBB_2_TX_BQ1_LS_SET(x)                                           (((0 | (x)) << CHN1_TXBB_2_TX_BQ1_LS_LSB) & CHN1_TXBB_2_TX_BQ1_LS_MASK)
#define CHN1_TXBB_2_TX_BQ1_LS_RESET                                            0x0
#define CHN1_TXBB_2_TX_BQ2_LS_LSB                                              25
#define CHN1_TXBB_2_TX_BQ2_LS_MSB                                              28
#define CHN1_TXBB_2_TX_BQ2_LS_MASK                                             0x1e000000
#define CHN1_TXBB_2_TX_BQ2_LS_GET(x)                                           (((x) & CHN1_TXBB_2_TX_BQ2_LS_MASK) >> CHN1_TXBB_2_TX_BQ2_LS_LSB)
#define CHN1_TXBB_2_TX_BQ2_LS_SET(x)                                           (((0 | (x)) << CHN1_TXBB_2_TX_BQ2_LS_LSB) & CHN1_TXBB_2_TX_BQ2_LS_MASK)
#define CHN1_TXBB_2_TX_BQ2_LS_RESET                                            0xf
#define CHN1_TXBB_2_TXBB_GC_LS_LSB                                             21
#define CHN1_TXBB_2_TXBB_GC_LS_MSB                                             24
#define CHN1_TXBB_2_TXBB_GC_LS_MASK                                            0x1e00000
#define CHN1_TXBB_2_TXBB_GC_LS_GET(x)                                          (((x) & CHN1_TXBB_2_TXBB_GC_LS_MASK) >> CHN1_TXBB_2_TXBB_GC_LS_LSB)
#define CHN1_TXBB_2_TXBB_GC_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_2_TXBB_GC_LS_LSB) & CHN1_TXBB_2_TXBB_GC_LS_MASK)
#define CHN1_TXBB_2_TXBB_GC_LS_RESET                                           0x3
#define CHN1_TXBB_2_DA_GC_LS_LSB                                               18
#define CHN1_TXBB_2_DA_GC_LS_MSB                                               20
#define CHN1_TXBB_2_DA_GC_LS_MASK                                              0x1c0000
#define CHN1_TXBB_2_DA_GC_LS_GET(x)                                            (((x) & CHN1_TXBB_2_DA_GC_LS_MASK) >> CHN1_TXBB_2_DA_GC_LS_LSB)
#define CHN1_TXBB_2_DA_GC_LS_SET(x)                                            (((0 | (x)) << CHN1_TXBB_2_DA_GC_LS_LSB) & CHN1_TXBB_2_DA_GC_LS_MASK)
#define CHN1_TXBB_2_DA_GC_LS_RESET                                             0x7
#define CHN1_TXBB_2_PGALPF_LS_LSB                                              16
#define CHN1_TXBB_2_PGALPF_LS_MSB                                              17
#define CHN1_TXBB_2_PGALPF_LS_MASK                                             0x30000
#define CHN1_TXBB_2_PGALPF_LS_GET(x)                                           (((x) & CHN1_TXBB_2_PGALPF_LS_MASK) >> CHN1_TXBB_2_PGALPF_LS_LSB)
#define CHN1_TXBB_2_PGALPF_LS_SET(x)                                           (((0 | (x)) << CHN1_TXBB_2_PGALPF_LS_LSB) & CHN1_TXBB_2_PGALPF_LS_MASK)
#define CHN1_TXBB_2_PGALPF_LS_RESET                                            0x0
#define CHN1_TXBB_2_BQ_S1_LS_LSB                                               14
#define CHN1_TXBB_2_BQ_S1_LS_MSB                                               15
#define CHN1_TXBB_2_BQ_S1_LS_MASK                                              0xc000
#define CHN1_TXBB_2_BQ_S1_LS_GET(x)                                            (((x) & CHN1_TXBB_2_BQ_S1_LS_MASK) >> CHN1_TXBB_2_BQ_S1_LS_LSB)
#define CHN1_TXBB_2_BQ_S1_LS_SET(x)                                            (((0 | (x)) << CHN1_TXBB_2_BQ_S1_LS_LSB) & CHN1_TXBB_2_BQ_S1_LS_MASK)
#define CHN1_TXBB_2_BQ_S1_LS_RESET                                             0x0
#define CHN1_TXBB_2_BQ_S2_LS_LSB                                               12
#define CHN1_TXBB_2_BQ_S2_LS_MSB                                               13
#define CHN1_TXBB_2_BQ_S2_LS_MASK                                              0x3000
#define CHN1_TXBB_2_BQ_S2_LS_GET(x)                                            (((x) & CHN1_TXBB_2_BQ_S2_LS_MASK) >> CHN1_TXBB_2_BQ_S2_LS_LSB)
#define CHN1_TXBB_2_BQ_S2_LS_SET(x)                                            (((0 | (x)) << CHN1_TXBB_2_BQ_S2_LS_LSB) & CHN1_TXBB_2_BQ_S2_LS_MASK)
#define CHN1_TXBB_2_BQ_S2_LS_RESET                                             0x0
#define CHN1_TXBB_2_PGA_S1_LSB                                                 10
#define CHN1_TXBB_2_PGA_S1_MSB                                                 11
#define CHN1_TXBB_2_PGA_S1_MASK                                                0xc00
#define CHN1_TXBB_2_PGA_S1_GET(x)                                              (((x) & CHN1_TXBB_2_PGA_S1_MASK) >> CHN1_TXBB_2_PGA_S1_LSB)
#define CHN1_TXBB_2_PGA_S1_SET(x)                                              (((0 | (x)) << CHN1_TXBB_2_PGA_S1_LSB) & CHN1_TXBB_2_PGA_S1_MASK)
#define CHN1_TXBB_2_PGA_S1_RESET                                               0x0
#define CHN1_TXBB_2_TXBW_OVERRIDE_LSB                                          9
#define CHN1_TXBB_2_TXBW_OVERRIDE_MSB                                          9
#define CHN1_TXBB_2_TXBW_OVERRIDE_MASK                                         0x200
#define CHN1_TXBB_2_TXBW_OVERRIDE_GET(x)                                       (((x) & CHN1_TXBB_2_TXBW_OVERRIDE_MASK) >> CHN1_TXBB_2_TXBW_OVERRIDE_LSB)
#define CHN1_TXBB_2_TXBW_OVERRIDE_SET(x)                                       (((0 | (x)) << CHN1_TXBB_2_TXBW_OVERRIDE_LSB) & CHN1_TXBB_2_TXBW_OVERRIDE_MASK)
#define CHN1_TXBB_2_TXBW_OVERRIDE_RESET                                        0x0
#define CHN1_TXBB_2_TXBB_BW_LS_LSB                                             4
#define CHN1_TXBB_2_TXBB_BW_LS_MSB                                             8
#define CHN1_TXBB_2_TXBB_BW_LS_MASK                                            0x1f0
#define CHN1_TXBB_2_TXBB_BW_LS_GET(x)                                          (((x) & CHN1_TXBB_2_TXBB_BW_LS_MASK) >> CHN1_TXBB_2_TXBB_BW_LS_LSB)
#define CHN1_TXBB_2_TXBB_BW_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_2_TXBB_BW_LS_LSB) & CHN1_TXBB_2_TXBB_BW_LS_MASK)
#define CHN1_TXBB_2_TXBB_BW_LS_RESET                                           0x0
#define CHN1_TXBB_2_BW_CALFC_LS_LSB                                            0
#define CHN1_TXBB_2_BW_CALFC_LS_MSB                                            3
#define CHN1_TXBB_2_BW_CALFC_LS_MASK                                           0xf
#define CHN1_TXBB_2_BW_CALFC_LS_GET(x)                                         (((x) & CHN1_TXBB_2_BW_CALFC_LS_MASK) >> CHN1_TXBB_2_BW_CALFC_LS_LSB)
#define CHN1_TXBB_2_BW_CALFC_LS_SET(x)                                         (((0 | (x)) << CHN1_TXBB_2_BW_CALFC_LS_LSB) & CHN1_TXBB_2_BW_CALFC_LS_MASK)
#define CHN1_TXBB_2_BW_CALFC_LS_RESET                                          0x0
#define CHN1_TXBB_2_ADDRESS                                                    (0x8 + __CHN1_TXBB_REG_CSR_BASE_ADDRESS)
#define CHN1_TXBB_2_RSTMASK                                                    0xffffffff
#define CHN1_TXBB_2_RESET                                                      0x5e7c0000

// 0xc (CHN1_TXBB_3)
#define CHN1_TXBB_3_BW0_LPF_LS_LSB                                             28
#define CHN1_TXBB_3_BW0_LPF_LS_MSB                                             31
#define CHN1_TXBB_3_BW0_LPF_LS_MASK                                            0xf0000000
#define CHN1_TXBB_3_BW0_LPF_LS_GET(x)                                          (((x) & CHN1_TXBB_3_BW0_LPF_LS_MASK) >> CHN1_TXBB_3_BW0_LPF_LS_LSB)
#define CHN1_TXBB_3_BW0_LPF_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_3_BW0_LPF_LS_LSB) & CHN1_TXBB_3_BW0_LPF_LS_MASK)
#define CHN1_TXBB_3_BW0_LPF_LS_RESET                                           0x1
#define CHN1_TXBB_3_BW1_LPF_LS_LSB                                             24
#define CHN1_TXBB_3_BW1_LPF_LS_MSB                                             27
#define CHN1_TXBB_3_BW1_LPF_LS_MASK                                            0xf000000
#define CHN1_TXBB_3_BW1_LPF_LS_GET(x)                                          (((x) & CHN1_TXBB_3_BW1_LPF_LS_MASK) >> CHN1_TXBB_3_BW1_LPF_LS_LSB)
#define CHN1_TXBB_3_BW1_LPF_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_3_BW1_LPF_LS_LSB) & CHN1_TXBB_3_BW1_LPF_LS_MASK)
#define CHN1_TXBB_3_BW1_LPF_LS_RESET                                           0x4
#define CHN1_TXBB_3_BW2_LPF_LS_LSB                                             20
#define CHN1_TXBB_3_BW2_LPF_LS_MSB                                             23
#define CHN1_TXBB_3_BW2_LPF_LS_MASK                                            0xf00000
#define CHN1_TXBB_3_BW2_LPF_LS_GET(x)                                          (((x) & CHN1_TXBB_3_BW2_LPF_LS_MASK) >> CHN1_TXBB_3_BW2_LPF_LS_LSB)
#define CHN1_TXBB_3_BW2_LPF_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_3_BW2_LPF_LS_LSB) & CHN1_TXBB_3_BW2_LPF_LS_MASK)
#define CHN1_TXBB_3_BW2_LPF_LS_RESET                                           0x6
#define CHN1_TXBB_3_BW3_LPF_LS_LSB                                             16
#define CHN1_TXBB_3_BW3_LPF_LS_MSB                                             19
#define CHN1_TXBB_3_BW3_LPF_LS_MASK                                            0xf0000
#define CHN1_TXBB_3_BW3_LPF_LS_GET(x)                                          (((x) & CHN1_TXBB_3_BW3_LPF_LS_MASK) >> CHN1_TXBB_3_BW3_LPF_LS_LSB)
#define CHN1_TXBB_3_BW3_LPF_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_3_BW3_LPF_LS_LSB) & CHN1_TXBB_3_BW3_LPF_LS_MASK)
#define CHN1_TXBB_3_BW3_LPF_LS_RESET                                           0x7
#define CHN1_TXBB_3_BW4_LPF_LS_LSB                                             12
#define CHN1_TXBB_3_BW4_LPF_LS_MSB                                             15
#define CHN1_TXBB_3_BW4_LPF_LS_MASK                                            0xf000
#define CHN1_TXBB_3_BW4_LPF_LS_GET(x)                                          (((x) & CHN1_TXBB_3_BW4_LPF_LS_MASK) >> CHN1_TXBB_3_BW4_LPF_LS_LSB)
#define CHN1_TXBB_3_BW4_LPF_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_3_BW4_LPF_LS_LSB) & CHN1_TXBB_3_BW4_LPF_LS_MASK)
#define CHN1_TXBB_3_BW4_LPF_LS_RESET                                           0x9
#define CHN1_TXBB_3_BW5_LPF_LS_LSB                                             8
#define CHN1_TXBB_3_BW5_LPF_LS_MSB                                             11
#define CHN1_TXBB_3_BW5_LPF_LS_MASK                                            0xf00
#define CHN1_TXBB_3_BW5_LPF_LS_GET(x)                                          (((x) & CHN1_TXBB_3_BW5_LPF_LS_MASK) >> CHN1_TXBB_3_BW5_LPF_LS_LSB)
#define CHN1_TXBB_3_BW5_LPF_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_3_BW5_LPF_LS_LSB) & CHN1_TXBB_3_BW5_LPF_LS_MASK)
#define CHN1_TXBB_3_BW5_LPF_LS_RESET                                           0xb
#define CHN1_TXBB_3_BW6_LPF_LS_LSB                                             4
#define CHN1_TXBB_3_BW6_LPF_LS_MSB                                             7
#define CHN1_TXBB_3_BW6_LPF_LS_MASK                                            0xf0
#define CHN1_TXBB_3_BW6_LPF_LS_GET(x)                                          (((x) & CHN1_TXBB_3_BW6_LPF_LS_MASK) >> CHN1_TXBB_3_BW6_LPF_LS_LSB)
#define CHN1_TXBB_3_BW6_LPF_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_3_BW6_LPF_LS_LSB) & CHN1_TXBB_3_BW6_LPF_LS_MASK)
#define CHN1_TXBB_3_BW6_LPF_LS_RESET                                           0xc
#define CHN1_TXBB_3_BW7_LPF_LS_LSB                                             0
#define CHN1_TXBB_3_BW7_LPF_LS_MSB                                             3
#define CHN1_TXBB_3_BW7_LPF_LS_MASK                                            0xf
#define CHN1_TXBB_3_BW7_LPF_LS_GET(x)                                          (((x) & CHN1_TXBB_3_BW7_LPF_LS_MASK) >> CHN1_TXBB_3_BW7_LPF_LS_LSB)
#define CHN1_TXBB_3_BW7_LPF_LS_SET(x)                                          (((0 | (x)) << CHN1_TXBB_3_BW7_LPF_LS_LSB) & CHN1_TXBB_3_BW7_LPF_LS_MASK)
#define CHN1_TXBB_3_BW7_LPF_LS_RESET                                           0xf
#define CHN1_TXBB_3_ADDRESS                                                    (0xc + __CHN1_TXBB_REG_CSR_BASE_ADDRESS)
#define CHN1_TXBB_3_RSTMASK                                                    0xffffffff
#define CHN1_TXBB_3_RESET                                                      0x14679bcf

// 0x10 (CHN1_TXBB_4)
#define CHN1_TXBB_4_FNOTCH_LSB                                                 28
#define CHN1_TXBB_4_FNOTCH_MSB                                                 31
#define CHN1_TXBB_4_FNOTCH_MASK                                                0xf0000000
#define CHN1_TXBB_4_FNOTCH_GET(x)                                              (((x) & CHN1_TXBB_4_FNOTCH_MASK) >> CHN1_TXBB_4_FNOTCH_LSB)
#define CHN1_TXBB_4_FNOTCH_SET(x)                                              (((0 | (x)) << CHN1_TXBB_4_FNOTCH_LSB) & CHN1_TXBB_4_FNOTCH_MASK)
#define CHN1_TXBB_4_FNOTCH_RESET                                               0x6
#define CHN1_TXBB_4_TX_FILTERFC_LSB                                            23
#define CHN1_TXBB_4_TX_FILTERFC_MSB                                            27
#define CHN1_TXBB_4_TX_FILTERFC_MASK                                           0xf800000
#define CHN1_TXBB_4_TX_FILTERFC_GET(x)                                         (((x) & CHN1_TXBB_4_TX_FILTERFC_MASK) >> CHN1_TXBB_4_TX_FILTERFC_LSB)
#define CHN1_TXBB_4_TX_FILTERFC_SET(x)                                         (((0 | (x)) << CHN1_TXBB_4_TX_FILTERFC_LSB) & CHN1_TXBB_4_TX_FILTERFC_MASK)
#define CHN1_TXBB_4_TX_FILTERFC_RESET                                          0xc
#define CHN1_TXBB_4_PGALPF_C_SEL_LSB                                           18
#define CHN1_TXBB_4_PGALPF_C_SEL_MSB                                           22
#define CHN1_TXBB_4_PGALPF_C_SEL_MASK                                          0x7c0000
#define CHN1_TXBB_4_PGALPF_C_SEL_GET(x)                                        (((x) & CHN1_TXBB_4_PGALPF_C_SEL_MASK) >> CHN1_TXBB_4_PGALPF_C_SEL_LSB)
#define CHN1_TXBB_4_PGALPF_C_SEL_SET(x)                                        (((0 | (x)) << CHN1_TXBB_4_PGALPF_C_SEL_LSB) & CHN1_TXBB_4_PGALPF_C_SEL_MASK)
#define CHN1_TXBB_4_PGALPF_C_SEL_RESET                                         0xc
#define CHN1_TXBB_4_ISEL_IC25BQLVSH_LSB                                        15
#define CHN1_TXBB_4_ISEL_IC25BQLVSH_MSB                                        17
#define CHN1_TXBB_4_ISEL_IC25BQLVSH_MASK                                       0x38000
#define CHN1_TXBB_4_ISEL_IC25BQLVSH_GET(x)                                     (((x) & CHN1_TXBB_4_ISEL_IC25BQLVSH_MASK) >> CHN1_TXBB_4_ISEL_IC25BQLVSH_LSB)
#define CHN1_TXBB_4_ISEL_IC25BQLVSH_SET(x)                                     (((0 | (x)) << CHN1_TXBB_4_ISEL_IC25BQLVSH_LSB) & CHN1_TXBB_4_ISEL_IC25BQLVSH_MASK)
#define CHN1_TXBB_4_ISEL_IC25BQLVSH_RESET                                      0x3
#define CHN1_TXBB_4_VSEL_BQ_VCM_LSB                                            13
#define CHN1_TXBB_4_VSEL_BQ_VCM_MSB                                            14
#define CHN1_TXBB_4_VSEL_BQ_VCM_MASK                                           0x6000
#define CHN1_TXBB_4_VSEL_BQ_VCM_GET(x)                                         (((x) & CHN1_TXBB_4_VSEL_BQ_VCM_MASK) >> CHN1_TXBB_4_VSEL_BQ_VCM_LSB)
#define CHN1_TXBB_4_VSEL_BQ_VCM_SET(x)                                         (((0 | (x)) << CHN1_TXBB_4_VSEL_BQ_VCM_LSB) & CHN1_TXBB_4_VSEL_BQ_VCM_MASK)
#define CHN1_TXBB_4_VSEL_BQ_VCM_RESET                                          0x1
#define CHN1_TXBB_4_DAC_GAIN_LSB                                               10
#define CHN1_TXBB_4_DAC_GAIN_MSB                                               12
#define CHN1_TXBB_4_DAC_GAIN_MASK                                              0x1c00
#define CHN1_TXBB_4_DAC_GAIN_GET(x)                                            (((x) & CHN1_TXBB_4_DAC_GAIN_MASK) >> CHN1_TXBB_4_DAC_GAIN_LSB)
#define CHN1_TXBB_4_DAC_GAIN_SET(x)                                            (((0 | (x)) << CHN1_TXBB_4_DAC_GAIN_LSB) & CHN1_TXBB_4_DAC_GAIN_MASK)
#define CHN1_TXBB_4_DAC_GAIN_RESET                                             0x0
#define CHN1_TXBB_4_RESERVED_0_LSB                                             9
#define CHN1_TXBB_4_RESERVED_0_MSB                                             9
#define CHN1_TXBB_4_RESERVED_0_MASK                                            0x200
#define CHN1_TXBB_4_RESERVED_0_GET(x)                                          (((x) & CHN1_TXBB_4_RESERVED_0_MASK) >> CHN1_TXBB_4_RESERVED_0_LSB)
#define CHN1_TXBB_4_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN1_TXBB_4_RESERVED_0_LSB) & CHN1_TXBB_4_RESERVED_0_MASK)
#define CHN1_TXBB_4_RESERVED_0_RESET                                           0x0
#define CHN1_TXBB_4_BBFATBEN_LSB                                               8
#define CHN1_TXBB_4_BBFATBEN_MSB                                               8
#define CHN1_TXBB_4_BBFATBEN_MASK                                              0x100
#define CHN1_TXBB_4_BBFATBEN_GET(x)                                            (((x) & CHN1_TXBB_4_BBFATBEN_MASK) >> CHN1_TXBB_4_BBFATBEN_LSB)
#define CHN1_TXBB_4_BBFATBEN_SET(x)                                            (((0 | (x)) << CHN1_TXBB_4_BBFATBEN_LSB) & CHN1_TXBB_4_BBFATBEN_MASK)
#define CHN1_TXBB_4_BBFATBEN_RESET                                             0x0
#define CHN1_TXBB_4_BBFATBSEL_LSB                                              4
#define CHN1_TXBB_4_BBFATBSEL_MSB                                              7
#define CHN1_TXBB_4_BBFATBSEL_MASK                                             0xf0
#define CHN1_TXBB_4_BBFATBSEL_GET(x)                                           (((x) & CHN1_TXBB_4_BBFATBSEL_MASK) >> CHN1_TXBB_4_BBFATBSEL_LSB)
#define CHN1_TXBB_4_BBFATBSEL_SET(x)                                           (((0 | (x)) << CHN1_TXBB_4_BBFATBSEL_LSB) & CHN1_TXBB_4_BBFATBSEL_MASK)
#define CHN1_TXBB_4_BBFATBSEL_RESET                                            0x0
#define CHN1_TXBB_4_TESTSEL_LSB                                                0
#define CHN1_TXBB_4_TESTSEL_MSB                                                3
#define CHN1_TXBB_4_TESTSEL_MASK                                               0xf
#define CHN1_TXBB_4_TESTSEL_GET(x)                                             (((x) & CHN1_TXBB_4_TESTSEL_MASK) >> CHN1_TXBB_4_TESTSEL_LSB)
#define CHN1_TXBB_4_TESTSEL_SET(x)                                             (((0 | (x)) << CHN1_TXBB_4_TESTSEL_LSB) & CHN1_TXBB_4_TESTSEL_MASK)
#define CHN1_TXBB_4_TESTSEL_RESET                                              0x0
#define CHN1_TXBB_4_ADDRESS                                                    (0x10 + __CHN1_TXBB_REG_CSR_BASE_ADDRESS)
#define CHN1_TXBB_4_RSTMASK                                                    0xffffffff
#define CHN1_TXBB_4_RESET                                                      0x6631a000

// 0x14 (CHN1_TXBB_5)
#define CHN1_TXBB_5_TXBB_SPARE_LSB                                             0
#define CHN1_TXBB_5_TXBB_SPARE_MSB                                             31
#define CHN1_TXBB_5_TXBB_SPARE_MASK                                            0xffffffff
#define CHN1_TXBB_5_TXBB_SPARE_GET(x)                                          (((x) & CHN1_TXBB_5_TXBB_SPARE_MASK) >> CHN1_TXBB_5_TXBB_SPARE_LSB)
#define CHN1_TXBB_5_TXBB_SPARE_SET(x)                                          (((0 | (x)) << CHN1_TXBB_5_TXBB_SPARE_LSB) & CHN1_TXBB_5_TXBB_SPARE_MASK)
#define CHN1_TXBB_5_TXBB_SPARE_RESET                                           0x0
#define CHN1_TXBB_5_ADDRESS                                                    (0x14 + __CHN1_TXBB_REG_CSR_BASE_ADDRESS)
#define CHN1_TXBB_5_RSTMASK                                                    0xffffffff
#define CHN1_TXBB_5_RESET                                                      0x0



#endif /* _CHN1_TXBB_REG_CSR_H_ */
