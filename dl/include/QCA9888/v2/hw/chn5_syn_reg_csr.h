/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CHN5_SYN_REG_CSR_H_
#define _CHN5_SYN_REG_CSR_H_


#ifndef __CHN5_SYN_REG_CSR_BASE_ADDRESS
#define __CHN5_SYN_REG_CSR_BASE_ADDRESS (0x47740)
#endif


// 0x0 (CHN5_SYNTH0)
#define CHN5_SYNTH0_SEL_ATB_LSB                                                28
#define CHN5_SYNTH0_SEL_ATB_MSB                                                31
#define CHN5_SYNTH0_SEL_ATB_MASK                                               0xf0000000
#define CHN5_SYNTH0_SEL_ATB_GET(x)                                             (((x) & CHN5_SYNTH0_SEL_ATB_MASK) >> CHN5_SYNTH0_SEL_ATB_LSB)
#define CHN5_SYNTH0_SEL_ATB_SET(x)                                             (((0 | (x)) << CHN5_SYNTH0_SEL_ATB_LSB) & CHN5_SYNTH0_SEL_ATB_MASK)
#define CHN5_SYNTH0_SEL_ATB_RESET                                              0x0
#define CHN5_SYNTH0_SEL_ATBH_LSB                                               25
#define CHN5_SYNTH0_SEL_ATBH_MSB                                               27
#define CHN5_SYNTH0_SEL_ATBH_MASK                                              0xe000000
#define CHN5_SYNTH0_SEL_ATBH_GET(x)                                            (((x) & CHN5_SYNTH0_SEL_ATBH_MASK) >> CHN5_SYNTH0_SEL_ATBH_LSB)
#define CHN5_SYNTH0_SEL_ATBH_SET(x)                                            (((0 | (x)) << CHN5_SYNTH0_SEL_ATBH_LSB) & CHN5_SYNTH0_SEL_ATBH_MASK)
#define CHN5_SYNTH0_SEL_ATBH_RESET                                             0x0
#define CHN5_SYNTH0_REFMULT_DLL_ABSEL_LSB                                      22
#define CHN5_SYNTH0_REFMULT_DLL_ABSEL_MSB                                      24
#define CHN5_SYNTH0_REFMULT_DLL_ABSEL_MASK                                     0x1c00000
#define CHN5_SYNTH0_REFMULT_DLL_ABSEL_GET(x)                                   (((x) & CHN5_SYNTH0_REFMULT_DLL_ABSEL_MASK) >> CHN5_SYNTH0_REFMULT_DLL_ABSEL_LSB)
#define CHN5_SYNTH0_REFMULT_DLL_ABSEL_SET(x)                                   (((0 | (x)) << CHN5_SYNTH0_REFMULT_DLL_ABSEL_LSB) & CHN5_SYNTH0_REFMULT_DLL_ABSEL_MASK)
#define CHN5_SYNTH0_REFMULT_DLL_ABSEL_RESET                                    0x0
#define CHN5_SYNTH0_BIAS_ATB_LSB                                               17
#define CHN5_SYNTH0_BIAS_ATB_MSB                                               21
#define CHN5_SYNTH0_BIAS_ATB_MASK                                              0x3e0000
#define CHN5_SYNTH0_BIAS_ATB_GET(x)                                            (((x) & CHN5_SYNTH0_BIAS_ATB_MASK) >> CHN5_SYNTH0_BIAS_ATB_LSB)
#define CHN5_SYNTH0_BIAS_ATB_SET(x)                                            (((0 | (x)) << CHN5_SYNTH0_BIAS_ATB_LSB) & CHN5_SYNTH0_BIAS_ATB_MASK)
#define CHN5_SYNTH0_BIAS_ATB_RESET                                             0x0
#define CHN5_SYNTH0_VCO_ATBH_VTAIL_SEL_LSB                                     16
#define CHN5_SYNTH0_VCO_ATBH_VTAIL_SEL_MSB                                     16
#define CHN5_SYNTH0_VCO_ATBH_VTAIL_SEL_MASK                                    0x10000
#define CHN5_SYNTH0_VCO_ATBH_VTAIL_SEL_GET(x)                                  (((x) & CHN5_SYNTH0_VCO_ATBH_VTAIL_SEL_MASK) >> CHN5_SYNTH0_VCO_ATBH_VTAIL_SEL_LSB)
#define CHN5_SYNTH0_VCO_ATBH_VTAIL_SEL_SET(x)                                  (((0 | (x)) << CHN5_SYNTH0_VCO_ATBH_VTAIL_SEL_LSB) & CHN5_SYNTH0_VCO_ATBH_VTAIL_SEL_MASK)
#define CHN5_SYNTH0_VCO_ATBH_VTAIL_SEL_RESET                                   0x0
#define CHN5_SYNTH0_REG_SYN_ENABLE_LSB                                         15
#define CHN5_SYNTH0_REG_SYN_ENABLE_MSB                                         15
#define CHN5_SYNTH0_REG_SYN_ENABLE_MASK                                        0x8000
#define CHN5_SYNTH0_REG_SYN_ENABLE_GET(x)                                      (((x) & CHN5_SYNTH0_REG_SYN_ENABLE_MASK) >> CHN5_SYNTH0_REG_SYN_ENABLE_LSB)
#define CHN5_SYNTH0_REG_SYN_ENABLE_SET(x)                                      (((0 | (x)) << CHN5_SYNTH0_REG_SYN_ENABLE_LSB) & CHN5_SYNTH0_REG_SYN_ENABLE_MASK)
#define CHN5_SYNTH0_REG_SYN_ENABLE_RESET                                       0x1
#define CHN5_SYNTH0_REG_SYN_BYPASS_LSB                                         14
#define CHN5_SYNTH0_REG_SYN_BYPASS_MSB                                         14
#define CHN5_SYNTH0_REG_SYN_BYPASS_MASK                                        0x4000
#define CHN5_SYNTH0_REG_SYN_BYPASS_GET(x)                                      (((x) & CHN5_SYNTH0_REG_SYN_BYPASS_MASK) >> CHN5_SYNTH0_REG_SYN_BYPASS_LSB)
#define CHN5_SYNTH0_REG_SYN_BYPASS_SET(x)                                      (((0 | (x)) << CHN5_SYNTH0_REG_SYN_BYPASS_LSB) & CHN5_SYNTH0_REG_SYN_BYPASS_MASK)
#define CHN5_SYNTH0_REG_SYN_BYPASS_RESET                                       0x0
#define CHN5_SYNTH0_REG_LO_ENABLE_LSB                                          13
#define CHN5_SYNTH0_REG_LO_ENABLE_MSB                                          13
#define CHN5_SYNTH0_REG_LO_ENABLE_MASK                                         0x2000
#define CHN5_SYNTH0_REG_LO_ENABLE_GET(x)                                       (((x) & CHN5_SYNTH0_REG_LO_ENABLE_MASK) >> CHN5_SYNTH0_REG_LO_ENABLE_LSB)
#define CHN5_SYNTH0_REG_LO_ENABLE_SET(x)                                       (((0 | (x)) << CHN5_SYNTH0_REG_LO_ENABLE_LSB) & CHN5_SYNTH0_REG_LO_ENABLE_MASK)
#define CHN5_SYNTH0_REG_LO_ENABLE_RESET                                        0x1
#define CHN5_SYNTH0_REG_LO_BYPASS_LSB                                          12
#define CHN5_SYNTH0_REG_LO_BYPASS_MSB                                          12
#define CHN5_SYNTH0_REG_LO_BYPASS_MASK                                         0x1000
#define CHN5_SYNTH0_REG_LO_BYPASS_GET(x)                                       (((x) & CHN5_SYNTH0_REG_LO_BYPASS_MASK) >> CHN5_SYNTH0_REG_LO_BYPASS_LSB)
#define CHN5_SYNTH0_REG_LO_BYPASS_SET(x)                                       (((0 | (x)) << CHN5_SYNTH0_REG_LO_BYPASS_LSB) & CHN5_SYNTH0_REG_LO_BYPASS_MASK)
#define CHN5_SYNTH0_REG_LO_BYPASS_RESET                                        0x0
#define CHN5_SYNTH0_FORCE_SHORTR_REFGEN_LSB                                    11
#define CHN5_SYNTH0_FORCE_SHORTR_REFGEN_MSB                                    11
#define CHN5_SYNTH0_FORCE_SHORTR_REFGEN_MASK                                   0x800
#define CHN5_SYNTH0_FORCE_SHORTR_REFGEN_GET(x)                                 (((x) & CHN5_SYNTH0_FORCE_SHORTR_REFGEN_MASK) >> CHN5_SYNTH0_FORCE_SHORTR_REFGEN_LSB)
#define CHN5_SYNTH0_FORCE_SHORTR_REFGEN_SET(x)                                 (((0 | (x)) << CHN5_SYNTH0_FORCE_SHORTR_REFGEN_LSB) & CHN5_SYNTH0_FORCE_SHORTR_REFGEN_MASK)
#define CHN5_SYNTH0_FORCE_SHORTR_REFGEN_RESET                                  0x0
#define CHN5_SYNTH0_REG_SHORTR_REFGEN_OVR_LSB                                  10
#define CHN5_SYNTH0_REG_SHORTR_REFGEN_OVR_MSB                                  10
#define CHN5_SYNTH0_REG_SHORTR_REFGEN_OVR_MASK                                 0x400
#define CHN5_SYNTH0_REG_SHORTR_REFGEN_OVR_GET(x)                               (((x) & CHN5_SYNTH0_REG_SHORTR_REFGEN_OVR_MASK) >> CHN5_SYNTH0_REG_SHORTR_REFGEN_OVR_LSB)
#define CHN5_SYNTH0_REG_SHORTR_REFGEN_OVR_SET(x)                               (((0 | (x)) << CHN5_SYNTH0_REG_SHORTR_REFGEN_OVR_LSB) & CHN5_SYNTH0_REG_SHORTR_REFGEN_OVR_MASK)
#define CHN5_SYNTH0_REG_SHORTR_REFGEN_OVR_RESET                                0x0
#define CHN5_SYNTH0_REG_VREF_AMP_LSB                                           8
#define CHN5_SYNTH0_REG_VREF_AMP_MSB                                           9
#define CHN5_SYNTH0_REG_VREF_AMP_MASK                                          0x300
#define CHN5_SYNTH0_REG_VREF_AMP_GET(x)                                        (((x) & CHN5_SYNTH0_REG_VREF_AMP_MASK) >> CHN5_SYNTH0_REG_VREF_AMP_LSB)
#define CHN5_SYNTH0_REG_VREF_AMP_SET(x)                                        (((0 | (x)) << CHN5_SYNTH0_REG_VREF_AMP_LSB) & CHN5_SYNTH0_REG_VREF_AMP_MASK)
#define CHN5_SYNTH0_REG_VREF_AMP_RESET                                         0x1
#define CHN5_SYNTH0_REG_EN_LVMODE_LSB                                          7
#define CHN5_SYNTH0_REG_EN_LVMODE_MSB                                          7
#define CHN5_SYNTH0_REG_EN_LVMODE_MASK                                         0x80
#define CHN5_SYNTH0_REG_EN_LVMODE_GET(x)                                       (((x) & CHN5_SYNTH0_REG_EN_LVMODE_MASK) >> CHN5_SYNTH0_REG_EN_LVMODE_LSB)
#define CHN5_SYNTH0_REG_EN_LVMODE_SET(x)                                       (((0 | (x)) << CHN5_SYNTH0_REG_EN_LVMODE_LSB) & CHN5_SYNTH0_REG_EN_LVMODE_MASK)
#define CHN5_SYNTH0_REG_EN_LVMODE_RESET                                        0x0
#define CHN5_SYNTH0_FBDIV_RSTB_LSB                                             6
#define CHN5_SYNTH0_FBDIV_RSTB_MSB                                             6
#define CHN5_SYNTH0_FBDIV_RSTB_MASK                                            0x40
#define CHN5_SYNTH0_FBDIV_RSTB_GET(x)                                          (((x) & CHN5_SYNTH0_FBDIV_RSTB_MASK) >> CHN5_SYNTH0_FBDIV_RSTB_LSB)
#define CHN5_SYNTH0_FBDIV_RSTB_SET(x)                                          (((0 | (x)) << CHN5_SYNTH0_FBDIV_RSTB_LSB) & CHN5_SYNTH0_FBDIV_RSTB_MASK)
#define CHN5_SYNTH0_FBDIV_RSTB_RESET                                           0x1
#define CHN5_SYNTH0_FBDIV_PULSE_WIDTH_LSB                                      4
#define CHN5_SYNTH0_FBDIV_PULSE_WIDTH_MSB                                      5
#define CHN5_SYNTH0_FBDIV_PULSE_WIDTH_MASK                                     0x30
#define CHN5_SYNTH0_FBDIV_PULSE_WIDTH_GET(x)                                   (((x) & CHN5_SYNTH0_FBDIV_PULSE_WIDTH_MASK) >> CHN5_SYNTH0_FBDIV_PULSE_WIDTH_LSB)
#define CHN5_SYNTH0_FBDIV_PULSE_WIDTH_SET(x)                                   (((0 | (x)) << CHN5_SYNTH0_FBDIV_PULSE_WIDTH_LSB) & CHN5_SYNTH0_FBDIV_PULSE_WIDTH_MASK)
#define CHN5_SYNTH0_FBDIV_PULSE_WIDTH_RESET                                    0x1
#define CHN5_SYNTH0_RESERVED_LSB                                               0
#define CHN5_SYNTH0_RESERVED_MSB                                               3
#define CHN5_SYNTH0_RESERVED_MASK                                              0xf
#define CHN5_SYNTH0_RESERVED_GET(x)                                            (((x) & CHN5_SYNTH0_RESERVED_MASK) >> CHN5_SYNTH0_RESERVED_LSB)
#define CHN5_SYNTH0_RESERVED_SET(x)                                            (((0 | (x)) << CHN5_SYNTH0_RESERVED_LSB) & CHN5_SYNTH0_RESERVED_MASK)
#define CHN5_SYNTH0_RESERVED_RESET                                             0x0
#define CHN5_SYNTH0_ADDRESS                                                    (0x0 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH0_RSTMASK                                                    0xffffffff
#define CHN5_SYNTH0_RESET                                                      0xa150

