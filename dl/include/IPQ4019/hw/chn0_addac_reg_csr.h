/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CHN0_ADDAC_REG_CSR_H_
#define _CHN0_ADDAC_REG_CSR_H_


#ifndef __CHN0_ADDAC_REG_CSR_BASE_ADDRESS
#define __CHN0_ADDAC_REG_CSR_BASE_ADDRESS (0x48180)
#endif


// 0x0 (CHN0_ADDAC0)
#define CHN0_ADDAC0_LOCAL_ADCPWD_LSB                                           31
#define CHN0_ADDAC0_LOCAL_ADCPWD_MSB                                           31
#define CHN0_ADDAC0_LOCAL_ADCPWD_MASK                                          0x80000000
#define CHN0_ADDAC0_LOCAL_ADCPWD_GET(x)                                        (((x) & CHN0_ADDAC0_LOCAL_ADCPWD_MASK) >> CHN0_ADDAC0_LOCAL_ADCPWD_LSB)
#define CHN0_ADDAC0_LOCAL_ADCPWD_SET(x)                                        (((0 | (x)) << CHN0_ADDAC0_LOCAL_ADCPWD_LSB) & CHN0_ADDAC0_LOCAL_ADCPWD_MASK)
#define CHN0_ADDAC0_LOCAL_ADCPWD_RESET                                         0x0
#define CHN0_ADDAC0_ADCPWD_LS_LSB                                              30
#define CHN0_ADDAC0_ADCPWD_LS_MSB                                              30
#define CHN0_ADDAC0_ADCPWD_LS_MASK                                             0x40000000
#define CHN0_ADDAC0_ADCPWD_LS_GET(x)                                           (((x) & CHN0_ADDAC0_ADCPWD_LS_MASK) >> CHN0_ADDAC0_ADCPWD_LS_LSB)
#define CHN0_ADDAC0_ADCPWD_LS_SET(x)                                           (((0 | (x)) << CHN0_ADDAC0_ADCPWD_LS_LSB) & CHN0_ADDAC0_ADCPWD_LS_MASK)
#define CHN0_ADDAC0_ADCPWD_LS_RESET                                            0x0
#define CHN0_ADDAC0_ADCCLKPWD_LS_LSB                                           29
#define CHN0_ADDAC0_ADCCLKPWD_LS_MSB                                           29
#define CHN0_ADDAC0_ADCCLKPWD_LS_MASK                                          0x20000000
#define CHN0_ADDAC0_ADCCLKPWD_LS_GET(x)                                        (((x) & CHN0_ADDAC0_ADCCLKPWD_LS_MASK) >> CHN0_ADDAC0_ADCCLKPWD_LS_LSB)
#define CHN0_ADDAC0_ADCCLKPWD_LS_SET(x)                                        (((0 | (x)) << CHN0_ADDAC0_ADCCLKPWD_LS_LSB) & CHN0_ADDAC0_ADCCLKPWD_LS_MASK)
#define CHN0_ADDAC0_ADCCLKPWD_LS_RESET                                         0x0
#define CHN0_ADDAC0_ADC_ENABLEI_LS_LSB                                         28
#define CHN0_ADDAC0_ADC_ENABLEI_LS_MSB                                         28
#define CHN0_ADDAC0_ADC_ENABLEI_LS_MASK                                        0x10000000
#define CHN0_ADDAC0_ADC_ENABLEI_LS_GET(x)                                      (((x) & CHN0_ADDAC0_ADC_ENABLEI_LS_MASK) >> CHN0_ADDAC0_ADC_ENABLEI_LS_LSB)
#define CHN0_ADDAC0_ADC_ENABLEI_LS_SET(x)                                      (((0 | (x)) << CHN0_ADDAC0_ADC_ENABLEI_LS_LSB) & CHN0_ADDAC0_ADC_ENABLEI_LS_MASK)
#define CHN0_ADDAC0_ADC_ENABLEI_LS_RESET                                       0x0
#define CHN0_ADDAC0_ADC_ENABLEQ_LS_LSB                                         27
#define CHN0_ADDAC0_ADC_ENABLEQ_LS_MSB                                         27
#define CHN0_ADDAC0_ADC_ENABLEQ_LS_MASK                                        0x8000000
#define CHN0_ADDAC0_ADC_ENABLEQ_LS_GET(x)                                      (((x) & CHN0_ADDAC0_ADC_ENABLEQ_LS_MASK) >> CHN0_ADDAC0_ADC_ENABLEQ_LS_LSB)
#define CHN0_ADDAC0_ADC_ENABLEQ_LS_SET(x)                                      (((0 | (x)) << CHN0_ADDAC0_ADC_ENABLEQ_LS_LSB) & CHN0_ADDAC0_ADC_ENABLEQ_LS_MASK)
#define CHN0_ADDAC0_ADC_ENABLEQ_LS_RESET                                       0x0
#define CHN0_ADDAC0_INV_CLK320_ADC_LSB                                         26
#define CHN0_ADDAC0_INV_CLK320_ADC_MSB                                         26
#define CHN0_ADDAC0_INV_CLK320_ADC_MASK                                        0x4000000
#define CHN0_ADDAC0_INV_CLK320_ADC_GET(x)                                      (((x) & CHN0_ADDAC0_INV_CLK320_ADC_MASK) >> CHN0_ADDAC0_INV_CLK320_ADC_LSB)
#define CHN0_ADDAC0_INV_CLK320_ADC_SET(x)                                      (((0 | (x)) << CHN0_ADDAC0_INV_CLK320_ADC_LSB) & CHN0_ADDAC0_INV_CLK320_ADC_MASK)
#define CHN0_ADDAC0_INV_CLK320_ADC_RESET                                       0x0
#define CHN0_ADDAC0_ADC_CLK_SEL_LS_LSB                                         24
#define CHN0_ADDAC0_ADC_CLK_SEL_LS_MSB                                         25
#define CHN0_ADDAC0_ADC_CLK_SEL_LS_MASK                                        0x3000000
#define CHN0_ADDAC0_ADC_CLK_SEL_LS_GET(x)                                      (((x) & CHN0_ADDAC0_ADC_CLK_SEL_LS_MASK) >> CHN0_ADDAC0_ADC_CLK_SEL_LS_LSB)
#define CHN0_ADDAC0_ADC_CLK_SEL_LS_SET(x)                                      (((0 | (x)) << CHN0_ADDAC0_ADC_CLK_SEL_LS_LSB) & CHN0_ADDAC0_ADC_CLK_SEL_LS_MASK)
#define CHN0_ADDAC0_ADC_CLK_SEL_LS_RESET                                       0x0
#define CHN0_ADDAC0_FLIP_ADC_STROBE_CLK_GATED_LSB                              23
#define CHN0_ADDAC0_FLIP_ADC_STROBE_CLK_GATED_MSB                              23
#define CHN0_ADDAC0_FLIP_ADC_STROBE_CLK_GATED_MASK                             0x800000
#define CHN0_ADDAC0_FLIP_ADC_STROBE_CLK_GATED_GET(x)                           (((x) & CHN0_ADDAC0_FLIP_ADC_STROBE_CLK_GATED_MASK) >> CHN0_ADDAC0_FLIP_ADC_STROBE_CLK_GATED_LSB)
#define CHN0_ADDAC0_FLIP_ADC_STROBE_CLK_GATED_SET(x)                           (((0 | (x)) << CHN0_ADDAC0_FLIP_ADC_STROBE_CLK_GATED_LSB) & CHN0_ADDAC0_FLIP_ADC_STROBE_CLK_GATED_MASK)
#define CHN0_ADDAC0_FLIP_ADC_STROBE_CLK_GATED_RESET                            0x0
#define CHN0_ADDAC0_ADC_OUTENABLE_LSB                                          22
#define CHN0_ADDAC0_ADC_OUTENABLE_MSB                                          22
#define CHN0_ADDAC0_ADC_OUTENABLE_MASK                                         0x400000
#define CHN0_ADDAC0_ADC_OUTENABLE_GET(x)                                       (((x) & CHN0_ADDAC0_ADC_OUTENABLE_MASK) >> CHN0_ADDAC0_ADC_OUTENABLE_LSB)
#define CHN0_ADDAC0_ADC_OUTENABLE_SET(x)                                       (((0 | (x)) << CHN0_ADDAC0_ADC_OUTENABLE_LSB) & CHN0_ADDAC0_ADC_OUTENABLE_MASK)
#define CHN0_ADDAC0_ADC_OUTENABLE_RESET                                        0x0
#define CHN0_ADDAC0_ADCSHORT_OVR_LSB                                           20
#define CHN0_ADDAC0_ADCSHORT_OVR_MSB                                           21
#define CHN0_ADDAC0_ADCSHORT_OVR_MASK                                          0x300000
#define CHN0_ADDAC0_ADCSHORT_OVR_GET(x)                                        (((x) & CHN0_ADDAC0_ADCSHORT_OVR_MASK) >> CHN0_ADDAC0_ADCSHORT_OVR_LSB)
#define CHN0_ADDAC0_ADCSHORT_OVR_SET(x)                                        (((0 | (x)) << CHN0_ADDAC0_ADCSHORT_OVR_LSB) & CHN0_ADDAC0_ADCSHORT_OVR_MASK)
#define CHN0_ADDAC0_ADCSHORT_OVR_RESET                                         0x0
#define CHN0_ADDAC0_ADC_TIMEINTLV_LS_LSB                                       18
#define CHN0_ADDAC0_ADC_TIMEINTLV_LS_MSB                                       19
#define CHN0_ADDAC0_ADC_TIMEINTLV_LS_MASK                                      0xc0000
#define CHN0_ADDAC0_ADC_TIMEINTLV_LS_GET(x)                                    (((x) & CHN0_ADDAC0_ADC_TIMEINTLV_LS_MASK) >> CHN0_ADDAC0_ADC_TIMEINTLV_LS_LSB)
#define CHN0_ADDAC0_ADC_TIMEINTLV_LS_SET(x)                                    (((0 | (x)) << CHN0_ADDAC0_ADC_TIMEINTLV_LS_LSB) & CHN0_ADDAC0_ADC_TIMEINTLV_LS_MASK)
#define CHN0_ADDAC0_ADC_TIMEINTLV_LS_RESET                                     0x1
#define CHN0_ADDAC0_LOCAL_DACPWD_LSB                                           17
#define CHN0_ADDAC0_LOCAL_DACPWD_MSB                                           17
#define CHN0_ADDAC0_LOCAL_DACPWD_MASK                                          0x20000
#define CHN0_ADDAC0_LOCAL_DACPWD_GET(x)                                        (((x) & CHN0_ADDAC0_LOCAL_DACPWD_MASK) >> CHN0_ADDAC0_LOCAL_DACPWD_LSB)
#define CHN0_ADDAC0_LOCAL_DACPWD_SET(x)                                        (((0 | (x)) << CHN0_ADDAC0_LOCAL_DACPWD_LSB) & CHN0_ADDAC0_LOCAL_DACPWD_MASK)
#define CHN0_ADDAC0_LOCAL_DACPWD_RESET                                         0x0
#define CHN0_ADDAC0_DACPWD_LS_LSB                                              16
#define CHN0_ADDAC0_DACPWD_LS_MSB                                              16
#define CHN0_ADDAC0_DACPWD_LS_MASK                                             0x10000
#define CHN0_ADDAC0_DACPWD_LS_GET(x)                                           (((x) & CHN0_ADDAC0_DACPWD_LS_MASK) >> CHN0_ADDAC0_DACPWD_LS_LSB)
#define CHN0_ADDAC0_DACPWD_LS_SET(x)                                           (((0 | (x)) << CHN0_ADDAC0_DACPWD_LS_LSB) & CHN0_ADDAC0_DACPWD_LS_MASK)
#define CHN0_ADDAC0_DACPWD_LS_RESET                                            0x0
#define CHN0_ADDAC0_DACCLKPWD_LS_LSB                                           15
#define CHN0_ADDAC0_DACCLKPWD_LS_MSB                                           15
#define CHN0_ADDAC0_DACCLKPWD_LS_MASK                                          0x8000
#define CHN0_ADDAC0_DACCLKPWD_LS_GET(x)                                        (((x) & CHN0_ADDAC0_DACCLKPWD_LS_MASK) >> CHN0_ADDAC0_DACCLKPWD_LS_LSB)
#define CHN0_ADDAC0_DACCLKPWD_LS_SET(x)                                        (((0 | (x)) << CHN0_ADDAC0_DACCLKPWD_LS_LSB) & CHN0_ADDAC0_DACCLKPWD_LS_MASK)
#define CHN0_ADDAC0_DACCLKPWD_LS_RESET                                         0x0
#define CHN0_ADDAC0_DAC_CLK_INV_SEL_LSB                                        14
#define CHN0_ADDAC0_DAC_CLK_INV_SEL_MSB                                        14
#define CHN0_ADDAC0_DAC_CLK_INV_SEL_MASK                                       0x4000
#define CHN0_ADDAC0_DAC_CLK_INV_SEL_GET(x)                                     (((x) & CHN0_ADDAC0_DAC_CLK_INV_SEL_MASK) >> CHN0_ADDAC0_DAC_CLK_INV_SEL_LSB)
#define CHN0_ADDAC0_DAC_CLK_INV_SEL_SET(x)                                     (((0 | (x)) << CHN0_ADDAC0_DAC_CLK_INV_SEL_LSB) & CHN0_ADDAC0_DAC_CLK_INV_SEL_MASK)
#define CHN0_ADDAC0_DAC_CLK_INV_SEL_RESET                                      0x1
#define CHN0_ADDAC0_DAC_CLK_SEL_LS_LSB                                         13
#define CHN0_ADDAC0_DAC_CLK_SEL_LS_MSB                                         13
#define CHN0_ADDAC0_DAC_CLK_SEL_LS_MASK                                        0x2000
#define CHN0_ADDAC0_DAC_CLK_SEL_LS_GET(x)                                      (((x) & CHN0_ADDAC0_DAC_CLK_SEL_LS_MASK) >> CHN0_ADDAC0_DAC_CLK_SEL_LS_LSB)
#define CHN0_ADDAC0_DAC_CLK_SEL_LS_SET(x)                                      (((0 | (x)) << CHN0_ADDAC0_DAC_CLK_SEL_LS_LSB) & CHN0_ADDAC0_DAC_CLK_SEL_LS_MASK)
#define CHN0_ADDAC0_DAC_CLK_SEL_LS_RESET                                       0x0
#define CHN0_ADDAC0_DACRSTB_LSB                                                12
#define CHN0_ADDAC0_DACRSTB_MSB                                                12
#define CHN0_ADDAC0_DACRSTB_MASK                                               0x1000
#define CHN0_ADDAC0_DACRSTB_GET(x)                                             (((x) & CHN0_ADDAC0_DACRSTB_MASK) >> CHN0_ADDAC0_DACRSTB_LSB)
#define CHN0_ADDAC0_DACRSTB_SET(x)                                             (((0 | (x)) << CHN0_ADDAC0_DACRSTB_LSB) & CHN0_ADDAC0_DACRSTB_MASK)
#define CHN0_ADDAC0_DACRSTB_RESET                                              0x1
#define CHN0_ADDAC0_DACFULLSCALE_OVR_LSB                                       10
#define CHN0_ADDAC0_DACFULLSCALE_OVR_MSB                                       11
#define CHN0_ADDAC0_DACFULLSCALE_OVR_MASK                                      0xc00
#define CHN0_ADDAC0_DACFULLSCALE_OVR_GET(x)                                    (((x) & CHN0_ADDAC0_DACFULLSCALE_OVR_MASK) >> CHN0_ADDAC0_DACFULLSCALE_OVR_LSB)
#define CHN0_ADDAC0_DACFULLSCALE_OVR_SET(x)                                    (((0 | (x)) << CHN0_ADDAC0_DACFULLSCALE_OVR_LSB) & CHN0_ADDAC0_DACFULLSCALE_OVR_MASK)
#define CHN0_ADDAC0_DACFULLSCALE_OVR_RESET                                     0x0
#define CHN0_ADDAC0_DAC_BIAS_EN_OVR_LSB                                        8
#define CHN0_ADDAC0_DAC_BIAS_EN_OVR_MSB                                        9
#define CHN0_ADDAC0_DAC_BIAS_EN_OVR_MASK                                       0x300
#define CHN0_ADDAC0_DAC_BIAS_EN_OVR_GET(x)                                     (((x) & CHN0_ADDAC0_DAC_BIAS_EN_OVR_MASK) >> CHN0_ADDAC0_DAC_BIAS_EN_OVR_LSB)
#define CHN0_ADDAC0_DAC_BIAS_EN_OVR_SET(x)                                     (((0 | (x)) << CHN0_ADDAC0_DAC_BIAS_EN_OVR_LSB) & CHN0_ADDAC0_DAC_BIAS_EN_OVR_MASK)
#define CHN0_ADDAC0_DAC_BIAS_EN_OVR_RESET                                      0x0
#define CHN0_ADDAC0_LOCAL_CLKMODAADDAC_LSB                                     7
#define CHN0_ADDAC0_LOCAL_CLKMODAADDAC_MSB                                     7
#define CHN0_ADDAC0_LOCAL_CLKMODAADDAC_MASK                                    0x80
#define CHN0_ADDAC0_LOCAL_CLKMODAADDAC_GET(x)                                  (((x) & CHN0_ADDAC0_LOCAL_CLKMODAADDAC_MASK) >> CHN0_ADDAC0_LOCAL_CLKMODAADDAC_LSB)
#define CHN0_ADDAC0_LOCAL_CLKMODAADDAC_SET(x)                                  (((0 | (x)) << CHN0_ADDAC0_LOCAL_CLKMODAADDAC_LSB) & CHN0_ADDAC0_LOCAL_CLKMODAADDAC_MASK)
#define CHN0_ADDAC0_LOCAL_CLKMODAADDAC_RESET                                   0x0
#define CHN0_ADDAC0_ADDACLOOPBACK_LSB                                          6
#define CHN0_ADDAC0_ADDACLOOPBACK_MSB                                          6
#define CHN0_ADDAC0_ADDACLOOPBACK_MASK                                         0x40
#define CHN0_ADDAC0_ADDACLOOPBACK_GET(x)                                       (((x) & CHN0_ADDAC0_ADDACLOOPBACK_MASK) >> CHN0_ADDAC0_ADDACLOOPBACK_LSB)
#define CHN0_ADDAC0_ADDACLOOPBACK_SET(x)                                       (((0 | (x)) << CHN0_ADDAC0_ADDACLOOPBACK_LSB) & CHN0_ADDAC0_ADDACLOOPBACK_MASK)
#define CHN0_ADDAC0_ADDACLOOPBACK_RESET                                        0x0
#define CHN0_ADDAC0_ADC_PRECHARGE_CTANK_LSB                                    5
#define CHN0_ADDAC0_ADC_PRECHARGE_CTANK_MSB                                    5
#define CHN0_ADDAC0_ADC_PRECHARGE_CTANK_MASK                                   0x20
#define CHN0_ADDAC0_ADC_PRECHARGE_CTANK_GET(x)                                 (((x) & CHN0_ADDAC0_ADC_PRECHARGE_CTANK_MASK) >> CHN0_ADDAC0_ADC_PRECHARGE_CTANK_LSB)
#define CHN0_ADDAC0_ADC_PRECHARGE_CTANK_SET(x)                                 (((0 | (x)) << CHN0_ADDAC0_ADC_PRECHARGE_CTANK_LSB) & CHN0_ADDAC0_ADC_PRECHARGE_CTANK_MASK)
#define CHN0_ADDAC0_ADC_PRECHARGE_CTANK_RESET                                  0x0
#define CHN0_ADDAC0_ADC_ENABLE_REF_LSB                                         4
#define CHN0_ADDAC0_ADC_ENABLE_REF_MSB                                         4
#define CHN0_ADDAC0_ADC_ENABLE_REF_MASK                                        0x10
#define CHN0_ADDAC0_ADC_ENABLE_REF_GET(x)                                      (((x) & CHN0_ADDAC0_ADC_ENABLE_REF_MASK) >> CHN0_ADDAC0_ADC_ENABLE_REF_LSB)
#define CHN0_ADDAC0_ADC_ENABLE_REF_SET(x)                                      (((0 | (x)) << CHN0_ADDAC0_ADC_ENABLE_REF_LSB) & CHN0_ADDAC0_ADC_ENABLE_REF_MASK)
#define CHN0_ADDAC0_ADC_ENABLE_REF_RESET                                       0x0
#define CHN0_ADDAC0_ADC_DATA_OUT_NODELAY_LSB                                   3
#define CHN0_ADDAC0_ADC_DATA_OUT_NODELAY_MSB                                   3
#define CHN0_ADDAC0_ADC_DATA_OUT_NODELAY_MASK                                  0x8
#define CHN0_ADDAC0_ADC_DATA_OUT_NODELAY_GET(x)                                (((x) & CHN0_ADDAC0_ADC_DATA_OUT_NODELAY_MASK) >> CHN0_ADDAC0_ADC_DATA_OUT_NODELAY_LSB)
#define CHN0_ADDAC0_ADC_DATA_OUT_NODELAY_SET(x)                                (((0 | (x)) << CHN0_ADDAC0_ADC_DATA_OUT_NODELAY_LSB) & CHN0_ADDAC0_ADC_DATA_OUT_NODELAY_MASK)
#define CHN0_ADDAC0_ADC_DATA_OUT_NODELAY_RESET                                 0x0
#define CHN0_ADDAC0_ADDAC_SPARE_0_LSB                                          0
#define CHN0_ADDAC0_ADDAC_SPARE_0_MSB                                          2
#define CHN0_ADDAC0_ADDAC_SPARE_0_MASK                                         0x7
#define CHN0_ADDAC0_ADDAC_SPARE_0_GET(x)                                       (((x) & CHN0_ADDAC0_ADDAC_SPARE_0_MASK) >> CHN0_ADDAC0_ADDAC_SPARE_0_LSB)
#define CHN0_ADDAC0_ADDAC_SPARE_0_SET(x)                                       (((0 | (x)) << CHN0_ADDAC0_ADDAC_SPARE_0_LSB) & CHN0_ADDAC0_ADDAC_SPARE_0_MASK)
#define CHN0_ADDAC0_ADDAC_SPARE_0_RESET                                        0x0
#define CHN0_ADDAC0_ADDRESS                                                    (0x0 + __CHN0_ADDAC_REG_CSR_BASE_ADDRESS)
#define CHN0_ADDAC0_RSTMASK                                                    0xffffffff
#define CHN0_ADDAC0_RESET                                                      0x45000

