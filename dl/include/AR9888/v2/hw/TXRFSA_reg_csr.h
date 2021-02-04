//                                                                             
// File:       ./TXRFSA_reg_csr.vrh                                            
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:42:50 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             TXRFSA_reg_csr.rdl                                              
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/TXRFSA_reg.rdl
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


#ifndef _TXRFSA_REG_CSR_H_
#define _TXRFSA_REG_CSR_H_
// 0x0000 (TXRFSA1)
#define TXRFSA1_LOCALTXGAIN2G_MSB                                    31
#define TXRFSA1_LOCALTXGAIN2G_LSB                                    31
#define TXRFSA1_LOCALTXGAIN2G_MASK                                   0x80000000
#define TXRFSA1_LOCALTXGAIN2G_GET(x)                                 (((x) & TXRFSA1_LOCALTXGAIN2G_MASK) >> TXRFSA1_LOCALTXGAIN2G_LSB)
#define TXRFSA1_LOCALTXGAIN2G_SET(x)                                 (((0 | (x)) << TXRFSA1_LOCALTXGAIN2G_LSB) & TXRFSA1_LOCALTXGAIN2G_MASK)
#define TXRFSA1_LOCALTXGAIN2G_RESET                                  0
#define TXRFSA1_PADRVGN2G_MSB                                        30
#define TXRFSA1_PADRVGN2G_LSB                                        24
#define TXRFSA1_PADRVGN2G_MASK                                       0x7f000000
#define TXRFSA1_PADRVGN2G_GET(x)                                     (((x) & TXRFSA1_PADRVGN2G_MASK) >> TXRFSA1_PADRVGN2G_LSB)
#define TXRFSA1_PADRVGN2G_SET(x)                                     (((0 | (x)) << TXRFSA1_PADRVGN2G_LSB) & TXRFSA1_PADRVGN2G_MASK)
#define TXRFSA1_PADRVGN2G_RESET                                      63
#define TXRFSA1_LODIV2GFORCED_MSB                                    23
#define TXRFSA1_LODIV2GFORCED_LSB                                    23
#define TXRFSA1_LODIV2GFORCED_MASK                                   0x00800000
#define TXRFSA1_LODIV2GFORCED_GET(x)                                 (((x) & TXRFSA1_LODIV2GFORCED_MASK) >> TXRFSA1_LODIV2GFORCED_LSB)
#define TXRFSA1_LODIV2GFORCED_SET(x)                                 (((0 | (x)) << TXRFSA1_LODIV2GFORCED_LSB) & TXRFSA1_LODIV2GFORCED_MASK)
#define TXRFSA1_LODIV2GFORCED_RESET                                  1
#define TXRFSA1_LOBUF2GFORCED_MSB                                    22
#define TXRFSA1_LOBUF2GFORCED_LSB                                    22
#define TXRFSA1_LOBUF2GFORCED_MASK                                   0x00400000
#define TXRFSA1_LOBUF2GFORCED_GET(x)                                 (((x) & TXRFSA1_LOBUF2GFORCED_MASK) >> TXRFSA1_LOBUF2GFORCED_LSB)
#define TXRFSA1_LOBUF2GFORCED_SET(x)                                 (((0 | (x)) << TXRFSA1_LOBUF2GFORCED_LSB) & TXRFSA1_LOBUF2GFORCED_MASK)
#define TXRFSA1_LOBUF2GFORCED_RESET                                  0
#define TXRFSA1_PDLODIV2G_MSB                                        21
#define TXRFSA1_PDLODIV2G_LSB                                        21
#define TXRFSA1_PDLODIV2G_MASK                                       0x00200000
#define TXRFSA1_PDLODIV2G_GET(x)                                     (((x) & TXRFSA1_PDLODIV2G_MASK) >> TXRFSA1_PDLODIV2G_LSB)
#define TXRFSA1_PDLODIV2G_SET(x)                                     (((0 | (x)) << TXRFSA1_PDLODIV2G_LSB) & TXRFSA1_PDLODIV2G_MASK)
#define TXRFSA1_PDLODIV2G_RESET                                      0
#define TXRFSA1_PDLOBUF2G_MSB                                        20
#define TXRFSA1_PDLOBUF2G_LSB                                        20
#define TXRFSA1_PDLOBUF2G_MASK                                       0x00100000
#define TXRFSA1_PDLOBUF2G_GET(x)                                     (((x) & TXRFSA1_PDLOBUF2G_MASK) >> TXRFSA1_PDLOBUF2G_LSB)
#define TXRFSA1_PDLOBUF2G_SET(x)                                     (((0 | (x)) << TXRFSA1_PDLOBUF2G_LSB) & TXRFSA1_PDLOBUF2G_MASK)
#define TXRFSA1_PDLOBUF2G_RESET                                      0
#define TXRFSA1_PDMXR2G_MSB                                          19
#define TXRFSA1_PDMXR2G_LSB                                          19
#define TXRFSA1_PDMXR2G_MASK                                         0x00080000
#define TXRFSA1_PDMXR2G_GET(x)                                       (((x) & TXRFSA1_PDMXR2G_MASK) >> TXRFSA1_PDMXR2G_LSB)
#define TXRFSA1_PDMXR2G_SET(x)                                       (((0 | (x)) << TXRFSA1_PDMXR2G_LSB) & TXRFSA1_PDMXR2G_MASK)
#define TXRFSA1_PDMXR2G_RESET                                        0
#define TXRFSA1_PDDR2G_MSB                                           18
#define TXRFSA1_PDDR2G_LSB                                           18
#define TXRFSA1_PDDR2G_MASK                                          0x00040000
#define TXRFSA1_PDDR2G_GET(x)                                        (((x) & TXRFSA1_PDDR2G_MASK) >> TXRFSA1_PDDR2G_LSB)
#define TXRFSA1_PDDR2G_SET(x)                                        (((0 | (x)) << TXRFSA1_PDDR2G_LSB) & TXRFSA1_PDDR2G_MASK)
#define TXRFSA1_PDDR2G_RESET                                         0
#define TXRFSA1_PDOUT2G_MSB                                          17
#define TXRFSA1_PDOUT2G_LSB                                          17
#define TXRFSA1_PDOUT2G_MASK                                         0x00020000
#define TXRFSA1_PDOUT2G_GET(x)                                       (((x) & TXRFSA1_PDOUT2G_MASK) >> TXRFSA1_PDOUT2G_LSB)
#define TXRFSA1_PDOUT2G_SET(x)                                       (((0 | (x)) << TXRFSA1_PDOUT2G_LSB) & TXRFSA1_PDOUT2G_MASK)
#define TXRFSA1_PDOUT2G_RESET                                        0
#define TXRFSA1_LOCALTXGAIN5G_MSB                                    16
#define TXRFSA1_LOCALTXGAIN5G_LSB                                    16
#define TXRFSA1_LOCALTXGAIN5G_MASK                                   0x00010000
#define TXRFSA1_LOCALTXGAIN5G_GET(x)                                 (((x) & TXRFSA1_LOCALTXGAIN5G_MASK) >> TXRFSA1_LOCALTXGAIN5G_LSB)
#define TXRFSA1_LOCALTXGAIN5G_SET(x)                                 (((0 | (x)) << TXRFSA1_LOCALTXGAIN5G_LSB) & TXRFSA1_LOCALTXGAIN5G_MASK)
#define TXRFSA1_LOCALTXGAIN5G_RESET                                  0
#define TXRFSA1_PADRV3GN5G_MSB                                       15
#define TXRFSA1_PADRV3GN5G_LSB                                       12
#define TXRFSA1_PADRV3GN5G_MASK                                      0x0000f000
#define TXRFSA1_PADRV3GN5G_GET(x)                                    (((x) & TXRFSA1_PADRV3GN5G_MASK) >> TXRFSA1_PADRV3GN5G_LSB)
#define TXRFSA1_PADRV3GN5G_SET(x)                                    (((0 | (x)) << TXRFSA1_PADRV3GN5G_LSB) & TXRFSA1_PADRV3GN5G_MASK)
#define TXRFSA1_PADRV3GN5G_RESET                                     7
#define TXRFSA1_PADRV2GN5G_MAIN_MSB                                  11
#define TXRFSA1_PADRV2GN5G_MAIN_LSB                                  9
#define TXRFSA1_PADRV2GN5G_MAIN_MASK                                 0x00000e00
#define TXRFSA1_PADRV2GN5G_MAIN_GET(x)                               (((x) & TXRFSA1_PADRV2GN5G_MAIN_MASK) >> TXRFSA1_PADRV2GN5G_MAIN_LSB)
#define TXRFSA1_PADRV2GN5G_MAIN_SET(x)                               (((0 | (x)) << TXRFSA1_PADRV2GN5G_MAIN_LSB) & TXRFSA1_PADRV2GN5G_MAIN_MASK)
#define TXRFSA1_PADRV2GN5G_MAIN_RESET                                4
#define TXRFSA1_PADRV2GN5G_AUX1_MSB                                  8
#define TXRFSA1_PADRV2GN5G_AUX1_LSB                                  6
#define TXRFSA1_PADRV2GN5G_AUX1_MASK                                 0x000001c0
#define TXRFSA1_PADRV2GN5G_AUX1_GET(x)                               (((x) & TXRFSA1_PADRV2GN5G_AUX1_MASK) >> TXRFSA1_PADRV2GN5G_AUX1_LSB)
#define TXRFSA1_PADRV2GN5G_AUX1_SET(x)                               (((0 | (x)) << TXRFSA1_PADRV2GN5G_AUX1_LSB) & TXRFSA1_PADRV2GN5G_AUX1_MASK)
#define TXRFSA1_PADRV2GN5G_AUX1_RESET                                4
#define TXRFSA1_PADRV2GN5G_AUX2_MSB                                  5
#define TXRFSA1_PADRV2GN5G_AUX2_LSB                                  3
#define TXRFSA1_PADRV2GN5G_AUX2_MASK                                 0x00000038
#define TXRFSA1_PADRV2GN5G_AUX2_GET(x)                               (((x) & TXRFSA1_PADRV2GN5G_AUX2_MASK) >> TXRFSA1_PADRV2GN5G_AUX2_LSB)
#define TXRFSA1_PADRV2GN5G_AUX2_SET(x)                               (((0 | (x)) << TXRFSA1_PADRV2GN5G_AUX2_LSB) & TXRFSA1_PADRV2GN5G_AUX2_MASK)
#define TXRFSA1_PADRV2GN5G_AUX2_RESET                                4
#define TXRFSA1_RESERVED_PA2G_MSB                                    2
#define TXRFSA1_RESERVED_PA2G_LSB                                    0
#define TXRFSA1_RESERVED_PA2G_MASK                                   0x00000007
#define TXRFSA1_RESERVED_PA2G_GET(x)                                 (((x) & TXRFSA1_RESERVED_PA2G_MASK) >> TXRFSA1_RESERVED_PA2G_LSB)
#define TXRFSA1_RESERVED_PA2G_SET(x)                                 (((0 | (x)) << TXRFSA1_RESERVED_PA2G_LSB) & TXRFSA1_RESERVED_PA2G_MASK)
#define TXRFSA1_RESERVED_PA2G_RESET                                  3
#define TXRFSA1_ADDRESS                                              0x0000
#define TXRFSA1_HW_MASK                                              0xffffffff
#define TXRFSA1_SW_MASK                                              0xffffffff
#define TXRFSA1_HW_WRITE_MASK                                        0x00000000
#define TXRFSA1_SW_WRITE_MASK                                        0xffffffff
#define TXRFSA1_RSTMASK                                              0xffffffff
#define TXRFSA1_RESET                                                0x3f807923

