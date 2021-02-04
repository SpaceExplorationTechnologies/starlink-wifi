/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CHN5_SYN_1_REG_CSR_H_
#define _CHN5_SYN_1_REG_CSR_H_


#ifndef __CHN5_SYN_1_REG_CSR_BASE_ADDRESS
#define __CHN5_SYN_1_REG_CSR_BASE_ADDRESS (0x47780)
#endif


// 0x0 (CHN5_SYNTHB0)
#define CHN5_SYNTHB0_VCOCAPCNTSAVED_LSB                                        14
#define CHN5_SYNTHB0_VCOCAPCNTSAVED_MSB                                        31
#define CHN5_SYNTHB0_VCOCAPCNTSAVED_MASK                                       0xffffc000
#define CHN5_SYNTHB0_VCOCAPCNTSAVED_GET(x)                                     (((x) & CHN5_SYNTHB0_VCOCAPCNTSAVED_MASK) >> CHN5_SYNTHB0_VCOCAPCNTSAVED_LSB)
#define CHN5_SYNTHB0_VCOCAPCNTSAVED_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB0_VCOCAPCNTSAVED_LSB) & CHN5_SYNTHB0_VCOCAPCNTSAVED_MASK)
#define CHN5_SYNTHB0_VCOCAPCNTSAVED_RESET                                      0x0
#define CHN5_SYNTHB0_ICP_LSB                                                   8
#define CHN5_SYNTHB0_ICP_MSB                                                   13
#define CHN5_SYNTHB0_ICP_MASK                                                  0x3f00
#define CHN5_SYNTHB0_ICP_GET(x)                                                (((x) & CHN5_SYNTHB0_ICP_MASK) >> CHN5_SYNTHB0_ICP_LSB)
#define CHN5_SYNTHB0_ICP_SET(x)                                                (((0 | (x)) << CHN5_SYNTHB0_ICP_LSB) & CHN5_SYNTHB0_ICP_MASK)
#define CHN5_SYNTHB0_ICP_RESET                                                 0x0
#define CHN5_SYNTHB0_VC_MON_ERROR_COUNT_LSB                                    1
#define CHN5_SYNTHB0_VC_MON_ERROR_COUNT_MSB                                    7
#define CHN5_SYNTHB0_VC_MON_ERROR_COUNT_MASK                                   0xfe
#define CHN5_SYNTHB0_VC_MON_ERROR_COUNT_GET(x)                                 (((x) & CHN5_SYNTHB0_VC_MON_ERROR_COUNT_MASK) >> CHN5_SYNTHB0_VC_MON_ERROR_COUNT_LSB)
#define CHN5_SYNTHB0_VC_MON_ERROR_COUNT_SET(x)                                 (((0 | (x)) << CHN5_SYNTHB0_VC_MON_ERROR_COUNT_LSB) & CHN5_SYNTHB0_VC_MON_ERROR_COUNT_MASK)
#define CHN5_SYNTHB0_VC_MON_ERROR_COUNT_RESET                                  0x0
#define CHN5_SYNTHB0_ADDRESS                                                   (0x0 + __CHN5_SYN_1_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTHB0_RSTMASK                                                   0xfffffffe
#define CHN5_SYNTHB0_RESET                                                     0x0