// 0x4 (CHN5_SYNTH1)
#define CHN5_SYNTH1_REFMULT_ENABLE_LSB                                         31
#define CHN5_SYNTH1_REFMULT_ENABLE_MSB                                         31
#define CHN5_SYNTH1_REFMULT_ENABLE_MASK                                        0x80000000
#define CHN5_SYNTH1_REFMULT_ENABLE_GET(x)                                      (((x) & CHN5_SYNTH1_REFMULT_ENABLE_MASK) >> CHN5_SYNTH1_REFMULT_ENABLE_LSB)
#define CHN5_SYNTH1_REFMULT_ENABLE_SET(x)                                      (((0 | (x)) << CHN5_SYNTH1_REFMULT_ENABLE_LSB) & CHN5_SYNTH1_REFMULT_ENABLE_MASK)
#define CHN5_SYNTH1_REFMULT_ENABLE_RESET                                       0x1
#define CHN5_SYNTH1_REFMULT_A01_LSB                                            28
#define CHN5_SYNTH1_REFMULT_A01_MSB                                            30
#define CHN5_SYNTH1_REFMULT_A01_MASK                                           0x70000000
#define CHN5_SYNTH1_REFMULT_A01_GET(x)                                         (((x) & CHN5_SYNTH1_REFMULT_A01_MASK) >> CHN5_SYNTH1_REFMULT_A01_LSB)
#define CHN5_SYNTH1_REFMULT_A01_SET(x)                                         (((0 | (x)) << CHN5_SYNTH1_REFMULT_A01_LSB) & CHN5_SYNTH1_REFMULT_A01_MASK)
#define CHN5_SYNTH1_REFMULT_A01_RESET                                          0x1
#define CHN5_SYNTH1_REFMULT_A23_LSB                                            25
#define CHN5_SYNTH1_REFMULT_A23_MSB                                            27
#define CHN5_SYNTH1_REFMULT_A23_MASK                                           0xe000000
#define CHN5_SYNTH1_REFMULT_A23_GET(x)                                         (((x) & CHN5_SYNTH1_REFMULT_A23_MASK) >> CHN5_SYNTH1_REFMULT_A23_LSB)
#define CHN5_SYNTH1_REFMULT_A23_SET(x)                                         (((0 | (x)) << CHN5_SYNTH1_REFMULT_A23_LSB) & CHN5_SYNTH1_REFMULT_A23_MASK)
#define CHN5_SYNTH1_REFMULT_A23_RESET                                          0x1
#define CHN5_SYNTH1_REFMULT_XTALEDGESEL_LSB                                    24
#define CHN5_SYNTH1_REFMULT_XTALEDGESEL_MSB                                    24
#define CHN5_SYNTH1_REFMULT_XTALEDGESEL_MASK                                   0x1000000
#define CHN5_SYNTH1_REFMULT_XTALEDGESEL_GET(x)                                 (((x) & CHN5_SYNTH1_REFMULT_XTALEDGESEL_MASK) >> CHN5_SYNTH1_REFMULT_XTALEDGESEL_LSB)
#define CHN5_SYNTH1_REFMULT_XTALEDGESEL_SET(x)                                 (((0 | (x)) << CHN5_SYNTH1_REFMULT_XTALEDGESEL_LSB) & CHN5_SYNTH1_REFMULT_XTALEDGESEL_MASK)
#define CHN5_SYNTH1_REFMULT_XTALEDGESEL_RESET                                  0x0
#define CHN5_SYNTH1_DLL_PDCAL_LSB                                              23
#define CHN5_SYNTH1_DLL_PDCAL_MSB                                              23
#define CHN5_SYNTH1_DLL_PDCAL_MASK                                             0x800000
#define CHN5_SYNTH1_DLL_PDCAL_GET(x)                                           (((x) & CHN5_SYNTH1_DLL_PDCAL_MASK) >> CHN5_SYNTH1_DLL_PDCAL_LSB)
#define CHN5_SYNTH1_DLL_PDCAL_SET(x)                                           (((0 | (x)) << CHN5_SYNTH1_DLL_PDCAL_LSB) & CHN5_SYNTH1_DLL_PDCAL_MASK)
#define CHN5_SYNTH1_DLL_PDCAL_RESET                                            0x1
#define CHN5_SYNTH1_DLL_CPCAL_A01_LSB                                          21
#define CHN5_SYNTH1_DLL_CPCAL_A01_MSB                                          22
#define CHN5_SYNTH1_DLL_CPCAL_A01_MASK                                         0x600000
#define CHN5_SYNTH1_DLL_CPCAL_A01_GET(x)                                       (((x) & CHN5_SYNTH1_DLL_CPCAL_A01_MASK) >> CHN5_SYNTH1_DLL_CPCAL_A01_LSB)
#define CHN5_SYNTH1_DLL_CPCAL_A01_SET(x)                                       (((0 | (x)) << CHN5_SYNTH1_DLL_CPCAL_A01_LSB) & CHN5_SYNTH1_DLL_CPCAL_A01_MASK)
#define CHN5_SYNTH1_DLL_CPCAL_A01_RESET                                        0x2
#define CHN5_SYNTH1_DLL_CPCAL_A23_LSB                                          19
#define CHN5_SYNTH1_DLL_CPCAL_A23_MSB                                          20
#define CHN5_SYNTH1_DLL_CPCAL_A23_MASK                                         0x180000
#define CHN5_SYNTH1_DLL_CPCAL_A23_GET(x)                                       (((x) & CHN5_SYNTH1_DLL_CPCAL_A23_MASK) >> CHN5_SYNTH1_DLL_CPCAL_A23_LSB)
#define CHN5_SYNTH1_DLL_CPCAL_A23_SET(x)                                       (((0 | (x)) << CHN5_SYNTH1_DLL_CPCAL_A23_LSB) & CHN5_SYNTH1_DLL_CPCAL_A23_MASK)
#define CHN5_SYNTH1_DLL_CPCAL_A23_RESET                                        0x2
#define CHN5_SYNTH1_DLL_VCL_LSB                                                17
#define CHN5_SYNTH1_DLL_VCL_MSB                                                18
#define CHN5_SYNTH1_DLL_VCL_MASK                                               0x60000
#define CHN5_SYNTH1_DLL_VCL_GET(x)                                             (((x) & CHN5_SYNTH1_DLL_VCL_MASK) >> CHN5_SYNTH1_DLL_VCL_LSB)
#define CHN5_SYNTH1_DLL_VCL_SET(x)                                             (((0 | (x)) << CHN5_SYNTH1_DLL_VCL_LSB) & CHN5_SYNTH1_DLL_VCL_MASK)
#define CHN5_SYNTH1_DLL_VCL_RESET                                              0x0
#define CHN5_SYNTH1_DLL_VCH_LSB                                                15
#define CHN5_SYNTH1_DLL_VCH_MSB                                                16
#define CHN5_SYNTH1_DLL_VCH_MASK                                               0x18000
#define CHN5_SYNTH1_DLL_VCH_GET(x)                                             (((x) & CHN5_SYNTH1_DLL_VCH_MASK) >> CHN5_SYNTH1_DLL_VCH_LSB)
#define CHN5_SYNTH1_DLL_VCH_SET(x)                                             (((0 | (x)) << CHN5_SYNTH1_DLL_VCH_LSB) & CHN5_SYNTH1_DLL_VCH_MASK)
#define CHN5_SYNTH1_DLL_VCH_RESET                                              0x0
#define CHN5_SYNTH1_DLL_FORCE_CAPCUR_LSB                                       14
#define CHN5_SYNTH1_DLL_FORCE_CAPCUR_MSB                                       14
#define CHN5_SYNTH1_DLL_FORCE_CAPCUR_MASK                                      0x4000
#define CHN5_SYNTH1_DLL_FORCE_CAPCUR_GET(x)                                    (((x) & CHN5_SYNTH1_DLL_FORCE_CAPCUR_MASK) >> CHN5_SYNTH1_DLL_FORCE_CAPCUR_LSB)
#define CHN5_SYNTH1_DLL_FORCE_CAPCUR_SET(x)                                    (((0 | (x)) << CHN5_SYNTH1_DLL_FORCE_CAPCUR_LSB) & CHN5_SYNTH1_DLL_FORCE_CAPCUR_MASK)
#define CHN5_SYNTH1_DLL_FORCE_CAPCUR_RESET                                     0x0
#define CHN5_SYNTH1_REFMULT_DLL_VCOCAP_MSB_LSB                                 13
#define CHN5_SYNTH1_REFMULT_DLL_VCOCAP_MSB_MSB                                 13
#define CHN5_SYNTH1_REFMULT_DLL_VCOCAP_MSB_MASK                                0x2000
#define CHN5_SYNTH1_REFMULT_DLL_VCOCAP_MSB_GET(x)                              (((x) & CHN5_SYNTH1_REFMULT_DLL_VCOCAP_MSB_MASK) >> CHN5_SYNTH1_REFMULT_DLL_VCOCAP_MSB_LSB)
#define CHN5_SYNTH1_REFMULT_DLL_VCOCAP_MSB_SET(x)                              (((0 | (x)) << CHN5_SYNTH1_REFMULT_DLL_VCOCAP_MSB_LSB) & CHN5_SYNTH1_REFMULT_DLL_VCOCAP_MSB_MASK)
#define CHN5_SYNTH1_REFMULT_DLL_VCOCAP_MSB_RESET                               0x0
#define CHN5_SYNTH1_DLL_VCOCAP_A01_LSB                                         10
#define CHN5_SYNTH1_DLL_VCOCAP_A01_MSB                                         12
#define CHN5_SYNTH1_DLL_VCOCAP_A01_MASK                                        0x1c00
#define CHN5_SYNTH1_DLL_VCOCAP_A01_GET(x)                                      (((x) & CHN5_SYNTH1_DLL_VCOCAP_A01_MASK) >> CHN5_SYNTH1_DLL_VCOCAP_A01_LSB)
#define CHN5_SYNTH1_DLL_VCOCAP_A01_SET(x)                                      (((0 | (x)) << CHN5_SYNTH1_DLL_VCOCAP_A01_LSB) & CHN5_SYNTH1_DLL_VCOCAP_A01_MASK)
#define CHN5_SYNTH1_DLL_VCOCAP_A01_RESET                                       0x3
#define CHN5_SYNTH1_DLL_VCOCAP_A23_LSB                                         7
#define CHN5_SYNTH1_DLL_VCOCAP_A23_MSB                                         9
#define CHN5_SYNTH1_DLL_VCOCAP_A23_MASK                                        0x380
#define CHN5_SYNTH1_DLL_VCOCAP_A23_GET(x)                                      (((x) & CHN5_SYNTH1_DLL_VCOCAP_A23_MASK) >> CHN5_SYNTH1_DLL_VCOCAP_A23_LSB)
#define CHN5_SYNTH1_DLL_VCOCAP_A23_SET(x)                                      (((0 | (x)) << CHN5_SYNTH1_DLL_VCOCAP_A23_LSB) & CHN5_SYNTH1_DLL_VCOCAP_A23_MASK)
#define CHN5_SYNTH1_DLL_VCOCAP_A23_RESET                                       0x3
#define CHN5_SYNTH1_REFMULT_DLL_VCOCUR_MSB_LSB                                 6
#define CHN5_SYNTH1_REFMULT_DLL_VCOCUR_MSB_MSB                                 6
#define CHN5_SYNTH1_REFMULT_DLL_VCOCUR_MSB_MASK                                0x40
#define CHN5_SYNTH1_REFMULT_DLL_VCOCUR_MSB_GET(x)                              (((x) & CHN5_SYNTH1_REFMULT_DLL_VCOCUR_MSB_MASK) >> CHN5_SYNTH1_REFMULT_DLL_VCOCUR_MSB_LSB)
#define CHN5_SYNTH1_REFMULT_DLL_VCOCUR_MSB_SET(x)                              (((0 | (x)) << CHN5_SYNTH1_REFMULT_DLL_VCOCUR_MSB_LSB) & CHN5_SYNTH1_REFMULT_DLL_VCOCUR_MSB_MASK)
#define CHN5_SYNTH1_REFMULT_DLL_VCOCUR_MSB_RESET                               0x0
#define CHN5_SYNTH1_DLL_VCOCUR_A01_LSB                                         3
#define CHN5_SYNTH1_DLL_VCOCUR_A01_MSB                                         5
#define CHN5_SYNTH1_DLL_VCOCUR_A01_MASK                                        0x38
#define CHN5_SYNTH1_DLL_VCOCUR_A01_GET(x)                                      (((x) & CHN5_SYNTH1_DLL_VCOCUR_A01_MASK) >> CHN5_SYNTH1_DLL_VCOCUR_A01_LSB)
#define CHN5_SYNTH1_DLL_VCOCUR_A01_SET(x)                                      (((0 | (x)) << CHN5_SYNTH1_DLL_VCOCUR_A01_LSB) & CHN5_SYNTH1_DLL_VCOCUR_A01_MASK)
#define CHN5_SYNTH1_DLL_VCOCUR_A01_RESET                                       0x0
#define CHN5_SYNTH1_DLL_VCOCUR_A23_LSB                                         0
#define CHN5_SYNTH1_DLL_VCOCUR_A23_MSB                                         2
#define CHN5_SYNTH1_DLL_VCOCUR_A23_MASK                                        0x7
#define CHN5_SYNTH1_DLL_VCOCUR_A23_GET(x)                                      (((x) & CHN5_SYNTH1_DLL_VCOCUR_A23_MASK) >> CHN5_SYNTH1_DLL_VCOCUR_A23_LSB)
#define CHN5_SYNTH1_DLL_VCOCUR_A23_SET(x)                                      (((0 | (x)) << CHN5_SYNTH1_DLL_VCOCUR_A23_LSB) & CHN5_SYNTH1_DLL_VCOCUR_A23_MASK)
#define CHN5_SYNTH1_DLL_VCOCUR_A23_RESET                                       0x0
#define CHN5_SYNTH1_ADDRESS                                                    (0x4 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH1_RSTMASK                                                    0xffffffff
#define CHN5_SYNTH1_RESET                                                      0x92d00d80

// 0x8 (CHN5_SYNTH2)
#define CHN5_SYNTH2_DLL_CP_A01_LSB                                             28
#define CHN5_SYNTH2_DLL_CP_A01_MSB                                             31
#define CHN5_SYNTH2_DLL_CP_A01_MASK                                            0xf0000000
#define CHN5_SYNTH2_DLL_CP_A01_GET(x)                                          (((x) & CHN5_SYNTH2_DLL_CP_A01_MASK) >> CHN5_SYNTH2_DLL_CP_A01_LSB)
#define CHN5_SYNTH2_DLL_CP_A01_SET(x)                                          (((0 | (x)) << CHN5_SYNTH2_DLL_CP_A01_LSB) & CHN5_SYNTH2_DLL_CP_A01_MASK)
#define CHN5_SYNTH2_DLL_CP_A01_RESET                                           0x3
#define CHN5_SYNTH2_DLL_CP_A23_LSB                                             24
#define CHN5_SYNTH2_DLL_CP_A23_MSB                                             27
#define CHN5_SYNTH2_DLL_CP_A23_MASK                                            0xf000000
#define CHN5_SYNTH2_DLL_CP_A23_GET(x)                                          (((x) & CHN5_SYNTH2_DLL_CP_A23_MASK) >> CHN5_SYNTH2_DLL_CP_A23_LSB)
#define CHN5_SYNTH2_DLL_CP_A23_SET(x)                                          (((0 | (x)) << CHN5_SYNTH2_DLL_CP_A23_LSB) & CHN5_SYNTH2_DLL_CP_A23_MASK)
#define CHN5_SYNTH2_DLL_CP_A23_RESET                                           0x3
#define CHN5_SYNTH2_REFMULT_FORCE_DLL_ON_LSB                                   23
#define CHN5_SYNTH2_REFMULT_FORCE_DLL_ON_MSB                                   23
#define CHN5_SYNTH2_REFMULT_FORCE_DLL_ON_MASK                                  0x800000
#define CHN5_SYNTH2_REFMULT_FORCE_DLL_ON_GET(x)                                (((x) & CHN5_SYNTH2_REFMULT_FORCE_DLL_ON_MASK) >> CHN5_SYNTH2_REFMULT_FORCE_DLL_ON_LSB)
#define CHN5_SYNTH2_REFMULT_FORCE_DLL_ON_SET(x)                                (((0 | (x)) << CHN5_SYNTH2_REFMULT_FORCE_DLL_ON_LSB) & CHN5_SYNTH2_REFMULT_FORCE_DLL_ON_MASK)
#define CHN5_SYNTH2_REFMULT_FORCE_DLL_ON_RESET                                 0x0
#define CHN5_SYNTH2_DLL_CHANGE_CAP_FIRST_LSB                                   22
#define CHN5_SYNTH2_DLL_CHANGE_CAP_FIRST_MSB                                   22
#define CHN5_SYNTH2_DLL_CHANGE_CAP_FIRST_MASK                                  0x400000
#define CHN5_SYNTH2_DLL_CHANGE_CAP_FIRST_GET(x)                                (((x) & CHN5_SYNTH2_DLL_CHANGE_CAP_FIRST_MASK) >> CHN5_SYNTH2_DLL_CHANGE_CAP_FIRST_LSB)
#define CHN5_SYNTH2_DLL_CHANGE_CAP_FIRST_SET(x)                                (((0 | (x)) << CHN5_SYNTH2_DLL_CHANGE_CAP_FIRST_LSB) & CHN5_SYNTH2_DLL_CHANGE_CAP_FIRST_MASK)
#define CHN5_SYNTH2_DLL_CHANGE_CAP_FIRST_RESET                                 0x0
#define CHN5_SYNTH2_FORCE_DLL_IS_LOCKED_LSB                                    21
#define CHN5_SYNTH2_FORCE_DLL_IS_LOCKED_MSB                                    21
#define CHN5_SYNTH2_FORCE_DLL_IS_LOCKED_MASK                                   0x200000
#define CHN5_SYNTH2_FORCE_DLL_IS_LOCKED_GET(x)                                 (((x) & CHN5_SYNTH2_FORCE_DLL_IS_LOCKED_MASK) >> CHN5_SYNTH2_FORCE_DLL_IS_LOCKED_LSB)
#define CHN5_SYNTH2_FORCE_DLL_IS_LOCKED_SET(x)                                 (((0 | (x)) << CHN5_SYNTH2_FORCE_DLL_IS_LOCKED_LSB) & CHN5_SYNTH2_FORCE_DLL_IS_LOCKED_MASK)
#define CHN5_SYNTH2_FORCE_DLL_IS_LOCKED_RESET                                  0x0
#define CHN5_SYNTH2_DLL_IS_LOCKED_OVR_LSB                                      20
#define CHN5_SYNTH2_DLL_IS_LOCKED_OVR_MSB                                      20
#define CHN5_SYNTH2_DLL_IS_LOCKED_OVR_MASK                                     0x100000
#define CHN5_SYNTH2_DLL_IS_LOCKED_OVR_GET(x)                                   (((x) & CHN5_SYNTH2_DLL_IS_LOCKED_OVR_MASK) >> CHN5_SYNTH2_DLL_IS_LOCKED_OVR_LSB)
#define CHN5_SYNTH2_DLL_IS_LOCKED_OVR_SET(x)                                   (((0 | (x)) << CHN5_SYNTH2_DLL_IS_LOCKED_OVR_LSB) & CHN5_SYNTH2_DLL_IS_LOCKED_OVR_MASK)
#define CHN5_SYNTH2_DLL_IS_LOCKED_OVR_RESET                                    0x1
#define CHN5_SYNTH2_WAIT_DLLSM_LSB                                             16
#define CHN5_SYNTH2_WAIT_DLLSM_MSB                                             19
#define CHN5_SYNTH2_WAIT_DLLSM_MASK                                            0xf0000
#define CHN5_SYNTH2_WAIT_DLLSM_GET(x)                                          (((x) & CHN5_SYNTH2_WAIT_DLLSM_MASK) >> CHN5_SYNTH2_WAIT_DLLSM_LSB)
#define CHN5_SYNTH2_WAIT_DLLSM_SET(x)                                          (((0 | (x)) << CHN5_SYNTH2_WAIT_DLLSM_LSB) & CHN5_SYNTH2_WAIT_DLLSM_MASK)
#define CHN5_SYNTH2_WAIT_DLLSM_RESET                                           0x5
#define CHN5_SYNTH2_DLL_VC_CHK_CNT_LSB                                         12
#define CHN5_SYNTH2_DLL_VC_CHK_CNT_MSB                                         15
#define CHN5_SYNTH2_DLL_VC_CHK_CNT_MASK                                        0xf000
#define CHN5_SYNTH2_DLL_VC_CHK_CNT_GET(x)                                      (((x) & CHN5_SYNTH2_DLL_VC_CHK_CNT_MASK) >> CHN5_SYNTH2_DLL_VC_CHK_CNT_LSB)
#define CHN5_SYNTH2_DLL_VC_CHK_CNT_SET(x)                                      (((0 | (x)) << CHN5_SYNTH2_DLL_VC_CHK_CNT_LSB) & CHN5_SYNTH2_DLL_VC_CHK_CNT_MASK)
#define CHN5_SYNTH2_DLL_VC_CHK_CNT_RESET                                       0x5
#define CHN5_SYNTH2_MONITORDLL_LSB                                             10
#define CHN5_SYNTH2_MONITORDLL_MSB                                             11
#define CHN5_SYNTH2_MONITORDLL_MASK                                            0xc00
#define CHN5_SYNTH2_MONITORDLL_GET(x)                                          (((x) & CHN5_SYNTH2_MONITORDLL_MASK) >> CHN5_SYNTH2_MONITORDLL_LSB)
#define CHN5_SYNTH2_MONITORDLL_SET(x)                                          (((0 | (x)) << CHN5_SYNTH2_MONITORDLL_LSB) & CHN5_SYNTH2_MONITORDLL_MASK)
#define CHN5_SYNTH2_MONITORDLL_RESET                                           0x0
#define CHN5_SYNTH2_RESERVED_LSB                                               0
#define CHN5_SYNTH2_RESERVED_MSB                                               9
#define CHN5_SYNTH2_RESERVED_MASK                                              0x3ff
#define CHN5_SYNTH2_RESERVED_GET(x)                                            (((x) & CHN5_SYNTH2_RESERVED_MASK) >> CHN5_SYNTH2_RESERVED_LSB)
#define CHN5_SYNTH2_RESERVED_SET(x)                                            (((0 | (x)) << CHN5_SYNTH2_RESERVED_LSB) & CHN5_SYNTH2_RESERVED_MASK)
#define CHN5_SYNTH2_RESERVED_RESET                                             0x0
#define CHN5_SYNTH2_ADDRESS                                                    (0x8 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH2_RSTMASK                                                    0xffffffff
#define CHN5_SYNTH2_RESET                                                      0x33155000

