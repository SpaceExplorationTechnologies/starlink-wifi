/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CHN7_RXFE2G_REG_CSR_H_
#define _CHN7_RXFE2G_REG_CSR_H_


#ifndef __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS
#define __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS (0x49c00)
#endif


// 0x0 (CHN7_RXFE2_0)
#define CHN7_RXFE2_0_OVRD_RXGAIN_LSB                                           31
#define CHN7_RXFE2_0_OVRD_RXGAIN_MSB                                           31
#define CHN7_RXFE2_0_OVRD_RXGAIN_MASK                                          0x80000000
#define CHN7_RXFE2_0_OVRD_RXGAIN_GET(x)                                        (((x) & CHN7_RXFE2_0_OVRD_RXGAIN_MASK) >> CHN7_RXFE2_0_OVRD_RXGAIN_LSB)
#define CHN7_RXFE2_0_OVRD_RXGAIN_SET(x)                                        (((0 | (x)) << CHN7_RXFE2_0_OVRD_RXGAIN_LSB) & CHN7_RXFE2_0_OVRD_RXGAIN_MASK)
#define CHN7_RXFE2_0_OVRD_RXGAIN_RESET                                         0x0
#define CHN7_RXFE2_0_LNAGAIN_LS_LSB                                            28
#define CHN7_RXFE2_0_LNAGAIN_LS_MSB                                            30
#define CHN7_RXFE2_0_LNAGAIN_LS_MASK                                           0x70000000
#define CHN7_RXFE2_0_LNAGAIN_LS_GET(x)                                         (((x) & CHN7_RXFE2_0_LNAGAIN_LS_MASK) >> CHN7_RXFE2_0_LNAGAIN_LS_LSB)
#define CHN7_RXFE2_0_LNAGAIN_LS_SET(x)                                         (((0 | (x)) << CHN7_RXFE2_0_LNAGAIN_LS_LSB) & CHN7_RXFE2_0_LNAGAIN_LS_MASK)
#define CHN7_RXFE2_0_LNAGAIN_LS_RESET                                          0x0
#define CHN7_RXFE2_0_GMGAIN_LS_LSB                                             26
#define CHN7_RXFE2_0_GMGAIN_LS_MSB                                             27
#define CHN7_RXFE2_0_GMGAIN_LS_MASK                                            0xc000000
#define CHN7_RXFE2_0_GMGAIN_LS_GET(x)                                          (((x) & CHN7_RXFE2_0_GMGAIN_LS_MASK) >> CHN7_RXFE2_0_GMGAIN_LS_LSB)
#define CHN7_RXFE2_0_GMGAIN_LS_SET(x)                                          (((0 | (x)) << CHN7_RXFE2_0_GMGAIN_LS_LSB) & CHN7_RXFE2_0_GMGAIN_LS_MASK)
#define CHN7_RXFE2_0_GMGAIN_LS_RESET                                           0x0
#define CHN7_RXFE2_0_CALDC_LS_LSB                                              25
#define CHN7_RXFE2_0_CALDC_LS_MSB                                              25
#define CHN7_RXFE2_0_CALDC_LS_MASK                                             0x2000000
#define CHN7_RXFE2_0_CALDC_LS_GET(x)                                           (((x) & CHN7_RXFE2_0_CALDC_LS_MASK) >> CHN7_RXFE2_0_CALDC_LS_LSB)
#define CHN7_RXFE2_0_CALDC_LS_SET(x)                                           (((0 | (x)) << CHN7_RXFE2_0_CALDC_LS_LSB) & CHN7_RXFE2_0_CALDC_LS_MASK)
#define CHN7_RXFE2_0_CALDC_LS_RESET                                            0x0
#define CHN7_RXFE2_0_OVRD_AGC_CAL_LSB                                          24
#define CHN7_RXFE2_0_OVRD_AGC_CAL_MSB                                          24
#define CHN7_RXFE2_0_OVRD_AGC_CAL_MASK                                         0x1000000
#define CHN7_RXFE2_0_OVRD_AGC_CAL_GET(x)                                       (((x) & CHN7_RXFE2_0_OVRD_AGC_CAL_MASK) >> CHN7_RXFE2_0_OVRD_AGC_CAL_LSB)
#define CHN7_RXFE2_0_OVRD_AGC_CAL_SET(x)                                       (((0 | (x)) << CHN7_RXFE2_0_OVRD_AGC_CAL_LSB) & CHN7_RXFE2_0_OVRD_AGC_CAL_MASK)
#define CHN7_RXFE2_0_OVRD_AGC_CAL_RESET                                        0x0
#define CHN7_RXFE2_0_AGC_CAL_LS_LSB                                            23
#define CHN7_RXFE2_0_AGC_CAL_LS_MSB                                            23
#define CHN7_RXFE2_0_AGC_CAL_LS_MASK                                           0x800000
#define CHN7_RXFE2_0_AGC_CAL_LS_GET(x)                                         (((x) & CHN7_RXFE2_0_AGC_CAL_LS_MASK) >> CHN7_RXFE2_0_AGC_CAL_LS_LSB)
#define CHN7_RXFE2_0_AGC_CAL_LS_SET(x)                                         (((0 | (x)) << CHN7_RXFE2_0_AGC_CAL_LS_LSB) & CHN7_RXFE2_0_AGC_CAL_LS_MASK)
#define CHN7_RXFE2_0_AGC_CAL_LS_RESET                                          0x0
#define CHN7_RXFE2_0_AGC_CALDAC_LS_LSB                                         16
#define CHN7_RXFE2_0_AGC_CALDAC_LS_MSB                                         22
#define CHN7_RXFE2_0_AGC_CALDAC_LS_MASK                                        0x7f0000
#define CHN7_RXFE2_0_AGC_CALDAC_LS_GET(x)                                      (((x) & CHN7_RXFE2_0_AGC_CALDAC_LS_MASK) >> CHN7_RXFE2_0_AGC_CALDAC_LS_LSB)
#define CHN7_RXFE2_0_AGC_CALDAC_LS_SET(x)                                      (((0 | (x)) << CHN7_RXFE2_0_AGC_CALDAC_LS_LSB) & CHN7_RXFE2_0_AGC_CALDAC_LS_MASK)
#define CHN7_RXFE2_0_AGC_CALDAC_LS_RESET                                       0x0
#define CHN7_RXFE2_0_AGC_DBDAC_LSB                                             12
#define CHN7_RXFE2_0_AGC_DBDAC_MSB                                             15
#define CHN7_RXFE2_0_AGC_DBDAC_MASK                                            0xf000
#define CHN7_RXFE2_0_AGC_DBDAC_GET(x)                                          (((x) & CHN7_RXFE2_0_AGC_DBDAC_MASK) >> CHN7_RXFE2_0_AGC_DBDAC_LSB)
#define CHN7_RXFE2_0_AGC_DBDAC_SET(x)                                          (((0 | (x)) << CHN7_RXFE2_0_AGC_DBDAC_LSB) & CHN7_RXFE2_0_AGC_DBDAC_MASK)
#define CHN7_RXFE2_0_AGC_DBDAC_RESET                                           0x0
#define CHN7_RXFE2_0_OVRD_BLK_LSB                                              11
#define CHN7_RXFE2_0_OVRD_BLK_MSB                                              11
#define CHN7_RXFE2_0_OVRD_BLK_MASK                                             0x800
#define CHN7_RXFE2_0_OVRD_BLK_GET(x)                                           (((x) & CHN7_RXFE2_0_OVRD_BLK_MASK) >> CHN7_RXFE2_0_OVRD_BLK_LSB)
#define CHN7_RXFE2_0_OVRD_BLK_SET(x)                                           (((0 | (x)) << CHN7_RXFE2_0_OVRD_BLK_LSB) & CHN7_RXFE2_0_OVRD_BLK_MASK)
#define CHN7_RXFE2_0_OVRD_BLK_RESET                                            0x0
#define CHN7_RXFE2_0_EN_LNA2_LS_LSB                                            10
#define CHN7_RXFE2_0_EN_LNA2_LS_MSB                                            10
#define CHN7_RXFE2_0_EN_LNA2_LS_MASK                                           0x400
#define CHN7_RXFE2_0_EN_LNA2_LS_GET(x)                                         (((x) & CHN7_RXFE2_0_EN_LNA2_LS_MASK) >> CHN7_RXFE2_0_EN_LNA2_LS_LSB)
#define CHN7_RXFE2_0_EN_LNA2_LS_SET(x)                                         (((0 | (x)) << CHN7_RXFE2_0_EN_LNA2_LS_LSB) & CHN7_RXFE2_0_EN_LNA2_LS_MASK)
#define CHN7_RXFE2_0_EN_LNA2_LS_RESET                                          0x0
#define CHN7_RXFE2_0_EN_GM2_LS_LSB                                             9
#define CHN7_RXFE2_0_EN_GM2_LS_MSB                                             9
#define CHN7_RXFE2_0_EN_GM2_LS_MASK                                            0x200
#define CHN7_RXFE2_0_EN_GM2_LS_GET(x)                                          (((x) & CHN7_RXFE2_0_EN_GM2_LS_MASK) >> CHN7_RXFE2_0_EN_GM2_LS_LSB)
#define CHN7_RXFE2_0_EN_GM2_LS_SET(x)                                          (((0 | (x)) << CHN7_RXFE2_0_EN_GM2_LS_LSB) & CHN7_RXFE2_0_EN_GM2_LS_MASK)
#define CHN7_RXFE2_0_EN_GM2_LS_RESET                                           0x0
#define CHN7_RXFE2_0_EN_AGC2_CAL_LS_LSB                                        8
#define CHN7_RXFE2_0_EN_AGC2_CAL_LS_MSB                                        8
#define CHN7_RXFE2_0_EN_AGC2_CAL_LS_MASK                                       0x100
#define CHN7_RXFE2_0_EN_AGC2_CAL_LS_GET(x)                                     (((x) & CHN7_RXFE2_0_EN_AGC2_CAL_LS_MASK) >> CHN7_RXFE2_0_EN_AGC2_CAL_LS_LSB)
#define CHN7_RXFE2_0_EN_AGC2_CAL_LS_SET(x)                                     (((0 | (x)) << CHN7_RXFE2_0_EN_AGC2_CAL_LS_LSB) & CHN7_RXFE2_0_EN_AGC2_CAL_LS_MASK)
#define CHN7_RXFE2_0_EN_AGC2_CAL_LS_RESET                                      0x0
#define CHN7_RXFE2_0_EN_RXLO2_DRV_LS_LSB                                       7
#define CHN7_RXFE2_0_EN_RXLO2_DRV_LS_MSB                                       7
#define CHN7_RXFE2_0_EN_RXLO2_DRV_LS_MASK                                      0x80
#define CHN7_RXFE2_0_EN_RXLO2_DRV_LS_GET(x)                                    (((x) & CHN7_RXFE2_0_EN_RXLO2_DRV_LS_MASK) >> CHN7_RXFE2_0_EN_RXLO2_DRV_LS_LSB)
#define CHN7_RXFE2_0_EN_RXLO2_DRV_LS_SET(x)                                    (((0 | (x)) << CHN7_RXFE2_0_EN_RXLO2_DRV_LS_LSB) & CHN7_RXFE2_0_EN_RXLO2_DRV_LS_MASK)
#define CHN7_RXFE2_0_EN_RXLO2_DRV_LS_RESET                                     0x0
#define CHN7_RXFE2_0_EN_RX2_CALTX_LS_LSB                                       6
#define CHN7_RXFE2_0_EN_RX2_CALTX_LS_MSB                                       6
#define CHN7_RXFE2_0_EN_RX2_CALTX_LS_MASK                                      0x40
#define CHN7_RXFE2_0_EN_RX2_CALTX_LS_GET(x)                                    (((x) & CHN7_RXFE2_0_EN_RX2_CALTX_LS_MASK) >> CHN7_RXFE2_0_EN_RX2_CALTX_LS_LSB)
#define CHN7_RXFE2_0_EN_RX2_CALTX_LS_SET(x)                                    (((0 | (x)) << CHN7_RXFE2_0_EN_RX2_CALTX_LS_LSB) & CHN7_RXFE2_0_EN_RX2_CALTX_LS_MASK)
#define CHN7_RXFE2_0_EN_RX2_CALTX_LS_RESET                                     0x0
#define CHN7_RXFE2_0_EN_RX2_CALTXSHIFT_LS_LSB                                  5
#define CHN7_RXFE2_0_EN_RX2_CALTXSHIFT_LS_MSB                                  5
#define CHN7_RXFE2_0_EN_RX2_CALTXSHIFT_LS_MASK                                 0x20
#define CHN7_RXFE2_0_EN_RX2_CALTXSHIFT_LS_GET(x)                               (((x) & CHN7_RXFE2_0_EN_RX2_CALTXSHIFT_LS_MASK) >> CHN7_RXFE2_0_EN_RX2_CALTXSHIFT_LS_LSB)
#define CHN7_RXFE2_0_EN_RX2_CALTXSHIFT_LS_SET(x)                               (((0 | (x)) << CHN7_RXFE2_0_EN_RX2_CALTXSHIFT_LS_LSB) & CHN7_RXFE2_0_EN_RX2_CALTXSHIFT_LS_MASK)
#define CHN7_RXFE2_0_EN_RX2_CALTXSHIFT_LS_RESET                                0x0
#define CHN7_RXFE2_0_EN_AGC2_PDET_LS_LSB                                       4
#define CHN7_RXFE2_0_EN_AGC2_PDET_LS_MSB                                       4
#define CHN7_RXFE2_0_EN_AGC2_PDET_LS_MASK                                      0x10
#define CHN7_RXFE2_0_EN_AGC2_PDET_LS_GET(x)                                    (((x) & CHN7_RXFE2_0_EN_AGC2_PDET_LS_MASK) >> CHN7_RXFE2_0_EN_AGC2_PDET_LS_LSB)
#define CHN7_RXFE2_0_EN_AGC2_PDET_LS_SET(x)                                    (((0 | (x)) << CHN7_RXFE2_0_EN_AGC2_PDET_LS_LSB) & CHN7_RXFE2_0_EN_AGC2_PDET_LS_MASK)
#define CHN7_RXFE2_0_EN_AGC2_PDET_LS_RESET                                     0x0
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_LS_LSB                                      3
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_LS_MSB                                      3
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_LS_MASK                                     0x8
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_LS_GET(x)                                   (((x) & CHN7_RXFE2_0_EN_RX2_IM2CAL_LS_MASK) >> CHN7_RXFE2_0_EN_RX2_IM2CAL_LS_LSB)
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_LS_SET(x)                                   (((0 | (x)) << CHN7_RXFE2_0_EN_RX2_IM2CAL_LS_LSB) & CHN7_RXFE2_0_EN_RX2_IM2CAL_LS_MASK)
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_LS_RESET                                    0x0
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_OTA_LS_LSB                                  2
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_OTA_LS_MSB                                  2
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_OTA_LS_MASK                                 0x4
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_OTA_LS_GET(x)                               (((x) & CHN7_RXFE2_0_EN_RX2_IM2CAL_OTA_LS_MASK) >> CHN7_RXFE2_0_EN_RX2_IM2CAL_OTA_LS_LSB)
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_OTA_LS_SET(x)                               (((0 | (x)) << CHN7_RXFE2_0_EN_RX2_IM2CAL_OTA_LS_LSB) & CHN7_RXFE2_0_EN_RX2_IM2CAL_OTA_LS_MASK)
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_OTA_LS_RESET                                0x0
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_BIAS_LS_LSB                                 1
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_BIAS_LS_MSB                                 1
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_BIAS_LS_MASK                                0x2
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_BIAS_LS_GET(x)                              (((x) & CHN7_RXFE2_0_EN_RX2_IM2CAL_BIAS_LS_MASK) >> CHN7_RXFE2_0_EN_RX2_IM2CAL_BIAS_LS_LSB)
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_BIAS_LS_SET(x)                              (((0 | (x)) << CHN7_RXFE2_0_EN_RX2_IM2CAL_BIAS_LS_LSB) & CHN7_RXFE2_0_EN_RX2_IM2CAL_BIAS_LS_MASK)
#define CHN7_RXFE2_0_EN_RX2_IM2CAL_BIAS_LS_RESET                               0x0
#define CHN7_RXFE2_0_RXLO2_ENABLE_TXON_LSB                                     0
#define CHN7_RXFE2_0_RXLO2_ENABLE_TXON_MSB                                     0
#define CHN7_RXFE2_0_RXLO2_ENABLE_TXON_MASK                                    0x1
#define CHN7_RXFE2_0_RXLO2_ENABLE_TXON_GET(x)                                  (((x) & CHN7_RXFE2_0_RXLO2_ENABLE_TXON_MASK) >> CHN7_RXFE2_0_RXLO2_ENABLE_TXON_LSB)
#define CHN7_RXFE2_0_RXLO2_ENABLE_TXON_SET(x)                                  (((0 | (x)) << CHN7_RXFE2_0_RXLO2_ENABLE_TXON_LSB) & CHN7_RXFE2_0_RXLO2_ENABLE_TXON_MASK)
#define CHN7_RXFE2_0_RXLO2_ENABLE_TXON_RESET                                   0x0
#define CHN7_RXFE2_0_ADDRESS                                                   (0x0 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_RXFE2_0_RSTMASK                                                   0xffffffff
#define CHN7_RXFE2_0_RESET                                                     0x0

