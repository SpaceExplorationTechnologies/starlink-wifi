//                                                                             
// File:       ./topWLAN_reg_csr.vrh                                           
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:48:20 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             topWLAN_reg_csr.rdl                                             
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/topWLAN_reg.rdl
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


#ifndef _TOPWLAN_REG_CSR_H_
#define _TOPWLAN_REG_CSR_H_
// 0x0000 (PLLCLKMODAWLAN)
#define PLLCLKMODAWLAN_RST_WARM_INT_L_MSB                            31
#define PLLCLKMODAWLAN_RST_WARM_INT_L_LSB                            31
#define PLLCLKMODAWLAN_RST_WARM_INT_L_MASK                           0x80000000
#define PLLCLKMODAWLAN_RST_WARM_INT_L_GET(x)                         (((x) & PLLCLKMODAWLAN_RST_WARM_INT_L_MASK) >> PLLCLKMODAWLAN_RST_WARM_INT_L_LSB)
#define PLLCLKMODAWLAN_RST_WARM_INT_L_SET(x)                         (((0 | (x)) << PLLCLKMODAWLAN_RST_WARM_INT_L_LSB) & PLLCLKMODAWLAN_RST_WARM_INT_L_MASK)
#define PLLCLKMODAWLAN_RST_WARM_INT_L_RESET                          1
#define PLLCLKMODAWLAN_LOCAL_PLLBYPASS_MSB                           30
#define PLLCLKMODAWLAN_LOCAL_PLLBYPASS_LSB                           30
#define PLLCLKMODAWLAN_LOCAL_PLLBYPASS_MASK                          0x40000000
#define PLLCLKMODAWLAN_LOCAL_PLLBYPASS_GET(x)                        (((x) & PLLCLKMODAWLAN_LOCAL_PLLBYPASS_MASK) >> PLLCLKMODAWLAN_LOCAL_PLLBYPASS_LSB)
#define PLLCLKMODAWLAN_LOCAL_PLLBYPASS_SET(x)                        (((0 | (x)) << PLLCLKMODAWLAN_LOCAL_PLLBYPASS_LSB) & PLLCLKMODAWLAN_LOCAL_PLLBYPASS_MASK)
#define PLLCLKMODAWLAN_LOCAL_PLLBYPASS_RESET                         0
#define PLLCLKMODAWLAN_PLLBYPASS_MSB                                 29
#define PLLCLKMODAWLAN_PLLBYPASS_LSB                                 29
#define PLLCLKMODAWLAN_PLLBYPASS_MASK                                0x20000000
#define PLLCLKMODAWLAN_PLLBYPASS_GET(x)                              (((x) & PLLCLKMODAWLAN_PLLBYPASS_MASK) >> PLLCLKMODAWLAN_PLLBYPASS_LSB)
#define PLLCLKMODAWLAN_PLLBYPASS_SET(x)                              (((0 | (x)) << PLLCLKMODAWLAN_PLLBYPASS_LSB) & PLLCLKMODAWLAN_PLLBYPASS_MASK)
#define PLLCLKMODAWLAN_PLLBYPASS_RESET                               0
#define PLLCLKMODAWLAN_PWDPLLREG_MSB                                 28
#define PLLCLKMODAWLAN_PWDPLLREG_LSB                                 28
#define PLLCLKMODAWLAN_PWDPLLREG_MASK                                0x10000000
#define PLLCLKMODAWLAN_PWDPLLREG_GET(x)                              (((x) & PLLCLKMODAWLAN_PWDPLLREG_MASK) >> PLLCLKMODAWLAN_PWDPLLREG_LSB)
#define PLLCLKMODAWLAN_PWDPLLREG_SET(x)                              (((0 | (x)) << PLLCLKMODAWLAN_PWDPLLREG_LSB) & PLLCLKMODAWLAN_PWDPLLREG_MASK)
#define PLLCLKMODAWLAN_PWDPLLREG_RESET                               0
#define PLLCLKMODAWLAN_GLOBAL_CLK_EN_MSB                             27
#define PLLCLKMODAWLAN_GLOBAL_CLK_EN_LSB                             27
#define PLLCLKMODAWLAN_GLOBAL_CLK_EN_MASK                            0x08000000
#define PLLCLKMODAWLAN_GLOBAL_CLK_EN_GET(x)                          (((x) & PLLCLKMODAWLAN_GLOBAL_CLK_EN_MASK) >> PLLCLKMODAWLAN_GLOBAL_CLK_EN_LSB)
#define PLLCLKMODAWLAN_GLOBAL_CLK_EN_SET(x)                          (((0 | (x)) << PLLCLKMODAWLAN_GLOBAL_CLK_EN_LSB) & PLLCLKMODAWLAN_GLOBAL_CLK_EN_MASK)
#define PLLCLKMODAWLAN_GLOBAL_CLK_EN_RESET                           0
#define PLLCLKMODAWLAN_LOCAL_CLKMODA_MSB                             26
#define PLLCLKMODAWLAN_LOCAL_CLKMODA_LSB                             26
#define PLLCLKMODAWLAN_LOCAL_CLKMODA_MASK                            0x04000000
#define PLLCLKMODAWLAN_LOCAL_CLKMODA_GET(x)                          (((x) & PLLCLKMODAWLAN_LOCAL_CLKMODA_MASK) >> PLLCLKMODAWLAN_LOCAL_CLKMODA_LSB)
#define PLLCLKMODAWLAN_LOCAL_CLKMODA_SET(x)                          (((0 | (x)) << PLLCLKMODAWLAN_LOCAL_CLKMODA_LSB) & PLLCLKMODAWLAN_LOCAL_CLKMODA_MASK)
#define PLLCLKMODAWLAN_LOCAL_CLKMODA_RESET                           0
#define PLLCLKMODAWLAN_REFCLK_SEL_MSB                                25
#define PLLCLKMODAWLAN_REFCLK_SEL_LSB                                24
#define PLLCLKMODAWLAN_REFCLK_SEL_MASK                               0x03000000
#define PLLCLKMODAWLAN_REFCLK_SEL_GET(x)                             (((x) & PLLCLKMODAWLAN_REFCLK_SEL_MASK) >> PLLCLKMODAWLAN_REFCLK_SEL_LSB)
#define PLLCLKMODAWLAN_REFCLK_SEL_SET(x)                             (((0 | (x)) << PLLCLKMODAWLAN_REFCLK_SEL_LSB) & PLLCLKMODAWLAN_REFCLK_SEL_MASK)
#define PLLCLKMODAWLAN_REFCLK_SEL_RESET                              0
#define PLLCLKMODAWLAN_FLIP_PLLCLK160_MSB                            23
#define PLLCLKMODAWLAN_FLIP_PLLCLK160_LSB                            23
#define PLLCLKMODAWLAN_FLIP_PLLCLK160_MASK                           0x00800000
#define PLLCLKMODAWLAN_FLIP_PLLCLK160_GET(x)                         (((x) & PLLCLKMODAWLAN_FLIP_PLLCLK160_MASK) >> PLLCLKMODAWLAN_FLIP_PLLCLK160_LSB)
#define PLLCLKMODAWLAN_FLIP_PLLCLK160_SET(x)                         (((0 | (x)) << PLLCLKMODAWLAN_FLIP_PLLCLK160_LSB) & PLLCLKMODAWLAN_FLIP_PLLCLK160_MASK)
#define PLLCLKMODAWLAN_FLIP_PLLCLK160_RESET                          0
#define PLLCLKMODAWLAN_FLIP_PLLCLK320_MSB                            22
#define PLLCLKMODAWLAN_FLIP_PLLCLK320_LSB                            22
#define PLLCLKMODAWLAN_FLIP_PLLCLK320_MASK                           0x00400000
#define PLLCLKMODAWLAN_FLIP_PLLCLK320_GET(x)                         (((x) & PLLCLKMODAWLAN_FLIP_PLLCLK320_MASK) >> PLLCLKMODAWLAN_FLIP_PLLCLK320_LSB)
#define PLLCLKMODAWLAN_FLIP_PLLCLK320_SET(x)                         (((0 | (x)) << PLLCLKMODAWLAN_FLIP_PLLCLK320_LSB) & PLLCLKMODAWLAN_FLIP_PLLCLK320_MASK)
#define PLLCLKMODAWLAN_FLIP_PLLCLK320_RESET                          0
#define PLLCLKMODAWLAN_FLIP_REFCLK40_MSB                             21
#define PLLCLKMODAWLAN_FLIP_REFCLK40_LSB                             21
#define PLLCLKMODAWLAN_FLIP_REFCLK40_MASK                            0x00200000
#define PLLCLKMODAWLAN_FLIP_REFCLK40_GET(x)                          (((x) & PLLCLKMODAWLAN_FLIP_REFCLK40_MASK) >> PLLCLKMODAWLAN_FLIP_REFCLK40_LSB)
#define PLLCLKMODAWLAN_FLIP_REFCLK40_SET(x)                          (((0 | (x)) << PLLCLKMODAWLAN_FLIP_REFCLK40_LSB) & PLLCLKMODAWLAN_FLIP_REFCLK40_MASK)
#define PLLCLKMODAWLAN_FLIP_REFCLK40_RESET                           0
#define PLLCLKMODAWLAN_CLK107_EN_MSB                                 20
#define PLLCLKMODAWLAN_CLK107_EN_LSB                                 20
#define PLLCLKMODAWLAN_CLK107_EN_MASK                                0x00100000
#define PLLCLKMODAWLAN_CLK107_EN_GET(x)                              (((x) & PLLCLKMODAWLAN_CLK107_EN_MASK) >> PLLCLKMODAWLAN_CLK107_EN_LSB)
#define PLLCLKMODAWLAN_CLK107_EN_SET(x)                              (((0 | (x)) << PLLCLKMODAWLAN_CLK107_EN_LSB) & PLLCLKMODAWLAN_CLK107_EN_MASK)
#define PLLCLKMODAWLAN_CLK107_EN_RESET                               1
#define PLLCLKMODAWLAN_EXTCLK_EN_MSB                                 19
#define PLLCLKMODAWLAN_EXTCLK_EN_LSB                                 19
#define PLLCLKMODAWLAN_EXTCLK_EN_MASK                                0x00080000
#define PLLCLKMODAWLAN_EXTCLK_EN_GET(x)                              (((x) & PLLCLKMODAWLAN_EXTCLK_EN_MASK) >> PLLCLKMODAWLAN_EXTCLK_EN_LSB)
#define PLLCLKMODAWLAN_EXTCLK_EN_SET(x)                              (((0 | (x)) << PLLCLKMODAWLAN_EXTCLK_EN_LSB) & PLLCLKMODAWLAN_EXTCLK_EN_MASK)
#define PLLCLKMODAWLAN_EXTCLK_EN_RESET                               0
#define PLLCLKMODAWLAN_PWDLPO_WLAN_MSB                               18
#define PLLCLKMODAWLAN_PWDLPO_WLAN_LSB                               18
#define PLLCLKMODAWLAN_PWDLPO_WLAN_MASK                              0x00040000
#define PLLCLKMODAWLAN_PWDLPO_WLAN_GET(x)                            (((x) & PLLCLKMODAWLAN_PWDLPO_WLAN_MASK) >> PLLCLKMODAWLAN_PWDLPO_WLAN_LSB)
#define PLLCLKMODAWLAN_PWDLPO_WLAN_SET(x)                            (((0 | (x)) << PLLCLKMODAWLAN_PWDLPO_WLAN_LSB) & PLLCLKMODAWLAN_PWDLPO_WLAN_MASK)
#define PLLCLKMODAWLAN_PWDLPO_WLAN_RESET                             0
#define PLLCLKMODAWLAN_RBIAS_OUT_MSB                                 17
#define PLLCLKMODAWLAN_RBIAS_OUT_LSB                                 12
#define PLLCLKMODAWLAN_RBIAS_OUT_MASK                                0x0003f000
#define PLLCLKMODAWLAN_RBIAS_OUT_GET(x)                              (((x) & PLLCLKMODAWLAN_RBIAS_OUT_MASK) >> PLLCLKMODAWLAN_RBIAS_OUT_LSB)
#define PLLCLKMODAWLAN_RBIAS_OUT_SET(x)                              (((0 | (x)) << PLLCLKMODAWLAN_RBIAS_OUT_LSB) & PLLCLKMODAWLAN_RBIAS_OUT_MASK)
#define PLLCLKMODAWLAN_RBIAS_OUT_RESET                               0
#define PLLCLKMODAWLAN_XLNAON_MSB                                    11
#define PLLCLKMODAWLAN_XLNAON_LSB                                    10
#define PLLCLKMODAWLAN_XLNAON_MASK                                   0x00000c00
#define PLLCLKMODAWLAN_XLNAON_GET(x)                                 (((x) & PLLCLKMODAWLAN_XLNAON_MASK) >> PLLCLKMODAWLAN_XLNAON_LSB)
#define PLLCLKMODAWLAN_XLNAON_SET(x)                                 (((0 | (x)) << PLLCLKMODAWLAN_XLNAON_LSB) & PLLCLKMODAWLAN_XLNAON_MASK)
#define PLLCLKMODAWLAN_XLNAON_RESET                                  0
#define PLLCLKMODAWLAN_XLNA2ON_0_MSB                                 9
#define PLLCLKMODAWLAN_XLNA2ON_0_LSB                                 9
#define PLLCLKMODAWLAN_XLNA2ON_0_MASK                                0x00000200
#define PLLCLKMODAWLAN_XLNA2ON_0_GET(x)                              (((x) & PLLCLKMODAWLAN_XLNA2ON_0_MASK) >> PLLCLKMODAWLAN_XLNA2ON_0_LSB)
#define PLLCLKMODAWLAN_XLNA2ON_0_SET(x)                              (((0 | (x)) << PLLCLKMODAWLAN_XLNA2ON_0_LSB) & PLLCLKMODAWLAN_XLNA2ON_0_MASK)
#define PLLCLKMODAWLAN_XLNA2ON_0_RESET                               0
#define PLLCLKMODAWLAN_XLNA5ON_0_MSB                                 8
#define PLLCLKMODAWLAN_XLNA5ON_0_LSB                                 8
#define PLLCLKMODAWLAN_XLNA5ON_0_MASK                                0x00000100
#define PLLCLKMODAWLAN_XLNA5ON_0_GET(x)                              (((x) & PLLCLKMODAWLAN_XLNA5ON_0_MASK) >> PLLCLKMODAWLAN_XLNA5ON_0_LSB)
#define PLLCLKMODAWLAN_XLNA5ON_0_SET(x)                              (((0 | (x)) << PLLCLKMODAWLAN_XLNA5ON_0_LSB) & PLLCLKMODAWLAN_XLNA5ON_0_MASK)
#define PLLCLKMODAWLAN_XLNA5ON_0_RESET                               0
#define PLLCLKMODAWLAN_XLNAON_OVR_MSB                                7
#define PLLCLKMODAWLAN_XLNAON_OVR_LSB                                7
#define PLLCLKMODAWLAN_XLNAON_OVR_MASK                               0x00000080
#define PLLCLKMODAWLAN_XLNAON_OVR_GET(x)                             (((x) & PLLCLKMODAWLAN_XLNAON_OVR_MASK) >> PLLCLKMODAWLAN_XLNAON_OVR_LSB)
#define PLLCLKMODAWLAN_XLNAON_OVR_SET(x)                             (((0 | (x)) << PLLCLKMODAWLAN_XLNAON_OVR_LSB) & PLLCLKMODAWLAN_XLNAON_OVR_MASK)
#define PLLCLKMODAWLAN_XLNAON_OVR_RESET                              0
#define PLLCLKMODAWLAN_PWD_XLNABIAS_MSB                              6
#define PLLCLKMODAWLAN_PWD_XLNABIAS_LSB                              6
#define PLLCLKMODAWLAN_PWD_XLNABIAS_MASK                             0x00000040
#define PLLCLKMODAWLAN_PWD_XLNABIAS_GET(x)                           (((x) & PLLCLKMODAWLAN_PWD_XLNABIAS_MASK) >> PLLCLKMODAWLAN_PWD_XLNABIAS_LSB)
#define PLLCLKMODAWLAN_PWD_XLNABIAS_SET(x)                           (((0 | (x)) << PLLCLKMODAWLAN_PWD_XLNABIAS_LSB) & PLLCLKMODAWLAN_PWD_XLNABIAS_MASK)
#define PLLCLKMODAWLAN_PWD_XLNABIAS_RESET                            0
#define PLLCLKMODAWLAN_XLNA_DRV_STRENGTH_MSB                         5
#define PLLCLKMODAWLAN_XLNA_DRV_STRENGTH_LSB                         4
#define PLLCLKMODAWLAN_XLNA_DRV_STRENGTH_MASK                        0x00000030
#define PLLCLKMODAWLAN_XLNA_DRV_STRENGTH_GET(x)                      (((x) & PLLCLKMODAWLAN_XLNA_DRV_STRENGTH_MASK) >> PLLCLKMODAWLAN_XLNA_DRV_STRENGTH_LSB)
#define PLLCLKMODAWLAN_XLNA_DRV_STRENGTH_SET(x)                      (((0 | (x)) << PLLCLKMODAWLAN_XLNA_DRV_STRENGTH_LSB) & PLLCLKMODAWLAN_XLNA_DRV_STRENGTH_MASK)
#define PLLCLKMODAWLAN_XLNA_DRV_STRENGTH_RESET                       0
#define PLLCLKMODAWLAN_RESERVED_MSB                                  3
#define PLLCLKMODAWLAN_RESERVED_LSB                                  0
#define PLLCLKMODAWLAN_RESERVED_MASK                                 0x0000000f
#define PLLCLKMODAWLAN_RESERVED_GET(x)                               (((x) & PLLCLKMODAWLAN_RESERVED_MASK) >> PLLCLKMODAWLAN_RESERVED_LSB)
#define PLLCLKMODAWLAN_RESERVED_SET(x)                               (((0 | (x)) << PLLCLKMODAWLAN_RESERVED_LSB) & PLLCLKMODAWLAN_RESERVED_MASK)
#define PLLCLKMODAWLAN_RESERVED_RESET                                0
#define PLLCLKMODAWLAN_ADDRESS                                       0x0000
#define PLLCLKMODAWLAN_HW_MASK                                       0xffffffff
#define PLLCLKMODAWLAN_SW_MASK                                       0xffffffff
#define PLLCLKMODAWLAN_HW_WRITE_MASK                                 0x0003f000
#define PLLCLKMODAWLAN_SW_WRITE_MASK                                 0xfffc0fff
#define PLLCLKMODAWLAN_RSTMASK                                       0xffffffff
#define PLLCLKMODAWLAN_RESET                                         0x80100000

