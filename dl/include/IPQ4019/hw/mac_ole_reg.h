/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _MAC_OLE_REG_H_
#define _MAC_OLE_REG_H_


#ifndef __MAC_OLE_REG_BASE_ADDRESS
#define __MAC_OLE_REG_BASE_ADDRESS (0x30c00)
#endif


// 0x0 (OLE_L2_WLAN_LLC_0)
#define OLE_L2_WLAN_LLC_0_ENABLE_LSB                                           24
#define OLE_L2_WLAN_LLC_0_ENABLE_MSB                                           24
#define OLE_L2_WLAN_LLC_0_ENABLE_MASK                                          0x1000000
#define OLE_L2_WLAN_LLC_0_ENABLE_GET(x)                                        (((x) & OLE_L2_WLAN_LLC_0_ENABLE_MASK) >> OLE_L2_WLAN_LLC_0_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_0_ENABLE_SET(x)                                        (((0 | (x)) << OLE_L2_WLAN_LLC_0_ENABLE_LSB) & OLE_L2_WLAN_LLC_0_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_0_ENABLE_RESET                                         0x1
#define OLE_L2_WLAN_LLC_0_BYTE6_LSB                                            16
#define OLE_L2_WLAN_LLC_0_BYTE6_MSB                                            23
#define OLE_L2_WLAN_LLC_0_BYTE6_MASK                                           0xff0000
#define OLE_L2_WLAN_LLC_0_BYTE6_GET(x)                                         (((x) & OLE_L2_WLAN_LLC_0_BYTE6_MASK) >> OLE_L2_WLAN_LLC_0_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_0_BYTE6_SET(x)                                         (((0 | (x)) << OLE_L2_WLAN_LLC_0_BYTE6_LSB) & OLE_L2_WLAN_LLC_0_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_0_BYTE6_RESET                                          0x0
#define OLE_L2_WLAN_LLC_0_TYPE_LSB                                             0
#define OLE_L2_WLAN_LLC_0_TYPE_MSB                                             15
#define OLE_L2_WLAN_LLC_0_TYPE_MASK                                            0xffff
#define OLE_L2_WLAN_LLC_0_TYPE_GET(x)                                          (((x) & OLE_L2_WLAN_LLC_0_TYPE_MASK) >> OLE_L2_WLAN_LLC_0_TYPE_LSB)
#define OLE_L2_WLAN_LLC_0_TYPE_SET(x)                                          (((0 | (x)) << OLE_L2_WLAN_LLC_0_TYPE_LSB) & OLE_L2_WLAN_LLC_0_TYPE_MASK)
#define OLE_L2_WLAN_LLC_0_TYPE_RESET                                           0x800
#define OLE_L2_WLAN_LLC_0_ADDRESS                                              (0x0 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_L2_WLAN_LLC_0_RSTMASK                                              0x1ffffff
#define OLE_L2_WLAN_LLC_0_RESET                                                0x1000800

// 0x4 (OLE_L2_WLAN_LLC_1)
#define OLE_L2_WLAN_LLC_1_ENABLE_LSB                                           24
#define OLE_L2_WLAN_LLC_1_ENABLE_MSB                                           24
#define OLE_L2_WLAN_LLC_1_ENABLE_MASK                                          0x1000000
#define OLE_L2_WLAN_LLC_1_ENABLE_GET(x)                                        (((x) & OLE_L2_WLAN_LLC_1_ENABLE_MASK) >> OLE_L2_WLAN_LLC_1_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_1_ENABLE_SET(x)                                        (((0 | (x)) << OLE_L2_WLAN_LLC_1_ENABLE_LSB) & OLE_L2_WLAN_LLC_1_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_1_ENABLE_RESET                                         0x1
#define OLE_L2_WLAN_LLC_1_BYTE6_LSB                                            16
#define OLE_L2_WLAN_LLC_1_BYTE6_MSB                                            23
#define OLE_L2_WLAN_LLC_1_BYTE6_MASK                                           0xff0000
#define OLE_L2_WLAN_LLC_1_BYTE6_GET(x)                                         (((x) & OLE_L2_WLAN_LLC_1_BYTE6_MASK) >> OLE_L2_WLAN_LLC_1_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_1_BYTE6_SET(x)                                         (((0 | (x)) << OLE_L2_WLAN_LLC_1_BYTE6_LSB) & OLE_L2_WLAN_LLC_1_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_1_BYTE6_RESET                                          0x0
#define OLE_L2_WLAN_LLC_1_TYPE_LSB                                             0
#define OLE_L2_WLAN_LLC_1_TYPE_MSB                                             15
#define OLE_L2_WLAN_LLC_1_TYPE_MASK                                            0xffff
#define OLE_L2_WLAN_LLC_1_TYPE_GET(x)                                          (((x) & OLE_L2_WLAN_LLC_1_TYPE_MASK) >> OLE_L2_WLAN_LLC_1_TYPE_LSB)
#define OLE_L2_WLAN_LLC_1_TYPE_SET(x)                                          (((0 | (x)) << OLE_L2_WLAN_LLC_1_TYPE_LSB) & OLE_L2_WLAN_LLC_1_TYPE_MASK)
#define OLE_L2_WLAN_LLC_1_TYPE_RESET                                           0x806
#define OLE_L2_WLAN_LLC_1_ADDRESS                                              (0x4 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_L2_WLAN_LLC_1_RSTMASK                                              0x1ffffff
#define OLE_L2_WLAN_LLC_1_RESET                                                0x1000806

// 0x8 (OLE_L2_WLAN_LLC_2)
#define OLE_L2_WLAN_LLC_2_ENABLE_LSB                                           24
#define OLE_L2_WLAN_LLC_2_ENABLE_MSB                                           24
#define OLE_L2_WLAN_LLC_2_ENABLE_MASK                                          0x1000000
#define OLE_L2_WLAN_LLC_2_ENABLE_GET(x)                                        (((x) & OLE_L2_WLAN_LLC_2_ENABLE_MASK) >> OLE_L2_WLAN_LLC_2_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_2_ENABLE_SET(x)                                        (((0 | (x)) << OLE_L2_WLAN_LLC_2_ENABLE_LSB) & OLE_L2_WLAN_LLC_2_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_2_ENABLE_RESET                                         0x1
#define OLE_L2_WLAN_LLC_2_BYTE6_LSB                                            16
#define OLE_L2_WLAN_LLC_2_BYTE6_MSB                                            23
#define OLE_L2_WLAN_LLC_2_BYTE6_MASK                                           0xff0000
#define OLE_L2_WLAN_LLC_2_BYTE6_GET(x)                                         (((x) & OLE_L2_WLAN_LLC_2_BYTE6_MASK) >> OLE_L2_WLAN_LLC_2_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_2_BYTE6_SET(x)                                         (((0 | (x)) << OLE_L2_WLAN_LLC_2_BYTE6_LSB) & OLE_L2_WLAN_LLC_2_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_2_BYTE6_RESET                                          0x0
#define OLE_L2_WLAN_LLC_2_TYPE_LSB                                             0
#define OLE_L2_WLAN_LLC_2_TYPE_MSB                                             15
#define OLE_L2_WLAN_LLC_2_TYPE_MASK                                            0xffff
#define OLE_L2_WLAN_LLC_2_TYPE_GET(x)                                          (((x) & OLE_L2_WLAN_LLC_2_TYPE_MASK) >> OLE_L2_WLAN_LLC_2_TYPE_LSB)
#define OLE_L2_WLAN_LLC_2_TYPE_SET(x)                                          (((0 | (x)) << OLE_L2_WLAN_LLC_2_TYPE_LSB) & OLE_L2_WLAN_LLC_2_TYPE_MASK)
#define OLE_L2_WLAN_LLC_2_TYPE_RESET                                           0x809b
#define OLE_L2_WLAN_LLC_2_ADDRESS                                              (0x8 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_L2_WLAN_LLC_2_RSTMASK                                              0x1ffffff
#define OLE_L2_WLAN_LLC_2_RESET                                                0x100809b

// 0xc (OLE_L2_WLAN_LLC_3)
#define OLE_L2_WLAN_LLC_3_ENABLE_LSB                                           24
#define OLE_L2_WLAN_LLC_3_ENABLE_MSB                                           24
#define OLE_L2_WLAN_LLC_3_ENABLE_MASK                                          0x1000000
#define OLE_L2_WLAN_LLC_3_ENABLE_GET(x)                                        (((x) & OLE_L2_WLAN_LLC_3_ENABLE_MASK) >> OLE_L2_WLAN_LLC_3_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_3_ENABLE_SET(x)                                        (((0 | (x)) << OLE_L2_WLAN_LLC_3_ENABLE_LSB) & OLE_L2_WLAN_LLC_3_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_3_ENABLE_RESET                                         0x1
#define OLE_L2_WLAN_LLC_3_BYTE6_LSB                                            16
#define OLE_L2_WLAN_LLC_3_BYTE6_MSB                                            23
#define OLE_L2_WLAN_LLC_3_BYTE6_MASK                                           0xff0000
#define OLE_L2_WLAN_LLC_3_BYTE6_GET(x)                                         (((x) & OLE_L2_WLAN_LLC_3_BYTE6_MASK) >> OLE_L2_WLAN_LLC_3_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_3_BYTE6_SET(x)                                         (((0 | (x)) << OLE_L2_WLAN_LLC_3_BYTE6_LSB) & OLE_L2_WLAN_LLC_3_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_3_BYTE6_RESET                                          0xf8
#define OLE_L2_WLAN_LLC_3_TYPE_LSB                                             0
#define OLE_L2_WLAN_LLC_3_TYPE_MSB                                             15
#define OLE_L2_WLAN_LLC_3_TYPE_MASK                                            0xffff
#define OLE_L2_WLAN_LLC_3_TYPE_GET(x)                                          (((x) & OLE_L2_WLAN_LLC_3_TYPE_MASK) >> OLE_L2_WLAN_LLC_3_TYPE_LSB)
#define OLE_L2_WLAN_LLC_3_TYPE_SET(x)                                          (((0 | (x)) << OLE_L2_WLAN_LLC_3_TYPE_LSB) & OLE_L2_WLAN_LLC_3_TYPE_MASK)
#define OLE_L2_WLAN_LLC_3_TYPE_RESET                                           0x80f3
#define OLE_L2_WLAN_LLC_3_ADDRESS                                              (0xc + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_L2_WLAN_LLC_3_RSTMASK                                              0x1ffffff
#define OLE_L2_WLAN_LLC_3_RESET                                                0x1f880f3

// 0x10 (OLE_L2_WLAN_LLC_4)
#define OLE_L2_WLAN_LLC_4_ENABLE_LSB                                           24
#define OLE_L2_WLAN_LLC_4_ENABLE_MSB                                           24
#define OLE_L2_WLAN_LLC_4_ENABLE_MASK                                          0x1000000
#define OLE_L2_WLAN_LLC_4_ENABLE_GET(x)                                        (((x) & OLE_L2_WLAN_LLC_4_ENABLE_MASK) >> OLE_L2_WLAN_LLC_4_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_4_ENABLE_SET(x)                                        (((0 | (x)) << OLE_L2_WLAN_LLC_4_ENABLE_LSB) & OLE_L2_WLAN_LLC_4_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_4_ENABLE_RESET                                         0x1
#define OLE_L2_WLAN_LLC_4_BYTE6_LSB                                            16
#define OLE_L2_WLAN_LLC_4_BYTE6_MSB                                            23
#define OLE_L2_WLAN_LLC_4_BYTE6_MASK                                           0xff0000
#define OLE_L2_WLAN_LLC_4_BYTE6_GET(x)                                         (((x) & OLE_L2_WLAN_LLC_4_BYTE6_MASK) >> OLE_L2_WLAN_LLC_4_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_4_BYTE6_SET(x)                                         (((0 | (x)) << OLE_L2_WLAN_LLC_4_BYTE6_LSB) & OLE_L2_WLAN_LLC_4_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_4_BYTE6_RESET                                          0xf8
#define OLE_L2_WLAN_LLC_4_TYPE_LSB                                             0
#define OLE_L2_WLAN_LLC_4_TYPE_MSB                                             15
#define OLE_L2_WLAN_LLC_4_TYPE_MASK                                            0xffff
#define OLE_L2_WLAN_LLC_4_TYPE_GET(x)                                          (((x) & OLE_L2_WLAN_LLC_4_TYPE_MASK) >> OLE_L2_WLAN_LLC_4_TYPE_LSB)
#define OLE_L2_WLAN_LLC_4_TYPE_SET(x)                                          (((0 | (x)) << OLE_L2_WLAN_LLC_4_TYPE_LSB) & OLE_L2_WLAN_LLC_4_TYPE_MASK)
#define OLE_L2_WLAN_LLC_4_TYPE_RESET                                           0x8137
#define OLE_L2_WLAN_LLC_4_ADDRESS                                              (0x10 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_L2_WLAN_LLC_4_RSTMASK                                              0x1ffffff
#define OLE_L2_WLAN_LLC_4_RESET                                                0x1f88137

// 0x14 (OLE_L2_WLAN_LLC_5)
#define OLE_L2_WLAN_LLC_5_ENABLE_LSB                                           24
#define OLE_L2_WLAN_LLC_5_ENABLE_MSB                                           24
#define OLE_L2_WLAN_LLC_5_ENABLE_MASK                                          0x1000000
#define OLE_L2_WLAN_LLC_5_ENABLE_GET(x)                                        (((x) & OLE_L2_WLAN_LLC_5_ENABLE_MASK) >> OLE_L2_WLAN_LLC_5_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_5_ENABLE_SET(x)                                        (((0 | (x)) << OLE_L2_WLAN_LLC_5_ENABLE_LSB) & OLE_L2_WLAN_LLC_5_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_5_ENABLE_RESET                                         0x1
#define OLE_L2_WLAN_LLC_5_BYTE6_LSB                                            16
#define OLE_L2_WLAN_LLC_5_BYTE6_MSB                                            23
#define OLE_L2_WLAN_LLC_5_BYTE6_MASK                                           0xff0000
#define OLE_L2_WLAN_LLC_5_BYTE6_GET(x)                                         (((x) & OLE_L2_WLAN_LLC_5_BYTE6_MASK) >> OLE_L2_WLAN_LLC_5_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_5_BYTE6_SET(x)                                         (((0 | (x)) << OLE_L2_WLAN_LLC_5_BYTE6_LSB) & OLE_L2_WLAN_LLC_5_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_5_BYTE6_RESET                                          0x0
#define OLE_L2_WLAN_LLC_5_TYPE_LSB                                             0
#define OLE_L2_WLAN_LLC_5_TYPE_MSB                                             15
#define OLE_L2_WLAN_LLC_5_TYPE_MASK                                            0xffff
#define OLE_L2_WLAN_LLC_5_TYPE_GET(x)                                          (((x) & OLE_L2_WLAN_LLC_5_TYPE_MASK) >> OLE_L2_WLAN_LLC_5_TYPE_LSB)
#define OLE_L2_WLAN_LLC_5_TYPE_SET(x)                                          (((0 | (x)) << OLE_L2_WLAN_LLC_5_TYPE_LSB) & OLE_L2_WLAN_LLC_5_TYPE_MASK)
#define OLE_L2_WLAN_LLC_5_TYPE_RESET                                           0x86dd
#define OLE_L2_WLAN_LLC_5_ADDRESS                                              (0x14 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_L2_WLAN_LLC_5_RSTMASK                                              0x1ffffff
#define OLE_L2_WLAN_LLC_5_RESET                                                0x10086dd

// 0x18 (OLE_L2_WLAN_LLC_6)
#define OLE_L2_WLAN_LLC_6_ENABLE_LSB                                           24
#define OLE_L2_WLAN_LLC_6_ENABLE_MSB                                           24
#define OLE_L2_WLAN_LLC_6_ENABLE_MASK                                          0x1000000
#define OLE_L2_WLAN_LLC_6_ENABLE_GET(x)                                        (((x) & OLE_L2_WLAN_LLC_6_ENABLE_MASK) >> OLE_L2_WLAN_LLC_6_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_6_ENABLE_SET(x)                                        (((0 | (x)) << OLE_L2_WLAN_LLC_6_ENABLE_LSB) & OLE_L2_WLAN_LLC_6_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_6_ENABLE_RESET                                         0x1
#define OLE_L2_WLAN_LLC_6_BYTE6_LSB                                            16
#define OLE_L2_WLAN_LLC_6_BYTE6_MSB                                            23
#define OLE_L2_WLAN_LLC_6_BYTE6_MASK                                           0xff0000
#define OLE_L2_WLAN_LLC_6_BYTE6_GET(x)                                         (((x) & OLE_L2_WLAN_LLC_6_BYTE6_MASK) >> OLE_L2_WLAN_LLC_6_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_6_BYTE6_SET(x)                                         (((0 | (x)) << OLE_L2_WLAN_LLC_6_BYTE6_LSB) & OLE_L2_WLAN_LLC_6_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_6_BYTE6_RESET                                          0x0
#define OLE_L2_WLAN_LLC_6_TYPE_LSB                                             0
#define OLE_L2_WLAN_LLC_6_TYPE_MSB                                             15
#define OLE_L2_WLAN_LLC_6_TYPE_MASK                                            0xffff
#define OLE_L2_WLAN_LLC_6_TYPE_GET(x)                                          (((x) & OLE_L2_WLAN_LLC_6_TYPE_MASK) >> OLE_L2_WLAN_LLC_6_TYPE_LSB)
#define OLE_L2_WLAN_LLC_6_TYPE_SET(x)                                          (((0 | (x)) << OLE_L2_WLAN_LLC_6_TYPE_LSB) & OLE_L2_WLAN_LLC_6_TYPE_MASK)
#define OLE_L2_WLAN_LLC_6_TYPE_RESET                                           0x888e
#define OLE_L2_WLAN_LLC_6_ADDRESS                                              (0x18 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_L2_WLAN_LLC_6_RSTMASK                                              0x1ffffff
#define OLE_L2_WLAN_LLC_6_RESET                                                0x100888e

// 0x20 (OLE_RX_CONFIG)
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_LSB                                       0
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_MSB                                       7
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_MASK                                      0xff
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_GET(x)                                    (((x) & OLE_RX_CONFIG_RX_HDR_BYTELEN_MASK) >> OLE_RX_CONFIG_RX_HDR_BYTELEN_LSB)
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RX_HDR_BYTELEN_LSB) & OLE_RX_CONFIG_RX_HDR_BYTELEN_MASK)
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_RESET                                     0x30
#define OLE_RX_CONFIG_ADDRESS                                                  (0x20 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_CONFIG_RSTMASK                                                  0xff
#define OLE_RX_CONFIG_RESET                                                    0x30