// 0x4 (CHN5_SYNTHB1)
#define CHN5_SYNTHB1_SYNTH_ON_LSB                                              31
#define CHN5_SYNTHB1_SYNTH_ON_MSB                                              31
#define CHN5_SYNTHB1_SYNTH_ON_MASK                                             0x80000000
#define CHN5_SYNTHB1_SYNTH_ON_GET(x)                                           (((x) & CHN5_SYNTHB1_SYNTH_ON_MASK) >> CHN5_SYNTHB1_SYNTH_ON_LSB)
#define CHN5_SYNTHB1_SYNTH_ON_SET(x)                                           (((0 | (x)) << CHN5_SYNTHB1_SYNTH_ON_LSB) & CHN5_SYNTHB1_SYNTH_ON_MASK)
#define CHN5_SYNTHB1_SYNTH_ON_RESET                                            0x0
#define CHN5_SYNTHB1_SYNTH_SM_STATE_LSB                                        27
#define CHN5_SYNTHB1_SYNTH_SM_STATE_MSB                                        30
#define CHN5_SYNTHB1_SYNTH_SM_STATE_MASK                                       0x78000000
#define CHN5_SYNTHB1_SYNTH_SM_STATE_GET(x)                                     (((x) & CHN5_SYNTHB1_SYNTH_SM_STATE_MASK) >> CHN5_SYNTHB1_SYNTH_SM_STATE_LSB)
#define CHN5_SYNTHB1_SYNTH_SM_STATE_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB1_SYNTH_SM_STATE_LSB) & CHN5_SYNTHB1_SYNTH_SM_STATE_MASK)
#define CHN5_SYNTHB1_SYNTH_SM_STATE_RESET                                      0x0
#define CHN5_SYNTHB1_CAP_SEARCH_LSB                                            26
#define CHN5_SYNTHB1_CAP_SEARCH_MSB                                            26
#define CHN5_SYNTHB1_CAP_SEARCH_MASK                                           0x4000000
#define CHN5_SYNTHB1_CAP_SEARCH_GET(x)                                         (((x) & CHN5_SYNTHB1_CAP_SEARCH_MASK) >> CHN5_SYNTHB1_CAP_SEARCH_LSB)
#define CHN5_SYNTHB1_CAP_SEARCH_SET(x)                                         (((0 | (x)) << CHN5_SYNTHB1_CAP_SEARCH_LSB) & CHN5_SYNTHB1_CAP_SEARCH_MASK)
#define CHN5_SYNTHB1_CAP_SEARCH_RESET                                          0x0
#define CHN5_SYNTHB1_SYNTH_LOCK_VC_OK_LSB                                      25
#define CHN5_SYNTHB1_SYNTH_LOCK_VC_OK_MSB                                      25
#define CHN5_SYNTHB1_SYNTH_LOCK_VC_OK_MASK                                     0x2000000
#define CHN5_SYNTHB1_SYNTH_LOCK_VC_OK_GET(x)                                   (((x) & CHN5_SYNTHB1_SYNTH_LOCK_VC_OK_MASK) >> CHN5_SYNTHB1_SYNTH_LOCK_VC_OK_LSB)
#define CHN5_SYNTHB1_SYNTH_LOCK_VC_OK_SET(x)                                   (((0 | (x)) << CHN5_SYNTHB1_SYNTH_LOCK_VC_OK_LSB) & CHN5_SYNTHB1_SYNTH_LOCK_VC_OK_MASK)
#define CHN5_SYNTHB1_SYNTH_LOCK_VC_OK_RESET                                    0x0
#define CHN5_SYNTHB1_SYNTH_IS_LOCKED_LSB                                       24
#define CHN5_SYNTHB1_SYNTH_IS_LOCKED_MSB                                       24
#define CHN5_SYNTHB1_SYNTH_IS_LOCKED_MASK                                      0x1000000
#define CHN5_SYNTHB1_SYNTH_IS_LOCKED_GET(x)                                    (((x) & CHN5_SYNTHB1_SYNTH_IS_LOCKED_MASK) >> CHN5_SYNTHB1_SYNTH_IS_LOCKED_LSB)
#define CHN5_SYNTHB1_SYNTH_IS_LOCKED_SET(x)                                    (((0 | (x)) << CHN5_SYNTHB1_SYNTH_IS_LOCKED_LSB) & CHN5_SYNTHB1_SYNTH_IS_LOCKED_MASK)
#define CHN5_SYNTHB1_SYNTH_IS_LOCKED_RESET                                     0x0
#define CHN5_SYNTHB1_PIN_VC_LSB                                                23
#define CHN5_SYNTHB1_PIN_VC_MSB                                                23
#define CHN5_SYNTHB1_PIN_VC_MASK                                               0x800000
#define CHN5_SYNTHB1_PIN_VC_GET(x)                                             (((x) & CHN5_SYNTHB1_PIN_VC_MASK) >> CHN5_SYNTHB1_PIN_VC_LSB)
#define CHN5_SYNTHB1_PIN_VC_SET(x)                                             (((0 | (x)) << CHN5_SYNTHB1_PIN_VC_LSB) & CHN5_SYNTHB1_PIN_VC_MASK)
#define CHN5_SYNTHB1_PIN_VC_RESET                                              0x0
#define CHN5_SYNTHB1_VCO_CAP_ST_LSB                                            13
#define CHN5_SYNTHB1_VCO_CAP_ST_MSB                                            22
#define CHN5_SYNTHB1_VCO_CAP_ST_MASK                                           0x7fe000
#define CHN5_SYNTHB1_VCO_CAP_ST_GET(x)                                         (((x) & CHN5_SYNTHB1_VCO_CAP_ST_MASK) >> CHN5_SYNTHB1_VCO_CAP_ST_LSB)
#define CHN5_SYNTHB1_VCO_CAP_ST_SET(x)                                         (((0 | (x)) << CHN5_SYNTHB1_VCO_CAP_ST_LSB) & CHN5_SYNTHB1_VCO_CAP_ST_MASK)
#define CHN5_SYNTHB1_VCO_CAP_ST_RESET                                          0x0
#define CHN5_SYNTHB1_SHORT_R_LSB                                               12
#define CHN5_SYNTHB1_SHORT_R_MSB                                               12
#define CHN5_SYNTHB1_SHORT_R_MASK                                              0x1000
#define CHN5_SYNTHB1_SHORT_R_GET(x)                                            (((x) & CHN5_SYNTHB1_SHORT_R_MASK) >> CHN5_SYNTHB1_SHORT_R_LSB)
#define CHN5_SYNTHB1_SHORT_R_SET(x)                                            (((0 | (x)) << CHN5_SYNTHB1_SHORT_R_LSB) & CHN5_SYNTHB1_SHORT_R_MASK)
#define CHN5_SYNTHB1_SHORT_R_RESET                                             0x0
#define CHN5_SYNTHB1_RESETB_PFD_LSB                                            11
#define CHN5_SYNTHB1_RESETB_PFD_MSB                                            11
#define CHN5_SYNTHB1_RESETB_PFD_MASK                                           0x800
#define CHN5_SYNTHB1_RESETB_PFD_GET(x)                                         (((x) & CHN5_SYNTHB1_RESETB_PFD_MASK) >> CHN5_SYNTHB1_RESETB_PFD_LSB)
#define CHN5_SYNTHB1_RESETB_PFD_SET(x)                                         (((0 | (x)) << CHN5_SYNTHB1_RESETB_PFD_LSB) & CHN5_SYNTHB1_RESETB_PFD_MASK)
#define CHN5_SYNTHB1_RESETB_PFD_RESET                                          0x0
#define CHN5_SYNTHB1_RESET_PSCOUNTERS_LSB                                      10
#define CHN5_SYNTHB1_RESET_PSCOUNTERS_MSB                                      10
#define CHN5_SYNTHB1_RESET_PSCOUNTERS_MASK                                     0x400
#define CHN5_SYNTHB1_RESET_PSCOUNTERS_GET(x)                                   (((x) & CHN5_SYNTHB1_RESET_PSCOUNTERS_MASK) >> CHN5_SYNTHB1_RESET_PSCOUNTERS_LSB)
#define CHN5_SYNTHB1_RESET_PSCOUNTERS_SET(x)                                   (((0 | (x)) << CHN5_SYNTHB1_RESET_PSCOUNTERS_LSB) & CHN5_SYNTHB1_RESET_PSCOUNTERS_MASK)
#define CHN5_SYNTHB1_RESET_PSCOUNTERS_RESET                                    0x0
#define CHN5_SYNTHB1_RESET_SDM_B_LSB                                           9
#define CHN5_SYNTHB1_RESET_SDM_B_MSB                                           9
#define CHN5_SYNTHB1_RESET_SDM_B_MASK                                          0x200
#define CHN5_SYNTHB1_RESET_SDM_B_GET(x)                                        (((x) & CHN5_SYNTHB1_RESET_SDM_B_MASK) >> CHN5_SYNTHB1_RESET_SDM_B_LSB)
#define CHN5_SYNTHB1_RESET_SDM_B_SET(x)                                        (((0 | (x)) << CHN5_SYNTHB1_RESET_SDM_B_LSB) & CHN5_SYNTHB1_RESET_SDM_B_MASK)
#define CHN5_SYNTHB1_RESET_SDM_B_RESET                                         0x0
#define CHN5_SYNTHB1_VC2HIGH_LSB                                               8
#define CHN5_SYNTHB1_VC2HIGH_MSB                                               8
#define CHN5_SYNTHB1_VC2HIGH_MASK                                              0x100
#define CHN5_SYNTHB1_VC2HIGH_GET(x)                                            (((x) & CHN5_SYNTHB1_VC2HIGH_MASK) >> CHN5_SYNTHB1_VC2HIGH_LSB)
#define CHN5_SYNTHB1_VC2HIGH_SET(x)                                            (((0 | (x)) << CHN5_SYNTHB1_VC2HIGH_LSB) & CHN5_SYNTHB1_VC2HIGH_MASK)
#define CHN5_SYNTHB1_VC2HIGH_RESET                                             0x0
#define CHN5_SYNTHB1_VC2LOW_LSB                                                7
#define CHN5_SYNTHB1_VC2LOW_MSB                                                7
#define CHN5_SYNTHB1_VC2LOW_MASK                                               0x80
#define CHN5_SYNTHB1_VC2LOW_GET(x)                                             (((x) & CHN5_SYNTHB1_VC2LOW_MASK) >> CHN5_SYNTHB1_VC2LOW_LSB)
#define CHN5_SYNTHB1_VC2LOW_SET(x)                                             (((0 | (x)) << CHN5_SYNTHB1_VC2LOW_LSB) & CHN5_SYNTHB1_VC2LOW_MASK)
#define CHN5_SYNTHB1_VC2LOW_RESET                                              0x0
#define CHN5_SYNTHB1_ADDRESS                                                   (0x4 + __CHN5_SYN_1_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTHB1_RSTMASK                                                   0xffffff80
#define CHN5_SYNTHB1_RESET                                                     0x0

