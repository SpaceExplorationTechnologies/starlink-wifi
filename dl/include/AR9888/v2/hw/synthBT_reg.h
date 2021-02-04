//                                                                             
// File:       ./synthBT_reg_csr.vrh                                           
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:47:58 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             synthBT_reg_csr.rdl                                             
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/synthBT_reg.rdl
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


#ifndef _SYNTHBT_REG_CSR_H_
#define _SYNTHBT_REG_CSR_H_
// 0x0000 (SYNTHBT1)
#define SYNTHBT1_PWD_BIAS_MSB                                        31
#define SYNTHBT1_PWD_BIAS_LSB                                        31
#define SYNTHBT1_PWD_BIAS_MASK                                       0x80000000
#define SYNTHBT1_PWD_BIAS_GET(x)                                     (((x) & SYNTHBT1_PWD_BIAS_MASK) >> SYNTHBT1_PWD_BIAS_LSB)
#define SYNTHBT1_PWD_BIAS_SET(x)                                     (((0 | (x)) << SYNTHBT1_PWD_BIAS_LSB) & SYNTHBT1_PWD_BIAS_MASK)
#define SYNTHBT1_PWD_BIAS_RESET                                      0
#define SYNTHBT1_PWD_CP_MSB                                          30
#define SYNTHBT1_PWD_CP_LSB                                          30
#define SYNTHBT1_PWD_CP_MASK                                         0x40000000
#define SYNTHBT1_PWD_CP_GET(x)                                       (((x) & SYNTHBT1_PWD_CP_MASK) >> SYNTHBT1_PWD_CP_LSB)
#define SYNTHBT1_PWD_CP_SET(x)                                       (((0 | (x)) << SYNTHBT1_PWD_CP_LSB) & SYNTHBT1_PWD_CP_MASK)
#define SYNTHBT1_PWD_CP_RESET                                        0
#define SYNTHBT1_PWD_VCMON_MSB                                       29
#define SYNTHBT1_PWD_VCMON_LSB                                       29
#define SYNTHBT1_PWD_VCMON_MASK                                      0x20000000
#define SYNTHBT1_PWD_VCMON_GET(x)                                    (((x) & SYNTHBT1_PWD_VCMON_MASK) >> SYNTHBT1_PWD_VCMON_LSB)
#define SYNTHBT1_PWD_VCMON_SET(x)                                    (((0 | (x)) << SYNTHBT1_PWD_VCMON_LSB) & SYNTHBT1_PWD_VCMON_MASK)
#define SYNTHBT1_PWD_VCMON_RESET                                     0
#define SYNTHBT1_PWD_VCO_MSB                                         28
#define SYNTHBT1_PWD_VCO_LSB                                         28
#define SYNTHBT1_PWD_VCO_MASK                                        0x10000000
#define SYNTHBT1_PWD_VCO_GET(x)                                      (((x) & SYNTHBT1_PWD_VCO_MASK) >> SYNTHBT1_PWD_VCO_LSB)
#define SYNTHBT1_PWD_VCO_SET(x)                                      (((0 | (x)) << SYNTHBT1_PWD_VCO_LSB) & SYNTHBT1_PWD_VCO_MASK)
#define SYNTHBT1_PWD_VCO_RESET                                       0
#define SYNTHBT1_PWD_PRESC_MSB                                       27
#define SYNTHBT1_PWD_PRESC_LSB                                       27
#define SYNTHBT1_PWD_PRESC_MASK                                      0x08000000
#define SYNTHBT1_PWD_PRESC_GET(x)                                    (((x) & SYNTHBT1_PWD_PRESC_MASK) >> SYNTHBT1_PWD_PRESC_LSB)
#define SYNTHBT1_PWD_PRESC_SET(x)                                    (((0 | (x)) << SYNTHBT1_PWD_PRESC_LSB) & SYNTHBT1_PWD_PRESC_MASK)
#define SYNTHBT1_PWD_PRESC_RESET                                     0
#define SYNTHBT1_VCOREGBYPASS_MSB                                    26
#define SYNTHBT1_VCOREGBYPASS_LSB                                    26
#define SYNTHBT1_VCOREGBYPASS_MASK                                   0x04000000
#define SYNTHBT1_VCOREGBYPASS_GET(x)                                 (((x) & SYNTHBT1_VCOREGBYPASS_MASK) >> SYNTHBT1_VCOREGBYPASS_LSB)
#define SYNTHBT1_VCOREGBYPASS_SET(x)                                 (((0 | (x)) << SYNTHBT1_VCOREGBYPASS_LSB) & SYNTHBT1_VCOREGBYPASS_MASK)
#define SYNTHBT1_VCOREGBYPASS_RESET                                  0
#define SYNTHBT1_VCOREGLEVEL_MSB                                     25
#define SYNTHBT1_VCOREGLEVEL_LSB                                     24
#define SYNTHBT1_VCOREGLEVEL_MASK                                    0x03000000
#define SYNTHBT1_VCOREGLEVEL_GET(x)                                  (((x) & SYNTHBT1_VCOREGLEVEL_MASK) >> SYNTHBT1_VCOREGLEVEL_LSB)
#define SYNTHBT1_VCOREGLEVEL_SET(x)                                  (((0 | (x)) << SYNTHBT1_VCOREGLEVEL_LSB) & SYNTHBT1_VCOREGLEVEL_MASK)
#define SYNTHBT1_VCOREGLEVEL_RESET                                   1
#define SYNTHBT1_MONITOR_FB_MSB                                      23
#define SYNTHBT1_MONITOR_FB_LSB                                      23
#define SYNTHBT1_MONITOR_FB_MASK                                     0x00800000
#define SYNTHBT1_MONITOR_FB_GET(x)                                   (((x) & SYNTHBT1_MONITOR_FB_MASK) >> SYNTHBT1_MONITOR_FB_LSB)
#define SYNTHBT1_MONITOR_FB_SET(x)                                   (((0 | (x)) << SYNTHBT1_MONITOR_FB_LSB) & SYNTHBT1_MONITOR_FB_MASK)
#define SYNTHBT1_MONITOR_FB_RESET                                    0
#define SYNTHBT1_MONITOR_REF_MSB                                     22
#define SYNTHBT1_MONITOR_REF_LSB                                     22
#define SYNTHBT1_MONITOR_REF_MASK                                    0x00400000
#define SYNTHBT1_MONITOR_REF_GET(x)                                  (((x) & SYNTHBT1_MONITOR_REF_MASK) >> SYNTHBT1_MONITOR_REF_LSB)
#define SYNTHBT1_MONITOR_REF_SET(x)                                  (((0 | (x)) << SYNTHBT1_MONITOR_REF_LSB) & SYNTHBT1_MONITOR_REF_MASK)
#define SYNTHBT1_MONITOR_REF_RESET                                   0
#define SYNTHBT1_MONITOR_VC2HIGH_MSB                                 21
#define SYNTHBT1_MONITOR_VC2HIGH_LSB                                 21
#define SYNTHBT1_MONITOR_VC2HIGH_MASK                                0x00200000
#define SYNTHBT1_MONITOR_VC2HIGH_GET(x)                              (((x) & SYNTHBT1_MONITOR_VC2HIGH_MASK) >> SYNTHBT1_MONITOR_VC2HIGH_LSB)
#define SYNTHBT1_MONITOR_VC2HIGH_SET(x)                              (((0 | (x)) << SYNTHBT1_MONITOR_VC2HIGH_LSB) & SYNTHBT1_MONITOR_VC2HIGH_MASK)
#define SYNTHBT1_MONITOR_VC2HIGH_RESET                               0
#define SYNTHBT1_MONITOR_VC2LOW_MSB                                  20
#define SYNTHBT1_MONITOR_VC2LOW_LSB                                  20
#define SYNTHBT1_MONITOR_VC2LOW_MASK                                 0x00100000
#define SYNTHBT1_MONITOR_VC2LOW_GET(x)                               (((x) & SYNTHBT1_MONITOR_VC2LOW_MASK) >> SYNTHBT1_MONITOR_VC2LOW_LSB)
#define SYNTHBT1_MONITOR_VC2LOW_SET(x)                               (((0 | (x)) << SYNTHBT1_MONITOR_VC2LOW_LSB) & SYNTHBT1_MONITOR_VC2LOW_MASK)
#define SYNTHBT1_MONITOR_VC2LOW_RESET                                0
#define SYNTHBT1_MONITOR_SYNTHLOCKVCOK_MSB                           19
#define SYNTHBT1_MONITOR_SYNTHLOCKVCOK_LSB                           19
#define SYNTHBT1_MONITOR_SYNTHLOCKVCOK_MASK                          0x00080000
#define SYNTHBT1_MONITOR_SYNTHLOCKVCOK_GET(x)                        (((x) & SYNTHBT1_MONITOR_SYNTHLOCKVCOK_MASK) >> SYNTHBT1_MONITOR_SYNTHLOCKVCOK_LSB)
#define SYNTHBT1_MONITOR_SYNTHLOCKVCOK_SET(x)                        (((0 | (x)) << SYNTHBT1_MONITOR_SYNTHLOCKVCOK_LSB) & SYNTHBT1_MONITOR_SYNTHLOCKVCOK_MASK)
#define SYNTHBT1_MONITOR_SYNTHLOCKVCOK_RESET                         0
#define SYNTHBT1_SEL_VCOABUS_MSB                                     18
#define SYNTHBT1_SEL_VCOABUS_LSB                                     16
#define SYNTHBT1_SEL_VCOABUS_MASK                                    0x00070000
#define SYNTHBT1_SEL_VCOABUS_GET(x)                                  (((x) & SYNTHBT1_SEL_VCOABUS_MASK) >> SYNTHBT1_SEL_VCOABUS_LSB)
#define SYNTHBT1_SEL_VCOABUS_SET(x)                                  (((0 | (x)) << SYNTHBT1_SEL_VCOABUS_LSB) & SYNTHBT1_SEL_VCOABUS_MASK)
#define SYNTHBT1_SEL_VCOABUS_RESET                                   0
#define SYNTHBT1_SEL_VCMONABUS_MSB                                   15
#define SYNTHBT1_SEL_VCMONABUS_LSB                                   13
#define SYNTHBT1_SEL_VCMONABUS_MASK                                  0x0000e000
#define SYNTHBT1_SEL_VCMONABUS_GET(x)                                (((x) & SYNTHBT1_SEL_VCMONABUS_MASK) >> SYNTHBT1_SEL_VCMONABUS_LSB)
#define SYNTHBT1_SEL_VCMONABUS_SET(x)                                (((0 | (x)) << SYNTHBT1_SEL_VCMONABUS_LSB) & SYNTHBT1_SEL_VCMONABUS_MASK)
#define SYNTHBT1_SEL_VCMONABUS_RESET                                 0
#define SYNTHBT1_DIGTESTOUTEN_MSB                                    12
#define SYNTHBT1_DIGTESTOUTEN_LSB                                    12
#define SYNTHBT1_DIGTESTOUTEN_MASK                                   0x00001000
#define SYNTHBT1_DIGTESTOUTEN_GET(x)                                 (((x) & SYNTHBT1_DIGTESTOUTEN_MASK) >> SYNTHBT1_DIGTESTOUTEN_LSB)
#define SYNTHBT1_DIGTESTOUTEN_SET(x)                                 (((0 | (x)) << SYNTHBT1_DIGTESTOUTEN_LSB) & SYNTHBT1_DIGTESTOUTEN_MASK)
#define SYNTHBT1_DIGTESTOUTEN_RESET                                  0
#define SYNTHBT1_CLKXTAL_EDGE_SEL_MSB                                11
#define SYNTHBT1_CLKXTAL_EDGE_SEL_LSB                                11
#define SYNTHBT1_CLKXTAL_EDGE_SEL_MASK                               0x00000800
#define SYNTHBT1_CLKXTAL_EDGE_SEL_GET(x)                             (((x) & SYNTHBT1_CLKXTAL_EDGE_SEL_MASK) >> SYNTHBT1_CLKXTAL_EDGE_SEL_LSB)
#define SYNTHBT1_CLKXTAL_EDGE_SEL_SET(x)                             (((0 | (x)) << SYNTHBT1_CLKXTAL_EDGE_SEL_LSB) & SYNTHBT1_CLKXTAL_EDGE_SEL_MASK)
#define SYNTHBT1_CLKXTAL_EDGE_SEL_RESET                              0
#define SYNTHBT1_PFD_DISABLE_MSB                                     10
#define SYNTHBT1_PFD_DISABLE_LSB                                     10
#define SYNTHBT1_PFD_DISABLE_MASK                                    0x00000400
#define SYNTHBT1_PFD_DISABLE_GET(x)                                  (((x) & SYNTHBT1_PFD_DISABLE_MASK) >> SYNTHBT1_PFD_DISABLE_LSB)
#define SYNTHBT1_PFD_DISABLE_SET(x)                                  (((0 | (x)) << SYNTHBT1_PFD_DISABLE_LSB) & SYNTHBT1_PFD_DISABLE_MASK)
#define SYNTHBT1_PFD_DISABLE_RESET                                   0
#define SYNTHBT1_RESET_PSCOUNTERS_MSB                                9
#define SYNTHBT1_RESET_PSCOUNTERS_LSB                                9
#define SYNTHBT1_RESET_PSCOUNTERS_MASK                               0x00000200
#define SYNTHBT1_RESET_PSCOUNTERS_GET(x)                             (((x) & SYNTHBT1_RESET_PSCOUNTERS_MASK) >> SYNTHBT1_RESET_PSCOUNTERS_LSB)
#define SYNTHBT1_RESET_PSCOUNTERS_SET(x)                             (((0 | (x)) << SYNTHBT1_RESET_PSCOUNTERS_LSB) & SYNTHBT1_RESET_PSCOUNTERS_MASK)
#define SYNTHBT1_RESET_PSCOUNTERS_RESET                              0
#define SYNTHBT1_PSCOUNT_FBSEL_MSB                                   8
#define SYNTHBT1_PSCOUNT_FBSEL_LSB                                   8
#define SYNTHBT1_PSCOUNT_FBSEL_MASK                                  0x00000100
#define SYNTHBT1_PSCOUNT_FBSEL_GET(x)                                (((x) & SYNTHBT1_PSCOUNT_FBSEL_MASK) >> SYNTHBT1_PSCOUNT_FBSEL_LSB)
#define SYNTHBT1_PSCOUNT_FBSEL_SET(x)                                (((0 | (x)) << SYNTHBT1_PSCOUNT_FBSEL_LSB) & SYNTHBT1_PSCOUNT_FBSEL_MASK)
#define SYNTHBT1_PSCOUNT_FBSEL_RESET                                 0
#define SYNTHBT1_PRESC_SEL_MSB                                       7
#define SYNTHBT1_PRESC_SEL_LSB                                       6
#define SYNTHBT1_PRESC_SEL_MASK                                      0x000000c0
#define SYNTHBT1_PRESC_SEL_GET(x)                                    (((x) & SYNTHBT1_PRESC_SEL_MASK) >> SYNTHBT1_PRESC_SEL_LSB)
#define SYNTHBT1_PRESC_SEL_SET(x)                                    (((0 | (x)) << SYNTHBT1_PRESC_SEL_LSB) & SYNTHBT1_PRESC_SEL_MASK)
#define SYNTHBT1_PRESC_SEL_RESET                                     1
#define SYNTHBT1_PFDDELAY_MSB                                        5
#define SYNTHBT1_PFDDELAY_LSB                                        5
#define SYNTHBT1_PFDDELAY_MASK                                       0x00000020
#define SYNTHBT1_PFDDELAY_GET(x)                                     (((x) & SYNTHBT1_PFDDELAY_MASK) >> SYNTHBT1_PFDDELAY_LSB)
#define SYNTHBT1_PFDDELAY_SET(x)                                     (((0 | (x)) << SYNTHBT1_PFDDELAY_LSB) & SYNTHBT1_PFDDELAY_MASK)
#define SYNTHBT1_PFDDELAY_RESET                                      1
#define SYNTHBT1_LONGSHIFTSEL_MSB                                    4
#define SYNTHBT1_LONGSHIFTSEL_LSB                                    4
#define SYNTHBT1_LONGSHIFTSEL_MASK                                   0x00000010
#define SYNTHBT1_LONGSHIFTSEL_GET(x)                                 (((x) & SYNTHBT1_LONGSHIFTSEL_MASK) >> SYNTHBT1_LONGSHIFTSEL_LSB)
#define SYNTHBT1_LONGSHIFTSEL_SET(x)                                 (((0 | (x)) << SYNTHBT1_LONGSHIFTSEL_LSB) & SYNTHBT1_LONGSHIFTSEL_MASK)
#define SYNTHBT1_LONGSHIFTSEL_RESET                                  1
#define SYNTHBT1_LOCALSYNTHCAL_MSB                                   3
#define SYNTHBT1_LOCALSYNTHCAL_LSB                                   3
#define SYNTHBT1_LOCALSYNTHCAL_MASK                                  0x00000008
#define SYNTHBT1_LOCALSYNTHCAL_GET(x)                                (((x) & SYNTHBT1_LOCALSYNTHCAL_MASK) >> SYNTHBT1_LOCALSYNTHCAL_LSB)
#define SYNTHBT1_LOCALSYNTHCAL_SET(x)                                (((0 | (x)) << SYNTHBT1_LOCALSYNTHCAL_LSB) & SYNTHBT1_LOCALSYNTHCAL_MASK)
#define SYNTHBT1_LOCALSYNTHCAL_RESET                                 0
#define SYNTHBT1_SYNTHCAL_MSB                                        2
#define SYNTHBT1_SYNTHCAL_LSB                                        2
#define SYNTHBT1_SYNTHCAL_MASK                                       0x00000004
#define SYNTHBT1_SYNTHCAL_GET(x)                                     (((x) & SYNTHBT1_SYNTHCAL_MASK) >> SYNTHBT1_SYNTHCAL_LSB)
#define SYNTHBT1_SYNTHCAL_SET(x)                                     (((0 | (x)) << SYNTHBT1_SYNTHCAL_LSB) & SYNTHBT1_SYNTHCAL_MASK)
#define SYNTHBT1_SYNTHCAL_RESET                                      0
#define SYNTHBT1_SPARE1_MSB                                          1
#define SYNTHBT1_SPARE1_LSB                                          0
#define SYNTHBT1_SPARE1_MASK                                         0x00000003
#define SYNTHBT1_SPARE1_GET(x)                                       (((x) & SYNTHBT1_SPARE1_MASK) >> SYNTHBT1_SPARE1_LSB)
#define SYNTHBT1_SPARE1_SET(x)                                       (((0 | (x)) << SYNTHBT1_SPARE1_LSB) & SYNTHBT1_SPARE1_MASK)
#define SYNTHBT1_SPARE1_RESET                                        0
#define SYNTHBT1_ADDRESS                                             0x0000
#define SYNTHBT1_HW_MASK                                             0xffffffff
#define SYNTHBT1_SW_MASK                                             0xffffffff
#define SYNTHBT1_HW_WRITE_MASK                                       0x00000000
#define SYNTHBT1_SW_WRITE_MASK                                       0xffffffff
#define SYNTHBT1_RSTMASK                                             0xffffffff
#define SYNTHBT1_RESET                                               0x01000070

