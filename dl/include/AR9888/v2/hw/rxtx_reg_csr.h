//                                                                             
// File:       ./rxtx_reg_csr.vrh                                              
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:47:23 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             rxtx_reg_csr.rdl                                                
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/rxtx_reg.rdl
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    sjod-chinghwa                                                   
// OS:         Linux 2.6.18-308.8.2.el5                                        
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
/*
 * Copyright (c) 2012-14 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */


#ifndef _RXTX_REG_CSR_H_
#define _RXTX_REG_CSR_H_
// 0x0000 (RXTX1)
#define RXTX1_MANTXGAIN_MSB                                          31
#define RXTX1_MANTXGAIN_LSB                                          31
#define RXTX1_MANTXGAIN_MASK                                         0x80000000
#define RXTX1_MANTXGAIN_GET(x)                                       (((x) & RXTX1_MANTXGAIN_MASK) >> RXTX1_MANTXGAIN_LSB)
#define RXTX1_MANTXGAIN_SET(x)                                       (((0 | (x)) << RXTX1_MANTXGAIN_LSB) & RXTX1_MANTXGAIN_MASK)
#define RXTX1_MANTXGAIN_RESET                                        0
#define RXTX1_PADRV3GN5G_MSB                                         30
#define RXTX1_PADRV3GN5G_LSB                                         27
#define RXTX1_PADRV3GN5G_MASK                                        0x78000000
#define RXTX1_PADRV3GN5G_GET(x)                                      (((x) & RXTX1_PADRV3GN5G_MASK) >> RXTX1_PADRV3GN5G_LSB)
#define RXTX1_PADRV3GN5G_SET(x)                                      (((0 | (x)) << RXTX1_PADRV3GN5G_LSB) & RXTX1_PADRV3GN5G_MASK)
#define RXTX1_PADRV3GN5G_RESET                                       1
#define RXTX1_PADRV2GN5G_MSB                                         26
#define RXTX1_PADRV2GN5G_LSB                                         24
#define RXTX1_PADRV2GN5G_MASK                                        0x07000000
#define RXTX1_PADRV2GN5G_GET(x)                                      (((x) & RXTX1_PADRV2GN5G_MASK) >> RXTX1_PADRV2GN5G_LSB)
#define RXTX1_PADRV2GN5G_SET(x)                                      (((0 | (x)) << RXTX1_PADRV2GN5G_LSB) & RXTX1_PADRV2GN5G_MASK)
#define RXTX1_PADRV2GN5G_RESET                                       2
#define RXTX1_PADRV2GN2G_MSB                                         23
#define RXTX1_PADRV2GN2G_LSB                                         20
#define RXTX1_PADRV2GN2G_MASK                                        0x00f00000
#define RXTX1_PADRV2GN2G_GET(x)                                      (((x) & RXTX1_PADRV2GN2G_MASK) >> RXTX1_PADRV2GN2G_LSB)
#define RXTX1_PADRV2GN2G_SET(x)                                      (((0 | (x)) << RXTX1_PADRV2GN2G_LSB) & RXTX1_PADRV2GN2G_MASK)
#define RXTX1_PADRV2GN2G_RESET                                       6
#define RXTX1_PADRVHALFGN2G_MSB                                      19
#define RXTX1_PADRVHALFGN2G_LSB                                      19
#define RXTX1_PADRVHALFGN2G_MASK                                     0x00080000
#define RXTX1_PADRVHALFGN2G_GET(x)                                   (((x) & RXTX1_PADRVHALFGN2G_MASK) >> RXTX1_PADRVHALFGN2G_LSB)
#define RXTX1_PADRVHALFGN2G_SET(x)                                   (((0 | (x)) << RXTX1_PADRVHALFGN2G_LSB) & RXTX1_PADRVHALFGN2G_MASK)
#define RXTX1_PADRVHALFGN2G_RESET                                    0
#define RXTX1_OVR_AGC_DBDAC_MSB                                      18
#define RXTX1_OVR_AGC_DBDAC_LSB                                      18
#define RXTX1_OVR_AGC_DBDAC_MASK                                     0x00040000
#define RXTX1_OVR_AGC_DBDAC_GET(x)                                   (((x) & RXTX1_OVR_AGC_DBDAC_MASK) >> RXTX1_OVR_AGC_DBDAC_LSB)
#define RXTX1_OVR_AGC_DBDAC_SET(x)                                   (((0 | (x)) << RXTX1_OVR_AGC_DBDAC_LSB) & RXTX1_OVR_AGC_DBDAC_MASK)
#define RXTX1_OVR_AGC_DBDAC_RESET                                    0
#define RXTX1_AGC_DBDAC_MSB                                          17
#define RXTX1_AGC_DBDAC_LSB                                          14
#define RXTX1_AGC_DBDAC_MASK                                         0x0003c000
#define RXTX1_AGC_DBDAC_GET(x)                                       (((x) & RXTX1_AGC_DBDAC_MASK) >> RXTX1_AGC_DBDAC_LSB)
#define RXTX1_AGC_DBDAC_SET(x)                                       (((0 | (x)) << RXTX1_AGC_DBDAC_LSB) & RXTX1_AGC_DBDAC_MASK)
#define RXTX1_AGC_DBDAC_RESET                                        0
#define RXTX1_MANRXGAIN_MSB                                          13
#define RXTX1_MANRXGAIN_LSB                                          13
#define RXTX1_MANRXGAIN_MASK                                         0x00002000
#define RXTX1_MANRXGAIN_GET(x)                                       (((x) & RXTX1_MANRXGAIN_MASK) >> RXTX1_MANRXGAIN_LSB)
#define RXTX1_MANRXGAIN_SET(x)                                       (((0 | (x)) << RXTX1_MANRXGAIN_LSB) & RXTX1_MANRXGAIN_MASK)
#define RXTX1_MANRXGAIN_RESET                                        0
#define RXTX1_LNAGAIN_MSB                                            12
#define RXTX1_LNAGAIN_LSB                                            10
#define RXTX1_LNAGAIN_MASK                                           0x00001c00
#define RXTX1_LNAGAIN_GET(x)                                         (((x) & RXTX1_LNAGAIN_MASK) >> RXTX1_LNAGAIN_LSB)
#define RXTX1_LNAGAIN_SET(x)                                         (((0 | (x)) << RXTX1_LNAGAIN_LSB) & RXTX1_LNAGAIN_MASK)
#define RXTX1_LNAGAIN_RESET                                          4
#define RXTX1_VGAGAIN_MSB                                            9
#define RXTX1_VGAGAIN_LSB                                            7
#define RXTX1_VGAGAIN_MASK                                           0x00000380
#define RXTX1_VGAGAIN_GET(x)                                         (((x) & RXTX1_VGAGAIN_MASK) >> RXTX1_VGAGAIN_LSB)
#define RXTX1_VGAGAIN_SET(x)                                         (((0 | (x)) << RXTX1_VGAGAIN_LSB) & RXTX1_VGAGAIN_MASK)
#define RXTX1_VGAGAIN_RESET                                          4
#define RXTX1_MXRGAIN_MSB                                            6
#define RXTX1_MXRGAIN_LSB                                            5
#define RXTX1_MXRGAIN_MASK                                           0x00000060
#define RXTX1_MXRGAIN_GET(x)                                         (((x) & RXTX1_MXRGAIN_MASK) >> RXTX1_MXRGAIN_LSB)
#define RXTX1_MXRGAIN_SET(x)                                         (((0 | (x)) << RXTX1_MXRGAIN_LSB) & RXTX1_MXRGAIN_MASK)
#define RXTX1_MXRGAIN_RESET                                          0
#define RXTX1_RESERVED_MSB                                           4
#define RXTX1_RESERVED_LSB                                           0
#define RXTX1_RESERVED_MASK                                          0x0000001f
#define RXTX1_RESERVED_GET(x)                                        (((x) & RXTX1_RESERVED_MASK) >> RXTX1_RESERVED_LSB)
#define RXTX1_RESERVED_SET(x)                                        (((0 | (x)) << RXTX1_RESERVED_LSB) & RXTX1_RESERVED_MASK)
#define RXTX1_RESERVED_RESET                                         0
#define RXTX1_ADDRESS                                                0x0000
#define RXTX1_HW_MASK                                                0xffffffff
#define RXTX1_SW_MASK                                                0xffffffff
#define RXTX1_HW_WRITE_MASK                                          0x00000000
#define RXTX1_SW_WRITE_MASK                                          0xffffffff
#define RXTX1_RSTMASK                                                0xffffffff
#define RXTX1_RESET                                                  0x0a601200