// 0x4 (CHN7_RXFE2_1)
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_DAC_INT_LSB                                24
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_DAC_INT_MSB                                31
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_DAC_INT_MASK                               0xff000000
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_DAC_INT_GET(x)                             (((x) & CHN7_RXFE2_1_RX2_IM2CAL_RSB_DAC_INT_MASK) >> CHN7_RXFE2_1_RX2_IM2CAL_RSB_DAC_INT_LSB)
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_DAC_INT_SET(x)                             (((0 | (x)) << CHN7_RXFE2_1_RX2_IM2CAL_RSB_DAC_INT_LSB) & CHN7_RXFE2_1_RX2_IM2CAL_RSB_DAC_INT_MASK)
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_DAC_INT_RESET                              0x3f
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_CONT_LSB                                   21
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_CONT_MSB                                   23
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_CONT_MASK                                  0xe00000
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_CONT_GET(x)                                (((x) & CHN7_RXFE2_1_RX2_IM2CAL_RSB_CONT_MASK) >> CHN7_RXFE2_1_RX2_IM2CAL_RSB_CONT_LSB)
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_CONT_SET(x)                                (((0 | (x)) << CHN7_RXFE2_1_RX2_IM2CAL_RSB_CONT_LSB) & CHN7_RXFE2_1_RX2_IM2CAL_RSB_CONT_MASK)
#define CHN7_RXFE2_1_RX2_IM2CAL_RSB_CONT_RESET                                 0x2
#define CHN7_RXFE2_1_RESERVED_0_LSB                                            20
#define CHN7_RXFE2_1_RESERVED_0_MSB                                            20
#define CHN7_RXFE2_1_RESERVED_0_MASK                                           0x100000
#define CHN7_RXFE2_1_RESERVED_0_GET(x)                                         (((x) & CHN7_RXFE2_1_RESERVED_0_MASK) >> CHN7_RXFE2_1_RESERVED_0_LSB)
#define CHN7_RXFE2_1_RESERVED_0_SET(x)                                         (((0 | (x)) << CHN7_RXFE2_1_RESERVED_0_LSB) & CHN7_RXFE2_1_RESERVED_0_MASK)
#define CHN7_RXFE2_1_RESERVED_0_RESET                                          0x0
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VGF_LSB                                    18
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VGF_MSB                                    19
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VGF_MASK                                   0xc0000
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VGF_GET(x)                                 (((x) & CHN7_RXFE2_1_RX2_IM2CAL_MIX_VGF_MASK) >> CHN7_RXFE2_1_RX2_IM2CAL_MIX_VGF_LSB)
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VGF_SET(x)                                 (((0 | (x)) << CHN7_RXFE2_1_RX2_IM2CAL_MIX_VGF_LSB) & CHN7_RXFE2_1_RX2_IM2CAL_MIX_VGF_MASK)
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VGF_RESET                                  0x2
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VCM_TIA_LSB                                16
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VCM_TIA_MSB                                17
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VCM_TIA_MASK                               0x30000
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VCM_TIA_GET(x)                             (((x) & CHN7_RXFE2_1_RX2_IM2CAL_MIX_VCM_TIA_MASK) >> CHN7_RXFE2_1_RX2_IM2CAL_MIX_VCM_TIA_LSB)
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VCM_TIA_SET(x)                             (((0 | (x)) << CHN7_RXFE2_1_RX2_IM2CAL_MIX_VCM_TIA_LSB) & CHN7_RXFE2_1_RX2_IM2CAL_MIX_VCM_TIA_MASK)
#define CHN7_RXFE2_1_RX2_IM2CAL_MIX_VCM_TIA_RESET                              0x1
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_IDAC_LSB                                  8
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_IDAC_MSB                                  15
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_IDAC_MASK                                 0xff00
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_IDAC_GET(x)                               (((x) & CHN7_RXFE2_1_RX2_IM2CAL_VCAL_IDAC_MASK) >> CHN7_RXFE2_1_RX2_IM2CAL_VCAL_IDAC_LSB)
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_IDAC_SET(x)                               (((0 | (x)) << CHN7_RXFE2_1_RX2_IM2CAL_VCAL_IDAC_LSB) & CHN7_RXFE2_1_RX2_IM2CAL_VCAL_IDAC_MASK)
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_IDAC_RESET                                0x3f
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_QDAC_LSB                                  0
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_QDAC_MSB                                  7
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_QDAC_MASK                                 0xff
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_QDAC_GET(x)                               (((x) & CHN7_RXFE2_1_RX2_IM2CAL_VCAL_QDAC_MASK) >> CHN7_RXFE2_1_RX2_IM2CAL_VCAL_QDAC_LSB)
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_QDAC_SET(x)                               (((0 | (x)) << CHN7_RXFE2_1_RX2_IM2CAL_VCAL_QDAC_LSB) & CHN7_RXFE2_1_RX2_IM2CAL_VCAL_QDAC_MASK)
#define CHN7_RXFE2_1_RX2_IM2CAL_VCAL_QDAC_RESET                                0x3f
#define CHN7_RXFE2_1_ADDRESS                                                   (0x4 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_RXFE2_1_RSTMASK                                                   0xffffffff
#define CHN7_RXFE2_1_RESET                                                     0x3f493f3f