// 0x0004 (SYNTHBT2)
#define SYNTHBT2_FREQ0_MSB                                           31
#define SYNTHBT2_FREQ0_LSB                                           17
#define SYNTHBT2_FREQ0_MASK                                          0xfffe0000
#define SYNTHBT2_FREQ0_GET(x)                                        (((x) & SYNTHBT2_FREQ0_MASK) >> SYNTHBT2_FREQ0_LSB)
#define SYNTHBT2_FREQ0_SET(x)                                        (((0 | (x)) << SYNTHBT2_FREQ0_LSB) & SYNTHBT2_FREQ0_MASK)
#define SYNTHBT2_FREQ0_RESET                                         12224
#define SYNTHBT2_FDIFF16_MSB                                         16
#define SYNTHBT2_FDIFF16_LSB                                         7
#define SYNTHBT2_FDIFF16_MASK                                        0x0001ff80
#define SYNTHBT2_FDIFF16_GET(x)                                      (((x) & SYNTHBT2_FDIFF16_MASK) >> SYNTHBT2_FDIFF16_LSB)
#define SYNTHBT2_FDIFF16_SET(x)                                      (((0 | (x)) << SYNTHBT2_FDIFF16_LSB) & SYNTHBT2_FDIFF16_MASK)
#define SYNTHBT2_FDIFF16_RESET                                       345
#define SYNTHBT2_VCOCAP0_MSB                                         6
#define SYNTHBT2_VCOCAP0_LSB                                         0
#define SYNTHBT2_VCOCAP0_MASK                                        0x0000007f
#define SYNTHBT2_VCOCAP0_GET(x)                                      (((x) & SYNTHBT2_VCOCAP0_MASK) >> SYNTHBT2_VCOCAP0_LSB)
#define SYNTHBT2_VCOCAP0_SET(x)                                      (((0 | (x)) << SYNTHBT2_VCOCAP0_LSB) & SYNTHBT2_VCOCAP0_MASK)
#define SYNTHBT2_VCOCAP0_RESET                                       45
#define SYNTHBT2_ADDRESS                                             0x0004
#define SYNTHBT2_HW_MASK                                             0xffffffff
#define SYNTHBT2_SW_MASK                                             0xffffffff
#define SYNTHBT2_HW_WRITE_MASK                                       0x00000000
#define SYNTHBT2_SW_WRITE_MASK                                       0xffffffff
#define SYNTHBT2_RSTMASK                                             0xffffffff
#define SYNTHBT2_RESET                                               0x5f80acad