// 0x0004 (RXTX2)
#define RXTX2_AGCON_OVR_MSB                                          31
#define RXTX2_AGCON_OVR_LSB                                          31
#define RXTX2_AGCON_OVR_MASK                                         0x80000000
#define RXTX2_AGCON_OVR_GET(x)                                       (((x) & RXTX2_AGCON_OVR_MASK) >> RXTX2_AGCON_OVR_LSB)
#define RXTX2_AGCON_OVR_SET(x)                                       (((0 | (x)) << RXTX2_AGCON_OVR_LSB) & RXTX2_AGCON_OVR_MASK)
#define RXTX2_AGCON_OVR_RESET                                        0
#define RXTX2_AGCON_MSB                                              30
#define RXTX2_AGCON_LSB                                              30
#define RXTX2_AGCON_MASK                                             0x40000000
#define RXTX2_AGCON_GET(x)                                           (((x) & RXTX2_AGCON_MASK) >> RXTX2_AGCON_LSB)
#define RXTX2_AGCON_SET(x)                                           (((0 | (x)) << RXTX2_AGCON_LSB) & RXTX2_AGCON_MASK)
#define RXTX2_AGCON_RESET                                            0
#define RXTX2_TXMOD_OVR_MSB                                          29
#define RXTX2_TXMOD_OVR_LSB                                          29
#define RXTX2_TXMOD_OVR_MASK                                         0x20000000
#define RXTX2_TXMOD_OVR_GET(x)                                       (((x) & RXTX2_TXMOD_OVR_MASK) >> RXTX2_TXMOD_OVR_LSB)
#define RXTX2_TXMOD_OVR_SET(x)                                       (((0 | (x)) << RXTX2_TXMOD_OVR_LSB) & RXTX2_TXMOD_OVR_MASK)
#define RXTX2_TXMOD_OVR_RESET                                        0
#define RXTX2_TXMOD_MSB                                              28
#define RXTX2_TXMOD_LSB                                              26
#define RXTX2_TXMOD_MASK                                             0x1c000000
#define RXTX2_TXMOD_GET(x)                                           (((x) & RXTX2_TXMOD_MASK) >> RXTX2_TXMOD_LSB)
#define RXTX2_TXMOD_SET(x)                                           (((0 | (x)) << RXTX2_TXMOD_LSB) & RXTX2_TXMOD_MASK)
#define RXTX2_TXMOD_RESET                                            0
#define RXTX2_RXON_OVR_MSB                                           25
#define RXTX2_RXON_OVR_LSB                                           25
#define RXTX2_RXON_OVR_MASK                                          0x02000000
#define RXTX2_RXON_OVR_GET(x)                                        (((x) & RXTX2_RXON_OVR_MASK) >> RXTX2_RXON_OVR_LSB)
#define RXTX2_RXON_OVR_SET(x)                                        (((0 | (x)) << RXTX2_RXON_OVR_LSB) & RXTX2_RXON_OVR_MASK)
#define RXTX2_RXON_OVR_RESET                                         0
#define RXTX2_RXON_MSB                                               24
#define RXTX2_RXON_LSB                                               24
#define RXTX2_RXON_MASK                                              0x01000000
#define RXTX2_RXON_GET(x)                                            (((x) & RXTX2_RXON_MASK) >> RXTX2_RXON_LSB)
#define RXTX2_RXON_SET(x)                                            (((0 | (x)) << RXTX2_RXON_LSB) & RXTX2_RXON_MASK)
#define RXTX2_RXON_RESET                                             0
#define RXTX2_PAON_OVR_MSB                                           23
#define RXTX2_PAON_OVR_LSB                                           23
#define RXTX2_PAON_OVR_MASK                                          0x00800000
#define RXTX2_PAON_OVR_GET(x)                                        (((x) & RXTX2_PAON_OVR_MASK) >> RXTX2_PAON_OVR_LSB)
#define RXTX2_PAON_OVR_SET(x)                                        (((0 | (x)) << RXTX2_PAON_OVR_LSB) & RXTX2_PAON_OVR_MASK)
#define RXTX2_PAON_OVR_RESET                                         0
#define RXTX2_PAON_MSB                                               22
#define RXTX2_PAON_LSB                                               22
#define RXTX2_PAON_MASK                                              0x00400000
#define RXTX2_PAON_GET(x)                                            (((x) & RXTX2_PAON_MASK) >> RXTX2_PAON_LSB)
#define RXTX2_PAON_SET(x)                                            (((0 | (x)) << RXTX2_PAON_LSB) & RXTX2_PAON_MASK)
#define RXTX2_PAON_RESET                                             0
#define RXTX2_TXON_OVR_MSB                                           21
#define RXTX2_TXON_OVR_LSB                                           21
#define RXTX2_TXON_OVR_MASK                                          0x00200000
#define RXTX2_TXON_OVR_GET(x)                                        (((x) & RXTX2_TXON_OVR_MASK) >> RXTX2_TXON_OVR_LSB)
#define RXTX2_TXON_OVR_SET(x)                                        (((0 | (x)) << RXTX2_TXON_OVR_LSB) & RXTX2_TXON_OVR_MASK)
#define RXTX2_TXON_OVR_RESET                                         0
#define RXTX2_TXON_MSB                                               20
#define RXTX2_TXON_LSB                                               20
#define RXTX2_TXON_MASK                                              0x00100000
#define RXTX2_TXON_GET(x)                                            (((x) & RXTX2_TXON_MASK) >> RXTX2_TXON_LSB)
#define RXTX2_TXON_SET(x)                                            (((0 | (x)) << RXTX2_TXON_LSB) & RXTX2_TXON_MASK)
#define RXTX2_TXON_RESET                                             0
#define RXTX2_BW_ST_OVR_MSB                                          19
#define RXTX2_BW_ST_OVR_LSB                                          19
#define RXTX2_BW_ST_OVR_MASK                                         0x00080000
#define RXTX2_BW_ST_OVR_GET(x)                                       (((x) & RXTX2_BW_ST_OVR_MASK) >> RXTX2_BW_ST_OVR_LSB)
#define RXTX2_BW_ST_OVR_SET(x)                                       (((0 | (x)) << RXTX2_BW_ST_OVR_LSB) & RXTX2_BW_ST_OVR_MASK)
#define RXTX2_BW_ST_OVR_RESET                                        0
#define RXTX2_BW_ST_MSB                                              18
#define RXTX2_BW_ST_LSB                                              16
#define RXTX2_BW_ST_MASK                                             0x00070000
#define RXTX2_BW_ST_GET(x)                                           (((x) & RXTX2_BW_ST_MASK) >> RXTX2_BW_ST_LSB)
#define RXTX2_BW_ST_SET(x)                                           (((0 | (x)) << RXTX2_BW_ST_LSB) & RXTX2_BW_ST_MASK)
#define RXTX2_BW_ST_RESET                                            0
#define RXTX2_SYNTHON_OVR_MSB                                        15
#define RXTX2_SYNTHON_OVR_LSB                                        15
#define RXTX2_SYNTHON_OVR_MASK                                       0x00008000
#define RXTX2_SYNTHON_OVR_GET(x)                                     (((x) & RXTX2_SYNTHON_OVR_MASK) >> RXTX2_SYNTHON_OVR_LSB)
#define RXTX2_SYNTHON_OVR_SET(x)                                     (((0 | (x)) << RXTX2_SYNTHON_OVR_LSB) & RXTX2_SYNTHON_OVR_MASK)
#define RXTX2_SYNTHON_OVR_RESET                                      0
#define RXTX2_SYNTHON_MSB                                            14
#define RXTX2_SYNTHON_LSB                                            14
#define RXTX2_SYNTHON_MASK                                           0x00004000
#define RXTX2_SYNTHON_GET(x)                                         (((x) & RXTX2_SYNTHON_MASK) >> RXTX2_SYNTHON_LSB)
#define RXTX2_SYNTHON_SET(x)                                         (((0 | (x)) << RXTX2_SYNTHON_LSB) & RXTX2_SYNTHON_MASK)
#define RXTX2_SYNTHON_RESET                                          0
#define RXTX2_BMODE_OVR_MSB                                          13
#define RXTX2_BMODE_OVR_LSB                                          13
#define RXTX2_BMODE_OVR_MASK                                         0x00002000
#define RXTX2_BMODE_OVR_GET(x)                                       (((x) & RXTX2_BMODE_OVR_MASK) >> RXTX2_BMODE_OVR_LSB)
#define RXTX2_BMODE_OVR_SET(x)                                       (((0 | (x)) << RXTX2_BMODE_OVR_LSB) & RXTX2_BMODE_OVR_MASK)
#define RXTX2_BMODE_OVR_RESET                                        0
#define RXTX2_BMODE_MSB                                              12
#define RXTX2_BMODE_LSB                                              12
#define RXTX2_BMODE_MASK                                             0x00001000
#define RXTX2_BMODE_GET(x)                                           (((x) & RXTX2_BMODE_MASK) >> RXTX2_BMODE_LSB)
#define RXTX2_BMODE_SET(x)                                           (((0 | (x)) << RXTX2_BMODE_LSB) & RXTX2_BMODE_MASK)
#define RXTX2_BMODE_RESET                                            0
#define RXTX2_CALPA_OVR_MSB                                          11
#define RXTX2_CALPA_OVR_LSB                                          11
#define RXTX2_CALPA_OVR_MASK                                         0x00000800
#define RXTX2_CALPA_OVR_GET(x)                                       (((x) & RXTX2_CALPA_OVR_MASK) >> RXTX2_CALPA_OVR_LSB)
#define RXTX2_CALPA_OVR_SET(x)                                       (((0 | (x)) << RXTX2_CALPA_OVR_LSB) & RXTX2_CALPA_OVR_MASK)
#define RXTX2_CALPA_OVR_RESET                                        0
#define RXTX2_CALPA_MSB                                              10
#define RXTX2_CALPA_LSB                                              10
#define RXTX2_CALPA_MASK                                             0x00000400
#define RXTX2_CALPA_GET(x)                                           (((x) & RXTX2_CALPA_MASK) >> RXTX2_CALPA_LSB)
#define RXTX2_CALPA_SET(x)                                           (((0 | (x)) << RXTX2_CALPA_LSB) & RXTX2_CALPA_MASK)
#define RXTX2_CALPA_RESET                                            0
#define RXTX2_CALTXSHIFT_OVR_MSB                                     9
#define RXTX2_CALTXSHIFT_OVR_LSB                                     9
#define RXTX2_CALTXSHIFT_OVR_MASK                                    0x00000200
#define RXTX2_CALTXSHIFT_OVR_GET(x)                                  (((x) & RXTX2_CALTXSHIFT_OVR_MASK) >> RXTX2_CALTXSHIFT_OVR_LSB)
#define RXTX2_CALTXSHIFT_OVR_SET(x)                                  (((0 | (x)) << RXTX2_CALTXSHIFT_OVR_LSB) & RXTX2_CALTXSHIFT_OVR_MASK)
#define RXTX2_CALTXSHIFT_OVR_RESET                                   0
#define RXTX2_CALTXSHIFT_MSB                                         8
#define RXTX2_CALTXSHIFT_LSB                                         8
#define RXTX2_CALTXSHIFT_MASK                                        0x00000100
#define RXTX2_CALTXSHIFT_GET(x)                                      (((x) & RXTX2_CALTXSHIFT_MASK) >> RXTX2_CALTXSHIFT_LSB)
#define RXTX2_CALTXSHIFT_SET(x)                                      (((0 | (x)) << RXTX2_CALTXSHIFT_LSB) & RXTX2_CALTXSHIFT_MASK)
#define RXTX2_CALTXSHIFT_RESET                                       0
#define RXTX2_CALTX_OVR_MSB                                          7
#define RXTX2_CALTX_OVR_LSB                                          7
#define RXTX2_CALTX_OVR_MASK                                         0x00000080
#define RXTX2_CALTX_OVR_GET(x)                                       (((x) & RXTX2_CALTX_OVR_MASK) >> RXTX2_CALTX_OVR_LSB)
#define RXTX2_CALTX_OVR_SET(x)                                       (((0 | (x)) << RXTX2_CALTX_OVR_LSB) & RXTX2_CALTX_OVR_MASK)
#define RXTX2_CALTX_OVR_RESET                                        0
#define RXTX2_CALTX_MSB                                              6
#define RXTX2_CALTX_LSB                                              6
#define RXTX2_CALTX_MASK                                             0x00000040
#define RXTX2_CALTX_GET(x)                                           (((x) & RXTX2_CALTX_MASK) >> RXTX2_CALTX_LSB)
#define RXTX2_CALTX_SET(x)                                           (((0 | (x)) << RXTX2_CALTX_LSB) & RXTX2_CALTX_MASK)
#define RXTX2_CALTX_RESET                                            0
#define RXTX2_CALFC_OVR_MSB                                          5
#define RXTX2_CALFC_OVR_LSB                                          5
#define RXTX2_CALFC_OVR_MASK                                         0x00000020
#define RXTX2_CALFC_OVR_GET(x)                                       (((x) & RXTX2_CALFC_OVR_MASK) >> RXTX2_CALFC_OVR_LSB)
#define RXTX2_CALFC_OVR_SET(x)                                       (((0 | (x)) << RXTX2_CALFC_OVR_LSB) & RXTX2_CALFC_OVR_MASK)
#define RXTX2_CALFC_OVR_RESET                                        0
#define RXTX2_CALFC_MSB                                              4
#define RXTX2_CALFC_LSB                                              4
#define RXTX2_CALFC_MASK                                             0x00000010
#define RXTX2_CALFC_GET(x)                                           (((x) & RXTX2_CALFC_MASK) >> RXTX2_CALFC_LSB)
#define RXTX2_CALFC_SET(x)                                           (((0 | (x)) << RXTX2_CALFC_LSB) & RXTX2_CALFC_MASK)
#define RXTX2_CALFC_RESET                                            0
#define RXTX2_CALRESIDUE_OVR_MSB                                     3
#define RXTX2_CALRESIDUE_OVR_LSB                                     3
#define RXTX2_CALRESIDUE_OVR_MASK                                    0x00000008
#define RXTX2_CALRESIDUE_OVR_GET(x)                                  (((x) & RXTX2_CALRESIDUE_OVR_MASK) >> RXTX2_CALRESIDUE_OVR_LSB)
#define RXTX2_CALRESIDUE_OVR_SET(x)                                  (((0 | (x)) << RXTX2_CALRESIDUE_OVR_LSB) & RXTX2_CALRESIDUE_OVR_MASK)
#define RXTX2_CALRESIDUE_OVR_RESET                                   0
#define RXTX2_CALRESIDUE_MSB                                         2
#define RXTX2_CALRESIDUE_LSB                                         2
#define RXTX2_CALRESIDUE_MASK                                        0x00000004
#define RXTX2_CALRESIDUE_GET(x)                                      (((x) & RXTX2_CALRESIDUE_MASK) >> RXTX2_CALRESIDUE_LSB)
#define RXTX2_CALRESIDUE_SET(x)                                      (((0 | (x)) << RXTX2_CALRESIDUE_LSB) & RXTX2_CALRESIDUE_MASK)
#define RXTX2_CALRESIDUE_RESET                                       0
#define RXTX2_LOFORCEDON_MSB                                         1
#define RXTX2_LOFORCEDON_LSB                                         1
#define RXTX2_LOFORCEDON_MASK                                        0x00000002
#define RXTX2_LOFORCEDON_GET(x)                                      (((x) & RXTX2_LOFORCEDON_MASK) >> RXTX2_LOFORCEDON_LSB)
#define RXTX2_LOFORCEDON_SET(x)                                      (((0 | (x)) << RXTX2_LOFORCEDON_LSB) & RXTX2_LOFORCEDON_MASK)
#define RXTX2_LOFORCEDON_RESET                                       1
#define RXTX2_RESERVED_MSB                                           0
#define RXTX2_RESERVED_LSB                                           0
#define RXTX2_RESERVED_MASK                                          0x00000001
#define RXTX2_RESERVED_GET(x)                                        (((x) & RXTX2_RESERVED_MASK) >> RXTX2_RESERVED_LSB)
#define RXTX2_RESERVED_SET(x)                                        (((0 | (x)) << RXTX2_RESERVED_LSB) & RXTX2_RESERVED_MASK)
#define RXTX2_RESERVED_RESET                                         0
#define RXTX2_ADDRESS                                                0x0004
#define RXTX2_HW_MASK                                                0xffffffff
#define RXTX2_SW_MASK                                                0xffffffff
#define RXTX2_HW_WRITE_MASK                                          0x00000000
#define RXTX2_SW_WRITE_MASK                                          0xffffffff
#define RXTX2_RSTMASK                                                0xffffffff
#define RXTX2_RESET                                                  0x00000002