// 0xc (CHN5_SYNTH3)
#define CHN5_SYNTH3_PFDCP_ENABLE_LSB                                           31
#define CHN5_SYNTH3_PFDCP_ENABLE_MSB                                           31
#define CHN5_SYNTH3_PFDCP_ENABLE_MASK                                          0x80000000
#define CHN5_SYNTH3_PFDCP_ENABLE_GET(x)                                        (((x) & CHN5_SYNTH3_PFDCP_ENABLE_MASK) >> CHN5_SYNTH3_PFDCP_ENABLE_LSB)
#define CHN5_SYNTH3_PFDCP_ENABLE_SET(x)                                        (((0 | (x)) << CHN5_SYNTH3_PFDCP_ENABLE_LSB) & CHN5_SYNTH3_PFDCP_ENABLE_MASK)
#define CHN5_SYNTH3_PFDCP_ENABLE_RESET                                         0x1
#define CHN5_SYNTH3_PFDCP_PFDRSTB_LSB                                          30
#define CHN5_SYNTH3_PFDCP_PFDRSTB_MSB                                          30
#define CHN5_SYNTH3_PFDCP_PFDRSTB_MASK                                         0x40000000
#define CHN5_SYNTH3_PFDCP_PFDRSTB_GET(x)                                       (((x) & CHN5_SYNTH3_PFDCP_PFDRSTB_MASK) >> CHN5_SYNTH3_PFDCP_PFDRSTB_LSB)
#define CHN5_SYNTH3_PFDCP_PFDRSTB_SET(x)                                       (((0 | (x)) << CHN5_SYNTH3_PFDCP_PFDRSTB_LSB) & CHN5_SYNTH3_PFDCP_PFDRSTB_MASK)
#define CHN5_SYNTH3_PFDCP_PFDRSTB_RESET                                        0x1
#define CHN5_SYNTH3_PFDCP_BIASMULT_LSB                                         26
#define CHN5_SYNTH3_PFDCP_BIASMULT_MSB                                         29
#define CHN5_SYNTH3_PFDCP_BIASMULT_MASK                                        0x3c000000
#define CHN5_SYNTH3_PFDCP_BIASMULT_GET(x)                                      (((x) & CHN5_SYNTH3_PFDCP_BIASMULT_MASK) >> CHN5_SYNTH3_PFDCP_BIASMULT_LSB)
#define CHN5_SYNTH3_PFDCP_BIASMULT_SET(x)                                      (((0 | (x)) << CHN5_SYNTH3_PFDCP_BIASMULT_LSB) & CHN5_SYNTH3_PFDCP_BIASMULT_MASK)
#define CHN5_SYNTH3_PFDCP_BIASMULT_RESET                                       0xf
#define CHN5_SYNTH3_ICPA0_LSB                                                  20
#define CHN5_SYNTH3_ICPA0_MSB                                                  25
#define CHN5_SYNTH3_ICPA0_MASK                                                 0x3f00000
#define CHN5_SYNTH3_ICPA0_GET(x)                                               (((x) & CHN5_SYNTH3_ICPA0_MASK) >> CHN5_SYNTH3_ICPA0_LSB)
#define CHN5_SYNTH3_ICPA0_SET(x)                                               (((0 | (x)) << CHN5_SYNTH3_ICPA0_LSB) & CHN5_SYNTH3_ICPA0_MASK)
#define CHN5_SYNTH3_ICPA0_RESET                                                0x14
#define CHN5_SYNTH3_ICPLKA0_LSB                                                14
#define CHN5_SYNTH3_ICPLKA0_MSB                                                19
#define CHN5_SYNTH3_ICPLKA0_MASK                                               0xfc000
#define CHN5_SYNTH3_ICPLKA0_GET(x)                                             (((x) & CHN5_SYNTH3_ICPLKA0_MASK) >> CHN5_SYNTH3_ICPLKA0_LSB)
#define CHN5_SYNTH3_ICPLKA0_SET(x)                                             (((0 | (x)) << CHN5_SYNTH3_ICPLKA0_LSB) & CHN5_SYNTH3_ICPLKA0_MASK)
#define CHN5_SYNTH3_ICPLKA0_RESET                                              0x22
#define CHN5_SYNTH3_ICPA1_LSB                                                  8
#define CHN5_SYNTH3_ICPA1_MSB                                                  13
#define CHN5_SYNTH3_ICPA1_MASK                                                 0x3f00
#define CHN5_SYNTH3_ICPA1_GET(x)                                               (((x) & CHN5_SYNTH3_ICPA1_MASK) >> CHN5_SYNTH3_ICPA1_LSB)
#define CHN5_SYNTH3_ICPA1_SET(x)                                               (((0 | (x)) << CHN5_SYNTH3_ICPA1_LSB) & CHN5_SYNTH3_ICPA1_MASK)
#define CHN5_SYNTH3_ICPA1_RESET                                                0x14
#define CHN5_SYNTH3_ICPLKA1_LSB                                                2
#define CHN5_SYNTH3_ICPLKA1_MSB                                                7
#define CHN5_SYNTH3_ICPLKA1_MASK                                               0xfc
#define CHN5_SYNTH3_ICPLKA1_GET(x)                                             (((x) & CHN5_SYNTH3_ICPLKA1_MASK) >> CHN5_SYNTH3_ICPLKA1_LSB)
#define CHN5_SYNTH3_ICPLKA1_SET(x)                                             (((0 | (x)) << CHN5_SYNTH3_ICPLKA1_LSB) & CHN5_SYNTH3_ICPLKA1_MASK)
#define CHN5_SYNTH3_ICPLKA1_RESET                                              0x22
#define CHN5_SYNTH3_RESERVED_LSB                                               0
#define CHN5_SYNTH3_RESERVED_MSB                                               1
#define CHN5_SYNTH3_RESERVED_MASK                                              0x3
#define CHN5_SYNTH3_RESERVED_GET(x)                                            (((x) & CHN5_SYNTH3_RESERVED_MASK) >> CHN5_SYNTH3_RESERVED_LSB)
#define CHN5_SYNTH3_RESERVED_SET(x)                                            (((0 | (x)) << CHN5_SYNTH3_RESERVED_LSB) & CHN5_SYNTH3_RESERVED_MASK)
#define CHN5_SYNTH3_RESERVED_RESET                                             0x0
#define CHN5_SYNTH3_ADDRESS                                                    (0xc + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH3_RSTMASK                                                    0xffffffff
#define CHN5_SYNTH3_RESET                                                      0xfd489488

// 0x10 (CHN5_SYNTH4)
#define CHN5_SYNTH4_ICPA2_LSB                                                  26
#define CHN5_SYNTH4_ICPA2_MSB                                                  31
#define CHN5_SYNTH4_ICPA2_MASK                                                 0xfc000000
#define CHN5_SYNTH4_ICPA2_GET(x)                                               (((x) & CHN5_SYNTH4_ICPA2_MASK) >> CHN5_SYNTH4_ICPA2_LSB)
#define CHN5_SYNTH4_ICPA2_SET(x)                                               (((0 | (x)) << CHN5_SYNTH4_ICPA2_LSB) & CHN5_SYNTH4_ICPA2_MASK)
#define CHN5_SYNTH4_ICPA2_RESET                                                0x14
#define CHN5_SYNTH4_ICPLKA2_LSB                                                20
#define CHN5_SYNTH4_ICPLKA2_MSB                                                25
#define CHN5_SYNTH4_ICPLKA2_MASK                                               0x3f00000
#define CHN5_SYNTH4_ICPLKA2_GET(x)                                             (((x) & CHN5_SYNTH4_ICPLKA2_MASK) >> CHN5_SYNTH4_ICPLKA2_LSB)
#define CHN5_SYNTH4_ICPLKA2_SET(x)                                             (((0 | (x)) << CHN5_SYNTH4_ICPLKA2_LSB) & CHN5_SYNTH4_ICPLKA2_MASK)
#define CHN5_SYNTH4_ICPLKA2_RESET                                              0x22
#define CHN5_SYNTH4_ICPA3_LSB                                                  14
#define CHN5_SYNTH4_ICPA3_MSB                                                  19
#define CHN5_SYNTH4_ICPA3_MASK                                                 0xfc000
#define CHN5_SYNTH4_ICPA3_GET(x)                                               (((x) & CHN5_SYNTH4_ICPA3_MASK) >> CHN5_SYNTH4_ICPA3_LSB)
#define CHN5_SYNTH4_ICPA3_SET(x)                                               (((0 | (x)) << CHN5_SYNTH4_ICPA3_LSB) & CHN5_SYNTH4_ICPA3_MASK)
#define CHN5_SYNTH4_ICPA3_RESET                                                0x14
#define CHN5_SYNTH4_ICPLKA3_LSB                                                8
#define CHN5_SYNTH4_ICPLKA3_MSB                                                13
#define CHN5_SYNTH4_ICPLKA3_MASK                                               0x3f00
#define CHN5_SYNTH4_ICPLKA3_GET(x)                                             (((x) & CHN5_SYNTH4_ICPLKA3_MASK) >> CHN5_SYNTH4_ICPLKA3_LSB)
#define CHN5_SYNTH4_ICPLKA3_SET(x)                                             (((0 | (x)) << CHN5_SYNTH4_ICPLKA3_LSB) & CHN5_SYNTH4_ICPLKA3_MASK)
#define CHN5_SYNTH4_ICPLKA3_RESET                                              0x22
#define CHN5_SYNTH4_PFDCP_LKI2_LSB                                             4
#define CHN5_SYNTH4_PFDCP_LKI2_MSB                                             7
#define CHN5_SYNTH4_PFDCP_LKI2_MASK                                            0xf0
#define CHN5_SYNTH4_PFDCP_LKI2_GET(x)                                          (((x) & CHN5_SYNTH4_PFDCP_LKI2_MASK) >> CHN5_SYNTH4_PFDCP_LKI2_LSB)
#define CHN5_SYNTH4_PFDCP_LKI2_SET(x)                                          (((0 | (x)) << CHN5_SYNTH4_PFDCP_LKI2_LSB) & CHN5_SYNTH4_PFDCP_LKI2_MASK)
#define CHN5_SYNTH4_PFDCP_LKI2_RESET                                           0xf
#define CHN5_SYNTH4_PFDCP_LOWLK_2VC_LSB                                        3
#define CHN5_SYNTH4_PFDCP_LOWLK_2VC_MSB                                        3
#define CHN5_SYNTH4_PFDCP_LOWLK_2VC_MASK                                       0x8
#define CHN5_SYNTH4_PFDCP_LOWLK_2VC_GET(x)                                     (((x) & CHN5_SYNTH4_PFDCP_LOWLK_2VC_MASK) >> CHN5_SYNTH4_PFDCP_LOWLK_2VC_LSB)
#define CHN5_SYNTH4_PFDCP_LOWLK_2VC_SET(x)                                     (((0 | (x)) << CHN5_SYNTH4_PFDCP_LOWLK_2VC_LSB) & CHN5_SYNTH4_PFDCP_LOWLK_2VC_MASK)
#define CHN5_SYNTH4_PFDCP_LOWLK_2VC_RESET                                      0x0
#define CHN5_SYNTH4_PFDCP_ENPFDDEL_LSB                                         2
#define CHN5_SYNTH4_PFDCP_ENPFDDEL_MSB                                         2
#define CHN5_SYNTH4_PFDCP_ENPFDDEL_MASK                                        0x4
#define CHN5_SYNTH4_PFDCP_ENPFDDEL_GET(x)                                      (((x) & CHN5_SYNTH4_PFDCP_ENPFDDEL_MASK) >> CHN5_SYNTH4_PFDCP_ENPFDDEL_LSB)
#define CHN5_SYNTH4_PFDCP_ENPFDDEL_SET(x)                                      (((0 | (x)) << CHN5_SYNTH4_PFDCP_ENPFDDEL_LSB) & CHN5_SYNTH4_PFDCP_ENPFDDEL_MASK)
#define CHN5_SYNTH4_PFDCP_ENPFDDEL_RESET                                       0x0
#define CHN5_SYNTH4_FORCE_PINVC_LSB                                            1
#define CHN5_SYNTH4_FORCE_PINVC_MSB                                            1
#define CHN5_SYNTH4_FORCE_PINVC_MASK                                           0x2
#define CHN5_SYNTH4_FORCE_PINVC_GET(x)                                         (((x) & CHN5_SYNTH4_FORCE_PINVC_MASK) >> CHN5_SYNTH4_FORCE_PINVC_LSB)
#define CHN5_SYNTH4_FORCE_PINVC_SET(x)                                         (((0 | (x)) << CHN5_SYNTH4_FORCE_PINVC_LSB) & CHN5_SYNTH4_FORCE_PINVC_MASK)
#define CHN5_SYNTH4_FORCE_PINVC_RESET                                          0x0
#define CHN5_SYNTH4_PFDCP_TEST_EN_LSB                                          0
#define CHN5_SYNTH4_PFDCP_TEST_EN_MSB                                          0
#define CHN5_SYNTH4_PFDCP_TEST_EN_MASK                                         0x1
#define CHN5_SYNTH4_PFDCP_TEST_EN_GET(x)                                       (((x) & CHN5_SYNTH4_PFDCP_TEST_EN_MASK) >> CHN5_SYNTH4_PFDCP_TEST_EN_LSB)
#define CHN5_SYNTH4_PFDCP_TEST_EN_SET(x)                                       (((0 | (x)) << CHN5_SYNTH4_PFDCP_TEST_EN_LSB) & CHN5_SYNTH4_PFDCP_TEST_EN_MASK)
#define CHN5_SYNTH4_PFDCP_TEST_EN_RESET                                        0x0
#define CHN5_SYNTH4_ADDRESS                                                    (0x10 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH4_RSTMASK                                                    0xffffffff
#define CHN5_SYNTH4_RESET                                                      0x522522f0

