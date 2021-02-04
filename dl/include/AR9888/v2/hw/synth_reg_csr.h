//                                                                             
// File:       ./synth_reg_csr.vrh                                             
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:48:09 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             synth_reg_csr.rdl                                               
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/synth_reg.rdl
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


#ifndef _SYNTH_REG_CSR_H_
#define _SYNTH_REG_CSR_H_
// 0x0000 (SYNTH1)
#define SYNTH1_PWD_BIAS_MSB                                          31
#define SYNTH1_PWD_BIAS_LSB                                          31
#define SYNTH1_PWD_BIAS_MASK                                         0x80000000
#define SYNTH1_PWD_BIAS_GET(x)                                       (((x) & SYNTH1_PWD_BIAS_MASK) >> SYNTH1_PWD_BIAS_LSB)
#define SYNTH1_PWD_BIAS_SET(x)                                       (((0 | (x)) << SYNTH1_PWD_BIAS_LSB) & SYNTH1_PWD_BIAS_MASK)
#define SYNTH1_PWD_BIAS_RESET                                        0
#define SYNTH1_PWD_CP_MSB                                            30
#define SYNTH1_PWD_CP_LSB                                            30
#define SYNTH1_PWD_CP_MASK                                           0x40000000
#define SYNTH1_PWD_CP_GET(x)                                         (((x) & SYNTH1_PWD_CP_MASK) >> SYNTH1_PWD_CP_LSB)
#define SYNTH1_PWD_CP_SET(x)                                         (((0 | (x)) << SYNTH1_PWD_CP_LSB) & SYNTH1_PWD_CP_MASK)
#define SYNTH1_PWD_CP_RESET                                          0
#define SYNTH1_PWD_VCMON_MSB                                         29
#define SYNTH1_PWD_VCMON_LSB                                         29
#define SYNTH1_PWD_VCMON_MASK                                        0x20000000
#define SYNTH1_PWD_VCMON_GET(x)                                      (((x) & SYNTH1_PWD_VCMON_MASK) >> SYNTH1_PWD_VCMON_LSB)
#define SYNTH1_PWD_VCMON_SET(x)                                      (((0 | (x)) << SYNTH1_PWD_VCMON_LSB) & SYNTH1_PWD_VCMON_MASK)
#define SYNTH1_PWD_VCMON_RESET                                       0
#define SYNTH1_PWD_VCO_MSB                                           28
#define SYNTH1_PWD_VCO_LSB                                           28
#define SYNTH1_PWD_VCO_MASK                                          0x10000000
#define SYNTH1_PWD_VCO_GET(x)                                        (((x) & SYNTH1_PWD_VCO_MASK) >> SYNTH1_PWD_VCO_LSB)
#define SYNTH1_PWD_VCO_SET(x)                                        (((0 | (x)) << SYNTH1_PWD_VCO_LSB) & SYNTH1_PWD_VCO_MASK)
#define SYNTH1_PWD_VCO_RESET                                         0
#define SYNTH1_PWD_PRESC_MSB                                         27
#define SYNTH1_PWD_PRESC_LSB                                         27
#define SYNTH1_PWD_PRESC_MASK                                        0x08000000
#define SYNTH1_PWD_PRESC_GET(x)                                      (((x) & SYNTH1_PWD_PRESC_MASK) >> SYNTH1_PWD_PRESC_LSB)
#define SYNTH1_PWD_PRESC_SET(x)                                      (((0 | (x)) << SYNTH1_PWD_PRESC_LSB) & SYNTH1_PWD_PRESC_MASK)
#define SYNTH1_PWD_PRESC_RESET                                       0
#define SYNTH1_PWD_LOBUFA2G_MSB                                      26
#define SYNTH1_PWD_LOBUFA2G_LSB                                      26
#define SYNTH1_PWD_LOBUFA2G_MASK                                     0x04000000
#define SYNTH1_PWD_LOBUFA2G_GET(x)                                   (((x) & SYNTH1_PWD_LOBUFA2G_MASK) >> SYNTH1_PWD_LOBUFA2G_LSB)
#define SYNTH1_PWD_LOBUFA2G_SET(x)                                   (((0 | (x)) << SYNTH1_PWD_LOBUFA2G_LSB) & SYNTH1_PWD_LOBUFA2G_MASK)
#define SYNTH1_PWD_LOBUFA2G_RESET                                    0
#define SYNTH1_PWD_LOBUFB2G_MSB                                      25
#define SYNTH1_PWD_LOBUFB2G_LSB                                      25
#define SYNTH1_PWD_LOBUFB2G_MASK                                     0x02000000
#define SYNTH1_PWD_LOBUFB2G_GET(x)                                   (((x) & SYNTH1_PWD_LOBUFB2G_MASK) >> SYNTH1_PWD_LOBUFB2G_LSB)
#define SYNTH1_PWD_LOBUFB2G_SET(x)                                   (((0 | (x)) << SYNTH1_PWD_LOBUFB2G_LSB) & SYNTH1_PWD_LOBUFB2G_MASK)
#define SYNTH1_PWD_LOBUFB2G_RESET                                    0
#define SYNTH1_SPARE1A_MSB                                           24
#define SYNTH1_SPARE1A_LSB                                           20
#define SYNTH1_SPARE1A_MASK                                          0x01f00000
#define SYNTH1_SPARE1A_GET(x)                                        (((x) & SYNTH1_SPARE1A_MASK) >> SYNTH1_SPARE1A_LSB)
#define SYNTH1_SPARE1A_SET(x)                                        (((0 | (x)) << SYNTH1_SPARE1A_LSB) & SYNTH1_SPARE1A_MASK)
#define SYNTH1_SPARE1A_RESET                                         0
#define SYNTH1_PWD_LODIV_MSB                                         19
#define SYNTH1_PWD_LODIV_LSB                                         19
#define SYNTH1_PWD_LODIV_MASK                                        0x00080000
#define SYNTH1_PWD_LODIV_GET(x)                                      (((x) & SYNTH1_PWD_LODIV_MASK) >> SYNTH1_PWD_LODIV_LSB)
#define SYNTH1_PWD_LODIV_SET(x)                                      (((0 | (x)) << SYNTH1_PWD_LODIV_LSB) & SYNTH1_PWD_LODIV_MASK)
#define SYNTH1_PWD_LODIV_RESET                                       0
#define SYNTH1_PWD_LOMIX_MSB                                         18
#define SYNTH1_PWD_LOMIX_LSB                                         18
#define SYNTH1_PWD_LOMIX_MASK                                        0x00040000
#define SYNTH1_PWD_LOMIX_GET(x)                                      (((x) & SYNTH1_PWD_LOMIX_MASK) >> SYNTH1_PWD_LOMIX_LSB)
#define SYNTH1_PWD_LOMIX_SET(x)                                      (((0 | (x)) << SYNTH1_PWD_LOMIX_LSB) & SYNTH1_PWD_LOMIX_MASK)
#define SYNTH1_PWD_LOMIX_RESET                                       0
#define SYNTH1_SEL_VCMON_LOGEN_ABUS_MSB                              17
#define SYNTH1_SEL_VCMON_LOGEN_ABUS_LSB                              17
#define SYNTH1_SEL_VCMON_LOGEN_ABUS_MASK                             0x00020000
#define SYNTH1_SEL_VCMON_LOGEN_ABUS_GET(x)                           (((x) & SYNTH1_SEL_VCMON_LOGEN_ABUS_MASK) >> SYNTH1_SEL_VCMON_LOGEN_ABUS_LSB)
#define SYNTH1_SEL_VCMON_LOGEN_ABUS_SET(x)                           (((0 | (x)) << SYNTH1_SEL_VCMON_LOGEN_ABUS_LSB) & SYNTH1_SEL_VCMON_LOGEN_ABUS_MASK)
#define SYNTH1_SEL_VCMON_LOGEN_ABUS_RESET                            0
#define SYNTH1_PWUP_LOGEN_PD_MSB                                     16
#define SYNTH1_PWUP_LOGEN_PD_LSB                                     14
#define SYNTH1_PWUP_LOGEN_PD_MASK                                    0x0001c000
#define SYNTH1_PWUP_LOGEN_PD_GET(x)                                  (((x) & SYNTH1_PWUP_LOGEN_PD_MASK) >> SYNTH1_PWUP_LOGEN_PD_LSB)
#define SYNTH1_PWUP_LOGEN_PD_SET(x)                                  (((0 | (x)) << SYNTH1_PWUP_LOGEN_PD_LSB) & SYNTH1_PWUP_LOGEN_PD_MASK)
#define SYNTH1_PWUP_LOGEN_PD_RESET                                   0
#define SYNTH1_MONITOR_DLL_MSB                                       13
#define SYNTH1_MONITOR_DLL_LSB                                       12
#define SYNTH1_MONITOR_DLL_MASK                                      0x00003000
#define SYNTH1_MONITOR_DLL_GET(x)                                    (((x) & SYNTH1_MONITOR_DLL_MASK) >> SYNTH1_MONITOR_DLL_LSB)
#define SYNTH1_MONITOR_DLL_SET(x)                                    (((0 | (x)) << SYNTH1_MONITOR_DLL_LSB) & SYNTH1_MONITOR_DLL_MASK)
#define SYNTH1_MONITOR_DLL_RESET                                     0
#define SYNTH1_MONITOR_FB_MSB                                        11
#define SYNTH1_MONITOR_FB_LSB                                        11
#define SYNTH1_MONITOR_FB_MASK                                       0x00000800
#define SYNTH1_MONITOR_FB_GET(x)                                     (((x) & SYNTH1_MONITOR_FB_MASK) >> SYNTH1_MONITOR_FB_LSB)
#define SYNTH1_MONITOR_FB_SET(x)                                     (((0 | (x)) << SYNTH1_MONITOR_FB_LSB) & SYNTH1_MONITOR_FB_MASK)
#define SYNTH1_MONITOR_FB_RESET                                      0
#define SYNTH1_MONITOR_REF_MSB                                       10
#define SYNTH1_MONITOR_REF_LSB                                       10
#define SYNTH1_MONITOR_REF_MASK                                      0x00000400
#define SYNTH1_MONITOR_REF_GET(x)                                    (((x) & SYNTH1_MONITOR_REF_MASK) >> SYNTH1_MONITOR_REF_LSB)
#define SYNTH1_MONITOR_REF_SET(x)                                    (((0 | (x)) << SYNTH1_MONITOR_REF_LSB) & SYNTH1_MONITOR_REF_MASK)
#define SYNTH1_MONITOR_REF_RESET                                     0
#define SYNTH1_MONITOR_FB_DIV2_MSB                                   9
#define SYNTH1_MONITOR_FB_DIV2_LSB                                   9
#define SYNTH1_MONITOR_FB_DIV2_MASK                                  0x00000200
#define SYNTH1_MONITOR_FB_DIV2_GET(x)                                (((x) & SYNTH1_MONITOR_FB_DIV2_MASK) >> SYNTH1_MONITOR_FB_DIV2_LSB)
#define SYNTH1_MONITOR_FB_DIV2_SET(x)                                (((0 | (x)) << SYNTH1_MONITOR_FB_DIV2_LSB) & SYNTH1_MONITOR_FB_DIV2_MASK)
#define SYNTH1_MONITOR_FB_DIV2_RESET                                 0
#define SYNTH1_MONITOR_VC2HIGH_MSB                                   8
#define SYNTH1_MONITOR_VC2HIGH_LSB                                   8
#define SYNTH1_MONITOR_VC2HIGH_MASK                                  0x00000100
#define SYNTH1_MONITOR_VC2HIGH_GET(x)                                (((x) & SYNTH1_MONITOR_VC2HIGH_MASK) >> SYNTH1_MONITOR_VC2HIGH_LSB)
#define SYNTH1_MONITOR_VC2HIGH_SET(x)                                (((0 | (x)) << SYNTH1_MONITOR_VC2HIGH_LSB) & SYNTH1_MONITOR_VC2HIGH_MASK)
#define SYNTH1_MONITOR_VC2HIGH_RESET                                 0
#define SYNTH1_MONITOR_VC2LOW_MSB                                    7
#define SYNTH1_MONITOR_VC2LOW_LSB                                    7
#define SYNTH1_MONITOR_VC2LOW_MASK                                   0x00000080
#define SYNTH1_MONITOR_VC2LOW_GET(x)                                 (((x) & SYNTH1_MONITOR_VC2LOW_MASK) >> SYNTH1_MONITOR_VC2LOW_LSB)
#define SYNTH1_MONITOR_VC2LOW_SET(x)                                 (((0 | (x)) << SYNTH1_MONITOR_VC2LOW_LSB) & SYNTH1_MONITOR_VC2LOW_MASK)
#define SYNTH1_MONITOR_VC2LOW_RESET                                  0
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_MSB                             6
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_LSB                             6
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_MASK                            0x00000040
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_GET(x)                          (((x) & SYNTH1_MONITOR_SYNTHLOCKVCOK_MASK) >> SYNTH1_MONITOR_SYNTHLOCKVCOK_LSB)
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_SET(x)                          (((0 | (x)) << SYNTH1_MONITOR_SYNTHLOCKVCOK_LSB) & SYNTH1_MONITOR_SYNTHLOCKVCOK_MASK)
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_RESET                           0
#define SYNTH1_SEL_VCOABUS_MSB                                       5
#define SYNTH1_SEL_VCOABUS_LSB                                       3
#define SYNTH1_SEL_VCOABUS_MASK                                      0x00000038
#define SYNTH1_SEL_VCOABUS_GET(x)                                    (((x) & SYNTH1_SEL_VCOABUS_MASK) >> SYNTH1_SEL_VCOABUS_LSB)
#define SYNTH1_SEL_VCOABUS_SET(x)                                    (((0 | (x)) << SYNTH1_SEL_VCOABUS_LSB) & SYNTH1_SEL_VCOABUS_MASK)
#define SYNTH1_SEL_VCOABUS_RESET                                     0
#define SYNTH1_SEL_VCMONABUS_MSB                                     2
#define SYNTH1_SEL_VCMONABUS_LSB                                     0
#define SYNTH1_SEL_VCMONABUS_MASK                                    0x00000007
#define SYNTH1_SEL_VCMONABUS_GET(x)                                  (((x) & SYNTH1_SEL_VCMONABUS_MASK) >> SYNTH1_SEL_VCMONABUS_LSB)
#define SYNTH1_SEL_VCMONABUS_SET(x)                                  (((0 | (x)) << SYNTH1_SEL_VCMONABUS_LSB) & SYNTH1_SEL_VCMONABUS_MASK)
#define SYNTH1_SEL_VCMONABUS_RESET                                   0
#define SYNTH1_ADDRESS                                               0x0000
#define SYNTH1_HW_MASK                                               0xffffffff
#define SYNTH1_SW_MASK                                               0xffffffff
#define SYNTH1_HW_WRITE_MASK                                         0x00000000
#define SYNTH1_SW_WRITE_MASK                                         0xffffffff
#define SYNTH1_RSTMASK                                               0xffffffff
#define SYNTH1_RESET                                                 0x00000000