// 0x0004 (TXRFSA2)
#define TXRFSA2_PDMXR5G_MSB                                          31
#define TXRFSA2_PDMXR5G_LSB                                          31
#define TXRFSA2_PDMXR5G_MASK                                         0x80000000
#define TXRFSA2_PDMXR5G_GET(x)                                       (((x) & TXRFSA2_PDMXR5G_MASK) >> TXRFSA2_PDMXR5G_LSB)
#define TXRFSA2_PDMXR5G_SET(x)                                       (((0 | (x)) << TXRFSA2_PDMXR5G_LSB) & TXRFSA2_PDMXR5G_MASK)
#define TXRFSA2_PDMXR5G_RESET                                        0
#define TXRFSA2_LODIV5GFORCED_MSB                                    30
#define TXRFSA2_LODIV5GFORCED_LSB                                    30
#define TXRFSA2_LODIV5GFORCED_MASK                                   0x40000000
#define TXRFSA2_LODIV5GFORCED_GET(x)                                 (((x) & TXRFSA2_LODIV5GFORCED_MASK) >> TXRFSA2_LODIV5GFORCED_LSB)
#define TXRFSA2_LODIV5GFORCED_SET(x)                                 (((0 | (x)) << TXRFSA2_LODIV5GFORCED_LSB) & TXRFSA2_LODIV5GFORCED_MASK)
#define TXRFSA2_LODIV5GFORCED_RESET                                  1
#define TXRFSA2_LOBUF5GFORCED_MSB                                    29
#define TXRFSA2_LOBUF5GFORCED_LSB                                    29
#define TXRFSA2_LOBUF5GFORCED_MASK                                   0x20000000
#define TXRFSA2_LOBUF5GFORCED_GET(x)                                 (((x) & TXRFSA2_LOBUF5GFORCED_MASK) >> TXRFSA2_LOBUF5GFORCED_LSB)
#define TXRFSA2_LOBUF5GFORCED_SET(x)                                 (((0 | (x)) << TXRFSA2_LOBUF5GFORCED_LSB) & TXRFSA2_LOBUF5GFORCED_MASK)
#define TXRFSA2_LOBUF5GFORCED_RESET                                  0
#define TXRFSA2_PDLODIV5G_MSB                                        28
#define TXRFSA2_PDLODIV5G_LSB                                        28
#define TXRFSA2_PDLODIV5G_MASK                                       0x10000000
#define TXRFSA2_PDLODIV5G_GET(x)                                     (((x) & TXRFSA2_PDLODIV5G_MASK) >> TXRFSA2_PDLODIV5G_LSB)
#define TXRFSA2_PDLODIV5G_SET(x)                                     (((0 | (x)) << TXRFSA2_PDLODIV5G_LSB) & TXRFSA2_PDLODIV5G_MASK)
#define TXRFSA2_PDLODIV5G_RESET                                      0
#define TXRFSA2_PDLOBUF5G_MSB                                        27
#define TXRFSA2_PDLOBUF5G_LSB                                        27
#define TXRFSA2_PDLOBUF5G_MASK                                       0x08000000
#define TXRFSA2_PDLOBUF5G_GET(x)                                     (((x) & TXRFSA2_PDLOBUF5G_MASK) >> TXRFSA2_PDLOBUF5G_LSB)
#define TXRFSA2_PDLOBUF5G_SET(x)                                     (((0 | (x)) << TXRFSA2_PDLOBUF5G_LSB) & TXRFSA2_PDLOBUF5G_MASK)
#define TXRFSA2_PDLOBUF5G_RESET                                      0
#define TXRFSA2_PDOUT5G_MSB                                          26
#define TXRFSA2_PDOUT5G_LSB                                          24
#define TXRFSA2_PDOUT5G_MASK                                         0x07000000
#define TXRFSA2_PDOUT5G_GET(x)                                       (((x) & TXRFSA2_PDOUT5G_MASK) >> TXRFSA2_PDOUT5G_LSB)
#define TXRFSA2_PDOUT5G_SET(x)                                       (((0 | (x)) << TXRFSA2_PDOUT5G_LSB) & TXRFSA2_PDOUT5G_MASK)
#define TXRFSA2_PDOUT5G_RESET                                        0
#define TXRFSA2_DB2G_MSB                                             23
#define TXRFSA2_DB2G_LSB                                             21
#define TXRFSA2_DB2G_MASK                                            0x00e00000
#define TXRFSA2_DB2G_GET(x)                                          (((x) & TXRFSA2_DB2G_MASK) >> TXRFSA2_DB2G_LSB)
#define TXRFSA2_DB2G_SET(x)                                          (((0 | (x)) << TXRFSA2_DB2G_LSB) & TXRFSA2_DB2G_MASK)
#define TXRFSA2_DB2G_RESET                                           1
#define TXRFSA2_OB2G_CCK_MSB                                         20
#define TXRFSA2_OB2G_CCK_LSB                                         18
#define TXRFSA2_OB2G_CCK_MASK                                        0x001c0000
#define TXRFSA2_OB2G_CCK_GET(x)                                      (((x) & TXRFSA2_OB2G_CCK_MASK) >> TXRFSA2_OB2G_CCK_LSB)
#define TXRFSA2_OB2G_CCK_SET(x)                                      (((0 | (x)) << TXRFSA2_OB2G_CCK_LSB) & TXRFSA2_OB2G_CCK_MASK)
#define TXRFSA2_OB2G_CCK_RESET                                       1
#define TXRFSA2_OB2G_PSK_MSB                                         17
#define TXRFSA2_OB2G_PSK_LSB                                         15
#define TXRFSA2_OB2G_PSK_MASK                                        0x00038000
#define TXRFSA2_OB2G_PSK_GET(x)                                      (((x) & TXRFSA2_OB2G_PSK_MASK) >> TXRFSA2_OB2G_PSK_LSB)
#define TXRFSA2_OB2G_PSK_SET(x)                                      (((0 | (x)) << TXRFSA2_OB2G_PSK_LSB) & TXRFSA2_OB2G_PSK_MASK)
#define TXRFSA2_OB2G_PSK_RESET                                       1
#define TXRFSA2_OB2G_QAM_MSB                                         14
#define TXRFSA2_OB2G_QAM_LSB                                         12
#define TXRFSA2_OB2G_QAM_MASK                                        0x00007000
#define TXRFSA2_OB2G_QAM_GET(x)                                      (((x) & TXRFSA2_OB2G_QAM_MASK) >> TXRFSA2_OB2G_QAM_LSB)
#define TXRFSA2_OB2G_QAM_SET(x)                                      (((0 | (x)) << TXRFSA2_OB2G_QAM_LSB) & TXRFSA2_OB2G_QAM_MASK)
#define TXRFSA2_OB2G_QAM_RESET                                       1
#define TXRFSA2_OB2G_SOFTPD_MSB                                      11
#define TXRFSA2_OB2G_SOFTPD_LSB                                      9
#define TXRFSA2_OB2G_SOFTPD_MASK                                     0x00000e00
#define TXRFSA2_OB2G_SOFTPD_GET(x)                                   (((x) & TXRFSA2_OB2G_SOFTPD_MASK) >> TXRFSA2_OB2G_SOFTPD_LSB)
#define TXRFSA2_OB2G_SOFTPD_SET(x)                                   (((0 | (x)) << TXRFSA2_OB2G_SOFTPD_LSB) & TXRFSA2_OB2G_SOFTPD_MASK)
#define TXRFSA2_OB2G_SOFTPD_RESET                                    0
#define TXRFSA2_DCAS2G_MSB                                           8
#define TXRFSA2_DCAS2G_LSB                                           6
#define TXRFSA2_DCAS2G_MASK                                          0x000001c0
#define TXRFSA2_DCAS2G_GET(x)                                        (((x) & TXRFSA2_DCAS2G_MASK) >> TXRFSA2_DCAS2G_LSB)
#define TXRFSA2_DCAS2G_SET(x)                                        (((0 | (x)) << TXRFSA2_DCAS2G_LSB) & TXRFSA2_DCAS2G_MASK)
#define TXRFSA2_DCAS2G_RESET                                         1
#define TXRFSA2_OCAS2G_WLAN_MSB                                      5
#define TXRFSA2_OCAS2G_WLAN_LSB                                      3
#define TXRFSA2_OCAS2G_WLAN_MASK                                     0x00000038
#define TXRFSA2_OCAS2G_WLAN_GET(x)                                   (((x) & TXRFSA2_OCAS2G_WLAN_MASK) >> TXRFSA2_OCAS2G_WLAN_LSB)
#define TXRFSA2_OCAS2G_WLAN_SET(x)                                   (((0 | (x)) << TXRFSA2_OCAS2G_WLAN_LSB) & TXRFSA2_OCAS2G_WLAN_MASK)
#define TXRFSA2_OCAS2G_WLAN_RESET                                    3
#define TXRFSA2_RESERVED_PA2G_MSB                                    2
#define TXRFSA2_RESERVED_PA2G_LSB                                    0
#define TXRFSA2_RESERVED_PA2G_MASK                                   0x00000007
#define TXRFSA2_RESERVED_PA2G_GET(x)                                 (((x) & TXRFSA2_RESERVED_PA2G_MASK) >> TXRFSA2_RESERVED_PA2G_LSB)
#define TXRFSA2_RESERVED_PA2G_SET(x)                                 (((0 | (x)) << TXRFSA2_RESERVED_PA2G_LSB) & TXRFSA2_RESERVED_PA2G_MASK)
#define TXRFSA2_RESERVED_PA2G_RESET                                  3
#define TXRFSA2_ADDRESS                                              0x0004
#define TXRFSA2_HW_MASK                                              0xffffffff
#define TXRFSA2_SW_MASK                                              0xffffffff
#define TXRFSA2_HW_WRITE_MASK                                        0x00000000
#define TXRFSA2_SW_WRITE_MASK                                        0xffffffff
#define TXRFSA2_RSTMASK                                              0xffffffff
#define TXRFSA2_RESET                                                0x4024905b