// 0x8 (CHN7_RXFE2_2)
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTI_LSB                                      28
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTI_MSB                                      31
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTI_MASK                                     0xf0000000
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTI_GET(x)                                   (((x) & CHN7_RXFE2_2_RX2_IM2CAL_CONTI_MASK) >> CHN7_RXFE2_2_RX2_IM2CAL_CONTI_LSB)
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTI_SET(x)                                   (((0 | (x)) << CHN7_RXFE2_2_RX2_IM2CAL_CONTI_LSB) & CHN7_RXFE2_2_RX2_IM2CAL_CONTI_MASK)
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTI_RESET                                    0x4
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTQ_LSB                                      24
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTQ_MSB                                      27
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTQ_MASK                                     0xf000000
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTQ_GET(x)                                   (((x) & CHN7_RXFE2_2_RX2_IM2CAL_CONTQ_MASK) >> CHN7_RXFE2_2_RX2_IM2CAL_CONTQ_LSB)
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTQ_SET(x)                                   (((0 | (x)) << CHN7_RXFE2_2_RX2_IM2CAL_CONTQ_LSB) & CHN7_RXFE2_2_RX2_IM2CAL_CONTQ_MASK)
#define CHN7_RXFE2_2_RX2_IM2CAL_CONTQ_RESET                                    0x4
#define CHN7_RXFE2_2_DPD_ATTENU_SEL_LSB                                        20
#define CHN7_RXFE2_2_DPD_ATTENU_SEL_MSB                                        23
#define CHN7_RXFE2_2_DPD_ATTENU_SEL_MASK                                       0xf00000
#define CHN7_RXFE2_2_DPD_ATTENU_SEL_GET(x)                                     (((x) & CHN7_RXFE2_2_DPD_ATTENU_SEL_MASK) >> CHN7_RXFE2_2_DPD_ATTENU_SEL_LSB)
#define CHN7_RXFE2_2_DPD_ATTENU_SEL_SET(x)                                     (((0 | (x)) << CHN7_RXFE2_2_DPD_ATTENU_SEL_LSB) & CHN7_RXFE2_2_DPD_ATTENU_SEL_MASK)
#define CHN7_RXFE2_2_DPD_ATTENU_SEL_RESET                                      0x0
#define CHN7_RXFE2_2_LNA_CM_LC_CSEL_LSB                                        16
#define CHN7_RXFE2_2_LNA_CM_LC_CSEL_MSB                                        19
#define CHN7_RXFE2_2_LNA_CM_LC_CSEL_MASK                                       0xf0000
#define CHN7_RXFE2_2_LNA_CM_LC_CSEL_GET(x)                                     (((x) & CHN7_RXFE2_2_LNA_CM_LC_CSEL_MASK) >> CHN7_RXFE2_2_LNA_CM_LC_CSEL_LSB)
#define CHN7_RXFE2_2_LNA_CM_LC_CSEL_SET(x)                                     (((0 | (x)) << CHN7_RXFE2_2_LNA_CM_LC_CSEL_LSB) & CHN7_RXFE2_2_LNA_CM_LC_CSEL_MASK)
#define CHN7_RXFE2_2_LNA_CM_LC_CSEL_RESET                                      0x8
#define CHN7_RXFE2_2_LNA_CM_LC_EN_LSB                                          15
#define CHN7_RXFE2_2_LNA_CM_LC_EN_MSB                                          15
#define CHN7_RXFE2_2_LNA_CM_LC_EN_MASK                                         0x8000
#define CHN7_RXFE2_2_LNA_CM_LC_EN_GET(x)                                       (((x) & CHN7_RXFE2_2_LNA_CM_LC_EN_MASK) >> CHN7_RXFE2_2_LNA_CM_LC_EN_LSB)
#define CHN7_RXFE2_2_LNA_CM_LC_EN_SET(x)                                       (((0 | (x)) << CHN7_RXFE2_2_LNA_CM_LC_EN_LSB) & CHN7_RXFE2_2_LNA_CM_LC_EN_MASK)
#define CHN7_RXFE2_2_LNA_CM_LC_EN_RESET                                        0x0
#define CHN7_RXFE2_2_AGC_BW_CTRL_LSB                                           12
#define CHN7_RXFE2_2_AGC_BW_CTRL_MSB                                           14
#define CHN7_RXFE2_2_AGC_BW_CTRL_MASK                                          0x7000
#define CHN7_RXFE2_2_AGC_BW_CTRL_GET(x)                                        (((x) & CHN7_RXFE2_2_AGC_BW_CTRL_MASK) >> CHN7_RXFE2_2_AGC_BW_CTRL_LSB)
#define CHN7_RXFE2_2_AGC_BW_CTRL_SET(x)                                        (((0 | (x)) << CHN7_RXFE2_2_AGC_BW_CTRL_LSB) & CHN7_RXFE2_2_AGC_BW_CTRL_MASK)
#define CHN7_RXFE2_2_AGC_BW_CTRL_RESET                                         0x0
#define CHN7_RXFE2_2_AGC_RNG_CTRL_LSB                                          10
#define CHN7_RXFE2_2_AGC_RNG_CTRL_MSB                                          11
#define CHN7_RXFE2_2_AGC_RNG_CTRL_MASK                                         0xc00
#define CHN7_RXFE2_2_AGC_RNG_CTRL_GET(x)                                       (((x) & CHN7_RXFE2_2_AGC_RNG_CTRL_MASK) >> CHN7_RXFE2_2_AGC_RNG_CTRL_LSB)
#define CHN7_RXFE2_2_AGC_RNG_CTRL_SET(x)                                       (((0 | (x)) << CHN7_RXFE2_2_AGC_RNG_CTRL_LSB) & CHN7_RXFE2_2_AGC_RNG_CTRL_MASK)
#define CHN7_RXFE2_2_AGC_RNG_CTRL_RESET                                        0x0
#define CHN7_RXFE2_2_LOAD_DEQ_LSB                                              9
#define CHN7_RXFE2_2_LOAD_DEQ_MSB                                              9
#define CHN7_RXFE2_2_LOAD_DEQ_MASK                                             0x200
#define CHN7_RXFE2_2_LOAD_DEQ_GET(x)                                           (((x) & CHN7_RXFE2_2_LOAD_DEQ_MASK) >> CHN7_RXFE2_2_LOAD_DEQ_LSB)
#define CHN7_RXFE2_2_LOAD_DEQ_SET(x)                                           (((0 | (x)) << CHN7_RXFE2_2_LOAD_DEQ_LSB) & CHN7_RXFE2_2_LOAD_DEQ_MASK)
#define CHN7_RXFE2_2_LOAD_DEQ_RESET                                            0x0
#define CHN7_RXFE2_2_BIAS_OTA_SHORTR_LSB                                       8
#define CHN7_RXFE2_2_BIAS_OTA_SHORTR_MSB                                       8
#define CHN7_RXFE2_2_BIAS_OTA_SHORTR_MASK                                      0x100
#define CHN7_RXFE2_2_BIAS_OTA_SHORTR_GET(x)                                    (((x) & CHN7_RXFE2_2_BIAS_OTA_SHORTR_MASK) >> CHN7_RXFE2_2_BIAS_OTA_SHORTR_LSB)
#define CHN7_RXFE2_2_BIAS_OTA_SHORTR_SET(x)                                    (((0 | (x)) << CHN7_RXFE2_2_BIAS_OTA_SHORTR_LSB) & CHN7_RXFE2_2_BIAS_OTA_SHORTR_MASK)
#define CHN7_RXFE2_2_BIAS_OTA_SHORTR_RESET                                     0x1
#define CHN7_RXFE2_2_RXLO2_CTRL_LSB                                            5
#define CHN7_RXFE2_2_RXLO2_CTRL_MSB                                            7
#define CHN7_RXFE2_2_RXLO2_CTRL_MASK                                           0xe0
#define CHN7_RXFE2_2_RXLO2_CTRL_GET(x)                                         (((x) & CHN7_RXFE2_2_RXLO2_CTRL_MASK) >> CHN7_RXFE2_2_RXLO2_CTRL_LSB)
#define CHN7_RXFE2_2_RXLO2_CTRL_SET(x)                                         (((0 | (x)) << CHN7_RXFE2_2_RXLO2_CTRL_LSB) & CHN7_RXFE2_2_RXLO2_CTRL_MASK)
#define CHN7_RXFE2_2_RXLO2_CTRL_RESET                                          0x0
#define CHN7_RXFE2_2_RESERVED_0_LSB                                            4
#define CHN7_RXFE2_2_RESERVED_0_MSB                                            4
#define CHN7_RXFE2_2_RESERVED_0_MASK                                           0x10
#define CHN7_RXFE2_2_RESERVED_0_GET(x)                                         (((x) & CHN7_RXFE2_2_RESERVED_0_MASK) >> CHN7_RXFE2_2_RESERVED_0_LSB)
#define CHN7_RXFE2_2_RESERVED_0_SET(x)                                         (((0 | (x)) << CHN7_RXFE2_2_RESERVED_0_LSB) & CHN7_RXFE2_2_RESERVED_0_MASK)
#define CHN7_RXFE2_2_RESERVED_0_RESET                                          0x0
#define CHN7_RXFE2_2_ATBSEL_RX2_LSB                                            0
#define CHN7_RXFE2_2_ATBSEL_RX2_MSB                                            3
#define CHN7_RXFE2_2_ATBSEL_RX2_MASK                                           0xf
#define CHN7_RXFE2_2_ATBSEL_RX2_GET(x)                                         (((x) & CHN7_RXFE2_2_ATBSEL_RX2_MASK) >> CHN7_RXFE2_2_ATBSEL_RX2_LSB)
#define CHN7_RXFE2_2_ATBSEL_RX2_SET(x)                                         (((0 | (x)) << CHN7_RXFE2_2_ATBSEL_RX2_LSB) & CHN7_RXFE2_2_ATBSEL_RX2_MASK)
#define CHN7_RXFE2_2_ATBSEL_RX2_RESET                                          0x0
#define CHN7_RXFE2_2_ADDRESS                                                   (0x8 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_RXFE2_2_RSTMASK                                                   0xffffffff
#define CHN7_RXFE2_2_RESET                                                     0x44080100

// 0xc (CHN7_RXFE2_3)
#define CHN7_RXFE2_3_RXFE2G_SPARE_LSB                                          0
#define CHN7_RXFE2_3_RXFE2G_SPARE_MSB                                          31
#define CHN7_RXFE2_3_RXFE2G_SPARE_MASK                                         0xffffffff
#define CHN7_RXFE2_3_RXFE2G_SPARE_GET(x)                                       (((x) & CHN7_RXFE2_3_RXFE2G_SPARE_MASK) >> CHN7_RXFE2_3_RXFE2G_SPARE_LSB)
#define CHN7_RXFE2_3_RXFE2G_SPARE_SET(x)                                       (((0 | (x)) << CHN7_RXFE2_3_RXFE2G_SPARE_LSB) & CHN7_RXFE2_3_RXFE2G_SPARE_MASK)
#define CHN7_RXFE2_3_RXFE2G_SPARE_RESET                                        0x0
#define CHN7_RXFE2_3_ADDRESS                                                   (0xc + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_RXFE2_3_RSTMASK                                                   0xffffffff
#define CHN7_RXFE2_3_RESET                                                     0x0

// 0x10 (CHN7_LNA2_0)
#define CHN7_LNA2_0_G0_GP_LSB                                                  24
#define CHN7_LNA2_0_G0_GP_MSB                                                  31
#define CHN7_LNA2_0_G0_GP_MASK                                                 0xff000000
#define CHN7_LNA2_0_G0_GP_GET(x)                                               (((x) & CHN7_LNA2_0_G0_GP_MASK) >> CHN7_LNA2_0_G0_GP_LSB)
#define CHN7_LNA2_0_G0_GP_SET(x)                                               (((0 | (x)) << CHN7_LNA2_0_G0_GP_LSB) & CHN7_LNA2_0_G0_GP_MASK)
#define CHN7_LNA2_0_G0_GP_RESET                                                0x2
#define CHN7_LNA2_0_RESERVED_0_LSB                                             16
#define CHN7_LNA2_0_RESERVED_0_MSB                                             23
#define CHN7_LNA2_0_RESERVED_0_MASK                                            0xff0000
#define CHN7_LNA2_0_RESERVED_0_GET(x)                                          (((x) & CHN7_LNA2_0_RESERVED_0_MASK) >> CHN7_LNA2_0_RESERVED_0_LSB)
#define CHN7_LNA2_0_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN7_LNA2_0_RESERVED_0_LSB) & CHN7_LNA2_0_RESERVED_0_MASK)
#define CHN7_LNA2_0_RESERVED_0_RESET                                           0x0
#define CHN7_LNA2_0_G0_INPCTUNE_LSB                                            13
#define CHN7_LNA2_0_G0_INPCTUNE_MSB                                            15
#define CHN7_LNA2_0_G0_INPCTUNE_MASK                                           0xe000
#define CHN7_LNA2_0_G0_INPCTUNE_GET(x)                                         (((x) & CHN7_LNA2_0_G0_INPCTUNE_MASK) >> CHN7_LNA2_0_G0_INPCTUNE_LSB)
#define CHN7_LNA2_0_G0_INPCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_0_G0_INPCTUNE_LSB) & CHN7_LNA2_0_G0_INPCTUNE_MASK)
#define CHN7_LNA2_0_G0_INPCTUNE_RESET                                          0x2
#define CHN7_LNA2_0_G0_OUTCTUNE_LSB                                            9
#define CHN7_LNA2_0_G0_OUTCTUNE_MSB                                            12
#define CHN7_LNA2_0_G0_OUTCTUNE_MASK                                           0x1e00
#define CHN7_LNA2_0_G0_OUTCTUNE_GET(x)                                         (((x) & CHN7_LNA2_0_G0_OUTCTUNE_MASK) >> CHN7_LNA2_0_G0_OUTCTUNE_LSB)
#define CHN7_LNA2_0_G0_OUTCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_0_G0_OUTCTUNE_LSB) & CHN7_LNA2_0_G0_OUTCTUNE_MASK)
#define CHN7_LNA2_0_G0_OUTCTUNE_RESET                                          0x7
#define CHN7_LNA2_0_G0_IBIAS_CTRL_LSB                                          2
#define CHN7_LNA2_0_G0_IBIAS_CTRL_MSB                                          8
#define CHN7_LNA2_0_G0_IBIAS_CTRL_MASK                                         0x1fc
#define CHN7_LNA2_0_G0_IBIAS_CTRL_GET(x)                                       (((x) & CHN7_LNA2_0_G0_IBIAS_CTRL_MASK) >> CHN7_LNA2_0_G0_IBIAS_CTRL_LSB)
#define CHN7_LNA2_0_G0_IBIAS_CTRL_SET(x)                                       (((0 | (x)) << CHN7_LNA2_0_G0_IBIAS_CTRL_LSB) & CHN7_LNA2_0_G0_IBIAS_CTRL_MASK)
#define CHN7_LNA2_0_G0_IBIAS_CTRL_RESET                                        0x39
#define CHN7_LNA2_0_G0_SHUNT_MATCH_LSB                                         0
#define CHN7_LNA2_0_G0_SHUNT_MATCH_MSB                                         1
#define CHN7_LNA2_0_G0_SHUNT_MATCH_MASK                                        0x3
#define CHN7_LNA2_0_G0_SHUNT_MATCH_GET(x)                                      (((x) & CHN7_LNA2_0_G0_SHUNT_MATCH_MASK) >> CHN7_LNA2_0_G0_SHUNT_MATCH_LSB)
#define CHN7_LNA2_0_G0_SHUNT_MATCH_SET(x)                                      (((0 | (x)) << CHN7_LNA2_0_G0_SHUNT_MATCH_LSB) & CHN7_LNA2_0_G0_SHUNT_MATCH_MASK)
#define CHN7_LNA2_0_G0_SHUNT_MATCH_RESET                                       0x1
#define CHN7_LNA2_0_ADDRESS                                                    (0x10 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_LNA2_0_RSTMASK                                                    0xffffffff
#define CHN7_LNA2_0_RESET                                                      0x2004ee5