// 0x14 (CHN5_SYNTH5)
#define CHN5_SYNTH5_LOOP_RSA0_LSB                                              27
#define CHN5_SYNTH5_LOOP_RSA0_MSB                                              31
#define CHN5_SYNTH5_LOOP_RSA0_MASK                                             0xf8000000
#define CHN5_SYNTH5_LOOP_RSA0_GET(x)                                           (((x) & CHN5_SYNTH5_LOOP_RSA0_MASK) >> CHN5_SYNTH5_LOOP_RSA0_LSB)
#define CHN5_SYNTH5_LOOP_RSA0_SET(x)                                           (((0 | (x)) << CHN5_SYNTH5_LOOP_RSA0_LSB) & CHN5_SYNTH5_LOOP_RSA0_MASK)
#define CHN5_SYNTH5_LOOP_RSA0_RESET                                            0x3
#define CHN5_SYNTH5_LOOP_RSA1_LSB                                              22
#define CHN5_SYNTH5_LOOP_RSA1_MSB                                              26
#define CHN5_SYNTH5_LOOP_RSA1_MASK                                             0x7c00000
#define CHN5_SYNTH5_LOOP_RSA1_GET(x)                                           (((x) & CHN5_SYNTH5_LOOP_RSA1_MASK) >> CHN5_SYNTH5_LOOP_RSA1_LSB)
#define CHN5_SYNTH5_LOOP_RSA1_SET(x)                                           (((0 | (x)) << CHN5_SYNTH5_LOOP_RSA1_LSB) & CHN5_SYNTH5_LOOP_RSA1_MASK)
#define CHN5_SYNTH5_LOOP_RSA1_RESET                                            0x3
#define CHN5_SYNTH5_LOOP_RSA2_LSB                                              17
#define CHN5_SYNTH5_LOOP_RSA2_MSB                                              21
#define CHN5_SYNTH5_LOOP_RSA2_MASK                                             0x3e0000
#define CHN5_SYNTH5_LOOP_RSA2_GET(x)                                           (((x) & CHN5_SYNTH5_LOOP_RSA2_MASK) >> CHN5_SYNTH5_LOOP_RSA2_LSB)
#define CHN5_SYNTH5_LOOP_RSA2_SET(x)                                           (((0 | (x)) << CHN5_SYNTH5_LOOP_RSA2_LSB) & CHN5_SYNTH5_LOOP_RSA2_MASK)
#define CHN5_SYNTH5_LOOP_RSA2_RESET                                            0x3
#define CHN5_SYNTH5_LOOP_RSA3_LSB                                              12
#define CHN5_SYNTH5_LOOP_RSA3_MSB                                              16
#define CHN5_SYNTH5_LOOP_RSA3_MASK                                             0x1f000
#define CHN5_SYNTH5_LOOP_RSA3_GET(x)                                           (((x) & CHN5_SYNTH5_LOOP_RSA3_MASK) >> CHN5_SYNTH5_LOOP_RSA3_LSB)
#define CHN5_SYNTH5_LOOP_RSA3_SET(x)                                           (((0 | (x)) << CHN5_SYNTH5_LOOP_RSA3_LSB) & CHN5_SYNTH5_LOOP_RSA3_MASK)
#define CHN5_SYNTH5_LOOP_RSA3_RESET                                            0x3
#define CHN5_SYNTH5_LPF_EN_VCMON_LSB                                           11
#define CHN5_SYNTH5_LPF_EN_VCMON_MSB                                           11
#define CHN5_SYNTH5_LPF_EN_VCMON_MASK                                          0x800
#define CHN5_SYNTH5_LPF_EN_VCMON_GET(x)                                        (((x) & CHN5_SYNTH5_LPF_EN_VCMON_MASK) >> CHN5_SYNTH5_LPF_EN_VCMON_LSB)
#define CHN5_SYNTH5_LPF_EN_VCMON_SET(x)                                        (((0 | (x)) << CHN5_SYNTH5_LPF_EN_VCMON_LSB) & CHN5_SYNTH5_LPF_EN_VCMON_MASK)
#define CHN5_SYNTH5_LPF_EN_VCMON_RESET                                         0x1
#define CHN5_SYNTH5_LPF_CINT_LSB                                               6
#define CHN5_SYNTH5_LPF_CINT_MSB                                               10
#define CHN5_SYNTH5_LPF_CINT_MASK                                              0x7c0
#define CHN5_SYNTH5_LPF_CINT_GET(x)                                            (((x) & CHN5_SYNTH5_LPF_CINT_MASK) >> CHN5_SYNTH5_LPF_CINT_LSB)
#define CHN5_SYNTH5_LPF_CINT_SET(x)                                            (((0 | (x)) << CHN5_SYNTH5_LPF_CINT_LSB) & CHN5_SYNTH5_LPF_CINT_MASK)
#define CHN5_SYNTH5_LPF_CINT_RESET                                             0x12
#define CHN5_SYNTH5_LPF_VREFLO_LSB                                             3
#define CHN5_SYNTH5_LPF_VREFLO_MSB                                             5
#define CHN5_SYNTH5_LPF_VREFLO_MASK                                            0x38
#define CHN5_SYNTH5_LPF_VREFLO_GET(x)                                          (((x) & CHN5_SYNTH5_LPF_VREFLO_MASK) >> CHN5_SYNTH5_LPF_VREFLO_LSB)
#define CHN5_SYNTH5_LPF_VREFLO_SET(x)                                          (((0 | (x)) << CHN5_SYNTH5_LPF_VREFLO_LSB) & CHN5_SYNTH5_LPF_VREFLO_MASK)
#define CHN5_SYNTH5_LPF_VREFLO_RESET                                           0x5
#define CHN5_SYNTH5_LPF_VREFMID_LSB                                            0
#define CHN5_SYNTH5_LPF_VREFMID_MSB                                            2
#define CHN5_SYNTH5_LPF_VREFMID_MASK                                           0x7
#define CHN5_SYNTH5_LPF_VREFMID_GET(x)                                         (((x) & CHN5_SYNTH5_LPF_VREFMID_MASK) >> CHN5_SYNTH5_LPF_VREFMID_LSB)
#define CHN5_SYNTH5_LPF_VREFMID_SET(x)                                         (((0 | (x)) << CHN5_SYNTH5_LPF_VREFMID_LSB) & CHN5_SYNTH5_LPF_VREFMID_MASK)
#define CHN5_SYNTH5_LPF_VREFMID_RESET                                          0x5
#define CHN5_SYNTH5_ADDRESS                                                    (0x14 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH5_RSTMASK                                                    0xffffffff
#define CHN5_SYNTH5_RESET                                                      0x18c63cad

// 0x18 (CHN5_SYNTH6)
#define CHN5_SYNTH6_LPF_VREFHI_LSB                                             29
#define CHN5_SYNTH6_LPF_VREFHI_MSB                                             31
#define CHN5_SYNTH6_LPF_VREFHI_MASK                                            0xe0000000
#define CHN5_SYNTH6_LPF_VREFHI_GET(x)                                          (((x) & CHN5_SYNTH6_LPF_VREFHI_MASK) >> CHN5_SYNTH6_LPF_VREFHI_LSB)
#define CHN5_SYNTH6_LPF_VREFHI_SET(x)                                          (((0 | (x)) << CHN5_SYNTH6_LPF_VREFHI_LSB) & CHN5_SYNTH6_LPF_VREFHI_MASK)
#define CHN5_SYNTH6_LPF_VREFHI_RESET                                           0x5
#define CHN5_SYNTH6_VCO_ENABLE_LSB                                             28
#define CHN5_SYNTH6_VCO_ENABLE_MSB                                             28
#define CHN5_SYNTH6_VCO_ENABLE_MASK                                            0x10000000
#define CHN5_SYNTH6_VCO_ENABLE_GET(x)                                          (((x) & CHN5_SYNTH6_VCO_ENABLE_MASK) >> CHN5_SYNTH6_VCO_ENABLE_LSB)
#define CHN5_SYNTH6_VCO_ENABLE_SET(x)                                          (((0 | (x)) << CHN5_SYNTH6_VCO_ENABLE_LSB) & CHN5_SYNTH6_VCO_ENABLE_MASK)
#define CHN5_SYNTH6_VCO_ENABLE_RESET                                           0x1
#define CHN5_SYNTH6_VCO_REG_1P1_BYPASS_LSB                                     27
#define CHN5_SYNTH6_VCO_REG_1P1_BYPASS_MSB                                     27
#define CHN5_SYNTH6_VCO_REG_1P1_BYPASS_MASK                                    0x8000000
#define CHN5_SYNTH6_VCO_REG_1P1_BYPASS_GET(x)                                  (((x) & CHN5_SYNTH6_VCO_REG_1P1_BYPASS_MASK) >> CHN5_SYNTH6_VCO_REG_1P1_BYPASS_LSB)
#define CHN5_SYNTH6_VCO_REG_1P1_BYPASS_SET(x)                                  (((0 | (x)) << CHN5_SYNTH6_VCO_REG_1P1_BYPASS_LSB) & CHN5_SYNTH6_VCO_REG_1P1_BYPASS_MASK)
#define CHN5_SYNTH6_VCO_REG_1P1_BYPASS_RESET                                   0x0
#define CHN5_SYNTH6_KVCOA0_LSB                                                 24
#define CHN5_SYNTH6_KVCOA0_MSB                                                 26
#define CHN5_SYNTH6_KVCOA0_MASK                                                0x7000000
#define CHN5_SYNTH6_KVCOA0_GET(x)                                              (((x) & CHN5_SYNTH6_KVCOA0_MASK) >> CHN5_SYNTH6_KVCOA0_LSB)
#define CHN5_SYNTH6_KVCOA0_SET(x)                                              (((0 | (x)) << CHN5_SYNTH6_KVCOA0_LSB) & CHN5_SYNTH6_KVCOA0_MASK)
#define CHN5_SYNTH6_KVCOA0_RESET                                               0x5
#define CHN5_SYNTH6_KVCOA1_LSB                                                 21
#define CHN5_SYNTH6_KVCOA1_MSB                                                 23
#define CHN5_SYNTH6_KVCOA1_MASK                                                0xe00000
#define CHN5_SYNTH6_KVCOA1_GET(x)                                              (((x) & CHN5_SYNTH6_KVCOA1_MASK) >> CHN5_SYNTH6_KVCOA1_LSB)
#define CHN5_SYNTH6_KVCOA1_SET(x)                                              (((0 | (x)) << CHN5_SYNTH6_KVCOA1_LSB) & CHN5_SYNTH6_KVCOA1_MASK)
#define CHN5_SYNTH6_KVCOA1_RESET                                               0x5
#define CHN5_SYNTH6_KVCOA2_LSB                                                 18
#define CHN5_SYNTH6_KVCOA2_MSB                                                 20
#define CHN5_SYNTH6_KVCOA2_MASK                                                0x1c0000
#define CHN5_SYNTH6_KVCOA2_GET(x)                                              (((x) & CHN5_SYNTH6_KVCOA2_MASK) >> CHN5_SYNTH6_KVCOA2_LSB)
#define CHN5_SYNTH6_KVCOA2_SET(x)                                              (((0 | (x)) << CHN5_SYNTH6_KVCOA2_LSB) & CHN5_SYNTH6_KVCOA2_MASK)
#define CHN5_SYNTH6_KVCOA2_RESET                                               0x5
#define CHN5_SYNTH6_KVCOA3_LSB                                                 15
#define CHN5_SYNTH6_KVCOA3_MSB                                                 17
#define CHN5_SYNTH6_KVCOA3_MASK                                                0x38000
#define CHN5_SYNTH6_KVCOA3_GET(x)                                              (((x) & CHN5_SYNTH6_KVCOA3_MASK) >> CHN5_SYNTH6_KVCOA3_LSB)
#define CHN5_SYNTH6_KVCOA3_SET(x)                                              (((0 | (x)) << CHN5_SYNTH6_KVCOA3_LSB) & CHN5_SYNTH6_KVCOA3_MASK)
#define CHN5_SYNTH6_KVCOA3_RESET                                               0x5
#define CHN5_SYNTH6_FORCE_SHORTR_VCO_LSB                                       14
#define CHN5_SYNTH6_FORCE_SHORTR_VCO_MSB                                       14
#define CHN5_SYNTH6_FORCE_SHORTR_VCO_MASK                                      0x4000
#define CHN5_SYNTH6_FORCE_SHORTR_VCO_GET(x)                                    (((x) & CHN5_SYNTH6_FORCE_SHORTR_VCO_MASK) >> CHN5_SYNTH6_FORCE_SHORTR_VCO_LSB)
#define CHN5_SYNTH6_FORCE_SHORTR_VCO_SET(x)                                    (((0 | (x)) << CHN5_SYNTH6_FORCE_SHORTR_VCO_LSB) & CHN5_SYNTH6_FORCE_SHORTR_VCO_MASK)
#define CHN5_SYNTH6_FORCE_SHORTR_VCO_RESET                                     0x0
#define CHN5_SYNTH6_VCO_SHORTR_VCOCORE_OVR_LSB                                 13
#define CHN5_SYNTH6_VCO_SHORTR_VCOCORE_OVR_MSB                                 13
#define CHN5_SYNTH6_VCO_SHORTR_VCOCORE_OVR_MASK                                0x2000
#define CHN5_SYNTH6_VCO_SHORTR_VCOCORE_OVR_GET(x)                              (((x) & CHN5_SYNTH6_VCO_SHORTR_VCOCORE_OVR_MASK) >> CHN5_SYNTH6_VCO_SHORTR_VCOCORE_OVR_LSB)
#define CHN5_SYNTH6_VCO_SHORTR_VCOCORE_OVR_SET(x)                              (((0 | (x)) << CHN5_SYNTH6_VCO_SHORTR_VCOCORE_OVR_LSB) & CHN5_SYNTH6_VCO_SHORTR_VCOCORE_OVR_MASK)
#define CHN5_SYNTH6_VCO_SHORTR_VCOCORE_OVR_RESET                               0x0
#define CHN5_SYNTH6_VCO_EN_VMODE_LSB                                           12
#define CHN5_SYNTH6_VCO_EN_VMODE_MSB                                           12
#define CHN5_SYNTH6_VCO_EN_VMODE_MASK                                          0x1000
#define CHN5_SYNTH6_VCO_EN_VMODE_GET(x)                                        (((x) & CHN5_SYNTH6_VCO_EN_VMODE_MASK) >> CHN5_SYNTH6_VCO_EN_VMODE_LSB)
#define CHN5_SYNTH6_VCO_EN_VMODE_SET(x)                                        (((0 | (x)) << CHN5_SYNTH6_VCO_EN_VMODE_LSB) & CHN5_SYNTH6_VCO_EN_VMODE_MASK)
#define CHN5_SYNTH6_VCO_EN_VMODE_RESET                                         0x0
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA0_LSB                                     9
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA0_MSB                                     11
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA0_MASK                                    0xe00
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA0_GET(x)                                  (((x) & CHN5_SYNTH6_LOOP_3RD_ORDER_RA0_MASK) >> CHN5_SYNTH6_LOOP_3RD_ORDER_RA0_LSB)
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA0_SET(x)                                  (((0 | (x)) << CHN5_SYNTH6_LOOP_3RD_ORDER_RA0_LSB) & CHN5_SYNTH6_LOOP_3RD_ORDER_RA0_MASK)
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA0_RESET                                   0x1
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA1_LSB                                     6
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA1_MSB                                     8
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA1_MASK                                    0x1c0
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA1_GET(x)                                  (((x) & CHN5_SYNTH6_LOOP_3RD_ORDER_RA1_MASK) >> CHN5_SYNTH6_LOOP_3RD_ORDER_RA1_LSB)
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA1_SET(x)                                  (((0 | (x)) << CHN5_SYNTH6_LOOP_3RD_ORDER_RA1_LSB) & CHN5_SYNTH6_LOOP_3RD_ORDER_RA1_MASK)
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA1_RESET                                   0x1
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA2_LSB                                     3
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA2_MSB                                     5
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA2_MASK                                    0x38
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA2_GET(x)                                  (((x) & CHN5_SYNTH6_LOOP_3RD_ORDER_RA2_MASK) >> CHN5_SYNTH6_LOOP_3RD_ORDER_RA2_LSB)
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA2_SET(x)                                  (((0 | (x)) << CHN5_SYNTH6_LOOP_3RD_ORDER_RA2_LSB) & CHN5_SYNTH6_LOOP_3RD_ORDER_RA2_MASK)
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA2_RESET                                   0x1
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA3_LSB                                     0
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA3_MSB                                     2
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA3_MASK                                    0x7
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA3_GET(x)                                  (((x) & CHN5_SYNTH6_LOOP_3RD_ORDER_RA3_MASK) >> CHN5_SYNTH6_LOOP_3RD_ORDER_RA3_LSB)
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA3_SET(x)                                  (((0 | (x)) << CHN5_SYNTH6_LOOP_3RD_ORDER_RA3_LSB) & CHN5_SYNTH6_LOOP_3RD_ORDER_RA3_MASK)
#define CHN5_SYNTH6_LOOP_3RD_ORDER_RA3_RESET                                   0x1
#define CHN5_SYNTH6_ADDRESS                                                    (0x18 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH6_RSTMASK                                                    0xffffffff
#define CHN5_SYNTH6_RESET                                                      0xb5b68249