// 0x0008 (SYNTHBT3)
#define SYNTHBT3_OVR_CAL_MSB                                         31
#define SYNTHBT3_OVR_CAL_LSB                                         31
#define SYNTHBT3_OVR_CAL_MASK                                        0x80000000
#define SYNTHBT3_OVR_CAL_GET(x)                                      (((x) & SYNTHBT3_OVR_CAL_MASK) >> SYNTHBT3_OVR_CAL_LSB)
#define SYNTHBT3_OVR_CAL_SET(x)                                      (((0 | (x)) << SYNTHBT3_OVR_CAL_LSB) & SYNTHBT3_OVR_CAL_MASK)
#define SYNTHBT3_OVR_CAL_RESET                                       0
#define SYNTHBT3_WAIT_CAL_SETTLE_MSB                                 30
#define SYNTHBT3_WAIT_CAL_SETTLE_LSB                                 25
#define SYNTHBT3_WAIT_CAL_SETTLE_MASK                                0x7e000000
#define SYNTHBT3_WAIT_CAL_SETTLE_GET(x)                              (((x) & SYNTHBT3_WAIT_CAL_SETTLE_MASK) >> SYNTHBT3_WAIT_CAL_SETTLE_LSB)
#define SYNTHBT3_WAIT_CAL_SETTLE_SET(x)                              (((0 | (x)) << SYNTHBT3_WAIT_CAL_SETTLE_LSB) & SYNTHBT3_WAIT_CAL_SETTLE_MASK)
#define SYNTHBT3_WAIT_CAL_SETTLE_RESET                               32
#define SYNTHBT3_WAIT_SHORTR_PWRUP_MSB                               24
#define SYNTHBT3_WAIT_SHORTR_PWRUP_LSB                               19
#define SYNTHBT3_WAIT_SHORTR_PWRUP_MASK                              0x01f80000
#define SYNTHBT3_WAIT_SHORTR_PWRUP_GET(x)                            (((x) & SYNTHBT3_WAIT_SHORTR_PWRUP_MASK) >> SYNTHBT3_WAIT_SHORTR_PWRUP_LSB)
#define SYNTHBT3_WAIT_SHORTR_PWRUP_SET(x)                            (((0 | (x)) << SYNTHBT3_WAIT_SHORTR_PWRUP_LSB) & SYNTHBT3_WAIT_SHORTR_PWRUP_MASK)
#define SYNTHBT3_WAIT_SHORTR_PWRUP_RESET                             32
#define SYNTHBT3_VC_CAL_REF_MSB                                      18
#define SYNTHBT3_VC_CAL_REF_LSB                                      16
#define SYNTHBT3_VC_CAL_REF_MASK                                     0x00070000
#define SYNTHBT3_VC_CAL_REF_GET(x)                                   (((x) & SYNTHBT3_VC_CAL_REF_MASK) >> SYNTHBT3_VC_CAL_REF_LSB)
#define SYNTHBT3_VC_CAL_REF_SET(x)                                   (((0 | (x)) << SYNTHBT3_VC_CAL_REF_LSB) & SYNTHBT3_VC_CAL_REF_MASK)
#define SYNTHBT3_VC_CAL_REF_RESET                                    0
#define SYNTHBT3_VC_HI_REF_MSB                                       15
#define SYNTHBT3_VC_HI_REF_LSB                                       13
#define SYNTHBT3_VC_HI_REF_MASK                                      0x0000e000
#define SYNTHBT3_VC_HI_REF_GET(x)                                    (((x) & SYNTHBT3_VC_HI_REF_MASK) >> SYNTHBT3_VC_HI_REF_LSB)
#define SYNTHBT3_VC_HI_REF_SET(x)                                    (((0 | (x)) << SYNTHBT3_VC_HI_REF_LSB) & SYNTHBT3_VC_HI_REF_MASK)
#define SYNTHBT3_VC_HI_REF_RESET                                     3
#define SYNTHBT3_VC_MID_REF_MSB                                      12
#define SYNTHBT3_VC_MID_REF_LSB                                      10
#define SYNTHBT3_VC_MID_REF_MASK                                     0x00001c00
#define SYNTHBT3_VC_MID_REF_GET(x)                                   (((x) & SYNTHBT3_VC_MID_REF_MASK) >> SYNTHBT3_VC_MID_REF_LSB)
#define SYNTHBT3_VC_MID_REF_SET(x)                                   (((0 | (x)) << SYNTHBT3_VC_MID_REF_LSB) & SYNTHBT3_VC_MID_REF_MASK)
#define SYNTHBT3_VC_MID_REF_RESET                                    7
#define SYNTHBT3_VC_LOW_REF_MSB                                      9
#define SYNTHBT3_VC_LOW_REF_LSB                                      7
#define SYNTHBT3_VC_LOW_REF_MASK                                     0x00000380
#define SYNTHBT3_VC_LOW_REF_GET(x)                                   (((x) & SYNTHBT3_VC_LOW_REF_MASK) >> SYNTHBT3_VC_LOW_REF_LSB)
#define SYNTHBT3_VC_LOW_REF_SET(x)                                   (((0 | (x)) << SYNTHBT3_VC_LOW_REF_LSB) & SYNTHBT3_VC_LOW_REF_MASK)
#define SYNTHBT3_VC_LOW_REF_RESET                                    4
#define SYNTHBT3_ALWAYS_SHORTR_MSB                                   6
#define SYNTHBT3_ALWAYS_SHORTR_LSB                                   6
#define SYNTHBT3_ALWAYS_SHORTR_MASK                                  0x00000040
#define SYNTHBT3_ALWAYS_SHORTR_GET(x)                                (((x) & SYNTHBT3_ALWAYS_SHORTR_MASK) >> SYNTHBT3_ALWAYS_SHORTR_LSB)
#define SYNTHBT3_ALWAYS_SHORTR_SET(x)                                (((0 | (x)) << SYNTHBT3_ALWAYS_SHORTR_LSB) & SYNTHBT3_ALWAYS_SHORTR_MASK)
#define SYNTHBT3_ALWAYS_SHORTR_RESET                                 0
#define SYNTHBT3_SHORTR_DURING_CAL_MSB                               5
#define SYNTHBT3_SHORTR_DURING_CAL_LSB                               5
#define SYNTHBT3_SHORTR_DURING_CAL_MASK                              0x00000020
#define SYNTHBT3_SHORTR_DURING_CAL_GET(x)                            (((x) & SYNTHBT3_SHORTR_DURING_CAL_MASK) >> SYNTHBT3_SHORTR_DURING_CAL_LSB)
#define SYNTHBT3_SHORTR_DURING_CAL_SET(x)                            (((0 | (x)) << SYNTHBT3_SHORTR_DURING_CAL_LSB) & SYNTHBT3_SHORTR_DURING_CAL_MASK)
#define SYNTHBT3_SHORTR_DURING_CAL_RESET                             1
#define SYNTHBT3_DIS_CLK_XTAL_MSB                                    4
#define SYNTHBT3_DIS_CLK_XTAL_LSB                                    4
#define SYNTHBT3_DIS_CLK_XTAL_MASK                                   0x00000010
#define SYNTHBT3_DIS_CLK_XTAL_GET(x)                                 (((x) & SYNTHBT3_DIS_CLK_XTAL_MASK) >> SYNTHBT3_DIS_CLK_XTAL_LSB)
#define SYNTHBT3_DIS_CLK_XTAL_SET(x)                                 (((0 | (x)) << SYNTHBT3_DIS_CLK_XTAL_LSB) & SYNTHBT3_DIS_CLK_XTAL_MASK)
#define SYNTHBT3_DIS_CLK_XTAL_RESET                                  0
#define SYNTHBT3_FORCE_PINVC_MSB                                     3
#define SYNTHBT3_FORCE_PINVC_LSB                                     3
#define SYNTHBT3_FORCE_PINVC_MASK                                    0x00000008
#define SYNTHBT3_FORCE_PINVC_GET(x)                                  (((x) & SYNTHBT3_FORCE_PINVC_MASK) >> SYNTHBT3_FORCE_PINVC_LSB)
#define SYNTHBT3_FORCE_PINVC_SET(x)                                  (((0 | (x)) << SYNTHBT3_FORCE_PINVC_LSB) & SYNTHBT3_FORCE_PINVC_MASK)
#define SYNTHBT3_FORCE_PINVC_RESET                                   0
#define SYNTHBT3_SDM_DISABLE_MSB                                     2
#define SYNTHBT3_SDM_DISABLE_LSB                                     2
#define SYNTHBT3_SDM_DISABLE_MASK                                    0x00000004
#define SYNTHBT3_SDM_DISABLE_GET(x)                                  (((x) & SYNTHBT3_SDM_DISABLE_MASK) >> SYNTHBT3_SDM_DISABLE_LSB)
#define SYNTHBT3_SDM_DISABLE_SET(x)                                  (((0 | (x)) << SYNTHBT3_SDM_DISABLE_LSB) & SYNTHBT3_SDM_DISABLE_MASK)
#define SYNTHBT3_SDM_DISABLE_RESET                                   0
#define SYNTHBT3_SDM_DITHER_MSB                                      1
#define SYNTHBT3_SDM_DITHER_LSB                                      0
#define SYNTHBT3_SDM_DITHER_MASK                                     0x00000003
#define SYNTHBT3_SDM_DITHER_GET(x)                                   (((x) & SYNTHBT3_SDM_DITHER_MASK) >> SYNTHBT3_SDM_DITHER_LSB)
#define SYNTHBT3_SDM_DITHER_SET(x)                                   (((0 | (x)) << SYNTHBT3_SDM_DITHER_LSB) & SYNTHBT3_SDM_DITHER_MASK)
#define SYNTHBT3_SDM_DITHER_RESET                                    0
#define SYNTHBT3_ADDRESS                                             0x0008
#define SYNTHBT3_HW_MASK                                             0xffffffff
#define SYNTHBT3_SW_MASK                                             0xffffffff
#define SYNTHBT3_HW_WRITE_MASK                                       0x00000000
#define SYNTHBT3_SW_WRITE_MASK                                       0xffffffff
#define SYNTHBT3_RSTMASK                                             0xffffffff
#define SYNTHBT3_RESET                                               0x41007e20