// 0x14 (CHN7_LNA2_1)
#define CHN7_LNA2_1_G1_GP_LSB                                                  24
#define CHN7_LNA2_1_G1_GP_MSB                                                  31
#define CHN7_LNA2_1_G1_GP_MASK                                                 0xff000000
#define CHN7_LNA2_1_G1_GP_GET(x)                                               (((x) & CHN7_LNA2_1_G1_GP_MASK) >> CHN7_LNA2_1_G1_GP_LSB)
#define CHN7_LNA2_1_G1_GP_SET(x)                                               (((0 | (x)) << CHN7_LNA2_1_G1_GP_LSB) & CHN7_LNA2_1_G1_GP_MASK)
#define CHN7_LNA2_1_G1_GP_RESET                                                0x3
#define CHN7_LNA2_1_RESERVED_0_LSB                                             16
#define CHN7_LNA2_1_RESERVED_0_MSB                                             23
#define CHN7_LNA2_1_RESERVED_0_MASK                                            0xff0000
#define CHN7_LNA2_1_RESERVED_0_GET(x)                                          (((x) & CHN7_LNA2_1_RESERVED_0_MASK) >> CHN7_LNA2_1_RESERVED_0_LSB)
#define CHN7_LNA2_1_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN7_LNA2_1_RESERVED_0_LSB) & CHN7_LNA2_1_RESERVED_0_MASK)
#define CHN7_LNA2_1_RESERVED_0_RESET                                           0x0
#define CHN7_LNA2_1_G1_INPCTUNE_LSB                                            13
#define CHN7_LNA2_1_G1_INPCTUNE_MSB                                            15
#define CHN7_LNA2_1_G1_INPCTUNE_MASK                                           0xe000
#define CHN7_LNA2_1_G1_INPCTUNE_GET(x)                                         (((x) & CHN7_LNA2_1_G1_INPCTUNE_MASK) >> CHN7_LNA2_1_G1_INPCTUNE_LSB)
#define CHN7_LNA2_1_G1_INPCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_1_G1_INPCTUNE_LSB) & CHN7_LNA2_1_G1_INPCTUNE_MASK)
#define CHN7_LNA2_1_G1_INPCTUNE_RESET                                          0x2
#define CHN7_LNA2_1_G1_OUTCTUNE_LSB                                            9
#define CHN7_LNA2_1_G1_OUTCTUNE_MSB                                            12
#define CHN7_LNA2_1_G1_OUTCTUNE_MASK                                           0x1e00
#define CHN7_LNA2_1_G1_OUTCTUNE_GET(x)                                         (((x) & CHN7_LNA2_1_G1_OUTCTUNE_MASK) >> CHN7_LNA2_1_G1_OUTCTUNE_LSB)
#define CHN7_LNA2_1_G1_OUTCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_1_G1_OUTCTUNE_LSB) & CHN7_LNA2_1_G1_OUTCTUNE_MASK)
#define CHN7_LNA2_1_G1_OUTCTUNE_RESET                                          0x7
#define CHN7_LNA2_1_G1_IBIAS_CTRL_LSB                                          2
#define CHN7_LNA2_1_G1_IBIAS_CTRL_MSB                                          8
#define CHN7_LNA2_1_G1_IBIAS_CTRL_MASK                                         0x1fc
#define CHN7_LNA2_1_G1_IBIAS_CTRL_GET(x)                                       (((x) & CHN7_LNA2_1_G1_IBIAS_CTRL_MASK) >> CHN7_LNA2_1_G1_IBIAS_CTRL_LSB)
#define CHN7_LNA2_1_G1_IBIAS_CTRL_SET(x)                                       (((0 | (x)) << CHN7_LNA2_1_G1_IBIAS_CTRL_LSB) & CHN7_LNA2_1_G1_IBIAS_CTRL_MASK)
#define CHN7_LNA2_1_G1_IBIAS_CTRL_RESET                                        0x64
#define CHN7_LNA2_1_G1_SHUNT_MATCH_LSB                                         0
#define CHN7_LNA2_1_G1_SHUNT_MATCH_MSB                                         1
#define CHN7_LNA2_1_G1_SHUNT_MATCH_MASK                                        0x3
#define CHN7_LNA2_1_G1_SHUNT_MATCH_GET(x)                                      (((x) & CHN7_LNA2_1_G1_SHUNT_MATCH_MASK) >> CHN7_LNA2_1_G1_SHUNT_MATCH_LSB)
#define CHN7_LNA2_1_G1_SHUNT_MATCH_SET(x)                                      (((0 | (x)) << CHN7_LNA2_1_G1_SHUNT_MATCH_LSB) & CHN7_LNA2_1_G1_SHUNT_MATCH_MASK)
#define CHN7_LNA2_1_G1_SHUNT_MATCH_RESET                                       0x1
#define CHN7_LNA2_1_ADDRESS                                                    (0x14 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_LNA2_1_RSTMASK                                                    0xffffffff
#define CHN7_LNA2_1_RESET                                                      0x3004f91

// 0x18 (CHN7_LNA2_2)
#define CHN7_LNA2_2_G2_GP_LSB                                                  24
#define CHN7_LNA2_2_G2_GP_MSB                                                  31
#define CHN7_LNA2_2_G2_GP_MASK                                                 0xff000000
#define CHN7_LNA2_2_G2_GP_GET(x)                                               (((x) & CHN7_LNA2_2_G2_GP_MASK) >> CHN7_LNA2_2_G2_GP_LSB)
#define CHN7_LNA2_2_G2_GP_SET(x)                                               (((0 | (x)) << CHN7_LNA2_2_G2_GP_LSB) & CHN7_LNA2_2_G2_GP_MASK)
#define CHN7_LNA2_2_G2_GP_RESET                                                0x7
#define CHN7_LNA2_2_RESERVED_0_LSB                                             16
#define CHN7_LNA2_2_RESERVED_0_MSB                                             23
#define CHN7_LNA2_2_RESERVED_0_MASK                                            0xff0000
#define CHN7_LNA2_2_RESERVED_0_GET(x)                                          (((x) & CHN7_LNA2_2_RESERVED_0_MASK) >> CHN7_LNA2_2_RESERVED_0_LSB)
#define CHN7_LNA2_2_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN7_LNA2_2_RESERVED_0_LSB) & CHN7_LNA2_2_RESERVED_0_MASK)
#define CHN7_LNA2_2_RESERVED_0_RESET                                           0x0
#define CHN7_LNA2_2_G2_INPCTUNE_LSB                                            13
#define CHN7_LNA2_2_G2_INPCTUNE_MSB                                            15
#define CHN7_LNA2_2_G2_INPCTUNE_MASK                                           0xe000
#define CHN7_LNA2_2_G2_INPCTUNE_GET(x)                                         (((x) & CHN7_LNA2_2_G2_INPCTUNE_MASK) >> CHN7_LNA2_2_G2_INPCTUNE_LSB)
#define CHN7_LNA2_2_G2_INPCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_2_G2_INPCTUNE_LSB) & CHN7_LNA2_2_G2_INPCTUNE_MASK)
#define CHN7_LNA2_2_G2_INPCTUNE_RESET                                          0x2
#define CHN7_LNA2_2_G2_OUTCTUNE_LSB                                            9
#define CHN7_LNA2_2_G2_OUTCTUNE_MSB                                            12
#define CHN7_LNA2_2_G2_OUTCTUNE_MASK                                           0x1e00
#define CHN7_LNA2_2_G2_OUTCTUNE_GET(x)                                         (((x) & CHN7_LNA2_2_G2_OUTCTUNE_MASK) >> CHN7_LNA2_2_G2_OUTCTUNE_LSB)
#define CHN7_LNA2_2_G2_OUTCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_2_G2_OUTCTUNE_LSB) & CHN7_LNA2_2_G2_OUTCTUNE_MASK)
#define CHN7_LNA2_2_G2_OUTCTUNE_RESET                                          0x7
#define CHN7_LNA2_2_G2_IBIAS_CTRL_LSB                                          2
#define CHN7_LNA2_2_G2_IBIAS_CTRL_MSB                                          8
#define CHN7_LNA2_2_G2_IBIAS_CTRL_MASK                                         0x1fc
#define CHN7_LNA2_2_G2_IBIAS_CTRL_GET(x)                                       (((x) & CHN7_LNA2_2_G2_IBIAS_CTRL_MASK) >> CHN7_LNA2_2_G2_IBIAS_CTRL_LSB)
#define CHN7_LNA2_2_G2_IBIAS_CTRL_SET(x)                                       (((0 | (x)) << CHN7_LNA2_2_G2_IBIAS_CTRL_LSB) & CHN7_LNA2_2_G2_IBIAS_CTRL_MASK)
#define CHN7_LNA2_2_G2_IBIAS_CTRL_RESET                                        0x53
#define CHN7_LNA2_2_G2_SHUNT_MATCH_LSB                                         0
#define CHN7_LNA2_2_G2_SHUNT_MATCH_MSB                                         1
#define CHN7_LNA2_2_G2_SHUNT_MATCH_MASK                                        0x3
#define CHN7_LNA2_2_G2_SHUNT_MATCH_GET(x)                                      (((x) & CHN7_LNA2_2_G2_SHUNT_MATCH_MASK) >> CHN7_LNA2_2_G2_SHUNT_MATCH_LSB)
#define CHN7_LNA2_2_G2_SHUNT_MATCH_SET(x)                                      (((0 | (x)) << CHN7_LNA2_2_G2_SHUNT_MATCH_LSB) & CHN7_LNA2_2_G2_SHUNT_MATCH_MASK)
#define CHN7_LNA2_2_G2_SHUNT_MATCH_RESET                                       0x1
#define CHN7_LNA2_2_ADDRESS                                                    (0x18 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_LNA2_2_RSTMASK                                                    0xffffffff
#define CHN7_LNA2_2_RESET                                                      0x7004f4d

// 0x1c (CHN7_LNA2_3)
#define CHN7_LNA2_3_G3_GP_LSB                                                  24
#define CHN7_LNA2_3_G3_GP_MSB                                                  31
#define CHN7_LNA2_3_G3_GP_MASK                                                 0xff000000
#define CHN7_LNA2_3_G3_GP_GET(x)                                               (((x) & CHN7_LNA2_3_G3_GP_MASK) >> CHN7_LNA2_3_G3_GP_LSB)
#define CHN7_LNA2_3_G3_GP_SET(x)                                               (((0 | (x)) << CHN7_LNA2_3_G3_GP_LSB) & CHN7_LNA2_3_G3_GP_MASK)
#define CHN7_LNA2_3_G3_GP_RESET                                                0xf
#define CHN7_LNA2_3_RESERVED_0_LSB                                             16
#define CHN7_LNA2_3_RESERVED_0_MSB                                             23
#define CHN7_LNA2_3_RESERVED_0_MASK                                            0xff0000
#define CHN7_LNA2_3_RESERVED_0_GET(x)                                          (((x) & CHN7_LNA2_3_RESERVED_0_MASK) >> CHN7_LNA2_3_RESERVED_0_LSB)
#define CHN7_LNA2_3_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN7_LNA2_3_RESERVED_0_LSB) & CHN7_LNA2_3_RESERVED_0_MASK)
#define CHN7_LNA2_3_RESERVED_0_RESET                                           0x0
#define CHN7_LNA2_3_G3_INPCTUNE_LSB                                            13
#define CHN7_LNA2_3_G3_INPCTUNE_MSB                                            15
#define CHN7_LNA2_3_G3_INPCTUNE_MASK                                           0xe000
#define CHN7_LNA2_3_G3_INPCTUNE_GET(x)                                         (((x) & CHN7_LNA2_3_G3_INPCTUNE_MASK) >> CHN7_LNA2_3_G3_INPCTUNE_LSB)
#define CHN7_LNA2_3_G3_INPCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_3_G3_INPCTUNE_LSB) & CHN7_LNA2_3_G3_INPCTUNE_MASK)
#define CHN7_LNA2_3_G3_INPCTUNE_RESET                                          0x2
#define CHN7_LNA2_3_G3_OUTCTUNE_LSB                                            9
#define CHN7_LNA2_3_G3_OUTCTUNE_MSB                                            12
#define CHN7_LNA2_3_G3_OUTCTUNE_MASK                                           0x1e00
#define CHN7_LNA2_3_G3_OUTCTUNE_GET(x)                                         (((x) & CHN7_LNA2_3_G3_OUTCTUNE_MASK) >> CHN7_LNA2_3_G3_OUTCTUNE_LSB)
#define CHN7_LNA2_3_G3_OUTCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_3_G3_OUTCTUNE_LSB) & CHN7_LNA2_3_G3_OUTCTUNE_MASK)
#define CHN7_LNA2_3_G3_OUTCTUNE_RESET                                          0x7
#define CHN7_LNA2_3_G3_IBIAS_CTRL_LSB                                          2
#define CHN7_LNA2_3_G3_IBIAS_CTRL_MSB                                          8
#define CHN7_LNA2_3_G3_IBIAS_CTRL_MASK                                         0x1fc
#define CHN7_LNA2_3_G3_IBIAS_CTRL_GET(x)                                       (((x) & CHN7_LNA2_3_G3_IBIAS_CTRL_MASK) >> CHN7_LNA2_3_G3_IBIAS_CTRL_LSB)
#define CHN7_LNA2_3_G3_IBIAS_CTRL_SET(x)                                       (((0 | (x)) << CHN7_LNA2_3_G3_IBIAS_CTRL_LSB) & CHN7_LNA2_3_G3_IBIAS_CTRL_MASK)
#define CHN7_LNA2_3_G3_IBIAS_CTRL_RESET                                        0x47
#define CHN7_LNA2_3_G3_SHUNT_MATCH_LSB                                         0
#define CHN7_LNA2_3_G3_SHUNT_MATCH_MSB                                         1
#define CHN7_LNA2_3_G3_SHUNT_MATCH_MASK                                        0x3
#define CHN7_LNA2_3_G3_SHUNT_MATCH_GET(x)                                      (((x) & CHN7_LNA2_3_G3_SHUNT_MATCH_MASK) >> CHN7_LNA2_3_G3_SHUNT_MATCH_LSB)
#define CHN7_LNA2_3_G3_SHUNT_MATCH_SET(x)                                      (((0 | (x)) << CHN7_LNA2_3_G3_SHUNT_MATCH_LSB) & CHN7_LNA2_3_G3_SHUNT_MATCH_MASK)
#define CHN7_LNA2_3_G3_SHUNT_MATCH_RESET                                       0x1
#define CHN7_LNA2_3_ADDRESS                                                    (0x1c + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_LNA2_3_RSTMASK                                                    0xffffffff
#define CHN7_LNA2_3_RESET                                                      0xf004f1d