// 0x0004 (SYNTH2)
#define SYNTH2_VC_CAL_REF_MSB                                        31
#define SYNTH2_VC_CAL_REF_LSB                                        29
#define SYNTH2_VC_CAL_REF_MASK                                       0xe0000000
#define SYNTH2_VC_CAL_REF_GET(x)                                     (((x) & SYNTH2_VC_CAL_REF_MASK) >> SYNTH2_VC_CAL_REF_LSB)
#define SYNTH2_VC_CAL_REF_SET(x)                                     (((0 | (x)) << SYNTH2_VC_CAL_REF_LSB) & SYNTH2_VC_CAL_REF_MASK)
#define SYNTH2_VC_CAL_REF_RESET                                      4
#define SYNTH2_VC_HI_REF_MSB                                         28
#define SYNTH2_VC_HI_REF_LSB                                         26
#define SYNTH2_VC_HI_REF_MASK                                        0x1c000000
#define SYNTH2_VC_HI_REF_GET(x)                                      (((x) & SYNTH2_VC_HI_REF_MASK) >> SYNTH2_VC_HI_REF_LSB)
#define SYNTH2_VC_HI_REF_SET(x)                                      (((0 | (x)) << SYNTH2_VC_HI_REF_LSB) & SYNTH2_VC_HI_REF_MASK)
#define SYNTH2_VC_HI_REF_RESET                                       4
#define SYNTH2_VC_MID_REF_MSB                                        25
#define SYNTH2_VC_MID_REF_LSB                                        23
#define SYNTH2_VC_MID_REF_MASK                                       0x03800000
#define SYNTH2_VC_MID_REF_GET(x)                                     (((x) & SYNTH2_VC_MID_REF_MASK) >> SYNTH2_VC_MID_REF_LSB)
#define SYNTH2_VC_MID_REF_SET(x)                                     (((0 | (x)) << SYNTH2_VC_MID_REF_LSB) & SYNTH2_VC_MID_REF_MASK)
#define SYNTH2_VC_MID_REF_RESET                                      4
#define SYNTH2_VC_LOW_REF_MSB                                        22
#define SYNTH2_VC_LOW_REF_LSB                                        20
#define SYNTH2_VC_LOW_REF_MASK                                       0x00700000
#define SYNTH2_VC_LOW_REF_GET(x)                                     (((x) & SYNTH2_VC_LOW_REF_MASK) >> SYNTH2_VC_LOW_REF_LSB)
#define SYNTH2_VC_LOW_REF_SET(x)                                     (((0 | (x)) << SYNTH2_VC_LOW_REF_LSB) & SYNTH2_VC_LOW_REF_MASK)
#define SYNTH2_VC_LOW_REF_RESET                                      4
#define SYNTH2_BIT_INDEX_SAVE_VCO_CAP_MSB                            19
#define SYNTH2_BIT_INDEX_SAVE_VCO_CAP_LSB                            16
#define SYNTH2_BIT_INDEX_SAVE_VCO_CAP_MASK                           0x000f0000
#define SYNTH2_BIT_INDEX_SAVE_VCO_CAP_GET(x)                         (((x) & SYNTH2_BIT_INDEX_SAVE_VCO_CAP_MASK) >> SYNTH2_BIT_INDEX_SAVE_VCO_CAP_LSB)
#define SYNTH2_BIT_INDEX_SAVE_VCO_CAP_SET(x)                         (((0 | (x)) << SYNTH2_BIT_INDEX_SAVE_VCO_CAP_LSB) & SYNTH2_BIT_INDEX_SAVE_VCO_CAP_MASK)
#define SYNTH2_BIT_INDEX_SAVE_VCO_CAP_RESET                          0
#define SYNTH2_MODULATELSB_MSB                                       15
#define SYNTH2_MODULATELSB_LSB                                       15
#define SYNTH2_MODULATELSB_MASK                                      0x00008000
#define SYNTH2_MODULATELSB_GET(x)                                    (((x) & SYNTH2_MODULATELSB_MASK) >> SYNTH2_MODULATELSB_LSB)
#define SYNTH2_MODULATELSB_SET(x)                                    (((0 | (x)) << SYNTH2_MODULATELSB_LSB) & SYNTH2_MODULATELSB_MASK)
#define SYNTH2_MODULATELSB_RESET                                     0
#define SYNTH2_ENINTERPOLATION_MSB                                   14
#define SYNTH2_ENINTERPOLATION_LSB                                   14
#define SYNTH2_ENINTERPOLATION_MASK                                  0x00004000
#define SYNTH2_ENINTERPOLATION_GET(x)                                (((x) & SYNTH2_ENINTERPOLATION_MASK) >> SYNTH2_ENINTERPOLATION_LSB)
#define SYNTH2_ENINTERPOLATION_SET(x)                                (((0 | (x)) << SYNTH2_ENINTERPOLATION_LSB) & SYNTH2_ENINTERPOLATION_MASK)
#define SYNTH2_ENINTERPOLATION_RESET                                 0
#define SYNTH2_INTERP_ENABLE_VCO_CAP_CHECK_MSB                       13
#define SYNTH2_INTERP_ENABLE_VCO_CAP_CHECK_LSB                       13
#define SYNTH2_INTERP_ENABLE_VCO_CAP_CHECK_MASK                      0x00002000
#define SYNTH2_INTERP_ENABLE_VCO_CAP_CHECK_GET(x)                    (((x) & SYNTH2_INTERP_ENABLE_VCO_CAP_CHECK_MASK) >> SYNTH2_INTERP_ENABLE_VCO_CAP_CHECK_LSB)
#define SYNTH2_INTERP_ENABLE_VCO_CAP_CHECK_SET(x)                    (((0 | (x)) << SYNTH2_INTERP_ENABLE_VCO_CAP_CHECK_LSB) & SYNTH2_INTERP_ENABLE_VCO_CAP_CHECK_MASK)
#define SYNTH2_INTERP_ENABLE_VCO_CAP_CHECK_RESET                     1
#define SYNTH2_RESERVED2A_MSB                                        12
#define SYNTH2_RESERVED2A_LSB                                        11
#define SYNTH2_RESERVED2A_MASK                                       0x00001800
#define SYNTH2_RESERVED2A_GET(x)                                     (((x) & SYNTH2_RESERVED2A_MASK) >> SYNTH2_RESERVED2A_LSB)
#define SYNTH2_RESERVED2A_SET(x)                                     (((0 | (x)) << SYNTH2_RESERVED2A_LSB) & SYNTH2_RESERVED2A_MASK)
#define SYNTH2_RESERVED2A_RESET                                      0
#define SYNTH2_CENTER_VC_BIN_MSB                                     10
#define SYNTH2_CENTER_VC_BIN_LSB                                     10
#define SYNTH2_CENTER_VC_BIN_MASK                                    0x00000400
#define SYNTH2_CENTER_VC_BIN_GET(x)                                  (((x) & SYNTH2_CENTER_VC_BIN_MASK) >> SYNTH2_CENTER_VC_BIN_LSB)
#define SYNTH2_CENTER_VC_BIN_SET(x)                                  (((0 | (x)) << SYNTH2_CENTER_VC_BIN_LSB) & SYNTH2_CENTER_VC_BIN_MASK)
#define SYNTH2_CENTER_VC_BIN_RESET                                   0
#define SYNTH2_CENTER_VC_MON_MSB                                     9
#define SYNTH2_CENTER_VC_MON_LSB                                     9
#define SYNTH2_CENTER_VC_MON_MASK                                    0x00000200
#define SYNTH2_CENTER_VC_MON_GET(x)                                  (((x) & SYNTH2_CENTER_VC_MON_MASK) >> SYNTH2_CENTER_VC_MON_LSB)
#define SYNTH2_CENTER_VC_MON_SET(x)                                  (((0 | (x)) << SYNTH2_CENTER_VC_MON_LSB) & SYNTH2_CENTER_VC_MON_MASK)
#define SYNTH2_CENTER_VC_MON_RESET                                   1
#define SYNTH2_SKIP_MON_ALIGN_MSB                                    8
#define SYNTH2_SKIP_MON_ALIGN_LSB                                    8
#define SYNTH2_SKIP_MON_ALIGN_MASK                                   0x00000100
#define SYNTH2_SKIP_MON_ALIGN_GET(x)                                 (((x) & SYNTH2_SKIP_MON_ALIGN_MASK) >> SYNTH2_SKIP_MON_ALIGN_LSB)
#define SYNTH2_SKIP_MON_ALIGN_SET(x)                                 (((0 | (x)) << SYNTH2_SKIP_MON_ALIGN_LSB) & SYNTH2_SKIP_MON_ALIGN_MASK)
#define SYNTH2_SKIP_MON_ALIGN_RESET                                  1
#define SYNTH2_LIN_SEARCH_STEP_SIZE_MSB                              7
#define SYNTH2_LIN_SEARCH_STEP_SIZE_LSB                              5
#define SYNTH2_LIN_SEARCH_STEP_SIZE_MASK                             0x000000e0
#define SYNTH2_LIN_SEARCH_STEP_SIZE_GET(x)                           (((x) & SYNTH2_LIN_SEARCH_STEP_SIZE_MASK) >> SYNTH2_LIN_SEARCH_STEP_SIZE_LSB)
#define SYNTH2_LIN_SEARCH_STEP_SIZE_SET(x)                           (((0 | (x)) << SYNTH2_LIN_SEARCH_STEP_SIZE_LSB) & SYNTH2_LIN_SEARCH_STEP_SIZE_MASK)
#define SYNTH2_LIN_SEARCH_STEP_SIZE_RESET                            0
#define SYNTH2_SKIPLINCAPSEARCH_MSB                                  4
#define SYNTH2_SKIPLINCAPSEARCH_LSB                                  4
#define SYNTH2_SKIPLINCAPSEARCH_MASK                                 0x00000010
#define SYNTH2_SKIPLINCAPSEARCH_GET(x)                               (((x) & SYNTH2_SKIPLINCAPSEARCH_MASK) >> SYNTH2_SKIPLINCAPSEARCH_LSB)
#define SYNTH2_SKIPLINCAPSEARCH_SET(x)                               (((0 | (x)) << SYNTH2_SKIPLINCAPSEARCH_LSB) & SYNTH2_SKIPLINCAPSEARCH_MASK)
#define SYNTH2_SKIPLINCAPSEARCH_RESET                                1
#define SYNTH2_MAXLINSTEPS_MSB                                       3
#define SYNTH2_MAXLINSTEPS_LSB                                       0
#define SYNTH2_MAXLINSTEPS_MASK                                      0x0000000f
#define SYNTH2_MAXLINSTEPS_GET(x)                                    (((x) & SYNTH2_MAXLINSTEPS_MASK) >> SYNTH2_MAXLINSTEPS_LSB)
#define SYNTH2_MAXLINSTEPS_SET(x)                                    (((0 | (x)) << SYNTH2_MAXLINSTEPS_LSB) & SYNTH2_MAXLINSTEPS_MASK)
#define SYNTH2_MAXLINSTEPS_RESET                                     0
#define SYNTH2_ADDRESS                                               0x0004
#define SYNTH2_HW_MASK                                               0xffffffff
#define SYNTH2_SW_MASK                                               0xffffffff
#define SYNTH2_HW_WRITE_MASK                                         0x00000000
#define SYNTH2_SW_WRITE_MASK                                         0xffffffff
#define SYNTH2_RSTMASK                                               0xffffffff
#define SYNTH2_RESET                                                 0x92402310

// 0x0008 (SYNTH3)
#define SYNTH3_DIS_CLK_XTAL_MSB                                      31
#define SYNTH3_DIS_CLK_XTAL_LSB                                      31
#define SYNTH3_DIS_CLK_XTAL_MASK                                     0x80000000
#define SYNTH3_DIS_CLK_XTAL_GET(x)                                   (((x) & SYNTH3_DIS_CLK_XTAL_MASK) >> SYNTH3_DIS_CLK_XTAL_LSB)
#define SYNTH3_DIS_CLK_XTAL_SET(x)                                   (((0 | (x)) << SYNTH3_DIS_CLK_XTAL_LSB) & SYNTH3_DIS_CLK_XTAL_MASK)
#define SYNTH3_DIS_CLK_XTAL_RESET                                    0
#define SYNTH3_SEL_CLK_DIV2_MSB                                      30
#define SYNTH3_SEL_CLK_DIV2_LSB                                      30
#define SYNTH3_SEL_CLK_DIV2_MASK                                     0x40000000
#define SYNTH3_SEL_CLK_DIV2_GET(x)                                   (((x) & SYNTH3_SEL_CLK_DIV2_MASK) >> SYNTH3_SEL_CLK_DIV2_LSB)
#define SYNTH3_SEL_CLK_DIV2_SET(x)                                   (((0 | (x)) << SYNTH3_SEL_CLK_DIV2_LSB) & SYNTH3_SEL_CLK_DIV2_MASK)
#define SYNTH3_SEL_CLK_DIV2_RESET                                    1
#define SYNTH3_WAIT_SHORTR_PWRUP_MSB                                 29
#define SYNTH3_WAIT_SHORTR_PWRUP_LSB                                 24
#define SYNTH3_WAIT_SHORTR_PWRUP_MASK                                0x3f000000
#define SYNTH3_WAIT_SHORTR_PWRUP_GET(x)                              (((x) & SYNTH3_WAIT_SHORTR_PWRUP_MASK) >> SYNTH3_WAIT_SHORTR_PWRUP_LSB)
#define SYNTH3_WAIT_SHORTR_PWRUP_SET(x)                              (((0 | (x)) << SYNTH3_WAIT_SHORTR_PWRUP_LSB) & SYNTH3_WAIT_SHORTR_PWRUP_MASK)
#define SYNTH3_WAIT_SHORTR_PWRUP_RESET                               31
#define SYNTH3_WAIT_PWRUP_MSB                                        23
#define SYNTH3_WAIT_PWRUP_LSB                                        18
#define SYNTH3_WAIT_PWRUP_MASK                                       0x00fc0000
#define SYNTH3_WAIT_PWRUP_GET(x)                                     (((x) & SYNTH3_WAIT_PWRUP_MASK) >> SYNTH3_WAIT_PWRUP_LSB)
#define SYNTH3_WAIT_PWRUP_SET(x)                                     (((0 | (x)) << SYNTH3_WAIT_PWRUP_LSB) & SYNTH3_WAIT_PWRUP_MASK)
#define SYNTH3_WAIT_PWRUP_RESET                                      31
#define SYNTH3_WAIT_VCO_SETTLE_EXTRA_MSB                             17
#define SYNTH3_WAIT_VCO_SETTLE_EXTRA_LSB                             12
#define SYNTH3_WAIT_VCO_SETTLE_EXTRA_MASK                            0x0003f000
#define SYNTH3_WAIT_VCO_SETTLE_EXTRA_GET(x)                          (((x) & SYNTH3_WAIT_VCO_SETTLE_EXTRA_MASK) >> SYNTH3_WAIT_VCO_SETTLE_EXTRA_LSB)
#define SYNTH3_WAIT_VCO_SETTLE_EXTRA_SET(x)                          (((0 | (x)) << SYNTH3_WAIT_VCO_SETTLE_EXTRA_LSB) & SYNTH3_WAIT_VCO_SETTLE_EXTRA_MASK)
#define SYNTH3_WAIT_VCO_SETTLE_EXTRA_RESET                           2
#define SYNTH3_WAIT_CAL_LIN_MSB                                      11
#define SYNTH3_WAIT_CAL_LIN_LSB                                      6
#define SYNTH3_WAIT_CAL_LIN_MASK                                     0x00000fc0
#define SYNTH3_WAIT_CAL_LIN_GET(x)                                   (((x) & SYNTH3_WAIT_CAL_LIN_MASK) >> SYNTH3_WAIT_CAL_LIN_LSB)
#define SYNTH3_WAIT_CAL_LIN_SET(x)                                   (((0 | (x)) << SYNTH3_WAIT_CAL_LIN_LSB) & SYNTH3_WAIT_CAL_LIN_MASK)
#define SYNTH3_WAIT_CAL_LIN_RESET                                    25
#define SYNTH3_WAIT_VC_CHECK_MSB                                     5
#define SYNTH3_WAIT_VC_CHECK_LSB                                     0
#define SYNTH3_WAIT_VC_CHECK_MASK                                    0x0000003f
#define SYNTH3_WAIT_VC_CHECK_GET(x)                                  (((x) & SYNTH3_WAIT_VC_CHECK_MASK) >> SYNTH3_WAIT_VC_CHECK_LSB)
#define SYNTH3_WAIT_VC_CHECK_SET(x)                                  (((0 | (x)) << SYNTH3_WAIT_VC_CHECK_LSB) & SYNTH3_WAIT_VC_CHECK_MASK)
#define SYNTH3_WAIT_VC_CHECK_RESET                                   5
#define SYNTH3_ADDRESS                                               0x0008
#define SYNTH3_HW_MASK                                               0xffffffff
#define SYNTH3_SW_MASK                                               0xffffffff
#define SYNTH3_HW_WRITE_MASK                                         0x00000000
#define SYNTH3_SW_WRITE_MASK                                         0xffffffff
#define SYNTH3_RSTMASK                                               0xffffffff
#define SYNTH3_RESET                                                 0x5f7c2645