// 0x0008 (TXRFSA3)
#define TXRFSA3_OBDBOFFST2G_AUX1_MSB                                 31
#define TXRFSA3_OBDBOFFST2G_AUX1_LSB                                 29
#define TXRFSA3_OBDBOFFST2G_AUX1_MASK                                0xe0000000
#define TXRFSA3_OBDBOFFST2G_AUX1_GET(x)                              (((x) & TXRFSA3_OBDBOFFST2G_AUX1_MASK) >> TXRFSA3_OBDBOFFST2G_AUX1_LSB)
#define TXRFSA3_OBDBOFFST2G_AUX1_SET(x)                              (((0 | (x)) << TXRFSA3_OBDBOFFST2G_AUX1_LSB) & TXRFSA3_OBDBOFFST2G_AUX1_MASK)
#define TXRFSA3_OBDBOFFST2G_AUX1_RESET                               3
#define TXRFSA3_OBDBOFFST2G_AUX2_MSB                                 28
#define TXRFSA3_OBDBOFFST2G_AUX2_LSB                                 26
#define TXRFSA3_OBDBOFFST2G_AUX2_MASK                                0x1c000000
#define TXRFSA3_OBDBOFFST2G_AUX2_GET(x)                              (((x) & TXRFSA3_OBDBOFFST2G_AUX2_MASK) >> TXRFSA3_OBDBOFFST2G_AUX2_LSB)
#define TXRFSA3_OBDBOFFST2G_AUX2_SET(x)                              (((0 | (x)) << TXRFSA3_OBDBOFFST2G_AUX2_LSB) & TXRFSA3_OBDBOFFST2G_AUX2_MASK)
#define TXRFSA3_OBDBOFFST2G_AUX2_RESET                               3
#define TXRFSA3_D3B5G_MSB                                            25
#define TXRFSA3_D3B5G_LSB                                            23
#define TXRFSA3_D3B5G_MASK                                           0x03800000
#define TXRFSA3_D3B5G_GET(x)                                         (((x) & TXRFSA3_D3B5G_MASK) >> TXRFSA3_D3B5G_LSB)
#define TXRFSA3_D3B5G_SET(x)                                         (((0 | (x)) << TXRFSA3_D3B5G_LSB) & TXRFSA3_D3B5G_MASK)
#define TXRFSA3_D3B5G_RESET                                          1
#define TXRFSA3_D2B5G_MSB                                            22
#define TXRFSA3_D2B5G_LSB                                            20
#define TXRFSA3_D2B5G_MASK                                           0x00700000
#define TXRFSA3_D2B5G_GET(x)                                         (((x) & TXRFSA3_D2B5G_MASK) >> TXRFSA3_D2B5G_LSB)
#define TXRFSA3_D2B5G_SET(x)                                         (((0 | (x)) << TXRFSA3_D2B5G_LSB) & TXRFSA3_D2B5G_MASK)
#define TXRFSA3_D2B5G_RESET                                          1
#define TXRFSA3_OB5G_CCK_MSB                                         19
#define TXRFSA3_OB5G_CCK_LSB                                         17
#define TXRFSA3_OB5G_CCK_MASK                                        0x000e0000
#define TXRFSA3_OB5G_CCK_GET(x)                                      (((x) & TXRFSA3_OB5G_CCK_MASK) >> TXRFSA3_OB5G_CCK_LSB)
#define TXRFSA3_OB5G_CCK_SET(x)                                      (((0 | (x)) << TXRFSA3_OB5G_CCK_LSB) & TXRFSA3_OB5G_CCK_MASK)
#define TXRFSA3_OB5G_CCK_RESET                                       1
#define TXRFSA3_OB5G_PSK_MSB                                         16
#define TXRFSA3_OB5G_PSK_LSB                                         14
#define TXRFSA3_OB5G_PSK_MASK                                        0x0001c000
#define TXRFSA3_OB5G_PSK_GET(x)                                      (((x) & TXRFSA3_OB5G_PSK_MASK) >> TXRFSA3_OB5G_PSK_LSB)
#define TXRFSA3_OB5G_PSK_SET(x)                                      (((0 | (x)) << TXRFSA3_OB5G_PSK_LSB) & TXRFSA3_OB5G_PSK_MASK)
#define TXRFSA3_OB5G_PSK_RESET                                       1
#define TXRFSA3_OB5G_QAM_MSB                                         13
#define TXRFSA3_OB5G_QAM_LSB                                         11
#define TXRFSA3_OB5G_QAM_MASK                                        0x00003800
#define TXRFSA3_OB5G_QAM_GET(x)                                      (((x) & TXRFSA3_OB5G_QAM_MASK) >> TXRFSA3_OB5G_QAM_LSB)
#define TXRFSA3_OB5G_QAM_SET(x)                                      (((0 | (x)) << TXRFSA3_OB5G_QAM_LSB) & TXRFSA3_OB5G_QAM_MASK)
#define TXRFSA3_OB5G_QAM_RESET                                       1
#define TXRFSA3_OBDBOFFST5G_AUX1_MSB                                 10
#define TXRFSA3_OBDBOFFST5G_AUX1_LSB                                 8
#define TXRFSA3_OBDBOFFST5G_AUX1_MASK                                0x00000700
#define TXRFSA3_OBDBOFFST5G_AUX1_GET(x)                              (((x) & TXRFSA3_OBDBOFFST5G_AUX1_MASK) >> TXRFSA3_OBDBOFFST5G_AUX1_LSB)
#define TXRFSA3_OBDBOFFST5G_AUX1_SET(x)                              (((0 | (x)) << TXRFSA3_OBDBOFFST5G_AUX1_LSB) & TXRFSA3_OBDBOFFST5G_AUX1_MASK)
#define TXRFSA3_OBDBOFFST5G_AUX1_RESET                               3
#define TXRFSA3_OBDBOFFST5G_AUX2_MSB                                 7
#define TXRFSA3_OBDBOFFST5G_AUX2_LSB                                 5
#define TXRFSA3_OBDBOFFST5G_AUX2_MASK                                0x000000e0
#define TXRFSA3_OBDBOFFST5G_AUX2_GET(x)                              (((x) & TXRFSA3_OBDBOFFST5G_AUX2_MASK) >> TXRFSA3_OBDBOFFST5G_AUX2_LSB)
#define TXRFSA3_OBDBOFFST5G_AUX2_SET(x)                              (((0 | (x)) << TXRFSA3_OBDBOFFST5G_AUX2_LSB) & TXRFSA3_OBDBOFFST5G_AUX2_MASK)
#define TXRFSA3_OBDBOFFST5G_AUX2_RESET                               3
#define TXRFSA3_D3CAS5G_MSB                                          4
#define TXRFSA3_D3CAS5G_LSB                                          2
#define TXRFSA3_D3CAS5G_MASK                                         0x0000001c
#define TXRFSA3_D3CAS5G_GET(x)                                       (((x) & TXRFSA3_D3CAS5G_MASK) >> TXRFSA3_D3CAS5G_LSB)
#define TXRFSA3_D3CAS5G_SET(x)                                       (((0 | (x)) << TXRFSA3_D3CAS5G_LSB) & TXRFSA3_D3CAS5G_MASK)
#define TXRFSA3_D3CAS5G_RESET                                        1
#define TXRFSA3_RESERVED_3_MSB                                       1
#define TXRFSA3_RESERVED_3_LSB                                       0
#define TXRFSA3_RESERVED_3_MASK                                      0x00000003
#define TXRFSA3_RESERVED_3_GET(x)                                    (((x) & TXRFSA3_RESERVED_3_MASK) >> TXRFSA3_RESERVED_3_LSB)
#define TXRFSA3_RESERVED_3_SET(x)                                    (((0 | (x)) << TXRFSA3_RESERVED_3_LSB) & TXRFSA3_RESERVED_3_MASK)
#define TXRFSA3_RESERVED_3_RESET                                     3
#define TXRFSA3_ADDRESS                                              0x0008
#define TXRFSA3_HW_MASK                                              0xffffffff
#define TXRFSA3_SW_MASK                                              0xffffffff
#define TXRFSA3_HW_WRITE_MASK                                        0x00000000
#define TXRFSA3_SW_WRITE_MASK                                        0xffffffff
#define TXRFSA3_RSTMASK                                              0xffffffff
#define TXRFSA3_RESET                                                0x6c924b67