// 0x000c (SYNTHBT4)
#define SYNTHBT4_FORCE_VCOCAP_MSB                                    31
#define SYNTHBT4_FORCE_VCOCAP_LSB                                    31
#define SYNTHBT4_FORCE_VCOCAP_MASK                                   0x80000000
#define SYNTHBT4_FORCE_VCOCAP_GET(x)                                 (((x) & SYNTHBT4_FORCE_VCOCAP_MASK) >> SYNTHBT4_FORCE_VCOCAP_LSB)
#define SYNTHBT4_FORCE_VCOCAP_SET(x)                                 (((0 | (x)) << SYNTHBT4_FORCE_VCOCAP_LSB) & SYNTHBT4_FORCE_VCOCAP_MASK)
#define SYNTHBT4_FORCE_VCOCAP_RESET                                  0
#define SYNTHBT4_VCOCAP_OVR_MSB                                      30
#define SYNTHBT4_VCOCAP_OVR_LSB                                      24
#define SYNTHBT4_VCOCAP_OVR_MASK                                     0x7f000000
#define SYNTHBT4_VCOCAP_OVR_GET(x)                                   (((x) & SYNTHBT4_VCOCAP_OVR_MASK) >> SYNTHBT4_VCOCAP_OVR_LSB)
#define SYNTHBT4_VCOCAP_OVR_SET(x)                                   (((0 | (x)) << SYNTHBT4_VCOCAP_OVR_LSB) & SYNTHBT4_VCOCAP_OVR_MASK)
#define SYNTHBT4_VCOCAP_OVR_RESET                                    64
#define SYNTHBT4_SYNTHON_ST_MSB                                      23
#define SYNTHBT4_SYNTHON_ST_LSB                                      23
#define SYNTHBT4_SYNTHON_ST_MASK                                     0x00800000
#define SYNTHBT4_SYNTHON_ST_GET(x)                                   (((x) & SYNTHBT4_SYNTHON_ST_MASK) >> SYNTHBT4_SYNTHON_ST_LSB)
#define SYNTHBT4_SYNTHON_ST_SET(x)                                   (((0 | (x)) << SYNTHBT4_SYNTHON_ST_LSB) & SYNTHBT4_SYNTHON_ST_MASK)
#define SYNTHBT4_SYNTHON_ST_RESET                                    0
#define SYNTHBT4_SYNTHCAL_ST_MSB                                     22
#define SYNTHBT4_SYNTHCAL_ST_LSB                                     22
#define SYNTHBT4_SYNTHCAL_ST_MASK                                    0x00400000
#define SYNTHBT4_SYNTHCAL_ST_GET(x)                                  (((x) & SYNTHBT4_SYNTHCAL_ST_MASK) >> SYNTHBT4_SYNTHCAL_ST_LSB)
#define SYNTHBT4_SYNTHCAL_ST_SET(x)                                  (((0 | (x)) << SYNTHBT4_SYNTHCAL_ST_LSB) & SYNTHBT4_SYNTHCAL_ST_MASK)
#define SYNTHBT4_SYNTHCAL_ST_RESET                                   0
#define SYNTHBT4_SYNTH_SM_STATE_MSB                                  21
#define SYNTHBT4_SYNTH_SM_STATE_LSB                                  19
#define SYNTHBT4_SYNTH_SM_STATE_MASK                                 0x00380000
#define SYNTHBT4_SYNTH_SM_STATE_GET(x)                               (((x) & SYNTHBT4_SYNTH_SM_STATE_MASK) >> SYNTHBT4_SYNTH_SM_STATE_LSB)
#define SYNTHBT4_SYNTH_SM_STATE_SET(x)                               (((0 | (x)) << SYNTHBT4_SYNTH_SM_STATE_LSB) & SYNTHBT4_SYNTH_SM_STATE_MASK)
#define SYNTHBT4_SYNTH_SM_STATE_RESET                                0
#define SYNTHBT4_PIN_VC_MSB                                          18
#define SYNTHBT4_PIN_VC_LSB                                          18
#define SYNTHBT4_PIN_VC_MASK                                         0x00040000
#define SYNTHBT4_PIN_VC_GET(x)                                       (((x) & SYNTHBT4_PIN_VC_MASK) >> SYNTHBT4_PIN_VC_LSB)
#define SYNTHBT4_PIN_VC_SET(x)                                       (((0 | (x)) << SYNTHBT4_PIN_VC_LSB) & SYNTHBT4_PIN_VC_MASK)
#define SYNTHBT4_PIN_VC_RESET                                        0
#define SYNTHBT4_SHORT_R_MSB                                         17
#define SYNTHBT4_SHORT_R_LSB                                         17
#define SYNTHBT4_SHORT_R_MASK                                        0x00020000
#define SYNTHBT4_SHORT_R_GET(x)                                      (((x) & SYNTHBT4_SHORT_R_MASK) >> SYNTHBT4_SHORT_R_LSB)
#define SYNTHBT4_SHORT_R_SET(x)                                      (((0 | (x)) << SYNTHBT4_SHORT_R_LSB) & SYNTHBT4_SHORT_R_MASK)
#define SYNTHBT4_SHORT_R_RESET                                       0
#define SYNTHBT4_RESET_RFD_MSB                                       16
#define SYNTHBT4_RESET_RFD_LSB                                       16
#define SYNTHBT4_RESET_RFD_MASK                                      0x00010000
#define SYNTHBT4_RESET_RFD_GET(x)                                    (((x) & SYNTHBT4_RESET_RFD_MASK) >> SYNTHBT4_RESET_RFD_LSB)
#define SYNTHBT4_RESET_RFD_SET(x)                                    (((0 | (x)) << SYNTHBT4_RESET_RFD_LSB) & SYNTHBT4_RESET_RFD_MASK)
#define SYNTHBT4_RESET_RFD_RESET                                     0
#define SYNTHBT4_RESET_PFD_MSB                                       15
#define SYNTHBT4_RESET_PFD_LSB                                       15
#define SYNTHBT4_RESET_PFD_MASK                                      0x00008000
#define SYNTHBT4_RESET_PFD_GET(x)                                    (((x) & SYNTHBT4_RESET_PFD_MASK) >> SYNTHBT4_RESET_PFD_LSB)
#define SYNTHBT4_RESET_PFD_SET(x)                                    (((0 | (x)) << SYNTHBT4_RESET_PFD_LSB) & SYNTHBT4_RESET_PFD_MASK)
#define SYNTHBT4_RESET_PFD_RESET                                     0
#define SYNTHBT4_RESET_PSCOUNTERS_MSB                                14
#define SYNTHBT4_RESET_PSCOUNTERS_LSB                                14
#define SYNTHBT4_RESET_PSCOUNTERS_MASK                               0x00004000
#define SYNTHBT4_RESET_PSCOUNTERS_GET(x)                             (((x) & SYNTHBT4_RESET_PSCOUNTERS_MASK) >> SYNTHBT4_RESET_PSCOUNTERS_LSB)
#define SYNTHBT4_RESET_PSCOUNTERS_SET(x)                             (((0 | (x)) << SYNTHBT4_RESET_PSCOUNTERS_LSB) & SYNTHBT4_RESET_PSCOUNTERS_MASK)
#define SYNTHBT4_RESET_PSCOUNTERS_RESET                              0
#define SYNTHBT4_RESET_SDM_B_MSB                                     13
#define SYNTHBT4_RESET_SDM_B_LSB                                     13
#define SYNTHBT4_RESET_SDM_B_MASK                                    0x00002000
#define SYNTHBT4_RESET_SDM_B_GET(x)                                  (((x) & SYNTHBT4_RESET_SDM_B_MASK) >> SYNTHBT4_RESET_SDM_B_LSB)
#define SYNTHBT4_RESET_SDM_B_SET(x)                                  (((0 | (x)) << SYNTHBT4_RESET_SDM_B_LSB) & SYNTHBT4_RESET_SDM_B_MASK)
#define SYNTHBT4_RESET_SDM_B_RESET                                   0
#define SYNTHBT4_VCO_CAP_ST_MSB                                      12
#define SYNTHBT4_VCO_CAP_ST_LSB                                      6
#define SYNTHBT4_VCO_CAP_ST_MASK                                     0x00001fc0
#define SYNTHBT4_VCO_CAP_ST_GET(x)                                   (((x) & SYNTHBT4_VCO_CAP_ST_MASK) >> SYNTHBT4_VCO_CAP_ST_LSB)
#define SYNTHBT4_VCO_CAP_ST_SET(x)                                   (((0 | (x)) << SYNTHBT4_VCO_CAP_ST_LSB) & SYNTHBT4_VCO_CAP_ST_MASK)
#define SYNTHBT4_VCO_CAP_ST_RESET                                    0
#define SYNTHBT4_SPARE4_MSB                                          5
#define SYNTHBT4_SPARE4_LSB                                          0
#define SYNTHBT4_SPARE4_MASK                                         0x0000003f
#define SYNTHBT4_SPARE4_GET(x)                                       (((x) & SYNTHBT4_SPARE4_MASK) >> SYNTHBT4_SPARE4_LSB)
#define SYNTHBT4_SPARE4_SET(x)                                       (((0 | (x)) << SYNTHBT4_SPARE4_LSB) & SYNTHBT4_SPARE4_MASK)
#define SYNTHBT4_SPARE4_RESET                                        0
#define SYNTHBT4_ADDRESS                                             0x000c
#define SYNTHBT4_HW_MASK                                             0xffffffff
#define SYNTHBT4_SW_MASK                                             0xffffffff
#define SYNTHBT4_HW_WRITE_MASK                                       0x00ffffc0
#define SYNTHBT4_SW_WRITE_MASK                                       0xff00003f
#define SYNTHBT4_RSTMASK                                             0xffffffff
#define SYNTHBT4_RESET                                               0x40000000