// 0x20 (CHN7_LNA2_4)
#define CHN7_LNA2_4_G4_GP_LSB                                                  24
#define CHN7_LNA2_4_G4_GP_MSB                                                  31
#define CHN7_LNA2_4_G4_GP_MASK                                                 0xff000000
#define CHN7_LNA2_4_G4_GP_GET(x)                                               (((x) & CHN7_LNA2_4_G4_GP_MASK) >> CHN7_LNA2_4_G4_GP_LSB)
#define CHN7_LNA2_4_G4_GP_SET(x)                                               (((0 | (x)) << CHN7_LNA2_4_G4_GP_LSB) & CHN7_LNA2_4_G4_GP_MASK)
#define CHN7_LNA2_4_G4_GP_RESET                                                0x4
#define CHN7_LNA2_4_RESERVED_0_LSB                                             16
#define CHN7_LNA2_4_RESERVED_0_MSB                                             23
#define CHN7_LNA2_4_RESERVED_0_MASK                                            0xff0000
#define CHN7_LNA2_4_RESERVED_0_GET(x)                                          (((x) & CHN7_LNA2_4_RESERVED_0_MASK) >> CHN7_LNA2_4_RESERVED_0_LSB)
#define CHN7_LNA2_4_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN7_LNA2_4_RESERVED_0_LSB) & CHN7_LNA2_4_RESERVED_0_MASK)
#define CHN7_LNA2_4_RESERVED_0_RESET                                           0x0
#define CHN7_LNA2_4_G4_INPCTUNE_LSB                                            13
#define CHN7_LNA2_4_G4_INPCTUNE_MSB                                            15
#define CHN7_LNA2_4_G4_INPCTUNE_MASK                                           0xe000
#define CHN7_LNA2_4_G4_INPCTUNE_GET(x)                                         (((x) & CHN7_LNA2_4_G4_INPCTUNE_MASK) >> CHN7_LNA2_4_G4_INPCTUNE_LSB)
#define CHN7_LNA2_4_G4_INPCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_4_G4_INPCTUNE_LSB) & CHN7_LNA2_4_G4_INPCTUNE_MASK)
#define CHN7_LNA2_4_G4_INPCTUNE_RESET                                          0x2
#define CHN7_LNA2_4_G4_OUTCTUNE_LSB                                            9
#define CHN7_LNA2_4_G4_OUTCTUNE_MSB                                            12
#define CHN7_LNA2_4_G4_OUTCTUNE_MASK                                           0x1e00
#define CHN7_LNA2_4_G4_OUTCTUNE_GET(x)                                         (((x) & CHN7_LNA2_4_G4_OUTCTUNE_MASK) >> CHN7_LNA2_4_G4_OUTCTUNE_LSB)
#define CHN7_LNA2_4_G4_OUTCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_4_G4_OUTCTUNE_LSB) & CHN7_LNA2_4_G4_OUTCTUNE_MASK)
#define CHN7_LNA2_4_G4_OUTCTUNE_RESET                                          0x7
#define CHN7_LNA2_4_G4_IBIAS_CTRL_LSB                                          2
#define CHN7_LNA2_4_G4_IBIAS_CTRL_MSB                                          8
#define CHN7_LNA2_4_G4_IBIAS_CTRL_MASK                                         0x1fc
#define CHN7_LNA2_4_G4_IBIAS_CTRL_GET(x)                                       (((x) & CHN7_LNA2_4_G4_IBIAS_CTRL_MASK) >> CHN7_LNA2_4_G4_IBIAS_CTRL_LSB)
#define CHN7_LNA2_4_G4_IBIAS_CTRL_SET(x)                                       (((0 | (x)) << CHN7_LNA2_4_G4_IBIAS_CTRL_LSB) & CHN7_LNA2_4_G4_IBIAS_CTRL_MASK)
#define CHN7_LNA2_4_G4_IBIAS_CTRL_RESET                                        0x32
#define CHN7_LNA2_4_G4_SHUNT_MATCH_LSB                                         0
#define CHN7_LNA2_4_G4_SHUNT_MATCH_MSB                                         1
#define CHN7_LNA2_4_G4_SHUNT_MATCH_MASK                                        0x3
#define CHN7_LNA2_4_G4_SHUNT_MATCH_GET(x)                                      (((x) & CHN7_LNA2_4_G4_SHUNT_MATCH_MASK) >> CHN7_LNA2_4_G4_SHUNT_MATCH_LSB)
#define CHN7_LNA2_4_G4_SHUNT_MATCH_SET(x)                                      (((0 | (x)) << CHN7_LNA2_4_G4_SHUNT_MATCH_LSB) & CHN7_LNA2_4_G4_SHUNT_MATCH_MASK)
#define CHN7_LNA2_4_G4_SHUNT_MATCH_RESET                                       0x0
#define CHN7_LNA2_4_ADDRESS                                                    (0x20 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_LNA2_4_RSTMASK                                                    0xffffffff
#define CHN7_LNA2_4_RESET                                                      0x4004ec8

// 0x24 (CHN7_LNA2_5)
#define CHN7_LNA2_5_G5_GP_LSB                                                  24
#define CHN7_LNA2_5_G5_GP_MSB                                                  31
#define CHN7_LNA2_5_G5_GP_MASK                                                 0xff000000
#define CHN7_LNA2_5_G5_GP_GET(x)                                               (((x) & CHN7_LNA2_5_G5_GP_MASK) >> CHN7_LNA2_5_G5_GP_LSB)
#define CHN7_LNA2_5_G5_GP_SET(x)                                               (((0 | (x)) << CHN7_LNA2_5_G5_GP_LSB) & CHN7_LNA2_5_G5_GP_MASK)
#define CHN7_LNA2_5_G5_GP_RESET                                                0x8
#define CHN7_LNA2_5_RESERVED_0_LSB                                             16
#define CHN7_LNA2_5_RESERVED_0_MSB                                             23
#define CHN7_LNA2_5_RESERVED_0_MASK                                            0xff0000
#define CHN7_LNA2_5_RESERVED_0_GET(x)                                          (((x) & CHN7_LNA2_5_RESERVED_0_MASK) >> CHN7_LNA2_5_RESERVED_0_LSB)
#define CHN7_LNA2_5_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN7_LNA2_5_RESERVED_0_LSB) & CHN7_LNA2_5_RESERVED_0_MASK)
#define CHN7_LNA2_5_RESERVED_0_RESET                                           0x0
#define CHN7_LNA2_5_G5_INPCTUNE_LSB                                            13
#define CHN7_LNA2_5_G5_INPCTUNE_MSB                                            15
#define CHN7_LNA2_5_G5_INPCTUNE_MASK                                           0xe000
#define CHN7_LNA2_5_G5_INPCTUNE_GET(x)                                         (((x) & CHN7_LNA2_5_G5_INPCTUNE_MASK) >> CHN7_LNA2_5_G5_INPCTUNE_LSB)
#define CHN7_LNA2_5_G5_INPCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_5_G5_INPCTUNE_LSB) & CHN7_LNA2_5_G5_INPCTUNE_MASK)
#define CHN7_LNA2_5_G5_INPCTUNE_RESET                                          0x2
#define CHN7_LNA2_5_G5_OUTCTUNE_LSB                                            9
#define CHN7_LNA2_5_G5_OUTCTUNE_MSB                                            12
#define CHN7_LNA2_5_G5_OUTCTUNE_MASK                                           0x1e00
#define CHN7_LNA2_5_G5_OUTCTUNE_GET(x)                                         (((x) & CHN7_LNA2_5_G5_OUTCTUNE_MASK) >> CHN7_LNA2_5_G5_OUTCTUNE_LSB)
#define CHN7_LNA2_5_G5_OUTCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_5_G5_OUTCTUNE_LSB) & CHN7_LNA2_5_G5_OUTCTUNE_MASK)
#define CHN7_LNA2_5_G5_OUTCTUNE_RESET                                          0x7
#define CHN7_LNA2_5_G5_IBIAS_CTRL_LSB                                          2
#define CHN7_LNA2_5_G5_IBIAS_CTRL_MSB                                          8
#define CHN7_LNA2_5_G5_IBIAS_CTRL_MASK                                         0x1fc
#define CHN7_LNA2_5_G5_IBIAS_CTRL_GET(x)                                       (((x) & CHN7_LNA2_5_G5_IBIAS_CTRL_MASK) >> CHN7_LNA2_5_G5_IBIAS_CTRL_LSB)
#define CHN7_LNA2_5_G5_IBIAS_CTRL_SET(x)                                       (((0 | (x)) << CHN7_LNA2_5_G5_IBIAS_CTRL_LSB) & CHN7_LNA2_5_G5_IBIAS_CTRL_MASK)
#define CHN7_LNA2_5_G5_IBIAS_CTRL_RESET                                        0x3b
#define CHN7_LNA2_5_G5_SHUNT_MATCH_LSB                                         0
#define CHN7_LNA2_5_G5_SHUNT_MATCH_MSB                                         1
#define CHN7_LNA2_5_G5_SHUNT_MATCH_MASK                                        0x3
#define CHN7_LNA2_5_G5_SHUNT_MATCH_GET(x)                                      (((x) & CHN7_LNA2_5_G5_SHUNT_MATCH_MASK) >> CHN7_LNA2_5_G5_SHUNT_MATCH_LSB)
#define CHN7_LNA2_5_G5_SHUNT_MATCH_SET(x)                                      (((0 | (x)) << CHN7_LNA2_5_G5_SHUNT_MATCH_LSB) & CHN7_LNA2_5_G5_SHUNT_MATCH_MASK)
#define CHN7_LNA2_5_G5_SHUNT_MATCH_RESET                                       0x0
#define CHN7_LNA2_5_ADDRESS                                                    (0x24 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_LNA2_5_RSTMASK                                                    0xffffffff
#define CHN7_LNA2_5_RESET                                                      0x8004eec