// 0x0004 (TOPWLAN1)
#define TOPWLAN1_INT2GND_MSB                                         31
#define TOPWLAN1_INT2GND_LSB                                         31
#define TOPWLAN1_INT2GND_MASK                                        0x80000000
#define TOPWLAN1_INT2GND_GET(x)                                      (((x) & TOPWLAN1_INT2GND_MASK) >> TOPWLAN1_INT2GND_LSB)
#define TOPWLAN1_INT2GND_SET(x)                                      (((0 | (x)) << TOPWLAN1_INT2GND_LSB) & TOPWLAN1_INT2GND_MASK)
#define TOPWLAN1_INT2GND_RESET                                       1
#define TOPWLAN1_INT2PAD_MSB                                         30
#define TOPWLAN1_INT2PAD_LSB                                         30
#define TOPWLAN1_INT2PAD_MASK                                        0x40000000
#define TOPWLAN1_INT2PAD_GET(x)                                      (((x) & TOPWLAN1_INT2PAD_MASK) >> TOPWLAN1_INT2PAD_LSB)
#define TOPWLAN1_INT2PAD_SET(x)                                      (((0 | (x)) << TOPWLAN1_INT2PAD_LSB) & TOPWLAN1_INT2PAD_MASK)
#define TOPWLAN1_INT2PAD_RESET                                       0
#define TOPWLAN1_INTH2GND_MSB                                        29
#define TOPWLAN1_INTH2GND_LSB                                        29
#define TOPWLAN1_INTH2GND_MASK                                       0x20000000
#define TOPWLAN1_INTH2GND_GET(x)                                     (((x) & TOPWLAN1_INTH2GND_MASK) >> TOPWLAN1_INTH2GND_LSB)
#define TOPWLAN1_INTH2GND_SET(x)                                     (((0 | (x)) << TOPWLAN1_INTH2GND_LSB) & TOPWLAN1_INTH2GND_MASK)
#define TOPWLAN1_INTH2GND_RESET                                      1
#define TOPWLAN1_INTH2PAD_MSB                                        28
#define TOPWLAN1_INTH2PAD_LSB                                        28
#define TOPWLAN1_INTH2PAD_MASK                                       0x10000000
#define TOPWLAN1_INTH2PAD_GET(x)                                     (((x) & TOPWLAN1_INTH2PAD_MASK) >> TOPWLAN1_INTH2PAD_LSB)
#define TOPWLAN1_INTH2PAD_SET(x)                                     (((0 | (x)) << TOPWLAN1_INTH2PAD_LSB) & TOPWLAN1_INTH2PAD_MASK)
#define TOPWLAN1_INTH2PAD_RESET                                      0
#define TOPWLAN1_PAD2GND_MSB                                         27
#define TOPWLAN1_PAD2GND_LSB                                         27
#define TOPWLAN1_PAD2GND_MASK                                        0x08000000
#define TOPWLAN1_PAD2GND_GET(x)                                      (((x) & TOPWLAN1_PAD2GND_MASK) >> TOPWLAN1_PAD2GND_LSB)
#define TOPWLAN1_PAD2GND_SET(x)                                      (((0 | (x)) << TOPWLAN1_PAD2GND_LSB) & TOPWLAN1_PAD2GND_MASK)
#define TOPWLAN1_PAD2GND_RESET                                       0
#define TOPWLAN1_AIOPADMUXEN_MSB                                     26
#define TOPWLAN1_AIOPADMUXEN_LSB                                     26
#define TOPWLAN1_AIOPADMUXEN_MASK                                    0x04000000
#define TOPWLAN1_AIOPADMUXEN_GET(x)                                  (((x) & TOPWLAN1_AIOPADMUXEN_MASK) >> TOPWLAN1_AIOPADMUXEN_LSB)
#define TOPWLAN1_AIOPADMUXEN_SET(x)                                  (((0 | (x)) << TOPWLAN1_AIOPADMUXEN_LSB) & TOPWLAN1_AIOPADMUXEN_MASK)
#define TOPWLAN1_AIOPADMUXEN_RESET                                   0
#define TOPWLAN1_PWDBIAS_MSB                                         25
#define TOPWLAN1_PWDBIAS_LSB                                         25
#define TOPWLAN1_PWDBIAS_MASK                                        0x02000000
#define TOPWLAN1_PWDBIAS_GET(x)                                      (((x) & TOPWLAN1_PWDBIAS_MASK) >> TOPWLAN1_PWDBIAS_LSB)
#define TOPWLAN1_PWDBIAS_SET(x)                                      (((0 | (x)) << TOPWLAN1_PWDBIAS_LSB) & TOPWLAN1_PWDBIAS_MASK)
#define TOPWLAN1_PWDBIAS_RESET                                       0
#define TOPWLAN1_PWDV2I_MSB                                          24
#define TOPWLAN1_PWDV2I_LSB                                          24
#define TOPWLAN1_PWDV2I_MASK                                         0x01000000
#define TOPWLAN1_PWDV2I_GET(x)                                       (((x) & TOPWLAN1_PWDV2I_MASK) >> TOPWLAN1_PWDV2I_LSB)
#define TOPWLAN1_PWDV2I_SET(x)                                       (((0 | (x)) << TOPWLAN1_PWDV2I_LSB) & TOPWLAN1_PWDV2I_MASK)
#define TOPWLAN1_PWDV2I_RESET                                        0
#define TOPWLAN1_LOCAL_XPAON_MSB                                     23
#define TOPWLAN1_LOCAL_XPAON_LSB                                     23
#define TOPWLAN1_LOCAL_XPAON_MASK                                    0x00800000
#define TOPWLAN1_LOCAL_XPAON_GET(x)                                  (((x) & TOPWLAN1_LOCAL_XPAON_MASK) >> TOPWLAN1_LOCAL_XPAON_LSB)
#define TOPWLAN1_LOCAL_XPAON_SET(x)                                  (((0 | (x)) << TOPWLAN1_LOCAL_XPAON_LSB) & TOPWLAN1_LOCAL_XPAON_MASK)
#define TOPWLAN1_LOCAL_XPAON_RESET                                   0
#define TOPWLAN1_XPA2ON_MSB                                          22
#define TOPWLAN1_XPA2ON_LSB                                          20
#define TOPWLAN1_XPA2ON_MASK                                         0x00700000
#define TOPWLAN1_XPA2ON_GET(x)                                       (((x) & TOPWLAN1_XPA2ON_MASK) >> TOPWLAN1_XPA2ON_LSB)
#define TOPWLAN1_XPA2ON_SET(x)                                       (((0 | (x)) << TOPWLAN1_XPA2ON_LSB) & TOPWLAN1_XPA2ON_MASK)
#define TOPWLAN1_XPA2ON_RESET                                        0
#define TOPWLAN1_XPA5ON_MSB                                          19
#define TOPWLAN1_XPA5ON_LSB                                          17
#define TOPWLAN1_XPA5ON_MASK                                         0x000e0000
#define TOPWLAN1_XPA5ON_GET(x)                                       (((x) & TOPWLAN1_XPA5ON_MASK) >> TOPWLAN1_XPA5ON_LSB)
#define TOPWLAN1_XPA5ON_SET(x)                                       (((0 | (x)) << TOPWLAN1_XPA5ON_LSB) & TOPWLAN1_XPA5ON_MASK)
#define TOPWLAN1_XPA5ON_RESET                                        0
#define TOPWLAN1_XPASHORT2GND_MSB                                    16
#define TOPWLAN1_XPASHORT2GND_LSB                                    16
#define TOPWLAN1_XPASHORT2GND_MASK                                   0x00010000
#define TOPWLAN1_XPASHORT2GND_GET(x)                                 (((x) & TOPWLAN1_XPASHORT2GND_MASK) >> TOPWLAN1_XPASHORT2GND_LSB)
#define TOPWLAN1_XPASHORT2GND_SET(x)                                 (((0 | (x)) << TOPWLAN1_XPASHORT2GND_LSB) & TOPWLAN1_XPASHORT2GND_MASK)
#define TOPWLAN1_XPASHORT2GND_RESET                                  1
#define TOPWLAN1_XPABIAS_BYPASS_MSB                                  15
#define TOPWLAN1_XPABIAS_BYPASS_LSB                                  15
#define TOPWLAN1_XPABIAS_BYPASS_MASK                                 0x00008000
#define TOPWLAN1_XPABIAS_BYPASS_GET(x)                               (((x) & TOPWLAN1_XPABIAS_BYPASS_MASK) >> TOPWLAN1_XPABIAS_BYPASS_LSB)
#define TOPWLAN1_XPABIAS_BYPASS_SET(x)                               (((0 | (x)) << TOPWLAN1_XPABIAS_BYPASS_LSB) & TOPWLAN1_XPABIAS_BYPASS_MASK)
#define TOPWLAN1_XPABIAS_BYPASS_RESET                                0
#define TOPWLAN1_XPAREGULATOR_EN_MSB                                 14
#define TOPWLAN1_XPAREGULATOR_EN_LSB                                 14
#define TOPWLAN1_XPAREGULATOR_EN_MASK                                0x00004000
#define TOPWLAN1_XPAREGULATOR_EN_GET(x)                              (((x) & TOPWLAN1_XPAREGULATOR_EN_MASK) >> TOPWLAN1_XPAREGULATOR_EN_LSB)
#define TOPWLAN1_XPAREGULATOR_EN_SET(x)                              (((0 | (x)) << TOPWLAN1_XPAREGULATOR_EN_LSB) & TOPWLAN1_XPAREGULATOR_EN_MASK)
#define TOPWLAN1_XPAREGULATOR_EN_RESET                               1
#define TOPWLAN1_XPABIASLVL_MSB                                      13
#define TOPWLAN1_XPABIASLVL_LSB                                      10
#define TOPWLAN1_XPABIASLVL_MASK                                     0x00003c00
#define TOPWLAN1_XPABIASLVL_GET(x)                                   (((x) & TOPWLAN1_XPABIASLVL_MASK) >> TOPWLAN1_XPABIASLVL_LSB)
#define TOPWLAN1_XPABIASLVL_SET(x)                                   (((0 | (x)) << TOPWLAN1_XPABIASLVL_LSB) & TOPWLAN1_XPABIASLVL_MASK)
#define TOPWLAN1_XPABIASLVL_RESET                                    0
#define TOPWLAN1_XPABIAS_ATBSELECT_MSB                               9
#define TOPWLAN1_XPABIAS_ATBSELECT_LSB                               9
#define TOPWLAN1_XPABIAS_ATBSELECT_MASK                              0x00000200
#define TOPWLAN1_XPABIAS_ATBSELECT_GET(x)                            (((x) & TOPWLAN1_XPABIAS_ATBSELECT_MASK) >> TOPWLAN1_XPABIAS_ATBSELECT_LSB)
#define TOPWLAN1_XPABIAS_ATBSELECT_SET(x)                            (((0 | (x)) << TOPWLAN1_XPABIAS_ATBSELECT_LSB) & TOPWLAN1_XPABIAS_ATBSELECT_MASK)
#define TOPWLAN1_XPABIAS_ATBSELECT_RESET                             0
#define TOPWLAN1_USE_WLAN_SETTING_MSB                                8
#define TOPWLAN1_USE_WLAN_SETTING_LSB                                8
#define TOPWLAN1_USE_WLAN_SETTING_MASK                               0x00000100
#define TOPWLAN1_USE_WLAN_SETTING_GET(x)                             (((x) & TOPWLAN1_USE_WLAN_SETTING_MASK) >> TOPWLAN1_USE_WLAN_SETTING_LSB)
#define TOPWLAN1_USE_WLAN_SETTING_SET(x)                             (((0 | (x)) << TOPWLAN1_USE_WLAN_SETTING_LSB) & TOPWLAN1_USE_WLAN_SETTING_MASK)
#define TOPWLAN1_USE_WLAN_SETTING_RESET                              0
#define TOPWLAN1_LOCALRBIAS_MSB                                      7
#define TOPWLAN1_LOCALRBIAS_LSB                                      7
#define TOPWLAN1_LOCALRBIAS_MASK                                     0x00000080
#define TOPWLAN1_LOCALRBIAS_GET(x)                                   (((x) & TOPWLAN1_LOCALRBIAS_MASK) >> TOPWLAN1_LOCALRBIAS_LSB)
#define TOPWLAN1_LOCALRBIAS_SET(x)                                   (((0 | (x)) << TOPWLAN1_LOCALRBIAS_LSB) & TOPWLAN1_LOCALRBIAS_MASK)
#define TOPWLAN1_LOCALRBIAS_RESET                                    0
#define TOPWLAN1_RBIAS_MSB                                           6
#define TOPWLAN1_RBIAS_LSB                                           1
#define TOPWLAN1_RBIAS_MASK                                          0x0000007e
#define TOPWLAN1_RBIAS_GET(x)                                        (((x) & TOPWLAN1_RBIAS_MASK) >> TOPWLAN1_RBIAS_LSB)
#define TOPWLAN1_RBIAS_SET(x)                                        (((0 | (x)) << TOPWLAN1_RBIAS_LSB) & TOPWLAN1_RBIAS_MASK)
#define TOPWLAN1_RBIAS_RESET                                         0
#define TOPWLAN1_RESERVED_MSB                                        0
#define TOPWLAN1_RESERVED_LSB                                        0
#define TOPWLAN1_RESERVED_MASK                                       0x00000001
#define TOPWLAN1_RESERVED_GET(x)                                     (((x) & TOPWLAN1_RESERVED_MASK) >> TOPWLAN1_RESERVED_LSB)
#define TOPWLAN1_RESERVED_SET(x)                                     (((0 | (x)) << TOPWLAN1_RESERVED_LSB) & TOPWLAN1_RESERVED_MASK)
#define TOPWLAN1_RESERVED_RESET                                      0
#define TOPWLAN1_ADDRESS                                             0x0004
#define TOPWLAN1_HW_MASK                                             0xffffffff
#define TOPWLAN1_SW_MASK                                             0xffffffff
#define TOPWLAN1_HW_WRITE_MASK                                       0x00000000
#define TOPWLAN1_SW_WRITE_MASK                                       0xffffffff
#define TOPWLAN1_RSTMASK                                             0xffffffff
#define TOPWLAN1_RESET                                               0xa0014000