// 0x0010 (SYNTHBT5)
#define SYNTHBT5_FREQ0_ST_MSB                                        31
#define SYNTHBT5_FREQ0_ST_LSB                                        17
#define SYNTHBT5_FREQ0_ST_MASK                                       0xfffe0000
#define SYNTHBT5_FREQ0_ST_GET(x)                                     (((x) & SYNTHBT5_FREQ0_ST_MASK) >> SYNTHBT5_FREQ0_ST_LSB)
#define SYNTHBT5_FREQ0_ST_SET(x)                                     (((0 | (x)) << SYNTHBT5_FREQ0_ST_LSB) & SYNTHBT5_FREQ0_ST_MASK)
#define SYNTHBT5_FREQ0_ST_RESET                                      0
#define SYNTHBT5_FDIFF16_ST_MSB                                      16
#define SYNTHBT5_FDIFF16_ST_LSB                                      7
#define SYNTHBT5_FDIFF16_ST_MASK                                     0x0001ff80
#define SYNTHBT5_FDIFF16_ST_GET(x)                                   (((x) & SYNTHBT5_FDIFF16_ST_MASK) >> SYNTHBT5_FDIFF16_ST_LSB)
#define SYNTHBT5_FDIFF16_ST_SET(x)                                   (((0 | (x)) << SYNTHBT5_FDIFF16_ST_LSB) & SYNTHBT5_FDIFF16_ST_MASK)
#define SYNTHBT5_FDIFF16_ST_RESET                                    0
#define SYNTHBT5_VCOCAP0_ST_MSB                                      6
#define SYNTHBT5_VCOCAP0_ST_LSB                                      0
#define SYNTHBT5_VCOCAP0_ST_MASK                                     0x0000007f
#define SYNTHBT5_VCOCAP0_ST_GET(x)                                   (((x) & SYNTHBT5_VCOCAP0_ST_MASK) >> SYNTHBT5_VCOCAP0_ST_LSB)
#define SYNTHBT5_VCOCAP0_ST_SET(x)                                   (((0 | (x)) << SYNTHBT5_VCOCAP0_ST_LSB) & SYNTHBT5_VCOCAP0_ST_MASK)
#define SYNTHBT5_VCOCAP0_ST_RESET                                    0
#define SYNTHBT5_ADDRESS                                             0x0010
#define SYNTHBT5_HW_MASK                                             0xffffffff
#define SYNTHBT5_SW_MASK                                             0xffffffff
#define SYNTHBT5_HW_WRITE_MASK                                       0xffffffff
#define SYNTHBT5_SW_WRITE_MASK                                       0x00000000
#define SYNTHBT5_RSTMASK                                             0xffffffff
#define SYNTHBT5_RESET                                               0x00000000