// 0x0008 (RXTX3)
#define RXTX3_AGC_CAL_OVR_MSB                                        31
#define RXTX3_AGC_CAL_OVR_LSB                                        31
#define RXTX3_AGC_CAL_OVR_MASK                                       0x80000000
#define RXTX3_AGC_CAL_OVR_GET(x)                                     (((x) & RXTX3_AGC_CAL_OVR_MASK) >> RXTX3_AGC_CAL_OVR_LSB)
#define RXTX3_AGC_CAL_OVR_SET(x)                                     (((0 | (x)) << RXTX3_AGC_CAL_OVR_LSB) & RXTX3_AGC_CAL_OVR_MASK)
#define RXTX3_AGC_CAL_OVR_RESET                                      0
#define RXTX3_AGC_CAL_MSB                                            30
#define RXTX3_AGC_CAL_LSB                                            30
#define RXTX3_AGC_CAL_MASK                                           0x40000000
#define RXTX3_AGC_CAL_GET(x)                                         (((x) & RXTX3_AGC_CAL_MASK) >> RXTX3_AGC_CAL_LSB)
#define RXTX3_AGC_CAL_SET(x)                                         (((0 | (x)) << RXTX3_AGC_CAL_LSB) & RXTX3_AGC_CAL_MASK)
#define RXTX3_AGC_CAL_RESET                                          0
#define RXTX3_AGC_CALDAC_MSB                                         29
#define RXTX3_AGC_CALDAC_LSB                                         24
#define RXTX3_AGC_CALDAC_MASK                                        0x3f000000
#define RXTX3_AGC_CALDAC_GET(x)                                      (((x) & RXTX3_AGC_CALDAC_MASK) >> RXTX3_AGC_CALDAC_LSB)
#define RXTX3_AGC_CALDAC_SET(x)                                      (((0 | (x)) << RXTX3_AGC_CALDAC_LSB) & RXTX3_AGC_CALDAC_MASK)
#define RXTX3_AGC_CALDAC_RESET                                       0
#define RXTX3_ADC_SAMP_RATE_OVR_MSB                                  23
#define RXTX3_ADC_SAMP_RATE_OVR_LSB                                  23
#define RXTX3_ADC_SAMP_RATE_OVR_MASK                                 0x00800000
#define RXTX3_ADC_SAMP_RATE_OVR_GET(x)                               (((x) & RXTX3_ADC_SAMP_RATE_OVR_MASK) >> RXTX3_ADC_SAMP_RATE_OVR_LSB)
#define RXTX3_ADC_SAMP_RATE_OVR_SET(x)                               (((0 | (x)) << RXTX3_ADC_SAMP_RATE_OVR_LSB) & RXTX3_ADC_SAMP_RATE_OVR_MASK)
#define RXTX3_ADC_SAMP_RATE_OVR_RESET                                0
#define RXTX3_ADC_SAMP_RATE_MSB                                      22
#define RXTX3_ADC_SAMP_RATE_LSB                                      21
#define RXTX3_ADC_SAMP_RATE_MASK                                     0x00600000
#define RXTX3_ADC_SAMP_RATE_GET(x)                                   (((x) & RXTX3_ADC_SAMP_RATE_MASK) >> RXTX3_ADC_SAMP_RATE_LSB)
#define RXTX3_ADC_SAMP_RATE_SET(x)                                   (((0 | (x)) << RXTX3_ADC_SAMP_RATE_LSB) & RXTX3_ADC_SAMP_RATE_MASK)
#define RXTX3_ADC_SAMP_RATE_RESET                                    2
#define RXTX3_CALRX_OVR_MSB                                          20
#define RXTX3_CALRX_OVR_LSB                                          20
#define RXTX3_CALRX_OVR_MASK                                         0x00100000
#define RXTX3_CALRX_OVR_GET(x)                                       (((x) & RXTX3_CALRX_OVR_MASK) >> RXTX3_CALRX_OVR_LSB)
#define RXTX3_CALRX_OVR_SET(x)                                       (((0 | (x)) << RXTX3_CALRX_OVR_LSB) & RXTX3_CALRX_OVR_MASK)
#define RXTX3_CALRX_OVR_RESET                                        0
#define RXTX3_CALRX_MSB                                              19
#define RXTX3_CALRX_LSB                                              19
#define RXTX3_CALRX_MASK                                             0x00080000
#define RXTX3_CALRX_GET(x)                                           (((x) & RXTX3_CALRX_MASK) >> RXTX3_CALRX_LSB)
#define RXTX3_CALRX_SET(x)                                           (((0 | (x)) << RXTX3_CALRX_LSB) & RXTX3_CALRX_MASK)
#define RXTX3_CALRX_RESET                                            0
#define RXTX3_CALADCOFFSET_OVR_MSB                                   18
#define RXTX3_CALADCOFFSET_OVR_LSB                                   18
#define RXTX3_CALADCOFFSET_OVR_MASK                                  0x00040000
#define RXTX3_CALADCOFFSET_OVR_GET(x)                                (((x) & RXTX3_CALADCOFFSET_OVR_MASK) >> RXTX3_CALADCOFFSET_OVR_LSB)
#define RXTX3_CALADCOFFSET_OVR_SET(x)                                (((0 | (x)) << RXTX3_CALADCOFFSET_OVR_LSB) & RXTX3_CALADCOFFSET_OVR_MASK)
#define RXTX3_CALADCOFFSET_OVR_RESET                                 0
#define RXTX3_CALADCOFFSET_MSB                                       17
#define RXTX3_CALADCOFFSET_LSB                                       17
#define RXTX3_CALADCOFFSET_MASK                                      0x00020000
#define RXTX3_CALADCOFFSET_GET(x)                                    (((x) & RXTX3_CALADCOFFSET_MASK) >> RXTX3_CALADCOFFSET_LSB)
#define RXTX3_CALADCOFFSET_SET(x)                                    (((0 | (x)) << RXTX3_CALADCOFFSET_LSB) & RXTX3_CALADCOFFSET_MASK)
#define RXTX3_CALADCOFFSET_RESET                                     0
#define RXTX3_CALXPA_OVR_MSB                                         16
#define RXTX3_CALXPA_OVR_LSB                                         16
#define RXTX3_CALXPA_OVR_MASK                                        0x00010000
#define RXTX3_CALXPA_OVR_GET(x)                                      (((x) & RXTX3_CALXPA_OVR_MASK) >> RXTX3_CALXPA_OVR_LSB)
#define RXTX3_CALXPA_OVR_SET(x)                                      (((0 | (x)) << RXTX3_CALXPA_OVR_LSB) & RXTX3_CALXPA_OVR_MASK)
#define RXTX3_CALXPA_OVR_RESET                                       0
#define RXTX3_CALXPA_MSB                                             15
#define RXTX3_CALXPA_LSB                                             15
#define RXTX3_CALXPA_MASK                                            0x00008000
#define RXTX3_CALXPA_GET(x)                                          (((x) & RXTX3_CALXPA_MASK) >> RXTX3_CALXPA_LSB)
#define RXTX3_CALXPA_SET(x)                                          (((0 | (x)) << RXTX3_CALXPA_LSB) & RXTX3_CALXPA_MASK)
#define RXTX3_CALXPA_RESET                                           0
#define RXTX3_XLNAON_OVR_MSB                                         14
#define RXTX3_XLNAON_OVR_LSB                                         14
#define RXTX3_XLNAON_OVR_MASK                                        0x00004000
#define RXTX3_XLNAON_OVR_GET(x)                                      (((x) & RXTX3_XLNAON_OVR_MASK) >> RXTX3_XLNAON_OVR_LSB)
#define RXTX3_XLNAON_OVR_SET(x)                                      (((0 | (x)) << RXTX3_XLNAON_OVR_LSB) & RXTX3_XLNAON_OVR_MASK)
#define RXTX3_XLNAON_OVR_RESET                                       0
#define RXTX3_XLNAON_MSB                                             13
#define RXTX3_XLNAON_LSB                                             13
#define RXTX3_XLNAON_MASK                                            0x00002000
#define RXTX3_XLNAON_GET(x)                                          (((x) & RXTX3_XLNAON_MASK) >> RXTX3_XLNAON_LSB)
#define RXTX3_XLNAON_SET(x)                                          (((0 | (x)) << RXTX3_XLNAON_LSB) & RXTX3_XLNAON_MASK)
#define RXTX3_XLNAON_RESET                                           0
#define RXTX3_XLNABIAS_PWD_MSB                                       12
#define RXTX3_XLNABIAS_PWD_LSB                                       12
#define RXTX3_XLNABIAS_PWD_MASK                                      0x00001000
#define RXTX3_XLNABIAS_PWD_GET(x)                                    (((x) & RXTX3_XLNABIAS_PWD_MASK) >> RXTX3_XLNABIAS_PWD_LSB)
#define RXTX3_XLNABIAS_PWD_SET(x)                                    (((0 | (x)) << RXTX3_XLNABIAS_PWD_LSB) & RXTX3_XLNABIAS_PWD_MASK)
#define RXTX3_XLNABIAS_PWD_RESET                                     0
#define RXTX3_RESERVED_MSB                                           11
#define RXTX3_RESERVED_LSB                                           0
#define RXTX3_RESERVED_MASK                                          0x00000fff
#define RXTX3_RESERVED_GET(x)                                        (((x) & RXTX3_RESERVED_MASK) >> RXTX3_RESERVED_LSB)
#define RXTX3_RESERVED_SET(x)                                        (((0 | (x)) << RXTX3_RESERVED_LSB) & RXTX3_RESERVED_MASK)
#define RXTX3_RESERVED_RESET                                         0
#define RXTX3_ADDRESS                                                0x0008
#define RXTX3_HW_MASK                                                0xffffffff
#define RXTX3_SW_MASK                                                0xffffffff
#define RXTX3_HW_WRITE_MASK                                          0x00000000
#define RXTX3_SW_WRITE_MASK                                          0xffffffff
#define RXTX3_RSTMASK                                                0xffffffff
#define RXTX3_RESET                                                  0x00400000