// 0x1c (CHN5_SYNTH7)
#define CHN5_SYNTH7_LO_CAPA0_LSB                                               29
#define CHN5_SYNTH7_LO_CAPA0_MSB                                               31
#define CHN5_SYNTH7_LO_CAPA0_MASK                                              0xe0000000
#define CHN5_SYNTH7_LO_CAPA0_GET(x)                                            (((x) & CHN5_SYNTH7_LO_CAPA0_MASK) >> CHN5_SYNTH7_LO_CAPA0_LSB)
#define CHN5_SYNTH7_LO_CAPA0_SET(x)                                            (((0 | (x)) << CHN5_SYNTH7_LO_CAPA0_LSB) & CHN5_SYNTH7_LO_CAPA0_MASK)
#define CHN5_SYNTH7_LO_CAPA0_RESET                                             0x0
#define CHN5_SYNTH7_LO_CAPA1_LSB                                               26
#define CHN5_SYNTH7_LO_CAPA1_MSB                                               28
#define CHN5_SYNTH7_LO_CAPA1_MASK                                              0x1c000000
#define CHN5_SYNTH7_LO_CAPA1_GET(x)                                            (((x) & CHN5_SYNTH7_LO_CAPA1_MASK) >> CHN5_SYNTH7_LO_CAPA1_LSB)
#define CHN5_SYNTH7_LO_CAPA1_SET(x)                                            (((0 | (x)) << CHN5_SYNTH7_LO_CAPA1_LSB) & CHN5_SYNTH7_LO_CAPA1_MASK)
#define CHN5_SYNTH7_LO_CAPA1_RESET                                             0x1
#define CHN5_SYNTH7_LO_CAPA2_LSB                                               23
#define CHN5_SYNTH7_LO_CAPA2_MSB                                               25
#define CHN5_SYNTH7_LO_CAPA2_MASK                                              0x3800000
#define CHN5_SYNTH7_LO_CAPA2_GET(x)                                            (((x) & CHN5_SYNTH7_LO_CAPA2_MASK) >> CHN5_SYNTH7_LO_CAPA2_LSB)
#define CHN5_SYNTH7_LO_CAPA2_SET(x)                                            (((0 | (x)) << CHN5_SYNTH7_LO_CAPA2_LSB) & CHN5_SYNTH7_LO_CAPA2_MASK)
#define CHN5_SYNTH7_LO_CAPA2_RESET                                             0x3
#define CHN5_SYNTH7_LO_CAPA3_LSB                                               20
#define CHN5_SYNTH7_LO_CAPA3_MSB                                               22
#define CHN5_SYNTH7_LO_CAPA3_MASK                                              0x700000
#define CHN5_SYNTH7_LO_CAPA3_GET(x)                                            (((x) & CHN5_SYNTH7_LO_CAPA3_MASK) >> CHN5_SYNTH7_LO_CAPA3_LSB)
#define CHN5_SYNTH7_LO_CAPA3_SET(x)                                            (((0 | (x)) << CHN5_SYNTH7_LO_CAPA3_LSB) & CHN5_SYNTH7_LO_CAPA3_MASK)
#define CHN5_SYNTH7_LO_CAPA3_RESET                                             0x7
#define CHN5_SYNTH7_LOGEN_EN_PATH_LSB                                          19
#define CHN5_SYNTH7_LOGEN_EN_PATH_MSB                                          19
#define CHN5_SYNTH7_LOGEN_EN_PATH_MASK                                         0x80000
#define CHN5_SYNTH7_LOGEN_EN_PATH_GET(x)                                       (((x) & CHN5_SYNTH7_LOGEN_EN_PATH_MASK) >> CHN5_SYNTH7_LOGEN_EN_PATH_LSB)
#define CHN5_SYNTH7_LOGEN_EN_PATH_SET(x)                                       (((0 | (x)) << CHN5_SYNTH7_LOGEN_EN_PATH_LSB) & CHN5_SYNTH7_LOGEN_EN_PATH_MASK)
#define CHN5_SYNTH7_LOGEN_EN_PATH_RESET                                        0x1
#define CHN5_SYNTH7_LOGEN_EN_DIV_LSB                                           18
#define CHN5_SYNTH7_LOGEN_EN_DIV_MSB                                           18
#define CHN5_SYNTH7_LOGEN_EN_DIV_MASK                                          0x40000
#define CHN5_SYNTH7_LOGEN_EN_DIV_GET(x)                                        (((x) & CHN5_SYNTH7_LOGEN_EN_DIV_MASK) >> CHN5_SYNTH7_LOGEN_EN_DIV_LSB)
#define CHN5_SYNTH7_LOGEN_EN_DIV_SET(x)                                        (((0 | (x)) << CHN5_SYNTH7_LOGEN_EN_DIV_LSB) & CHN5_SYNTH7_LOGEN_EN_DIV_MASK)
#define CHN5_SYNTH7_LOGEN_EN_DIV_RESET                                         0x1
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIX_LSB                                      17
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIX_MSB                                      17
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIX_MASK                                     0x20000
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIX_GET(x)                                   (((x) & CHN5_SYNTH7_LOGEN_EN_PATH_MIX_MASK) >> CHN5_SYNTH7_LOGEN_EN_PATH_MIX_LSB)
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIX_SET(x)                                   (((0 | (x)) << CHN5_SYNTH7_LOGEN_EN_PATH_MIX_LSB) & CHN5_SYNTH7_LOGEN_EN_PATH_MIX_MASK)
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIX_RESET                                    0x1
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIXBUF_LSB                                   16
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIXBUF_MSB                                   16
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIXBUF_MASK                                  0x10000
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIXBUF_GET(x)                                (((x) & CHN5_SYNTH7_LOGEN_EN_PATH_MIXBUF_MASK) >> CHN5_SYNTH7_LOGEN_EN_PATH_MIXBUF_LSB)
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIXBUF_SET(x)                                (((0 | (x)) << CHN5_SYNTH7_LOGEN_EN_PATH_MIXBUF_LSB) & CHN5_SYNTH7_LOGEN_EN_PATH_MIXBUF_MASK)
#define CHN5_SYNTH7_LOGEN_EN_PATH_MIXBUF_RESET                                 0x1
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF0_LSB                                 15
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF0_MSB                                 15
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF0_MASK                                0x8000
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF0_GET(x)                              (((x) & CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF0_MASK) >> CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF0_LSB)
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF0_SET(x)                              (((0 | (x)) << CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF0_LSB) & CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF0_MASK)
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF0_RESET                               0x1
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF1_LSB                                 14
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF1_MSB                                 14
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF1_MASK                                0x4000
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF1_GET(x)                              (((x) & CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF1_MASK) >> CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF1_LSB)
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF1_SET(x)                              (((0 | (x)) << CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF1_LSB) & CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF1_MASK)
#define CHN5_SYNTH7_LOGEN_EN_PATH_DISTBUF1_RESET                               0x1
#define CHN5_SYNTH7_LOGEN_EN_PATH_DIVNBUF_LSB                                  13
#define CHN5_SYNTH7_LOGEN_EN_PATH_DIVNBUF_MSB                                  13
#define CHN5_SYNTH7_LOGEN_EN_PATH_DIVNBUF_MASK                                 0x2000
#define CHN5_SYNTH7_LOGEN_EN_PATH_DIVNBUF_GET(x)                               (((x) & CHN5_SYNTH7_LOGEN_EN_PATH_DIVNBUF_MASK) >> CHN5_SYNTH7_LOGEN_EN_PATH_DIVNBUF_LSB)
#define CHN5_SYNTH7_LOGEN_EN_PATH_DIVNBUF_SET(x)                               (((0 | (x)) << CHN5_SYNTH7_LOGEN_EN_PATH_DIVNBUF_LSB) & CHN5_SYNTH7_LOGEN_EN_PATH_DIVNBUF_MASK)
#define CHN5_SYNTH7_LOGEN_EN_PATH_DIVNBUF_RESET                                0x1
#define CHN5_SYNTH7_LOGEN_NOTAIL_AMP_LSB                                       12
#define CHN5_SYNTH7_LOGEN_NOTAIL_AMP_MSB                                       12
#define CHN5_SYNTH7_LOGEN_NOTAIL_AMP_MASK                                      0x1000
#define CHN5_SYNTH7_LOGEN_NOTAIL_AMP_GET(x)                                    (((x) & CHN5_SYNTH7_LOGEN_NOTAIL_AMP_MASK) >> CHN5_SYNTH7_LOGEN_NOTAIL_AMP_LSB)
#define CHN5_SYNTH7_LOGEN_NOTAIL_AMP_SET(x)                                    (((0 | (x)) << CHN5_SYNTH7_LOGEN_NOTAIL_AMP_LSB) & CHN5_SYNTH7_LOGEN_NOTAIL_AMP_MASK)
#define CHN5_SYNTH7_LOGEN_NOTAIL_AMP_RESET                                     0x0
#define CHN5_SYNTH7_LOGEN_NOTAIL_V2I_LSB                                       11
#define CHN5_SYNTH7_LOGEN_NOTAIL_V2I_MSB                                       11
#define CHN5_SYNTH7_LOGEN_NOTAIL_V2I_MASK                                      0x800
#define CHN5_SYNTH7_LOGEN_NOTAIL_V2I_GET(x)                                    (((x) & CHN5_SYNTH7_LOGEN_NOTAIL_V2I_MASK) >> CHN5_SYNTH7_LOGEN_NOTAIL_V2I_LSB)
#define CHN5_SYNTH7_LOGEN_NOTAIL_V2I_SET(x)                                    (((0 | (x)) << CHN5_SYNTH7_LOGEN_NOTAIL_V2I_LSB) & CHN5_SYNTH7_LOGEN_NOTAIL_V2I_MASK)
#define CHN5_SYNTH7_LOGEN_NOTAIL_V2I_RESET                                     0x0
#define CHN5_SYNTH7_RESERVED_LSB                                               4
#define CHN5_SYNTH7_RESERVED_MSB                                               10
#define CHN5_SYNTH7_RESERVED_MASK                                              0x7f0
#define CHN5_SYNTH7_RESERVED_GET(x)                                            (((x) & CHN5_SYNTH7_RESERVED_MASK) >> CHN5_SYNTH7_RESERVED_LSB)
#define CHN5_SYNTH7_RESERVED_SET(x)                                            (((0 | (x)) << CHN5_SYNTH7_RESERVED_LSB) & CHN5_SYNTH7_RESERVED_MASK)
#define CHN5_SYNTH7_RESERVED_RESET                                             0x0
#define CHN5_SYNTH7_BIAS_ENABLE_LSB                                            3
#define CHN5_SYNTH7_BIAS_ENABLE_MSB                                            3
#define CHN5_SYNTH7_BIAS_ENABLE_MASK                                           0x8
#define CHN5_SYNTH7_BIAS_ENABLE_GET(x)                                         (((x) & CHN5_SYNTH7_BIAS_ENABLE_MASK) >> CHN5_SYNTH7_BIAS_ENABLE_LSB)
#define CHN5_SYNTH7_BIAS_ENABLE_SET(x)                                         (((0 | (x)) << CHN5_SYNTH7_BIAS_ENABLE_LSB) & CHN5_SYNTH7_BIAS_ENABLE_MASK)
#define CHN5_SYNTH7_BIAS_ENABLE_RESET                                          0x1
#define CHN5_SYNTH7_BIAS_REFMULT_DLL_LSB                                       0
#define CHN5_SYNTH7_BIAS_REFMULT_DLL_MSB                                       2
#define CHN5_SYNTH7_BIAS_REFMULT_DLL_MASK                                      0x7
#define CHN5_SYNTH7_BIAS_REFMULT_DLL_GET(x)                                    (((x) & CHN5_SYNTH7_BIAS_REFMULT_DLL_MASK) >> CHN5_SYNTH7_BIAS_REFMULT_DLL_LSB)
#define CHN5_SYNTH7_BIAS_REFMULT_DLL_SET(x)                                    (((0 | (x)) << CHN5_SYNTH7_BIAS_REFMULT_DLL_LSB) & CHN5_SYNTH7_BIAS_REFMULT_DLL_MASK)
#define CHN5_SYNTH7_BIAS_REFMULT_DLL_RESET                                     0x3
#define CHN5_SYNTH7_ADDRESS                                                    (0x1c + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH7_RSTMASK                                                    0xffffffff
#define CHN5_SYNTH7_RESET                                                      0x5ffe00b

// 0x20 (CHN5_SYNTH8)
#define CHN5_SYNTH8_BIAS_CHP_LSB                                               30
#define CHN5_SYNTH8_BIAS_CHP_MSB                                               31
#define CHN5_SYNTH8_BIAS_CHP_MASK                                              0xc0000000
#define CHN5_SYNTH8_BIAS_CHP_GET(x)                                            (((x) & CHN5_SYNTH8_BIAS_CHP_MASK) >> CHN5_SYNTH8_BIAS_CHP_LSB)
#define CHN5_SYNTH8_BIAS_CHP_SET(x)                                            (((0 | (x)) << CHN5_SYNTH8_BIAS_CHP_LSB) & CHN5_SYNTH8_BIAS_CHP_MASK)
#define CHN5_SYNTH8_BIAS_CHP_RESET                                             0x2
#define CHN5_SYNTH8_BIAS_LPF_COMP_LSB                                          27
#define CHN5_SYNTH8_BIAS_LPF_COMP_MSB                                          29
#define CHN5_SYNTH8_BIAS_LPF_COMP_MASK                                         0x38000000
#define CHN5_SYNTH8_BIAS_LPF_COMP_GET(x)                                       (((x) & CHN5_SYNTH8_BIAS_LPF_COMP_MASK) >> CHN5_SYNTH8_BIAS_LPF_COMP_LSB)
#define CHN5_SYNTH8_BIAS_LPF_COMP_SET(x)                                       (((0 | (x)) << CHN5_SYNTH8_BIAS_LPF_COMP_LSB) & CHN5_SYNTH8_BIAS_LPF_COMP_MASK)
#define CHN5_SYNTH8_BIAS_LPF_COMP_RESET                                        0x3
#define CHN5_SYNTH8_BIAS_LPF_BUF_LSB                                           24
#define CHN5_SYNTH8_BIAS_LPF_BUF_MSB                                           26
#define CHN5_SYNTH8_BIAS_LPF_BUF_MASK                                          0x7000000
#define CHN5_SYNTH8_BIAS_LPF_BUF_GET(x)                                        (((x) & CHN5_SYNTH8_BIAS_LPF_BUF_MASK) >> CHN5_SYNTH8_BIAS_LPF_BUF_LSB)
#define CHN5_SYNTH8_BIAS_LPF_BUF_SET(x)                                        (((0 | (x)) << CHN5_SYNTH8_BIAS_LPF_BUF_LSB) & CHN5_SYNTH8_BIAS_LPF_BUF_MASK)
#define CHN5_SYNTH8_BIAS_LPF_BUF_RESET                                         0x3
#define CHN5_SYNTH8_BIAS_VCO_LSB                                               21
#define CHN5_SYNTH8_BIAS_VCO_MSB                                               23
#define CHN5_SYNTH8_BIAS_VCO_MASK                                              0xe00000
#define CHN5_SYNTH8_BIAS_VCO_GET(x)                                            (((x) & CHN5_SYNTH8_BIAS_VCO_MASK) >> CHN5_SYNTH8_BIAS_VCO_LSB)
#define CHN5_SYNTH8_BIAS_VCO_SET(x)                                            (((0 | (x)) << CHN5_SYNTH8_BIAS_VCO_LSB) & CHN5_SYNTH8_BIAS_VCO_MASK)
#define CHN5_SYNTH8_BIAS_VCO_RESET                                             0x2
#define CHN5_SYNTH8_BIAS_LOGEN_DIV_LSB                                         18
#define CHN5_SYNTH8_BIAS_LOGEN_DIV_MSB                                         20
#define CHN5_SYNTH8_BIAS_LOGEN_DIV_MASK                                        0x1c0000
#define CHN5_SYNTH8_BIAS_LOGEN_DIV_GET(x)                                      (((x) & CHN5_SYNTH8_BIAS_LOGEN_DIV_MASK) >> CHN5_SYNTH8_BIAS_LOGEN_DIV_LSB)
#define CHN5_SYNTH8_BIAS_LOGEN_DIV_SET(x)                                      (((0 | (x)) << CHN5_SYNTH8_BIAS_LOGEN_DIV_LSB) & CHN5_SYNTH8_BIAS_LOGEN_DIV_MASK)
#define CHN5_SYNTH8_BIAS_LOGEN_DIV_RESET                                       0x3
#define CHN5_SYNTH8_BIAS_LOGEN_MIX_LSB                                         15
#define CHN5_SYNTH8_BIAS_LOGEN_MIX_MSB                                         17
#define CHN5_SYNTH8_BIAS_LOGEN_MIX_MASK                                        0x38000
#define CHN5_SYNTH8_BIAS_LOGEN_MIX_GET(x)                                      (((x) & CHN5_SYNTH8_BIAS_LOGEN_MIX_MASK) >> CHN5_SYNTH8_BIAS_LOGEN_MIX_LSB)
#define CHN5_SYNTH8_BIAS_LOGEN_MIX_SET(x)                                      (((0 | (x)) << CHN5_SYNTH8_BIAS_LOGEN_MIX_LSB) & CHN5_SYNTH8_BIAS_LOGEN_MIX_MASK)
#define CHN5_SYNTH8_BIAS_LOGEN_MIX_RESET                                       0x3
#define CHN5_SYNTH8_BIAS_LOGEN_AMP_LSB                                         12
#define CHN5_SYNTH8_BIAS_LOGEN_AMP_MSB                                         14
#define CHN5_SYNTH8_BIAS_LOGEN_AMP_MASK                                        0x7000
#define CHN5_SYNTH8_BIAS_LOGEN_AMP_GET(x)                                      (((x) & CHN5_SYNTH8_BIAS_LOGEN_AMP_MASK) >> CHN5_SYNTH8_BIAS_LOGEN_AMP_LSB)
#define CHN5_SYNTH8_BIAS_LOGEN_AMP_SET(x)                                      (((0 | (x)) << CHN5_SYNTH8_BIAS_LOGEN_AMP_LSB) & CHN5_SYNTH8_BIAS_LOGEN_AMP_MASK)
#define CHN5_SYNTH8_BIAS_LOGEN_AMP_RESET                                       0x3
#define CHN5_SYNTH8_BIAS_LOGEN_V2I0_LSB                                        9
#define CHN5_SYNTH8_BIAS_LOGEN_V2I0_MSB                                        11
#define CHN5_SYNTH8_BIAS_LOGEN_V2I0_MASK                                       0xe00
#define CHN5_SYNTH8_BIAS_LOGEN_V2I0_GET(x)                                     (((x) & CHN5_SYNTH8_BIAS_LOGEN_V2I0_MASK) >> CHN5_SYNTH8_BIAS_LOGEN_V2I0_LSB)
#define CHN5_SYNTH8_BIAS_LOGEN_V2I0_SET(x)                                     (((0 | (x)) << CHN5_SYNTH8_BIAS_LOGEN_V2I0_LSB) & CHN5_SYNTH8_BIAS_LOGEN_V2I0_MASK)
#define CHN5_SYNTH8_BIAS_LOGEN_V2I0_RESET                                      0x3
#define CHN5_SYNTH8_BIAS_LOGEN_V2I1_LSB                                        6
#define CHN5_SYNTH8_BIAS_LOGEN_V2I1_MSB                                        8
#define CHN5_SYNTH8_BIAS_LOGEN_V2I1_MASK                                       0x1c0
#define CHN5_SYNTH8_BIAS_LOGEN_V2I1_GET(x)                                     (((x) & CHN5_SYNTH8_BIAS_LOGEN_V2I1_MASK) >> CHN5_SYNTH8_BIAS_LOGEN_V2I1_LSB)
#define CHN5_SYNTH8_BIAS_LOGEN_V2I1_SET(x)                                     (((0 | (x)) << CHN5_SYNTH8_BIAS_LOGEN_V2I1_LSB) & CHN5_SYNTH8_BIAS_LOGEN_V2I1_MASK)
#define CHN5_SYNTH8_BIAS_LOGEN_V2I1_RESET                                      0x3
#define CHN5_SYNTH8_BIAS_LOGEN_CML2CMOS_LSB                                    3
#define CHN5_SYNTH8_BIAS_LOGEN_CML2CMOS_MSB                                    5
#define CHN5_SYNTH8_BIAS_LOGEN_CML2CMOS_MASK                                   0x38
#define CHN5_SYNTH8_BIAS_LOGEN_CML2CMOS_GET(x)                                 (((x) & CHN5_SYNTH8_BIAS_LOGEN_CML2CMOS_MASK) >> CHN5_SYNTH8_BIAS_LOGEN_CML2CMOS_LSB)
#define CHN5_SYNTH8_BIAS_LOGEN_CML2CMOS_SET(x)                                 (((0 | (x)) << CHN5_SYNTH8_BIAS_LOGEN_CML2CMOS_LSB) & CHN5_SYNTH8_BIAS_LOGEN_CML2CMOS_MASK)
#define CHN5_SYNTH8_BIAS_LOGEN_CML2CMOS_RESET                                  0x3
#define CHN5_SYNTH8_BIAS_IC25_SPARE_LSB                                        0
#define CHN5_SYNTH8_BIAS_IC25_SPARE_MSB                                        2
#define CHN5_SYNTH8_BIAS_IC25_SPARE_MASK                                       0x7
#define CHN5_SYNTH8_BIAS_IC25_SPARE_GET(x)                                     (((x) & CHN5_SYNTH8_BIAS_IC25_SPARE_MASK) >> CHN5_SYNTH8_BIAS_IC25_SPARE_LSB)
#define CHN5_SYNTH8_BIAS_IC25_SPARE_SET(x)                                     (((0 | (x)) << CHN5_SYNTH8_BIAS_IC25_SPARE_LSB) & CHN5_SYNTH8_BIAS_IC25_SPARE_MASK)
#define CHN5_SYNTH8_BIAS_IC25_SPARE_RESET                                      0x3
#define CHN5_SYNTH8_ADDRESS                                                    (0x20 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH8_RSTMASK                                                    0xffffffff
#define CHN5_SYNTH8_RESET                                                      0x9b4db6db