// 0x000c (SYNTH4)
#define SYNTH4_WAIT_PIN_VC_EXTRA_MSB                                 31
#define SYNTH4_WAIT_PIN_VC_EXTRA_LSB                                 28
#define SYNTH4_WAIT_PIN_VC_EXTRA_MASK                                0xf0000000
#define SYNTH4_WAIT_PIN_VC_EXTRA_GET(x)                              (((x) & SYNTH4_WAIT_PIN_VC_EXTRA_MASK) >> SYNTH4_WAIT_PIN_VC_EXTRA_LSB)
#define SYNTH4_WAIT_PIN_VC_EXTRA_SET(x)                              (((0 | (x)) << SYNTH4_WAIT_PIN_VC_EXTRA_LSB) & SYNTH4_WAIT_PIN_VC_EXTRA_MASK)
#define SYNTH4_WAIT_PIN_VC_EXTRA_RESET                               4
#define SYNTH4_XTAL_CLK_DIV2_EN_MSB                                  27
#define SYNTH4_XTAL_CLK_DIV2_EN_LSB                                  27
#define SYNTH4_XTAL_CLK_DIV2_EN_MASK                                 0x08000000
#define SYNTH4_XTAL_CLK_DIV2_EN_GET(x)                               (((x) & SYNTH4_XTAL_CLK_DIV2_EN_MASK) >> SYNTH4_XTAL_CLK_DIV2_EN_LSB)
#define SYNTH4_XTAL_CLK_DIV2_EN_SET(x)                               (((0 | (x)) << SYNTH4_XTAL_CLK_DIV2_EN_LSB) & SYNTH4_XTAL_CLK_DIV2_EN_MASK)
#define SYNTH4_XTAL_CLK_DIV2_EN_RESET                                0
#define SYNTH4_DIS_LOSTVC_MSB                                        26
#define SYNTH4_DIS_LOSTVC_LSB                                        26
#define SYNTH4_DIS_LOSTVC_MASK                                       0x04000000
#define SYNTH4_DIS_LOSTVC_GET(x)                                     (((x) & SYNTH4_DIS_LOSTVC_MASK) >> SYNTH4_DIS_LOSTVC_LSB)
#define SYNTH4_DIS_LOSTVC_SET(x)                                     (((0 | (x)) << SYNTH4_DIS_LOSTVC_LSB) & SYNTH4_DIS_LOSTVC_MASK)
#define SYNTH4_DIS_LOSTVC_RESET                                      0
#define SYNTH4_ALWAYS_SHORTR_MSB                                     25
#define SYNTH4_ALWAYS_SHORTR_LSB                                     25
#define SYNTH4_ALWAYS_SHORTR_MASK                                    0x02000000
#define SYNTH4_ALWAYS_SHORTR_GET(x)                                  (((x) & SYNTH4_ALWAYS_SHORTR_MASK) >> SYNTH4_ALWAYS_SHORTR_LSB)
#define SYNTH4_ALWAYS_SHORTR_SET(x)                                  (((0 | (x)) << SYNTH4_ALWAYS_SHORTR_LSB) & SYNTH4_ALWAYS_SHORTR_MASK)
#define SYNTH4_ALWAYS_SHORTR_RESET                                   0
#define SYNTH4_SHORTR_UNTIL_LOCKED_MSB                               24
#define SYNTH4_SHORTR_UNTIL_LOCKED_LSB                               24
#define SYNTH4_SHORTR_UNTIL_LOCKED_MASK                              0x01000000
#define SYNTH4_SHORTR_UNTIL_LOCKED_GET(x)                            (((x) & SYNTH4_SHORTR_UNTIL_LOCKED_MASK) >> SYNTH4_SHORTR_UNTIL_LOCKED_LSB)
#define SYNTH4_SHORTR_UNTIL_LOCKED_SET(x)                            (((0 | (x)) << SYNTH4_SHORTR_UNTIL_LOCKED_LSB) & SYNTH4_SHORTR_UNTIL_LOCKED_MASK)
#define SYNTH4_SHORTR_UNTIL_LOCKED_RESET                             1
#define SYNTH4_FORCE_PINVC_MSB                                       23
#define SYNTH4_FORCE_PINVC_LSB                                       23
#define SYNTH4_FORCE_PINVC_MASK                                      0x00800000
#define SYNTH4_FORCE_PINVC_GET(x)                                    (((x) & SYNTH4_FORCE_PINVC_MASK) >> SYNTH4_FORCE_PINVC_LSB)
#define SYNTH4_FORCE_PINVC_SET(x)                                    (((0 | (x)) << SYNTH4_FORCE_PINVC_LSB) & SYNTH4_FORCE_PINVC_MASK)
#define SYNTH4_FORCE_PINVC_RESET                                     0
#define SYNTH4_FORCE_VCOCAP_MSB                                      22
#define SYNTH4_FORCE_VCOCAP_LSB                                      22
#define SYNTH4_FORCE_VCOCAP_MASK                                     0x00400000
#define SYNTH4_FORCE_VCOCAP_GET(x)                                   (((x) & SYNTH4_FORCE_VCOCAP_MASK) >> SYNTH4_FORCE_VCOCAP_LSB)
#define SYNTH4_FORCE_VCOCAP_SET(x)                                   (((0 | (x)) << SYNTH4_FORCE_VCOCAP_LSB) & SYNTH4_FORCE_VCOCAP_MASK)
#define SYNTH4_FORCE_VCOCAP_RESET                                    0
#define SYNTH4_VCOCAP_OVR_MSB                                        21
#define SYNTH4_VCOCAP_OVR_LSB                                        12
#define SYNTH4_VCOCAP_OVR_MASK                                       0x003ff000
#define SYNTH4_VCOCAP_OVR_GET(x)                                     (((x) & SYNTH4_VCOCAP_OVR_MASK) >> SYNTH4_VCOCAP_OVR_LSB)
#define SYNTH4_VCOCAP_OVR_SET(x)                                     (((0 | (x)) << SYNTH4_VCOCAP_OVR_LSB) & SYNTH4_VCOCAP_OVR_MASK)
#define SYNTH4_VCOCAP_OVR_RESET                                      128
#define SYNTH4_CNT_WITH_FORCE_CAP_MSB                                11
#define SYNTH4_CNT_WITH_FORCE_CAP_LSB                                11
#define SYNTH4_CNT_WITH_FORCE_CAP_MASK                               0x00000800
#define SYNTH4_CNT_WITH_FORCE_CAP_GET(x)                             (((x) & SYNTH4_CNT_WITH_FORCE_CAP_MASK) >> SYNTH4_CNT_WITH_FORCE_CAP_LSB)
#define SYNTH4_CNT_WITH_FORCE_CAP_SET(x)                             (((0 | (x)) << SYNTH4_CNT_WITH_FORCE_CAP_LSB) & SYNTH4_CNT_WITH_FORCE_CAP_MASK)
#define SYNTH4_CNT_WITH_FORCE_CAP_RESET                              0
#define SYNTH4_CLKXTAL_EDGE_SEL_D_MSB                                10
#define SYNTH4_CLKXTAL_EDGE_SEL_D_LSB                                10
#define SYNTH4_CLKXTAL_EDGE_SEL_D_MASK                               0x00000400
#define SYNTH4_CLKXTAL_EDGE_SEL_D_GET(x)                             (((x) & SYNTH4_CLKXTAL_EDGE_SEL_D_MASK) >> SYNTH4_CLKXTAL_EDGE_SEL_D_LSB)
#define SYNTH4_CLKXTAL_EDGE_SEL_D_SET(x)                             (((0 | (x)) << SYNTH4_CLKXTAL_EDGE_SEL_D_LSB) & SYNTH4_CLKXTAL_EDGE_SEL_D_MASK)
#define SYNTH4_CLKXTAL_EDGE_SEL_D_RESET                              1
#define SYNTH4_FORCE_LO_ON_MSB                                       9
#define SYNTH4_FORCE_LO_ON_LSB                                       9
#define SYNTH4_FORCE_LO_ON_MASK                                      0x00000200
#define SYNTH4_FORCE_LO_ON_GET(x)                                    (((x) & SYNTH4_FORCE_LO_ON_MASK) >> SYNTH4_FORCE_LO_ON_LSB)
#define SYNTH4_FORCE_LO_ON_SET(x)                                    (((0 | (x)) << SYNTH4_FORCE_LO_ON_LSB) & SYNTH4_FORCE_LO_ON_MASK)
#define SYNTH4_FORCE_LO_ON_RESET                                     0
#define SYNTH4_FBWIDTH_MSB                                           8
#define SYNTH4_FBWIDTH_LSB                                           7
#define SYNTH4_FBWIDTH_MASK                                          0x00000180
#define SYNTH4_FBWIDTH_GET(x)                                        (((x) & SYNTH4_FBWIDTH_MASK) >> SYNTH4_FBWIDTH_LSB)
#define SYNTH4_FBWIDTH_SET(x)                                        (((0 | (x)) << SYNTH4_FBWIDTH_LSB) & SYNTH4_FBWIDTH_MASK)
#define SYNTH4_FBWIDTH_RESET                                         0
#define SYNTH4_DELCLKSD_MSB                                          6
#define SYNTH4_DELCLKSD_LSB                                          6
#define SYNTH4_DELCLKSD_MASK                                         0x00000040
#define SYNTH4_DELCLKSD_GET(x)                                       (((x) & SYNTH4_DELCLKSD_MASK) >> SYNTH4_DELCLKSD_LSB)
#define SYNTH4_DELCLKSD_SET(x)                                       (((0 | (x)) << SYNTH4_DELCLKSD_LSB) & SYNTH4_DELCLKSD_MASK)
#define SYNTH4_DELCLKSD_RESET                                        0
#define SYNTH4_PFD_DISABLE_MSB                                       5
#define SYNTH4_PFD_DISABLE_LSB                                       5
#define SYNTH4_PFD_DISABLE_MASK                                      0x00000020
#define SYNTH4_PFD_DISABLE_GET(x)                                    (((x) & SYNTH4_PFD_DISABLE_MASK) >> SYNTH4_PFD_DISABLE_LSB)
#define SYNTH4_PFD_DISABLE_SET(x)                                    (((0 | (x)) << SYNTH4_PFD_DISABLE_LSB) & SYNTH4_PFD_DISABLE_MASK)
#define SYNTH4_PFD_DISABLE_RESET                                     0
#define SYNTH4_SDM_DISABLE_MSB                                       4
#define SYNTH4_SDM_DISABLE_LSB                                       4
#define SYNTH4_SDM_DISABLE_MASK                                      0x00000010
#define SYNTH4_SDM_DISABLE_GET(x)                                    (((x) & SYNTH4_SDM_DISABLE_MASK) >> SYNTH4_SDM_DISABLE_LSB)
#define SYNTH4_SDM_DISABLE_SET(x)                                    (((0 | (x)) << SYNTH4_SDM_DISABLE_LSB) & SYNTH4_SDM_DISABLE_MASK)
#define SYNTH4_SDM_DISABLE_RESET                                     0
#define SYNTH4_SDM_MODE_MSB                                          3
#define SYNTH4_SDM_MODE_LSB                                          3
#define SYNTH4_SDM_MODE_MASK                                         0x00000008
#define SYNTH4_SDM_MODE_GET(x)                                       (((x) & SYNTH4_SDM_MODE_MASK) >> SYNTH4_SDM_MODE_LSB)
#define SYNTH4_SDM_MODE_SET(x)                                       (((0 | (x)) << SYNTH4_SDM_MODE_LSB) & SYNTH4_SDM_MODE_MASK)
#define SYNTH4_SDM_MODE_RESET                                        0
#define SYNTH4_SDM_SPARE1_MSB                                        2
#define SYNTH4_SDM_SPARE1_LSB                                        2
#define SYNTH4_SDM_SPARE1_MASK                                       0x00000004
#define SYNTH4_SDM_SPARE1_GET(x)                                     (((x) & SYNTH4_SDM_SPARE1_MASK) >> SYNTH4_SDM_SPARE1_LSB)
#define SYNTH4_SDM_SPARE1_SET(x)                                     (((0 | (x)) << SYNTH4_SDM_SPARE1_LSB) & SYNTH4_SDM_SPARE1_MASK)
#define SYNTH4_SDM_SPARE1_RESET                                      0
#define SYNTH4_LO5GIBIAS_MSB                                         1
#define SYNTH4_LO5GIBIAS_LSB                                         0
#define SYNTH4_LO5GIBIAS_MASK                                        0x00000003
#define SYNTH4_LO5GIBIAS_GET(x)                                      (((x) & SYNTH4_LO5GIBIAS_MASK) >> SYNTH4_LO5GIBIAS_LSB)
#define SYNTH4_LO5GIBIAS_SET(x)                                      (((0 | (x)) << SYNTH4_LO5GIBIAS_LSB) & SYNTH4_LO5GIBIAS_MASK)
#define SYNTH4_LO5GIBIAS_RESET                                       1
#define SYNTH4_ADDRESS                                               0x000c
#define SYNTH4_HW_MASK                                               0xffffffff
#define SYNTH4_SW_MASK                                               0xffffffff
#define SYNTH4_HW_WRITE_MASK                                         0x00000000
#define SYNTH4_SW_WRITE_MASK                                         0xffffffff
#define SYNTH4_RSTMASK                                               0xffffffff
#define SYNTH4_RESET                                                 0x41080401

