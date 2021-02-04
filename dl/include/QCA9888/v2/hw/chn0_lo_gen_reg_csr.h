/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CHN0_LO_GEN_REG_CSR_H_
#define _CHN0_LO_GEN_REG_CSR_H_


#ifndef __CHN0_LO_GEN_REG_CSR_BASE_ADDRESS
#define __CHN0_LO_GEN_REG_CSR_BASE_ADDRESS (0x46240)
#endif


// 0x0 (CHN0_LO0)
#define CHN0_LO0_LO_TXON_OVR_LSB                                               30
#define CHN0_LO0_LO_TXON_OVR_MSB                                               31
#define CHN0_LO0_LO_TXON_OVR_MASK                                              0xc0000000
#define CHN0_LO0_LO_TXON_OVR_GET(x)                                            (((x) & CHN0_LO0_LO_TXON_OVR_MASK) >> CHN0_LO0_LO_TXON_OVR_LSB)
#define CHN0_LO0_LO_TXON_OVR_SET(x)                                            (((0 | (x)) << CHN0_LO0_LO_TXON_OVR_LSB) & CHN0_LO0_LO_TXON_OVR_MASK)
#define CHN0_LO0_LO_TXON_OVR_RESET                                             0x0
#define CHN0_LO0_LO_RXON_OVR_LSB                                               28
#define CHN0_LO0_LO_RXON_OVR_MSB                                               29
#define CHN0_LO0_LO_RXON_OVR_MASK                                              0x30000000
#define CHN0_LO0_LO_RXON_OVR_GET(x)                                            (((x) & CHN0_LO0_LO_RXON_OVR_MASK) >> CHN0_LO0_LO_RXON_OVR_LSB)
#define CHN0_LO0_LO_RXON_OVR_SET(x)                                            (((0 | (x)) << CHN0_LO0_LO_RXON_OVR_LSB) & CHN0_LO0_LO_RXON_OVR_MASK)
#define CHN0_LO0_LO_RXON_OVR_RESET                                             0x0
#define CHN0_LO0_LO_DIV_EN_OVR_LSB                                             26
#define CHN0_LO0_LO_DIV_EN_OVR_MSB                                             27
#define CHN0_LO0_LO_DIV_EN_OVR_MASK                                            0xc000000
#define CHN0_LO0_LO_DIV_EN_OVR_GET(x)                                          (((x) & CHN0_LO0_LO_DIV_EN_OVR_MASK) >> CHN0_LO0_LO_DIV_EN_OVR_LSB)
#define CHN0_LO0_LO_DIV_EN_OVR_SET(x)                                          (((0 | (x)) << CHN0_LO0_LO_DIV_EN_OVR_LSB) & CHN0_LO0_LO_DIV_EN_OVR_MASK)
#define CHN0_LO0_LO_DIV_EN_OVR_RESET                                           0x0
#define CHN0_LO0_LO_DRV_EN_OVR_LSB                                             24
#define CHN0_LO0_LO_DRV_EN_OVR_MSB                                             25
#define CHN0_LO0_LO_DRV_EN_OVR_MASK                                            0x3000000
#define CHN0_LO0_LO_DRV_EN_OVR_GET(x)                                          (((x) & CHN0_LO0_LO_DRV_EN_OVR_MASK) >> CHN0_LO0_LO_DRV_EN_OVR_LSB)
#define CHN0_LO0_LO_DRV_EN_OVR_SET(x)                                          (((0 | (x)) << CHN0_LO0_LO_DRV_EN_OVR_LSB) & CHN0_LO0_LO_DRV_EN_OVR_MASK)
#define CHN0_LO0_LO_DRV_EN_OVR_RESET                                           0x0
#define CHN0_LO0_PAL_EN_OVR_LSB                                                22
#define CHN0_LO0_PAL_EN_OVR_MSB                                                23
#define CHN0_LO0_PAL_EN_OVR_MASK                                               0xc00000
#define CHN0_LO0_PAL_EN_OVR_GET(x)                                             (((x) & CHN0_LO0_PAL_EN_OVR_MASK) >> CHN0_LO0_PAL_EN_OVR_LSB)
#define CHN0_LO0_PAL_EN_OVR_SET(x)                                             (((0 | (x)) << CHN0_LO0_PAL_EN_OVR_LSB) & CHN0_LO0_PAL_EN_OVR_MASK)
#define CHN0_LO0_PAL_EN_OVR_RESET                                              0x0
#define CHN0_LO0_PAL_FLIP_MDIV_OVR_LSB                                         18
#define CHN0_LO0_PAL_FLIP_MDIV_OVR_MSB                                         19
#define CHN0_LO0_PAL_FLIP_MDIV_OVR_MASK                                        0xc0000
#define CHN0_LO0_PAL_FLIP_MDIV_OVR_GET(x)                                      (((x) & CHN0_LO0_PAL_FLIP_MDIV_OVR_MASK) >> CHN0_LO0_PAL_FLIP_MDIV_OVR_LSB)
#define CHN0_LO0_PAL_FLIP_MDIV_OVR_SET(x)                                      (((0 | (x)) << CHN0_LO0_PAL_FLIP_MDIV_OVR_LSB) & CHN0_LO0_PAL_FLIP_MDIV_OVR_MASK)
#define CHN0_LO0_PAL_FLIP_MDIV_OVR_RESET                                       0x0
#define CHN0_LO0_PAL_SWAL_MDIV_OVR_LSB                                         16
#define CHN0_LO0_PAL_SWAL_MDIV_OVR_MSB                                         17
#define CHN0_LO0_PAL_SWAL_MDIV_OVR_MASK                                        0x30000
#define CHN0_LO0_PAL_SWAL_MDIV_OVR_GET(x)                                      (((x) & CHN0_LO0_PAL_SWAL_MDIV_OVR_MASK) >> CHN0_LO0_PAL_SWAL_MDIV_OVR_LSB)
#define CHN0_LO0_PAL_SWAL_MDIV_OVR_SET(x)                                      (((0 | (x)) << CHN0_LO0_PAL_SWAL_MDIV_OVR_LSB) & CHN0_LO0_PAL_SWAL_MDIV_OVR_MASK)
#define CHN0_LO0_PAL_SWAL_MDIV_OVR_RESET                                       0x0
#define CHN0_LO0_LO_SYN0_CH0_ON_OVR_LSB                                        14
#define CHN0_LO0_LO_SYN0_CH0_ON_OVR_MSB                                        15
#define CHN0_LO0_LO_SYN0_CH0_ON_OVR_MASK                                       0xc000
#define CHN0_LO0_LO_SYN0_CH0_ON_OVR_GET(x)                                     (((x) & CHN0_LO0_LO_SYN0_CH0_ON_OVR_MASK) >> CHN0_LO0_LO_SYN0_CH0_ON_OVR_LSB)
#define CHN0_LO0_LO_SYN0_CH0_ON_OVR_SET(x)                                     (((0 | (x)) << CHN0_LO0_LO_SYN0_CH0_ON_OVR_LSB) & CHN0_LO0_LO_SYN0_CH0_ON_OVR_MASK)
#define CHN0_LO0_LO_SYN0_CH0_ON_OVR_RESET                                      0x0
#define CHN0_LO0_LO_SYN0_CH1_ON_OVR_LSB                                        12
#define CHN0_LO0_LO_SYN0_CH1_ON_OVR_MSB                                        13
#define CHN0_LO0_LO_SYN0_CH1_ON_OVR_MASK                                       0x3000
#define CHN0_LO0_LO_SYN0_CH1_ON_OVR_GET(x)                                     (((x) & CHN0_LO0_LO_SYN0_CH1_ON_OVR_MASK) >> CHN0_LO0_LO_SYN0_CH1_ON_OVR_LSB)
#define CHN0_LO0_LO_SYN0_CH1_ON_OVR_SET(x)                                     (((0 | (x)) << CHN0_LO0_LO_SYN0_CH1_ON_OVR_LSB) & CHN0_LO0_LO_SYN0_CH1_ON_OVR_MASK)
#define CHN0_LO0_LO_SYN0_CH1_ON_OVR_RESET                                      0x0
#define CHN0_LO0_LO_SYN1_CH1_ON_OVR_LSB                                        10
#define CHN0_LO0_LO_SYN1_CH1_ON_OVR_MSB                                        11
#define CHN0_LO0_LO_SYN1_CH1_ON_OVR_MASK                                       0xc00
#define CHN0_LO0_LO_SYN1_CH1_ON_OVR_GET(x)                                     (((x) & CHN0_LO0_LO_SYN1_CH1_ON_OVR_MASK) >> CHN0_LO0_LO_SYN1_CH1_ON_OVR_LSB)
#define CHN0_LO0_LO_SYN1_CH1_ON_OVR_SET(x)                                     (((0 | (x)) << CHN0_LO0_LO_SYN1_CH1_ON_OVR_LSB) & CHN0_LO0_LO_SYN1_CH1_ON_OVR_MASK)
#define CHN0_LO0_LO_SYN1_CH1_ON_OVR_RESET                                      0x0
#define CHN0_LO0_RXLOBUFDRV_LSB                                                8
#define CHN0_LO0_RXLOBUFDRV_MSB                                                9
#define CHN0_LO0_RXLOBUFDRV_MASK                                               0x300
#define CHN0_LO0_RXLOBUFDRV_GET(x)                                             (((x) & CHN0_LO0_RXLOBUFDRV_MASK) >> CHN0_LO0_RXLOBUFDRV_LSB)
#define CHN0_LO0_RXLOBUFDRV_SET(x)                                             (((0 | (x)) << CHN0_LO0_RXLOBUFDRV_LSB) & CHN0_LO0_RXLOBUFDRV_MASK)
#define CHN0_LO0_RXLOBUFDRV_RESET                                              0x2
#define CHN0_LO0_TXLOBUFDRV_LSB                                                6
#define CHN0_LO0_TXLOBUFDRV_MSB                                                7
#define CHN0_LO0_TXLOBUFDRV_MASK                                               0xc0
#define CHN0_LO0_TXLOBUFDRV_GET(x)                                             (((x) & CHN0_LO0_TXLOBUFDRV_MASK) >> CHN0_LO0_TXLOBUFDRV_LSB)
#define CHN0_LO0_TXLOBUFDRV_SET(x)                                             (((0 | (x)) << CHN0_LO0_TXLOBUFDRV_LSB) & CHN0_LO0_TXLOBUFDRV_MASK)
#define CHN0_LO0_TXLOBUFDRV_RESET                                              0x2
#define CHN0_LO0_LO_CTRL_LSB                                                   4
#define CHN0_LO0_LO_CTRL_MSB                                                   5
#define CHN0_LO0_LO_CTRL_MASK                                                  0x30
#define CHN0_LO0_LO_CTRL_GET(x)                                                (((x) & CHN0_LO0_LO_CTRL_MASK) >> CHN0_LO0_LO_CTRL_LSB)
#define CHN0_LO0_LO_CTRL_SET(x)                                                (((0 | (x)) << CHN0_LO0_LO_CTRL_LSB) & CHN0_LO0_LO_CTRL_MASK)
#define CHN0_LO0_LO_CTRL_RESET                                                 0x1
#define CHN0_LO0_LO_PKEN_LSB                                                   2
#define CHN0_LO0_LO_PKEN_MSB                                                   3
#define CHN0_LO0_LO_PKEN_MASK                                                  0xc
#define CHN0_LO0_LO_PKEN_GET(x)                                                (((x) & CHN0_LO0_LO_PKEN_MASK) >> CHN0_LO0_LO_PKEN_LSB)
#define CHN0_LO0_LO_PKEN_SET(x)                                                (((0 | (x)) << CHN0_LO0_LO_PKEN_LSB) & CHN0_LO0_LO_PKEN_MASK)
#define CHN0_LO0_LO_PKEN_RESET                                                 0x0
#define CHN0_LO0_ABUS_EN_LSB                                                   1
#define CHN0_LO0_ABUS_EN_MSB                                                   1
#define CHN0_LO0_ABUS_EN_MASK                                                  0x2
#define CHN0_LO0_ABUS_EN_GET(x)                                                (((x) & CHN0_LO0_ABUS_EN_MASK) >> CHN0_LO0_ABUS_EN_LSB)
#define CHN0_LO0_ABUS_EN_SET(x)                                                (((0 | (x)) << CHN0_LO0_ABUS_EN_LSB) & CHN0_LO0_ABUS_EN_MASK)
#define CHN0_LO0_ABUS_EN_RESET                                                 0x0
#define CHN0_LO0_RESERVED_0_LSB                                                0
#define CHN0_LO0_RESERVED_0_MSB                                                0
#define CHN0_LO0_RESERVED_0_MASK                                               0x1
#define CHN0_LO0_RESERVED_0_GET(x)                                             (((x) & CHN0_LO0_RESERVED_0_MASK) >> CHN0_LO0_RESERVED_0_LSB)
#define CHN0_LO0_RESERVED_0_SET(x)                                             (((0 | (x)) << CHN0_LO0_RESERVED_0_LSB) & CHN0_LO0_RESERVED_0_MASK)
#define CHN0_LO0_RESERVED_0_RESET                                              0x0
#define CHN0_LO0_ADDRESS                                                       (0x0 + __CHN0_LO_GEN_REG_CSR_BASE_ADDRESS)
#define CHN0_LO0_RSTMASK                                                       0xffcfffff
#define CHN0_LO0_RESET                                                         0x290