// 0x000c (TXRFSA4)
#define TXRFSA4_D1CAS5G_MAIN_MSB                                     31
#define TXRFSA4_D1CAS5G_MAIN_LSB                                     29
#define TXRFSA4_D1CAS5G_MAIN_MASK                                    0xe0000000
#define TXRFSA4_D1CAS5G_MAIN_GET(x)                                  (((x) & TXRFSA4_D1CAS5G_MAIN_MASK) >> TXRFSA4_D1CAS5G_MAIN_LSB)
#define TXRFSA4_D1CAS5G_MAIN_SET(x)                                  (((0 | (x)) << TXRFSA4_D1CAS5G_MAIN_LSB) & TXRFSA4_D1CAS5G_MAIN_MASK)
#define TXRFSA4_D1CAS5G_MAIN_RESET                                   1
#define TXRFSA4_D1CAS5G_AUX1_MSB                                     28
#define TXRFSA4_D1CAS5G_AUX1_LSB                                     26
#define TXRFSA4_D1CAS5G_AUX1_MASK                                    0x1c000000
#define TXRFSA4_D1CAS5G_AUX1_GET(x)                                  (((x) & TXRFSA4_D1CAS5G_AUX1_MASK) >> TXRFSA4_D1CAS5G_AUX1_LSB)
#define TXRFSA4_D1CAS5G_AUX1_SET(x)                                  (((0 | (x)) << TXRFSA4_D1CAS5G_AUX1_LSB) & TXRFSA4_D1CAS5G_AUX1_MASK)
#define TXRFSA4_D1CAS5G_AUX1_RESET                                   1
#define TXRFSA4_D1CAS5G_AUX2_MSB                                     25
#define TXRFSA4_D1CAS5G_AUX2_LSB                                     23
#define TXRFSA4_D1CAS5G_AUX2_MASK                                    0x03800000
#define TXRFSA4_D1CAS5G_AUX2_GET(x)                                  (((x) & TXRFSA4_D1CAS5G_AUX2_MASK) >> TXRFSA4_D1CAS5G_AUX2_LSB)
#define TXRFSA4_D1CAS5G_AUX2_SET(x)                                  (((0 | (x)) << TXRFSA4_D1CAS5G_AUX2_LSB) & TXRFSA4_D1CAS5G_AUX2_MASK)
#define TXRFSA4_D1CAS5G_AUX2_RESET                                   1
#define TXRFSA4_D2CAS5G_MAIN_MSB                                     22
#define TXRFSA4_D2CAS5G_MAIN_LSB                                     20
#define TXRFSA4_D2CAS5G_MAIN_MASK                                    0x00700000
#define TXRFSA4_D2CAS5G_MAIN_GET(x)                                  (((x) & TXRFSA4_D2CAS5G_MAIN_MASK) >> TXRFSA4_D2CAS5G_MAIN_LSB)
#define TXRFSA4_D2CAS5G_MAIN_SET(x)                                  (((0 | (x)) << TXRFSA4_D2CAS5G_MAIN_LSB) & TXRFSA4_D2CAS5G_MAIN_MASK)
#define TXRFSA4_D2CAS5G_MAIN_RESET                                   1
#define TXRFSA4_D2CAS5G_AUX1_MSB                                     19
#define TXRFSA4_D2CAS5G_AUX1_LSB                                     17
#define TXRFSA4_D2CAS5G_AUX1_MASK                                    0x000e0000
#define TXRFSA4_D2CAS5G_AUX1_GET(x)                                  (((x) & TXRFSA4_D2CAS5G_AUX1_MASK) >> TXRFSA4_D2CAS5G_AUX1_LSB)
#define TXRFSA4_D2CAS5G_AUX1_SET(x)                                  (((0 | (x)) << TXRFSA4_D2CAS5G_AUX1_LSB) & TXRFSA4_D2CAS5G_AUX1_MASK)
#define TXRFSA4_D2CAS5G_AUX1_RESET                                   1
#define TXRFSA4_D2CAS5G_AUX2_MSB                                     16
#define TXRFSA4_D2CAS5G_AUX2_LSB                                     14
#define TXRFSA4_D2CAS5G_AUX2_MASK                                    0x0001c000
#define TXRFSA4_D2CAS5G_AUX2_GET(x)                                  (((x) & TXRFSA4_D2CAS5G_AUX2_MASK) >> TXRFSA4_D2CAS5G_AUX2_LSB)
#define TXRFSA4_D2CAS5G_AUX2_SET(x)                                  (((0 | (x)) << TXRFSA4_D2CAS5G_AUX2_LSB) & TXRFSA4_D2CAS5G_AUX2_MASK)
#define TXRFSA4_D2CAS5G_AUX2_RESET                                   1
#define TXRFSA4_BTOB_WLAN_MSB                                        13
#define TXRFSA4_BTOB_WLAN_LSB                                        11
#define TXRFSA4_BTOB_WLAN_MASK                                       0x00003800
#define TXRFSA4_BTOB_WLAN_GET(x)                                     (((x) & TXRFSA4_BTOB_WLAN_MASK) >> TXRFSA4_BTOB_WLAN_LSB)
#define TXRFSA4_BTOB_WLAN_SET(x)                                     (((0 | (x)) << TXRFSA4_BTOB_WLAN_LSB) & TXRFSA4_BTOB_WLAN_MASK)
#define TXRFSA4_BTOB_WLAN_RESET                                      3
#define TXRFSA4_BTOB_SOFTPD_WLAN_MSB                                 10
#define TXRFSA4_BTOB_SOFTPD_WLAN_LSB                                 8
#define TXRFSA4_BTOB_SOFTPD_WLAN_MASK                                0x00000700
#define TXRFSA4_BTOB_SOFTPD_WLAN_GET(x)                              (((x) & TXRFSA4_BTOB_SOFTPD_WLAN_MASK) >> TXRFSA4_BTOB_SOFTPD_WLAN_LSB)
#define TXRFSA4_BTOB_SOFTPD_WLAN_SET(x)                              (((0 | (x)) << TXRFSA4_BTOB_SOFTPD_WLAN_LSB) & TXRFSA4_BTOB_SOFTPD_WLAN_MASK)
#define TXRFSA4_BTOB_SOFTPD_WLAN_RESET                               0
#define TXRFSA4_PAFORCEDON_WLAN_MSB                                  7
#define TXRFSA4_PAFORCEDON_WLAN_LSB                                  7
#define TXRFSA4_PAFORCEDON_WLAN_MASK                                 0x00000080
#define TXRFSA4_PAFORCEDON_WLAN_GET(x)                               (((x) & TXRFSA4_PAFORCEDON_WLAN_MASK) >> TXRFSA4_PAFORCEDON_WLAN_LSB)
#define TXRFSA4_PAFORCEDON_WLAN_SET(x)                               (((0 | (x)) << TXRFSA4_PAFORCEDON_WLAN_LSB) & TXRFSA4_PAFORCEDON_WLAN_MASK)
#define TXRFSA4_PAFORCEDON_WLAN_RESET                                0
#define TXRFSA4_USEBTOB_WLANSR_MSB                                   6
#define TXRFSA4_USEBTOB_WLANSR_LSB                                   6
#define TXRFSA4_USEBTOB_WLANSR_MASK                                  0x00000040
#define TXRFSA4_USEBTOB_WLANSR_GET(x)                                (((x) & TXRFSA4_USEBTOB_WLANSR_MASK) >> TXRFSA4_USEBTOB_WLANSR_LSB)
#define TXRFSA4_USEBTOB_WLANSR_SET(x)                                (((0 | (x)) << TXRFSA4_USEBTOB_WLANSR_LSB) & TXRFSA4_USEBTOB_WLANSR_MASK)
#define TXRFSA4_USEBTOB_WLANSR_RESET                                 0
#define TXRFSA4_PWD_IC25AIC_MSB                                      5
#define TXRFSA4_PWD_IC25AIC_LSB                                      3
#define TXRFSA4_PWD_IC25AIC_MASK                                     0x00000038
#define TXRFSA4_PWD_IC25AIC_GET(x)                                   (((x) & TXRFSA4_PWD_IC25AIC_MASK) >> TXRFSA4_PWD_IC25AIC_LSB)
#define TXRFSA4_PWD_IC25AIC_SET(x)                                   (((0 | (x)) << TXRFSA4_PWD_IC25AIC_LSB) & TXRFSA4_PWD_IC25AIC_MASK)
#define TXRFSA4_PWD_IC25AIC_RESET                                    3
#define TXRFSA4_PWD_IC25SPARE_MSB                                    2
#define TXRFSA4_PWD_IC25SPARE_LSB                                    0
#define TXRFSA4_PWD_IC25SPARE_MASK                                   0x00000007
#define TXRFSA4_PWD_IC25SPARE_GET(x)                                 (((x) & TXRFSA4_PWD_IC25SPARE_MASK) >> TXRFSA4_PWD_IC25SPARE_LSB)
#define TXRFSA4_PWD_IC25SPARE_SET(x)                                 (((0 | (x)) << TXRFSA4_PWD_IC25SPARE_LSB) & TXRFSA4_PWD_IC25SPARE_MASK)
#define TXRFSA4_PWD_IC25SPARE_RESET                                  3
#define TXRFSA4_ADDRESS                                              0x000c
#define TXRFSA4_HW_MASK                                              0xffffffff
#define TXRFSA4_SW_MASK                                              0xffffffff
#define TXRFSA4_HW_WRITE_MASK                                        0x00000000
#define TXRFSA4_SW_WRITE_MASK                                        0xffffffff
#define TXRFSA4_RSTMASK                                              0xffffffff
#define TXRFSA4_RESET                                                0x2492581b