// 0x8 (CHN5_SYNTHB2)
#define CHN5_SYNTHB2_DLL_SM_STATE_LSB                                          30
#define CHN5_SYNTHB2_DLL_SM_STATE_MSB                                          31
#define CHN5_SYNTHB2_DLL_SM_STATE_MASK                                         0xc0000000
#define CHN5_SYNTHB2_DLL_SM_STATE_GET(x)                                       (((x) & CHN5_SYNTHB2_DLL_SM_STATE_MASK) >> CHN5_SYNTHB2_DLL_SM_STATE_LSB)
#define CHN5_SYNTHB2_DLL_SM_STATE_SET(x)                                       (((0 | (x)) << CHN5_SYNTHB2_DLL_SM_STATE_LSB) & CHN5_SYNTHB2_DLL_SM_STATE_MASK)
#define CHN5_SYNTHB2_DLL_SM_STATE_RESET                                        0x0
#define CHN5_SYNTHB2_DLL_IS_LOCKED_LSB                                         29
#define CHN5_SYNTHB2_DLL_IS_LOCKED_MSB                                         29
#define CHN5_SYNTHB2_DLL_IS_LOCKED_MASK                                        0x20000000
#define CHN5_SYNTHB2_DLL_IS_LOCKED_GET(x)                                      (((x) & CHN5_SYNTHB2_DLL_IS_LOCKED_MASK) >> CHN5_SYNTHB2_DLL_IS_LOCKED_LSB)
#define CHN5_SYNTHB2_DLL_IS_LOCKED_SET(x)                                      (((0 | (x)) << CHN5_SYNTHB2_DLL_IS_LOCKED_LSB) & CHN5_SYNTHB2_DLL_IS_LOCKED_MASK)
#define CHN5_SYNTHB2_DLL_IS_LOCKED_RESET                                       0x0
#define CHN5_SYNTHB2_DLL_CAPCUR_EXHAUSTED_LSB                                  28
#define CHN5_SYNTHB2_DLL_CAPCUR_EXHAUSTED_MSB                                  28
#define CHN5_SYNTHB2_DLL_CAPCUR_EXHAUSTED_MASK                                 0x10000000
#define CHN5_SYNTHB2_DLL_CAPCUR_EXHAUSTED_GET(x)                               (((x) & CHN5_SYNTHB2_DLL_CAPCUR_EXHAUSTED_MASK) >> CHN5_SYNTHB2_DLL_CAPCUR_EXHAUSTED_LSB)
#define CHN5_SYNTHB2_DLL_CAPCUR_EXHAUSTED_SET(x)                               (((0 | (x)) << CHN5_SYNTHB2_DLL_CAPCUR_EXHAUSTED_LSB) & CHN5_SYNTHB2_DLL_CAPCUR_EXHAUSTED_MASK)
#define CHN5_SYNTHB2_DLL_CAPCUR_EXHAUSTED_RESET                                0x0
#define CHN5_SYNTHB2_DLL_VCO_CUR_ST_LSB                                        24
#define CHN5_SYNTHB2_DLL_VCO_CUR_ST_MSB                                        27
#define CHN5_SYNTHB2_DLL_VCO_CUR_ST_MASK                                       0xf000000
#define CHN5_SYNTHB2_DLL_VCO_CUR_ST_GET(x)                                     (((x) & CHN5_SYNTHB2_DLL_VCO_CUR_ST_MASK) >> CHN5_SYNTHB2_DLL_VCO_CUR_ST_LSB)
#define CHN5_SYNTHB2_DLL_VCO_CUR_ST_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB2_DLL_VCO_CUR_ST_LSB) & CHN5_SYNTHB2_DLL_VCO_CUR_ST_MASK)
#define CHN5_SYNTHB2_DLL_VCO_CUR_ST_RESET                                      0x0
#define CHN5_SYNTHB2_DLL_VCO_CAP_ST_LSB                                        20
#define CHN5_SYNTHB2_DLL_VCO_CAP_ST_MSB                                        23
#define CHN5_SYNTHB2_DLL_VCO_CAP_ST_MASK                                       0xf00000
#define CHN5_SYNTHB2_DLL_VCO_CAP_ST_GET(x)                                     (((x) & CHN5_SYNTHB2_DLL_VCO_CAP_ST_MASK) >> CHN5_SYNTHB2_DLL_VCO_CAP_ST_LSB)
#define CHN5_SYNTHB2_DLL_VCO_CAP_ST_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB2_DLL_VCO_CAP_ST_LSB) & CHN5_SYNTHB2_DLL_VCO_CAP_ST_MASK)
#define CHN5_SYNTHB2_DLL_VCO_CAP_ST_RESET                                      0x0
#define CHN5_SYNTHB2_DLLVC2HI_LSB                                              19
#define CHN5_SYNTHB2_DLLVC2HI_MSB                                              19
#define CHN5_SYNTHB2_DLLVC2HI_MASK                                             0x80000
#define CHN5_SYNTHB2_DLLVC2HI_GET(x)                                           (((x) & CHN5_SYNTHB2_DLLVC2HI_MASK) >> CHN5_SYNTHB2_DLLVC2HI_LSB)
#define CHN5_SYNTHB2_DLLVC2HI_SET(x)                                           (((0 | (x)) << CHN5_SYNTHB2_DLLVC2HI_LSB) & CHN5_SYNTHB2_DLLVC2HI_MASK)
#define CHN5_SYNTHB2_DLLVC2HI_RESET                                            0x0
#define CHN5_SYNTHB2_DLLVC2LO_LSB                                              18
#define CHN5_SYNTHB2_DLLVC2LO_MSB                                              18
#define CHN5_SYNTHB2_DLLVC2LO_MASK                                             0x40000
#define CHN5_SYNTHB2_DLLVC2LO_GET(x)                                           (((x) & CHN5_SYNTHB2_DLLVC2LO_MASK) >> CHN5_SYNTHB2_DLLVC2LO_LSB)
#define CHN5_SYNTHB2_DLLVC2LO_SET(x)                                           (((0 | (x)) << CHN5_SYNTHB2_DLLVC2LO_LSB) & CHN5_SYNTHB2_DLLVC2LO_MASK)
#define CHN5_SYNTHB2_DLLVC2LO_RESET                                            0x0
#define CHN5_SYNTHB2_VCO_CAP_ST_BIN_SEARCH_LSB                                 8
#define CHN5_SYNTHB2_VCO_CAP_ST_BIN_SEARCH_MSB                                 17
#define CHN5_SYNTHB2_VCO_CAP_ST_BIN_SEARCH_MASK                                0x3ff00
#define CHN5_SYNTHB2_VCO_CAP_ST_BIN_SEARCH_GET(x)                              (((x) & CHN5_SYNTHB2_VCO_CAP_ST_BIN_SEARCH_MASK) >> CHN5_SYNTHB2_VCO_CAP_ST_BIN_SEARCH_LSB)
#define CHN5_SYNTHB2_VCO_CAP_ST_BIN_SEARCH_SET(x)                              (((0 | (x)) << CHN5_SYNTHB2_VCO_CAP_ST_BIN_SEARCH_LSB) & CHN5_SYNTHB2_VCO_CAP_ST_BIN_SEARCH_MASK)
#define CHN5_SYNTHB2_VCO_CAP_ST_BIN_SEARCH_RESET                               0x0
#define CHN5_SYNTHB2_VHT160_MODE_LSB                                           6
#define CHN5_SYNTHB2_VHT160_MODE_MSB                                           6
#define CHN5_SYNTHB2_VHT160_MODE_MASK                                          0x40
#define CHN5_SYNTHB2_VHT160_MODE_GET(x)                                        (((x) & CHN5_SYNTHB2_VHT160_MODE_MASK) >> CHN5_SYNTHB2_VHT160_MODE_LSB)
#define CHN5_SYNTHB2_VHT160_MODE_SET(x)                                        (((0 | (x)) << CHN5_SYNTHB2_VHT160_MODE_LSB) & CHN5_SYNTHB2_VHT160_MODE_MASK)
#define CHN5_SYNTHB2_VHT160_MODE_RESET                                         0x0
#define CHN5_SYNTHB2_VHT160_EN_LSB                                             5
#define CHN5_SYNTHB2_VHT160_EN_MSB                                             5
#define CHN5_SYNTHB2_VHT160_EN_MASK                                            0x20
#define CHN5_SYNTHB2_VHT160_EN_GET(x)                                          (((x) & CHN5_SYNTHB2_VHT160_EN_MASK) >> CHN5_SYNTHB2_VHT160_EN_LSB)
#define CHN5_SYNTHB2_VHT160_EN_SET(x)                                          (((0 | (x)) << CHN5_SYNTHB2_VHT160_EN_LSB) & CHN5_SYNTHB2_VHT160_EN_MASK)
#define CHN5_SYNTHB2_VHT160_EN_RESET                                           0x0
#define CHN5_SYNTHB2_PAL_ON_LSB                                                4
#define CHN5_SYNTHB2_PAL_ON_MSB                                                4
#define CHN5_SYNTHB2_PAL_ON_MASK                                               0x10
#define CHN5_SYNTHB2_PAL_ON_GET(x)                                             (((x) & CHN5_SYNTHB2_PAL_ON_MASK) >> CHN5_SYNTHB2_PAL_ON_LSB)
#define CHN5_SYNTHB2_PAL_ON_SET(x)                                             (((0 | (x)) << CHN5_SYNTHB2_PAL_ON_LSB) & CHN5_SYNTHB2_PAL_ON_MASK)
#define CHN5_SYNTHB2_PAL_ON_RESET                                              0x0
#define CHN5_SYNTHB2_PP_PAL_BIST_FAIL_LSB                                      3
#define CHN5_SYNTHB2_PP_PAL_BIST_FAIL_MSB                                      3
#define CHN5_SYNTHB2_PP_PAL_BIST_FAIL_MASK                                     0x8
#define CHN5_SYNTHB2_PP_PAL_BIST_FAIL_GET(x)                                   (((x) & CHN5_SYNTHB2_PP_PAL_BIST_FAIL_MASK) >> CHN5_SYNTHB2_PP_PAL_BIST_FAIL_LSB)
#define CHN5_SYNTHB2_PP_PAL_BIST_FAIL_SET(x)                                   (((0 | (x)) << CHN5_SYNTHB2_PP_PAL_BIST_FAIL_LSB) & CHN5_SYNTHB2_PP_PAL_BIST_FAIL_MASK)
#define CHN5_SYNTHB2_PP_PAL_BIST_FAIL_RESET                                    0x0
#define CHN5_SYNTHB2_PAL_RESULT_MDIV_LSB                                       2
#define CHN5_SYNTHB2_PAL_RESULT_MDIV_MSB                                       2
#define CHN5_SYNTHB2_PAL_RESULT_MDIV_MASK                                      0x4
#define CHN5_SYNTHB2_PAL_RESULT_MDIV_GET(x)                                    (((x) & CHN5_SYNTHB2_PAL_RESULT_MDIV_MASK) >> CHN5_SYNTHB2_PAL_RESULT_MDIV_LSB)
#define CHN5_SYNTHB2_PAL_RESULT_MDIV_SET(x)                                    (((0 | (x)) << CHN5_SYNTHB2_PAL_RESULT_MDIV_LSB) & CHN5_SYNTHB2_PAL_RESULT_MDIV_MASK)
#define CHN5_SYNTHB2_PAL_RESULT_MDIV_RESET                                     0x0
#define CHN5_SYNTHB2_PAL_FLIP_MDIV_LSB                                         0
#define CHN5_SYNTHB2_PAL_FLIP_MDIV_MSB                                         1
#define CHN5_SYNTHB2_PAL_FLIP_MDIV_MASK                                        0x3
#define CHN5_SYNTHB2_PAL_FLIP_MDIV_GET(x)                                      (((x) & CHN5_SYNTHB2_PAL_FLIP_MDIV_MASK) >> CHN5_SYNTHB2_PAL_FLIP_MDIV_LSB)
#define CHN5_SYNTHB2_PAL_FLIP_MDIV_SET(x)                                      (((0 | (x)) << CHN5_SYNTHB2_PAL_FLIP_MDIV_LSB) & CHN5_SYNTHB2_PAL_FLIP_MDIV_MASK)
#define CHN5_SYNTHB2_PAL_FLIP_MDIV_RESET                                       0x0
#define CHN5_SYNTHB2_ADDRESS                                                   (0x8 + __CHN5_SYN_1_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTHB2_RSTMASK                                                   0xffffff7f
#define CHN5_SYNTHB2_RESET                                                     0x0