// 0x0010 (SYNTH5)
#define SYNTH5_SDM_SPARE2_MSB                                        31
#define SYNTH5_SDM_SPARE2_LSB                                        30
#define SYNTH5_SDM_SPARE2_MASK                                       0xc0000000
#define SYNTH5_SDM_SPARE2_GET(x)                                     (((x) & SYNTH5_SDM_SPARE2_MASK) >> SYNTH5_SDM_SPARE2_LSB)
#define SYNTH5_SDM_SPARE2_SET(x)                                     (((0 | (x)) << SYNTH5_SDM_SPARE2_LSB) & SYNTH5_SDM_SPARE2_MASK)
#define SYNTH5_SDM_SPARE2_RESET                                      0
#define SYNTH5_LO48BUF_ATB_MSB                                       29
#define SYNTH5_LO48BUF_ATB_LSB                                       29
#define SYNTH5_LO48BUF_ATB_MASK                                      0x20000000
#define SYNTH5_LO48BUF_ATB_GET(x)                                    (((x) & SYNTH5_LO48BUF_ATB_MASK) >> SYNTH5_LO48BUF_ATB_LSB)
#define SYNTH5_LO48BUF_ATB_SET(x)                                    (((0 | (x)) << SYNTH5_LO48BUF_ATB_LSB) & SYNTH5_LO48BUF_ATB_MASK)
#define SYNTH5_LO48BUF_ATB_RESET                                     0
#define SYNTH5_BIASVCO_MSB                                           28
#define SYNTH5_BIASVCO_LSB                                           25
#define SYNTH5_BIASVCO_MASK                                          0x1e000000
#define SYNTH5_BIASVCO_GET(x)                                        (((x) & SYNTH5_BIASVCO_MASK) >> SYNTH5_BIASVCO_LSB)
#define SYNTH5_BIASVCO_SET(x)                                        (((0 | (x)) << SYNTH5_BIASVCO_LSB) & SYNTH5_BIASVCO_MASK)
#define SYNTH5_BIASVCO_RESET                                         15
#define SYNTH5_FRACMODE_MSB                                          24
#define SYNTH5_FRACMODE_LSB                                          24
#define SYNTH5_FRACMODE_MASK                                         0x01000000
#define SYNTH5_FRACMODE_GET(x)                                       (((x) & SYNTH5_FRACMODE_MASK) >> SYNTH5_FRACMODE_LSB)
#define SYNTH5_FRACMODE_SET(x)                                       (((0 | (x)) << SYNTH5_FRACMODE_LSB) & SYNTH5_FRACMODE_MASK)
#define SYNTH5_FRACMODE_RESET                                        1
#define SYNTH5_FORCE_FRACLSB_MSB                                     23
#define SYNTH5_FORCE_FRACLSB_LSB                                     23
#define SYNTH5_FORCE_FRACLSB_MASK                                    0x00800000
#define SYNTH5_FORCE_FRACLSB_GET(x)                                  (((x) & SYNTH5_FORCE_FRACLSB_MASK) >> SYNTH5_FORCE_FRACLSB_LSB)
#define SYNTH5_FORCE_FRACLSB_SET(x)                                  (((0 | (x)) << SYNTH5_FORCE_FRACLSB_LSB) & SYNTH5_FORCE_FRACLSB_MASK)
#define SYNTH5_FORCE_FRACLSB_RESET                                   0
#define SYNTH5_OVRCHANDECODER_MSB                                    22
#define SYNTH5_OVRCHANDECODER_LSB                                    22
#define SYNTH5_OVRCHANDECODER_MASK                                   0x00400000
#define SYNTH5_OVRCHANDECODER_GET(x)                                 (((x) & SYNTH5_OVRCHANDECODER_MASK) >> SYNTH5_OVRCHANDECODER_LSB)
#define SYNTH5_OVRCHANDECODER_SET(x)                                 (((0 | (x)) << SYNTH5_OVRCHANDECODER_LSB) & SYNTH5_OVRCHANDECODER_MASK)
#define SYNTH5_OVRCHANDECODER_RESET                                  0
#define SYNTH5_PRECH_VCO_REF_MSB                                     21
#define SYNTH5_PRECH_VCO_REF_LSB                                     19
#define SYNTH5_PRECH_VCO_REF_MASK                                    0x00380000
#define SYNTH5_PRECH_VCO_REF_GET(x)                                  (((x) & SYNTH5_PRECH_VCO_REF_MASK) >> SYNTH5_PRECH_VCO_REF_LSB)
#define SYNTH5_PRECH_VCO_REF_SET(x)                                  (((0 | (x)) << SYNTH5_PRECH_VCO_REF_LSB) & SYNTH5_PRECH_VCO_REF_MASK)
#define SYNTH5_PRECH_VCO_REF_RESET                                   1
#define SYNTH5_EN_PRECH_VCO_MSB                                      18
#define SYNTH5_EN_PRECH_VCO_LSB                                      18
#define SYNTH5_EN_PRECH_VCO_MASK                                     0x00040000
#define SYNTH5_EN_PRECH_VCO_GET(x)                                   (((x) & SYNTH5_EN_PRECH_VCO_MASK) >> SYNTH5_EN_PRECH_VCO_LSB)
#define SYNTH5_EN_PRECH_VCO_SET(x)                                   (((0 | (x)) << SYNTH5_EN_PRECH_VCO_LSB) & SYNTH5_EN_PRECH_VCO_MASK)
#define SYNTH5_EN_PRECH_VCO_RESET                                    1
#define SYNTH5_LO5GIBIAS_CH0_MSB                                     17
#define SYNTH5_LO5GIBIAS_CH0_LSB                                     16
#define SYNTH5_LO5GIBIAS_CH0_MASK                                    0x00030000
#define SYNTH5_LO5GIBIAS_CH0_GET(x)                                  (((x) & SYNTH5_LO5GIBIAS_CH0_MASK) >> SYNTH5_LO5GIBIAS_CH0_LSB)
#define SYNTH5_LO5GIBIAS_CH0_SET(x)                                  (((0 | (x)) << SYNTH5_LO5GIBIAS_CH0_LSB) & SYNTH5_LO5GIBIAS_CH0_MASK)
#define SYNTH5_LO5GIBIAS_CH0_RESET                                   1
#define SYNTH5_USEVCOCAPIN_MSB                                       15
#define SYNTH5_USEVCOCAPIN_LSB                                       15
#define SYNTH5_USEVCOCAPIN_MASK                                      0x00008000
#define SYNTH5_USEVCOCAPIN_GET(x)                                    (((x) & SYNTH5_USEVCOCAPIN_MASK) >> SYNTH5_USEVCOCAPIN_LSB)
#define SYNTH5_USEVCOCAPIN_SET(x)                                    (((0 | (x)) << SYNTH5_USEVCOCAPIN_LSB) & SYNTH5_USEVCOCAPIN_MASK)
#define SYNTH5_USEVCOCAPIN_RESET                                     0
#define SYNTH5_VCOCAPIN_MSB                                          14
#define SYNTH5_VCOCAPIN_LSB                                          5
#define SYNTH5_VCOCAPIN_MASK                                         0x00007fe0
#define SYNTH5_VCOCAPIN_GET(x)                                       (((x) & SYNTH5_VCOCAPIN_MASK) >> SYNTH5_VCOCAPIN_LSB)
#define SYNTH5_VCOCAPIN_SET(x)                                       (((0 | (x)) << SYNTH5_VCOCAPIN_LSB) & SYNTH5_VCOCAPIN_MASK)
#define SYNTH5_VCOCAPIN_RESET                                        512
#define SYNTH5_LSBOVERLAPVALUE_MSB                                   4
#define SYNTH5_LSBOVERLAPVALUE_LSB                                   0
#define SYNTH5_LSBOVERLAPVALUE_MASK                                  0x0000001f
#define SYNTH5_LSBOVERLAPVALUE_GET(x)                                (((x) & SYNTH5_LSBOVERLAPVALUE_MASK) >> SYNTH5_LSBOVERLAPVALUE_LSB)
#define SYNTH5_LSBOVERLAPVALUE_SET(x)                                (((0 | (x)) << SYNTH5_LSBOVERLAPVALUE_LSB) & SYNTH5_LSBOVERLAPVALUE_MASK)
#define SYNTH5_LSBOVERLAPVALUE_RESET                                 6
#define SYNTH5_ADDRESS                                               0x0010
#define SYNTH5_HW_MASK                                               0xffffffff
#define SYNTH5_SW_MASK                                               0xffffffff
#define SYNTH5_HW_WRITE_MASK                                         0x00000000
#define SYNTH5_SW_WRITE_MASK                                         0xffffffff
#define SYNTH5_RSTMASK                                               0xffffffff
#define SYNTH5_RESET                                                 0x1f0d4006

// 0x0014 (SYNTH6)
#define SYNTH6_SYNTH_ON_MSB                                          31
#define SYNTH6_SYNTH_ON_LSB                                          31
#define SYNTH6_SYNTH_ON_MASK                                         0x80000000
#define SYNTH6_SYNTH_ON_GET(x)                                       (((x) & SYNTH6_SYNTH_ON_MASK) >> SYNTH6_SYNTH_ON_LSB)
#define SYNTH6_SYNTH_ON_SET(x)                                       (((0 | (x)) << SYNTH6_SYNTH_ON_LSB) & SYNTH6_SYNTH_ON_MASK)
#define SYNTH6_SYNTH_ON_RESET                                        0
#define SYNTH6_SYNTH_SM_STATE_MSB                                    30
#define SYNTH6_SYNTH_SM_STATE_LSB                                    27
#define SYNTH6_SYNTH_SM_STATE_MASK                                   0x78000000
#define SYNTH6_SYNTH_SM_STATE_GET(x)                                 (((x) & SYNTH6_SYNTH_SM_STATE_MASK) >> SYNTH6_SYNTH_SM_STATE_LSB)
#define SYNTH6_SYNTH_SM_STATE_SET(x)                                 (((0 | (x)) << SYNTH6_SYNTH_SM_STATE_LSB) & SYNTH6_SYNTH_SM_STATE_MASK)
#define SYNTH6_SYNTH_SM_STATE_RESET                                  0
#define SYNTH6_CAP_SEARCH_MSB                                        26
#define SYNTH6_CAP_SEARCH_LSB                                        26
#define SYNTH6_CAP_SEARCH_MASK                                       0x04000000
#define SYNTH6_CAP_SEARCH_GET(x)                                     (((x) & SYNTH6_CAP_SEARCH_MASK) >> SYNTH6_CAP_SEARCH_LSB)
#define SYNTH6_CAP_SEARCH_SET(x)                                     (((0 | (x)) << SYNTH6_CAP_SEARCH_LSB) & SYNTH6_CAP_SEARCH_MASK)
#define SYNTH6_CAP_SEARCH_RESET                                      0
#define SYNTH6_SYNTH_LOCK_VC_OK_MSB                                  25
#define SYNTH6_SYNTH_LOCK_VC_OK_LSB                                  25
#define SYNTH6_SYNTH_LOCK_VC_OK_MASK                                 0x02000000
#define SYNTH6_SYNTH_LOCK_VC_OK_GET(x)                               (((x) & SYNTH6_SYNTH_LOCK_VC_OK_MASK) >> SYNTH6_SYNTH_LOCK_VC_OK_LSB)
#define SYNTH6_SYNTH_LOCK_VC_OK_SET(x)                               (((0 | (x)) << SYNTH6_SYNTH_LOCK_VC_OK_LSB) & SYNTH6_SYNTH_LOCK_VC_OK_MASK)
#define SYNTH6_SYNTH_LOCK_VC_OK_RESET                                0
#define SYNTH6_SYNTH_IS_LOCKED_MSB                                   24
#define SYNTH6_SYNTH_IS_LOCKED_LSB                                   24
#define SYNTH6_SYNTH_IS_LOCKED_MASK                                  0x01000000
#define SYNTH6_SYNTH_IS_LOCKED_GET(x)                                (((x) & SYNTH6_SYNTH_IS_LOCKED_MASK) >> SYNTH6_SYNTH_IS_LOCKED_LSB)
#define SYNTH6_SYNTH_IS_LOCKED_SET(x)                                (((0 | (x)) << SYNTH6_SYNTH_IS_LOCKED_LSB) & SYNTH6_SYNTH_IS_LOCKED_MASK)
#define SYNTH6_SYNTH_IS_LOCKED_RESET                                 0
#define SYNTH6_PIN_VC_MSB                                            23
#define SYNTH6_PIN_VC_LSB                                            23
#define SYNTH6_PIN_VC_MASK                                           0x00800000
#define SYNTH6_PIN_VC_GET(x)                                         (((x) & SYNTH6_PIN_VC_MASK) >> SYNTH6_PIN_VC_LSB)
#define SYNTH6_PIN_VC_SET(x)                                         (((0 | (x)) << SYNTH6_PIN_VC_LSB) & SYNTH6_PIN_VC_MASK)
#define SYNTH6_PIN_VC_RESET                                          0
#define SYNTH6_VCO_CAP_ST_MSB                                        22
#define SYNTH6_VCO_CAP_ST_LSB                                        13
#define SYNTH6_VCO_CAP_ST_MASK                                       0x007fe000
#define SYNTH6_VCO_CAP_ST_GET(x)                                     (((x) & SYNTH6_VCO_CAP_ST_MASK) >> SYNTH6_VCO_CAP_ST_LSB)
#define SYNTH6_VCO_CAP_ST_SET(x)                                     (((0 | (x)) << SYNTH6_VCO_CAP_ST_LSB) & SYNTH6_VCO_CAP_ST_MASK)
#define SYNTH6_VCO_CAP_ST_RESET                                      0
#define SYNTH6_SHORT_R_MSB                                           12
#define SYNTH6_SHORT_R_LSB                                           12
#define SYNTH6_SHORT_R_MASK                                          0x00001000
#define SYNTH6_SHORT_R_GET(x)                                        (((x) & SYNTH6_SHORT_R_MASK) >> SYNTH6_SHORT_R_LSB)
#define SYNTH6_SHORT_R_SET(x)                                        (((0 | (x)) << SYNTH6_SHORT_R_LSB) & SYNTH6_SHORT_R_MASK)
#define SYNTH6_SHORT_R_RESET                                         0
#define SYNTH6_RESET_PFD_MSB                                         11
#define SYNTH6_RESET_PFD_LSB                                         11
#define SYNTH6_RESET_PFD_MASK                                        0x00000800
#define SYNTH6_RESET_PFD_GET(x)                                      (((x) & SYNTH6_RESET_PFD_MASK) >> SYNTH6_RESET_PFD_LSB)
#define SYNTH6_RESET_PFD_SET(x)                                      (((0 | (x)) << SYNTH6_RESET_PFD_LSB) & SYNTH6_RESET_PFD_MASK)
#define SYNTH6_RESET_PFD_RESET                                       0
#define SYNTH6_RESET_PSCOUNTERS_MSB                                  10
#define SYNTH6_RESET_PSCOUNTERS_LSB                                  10
#define SYNTH6_RESET_PSCOUNTERS_MASK                                 0x00000400
#define SYNTH6_RESET_PSCOUNTERS_GET(x)                               (((x) & SYNTH6_RESET_PSCOUNTERS_MASK) >> SYNTH6_RESET_PSCOUNTERS_LSB)
#define SYNTH6_RESET_PSCOUNTERS_SET(x)                               (((0 | (x)) << SYNTH6_RESET_PSCOUNTERS_LSB) & SYNTH6_RESET_PSCOUNTERS_MASK)
#define SYNTH6_RESET_PSCOUNTERS_RESET                                0
#define SYNTH6_RESET_SDM_B_MSB                                       9
#define SYNTH6_RESET_SDM_B_LSB                                       9
#define SYNTH6_RESET_SDM_B_MASK                                      0x00000200
#define SYNTH6_RESET_SDM_B_GET(x)                                    (((x) & SYNTH6_RESET_SDM_B_MASK) >> SYNTH6_RESET_SDM_B_LSB)
#define SYNTH6_RESET_SDM_B_SET(x)                                    (((0 | (x)) << SYNTH6_RESET_SDM_B_LSB) & SYNTH6_RESET_SDM_B_MASK)
#define SYNTH6_RESET_SDM_B_RESET                                     0
#define SYNTH6_VC2HIGH_MSB                                           8
#define SYNTH6_VC2HIGH_LSB                                           8
#define SYNTH6_VC2HIGH_MASK                                          0x00000100
#define SYNTH6_VC2HIGH_GET(x)                                        (((x) & SYNTH6_VC2HIGH_MASK) >> SYNTH6_VC2HIGH_LSB)
#define SYNTH6_VC2HIGH_SET(x)                                        (((0 | (x)) << SYNTH6_VC2HIGH_LSB) & SYNTH6_VC2HIGH_MASK)
#define SYNTH6_VC2HIGH_RESET                                         0
#define SYNTH6_VC2LOW_MSB                                            7
#define SYNTH6_VC2LOW_LSB                                            7
#define SYNTH6_VC2LOW_MASK                                           0x00000080
#define SYNTH6_VC2LOW_GET(x)                                         (((x) & SYNTH6_VC2LOW_MASK) >> SYNTH6_VC2LOW_LSB)
#define SYNTH6_VC2LOW_SET(x)                                         (((0 | (x)) << SYNTH6_VC2LOW_LSB) & SYNTH6_VC2LOW_MASK)
#define SYNTH6_VC2LOW_RESET                                          0
#define SYNTH6_DLLVC2HI_MSB                                          6
#define SYNTH6_DLLVC2HI_LSB                                          6
#define SYNTH6_DLLVC2HI_MASK                                         0x00000040
#define SYNTH6_DLLVC2HI_GET(x)                                       (((x) & SYNTH6_DLLVC2HI_MASK) >> SYNTH6_DLLVC2HI_LSB)
#define SYNTH6_DLLVC2HI_SET(x)                                       (((0 | (x)) << SYNTH6_DLLVC2HI_LSB) & SYNTH6_DLLVC2HI_MASK)
#define SYNTH6_DLLVC2HI_RESET                                        0
#define SYNTH6_DLLVC2LO_MSB                                          5
#define SYNTH6_DLLVC2LO_LSB                                          5
#define SYNTH6_DLLVC2LO_MASK                                         0x00000020
#define SYNTH6_DLLVC2LO_GET(x)                                       (((x) & SYNTH6_DLLVC2LO_MASK) >> SYNTH6_DLLVC2LO_LSB)
#define SYNTH6_DLLVC2LO_SET(x)                                       (((0 | (x)) << SYNTH6_DLLVC2LO_LSB) & SYNTH6_DLLVC2LO_MASK)
#define SYNTH6_DLLVC2LO_RESET                                        0
#define SYNTH6_RESERVED6A_MSB                                        4
#define SYNTH6_RESERVED6A_LSB                                        0
#define SYNTH6_RESERVED6A_MASK                                       0x0000001f
#define SYNTH6_RESERVED6A_GET(x)                                     (((x) & SYNTH6_RESERVED6A_MASK) >> SYNTH6_RESERVED6A_LSB)
#define SYNTH6_RESERVED6A_SET(x)                                     (((0 | (x)) << SYNTH6_RESERVED6A_LSB) & SYNTH6_RESERVED6A_MASK)
#define SYNTH6_RESERVED6A_RESET                                      0
#define SYNTH6_ADDRESS                                               0x0014
#define SYNTH6_HW_MASK                                               0xffffffff
#define SYNTH6_SW_MASK                                               0xffffffff
#define SYNTH6_HW_WRITE_MASK                                         0xffffffff
#define SYNTH6_SW_WRITE_MASK                                         0x00000000
#define SYNTH6_RSTMASK                                               0xffffffff
#define SYNTH6_RESET                                                 0x00000000