// 0x0008 (THERMWLAN)
#define THERMWLAN_LOCAL_THERM_MSB                                    31
#define THERMWLAN_LOCAL_THERM_LSB                                    31
#define THERMWLAN_LOCAL_THERM_MASK                                   0x80000000
#define THERMWLAN_LOCAL_THERM_GET(x)                                 (((x) & THERMWLAN_LOCAL_THERM_MASK) >> THERMWLAN_LOCAL_THERM_LSB)
#define THERMWLAN_LOCAL_THERM_SET(x)                                 (((0 | (x)) << THERMWLAN_LOCAL_THERM_LSB) & THERMWLAN_LOCAL_THERM_MASK)
#define THERMWLAN_LOCAL_THERM_RESET                                  0
#define THERMWLAN_SAR_AUTOPWD_EN_MSB                                 30
#define THERMWLAN_SAR_AUTOPWD_EN_LSB                                 30
#define THERMWLAN_SAR_AUTOPWD_EN_MASK                                0x40000000
#define THERMWLAN_SAR_AUTOPWD_EN_GET(x)                              (((x) & THERMWLAN_SAR_AUTOPWD_EN_MASK) >> THERMWLAN_SAR_AUTOPWD_EN_LSB)
#define THERMWLAN_SAR_AUTOPWD_EN_SET(x)                              (((0 | (x)) << THERMWLAN_SAR_AUTOPWD_EN_LSB) & THERMWLAN_SAR_AUTOPWD_EN_MASK)
#define THERMWLAN_SAR_AUTOPWD_EN_RESET                               0
#define THERMWLAN_THERMSTART_MSB                                     29
#define THERMWLAN_THERMSTART_LSB                                     29
#define THERMWLAN_THERMSTART_MASK                                    0x20000000
#define THERMWLAN_THERMSTART_GET(x)                                  (((x) & THERMWLAN_THERMSTART_MASK) >> THERMWLAN_THERMSTART_LSB)
#define THERMWLAN_THERMSTART_SET(x)                                  (((0 | (x)) << THERMWLAN_THERMSTART_LSB) & THERMWLAN_THERMSTART_MASK)
#define THERMWLAN_THERMSTART_RESET                                   0
#define THERMWLAN_SAR_SLOW_EN_MSB                                    28
#define THERMWLAN_SAR_SLOW_EN_LSB                                    28
#define THERMWLAN_SAR_SLOW_EN_MASK                                   0x10000000
#define THERMWLAN_SAR_SLOW_EN_GET(x)                                 (((x) & THERMWLAN_SAR_SLOW_EN_MASK) >> THERMWLAN_SAR_SLOW_EN_LSB)
#define THERMWLAN_SAR_SLOW_EN_SET(x)                                 (((0 | (x)) << THERMWLAN_SAR_SLOW_EN_LSB) & THERMWLAN_SAR_SLOW_EN_MASK)
#define THERMWLAN_SAR_SLOW_EN_RESET                                  0
#define THERMWLAN_THERMSEL_MSB                                       27
#define THERMWLAN_THERMSEL_LSB                                       26
#define THERMWLAN_THERMSEL_MASK                                      0x0c000000
#define THERMWLAN_THERMSEL_GET(x)                                    (((x) & THERMWLAN_THERMSEL_MASK) >> THERMWLAN_THERMSEL_LSB)
#define THERMWLAN_THERMSEL_SET(x)                                    (((0 | (x)) << THERMWLAN_THERMSEL_LSB) & THERMWLAN_THERMSEL_MASK)
#define THERMWLAN_THERMSEL_RESET                                     0
#define THERMWLAN_SAR_ADCCAL_EN_MSB                                  25
#define THERMWLAN_SAR_ADCCAL_EN_LSB                                  25
#define THERMWLAN_SAR_ADCCAL_EN_MASK                                 0x02000000
#define THERMWLAN_SAR_ADCCAL_EN_GET(x)                               (((x) & THERMWLAN_SAR_ADCCAL_EN_MASK) >> THERMWLAN_SAR_ADCCAL_EN_LSB)
#define THERMWLAN_SAR_ADCCAL_EN_SET(x)                               (((0 | (x)) << THERMWLAN_SAR_ADCCAL_EN_LSB) & THERMWLAN_SAR_ADCCAL_EN_MASK)
#define THERMWLAN_SAR_ADCCAL_EN_RESET                                0
#define THERMWLAN_SAR_DACTEST_EN_MSB                                 24
#define THERMWLAN_SAR_DACTEST_EN_LSB                                 24
#define THERMWLAN_SAR_DACTEST_EN_MASK                                0x01000000
#define THERMWLAN_SAR_DACTEST_EN_GET(x)                              (((x) & THERMWLAN_SAR_DACTEST_EN_MASK) >> THERMWLAN_SAR_DACTEST_EN_LSB)
#define THERMWLAN_SAR_DACTEST_EN_SET(x)                              (((0 | (x)) << THERMWLAN_SAR_DACTEST_EN_LSB) & THERMWLAN_SAR_DACTEST_EN_MASK)
#define THERMWLAN_SAR_DACTEST_EN_RESET                               0
#define THERMWLAN_SAR_DACTEST_CODE_MSB                               23
#define THERMWLAN_SAR_DACTEST_CODE_LSB                               16
#define THERMWLAN_SAR_DACTEST_CODE_MASK                              0x00ff0000
#define THERMWLAN_SAR_DACTEST_CODE_GET(x)                            (((x) & THERMWLAN_SAR_DACTEST_CODE_MASK) >> THERMWLAN_SAR_DACTEST_CODE_LSB)
#define THERMWLAN_SAR_DACTEST_CODE_SET(x)                            (((0 | (x)) << THERMWLAN_SAR_DACTEST_CODE_LSB) & THERMWLAN_SAR_DACTEST_CODE_MASK)
#define THERMWLAN_SAR_DACTEST_CODE_RESET                             0
#define THERMWLAN_SAR_ADC_OUT_MSB                                    15
#define THERMWLAN_SAR_ADC_OUT_LSB                                    8
#define THERMWLAN_SAR_ADC_OUT_MASK                                   0x0000ff00
#define THERMWLAN_SAR_ADC_OUT_GET(x)                                 (((x) & THERMWLAN_SAR_ADC_OUT_MASK) >> THERMWLAN_SAR_ADC_OUT_LSB)
#define THERMWLAN_SAR_ADC_OUT_SET(x)                                 (((0 | (x)) << THERMWLAN_SAR_ADC_OUT_LSB) & THERMWLAN_SAR_ADC_OUT_MASK)
#define THERMWLAN_SAR_ADC_OUT_RESET                                  0
#define THERMWLAN_SAR_ADC_DONE_MSB                                   7
#define THERMWLAN_SAR_ADC_DONE_LSB                                   7
#define THERMWLAN_SAR_ADC_DONE_MASK                                  0x00000080
#define THERMWLAN_SAR_ADC_DONE_GET(x)                                (((x) & THERMWLAN_SAR_ADC_DONE_MASK) >> THERMWLAN_SAR_ADC_DONE_LSB)
#define THERMWLAN_SAR_ADC_DONE_SET(x)                                (((0 | (x)) << THERMWLAN_SAR_ADC_DONE_LSB) & THERMWLAN_SAR_ADC_DONE_MASK)
#define THERMWLAN_SAR_ADC_DONE_RESET                                 0
#define THERMWLAN_SEL_TEMPSENSOR_MSB                                 6
#define THERMWLAN_SEL_TEMPSENSOR_LSB                                 6
#define THERMWLAN_SEL_TEMPSENSOR_MASK                                0x00000040
#define THERMWLAN_SEL_TEMPSENSOR_GET(x)                              (((x) & THERMWLAN_SEL_TEMPSENSOR_MASK) >> THERMWLAN_SEL_TEMPSENSOR_LSB)
#define THERMWLAN_SEL_TEMPSENSOR_SET(x)                              (((0 | (x)) << THERMWLAN_SEL_TEMPSENSOR_LSB) & THERMWLAN_SEL_TEMPSENSOR_MASK)
#define THERMWLAN_SEL_TEMPSENSOR_RESET                               0
#define THERMWLAN_THERM_FORCERST_B_MSB                               5
#define THERMWLAN_THERM_FORCERST_B_LSB                               5
#define THERMWLAN_THERM_FORCERST_B_MASK                              0x00000020
#define THERMWLAN_THERM_FORCERST_B_GET(x)                            (((x) & THERMWLAN_THERM_FORCERST_B_MASK) >> THERMWLAN_THERM_FORCERST_B_LSB)
#define THERMWLAN_THERM_FORCERST_B_SET(x)                            (((0 | (x)) << THERMWLAN_THERM_FORCERST_B_LSB) & THERMWLAN_THERM_FORCERST_B_MASK)
#define THERMWLAN_THERM_FORCERST_B_RESET                             1
#define THERMWLAN_PWD_SWREGCLK_MSB                                   4
#define THERMWLAN_PWD_SWREGCLK_LSB                                   4
#define THERMWLAN_PWD_SWREGCLK_MASK                                  0x00000010
#define THERMWLAN_PWD_SWREGCLK_GET(x)                                (((x) & THERMWLAN_PWD_SWREGCLK_MASK) >> THERMWLAN_PWD_SWREGCLK_LSB)
#define THERMWLAN_PWD_SWREGCLK_SET(x)                                (((0 | (x)) << THERMWLAN_PWD_SWREGCLK_LSB) & THERMWLAN_PWD_SWREGCLK_MASK)
#define THERMWLAN_PWD_SWREGCLK_RESET                                 0
#define THERMWLAN_FLIP_SWREGCLK_MSB                                  3
#define THERMWLAN_FLIP_SWREGCLK_LSB                                  3
#define THERMWLAN_FLIP_SWREGCLK_MASK                                 0x00000008
#define THERMWLAN_FLIP_SWREGCLK_GET(x)                               (((x) & THERMWLAN_FLIP_SWREGCLK_MASK) >> THERMWLAN_FLIP_SWREGCLK_LSB)
#define THERMWLAN_FLIP_SWREGCLK_SET(x)                               (((0 | (x)) << THERMWLAN_FLIP_SWREGCLK_LSB) & THERMWLAN_FLIP_SWREGCLK_MASK)
#define THERMWLAN_FLIP_SWREGCLK_RESET                                0
#define THERMWLAN_XTAL_ABSEL_MSB                                     2
#define THERMWLAN_XTAL_ABSEL_LSB                                     1
#define THERMWLAN_XTAL_ABSEL_MASK                                    0x00000006
#define THERMWLAN_XTAL_ABSEL_GET(x)                                  (((x) & THERMWLAN_XTAL_ABSEL_MASK) >> THERMWLAN_XTAL_ABSEL_LSB)
#define THERMWLAN_XTAL_ABSEL_SET(x)                                  (((0 | (x)) << THERMWLAN_XTAL_ABSEL_LSB) & THERMWLAN_XTAL_ABSEL_MASK)
#define THERMWLAN_XTAL_ABSEL_RESET                                   0
#define THERMWLAN_FORCEPWDBTCLK_MSB                                  0
#define THERMWLAN_FORCEPWDBTCLK_LSB                                  0
#define THERMWLAN_FORCEPWDBTCLK_MASK                                 0x00000001
#define THERMWLAN_FORCEPWDBTCLK_GET(x)                               (((x) & THERMWLAN_FORCEPWDBTCLK_MASK) >> THERMWLAN_FORCEPWDBTCLK_LSB)
#define THERMWLAN_FORCEPWDBTCLK_SET(x)                               (((0 | (x)) << THERMWLAN_FORCEPWDBTCLK_LSB) & THERMWLAN_FORCEPWDBTCLK_MASK)
#define THERMWLAN_FORCEPWDBTCLK_RESET                                0
#define THERMWLAN_ADDRESS                                            0x0008
#define THERMWLAN_HW_MASK                                            0xffffffff
#define THERMWLAN_SW_MASK                                            0xffffffff
#define THERMWLAN_HW_WRITE_MASK                                      0x0000ff80
#define THERMWLAN_SW_WRITE_MASK                                      0xffff007f
#define THERMWLAN_RSTMASK                                            0xffffffff
#define THERMWLAN_RESET                                              0x00000020