// 0x0014 (SYNTHBT6)
#define SYNTHBT6_PWDB_IRPFDCP_MSB                                    31
#define SYNTHBT6_PWDB_IRPFDCP_LSB                                    29
#define SYNTHBT6_PWDB_IRPFDCP_MASK                                   0xe0000000
#define SYNTHBT6_PWDB_IRPFDCP_GET(x)                                 (((x) & SYNTHBT6_PWDB_IRPFDCP_MASK) >> SYNTHBT6_PWDB_IRPFDCP_LSB)
#define SYNTHBT6_PWDB_IRPFDCP_SET(x)                                 (((0 | (x)) << SYNTHBT6_PWDB_IRPFDCP_LSB) & SYNTHBT6_PWDB_IRPFDCP_MASK)
#define SYNTHBT6_PWDB_IRPFDCP_RESET                                  4
#define SYNTHBT6_PWDB_IRVCMON25_MSB                                  28
#define SYNTHBT6_PWDB_IRVCMON25_LSB                                  26
#define SYNTHBT6_PWDB_IRVCMON25_MASK                                 0x1c000000
#define SYNTHBT6_PWDB_IRVCMON25_GET(x)                               (((x) & SYNTHBT6_PWDB_IRVCMON25_MASK) >> SYNTHBT6_PWDB_IRVCMON25_LSB)
#define SYNTHBT6_PWDB_IRVCMON25_SET(x)                               (((0 | (x)) << SYNTHBT6_PWDB_IRVCMON25_LSB) & SYNTHBT6_PWDB_IRVCMON25_MASK)
#define SYNTHBT6_PWDB_IRVCMON25_RESET                                4
#define SYNTHBT6_PWDB_ICPRESC50_MSB                                  25
#define SYNTHBT6_PWDB_ICPRESC50_LSB                                  23
#define SYNTHBT6_PWDB_ICPRESC50_MASK                                 0x03800000
#define SYNTHBT6_PWDB_ICPRESC50_GET(x)                               (((x) & SYNTHBT6_PWDB_ICPRESC50_MASK) >> SYNTHBT6_PWDB_ICPRESC50_LSB)
#define SYNTHBT6_PWDB_ICPRESC50_SET(x)                               (((0 | (x)) << SYNTHBT6_PWDB_ICPRESC50_LSB) & SYNTHBT6_PWDB_ICPRESC50_MASK)
#define SYNTHBT6_PWDB_ICPRESC50_RESET                                4
#define SYNTHBT6_PWDB_IRVCOREG50_MSB                                 22
#define SYNTHBT6_PWDB_IRVCOREG50_LSB                                 22
#define SYNTHBT6_PWDB_IRVCOREG50_MASK                                0x00400000
#define SYNTHBT6_PWDB_IRVCOREG50_GET(x)                              (((x) & SYNTHBT6_PWDB_IRVCOREG50_MASK) >> SYNTHBT6_PWDB_IRVCOREG50_LSB)
#define SYNTHBT6_PWDB_IRVCOREG50_SET(x)                              (((0 | (x)) << SYNTHBT6_PWDB_IRVCOREG50_LSB) & SYNTHBT6_PWDB_IRVCOREG50_MASK)
#define SYNTHBT6_PWDB_IRVCOREG50_RESET                               1
#define SYNTHBT6_PWDB_ICVCOREG25_MSB                                 21
#define SYNTHBT6_PWDB_ICVCOREG25_LSB                                 19
#define SYNTHBT6_PWDB_ICVCOREG25_MASK                                0x00380000
#define SYNTHBT6_PWDB_ICVCOREG25_GET(x)                              (((x) & SYNTHBT6_PWDB_ICVCOREG25_MASK) >> SYNTHBT6_PWDB_ICVCOREG25_LSB)
#define SYNTHBT6_PWDB_ICVCOREG25_SET(x)                              (((0 | (x)) << SYNTHBT6_PWDB_ICVCOREG25_LSB) & SYNTHBT6_PWDB_ICVCOREG25_MASK)
#define SYNTHBT6_PWDB_ICVCOREG25_RESET                               4
#define SYNTHBT6_PWDB_ICVCO25_MSB                                    18
#define SYNTHBT6_PWDB_ICVCO25_LSB                                    16
#define SYNTHBT6_PWDB_ICVCO25_MASK                                   0x00070000
#define SYNTHBT6_PWDB_ICVCO25_GET(x)                                 (((x) & SYNTHBT6_PWDB_ICVCO25_MASK) >> SYNTHBT6_PWDB_ICVCO25_LSB)
#define SYNTHBT6_PWDB_ICVCO25_SET(x)                                 (((0 | (x)) << SYNTHBT6_PWDB_ICVCO25_LSB) & SYNTHBT6_PWDB_ICVCO25_MASK)
#define SYNTHBT6_PWDB_ICVCO25_RESET                                  5
#define SYNTHBT6_VCOBIAS_MSB                                         15
#define SYNTHBT6_VCOBIAS_LSB                                         14
#define SYNTHBT6_VCOBIAS_MASK                                        0x0000c000
#define SYNTHBT6_VCOBIAS_GET(x)                                      (((x) & SYNTHBT6_VCOBIAS_MASK) >> SYNTHBT6_VCOBIAS_LSB)
#define SYNTHBT6_VCOBIAS_SET(x)                                      (((0 | (x)) << SYNTHBT6_VCOBIAS_LSB) & SYNTHBT6_VCOBIAS_MASK)
#define SYNTHBT6_VCOBIAS_RESET                                       0
#define SYNTHBT6_PWDB_ICSPARE_MSB                                    13
#define SYNTHBT6_PWDB_ICSPARE_LSB                                    3
#define SYNTHBT6_PWDB_ICSPARE_MASK                                   0x00003ff8
#define SYNTHBT6_PWDB_ICSPARE_GET(x)                                 (((x) & SYNTHBT6_PWDB_ICSPARE_MASK) >> SYNTHBT6_PWDB_ICSPARE_LSB)
#define SYNTHBT6_PWDB_ICSPARE_SET(x)                                 (((0 | (x)) << SYNTHBT6_PWDB_ICSPARE_LSB) & SYNTHBT6_PWDB_ICSPARE_MASK)
#define SYNTHBT6_PWDB_ICSPARE_RESET                                  1194
#define SYNTHBT6_PWDB_IRSPARE_MSB                                    2
#define SYNTHBT6_PWDB_IRSPARE_LSB                                    0
#define SYNTHBT6_PWDB_IRSPARE_MASK                                   0x00000007
#define SYNTHBT6_PWDB_IRSPARE_GET(x)                                 (((x) & SYNTHBT6_PWDB_IRSPARE_MASK) >> SYNTHBT6_PWDB_IRSPARE_LSB)
#define SYNTHBT6_PWDB_IRSPARE_SET(x)                                 (((0 | (x)) << SYNTHBT6_PWDB_IRSPARE_LSB) & SYNTHBT6_PWDB_IRSPARE_MASK)
#define SYNTHBT6_PWDB_IRSPARE_RESET                                  4
#define SYNTHBT6_ADDRESS                                             0x0014
#define SYNTHBT6_HW_MASK                                             0xffffffff
#define SYNTHBT6_SW_MASK                                             0xffffffff
#define SYNTHBT6_HW_WRITE_MASK                                       0x00000000
#define SYNTHBT6_SW_WRITE_MASK                                       0xffffffff
#define SYNTHBT6_RSTMASK                                             0xffffffff
#define SYNTHBT6_RESET                                               0x92652554