// 0x0018 (SYNTH7)
#define SYNTH7_LOADSYNTHCHANNEL_MSB                                  31
#define SYNTH7_LOADSYNTHCHANNEL_LSB                                  31
#define SYNTH7_LOADSYNTHCHANNEL_MASK                                 0x80000000
#define SYNTH7_LOADSYNTHCHANNEL_GET(x)                               (((x) & SYNTH7_LOADSYNTHCHANNEL_MASK) >> SYNTH7_LOADSYNTHCHANNEL_LSB)
#define SYNTH7_LOADSYNTHCHANNEL_SET(x)                               (((0 | (x)) << SYNTH7_LOADSYNTHCHANNEL_LSB) & SYNTH7_LOADSYNTHCHANNEL_MASK)
#define SYNTH7_LOADSYNTHCHANNEL_RESET                                1
#define SYNTH7_BANDSEL5G_MSB                                         30
#define SYNTH7_BANDSEL5G_LSB                                         29
#define SYNTH7_BANDSEL5G_MASK                                        0x60000000
#define SYNTH7_BANDSEL5G_GET(x)                                      (((x) & SYNTH7_BANDSEL5G_MASK) >> SYNTH7_BANDSEL5G_LSB)
#define SYNTH7_BANDSEL5G_SET(x)                                      (((0 | (x)) << SYNTH7_BANDSEL5G_LSB) & SYNTH7_BANDSEL5G_MASK)
#define SYNTH7_BANDSEL5G_RESET                                       0
#define SYNTH7_CHANSEL_MSB                                           28
#define SYNTH7_CHANSEL_LSB                                           21
#define SYNTH7_CHANSEL_MASK                                          0x1fe00000
#define SYNTH7_CHANSEL_GET(x)                                        (((x) & SYNTH7_CHANSEL_MASK) >> SYNTH7_CHANSEL_LSB)
#define SYNTH7_CHANSEL_SET(x)                                        (((0 | (x)) << SYNTH7_CHANSEL_LSB) & SYNTH7_CHANSEL_MASK)
#define SYNTH7_CHANSEL_RESET                                         81
#define SYNTH7_CHANFRAC_MSB                                          20
#define SYNTH7_CHANFRAC_LSB                                          0
#define SYNTH7_CHANFRAC_MASK                                         0x001fffff
#define SYNTH7_CHANFRAC_GET(x)                                       (((x) & SYNTH7_CHANFRAC_MASK) >> SYNTH7_CHANFRAC_LSB)
#define SYNTH7_CHANFRAC_SET(x)                                       (((0 | (x)) << SYNTH7_CHANFRAC_LSB) & SYNTH7_CHANFRAC_MASK)
#define SYNTH7_CHANFRAC_RESET                                        838848
#define SYNTH7_ADDRESS                                               0x0018
#define SYNTH7_HW_MASK                                               0xffffffff
#define SYNTH7_SW_MASK                                               0xffffffff
#define SYNTH7_HW_WRITE_MASK                                         0x00000000
#define SYNTH7_SW_WRITE_MASK                                         0xffffffff
#define SYNTH7_RSTMASK                                               0xffffffff
#define SYNTH7_RESET                                                 0x8a2cccc0

// 0x001c (SYNTH8)
#define SYNTH8_REFMULTB_MSB                                          31
#define SYNTH8_REFMULTB_LSB                                          29
#define SYNTH8_REFMULTB_MASK                                         0xe0000000
#define SYNTH8_REFMULTB_GET(x)                                       (((x) & SYNTH8_REFMULTB_MASK) >> SYNTH8_REFMULTB_LSB)
#define SYNTH8_REFMULTB_SET(x)                                       (((0 | (x)) << SYNTH8_REFMULTB_LSB) & SYNTH8_REFMULTB_MASK)
#define SYNTH8_REFMULTB_RESET                                        0
#define SYNTH8_DLLVCOCAPB_MSB                                        28
#define SYNTH8_DLLVCOCAPB_LSB                                        26
#define SYNTH8_DLLVCOCAPB_MASK                                       0x1c000000
#define SYNTH8_DLLVCOCAPB_GET(x)                                     (((x) & SYNTH8_DLLVCOCAPB_MASK) >> SYNTH8_DLLVCOCAPB_LSB)
#define SYNTH8_DLLVCOCAPB_SET(x)                                     (((0 | (x)) << SYNTH8_DLLVCOCAPB_LSB) & SYNTH8_DLLVCOCAPB_MASK)
#define SYNTH8_DLLVCOCAPB_RESET                                      3
#define SYNTH8_DLLVCOCURB_MSB                                        25
#define SYNTH8_DLLVCOCURB_LSB                                        23
#define SYNTH8_DLLVCOCURB_MASK                                       0x03800000
#define SYNTH8_DLLVCOCURB_GET(x)                                     (((x) & SYNTH8_DLLVCOCURB_MASK) >> SYNTH8_DLLVCOCURB_LSB)
#define SYNTH8_DLLVCOCURB_SET(x)                                     (((0 | (x)) << SYNTH8_DLLVCOCURB_LSB) & SYNTH8_DLLVCOCURB_MASK)
#define SYNTH8_DLLVCOCURB_RESET                                      0
#define SYNTH8_LOOP_3RD_ORDER_RB_MSB                                 22
#define SYNTH8_LOOP_3RD_ORDER_RB_LSB                                 20
#define SYNTH8_LOOP_3RD_ORDER_RB_MASK                                0x00700000
#define SYNTH8_LOOP_3RD_ORDER_RB_GET(x)                              (((x) & SYNTH8_LOOP_3RD_ORDER_RB_MASK) >> SYNTH8_LOOP_3RD_ORDER_RB_LSB)
#define SYNTH8_LOOP_3RD_ORDER_RB_SET(x)                              (((0 | (x)) << SYNTH8_LOOP_3RD_ORDER_RB_LSB) & SYNTH8_LOOP_3RD_ORDER_RB_MASK)
#define SYNTH8_LOOP_3RD_ORDER_RB_RESET                               1
#define SYNTH8_KVCOB_MSB                                             19
#define SYNTH8_KVCOB_LSB                                             17
#define SYNTH8_KVCOB_MASK                                            0x000e0000
#define SYNTH8_KVCOB_GET(x)                                          (((x) & SYNTH8_KVCOB_MASK) >> SYNTH8_KVCOB_LSB)
#define SYNTH8_KVCOB_SET(x)                                          (((0 | (x)) << SYNTH8_KVCOB_LSB) & SYNTH8_KVCOB_MASK)
#define SYNTH8_KVCOB_RESET                                           2
#define SYNTH8_DLLCPCAL_B_MSB                                        16
#define SYNTH8_DLLCPCAL_B_LSB                                        15
#define SYNTH8_DLLCPCAL_B_MASK                                       0x00018000
#define SYNTH8_DLLCPCAL_B_GET(x)                                     (((x) & SYNTH8_DLLCPCAL_B_MASK) >> SYNTH8_DLLCPCAL_B_LSB)
#define SYNTH8_DLLCPCAL_B_SET(x)                                     (((0 | (x)) << SYNTH8_DLLCPCAL_B_LSB) & SYNTH8_DLLCPCAL_B_MASK)
#define SYNTH8_DLLCPCAL_B_RESET                                      0
#define SYNTH8_LOOP_RSB_MSB                                          14
#define SYNTH8_LOOP_RSB_LSB                                          11
#define SYNTH8_LOOP_RSB_MASK                                         0x00007800
#define SYNTH8_LOOP_RSB_GET(x)                                       (((x) & SYNTH8_LOOP_RSB_MASK) >> SYNTH8_LOOP_RSB_LSB)
#define SYNTH8_LOOP_RSB_SET(x)                                       (((0 | (x)) << SYNTH8_LOOP_RSB_LSB) & SYNTH8_LOOP_RSB_MASK)
#define SYNTH8_LOOP_RSB_RESET                                        5
#define SYNTH8_ICPB_MSB                                              10
#define SYNTH8_ICPB_LSB                                              4
#define SYNTH8_ICPB_MASK                                             0x000007f0
#define SYNTH8_ICPB_GET(x)                                           (((x) & SYNTH8_ICPB_MASK) >> SYNTH8_ICPB_LSB)
#define SYNTH8_ICPB_SET(x)                                           (((0 | (x)) << SYNTH8_ICPB_LSB) & SYNTH8_ICPB_MASK)
#define SYNTH8_ICPB_RESET                                            28
#define SYNTH8_ICPLKB_MSB                                            3
#define SYNTH8_ICPLKB_LSB                                            0
#define SYNTH8_ICPLKB_MASK                                           0x0000000f
#define SYNTH8_ICPLKB_GET(x)                                         (((x) & SYNTH8_ICPLKB_MASK) >> SYNTH8_ICPLKB_LSB)
#define SYNTH8_ICPLKB_SET(x)                                         (((0 | (x)) << SYNTH8_ICPLKB_LSB) & SYNTH8_ICPLKB_MASK)
#define SYNTH8_ICPLKB_RESET                                          7
#define SYNTH8_ADDRESS                                               0x001c
#define SYNTH8_HW_MASK                                               0xffffffff
#define SYNTH8_SW_MASK                                               0xffffffff
#define SYNTH8_HW_WRITE_MASK                                         0x00000000
#define SYNTH8_SW_WRITE_MASK                                         0xffffffff
#define SYNTH8_RSTMASK                                               0xffffffff
#define SYNTH8_RESET                                                 0x0c1429c7

// 0x0020 (SYNTH9)
#define SYNTH9_REFMULTA01_MSB                                        31
#define SYNTH9_REFMULTA01_LSB                                        29
#define SYNTH9_REFMULTA01_MASK                                       0xe0000000
#define SYNTH9_REFMULTA01_GET(x)                                     (((x) & SYNTH9_REFMULTA01_MASK) >> SYNTH9_REFMULTA01_LSB)
#define SYNTH9_REFMULTA01_SET(x)                                     (((0 | (x)) << SYNTH9_REFMULTA01_LSB) & SYNTH9_REFMULTA01_MASK)
#define SYNTH9_REFMULTA01_RESET                                      0
#define SYNTH9_KVCOA0_MSB                                            28
#define SYNTH9_KVCOA0_LSB                                            26
#define SYNTH9_KVCOA0_MASK                                           0x1c000000
#define SYNTH9_KVCOA0_GET(x)                                         (((x) & SYNTH9_KVCOA0_MASK) >> SYNTH9_KVCOA0_LSB)
#define SYNTH9_KVCOA0_SET(x)                                         (((0 | (x)) << SYNTH9_KVCOA0_LSB) & SYNTH9_KVCOA0_MASK)
#define SYNTH9_KVCOA0_RESET                                          2
#define SYNTH9_DLLVCOCAPA01_MSB                                      25
#define SYNTH9_DLLVCOCAPA01_LSB                                      23
#define SYNTH9_DLLVCOCAPA01_MASK                                     0x03800000
#define SYNTH9_DLLVCOCAPA01_GET(x)                                   (((x) & SYNTH9_DLLVCOCAPA01_MASK) >> SYNTH9_DLLVCOCAPA01_LSB)
#define SYNTH9_DLLVCOCAPA01_SET(x)                                   (((0 | (x)) << SYNTH9_DLLVCOCAPA01_LSB) & SYNTH9_DLLVCOCAPA01_MASK)
#define SYNTH9_DLLVCOCAPA01_RESET                                    3
#define SYNTH9_DLLVCOCURA01_MSB                                      22
#define SYNTH9_DLLVCOCURA01_LSB                                      20
#define SYNTH9_DLLVCOCURA01_MASK                                     0x00700000
#define SYNTH9_DLLVCOCURA01_GET(x)                                   (((x) & SYNTH9_DLLVCOCURA01_MASK) >> SYNTH9_DLLVCOCURA01_LSB)
#define SYNTH9_DLLVCOCURA01_SET(x)                                   (((0 | (x)) << SYNTH9_DLLVCOCURA01_LSB) & SYNTH9_DLLVCOCURA01_MASK)
#define SYNTH9_DLLVCOCURA01_RESET                                    0
#define SYNTH9_DLLCPCAL_A01_MSB                                      19
#define SYNTH9_DLLCPCAL_A01_LSB                                      18
#define SYNTH9_DLLCPCAL_A01_MASK                                     0x000c0000
#define SYNTH9_DLLCPCAL_A01_GET(x)                                   (((x) & SYNTH9_DLLCPCAL_A01_MASK) >> SYNTH9_DLLCPCAL_A01_LSB)
#define SYNTH9_DLLCPCAL_A01_SET(x)                                   (((0 | (x)) << SYNTH9_DLLCPCAL_A01_LSB) & SYNTH9_DLLCPCAL_A01_MASK)
#define SYNTH9_DLLCPCAL_A01_RESET                                    0
#define SYNTH9_LOOP_3RD_ORDER_RA0_MSB                                17
#define SYNTH9_LOOP_3RD_ORDER_RA0_LSB                                15
#define SYNTH9_LOOP_3RD_ORDER_RA0_MASK                               0x00038000
#define SYNTH9_LOOP_3RD_ORDER_RA0_GET(x)                             (((x) & SYNTH9_LOOP_3RD_ORDER_RA0_MASK) >> SYNTH9_LOOP_3RD_ORDER_RA0_LSB)
#define SYNTH9_LOOP_3RD_ORDER_RA0_SET(x)                             (((0 | (x)) << SYNTH9_LOOP_3RD_ORDER_RA0_LSB) & SYNTH9_LOOP_3RD_ORDER_RA0_MASK)
#define SYNTH9_LOOP_3RD_ORDER_RA0_RESET                              1
#define SYNTH9_LOOP_RSA0_MSB                                         14
#define SYNTH9_LOOP_RSA0_LSB                                         11
#define SYNTH9_LOOP_RSA0_MASK                                        0x00007800
#define SYNTH9_LOOP_RSA0_GET(x)                                      (((x) & SYNTH9_LOOP_RSA0_MASK) >> SYNTH9_LOOP_RSA0_LSB)
#define SYNTH9_LOOP_RSA0_SET(x)                                      (((0 | (x)) << SYNTH9_LOOP_RSA0_LSB) & SYNTH9_LOOP_RSA0_MASK)
#define SYNTH9_LOOP_RSA0_RESET                                       5
#define SYNTH9_ICPA0_MSB                                             10
#define SYNTH9_ICPA0_LSB                                             4
#define SYNTH9_ICPA0_MASK                                            0x000007f0
#define SYNTH9_ICPA0_GET(x)                                          (((x) & SYNTH9_ICPA0_MASK) >> SYNTH9_ICPA0_LSB)
#define SYNTH9_ICPA0_SET(x)                                          (((0 | (x)) << SYNTH9_ICPA0_LSB) & SYNTH9_ICPA0_MASK)
#define SYNTH9_ICPA0_RESET                                           28
#define SYNTH9_ICPLKA0_MSB                                           3
#define SYNTH9_ICPLKA0_LSB                                           0
#define SYNTH9_ICPLKA0_MASK                                          0x0000000f
#define SYNTH9_ICPLKA0_GET(x)                                        (((x) & SYNTH9_ICPLKA0_MASK) >> SYNTH9_ICPLKA0_LSB)
#define SYNTH9_ICPLKA0_SET(x)                                        (((0 | (x)) << SYNTH9_ICPLKA0_LSB) & SYNTH9_ICPLKA0_MASK)
#define SYNTH9_ICPLKA0_RESET                                         7
#define SYNTH9_ADDRESS                                               0x0020
#define SYNTH9_HW_MASK                                               0xffffffff
#define SYNTH9_SW_MASK                                               0xffffffff
#define SYNTH9_HW_WRITE_MASK                                         0x00000000
#define SYNTH9_SW_WRITE_MASK                                         0xffffffff
#define SYNTH9_RSTMASK                                               0xffffffff
#define SYNTH9_RESET                                                 0x0980a9c7