// 0xc (CHN5_SYNTHB3)
#define CHN5_SYNTHB3_PAL_DISABLE_LSB                                           31
#define CHN5_SYNTHB3_PAL_DISABLE_MSB                                           31
#define CHN5_SYNTHB3_PAL_DISABLE_MASK                                          0x80000000
#define CHN5_SYNTHB3_PAL_DISABLE_GET(x)                                        (((x) & CHN5_SYNTHB3_PAL_DISABLE_MASK) >> CHN5_SYNTHB3_PAL_DISABLE_LSB)
#define CHN5_SYNTHB3_PAL_DISABLE_SET(x)                                        (((0 | (x)) << CHN5_SYNTHB3_PAL_DISABLE_LSB) & CHN5_SYNTHB3_PAL_DISABLE_MASK)
#define CHN5_SYNTHB3_PAL_DISABLE_RESET                                         0x0
#define CHN5_SYNTHB3_PAL_START_LSB                                             30
#define CHN5_SYNTHB3_PAL_START_MSB                                             30
#define CHN5_SYNTHB3_PAL_START_MASK                                            0x40000000
#define CHN5_SYNTHB3_PAL_START_GET(x)                                          (((x) & CHN5_SYNTHB3_PAL_START_MASK) >> CHN5_SYNTHB3_PAL_START_LSB)
#define CHN5_SYNTHB3_PAL_START_SET(x)                                          (((0 | (x)) << CHN5_SYNTHB3_PAL_START_LSB) & CHN5_SYNTHB3_PAL_START_MASK)
#define CHN5_SYNTHB3_PAL_START_RESET                                           0x0
#define CHN5_SYNTHB3_PAL_START_SEL_LSB                                         29
#define CHN5_SYNTHB3_PAL_START_SEL_MSB                                         29
#define CHN5_SYNTHB3_PAL_START_SEL_MASK                                        0x20000000
#define CHN5_SYNTHB3_PAL_START_SEL_GET(x)                                      (((x) & CHN5_SYNTHB3_PAL_START_SEL_MASK) >> CHN5_SYNTHB3_PAL_START_SEL_LSB)
#define CHN5_SYNTHB3_PAL_START_SEL_SET(x)                                      (((0 | (x)) << CHN5_SYNTHB3_PAL_START_SEL_LSB) & CHN5_SYNTHB3_PAL_START_SEL_MASK)
#define CHN5_SYNTHB3_PAL_START_SEL_RESET                                       0x0
#define CHN5_SYNTHB3_PAL_EN_ON_BS_LSB                                          28
#define CHN5_SYNTHB3_PAL_EN_ON_BS_MSB                                          28
#define CHN5_SYNTHB3_PAL_EN_ON_BS_MASK                                         0x10000000
#define CHN5_SYNTHB3_PAL_EN_ON_BS_GET(x)                                       (((x) & CHN5_SYNTHB3_PAL_EN_ON_BS_MASK) >> CHN5_SYNTHB3_PAL_EN_ON_BS_LSB)
#define CHN5_SYNTHB3_PAL_EN_ON_BS_SET(x)                                       (((0 | (x)) << CHN5_SYNTHB3_PAL_EN_ON_BS_LSB) & CHN5_SYNTHB3_PAL_EN_ON_BS_MASK)
#define CHN5_SYNTHB3_PAL_EN_ON_BS_RESET                                        0x1
#define CHN5_SYNTHB3_PAL_COMP_CAL_DELAY_LSB                                    26
#define CHN5_SYNTHB3_PAL_COMP_CAL_DELAY_MSB                                    27
#define CHN5_SYNTHB3_PAL_COMP_CAL_DELAY_MASK                                   0xc000000
#define CHN5_SYNTHB3_PAL_COMP_CAL_DELAY_GET(x)                                 (((x) & CHN5_SYNTHB3_PAL_COMP_CAL_DELAY_MASK) >> CHN5_SYNTHB3_PAL_COMP_CAL_DELAY_LSB)
#define CHN5_SYNTHB3_PAL_COMP_CAL_DELAY_SET(x)                                 (((0 | (x)) << CHN5_SYNTHB3_PAL_COMP_CAL_DELAY_LSB) & CHN5_SYNTHB3_PAL_COMP_CAL_DELAY_MASK)
#define CHN5_SYNTHB3_PAL_COMP_CAL_DELAY_RESET                                  0x0
#define CHN5_SYNTHB3_VHT160_EARLY_TIME_LSB                                     24
#define CHN5_SYNTHB3_VHT160_EARLY_TIME_MSB                                     25
#define CHN5_SYNTHB3_VHT160_EARLY_TIME_MASK                                    0x3000000
#define CHN5_SYNTHB3_VHT160_EARLY_TIME_GET(x)                                  (((x) & CHN5_SYNTHB3_VHT160_EARLY_TIME_MASK) >> CHN5_SYNTHB3_VHT160_EARLY_TIME_LSB)
#define CHN5_SYNTHB3_VHT160_EARLY_TIME_SET(x)                                  (((0 | (x)) << CHN5_SYNTHB3_VHT160_EARLY_TIME_LSB) & CHN5_SYNTHB3_VHT160_EARLY_TIME_MASK)
#define CHN5_SYNTHB3_VHT160_EARLY_TIME_RESET                                   0x0
#define CHN5_SYNTHB3_VHT160_MODE_OVR_LSB                                       22
#define CHN5_SYNTHB3_VHT160_MODE_OVR_MSB                                       23
#define CHN5_SYNTHB3_VHT160_MODE_OVR_MASK                                      0xc00000
#define CHN5_SYNTHB3_VHT160_MODE_OVR_GET(x)                                    (((x) & CHN5_SYNTHB3_VHT160_MODE_OVR_MASK) >> CHN5_SYNTHB3_VHT160_MODE_OVR_LSB)
#define CHN5_SYNTHB3_VHT160_MODE_OVR_SET(x)                                    (((0 | (x)) << CHN5_SYNTHB3_VHT160_MODE_OVR_LSB) & CHN5_SYNTHB3_VHT160_MODE_OVR_MASK)
#define CHN5_SYNTHB3_VHT160_MODE_OVR_RESET                                     0x0
#define CHN5_SYNTHB3_VHT160_EN_OVR_LSB                                         20
#define CHN5_SYNTHB3_VHT160_EN_OVR_MSB                                         21
#define CHN5_SYNTHB3_VHT160_EN_OVR_MASK                                        0x300000
#define CHN5_SYNTHB3_VHT160_EN_OVR_GET(x)                                      (((x) & CHN5_SYNTHB3_VHT160_EN_OVR_MASK) >> CHN5_SYNTHB3_VHT160_EN_OVR_LSB)
#define CHN5_SYNTHB3_VHT160_EN_OVR_SET(x)                                      (((0 | (x)) << CHN5_SYNTHB3_VHT160_EN_OVR_LSB) & CHN5_SYNTHB3_VHT160_EN_OVR_MASK)
#define CHN5_SYNTHB3_VHT160_EN_OVR_RESET                                       0x0
#define CHN5_SYNTHB3_PAL_COMP_START_OVR_LSB                                    18
#define CHN5_SYNTHB3_PAL_COMP_START_OVR_MSB                                    19
#define CHN5_SYNTHB3_PAL_COMP_START_OVR_MASK                                   0xc0000
#define CHN5_SYNTHB3_PAL_COMP_START_OVR_GET(x)                                 (((x) & CHN5_SYNTHB3_PAL_COMP_START_OVR_MASK) >> CHN5_SYNTHB3_PAL_COMP_START_OVR_LSB)
#define CHN5_SYNTHB3_PAL_COMP_START_OVR_SET(x)                                 (((0 | (x)) << CHN5_SYNTHB3_PAL_COMP_START_OVR_LSB) & CHN5_SYNTHB3_PAL_COMP_START_OVR_MASK)
#define CHN5_SYNTHB3_PAL_COMP_START_OVR_RESET                                  0x0
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_POS_LSB                                17
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_POS_MSB                                17
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_POS_MASK                               0x20000
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_POS_GET(x)                             (((x) & CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_POS_MASK) >> CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_POS_LSB)
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_POS_SET(x)                             (((0 | (x)) << CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_POS_LSB) & CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_POS_MASK)
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_POS_RESET                              0x1
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_NEG_LSB                                16
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_NEG_MSB                                16
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_NEG_MASK                               0x10000
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_NEG_GET(x)                             (((x) & CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_NEG_MASK) >> CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_NEG_LSB)
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_NEG_SET(x)                             (((0 | (x)) << CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_NEG_LSB) & CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_NEG_MASK)
#define CHN5_SYNTHB3_PP_PAL_DISABLE_VHT_NEG_RESET                              0x0
#define CHN5_SYNTHB3_PP_PAL_DISABLE_FLIP_LSB                                   15
#define CHN5_SYNTHB3_PP_PAL_DISABLE_FLIP_MSB                                   15
#define CHN5_SYNTHB3_PP_PAL_DISABLE_FLIP_MASK                                  0x8000
#define CHN5_SYNTHB3_PP_PAL_DISABLE_FLIP_GET(x)                                (((x) & CHN5_SYNTHB3_PP_PAL_DISABLE_FLIP_MASK) >> CHN5_SYNTHB3_PP_PAL_DISABLE_FLIP_LSB)
#define CHN5_SYNTHB3_PP_PAL_DISABLE_FLIP_SET(x)                                (((0 | (x)) << CHN5_SYNTHB3_PP_PAL_DISABLE_FLIP_LSB) & CHN5_SYNTHB3_PP_PAL_DISABLE_FLIP_MASK)
#define CHN5_SYNTHB3_PP_PAL_DISABLE_FLIP_RESET                                 0x0
#define CHN5_SYNTHB3_PP_PAL_START_LSB                                          14
#define CHN5_SYNTHB3_PP_PAL_START_MSB                                          14
#define CHN5_SYNTHB3_PP_PAL_START_MASK                                         0x4000
#define CHN5_SYNTHB3_PP_PAL_START_GET(x)                                       (((x) & CHN5_SYNTHB3_PP_PAL_START_MASK) >> CHN5_SYNTHB3_PP_PAL_START_LSB)
#define CHN5_SYNTHB3_PP_PAL_START_SET(x)                                       (((0 | (x)) << CHN5_SYNTHB3_PP_PAL_START_LSB) & CHN5_SYNTHB3_PP_PAL_START_MASK)
#define CHN5_SYNTHB3_PP_PAL_START_RESET                                        0x0
#define CHN5_SYNTHB3_PP_PAL_COMP_REPEAT_LSB                                    13
#define CHN5_SYNTHB3_PP_PAL_COMP_REPEAT_MSB                                    13
#define CHN5_SYNTHB3_PP_PAL_COMP_REPEAT_MASK                                   0x2000
#define CHN5_SYNTHB3_PP_PAL_COMP_REPEAT_GET(x)                                 (((x) & CHN5_SYNTHB3_PP_PAL_COMP_REPEAT_MASK) >> CHN5_SYNTHB3_PP_PAL_COMP_REPEAT_LSB)
#define CHN5_SYNTHB3_PP_PAL_COMP_REPEAT_SET(x)                                 (((0 | (x)) << CHN5_SYNTHB3_PP_PAL_COMP_REPEAT_LSB) & CHN5_SYNTHB3_PP_PAL_COMP_REPEAT_MASK)
#define CHN5_SYNTHB3_PP_PAL_COMP_REPEAT_RESET                                  0x0
#define CHN5_SYNTHB3_PP_PAL_COMP_START_DELAY_LSB                               10
#define CHN5_SYNTHB3_PP_PAL_COMP_START_DELAY_MSB                               12
#define CHN5_SYNTHB3_PP_PAL_COMP_START_DELAY_MASK                              0x1c00
#define CHN5_SYNTHB3_PP_PAL_COMP_START_DELAY_GET(x)                            (((x) & CHN5_SYNTHB3_PP_PAL_COMP_START_DELAY_MASK) >> CHN5_SYNTHB3_PP_PAL_COMP_START_DELAY_LSB)
#define CHN5_SYNTHB3_PP_PAL_COMP_START_DELAY_SET(x)                            (((0 | (x)) << CHN5_SYNTHB3_PP_PAL_COMP_START_DELAY_LSB) & CHN5_SYNTHB3_PP_PAL_COMP_START_DELAY_MASK)
#define CHN5_SYNTHB3_PP_PAL_COMP_START_DELAY_RESET                             0x1
#define CHN5_SYNTHB3_PP_PAL_COMP_DUR_LSB                                       8
#define CHN5_SYNTHB3_PP_PAL_COMP_DUR_MSB                                       9
#define CHN5_SYNTHB3_PP_PAL_COMP_DUR_MASK                                      0x300
#define CHN5_SYNTHB3_PP_PAL_COMP_DUR_GET(x)                                    (((x) & CHN5_SYNTHB3_PP_PAL_COMP_DUR_MASK) >> CHN5_SYNTHB3_PP_PAL_COMP_DUR_LSB)
#define CHN5_SYNTHB3_PP_PAL_COMP_DUR_SET(x)                                    (((0 | (x)) << CHN5_SYNTHB3_PP_PAL_COMP_DUR_LSB) & CHN5_SYNTHB3_PP_PAL_COMP_DUR_MASK)
#define CHN5_SYNTHB3_PP_PAL_COMP_DUR_RESET                                     0x1
#define CHN5_SYNTHB3_PP_PAL_BIST_EN_LSB                                        7
#define CHN5_SYNTHB3_PP_PAL_BIST_EN_MSB                                        7
#define CHN5_SYNTHB3_PP_PAL_BIST_EN_MASK                                       0x80
#define CHN5_SYNTHB3_PP_PAL_BIST_EN_GET(x)                                     (((x) & CHN5_SYNTHB3_PP_PAL_BIST_EN_MASK) >> CHN5_SYNTHB3_PP_PAL_BIST_EN_LSB)
#define CHN5_SYNTHB3_PP_PAL_BIST_EN_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB3_PP_PAL_BIST_EN_LSB) & CHN5_SYNTHB3_PP_PAL_BIST_EN_MASK)
#define CHN5_SYNTHB3_PP_PAL_BIST_EN_RESET                                      0x0
#define CHN5_SYNTHB3_PAL_BIST_START_LSB                                        6
#define CHN5_SYNTHB3_PAL_BIST_START_MSB                                        6
#define CHN5_SYNTHB3_PAL_BIST_START_MASK                                       0x40
#define CHN5_SYNTHB3_PAL_BIST_START_GET(x)                                     (((x) & CHN5_SYNTHB3_PAL_BIST_START_MASK) >> CHN5_SYNTHB3_PAL_BIST_START_LSB)
#define CHN5_SYNTHB3_PAL_BIST_START_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB3_PAL_BIST_START_LSB) & CHN5_SYNTHB3_PAL_BIST_START_MASK)
#define CHN5_SYNTHB3_PAL_BIST_START_RESET                                      0x0
#define CHN5_SYNTHB3_PP_PAL_BIST_START_LSB                                     5
#define CHN5_SYNTHB3_PP_PAL_BIST_START_MSB                                     5
#define CHN5_SYNTHB3_PP_PAL_BIST_START_MASK                                    0x20
#define CHN5_SYNTHB3_PP_PAL_BIST_START_GET(x)                                  (((x) & CHN5_SYNTHB3_PP_PAL_BIST_START_MASK) >> CHN5_SYNTHB3_PP_PAL_BIST_START_LSB)
#define CHN5_SYNTHB3_PP_PAL_BIST_START_SET(x)                                  (((0 | (x)) << CHN5_SYNTHB3_PP_PAL_BIST_START_LSB) & CHN5_SYNTHB3_PP_PAL_BIST_START_MASK)
#define CHN5_SYNTHB3_PP_PAL_BIST_START_RESET                                   0x0
#define CHN5_SYNTHB3_PAL_FLIP_MDIV_RESET_LSB                                   4
#define CHN5_SYNTHB3_PAL_FLIP_MDIV_RESET_MSB                                   4
#define CHN5_SYNTHB3_PAL_FLIP_MDIV_RESET_MASK                                  0x10
#define CHN5_SYNTHB3_PAL_FLIP_MDIV_RESET_GET(x)                                (((x) & CHN5_SYNTHB3_PAL_FLIP_MDIV_RESET_MASK) >> CHN5_SYNTHB3_PAL_FLIP_MDIV_RESET_LSB)
#define CHN5_SYNTHB3_PAL_FLIP_MDIV_RESET_SET(x)                                (((0 | (x)) << CHN5_SYNTHB3_PAL_FLIP_MDIV_RESET_LSB) & CHN5_SYNTHB3_PAL_FLIP_MDIV_RESET_MASK)
#define CHN5_SYNTHB3_PAL_FLIP_MDIV_RESET_RESET                                 0x0
#define CHN5_SYNTHB3_PAL_USE_SWAL_LSB                                          3
#define CHN5_SYNTHB3_PAL_USE_SWAL_MSB                                          3
#define CHN5_SYNTHB3_PAL_USE_SWAL_MASK                                         0x8
#define CHN5_SYNTHB3_PAL_USE_SWAL_GET(x)                                       (((x) & CHN5_SYNTHB3_PAL_USE_SWAL_MASK) >> CHN5_SYNTHB3_PAL_USE_SWAL_LSB)
#define CHN5_SYNTHB3_PAL_USE_SWAL_SET(x)                                       (((0 | (x)) << CHN5_SYNTHB3_PAL_USE_SWAL_LSB) & CHN5_SYNTHB3_PAL_USE_SWAL_MASK)
#define CHN5_SYNTHB3_PAL_USE_SWAL_RESET                                        0x0
#define CHN5_SYNTHB3_PAL_FLIP_SWAP_LSB                                         2
#define CHN5_SYNTHB3_PAL_FLIP_SWAP_MSB                                         2
#define CHN5_SYNTHB3_PAL_FLIP_SWAP_MASK                                        0x4
#define CHN5_SYNTHB3_PAL_FLIP_SWAP_GET(x)                                      (((x) & CHN5_SYNTHB3_PAL_FLIP_SWAP_MASK) >> CHN5_SYNTHB3_PAL_FLIP_SWAP_LSB)
#define CHN5_SYNTHB3_PAL_FLIP_SWAP_SET(x)                                      (((0 | (x)) << CHN5_SYNTHB3_PAL_FLIP_SWAP_LSB) & CHN5_SYNTHB3_PAL_FLIP_SWAP_MASK)
#define CHN5_SYNTHB3_PAL_FLIP_SWAP_RESET                                       0x0
#define CHN5_SYNTHB3_RESERVED_LSB                                              0
#define CHN5_SYNTHB3_RESERVED_MSB                                              1
#define CHN5_SYNTHB3_RESERVED_MASK                                             0x3
#define CHN5_SYNTHB3_RESERVED_GET(x)                                           (((x) & CHN5_SYNTHB3_RESERVED_MASK) >> CHN5_SYNTHB3_RESERVED_LSB)
#define CHN5_SYNTHB3_RESERVED_SET(x)                                           (((0 | (x)) << CHN5_SYNTHB3_RESERVED_LSB) & CHN5_SYNTHB3_RESERVED_MASK)
#define CHN5_SYNTHB3_RESERVED_RESET                                            0x0
#define CHN5_SYNTHB3_ADDRESS                                                   (0xc + __CHN5_SYN_1_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTHB3_RSTMASK                                                   0xffffffff
#define CHN5_SYNTHB3_RESET                                                     0x10020500