// 0x0018 (SYNTHBT7)
#define SYNTHBT7_LOADSYNTHCHANNEL_MSB                                31
#define SYNTHBT7_LOADSYNTHCHANNEL_LSB                                31
#define SYNTHBT7_LOADSYNTHCHANNEL_MASK                               0x80000000
#define SYNTHBT7_LOADSYNTHCHANNEL_GET(x)                             (((x) & SYNTHBT7_LOADSYNTHCHANNEL_MASK) >> SYNTHBT7_LOADSYNTHCHANNEL_LSB)
#define SYNTHBT7_LOADSYNTHCHANNEL_SET(x)                             (((0 | (x)) << SYNTHBT7_LOADSYNTHCHANNEL_LSB) & SYNTHBT7_LOADSYNTHCHANNEL_MASK)
#define SYNTHBT7_LOADSYNTHCHANNEL_RESET                              0
#define SYNTHBT7_CHANSEL_MSB                                         30
#define SYNTHBT7_CHANSEL_LSB                                         22
#define SYNTHBT7_CHANSEL_MASK                                        0x7fc00000
#define SYNTHBT7_CHANSEL_GET(x)                                      (((x) & SYNTHBT7_CHANSEL_MASK) >> SYNTHBT7_CHANSEL_LSB)
#define SYNTHBT7_CHANSEL_SET(x)                                      (((0 | (x)) << SYNTHBT7_CHANSEL_LSB) & SYNTHBT7_CHANSEL_MASK)
#define SYNTHBT7_CHANSEL_RESET                                       184
#define SYNTHBT7_CHANFRAC_MSB                                        21
#define SYNTHBT7_CHANFRAC_LSB                                        5
#define SYNTHBT7_CHANFRAC_MASK                                       0x003fffe0
#define SYNTHBT7_CHANFRAC_GET(x)                                     (((x) & SYNTHBT7_CHANFRAC_MASK) >> SYNTHBT7_CHANFRAC_LSB)
#define SYNTHBT7_CHANFRAC_SET(x)                                     (((0 | (x)) << SYNTHBT7_CHANFRAC_LSB) & SYNTHBT7_CHANFRAC_MASK)
#define SYNTHBT7_CHANFRAC_RESET                                      90742
#define SYNTHBT7_REFDIV_MSB                                          4
#define SYNTHBT7_REFDIV_LSB                                          3
#define SYNTHBT7_REFDIV_MASK                                         0x00000018
#define SYNTHBT7_REFDIV_GET(x)                                       (((x) & SYNTHBT7_REFDIV_MASK) >> SYNTHBT7_REFDIV_LSB)
#define SYNTHBT7_REFDIV_SET(x)                                       (((0 | (x)) << SYNTHBT7_REFDIV_LSB) & SYNTHBT7_REFDIV_MASK)
#define SYNTHBT7_REFDIV_RESET                                        1
#define SYNTHBT7_SPARE7_MSB                                          2
#define SYNTHBT7_SPARE7_LSB                                          0
#define SYNTHBT7_SPARE7_MASK                                         0x00000007
#define SYNTHBT7_SPARE7_GET(x)                                       (((x) & SYNTHBT7_SPARE7_MASK) >> SYNTHBT7_SPARE7_LSB)
#define SYNTHBT7_SPARE7_SET(x)                                       (((0 | (x)) << SYNTHBT7_SPARE7_LSB) & SYNTHBT7_SPARE7_MASK)
#define SYNTHBT7_SPARE7_RESET                                        0
#define SYNTHBT7_ADDRESS                                             0x0018
#define SYNTHBT7_HW_MASK                                             0xffffffff
#define SYNTHBT7_SW_MASK                                             0xffffffff
#define SYNTHBT7_HW_WRITE_MASK                                       0x00000000
#define SYNTHBT7_SW_WRITE_MASK                                       0xffffffff
#define SYNTHBT7_RSTMASK                                             0xffffffff
#define SYNTHBT7_RESET                                               0x2e2c4ec8