// 0x24 (CHN5_SYNTH9)
#define CHN5_SYNTH9_LOADSYNTHCHANNEL_LSB                                       31
#define CHN5_SYNTH9_LOADSYNTHCHANNEL_MSB                                       31
#define CHN5_SYNTH9_LOADSYNTHCHANNEL_MASK                                      0x80000000
#define CHN5_SYNTH9_LOADSYNTHCHANNEL_GET(x)                                    (((x) & CHN5_SYNTH9_LOADSYNTHCHANNEL_MASK) >> CHN5_SYNTH9_LOADSYNTHCHANNEL_LSB)
#define CHN5_SYNTH9_LOADSYNTHCHANNEL_SET(x)                                    (((0 | (x)) << CHN5_SYNTH9_LOADSYNTHCHANNEL_LSB) & CHN5_SYNTH9_LOADSYNTHCHANNEL_MASK)
#define CHN5_SYNTH9_LOADSYNTHCHANNEL_RESET                                     0x1
#define CHN5_SYNTH9_FRACMODE_LSB                                               30
#define CHN5_SYNTH9_FRACMODE_MSB                                               30
#define CHN5_SYNTH9_FRACMODE_MASK                                              0x40000000
#define CHN5_SYNTH9_FRACMODE_GET(x)                                            (((x) & CHN5_SYNTH9_FRACMODE_MASK) >> CHN5_SYNTH9_FRACMODE_LSB)
#define CHN5_SYNTH9_FRACMODE_SET(x)                                            (((0 | (x)) << CHN5_SYNTH9_FRACMODE_LSB) & CHN5_SYNTH9_FRACMODE_MASK)
#define CHN5_SYNTH9_FRACMODE_RESET                                             0x1
#define CHN5_SYNTH9_CHANSEL_LSB                                                22
#define CHN5_SYNTH9_CHANSEL_MSB                                                29
#define CHN5_SYNTH9_CHANSEL_MASK                                               0x3fc00000
#define CHN5_SYNTH9_CHANSEL_GET(x)                                             (((x) & CHN5_SYNTH9_CHANSEL_MASK) >> CHN5_SYNTH9_CHANSEL_LSB)
#define CHN5_SYNTH9_CHANSEL_SET(x)                                             (((0 | (x)) << CHN5_SYNTH9_CHANSEL_LSB) & CHN5_SYNTH9_CHANSEL_MASK)
#define CHN5_SYNTH9_CHANSEL_RESET                                              0x51
#define CHN5_SYNTH9_CHANFRAC_LSB                                               0
#define CHN5_SYNTH9_CHANFRAC_MSB                                               21
#define CHN5_SYNTH9_CHANFRAC_MASK                                              0x3fffff
#define CHN5_SYNTH9_CHANFRAC_GET(x)                                            (((x) & CHN5_SYNTH9_CHANFRAC_MASK) >> CHN5_SYNTH9_CHANFRAC_LSB)
#define CHN5_SYNTH9_CHANFRAC_SET(x)                                            (((0 | (x)) << CHN5_SYNTH9_CHANFRAC_LSB) & CHN5_SYNTH9_CHANFRAC_MASK)
#define CHN5_SYNTH9_CHANFRAC_RESET                                             0x4
#define CHN5_SYNTH9_ADDRESS                                                    (0x24 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH9_RSTMASK                                                    0xffffffff
#define CHN5_SYNTH9_RESET                                                      0xd4400004

// 0x28 (CHN5_SYNTH10)
#define CHN5_SYNTH10_FORCE_FRACLSB_LSB                                         31
#define CHN5_SYNTH10_FORCE_FRACLSB_MSB                                         31
#define CHN5_SYNTH10_FORCE_FRACLSB_MASK                                        0x80000000
#define CHN5_SYNTH10_FORCE_FRACLSB_GET(x)                                      (((x) & CHN5_SYNTH10_FORCE_FRACLSB_MASK) >> CHN5_SYNTH10_FORCE_FRACLSB_LSB)
#define CHN5_SYNTH10_FORCE_FRACLSB_SET(x)                                      (((0 | (x)) << CHN5_SYNTH10_FORCE_FRACLSB_LSB) & CHN5_SYNTH10_FORCE_FRACLSB_MASK)
#define CHN5_SYNTH10_FORCE_FRACLSB_RESET                                       0x1
#define CHN5_SYNTH10_USEVCOCAPIN_LSB                                           30
#define CHN5_SYNTH10_USEVCOCAPIN_MSB                                           30
#define CHN5_SYNTH10_USEVCOCAPIN_MASK                                          0x40000000
#define CHN5_SYNTH10_USEVCOCAPIN_GET(x)                                        (((x) & CHN5_SYNTH10_USEVCOCAPIN_MASK) >> CHN5_SYNTH10_USEVCOCAPIN_LSB)
#define CHN5_SYNTH10_USEVCOCAPIN_SET(x)                                        (((0 | (x)) << CHN5_SYNTH10_USEVCOCAPIN_LSB) & CHN5_SYNTH10_USEVCOCAPIN_MASK)
#define CHN5_SYNTH10_USEVCOCAPIN_RESET                                         0x0
#define CHN5_SYNTH10_VCO_CAPIN_LSB                                             20
#define CHN5_SYNTH10_VCO_CAPIN_MSB                                             29
#define CHN5_SYNTH10_VCO_CAPIN_MASK                                            0x3ff00000
#define CHN5_SYNTH10_VCO_CAPIN_GET(x)                                          (((x) & CHN5_SYNTH10_VCO_CAPIN_MASK) >> CHN5_SYNTH10_VCO_CAPIN_LSB)
#define CHN5_SYNTH10_VCO_CAPIN_SET(x)                                          (((0 | (x)) << CHN5_SYNTH10_VCO_CAPIN_LSB) & CHN5_SYNTH10_VCO_CAPIN_MASK)
#define CHN5_SYNTH10_VCO_CAPIN_RESET                                           0x15e
#define CHN5_SYNTH10_CNT_WITH_FORCE_CAP_LSB                                    19
#define CHN5_SYNTH10_CNT_WITH_FORCE_CAP_MSB                                    19
#define CHN5_SYNTH10_CNT_WITH_FORCE_CAP_MASK                                   0x80000
#define CHN5_SYNTH10_CNT_WITH_FORCE_CAP_GET(x)                                 (((x) & CHN5_SYNTH10_CNT_WITH_FORCE_CAP_MASK) >> CHN5_SYNTH10_CNT_WITH_FORCE_CAP_LSB)
#define CHN5_SYNTH10_CNT_WITH_FORCE_CAP_SET(x)                                 (((0 | (x)) << CHN5_SYNTH10_CNT_WITH_FORCE_CAP_LSB) & CHN5_SYNTH10_CNT_WITH_FORCE_CAP_MASK)
#define CHN5_SYNTH10_CNT_WITH_FORCE_CAP_RESET                                  0x0
#define CHN5_SYNTH10_FORCE_VCOCAP_LSB                                          18
#define CHN5_SYNTH10_FORCE_VCOCAP_MSB                                          18
#define CHN5_SYNTH10_FORCE_VCOCAP_MASK                                         0x40000
#define CHN5_SYNTH10_FORCE_VCOCAP_GET(x)                                       (((x) & CHN5_SYNTH10_FORCE_VCOCAP_MASK) >> CHN5_SYNTH10_FORCE_VCOCAP_LSB)
#define CHN5_SYNTH10_FORCE_VCOCAP_SET(x)                                       (((0 | (x)) << CHN5_SYNTH10_FORCE_VCOCAP_LSB) & CHN5_SYNTH10_FORCE_VCOCAP_MASK)
#define CHN5_SYNTH10_FORCE_VCOCAP_RESET                                        0x0
#define CHN5_SYNTH10_VCOCAP_OVR_LSB                                            8
#define CHN5_SYNTH10_VCOCAP_OVR_MSB                                            17
#define CHN5_SYNTH10_VCOCAP_OVR_MASK                                           0x3ff00
#define CHN5_SYNTH10_VCOCAP_OVR_GET(x)                                         (((x) & CHN5_SYNTH10_VCOCAP_OVR_MASK) >> CHN5_SYNTH10_VCOCAP_OVR_LSB)
#define CHN5_SYNTH10_VCOCAP_OVR_SET(x)                                         (((0 | (x)) << CHN5_SYNTH10_VCOCAP_OVR_LSB) & CHN5_SYNTH10_VCOCAP_OVR_MASK)
#define CHN5_SYNTH10_VCOCAP_OVR_RESET                                          0x200
#define CHN5_SYNTH10_BANDSEL5G_LSB                                             6
#define CHN5_SYNTH10_BANDSEL5G_MSB                                             7
#define CHN5_SYNTH10_BANDSEL5G_MASK                                            0xc0
#define CHN5_SYNTH10_BANDSEL5G_GET(x)                                          (((x) & CHN5_SYNTH10_BANDSEL5G_MASK) >> CHN5_SYNTH10_BANDSEL5G_LSB)
#define CHN5_SYNTH10_BANDSEL5G_SET(x)                                          (((0 | (x)) << CHN5_SYNTH10_BANDSEL5G_LSB) & CHN5_SYNTH10_BANDSEL5G_MASK)
#define CHN5_SYNTH10_BANDSEL5G_RESET                                           0x0
#define CHN5_SYNTH10_MODULATELSB_LSB                                           5
#define CHN5_SYNTH10_MODULATELSB_MSB                                           5
#define CHN5_SYNTH10_MODULATELSB_MASK                                          0x20
#define CHN5_SYNTH10_MODULATELSB_GET(x)                                        (((x) & CHN5_SYNTH10_MODULATELSB_MASK) >> CHN5_SYNTH10_MODULATELSB_LSB)
#define CHN5_SYNTH10_MODULATELSB_SET(x)                                        (((0 | (x)) << CHN5_SYNTH10_MODULATELSB_LSB) & CHN5_SYNTH10_MODULATELSB_MASK)
#define CHN5_SYNTH10_MODULATELSB_RESET                                         0x0
#define CHN5_SYNTH10_MANLSBOVERLAPVALUE_LSB                                    0
#define CHN5_SYNTH10_MANLSBOVERLAPVALUE_MSB                                    4
#define CHN5_SYNTH10_MANLSBOVERLAPVALUE_MASK                                   0x1f
#define CHN5_SYNTH10_MANLSBOVERLAPVALUE_GET(x)                                 (((x) & CHN5_SYNTH10_MANLSBOVERLAPVALUE_MASK) >> CHN5_SYNTH10_MANLSBOVERLAPVALUE_LSB)
#define CHN5_SYNTH10_MANLSBOVERLAPVALUE_SET(x)                                 (((0 | (x)) << CHN5_SYNTH10_MANLSBOVERLAPVALUE_LSB) & CHN5_SYNTH10_MANLSBOVERLAPVALUE_MASK)
#define CHN5_SYNTH10_MANLSBOVERLAPVALUE_RESET                                  0x1a
#define CHN5_SYNTH10_ADDRESS                                                   (0x28 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH10_RSTMASK                                                   0xffffffff
#define CHN5_SYNTH10_RESET                                                     0x95e2001a