// 0x0010 (TXRFSA5)
#define TXRFSA5_AICSTBY_ENABLE_MSB                                   31
#define TXRFSA5_AICSTBY_ENABLE_LSB                                   31
#define TXRFSA5_AICSTBY_ENABLE_MASK                                  0x80000000
#define TXRFSA5_AICSTBY_ENABLE_GET(x)                                (((x) & TXRFSA5_AICSTBY_ENABLE_MASK) >> TXRFSA5_AICSTBY_ENABLE_LSB)
#define TXRFSA5_AICSTBY_ENABLE_SET(x)                                (((0 | (x)) << TXRFSA5_AICSTBY_ENABLE_LSB) & TXRFSA5_AICSTBY_ENABLE_MASK)
#define TXRFSA5_AICSTBY_ENABLE_RESET                                 0
#define TXRFSA5_LOCAL_AICPWD_MSB                                     30
#define TXRFSA5_LOCAL_AICPWD_LSB                                     30
#define TXRFSA5_LOCAL_AICPWD_MASK                                    0x40000000
#define TXRFSA5_LOCAL_AICPWD_GET(x)                                  (((x) & TXRFSA5_LOCAL_AICPWD_MASK) >> TXRFSA5_LOCAL_AICPWD_LSB)
#define TXRFSA5_LOCAL_AICPWD_SET(x)                                  (((0 | (x)) << TXRFSA5_LOCAL_AICPWD_LSB) & TXRFSA5_LOCAL_AICPWD_MASK)
#define TXRFSA5_LOCAL_AICPWD_RESET                                   0
#define TXRFSA5_PWDAICVGAI_LS_MSB                                    29
#define TXRFSA5_PWDAICVGAI_LS_LSB                                    29
#define TXRFSA5_PWDAICVGAI_LS_MASK                                   0x20000000
#define TXRFSA5_PWDAICVGAI_LS_GET(x)                                 (((x) & TXRFSA5_PWDAICVGAI_LS_MASK) >> TXRFSA5_PWDAICVGAI_LS_LSB)
#define TXRFSA5_PWDAICVGAI_LS_SET(x)                                 (((0 | (x)) << TXRFSA5_PWDAICVGAI_LS_LSB) & TXRFSA5_PWDAICVGAI_LS_MASK)
#define TXRFSA5_PWDAICVGAI_LS_RESET                                  0
#define TXRFSA5_PWDAICVGAQ_LS_MSB                                    28
#define TXRFSA5_PWDAICVGAQ_LS_LSB                                    28
#define TXRFSA5_PWDAICVGAQ_LS_MASK                                   0x10000000
#define TXRFSA5_PWDAICVGAQ_LS_GET(x)                                 (((x) & TXRFSA5_PWDAICVGAQ_LS_MASK) >> TXRFSA5_PWDAICVGAQ_LS_LSB)
#define TXRFSA5_PWDAICVGAQ_LS_SET(x)                                 (((0 | (x)) << TXRFSA5_PWDAICVGAQ_LS_LSB) & TXRFSA5_PWDAICVGAQ_LS_MASK)
#define TXRFSA5_PWDAICVGAQ_LS_RESET                                  0
#define TXRFSA5_CSTEER_EN_MSB                                        27
#define TXRFSA5_CSTEER_EN_LSB                                        27
#define TXRFSA5_CSTEER_EN_MASK                                       0x08000000
#define TXRFSA5_CSTEER_EN_GET(x)                                     (((x) & TXRFSA5_CSTEER_EN_MASK) >> TXRFSA5_CSTEER_EN_LSB)
#define TXRFSA5_CSTEER_EN_SET(x)                                     (((0 | (x)) << TXRFSA5_CSTEER_EN_LSB) & TXRFSA5_CSTEER_EN_MASK)
#define TXRFSA5_CSTEER_EN_RESET                                      1
#define TXRFSA5_RESERVED7_1_MSB                                      26
#define TXRFSA5_RESERVED7_1_LSB                                      0
#define TXRFSA5_RESERVED7_1_MASK                                     0x07ffffff
#define TXRFSA5_RESERVED7_1_GET(x)                                   (((x) & TXRFSA5_RESERVED7_1_MASK) >> TXRFSA5_RESERVED7_1_LSB)
#define TXRFSA5_RESERVED7_1_SET(x)                                   (((0 | (x)) << TXRFSA5_RESERVED7_1_LSB) & TXRFSA5_RESERVED7_1_MASK)
#define TXRFSA5_RESERVED7_1_RESET                                    0
#define TXRFSA5_ADDRESS                                              0x0010
#define TXRFSA5_HW_MASK                                              0xffffffff
#define TXRFSA5_SW_MASK                                              0xffffffff
#define TXRFSA5_HW_WRITE_MASK                                        0x00000000
#define TXRFSA5_SW_WRITE_MASK                                        0xffffffff
#define TXRFSA5_RSTMASK                                              0xffffffff
#define TXRFSA5_RESET                                                0x08000000