// 0x000c (RXTX4)
#define RXTX4_XLNA_STRENGTH_MSB                                      31
#define RXTX4_XLNA_STRENGTH_LSB                                      30
#define RXTX4_XLNA_STRENGTH_MASK                                     0xc0000000
#define RXTX4_XLNA_STRENGTH_GET(x)                                   (((x) & RXTX4_XLNA_STRENGTH_MASK) >> RXTX4_XLNA_STRENGTH_LSB)
#define RXTX4_XLNA_STRENGTH_SET(x)                                   (((0 | (x)) << RXTX4_XLNA_STRENGTH_LSB) & RXTX4_XLNA_STRENGTH_MASK)
#define RXTX4_XLNA_STRENGTH_RESET                                    0
#define RXTX4_THERMON_OVR_MSB                                        29
#define RXTX4_THERMON_OVR_LSB                                        29
#define RXTX4_THERMON_OVR_MASK                                       0x20000000
#define RXTX4_THERMON_OVR_GET(x)                                     (((x) & RXTX4_THERMON_OVR_MASK) >> RXTX4_THERMON_OVR_LSB)
#define RXTX4_THERMON_OVR_SET(x)                                     (((0 | (x)) << RXTX4_THERMON_OVR_LSB) & RXTX4_THERMON_OVR_MASK)
#define RXTX4_THERMON_OVR_RESET                                      0
#define RXTX4_THERMON_MSB                                            28
#define RXTX4_THERMON_LSB                                            28
#define RXTX4_THERMON_MASK                                           0x10000000
#define RXTX4_THERMON_GET(x)                                         (((x) & RXTX4_THERMON_MASK) >> RXTX4_THERMON_LSB)
#define RXTX4_THERMON_SET(x)                                         (((0 | (x)) << RXTX4_THERMON_LSB) & RXTX4_THERMON_MASK)
#define RXTX4_THERMON_RESET                                          0
#define RXTX4_TXSWEN_MSB                                             25
#define RXTX4_TXSWEN_LSB                                             25
#define RXTX4_TXSWEN_MASK                                            0x02000000
#define RXTX4_TXSWEN_GET(x)                                          (((x) & RXTX4_TXSWEN_MASK) >> RXTX4_TXSWEN_LSB)
#define RXTX4_TXSWEN_SET(x)                                          (((0 | (x)) << RXTX4_TXSWEN_LSB) & RXTX4_TXSWEN_MASK)
#define RXTX4_TXSWEN_RESET                                           0
#define RXTX4_TXSWEN_OVR_MSB                                         24
#define RXTX4_TXSWEN_OVR_LSB                                         24
#define RXTX4_TXSWEN_OVR_MASK                                        0x01000000
#define RXTX4_TXSWEN_OVR_GET(x)                                      (((x) & RXTX4_TXSWEN_OVR_MASK) >> RXTX4_TXSWEN_OVR_LSB)
#define RXTX4_TXSWEN_OVR_SET(x)                                      (((0 | (x)) << RXTX4_TXSWEN_OVR_LSB) & RXTX4_TXSWEN_OVR_MASK)
#define RXTX4_TXSWEN_OVR_RESET                                       0
#define RXTX4_AICCAPDIV2GI_MSB                                       23
#define RXTX4_AICCAPDIV2GI_LSB                                       20
#define RXTX4_AICCAPDIV2GI_MASK                                      0x00f00000
#define RXTX4_AICCAPDIV2GI_GET(x)                                    (((x) & RXTX4_AICCAPDIV2GI_MASK) >> RXTX4_AICCAPDIV2GI_LSB)
#define RXTX4_AICCAPDIV2GI_SET(x)                                    (((0 | (x)) << RXTX4_AICCAPDIV2GI_LSB) & RXTX4_AICCAPDIV2GI_MASK)
#define RXTX4_AICCAPDIV2GI_RESET                                     0
#define RXTX4_AICCAPDIV2GQ_MSB                                       19
#define RXTX4_AICCAPDIV2GQ_LSB                                       16
#define RXTX4_AICCAPDIV2GQ_MASK                                      0x000f0000
#define RXTX4_AICCAPDIV2GQ_GET(x)                                    (((x) & RXTX4_AICCAPDIV2GQ_MASK) >> RXTX4_AICCAPDIV2GQ_LSB)
#define RXTX4_AICCAPDIV2GQ_SET(x)                                    (((0 | (x)) << RXTX4_AICCAPDIV2GQ_LSB) & RXTX4_AICCAPDIV2GQ_MASK)
#define RXTX4_AICCAPDIV2GQ_RESET                                     0
#define RXTX4_AICVGA_GNI_MSB                                         15
#define RXTX4_AICVGA_GNI_LSB                                         11
#define RXTX4_AICVGA_GNI_MASK                                        0x0000f800
#define RXTX4_AICVGA_GNI_GET(x)                                      (((x) & RXTX4_AICVGA_GNI_MASK) >> RXTX4_AICVGA_GNI_LSB)
#define RXTX4_AICVGA_GNI_SET(x)                                      (((0 | (x)) << RXTX4_AICVGA_GNI_LSB) & RXTX4_AICVGA_GNI_MASK)
#define RXTX4_AICVGA_GNI_RESET                                       0
#define RXTX4_AICVGA_GNQ_MSB                                         10
#define RXTX4_AICVGA_GNQ_LSB                                         6
#define RXTX4_AICVGA_GNQ_MASK                                        0x000007c0
#define RXTX4_AICVGA_GNQ_GET(x)                                      (((x) & RXTX4_AICVGA_GNQ_MASK) >> RXTX4_AICVGA_GNQ_LSB)
#define RXTX4_AICVGA_GNQ_SET(x)                                      (((0 | (x)) << RXTX4_AICVGA_GNQ_LSB) & RXTX4_AICVGA_GNQ_MASK)
#define RXTX4_AICVGA_GNQ_RESET                                       0
#define RXTX4_AICINVI_MSB                                            5
#define RXTX4_AICINVI_LSB                                            5
#define RXTX4_AICINVI_MASK                                           0x00000020
#define RXTX4_AICINVI_GET(x)                                         (((x) & RXTX4_AICINVI_MASK) >> RXTX4_AICINVI_LSB)
#define RXTX4_AICINVI_SET(x)                                         (((0 | (x)) << RXTX4_AICINVI_LSB) & RXTX4_AICINVI_MASK)
#define RXTX4_AICINVI_RESET                                          0
#define RXTX4_AICINVQ_MSB                                            4
#define RXTX4_AICINVQ_LSB                                            4
#define RXTX4_AICINVQ_MASK                                           0x00000010
#define RXTX4_AICINVQ_GET(x)                                         (((x) & RXTX4_AICINVQ_MASK) >> RXTX4_AICINVQ_LSB)
#define RXTX4_AICINVQ_SET(x)                                         (((0 | (x)) << RXTX4_AICINVQ_LSB) & RXTX4_AICINVQ_MASK)
#define RXTX4_AICINVQ_RESET                                          0
#define RXTX4_AICGMGN6DB_MSB                                         3
#define RXTX4_AICGMGN6DB_LSB                                         0
#define RXTX4_AICGMGN6DB_MASK                                        0x0000000f
#define RXTX4_AICGMGN6DB_GET(x)                                      (((x) & RXTX4_AICGMGN6DB_MASK) >> RXTX4_AICGMGN6DB_LSB)
#define RXTX4_AICGMGN6DB_SET(x)                                      (((0 | (x)) << RXTX4_AICGMGN6DB_LSB) & RXTX4_AICGMGN6DB_MASK)
#define RXTX4_AICGMGN6DB_RESET                                       0
#define RXTX4_ADDRESS                                                0x000c
#define RXTX4_HW_MASK                                                0xf3ffffff
#define RXTX4_SW_MASK                                                0xf3ffffff
#define RXTX4_HW_WRITE_MASK                                          0x00000000
#define RXTX4_SW_WRITE_MASK                                          0xf3ffffff
#define RXTX4_RSTMASK                                                0xffffffff
#define RXTX4_RESET                                                  0x00000000