// 0x28 (CHN7_LNA2_6)
#define CHN7_LNA2_6_G6_GP_LSB                                                  24
#define CHN7_LNA2_6_G6_GP_MSB                                                  31
#define CHN7_LNA2_6_G6_GP_MASK                                                 0xff000000
#define CHN7_LNA2_6_G6_GP_GET(x)                                               (((x) & CHN7_LNA2_6_G6_GP_MASK) >> CHN7_LNA2_6_G6_GP_LSB)
#define CHN7_LNA2_6_G6_GP_SET(x)                                               (((0 | (x)) << CHN7_LNA2_6_G6_GP_LSB) & CHN7_LNA2_6_G6_GP_MASK)
#define CHN7_LNA2_6_G6_GP_RESET                                                0x11
#define CHN7_LNA2_6_RESERVED_0_LSB                                             16
#define CHN7_LNA2_6_RESERVED_0_MSB                                             23
#define CHN7_LNA2_6_RESERVED_0_MASK                                            0xff0000
#define CHN7_LNA2_6_RESERVED_0_GET(x)                                          (((x) & CHN7_LNA2_6_RESERVED_0_MASK) >> CHN7_LNA2_6_RESERVED_0_LSB)
#define CHN7_LNA2_6_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN7_LNA2_6_RESERVED_0_LSB) & CHN7_LNA2_6_RESERVED_0_MASK)
#define CHN7_LNA2_6_RESERVED_0_RESET                                           0x0
#define CHN7_LNA2_6_G6_INPCTUNE_LSB                                            13
#define CHN7_LNA2_6_G6_INPCTUNE_MSB                                            15
#define CHN7_LNA2_6_G6_INPCTUNE_MASK                                           0xe000
#define CHN7_LNA2_6_G6_INPCTUNE_GET(x)                                         (((x) & CHN7_LNA2_6_G6_INPCTUNE_MASK) >> CHN7_LNA2_6_G6_INPCTUNE_LSB)
#define CHN7_LNA2_6_G6_INPCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_6_G6_INPCTUNE_LSB) & CHN7_LNA2_6_G6_INPCTUNE_MASK)
#define CHN7_LNA2_6_G6_INPCTUNE_RESET                                          0x2
#define CHN7_LNA2_6_G6_OUTCTUNE_LSB                                            9
#define CHN7_LNA2_6_G6_OUTCTUNE_MSB                                            12
#define CHN7_LNA2_6_G6_OUTCTUNE_MASK                                           0x1e00
#define CHN7_LNA2_6_G6_OUTCTUNE_GET(x)                                         (((x) & CHN7_LNA2_6_G6_OUTCTUNE_MASK) >> CHN7_LNA2_6_G6_OUTCTUNE_LSB)
#define CHN7_LNA2_6_G6_OUTCTUNE_SET(x)                                         (((0 | (x)) << CHN7_LNA2_6_G6_OUTCTUNE_LSB) & CHN7_LNA2_6_G6_OUTCTUNE_MASK)
#define CHN7_LNA2_6_G6_OUTCTUNE_RESET                                          0x7
#define CHN7_LNA2_6_G6_IBIAS_CTRL_LSB                                          2
#define CHN7_LNA2_6_G6_IBIAS_CTRL_MSB                                          8
#define CHN7_LNA2_6_G6_IBIAS_CTRL_MASK                                         0x1fc
#define CHN7_LNA2_6_G6_IBIAS_CTRL_GET(x)                                       (((x) & CHN7_LNA2_6_G6_IBIAS_CTRL_MASK) >> CHN7_LNA2_6_G6_IBIAS_CTRL_LSB)
#define CHN7_LNA2_6_G6_IBIAS_CTRL_SET(x)                                       (((0 | (x)) << CHN7_LNA2_6_G6_IBIAS_CTRL_LSB) & CHN7_LNA2_6_G6_IBIAS_CTRL_MASK)
#define CHN7_LNA2_6_G6_IBIAS_CTRL_RESET                                        0x46
#define CHN7_LNA2_6_G6_SHUNT_MATCH_LSB                                         0
#define CHN7_LNA2_6_G6_SHUNT_MATCH_MSB                                         1
#define CHN7_LNA2_6_G6_SHUNT_MATCH_MASK                                        0x3
#define CHN7_LNA2_6_G6_SHUNT_MATCH_GET(x)                                      (((x) & CHN7_LNA2_6_G6_SHUNT_MATCH_MASK) >> CHN7_LNA2_6_G6_SHUNT_MATCH_LSB)
#define CHN7_LNA2_6_G6_SHUNT_MATCH_SET(x)                                      (((0 | (x)) << CHN7_LNA2_6_G6_SHUNT_MATCH_LSB) & CHN7_LNA2_6_G6_SHUNT_MATCH_MASK)
#define CHN7_LNA2_6_G6_SHUNT_MATCH_RESET                                       0x0
#define CHN7_LNA2_6_ADDRESS                                                    (0x28 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_LNA2_6_RSTMASK                                                    0xffffffff
#define CHN7_LNA2_6_RESET                                                      0x11004f18

// 0x2c (CHN7_LNA2_7)
#define CHN7_LNA2_7_G0_NGMIBIAS_CTRL_LSB                                       27
#define CHN7_LNA2_7_G0_NGMIBIAS_CTRL_MSB                                       31
#define CHN7_LNA2_7_G0_NGMIBIAS_CTRL_MASK                                      0xf8000000
#define CHN7_LNA2_7_G0_NGMIBIAS_CTRL_GET(x)                                    (((x) & CHN7_LNA2_7_G0_NGMIBIAS_CTRL_MASK) >> CHN7_LNA2_7_G0_NGMIBIAS_CTRL_LSB)
#define CHN7_LNA2_7_G0_NGMIBIAS_CTRL_SET(x)                                    (((0 | (x)) << CHN7_LNA2_7_G0_NGMIBIAS_CTRL_LSB) & CHN7_LNA2_7_G0_NGMIBIAS_CTRL_MASK)
#define CHN7_LNA2_7_G0_NGMIBIAS_CTRL_RESET                                     0x0
#define CHN7_LNA2_7_G0_ATTEN_CAP_LSB                                           25
#define CHN7_LNA2_7_G0_ATTEN_CAP_MSB                                           26
#define CHN7_LNA2_7_G0_ATTEN_CAP_MASK                                          0x6000000
#define CHN7_LNA2_7_G0_ATTEN_CAP_GET(x)                                        (((x) & CHN7_LNA2_7_G0_ATTEN_CAP_MASK) >> CHN7_LNA2_7_G0_ATTEN_CAP_LSB)
#define CHN7_LNA2_7_G0_ATTEN_CAP_SET(x)                                        (((0 | (x)) << CHN7_LNA2_7_G0_ATTEN_CAP_LSB) & CHN7_LNA2_7_G0_ATTEN_CAP_MASK)
#define CHN7_LNA2_7_G0_ATTEN_CAP_RESET                                         0x3
#define CHN7_LNA2_7_G0_AUX_EN_LSB                                              24
#define CHN7_LNA2_7_G0_AUX_EN_MSB                                              24
#define CHN7_LNA2_7_G0_AUX_EN_MASK                                             0x1000000
#define CHN7_LNA2_7_G0_AUX_EN_GET(x)                                           (((x) & CHN7_LNA2_7_G0_AUX_EN_MASK) >> CHN7_LNA2_7_G0_AUX_EN_LSB)
#define CHN7_LNA2_7_G0_AUX_EN_SET(x)                                           (((0 | (x)) << CHN7_LNA2_7_G0_AUX_EN_LSB) & CHN7_LNA2_7_G0_AUX_EN_MASK)
#define CHN7_LNA2_7_G0_AUX_EN_RESET                                            0x1
#define CHN7_LNA2_7_G1_NGMIBIAS_CTRL_LSB                                       19
#define CHN7_LNA2_7_G1_NGMIBIAS_CTRL_MSB                                       23
#define CHN7_LNA2_7_G1_NGMIBIAS_CTRL_MASK                                      0xf80000
#define CHN7_LNA2_7_G1_NGMIBIAS_CTRL_GET(x)                                    (((x) & CHN7_LNA2_7_G1_NGMIBIAS_CTRL_MASK) >> CHN7_LNA2_7_G1_NGMIBIAS_CTRL_LSB)
#define CHN7_LNA2_7_G1_NGMIBIAS_CTRL_SET(x)                                    (((0 | (x)) << CHN7_LNA2_7_G1_NGMIBIAS_CTRL_LSB) & CHN7_LNA2_7_G1_NGMIBIAS_CTRL_MASK)
#define CHN7_LNA2_7_G1_NGMIBIAS_CTRL_RESET                                     0x0
#define CHN7_LNA2_7_G1_ATTEN_CAP_LSB                                           17
#define CHN7_LNA2_7_G1_ATTEN_CAP_MSB                                           18
#define CHN7_LNA2_7_G1_ATTEN_CAP_MASK                                          0x60000
#define CHN7_LNA2_7_G1_ATTEN_CAP_GET(x)                                        (((x) & CHN7_LNA2_7_G1_ATTEN_CAP_MASK) >> CHN7_LNA2_7_G1_ATTEN_CAP_LSB)
#define CHN7_LNA2_7_G1_ATTEN_CAP_SET(x)                                        (((0 | (x)) << CHN7_LNA2_7_G1_ATTEN_CAP_LSB) & CHN7_LNA2_7_G1_ATTEN_CAP_MASK)
#define CHN7_LNA2_7_G1_ATTEN_CAP_RESET                                         0x3
#define CHN7_LNA2_7_G1_AUX_EN_LSB                                              16
#define CHN7_LNA2_7_G1_AUX_EN_MSB                                              16
#define CHN7_LNA2_7_G1_AUX_EN_MASK                                             0x10000
#define CHN7_LNA2_7_G1_AUX_EN_GET(x)                                           (((x) & CHN7_LNA2_7_G1_AUX_EN_MASK) >> CHN7_LNA2_7_G1_AUX_EN_LSB)
#define CHN7_LNA2_7_G1_AUX_EN_SET(x)                                           (((0 | (x)) << CHN7_LNA2_7_G1_AUX_EN_LSB) & CHN7_LNA2_7_G1_AUX_EN_MASK)
#define CHN7_LNA2_7_G1_AUX_EN_RESET                                            0x1
#define CHN7_LNA2_7_G2_NGMIBIAS_CTRL_LSB                                       11
#define CHN7_LNA2_7_G2_NGMIBIAS_CTRL_MSB                                       15
#define CHN7_LNA2_7_G2_NGMIBIAS_CTRL_MASK                                      0xf800
#define CHN7_LNA2_7_G2_NGMIBIAS_CTRL_GET(x)                                    (((x) & CHN7_LNA2_7_G2_NGMIBIAS_CTRL_MASK) >> CHN7_LNA2_7_G2_NGMIBIAS_CTRL_LSB)
#define CHN7_LNA2_7_G2_NGMIBIAS_CTRL_SET(x)                                    (((0 | (x)) << CHN7_LNA2_7_G2_NGMIBIAS_CTRL_LSB) & CHN7_LNA2_7_G2_NGMIBIAS_CTRL_MASK)
#define CHN7_LNA2_7_G2_NGMIBIAS_CTRL_RESET                                     0x0
#define CHN7_LNA2_7_G2_ATTEN_CAP_LSB                                           9
#define CHN7_LNA2_7_G2_ATTEN_CAP_MSB                                           10
#define CHN7_LNA2_7_G2_ATTEN_CAP_MASK                                          0x600
#define CHN7_LNA2_7_G2_ATTEN_CAP_GET(x)                                        (((x) & CHN7_LNA2_7_G2_ATTEN_CAP_MASK) >> CHN7_LNA2_7_G2_ATTEN_CAP_LSB)
#define CHN7_LNA2_7_G2_ATTEN_CAP_SET(x)                                        (((0 | (x)) << CHN7_LNA2_7_G2_ATTEN_CAP_LSB) & CHN7_LNA2_7_G2_ATTEN_CAP_MASK)
#define CHN7_LNA2_7_G2_ATTEN_CAP_RESET                                         0x3
#define CHN7_LNA2_7_G2_AUX_EN_LSB                                              8
#define CHN7_LNA2_7_G2_AUX_EN_MSB                                              8
#define CHN7_LNA2_7_G2_AUX_EN_MASK                                             0x100
#define CHN7_LNA2_7_G2_AUX_EN_GET(x)                                           (((x) & CHN7_LNA2_7_G2_AUX_EN_MASK) >> CHN7_LNA2_7_G2_AUX_EN_LSB)
#define CHN7_LNA2_7_G2_AUX_EN_SET(x)                                           (((0 | (x)) << CHN7_LNA2_7_G2_AUX_EN_LSB) & CHN7_LNA2_7_G2_AUX_EN_MASK)
#define CHN7_LNA2_7_G2_AUX_EN_RESET                                            0x1
#define CHN7_LNA2_7_G3_NGMIBIAS_CTRL_LSB                                       3
#define CHN7_LNA2_7_G3_NGMIBIAS_CTRL_MSB                                       7
#define CHN7_LNA2_7_G3_NGMIBIAS_CTRL_MASK                                      0xf8
#define CHN7_LNA2_7_G3_NGMIBIAS_CTRL_GET(x)                                    (((x) & CHN7_LNA2_7_G3_NGMIBIAS_CTRL_MASK) >> CHN7_LNA2_7_G3_NGMIBIAS_CTRL_LSB)
#define CHN7_LNA2_7_G3_NGMIBIAS_CTRL_SET(x)                                    (((0 | (x)) << CHN7_LNA2_7_G3_NGMIBIAS_CTRL_LSB) & CHN7_LNA2_7_G3_NGMIBIAS_CTRL_MASK)
#define CHN7_LNA2_7_G3_NGMIBIAS_CTRL_RESET                                     0x0
#define CHN7_LNA2_7_G3_ATTEN_CAP_LSB                                           1
#define CHN7_LNA2_7_G3_ATTEN_CAP_MSB                                           2
#define CHN7_LNA2_7_G3_ATTEN_CAP_MASK                                          0x6
#define CHN7_LNA2_7_G3_ATTEN_CAP_GET(x)                                        (((x) & CHN7_LNA2_7_G3_ATTEN_CAP_MASK) >> CHN7_LNA2_7_G3_ATTEN_CAP_LSB)
#define CHN7_LNA2_7_G3_ATTEN_CAP_SET(x)                                        (((0 | (x)) << CHN7_LNA2_7_G3_ATTEN_CAP_LSB) & CHN7_LNA2_7_G3_ATTEN_CAP_MASK)
#define CHN7_LNA2_7_G3_ATTEN_CAP_RESET                                         0x0
#define CHN7_LNA2_7_G3_AUX_EN_LSB                                              0
#define CHN7_LNA2_7_G3_AUX_EN_MSB                                              0
#define CHN7_LNA2_7_G3_AUX_EN_MASK                                             0x1
#define CHN7_LNA2_7_G3_AUX_EN_GET(x)                                           (((x) & CHN7_LNA2_7_G3_AUX_EN_MASK) >> CHN7_LNA2_7_G3_AUX_EN_LSB)
#define CHN7_LNA2_7_G3_AUX_EN_SET(x)                                           (((0 | (x)) << CHN7_LNA2_7_G3_AUX_EN_LSB) & CHN7_LNA2_7_G3_AUX_EN_MASK)
#define CHN7_LNA2_7_G3_AUX_EN_RESET                                            0x1
#define CHN7_LNA2_7_ADDRESS                                                    (0x2c + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_LNA2_7_RSTMASK                                                    0xffffffff
#define CHN7_LNA2_7_RESET                                                      0x7070701