// 0x10 (CHN5_SYNTHB4)
#define CHN5_SYNTHB4_PAL_FLIP_DATA_LSB                                         30
#define CHN5_SYNTHB4_PAL_FLIP_DATA_MSB                                         31
#define CHN5_SYNTHB4_PAL_FLIP_DATA_MASK                                        0xc0000000
#define CHN5_SYNTHB4_PAL_FLIP_DATA_GET(x)                                      (((x) & CHN5_SYNTHB4_PAL_FLIP_DATA_MASK) >> CHN5_SYNTHB4_PAL_FLIP_DATA_LSB)
#define CHN5_SYNTHB4_PAL_FLIP_DATA_SET(x)                                      (((0 | (x)) << CHN5_SYNTHB4_PAL_FLIP_DATA_LSB) & CHN5_SYNTHB4_PAL_FLIP_DATA_MASK)
#define CHN5_SYNTHB4_PAL_FLIP_DATA_RESET                                       0x0
#define CHN5_SYNTHB4_PAL_FLIP_START_LSB                                        29
#define CHN5_SYNTHB4_PAL_FLIP_START_MSB                                        29
#define CHN5_SYNTHB4_PAL_FLIP_START_MASK                                       0x20000000
#define CHN5_SYNTHB4_PAL_FLIP_START_GET(x)                                     (((x) & CHN5_SYNTHB4_PAL_FLIP_START_MASK) >> CHN5_SYNTHB4_PAL_FLIP_START_LSB)
#define CHN5_SYNTHB4_PAL_FLIP_START_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB4_PAL_FLIP_START_LSB) & CHN5_SYNTHB4_PAL_FLIP_START_MASK)
#define CHN5_SYNTHB4_PAL_FLIP_START_RESET                                      0x0
#define CHN5_SYNTHB4_RESERVED_LSB                                              8
#define CHN5_SYNTHB4_RESERVED_MSB                                              28
#define CHN5_SYNTHB4_RESERVED_MASK                                             0x1fffff00
#define CHN5_SYNTHB4_RESERVED_GET(x)                                           (((x) & CHN5_SYNTHB4_RESERVED_MASK) >> CHN5_SYNTHB4_RESERVED_LSB)
#define CHN5_SYNTHB4_RESERVED_SET(x)                                           (((0 | (x)) << CHN5_SYNTHB4_RESERVED_LSB) & CHN5_SYNTHB4_RESERVED_MASK)
#define CHN5_SYNTHB4_RESERVED_RESET                                            0x0
#define CHN5_SYNTHB4_PAL_DTEST1_LSB                                            4
#define CHN5_SYNTHB4_PAL_DTEST1_MSB                                            7
#define CHN5_SYNTHB4_PAL_DTEST1_MASK                                           0xf0
#define CHN5_SYNTHB4_PAL_DTEST1_GET(x)                                         (((x) & CHN5_SYNTHB4_PAL_DTEST1_MASK) >> CHN5_SYNTHB4_PAL_DTEST1_LSB)
#define CHN5_SYNTHB4_PAL_DTEST1_SET(x)                                         (((0 | (x)) << CHN5_SYNTHB4_PAL_DTEST1_LSB) & CHN5_SYNTHB4_PAL_DTEST1_MASK)
#define CHN5_SYNTHB4_PAL_DTEST1_RESET                                          0x0
#define CHN5_SYNTHB4_PAL_DTEST0_LSB                                            0
#define CHN5_SYNTHB4_PAL_DTEST0_MSB                                            3
#define CHN5_SYNTHB4_PAL_DTEST0_MASK                                           0xf
#define CHN5_SYNTHB4_PAL_DTEST0_GET(x)                                         (((x) & CHN5_SYNTHB4_PAL_DTEST0_MASK) >> CHN5_SYNTHB4_PAL_DTEST0_LSB)
#define CHN5_SYNTHB4_PAL_DTEST0_SET(x)                                         (((0 | (x)) << CHN5_SYNTHB4_PAL_DTEST0_LSB) & CHN5_SYNTHB4_PAL_DTEST0_MASK)
#define CHN5_SYNTHB4_PAL_DTEST0_RESET                                          0x0
#define CHN5_SYNTHB4_ADDRESS                                                   (0x10 + __CHN5_SYN_1_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTHB4_RSTMASK                                                   0xffffffff
#define CHN5_SYNTHB4_RESET                                                     0x0