// 0x0024 (SYNTH10)
#define SYNTH10_KVCOA1_MSB                                           31
#define SYNTH10_KVCOA1_LSB                                           29
#define SYNTH10_KVCOA1_MASK                                          0xe0000000
#define SYNTH10_KVCOA1_GET(x)                                        (((x) & SYNTH10_KVCOA1_MASK) >> SYNTH10_KVCOA1_LSB)
#define SYNTH10_KVCOA1_SET(x)                                        (((0 | (x)) << SYNTH10_KVCOA1_LSB) & SYNTH10_KVCOA1_MASK)
#define SYNTH10_KVCOA1_RESET                                         2
#define SYNTH10_LOOP_RSA1_MSB                                        28
#define SYNTH10_LOOP_RSA1_LSB                                        25
#define SYNTH10_LOOP_RSA1_MASK                                       0x1e000000
#define SYNTH10_LOOP_RSA1_GET(x)                                     (((x) & SYNTH10_LOOP_RSA1_MASK) >> SYNTH10_LOOP_RSA1_LSB)
#define SYNTH10_LOOP_RSA1_SET(x)                                     (((0 | (x)) << SYNTH10_LOOP_RSA1_LSB) & SYNTH10_LOOP_RSA1_MASK)
#define SYNTH10_LOOP_RSA1_RESET                                      5
#define SYNTH10_ICPA1_MSB                                            24
#define SYNTH10_ICPA1_LSB                                            18
#define SYNTH10_ICPA1_MASK                                           0x01fc0000
#define SYNTH10_ICPA1_GET(x)                                         (((x) & SYNTH10_ICPA1_MASK) >> SYNTH10_ICPA1_LSB)
#define SYNTH10_ICPA1_SET(x)                                         (((0 | (x)) << SYNTH10_ICPA1_LSB) & SYNTH10_ICPA1_MASK)
#define SYNTH10_ICPA1_RESET                                          28
#define SYNTH10_ICPLKA1_MSB                                          17
#define SYNTH10_ICPLKA1_LSB                                          14
#define SYNTH10_ICPLKA1_MASK                                         0x0003c000
#define SYNTH10_ICPLKA1_GET(x)                                       (((x) & SYNTH10_ICPLKA1_MASK) >> SYNTH10_ICPLKA1_LSB)
#define SYNTH10_ICPLKA1_SET(x)                                       (((0 | (x)) << SYNTH10_ICPLKA1_LSB) & SYNTH10_ICPLKA1_MASK)
#define SYNTH10_ICPLKA1_RESET                                        7
#define SYNTH10_LO5GIBIAS_CH1_MSB                                    13
#define SYNTH10_LO5GIBIAS_CH1_LSB                                    12
#define SYNTH10_LO5GIBIAS_CH1_MASK                                   0x00003000
#define SYNTH10_LO5GIBIAS_CH1_GET(x)                                 (((x) & SYNTH10_LO5GIBIAS_CH1_MASK) >> SYNTH10_LO5GIBIAS_CH1_LSB)
#define SYNTH10_LO5GIBIAS_CH1_SET(x)                                 (((0 | (x)) << SYNTH10_LO5GIBIAS_CH1_LSB) & SYNTH10_LO5GIBIAS_CH1_MASK)
#define SYNTH10_LO5GIBIAS_CH1_RESET                                  1
#define SYNTH10_LOOP_3RD_ORDER_RA1_MSB                               11
#define SYNTH10_LOOP_3RD_ORDER_RA1_LSB                               9
#define SYNTH10_LOOP_3RD_ORDER_RA1_MASK                              0x00000e00
#define SYNTH10_LOOP_3RD_ORDER_RA1_GET(x)                            (((x) & SYNTH10_LOOP_3RD_ORDER_RA1_MASK) >> SYNTH10_LOOP_3RD_ORDER_RA1_LSB)
#define SYNTH10_LOOP_3RD_ORDER_RA1_SET(x)                            (((0 | (x)) << SYNTH10_LOOP_3RD_ORDER_RA1_LSB) & SYNTH10_LOOP_3RD_ORDER_RA1_MASK)
#define SYNTH10_LOOP_3RD_ORDER_RA1_RESET                             1
#define SYNTH10_LODIV2IBIAS_MSB                                      8
#define SYNTH10_LODIV2IBIAS_LSB                                      7
#define SYNTH10_LODIV2IBIAS_MASK                                     0x00000180
#define SYNTH10_LODIV2IBIAS_GET(x)                                   (((x) & SYNTH10_LODIV2IBIAS_MASK) >> SYNTH10_LODIV2IBIAS_LSB)
#define SYNTH10_LODIV2IBIAS_SET(x)                                   (((0 | (x)) << SYNTH10_LODIV2IBIAS_LSB) & SYNTH10_LODIV2IBIAS_MASK)
#define SYNTH10_LODIV2IBIAS_RESET                                    1
#define SYNTH10_LOMIXIBIAS_MSB                                       6
#define SYNTH10_LOMIXIBIAS_LSB                                       5
#define SYNTH10_LOMIXIBIAS_MASK                                      0x00000060
#define SYNTH10_LOMIXIBIAS_GET(x)                                    (((x) & SYNTH10_LOMIXIBIAS_MASK) >> SYNTH10_LOMIXIBIAS_LSB)
#define SYNTH10_LOMIXIBIAS_SET(x)                                    (((0 | (x)) << SYNTH10_LOMIXIBIAS_LSB) & SYNTH10_LOMIXIBIAS_MASK)
#define SYNTH10_LOMIXIBIAS_RESET                                     1
#define SYNTH10_LO36BUF_ATB_MSB                                      4
#define SYNTH10_LO36BUF_ATB_LSB                                      2
#define SYNTH10_LO36BUF_ATB_MASK                                     0x0000001c
#define SYNTH10_LO36BUF_ATB_GET(x)                                   (((x) & SYNTH10_LO36BUF_ATB_MASK) >> SYNTH10_LO36BUF_ATB_LSB)
#define SYNTH10_LO36BUF_ATB_SET(x)                                   (((0 | (x)) << SYNTH10_LO36BUF_ATB_LSB) & SYNTH10_LO36BUF_ATB_MASK)
#define SYNTH10_LO36BUF_ATB_RESET                                    0
#define SYNTH10_LOBUFB2GTUNE_MSB                                     1
#define SYNTH10_LOBUFB2GTUNE_LSB                                     0
#define SYNTH10_LOBUFB2GTUNE_MASK                                    0x00000003
#define SYNTH10_LOBUFB2GTUNE_GET(x)                                  (((x) & SYNTH10_LOBUFB2GTUNE_MASK) >> SYNTH10_LOBUFB2GTUNE_LSB)
#define SYNTH10_LOBUFB2GTUNE_SET(x)                                  (((0 | (x)) << SYNTH10_LOBUFB2GTUNE_LSB) & SYNTH10_LOBUFB2GTUNE_MASK)
#define SYNTH10_LOBUFB2GTUNE_RESET                                   1
#define SYNTH10_ADDRESS                                              0x0024
#define SYNTH10_HW_MASK                                              0xffffffff
#define SYNTH10_SW_MASK                                              0xffffffff
#define SYNTH10_HW_WRITE_MASK                                        0x00000000
#define SYNTH10_SW_WRITE_MASK                                        0xffffffff
#define SYNTH10_RSTMASK                                              0xffffffff
#define SYNTH10_RESET                                                0x4a71d2a1

// 0x0028 (SYNTH11)
#define SYNTH11_FORCE_SHORTR_BIASNREF_MSB                            31
#define SYNTH11_FORCE_SHORTR_BIASNREF_LSB                            31
#define SYNTH11_FORCE_SHORTR_BIASNREF_MASK                           0x80000000
#define SYNTH11_FORCE_SHORTR_BIASNREF_GET(x)                         (((x) & SYNTH11_FORCE_SHORTR_BIASNREF_MASK) >> SYNTH11_FORCE_SHORTR_BIASNREF_LSB)
#define SYNTH11_FORCE_SHORTR_BIASNREF_SET(x)                         (((0 | (x)) << SYNTH11_FORCE_SHORTR_BIASNREF_LSB) & SYNTH11_FORCE_SHORTR_BIASNREF_MASK)
#define SYNTH11_FORCE_SHORTR_BIASNREF_RESET                          0
#define SYNTH11_FORCE_SHORTR_VCO_MSB                                 30
#define SYNTH11_FORCE_SHORTR_VCO_LSB                                 30
#define SYNTH11_FORCE_SHORTR_VCO_MASK                                0x40000000
#define SYNTH11_FORCE_SHORTR_VCO_GET(x)                              (((x) & SYNTH11_FORCE_SHORTR_VCO_MASK) >> SYNTH11_FORCE_SHORTR_VCO_LSB)
#define SYNTH11_FORCE_SHORTR_VCO_SET(x)                              (((0 | (x)) << SYNTH11_FORCE_SHORTR_VCO_LSB) & SYNTH11_FORCE_SHORTR_VCO_MASK)
#define SYNTH11_FORCE_SHORTR_VCO_RESET                               0
#define SYNTH11_FORCE_SHORTR_CP_MSB                                  29
#define SYNTH11_FORCE_SHORTR_CP_LSB                                  29
#define SYNTH11_FORCE_SHORTR_CP_MASK                                 0x20000000
#define SYNTH11_FORCE_SHORTR_CP_GET(x)                               (((x) & SYNTH11_FORCE_SHORTR_CP_MASK) >> SYNTH11_FORCE_SHORTR_CP_LSB)
#define SYNTH11_FORCE_SHORTR_CP_SET(x)                               (((0 | (x)) << SYNTH11_FORCE_SHORTR_CP_LSB) & SYNTH11_FORCE_SHORTR_CP_MASK)
#define SYNTH11_FORCE_SHORTR_CP_RESET                                0
#define SYNTH11_SHORTR_BIASNREF_OVR_MSB                              28
#define SYNTH11_SHORTR_BIASNREF_OVR_LSB                              28
#define SYNTH11_SHORTR_BIASNREF_OVR_MASK                             0x10000000
#define SYNTH11_SHORTR_BIASNREF_OVR_GET(x)                           (((x) & SYNTH11_SHORTR_BIASNREF_OVR_MASK) >> SYNTH11_SHORTR_BIASNREF_OVR_LSB)
#define SYNTH11_SHORTR_BIASNREF_OVR_SET(x)                           (((0 | (x)) << SYNTH11_SHORTR_BIASNREF_OVR_LSB) & SYNTH11_SHORTR_BIASNREF_OVR_MASK)
#define SYNTH11_SHORTR_BIASNREF_OVR_RESET                            0
#define SYNTH11_SHORTR_VCO_OVR_MSB                                   27
#define SYNTH11_SHORTR_VCO_OVR_LSB                                   27
#define SYNTH11_SHORTR_VCO_OVR_MASK                                  0x08000000
#define SYNTH11_SHORTR_VCO_OVR_GET(x)                                (((x) & SYNTH11_SHORTR_VCO_OVR_MASK) >> SYNTH11_SHORTR_VCO_OVR_LSB)
#define SYNTH11_SHORTR_VCO_OVR_SET(x)                                (((0 | (x)) << SYNTH11_SHORTR_VCO_OVR_LSB) & SYNTH11_SHORTR_VCO_OVR_MASK)
#define SYNTH11_SHORTR_VCO_OVR_RESET                                 0
#define SYNTH11_SHORTR_CP_OVR_MSB                                    26
#define SYNTH11_SHORTR_CP_OVR_LSB                                    26
#define SYNTH11_SHORTR_CP_OVR_MASK                                   0x04000000
#define SYNTH11_SHORTR_CP_OVR_GET(x)                                 (((x) & SYNTH11_SHORTR_CP_OVR_MASK) >> SYNTH11_SHORTR_CP_OVR_LSB)
#define SYNTH11_SHORTR_CP_OVR_SET(x)                                 (((0 | (x)) << SYNTH11_SHORTR_CP_OVR_LSB) & SYNTH11_SHORTR_CP_OVR_MASK)
#define SYNTH11_SHORTR_CP_OVR_RESET                                  0
#define SYNTH11_KVCOA2_MSB                                           25
#define SYNTH11_KVCOA2_LSB                                           23
#define SYNTH11_KVCOA2_MASK                                          0x03800000
#define SYNTH11_KVCOA2_GET(x)                                        (((x) & SYNTH11_KVCOA2_MASK) >> SYNTH11_KVCOA2_LSB)
#define SYNTH11_KVCOA2_SET(x)                                        (((0 | (x)) << SYNTH11_KVCOA2_LSB) & SYNTH11_KVCOA2_MASK)
#define SYNTH11_KVCOA2_RESET                                         2
#define SYNTH11_LOOP_RSA2_MSB                                        22
#define SYNTH11_LOOP_RSA2_LSB                                        19
#define SYNTH11_LOOP_RSA2_MASK                                       0x00780000
#define SYNTH11_LOOP_RSA2_GET(x)                                     (((x) & SYNTH11_LOOP_RSA2_MASK) >> SYNTH11_LOOP_RSA2_LSB)
#define SYNTH11_LOOP_RSA2_SET(x)                                     (((0 | (x)) << SYNTH11_LOOP_RSA2_LSB) & SYNTH11_LOOP_RSA2_MASK)
#define SYNTH11_LOOP_RSA2_RESET                                      5
#define SYNTH11_ICPA2_MSB                                            18
#define SYNTH11_ICPA2_LSB                                            12
#define SYNTH11_ICPA2_MASK                                           0x0007f000
#define SYNTH11_ICPA2_GET(x)                                         (((x) & SYNTH11_ICPA2_MASK) >> SYNTH11_ICPA2_LSB)
#define SYNTH11_ICPA2_SET(x)                                         (((0 | (x)) << SYNTH11_ICPA2_LSB) & SYNTH11_ICPA2_MASK)
#define SYNTH11_ICPA2_RESET                                          28
#define SYNTH11_ICPLKA2_MSB                                          11
#define SYNTH11_ICPLKA2_LSB                                          8
#define SYNTH11_ICPLKA2_MASK                                         0x00000f00
#define SYNTH11_ICPLKA2_GET(x)                                       (((x) & SYNTH11_ICPLKA2_MASK) >> SYNTH11_ICPLKA2_LSB)
#define SYNTH11_ICPLKA2_SET(x)                                       (((0 | (x)) << SYNTH11_ICPLKA2_LSB) & SYNTH11_ICPLKA2_MASK)
#define SYNTH11_ICPLKA2_RESET                                        7
#define SYNTH11_LOOP_3RD_ORDER_RA2_MSB                               7
#define SYNTH11_LOOP_3RD_ORDER_RA2_LSB                               5
#define SYNTH11_LOOP_3RD_ORDER_RA2_MASK                              0x000000e0
#define SYNTH11_LOOP_3RD_ORDER_RA2_GET(x)                            (((x) & SYNTH11_LOOP_3RD_ORDER_RA2_MASK) >> SYNTH11_LOOP_3RD_ORDER_RA2_LSB)
#define SYNTH11_LOOP_3RD_ORDER_RA2_SET(x)                            (((0 | (x)) << SYNTH11_LOOP_3RD_ORDER_RA2_LSB) & SYNTH11_LOOP_3RD_ORDER_RA2_MASK)
#define SYNTH11_LOOP_3RD_ORDER_RA2_RESET                             1
#define SYNTH11_RESERVED11A_MSB                                      4
#define SYNTH11_RESERVED11A_LSB                                      3
#define SYNTH11_RESERVED11A_MASK                                     0x00000018
#define SYNTH11_RESERVED11A_GET(x)                                   (((x) & SYNTH11_RESERVED11A_MASK) >> SYNTH11_RESERVED11A_LSB)
#define SYNTH11_RESERVED11A_SET(x)                                   (((0 | (x)) << SYNTH11_RESERVED11A_LSB) & SYNTH11_RESERVED11A_MASK)
#define SYNTH11_RESERVED11A_RESET                                    0
#define SYNTH11_LOBUFA2GTUNE_MSB                                     2
#define SYNTH11_LOBUFA2GTUNE_LSB                                     1
#define SYNTH11_LOBUFA2GTUNE_MASK                                    0x00000006
#define SYNTH11_LOBUFA2GTUNE_GET(x)                                  (((x) & SYNTH11_LOBUFA2GTUNE_MASK) >> SYNTH11_LOBUFA2GTUNE_LSB)
#define SYNTH11_LOBUFA2GTUNE_SET(x)                                  (((0 | (x)) << SYNTH11_LOBUFA2GTUNE_LSB) & SYNTH11_LOBUFA2GTUNE_MASK)
#define SYNTH11_LOBUFA2GTUNE_RESET                                   1
#define SYNTH11_INVERT_SDM_CLK_MSB                                   0
#define SYNTH11_INVERT_SDM_CLK_LSB                                   0
#define SYNTH11_INVERT_SDM_CLK_MASK                                  0x00000001
#define SYNTH11_INVERT_SDM_CLK_GET(x)                                (((x) & SYNTH11_INVERT_SDM_CLK_MASK) >> SYNTH11_INVERT_SDM_CLK_LSB)
#define SYNTH11_INVERT_SDM_CLK_SET(x)                                (((0 | (x)) << SYNTH11_INVERT_SDM_CLK_LSB) & SYNTH11_INVERT_SDM_CLK_MASK)
#define SYNTH11_INVERT_SDM_CLK_RESET                                 0
#define SYNTH11_ADDRESS                                              0x0028
#define SYNTH11_HW_MASK                                              0xffffffff
#define SYNTH11_SW_MASK                                              0xffffffff
#define SYNTH11_HW_WRITE_MASK                                        0x00000000
#define SYNTH11_SW_WRITE_MASK                                        0xffffffff
#define SYNTH11_RSTMASK                                              0xffffffff
#define SYNTH11_RESET                                                0x0129c722