// 0x24 (OLE_RX_CONFIG_RING0)
#define OLE_RX_CONFIG_RING0_RESERVED_2_LSB                                     28
#define OLE_RX_CONFIG_RING0_RESERVED_2_MSB                                     31
#define OLE_RX_CONFIG_RING0_RESERVED_2_MASK                                    0xf0000000
#define OLE_RX_CONFIG_RING0_RESERVED_2_GET(x)                                  (((x) & OLE_RX_CONFIG_RING0_RESERVED_2_MASK) >> OLE_RX_CONFIG_RING0_RESERVED_2_LSB)
#define OLE_RX_CONFIG_RING0_RESERVED_2_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING0_RESERVED_2_LSB) & OLE_RX_CONFIG_RING0_RESERVED_2_MASK)
#define OLE_RX_CONFIG_RING0_RESERVED_2_RESET                                   0x0
#define OLE_RX_CONFIG_RING0_ETHERNET_3_LSB                                     27
#define OLE_RX_CONFIG_RING0_ETHERNET_3_MSB                                     27
#define OLE_RX_CONFIG_RING0_ETHERNET_3_MASK                                    0x8000000
#define OLE_RX_CONFIG_RING0_ETHERNET_3_GET(x)                                  (((x) & OLE_RX_CONFIG_RING0_ETHERNET_3_MASK) >> OLE_RX_CONFIG_RING0_ETHERNET_3_LSB)
#define OLE_RX_CONFIG_RING0_ETHERNET_3_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING0_ETHERNET_3_LSB) & OLE_RX_CONFIG_RING0_ETHERNET_3_MASK)
#define OLE_RX_CONFIG_RING0_ETHERNET_3_RESET                                   0x0
#define OLE_RX_CONFIG_RING0_ETHERNET_2_LSB                                     26
#define OLE_RX_CONFIG_RING0_ETHERNET_2_MSB                                     26
#define OLE_RX_CONFIG_RING0_ETHERNET_2_MASK                                    0x4000000
#define OLE_RX_CONFIG_RING0_ETHERNET_2_GET(x)                                  (((x) & OLE_RX_CONFIG_RING0_ETHERNET_2_MASK) >> OLE_RX_CONFIG_RING0_ETHERNET_2_LSB)
#define OLE_RX_CONFIG_RING0_ETHERNET_2_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING0_ETHERNET_2_LSB) & OLE_RX_CONFIG_RING0_ETHERNET_2_MASK)
#define OLE_RX_CONFIG_RING0_ETHERNET_2_RESET                                   0x0
#define OLE_RX_CONFIG_RING0_ETHERNET_1_LSB                                     25
#define OLE_RX_CONFIG_RING0_ETHERNET_1_MSB                                     25
#define OLE_RX_CONFIG_RING0_ETHERNET_1_MASK                                    0x2000000
#define OLE_RX_CONFIG_RING0_ETHERNET_1_GET(x)                                  (((x) & OLE_RX_CONFIG_RING0_ETHERNET_1_MASK) >> OLE_RX_CONFIG_RING0_ETHERNET_1_LSB)
#define OLE_RX_CONFIG_RING0_ETHERNET_1_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING0_ETHERNET_1_LSB) & OLE_RX_CONFIG_RING0_ETHERNET_1_MASK)
#define OLE_RX_CONFIG_RING0_ETHERNET_1_RESET                                   0x0
#define OLE_RX_CONFIG_RING0_ETHERNET_0_LSB                                     24
#define OLE_RX_CONFIG_RING0_ETHERNET_0_MSB                                     24
#define OLE_RX_CONFIG_RING0_ETHERNET_0_MASK                                    0x1000000
#define OLE_RX_CONFIG_RING0_ETHERNET_0_GET(x)                                  (((x) & OLE_RX_CONFIG_RING0_ETHERNET_0_MASK) >> OLE_RX_CONFIG_RING0_ETHERNET_0_LSB)
#define OLE_RX_CONFIG_RING0_ETHERNET_0_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING0_ETHERNET_0_LSB) & OLE_RX_CONFIG_RING0_ETHERNET_0_MASK)
#define OLE_RX_CONFIG_RING0_ETHERNET_0_RESET                                   0x0
#define OLE_RX_CONFIG_RING0_RESERVED_1_LSB                                     22
#define OLE_RX_CONFIG_RING0_RESERVED_1_MSB                                     23
#define OLE_RX_CONFIG_RING0_RESERVED_1_MASK                                    0xc00000
#define OLE_RX_CONFIG_RING0_RESERVED_1_GET(x)                                  (((x) & OLE_RX_CONFIG_RING0_RESERVED_1_MASK) >> OLE_RX_CONFIG_RING0_RESERVED_1_LSB)
#define OLE_RX_CONFIG_RING0_RESERVED_1_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING0_RESERVED_1_LSB) & OLE_RX_CONFIG_RING0_RESERVED_1_MASK)
#define OLE_RX_CONFIG_RING0_RESERVED_1_RESET                                   0x0
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_LSB                                  21
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_MSB                                  21
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_MASK                                 0x200000
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_GET(x)                               (((x) & OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_SET(x)                               (((0 | (x)) << OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_RESET                                0x1
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_LSB                                 20
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_MSB                                 20
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_MASK                                0x100000
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_GET(x)                              (((x) & OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_SET(x)                              (((0 | (x)) << OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_RESET                               0x1
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_LSB                                19
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_MSB                                19
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_MASK                               0x80000
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_GET(x)                             (((x) & OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_SET(x)                             (((0 | (x)) << OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_RESET                              0x1
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_LSB                                18
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_MSB                                18
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_MASK                               0x40000
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_GET(x)                             (((x) & OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_SET(x)                             (((0 | (x)) << OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_RESET                              0x1
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_LSB                                      17
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_MSB                                      17
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_MASK                                     0x20000
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_GET(x)                                   (((x) & OLE_RX_CONFIG_RING0_MGMT_TYPE_MASK) >> OLE_RX_CONFIG_RING0_MGMT_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING0_MGMT_TYPE_LSB) & OLE_RX_CONFIG_RING0_MGMT_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_RESET                                    0x1
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_LSB                                      16
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_MSB                                      16
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_MASK                                     0x10000
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_GET(x)                                   (((x) & OLE_RX_CONFIG_RING0_CTRL_TYPE_MASK) >> OLE_RX_CONFIG_RING0_CTRL_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING0_CTRL_TYPE_LSB) & OLE_RX_CONFIG_RING0_CTRL_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_RESET                                    0x1
#define OLE_RX_CONFIG_RING0_RESERVED_0_LSB                                     10
#define OLE_RX_CONFIG_RING0_RESERVED_0_MSB                                     15
#define OLE_RX_CONFIG_RING0_RESERVED_0_MASK                                    0xfc00
#define OLE_RX_CONFIG_RING0_RESERVED_0_GET(x)                                  (((x) & OLE_RX_CONFIG_RING0_RESERVED_0_MASK) >> OLE_RX_CONFIG_RING0_RESERVED_0_LSB)
#define OLE_RX_CONFIG_RING0_RESERVED_0_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING0_RESERVED_0_LSB) & OLE_RX_CONFIG_RING0_RESERVED_0_MASK)
#define OLE_RX_CONFIG_RING0_RESERVED_0_RESET                                   0x0
#define OLE_RX_CONFIG_RING0_FRAG_INFO_LSB                                      9
#define OLE_RX_CONFIG_RING0_FRAG_INFO_MSB                                      9
#define OLE_RX_CONFIG_RING0_FRAG_INFO_MASK                                     0x200
#define OLE_RX_CONFIG_RING0_FRAG_INFO_GET(x)                                   (((x) & OLE_RX_CONFIG_RING0_FRAG_INFO_MASK) >> OLE_RX_CONFIG_RING0_FRAG_INFO_LSB)
#define OLE_RX_CONFIG_RING0_FRAG_INFO_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING0_FRAG_INFO_LSB) & OLE_RX_CONFIG_RING0_FRAG_INFO_MASK)
#define OLE_RX_CONFIG_RING0_FRAG_INFO_RESET                                    0x1
#define OLE_RX_CONFIG_RING0_ATTENTION_LSB                                      8
#define OLE_RX_CONFIG_RING0_ATTENTION_MSB                                      8
#define OLE_RX_CONFIG_RING0_ATTENTION_MASK                                     0x100
#define OLE_RX_CONFIG_RING0_ATTENTION_GET(x)                                   (((x) & OLE_RX_CONFIG_RING0_ATTENTION_MASK) >> OLE_RX_CONFIG_RING0_ATTENTION_LSB)
#define OLE_RX_CONFIG_RING0_ATTENTION_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING0_ATTENTION_LSB) & OLE_RX_CONFIG_RING0_ATTENTION_MASK)
#define OLE_RX_CONFIG_RING0_ATTENTION_RESET                                    0x1
#define OLE_RX_CONFIG_RING0_PPDU_END_LSB                                       7
#define OLE_RX_CONFIG_RING0_PPDU_END_MSB                                       7
#define OLE_RX_CONFIG_RING0_PPDU_END_MASK                                      0x80
#define OLE_RX_CONFIG_RING0_PPDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING0_PPDU_END_MASK) >> OLE_RX_CONFIG_RING0_PPDU_END_LSB)
#define OLE_RX_CONFIG_RING0_PPDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING0_PPDU_END_LSB) & OLE_RX_CONFIG_RING0_PPDU_END_MASK)
#define OLE_RX_CONFIG_RING0_PPDU_END_RESET                                     0x1
#define OLE_RX_CONFIG_RING0_MPDU_END_LSB                                       6
#define OLE_RX_CONFIG_RING0_MPDU_END_MSB                                       6
#define OLE_RX_CONFIG_RING0_MPDU_END_MASK                                      0x40
#define OLE_RX_CONFIG_RING0_MPDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING0_MPDU_END_MASK) >> OLE_RX_CONFIG_RING0_MPDU_END_LSB)
#define OLE_RX_CONFIG_RING0_MPDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING0_MPDU_END_LSB) & OLE_RX_CONFIG_RING0_MPDU_END_MASK)
#define OLE_RX_CONFIG_RING0_MPDU_END_RESET                                     0x1
#define OLE_RX_CONFIG_RING0_MSDU_END_LSB                                       5
#define OLE_RX_CONFIG_RING0_MSDU_END_MSB                                       5
#define OLE_RX_CONFIG_RING0_MSDU_END_MASK                                      0x20
#define OLE_RX_CONFIG_RING0_MSDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING0_MSDU_END_MASK) >> OLE_RX_CONFIG_RING0_MSDU_END_LSB)
#define OLE_RX_CONFIG_RING0_MSDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING0_MSDU_END_LSB) & OLE_RX_CONFIG_RING0_MSDU_END_MASK)
#define OLE_RX_CONFIG_RING0_MSDU_END_RESET                                     0x1
#define OLE_RX_CONFIG_RING0_PKT_LSB                                            4
#define OLE_RX_CONFIG_RING0_PKT_MSB                                            4
#define OLE_RX_CONFIG_RING0_PKT_MASK                                           0x10
#define OLE_RX_CONFIG_RING0_PKT_GET(x)                                         (((x) & OLE_RX_CONFIG_RING0_PKT_MASK) >> OLE_RX_CONFIG_RING0_PKT_LSB)
#define OLE_RX_CONFIG_RING0_PKT_SET(x)                                         (((0 | (x)) << OLE_RX_CONFIG_RING0_PKT_LSB) & OLE_RX_CONFIG_RING0_PKT_MASK)
#define OLE_RX_CONFIG_RING0_PKT_RESET                                          0x1
#define OLE_RX_CONFIG_RING0_MSDU_START_LSB                                     3
#define OLE_RX_CONFIG_RING0_MSDU_START_MSB                                     3
#define OLE_RX_CONFIG_RING0_MSDU_START_MASK                                    0x8
#define OLE_RX_CONFIG_RING0_MSDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING0_MSDU_START_MASK) >> OLE_RX_CONFIG_RING0_MSDU_START_LSB)
#define OLE_RX_CONFIG_RING0_MSDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING0_MSDU_START_LSB) & OLE_RX_CONFIG_RING0_MSDU_START_MASK)
#define OLE_RX_CONFIG_RING0_MSDU_START_RESET                                   0x1
#define OLE_RX_CONFIG_RING0_MPDU_START_LSB                                     2
#define OLE_RX_CONFIG_RING0_MPDU_START_MSB                                     2
#define OLE_RX_CONFIG_RING0_MPDU_START_MASK                                    0x4
#define OLE_RX_CONFIG_RING0_MPDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING0_MPDU_START_MASK) >> OLE_RX_CONFIG_RING0_MPDU_START_LSB)
#define OLE_RX_CONFIG_RING0_MPDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING0_MPDU_START_LSB) & OLE_RX_CONFIG_RING0_MPDU_START_MASK)
#define OLE_RX_CONFIG_RING0_MPDU_START_RESET                                   0x1
#define OLE_RX_CONFIG_RING0_HDR_LSB                                            1
#define OLE_RX_CONFIG_RING0_HDR_MSB                                            1
#define OLE_RX_CONFIG_RING0_HDR_MASK                                           0x2
#define OLE_RX_CONFIG_RING0_HDR_GET(x)                                         (((x) & OLE_RX_CONFIG_RING0_HDR_MASK) >> OLE_RX_CONFIG_RING0_HDR_LSB)
#define OLE_RX_CONFIG_RING0_HDR_SET(x)                                         (((0 | (x)) << OLE_RX_CONFIG_RING0_HDR_LSB) & OLE_RX_CONFIG_RING0_HDR_MASK)
#define OLE_RX_CONFIG_RING0_HDR_RESET                                          0x1
#define OLE_RX_CONFIG_RING0_PPDU_START_LSB                                     0
#define OLE_RX_CONFIG_RING0_PPDU_START_MSB                                     0
#define OLE_RX_CONFIG_RING0_PPDU_START_MASK                                    0x1
#define OLE_RX_CONFIG_RING0_PPDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING0_PPDU_START_MASK) >> OLE_RX_CONFIG_RING0_PPDU_START_LSB)
#define OLE_RX_CONFIG_RING0_PPDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING0_PPDU_START_LSB) & OLE_RX_CONFIG_RING0_PPDU_START_MASK)
#define OLE_RX_CONFIG_RING0_PPDU_START_RESET                                   0x1
#define OLE_RX_CONFIG_RING0_ADDRESS                                            (0x24 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_CONFIG_RING0_RSTMASK                                            0xffffffff
#define OLE_RX_CONFIG_RING0_RESET                                              0x3f03ff

// 0x28 (OLE_RX_CONFIG_RING1)
#define OLE_RX_CONFIG_RING1_RESERVED_2_LSB                                     28
#define OLE_RX_CONFIG_RING1_RESERVED_2_MSB                                     31
#define OLE_RX_CONFIG_RING1_RESERVED_2_MASK                                    0xf0000000
#define OLE_RX_CONFIG_RING1_RESERVED_2_GET(x)                                  (((x) & OLE_RX_CONFIG_RING1_RESERVED_2_MASK) >> OLE_RX_CONFIG_RING1_RESERVED_2_LSB)
#define OLE_RX_CONFIG_RING1_RESERVED_2_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING1_RESERVED_2_LSB) & OLE_RX_CONFIG_RING1_RESERVED_2_MASK)
#define OLE_RX_CONFIG_RING1_RESERVED_2_RESET                                   0x0
#define OLE_RX_CONFIG_RING1_ETHERNET_3_LSB                                     27
#define OLE_RX_CONFIG_RING1_ETHERNET_3_MSB                                     27
#define OLE_RX_CONFIG_RING1_ETHERNET_3_MASK                                    0x8000000
#define OLE_RX_CONFIG_RING1_ETHERNET_3_GET(x)                                  (((x) & OLE_RX_CONFIG_RING1_ETHERNET_3_MASK) >> OLE_RX_CONFIG_RING1_ETHERNET_3_LSB)
#define OLE_RX_CONFIG_RING1_ETHERNET_3_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING1_ETHERNET_3_LSB) & OLE_RX_CONFIG_RING1_ETHERNET_3_MASK)
#define OLE_RX_CONFIG_RING1_ETHERNET_3_RESET                                   0x0
#define OLE_RX_CONFIG_RING1_ETHERNET_2_LSB                                     26
#define OLE_RX_CONFIG_RING1_ETHERNET_2_MSB                                     26
#define OLE_RX_CONFIG_RING1_ETHERNET_2_MASK                                    0x4000000
#define OLE_RX_CONFIG_RING1_ETHERNET_2_GET(x)                                  (((x) & OLE_RX_CONFIG_RING1_ETHERNET_2_MASK) >> OLE_RX_CONFIG_RING1_ETHERNET_2_LSB)
#define OLE_RX_CONFIG_RING1_ETHERNET_2_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING1_ETHERNET_2_LSB) & OLE_RX_CONFIG_RING1_ETHERNET_2_MASK)
#define OLE_RX_CONFIG_RING1_ETHERNET_2_RESET                                   0x0
#define OLE_RX_CONFIG_RING1_ETHERNET_1_LSB                                     25
#define OLE_RX_CONFIG_RING1_ETHERNET_1_MSB                                     25
#define OLE_RX_CONFIG_RING1_ETHERNET_1_MASK                                    0x2000000
#define OLE_RX_CONFIG_RING1_ETHERNET_1_GET(x)                                  (((x) & OLE_RX_CONFIG_RING1_ETHERNET_1_MASK) >> OLE_RX_CONFIG_RING1_ETHERNET_1_LSB)
#define OLE_RX_CONFIG_RING1_ETHERNET_1_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING1_ETHERNET_1_LSB) & OLE_RX_CONFIG_RING1_ETHERNET_1_MASK)
#define OLE_RX_CONFIG_RING1_ETHERNET_1_RESET                                   0x0
#define OLE_RX_CONFIG_RING1_ETHERNET_0_LSB                                     24
#define OLE_RX_CONFIG_RING1_ETHERNET_0_MSB                                     24
#define OLE_RX_CONFIG_RING1_ETHERNET_0_MASK                                    0x1000000
#define OLE_RX_CONFIG_RING1_ETHERNET_0_GET(x)                                  (((x) & OLE_RX_CONFIG_RING1_ETHERNET_0_MASK) >> OLE_RX_CONFIG_RING1_ETHERNET_0_LSB)
#define OLE_RX_CONFIG_RING1_ETHERNET_0_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING1_ETHERNET_0_LSB) & OLE_RX_CONFIG_RING1_ETHERNET_0_MASK)
#define OLE_RX_CONFIG_RING1_ETHERNET_0_RESET                                   0x0
#define OLE_RX_CONFIG_RING1_RESERVED_1_LSB                                     22
#define OLE_RX_CONFIG_RING1_RESERVED_1_MSB                                     23
#define OLE_RX_CONFIG_RING1_RESERVED_1_MASK                                    0xc00000
#define OLE_RX_CONFIG_RING1_RESERVED_1_GET(x)                                  (((x) & OLE_RX_CONFIG_RING1_RESERVED_1_MASK) >> OLE_RX_CONFIG_RING1_RESERVED_1_LSB)
#define OLE_RX_CONFIG_RING1_RESERVED_1_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING1_RESERVED_1_LSB) & OLE_RX_CONFIG_RING1_RESERVED_1_MASK)
#define OLE_RX_CONFIG_RING1_RESERVED_1_RESET                                   0x0
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_LSB                                  21
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_MSB                                  21
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_MASK                                 0x200000
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_GET(x)                               (((x) & OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_SET(x)                               (((0 | (x)) << OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_RESET                                0x1
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_LSB                                 20
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_MSB                                 20
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_MASK                                0x100000
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_GET(x)                              (((x) & OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_SET(x)                              (((0 | (x)) << OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_RESET                               0x1
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_LSB                                19
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_MSB                                19
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_MASK                               0x80000
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_GET(x)                             (((x) & OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_SET(x)                             (((0 | (x)) << OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_RESET                              0x1
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_LSB                                18
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_MSB                                18
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_MASK                               0x40000
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_GET(x)                             (((x) & OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_SET(x)                             (((0 | (x)) << OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_RESET                              0x1
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_LSB                                      17
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_MSB                                      17
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_MASK                                     0x20000
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_GET(x)                                   (((x) & OLE_RX_CONFIG_RING1_MGMT_TYPE_MASK) >> OLE_RX_CONFIG_RING1_MGMT_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING1_MGMT_TYPE_LSB) & OLE_RX_CONFIG_RING1_MGMT_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_RESET                                    0x1
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_LSB                                      16
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_MSB                                      16
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_MASK                                     0x10000
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_GET(x)                                   (((x) & OLE_RX_CONFIG_RING1_CTRL_TYPE_MASK) >> OLE_RX_CONFIG_RING1_CTRL_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING1_CTRL_TYPE_LSB) & OLE_RX_CONFIG_RING1_CTRL_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_RESET                                    0x1
#define OLE_RX_CONFIG_RING1_RESERVED_0_LSB                                     10
#define OLE_RX_CONFIG_RING1_RESERVED_0_MSB                                     15
#define OLE_RX_CONFIG_RING1_RESERVED_0_MASK                                    0xfc00
#define OLE_RX_CONFIG_RING1_RESERVED_0_GET(x)                                  (((x) & OLE_RX_CONFIG_RING1_RESERVED_0_MASK) >> OLE_RX_CONFIG_RING1_RESERVED_0_LSB)
#define OLE_RX_CONFIG_RING1_RESERVED_0_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING1_RESERVED_0_LSB) & OLE_RX_CONFIG_RING1_RESERVED_0_MASK)
#define OLE_RX_CONFIG_RING1_RESERVED_0_RESET                                   0x0
#define OLE_RX_CONFIG_RING1_FRAG_INFO_LSB                                      9
#define OLE_RX_CONFIG_RING1_FRAG_INFO_MSB                                      9
#define OLE_RX_CONFIG_RING1_FRAG_INFO_MASK                                     0x200
#define OLE_RX_CONFIG_RING1_FRAG_INFO_GET(x)                                   (((x) & OLE_RX_CONFIG_RING1_FRAG_INFO_MASK) >> OLE_RX_CONFIG_RING1_FRAG_INFO_LSB)
#define OLE_RX_CONFIG_RING1_FRAG_INFO_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING1_FRAG_INFO_LSB) & OLE_RX_CONFIG_RING1_FRAG_INFO_MASK)
#define OLE_RX_CONFIG_RING1_FRAG_INFO_RESET                                    0x0
#define OLE_RX_CONFIG_RING1_ATTENTION_LSB                                      8
#define OLE_RX_CONFIG_RING1_ATTENTION_MSB                                      8
#define OLE_RX_CONFIG_RING1_ATTENTION_MASK                                     0x100
#define OLE_RX_CONFIG_RING1_ATTENTION_GET(x)                                   (((x) & OLE_RX_CONFIG_RING1_ATTENTION_MASK) >> OLE_RX_CONFIG_RING1_ATTENTION_LSB)
#define OLE_RX_CONFIG_RING1_ATTENTION_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING1_ATTENTION_LSB) & OLE_RX_CONFIG_RING1_ATTENTION_MASK)
#define OLE_RX_CONFIG_RING1_ATTENTION_RESET                                    0x0
#define OLE_RX_CONFIG_RING1_PPDU_END_LSB                                       7
#define OLE_RX_CONFIG_RING1_PPDU_END_MSB                                       7
#define OLE_RX_CONFIG_RING1_PPDU_END_MASK                                      0x80
#define OLE_RX_CONFIG_RING1_PPDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING1_PPDU_END_MASK) >> OLE_RX_CONFIG_RING1_PPDU_END_LSB)
#define OLE_RX_CONFIG_RING1_PPDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING1_PPDU_END_LSB) & OLE_RX_CONFIG_RING1_PPDU_END_MASK)
#define OLE_RX_CONFIG_RING1_PPDU_END_RESET                                     0x0
#define OLE_RX_CONFIG_RING1_MPDU_END_LSB                                       6
#define OLE_RX_CONFIG_RING1_MPDU_END_MSB                                       6
#define OLE_RX_CONFIG_RING1_MPDU_END_MASK                                      0x40
#define OLE_RX_CONFIG_RING1_MPDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING1_MPDU_END_MASK) >> OLE_RX_CONFIG_RING1_MPDU_END_LSB)
#define OLE_RX_CONFIG_RING1_MPDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING1_MPDU_END_LSB) & OLE_RX_CONFIG_RING1_MPDU_END_MASK)
#define OLE_RX_CONFIG_RING1_MPDU_END_RESET                                     0x0
#define OLE_RX_CONFIG_RING1_MSDU_END_LSB                                       5
#define OLE_RX_CONFIG_RING1_MSDU_END_MSB                                       5
#define OLE_RX_CONFIG_RING1_MSDU_END_MASK                                      0x20
#define OLE_RX_CONFIG_RING1_MSDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING1_MSDU_END_MASK) >> OLE_RX_CONFIG_RING1_MSDU_END_LSB)
#define OLE_RX_CONFIG_RING1_MSDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING1_MSDU_END_LSB) & OLE_RX_CONFIG_RING1_MSDU_END_MASK)
#define OLE_RX_CONFIG_RING1_MSDU_END_RESET                                     0x0
#define OLE_RX_CONFIG_RING1_PKT_LSB                                            4
#define OLE_RX_CONFIG_RING1_PKT_MSB                                            4
#define OLE_RX_CONFIG_RING1_PKT_MASK                                           0x10
#define OLE_RX_CONFIG_RING1_PKT_GET(x)                                         (((x) & OLE_RX_CONFIG_RING1_PKT_MASK) >> OLE_RX_CONFIG_RING1_PKT_LSB)
#define OLE_RX_CONFIG_RING1_PKT_SET(x)                                         (((0 | (x)) << OLE_RX_CONFIG_RING1_PKT_LSB) & OLE_RX_CONFIG_RING1_PKT_MASK)
#define OLE_RX_CONFIG_RING1_PKT_RESET                                          0x0
#define OLE_RX_CONFIG_RING1_MSDU_START_LSB                                     3
#define OLE_RX_CONFIG_RING1_MSDU_START_MSB                                     3
#define OLE_RX_CONFIG_RING1_MSDU_START_MASK                                    0x8
#define OLE_RX_CONFIG_RING1_MSDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING1_MSDU_START_MASK) >> OLE_RX_CONFIG_RING1_MSDU_START_LSB)
#define OLE_RX_CONFIG_RING1_MSDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING1_MSDU_START_LSB) & OLE_RX_CONFIG_RING1_MSDU_START_MASK)
#define OLE_RX_CONFIG_RING1_MSDU_START_RESET                                   0x0
#define OLE_RX_CONFIG_RING1_MPDU_START_LSB                                     2
#define OLE_RX_CONFIG_RING1_MPDU_START_MSB                                     2
#define OLE_RX_CONFIG_RING1_MPDU_START_MASK                                    0x4
#define OLE_RX_CONFIG_RING1_MPDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING1_MPDU_START_MASK) >> OLE_RX_CONFIG_RING1_MPDU_START_LSB)
#define OLE_RX_CONFIG_RING1_MPDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING1_MPDU_START_LSB) & OLE_RX_CONFIG_RING1_MPDU_START_MASK)
#define OLE_RX_CONFIG_RING1_MPDU_START_RESET                                   0x0
#define OLE_RX_CONFIG_RING1_HDR_LSB                                            1
#define OLE_RX_CONFIG_RING1_HDR_MSB                                            1
#define OLE_RX_CONFIG_RING1_HDR_MASK                                           0x2
#define OLE_RX_CONFIG_RING1_HDR_GET(x)                                         (((x) & OLE_RX_CONFIG_RING1_HDR_MASK) >> OLE_RX_CONFIG_RING1_HDR_LSB)
#define OLE_RX_CONFIG_RING1_HDR_SET(x)                                         (((0 | (x)) << OLE_RX_CONFIG_RING1_HDR_LSB) & OLE_RX_CONFIG_RING1_HDR_MASK)
#define OLE_RX_CONFIG_RING1_HDR_RESET                                          0x0
#define OLE_RX_CONFIG_RING1_PPDU_START_LSB                                     0
#define OLE_RX_CONFIG_RING1_PPDU_START_MSB                                     0
#define OLE_RX_CONFIG_RING1_PPDU_START_MASK                                    0x1
#define OLE_RX_CONFIG_RING1_PPDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING1_PPDU_START_MASK) >> OLE_RX_CONFIG_RING1_PPDU_START_LSB)
#define OLE_RX_CONFIG_RING1_PPDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING1_PPDU_START_LSB) & OLE_RX_CONFIG_RING1_PPDU_START_MASK)
#define OLE_RX_CONFIG_RING1_PPDU_START_RESET                                   0x0
#define OLE_RX_CONFIG_RING1_ADDRESS                                            (0x28 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_CONFIG_RING1_RSTMASK                                            0xffffffff
#define OLE_RX_CONFIG_RING1_RESET                                              0x3f0000

// 0x2c (OLE_RX_CONFIG_RING2)
#define OLE_RX_CONFIG_RING2_RESERVED_2_LSB                                     28
#define OLE_RX_CONFIG_RING2_RESERVED_2_MSB                                     31
#define OLE_RX_CONFIG_RING2_RESERVED_2_MASK                                    0xf0000000
#define OLE_RX_CONFIG_RING2_RESERVED_2_GET(x)                                  (((x) & OLE_RX_CONFIG_RING2_RESERVED_2_MASK) >> OLE_RX_CONFIG_RING2_RESERVED_2_LSB)
#define OLE_RX_CONFIG_RING2_RESERVED_2_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING2_RESERVED_2_LSB) & OLE_RX_CONFIG_RING2_RESERVED_2_MASK)
#define OLE_RX_CONFIG_RING2_RESERVED_2_RESET                                   0x0
#define OLE_RX_CONFIG_RING2_ETHERNET_3_LSB                                     27
#define OLE_RX_CONFIG_RING2_ETHERNET_3_MSB                                     27
#define OLE_RX_CONFIG_RING2_ETHERNET_3_MASK                                    0x8000000
#define OLE_RX_CONFIG_RING2_ETHERNET_3_GET(x)                                  (((x) & OLE_RX_CONFIG_RING2_ETHERNET_3_MASK) >> OLE_RX_CONFIG_RING2_ETHERNET_3_LSB)
#define OLE_RX_CONFIG_RING2_ETHERNET_3_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING2_ETHERNET_3_LSB) & OLE_RX_CONFIG_RING2_ETHERNET_3_MASK)
#define OLE_RX_CONFIG_RING2_ETHERNET_3_RESET                                   0x0
#define OLE_RX_CONFIG_RING2_ETHERNET_2_LSB                                     26
#define OLE_RX_CONFIG_RING2_ETHERNET_2_MSB                                     26
#define OLE_RX_CONFIG_RING2_ETHERNET_2_MASK                                    0x4000000
#define OLE_RX_CONFIG_RING2_ETHERNET_2_GET(x)                                  (((x) & OLE_RX_CONFIG_RING2_ETHERNET_2_MASK) >> OLE_RX_CONFIG_RING2_ETHERNET_2_LSB)
#define OLE_RX_CONFIG_RING2_ETHERNET_2_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING2_ETHERNET_2_LSB) & OLE_RX_CONFIG_RING2_ETHERNET_2_MASK)
#define OLE_RX_CONFIG_RING2_ETHERNET_2_RESET                                   0x0
#define OLE_RX_CONFIG_RING2_ETHERNET_1_LSB                                     25
#define OLE_RX_CONFIG_RING2_ETHERNET_1_MSB                                     25
#define OLE_RX_CONFIG_RING2_ETHERNET_1_MASK                                    0x2000000
#define OLE_RX_CONFIG_RING2_ETHERNET_1_GET(x)                                  (((x) & OLE_RX_CONFIG_RING2_ETHERNET_1_MASK) >> OLE_RX_CONFIG_RING2_ETHERNET_1_LSB)
#define OLE_RX_CONFIG_RING2_ETHERNET_1_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING2_ETHERNET_1_LSB) & OLE_RX_CONFIG_RING2_ETHERNET_1_MASK)
#define OLE_RX_CONFIG_RING2_ETHERNET_1_RESET                                   0x0
#define OLE_RX_CONFIG_RING2_ETHERNET_0_LSB                                     24
#define OLE_RX_CONFIG_RING2_ETHERNET_0_MSB                                     24
#define OLE_RX_CONFIG_RING2_ETHERNET_0_MASK                                    0x1000000
#define OLE_RX_CONFIG_RING2_ETHERNET_0_GET(x)                                  (((x) & OLE_RX_CONFIG_RING2_ETHERNET_0_MASK) >> OLE_RX_CONFIG_RING2_ETHERNET_0_LSB)
#define OLE_RX_CONFIG_RING2_ETHERNET_0_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING2_ETHERNET_0_LSB) & OLE_RX_CONFIG_RING2_ETHERNET_0_MASK)
#define OLE_RX_CONFIG_RING2_ETHERNET_0_RESET                                   0x0
#define OLE_RX_CONFIG_RING2_RESERVED_1_LSB                                     22
#define OLE_RX_CONFIG_RING2_RESERVED_1_MSB                                     23
#define OLE_RX_CONFIG_RING2_RESERVED_1_MASK                                    0xc00000
#define OLE_RX_CONFIG_RING2_RESERVED_1_GET(x)                                  (((x) & OLE_RX_CONFIG_RING2_RESERVED_1_MASK) >> OLE_RX_CONFIG_RING2_RESERVED_1_LSB)
#define OLE_RX_CONFIG_RING2_RESERVED_1_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING2_RESERVED_1_LSB) & OLE_RX_CONFIG_RING2_RESERVED_1_MASK)
#define OLE_RX_CONFIG_RING2_RESERVED_1_RESET                                   0x0
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_LSB                                  21
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_MSB                                  21
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_MASK                                 0x200000
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_GET(x)                               (((x) & OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_SET(x)                               (((0 | (x)) << OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_RESET                                0x1
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_LSB                                 20
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_MSB                                 20
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_MASK                                0x100000
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_GET(x)                              (((x) & OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_SET(x)                              (((0 | (x)) << OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_RESET                               0x1
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_LSB                                19
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_MSB                                19
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_MASK                               0x80000
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_GET(x)                             (((x) & OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_SET(x)                             (((0 | (x)) << OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_RESET                              0x1
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_LSB                                18
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_MSB                                18
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_MASK                               0x40000
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_GET(x)                             (((x) & OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_SET(x)                             (((0 | (x)) << OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_RESET                              0x1
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_LSB                                      17
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_MSB                                      17
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_MASK                                     0x20000
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_GET(x)                                   (((x) & OLE_RX_CONFIG_RING2_MGMT_TYPE_MASK) >> OLE_RX_CONFIG_RING2_MGMT_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING2_MGMT_TYPE_LSB) & OLE_RX_CONFIG_RING2_MGMT_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_RESET                                    0x1
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_LSB                                      16
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_MSB                                      16
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_MASK                                     0x10000
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_GET(x)                                   (((x) & OLE_RX_CONFIG_RING2_CTRL_TYPE_MASK) >> OLE_RX_CONFIG_RING2_CTRL_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING2_CTRL_TYPE_LSB) & OLE_RX_CONFIG_RING2_CTRL_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_RESET                                    0x1
#define OLE_RX_CONFIG_RING2_RESERVED_0_LSB                                     10
#define OLE_RX_CONFIG_RING2_RESERVED_0_MSB                                     15
#define OLE_RX_CONFIG_RING2_RESERVED_0_MASK                                    0xfc00
#define OLE_RX_CONFIG_RING2_RESERVED_0_GET(x)                                  (((x) & OLE_RX_CONFIG_RING2_RESERVED_0_MASK) >> OLE_RX_CONFIG_RING2_RESERVED_0_LSB)
#define OLE_RX_CONFIG_RING2_RESERVED_0_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING2_RESERVED_0_LSB) & OLE_RX_CONFIG_RING2_RESERVED_0_MASK)
#define OLE_RX_CONFIG_RING2_RESERVED_0_RESET                                   0x0
#define OLE_RX_CONFIG_RING2_FRAG_INFO_LSB                                      9
#define OLE_RX_CONFIG_RING2_FRAG_INFO_MSB                                      9
#define OLE_RX_CONFIG_RING2_FRAG_INFO_MASK                                     0x200
#define OLE_RX_CONFIG_RING2_FRAG_INFO_GET(x)                                   (((x) & OLE_RX_CONFIG_RING2_FRAG_INFO_MASK) >> OLE_RX_CONFIG_RING2_FRAG_INFO_LSB)
#define OLE_RX_CONFIG_RING2_FRAG_INFO_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING2_FRAG_INFO_LSB) & OLE_RX_CONFIG_RING2_FRAG_INFO_MASK)
#define OLE_RX_CONFIG_RING2_FRAG_INFO_RESET                                    0x0
#define OLE_RX_CONFIG_RING2_ATTENTION_LSB                                      8
#define OLE_RX_CONFIG_RING2_ATTENTION_MSB                                      8
#define OLE_RX_CONFIG_RING2_ATTENTION_MASK                                     0x100
#define OLE_RX_CONFIG_RING2_ATTENTION_GET(x)                                   (((x) & OLE_RX_CONFIG_RING2_ATTENTION_MASK) >> OLE_RX_CONFIG_RING2_ATTENTION_LSB)
#define OLE_RX_CONFIG_RING2_ATTENTION_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING2_ATTENTION_LSB) & OLE_RX_CONFIG_RING2_ATTENTION_MASK)
#define OLE_RX_CONFIG_RING2_ATTENTION_RESET                                    0x0
#define OLE_RX_CONFIG_RING2_PPDU_END_LSB                                       7
#define OLE_RX_CONFIG_RING2_PPDU_END_MSB                                       7
#define OLE_RX_CONFIG_RING2_PPDU_END_MASK                                      0x80
#define OLE_RX_CONFIG_RING2_PPDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING2_PPDU_END_MASK) >> OLE_RX_CONFIG_RING2_PPDU_END_LSB)
#define OLE_RX_CONFIG_RING2_PPDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING2_PPDU_END_LSB) & OLE_RX_CONFIG_RING2_PPDU_END_MASK)
#define OLE_RX_CONFIG_RING2_PPDU_END_RESET                                     0x0
#define OLE_RX_CONFIG_RING2_MPDU_END_LSB                                       6
#define OLE_RX_CONFIG_RING2_MPDU_END_MSB                                       6
#define OLE_RX_CONFIG_RING2_MPDU_END_MASK                                      0x40
#define OLE_RX_CONFIG_RING2_MPDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING2_MPDU_END_MASK) >> OLE_RX_CONFIG_RING2_MPDU_END_LSB)
#define OLE_RX_CONFIG_RING2_MPDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING2_MPDU_END_LSB) & OLE_RX_CONFIG_RING2_MPDU_END_MASK)
#define OLE_RX_CONFIG_RING2_MPDU_END_RESET                                     0x0
#define OLE_RX_CONFIG_RING2_MSDU_END_LSB                                       5
#define OLE_RX_CONFIG_RING2_MSDU_END_MSB                                       5
#define OLE_RX_CONFIG_RING2_MSDU_END_MASK                                      0x20
#define OLE_RX_CONFIG_RING2_MSDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING2_MSDU_END_MASK) >> OLE_RX_CONFIG_RING2_MSDU_END_LSB)
#define OLE_RX_CONFIG_RING2_MSDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING2_MSDU_END_LSB) & OLE_RX_CONFIG_RING2_MSDU_END_MASK)
#define OLE_RX_CONFIG_RING2_MSDU_END_RESET                                     0x0
#define OLE_RX_CONFIG_RING2_PKT_LSB                                            4
#define OLE_RX_CONFIG_RING2_PKT_MSB                                            4
#define OLE_RX_CONFIG_RING2_PKT_MASK                                           0x10
#define OLE_RX_CONFIG_RING2_PKT_GET(x)                                         (((x) & OLE_RX_CONFIG_RING2_PKT_MASK) >> OLE_RX_CONFIG_RING2_PKT_LSB)
#define OLE_RX_CONFIG_RING2_PKT_SET(x)                                         (((0 | (x)) << OLE_RX_CONFIG_RING2_PKT_LSB) & OLE_RX_CONFIG_RING2_PKT_MASK)
#define OLE_RX_CONFIG_RING2_PKT_RESET                                          0x0
#define OLE_RX_CONFIG_RING2_MSDU_START_LSB                                     3
#define OLE_RX_CONFIG_RING2_MSDU_START_MSB                                     3
#define OLE_RX_CONFIG_RING2_MSDU_START_MASK                                    0x8
#define OLE_RX_CONFIG_RING2_MSDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING2_MSDU_START_MASK) >> OLE_RX_CONFIG_RING2_MSDU_START_LSB)
#define OLE_RX_CONFIG_RING2_MSDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING2_MSDU_START_LSB) & OLE_RX_CONFIG_RING2_MSDU_START_MASK)
#define OLE_RX_CONFIG_RING2_MSDU_START_RESET                                   0x0
#define OLE_RX_CONFIG_RING2_MPDU_START_LSB                                     2
#define OLE_RX_CONFIG_RING2_MPDU_START_MSB                                     2
#define OLE_RX_CONFIG_RING2_MPDU_START_MASK                                    0x4
#define OLE_RX_CONFIG_RING2_MPDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING2_MPDU_START_MASK) >> OLE_RX_CONFIG_RING2_MPDU_START_LSB)
#define OLE_RX_CONFIG_RING2_MPDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING2_MPDU_START_LSB) & OLE_RX_CONFIG_RING2_MPDU_START_MASK)
#define OLE_RX_CONFIG_RING2_MPDU_START_RESET                                   0x0
#define OLE_RX_CONFIG_RING2_HDR_LSB                                            1
#define OLE_RX_CONFIG_RING2_HDR_MSB                                            1
#define OLE_RX_CONFIG_RING2_HDR_MASK                                           0x2
#define OLE_RX_CONFIG_RING2_HDR_GET(x)                                         (((x) & OLE_RX_CONFIG_RING2_HDR_MASK) >> OLE_RX_CONFIG_RING2_HDR_LSB)
#define OLE_RX_CONFIG_RING2_HDR_SET(x)                                         (((0 | (x)) << OLE_RX_CONFIG_RING2_HDR_LSB) & OLE_RX_CONFIG_RING2_HDR_MASK)
#define OLE_RX_CONFIG_RING2_HDR_RESET                                          0x0
#define OLE_RX_CONFIG_RING2_PPDU_START_LSB                                     0
#define OLE_RX_CONFIG_RING2_PPDU_START_MSB                                     0
#define OLE_RX_CONFIG_RING2_PPDU_START_MASK                                    0x1
#define OLE_RX_CONFIG_RING2_PPDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING2_PPDU_START_MASK) >> OLE_RX_CONFIG_RING2_PPDU_START_LSB)
#define OLE_RX_CONFIG_RING2_PPDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING2_PPDU_START_LSB) & OLE_RX_CONFIG_RING2_PPDU_START_MASK)
#define OLE_RX_CONFIG_RING2_PPDU_START_RESET                                   0x0
#define OLE_RX_CONFIG_RING2_ADDRESS                                            (0x2c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_CONFIG_RING2_RSTMASK                                            0xffffffff
#define OLE_RX_CONFIG_RING2_RESET                                              0x3f0000

// 0x30 (OLE_RX_CONFIG_RING3)
#define OLE_RX_CONFIG_RING3_RESERVED_2_LSB                                     28
#define OLE_RX_CONFIG_RING3_RESERVED_2_MSB                                     31
#define OLE_RX_CONFIG_RING3_RESERVED_2_MASK                                    0xf0000000
#define OLE_RX_CONFIG_RING3_RESERVED_2_GET(x)                                  (((x) & OLE_RX_CONFIG_RING3_RESERVED_2_MASK) >> OLE_RX_CONFIG_RING3_RESERVED_2_LSB)
#define OLE_RX_CONFIG_RING3_RESERVED_2_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING3_RESERVED_2_LSB) & OLE_RX_CONFIG_RING3_RESERVED_2_MASK)
#define OLE_RX_CONFIG_RING3_RESERVED_2_RESET                                   0x0
#define OLE_RX_CONFIG_RING3_ETHERNET_3_LSB                                     27
#define OLE_RX_CONFIG_RING3_ETHERNET_3_MSB                                     27
#define OLE_RX_CONFIG_RING3_ETHERNET_3_MASK                                    0x8000000
#define OLE_RX_CONFIG_RING3_ETHERNET_3_GET(x)                                  (((x) & OLE_RX_CONFIG_RING3_ETHERNET_3_MASK) >> OLE_RX_CONFIG_RING3_ETHERNET_3_LSB)
#define OLE_RX_CONFIG_RING3_ETHERNET_3_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING3_ETHERNET_3_LSB) & OLE_RX_CONFIG_RING3_ETHERNET_3_MASK)
#define OLE_RX_CONFIG_RING3_ETHERNET_3_RESET                                   0x0
#define OLE_RX_CONFIG_RING3_ETHERNET_2_LSB                                     26
#define OLE_RX_CONFIG_RING3_ETHERNET_2_MSB                                     26
#define OLE_RX_CONFIG_RING3_ETHERNET_2_MASK                                    0x4000000
#define OLE_RX_CONFIG_RING3_ETHERNET_2_GET(x)                                  (((x) & OLE_RX_CONFIG_RING3_ETHERNET_2_MASK) >> OLE_RX_CONFIG_RING3_ETHERNET_2_LSB)
#define OLE_RX_CONFIG_RING3_ETHERNET_2_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING3_ETHERNET_2_LSB) & OLE_RX_CONFIG_RING3_ETHERNET_2_MASK)
#define OLE_RX_CONFIG_RING3_ETHERNET_2_RESET                                   0x0
#define OLE_RX_CONFIG_RING3_ETHERNET_1_LSB                                     25
#define OLE_RX_CONFIG_RING3_ETHERNET_1_MSB                                     25
#define OLE_RX_CONFIG_RING3_ETHERNET_1_MASK                                    0x2000000
#define OLE_RX_CONFIG_RING3_ETHERNET_1_GET(x)                                  (((x) & OLE_RX_CONFIG_RING3_ETHERNET_1_MASK) >> OLE_RX_CONFIG_RING3_ETHERNET_1_LSB)
#define OLE_RX_CONFIG_RING3_ETHERNET_1_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING3_ETHERNET_1_LSB) & OLE_RX_CONFIG_RING3_ETHERNET_1_MASK)
#define OLE_RX_CONFIG_RING3_ETHERNET_1_RESET                                   0x0
#define OLE_RX_CONFIG_RING3_ETHERNET_0_LSB                                     24
#define OLE_RX_CONFIG_RING3_ETHERNET_0_MSB                                     24
#define OLE_RX_CONFIG_RING3_ETHERNET_0_MASK                                    0x1000000
#define OLE_RX_CONFIG_RING3_ETHERNET_0_GET(x)                                  (((x) & OLE_RX_CONFIG_RING3_ETHERNET_0_MASK) >> OLE_RX_CONFIG_RING3_ETHERNET_0_LSB)
#define OLE_RX_CONFIG_RING3_ETHERNET_0_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING3_ETHERNET_0_LSB) & OLE_RX_CONFIG_RING3_ETHERNET_0_MASK)
#define OLE_RX_CONFIG_RING3_ETHERNET_0_RESET                                   0x0
#define OLE_RX_CONFIG_RING3_RESERVED_1_LSB                                     22
#define OLE_RX_CONFIG_RING3_RESERVED_1_MSB                                     23
#define OLE_RX_CONFIG_RING3_RESERVED_1_MASK                                    0xc00000
#define OLE_RX_CONFIG_RING3_RESERVED_1_GET(x)                                  (((x) & OLE_RX_CONFIG_RING3_RESERVED_1_MASK) >> OLE_RX_CONFIG_RING3_RESERVED_1_LSB)
#define OLE_RX_CONFIG_RING3_RESERVED_1_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING3_RESERVED_1_LSB) & OLE_RX_CONFIG_RING3_RESERVED_1_MASK)
#define OLE_RX_CONFIG_RING3_RESERVED_1_RESET                                   0x0
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_LSB                                  21
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_MSB                                  21
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_MASK                                 0x200000
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_GET(x)                               (((x) & OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_SET(x)                               (((0 | (x)) << OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_RESET                                0x1
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_LSB                                 20
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_MSB                                 20
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_MASK                                0x100000
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_GET(x)                              (((x) & OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_SET(x)                              (((0 | (x)) << OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_RESET                               0x1
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_LSB                                19
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_MSB                                19
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_MASK                               0x80000
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_GET(x)                             (((x) & OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_SET(x)                             (((0 | (x)) << OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_RESET                              0x1
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_LSB                                18
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_MSB                                18
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_MASK                               0x40000
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_GET(x)                             (((x) & OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_SET(x)                             (((0 | (x)) << OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_RESET                              0x1
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_LSB                                      17
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_MSB                                      17
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_MASK                                     0x20000
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_GET(x)                                   (((x) & OLE_RX_CONFIG_RING3_MGMT_TYPE_MASK) >> OLE_RX_CONFIG_RING3_MGMT_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING3_MGMT_TYPE_LSB) & OLE_RX_CONFIG_RING3_MGMT_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_RESET                                    0x1
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_LSB                                      16
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_MSB                                      16
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_MASK                                     0x10000
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_GET(x)                                   (((x) & OLE_RX_CONFIG_RING3_CTRL_TYPE_MASK) >> OLE_RX_CONFIG_RING3_CTRL_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING3_CTRL_TYPE_LSB) & OLE_RX_CONFIG_RING3_CTRL_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_RESET                                    0x1
#define OLE_RX_CONFIG_RING3_RESERVED_0_LSB                                     10
#define OLE_RX_CONFIG_RING3_RESERVED_0_MSB                                     15
#define OLE_RX_CONFIG_RING3_RESERVED_0_MASK                                    0xfc00
#define OLE_RX_CONFIG_RING3_RESERVED_0_GET(x)                                  (((x) & OLE_RX_CONFIG_RING3_RESERVED_0_MASK) >> OLE_RX_CONFIG_RING3_RESERVED_0_LSB)
#define OLE_RX_CONFIG_RING3_RESERVED_0_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING3_RESERVED_0_LSB) & OLE_RX_CONFIG_RING3_RESERVED_0_MASK)
#define OLE_RX_CONFIG_RING3_RESERVED_0_RESET                                   0x0
#define OLE_RX_CONFIG_RING3_FRAG_INFO_LSB                                      9
#define OLE_RX_CONFIG_RING3_FRAG_INFO_MSB                                      9
#define OLE_RX_CONFIG_RING3_FRAG_INFO_MASK                                     0x200
#define OLE_RX_CONFIG_RING3_FRAG_INFO_GET(x)                                   (((x) & OLE_RX_CONFIG_RING3_FRAG_INFO_MASK) >> OLE_RX_CONFIG_RING3_FRAG_INFO_LSB)
#define OLE_RX_CONFIG_RING3_FRAG_INFO_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING3_FRAG_INFO_LSB) & OLE_RX_CONFIG_RING3_FRAG_INFO_MASK)
#define OLE_RX_CONFIG_RING3_FRAG_INFO_RESET                                    0x0
#define OLE_RX_CONFIG_RING3_ATTENTION_LSB                                      8
#define OLE_RX_CONFIG_RING3_ATTENTION_MSB                                      8
#define OLE_RX_CONFIG_RING3_ATTENTION_MASK                                     0x100
#define OLE_RX_CONFIG_RING3_ATTENTION_GET(x)                                   (((x) & OLE_RX_CONFIG_RING3_ATTENTION_MASK) >> OLE_RX_CONFIG_RING3_ATTENTION_LSB)
#define OLE_RX_CONFIG_RING3_ATTENTION_SET(x)                                   (((0 | (x)) << OLE_RX_CONFIG_RING3_ATTENTION_LSB) & OLE_RX_CONFIG_RING3_ATTENTION_MASK)
#define OLE_RX_CONFIG_RING3_ATTENTION_RESET                                    0x0
#define OLE_RX_CONFIG_RING3_PPDU_END_LSB                                       7
#define OLE_RX_CONFIG_RING3_PPDU_END_MSB                                       7
#define OLE_RX_CONFIG_RING3_PPDU_END_MASK                                      0x80
#define OLE_RX_CONFIG_RING3_PPDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING3_PPDU_END_MASK) >> OLE_RX_CONFIG_RING3_PPDU_END_LSB)
#define OLE_RX_CONFIG_RING3_PPDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING3_PPDU_END_LSB) & OLE_RX_CONFIG_RING3_PPDU_END_MASK)
#define OLE_RX_CONFIG_RING3_PPDU_END_RESET                                     0x0
#define OLE_RX_CONFIG_RING3_MPDU_END_LSB                                       6
#define OLE_RX_CONFIG_RING3_MPDU_END_MSB                                       6
#define OLE_RX_CONFIG_RING3_MPDU_END_MASK                                      0x40
#define OLE_RX_CONFIG_RING3_MPDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING3_MPDU_END_MASK) >> OLE_RX_CONFIG_RING3_MPDU_END_LSB)
#define OLE_RX_CONFIG_RING3_MPDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING3_MPDU_END_LSB) & OLE_RX_CONFIG_RING3_MPDU_END_MASK)
#define OLE_RX_CONFIG_RING3_MPDU_END_RESET                                     0x0
#define OLE_RX_CONFIG_RING3_MSDU_END_LSB                                       5
#define OLE_RX_CONFIG_RING3_MSDU_END_MSB                                       5
#define OLE_RX_CONFIG_RING3_MSDU_END_MASK                                      0x20
#define OLE_RX_CONFIG_RING3_MSDU_END_GET(x)                                    (((x) & OLE_RX_CONFIG_RING3_MSDU_END_MASK) >> OLE_RX_CONFIG_RING3_MSDU_END_LSB)
#define OLE_RX_CONFIG_RING3_MSDU_END_SET(x)                                    (((0 | (x)) << OLE_RX_CONFIG_RING3_MSDU_END_LSB) & OLE_RX_CONFIG_RING3_MSDU_END_MASK)
#define OLE_RX_CONFIG_RING3_MSDU_END_RESET                                     0x0
#define OLE_RX_CONFIG_RING3_PKT_LSB                                            4
#define OLE_RX_CONFIG_RING3_PKT_MSB                                            4
#define OLE_RX_CONFIG_RING3_PKT_MASK                                           0x10
#define OLE_RX_CONFIG_RING3_PKT_GET(x)                                         (((x) & OLE_RX_CONFIG_RING3_PKT_MASK) >> OLE_RX_CONFIG_RING3_PKT_LSB)
#define OLE_RX_CONFIG_RING3_PKT_SET(x)                                         (((0 | (x)) << OLE_RX_CONFIG_RING3_PKT_LSB) & OLE_RX_CONFIG_RING3_PKT_MASK)
#define OLE_RX_CONFIG_RING3_PKT_RESET                                          0x0
#define OLE_RX_CONFIG_RING3_MSDU_START_LSB                                     3
#define OLE_RX_CONFIG_RING3_MSDU_START_MSB                                     3
#define OLE_RX_CONFIG_RING3_MSDU_START_MASK                                    0x8
#define OLE_RX_CONFIG_RING3_MSDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING3_MSDU_START_MASK) >> OLE_RX_CONFIG_RING3_MSDU_START_LSB)
#define OLE_RX_CONFIG_RING3_MSDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING3_MSDU_START_LSB) & OLE_RX_CONFIG_RING3_MSDU_START_MASK)
#define OLE_RX_CONFIG_RING3_MSDU_START_RESET                                   0x0
#define OLE_RX_CONFIG_RING3_MPDU_START_LSB                                     2
#define OLE_RX_CONFIG_RING3_MPDU_START_MSB                                     2
#define OLE_RX_CONFIG_RING3_MPDU_START_MASK                                    0x4
#define OLE_RX_CONFIG_RING3_MPDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING3_MPDU_START_MASK) >> OLE_RX_CONFIG_RING3_MPDU_START_LSB)
#define OLE_RX_CONFIG_RING3_MPDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING3_MPDU_START_LSB) & OLE_RX_CONFIG_RING3_MPDU_START_MASK)
#define OLE_RX_CONFIG_RING3_MPDU_START_RESET                                   0x0
#define OLE_RX_CONFIG_RING3_HDR_LSB                                            1
#define OLE_RX_CONFIG_RING3_HDR_MSB                                            1
#define OLE_RX_CONFIG_RING3_HDR_MASK                                           0x2
#define OLE_RX_CONFIG_RING3_HDR_GET(x)                                         (((x) & OLE_RX_CONFIG_RING3_HDR_MASK) >> OLE_RX_CONFIG_RING3_HDR_LSB)
#define OLE_RX_CONFIG_RING3_HDR_SET(x)                                         (((0 | (x)) << OLE_RX_CONFIG_RING3_HDR_LSB) & OLE_RX_CONFIG_RING3_HDR_MASK)
#define OLE_RX_CONFIG_RING3_HDR_RESET                                          0x0
#define OLE_RX_CONFIG_RING3_PPDU_START_LSB                                     0
#define OLE_RX_CONFIG_RING3_PPDU_START_MSB                                     0
#define OLE_RX_CONFIG_RING3_PPDU_START_MASK                                    0x1
#define OLE_RX_CONFIG_RING3_PPDU_START_GET(x)                                  (((x) & OLE_RX_CONFIG_RING3_PPDU_START_MASK) >> OLE_RX_CONFIG_RING3_PPDU_START_LSB)
#define OLE_RX_CONFIG_RING3_PPDU_START_SET(x)                                  (((0 | (x)) << OLE_RX_CONFIG_RING3_PPDU_START_LSB) & OLE_RX_CONFIG_RING3_PPDU_START_MASK)
#define OLE_RX_CONFIG_RING3_PPDU_START_RESET                                   0x0
#define OLE_RX_CONFIG_RING3_ADDRESS                                            (0x30 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_CONFIG_RING3_RSTMASK                                            0xffffffff
#define OLE_RX_CONFIG_RING3_RESET                                              0x3f0000

// 0x34 (OLE_DECAP_CONFIG)
#define OLE_DECAP_CONFIG_EV_135902_DISABLE_LSB                                 17
#define OLE_DECAP_CONFIG_EV_135902_DISABLE_MSB                                 17
#define OLE_DECAP_CONFIG_EV_135902_DISABLE_MASK                                0x20000
#define OLE_DECAP_CONFIG_EV_135902_DISABLE_GET(x)                              (((x) & OLE_DECAP_CONFIG_EV_135902_DISABLE_MASK) >> OLE_DECAP_CONFIG_EV_135902_DISABLE_LSB)
#define OLE_DECAP_CONFIG_EV_135902_DISABLE_SET(x)                              (((0 | (x)) << OLE_DECAP_CONFIG_EV_135902_DISABLE_LSB) & OLE_DECAP_CONFIG_EV_135902_DISABLE_MASK)
#define OLE_DECAP_CONFIG_EV_135902_DISABLE_RESET                               0x1
#define OLE_DECAP_CONFIG_ENABLE_PE_LSB                                         16
#define OLE_DECAP_CONFIG_ENABLE_PE_MSB                                         16
#define OLE_DECAP_CONFIG_ENABLE_PE_MASK                                        0x10000
#define OLE_DECAP_CONFIG_ENABLE_PE_GET(x)                                      (((x) & OLE_DECAP_CONFIG_ENABLE_PE_MASK) >> OLE_DECAP_CONFIG_ENABLE_PE_LSB)
#define OLE_DECAP_CONFIG_ENABLE_PE_SET(x)                                      (((0 | (x)) << OLE_DECAP_CONFIG_ENABLE_PE_LSB) & OLE_DECAP_CONFIG_ENABLE_PE_MASK)
#define OLE_DECAP_CONFIG_ENABLE_PE_RESET                                       0x1
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_LSB                                  8
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_MSB                                  15
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_MASK                                 0xff00
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_GET(x)                               (((x) & OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_MASK) >> OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_LSB)
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_SET(x)                               (((0 | (x)) << OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_LSB) & OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_MASK)
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_RESET                                0x10
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_LSB                                  7
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_MSB                                  7
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_MASK                                 0x80
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_GET(x)                               (((x) & OLE_DECAP_CONFIG_CHECKSUM_DISABLE_MASK) >> OLE_DECAP_CONFIG_CHECKSUM_DISABLE_LSB)
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_SET(x)                               (((0 | (x)) << OLE_DECAP_CONFIG_CHECKSUM_DISABLE_LSB) & OLE_DECAP_CONFIG_CHECKSUM_DISABLE_MASK)
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_RESET                                0x1
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_LSB                         6
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_MSB                         6
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_MASK                        0x40
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_GET(x)                      (((x) & OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_MASK) >> OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_LSB)
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_SET(x)                      (((0 | (x)) << OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_LSB) & OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_MASK)
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_RESET                       0x1
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_LSB                              5
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_MSB                              5
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_MASK                             0x20
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_GET(x)                           (((x) & OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_MASK) >> OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_LSB)
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_SET(x)                           (((0 | (x)) << OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_LSB) & OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_MASK)
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_RESET                            0x1
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_LSB                                   4
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_MSB                                   4
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_MASK                                  0x10
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_GET(x)                                (((x) & OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_MASK) >> OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_LSB)
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_SET(x)                                (((0 | (x)) << OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_LSB) & OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_MASK)
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_RESET                                 0x1
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_LSB                          3
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_MSB                          3
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_MASK                         0x8
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_GET(x)                       (((x) & OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_MASK) >> OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_LSB)
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_SET(x)                       (((0 | (x)) << OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_LSB) & OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_MASK)
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_RESET                        0x1
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_LSB                                   2
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_MSB                                   2
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_MASK                                  0x4
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_GET(x)                                (((x) & OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_MASK) >> OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_LSB)
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_SET(x)                                (((0 | (x)) << OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_LSB) & OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_MASK)
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_RESET                                 0x0
#define OLE_DECAP_CONFIG_TARGET_FORMAT_LSB                                     1
#define OLE_DECAP_CONFIG_TARGET_FORMAT_MSB                                     1
#define OLE_DECAP_CONFIG_TARGET_FORMAT_MASK                                    0x2
#define OLE_DECAP_CONFIG_TARGET_FORMAT_GET(x)                                  (((x) & OLE_DECAP_CONFIG_TARGET_FORMAT_MASK) >> OLE_DECAP_CONFIG_TARGET_FORMAT_LSB)
#define OLE_DECAP_CONFIG_TARGET_FORMAT_SET(x)                                  (((0 | (x)) << OLE_DECAP_CONFIG_TARGET_FORMAT_LSB) & OLE_DECAP_CONFIG_TARGET_FORMAT_MASK)
#define OLE_DECAP_CONFIG_TARGET_FORMAT_RESET                                   0x1
#define OLE_DECAP_CONFIG_ENABLE_LSB                                            0
#define OLE_DECAP_CONFIG_ENABLE_MSB                                            0
#define OLE_DECAP_CONFIG_ENABLE_MASK                                           0x1
#define OLE_DECAP_CONFIG_ENABLE_GET(x)                                         (((x) & OLE_DECAP_CONFIG_ENABLE_MASK) >> OLE_DECAP_CONFIG_ENABLE_LSB)
#define OLE_DECAP_CONFIG_ENABLE_SET(x)                                         (((0 | (x)) << OLE_DECAP_CONFIG_ENABLE_LSB) & OLE_DECAP_CONFIG_ENABLE_MASK)
#define OLE_DECAP_CONFIG_ENABLE_RESET                                          0x0
#define OLE_DECAP_CONFIG_ADDRESS                                               (0x34 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_CONFIG_RSTMASK                                               0x3ffff
#define OLE_DECAP_CONFIG_RESET                                                 0x310fa

// 0x38 (OLE_HEADER_PADDING)
#define OLE_HEADER_PADDING_RX_L3_HEADER_PADDING_LSB                            2
#define OLE_HEADER_PADDING_RX_L3_HEADER_PADDING_MSB                            2
#define OLE_HEADER_PADDING_RX_L3_HEADER_PADDING_MASK                           0x4
#define OLE_HEADER_PADDING_RX_L3_HEADER_PADDING_GET(x)                         (((x) & OLE_HEADER_PADDING_RX_L3_HEADER_PADDING_MASK) >> OLE_HEADER_PADDING_RX_L3_HEADER_PADDING_LSB)
#define OLE_HEADER_PADDING_RX_L3_HEADER_PADDING_SET(x)                         (((0 | (x)) << OLE_HEADER_PADDING_RX_L3_HEADER_PADDING_LSB) & OLE_HEADER_PADDING_RX_L3_HEADER_PADDING_MASK)
#define OLE_HEADER_PADDING_RX_L3_HEADER_PADDING_RESET                          0x0
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_LSB                        1
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_MSB                        1
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_MASK                       0x2
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_GET(x)                     (((x) & OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_MASK) >> OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_LSB)
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_SET(x)                     (((0 | (x)) << OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_LSB) & OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_MASK)
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_RESET                      0x1
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_LSB                         0
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_MSB                         0
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_MASK                        0x1
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_GET(x)                      (((x) & OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_MASK) >> OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_LSB)
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_SET(x)                      (((0 | (x)) << OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_LSB) & OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_MASK)
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_RESET                       0x0
#define OLE_HEADER_PADDING_ADDRESS                                             (0x38 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_HEADER_PADDING_RSTMASK                                             0x7
#define OLE_HEADER_PADDING_RESET                                               0x2

// 0x3c (OLE_DECAP_TABLE_0_HALF1)
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_LSB                              25
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_MSB                              25
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_MASK                             0x2000000
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_GET(x)                           (((x) & OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_SET(x)                           (((0 | (x)) << OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_RESET                            0x1
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_LSB                                     24
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_MSB                                     24
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_MASK                                    0x1000000
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_GET(x)                                  (((x) & OLE_DECAP_TABLE_0_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_0_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_SET(x)                                  (((0 | (x)) << OLE_DECAP_TABLE_0_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_0_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_RESET                                   0x1
#define OLE_DECAP_TABLE_0_HALF1_OUI_LSB                                        0
#define OLE_DECAP_TABLE_0_HALF1_OUI_MSB                                        23
#define OLE_DECAP_TABLE_0_HALF1_OUI_MASK                                       0xffffff
#define OLE_DECAP_TABLE_0_HALF1_OUI_GET(x)                                     (((x) & OLE_DECAP_TABLE_0_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_0_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_0_HALF1_OUI_SET(x)                                     (((0 | (x)) << OLE_DECAP_TABLE_0_HALF1_OUI_LSB) & OLE_DECAP_TABLE_0_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_0_HALF1_OUI_RESET                                      0x0
#define OLE_DECAP_TABLE_0_HALF1_ADDRESS                                        (0x3c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_0_HALF1_RSTMASK                                        0x3ffffff
#define OLE_DECAP_TABLE_0_HALF1_RESET                                          0x3000000

// 0x40 (OLE_DECAP_TABLE_0_HALF2)
#define OLE_DECAP_TABLE_0_HALF2_TYPE_LSB                                       0
#define OLE_DECAP_TABLE_0_HALF2_TYPE_MSB                                       15
#define OLE_DECAP_TABLE_0_HALF2_TYPE_MASK                                      0xffff
#define OLE_DECAP_TABLE_0_HALF2_TYPE_GET(x)                                    (((x) & OLE_DECAP_TABLE_0_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_0_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_0_HALF2_TYPE_SET(x)                                    (((0 | (x)) << OLE_DECAP_TABLE_0_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_0_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_0_HALF2_TYPE_RESET                                     0x800
#define OLE_DECAP_TABLE_0_HALF2_ADDRESS                                        (0x40 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_0_HALF2_RSTMASK                                        0xffff
#define OLE_DECAP_TABLE_0_HALF2_RESET                                          0x800

// 0x44 (OLE_DECAP_TABLE_1_HALF1)
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_LSB                              25
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_MSB                              25
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_MASK                             0x2000000
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_GET(x)                           (((x) & OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_SET(x)                           (((0 | (x)) << OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_RESET                            0x1
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_LSB                                     24
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_MSB                                     24
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_MASK                                    0x1000000
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_GET(x)                                  (((x) & OLE_DECAP_TABLE_1_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_1_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_SET(x)                                  (((0 | (x)) << OLE_DECAP_TABLE_1_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_1_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_RESET                                   0x1
#define OLE_DECAP_TABLE_1_HALF1_OUI_LSB                                        0
#define OLE_DECAP_TABLE_1_HALF1_OUI_MSB                                        23
#define OLE_DECAP_TABLE_1_HALF1_OUI_MASK                                       0xffffff
#define OLE_DECAP_TABLE_1_HALF1_OUI_GET(x)                                     (((x) & OLE_DECAP_TABLE_1_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_1_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_1_HALF1_OUI_SET(x)                                     (((0 | (x)) << OLE_DECAP_TABLE_1_HALF1_OUI_LSB) & OLE_DECAP_TABLE_1_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_1_HALF1_OUI_RESET                                      0x0
#define OLE_DECAP_TABLE_1_HALF1_ADDRESS                                        (0x44 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_1_HALF1_RSTMASK                                        0x3ffffff
#define OLE_DECAP_TABLE_1_HALF1_RESET                                          0x3000000

// 0x48 (OLE_DECAP_TABLE_1_HALF2)
#define OLE_DECAP_TABLE_1_HALF2_TYPE_LSB                                       0
#define OLE_DECAP_TABLE_1_HALF2_TYPE_MSB                                       15
#define OLE_DECAP_TABLE_1_HALF2_TYPE_MASK                                      0xffff
#define OLE_DECAP_TABLE_1_HALF2_TYPE_GET(x)                                    (((x) & OLE_DECAP_TABLE_1_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_1_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_1_HALF2_TYPE_SET(x)                                    (((0 | (x)) << OLE_DECAP_TABLE_1_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_1_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_1_HALF2_TYPE_RESET                                     0x86dd
#define OLE_DECAP_TABLE_1_HALF2_ADDRESS                                        (0x48 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_1_HALF2_RSTMASK                                        0xffff
#define OLE_DECAP_TABLE_1_HALF2_RESET                                          0x86dd

// 0x4c (OLE_DECAP_TABLE_2_HALF1)
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_LSB                              25
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_MSB                              25
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_MASK                             0x2000000
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_GET(x)                           (((x) & OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_SET(x)                           (((0 | (x)) << OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_RESET                            0x1
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_LSB                                     24
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_MSB                                     24
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_MASK                                    0x1000000
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_GET(x)                                  (((x) & OLE_DECAP_TABLE_2_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_2_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_SET(x)                                  (((0 | (x)) << OLE_DECAP_TABLE_2_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_2_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_RESET                                   0x1
#define OLE_DECAP_TABLE_2_HALF1_OUI_LSB                                        0
#define OLE_DECAP_TABLE_2_HALF1_OUI_MSB                                        23
#define OLE_DECAP_TABLE_2_HALF1_OUI_MASK                                       0xffffff
#define OLE_DECAP_TABLE_2_HALF1_OUI_GET(x)                                     (((x) & OLE_DECAP_TABLE_2_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_2_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_2_HALF1_OUI_SET(x)                                     (((0 | (x)) << OLE_DECAP_TABLE_2_HALF1_OUI_LSB) & OLE_DECAP_TABLE_2_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_2_HALF1_OUI_RESET                                      0x0
#define OLE_DECAP_TABLE_2_HALF1_ADDRESS                                        (0x4c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_2_HALF1_RSTMASK                                        0x3ffffff
#define OLE_DECAP_TABLE_2_HALF1_RESET                                          0x3000000

// 0x50 (OLE_DECAP_TABLE_2_HALF2)
#define OLE_DECAP_TABLE_2_HALF2_TYPE_LSB                                       0
#define OLE_DECAP_TABLE_2_HALF2_TYPE_MSB                                       15
#define OLE_DECAP_TABLE_2_HALF2_TYPE_MASK                                      0xffff
#define OLE_DECAP_TABLE_2_HALF2_TYPE_GET(x)                                    (((x) & OLE_DECAP_TABLE_2_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_2_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_2_HALF2_TYPE_SET(x)                                    (((0 | (x)) << OLE_DECAP_TABLE_2_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_2_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_2_HALF2_TYPE_RESET                                     0x806
#define OLE_DECAP_TABLE_2_HALF2_ADDRESS                                        (0x50 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_2_HALF2_RSTMASK                                        0xffff
#define OLE_DECAP_TABLE_2_HALF2_RESET                                          0x806

// 0x54 (OLE_DECAP_TABLE_3_HALF1)
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_LSB                              25
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_MSB                              25
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_MASK                             0x2000000
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_GET(x)                           (((x) & OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_SET(x)                           (((0 | (x)) << OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_RESET                            0x1
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_LSB                                     24
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_MSB                                     24
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_MASK                                    0x1000000
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_GET(x)                                  (((x) & OLE_DECAP_TABLE_3_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_3_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_SET(x)                                  (((0 | (x)) << OLE_DECAP_TABLE_3_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_3_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_RESET                                   0x1
#define OLE_DECAP_TABLE_3_HALF1_OUI_LSB                                        0
#define OLE_DECAP_TABLE_3_HALF1_OUI_MSB                                        23
#define OLE_DECAP_TABLE_3_HALF1_OUI_MASK                                       0xffffff
#define OLE_DECAP_TABLE_3_HALF1_OUI_GET(x)                                     (((x) & OLE_DECAP_TABLE_3_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_3_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_3_HALF1_OUI_SET(x)                                     (((0 | (x)) << OLE_DECAP_TABLE_3_HALF1_OUI_LSB) & OLE_DECAP_TABLE_3_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_3_HALF1_OUI_RESET                                      0x0
#define OLE_DECAP_TABLE_3_HALF1_ADDRESS                                        (0x54 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_3_HALF1_RSTMASK                                        0x3ffffff
#define OLE_DECAP_TABLE_3_HALF1_RESET                                          0x3000000

// 0x58 (OLE_DECAP_TABLE_3_HALF2)
#define OLE_DECAP_TABLE_3_HALF2_TYPE_LSB                                       0
#define OLE_DECAP_TABLE_3_HALF2_TYPE_MSB                                       15
#define OLE_DECAP_TABLE_3_HALF2_TYPE_MASK                                      0xffff
#define OLE_DECAP_TABLE_3_HALF2_TYPE_GET(x)                                    (((x) & OLE_DECAP_TABLE_3_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_3_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_3_HALF2_TYPE_SET(x)                                    (((0 | (x)) << OLE_DECAP_TABLE_3_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_3_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_3_HALF2_TYPE_RESET                                     0x809b
#define OLE_DECAP_TABLE_3_HALF2_ADDRESS                                        (0x58 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_3_HALF2_RSTMASK                                        0xffff
#define OLE_DECAP_TABLE_3_HALF2_RESET                                          0x809b

// 0x5c (OLE_DECAP_TABLE_4_HALF1)
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_LSB                              25
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_MSB                              25
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_MASK                             0x2000000
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_GET(x)                           (((x) & OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_SET(x)                           (((0 | (x)) << OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_RESET                            0x1
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_LSB                                     24
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_MSB                                     24
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_MASK                                    0x1000000
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_GET(x)                                  (((x) & OLE_DECAP_TABLE_4_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_4_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_SET(x)                                  (((0 | (x)) << OLE_DECAP_TABLE_4_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_4_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_RESET                                   0x1
#define OLE_DECAP_TABLE_4_HALF1_OUI_LSB                                        0
#define OLE_DECAP_TABLE_4_HALF1_OUI_MSB                                        23
#define OLE_DECAP_TABLE_4_HALF1_OUI_MASK                                       0xffffff
#define OLE_DECAP_TABLE_4_HALF1_OUI_GET(x)                                     (((x) & OLE_DECAP_TABLE_4_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_4_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_4_HALF1_OUI_SET(x)                                     (((0 | (x)) << OLE_DECAP_TABLE_4_HALF1_OUI_LSB) & OLE_DECAP_TABLE_4_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_4_HALF1_OUI_RESET                                      0xf8
#define OLE_DECAP_TABLE_4_HALF1_ADDRESS                                        (0x5c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_4_HALF1_RSTMASK                                        0x3ffffff
#define OLE_DECAP_TABLE_4_HALF1_RESET                                          0x30000f8

// 0x60 (OLE_DECAP_TABLE_4_HALF2)
#define OLE_DECAP_TABLE_4_HALF2_TYPE_LSB                                       0
#define OLE_DECAP_TABLE_4_HALF2_TYPE_MSB                                       15
#define OLE_DECAP_TABLE_4_HALF2_TYPE_MASK                                      0xffff
#define OLE_DECAP_TABLE_4_HALF2_TYPE_GET(x)                                    (((x) & OLE_DECAP_TABLE_4_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_4_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_4_HALF2_TYPE_SET(x)                                    (((0 | (x)) << OLE_DECAP_TABLE_4_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_4_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_4_HALF2_TYPE_RESET                                     0x80f3
#define OLE_DECAP_TABLE_4_HALF2_ADDRESS                                        (0x60 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_4_HALF2_RSTMASK                                        0xffff
#define OLE_DECAP_TABLE_4_HALF2_RESET                                          0x80f3

// 0x64 (OLE_DECAP_TABLE_5_HALF1)
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_LSB                              25
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_MSB                              25
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_MASK                             0x2000000
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_GET(x)                           (((x) & OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_SET(x)                           (((0 | (x)) << OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_RESET                            0x1
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_LSB                                     24
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_MSB                                     24
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_MASK                                    0x1000000
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_GET(x)                                  (((x) & OLE_DECAP_TABLE_5_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_5_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_SET(x)                                  (((0 | (x)) << OLE_DECAP_TABLE_5_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_5_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_RESET                                   0x1
#define OLE_DECAP_TABLE_5_HALF1_OUI_LSB                                        0
#define OLE_DECAP_TABLE_5_HALF1_OUI_MSB                                        23
#define OLE_DECAP_TABLE_5_HALF1_OUI_MASK                                       0xffffff
#define OLE_DECAP_TABLE_5_HALF1_OUI_GET(x)                                     (((x) & OLE_DECAP_TABLE_5_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_5_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_5_HALF1_OUI_SET(x)                                     (((0 | (x)) << OLE_DECAP_TABLE_5_HALF1_OUI_LSB) & OLE_DECAP_TABLE_5_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_5_HALF1_OUI_RESET                                      0xf8
#define OLE_DECAP_TABLE_5_HALF1_ADDRESS                                        (0x64 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_5_HALF1_RSTMASK                                        0x3ffffff
#define OLE_DECAP_TABLE_5_HALF1_RESET                                          0x30000f8

// 0x68 (OLE_DECAP_TABLE_5_HALF2)
#define OLE_DECAP_TABLE_5_HALF2_TYPE_LSB                                       0
#define OLE_DECAP_TABLE_5_HALF2_TYPE_MSB                                       15
#define OLE_DECAP_TABLE_5_HALF2_TYPE_MASK                                      0xffff
#define OLE_DECAP_TABLE_5_HALF2_TYPE_GET(x)                                    (((x) & OLE_DECAP_TABLE_5_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_5_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_5_HALF2_TYPE_SET(x)                                    (((0 | (x)) << OLE_DECAP_TABLE_5_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_5_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_5_HALF2_TYPE_RESET                                     0x8137
#define OLE_DECAP_TABLE_5_HALF2_ADDRESS                                        (0x68 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_5_HALF2_RSTMASK                                        0xffff
#define OLE_DECAP_TABLE_5_HALF2_RESET                                          0x8137

// 0x6c (OLE_DECAP_TABLE_6_HALF1)
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_LSB                              25
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_MSB                              25
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_MASK                             0x2000000
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_GET(x)                           (((x) & OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_SET(x)                           (((0 | (x)) << OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_RESET                            0x1
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_LSB                                     24
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_MSB                                     24
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_MASK                                    0x1000000
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_GET(x)                                  (((x) & OLE_DECAP_TABLE_6_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_6_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_SET(x)                                  (((0 | (x)) << OLE_DECAP_TABLE_6_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_6_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_RESET                                   0x0
#define OLE_DECAP_TABLE_6_HALF1_OUI_LSB                                        0
#define OLE_DECAP_TABLE_6_HALF1_OUI_MSB                                        23
#define OLE_DECAP_TABLE_6_HALF1_OUI_MASK                                       0xffffff
#define OLE_DECAP_TABLE_6_HALF1_OUI_GET(x)                                     (((x) & OLE_DECAP_TABLE_6_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_6_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_6_HALF1_OUI_SET(x)                                     (((0 | (x)) << OLE_DECAP_TABLE_6_HALF1_OUI_LSB) & OLE_DECAP_TABLE_6_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_6_HALF1_OUI_RESET                                      0x0
#define OLE_DECAP_TABLE_6_HALF1_ADDRESS                                        (0x6c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_6_HALF1_RSTMASK                                        0x3ffffff
#define OLE_DECAP_TABLE_6_HALF1_RESET                                          0x2000000

// 0x70 (OLE_DECAP_TABLE_6_HALF2)
#define OLE_DECAP_TABLE_6_HALF2_TYPE_LSB                                       0
#define OLE_DECAP_TABLE_6_HALF2_TYPE_MSB                                       15
#define OLE_DECAP_TABLE_6_HALF2_TYPE_MASK                                      0xffff
#define OLE_DECAP_TABLE_6_HALF2_TYPE_GET(x)                                    (((x) & OLE_DECAP_TABLE_6_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_6_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_6_HALF2_TYPE_SET(x)                                    (((0 | (x)) << OLE_DECAP_TABLE_6_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_6_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_6_HALF2_TYPE_RESET                                     0x800
#define OLE_DECAP_TABLE_6_HALF2_ADDRESS                                        (0x70 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_6_HALF2_RSTMASK                                        0xffff
#define OLE_DECAP_TABLE_6_HALF2_RESET                                          0x800

// 0x74 (OLE_DECAP_TABLE_7_HALF1)
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_LSB                              25
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_MSB                              25
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_MASK                             0x2000000
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_GET(x)                           (((x) & OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_SET(x)                           (((0 | (x)) << OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_RESET                            0x1
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_LSB                                     24
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_MSB                                     24
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_MASK                                    0x1000000
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_GET(x)                                  (((x) & OLE_DECAP_TABLE_7_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_7_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_SET(x)                                  (((0 | (x)) << OLE_DECAP_TABLE_7_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_7_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_RESET                                   0x0
#define OLE_DECAP_TABLE_7_HALF1_OUI_LSB                                        0
#define OLE_DECAP_TABLE_7_HALF1_OUI_MSB                                        23
#define OLE_DECAP_TABLE_7_HALF1_OUI_MASK                                       0xffffff
#define OLE_DECAP_TABLE_7_HALF1_OUI_GET(x)                                     (((x) & OLE_DECAP_TABLE_7_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_7_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_7_HALF1_OUI_SET(x)                                     (((0 | (x)) << OLE_DECAP_TABLE_7_HALF1_OUI_LSB) & OLE_DECAP_TABLE_7_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_7_HALF1_OUI_RESET                                      0x0
#define OLE_DECAP_TABLE_7_HALF1_ADDRESS                                        (0x74 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_7_HALF1_RSTMASK                                        0x3ffffff
#define OLE_DECAP_TABLE_7_HALF1_RESET                                          0x2000000

// 0x78 (OLE_DECAP_TABLE_7_HALF2)
#define OLE_DECAP_TABLE_7_HALF2_TYPE_LSB                                       0
#define OLE_DECAP_TABLE_7_HALF2_TYPE_MSB                                       15
#define OLE_DECAP_TABLE_7_HALF2_TYPE_MASK                                      0xffff
#define OLE_DECAP_TABLE_7_HALF2_TYPE_GET(x)                                    (((x) & OLE_DECAP_TABLE_7_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_7_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_7_HALF2_TYPE_SET(x)                                    (((0 | (x)) << OLE_DECAP_TABLE_7_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_7_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_7_HALF2_TYPE_RESET                                     0x800
#define OLE_DECAP_TABLE_7_HALF2_ADDRESS                                        (0x78 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DECAP_TABLE_7_HALF2_RSTMASK                                        0xffff
#define OLE_DECAP_TABLE_7_HALF2_RESET                                          0x800

// 0x7c (OLE_ASE_AST_BASE_ADDR)
#define OLE_ASE_AST_BASE_ADDR_VALUE_LSB                                        0
#define OLE_ASE_AST_BASE_ADDR_VALUE_MSB                                        31
#define OLE_ASE_AST_BASE_ADDR_VALUE_MASK                                       0xffffffff
#define OLE_ASE_AST_BASE_ADDR_VALUE_GET(x)                                     (((x) & OLE_ASE_AST_BASE_ADDR_VALUE_MASK) >> OLE_ASE_AST_BASE_ADDR_VALUE_LSB)
#define OLE_ASE_AST_BASE_ADDR_VALUE_SET(x)                                     (((0 | (x)) << OLE_ASE_AST_BASE_ADDR_VALUE_LSB) & OLE_ASE_AST_BASE_ADDR_VALUE_MASK)
#define OLE_ASE_AST_BASE_ADDR_VALUE_RESET                                      0x0
#define OLE_ASE_AST_BASE_ADDR_ADDRESS                                          (0x7c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_ASE_AST_BASE_ADDR_RSTMASK                                          0xffffffff
#define OLE_ASE_AST_BASE_ADDR_RESET                                            0x0

// 0x80 (OLE_ASE_AST_SIZE)
#define OLE_ASE_AST_SIZE_VALUE_LSB                                             0
#define OLE_ASE_AST_SIZE_VALUE_MSB                                             12
#define OLE_ASE_AST_SIZE_VALUE_MASK                                            0x1fff
#define OLE_ASE_AST_SIZE_VALUE_GET(x)                                          (((x) & OLE_ASE_AST_SIZE_VALUE_MASK) >> OLE_ASE_AST_SIZE_VALUE_LSB)
#define OLE_ASE_AST_SIZE_VALUE_SET(x)                                          (((0 | (x)) << OLE_ASE_AST_SIZE_VALUE_LSB) & OLE_ASE_AST_SIZE_VALUE_MASK)
#define OLE_ASE_AST_SIZE_VALUE_RESET                                           0x0
#define OLE_ASE_AST_SIZE_ADDRESS                                               (0x80 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_ASE_AST_SIZE_RSTMASK                                               0x1fff
#define OLE_ASE_AST_SIZE_RESET                                                 0x0

// 0x84 (OLE_ASE_SEARCH_CTRL)
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_LSB                                 16
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MSB                                 31
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MASK                                0xffff0000
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_GET(x)                              (((x) & OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MASK) >> OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_LSB)
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_SET(x)                              (((0 | (x)) << OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_LSB) & OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MASK)
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_RESET                               0x0
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_LSB                               8
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MSB                               8
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MASK                              0x100
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_GET(x)                            (((x) & OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MASK) >> OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_LSB)
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_SET(x)                            (((0 | (x)) << OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_LSB) & OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MASK)
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_RESET                             0x0
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_LSB                                     0
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_MSB                                     7
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_MASK                                    0xff
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_GET(x)                                  (((x) & OLE_ASE_SEARCH_CTRL_MAX_SEARCH_MASK) >> OLE_ASE_SEARCH_CTRL_MAX_SEARCH_LSB)
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_SET(x)                                  (((0 | (x)) << OLE_ASE_SEARCH_CTRL_MAX_SEARCH_LSB) & OLE_ASE_SEARCH_CTRL_MAX_SEARCH_MASK)
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_RESET                                   0x0
#define OLE_ASE_SEARCH_CTRL_ADDRESS                                            (0x84 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_ASE_SEARCH_CTRL_RSTMASK                                            0xffff01ff
#define OLE_ASE_SEARCH_CTRL_RESET                                              0x0

// 0x88 (OLE_ASE_HASH_CTRL)
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_LSB                                 23
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_MSB                                 23
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_MASK                                0x800000
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_GET(x)                              (((x) & OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_MASK) >> OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_LSB)
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_SET(x)                              (((0 | (x)) << OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_LSB) & OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_MASK)
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_RESET                               0x0
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_LSB                                    22
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_MSB                                    22
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_MASK                                   0x400000
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_GET(x)                                 (((x) & OLE_ASE_HASH_CTRL_CACHE_DISABLE_MASK) >> OLE_ASE_HASH_CTRL_CACHE_DISABLE_LSB)
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_SET(x)                                 (((0 | (x)) << OLE_ASE_HASH_CTRL_CACHE_DISABLE_LSB) & OLE_ASE_HASH_CTRL_CACHE_DISABLE_MASK)
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_RESET                                  0x0
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_LSB                             21
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MSB                             21
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MASK                            0x200000
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_GET(x)                          (((x) & OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MASK) >> OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_LSB)
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_SET(x)                          (((0 | (x)) << OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_LSB) & OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MASK)
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_RESET                           0x0
#define OLE_ASE_HASH_CTRL_HASH_SEL_LSB                                         20
#define OLE_ASE_HASH_CTRL_HASH_SEL_MSB                                         20
#define OLE_ASE_HASH_CTRL_HASH_SEL_MASK                                        0x100000
#define OLE_ASE_HASH_CTRL_HASH_SEL_GET(x)                                      (((x) & OLE_ASE_HASH_CTRL_HASH_SEL_MASK) >> OLE_ASE_HASH_CTRL_HASH_SEL_LSB)
#define OLE_ASE_HASH_CTRL_HASH_SEL_SET(x)                                      (((0 | (x)) << OLE_ASE_HASH_CTRL_HASH_SEL_LSB) & OLE_ASE_HASH_CTRL_HASH_SEL_MASK)
#define OLE_ASE_HASH_CTRL_HASH_SEL_RESET                                       0x1
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_LSB                                 16
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MSB                                 19
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MASK                                0xf0000
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_GET(x)                              (((x) & OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MASK) >> OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_LSB)
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_SET(x)                              (((0 | (x)) << OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_LSB) & OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MASK)
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_RESET                               0x2
#define OLE_ASE_HASH_CTRL_HASH_XOR_LSB                                         0
#define OLE_ASE_HASH_CTRL_HASH_XOR_MSB                                         15
#define OLE_ASE_HASH_CTRL_HASH_XOR_MASK                                        0xffff
#define OLE_ASE_HASH_CTRL_HASH_XOR_GET(x)                                      (((x) & OLE_ASE_HASH_CTRL_HASH_XOR_MASK) >> OLE_ASE_HASH_CTRL_HASH_XOR_LSB)
#define OLE_ASE_HASH_CTRL_HASH_XOR_SET(x)                                      (((0 | (x)) << OLE_ASE_HASH_CTRL_HASH_XOR_LSB) & OLE_ASE_HASH_CTRL_HASH_XOR_MASK)
#define OLE_ASE_HASH_CTRL_HASH_XOR_RESET                                       0xabcd
#define OLE_ASE_HASH_CTRL_ADDRESS                                              (0x88 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_ASE_HASH_CTRL_RSTMASK                                              0xffffff
#define OLE_ASE_HASH_CTRL_RESET                                                0x12abcd

// 0x8c (OLE_CONFIG)
#define OLE_CONFIG_USE_KEYID_ZERO_FOR_AST_LSB                                  6
#define OLE_CONFIG_USE_KEYID_ZERO_FOR_AST_MSB                                  6
#define OLE_CONFIG_USE_KEYID_ZERO_FOR_AST_MASK                                 0x40
#define OLE_CONFIG_USE_KEYID_ZERO_FOR_AST_GET(x)                               (((x) & OLE_CONFIG_USE_KEYID_ZERO_FOR_AST_MASK) >> OLE_CONFIG_USE_KEYID_ZERO_FOR_AST_LSB)
#define OLE_CONFIG_USE_KEYID_ZERO_FOR_AST_SET(x)                               (((0 | (x)) << OLE_CONFIG_USE_KEYID_ZERO_FOR_AST_LSB) & OLE_CONFIG_USE_KEYID_ZERO_FOR_AST_MASK)
#define OLE_CONFIG_USE_KEYID_ZERO_FOR_AST_RESET                                0x0
#define OLE_CONFIG_INDUSTRY_STD_VLAN_LLC_PARSE_EN_LSB                          5
#define OLE_CONFIG_INDUSTRY_STD_VLAN_LLC_PARSE_EN_MSB                          5
#define OLE_CONFIG_INDUSTRY_STD_VLAN_LLC_PARSE_EN_MASK                         0x20
#define OLE_CONFIG_INDUSTRY_STD_VLAN_LLC_PARSE_EN_GET(x)                       (((x) & OLE_CONFIG_INDUSTRY_STD_VLAN_LLC_PARSE_EN_MASK) >> OLE_CONFIG_INDUSTRY_STD_VLAN_LLC_PARSE_EN_LSB)
#define OLE_CONFIG_INDUSTRY_STD_VLAN_LLC_PARSE_EN_SET(x)                       (((0 | (x)) << OLE_CONFIG_INDUSTRY_STD_VLAN_LLC_PARSE_EN_LSB) & OLE_CONFIG_INDUSTRY_STD_VLAN_LLC_PARSE_EN_MASK)
#define OLE_CONFIG_INDUSTRY_STD_VLAN_LLC_PARSE_EN_RESET                        0x0
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_LSB                                     4
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_MSB                                     4
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_MASK                                    0x10
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_GET(x)                                  (((x) & OLE_CONFIG_USE_BSSID_FOR_AMSDU_MASK) >> OLE_CONFIG_USE_BSSID_FOR_AMSDU_LSB)
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_SET(x)                                  (((0 | (x)) << OLE_CONFIG_USE_BSSID_FOR_AMSDU_LSB) & OLE_CONFIG_USE_BSSID_FOR_AMSDU_MASK)
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_RESET                                   0x1
#define OLE_CONFIG_TX_ABORT_LSB                                                3
#define OLE_CONFIG_TX_ABORT_MSB                                                3
#define OLE_CONFIG_TX_ABORT_MASK                                               0x8
#define OLE_CONFIG_TX_ABORT_GET(x)                                             (((x) & OLE_CONFIG_TX_ABORT_MASK) >> OLE_CONFIG_TX_ABORT_LSB)
#define OLE_CONFIG_TX_ABORT_SET(x)                                             (((0 | (x)) << OLE_CONFIG_TX_ABORT_LSB) & OLE_CONFIG_TX_ABORT_MASK)
#define OLE_CONFIG_TX_ABORT_RESET                                              0x0
#define OLE_CONFIG_RX_RESET_LSB                                                2
#define OLE_CONFIG_RX_RESET_MSB                                                2
#define OLE_CONFIG_RX_RESET_MASK                                               0x4
#define OLE_CONFIG_RX_RESET_GET(x)                                             (((x) & OLE_CONFIG_RX_RESET_MASK) >> OLE_CONFIG_RX_RESET_LSB)
#define OLE_CONFIG_RX_RESET_SET(x)                                             (((0 | (x)) << OLE_CONFIG_RX_RESET_LSB) & OLE_CONFIG_RX_RESET_MASK)
#define OLE_CONFIG_RX_RESET_RESET                                              0x0
#define OLE_CONFIG_TX_RESET_LSB                                                1
#define OLE_CONFIG_TX_RESET_MSB                                                1
#define OLE_CONFIG_TX_RESET_MASK                                               0x2
#define OLE_CONFIG_TX_RESET_GET(x)                                             (((x) & OLE_CONFIG_TX_RESET_MASK) >> OLE_CONFIG_TX_RESET_LSB)
#define OLE_CONFIG_TX_RESET_SET(x)                                             (((0 | (x)) << OLE_CONFIG_TX_RESET_LSB) & OLE_CONFIG_TX_RESET_MASK)
#define OLE_CONFIG_TX_RESET_RESET                                              0x0
#define OLE_CONFIG_RESET_LSB                                                   0
#define OLE_CONFIG_RESET_MSB                                                   0
#define OLE_CONFIG_RESET_MASK                                                  0x1
#define OLE_CONFIG_RESET_GET(x)                                                (((x) & OLE_CONFIG_RESET_MASK) >> OLE_CONFIG_RESET_LSB)
#define OLE_CONFIG_RESET_SET(x)                                                (((0 | (x)) << OLE_CONFIG_RESET_LSB) & OLE_CONFIG_RESET_MASK)
#define OLE_CONFIG_RESET_RESET                                                 0x0
#define OLE_CONFIG_ADDRESS                                                     (0x8c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_CONFIG_RSTMASK                                                     0x7f
#define OLE_CONFIG_RESET                                                       0x10

// 0x90 (OLE_PN_SHIFT_FACTOR)
#define OLE_PN_SHIFT_FACTOR_USER2_LSB                                          8
#define OLE_PN_SHIFT_FACTOR_USER2_MSB                                          11
#define OLE_PN_SHIFT_FACTOR_USER2_MASK                                         0xf00
#define OLE_PN_SHIFT_FACTOR_USER2_GET(x)                                       (((x) & OLE_PN_SHIFT_FACTOR_USER2_MASK) >> OLE_PN_SHIFT_FACTOR_USER2_LSB)
#define OLE_PN_SHIFT_FACTOR_USER2_SET(x)                                       (((0 | (x)) << OLE_PN_SHIFT_FACTOR_USER2_LSB) & OLE_PN_SHIFT_FACTOR_USER2_MASK)
#define OLE_PN_SHIFT_FACTOR_USER2_RESET                                        0x3
#define OLE_PN_SHIFT_FACTOR_USER1_LSB                                          4
#define OLE_PN_SHIFT_FACTOR_USER1_MSB                                          7
#define OLE_PN_SHIFT_FACTOR_USER1_MASK                                         0xf0
#define OLE_PN_SHIFT_FACTOR_USER1_GET(x)                                       (((x) & OLE_PN_SHIFT_FACTOR_USER1_MASK) >> OLE_PN_SHIFT_FACTOR_USER1_LSB)
#define OLE_PN_SHIFT_FACTOR_USER1_SET(x)                                       (((0 | (x)) << OLE_PN_SHIFT_FACTOR_USER1_LSB) & OLE_PN_SHIFT_FACTOR_USER1_MASK)
#define OLE_PN_SHIFT_FACTOR_USER1_RESET                                        0x3
#define OLE_PN_SHIFT_FACTOR_USER0_LSB                                          0
#define OLE_PN_SHIFT_FACTOR_USER0_MSB                                          3
#define OLE_PN_SHIFT_FACTOR_USER0_MASK                                         0xf
#define OLE_PN_SHIFT_FACTOR_USER0_GET(x)                                       (((x) & OLE_PN_SHIFT_FACTOR_USER0_MASK) >> OLE_PN_SHIFT_FACTOR_USER0_LSB)
#define OLE_PN_SHIFT_FACTOR_USER0_SET(x)                                       (((0 | (x)) << OLE_PN_SHIFT_FACTOR_USER0_LSB) & OLE_PN_SHIFT_FACTOR_USER0_MASK)
#define OLE_PN_SHIFT_FACTOR_USER0_RESET                                        0x3
#define OLE_PN_SHIFT_FACTOR_ADDRESS                                            (0x90 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_PN_SHIFT_FACTOR_RSTMASK                                            0xfff
#define OLE_PN_SHIFT_FACTOR_RESET                                              0x333

// 0x94 (OLE_RX_CLASSIFY_ETHERNET_0)
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_LSB                                  16
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_MSB                                  16
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_MASK                                 0x10000
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_GET(x)                               (((x) & OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_SET(x)                               (((0 | (x)) << OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_LSB) & OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_RESET                                0x0
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_LSB                                    0
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_MSB                                    15
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_MASK                                   0xffff
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_GET(x)                                 (((x) & OLE_RX_CLASSIFY_ETHERNET_0_TYPE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_0_TYPE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_SET(x)                                 (((0 | (x)) << OLE_RX_CLASSIFY_ETHERNET_0_TYPE_LSB) & OLE_RX_CLASSIFY_ETHERNET_0_TYPE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_RESET                                  0x888e
#define OLE_RX_CLASSIFY_ETHERNET_0_ADDRESS                                     (0x94 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_CLASSIFY_ETHERNET_0_RSTMASK                                     0x1ffff
#define OLE_RX_CLASSIFY_ETHERNET_0_RESET                                       0x888e

// 0x98 (OLE_RX_CLASSIFY_ETHERNET_1)
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_LSB                                  16
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_MSB                                  16
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_MASK                                 0x10000
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_GET(x)                               (((x) & OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_SET(x)                               (((0 | (x)) << OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_LSB) & OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_RESET                                0x0
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_LSB                                    0
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_MSB                                    15
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_MASK                                   0xffff
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_GET(x)                                 (((x) & OLE_RX_CLASSIFY_ETHERNET_1_TYPE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_1_TYPE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_SET(x)                                 (((0 | (x)) << OLE_RX_CLASSIFY_ETHERNET_1_TYPE_LSB) & OLE_RX_CLASSIFY_ETHERNET_1_TYPE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_RESET                                  0x888e
#define OLE_RX_CLASSIFY_ETHERNET_1_ADDRESS                                     (0x98 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_CLASSIFY_ETHERNET_1_RSTMASK                                     0x1ffff
#define OLE_RX_CLASSIFY_ETHERNET_1_RESET                                       0x888e

// 0x9c (OLE_RX_CLASSIFY_ETHERNET_2)
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_LSB                                  16
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_MSB                                  16
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_MASK                                 0x10000
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_GET(x)                               (((x) & OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_SET(x)                               (((0 | (x)) << OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_LSB) & OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_RESET                                0x0
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_LSB                                    0
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_MSB                                    15
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_MASK                                   0xffff
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_GET(x)                                 (((x) & OLE_RX_CLASSIFY_ETHERNET_2_TYPE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_2_TYPE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_SET(x)                                 (((0 | (x)) << OLE_RX_CLASSIFY_ETHERNET_2_TYPE_LSB) & OLE_RX_CLASSIFY_ETHERNET_2_TYPE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_RESET                                  0x888e
#define OLE_RX_CLASSIFY_ETHERNET_2_ADDRESS                                     (0x9c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_CLASSIFY_ETHERNET_2_RSTMASK                                     0x1ffff
#define OLE_RX_CLASSIFY_ETHERNET_2_RESET                                       0x888e

// 0xa0 (OLE_RX_CLASSIFY_ETHERNET_3)
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_LSB                                  16
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_MSB                                  16
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_MASK                                 0x10000
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_GET(x)                               (((x) & OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_SET(x)                               (((0 | (x)) << OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_LSB) & OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_RESET                                0x0
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_LSB                                    0
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_MSB                                    15
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_MASK                                   0xffff
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_GET(x)                                 (((x) & OLE_RX_CLASSIFY_ETHERNET_3_TYPE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_3_TYPE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_SET(x)                                 (((0 | (x)) << OLE_RX_CLASSIFY_ETHERNET_3_TYPE_LSB) & OLE_RX_CLASSIFY_ETHERNET_3_TYPE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_RESET                                  0x888e
#define OLE_RX_CLASSIFY_ETHERNET_3_ADDRESS                                     (0xa0 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_CLASSIFY_ETHERNET_3_RSTMASK                                     0x1ffff
#define OLE_RX_CLASSIFY_ETHERNET_3_RESET                                       0x888e

// 0xc0 (OLE_RX_L3_IPV6_EXTN_HDR_0)
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_LEN_LSB                                  8
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_LEN_MSB                                  19
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_LEN_MASK                                 0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_LEN_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_LEN_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_LEN_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_ID_LSB                                   0
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_ID_MSB                                   7
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_ID_MASK                                  0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_ID_GET(x)                                (((x) & OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_ID_SET(x)                                (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_0_HDR_ID_RESET                                 0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_0_ADDRESS                                      (0xc0 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_0_RSTMASK                                      0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_0_RESET                                        0x0

// 0xc4 (OLE_RX_L3_IPV6_EXTN_HDR_1)
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_LEN_LSB                                  8
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_LEN_MSB                                  19
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_LEN_MASK                                 0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_LEN_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_LEN_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_LEN_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_ID_LSB                                   0
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_ID_MSB                                   7
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_ID_MASK                                  0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_ID_GET(x)                                (((x) & OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_ID_SET(x)                                (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_1_HDR_ID_RESET                                 0x2b
#define OLE_RX_L3_IPV6_EXTN_HDR_1_ADDRESS                                      (0xc4 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_1_RSTMASK                                      0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_1_RESET                                        0x2b

// 0xc8 (OLE_RX_L3_IPV6_EXTN_HDR_2)
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_LEN_LSB                                  8
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_LEN_MSB                                  19
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_LEN_MASK                                 0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_LEN_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_LEN_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_LEN_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_ID_LSB                                   0
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_ID_MSB                                   7
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_ID_MASK                                  0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_ID_GET(x)                                (((x) & OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_ID_SET(x)                                (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_2_HDR_ID_RESET                                 0x3c
#define OLE_RX_L3_IPV6_EXTN_HDR_2_ADDRESS                                      (0xc8 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_2_RSTMASK                                      0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_2_RESET                                        0x3c

// 0xcc (OLE_RX_L3_IPV6_EXTN_HDR_3)
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_LEN_LSB                                  8
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_LEN_MSB                                  19
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_LEN_MASK                                 0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_LEN_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_LEN_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_LEN_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_ID_LSB                                   0
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_ID_MSB                                   7
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_ID_MASK                                  0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_ID_GET(x)                                (((x) & OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_ID_SET(x)                                (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_3_HDR_ID_RESET                                 0x33
#define OLE_RX_L3_IPV6_EXTN_HDR_3_ADDRESS                                      (0xcc + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_3_RSTMASK                                      0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_3_RESET                                        0x33

// 0xd0 (OLE_RX_L3_IPV6_EXTN_HDR_4)
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_LEN_LSB                                  8
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_LEN_MSB                                  19
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_LEN_MASK                                 0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_LEN_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_LEN_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_LEN_RESET                                0x8
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_ID_LSB                                   0
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_ID_MSB                                   7
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_ID_MASK                                  0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_ID_GET(x)                                (((x) & OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_ID_SET(x)                                (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_4_HDR_ID_RESET                                 0x87
#define OLE_RX_L3_IPV6_EXTN_HDR_4_ADDRESS                                      (0xd0 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_4_RSTMASK                                      0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_4_RESET                                        0x887

// 0xd4 (OLE_RX_L3_IPV6_EXTN_HDR_5)
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_LEN_LSB                                  8
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_LEN_MSB                                  19
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_LEN_MASK                                 0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_LEN_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_LEN_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_LEN_RESET                                0x8
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_ID_LSB                                   0
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_ID_MSB                                   7
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_ID_MASK                                  0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_ID_GET(x)                                (((x) & OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_ID_SET(x)                                (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_5_HDR_ID_RESET                                 0x2c
#define OLE_RX_L3_IPV6_EXTN_HDR_5_ADDRESS                                      (0xd4 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_5_RSTMASK                                      0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_5_RESET                                        0x82c

// 0xd8 (OLE_RX_L3_IPV6_EXTN_HDR_6)
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_LEN_LSB                                  8
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_LEN_MSB                                  19
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_LEN_MASK                                 0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_LEN_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_LEN_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_LEN_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_ID_LSB                                   0
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_ID_MSB                                   7
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_ID_MASK                                  0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_ID_GET(x)                                (((x) & OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_ID_SET(x)                                (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_6_HDR_ID_RESET                                 0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_6_ADDRESS                                      (0xd8 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_6_RSTMASK                                      0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_6_RESET                                        0x0

// 0xdc (OLE_RX_L3_IPV6_EXTN_HDR_7)
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_LEN_LSB                                  8
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_LEN_MSB                                  19
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_LEN_MASK                                 0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_LEN_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_LEN_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_LEN_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_ID_LSB                                   0
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_ID_MSB                                   7
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_ID_MASK                                  0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_ID_GET(x)                                (((x) & OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_ID_SET(x)                                (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_7_HDR_ID_RESET                                 0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_7_ADDRESS                                      (0xdc + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_7_RSTMASK                                      0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_7_RESET                                        0x0

// 0xe0 (OLE_RX_L3_IPV6_EXTN_HDR_8)
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_LEN_LSB                                  8
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_LEN_MSB                                  19
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_LEN_MASK                                 0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_LEN_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_LEN_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_LEN_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_ID_LSB                                   0
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_ID_MSB                                   7
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_ID_MASK                                  0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_ID_GET(x)                                (((x) & OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_ID_SET(x)                                (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_8_HDR_ID_RESET                                 0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_8_ADDRESS                                      (0xe0 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_8_RSTMASK                                      0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_8_RESET                                        0x0

// 0xe4 (OLE_RX_L3_IPV6_EXTN_HDR_9)
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_LEN_LSB                                  8
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_LEN_MSB                                  19
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_LEN_MASK                                 0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_LEN_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_LEN_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_LEN_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_ID_LSB                                   0
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_ID_MSB                                   7
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_ID_MASK                                  0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_ID_GET(x)                                (((x) & OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_ID_SET(x)                                (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_9_HDR_ID_RESET                                 0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_9_ADDRESS                                      (0xe4 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_9_RSTMASK                                      0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_9_RESET                                        0x0

// 0xe8 (OLE_RX_L3_IPV6_EXTN_HDR_10)
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_LEN_LSB                                 8
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_LEN_MSB                                 19
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_LEN_MASK                                0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_LEN_GET(x)                              (((x) & OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_LEN_SET(x)                              (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_LEN_RESET                               0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_ID_LSB                                  0
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_ID_MSB                                  7
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_ID_MASK                                 0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_ID_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_ID_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_10_HDR_ID_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_10_ADDRESS                                     (0xe8 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_10_RSTMASK                                     0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_10_RESET                                       0x0

// 0xec (OLE_RX_L3_IPV6_EXTN_HDR_11)
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_LEN_LSB                                 8
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_LEN_MSB                                 19
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_LEN_MASK                                0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_LEN_GET(x)                              (((x) & OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_LEN_SET(x)                              (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_LEN_RESET                               0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_ID_LSB                                  0
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_ID_MSB                                  7
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_ID_MASK                                 0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_ID_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_ID_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_11_HDR_ID_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_11_ADDRESS                                     (0xec + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_11_RSTMASK                                     0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_11_RESET                                       0x0

// 0xf0 (OLE_RX_L3_IPV6_EXTN_HDR_12)
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_LEN_LSB                                 8
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_LEN_MSB                                 19
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_LEN_MASK                                0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_LEN_GET(x)                              (((x) & OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_LEN_SET(x)                              (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_LEN_RESET                               0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_ID_LSB                                  0
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_ID_MSB                                  7
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_ID_MASK                                 0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_ID_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_ID_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_12_HDR_ID_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_12_ADDRESS                                     (0xf0 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_12_RSTMASK                                     0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_12_RESET                                       0x0

// 0xf4 (OLE_RX_L3_IPV6_EXTN_HDR_13)
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_LEN_LSB                                 8
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_LEN_MSB                                 19
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_LEN_MASK                                0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_LEN_GET(x)                              (((x) & OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_LEN_SET(x)                              (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_LEN_RESET                               0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_ID_LSB                                  0
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_ID_MSB                                  7
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_ID_MASK                                 0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_ID_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_ID_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_13_HDR_ID_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_13_ADDRESS                                     (0xf4 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_13_RSTMASK                                     0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_13_RESET                                       0x0

// 0xf8 (OLE_RX_L3_IPV6_EXTN_HDR_14)
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_LEN_LSB                                 8
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_LEN_MSB                                 19
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_LEN_MASK                                0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_LEN_GET(x)                              (((x) & OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_LEN_SET(x)                              (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_LEN_RESET                               0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_ID_LSB                                  0
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_ID_MSB                                  7
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_ID_MASK                                 0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_ID_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_ID_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_14_HDR_ID_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_14_ADDRESS                                     (0xf8 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_14_RSTMASK                                     0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_14_RESET                                       0x0

// 0xfc (OLE_RX_L3_IPV6_EXTN_HDR_15)
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_LEN_LSB                                 8
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_LEN_MSB                                 19
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_LEN_MASK                                0xfff00
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_LEN_GET(x)                              (((x) & OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_LEN_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_LEN_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_LEN_SET(x)                              (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_LEN_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_LEN_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_LEN_RESET                               0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_ID_LSB                                  0
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_ID_MSB                                  7
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_ID_MASK                                 0xff
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_ID_GET(x)                               (((x) & OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_ID_MASK) >> OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_ID_LSB)
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_ID_SET(x)                               (((0 | (x)) << OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_ID_LSB) & OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_ID_MASK)
#define OLE_RX_L3_IPV6_EXTN_HDR_15_HDR_ID_RESET                                0x0
#define OLE_RX_L3_IPV6_EXTN_HDR_15_ADDRESS                                     (0xfc + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_L3_IPV6_EXTN_HDR_15_RSTMASK                                     0xfffff
#define OLE_RX_L3_IPV6_EXTN_HDR_15_RESET                                       0x0

// 0x100 (OLE_BUF_STAT)
#define OLE_BUF_STAT_CMD_FIFO_THRESHOLD_LSB                                    9
#define OLE_BUF_STAT_CMD_FIFO_THRESHOLD_MSB                                    13
#define OLE_BUF_STAT_CMD_FIFO_THRESHOLD_MASK                                   0x3e00
#define OLE_BUF_STAT_CMD_FIFO_THRESHOLD_GET(x)                                 (((x) & OLE_BUF_STAT_CMD_FIFO_THRESHOLD_MASK) >> OLE_BUF_STAT_CMD_FIFO_THRESHOLD_LSB)
#define OLE_BUF_STAT_CMD_FIFO_THRESHOLD_SET(x)                                 (((0 | (x)) << OLE_BUF_STAT_CMD_FIFO_THRESHOLD_LSB) & OLE_BUF_STAT_CMD_FIFO_THRESHOLD_MASK)
#define OLE_BUF_STAT_CMD_FIFO_THRESHOLD_RESET                                  0x8
#define OLE_BUF_STAT_DATA_FIFO_THRESHOLD_LSB                                   0
#define OLE_BUF_STAT_DATA_FIFO_THRESHOLD_MSB                                   8
#define OLE_BUF_STAT_DATA_FIFO_THRESHOLD_MASK                                  0x1ff
#define OLE_BUF_STAT_DATA_FIFO_THRESHOLD_GET(x)                                (((x) & OLE_BUF_STAT_DATA_FIFO_THRESHOLD_MASK) >> OLE_BUF_STAT_DATA_FIFO_THRESHOLD_LSB)
#define OLE_BUF_STAT_DATA_FIFO_THRESHOLD_SET(x)                                (((0 | (x)) << OLE_BUF_STAT_DATA_FIFO_THRESHOLD_LSB) & OLE_BUF_STAT_DATA_FIFO_THRESHOLD_MASK)
#define OLE_BUF_STAT_DATA_FIFO_THRESHOLD_RESET                                 0x20
#define OLE_BUF_STAT_ADDRESS                                                   (0x100 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_BUF_STAT_RSTMASK                                                   0x3fff
#define OLE_BUF_STAT_RESET                                                     0x1020

// 0x104 (OLE_RX_AMSDU_LIMIT)
#define OLE_RX_AMSDU_LIMIT_COUNT_THRESHOLD_LSB                                 1
#define OLE_RX_AMSDU_LIMIT_COUNT_THRESHOLD_MSB                                 12
#define OLE_RX_AMSDU_LIMIT_COUNT_THRESHOLD_MASK                                0x1ffe
#define OLE_RX_AMSDU_LIMIT_COUNT_THRESHOLD_GET(x)                              (((x) & OLE_RX_AMSDU_LIMIT_COUNT_THRESHOLD_MASK) >> OLE_RX_AMSDU_LIMIT_COUNT_THRESHOLD_LSB)
#define OLE_RX_AMSDU_LIMIT_COUNT_THRESHOLD_SET(x)                              (((0 | (x)) << OLE_RX_AMSDU_LIMIT_COUNT_THRESHOLD_LSB) & OLE_RX_AMSDU_LIMIT_COUNT_THRESHOLD_MASK)
#define OLE_RX_AMSDU_LIMIT_COUNT_THRESHOLD_RESET                               0x30
#define OLE_RX_AMSDU_LIMIT_COUNT_ENABLE_LSB                                    0
#define OLE_RX_AMSDU_LIMIT_COUNT_ENABLE_MSB                                    0
#define OLE_RX_AMSDU_LIMIT_COUNT_ENABLE_MASK                                   0x1
#define OLE_RX_AMSDU_LIMIT_COUNT_ENABLE_GET(x)                                 (((x) & OLE_RX_AMSDU_LIMIT_COUNT_ENABLE_MASK) >> OLE_RX_AMSDU_LIMIT_COUNT_ENABLE_LSB)
#define OLE_RX_AMSDU_LIMIT_COUNT_ENABLE_SET(x)                                 (((0 | (x)) << OLE_RX_AMSDU_LIMIT_COUNT_ENABLE_LSB) & OLE_RX_AMSDU_LIMIT_COUNT_ENABLE_MASK)
#define OLE_RX_AMSDU_LIMIT_COUNT_ENABLE_RESET                                  0x0
#define OLE_RX_AMSDU_LIMIT_ADDRESS                                             (0x104 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_AMSDU_LIMIT_RSTMASK                                             0x1fff
#define OLE_RX_AMSDU_LIMIT_RESET                                               0x60

// 0x10c (OLE_LRO)
#define OLE_LRO_TCP_FLAG_MASK_LSB                                              13
#define OLE_LRO_TCP_FLAG_MASK_MSB                                              21
#define OLE_LRO_TCP_FLAG_MASK_MASK                                             0x3fe000
#define OLE_LRO_TCP_FLAG_MASK_GET(x)                                           (((x) & OLE_LRO_TCP_FLAG_MASK_MASK) >> OLE_LRO_TCP_FLAG_MASK_LSB)
#define OLE_LRO_TCP_FLAG_MASK_SET(x)                                           (((0 | (x)) << OLE_LRO_TCP_FLAG_MASK_LSB) & OLE_LRO_TCP_FLAG_MASK_MASK)
#define OLE_LRO_TCP_FLAG_MASK_RESET                                            0x0
#define OLE_LRO_TCP_FLAG_LSB                                                   4
#define OLE_LRO_TCP_FLAG_MSB                                                   12
#define OLE_LRO_TCP_FLAG_MASK                                                  0x1ff0
#define OLE_LRO_TCP_FLAG_GET(x)                                                (((x) & OLE_LRO_TCP_FLAG_MASK) >> OLE_LRO_TCP_FLAG_LSB)
#define OLE_LRO_TCP_FLAG_SET(x)                                                (((0 | (x)) << OLE_LRO_TCP_FLAG_LSB) & OLE_LRO_TCP_FLAG_MASK)
#define OLE_LRO_TCP_FLAG_RESET                                                 0x0
#define OLE_LRO_PAYLOAD_CHECKSUM_ON_LRO_LSB                                    1
#define OLE_LRO_PAYLOAD_CHECKSUM_ON_LRO_MSB                                    1
#define OLE_LRO_PAYLOAD_CHECKSUM_ON_LRO_MASK                                   0x2
#define OLE_LRO_PAYLOAD_CHECKSUM_ON_LRO_GET(x)                                 (((x) & OLE_LRO_PAYLOAD_CHECKSUM_ON_LRO_MASK) >> OLE_LRO_PAYLOAD_CHECKSUM_ON_LRO_LSB)
#define OLE_LRO_PAYLOAD_CHECKSUM_ON_LRO_SET(x)                                 (((0 | (x)) << OLE_LRO_PAYLOAD_CHECKSUM_ON_LRO_LSB) & OLE_LRO_PAYLOAD_CHECKSUM_ON_LRO_MASK)
#define OLE_LRO_PAYLOAD_CHECKSUM_ON_LRO_RESET                                  0x1
#define OLE_LRO_ENABLE_LSB                                                     0
#define OLE_LRO_ENABLE_MSB                                                     0
#define OLE_LRO_ENABLE_MASK                                                    0x1
#define OLE_LRO_ENABLE_GET(x)                                                  (((x) & OLE_LRO_ENABLE_MASK) >> OLE_LRO_ENABLE_LSB)
#define OLE_LRO_ENABLE_SET(x)                                                  (((0 | (x)) << OLE_LRO_ENABLE_LSB) & OLE_LRO_ENABLE_MASK)
#define OLE_LRO_ENABLE_RESET                                                   0x0
#define OLE_LRO_ADDRESS                                                        (0x10c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_LRO_RSTMASK                                                        0x3ffff3
#define OLE_LRO_RESET                                                          0x2

// 0x110 (OLE_IPV6_CRC_OPTIONS_EN)
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS1_LSB                                   4
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS1_MSB                                   7
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS1_MASK                                  0xf0
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS1_GET(x)                                (((x) & OLE_IPV6_CRC_OPTIONS_EN_HEADERS1_MASK) >> OLE_IPV6_CRC_OPTIONS_EN_HEADERS1_LSB)
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS1_SET(x)                                (((0 | (x)) << OLE_IPV6_CRC_OPTIONS_EN_HEADERS1_LSB) & OLE_IPV6_CRC_OPTIONS_EN_HEADERS1_MASK)
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS1_RESET                                 0x0
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS0_LSB                                   0
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS0_MSB                                   3
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS0_MASK                                  0xf
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS0_GET(x)                                (((x) & OLE_IPV6_CRC_OPTIONS_EN_HEADERS0_MASK) >> OLE_IPV6_CRC_OPTIONS_EN_HEADERS0_LSB)
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS0_SET(x)                                (((0 | (x)) << OLE_IPV6_CRC_OPTIONS_EN_HEADERS0_LSB) & OLE_IPV6_CRC_OPTIONS_EN_HEADERS0_MASK)
#define OLE_IPV6_CRC_OPTIONS_EN_HEADERS0_RESET                                 0x0
#define OLE_IPV6_CRC_OPTIONS_EN_ADDRESS                                        (0x110 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_IPV6_CRC_OPTIONS_EN_RSTMASK                                        0xff
#define OLE_IPV6_CRC_OPTIONS_EN_RESET                                          0x0

// 0x114 (OLE_IPV6_CRC_OPTIONS_HEADERS0)
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL3_LSB                                 24
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL3_MSB                                 31
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL3_MASK                                0xff000000
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL3_GET(x)                              (((x) & OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL3_MASK) >> OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL3_LSB)
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL3_SET(x)                              (((0 | (x)) << OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL3_LSB) & OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL3_MASK)
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL3_RESET                               0x0
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL2_LSB                                 16
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL2_MSB                                 23
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL2_MASK                                0xff0000
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL2_GET(x)                              (((x) & OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL2_MASK) >> OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL2_LSB)
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL2_SET(x)                              (((0 | (x)) << OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL2_LSB) & OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL2_MASK)
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL2_RESET                               0x0
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL1_LSB                                 8
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL1_MSB                                 15
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL1_MASK                                0xff00
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL1_GET(x)                              (((x) & OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL1_MASK) >> OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL1_LSB)
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL1_SET(x)                              (((0 | (x)) << OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL1_LSB) & OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL1_MASK)
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL1_RESET                               0x0
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL0_LSB                                 0
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL0_MSB                                 7
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL0_MASK                                0xff
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL0_GET(x)                              (((x) & OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL0_MASK) >> OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL0_LSB)
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL0_SET(x)                              (((0 | (x)) << OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL0_LSB) & OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL0_MASK)
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_SEL0_RESET                               0x0
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_ADDRESS                                  (0x114 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_RSTMASK                                  0xffffffff
#define OLE_IPV6_CRC_OPTIONS_HEADERS0_RESET                                    0x0

// 0x118 (OLE_IPV6_CRC_OPTIONS_HEADERS1)
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL7_LSB                                 24
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL7_MSB                                 31
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL7_MASK                                0xff000000
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL7_GET(x)                              (((x) & OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL7_MASK) >> OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL7_LSB)
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL7_SET(x)                              (((0 | (x)) << OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL7_LSB) & OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL7_MASK)
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL7_RESET                               0x0
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL6_LSB                                 16
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL6_MSB                                 23
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL6_MASK                                0xff0000
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL6_GET(x)                              (((x) & OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL6_MASK) >> OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL6_LSB)
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL6_SET(x)                              (((0 | (x)) << OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL6_LSB) & OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL6_MASK)
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL6_RESET                               0x0
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL5_LSB                                 8
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL5_MSB                                 15
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL5_MASK                                0xff00
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL5_GET(x)                              (((x) & OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL5_MASK) >> OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL5_LSB)
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL5_SET(x)                              (((0 | (x)) << OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL5_LSB) & OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL5_MASK)
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL5_RESET                               0x0
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL4_LSB                                 0
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL4_MSB                                 7
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL4_MASK                                0xff
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL4_GET(x)                              (((x) & OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL4_MASK) >> OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL4_LSB)
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL4_SET(x)                              (((0 | (x)) << OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL4_LSB) & OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL4_MASK)
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_SEL4_RESET                               0x0
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_ADDRESS                                  (0x118 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_RSTMASK                                  0xffffffff
#define OLE_IPV6_CRC_OPTIONS_HEADERS1_RESET                                    0x0

// 0x11c (OLE_TX_WATCHDOG)
#define OLE_TX_WATCHDOG_STATUS_LSB                                             16
#define OLE_TX_WATCHDOG_STATUS_MSB                                             31
#define OLE_TX_WATCHDOG_STATUS_MASK                                            0xffff0000
#define OLE_TX_WATCHDOG_STATUS_GET(x)                                          (((x) & OLE_TX_WATCHDOG_STATUS_MASK) >> OLE_TX_WATCHDOG_STATUS_LSB)
#define OLE_TX_WATCHDOG_STATUS_SET(x)                                          (((0 | (x)) << OLE_TX_WATCHDOG_STATUS_LSB) & OLE_TX_WATCHDOG_STATUS_MASK)
#define OLE_TX_WATCHDOG_STATUS_RESET                                           0x0
#define OLE_TX_WATCHDOG_LIMIT_LSB                                              0
#define OLE_TX_WATCHDOG_LIMIT_MSB                                              15
#define OLE_TX_WATCHDOG_LIMIT_MASK                                             0xffff
#define OLE_TX_WATCHDOG_LIMIT_GET(x)                                           (((x) & OLE_TX_WATCHDOG_LIMIT_MASK) >> OLE_TX_WATCHDOG_LIMIT_LSB)
#define OLE_TX_WATCHDOG_LIMIT_SET(x)                                           (((0 | (x)) << OLE_TX_WATCHDOG_LIMIT_LSB) & OLE_TX_WATCHDOG_LIMIT_MASK)
#define OLE_TX_WATCHDOG_LIMIT_RESET                                            0xffff
#define OLE_TX_WATCHDOG_ADDRESS                                                (0x11c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_TX_WATCHDOG_RSTMASK                                                0xffffffff
#define OLE_TX_WATCHDOG_RESET                                                  0xffff

// 0x120 (OLE_RX_WATCHDOG)
#define OLE_RX_WATCHDOG_STATUS_LSB                                             16
#define OLE_RX_WATCHDOG_STATUS_MSB                                             31
#define OLE_RX_WATCHDOG_STATUS_MASK                                            0xffff0000
#define OLE_RX_WATCHDOG_STATUS_GET(x)                                          (((x) & OLE_RX_WATCHDOG_STATUS_MASK) >> OLE_RX_WATCHDOG_STATUS_LSB)
#define OLE_RX_WATCHDOG_STATUS_SET(x)                                          (((0 | (x)) << OLE_RX_WATCHDOG_STATUS_LSB) & OLE_RX_WATCHDOG_STATUS_MASK)
#define OLE_RX_WATCHDOG_STATUS_RESET                                           0x0
#define OLE_RX_WATCHDOG_LIMIT_LSB                                              0
#define OLE_RX_WATCHDOG_LIMIT_MSB                                              15
#define OLE_RX_WATCHDOG_LIMIT_MASK                                             0xffff
#define OLE_RX_WATCHDOG_LIMIT_GET(x)                                           (((x) & OLE_RX_WATCHDOG_LIMIT_MASK) >> OLE_RX_WATCHDOG_LIMIT_LSB)
#define OLE_RX_WATCHDOG_LIMIT_SET(x)                                           (((0 | (x)) << OLE_RX_WATCHDOG_LIMIT_LSB) & OLE_RX_WATCHDOG_LIMIT_MASK)
#define OLE_RX_WATCHDOG_LIMIT_RESET                                            0xffff
#define OLE_RX_WATCHDOG_ADDRESS                                                (0x120 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_RX_WATCHDOG_RSTMASK                                                0xffffffff
#define OLE_RX_WATCHDOG_RESET                                                  0xffff

// 0x124 (OLE_WATCHDOG_INTR_STATUS)
#define OLE_WATCHDOG_INTR_STATUS_RX_LSB                                        1
#define OLE_WATCHDOG_INTR_STATUS_RX_MSB                                        1
#define OLE_WATCHDOG_INTR_STATUS_RX_MASK                                       0x2
#define OLE_WATCHDOG_INTR_STATUS_RX_GET(x)                                     (((x) & OLE_WATCHDOG_INTR_STATUS_RX_MASK) >> OLE_WATCHDOG_INTR_STATUS_RX_LSB)
#define OLE_WATCHDOG_INTR_STATUS_RX_SET(x)                                     (((0 | (x)) << OLE_WATCHDOG_INTR_STATUS_RX_LSB) & OLE_WATCHDOG_INTR_STATUS_RX_MASK)
#define OLE_WATCHDOG_INTR_STATUS_RX_RESET                                      0x0
#define OLE_WATCHDOG_INTR_STATUS_TX_LSB                                        0
#define OLE_WATCHDOG_INTR_STATUS_TX_MSB                                        0
#define OLE_WATCHDOG_INTR_STATUS_TX_MASK                                       0x1
#define OLE_WATCHDOG_INTR_STATUS_TX_GET(x)                                     (((x) & OLE_WATCHDOG_INTR_STATUS_TX_MASK) >> OLE_WATCHDOG_INTR_STATUS_TX_LSB)
#define OLE_WATCHDOG_INTR_STATUS_TX_SET(x)                                     (((0 | (x)) << OLE_WATCHDOG_INTR_STATUS_TX_LSB) & OLE_WATCHDOG_INTR_STATUS_TX_MASK)
#define OLE_WATCHDOG_INTR_STATUS_TX_RESET                                      0x0
#define OLE_WATCHDOG_INTR_STATUS_ADDRESS                                       (0x124 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_WATCHDOG_INTR_STATUS_RSTMASK                                       0x3
#define OLE_WATCHDOG_INTR_STATUS_RESET                                         0x0

// 0x128 (OLE_DEBUG_1)
#define OLE_DEBUG_1_VAL_LSB                                                    0
#define OLE_DEBUG_1_VAL_MSB                                                    31
#define OLE_DEBUG_1_VAL_MASK                                                   0xffffffff
#define OLE_DEBUG_1_VAL_GET(x)                                                 (((x) & OLE_DEBUG_1_VAL_MASK) >> OLE_DEBUG_1_VAL_LSB)
#define OLE_DEBUG_1_VAL_SET(x)                                                 (((0 | (x)) << OLE_DEBUG_1_VAL_LSB) & OLE_DEBUG_1_VAL_MASK)
#define OLE_DEBUG_1_VAL_RESET                                                  0x0
#define OLE_DEBUG_1_ADDRESS                                                    (0x128 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DEBUG_1_RSTMASK                                                    0xffffffff
#define OLE_DEBUG_1_RESET                                                      0x0

// 0x12c (OLE_DEBUGBUS_CONTROL)
#define OLE_DEBUGBUS_CONTROL_TRCBUS_SELECT_LSB                                 0
#define OLE_DEBUGBUS_CONTROL_TRCBUS_SELECT_MSB                                 4
#define OLE_DEBUGBUS_CONTROL_TRCBUS_SELECT_MASK                                0x1f
#define OLE_DEBUGBUS_CONTROL_TRCBUS_SELECT_GET(x)                              (((x) & OLE_DEBUGBUS_CONTROL_TRCBUS_SELECT_MASK) >> OLE_DEBUGBUS_CONTROL_TRCBUS_SELECT_LSB)
#define OLE_DEBUGBUS_CONTROL_TRCBUS_SELECT_SET(x)                              (((0 | (x)) << OLE_DEBUGBUS_CONTROL_TRCBUS_SELECT_LSB) & OLE_DEBUGBUS_CONTROL_TRCBUS_SELECT_MASK)
#define OLE_DEBUGBUS_CONTROL_TRCBUS_SELECT_RESET                               0x0
#define OLE_DEBUGBUS_CONTROL_ADDRESS                                           (0x12c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_DEBUGBUS_CONTROL_RSTMASK                                           0x1f
#define OLE_DEBUGBUS_CONTROL_RESET                                             0x0

// 0x130 (OLE_TX_FIFO_STATUS)
#define OLE_TX_FIFO_STATUS_CMD_FIFO_DELTA_WORDS_DRAINED_LSB                    23
#define OLE_TX_FIFO_STATUS_CMD_FIFO_DELTA_WORDS_DRAINED_MSB                    28
#define OLE_TX_FIFO_STATUS_CMD_FIFO_DELTA_WORDS_DRAINED_MASK                   0x1f800000
#define OLE_TX_FIFO_STATUS_CMD_FIFO_DELTA_WORDS_DRAINED_GET(x)                 (((x) & OLE_TX_FIFO_STATUS_CMD_FIFO_DELTA_WORDS_DRAINED_MASK) >> OLE_TX_FIFO_STATUS_CMD_FIFO_DELTA_WORDS_DRAINED_LSB)
#define OLE_TX_FIFO_STATUS_CMD_FIFO_DELTA_WORDS_DRAINED_SET(x)                 (((0 | (x)) << OLE_TX_FIFO_STATUS_CMD_FIFO_DELTA_WORDS_DRAINED_LSB) & OLE_TX_FIFO_STATUS_CMD_FIFO_DELTA_WORDS_DRAINED_MASK)
#define OLE_TX_FIFO_STATUS_CMD_FIFO_DELTA_WORDS_DRAINED_RESET                  0x0
#define OLE_TX_FIFO_STATUS_DATA_FIFO_AVAILABLE_SPACE_LSB                       12
#define OLE_TX_FIFO_STATUS_DATA_FIFO_AVAILABLE_SPACE_MSB                       22
#define OLE_TX_FIFO_STATUS_DATA_FIFO_AVAILABLE_SPACE_MASK                      0x7ff000
#define OLE_TX_FIFO_STATUS_DATA_FIFO_AVAILABLE_SPACE_GET(x)                    (((x) & OLE_TX_FIFO_STATUS_DATA_FIFO_AVAILABLE_SPACE_MASK) >> OLE_TX_FIFO_STATUS_DATA_FIFO_AVAILABLE_SPACE_LSB)
#define OLE_TX_FIFO_STATUS_DATA_FIFO_AVAILABLE_SPACE_SET(x)                    (((0 | (x)) << OLE_TX_FIFO_STATUS_DATA_FIFO_AVAILABLE_SPACE_LSB) & OLE_TX_FIFO_STATUS_DATA_FIFO_AVAILABLE_SPACE_MASK)
#define OLE_TX_FIFO_STATUS_DATA_FIFO_AVAILABLE_SPACE_RESET                     0x7ff
#define OLE_TX_FIFO_STATUS_DATA_FIFO_DELTA_WORDS_DRAINED_LSB                   0
#define OLE_TX_FIFO_STATUS_DATA_FIFO_DELTA_WORDS_DRAINED_MSB                   11
#define OLE_TX_FIFO_STATUS_DATA_FIFO_DELTA_WORDS_DRAINED_MASK                  0xfff
#define OLE_TX_FIFO_STATUS_DATA_FIFO_DELTA_WORDS_DRAINED_GET(x)                (((x) & OLE_TX_FIFO_STATUS_DATA_FIFO_DELTA_WORDS_DRAINED_MASK) >> OLE_TX_FIFO_STATUS_DATA_FIFO_DELTA_WORDS_DRAINED_LSB)
#define OLE_TX_FIFO_STATUS_DATA_FIFO_DELTA_WORDS_DRAINED_SET(x)                (((0 | (x)) << OLE_TX_FIFO_STATUS_DATA_FIFO_DELTA_WORDS_DRAINED_LSB) & OLE_TX_FIFO_STATUS_DATA_FIFO_DELTA_WORDS_DRAINED_MASK)
#define OLE_TX_FIFO_STATUS_DATA_FIFO_DELTA_WORDS_DRAINED_RESET                 0x0
#define OLE_TX_FIFO_STATUS_ADDRESS                                             (0x130 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_TX_FIFO_STATUS_RSTMASK                                             0x1fffffff
#define OLE_TX_FIFO_STATUS_RESET                                               0x7ff000

// 0x134 (OLE_CLOCK_GATE)
#define OLE_CLOCK_GATE_DISABLE_LSB                                             0
#define OLE_CLOCK_GATE_DISABLE_MSB                                             2
#define OLE_CLOCK_GATE_DISABLE_MASK                                            0x7
#define OLE_CLOCK_GATE_DISABLE_GET(x)                                          (((x) & OLE_CLOCK_GATE_DISABLE_MASK) >> OLE_CLOCK_GATE_DISABLE_LSB)
#define OLE_CLOCK_GATE_DISABLE_SET(x)                                          (((0 | (x)) << OLE_CLOCK_GATE_DISABLE_LSB) & OLE_CLOCK_GATE_DISABLE_MASK)
#define OLE_CLOCK_GATE_DISABLE_RESET                                           0x7
#define OLE_CLOCK_GATE_ADDRESS                                                 (0x134 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_CLOCK_GATE_RSTMASK                                                 0x7
#define OLE_CLOCK_GATE_RESET                                                   0x7

// 0x138 (OLE_EVENT_BUS_MASK0)
#define OLE_EVENT_BUS_MASK0_VALUE_LSB                                          0
#define OLE_EVENT_BUS_MASK0_VALUE_MSB                                          31
#define OLE_EVENT_BUS_MASK0_VALUE_MASK                                         0xffffffff
#define OLE_EVENT_BUS_MASK0_VALUE_GET(x)                                       (((x) & OLE_EVENT_BUS_MASK0_VALUE_MASK) >> OLE_EVENT_BUS_MASK0_VALUE_LSB)
#define OLE_EVENT_BUS_MASK0_VALUE_SET(x)                                       (((0 | (x)) << OLE_EVENT_BUS_MASK0_VALUE_LSB) & OLE_EVENT_BUS_MASK0_VALUE_MASK)
#define OLE_EVENT_BUS_MASK0_VALUE_RESET                                        0x0
#define OLE_EVENT_BUS_MASK0_ADDRESS                                            (0x138 + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_EVENT_BUS_MASK0_RSTMASK                                            0xffffffff
#define OLE_EVENT_BUS_MASK0_RESET                                              0x0

// 0x13c (OLE_EVENT_BUS_MASK1)
#define OLE_EVENT_BUS_MASK1_VALUE_LSB                                          0
#define OLE_EVENT_BUS_MASK1_VALUE_MSB                                          31
#define OLE_EVENT_BUS_MASK1_VALUE_MASK                                         0xffffffff
#define OLE_EVENT_BUS_MASK1_VALUE_GET(x)                                       (((x) & OLE_EVENT_BUS_MASK1_VALUE_MASK) >> OLE_EVENT_BUS_MASK1_VALUE_LSB)
#define OLE_EVENT_BUS_MASK1_VALUE_SET(x)                                       (((0 | (x)) << OLE_EVENT_BUS_MASK1_VALUE_LSB) & OLE_EVENT_BUS_MASK1_VALUE_MASK)
#define OLE_EVENT_BUS_MASK1_VALUE_RESET                                        0x0
#define OLE_EVENT_BUS_MASK1_ADDRESS                                            (0x13c + __MAC_OLE_REG_BASE_ADDRESS)
#define OLE_EVENT_BUS_MASK1_RSTMASK                                            0xffffffff
#define OLE_EVENT_BUS_MASK1_RESET                                              0x0



#endif /* _MAC_OLE_REG_H_ */