// 0x4 (CHN0_LO1)
#define CHN0_LO1_DIST_ENCAP_OVR_EN_LSB                                         31
#define CHN0_LO1_DIST_ENCAP_OVR_EN_MSB                                         31
#define CHN0_LO1_DIST_ENCAP_OVR_EN_MASK                                        0x80000000
#define CHN0_LO1_DIST_ENCAP_OVR_EN_GET(x)                                      (((x) & CHN0_LO1_DIST_ENCAP_OVR_EN_MASK) >> CHN0_LO1_DIST_ENCAP_OVR_EN_LSB)
#define CHN0_LO1_DIST_ENCAP_OVR_EN_SET(x)                                      (((0 | (x)) << CHN0_LO1_DIST_ENCAP_OVR_EN_LSB) & CHN0_LO1_DIST_ENCAP_OVR_EN_MASK)
#define CHN0_LO1_DIST_ENCAP_OVR_EN_RESET                                       0x0
#define CHN0_LO1_DIST_ENCAP_OVR_VAL_LSB                                        28
#define CHN0_LO1_DIST_ENCAP_OVR_VAL_MSB                                        30
#define CHN0_LO1_DIST_ENCAP_OVR_VAL_MASK                                       0x70000000
#define CHN0_LO1_DIST_ENCAP_OVR_VAL_GET(x)                                     (((x) & CHN0_LO1_DIST_ENCAP_OVR_VAL_MASK) >> CHN0_LO1_DIST_ENCAP_OVR_VAL_LSB)
#define CHN0_LO1_DIST_ENCAP_OVR_VAL_SET(x)                                     (((0 | (x)) << CHN0_LO1_DIST_ENCAP_OVR_VAL_LSB) & CHN0_LO1_DIST_ENCAP_OVR_VAL_MASK)
#define CHN0_LO1_DIST_ENCAP_OVR_VAL_RESET                                      0x1
#define CHN0_LO1_RESERVED_0_LSB                                                0
#define CHN0_LO1_RESERVED_0_MSB                                                27
#define CHN0_LO1_RESERVED_0_MASK                                               0xfffffff
#define CHN0_LO1_RESERVED_0_GET(x)                                             (((x) & CHN0_LO1_RESERVED_0_MASK) >> CHN0_LO1_RESERVED_0_LSB)
#define CHN0_LO1_RESERVED_0_SET(x)                                             (((0 | (x)) << CHN0_LO1_RESERVED_0_LSB) & CHN0_LO1_RESERVED_0_MASK)
#define CHN0_LO1_RESERVED_0_RESET                                              0x0
#define CHN0_LO1_ADDRESS                                                       (0x4 + __CHN0_LO_GEN_REG_CSR_BASE_ADDRESS)
#define CHN0_LO1_RSTMASK                                                       0xffffffff
#define CHN0_LO1_RESET                                                         0x10000000

// 0x8 (CHN0_LO2)
#define CHN0_LO2_LO_DTOP_SPARE_LSB                                             0
#define CHN0_LO2_LO_DTOP_SPARE_MSB                                             31
#define CHN0_LO2_LO_DTOP_SPARE_MASK                                            0xffffffff
#define CHN0_LO2_LO_DTOP_SPARE_GET(x)                                          (((x) & CHN0_LO2_LO_DTOP_SPARE_MASK) >> CHN0_LO2_LO_DTOP_SPARE_LSB)
#define CHN0_LO2_LO_DTOP_SPARE_SET(x)                                          (((0 | (x)) << CHN0_LO2_LO_DTOP_SPARE_LSB) & CHN0_LO2_LO_DTOP_SPARE_MASK)
#define CHN0_LO2_LO_DTOP_SPARE_RESET                                           0x0
#define CHN0_LO2_ADDRESS                                                       (0x8 + __CHN0_LO_GEN_REG_CSR_BASE_ADDRESS)
#define CHN0_LO2_RSTMASK                                                       0xffffffff
#define CHN0_LO2_RESET                                                         0x0



#endif /* _CHN0_LO_GEN_REG_CSR_H_ */