// 0x002c (SYNTH12)
#define SYNTH12_FORCELOBUF5GON_MSB                                   31
#define SYNTH12_FORCELOBUF5GON_LSB                                   29
#define SYNTH12_FORCELOBUF5GON_MASK                                  0xe0000000
#define SYNTH12_FORCELOBUF5GON_GET(x)                                (((x) & SYNTH12_FORCELOBUF5GON_MASK) >> SYNTH12_FORCELOBUF5GON_LSB)
#define SYNTH12_FORCELOBUF5GON_SET(x)                                (((0 | (x)) << SYNTH12_FORCELOBUF5GON_LSB) & SYNTH12_FORCELOBUF5GON_MASK)
#define SYNTH12_FORCELOBUF5GON_RESET                                 0
#define SYNTH12_FORCEPWDLOBUF5G_MSB                                  28
#define SYNTH12_FORCEPWDLOBUF5G_LSB                                  26
#define SYNTH12_FORCEPWDLOBUF5G_MASK                                 0x1c000000
#define SYNTH12_FORCEPWDLOBUF5G_GET(x)                               (((x) & SYNTH12_FORCEPWDLOBUF5G_MASK) >> SYNTH12_FORCEPWDLOBUF5G_LSB)
#define SYNTH12_FORCEPWDLOBUF5G_SET(x)                               (((0 | (x)) << SYNTH12_FORCEPWDLOBUF5G_LSB) & SYNTH12_FORCEPWDLOBUF5G_MASK)
#define SYNTH12_FORCEPWDLOBUF5G_RESET                                0
#define SYNTH12_SYNTHDIGOUTEN_MSB                                    25
#define SYNTH12_SYNTHDIGOUTEN_LSB                                    25
#define SYNTH12_SYNTHDIGOUTEN_MASK                                   0x02000000
#define SYNTH12_SYNTHDIGOUTEN_GET(x)                                 (((x) & SYNTH12_SYNTHDIGOUTEN_MASK) >> SYNTH12_SYNTHDIGOUTEN_LSB)
#define SYNTH12_SYNTHDIGOUTEN_SET(x)                                 (((0 | (x)) << SYNTH12_SYNTHDIGOUTEN_LSB) & SYNTH12_SYNTHDIGOUTEN_MASK)
#define SYNTH12_SYNTHDIGOUTEN_RESET                                  0
#define SYNTH12_ISELQEN_LOBUFA2G_MSB                                 24
#define SYNTH12_ISELQEN_LOBUFA2G_LSB                                 22
#define SYNTH12_ISELQEN_LOBUFA2G_MASK                                0x01c00000
#define SYNTH12_ISELQEN_LOBUFA2G_GET(x)                              (((x) & SYNTH12_ISELQEN_LOBUFA2G_MASK) >> SYNTH12_ISELQEN_LOBUFA2G_LSB)
#define SYNTH12_ISELQEN_LOBUFA2G_SET(x)                              (((0 | (x)) << SYNTH12_ISELQEN_LOBUFA2G_LSB) & SYNTH12_ISELQEN_LOBUFA2G_MASK)
#define SYNTH12_ISELQEN_LOBUFA2G_RESET                               0
#define SYNTH12_DLLCP_B_MSB                                          21
#define SYNTH12_DLLCP_B_LSB                                          18
#define SYNTH12_DLLCP_B_MASK                                         0x003c0000
#define SYNTH12_DLLCP_B_GET(x)                                       (((x) & SYNTH12_DLLCP_B_MASK) >> SYNTH12_DLLCP_B_LSB)
#define SYNTH12_DLLCP_B_SET(x)                                       (((0 | (x)) << SYNTH12_DLLCP_B_LSB) & SYNTH12_DLLCP_B_MASK)
#define SYNTH12_DLLCP_B_RESET                                        3
#define SYNTH12_DLLCP_A01_MSB                                        17
#define SYNTH12_DLLCP_A01_LSB                                        14
#define SYNTH12_DLLCP_A01_MASK                                       0x0003c000
#define SYNTH12_DLLCP_A01_GET(x)                                     (((x) & SYNTH12_DLLCP_A01_MASK) >> SYNTH12_DLLCP_A01_LSB)
#define SYNTH12_DLLCP_A01_SET(x)                                     (((0 | (x)) << SYNTH12_DLLCP_A01_LSB) & SYNTH12_DLLCP_A01_MASK)
#define SYNTH12_DLLCP_A01_RESET                                      3
#define SYNTH12_DLLCP_A23_MSB                                        13
#define SYNTH12_DLLCP_A23_LSB                                        10
#define SYNTH12_DLLCP_A23_MASK                                       0x00003c00
#define SYNTH12_DLLCP_A23_GET(x)                                     (((x) & SYNTH12_DLLCP_A23_MASK) >> SYNTH12_DLLCP_A23_LSB)
#define SYNTH12_DLLCP_A23_SET(x)                                     (((0 | (x)) << SYNTH12_DLLCP_A23_LSB) & SYNTH12_DLLCP_A23_MASK)
#define SYNTH12_DLLCP_A23_RESET                                      3
#define SYNTH12_LOOP_CPB_MSB                                         9
#define SYNTH12_LOOP_CPB_LSB                                         8
#define SYNTH12_LOOP_CPB_MASK                                        0x00000300
#define SYNTH12_LOOP_CPB_GET(x)                                      (((x) & SYNTH12_LOOP_CPB_MASK) >> SYNTH12_LOOP_CPB_LSB)
#define SYNTH12_LOOP_CPB_SET(x)                                      (((0 | (x)) << SYNTH12_LOOP_CPB_LSB) & SYNTH12_LOOP_CPB_MASK)
#define SYNTH12_LOOP_CPB_RESET                                       3
#define SYNTH12_LOOP_CPA0_MSB                                        7
#define SYNTH12_LOOP_CPA0_LSB                                        6
#define SYNTH12_LOOP_CPA0_MASK                                       0x000000c0
#define SYNTH12_LOOP_CPA0_GET(x)                                     (((x) & SYNTH12_LOOP_CPA0_MASK) >> SYNTH12_LOOP_CPA0_LSB)
#define SYNTH12_LOOP_CPA0_SET(x)                                     (((0 | (x)) << SYNTH12_LOOP_CPA0_LSB) & SYNTH12_LOOP_CPA0_MASK)
#define SYNTH12_LOOP_CPA0_RESET                                      3
#define SYNTH12_LOOP_CPA1_MSB                                        5
#define SYNTH12_LOOP_CPA1_LSB                                        4
#define SYNTH12_LOOP_CPA1_MASK                                       0x00000030
#define SYNTH12_LOOP_CPA1_GET(x)                                     (((x) & SYNTH12_LOOP_CPA1_MASK) >> SYNTH12_LOOP_CPA1_LSB)
#define SYNTH12_LOOP_CPA1_SET(x)                                     (((0 | (x)) << SYNTH12_LOOP_CPA1_LSB) & SYNTH12_LOOP_CPA1_MASK)
#define SYNTH12_LOOP_CPA1_RESET                                      3
#define SYNTH12_LOOP_CPA2_MSB                                        3
#define SYNTH12_LOOP_CPA2_LSB                                        2
#define SYNTH12_LOOP_CPA2_MASK                                       0x0000000c
#define SYNTH12_LOOP_CPA2_GET(x)                                     (((x) & SYNTH12_LOOP_CPA2_MASK) >> SYNTH12_LOOP_CPA2_LSB)
#define SYNTH12_LOOP_CPA2_SET(x)                                     (((0 | (x)) << SYNTH12_LOOP_CPA2_LSB) & SYNTH12_LOOP_CPA2_MASK)
#define SYNTH12_LOOP_CPA2_RESET                                      3
#define SYNTH12_LOOP_CPA3_MSB                                        1
#define SYNTH12_LOOP_CPA3_LSB                                        0
#define SYNTH12_LOOP_CPA3_MASK                                       0x00000003
#define SYNTH12_LOOP_CPA3_GET(x)                                     (((x) & SYNTH12_LOOP_CPA3_MASK) >> SYNTH12_LOOP_CPA3_LSB)
#define SYNTH12_LOOP_CPA3_SET(x)                                     (((0 | (x)) << SYNTH12_LOOP_CPA3_LSB) & SYNTH12_LOOP_CPA3_MASK)
#define SYNTH12_LOOP_CPA3_RESET                                      3
#define SYNTH12_ADDRESS                                              0x002c
#define SYNTH12_HW_MASK                                              0xffffffff
#define SYNTH12_SW_MASK                                              0xffffffff
#define SYNTH12_HW_WRITE_MASK                                        0x00000000
#define SYNTH12_SW_WRITE_MASK                                        0xffffffff
#define SYNTH12_RSTMASK                                              0xffffffff
#define SYNTH12_RESET                                                0x000ccfff

// 0x0030 (SYNTH13)
#define SYNTH13_REFMULTA23_MSB                                       31
#define SYNTH13_REFMULTA23_LSB                                       29
#define SYNTH13_REFMULTA23_MASK                                      0xe0000000
#define SYNTH13_REFMULTA23_GET(x)                                    (((x) & SYNTH13_REFMULTA23_MASK) >> SYNTH13_REFMULTA23_LSB)
#define SYNTH13_REFMULTA23_SET(x)                                    (((0 | (x)) << SYNTH13_REFMULTA23_LSB) & SYNTH13_REFMULTA23_MASK)
#define SYNTH13_REFMULTA23_RESET                                     0
#define SYNTH13_KVCOA3_MSB                                           28
#define SYNTH13_KVCOA3_LSB                                           26
#define SYNTH13_KVCOA3_MASK                                          0x1c000000
#define SYNTH13_KVCOA3_GET(x)                                        (((x) & SYNTH13_KVCOA3_MASK) >> SYNTH13_KVCOA3_LSB)
#define SYNTH13_KVCOA3_SET(x)                                        (((0 | (x)) << SYNTH13_KVCOA3_LSB) & SYNTH13_KVCOA3_MASK)
#define SYNTH13_KVCOA3_RESET                                         2
#define SYNTH13_LOOP_3RD_ORDER_RA3_MSB                               25
#define SYNTH13_LOOP_3RD_ORDER_RA3_LSB                               23
#define SYNTH13_LOOP_3RD_ORDER_RA3_MASK                              0x03800000
#define SYNTH13_LOOP_3RD_ORDER_RA3_GET(x)                            (((x) & SYNTH13_LOOP_3RD_ORDER_RA3_MASK) >> SYNTH13_LOOP_3RD_ORDER_RA3_LSB)
#define SYNTH13_LOOP_3RD_ORDER_RA3_SET(x)                            (((0 | (x)) << SYNTH13_LOOP_3RD_ORDER_RA3_LSB) & SYNTH13_LOOP_3RD_ORDER_RA3_MASK)
#define SYNTH13_LOOP_3RD_ORDER_RA3_RESET                             1
#define SYNTH13_DLLVCOCAPA23_MSB                                     22
#define SYNTH13_DLLVCOCAPA23_LSB                                     20
#define SYNTH13_DLLVCOCAPA23_MASK                                    0x00700000
#define SYNTH13_DLLVCOCAPA23_GET(x)                                  (((x) & SYNTH13_DLLVCOCAPA23_MASK) >> SYNTH13_DLLVCOCAPA23_LSB)
#define SYNTH13_DLLVCOCAPA23_SET(x)                                  (((0 | (x)) << SYNTH13_DLLVCOCAPA23_LSB) & SYNTH13_DLLVCOCAPA23_MASK)
#define SYNTH13_DLLVCOCAPA23_RESET                                   3
#define SYNTH13_DLLVCOCURA23_MSB                                     19
#define SYNTH13_DLLVCOCURA23_LSB                                     17
#define SYNTH13_DLLVCOCURA23_MASK                                    0x000e0000
#define SYNTH13_DLLVCOCURA23_GET(x)                                  (((x) & SYNTH13_DLLVCOCURA23_MASK) >> SYNTH13_DLLVCOCURA23_LSB)
#define SYNTH13_DLLVCOCURA23_SET(x)                                  (((0 | (x)) << SYNTH13_DLLVCOCURA23_LSB) & SYNTH13_DLLVCOCURA23_MASK)
#define SYNTH13_DLLVCOCURA23_RESET                                   0
#define SYNTH13_DLLCPCAL_A23_MSB                                     16
#define SYNTH13_DLLCPCAL_A23_LSB                                     15
#define SYNTH13_DLLCPCAL_A23_MASK                                    0x00018000
#define SYNTH13_DLLCPCAL_A23_GET(x)                                  (((x) & SYNTH13_DLLCPCAL_A23_MASK) >> SYNTH13_DLLCPCAL_A23_LSB)
#define SYNTH13_DLLCPCAL_A23_SET(x)                                  (((0 | (x)) << SYNTH13_DLLCPCAL_A23_LSB) & SYNTH13_DLLCPCAL_A23_MASK)
#define SYNTH13_DLLCPCAL_A23_RESET                                   0
#define SYNTH13_LOOP_RSA3_MSB                                        14
#define SYNTH13_LOOP_RSA3_LSB                                        11
#define SYNTH13_LOOP_RSA3_MASK                                       0x00007800
#define SYNTH13_LOOP_RSA3_GET(x)                                     (((x) & SYNTH13_LOOP_RSA3_MASK) >> SYNTH13_LOOP_RSA3_LSB)
#define SYNTH13_LOOP_RSA3_SET(x)                                     (((0 | (x)) << SYNTH13_LOOP_RSA3_LSB) & SYNTH13_LOOP_RSA3_MASK)
#define SYNTH13_LOOP_RSA3_RESET                                      5
#define SYNTH13_ICPA3_MSB                                            10
#define SYNTH13_ICPA3_LSB                                            4
#define SYNTH13_ICPA3_MASK                                           0x000007f0
#define SYNTH13_ICPA3_GET(x)                                         (((x) & SYNTH13_ICPA3_MASK) >> SYNTH13_ICPA3_LSB)
#define SYNTH13_ICPA3_SET(x)                                         (((0 | (x)) << SYNTH13_ICPA3_LSB) & SYNTH13_ICPA3_MASK)
#define SYNTH13_ICPA3_RESET                                          28
#define SYNTH13_ICPLKA3_MSB                                          3
#define SYNTH13_ICPLKA3_LSB                                          0
#define SYNTH13_ICPLKA3_MASK                                         0x0000000f
#define SYNTH13_ICPLKA3_GET(x)                                       (((x) & SYNTH13_ICPLKA3_MASK) >> SYNTH13_ICPLKA3_LSB)
#define SYNTH13_ICPLKA3_SET(x)                                       (((0 | (x)) << SYNTH13_ICPLKA3_LSB) & SYNTH13_ICPLKA3_MASK)
#define SYNTH13_ICPLKA3_RESET                                        7
#define SYNTH13_ADDRESS                                              0x0030
#define SYNTH13_HW_MASK                                              0xffffffff
#define SYNTH13_SW_MASK                                              0xffffffff
#define SYNTH13_HW_WRITE_MASK                                        0x00000000
#define SYNTH13_SW_WRITE_MASK                                        0xffffffff
#define SYNTH13_RSTMASK                                              0xffffffff
#define SYNTH13_RESET                                                0x08b029c7