// 0x2c (CHN5_SYNTH11)
#define CHN5_SYNTH11_VCOCAPCNT_COARSE_OFFSET_LSB                               26
#define CHN5_SYNTH11_VCOCAPCNT_COARSE_OFFSET_MSB                               31
#define CHN5_SYNTH11_VCOCAPCNT_COARSE_OFFSET_MASK                              0xfc000000
#define CHN5_SYNTH11_VCOCAPCNT_COARSE_OFFSET_GET(x)                            (((x) & CHN5_SYNTH11_VCOCAPCNT_COARSE_OFFSET_MASK) >> CHN5_SYNTH11_VCOCAPCNT_COARSE_OFFSET_LSB)
#define CHN5_SYNTH11_VCOCAPCNT_COARSE_OFFSET_SET(x)                            (((0 | (x)) << CHN5_SYNTH11_VCOCAPCNT_COARSE_OFFSET_LSB) & CHN5_SYNTH11_VCOCAPCNT_COARSE_OFFSET_MASK)
#define CHN5_SYNTH11_VCOCAPCNT_COARSE_OFFSET_RESET                             0x28
#define CHN5_SYNTH11_VCOCAPCNT_FINE_OFFSET_LSB                                 20
#define CHN5_SYNTH11_VCOCAPCNT_FINE_OFFSET_MSB                                 25
#define CHN5_SYNTH11_VCOCAPCNT_FINE_OFFSET_MASK                                0x3f00000
#define CHN5_SYNTH11_VCOCAPCNT_FINE_OFFSET_GET(x)                              (((x) & CHN5_SYNTH11_VCOCAPCNT_FINE_OFFSET_MASK) >> CHN5_SYNTH11_VCOCAPCNT_FINE_OFFSET_LSB)
#define CHN5_SYNTH11_VCOCAPCNT_FINE_OFFSET_SET(x)                              (((0 | (x)) << CHN5_SYNTH11_VCOCAPCNT_FINE_OFFSET_LSB) & CHN5_SYNTH11_VCOCAPCNT_FINE_OFFSET_MASK)
#define CHN5_SYNTH11_VCOCAPCNT_FINE_OFFSET_RESET                               0x0
#define CHN5_SYNTH11_BIT_INDEX_SAVE_VCO_CAP_LSB                                16
#define CHN5_SYNTH11_BIT_INDEX_SAVE_VCO_CAP_MSB                                19
#define CHN5_SYNTH11_BIT_INDEX_SAVE_VCO_CAP_MASK                               0xf0000
#define CHN5_SYNTH11_BIT_INDEX_SAVE_VCO_CAP_GET(x)                             (((x) & CHN5_SYNTH11_BIT_INDEX_SAVE_VCO_CAP_MASK) >> CHN5_SYNTH11_BIT_INDEX_SAVE_VCO_CAP_LSB)
#define CHN5_SYNTH11_BIT_INDEX_SAVE_VCO_CAP_SET(x)                             (((0 | (x)) << CHN5_SYNTH11_BIT_INDEX_SAVE_VCO_CAP_LSB) & CHN5_SYNTH11_BIT_INDEX_SAVE_VCO_CAP_MASK)
#define CHN5_SYNTH11_BIT_INDEX_SAVE_VCO_CAP_RESET                              0x0
#define CHN5_SYNTH11_MAXLINSTEPS_LSB                                           12
#define CHN5_SYNTH11_MAXLINSTEPS_MSB                                           15
#define CHN5_SYNTH11_MAXLINSTEPS_MASK                                          0xf000
#define CHN5_SYNTH11_MAXLINSTEPS_GET(x)                                        (((x) & CHN5_SYNTH11_MAXLINSTEPS_MASK) >> CHN5_SYNTH11_MAXLINSTEPS_LSB)
#define CHN5_SYNTH11_MAXLINSTEPS_SET(x)                                        (((0 | (x)) << CHN5_SYNTH11_MAXLINSTEPS_LSB) & CHN5_SYNTH11_MAXLINSTEPS_MASK)
#define CHN5_SYNTH11_MAXLINSTEPS_RESET                                         0x0
#define CHN5_SYNTH11_LIN_SEARCH_STEP_SIZE_LSB                                  9
#define CHN5_SYNTH11_LIN_SEARCH_STEP_SIZE_MSB                                  11
#define CHN5_SYNTH11_LIN_SEARCH_STEP_SIZE_MASK                                 0xe00
#define CHN5_SYNTH11_LIN_SEARCH_STEP_SIZE_GET(x)                               (((x) & CHN5_SYNTH11_LIN_SEARCH_STEP_SIZE_MASK) >> CHN5_SYNTH11_LIN_SEARCH_STEP_SIZE_LSB)
#define CHN5_SYNTH11_LIN_SEARCH_STEP_SIZE_SET(x)                               (((0 | (x)) << CHN5_SYNTH11_LIN_SEARCH_STEP_SIZE_LSB) & CHN5_SYNTH11_LIN_SEARCH_STEP_SIZE_MASK)
#define CHN5_SYNTH11_LIN_SEARCH_STEP_SIZE_RESET                                0x0
#define CHN5_SYNTH11_DIS_LIN_CAPSEARCH_LSB                                     8
#define CHN5_SYNTH11_DIS_LIN_CAPSEARCH_MSB                                     8
#define CHN5_SYNTH11_DIS_LIN_CAPSEARCH_MASK                                    0x100
#define CHN5_SYNTH11_DIS_LIN_CAPSEARCH_GET(x)                                  (((x) & CHN5_SYNTH11_DIS_LIN_CAPSEARCH_MASK) >> CHN5_SYNTH11_DIS_LIN_CAPSEARCH_LSB)
#define CHN5_SYNTH11_DIS_LIN_CAPSEARCH_SET(x)                                  (((0 | (x)) << CHN5_SYNTH11_DIS_LIN_CAPSEARCH_LSB) & CHN5_SYNTH11_DIS_LIN_CAPSEARCH_MASK)
#define CHN5_SYNTH11_DIS_LIN_CAPSEARCH_RESET                                   0x0
#define CHN5_SYNTH11_SKIPLINCAPSEARCH_LSB                                      7
#define CHN5_SYNTH11_SKIPLINCAPSEARCH_MSB                                      7
#define CHN5_SYNTH11_SKIPLINCAPSEARCH_MASK                                     0x80
#define CHN5_SYNTH11_SKIPLINCAPSEARCH_GET(x)                                   (((x) & CHN5_SYNTH11_SKIPLINCAPSEARCH_MASK) >> CHN5_SYNTH11_SKIPLINCAPSEARCH_LSB)
#define CHN5_SYNTH11_SKIPLINCAPSEARCH_SET(x)                                   (((0 | (x)) << CHN5_SYNTH11_SKIPLINCAPSEARCH_LSB) & CHN5_SYNTH11_SKIPLINCAPSEARCH_MASK)
#define CHN5_SYNTH11_SKIPLINCAPSEARCH_RESET                                    0x0
#define CHN5_SYNTH11_SKIP_MON_ALIGN_LSB                                        6
#define CHN5_SYNTH11_SKIP_MON_ALIGN_MSB                                        6
#define CHN5_SYNTH11_SKIP_MON_ALIGN_MASK                                       0x40
#define CHN5_SYNTH11_SKIP_MON_ALIGN_GET(x)                                     (((x) & CHN5_SYNTH11_SKIP_MON_ALIGN_MASK) >> CHN5_SYNTH11_SKIP_MON_ALIGN_LSB)
#define CHN5_SYNTH11_SKIP_MON_ALIGN_SET(x)                                     (((0 | (x)) << CHN5_SYNTH11_SKIP_MON_ALIGN_LSB) & CHN5_SYNTH11_SKIP_MON_ALIGN_MASK)
#define CHN5_SYNTH11_SKIP_MON_ALIGN_RESET                                      0x1
#define CHN5_SYNTH11_CENTER_VC_BIN_LSB                                         5
#define CHN5_SYNTH11_CENTER_VC_BIN_MSB                                         5
#define CHN5_SYNTH11_CENTER_VC_BIN_MASK                                        0x20
#define CHN5_SYNTH11_CENTER_VC_BIN_GET(x)                                      (((x) & CHN5_SYNTH11_CENTER_VC_BIN_MASK) >> CHN5_SYNTH11_CENTER_VC_BIN_LSB)
#define CHN5_SYNTH11_CENTER_VC_BIN_SET(x)                                      (((0 | (x)) << CHN5_SYNTH11_CENTER_VC_BIN_LSB) & CHN5_SYNTH11_CENTER_VC_BIN_MASK)
#define CHN5_SYNTH11_CENTER_VC_BIN_RESET                                       0x0
#define CHN5_SYNTH11_CENTER_VC_MON_LSB                                         4
#define CHN5_SYNTH11_CENTER_VC_MON_MSB                                         4
#define CHN5_SYNTH11_CENTER_VC_MON_MASK                                        0x10
#define CHN5_SYNTH11_CENTER_VC_MON_GET(x)                                      (((x) & CHN5_SYNTH11_CENTER_VC_MON_MASK) >> CHN5_SYNTH11_CENTER_VC_MON_LSB)
#define CHN5_SYNTH11_CENTER_VC_MON_SET(x)                                      (((0 | (x)) << CHN5_SYNTH11_CENTER_VC_MON_LSB) & CHN5_SYNTH11_CENTER_VC_MON_MASK)
#define CHN5_SYNTH11_CENTER_VC_MON_RESET                                       0x1
#define CHN5_SYNTH11_DIS_LOSTVC_LSB                                            3
#define CHN5_SYNTH11_DIS_LOSTVC_MSB                                            3
#define CHN5_SYNTH11_DIS_LOSTVC_MASK                                           0x8
#define CHN5_SYNTH11_DIS_LOSTVC_GET(x)                                         (((x) & CHN5_SYNTH11_DIS_LOSTVC_MASK) >> CHN5_SYNTH11_DIS_LOSTVC_LSB)
#define CHN5_SYNTH11_DIS_LOSTVC_SET(x)                                         (((0 | (x)) << CHN5_SYNTH11_DIS_LOSTVC_LSB) & CHN5_SYNTH11_DIS_LOSTVC_MASK)
#define CHN5_SYNTH11_DIS_LOSTVC_RESET                                          0x0
#define CHN5_SYNTH11_VC_CAL_REF_LSB                                            0
#define CHN5_SYNTH11_VC_CAL_REF_MSB                                            2
#define CHN5_SYNTH11_VC_CAL_REF_MASK                                           0x7
#define CHN5_SYNTH11_VC_CAL_REF_GET(x)                                         (((x) & CHN5_SYNTH11_VC_CAL_REF_MASK) >> CHN5_SYNTH11_VC_CAL_REF_LSB)
#define CHN5_SYNTH11_VC_CAL_REF_SET(x)                                         (((0 | (x)) << CHN5_SYNTH11_VC_CAL_REF_LSB) & CHN5_SYNTH11_VC_CAL_REF_MASK)
#define CHN5_SYNTH11_VC_CAL_REF_RESET                                          0x4
#define CHN5_SYNTH11_ADDRESS                                                   (0x2c + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH11_RSTMASK                                                   0xffffffff
#define CHN5_SYNTH11_RESET                                                     0xa0000054

// 0x30 (CHN5_SYNTH12)
#define CHN5_SYNTH12_ENVCOCAPCHECK_LSB                                         31
#define CHN5_SYNTH12_ENVCOCAPCHECK_MSB                                         31
#define CHN5_SYNTH12_ENVCOCAPCHECK_MASK                                        0x80000000
#define CHN5_SYNTH12_ENVCOCAPCHECK_GET(x)                                      (((x) & CHN5_SYNTH12_ENVCOCAPCHECK_MASK) >> CHN5_SYNTH12_ENVCOCAPCHECK_LSB)
#define CHN5_SYNTH12_ENVCOCAPCHECK_SET(x)                                      (((0 | (x)) << CHN5_SYNTH12_ENVCOCAPCHECK_LSB) & CHN5_SYNTH12_ENVCOCAPCHECK_MASK)
#define CHN5_SYNTH12_ENVCOCAPCHECK_RESET                                       0x0
#define CHN5_SYNTH12_ENINTERPOLATION_LSB                                       30
#define CHN5_SYNTH12_ENINTERPOLATION_MSB                                       30
#define CHN5_SYNTH12_ENINTERPOLATION_MASK                                      0x40000000
#define CHN5_SYNTH12_ENINTERPOLATION_GET(x)                                    (((x) & CHN5_SYNTH12_ENINTERPOLATION_MASK) >> CHN5_SYNTH12_ENINTERPOLATION_LSB)
#define CHN5_SYNTH12_ENINTERPOLATION_SET(x)                                    (((0 | (x)) << CHN5_SYNTH12_ENINTERPOLATION_LSB) & CHN5_SYNTH12_ENINTERPOLATION_MASK)
#define CHN5_SYNTH12_ENINTERPOLATION_RESET                                     0x0
#define CHN5_SYNTH12_WAIT_PWRUP_LSB                                            24
#define CHN5_SYNTH12_WAIT_PWRUP_MSB                                            29
#define CHN5_SYNTH12_WAIT_PWRUP_MASK                                           0x3f000000
#define CHN5_SYNTH12_WAIT_PWRUP_GET(x)                                         (((x) & CHN5_SYNTH12_WAIT_PWRUP_MASK) >> CHN5_SYNTH12_WAIT_PWRUP_LSB)
#define CHN5_SYNTH12_WAIT_PWRUP_SET(x)                                         (((0 | (x)) << CHN5_SYNTH12_WAIT_PWRUP_LSB) & CHN5_SYNTH12_WAIT_PWRUP_MASK)
#define CHN5_SYNTH12_WAIT_PWRUP_RESET                                          0xa
#define CHN5_SYNTH12_WAIT_SHORTR_PWRUP_LSB                                     18
#define CHN5_SYNTH12_WAIT_SHORTR_PWRUP_MSB                                     23
#define CHN5_SYNTH12_WAIT_SHORTR_PWRUP_MASK                                    0xfc0000
#define CHN5_SYNTH12_WAIT_SHORTR_PWRUP_GET(x)                                  (((x) & CHN5_SYNTH12_WAIT_SHORTR_PWRUP_MASK) >> CHN5_SYNTH12_WAIT_SHORTR_PWRUP_LSB)
#define CHN5_SYNTH12_WAIT_SHORTR_PWRUP_SET(x)                                  (((0 | (x)) << CHN5_SYNTH12_WAIT_SHORTR_PWRUP_LSB) & CHN5_SYNTH12_WAIT_SHORTR_PWRUP_MASK)
#define CHN5_SYNTH12_WAIT_SHORTR_PWRUP_RESET                                   0x5
#define CHN5_SYNTH12_WAIT_CAL_LIN_LSB                                          12
#define CHN5_SYNTH12_WAIT_CAL_LIN_MSB                                          17
#define CHN5_SYNTH12_WAIT_CAL_LIN_MASK                                         0x3f000
#define CHN5_SYNTH12_WAIT_CAL_LIN_GET(x)                                       (((x) & CHN5_SYNTH12_WAIT_CAL_LIN_MASK) >> CHN5_SYNTH12_WAIT_CAL_LIN_LSB)
#define CHN5_SYNTH12_WAIT_CAL_LIN_SET(x)                                       (((0 | (x)) << CHN5_SYNTH12_WAIT_CAL_LIN_LSB) & CHN5_SYNTH12_WAIT_CAL_LIN_MASK)
#define CHN5_SYNTH12_WAIT_CAL_LIN_RESET                                        0xf
#define CHN5_SYNTH12_WAIT_CAL_BIN_COARSE_LSB                                   6
#define CHN5_SYNTH12_WAIT_CAL_BIN_COARSE_MSB                                   11
#define CHN5_SYNTH12_WAIT_CAL_BIN_COARSE_MASK                                  0xfc0
#define CHN5_SYNTH12_WAIT_CAL_BIN_COARSE_GET(x)                                (((x) & CHN5_SYNTH12_WAIT_CAL_BIN_COARSE_MASK) >> CHN5_SYNTH12_WAIT_CAL_BIN_COARSE_LSB)
#define CHN5_SYNTH12_WAIT_CAL_BIN_COARSE_SET(x)                                (((0 | (x)) << CHN5_SYNTH12_WAIT_CAL_BIN_COARSE_LSB) & CHN5_SYNTH12_WAIT_CAL_BIN_COARSE_MASK)
#define CHN5_SYNTH12_WAIT_CAL_BIN_COARSE_RESET                                 0x6
#define CHN5_SYNTH12_WAIT_CAL_BIN_FINE_LSB                                     0
#define CHN5_SYNTH12_WAIT_CAL_BIN_FINE_MSB                                     5
#define CHN5_SYNTH12_WAIT_CAL_BIN_FINE_MASK                                    0x3f
#define CHN5_SYNTH12_WAIT_CAL_BIN_FINE_GET(x)                                  (((x) & CHN5_SYNTH12_WAIT_CAL_BIN_FINE_MASK) >> CHN5_SYNTH12_WAIT_CAL_BIN_FINE_LSB)
#define CHN5_SYNTH12_WAIT_CAL_BIN_FINE_SET(x)                                  (((0 | (x)) << CHN5_SYNTH12_WAIT_CAL_BIN_FINE_LSB) & CHN5_SYNTH12_WAIT_CAL_BIN_FINE_MASK)
#define CHN5_SYNTH12_WAIT_CAL_BIN_FINE_RESET                                   0x9
#define CHN5_SYNTH12_ADDRESS                                                   (0x30 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH12_RSTMASK                                                   0xffffffff
#define CHN5_SYNTH12_RESET                                                     0xa14f189