// 0x0014 (TXRFSA6)
#define TXRFSA6_PDPREDIST2G_MSB                                      31
#define TXRFSA6_PDPREDIST2G_LSB                                      31
#define TXRFSA6_PDPREDIST2G_MASK                                     0x80000000
#define TXRFSA6_PDPREDIST2G_GET(x)                                   (((x) & TXRFSA6_PDPREDIST2G_MASK) >> TXRFSA6_PDPREDIST2G_LSB)
#define TXRFSA6_PDPREDIST2G_SET(x)                                   (((0 | (x)) << TXRFSA6_PDPREDIST2G_LSB) & TXRFSA6_PDPREDIST2G_MASK)
#define TXRFSA6_PDPREDIST2G_RESET                                    0
#define TXRFSA6_CAPDIV2G_PREDIST_MSB                                 30
#define TXRFSA6_CAPDIV2G_PREDIST_LSB                                 27
#define TXRFSA6_CAPDIV2G_PREDIST_MASK                                0x78000000
#define TXRFSA6_CAPDIV2G_PREDIST_GET(x)                              (((x) & TXRFSA6_CAPDIV2G_PREDIST_MASK) >> TXRFSA6_CAPDIV2G_PREDIST_LSB)
#define TXRFSA6_CAPDIV2G_PREDIST_SET(x)                              (((0 | (x)) << TXRFSA6_CAPDIV2G_PREDIST_LSB) & TXRFSA6_CAPDIV2G_PREDIST_MASK)
#define TXRFSA6_CAPDIV2G_PREDIST_RESET                               8
#define TXRFSA6_RDIV2G_MSB                                           26
#define TXRFSA6_RDIV2G_LSB                                           25
#define TXRFSA6_RDIV2G_MASK                                          0x06000000
#define TXRFSA6_RDIV2G_GET(x)                                        (((x) & TXRFSA6_RDIV2G_MASK) >> TXRFSA6_RDIV2G_LSB)
#define TXRFSA6_RDIV2G_SET(x)                                        (((0 | (x)) << TXRFSA6_RDIV2G_LSB) & TXRFSA6_RDIV2G_MASK)
#define TXRFSA6_RDIV2G_RESET                                         3
#define TXRFSA6_PDPREDIST5G_MSB                                      24
#define TXRFSA6_PDPREDIST5G_LSB                                      24
#define TXRFSA6_PDPREDIST5G_MASK                                     0x01000000
#define TXRFSA6_PDPREDIST5G_GET(x)                                   (((x) & TXRFSA6_PDPREDIST5G_MASK) >> TXRFSA6_PDPREDIST5G_LSB)
#define TXRFSA6_PDPREDIST5G_SET(x)                                   (((0 | (x)) << TXRFSA6_PDPREDIST5G_LSB) & TXRFSA6_PDPREDIST5G_MASK)
#define TXRFSA6_PDPREDIST5G_RESET                                    0
#define TXRFSA6_CAPDIV5G_MSB                                         23
#define TXRFSA6_CAPDIV5G_LSB                                         21
#define TXRFSA6_CAPDIV5G_MASK                                        0x00e00000
#define TXRFSA6_CAPDIV5G_GET(x)                                      (((x) & TXRFSA6_CAPDIV5G_MASK) >> TXRFSA6_CAPDIV5G_LSB)
#define TXRFSA6_CAPDIV5G_SET(x)                                      (((0 | (x)) << TXRFSA6_CAPDIV5G_LSB) & TXRFSA6_CAPDIV5G_MASK)
#define TXRFSA6_CAPDIV5G_RESET                                       4
#define TXRFSA6_RDIV5G_MSB                                           20
#define TXRFSA6_RDIV5G_LSB                                           19
#define TXRFSA6_RDIV5G_MASK                                          0x00180000
#define TXRFSA6_RDIV5G_GET(x)                                        (((x) & TXRFSA6_RDIV5G_MASK) >> TXRFSA6_RDIV5G_LSB)
#define TXRFSA6_RDIV5G_SET(x)                                        (((0 | (x)) << TXRFSA6_RDIV5G_LSB) & TXRFSA6_RDIV5G_MASK)
#define TXRFSA6_RDIV5G_RESET                                         3
#define TXRFSA6_CALTXSHIFTOVR_MSB                                    18
#define TXRFSA6_CALTXSHIFTOVR_LSB                                    18
#define TXRFSA6_CALTXSHIFTOVR_MASK                                   0x00040000
#define TXRFSA6_CALTXSHIFTOVR_GET(x)                                 (((x) & TXRFSA6_CALTXSHIFTOVR_MASK) >> TXRFSA6_CALTXSHIFTOVR_LSB)
#define TXRFSA6_CALTXSHIFTOVR_SET(x)                                 (((0 | (x)) << TXRFSA6_CALTXSHIFTOVR_LSB) & TXRFSA6_CALTXSHIFTOVR_MASK)
#define TXRFSA6_CALTXSHIFTOVR_RESET                                  0
#define TXRFSA6_CALTXSHIFT_MSB                                       17
#define TXRFSA6_CALTXSHIFT_LSB                                       17
#define TXRFSA6_CALTXSHIFT_MASK                                      0x00020000
#define TXRFSA6_CALTXSHIFT_GET(x)                                    (((x) & TXRFSA6_CALTXSHIFT_MASK) >> TXRFSA6_CALTXSHIFT_LSB)
#define TXRFSA6_CALTXSHIFT_SET(x)                                    (((0 | (x)) << TXRFSA6_CALTXSHIFT_LSB) & TXRFSA6_CALTXSHIFT_MASK)
#define TXRFSA6_CALTXSHIFT_RESET                                     0
#define TXRFSA6_DB2GCALTX_MSB                                        16
#define TXRFSA6_DB2GCALTX_LSB                                        14
#define TXRFSA6_DB2GCALTX_MASK                                       0x0001c000
#define TXRFSA6_DB2GCALTX_GET(x)                                     (((x) & TXRFSA6_DB2GCALTX_MASK) >> TXRFSA6_DB2GCALTX_LSB)
#define TXRFSA6_DB2GCALTX_SET(x)                                     (((0 | (x)) << TXRFSA6_DB2GCALTX_LSB) & TXRFSA6_DB2GCALTX_MASK)
#define TXRFSA6_DB2GCALTX_RESET                                      7
#define TXRFSA6_PADRVGN2GCALTX_MSB                                   13
#define TXRFSA6_PADRVGN2GCALTX_LSB                                   7
#define TXRFSA6_PADRVGN2GCALTX_MASK                                  0x00003f80
#define TXRFSA6_PADRVGN2GCALTX_GET(x)                                (((x) & TXRFSA6_PADRVGN2GCALTX_MASK) >> TXRFSA6_PADRVGN2GCALTX_LSB)
#define TXRFSA6_PADRVGN2GCALTX_SET(x)                                (((0 | (x)) << TXRFSA6_PADRVGN2GCALTX_LSB) & TXRFSA6_PADRVGN2GCALTX_MASK)
#define TXRFSA6_PADRVGN2GCALTX_RESET                                 64
#define TXRFSA6_D3B5GCALTX_MSB                                       6
#define TXRFSA6_D3B5GCALTX_LSB                                       4
#define TXRFSA6_D3B5GCALTX_MASK                                      0x00000070
#define TXRFSA6_D3B5GCALTX_GET(x)                                    (((x) & TXRFSA6_D3B5GCALTX_MASK) >> TXRFSA6_D3B5GCALTX_LSB)
#define TXRFSA6_D3B5GCALTX_SET(x)                                    (((0 | (x)) << TXRFSA6_D3B5GCALTX_LSB) & TXRFSA6_D3B5GCALTX_MASK)
#define TXRFSA6_D3B5GCALTX_RESET                                     7
#define TXRFSA6_PDOUT5G_3CALTX_MSB                                   3
#define TXRFSA6_PDOUT5G_3CALTX_LSB                                   3
#define TXRFSA6_PDOUT5G_3CALTX_MASK                                  0x00000008
#define TXRFSA6_PDOUT5G_3CALTX_GET(x)                                (((x) & TXRFSA6_PDOUT5G_3CALTX_MASK) >> TXRFSA6_PDOUT5G_3CALTX_LSB)
#define TXRFSA6_PDOUT5G_3CALTX_SET(x)                                (((0 | (x)) << TXRFSA6_PDOUT5G_3CALTX_LSB) & TXRFSA6_PDOUT5G_3CALTX_MASK)
#define TXRFSA6_PDOUT5G_3CALTX_RESET                                 0
#define TXRFSA6_RESERVED_5_MSB                                       2
#define TXRFSA6_RESERVED_5_LSB                                       0
#define TXRFSA6_RESERVED_5_MASK                                      0x00000007
#define TXRFSA6_RESERVED_5_GET(x)                                    (((x) & TXRFSA6_RESERVED_5_MASK) >> TXRFSA6_RESERVED_5_LSB)
#define TXRFSA6_RESERVED_5_SET(x)                                    (((0 | (x)) << TXRFSA6_RESERVED_5_LSB) & TXRFSA6_RESERVED_5_MASK)
#define TXRFSA6_RESERVED_5_RESET                                     7
#define TXRFSA6_ADDRESS                                              0x0014
#define TXRFSA6_HW_MASK                                              0xffffffff
#define TXRFSA6_SW_MASK                                              0xffffffff
#define TXRFSA6_HW_WRITE_MASK                                        0x00000000
#define TXRFSA6_SW_WRITE_MASK                                        0xffffffff
#define TXRFSA6_RSTMASK                                              0xffffffff
#define TXRFSA6_RESET                                                0x4699e077

// 0x0018 (TXRFSA7)
#define TXRFSA7_PWD_IC25MIXBUF5G_MSB                                 31
#define TXRFSA7_PWD_IC25MIXBUF5G_LSB                                 29
#define TXRFSA7_PWD_IC25MIXBUF5G_MASK                                0xe0000000
#define TXRFSA7_PWD_IC25MIXBUF5G_GET(x)                              (((x) & TXRFSA7_PWD_IC25MIXBUF5G_MASK) >> TXRFSA7_PWD_IC25MIXBUF5G_LSB)
#define TXRFSA7_PWD_IC25MIXBUF5G_SET(x)                              (((0 | (x)) << TXRFSA7_PWD_IC25MIXBUF5G_LSB) & TXRFSA7_PWD_IC25MIXBUF5G_MASK)
#define TXRFSA7_PWD_IC25MIXBUF5G_RESET                               3
#define TXRFSA7_PWD_IR25PA5G1_MSB                                    28
#define TXRFSA7_PWD_IR25PA5G1_LSB                                    26
#define TXRFSA7_PWD_IR25PA5G1_MASK                                   0x1c000000
#define TXRFSA7_PWD_IR25PA5G1_GET(x)                                 (((x) & TXRFSA7_PWD_IR25PA5G1_MASK) >> TXRFSA7_PWD_IR25PA5G1_LSB)
#define TXRFSA7_PWD_IR25PA5G1_SET(x)                                 (((0 | (x)) << TXRFSA7_PWD_IR25PA5G1_LSB) & TXRFSA7_PWD_IR25PA5G1_MASK)
#define TXRFSA7_PWD_IR25PA5G1_RESET                                  3
#define TXRFSA7_PWD_IR25PA5G2_MSB                                    25
#define TXRFSA7_PWD_IR25PA5G2_LSB                                    23
#define TXRFSA7_PWD_IR25PA5G2_MASK                                   0x03800000
#define TXRFSA7_PWD_IR25PA5G2_GET(x)                                 (((x) & TXRFSA7_PWD_IR25PA5G2_MASK) >> TXRFSA7_PWD_IR25PA5G2_LSB)
#define TXRFSA7_PWD_IR25PA5G2_SET(x)                                 (((0 | (x)) << TXRFSA7_PWD_IR25PA5G2_LSB) & TXRFSA7_PWD_IR25PA5G2_MASK)
#define TXRFSA7_PWD_IR25PA5G2_RESET                                  3
#define TXRFSA7_PWD_IC25TEMPSEN_MSB                                  22
#define TXRFSA7_PWD_IC25TEMPSEN_LSB                                  20
#define TXRFSA7_PWD_IC25TEMPSEN_MASK                                 0x00700000
#define TXRFSA7_PWD_IC25TEMPSEN_GET(x)                               (((x) & TXRFSA7_PWD_IC25TEMPSEN_MASK) >> TXRFSA7_PWD_IC25TEMPSEN_LSB)
#define TXRFSA7_PWD_IC25TEMPSEN_SET(x)                               (((0 | (x)) << TXRFSA7_PWD_IC25TEMPSEN_LSB) & TXRFSA7_PWD_IC25TEMPSEN_MASK)
#define TXRFSA7_PWD_IC25TEMPSEN_RESET                                3
#define TXRFSA7_PWDWLAN_IC25PABT_MSB                                 19
#define TXRFSA7_PWDWLAN_IC25PABT_LSB                                 17
#define TXRFSA7_PWDWLAN_IC25PABT_MASK                                0x000e0000
#define TXRFSA7_PWDWLAN_IC25PABT_GET(x)                              (((x) & TXRFSA7_PWDWLAN_IC25PABT_MASK) >> TXRFSA7_PWDWLAN_IC25PABT_LSB)
#define TXRFSA7_PWDWLAN_IC25PABT_SET(x)                              (((0 | (x)) << TXRFSA7_PWDWLAN_IC25PABT_LSB) & TXRFSA7_PWDWLAN_IC25PABT_MASK)
#define TXRFSA7_PWDWLAN_IC25PABT_RESET                               3
#define TXRFSA7_PWD_IR25MIXDIV2G_MSB                                 16
#define TXRFSA7_PWD_IR25MIXDIV2G_LSB                                 14
#define TXRFSA7_PWD_IR25MIXDIV2G_MASK                                0x0001c000
#define TXRFSA7_PWD_IR25MIXDIV2G_GET(x)                              (((x) & TXRFSA7_PWD_IR25MIXDIV2G_MASK) >> TXRFSA7_PWD_IR25MIXDIV2G_LSB)
#define TXRFSA7_PWD_IR25MIXDIV2G_SET(x)                              (((0 | (x)) << TXRFSA7_PWD_IR25MIXDIV2G_LSB) & TXRFSA7_PWD_IR25MIXDIV2G_MASK)
#define TXRFSA7_PWD_IR25MIXDIV2G_RESET                               3
#define TXRFSA7_PWD_IR25MIXBIAS2G_MSB                                13
#define TXRFSA7_PWD_IR25MIXBIAS2G_LSB                                11
#define TXRFSA7_PWD_IR25MIXBIAS2G_MASK                               0x00003800
#define TXRFSA7_PWD_IR25MIXBIAS2G_GET(x)                             (((x) & TXRFSA7_PWD_IR25MIXBIAS2G_MASK) >> TXRFSA7_PWD_IR25MIXBIAS2G_LSB)
#define TXRFSA7_PWD_IR25MIXBIAS2G_SET(x)                             (((0 | (x)) << TXRFSA7_PWD_IR25MIXBIAS2G_LSB) & TXRFSA7_PWD_IR25MIXBIAS2G_MASK)
#define TXRFSA7_PWD_IR25MIXBIAS2G_RESET                              3
#define TXRFSA7_PWDWLAN_IR25PA2G_MSB                                 10
#define TXRFSA7_PWDWLAN_IR25PA2G_LSB                                 8
#define TXRFSA7_PWDWLAN_IR25PA2G_MASK                                0x00000700
#define TXRFSA7_PWDWLAN_IR25PA2G_GET(x)                              (((x) & TXRFSA7_PWDWLAN_IR25PA2G_MASK) >> TXRFSA7_PWDWLAN_IR25PA2G_LSB)
#define TXRFSA7_PWDWLAN_IR25PA2G_SET(x)                              (((0 | (x)) << TXRFSA7_PWDWLAN_IR25PA2G_LSB) & TXRFSA7_PWDWLAN_IR25PA2G_MASK)
#define TXRFSA7_PWDWLAN_IR25PA2G_RESET                               3
#define TXRFSA7_PWD_IR25MIXDIV5G_MSB                                 7
#define TXRFSA7_PWD_IR25MIXDIV5G_LSB                                 5
#define TXRFSA7_PWD_IR25MIXDIV5G_MASK                                0x000000e0
#define TXRFSA7_PWD_IR25MIXDIV5G_GET(x)                              (((x) & TXRFSA7_PWD_IR25MIXDIV5G_MASK) >> TXRFSA7_PWD_IR25MIXDIV5G_LSB)
#define TXRFSA7_PWD_IR25MIXDIV5G_SET(x)                              (((0 | (x)) << TXRFSA7_PWD_IR25MIXDIV5G_LSB) & TXRFSA7_PWD_IR25MIXDIV5G_MASK)
#define TXRFSA7_PWD_IR25MIXDIV5G_RESET                               3
#define TXRFSA7_AICCAPDIVMASKING_B_MSB                               4
#define TXRFSA7_AICCAPDIVMASKING_B_LSB                               4
#define TXRFSA7_AICCAPDIVMASKING_B_MASK                              0x00000010
#define TXRFSA7_AICCAPDIVMASKING_B_GET(x)                            (((x) & TXRFSA7_AICCAPDIVMASKING_B_MASK) >> TXRFSA7_AICCAPDIVMASKING_B_LSB)
#define TXRFSA7_AICCAPDIVMASKING_B_SET(x)                            (((0 | (x)) << TXRFSA7_AICCAPDIVMASKING_B_LSB) & TXRFSA7_AICCAPDIVMASKING_B_MASK)
#define TXRFSA7_AICCAPDIVMASKING_B_RESET                             0
#define TXRFSA7_RESERVED5_MSB                                        3
#define TXRFSA7_RESERVED5_LSB                                        0
#define TXRFSA7_RESERVED5_MASK                                       0x0000000f
#define TXRFSA7_RESERVED5_GET(x)                                     (((x) & TXRFSA7_RESERVED5_MASK) >> TXRFSA7_RESERVED5_LSB)
#define TXRFSA7_RESERVED5_SET(x)                                     (((0 | (x)) << TXRFSA7_RESERVED5_LSB) & TXRFSA7_RESERVED5_MASK)
#define TXRFSA7_RESERVED5_RESET                                      0
#define TXRFSA7_ADDRESS                                              0x0018
#define TXRFSA7_HW_MASK                                              0xffffffff
#define TXRFSA7_SW_MASK                                              0xffffffff
#define TXRFSA7_HW_WRITE_MASK                                        0x00000000
#define TXRFSA7_SW_WRITE_MASK                                        0xffffffff
#define TXRFSA7_RSTMASK                                              0xffffffff
#define TXRFSA7_RESET                                                0x6db6db60