// 0x0010 (RXTX5)
#define RXTX5_AICGMHP_MSB                                            31
#define RXTX5_AICGMHP_LSB                                            31
#define RXTX5_AICGMHP_MASK                                           0x80000000
#define RXTX5_AICGMHP_GET(x)                                         (((x) & RXTX5_AICGMHP_MASK) >> RXTX5_AICGMHP_LSB)
#define RXTX5_AICGMHP_SET(x)                                         (((0 | (x)) << RXTX5_AICGMHP_LSB) & RXTX5_AICGMHP_MASK)
#define RXTX5_AICGMHP_RESET                                          0
#define RXTX5_AICLOCAL_MODE_MSB                                      30
#define RXTX5_AICLOCAL_MODE_LSB                                      30
#define RXTX5_AICLOCAL_MODE_MASK                                     0x40000000
#define RXTX5_AICLOCAL_MODE_GET(x)                                   (((x) & RXTX5_AICLOCAL_MODE_MASK) >> RXTX5_AICLOCAL_MODE_LSB)
#define RXTX5_AICLOCAL_MODE_SET(x)                                   (((0 | (x)) << RXTX5_AICLOCAL_MODE_LSB) & RXTX5_AICLOCAL_MODE_MASK)
#define RXTX5_AICLOCAL_MODE_RESET                                    0
#define RXTX5_AICON_MSB                                              29
#define RXTX5_AICON_LSB                                              29
#define RXTX5_AICON_MASK                                             0x20000000
#define RXTX5_AICON_GET(x)                                           (((x) & RXTX5_AICON_MASK) >> RXTX5_AICON_LSB)
#define RXTX5_AICON_SET(x)                                           (((0 | (x)) << RXTX5_AICON_LSB) & RXTX5_AICON_MASK)
#define RXTX5_AICON_RESET                                            0
#define RXTX5_AICSTBY_MSB                                            28
#define RXTX5_AICSTBY_LSB                                            28
#define RXTX5_AICSTBY_MASK                                           0x10000000
#define RXTX5_AICSTBY_GET(x)                                         (((x) & RXTX5_AICSTBY_MASK) >> RXTX5_AICSTBY_LSB)
#define RXTX5_AICSTBY_SET(x)                                         (((0 | (x)) << RXTX5_AICSTBY_LSB) & RXTX5_AICSTBY_MASK)
#define RXTX5_AICSTBY_RESET                                          0
#define RXTX5_AIC_CHANOVR_MSB                                        27
#define RXTX5_AIC_CHANOVR_LSB                                        26
#define RXTX5_AIC_CHANOVR_MASK                                       0x0c000000
#define RXTX5_AIC_CHANOVR_GET(x)                                     (((x) & RXTX5_AIC_CHANOVR_MASK) >> RXTX5_AIC_CHANOVR_LSB)
#define RXTX5_AIC_CHANOVR_SET(x)                                     (((0 | (x)) << RXTX5_AIC_CHANOVR_LSB) & RXTX5_AIC_CHANOVR_MASK)
#define RXTX5_AIC_CHANOVR_RESET                                      0
#define RXTX5_AIC_LOADCHANNEL_MSB                                    25
#define RXTX5_AIC_LOADCHANNEL_LSB                                    25
#define RXTX5_AIC_LOADCHANNEL_MASK                                   0x02000000
#define RXTX5_AIC_LOADCHANNEL_GET(x)                                 (((x) & RXTX5_AIC_LOADCHANNEL_MASK) >> RXTX5_AIC_LOADCHANNEL_LSB)
#define RXTX5_AIC_LOADCHANNEL_SET(x)                                 (((0 | (x)) << RXTX5_AIC_LOADCHANNEL_LSB) & RXTX5_AIC_LOADCHANNEL_MASK)
#define RXTX5_AIC_LOADCHANNEL_RESET                                  0
#define RXTX5_TESTIQ_RSEL_MSB                                        24
#define RXTX5_TESTIQ_RSEL_LSB                                        24
#define RXTX5_TESTIQ_RSEL_MASK                                       0x01000000
#define RXTX5_TESTIQ_RSEL_GET(x)                                     (((x) & RXTX5_TESTIQ_RSEL_MASK) >> RXTX5_TESTIQ_RSEL_LSB)
#define RXTX5_TESTIQ_RSEL_SET(x)                                     (((0 | (x)) << RXTX5_TESTIQ_RSEL_LSB) & RXTX5_TESTIQ_RSEL_MASK)
#define RXTX5_TESTIQ_RSEL_RESET                                      0
#define RXTX5_TESTIQ_BUFEN_MSB                                       23
#define RXTX5_TESTIQ_BUFEN_LSB                                       23
#define RXTX5_TESTIQ_BUFEN_MASK                                      0x00800000
#define RXTX5_TESTIQ_BUFEN_GET(x)                                    (((x) & RXTX5_TESTIQ_BUFEN_MASK) >> RXTX5_TESTIQ_BUFEN_LSB)
#define RXTX5_TESTIQ_BUFEN_SET(x)                                    (((0 | (x)) << RXTX5_TESTIQ_BUFEN_LSB) & RXTX5_TESTIQ_BUFEN_MASK)
#define RXTX5_TESTIQ_BUFEN_RESET                                     0
#define RXTX5_TESTIQ_ON_MSB                                          22
#define RXTX5_TESTIQ_ON_LSB                                          22
#define RXTX5_TESTIQ_ON_MASK                                         0x00400000
#define RXTX5_TESTIQ_ON_GET(x)                                       (((x) & RXTX5_TESTIQ_ON_MASK) >> RXTX5_TESTIQ_ON_LSB)
#define RXTX5_TESTIQ_ON_SET(x)                                       (((0 | (x)) << RXTX5_TESTIQ_ON_LSB) & RXTX5_TESTIQ_ON_MASK)
#define RXTX5_TESTIQ_ON_RESET                                        0
#define RXTX5_RESERVED5_MSB                                          21
#define RXTX5_RESERVED5_LSB                                          0
#define RXTX5_RESERVED5_MASK                                         0x003fffff
#define RXTX5_RESERVED5_GET(x)                                       (((x) & RXTX5_RESERVED5_MASK) >> RXTX5_RESERVED5_LSB)
#define RXTX5_RESERVED5_SET(x)                                       (((0 | (x)) << RXTX5_RESERVED5_LSB) & RXTX5_RESERVED5_MASK)
#define RXTX5_RESERVED5_RESET                                        0
#define RXTX5_ADDRESS                                                0x0010
#define RXTX5_HW_MASK                                                0xffffffff
#define RXTX5_SW_MASK                                                0xffffffff
#define RXTX5_HW_WRITE_MASK                                          0x00000000
#define RXTX5_SW_WRITE_MASK                                          0xffffffff
#define RXTX5_RSTMASK                                                0xffffffff
#define RXTX5_RESET                                                  0x00000000


#endif /* _RXTX_REG_CSR_H_ */