// 0x34 (CHN5_SYNTH13)
#define CHN5_SYNTH13_WAIT_VCO_SETTLE_EXTRA_LSB                                 26
#define CHN5_SYNTH13_WAIT_VCO_SETTLE_EXTRA_MSB                                 31
#define CHN5_SYNTH13_WAIT_VCO_SETTLE_EXTRA_MASK                                0xfc000000
#define CHN5_SYNTH13_WAIT_VCO_SETTLE_EXTRA_GET(x)                              (((x) & CHN5_SYNTH13_WAIT_VCO_SETTLE_EXTRA_MASK) >> CHN5_SYNTH13_WAIT_VCO_SETTLE_EXTRA_LSB)
#define CHN5_SYNTH13_WAIT_VCO_SETTLE_EXTRA_SET(x)                              (((0 | (x)) << CHN5_SYNTH13_WAIT_VCO_SETTLE_EXTRA_LSB) & CHN5_SYNTH13_WAIT_VCO_SETTLE_EXTRA_MASK)
#define CHN5_SYNTH13_WAIT_VCO_SETTLE_EXTRA_RESET                               0x0
#define CHN5_SYNTH13_WAIT_VC_CHECK_LSB                                         20
#define CHN5_SYNTH13_WAIT_VC_CHECK_MSB                                         25
#define CHN5_SYNTH13_WAIT_VC_CHECK_MASK                                        0x3f00000
#define CHN5_SYNTH13_WAIT_VC_CHECK_GET(x)                                      (((x) & CHN5_SYNTH13_WAIT_VC_CHECK_MASK) >> CHN5_SYNTH13_WAIT_VC_CHECK_LSB)
#define CHN5_SYNTH13_WAIT_VC_CHECK_SET(x)                                      (((0 | (x)) << CHN5_SYNTH13_WAIT_VC_CHECK_LSB) & CHN5_SYNTH13_WAIT_VC_CHECK_MASK)
#define CHN5_SYNTH13_WAIT_VC_CHECK_RESET                                       0x5
#define CHN5_SYNTH13_WAIT_PIN_VC_EXTRA_LSB                                     16
#define CHN5_SYNTH13_WAIT_PIN_VC_EXTRA_MSB                                     19
#define CHN5_SYNTH13_WAIT_PIN_VC_EXTRA_MASK                                    0xf0000
#define CHN5_SYNTH13_WAIT_PIN_VC_EXTRA_GET(x)                                  (((x) & CHN5_SYNTH13_WAIT_PIN_VC_EXTRA_MASK) >> CHN5_SYNTH13_WAIT_PIN_VC_EXTRA_LSB)
#define CHN5_SYNTH13_WAIT_PIN_VC_EXTRA_SET(x)                                  (((0 | (x)) << CHN5_SYNTH13_WAIT_PIN_VC_EXTRA_LSB) & CHN5_SYNTH13_WAIT_PIN_VC_EXTRA_MASK)
#define CHN5_SYNTH13_WAIT_PIN_VC_EXTRA_RESET                                   0x4
#define CHN5_SYNTH13_MAX_LOST_VC_CNT_LSB                                       10
#define CHN5_SYNTH13_MAX_LOST_VC_CNT_MSB                                       15
#define CHN5_SYNTH13_MAX_LOST_VC_CNT_MASK                                      0xfc00
#define CHN5_SYNTH13_MAX_LOST_VC_CNT_GET(x)                                    (((x) & CHN5_SYNTH13_MAX_LOST_VC_CNT_MASK) >> CHN5_SYNTH13_MAX_LOST_VC_CNT_LSB)
#define CHN5_SYNTH13_MAX_LOST_VC_CNT_SET(x)                                    (((0 | (x)) << CHN5_SYNTH13_MAX_LOST_VC_CNT_LSB) & CHN5_SYNTH13_MAX_LOST_VC_CNT_MASK)
#define CHN5_SYNTH13_MAX_LOST_VC_CNT_RESET                                     0xa
#define CHN5_SYNTH13_DIS_CLK_XTAL_LSB                                          9
#define CHN5_SYNTH13_DIS_CLK_XTAL_MSB                                          9
#define CHN5_SYNTH13_DIS_CLK_XTAL_MASK                                         0x200
#define CHN5_SYNTH13_DIS_CLK_XTAL_GET(x)                                       (((x) & CHN5_SYNTH13_DIS_CLK_XTAL_MASK) >> CHN5_SYNTH13_DIS_CLK_XTAL_LSB)
#define CHN5_SYNTH13_DIS_CLK_XTAL_SET(x)                                       (((0 | (x)) << CHN5_SYNTH13_DIS_CLK_XTAL_LSB) & CHN5_SYNTH13_DIS_CLK_XTAL_MASK)
#define CHN5_SYNTH13_DIS_CLK_XTAL_RESET                                        0x0
#define CHN5_SYNTH13_SEL_CLK_DIV2_LSB                                          8
#define CHN5_SYNTH13_SEL_CLK_DIV2_MSB                                          8
#define CHN5_SYNTH13_SEL_CLK_DIV2_MASK                                         0x100
#define CHN5_SYNTH13_SEL_CLK_DIV2_GET(x)                                       (((x) & CHN5_SYNTH13_SEL_CLK_DIV2_MASK) >> CHN5_SYNTH13_SEL_CLK_DIV2_LSB)
#define CHN5_SYNTH13_SEL_CLK_DIV2_SET(x)                                       (((0 | (x)) << CHN5_SYNTH13_SEL_CLK_DIV2_LSB) & CHN5_SYNTH13_SEL_CLK_DIV2_MASK)
#define CHN5_SYNTH13_SEL_CLK_DIV2_RESET                                        0x1
#define CHN5_SYNTH13_CLKXTAL_EDGE_SEL_D_LSB                                    7
#define CHN5_SYNTH13_CLKXTAL_EDGE_SEL_D_MSB                                    7
#define CHN5_SYNTH13_CLKXTAL_EDGE_SEL_D_MASK                                   0x80
#define CHN5_SYNTH13_CLKXTAL_EDGE_SEL_D_GET(x)                                 (((x) & CHN5_SYNTH13_CLKXTAL_EDGE_SEL_D_MASK) >> CHN5_SYNTH13_CLKXTAL_EDGE_SEL_D_LSB)
#define CHN5_SYNTH13_CLKXTAL_EDGE_SEL_D_SET(x)                                 (((0 | (x)) << CHN5_SYNTH13_CLKXTAL_EDGE_SEL_D_LSB) & CHN5_SYNTH13_CLKXTAL_EDGE_SEL_D_MASK)
#define CHN5_SYNTH13_CLKXTAL_EDGE_SEL_D_RESET                                  0x0
#define CHN5_SYNTH13_FORCE_LO_ON_LSB                                           4
#define CHN5_SYNTH13_FORCE_LO_ON_MSB                                           4
#define CHN5_SYNTH13_FORCE_LO_ON_MASK                                          0x10
#define CHN5_SYNTH13_FORCE_LO_ON_GET(x)                                        (((x) & CHN5_SYNTH13_FORCE_LO_ON_MASK) >> CHN5_SYNTH13_FORCE_LO_ON_LSB)
#define CHN5_SYNTH13_FORCE_LO_ON_SET(x)                                        (((0 | (x)) << CHN5_SYNTH13_FORCE_LO_ON_LSB) & CHN5_SYNTH13_FORCE_LO_ON_MASK)
#define CHN5_SYNTH13_FORCE_LO_ON_RESET                                         0x0
#define CHN5_SYNTH13_ALWAYS_SHORTR_LSB                                         3
#define CHN5_SYNTH13_ALWAYS_SHORTR_MSB                                         3
#define CHN5_SYNTH13_ALWAYS_SHORTR_MASK                                        0x8
#define CHN5_SYNTH13_ALWAYS_SHORTR_GET(x)                                      (((x) & CHN5_SYNTH13_ALWAYS_SHORTR_MASK) >> CHN5_SYNTH13_ALWAYS_SHORTR_LSB)
#define CHN5_SYNTH13_ALWAYS_SHORTR_SET(x)                                      (((0 | (x)) << CHN5_SYNTH13_ALWAYS_SHORTR_LSB) & CHN5_SYNTH13_ALWAYS_SHORTR_MASK)
#define CHN5_SYNTH13_ALWAYS_SHORTR_RESET                                       0x0
#define CHN5_SYNTH13_SHORTR_UNTIL_LOCKED_LSB                                   2
#define CHN5_SYNTH13_SHORTR_UNTIL_LOCKED_MSB                                   2
#define CHN5_SYNTH13_SHORTR_UNTIL_LOCKED_MASK                                  0x4
#define CHN5_SYNTH13_SHORTR_UNTIL_LOCKED_GET(x)                                (((x) & CHN5_SYNTH13_SHORTR_UNTIL_LOCKED_MASK) >> CHN5_SYNTH13_SHORTR_UNTIL_LOCKED_LSB)
#define CHN5_SYNTH13_SHORTR_UNTIL_LOCKED_SET(x)                                (((0 | (x)) << CHN5_SYNTH13_SHORTR_UNTIL_LOCKED_LSB) & CHN5_SYNTH13_SHORTR_UNTIL_LOCKED_MASK)
#define CHN5_SYNTH13_SHORTR_UNTIL_LOCKED_RESET                                 0x0
#define CHN5_SYNTH13_INVERT_SDM_CLK_LSB                                        1
#define CHN5_SYNTH13_INVERT_SDM_CLK_MSB                                        1
#define CHN5_SYNTH13_INVERT_SDM_CLK_MASK                                       0x2
#define CHN5_SYNTH13_INVERT_SDM_CLK_GET(x)                                     (((x) & CHN5_SYNTH13_INVERT_SDM_CLK_MASK) >> CHN5_SYNTH13_INVERT_SDM_CLK_LSB)
#define CHN5_SYNTH13_INVERT_SDM_CLK_SET(x)                                     (((0 | (x)) << CHN5_SYNTH13_INVERT_SDM_CLK_LSB) & CHN5_SYNTH13_INVERT_SDM_CLK_MASK)
#define CHN5_SYNTH13_INVERT_SDM_CLK_RESET                                      0x0
#define CHN5_SYNTH13_SDM_DISABLE_LSB                                           0
#define CHN5_SYNTH13_SDM_DISABLE_MSB                                           0
#define CHN5_SYNTH13_SDM_DISABLE_MASK                                          0x1
#define CHN5_SYNTH13_SDM_DISABLE_GET(x)                                        (((x) & CHN5_SYNTH13_SDM_DISABLE_MASK) >> CHN5_SYNTH13_SDM_DISABLE_LSB)
#define CHN5_SYNTH13_SDM_DISABLE_SET(x)                                        (((0 | (x)) << CHN5_SYNTH13_SDM_DISABLE_LSB) & CHN5_SYNTH13_SDM_DISABLE_MASK)
#define CHN5_SYNTH13_SDM_DISABLE_RESET                                         0x0
#define CHN5_SYNTH13_ADDRESS                                                   (0x34 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH13_RSTMASK                                                   0xffffff9f
#define CHN5_SYNTH13_RESET                                                     0x542900

// 0x38 (CHN5_SYNTH14)
#define CHN5_SYNTH14_MONITOR_FBDIV2_LSB                                        31
#define CHN5_SYNTH14_MONITOR_FBDIV2_MSB                                        31
#define CHN5_SYNTH14_MONITOR_FBDIV2_MASK                                       0x80000000
#define CHN5_SYNTH14_MONITOR_FBDIV2_GET(x)                                     (((x) & CHN5_SYNTH14_MONITOR_FBDIV2_MASK) >> CHN5_SYNTH14_MONITOR_FBDIV2_LSB)
#define CHN5_SYNTH14_MONITOR_FBDIV2_SET(x)                                     (((0 | (x)) << CHN5_SYNTH14_MONITOR_FBDIV2_LSB) & CHN5_SYNTH14_MONITOR_FBDIV2_MASK)
#define CHN5_SYNTH14_MONITOR_FBDIV2_RESET                                      0x0
#define CHN5_SYNTH14_MONITOR_FB_LSB                                            30
#define CHN5_SYNTH14_MONITOR_FB_MSB                                            30
#define CHN5_SYNTH14_MONITOR_FB_MASK                                           0x40000000
#define CHN5_SYNTH14_MONITOR_FB_GET(x)                                         (((x) & CHN5_SYNTH14_MONITOR_FB_MASK) >> CHN5_SYNTH14_MONITOR_FB_LSB)
#define CHN5_SYNTH14_MONITOR_FB_SET(x)                                         (((0 | (x)) << CHN5_SYNTH14_MONITOR_FB_LSB) & CHN5_SYNTH14_MONITOR_FB_MASK)
#define CHN5_SYNTH14_MONITOR_FB_RESET                                          0x0
#define CHN5_SYNTH14_MONITOR_VC2HIGH_LSB                                       29
#define CHN5_SYNTH14_MONITOR_VC2HIGH_MSB                                       29
#define CHN5_SYNTH14_MONITOR_VC2HIGH_MASK                                      0x20000000
#define CHN5_SYNTH14_MONITOR_VC2HIGH_GET(x)                                    (((x) & CHN5_SYNTH14_MONITOR_VC2HIGH_MASK) >> CHN5_SYNTH14_MONITOR_VC2HIGH_LSB)
#define CHN5_SYNTH14_MONITOR_VC2HIGH_SET(x)                                    (((0 | (x)) << CHN5_SYNTH14_MONITOR_VC2HIGH_LSB) & CHN5_SYNTH14_MONITOR_VC2HIGH_MASK)
#define CHN5_SYNTH14_MONITOR_VC2HIGH_RESET                                     0x0
#define CHN5_SYNTH14_MONITOR_VC2LO_LSB                                         28
#define CHN5_SYNTH14_MONITOR_VC2LO_MSB                                         28
#define CHN5_SYNTH14_MONITOR_VC2LO_MASK                                        0x10000000
#define CHN5_SYNTH14_MONITOR_VC2LO_GET(x)                                      (((x) & CHN5_SYNTH14_MONITOR_VC2LO_MASK) >> CHN5_SYNTH14_MONITOR_VC2LO_LSB)
#define CHN5_SYNTH14_MONITOR_VC2LO_SET(x)                                      (((0 | (x)) << CHN5_SYNTH14_MONITOR_VC2LO_LSB) & CHN5_SYNTH14_MONITOR_VC2LO_MASK)
#define CHN5_SYNTH14_MONITOR_VC2LO_RESET                                       0x0
#define CHN5_SYNTH14_MONITOR_SYNTHLOCKVCOK_LSB                                 27
#define CHN5_SYNTH14_MONITOR_SYNTHLOCKVCOK_MSB                                 27
#define CHN5_SYNTH14_MONITOR_SYNTHLOCKVCOK_MASK                                0x8000000
#define CHN5_SYNTH14_MONITOR_SYNTHLOCKVCOK_GET(x)                              (((x) & CHN5_SYNTH14_MONITOR_SYNTHLOCKVCOK_MASK) >> CHN5_SYNTH14_MONITOR_SYNTHLOCKVCOK_LSB)
#define CHN5_SYNTH14_MONITOR_SYNTHLOCKVCOK_SET(x)                              (((0 | (x)) << CHN5_SYNTH14_MONITOR_SYNTHLOCKVCOK_LSB) & CHN5_SYNTH14_MONITOR_SYNTHLOCKVCOK_MASK)
#define CHN5_SYNTH14_MONITOR_SYNTHLOCKVCOK_RESET                               0x0
#define CHN5_SYNTH14_SYNTHDIGOUTEN_0_LSB                                       26
#define CHN5_SYNTH14_SYNTHDIGOUTEN_0_MSB                                       26
#define CHN5_SYNTH14_SYNTHDIGOUTEN_0_MASK                                      0x4000000
#define CHN5_SYNTH14_SYNTHDIGOUTEN_0_GET(x)                                    (((x) & CHN5_SYNTH14_SYNTHDIGOUTEN_0_MASK) >> CHN5_SYNTH14_SYNTHDIGOUTEN_0_LSB)
#define CHN5_SYNTH14_SYNTHDIGOUTEN_0_SET(x)                                    (((0 | (x)) << CHN5_SYNTH14_SYNTHDIGOUTEN_0_LSB) & CHN5_SYNTH14_SYNTHDIGOUTEN_0_MASK)
#define CHN5_SYNTH14_SYNTHDIGOUTEN_0_RESET                                     0x0
#define CHN5_SYNTH14_SYNTHDIGOUTEN_1_LSB                                       25
#define CHN5_SYNTH14_SYNTHDIGOUTEN_1_MSB                                       25
#define CHN5_SYNTH14_SYNTHDIGOUTEN_1_MASK                                      0x2000000
#define CHN5_SYNTH14_SYNTHDIGOUTEN_1_GET(x)                                    (((x) & CHN5_SYNTH14_SYNTHDIGOUTEN_1_MASK) >> CHN5_SYNTH14_SYNTHDIGOUTEN_1_LSB)
#define CHN5_SYNTH14_SYNTHDIGOUTEN_1_SET(x)                                    (((0 | (x)) << CHN5_SYNTH14_SYNTHDIGOUTEN_1_LSB) & CHN5_SYNTH14_SYNTHDIGOUTEN_1_MASK)
#define CHN5_SYNTH14_SYNTHDIGOUTEN_1_RESET                                     0x0
#define CHN5_SYNTH14_RESERVED_LSB                                              0
#define CHN5_SYNTH14_RESERVED_MSB                                              24
#define CHN5_SYNTH14_RESERVED_MASK                                             0x1ffffff
#define CHN5_SYNTH14_RESERVED_GET(x)                                           (((x) & CHN5_SYNTH14_RESERVED_MASK) >> CHN5_SYNTH14_RESERVED_LSB)
#define CHN5_SYNTH14_RESERVED_SET(x)                                           (((0 | (x)) << CHN5_SYNTH14_RESERVED_LSB) & CHN5_SYNTH14_RESERVED_MASK)
#define CHN5_SYNTH14_RESERVED_RESET                                            0x0
#define CHN5_SYNTH14_ADDRESS                                                   (0x38 + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH14_RSTMASK                                                   0xffffffff
#define CHN5_SYNTH14_RESET                                                     0x0

// 0x3c (CHN5_SYNTH15)
#define CHN5_SYNTH15_SYNTH_SPARE_LSB                                           0
#define CHN5_SYNTH15_SYNTH_SPARE_MSB                                           31
#define CHN5_SYNTH15_SYNTH_SPARE_MASK                                          0xffffffff
#define CHN5_SYNTH15_SYNTH_SPARE_GET(x)                                        (((x) & CHN5_SYNTH15_SYNTH_SPARE_MASK) >> CHN5_SYNTH15_SYNTH_SPARE_LSB)
#define CHN5_SYNTH15_SYNTH_SPARE_SET(x)                                        (((0 | (x)) << CHN5_SYNTH15_SYNTH_SPARE_LSB) & CHN5_SYNTH15_SYNTH_SPARE_MASK)
#define CHN5_SYNTH15_SYNTH_SPARE_RESET                                         0x0
#define CHN5_SYNTH15_ADDRESS                                                   (0x3c + __CHN5_SYN_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTH15_RSTMASK                                                   0xffffffff
#define CHN5_SYNTH15_RESET                                                     0x0



#endif /* _CHN5_SYN_REG_CSR_H_ */