// 0x001c (TXRFSA8)
#define TXRFSA8_PWD_IR25MIXBIAS5G_MSB                                31
#define TXRFSA8_PWD_IR25MIXBIAS5G_LSB                                29
#define TXRFSA8_PWD_IR25MIXBIAS5G_MASK                               0xe0000000
#define TXRFSA8_PWD_IR25MIXBIAS5G_GET(x)                             (((x) & TXRFSA8_PWD_IR25MIXBIAS5G_MASK) >> TXRFSA8_PWD_IR25MIXBIAS5G_LSB)
#define TXRFSA8_PWD_IR25MIXBIAS5G_SET(x)                             (((0 | (x)) << TXRFSA8_PWD_IR25MIXBIAS5G_LSB) & TXRFSA8_PWD_IR25MIXBIAS5G_MASK)
#define TXRFSA8_PWD_IR25MIXBIAS5G_RESET                              3
#define TXRFSA8_BIAS_CGM_IGSEL_PA2G_MSB                              28
#define TXRFSA8_BIAS_CGM_IGSEL_PA2G_LSB                              25
#define TXRFSA8_BIAS_CGM_IGSEL_PA2G_MASK                             0x1e000000
#define TXRFSA8_BIAS_CGM_IGSEL_PA2G_GET(x)                           (((x) & TXRFSA8_BIAS_CGM_IGSEL_PA2G_MASK) >> TXRFSA8_BIAS_CGM_IGSEL_PA2G_LSB)
#define TXRFSA8_BIAS_CGM_IGSEL_PA2G_SET(x)                           (((0 | (x)) << TXRFSA8_BIAS_CGM_IGSEL_PA2G_LSB) & TXRFSA8_BIAS_CGM_IGSEL_PA2G_MASK)
#define TXRFSA8_BIAS_CGM_IGSEL_PA2G_RESET                            8
#define TXRFSA8_BIAS_CGM_ICSEL_PA2G_MSB                              24
#define TXRFSA8_BIAS_CGM_ICSEL_PA2G_LSB                              21
#define TXRFSA8_BIAS_CGM_ICSEL_PA2G_MASK                             0x01e00000
#define TXRFSA8_BIAS_CGM_ICSEL_PA2G_GET(x)                           (((x) & TXRFSA8_BIAS_CGM_ICSEL_PA2G_MASK) >> TXRFSA8_BIAS_CGM_ICSEL_PA2G_LSB)
#define TXRFSA8_BIAS_CGM_ICSEL_PA2G_SET(x)                           (((0 | (x)) << TXRFSA8_BIAS_CGM_ICSEL_PA2G_LSB) & TXRFSA8_BIAS_CGM_ICSEL_PA2G_MASK)
#define TXRFSA8_BIAS_CGM_ICSEL_PA2G_RESET                            0
#define TXRFSA8_BIAS_CGM_IGSEL_PA5G_MSB                              20
#define TXRFSA8_BIAS_CGM_IGSEL_PA5G_LSB                              17
#define TXRFSA8_BIAS_CGM_IGSEL_PA5G_MASK                             0x001e0000
#define TXRFSA8_BIAS_CGM_IGSEL_PA5G_GET(x)                           (((x) & TXRFSA8_BIAS_CGM_IGSEL_PA5G_MASK) >> TXRFSA8_BIAS_CGM_IGSEL_PA5G_LSB)
#define TXRFSA8_BIAS_CGM_IGSEL_PA5G_SET(x)                           (((0 | (x)) << TXRFSA8_BIAS_CGM_IGSEL_PA5G_LSB) & TXRFSA8_BIAS_CGM_IGSEL_PA5G_MASK)
#define TXRFSA8_BIAS_CGM_IGSEL_PA5G_RESET                            8
#define TXRFSA8_BIAS_CGM_ICSEL_PA5G_MSB                              16
#define TXRFSA8_BIAS_CGM_ICSEL_PA5G_LSB                              13
#define TXRFSA8_BIAS_CGM_ICSEL_PA5G_MASK                             0x0001e000
#define TXRFSA8_BIAS_CGM_ICSEL_PA5G_GET(x)                           (((x) & TXRFSA8_BIAS_CGM_ICSEL_PA5G_MASK) >> TXRFSA8_BIAS_CGM_ICSEL_PA5G_LSB)
#define TXRFSA8_BIAS_CGM_ICSEL_PA5G_SET(x)                           (((0 | (x)) << TXRFSA8_BIAS_CGM_ICSEL_PA5G_LSB) & TXRFSA8_BIAS_CGM_ICSEL_PA5G_MASK)
#define TXRFSA8_BIAS_CGM_ICSEL_PA5G_RESET                            0
#define TXRFSA8_PWD_IR25TEMPSEN_MSB                                  12
#define TXRFSA8_PWD_IR25TEMPSEN_LSB                                  10
#define TXRFSA8_PWD_IR25TEMPSEN_MASK                                 0x00001c00
#define TXRFSA8_PWD_IR25TEMPSEN_GET(x)                               (((x) & TXRFSA8_PWD_IR25TEMPSEN_MASK) >> TXRFSA8_PWD_IR25TEMPSEN_LSB)
#define TXRFSA8_PWD_IR25TEMPSEN_SET(x)                               (((0 | (x)) << TXRFSA8_PWD_IR25TEMPSEN_LSB) & TXRFSA8_PWD_IR25TEMPSEN_MASK)
#define TXRFSA8_PWD_IR25TEMPSEN_RESET                                3
#define TXRFSA8_PWD_IRSPARE_MSB                                      9
#define TXRFSA8_PWD_IRSPARE_LSB                                      7
#define TXRFSA8_PWD_IRSPARE_MASK                                     0x00000380
#define TXRFSA8_PWD_IRSPARE_GET(x)                                   (((x) & TXRFSA8_PWD_IRSPARE_MASK) >> TXRFSA8_PWD_IRSPARE_LSB)
#define TXRFSA8_PWD_IRSPARE_SET(x)                                   (((0 | (x)) << TXRFSA8_PWD_IRSPARE_LSB) & TXRFSA8_PWD_IRSPARE_MASK)
#define TXRFSA8_PWD_IRSPARE_RESET                                    3
#define TXRFSA8_SHSHOBDB2G_MSB                                       6
#define TXRFSA8_SHSHOBDB2G_LSB                                       6
#define TXRFSA8_SHSHOBDB2G_MASK                                      0x00000040
#define TXRFSA8_SHSHOBDB2G_GET(x)                                    (((x) & TXRFSA8_SHSHOBDB2G_MASK) >> TXRFSA8_SHSHOBDB2G_LSB)
#define TXRFSA8_SHSHOBDB2G_SET(x)                                    (((0 | (x)) << TXRFSA8_SHSHOBDB2G_LSB) & TXRFSA8_SHSHOBDB2G_MASK)
#define TXRFSA8_SHSHOBDB2G_RESET                                     0
#define TXRFSA8_SHSHOBDB5G_MSB                                       5
#define TXRFSA8_SHSHOBDB5G_LSB                                       5
#define TXRFSA8_SHSHOBDB5G_MASK                                      0x00000020
#define TXRFSA8_SHSHOBDB5G_GET(x)                                    (((x) & TXRFSA8_SHSHOBDB5G_MASK) >> TXRFSA8_SHSHOBDB5G_LSB)
#define TXRFSA8_SHSHOBDB5G_SET(x)                                    (((0 | (x)) << TXRFSA8_SHSHOBDB5G_LSB) & TXRFSA8_SHSHOBDB5G_MASK)
#define TXRFSA8_SHSHOBDB5G_RESET                                     0
#define TXRFSA8_RESERVED6_2_MSB                                      4
#define TXRFSA8_RESERVED6_2_LSB                                      0
#define TXRFSA8_RESERVED6_2_MASK                                     0x0000001f
#define TXRFSA8_RESERVED6_2_GET(x)                                   (((x) & TXRFSA8_RESERVED6_2_MASK) >> TXRFSA8_RESERVED6_2_LSB)
#define TXRFSA8_RESERVED6_2_SET(x)                                   (((0 | (x)) << TXRFSA8_RESERVED6_2_LSB) & TXRFSA8_RESERVED6_2_MASK)
#define TXRFSA8_RESERVED6_2_RESET                                    0
#define TXRFSA8_ADDRESS                                              0x001c
#define TXRFSA8_HW_MASK                                              0xffffffff
#define TXRFSA8_SW_MASK                                              0xffffffff
#define TXRFSA8_HW_WRITE_MASK                                        0x0000001f
#define TXRFSA8_SW_WRITE_MASK                                        0xffffffe0
#define TXRFSA8_RSTMASK                                              0xffffffff
#define TXRFSA8_RESET                                                0x70100d80