// 0x4 (CHN0_PDADC0)
#define CHN0_PDADC0_PDADC_CLK_CLKMODA_EN_LSB                                   31
#define CHN0_PDADC0_PDADC_CLK_CLKMODA_EN_MSB                                   31
#define CHN0_PDADC0_PDADC_CLK_CLKMODA_EN_MASK                                  0x80000000
#define CHN0_PDADC0_PDADC_CLK_CLKMODA_EN_GET(x)                                (((x) & CHN0_PDADC0_PDADC_CLK_CLKMODA_EN_MASK) >> CHN0_PDADC0_PDADC_CLK_CLKMODA_EN_LSB)
#define CHN0_PDADC0_PDADC_CLK_CLKMODA_EN_SET(x)                                (((0 | (x)) << CHN0_PDADC0_PDADC_CLK_CLKMODA_EN_LSB) & CHN0_PDADC0_PDADC_CLK_CLKMODA_EN_MASK)
#define CHN0_PDADC0_PDADC_CLK_CLKMODA_EN_RESET                                 0x0
#define CHN0_PDADC0_PDADC_CLK_ANALOG_EN_LSB                                    30
#define CHN0_PDADC0_PDADC_CLK_ANALOG_EN_MSB                                    30
#define CHN0_PDADC0_PDADC_CLK_ANALOG_EN_MASK                                   0x40000000
#define CHN0_PDADC0_PDADC_CLK_ANALOG_EN_GET(x)                                 (((x) & CHN0_PDADC0_PDADC_CLK_ANALOG_EN_MASK) >> CHN0_PDADC0_PDADC_CLK_ANALOG_EN_LSB)
#define CHN0_PDADC0_PDADC_CLK_ANALOG_EN_SET(x)                                 (((0 | (x)) << CHN0_PDADC0_PDADC_CLK_ANALOG_EN_LSB) & CHN0_PDADC0_PDADC_CLK_ANALOG_EN_MASK)
#define CHN0_PDADC0_PDADC_CLK_ANALOG_EN_RESET                                  0x0
#define CHN0_PDADC0_PDADC_EN_OVR_LSB                                           28
#define CHN0_PDADC0_PDADC_EN_OVR_MSB                                           29
#define CHN0_PDADC0_PDADC_EN_OVR_MASK                                          0x30000000
#define CHN0_PDADC0_PDADC_EN_OVR_GET(x)                                        (((x) & CHN0_PDADC0_PDADC_EN_OVR_MASK) >> CHN0_PDADC0_PDADC_EN_OVR_LSB)
#define CHN0_PDADC0_PDADC_EN_OVR_SET(x)                                        (((0 | (x)) << CHN0_PDADC0_PDADC_EN_OVR_LSB) & CHN0_PDADC0_PDADC_EN_OVR_MASK)
#define CHN0_PDADC0_PDADC_EN_OVR_RESET                                         0x0
#define CHN0_PDADC0_PDADC_INPUT_SEL_OVR_LSB                                    24
#define CHN0_PDADC0_PDADC_INPUT_SEL_OVR_MSB                                    27
#define CHN0_PDADC0_PDADC_INPUT_SEL_OVR_MASK                                   0xf000000
#define CHN0_PDADC0_PDADC_INPUT_SEL_OVR_GET(x)                                 (((x) & CHN0_PDADC0_PDADC_INPUT_SEL_OVR_MASK) >> CHN0_PDADC0_PDADC_INPUT_SEL_OVR_LSB)
#define CHN0_PDADC0_PDADC_INPUT_SEL_OVR_SET(x)                                 (((0 | (x)) << CHN0_PDADC0_PDADC_INPUT_SEL_OVR_LSB) & CHN0_PDADC0_PDADC_INPUT_SEL_OVR_MASK)
#define CHN0_PDADC0_PDADC_INPUT_SEL_OVR_RESET                                  0x0
#define CHN0_PDADC0_PDADC_BOOSTVCM_LSB                                         23
#define CHN0_PDADC0_PDADC_BOOSTVCM_MSB                                         23
#define CHN0_PDADC0_PDADC_BOOSTVCM_MASK                                        0x800000
#define CHN0_PDADC0_PDADC_BOOSTVCM_GET(x)                                      (((x) & CHN0_PDADC0_PDADC_BOOSTVCM_MASK) >> CHN0_PDADC0_PDADC_BOOSTVCM_LSB)
#define CHN0_PDADC0_PDADC_BOOSTVCM_SET(x)                                      (((0 | (x)) << CHN0_PDADC0_PDADC_BOOSTVCM_LSB) & CHN0_PDADC0_PDADC_BOOSTVCM_MASK)
#define CHN0_PDADC0_PDADC_BOOSTVCM_RESET                                       0x1
#define CHN0_PDADC0_PDADC_FULLSWING_LSB                                        21
#define CHN0_PDADC0_PDADC_FULLSWING_MSB                                        22
#define CHN0_PDADC0_PDADC_FULLSWING_MASK                                       0x600000
#define CHN0_PDADC0_PDADC_FULLSWING_GET(x)                                     (((x) & CHN0_PDADC0_PDADC_FULLSWING_MASK) >> CHN0_PDADC0_PDADC_FULLSWING_LSB)
#define CHN0_PDADC0_PDADC_FULLSWING_SET(x)                                     (((0 | (x)) << CHN0_PDADC0_PDADC_FULLSWING_LSB) & CHN0_PDADC0_PDADC_FULLSWING_MASK)
#define CHN0_PDADC0_PDADC_FULLSWING_RESET                                      0x2
#define CHN0_PDADC0_PDADC_REF_ADJ_LSB                                          18
#define CHN0_PDADC0_PDADC_REF_ADJ_MSB                                          20
#define CHN0_PDADC0_PDADC_REF_ADJ_MASK                                         0x1c0000
#define CHN0_PDADC0_PDADC_REF_ADJ_GET(x)                                       (((x) & CHN0_PDADC0_PDADC_REF_ADJ_MASK) >> CHN0_PDADC0_PDADC_REF_ADJ_LSB)
#define CHN0_PDADC0_PDADC_REF_ADJ_SET(x)                                       (((0 | (x)) << CHN0_PDADC0_PDADC_REF_ADJ_LSB) & CHN0_PDADC0_PDADC_REF_ADJ_MASK)
#define CHN0_PDADC0_PDADC_REF_ADJ_RESET                                        0x3
#define CHN0_PDADC0_PDADC_ATB_SEL_LSB                                          15
#define CHN0_PDADC0_PDADC_ATB_SEL_MSB                                          17
#define CHN0_PDADC0_PDADC_ATB_SEL_MASK                                         0x38000
#define CHN0_PDADC0_PDADC_ATB_SEL_GET(x)                                       (((x) & CHN0_PDADC0_PDADC_ATB_SEL_MASK) >> CHN0_PDADC0_PDADC_ATB_SEL_LSB)
#define CHN0_PDADC0_PDADC_ATB_SEL_SET(x)                                       (((0 | (x)) << CHN0_PDADC0_PDADC_ATB_SEL_LSB) & CHN0_PDADC0_PDADC_ATB_SEL_MASK)
#define CHN0_PDADC0_PDADC_ATB_SEL_RESET                                        0x0
#define CHN0_PDADC0_PDADC_VREF_CTRL_LSB                                        12
#define CHN0_PDADC0_PDADC_VREF_CTRL_MSB                                        14
#define CHN0_PDADC0_PDADC_VREF_CTRL_MASK                                       0x7000
#define CHN0_PDADC0_PDADC_VREF_CTRL_GET(x)                                     (((x) & CHN0_PDADC0_PDADC_VREF_CTRL_MASK) >> CHN0_PDADC0_PDADC_VREF_CTRL_LSB)
#define CHN0_PDADC0_PDADC_VREF_CTRL_SET(x)                                     (((0 | (x)) << CHN0_PDADC0_PDADC_VREF_CTRL_LSB) & CHN0_PDADC0_PDADC_VREF_CTRL_MASK)
#define CHN0_PDADC0_PDADC_VREF_CTRL_RESET                                      0x4
#define CHN0_PDADC0_PDADC_FLIP_CLK_LSB                                         11
#define CHN0_PDADC0_PDADC_FLIP_CLK_MSB                                         11
#define CHN0_PDADC0_PDADC_FLIP_CLK_MASK                                        0x800
#define CHN0_PDADC0_PDADC_FLIP_CLK_GET(x)                                      (((x) & CHN0_PDADC0_PDADC_FLIP_CLK_MASK) >> CHN0_PDADC0_PDADC_FLIP_CLK_LSB)
#define CHN0_PDADC0_PDADC_FLIP_CLK_SET(x)                                      (((0 | (x)) << CHN0_PDADC0_PDADC_FLIP_CLK_LSB) & CHN0_PDADC0_PDADC_FLIP_CLK_MASK)
#define CHN0_PDADC0_PDADC_FLIP_CLK_RESET                                       0x0
#define CHN0_PDADC0_PDADC_THERM_SENS_RES_LSB                                   8
#define CHN0_PDADC0_PDADC_THERM_SENS_RES_MSB                                   10
#define CHN0_PDADC0_PDADC_THERM_SENS_RES_MASK                                  0x700
#define CHN0_PDADC0_PDADC_THERM_SENS_RES_GET(x)                                (((x) & CHN0_PDADC0_PDADC_THERM_SENS_RES_MASK) >> CHN0_PDADC0_PDADC_THERM_SENS_RES_LSB)
#define CHN0_PDADC0_PDADC_THERM_SENS_RES_SET(x)                                (((0 | (x)) << CHN0_PDADC0_PDADC_THERM_SENS_RES_LSB) & CHN0_PDADC0_PDADC_THERM_SENS_RES_MASK)
#define CHN0_PDADC0_PDADC_THERM_SENS_RES_RESET                                 0x0
#define CHN0_PDADC0_RESERVED_0_LSB                                             7
#define CHN0_PDADC0_RESERVED_0_MSB                                             7
#define CHN0_PDADC0_RESERVED_0_MASK                                            0x80
#define CHN0_PDADC0_RESERVED_0_GET(x)                                          (((x) & CHN0_PDADC0_RESERVED_0_MASK) >> CHN0_PDADC0_RESERVED_0_LSB)
#define CHN0_PDADC0_RESERVED_0_SET(x)                                          (((0 | (x)) << CHN0_PDADC0_RESERVED_0_LSB) & CHN0_PDADC0_RESERVED_0_MASK)
#define CHN0_PDADC0_RESERVED_0_RESET                                           0x0
#define CHN0_PDADC0_PDADC_SPARE_0_LSB                                          0
#define CHN0_PDADC0_PDADC_SPARE_0_MSB                                          6
#define CHN0_PDADC0_PDADC_SPARE_0_MASK                                         0x7f
#define CHN0_PDADC0_PDADC_SPARE_0_GET(x)                                       (((x) & CHN0_PDADC0_PDADC_SPARE_0_MASK) >> CHN0_PDADC0_PDADC_SPARE_0_LSB)
#define CHN0_PDADC0_PDADC_SPARE_0_SET(x)                                       (((0 | (x)) << CHN0_PDADC0_PDADC_SPARE_0_LSB) & CHN0_PDADC0_PDADC_SPARE_0_MASK)
#define CHN0_PDADC0_PDADC_SPARE_0_RESET                                        0x0
#define CHN0_PDADC0_ADDRESS                                                    (0x4 + __CHN0_ADDAC_REG_CSR_BASE_ADDRESS)
#define CHN0_PDADC0_RSTMASK                                                    0xffffffff
#define CHN0_PDADC0_RESET                                                      0xcc4000