// 0x001c (SYNTHBT8)
#define SYNTHBT8_LOOP_3RD_ORDER_R_MSB                                31
#define SYNTHBT8_LOOP_3RD_ORDER_R_LSB                                27
#define SYNTHBT8_LOOP_3RD_ORDER_R_MASK                               0xf8000000
#define SYNTHBT8_LOOP_3RD_ORDER_R_GET(x)                             (((x) & SYNTHBT8_LOOP_3RD_ORDER_R_MASK) >> SYNTHBT8_LOOP_3RD_ORDER_R_LSB)
#define SYNTHBT8_LOOP_3RD_ORDER_R_SET(x)                             (((0 | (x)) << SYNTHBT8_LOOP_3RD_ORDER_R_LSB) & SYNTHBT8_LOOP_3RD_ORDER_R_MASK)
#define SYNTHBT8_LOOP_3RD_ORDER_R_RESET                              26
#define SYNTHBT8_LOOP_CP_MSB                                         26
#define SYNTHBT8_LOOP_CP_LSB                                         22
#define SYNTHBT8_LOOP_CP_MASK                                        0x07c00000
#define SYNTHBT8_LOOP_CP_GET(x)                                      (((x) & SYNTHBT8_LOOP_CP_MASK) >> SYNTHBT8_LOOP_CP_LSB)
#define SYNTHBT8_LOOP_CP_SET(x)                                      (((0 | (x)) << SYNTHBT8_LOOP_CP_LSB) & SYNTHBT8_LOOP_CP_MASK)
#define SYNTHBT8_LOOP_CP_RESET                                       4
#define SYNTHBT8_LOOP_RS_MSB                                         21
#define SYNTHBT8_LOOP_RS_LSB                                         17
#define SYNTHBT8_LOOP_RS_MASK                                        0x003e0000
#define SYNTHBT8_LOOP_RS_GET(x)                                      (((x) & SYNTHBT8_LOOP_RS_MASK) >> SYNTHBT8_LOOP_RS_LSB)
#define SYNTHBT8_LOOP_RS_SET(x)                                      (((0 | (x)) << SYNTHBT8_LOOP_RS_LSB) & SYNTHBT8_LOOP_RS_MASK)
#define SYNTHBT8_LOOP_RS_RESET                                       5
#define SYNTHBT8_LOOP_ICP_MSB                                        16
#define SYNTHBT8_LOOP_ICP_LSB                                        12
#define SYNTHBT8_LOOP_ICP_MASK                                       0x0001f000
#define SYNTHBT8_LOOP_ICP_GET(x)                                     (((x) & SYNTHBT8_LOOP_ICP_MASK) >> SYNTHBT8_LOOP_ICP_LSB)
#define SYNTHBT8_LOOP_ICP_SET(x)                                     (((0 | (x)) << SYNTHBT8_LOOP_ICP_LSB) & SYNTHBT8_LOOP_ICP_MASK)
#define SYNTHBT8_LOOP_ICP_RESET                                      3
#define SYNTHBT8_LOOPLEAKCUR_MSB                                     11
#define SYNTHBT8_LOOPLEAKCUR_LSB                                     8
#define SYNTHBT8_LOOPLEAKCUR_MASK                                    0x00000f00
#define SYNTHBT8_LOOPLEAKCUR_GET(x)                                  (((x) & SYNTHBT8_LOOPLEAKCUR_MASK) >> SYNTHBT8_LOOPLEAKCUR_LSB)
#define SYNTHBT8_LOOPLEAKCUR_SET(x)                                  (((0 | (x)) << SYNTHBT8_LOOPLEAKCUR_LSB) & SYNTHBT8_LOOPLEAKCUR_MASK)
#define SYNTHBT8_LOOPLEAKCUR_RESET                                   0
#define SYNTHBT8_CPBIAS_MSB                                          7
#define SYNTHBT8_CPBIAS_LSB                                          6
#define SYNTHBT8_CPBIAS_MASK                                         0x000000c0
#define SYNTHBT8_CPBIAS_GET(x)                                       (((x) & SYNTHBT8_CPBIAS_MASK) >> SYNTHBT8_CPBIAS_LSB)
#define SYNTHBT8_CPBIAS_SET(x)                                       (((0 | (x)) << SYNTHBT8_CPBIAS_LSB) & SYNTHBT8_CPBIAS_MASK)
#define SYNTHBT8_CPBIAS_RESET                                        3
#define SYNTHBT8_CPLOWLK_MSB                                         5
#define SYNTHBT8_CPLOWLK_LSB                                         5
#define SYNTHBT8_CPLOWLK_MASK                                        0x00000020
#define SYNTHBT8_CPLOWLK_GET(x)                                      (((x) & SYNTHBT8_CPLOWLK_MASK) >> SYNTHBT8_CPLOWLK_LSB)
#define SYNTHBT8_CPLOWLK_SET(x)                                      (((0 | (x)) << SYNTHBT8_CPLOWLK_LSB) & SYNTHBT8_CPLOWLK_MASK)
#define SYNTHBT8_CPLOWLK_RESET                                       0
#define SYNTHBT8_CPSTEERING_EN_MSB                                   4
#define SYNTHBT8_CPSTEERING_EN_LSB                                   4
#define SYNTHBT8_CPSTEERING_EN_MASK                                  0x00000010
#define SYNTHBT8_CPSTEERING_EN_GET(x)                                (((x) & SYNTHBT8_CPSTEERING_EN_MASK) >> SYNTHBT8_CPSTEERING_EN_LSB)
#define SYNTHBT8_CPSTEERING_EN_SET(x)                                (((0 | (x)) << SYNTHBT8_CPSTEERING_EN_LSB) & SYNTHBT8_CPSTEERING_EN_MASK)
#define SYNTHBT8_CPSTEERING_EN_RESET                                 0
#define SYNTHBT8_SPARE8_MSB                                          3
#define SYNTHBT8_SPARE8_LSB                                          0
#define SYNTHBT8_SPARE8_MASK                                         0x0000000f
#define SYNTHBT8_SPARE8_GET(x)                                       (((x) & SYNTHBT8_SPARE8_MASK) >> SYNTHBT8_SPARE8_LSB)
#define SYNTHBT8_SPARE8_SET(x)                                       (((0 | (x)) << SYNTHBT8_SPARE8_LSB) & SYNTHBT8_SPARE8_MASK)
#define SYNTHBT8_SPARE8_RESET                                        0
#define SYNTHBT8_ADDRESS                                             0x001c
#define SYNTHBT8_HW_MASK                                             0xffffffff
#define SYNTHBT8_SW_MASK                                             0xffffffff
#define SYNTHBT8_HW_WRITE_MASK                                       0x00000000
#define SYNTHBT8_SW_WRITE_MASK                                       0xffffffff
#define SYNTHBT8_RSTMASK                                             0xffffffff
#define SYNTHBT8_RESET                                               0xd10a30c0


#endif /* _SYNTHBT_REG_CSR_H_ */