// 0x000c (XTALWLAN)
#define XTALWLAN_TCXODET_MSB                                         31
#define XTALWLAN_TCXODET_LSB                                         31
#define XTALWLAN_TCXODET_MASK                                        0x80000000
#define XTALWLAN_TCXODET_GET(x)                                      (((x) & XTALWLAN_TCXODET_MASK) >> XTALWLAN_TCXODET_LSB)
#define XTALWLAN_TCXODET_SET(x)                                      (((0 | (x)) << XTALWLAN_TCXODET_LSB) & XTALWLAN_TCXODET_MASK)
#define XTALWLAN_TCXODET_RESET                                       0
#define XTALWLAN_XTAL_CAPINDAC_MSB                                   30
#define XTALWLAN_XTAL_CAPINDAC_LSB                                   24
#define XTALWLAN_XTAL_CAPINDAC_MASK                                  0x7f000000
#define XTALWLAN_XTAL_CAPINDAC_GET(x)                                (((x) & XTALWLAN_XTAL_CAPINDAC_MASK) >> XTALWLAN_XTAL_CAPINDAC_LSB)
#define XTALWLAN_XTAL_CAPINDAC_SET(x)                                (((0 | (x)) << XTALWLAN_XTAL_CAPINDAC_LSB) & XTALWLAN_XTAL_CAPINDAC_MASK)
#define XTALWLAN_XTAL_CAPINDAC_RESET                                 75
#define XTALWLAN_XTAL_CAPOUTDAC_MSB                                  23
#define XTALWLAN_XTAL_CAPOUTDAC_LSB                                  17
#define XTALWLAN_XTAL_CAPOUTDAC_MASK                                 0x00fe0000
#define XTALWLAN_XTAL_CAPOUTDAC_GET(x)                               (((x) & XTALWLAN_XTAL_CAPOUTDAC_MASK) >> XTALWLAN_XTAL_CAPOUTDAC_LSB)
#define XTALWLAN_XTAL_CAPOUTDAC_SET(x)                               (((0 | (x)) << XTALWLAN_XTAL_CAPOUTDAC_LSB) & XTALWLAN_XTAL_CAPOUTDAC_MASK)
#define XTALWLAN_XTAL_CAPOUTDAC_RESET                                75
#define XTALWLAN_XTAL_XOSCREFV_MSB                                   16
#define XTALWLAN_XTAL_XOSCREFV_LSB                                   15
#define XTALWLAN_XTAL_XOSCREFV_MASK                                  0x00018000
#define XTALWLAN_XTAL_XOSCREFV_GET(x)                                (((x) & XTALWLAN_XTAL_XOSCREFV_MASK) >> XTALWLAN_XTAL_XOSCREFV_LSB)
#define XTALWLAN_XTAL_XOSCREFV_SET(x)                                (((0 | (x)) << XTALWLAN_XTAL_XOSCREFV_LSB) & XTALWLAN_XTAL_XOSCREFV_MASK)
#define XTALWLAN_XTAL_XOSCREFV_RESET                                 1
#define XTALWLAN_XTAL_SHORTXIN_MSB                                   14
#define XTALWLAN_XTAL_SHORTXIN_LSB                                   14
#define XTALWLAN_XTAL_SHORTXIN_MASK                                  0x00004000
#define XTALWLAN_XTAL_SHORTXIN_GET(x)                                (((x) & XTALWLAN_XTAL_SHORTXIN_MASK) >> XTALWLAN_XTAL_SHORTXIN_LSB)
#define XTALWLAN_XTAL_SHORTXIN_SET(x)                                (((0 | (x)) << XTALWLAN_XTAL_SHORTXIN_LSB) & XTALWLAN_XTAL_SHORTXIN_MASK)
#define XTALWLAN_XTAL_SHORTXIN_RESET                                 0
#define XTALWLAN_XTAL_DUTY_MSB                                       13
#define XTALWLAN_XTAL_DUTY_LSB                                       13
#define XTALWLAN_XTAL_DUTY_MASK                                      0x00002000
#define XTALWLAN_XTAL_DUTY_GET(x)                                    (((x) & XTALWLAN_XTAL_DUTY_MASK) >> XTALWLAN_XTAL_DUTY_LSB)
#define XTALWLAN_XTAL_DUTY_SET(x)                                    (((0 | (x)) << XTALWLAN_XTAL_DUTY_LSB) & XTALWLAN_XTAL_DUTY_MASK)
#define XTALWLAN_XTAL_DUTY_RESET                                     0
#define XTALWLAN_XTAL_PWDCLKD_MSB                                    12
#define XTALWLAN_XTAL_PWDCLKD_LSB                                    12
#define XTALWLAN_XTAL_PWDCLKD_MASK                                   0x00001000
#define XTALWLAN_XTAL_PWDCLKD_GET(x)                                 (((x) & XTALWLAN_XTAL_PWDCLKD_MASK) >> XTALWLAN_XTAL_PWDCLKD_LSB)
#define XTALWLAN_XTAL_PWDCLKD_SET(x)                                 (((0 | (x)) << XTALWLAN_XTAL_PWDCLKD_LSB) & XTALWLAN_XTAL_PWDCLKD_MASK)
#define XTALWLAN_XTAL_PWDCLKD_RESET                                  0
#define XTALWLAN_XTAL_LEN_MSB                                        11
#define XTALWLAN_XTAL_LEN_LSB                                        10
#define XTALWLAN_XTAL_LEN_MASK                                       0x00000c00
#define XTALWLAN_XTAL_LEN_GET(x)                                     (((x) & XTALWLAN_XTAL_LEN_MASK) >> XTALWLAN_XTAL_LEN_LSB)
#define XTALWLAN_XTAL_LEN_SET(x)                                     (((0 | (x)) << XTALWLAN_XTAL_LEN_LSB) & XTALWLAN_XTAL_LEN_MASK)
#define XTALWLAN_XTAL_LEN_RESET                                      1
#define XTALWLAN_XTAL_SELVREG_MSB                                    9
#define XTALWLAN_XTAL_SELVREG_LSB                                    9
#define XTALWLAN_XTAL_SELVREG_MASK                                   0x00000200
#define XTALWLAN_XTAL_SELVREG_GET(x)                                 (((x) & XTALWLAN_XTAL_SELVREG_MASK) >> XTALWLAN_XTAL_SELVREG_LSB)
#define XTALWLAN_XTAL_SELVREG_SET(x)                                 (((0 | (x)) << XTALWLAN_XTAL_SELVREG_LSB) & XTALWLAN_XTAL_SELVREG_MASK)
#define XTALWLAN_XTAL_SELVREG_RESET                                  0
#define XTALWLAN_XTAL_OSCON_MSB                                      8
#define XTALWLAN_XTAL_OSCON_LSB                                      8
#define XTALWLAN_XTAL_OSCON_MASK                                     0x00000100
#define XTALWLAN_XTAL_OSCON_GET(x)                                   (((x) & XTALWLAN_XTAL_OSCON_MASK) >> XTALWLAN_XTAL_OSCON_LSB)
#define XTALWLAN_XTAL_OSCON_SET(x)                                   (((0 | (x)) << XTALWLAN_XTAL_OSCON_LSB) & XTALWLAN_XTAL_OSCON_MASK)
#define XTALWLAN_XTAL_OSCON_RESET                                    1
#define XTALWLAN_XTAL_PWDCLKIN_MSB                                   7
#define XTALWLAN_XTAL_PWDCLKIN_LSB                                   7
#define XTALWLAN_XTAL_PWDCLKIN_MASK                                  0x00000080
#define XTALWLAN_XTAL_PWDCLKIN_GET(x)                                (((x) & XTALWLAN_XTAL_PWDCLKIN_MASK) >> XTALWLAN_XTAL_PWDCLKIN_LSB)
#define XTALWLAN_XTAL_PWDCLKIN_SET(x)                                (((0 | (x)) << XTALWLAN_XTAL_PWDCLKIN_LSB) & XTALWLAN_XTAL_PWDCLKIN_MASK)
#define XTALWLAN_XTAL_PWDCLKIN_RESET                                 0
#define XTALWLAN_LOCAL_XTAL_MSB                                      6
#define XTALWLAN_LOCAL_XTAL_LSB                                      6
#define XTALWLAN_LOCAL_XTAL_MASK                                     0x00000040
#define XTALWLAN_LOCAL_XTAL_GET(x)                                   (((x) & XTALWLAN_LOCAL_XTAL_MASK) >> XTALWLAN_LOCAL_XTAL_LSB)
#define XTALWLAN_LOCAL_XTAL_SET(x)                                   (((0 | (x)) << XTALWLAN_LOCAL_XTAL_LSB) & XTALWLAN_LOCAL_XTAL_MASK)
#define XTALWLAN_LOCAL_XTAL_RESET                                    0
#define XTALWLAN_XTAL_SMALLRREGREF_MSB                               5
#define XTALWLAN_XTAL_SMALLRREGREF_LSB                               5
#define XTALWLAN_XTAL_SMALLRREGREF_MASK                              0x00000020
#define XTALWLAN_XTAL_SMALLRREGREF_GET(x)                            (((x) & XTALWLAN_XTAL_SMALLRREGREF_MASK) >> XTALWLAN_XTAL_SMALLRREGREF_LSB)
#define XTALWLAN_XTAL_SMALLRREGREF_SET(x)                            (((0 | (x)) << XTALWLAN_XTAL_SMALLRREGREF_LSB) & XTALWLAN_XTAL_SMALLRREGREF_MASK)
#define XTALWLAN_XTAL_SMALLRREGREF_RESET                             1
#define XTALWLAN_XTAL_SMALLRBIAS_MSB                                 4
#define XTALWLAN_XTAL_SMALLRBIAS_LSB                                 4
#define XTALWLAN_XTAL_SMALLRBIAS_MASK                                0x00000010
#define XTALWLAN_XTAL_SMALLRBIAS_GET(x)                              (((x) & XTALWLAN_XTAL_SMALLRBIAS_MASK) >> XTALWLAN_XTAL_SMALLRBIAS_LSB)
#define XTALWLAN_XTAL_SMALLRBIAS_SET(x)                              (((0 | (x)) << XTALWLAN_XTAL_SMALLRBIAS_LSB) & XTALWLAN_XTAL_SMALLRBIAS_MASK)
#define XTALWLAN_XTAL_SMALLRBIAS_RESET                               1
#define XTALWLAN_XTAL_DOUBLE_MSB                                     3
#define XTALWLAN_XTAL_DOUBLE_LSB                                     3
#define XTALWLAN_XTAL_DOUBLE_MASK                                    0x00000008
#define XTALWLAN_XTAL_DOUBLE_GET(x)                                  (((x) & XTALWLAN_XTAL_DOUBLE_MASK) >> XTALWLAN_XTAL_DOUBLE_LSB)
#define XTALWLAN_XTAL_DOUBLE_SET(x)                                  (((0 | (x)) << XTALWLAN_XTAL_DOUBLE_LSB) & XTALWLAN_XTAL_DOUBLE_MASK)
#define XTALWLAN_XTAL_DOUBLE_RESET                                   0
#define XTALWLAN_XTAL_BIBXOSC_MSB                                    2
#define XTALWLAN_XTAL_BIBXOSC_LSB                                    0
#define XTALWLAN_XTAL_BIBXOSC_MASK                                   0x00000007
#define XTALWLAN_XTAL_BIBXOSC_GET(x)                                 (((x) & XTALWLAN_XTAL_BIBXOSC_MASK) >> XTALWLAN_XTAL_BIBXOSC_LSB)
#define XTALWLAN_XTAL_BIBXOSC_SET(x)                                 (((0 | (x)) << XTALWLAN_XTAL_BIBXOSC_LSB) & XTALWLAN_XTAL_BIBXOSC_MASK)
#define XTALWLAN_XTAL_BIBXOSC_RESET                                  3
#define XTALWLAN_ADDRESS                                             0x000c
#define XTALWLAN_HW_MASK                                             0xffffffff
#define XTALWLAN_SW_MASK                                             0xffffffff
#define XTALWLAN_HW_WRITE_MASK                                       0x80000000
#define XTALWLAN_SW_WRITE_MASK                                       0x7fffffff
#define XTALWLAN_RSTMASK                                             0xffffffff
#define XTALWLAN_RESET                                               0x4b968533


#endif /* _TOPWLAN_REG_CSR_H_ */