// 0x30 (CHN7_LNA2_8)
#define CHN7_LNA2_8_G4_NGMIBIAS_CTRL_LSB                                       27
#define CHN7_LNA2_8_G4_NGMIBIAS_CTRL_MSB                                       31
#define CHN7_LNA2_8_G4_NGMIBIAS_CTRL_MASK                                      0xf8000000
#define CHN7_LNA2_8_G4_NGMIBIAS_CTRL_GET(x)                                    (((x) & CHN7_LNA2_8_G4_NGMIBIAS_CTRL_MASK) >> CHN7_LNA2_8_G4_NGMIBIAS_CTRL_LSB)
#define CHN7_LNA2_8_G4_NGMIBIAS_CTRL_SET(x)                                    (((0 | (x)) << CHN7_LNA2_8_G4_NGMIBIAS_CTRL_LSB) & CHN7_LNA2_8_G4_NGMIBIAS_CTRL_MASK)
#define CHN7_LNA2_8_G4_NGMIBIAS_CTRL_RESET                                     0x0
#define CHN7_LNA2_8_G4_ATTEN_CAP_LSB                                           25
#define CHN7_LNA2_8_G4_ATTEN_CAP_MSB                                           26
#define CHN7_LNA2_8_G4_ATTEN_CAP_MASK                                          0x6000000
#define CHN7_LNA2_8_G4_ATTEN_CAP_GET(x)                                        (((x) & CHN7_LNA2_8_G4_ATTEN_CAP_MASK) >> CHN7_LNA2_8_G4_ATTEN_CAP_LSB)
#define CHN7_LNA2_8_G4_ATTEN_CAP_SET(x)                                        (((0 | (x)) << CHN7_LNA2_8_G4_ATTEN_CAP_LSB) & CHN7_LNA2_8_G4_ATTEN_CAP_MASK)
#define CHN7_LNA2_8_G4_ATTEN_CAP_RESET                                         0x0
#define CHN7_LNA2_8_G4_AUX_EN_LSB                                              24
#define CHN7_LNA2_8_G4_AUX_EN_MSB                                              24
#define CHN7_LNA2_8_G4_AUX_EN_MASK                                             0x1000000
#define CHN7_LNA2_8_G4_AUX_EN_GET(x)                                           (((x) & CHN7_LNA2_8_G4_AUX_EN_MASK) >> CHN7_LNA2_8_G4_AUX_EN_LSB)
#define CHN7_LNA2_8_G4_AUX_EN_SET(x)                                           (((0 | (x)) << CHN7_LNA2_8_G4_AUX_EN_LSB) & CHN7_LNA2_8_G4_AUX_EN_MASK)
#define CHN7_LNA2_8_G4_AUX_EN_RESET                                            0x0
#define CHN7_LNA2_8_G5_NGMIBIAS_CTRL_LSB                                       19
#define CHN7_LNA2_8_G5_NGMIBIAS_CTRL_MSB                                       23
#define CHN7_LNA2_8_G5_NGMIBIAS_CTRL_MASK                                      0xf80000
#define CHN7_LNA2_8_G5_NGMIBIAS_CTRL_GET(x)                                    (((x) & CHN7_LNA2_8_G5_NGMIBIAS_CTRL_MASK) >> CHN7_LNA2_8_G5_NGMIBIAS_CTRL_LSB)
#define CHN7_LNA2_8_G5_NGMIBIAS_CTRL_SET(x)                                    (((0 | (x)) << CHN7_LNA2_8_G5_NGMIBIAS_CTRL_LSB) & CHN7_LNA2_8_G5_NGMIBIAS_CTRL_MASK)
#define CHN7_LNA2_8_G5_NGMIBIAS_CTRL_RESET                                     0x0
#define CHN7_LNA2_8_G5_ATTEN_CAP_LSB                                           17
#define CHN7_LNA2_8_G5_ATTEN_CAP_MSB                                           18
#define CHN7_LNA2_8_G5_ATTEN_CAP_MASK                                          0x60000
#define CHN7_LNA2_8_G5_ATTEN_CAP_GET(x)                                        (((x) & CHN7_LNA2_8_G5_ATTEN_CAP_MASK) >> CHN7_LNA2_8_G5_ATTEN_CAP_LSB)
#define CHN7_LNA2_8_G5_ATTEN_CAP_SET(x)                                        (((0 | (x)) << CHN7_LNA2_8_G5_ATTEN_CAP_LSB) & CHN7_LNA2_8_G5_ATTEN_CAP_MASK)
#define CHN7_LNA2_8_G5_ATTEN_CAP_RESET                                         0x0
#define CHN7_LNA2_8_G5_AUX_EN_LSB                                              16
#define CHN7_LNA2_8_G5_AUX_EN_MSB                                              16
#define CHN7_LNA2_8_G5_AUX_EN_MASK                                             0x10000
#define CHN7_LNA2_8_G5_AUX_EN_GET(x)                                           (((x) & CHN7_LNA2_8_G5_AUX_EN_MASK) >> CHN7_LNA2_8_G5_AUX_EN_LSB)
#define CHN7_LNA2_8_G5_AUX_EN_SET(x)                                           (((0 | (x)) << CHN7_LNA2_8_G5_AUX_EN_LSB) & CHN7_LNA2_8_G5_AUX_EN_MASK)
#define CHN7_LNA2_8_G5_AUX_EN_RESET                                            0x0
#define CHN7_LNA2_8_G6_NGMIBIAS_CTRL_LSB                                       11
#define CHN7_LNA2_8_G6_NGMIBIAS_CTRL_MSB                                       15
#define CHN7_LNA2_8_G6_NGMIBIAS_CTRL_MASK                                      0xf800
#define CHN7_LNA2_8_G6_NGMIBIAS_CTRL_GET(x)                                    (((x) & CHN7_LNA2_8_G6_NGMIBIAS_CTRL_MASK) >> CHN7_LNA2_8_G6_NGMIBIAS_CTRL_LSB)
#define CHN7_LNA2_8_G6_NGMIBIAS_CTRL_SET(x)                                    (((0 | (x)) << CHN7_LNA2_8_G6_NGMIBIAS_CTRL_LSB) & CHN7_LNA2_8_G6_NGMIBIAS_CTRL_MASK)
#define CHN7_LNA2_8_G6_NGMIBIAS_CTRL_RESET                                     0x0
#define CHN7_LNA2_8_G6_ATTEN_CAP_LSB                                           9
#define CHN7_LNA2_8_G6_ATTEN_CAP_MSB                                           10
#define CHN7_LNA2_8_G6_ATTEN_CAP_MASK                                          0x600
#define CHN7_LNA2_8_G6_ATTEN_CAP_GET(x)                                        (((x) & CHN7_LNA2_8_G6_ATTEN_CAP_MASK) >> CHN7_LNA2_8_G6_ATTEN_CAP_LSB)
#define CHN7_LNA2_8_G6_ATTEN_CAP_SET(x)                                        (((0 | (x)) << CHN7_LNA2_8_G6_ATTEN_CAP_LSB) & CHN7_LNA2_8_G6_ATTEN_CAP_MASK)
#define CHN7_LNA2_8_G6_ATTEN_CAP_RESET                                         0x0
#define CHN7_LNA2_8_G6_AUX_EN_LSB                                              8
#define CHN7_LNA2_8_G6_AUX_EN_MSB                                              8
#define CHN7_LNA2_8_G6_AUX_EN_MASK                                             0x100
#define CHN7_LNA2_8_G6_AUX_EN_GET(x)                                           (((x) & CHN7_LNA2_8_G6_AUX_EN_MASK) >> CHN7_LNA2_8_G6_AUX_EN_LSB)
#define CHN7_LNA2_8_G6_AUX_EN_SET(x)                                           (((0 | (x)) << CHN7_LNA2_8_G6_AUX_EN_LSB) & CHN7_LNA2_8_G6_AUX_EN_MASK)
#define CHN7_LNA2_8_G6_AUX_EN_RESET                                            0x0
#define CHN7_LNA2_8_RESERVED_0_LSB                                             0
#define CHN7_LNA2_8_RESERVED_0_MSB                                             7
#define CHN7_LNA2_8_RESERVED_0_MASK                                            0xff
#define CHN7_LNA2_8_RESERVED_0_GET(x)                                          (((x) & CHN7_LNA2_8_RESERVED_0_MASK) >> CHN7_LNA2_8_RESERVED_0_LSB)
#define CHN7_LNA2_8_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN7_LNA2_8_RESERVED_0_LSB) & CHN7_LNA2_8_RESERVED_0_MASK)
#define CHN7_LNA2_8_RESERVED_0_RESET                                           0x0
#define CHN7_LNA2_8_ADDRESS                                                    (0x30 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_LNA2_8_RSTMASK                                                    0xffffffff
#define CHN7_LNA2_8_RESET                                                      0x0