// 0x8 (CHN0_PDADC1)
#define CHN0_PDADC1_PDADC_IC25_ADC_LSB                                         29
#define CHN0_PDADC1_PDADC_IC25_ADC_MSB                                         31
#define CHN0_PDADC1_PDADC_IC25_ADC_MASK                                        0xe0000000
#define CHN0_PDADC1_PDADC_IC25_ADC_GET(x)                                      (((x) & CHN0_PDADC1_PDADC_IC25_ADC_MASK) >> CHN0_PDADC1_PDADC_IC25_ADC_LSB)
#define CHN0_PDADC1_PDADC_IC25_ADC_SET(x)                                      (((0 | (x)) << CHN0_PDADC1_PDADC_IC25_ADC_LSB) & CHN0_PDADC1_PDADC_IC25_ADC_MASK)
#define CHN0_PDADC1_PDADC_IC25_ADC_RESET                                       0x4
#define CHN0_PDADC1_PDADC_IC25_ADCBUF1_LSB                                     26
#define CHN0_PDADC1_PDADC_IC25_ADCBUF1_MSB                                     28
#define CHN0_PDADC1_PDADC_IC25_ADCBUF1_MASK                                    0x1c000000
#define CHN0_PDADC1_PDADC_IC25_ADCBUF1_GET(x)                                  (((x) & CHN0_PDADC1_PDADC_IC25_ADCBUF1_MASK) >> CHN0_PDADC1_PDADC_IC25_ADCBUF1_LSB)
#define CHN0_PDADC1_PDADC_IC25_ADCBUF1_SET(x)                                  (((0 | (x)) << CHN0_PDADC1_PDADC_IC25_ADCBUF1_LSB) & CHN0_PDADC1_PDADC_IC25_ADCBUF1_MASK)
#define CHN0_PDADC1_PDADC_IC25_ADCBUF1_RESET                                   0x4
#define CHN0_PDADC1_PDADC_IC25_ADCBUF2_LSB                                     23
#define CHN0_PDADC1_PDADC_IC25_ADCBUF2_MSB                                     25
#define CHN0_PDADC1_PDADC_IC25_ADCBUF2_MASK                                    0x3800000
#define CHN0_PDADC1_PDADC_IC25_ADCBUF2_GET(x)                                  (((x) & CHN0_PDADC1_PDADC_IC25_ADCBUF2_MASK) >> CHN0_PDADC1_PDADC_IC25_ADCBUF2_LSB)
#define CHN0_PDADC1_PDADC_IC25_ADCBUF2_SET(x)                                  (((0 | (x)) << CHN0_PDADC1_PDADC_IC25_ADCBUF2_LSB) & CHN0_PDADC1_PDADC_IC25_ADCBUF2_MASK)
#define CHN0_PDADC1_PDADC_IC25_ADCBUF2_RESET                                   0x4
#define CHN0_PDADC1_PDADC_IR25_SRCH_LSB                                        20
#define CHN0_PDADC1_PDADC_IR25_SRCH_MSB                                        22
#define CHN0_PDADC1_PDADC_IR25_SRCH_MASK                                       0x700000
#define CHN0_PDADC1_PDADC_IR25_SRCH_GET(x)                                     (((x) & CHN0_PDADC1_PDADC_IR25_SRCH_MASK) >> CHN0_PDADC1_PDADC_IR25_SRCH_LSB)
#define CHN0_PDADC1_PDADC_IR25_SRCH_SET(x)                                     (((0 | (x)) << CHN0_PDADC1_PDADC_IR25_SRCH_LSB) & CHN0_PDADC1_PDADC_IR25_SRCH_MASK)
#define CHN0_PDADC1_PDADC_IR25_SRCH_RESET                                      0x4
#define CHN0_PDADC1_PDADC_IR25_VREF_LSB                                        17
#define CHN0_PDADC1_PDADC_IR25_VREF_MSB                                        19
#define CHN0_PDADC1_PDADC_IR25_VREF_MASK                                       0xe0000
#define CHN0_PDADC1_PDADC_IR25_VREF_GET(x)                                     (((x) & CHN0_PDADC1_PDADC_IR25_VREF_MASK) >> CHN0_PDADC1_PDADC_IR25_VREF_LSB)
#define CHN0_PDADC1_PDADC_IR25_VREF_SET(x)                                     (((0 | (x)) << CHN0_PDADC1_PDADC_IR25_VREF_LSB) & CHN0_PDADC1_PDADC_IR25_VREF_MASK)
#define CHN0_PDADC1_PDADC_IR25_VREF_RESET                                      0x4
#define CHN0_PDADC1_PDADC_SPARE_1_LSB                                          0
#define CHN0_PDADC1_PDADC_SPARE_1_MSB                                          16
#define CHN0_PDADC1_PDADC_SPARE_1_MASK                                         0x1ffff
#define CHN0_PDADC1_PDADC_SPARE_1_GET(x)                                       (((x) & CHN0_PDADC1_PDADC_SPARE_1_MASK) >> CHN0_PDADC1_PDADC_SPARE_1_LSB)
#define CHN0_PDADC1_PDADC_SPARE_1_SET(x)                                       (((0 | (x)) << CHN0_PDADC1_PDADC_SPARE_1_LSB) & CHN0_PDADC1_PDADC_SPARE_1_MASK)
#define CHN0_PDADC1_PDADC_SPARE_1_RESET                                        0x0
#define CHN0_PDADC1_ADDRESS                                                    (0x8 + __CHN0_ADDAC_REG_CSR_BASE_ADDRESS)
#define CHN0_PDADC1_RSTMASK                                                    0xffffffff
#define CHN0_PDADC1_RESET                                                      0x92480000

// 0xc (CHN0_PDADC2)
#define CHN0_PDADC2_PDADC_DATAOUT_LSB                                          0
#define CHN0_PDADC2_PDADC_DATAOUT_MSB                                          8
#define CHN0_PDADC2_PDADC_DATAOUT_MASK                                         0x1ff
#define CHN0_PDADC2_PDADC_DATAOUT_GET(x)                                       (((x) & CHN0_PDADC2_PDADC_DATAOUT_MASK) >> CHN0_PDADC2_PDADC_DATAOUT_LSB)
#define CHN0_PDADC2_PDADC_DATAOUT_SET(x)                                       (((0 | (x)) << CHN0_PDADC2_PDADC_DATAOUT_LSB) & CHN0_PDADC2_PDADC_DATAOUT_MASK)
#define CHN0_PDADC2_PDADC_DATAOUT_RESET                                        0x0
#define CHN0_PDADC2_ADDRESS                                                    (0xc + __CHN0_ADDAC_REG_CSR_BASE_ADDRESS)
#define CHN0_PDADC2_RSTMASK                                                    0x1ff
#define CHN0_PDADC2_RESET                                                      0x0



#endif /* _CHN0_ADDAC_REG_CSR_H_ */