// 0x14 (CHN5_SYNTHB5)
#define CHN5_SYNTHB5_LO_DIST_THRSH1_LSB                                        27
#define CHN5_SYNTHB5_LO_DIST_THRSH1_MSB                                        31
#define CHN5_SYNTHB5_LO_DIST_THRSH1_MASK                                       0xf8000000
#define CHN5_SYNTHB5_LO_DIST_THRSH1_GET(x)                                     (((x) & CHN5_SYNTHB5_LO_DIST_THRSH1_MASK) >> CHN5_SYNTHB5_LO_DIST_THRSH1_LSB)
#define CHN5_SYNTHB5_LO_DIST_THRSH1_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB5_LO_DIST_THRSH1_LSB) & CHN5_SYNTHB5_LO_DIST_THRSH1_MASK)
#define CHN5_SYNTHB5_LO_DIST_THRSH1_RESET                                      0x3
#define CHN5_SYNTHB5_LO_DIST_THRSH2_LSB                                        22
#define CHN5_SYNTHB5_LO_DIST_THRSH2_MSB                                        26
#define CHN5_SYNTHB5_LO_DIST_THRSH2_MASK                                       0x7c00000
#define CHN5_SYNTHB5_LO_DIST_THRSH2_GET(x)                                     (((x) & CHN5_SYNTHB5_LO_DIST_THRSH2_MASK) >> CHN5_SYNTHB5_LO_DIST_THRSH2_LSB)
#define CHN5_SYNTHB5_LO_DIST_THRSH2_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB5_LO_DIST_THRSH2_LSB) & CHN5_SYNTHB5_LO_DIST_THRSH2_MASK)
#define CHN5_SYNTHB5_LO_DIST_THRSH2_RESET                                      0x8
#define CHN5_SYNTHB5_LO_DIST_THRSH3_LSB                                        17
#define CHN5_SYNTHB5_LO_DIST_THRSH3_MSB                                        21
#define CHN5_SYNTHB5_LO_DIST_THRSH3_MASK                                       0x3e0000
#define CHN5_SYNTHB5_LO_DIST_THRSH3_GET(x)                                     (((x) & CHN5_SYNTHB5_LO_DIST_THRSH3_MASK) >> CHN5_SYNTHB5_LO_DIST_THRSH3_LSB)
#define CHN5_SYNTHB5_LO_DIST_THRSH3_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB5_LO_DIST_THRSH3_LSB) & CHN5_SYNTHB5_LO_DIST_THRSH3_MASK)
#define CHN5_SYNTHB5_LO_DIST_THRSH3_RESET                                      0xd
#define CHN5_SYNTHB5_LO_DIST_THRSH4_LSB                                        12
#define CHN5_SYNTHB5_LO_DIST_THRSH4_MSB                                        16
#define CHN5_SYNTHB5_LO_DIST_THRSH4_MASK                                       0x1f000
#define CHN5_SYNTHB5_LO_DIST_THRSH4_GET(x)                                     (((x) & CHN5_SYNTHB5_LO_DIST_THRSH4_MASK) >> CHN5_SYNTHB5_LO_DIST_THRSH4_LSB)
#define CHN5_SYNTHB5_LO_DIST_THRSH4_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB5_LO_DIST_THRSH4_LSB) & CHN5_SYNTHB5_LO_DIST_THRSH4_MASK)
#define CHN5_SYNTHB5_LO_DIST_THRSH4_RESET                                      0x13
#define CHN5_SYNTHB5_LO_DIST_THRSH5_LSB                                        7
#define CHN5_SYNTHB5_LO_DIST_THRSH5_MSB                                        11
#define CHN5_SYNTHB5_LO_DIST_THRSH5_MASK                                       0xf80
#define CHN5_SYNTHB5_LO_DIST_THRSH5_GET(x)                                     (((x) & CHN5_SYNTHB5_LO_DIST_THRSH5_MASK) >> CHN5_SYNTHB5_LO_DIST_THRSH5_LSB)
#define CHN5_SYNTHB5_LO_DIST_THRSH5_SET(x)                                     (((0 | (x)) << CHN5_SYNTHB5_LO_DIST_THRSH5_LSB) & CHN5_SYNTHB5_LO_DIST_THRSH5_MASK)
#define CHN5_SYNTHB5_LO_DIST_THRSH5_RESET                                      0x19
#define CHN5_SYNTHB5_LO_CHAIN_EN_OVR_LSB                                       4
#define CHN5_SYNTHB5_LO_CHAIN_EN_OVR_MSB                                       6
#define CHN5_SYNTHB5_LO_CHAIN_EN_OVR_MASK                                      0x70
#define CHN5_SYNTHB5_LO_CHAIN_EN_OVR_GET(x)                                    (((x) & CHN5_SYNTHB5_LO_CHAIN_EN_OVR_MASK) >> CHN5_SYNTHB5_LO_CHAIN_EN_OVR_LSB)
#define CHN5_SYNTHB5_LO_CHAIN_EN_OVR_SET(x)                                    (((0 | (x)) << CHN5_SYNTHB5_LO_CHAIN_EN_OVR_LSB) & CHN5_SYNTHB5_LO_CHAIN_EN_OVR_MASK)
#define CHN5_SYNTHB5_LO_CHAIN_EN_OVR_RESET                                     0x0
#define CHN5_SYNTHB5_SYNTHON_OVR_LSB                                           2
#define CHN5_SYNTHB5_SYNTHON_OVR_MSB                                           3
#define CHN5_SYNTHB5_SYNTHON_OVR_MASK                                          0xc
#define CHN5_SYNTHB5_SYNTHON_OVR_GET(x)                                        (((x) & CHN5_SYNTHB5_SYNTHON_OVR_MASK) >> CHN5_SYNTHB5_SYNTHON_OVR_LSB)
#define CHN5_SYNTHB5_SYNTHON_OVR_SET(x)                                        (((0 | (x)) << CHN5_SYNTHB5_SYNTHON_OVR_LSB) & CHN5_SYNTHB5_SYNTHON_OVR_MASK)
#define CHN5_SYNTHB5_SYNTHON_OVR_RESET                                         0x0
#define CHN5_SYNTHB5_XO_DOUBLE_LSB                                             1
#define CHN5_SYNTHB5_XO_DOUBLE_MSB                                             1
#define CHN5_SYNTHB5_XO_DOUBLE_MASK                                            0x2
#define CHN5_SYNTHB5_XO_DOUBLE_GET(x)                                          (((x) & CHN5_SYNTHB5_XO_DOUBLE_MASK) >> CHN5_SYNTHB5_XO_DOUBLE_LSB)
#define CHN5_SYNTHB5_XO_DOUBLE_SET(x)                                          (((0 | (x)) << CHN5_SYNTHB5_XO_DOUBLE_LSB) & CHN5_SYNTHB5_XO_DOUBLE_MASK)
#define CHN5_SYNTHB5_XO_DOUBLE_RESET                                           0x1
#define CHN5_SYNTHB5_RESERVED_LSB                                              0
#define CHN5_SYNTHB5_RESERVED_MSB                                              0
#define CHN5_SYNTHB5_RESERVED_MASK                                             0x1
#define CHN5_SYNTHB5_RESERVED_GET(x)                                           (((x) & CHN5_SYNTHB5_RESERVED_MASK) >> CHN5_SYNTHB5_RESERVED_LSB)
#define CHN5_SYNTHB5_RESERVED_SET(x)                                           (((0 | (x)) << CHN5_SYNTHB5_RESERVED_LSB) & CHN5_SYNTHB5_RESERVED_MASK)
#define CHN5_SYNTHB5_RESERVED_RESET                                            0x0
#define CHN5_SYNTHB5_ADDRESS                                                   (0x14 + __CHN5_SYN_1_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTHB5_RSTMASK                                                   0xffffffff
#define CHN5_SYNTHB5_RESET                                                     0x1a1b3c82