// 0x0020 (TXRFSA9)
#define TXRFSA9_PA5G_IND_SWTBL_MSB                                   31
#define TXRFSA9_PA5G_IND_SWTBL_LSB                                   28
#define TXRFSA9_PA5G_IND_SWTBL_MASK                                  0xf0000000
#define TXRFSA9_PA5G_IND_SWTBL_GET(x)                                (((x) & TXRFSA9_PA5G_IND_SWTBL_MASK) >> TXRFSA9_PA5G_IND_SWTBL_LSB)
#define TXRFSA9_PA5G_IND_SWTBL_SET(x)                                (((0 | (x)) << TXRFSA9_PA5G_IND_SWTBL_LSB) & TXRFSA9_PA5G_IND_SWTBL_MASK)
#define TXRFSA9_PA5G_IND_SWTBL_RESET                                 3
#define TXRFSA9_PA5G_CAP_SWTBL_00_MSB                                27
#define TXRFSA9_PA5G_CAP_SWTBL_00_LSB                                25
#define TXRFSA9_PA5G_CAP_SWTBL_00_MASK                               0x0e000000
#define TXRFSA9_PA5G_CAP_SWTBL_00_GET(x)                             (((x) & TXRFSA9_PA5G_CAP_SWTBL_00_MASK) >> TXRFSA9_PA5G_CAP_SWTBL_00_LSB)
#define TXRFSA9_PA5G_CAP_SWTBL_00_SET(x)                             (((0 | (x)) << TXRFSA9_PA5G_CAP_SWTBL_00_LSB) & TXRFSA9_PA5G_CAP_SWTBL_00_MASK)
#define TXRFSA9_PA5G_CAP_SWTBL_00_RESET                              0
#define TXRFSA9_PA5G_CAP_SWTBL_01_MSB                                24
#define TXRFSA9_PA5G_CAP_SWTBL_01_LSB                                22
#define TXRFSA9_PA5G_CAP_SWTBL_01_MASK                               0x01c00000
#define TXRFSA9_PA5G_CAP_SWTBL_01_GET(x)                             (((x) & TXRFSA9_PA5G_CAP_SWTBL_01_MASK) >> TXRFSA9_PA5G_CAP_SWTBL_01_LSB)
#define TXRFSA9_PA5G_CAP_SWTBL_01_SET(x)                             (((0 | (x)) << TXRFSA9_PA5G_CAP_SWTBL_01_LSB) & TXRFSA9_PA5G_CAP_SWTBL_01_MASK)
#define TXRFSA9_PA5G_CAP_SWTBL_01_RESET                              1
#define TXRFSA9_PA5G_CAP_SWTBL_10_MSB                                21
#define TXRFSA9_PA5G_CAP_SWTBL_10_LSB                                19
#define TXRFSA9_PA5G_CAP_SWTBL_10_MASK                               0x00380000
#define TXRFSA9_PA5G_CAP_SWTBL_10_GET(x)                             (((x) & TXRFSA9_PA5G_CAP_SWTBL_10_MASK) >> TXRFSA9_PA5G_CAP_SWTBL_10_LSB)
#define TXRFSA9_PA5G_CAP_SWTBL_10_SET(x)                             (((0 | (x)) << TXRFSA9_PA5G_CAP_SWTBL_10_LSB) & TXRFSA9_PA5G_CAP_SWTBL_10_MASK)
#define TXRFSA9_PA5G_CAP_SWTBL_10_RESET                              2
#define TXRFSA9_PA5G_CAP_SWTBL_11_MSB                                18
#define TXRFSA9_PA5G_CAP_SWTBL_11_LSB                                16
#define TXRFSA9_PA5G_CAP_SWTBL_11_MASK                               0x00070000
#define TXRFSA9_PA5G_CAP_SWTBL_11_GET(x)                             (((x) & TXRFSA9_PA5G_CAP_SWTBL_11_MASK) >> TXRFSA9_PA5G_CAP_SWTBL_11_LSB)
#define TXRFSA9_PA5G_CAP_SWTBL_11_SET(x)                             (((0 | (x)) << TXRFSA9_PA5G_CAP_SWTBL_11_LSB) & TXRFSA9_PA5G_CAP_SWTBL_11_MASK)
#define TXRFSA9_PA5G_CAP_SWTBL_11_RESET                              4
#define TXRFSA9_ATBSEL2G_MSB                                         15
#define TXRFSA9_ATBSEL2G_LSB                                         12
#define TXRFSA9_ATBSEL2G_MASK                                        0x0000f000
#define TXRFSA9_ATBSEL2G_GET(x)                                      (((x) & TXRFSA9_ATBSEL2G_MASK) >> TXRFSA9_ATBSEL2G_LSB)
#define TXRFSA9_ATBSEL2G_SET(x)                                      (((0 | (x)) << TXRFSA9_ATBSEL2G_LSB) & TXRFSA9_ATBSEL2G_MASK)
#define TXRFSA9_ATBSEL2G_RESET                                       0
#define TXRFSA9_ATBSEL5G_MSB                                         11
#define TXRFSA9_ATBSEL5G_LSB                                         8
#define TXRFSA9_ATBSEL5G_MASK                                        0x00000f00
#define TXRFSA9_ATBSEL5G_GET(x)                                      (((x) & TXRFSA9_ATBSEL5G_MASK) >> TXRFSA9_ATBSEL5G_LSB)
#define TXRFSA9_ATBSEL5G_SET(x)                                      (((0 | (x)) << TXRFSA9_ATBSEL5G_LSB) & TXRFSA9_ATBSEL5G_MASK)
#define TXRFSA9_ATBSEL5G_RESET                                       0
#define TXRFSA9_RESERVED7_MSB                                        7
#define TXRFSA9_RESERVED7_LSB                                        0
#define TXRFSA9_RESERVED7_MASK                                       0x000000ff
#define TXRFSA9_RESERVED7_GET(x)                                     (((x) & TXRFSA9_RESERVED7_MASK) >> TXRFSA9_RESERVED7_LSB)
#define TXRFSA9_RESERVED7_SET(x)                                     (((0 | (x)) << TXRFSA9_RESERVED7_LSB) & TXRFSA9_RESERVED7_MASK)
#define TXRFSA9_RESERVED7_RESET                                      0
#define TXRFSA9_ADDRESS                                              0x0020
#define TXRFSA9_HW_MASK                                              0xffffffff
#define TXRFSA9_SW_MASK                                              0xffffffff
#define TXRFSA9_HW_WRITE_MASK                                        0x00000000
#define TXRFSA9_SW_WRITE_MASK                                        0xffffffff
#define TXRFSA9_RSTMASK                                              0xffffffff
#define TXRFSA9_RESET                                                0x30540000


#endif /* _TXRFSA_REG_CSR_H_ */