// 0x34 (CHN7_GM2_0)
#define CHN7_GM2_0_G0_GM_SIMPLE_BIAS_LSB                                       31
#define CHN7_GM2_0_G0_GM_SIMPLE_BIAS_MSB                                       31
#define CHN7_GM2_0_G0_GM_SIMPLE_BIAS_MASK                                      0x80000000
#define CHN7_GM2_0_G0_GM_SIMPLE_BIAS_GET(x)                                    (((x) & CHN7_GM2_0_G0_GM_SIMPLE_BIAS_MASK) >> CHN7_GM2_0_G0_GM_SIMPLE_BIAS_LSB)
#define CHN7_GM2_0_G0_GM_SIMPLE_BIAS_SET(x)                                    (((0 | (x)) << CHN7_GM2_0_G0_GM_SIMPLE_BIAS_LSB) & CHN7_GM2_0_G0_GM_SIMPLE_BIAS_MASK)
#define CHN7_GM2_0_G0_GM_SIMPLE_BIAS_RESET                                     0x0
#define CHN7_GM2_0_G0_GM_RDGEN_LSB                                             28
#define CHN7_GM2_0_G0_GM_RDGEN_MSB                                             30
#define CHN7_GM2_0_G0_GM_RDGEN_MASK                                            0x70000000
#define CHN7_GM2_0_G0_GM_RDGEN_GET(x)                                          (((x) & CHN7_GM2_0_G0_GM_RDGEN_MASK) >> CHN7_GM2_0_G0_GM_RDGEN_LSB)
#define CHN7_GM2_0_G0_GM_RDGEN_SET(x)                                          (((0 | (x)) << CHN7_GM2_0_G0_GM_RDGEN_LSB) & CHN7_GM2_0_G0_GM_RDGEN_MASK)
#define CHN7_GM2_0_G0_GM_RDGEN_RESET                                           0x3
#define CHN7_GM2_0_G0_GM_IBIAS_CTRL_LSB                                        24
#define CHN7_GM2_0_G0_GM_IBIAS_CTRL_MSB                                        27
#define CHN7_GM2_0_G0_GM_IBIAS_CTRL_MASK                                       0xf000000
#define CHN7_GM2_0_G0_GM_IBIAS_CTRL_GET(x)                                     (((x) & CHN7_GM2_0_G0_GM_IBIAS_CTRL_MASK) >> CHN7_GM2_0_G0_GM_IBIAS_CTRL_LSB)
#define CHN7_GM2_0_G0_GM_IBIAS_CTRL_SET(x)                                     (((0 | (x)) << CHN7_GM2_0_G0_GM_IBIAS_CTRL_LSB) & CHN7_GM2_0_G0_GM_IBIAS_CTRL_MASK)
#define CHN7_GM2_0_G0_GM_IBIAS_CTRL_RESET                                      0xb
#define CHN7_GM2_0_G0_GM_GAIN_LSB                                              22
#define CHN7_GM2_0_G0_GM_GAIN_MSB                                              23
#define CHN7_GM2_0_G0_GM_GAIN_MASK                                             0xc00000
#define CHN7_GM2_0_G0_GM_GAIN_GET(x)                                           (((x) & CHN7_GM2_0_G0_GM_GAIN_MASK) >> CHN7_GM2_0_G0_GM_GAIN_LSB)
#define CHN7_GM2_0_G0_GM_GAIN_SET(x)                                           (((0 | (x)) << CHN7_GM2_0_G0_GM_GAIN_LSB) & CHN7_GM2_0_G0_GM_GAIN_MASK)
#define CHN7_GM2_0_G0_GM_GAIN_RESET                                            0x0
#define CHN7_GM2_0_G1_GM_SIMPLE_BIAS_LSB                                       21
#define CHN7_GM2_0_G1_GM_SIMPLE_BIAS_MSB                                       21
#define CHN7_GM2_0_G1_GM_SIMPLE_BIAS_MASK                                      0x200000
#define CHN7_GM2_0_G1_GM_SIMPLE_BIAS_GET(x)                                    (((x) & CHN7_GM2_0_G1_GM_SIMPLE_BIAS_MASK) >> CHN7_GM2_0_G1_GM_SIMPLE_BIAS_LSB)
#define CHN7_GM2_0_G1_GM_SIMPLE_BIAS_SET(x)                                    (((0 | (x)) << CHN7_GM2_0_G1_GM_SIMPLE_BIAS_LSB) & CHN7_GM2_0_G1_GM_SIMPLE_BIAS_MASK)
#define CHN7_GM2_0_G1_GM_SIMPLE_BIAS_RESET                                     0x0
#define CHN7_GM2_0_G1_GM_RDGEN_LSB                                             18
#define CHN7_GM2_0_G1_GM_RDGEN_MSB                                             20
#define CHN7_GM2_0_G1_GM_RDGEN_MASK                                            0x1c0000
#define CHN7_GM2_0_G1_GM_RDGEN_GET(x)                                          (((x) & CHN7_GM2_0_G1_GM_RDGEN_MASK) >> CHN7_GM2_0_G1_GM_RDGEN_LSB)
#define CHN7_GM2_0_G1_GM_RDGEN_SET(x)                                          (((0 | (x)) << CHN7_GM2_0_G1_GM_RDGEN_LSB) & CHN7_GM2_0_G1_GM_RDGEN_MASK)
#define CHN7_GM2_0_G1_GM_RDGEN_RESET                                           0x3
#define CHN7_GM2_0_G1_GM_IBIAS_CTRL_LSB                                        14
#define CHN7_GM2_0_G1_GM_IBIAS_CTRL_MSB                                        17
#define CHN7_GM2_0_G1_GM_IBIAS_CTRL_MASK                                       0x3c000
#define CHN7_GM2_0_G1_GM_IBIAS_CTRL_GET(x)                                     (((x) & CHN7_GM2_0_G1_GM_IBIAS_CTRL_MASK) >> CHN7_GM2_0_G1_GM_IBIAS_CTRL_LSB)
#define CHN7_GM2_0_G1_GM_IBIAS_CTRL_SET(x)                                     (((0 | (x)) << CHN7_GM2_0_G1_GM_IBIAS_CTRL_LSB) & CHN7_GM2_0_G1_GM_IBIAS_CTRL_MASK)
#define CHN7_GM2_0_G1_GM_IBIAS_CTRL_RESET                                      0xb
#define CHN7_GM2_0_G1_GM_GAIN_LSB                                              12
#define CHN7_GM2_0_G1_GM_GAIN_MSB                                              13
#define CHN7_GM2_0_G1_GM_GAIN_MASK                                             0x3000
#define CHN7_GM2_0_G1_GM_GAIN_GET(x)                                           (((x) & CHN7_GM2_0_G1_GM_GAIN_MASK) >> CHN7_GM2_0_G1_GM_GAIN_LSB)
#define CHN7_GM2_0_G1_GM_GAIN_SET(x)                                           (((0 | (x)) << CHN7_GM2_0_G1_GM_GAIN_LSB) & CHN7_GM2_0_G1_GM_GAIN_MASK)
#define CHN7_GM2_0_G1_GM_GAIN_RESET                                            0x1
#define CHN7_GM2_0_G2_GM_SIMPLE_BIAS_LSB                                       11
#define CHN7_GM2_0_G2_GM_SIMPLE_BIAS_MSB                                       11
#define CHN7_GM2_0_G2_GM_SIMPLE_BIAS_MASK                                      0x800
#define CHN7_GM2_0_G2_GM_SIMPLE_BIAS_GET(x)                                    (((x) & CHN7_GM2_0_G2_GM_SIMPLE_BIAS_MASK) >> CHN7_GM2_0_G2_GM_SIMPLE_BIAS_LSB)
#define CHN7_GM2_0_G2_GM_SIMPLE_BIAS_SET(x)                                    (((0 | (x)) << CHN7_GM2_0_G2_GM_SIMPLE_BIAS_LSB) & CHN7_GM2_0_G2_GM_SIMPLE_BIAS_MASK)
#define CHN7_GM2_0_G2_GM_SIMPLE_BIAS_RESET                                     0x0
#define CHN7_GM2_0_G2_GM_RDGEN_LSB                                             8
#define CHN7_GM2_0_G2_GM_RDGEN_MSB                                             10
#define CHN7_GM2_0_G2_GM_RDGEN_MASK                                            0x700
#define CHN7_GM2_0_G2_GM_RDGEN_GET(x)                                          (((x) & CHN7_GM2_0_G2_GM_RDGEN_MASK) >> CHN7_GM2_0_G2_GM_RDGEN_LSB)
#define CHN7_GM2_0_G2_GM_RDGEN_SET(x)                                          (((0 | (x)) << CHN7_GM2_0_G2_GM_RDGEN_LSB) & CHN7_GM2_0_G2_GM_RDGEN_MASK)
#define CHN7_GM2_0_G2_GM_RDGEN_RESET                                           0x3
#define CHN7_GM2_0_G2_GM_IBIAS_CTRL_LSB                                        4
#define CHN7_GM2_0_G2_GM_IBIAS_CTRL_MSB                                        7
#define CHN7_GM2_0_G2_GM_IBIAS_CTRL_MASK                                       0xf0
#define CHN7_GM2_0_G2_GM_IBIAS_CTRL_GET(x)                                     (((x) & CHN7_GM2_0_G2_GM_IBIAS_CTRL_MASK) >> CHN7_GM2_0_G2_GM_IBIAS_CTRL_LSB)
#define CHN7_GM2_0_G2_GM_IBIAS_CTRL_SET(x)                                     (((0 | (x)) << CHN7_GM2_0_G2_GM_IBIAS_CTRL_LSB) & CHN7_GM2_0_G2_GM_IBIAS_CTRL_MASK)
#define CHN7_GM2_0_G2_GM_IBIAS_CTRL_RESET                                      0xb
#define CHN7_GM2_0_G2_GM_GAIN_LSB                                              2
#define CHN7_GM2_0_G2_GM_GAIN_MSB                                              3
#define CHN7_GM2_0_G2_GM_GAIN_MASK                                             0xc
#define CHN7_GM2_0_G2_GM_GAIN_GET(x)                                           (((x) & CHN7_GM2_0_G2_GM_GAIN_MASK) >> CHN7_GM2_0_G2_GM_GAIN_LSB)
#define CHN7_GM2_0_G2_GM_GAIN_SET(x)                                           (((0 | (x)) << CHN7_GM2_0_G2_GM_GAIN_LSB) & CHN7_GM2_0_G2_GM_GAIN_MASK)
#define CHN7_GM2_0_G2_GM_GAIN_RESET                                            0x2
#define CHN7_GM2_0_RESERVED_0_LSB                                              0
#define CHN7_GM2_0_RESERVED_0_MSB                                              1
#define CHN7_GM2_0_RESERVED_0_MASK                                             0x3
#define CHN7_GM2_0_RESERVED_0_GET(x)                                           (((x) & CHN7_GM2_0_RESERVED_0_MASK) >> CHN7_GM2_0_RESERVED_0_LSB)
#define CHN7_GM2_0_RESERVED_0_SET(x)                                           (((0 | (x)) << CHN7_GM2_0_RESERVED_0_LSB) & CHN7_GM2_0_RESERVED_0_MASK)
#define CHN7_GM2_0_RESERVED_0_RESET                                            0x0
#define CHN7_GM2_0_ADDRESS                                                     (0x34 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_GM2_0_RSTMASK                                                     0xffffffff
#define CHN7_GM2_0_RESET                                                       0x3b0ed3b8

// 0x38 (CHN7_GM2_1)
#define CHN7_GM2_1_G3_GM_SIMPLE_BIAS_LSB                                       31
#define CHN7_GM2_1_G3_GM_SIMPLE_BIAS_MSB                                       31
#define CHN7_GM2_1_G3_GM_SIMPLE_BIAS_MASK                                      0x80000000
#define CHN7_GM2_1_G3_GM_SIMPLE_BIAS_GET(x)                                    (((x) & CHN7_GM2_1_G3_GM_SIMPLE_BIAS_MASK) >> CHN7_GM2_1_G3_GM_SIMPLE_BIAS_LSB)
#define CHN7_GM2_1_G3_GM_SIMPLE_BIAS_SET(x)                                    (((0 | (x)) << CHN7_GM2_1_G3_GM_SIMPLE_BIAS_LSB) & CHN7_GM2_1_G3_GM_SIMPLE_BIAS_MASK)
#define CHN7_GM2_1_G3_GM_SIMPLE_BIAS_RESET                                     0x0
#define CHN7_GM2_1_G3_GM_RDGEN_LSB                                             28
#define CHN7_GM2_1_G3_GM_RDGEN_MSB                                             30
#define CHN7_GM2_1_G3_GM_RDGEN_MASK                                            0x70000000
#define CHN7_GM2_1_G3_GM_RDGEN_GET(x)                                          (((x) & CHN7_GM2_1_G3_GM_RDGEN_MASK) >> CHN7_GM2_1_G3_GM_RDGEN_LSB)
#define CHN7_GM2_1_G3_GM_RDGEN_SET(x)                                          (((0 | (x)) << CHN7_GM2_1_G3_GM_RDGEN_LSB) & CHN7_GM2_1_G3_GM_RDGEN_MASK)
#define CHN7_GM2_1_G3_GM_RDGEN_RESET                                           0x3
#define CHN7_GM2_1_G3_GM_IBIAS_CTRL_LSB                                        24
#define CHN7_GM2_1_G3_GM_IBIAS_CTRL_MSB                                        27
#define CHN7_GM2_1_G3_GM_IBIAS_CTRL_MASK                                       0xf000000
#define CHN7_GM2_1_G3_GM_IBIAS_CTRL_GET(x)                                     (((x) & CHN7_GM2_1_G3_GM_IBIAS_CTRL_MASK) >> CHN7_GM2_1_G3_GM_IBIAS_CTRL_LSB)
#define CHN7_GM2_1_G3_GM_IBIAS_CTRL_SET(x)                                     (((0 | (x)) << CHN7_GM2_1_G3_GM_IBIAS_CTRL_LSB) & CHN7_GM2_1_G3_GM_IBIAS_CTRL_MASK)
#define CHN7_GM2_1_G3_GM_IBIAS_CTRL_RESET                                      0xb
#define CHN7_GM2_1_G3_GM_GAIN_LSB                                              22
#define CHN7_GM2_1_G3_GM_GAIN_MSB                                              23
#define CHN7_GM2_1_G3_GM_GAIN_MASK                                             0xc00000
#define CHN7_GM2_1_G3_GM_GAIN_GET(x)                                           (((x) & CHN7_GM2_1_G3_GM_GAIN_MASK) >> CHN7_GM2_1_G3_GM_GAIN_LSB)
#define CHN7_GM2_1_G3_GM_GAIN_SET(x)                                           (((0 | (x)) << CHN7_GM2_1_G3_GM_GAIN_LSB) & CHN7_GM2_1_G3_GM_GAIN_MASK)
#define CHN7_GM2_1_G3_GM_GAIN_RESET                                            0x3
#define CHN7_GM2_1_RESERVED_0_LSB                                              0
#define CHN7_GM2_1_RESERVED_0_MSB                                              21
#define CHN7_GM2_1_RESERVED_0_MASK                                             0x3fffff
#define CHN7_GM2_1_RESERVED_0_GET(x)                                           (((x) & CHN7_GM2_1_RESERVED_0_MASK) >> CHN7_GM2_1_RESERVED_0_LSB)
#define CHN7_GM2_1_RESERVED_0_SET(x)                                           (((0 | (x)) << CHN7_GM2_1_RESERVED_0_LSB) & CHN7_GM2_1_RESERVED_0_MASK)
#define CHN7_GM2_1_RESERVED_0_RESET                                            0x0
#define CHN7_GM2_1_ADDRESS                                                     (0x38 + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_GM2_1_RSTMASK                                                     0xffffffff
#define CHN7_GM2_1_RESET                                                       0x3bc00000

// 0x3c (CHN7_RXFE2_READ)
#define CHN7_RXFE2_READ_AGC_PKOUT_LSB                                          31
#define CHN7_RXFE2_READ_AGC_PKOUT_MSB                                          31
#define CHN7_RXFE2_READ_AGC_PKOUT_MASK                                         0x80000000
#define CHN7_RXFE2_READ_AGC_PKOUT_GET(x)                                       (((x) & CHN7_RXFE2_READ_AGC_PKOUT_MASK) >> CHN7_RXFE2_READ_AGC_PKOUT_LSB)
#define CHN7_RXFE2_READ_AGC_PKOUT_SET(x)                                       (((0 | (x)) << CHN7_RXFE2_READ_AGC_PKOUT_LSB) & CHN7_RXFE2_READ_AGC_PKOUT_MASK)
#define CHN7_RXFE2_READ_AGC_PKOUT_RESET                                        0x0
#define CHN7_RXFE2_READ_ADDRESS                                                (0x3c + __CHN7_RXFE2G_REG_CSR_BASE_ADDRESS)
#define CHN7_RXFE2_READ_RSTMASK                                                0x80000000
#define CHN7_RXFE2_READ_RESET                                                  0x0



#endif /* _CHN7_RXFE2G_REG_CSR_H_ */