// 0x0034 (SYNTH14)
#define SYNTH14_RESERVED14A_MSB                                      31
#define SYNTH14_RESERVED14A_LSB                                      29
#define SYNTH14_RESERVED14A_MASK                                     0xe0000000
#define SYNTH14_RESERVED14A_GET(x)                                   (((x) & SYNTH14_RESERVED14A_MASK) >> SYNTH14_RESERVED14A_LSB)
#define SYNTH14_RESERVED14A_SET(x)                                   (((0 | (x)) << SYNTH14_RESERVED14A_LSB) & SYNTH14_RESERVED14A_MASK)
#define SYNTH14_RESERVED14A_RESET                                    0
#define SYNTH14_AICOVR1_CHANSEL_MSB                                  28
#define SYNTH14_AICOVR1_CHANSEL_LSB                                  21
#define SYNTH14_AICOVR1_CHANSEL_MASK                                 0x1fe00000
#define SYNTH14_AICOVR1_CHANSEL_GET(x)                               (((x) & SYNTH14_AICOVR1_CHANSEL_MASK) >> SYNTH14_AICOVR1_CHANSEL_LSB)
#define SYNTH14_AICOVR1_CHANSEL_SET(x)                               (((0 | (x)) << SYNTH14_AICOVR1_CHANSEL_LSB) & SYNTH14_AICOVR1_CHANSEL_MASK)
#define SYNTH14_AICOVR1_CHANSEL_RESET                                80
#define SYNTH14_AICOVR1_CHANFRAC_MSB                                 20
#define SYNTH14_AICOVR1_CHANFRAC_LSB                                 0
#define SYNTH14_AICOVR1_CHANFRAC_MASK                                0x001fffff
#define SYNTH14_AICOVR1_CHANFRAC_GET(x)                              (((x) & SYNTH14_AICOVR1_CHANFRAC_MASK) >> SYNTH14_AICOVR1_CHANFRAC_LSB)
#define SYNTH14_AICOVR1_CHANFRAC_SET(x)                              (((0 | (x)) << SYNTH14_AICOVR1_CHANFRAC_LSB) & SYNTH14_AICOVR1_CHANFRAC_MASK)
#define SYNTH14_AICOVR1_CHANFRAC_RESET                               1537911
#define SYNTH14_ADDRESS                                              0x0034
#define SYNTH14_HW_MASK                                              0xffffffff
#define SYNTH14_SW_MASK                                              0xffffffff
#define SYNTH14_HW_WRITE_MASK                                        0x00000000
#define SYNTH14_SW_WRITE_MASK                                        0xffffffff
#define SYNTH14_RSTMASK                                              0xffffffff
#define SYNTH14_RESET                                                0x0a177777

// 0x0038 (SYNTH15)
#define SYNTH15_RESERVED15A_MSB                                      31
#define SYNTH15_RESERVED15A_LSB                                      29
#define SYNTH15_RESERVED15A_MASK                                     0xe0000000
#define SYNTH15_RESERVED15A_GET(x)                                   (((x) & SYNTH15_RESERVED15A_MASK) >> SYNTH15_RESERVED15A_LSB)
#define SYNTH15_RESERVED15A_SET(x)                                   (((0 | (x)) << SYNTH15_RESERVED15A_LSB) & SYNTH15_RESERVED15A_MASK)
#define SYNTH15_RESERVED15A_RESET                                    0
#define SYNTH15_AICOVR2_CHANSEL_MSB                                  28
#define SYNTH15_AICOVR2_CHANSEL_LSB                                  21
#define SYNTH15_AICOVR2_CHANSEL_MASK                                 0x1fe00000
#define SYNTH15_AICOVR2_CHANSEL_GET(x)                               (((x) & SYNTH15_AICOVR2_CHANSEL_MASK) >> SYNTH15_AICOVR2_CHANSEL_LSB)
#define SYNTH15_AICOVR2_CHANSEL_SET(x)                               (((0 | (x)) << SYNTH15_AICOVR2_CHANSEL_LSB) & SYNTH15_AICOVR2_CHANSEL_MASK)
#define SYNTH15_AICOVR2_CHANSEL_RESET                                80
#define SYNTH15_AICOVR2_CHANFRAC_MSB                                 20
#define SYNTH15_AICOVR2_CHANFRAC_LSB                                 0
#define SYNTH15_AICOVR2_CHANFRAC_MASK                                0x001fffff
#define SYNTH15_AICOVR2_CHANFRAC_GET(x)                              (((x) & SYNTH15_AICOVR2_CHANFRAC_MASK) >> SYNTH15_AICOVR2_CHANFRAC_LSB)
#define SYNTH15_AICOVR2_CHANFRAC_SET(x)                              (((0 | (x)) << SYNTH15_AICOVR2_CHANFRAC_LSB) & SYNTH15_AICOVR2_CHANFRAC_MASK)
#define SYNTH15_AICOVR2_CHANFRAC_RESET                               1537911
#define SYNTH15_ADDRESS                                              0x0038
#define SYNTH15_HW_MASK                                              0xffffffff
#define SYNTH15_SW_MASK                                              0xffffffff
#define SYNTH15_HW_WRITE_MASK                                        0x00000000
#define SYNTH15_SW_WRITE_MASK                                        0xffffffff
#define SYNTH15_RSTMASK                                              0xffffffff
#define SYNTH15_RESET                                                0x0a177777

// 0x003c (SYNTH16)
#define SYNTH16_DLLABSEL_MSB                                         31
#define SYNTH16_DLLABSEL_LSB                                         30
#define SYNTH16_DLLABSEL_MASK                                        0xc0000000
#define SYNTH16_DLLABSEL_GET(x)                                      (((x) & SYNTH16_DLLABSEL_MASK) >> SYNTH16_DLLABSEL_LSB)
#define SYNTH16_DLLABSEL_SET(x)                                      (((0 | (x)) << SYNTH16_DLLABSEL_LSB) & SYNTH16_DLLABSEL_MASK)
#define SYNTH16_DLLABSEL_RESET                                       0
#define SYNTH16_RESERVED16A_MSB                                      29
#define SYNTH16_RESERVED16A_LSB                                      24
#define SYNTH16_RESERVED16A_MASK                                     0x3f000000
#define SYNTH16_RESERVED16A_GET(x)                                   (((x) & SYNTH16_RESERVED16A_MASK) >> SYNTH16_RESERVED16A_LSB)
#define SYNTH16_RESERVED16A_SET(x)                                   (((0 | (x)) << SYNTH16_RESERVED16A_LSB) & SYNTH16_RESERVED16A_MASK)
#define SYNTH16_RESERVED16A_RESET                                    0
#define SYNTH16_DLLPD_MSB                                            23
#define SYNTH16_DLLPD_LSB                                            23
#define SYNTH16_DLLPD_MASK                                           0x00800000
#define SYNTH16_DLLPD_GET(x)                                         (((x) & SYNTH16_DLLPD_MASK) >> SYNTH16_DLLPD_LSB)
#define SYNTH16_DLLPD_SET(x)                                         (((0 | (x)) << SYNTH16_DLLPD_LSB) & SYNTH16_DLLPD_MASK)
#define SYNTH16_DLLPD_RESET                                          0
#define SYNTH16_DLLPDCAL_MSB                                         22
#define SYNTH16_DLLPDCAL_LSB                                         22
#define SYNTH16_DLLPDCAL_MASK                                        0x00400000
#define SYNTH16_DLLPDCAL_GET(x)                                      (((x) & SYNTH16_DLLPDCAL_MASK) >> SYNTH16_DLLPDCAL_LSB)
#define SYNTH16_DLLPDCAL_SET(x)                                      (((0 | (x)) << SYNTH16_DLLPDCAL_LSB) & SYNTH16_DLLPDCAL_MASK)
#define SYNTH16_DLLPDCAL_RESET                                       1
#define SYNTH16_DLLVCH_MSB                                           21
#define SYNTH16_DLLVCH_LSB                                           20
#define SYNTH16_DLLVCH_MASK                                          0x00300000
#define SYNTH16_DLLVCH_GET(x)                                        (((x) & SYNTH16_DLLVCH_MASK) >> SYNTH16_DLLVCH_LSB)
#define SYNTH16_DLLVCH_SET(x)                                        (((0 | (x)) << SYNTH16_DLLVCH_LSB) & SYNTH16_DLLVCH_MASK)
#define SYNTH16_DLLVCH_RESET                                         0
#define SYNTH16_DLLVCL_MSB                                           19
#define SYNTH16_DLLVCL_LSB                                           18
#define SYNTH16_DLLVCL_MASK                                          0x000c0000
#define SYNTH16_DLLVCL_GET(x)                                        (((x) & SYNTH16_DLLVCL_MASK) >> SYNTH16_DLLVCL_LSB)
#define SYNTH16_DLLVCL_SET(x)                                        (((0 | (x)) << SYNTH16_DLLVCL_LSB) & SYNTH16_DLLVCL_MASK)
#define SYNTH16_DLLVCL_RESET                                         0
#define SYNTH16_FORCE_DLL_CAPCUR_MSB                                 17
#define SYNTH16_FORCE_DLL_CAPCUR_LSB                                 17
#define SYNTH16_FORCE_DLL_CAPCUR_MASK                                0x00020000
#define SYNTH16_FORCE_DLL_CAPCUR_GET(x)                              (((x) & SYNTH16_FORCE_DLL_CAPCUR_MASK) >> SYNTH16_FORCE_DLL_CAPCUR_LSB)
#define SYNTH16_FORCE_DLL_CAPCUR_SET(x)                              (((0 | (x)) << SYNTH16_FORCE_DLL_CAPCUR_LSB) & SYNTH16_FORCE_DLL_CAPCUR_MASK)
#define SYNTH16_FORCE_DLL_CAPCUR_RESET                               0
#define SYNTH16_DLL_CHANGE_CAP_FIRST_MSB                             16
#define SYNTH16_DLL_CHANGE_CAP_FIRST_LSB                             16
#define SYNTH16_DLL_CHANGE_CAP_FIRST_MASK                            0x00010000
#define SYNTH16_DLL_CHANGE_CAP_FIRST_GET(x)                          (((x) & SYNTH16_DLL_CHANGE_CAP_FIRST_MASK) >> SYNTH16_DLL_CHANGE_CAP_FIRST_LSB)
#define SYNTH16_DLL_CHANGE_CAP_FIRST_SET(x)                          (((0 | (x)) << SYNTH16_DLL_CHANGE_CAP_FIRST_LSB) & SYNTH16_DLL_CHANGE_CAP_FIRST_MASK)
#define SYNTH16_DLL_CHANGE_CAP_FIRST_RESET                           0
#define SYNTH16_WAIT_DLLSM_MSB                                       15
#define SYNTH16_WAIT_DLLSM_LSB                                       12
#define SYNTH16_WAIT_DLLSM_MASK                                      0x0000f000
#define SYNTH16_WAIT_DLLSM_GET(x)                                    (((x) & SYNTH16_WAIT_DLLSM_MASK) >> SYNTH16_WAIT_DLLSM_LSB)
#define SYNTH16_WAIT_DLLSM_SET(x)                                    (((0 | (x)) << SYNTH16_WAIT_DLLSM_LSB) & SYNTH16_WAIT_DLLSM_MASK)
#define SYNTH16_WAIT_DLLSM_RESET                                     5
#define SYNTH16_DLL_VC_CHK_CNT_MSB                                   11
#define SYNTH16_DLL_VC_CHK_CNT_LSB                                   8
#define SYNTH16_DLL_VC_CHK_CNT_MASK                                  0x00000f00
#define SYNTH16_DLL_VC_CHK_CNT_GET(x)                                (((x) & SYNTH16_DLL_VC_CHK_CNT_MASK) >> SYNTH16_DLL_VC_CHK_CNT_LSB)
#define SYNTH16_DLL_VC_CHK_CNT_SET(x)                                (((0 | (x)) << SYNTH16_DLL_VC_CHK_CNT_LSB) & SYNTH16_DLL_VC_CHK_CNT_MASK)
#define SYNTH16_DLL_VC_CHK_CNT_RESET                                 5
#define SYNTH16_FORCE_DLL_IS_LOCKED_MSB                              7
#define SYNTH16_FORCE_DLL_IS_LOCKED_LSB                              7
#define SYNTH16_FORCE_DLL_IS_LOCKED_MASK                             0x00000080
#define SYNTH16_FORCE_DLL_IS_LOCKED_GET(x)                           (((x) & SYNTH16_FORCE_DLL_IS_LOCKED_MASK) >> SYNTH16_FORCE_DLL_IS_LOCKED_LSB)
#define SYNTH16_FORCE_DLL_IS_LOCKED_SET(x)                           (((0 | (x)) << SYNTH16_FORCE_DLL_IS_LOCKED_LSB) & SYNTH16_FORCE_DLL_IS_LOCKED_MASK)
#define SYNTH16_FORCE_DLL_IS_LOCKED_RESET                            0
#define SYNTH16_DLL_IS_LOCKED_OVR_MSB                                6
#define SYNTH16_DLL_IS_LOCKED_OVR_LSB                                6
#define SYNTH16_DLL_IS_LOCKED_OVR_MASK                               0x00000040
#define SYNTH16_DLL_IS_LOCKED_OVR_GET(x)                             (((x) & SYNTH16_DLL_IS_LOCKED_OVR_MASK) >> SYNTH16_DLL_IS_LOCKED_OVR_LSB)
#define SYNTH16_DLL_IS_LOCKED_OVR_SET(x)                             (((0 | (x)) << SYNTH16_DLL_IS_LOCKED_OVR_LSB) & SYNTH16_DLL_IS_LOCKED_OVR_MASK)
#define SYNTH16_DLL_IS_LOCKED_OVR_RESET                              1
#define SYNTH16_REFV_MSB                                             5
#define SYNTH16_REFV_LSB                                             4
#define SYNTH16_REFV_MASK                                            0x00000030
#define SYNTH16_REFV_GET(x)                                          (((x) & SYNTH16_REFV_MASK) >> SYNTH16_REFV_LSB)
#define SYNTH16_REFV_SET(x)                                          (((0 | (x)) << SYNTH16_REFV_LSB) & SYNTH16_REFV_MASK)
#define SYNTH16_REFV_RESET                                           0
#define SYNTH16_ALIGN_MSB                                            3
#define SYNTH16_ALIGN_LSB                                            1
#define SYNTH16_ALIGN_MASK                                           0x0000000e
#define SYNTH16_ALIGN_GET(x)                                         (((x) & SYNTH16_ALIGN_MASK) >> SYNTH16_ALIGN_LSB)
#define SYNTH16_ALIGN_SET(x)                                         (((0 | (x)) << SYNTH16_ALIGN_LSB) & SYNTH16_ALIGN_MASK)
#define SYNTH16_ALIGN_RESET                                          2
#define SYNTH16_PWUPLOB2GPD_MSB                                      0
#define SYNTH16_PWUPLOB2GPD_LSB                                      0
#define SYNTH16_PWUPLOB2GPD_MASK                                     0x00000001
#define SYNTH16_PWUPLOB2GPD_GET(x)                                   (((x) & SYNTH16_PWUPLOB2GPD_MASK) >> SYNTH16_PWUPLOB2GPD_LSB)
#define SYNTH16_PWUPLOB2GPD_SET(x)                                   (((0 | (x)) << SYNTH16_PWUPLOB2GPD_LSB) & SYNTH16_PWUPLOB2GPD_MASK)
#define SYNTH16_PWUPLOB2GPD_RESET                                    0
#define SYNTH16_ADDRESS                                              0x003c
#define SYNTH16_HW_MASK                                              0xffffffff
#define SYNTH16_SW_MASK                                              0xffffffff
#define SYNTH16_HW_WRITE_MASK                                        0x00000000
#define SYNTH16_SW_WRITE_MASK                                        0xffffffff
#define SYNTH16_RSTMASK                                              0xffffffff
#define SYNTH16_RESET                                                0x00405544


#endif /* _SYNTH_REG_CSR_H_ */