// 0x18 (CHN5_SYNTHB6)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH1_LSB                                       27
#define CHN5_SYNTHB6_PA_CTUNE_THRSH1_MSB                                       31
#define CHN5_SYNTHB6_PA_CTUNE_THRSH1_MASK                                      0xf8000000
#define CHN5_SYNTHB6_PA_CTUNE_THRSH1_GET(x)                                    (((x) & CHN5_SYNTHB6_PA_CTUNE_THRSH1_MASK) >> CHN5_SYNTHB6_PA_CTUNE_THRSH1_LSB)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH1_SET(x)                                    (((0 | (x)) << CHN5_SYNTHB6_PA_CTUNE_THRSH1_LSB) & CHN5_SYNTHB6_PA_CTUNE_THRSH1_MASK)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH1_RESET                                     0x9
#define CHN5_SYNTHB6_PA_CTUNE_THRSH2_LSB                                       22
#define CHN5_SYNTHB6_PA_CTUNE_THRSH2_MSB                                       26
#define CHN5_SYNTHB6_PA_CTUNE_THRSH2_MASK                                      0x7c00000
#define CHN5_SYNTHB6_PA_CTUNE_THRSH2_GET(x)                                    (((x) & CHN5_SYNTHB6_PA_CTUNE_THRSH2_MASK) >> CHN5_SYNTHB6_PA_CTUNE_THRSH2_LSB)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH2_SET(x)                                    (((0 | (x)) << CHN5_SYNTHB6_PA_CTUNE_THRSH2_LSB) & CHN5_SYNTHB6_PA_CTUNE_THRSH2_MASK)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH2_RESET                                     0xb
#define CHN5_SYNTHB6_PA_CTUNE_THRSH3_LSB                                       17
#define CHN5_SYNTHB6_PA_CTUNE_THRSH3_MSB                                       21
#define CHN5_SYNTHB6_PA_CTUNE_THRSH3_MASK                                      0x3e0000
#define CHN5_SYNTHB6_PA_CTUNE_THRSH3_GET(x)                                    (((x) & CHN5_SYNTHB6_PA_CTUNE_THRSH3_MASK) >> CHN5_SYNTHB6_PA_CTUNE_THRSH3_LSB)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH3_SET(x)                                    (((0 | (x)) << CHN5_SYNTHB6_PA_CTUNE_THRSH3_LSB) & CHN5_SYNTHB6_PA_CTUNE_THRSH3_MASK)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH3_RESET                                     0xe
#define CHN5_SYNTHB6_PA_CTUNE_THRSH4_LSB                                       12
#define CHN5_SYNTHB6_PA_CTUNE_THRSH4_MSB                                       16
#define CHN5_SYNTHB6_PA_CTUNE_THRSH4_MASK                                      0x1f000
#define CHN5_SYNTHB6_PA_CTUNE_THRSH4_GET(x)                                    (((x) & CHN5_SYNTHB6_PA_CTUNE_THRSH4_MASK) >> CHN5_SYNTHB6_PA_CTUNE_THRSH4_LSB)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH4_SET(x)                                    (((0 | (x)) << CHN5_SYNTHB6_PA_CTUNE_THRSH4_LSB) & CHN5_SYNTHB6_PA_CTUNE_THRSH4_MASK)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH4_RESET                                     0x12
#define CHN5_SYNTHB6_PA_CTUNE_THRSH5_LSB                                       7
#define CHN5_SYNTHB6_PA_CTUNE_THRSH5_MSB                                       11
#define CHN5_SYNTHB6_PA_CTUNE_THRSH5_MASK                                      0xf80
#define CHN5_SYNTHB6_PA_CTUNE_THRSH5_GET(x)                                    (((x) & CHN5_SYNTHB6_PA_CTUNE_THRSH5_MASK) >> CHN5_SYNTHB6_PA_CTUNE_THRSH5_LSB)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH5_SET(x)                                    (((0 | (x)) << CHN5_SYNTHB6_PA_CTUNE_THRSH5_LSB) & CHN5_SYNTHB6_PA_CTUNE_THRSH5_MASK)
#define CHN5_SYNTHB6_PA_CTUNE_THRSH5_RESET                                     0x16
#define CHN5_SYNTHB6_RESERVED_LSB                                              0
#define CHN5_SYNTHB6_RESERVED_MSB                                              6
#define CHN5_SYNTHB6_RESERVED_MASK                                             0x7f
#define CHN5_SYNTHB6_RESERVED_GET(x)                                           (((x) & CHN5_SYNTHB6_RESERVED_MASK) >> CHN5_SYNTHB6_RESERVED_LSB)
#define CHN5_SYNTHB6_RESERVED_SET(x)                                           (((0 | (x)) << CHN5_SYNTHB6_RESERVED_LSB) & CHN5_SYNTHB6_RESERVED_MASK)
#define CHN5_SYNTHB6_RESERVED_RESET                                            0x0
#define CHN5_SYNTHB6_ADDRESS                                                   (0x18 + __CHN5_SYN_1_REG_CSR_BASE_ADDRESS)
#define CHN5_SYNTHB6_RSTMASK                                                   0xffffffff
#define CHN5_SYNTHB6_RESET                                                     0x4add2b00



#endif /* _CHN5_SYN_1_REG_CSR_H_ */
