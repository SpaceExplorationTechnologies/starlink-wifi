//                                                                             
// File:       ./mac_pcu_reg.vrh                                               
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:45:17 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             mac_pcu_reg.rdl                                                 
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/athr/wifi/rtl/./mac/rtl/dev/mac/rtl/mac_pcu/blueprint/mac_pcu_reg.rdl
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/env/blueprint/ath_vrh.pm
//             /cad/local/lib/perl/Pinfo.pm                                    
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


#ifndef _MAC_PCU_REG_H_
#define _MAC_PCU_REG_H_
// 0x8000 (MAC_PCU_STA_ADDR_L32)
#define MAC_PCU_STA_ADDR_L32_ADDR_31_0_MSB                           31
#define MAC_PCU_STA_ADDR_L32_ADDR_31_0_LSB                           0
#define MAC_PCU_STA_ADDR_L32_ADDR_31_0_MASK                          0xffffffff
#define MAC_PCU_STA_ADDR_L32_ADDR_31_0_GET(x)                        (((x) & MAC_PCU_STA_ADDR_L32_ADDR_31_0_MASK) >> MAC_PCU_STA_ADDR_L32_ADDR_31_0_LSB)
#define MAC_PCU_STA_ADDR_L32_ADDR_31_0_SET(x)                        (((0 | (x)) << MAC_PCU_STA_ADDR_L32_ADDR_31_0_LSB) & MAC_PCU_STA_ADDR_L32_ADDR_31_0_MASK)
#define MAC_PCU_STA_ADDR_L32_ADDR_31_0_RESET                         0
#define MAC_PCU_STA_ADDR_L32_ADDRESS                                 0x8000
#define MAC_PCU_STA_ADDR_L32_HW_MASK                                 0xffffffff
#define MAC_PCU_STA_ADDR_L32_SW_MASK                                 0xffffffff
#define MAC_PCU_STA_ADDR_L32_HW_WRITE_MASK                           0x00000000
#define MAC_PCU_STA_ADDR_L32_SW_WRITE_MASK                           0xffffffff
#define MAC_PCU_STA_ADDR_L32_RSTMASK                                 0xffffffff
#define MAC_PCU_STA_ADDR_L32_RESET                                   0x00000000

// 0x8004 (MAC_PCU_STA_ADDR_U16)
#define MAC_PCU_STA_ADDR_U16_ADHOC_MCAST_SEARCH_MSB                  31
#define MAC_PCU_STA_ADDR_U16_ADHOC_MCAST_SEARCH_LSB                  31
#define MAC_PCU_STA_ADDR_U16_ADHOC_MCAST_SEARCH_MASK                 0x80000000
#define MAC_PCU_STA_ADDR_U16_ADHOC_MCAST_SEARCH_GET(x)               (((x) & MAC_PCU_STA_ADDR_U16_ADHOC_MCAST_SEARCH_MASK) >> MAC_PCU_STA_ADDR_U16_ADHOC_MCAST_SEARCH_LSB)
#define MAC_PCU_STA_ADDR_U16_ADHOC_MCAST_SEARCH_SET(x)               (((0 | (x)) << MAC_PCU_STA_ADDR_U16_ADHOC_MCAST_SEARCH_LSB) & MAC_PCU_STA_ADDR_U16_ADHOC_MCAST_SEARCH_MASK)
#define MAC_PCU_STA_ADDR_U16_ADHOC_MCAST_SEARCH_RESET                0
#define MAC_PCU_STA_ADDR_U16_CBCIV_ENDIAN_MSB                        30
#define MAC_PCU_STA_ADDR_U16_CBCIV_ENDIAN_LSB                        30
#define MAC_PCU_STA_ADDR_U16_CBCIV_ENDIAN_MASK                       0x40000000
#define MAC_PCU_STA_ADDR_U16_CBCIV_ENDIAN_GET(x)                     (((x) & MAC_PCU_STA_ADDR_U16_CBCIV_ENDIAN_MASK) >> MAC_PCU_STA_ADDR_U16_CBCIV_ENDIAN_LSB)
#define MAC_PCU_STA_ADDR_U16_CBCIV_ENDIAN_SET(x)                     (((0 | (x)) << MAC_PCU_STA_ADDR_U16_CBCIV_ENDIAN_LSB) & MAC_PCU_STA_ADDR_U16_CBCIV_ENDIAN_MASK)
#define MAC_PCU_STA_ADDR_U16_CBCIV_ENDIAN_RESET                      0
#define MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_MSB                     29
#define MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_LSB                     29
#define MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_MASK                    0x20000000
#define MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_GET(x)                  (((x) & MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_MASK) >> MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_LSB)
#define MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_SET(x)                  (((0 | (x)) << MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_LSB) & MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_MASK)
#define MAC_PCU_STA_ADDR_U16_PRESERVE_SEQNUM_RESET                   1
#define MAC_PCU_STA_ADDR_U16_KSRCH_MODE_MSB                          28
#define MAC_PCU_STA_ADDR_U16_KSRCH_MODE_LSB                          28
#define MAC_PCU_STA_ADDR_U16_KSRCH_MODE_MASK                         0x10000000
#define MAC_PCU_STA_ADDR_U16_KSRCH_MODE_GET(x)                       (((x) & MAC_PCU_STA_ADDR_U16_KSRCH_MODE_MASK) >> MAC_PCU_STA_ADDR_U16_KSRCH_MODE_LSB)
#define MAC_PCU_STA_ADDR_U16_KSRCH_MODE_SET(x)                       (((0 | (x)) << MAC_PCU_STA_ADDR_U16_KSRCH_MODE_LSB) & MAC_PCU_STA_ADDR_U16_KSRCH_MODE_MASK)
#define MAC_PCU_STA_ADDR_U16_KSRCH_MODE_RESET                        0
#define MAC_PCU_STA_ADDR_U16_CRPT_MIC_ENABLE_MSB                     27
#define MAC_PCU_STA_ADDR_U16_CRPT_MIC_ENABLE_LSB                     27
#define MAC_PCU_STA_ADDR_U16_CRPT_MIC_ENABLE_MASK                    0x08000000
#define MAC_PCU_STA_ADDR_U16_CRPT_MIC_ENABLE_GET(x)                  (((x) & MAC_PCU_STA_ADDR_U16_CRPT_MIC_ENABLE_MASK) >> MAC_PCU_STA_ADDR_U16_CRPT_MIC_ENABLE_LSB)
#define MAC_PCU_STA_ADDR_U16_CRPT_MIC_ENABLE_SET(x)                  (((0 | (x)) << MAC_PCU_STA_ADDR_U16_CRPT_MIC_ENABLE_LSB) & MAC_PCU_STA_ADDR_U16_CRPT_MIC_ENABLE_MASK)
#define MAC_PCU_STA_ADDR_U16_CRPT_MIC_ENABLE_RESET                   0
#define MAC_PCU_STA_ADDR_U16_SECTOR_SELF_GEN_MSB                     26
#define MAC_PCU_STA_ADDR_U16_SECTOR_SELF_GEN_LSB                     26
#define MAC_PCU_STA_ADDR_U16_SECTOR_SELF_GEN_MASK                    0x04000000
#define MAC_PCU_STA_ADDR_U16_SECTOR_SELF_GEN_GET(x)                  (((x) & MAC_PCU_STA_ADDR_U16_SECTOR_SELF_GEN_MASK) >> MAC_PCU_STA_ADDR_U16_SECTOR_SELF_GEN_LSB)
#define MAC_PCU_STA_ADDR_U16_SECTOR_SELF_GEN_SET(x)                  (((0 | (x)) << MAC_PCU_STA_ADDR_U16_SECTOR_SELF_GEN_LSB) & MAC_PCU_STA_ADDR_U16_SECTOR_SELF_GEN_MASK)
#define MAC_PCU_STA_ADDR_U16_SECTOR_SELF_GEN_RESET                   0
#define MAC_PCU_STA_ADDR_U16_BASE_RATE_11B_MSB                       25
#define MAC_PCU_STA_ADDR_U16_BASE_RATE_11B_LSB                       25
#define MAC_PCU_STA_ADDR_U16_BASE_RATE_11B_MASK                      0x02000000
#define MAC_PCU_STA_ADDR_U16_BASE_RATE_11B_GET(x)                    (((x) & MAC_PCU_STA_ADDR_U16_BASE_RATE_11B_MASK) >> MAC_PCU_STA_ADDR_U16_BASE_RATE_11B_LSB)
#define MAC_PCU_STA_ADDR_U16_BASE_RATE_11B_SET(x)                    (((0 | (x)) << MAC_PCU_STA_ADDR_U16_BASE_RATE_11B_LSB) & MAC_PCU_STA_ADDR_U16_BASE_RATE_11B_MASK)
#define MAC_PCU_STA_ADDR_U16_BASE_RATE_11B_RESET                     0
#define MAC_PCU_STA_ADDR_U16_ACKCTS_6MB_MSB                          24
#define MAC_PCU_STA_ADDR_U16_ACKCTS_6MB_LSB                          24
#define MAC_PCU_STA_ADDR_U16_ACKCTS_6MB_MASK                         0x01000000
#define MAC_PCU_STA_ADDR_U16_ACKCTS_6MB_GET(x)                       (((x) & MAC_PCU_STA_ADDR_U16_ACKCTS_6MB_MASK) >> MAC_PCU_STA_ADDR_U16_ACKCTS_6MB_LSB)
#define MAC_PCU_STA_ADDR_U16_ACKCTS_6MB_SET(x)                       (((0 | (x)) << MAC_PCU_STA_ADDR_U16_ACKCTS_6MB_LSB) & MAC_PCU_STA_ADDR_U16_ACKCTS_6MB_MASK)
#define MAC_PCU_STA_ADDR_U16_ACKCTS_6MB_RESET                        0
#define MAC_PCU_STA_ADDR_U16_RTS_USE_DEF_MSB                         23
#define MAC_PCU_STA_ADDR_U16_RTS_USE_DEF_LSB                         23
#define MAC_PCU_STA_ADDR_U16_RTS_USE_DEF_MASK                        0x00800000
#define MAC_PCU_STA_ADDR_U16_RTS_USE_DEF_GET(x)                      (((x) & MAC_PCU_STA_ADDR_U16_RTS_USE_DEF_MASK) >> MAC_PCU_STA_ADDR_U16_RTS_USE_DEF_LSB)
#define MAC_PCU_STA_ADDR_U16_RTS_USE_DEF_SET(x)                      (((0 | (x)) << MAC_PCU_STA_ADDR_U16_RTS_USE_DEF_LSB) & MAC_PCU_STA_ADDR_U16_RTS_USE_DEF_MASK)
#define MAC_PCU_STA_ADDR_U16_RTS_USE_DEF_RESET                       0
#define MAC_PCU_STA_ADDR_U16_DEFANT_UPDATE_MSB                       22
#define MAC_PCU_STA_ADDR_U16_DEFANT_UPDATE_LSB                       22
#define MAC_PCU_STA_ADDR_U16_DEFANT_UPDATE_MASK                      0x00400000
#define MAC_PCU_STA_ADDR_U16_DEFANT_UPDATE_GET(x)                    (((x) & MAC_PCU_STA_ADDR_U16_DEFANT_UPDATE_MASK) >> MAC_PCU_STA_ADDR_U16_DEFANT_UPDATE_LSB)
#define MAC_PCU_STA_ADDR_U16_DEFANT_UPDATE_SET(x)                    (((0 | (x)) << MAC_PCU_STA_ADDR_U16_DEFANT_UPDATE_LSB) & MAC_PCU_STA_ADDR_U16_DEFANT_UPDATE_MASK)
#define MAC_PCU_STA_ADDR_U16_DEFANT_UPDATE_RESET                     0
#define MAC_PCU_STA_ADDR_U16_USE_DEFANT_MSB                          21
#define MAC_PCU_STA_ADDR_U16_USE_DEFANT_LSB                          21
#define MAC_PCU_STA_ADDR_U16_USE_DEFANT_MASK                         0x00200000
#define MAC_PCU_STA_ADDR_U16_USE_DEFANT_GET(x)                       (((x) & MAC_PCU_STA_ADDR_U16_USE_DEFANT_MASK) >> MAC_PCU_STA_ADDR_U16_USE_DEFANT_LSB)
#define MAC_PCU_STA_ADDR_U16_USE_DEFANT_SET(x)                       (((0 | (x)) << MAC_PCU_STA_ADDR_U16_USE_DEFANT_LSB) & MAC_PCU_STA_ADDR_U16_USE_DEFANT_MASK)
#define MAC_PCU_STA_ADDR_U16_USE_DEFANT_RESET                        0
#define MAC_PCU_STA_ADDR_U16_PCF_MSB                                 20
#define MAC_PCU_STA_ADDR_U16_PCF_LSB                                 20
#define MAC_PCU_STA_ADDR_U16_PCF_MASK                                0x00100000
#define MAC_PCU_STA_ADDR_U16_PCF_GET(x)                              (((x) & MAC_PCU_STA_ADDR_U16_PCF_MASK) >> MAC_PCU_STA_ADDR_U16_PCF_LSB)
#define MAC_PCU_STA_ADDR_U16_PCF_SET(x)                              (((0 | (x)) << MAC_PCU_STA_ADDR_U16_PCF_LSB) & MAC_PCU_STA_ADDR_U16_PCF_MASK)
#define MAC_PCU_STA_ADDR_U16_PCF_RESET                               0
#define MAC_PCU_STA_ADDR_U16_KEYSRCH_DIS_MSB                         19
#define MAC_PCU_STA_ADDR_U16_KEYSRCH_DIS_LSB                         19
#define MAC_PCU_STA_ADDR_U16_KEYSRCH_DIS_MASK                        0x00080000
#define MAC_PCU_STA_ADDR_U16_KEYSRCH_DIS_GET(x)                      (((x) & MAC_PCU_STA_ADDR_U16_KEYSRCH_DIS_MASK) >> MAC_PCU_STA_ADDR_U16_KEYSRCH_DIS_LSB)
#define MAC_PCU_STA_ADDR_U16_KEYSRCH_DIS_SET(x)                      (((0 | (x)) << MAC_PCU_STA_ADDR_U16_KEYSRCH_DIS_LSB) & MAC_PCU_STA_ADDR_U16_KEYSRCH_DIS_MASK)
#define MAC_PCU_STA_ADDR_U16_KEYSRCH_DIS_RESET                       0
#define MAC_PCU_STA_ADDR_U16_PW_SAVE_MSB                             18
#define MAC_PCU_STA_ADDR_U16_PW_SAVE_LSB                             18
#define MAC_PCU_STA_ADDR_U16_PW_SAVE_MASK                            0x00040000
#define MAC_PCU_STA_ADDR_U16_PW_SAVE_GET(x)                          (((x) & MAC_PCU_STA_ADDR_U16_PW_SAVE_MASK) >> MAC_PCU_STA_ADDR_U16_PW_SAVE_LSB)
#define MAC_PCU_STA_ADDR_U16_PW_SAVE_SET(x)                          (((0 | (x)) << MAC_PCU_STA_ADDR_U16_PW_SAVE_LSB) & MAC_PCU_STA_ADDR_U16_PW_SAVE_MASK)
#define MAC_PCU_STA_ADDR_U16_PW_SAVE_RESET                           0
#define MAC_PCU_STA_ADDR_U16_ADHOC_MSB                               17
#define MAC_PCU_STA_ADDR_U16_ADHOC_LSB                               17
#define MAC_PCU_STA_ADDR_U16_ADHOC_MASK                              0x00020000
#define MAC_PCU_STA_ADDR_U16_ADHOC_GET(x)                            (((x) & MAC_PCU_STA_ADDR_U16_ADHOC_MASK) >> MAC_PCU_STA_ADDR_U16_ADHOC_LSB)
#define MAC_PCU_STA_ADDR_U16_ADHOC_SET(x)                            (((0 | (x)) << MAC_PCU_STA_ADDR_U16_ADHOC_LSB) & MAC_PCU_STA_ADDR_U16_ADHOC_MASK)
#define MAC_PCU_STA_ADDR_U16_ADHOC_RESET                             0
#define MAC_PCU_STA_ADDR_U16_STA_AP_MSB                              16
#define MAC_PCU_STA_ADDR_U16_STA_AP_LSB                              16
#define MAC_PCU_STA_ADDR_U16_STA_AP_MASK                             0x00010000
#define MAC_PCU_STA_ADDR_U16_STA_AP_GET(x)                           (((x) & MAC_PCU_STA_ADDR_U16_STA_AP_MASK) >> MAC_PCU_STA_ADDR_U16_STA_AP_LSB)
#define MAC_PCU_STA_ADDR_U16_STA_AP_SET(x)                           (((0 | (x)) << MAC_PCU_STA_ADDR_U16_STA_AP_LSB) & MAC_PCU_STA_ADDR_U16_STA_AP_MASK)
#define MAC_PCU_STA_ADDR_U16_STA_AP_RESET                            0
#define MAC_PCU_STA_ADDR_U16_ADDR_47_32_MSB                          15
#define MAC_PCU_STA_ADDR_U16_ADDR_47_32_LSB                          0
#define MAC_PCU_STA_ADDR_U16_ADDR_47_32_MASK                         0x0000ffff
#define MAC_PCU_STA_ADDR_U16_ADDR_47_32_GET(x)                       (((x) & MAC_PCU_STA_ADDR_U16_ADDR_47_32_MASK) >> MAC_PCU_STA_ADDR_U16_ADDR_47_32_LSB)
#define MAC_PCU_STA_ADDR_U16_ADDR_47_32_SET(x)                       (((0 | (x)) << MAC_PCU_STA_ADDR_U16_ADDR_47_32_LSB) & MAC_PCU_STA_ADDR_U16_ADDR_47_32_MASK)
#define MAC_PCU_STA_ADDR_U16_ADDR_47_32_RESET                        0
#define MAC_PCU_STA_ADDR_U16_ADDRESS                                 0x8004
#define MAC_PCU_STA_ADDR_U16_HW_MASK                                 0xffffffff
#define MAC_PCU_STA_ADDR_U16_SW_MASK                                 0xffffffff
#define MAC_PCU_STA_ADDR_U16_HW_WRITE_MASK                           0x00000000
#define MAC_PCU_STA_ADDR_U16_SW_WRITE_MASK                           0xffffffff
#define MAC_PCU_STA_ADDR_U16_RSTMASK                                 0xffffffff
#define MAC_PCU_STA_ADDR_U16_RESET                                   0x20000000

// 0x8008 (MAC_PCU_BSSID_L32)
#define MAC_PCU_BSSID_L32_ADDR_MSB                                   31
#define MAC_PCU_BSSID_L32_ADDR_LSB                                   0
#define MAC_PCU_BSSID_L32_ADDR_MASK                                  0xffffffff
#define MAC_PCU_BSSID_L32_ADDR_GET(x)                                (((x) & MAC_PCU_BSSID_L32_ADDR_MASK) >> MAC_PCU_BSSID_L32_ADDR_LSB)
#define MAC_PCU_BSSID_L32_ADDR_SET(x)                                (((0 | (x)) << MAC_PCU_BSSID_L32_ADDR_LSB) & MAC_PCU_BSSID_L32_ADDR_MASK)
#define MAC_PCU_BSSID_L32_ADDR_RESET                                 0
#define MAC_PCU_BSSID_L32_ADDRESS                                    0x8008
#define MAC_PCU_BSSID_L32_HW_MASK                                    0xffffffff
#define MAC_PCU_BSSID_L32_SW_MASK                                    0xffffffff
#define MAC_PCU_BSSID_L32_HW_WRITE_MASK                              0x00000000
#define MAC_PCU_BSSID_L32_SW_WRITE_MASK                              0xffffffff
#define MAC_PCU_BSSID_L32_RSTMASK                                    0xffffffff
#define MAC_PCU_BSSID_L32_RESET                                      0x00000000

// 0x800c (MAC_PCU_BSSID_U16)
#define MAC_PCU_BSSID_U16_AID_MSB                                    26
#define MAC_PCU_BSSID_U16_AID_LSB                                    16
#define MAC_PCU_BSSID_U16_AID_MASK                                   0x07ff0000
#define MAC_PCU_BSSID_U16_AID_GET(x)                                 (((x) & MAC_PCU_BSSID_U16_AID_MASK) >> MAC_PCU_BSSID_U16_AID_LSB)
#define MAC_PCU_BSSID_U16_AID_SET(x)                                 (((0 | (x)) << MAC_PCU_BSSID_U16_AID_LSB) & MAC_PCU_BSSID_U16_AID_MASK)
#define MAC_PCU_BSSID_U16_AID_RESET                                  0
#define MAC_PCU_BSSID_U16_ADDR_MSB                                   15
#define MAC_PCU_BSSID_U16_ADDR_LSB                                   0
#define MAC_PCU_BSSID_U16_ADDR_MASK                                  0x0000ffff
#define MAC_PCU_BSSID_U16_ADDR_GET(x)                                (((x) & MAC_PCU_BSSID_U16_ADDR_MASK) >> MAC_PCU_BSSID_U16_ADDR_LSB)
#define MAC_PCU_BSSID_U16_ADDR_SET(x)                                (((0 | (x)) << MAC_PCU_BSSID_U16_ADDR_LSB) & MAC_PCU_BSSID_U16_ADDR_MASK)
#define MAC_PCU_BSSID_U16_ADDR_RESET                                 0
#define MAC_PCU_BSSID_U16_ADDRESS                                    0x800c
#define MAC_PCU_BSSID_U16_HW_MASK                                    0x07ffffff
#define MAC_PCU_BSSID_U16_SW_MASK                                    0x07ffffff
#define MAC_PCU_BSSID_U16_HW_WRITE_MASK                              0x00000000
#define MAC_PCU_BSSID_U16_SW_WRITE_MASK                              0x07ffffff
#define MAC_PCU_BSSID_U16_RSTMASK                                    0xffffffff
#define MAC_PCU_BSSID_U16_RESET                                      0x00000000

// 0x8010 (MAC_PCU_BCN_RSSI_AVE)
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE2_MSB                          27
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE2_LSB                          16
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE2_MASK                         0x0fff0000
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE2_GET(x)                       (((x) & MAC_PCU_BCN_RSSI_AVE_AVE_VALUE2_MASK) >> MAC_PCU_BCN_RSSI_AVE_AVE_VALUE2_LSB)
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE2_SET(x)                       (((0 | (x)) << MAC_PCU_BCN_RSSI_AVE_AVE_VALUE2_LSB) & MAC_PCU_BCN_RSSI_AVE_AVE_VALUE2_MASK)
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE2_RESET                        2048
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE_MSB                           11
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE_LSB                           0
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE_MASK                          0x00000fff
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE_GET(x)                        (((x) & MAC_PCU_BCN_RSSI_AVE_AVE_VALUE_MASK) >> MAC_PCU_BCN_RSSI_AVE_AVE_VALUE_LSB)
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE_SET(x)                        (((0 | (x)) << MAC_PCU_BCN_RSSI_AVE_AVE_VALUE_LSB) & MAC_PCU_BCN_RSSI_AVE_AVE_VALUE_MASK)
#define MAC_PCU_BCN_RSSI_AVE_AVE_VALUE_RESET                         2048
#define MAC_PCU_BCN_RSSI_AVE_ADDRESS                                 0x8010
#define MAC_PCU_BCN_RSSI_AVE_HW_MASK                                 0x0fff0fff
#define MAC_PCU_BCN_RSSI_AVE_SW_MASK                                 0x0fff0fff
#define MAC_PCU_BCN_RSSI_AVE_HW_WRITE_MASK                           0x0fff0fff
#define MAC_PCU_BCN_RSSI_AVE_SW_WRITE_MASK                           0x00000000
#define MAC_PCU_BCN_RSSI_AVE_RSTMASK                                 0xffffffff
#define MAC_PCU_BCN_RSSI_AVE_RESET                                   0x08000800

// 0x8014 (MAC_PCU_ACK_CTS_TIMEOUT)
#define MAC_PCU_ACK_CTS_TIMEOUT_CTS_TIMEOUT_MSB                      29
#define MAC_PCU_ACK_CTS_TIMEOUT_CTS_TIMEOUT_LSB                      16
#define MAC_PCU_ACK_CTS_TIMEOUT_CTS_TIMEOUT_MASK                     0x3fff0000
#define MAC_PCU_ACK_CTS_TIMEOUT_CTS_TIMEOUT_GET(x)                   (((x) & MAC_PCU_ACK_CTS_TIMEOUT_CTS_TIMEOUT_MASK) >> MAC_PCU_ACK_CTS_TIMEOUT_CTS_TIMEOUT_LSB)
#define MAC_PCU_ACK_CTS_TIMEOUT_CTS_TIMEOUT_SET(x)                   (((0 | (x)) << MAC_PCU_ACK_CTS_TIMEOUT_CTS_TIMEOUT_LSB) & MAC_PCU_ACK_CTS_TIMEOUT_CTS_TIMEOUT_MASK)
#define MAC_PCU_ACK_CTS_TIMEOUT_CTS_TIMEOUT_RESET                    0
#define MAC_PCU_ACK_CTS_TIMEOUT_ACK_TIMEOUT_MSB                      13
#define MAC_PCU_ACK_CTS_TIMEOUT_ACK_TIMEOUT_LSB                      0
#define MAC_PCU_ACK_CTS_TIMEOUT_ACK_TIMEOUT_MASK                     0x00003fff
#define MAC_PCU_ACK_CTS_TIMEOUT_ACK_TIMEOUT_GET(x)                   (((x) & MAC_PCU_ACK_CTS_TIMEOUT_ACK_TIMEOUT_MASK) >> MAC_PCU_ACK_CTS_TIMEOUT_ACK_TIMEOUT_LSB)
#define MAC_PCU_ACK_CTS_TIMEOUT_ACK_TIMEOUT_SET(x)                   (((0 | (x)) << MAC_PCU_ACK_CTS_TIMEOUT_ACK_TIMEOUT_LSB) & MAC_PCU_ACK_CTS_TIMEOUT_ACK_TIMEOUT_MASK)
#define MAC_PCU_ACK_CTS_TIMEOUT_ACK_TIMEOUT_RESET                    0
#define MAC_PCU_ACK_CTS_TIMEOUT_ADDRESS                              0x8014
#define MAC_PCU_ACK_CTS_TIMEOUT_HW_MASK                              0x3fff3fff
#define MAC_PCU_ACK_CTS_TIMEOUT_SW_MASK                              0x3fff3fff
#define MAC_PCU_ACK_CTS_TIMEOUT_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_ACK_CTS_TIMEOUT_SW_WRITE_MASK                        0x3fff3fff
#define MAC_PCU_ACK_CTS_TIMEOUT_RSTMASK                              0xffffffff
#define MAC_PCU_ACK_CTS_TIMEOUT_RESET                                0x00000000

// 0x8018 (MAC_PCU_BCN_RSSI_CTL)
#define MAC_PCU_BCN_RSSI_CTL_RESET_MSB                               29
#define MAC_PCU_BCN_RSSI_CTL_RESET_LSB                               29
#define MAC_PCU_BCN_RSSI_CTL_RESET_MASK                              0x20000000
#define MAC_PCU_BCN_RSSI_CTL_RESET_GET(x)                            (((x) & MAC_PCU_BCN_RSSI_CTL_RESET_MASK) >> MAC_PCU_BCN_RSSI_CTL_RESET_LSB)
#define MAC_PCU_BCN_RSSI_CTL_RESET_SET(x)                            (((0 | (x)) << MAC_PCU_BCN_RSSI_CTL_RESET_LSB) & MAC_PCU_BCN_RSSI_CTL_RESET_MASK)
#define MAC_PCU_BCN_RSSI_CTL_RESET_RESET                             0
#define MAC_PCU_BCN_RSSI_CTL_WEIGHT_MSB                              28
#define MAC_PCU_BCN_RSSI_CTL_WEIGHT_LSB                              24
#define MAC_PCU_BCN_RSSI_CTL_WEIGHT_MASK                             0x1f000000
#define MAC_PCU_BCN_RSSI_CTL_WEIGHT_GET(x)                           (((x) & MAC_PCU_BCN_RSSI_CTL_WEIGHT_MASK) >> MAC_PCU_BCN_RSSI_CTL_WEIGHT_LSB)
#define MAC_PCU_BCN_RSSI_CTL_WEIGHT_SET(x)                           (((0 | (x)) << MAC_PCU_BCN_RSSI_CTL_WEIGHT_LSB) & MAC_PCU_BCN_RSSI_CTL_WEIGHT_MASK)
#define MAC_PCU_BCN_RSSI_CTL_WEIGHT_RESET                            0
#define MAC_PCU_BCN_RSSI_CTL_RSSI_HIGH_THRESH_MSB                    23
#define MAC_PCU_BCN_RSSI_CTL_RSSI_HIGH_THRESH_LSB                    16
#define MAC_PCU_BCN_RSSI_CTL_RSSI_HIGH_THRESH_MASK                   0x00ff0000
#define MAC_PCU_BCN_RSSI_CTL_RSSI_HIGH_THRESH_GET(x)                 (((x) & MAC_PCU_BCN_RSSI_CTL_RSSI_HIGH_THRESH_MASK) >> MAC_PCU_BCN_RSSI_CTL_RSSI_HIGH_THRESH_LSB)
#define MAC_PCU_BCN_RSSI_CTL_RSSI_HIGH_THRESH_SET(x)                 (((0 | (x)) << MAC_PCU_BCN_RSSI_CTL_RSSI_HIGH_THRESH_LSB) & MAC_PCU_BCN_RSSI_CTL_RSSI_HIGH_THRESH_MASK)
#define MAC_PCU_BCN_RSSI_CTL_RSSI_HIGH_THRESH_RESET                  0
#define MAC_PCU_BCN_RSSI_CTL_MISS_THRESH_MSB                         15
#define MAC_PCU_BCN_RSSI_CTL_MISS_THRESH_LSB                         8
#define MAC_PCU_BCN_RSSI_CTL_MISS_THRESH_MASK                        0x0000ff00
#define MAC_PCU_BCN_RSSI_CTL_MISS_THRESH_GET(x)                      (((x) & MAC_PCU_BCN_RSSI_CTL_MISS_THRESH_MASK) >> MAC_PCU_BCN_RSSI_CTL_MISS_THRESH_LSB)
#define MAC_PCU_BCN_RSSI_CTL_MISS_THRESH_SET(x)                      (((0 | (x)) << MAC_PCU_BCN_RSSI_CTL_MISS_THRESH_LSB) & MAC_PCU_BCN_RSSI_CTL_MISS_THRESH_MASK)
#define MAC_PCU_BCN_RSSI_CTL_MISS_THRESH_RESET                       0
#define MAC_PCU_BCN_RSSI_CTL_RSSI_LOW_THRESH_MSB                     7
#define MAC_PCU_BCN_RSSI_CTL_RSSI_LOW_THRESH_LSB                     0
#define MAC_PCU_BCN_RSSI_CTL_RSSI_LOW_THRESH_MASK                    0x000000ff
#define MAC_PCU_BCN_RSSI_CTL_RSSI_LOW_THRESH_GET(x)                  (((x) & MAC_PCU_BCN_RSSI_CTL_RSSI_LOW_THRESH_MASK) >> MAC_PCU_BCN_RSSI_CTL_RSSI_LOW_THRESH_LSB)
#define MAC_PCU_BCN_RSSI_CTL_RSSI_LOW_THRESH_SET(x)                  (((0 | (x)) << MAC_PCU_BCN_RSSI_CTL_RSSI_LOW_THRESH_LSB) & MAC_PCU_BCN_RSSI_CTL_RSSI_LOW_THRESH_MASK)
#define MAC_PCU_BCN_RSSI_CTL_RSSI_LOW_THRESH_RESET                   0
#define MAC_PCU_BCN_RSSI_CTL_ADDRESS                                 0x8018
#define MAC_PCU_BCN_RSSI_CTL_HW_MASK                                 0x3fffffff
#define MAC_PCU_BCN_RSSI_CTL_SW_MASK                                 0x3fffffff
#define MAC_PCU_BCN_RSSI_CTL_HW_WRITE_MASK                           0x20000000
#define MAC_PCU_BCN_RSSI_CTL_SW_WRITE_MASK                           0x3fffffff
#define MAC_PCU_BCN_RSSI_CTL_RSTMASK                                 0xffffffff
#define MAC_PCU_BCN_RSSI_CTL_RESET                                   0x00000000

// 0x801c (MAC_PCU_USEC_LATENCY)
#define MAC_PCU_USEC_LATENCY_RX_LATENCY_MSB                          28
#define MAC_PCU_USEC_LATENCY_RX_LATENCY_LSB                          23
#define MAC_PCU_USEC_LATENCY_RX_LATENCY_MASK                         0x1f800000
#define MAC_PCU_USEC_LATENCY_RX_LATENCY_GET(x)                       (((x) & MAC_PCU_USEC_LATENCY_RX_LATENCY_MASK) >> MAC_PCU_USEC_LATENCY_RX_LATENCY_LSB)
#define MAC_PCU_USEC_LATENCY_RX_LATENCY_SET(x)                       (((0 | (x)) << MAC_PCU_USEC_LATENCY_RX_LATENCY_LSB) & MAC_PCU_USEC_LATENCY_RX_LATENCY_MASK)
#define MAC_PCU_USEC_LATENCY_RX_LATENCY_RESET                        0
#define MAC_PCU_USEC_LATENCY_TX_LATENCY_MSB                          22
#define MAC_PCU_USEC_LATENCY_TX_LATENCY_LSB                          14
#define MAC_PCU_USEC_LATENCY_TX_LATENCY_MASK                         0x007fc000
#define MAC_PCU_USEC_LATENCY_TX_LATENCY_GET(x)                       (((x) & MAC_PCU_USEC_LATENCY_TX_LATENCY_MASK) >> MAC_PCU_USEC_LATENCY_TX_LATENCY_LSB)
#define MAC_PCU_USEC_LATENCY_TX_LATENCY_SET(x)                       (((0 | (x)) << MAC_PCU_USEC_LATENCY_TX_LATENCY_LSB) & MAC_PCU_USEC_LATENCY_TX_LATENCY_MASK)
#define MAC_PCU_USEC_LATENCY_TX_LATENCY_RESET                        0
#define MAC_PCU_USEC_LATENCY_USEC_MSB                                7
#define MAC_PCU_USEC_LATENCY_USEC_LSB                                0
#define MAC_PCU_USEC_LATENCY_USEC_MASK                               0x000000ff
#define MAC_PCU_USEC_LATENCY_USEC_GET(x)                             (((x) & MAC_PCU_USEC_LATENCY_USEC_MASK) >> MAC_PCU_USEC_LATENCY_USEC_LSB)
#define MAC_PCU_USEC_LATENCY_USEC_SET(x)                             (((0 | (x)) << MAC_PCU_USEC_LATENCY_USEC_LSB) & MAC_PCU_USEC_LATENCY_USEC_MASK)
#define MAC_PCU_USEC_LATENCY_USEC_RESET                              39
#define MAC_PCU_USEC_LATENCY_ADDRESS                                 0x801c
#define MAC_PCU_USEC_LATENCY_HW_MASK                                 0x1fffc0ff
#define MAC_PCU_USEC_LATENCY_SW_MASK                                 0x1fffc0ff
#define MAC_PCU_USEC_LATENCY_HW_WRITE_MASK                           0x00000000
#define MAC_PCU_USEC_LATENCY_SW_WRITE_MASK                           0x1fffc0ff
#define MAC_PCU_USEC_LATENCY_RSTMASK                                 0xffffffff
#define MAC_PCU_USEC_LATENCY_RESET                                   0x00000027

// 0x8020 (MAC_PCU_BCN_RSSI_CTL2)
#define MAC_PCU_BCN_RSSI_CTL2_RESET2_MSB                             29
#define MAC_PCU_BCN_RSSI_CTL2_RESET2_LSB                             29
#define MAC_PCU_BCN_RSSI_CTL2_RESET2_MASK                            0x20000000
#define MAC_PCU_BCN_RSSI_CTL2_RESET2_GET(x)                          (((x) & MAC_PCU_BCN_RSSI_CTL2_RESET2_MASK) >> MAC_PCU_BCN_RSSI_CTL2_RESET2_LSB)
#define MAC_PCU_BCN_RSSI_CTL2_RESET2_SET(x)                          (((0 | (x)) << MAC_PCU_BCN_RSSI_CTL2_RESET2_LSB) & MAC_PCU_BCN_RSSI_CTL2_RESET2_MASK)
#define MAC_PCU_BCN_RSSI_CTL2_RESET2_RESET                           0
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_HIGH_THRESH_MSB                  23
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_HIGH_THRESH_LSB                  16
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_HIGH_THRESH_MASK                 0x00ff0000
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_HIGH_THRESH_GET(x)               (((x) & MAC_PCU_BCN_RSSI_CTL2_RSSI2_HIGH_THRESH_MASK) >> MAC_PCU_BCN_RSSI_CTL2_RSSI2_HIGH_THRESH_LSB)
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_HIGH_THRESH_SET(x)               (((0 | (x)) << MAC_PCU_BCN_RSSI_CTL2_RSSI2_HIGH_THRESH_LSB) & MAC_PCU_BCN_RSSI_CTL2_RSSI2_HIGH_THRESH_MASK)
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_HIGH_THRESH_RESET                0
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_LOW_THRESH_MSB                   7
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_LOW_THRESH_LSB                   0
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_LOW_THRESH_MASK                  0x000000ff
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_LOW_THRESH_GET(x)                (((x) & MAC_PCU_BCN_RSSI_CTL2_RSSI2_LOW_THRESH_MASK) >> MAC_PCU_BCN_RSSI_CTL2_RSSI2_LOW_THRESH_LSB)
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_LOW_THRESH_SET(x)                (((0 | (x)) << MAC_PCU_BCN_RSSI_CTL2_RSSI2_LOW_THRESH_LSB) & MAC_PCU_BCN_RSSI_CTL2_RSSI2_LOW_THRESH_MASK)
#define MAC_PCU_BCN_RSSI_CTL2_RSSI2_LOW_THRESH_RESET                 0
#define MAC_PCU_BCN_RSSI_CTL2_ADDRESS                                0x8020
#define MAC_PCU_BCN_RSSI_CTL2_HW_MASK                                0x20ff00ff
#define MAC_PCU_BCN_RSSI_CTL2_SW_MASK                                0x20ff00ff
#define MAC_PCU_BCN_RSSI_CTL2_HW_WRITE_MASK                          0x20000000
#define MAC_PCU_BCN_RSSI_CTL2_SW_WRITE_MASK                          0x20ff00ff
#define MAC_PCU_BCN_RSSI_CTL2_RSTMASK                                0xffffffff
#define MAC_PCU_BCN_RSSI_CTL2_RESET                                  0x00000000

// 0x8024 (MAC_PCU_BT_WL_1)
#define MAC_PCU_BT_WL_1_WEIGHT_MSB                                   31
#define MAC_PCU_BT_WL_1_WEIGHT_LSB                                   0
#define MAC_PCU_BT_WL_1_WEIGHT_MASK                                  0xffffffff
#define MAC_PCU_BT_WL_1_WEIGHT_GET(x)                                (((x) & MAC_PCU_BT_WL_1_WEIGHT_MASK) >> MAC_PCU_BT_WL_1_WEIGHT_LSB)
#define MAC_PCU_BT_WL_1_WEIGHT_SET(x)                                (((0 | (x)) << MAC_PCU_BT_WL_1_WEIGHT_LSB) & MAC_PCU_BT_WL_1_WEIGHT_MASK)
#define MAC_PCU_BT_WL_1_WEIGHT_RESET                                 0
#define MAC_PCU_BT_WL_1_ADDRESS                                      0x8024
#define MAC_PCU_BT_WL_1_HW_MASK                                      0xffffffff
#define MAC_PCU_BT_WL_1_SW_MASK                                      0xffffffff
#define MAC_PCU_BT_WL_1_HW_WRITE_MASK                                0x00000000
#define MAC_PCU_BT_WL_1_SW_WRITE_MASK                                0xffffffff
#define MAC_PCU_BT_WL_1_RSTMASK                                      0xffffffff
#define MAC_PCU_BT_WL_1_RESET                                        0x00000000

// 0x8028 (MAC_PCU_BT_WL_2)
#define MAC_PCU_BT_WL_2_WEIGHT_MSB                                   31
#define MAC_PCU_BT_WL_2_WEIGHT_LSB                                   0
#define MAC_PCU_BT_WL_2_WEIGHT_MASK                                  0xffffffff
#define MAC_PCU_BT_WL_2_WEIGHT_GET(x)                                (((x) & MAC_PCU_BT_WL_2_WEIGHT_MASK) >> MAC_PCU_BT_WL_2_WEIGHT_LSB)
#define MAC_PCU_BT_WL_2_WEIGHT_SET(x)                                (((0 | (x)) << MAC_PCU_BT_WL_2_WEIGHT_LSB) & MAC_PCU_BT_WL_2_WEIGHT_MASK)
#define MAC_PCU_BT_WL_2_WEIGHT_RESET                                 0
#define MAC_PCU_BT_WL_2_ADDRESS                                      0x8028
#define MAC_PCU_BT_WL_2_HW_MASK                                      0xffffffff
#define MAC_PCU_BT_WL_2_SW_MASK                                      0xffffffff
#define MAC_PCU_BT_WL_2_HW_WRITE_MASK                                0x00000000
#define MAC_PCU_BT_WL_2_SW_WRITE_MASK                                0xffffffff
#define MAC_PCU_BT_WL_2_RSTMASK                                      0xffffffff
#define MAC_PCU_BT_WL_2_RESET                                        0x00000000

// 0x802c (MAC_PCU_BT_WL_3)
#define MAC_PCU_BT_WL_3_WEIGHT_MSB                                   31
#define MAC_PCU_BT_WL_3_WEIGHT_LSB                                   0
#define MAC_PCU_BT_WL_3_WEIGHT_MASK                                  0xffffffff
#define MAC_PCU_BT_WL_3_WEIGHT_GET(x)                                (((x) & MAC_PCU_BT_WL_3_WEIGHT_MASK) >> MAC_PCU_BT_WL_3_WEIGHT_LSB)
#define MAC_PCU_BT_WL_3_WEIGHT_SET(x)                                (((0 | (x)) << MAC_PCU_BT_WL_3_WEIGHT_LSB) & MAC_PCU_BT_WL_3_WEIGHT_MASK)
#define MAC_PCU_BT_WL_3_WEIGHT_RESET                                 0
#define MAC_PCU_BT_WL_3_ADDRESS                                      0x802c
#define MAC_PCU_BT_WL_3_HW_MASK                                      0xffffffff
#define MAC_PCU_BT_WL_3_SW_MASK                                      0xffffffff
#define MAC_PCU_BT_WL_3_HW_WRITE_MASK                                0x00000000
#define MAC_PCU_BT_WL_3_SW_WRITE_MASK                                0xffffffff
#define MAC_PCU_BT_WL_3_RSTMASK                                      0xffffffff
#define MAC_PCU_BT_WL_3_RESET                                        0x00000000

// 0x8030 (MAC_PCU_BT_WL_4)
#define MAC_PCU_BT_WL_4_WEIGHT_MSB                                   31
#define MAC_PCU_BT_WL_4_WEIGHT_LSB                                   0
#define MAC_PCU_BT_WL_4_WEIGHT_MASK                                  0xffffffff
#define MAC_PCU_BT_WL_4_WEIGHT_GET(x)                                (((x) & MAC_PCU_BT_WL_4_WEIGHT_MASK) >> MAC_PCU_BT_WL_4_WEIGHT_LSB)
#define MAC_PCU_BT_WL_4_WEIGHT_SET(x)                                (((0 | (x)) << MAC_PCU_BT_WL_4_WEIGHT_LSB) & MAC_PCU_BT_WL_4_WEIGHT_MASK)
#define MAC_PCU_BT_WL_4_WEIGHT_RESET                                 0
#define MAC_PCU_BT_WL_4_ADDRESS                                      0x8030
#define MAC_PCU_BT_WL_4_HW_MASK                                      0xffffffff
#define MAC_PCU_BT_WL_4_SW_MASK                                      0xffffffff
#define MAC_PCU_BT_WL_4_HW_WRITE_MASK                                0x00000000
#define MAC_PCU_BT_WL_4_SW_WRITE_MASK                                0xffffffff
#define MAC_PCU_BT_WL_4_RSTMASK                                      0xffffffff
#define MAC_PCU_BT_WL_4_RESET                                        0x00000000

// 0x8034 (MAC_PCU_COEX_EPTA)
#define MAC_PCU_COEX_EPTA_WT_IDX_MSB                                 12
#define MAC_PCU_COEX_EPTA_WT_IDX_LSB                                 6
#define MAC_PCU_COEX_EPTA_WT_IDX_MASK                                0x00001fc0
#define MAC_PCU_COEX_EPTA_WT_IDX_GET(x)                              (((x) & MAC_PCU_COEX_EPTA_WT_IDX_MASK) >> MAC_PCU_COEX_EPTA_WT_IDX_LSB)
#define MAC_PCU_COEX_EPTA_WT_IDX_SET(x)                              (((0 | (x)) << MAC_PCU_COEX_EPTA_WT_IDX_LSB) & MAC_PCU_COEX_EPTA_WT_IDX_MASK)
#define MAC_PCU_COEX_EPTA_WT_IDX_RESET                               0
#define MAC_PCU_COEX_EPTA_LINKID_MSB                                 5
#define MAC_PCU_COEX_EPTA_LINKID_LSB                                 0
#define MAC_PCU_COEX_EPTA_LINKID_MASK                                0x0000003f
#define MAC_PCU_COEX_EPTA_LINKID_GET(x)                              (((x) & MAC_PCU_COEX_EPTA_LINKID_MASK) >> MAC_PCU_COEX_EPTA_LINKID_LSB)
#define MAC_PCU_COEX_EPTA_LINKID_SET(x)                              (((0 | (x)) << MAC_PCU_COEX_EPTA_LINKID_LSB) & MAC_PCU_COEX_EPTA_LINKID_MASK)
#define MAC_PCU_COEX_EPTA_LINKID_RESET                               0
#define MAC_PCU_COEX_EPTA_ADDRESS                                    0x8034
#define MAC_PCU_COEX_EPTA_HW_MASK                                    0x00001fff
#define MAC_PCU_COEX_EPTA_SW_MASK                                    0x00001fff
#define MAC_PCU_COEX_EPTA_HW_WRITE_MASK                              0x00001fff
#define MAC_PCU_COEX_EPTA_SW_WRITE_MASK                              0x00001fff
#define MAC_PCU_COEX_EPTA_RSTMASK                                    0xffffffff
#define MAC_PCU_COEX_EPTA_RESET                                      0x00000000

// 0x8038 (MAC_PCU_MAX_CFP_DUR)
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_DENOMINATOR_MSB                27
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_DENOMINATOR_LSB                24
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_DENOMINATOR_MASK               0x0f000000
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_DENOMINATOR_GET(x)             (((x) & MAC_PCU_MAX_CFP_DUR_USEC_FRAC_DENOMINATOR_MASK) >> MAC_PCU_MAX_CFP_DUR_USEC_FRAC_DENOMINATOR_LSB)
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_DENOMINATOR_SET(x)             (((0 | (x)) << MAC_PCU_MAX_CFP_DUR_USEC_FRAC_DENOMINATOR_LSB) & MAC_PCU_MAX_CFP_DUR_USEC_FRAC_DENOMINATOR_MASK)
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_DENOMINATOR_RESET              0
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_NUMERATOR_MSB                  19
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_NUMERATOR_LSB                  16
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_NUMERATOR_MASK                 0x000f0000
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_NUMERATOR_GET(x)               (((x) & MAC_PCU_MAX_CFP_DUR_USEC_FRAC_NUMERATOR_MASK) >> MAC_PCU_MAX_CFP_DUR_USEC_FRAC_NUMERATOR_LSB)
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_NUMERATOR_SET(x)               (((0 | (x)) << MAC_PCU_MAX_CFP_DUR_USEC_FRAC_NUMERATOR_LSB) & MAC_PCU_MAX_CFP_DUR_USEC_FRAC_NUMERATOR_MASK)
#define MAC_PCU_MAX_CFP_DUR_USEC_FRAC_NUMERATOR_RESET                0
#define MAC_PCU_MAX_CFP_DUR_VALUE_MSB                                15
#define MAC_PCU_MAX_CFP_DUR_VALUE_LSB                                0
#define MAC_PCU_MAX_CFP_DUR_VALUE_MASK                               0x0000ffff
#define MAC_PCU_MAX_CFP_DUR_VALUE_GET(x)                             (((x) & MAC_PCU_MAX_CFP_DUR_VALUE_MASK) >> MAC_PCU_MAX_CFP_DUR_VALUE_LSB)
#define MAC_PCU_MAX_CFP_DUR_VALUE_SET(x)                             (((0 | (x)) << MAC_PCU_MAX_CFP_DUR_VALUE_LSB) & MAC_PCU_MAX_CFP_DUR_VALUE_MASK)
#define MAC_PCU_MAX_CFP_DUR_VALUE_RESET                              0
#define MAC_PCU_MAX_CFP_DUR_ADDRESS                                  0x8038
#define MAC_PCU_MAX_CFP_DUR_HW_MASK                                  0x0f0fffff
#define MAC_PCU_MAX_CFP_DUR_SW_MASK                                  0x0f0fffff
#define MAC_PCU_MAX_CFP_DUR_HW_WRITE_MASK                            0x00000000
#define MAC_PCU_MAX_CFP_DUR_SW_WRITE_MASK                            0x0f0fffff
#define MAC_PCU_MAX_CFP_DUR_RSTMASK                                  0xffffffff
#define MAC_PCU_MAX_CFP_DUR_RESET                                    0x00000000

// 0x803c (MAC_PCU_RX_FILTER)
#define MAC_PCU_RX_FILTER_BSSID_BASED_MULTICAST_MSB                  31
#define MAC_PCU_RX_FILTER_BSSID_BASED_MULTICAST_LSB                  31
#define MAC_PCU_RX_FILTER_BSSID_BASED_MULTICAST_MASK                 0x80000000
#define MAC_PCU_RX_FILTER_BSSID_BASED_MULTICAST_GET(x)               (((x) & MAC_PCU_RX_FILTER_BSSID_BASED_MULTICAST_MASK) >> MAC_PCU_RX_FILTER_BSSID_BASED_MULTICAST_LSB)
#define MAC_PCU_RX_FILTER_BSSID_BASED_MULTICAST_SET(x)               (((0 | (x)) << MAC_PCU_RX_FILTER_BSSID_BASED_MULTICAST_LSB) & MAC_PCU_RX_FILTER_BSSID_BASED_MULTICAST_MASK)
#define MAC_PCU_RX_FILTER_BSSID_BASED_MULTICAST_RESET                0
#define MAC_PCU_RX_FILTER_PHY_DATA_MSB                               30
#define MAC_PCU_RX_FILTER_PHY_DATA_LSB                               30
#define MAC_PCU_RX_FILTER_PHY_DATA_MASK                              0x40000000
#define MAC_PCU_RX_FILTER_PHY_DATA_GET(x)                            (((x) & MAC_PCU_RX_FILTER_PHY_DATA_MASK) >> MAC_PCU_RX_FILTER_PHY_DATA_LSB)
#define MAC_PCU_RX_FILTER_PHY_DATA_SET(x)                            (((0 | (x)) << MAC_PCU_RX_FILTER_PHY_DATA_LSB) & MAC_PCU_RX_FILTER_PHY_DATA_MASK)
#define MAC_PCU_RX_FILTER_PHY_DATA_RESET                             0
#define MAC_PCU_RX_FILTER_MY_BEACON2_MSB                             29
#define MAC_PCU_RX_FILTER_MY_BEACON2_LSB                             29
#define MAC_PCU_RX_FILTER_MY_BEACON2_MASK                            0x20000000
#define MAC_PCU_RX_FILTER_MY_BEACON2_GET(x)                          (((x) & MAC_PCU_RX_FILTER_MY_BEACON2_MASK) >> MAC_PCU_RX_FILTER_MY_BEACON2_LSB)
#define MAC_PCU_RX_FILTER_MY_BEACON2_SET(x)                          (((0 | (x)) << MAC_PCU_RX_FILTER_MY_BEACON2_LSB) & MAC_PCU_RX_FILTER_MY_BEACON2_MASK)
#define MAC_PCU_RX_FILTER_MY_BEACON2_RESET                           0
#define MAC_PCU_RX_FILTER_GENERIC_FILTER_MSB                         28
#define MAC_PCU_RX_FILTER_GENERIC_FILTER_LSB                         27
#define MAC_PCU_RX_FILTER_GENERIC_FILTER_MASK                        0x18000000
#define MAC_PCU_RX_FILTER_GENERIC_FILTER_GET(x)                      (((x) & MAC_PCU_RX_FILTER_GENERIC_FILTER_MASK) >> MAC_PCU_RX_FILTER_GENERIC_FILTER_LSB)
#define MAC_PCU_RX_FILTER_GENERIC_FILTER_SET(x)                      (((0 | (x)) << MAC_PCU_RX_FILTER_GENERIC_FILTER_LSB) & MAC_PCU_RX_FILTER_GENERIC_FILTER_MASK)
#define MAC_PCU_RX_FILTER_GENERIC_FILTER_RESET                       0
#define MAC_PCU_RX_FILTER_GENERIC_FTYPE_MSB                          26
#define MAC_PCU_RX_FILTER_GENERIC_FTYPE_LSB                          21
#define MAC_PCU_RX_FILTER_GENERIC_FTYPE_MASK                         0x07e00000
#define MAC_PCU_RX_FILTER_GENERIC_FTYPE_GET(x)                       (((x) & MAC_PCU_RX_FILTER_GENERIC_FTYPE_MASK) >> MAC_PCU_RX_FILTER_GENERIC_FTYPE_LSB)
#define MAC_PCU_RX_FILTER_GENERIC_FTYPE_SET(x)                       (((0 | (x)) << MAC_PCU_RX_FILTER_GENERIC_FTYPE_LSB) & MAC_PCU_RX_FILTER_GENERIC_FTYPE_MASK)
#define MAC_PCU_RX_FILTER_GENERIC_FTYPE_RESET                        0
#define MAC_PCU_RX_FILTER_FROM_TO_DS_MSB                             20
#define MAC_PCU_RX_FILTER_FROM_TO_DS_LSB                             20
#define MAC_PCU_RX_FILTER_FROM_TO_DS_MASK                            0x00100000
#define MAC_PCU_RX_FILTER_FROM_TO_DS_GET(x)                          (((x) & MAC_PCU_RX_FILTER_FROM_TO_DS_MASK) >> MAC_PCU_RX_FILTER_FROM_TO_DS_LSB)
#define MAC_PCU_RX_FILTER_FROM_TO_DS_SET(x)                          (((0 | (x)) << MAC_PCU_RX_FILTER_FROM_TO_DS_LSB) & MAC_PCU_RX_FILTER_FROM_TO_DS_MASK)
#define MAC_PCU_RX_FILTER_FROM_TO_DS_RESET                           0
#define MAC_PCU_RX_FILTER_CONTROL_WRAPPER_MSB                        19
#define MAC_PCU_RX_FILTER_CONTROL_WRAPPER_LSB                        19
#define MAC_PCU_RX_FILTER_CONTROL_WRAPPER_MASK                       0x00080000
#define MAC_PCU_RX_FILTER_CONTROL_WRAPPER_GET(x)                     (((x) & MAC_PCU_RX_FILTER_CONTROL_WRAPPER_MASK) >> MAC_PCU_RX_FILTER_CONTROL_WRAPPER_LSB)
#define MAC_PCU_RX_FILTER_CONTROL_WRAPPER_SET(x)                     (((0 | (x)) << MAC_PCU_RX_FILTER_CONTROL_WRAPPER_LSB) & MAC_PCU_RX_FILTER_CONTROL_WRAPPER_MASK)
#define MAC_PCU_RX_FILTER_CONTROL_WRAPPER_RESET                      0
#define MAC_PCU_RX_FILTER_MGMT_ACTION_MCAST_MSB                      18
#define MAC_PCU_RX_FILTER_MGMT_ACTION_MCAST_LSB                      18
#define MAC_PCU_RX_FILTER_MGMT_ACTION_MCAST_MASK                     0x00040000
#define MAC_PCU_RX_FILTER_MGMT_ACTION_MCAST_GET(x)                   (((x) & MAC_PCU_RX_FILTER_MGMT_ACTION_MCAST_MASK) >> MAC_PCU_RX_FILTER_MGMT_ACTION_MCAST_LSB)
#define MAC_PCU_RX_FILTER_MGMT_ACTION_MCAST_SET(x)                   (((0 | (x)) << MAC_PCU_RX_FILTER_MGMT_ACTION_MCAST_LSB) & MAC_PCU_RX_FILTER_MGMT_ACTION_MCAST_MASK)
#define MAC_PCU_RX_FILTER_MGMT_ACTION_MCAST_RESET                    0
#define MAC_PCU_RX_FILTER_HW_BCN_PROC_ENABLE_MSB                     17
#define MAC_PCU_RX_FILTER_HW_BCN_PROC_ENABLE_LSB                     17
#define MAC_PCU_RX_FILTER_HW_BCN_PROC_ENABLE_MASK                    0x00020000
#define MAC_PCU_RX_FILTER_HW_BCN_PROC_ENABLE_GET(x)                  (((x) & MAC_PCU_RX_FILTER_HW_BCN_PROC_ENABLE_MASK) >> MAC_PCU_RX_FILTER_HW_BCN_PROC_ENABLE_LSB)
#define MAC_PCU_RX_FILTER_HW_BCN_PROC_ENABLE_SET(x)                  (((0 | (x)) << MAC_PCU_RX_FILTER_HW_BCN_PROC_ENABLE_LSB) & MAC_PCU_RX_FILTER_HW_BCN_PROC_ENABLE_MASK)
#define MAC_PCU_RX_FILTER_HW_BCN_PROC_ENABLE_RESET                   0
#define MAC_PCU_RX_FILTER_RST_DLMTR_CNT_DISABLE_MSB                  16
#define MAC_PCU_RX_FILTER_RST_DLMTR_CNT_DISABLE_LSB                  16
#define MAC_PCU_RX_FILTER_RST_DLMTR_CNT_DISABLE_MASK                 0x00010000
#define MAC_PCU_RX_FILTER_RST_DLMTR_CNT_DISABLE_GET(x)               (((x) & MAC_PCU_RX_FILTER_RST_DLMTR_CNT_DISABLE_MASK) >> MAC_PCU_RX_FILTER_RST_DLMTR_CNT_DISABLE_LSB)
#define MAC_PCU_RX_FILTER_RST_DLMTR_CNT_DISABLE_SET(x)               (((0 | (x)) << MAC_PCU_RX_FILTER_RST_DLMTR_CNT_DISABLE_LSB) & MAC_PCU_RX_FILTER_RST_DLMTR_CNT_DISABLE_MASK)
#define MAC_PCU_RX_FILTER_RST_DLMTR_CNT_DISABLE_RESET                0
#define MAC_PCU_RX_FILTER_MCAST_BCAST_ALL_MSB                        15
#define MAC_PCU_RX_FILTER_MCAST_BCAST_ALL_LSB                        15
#define MAC_PCU_RX_FILTER_MCAST_BCAST_ALL_MASK                       0x00008000
#define MAC_PCU_RX_FILTER_MCAST_BCAST_ALL_GET(x)                     (((x) & MAC_PCU_RX_FILTER_MCAST_BCAST_ALL_MASK) >> MAC_PCU_RX_FILTER_MCAST_BCAST_ALL_LSB)
#define MAC_PCU_RX_FILTER_MCAST_BCAST_ALL_SET(x)                     (((0 | (x)) << MAC_PCU_RX_FILTER_MCAST_BCAST_ALL_LSB) & MAC_PCU_RX_FILTER_MCAST_BCAST_ALL_MASK)
#define MAC_PCU_RX_FILTER_MCAST_BCAST_ALL_RESET                      0
#define MAC_PCU_RX_FILTER_PS_POLL_MSB                                14
#define MAC_PCU_RX_FILTER_PS_POLL_LSB                                14
#define MAC_PCU_RX_FILTER_PS_POLL_MASK                               0x00004000
#define MAC_PCU_RX_FILTER_PS_POLL_GET(x)                             (((x) & MAC_PCU_RX_FILTER_PS_POLL_MASK) >> MAC_PCU_RX_FILTER_PS_POLL_LSB)
#define MAC_PCU_RX_FILTER_PS_POLL_SET(x)                             (((0 | (x)) << MAC_PCU_RX_FILTER_PS_POLL_LSB) & MAC_PCU_RX_FILTER_PS_POLL_MASK)
#define MAC_PCU_RX_FILTER_PS_POLL_RESET                              0
#define MAC_PCU_RX_FILTER_RESERVED_MSB                               13
#define MAC_PCU_RX_FILTER_RESERVED_LSB                               13
#define MAC_PCU_RX_FILTER_RESERVED_MASK                              0x00002000
#define MAC_PCU_RX_FILTER_RESERVED_GET(x)                            (((x) & MAC_PCU_RX_FILTER_RESERVED_MASK) >> MAC_PCU_RX_FILTER_RESERVED_LSB)
#define MAC_PCU_RX_FILTER_RESERVED_SET(x)                            (((0 | (x)) << MAC_PCU_RX_FILTER_RESERVED_LSB) & MAC_PCU_RX_FILTER_RESERVED_MASK)
#define MAC_PCU_RX_FILTER_RESERVED_RESET                             0
#define MAC_PCU_RX_FILTER_UNCOMPRESSED_BA_BAR_MSB                    12
#define MAC_PCU_RX_FILTER_UNCOMPRESSED_BA_BAR_LSB                    12
#define MAC_PCU_RX_FILTER_UNCOMPRESSED_BA_BAR_MASK                   0x00001000
#define MAC_PCU_RX_FILTER_UNCOMPRESSED_BA_BAR_GET(x)                 (((x) & MAC_PCU_RX_FILTER_UNCOMPRESSED_BA_BAR_MASK) >> MAC_PCU_RX_FILTER_UNCOMPRESSED_BA_BAR_LSB)
#define MAC_PCU_RX_FILTER_UNCOMPRESSED_BA_BAR_SET(x)                 (((0 | (x)) << MAC_PCU_RX_FILTER_UNCOMPRESSED_BA_BAR_LSB) & MAC_PCU_RX_FILTER_UNCOMPRESSED_BA_BAR_MASK)
#define MAC_PCU_RX_FILTER_UNCOMPRESSED_BA_BAR_RESET                  0
#define MAC_PCU_RX_FILTER_COMPRESSED_BA_MSB                          11
#define MAC_PCU_RX_FILTER_COMPRESSED_BA_LSB                          11
#define MAC_PCU_RX_FILTER_COMPRESSED_BA_MASK                         0x00000800
#define MAC_PCU_RX_FILTER_COMPRESSED_BA_GET(x)                       (((x) & MAC_PCU_RX_FILTER_COMPRESSED_BA_MASK) >> MAC_PCU_RX_FILTER_COMPRESSED_BA_LSB)
#define MAC_PCU_RX_FILTER_COMPRESSED_BA_SET(x)                       (((0 | (x)) << MAC_PCU_RX_FILTER_COMPRESSED_BA_LSB) & MAC_PCU_RX_FILTER_COMPRESSED_BA_MASK)
#define MAC_PCU_RX_FILTER_COMPRESSED_BA_RESET                        0
#define MAC_PCU_RX_FILTER_COMPRESSED_BAR_MSB                         10
#define MAC_PCU_RX_FILTER_COMPRESSED_BAR_LSB                         10
#define MAC_PCU_RX_FILTER_COMPRESSED_BAR_MASK                        0x00000400
#define MAC_PCU_RX_FILTER_COMPRESSED_BAR_GET(x)                      (((x) & MAC_PCU_RX_FILTER_COMPRESSED_BAR_MASK) >> MAC_PCU_RX_FILTER_COMPRESSED_BAR_LSB)
#define MAC_PCU_RX_FILTER_COMPRESSED_BAR_SET(x)                      (((0 | (x)) << MAC_PCU_RX_FILTER_COMPRESSED_BAR_LSB) & MAC_PCU_RX_FILTER_COMPRESSED_BAR_MASK)
#define MAC_PCU_RX_FILTER_COMPRESSED_BAR_RESET                       0
#define MAC_PCU_RX_FILTER_MY_BEACON_MSB                              9
#define MAC_PCU_RX_FILTER_MY_BEACON_LSB                              9
#define MAC_PCU_RX_FILTER_MY_BEACON_MASK                             0x00000200
#define MAC_PCU_RX_FILTER_MY_BEACON_GET(x)                           (((x) & MAC_PCU_RX_FILTER_MY_BEACON_MASK) >> MAC_PCU_RX_FILTER_MY_BEACON_LSB)
#define MAC_PCU_RX_FILTER_MY_BEACON_SET(x)                           (((0 | (x)) << MAC_PCU_RX_FILTER_MY_BEACON_LSB) & MAC_PCU_RX_FILTER_MY_BEACON_MASK)
#define MAC_PCU_RX_FILTER_MY_BEACON_RESET                            0
#define MAC_PCU_RX_FILTER_SYNC_FRAME_MSB                             8
#define MAC_PCU_RX_FILTER_SYNC_FRAME_LSB                             8
#define MAC_PCU_RX_FILTER_SYNC_FRAME_MASK                            0x00000100
#define MAC_PCU_RX_FILTER_SYNC_FRAME_GET(x)                          (((x) & MAC_PCU_RX_FILTER_SYNC_FRAME_MASK) >> MAC_PCU_RX_FILTER_SYNC_FRAME_LSB)
#define MAC_PCU_RX_FILTER_SYNC_FRAME_SET(x)                          (((0 | (x)) << MAC_PCU_RX_FILTER_SYNC_FRAME_LSB) & MAC_PCU_RX_FILTER_SYNC_FRAME_MASK)
#define MAC_PCU_RX_FILTER_SYNC_FRAME_RESET                           0
#define MAC_PCU_RX_FILTER_PROBE_REQ_MSB                              7
#define MAC_PCU_RX_FILTER_PROBE_REQ_LSB                              7
#define MAC_PCU_RX_FILTER_PROBE_REQ_MASK                             0x00000080
#define MAC_PCU_RX_FILTER_PROBE_REQ_GET(x)                           (((x) & MAC_PCU_RX_FILTER_PROBE_REQ_MASK) >> MAC_PCU_RX_FILTER_PROBE_REQ_LSB)
#define MAC_PCU_RX_FILTER_PROBE_REQ_SET(x)                           (((0 | (x)) << MAC_PCU_RX_FILTER_PROBE_REQ_LSB) & MAC_PCU_RX_FILTER_PROBE_REQ_MASK)
#define MAC_PCU_RX_FILTER_PROBE_REQ_RESET                            0
#define MAC_PCU_RX_FILTER_XR_POLL_MSB                                6
#define MAC_PCU_RX_FILTER_XR_POLL_LSB                                6
#define MAC_PCU_RX_FILTER_XR_POLL_MASK                               0x00000040
#define MAC_PCU_RX_FILTER_XR_POLL_GET(x)                             (((x) & MAC_PCU_RX_FILTER_XR_POLL_MASK) >> MAC_PCU_RX_FILTER_XR_POLL_LSB)
#define MAC_PCU_RX_FILTER_XR_POLL_SET(x)                             (((0 | (x)) << MAC_PCU_RX_FILTER_XR_POLL_LSB) & MAC_PCU_RX_FILTER_XR_POLL_MASK)
#define MAC_PCU_RX_FILTER_XR_POLL_RESET                              0
#define MAC_PCU_RX_FILTER_PROMISCUOUS_MSB                            5
#define MAC_PCU_RX_FILTER_PROMISCUOUS_LSB                            5
#define MAC_PCU_RX_FILTER_PROMISCUOUS_MASK                           0x00000020
#define MAC_PCU_RX_FILTER_PROMISCUOUS_GET(x)                         (((x) & MAC_PCU_RX_FILTER_PROMISCUOUS_MASK) >> MAC_PCU_RX_FILTER_PROMISCUOUS_LSB)
#define MAC_PCU_RX_FILTER_PROMISCUOUS_SET(x)                         (((0 | (x)) << MAC_PCU_RX_FILTER_PROMISCUOUS_LSB) & MAC_PCU_RX_FILTER_PROMISCUOUS_MASK)
#define MAC_PCU_RX_FILTER_PROMISCUOUS_RESET                          0
#define MAC_PCU_RX_FILTER_BEACON_MSB                                 4
#define MAC_PCU_RX_FILTER_BEACON_LSB                                 4
#define MAC_PCU_RX_FILTER_BEACON_MASK                                0x00000010
#define MAC_PCU_RX_FILTER_BEACON_GET(x)                              (((x) & MAC_PCU_RX_FILTER_BEACON_MASK) >> MAC_PCU_RX_FILTER_BEACON_LSB)
#define MAC_PCU_RX_FILTER_BEACON_SET(x)                              (((0 | (x)) << MAC_PCU_RX_FILTER_BEACON_LSB) & MAC_PCU_RX_FILTER_BEACON_MASK)
#define MAC_PCU_RX_FILTER_BEACON_RESET                               0
#define MAC_PCU_RX_FILTER_CONTROL_MSB                                3
#define MAC_PCU_RX_FILTER_CONTROL_LSB                                3
#define MAC_PCU_RX_FILTER_CONTROL_MASK                               0x00000008
#define MAC_PCU_RX_FILTER_CONTROL_GET(x)                             (((x) & MAC_PCU_RX_FILTER_CONTROL_MASK) >> MAC_PCU_RX_FILTER_CONTROL_LSB)
#define MAC_PCU_RX_FILTER_CONTROL_SET(x)                             (((0 | (x)) << MAC_PCU_RX_FILTER_CONTROL_LSB) & MAC_PCU_RX_FILTER_CONTROL_MASK)
#define MAC_PCU_RX_FILTER_CONTROL_RESET                              0
#define MAC_PCU_RX_FILTER_BROADCAST_MSB                              2
#define MAC_PCU_RX_FILTER_BROADCAST_LSB                              2
#define MAC_PCU_RX_FILTER_BROADCAST_MASK                             0x00000004
#define MAC_PCU_RX_FILTER_BROADCAST_GET(x)                           (((x) & MAC_PCU_RX_FILTER_BROADCAST_MASK) >> MAC_PCU_RX_FILTER_BROADCAST_LSB)
#define MAC_PCU_RX_FILTER_BROADCAST_SET(x)                           (((0 | (x)) << MAC_PCU_RX_FILTER_BROADCAST_LSB) & MAC_PCU_RX_FILTER_BROADCAST_MASK)
#define MAC_PCU_RX_FILTER_BROADCAST_RESET                            0
#define MAC_PCU_RX_FILTER_MULTICAST_MSB                              1
#define MAC_PCU_RX_FILTER_MULTICAST_LSB                              1
#define MAC_PCU_RX_FILTER_MULTICAST_MASK                             0x00000002
#define MAC_PCU_RX_FILTER_MULTICAST_GET(x)                           (((x) & MAC_PCU_RX_FILTER_MULTICAST_MASK) >> MAC_PCU_RX_FILTER_MULTICAST_LSB)
#define MAC_PCU_RX_FILTER_MULTICAST_SET(x)                           (((0 | (x)) << MAC_PCU_RX_FILTER_MULTICAST_LSB) & MAC_PCU_RX_FILTER_MULTICAST_MASK)
#define MAC_PCU_RX_FILTER_MULTICAST_RESET                            0
#define MAC_PCU_RX_FILTER_UNICAST_MSB                                0
#define MAC_PCU_RX_FILTER_UNICAST_LSB                                0
#define MAC_PCU_RX_FILTER_UNICAST_MASK                               0x00000001
#define MAC_PCU_RX_FILTER_UNICAST_GET(x)                             (((x) & MAC_PCU_RX_FILTER_UNICAST_MASK) >> MAC_PCU_RX_FILTER_UNICAST_LSB)
#define MAC_PCU_RX_FILTER_UNICAST_SET(x)                             (((0 | (x)) << MAC_PCU_RX_FILTER_UNICAST_LSB) & MAC_PCU_RX_FILTER_UNICAST_MASK)
#define MAC_PCU_RX_FILTER_UNICAST_RESET                              0
#define MAC_PCU_RX_FILTER_ADDRESS                                    0x803c
#define MAC_PCU_RX_FILTER_HW_MASK                                    0xffffffff
#define MAC_PCU_RX_FILTER_SW_MASK                                    0xffffffff
#define MAC_PCU_RX_FILTER_HW_WRITE_MASK                              0x00000000
#define MAC_PCU_RX_FILTER_SW_WRITE_MASK                              0xffffffff
#define MAC_PCU_RX_FILTER_RSTMASK                                    0xffffffff
#define MAC_PCU_RX_FILTER_RESET                                      0x00000000

// 0x8040 (MAC_PCU_MCAST_FILTER_L32)
#define MAC_PCU_MCAST_FILTER_L32_VALUE_MSB                           31
#define MAC_PCU_MCAST_FILTER_L32_VALUE_LSB                           0
#define MAC_PCU_MCAST_FILTER_L32_VALUE_MASK                          0xffffffff
#define MAC_PCU_MCAST_FILTER_L32_VALUE_GET(x)                        (((x) & MAC_PCU_MCAST_FILTER_L32_VALUE_MASK) >> MAC_PCU_MCAST_FILTER_L32_VALUE_LSB)
#define MAC_PCU_MCAST_FILTER_L32_VALUE_SET(x)                        (((0 | (x)) << MAC_PCU_MCAST_FILTER_L32_VALUE_LSB) & MAC_PCU_MCAST_FILTER_L32_VALUE_MASK)
#define MAC_PCU_MCAST_FILTER_L32_VALUE_RESET                         0
#define MAC_PCU_MCAST_FILTER_L32_ADDRESS                             0x8040
#define MAC_PCU_MCAST_FILTER_L32_HW_MASK                             0xffffffff
#define MAC_PCU_MCAST_FILTER_L32_SW_MASK                             0xffffffff
#define MAC_PCU_MCAST_FILTER_L32_HW_WRITE_MASK                       0x00000000
#define MAC_PCU_MCAST_FILTER_L32_SW_WRITE_MASK                       0xffffffff
#define MAC_PCU_MCAST_FILTER_L32_RSTMASK                             0xffffffff
#define MAC_PCU_MCAST_FILTER_L32_RESET                               0x00000000

// 0x8044 (MAC_PCU_MCAST_FILTER_U32)
#define MAC_PCU_MCAST_FILTER_U32_VALUE_MSB                           31
#define MAC_PCU_MCAST_FILTER_U32_VALUE_LSB                           0
#define MAC_PCU_MCAST_FILTER_U32_VALUE_MASK                          0xffffffff
#define MAC_PCU_MCAST_FILTER_U32_VALUE_GET(x)                        (((x) & MAC_PCU_MCAST_FILTER_U32_VALUE_MASK) >> MAC_PCU_MCAST_FILTER_U32_VALUE_LSB)
#define MAC_PCU_MCAST_FILTER_U32_VALUE_SET(x)                        (((0 | (x)) << MAC_PCU_MCAST_FILTER_U32_VALUE_LSB) & MAC_PCU_MCAST_FILTER_U32_VALUE_MASK)
#define MAC_PCU_MCAST_FILTER_U32_VALUE_RESET                         0
#define MAC_PCU_MCAST_FILTER_U32_ADDRESS                             0x8044
#define MAC_PCU_MCAST_FILTER_U32_HW_MASK                             0xffffffff
#define MAC_PCU_MCAST_FILTER_U32_SW_MASK                             0xffffffff
#define MAC_PCU_MCAST_FILTER_U32_HW_WRITE_MASK                       0x00000000
#define MAC_PCU_MCAST_FILTER_U32_SW_WRITE_MASK                       0xffffffff
#define MAC_PCU_MCAST_FILTER_U32_RSTMASK                             0xffffffff
#define MAC_PCU_MCAST_FILTER_U32_RESET                               0x00000000

// 0x8048 (MAC_PCU_DIAG_SW)
#define MAC_PCU_DIAG_SW_DEBUG_MODE_MSB                               31
#define MAC_PCU_DIAG_SW_DEBUG_MODE_LSB                               30
#define MAC_PCU_DIAG_SW_DEBUG_MODE_MASK                              0xc0000000
#define MAC_PCU_DIAG_SW_DEBUG_MODE_GET(x)                            (((x) & MAC_PCU_DIAG_SW_DEBUG_MODE_MASK) >> MAC_PCU_DIAG_SW_DEBUG_MODE_LSB)
#define MAC_PCU_DIAG_SW_DEBUG_MODE_SET(x)                            (((0 | (x)) << MAC_PCU_DIAG_SW_DEBUG_MODE_LSB) & MAC_PCU_DIAG_SW_DEBUG_MODE_MASK)
#define MAC_PCU_DIAG_SW_DEBUG_MODE_RESET                             0
#define MAC_PCU_DIAG_SW_RX_CLEAR_EXT_LOW_MSB                         29
#define MAC_PCU_DIAG_SW_RX_CLEAR_EXT_LOW_LSB                         29
#define MAC_PCU_DIAG_SW_RX_CLEAR_EXT_LOW_MASK                        0x20000000
#define MAC_PCU_DIAG_SW_RX_CLEAR_EXT_LOW_GET(x)                      (((x) & MAC_PCU_DIAG_SW_RX_CLEAR_EXT_LOW_MASK) >> MAC_PCU_DIAG_SW_RX_CLEAR_EXT_LOW_LSB)
#define MAC_PCU_DIAG_SW_RX_CLEAR_EXT_LOW_SET(x)                      (((0 | (x)) << MAC_PCU_DIAG_SW_RX_CLEAR_EXT_LOW_LSB) & MAC_PCU_DIAG_SW_RX_CLEAR_EXT_LOW_MASK)
#define MAC_PCU_DIAG_SW_RX_CLEAR_EXT_LOW_RESET                       0
#define MAC_PCU_DIAG_SW_RX_CLEAR_CTL_LOW_MSB                         28
#define MAC_PCU_DIAG_SW_RX_CLEAR_CTL_LOW_LSB                         28
#define MAC_PCU_DIAG_SW_RX_CLEAR_CTL_LOW_MASK                        0x10000000
#define MAC_PCU_DIAG_SW_RX_CLEAR_CTL_LOW_GET(x)                      (((x) & MAC_PCU_DIAG_SW_RX_CLEAR_CTL_LOW_MASK) >> MAC_PCU_DIAG_SW_RX_CLEAR_CTL_LOW_LSB)
#define MAC_PCU_DIAG_SW_RX_CLEAR_CTL_LOW_SET(x)                      (((0 | (x)) << MAC_PCU_DIAG_SW_RX_CLEAR_CTL_LOW_LSB) & MAC_PCU_DIAG_SW_RX_CLEAR_CTL_LOW_MASK)
#define MAC_PCU_DIAG_SW_RX_CLEAR_CTL_LOW_RESET                       0
#define MAC_PCU_DIAG_SW_OBS_SEL_2_MSB                                27
#define MAC_PCU_DIAG_SW_OBS_SEL_2_LSB                                27
#define MAC_PCU_DIAG_SW_OBS_SEL_2_MASK                               0x08000000
#define MAC_PCU_DIAG_SW_OBS_SEL_2_GET(x)                             (((x) & MAC_PCU_DIAG_SW_OBS_SEL_2_MASK) >> MAC_PCU_DIAG_SW_OBS_SEL_2_LSB)
#define MAC_PCU_DIAG_SW_OBS_SEL_2_SET(x)                             (((0 | (x)) << MAC_PCU_DIAG_SW_OBS_SEL_2_LSB) & MAC_PCU_DIAG_SW_OBS_SEL_2_MASK)
#define MAC_PCU_DIAG_SW_OBS_SEL_2_RESET                              0
#define MAC_PCU_DIAG_SW_SATURATE_CYCLE_CNT_MSB                       26
#define MAC_PCU_DIAG_SW_SATURATE_CYCLE_CNT_LSB                       26
#define MAC_PCU_DIAG_SW_SATURATE_CYCLE_CNT_MASK                      0x04000000
#define MAC_PCU_DIAG_SW_SATURATE_CYCLE_CNT_GET(x)                    (((x) & MAC_PCU_DIAG_SW_SATURATE_CYCLE_CNT_MASK) >> MAC_PCU_DIAG_SW_SATURATE_CYCLE_CNT_LSB)
#define MAC_PCU_DIAG_SW_SATURATE_CYCLE_CNT_SET(x)                    (((0 | (x)) << MAC_PCU_DIAG_SW_SATURATE_CYCLE_CNT_LSB) & MAC_PCU_DIAG_SW_SATURATE_CYCLE_CNT_MASK)
#define MAC_PCU_DIAG_SW_SATURATE_CYCLE_CNT_RESET                     0
#define MAC_PCU_DIAG_SW_FORCE_RX_ABORT_MSB                           25
#define MAC_PCU_DIAG_SW_FORCE_RX_ABORT_LSB                           25
#define MAC_PCU_DIAG_SW_FORCE_RX_ABORT_MASK                          0x02000000
#define MAC_PCU_DIAG_SW_FORCE_RX_ABORT_GET(x)                        (((x) & MAC_PCU_DIAG_SW_FORCE_RX_ABORT_MASK) >> MAC_PCU_DIAG_SW_FORCE_RX_ABORT_LSB)
#define MAC_PCU_DIAG_SW_FORCE_RX_ABORT_SET(x)                        (((0 | (x)) << MAC_PCU_DIAG_SW_FORCE_RX_ABORT_LSB) & MAC_PCU_DIAG_SW_FORCE_RX_ABORT_MASK)
#define MAC_PCU_DIAG_SW_FORCE_RX_ABORT_RESET                         0
#define MAC_PCU_DIAG_SW_DUAL_CHAIN_CHAN_INFO_MSB                     24
#define MAC_PCU_DIAG_SW_DUAL_CHAIN_CHAN_INFO_LSB                     24
#define MAC_PCU_DIAG_SW_DUAL_CHAIN_CHAN_INFO_MASK                    0x01000000
#define MAC_PCU_DIAG_SW_DUAL_CHAIN_CHAN_INFO_GET(x)                  (((x) & MAC_PCU_DIAG_SW_DUAL_CHAIN_CHAN_INFO_MASK) >> MAC_PCU_DIAG_SW_DUAL_CHAIN_CHAN_INFO_LSB)
#define MAC_PCU_DIAG_SW_DUAL_CHAIN_CHAN_INFO_SET(x)                  (((0 | (x)) << MAC_PCU_DIAG_SW_DUAL_CHAIN_CHAN_INFO_LSB) & MAC_PCU_DIAG_SW_DUAL_CHAIN_CHAN_INFO_MASK)
#define MAC_PCU_DIAG_SW_DUAL_CHAIN_CHAN_INFO_RESET                   0
#define MAC_PCU_DIAG_SW_PHYERR_ENABLE_EIFS_CTL_MSB                   23
#define MAC_PCU_DIAG_SW_PHYERR_ENABLE_EIFS_CTL_LSB                   23
#define MAC_PCU_DIAG_SW_PHYERR_ENABLE_EIFS_CTL_MASK                  0x00800000
#define MAC_PCU_DIAG_SW_PHYERR_ENABLE_EIFS_CTL_GET(x)                (((x) & MAC_PCU_DIAG_SW_PHYERR_ENABLE_EIFS_CTL_MASK) >> MAC_PCU_DIAG_SW_PHYERR_ENABLE_EIFS_CTL_LSB)
#define MAC_PCU_DIAG_SW_PHYERR_ENABLE_EIFS_CTL_SET(x)                (((0 | (x)) << MAC_PCU_DIAG_SW_PHYERR_ENABLE_EIFS_CTL_LSB) & MAC_PCU_DIAG_SW_PHYERR_ENABLE_EIFS_CTL_MASK)
#define MAC_PCU_DIAG_SW_PHYERR_ENABLE_EIFS_CTL_RESET                 0
#define MAC_PCU_DIAG_SW_CHAN_IDLE_HIGH_MSB                           22
#define MAC_PCU_DIAG_SW_CHAN_IDLE_HIGH_LSB                           22
#define MAC_PCU_DIAG_SW_CHAN_IDLE_HIGH_MASK                          0x00400000
#define MAC_PCU_DIAG_SW_CHAN_IDLE_HIGH_GET(x)                        (((x) & MAC_PCU_DIAG_SW_CHAN_IDLE_HIGH_MASK) >> MAC_PCU_DIAG_SW_CHAN_IDLE_HIGH_LSB)
#define MAC_PCU_DIAG_SW_CHAN_IDLE_HIGH_SET(x)                        (((0 | (x)) << MAC_PCU_DIAG_SW_CHAN_IDLE_HIGH_LSB) & MAC_PCU_DIAG_SW_CHAN_IDLE_HIGH_MASK)
#define MAC_PCU_DIAG_SW_CHAN_IDLE_HIGH_RESET                         0
#define MAC_PCU_DIAG_SW_IGNORE_NAV_MSB                               21
#define MAC_PCU_DIAG_SW_IGNORE_NAV_LSB                               21
#define MAC_PCU_DIAG_SW_IGNORE_NAV_MASK                              0x00200000
#define MAC_PCU_DIAG_SW_IGNORE_NAV_GET(x)                            (((x) & MAC_PCU_DIAG_SW_IGNORE_NAV_MASK) >> MAC_PCU_DIAG_SW_IGNORE_NAV_LSB)
#define MAC_PCU_DIAG_SW_IGNORE_NAV_SET(x)                            (((0 | (x)) << MAC_PCU_DIAG_SW_IGNORE_NAV_LSB) & MAC_PCU_DIAG_SW_IGNORE_NAV_MASK)
#define MAC_PCU_DIAG_SW_IGNORE_NAV_RESET                             0
#define MAC_PCU_DIAG_SW_RX_CLEAR_HIGH_MSB                            20
#define MAC_PCU_DIAG_SW_RX_CLEAR_HIGH_LSB                            20
#define MAC_PCU_DIAG_SW_RX_CLEAR_HIGH_MASK                           0x00100000
#define MAC_PCU_DIAG_SW_RX_CLEAR_HIGH_GET(x)                         (((x) & MAC_PCU_DIAG_SW_RX_CLEAR_HIGH_MASK) >> MAC_PCU_DIAG_SW_RX_CLEAR_HIGH_LSB)
#define MAC_PCU_DIAG_SW_RX_CLEAR_HIGH_SET(x)                         (((0 | (x)) << MAC_PCU_DIAG_SW_RX_CLEAR_HIGH_LSB) & MAC_PCU_DIAG_SW_RX_CLEAR_HIGH_MASK)
#define MAC_PCU_DIAG_SW_RX_CLEAR_HIGH_RESET                          0
#define MAC_PCU_DIAG_SW_OBS_SEL_1_0_MSB                              19
#define MAC_PCU_DIAG_SW_OBS_SEL_1_0_LSB                              18
#define MAC_PCU_DIAG_SW_OBS_SEL_1_0_MASK                             0x000c0000
#define MAC_PCU_DIAG_SW_OBS_SEL_1_0_GET(x)                           (((x) & MAC_PCU_DIAG_SW_OBS_SEL_1_0_MASK) >> MAC_PCU_DIAG_SW_OBS_SEL_1_0_LSB)
#define MAC_PCU_DIAG_SW_OBS_SEL_1_0_SET(x)                           (((0 | (x)) << MAC_PCU_DIAG_SW_OBS_SEL_1_0_LSB) & MAC_PCU_DIAG_SW_OBS_SEL_1_0_MASK)
#define MAC_PCU_DIAG_SW_OBS_SEL_1_0_RESET                            0
#define MAC_PCU_DIAG_SW_ACCEPT_NON_V0_MSB                            17
#define MAC_PCU_DIAG_SW_ACCEPT_NON_V0_LSB                            17
#define MAC_PCU_DIAG_SW_ACCEPT_NON_V0_MASK                           0x00020000
#define MAC_PCU_DIAG_SW_ACCEPT_NON_V0_GET(x)                         (((x) & MAC_PCU_DIAG_SW_ACCEPT_NON_V0_MASK) >> MAC_PCU_DIAG_SW_ACCEPT_NON_V0_LSB)
#define MAC_PCU_DIAG_SW_ACCEPT_NON_V0_SET(x)                         (((0 | (x)) << MAC_PCU_DIAG_SW_ACCEPT_NON_V0_LSB) & MAC_PCU_DIAG_SW_ACCEPT_NON_V0_MASK)
#define MAC_PCU_DIAG_SW_ACCEPT_NON_V0_RESET                          0
#define MAC_PCU_DIAG_SW_DUMP_CHAN_INFO_MSB                           8
#define MAC_PCU_DIAG_SW_DUMP_CHAN_INFO_LSB                           8
#define MAC_PCU_DIAG_SW_DUMP_CHAN_INFO_MASK                          0x00000100
#define MAC_PCU_DIAG_SW_DUMP_CHAN_INFO_GET(x)                        (((x) & MAC_PCU_DIAG_SW_DUMP_CHAN_INFO_MASK) >> MAC_PCU_DIAG_SW_DUMP_CHAN_INFO_LSB)
#define MAC_PCU_DIAG_SW_DUMP_CHAN_INFO_SET(x)                        (((0 | (x)) << MAC_PCU_DIAG_SW_DUMP_CHAN_INFO_LSB) & MAC_PCU_DIAG_SW_DUMP_CHAN_INFO_MASK)
#define MAC_PCU_DIAG_SW_DUMP_CHAN_INFO_RESET                         0
#define MAC_PCU_DIAG_SW_CORRUPT_FCS_MSB                              7
#define MAC_PCU_DIAG_SW_CORRUPT_FCS_LSB                              7
#define MAC_PCU_DIAG_SW_CORRUPT_FCS_MASK                             0x00000080
#define MAC_PCU_DIAG_SW_CORRUPT_FCS_GET(x)                           (((x) & MAC_PCU_DIAG_SW_CORRUPT_FCS_MASK) >> MAC_PCU_DIAG_SW_CORRUPT_FCS_LSB)
#define MAC_PCU_DIAG_SW_CORRUPT_FCS_SET(x)                           (((0 | (x)) << MAC_PCU_DIAG_SW_CORRUPT_FCS_LSB) & MAC_PCU_DIAG_SW_CORRUPT_FCS_MASK)
#define MAC_PCU_DIAG_SW_CORRUPT_FCS_RESET                            0
#define MAC_PCU_DIAG_SW_LOOP_BACK_MSB                                6
#define MAC_PCU_DIAG_SW_LOOP_BACK_LSB                                6
#define MAC_PCU_DIAG_SW_LOOP_BACK_MASK                               0x00000040
#define MAC_PCU_DIAG_SW_LOOP_BACK_GET(x)                             (((x) & MAC_PCU_DIAG_SW_LOOP_BACK_MASK) >> MAC_PCU_DIAG_SW_LOOP_BACK_LSB)
#define MAC_PCU_DIAG_SW_LOOP_BACK_SET(x)                             (((0 | (x)) << MAC_PCU_DIAG_SW_LOOP_BACK_LSB) & MAC_PCU_DIAG_SW_LOOP_BACK_MASK)
#define MAC_PCU_DIAG_SW_LOOP_BACK_RESET                              0
#define MAC_PCU_DIAG_SW_HALT_RX_MSB                                  5
#define MAC_PCU_DIAG_SW_HALT_RX_LSB                                  5
#define MAC_PCU_DIAG_SW_HALT_RX_MASK                                 0x00000020
#define MAC_PCU_DIAG_SW_HALT_RX_GET(x)                               (((x) & MAC_PCU_DIAG_SW_HALT_RX_MASK) >> MAC_PCU_DIAG_SW_HALT_RX_LSB)
#define MAC_PCU_DIAG_SW_HALT_RX_SET(x)                               (((0 | (x)) << MAC_PCU_DIAG_SW_HALT_RX_LSB) & MAC_PCU_DIAG_SW_HALT_RX_MASK)
#define MAC_PCU_DIAG_SW_HALT_RX_RESET                                0
#define MAC_PCU_DIAG_SW_NO_DECRYPT_MSB                               4
#define MAC_PCU_DIAG_SW_NO_DECRYPT_LSB                               4
#define MAC_PCU_DIAG_SW_NO_DECRYPT_MASK                              0x00000010
#define MAC_PCU_DIAG_SW_NO_DECRYPT_GET(x)                            (((x) & MAC_PCU_DIAG_SW_NO_DECRYPT_MASK) >> MAC_PCU_DIAG_SW_NO_DECRYPT_LSB)
#define MAC_PCU_DIAG_SW_NO_DECRYPT_SET(x)                            (((0 | (x)) << MAC_PCU_DIAG_SW_NO_DECRYPT_LSB) & MAC_PCU_DIAG_SW_NO_DECRYPT_MASK)
#define MAC_PCU_DIAG_SW_NO_DECRYPT_RESET                             0
#define MAC_PCU_DIAG_SW_NO_ENCRYPT_MSB                               3
#define MAC_PCU_DIAG_SW_NO_ENCRYPT_LSB                               3
#define MAC_PCU_DIAG_SW_NO_ENCRYPT_MASK                              0x00000008
#define MAC_PCU_DIAG_SW_NO_ENCRYPT_GET(x)                            (((x) & MAC_PCU_DIAG_SW_NO_ENCRYPT_MASK) >> MAC_PCU_DIAG_SW_NO_ENCRYPT_LSB)
#define MAC_PCU_DIAG_SW_NO_ENCRYPT_SET(x)                            (((0 | (x)) << MAC_PCU_DIAG_SW_NO_ENCRYPT_LSB) & MAC_PCU_DIAG_SW_NO_ENCRYPT_MASK)
#define MAC_PCU_DIAG_SW_NO_ENCRYPT_RESET                             0
#define MAC_PCU_DIAG_SW_NO_CTS_MSB                                   2
#define MAC_PCU_DIAG_SW_NO_CTS_LSB                                   2
#define MAC_PCU_DIAG_SW_NO_CTS_MASK                                  0x00000004
#define MAC_PCU_DIAG_SW_NO_CTS_GET(x)                                (((x) & MAC_PCU_DIAG_SW_NO_CTS_MASK) >> MAC_PCU_DIAG_SW_NO_CTS_LSB)
#define MAC_PCU_DIAG_SW_NO_CTS_SET(x)                                (((0 | (x)) << MAC_PCU_DIAG_SW_NO_CTS_LSB) & MAC_PCU_DIAG_SW_NO_CTS_MASK)
#define MAC_PCU_DIAG_SW_NO_CTS_RESET                                 0
#define MAC_PCU_DIAG_SW_NO_ACK_MSB                                   1
#define MAC_PCU_DIAG_SW_NO_ACK_LSB                                   1
#define MAC_PCU_DIAG_SW_NO_ACK_MASK                                  0x00000002
#define MAC_PCU_DIAG_SW_NO_ACK_GET(x)                                (((x) & MAC_PCU_DIAG_SW_NO_ACK_MASK) >> MAC_PCU_DIAG_SW_NO_ACK_LSB)
#define MAC_PCU_DIAG_SW_NO_ACK_SET(x)                                (((0 | (x)) << MAC_PCU_DIAG_SW_NO_ACK_LSB) & MAC_PCU_DIAG_SW_NO_ACK_MASK)
#define MAC_PCU_DIAG_SW_NO_ACK_RESET                                 0
#define MAC_PCU_DIAG_SW_INVALID_KEY_NO_ACK_MSB                       0
#define MAC_PCU_DIAG_SW_INVALID_KEY_NO_ACK_LSB                       0
#define MAC_PCU_DIAG_SW_INVALID_KEY_NO_ACK_MASK                      0x00000001
#define MAC_PCU_DIAG_SW_INVALID_KEY_NO_ACK_GET(x)                    (((x) & MAC_PCU_DIAG_SW_INVALID_KEY_NO_ACK_MASK) >> MAC_PCU_DIAG_SW_INVALID_KEY_NO_ACK_LSB)
#define MAC_PCU_DIAG_SW_INVALID_KEY_NO_ACK_SET(x)                    (((0 | (x)) << MAC_PCU_DIAG_SW_INVALID_KEY_NO_ACK_LSB) & MAC_PCU_DIAG_SW_INVALID_KEY_NO_ACK_MASK)
#define MAC_PCU_DIAG_SW_INVALID_KEY_NO_ACK_RESET                     0
#define MAC_PCU_DIAG_SW_ADDRESS                                      0x8048
#define MAC_PCU_DIAG_SW_HW_MASK                                      0xfffe01ff
#define MAC_PCU_DIAG_SW_SW_MASK                                      0xfffe01ff
#define MAC_PCU_DIAG_SW_HW_WRITE_MASK                                0x00000000
#define MAC_PCU_DIAG_SW_SW_WRITE_MASK                                0xfffe01ff
#define MAC_PCU_DIAG_SW_RSTMASK                                      0xffffffff
#define MAC_PCU_DIAG_SW_RESET                                        0x00000000

// 0x804c (MAC_PCU_WARM_TX_CONTROL)
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_SELF_GEN_MSB                  31
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_SELF_GEN_LSB                  31
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_SELF_GEN_MASK                 0x80000000
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_SELF_GEN_GET(x)               (((x) & MAC_PCU_WARM_TX_CONTROL_ENABLE_SELF_GEN_MASK) >> MAC_PCU_WARM_TX_CONTROL_ENABLE_SELF_GEN_LSB)
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_SELF_GEN_SET(x)               (((0 | (x)) << MAC_PCU_WARM_TX_CONTROL_ENABLE_SELF_GEN_LSB) & MAC_PCU_WARM_TX_CONTROL_ENABLE_SELF_GEN_MASK)
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_SELF_GEN_RESET                0
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_DATA_MSB                      30
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_DATA_LSB                      30
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_DATA_MASK                     0x40000000
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_DATA_GET(x)                   (((x) & MAC_PCU_WARM_TX_CONTROL_ENABLE_DATA_MASK) >> MAC_PCU_WARM_TX_CONTROL_ENABLE_DATA_LSB)
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_DATA_SET(x)                   (((0 | (x)) << MAC_PCU_WARM_TX_CONTROL_ENABLE_DATA_LSB) & MAC_PCU_WARM_TX_CONTROL_ENABLE_DATA_MASK)
#define MAC_PCU_WARM_TX_CONTROL_ENABLE_DATA_RESET                    0
#define MAC_PCU_WARM_TX_CONTROL_SIFS_DUR_MSB                         15
#define MAC_PCU_WARM_TX_CONTROL_SIFS_DUR_LSB                         0
#define MAC_PCU_WARM_TX_CONTROL_SIFS_DUR_MASK                        0x0000ffff
#define MAC_PCU_WARM_TX_CONTROL_SIFS_DUR_GET(x)                      (((x) & MAC_PCU_WARM_TX_CONTROL_SIFS_DUR_MASK) >> MAC_PCU_WARM_TX_CONTROL_SIFS_DUR_LSB)
#define MAC_PCU_WARM_TX_CONTROL_SIFS_DUR_SET(x)                      (((0 | (x)) << MAC_PCU_WARM_TX_CONTROL_SIFS_DUR_LSB) & MAC_PCU_WARM_TX_CONTROL_SIFS_DUR_MASK)
#define MAC_PCU_WARM_TX_CONTROL_SIFS_DUR_RESET                       640
#define MAC_PCU_WARM_TX_CONTROL_ADDRESS                              0x804c
#define MAC_PCU_WARM_TX_CONTROL_HW_MASK                              0xc000ffff
#define MAC_PCU_WARM_TX_CONTROL_SW_MASK                              0xc000ffff
#define MAC_PCU_WARM_TX_CONTROL_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_WARM_TX_CONTROL_SW_WRITE_MASK                        0xc000ffff
#define MAC_PCU_WARM_TX_CONTROL_RSTMASK                              0xffffffff
#define MAC_PCU_WARM_TX_CONTROL_RESET                                0x00000280

// 0x8054 (MAC_PCU_TST_ADDAC)
#define MAC_PCU_TST_ADDAC_TEST_ARM_MSB                               20
#define MAC_PCU_TST_ADDAC_TEST_ARM_LSB                               20
#define MAC_PCU_TST_ADDAC_TEST_ARM_MASK                              0x00100000
#define MAC_PCU_TST_ADDAC_TEST_ARM_GET(x)                            (((x) & MAC_PCU_TST_ADDAC_TEST_ARM_MASK) >> MAC_PCU_TST_ADDAC_TEST_ARM_LSB)
#define MAC_PCU_TST_ADDAC_TEST_ARM_SET(x)                            (((0 | (x)) << MAC_PCU_TST_ADDAC_TEST_ARM_LSB) & MAC_PCU_TST_ADDAC_TEST_ARM_MASK)
#define MAC_PCU_TST_ADDAC_TEST_ARM_RESET                             0
#define MAC_PCU_TST_ADDAC_TEST_CAPTURE_MSB                           19
#define MAC_PCU_TST_ADDAC_TEST_CAPTURE_LSB                           19
#define MAC_PCU_TST_ADDAC_TEST_CAPTURE_MASK                          0x00080000
#define MAC_PCU_TST_ADDAC_TEST_CAPTURE_GET(x)                        (((x) & MAC_PCU_TST_ADDAC_TEST_CAPTURE_MASK) >> MAC_PCU_TST_ADDAC_TEST_CAPTURE_LSB)
#define MAC_PCU_TST_ADDAC_TEST_CAPTURE_SET(x)                        (((0 | (x)) << MAC_PCU_TST_ADDAC_TEST_CAPTURE_LSB) & MAC_PCU_TST_ADDAC_TEST_CAPTURE_MASK)
#define MAC_PCU_TST_ADDAC_TEST_CAPTURE_RESET                         0
#define MAC_PCU_TST_ADDAC_CONT_TEST_MSB                              18
#define MAC_PCU_TST_ADDAC_CONT_TEST_LSB                              18
#define MAC_PCU_TST_ADDAC_CONT_TEST_MASK                             0x00040000
#define MAC_PCU_TST_ADDAC_CONT_TEST_GET(x)                           (((x) & MAC_PCU_TST_ADDAC_CONT_TEST_MASK) >> MAC_PCU_TST_ADDAC_CONT_TEST_LSB)
#define MAC_PCU_TST_ADDAC_CONT_TEST_SET(x)                           (((0 | (x)) << MAC_PCU_TST_ADDAC_CONT_TEST_LSB) & MAC_PCU_TST_ADDAC_CONT_TEST_MASK)
#define MAC_PCU_TST_ADDAC_CONT_TEST_RESET                            0
#define MAC_PCU_TST_ADDAC_TRIG_POLARITY_MSB                          17
#define MAC_PCU_TST_ADDAC_TRIG_POLARITY_LSB                          17
#define MAC_PCU_TST_ADDAC_TRIG_POLARITY_MASK                         0x00020000
#define MAC_PCU_TST_ADDAC_TRIG_POLARITY_GET(x)                       (((x) & MAC_PCU_TST_ADDAC_TRIG_POLARITY_MASK) >> MAC_PCU_TST_ADDAC_TRIG_POLARITY_LSB)
#define MAC_PCU_TST_ADDAC_TRIG_POLARITY_SET(x)                       (((0 | (x)) << MAC_PCU_TST_ADDAC_TRIG_POLARITY_LSB) & MAC_PCU_TST_ADDAC_TRIG_POLARITY_MASK)
#define MAC_PCU_TST_ADDAC_TRIG_POLARITY_RESET                        0
#define MAC_PCU_TST_ADDAC_TRIG_SEL_MSB                               16
#define MAC_PCU_TST_ADDAC_TRIG_SEL_LSB                               16
#define MAC_PCU_TST_ADDAC_TRIG_SEL_MASK                              0x00010000
#define MAC_PCU_TST_ADDAC_TRIG_SEL_GET(x)                            (((x) & MAC_PCU_TST_ADDAC_TRIG_SEL_MASK) >> MAC_PCU_TST_ADDAC_TRIG_SEL_LSB)
#define MAC_PCU_TST_ADDAC_TRIG_SEL_SET(x)                            (((0 | (x)) << MAC_PCU_TST_ADDAC_TRIG_SEL_LSB) & MAC_PCU_TST_ADDAC_TRIG_SEL_MASK)
#define MAC_PCU_TST_ADDAC_TRIG_SEL_RESET                             0
#define MAC_PCU_TST_ADDAC_SAMPLE_SIZE_2K_MSB                         15
#define MAC_PCU_TST_ADDAC_SAMPLE_SIZE_2K_LSB                         15
#define MAC_PCU_TST_ADDAC_SAMPLE_SIZE_2K_MASK                        0x00008000
#define MAC_PCU_TST_ADDAC_SAMPLE_SIZE_2K_GET(x)                      (((x) & MAC_PCU_TST_ADDAC_SAMPLE_SIZE_2K_MASK) >> MAC_PCU_TST_ADDAC_SAMPLE_SIZE_2K_LSB)
#define MAC_PCU_TST_ADDAC_SAMPLE_SIZE_2K_SET(x)                      (((0 | (x)) << MAC_PCU_TST_ADDAC_SAMPLE_SIZE_2K_LSB) & MAC_PCU_TST_ADDAC_SAMPLE_SIZE_2K_MASK)
#define MAC_PCU_TST_ADDAC_SAMPLE_SIZE_2K_RESET                       0
#define MAC_PCU_TST_ADDAC_UPPER_8B_MSB                               14
#define MAC_PCU_TST_ADDAC_UPPER_8B_LSB                               14
#define MAC_PCU_TST_ADDAC_UPPER_8B_MASK                              0x00004000
#define MAC_PCU_TST_ADDAC_UPPER_8B_GET(x)                            (((x) & MAC_PCU_TST_ADDAC_UPPER_8B_MASK) >> MAC_PCU_TST_ADDAC_UPPER_8B_LSB)
#define MAC_PCU_TST_ADDAC_UPPER_8B_SET(x)                            (((0 | (x)) << MAC_PCU_TST_ADDAC_UPPER_8B_LSB) & MAC_PCU_TST_ADDAC_UPPER_8B_MASK)
#define MAC_PCU_TST_ADDAC_UPPER_8B_RESET                             0
#define MAC_PCU_TST_ADDAC_LOOP_LEN_MSB                               13
#define MAC_PCU_TST_ADDAC_LOOP_LEN_LSB                               3
#define MAC_PCU_TST_ADDAC_LOOP_LEN_MASK                              0x00003ff8
#define MAC_PCU_TST_ADDAC_LOOP_LEN_GET(x)                            (((x) & MAC_PCU_TST_ADDAC_LOOP_LEN_MASK) >> MAC_PCU_TST_ADDAC_LOOP_LEN_LSB)
#define MAC_PCU_TST_ADDAC_LOOP_LEN_SET(x)                            (((0 | (x)) << MAC_PCU_TST_ADDAC_LOOP_LEN_LSB) & MAC_PCU_TST_ADDAC_LOOP_LEN_MASK)
#define MAC_PCU_TST_ADDAC_LOOP_LEN_RESET                             0
#define MAC_PCU_TST_ADDAC_LOOP_MSB                                   2
#define MAC_PCU_TST_ADDAC_LOOP_LSB                                   2
#define MAC_PCU_TST_ADDAC_LOOP_MASK                                  0x00000004
#define MAC_PCU_TST_ADDAC_LOOP_GET(x)                                (((x) & MAC_PCU_TST_ADDAC_LOOP_MASK) >> MAC_PCU_TST_ADDAC_LOOP_LSB)
#define MAC_PCU_TST_ADDAC_LOOP_SET(x)                                (((0 | (x)) << MAC_PCU_TST_ADDAC_LOOP_LSB) & MAC_PCU_TST_ADDAC_LOOP_MASK)
#define MAC_PCU_TST_ADDAC_LOOP_RESET                                 0
#define MAC_PCU_TST_ADDAC_TESTMODE_MSB                               1
#define MAC_PCU_TST_ADDAC_TESTMODE_LSB                               1
#define MAC_PCU_TST_ADDAC_TESTMODE_MASK                              0x00000002
#define MAC_PCU_TST_ADDAC_TESTMODE_GET(x)                            (((x) & MAC_PCU_TST_ADDAC_TESTMODE_MASK) >> MAC_PCU_TST_ADDAC_TESTMODE_LSB)
#define MAC_PCU_TST_ADDAC_TESTMODE_SET(x)                            (((0 | (x)) << MAC_PCU_TST_ADDAC_TESTMODE_LSB) & MAC_PCU_TST_ADDAC_TESTMODE_MASK)
#define MAC_PCU_TST_ADDAC_TESTMODE_RESET                             0
#define MAC_PCU_TST_ADDAC_CONT_TX_MSB                                0
#define MAC_PCU_TST_ADDAC_CONT_TX_LSB                                0
#define MAC_PCU_TST_ADDAC_CONT_TX_MASK                               0x00000001
#define MAC_PCU_TST_ADDAC_CONT_TX_GET(x)                             (((x) & MAC_PCU_TST_ADDAC_CONT_TX_MASK) >> MAC_PCU_TST_ADDAC_CONT_TX_LSB)
#define MAC_PCU_TST_ADDAC_CONT_TX_SET(x)                             (((0 | (x)) << MAC_PCU_TST_ADDAC_CONT_TX_LSB) & MAC_PCU_TST_ADDAC_CONT_TX_MASK)
#define MAC_PCU_TST_ADDAC_CONT_TX_RESET                              0
#define MAC_PCU_TST_ADDAC_ADDRESS                                    0x8054
#define MAC_PCU_TST_ADDAC_HW_MASK                                    0x001fffff
#define MAC_PCU_TST_ADDAC_SW_MASK                                    0x001fffff
#define MAC_PCU_TST_ADDAC_HW_WRITE_MASK                              0x00180000
#define MAC_PCU_TST_ADDAC_SW_WRITE_MASK                              0x001bffff
#define MAC_PCU_TST_ADDAC_RSTMASK                                    0xffffffff
#define MAC_PCU_TST_ADDAC_RESET                                      0x00000000

// 0x8058 (MAC_PCU_DEF_ANTENNA)
#define MAC_PCU_DEF_ANTENNA_RX_ANT_DIV_ON_MSB                        31
#define MAC_PCU_DEF_ANTENNA_RX_ANT_DIV_ON_LSB                        31
#define MAC_PCU_DEF_ANTENNA_RX_ANT_DIV_ON_MASK                       0x80000000
#define MAC_PCU_DEF_ANTENNA_RX_ANT_DIV_ON_GET(x)                     (((x) & MAC_PCU_DEF_ANTENNA_RX_ANT_DIV_ON_MASK) >> MAC_PCU_DEF_ANTENNA_RX_ANT_DIV_ON_LSB)
#define MAC_PCU_DEF_ANTENNA_RX_ANT_DIV_ON_SET(x)                     (((0 | (x)) << MAC_PCU_DEF_ANTENNA_RX_ANT_DIV_ON_LSB) & MAC_PCU_DEF_ANTENNA_RX_ANT_DIV_ON_MASK)
#define MAC_PCU_DEF_ANTENNA_RX_ANT_DIV_ON_RESET                      0
#define MAC_PCU_DEF_ANTENNA_RX_ANT_EN_MSB                            30
#define MAC_PCU_DEF_ANTENNA_RX_ANT_EN_LSB                            30
#define MAC_PCU_DEF_ANTENNA_RX_ANT_EN_MASK                           0x40000000
#define MAC_PCU_DEF_ANTENNA_RX_ANT_EN_GET(x)                         (((x) & MAC_PCU_DEF_ANTENNA_RX_ANT_EN_MASK) >> MAC_PCU_DEF_ANTENNA_RX_ANT_EN_LSB)
#define MAC_PCU_DEF_ANTENNA_RX_ANT_EN_SET(x)                         (((0 | (x)) << MAC_PCU_DEF_ANTENNA_RX_ANT_EN_LSB) & MAC_PCU_DEF_ANTENNA_RX_ANT_EN_MASK)
#define MAC_PCU_DEF_ANTENNA_RX_ANT_EN_RESET                          0
#define MAC_PCU_DEF_ANTENNA_FAST_TX_ANT_EN_MSB                       29
#define MAC_PCU_DEF_ANTENNA_FAST_TX_ANT_EN_LSB                       29
#define MAC_PCU_DEF_ANTENNA_FAST_TX_ANT_EN_MASK                      0x20000000
#define MAC_PCU_DEF_ANTENNA_FAST_TX_ANT_EN_GET(x)                    (((x) & MAC_PCU_DEF_ANTENNA_FAST_TX_ANT_EN_MASK) >> MAC_PCU_DEF_ANTENNA_FAST_TX_ANT_EN_LSB)
#define MAC_PCU_DEF_ANTENNA_FAST_TX_ANT_EN_SET(x)                    (((0 | (x)) << MAC_PCU_DEF_ANTENNA_FAST_TX_ANT_EN_LSB) & MAC_PCU_DEF_ANTENNA_FAST_TX_ANT_EN_MASK)
#define MAC_PCU_DEF_ANTENNA_FAST_TX_ANT_EN_RESET                     0
#define MAC_PCU_DEF_ANTENNA_RX_LNA_CONFIG_SEL_MSB                    28
#define MAC_PCU_DEF_ANTENNA_RX_LNA_CONFIG_SEL_LSB                    28
#define MAC_PCU_DEF_ANTENNA_RX_LNA_CONFIG_SEL_MASK                   0x10000000
#define MAC_PCU_DEF_ANTENNA_RX_LNA_CONFIG_SEL_GET(x)                 (((x) & MAC_PCU_DEF_ANTENNA_RX_LNA_CONFIG_SEL_MASK) >> MAC_PCU_DEF_ANTENNA_RX_LNA_CONFIG_SEL_LSB)
#define MAC_PCU_DEF_ANTENNA_RX_LNA_CONFIG_SEL_SET(x)                 (((0 | (x)) << MAC_PCU_DEF_ANTENNA_RX_LNA_CONFIG_SEL_LSB) & MAC_PCU_DEF_ANTENNA_RX_LNA_CONFIG_SEL_MASK)
#define MAC_PCU_DEF_ANTENNA_RX_LNA_CONFIG_SEL_RESET                  0
#define MAC_PCU_DEF_ANTENNA_FAST_DEF_ANT_MSB                         27
#define MAC_PCU_DEF_ANTENNA_FAST_DEF_ANT_LSB                         27
#define MAC_PCU_DEF_ANTENNA_FAST_DEF_ANT_MASK                        0x08000000
#define MAC_PCU_DEF_ANTENNA_FAST_DEF_ANT_GET(x)                      (((x) & MAC_PCU_DEF_ANTENNA_FAST_DEF_ANT_MASK) >> MAC_PCU_DEF_ANTENNA_FAST_DEF_ANT_LSB)
#define MAC_PCU_DEF_ANTENNA_FAST_DEF_ANT_SET(x)                      (((0 | (x)) << MAC_PCU_DEF_ANTENNA_FAST_DEF_ANT_LSB) & MAC_PCU_DEF_ANTENNA_FAST_DEF_ANT_MASK)
#define MAC_PCU_DEF_ANTENNA_FAST_DEF_ANT_RESET                       0
#define MAC_PCU_DEF_ANTENNA_TX_CUR_ANT_MSB                           26
#define MAC_PCU_DEF_ANTENNA_TX_CUR_ANT_LSB                           26
#define MAC_PCU_DEF_ANTENNA_TX_CUR_ANT_MASK                          0x04000000
#define MAC_PCU_DEF_ANTENNA_TX_CUR_ANT_GET(x)                        (((x) & MAC_PCU_DEF_ANTENNA_TX_CUR_ANT_MASK) >> MAC_PCU_DEF_ANTENNA_TX_CUR_ANT_LSB)
#define MAC_PCU_DEF_ANTENNA_TX_CUR_ANT_SET(x)                        (((0 | (x)) << MAC_PCU_DEF_ANTENNA_TX_CUR_ANT_LSB) & MAC_PCU_DEF_ANTENNA_TX_CUR_ANT_MASK)
#define MAC_PCU_DEF_ANTENNA_TX_CUR_ANT_RESET                         0
#define MAC_PCU_DEF_ANTENNA_SLOW_TX_ANT_EN_MSB                       25
#define MAC_PCU_DEF_ANTENNA_SLOW_TX_ANT_EN_LSB                       25
#define MAC_PCU_DEF_ANTENNA_SLOW_TX_ANT_EN_MASK                      0x02000000
#define MAC_PCU_DEF_ANTENNA_SLOW_TX_ANT_EN_GET(x)                    (((x) & MAC_PCU_DEF_ANTENNA_SLOW_TX_ANT_EN_MASK) >> MAC_PCU_DEF_ANTENNA_SLOW_TX_ANT_EN_LSB)
#define MAC_PCU_DEF_ANTENNA_SLOW_TX_ANT_EN_SET(x)                    (((0 | (x)) << MAC_PCU_DEF_ANTENNA_SLOW_TX_ANT_EN_LSB) & MAC_PCU_DEF_ANTENNA_SLOW_TX_ANT_EN_MASK)
#define MAC_PCU_DEF_ANTENNA_SLOW_TX_ANT_EN_RESET                     0
#define MAC_PCU_DEF_ANTENNA_TX_DEF_ANT_SEL_MSB                       24
#define MAC_PCU_DEF_ANTENNA_TX_DEF_ANT_SEL_LSB                       24
#define MAC_PCU_DEF_ANTENNA_TX_DEF_ANT_SEL_MASK                      0x01000000
#define MAC_PCU_DEF_ANTENNA_TX_DEF_ANT_SEL_GET(x)                    (((x) & MAC_PCU_DEF_ANTENNA_TX_DEF_ANT_SEL_MASK) >> MAC_PCU_DEF_ANTENNA_TX_DEF_ANT_SEL_LSB)
#define MAC_PCU_DEF_ANTENNA_TX_DEF_ANT_SEL_SET(x)                    (((0 | (x)) << MAC_PCU_DEF_ANTENNA_TX_DEF_ANT_SEL_LSB) & MAC_PCU_DEF_ANTENNA_TX_DEF_ANT_SEL_MASK)
#define MAC_PCU_DEF_ANTENNA_TX_DEF_ANT_SEL_RESET                     0
#define MAC_PCU_DEF_ANTENNA_VALUE_MSB                                23
#define MAC_PCU_DEF_ANTENNA_VALUE_LSB                                0
#define MAC_PCU_DEF_ANTENNA_VALUE_MASK                               0x00ffffff
#define MAC_PCU_DEF_ANTENNA_VALUE_GET(x)                             (((x) & MAC_PCU_DEF_ANTENNA_VALUE_MASK) >> MAC_PCU_DEF_ANTENNA_VALUE_LSB)
#define MAC_PCU_DEF_ANTENNA_VALUE_SET(x)                             (((0 | (x)) << MAC_PCU_DEF_ANTENNA_VALUE_LSB) & MAC_PCU_DEF_ANTENNA_VALUE_MASK)
#define MAC_PCU_DEF_ANTENNA_VALUE_RESET                              0
#define MAC_PCU_DEF_ANTENNA_ADDRESS                                  0x8058
#define MAC_PCU_DEF_ANTENNA_HW_MASK                                  0xffffffff
#define MAC_PCU_DEF_ANTENNA_SW_MASK                                  0xffffffff
#define MAC_PCU_DEF_ANTENNA_HW_WRITE_MASK                            0x0c000000
#define MAC_PCU_DEF_ANTENNA_SW_WRITE_MASK                            0xffffffff
#define MAC_PCU_DEF_ANTENNA_RSTMASK                                  0xffffffff
#define MAC_PCU_DEF_ANTENNA_RESET                                    0x00000000

// 0x805c (MAC_PCU_AES_MUTE_MASK_0)
#define MAC_PCU_AES_MUTE_MASK_0_QOS_MSB                              31
#define MAC_PCU_AES_MUTE_MASK_0_QOS_LSB                              16
#define MAC_PCU_AES_MUTE_MASK_0_QOS_MASK                             0xffff0000
#define MAC_PCU_AES_MUTE_MASK_0_QOS_GET(x)                           (((x) & MAC_PCU_AES_MUTE_MASK_0_QOS_MASK) >> MAC_PCU_AES_MUTE_MASK_0_QOS_LSB)
#define MAC_PCU_AES_MUTE_MASK_0_QOS_SET(x)                           (((0 | (x)) << MAC_PCU_AES_MUTE_MASK_0_QOS_LSB) & MAC_PCU_AES_MUTE_MASK_0_QOS_MASK)
#define MAC_PCU_AES_MUTE_MASK_0_QOS_RESET                            65535
#define MAC_PCU_AES_MUTE_MASK_0_FC_MSB                               15
#define MAC_PCU_AES_MUTE_MASK_0_FC_LSB                               0
#define MAC_PCU_AES_MUTE_MASK_0_FC_MASK                              0x0000ffff
#define MAC_PCU_AES_MUTE_MASK_0_FC_GET(x)                            (((x) & MAC_PCU_AES_MUTE_MASK_0_FC_MASK) >> MAC_PCU_AES_MUTE_MASK_0_FC_LSB)
#define MAC_PCU_AES_MUTE_MASK_0_FC_SET(x)                            (((0 | (x)) << MAC_PCU_AES_MUTE_MASK_0_FC_LSB) & MAC_PCU_AES_MUTE_MASK_0_FC_MASK)
#define MAC_PCU_AES_MUTE_MASK_0_FC_RESET                             18319
#define MAC_PCU_AES_MUTE_MASK_0_ADDRESS                              0x805c
#define MAC_PCU_AES_MUTE_MASK_0_HW_MASK                              0xffffffff
#define MAC_PCU_AES_MUTE_MASK_0_SW_MASK                              0xffffffff
#define MAC_PCU_AES_MUTE_MASK_0_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_AES_MUTE_MASK_0_SW_WRITE_MASK                        0xffffffff
#define MAC_PCU_AES_MUTE_MASK_0_RSTMASK                              0xffffffff
#define MAC_PCU_AES_MUTE_MASK_0_RESET                                0xffff478f

// 0x8060 (MAC_PCU_AES_MUTE_MASK_1)
#define MAC_PCU_AES_MUTE_MASK_1_FC_MGMT_MSB                          31
#define MAC_PCU_AES_MUTE_MASK_1_FC_MGMT_LSB                          16
#define MAC_PCU_AES_MUTE_MASK_1_FC_MGMT_MASK                         0xffff0000
#define MAC_PCU_AES_MUTE_MASK_1_FC_MGMT_GET(x)                       (((x) & MAC_PCU_AES_MUTE_MASK_1_FC_MGMT_MASK) >> MAC_PCU_AES_MUTE_MASK_1_FC_MGMT_LSB)
#define MAC_PCU_AES_MUTE_MASK_1_FC_MGMT_SET(x)                       (((0 | (x)) << MAC_PCU_AES_MUTE_MASK_1_FC_MGMT_LSB) & MAC_PCU_AES_MUTE_MASK_1_FC_MGMT_MASK)
#define MAC_PCU_AES_MUTE_MASK_1_FC_MGMT_RESET                        59391
#define MAC_PCU_AES_MUTE_MASK_1_SEQ_MSB                              15
#define MAC_PCU_AES_MUTE_MASK_1_SEQ_LSB                              0
#define MAC_PCU_AES_MUTE_MASK_1_SEQ_MASK                             0x0000ffff
#define MAC_PCU_AES_MUTE_MASK_1_SEQ_GET(x)                           (((x) & MAC_PCU_AES_MUTE_MASK_1_SEQ_MASK) >> MAC_PCU_AES_MUTE_MASK_1_SEQ_LSB)
#define MAC_PCU_AES_MUTE_MASK_1_SEQ_SET(x)                           (((0 | (x)) << MAC_PCU_AES_MUTE_MASK_1_SEQ_LSB) & MAC_PCU_AES_MUTE_MASK_1_SEQ_MASK)
#define MAC_PCU_AES_MUTE_MASK_1_SEQ_RESET                            15
#define MAC_PCU_AES_MUTE_MASK_1_ADDRESS                              0x8060
#define MAC_PCU_AES_MUTE_MASK_1_HW_MASK                              0xffffffff
#define MAC_PCU_AES_MUTE_MASK_1_SW_MASK                              0xffffffff
#define MAC_PCU_AES_MUTE_MASK_1_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_AES_MUTE_MASK_1_SW_WRITE_MASK                        0xffffffff
#define MAC_PCU_AES_MUTE_MASK_1_RSTMASK                              0xffffffff
#define MAC_PCU_AES_MUTE_MASK_1_RESET                                0xe7ff000f

// 0x8064 (MAC_PCU_GATED_CLKS)
#define MAC_PCU_GATED_CLKS_GATED_REG_MSB                             3
#define MAC_PCU_GATED_CLKS_GATED_REG_LSB                             3
#define MAC_PCU_GATED_CLKS_GATED_REG_MASK                            0x00000008
#define MAC_PCU_GATED_CLKS_GATED_REG_GET(x)                          (((x) & MAC_PCU_GATED_CLKS_GATED_REG_MASK) >> MAC_PCU_GATED_CLKS_GATED_REG_LSB)
#define MAC_PCU_GATED_CLKS_GATED_REG_SET(x)                          (((0 | (x)) << MAC_PCU_GATED_CLKS_GATED_REG_LSB) & MAC_PCU_GATED_CLKS_GATED_REG_MASK)
#define MAC_PCU_GATED_CLKS_GATED_REG_RESET                           0
#define MAC_PCU_GATED_CLKS_GATED_RX_MSB                              2
#define MAC_PCU_GATED_CLKS_GATED_RX_LSB                              2
#define MAC_PCU_GATED_CLKS_GATED_RX_MASK                             0x00000004
#define MAC_PCU_GATED_CLKS_GATED_RX_GET(x)                           (((x) & MAC_PCU_GATED_CLKS_GATED_RX_MASK) >> MAC_PCU_GATED_CLKS_GATED_RX_LSB)
#define MAC_PCU_GATED_CLKS_GATED_RX_SET(x)                           (((0 | (x)) << MAC_PCU_GATED_CLKS_GATED_RX_LSB) & MAC_PCU_GATED_CLKS_GATED_RX_MASK)
#define MAC_PCU_GATED_CLKS_GATED_RX_RESET                            0
#define MAC_PCU_GATED_CLKS_GATED_TX_MSB                              1
#define MAC_PCU_GATED_CLKS_GATED_TX_LSB                              1
#define MAC_PCU_GATED_CLKS_GATED_TX_MASK                             0x00000002
#define MAC_PCU_GATED_CLKS_GATED_TX_GET(x)                           (((x) & MAC_PCU_GATED_CLKS_GATED_TX_MASK) >> MAC_PCU_GATED_CLKS_GATED_TX_LSB)
#define MAC_PCU_GATED_CLKS_GATED_TX_SET(x)                           (((0 | (x)) << MAC_PCU_GATED_CLKS_GATED_TX_LSB) & MAC_PCU_GATED_CLKS_GATED_TX_MASK)
#define MAC_PCU_GATED_CLKS_GATED_TX_RESET                            0
#define MAC_PCU_GATED_CLKS_ADDRESS                                   0x8064
#define MAC_PCU_GATED_CLKS_HW_MASK                                   0x0000000e
#define MAC_PCU_GATED_CLKS_SW_MASK                                   0x0000000e
#define MAC_PCU_GATED_CLKS_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_GATED_CLKS_SW_WRITE_MASK                             0x0000000e
#define MAC_PCU_GATED_CLKS_RSTMASK                                   0xffffffff
#define MAC_PCU_GATED_CLKS_RESET                                     0x00000000

// 0x8068 (MAC_PCU_OBS_BUS_2)
#define MAC_PCU_OBS_BUS_2_VALUE2_MSB                                 31
#define MAC_PCU_OBS_BUS_2_VALUE2_LSB                                 18
#define MAC_PCU_OBS_BUS_2_VALUE2_MASK                                0xfffc0000
#define MAC_PCU_OBS_BUS_2_VALUE2_GET(x)                              (((x) & MAC_PCU_OBS_BUS_2_VALUE2_MASK) >> MAC_PCU_OBS_BUS_2_VALUE2_LSB)
#define MAC_PCU_OBS_BUS_2_VALUE2_SET(x)                              (((0 | (x)) << MAC_PCU_OBS_BUS_2_VALUE2_LSB) & MAC_PCU_OBS_BUS_2_VALUE2_MASK)
#define MAC_PCU_OBS_BUS_2_VALUE2_RESET                               0
#define MAC_PCU_OBS_BUS_2_VALUE_MSB                                  17
#define MAC_PCU_OBS_BUS_2_VALUE_LSB                                  0
#define MAC_PCU_OBS_BUS_2_VALUE_MASK                                 0x0003ffff
#define MAC_PCU_OBS_BUS_2_VALUE_GET(x)                               (((x) & MAC_PCU_OBS_BUS_2_VALUE_MASK) >> MAC_PCU_OBS_BUS_2_VALUE_LSB)
#define MAC_PCU_OBS_BUS_2_VALUE_SET(x)                               (((0 | (x)) << MAC_PCU_OBS_BUS_2_VALUE_LSB) & MAC_PCU_OBS_BUS_2_VALUE_MASK)
#define MAC_PCU_OBS_BUS_2_VALUE_RESET                                0
#define MAC_PCU_OBS_BUS_2_ADDRESS                                    0x8068
#define MAC_PCU_OBS_BUS_2_HW_MASK                                    0xffffffff
#define MAC_PCU_OBS_BUS_2_SW_MASK                                    0xffffffff
#define MAC_PCU_OBS_BUS_2_HW_WRITE_MASK                              0xffffffff
#define MAC_PCU_OBS_BUS_2_SW_WRITE_MASK                              0x00000000
#define MAC_PCU_OBS_BUS_2_RSTMASK                                    0xffffffff
#define MAC_PCU_OBS_BUS_2_RESET                                      0x00000000

// 0x806c (MAC_PCU_OBS_BUS_1)
#define MAC_PCU_OBS_BUS_1_TX_STATE_MSB                               30
#define MAC_PCU_OBS_BUS_1_TX_STATE_LSB                               25
#define MAC_PCU_OBS_BUS_1_TX_STATE_MASK                              0x7e000000
#define MAC_PCU_OBS_BUS_1_TX_STATE_GET(x)                            (((x) & MAC_PCU_OBS_BUS_1_TX_STATE_MASK) >> MAC_PCU_OBS_BUS_1_TX_STATE_LSB)
#define MAC_PCU_OBS_BUS_1_TX_STATE_SET(x)                            (((0 | (x)) << MAC_PCU_OBS_BUS_1_TX_STATE_LSB) & MAC_PCU_OBS_BUS_1_TX_STATE_MASK)
#define MAC_PCU_OBS_BUS_1_TX_STATE_RESET                             0
#define MAC_PCU_OBS_BUS_1_RX_STATE_MSB                               24
#define MAC_PCU_OBS_BUS_1_RX_STATE_LSB                               20
#define MAC_PCU_OBS_BUS_1_RX_STATE_MASK                              0x01f00000
#define MAC_PCU_OBS_BUS_1_RX_STATE_GET(x)                            (((x) & MAC_PCU_OBS_BUS_1_RX_STATE_MASK) >> MAC_PCU_OBS_BUS_1_RX_STATE_LSB)
#define MAC_PCU_OBS_BUS_1_RX_STATE_SET(x)                            (((0 | (x)) << MAC_PCU_OBS_BUS_1_RX_STATE_LSB) & MAC_PCU_OBS_BUS_1_RX_STATE_MASK)
#define MAC_PCU_OBS_BUS_1_RX_STATE_RESET                             0
#define MAC_PCU_OBS_BUS_1_WEP_STATE_MSB                              17
#define MAC_PCU_OBS_BUS_1_WEP_STATE_LSB                              12
#define MAC_PCU_OBS_BUS_1_WEP_STATE_MASK                             0x0003f000
#define MAC_PCU_OBS_BUS_1_WEP_STATE_GET(x)                           (((x) & MAC_PCU_OBS_BUS_1_WEP_STATE_MASK) >> MAC_PCU_OBS_BUS_1_WEP_STATE_LSB)
#define MAC_PCU_OBS_BUS_1_WEP_STATE_SET(x)                           (((0 | (x)) << MAC_PCU_OBS_BUS_1_WEP_STATE_LSB) & MAC_PCU_OBS_BUS_1_WEP_STATE_MASK)
#define MAC_PCU_OBS_BUS_1_WEP_STATE_RESET                            0
#define MAC_PCU_OBS_BUS_1_RX_CLEAR_MSB                               11
#define MAC_PCU_OBS_BUS_1_RX_CLEAR_LSB                               11
#define MAC_PCU_OBS_BUS_1_RX_CLEAR_MASK                              0x00000800
#define MAC_PCU_OBS_BUS_1_RX_CLEAR_GET(x)                            (((x) & MAC_PCU_OBS_BUS_1_RX_CLEAR_MASK) >> MAC_PCU_OBS_BUS_1_RX_CLEAR_LSB)
#define MAC_PCU_OBS_BUS_1_RX_CLEAR_SET(x)                            (((0 | (x)) << MAC_PCU_OBS_BUS_1_RX_CLEAR_LSB) & MAC_PCU_OBS_BUS_1_RX_CLEAR_MASK)
#define MAC_PCU_OBS_BUS_1_RX_CLEAR_RESET                             0
#define MAC_PCU_OBS_BUS_1_RX_FRAME_MSB                               10
#define MAC_PCU_OBS_BUS_1_RX_FRAME_LSB                               10
#define MAC_PCU_OBS_BUS_1_RX_FRAME_MASK                              0x00000400
#define MAC_PCU_OBS_BUS_1_RX_FRAME_GET(x)                            (((x) & MAC_PCU_OBS_BUS_1_RX_FRAME_MASK) >> MAC_PCU_OBS_BUS_1_RX_FRAME_LSB)
#define MAC_PCU_OBS_BUS_1_RX_FRAME_SET(x)                            (((0 | (x)) << MAC_PCU_OBS_BUS_1_RX_FRAME_LSB) & MAC_PCU_OBS_BUS_1_RX_FRAME_MASK)
#define MAC_PCU_OBS_BUS_1_RX_FRAME_RESET                             0
#define MAC_PCU_OBS_BUS_1_TX_FRAME_MSB                               9
#define MAC_PCU_OBS_BUS_1_TX_FRAME_LSB                               9
#define MAC_PCU_OBS_BUS_1_TX_FRAME_MASK                              0x00000200
#define MAC_PCU_OBS_BUS_1_TX_FRAME_GET(x)                            (((x) & MAC_PCU_OBS_BUS_1_TX_FRAME_MASK) >> MAC_PCU_OBS_BUS_1_TX_FRAME_LSB)
#define MAC_PCU_OBS_BUS_1_TX_FRAME_SET(x)                            (((0 | (x)) << MAC_PCU_OBS_BUS_1_TX_FRAME_LSB) & MAC_PCU_OBS_BUS_1_TX_FRAME_MASK)
#define MAC_PCU_OBS_BUS_1_TX_FRAME_RESET                             0
#define MAC_PCU_OBS_BUS_1_TX_HOLD_MSB                                8
#define MAC_PCU_OBS_BUS_1_TX_HOLD_LSB                                8
#define MAC_PCU_OBS_BUS_1_TX_HOLD_MASK                               0x00000100
#define MAC_PCU_OBS_BUS_1_TX_HOLD_GET(x)                             (((x) & MAC_PCU_OBS_BUS_1_TX_HOLD_MASK) >> MAC_PCU_OBS_BUS_1_TX_HOLD_LSB)
#define MAC_PCU_OBS_BUS_1_TX_HOLD_SET(x)                             (((0 | (x)) << MAC_PCU_OBS_BUS_1_TX_HOLD_LSB) & MAC_PCU_OBS_BUS_1_TX_HOLD_MASK)
#define MAC_PCU_OBS_BUS_1_TX_HOLD_RESET                              0
#define MAC_PCU_OBS_BUS_1_PCU_CHANNEL_IDLE_MSB                       7
#define MAC_PCU_OBS_BUS_1_PCU_CHANNEL_IDLE_LSB                       7
#define MAC_PCU_OBS_BUS_1_PCU_CHANNEL_IDLE_MASK                      0x00000080
#define MAC_PCU_OBS_BUS_1_PCU_CHANNEL_IDLE_GET(x)                    (((x) & MAC_PCU_OBS_BUS_1_PCU_CHANNEL_IDLE_MASK) >> MAC_PCU_OBS_BUS_1_PCU_CHANNEL_IDLE_LSB)
#define MAC_PCU_OBS_BUS_1_PCU_CHANNEL_IDLE_SET(x)                    (((0 | (x)) << MAC_PCU_OBS_BUS_1_PCU_CHANNEL_IDLE_LSB) & MAC_PCU_OBS_BUS_1_PCU_CHANNEL_IDLE_MASK)
#define MAC_PCU_OBS_BUS_1_PCU_CHANNEL_IDLE_RESET                     0
#define MAC_PCU_OBS_BUS_1_TM_QUIET_TIME_MSB                          6
#define MAC_PCU_OBS_BUS_1_TM_QUIET_TIME_LSB                          6
#define MAC_PCU_OBS_BUS_1_TM_QUIET_TIME_MASK                         0x00000040
#define MAC_PCU_OBS_BUS_1_TM_QUIET_TIME_GET(x)                       (((x) & MAC_PCU_OBS_BUS_1_TM_QUIET_TIME_MASK) >> MAC_PCU_OBS_BUS_1_TM_QUIET_TIME_LSB)
#define MAC_PCU_OBS_BUS_1_TM_QUIET_TIME_SET(x)                       (((0 | (x)) << MAC_PCU_OBS_BUS_1_TM_QUIET_TIME_LSB) & MAC_PCU_OBS_BUS_1_TM_QUIET_TIME_MASK)
#define MAC_PCU_OBS_BUS_1_TM_QUIET_TIME_RESET                        0
#define MAC_PCU_OBS_BUS_1_TX_HCF_MSB                                 5
#define MAC_PCU_OBS_BUS_1_TX_HCF_LSB                                 5
#define MAC_PCU_OBS_BUS_1_TX_HCF_MASK                                0x00000020
#define MAC_PCU_OBS_BUS_1_TX_HCF_GET(x)                              (((x) & MAC_PCU_OBS_BUS_1_TX_HCF_MASK) >> MAC_PCU_OBS_BUS_1_TX_HCF_LSB)
#define MAC_PCU_OBS_BUS_1_TX_HCF_SET(x)                              (((0 | (x)) << MAC_PCU_OBS_BUS_1_TX_HCF_LSB) & MAC_PCU_OBS_BUS_1_TX_HCF_MASK)
#define MAC_PCU_OBS_BUS_1_TX_HCF_RESET                               0
#define MAC_PCU_OBS_BUS_1_FILTER_PASS_MSB                            4
#define MAC_PCU_OBS_BUS_1_FILTER_PASS_LSB                            4
#define MAC_PCU_OBS_BUS_1_FILTER_PASS_MASK                           0x00000010
#define MAC_PCU_OBS_BUS_1_FILTER_PASS_GET(x)                         (((x) & MAC_PCU_OBS_BUS_1_FILTER_PASS_MASK) >> MAC_PCU_OBS_BUS_1_FILTER_PASS_LSB)
#define MAC_PCU_OBS_BUS_1_FILTER_PASS_SET(x)                         (((0 | (x)) << MAC_PCU_OBS_BUS_1_FILTER_PASS_LSB) & MAC_PCU_OBS_BUS_1_FILTER_PASS_MASK)
#define MAC_PCU_OBS_BUS_1_FILTER_PASS_RESET                          0
#define MAC_PCU_OBS_BUS_1_RX_MY_BEACON_MSB                           3
#define MAC_PCU_OBS_BUS_1_RX_MY_BEACON_LSB                           3
#define MAC_PCU_OBS_BUS_1_RX_MY_BEACON_MASK                          0x00000008
#define MAC_PCU_OBS_BUS_1_RX_MY_BEACON_GET(x)                        (((x) & MAC_PCU_OBS_BUS_1_RX_MY_BEACON_MASK) >> MAC_PCU_OBS_BUS_1_RX_MY_BEACON_LSB)
#define MAC_PCU_OBS_BUS_1_RX_MY_BEACON_SET(x)                        (((0 | (x)) << MAC_PCU_OBS_BUS_1_RX_MY_BEACON_LSB) & MAC_PCU_OBS_BUS_1_RX_MY_BEACON_MASK)
#define MAC_PCU_OBS_BUS_1_RX_MY_BEACON_RESET                         0
#define MAC_PCU_OBS_BUS_1_RX_WEP_MSB                                 2
#define MAC_PCU_OBS_BUS_1_RX_WEP_LSB                                 2
#define MAC_PCU_OBS_BUS_1_RX_WEP_MASK                                0x00000004
#define MAC_PCU_OBS_BUS_1_RX_WEP_GET(x)                              (((x) & MAC_PCU_OBS_BUS_1_RX_WEP_MASK) >> MAC_PCU_OBS_BUS_1_RX_WEP_LSB)
#define MAC_PCU_OBS_BUS_1_RX_WEP_SET(x)                              (((0 | (x)) << MAC_PCU_OBS_BUS_1_RX_WEP_LSB) & MAC_PCU_OBS_BUS_1_RX_WEP_MASK)
#define MAC_PCU_OBS_BUS_1_RX_WEP_RESET                               0
#define MAC_PCU_OBS_BUS_1_PCU_RX_END_MSB                             1
#define MAC_PCU_OBS_BUS_1_PCU_RX_END_LSB                             1
#define MAC_PCU_OBS_BUS_1_PCU_RX_END_MASK                            0x00000002
#define MAC_PCU_OBS_BUS_1_PCU_RX_END_GET(x)                          (((x) & MAC_PCU_OBS_BUS_1_PCU_RX_END_MASK) >> MAC_PCU_OBS_BUS_1_PCU_RX_END_LSB)
#define MAC_PCU_OBS_BUS_1_PCU_RX_END_SET(x)                          (((0 | (x)) << MAC_PCU_OBS_BUS_1_PCU_RX_END_LSB) & MAC_PCU_OBS_BUS_1_PCU_RX_END_MASK)
#define MAC_PCU_OBS_BUS_1_PCU_RX_END_RESET                           0
#define MAC_PCU_OBS_BUS_1_PCU_DIRECTED_MSB                           0
#define MAC_PCU_OBS_BUS_1_PCU_DIRECTED_LSB                           0
#define MAC_PCU_OBS_BUS_1_PCU_DIRECTED_MASK                          0x00000001
#define MAC_PCU_OBS_BUS_1_PCU_DIRECTED_GET(x)                        (((x) & MAC_PCU_OBS_BUS_1_PCU_DIRECTED_MASK) >> MAC_PCU_OBS_BUS_1_PCU_DIRECTED_LSB)
#define MAC_PCU_OBS_BUS_1_PCU_DIRECTED_SET(x)                        (((0 | (x)) << MAC_PCU_OBS_BUS_1_PCU_DIRECTED_LSB) & MAC_PCU_OBS_BUS_1_PCU_DIRECTED_MASK)
#define MAC_PCU_OBS_BUS_1_PCU_DIRECTED_RESET                         0
#define MAC_PCU_OBS_BUS_1_ADDRESS                                    0x806c
#define MAC_PCU_OBS_BUS_1_HW_MASK                                    0x7ff3ffff
#define MAC_PCU_OBS_BUS_1_SW_MASK                                    0x7ff3ffff
#define MAC_PCU_OBS_BUS_1_HW_WRITE_MASK                              0x7ff3ffff
#define MAC_PCU_OBS_BUS_1_SW_WRITE_MASK                              0x00000000
#define MAC_PCU_OBS_BUS_1_RSTMASK                                    0xffffffff
#define MAC_PCU_OBS_BUS_1_RESET                                      0x00000000

// 0x8070 (MAC_PCU_DYM_MIMO_PWR_SAVE)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HI_PWR_CHAIN_MASK_MSB              10
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HI_PWR_CHAIN_MASK_LSB              8
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HI_PWR_CHAIN_MASK_MASK             0x00000700
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HI_PWR_CHAIN_MASK_GET(x)           (((x) & MAC_PCU_DYM_MIMO_PWR_SAVE_HI_PWR_CHAIN_MASK_MASK) >> MAC_PCU_DYM_MIMO_PWR_SAVE_HI_PWR_CHAIN_MASK_LSB)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HI_PWR_CHAIN_MASK_SET(x)           (((0 | (x)) << MAC_PCU_DYM_MIMO_PWR_SAVE_HI_PWR_CHAIN_MASK_LSB) & MAC_PCU_DYM_MIMO_PWR_SAVE_HI_PWR_CHAIN_MASK_MASK)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HI_PWR_CHAIN_MASK_RESET            3
#define MAC_PCU_DYM_MIMO_PWR_SAVE_LOW_PWR_CHAIN_MASK_MSB             6
#define MAC_PCU_DYM_MIMO_PWR_SAVE_LOW_PWR_CHAIN_MASK_LSB             4
#define MAC_PCU_DYM_MIMO_PWR_SAVE_LOW_PWR_CHAIN_MASK_MASK            0x00000070
#define MAC_PCU_DYM_MIMO_PWR_SAVE_LOW_PWR_CHAIN_MASK_GET(x)          (((x) & MAC_PCU_DYM_MIMO_PWR_SAVE_LOW_PWR_CHAIN_MASK_MASK) >> MAC_PCU_DYM_MIMO_PWR_SAVE_LOW_PWR_CHAIN_MASK_LSB)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_LOW_PWR_CHAIN_MASK_SET(x)          (((0 | (x)) << MAC_PCU_DYM_MIMO_PWR_SAVE_LOW_PWR_CHAIN_MASK_LSB) & MAC_PCU_DYM_MIMO_PWR_SAVE_LOW_PWR_CHAIN_MASK_MASK)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_LOW_PWR_CHAIN_MASK_RESET           1
#define MAC_PCU_DYM_MIMO_PWR_SAVE_SW_CHAIN_MASK_SEL_MSB              2
#define MAC_PCU_DYM_MIMO_PWR_SAVE_SW_CHAIN_MASK_SEL_LSB              2
#define MAC_PCU_DYM_MIMO_PWR_SAVE_SW_CHAIN_MASK_SEL_MASK             0x00000004
#define MAC_PCU_DYM_MIMO_PWR_SAVE_SW_CHAIN_MASK_SEL_GET(x)           (((x) & MAC_PCU_DYM_MIMO_PWR_SAVE_SW_CHAIN_MASK_SEL_MASK) >> MAC_PCU_DYM_MIMO_PWR_SAVE_SW_CHAIN_MASK_SEL_LSB)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_SW_CHAIN_MASK_SEL_SET(x)           (((0 | (x)) << MAC_PCU_DYM_MIMO_PWR_SAVE_SW_CHAIN_MASK_SEL_LSB) & MAC_PCU_DYM_MIMO_PWR_SAVE_SW_CHAIN_MASK_SEL_MASK)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_SW_CHAIN_MASK_SEL_RESET            0
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HW_CTRL_EN_MSB                     1
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HW_CTRL_EN_LSB                     1
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HW_CTRL_EN_MASK                    0x00000002
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HW_CTRL_EN_GET(x)                  (((x) & MAC_PCU_DYM_MIMO_PWR_SAVE_HW_CTRL_EN_MASK) >> MAC_PCU_DYM_MIMO_PWR_SAVE_HW_CTRL_EN_LSB)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HW_CTRL_EN_SET(x)                  (((0 | (x)) << MAC_PCU_DYM_MIMO_PWR_SAVE_HW_CTRL_EN_LSB) & MAC_PCU_DYM_MIMO_PWR_SAVE_HW_CTRL_EN_MASK)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HW_CTRL_EN_RESET                   0
#define MAC_PCU_DYM_MIMO_PWR_SAVE_USE_MAC_CTRL_MSB                   0
#define MAC_PCU_DYM_MIMO_PWR_SAVE_USE_MAC_CTRL_LSB                   0
#define MAC_PCU_DYM_MIMO_PWR_SAVE_USE_MAC_CTRL_MASK                  0x00000001
#define MAC_PCU_DYM_MIMO_PWR_SAVE_USE_MAC_CTRL_GET(x)                (((x) & MAC_PCU_DYM_MIMO_PWR_SAVE_USE_MAC_CTRL_MASK) >> MAC_PCU_DYM_MIMO_PWR_SAVE_USE_MAC_CTRL_LSB)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_USE_MAC_CTRL_SET(x)                (((0 | (x)) << MAC_PCU_DYM_MIMO_PWR_SAVE_USE_MAC_CTRL_LSB) & MAC_PCU_DYM_MIMO_PWR_SAVE_USE_MAC_CTRL_MASK)
#define MAC_PCU_DYM_MIMO_PWR_SAVE_USE_MAC_CTRL_RESET                 0
#define MAC_PCU_DYM_MIMO_PWR_SAVE_ADDRESS                            0x8070
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HW_MASK                            0x00000777
#define MAC_PCU_DYM_MIMO_PWR_SAVE_SW_MASK                            0x00000777
#define MAC_PCU_DYM_MIMO_PWR_SAVE_HW_WRITE_MASK                      0x00000000
#define MAC_PCU_DYM_MIMO_PWR_SAVE_SW_WRITE_MASK                      0x00000777
#define MAC_PCU_DYM_MIMO_PWR_SAVE_RSTMASK                            0xffffffff
#define MAC_PCU_DYM_MIMO_PWR_SAVE_RESET                              0x00000310

// 0x8080 (MAC_PCU_LAST_BEACON_TSF)
#define MAC_PCU_LAST_BEACON_TSF_VALUE_MSB                            31
#define MAC_PCU_LAST_BEACON_TSF_VALUE_LSB                            0
#define MAC_PCU_LAST_BEACON_TSF_VALUE_MASK                           0xffffffff
#define MAC_PCU_LAST_BEACON_TSF_VALUE_GET(x)                         (((x) & MAC_PCU_LAST_BEACON_TSF_VALUE_MASK) >> MAC_PCU_LAST_BEACON_TSF_VALUE_LSB)
#define MAC_PCU_LAST_BEACON_TSF_VALUE_SET(x)                         (((0 | (x)) << MAC_PCU_LAST_BEACON_TSF_VALUE_LSB) & MAC_PCU_LAST_BEACON_TSF_VALUE_MASK)
#define MAC_PCU_LAST_BEACON_TSF_VALUE_RESET                          0
#define MAC_PCU_LAST_BEACON_TSF_ADDRESS                              0x8080
#define MAC_PCU_LAST_BEACON_TSF_HW_MASK                              0xffffffff
#define MAC_PCU_LAST_BEACON_TSF_SW_MASK                              0xffffffff
#define MAC_PCU_LAST_BEACON_TSF_HW_WRITE_MASK                        0xffffffff
#define MAC_PCU_LAST_BEACON_TSF_SW_WRITE_MASK                        0x00000000
#define MAC_PCU_LAST_BEACON_TSF_RSTMASK                              0xffffffff
#define MAC_PCU_LAST_BEACON_TSF_RESET                                0x00000000

// 0x8084 (MAC_PCU_NAV)
#define MAC_PCU_NAV_VALUE_MSB                                        25
#define MAC_PCU_NAV_VALUE_LSB                                        0
#define MAC_PCU_NAV_VALUE_MASK                                       0x03ffffff
#define MAC_PCU_NAV_VALUE_GET(x)                                     (((x) & MAC_PCU_NAV_VALUE_MASK) >> MAC_PCU_NAV_VALUE_LSB)
#define MAC_PCU_NAV_VALUE_SET(x)                                     (((0 | (x)) << MAC_PCU_NAV_VALUE_LSB) & MAC_PCU_NAV_VALUE_MASK)
#define MAC_PCU_NAV_VALUE_RESET                                      0
#define MAC_PCU_NAV_ADDRESS                                          0x8084
#define MAC_PCU_NAV_HW_MASK                                          0x03ffffff
#define MAC_PCU_NAV_SW_MASK                                          0x03ffffff
#define MAC_PCU_NAV_HW_WRITE_MASK                                    0x03ffffff
#define MAC_PCU_NAV_SW_WRITE_MASK                                    0x03ffffff
#define MAC_PCU_NAV_RSTMASK                                          0xffffffff
#define MAC_PCU_NAV_RESET                                            0x00000000

// 0x8088 (MAC_PCU_RTS_SUCCESS_CNT)
#define MAC_PCU_RTS_SUCCESS_CNT_VALUE_MSB                            15
#define MAC_PCU_RTS_SUCCESS_CNT_VALUE_LSB                            0
#define MAC_PCU_RTS_SUCCESS_CNT_VALUE_MASK                           0x0000ffff
#define MAC_PCU_RTS_SUCCESS_CNT_VALUE_GET(x)                         (((x) & MAC_PCU_RTS_SUCCESS_CNT_VALUE_MASK) >> MAC_PCU_RTS_SUCCESS_CNT_VALUE_LSB)
#define MAC_PCU_RTS_SUCCESS_CNT_VALUE_SET(x)                         (((0 | (x)) << MAC_PCU_RTS_SUCCESS_CNT_VALUE_LSB) & MAC_PCU_RTS_SUCCESS_CNT_VALUE_MASK)
#define MAC_PCU_RTS_SUCCESS_CNT_VALUE_RESET                          0
#define MAC_PCU_RTS_SUCCESS_CNT_ADDRESS                              0x8088
#define MAC_PCU_RTS_SUCCESS_CNT_HW_MASK                              0x0000ffff
#define MAC_PCU_RTS_SUCCESS_CNT_SW_MASK                              0x0000ffff
#define MAC_PCU_RTS_SUCCESS_CNT_HW_WRITE_MASK                        0x0000ffff
#define MAC_PCU_RTS_SUCCESS_CNT_SW_WRITE_MASK                        0x00000000
#define MAC_PCU_RTS_SUCCESS_CNT_RSTMASK                              0xffffffff
#define MAC_PCU_RTS_SUCCESS_CNT_RESET                                0x00000000

// 0x808c (MAC_PCU_RTS_FAIL_CNT)
#define MAC_PCU_RTS_FAIL_CNT_VALUE_MSB                               15
#define MAC_PCU_RTS_FAIL_CNT_VALUE_LSB                               0
#define MAC_PCU_RTS_FAIL_CNT_VALUE_MASK                              0x0000ffff
#define MAC_PCU_RTS_FAIL_CNT_VALUE_GET(x)                            (((x) & MAC_PCU_RTS_FAIL_CNT_VALUE_MASK) >> MAC_PCU_RTS_FAIL_CNT_VALUE_LSB)
#define MAC_PCU_RTS_FAIL_CNT_VALUE_SET(x)                            (((0 | (x)) << MAC_PCU_RTS_FAIL_CNT_VALUE_LSB) & MAC_PCU_RTS_FAIL_CNT_VALUE_MASK)
#define MAC_PCU_RTS_FAIL_CNT_VALUE_RESET                             0
#define MAC_PCU_RTS_FAIL_CNT_ADDRESS                                 0x808c
#define MAC_PCU_RTS_FAIL_CNT_HW_MASK                                 0x0000ffff
#define MAC_PCU_RTS_FAIL_CNT_SW_MASK                                 0x0000ffff
#define MAC_PCU_RTS_FAIL_CNT_HW_WRITE_MASK                           0x0000ffff
#define MAC_PCU_RTS_FAIL_CNT_SW_WRITE_MASK                           0x00000000
#define MAC_PCU_RTS_FAIL_CNT_RSTMASK                                 0xffffffff
#define MAC_PCU_RTS_FAIL_CNT_RESET                                   0x00000000

// 0x8090 (MAC_PCU_ACK_FAIL_CNT)
#define MAC_PCU_ACK_FAIL_CNT_VALUE_MSB                               15
#define MAC_PCU_ACK_FAIL_CNT_VALUE_LSB                               0
#define MAC_PCU_ACK_FAIL_CNT_VALUE_MASK                              0x0000ffff
#define MAC_PCU_ACK_FAIL_CNT_VALUE_GET(x)                            (((x) & MAC_PCU_ACK_FAIL_CNT_VALUE_MASK) >> MAC_PCU_ACK_FAIL_CNT_VALUE_LSB)
#define MAC_PCU_ACK_FAIL_CNT_VALUE_SET(x)                            (((0 | (x)) << MAC_PCU_ACK_FAIL_CNT_VALUE_LSB) & MAC_PCU_ACK_FAIL_CNT_VALUE_MASK)
#define MAC_PCU_ACK_FAIL_CNT_VALUE_RESET                             0
#define MAC_PCU_ACK_FAIL_CNT_ADDRESS                                 0x8090
#define MAC_PCU_ACK_FAIL_CNT_HW_MASK                                 0x0000ffff
#define MAC_PCU_ACK_FAIL_CNT_SW_MASK                                 0x0000ffff
#define MAC_PCU_ACK_FAIL_CNT_HW_WRITE_MASK                           0x0000ffff
#define MAC_PCU_ACK_FAIL_CNT_SW_WRITE_MASK                           0x00000000
#define MAC_PCU_ACK_FAIL_CNT_RSTMASK                                 0xffffffff
#define MAC_PCU_ACK_FAIL_CNT_RESET                                   0x00000000

// 0x8094 (MAC_PCU_FCS_FAIL_CNT)
#define MAC_PCU_FCS_FAIL_CNT_VALUE_MSB                               15
#define MAC_PCU_FCS_FAIL_CNT_VALUE_LSB                               0
#define MAC_PCU_FCS_FAIL_CNT_VALUE_MASK                              0x0000ffff
#define MAC_PCU_FCS_FAIL_CNT_VALUE_GET(x)                            (((x) & MAC_PCU_FCS_FAIL_CNT_VALUE_MASK) >> MAC_PCU_FCS_FAIL_CNT_VALUE_LSB)
#define MAC_PCU_FCS_FAIL_CNT_VALUE_SET(x)                            (((0 | (x)) << MAC_PCU_FCS_FAIL_CNT_VALUE_LSB) & MAC_PCU_FCS_FAIL_CNT_VALUE_MASK)
#define MAC_PCU_FCS_FAIL_CNT_VALUE_RESET                             0
#define MAC_PCU_FCS_FAIL_CNT_ADDRESS                                 0x8094
#define MAC_PCU_FCS_FAIL_CNT_HW_MASK                                 0x0000ffff
#define MAC_PCU_FCS_FAIL_CNT_SW_MASK                                 0x0000ffff
#define MAC_PCU_FCS_FAIL_CNT_HW_WRITE_MASK                           0x0000ffff
#define MAC_PCU_FCS_FAIL_CNT_SW_WRITE_MASK                           0x00000000
#define MAC_PCU_FCS_FAIL_CNT_RSTMASK                                 0xffffffff
#define MAC_PCU_FCS_FAIL_CNT_RESET                                   0x00000000

// 0x8098 (MAC_PCU_BEACON_CNT)
#define MAC_PCU_BEACON_CNT_VALUE_MSB                                 15
#define MAC_PCU_BEACON_CNT_VALUE_LSB                                 0
#define MAC_PCU_BEACON_CNT_VALUE_MASK                                0x0000ffff
#define MAC_PCU_BEACON_CNT_VALUE_GET(x)                              (((x) & MAC_PCU_BEACON_CNT_VALUE_MASK) >> MAC_PCU_BEACON_CNT_VALUE_LSB)
#define MAC_PCU_BEACON_CNT_VALUE_SET(x)                              (((0 | (x)) << MAC_PCU_BEACON_CNT_VALUE_LSB) & MAC_PCU_BEACON_CNT_VALUE_MASK)
#define MAC_PCU_BEACON_CNT_VALUE_RESET                               0
#define MAC_PCU_BEACON_CNT_ADDRESS                                   0x8098
#define MAC_PCU_BEACON_CNT_HW_MASK                                   0x0000ffff
#define MAC_PCU_BEACON_CNT_SW_MASK                                   0x0000ffff
#define MAC_PCU_BEACON_CNT_HW_WRITE_MASK                             0x0000ffff
#define MAC_PCU_BEACON_CNT_SW_WRITE_MASK                             0x00000000
#define MAC_PCU_BEACON_CNT_RSTMASK                                   0xffffffff
#define MAC_PCU_BEACON_CNT_RESET                                     0x00000000

// 0x809c (MAC_PCU_BEACON2_CNT)
#define MAC_PCU_BEACON2_CNT_VALUE_MSB                                15
#define MAC_PCU_BEACON2_CNT_VALUE_LSB                                0
#define MAC_PCU_BEACON2_CNT_VALUE_MASK                               0x0000ffff
#define MAC_PCU_BEACON2_CNT_VALUE_GET(x)                             (((x) & MAC_PCU_BEACON2_CNT_VALUE_MASK) >> MAC_PCU_BEACON2_CNT_VALUE_LSB)
#define MAC_PCU_BEACON2_CNT_VALUE_SET(x)                             (((0 | (x)) << MAC_PCU_BEACON2_CNT_VALUE_LSB) & MAC_PCU_BEACON2_CNT_VALUE_MASK)
#define MAC_PCU_BEACON2_CNT_VALUE_RESET                              0
#define MAC_PCU_BEACON2_CNT_ADDRESS                                  0x809c
#define MAC_PCU_BEACON2_CNT_HW_MASK                                  0x0000ffff
#define MAC_PCU_BEACON2_CNT_SW_MASK                                  0x0000ffff
#define MAC_PCU_BEACON2_CNT_HW_WRITE_MASK                            0x0000ffff
#define MAC_PCU_BEACON2_CNT_SW_WRITE_MASK                            0x00000000
#define MAC_PCU_BEACON2_CNT_RSTMASK                                  0xffffffff
#define MAC_PCU_BEACON2_CNT_RESET                                    0x00000000

// 0x80a0 (MAC_PCU_BASIC_SET)
#define MAC_PCU_BASIC_SET_MCS_MSB                                    31
#define MAC_PCU_BASIC_SET_MCS_LSB                                    0
#define MAC_PCU_BASIC_SET_MCS_MASK                                   0xffffffff
#define MAC_PCU_BASIC_SET_MCS_GET(x)                                 (((x) & MAC_PCU_BASIC_SET_MCS_MASK) >> MAC_PCU_BASIC_SET_MCS_LSB)
#define MAC_PCU_BASIC_SET_MCS_SET(x)                                 (((0 | (x)) << MAC_PCU_BASIC_SET_MCS_LSB) & MAC_PCU_BASIC_SET_MCS_MASK)
#define MAC_PCU_BASIC_SET_MCS_RESET                                  0
#define MAC_PCU_BASIC_SET_ADDRESS                                    0x80a0
#define MAC_PCU_BASIC_SET_HW_MASK                                    0xffffffff
#define MAC_PCU_BASIC_SET_SW_MASK                                    0xffffffff
#define MAC_PCU_BASIC_SET_HW_WRITE_MASK                              0x00000000
#define MAC_PCU_BASIC_SET_SW_WRITE_MASK                              0xffffffff
#define MAC_PCU_BASIC_SET_RSTMASK                                    0xffffffff
#define MAC_PCU_BASIC_SET_RESET                                      0x00000000

// 0x80a4 (MAC_PCU_MGMT_SEQ)
#define MAC_PCU_MGMT_SEQ_MAX_MSB                                     27
#define MAC_PCU_MGMT_SEQ_MAX_LSB                                     16
#define MAC_PCU_MGMT_SEQ_MAX_MASK                                    0x0fff0000
#define MAC_PCU_MGMT_SEQ_MAX_GET(x)                                  (((x) & MAC_PCU_MGMT_SEQ_MAX_MASK) >> MAC_PCU_MGMT_SEQ_MAX_LSB)
#define MAC_PCU_MGMT_SEQ_MAX_SET(x)                                  (((0 | (x)) << MAC_PCU_MGMT_SEQ_MAX_LSB) & MAC_PCU_MGMT_SEQ_MAX_MASK)
#define MAC_PCU_MGMT_SEQ_MAX_RESET                                   767
#define MAC_PCU_MGMT_SEQ_MIN_MSB                                     11
#define MAC_PCU_MGMT_SEQ_MIN_LSB                                     0
#define MAC_PCU_MGMT_SEQ_MIN_MASK                                    0x00000fff
#define MAC_PCU_MGMT_SEQ_MIN_GET(x)                                  (((x) & MAC_PCU_MGMT_SEQ_MIN_MASK) >> MAC_PCU_MGMT_SEQ_MIN_LSB)
#define MAC_PCU_MGMT_SEQ_MIN_SET(x)                                  (((0 | (x)) << MAC_PCU_MGMT_SEQ_MIN_LSB) & MAC_PCU_MGMT_SEQ_MIN_MASK)
#define MAC_PCU_MGMT_SEQ_MIN_RESET                                   0
#define MAC_PCU_MGMT_SEQ_ADDRESS                                     0x80a4
#define MAC_PCU_MGMT_SEQ_HW_MASK                                     0x0fff0fff
#define MAC_PCU_MGMT_SEQ_SW_MASK                                     0x0fff0fff
#define MAC_PCU_MGMT_SEQ_HW_WRITE_MASK                               0x00000000
#define MAC_PCU_MGMT_SEQ_SW_WRITE_MASK                               0x0fff0fff
#define MAC_PCU_MGMT_SEQ_RSTMASK                                     0xffffffff
#define MAC_PCU_MGMT_SEQ_RESET                                       0x02ff0000

// 0x80a8 (MAC_PCU_BF_RPT1)
#define MAC_PCU_BF_RPT1_FRAME_TYPE_VALUE_MSB                         29
#define MAC_PCU_BF_RPT1_FRAME_TYPE_VALUE_LSB                         28
#define MAC_PCU_BF_RPT1_FRAME_TYPE_VALUE_MASK                        0x30000000
#define MAC_PCU_BF_RPT1_FRAME_TYPE_VALUE_GET(x)                      (((x) & MAC_PCU_BF_RPT1_FRAME_TYPE_VALUE_MASK) >> MAC_PCU_BF_RPT1_FRAME_TYPE_VALUE_LSB)
#define MAC_PCU_BF_RPT1_FRAME_TYPE_VALUE_SET(x)                      (((0 | (x)) << MAC_PCU_BF_RPT1_FRAME_TYPE_VALUE_LSB) & MAC_PCU_BF_RPT1_FRAME_TYPE_VALUE_MASK)
#define MAC_PCU_BF_RPT1_FRAME_TYPE_VALUE_RESET                       0
#define MAC_PCU_BF_RPT1_FRAME_SUBTYPE_VALUE_MSB                      27
#define MAC_PCU_BF_RPT1_FRAME_SUBTYPE_VALUE_LSB                      24
#define MAC_PCU_BF_RPT1_FRAME_SUBTYPE_VALUE_MASK                     0x0f000000
#define MAC_PCU_BF_RPT1_FRAME_SUBTYPE_VALUE_GET(x)                   (((x) & MAC_PCU_BF_RPT1_FRAME_SUBTYPE_VALUE_MASK) >> MAC_PCU_BF_RPT1_FRAME_SUBTYPE_VALUE_LSB)
#define MAC_PCU_BF_RPT1_FRAME_SUBTYPE_VALUE_SET(x)                   (((0 | (x)) << MAC_PCU_BF_RPT1_FRAME_SUBTYPE_VALUE_LSB) & MAC_PCU_BF_RPT1_FRAME_SUBTYPE_VALUE_MASK)
#define MAC_PCU_BF_RPT1_FRAME_SUBTYPE_VALUE_RESET                    14
#define MAC_PCU_BF_RPT1_CATEGORY_VALUE_MSB                           23
#define MAC_PCU_BF_RPT1_CATEGORY_VALUE_LSB                           16
#define MAC_PCU_BF_RPT1_CATEGORY_VALUE_MASK                          0x00ff0000
#define MAC_PCU_BF_RPT1_CATEGORY_VALUE_GET(x)                        (((x) & MAC_PCU_BF_RPT1_CATEGORY_VALUE_MASK) >> MAC_PCU_BF_RPT1_CATEGORY_VALUE_LSB)
#define MAC_PCU_BF_RPT1_CATEGORY_VALUE_SET(x)                        (((0 | (x)) << MAC_PCU_BF_RPT1_CATEGORY_VALUE_LSB) & MAC_PCU_BF_RPT1_CATEGORY_VALUE_MASK)
#define MAC_PCU_BF_RPT1_CATEGORY_VALUE_RESET                         7
#define MAC_PCU_BF_RPT1_CV_ACTION_VALUE_MSB                          15
#define MAC_PCU_BF_RPT1_CV_ACTION_VALUE_LSB                          8
#define MAC_PCU_BF_RPT1_CV_ACTION_VALUE_MASK                         0x0000ff00
#define MAC_PCU_BF_RPT1_CV_ACTION_VALUE_GET(x)                       (((x) & MAC_PCU_BF_RPT1_CV_ACTION_VALUE_MASK) >> MAC_PCU_BF_RPT1_CV_ACTION_VALUE_LSB)
#define MAC_PCU_BF_RPT1_CV_ACTION_VALUE_SET(x)                       (((0 | (x)) << MAC_PCU_BF_RPT1_CV_ACTION_VALUE_LSB) & MAC_PCU_BF_RPT1_CV_ACTION_VALUE_MASK)
#define MAC_PCU_BF_RPT1_CV_ACTION_VALUE_RESET                        6
#define MAC_PCU_BF_RPT1_V_ACTION_VALUE_MSB                           7
#define MAC_PCU_BF_RPT1_V_ACTION_VALUE_LSB                           0
#define MAC_PCU_BF_RPT1_V_ACTION_VALUE_MASK                          0x000000ff
#define MAC_PCU_BF_RPT1_V_ACTION_VALUE_GET(x)                        (((x) & MAC_PCU_BF_RPT1_V_ACTION_VALUE_MASK) >> MAC_PCU_BF_RPT1_V_ACTION_VALUE_LSB)
#define MAC_PCU_BF_RPT1_V_ACTION_VALUE_SET(x)                        (((0 | (x)) << MAC_PCU_BF_RPT1_V_ACTION_VALUE_LSB) & MAC_PCU_BF_RPT1_V_ACTION_VALUE_MASK)
#define MAC_PCU_BF_RPT1_V_ACTION_VALUE_RESET                         5
#define MAC_PCU_BF_RPT1_ADDRESS                                      0x80a8
#define MAC_PCU_BF_RPT1_HW_MASK                                      0x3fffffff
#define MAC_PCU_BF_RPT1_SW_MASK                                      0x3fffffff
#define MAC_PCU_BF_RPT1_HW_WRITE_MASK                                0x00000000
#define MAC_PCU_BF_RPT1_SW_WRITE_MASK                                0x3fffffff
#define MAC_PCU_BF_RPT1_RSTMASK                                      0xffffffff
#define MAC_PCU_BF_RPT1_RESET                                        0x0e070605

// 0x80ac (MAC_PCU_BF_RPT2)
#define MAC_PCU_BF_RPT2_FRAME_SUBTYPE_VALUE_MSB                      3
#define MAC_PCU_BF_RPT2_FRAME_SUBTYPE_VALUE_LSB                      0
#define MAC_PCU_BF_RPT2_FRAME_SUBTYPE_VALUE_MASK                     0x0000000f
#define MAC_PCU_BF_RPT2_FRAME_SUBTYPE_VALUE_GET(x)                   (((x) & MAC_PCU_BF_RPT2_FRAME_SUBTYPE_VALUE_MASK) >> MAC_PCU_BF_RPT2_FRAME_SUBTYPE_VALUE_LSB)
#define MAC_PCU_BF_RPT2_FRAME_SUBTYPE_VALUE_SET(x)                   (((0 | (x)) << MAC_PCU_BF_RPT2_FRAME_SUBTYPE_VALUE_LSB) & MAC_PCU_BF_RPT2_FRAME_SUBTYPE_VALUE_MASK)
#define MAC_PCU_BF_RPT2_FRAME_SUBTYPE_VALUE_RESET                    13
#define MAC_PCU_BF_RPT2_ADDRESS                                      0x80ac
#define MAC_PCU_BF_RPT2_HW_MASK                                      0x0000000f
#define MAC_PCU_BF_RPT2_SW_MASK                                      0x0000000f
#define MAC_PCU_BF_RPT2_HW_WRITE_MASK                                0x00000000
#define MAC_PCU_BF_RPT2_SW_WRITE_MASK                                0x0000000f
#define MAC_PCU_BF_RPT2_RSTMASK                                      0xffffffff
#define MAC_PCU_BF_RPT2_RESET                                        0x0000000d

// 0x80b0 (MAC_PCU_TX_ANT_1)
#define MAC_PCU_TX_ANT_1_VALUE_MSB                                   31
#define MAC_PCU_TX_ANT_1_VALUE_LSB                                   0
#define MAC_PCU_TX_ANT_1_VALUE_MASK                                  0xffffffff
#define MAC_PCU_TX_ANT_1_VALUE_GET(x)                                (((x) & MAC_PCU_TX_ANT_1_VALUE_MASK) >> MAC_PCU_TX_ANT_1_VALUE_LSB)
#define MAC_PCU_TX_ANT_1_VALUE_SET(x)                                (((0 | (x)) << MAC_PCU_TX_ANT_1_VALUE_LSB) & MAC_PCU_TX_ANT_1_VALUE_MASK)
#define MAC_PCU_TX_ANT_1_VALUE_RESET                                 0
#define MAC_PCU_TX_ANT_1_ADDRESS                                     0x80b0
#define MAC_PCU_TX_ANT_1_HW_MASK                                     0xffffffff
#define MAC_PCU_TX_ANT_1_SW_MASK                                     0xffffffff
#define MAC_PCU_TX_ANT_1_HW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TX_ANT_1_SW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TX_ANT_1_RSTMASK                                     0xffffffff
#define MAC_PCU_TX_ANT_1_RESET                                       0x00000000

// 0x80b4 (MAC_PCU_TX_ANT_2)
#define MAC_PCU_TX_ANT_2_VALUE_MSB                                   31
#define MAC_PCU_TX_ANT_2_VALUE_LSB                                   0
#define MAC_PCU_TX_ANT_2_VALUE_MASK                                  0xffffffff
#define MAC_PCU_TX_ANT_2_VALUE_GET(x)                                (((x) & MAC_PCU_TX_ANT_2_VALUE_MASK) >> MAC_PCU_TX_ANT_2_VALUE_LSB)
#define MAC_PCU_TX_ANT_2_VALUE_SET(x)                                (((0 | (x)) << MAC_PCU_TX_ANT_2_VALUE_LSB) & MAC_PCU_TX_ANT_2_VALUE_MASK)
#define MAC_PCU_TX_ANT_2_VALUE_RESET                                 0
#define MAC_PCU_TX_ANT_2_ADDRESS                                     0x80b4
#define MAC_PCU_TX_ANT_2_HW_MASK                                     0xffffffff
#define MAC_PCU_TX_ANT_2_SW_MASK                                     0xffffffff
#define MAC_PCU_TX_ANT_2_HW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TX_ANT_2_SW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TX_ANT_2_RSTMASK                                     0xffffffff
#define MAC_PCU_TX_ANT_2_RESET                                       0x00000000

// 0x80b8 (MAC_PCU_TX_ANT_3)
#define MAC_PCU_TX_ANT_3_VALUE_MSB                                   31
#define MAC_PCU_TX_ANT_3_VALUE_LSB                                   0
#define MAC_PCU_TX_ANT_3_VALUE_MASK                                  0xffffffff
#define MAC_PCU_TX_ANT_3_VALUE_GET(x)                                (((x) & MAC_PCU_TX_ANT_3_VALUE_MASK) >> MAC_PCU_TX_ANT_3_VALUE_LSB)
#define MAC_PCU_TX_ANT_3_VALUE_SET(x)                                (((0 | (x)) << MAC_PCU_TX_ANT_3_VALUE_LSB) & MAC_PCU_TX_ANT_3_VALUE_MASK)
#define MAC_PCU_TX_ANT_3_VALUE_RESET                                 0
#define MAC_PCU_TX_ANT_3_ADDRESS                                     0x80b8
#define MAC_PCU_TX_ANT_3_HW_MASK                                     0xffffffff
#define MAC_PCU_TX_ANT_3_SW_MASK                                     0xffffffff
#define MAC_PCU_TX_ANT_3_HW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TX_ANT_3_SW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TX_ANT_3_RSTMASK                                     0xffffffff
#define MAC_PCU_TX_ANT_3_RESET                                       0x00000000

// 0x80bc (MAC_PCU_TX_ANT_4)
#define MAC_PCU_TX_ANT_4_VALUE_MSB                                   31
#define MAC_PCU_TX_ANT_4_VALUE_LSB                                   0
#define MAC_PCU_TX_ANT_4_VALUE_MASK                                  0xffffffff
#define MAC_PCU_TX_ANT_4_VALUE_GET(x)                                (((x) & MAC_PCU_TX_ANT_4_VALUE_MASK) >> MAC_PCU_TX_ANT_4_VALUE_LSB)
#define MAC_PCU_TX_ANT_4_VALUE_SET(x)                                (((0 | (x)) << MAC_PCU_TX_ANT_4_VALUE_LSB) & MAC_PCU_TX_ANT_4_VALUE_MASK)
#define MAC_PCU_TX_ANT_4_VALUE_RESET                                 0
#define MAC_PCU_TX_ANT_4_ADDRESS                                     0x80bc
#define MAC_PCU_TX_ANT_4_HW_MASK                                     0xffffffff
#define MAC_PCU_TX_ANT_4_SW_MASK                                     0xffffffff
#define MAC_PCU_TX_ANT_4_HW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TX_ANT_4_SW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TX_ANT_4_RSTMASK                                     0xffffffff
#define MAC_PCU_TX_ANT_4_RESET                                       0x00000000

// 0x80c0 (MAC_PCU_XRMODE)
#define MAC_PCU_XRMODE_FRAME_HOLD_MSB                                31
#define MAC_PCU_XRMODE_FRAME_HOLD_LSB                                20
#define MAC_PCU_XRMODE_FRAME_HOLD_MASK                               0xfff00000
#define MAC_PCU_XRMODE_FRAME_HOLD_GET(x)                             (((x) & MAC_PCU_XRMODE_FRAME_HOLD_MASK) >> MAC_PCU_XRMODE_FRAME_HOLD_LSB)
#define MAC_PCU_XRMODE_FRAME_HOLD_SET(x)                             (((0 | (x)) << MAC_PCU_XRMODE_FRAME_HOLD_LSB) & MAC_PCU_XRMODE_FRAME_HOLD_MASK)
#define MAC_PCU_XRMODE_FRAME_HOLD_RESET                              680
#define MAC_PCU_XRMODE_WAIT_FOR_POLL_MSB                             7
#define MAC_PCU_XRMODE_WAIT_FOR_POLL_LSB                             7
#define MAC_PCU_XRMODE_WAIT_FOR_POLL_MASK                            0x00000080
#define MAC_PCU_XRMODE_WAIT_FOR_POLL_GET(x)                          (((x) & MAC_PCU_XRMODE_WAIT_FOR_POLL_MASK) >> MAC_PCU_XRMODE_WAIT_FOR_POLL_LSB)
#define MAC_PCU_XRMODE_WAIT_FOR_POLL_SET(x)                          (((0 | (x)) << MAC_PCU_XRMODE_WAIT_FOR_POLL_LSB) & MAC_PCU_XRMODE_WAIT_FOR_POLL_MASK)
#define MAC_PCU_XRMODE_WAIT_FOR_POLL_RESET                           0
#define MAC_PCU_XRMODE_POLL_TYPE_MSB                                 5
#define MAC_PCU_XRMODE_POLL_TYPE_LSB                                 0
#define MAC_PCU_XRMODE_POLL_TYPE_MASK                                0x0000003f
#define MAC_PCU_XRMODE_POLL_TYPE_GET(x)                              (((x) & MAC_PCU_XRMODE_POLL_TYPE_MASK) >> MAC_PCU_XRMODE_POLL_TYPE_LSB)
#define MAC_PCU_XRMODE_POLL_TYPE_SET(x)                              (((0 | (x)) << MAC_PCU_XRMODE_POLL_TYPE_LSB) & MAC_PCU_XRMODE_POLL_TYPE_MASK)
#define MAC_PCU_XRMODE_POLL_TYPE_RESET                               0
#define MAC_PCU_XRMODE_ADDRESS                                       0x80c0
#define MAC_PCU_XRMODE_HW_MASK                                       0xfff000bf
#define MAC_PCU_XRMODE_SW_MASK                                       0xfff000bf
#define MAC_PCU_XRMODE_HW_WRITE_MASK                                 0x00000000
#define MAC_PCU_XRMODE_SW_WRITE_MASK                                 0xfff000bf
#define MAC_PCU_XRMODE_RSTMASK                                       0xffffffff
#define MAC_PCU_XRMODE_RESET                                         0x2a800000

// 0x80c4 (MAC_PCU_XRDEL)
#define MAC_PCU_XRDEL_CHIRP_DATA_DELAY_MSB                           31
#define MAC_PCU_XRDEL_CHIRP_DATA_DELAY_LSB                           16
#define MAC_PCU_XRDEL_CHIRP_DATA_DELAY_MASK                          0xffff0000
#define MAC_PCU_XRDEL_CHIRP_DATA_DELAY_GET(x)                        (((x) & MAC_PCU_XRDEL_CHIRP_DATA_DELAY_MASK) >> MAC_PCU_XRDEL_CHIRP_DATA_DELAY_LSB)
#define MAC_PCU_XRDEL_CHIRP_DATA_DELAY_SET(x)                        (((0 | (x)) << MAC_PCU_XRDEL_CHIRP_DATA_DELAY_LSB) & MAC_PCU_XRDEL_CHIRP_DATA_DELAY_MASK)
#define MAC_PCU_XRDEL_CHIRP_DATA_DELAY_RESET                         1680
#define MAC_PCU_XRDEL_SLOT_DELAY_MSB                                 15
#define MAC_PCU_XRDEL_SLOT_DELAY_LSB                                 0
#define MAC_PCU_XRDEL_SLOT_DELAY_MASK                                0x0000ffff
#define MAC_PCU_XRDEL_SLOT_DELAY_GET(x)                              (((x) & MAC_PCU_XRDEL_SLOT_DELAY_MASK) >> MAC_PCU_XRDEL_SLOT_DELAY_LSB)
#define MAC_PCU_XRDEL_SLOT_DELAY_SET(x)                              (((0 | (x)) << MAC_PCU_XRDEL_SLOT_DELAY_LSB) & MAC_PCU_XRDEL_SLOT_DELAY_MASK)
#define MAC_PCU_XRDEL_SLOT_DELAY_RESET                               360
#define MAC_PCU_XRDEL_ADDRESS                                        0x80c4
#define MAC_PCU_XRDEL_HW_MASK                                        0xffffffff
#define MAC_PCU_XRDEL_SW_MASK                                        0xffffffff
#define MAC_PCU_XRDEL_HW_WRITE_MASK                                  0x00000000
#define MAC_PCU_XRDEL_SW_WRITE_MASK                                  0xffffffff
#define MAC_PCU_XRDEL_RSTMASK                                        0xffffffff
#define MAC_PCU_XRDEL_RESET                                          0x06900168

// 0x80c8 (MAC_PCU_XRTO)
#define MAC_PCU_XRTO_POLL_TIMEOUT_MSB                                31
#define MAC_PCU_XRTO_POLL_TIMEOUT_LSB                                16
#define MAC_PCU_XRTO_POLL_TIMEOUT_MASK                               0xffff0000
#define MAC_PCU_XRTO_POLL_TIMEOUT_GET(x)                             (((x) & MAC_PCU_XRTO_POLL_TIMEOUT_MASK) >> MAC_PCU_XRTO_POLL_TIMEOUT_LSB)
#define MAC_PCU_XRTO_POLL_TIMEOUT_SET(x)                             (((0 | (x)) << MAC_PCU_XRTO_POLL_TIMEOUT_LSB) & MAC_PCU_XRTO_POLL_TIMEOUT_MASK)
#define MAC_PCU_XRTO_POLL_TIMEOUT_RESET                              5000
#define MAC_PCU_XRTO_CHIRP_TIMEOUT_MSB                               15
#define MAC_PCU_XRTO_CHIRP_TIMEOUT_LSB                               0
#define MAC_PCU_XRTO_CHIRP_TIMEOUT_MASK                              0x0000ffff
#define MAC_PCU_XRTO_CHIRP_TIMEOUT_GET(x)                            (((x) & MAC_PCU_XRTO_CHIRP_TIMEOUT_MASK) >> MAC_PCU_XRTO_CHIRP_TIMEOUT_LSB)
#define MAC_PCU_XRTO_CHIRP_TIMEOUT_SET(x)                            (((0 | (x)) << MAC_PCU_XRTO_CHIRP_TIMEOUT_LSB) & MAC_PCU_XRTO_CHIRP_TIMEOUT_MASK)
#define MAC_PCU_XRTO_CHIRP_TIMEOUT_RESET                             7200
#define MAC_PCU_XRTO_ADDRESS                                         0x80c8
#define MAC_PCU_XRTO_HW_MASK                                         0xffffffff
#define MAC_PCU_XRTO_SW_MASK                                         0xffffffff
#define MAC_PCU_XRTO_HW_WRITE_MASK                                   0x00000000
#define MAC_PCU_XRTO_SW_WRITE_MASK                                   0xffffffff
#define MAC_PCU_XRTO_RSTMASK                                         0xffffffff
#define MAC_PCU_XRTO_RESET                                           0x13881c20

// 0x80cc (MAC_PCU_XRCRP)
#define MAC_PCU_XRCRP_CHIRP_GAP_MSB                                  31
#define MAC_PCU_XRCRP_CHIRP_GAP_LSB                                  16
#define MAC_PCU_XRCRP_CHIRP_GAP_MASK                                 0xffff0000
#define MAC_PCU_XRCRP_CHIRP_GAP_GET(x)                               (((x) & MAC_PCU_XRCRP_CHIRP_GAP_MASK) >> MAC_PCU_XRCRP_CHIRP_GAP_LSB)
#define MAC_PCU_XRCRP_CHIRP_GAP_SET(x)                               (((0 | (x)) << MAC_PCU_XRCRP_CHIRP_GAP_LSB) & MAC_PCU_XRCRP_CHIRP_GAP_MASK)
#define MAC_PCU_XRCRP_CHIRP_GAP_RESET                                500
#define MAC_PCU_XRCRP_SEND_CHIRP_MSB                                 0
#define MAC_PCU_XRCRP_SEND_CHIRP_LSB                                 0
#define MAC_PCU_XRCRP_SEND_CHIRP_MASK                                0x00000001
#define MAC_PCU_XRCRP_SEND_CHIRP_GET(x)                              (((x) & MAC_PCU_XRCRP_SEND_CHIRP_MASK) >> MAC_PCU_XRCRP_SEND_CHIRP_LSB)
#define MAC_PCU_XRCRP_SEND_CHIRP_SET(x)                              (((0 | (x)) << MAC_PCU_XRCRP_SEND_CHIRP_LSB) & MAC_PCU_XRCRP_SEND_CHIRP_MASK)
#define MAC_PCU_XRCRP_SEND_CHIRP_RESET                               0
#define MAC_PCU_XRCRP_ADDRESS                                        0x80cc
#define MAC_PCU_XRCRP_HW_MASK                                        0xffff0001
#define MAC_PCU_XRCRP_SW_MASK                                        0xffff0001
#define MAC_PCU_XRCRP_HW_WRITE_MASK                                  0x00000001
#define MAC_PCU_XRCRP_SW_WRITE_MASK                                  0xffff0001
#define MAC_PCU_XRCRP_RSTMASK                                        0xffffffff
#define MAC_PCU_XRCRP_RESET                                          0x01f40000

// 0x80d0 (MAC_PCU_XRSTMP)
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_THRESH_MSB                      23
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_THRESH_LSB                      16
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_THRESH_MASK                     0x00ff0000
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_THRESH_GET(x)                   (((x) & MAC_PCU_XRSTMP_RX_ABORT_RSSI_THRESH_MASK) >> MAC_PCU_XRSTMP_RX_ABORT_RSSI_THRESH_LSB)
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_THRESH_SET(x)                   (((0 | (x)) << MAC_PCU_XRSTMP_RX_ABORT_RSSI_THRESH_LSB) & MAC_PCU_XRSTMP_RX_ABORT_RSSI_THRESH_MASK)
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_THRESH_RESET                    37
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_THRESH_MSB                      15
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_THRESH_LSB                      8
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_THRESH_MASK                     0x0000ff00
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_THRESH_GET(x)                   (((x) & MAC_PCU_XRSTMP_TX_STOMP_RSSI_THRESH_MASK) >> MAC_PCU_XRSTMP_TX_STOMP_RSSI_THRESH_LSB)
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_THRESH_SET(x)                   (((0 | (x)) << MAC_PCU_XRSTMP_TX_STOMP_RSSI_THRESH_LSB) & MAC_PCU_XRSTMP_TX_STOMP_RSSI_THRESH_MASK)
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_THRESH_RESET                    37
#define MAC_PCU_XRSTMP_RX_ABORT_DATA_MSB                             5
#define MAC_PCU_XRSTMP_RX_ABORT_DATA_LSB                             5
#define MAC_PCU_XRSTMP_RX_ABORT_DATA_MASK                            0x00000020
#define MAC_PCU_XRSTMP_RX_ABORT_DATA_GET(x)                          (((x) & MAC_PCU_XRSTMP_RX_ABORT_DATA_MASK) >> MAC_PCU_XRSTMP_RX_ABORT_DATA_LSB)
#define MAC_PCU_XRSTMP_RX_ABORT_DATA_SET(x)                          (((0 | (x)) << MAC_PCU_XRSTMP_RX_ABORT_DATA_LSB) & MAC_PCU_XRSTMP_RX_ABORT_DATA_MASK)
#define MAC_PCU_XRSTMP_RX_ABORT_DATA_RESET                           0
#define MAC_PCU_XRSTMP_TX_STOMP_DATA_MSB                             4
#define MAC_PCU_XRSTMP_TX_STOMP_DATA_LSB                             4
#define MAC_PCU_XRSTMP_TX_STOMP_DATA_MASK                            0x00000010
#define MAC_PCU_XRSTMP_TX_STOMP_DATA_GET(x)                          (((x) & MAC_PCU_XRSTMP_TX_STOMP_DATA_MASK) >> MAC_PCU_XRSTMP_TX_STOMP_DATA_LSB)
#define MAC_PCU_XRSTMP_TX_STOMP_DATA_SET(x)                          (((0 | (x)) << MAC_PCU_XRSTMP_TX_STOMP_DATA_LSB) & MAC_PCU_XRSTMP_TX_STOMP_DATA_MASK)
#define MAC_PCU_XRSTMP_TX_STOMP_DATA_RESET                           0
#define MAC_PCU_XRSTMP_TX_STOMP_BSSID_MSB                            3
#define MAC_PCU_XRSTMP_TX_STOMP_BSSID_LSB                            3
#define MAC_PCU_XRSTMP_TX_STOMP_BSSID_MASK                           0x00000008
#define MAC_PCU_XRSTMP_TX_STOMP_BSSID_GET(x)                         (((x) & MAC_PCU_XRSTMP_TX_STOMP_BSSID_MASK) >> MAC_PCU_XRSTMP_TX_STOMP_BSSID_LSB)
#define MAC_PCU_XRSTMP_TX_STOMP_BSSID_SET(x)                         (((0 | (x)) << MAC_PCU_XRSTMP_TX_STOMP_BSSID_LSB) & MAC_PCU_XRSTMP_TX_STOMP_BSSID_MASK)
#define MAC_PCU_XRSTMP_TX_STOMP_BSSID_RESET                          0
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_MSB                             2
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_LSB                             2
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_MASK                            0x00000004
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_GET(x)                          (((x) & MAC_PCU_XRSTMP_TX_STOMP_RSSI_MASK) >> MAC_PCU_XRSTMP_TX_STOMP_RSSI_LSB)
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_SET(x)                          (((0 | (x)) << MAC_PCU_XRSTMP_TX_STOMP_RSSI_LSB) & MAC_PCU_XRSTMP_TX_STOMP_RSSI_MASK)
#define MAC_PCU_XRSTMP_TX_STOMP_RSSI_RESET                           0
#define MAC_PCU_XRSTMP_RX_ABORT_BSSID_MSB                            1
#define MAC_PCU_XRSTMP_RX_ABORT_BSSID_LSB                            1
#define MAC_PCU_XRSTMP_RX_ABORT_BSSID_MASK                           0x00000002
#define MAC_PCU_XRSTMP_RX_ABORT_BSSID_GET(x)                         (((x) & MAC_PCU_XRSTMP_RX_ABORT_BSSID_MASK) >> MAC_PCU_XRSTMP_RX_ABORT_BSSID_LSB)
#define MAC_PCU_XRSTMP_RX_ABORT_BSSID_SET(x)                         (((0 | (x)) << MAC_PCU_XRSTMP_RX_ABORT_BSSID_LSB) & MAC_PCU_XRSTMP_RX_ABORT_BSSID_MASK)
#define MAC_PCU_XRSTMP_RX_ABORT_BSSID_RESET                          0
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_MSB                             0
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_LSB                             0
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_MASK                            0x00000001
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_GET(x)                          (((x) & MAC_PCU_XRSTMP_RX_ABORT_RSSI_MASK) >> MAC_PCU_XRSTMP_RX_ABORT_RSSI_LSB)
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_SET(x)                          (((0 | (x)) << MAC_PCU_XRSTMP_RX_ABORT_RSSI_LSB) & MAC_PCU_XRSTMP_RX_ABORT_RSSI_MASK)
#define MAC_PCU_XRSTMP_RX_ABORT_RSSI_RESET                           0
#define MAC_PCU_XRSTMP_ADDRESS                                       0x80d0
#define MAC_PCU_XRSTMP_HW_MASK                                       0x00ffff3f
#define MAC_PCU_XRSTMP_SW_MASK                                       0x00ffff3f
#define MAC_PCU_XRSTMP_HW_WRITE_MASK                                 0x00000000
#define MAC_PCU_XRSTMP_SW_WRITE_MASK                                 0x00ffff3f
#define MAC_PCU_XRSTMP_RSTMASK                                       0xffffffff
#define MAC_PCU_XRSTMP_RESET                                         0x00252500

// 0x80dc (MAC_PCU_SELF_GEN_DEFAULT)
#define MAC_PCU_SELF_GEN_DEFAULT_STAGGER_SOUNDING_MSB                5
#define MAC_PCU_SELF_GEN_DEFAULT_STAGGER_SOUNDING_LSB                5
#define MAC_PCU_SELF_GEN_DEFAULT_STAGGER_SOUNDING_MASK               0x00000020
#define MAC_PCU_SELF_GEN_DEFAULT_STAGGER_SOUNDING_GET(x)             (((x) & MAC_PCU_SELF_GEN_DEFAULT_STAGGER_SOUNDING_MASK) >> MAC_PCU_SELF_GEN_DEFAULT_STAGGER_SOUNDING_LSB)
#define MAC_PCU_SELF_GEN_DEFAULT_STAGGER_SOUNDING_SET(x)             (((0 | (x)) << MAC_PCU_SELF_GEN_DEFAULT_STAGGER_SOUNDING_LSB) & MAC_PCU_SELF_GEN_DEFAULT_STAGGER_SOUNDING_MASK)
#define MAC_PCU_SELF_GEN_DEFAULT_STAGGER_SOUNDING_RESET              0
#define MAC_PCU_SELF_GEN_DEFAULT_CEC_MSB                             4
#define MAC_PCU_SELF_GEN_DEFAULT_CEC_LSB                             3
#define MAC_PCU_SELF_GEN_DEFAULT_CEC_MASK                            0x00000018
#define MAC_PCU_SELF_GEN_DEFAULT_CEC_GET(x)                          (((x) & MAC_PCU_SELF_GEN_DEFAULT_CEC_MASK) >> MAC_PCU_SELF_GEN_DEFAULT_CEC_LSB)
#define MAC_PCU_SELF_GEN_DEFAULT_CEC_SET(x)                          (((0 | (x)) << MAC_PCU_SELF_GEN_DEFAULT_CEC_LSB) & MAC_PCU_SELF_GEN_DEFAULT_CEC_MASK)
#define MAC_PCU_SELF_GEN_DEFAULT_CEC_RESET                           0
#define MAC_PCU_SELF_GEN_DEFAULT_MMSS_MSB                            2
#define MAC_PCU_SELF_GEN_DEFAULT_MMSS_LSB                            0
#define MAC_PCU_SELF_GEN_DEFAULT_MMSS_MASK                           0x00000007
#define MAC_PCU_SELF_GEN_DEFAULT_MMSS_GET(x)                         (((x) & MAC_PCU_SELF_GEN_DEFAULT_MMSS_MASK) >> MAC_PCU_SELF_GEN_DEFAULT_MMSS_LSB)
#define MAC_PCU_SELF_GEN_DEFAULT_MMSS_SET(x)                         (((0 | (x)) << MAC_PCU_SELF_GEN_DEFAULT_MMSS_LSB) & MAC_PCU_SELF_GEN_DEFAULT_MMSS_MASK)
#define MAC_PCU_SELF_GEN_DEFAULT_MMSS_RESET                          0
#define MAC_PCU_SELF_GEN_DEFAULT_ADDRESS                             0x80dc
#define MAC_PCU_SELF_GEN_DEFAULT_HW_MASK                             0x0000003f
#define MAC_PCU_SELF_GEN_DEFAULT_SW_MASK                             0x0000003f
#define MAC_PCU_SELF_GEN_DEFAULT_HW_WRITE_MASK                       0x00000000
#define MAC_PCU_SELF_GEN_DEFAULT_SW_WRITE_MASK                       0x0000003f
#define MAC_PCU_SELF_GEN_DEFAULT_RSTMASK                             0xffffffff
#define MAC_PCU_SELF_GEN_DEFAULT_RESET                               0x00000000

// 0x80e0 (MAC_PCU_ADDR1_MASK_L32)
#define MAC_PCU_ADDR1_MASK_L32_VALUE_MSB                             31
#define MAC_PCU_ADDR1_MASK_L32_VALUE_LSB                             0
#define MAC_PCU_ADDR1_MASK_L32_VALUE_MASK                            0xffffffff
#define MAC_PCU_ADDR1_MASK_L32_VALUE_GET(x)                          (((x) & MAC_PCU_ADDR1_MASK_L32_VALUE_MASK) >> MAC_PCU_ADDR1_MASK_L32_VALUE_LSB)
#define MAC_PCU_ADDR1_MASK_L32_VALUE_SET(x)                          (((0 | (x)) << MAC_PCU_ADDR1_MASK_L32_VALUE_LSB) & MAC_PCU_ADDR1_MASK_L32_VALUE_MASK)
#define MAC_PCU_ADDR1_MASK_L32_VALUE_RESET                           4294967295
#define MAC_PCU_ADDR1_MASK_L32_ADDRESS                               0x80e0
#define MAC_PCU_ADDR1_MASK_L32_HW_MASK                               0xffffffff
#define MAC_PCU_ADDR1_MASK_L32_SW_MASK                               0xffffffff
#define MAC_PCU_ADDR1_MASK_L32_HW_WRITE_MASK                         0x00000000
#define MAC_PCU_ADDR1_MASK_L32_SW_WRITE_MASK                         0xffffffff
#define MAC_PCU_ADDR1_MASK_L32_RSTMASK                               0xffffffff
#define MAC_PCU_ADDR1_MASK_L32_RESET                                 0xffffffff

// 0x80e4 (MAC_PCU_ADDR1_MASK_U16)
#define MAC_PCU_ADDR1_MASK_U16_VALUE_MSB                             15
#define MAC_PCU_ADDR1_MASK_U16_VALUE_LSB                             0
#define MAC_PCU_ADDR1_MASK_U16_VALUE_MASK                            0x0000ffff
#define MAC_PCU_ADDR1_MASK_U16_VALUE_GET(x)                          (((x) & MAC_PCU_ADDR1_MASK_U16_VALUE_MASK) >> MAC_PCU_ADDR1_MASK_U16_VALUE_LSB)
#define MAC_PCU_ADDR1_MASK_U16_VALUE_SET(x)                          (((0 | (x)) << MAC_PCU_ADDR1_MASK_U16_VALUE_LSB) & MAC_PCU_ADDR1_MASK_U16_VALUE_MASK)
#define MAC_PCU_ADDR1_MASK_U16_VALUE_RESET                           65535
#define MAC_PCU_ADDR1_MASK_U16_ADDRESS                               0x80e4
#define MAC_PCU_ADDR1_MASK_U16_HW_MASK                               0x0000ffff
#define MAC_PCU_ADDR1_MASK_U16_SW_MASK                               0x0000ffff
#define MAC_PCU_ADDR1_MASK_U16_HW_WRITE_MASK                         0x00000000
#define MAC_PCU_ADDR1_MASK_U16_SW_WRITE_MASK                         0x0000ffff
#define MAC_PCU_ADDR1_MASK_U16_RSTMASK                               0xffffffff
#define MAC_PCU_ADDR1_MASK_U16_RESET                                 0x0000ffff

// 0x80e8 (MAC_PCU_TPC)
#define MAC_PCU_TPC_TXBF_FB_PWR_MSB                                  29
#define MAC_PCU_TPC_TXBF_FB_PWR_LSB                                  24
#define MAC_PCU_TPC_TXBF_FB_PWR_MASK                                 0x3f000000
#define MAC_PCU_TPC_TXBF_FB_PWR_GET(x)                               (((x) & MAC_PCU_TPC_TXBF_FB_PWR_MASK) >> MAC_PCU_TPC_TXBF_FB_PWR_LSB)
#define MAC_PCU_TPC_TXBF_FB_PWR_SET(x)                               (((0 | (x)) << MAC_PCU_TPC_TXBF_FB_PWR_LSB) & MAC_PCU_TPC_TXBF_FB_PWR_MASK)
#define MAC_PCU_TPC_TXBF_FB_PWR_RESET                                63
#define MAC_PCU_TPC_CHIRP_PWR_MSB                                    21
#define MAC_PCU_TPC_CHIRP_PWR_LSB                                    16
#define MAC_PCU_TPC_CHIRP_PWR_MASK                                   0x003f0000
#define MAC_PCU_TPC_CHIRP_PWR_GET(x)                                 (((x) & MAC_PCU_TPC_CHIRP_PWR_MASK) >> MAC_PCU_TPC_CHIRP_PWR_LSB)
#define MAC_PCU_TPC_CHIRP_PWR_SET(x)                                 (((0 | (x)) << MAC_PCU_TPC_CHIRP_PWR_LSB) & MAC_PCU_TPC_CHIRP_PWR_MASK)
#define MAC_PCU_TPC_CHIRP_PWR_RESET                                  63
#define MAC_PCU_TPC_CTS_ACK_PWR_OFDM_MSB                             13
#define MAC_PCU_TPC_CTS_ACK_PWR_OFDM_LSB                             8
#define MAC_PCU_TPC_CTS_ACK_PWR_OFDM_MASK                            0x00003f00
#define MAC_PCU_TPC_CTS_ACK_PWR_OFDM_GET(x)                          (((x) & MAC_PCU_TPC_CTS_ACK_PWR_OFDM_MASK) >> MAC_PCU_TPC_CTS_ACK_PWR_OFDM_LSB)
#define MAC_PCU_TPC_CTS_ACK_PWR_OFDM_SET(x)                          (((0 | (x)) << MAC_PCU_TPC_CTS_ACK_PWR_OFDM_LSB) & MAC_PCU_TPC_CTS_ACK_PWR_OFDM_MASK)
#define MAC_PCU_TPC_CTS_ACK_PWR_OFDM_RESET                           63
#define MAC_PCU_TPC_CTS_ACK_PWR_CCK_MSB                              5
#define MAC_PCU_TPC_CTS_ACK_PWR_CCK_LSB                              0
#define MAC_PCU_TPC_CTS_ACK_PWR_CCK_MASK                             0x0000003f
#define MAC_PCU_TPC_CTS_ACK_PWR_CCK_GET(x)                           (((x) & MAC_PCU_TPC_CTS_ACK_PWR_CCK_MASK) >> MAC_PCU_TPC_CTS_ACK_PWR_CCK_LSB)
#define MAC_PCU_TPC_CTS_ACK_PWR_CCK_SET(x)                           (((0 | (x)) << MAC_PCU_TPC_CTS_ACK_PWR_CCK_LSB) & MAC_PCU_TPC_CTS_ACK_PWR_CCK_MASK)
#define MAC_PCU_TPC_CTS_ACK_PWR_CCK_RESET                            63
#define MAC_PCU_TPC_ADDRESS                                          0x80e8
#define MAC_PCU_TPC_HW_MASK                                          0x3f3f3f3f
#define MAC_PCU_TPC_SW_MASK                                          0x3f3f3f3f
#define MAC_PCU_TPC_HW_WRITE_MASK                                    0x00000000
#define MAC_PCU_TPC_SW_WRITE_MASK                                    0x3f3f3f3f
#define MAC_PCU_TPC_RSTMASK                                          0xffffffff
#define MAC_PCU_TPC_RESET                                            0x3f3f3f3f

// 0x80ec (MAC_PCU_TX_FRAME_CNT)
#define MAC_PCU_TX_FRAME_CNT_VALUE_MSB                               31
#define MAC_PCU_TX_FRAME_CNT_VALUE_LSB                               0
#define MAC_PCU_TX_FRAME_CNT_VALUE_MASK                              0xffffffff
#define MAC_PCU_TX_FRAME_CNT_VALUE_GET(x)                            (((x) & MAC_PCU_TX_FRAME_CNT_VALUE_MASK) >> MAC_PCU_TX_FRAME_CNT_VALUE_LSB)
#define MAC_PCU_TX_FRAME_CNT_VALUE_SET(x)                            (((0 | (x)) << MAC_PCU_TX_FRAME_CNT_VALUE_LSB) & MAC_PCU_TX_FRAME_CNT_VALUE_MASK)
#define MAC_PCU_TX_FRAME_CNT_VALUE_RESET                             0
#define MAC_PCU_TX_FRAME_CNT_ADDRESS                                 0x80ec
#define MAC_PCU_TX_FRAME_CNT_HW_MASK                                 0xffffffff
#define MAC_PCU_TX_FRAME_CNT_SW_MASK                                 0xffffffff
#define MAC_PCU_TX_FRAME_CNT_HW_WRITE_MASK                           0xffffffff
#define MAC_PCU_TX_FRAME_CNT_SW_WRITE_MASK                           0xffffffff
#define MAC_PCU_TX_FRAME_CNT_RSTMASK                                 0xffffffff
#define MAC_PCU_TX_FRAME_CNT_RESET                                   0x00000000

// 0x80f0 (MAC_PCU_RX_FRAME_CNT)
#define MAC_PCU_RX_FRAME_CNT_VALUE_MSB                               31
#define MAC_PCU_RX_FRAME_CNT_VALUE_LSB                               0
#define MAC_PCU_RX_FRAME_CNT_VALUE_MASK                              0xffffffff
#define MAC_PCU_RX_FRAME_CNT_VALUE_GET(x)                            (((x) & MAC_PCU_RX_FRAME_CNT_VALUE_MASK) >> MAC_PCU_RX_FRAME_CNT_VALUE_LSB)
#define MAC_PCU_RX_FRAME_CNT_VALUE_SET(x)                            (((0 | (x)) << MAC_PCU_RX_FRAME_CNT_VALUE_LSB) & MAC_PCU_RX_FRAME_CNT_VALUE_MASK)
#define MAC_PCU_RX_FRAME_CNT_VALUE_RESET                             0
#define MAC_PCU_RX_FRAME_CNT_ADDRESS                                 0x80f0
#define MAC_PCU_RX_FRAME_CNT_HW_MASK                                 0xffffffff
#define MAC_PCU_RX_FRAME_CNT_SW_MASK                                 0xffffffff
#define MAC_PCU_RX_FRAME_CNT_HW_WRITE_MASK                           0xffffffff
#define MAC_PCU_RX_FRAME_CNT_SW_WRITE_MASK                           0xffffffff
#define MAC_PCU_RX_FRAME_CNT_RSTMASK                                 0xffffffff
#define MAC_PCU_RX_FRAME_CNT_RESET                                   0x00000000

// 0x80f4 (MAC_PCU_RX_CLEAR_CNT)
#define MAC_PCU_RX_CLEAR_CNT_VALUE_MSB                               31
#define MAC_PCU_RX_CLEAR_CNT_VALUE_LSB                               0
#define MAC_PCU_RX_CLEAR_CNT_VALUE_MASK                              0xffffffff
#define MAC_PCU_RX_CLEAR_CNT_VALUE_GET(x)                            (((x) & MAC_PCU_RX_CLEAR_CNT_VALUE_MASK) >> MAC_PCU_RX_CLEAR_CNT_VALUE_LSB)
#define MAC_PCU_RX_CLEAR_CNT_VALUE_SET(x)                            (((0 | (x)) << MAC_PCU_RX_CLEAR_CNT_VALUE_LSB) & MAC_PCU_RX_CLEAR_CNT_VALUE_MASK)
#define MAC_PCU_RX_CLEAR_CNT_VALUE_RESET                             0
#define MAC_PCU_RX_CLEAR_CNT_ADDRESS                                 0x80f4
#define MAC_PCU_RX_CLEAR_CNT_HW_MASK                                 0xffffffff
#define MAC_PCU_RX_CLEAR_CNT_SW_MASK                                 0xffffffff
#define MAC_PCU_RX_CLEAR_CNT_HW_WRITE_MASK                           0xffffffff
#define MAC_PCU_RX_CLEAR_CNT_SW_WRITE_MASK                           0xffffffff
#define MAC_PCU_RX_CLEAR_CNT_RSTMASK                                 0xffffffff
#define MAC_PCU_RX_CLEAR_CNT_RESET                                   0x00000000

// 0x80f8 (MAC_PCU_CYCLE_CNT)
#define MAC_PCU_CYCLE_CNT_VALUE_MSB                                  31
#define MAC_PCU_CYCLE_CNT_VALUE_LSB                                  0
#define MAC_PCU_CYCLE_CNT_VALUE_MASK                                 0xffffffff
#define MAC_PCU_CYCLE_CNT_VALUE_GET(x)                               (((x) & MAC_PCU_CYCLE_CNT_VALUE_MASK) >> MAC_PCU_CYCLE_CNT_VALUE_LSB)
#define MAC_PCU_CYCLE_CNT_VALUE_SET(x)                               (((0 | (x)) << MAC_PCU_CYCLE_CNT_VALUE_LSB) & MAC_PCU_CYCLE_CNT_VALUE_MASK)
#define MAC_PCU_CYCLE_CNT_VALUE_RESET                                0
#define MAC_PCU_CYCLE_CNT_ADDRESS                                    0x80f8
#define MAC_PCU_CYCLE_CNT_HW_MASK                                    0xffffffff
#define MAC_PCU_CYCLE_CNT_SW_MASK                                    0xffffffff
#define MAC_PCU_CYCLE_CNT_HW_WRITE_MASK                              0xffffffff
#define MAC_PCU_CYCLE_CNT_SW_WRITE_MASK                              0xffffffff
#define MAC_PCU_CYCLE_CNT_RSTMASK                                    0xffffffff
#define MAC_PCU_CYCLE_CNT_RESET                                      0x00000000

// 0x80fc (MAC_PCU_QUIET_TIME_1)
#define MAC_PCU_QUIET_TIME_1_ACK_CTS_ENABLE_MSB                      17
#define MAC_PCU_QUIET_TIME_1_ACK_CTS_ENABLE_LSB                      17
#define MAC_PCU_QUIET_TIME_1_ACK_CTS_ENABLE_MASK                     0x00020000
#define MAC_PCU_QUIET_TIME_1_ACK_CTS_ENABLE_GET(x)                   (((x) & MAC_PCU_QUIET_TIME_1_ACK_CTS_ENABLE_MASK) >> MAC_PCU_QUIET_TIME_1_ACK_CTS_ENABLE_LSB)
#define MAC_PCU_QUIET_TIME_1_ACK_CTS_ENABLE_SET(x)                   (((0 | (x)) << MAC_PCU_QUIET_TIME_1_ACK_CTS_ENABLE_LSB) & MAC_PCU_QUIET_TIME_1_ACK_CTS_ENABLE_MASK)
#define MAC_PCU_QUIET_TIME_1_ACK_CTS_ENABLE_RESET                    1
#define MAC_PCU_QUIET_TIME_1_ADDRESS                                 0x80fc
#define MAC_PCU_QUIET_TIME_1_HW_MASK                                 0x00020000
#define MAC_PCU_QUIET_TIME_1_SW_MASK                                 0x00020000
#define MAC_PCU_QUIET_TIME_1_HW_WRITE_MASK                           0x00000000
#define MAC_PCU_QUIET_TIME_1_SW_WRITE_MASK                           0x00020000
#define MAC_PCU_QUIET_TIME_1_RSTMASK                                 0xffffffff
#define MAC_PCU_QUIET_TIME_1_RESET                                   0x00020000

// 0x8100 (MAC_PCU_QUIET_TIME_2)
#define MAC_PCU_QUIET_TIME_2_DURATION_MSB                            31
#define MAC_PCU_QUIET_TIME_2_DURATION_LSB                            16
#define MAC_PCU_QUIET_TIME_2_DURATION_MASK                           0xffff0000
#define MAC_PCU_QUIET_TIME_2_DURATION_GET(x)                         (((x) & MAC_PCU_QUIET_TIME_2_DURATION_MASK) >> MAC_PCU_QUIET_TIME_2_DURATION_LSB)
#define MAC_PCU_QUIET_TIME_2_DURATION_SET(x)                         (((0 | (x)) << MAC_PCU_QUIET_TIME_2_DURATION_LSB) & MAC_PCU_QUIET_TIME_2_DURATION_MASK)
#define MAC_PCU_QUIET_TIME_2_DURATION_RESET                          0
#define MAC_PCU_QUIET_TIME_2_DURATION2_MSB                           15
#define MAC_PCU_QUIET_TIME_2_DURATION2_LSB                           0
#define MAC_PCU_QUIET_TIME_2_DURATION2_MASK                          0x0000ffff
#define MAC_PCU_QUIET_TIME_2_DURATION2_GET(x)                        (((x) & MAC_PCU_QUIET_TIME_2_DURATION2_MASK) >> MAC_PCU_QUIET_TIME_2_DURATION2_LSB)
#define MAC_PCU_QUIET_TIME_2_DURATION2_SET(x)                        (((0 | (x)) << MAC_PCU_QUIET_TIME_2_DURATION2_LSB) & MAC_PCU_QUIET_TIME_2_DURATION2_MASK)
#define MAC_PCU_QUIET_TIME_2_DURATION2_RESET                         0
#define MAC_PCU_QUIET_TIME_2_ADDRESS                                 0x8100
#define MAC_PCU_QUIET_TIME_2_HW_MASK                                 0xffffffff
#define MAC_PCU_QUIET_TIME_2_SW_MASK                                 0xffffffff
#define MAC_PCU_QUIET_TIME_2_HW_WRITE_MASK                           0x00000000
#define MAC_PCU_QUIET_TIME_2_SW_WRITE_MASK                           0xffffffff
#define MAC_PCU_QUIET_TIME_2_RSTMASK                                 0xffffffff
#define MAC_PCU_QUIET_TIME_2_RESET                                   0x00000000

// 0x8108 (MAC_PCU_QOS_NO_ACK)
#define MAC_PCU_QOS_NO_ACK_BYTE_OFFSET_MSB                           8
#define MAC_PCU_QOS_NO_ACK_BYTE_OFFSET_LSB                           7
#define MAC_PCU_QOS_NO_ACK_BYTE_OFFSET_MASK                          0x00000180
#define MAC_PCU_QOS_NO_ACK_BYTE_OFFSET_GET(x)                        (((x) & MAC_PCU_QOS_NO_ACK_BYTE_OFFSET_MASK) >> MAC_PCU_QOS_NO_ACK_BYTE_OFFSET_LSB)
#define MAC_PCU_QOS_NO_ACK_BYTE_OFFSET_SET(x)                        (((0 | (x)) << MAC_PCU_QOS_NO_ACK_BYTE_OFFSET_LSB) & MAC_PCU_QOS_NO_ACK_BYTE_OFFSET_MASK)
#define MAC_PCU_QOS_NO_ACK_BYTE_OFFSET_RESET                         0
#define MAC_PCU_QOS_NO_ACK_BIT_OFFSET_MSB                            6
#define MAC_PCU_QOS_NO_ACK_BIT_OFFSET_LSB                            4
#define MAC_PCU_QOS_NO_ACK_BIT_OFFSET_MASK                           0x00000070
#define MAC_PCU_QOS_NO_ACK_BIT_OFFSET_GET(x)                         (((x) & MAC_PCU_QOS_NO_ACK_BIT_OFFSET_MASK) >> MAC_PCU_QOS_NO_ACK_BIT_OFFSET_LSB)
#define MAC_PCU_QOS_NO_ACK_BIT_OFFSET_SET(x)                         (((0 | (x)) << MAC_PCU_QOS_NO_ACK_BIT_OFFSET_LSB) & MAC_PCU_QOS_NO_ACK_BIT_OFFSET_MASK)
#define MAC_PCU_QOS_NO_ACK_BIT_OFFSET_RESET                          5
#define MAC_PCU_QOS_NO_ACK_TWO_BIT_VALUES_MSB                        3
#define MAC_PCU_QOS_NO_ACK_TWO_BIT_VALUES_LSB                        0
#define MAC_PCU_QOS_NO_ACK_TWO_BIT_VALUES_MASK                       0x0000000f
#define MAC_PCU_QOS_NO_ACK_TWO_BIT_VALUES_GET(x)                     (((x) & MAC_PCU_QOS_NO_ACK_TWO_BIT_VALUES_MASK) >> MAC_PCU_QOS_NO_ACK_TWO_BIT_VALUES_LSB)
#define MAC_PCU_QOS_NO_ACK_TWO_BIT_VALUES_SET(x)                     (((0 | (x)) << MAC_PCU_QOS_NO_ACK_TWO_BIT_VALUES_LSB) & MAC_PCU_QOS_NO_ACK_TWO_BIT_VALUES_MASK)
#define MAC_PCU_QOS_NO_ACK_TWO_BIT_VALUES_RESET                      2
#define MAC_PCU_QOS_NO_ACK_ADDRESS                                   0x8108
#define MAC_PCU_QOS_NO_ACK_HW_MASK                                   0x000001ff
#define MAC_PCU_QOS_NO_ACK_SW_MASK                                   0x000001ff
#define MAC_PCU_QOS_NO_ACK_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_QOS_NO_ACK_SW_WRITE_MASK                             0x000001ff
#define MAC_PCU_QOS_NO_ACK_RSTMASK                                   0xffffffff
#define MAC_PCU_QOS_NO_ACK_RESET                                     0x00000052

// 0x810c (MAC_PCU_PHY_ERROR_MASK)
#define MAC_PCU_PHY_ERROR_MASK_VALUE_MSB                             31
#define MAC_PCU_PHY_ERROR_MASK_VALUE_LSB                             0
#define MAC_PCU_PHY_ERROR_MASK_VALUE_MASK                            0xffffffff
#define MAC_PCU_PHY_ERROR_MASK_VALUE_GET(x)                          (((x) & MAC_PCU_PHY_ERROR_MASK_VALUE_MASK) >> MAC_PCU_PHY_ERROR_MASK_VALUE_LSB)
#define MAC_PCU_PHY_ERROR_MASK_VALUE_SET(x)                          (((0 | (x)) << MAC_PCU_PHY_ERROR_MASK_VALUE_LSB) & MAC_PCU_PHY_ERROR_MASK_VALUE_MASK)
#define MAC_PCU_PHY_ERROR_MASK_VALUE_RESET                           0
#define MAC_PCU_PHY_ERROR_MASK_ADDRESS                               0x810c
#define MAC_PCU_PHY_ERROR_MASK_HW_MASK                               0xffffffff
#define MAC_PCU_PHY_ERROR_MASK_SW_MASK                               0xffffffff
#define MAC_PCU_PHY_ERROR_MASK_HW_WRITE_MASK                         0x00000000
#define MAC_PCU_PHY_ERROR_MASK_SW_WRITE_MASK                         0xffffffff
#define MAC_PCU_PHY_ERROR_MASK_RSTMASK                               0xffffffff
#define MAC_PCU_PHY_ERROR_MASK_RESET                                 0x00000000

// 0x8110 (MAC_PCU_XRLAT)
#define MAC_PCU_XRLAT_VALUE_MSB                                      11
#define MAC_PCU_XRLAT_VALUE_LSB                                      0
#define MAC_PCU_XRLAT_VALUE_MASK                                     0x00000fff
#define MAC_PCU_XRLAT_VALUE_GET(x)                                   (((x) & MAC_PCU_XRLAT_VALUE_MASK) >> MAC_PCU_XRLAT_VALUE_LSB)
#define MAC_PCU_XRLAT_VALUE_SET(x)                                   (((0 | (x)) << MAC_PCU_XRLAT_VALUE_LSB) & MAC_PCU_XRLAT_VALUE_MASK)
#define MAC_PCU_XRLAT_VALUE_RESET                                    0
#define MAC_PCU_XRLAT_ADDRESS                                        0x8110
#define MAC_PCU_XRLAT_HW_MASK                                        0x00000fff
#define MAC_PCU_XRLAT_SW_MASK                                        0x00000fff
#define MAC_PCU_XRLAT_HW_WRITE_MASK                                  0x00000000
#define MAC_PCU_XRLAT_SW_WRITE_MASK                                  0x00000fff
#define MAC_PCU_XRLAT_RSTMASK                                        0xffffffff
#define MAC_PCU_XRLAT_RESET                                          0x00000000

// 0x8114 (MAC_PCU_RXBUF)
#define MAC_PCU_RXBUF_REG_RD_ENABLE_MSB                              11
#define MAC_PCU_RXBUF_REG_RD_ENABLE_LSB                              11
#define MAC_PCU_RXBUF_REG_RD_ENABLE_MASK                             0x00000800
#define MAC_PCU_RXBUF_REG_RD_ENABLE_GET(x)                           (((x) & MAC_PCU_RXBUF_REG_RD_ENABLE_MASK) >> MAC_PCU_RXBUF_REG_RD_ENABLE_LSB)
#define MAC_PCU_RXBUF_REG_RD_ENABLE_SET(x)                           (((0 | (x)) << MAC_PCU_RXBUF_REG_RD_ENABLE_LSB) & MAC_PCU_RXBUF_REG_RD_ENABLE_MASK)
#define MAC_PCU_RXBUF_REG_RD_ENABLE_RESET                            0
#define MAC_PCU_RXBUF_HIGH_PRIORITY_THRSHD_MSB                       10
#define MAC_PCU_RXBUF_HIGH_PRIORITY_THRSHD_LSB                       0
#define MAC_PCU_RXBUF_HIGH_PRIORITY_THRSHD_MASK                      0x000007ff
#define MAC_PCU_RXBUF_HIGH_PRIORITY_THRSHD_GET(x)                    (((x) & MAC_PCU_RXBUF_HIGH_PRIORITY_THRSHD_MASK) >> MAC_PCU_RXBUF_HIGH_PRIORITY_THRSHD_LSB)
#define MAC_PCU_RXBUF_HIGH_PRIORITY_THRSHD_SET(x)                    (((0 | (x)) << MAC_PCU_RXBUF_HIGH_PRIORITY_THRSHD_LSB) & MAC_PCU_RXBUF_HIGH_PRIORITY_THRSHD_MASK)
#define MAC_PCU_RXBUF_HIGH_PRIORITY_THRSHD_RESET                     2047
#define MAC_PCU_RXBUF_ADDRESS                                        0x8114
#define MAC_PCU_RXBUF_HW_MASK                                        0x00000fff
#define MAC_PCU_RXBUF_SW_MASK                                        0x00000fff
#define MAC_PCU_RXBUF_HW_WRITE_MASK                                  0x00000000
#define MAC_PCU_RXBUF_SW_WRITE_MASK                                  0x00000fff
#define MAC_PCU_RXBUF_RSTMASK                                        0xffffffff
#define MAC_PCU_RXBUF_RESET                                          0x000007ff

// 0x8118 (MAC_PCU_MIC_QOS_CONTROL)
#define MAC_PCU_MIC_QOS_CONTROL_ENABLE_MSB                           16
#define MAC_PCU_MIC_QOS_CONTROL_ENABLE_LSB                           16
#define MAC_PCU_MIC_QOS_CONTROL_ENABLE_MASK                          0x00010000
#define MAC_PCU_MIC_QOS_CONTROL_ENABLE_GET(x)                        (((x) & MAC_PCU_MIC_QOS_CONTROL_ENABLE_MASK) >> MAC_PCU_MIC_QOS_CONTROL_ENABLE_LSB)
#define MAC_PCU_MIC_QOS_CONTROL_ENABLE_SET(x)                        (((0 | (x)) << MAC_PCU_MIC_QOS_CONTROL_ENABLE_LSB) & MAC_PCU_MIC_QOS_CONTROL_ENABLE_MASK)
#define MAC_PCU_MIC_QOS_CONTROL_ENABLE_RESET                         0
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_7_MSB                          15
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_7_LSB                          14
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_7_MASK                         0x0000c000
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_7_GET(x)                       (((x) & MAC_PCU_MIC_QOS_CONTROL_VALUE_7_MASK) >> MAC_PCU_MIC_QOS_CONTROL_VALUE_7_LSB)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_7_SET(x)                       (((0 | (x)) << MAC_PCU_MIC_QOS_CONTROL_VALUE_7_LSB) & MAC_PCU_MIC_QOS_CONTROL_VALUE_7_MASK)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_7_RESET                        0
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_6_MSB                          13
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_6_LSB                          12
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_6_MASK                         0x00003000
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_6_GET(x)                       (((x) & MAC_PCU_MIC_QOS_CONTROL_VALUE_6_MASK) >> MAC_PCU_MIC_QOS_CONTROL_VALUE_6_LSB)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_6_SET(x)                       (((0 | (x)) << MAC_PCU_MIC_QOS_CONTROL_VALUE_6_LSB) & MAC_PCU_MIC_QOS_CONTROL_VALUE_6_MASK)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_6_RESET                        0
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_5_MSB                          11
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_5_LSB                          10
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_5_MASK                         0x00000c00
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_5_GET(x)                       (((x) & MAC_PCU_MIC_QOS_CONTROL_VALUE_5_MASK) >> MAC_PCU_MIC_QOS_CONTROL_VALUE_5_LSB)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_5_SET(x)                       (((0 | (x)) << MAC_PCU_MIC_QOS_CONTROL_VALUE_5_LSB) & MAC_PCU_MIC_QOS_CONTROL_VALUE_5_MASK)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_5_RESET                        0
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_4_MSB                          9
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_4_LSB                          8
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_4_MASK                         0x00000300
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_4_GET(x)                       (((x) & MAC_PCU_MIC_QOS_CONTROL_VALUE_4_MASK) >> MAC_PCU_MIC_QOS_CONTROL_VALUE_4_LSB)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_4_SET(x)                       (((0 | (x)) << MAC_PCU_MIC_QOS_CONTROL_VALUE_4_LSB) & MAC_PCU_MIC_QOS_CONTROL_VALUE_4_MASK)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_4_RESET                        0
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_3_MSB                          7
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_3_LSB                          6
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_3_MASK                         0x000000c0
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_3_GET(x)                       (((x) & MAC_PCU_MIC_QOS_CONTROL_VALUE_3_MASK) >> MAC_PCU_MIC_QOS_CONTROL_VALUE_3_LSB)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_3_SET(x)                       (((0 | (x)) << MAC_PCU_MIC_QOS_CONTROL_VALUE_3_LSB) & MAC_PCU_MIC_QOS_CONTROL_VALUE_3_MASK)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_3_RESET                        2
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_2_MSB                          5
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_2_LSB                          4
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_2_MASK                         0x00000030
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_2_GET(x)                       (((x) & MAC_PCU_MIC_QOS_CONTROL_VALUE_2_MASK) >> MAC_PCU_MIC_QOS_CONTROL_VALUE_2_LSB)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_2_SET(x)                       (((0 | (x)) << MAC_PCU_MIC_QOS_CONTROL_VALUE_2_LSB) & MAC_PCU_MIC_QOS_CONTROL_VALUE_2_MASK)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_2_RESET                        2
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_1_MSB                          3
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_1_LSB                          2
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_1_MASK                         0x0000000c
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_1_GET(x)                       (((x) & MAC_PCU_MIC_QOS_CONTROL_VALUE_1_MASK) >> MAC_PCU_MIC_QOS_CONTROL_VALUE_1_LSB)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_1_SET(x)                       (((0 | (x)) << MAC_PCU_MIC_QOS_CONTROL_VALUE_1_LSB) & MAC_PCU_MIC_QOS_CONTROL_VALUE_1_MASK)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_1_RESET                        2
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_0_MSB                          1
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_0_LSB                          0
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_0_MASK                         0x00000003
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_0_GET(x)                       (((x) & MAC_PCU_MIC_QOS_CONTROL_VALUE_0_MASK) >> MAC_PCU_MIC_QOS_CONTROL_VALUE_0_LSB)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_0_SET(x)                       (((0 | (x)) << MAC_PCU_MIC_QOS_CONTROL_VALUE_0_LSB) & MAC_PCU_MIC_QOS_CONTROL_VALUE_0_MASK)
#define MAC_PCU_MIC_QOS_CONTROL_VALUE_0_RESET                        2
#define MAC_PCU_MIC_QOS_CONTROL_ADDRESS                              0x8118
#define MAC_PCU_MIC_QOS_CONTROL_HW_MASK                              0x0001ffff
#define MAC_PCU_MIC_QOS_CONTROL_SW_MASK                              0x0001ffff
#define MAC_PCU_MIC_QOS_CONTROL_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_MIC_QOS_CONTROL_SW_WRITE_MASK                        0x0001ffff
#define MAC_PCU_MIC_QOS_CONTROL_RSTMASK                              0xffffffff
#define MAC_PCU_MIC_QOS_CONTROL_RESET                                0x000000aa

// 0x811c (MAC_PCU_MIC_QOS_SELECT)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_7_MSB                           31
#define MAC_PCU_MIC_QOS_SELECT_VALUE_7_LSB                           28
#define MAC_PCU_MIC_QOS_SELECT_VALUE_7_MASK                          0xf0000000
#define MAC_PCU_MIC_QOS_SELECT_VALUE_7_GET(x)                        (((x) & MAC_PCU_MIC_QOS_SELECT_VALUE_7_MASK) >> MAC_PCU_MIC_QOS_SELECT_VALUE_7_LSB)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_7_SET(x)                        (((0 | (x)) << MAC_PCU_MIC_QOS_SELECT_VALUE_7_LSB) & MAC_PCU_MIC_QOS_SELECT_VALUE_7_MASK)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_7_RESET                         0
#define MAC_PCU_MIC_QOS_SELECT_VALUE_6_MSB                           27
#define MAC_PCU_MIC_QOS_SELECT_VALUE_6_LSB                           24
#define MAC_PCU_MIC_QOS_SELECT_VALUE_6_MASK                          0x0f000000
#define MAC_PCU_MIC_QOS_SELECT_VALUE_6_GET(x)                        (((x) & MAC_PCU_MIC_QOS_SELECT_VALUE_6_MASK) >> MAC_PCU_MIC_QOS_SELECT_VALUE_6_LSB)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_6_SET(x)                        (((0 | (x)) << MAC_PCU_MIC_QOS_SELECT_VALUE_6_LSB) & MAC_PCU_MIC_QOS_SELECT_VALUE_6_MASK)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_6_RESET                         0
#define MAC_PCU_MIC_QOS_SELECT_VALUE_5_MSB                           23
#define MAC_PCU_MIC_QOS_SELECT_VALUE_5_LSB                           20
#define MAC_PCU_MIC_QOS_SELECT_VALUE_5_MASK                          0x00f00000
#define MAC_PCU_MIC_QOS_SELECT_VALUE_5_GET(x)                        (((x) & MAC_PCU_MIC_QOS_SELECT_VALUE_5_MASK) >> MAC_PCU_MIC_QOS_SELECT_VALUE_5_LSB)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_5_SET(x)                        (((0 | (x)) << MAC_PCU_MIC_QOS_SELECT_VALUE_5_LSB) & MAC_PCU_MIC_QOS_SELECT_VALUE_5_MASK)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_5_RESET                         0
#define MAC_PCU_MIC_QOS_SELECT_VALUE_4_MSB                           19
#define MAC_PCU_MIC_QOS_SELECT_VALUE_4_LSB                           16
#define MAC_PCU_MIC_QOS_SELECT_VALUE_4_MASK                          0x000f0000
#define MAC_PCU_MIC_QOS_SELECT_VALUE_4_GET(x)                        (((x) & MAC_PCU_MIC_QOS_SELECT_VALUE_4_MASK) >> MAC_PCU_MIC_QOS_SELECT_VALUE_4_LSB)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_4_SET(x)                        (((0 | (x)) << MAC_PCU_MIC_QOS_SELECT_VALUE_4_LSB) & MAC_PCU_MIC_QOS_SELECT_VALUE_4_MASK)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_4_RESET                         0
#define MAC_PCU_MIC_QOS_SELECT_VALUE_3_MSB                           15
#define MAC_PCU_MIC_QOS_SELECT_VALUE_3_LSB                           12
#define MAC_PCU_MIC_QOS_SELECT_VALUE_3_MASK                          0x0000f000
#define MAC_PCU_MIC_QOS_SELECT_VALUE_3_GET(x)                        (((x) & MAC_PCU_MIC_QOS_SELECT_VALUE_3_MASK) >> MAC_PCU_MIC_QOS_SELECT_VALUE_3_LSB)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_3_SET(x)                        (((0 | (x)) << MAC_PCU_MIC_QOS_SELECT_VALUE_3_LSB) & MAC_PCU_MIC_QOS_SELECT_VALUE_3_MASK)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_3_RESET                         3
#define MAC_PCU_MIC_QOS_SELECT_VALUE_2_MSB                           11
#define MAC_PCU_MIC_QOS_SELECT_VALUE_2_LSB                           8
#define MAC_PCU_MIC_QOS_SELECT_VALUE_2_MASK                          0x00000f00
#define MAC_PCU_MIC_QOS_SELECT_VALUE_2_GET(x)                        (((x) & MAC_PCU_MIC_QOS_SELECT_VALUE_2_MASK) >> MAC_PCU_MIC_QOS_SELECT_VALUE_2_LSB)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_2_SET(x)                        (((0 | (x)) << MAC_PCU_MIC_QOS_SELECT_VALUE_2_LSB) & MAC_PCU_MIC_QOS_SELECT_VALUE_2_MASK)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_2_RESET                         2
#define MAC_PCU_MIC_QOS_SELECT_VALUE_1_MSB                           7
#define MAC_PCU_MIC_QOS_SELECT_VALUE_1_LSB                           4
#define MAC_PCU_MIC_QOS_SELECT_VALUE_1_MASK                          0x000000f0
#define MAC_PCU_MIC_QOS_SELECT_VALUE_1_GET(x)                        (((x) & MAC_PCU_MIC_QOS_SELECT_VALUE_1_MASK) >> MAC_PCU_MIC_QOS_SELECT_VALUE_1_LSB)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_1_SET(x)                        (((0 | (x)) << MAC_PCU_MIC_QOS_SELECT_VALUE_1_LSB) & MAC_PCU_MIC_QOS_SELECT_VALUE_1_MASK)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_1_RESET                         1
#define MAC_PCU_MIC_QOS_SELECT_VALUE_0_MSB                           3
#define MAC_PCU_MIC_QOS_SELECT_VALUE_0_LSB                           0
#define MAC_PCU_MIC_QOS_SELECT_VALUE_0_MASK                          0x0000000f
#define MAC_PCU_MIC_QOS_SELECT_VALUE_0_GET(x)                        (((x) & MAC_PCU_MIC_QOS_SELECT_VALUE_0_MASK) >> MAC_PCU_MIC_QOS_SELECT_VALUE_0_LSB)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_0_SET(x)                        (((0 | (x)) << MAC_PCU_MIC_QOS_SELECT_VALUE_0_LSB) & MAC_PCU_MIC_QOS_SELECT_VALUE_0_MASK)
#define MAC_PCU_MIC_QOS_SELECT_VALUE_0_RESET                         0
#define MAC_PCU_MIC_QOS_SELECT_ADDRESS                               0x811c
#define MAC_PCU_MIC_QOS_SELECT_HW_MASK                               0xffffffff
#define MAC_PCU_MIC_QOS_SELECT_SW_MASK                               0xffffffff
#define MAC_PCU_MIC_QOS_SELECT_HW_WRITE_MASK                         0x00000000
#define MAC_PCU_MIC_QOS_SELECT_SW_WRITE_MASK                         0xffffffff
#define MAC_PCU_MIC_QOS_SELECT_RSTMASK                               0xffffffff
#define MAC_PCU_MIC_QOS_SELECT_RESET                                 0x00003210

// 0x8120 (MAC_PCU_MISC_MODE)
#define MAC_PCU_MISC_MODE_DEBUG_MODE_MSB                             31
#define MAC_PCU_MISC_MODE_DEBUG_MODE_LSB                             30
#define MAC_PCU_MISC_MODE_DEBUG_MODE_MASK                            0xc0000000
#define MAC_PCU_MISC_MODE_DEBUG_MODE_GET(x)                          (((x) & MAC_PCU_MISC_MODE_DEBUG_MODE_MASK) >> MAC_PCU_MISC_MODE_DEBUG_MODE_LSB)
#define MAC_PCU_MISC_MODE_DEBUG_MODE_SET(x)                          (((0 | (x)) << MAC_PCU_MISC_MODE_DEBUG_MODE_LSB) & MAC_PCU_MISC_MODE_DEBUG_MODE_MASK)
#define MAC_PCU_MISC_MODE_DEBUG_MODE_RESET                           0
#define MAC_PCU_MISC_MODE_USE_EOP_PTR_FOR_DMA_WR_MSB                 29
#define MAC_PCU_MISC_MODE_USE_EOP_PTR_FOR_DMA_WR_LSB                 29
#define MAC_PCU_MISC_MODE_USE_EOP_PTR_FOR_DMA_WR_MASK                0x20000000
#define MAC_PCU_MISC_MODE_USE_EOP_PTR_FOR_DMA_WR_GET(x)              (((x) & MAC_PCU_MISC_MODE_USE_EOP_PTR_FOR_DMA_WR_MASK) >> MAC_PCU_MISC_MODE_USE_EOP_PTR_FOR_DMA_WR_LSB)
#define MAC_PCU_MISC_MODE_USE_EOP_PTR_FOR_DMA_WR_SET(x)              (((0 | (x)) << MAC_PCU_MISC_MODE_USE_EOP_PTR_FOR_DMA_WR_LSB) & MAC_PCU_MISC_MODE_USE_EOP_PTR_FOR_DMA_WR_MASK)
#define MAC_PCU_MISC_MODE_USE_EOP_PTR_FOR_DMA_WR_RESET               0
#define MAC_PCU_MISC_MODE_ALWAYS_PERFORM_KEY_SEARCH_MSB              28
#define MAC_PCU_MISC_MODE_ALWAYS_PERFORM_KEY_SEARCH_LSB              28
#define MAC_PCU_MISC_MODE_ALWAYS_PERFORM_KEY_SEARCH_MASK             0x10000000
#define MAC_PCU_MISC_MODE_ALWAYS_PERFORM_KEY_SEARCH_GET(x)           (((x) & MAC_PCU_MISC_MODE_ALWAYS_PERFORM_KEY_SEARCH_MASK) >> MAC_PCU_MISC_MODE_ALWAYS_PERFORM_KEY_SEARCH_LSB)
#define MAC_PCU_MISC_MODE_ALWAYS_PERFORM_KEY_SEARCH_SET(x)           (((0 | (x)) << MAC_PCU_MISC_MODE_ALWAYS_PERFORM_KEY_SEARCH_LSB) & MAC_PCU_MISC_MODE_ALWAYS_PERFORM_KEY_SEARCH_MASK)
#define MAC_PCU_MISC_MODE_ALWAYS_PERFORM_KEY_SEARCH_RESET            0
#define MAC_PCU_MISC_MODE_SEL_EVM_MSB                                27
#define MAC_PCU_MISC_MODE_SEL_EVM_LSB                                27
#define MAC_PCU_MISC_MODE_SEL_EVM_MASK                               0x08000000
#define MAC_PCU_MISC_MODE_SEL_EVM_GET(x)                             (((x) & MAC_PCU_MISC_MODE_SEL_EVM_MASK) >> MAC_PCU_MISC_MODE_SEL_EVM_LSB)
#define MAC_PCU_MISC_MODE_SEL_EVM_SET(x)                             (((0 | (x)) << MAC_PCU_MISC_MODE_SEL_EVM_LSB) & MAC_PCU_MISC_MODE_SEL_EVM_MASK)
#define MAC_PCU_MISC_MODE_SEL_EVM_RESET                              1
#define MAC_PCU_MISC_MODE_CLEAR_BA_VALID_MSB                         26
#define MAC_PCU_MISC_MODE_CLEAR_BA_VALID_LSB                         26
#define MAC_PCU_MISC_MODE_CLEAR_BA_VALID_MASK                        0x04000000
#define MAC_PCU_MISC_MODE_CLEAR_BA_VALID_GET(x)                      (((x) & MAC_PCU_MISC_MODE_CLEAR_BA_VALID_MASK) >> MAC_PCU_MISC_MODE_CLEAR_BA_VALID_LSB)
#define MAC_PCU_MISC_MODE_CLEAR_BA_VALID_SET(x)                      (((0 | (x)) << MAC_PCU_MISC_MODE_CLEAR_BA_VALID_LSB) & MAC_PCU_MISC_MODE_CLEAR_BA_VALID_MASK)
#define MAC_PCU_MISC_MODE_CLEAR_BA_VALID_RESET                       0
#define MAC_PCU_MISC_MODE_CLEAR_FIRST_HCF_MSB                        25
#define MAC_PCU_MISC_MODE_CLEAR_FIRST_HCF_LSB                        25
#define MAC_PCU_MISC_MODE_CLEAR_FIRST_HCF_MASK                       0x02000000
#define MAC_PCU_MISC_MODE_CLEAR_FIRST_HCF_GET(x)                     (((x) & MAC_PCU_MISC_MODE_CLEAR_FIRST_HCF_MASK) >> MAC_PCU_MISC_MODE_CLEAR_FIRST_HCF_LSB)
#define MAC_PCU_MISC_MODE_CLEAR_FIRST_HCF_SET(x)                     (((0 | (x)) << MAC_PCU_MISC_MODE_CLEAR_FIRST_HCF_LSB) & MAC_PCU_MISC_MODE_CLEAR_FIRST_HCF_MASK)
#define MAC_PCU_MISC_MODE_CLEAR_FIRST_HCF_RESET                      0
#define MAC_PCU_MISC_MODE_CLEAR_VMF_MSB                              24
#define MAC_PCU_MISC_MODE_CLEAR_VMF_LSB                              24
#define MAC_PCU_MISC_MODE_CLEAR_VMF_MASK                             0x01000000
#define MAC_PCU_MISC_MODE_CLEAR_VMF_GET(x)                           (((x) & MAC_PCU_MISC_MODE_CLEAR_VMF_MASK) >> MAC_PCU_MISC_MODE_CLEAR_VMF_LSB)
#define MAC_PCU_MISC_MODE_CLEAR_VMF_SET(x)                           (((0 | (x)) << MAC_PCU_MISC_MODE_CLEAR_VMF_LSB) & MAC_PCU_MISC_MODE_CLEAR_VMF_MASK)
#define MAC_PCU_MISC_MODE_CLEAR_VMF_RESET                            0
#define MAC_PCU_MISC_MODE_RX_HCF_POLL_ENABLE_MSB                     23
#define MAC_PCU_MISC_MODE_RX_HCF_POLL_ENABLE_LSB                     23
#define MAC_PCU_MISC_MODE_RX_HCF_POLL_ENABLE_MASK                    0x00800000
#define MAC_PCU_MISC_MODE_RX_HCF_POLL_ENABLE_GET(x)                  (((x) & MAC_PCU_MISC_MODE_RX_HCF_POLL_ENABLE_MASK) >> MAC_PCU_MISC_MODE_RX_HCF_POLL_ENABLE_LSB)
#define MAC_PCU_MISC_MODE_RX_HCF_POLL_ENABLE_SET(x)                  (((0 | (x)) << MAC_PCU_MISC_MODE_RX_HCF_POLL_ENABLE_LSB) & MAC_PCU_MISC_MODE_RX_HCF_POLL_ENABLE_MASK)
#define MAC_PCU_MISC_MODE_RX_HCF_POLL_ENABLE_RESET                   1
#define MAC_PCU_MISC_MODE_HCF_POLL_CANCELS_NAV_MSB                   22
#define MAC_PCU_MISC_MODE_HCF_POLL_CANCELS_NAV_LSB                   22
#define MAC_PCU_MISC_MODE_HCF_POLL_CANCELS_NAV_MASK                  0x00400000
#define MAC_PCU_MISC_MODE_HCF_POLL_CANCELS_NAV_GET(x)                (((x) & MAC_PCU_MISC_MODE_HCF_POLL_CANCELS_NAV_MASK) >> MAC_PCU_MISC_MODE_HCF_POLL_CANCELS_NAV_LSB)
#define MAC_PCU_MISC_MODE_HCF_POLL_CANCELS_NAV_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE_HCF_POLL_CANCELS_NAV_LSB) & MAC_PCU_MISC_MODE_HCF_POLL_CANCELS_NAV_MASK)
#define MAC_PCU_MISC_MODE_HCF_POLL_CANCELS_NAV_RESET                 1
#define MAC_PCU_MISC_MODE_TBTT_PROTECT_MSB                           21
#define MAC_PCU_MISC_MODE_TBTT_PROTECT_LSB                           21
#define MAC_PCU_MISC_MODE_TBTT_PROTECT_MASK                          0x00200000
#define MAC_PCU_MISC_MODE_TBTT_PROTECT_GET(x)                        (((x) & MAC_PCU_MISC_MODE_TBTT_PROTECT_MASK) >> MAC_PCU_MISC_MODE_TBTT_PROTECT_LSB)
#define MAC_PCU_MISC_MODE_TBTT_PROTECT_SET(x)                        (((0 | (x)) << MAC_PCU_MISC_MODE_TBTT_PROTECT_LSB) & MAC_PCU_MISC_MODE_TBTT_PROTECT_MASK)
#define MAC_PCU_MISC_MODE_TBTT_PROTECT_RESET                         1
#define MAC_PCU_MISC_MODE_BT_ANT_PREVENTS_RX_MSB                     20
#define MAC_PCU_MISC_MODE_BT_ANT_PREVENTS_RX_LSB                     20
#define MAC_PCU_MISC_MODE_BT_ANT_PREVENTS_RX_MASK                    0x00100000
#define MAC_PCU_MISC_MODE_BT_ANT_PREVENTS_RX_GET(x)                  (((x) & MAC_PCU_MISC_MODE_BT_ANT_PREVENTS_RX_MASK) >> MAC_PCU_MISC_MODE_BT_ANT_PREVENTS_RX_LSB)
#define MAC_PCU_MISC_MODE_BT_ANT_PREVENTS_RX_SET(x)                  (((0 | (x)) << MAC_PCU_MISC_MODE_BT_ANT_PREVENTS_RX_LSB) & MAC_PCU_MISC_MODE_BT_ANT_PREVENTS_RX_MASK)
#define MAC_PCU_MISC_MODE_BT_ANT_PREVENTS_RX_RESET                   1
#define MAC_PCU_MISC_MODE_FORCE_QUIET_COLLISION_MSB                  18
#define MAC_PCU_MISC_MODE_FORCE_QUIET_COLLISION_LSB                  18
#define MAC_PCU_MISC_MODE_FORCE_QUIET_COLLISION_MASK                 0x00040000
#define MAC_PCU_MISC_MODE_FORCE_QUIET_COLLISION_GET(x)               (((x) & MAC_PCU_MISC_MODE_FORCE_QUIET_COLLISION_MASK) >> MAC_PCU_MISC_MODE_FORCE_QUIET_COLLISION_LSB)
#define MAC_PCU_MISC_MODE_FORCE_QUIET_COLLISION_SET(x)               (((0 | (x)) << MAC_PCU_MISC_MODE_FORCE_QUIET_COLLISION_LSB) & MAC_PCU_MISC_MODE_FORCE_QUIET_COLLISION_MASK)
#define MAC_PCU_MISC_MODE_FORCE_QUIET_COLLISION_RESET                0
#define MAC_PCU_MISC_MODE_MISS_BEACON_IN_SLEEP_MSB                   14
#define MAC_PCU_MISC_MODE_MISS_BEACON_IN_SLEEP_LSB                   14
#define MAC_PCU_MISC_MODE_MISS_BEACON_IN_SLEEP_MASK                  0x00004000
#define MAC_PCU_MISC_MODE_MISS_BEACON_IN_SLEEP_GET(x)                (((x) & MAC_PCU_MISC_MODE_MISS_BEACON_IN_SLEEP_MASK) >> MAC_PCU_MISC_MODE_MISS_BEACON_IN_SLEEP_LSB)
#define MAC_PCU_MISC_MODE_MISS_BEACON_IN_SLEEP_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE_MISS_BEACON_IN_SLEEP_LSB) & MAC_PCU_MISC_MODE_MISS_BEACON_IN_SLEEP_MASK)
#define MAC_PCU_MISC_MODE_MISS_BEACON_IN_SLEEP_RESET                 1
#define MAC_PCU_MISC_MODE_TXOP_TBTT_LIMIT_ENABLE_MSB                 12
#define MAC_PCU_MISC_MODE_TXOP_TBTT_LIMIT_ENABLE_LSB                 12
#define MAC_PCU_MISC_MODE_TXOP_TBTT_LIMIT_ENABLE_MASK                0x00001000
#define MAC_PCU_MISC_MODE_TXOP_TBTT_LIMIT_ENABLE_GET(x)              (((x) & MAC_PCU_MISC_MODE_TXOP_TBTT_LIMIT_ENABLE_MASK) >> MAC_PCU_MISC_MODE_TXOP_TBTT_LIMIT_ENABLE_LSB)
#define MAC_PCU_MISC_MODE_TXOP_TBTT_LIMIT_ENABLE_SET(x)              (((0 | (x)) << MAC_PCU_MISC_MODE_TXOP_TBTT_LIMIT_ENABLE_LSB) & MAC_PCU_MISC_MODE_TXOP_TBTT_LIMIT_ENABLE_MASK)
#define MAC_PCU_MISC_MODE_TXOP_TBTT_LIMIT_ENABLE_RESET               0
#define MAC_PCU_MISC_MODE_KC_RX_ANT_UPDATE_MSB                       11
#define MAC_PCU_MISC_MODE_KC_RX_ANT_UPDATE_LSB                       11
#define MAC_PCU_MISC_MODE_KC_RX_ANT_UPDATE_MASK                      0x00000800
#define MAC_PCU_MISC_MODE_KC_RX_ANT_UPDATE_GET(x)                    (((x) & MAC_PCU_MISC_MODE_KC_RX_ANT_UPDATE_MASK) >> MAC_PCU_MISC_MODE_KC_RX_ANT_UPDATE_LSB)
#define MAC_PCU_MISC_MODE_KC_RX_ANT_UPDATE_SET(x)                    (((0 | (x)) << MAC_PCU_MISC_MODE_KC_RX_ANT_UPDATE_LSB) & MAC_PCU_MISC_MODE_KC_RX_ANT_UPDATE_MASK)
#define MAC_PCU_MISC_MODE_KC_RX_ANT_UPDATE_RESET                     1
#define MAC_PCU_MISC_MODE_DEBUG_MODE_SIFS_MSB                        10
#define MAC_PCU_MISC_MODE_DEBUG_MODE_SIFS_LSB                        10
#define MAC_PCU_MISC_MODE_DEBUG_MODE_SIFS_MASK                       0x00000400
#define MAC_PCU_MISC_MODE_DEBUG_MODE_SIFS_GET(x)                     (((x) & MAC_PCU_MISC_MODE_DEBUG_MODE_SIFS_MASK) >> MAC_PCU_MISC_MODE_DEBUG_MODE_SIFS_LSB)
#define MAC_PCU_MISC_MODE_DEBUG_MODE_SIFS_SET(x)                     (((0 | (x)) << MAC_PCU_MISC_MODE_DEBUG_MODE_SIFS_LSB) & MAC_PCU_MISC_MODE_DEBUG_MODE_SIFS_MASK)
#define MAC_PCU_MISC_MODE_DEBUG_MODE_SIFS_RESET                      0
#define MAC_PCU_MISC_MODE_DEBUG_MODE_BA_BITMAP_MSB                   9
#define MAC_PCU_MISC_MODE_DEBUG_MODE_BA_BITMAP_LSB                   9
#define MAC_PCU_MISC_MODE_DEBUG_MODE_BA_BITMAP_MASK                  0x00000200
#define MAC_PCU_MISC_MODE_DEBUG_MODE_BA_BITMAP_GET(x)                (((x) & MAC_PCU_MISC_MODE_DEBUG_MODE_BA_BITMAP_MASK) >> MAC_PCU_MISC_MODE_DEBUG_MODE_BA_BITMAP_LSB)
#define MAC_PCU_MISC_MODE_DEBUG_MODE_BA_BITMAP_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE_DEBUG_MODE_BA_BITMAP_LSB) & MAC_PCU_MISC_MODE_DEBUG_MODE_BA_BITMAP_MASK)
#define MAC_PCU_MISC_MODE_DEBUG_MODE_BA_BITMAP_RESET                 0
#define MAC_PCU_MISC_MODE_RCV_DELAY_SOUNDING_IM_TXBF_MSB             6
#define MAC_PCU_MISC_MODE_RCV_DELAY_SOUNDING_IM_TXBF_LSB             6
#define MAC_PCU_MISC_MODE_RCV_DELAY_SOUNDING_IM_TXBF_MASK            0x00000040
#define MAC_PCU_MISC_MODE_RCV_DELAY_SOUNDING_IM_TXBF_GET(x)          (((x) & MAC_PCU_MISC_MODE_RCV_DELAY_SOUNDING_IM_TXBF_MASK) >> MAC_PCU_MISC_MODE_RCV_DELAY_SOUNDING_IM_TXBF_LSB)
#define MAC_PCU_MISC_MODE_RCV_DELAY_SOUNDING_IM_TXBF_SET(x)          (((0 | (x)) << MAC_PCU_MISC_MODE_RCV_DELAY_SOUNDING_IM_TXBF_LSB) & MAC_PCU_MISC_MODE_RCV_DELAY_SOUNDING_IM_TXBF_MASK)
#define MAC_PCU_MISC_MODE_RCV_DELAY_SOUNDING_IM_TXBF_RESET           0
#define MAC_PCU_MISC_MODE_RXSM2SVD_PRE_RST_MSB                       5
#define MAC_PCU_MISC_MODE_RXSM2SVD_PRE_RST_LSB                       5
#define MAC_PCU_MISC_MODE_RXSM2SVD_PRE_RST_MASK                      0x00000020
#define MAC_PCU_MISC_MODE_RXSM2SVD_PRE_RST_GET(x)                    (((x) & MAC_PCU_MISC_MODE_RXSM2SVD_PRE_RST_MASK) >> MAC_PCU_MISC_MODE_RXSM2SVD_PRE_RST_LSB)
#define MAC_PCU_MISC_MODE_RXSM2SVD_PRE_RST_SET(x)                    (((0 | (x)) << MAC_PCU_MISC_MODE_RXSM2SVD_PRE_RST_LSB) & MAC_PCU_MISC_MODE_RXSM2SVD_PRE_RST_MASK)
#define MAC_PCU_MISC_MODE_RXSM2SVD_PRE_RST_RESET                     0
#define MAC_PCU_MISC_MODE_CCK_SIFS_MODE_MSB                          4
#define MAC_PCU_MISC_MODE_CCK_SIFS_MODE_LSB                          4
#define MAC_PCU_MISC_MODE_CCK_SIFS_MODE_MASK                         0x00000010
#define MAC_PCU_MISC_MODE_CCK_SIFS_MODE_GET(x)                       (((x) & MAC_PCU_MISC_MODE_CCK_SIFS_MODE_MASK) >> MAC_PCU_MISC_MODE_CCK_SIFS_MODE_LSB)
#define MAC_PCU_MISC_MODE_CCK_SIFS_MODE_SET(x)                       (((0 | (x)) << MAC_PCU_MISC_MODE_CCK_SIFS_MODE_LSB) & MAC_PCU_MISC_MODE_CCK_SIFS_MODE_MASK)
#define MAC_PCU_MISC_MODE_CCK_SIFS_MODE_RESET                        0
#define MAC_PCU_MISC_MODE_TX_ADD_TSF_MSB                             3
#define MAC_PCU_MISC_MODE_TX_ADD_TSF_LSB                             3
#define MAC_PCU_MISC_MODE_TX_ADD_TSF_MASK                            0x00000008
#define MAC_PCU_MISC_MODE_TX_ADD_TSF_GET(x)                          (((x) & MAC_PCU_MISC_MODE_TX_ADD_TSF_MASK) >> MAC_PCU_MISC_MODE_TX_ADD_TSF_LSB)
#define MAC_PCU_MISC_MODE_TX_ADD_TSF_SET(x)                          (((0 | (x)) << MAC_PCU_MISC_MODE_TX_ADD_TSF_LSB) & MAC_PCU_MISC_MODE_TX_ADD_TSF_MASK)
#define MAC_PCU_MISC_MODE_TX_ADD_TSF_RESET                           0
#define MAC_PCU_MISC_MODE_MIC_NEW_LOCATION_ENABLE_MSB                2
#define MAC_PCU_MISC_MODE_MIC_NEW_LOCATION_ENABLE_LSB                2
#define MAC_PCU_MISC_MODE_MIC_NEW_LOCATION_ENABLE_MASK               0x00000004
#define MAC_PCU_MISC_MODE_MIC_NEW_LOCATION_ENABLE_GET(x)             (((x) & MAC_PCU_MISC_MODE_MIC_NEW_LOCATION_ENABLE_MASK) >> MAC_PCU_MISC_MODE_MIC_NEW_LOCATION_ENABLE_LSB)
#define MAC_PCU_MISC_MODE_MIC_NEW_LOCATION_ENABLE_SET(x)             (((0 | (x)) << MAC_PCU_MISC_MODE_MIC_NEW_LOCATION_ENABLE_LSB) & MAC_PCU_MISC_MODE_MIC_NEW_LOCATION_ENABLE_MASK)
#define MAC_PCU_MISC_MODE_MIC_NEW_LOCATION_ENABLE_RESET              0
#define MAC_PCU_MISC_MODE_DEBUG_MODE_AD_MSB                          1
#define MAC_PCU_MISC_MODE_DEBUG_MODE_AD_LSB                          1
#define MAC_PCU_MISC_MODE_DEBUG_MODE_AD_MASK                         0x00000002
#define MAC_PCU_MISC_MODE_DEBUG_MODE_AD_GET(x)                       (((x) & MAC_PCU_MISC_MODE_DEBUG_MODE_AD_MASK) >> MAC_PCU_MISC_MODE_DEBUG_MODE_AD_LSB)
#define MAC_PCU_MISC_MODE_DEBUG_MODE_AD_SET(x)                       (((0 | (x)) << MAC_PCU_MISC_MODE_DEBUG_MODE_AD_LSB) & MAC_PCU_MISC_MODE_DEBUG_MODE_AD_MASK)
#define MAC_PCU_MISC_MODE_DEBUG_MODE_AD_RESET                        0
#define MAC_PCU_MISC_MODE_BSSID_MATCH_FORCE_MSB                      0
#define MAC_PCU_MISC_MODE_BSSID_MATCH_FORCE_LSB                      0
#define MAC_PCU_MISC_MODE_BSSID_MATCH_FORCE_MASK                     0x00000001
#define MAC_PCU_MISC_MODE_BSSID_MATCH_FORCE_GET(x)                   (((x) & MAC_PCU_MISC_MODE_BSSID_MATCH_FORCE_MASK) >> MAC_PCU_MISC_MODE_BSSID_MATCH_FORCE_LSB)
#define MAC_PCU_MISC_MODE_BSSID_MATCH_FORCE_SET(x)                   (((0 | (x)) << MAC_PCU_MISC_MODE_BSSID_MATCH_FORCE_LSB) & MAC_PCU_MISC_MODE_BSSID_MATCH_FORCE_MASK)
#define MAC_PCU_MISC_MODE_BSSID_MATCH_FORCE_RESET                    0
#define MAC_PCU_MISC_MODE_ADDRESS                                    0x8120
#define MAC_PCU_MISC_MODE_HW_MASK                                    0xfff45e7f
#define MAC_PCU_MISC_MODE_SW_MASK                                    0xfff45e7f
#define MAC_PCU_MISC_MODE_HW_WRITE_MASK                              0x04000000
#define MAC_PCU_MISC_MODE_SW_WRITE_MASK                              0xfff45e7f
#define MAC_PCU_MISC_MODE_RSTMASK                                    0xffffffff
#define MAC_PCU_MISC_MODE_RESET                                      0x08f04800

// 0x8124 (MAC_PCU_FILTER_OFDM_CNT)
#define MAC_PCU_FILTER_OFDM_CNT_VALUE_MSB                            23
#define MAC_PCU_FILTER_OFDM_CNT_VALUE_LSB                            0
#define MAC_PCU_FILTER_OFDM_CNT_VALUE_MASK                           0x00ffffff
#define MAC_PCU_FILTER_OFDM_CNT_VALUE_GET(x)                         (((x) & MAC_PCU_FILTER_OFDM_CNT_VALUE_MASK) >> MAC_PCU_FILTER_OFDM_CNT_VALUE_LSB)
#define MAC_PCU_FILTER_OFDM_CNT_VALUE_SET(x)                         (((0 | (x)) << MAC_PCU_FILTER_OFDM_CNT_VALUE_LSB) & MAC_PCU_FILTER_OFDM_CNT_VALUE_MASK)
#define MAC_PCU_FILTER_OFDM_CNT_VALUE_RESET                          0
#define MAC_PCU_FILTER_OFDM_CNT_ADDRESS                              0x8124
#define MAC_PCU_FILTER_OFDM_CNT_HW_MASK                              0x00ffffff
#define MAC_PCU_FILTER_OFDM_CNT_SW_MASK                              0x00ffffff
#define MAC_PCU_FILTER_OFDM_CNT_HW_WRITE_MASK                        0x00ffffff
#define MAC_PCU_FILTER_OFDM_CNT_SW_WRITE_MASK                        0x00ffffff
#define MAC_PCU_FILTER_OFDM_CNT_RSTMASK                              0xffffffff
#define MAC_PCU_FILTER_OFDM_CNT_RESET                                0x00000000

// 0x8128 (MAC_PCU_FILTER_CCK_CNT)
#define MAC_PCU_FILTER_CCK_CNT_VALUE_MSB                             23
#define MAC_PCU_FILTER_CCK_CNT_VALUE_LSB                             0
#define MAC_PCU_FILTER_CCK_CNT_VALUE_MASK                            0x00ffffff
#define MAC_PCU_FILTER_CCK_CNT_VALUE_GET(x)                          (((x) & MAC_PCU_FILTER_CCK_CNT_VALUE_MASK) >> MAC_PCU_FILTER_CCK_CNT_VALUE_LSB)
#define MAC_PCU_FILTER_CCK_CNT_VALUE_SET(x)                          (((0 | (x)) << MAC_PCU_FILTER_CCK_CNT_VALUE_LSB) & MAC_PCU_FILTER_CCK_CNT_VALUE_MASK)
#define MAC_PCU_FILTER_CCK_CNT_VALUE_RESET                           0
#define MAC_PCU_FILTER_CCK_CNT_ADDRESS                               0x8128
#define MAC_PCU_FILTER_CCK_CNT_HW_MASK                               0x00ffffff
#define MAC_PCU_FILTER_CCK_CNT_SW_MASK                               0x00ffffff
#define MAC_PCU_FILTER_CCK_CNT_HW_WRITE_MASK                         0x00ffffff
#define MAC_PCU_FILTER_CCK_CNT_SW_WRITE_MASK                         0x00ffffff
#define MAC_PCU_FILTER_CCK_CNT_RSTMASK                               0xffffffff
#define MAC_PCU_FILTER_CCK_CNT_RESET                                 0x00000000

// 0x812c (MAC_PCU_PHY_ERR_CNT_1)
#define MAC_PCU_PHY_ERR_CNT_1_VALUE_MSB                              23
#define MAC_PCU_PHY_ERR_CNT_1_VALUE_LSB                              0
#define MAC_PCU_PHY_ERR_CNT_1_VALUE_MASK                             0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_1_VALUE_GET(x)                           (((x) & MAC_PCU_PHY_ERR_CNT_1_VALUE_MASK) >> MAC_PCU_PHY_ERR_CNT_1_VALUE_LSB)
#define MAC_PCU_PHY_ERR_CNT_1_VALUE_SET(x)                           (((0 | (x)) << MAC_PCU_PHY_ERR_CNT_1_VALUE_LSB) & MAC_PCU_PHY_ERR_CNT_1_VALUE_MASK)
#define MAC_PCU_PHY_ERR_CNT_1_VALUE_RESET                            0
#define MAC_PCU_PHY_ERR_CNT_1_ADDRESS                                0x812c
#define MAC_PCU_PHY_ERR_CNT_1_HW_MASK                                0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_1_SW_MASK                                0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_1_HW_WRITE_MASK                          0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_1_SW_WRITE_MASK                          0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_1_RSTMASK                                0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_RESET                                  0x00000000

// 0x8130 (MAC_PCU_PHY_ERR_CNT_1_MASK)
#define MAC_PCU_PHY_ERR_CNT_1_MASK_VALUE_MSB                         31
#define MAC_PCU_PHY_ERR_CNT_1_MASK_VALUE_LSB                         0
#define MAC_PCU_PHY_ERR_CNT_1_MASK_VALUE_MASK                        0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_MASK_VALUE_GET(x)                      (((x) & MAC_PCU_PHY_ERR_CNT_1_MASK_VALUE_MASK) >> MAC_PCU_PHY_ERR_CNT_1_MASK_VALUE_LSB)
#define MAC_PCU_PHY_ERR_CNT_1_MASK_VALUE_SET(x)                      (((0 | (x)) << MAC_PCU_PHY_ERR_CNT_1_MASK_VALUE_LSB) & MAC_PCU_PHY_ERR_CNT_1_MASK_VALUE_MASK)
#define MAC_PCU_PHY_ERR_CNT_1_MASK_VALUE_RESET                       0
#define MAC_PCU_PHY_ERR_CNT_1_MASK_ADDRESS                           0x8130
#define MAC_PCU_PHY_ERR_CNT_1_MASK_HW_MASK                           0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_MASK_SW_MASK                           0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_MASK_HW_WRITE_MASK                     0x00000000
#define MAC_PCU_PHY_ERR_CNT_1_MASK_SW_WRITE_MASK                     0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_MASK_RSTMASK                           0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_MASK_RESET                             0x00000000

// 0x8134 (MAC_PCU_PHY_ERR_CNT_2)
#define MAC_PCU_PHY_ERR_CNT_2_VALUE_MSB                              23
#define MAC_PCU_PHY_ERR_CNT_2_VALUE_LSB                              0
#define MAC_PCU_PHY_ERR_CNT_2_VALUE_MASK                             0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_2_VALUE_GET(x)                           (((x) & MAC_PCU_PHY_ERR_CNT_2_VALUE_MASK) >> MAC_PCU_PHY_ERR_CNT_2_VALUE_LSB)
#define MAC_PCU_PHY_ERR_CNT_2_VALUE_SET(x)                           (((0 | (x)) << MAC_PCU_PHY_ERR_CNT_2_VALUE_LSB) & MAC_PCU_PHY_ERR_CNT_2_VALUE_MASK)
#define MAC_PCU_PHY_ERR_CNT_2_VALUE_RESET                            0
#define MAC_PCU_PHY_ERR_CNT_2_ADDRESS                                0x8134
#define MAC_PCU_PHY_ERR_CNT_2_HW_MASK                                0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_2_SW_MASK                                0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_2_HW_WRITE_MASK                          0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_2_SW_WRITE_MASK                          0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_2_RSTMASK                                0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_RESET                                  0x00000000

// 0x8138 (MAC_PCU_PHY_ERR_CNT_2_MASK)
#define MAC_PCU_PHY_ERR_CNT_2_MASK_VALUE_MSB                         31
#define MAC_PCU_PHY_ERR_CNT_2_MASK_VALUE_LSB                         0
#define MAC_PCU_PHY_ERR_CNT_2_MASK_VALUE_MASK                        0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_MASK_VALUE_GET(x)                      (((x) & MAC_PCU_PHY_ERR_CNT_2_MASK_VALUE_MASK) >> MAC_PCU_PHY_ERR_CNT_2_MASK_VALUE_LSB)
#define MAC_PCU_PHY_ERR_CNT_2_MASK_VALUE_SET(x)                      (((0 | (x)) << MAC_PCU_PHY_ERR_CNT_2_MASK_VALUE_LSB) & MAC_PCU_PHY_ERR_CNT_2_MASK_VALUE_MASK)
#define MAC_PCU_PHY_ERR_CNT_2_MASK_VALUE_RESET                       0
#define MAC_PCU_PHY_ERR_CNT_2_MASK_ADDRESS                           0x8138
#define MAC_PCU_PHY_ERR_CNT_2_MASK_HW_MASK                           0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_MASK_SW_MASK                           0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_MASK_HW_WRITE_MASK                     0x00000000
#define MAC_PCU_PHY_ERR_CNT_2_MASK_SW_WRITE_MASK                     0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_MASK_RSTMASK                           0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_MASK_RESET                             0x00000000

// 0x8144 (MAC_PCU_PHY_ERROR_EIFS_MASK)
#define MAC_PCU_PHY_ERROR_EIFS_MASK_VALUE_MSB                        31
#define MAC_PCU_PHY_ERROR_EIFS_MASK_VALUE_LSB                        0
#define MAC_PCU_PHY_ERROR_EIFS_MASK_VALUE_MASK                       0xffffffff
#define MAC_PCU_PHY_ERROR_EIFS_MASK_VALUE_GET(x)                     (((x) & MAC_PCU_PHY_ERROR_EIFS_MASK_VALUE_MASK) >> MAC_PCU_PHY_ERROR_EIFS_MASK_VALUE_LSB)
#define MAC_PCU_PHY_ERROR_EIFS_MASK_VALUE_SET(x)                     (((0 | (x)) << MAC_PCU_PHY_ERROR_EIFS_MASK_VALUE_LSB) & MAC_PCU_PHY_ERROR_EIFS_MASK_VALUE_MASK)
#define MAC_PCU_PHY_ERROR_EIFS_MASK_VALUE_RESET                      0
#define MAC_PCU_PHY_ERROR_EIFS_MASK_ADDRESS                          0x8144
#define MAC_PCU_PHY_ERROR_EIFS_MASK_HW_MASK                          0xffffffff
#define MAC_PCU_PHY_ERROR_EIFS_MASK_SW_MASK                          0xffffffff
#define MAC_PCU_PHY_ERROR_EIFS_MASK_HW_WRITE_MASK                    0x00000000
#define MAC_PCU_PHY_ERROR_EIFS_MASK_SW_WRITE_MASK                    0xffffffff
#define MAC_PCU_PHY_ERROR_EIFS_MASK_RSTMASK                          0xffffffff
#define MAC_PCU_PHY_ERROR_EIFS_MASK_RESET                            0x00000000

// 0x8168 (MAC_PCU_PHY_ERR_CNT_3)
#define MAC_PCU_PHY_ERR_CNT_3_VALUE_MSB                              23
#define MAC_PCU_PHY_ERR_CNT_3_VALUE_LSB                              0
#define MAC_PCU_PHY_ERR_CNT_3_VALUE_MASK                             0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_3_VALUE_GET(x)                           (((x) & MAC_PCU_PHY_ERR_CNT_3_VALUE_MASK) >> MAC_PCU_PHY_ERR_CNT_3_VALUE_LSB)
#define MAC_PCU_PHY_ERR_CNT_3_VALUE_SET(x)                           (((0 | (x)) << MAC_PCU_PHY_ERR_CNT_3_VALUE_LSB) & MAC_PCU_PHY_ERR_CNT_3_VALUE_MASK)
#define MAC_PCU_PHY_ERR_CNT_3_VALUE_RESET                            0
#define MAC_PCU_PHY_ERR_CNT_3_ADDRESS                                0x8168
#define MAC_PCU_PHY_ERR_CNT_3_HW_MASK                                0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_3_SW_MASK                                0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_3_HW_WRITE_MASK                          0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_3_SW_WRITE_MASK                          0x00ffffff
#define MAC_PCU_PHY_ERR_CNT_3_RSTMASK                                0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_RESET                                  0x00000000

// 0x816c (MAC_PCU_PHY_ERR_CNT_3_MASK)
#define MAC_PCU_PHY_ERR_CNT_3_MASK_VALUE_MSB                         31
#define MAC_PCU_PHY_ERR_CNT_3_MASK_VALUE_LSB                         0
#define MAC_PCU_PHY_ERR_CNT_3_MASK_VALUE_MASK                        0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_MASK_VALUE_GET(x)                      (((x) & MAC_PCU_PHY_ERR_CNT_3_MASK_VALUE_MASK) >> MAC_PCU_PHY_ERR_CNT_3_MASK_VALUE_LSB)
#define MAC_PCU_PHY_ERR_CNT_3_MASK_VALUE_SET(x)                      (((0 | (x)) << MAC_PCU_PHY_ERR_CNT_3_MASK_VALUE_LSB) & MAC_PCU_PHY_ERR_CNT_3_MASK_VALUE_MASK)
#define MAC_PCU_PHY_ERR_CNT_3_MASK_VALUE_RESET                       0
#define MAC_PCU_PHY_ERR_CNT_3_MASK_ADDRESS                           0x816c
#define MAC_PCU_PHY_ERR_CNT_3_MASK_HW_MASK                           0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_MASK_SW_MASK                           0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_MASK_HW_WRITE_MASK                     0x00000000
#define MAC_PCU_PHY_ERR_CNT_3_MASK_SW_WRITE_MASK                     0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_MASK_RSTMASK                           0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_MASK_RESET                             0x00000000

// 0x8170 (MAC_PCU_BLUETOOTH_MODE)
#define MAC_PCU_BLUETOOTH_MODE_FIRST_SLOT_TIME_MSB                   31
#define MAC_PCU_BLUETOOTH_MODE_FIRST_SLOT_TIME_LSB                   24
#define MAC_PCU_BLUETOOTH_MODE_FIRST_SLOT_TIME_MASK                  0xff000000
#define MAC_PCU_BLUETOOTH_MODE_FIRST_SLOT_TIME_GET(x)                (((x) & MAC_PCU_BLUETOOTH_MODE_FIRST_SLOT_TIME_MASK) >> MAC_PCU_BLUETOOTH_MODE_FIRST_SLOT_TIME_LSB)
#define MAC_PCU_BLUETOOTH_MODE_FIRST_SLOT_TIME_SET(x)                (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE_FIRST_SLOT_TIME_LSB) & MAC_PCU_BLUETOOTH_MODE_FIRST_SLOT_TIME_MASK)
#define MAC_PCU_BLUETOOTH_MODE_FIRST_SLOT_TIME_RESET                 24
#define MAC_PCU_BLUETOOTH_MODE_PRIORITY_TIME_MSB                     23
#define MAC_PCU_BLUETOOTH_MODE_PRIORITY_TIME_LSB                     18
#define MAC_PCU_BLUETOOTH_MODE_PRIORITY_TIME_MASK                    0x00fc0000
#define MAC_PCU_BLUETOOTH_MODE_PRIORITY_TIME_GET(x)                  (((x) & MAC_PCU_BLUETOOTH_MODE_PRIORITY_TIME_MASK) >> MAC_PCU_BLUETOOTH_MODE_PRIORITY_TIME_LSB)
#define MAC_PCU_BLUETOOTH_MODE_PRIORITY_TIME_SET(x)                  (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE_PRIORITY_TIME_LSB) & MAC_PCU_BLUETOOTH_MODE_PRIORITY_TIME_MASK)
#define MAC_PCU_BLUETOOTH_MODE_PRIORITY_TIME_RESET                   18
#define MAC_PCU_BLUETOOTH_MODE_RX_CLEAR_POLARITY_MSB                 17
#define MAC_PCU_BLUETOOTH_MODE_RX_CLEAR_POLARITY_LSB                 17
#define MAC_PCU_BLUETOOTH_MODE_RX_CLEAR_POLARITY_MASK                0x00020000
#define MAC_PCU_BLUETOOTH_MODE_RX_CLEAR_POLARITY_GET(x)              (((x) & MAC_PCU_BLUETOOTH_MODE_RX_CLEAR_POLARITY_MASK) >> MAC_PCU_BLUETOOTH_MODE_RX_CLEAR_POLARITY_LSB)
#define MAC_PCU_BLUETOOTH_MODE_RX_CLEAR_POLARITY_SET(x)              (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE_RX_CLEAR_POLARITY_LSB) & MAC_PCU_BLUETOOTH_MODE_RX_CLEAR_POLARITY_MASK)
#define MAC_PCU_BLUETOOTH_MODE_RX_CLEAR_POLARITY_RESET               0
#define MAC_PCU_BLUETOOTH_MODE_QCU_THRESH_MSB                        16
#define MAC_PCU_BLUETOOTH_MODE_QCU_THRESH_LSB                        13
#define MAC_PCU_BLUETOOTH_MODE_QCU_THRESH_MASK                       0x0001e000
#define MAC_PCU_BLUETOOTH_MODE_QCU_THRESH_GET(x)                     (((x) & MAC_PCU_BLUETOOTH_MODE_QCU_THRESH_MASK) >> MAC_PCU_BLUETOOTH_MODE_QCU_THRESH_LSB)
#define MAC_PCU_BLUETOOTH_MODE_QCU_THRESH_SET(x)                     (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE_QCU_THRESH_LSB) & MAC_PCU_BLUETOOTH_MODE_QCU_THRESH_MASK)
#define MAC_PCU_BLUETOOTH_MODE_QCU_THRESH_RESET                      3
#define MAC_PCU_BLUETOOTH_MODE_QUIET_MSB                             12
#define MAC_PCU_BLUETOOTH_MODE_QUIET_LSB                             12
#define MAC_PCU_BLUETOOTH_MODE_QUIET_MASK                            0x00001000
#define MAC_PCU_BLUETOOTH_MODE_QUIET_GET(x)                          (((x) & MAC_PCU_BLUETOOTH_MODE_QUIET_MASK) >> MAC_PCU_BLUETOOTH_MODE_QUIET_LSB)
#define MAC_PCU_BLUETOOTH_MODE_QUIET_SET(x)                          (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE_QUIET_LSB) & MAC_PCU_BLUETOOTH_MODE_QUIET_MASK)
#define MAC_PCU_BLUETOOTH_MODE_QUIET_RESET                           0
#define MAC_PCU_BLUETOOTH_MODE_MODE_MSB                              11
#define MAC_PCU_BLUETOOTH_MODE_MODE_LSB                              10
#define MAC_PCU_BLUETOOTH_MODE_MODE_MASK                             0x00000c00
#define MAC_PCU_BLUETOOTH_MODE_MODE_GET(x)                           (((x) & MAC_PCU_BLUETOOTH_MODE_MODE_MASK) >> MAC_PCU_BLUETOOTH_MODE_MODE_LSB)
#define MAC_PCU_BLUETOOTH_MODE_MODE_SET(x)                           (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE_MODE_LSB) & MAC_PCU_BLUETOOTH_MODE_MODE_MASK)
#define MAC_PCU_BLUETOOTH_MODE_MODE_RESET                            3
#define MAC_PCU_BLUETOOTH_MODE_TX_FRAME_EXTEND_MSB                   9
#define MAC_PCU_BLUETOOTH_MODE_TX_FRAME_EXTEND_LSB                   9
#define MAC_PCU_BLUETOOTH_MODE_TX_FRAME_EXTEND_MASK                  0x00000200
#define MAC_PCU_BLUETOOTH_MODE_TX_FRAME_EXTEND_GET(x)                (((x) & MAC_PCU_BLUETOOTH_MODE_TX_FRAME_EXTEND_MASK) >> MAC_PCU_BLUETOOTH_MODE_TX_FRAME_EXTEND_LSB)
#define MAC_PCU_BLUETOOTH_MODE_TX_FRAME_EXTEND_SET(x)                (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE_TX_FRAME_EXTEND_LSB) & MAC_PCU_BLUETOOTH_MODE_TX_FRAME_EXTEND_MASK)
#define MAC_PCU_BLUETOOTH_MODE_TX_FRAME_EXTEND_RESET                 0
#define MAC_PCU_BLUETOOTH_MODE_TX_STATE_EXTEND_MSB                   8
#define MAC_PCU_BLUETOOTH_MODE_TX_STATE_EXTEND_LSB                   8
#define MAC_PCU_BLUETOOTH_MODE_TX_STATE_EXTEND_MASK                  0x00000100
#define MAC_PCU_BLUETOOTH_MODE_TX_STATE_EXTEND_GET(x)                (((x) & MAC_PCU_BLUETOOTH_MODE_TX_STATE_EXTEND_MASK) >> MAC_PCU_BLUETOOTH_MODE_TX_STATE_EXTEND_LSB)
#define MAC_PCU_BLUETOOTH_MODE_TX_STATE_EXTEND_SET(x)                (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE_TX_STATE_EXTEND_LSB) & MAC_PCU_BLUETOOTH_MODE_TX_STATE_EXTEND_MASK)
#define MAC_PCU_BLUETOOTH_MODE_TX_STATE_EXTEND_RESET                 0
#define MAC_PCU_BLUETOOTH_MODE_TIME_EXTEND_MSB                       7
#define MAC_PCU_BLUETOOTH_MODE_TIME_EXTEND_LSB                       0
#define MAC_PCU_BLUETOOTH_MODE_TIME_EXTEND_MASK                      0x000000ff
#define MAC_PCU_BLUETOOTH_MODE_TIME_EXTEND_GET(x)                    (((x) & MAC_PCU_BLUETOOTH_MODE_TIME_EXTEND_MASK) >> MAC_PCU_BLUETOOTH_MODE_TIME_EXTEND_LSB)
#define MAC_PCU_BLUETOOTH_MODE_TIME_EXTEND_SET(x)                    (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE_TIME_EXTEND_LSB) & MAC_PCU_BLUETOOTH_MODE_TIME_EXTEND_MASK)
#define MAC_PCU_BLUETOOTH_MODE_TIME_EXTEND_RESET                     0
#define MAC_PCU_BLUETOOTH_MODE_ADDRESS                               0x8170
#define MAC_PCU_BLUETOOTH_MODE_HW_MASK                               0xffffffff
#define MAC_PCU_BLUETOOTH_MODE_SW_MASK                               0xffffffff
#define MAC_PCU_BLUETOOTH_MODE_HW_WRITE_MASK                         0x00000000
#define MAC_PCU_BLUETOOTH_MODE_SW_WRITE_MASK                         0xffffffff
#define MAC_PCU_BLUETOOTH_MODE_RSTMASK                               0xffffffff
#define MAC_PCU_BLUETOOTH_MODE_RESET                                 0x18486c00

// 0x8178 (MAC_PCU_HCF_TIMEOUT)
#define MAC_PCU_HCF_TIMEOUT_VALUE_MSB                                15
#define MAC_PCU_HCF_TIMEOUT_VALUE_LSB                                0
#define MAC_PCU_HCF_TIMEOUT_VALUE_MASK                               0x0000ffff
#define MAC_PCU_HCF_TIMEOUT_VALUE_GET(x)                             (((x) & MAC_PCU_HCF_TIMEOUT_VALUE_MASK) >> MAC_PCU_HCF_TIMEOUT_VALUE_LSB)
#define MAC_PCU_HCF_TIMEOUT_VALUE_SET(x)                             (((0 | (x)) << MAC_PCU_HCF_TIMEOUT_VALUE_LSB) & MAC_PCU_HCF_TIMEOUT_VALUE_MASK)
#define MAC_PCU_HCF_TIMEOUT_VALUE_RESET                              0
#define MAC_PCU_HCF_TIMEOUT_ADDRESS                                  0x8178
#define MAC_PCU_HCF_TIMEOUT_HW_MASK                                  0x0000ffff
#define MAC_PCU_HCF_TIMEOUT_SW_MASK                                  0x0000ffff
#define MAC_PCU_HCF_TIMEOUT_HW_WRITE_MASK                            0x00000000
#define MAC_PCU_HCF_TIMEOUT_SW_WRITE_MASK                            0x0000ffff
#define MAC_PCU_HCF_TIMEOUT_RSTMASK                                  0xffffffff
#define MAC_PCU_HCF_TIMEOUT_RESET                                    0x00000000

// 0x817c (MAC_PCU_BLUETOOTH_MODE2)
#define MAC_PCU_BLUETOOTH_MODE2_PHY_ERR_BT_COLL_ENABLE_MSB           31
#define MAC_PCU_BLUETOOTH_MODE2_PHY_ERR_BT_COLL_ENABLE_LSB           31
#define MAC_PCU_BLUETOOTH_MODE2_PHY_ERR_BT_COLL_ENABLE_MASK          0x80000000
#define MAC_PCU_BLUETOOTH_MODE2_PHY_ERR_BT_COLL_ENABLE_GET(x)        (((x) & MAC_PCU_BLUETOOTH_MODE2_PHY_ERR_BT_COLL_ENABLE_MASK) >> MAC_PCU_BLUETOOTH_MODE2_PHY_ERR_BT_COLL_ENABLE_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_PHY_ERR_BT_COLL_ENABLE_SET(x)        (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_PHY_ERR_BT_COLL_ENABLE_LSB) & MAC_PCU_BLUETOOTH_MODE2_PHY_ERR_BT_COLL_ENABLE_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_PHY_ERR_BT_COLL_ENABLE_RESET         0
#define MAC_PCU_BLUETOOTH_MODE2_INTERRUPT_ENABLE_MSB                 30
#define MAC_PCU_BLUETOOTH_MODE2_INTERRUPT_ENABLE_LSB                 30
#define MAC_PCU_BLUETOOTH_MODE2_INTERRUPT_ENABLE_MASK                0x40000000
#define MAC_PCU_BLUETOOTH_MODE2_INTERRUPT_ENABLE_GET(x)              (((x) & MAC_PCU_BLUETOOTH_MODE2_INTERRUPT_ENABLE_MASK) >> MAC_PCU_BLUETOOTH_MODE2_INTERRUPT_ENABLE_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_INTERRUPT_ENABLE_SET(x)              (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_INTERRUPT_ENABLE_LSB) & MAC_PCU_BLUETOOTH_MODE2_INTERRUPT_ENABLE_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_INTERRUPT_ENABLE_RESET               0
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_PRIORITY_CTRL_MSB             29
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_PRIORITY_CTRL_LSB             28
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_PRIORITY_CTRL_MASK            0x30000000
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_PRIORITY_CTRL_GET(x)          (((x) & MAC_PCU_BLUETOOTH_MODE2_TSF_BT_PRIORITY_CTRL_MASK) >> MAC_PCU_BLUETOOTH_MODE2_TSF_BT_PRIORITY_CTRL_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_PRIORITY_CTRL_SET(x)          (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_TSF_BT_PRIORITY_CTRL_LSB) & MAC_PCU_BLUETOOTH_MODE2_TSF_BT_PRIORITY_CTRL_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_PRIORITY_CTRL_RESET           0
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_ACTIVE_CTRL_MSB               27
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_ACTIVE_CTRL_LSB               26
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_ACTIVE_CTRL_MASK              0x0c000000
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_ACTIVE_CTRL_GET(x)            (((x) & MAC_PCU_BLUETOOTH_MODE2_TSF_BT_ACTIVE_CTRL_MASK) >> MAC_PCU_BLUETOOTH_MODE2_TSF_BT_ACTIVE_CTRL_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_ACTIVE_CTRL_SET(x)            (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_TSF_BT_ACTIVE_CTRL_LSB) & MAC_PCU_BLUETOOTH_MODE2_TSF_BT_ACTIVE_CTRL_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_TSF_BT_ACTIVE_CTRL_RESET             0
#define MAC_PCU_BLUETOOTH_MODE2_RS_DISCARD_EXTEND_MSB                25
#define MAC_PCU_BLUETOOTH_MODE2_RS_DISCARD_EXTEND_LSB                25
#define MAC_PCU_BLUETOOTH_MODE2_RS_DISCARD_EXTEND_MASK               0x02000000
#define MAC_PCU_BLUETOOTH_MODE2_RS_DISCARD_EXTEND_GET(x)             (((x) & MAC_PCU_BLUETOOTH_MODE2_RS_DISCARD_EXTEND_MASK) >> MAC_PCU_BLUETOOTH_MODE2_RS_DISCARD_EXTEND_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_RS_DISCARD_EXTEND_SET(x)             (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_RS_DISCARD_EXTEND_LSB) & MAC_PCU_BLUETOOTH_MODE2_RS_DISCARD_EXTEND_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_RS_DISCARD_EXTEND_RESET              0
#define MAC_PCU_BLUETOOTH_MODE2_WL_TXRX_SEPARATE_MSB                 24
#define MAC_PCU_BLUETOOTH_MODE2_WL_TXRX_SEPARATE_LSB                 24
#define MAC_PCU_BLUETOOTH_MODE2_WL_TXRX_SEPARATE_MASK                0x01000000
#define MAC_PCU_BLUETOOTH_MODE2_WL_TXRX_SEPARATE_GET(x)              (((x) & MAC_PCU_BLUETOOTH_MODE2_WL_TXRX_SEPARATE_MASK) >> MAC_PCU_BLUETOOTH_MODE2_WL_TXRX_SEPARATE_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_WL_TXRX_SEPARATE_SET(x)              (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_WL_TXRX_SEPARATE_LSB) & MAC_PCU_BLUETOOTH_MODE2_WL_TXRX_SEPARATE_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_WL_TXRX_SEPARATE_RESET               0
#define MAC_PCU_BLUETOOTH_MODE2_WL_ACTIVE_MODE_MSB                   23
#define MAC_PCU_BLUETOOTH_MODE2_WL_ACTIVE_MODE_LSB                   22
#define MAC_PCU_BLUETOOTH_MODE2_WL_ACTIVE_MODE_MASK                  0x00c00000
#define MAC_PCU_BLUETOOTH_MODE2_WL_ACTIVE_MODE_GET(x)                (((x) & MAC_PCU_BLUETOOTH_MODE2_WL_ACTIVE_MODE_MASK) >> MAC_PCU_BLUETOOTH_MODE2_WL_ACTIVE_MODE_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_WL_ACTIVE_MODE_SET(x)                (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_WL_ACTIVE_MODE_LSB) & MAC_PCU_BLUETOOTH_MODE2_WL_ACTIVE_MODE_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_WL_ACTIVE_MODE_RESET                 0
#define MAC_PCU_BLUETOOTH_MODE2_QUIET_2_WIRE_MSB                     21
#define MAC_PCU_BLUETOOTH_MODE2_QUIET_2_WIRE_LSB                     21
#define MAC_PCU_BLUETOOTH_MODE2_QUIET_2_WIRE_MASK                    0x00200000
#define MAC_PCU_BLUETOOTH_MODE2_QUIET_2_WIRE_GET(x)                  (((x) & MAC_PCU_BLUETOOTH_MODE2_QUIET_2_WIRE_MASK) >> MAC_PCU_BLUETOOTH_MODE2_QUIET_2_WIRE_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_QUIET_2_WIRE_SET(x)                  (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_QUIET_2_WIRE_LSB) & MAC_PCU_BLUETOOTH_MODE2_QUIET_2_WIRE_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_QUIET_2_WIRE_RESET                   0
#define MAC_PCU_BLUETOOTH_MODE2_DISABLE_BT_ANT_MSB                   20
#define MAC_PCU_BLUETOOTH_MODE2_DISABLE_BT_ANT_LSB                   20
#define MAC_PCU_BLUETOOTH_MODE2_DISABLE_BT_ANT_MASK                  0x00100000
#define MAC_PCU_BLUETOOTH_MODE2_DISABLE_BT_ANT_GET(x)                (((x) & MAC_PCU_BLUETOOTH_MODE2_DISABLE_BT_ANT_MASK) >> MAC_PCU_BLUETOOTH_MODE2_DISABLE_BT_ANT_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_DISABLE_BT_ANT_SET(x)                (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_DISABLE_BT_ANT_LSB) & MAC_PCU_BLUETOOTH_MODE2_DISABLE_BT_ANT_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_DISABLE_BT_ANT_RESET                 0
#define MAC_PCU_BLUETOOTH_MODE2_PROTECT_BT_AFTER_WAKEUP_MSB          19
#define MAC_PCU_BLUETOOTH_MODE2_PROTECT_BT_AFTER_WAKEUP_LSB          19
#define MAC_PCU_BLUETOOTH_MODE2_PROTECT_BT_AFTER_WAKEUP_MASK         0x00080000
#define MAC_PCU_BLUETOOTH_MODE2_PROTECT_BT_AFTER_WAKEUP_GET(x)       (((x) & MAC_PCU_BLUETOOTH_MODE2_PROTECT_BT_AFTER_WAKEUP_MASK) >> MAC_PCU_BLUETOOTH_MODE2_PROTECT_BT_AFTER_WAKEUP_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_PROTECT_BT_AFTER_WAKEUP_SET(x)       (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_PROTECT_BT_AFTER_WAKEUP_LSB) & MAC_PCU_BLUETOOTH_MODE2_PROTECT_BT_AFTER_WAKEUP_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_PROTECT_BT_AFTER_WAKEUP_RESET        0
#define MAC_PCU_BLUETOOTH_MODE2_SLEEP_ALLOW_BT_ACCESS_MSB            17
#define MAC_PCU_BLUETOOTH_MODE2_SLEEP_ALLOW_BT_ACCESS_LSB            17
#define MAC_PCU_BLUETOOTH_MODE2_SLEEP_ALLOW_BT_ACCESS_MASK           0x00020000
#define MAC_PCU_BLUETOOTH_MODE2_SLEEP_ALLOW_BT_ACCESS_GET(x)         (((x) & MAC_PCU_BLUETOOTH_MODE2_SLEEP_ALLOW_BT_ACCESS_MASK) >> MAC_PCU_BLUETOOTH_MODE2_SLEEP_ALLOW_BT_ACCESS_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_SLEEP_ALLOW_BT_ACCESS_SET(x)         (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_SLEEP_ALLOW_BT_ACCESS_LSB) & MAC_PCU_BLUETOOTH_MODE2_SLEEP_ALLOW_BT_ACCESS_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_SLEEP_ALLOW_BT_ACCESS_RESET          1
#define MAC_PCU_BLUETOOTH_MODE2_HOLD_RX_CLEAR_MSB                    16
#define MAC_PCU_BLUETOOTH_MODE2_HOLD_RX_CLEAR_LSB                    16
#define MAC_PCU_BLUETOOTH_MODE2_HOLD_RX_CLEAR_MASK                   0x00010000
#define MAC_PCU_BLUETOOTH_MODE2_HOLD_RX_CLEAR_GET(x)                 (((x) & MAC_PCU_BLUETOOTH_MODE2_HOLD_RX_CLEAR_MASK) >> MAC_PCU_BLUETOOTH_MODE2_HOLD_RX_CLEAR_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_HOLD_RX_CLEAR_SET(x)                 (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_HOLD_RX_CLEAR_LSB) & MAC_PCU_BLUETOOTH_MODE2_HOLD_RX_CLEAR_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_HOLD_RX_CLEAR_RESET                  0
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_CNT_MSB                     15
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_CNT_LSB                     8
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_CNT_MASK                    0x0000ff00
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_CNT_GET(x)                  (((x) & MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_CNT_MASK) >> MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_CNT_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_CNT_SET(x)                  (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_CNT_LSB) & MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_CNT_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_CNT_RESET                   0
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_THRESH_MSB                  7
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_THRESH_LSB                  0
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_THRESH_MASK                 0x000000ff
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_THRESH_GET(x)               (((x) & MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_THRESH_MASK) >> MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_THRESH_LSB)
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_THRESH_SET(x)               (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_THRESH_LSB) & MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_THRESH_MASK)
#define MAC_PCU_BLUETOOTH_MODE2_BCN_MISS_THRESH_RESET                0
#define MAC_PCU_BLUETOOTH_MODE2_ADDRESS                              0x817c
#define MAC_PCU_BLUETOOTH_MODE2_HW_MASK                              0xfffbffff
#define MAC_PCU_BLUETOOTH_MODE2_SW_MASK                              0xfffbffff
#define MAC_PCU_BLUETOOTH_MODE2_HW_WRITE_MASK                        0x0000ff00
#define MAC_PCU_BLUETOOTH_MODE2_SW_WRITE_MASK                        0xfffb00ff
#define MAC_PCU_BLUETOOTH_MODE2_RSTMASK                              0xffffffff
#define MAC_PCU_BLUETOOTH_MODE2_RESET                                0x00020000

// 0x81c8 (MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE)
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_VALUE_MSB                    31
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_VALUE_LSB                    0
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_VALUE_MASK                   0xffffffff
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_VALUE_GET(x)                 (((x) & MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_VALUE_MASK) >> MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_VALUE_LSB)
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_VALUE_SET(x)                 (((0 | (x)) << MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_VALUE_LSB) & MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_VALUE_MASK)
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_VALUE_RESET                  0
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_ADDRESS                      0x81c8
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_HW_MASK                      0xffffffff
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_SW_MASK                      0xffffffff
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_HW_WRITE_MASK                0xffffffff
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_SW_WRITE_MASK                0x00000000
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_RSTMASK                      0xffffffff
#define MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE_RESET                        0x00000000

// 0x81cc (MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY)
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_VALUE_MSB                  31
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_VALUE_LSB                  0
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_VALUE_MASK                 0xffffffff
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_VALUE_GET(x)               (((x) & MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_VALUE_MASK) >> MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_VALUE_LSB)
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_VALUE_SET(x)               (((0 | (x)) << MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_VALUE_LSB) & MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_VALUE_MASK)
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_VALUE_RESET                0
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_ADDRESS                    0x81cc
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_HW_MASK                    0xffffffff
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_SW_MASK                    0xffffffff
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_HW_WRITE_MASK              0xffffffff
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_SW_WRITE_MASK              0x00000000
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_RSTMASK                    0xffffffff
#define MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY_RESET                      0x00000000

// 0x81d0 (MAC_PCU_TXSIFS)
#define MAC_PCU_TXSIFS_ACK_SHIFT_MSB                                 14
#define MAC_PCU_TXSIFS_ACK_SHIFT_LSB                                 12
#define MAC_PCU_TXSIFS_ACK_SHIFT_MASK                                0x00007000
#define MAC_PCU_TXSIFS_ACK_SHIFT_GET(x)                              (((x) & MAC_PCU_TXSIFS_ACK_SHIFT_MASK) >> MAC_PCU_TXSIFS_ACK_SHIFT_LSB)
#define MAC_PCU_TXSIFS_ACK_SHIFT_SET(x)                              (((0 | (x)) << MAC_PCU_TXSIFS_ACK_SHIFT_LSB) & MAC_PCU_TXSIFS_ACK_SHIFT_MASK)
#define MAC_PCU_TXSIFS_ACK_SHIFT_RESET                               3
#define MAC_PCU_TXSIFS_TX_LATENCY_MSB                                11
#define MAC_PCU_TXSIFS_TX_LATENCY_LSB                                8
#define MAC_PCU_TXSIFS_TX_LATENCY_MASK                               0x00000f00
#define MAC_PCU_TXSIFS_TX_LATENCY_GET(x)                             (((x) & MAC_PCU_TXSIFS_TX_LATENCY_MASK) >> MAC_PCU_TXSIFS_TX_LATENCY_LSB)
#define MAC_PCU_TXSIFS_TX_LATENCY_SET(x)                             (((0 | (x)) << MAC_PCU_TXSIFS_TX_LATENCY_LSB) & MAC_PCU_TXSIFS_TX_LATENCY_MASK)
#define MAC_PCU_TXSIFS_TX_LATENCY_RESET                              2
#define MAC_PCU_TXSIFS_SIFS_TIME_MSB                                 7
#define MAC_PCU_TXSIFS_SIFS_TIME_LSB                                 0
#define MAC_PCU_TXSIFS_SIFS_TIME_MASK                                0x000000ff
#define MAC_PCU_TXSIFS_SIFS_TIME_GET(x)                              (((x) & MAC_PCU_TXSIFS_SIFS_TIME_MASK) >> MAC_PCU_TXSIFS_SIFS_TIME_LSB)
#define MAC_PCU_TXSIFS_SIFS_TIME_SET(x)                              (((0 | (x)) << MAC_PCU_TXSIFS_SIFS_TIME_LSB) & MAC_PCU_TXSIFS_SIFS_TIME_MASK)
#define MAC_PCU_TXSIFS_SIFS_TIME_RESET                               16
#define MAC_PCU_TXSIFS_ADDRESS                                       0x81d0
#define MAC_PCU_TXSIFS_HW_MASK                                       0x00007fff
#define MAC_PCU_TXSIFS_SW_MASK                                       0x00007fff
#define MAC_PCU_TXSIFS_HW_WRITE_MASK                                 0x00000000
#define MAC_PCU_TXSIFS_SW_WRITE_MASK                                 0x00007fff
#define MAC_PCU_TXSIFS_RSTMASK                                       0xffffffff
#define MAC_PCU_TXSIFS_RESET                                         0x00003210

// 0x81d4 (MAC_PCU_BLUETOOTH_MODE3)
#define MAC_PCU_BLUETOOTH_MODE3_BT_PRIORITY_EXTEND_THRES_MSB         31
#define MAC_PCU_BLUETOOTH_MODE3_BT_PRIORITY_EXTEND_THRES_LSB         28
#define MAC_PCU_BLUETOOTH_MODE3_BT_PRIORITY_EXTEND_THRES_MASK        0xf0000000
#define MAC_PCU_BLUETOOTH_MODE3_BT_PRIORITY_EXTEND_THRES_GET(x)      (((x) & MAC_PCU_BLUETOOTH_MODE3_BT_PRIORITY_EXTEND_THRES_MASK) >> MAC_PCU_BLUETOOTH_MODE3_BT_PRIORITY_EXTEND_THRES_LSB)
#define MAC_PCU_BLUETOOTH_MODE3_BT_PRIORITY_EXTEND_THRES_SET(x)      (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE3_BT_PRIORITY_EXTEND_THRES_LSB) & MAC_PCU_BLUETOOTH_MODE3_BT_PRIORITY_EXTEND_THRES_MASK)
#define MAC_PCU_BLUETOOTH_MODE3_BT_PRIORITY_EXTEND_THRES_RESET       0
#define MAC_PCU_BLUETOOTH_MODE3_BT_TX_ON_EN_MSB                      27
#define MAC_PCU_BLUETOOTH_MODE3_BT_TX_ON_EN_LSB                      27
#define MAC_PCU_BLUETOOTH_MODE3_BT_TX_ON_EN_MASK                     0x08000000
#define MAC_PCU_BLUETOOTH_MODE3_BT_TX_ON_EN_GET(x)                   (((x) & MAC_PCU_BLUETOOTH_MODE3_BT_TX_ON_EN_MASK) >> MAC_PCU_BLUETOOTH_MODE3_BT_TX_ON_EN_LSB)
#define MAC_PCU_BLUETOOTH_MODE3_BT_TX_ON_EN_SET(x)                   (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE3_BT_TX_ON_EN_LSB) & MAC_PCU_BLUETOOTH_MODE3_BT_TX_ON_EN_MASK)
#define MAC_PCU_BLUETOOTH_MODE3_BT_TX_ON_EN_RESET                    1
#define MAC_PCU_BLUETOOTH_MODE3_SLOT_SLOP_MSB                        26
#define MAC_PCU_BLUETOOTH_MODE3_SLOT_SLOP_LSB                        25
#define MAC_PCU_BLUETOOTH_MODE3_SLOT_SLOP_MASK                       0x06000000
#define MAC_PCU_BLUETOOTH_MODE3_SLOT_SLOP_GET(x)                     (((x) & MAC_PCU_BLUETOOTH_MODE3_SLOT_SLOP_MASK) >> MAC_PCU_BLUETOOTH_MODE3_SLOT_SLOP_LSB)
#define MAC_PCU_BLUETOOTH_MODE3_SLOT_SLOP_SET(x)                     (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE3_SLOT_SLOP_LSB) & MAC_PCU_BLUETOOTH_MODE3_SLOT_SLOP_MASK)
#define MAC_PCU_BLUETOOTH_MODE3_SLOT_SLOP_RESET                      1
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_TOGGLE_WLA_EN_MSB            24
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_TOGGLE_WLA_EN_LSB            24
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_TOGGLE_WLA_EN_MASK           0x01000000
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_TOGGLE_WLA_EN_GET(x)         (((x) & MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_TOGGLE_WLA_EN_MASK) >> MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_TOGGLE_WLA_EN_LSB)
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_TOGGLE_WLA_EN_SET(x)         (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_TOGGLE_WLA_EN_LSB) & MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_TOGGLE_WLA_EN_MASK)
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_TOGGLE_WLA_EN_RESET          0
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_PRI_EN_MSB                   23
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_PRI_EN_LSB                   23
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_PRI_EN_MASK                  0x00800000
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_PRI_EN_GET(x)                (((x) & MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_PRI_EN_MASK) >> MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_PRI_EN_LSB)
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_PRI_EN_SET(x)                (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_PRI_EN_LSB) & MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_PRI_EN_MASK)
#define MAC_PCU_BLUETOOTH_MODE3_DYNAMIC_PRI_EN_RESET                 0
#define MAC_PCU_BLUETOOTH_MODE3_WL_PRIORITY_OFFSET_EN_MSB            21
#define MAC_PCU_BLUETOOTH_MODE3_WL_PRIORITY_OFFSET_EN_LSB            21
#define MAC_PCU_BLUETOOTH_MODE3_WL_PRIORITY_OFFSET_EN_MASK           0x00200000
#define MAC_PCU_BLUETOOTH_MODE3_WL_PRIORITY_OFFSET_EN_GET(x)         (((x) & MAC_PCU_BLUETOOTH_MODE3_WL_PRIORITY_OFFSET_EN_MASK) >> MAC_PCU_BLUETOOTH_MODE3_WL_PRIORITY_OFFSET_EN_LSB)
#define MAC_PCU_BLUETOOTH_MODE3_WL_PRIORITY_OFFSET_EN_SET(x)         (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE3_WL_PRIORITY_OFFSET_EN_LSB) & MAC_PCU_BLUETOOTH_MODE3_WL_PRIORITY_OFFSET_EN_MASK)
#define MAC_PCU_BLUETOOTH_MODE3_WL_PRIORITY_OFFSET_EN_RESET          0
#define MAC_PCU_BLUETOOTH_MODE3_AGC_SATURATION_CNT_ENABLE_MSB        20
#define MAC_PCU_BLUETOOTH_MODE3_AGC_SATURATION_CNT_ENABLE_LSB        20
#define MAC_PCU_BLUETOOTH_MODE3_AGC_SATURATION_CNT_ENABLE_MASK       0x00100000
#define MAC_PCU_BLUETOOTH_MODE3_AGC_SATURATION_CNT_ENABLE_GET(x)     (((x) & MAC_PCU_BLUETOOTH_MODE3_AGC_SATURATION_CNT_ENABLE_MASK) >> MAC_PCU_BLUETOOTH_MODE3_AGC_SATURATION_CNT_ENABLE_LSB)
#define MAC_PCU_BLUETOOTH_MODE3_AGC_SATURATION_CNT_ENABLE_SET(x)     (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE3_AGC_SATURATION_CNT_ENABLE_LSB) & MAC_PCU_BLUETOOTH_MODE3_AGC_SATURATION_CNT_ENABLE_MASK)
#define MAC_PCU_BLUETOOTH_MODE3_AGC_SATURATION_CNT_ENABLE_RESET      0
#define MAC_PCU_BLUETOOTH_MODE3_ALLOW_CONCURRENT_ACCESS_MSB          19
#define MAC_PCU_BLUETOOTH_MODE3_ALLOW_CONCURRENT_ACCESS_LSB          16
#define MAC_PCU_BLUETOOTH_MODE3_ALLOW_CONCURRENT_ACCESS_MASK         0x000f0000
#define MAC_PCU_BLUETOOTH_MODE3_ALLOW_CONCURRENT_ACCESS_GET(x)       (((x) & MAC_PCU_BLUETOOTH_MODE3_ALLOW_CONCURRENT_ACCESS_MASK) >> MAC_PCU_BLUETOOTH_MODE3_ALLOW_CONCURRENT_ACCESS_LSB)
#define MAC_PCU_BLUETOOTH_MODE3_ALLOW_CONCURRENT_ACCESS_SET(x)       (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE3_ALLOW_CONCURRENT_ACCESS_LSB) & MAC_PCU_BLUETOOTH_MODE3_ALLOW_CONCURRENT_ACCESS_MASK)
#define MAC_PCU_BLUETOOTH_MODE3_ALLOW_CONCURRENT_ACCESS_RESET        0
#define MAC_PCU_BLUETOOTH_MODE3_WL_QC_TIME_MSB                       15
#define MAC_PCU_BLUETOOTH_MODE3_WL_QC_TIME_LSB                       8
#define MAC_PCU_BLUETOOTH_MODE3_WL_QC_TIME_MASK                      0x0000ff00
#define MAC_PCU_BLUETOOTH_MODE3_WL_QC_TIME_GET(x)                    (((x) & MAC_PCU_BLUETOOTH_MODE3_WL_QC_TIME_MASK) >> MAC_PCU_BLUETOOTH_MODE3_WL_QC_TIME_LSB)
#define MAC_PCU_BLUETOOTH_MODE3_WL_QC_TIME_SET(x)                    (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE3_WL_QC_TIME_LSB) & MAC_PCU_BLUETOOTH_MODE3_WL_QC_TIME_MASK)
#define MAC_PCU_BLUETOOTH_MODE3_WL_QC_TIME_RESET                     0
#define MAC_PCU_BLUETOOTH_MODE3_WL_ACTIVE_TIME_MSB                   7
#define MAC_PCU_BLUETOOTH_MODE3_WL_ACTIVE_TIME_LSB                   0
#define MAC_PCU_BLUETOOTH_MODE3_WL_ACTIVE_TIME_MASK                  0x000000ff
#define MAC_PCU_BLUETOOTH_MODE3_WL_ACTIVE_TIME_GET(x)                (((x) & MAC_PCU_BLUETOOTH_MODE3_WL_ACTIVE_TIME_MASK) >> MAC_PCU_BLUETOOTH_MODE3_WL_ACTIVE_TIME_LSB)
#define MAC_PCU_BLUETOOTH_MODE3_WL_ACTIVE_TIME_SET(x)                (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE3_WL_ACTIVE_TIME_LSB) & MAC_PCU_BLUETOOTH_MODE3_WL_ACTIVE_TIME_MASK)
#define MAC_PCU_BLUETOOTH_MODE3_WL_ACTIVE_TIME_RESET                 0
#define MAC_PCU_BLUETOOTH_MODE3_ADDRESS                              0x81d4
#define MAC_PCU_BLUETOOTH_MODE3_HW_MASK                              0xffbfffff
#define MAC_PCU_BLUETOOTH_MODE3_SW_MASK                              0xffbfffff
#define MAC_PCU_BLUETOOTH_MODE3_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_BLUETOOTH_MODE3_SW_WRITE_MASK                        0xffbfffff
#define MAC_PCU_BLUETOOTH_MODE3_RSTMASK                              0xffffffff
#define MAC_PCU_BLUETOOTH_MODE3_RESET                                0x0a000000

// 0x81d8 (MAC_PCU_BLUETOOTH_MODE4)
#define MAC_PCU_BLUETOOTH_MODE4_BT_PRIORITY_EXTEND_MSB               31
#define MAC_PCU_BLUETOOTH_MODE4_BT_PRIORITY_EXTEND_LSB               16
#define MAC_PCU_BLUETOOTH_MODE4_BT_PRIORITY_EXTEND_MASK              0xffff0000
#define MAC_PCU_BLUETOOTH_MODE4_BT_PRIORITY_EXTEND_GET(x)            (((x) & MAC_PCU_BLUETOOTH_MODE4_BT_PRIORITY_EXTEND_MASK) >> MAC_PCU_BLUETOOTH_MODE4_BT_PRIORITY_EXTEND_LSB)
#define MAC_PCU_BLUETOOTH_MODE4_BT_PRIORITY_EXTEND_SET(x)            (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE4_BT_PRIORITY_EXTEND_LSB) & MAC_PCU_BLUETOOTH_MODE4_BT_PRIORITY_EXTEND_MASK)
#define MAC_PCU_BLUETOOTH_MODE4_BT_PRIORITY_EXTEND_RESET             0
#define MAC_PCU_BLUETOOTH_MODE4_BT_ACTIVE_EXTEND_MSB                 15
#define MAC_PCU_BLUETOOTH_MODE4_BT_ACTIVE_EXTEND_LSB                 0
#define MAC_PCU_BLUETOOTH_MODE4_BT_ACTIVE_EXTEND_MASK                0x0000ffff
#define MAC_PCU_BLUETOOTH_MODE4_BT_ACTIVE_EXTEND_GET(x)              (((x) & MAC_PCU_BLUETOOTH_MODE4_BT_ACTIVE_EXTEND_MASK) >> MAC_PCU_BLUETOOTH_MODE4_BT_ACTIVE_EXTEND_LSB)
#define MAC_PCU_BLUETOOTH_MODE4_BT_ACTIVE_EXTEND_SET(x)              (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE4_BT_ACTIVE_EXTEND_LSB) & MAC_PCU_BLUETOOTH_MODE4_BT_ACTIVE_EXTEND_MASK)
#define MAC_PCU_BLUETOOTH_MODE4_BT_ACTIVE_EXTEND_RESET               0
#define MAC_PCU_BLUETOOTH_MODE4_ADDRESS                              0x81d8
#define MAC_PCU_BLUETOOTH_MODE4_HW_MASK                              0xffffffff
#define MAC_PCU_BLUETOOTH_MODE4_SW_MASK                              0xffffffff
#define MAC_PCU_BLUETOOTH_MODE4_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_BLUETOOTH_MODE4_SW_WRITE_MASK                        0xffffffff
#define MAC_PCU_BLUETOOTH_MODE4_RSTMASK                              0xffffffff
#define MAC_PCU_BLUETOOTH_MODE4_RESET                                0x00000000

// 0x81dc (MAC_PCU_BLUETOOTH_MODE5)
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_VAL_MSB               24
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_VAL_LSB               24
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_VAL_MASK              0x01000000
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_VAL_GET(x)            (((x) & MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_VAL_MASK) >> MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_VAL_LSB)
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_VAL_SET(x)            (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_VAL_LSB) & MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_VAL_MASK)
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_VAL_RESET             1
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_EN_MSB                23
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_EN_LSB                23
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_EN_MASK               0x00800000
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_EN_GET(x)             (((x) & MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_EN_MASK) >> MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_EN_LSB)
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_EN_SET(x)             (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_EN_LSB) & MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_EN_MASK)
#define MAC_PCU_BLUETOOTH_MODE5_FORCE_RX_CLEAR_EN_RESET              0
#define MAC_PCU_BLUETOOTH_MODE5_USE_D2_SLEEP_MSB                     22
#define MAC_PCU_BLUETOOTH_MODE5_USE_D2_SLEEP_LSB                     22
#define MAC_PCU_BLUETOOTH_MODE5_USE_D2_SLEEP_MASK                    0x00400000
#define MAC_PCU_BLUETOOTH_MODE5_USE_D2_SLEEP_GET(x)                  (((x) & MAC_PCU_BLUETOOTH_MODE5_USE_D2_SLEEP_MASK) >> MAC_PCU_BLUETOOTH_MODE5_USE_D2_SLEEP_LSB)
#define MAC_PCU_BLUETOOTH_MODE5_USE_D2_SLEEP_SET(x)                  (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE5_USE_D2_SLEEP_LSB) & MAC_PCU_BLUETOOTH_MODE5_USE_D2_SLEEP_MASK)
#define MAC_PCU_BLUETOOTH_MODE5_USE_D2_SLEEP_RESET                   0
#define MAC_PCU_BLUETOOTH_MODE5_USE_BTP_EXT_MSB                      21
#define MAC_PCU_BLUETOOTH_MODE5_USE_BTP_EXT_LSB                      21
#define MAC_PCU_BLUETOOTH_MODE5_USE_BTP_EXT_MASK                     0x00200000
#define MAC_PCU_BLUETOOTH_MODE5_USE_BTP_EXT_GET(x)                   (((x) & MAC_PCU_BLUETOOTH_MODE5_USE_BTP_EXT_MASK) >> MAC_PCU_BLUETOOTH_MODE5_USE_BTP_EXT_LSB)
#define MAC_PCU_BLUETOOTH_MODE5_USE_BTP_EXT_SET(x)                   (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE5_USE_BTP_EXT_LSB) & MAC_PCU_BLUETOOTH_MODE5_USE_BTP_EXT_MASK)
#define MAC_PCU_BLUETOOTH_MODE5_USE_BTP_EXT_RESET                    1
#define MAC_PCU_BLUETOOTH_MODE5_SHARED_RX_MSB                        20
#define MAC_PCU_BLUETOOTH_MODE5_SHARED_RX_LSB                        20
#define MAC_PCU_BLUETOOTH_MODE5_SHARED_RX_MASK                       0x00100000
#define MAC_PCU_BLUETOOTH_MODE5_SHARED_RX_GET(x)                     (((x) & MAC_PCU_BLUETOOTH_MODE5_SHARED_RX_MASK) >> MAC_PCU_BLUETOOTH_MODE5_SHARED_RX_LSB)
#define MAC_PCU_BLUETOOTH_MODE5_SHARED_RX_SET(x)                     (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE5_SHARED_RX_LSB) & MAC_PCU_BLUETOOTH_MODE5_SHARED_RX_MASK)
#define MAC_PCU_BLUETOOTH_MODE5_SHARED_RX_RESET                      0
#define MAC_PCU_BLUETOOTH_MODE5_TIMER_TARGET_MSB                     19
#define MAC_PCU_BLUETOOTH_MODE5_TIMER_TARGET_LSB                     4
#define MAC_PCU_BLUETOOTH_MODE5_TIMER_TARGET_MASK                    0x000ffff0
#define MAC_PCU_BLUETOOTH_MODE5_TIMER_TARGET_GET(x)                  (((x) & MAC_PCU_BLUETOOTH_MODE5_TIMER_TARGET_MASK) >> MAC_PCU_BLUETOOTH_MODE5_TIMER_TARGET_LSB)
#define MAC_PCU_BLUETOOTH_MODE5_TIMER_TARGET_SET(x)                  (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE5_TIMER_TARGET_LSB) & MAC_PCU_BLUETOOTH_MODE5_TIMER_TARGET_MASK)
#define MAC_PCU_BLUETOOTH_MODE5_TIMER_TARGET_RESET                   65535
#define MAC_PCU_BLUETOOTH_MODE5_TX_ON_SRC_MSB                        3
#define MAC_PCU_BLUETOOTH_MODE5_TX_ON_SRC_LSB                        3
#define MAC_PCU_BLUETOOTH_MODE5_TX_ON_SRC_MASK                       0x00000008
#define MAC_PCU_BLUETOOTH_MODE5_TX_ON_SRC_GET(x)                     (((x) & MAC_PCU_BLUETOOTH_MODE5_TX_ON_SRC_MASK) >> MAC_PCU_BLUETOOTH_MODE5_TX_ON_SRC_LSB)
#define MAC_PCU_BLUETOOTH_MODE5_TX_ON_SRC_SET(x)                     (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE5_TX_ON_SRC_LSB) & MAC_PCU_BLUETOOTH_MODE5_TX_ON_SRC_MASK)
#define MAC_PCU_BLUETOOTH_MODE5_TX_ON_SRC_RESET                      0
#define MAC_PCU_BLUETOOTH_MODE5_MCI_WL_LEVEL_MULT_MSB                2
#define MAC_PCU_BLUETOOTH_MODE5_MCI_WL_LEVEL_MULT_LSB                0
#define MAC_PCU_BLUETOOTH_MODE5_MCI_WL_LEVEL_MULT_MASK               0x00000007
#define MAC_PCU_BLUETOOTH_MODE5_MCI_WL_LEVEL_MULT_GET(x)             (((x) & MAC_PCU_BLUETOOTH_MODE5_MCI_WL_LEVEL_MULT_MASK) >> MAC_PCU_BLUETOOTH_MODE5_MCI_WL_LEVEL_MULT_LSB)
#define MAC_PCU_BLUETOOTH_MODE5_MCI_WL_LEVEL_MULT_SET(x)             (((0 | (x)) << MAC_PCU_BLUETOOTH_MODE5_MCI_WL_LEVEL_MULT_LSB) & MAC_PCU_BLUETOOTH_MODE5_MCI_WL_LEVEL_MULT_MASK)
#define MAC_PCU_BLUETOOTH_MODE5_MCI_WL_LEVEL_MULT_RESET              0
#define MAC_PCU_BLUETOOTH_MODE5_ADDRESS                              0x81dc
#define MAC_PCU_BLUETOOTH_MODE5_HW_MASK                              0x01ffffff
#define MAC_PCU_BLUETOOTH_MODE5_SW_MASK                              0x01ffffff
#define MAC_PCU_BLUETOOTH_MODE5_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_BLUETOOTH_MODE5_SW_WRITE_MASK                        0x01ffffff
#define MAC_PCU_BLUETOOTH_MODE5_RSTMASK                              0xffffffff
#define MAC_PCU_BLUETOOTH_MODE5_RESET                                0x012ffff0

// 0x81e4 (MAC_PCU_BT_BT_ASYNC)
#define MAC_PCU_BT_BT_ASYNC_RXLP_WEIGHT_MSB                          15
#define MAC_PCU_BT_BT_ASYNC_RXLP_WEIGHT_LSB                          12
#define MAC_PCU_BT_BT_ASYNC_RXLP_WEIGHT_MASK                         0x0000f000
#define MAC_PCU_BT_BT_ASYNC_RXLP_WEIGHT_GET(x)                       (((x) & MAC_PCU_BT_BT_ASYNC_RXLP_WEIGHT_MASK) >> MAC_PCU_BT_BT_ASYNC_RXLP_WEIGHT_LSB)
#define MAC_PCU_BT_BT_ASYNC_RXLP_WEIGHT_SET(x)                       (((0 | (x)) << MAC_PCU_BT_BT_ASYNC_RXLP_WEIGHT_LSB) & MAC_PCU_BT_BT_ASYNC_RXLP_WEIGHT_MASK)
#define MAC_PCU_BT_BT_ASYNC_RXLP_WEIGHT_RESET                        0
#define MAC_PCU_BT_BT_ASYNC_RXHP_WEIGHT_MSB                          11
#define MAC_PCU_BT_BT_ASYNC_RXHP_WEIGHT_LSB                          8
#define MAC_PCU_BT_BT_ASYNC_RXHP_WEIGHT_MASK                         0x00000f00
#define MAC_PCU_BT_BT_ASYNC_RXHP_WEIGHT_GET(x)                       (((x) & MAC_PCU_BT_BT_ASYNC_RXHP_WEIGHT_MASK) >> MAC_PCU_BT_BT_ASYNC_RXHP_WEIGHT_LSB)
#define MAC_PCU_BT_BT_ASYNC_RXHP_WEIGHT_SET(x)                       (((0 | (x)) << MAC_PCU_BT_BT_ASYNC_RXHP_WEIGHT_LSB) & MAC_PCU_BT_BT_ASYNC_RXHP_WEIGHT_MASK)
#define MAC_PCU_BT_BT_ASYNC_RXHP_WEIGHT_RESET                        0
#define MAC_PCU_BT_BT_ASYNC_TXLP_WEIGHT_MSB                          7
#define MAC_PCU_BT_BT_ASYNC_TXLP_WEIGHT_LSB                          4
#define MAC_PCU_BT_BT_ASYNC_TXLP_WEIGHT_MASK                         0x000000f0
#define MAC_PCU_BT_BT_ASYNC_TXLP_WEIGHT_GET(x)                       (((x) & MAC_PCU_BT_BT_ASYNC_TXLP_WEIGHT_MASK) >> MAC_PCU_BT_BT_ASYNC_TXLP_WEIGHT_LSB)
#define MAC_PCU_BT_BT_ASYNC_TXLP_WEIGHT_SET(x)                       (((0 | (x)) << MAC_PCU_BT_BT_ASYNC_TXLP_WEIGHT_LSB) & MAC_PCU_BT_BT_ASYNC_TXLP_WEIGHT_MASK)
#define MAC_PCU_BT_BT_ASYNC_TXLP_WEIGHT_RESET                        0
#define MAC_PCU_BT_BT_ASYNC_TXHP_WEIGHT_MSB                          3
#define MAC_PCU_BT_BT_ASYNC_TXHP_WEIGHT_LSB                          0
#define MAC_PCU_BT_BT_ASYNC_TXHP_WEIGHT_MASK                         0x0000000f
#define MAC_PCU_BT_BT_ASYNC_TXHP_WEIGHT_GET(x)                       (((x) & MAC_PCU_BT_BT_ASYNC_TXHP_WEIGHT_MASK) >> MAC_PCU_BT_BT_ASYNC_TXHP_WEIGHT_LSB)
#define MAC_PCU_BT_BT_ASYNC_TXHP_WEIGHT_SET(x)                       (((0 | (x)) << MAC_PCU_BT_BT_ASYNC_TXHP_WEIGHT_LSB) & MAC_PCU_BT_BT_ASYNC_TXHP_WEIGHT_MASK)
#define MAC_PCU_BT_BT_ASYNC_TXHP_WEIGHT_RESET                        0
#define MAC_PCU_BT_BT_ASYNC_ADDRESS                                  0x81e4
#define MAC_PCU_BT_BT_ASYNC_HW_MASK                                  0x0000ffff
#define MAC_PCU_BT_BT_ASYNC_SW_MASK                                  0x0000ffff
#define MAC_PCU_BT_BT_ASYNC_HW_WRITE_MASK                            0x00000000
#define MAC_PCU_BT_BT_ASYNC_SW_WRITE_MASK                            0x0000ffff
#define MAC_PCU_BT_BT_ASYNC_RSTMASK                                  0xffffffff
#define MAC_PCU_BT_BT_ASYNC_RESET                                    0x00000000

// 0x81ec (MAC_PCU_TXOP_X)
#define MAC_PCU_TXOP_X_VALUE_MSB                                     7
#define MAC_PCU_TXOP_X_VALUE_LSB                                     0
#define MAC_PCU_TXOP_X_VALUE_MASK                                    0x000000ff
#define MAC_PCU_TXOP_X_VALUE_GET(x)                                  (((x) & MAC_PCU_TXOP_X_VALUE_MASK) >> MAC_PCU_TXOP_X_VALUE_LSB)
#define MAC_PCU_TXOP_X_VALUE_SET(x)                                  (((0 | (x)) << MAC_PCU_TXOP_X_VALUE_LSB) & MAC_PCU_TXOP_X_VALUE_MASK)
#define MAC_PCU_TXOP_X_VALUE_RESET                                   0
#define MAC_PCU_TXOP_X_ADDRESS                                       0x81ec
#define MAC_PCU_TXOP_X_HW_MASK                                       0x000000ff
#define MAC_PCU_TXOP_X_SW_MASK                                       0x000000ff
#define MAC_PCU_TXOP_X_HW_WRITE_MASK                                 0x00000000
#define MAC_PCU_TXOP_X_SW_WRITE_MASK                                 0x000000ff
#define MAC_PCU_TXOP_X_RSTMASK                                       0xffffffff
#define MAC_PCU_TXOP_X_RESET                                         0x00000000

// 0x81f0 (MAC_PCU_TXOP_0_3)
#define MAC_PCU_TXOP_0_3_VALUE_3_MSB                                 31
#define MAC_PCU_TXOP_0_3_VALUE_3_LSB                                 24
#define MAC_PCU_TXOP_0_3_VALUE_3_MASK                                0xff000000
#define MAC_PCU_TXOP_0_3_VALUE_3_GET(x)                              (((x) & MAC_PCU_TXOP_0_3_VALUE_3_MASK) >> MAC_PCU_TXOP_0_3_VALUE_3_LSB)
#define MAC_PCU_TXOP_0_3_VALUE_3_SET(x)                              (((0 | (x)) << MAC_PCU_TXOP_0_3_VALUE_3_LSB) & MAC_PCU_TXOP_0_3_VALUE_3_MASK)
#define MAC_PCU_TXOP_0_3_VALUE_3_RESET                               0
#define MAC_PCU_TXOP_0_3_VALUE_2_MSB                                 23
#define MAC_PCU_TXOP_0_3_VALUE_2_LSB                                 16
#define MAC_PCU_TXOP_0_3_VALUE_2_MASK                                0x00ff0000
#define MAC_PCU_TXOP_0_3_VALUE_2_GET(x)                              (((x) & MAC_PCU_TXOP_0_3_VALUE_2_MASK) >> MAC_PCU_TXOP_0_3_VALUE_2_LSB)
#define MAC_PCU_TXOP_0_3_VALUE_2_SET(x)                              (((0 | (x)) << MAC_PCU_TXOP_0_3_VALUE_2_LSB) & MAC_PCU_TXOP_0_3_VALUE_2_MASK)
#define MAC_PCU_TXOP_0_3_VALUE_2_RESET                               0
#define MAC_PCU_TXOP_0_3_VALUE_1_MSB                                 15
#define MAC_PCU_TXOP_0_3_VALUE_1_LSB                                 8
#define MAC_PCU_TXOP_0_3_VALUE_1_MASK                                0x0000ff00
#define MAC_PCU_TXOP_0_3_VALUE_1_GET(x)                              (((x) & MAC_PCU_TXOP_0_3_VALUE_1_MASK) >> MAC_PCU_TXOP_0_3_VALUE_1_LSB)
#define MAC_PCU_TXOP_0_3_VALUE_1_SET(x)                              (((0 | (x)) << MAC_PCU_TXOP_0_3_VALUE_1_LSB) & MAC_PCU_TXOP_0_3_VALUE_1_MASK)
#define MAC_PCU_TXOP_0_3_VALUE_1_RESET                               0
#define MAC_PCU_TXOP_0_3_VALUE_0_MSB                                 7
#define MAC_PCU_TXOP_0_3_VALUE_0_LSB                                 0
#define MAC_PCU_TXOP_0_3_VALUE_0_MASK                                0x000000ff
#define MAC_PCU_TXOP_0_3_VALUE_0_GET(x)                              (((x) & MAC_PCU_TXOP_0_3_VALUE_0_MASK) >> MAC_PCU_TXOP_0_3_VALUE_0_LSB)
#define MAC_PCU_TXOP_0_3_VALUE_0_SET(x)                              (((0 | (x)) << MAC_PCU_TXOP_0_3_VALUE_0_LSB) & MAC_PCU_TXOP_0_3_VALUE_0_MASK)
#define MAC_PCU_TXOP_0_3_VALUE_0_RESET                               0
#define MAC_PCU_TXOP_0_3_ADDRESS                                     0x81f0
#define MAC_PCU_TXOP_0_3_HW_MASK                                     0xffffffff
#define MAC_PCU_TXOP_0_3_SW_MASK                                     0xffffffff
#define MAC_PCU_TXOP_0_3_HW_WRITE_MASK                               0x00000000
#define MAC_PCU_TXOP_0_3_SW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TXOP_0_3_RSTMASK                                     0xffffffff
#define MAC_PCU_TXOP_0_3_RESET                                       0x00000000

// 0x81f4 (MAC_PCU_TXOP_4_7)
#define MAC_PCU_TXOP_4_7_VALUE_7_MSB                                 31
#define MAC_PCU_TXOP_4_7_VALUE_7_LSB                                 24
#define MAC_PCU_TXOP_4_7_VALUE_7_MASK                                0xff000000
#define MAC_PCU_TXOP_4_7_VALUE_7_GET(x)                              (((x) & MAC_PCU_TXOP_4_7_VALUE_7_MASK) >> MAC_PCU_TXOP_4_7_VALUE_7_LSB)
#define MAC_PCU_TXOP_4_7_VALUE_7_SET(x)                              (((0 | (x)) << MAC_PCU_TXOP_4_7_VALUE_7_LSB) & MAC_PCU_TXOP_4_7_VALUE_7_MASK)
#define MAC_PCU_TXOP_4_7_VALUE_7_RESET                               0
#define MAC_PCU_TXOP_4_7_VALUE_6_MSB                                 23
#define MAC_PCU_TXOP_4_7_VALUE_6_LSB                                 16
#define MAC_PCU_TXOP_4_7_VALUE_6_MASK                                0x00ff0000
#define MAC_PCU_TXOP_4_7_VALUE_6_GET(x)                              (((x) & MAC_PCU_TXOP_4_7_VALUE_6_MASK) >> MAC_PCU_TXOP_4_7_VALUE_6_LSB)
#define MAC_PCU_TXOP_4_7_VALUE_6_SET(x)                              (((0 | (x)) << MAC_PCU_TXOP_4_7_VALUE_6_LSB) & MAC_PCU_TXOP_4_7_VALUE_6_MASK)
#define MAC_PCU_TXOP_4_7_VALUE_6_RESET                               0
#define MAC_PCU_TXOP_4_7_VALUE_5_MSB                                 15
#define MAC_PCU_TXOP_4_7_VALUE_5_LSB                                 8
#define MAC_PCU_TXOP_4_7_VALUE_5_MASK                                0x0000ff00
#define MAC_PCU_TXOP_4_7_VALUE_5_GET(x)                              (((x) & MAC_PCU_TXOP_4_7_VALUE_5_MASK) >> MAC_PCU_TXOP_4_7_VALUE_5_LSB)
#define MAC_PCU_TXOP_4_7_VALUE_5_SET(x)                              (((0 | (x)) << MAC_PCU_TXOP_4_7_VALUE_5_LSB) & MAC_PCU_TXOP_4_7_VALUE_5_MASK)
#define MAC_PCU_TXOP_4_7_VALUE_5_RESET                               0
#define MAC_PCU_TXOP_4_7_VALUE_4_MSB                                 7
#define MAC_PCU_TXOP_4_7_VALUE_4_LSB                                 0
#define MAC_PCU_TXOP_4_7_VALUE_4_MASK                                0x000000ff
#define MAC_PCU_TXOP_4_7_VALUE_4_GET(x)                              (((x) & MAC_PCU_TXOP_4_7_VALUE_4_MASK) >> MAC_PCU_TXOP_4_7_VALUE_4_LSB)
#define MAC_PCU_TXOP_4_7_VALUE_4_SET(x)                              (((0 | (x)) << MAC_PCU_TXOP_4_7_VALUE_4_LSB) & MAC_PCU_TXOP_4_7_VALUE_4_MASK)
#define MAC_PCU_TXOP_4_7_VALUE_4_RESET                               0
#define MAC_PCU_TXOP_4_7_ADDRESS                                     0x81f4
#define MAC_PCU_TXOP_4_7_HW_MASK                                     0xffffffff
#define MAC_PCU_TXOP_4_7_SW_MASK                                     0xffffffff
#define MAC_PCU_TXOP_4_7_HW_WRITE_MASK                               0x00000000
#define MAC_PCU_TXOP_4_7_SW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TXOP_4_7_RSTMASK                                     0xffffffff
#define MAC_PCU_TXOP_4_7_RESET                                       0x00000000

// 0x81f8 (MAC_PCU_TXOP_8_11)
#define MAC_PCU_TXOP_8_11_VALUE_11_MSB                               31
#define MAC_PCU_TXOP_8_11_VALUE_11_LSB                               24
#define MAC_PCU_TXOP_8_11_VALUE_11_MASK                              0xff000000
#define MAC_PCU_TXOP_8_11_VALUE_11_GET(x)                            (((x) & MAC_PCU_TXOP_8_11_VALUE_11_MASK) >> MAC_PCU_TXOP_8_11_VALUE_11_LSB)
#define MAC_PCU_TXOP_8_11_VALUE_11_SET(x)                            (((0 | (x)) << MAC_PCU_TXOP_8_11_VALUE_11_LSB) & MAC_PCU_TXOP_8_11_VALUE_11_MASK)
#define MAC_PCU_TXOP_8_11_VALUE_11_RESET                             0
#define MAC_PCU_TXOP_8_11_VALUE_10_MSB                               23
#define MAC_PCU_TXOP_8_11_VALUE_10_LSB                               16
#define MAC_PCU_TXOP_8_11_VALUE_10_MASK                              0x00ff0000
#define MAC_PCU_TXOP_8_11_VALUE_10_GET(x)                            (((x) & MAC_PCU_TXOP_8_11_VALUE_10_MASK) >> MAC_PCU_TXOP_8_11_VALUE_10_LSB)
#define MAC_PCU_TXOP_8_11_VALUE_10_SET(x)                            (((0 | (x)) << MAC_PCU_TXOP_8_11_VALUE_10_LSB) & MAC_PCU_TXOP_8_11_VALUE_10_MASK)
#define MAC_PCU_TXOP_8_11_VALUE_10_RESET                             0
#define MAC_PCU_TXOP_8_11_VALUE_9_MSB                                15
#define MAC_PCU_TXOP_8_11_VALUE_9_LSB                                8
#define MAC_PCU_TXOP_8_11_VALUE_9_MASK                               0x0000ff00
#define MAC_PCU_TXOP_8_11_VALUE_9_GET(x)                             (((x) & MAC_PCU_TXOP_8_11_VALUE_9_MASK) >> MAC_PCU_TXOP_8_11_VALUE_9_LSB)
#define MAC_PCU_TXOP_8_11_VALUE_9_SET(x)                             (((0 | (x)) << MAC_PCU_TXOP_8_11_VALUE_9_LSB) & MAC_PCU_TXOP_8_11_VALUE_9_MASK)
#define MAC_PCU_TXOP_8_11_VALUE_9_RESET                              0
#define MAC_PCU_TXOP_8_11_VALUE_8_MSB                                7
#define MAC_PCU_TXOP_8_11_VALUE_8_LSB                                0
#define MAC_PCU_TXOP_8_11_VALUE_8_MASK                               0x000000ff
#define MAC_PCU_TXOP_8_11_VALUE_8_GET(x)                             (((x) & MAC_PCU_TXOP_8_11_VALUE_8_MASK) >> MAC_PCU_TXOP_8_11_VALUE_8_LSB)
#define MAC_PCU_TXOP_8_11_VALUE_8_SET(x)                             (((0 | (x)) << MAC_PCU_TXOP_8_11_VALUE_8_LSB) & MAC_PCU_TXOP_8_11_VALUE_8_MASK)
#define MAC_PCU_TXOP_8_11_VALUE_8_RESET                              0
#define MAC_PCU_TXOP_8_11_ADDRESS                                    0x81f8
#define MAC_PCU_TXOP_8_11_HW_MASK                                    0xffffffff
#define MAC_PCU_TXOP_8_11_SW_MASK                                    0xffffffff
#define MAC_PCU_TXOP_8_11_HW_WRITE_MASK                              0x00000000
#define MAC_PCU_TXOP_8_11_SW_WRITE_MASK                              0xffffffff
#define MAC_PCU_TXOP_8_11_RSTMASK                                    0xffffffff
#define MAC_PCU_TXOP_8_11_RESET                                      0x00000000

// 0x81fc (MAC_PCU_TXOP_12_15)
#define MAC_PCU_TXOP_12_15_VALUE_15_MSB                              31
#define MAC_PCU_TXOP_12_15_VALUE_15_LSB                              24
#define MAC_PCU_TXOP_12_15_VALUE_15_MASK                             0xff000000
#define MAC_PCU_TXOP_12_15_VALUE_15_GET(x)                           (((x) & MAC_PCU_TXOP_12_15_VALUE_15_MASK) >> MAC_PCU_TXOP_12_15_VALUE_15_LSB)
#define MAC_PCU_TXOP_12_15_VALUE_15_SET(x)                           (((0 | (x)) << MAC_PCU_TXOP_12_15_VALUE_15_LSB) & MAC_PCU_TXOP_12_15_VALUE_15_MASK)
#define MAC_PCU_TXOP_12_15_VALUE_15_RESET                            0
#define MAC_PCU_TXOP_12_15_VALUE_14_MSB                              23
#define MAC_PCU_TXOP_12_15_VALUE_14_LSB                              16
#define MAC_PCU_TXOP_12_15_VALUE_14_MASK                             0x00ff0000
#define MAC_PCU_TXOP_12_15_VALUE_14_GET(x)                           (((x) & MAC_PCU_TXOP_12_15_VALUE_14_MASK) >> MAC_PCU_TXOP_12_15_VALUE_14_LSB)
#define MAC_PCU_TXOP_12_15_VALUE_14_SET(x)                           (((0 | (x)) << MAC_PCU_TXOP_12_15_VALUE_14_LSB) & MAC_PCU_TXOP_12_15_VALUE_14_MASK)
#define MAC_PCU_TXOP_12_15_VALUE_14_RESET                            0
#define MAC_PCU_TXOP_12_15_VALUE_13_MSB                              15
#define MAC_PCU_TXOP_12_15_VALUE_13_LSB                              8
#define MAC_PCU_TXOP_12_15_VALUE_13_MASK                             0x0000ff00
#define MAC_PCU_TXOP_12_15_VALUE_13_GET(x)                           (((x) & MAC_PCU_TXOP_12_15_VALUE_13_MASK) >> MAC_PCU_TXOP_12_15_VALUE_13_LSB)
#define MAC_PCU_TXOP_12_15_VALUE_13_SET(x)                           (((0 | (x)) << MAC_PCU_TXOP_12_15_VALUE_13_LSB) & MAC_PCU_TXOP_12_15_VALUE_13_MASK)
#define MAC_PCU_TXOP_12_15_VALUE_13_RESET                            0
#define MAC_PCU_TXOP_12_15_VALUE_12_MSB                              7
#define MAC_PCU_TXOP_12_15_VALUE_12_LSB                              0
#define MAC_PCU_TXOP_12_15_VALUE_12_MASK                             0x000000ff
#define MAC_PCU_TXOP_12_15_VALUE_12_GET(x)                           (((x) & MAC_PCU_TXOP_12_15_VALUE_12_MASK) >> MAC_PCU_TXOP_12_15_VALUE_12_LSB)
#define MAC_PCU_TXOP_12_15_VALUE_12_SET(x)                           (((0 | (x)) << MAC_PCU_TXOP_12_15_VALUE_12_LSB) & MAC_PCU_TXOP_12_15_VALUE_12_MASK)
#define MAC_PCU_TXOP_12_15_VALUE_12_RESET                            0
#define MAC_PCU_TXOP_12_15_ADDRESS                                   0x81fc
#define MAC_PCU_TXOP_12_15_HW_MASK                                   0xffffffff
#define MAC_PCU_TXOP_12_15_SW_MASK                                   0xffffffff
#define MAC_PCU_TXOP_12_15_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_TXOP_12_15_SW_WRITE_MASK                             0xffffffff
#define MAC_PCU_TXOP_12_15_RSTMASK                                   0xffffffff
#define MAC_PCU_TXOP_12_15_RESET                                     0x00000000

// 0x8200 (MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB)
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_VALUE_MSB        31
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_VALUE_LSB        0
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_VALUE_MASK       0xffffffff
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_VALUE_GET(x)     (((x) & MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_VALUE_MASK) >> MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_VALUE_LSB)
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_VALUE_SET(x)     (((0 | (x)) << MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_VALUE_LSB) & MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_VALUE_MASK)
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_VALUE_RESET      32
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_ADDRESS          0x8200
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_HW_MASK          0xffffffff
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_SW_MASK          0xffffffff
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_HW_WRITE_MASK    0x00000000
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_SW_WRITE_MASK    0xffffffff
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_RSTMASK          0xffffffff
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB_RESET            0x00000020

// 0x8204 (MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB)
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_VALUE_MSB        31
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_VALUE_LSB        0
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_VALUE_MASK       0xffffffff
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_VALUE_GET(x)     (((x) & MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_VALUE_MASK) >> MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_VALUE_LSB)
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_VALUE_SET(x)     (((0 | (x)) << MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_VALUE_LSB) & MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_VALUE_MASK)
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_VALUE_RESET      0
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_ADDRESS          0x8204
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_HW_MASK          0xffffffff
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_SW_MASK          0xffffffff
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_HW_WRITE_MASK    0x00000000
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_SW_WRITE_MASK    0xffffffff
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_RSTMASK          0xffffffff
#define MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB_RESET            0x00000000

// 0x8208 (MAC_PCU_TDMA_SLOT_ALERT_CNTL)
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_VALUE_MSB                       15
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_VALUE_LSB                       0
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_VALUE_MASK                      0x0000ffff
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_VALUE_GET(x)                    (((x) & MAC_PCU_TDMA_SLOT_ALERT_CNTL_VALUE_MASK) >> MAC_PCU_TDMA_SLOT_ALERT_CNTL_VALUE_LSB)
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_VALUE_SET(x)                    (((0 | (x)) << MAC_PCU_TDMA_SLOT_ALERT_CNTL_VALUE_LSB) & MAC_PCU_TDMA_SLOT_ALERT_CNTL_VALUE_MASK)
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_VALUE_RESET                     15
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_ADDRESS                         0x8208
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_HW_MASK                         0x0000ffff
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_SW_MASK                         0x0000ffff
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_HW_WRITE_MASK                   0x00000000
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_SW_WRITE_MASK                   0x0000ffff
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_RSTMASK                         0xffffffff
#define MAC_PCU_TDMA_SLOT_ALERT_CNTL_RESET                           0x0000000f

// 0x825c (MAC_PCU_WOW1)
#define MAC_PCU_WOW1_CW_BITS_MSB                                     31
#define MAC_PCU_WOW1_CW_BITS_LSB                                     28
#define MAC_PCU_WOW1_CW_BITS_MASK                                    0xf0000000
#define MAC_PCU_WOW1_CW_BITS_GET(x)                                  (((x) & MAC_PCU_WOW1_CW_BITS_MASK) >> MAC_PCU_WOW1_CW_BITS_LSB)
#define MAC_PCU_WOW1_CW_BITS_SET(x)                                  (((0 | (x)) << MAC_PCU_WOW1_CW_BITS_LSB) & MAC_PCU_WOW1_CW_BITS_MASK)
#define MAC_PCU_WOW1_CW_BITS_RESET                                   4
#define MAC_PCU_WOW1_BEACON_FAIL_MSB                                 21
#define MAC_PCU_WOW1_BEACON_FAIL_LSB                                 21
#define MAC_PCU_WOW1_BEACON_FAIL_MASK                                0x00200000
#define MAC_PCU_WOW1_BEACON_FAIL_GET(x)                              (((x) & MAC_PCU_WOW1_BEACON_FAIL_MASK) >> MAC_PCU_WOW1_BEACON_FAIL_LSB)
#define MAC_PCU_WOW1_BEACON_FAIL_SET(x)                              (((0 | (x)) << MAC_PCU_WOW1_BEACON_FAIL_LSB) & MAC_PCU_WOW1_BEACON_FAIL_MASK)
#define MAC_PCU_WOW1_BEACON_FAIL_RESET                               0
#define MAC_PCU_WOW1_KEEP_ALIVE_FAIL_MSB                             20
#define MAC_PCU_WOW1_KEEP_ALIVE_FAIL_LSB                             20
#define MAC_PCU_WOW1_KEEP_ALIVE_FAIL_MASK                            0x00100000
#define MAC_PCU_WOW1_KEEP_ALIVE_FAIL_GET(x)                          (((x) & MAC_PCU_WOW1_KEEP_ALIVE_FAIL_MASK) >> MAC_PCU_WOW1_KEEP_ALIVE_FAIL_LSB)
#define MAC_PCU_WOW1_KEEP_ALIVE_FAIL_SET(x)                          (((0 | (x)) << MAC_PCU_WOW1_KEEP_ALIVE_FAIL_LSB) & MAC_PCU_WOW1_KEEP_ALIVE_FAIL_MASK)
#define MAC_PCU_WOW1_KEEP_ALIVE_FAIL_RESET                           0
#define MAC_PCU_WOW1_INTR_DETECT_MSB                                 19
#define MAC_PCU_WOW1_INTR_DETECT_LSB                                 19
#define MAC_PCU_WOW1_INTR_DETECT_MASK                                0x00080000
#define MAC_PCU_WOW1_INTR_DETECT_GET(x)                              (((x) & MAC_PCU_WOW1_INTR_DETECT_MASK) >> MAC_PCU_WOW1_INTR_DETECT_LSB)
#define MAC_PCU_WOW1_INTR_DETECT_SET(x)                              (((0 | (x)) << MAC_PCU_WOW1_INTR_DETECT_LSB) & MAC_PCU_WOW1_INTR_DETECT_MASK)
#define MAC_PCU_WOW1_INTR_DETECT_RESET                               0
#define MAC_PCU_WOW1_INTR_ENABLE_MSB                                 18
#define MAC_PCU_WOW1_INTR_ENABLE_LSB                                 18
#define MAC_PCU_WOW1_INTR_ENABLE_MASK                                0x00040000
#define MAC_PCU_WOW1_INTR_ENABLE_GET(x)                              (((x) & MAC_PCU_WOW1_INTR_ENABLE_MASK) >> MAC_PCU_WOW1_INTR_ENABLE_LSB)
#define MAC_PCU_WOW1_INTR_ENABLE_SET(x)                              (((0 | (x)) << MAC_PCU_WOW1_INTR_ENABLE_LSB) & MAC_PCU_WOW1_INTR_ENABLE_MASK)
#define MAC_PCU_WOW1_INTR_ENABLE_RESET                               0
#define MAC_PCU_WOW1_MAGIC_DETECT_MSB                                17
#define MAC_PCU_WOW1_MAGIC_DETECT_LSB                                17
#define MAC_PCU_WOW1_MAGIC_DETECT_MASK                               0x00020000
#define MAC_PCU_WOW1_MAGIC_DETECT_GET(x)                             (((x) & MAC_PCU_WOW1_MAGIC_DETECT_MASK) >> MAC_PCU_WOW1_MAGIC_DETECT_LSB)
#define MAC_PCU_WOW1_MAGIC_DETECT_SET(x)                             (((0 | (x)) << MAC_PCU_WOW1_MAGIC_DETECT_LSB) & MAC_PCU_WOW1_MAGIC_DETECT_MASK)
#define MAC_PCU_WOW1_MAGIC_DETECT_RESET                              0
#define MAC_PCU_WOW1_MAGIC_ENABLE_MSB                                16
#define MAC_PCU_WOW1_MAGIC_ENABLE_LSB                                16
#define MAC_PCU_WOW1_MAGIC_ENABLE_MASK                               0x00010000
#define MAC_PCU_WOW1_MAGIC_ENABLE_GET(x)                             (((x) & MAC_PCU_WOW1_MAGIC_ENABLE_MASK) >> MAC_PCU_WOW1_MAGIC_ENABLE_LSB)
#define MAC_PCU_WOW1_MAGIC_ENABLE_SET(x)                             (((0 | (x)) << MAC_PCU_WOW1_MAGIC_ENABLE_LSB) & MAC_PCU_WOW1_MAGIC_ENABLE_MASK)
#define MAC_PCU_WOW1_MAGIC_ENABLE_RESET                              0
#define MAC_PCU_WOW1_PATTERN_DETECT_MSB                              15
#define MAC_PCU_WOW1_PATTERN_DETECT_LSB                              8
#define MAC_PCU_WOW1_PATTERN_DETECT_MASK                             0x0000ff00
#define MAC_PCU_WOW1_PATTERN_DETECT_GET(x)                           (((x) & MAC_PCU_WOW1_PATTERN_DETECT_MASK) >> MAC_PCU_WOW1_PATTERN_DETECT_LSB)
#define MAC_PCU_WOW1_PATTERN_DETECT_SET(x)                           (((0 | (x)) << MAC_PCU_WOW1_PATTERN_DETECT_LSB) & MAC_PCU_WOW1_PATTERN_DETECT_MASK)
#define MAC_PCU_WOW1_PATTERN_DETECT_RESET                            0
#define MAC_PCU_WOW1_PATTERN_ENABLE_MSB                              7
#define MAC_PCU_WOW1_PATTERN_ENABLE_LSB                              0
#define MAC_PCU_WOW1_PATTERN_ENABLE_MASK                             0x000000ff
#define MAC_PCU_WOW1_PATTERN_ENABLE_GET(x)                           (((x) & MAC_PCU_WOW1_PATTERN_ENABLE_MASK) >> MAC_PCU_WOW1_PATTERN_ENABLE_LSB)
#define MAC_PCU_WOW1_PATTERN_ENABLE_SET(x)                           (((0 | (x)) << MAC_PCU_WOW1_PATTERN_ENABLE_LSB) & MAC_PCU_WOW1_PATTERN_ENABLE_MASK)
#define MAC_PCU_WOW1_PATTERN_ENABLE_RESET                            0
#define MAC_PCU_WOW1_ADDRESS                                         0x825c
#define MAC_PCU_WOW1_HW_MASK                                         0xf03fffff
#define MAC_PCU_WOW1_SW_MASK                                         0xf03fffff
#define MAC_PCU_WOW1_HW_WRITE_MASK                                   0x003aff00
#define MAC_PCU_WOW1_SW_WRITE_MASK                                   0xf00500ff
#define MAC_PCU_WOW1_RSTMASK                                         0xffffffff
#define MAC_PCU_WOW1_RESET                                           0x40000000

// 0x8260 (MAC_PCU_WOW2)
#define MAC_PCU_WOW2_TRY_CNT_MSB                                     23
#define MAC_PCU_WOW2_TRY_CNT_LSB                                     16
#define MAC_PCU_WOW2_TRY_CNT_MASK                                    0x00ff0000
#define MAC_PCU_WOW2_TRY_CNT_GET(x)                                  (((x) & MAC_PCU_WOW2_TRY_CNT_MASK) >> MAC_PCU_WOW2_TRY_CNT_LSB)
#define MAC_PCU_WOW2_TRY_CNT_SET(x)                                  (((0 | (x)) << MAC_PCU_WOW2_TRY_CNT_LSB) & MAC_PCU_WOW2_TRY_CNT_MASK)
#define MAC_PCU_WOW2_TRY_CNT_RESET                                   8
#define MAC_PCU_WOW2_SLOT_MSB                                        15
#define MAC_PCU_WOW2_SLOT_LSB                                        8
#define MAC_PCU_WOW2_SLOT_MASK                                       0x0000ff00
#define MAC_PCU_WOW2_SLOT_GET(x)                                     (((x) & MAC_PCU_WOW2_SLOT_MASK) >> MAC_PCU_WOW2_SLOT_LSB)
#define MAC_PCU_WOW2_SLOT_SET(x)                                     (((0 | (x)) << MAC_PCU_WOW2_SLOT_LSB) & MAC_PCU_WOW2_SLOT_MASK)
#define MAC_PCU_WOW2_SLOT_RESET                                      9
#define MAC_PCU_WOW2_AIFS_MSB                                        7
#define MAC_PCU_WOW2_AIFS_LSB                                        0
#define MAC_PCU_WOW2_AIFS_MASK                                       0x000000ff
#define MAC_PCU_WOW2_AIFS_GET(x)                                     (((x) & MAC_PCU_WOW2_AIFS_MASK) >> MAC_PCU_WOW2_AIFS_LSB)
#define MAC_PCU_WOW2_AIFS_SET(x)                                     (((0 | (x)) << MAC_PCU_WOW2_AIFS_LSB) & MAC_PCU_WOW2_AIFS_MASK)
#define MAC_PCU_WOW2_AIFS_RESET                                      34
#define MAC_PCU_WOW2_ADDRESS                                         0x8260
#define MAC_PCU_WOW2_HW_MASK                                         0x00ffffff
#define MAC_PCU_WOW2_SW_MASK                                         0x00ffffff
#define MAC_PCU_WOW2_HW_WRITE_MASK                                   0x00000000
#define MAC_PCU_WOW2_SW_WRITE_MASK                                   0x00ffffff
#define MAC_PCU_WOW2_RSTMASK                                         0xffffffff
#define MAC_PCU_WOW2_RESET                                           0x00080922

// 0x8264 (MAC_PCU_LOGIC_ANALYZER)
#define MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_MSB                         31
#define MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_LSB                         18
#define MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_MASK                        0xfffc0000
#define MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_GET(x)                      (((x) & MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_MASK) >> MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_LSB)
#define MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_SET(x)                      (((0 | (x)) << MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_LSB) & MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_MASK)
#define MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_RESET                       9840
#define MAC_PCU_LOGIC_ANALYZER_INT_ADDR_MSB                          17
#define MAC_PCU_LOGIC_ANALYZER_INT_ADDR_LSB                          8
#define MAC_PCU_LOGIC_ANALYZER_INT_ADDR_MASK                         0x0003ff00
#define MAC_PCU_LOGIC_ANALYZER_INT_ADDR_GET(x)                       (((x) & MAC_PCU_LOGIC_ANALYZER_INT_ADDR_MASK) >> MAC_PCU_LOGIC_ANALYZER_INT_ADDR_LSB)
#define MAC_PCU_LOGIC_ANALYZER_INT_ADDR_SET(x)                       (((0 | (x)) << MAC_PCU_LOGIC_ANALYZER_INT_ADDR_LSB) & MAC_PCU_LOGIC_ANALYZER_INT_ADDR_MASK)
#define MAC_PCU_LOGIC_ANALYZER_INT_ADDR_RESET                        0
#define MAC_PCU_LOGIC_ANALYZER_QCU_SEL_MSB                           7
#define MAC_PCU_LOGIC_ANALYZER_QCU_SEL_LSB                           4
#define MAC_PCU_LOGIC_ANALYZER_QCU_SEL_MASK                          0x000000f0
#define MAC_PCU_LOGIC_ANALYZER_QCU_SEL_GET(x)                        (((x) & MAC_PCU_LOGIC_ANALYZER_QCU_SEL_MASK) >> MAC_PCU_LOGIC_ANALYZER_QCU_SEL_LSB)
#define MAC_PCU_LOGIC_ANALYZER_QCU_SEL_SET(x)                        (((0 | (x)) << MAC_PCU_LOGIC_ANALYZER_QCU_SEL_LSB) & MAC_PCU_LOGIC_ANALYZER_QCU_SEL_MASK)
#define MAC_PCU_LOGIC_ANALYZER_QCU_SEL_RESET                         1
#define MAC_PCU_LOGIC_ANALYZER_ENABLE_MSB                            3
#define MAC_PCU_LOGIC_ANALYZER_ENABLE_LSB                            3
#define MAC_PCU_LOGIC_ANALYZER_ENABLE_MASK                           0x00000008
#define MAC_PCU_LOGIC_ANALYZER_ENABLE_GET(x)                         (((x) & MAC_PCU_LOGIC_ANALYZER_ENABLE_MASK) >> MAC_PCU_LOGIC_ANALYZER_ENABLE_LSB)
#define MAC_PCU_LOGIC_ANALYZER_ENABLE_SET(x)                         (((0 | (x)) << MAC_PCU_LOGIC_ANALYZER_ENABLE_LSB) & MAC_PCU_LOGIC_ANALYZER_ENABLE_MASK)
#define MAC_PCU_LOGIC_ANALYZER_ENABLE_RESET                          0
#define MAC_PCU_LOGIC_ANALYZER_STATE_MSB                             2
#define MAC_PCU_LOGIC_ANALYZER_STATE_LSB                             2
#define MAC_PCU_LOGIC_ANALYZER_STATE_MASK                            0x00000004
#define MAC_PCU_LOGIC_ANALYZER_STATE_GET(x)                          (((x) & MAC_PCU_LOGIC_ANALYZER_STATE_MASK) >> MAC_PCU_LOGIC_ANALYZER_STATE_LSB)
#define MAC_PCU_LOGIC_ANALYZER_STATE_SET(x)                          (((0 | (x)) << MAC_PCU_LOGIC_ANALYZER_STATE_LSB) & MAC_PCU_LOGIC_ANALYZER_STATE_MASK)
#define MAC_PCU_LOGIC_ANALYZER_STATE_RESET                           0
#define MAC_PCU_LOGIC_ANALYZER_CLEAR_MSB                             1
#define MAC_PCU_LOGIC_ANALYZER_CLEAR_LSB                             1
#define MAC_PCU_LOGIC_ANALYZER_CLEAR_MASK                            0x00000002
#define MAC_PCU_LOGIC_ANALYZER_CLEAR_GET(x)                          (((x) & MAC_PCU_LOGIC_ANALYZER_CLEAR_MASK) >> MAC_PCU_LOGIC_ANALYZER_CLEAR_LSB)
#define MAC_PCU_LOGIC_ANALYZER_CLEAR_SET(x)                          (((0 | (x)) << MAC_PCU_LOGIC_ANALYZER_CLEAR_LSB) & MAC_PCU_LOGIC_ANALYZER_CLEAR_MASK)
#define MAC_PCU_LOGIC_ANALYZER_CLEAR_RESET                           0
#define MAC_PCU_LOGIC_ANALYZER_HOLD_MSB                              0
#define MAC_PCU_LOGIC_ANALYZER_HOLD_LSB                              0
#define MAC_PCU_LOGIC_ANALYZER_HOLD_MASK                             0x00000001
#define MAC_PCU_LOGIC_ANALYZER_HOLD_GET(x)                           (((x) & MAC_PCU_LOGIC_ANALYZER_HOLD_MASK) >> MAC_PCU_LOGIC_ANALYZER_HOLD_LSB)
#define MAC_PCU_LOGIC_ANALYZER_HOLD_SET(x)                           (((0 | (x)) << MAC_PCU_LOGIC_ANALYZER_HOLD_LSB) & MAC_PCU_LOGIC_ANALYZER_HOLD_MASK)
#define MAC_PCU_LOGIC_ANALYZER_HOLD_RESET                            0
#define MAC_PCU_LOGIC_ANALYZER_ADDRESS                               0x8264
#define MAC_PCU_LOGIC_ANALYZER_HW_MASK                               0xffffffff
#define MAC_PCU_LOGIC_ANALYZER_SW_MASK                               0xffffffff
#define MAC_PCU_LOGIC_ANALYZER_HW_WRITE_MASK                         0x0003ff07
#define MAC_PCU_LOGIC_ANALYZER_SW_WRITE_MASK                         0xfffc00fb
#define MAC_PCU_LOGIC_ANALYZER_RSTMASK                               0xffffffff
#define MAC_PCU_LOGIC_ANALYZER_RESET                                 0x99c00010

// 0x8268 (MAC_PCU_LOGIC_ANALYZER_32L)
#define MAC_PCU_LOGIC_ANALYZER_32L_MASK_MSB                          31
#define MAC_PCU_LOGIC_ANALYZER_32L_MASK_LSB                          0
#define MAC_PCU_LOGIC_ANALYZER_32L_MASK_MASK                         0xffffffff
#define MAC_PCU_LOGIC_ANALYZER_32L_MASK_GET(x)                       (((x) & MAC_PCU_LOGIC_ANALYZER_32L_MASK_MASK) >> MAC_PCU_LOGIC_ANALYZER_32L_MASK_LSB)
#define MAC_PCU_LOGIC_ANALYZER_32L_MASK_SET(x)                       (((0 | (x)) << MAC_PCU_LOGIC_ANALYZER_32L_MASK_LSB) & MAC_PCU_LOGIC_ANALYZER_32L_MASK_MASK)
#define MAC_PCU_LOGIC_ANALYZER_32L_MASK_RESET                        4294967295
#define MAC_PCU_LOGIC_ANALYZER_32L_ADDRESS                           0x8268
#define MAC_PCU_LOGIC_ANALYZER_32L_HW_MASK                           0xffffffff
#define MAC_PCU_LOGIC_ANALYZER_32L_SW_MASK                           0xffffffff
#define MAC_PCU_LOGIC_ANALYZER_32L_HW_WRITE_MASK                     0x00000000
#define MAC_PCU_LOGIC_ANALYZER_32L_SW_WRITE_MASK                     0xffffffff
#define MAC_PCU_LOGIC_ANALYZER_32L_RSTMASK                           0xffffffff
#define MAC_PCU_LOGIC_ANALYZER_32L_RESET                             0xffffffff

// 0x826c (MAC_PCU_LOGIC_ANALYZER_16U)
#define MAC_PCU_LOGIC_ANALYZER_16U_MASK_MSB                          15
#define MAC_PCU_LOGIC_ANALYZER_16U_MASK_LSB                          0
#define MAC_PCU_LOGIC_ANALYZER_16U_MASK_MASK                         0x0000ffff
#define MAC_PCU_LOGIC_ANALYZER_16U_MASK_GET(x)                       (((x) & MAC_PCU_LOGIC_ANALYZER_16U_MASK_MASK) >> MAC_PCU_LOGIC_ANALYZER_16U_MASK_LSB)
#define MAC_PCU_LOGIC_ANALYZER_16U_MASK_SET(x)                       (((0 | (x)) << MAC_PCU_LOGIC_ANALYZER_16U_MASK_LSB) & MAC_PCU_LOGIC_ANALYZER_16U_MASK_MASK)
#define MAC_PCU_LOGIC_ANALYZER_16U_MASK_RESET                        65535
#define MAC_PCU_LOGIC_ANALYZER_16U_ADDRESS                           0x826c
#define MAC_PCU_LOGIC_ANALYZER_16U_HW_MASK                           0x0000ffff
#define MAC_PCU_LOGIC_ANALYZER_16U_SW_MASK                           0x0000ffff
#define MAC_PCU_LOGIC_ANALYZER_16U_HW_WRITE_MASK                     0x00000000
#define MAC_PCU_LOGIC_ANALYZER_16U_SW_WRITE_MASK                     0x0000ffff
#define MAC_PCU_LOGIC_ANALYZER_16U_RSTMASK                           0xffffffff
#define MAC_PCU_LOGIC_ANALYZER_16U_RESET                             0x0000ffff

// 0x8270 (MAC_PCU_WOW3_BEACON_FAIL)
#define MAC_PCU_WOW3_BEACON_FAIL_ENABLE_MSB                          0
#define MAC_PCU_WOW3_BEACON_FAIL_ENABLE_LSB                          0
#define MAC_PCU_WOW3_BEACON_FAIL_ENABLE_MASK                         0x00000001
#define MAC_PCU_WOW3_BEACON_FAIL_ENABLE_GET(x)                       (((x) & MAC_PCU_WOW3_BEACON_FAIL_ENABLE_MASK) >> MAC_PCU_WOW3_BEACON_FAIL_ENABLE_LSB)
#define MAC_PCU_WOW3_BEACON_FAIL_ENABLE_SET(x)                       (((0 | (x)) << MAC_PCU_WOW3_BEACON_FAIL_ENABLE_LSB) & MAC_PCU_WOW3_BEACON_FAIL_ENABLE_MASK)
#define MAC_PCU_WOW3_BEACON_FAIL_ENABLE_RESET                        0
#define MAC_PCU_WOW3_BEACON_FAIL_ADDRESS                             0x8270
#define MAC_PCU_WOW3_BEACON_FAIL_HW_MASK                             0x00000001
#define MAC_PCU_WOW3_BEACON_FAIL_SW_MASK                             0x00000001
#define MAC_PCU_WOW3_BEACON_FAIL_HW_WRITE_MASK                       0x00000000
#define MAC_PCU_WOW3_BEACON_FAIL_SW_WRITE_MASK                       0x00000001
#define MAC_PCU_WOW3_BEACON_FAIL_RSTMASK                             0xffffffff
#define MAC_PCU_WOW3_BEACON_FAIL_RESET                               0x00000000

// 0x8274 (MAC_PCU_WOW3_BEACON)
#define MAC_PCU_WOW3_BEACON_TIMEOUT_MSB                              31
#define MAC_PCU_WOW3_BEACON_TIMEOUT_LSB                              0
#define MAC_PCU_WOW3_BEACON_TIMEOUT_MASK                             0xffffffff
#define MAC_PCU_WOW3_BEACON_TIMEOUT_GET(x)                           (((x) & MAC_PCU_WOW3_BEACON_TIMEOUT_MASK) >> MAC_PCU_WOW3_BEACON_TIMEOUT_LSB)
#define MAC_PCU_WOW3_BEACON_TIMEOUT_SET(x)                           (((0 | (x)) << MAC_PCU_WOW3_BEACON_TIMEOUT_LSB) & MAC_PCU_WOW3_BEACON_TIMEOUT_MASK)
#define MAC_PCU_WOW3_BEACON_TIMEOUT_RESET                            1073741824
#define MAC_PCU_WOW3_BEACON_ADDRESS                                  0x8274
#define MAC_PCU_WOW3_BEACON_HW_MASK                                  0xffffffff
#define MAC_PCU_WOW3_BEACON_SW_MASK                                  0xffffffff
#define MAC_PCU_WOW3_BEACON_HW_WRITE_MASK                            0x00000000
#define MAC_PCU_WOW3_BEACON_SW_WRITE_MASK                            0xffffffff
#define MAC_PCU_WOW3_BEACON_RSTMASK                                  0xffffffff
#define MAC_PCU_WOW3_BEACON_RESET                                    0x40000000

// 0x8278 (MAC_PCU_WOW3_KEEP_ALIVE)
#define MAC_PCU_WOW3_KEEP_ALIVE_TIMEOUT_MSB                          31
#define MAC_PCU_WOW3_KEEP_ALIVE_TIMEOUT_LSB                          0
#define MAC_PCU_WOW3_KEEP_ALIVE_TIMEOUT_MASK                         0xffffffff
#define MAC_PCU_WOW3_KEEP_ALIVE_TIMEOUT_GET(x)                       (((x) & MAC_PCU_WOW3_KEEP_ALIVE_TIMEOUT_MASK) >> MAC_PCU_WOW3_KEEP_ALIVE_TIMEOUT_LSB)
#define MAC_PCU_WOW3_KEEP_ALIVE_TIMEOUT_SET(x)                       (((0 | (x)) << MAC_PCU_WOW3_KEEP_ALIVE_TIMEOUT_LSB) & MAC_PCU_WOW3_KEEP_ALIVE_TIMEOUT_MASK)
#define MAC_PCU_WOW3_KEEP_ALIVE_TIMEOUT_RESET                        4080000
#define MAC_PCU_WOW3_KEEP_ALIVE_ADDRESS                              0x8278
#define MAC_PCU_WOW3_KEEP_ALIVE_HW_MASK                              0xffffffff
#define MAC_PCU_WOW3_KEEP_ALIVE_SW_MASK                              0xffffffff
#define MAC_PCU_WOW3_KEEP_ALIVE_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_WOW3_KEEP_ALIVE_SW_WRITE_MASK                        0xffffffff
#define MAC_PCU_WOW3_KEEP_ALIVE_RSTMASK                              0xffffffff
#define MAC_PCU_WOW3_KEEP_ALIVE_RESET                                0x003e4180

// 0x827c (MAC_PCU_WOW_KA)
#define MAC_PCU_WOW_KA_BKOFF_CS_ENABLE_MSB                           2
#define MAC_PCU_WOW_KA_BKOFF_CS_ENABLE_LSB                           2
#define MAC_PCU_WOW_KA_BKOFF_CS_ENABLE_MASK                          0x00000004
#define MAC_PCU_WOW_KA_BKOFF_CS_ENABLE_GET(x)                        (((x) & MAC_PCU_WOW_KA_BKOFF_CS_ENABLE_MASK) >> MAC_PCU_WOW_KA_BKOFF_CS_ENABLE_LSB)
#define MAC_PCU_WOW_KA_BKOFF_CS_ENABLE_SET(x)                        (((0 | (x)) << MAC_PCU_WOW_KA_BKOFF_CS_ENABLE_LSB) & MAC_PCU_WOW_KA_BKOFF_CS_ENABLE_MASK)
#define MAC_PCU_WOW_KA_BKOFF_CS_ENABLE_RESET                         1
#define MAC_PCU_WOW_KA_FAIL_DISABLE_MSB                              1
#define MAC_PCU_WOW_KA_FAIL_DISABLE_LSB                              1
#define MAC_PCU_WOW_KA_FAIL_DISABLE_MASK                             0x00000002
#define MAC_PCU_WOW_KA_FAIL_DISABLE_GET(x)                           (((x) & MAC_PCU_WOW_KA_FAIL_DISABLE_MASK) >> MAC_PCU_WOW_KA_FAIL_DISABLE_LSB)
#define MAC_PCU_WOW_KA_FAIL_DISABLE_SET(x)                           (((0 | (x)) << MAC_PCU_WOW_KA_FAIL_DISABLE_LSB) & MAC_PCU_WOW_KA_FAIL_DISABLE_MASK)
#define MAC_PCU_WOW_KA_FAIL_DISABLE_RESET                            0
#define MAC_PCU_WOW_KA_AUTO_DISABLE_MSB                              0
#define MAC_PCU_WOW_KA_AUTO_DISABLE_LSB                              0
#define MAC_PCU_WOW_KA_AUTO_DISABLE_MASK                             0x00000001
#define MAC_PCU_WOW_KA_AUTO_DISABLE_GET(x)                           (((x) & MAC_PCU_WOW_KA_AUTO_DISABLE_MASK) >> MAC_PCU_WOW_KA_AUTO_DISABLE_LSB)
#define MAC_PCU_WOW_KA_AUTO_DISABLE_SET(x)                           (((0 | (x)) << MAC_PCU_WOW_KA_AUTO_DISABLE_LSB) & MAC_PCU_WOW_KA_AUTO_DISABLE_MASK)
#define MAC_PCU_WOW_KA_AUTO_DISABLE_RESET                            0
#define MAC_PCU_WOW_KA_ADDRESS                                       0x827c
#define MAC_PCU_WOW_KA_HW_MASK                                       0x00000007
#define MAC_PCU_WOW_KA_SW_MASK                                       0x00000007
#define MAC_PCU_WOW_KA_HW_WRITE_MASK                                 0x00000000
#define MAC_PCU_WOW_KA_SW_WRITE_MASK                                 0x00000007
#define MAC_PCU_WOW_KA_RSTMASK                                       0xffffffff
#define MAC_PCU_WOW_KA_RESET                                         0x00000004

// 0x8284 (PCU_1US)
#define PCU_1US_SCALER_MSB                                           6
#define PCU_1US_SCALER_LSB                                           0
#define PCU_1US_SCALER_MASK                                          0x0000007f
#define PCU_1US_SCALER_GET(x)                                        (((x) & PCU_1US_SCALER_MASK) >> PCU_1US_SCALER_LSB)
#define PCU_1US_SCALER_SET(x)                                        (((0 | (x)) << PCU_1US_SCALER_LSB) & PCU_1US_SCALER_MASK)
#define PCU_1US_SCALER_RESET                                         44
#define PCU_1US_ADDRESS                                              0x8284
#define PCU_1US_HW_MASK                                              0x0000007f
#define PCU_1US_SW_MASK                                              0x0000007f
#define PCU_1US_HW_WRITE_MASK                                        0x00000000
#define PCU_1US_SW_WRITE_MASK                                        0x0000007f
#define PCU_1US_RSTMASK                                              0xffffffff
#define PCU_1US_RESET                                                0x0000002c

// 0x8288 (PCU_KA)
#define PCU_KA_DEL_MSB                                               11
#define PCU_KA_DEL_LSB                                               0
#define PCU_KA_DEL_MASK                                              0x00000fff
#define PCU_KA_DEL_GET(x)                                            (((x) & PCU_KA_DEL_MASK) >> PCU_KA_DEL_LSB)
#define PCU_KA_DEL_SET(x)                                            (((0 | (x)) << PCU_KA_DEL_LSB) & PCU_KA_DEL_MASK)
#define PCU_KA_DEL_RESET                                             44
#define PCU_KA_ADDRESS                                               0x8288
#define PCU_KA_HW_MASK                                               0x00000fff
#define PCU_KA_SW_MASK                                               0x00000fff
#define PCU_KA_HW_WRITE_MASK                                         0x00000000
#define PCU_KA_SW_WRITE_MASK                                         0x00000fff
#define PCU_KA_RSTMASK                                               0xffffffff
#define PCU_KA_RESET                                                 0x0000002c

// 0x828c (WOW_EXACT)
#define WOW_EXACT_OFFSET_MSB                                         15
#define WOW_EXACT_OFFSET_LSB                                         8
#define WOW_EXACT_OFFSET_MASK                                        0x0000ff00
#define WOW_EXACT_OFFSET_GET(x)                                      (((x) & WOW_EXACT_OFFSET_MASK) >> WOW_EXACT_OFFSET_LSB)
#define WOW_EXACT_OFFSET_SET(x)                                      (((0 | (x)) << WOW_EXACT_OFFSET_LSB) & WOW_EXACT_OFFSET_MASK)
#define WOW_EXACT_OFFSET_RESET                                       0
#define WOW_EXACT_LENGTH_MSB                                         7
#define WOW_EXACT_LENGTH_LSB                                         0
#define WOW_EXACT_LENGTH_MASK                                        0x000000ff
#define WOW_EXACT_LENGTH_GET(x)                                      (((x) & WOW_EXACT_LENGTH_MASK) >> WOW_EXACT_LENGTH_LSB)
#define WOW_EXACT_LENGTH_SET(x)                                      (((0 | (x)) << WOW_EXACT_LENGTH_LSB) & WOW_EXACT_LENGTH_MASK)
#define WOW_EXACT_LENGTH_RESET                                       255
#define WOW_EXACT_ADDRESS                                            0x828c
#define WOW_EXACT_HW_MASK                                            0x0000ffff
#define WOW_EXACT_SW_MASK                                            0x0000ffff
#define WOW_EXACT_HW_WRITE_MASK                                      0x00000000
#define WOW_EXACT_SW_WRITE_MASK                                      0x0000ffff
#define WOW_EXACT_RSTMASK                                            0xffffffff
#define WOW_EXACT_RESET                                              0x000000ff

// 0x8294 (PCU_WOW4)
#define PCU_WOW4_OFFSET3_MSB                                         31
#define PCU_WOW4_OFFSET3_LSB                                         24
#define PCU_WOW4_OFFSET3_MASK                                        0xff000000
#define PCU_WOW4_OFFSET3_GET(x)                                      (((x) & PCU_WOW4_OFFSET3_MASK) >> PCU_WOW4_OFFSET3_LSB)
#define PCU_WOW4_OFFSET3_SET(x)                                      (((0 | (x)) << PCU_WOW4_OFFSET3_LSB) & PCU_WOW4_OFFSET3_MASK)
#define PCU_WOW4_OFFSET3_RESET                                       0
#define PCU_WOW4_OFFSET2_MSB                                         23
#define PCU_WOW4_OFFSET2_LSB                                         16
#define PCU_WOW4_OFFSET2_MASK                                        0x00ff0000
#define PCU_WOW4_OFFSET2_GET(x)                                      (((x) & PCU_WOW4_OFFSET2_MASK) >> PCU_WOW4_OFFSET2_LSB)
#define PCU_WOW4_OFFSET2_SET(x)                                      (((0 | (x)) << PCU_WOW4_OFFSET2_LSB) & PCU_WOW4_OFFSET2_MASK)
#define PCU_WOW4_OFFSET2_RESET                                       0
#define PCU_WOW4_OFFSET1_MSB                                         15
#define PCU_WOW4_OFFSET1_LSB                                         8
#define PCU_WOW4_OFFSET1_MASK                                        0x0000ff00
#define PCU_WOW4_OFFSET1_GET(x)                                      (((x) & PCU_WOW4_OFFSET1_MASK) >> PCU_WOW4_OFFSET1_LSB)
#define PCU_WOW4_OFFSET1_SET(x)                                      (((0 | (x)) << PCU_WOW4_OFFSET1_LSB) & PCU_WOW4_OFFSET1_MASK)
#define PCU_WOW4_OFFSET1_RESET                                       0
#define PCU_WOW4_OFFSET0_MSB                                         7
#define PCU_WOW4_OFFSET0_LSB                                         0
#define PCU_WOW4_OFFSET0_MASK                                        0x000000ff
#define PCU_WOW4_OFFSET0_GET(x)                                      (((x) & PCU_WOW4_OFFSET0_MASK) >> PCU_WOW4_OFFSET0_LSB)
#define PCU_WOW4_OFFSET0_SET(x)                                      (((0 | (x)) << PCU_WOW4_OFFSET0_LSB) & PCU_WOW4_OFFSET0_MASK)
#define PCU_WOW4_OFFSET0_RESET                                       0
#define PCU_WOW4_ADDRESS                                             0x8294
#define PCU_WOW4_HW_MASK                                             0xffffffff
#define PCU_WOW4_SW_MASK                                             0xffffffff
#define PCU_WOW4_HW_WRITE_MASK                                       0x00000000
#define PCU_WOW4_SW_WRITE_MASK                                       0xffffffff
#define PCU_WOW4_RSTMASK                                             0xffffffff
#define PCU_WOW4_RESET                                               0x00000000

// 0x8298 (PCU_WOW5)
#define PCU_WOW5_OFFSET7_MSB                                         31
#define PCU_WOW5_OFFSET7_LSB                                         24
#define PCU_WOW5_OFFSET7_MASK                                        0xff000000
#define PCU_WOW5_OFFSET7_GET(x)                                      (((x) & PCU_WOW5_OFFSET7_MASK) >> PCU_WOW5_OFFSET7_LSB)
#define PCU_WOW5_OFFSET7_SET(x)                                      (((0 | (x)) << PCU_WOW5_OFFSET7_LSB) & PCU_WOW5_OFFSET7_MASK)
#define PCU_WOW5_OFFSET7_RESET                                       0
#define PCU_WOW5_OFFSET6_MSB                                         23
#define PCU_WOW5_OFFSET6_LSB                                         16
#define PCU_WOW5_OFFSET6_MASK                                        0x00ff0000
#define PCU_WOW5_OFFSET6_GET(x)                                      (((x) & PCU_WOW5_OFFSET6_MASK) >> PCU_WOW5_OFFSET6_LSB)
#define PCU_WOW5_OFFSET6_SET(x)                                      (((0 | (x)) << PCU_WOW5_OFFSET6_LSB) & PCU_WOW5_OFFSET6_MASK)
#define PCU_WOW5_OFFSET6_RESET                                       0
#define PCU_WOW5_OFFSET5_MSB                                         15
#define PCU_WOW5_OFFSET5_LSB                                         8
#define PCU_WOW5_OFFSET5_MASK                                        0x0000ff00
#define PCU_WOW5_OFFSET5_GET(x)                                      (((x) & PCU_WOW5_OFFSET5_MASK) >> PCU_WOW5_OFFSET5_LSB)
#define PCU_WOW5_OFFSET5_SET(x)                                      (((0 | (x)) << PCU_WOW5_OFFSET5_LSB) & PCU_WOW5_OFFSET5_MASK)
#define PCU_WOW5_OFFSET5_RESET                                       0
#define PCU_WOW5_OFFSET4_MSB                                         7
#define PCU_WOW5_OFFSET4_LSB                                         0
#define PCU_WOW5_OFFSET4_MASK                                        0x000000ff
#define PCU_WOW5_OFFSET4_GET(x)                                      (((x) & PCU_WOW5_OFFSET4_MASK) >> PCU_WOW5_OFFSET4_LSB)
#define PCU_WOW5_OFFSET4_SET(x)                                      (((0 | (x)) << PCU_WOW5_OFFSET4_LSB) & PCU_WOW5_OFFSET4_MASK)
#define PCU_WOW5_OFFSET4_RESET                                       0
#define PCU_WOW5_ADDRESS                                             0x8298
#define PCU_WOW5_HW_MASK                                             0xffffffff
#define PCU_WOW5_SW_MASK                                             0xffffffff
#define PCU_WOW5_HW_WRITE_MASK                                       0x00000000
#define PCU_WOW5_SW_WRITE_MASK                                       0xffffffff
#define PCU_WOW5_RSTMASK                                             0xffffffff
#define PCU_WOW5_RESET                                               0x00000000

// 0x829c (MAC_PCU_PHY_ERR_CNT_1_MASK_CONT)
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_VALUE_MSB                    31
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_VALUE_LSB                    0
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_VALUE_MASK                   0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_VALUE_GET(x)                 (((x) & MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_VALUE_MASK) >> MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_VALUE_LSB)
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_VALUE_SET(x)                 (((0 | (x)) << MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_VALUE_LSB) & MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_VALUE_MASK)
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_VALUE_RESET                  0
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_ADDRESS                      0x829c
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_HW_MASK                      0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_SW_MASK                      0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_HW_WRITE_MASK                0x00000000
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_SW_WRITE_MASK                0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_RSTMASK                      0xffffffff
#define MAC_PCU_PHY_ERR_CNT_1_MASK_CONT_RESET                        0x00000000

// 0x8300 (MAC_PCU_AZIMUTH_MODE)
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX2_ENABLE_MSB               11
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX2_ENABLE_LSB               11
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX2_ENABLE_MASK              0x00000800
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX2_ENABLE_GET(x)            (((x) & MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX2_ENABLE_MASK) >> MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX2_ENABLE_LSB)
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX2_ENABLE_SET(x)            (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX2_ENABLE_LSB) & MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX2_ENABLE_MASK)
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX2_ENABLE_RESET             1
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX1_ENABLE_MSB               10
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX1_ENABLE_LSB               10
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX1_ENABLE_MASK              0x00000400
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX1_ENABLE_GET(x)            (((x) & MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX1_ENABLE_MASK) >> MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX1_ENABLE_LSB)
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX1_ENABLE_SET(x)            (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX1_ENABLE_LSB) & MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX1_ENABLE_MASK)
#define MAC_PCU_AZIMUTH_MODE_PROXY_STA_FIX1_ENABLE_RESET             1
#define MAC_PCU_AZIMUTH_MODE_FILTER_PASS_HOLD_MSB                    9
#define MAC_PCU_AZIMUTH_MODE_FILTER_PASS_HOLD_LSB                    9
#define MAC_PCU_AZIMUTH_MODE_FILTER_PASS_HOLD_MASK                   0x00000200
#define MAC_PCU_AZIMUTH_MODE_FILTER_PASS_HOLD_GET(x)                 (((x) & MAC_PCU_AZIMUTH_MODE_FILTER_PASS_HOLD_MASK) >> MAC_PCU_AZIMUTH_MODE_FILTER_PASS_HOLD_LSB)
#define MAC_PCU_AZIMUTH_MODE_FILTER_PASS_HOLD_SET(x)                 (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_FILTER_PASS_HOLD_LSB) & MAC_PCU_AZIMUTH_MODE_FILTER_PASS_HOLD_MASK)
#define MAC_PCU_AZIMUTH_MODE_FILTER_PASS_HOLD_RESET                  1
#define MAC_PCU_AZIMUTH_MODE_WMAC_CLK_SEL_MSB                        8
#define MAC_PCU_AZIMUTH_MODE_WMAC_CLK_SEL_LSB                        8
#define MAC_PCU_AZIMUTH_MODE_WMAC_CLK_SEL_MASK                       0x00000100
#define MAC_PCU_AZIMUTH_MODE_WMAC_CLK_SEL_GET(x)                     (((x) & MAC_PCU_AZIMUTH_MODE_WMAC_CLK_SEL_MASK) >> MAC_PCU_AZIMUTH_MODE_WMAC_CLK_SEL_LSB)
#define MAC_PCU_AZIMUTH_MODE_WMAC_CLK_SEL_SET(x)                     (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_WMAC_CLK_SEL_LSB) & MAC_PCU_AZIMUTH_MODE_WMAC_CLK_SEL_MASK)
#define MAC_PCU_AZIMUTH_MODE_WMAC_CLK_SEL_RESET                      1
#define MAC_PCU_AZIMUTH_MODE_BA_USES_AD1_MSB                         7
#define MAC_PCU_AZIMUTH_MODE_BA_USES_AD1_LSB                         7
#define MAC_PCU_AZIMUTH_MODE_BA_USES_AD1_MASK                        0x00000080
#define MAC_PCU_AZIMUTH_MODE_BA_USES_AD1_GET(x)                      (((x) & MAC_PCU_AZIMUTH_MODE_BA_USES_AD1_MASK) >> MAC_PCU_AZIMUTH_MODE_BA_USES_AD1_LSB)
#define MAC_PCU_AZIMUTH_MODE_BA_USES_AD1_SET(x)                      (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_BA_USES_AD1_LSB) & MAC_PCU_AZIMUTH_MODE_BA_USES_AD1_MASK)
#define MAC_PCU_AZIMUTH_MODE_BA_USES_AD1_RESET                       0
#define MAC_PCU_AZIMUTH_MODE_ACK_CTS_MATCH_TX_AD2_MSB                6
#define MAC_PCU_AZIMUTH_MODE_ACK_CTS_MATCH_TX_AD2_LSB                6
#define MAC_PCU_AZIMUTH_MODE_ACK_CTS_MATCH_TX_AD2_MASK               0x00000040
#define MAC_PCU_AZIMUTH_MODE_ACK_CTS_MATCH_TX_AD2_GET(x)             (((x) & MAC_PCU_AZIMUTH_MODE_ACK_CTS_MATCH_TX_AD2_MASK) >> MAC_PCU_AZIMUTH_MODE_ACK_CTS_MATCH_TX_AD2_LSB)
#define MAC_PCU_AZIMUTH_MODE_ACK_CTS_MATCH_TX_AD2_SET(x)             (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_ACK_CTS_MATCH_TX_AD2_LSB) & MAC_PCU_AZIMUTH_MODE_ACK_CTS_MATCH_TX_AD2_MASK)
#define MAC_PCU_AZIMUTH_MODE_ACK_CTS_MATCH_TX_AD2_RESET              1
#define MAC_PCU_AZIMUTH_MODE_TX_DESC_EN_MSB                          5
#define MAC_PCU_AZIMUTH_MODE_TX_DESC_EN_LSB                          5
#define MAC_PCU_AZIMUTH_MODE_TX_DESC_EN_MASK                         0x00000020
#define MAC_PCU_AZIMUTH_MODE_TX_DESC_EN_GET(x)                       (((x) & MAC_PCU_AZIMUTH_MODE_TX_DESC_EN_MASK) >> MAC_PCU_AZIMUTH_MODE_TX_DESC_EN_LSB)
#define MAC_PCU_AZIMUTH_MODE_TX_DESC_EN_SET(x)                       (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_TX_DESC_EN_LSB) & MAC_PCU_AZIMUTH_MODE_TX_DESC_EN_MASK)
#define MAC_PCU_AZIMUTH_MODE_TX_DESC_EN_RESET                        0
#define MAC_PCU_AZIMUTH_MODE_CLK_EN_MSB                              4
#define MAC_PCU_AZIMUTH_MODE_CLK_EN_LSB                              4
#define MAC_PCU_AZIMUTH_MODE_CLK_EN_MASK                             0x00000010
#define MAC_PCU_AZIMUTH_MODE_CLK_EN_GET(x)                           (((x) & MAC_PCU_AZIMUTH_MODE_CLK_EN_MASK) >> MAC_PCU_AZIMUTH_MODE_CLK_EN_LSB)
#define MAC_PCU_AZIMUTH_MODE_CLK_EN_SET(x)                           (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_CLK_EN_LSB) & MAC_PCU_AZIMUTH_MODE_CLK_EN_MASK)
#define MAC_PCU_AZIMUTH_MODE_CLK_EN_RESET                            0
#define MAC_PCU_AZIMUTH_MODE_RX_TSF_STATUS_SEL_MSB                   3
#define MAC_PCU_AZIMUTH_MODE_RX_TSF_STATUS_SEL_LSB                   3
#define MAC_PCU_AZIMUTH_MODE_RX_TSF_STATUS_SEL_MASK                  0x00000008
#define MAC_PCU_AZIMUTH_MODE_RX_TSF_STATUS_SEL_GET(x)                (((x) & MAC_PCU_AZIMUTH_MODE_RX_TSF_STATUS_SEL_MASK) >> MAC_PCU_AZIMUTH_MODE_RX_TSF_STATUS_SEL_LSB)
#define MAC_PCU_AZIMUTH_MODE_RX_TSF_STATUS_SEL_SET(x)                (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_RX_TSF_STATUS_SEL_LSB) & MAC_PCU_AZIMUTH_MODE_RX_TSF_STATUS_SEL_MASK)
#define MAC_PCU_AZIMUTH_MODE_RX_TSF_STATUS_SEL_RESET                 0
#define MAC_PCU_AZIMUTH_MODE_TX_TSF_STATUS_SEL_MSB                   2
#define MAC_PCU_AZIMUTH_MODE_TX_TSF_STATUS_SEL_LSB                   2
#define MAC_PCU_AZIMUTH_MODE_TX_TSF_STATUS_SEL_MASK                  0x00000004
#define MAC_PCU_AZIMUTH_MODE_TX_TSF_STATUS_SEL_GET(x)                (((x) & MAC_PCU_AZIMUTH_MODE_TX_TSF_STATUS_SEL_MASK) >> MAC_PCU_AZIMUTH_MODE_TX_TSF_STATUS_SEL_LSB)
#define MAC_PCU_AZIMUTH_MODE_TX_TSF_STATUS_SEL_SET(x)                (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_TX_TSF_STATUS_SEL_LSB) & MAC_PCU_AZIMUTH_MODE_TX_TSF_STATUS_SEL_MASK)
#define MAC_PCU_AZIMUTH_MODE_TX_TSF_STATUS_SEL_RESET                 0
#define MAC_PCU_AZIMUTH_MODE_KEY_SEARCH_AD1_MSB                      1
#define MAC_PCU_AZIMUTH_MODE_KEY_SEARCH_AD1_LSB                      1
#define MAC_PCU_AZIMUTH_MODE_KEY_SEARCH_AD1_MASK                     0x00000002
#define MAC_PCU_AZIMUTH_MODE_KEY_SEARCH_AD1_GET(x)                   (((x) & MAC_PCU_AZIMUTH_MODE_KEY_SEARCH_AD1_MASK) >> MAC_PCU_AZIMUTH_MODE_KEY_SEARCH_AD1_LSB)
#define MAC_PCU_AZIMUTH_MODE_KEY_SEARCH_AD1_SET(x)                   (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_KEY_SEARCH_AD1_LSB) & MAC_PCU_AZIMUTH_MODE_KEY_SEARCH_AD1_MASK)
#define MAC_PCU_AZIMUTH_MODE_KEY_SEARCH_AD1_RESET                    0
#define MAC_PCU_AZIMUTH_MODE_DISABLE_TSF_UPDATE_MSB                  0
#define MAC_PCU_AZIMUTH_MODE_DISABLE_TSF_UPDATE_LSB                  0
#define MAC_PCU_AZIMUTH_MODE_DISABLE_TSF_UPDATE_MASK                 0x00000001
#define MAC_PCU_AZIMUTH_MODE_DISABLE_TSF_UPDATE_GET(x)               (((x) & MAC_PCU_AZIMUTH_MODE_DISABLE_TSF_UPDATE_MASK) >> MAC_PCU_AZIMUTH_MODE_DISABLE_TSF_UPDATE_LSB)
#define MAC_PCU_AZIMUTH_MODE_DISABLE_TSF_UPDATE_SET(x)               (((0 | (x)) << MAC_PCU_AZIMUTH_MODE_DISABLE_TSF_UPDATE_LSB) & MAC_PCU_AZIMUTH_MODE_DISABLE_TSF_UPDATE_MASK)
#define MAC_PCU_AZIMUTH_MODE_DISABLE_TSF_UPDATE_RESET                0
#define MAC_PCU_AZIMUTH_MODE_ADDRESS                                 0x8300
#define MAC_PCU_AZIMUTH_MODE_HW_MASK                                 0x00000fff
#define MAC_PCU_AZIMUTH_MODE_SW_MASK                                 0x00000fff
#define MAC_PCU_AZIMUTH_MODE_HW_WRITE_MASK                           0x00000000
#define MAC_PCU_AZIMUTH_MODE_SW_WRITE_MASK                           0x00000fff
#define MAC_PCU_AZIMUTH_MODE_RSTMASK                                 0xffffffff
#define MAC_PCU_AZIMUTH_MODE_RESET                                   0x00000f40

// 0x8314 (MAC_PCU_AZIMUTH_TIME_STAMP)
#define MAC_PCU_AZIMUTH_TIME_STAMP_VALUE_MSB                         31
#define MAC_PCU_AZIMUTH_TIME_STAMP_VALUE_LSB                         0
#define MAC_PCU_AZIMUTH_TIME_STAMP_VALUE_MASK                        0xffffffff
#define MAC_PCU_AZIMUTH_TIME_STAMP_VALUE_GET(x)                      (((x) & MAC_PCU_AZIMUTH_TIME_STAMP_VALUE_MASK) >> MAC_PCU_AZIMUTH_TIME_STAMP_VALUE_LSB)
#define MAC_PCU_AZIMUTH_TIME_STAMP_VALUE_SET(x)                      (((0 | (x)) << MAC_PCU_AZIMUTH_TIME_STAMP_VALUE_LSB) & MAC_PCU_AZIMUTH_TIME_STAMP_VALUE_MASK)
#define MAC_PCU_AZIMUTH_TIME_STAMP_VALUE_RESET                       0
#define MAC_PCU_AZIMUTH_TIME_STAMP_ADDRESS                           0x8314
#define MAC_PCU_AZIMUTH_TIME_STAMP_HW_MASK                           0xffffffff
#define MAC_PCU_AZIMUTH_TIME_STAMP_SW_MASK                           0xffffffff
#define MAC_PCU_AZIMUTH_TIME_STAMP_HW_WRITE_MASK                     0xffffffff
#define MAC_PCU_AZIMUTH_TIME_STAMP_SW_WRITE_MASK                     0xffffffff
#define MAC_PCU_AZIMUTH_TIME_STAMP_RSTMASK                           0xffffffff
#define MAC_PCU_AZIMUTH_TIME_STAMP_RESET                             0x00000000

// 0x8318 (MAC_PCU_20_40_MODE)
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC80_MSB                 17
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC80_LSB                 17
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC80_MASK                0x00020000
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC80_GET(x)              (((x) & MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC80_MASK) >> MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC80_LSB)
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC80_SET(x)              (((0 | (x)) << MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC80_LSB) & MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC80_MASK)
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC80_RESET               0
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC40_MSB                 16
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC40_LSB                 16
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC40_MASK                0x00010000
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC40_GET(x)              (((x) & MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC40_MASK) >> MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC40_LSB)
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC40_SET(x)              (((0 | (x)) << MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC40_LSB) & MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC40_MASK)
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SEC40_RESET               0
#define MAC_PCU_20_40_MODE_PIFS_CYCLES_MSB                           15
#define MAC_PCU_20_40_MODE_PIFS_CYCLES_LSB                           4
#define MAC_PCU_20_40_MODE_PIFS_CYCLES_MASK                          0x0000fff0
#define MAC_PCU_20_40_MODE_PIFS_CYCLES_GET(x)                        (((x) & MAC_PCU_20_40_MODE_PIFS_CYCLES_MASK) >> MAC_PCU_20_40_MODE_PIFS_CYCLES_LSB)
#define MAC_PCU_20_40_MODE_PIFS_CYCLES_SET(x)                        (((0 | (x)) << MAC_PCU_20_40_MODE_PIFS_CYCLES_LSB) & MAC_PCU_20_40_MODE_PIFS_CYCLES_MASK)
#define MAC_PCU_20_40_MODE_PIFS_CYCLES_RESET                         1672
#define MAC_PCU_20_40_MODE_SWAMPED_FORCES_RX_CLEAR_CTL_IDLE_MSB      3
#define MAC_PCU_20_40_MODE_SWAMPED_FORCES_RX_CLEAR_CTL_IDLE_LSB      3
#define MAC_PCU_20_40_MODE_SWAMPED_FORCES_RX_CLEAR_CTL_IDLE_MASK     0x00000008
#define MAC_PCU_20_40_MODE_SWAMPED_FORCES_RX_CLEAR_CTL_IDLE_GET(x)   (((x) & MAC_PCU_20_40_MODE_SWAMPED_FORCES_RX_CLEAR_CTL_IDLE_MASK) >> MAC_PCU_20_40_MODE_SWAMPED_FORCES_RX_CLEAR_CTL_IDLE_LSB)
#define MAC_PCU_20_40_MODE_SWAMPED_FORCES_RX_CLEAR_CTL_IDLE_SET(x)   (((0 | (x)) << MAC_PCU_20_40_MODE_SWAMPED_FORCES_RX_CLEAR_CTL_IDLE_LSB) & MAC_PCU_20_40_MODE_SWAMPED_FORCES_RX_CLEAR_CTL_IDLE_MASK)
#define MAC_PCU_20_40_MODE_SWAMPED_FORCES_RX_CLEAR_CTL_IDLE_RESET    0
#define MAC_PCU_20_40_MODE_TX_HT20_ON_EXT_BUSY_MSB                   2
#define MAC_PCU_20_40_MODE_TX_HT20_ON_EXT_BUSY_LSB                   2
#define MAC_PCU_20_40_MODE_TX_HT20_ON_EXT_BUSY_MASK                  0x00000004
#define MAC_PCU_20_40_MODE_TX_HT20_ON_EXT_BUSY_GET(x)                (((x) & MAC_PCU_20_40_MODE_TX_HT20_ON_EXT_BUSY_MASK) >> MAC_PCU_20_40_MODE_TX_HT20_ON_EXT_BUSY_LSB)
#define MAC_PCU_20_40_MODE_TX_HT20_ON_EXT_BUSY_SET(x)                (((0 | (x)) << MAC_PCU_20_40_MODE_TX_HT20_ON_EXT_BUSY_LSB) & MAC_PCU_20_40_MODE_TX_HT20_ON_EXT_BUSY_MASK)
#define MAC_PCU_20_40_MODE_TX_HT20_ON_EXT_BUSY_RESET                 0
#define MAC_PCU_20_40_MODE_EXT_PIFS_ENABLE_MSB                       1
#define MAC_PCU_20_40_MODE_EXT_PIFS_ENABLE_LSB                       1
#define MAC_PCU_20_40_MODE_EXT_PIFS_ENABLE_MASK                      0x00000002
#define MAC_PCU_20_40_MODE_EXT_PIFS_ENABLE_GET(x)                    (((x) & MAC_PCU_20_40_MODE_EXT_PIFS_ENABLE_MASK) >> MAC_PCU_20_40_MODE_EXT_PIFS_ENABLE_LSB)
#define MAC_PCU_20_40_MODE_EXT_PIFS_ENABLE_SET(x)                    (((0 | (x)) << MAC_PCU_20_40_MODE_EXT_PIFS_ENABLE_LSB) & MAC_PCU_20_40_MODE_EXT_PIFS_ENABLE_MASK)
#define MAC_PCU_20_40_MODE_EXT_PIFS_ENABLE_RESET                     0
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_MSB                       0
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_LSB                       0
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_MASK                      0x00000001
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_GET(x)                    (((x) & MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_MASK) >> MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_LSB)
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_SET(x)                    (((0 | (x)) << MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_LSB) & MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_MASK)
#define MAC_PCU_20_40_MODE_JOINED_RX_CLEAR_RESET                     0
#define MAC_PCU_20_40_MODE_ADDRESS                                   0x8318
#define MAC_PCU_20_40_MODE_HW_MASK                                   0x0003ffff
#define MAC_PCU_20_40_MODE_SW_MASK                                   0x0003ffff
#define MAC_PCU_20_40_MODE_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_20_40_MODE_SW_WRITE_MASK                             0x0003ffff
#define MAC_PCU_20_40_MODE_RSTMASK                                   0xffffffff
#define MAC_PCU_20_40_MODE_RESET                                     0x00006880

// 0x831c (MAC_PCU_H_XFER_TIMEOUT)
#define MAC_PCU_H_XFER_TIMEOUT_EV_78384_FIX_DISABLE_MSB              9
#define MAC_PCU_H_XFER_TIMEOUT_EV_78384_FIX_DISABLE_LSB              9
#define MAC_PCU_H_XFER_TIMEOUT_EV_78384_FIX_DISABLE_MASK             0x00000200
#define MAC_PCU_H_XFER_TIMEOUT_EV_78384_FIX_DISABLE_GET(x)           (((x) & MAC_PCU_H_XFER_TIMEOUT_EV_78384_FIX_DISABLE_MASK) >> MAC_PCU_H_XFER_TIMEOUT_EV_78384_FIX_DISABLE_LSB)
#define MAC_PCU_H_XFER_TIMEOUT_EV_78384_FIX_DISABLE_SET(x)           (((0 | (x)) << MAC_PCU_H_XFER_TIMEOUT_EV_78384_FIX_DISABLE_LSB) & MAC_PCU_H_XFER_TIMEOUT_EV_78384_FIX_DISABLE_MASK)
#define MAC_PCU_H_XFER_TIMEOUT_EV_78384_FIX_DISABLE_RESET            0
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_NOACK_NORPT_MSB                8
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_NOACK_NORPT_LSB                8
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_NOACK_NORPT_MASK               0x00000100
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_NOACK_NORPT_GET(x)             (((x) & MAC_PCU_H_XFER_TIMEOUT_EXTXBF_NOACK_NORPT_MASK) >> MAC_PCU_H_XFER_TIMEOUT_EXTXBF_NOACK_NORPT_LSB)
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_NOACK_NORPT_SET(x)             (((0 | (x)) << MAC_PCU_H_XFER_TIMEOUT_EXTXBF_NOACK_NORPT_LSB) & MAC_PCU_H_XFER_TIMEOUT_EXTXBF_NOACK_NORPT_MASK)
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_NOACK_NORPT_RESET              1
#define MAC_PCU_H_XFER_TIMEOUT_DELAY_EXTXBF_ONLY_UPLOAD_H_MSB        7
#define MAC_PCU_H_XFER_TIMEOUT_DELAY_EXTXBF_ONLY_UPLOAD_H_LSB        7
#define MAC_PCU_H_XFER_TIMEOUT_DELAY_EXTXBF_ONLY_UPLOAD_H_MASK       0x00000080
#define MAC_PCU_H_XFER_TIMEOUT_DELAY_EXTXBF_ONLY_UPLOAD_H_GET(x)     (((x) & MAC_PCU_H_XFER_TIMEOUT_DELAY_EXTXBF_ONLY_UPLOAD_H_MASK) >> MAC_PCU_H_XFER_TIMEOUT_DELAY_EXTXBF_ONLY_UPLOAD_H_LSB)
#define MAC_PCU_H_XFER_TIMEOUT_DELAY_EXTXBF_ONLY_UPLOAD_H_SET(x)     (((0 | (x)) << MAC_PCU_H_XFER_TIMEOUT_DELAY_EXTXBF_ONLY_UPLOAD_H_LSB) & MAC_PCU_H_XFER_TIMEOUT_DELAY_EXTXBF_ONLY_UPLOAD_H_MASK)
#define MAC_PCU_H_XFER_TIMEOUT_DELAY_EXTXBF_ONLY_UPLOAD_H_RESET      0
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_IMMEDIATE_RESP_MSB             6
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_IMMEDIATE_RESP_LSB             6
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_IMMEDIATE_RESP_MASK            0x00000040
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_IMMEDIATE_RESP_GET(x)          (((x) & MAC_PCU_H_XFER_TIMEOUT_EXTXBF_IMMEDIATE_RESP_MASK) >> MAC_PCU_H_XFER_TIMEOUT_EXTXBF_IMMEDIATE_RESP_LSB)
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_IMMEDIATE_RESP_SET(x)          (((0 | (x)) << MAC_PCU_H_XFER_TIMEOUT_EXTXBF_IMMEDIATE_RESP_LSB) & MAC_PCU_H_XFER_TIMEOUT_EXTXBF_IMMEDIATE_RESP_MASK)
#define MAC_PCU_H_XFER_TIMEOUT_EXTXBF_IMMEDIATE_RESP_RESET           0
#define MAC_PCU_H_XFER_TIMEOUT_DISABLE_MSB                           5
#define MAC_PCU_H_XFER_TIMEOUT_DISABLE_LSB                           5
#define MAC_PCU_H_XFER_TIMEOUT_DISABLE_MASK                          0x00000020
#define MAC_PCU_H_XFER_TIMEOUT_DISABLE_GET(x)                        (((x) & MAC_PCU_H_XFER_TIMEOUT_DISABLE_MASK) >> MAC_PCU_H_XFER_TIMEOUT_DISABLE_LSB)
#define MAC_PCU_H_XFER_TIMEOUT_DISABLE_SET(x)                        (((0 | (x)) << MAC_PCU_H_XFER_TIMEOUT_DISABLE_LSB) & MAC_PCU_H_XFER_TIMEOUT_DISABLE_MASK)
#define MAC_PCU_H_XFER_TIMEOUT_DISABLE_RESET                         0
#define MAC_PCU_H_XFER_TIMEOUT_VALUE_MSB                             4
#define MAC_PCU_H_XFER_TIMEOUT_VALUE_LSB                             0
#define MAC_PCU_H_XFER_TIMEOUT_VALUE_MASK                            0x0000001f
#define MAC_PCU_H_XFER_TIMEOUT_VALUE_GET(x)                          (((x) & MAC_PCU_H_XFER_TIMEOUT_VALUE_MASK) >> MAC_PCU_H_XFER_TIMEOUT_VALUE_LSB)
#define MAC_PCU_H_XFER_TIMEOUT_VALUE_SET(x)                          (((0 | (x)) << MAC_PCU_H_XFER_TIMEOUT_VALUE_LSB) & MAC_PCU_H_XFER_TIMEOUT_VALUE_MASK)
#define MAC_PCU_H_XFER_TIMEOUT_VALUE_RESET                           13
#define MAC_PCU_H_XFER_TIMEOUT_ADDRESS                               0x831c
#define MAC_PCU_H_XFER_TIMEOUT_HW_MASK                               0x000003ff
#define MAC_PCU_H_XFER_TIMEOUT_SW_MASK                               0x000003ff
#define MAC_PCU_H_XFER_TIMEOUT_HW_WRITE_MASK                         0x00000000
#define MAC_PCU_H_XFER_TIMEOUT_SW_WRITE_MASK                         0x000003ff
#define MAC_PCU_H_XFER_TIMEOUT_RSTMASK                               0xffffffff
#define MAC_PCU_H_XFER_TIMEOUT_RESET                                 0x0000010d

// 0x8328 (MAC_PCU_RX_CLEAR_DIFF_CNT)
#define MAC_PCU_RX_CLEAR_DIFF_CNT_VALUE_MSB                          31
#define MAC_PCU_RX_CLEAR_DIFF_CNT_VALUE_LSB                          0
#define MAC_PCU_RX_CLEAR_DIFF_CNT_VALUE_MASK                         0xffffffff
#define MAC_PCU_RX_CLEAR_DIFF_CNT_VALUE_GET(x)                       (((x) & MAC_PCU_RX_CLEAR_DIFF_CNT_VALUE_MASK) >> MAC_PCU_RX_CLEAR_DIFF_CNT_VALUE_LSB)
#define MAC_PCU_RX_CLEAR_DIFF_CNT_VALUE_SET(x)                       (((0 | (x)) << MAC_PCU_RX_CLEAR_DIFF_CNT_VALUE_LSB) & MAC_PCU_RX_CLEAR_DIFF_CNT_VALUE_MASK)
#define MAC_PCU_RX_CLEAR_DIFF_CNT_VALUE_RESET                        0
#define MAC_PCU_RX_CLEAR_DIFF_CNT_ADDRESS                            0x8328
#define MAC_PCU_RX_CLEAR_DIFF_CNT_HW_MASK                            0xffffffff
#define MAC_PCU_RX_CLEAR_DIFF_CNT_SW_MASK                            0xffffffff
#define MAC_PCU_RX_CLEAR_DIFF_CNT_HW_WRITE_MASK                      0xffffffff
#define MAC_PCU_RX_CLEAR_DIFF_CNT_SW_WRITE_MASK                      0xffffffff
#define MAC_PCU_RX_CLEAR_DIFF_CNT_RSTMASK                            0xffffffff
#define MAC_PCU_RX_CLEAR_DIFF_CNT_RESET                              0x00000000

// 0x832c (MAC_PCU_SELF_GEN_ANTENNA_MASK)
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_M_ACK_VALUE_MSB                7
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_M_ACK_VALUE_LSB                5
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_M_ACK_VALUE_MASK               0x000000e0
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_M_ACK_VALUE_GET(x)             (((x) & MAC_PCU_SELF_GEN_ANTENNA_MASK_M_ACK_VALUE_MASK) >> MAC_PCU_SELF_GEN_ANTENNA_MASK_M_ACK_VALUE_LSB)
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_M_ACK_VALUE_SET(x)             (((0 | (x)) << MAC_PCU_SELF_GEN_ANTENNA_MASK_M_ACK_VALUE_LSB) & MAC_PCU_SELF_GEN_ANTENNA_MASK_M_ACK_VALUE_MASK)
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_M_ACK_VALUE_RESET              7
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_FORCE_CHAIN_0_MSB              4
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_FORCE_CHAIN_0_LSB              4
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_FORCE_CHAIN_0_MASK             0x00000010
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_FORCE_CHAIN_0_GET(x)           (((x) & MAC_PCU_SELF_GEN_ANTENNA_MASK_FORCE_CHAIN_0_MASK) >> MAC_PCU_SELF_GEN_ANTENNA_MASK_FORCE_CHAIN_0_LSB)
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_FORCE_CHAIN_0_SET(x)           (((0 | (x)) << MAC_PCU_SELF_GEN_ANTENNA_MASK_FORCE_CHAIN_0_LSB) & MAC_PCU_SELF_GEN_ANTENNA_MASK_FORCE_CHAIN_0_MASK)
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_FORCE_CHAIN_0_RESET            0
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_ONE_RESP_EN_MSB                3
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_ONE_RESP_EN_LSB                3
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_ONE_RESP_EN_MASK               0x00000008
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_ONE_RESP_EN_GET(x)             (((x) & MAC_PCU_SELF_GEN_ANTENNA_MASK_ONE_RESP_EN_MASK) >> MAC_PCU_SELF_GEN_ANTENNA_MASK_ONE_RESP_EN_LSB)
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_ONE_RESP_EN_SET(x)             (((0 | (x)) << MAC_PCU_SELF_GEN_ANTENNA_MASK_ONE_RESP_EN_LSB) & MAC_PCU_SELF_GEN_ANTENNA_MASK_ONE_RESP_EN_MASK)
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_ONE_RESP_EN_RESET              1
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_VALUE_MSB                      2
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_VALUE_LSB                      0
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_VALUE_MASK                     0x00000007
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_VALUE_GET(x)                   (((x) & MAC_PCU_SELF_GEN_ANTENNA_MASK_VALUE_MASK) >> MAC_PCU_SELF_GEN_ANTENNA_MASK_VALUE_LSB)
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_VALUE_SET(x)                   (((0 | (x)) << MAC_PCU_SELF_GEN_ANTENNA_MASK_VALUE_LSB) & MAC_PCU_SELF_GEN_ANTENNA_MASK_VALUE_MASK)
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_VALUE_RESET                    7
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_ADDRESS                        0x832c
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_HW_MASK                        0x000000ff
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_SW_MASK                        0x000000ff
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_HW_WRITE_MASK                  0x00000000
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_SW_WRITE_MASK                  0x000000ff
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_RSTMASK                        0xffffffff
#define MAC_PCU_SELF_GEN_ANTENNA_MASK_RESET                          0x000000ef

// 0x8330 (MAC_PCU_BA_BAR_CONTROL)
#define MAC_PCU_BA_BAR_CONTROL_SEARCH_DEPTH_MSB                      19
#define MAC_PCU_BA_BAR_CONTROL_SEARCH_DEPTH_LSB                      16
#define MAC_PCU_BA_BAR_CONTROL_SEARCH_DEPTH_MASK                     0x000f0000
#define MAC_PCU_BA_BAR_CONTROL_SEARCH_DEPTH_GET(x)                   (((x) & MAC_PCU_BA_BAR_CONTROL_SEARCH_DEPTH_MASK) >> MAC_PCU_BA_BAR_CONTROL_SEARCH_DEPTH_LSB)
#define MAC_PCU_BA_BAR_CONTROL_SEARCH_DEPTH_SET(x)                   (((0 | (x)) << MAC_PCU_BA_BAR_CONTROL_SEARCH_DEPTH_LSB) & MAC_PCU_BA_BAR_CONTROL_SEARCH_DEPTH_MASK)
#define MAC_PCU_BA_BAR_CONTROL_SEARCH_DEPTH_RESET                    3
#define MAC_PCU_BA_BAR_CONTROL_UPDATE_BA_BITMAP_QOS_NULL_MSB         12
#define MAC_PCU_BA_BAR_CONTROL_UPDATE_BA_BITMAP_QOS_NULL_LSB         12
#define MAC_PCU_BA_BAR_CONTROL_UPDATE_BA_BITMAP_QOS_NULL_MASK        0x00001000
#define MAC_PCU_BA_BAR_CONTROL_UPDATE_BA_BITMAP_QOS_NULL_GET(x)      (((x) & MAC_PCU_BA_BAR_CONTROL_UPDATE_BA_BITMAP_QOS_NULL_MASK) >> MAC_PCU_BA_BAR_CONTROL_UPDATE_BA_BITMAP_QOS_NULL_LSB)
#define MAC_PCU_BA_BAR_CONTROL_UPDATE_BA_BITMAP_QOS_NULL_SET(x)      (((0 | (x)) << MAC_PCU_BA_BAR_CONTROL_UPDATE_BA_BITMAP_QOS_NULL_LSB) & MAC_PCU_BA_BAR_CONTROL_UPDATE_BA_BITMAP_QOS_NULL_MASK)
#define MAC_PCU_BA_BAR_CONTROL_UPDATE_BA_BITMAP_QOS_NULL_RESET       0
#define MAC_PCU_BA_BAR_CONTROL_TX_BA_CLEAR_BA_VALID_MSB              11
#define MAC_PCU_BA_BAR_CONTROL_TX_BA_CLEAR_BA_VALID_LSB              11
#define MAC_PCU_BA_BAR_CONTROL_TX_BA_CLEAR_BA_VALID_MASK             0x00000800
#define MAC_PCU_BA_BAR_CONTROL_TX_BA_CLEAR_BA_VALID_GET(x)           (((x) & MAC_PCU_BA_BAR_CONTROL_TX_BA_CLEAR_BA_VALID_MASK) >> MAC_PCU_BA_BAR_CONTROL_TX_BA_CLEAR_BA_VALID_LSB)
#define MAC_PCU_BA_BAR_CONTROL_TX_BA_CLEAR_BA_VALID_SET(x)           (((0 | (x)) << MAC_PCU_BA_BAR_CONTROL_TX_BA_CLEAR_BA_VALID_LSB) & MAC_PCU_BA_BAR_CONTROL_TX_BA_CLEAR_BA_VALID_MASK)
#define MAC_PCU_BA_BAR_CONTROL_TX_BA_CLEAR_BA_VALID_RESET            0
#define MAC_PCU_BA_BAR_CONTROL_FORCE_NO_MATCH_MSB                    10
#define MAC_PCU_BA_BAR_CONTROL_FORCE_NO_MATCH_LSB                    10
#define MAC_PCU_BA_BAR_CONTROL_FORCE_NO_MATCH_MASK                   0x00000400
#define MAC_PCU_BA_BAR_CONTROL_FORCE_NO_MATCH_GET(x)                 (((x) & MAC_PCU_BA_BAR_CONTROL_FORCE_NO_MATCH_MASK) >> MAC_PCU_BA_BAR_CONTROL_FORCE_NO_MATCH_LSB)
#define MAC_PCU_BA_BAR_CONTROL_FORCE_NO_MATCH_SET(x)                 (((0 | (x)) << MAC_PCU_BA_BAR_CONTROL_FORCE_NO_MATCH_LSB) & MAC_PCU_BA_BAR_CONTROL_FORCE_NO_MATCH_MASK)
#define MAC_PCU_BA_BAR_CONTROL_FORCE_NO_MATCH_RESET                  0
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_VALUE_MSB                  9
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_VALUE_LSB                  9
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_VALUE_MASK                 0x00000200
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_VALUE_GET(x)               (((x) & MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_VALUE_MASK) >> MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_VALUE_LSB)
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_VALUE_SET(x)               (((0 | (x)) << MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_VALUE_LSB) & MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_VALUE_MASK)
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_VALUE_RESET                1
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_VALUE_MSB                  8
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_VALUE_LSB                  8
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_VALUE_MASK                 0x00000100
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_VALUE_GET(x)               (((x) & MAC_PCU_BA_BAR_CONTROL_COMPRESSED_VALUE_MASK) >> MAC_PCU_BA_BAR_CONTROL_COMPRESSED_VALUE_LSB)
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_VALUE_SET(x)               (((0 | (x)) << MAC_PCU_BA_BAR_CONTROL_COMPRESSED_VALUE_LSB) & MAC_PCU_BA_BAR_CONTROL_COMPRESSED_VALUE_MASK)
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_VALUE_RESET                1
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_OFFSET_MSB                 7
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_OFFSET_LSB                 4
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_OFFSET_MASK                0x000000f0
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_OFFSET_GET(x)              (((x) & MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_OFFSET_MASK) >> MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_OFFSET_LSB)
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_OFFSET_SET(x)              (((0 | (x)) << MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_OFFSET_LSB) & MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_OFFSET_MASK)
#define MAC_PCU_BA_BAR_CONTROL_ACK_POLICY_OFFSET_RESET               0
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_OFFSET_MSB                 3
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_OFFSET_LSB                 0
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_OFFSET_MASK                0x0000000f
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_OFFSET_GET(x)              (((x) & MAC_PCU_BA_BAR_CONTROL_COMPRESSED_OFFSET_MASK) >> MAC_PCU_BA_BAR_CONTROL_COMPRESSED_OFFSET_LSB)
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_OFFSET_SET(x)              (((0 | (x)) << MAC_PCU_BA_BAR_CONTROL_COMPRESSED_OFFSET_LSB) & MAC_PCU_BA_BAR_CONTROL_COMPRESSED_OFFSET_MASK)
#define MAC_PCU_BA_BAR_CONTROL_COMPRESSED_OFFSET_RESET               2
#define MAC_PCU_BA_BAR_CONTROL_ADDRESS                               0x8330
#define MAC_PCU_BA_BAR_CONTROL_HW_MASK                               0x000f1fff
#define MAC_PCU_BA_BAR_CONTROL_SW_MASK                               0x000f1fff
#define MAC_PCU_BA_BAR_CONTROL_HW_WRITE_MASK                         0x00000000
#define MAC_PCU_BA_BAR_CONTROL_SW_WRITE_MASK                         0x000f1fff
#define MAC_PCU_BA_BAR_CONTROL_RSTMASK                               0xffffffff
#define MAC_PCU_BA_BAR_CONTROL_RESET                                 0x00030302

// 0x8334 (MAC_PCU_LEGACY_PLCP_SPOOF)
#define MAC_PCU_LEGACY_PLCP_SPOOF_MIN_LENGTH_MSB                     12
#define MAC_PCU_LEGACY_PLCP_SPOOF_MIN_LENGTH_LSB                     8
#define MAC_PCU_LEGACY_PLCP_SPOOF_MIN_LENGTH_MASK                    0x00001f00
#define MAC_PCU_LEGACY_PLCP_SPOOF_MIN_LENGTH_GET(x)                  (((x) & MAC_PCU_LEGACY_PLCP_SPOOF_MIN_LENGTH_MASK) >> MAC_PCU_LEGACY_PLCP_SPOOF_MIN_LENGTH_LSB)
#define MAC_PCU_LEGACY_PLCP_SPOOF_MIN_LENGTH_SET(x)                  (((0 | (x)) << MAC_PCU_LEGACY_PLCP_SPOOF_MIN_LENGTH_LSB) & MAC_PCU_LEGACY_PLCP_SPOOF_MIN_LENGTH_MASK)
#define MAC_PCU_LEGACY_PLCP_SPOOF_MIN_LENGTH_RESET                   14
#define MAC_PCU_LEGACY_PLCP_SPOOF_EIFS_MINUS_DIFS_MSB                7
#define MAC_PCU_LEGACY_PLCP_SPOOF_EIFS_MINUS_DIFS_LSB                0
#define MAC_PCU_LEGACY_PLCP_SPOOF_EIFS_MINUS_DIFS_MASK               0x000000ff
#define MAC_PCU_LEGACY_PLCP_SPOOF_EIFS_MINUS_DIFS_GET(x)             (((x) & MAC_PCU_LEGACY_PLCP_SPOOF_EIFS_MINUS_DIFS_MASK) >> MAC_PCU_LEGACY_PLCP_SPOOF_EIFS_MINUS_DIFS_LSB)
#define MAC_PCU_LEGACY_PLCP_SPOOF_EIFS_MINUS_DIFS_SET(x)             (((0 | (x)) << MAC_PCU_LEGACY_PLCP_SPOOF_EIFS_MINUS_DIFS_LSB) & MAC_PCU_LEGACY_PLCP_SPOOF_EIFS_MINUS_DIFS_MASK)
#define MAC_PCU_LEGACY_PLCP_SPOOF_EIFS_MINUS_DIFS_RESET              0
#define MAC_PCU_LEGACY_PLCP_SPOOF_ADDRESS                            0x8334
#define MAC_PCU_LEGACY_PLCP_SPOOF_HW_MASK                            0x00001fff
#define MAC_PCU_LEGACY_PLCP_SPOOF_SW_MASK                            0x00001fff
#define MAC_PCU_LEGACY_PLCP_SPOOF_HW_WRITE_MASK                      0x00000000
#define MAC_PCU_LEGACY_PLCP_SPOOF_SW_WRITE_MASK                      0x00001fff
#define MAC_PCU_LEGACY_PLCP_SPOOF_RSTMASK                            0xffffffff
#define MAC_PCU_LEGACY_PLCP_SPOOF_RESET                              0x00000e00

// 0x8338 (MAC_PCU_PHY_ERROR_MASK_CONT)
#define MAC_PCU_PHY_ERROR_MASK_CONT_VALUE_MSB                        31
#define MAC_PCU_PHY_ERROR_MASK_CONT_VALUE_LSB                        0
#define MAC_PCU_PHY_ERROR_MASK_CONT_VALUE_MASK                       0xffffffff
#define MAC_PCU_PHY_ERROR_MASK_CONT_VALUE_GET(x)                     (((x) & MAC_PCU_PHY_ERROR_MASK_CONT_VALUE_MASK) >> MAC_PCU_PHY_ERROR_MASK_CONT_VALUE_LSB)
#define MAC_PCU_PHY_ERROR_MASK_CONT_VALUE_SET(x)                     (((0 | (x)) << MAC_PCU_PHY_ERROR_MASK_CONT_VALUE_LSB) & MAC_PCU_PHY_ERROR_MASK_CONT_VALUE_MASK)
#define MAC_PCU_PHY_ERROR_MASK_CONT_VALUE_RESET                      0
#define MAC_PCU_PHY_ERROR_MASK_CONT_ADDRESS                          0x8338
#define MAC_PCU_PHY_ERROR_MASK_CONT_HW_MASK                          0xffffffff
#define MAC_PCU_PHY_ERROR_MASK_CONT_SW_MASK                          0xffffffff
#define MAC_PCU_PHY_ERROR_MASK_CONT_HW_WRITE_MASK                    0x00000000
#define MAC_PCU_PHY_ERROR_MASK_CONT_SW_WRITE_MASK                    0xffffffff
#define MAC_PCU_PHY_ERROR_MASK_CONT_RSTMASK                          0xffffffff
#define MAC_PCU_PHY_ERROR_MASK_CONT_RESET                            0x00000000

// 0x833c (MAC_PCU_TX_TIMER)
#define MAC_PCU_TX_TIMER_QUIET_TIMER_ENABLE_MSB                      25
#define MAC_PCU_TX_TIMER_QUIET_TIMER_ENABLE_LSB                      25
#define MAC_PCU_TX_TIMER_QUIET_TIMER_ENABLE_MASK                     0x02000000
#define MAC_PCU_TX_TIMER_QUIET_TIMER_ENABLE_GET(x)                   (((x) & MAC_PCU_TX_TIMER_QUIET_TIMER_ENABLE_MASK) >> MAC_PCU_TX_TIMER_QUIET_TIMER_ENABLE_LSB)
#define MAC_PCU_TX_TIMER_QUIET_TIMER_ENABLE_SET(x)                   (((0 | (x)) << MAC_PCU_TX_TIMER_QUIET_TIMER_ENABLE_LSB) & MAC_PCU_TX_TIMER_QUIET_TIMER_ENABLE_MASK)
#define MAC_PCU_TX_TIMER_QUIET_TIMER_ENABLE_RESET                    1
#define MAC_PCU_TX_TIMER_QUIET_TIMER_MSB                             24
#define MAC_PCU_TX_TIMER_QUIET_TIMER_LSB                             20
#define MAC_PCU_TX_TIMER_QUIET_TIMER_MASK                            0x01f00000
#define MAC_PCU_TX_TIMER_QUIET_TIMER_GET(x)                          (((x) & MAC_PCU_TX_TIMER_QUIET_TIMER_MASK) >> MAC_PCU_TX_TIMER_QUIET_TIMER_LSB)
#define MAC_PCU_TX_TIMER_QUIET_TIMER_SET(x)                          (((0 | (x)) << MAC_PCU_TX_TIMER_QUIET_TIMER_LSB) & MAC_PCU_TX_TIMER_QUIET_TIMER_MASK)
#define MAC_PCU_TX_TIMER_QUIET_TIMER_RESET                           4
#define MAC_PCU_TX_TIMER_RIFS_TIMER_MSB                              19
#define MAC_PCU_TX_TIMER_RIFS_TIMER_LSB                              16
#define MAC_PCU_TX_TIMER_RIFS_TIMER_MASK                             0x000f0000
#define MAC_PCU_TX_TIMER_RIFS_TIMER_GET(x)                           (((x) & MAC_PCU_TX_TIMER_RIFS_TIMER_MASK) >> MAC_PCU_TX_TIMER_RIFS_TIMER_LSB)
#define MAC_PCU_TX_TIMER_RIFS_TIMER_SET(x)                           (((0 | (x)) << MAC_PCU_TX_TIMER_RIFS_TIMER_LSB) & MAC_PCU_TX_TIMER_RIFS_TIMER_MASK)
#define MAC_PCU_TX_TIMER_RIFS_TIMER_RESET                            0
#define MAC_PCU_TX_TIMER_TX_TIMER_ENABLE_MSB                         15
#define MAC_PCU_TX_TIMER_TX_TIMER_ENABLE_LSB                         15
#define MAC_PCU_TX_TIMER_TX_TIMER_ENABLE_MASK                        0x00008000
#define MAC_PCU_TX_TIMER_TX_TIMER_ENABLE_GET(x)                      (((x) & MAC_PCU_TX_TIMER_TX_TIMER_ENABLE_MASK) >> MAC_PCU_TX_TIMER_TX_TIMER_ENABLE_LSB)
#define MAC_PCU_TX_TIMER_TX_TIMER_ENABLE_SET(x)                      (((0 | (x)) << MAC_PCU_TX_TIMER_TX_TIMER_ENABLE_LSB) & MAC_PCU_TX_TIMER_TX_TIMER_ENABLE_MASK)
#define MAC_PCU_TX_TIMER_TX_TIMER_ENABLE_RESET                       0
#define MAC_PCU_TX_TIMER_TX_TIMER_MSB                                14
#define MAC_PCU_TX_TIMER_TX_TIMER_LSB                                0
#define MAC_PCU_TX_TIMER_TX_TIMER_MASK                               0x00007fff
#define MAC_PCU_TX_TIMER_TX_TIMER_GET(x)                             (((x) & MAC_PCU_TX_TIMER_TX_TIMER_MASK) >> MAC_PCU_TX_TIMER_TX_TIMER_LSB)
#define MAC_PCU_TX_TIMER_TX_TIMER_SET(x)                             (((0 | (x)) << MAC_PCU_TX_TIMER_TX_TIMER_LSB) & MAC_PCU_TX_TIMER_TX_TIMER_MASK)
#define MAC_PCU_TX_TIMER_TX_TIMER_RESET                              0
#define MAC_PCU_TX_TIMER_ADDRESS                                     0x833c
#define MAC_PCU_TX_TIMER_HW_MASK                                     0x03ffffff
#define MAC_PCU_TX_TIMER_SW_MASK                                     0x03ffffff
#define MAC_PCU_TX_TIMER_HW_WRITE_MASK                               0x00000000
#define MAC_PCU_TX_TIMER_SW_WRITE_MASK                               0x03ffffff
#define MAC_PCU_TX_TIMER_RSTMASK                                     0xffffffff
#define MAC_PCU_TX_TIMER_RESET                                       0x02400000

// 0x8340 (MAC_PCU_TXBUF_CTRL)
#define MAC_PCU_TXBUF_CTRL_TX_FIFO_WRAP_ENABLE_MSB                   16
#define MAC_PCU_TXBUF_CTRL_TX_FIFO_WRAP_ENABLE_LSB                   16
#define MAC_PCU_TXBUF_CTRL_TX_FIFO_WRAP_ENABLE_MASK                  0x00010000
#define MAC_PCU_TXBUF_CTRL_TX_FIFO_WRAP_ENABLE_GET(x)                (((x) & MAC_PCU_TXBUF_CTRL_TX_FIFO_WRAP_ENABLE_MASK) >> MAC_PCU_TXBUF_CTRL_TX_FIFO_WRAP_ENABLE_LSB)
#define MAC_PCU_TXBUF_CTRL_TX_FIFO_WRAP_ENABLE_SET(x)                (((0 | (x)) << MAC_PCU_TXBUF_CTRL_TX_FIFO_WRAP_ENABLE_LSB) & MAC_PCU_TXBUF_CTRL_TX_FIFO_WRAP_ENABLE_MASK)
#define MAC_PCU_TXBUF_CTRL_TX_FIFO_WRAP_ENABLE_RESET                 1
#define MAC_PCU_TXBUF_CTRL_USABLE_ENTRIES_MSB                        11
#define MAC_PCU_TXBUF_CTRL_USABLE_ENTRIES_LSB                        0
#define MAC_PCU_TXBUF_CTRL_USABLE_ENTRIES_MASK                       0x00000fff
#define MAC_PCU_TXBUF_CTRL_USABLE_ENTRIES_GET(x)                     (((x) & MAC_PCU_TXBUF_CTRL_USABLE_ENTRIES_MASK) >> MAC_PCU_TXBUF_CTRL_USABLE_ENTRIES_LSB)
#define MAC_PCU_TXBUF_CTRL_USABLE_ENTRIES_SET(x)                     (((0 | (x)) << MAC_PCU_TXBUF_CTRL_USABLE_ENTRIES_LSB) & MAC_PCU_TXBUF_CTRL_USABLE_ENTRIES_MASK)
#define MAC_PCU_TXBUF_CTRL_USABLE_ENTRIES_RESET                      1023
#define MAC_PCU_TXBUF_CTRL_ADDRESS                                   0x8340
#define MAC_PCU_TXBUF_CTRL_HW_MASK                                   0x00010fff
#define MAC_PCU_TXBUF_CTRL_SW_MASK                                   0x00010fff
#define MAC_PCU_TXBUF_CTRL_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_TXBUF_CTRL_SW_WRITE_MASK                             0x00010fff
#define MAC_PCU_TXBUF_CTRL_RSTMASK                                   0xffffffff
#define MAC_PCU_TXBUF_CTRL_RESET                                     0x000103ff

// 0x8344 (MAC_PCU_MISC_MODE2)
#define MAC_PCU_MISC_MODE2_CLEAR_WEP_TXBUSY_ON_TXURN_MSB             31
#define MAC_PCU_MISC_MODE2_CLEAR_WEP_TXBUSY_ON_TXURN_LSB             31
#define MAC_PCU_MISC_MODE2_CLEAR_WEP_TXBUSY_ON_TXURN_MASK            0x80000000
#define MAC_PCU_MISC_MODE2_CLEAR_WEP_TXBUSY_ON_TXURN_GET(x)          (((x) & MAC_PCU_MISC_MODE2_CLEAR_WEP_TXBUSY_ON_TXURN_MASK) >> MAC_PCU_MISC_MODE2_CLEAR_WEP_TXBUSY_ON_TXURN_LSB)
#define MAC_PCU_MISC_MODE2_CLEAR_WEP_TXBUSY_ON_TXURN_SET(x)          (((0 | (x)) << MAC_PCU_MISC_MODE2_CLEAR_WEP_TXBUSY_ON_TXURN_LSB) & MAC_PCU_MISC_MODE2_CLEAR_WEP_TXBUSY_ON_TXURN_MASK)
#define MAC_PCU_MISC_MODE2_CLEAR_WEP_TXBUSY_ON_TXURN_RESET           1
#define MAC_PCU_MISC_MODE2_PCU_LOOP_TXBF_MSB                         30
#define MAC_PCU_MISC_MODE2_PCU_LOOP_TXBF_LSB                         30
#define MAC_PCU_MISC_MODE2_PCU_LOOP_TXBF_MASK                        0x40000000
#define MAC_PCU_MISC_MODE2_PCU_LOOP_TXBF_GET(x)                      (((x) & MAC_PCU_MISC_MODE2_PCU_LOOP_TXBF_MASK) >> MAC_PCU_MISC_MODE2_PCU_LOOP_TXBF_LSB)
#define MAC_PCU_MISC_MODE2_PCU_LOOP_TXBF_SET(x)                      (((0 | (x)) << MAC_PCU_MISC_MODE2_PCU_LOOP_TXBF_LSB) & MAC_PCU_MISC_MODE2_PCU_LOOP_TXBF_MASK)
#define MAC_PCU_MISC_MODE2_PCU_LOOP_TXBF_RESET                       0
#define MAC_PCU_MISC_MODE2_TXBF_ACT_RPT_DONE_PASS_MSB                29
#define MAC_PCU_MISC_MODE2_TXBF_ACT_RPT_DONE_PASS_LSB                29
#define MAC_PCU_MISC_MODE2_TXBF_ACT_RPT_DONE_PASS_MASK               0x20000000
#define MAC_PCU_MISC_MODE2_TXBF_ACT_RPT_DONE_PASS_GET(x)             (((x) & MAC_PCU_MISC_MODE2_TXBF_ACT_RPT_DONE_PASS_MASK) >> MAC_PCU_MISC_MODE2_TXBF_ACT_RPT_DONE_PASS_LSB)
#define MAC_PCU_MISC_MODE2_TXBF_ACT_RPT_DONE_PASS_SET(x)             (((0 | (x)) << MAC_PCU_MISC_MODE2_TXBF_ACT_RPT_DONE_PASS_LSB) & MAC_PCU_MISC_MODE2_TXBF_ACT_RPT_DONE_PASS_MASK)
#define MAC_PCU_MISC_MODE2_TXBF_ACT_RPT_DONE_PASS_RESET              1
#define MAC_PCU_MISC_MODE2_H_TO_SW_DEBUG_MODE_MSB                    28
#define MAC_PCU_MISC_MODE2_H_TO_SW_DEBUG_MODE_LSB                    28
#define MAC_PCU_MISC_MODE2_H_TO_SW_DEBUG_MODE_MASK                   0x10000000
#define MAC_PCU_MISC_MODE2_H_TO_SW_DEBUG_MODE_GET(x)                 (((x) & MAC_PCU_MISC_MODE2_H_TO_SW_DEBUG_MODE_MASK) >> MAC_PCU_MISC_MODE2_H_TO_SW_DEBUG_MODE_LSB)
#define MAC_PCU_MISC_MODE2_H_TO_SW_DEBUG_MODE_SET(x)                 (((0 | (x)) << MAC_PCU_MISC_MODE2_H_TO_SW_DEBUG_MODE_LSB) & MAC_PCU_MISC_MODE2_H_TO_SW_DEBUG_MODE_MASK)
#define MAC_PCU_MISC_MODE2_H_TO_SW_DEBUG_MODE_RESET                  0
#define MAC_PCU_MISC_MODE2_DECOUPLE_DECRYPTION_MSB                   27
#define MAC_PCU_MISC_MODE2_DECOUPLE_DECRYPTION_LSB                   27
#define MAC_PCU_MISC_MODE2_DECOUPLE_DECRYPTION_MASK                  0x08000000
#define MAC_PCU_MISC_MODE2_DECOUPLE_DECRYPTION_GET(x)                (((x) & MAC_PCU_MISC_MODE2_DECOUPLE_DECRYPTION_MASK) >> MAC_PCU_MISC_MODE2_DECOUPLE_DECRYPTION_LSB)
#define MAC_PCU_MISC_MODE2_DECOUPLE_DECRYPTION_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE2_DECOUPLE_DECRYPTION_LSB) & MAC_PCU_MISC_MODE2_DECOUPLE_DECRYPTION_MASK)
#define MAC_PCU_MISC_MODE2_DECOUPLE_DECRYPTION_RESET                 1
#define MAC_PCU_MISC_MODE2_RCV_TIMESTAMP_FIX_MSB                     25
#define MAC_PCU_MISC_MODE2_RCV_TIMESTAMP_FIX_LSB                     25
#define MAC_PCU_MISC_MODE2_RCV_TIMESTAMP_FIX_MASK                    0x02000000
#define MAC_PCU_MISC_MODE2_RCV_TIMESTAMP_FIX_GET(x)                  (((x) & MAC_PCU_MISC_MODE2_RCV_TIMESTAMP_FIX_MASK) >> MAC_PCU_MISC_MODE2_RCV_TIMESTAMP_FIX_LSB)
#define MAC_PCU_MISC_MODE2_RCV_TIMESTAMP_FIX_SET(x)                  (((0 | (x)) << MAC_PCU_MISC_MODE2_RCV_TIMESTAMP_FIX_LSB) & MAC_PCU_MISC_MODE2_RCV_TIMESTAMP_FIX_MASK)
#define MAC_PCU_MISC_MODE2_RCV_TIMESTAMP_FIX_RESET                   1
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_WAIT_WEP_MSB                 24
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_WAIT_WEP_LSB                 24
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_WAIT_WEP_MASK                0x01000000
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_WAIT_WEP_GET(x)              (((x) & MAC_PCU_MISC_MODE2_MPDU_DENSITY_WAIT_WEP_MASK) >> MAC_PCU_MISC_MODE2_MPDU_DENSITY_WAIT_WEP_LSB)
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_WAIT_WEP_SET(x)              (((0 | (x)) << MAC_PCU_MISC_MODE2_MPDU_DENSITY_WAIT_WEP_LSB) & MAC_PCU_MISC_MODE2_MPDU_DENSITY_WAIT_WEP_MASK)
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_WAIT_WEP_RESET               0
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_STS_FIX_MSB                  23
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_STS_FIX_LSB                  23
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_STS_FIX_MASK                 0x00800000
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_STS_FIX_GET(x)               (((x) & MAC_PCU_MISC_MODE2_MPDU_DENSITY_STS_FIX_MASK) >> MAC_PCU_MISC_MODE2_MPDU_DENSITY_STS_FIX_LSB)
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_STS_FIX_SET(x)               (((0 | (x)) << MAC_PCU_MISC_MODE2_MPDU_DENSITY_STS_FIX_LSB) & MAC_PCU_MISC_MODE2_MPDU_DENSITY_STS_FIX_MASK)
#define MAC_PCU_MISC_MODE2_MPDU_DENSITY_STS_FIX_RESET                0
#define MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT_MSB                   22
#define MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT_LSB                   22
#define MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT_MASK                  0x00400000
#define MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT_GET(x)                (((x) & MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT_MASK) >> MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT_LSB)
#define MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT_LSB) & MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT_MASK)
#define MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT_RESET                 1
#define MAC_PCU_MISC_MODE2_CLEAR_MORE_FRAG_MSB                       21
#define MAC_PCU_MISC_MODE2_CLEAR_MORE_FRAG_LSB                       21
#define MAC_PCU_MISC_MODE2_CLEAR_MORE_FRAG_MASK                      0x00200000
#define MAC_PCU_MISC_MODE2_CLEAR_MORE_FRAG_GET(x)                    (((x) & MAC_PCU_MISC_MODE2_CLEAR_MORE_FRAG_MASK) >> MAC_PCU_MISC_MODE2_CLEAR_MORE_FRAG_LSB)
#define MAC_PCU_MISC_MODE2_CLEAR_MORE_FRAG_SET(x)                    (((0 | (x)) << MAC_PCU_MISC_MODE2_CLEAR_MORE_FRAG_LSB) & MAC_PCU_MISC_MODE2_CLEAR_MORE_FRAG_MASK)
#define MAC_PCU_MISC_MODE2_CLEAR_MORE_FRAG_RESET                     0
#define MAC_PCU_MISC_MODE2_BUG_28676_MSB                             20
#define MAC_PCU_MISC_MODE2_BUG_28676_LSB                             20
#define MAC_PCU_MISC_MODE2_BUG_28676_MASK                            0x00100000
#define MAC_PCU_MISC_MODE2_BUG_28676_GET(x)                          (((x) & MAC_PCU_MISC_MODE2_BUG_28676_MASK) >> MAC_PCU_MISC_MODE2_BUG_28676_LSB)
#define MAC_PCU_MISC_MODE2_BUG_28676_SET(x)                          (((0 | (x)) << MAC_PCU_MISC_MODE2_BUG_28676_LSB) & MAC_PCU_MISC_MODE2_BUG_28676_MASK)
#define MAC_PCU_MISC_MODE2_BUG_28676_RESET                           1
#define MAC_PCU_MISC_MODE2_DUR_ACCOUNT_BY_BA_MSB                     19
#define MAC_PCU_MISC_MODE2_DUR_ACCOUNT_BY_BA_LSB                     19
#define MAC_PCU_MISC_MODE2_DUR_ACCOUNT_BY_BA_MASK                    0x00080000
#define MAC_PCU_MISC_MODE2_DUR_ACCOUNT_BY_BA_GET(x)                  (((x) & MAC_PCU_MISC_MODE2_DUR_ACCOUNT_BY_BA_MASK) >> MAC_PCU_MISC_MODE2_DUR_ACCOUNT_BY_BA_LSB)
#define MAC_PCU_MISC_MODE2_DUR_ACCOUNT_BY_BA_SET(x)                  (((0 | (x)) << MAC_PCU_MISC_MODE2_DUR_ACCOUNT_BY_BA_LSB) & MAC_PCU_MISC_MODE2_DUR_ACCOUNT_BY_BA_MASK)
#define MAC_PCU_MISC_MODE2_DUR_ACCOUNT_BY_BA_RESET                   1
#define MAC_PCU_MISC_MODE2_BC_MC_WAPI_MODE_MSB                       18
#define MAC_PCU_MISC_MODE2_BC_MC_WAPI_MODE_LSB                       18
#define MAC_PCU_MISC_MODE2_BC_MC_WAPI_MODE_MASK                      0x00040000
#define MAC_PCU_MISC_MODE2_BC_MC_WAPI_MODE_GET(x)                    (((x) & MAC_PCU_MISC_MODE2_BC_MC_WAPI_MODE_MASK) >> MAC_PCU_MISC_MODE2_BC_MC_WAPI_MODE_LSB)
#define MAC_PCU_MISC_MODE2_BC_MC_WAPI_MODE_SET(x)                    (((0 | (x)) << MAC_PCU_MISC_MODE2_BC_MC_WAPI_MODE_LSB) & MAC_PCU_MISC_MODE2_BC_MC_WAPI_MODE_MASK)
#define MAC_PCU_MISC_MODE2_BC_MC_WAPI_MODE_RESET                     0
#define MAC_PCU_MISC_MODE2_AGG_WEP_MSB                               17
#define MAC_PCU_MISC_MODE2_AGG_WEP_LSB                               17
#define MAC_PCU_MISC_MODE2_AGG_WEP_MASK                              0x00020000
#define MAC_PCU_MISC_MODE2_AGG_WEP_GET(x)                            (((x) & MAC_PCU_MISC_MODE2_AGG_WEP_MASK) >> MAC_PCU_MISC_MODE2_AGG_WEP_LSB)
#define MAC_PCU_MISC_MODE2_AGG_WEP_SET(x)                            (((0 | (x)) << MAC_PCU_MISC_MODE2_AGG_WEP_LSB) & MAC_PCU_MISC_MODE2_AGG_WEP_MASK)
#define MAC_PCU_MISC_MODE2_AGG_WEP_RESET                             1
#define MAC_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION_MSB       16
#define MAC_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION_LSB       16
#define MAC_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION_MASK      0x00010000
#define MAC_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION_GET(x)    (((x) & MAC_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION_MASK) >> MAC_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION_LSB)
#define MAC_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION_SET(x)    (((0 | (x)) << MAC_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION_LSB) & MAC_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION_MASK)
#define MAC_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION_RESET     0
#define MAC_PCU_MISC_MODE2_MGMT_QOS_MSB                              15
#define MAC_PCU_MISC_MODE2_MGMT_QOS_LSB                              8
#define MAC_PCU_MISC_MODE2_MGMT_QOS_MASK                             0x0000ff00
#define MAC_PCU_MISC_MODE2_MGMT_QOS_GET(x)                           (((x) & MAC_PCU_MISC_MODE2_MGMT_QOS_MASK) >> MAC_PCU_MISC_MODE2_MGMT_QOS_LSB)
#define MAC_PCU_MISC_MODE2_MGMT_QOS_SET(x)                           (((0 | (x)) << MAC_PCU_MISC_MODE2_MGMT_QOS_LSB) & MAC_PCU_MISC_MODE2_MGMT_QOS_MASK)
#define MAC_PCU_MISC_MODE2_MGMT_QOS_RESET                            16
#define MAC_PCU_MISC_MODE2_CFP_IGNORE_MSB                            7
#define MAC_PCU_MISC_MODE2_CFP_IGNORE_LSB                            7
#define MAC_PCU_MISC_MODE2_CFP_IGNORE_MASK                           0x00000080
#define MAC_PCU_MISC_MODE2_CFP_IGNORE_GET(x)                         (((x) & MAC_PCU_MISC_MODE2_CFP_IGNORE_MASK) >> MAC_PCU_MISC_MODE2_CFP_IGNORE_LSB)
#define MAC_PCU_MISC_MODE2_CFP_IGNORE_SET(x)                         (((0 | (x)) << MAC_PCU_MISC_MODE2_CFP_IGNORE_LSB) & MAC_PCU_MISC_MODE2_CFP_IGNORE_MASK)
#define MAC_PCU_MISC_MODE2_CFP_IGNORE_RESET                          0
#define MAC_PCU_MISC_MODE2_ADHOC_MCAST_KEYID_ENABLE_MSB              6
#define MAC_PCU_MISC_MODE2_ADHOC_MCAST_KEYID_ENABLE_LSB              6
#define MAC_PCU_MISC_MODE2_ADHOC_MCAST_KEYID_ENABLE_MASK             0x00000040
#define MAC_PCU_MISC_MODE2_ADHOC_MCAST_KEYID_ENABLE_GET(x)           (((x) & MAC_PCU_MISC_MODE2_ADHOC_MCAST_KEYID_ENABLE_MASK) >> MAC_PCU_MISC_MODE2_ADHOC_MCAST_KEYID_ENABLE_LSB)
#define MAC_PCU_MISC_MODE2_ADHOC_MCAST_KEYID_ENABLE_SET(x)           (((0 | (x)) << MAC_PCU_MISC_MODE2_ADHOC_MCAST_KEYID_ENABLE_LSB) & MAC_PCU_MISC_MODE2_ADHOC_MCAST_KEYID_ENABLE_MASK)
#define MAC_PCU_MISC_MODE2_ADHOC_MCAST_KEYID_ENABLE_RESET            1
#define MAC_PCU_MISC_MODE2_EV_76218_FIX_DISABLE_MSB                  5
#define MAC_PCU_MISC_MODE2_EV_76218_FIX_DISABLE_LSB                  5
#define MAC_PCU_MISC_MODE2_EV_76218_FIX_DISABLE_MASK                 0x00000020
#define MAC_PCU_MISC_MODE2_EV_76218_FIX_DISABLE_GET(x)               (((x) & MAC_PCU_MISC_MODE2_EV_76218_FIX_DISABLE_MASK) >> MAC_PCU_MISC_MODE2_EV_76218_FIX_DISABLE_LSB)
#define MAC_PCU_MISC_MODE2_EV_76218_FIX_DISABLE_SET(x)               (((0 | (x)) << MAC_PCU_MISC_MODE2_EV_76218_FIX_DISABLE_LSB) & MAC_PCU_MISC_MODE2_EV_76218_FIX_DISABLE_MASK)
#define MAC_PCU_MISC_MODE2_EV_76218_FIX_DISABLE_RESET                0
#define MAC_PCU_MISC_MODE2_BUG_58057_FIX_ENABLE_MSB                  4
#define MAC_PCU_MISC_MODE2_BUG_58057_FIX_ENABLE_LSB                  4
#define MAC_PCU_MISC_MODE2_BUG_58057_FIX_ENABLE_MASK                 0x00000010
#define MAC_PCU_MISC_MODE2_BUG_58057_FIX_ENABLE_GET(x)               (((x) & MAC_PCU_MISC_MODE2_BUG_58057_FIX_ENABLE_MASK) >> MAC_PCU_MISC_MODE2_BUG_58057_FIX_ENABLE_LSB)
#define MAC_PCU_MISC_MODE2_BUG_58057_FIX_ENABLE_SET(x)               (((0 | (x)) << MAC_PCU_MISC_MODE2_BUG_58057_FIX_ENABLE_LSB) & MAC_PCU_MISC_MODE2_BUG_58057_FIX_ENABLE_MASK)
#define MAC_PCU_MISC_MODE2_BUG_58057_FIX_ENABLE_RESET                1
#define MAC_PCU_MISC_MODE2_BUG_58603_FIX_ENABLE_MSB                  3
#define MAC_PCU_MISC_MODE2_BUG_58603_FIX_ENABLE_LSB                  3
#define MAC_PCU_MISC_MODE2_BUG_58603_FIX_ENABLE_MASK                 0x00000008
#define MAC_PCU_MISC_MODE2_BUG_58603_FIX_ENABLE_GET(x)               (((x) & MAC_PCU_MISC_MODE2_BUG_58603_FIX_ENABLE_MASK) >> MAC_PCU_MISC_MODE2_BUG_58603_FIX_ENABLE_LSB)
#define MAC_PCU_MISC_MODE2_BUG_58603_FIX_ENABLE_SET(x)               (((0 | (x)) << MAC_PCU_MISC_MODE2_BUG_58603_FIX_ENABLE_LSB) & MAC_PCU_MISC_MODE2_BUG_58603_FIX_ENABLE_MASK)
#define MAC_PCU_MISC_MODE2_BUG_58603_FIX_ENABLE_RESET                1
#define MAC_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT_MSB            2
#define MAC_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT_LSB            2
#define MAC_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT_MASK           0x00000004
#define MAC_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT_GET(x)         (((x) & MAC_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT_MASK) >> MAC_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT_LSB)
#define MAC_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT_SET(x)         (((0 | (x)) << MAC_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT_LSB) & MAC_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT_MASK)
#define MAC_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT_RESET          0
#define MAC_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE_MSB                    1
#define MAC_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE_LSB                    1
#define MAC_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE_MASK                   0x00000002
#define MAC_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE_GET(x)                 (((x) & MAC_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE_MASK) >> MAC_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE_LSB)
#define MAC_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE_SET(x)                 (((0 | (x)) << MAC_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE_LSB) & MAC_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE_MASK)
#define MAC_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE_RESET                  1
#define MAC_PCU_MISC_MODE2_BUG_21532_FIX_ENABLE_MSB                  0
#define MAC_PCU_MISC_MODE2_BUG_21532_FIX_ENABLE_LSB                  0
#define MAC_PCU_MISC_MODE2_BUG_21532_FIX_ENABLE_MASK                 0x00000001
#define MAC_PCU_MISC_MODE2_BUG_21532_FIX_ENABLE_GET(x)               (((x) & MAC_PCU_MISC_MODE2_BUG_21532_FIX_ENABLE_MASK) >> MAC_PCU_MISC_MODE2_BUG_21532_FIX_ENABLE_LSB)
#define MAC_PCU_MISC_MODE2_BUG_21532_FIX_ENABLE_SET(x)               (((0 | (x)) << MAC_PCU_MISC_MODE2_BUG_21532_FIX_ENABLE_LSB) & MAC_PCU_MISC_MODE2_BUG_21532_FIX_ENABLE_MASK)
#define MAC_PCU_MISC_MODE2_BUG_21532_FIX_ENABLE_RESET                1
#define MAC_PCU_MISC_MODE2_ADDRESS                                   0x8344
#define MAC_PCU_MISC_MODE2_HW_MASK                                   0xfbffffff
#define MAC_PCU_MISC_MODE2_SW_MASK                                   0xfbffffff
#define MAC_PCU_MISC_MODE2_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_MISC_MODE2_SW_WRITE_MASK                             0xfbffffff
#define MAC_PCU_MISC_MODE2_RSTMASK                                   0xffffffff
#define MAC_PCU_MISC_MODE2_RESET                                     0xaa5a105b

// 0x8348 (MAC_PCU_ALT_AES_MUTE_MASK)
#define MAC_PCU_ALT_AES_MUTE_MASK_QOS_MSB                            31
#define MAC_PCU_ALT_AES_MUTE_MASK_QOS_LSB                            16
#define MAC_PCU_ALT_AES_MUTE_MASK_QOS_MASK                           0xffff0000
#define MAC_PCU_ALT_AES_MUTE_MASK_QOS_GET(x)                         (((x) & MAC_PCU_ALT_AES_MUTE_MASK_QOS_MASK) >> MAC_PCU_ALT_AES_MUTE_MASK_QOS_LSB)
#define MAC_PCU_ALT_AES_MUTE_MASK_QOS_SET(x)                         (((0 | (x)) << MAC_PCU_ALT_AES_MUTE_MASK_QOS_LSB) & MAC_PCU_ALT_AES_MUTE_MASK_QOS_MASK)
#define MAC_PCU_ALT_AES_MUTE_MASK_QOS_RESET                          143
#define MAC_PCU_ALT_AES_MUTE_MASK_ADDRESS                            0x8348
#define MAC_PCU_ALT_AES_MUTE_MASK_HW_MASK                            0xffff0000
#define MAC_PCU_ALT_AES_MUTE_MASK_SW_MASK                            0xffff0000
#define MAC_PCU_ALT_AES_MUTE_MASK_HW_WRITE_MASK                      0x00000000
#define MAC_PCU_ALT_AES_MUTE_MASK_SW_WRITE_MASK                      0xffff0000
#define MAC_PCU_ALT_AES_MUTE_MASK_RSTMASK                            0xffffffff
#define MAC_PCU_ALT_AES_MUTE_MASK_RESET                              0x008f0000

// 0x834c (MAC_PCU_WOW6)
#define MAC_PCU_WOW6_RXBUF_START_ADDR_MSB                            15
#define MAC_PCU_WOW6_RXBUF_START_ADDR_LSB                            0
#define MAC_PCU_WOW6_RXBUF_START_ADDR_MASK                           0x0000ffff
#define MAC_PCU_WOW6_RXBUF_START_ADDR_GET(x)                         (((x) & MAC_PCU_WOW6_RXBUF_START_ADDR_MASK) >> MAC_PCU_WOW6_RXBUF_START_ADDR_LSB)
#define MAC_PCU_WOW6_RXBUF_START_ADDR_SET(x)                         (((0 | (x)) << MAC_PCU_WOW6_RXBUF_START_ADDR_LSB) & MAC_PCU_WOW6_RXBUF_START_ADDR_MASK)
#define MAC_PCU_WOW6_RXBUF_START_ADDR_RESET                          0
#define MAC_PCU_WOW6_ADDRESS                                         0x834c
#define MAC_PCU_WOW6_HW_MASK                                         0x0000ffff
#define MAC_PCU_WOW6_SW_MASK                                         0x0000ffff
#define MAC_PCU_WOW6_HW_WRITE_MASK                                   0x0000ffff
#define MAC_PCU_WOW6_SW_WRITE_MASK                                   0x00000000
#define MAC_PCU_WOW6_RSTMASK                                         0xffffffff
#define MAC_PCU_WOW6_RESET                                           0x00000000

// 0x835c (MAC_PCU_WOW5)
#define MAC_PCU_WOW5_RX_ABORT_ENABLE_MSB                             15
#define MAC_PCU_WOW5_RX_ABORT_ENABLE_LSB                             0
#define MAC_PCU_WOW5_RX_ABORT_ENABLE_MASK                            0x0000ffff
#define MAC_PCU_WOW5_RX_ABORT_ENABLE_GET(x)                          (((x) & MAC_PCU_WOW5_RX_ABORT_ENABLE_MASK) >> MAC_PCU_WOW5_RX_ABORT_ENABLE_LSB)
#define MAC_PCU_WOW5_RX_ABORT_ENABLE_SET(x)                          (((0 | (x)) << MAC_PCU_WOW5_RX_ABORT_ENABLE_LSB) & MAC_PCU_WOW5_RX_ABORT_ENABLE_MASK)
#define MAC_PCU_WOW5_RX_ABORT_ENABLE_RESET                           0
#define MAC_PCU_WOW5_ADDRESS                                         0x835c
#define MAC_PCU_WOW5_HW_MASK                                         0x0000ffff
#define MAC_PCU_WOW5_SW_MASK                                         0x0000ffff
#define MAC_PCU_WOW5_HW_WRITE_MASK                                   0x00000000
#define MAC_PCU_WOW5_SW_WRITE_MASK                                   0x0000ffff
#define MAC_PCU_WOW5_RSTMASK                                         0xffffffff
#define MAC_PCU_WOW5_RESET                                           0x00000000

// 0x8360 (MAC_PCU_WOW_LENGTH1)
#define MAC_PCU_WOW_LENGTH1_PATTERN_0_MSB                            31
#define MAC_PCU_WOW_LENGTH1_PATTERN_0_LSB                            24
#define MAC_PCU_WOW_LENGTH1_PATTERN_0_MASK                           0xff000000
#define MAC_PCU_WOW_LENGTH1_PATTERN_0_GET(x)                         (((x) & MAC_PCU_WOW_LENGTH1_PATTERN_0_MASK) >> MAC_PCU_WOW_LENGTH1_PATTERN_0_LSB)
#define MAC_PCU_WOW_LENGTH1_PATTERN_0_SET(x)                         (((0 | (x)) << MAC_PCU_WOW_LENGTH1_PATTERN_0_LSB) & MAC_PCU_WOW_LENGTH1_PATTERN_0_MASK)
#define MAC_PCU_WOW_LENGTH1_PATTERN_0_RESET                          255
#define MAC_PCU_WOW_LENGTH1_PATTERN_1_MSB                            23
#define MAC_PCU_WOW_LENGTH1_PATTERN_1_LSB                            16
#define MAC_PCU_WOW_LENGTH1_PATTERN_1_MASK                           0x00ff0000
#define MAC_PCU_WOW_LENGTH1_PATTERN_1_GET(x)                         (((x) & MAC_PCU_WOW_LENGTH1_PATTERN_1_MASK) >> MAC_PCU_WOW_LENGTH1_PATTERN_1_LSB)
#define MAC_PCU_WOW_LENGTH1_PATTERN_1_SET(x)                         (((0 | (x)) << MAC_PCU_WOW_LENGTH1_PATTERN_1_LSB) & MAC_PCU_WOW_LENGTH1_PATTERN_1_MASK)
#define MAC_PCU_WOW_LENGTH1_PATTERN_1_RESET                          255
#define MAC_PCU_WOW_LENGTH1_PATTERN_2_MSB                            15
#define MAC_PCU_WOW_LENGTH1_PATTERN_2_LSB                            8
#define MAC_PCU_WOW_LENGTH1_PATTERN_2_MASK                           0x0000ff00
#define MAC_PCU_WOW_LENGTH1_PATTERN_2_GET(x)                         (((x) & MAC_PCU_WOW_LENGTH1_PATTERN_2_MASK) >> MAC_PCU_WOW_LENGTH1_PATTERN_2_LSB)
#define MAC_PCU_WOW_LENGTH1_PATTERN_2_SET(x)                         (((0 | (x)) << MAC_PCU_WOW_LENGTH1_PATTERN_2_LSB) & MAC_PCU_WOW_LENGTH1_PATTERN_2_MASK)
#define MAC_PCU_WOW_LENGTH1_PATTERN_2_RESET                          255
#define MAC_PCU_WOW_LENGTH1_PATTERN_3_MSB                            7
#define MAC_PCU_WOW_LENGTH1_PATTERN_3_LSB                            0
#define MAC_PCU_WOW_LENGTH1_PATTERN_3_MASK                           0x000000ff
#define MAC_PCU_WOW_LENGTH1_PATTERN_3_GET(x)                         (((x) & MAC_PCU_WOW_LENGTH1_PATTERN_3_MASK) >> MAC_PCU_WOW_LENGTH1_PATTERN_3_LSB)
#define MAC_PCU_WOW_LENGTH1_PATTERN_3_SET(x)                         (((0 | (x)) << MAC_PCU_WOW_LENGTH1_PATTERN_3_LSB) & MAC_PCU_WOW_LENGTH1_PATTERN_3_MASK)
#define MAC_PCU_WOW_LENGTH1_PATTERN_3_RESET                          255
#define MAC_PCU_WOW_LENGTH1_ADDRESS                                  0x8360
#define MAC_PCU_WOW_LENGTH1_HW_MASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH1_SW_MASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH1_HW_WRITE_MASK                            0x00000000
#define MAC_PCU_WOW_LENGTH1_SW_WRITE_MASK                            0xffffffff
#define MAC_PCU_WOW_LENGTH1_RSTMASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH1_RESET                                    0xffffffff

// 0x8364 (MAC_PCU_WOW_LENGTH2)
#define MAC_PCU_WOW_LENGTH2_PATTERN_4_MSB                            31
#define MAC_PCU_WOW_LENGTH2_PATTERN_4_LSB                            24
#define MAC_PCU_WOW_LENGTH2_PATTERN_4_MASK                           0xff000000
#define MAC_PCU_WOW_LENGTH2_PATTERN_4_GET(x)                         (((x) & MAC_PCU_WOW_LENGTH2_PATTERN_4_MASK) >> MAC_PCU_WOW_LENGTH2_PATTERN_4_LSB)
#define MAC_PCU_WOW_LENGTH2_PATTERN_4_SET(x)                         (((0 | (x)) << MAC_PCU_WOW_LENGTH2_PATTERN_4_LSB) & MAC_PCU_WOW_LENGTH2_PATTERN_4_MASK)
#define MAC_PCU_WOW_LENGTH2_PATTERN_4_RESET                          255
#define MAC_PCU_WOW_LENGTH2_PATTERN_5_MSB                            23
#define MAC_PCU_WOW_LENGTH2_PATTERN_5_LSB                            16
#define MAC_PCU_WOW_LENGTH2_PATTERN_5_MASK                           0x00ff0000
#define MAC_PCU_WOW_LENGTH2_PATTERN_5_GET(x)                         (((x) & MAC_PCU_WOW_LENGTH2_PATTERN_5_MASK) >> MAC_PCU_WOW_LENGTH2_PATTERN_5_LSB)
#define MAC_PCU_WOW_LENGTH2_PATTERN_5_SET(x)                         (((0 | (x)) << MAC_PCU_WOW_LENGTH2_PATTERN_5_LSB) & MAC_PCU_WOW_LENGTH2_PATTERN_5_MASK)
#define MAC_PCU_WOW_LENGTH2_PATTERN_5_RESET                          255
#define MAC_PCU_WOW_LENGTH2_PATTERN_6_MSB                            15
#define MAC_PCU_WOW_LENGTH2_PATTERN_6_LSB                            8
#define MAC_PCU_WOW_LENGTH2_PATTERN_6_MASK                           0x0000ff00
#define MAC_PCU_WOW_LENGTH2_PATTERN_6_GET(x)                         (((x) & MAC_PCU_WOW_LENGTH2_PATTERN_6_MASK) >> MAC_PCU_WOW_LENGTH2_PATTERN_6_LSB)
#define MAC_PCU_WOW_LENGTH2_PATTERN_6_SET(x)                         (((0 | (x)) << MAC_PCU_WOW_LENGTH2_PATTERN_6_LSB) & MAC_PCU_WOW_LENGTH2_PATTERN_6_MASK)
#define MAC_PCU_WOW_LENGTH2_PATTERN_6_RESET                          255
#define MAC_PCU_WOW_LENGTH2_PATTERN_7_MSB                            7
#define MAC_PCU_WOW_LENGTH2_PATTERN_7_LSB                            0
#define MAC_PCU_WOW_LENGTH2_PATTERN_7_MASK                           0x000000ff
#define MAC_PCU_WOW_LENGTH2_PATTERN_7_GET(x)                         (((x) & MAC_PCU_WOW_LENGTH2_PATTERN_7_MASK) >> MAC_PCU_WOW_LENGTH2_PATTERN_7_LSB)
#define MAC_PCU_WOW_LENGTH2_PATTERN_7_SET(x)                         (((0 | (x)) << MAC_PCU_WOW_LENGTH2_PATTERN_7_LSB) & MAC_PCU_WOW_LENGTH2_PATTERN_7_MASK)
#define MAC_PCU_WOW_LENGTH2_PATTERN_7_RESET                          255
#define MAC_PCU_WOW_LENGTH2_ADDRESS                                  0x8364
#define MAC_PCU_WOW_LENGTH2_HW_MASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH2_SW_MASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH2_HW_WRITE_MASK                            0x00000000
#define MAC_PCU_WOW_LENGTH2_SW_WRITE_MASK                            0xffffffff
#define MAC_PCU_WOW_LENGTH2_RSTMASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH2_RESET                                    0xffffffff

// 0x8368 (WOW_PATTERN_MATCH_LESS_THAN_256_BYTES)
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_EN_MSB                 15
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_EN_LSB                 0
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_EN_MASK                0x0000ffff
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_EN_GET(x)              (((x) & WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_EN_MASK) >> WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_EN_LSB)
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_EN_SET(x)              (((0 | (x)) << WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_EN_LSB) & WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_EN_MASK)
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_EN_RESET               0
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_ADDRESS                0x8368
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_HW_MASK                0x0000ffff
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_SW_MASK                0x0000ffff
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_HW_WRITE_MASK          0x00000000
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_SW_WRITE_MASK          0x0000ffff
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_RSTMASK                0xffffffff
#define WOW_PATTERN_MATCH_LESS_THAN_256_BYTES_RESET                  0x00000000

// 0x8370 (MAC_PCU_WOW4)
#define MAC_PCU_WOW4_PATTERN_DETECT_MSB                              15
#define MAC_PCU_WOW4_PATTERN_DETECT_LSB                              8
#define MAC_PCU_WOW4_PATTERN_DETECT_MASK                             0x0000ff00
#define MAC_PCU_WOW4_PATTERN_DETECT_GET(x)                           (((x) & MAC_PCU_WOW4_PATTERN_DETECT_MASK) >> MAC_PCU_WOW4_PATTERN_DETECT_LSB)
#define MAC_PCU_WOW4_PATTERN_DETECT_SET(x)                           (((0 | (x)) << MAC_PCU_WOW4_PATTERN_DETECT_LSB) & MAC_PCU_WOW4_PATTERN_DETECT_MASK)
#define MAC_PCU_WOW4_PATTERN_DETECT_RESET                            0
#define MAC_PCU_WOW4_PATTERN_ENABLE_MSB                              7
#define MAC_PCU_WOW4_PATTERN_ENABLE_LSB                              0
#define MAC_PCU_WOW4_PATTERN_ENABLE_MASK                             0x000000ff
#define MAC_PCU_WOW4_PATTERN_ENABLE_GET(x)                           (((x) & MAC_PCU_WOW4_PATTERN_ENABLE_MASK) >> MAC_PCU_WOW4_PATTERN_ENABLE_LSB)
#define MAC_PCU_WOW4_PATTERN_ENABLE_SET(x)                           (((0 | (x)) << MAC_PCU_WOW4_PATTERN_ENABLE_LSB) & MAC_PCU_WOW4_PATTERN_ENABLE_MASK)
#define MAC_PCU_WOW4_PATTERN_ENABLE_RESET                            0
#define MAC_PCU_WOW4_ADDRESS                                         0x8370
#define MAC_PCU_WOW4_HW_MASK                                         0x0000ffff
#define MAC_PCU_WOW4_SW_MASK                                         0x0000ffff
#define MAC_PCU_WOW4_HW_WRITE_MASK                                   0x0000ff00
#define MAC_PCU_WOW4_SW_WRITE_MASK                                   0x000000ff
#define MAC_PCU_WOW4_RSTMASK                                         0xffffffff
#define MAC_PCU_WOW4_RESET                                           0x00000000

// 0x8374 (WOW2_EXACT)
#define WOW2_EXACT_OFFSET_MSB                                        15
#define WOW2_EXACT_OFFSET_LSB                                        8
#define WOW2_EXACT_OFFSET_MASK                                       0x0000ff00
#define WOW2_EXACT_OFFSET_GET(x)                                     (((x) & WOW2_EXACT_OFFSET_MASK) >> WOW2_EXACT_OFFSET_LSB)
#define WOW2_EXACT_OFFSET_SET(x)                                     (((0 | (x)) << WOW2_EXACT_OFFSET_LSB) & WOW2_EXACT_OFFSET_MASK)
#define WOW2_EXACT_OFFSET_RESET                                      0
#define WOW2_EXACT_LENGTH_MSB                                        7
#define WOW2_EXACT_LENGTH_LSB                                        0
#define WOW2_EXACT_LENGTH_MASK                                       0x000000ff
#define WOW2_EXACT_LENGTH_GET(x)                                     (((x) & WOW2_EXACT_LENGTH_MASK) >> WOW2_EXACT_LENGTH_LSB)
#define WOW2_EXACT_LENGTH_SET(x)                                     (((0 | (x)) << WOW2_EXACT_LENGTH_LSB) & WOW2_EXACT_LENGTH_MASK)
#define WOW2_EXACT_LENGTH_RESET                                      255
#define WOW2_EXACT_ADDRESS                                           0x8374
#define WOW2_EXACT_HW_MASK                                           0x0000ffff
#define WOW2_EXACT_SW_MASK                                           0x0000ffff
#define WOW2_EXACT_HW_WRITE_MASK                                     0x00000000
#define WOW2_EXACT_SW_WRITE_MASK                                     0x0000ffff
#define WOW2_EXACT_RSTMASK                                           0xffffffff
#define WOW2_EXACT_RESET                                             0x000000ff

// 0x8378 (PCU_WOW6)
#define PCU_WOW6_OFFSET11_MSB                                        31
#define PCU_WOW6_OFFSET11_LSB                                        24
#define PCU_WOW6_OFFSET11_MASK                                       0xff000000
#define PCU_WOW6_OFFSET11_GET(x)                                     (((x) & PCU_WOW6_OFFSET11_MASK) >> PCU_WOW6_OFFSET11_LSB)
#define PCU_WOW6_OFFSET11_SET(x)                                     (((0 | (x)) << PCU_WOW6_OFFSET11_LSB) & PCU_WOW6_OFFSET11_MASK)
#define PCU_WOW6_OFFSET11_RESET                                      0
#define PCU_WOW6_OFFSET10_MSB                                        23
#define PCU_WOW6_OFFSET10_LSB                                        16
#define PCU_WOW6_OFFSET10_MASK                                       0x00ff0000
#define PCU_WOW6_OFFSET10_GET(x)                                     (((x) & PCU_WOW6_OFFSET10_MASK) >> PCU_WOW6_OFFSET10_LSB)
#define PCU_WOW6_OFFSET10_SET(x)                                     (((0 | (x)) << PCU_WOW6_OFFSET10_LSB) & PCU_WOW6_OFFSET10_MASK)
#define PCU_WOW6_OFFSET10_RESET                                      0
#define PCU_WOW6_OFFSET9_MSB                                         15
#define PCU_WOW6_OFFSET9_LSB                                         8
#define PCU_WOW6_OFFSET9_MASK                                        0x0000ff00
#define PCU_WOW6_OFFSET9_GET(x)                                      (((x) & PCU_WOW6_OFFSET9_MASK) >> PCU_WOW6_OFFSET9_LSB)
#define PCU_WOW6_OFFSET9_SET(x)                                      (((0 | (x)) << PCU_WOW6_OFFSET9_LSB) & PCU_WOW6_OFFSET9_MASK)
#define PCU_WOW6_OFFSET9_RESET                                       0
#define PCU_WOW6_OFFSET8_MSB                                         7
#define PCU_WOW6_OFFSET8_LSB                                         0
#define PCU_WOW6_OFFSET8_MASK                                        0x000000ff
#define PCU_WOW6_OFFSET8_GET(x)                                      (((x) & PCU_WOW6_OFFSET8_MASK) >> PCU_WOW6_OFFSET8_LSB)
#define PCU_WOW6_OFFSET8_SET(x)                                      (((0 | (x)) << PCU_WOW6_OFFSET8_LSB) & PCU_WOW6_OFFSET8_MASK)
#define PCU_WOW6_OFFSET8_RESET                                       0
#define PCU_WOW6_ADDRESS                                             0x8378
#define PCU_WOW6_HW_MASK                                             0xffffffff
#define PCU_WOW6_SW_MASK                                             0xffffffff
#define PCU_WOW6_HW_WRITE_MASK                                       0x00000000
#define PCU_WOW6_SW_WRITE_MASK                                       0xffffffff
#define PCU_WOW6_RSTMASK                                             0xffffffff
#define PCU_WOW6_RESET                                               0x00000000

// 0x837c (PCU_WOW7)
#define PCU_WOW7_OFFSET15_MSB                                        31
#define PCU_WOW7_OFFSET15_LSB                                        24
#define PCU_WOW7_OFFSET15_MASK                                       0xff000000
#define PCU_WOW7_OFFSET15_GET(x)                                     (((x) & PCU_WOW7_OFFSET15_MASK) >> PCU_WOW7_OFFSET15_LSB)
#define PCU_WOW7_OFFSET15_SET(x)                                     (((0 | (x)) << PCU_WOW7_OFFSET15_LSB) & PCU_WOW7_OFFSET15_MASK)
#define PCU_WOW7_OFFSET15_RESET                                      0
#define PCU_WOW7_OFFSET14_MSB                                        23
#define PCU_WOW7_OFFSET14_LSB                                        16
#define PCU_WOW7_OFFSET14_MASK                                       0x00ff0000
#define PCU_WOW7_OFFSET14_GET(x)                                     (((x) & PCU_WOW7_OFFSET14_MASK) >> PCU_WOW7_OFFSET14_LSB)
#define PCU_WOW7_OFFSET14_SET(x)                                     (((0 | (x)) << PCU_WOW7_OFFSET14_LSB) & PCU_WOW7_OFFSET14_MASK)
#define PCU_WOW7_OFFSET14_RESET                                      0
#define PCU_WOW7_OFFSET13_MSB                                        15
#define PCU_WOW7_OFFSET13_LSB                                        8
#define PCU_WOW7_OFFSET13_MASK                                       0x0000ff00
#define PCU_WOW7_OFFSET13_GET(x)                                     (((x) & PCU_WOW7_OFFSET13_MASK) >> PCU_WOW7_OFFSET13_LSB)
#define PCU_WOW7_OFFSET13_SET(x)                                     (((0 | (x)) << PCU_WOW7_OFFSET13_LSB) & PCU_WOW7_OFFSET13_MASK)
#define PCU_WOW7_OFFSET13_RESET                                      0
#define PCU_WOW7_OFFSET12_MSB                                        7
#define PCU_WOW7_OFFSET12_LSB                                        0
#define PCU_WOW7_OFFSET12_MASK                                       0x000000ff
#define PCU_WOW7_OFFSET12_GET(x)                                     (((x) & PCU_WOW7_OFFSET12_MASK) >> PCU_WOW7_OFFSET12_LSB)
#define PCU_WOW7_OFFSET12_SET(x)                                     (((0 | (x)) << PCU_WOW7_OFFSET12_LSB) & PCU_WOW7_OFFSET12_MASK)
#define PCU_WOW7_OFFSET12_RESET                                      0
#define PCU_WOW7_ADDRESS                                             0x837c
#define PCU_WOW7_HW_MASK                                             0xffffffff
#define PCU_WOW7_SW_MASK                                             0xffffffff
#define PCU_WOW7_HW_WRITE_MASK                                       0x00000000
#define PCU_WOW7_SW_WRITE_MASK                                       0xffffffff
#define PCU_WOW7_RSTMASK                                             0xffffffff
#define PCU_WOW7_RESET                                               0x00000000

// 0x8380 (MAC_PCU_WOW_LENGTH3)
#define MAC_PCU_WOW_LENGTH3_PATTERN_8_MSB                            31
#define MAC_PCU_WOW_LENGTH3_PATTERN_8_LSB                            24
#define MAC_PCU_WOW_LENGTH3_PATTERN_8_MASK                           0xff000000
#define MAC_PCU_WOW_LENGTH3_PATTERN_8_GET(x)                         (((x) & MAC_PCU_WOW_LENGTH3_PATTERN_8_MASK) >> MAC_PCU_WOW_LENGTH3_PATTERN_8_LSB)
#define MAC_PCU_WOW_LENGTH3_PATTERN_8_SET(x)                         (((0 | (x)) << MAC_PCU_WOW_LENGTH3_PATTERN_8_LSB) & MAC_PCU_WOW_LENGTH3_PATTERN_8_MASK)
#define MAC_PCU_WOW_LENGTH3_PATTERN_8_RESET                          255
#define MAC_PCU_WOW_LENGTH3_PATTERN_9_MSB                            23
#define MAC_PCU_WOW_LENGTH3_PATTERN_9_LSB                            16
#define MAC_PCU_WOW_LENGTH3_PATTERN_9_MASK                           0x00ff0000
#define MAC_PCU_WOW_LENGTH3_PATTERN_9_GET(x)                         (((x) & MAC_PCU_WOW_LENGTH3_PATTERN_9_MASK) >> MAC_PCU_WOW_LENGTH3_PATTERN_9_LSB)
#define MAC_PCU_WOW_LENGTH3_PATTERN_9_SET(x)                         (((0 | (x)) << MAC_PCU_WOW_LENGTH3_PATTERN_9_LSB) & MAC_PCU_WOW_LENGTH3_PATTERN_9_MASK)
#define MAC_PCU_WOW_LENGTH3_PATTERN_9_RESET                          255
#define MAC_PCU_WOW_LENGTH3_PATTERN_10_MSB                           15
#define MAC_PCU_WOW_LENGTH3_PATTERN_10_LSB                           8
#define MAC_PCU_WOW_LENGTH3_PATTERN_10_MASK                          0x0000ff00
#define MAC_PCU_WOW_LENGTH3_PATTERN_10_GET(x)                        (((x) & MAC_PCU_WOW_LENGTH3_PATTERN_10_MASK) >> MAC_PCU_WOW_LENGTH3_PATTERN_10_LSB)
#define MAC_PCU_WOW_LENGTH3_PATTERN_10_SET(x)                        (((0 | (x)) << MAC_PCU_WOW_LENGTH3_PATTERN_10_LSB) & MAC_PCU_WOW_LENGTH3_PATTERN_10_MASK)
#define MAC_PCU_WOW_LENGTH3_PATTERN_10_RESET                         255
#define MAC_PCU_WOW_LENGTH3_PATTERN_11_MSB                           7
#define MAC_PCU_WOW_LENGTH3_PATTERN_11_LSB                           0
#define MAC_PCU_WOW_LENGTH3_PATTERN_11_MASK                          0x000000ff
#define MAC_PCU_WOW_LENGTH3_PATTERN_11_GET(x)                        (((x) & MAC_PCU_WOW_LENGTH3_PATTERN_11_MASK) >> MAC_PCU_WOW_LENGTH3_PATTERN_11_LSB)
#define MAC_PCU_WOW_LENGTH3_PATTERN_11_SET(x)                        (((0 | (x)) << MAC_PCU_WOW_LENGTH3_PATTERN_11_LSB) & MAC_PCU_WOW_LENGTH3_PATTERN_11_MASK)
#define MAC_PCU_WOW_LENGTH3_PATTERN_11_RESET                         255
#define MAC_PCU_WOW_LENGTH3_ADDRESS                                  0x8380
#define MAC_PCU_WOW_LENGTH3_HW_MASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH3_SW_MASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH3_HW_WRITE_MASK                            0x00000000
#define MAC_PCU_WOW_LENGTH3_SW_WRITE_MASK                            0xffffffff
#define MAC_PCU_WOW_LENGTH3_RSTMASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH3_RESET                                    0xffffffff

// 0x8384 (MAC_PCU_WOW_LENGTH4)
#define MAC_PCU_WOW_LENGTH4_PATTERN_12_MSB                           31
#define MAC_PCU_WOW_LENGTH4_PATTERN_12_LSB                           24
#define MAC_PCU_WOW_LENGTH4_PATTERN_12_MASK                          0xff000000
#define MAC_PCU_WOW_LENGTH4_PATTERN_12_GET(x)                        (((x) & MAC_PCU_WOW_LENGTH4_PATTERN_12_MASK) >> MAC_PCU_WOW_LENGTH4_PATTERN_12_LSB)
#define MAC_PCU_WOW_LENGTH4_PATTERN_12_SET(x)                        (((0 | (x)) << MAC_PCU_WOW_LENGTH4_PATTERN_12_LSB) & MAC_PCU_WOW_LENGTH4_PATTERN_12_MASK)
#define MAC_PCU_WOW_LENGTH4_PATTERN_12_RESET                         255
#define MAC_PCU_WOW_LENGTH4_PATTERN_13_MSB                           23
#define MAC_PCU_WOW_LENGTH4_PATTERN_13_LSB                           16
#define MAC_PCU_WOW_LENGTH4_PATTERN_13_MASK                          0x00ff0000
#define MAC_PCU_WOW_LENGTH4_PATTERN_13_GET(x)                        (((x) & MAC_PCU_WOW_LENGTH4_PATTERN_13_MASK) >> MAC_PCU_WOW_LENGTH4_PATTERN_13_LSB)
#define MAC_PCU_WOW_LENGTH4_PATTERN_13_SET(x)                        (((0 | (x)) << MAC_PCU_WOW_LENGTH4_PATTERN_13_LSB) & MAC_PCU_WOW_LENGTH4_PATTERN_13_MASK)
#define MAC_PCU_WOW_LENGTH4_PATTERN_13_RESET                         255
#define MAC_PCU_WOW_LENGTH4_PATTERN_14_MSB                           15
#define MAC_PCU_WOW_LENGTH4_PATTERN_14_LSB                           8
#define MAC_PCU_WOW_LENGTH4_PATTERN_14_MASK                          0x0000ff00
#define MAC_PCU_WOW_LENGTH4_PATTERN_14_GET(x)                        (((x) & MAC_PCU_WOW_LENGTH4_PATTERN_14_MASK) >> MAC_PCU_WOW_LENGTH4_PATTERN_14_LSB)
#define MAC_PCU_WOW_LENGTH4_PATTERN_14_SET(x)                        (((0 | (x)) << MAC_PCU_WOW_LENGTH4_PATTERN_14_LSB) & MAC_PCU_WOW_LENGTH4_PATTERN_14_MASK)
#define MAC_PCU_WOW_LENGTH4_PATTERN_14_RESET                         255
#define MAC_PCU_WOW_LENGTH4_PATTERN_15_MSB                           7
#define MAC_PCU_WOW_LENGTH4_PATTERN_15_LSB                           0
#define MAC_PCU_WOW_LENGTH4_PATTERN_15_MASK                          0x000000ff
#define MAC_PCU_WOW_LENGTH4_PATTERN_15_GET(x)                        (((x) & MAC_PCU_WOW_LENGTH4_PATTERN_15_MASK) >> MAC_PCU_WOW_LENGTH4_PATTERN_15_LSB)
#define MAC_PCU_WOW_LENGTH4_PATTERN_15_SET(x)                        (((0 | (x)) << MAC_PCU_WOW_LENGTH4_PATTERN_15_LSB) & MAC_PCU_WOW_LENGTH4_PATTERN_15_MASK)
#define MAC_PCU_WOW_LENGTH4_PATTERN_15_RESET                         255
#define MAC_PCU_WOW_LENGTH4_ADDRESS                                  0x8384
#define MAC_PCU_WOW_LENGTH4_HW_MASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH4_SW_MASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH4_HW_WRITE_MASK                            0x00000000
#define MAC_PCU_WOW_LENGTH4_SW_WRITE_MASK                            0xffffffff
#define MAC_PCU_WOW_LENGTH4_RSTMASK                                  0xffffffff
#define MAC_PCU_WOW_LENGTH4_RESET                                    0xffffffff

// 0x8388 (MAC_PCU_LOCATION_MODE_CONTROL)
#define MAC_PCU_LOCATION_MODE_CONTROL_UPLOAD_H_DISABLE_MSB           1
#define MAC_PCU_LOCATION_MODE_CONTROL_UPLOAD_H_DISABLE_LSB           1
#define MAC_PCU_LOCATION_MODE_CONTROL_UPLOAD_H_DISABLE_MASK          0x00000002
#define MAC_PCU_LOCATION_MODE_CONTROL_UPLOAD_H_DISABLE_GET(x)        (((x) & MAC_PCU_LOCATION_MODE_CONTROL_UPLOAD_H_DISABLE_MASK) >> MAC_PCU_LOCATION_MODE_CONTROL_UPLOAD_H_DISABLE_LSB)
#define MAC_PCU_LOCATION_MODE_CONTROL_UPLOAD_H_DISABLE_SET(x)        (((0 | (x)) << MAC_PCU_LOCATION_MODE_CONTROL_UPLOAD_H_DISABLE_LSB) & MAC_PCU_LOCATION_MODE_CONTROL_UPLOAD_H_DISABLE_MASK)
#define MAC_PCU_LOCATION_MODE_CONTROL_UPLOAD_H_DISABLE_RESET         0
#define MAC_PCU_LOCATION_MODE_CONTROL_ENABLE_MSB                     0
#define MAC_PCU_LOCATION_MODE_CONTROL_ENABLE_LSB                     0
#define MAC_PCU_LOCATION_MODE_CONTROL_ENABLE_MASK                    0x00000001
#define MAC_PCU_LOCATION_MODE_CONTROL_ENABLE_GET(x)                  (((x) & MAC_PCU_LOCATION_MODE_CONTROL_ENABLE_MASK) >> MAC_PCU_LOCATION_MODE_CONTROL_ENABLE_LSB)
#define MAC_PCU_LOCATION_MODE_CONTROL_ENABLE_SET(x)                  (((0 | (x)) << MAC_PCU_LOCATION_MODE_CONTROL_ENABLE_LSB) & MAC_PCU_LOCATION_MODE_CONTROL_ENABLE_MASK)
#define MAC_PCU_LOCATION_MODE_CONTROL_ENABLE_RESET                   0
#define MAC_PCU_LOCATION_MODE_CONTROL_ADDRESS                        0x8388
#define MAC_PCU_LOCATION_MODE_CONTROL_HW_MASK                        0x00000003
#define MAC_PCU_LOCATION_MODE_CONTROL_SW_MASK                        0x00000003
#define MAC_PCU_LOCATION_MODE_CONTROL_HW_WRITE_MASK                  0x00000000
#define MAC_PCU_LOCATION_MODE_CONTROL_SW_WRITE_MASK                  0x00000003
#define MAC_PCU_LOCATION_MODE_CONTROL_RSTMASK                        0xffffffff
#define MAC_PCU_LOCATION_MODE_CONTROL_RESET                          0x00000000

// 0x838c (MAC_PCU_LOCATION_MODE_TIMER)
#define MAC_PCU_LOCATION_MODE_TIMER_VALUE_MSB                        31
#define MAC_PCU_LOCATION_MODE_TIMER_VALUE_LSB                        0
#define MAC_PCU_LOCATION_MODE_TIMER_VALUE_MASK                       0xffffffff
#define MAC_PCU_LOCATION_MODE_TIMER_VALUE_GET(x)                     (((x) & MAC_PCU_LOCATION_MODE_TIMER_VALUE_MASK) >> MAC_PCU_LOCATION_MODE_TIMER_VALUE_LSB)
#define MAC_PCU_LOCATION_MODE_TIMER_VALUE_SET(x)                     (((0 | (x)) << MAC_PCU_LOCATION_MODE_TIMER_VALUE_LSB) & MAC_PCU_LOCATION_MODE_TIMER_VALUE_MASK)
#define MAC_PCU_LOCATION_MODE_TIMER_VALUE_RESET                      0
#define MAC_PCU_LOCATION_MODE_TIMER_ADDRESS                          0x838c
#define MAC_PCU_LOCATION_MODE_TIMER_HW_MASK                          0xffffffff
#define MAC_PCU_LOCATION_MODE_TIMER_SW_MASK                          0xffffffff
#define MAC_PCU_LOCATION_MODE_TIMER_HW_WRITE_MASK                    0xffffffff
#define MAC_PCU_LOCATION_MODE_TIMER_SW_WRITE_MASK                    0xffffffff
#define MAC_PCU_LOCATION_MODE_TIMER_RSTMASK                          0xffffffff
#define MAC_PCU_LOCATION_MODE_TIMER_RESET                            0x00000000

// 0x8398 (MAC_PCU_BSSID2_L32)
#define MAC_PCU_BSSID2_L32_ADDR_MSB                                  31
#define MAC_PCU_BSSID2_L32_ADDR_LSB                                  0
#define MAC_PCU_BSSID2_L32_ADDR_MASK                                 0xffffffff
#define MAC_PCU_BSSID2_L32_ADDR_GET(x)                               (((x) & MAC_PCU_BSSID2_L32_ADDR_MASK) >> MAC_PCU_BSSID2_L32_ADDR_LSB)
#define MAC_PCU_BSSID2_L32_ADDR_SET(x)                               (((0 | (x)) << MAC_PCU_BSSID2_L32_ADDR_LSB) & MAC_PCU_BSSID2_L32_ADDR_MASK)
#define MAC_PCU_BSSID2_L32_ADDR_RESET                                0
#define MAC_PCU_BSSID2_L32_ADDRESS                                   0x8398
#define MAC_PCU_BSSID2_L32_HW_MASK                                   0xffffffff
#define MAC_PCU_BSSID2_L32_SW_MASK                                   0xffffffff
#define MAC_PCU_BSSID2_L32_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_BSSID2_L32_SW_WRITE_MASK                             0xffffffff
#define MAC_PCU_BSSID2_L32_RSTMASK                                   0xffffffff
#define MAC_PCU_BSSID2_L32_RESET                                     0x00000000

// 0x839c (MAC_PCU_BSSID2_U16)
#define MAC_PCU_BSSID2_U16_AID_MSB                                   30
#define MAC_PCU_BSSID2_U16_AID_LSB                                   20
#define MAC_PCU_BSSID2_U16_AID_MASK                                  0x7ff00000
#define MAC_PCU_BSSID2_U16_AID_GET(x)                                (((x) & MAC_PCU_BSSID2_U16_AID_MASK) >> MAC_PCU_BSSID2_U16_AID_LSB)
#define MAC_PCU_BSSID2_U16_AID_SET(x)                                (((0 | (x)) << MAC_PCU_BSSID2_U16_AID_LSB) & MAC_PCU_BSSID2_U16_AID_MASK)
#define MAC_PCU_BSSID2_U16_AID_RESET                                 0
#define MAC_PCU_BSSID2_U16_ENABLE_MSB                                16
#define MAC_PCU_BSSID2_U16_ENABLE_LSB                                16
#define MAC_PCU_BSSID2_U16_ENABLE_MASK                               0x00010000
#define MAC_PCU_BSSID2_U16_ENABLE_GET(x)                             (((x) & MAC_PCU_BSSID2_U16_ENABLE_MASK) >> MAC_PCU_BSSID2_U16_ENABLE_LSB)
#define MAC_PCU_BSSID2_U16_ENABLE_SET(x)                             (((0 | (x)) << MAC_PCU_BSSID2_U16_ENABLE_LSB) & MAC_PCU_BSSID2_U16_ENABLE_MASK)
#define MAC_PCU_BSSID2_U16_ENABLE_RESET                              0
#define MAC_PCU_BSSID2_U16_ADDR_MSB                                  15
#define MAC_PCU_BSSID2_U16_ADDR_LSB                                  0
#define MAC_PCU_BSSID2_U16_ADDR_MASK                                 0x0000ffff
#define MAC_PCU_BSSID2_U16_ADDR_GET(x)                               (((x) & MAC_PCU_BSSID2_U16_ADDR_MASK) >> MAC_PCU_BSSID2_U16_ADDR_LSB)
#define MAC_PCU_BSSID2_U16_ADDR_SET(x)                               (((0 | (x)) << MAC_PCU_BSSID2_U16_ADDR_LSB) & MAC_PCU_BSSID2_U16_ADDR_MASK)
#define MAC_PCU_BSSID2_U16_ADDR_RESET                                0
#define MAC_PCU_BSSID2_U16_ADDRESS                                   0x839c
#define MAC_PCU_BSSID2_U16_HW_MASK                                   0x7ff1ffff
#define MAC_PCU_BSSID2_U16_SW_MASK                                   0x7ff1ffff
#define MAC_PCU_BSSID2_U16_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_BSSID2_U16_SW_WRITE_MASK                             0x7ff1ffff
#define MAC_PCU_BSSID2_U16_RSTMASK                                   0xffffffff
#define MAC_PCU_BSSID2_U16_RESET                                     0x00000000

// 0x83a0 (MAC_PCU_DIRECT_CONNECT)
#define MAC_PCU_DIRECT_CONNECT_RESERVED_2_MSB                        31
#define MAC_PCU_DIRECT_CONNECT_RESERVED_2_LSB                        17
#define MAC_PCU_DIRECT_CONNECT_RESERVED_2_MASK                       0xfffe0000
#define MAC_PCU_DIRECT_CONNECT_RESERVED_2_GET(x)                     (((x) & MAC_PCU_DIRECT_CONNECT_RESERVED_2_MASK) >> MAC_PCU_DIRECT_CONNECT_RESERVED_2_LSB)
#define MAC_PCU_DIRECT_CONNECT_RESERVED_2_SET(x)                     (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_RESERVED_2_LSB) & MAC_PCU_DIRECT_CONNECT_RESERVED_2_MASK)
#define MAC_PCU_DIRECT_CONNECT_RESERVED_2_RESET                      0
#define MAC_PCU_DIRECT_CONNECT_SVD_TSF_SEL_EN_MSB                    16
#define MAC_PCU_DIRECT_CONNECT_SVD_TSF_SEL_EN_LSB                    16
#define MAC_PCU_DIRECT_CONNECT_SVD_TSF_SEL_EN_MASK                   0x00010000
#define MAC_PCU_DIRECT_CONNECT_SVD_TSF_SEL_EN_GET(x)                 (((x) & MAC_PCU_DIRECT_CONNECT_SVD_TSF_SEL_EN_MASK) >> MAC_PCU_DIRECT_CONNECT_SVD_TSF_SEL_EN_LSB)
#define MAC_PCU_DIRECT_CONNECT_SVD_TSF_SEL_EN_SET(x)                 (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_SVD_TSF_SEL_EN_LSB) & MAC_PCU_DIRECT_CONNECT_SVD_TSF_SEL_EN_MASK)
#define MAC_PCU_DIRECT_CONNECT_SVD_TSF_SEL_EN_RESET                  1
#define MAC_PCU_DIRECT_CONNECT_BC_MC_WAPI_MODE_AP_SEL_MSB            15
#define MAC_PCU_DIRECT_CONNECT_BC_MC_WAPI_MODE_AP_SEL_LSB            15
#define MAC_PCU_DIRECT_CONNECT_BC_MC_WAPI_MODE_AP_SEL_MASK           0x00008000
#define MAC_PCU_DIRECT_CONNECT_BC_MC_WAPI_MODE_AP_SEL_GET(x)         (((x) & MAC_PCU_DIRECT_CONNECT_BC_MC_WAPI_MODE_AP_SEL_MASK) >> MAC_PCU_DIRECT_CONNECT_BC_MC_WAPI_MODE_AP_SEL_LSB)
#define MAC_PCU_DIRECT_CONNECT_BC_MC_WAPI_MODE_AP_SEL_SET(x)         (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_BC_MC_WAPI_MODE_AP_SEL_LSB) & MAC_PCU_DIRECT_CONNECT_BC_MC_WAPI_MODE_AP_SEL_MASK)
#define MAC_PCU_DIRECT_CONNECT_BC_MC_WAPI_MODE_AP_SEL_RESET          0
#define MAC_PCU_DIRECT_CONNECT_RESERVED_1_MSB                        14
#define MAC_PCU_DIRECT_CONNECT_RESERVED_1_LSB                        10
#define MAC_PCU_DIRECT_CONNECT_RESERVED_1_MASK                       0x00007c00
#define MAC_PCU_DIRECT_CONNECT_RESERVED_1_GET(x)                     (((x) & MAC_PCU_DIRECT_CONNECT_RESERVED_1_MASK) >> MAC_PCU_DIRECT_CONNECT_RESERVED_1_LSB)
#define MAC_PCU_DIRECT_CONNECT_RESERVED_1_SET(x)                     (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_RESERVED_1_LSB) & MAC_PCU_DIRECT_CONNECT_RESERVED_1_MASK)
#define MAC_PCU_DIRECT_CONNECT_RESERVED_1_RESET                      0
#define MAC_PCU_DIRECT_CONNECT_TSF1_CLK_REQ_DISABLE_MSB              9
#define MAC_PCU_DIRECT_CONNECT_TSF1_CLK_REQ_DISABLE_LSB              9
#define MAC_PCU_DIRECT_CONNECT_TSF1_CLK_REQ_DISABLE_MASK             0x00000200
#define MAC_PCU_DIRECT_CONNECT_TSF1_CLK_REQ_DISABLE_GET(x)           (((x) & MAC_PCU_DIRECT_CONNECT_TSF1_CLK_REQ_DISABLE_MASK) >> MAC_PCU_DIRECT_CONNECT_TSF1_CLK_REQ_DISABLE_LSB)
#define MAC_PCU_DIRECT_CONNECT_TSF1_CLK_REQ_DISABLE_SET(x)           (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_TSF1_CLK_REQ_DISABLE_LSB) & MAC_PCU_DIRECT_CONNECT_TSF1_CLK_REQ_DISABLE_MASK)
#define MAC_PCU_DIRECT_CONNECT_TSF1_CLK_REQ_DISABLE_RESET            0
#define MAC_PCU_DIRECT_CONNECT_RESERVED_0_MSB                        8
#define MAC_PCU_DIRECT_CONNECT_RESERVED_0_LSB                        8
#define MAC_PCU_DIRECT_CONNECT_RESERVED_0_MASK                       0x00000100
#define MAC_PCU_DIRECT_CONNECT_RESERVED_0_GET(x)                     (((x) & MAC_PCU_DIRECT_CONNECT_RESERVED_0_MASK) >> MAC_PCU_DIRECT_CONNECT_RESERVED_0_LSB)
#define MAC_PCU_DIRECT_CONNECT_RESERVED_0_SET(x)                     (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_RESERVED_0_LSB) & MAC_PCU_DIRECT_CONNECT_RESERVED_0_MASK)
#define MAC_PCU_DIRECT_CONNECT_RESERVED_0_RESET                      0
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_OVERRIDE_MSB                7
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_OVERRIDE_LSB                7
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_OVERRIDE_MASK               0x00000080
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_OVERRIDE_GET(x)             (((x) & MAC_PCU_DIRECT_CONNECT_BMISS_CNT_OVERRIDE_MASK) >> MAC_PCU_DIRECT_CONNECT_BMISS_CNT_OVERRIDE_LSB)
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_OVERRIDE_SET(x)             (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_BMISS_CNT_OVERRIDE_LSB) & MAC_PCU_DIRECT_CONNECT_BMISS_CNT_OVERRIDE_MASK)
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_OVERRIDE_RESET              0
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_TSF_SEL_MSB                 6
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_TSF_SEL_LSB                 6
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_TSF_SEL_MASK                0x00000040
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_TSF_SEL_GET(x)              (((x) & MAC_PCU_DIRECT_CONNECT_BMISS_CNT_TSF_SEL_MASK) >> MAC_PCU_DIRECT_CONNECT_BMISS_CNT_TSF_SEL_LSB)
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_TSF_SEL_SET(x)              (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_BMISS_CNT_TSF_SEL_LSB) & MAC_PCU_DIRECT_CONNECT_BMISS_CNT_TSF_SEL_MASK)
#define MAC_PCU_DIRECT_CONNECT_BMISS_CNT_TSF_SEL_RESET               0
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON2_OVERRIDE_MSB               5
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON2_OVERRIDE_LSB               5
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON2_OVERRIDE_MASK              0x00000020
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON2_OVERRIDE_GET(x)            (((x) & MAC_PCU_DIRECT_CONNECT_MY_BEACON2_OVERRIDE_MASK) >> MAC_PCU_DIRECT_CONNECT_MY_BEACON2_OVERRIDE_LSB)
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON2_OVERRIDE_SET(x)            (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_MY_BEACON2_OVERRIDE_LSB) & MAC_PCU_DIRECT_CONNECT_MY_BEACON2_OVERRIDE_MASK)
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON2_OVERRIDE_RESET             0
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON_OVERRIDE_MSB                4
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON_OVERRIDE_LSB                4
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON_OVERRIDE_MASK               0x00000010
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON_OVERRIDE_GET(x)             (((x) & MAC_PCU_DIRECT_CONNECT_MY_BEACON_OVERRIDE_MASK) >> MAC_PCU_DIRECT_CONNECT_MY_BEACON_OVERRIDE_LSB)
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON_OVERRIDE_SET(x)             (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_MY_BEACON_OVERRIDE_LSB) & MAC_PCU_DIRECT_CONNECT_MY_BEACON_OVERRIDE_MASK)
#define MAC_PCU_DIRECT_CONNECT_MY_BEACON_OVERRIDE_RESET              0
#define MAC_PCU_DIRECT_CONNECT_TSF2_UPDATE_MSB                       3
#define MAC_PCU_DIRECT_CONNECT_TSF2_UPDATE_LSB                       3
#define MAC_PCU_DIRECT_CONNECT_TSF2_UPDATE_MASK                      0x00000008
#define MAC_PCU_DIRECT_CONNECT_TSF2_UPDATE_GET(x)                    (((x) & MAC_PCU_DIRECT_CONNECT_TSF2_UPDATE_MASK) >> MAC_PCU_DIRECT_CONNECT_TSF2_UPDATE_LSB)
#define MAC_PCU_DIRECT_CONNECT_TSF2_UPDATE_SET(x)                    (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_TSF2_UPDATE_LSB) & MAC_PCU_DIRECT_CONNECT_TSF2_UPDATE_MASK)
#define MAC_PCU_DIRECT_CONNECT_TSF2_UPDATE_RESET                     0
#define MAC_PCU_DIRECT_CONNECT_TSF1_UPDATE_MSB                       2
#define MAC_PCU_DIRECT_CONNECT_TSF1_UPDATE_LSB                       2
#define MAC_PCU_DIRECT_CONNECT_TSF1_UPDATE_MASK                      0x00000004
#define MAC_PCU_DIRECT_CONNECT_TSF1_UPDATE_GET(x)                    (((x) & MAC_PCU_DIRECT_CONNECT_TSF1_UPDATE_MASK) >> MAC_PCU_DIRECT_CONNECT_TSF1_UPDATE_LSB)
#define MAC_PCU_DIRECT_CONNECT_TSF1_UPDATE_SET(x)                    (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_TSF1_UPDATE_LSB) & MAC_PCU_DIRECT_CONNECT_TSF1_UPDATE_MASK)
#define MAC_PCU_DIRECT_CONNECT_TSF1_UPDATE_RESET                     1
#define MAC_PCU_DIRECT_CONNECT_TS_TSF_SEL_MSB                        1
#define MAC_PCU_DIRECT_CONNECT_TS_TSF_SEL_LSB                        1
#define MAC_PCU_DIRECT_CONNECT_TS_TSF_SEL_MASK                       0x00000002
#define MAC_PCU_DIRECT_CONNECT_TS_TSF_SEL_GET(x)                     (((x) & MAC_PCU_DIRECT_CONNECT_TS_TSF_SEL_MASK) >> MAC_PCU_DIRECT_CONNECT_TS_TSF_SEL_LSB)
#define MAC_PCU_DIRECT_CONNECT_TS_TSF_SEL_SET(x)                     (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_TS_TSF_SEL_LSB) & MAC_PCU_DIRECT_CONNECT_TS_TSF_SEL_MASK)
#define MAC_PCU_DIRECT_CONNECT_TS_TSF_SEL_RESET                      0
#define MAC_PCU_DIRECT_CONNECT_TSF2_ENABLE_MSB                       0
#define MAC_PCU_DIRECT_CONNECT_TSF2_ENABLE_LSB                       0
#define MAC_PCU_DIRECT_CONNECT_TSF2_ENABLE_MASK                      0x00000001
#define MAC_PCU_DIRECT_CONNECT_TSF2_ENABLE_GET(x)                    (((x) & MAC_PCU_DIRECT_CONNECT_TSF2_ENABLE_MASK) >> MAC_PCU_DIRECT_CONNECT_TSF2_ENABLE_LSB)
#define MAC_PCU_DIRECT_CONNECT_TSF2_ENABLE_SET(x)                    (((0 | (x)) << MAC_PCU_DIRECT_CONNECT_TSF2_ENABLE_LSB) & MAC_PCU_DIRECT_CONNECT_TSF2_ENABLE_MASK)
#define MAC_PCU_DIRECT_CONNECT_TSF2_ENABLE_RESET                     0
#define MAC_PCU_DIRECT_CONNECT_ADDRESS                               0x83a0
#define MAC_PCU_DIRECT_CONNECT_HW_MASK                               0xffffffff
#define MAC_PCU_DIRECT_CONNECT_SW_MASK                               0xffffffff
#define MAC_PCU_DIRECT_CONNECT_HW_WRITE_MASK                         0x00000000
#define MAC_PCU_DIRECT_CONNECT_SW_WRITE_MASK                         0xffffffff
#define MAC_PCU_DIRECT_CONNECT_RSTMASK                               0xffffffff
#define MAC_PCU_DIRECT_CONNECT_RESET                                 0x00010004

// 0x83a4 (MAC_PCU_TID_TO_AC)
#define MAC_PCU_TID_TO_AC_DATA_MSB                                   31
#define MAC_PCU_TID_TO_AC_DATA_LSB                                   0
#define MAC_PCU_TID_TO_AC_DATA_MASK                                  0xffffffff
#define MAC_PCU_TID_TO_AC_DATA_GET(x)                                (((x) & MAC_PCU_TID_TO_AC_DATA_MASK) >> MAC_PCU_TID_TO_AC_DATA_LSB)
#define MAC_PCU_TID_TO_AC_DATA_SET(x)                                (((0 | (x)) << MAC_PCU_TID_TO_AC_DATA_LSB) & MAC_PCU_TID_TO_AC_DATA_MASK)
#define MAC_PCU_TID_TO_AC_DATA_RESET                                 64020
#define MAC_PCU_TID_TO_AC_ADDRESS                                    0x83a4
#define MAC_PCU_TID_TO_AC_HW_MASK                                    0xffffffff
#define MAC_PCU_TID_TO_AC_SW_MASK                                    0xffffffff
#define MAC_PCU_TID_TO_AC_HW_WRITE_MASK                              0x00000000
#define MAC_PCU_TID_TO_AC_SW_WRITE_MASK                              0xffffffff
#define MAC_PCU_TID_TO_AC_RSTMASK                                    0xffffffff
#define MAC_PCU_TID_TO_AC_RESET                                      0x0000fa14

// 0x83a8 (MAC_PCU_HP_QUEUE)
#define MAC_PCU_HP_QUEUE_UAPSD_ONLY_QOS_MSB                          24
#define MAC_PCU_HP_QUEUE_UAPSD_ONLY_QOS_LSB                          24
#define MAC_PCU_HP_QUEUE_UAPSD_ONLY_QOS_MASK                         0x01000000
#define MAC_PCU_HP_QUEUE_UAPSD_ONLY_QOS_GET(x)                       (((x) & MAC_PCU_HP_QUEUE_UAPSD_ONLY_QOS_MASK) >> MAC_PCU_HP_QUEUE_UAPSD_ONLY_QOS_LSB)
#define MAC_PCU_HP_QUEUE_UAPSD_ONLY_QOS_SET(x)                       (((0 | (x)) << MAC_PCU_HP_QUEUE_UAPSD_ONLY_QOS_LSB) & MAC_PCU_HP_QUEUE_UAPSD_ONLY_QOS_MASK)
#define MAC_PCU_HP_QUEUE_UAPSD_ONLY_QOS_RESET                        0
#define MAC_PCU_HP_QUEUE_UAPSD_AC_MUST_MATCH_MSB                     23
#define MAC_PCU_HP_QUEUE_UAPSD_AC_MUST_MATCH_LSB                     23
#define MAC_PCU_HP_QUEUE_UAPSD_AC_MUST_MATCH_MASK                    0x00800000
#define MAC_PCU_HP_QUEUE_UAPSD_AC_MUST_MATCH_GET(x)                  (((x) & MAC_PCU_HP_QUEUE_UAPSD_AC_MUST_MATCH_MASK) >> MAC_PCU_HP_QUEUE_UAPSD_AC_MUST_MATCH_LSB)
#define MAC_PCU_HP_QUEUE_UAPSD_AC_MUST_MATCH_SET(x)                  (((0 | (x)) << MAC_PCU_HP_QUEUE_UAPSD_AC_MUST_MATCH_LSB) & MAC_PCU_HP_QUEUE_UAPSD_AC_MUST_MATCH_MASK)
#define MAC_PCU_HP_QUEUE_UAPSD_AC_MUST_MATCH_RESET                   0
#define MAC_PCU_HP_QUEUE_NON_UAPSD_EN_MSB                            22
#define MAC_PCU_HP_QUEUE_NON_UAPSD_EN_LSB                            22
#define MAC_PCU_HP_QUEUE_NON_UAPSD_EN_MASK                           0x00400000
#define MAC_PCU_HP_QUEUE_NON_UAPSD_EN_GET(x)                         (((x) & MAC_PCU_HP_QUEUE_NON_UAPSD_EN_MASK) >> MAC_PCU_HP_QUEUE_NON_UAPSD_EN_LSB)
#define MAC_PCU_HP_QUEUE_NON_UAPSD_EN_SET(x)                         (((0 | (x)) << MAC_PCU_HP_QUEUE_NON_UAPSD_EN_LSB) & MAC_PCU_HP_QUEUE_NON_UAPSD_EN_MASK)
#define MAC_PCU_HP_QUEUE_NON_UAPSD_EN_RESET                          1
#define MAC_PCU_HP_QUEUE_PM_CHANGE_MSB                               21
#define MAC_PCU_HP_QUEUE_PM_CHANGE_LSB                               21
#define MAC_PCU_HP_QUEUE_PM_CHANGE_MASK                              0x00200000
#define MAC_PCU_HP_QUEUE_PM_CHANGE_GET(x)                            (((x) & MAC_PCU_HP_QUEUE_PM_CHANGE_MASK) >> MAC_PCU_HP_QUEUE_PM_CHANGE_LSB)
#define MAC_PCU_HP_QUEUE_PM_CHANGE_SET(x)                            (((0 | (x)) << MAC_PCU_HP_QUEUE_PM_CHANGE_LSB) & MAC_PCU_HP_QUEUE_PM_CHANGE_MASK)
#define MAC_PCU_HP_QUEUE_PM_CHANGE_RESET                             1
#define MAC_PCU_HP_QUEUE_UAPSD_EN_MSB                                20
#define MAC_PCU_HP_QUEUE_UAPSD_EN_LSB                                20
#define MAC_PCU_HP_QUEUE_UAPSD_EN_MASK                               0x00100000
#define MAC_PCU_HP_QUEUE_UAPSD_EN_GET(x)                             (((x) & MAC_PCU_HP_QUEUE_UAPSD_EN_MASK) >> MAC_PCU_HP_QUEUE_UAPSD_EN_LSB)
#define MAC_PCU_HP_QUEUE_UAPSD_EN_SET(x)                             (((0 | (x)) << MAC_PCU_HP_QUEUE_UAPSD_EN_LSB) & MAC_PCU_HP_QUEUE_UAPSD_EN_MASK)
#define MAC_PCU_HP_QUEUE_UAPSD_EN_RESET                              0
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE_MASK0_MSB                     19
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE_MASK0_LSB                     16
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE_MASK0_MASK                    0x000f0000
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE_MASK0_GET(x)                  (((x) & MAC_PCU_HP_QUEUE_FRAME_SUBTYPE_MASK0_MASK) >> MAC_PCU_HP_QUEUE_FRAME_SUBTYPE_MASK0_LSB)
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE_MASK0_SET(x)                  (((0 | (x)) << MAC_PCU_HP_QUEUE_FRAME_SUBTYPE_MASK0_LSB) & MAC_PCU_HP_QUEUE_FRAME_SUBTYPE_MASK0_MASK)
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE_MASK0_RESET                   15
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE0_MSB                          15
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE0_LSB                          12
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE0_MASK                         0x0000f000
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE0_GET(x)                       (((x) & MAC_PCU_HP_QUEUE_FRAME_SUBTYPE0_MASK) >> MAC_PCU_HP_QUEUE_FRAME_SUBTYPE0_LSB)
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE0_SET(x)                       (((0 | (x)) << MAC_PCU_HP_QUEUE_FRAME_SUBTYPE0_LSB) & MAC_PCU_HP_QUEUE_FRAME_SUBTYPE0_MASK)
#define MAC_PCU_HP_QUEUE_FRAME_SUBTYPE0_RESET                        0
#define MAC_PCU_HP_QUEUE_FRAME_TYPE_MASK0_MSB                        11
#define MAC_PCU_HP_QUEUE_FRAME_TYPE_MASK0_LSB                        10
#define MAC_PCU_HP_QUEUE_FRAME_TYPE_MASK0_MASK                       0x00000c00
#define MAC_PCU_HP_QUEUE_FRAME_TYPE_MASK0_GET(x)                     (((x) & MAC_PCU_HP_QUEUE_FRAME_TYPE_MASK0_MASK) >> MAC_PCU_HP_QUEUE_FRAME_TYPE_MASK0_LSB)
#define MAC_PCU_HP_QUEUE_FRAME_TYPE_MASK0_SET(x)                     (((0 | (x)) << MAC_PCU_HP_QUEUE_FRAME_TYPE_MASK0_LSB) & MAC_PCU_HP_QUEUE_FRAME_TYPE_MASK0_MASK)
#define MAC_PCU_HP_QUEUE_FRAME_TYPE_MASK0_RESET                      3
#define MAC_PCU_HP_QUEUE_FRAME_TYPE0_MSB                             9
#define MAC_PCU_HP_QUEUE_FRAME_TYPE0_LSB                             8
#define MAC_PCU_HP_QUEUE_FRAME_TYPE0_MASK                            0x00000300
#define MAC_PCU_HP_QUEUE_FRAME_TYPE0_GET(x)                          (((x) & MAC_PCU_HP_QUEUE_FRAME_TYPE0_MASK) >> MAC_PCU_HP_QUEUE_FRAME_TYPE0_LSB)
#define MAC_PCU_HP_QUEUE_FRAME_TYPE0_SET(x)                          (((0 | (x)) << MAC_PCU_HP_QUEUE_FRAME_TYPE0_LSB) & MAC_PCU_HP_QUEUE_FRAME_TYPE0_MASK)
#define MAC_PCU_HP_QUEUE_FRAME_TYPE0_RESET                           0
#define MAC_PCU_HP_QUEUE_FRAME_BSSID_MATCH0_MSB                      7
#define MAC_PCU_HP_QUEUE_FRAME_BSSID_MATCH0_LSB                      7
#define MAC_PCU_HP_QUEUE_FRAME_BSSID_MATCH0_MASK                     0x00000080
#define MAC_PCU_HP_QUEUE_FRAME_BSSID_MATCH0_GET(x)                   (((x) & MAC_PCU_HP_QUEUE_FRAME_BSSID_MATCH0_MASK) >> MAC_PCU_HP_QUEUE_FRAME_BSSID_MATCH0_LSB)
#define MAC_PCU_HP_QUEUE_FRAME_BSSID_MATCH0_SET(x)                   (((0 | (x)) << MAC_PCU_HP_QUEUE_FRAME_BSSID_MATCH0_LSB) & MAC_PCU_HP_QUEUE_FRAME_BSSID_MATCH0_MASK)
#define MAC_PCU_HP_QUEUE_FRAME_BSSID_MATCH0_RESET                    0
#define MAC_PCU_HP_QUEUE_FRAME_FILTER_ENABLE0_MSB                    6
#define MAC_PCU_HP_QUEUE_FRAME_FILTER_ENABLE0_LSB                    6
#define MAC_PCU_HP_QUEUE_FRAME_FILTER_ENABLE0_MASK                   0x00000040
#define MAC_PCU_HP_QUEUE_FRAME_FILTER_ENABLE0_GET(x)                 (((x) & MAC_PCU_HP_QUEUE_FRAME_FILTER_ENABLE0_MASK) >> MAC_PCU_HP_QUEUE_FRAME_FILTER_ENABLE0_LSB)
#define MAC_PCU_HP_QUEUE_FRAME_FILTER_ENABLE0_SET(x)                 (((0 | (x)) << MAC_PCU_HP_QUEUE_FRAME_FILTER_ENABLE0_LSB) & MAC_PCU_HP_QUEUE_FRAME_FILTER_ENABLE0_MASK)
#define MAC_PCU_HP_QUEUE_FRAME_FILTER_ENABLE0_RESET                  0
#define MAC_PCU_HP_QUEUE_HPQON_UAPSD_MSB                             5
#define MAC_PCU_HP_QUEUE_HPQON_UAPSD_LSB                             5
#define MAC_PCU_HP_QUEUE_HPQON_UAPSD_MASK                            0x00000020
#define MAC_PCU_HP_QUEUE_HPQON_UAPSD_GET(x)                          (((x) & MAC_PCU_HP_QUEUE_HPQON_UAPSD_MASK) >> MAC_PCU_HP_QUEUE_HPQON_UAPSD_LSB)
#define MAC_PCU_HP_QUEUE_HPQON_UAPSD_SET(x)                          (((0 | (x)) << MAC_PCU_HP_QUEUE_HPQON_UAPSD_LSB) & MAC_PCU_HP_QUEUE_HPQON_UAPSD_MASK)
#define MAC_PCU_HP_QUEUE_HPQON_UAPSD_RESET                           0
#define MAC_PCU_HP_QUEUE_AC_MASK_VO_MSB                              4
#define MAC_PCU_HP_QUEUE_AC_MASK_VO_LSB                              4
#define MAC_PCU_HP_QUEUE_AC_MASK_VO_MASK                             0x00000010
#define MAC_PCU_HP_QUEUE_AC_MASK_VO_GET(x)                           (((x) & MAC_PCU_HP_QUEUE_AC_MASK_VO_MASK) >> MAC_PCU_HP_QUEUE_AC_MASK_VO_LSB)
#define MAC_PCU_HP_QUEUE_AC_MASK_VO_SET(x)                           (((0 | (x)) << MAC_PCU_HP_QUEUE_AC_MASK_VO_LSB) & MAC_PCU_HP_QUEUE_AC_MASK_VO_MASK)
#define MAC_PCU_HP_QUEUE_AC_MASK_VO_RESET                            0
#define MAC_PCU_HP_QUEUE_AC_MASK_VI_MSB                              3
#define MAC_PCU_HP_QUEUE_AC_MASK_VI_LSB                              3
#define MAC_PCU_HP_QUEUE_AC_MASK_VI_MASK                             0x00000008
#define MAC_PCU_HP_QUEUE_AC_MASK_VI_GET(x)                           (((x) & MAC_PCU_HP_QUEUE_AC_MASK_VI_MASK) >> MAC_PCU_HP_QUEUE_AC_MASK_VI_LSB)
#define MAC_PCU_HP_QUEUE_AC_MASK_VI_SET(x)                           (((0 | (x)) << MAC_PCU_HP_QUEUE_AC_MASK_VI_LSB) & MAC_PCU_HP_QUEUE_AC_MASK_VI_MASK)
#define MAC_PCU_HP_QUEUE_AC_MASK_VI_RESET                            0
#define MAC_PCU_HP_QUEUE_AC_MASK_BK_MSB                              2
#define MAC_PCU_HP_QUEUE_AC_MASK_BK_LSB                              2
#define MAC_PCU_HP_QUEUE_AC_MASK_BK_MASK                             0x00000004
#define MAC_PCU_HP_QUEUE_AC_MASK_BK_GET(x)                           (((x) & MAC_PCU_HP_QUEUE_AC_MASK_BK_MASK) >> MAC_PCU_HP_QUEUE_AC_MASK_BK_LSB)
#define MAC_PCU_HP_QUEUE_AC_MASK_BK_SET(x)                           (((0 | (x)) << MAC_PCU_HP_QUEUE_AC_MASK_BK_LSB) & MAC_PCU_HP_QUEUE_AC_MASK_BK_MASK)
#define MAC_PCU_HP_QUEUE_AC_MASK_BK_RESET                            0
#define MAC_PCU_HP_QUEUE_AC_MASK_BE_MSB                              1
#define MAC_PCU_HP_QUEUE_AC_MASK_BE_LSB                              1
#define MAC_PCU_HP_QUEUE_AC_MASK_BE_MASK                             0x00000002
#define MAC_PCU_HP_QUEUE_AC_MASK_BE_GET(x)                           (((x) & MAC_PCU_HP_QUEUE_AC_MASK_BE_MASK) >> MAC_PCU_HP_QUEUE_AC_MASK_BE_LSB)
#define MAC_PCU_HP_QUEUE_AC_MASK_BE_SET(x)                           (((0 | (x)) << MAC_PCU_HP_QUEUE_AC_MASK_BE_LSB) & MAC_PCU_HP_QUEUE_AC_MASK_BE_MASK)
#define MAC_PCU_HP_QUEUE_AC_MASK_BE_RESET                            0
#define MAC_PCU_HP_QUEUE_ENABLE_MSB                                  0
#define MAC_PCU_HP_QUEUE_ENABLE_LSB                                  0
#define MAC_PCU_HP_QUEUE_ENABLE_MASK                                 0x00000001
#define MAC_PCU_HP_QUEUE_ENABLE_GET(x)                               (((x) & MAC_PCU_HP_QUEUE_ENABLE_MASK) >> MAC_PCU_HP_QUEUE_ENABLE_LSB)
#define MAC_PCU_HP_QUEUE_ENABLE_SET(x)                               (((0 | (x)) << MAC_PCU_HP_QUEUE_ENABLE_LSB) & MAC_PCU_HP_QUEUE_ENABLE_MASK)
#define MAC_PCU_HP_QUEUE_ENABLE_RESET                                0
#define MAC_PCU_HP_QUEUE_ADDRESS                                     0x83a8
#define MAC_PCU_HP_QUEUE_HW_MASK                                     0x01ffffff
#define MAC_PCU_HP_QUEUE_SW_MASK                                     0x01ffffff
#define MAC_PCU_HP_QUEUE_HW_WRITE_MASK                               0x00000000
#define MAC_PCU_HP_QUEUE_SW_WRITE_MASK                               0x01ffffff
#define MAC_PCU_HP_QUEUE_RSTMASK                                     0xffffffff
#define MAC_PCU_HP_QUEUE_RESET                                       0x006f0c00

// 0x83bc (MAC_PCU_AGC_SATURATION_CNT0)
#define MAC_PCU_AGC_SATURATION_CNT0_VALUE_MSB                        31
#define MAC_PCU_AGC_SATURATION_CNT0_VALUE_LSB                        0
#define MAC_PCU_AGC_SATURATION_CNT0_VALUE_MASK                       0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT0_VALUE_GET(x)                     (((x) & MAC_PCU_AGC_SATURATION_CNT0_VALUE_MASK) >> MAC_PCU_AGC_SATURATION_CNT0_VALUE_LSB)
#define MAC_PCU_AGC_SATURATION_CNT0_VALUE_SET(x)                     (((0 | (x)) << MAC_PCU_AGC_SATURATION_CNT0_VALUE_LSB) & MAC_PCU_AGC_SATURATION_CNT0_VALUE_MASK)
#define MAC_PCU_AGC_SATURATION_CNT0_VALUE_RESET                      0
#define MAC_PCU_AGC_SATURATION_CNT0_ADDRESS                          0x83bc
#define MAC_PCU_AGC_SATURATION_CNT0_HW_MASK                          0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT0_SW_MASK                          0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT0_HW_WRITE_MASK                    0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT0_SW_WRITE_MASK                    0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT0_RSTMASK                          0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT0_RESET                            0x00000000

// 0x83c0 (MAC_PCU_AGC_SATURATION_CNT1)
#define MAC_PCU_AGC_SATURATION_CNT1_VALUE_MSB                        31
#define MAC_PCU_AGC_SATURATION_CNT1_VALUE_LSB                        0
#define MAC_PCU_AGC_SATURATION_CNT1_VALUE_MASK                       0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT1_VALUE_GET(x)                     (((x) & MAC_PCU_AGC_SATURATION_CNT1_VALUE_MASK) >> MAC_PCU_AGC_SATURATION_CNT1_VALUE_LSB)
#define MAC_PCU_AGC_SATURATION_CNT1_VALUE_SET(x)                     (((0 | (x)) << MAC_PCU_AGC_SATURATION_CNT1_VALUE_LSB) & MAC_PCU_AGC_SATURATION_CNT1_VALUE_MASK)
#define MAC_PCU_AGC_SATURATION_CNT1_VALUE_RESET                      0
#define MAC_PCU_AGC_SATURATION_CNT1_ADDRESS                          0x83c0
#define MAC_PCU_AGC_SATURATION_CNT1_HW_MASK                          0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT1_SW_MASK                          0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT1_HW_WRITE_MASK                    0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT1_SW_WRITE_MASK                    0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT1_RSTMASK                          0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT1_RESET                            0x00000000

// 0x83c4 (MAC_PCU_AGC_SATURATION_CNT2)
#define MAC_PCU_AGC_SATURATION_CNT2_VALUE_MSB                        31
#define MAC_PCU_AGC_SATURATION_CNT2_VALUE_LSB                        0
#define MAC_PCU_AGC_SATURATION_CNT2_VALUE_MASK                       0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT2_VALUE_GET(x)                     (((x) & MAC_PCU_AGC_SATURATION_CNT2_VALUE_MASK) >> MAC_PCU_AGC_SATURATION_CNT2_VALUE_LSB)
#define MAC_PCU_AGC_SATURATION_CNT2_VALUE_SET(x)                     (((0 | (x)) << MAC_PCU_AGC_SATURATION_CNT2_VALUE_LSB) & MAC_PCU_AGC_SATURATION_CNT2_VALUE_MASK)
#define MAC_PCU_AGC_SATURATION_CNT2_VALUE_RESET                      0
#define MAC_PCU_AGC_SATURATION_CNT2_ADDRESS                          0x83c4
#define MAC_PCU_AGC_SATURATION_CNT2_HW_MASK                          0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT2_SW_MASK                          0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT2_HW_WRITE_MASK                    0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT2_SW_WRITE_MASK                    0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT2_RSTMASK                          0xffffffff
#define MAC_PCU_AGC_SATURATION_CNT2_RESET                            0x00000000

// 0x83c8 (MAC_PCU_HW_BCN_PROC1)
#define MAC_PCU_HW_BCN_PROC1_ELM2_ID_MSB                             31
#define MAC_PCU_HW_BCN_PROC1_ELM2_ID_LSB                             24
#define MAC_PCU_HW_BCN_PROC1_ELM2_ID_MASK                            0xff000000
#define MAC_PCU_HW_BCN_PROC1_ELM2_ID_GET(x)                          (((x) & MAC_PCU_HW_BCN_PROC1_ELM2_ID_MASK) >> MAC_PCU_HW_BCN_PROC1_ELM2_ID_LSB)
#define MAC_PCU_HW_BCN_PROC1_ELM2_ID_SET(x)                          (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_ELM2_ID_LSB) & MAC_PCU_HW_BCN_PROC1_ELM2_ID_MASK)
#define MAC_PCU_HW_BCN_PROC1_ELM2_ID_RESET                           0
#define MAC_PCU_HW_BCN_PROC1_ELM1_ID_MSB                             23
#define MAC_PCU_HW_BCN_PROC1_ELM1_ID_LSB                             16
#define MAC_PCU_HW_BCN_PROC1_ELM1_ID_MASK                            0x00ff0000
#define MAC_PCU_HW_BCN_PROC1_ELM1_ID_GET(x)                          (((x) & MAC_PCU_HW_BCN_PROC1_ELM1_ID_MASK) >> MAC_PCU_HW_BCN_PROC1_ELM1_ID_LSB)
#define MAC_PCU_HW_BCN_PROC1_ELM1_ID_SET(x)                          (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_ELM1_ID_LSB) & MAC_PCU_HW_BCN_PROC1_ELM1_ID_MASK)
#define MAC_PCU_HW_BCN_PROC1_ELM1_ID_RESET                           0
#define MAC_PCU_HW_BCN_PROC1_ELM0_ID_MSB                             15
#define MAC_PCU_HW_BCN_PROC1_ELM0_ID_LSB                             8
#define MAC_PCU_HW_BCN_PROC1_ELM0_ID_MASK                            0x0000ff00
#define MAC_PCU_HW_BCN_PROC1_ELM0_ID_GET(x)                          (((x) & MAC_PCU_HW_BCN_PROC1_ELM0_ID_MASK) >> MAC_PCU_HW_BCN_PROC1_ELM0_ID_LSB)
#define MAC_PCU_HW_BCN_PROC1_ELM0_ID_SET(x)                          (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_ELM0_ID_LSB) & MAC_PCU_HW_BCN_PROC1_ELM0_ID_MASK)
#define MAC_PCU_HW_BCN_PROC1_ELM0_ID_RESET                           0
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM2_MSB                        7
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM2_LSB                        7
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM2_MASK                       0x00000080
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM2_GET(x)                     (((x) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM2_MASK) >> MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM2_LSB)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM2_SET(x)                     (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM2_LSB) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM2_MASK)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM2_RESET                      0
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM1_MSB                        6
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM1_LSB                        6
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM1_MASK                       0x00000040
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM1_GET(x)                     (((x) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM1_MASK) >> MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM1_LSB)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM1_SET(x)                     (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM1_LSB) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM1_MASK)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM1_RESET                      0
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM0_MSB                        5
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM0_LSB                        5
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM0_MASK                       0x00000020
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM0_GET(x)                     (((x) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM0_MASK) >> MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM0_LSB)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM0_SET(x)                     (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM0_LSB) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM0_MASK)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_ELM0_RESET                      0
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_TIM_ELM_MSB                     4
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_TIM_ELM_LSB                     4
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_TIM_ELM_MASK                    0x00000010
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_TIM_ELM_GET(x)                  (((x) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_TIM_ELM_MASK) >> MAC_PCU_HW_BCN_PROC1_EXCLUDE_TIM_ELM_LSB)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_TIM_ELM_SET(x)                  (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_EXCLUDE_TIM_ELM_LSB) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_TIM_ELM_MASK)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_TIM_ELM_RESET                   0
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_CAP_INFO_MSB                    3
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_CAP_INFO_LSB                    3
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_CAP_INFO_MASK                   0x00000008
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_CAP_INFO_GET(x)                 (((x) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_CAP_INFO_MASK) >> MAC_PCU_HW_BCN_PROC1_EXCLUDE_CAP_INFO_LSB)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_CAP_INFO_SET(x)                 (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_EXCLUDE_CAP_INFO_LSB) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_CAP_INFO_MASK)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_CAP_INFO_RESET                  0
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_BCN_INTVL_MSB                   2
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_BCN_INTVL_LSB                   2
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_BCN_INTVL_MASK                  0x00000004
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_BCN_INTVL_GET(x)                (((x) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_BCN_INTVL_MASK) >> MAC_PCU_HW_BCN_PROC1_EXCLUDE_BCN_INTVL_LSB)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_BCN_INTVL_SET(x)                (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_EXCLUDE_BCN_INTVL_LSB) & MAC_PCU_HW_BCN_PROC1_EXCLUDE_BCN_INTVL_MASK)
#define MAC_PCU_HW_BCN_PROC1_EXCLUDE_BCN_INTVL_RESET                 0
#define MAC_PCU_HW_BCN_PROC1_RESET_CRC_MSB                           1
#define MAC_PCU_HW_BCN_PROC1_RESET_CRC_LSB                           1
#define MAC_PCU_HW_BCN_PROC1_RESET_CRC_MASK                          0x00000002
#define MAC_PCU_HW_BCN_PROC1_RESET_CRC_GET(x)                        (((x) & MAC_PCU_HW_BCN_PROC1_RESET_CRC_MASK) >> MAC_PCU_HW_BCN_PROC1_RESET_CRC_LSB)
#define MAC_PCU_HW_BCN_PROC1_RESET_CRC_SET(x)                        (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_RESET_CRC_LSB) & MAC_PCU_HW_BCN_PROC1_RESET_CRC_MASK)
#define MAC_PCU_HW_BCN_PROC1_RESET_CRC_RESET                         0
#define MAC_PCU_HW_BCN_PROC1_CRC_ENABLE_MSB                          0
#define MAC_PCU_HW_BCN_PROC1_CRC_ENABLE_LSB                          0
#define MAC_PCU_HW_BCN_PROC1_CRC_ENABLE_MASK                         0x00000001
#define MAC_PCU_HW_BCN_PROC1_CRC_ENABLE_GET(x)                       (((x) & MAC_PCU_HW_BCN_PROC1_CRC_ENABLE_MASK) >> MAC_PCU_HW_BCN_PROC1_CRC_ENABLE_LSB)
#define MAC_PCU_HW_BCN_PROC1_CRC_ENABLE_SET(x)                       (((0 | (x)) << MAC_PCU_HW_BCN_PROC1_CRC_ENABLE_LSB) & MAC_PCU_HW_BCN_PROC1_CRC_ENABLE_MASK)
#define MAC_PCU_HW_BCN_PROC1_CRC_ENABLE_RESET                        0
#define MAC_PCU_HW_BCN_PROC1_ADDRESS                                 0x83c8
#define MAC_PCU_HW_BCN_PROC1_HW_MASK                                 0xffffffff
#define MAC_PCU_HW_BCN_PROC1_SW_MASK                                 0xffffffff
#define MAC_PCU_HW_BCN_PROC1_HW_WRITE_MASK                           0x00000002
#define MAC_PCU_HW_BCN_PROC1_SW_WRITE_MASK                           0xffffffff
#define MAC_PCU_HW_BCN_PROC1_RSTMASK                                 0xffffffff
#define MAC_PCU_HW_BCN_PROC1_RESET                                   0x00000000

// 0x83cc (MAC_PCU_HW_BCN_PROC2)
#define MAC_PCU_HW_BCN_PROC2_ELM3_ID_MSB                             23
#define MAC_PCU_HW_BCN_PROC2_ELM3_ID_LSB                             16
#define MAC_PCU_HW_BCN_PROC2_ELM3_ID_MASK                            0x00ff0000
#define MAC_PCU_HW_BCN_PROC2_ELM3_ID_GET(x)                          (((x) & MAC_PCU_HW_BCN_PROC2_ELM3_ID_MASK) >> MAC_PCU_HW_BCN_PROC2_ELM3_ID_LSB)
#define MAC_PCU_HW_BCN_PROC2_ELM3_ID_SET(x)                          (((0 | (x)) << MAC_PCU_HW_BCN_PROC2_ELM3_ID_LSB) & MAC_PCU_HW_BCN_PROC2_ELM3_ID_MASK)
#define MAC_PCU_HW_BCN_PROC2_ELM3_ID_RESET                           0
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_MSB                     15
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_LSB                     8
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_MASK                    0x0000ff00
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_GET(x)                  (((x) & MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_MASK) >> MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_LSB)
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_SET(x)                  (((0 | (x)) << MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_LSB) & MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_MASK)
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_RESET                   2
#define MAC_PCU_HW_BCN_PROC2_EXCLUDE_ELM3_MSB                        2
#define MAC_PCU_HW_BCN_PROC2_EXCLUDE_ELM3_LSB                        2
#define MAC_PCU_HW_BCN_PROC2_EXCLUDE_ELM3_MASK                       0x00000004
#define MAC_PCU_HW_BCN_PROC2_EXCLUDE_ELM3_GET(x)                     (((x) & MAC_PCU_HW_BCN_PROC2_EXCLUDE_ELM3_MASK) >> MAC_PCU_HW_BCN_PROC2_EXCLUDE_ELM3_LSB)
#define MAC_PCU_HW_BCN_PROC2_EXCLUDE_ELM3_SET(x)                     (((0 | (x)) << MAC_PCU_HW_BCN_PROC2_EXCLUDE_ELM3_LSB) & MAC_PCU_HW_BCN_PROC2_EXCLUDE_ELM3_MASK)
#define MAC_PCU_HW_BCN_PROC2_EXCLUDE_ELM3_RESET                      0
#define MAC_PCU_HW_BCN_PROC2_RESET_INTERVAL_MSB                      1
#define MAC_PCU_HW_BCN_PROC2_RESET_INTERVAL_LSB                      1
#define MAC_PCU_HW_BCN_PROC2_RESET_INTERVAL_MASK                     0x00000002
#define MAC_PCU_HW_BCN_PROC2_RESET_INTERVAL_GET(x)                   (((x) & MAC_PCU_HW_BCN_PROC2_RESET_INTERVAL_MASK) >> MAC_PCU_HW_BCN_PROC2_RESET_INTERVAL_LSB)
#define MAC_PCU_HW_BCN_PROC2_RESET_INTERVAL_SET(x)                   (((0 | (x)) << MAC_PCU_HW_BCN_PROC2_RESET_INTERVAL_LSB) & MAC_PCU_HW_BCN_PROC2_RESET_INTERVAL_MASK)
#define MAC_PCU_HW_BCN_PROC2_RESET_INTERVAL_RESET                    0
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_ENABLE_MSB              0
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_ENABLE_LSB              0
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_ENABLE_MASK             0x00000001
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_ENABLE_GET(x)           (((x) & MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_ENABLE_MASK) >> MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_ENABLE_LSB)
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_ENABLE_SET(x)           (((0 | (x)) << MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_ENABLE_LSB) & MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_ENABLE_MASK)
#define MAC_PCU_HW_BCN_PROC2_FILTER_INTERVAL_ENABLE_RESET            0
#define MAC_PCU_HW_BCN_PROC2_ADDRESS                                 0x83cc
#define MAC_PCU_HW_BCN_PROC2_HW_MASK                                 0x00ffff07
#define MAC_PCU_HW_BCN_PROC2_SW_MASK                                 0x00ffff07
#define MAC_PCU_HW_BCN_PROC2_HW_WRITE_MASK                           0x00000002
#define MAC_PCU_HW_BCN_PROC2_SW_WRITE_MASK                           0x00ffff07
#define MAC_PCU_HW_BCN_PROC2_RSTMASK                                 0xffffffff
#define MAC_PCU_HW_BCN_PROC2_RESET                                   0x00000200

// 0x83d0 (MAC_PCU_MISC_MODE3)
#define MAC_PCU_MISC_MODE3_TIME_BASED_DISCARD_EN_MSB                 31
#define MAC_PCU_MISC_MODE3_TIME_BASED_DISCARD_EN_LSB                 31
#define MAC_PCU_MISC_MODE3_TIME_BASED_DISCARD_EN_MASK                0x80000000
#define MAC_PCU_MISC_MODE3_TIME_BASED_DISCARD_EN_GET(x)              (((x) & MAC_PCU_MISC_MODE3_TIME_BASED_DISCARD_EN_MASK) >> MAC_PCU_MISC_MODE3_TIME_BASED_DISCARD_EN_LSB)
#define MAC_PCU_MISC_MODE3_TIME_BASED_DISCARD_EN_SET(x)              (((0 | (x)) << MAC_PCU_MISC_MODE3_TIME_BASED_DISCARD_EN_LSB) & MAC_PCU_MISC_MODE3_TIME_BASED_DISCARD_EN_MASK)
#define MAC_PCU_MISC_MODE3_TIME_BASED_DISCARD_EN_RESET               1
#define MAC_PCU_MISC_MODE3_PER_STA_WEP_ENTRY_ENABLE_MSB              30
#define MAC_PCU_MISC_MODE3_PER_STA_WEP_ENTRY_ENABLE_LSB              30
#define MAC_PCU_MISC_MODE3_PER_STA_WEP_ENTRY_ENABLE_MASK             0x40000000
#define MAC_PCU_MISC_MODE3_PER_STA_WEP_ENTRY_ENABLE_GET(x)           (((x) & MAC_PCU_MISC_MODE3_PER_STA_WEP_ENTRY_ENABLE_MASK) >> MAC_PCU_MISC_MODE3_PER_STA_WEP_ENTRY_ENABLE_LSB)
#define MAC_PCU_MISC_MODE3_PER_STA_WEP_ENTRY_ENABLE_SET(x)           (((0 | (x)) << MAC_PCU_MISC_MODE3_PER_STA_WEP_ENTRY_ENABLE_LSB) & MAC_PCU_MISC_MODE3_PER_STA_WEP_ENTRY_ENABLE_MASK)
#define MAC_PCU_MISC_MODE3_PER_STA_WEP_ENTRY_ENABLE_RESET            1
#define MAC_PCU_MISC_MODE3_KEY_MISS_FIX_MSB                          29
#define MAC_PCU_MISC_MODE3_KEY_MISS_FIX_LSB                          29
#define MAC_PCU_MISC_MODE3_KEY_MISS_FIX_MASK                         0x20000000
#define MAC_PCU_MISC_MODE3_KEY_MISS_FIX_GET(x)                       (((x) & MAC_PCU_MISC_MODE3_KEY_MISS_FIX_MASK) >> MAC_PCU_MISC_MODE3_KEY_MISS_FIX_LSB)
#define MAC_PCU_MISC_MODE3_KEY_MISS_FIX_SET(x)                       (((0 | (x)) << MAC_PCU_MISC_MODE3_KEY_MISS_FIX_LSB) & MAC_PCU_MISC_MODE3_KEY_MISS_FIX_MASK)
#define MAC_PCU_MISC_MODE3_KEY_MISS_FIX_RESET                        1
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_MGT_MSB                     28
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_MGT_LSB                     28
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_MGT_MASK                    0x10000000
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_MGT_GET(x)                  (((x) & MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_MGT_MASK) >> MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_MGT_LSB)
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_MGT_SET(x)                  (((0 | (x)) << MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_MGT_LSB) & MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_MGT_MASK)
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_MGT_RESET                   0
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_DAT_MSB                     27
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_DAT_LSB                     27
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_DAT_MASK                    0x08000000
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_DAT_GET(x)                  (((x) & MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_DAT_MASK) >> MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_DAT_LSB)
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_DAT_SET(x)                  (((0 | (x)) << MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_DAT_LSB) & MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_DAT_MASK)
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_DAT_RESET                   0
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_CTL_MSB                     26
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_CTL_LSB                     26
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_CTL_MASK                    0x04000000
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_CTL_GET(x)                  (((x) & MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_CTL_MASK) >> MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_CTL_LSB)
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_CTL_SET(x)                  (((0 | (x)) << MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_CTL_LSB) & MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_CTL_MASK)
#define MAC_PCU_MISC_MODE3_PM_FIELD2_FOR_CTL_RESET                   0
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_MGMT_MSB                     25
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_MGMT_LSB                     25
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_MGMT_MASK                    0x02000000
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_MGMT_GET(x)                  (((x) & MAC_PCU_MISC_MODE3_PM_FIELD_FOR_MGMT_MASK) >> MAC_PCU_MISC_MODE3_PM_FIELD_FOR_MGMT_LSB)
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_MGMT_SET(x)                  (((0 | (x)) << MAC_PCU_MISC_MODE3_PM_FIELD_FOR_MGMT_LSB) & MAC_PCU_MISC_MODE3_PM_FIELD_FOR_MGMT_MASK)
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_MGMT_RESET                   0
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_DAT_MSB                      24
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_DAT_LSB                      24
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_DAT_MASK                     0x01000000
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_DAT_GET(x)                   (((x) & MAC_PCU_MISC_MODE3_PM_FIELD_FOR_DAT_MASK) >> MAC_PCU_MISC_MODE3_PM_FIELD_FOR_DAT_LSB)
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_DAT_SET(x)                   (((0 | (x)) << MAC_PCU_MISC_MODE3_PM_FIELD_FOR_DAT_LSB) & MAC_PCU_MISC_MODE3_PM_FIELD_FOR_DAT_MASK)
#define MAC_PCU_MISC_MODE3_PM_FIELD_FOR_DAT_RESET                    0
#define MAC_PCU_MISC_MODE3_BEACON_FROM_TO_DS_CHECK_MSB               23
#define MAC_PCU_MISC_MODE3_BEACON_FROM_TO_DS_CHECK_LSB               23
#define MAC_PCU_MISC_MODE3_BEACON_FROM_TO_DS_CHECK_MASK              0x00800000
#define MAC_PCU_MISC_MODE3_BEACON_FROM_TO_DS_CHECK_GET(x)            (((x) & MAC_PCU_MISC_MODE3_BEACON_FROM_TO_DS_CHECK_MASK) >> MAC_PCU_MISC_MODE3_BEACON_FROM_TO_DS_CHECK_LSB)
#define MAC_PCU_MISC_MODE3_BEACON_FROM_TO_DS_CHECK_SET(x)            (((0 | (x)) << MAC_PCU_MISC_MODE3_BEACON_FROM_TO_DS_CHECK_LSB) & MAC_PCU_MISC_MODE3_BEACON_FROM_TO_DS_CHECK_MASK)
#define MAC_PCU_MISC_MODE3_BEACON_FROM_TO_DS_CHECK_RESET             1
#define MAC_PCU_MISC_MODE3_IGNORE_TXOP_IF_ZER0_MSB                   22
#define MAC_PCU_MISC_MODE3_IGNORE_TXOP_IF_ZER0_LSB                   22
#define MAC_PCU_MISC_MODE3_IGNORE_TXOP_IF_ZER0_MASK                  0x00400000
#define MAC_PCU_MISC_MODE3_IGNORE_TXOP_IF_ZER0_GET(x)                (((x) & MAC_PCU_MISC_MODE3_IGNORE_TXOP_IF_ZER0_MASK) >> MAC_PCU_MISC_MODE3_IGNORE_TXOP_IF_ZER0_LSB)
#define MAC_PCU_MISC_MODE3_IGNORE_TXOP_IF_ZER0_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE3_IGNORE_TXOP_IF_ZER0_LSB) & MAC_PCU_MISC_MODE3_IGNORE_TXOP_IF_ZER0_MASK)
#define MAC_PCU_MISC_MODE3_IGNORE_TXOP_IF_ZER0_RESET                 0
#define MAC_PCU_MISC_MODE3_ALLOW_RAC_MSB                             21
#define MAC_PCU_MISC_MODE3_ALLOW_RAC_LSB                             21
#define MAC_PCU_MISC_MODE3_ALLOW_RAC_MASK                            0x00200000
#define MAC_PCU_MISC_MODE3_ALLOW_RAC_GET(x)                          (((x) & MAC_PCU_MISC_MODE3_ALLOW_RAC_MASK) >> MAC_PCU_MISC_MODE3_ALLOW_RAC_LSB)
#define MAC_PCU_MISC_MODE3_ALLOW_RAC_SET(x)                          (((0 | (x)) << MAC_PCU_MISC_MODE3_ALLOW_RAC_LSB) & MAC_PCU_MISC_MODE3_ALLOW_RAC_MASK)
#define MAC_PCU_MISC_MODE3_ALLOW_RAC_RESET                           0
#define MAC_PCU_MISC_MODE3_SMOOTHING_FORCE_MSB                       20
#define MAC_PCU_MISC_MODE3_SMOOTHING_FORCE_LSB                       20
#define MAC_PCU_MISC_MODE3_SMOOTHING_FORCE_MASK                      0x00100000
#define MAC_PCU_MISC_MODE3_SMOOTHING_FORCE_GET(x)                    (((x) & MAC_PCU_MISC_MODE3_SMOOTHING_FORCE_MASK) >> MAC_PCU_MISC_MODE3_SMOOTHING_FORCE_LSB)
#define MAC_PCU_MISC_MODE3_SMOOTHING_FORCE_SET(x)                    (((0 | (x)) << MAC_PCU_MISC_MODE3_SMOOTHING_FORCE_LSB) & MAC_PCU_MISC_MODE3_SMOOTHING_FORCE_MASK)
#define MAC_PCU_MISC_MODE3_SMOOTHING_FORCE_RESET                     1
#define MAC_PCU_MISC_MODE3_SELF_GEN_SMOOTHING_MSB                    19
#define MAC_PCU_MISC_MODE3_SELF_GEN_SMOOTHING_LSB                    19
#define MAC_PCU_MISC_MODE3_SELF_GEN_SMOOTHING_MASK                   0x00080000
#define MAC_PCU_MISC_MODE3_SELF_GEN_SMOOTHING_GET(x)                 (((x) & MAC_PCU_MISC_MODE3_SELF_GEN_SMOOTHING_MASK) >> MAC_PCU_MISC_MODE3_SELF_GEN_SMOOTHING_LSB)
#define MAC_PCU_MISC_MODE3_SELF_GEN_SMOOTHING_SET(x)                 (((0 | (x)) << MAC_PCU_MISC_MODE3_SELF_GEN_SMOOTHING_LSB) & MAC_PCU_MISC_MODE3_SELF_GEN_SMOOTHING_MASK)
#define MAC_PCU_MISC_MODE3_SELF_GEN_SMOOTHING_RESET                  1
#define MAC_PCU_MISC_MODE3_BB_LDPC_EN_MSB                            18
#define MAC_PCU_MISC_MODE3_BB_LDPC_EN_LSB                            18
#define MAC_PCU_MISC_MODE3_BB_LDPC_EN_MASK                           0x00040000
#define MAC_PCU_MISC_MODE3_BB_LDPC_EN_GET(x)                         (((x) & MAC_PCU_MISC_MODE3_BB_LDPC_EN_MASK) >> MAC_PCU_MISC_MODE3_BB_LDPC_EN_LSB)
#define MAC_PCU_MISC_MODE3_BB_LDPC_EN_SET(x)                         (((0 | (x)) << MAC_PCU_MISC_MODE3_BB_LDPC_EN_LSB) & MAC_PCU_MISC_MODE3_BB_LDPC_EN_MASK)
#define MAC_PCU_MISC_MODE3_BB_LDPC_EN_RESET                          0
#define MAC_PCU_MISC_MODE3_WAPI_ORDER_MASK_MSB                       17
#define MAC_PCU_MISC_MODE3_WAPI_ORDER_MASK_LSB                       17
#define MAC_PCU_MISC_MODE3_WAPI_ORDER_MASK_MASK                      0x00020000
#define MAC_PCU_MISC_MODE3_WAPI_ORDER_MASK_GET(x)                    (((x) & MAC_PCU_MISC_MODE3_WAPI_ORDER_MASK_MASK) >> MAC_PCU_MISC_MODE3_WAPI_ORDER_MASK_LSB)
#define MAC_PCU_MISC_MODE3_WAPI_ORDER_MASK_SET(x)                    (((0 | (x)) << MAC_PCU_MISC_MODE3_WAPI_ORDER_MASK_LSB) & MAC_PCU_MISC_MODE3_WAPI_ORDER_MASK_MASK)
#define MAC_PCU_MISC_MODE3_WAPI_ORDER_MASK_RESET                     0
#define MAC_PCU_MISC_MODE3_MATCH_TID_FOR_BA_MSB                      16
#define MAC_PCU_MISC_MODE3_MATCH_TID_FOR_BA_LSB                      16
#define MAC_PCU_MISC_MODE3_MATCH_TID_FOR_BA_MASK                     0x00010000
#define MAC_PCU_MISC_MODE3_MATCH_TID_FOR_BA_GET(x)                   (((x) & MAC_PCU_MISC_MODE3_MATCH_TID_FOR_BA_MASK) >> MAC_PCU_MISC_MODE3_MATCH_TID_FOR_BA_LSB)
#define MAC_PCU_MISC_MODE3_MATCH_TID_FOR_BA_SET(x)                   (((0 | (x)) << MAC_PCU_MISC_MODE3_MATCH_TID_FOR_BA_LSB) & MAC_PCU_MISC_MODE3_MATCH_TID_FOR_BA_MASK)
#define MAC_PCU_MISC_MODE3_MATCH_TID_FOR_BA_RESET                    0
#define MAC_PCU_MISC_MODE3_BA_FRAME_LENGTH_MSB                       15
#define MAC_PCU_MISC_MODE3_BA_FRAME_LENGTH_LSB                       8
#define MAC_PCU_MISC_MODE3_BA_FRAME_LENGTH_MASK                      0x0000ff00
#define MAC_PCU_MISC_MODE3_BA_FRAME_LENGTH_GET(x)                    (((x) & MAC_PCU_MISC_MODE3_BA_FRAME_LENGTH_MASK) >> MAC_PCU_MISC_MODE3_BA_FRAME_LENGTH_LSB)
#define MAC_PCU_MISC_MODE3_BA_FRAME_LENGTH_SET(x)                    (((0 | (x)) << MAC_PCU_MISC_MODE3_BA_FRAME_LENGTH_LSB) & MAC_PCU_MISC_MODE3_BA_FRAME_LENGTH_MASK)
#define MAC_PCU_MISC_MODE3_BA_FRAME_LENGTH_RESET                     32
#define MAC_PCU_MISC_MODE3_CHECK_LENGTH_FOR_BA_MSB                   7
#define MAC_PCU_MISC_MODE3_CHECK_LENGTH_FOR_BA_LSB                   7
#define MAC_PCU_MISC_MODE3_CHECK_LENGTH_FOR_BA_MASK                  0x00000080
#define MAC_PCU_MISC_MODE3_CHECK_LENGTH_FOR_BA_GET(x)                (((x) & MAC_PCU_MISC_MODE3_CHECK_LENGTH_FOR_BA_MASK) >> MAC_PCU_MISC_MODE3_CHECK_LENGTH_FOR_BA_LSB)
#define MAC_PCU_MISC_MODE3_CHECK_LENGTH_FOR_BA_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE3_CHECK_LENGTH_FOR_BA_LSB) & MAC_PCU_MISC_MODE3_CHECK_LENGTH_FOR_BA_MASK)
#define MAC_PCU_MISC_MODE3_CHECK_LENGTH_FOR_BA_RESET                 0
#define MAC_PCU_MISC_MODE3_BUG_61936_FIX_ENABLE_MSB                  6
#define MAC_PCU_MISC_MODE3_BUG_61936_FIX_ENABLE_LSB                  6
#define MAC_PCU_MISC_MODE3_BUG_61936_FIX_ENABLE_MASK                 0x00000040
#define MAC_PCU_MISC_MODE3_BUG_61936_FIX_ENABLE_GET(x)               (((x) & MAC_PCU_MISC_MODE3_BUG_61936_FIX_ENABLE_MASK) >> MAC_PCU_MISC_MODE3_BUG_61936_FIX_ENABLE_LSB)
#define MAC_PCU_MISC_MODE3_BUG_61936_FIX_ENABLE_SET(x)               (((0 | (x)) << MAC_PCU_MISC_MODE3_BUG_61936_FIX_ENABLE_LSB) & MAC_PCU_MISC_MODE3_BUG_61936_FIX_ENABLE_MASK)
#define MAC_PCU_MISC_MODE3_BUG_61936_FIX_ENABLE_RESET                0
#define MAC_PCU_MISC_MODE3_WOW_ADDR1_MASK_ENABLE_MSB                 5
#define MAC_PCU_MISC_MODE3_WOW_ADDR1_MASK_ENABLE_LSB                 5
#define MAC_PCU_MISC_MODE3_WOW_ADDR1_MASK_ENABLE_MASK                0x00000020
#define MAC_PCU_MISC_MODE3_WOW_ADDR1_MASK_ENABLE_GET(x)              (((x) & MAC_PCU_MISC_MODE3_WOW_ADDR1_MASK_ENABLE_MASK) >> MAC_PCU_MISC_MODE3_WOW_ADDR1_MASK_ENABLE_LSB)
#define MAC_PCU_MISC_MODE3_WOW_ADDR1_MASK_ENABLE_SET(x)              (((0 | (x)) << MAC_PCU_MISC_MODE3_WOW_ADDR1_MASK_ENABLE_LSB) & MAC_PCU_MISC_MODE3_WOW_ADDR1_MASK_ENABLE_MASK)
#define MAC_PCU_MISC_MODE3_WOW_ADDR1_MASK_ENABLE_RESET               1
#define MAC_PCU_MISC_MODE3_BUG_56991_FIX_ENABLE_MSB                  4
#define MAC_PCU_MISC_MODE3_BUG_56991_FIX_ENABLE_LSB                  4
#define MAC_PCU_MISC_MODE3_BUG_56991_FIX_ENABLE_MASK                 0x00000010
#define MAC_PCU_MISC_MODE3_BUG_56991_FIX_ENABLE_GET(x)               (((x) & MAC_PCU_MISC_MODE3_BUG_56991_FIX_ENABLE_MASK) >> MAC_PCU_MISC_MODE3_BUG_56991_FIX_ENABLE_LSB)
#define MAC_PCU_MISC_MODE3_BUG_56991_FIX_ENABLE_SET(x)               (((0 | (x)) << MAC_PCU_MISC_MODE3_BUG_56991_FIX_ENABLE_LSB) & MAC_PCU_MISC_MODE3_BUG_56991_FIX_ENABLE_MASK)
#define MAC_PCU_MISC_MODE3_BUG_56991_FIX_ENABLE_RESET                1
#define MAC_PCU_MISC_MODE3_BUG_58011_FIX_ENABLE_MSB                  3
#define MAC_PCU_MISC_MODE3_BUG_58011_FIX_ENABLE_LSB                  3
#define MAC_PCU_MISC_MODE3_BUG_58011_FIX_ENABLE_MASK                 0x00000008
#define MAC_PCU_MISC_MODE3_BUG_58011_FIX_ENABLE_GET(x)               (((x) & MAC_PCU_MISC_MODE3_BUG_58011_FIX_ENABLE_MASK) >> MAC_PCU_MISC_MODE3_BUG_58011_FIX_ENABLE_LSB)
#define MAC_PCU_MISC_MODE3_BUG_58011_FIX_ENABLE_SET(x)               (((0 | (x)) << MAC_PCU_MISC_MODE3_BUG_58011_FIX_ENABLE_LSB) & MAC_PCU_MISC_MODE3_BUG_58011_FIX_ENABLE_MASK)
#define MAC_PCU_MISC_MODE3_BUG_58011_FIX_ENABLE_RESET                1
#define MAC_PCU_MISC_MODE3_REGULAR_SOUNDING_MSB                      2
#define MAC_PCU_MISC_MODE3_REGULAR_SOUNDING_LSB                      2
#define MAC_PCU_MISC_MODE3_REGULAR_SOUNDING_MASK                     0x00000004
#define MAC_PCU_MISC_MODE3_REGULAR_SOUNDING_GET(x)                   (((x) & MAC_PCU_MISC_MODE3_REGULAR_SOUNDING_MASK) >> MAC_PCU_MISC_MODE3_REGULAR_SOUNDING_LSB)
#define MAC_PCU_MISC_MODE3_REGULAR_SOUNDING_SET(x)                   (((0 | (x)) << MAC_PCU_MISC_MODE3_REGULAR_SOUNDING_LSB) & MAC_PCU_MISC_MODE3_REGULAR_SOUNDING_MASK)
#define MAC_PCU_MISC_MODE3_REGULAR_SOUNDING_RESET                    0
#define MAC_PCU_MISC_MODE3_AES_3STREAM_MSB                           1
#define MAC_PCU_MISC_MODE3_AES_3STREAM_LSB                           1
#define MAC_PCU_MISC_MODE3_AES_3STREAM_MASK                          0x00000002
#define MAC_PCU_MISC_MODE3_AES_3STREAM_GET(x)                        (((x) & MAC_PCU_MISC_MODE3_AES_3STREAM_MASK) >> MAC_PCU_MISC_MODE3_AES_3STREAM_LSB)
#define MAC_PCU_MISC_MODE3_AES_3STREAM_SET(x)                        (((0 | (x)) << MAC_PCU_MISC_MODE3_AES_3STREAM_LSB) & MAC_PCU_MISC_MODE3_AES_3STREAM_MASK)
#define MAC_PCU_MISC_MODE3_AES_3STREAM_RESET                         1
#define MAC_PCU_MISC_MODE3_BUG_55702_FIX_ENABLE_MSB                  0
#define MAC_PCU_MISC_MODE3_BUG_55702_FIX_ENABLE_LSB                  0
#define MAC_PCU_MISC_MODE3_BUG_55702_FIX_ENABLE_MASK                 0x00000001
#define MAC_PCU_MISC_MODE3_BUG_55702_FIX_ENABLE_GET(x)               (((x) & MAC_PCU_MISC_MODE3_BUG_55702_FIX_ENABLE_MASK) >> MAC_PCU_MISC_MODE3_BUG_55702_FIX_ENABLE_LSB)
#define MAC_PCU_MISC_MODE3_BUG_55702_FIX_ENABLE_SET(x)               (((0 | (x)) << MAC_PCU_MISC_MODE3_BUG_55702_FIX_ENABLE_LSB) & MAC_PCU_MISC_MODE3_BUG_55702_FIX_ENABLE_MASK)
#define MAC_PCU_MISC_MODE3_BUG_55702_FIX_ENABLE_RESET                1
#define MAC_PCU_MISC_MODE3_ADDRESS                                   0x83d0
#define MAC_PCU_MISC_MODE3_HW_MASK                                   0xffffffff
#define MAC_PCU_MISC_MODE3_SW_MASK                                   0xffffffff
#define MAC_PCU_MISC_MODE3_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_MISC_MODE3_SW_WRITE_MASK                             0xffffffff
#define MAC_PCU_MISC_MODE3_RSTMASK                                   0xffffffff
#define MAC_PCU_MISC_MODE3_RESET                                     0xe098203b

// 0x83d4 (MAC_PCU_MISC_MODE4)
#define MAC_PCU_MISC_MODE4_IGNORE_RXSM_INIT_STATE_MSB                17
#define MAC_PCU_MISC_MODE4_IGNORE_RXSM_INIT_STATE_LSB                17
#define MAC_PCU_MISC_MODE4_IGNORE_RXSM_INIT_STATE_MASK               0x00020000
#define MAC_PCU_MISC_MODE4_IGNORE_RXSM_INIT_STATE_GET(x)             (((x) & MAC_PCU_MISC_MODE4_IGNORE_RXSM_INIT_STATE_MASK) >> MAC_PCU_MISC_MODE4_IGNORE_RXSM_INIT_STATE_LSB)
#define MAC_PCU_MISC_MODE4_IGNORE_RXSM_INIT_STATE_SET(x)             (((0 | (x)) << MAC_PCU_MISC_MODE4_IGNORE_RXSM_INIT_STATE_LSB) & MAC_PCU_MISC_MODE4_IGNORE_RXSM_INIT_STATE_MASK)
#define MAC_PCU_MISC_MODE4_IGNORE_RXSM_INIT_STATE_RESET              1
#define MAC_PCU_MISC_MODE4_SMART_ANT_SEL_MSB                         16
#define MAC_PCU_MISC_MODE4_SMART_ANT_SEL_LSB                         16
#define MAC_PCU_MISC_MODE4_SMART_ANT_SEL_MASK                        0x00010000
#define MAC_PCU_MISC_MODE4_SMART_ANT_SEL_GET(x)                      (((x) & MAC_PCU_MISC_MODE4_SMART_ANT_SEL_MASK) >> MAC_PCU_MISC_MODE4_SMART_ANT_SEL_LSB)
#define MAC_PCU_MISC_MODE4_SMART_ANT_SEL_SET(x)                      (((0 | (x)) << MAC_PCU_MISC_MODE4_SMART_ANT_SEL_LSB) & MAC_PCU_MISC_MODE4_SMART_ANT_SEL_MASK)
#define MAC_PCU_MISC_MODE4_SMART_ANT_SEL_RESET                       0
#define MAC_PCU_MISC_MODE4_TX_CONFIG_PHY_ERR_ENABLE_MSB              15
#define MAC_PCU_MISC_MODE4_TX_CONFIG_PHY_ERR_ENABLE_LSB              15
#define MAC_PCU_MISC_MODE4_TX_CONFIG_PHY_ERR_ENABLE_MASK             0x00008000
#define MAC_PCU_MISC_MODE4_TX_CONFIG_PHY_ERR_ENABLE_GET(x)           (((x) & MAC_PCU_MISC_MODE4_TX_CONFIG_PHY_ERR_ENABLE_MASK) >> MAC_PCU_MISC_MODE4_TX_CONFIG_PHY_ERR_ENABLE_LSB)
#define MAC_PCU_MISC_MODE4_TX_CONFIG_PHY_ERR_ENABLE_SET(x)           (((0 | (x)) << MAC_PCU_MISC_MODE4_TX_CONFIG_PHY_ERR_ENABLE_LSB) & MAC_PCU_MISC_MODE4_TX_CONFIG_PHY_ERR_ENABLE_MASK)
#define MAC_PCU_MISC_MODE4_TX_CONFIG_PHY_ERR_ENABLE_RESET            1
#define MAC_PCU_MISC_MODE4_CTS2SELF_AD1_FIX_ENABLE_MSB               14
#define MAC_PCU_MISC_MODE4_CTS2SELF_AD1_FIX_ENABLE_LSB               14
#define MAC_PCU_MISC_MODE4_CTS2SELF_AD1_FIX_ENABLE_MASK              0x00004000
#define MAC_PCU_MISC_MODE4_CTS2SELF_AD1_FIX_ENABLE_GET(x)            (((x) & MAC_PCU_MISC_MODE4_CTS2SELF_AD1_FIX_ENABLE_MASK) >> MAC_PCU_MISC_MODE4_CTS2SELF_AD1_FIX_ENABLE_LSB)
#define MAC_PCU_MISC_MODE4_CTS2SELF_AD1_FIX_ENABLE_SET(x)            (((0 | (x)) << MAC_PCU_MISC_MODE4_CTS2SELF_AD1_FIX_ENABLE_LSB) & MAC_PCU_MISC_MODE4_CTS2SELF_AD1_FIX_ENABLE_MASK)
#define MAC_PCU_MISC_MODE4_CTS2SELF_AD1_FIX_ENABLE_RESET             1
#define MAC_PCU_MISC_MODE4_ZEROLEN_CRYPTO_ENABLE_MSB                 13
#define MAC_PCU_MISC_MODE4_ZEROLEN_CRYPTO_ENABLE_LSB                 13
#define MAC_PCU_MISC_MODE4_ZEROLEN_CRYPTO_ENABLE_MASK                0x00002000
#define MAC_PCU_MISC_MODE4_ZEROLEN_CRYPTO_ENABLE_GET(x)              (((x) & MAC_PCU_MISC_MODE4_ZEROLEN_CRYPTO_ENABLE_MASK) >> MAC_PCU_MISC_MODE4_ZEROLEN_CRYPTO_ENABLE_LSB)
#define MAC_PCU_MISC_MODE4_ZEROLEN_CRYPTO_ENABLE_SET(x)              (((0 | (x)) << MAC_PCU_MISC_MODE4_ZEROLEN_CRYPTO_ENABLE_LSB) & MAC_PCU_MISC_MODE4_ZEROLEN_CRYPTO_ENABLE_MASK)
#define MAC_PCU_MISC_MODE4_ZEROLEN_CRYPTO_ENABLE_RESET               0
#define MAC_PCU_MISC_MODE4_HT_DYNAMIC_CBW_MSB                        12
#define MAC_PCU_MISC_MODE4_HT_DYNAMIC_CBW_LSB                        12
#define MAC_PCU_MISC_MODE4_HT_DYNAMIC_CBW_MASK                       0x00001000
#define MAC_PCU_MISC_MODE4_HT_DYNAMIC_CBW_GET(x)                     (((x) & MAC_PCU_MISC_MODE4_HT_DYNAMIC_CBW_MASK) >> MAC_PCU_MISC_MODE4_HT_DYNAMIC_CBW_LSB)
#define MAC_PCU_MISC_MODE4_HT_DYNAMIC_CBW_SET(x)                     (((0 | (x)) << MAC_PCU_MISC_MODE4_HT_DYNAMIC_CBW_LSB) & MAC_PCU_MISC_MODE4_HT_DYNAMIC_CBW_MASK)
#define MAC_PCU_MISC_MODE4_HT_DYNAMIC_CBW_RESET                      0
#define MAC_PCU_MISC_MODE4_ENABLE_SF_MSB                             11
#define MAC_PCU_MISC_MODE4_ENABLE_SF_LSB                             11
#define MAC_PCU_MISC_MODE4_ENABLE_SF_MASK                            0x00000800
#define MAC_PCU_MISC_MODE4_ENABLE_SF_GET(x)                          (((x) & MAC_PCU_MISC_MODE4_ENABLE_SF_MASK) >> MAC_PCU_MISC_MODE4_ENABLE_SF_LSB)
#define MAC_PCU_MISC_MODE4_ENABLE_SF_SET(x)                          (((0 | (x)) << MAC_PCU_MISC_MODE4_ENABLE_SF_LSB) & MAC_PCU_MISC_MODE4_ENABLE_SF_MASK)
#define MAC_PCU_MISC_MODE4_ENABLE_SF_RESET                           0
#define MAC_PCU_MISC_MODE4_PEER_ENTRY_SWAP_MSB                       10
#define MAC_PCU_MISC_MODE4_PEER_ENTRY_SWAP_LSB                       10
#define MAC_PCU_MISC_MODE4_PEER_ENTRY_SWAP_MASK                      0x00000400
#define MAC_PCU_MISC_MODE4_PEER_ENTRY_SWAP_GET(x)                    (((x) & MAC_PCU_MISC_MODE4_PEER_ENTRY_SWAP_MASK) >> MAC_PCU_MISC_MODE4_PEER_ENTRY_SWAP_LSB)
#define MAC_PCU_MISC_MODE4_PEER_ENTRY_SWAP_SET(x)                    (((0 | (x)) << MAC_PCU_MISC_MODE4_PEER_ENTRY_SWAP_LSB) & MAC_PCU_MISC_MODE4_PEER_ENTRY_SWAP_MASK)
#define MAC_PCU_MISC_MODE4_PEER_ENTRY_SWAP_RESET                     0
#define MAC_PCU_MISC_MODE4_VHT_SERVICE_DYNAMIC_MSB                   9
#define MAC_PCU_MISC_MODE4_VHT_SERVICE_DYNAMIC_LSB                   9
#define MAC_PCU_MISC_MODE4_VHT_SERVICE_DYNAMIC_MASK                  0x00000200
#define MAC_PCU_MISC_MODE4_VHT_SERVICE_DYNAMIC_GET(x)                (((x) & MAC_PCU_MISC_MODE4_VHT_SERVICE_DYNAMIC_MASK) >> MAC_PCU_MISC_MODE4_VHT_SERVICE_DYNAMIC_LSB)
#define MAC_PCU_MISC_MODE4_VHT_SERVICE_DYNAMIC_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE4_VHT_SERVICE_DYNAMIC_LSB) & MAC_PCU_MISC_MODE4_VHT_SERVICE_DYNAMIC_MASK)
#define MAC_PCU_MISC_MODE4_VHT_SERVICE_DYNAMIC_RESET                 1
#define MAC_PCU_MISC_MODE4_EV_83864_FIX_ENABLE_MSB                   8
#define MAC_PCU_MISC_MODE4_EV_83864_FIX_ENABLE_LSB                   8
#define MAC_PCU_MISC_MODE4_EV_83864_FIX_ENABLE_MASK                  0x00000100
#define MAC_PCU_MISC_MODE4_EV_83864_FIX_ENABLE_GET(x)                (((x) & MAC_PCU_MISC_MODE4_EV_83864_FIX_ENABLE_MASK) >> MAC_PCU_MISC_MODE4_EV_83864_FIX_ENABLE_LSB)
#define MAC_PCU_MISC_MODE4_EV_83864_FIX_ENABLE_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE4_EV_83864_FIX_ENABLE_LSB) & MAC_PCU_MISC_MODE4_EV_83864_FIX_ENABLE_MASK)
#define MAC_PCU_MISC_MODE4_EV_83864_FIX_ENABLE_RESET                 0
#define MAC_PCU_MISC_MODE4_EV_78561_FIX_ENABLE_MSB                   7
#define MAC_PCU_MISC_MODE4_EV_78561_FIX_ENABLE_LSB                   7
#define MAC_PCU_MISC_MODE4_EV_78561_FIX_ENABLE_MASK                  0x00000080
#define MAC_PCU_MISC_MODE4_EV_78561_FIX_ENABLE_GET(x)                (((x) & MAC_PCU_MISC_MODE4_EV_78561_FIX_ENABLE_MASK) >> MAC_PCU_MISC_MODE4_EV_78561_FIX_ENABLE_LSB)
#define MAC_PCU_MISC_MODE4_EV_78561_FIX_ENABLE_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE4_EV_78561_FIX_ENABLE_LSB) & MAC_PCU_MISC_MODE4_EV_78561_FIX_ENABLE_MASK)
#define MAC_PCU_MISC_MODE4_EV_78561_FIX_ENABLE_RESET                 0
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_PROBE_RESP_MSB          6
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_PROBE_RESP_LSB          6
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_PROBE_RESP_MASK         0x00000040
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_PROBE_RESP_GET(x)       (((x) & MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_PROBE_RESP_MASK) >> MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_PROBE_RESP_LSB)
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_PROBE_RESP_SET(x)       (((0 | (x)) << MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_PROBE_RESP_LSB) & MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_PROBE_RESP_MASK)
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_PROBE_RESP_RESET        1
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_MOON_PROBE_RESP_MSB     5
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_MOON_PROBE_RESP_LSB     5
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_MOON_PROBE_RESP_MASK    0x00000020
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_MOON_PROBE_RESP_GET(x)  (((x) & MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_MOON_PROBE_RESP_MASK) >> MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_MOON_PROBE_RESP_LSB)
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_MOON_PROBE_RESP_SET(x)  (((0 | (x)) << MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_MOON_PROBE_RESP_LSB) & MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_MOON_PROBE_RESP_MASK)
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_UCAST_MOON_PROBE_RESP_RESET   1
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_MCAST_PROBE_RESP_MSB          4
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_MCAST_PROBE_RESP_LSB          4
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_MCAST_PROBE_RESP_MASK         0x00000010
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_MCAST_PROBE_RESP_GET(x)       (((x) & MAC_PCU_MISC_MODE4_SYNC_TSF_ON_MCAST_PROBE_RESP_MASK) >> MAC_PCU_MISC_MODE4_SYNC_TSF_ON_MCAST_PROBE_RESP_LSB)
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_MCAST_PROBE_RESP_SET(x)       (((0 | (x)) << MAC_PCU_MISC_MODE4_SYNC_TSF_ON_MCAST_PROBE_RESP_LSB) & MAC_PCU_MISC_MODE4_SYNC_TSF_ON_MCAST_PROBE_RESP_MASK)
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_MCAST_PROBE_RESP_RESET        1
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BCAST_PROBE_RESP_MSB          3
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BCAST_PROBE_RESP_LSB          3
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BCAST_PROBE_RESP_MASK         0x00000008
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BCAST_PROBE_RESP_GET(x)       (((x) & MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BCAST_PROBE_RESP_MASK) >> MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BCAST_PROBE_RESP_LSB)
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BCAST_PROBE_RESP_SET(x)       (((0 | (x)) << MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BCAST_PROBE_RESP_LSB) & MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BCAST_PROBE_RESP_MASK)
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BCAST_PROBE_RESP_RESET        1
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BEACON_MSB                    2
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BEACON_LSB                    2
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BEACON_MASK                   0x00000004
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BEACON_GET(x)                 (((x) & MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BEACON_MASK) >> MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BEACON_LSB)
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BEACON_SET(x)                 (((0 | (x)) << MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BEACON_LSB) & MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BEACON_MASK)
#define MAC_PCU_MISC_MODE4_SYNC_TSF_ON_BEACON_RESET                  1
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_MSB                      1
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_LSB                      1
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_MASK                     0x00000002
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_GET(x)                   (((x) & MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_MASK) >> MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_LSB)
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_SET(x)                   (((0 | (x)) << MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_LSB) & MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_MASK)
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_RESET                    0
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_EN_MSB                   0
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_EN_LSB                   0
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_EN_MASK                  0x00000001
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_EN_GET(x)                (((x) & MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_EN_MASK) >> MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_EN_LSB)
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_EN_SET(x)                (((0 | (x)) << MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_EN_LSB) & MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_EN_MASK)
#define MAC_PCU_MISC_MODE4_BC_MC_WAPI_MODE2_EN_RESET                 0
#define MAC_PCU_MISC_MODE4_ADDRESS                                   0x83d4
#define MAC_PCU_MISC_MODE4_HW_MASK                                   0x0003ffff
#define MAC_PCU_MISC_MODE4_SW_MASK                                   0x0003ffff
#define MAC_PCU_MISC_MODE4_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_MISC_MODE4_SW_WRITE_MASK                             0x0003ffff
#define MAC_PCU_MISC_MODE4_RSTMASK                                   0xffffffff
#define MAC_PCU_MISC_MODE4_RESET                                     0x0002c27c

// 0x83dc (MAC_PCU_PS_FILTER)
#define MAC_PCU_PS_FILTER_PS_SAVE_ENABLE_MSB                         1
#define MAC_PCU_PS_FILTER_PS_SAVE_ENABLE_LSB                         1
#define MAC_PCU_PS_FILTER_PS_SAVE_ENABLE_MASK                        0x00000002
#define MAC_PCU_PS_FILTER_PS_SAVE_ENABLE_GET(x)                      (((x) & MAC_PCU_PS_FILTER_PS_SAVE_ENABLE_MASK) >> MAC_PCU_PS_FILTER_PS_SAVE_ENABLE_LSB)
#define MAC_PCU_PS_FILTER_PS_SAVE_ENABLE_SET(x)                      (((0 | (x)) << MAC_PCU_PS_FILTER_PS_SAVE_ENABLE_LSB) & MAC_PCU_PS_FILTER_PS_SAVE_ENABLE_MASK)
#define MAC_PCU_PS_FILTER_PS_SAVE_ENABLE_RESET                       1
#define MAC_PCU_PS_FILTER_ENABLE_MSB                                 0
#define MAC_PCU_PS_FILTER_ENABLE_LSB                                 0
#define MAC_PCU_PS_FILTER_ENABLE_MASK                                0x00000001
#define MAC_PCU_PS_FILTER_ENABLE_GET(x)                              (((x) & MAC_PCU_PS_FILTER_ENABLE_MASK) >> MAC_PCU_PS_FILTER_ENABLE_LSB)
#define MAC_PCU_PS_FILTER_ENABLE_SET(x)                              (((0 | (x)) << MAC_PCU_PS_FILTER_ENABLE_LSB) & MAC_PCU_PS_FILTER_ENABLE_MASK)
#define MAC_PCU_PS_FILTER_ENABLE_RESET                               0
#define MAC_PCU_PS_FILTER_ADDRESS                                    0x83dc
#define MAC_PCU_PS_FILTER_HW_MASK                                    0x00000003
#define MAC_PCU_PS_FILTER_SW_MASK                                    0x00000003
#define MAC_PCU_PS_FILTER_HW_WRITE_MASK                              0x00000000
#define MAC_PCU_PS_FILTER_SW_WRITE_MASK                              0x00000003
#define MAC_PCU_PS_FILTER_RSTMASK                                    0xffffffff
#define MAC_PCU_PS_FILTER_RESET                                      0x00000002

// 0x83e0 (MAC_PCU_BASIC_RATE_SET0)
#define MAC_PCU_BASIC_RATE_SET0_VALUE_MSB                            29
#define MAC_PCU_BASIC_RATE_SET0_VALUE_LSB                            0
#define MAC_PCU_BASIC_RATE_SET0_VALUE_MASK                           0x3fffffff
#define MAC_PCU_BASIC_RATE_SET0_VALUE_GET(x)                         (((x) & MAC_PCU_BASIC_RATE_SET0_VALUE_MASK) >> MAC_PCU_BASIC_RATE_SET0_VALUE_LSB)
#define MAC_PCU_BASIC_RATE_SET0_VALUE_SET(x)                         (((0 | (x)) << MAC_PCU_BASIC_RATE_SET0_VALUE_LSB) & MAC_PCU_BASIC_RATE_SET0_VALUE_MASK)
#define MAC_PCU_BASIC_RATE_SET0_VALUE_RESET                          836565851
#define MAC_PCU_BASIC_RATE_SET0_ADDRESS                              0x83e0
#define MAC_PCU_BASIC_RATE_SET0_HW_MASK                              0x3fffffff
#define MAC_PCU_BASIC_RATE_SET0_SW_MASK                              0x3fffffff
#define MAC_PCU_BASIC_RATE_SET0_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_BASIC_RATE_SET0_SW_WRITE_MASK                        0x3fffffff
#define MAC_PCU_BASIC_RATE_SET0_RSTMASK                              0xffffffff
#define MAC_PCU_BASIC_RATE_SET0_RESET                                0x31dcfb5b

// 0x83e4 (MAC_PCU_BASIC_RATE_SET1)
#define MAC_PCU_BASIC_RATE_SET1_VALUE_MSB                            29
#define MAC_PCU_BASIC_RATE_SET1_VALUE_LSB                            0
#define MAC_PCU_BASIC_RATE_SET1_VALUE_MASK                           0x3fffffff
#define MAC_PCU_BASIC_RATE_SET1_VALUE_GET(x)                         (((x) & MAC_PCU_BASIC_RATE_SET1_VALUE_MASK) >> MAC_PCU_BASIC_RATE_SET1_VALUE_LSB)
#define MAC_PCU_BASIC_RATE_SET1_VALUE_SET(x)                         (((0 | (x)) << MAC_PCU_BASIC_RATE_SET1_VALUE_LSB) & MAC_PCU_BASIC_RATE_SET1_VALUE_MASK)
#define MAC_PCU_BASIC_RATE_SET1_VALUE_RESET                          312814972
#define MAC_PCU_BASIC_RATE_SET1_ADDRESS                              0x83e4
#define MAC_PCU_BASIC_RATE_SET1_HW_MASK                              0x3fffffff
#define MAC_PCU_BASIC_RATE_SET1_SW_MASK                              0x3fffffff
#define MAC_PCU_BASIC_RATE_SET1_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_BASIC_RATE_SET1_SW_WRITE_MASK                        0x3fffffff
#define MAC_PCU_BASIC_RATE_SET1_RSTMASK                              0xffffffff
#define MAC_PCU_BASIC_RATE_SET1_RESET                                0x12a52d7c

// 0x83e8 (MAC_PCU_BASIC_RATE_SET2)
#define MAC_PCU_BASIC_RATE_SET2_VALUE_MSB                            29
#define MAC_PCU_BASIC_RATE_SET2_VALUE_LSB                            0
#define MAC_PCU_BASIC_RATE_SET2_VALUE_MASK                           0x3fffffff
#define MAC_PCU_BASIC_RATE_SET2_VALUE_GET(x)                         (((x) & MAC_PCU_BASIC_RATE_SET2_VALUE_MASK) >> MAC_PCU_BASIC_RATE_SET2_VALUE_LSB)
#define MAC_PCU_BASIC_RATE_SET2_VALUE_SET(x)                         (((0 | (x)) << MAC_PCU_BASIC_RATE_SET2_VALUE_LSB) & MAC_PCU_BASIC_RATE_SET2_VALUE_MASK)
#define MAC_PCU_BASIC_RATE_SET2_VALUE_RESET                          346400041
#define MAC_PCU_BASIC_RATE_SET2_ADDRESS                              0x83e8
#define MAC_PCU_BASIC_RATE_SET2_HW_MASK                              0x3fffffff
#define MAC_PCU_BASIC_RATE_SET2_SW_MASK                              0x3fffffff
#define MAC_PCU_BASIC_RATE_SET2_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_BASIC_RATE_SET2_SW_WRITE_MASK                        0x3fffffff
#define MAC_PCU_BASIC_RATE_SET2_RSTMASK                              0xffffffff
#define MAC_PCU_BASIC_RATE_SET2_RESET                                0x14a5a529

// 0x83ec (MAC_PCU_BASIC_RATE_SET3)
#define MAC_PCU_BASIC_RATE_SET3_VALUE_MSB                            24
#define MAC_PCU_BASIC_RATE_SET3_VALUE_LSB                            0
#define MAC_PCU_BASIC_RATE_SET3_VALUE_MASK                           0x01ffffff
#define MAC_PCU_BASIC_RATE_SET3_VALUE_GET(x)                         (((x) & MAC_PCU_BASIC_RATE_SET3_VALUE_MASK) >> MAC_PCU_BASIC_RATE_SET3_VALUE_LSB)
#define MAC_PCU_BASIC_RATE_SET3_VALUE_SET(x)                         (((0 | (x)) << MAC_PCU_BASIC_RATE_SET3_VALUE_LSB) & MAC_PCU_BASIC_RATE_SET3_VALUE_MASK)
#define MAC_PCU_BASIC_RATE_SET3_VALUE_RESET                          9741609
#define MAC_PCU_BASIC_RATE_SET3_ADDRESS                              0x83ec
#define MAC_PCU_BASIC_RATE_SET3_HW_MASK                              0x01ffffff
#define MAC_PCU_BASIC_RATE_SET3_SW_MASK                              0x01ffffff
#define MAC_PCU_BASIC_RATE_SET3_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_BASIC_RATE_SET3_SW_WRITE_MASK                        0x01ffffff
#define MAC_PCU_BASIC_RATE_SET3_RSTMASK                              0xffffffff
#define MAC_PCU_BASIC_RATE_SET3_RESET                                0x0094a529

// 0x83f0 (MAC_PCU_BASIC_RATE_SET4)
#define MAC_PCU_BASIC_RATE_SET4_VALUE_MSB                            9
#define MAC_PCU_BASIC_RATE_SET4_VALUE_LSB                            0
#define MAC_PCU_BASIC_RATE_SET4_VALUE_MASK                           0x000003ff
#define MAC_PCU_BASIC_RATE_SET4_VALUE_GET(x)                         (((x) & MAC_PCU_BASIC_RATE_SET4_VALUE_MASK) >> MAC_PCU_BASIC_RATE_SET4_VALUE_LSB)
#define MAC_PCU_BASIC_RATE_SET4_VALUE_SET(x)                         (((0 | (x)) << MAC_PCU_BASIC_RATE_SET4_VALUE_LSB) & MAC_PCU_BASIC_RATE_SET4_VALUE_MASK)
#define MAC_PCU_BASIC_RATE_SET4_VALUE_RESET                          297
#define MAC_PCU_BASIC_RATE_SET4_ADDRESS                              0x83f0
#define MAC_PCU_BASIC_RATE_SET4_HW_MASK                              0x000003ff
#define MAC_PCU_BASIC_RATE_SET4_SW_MASK                              0x000003ff
#define MAC_PCU_BASIC_RATE_SET4_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_BASIC_RATE_SET4_SW_WRITE_MASK                        0x000003ff
#define MAC_PCU_BASIC_RATE_SET4_RSTMASK                              0xffffffff
#define MAC_PCU_BASIC_RATE_SET4_RESET                                0x00000129

// 0x8400 (MAC_PCU_TXBUF_BA_0)
#define MAC_PCU_TXBUF_BA_0_DATA_MSB                                  31
#define MAC_PCU_TXBUF_BA_0_DATA_LSB                                  0
#define MAC_PCU_TXBUF_BA_0_DATA_MASK                                 0xffffffff
#define MAC_PCU_TXBUF_BA_0_DATA_GET(x)                               (((x) & MAC_PCU_TXBUF_BA_0_DATA_MASK) >> MAC_PCU_TXBUF_BA_0_DATA_LSB)
#define MAC_PCU_TXBUF_BA_0_DATA_SET(x)                               (((0 | (x)) << MAC_PCU_TXBUF_BA_0_DATA_LSB) & MAC_PCU_TXBUF_BA_0_DATA_MASK)
#define MAC_PCU_TXBUF_BA_0_DATA_RESET                                0
#define MAC_PCU_TXBUF_BA_0_ADDRESS                                   0x8400
#define MAC_PCU_TXBUF_BA_ADDRESS                                     MAC_PCU_TXBUF_BA_0_ADDRESS
#define MAC_PCU_TXBUF_BA_0_HW_MASK                                   0xffffffff
#define MAC_PCU_TXBUF_BA_0_SW_MASK                                   0xffffffff
#define MAC_PCU_TXBUF_BA_0_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_TXBUF_BA_0_SW_WRITE_MASK                             0xffffffff
#define MAC_PCU_TXBUF_BA_0_RSTMASK                                   0x00000000
#define MAC_PCU_TXBUF_BA_0_RESET                                     0x00000000

// Skip 8404 (MAC_PCU_TXBUF_BA_1) - 84fc (MAC_PCU_TXBUF_BA_63) for brevity
// 0x8500 (MAC_PCU_BT_BT_0)
#define MAC_PCU_BT_BT_0_WEIGHT_MSB                                   31
#define MAC_PCU_BT_BT_0_WEIGHT_LSB                                   0
#define MAC_PCU_BT_BT_0_WEIGHT_MASK                                  0xffffffff
#define MAC_PCU_BT_BT_0_WEIGHT_GET(x)                                (((x) & MAC_PCU_BT_BT_0_WEIGHT_MASK) >> MAC_PCU_BT_BT_0_WEIGHT_LSB)
#define MAC_PCU_BT_BT_0_WEIGHT_SET(x)                                (((0 | (x)) << MAC_PCU_BT_BT_0_WEIGHT_LSB) & MAC_PCU_BT_BT_0_WEIGHT_MASK)
#define MAC_PCU_BT_BT_0_WEIGHT_RESET                                 0
#define MAC_PCU_BT_BT_0_ADDRESS                                      0x8500
#define MAC_PCU_BT_BT_ADDRESS                                        MAC_PCU_BT_BT_0_ADDRESS
#define MAC_PCU_BT_BT_0_HW_MASK                                      0xffffffff
#define MAC_PCU_BT_BT_0_SW_MASK                                      0xffffffff
#define MAC_PCU_BT_BT_0_HW_WRITE_MASK                                0x00000000
#define MAC_PCU_BT_BT_0_SW_WRITE_MASK                                0xffffffff
#define MAC_PCU_BT_BT_0_RSTMASK                                      0x00000000
#define MAC_PCU_BT_BT_0_RESET                                        0x00000000

// Skip 8504 (MAC_PCU_BT_BT_1) - 85fc (MAC_PCU_BT_BT_63) for brevity
// 0x8600 (MAC_PCU_RX_INT_STATUS0)
#define MAC_PCU_RX_INT_STATUS0_DURATION_H_MSB                        31
#define MAC_PCU_RX_INT_STATUS0_DURATION_H_LSB                        24
#define MAC_PCU_RX_INT_STATUS0_DURATION_H_MASK                       0xff000000
#define MAC_PCU_RX_INT_STATUS0_DURATION_H_GET(x)                     (((x) & MAC_PCU_RX_INT_STATUS0_DURATION_H_MASK) >> MAC_PCU_RX_INT_STATUS0_DURATION_H_LSB)
#define MAC_PCU_RX_INT_STATUS0_DURATION_H_SET(x)                     (((0 | (x)) << MAC_PCU_RX_INT_STATUS0_DURATION_H_LSB) & MAC_PCU_RX_INT_STATUS0_DURATION_H_MASK)
#define MAC_PCU_RX_INT_STATUS0_DURATION_H_RESET                      0
#define MAC_PCU_RX_INT_STATUS0_DURATION_L_MSB                        23
#define MAC_PCU_RX_INT_STATUS0_DURATION_L_LSB                        16
#define MAC_PCU_RX_INT_STATUS0_DURATION_L_MASK                       0x00ff0000
#define MAC_PCU_RX_INT_STATUS0_DURATION_L_GET(x)                     (((x) & MAC_PCU_RX_INT_STATUS0_DURATION_L_MASK) >> MAC_PCU_RX_INT_STATUS0_DURATION_L_LSB)
#define MAC_PCU_RX_INT_STATUS0_DURATION_L_SET(x)                     (((0 | (x)) << MAC_PCU_RX_INT_STATUS0_DURATION_L_LSB) & MAC_PCU_RX_INT_STATUS0_DURATION_L_MASK)
#define MAC_PCU_RX_INT_STATUS0_DURATION_L_RESET                      0
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_H_MSB                   15
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_H_LSB                   8
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_H_MASK                  0x0000ff00
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_H_GET(x)                (((x) & MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_H_MASK) >> MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_H_LSB)
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_H_SET(x)                (((0 | (x)) << MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_H_LSB) & MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_H_MASK)
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_H_RESET                 0
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_L_MSB                   7
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_L_LSB                   0
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_L_MASK                  0x000000ff
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_L_GET(x)                (((x) & MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_L_MASK) >> MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_L_LSB)
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_L_SET(x)                (((0 | (x)) << MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_L_LSB) & MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_L_MASK)
#define MAC_PCU_RX_INT_STATUS0_FRAME_CONTROL_L_RESET                 0
#define MAC_PCU_RX_INT_STATUS0_ADDRESS                               0x8600
#define MAC_PCU_RX_INT_STATUS0_HW_MASK                               0xffffffff
#define MAC_PCU_RX_INT_STATUS0_SW_MASK                               0xffffffff
#define MAC_PCU_RX_INT_STATUS0_HW_WRITE_MASK                         0xffffffff
#define MAC_PCU_RX_INT_STATUS0_SW_WRITE_MASK                         0x00000000
#define MAC_PCU_RX_INT_STATUS0_RSTMASK                               0xffffffff
#define MAC_PCU_RX_INT_STATUS0_RESET                                 0x00000000

// 0x8604 (MAC_PCU_RX_INT_STATUS1)
#define MAC_PCU_RX_INT_STATUS1_VALUE_MSB                             17
#define MAC_PCU_RX_INT_STATUS1_VALUE_LSB                             0
#define MAC_PCU_RX_INT_STATUS1_VALUE_MASK                            0x0003ffff
#define MAC_PCU_RX_INT_STATUS1_VALUE_GET(x)                          (((x) & MAC_PCU_RX_INT_STATUS1_VALUE_MASK) >> MAC_PCU_RX_INT_STATUS1_VALUE_LSB)
#define MAC_PCU_RX_INT_STATUS1_VALUE_SET(x)                          (((0 | (x)) << MAC_PCU_RX_INT_STATUS1_VALUE_LSB) & MAC_PCU_RX_INT_STATUS1_VALUE_MASK)
#define MAC_PCU_RX_INT_STATUS1_VALUE_RESET                           0
#define MAC_PCU_RX_INT_STATUS1_ADDRESS                               0x8604
#define MAC_PCU_RX_INT_STATUS1_HW_MASK                               0x0003ffff
#define MAC_PCU_RX_INT_STATUS1_SW_MASK                               0x0003ffff
#define MAC_PCU_RX_INT_STATUS1_HW_WRITE_MASK                         0x0003ffff
#define MAC_PCU_RX_INT_STATUS1_SW_WRITE_MASK                         0x00000000
#define MAC_PCU_RX_INT_STATUS1_RSTMASK                               0xffffffff
#define MAC_PCU_RX_INT_STATUS1_RESET                                 0x00000000

// 0x8608 (MAC_PCU_RX_INT_STATUS2)
#define MAC_PCU_RX_INT_STATUS2_VALUE_MSB                             26
#define MAC_PCU_RX_INT_STATUS2_VALUE_LSB                             0
#define MAC_PCU_RX_INT_STATUS2_VALUE_MASK                            0x07ffffff
#define MAC_PCU_RX_INT_STATUS2_VALUE_GET(x)                          (((x) & MAC_PCU_RX_INT_STATUS2_VALUE_MASK) >> MAC_PCU_RX_INT_STATUS2_VALUE_LSB)
#define MAC_PCU_RX_INT_STATUS2_VALUE_SET(x)                          (((0 | (x)) << MAC_PCU_RX_INT_STATUS2_VALUE_LSB) & MAC_PCU_RX_INT_STATUS2_VALUE_MASK)
#define MAC_PCU_RX_INT_STATUS2_VALUE_RESET                           0
#define MAC_PCU_RX_INT_STATUS2_ADDRESS                               0x8608
#define MAC_PCU_RX_INT_STATUS2_HW_MASK                               0x07ffffff
#define MAC_PCU_RX_INT_STATUS2_SW_MASK                               0x07ffffff
#define MAC_PCU_RX_INT_STATUS2_HW_WRITE_MASK                         0x07ffffff
#define MAC_PCU_RX_INT_STATUS2_SW_WRITE_MASK                         0x00000000
#define MAC_PCU_RX_INT_STATUS2_RSTMASK                               0xffffffff
#define MAC_PCU_RX_INT_STATUS2_RESET                                 0x00000000

// 0x860c (MAC_PCU_RX_INT_STATUS3)
#define MAC_PCU_RX_INT_STATUS3_VALUE_MSB                             23
#define MAC_PCU_RX_INT_STATUS3_VALUE_LSB                             0
#define MAC_PCU_RX_INT_STATUS3_VALUE_MASK                            0x00ffffff
#define MAC_PCU_RX_INT_STATUS3_VALUE_GET(x)                          (((x) & MAC_PCU_RX_INT_STATUS3_VALUE_MASK) >> MAC_PCU_RX_INT_STATUS3_VALUE_LSB)
#define MAC_PCU_RX_INT_STATUS3_VALUE_SET(x)                          (((0 | (x)) << MAC_PCU_RX_INT_STATUS3_VALUE_LSB) & MAC_PCU_RX_INT_STATUS3_VALUE_MASK)
#define MAC_PCU_RX_INT_STATUS3_VALUE_RESET                           0
#define MAC_PCU_RX_INT_STATUS3_ADDRESS                               0x860c
#define MAC_PCU_RX_INT_STATUS3_HW_MASK                               0x00ffffff
#define MAC_PCU_RX_INT_STATUS3_SW_MASK                               0x00ffffff
#define MAC_PCU_RX_INT_STATUS3_HW_WRITE_MASK                         0x00ffffff
#define MAC_PCU_RX_INT_STATUS3_SW_WRITE_MASK                         0x00000000
#define MAC_PCU_RX_INT_STATUS3_RSTMASK                               0xffffffff
#define MAC_PCU_RX_INT_STATUS3_RESET                                 0x00000000

// 0x8610 (HT_HALF_GI_RATE1)
#define HT_HALF_GI_RATE1_MCS3_MSB                                    31
#define HT_HALF_GI_RATE1_MCS3_LSB                                    24
#define HT_HALF_GI_RATE1_MCS3_MASK                                   0xff000000
#define HT_HALF_GI_RATE1_MCS3_GET(x)                                 (((x) & HT_HALF_GI_RATE1_MCS3_MASK) >> HT_HALF_GI_RATE1_MCS3_LSB)
#define HT_HALF_GI_RATE1_MCS3_SET(x)                                 (((0 | (x)) << HT_HALF_GI_RATE1_MCS3_LSB) & HT_HALF_GI_RATE1_MCS3_MASK)
#define HT_HALF_GI_RATE1_MCS3_RESET                                  29
#define HT_HALF_GI_RATE1_MCS2_MSB                                    23
#define HT_HALF_GI_RATE1_MCS2_LSB                                    16
#define HT_HALF_GI_RATE1_MCS2_MASK                                   0x00ff0000
#define HT_HALF_GI_RATE1_MCS2_GET(x)                                 (((x) & HT_HALF_GI_RATE1_MCS2_MASK) >> HT_HALF_GI_RATE1_MCS2_LSB)
#define HT_HALF_GI_RATE1_MCS2_SET(x)                                 (((0 | (x)) << HT_HALF_GI_RATE1_MCS2_LSB) & HT_HALF_GI_RATE1_MCS2_MASK)
#define HT_HALF_GI_RATE1_MCS2_RESET                                  22
#define HT_HALF_GI_RATE1_MCS1_MSB                                    15
#define HT_HALF_GI_RATE1_MCS1_LSB                                    8
#define HT_HALF_GI_RATE1_MCS1_MASK                                   0x0000ff00
#define HT_HALF_GI_RATE1_MCS1_GET(x)                                 (((x) & HT_HALF_GI_RATE1_MCS1_MASK) >> HT_HALF_GI_RATE1_MCS1_LSB)
#define HT_HALF_GI_RATE1_MCS1_SET(x)                                 (((0 | (x)) << HT_HALF_GI_RATE1_MCS1_LSB) & HT_HALF_GI_RATE1_MCS1_MASK)
#define HT_HALF_GI_RATE1_MCS1_RESET                                  14
#define HT_HALF_GI_RATE1_MCS0_MSB                                    7
#define HT_HALF_GI_RATE1_MCS0_LSB                                    0
#define HT_HALF_GI_RATE1_MCS0_MASK                                   0x000000ff
#define HT_HALF_GI_RATE1_MCS0_GET(x)                                 (((x) & HT_HALF_GI_RATE1_MCS0_MASK) >> HT_HALF_GI_RATE1_MCS0_LSB)
#define HT_HALF_GI_RATE1_MCS0_SET(x)                                 (((0 | (x)) << HT_HALF_GI_RATE1_MCS0_LSB) & HT_HALF_GI_RATE1_MCS0_MASK)
#define HT_HALF_GI_RATE1_MCS0_RESET                                  7
#define HT_HALF_GI_RATE1_ADDRESS                                     0x8610
#define HT_HALF_GI_RATE1_HW_MASK                                     0xffffffff
#define HT_HALF_GI_RATE1_SW_MASK                                     0xffffffff
#define HT_HALF_GI_RATE1_HW_WRITE_MASK                               0x00000000
#define HT_HALF_GI_RATE1_SW_WRITE_MASK                               0xffffffff
#define HT_HALF_GI_RATE1_RSTMASK                                     0xffffffff
#define HT_HALF_GI_RATE1_RESET                                       0x1d160e07

// 0x8614 (HT_HALF_GI_RATE2)
#define HT_HALF_GI_RATE2_MCS7_MSB                                    31
#define HT_HALF_GI_RATE2_MCS7_LSB                                    24
#define HT_HALF_GI_RATE2_MCS7_MASK                                   0xff000000
#define HT_HALF_GI_RATE2_MCS7_GET(x)                                 (((x) & HT_HALF_GI_RATE2_MCS7_MASK) >> HT_HALF_GI_RATE2_MCS7_LSB)
#define HT_HALF_GI_RATE2_MCS7_SET(x)                                 (((0 | (x)) << HT_HALF_GI_RATE2_MCS7_LSB) & HT_HALF_GI_RATE2_MCS7_MASK)
#define HT_HALF_GI_RATE2_MCS7_RESET                                  72
#define HT_HALF_GI_RATE2_MCS6_MSB                                    23
#define HT_HALF_GI_RATE2_MCS6_LSB                                    16
#define HT_HALF_GI_RATE2_MCS6_MASK                                   0x00ff0000
#define HT_HALF_GI_RATE2_MCS6_GET(x)                                 (((x) & HT_HALF_GI_RATE2_MCS6_MASK) >> HT_HALF_GI_RATE2_MCS6_LSB)
#define HT_HALF_GI_RATE2_MCS6_SET(x)                                 (((0 | (x)) << HT_HALF_GI_RATE2_MCS6_LSB) & HT_HALF_GI_RATE2_MCS6_MASK)
#define HT_HALF_GI_RATE2_MCS6_RESET                                  65
#define HT_HALF_GI_RATE2_MCS5_MSB                                    15
#define HT_HALF_GI_RATE2_MCS5_LSB                                    8
#define HT_HALF_GI_RATE2_MCS5_MASK                                   0x0000ff00
#define HT_HALF_GI_RATE2_MCS5_GET(x)                                 (((x) & HT_HALF_GI_RATE2_MCS5_MASK) >> HT_HALF_GI_RATE2_MCS5_LSB)
#define HT_HALF_GI_RATE2_MCS5_SET(x)                                 (((0 | (x)) << HT_HALF_GI_RATE2_MCS5_LSB) & HT_HALF_GI_RATE2_MCS5_MASK)
#define HT_HALF_GI_RATE2_MCS5_RESET                                  58
#define HT_HALF_GI_RATE2_MCS4_MSB                                    7
#define HT_HALF_GI_RATE2_MCS4_LSB                                    0
#define HT_HALF_GI_RATE2_MCS4_MASK                                   0x000000ff
#define HT_HALF_GI_RATE2_MCS4_GET(x)                                 (((x) & HT_HALF_GI_RATE2_MCS4_MASK) >> HT_HALF_GI_RATE2_MCS4_LSB)
#define HT_HALF_GI_RATE2_MCS4_SET(x)                                 (((0 | (x)) << HT_HALF_GI_RATE2_MCS4_LSB) & HT_HALF_GI_RATE2_MCS4_MASK)
#define HT_HALF_GI_RATE2_MCS4_RESET                                  43
#define HT_HALF_GI_RATE2_ADDRESS                                     0x8614
#define HT_HALF_GI_RATE2_HW_MASK                                     0xffffffff
#define HT_HALF_GI_RATE2_SW_MASK                                     0xffffffff
#define HT_HALF_GI_RATE2_HW_WRITE_MASK                               0x00000000
#define HT_HALF_GI_RATE2_SW_WRITE_MASK                               0xffffffff
#define HT_HALF_GI_RATE2_RSTMASK                                     0xffffffff
#define HT_HALF_GI_RATE2_RESET                                       0x48413a2b

// 0x8618 (HT_FULL_GI_RATE1)
#define HT_FULL_GI_RATE1_MCS3_MSB                                    31
#define HT_FULL_GI_RATE1_MCS3_LSB                                    24
#define HT_FULL_GI_RATE1_MCS3_MASK                                   0xff000000
#define HT_FULL_GI_RATE1_MCS3_GET(x)                                 (((x) & HT_FULL_GI_RATE1_MCS3_MASK) >> HT_FULL_GI_RATE1_MCS3_LSB)
#define HT_FULL_GI_RATE1_MCS3_SET(x)                                 (((0 | (x)) << HT_FULL_GI_RATE1_MCS3_LSB) & HT_FULL_GI_RATE1_MCS3_MASK)
#define HT_FULL_GI_RATE1_MCS3_RESET                                  26
#define HT_FULL_GI_RATE1_MCS2_MSB                                    23
#define HT_FULL_GI_RATE1_MCS2_LSB                                    16
#define HT_FULL_GI_RATE1_MCS2_MASK                                   0x00ff0000
#define HT_FULL_GI_RATE1_MCS2_GET(x)                                 (((x) & HT_FULL_GI_RATE1_MCS2_MASK) >> HT_FULL_GI_RATE1_MCS2_LSB)
#define HT_FULL_GI_RATE1_MCS2_SET(x)                                 (((0 | (x)) << HT_FULL_GI_RATE1_MCS2_LSB) & HT_FULL_GI_RATE1_MCS2_MASK)
#define HT_FULL_GI_RATE1_MCS2_RESET                                  20
#define HT_FULL_GI_RATE1_MCS1_MSB                                    15
#define HT_FULL_GI_RATE1_MCS1_LSB                                    8
#define HT_FULL_GI_RATE1_MCS1_MASK                                   0x0000ff00
#define HT_FULL_GI_RATE1_MCS1_GET(x)                                 (((x) & HT_FULL_GI_RATE1_MCS1_MASK) >> HT_FULL_GI_RATE1_MCS1_LSB)
#define HT_FULL_GI_RATE1_MCS1_SET(x)                                 (((0 | (x)) << HT_FULL_GI_RATE1_MCS1_LSB) & HT_FULL_GI_RATE1_MCS1_MASK)
#define HT_FULL_GI_RATE1_MCS1_RESET                                  13
#define HT_FULL_GI_RATE1_MCS0_MSB                                    7
#define HT_FULL_GI_RATE1_MCS0_LSB                                    0
#define HT_FULL_GI_RATE1_MCS0_MASK                                   0x000000ff
#define HT_FULL_GI_RATE1_MCS0_GET(x)                                 (((x) & HT_FULL_GI_RATE1_MCS0_MASK) >> HT_FULL_GI_RATE1_MCS0_LSB)
#define HT_FULL_GI_RATE1_MCS0_SET(x)                                 (((0 | (x)) << HT_FULL_GI_RATE1_MCS0_LSB) & HT_FULL_GI_RATE1_MCS0_MASK)
#define HT_FULL_GI_RATE1_MCS0_RESET                                  7
#define HT_FULL_GI_RATE1_ADDRESS                                     0x8618
#define HT_FULL_GI_RATE1_HW_MASK                                     0xffffffff
#define HT_FULL_GI_RATE1_SW_MASK                                     0xffffffff
#define HT_FULL_GI_RATE1_HW_WRITE_MASK                               0x00000000
#define HT_FULL_GI_RATE1_SW_WRITE_MASK                               0xffffffff
#define HT_FULL_GI_RATE1_RSTMASK                                     0xffffffff
#define HT_FULL_GI_RATE1_RESET                                       0x1a140d07

// 0x861c (HT_FULL_GI_RATE2)
#define HT_FULL_GI_RATE2_MCS7_MSB                                    31
#define HT_FULL_GI_RATE2_MCS7_LSB                                    24
#define HT_FULL_GI_RATE2_MCS7_MASK                                   0xff000000
#define HT_FULL_GI_RATE2_MCS7_GET(x)                                 (((x) & HT_FULL_GI_RATE2_MCS7_MASK) >> HT_FULL_GI_RATE2_MCS7_LSB)
#define HT_FULL_GI_RATE2_MCS7_SET(x)                                 (((0 | (x)) << HT_FULL_GI_RATE2_MCS7_LSB) & HT_FULL_GI_RATE2_MCS7_MASK)
#define HT_FULL_GI_RATE2_MCS7_RESET                                  65
#define HT_FULL_GI_RATE2_MCS6_MSB                                    23
#define HT_FULL_GI_RATE2_MCS6_LSB                                    16
#define HT_FULL_GI_RATE2_MCS6_MASK                                   0x00ff0000
#define HT_FULL_GI_RATE2_MCS6_GET(x)                                 (((x) & HT_FULL_GI_RATE2_MCS6_MASK) >> HT_FULL_GI_RATE2_MCS6_LSB)
#define HT_FULL_GI_RATE2_MCS6_SET(x)                                 (((0 | (x)) << HT_FULL_GI_RATE2_MCS6_LSB) & HT_FULL_GI_RATE2_MCS6_MASK)
#define HT_FULL_GI_RATE2_MCS6_RESET                                  59
#define HT_FULL_GI_RATE2_MCS5_MSB                                    15
#define HT_FULL_GI_RATE2_MCS5_LSB                                    8
#define HT_FULL_GI_RATE2_MCS5_MASK                                   0x0000ff00
#define HT_FULL_GI_RATE2_MCS5_GET(x)                                 (((x) & HT_FULL_GI_RATE2_MCS5_MASK) >> HT_FULL_GI_RATE2_MCS5_LSB)
#define HT_FULL_GI_RATE2_MCS5_SET(x)                                 (((0 | (x)) << HT_FULL_GI_RATE2_MCS5_LSB) & HT_FULL_GI_RATE2_MCS5_MASK)
#define HT_FULL_GI_RATE2_MCS5_RESET                                  52
#define HT_FULL_GI_RATE2_MCS4_MSB                                    7
#define HT_FULL_GI_RATE2_MCS4_LSB                                    0
#define HT_FULL_GI_RATE2_MCS4_MASK                                   0x000000ff
#define HT_FULL_GI_RATE2_MCS4_GET(x)                                 (((x) & HT_FULL_GI_RATE2_MCS4_MASK) >> HT_FULL_GI_RATE2_MCS4_LSB)
#define HT_FULL_GI_RATE2_MCS4_SET(x)                                 (((0 | (x)) << HT_FULL_GI_RATE2_MCS4_LSB) & HT_FULL_GI_RATE2_MCS4_MASK)
#define HT_FULL_GI_RATE2_MCS4_RESET                                  39
#define HT_FULL_GI_RATE2_ADDRESS                                     0x861c
#define HT_FULL_GI_RATE2_HW_MASK                                     0xffffffff
#define HT_FULL_GI_RATE2_SW_MASK                                     0xffffffff
#define HT_FULL_GI_RATE2_HW_WRITE_MASK                               0x00000000
#define HT_FULL_GI_RATE2_SW_WRITE_MASK                               0xffffffff
#define HT_FULL_GI_RATE2_RSTMASK                                     0xffffffff
#define HT_FULL_GI_RATE2_RESET                                       0x413b3427

// 0x8620 (LEGACY_RATE1)
#define LEGACY_RATE1_RATE12_MSB                                      29
#define LEGACY_RATE1_RATE12_LSB                                      24
#define LEGACY_RATE1_RATE12_MASK                                     0x3f000000
#define LEGACY_RATE1_RATE12_GET(x)                                   (((x) & LEGACY_RATE1_RATE12_MASK) >> LEGACY_RATE1_RATE12_LSB)
#define LEGACY_RATE1_RATE12_SET(x)                                   (((0 | (x)) << LEGACY_RATE1_RATE12_LSB) & LEGACY_RATE1_RATE12_MASK)
#define LEGACY_RATE1_RATE12_RESET                                    54
#define LEGACY_RATE1_RATE11_MSB                                      23
#define LEGACY_RATE1_RATE11_LSB                                      18
#define LEGACY_RATE1_RATE11_MASK                                     0x00fc0000
#define LEGACY_RATE1_RATE11_GET(x)                                   (((x) & LEGACY_RATE1_RATE11_MASK) >> LEGACY_RATE1_RATE11_LSB)
#define LEGACY_RATE1_RATE11_SET(x)                                   (((0 | (x)) << LEGACY_RATE1_RATE11_LSB) & LEGACY_RATE1_RATE11_MASK)
#define LEGACY_RATE1_RATE11_RESET                                    6
#define LEGACY_RATE1_RATE10_MSB                                      17
#define LEGACY_RATE1_RATE10_LSB                                      12
#define LEGACY_RATE1_RATE10_MASK                                     0x0003f000
#define LEGACY_RATE1_RATE10_GET(x)                                   (((x) & LEGACY_RATE1_RATE10_MASK) >> LEGACY_RATE1_RATE10_LSB)
#define LEGACY_RATE1_RATE10_SET(x)                                   (((0 | (x)) << LEGACY_RATE1_RATE10_LSB) & LEGACY_RATE1_RATE10_MASK)
#define LEGACY_RATE1_RATE10_RESET                                    12
#define LEGACY_RATE1_RATE9_MSB                                       11
#define LEGACY_RATE1_RATE9_LSB                                       6
#define LEGACY_RATE1_RATE9_MASK                                      0x00000fc0
#define LEGACY_RATE1_RATE9_GET(x)                                    (((x) & LEGACY_RATE1_RATE9_MASK) >> LEGACY_RATE1_RATE9_LSB)
#define LEGACY_RATE1_RATE9_SET(x)                                    (((0 | (x)) << LEGACY_RATE1_RATE9_LSB) & LEGACY_RATE1_RATE9_MASK)
#define LEGACY_RATE1_RATE9_RESET                                     24
#define LEGACY_RATE1_RATE8_MSB                                       5
#define LEGACY_RATE1_RATE8_LSB                                       0
#define LEGACY_RATE1_RATE8_MASK                                      0x0000003f
#define LEGACY_RATE1_RATE8_GET(x)                                    (((x) & LEGACY_RATE1_RATE8_MASK) >> LEGACY_RATE1_RATE8_LSB)
#define LEGACY_RATE1_RATE8_SET(x)                                    (((0 | (x)) << LEGACY_RATE1_RATE8_LSB) & LEGACY_RATE1_RATE8_MASK)
#define LEGACY_RATE1_RATE8_RESET                                     48
#define LEGACY_RATE1_ADDRESS                                         0x8620
#define LEGACY_RATE1_HW_MASK                                         0x3fffffff
#define LEGACY_RATE1_SW_MASK                                         0x3fffffff
#define LEGACY_RATE1_HW_WRITE_MASK                                   0x00000000
#define LEGACY_RATE1_SW_WRITE_MASK                                   0x3fffffff
#define LEGACY_RATE1_RSTMASK                                         0xffffffff
#define LEGACY_RATE1_RESET                                           0x3618c630

// 0x8624 (LEGACY_RATE2)
#define LEGACY_RATE2_RATE25_MSB                                      29
#define LEGACY_RATE2_RATE25_LSB                                      24
#define LEGACY_RATE2_RATE25_MASK                                     0x3f000000
#define LEGACY_RATE2_RATE25_GET(x)                                   (((x) & LEGACY_RATE2_RATE25_MASK) >> LEGACY_RATE2_RATE25_LSB)
#define LEGACY_RATE2_RATE25_SET(x)                                   (((0 | (x)) << LEGACY_RATE2_RATE25_LSB) & LEGACY_RATE2_RATE25_MASK)
#define LEGACY_RATE2_RATE25_RESET                                    6
#define LEGACY_RATE2_RATE24_MSB                                      23
#define LEGACY_RATE2_RATE24_LSB                                      18
#define LEGACY_RATE2_RATE24_MASK                                     0x00fc0000
#define LEGACY_RATE2_RATE24_GET(x)                                   (((x) & LEGACY_RATE2_RATE24_MASK) >> LEGACY_RATE2_RATE24_LSB)
#define LEGACY_RATE2_RATE24_SET(x)                                   (((0 | (x)) << LEGACY_RATE2_RATE24_LSB) & LEGACY_RATE2_RATE24_MASK)
#define LEGACY_RATE2_RATE24_RESET                                    11
#define LEGACY_RATE2_RATE15_MSB                                      17
#define LEGACY_RATE2_RATE15_LSB                                      12
#define LEGACY_RATE2_RATE15_MASK                                     0x0003f000
#define LEGACY_RATE2_RATE15_GET(x)                                   (((x) & LEGACY_RATE2_RATE15_MASK) >> LEGACY_RATE2_RATE15_LSB)
#define LEGACY_RATE2_RATE15_SET(x)                                   (((0 | (x)) << LEGACY_RATE2_RATE15_LSB) & LEGACY_RATE2_RATE15_MASK)
#define LEGACY_RATE2_RATE15_RESET                                    9
#define LEGACY_RATE2_RATE14_MSB                                      11
#define LEGACY_RATE2_RATE14_LSB                                      6
#define LEGACY_RATE2_RATE14_MASK                                     0x00000fc0
#define LEGACY_RATE2_RATE14_GET(x)                                   (((x) & LEGACY_RATE2_RATE14_MASK) >> LEGACY_RATE2_RATE14_LSB)
#define LEGACY_RATE2_RATE14_SET(x)                                   (((0 | (x)) << LEGACY_RATE2_RATE14_LSB) & LEGACY_RATE2_RATE14_MASK)
#define LEGACY_RATE2_RATE14_RESET                                    22
#define LEGACY_RATE2_RATE13_MSB                                      5
#define LEGACY_RATE2_RATE13_LSB                                      0
#define LEGACY_RATE2_RATE13_MASK                                     0x0000003f
#define LEGACY_RATE2_RATE13_GET(x)                                   (((x) & LEGACY_RATE2_RATE13_MASK) >> LEGACY_RATE2_RATE13_LSB)
#define LEGACY_RATE2_RATE13_SET(x)                                   (((0 | (x)) << LEGACY_RATE2_RATE13_LSB) & LEGACY_RATE2_RATE13_MASK)
#define LEGACY_RATE2_RATE13_RESET                                    36
#define LEGACY_RATE2_ADDRESS                                         0x8624
#define LEGACY_RATE2_HW_MASK                                         0x3fffffff
#define LEGACY_RATE2_SW_MASK                                         0x3fffffff
#define LEGACY_RATE2_HW_WRITE_MASK                                   0x00000000
#define LEGACY_RATE2_SW_WRITE_MASK                                   0x3fffffff
#define LEGACY_RATE2_RSTMASK                                         0xffffffff
#define LEGACY_RATE2_RESET                                           0x062c95a4

// 0x8628 (LEGACY_RATE3)
#define LEGACY_RATE3_RATE30_MSB                                      29
#define LEGACY_RATE3_RATE30_LSB                                      24
#define LEGACY_RATE3_RATE30_MASK                                     0x3f000000
#define LEGACY_RATE3_RATE30_GET(x)                                   (((x) & LEGACY_RATE3_RATE30_MASK) >> LEGACY_RATE3_RATE30_LSB)
#define LEGACY_RATE3_RATE30_SET(x)                                   (((0 | (x)) << LEGACY_RATE3_RATE30_LSB) & LEGACY_RATE3_RATE30_MASK)
#define LEGACY_RATE3_RATE30_RESET                                    2
#define LEGACY_RATE3_RATE29_MSB                                      23
#define LEGACY_RATE3_RATE29_LSB                                      18
#define LEGACY_RATE3_RATE29_MASK                                     0x00fc0000
#define LEGACY_RATE3_RATE29_GET(x)                                   (((x) & LEGACY_RATE3_RATE29_MASK) >> LEGACY_RATE3_RATE29_LSB)
#define LEGACY_RATE3_RATE29_SET(x)                                   (((0 | (x)) << LEGACY_RATE3_RATE29_LSB) & LEGACY_RATE3_RATE29_MASK)
#define LEGACY_RATE3_RATE29_RESET                                    6
#define LEGACY_RATE3_RATE28_MSB                                      17
#define LEGACY_RATE3_RATE28_LSB                                      12
#define LEGACY_RATE3_RATE28_MASK                                     0x0003f000
#define LEGACY_RATE3_RATE28_GET(x)                                   (((x) & LEGACY_RATE3_RATE28_MASK) >> LEGACY_RATE3_RATE28_LSB)
#define LEGACY_RATE3_RATE28_SET(x)                                   (((0 | (x)) << LEGACY_RATE3_RATE28_LSB) & LEGACY_RATE3_RATE28_MASK)
#define LEGACY_RATE3_RATE28_RESET                                    11
#define LEGACY_RATE3_RATE27_MSB                                      11
#define LEGACY_RATE3_RATE27_LSB                                      6
#define LEGACY_RATE3_RATE27_MASK                                     0x00000fc0
#define LEGACY_RATE3_RATE27_GET(x)                                   (((x) & LEGACY_RATE3_RATE27_MASK) >> LEGACY_RATE3_RATE27_LSB)
#define LEGACY_RATE3_RATE27_SET(x)                                   (((0 | (x)) << LEGACY_RATE3_RATE27_LSB) & LEGACY_RATE3_RATE27_MASK)
#define LEGACY_RATE3_RATE27_RESET                                    1
#define LEGACY_RATE3_RATE26_MSB                                      5
#define LEGACY_RATE3_RATE26_LSB                                      0
#define LEGACY_RATE3_RATE26_MASK                                     0x0000003f
#define LEGACY_RATE3_RATE26_GET(x)                                   (((x) & LEGACY_RATE3_RATE26_MASK) >> LEGACY_RATE3_RATE26_LSB)
#define LEGACY_RATE3_RATE26_SET(x)                                   (((0 | (x)) << LEGACY_RATE3_RATE26_LSB) & LEGACY_RATE3_RATE26_MASK)
#define LEGACY_RATE3_RATE26_RESET                                    2
#define LEGACY_RATE3_ADDRESS                                         0x8628
#define LEGACY_RATE3_HW_MASK                                         0x3fffffff
#define LEGACY_RATE3_SW_MASK                                         0x3fffffff
#define LEGACY_RATE3_HW_WRITE_MASK                                   0x00000000
#define LEGACY_RATE3_SW_WRITE_MASK                                   0x3fffffff
#define LEGACY_RATE3_RSTMASK                                         0xffffffff
#define LEGACY_RATE3_RESET                                           0x0218b042

// 0x862c (RX_INT_FILTER)
#define RX_INT_FILTER_RSSI_HIGH_MSB                                  18
#define RX_INT_FILTER_RSSI_HIGH_LSB                                  18
#define RX_INT_FILTER_RSSI_HIGH_MASK                                 0x00040000
#define RX_INT_FILTER_RSSI_HIGH_GET(x)                               (((x) & RX_INT_FILTER_RSSI_HIGH_MASK) >> RX_INT_FILTER_RSSI_HIGH_LSB)
#define RX_INT_FILTER_RSSI_HIGH_SET(x)                               (((0 | (x)) << RX_INT_FILTER_RSSI_HIGH_LSB) & RX_INT_FILTER_RSSI_HIGH_MASK)
#define RX_INT_FILTER_RSSI_HIGH_RESET                                1
#define RX_INT_FILTER_BEACON_MSB                                     17
#define RX_INT_FILTER_BEACON_LSB                                     17
#define RX_INT_FILTER_BEACON_MASK                                    0x00020000
#define RX_INT_FILTER_BEACON_GET(x)                                  (((x) & RX_INT_FILTER_BEACON_MASK) >> RX_INT_FILTER_BEACON_LSB)
#define RX_INT_FILTER_BEACON_SET(x)                                  (((0 | (x)) << RX_INT_FILTER_BEACON_LSB) & RX_INT_FILTER_BEACON_MASK)
#define RX_INT_FILTER_BEACON_RESET                                   1
#define RX_INT_FILTER_AMPDU_MSB                                      16
#define RX_INT_FILTER_AMPDU_LSB                                      16
#define RX_INT_FILTER_AMPDU_MASK                                     0x00010000
#define RX_INT_FILTER_AMPDU_GET(x)                                   (((x) & RX_INT_FILTER_AMPDU_MASK) >> RX_INT_FILTER_AMPDU_LSB)
#define RX_INT_FILTER_AMPDU_SET(x)                                   (((0 | (x)) << RX_INT_FILTER_AMPDU_LSB) & RX_INT_FILTER_AMPDU_MASK)
#define RX_INT_FILTER_AMPDU_RESET                                    1
#define RX_INT_FILTER_EOSP_MSB                                       15
#define RX_INT_FILTER_EOSP_LSB                                       15
#define RX_INT_FILTER_EOSP_MASK                                      0x00008000
#define RX_INT_FILTER_EOSP_GET(x)                                    (((x) & RX_INT_FILTER_EOSP_MASK) >> RX_INT_FILTER_EOSP_LSB)
#define RX_INT_FILTER_EOSP_SET(x)                                    (((0 | (x)) << RX_INT_FILTER_EOSP_LSB) & RX_INT_FILTER_EOSP_MASK)
#define RX_INT_FILTER_EOSP_RESET                                     1
#define RX_INT_FILTER_LENGTH_LOW_MSB                                 14
#define RX_INT_FILTER_LENGTH_LOW_LSB                                 14
#define RX_INT_FILTER_LENGTH_LOW_MASK                                0x00004000
#define RX_INT_FILTER_LENGTH_LOW_GET(x)                              (((x) & RX_INT_FILTER_LENGTH_LOW_MASK) >> RX_INT_FILTER_LENGTH_LOW_LSB)
#define RX_INT_FILTER_LENGTH_LOW_SET(x)                              (((0 | (x)) << RX_INT_FILTER_LENGTH_LOW_LSB) & RX_INT_FILTER_LENGTH_LOW_MASK)
#define RX_INT_FILTER_LENGTH_LOW_RESET                               1
#define RX_INT_FILTER_LENGTH_HIGH_MSB                                13
#define RX_INT_FILTER_LENGTH_HIGH_LSB                                13
#define RX_INT_FILTER_LENGTH_HIGH_MASK                               0x00002000
#define RX_INT_FILTER_LENGTH_HIGH_GET(x)                             (((x) & RX_INT_FILTER_LENGTH_HIGH_MASK) >> RX_INT_FILTER_LENGTH_HIGH_LSB)
#define RX_INT_FILTER_LENGTH_HIGH_SET(x)                             (((0 | (x)) << RX_INT_FILTER_LENGTH_HIGH_LSB) & RX_INT_FILTER_LENGTH_HIGH_MASK)
#define RX_INT_FILTER_LENGTH_HIGH_RESET                              1
#define RX_INT_FILTER_RSSI_MSB                                       12
#define RX_INT_FILTER_RSSI_LSB                                       12
#define RX_INT_FILTER_RSSI_MASK                                      0x00001000
#define RX_INT_FILTER_RSSI_GET(x)                                    (((x) & RX_INT_FILTER_RSSI_MASK) >> RX_INT_FILTER_RSSI_LSB)
#define RX_INT_FILTER_RSSI_SET(x)                                    (((0 | (x)) << RX_INT_FILTER_RSSI_LSB) & RX_INT_FILTER_RSSI_MASK)
#define RX_INT_FILTER_RSSI_RESET                                     1
#define RX_INT_FILTER_RATE_LOW_MSB                                   11
#define RX_INT_FILTER_RATE_LOW_LSB                                   11
#define RX_INT_FILTER_RATE_LOW_MASK                                  0x00000800
#define RX_INT_FILTER_RATE_LOW_GET(x)                                (((x) & RX_INT_FILTER_RATE_LOW_MASK) >> RX_INT_FILTER_RATE_LOW_LSB)
#define RX_INT_FILTER_RATE_LOW_SET(x)                                (((0 | (x)) << RX_INT_FILTER_RATE_LOW_LSB) & RX_INT_FILTER_RATE_LOW_MASK)
#define RX_INT_FILTER_RATE_LOW_RESET                                 1
#define RX_INT_FILTER_RATE_HIGH_MSB                                  10
#define RX_INT_FILTER_RATE_HIGH_LSB                                  10
#define RX_INT_FILTER_RATE_HIGH_MASK                                 0x00000400
#define RX_INT_FILTER_RATE_HIGH_GET(x)                               (((x) & RX_INT_FILTER_RATE_HIGH_MASK) >> RX_INT_FILTER_RATE_HIGH_LSB)
#define RX_INT_FILTER_RATE_HIGH_SET(x)                               (((0 | (x)) << RX_INT_FILTER_RATE_HIGH_LSB) & RX_INT_FILTER_RATE_HIGH_MASK)
#define RX_INT_FILTER_RATE_HIGH_RESET                                1
#define RX_INT_FILTER_MORE_FRAG_MSB                                  9
#define RX_INT_FILTER_MORE_FRAG_LSB                                  9
#define RX_INT_FILTER_MORE_FRAG_MASK                                 0x00000200
#define RX_INT_FILTER_MORE_FRAG_GET(x)                               (((x) & RX_INT_FILTER_MORE_FRAG_MASK) >> RX_INT_FILTER_MORE_FRAG_LSB)
#define RX_INT_FILTER_MORE_FRAG_SET(x)                               (((0 | (x)) << RX_INT_FILTER_MORE_FRAG_LSB) & RX_INT_FILTER_MORE_FRAG_MASK)
#define RX_INT_FILTER_MORE_FRAG_RESET                                1
#define RX_INT_FILTER_MORE_DATA_MSB                                  8
#define RX_INT_FILTER_MORE_DATA_LSB                                  8
#define RX_INT_FILTER_MORE_DATA_MASK                                 0x00000100
#define RX_INT_FILTER_MORE_DATA_GET(x)                               (((x) & RX_INT_FILTER_MORE_DATA_MASK) >> RX_INT_FILTER_MORE_DATA_LSB)
#define RX_INT_FILTER_MORE_DATA_SET(x)                               (((0 | (x)) << RX_INT_FILTER_MORE_DATA_LSB) & RX_INT_FILTER_MORE_DATA_MASK)
#define RX_INT_FILTER_MORE_DATA_RESET                                1
#define RX_INT_FILTER_RETRY_MSB                                      7
#define RX_INT_FILTER_RETRY_LSB                                      7
#define RX_INT_FILTER_RETRY_MASK                                     0x00000080
#define RX_INT_FILTER_RETRY_GET(x)                                   (((x) & RX_INT_FILTER_RETRY_MASK) >> RX_INT_FILTER_RETRY_LSB)
#define RX_INT_FILTER_RETRY_SET(x)                                   (((0 | (x)) << RX_INT_FILTER_RETRY_LSB) & RX_INT_FILTER_RETRY_MASK)
#define RX_INT_FILTER_RETRY_RESET                                    1
#define RX_INT_FILTER_CTS_MSB                                        6
#define RX_INT_FILTER_CTS_LSB                                        6
#define RX_INT_FILTER_CTS_MASK                                       0x00000040
#define RX_INT_FILTER_CTS_GET(x)                                     (((x) & RX_INT_FILTER_CTS_MASK) >> RX_INT_FILTER_CTS_LSB)
#define RX_INT_FILTER_CTS_SET(x)                                     (((0 | (x)) << RX_INT_FILTER_CTS_LSB) & RX_INT_FILTER_CTS_MASK)
#define RX_INT_FILTER_CTS_RESET                                      1
#define RX_INT_FILTER_ACK_MSB                                        5
#define RX_INT_FILTER_ACK_LSB                                        5
#define RX_INT_FILTER_ACK_MASK                                       0x00000020
#define RX_INT_FILTER_ACK_GET(x)                                     (((x) & RX_INT_FILTER_ACK_MASK) >> RX_INT_FILTER_ACK_LSB)
#define RX_INT_FILTER_ACK_SET(x)                                     (((0 | (x)) << RX_INT_FILTER_ACK_LSB) & RX_INT_FILTER_ACK_MASK)
#define RX_INT_FILTER_ACK_RESET                                      1
#define RX_INT_FILTER_RTS_MSB                                        4
#define RX_INT_FILTER_RTS_LSB                                        4
#define RX_INT_FILTER_RTS_MASK                                       0x00000010
#define RX_INT_FILTER_RTS_GET(x)                                     (((x) & RX_INT_FILTER_RTS_MASK) >> RX_INT_FILTER_RTS_LSB)
#define RX_INT_FILTER_RTS_SET(x)                                     (((0 | (x)) << RX_INT_FILTER_RTS_LSB) & RX_INT_FILTER_RTS_MASK)
#define RX_INT_FILTER_RTS_RESET                                      1
#define RX_INT_FILTER_MCAST_MSB                                      3
#define RX_INT_FILTER_MCAST_LSB                                      3
#define RX_INT_FILTER_MCAST_MASK                                     0x00000008
#define RX_INT_FILTER_MCAST_GET(x)                                   (((x) & RX_INT_FILTER_MCAST_MASK) >> RX_INT_FILTER_MCAST_LSB)
#define RX_INT_FILTER_MCAST_SET(x)                                   (((0 | (x)) << RX_INT_FILTER_MCAST_LSB) & RX_INT_FILTER_MCAST_MASK)
#define RX_INT_FILTER_MCAST_RESET                                    1
#define RX_INT_FILTER_BCAST_MSB                                      2
#define RX_INT_FILTER_BCAST_LSB                                      2
#define RX_INT_FILTER_BCAST_MASK                                     0x00000004
#define RX_INT_FILTER_BCAST_GET(x)                                   (((x) & RX_INT_FILTER_BCAST_MASK) >> RX_INT_FILTER_BCAST_LSB)
#define RX_INT_FILTER_BCAST_SET(x)                                   (((0 | (x)) << RX_INT_FILTER_BCAST_LSB) & RX_INT_FILTER_BCAST_MASK)
#define RX_INT_FILTER_BCAST_RESET                                    1
#define RX_INT_FILTER_DIRECTED_MSB                                   1
#define RX_INT_FILTER_DIRECTED_LSB                                   1
#define RX_INT_FILTER_DIRECTED_MASK                                  0x00000002
#define RX_INT_FILTER_DIRECTED_GET(x)                                (((x) & RX_INT_FILTER_DIRECTED_MASK) >> RX_INT_FILTER_DIRECTED_LSB)
#define RX_INT_FILTER_DIRECTED_SET(x)                                (((0 | (x)) << RX_INT_FILTER_DIRECTED_LSB) & RX_INT_FILTER_DIRECTED_MASK)
#define RX_INT_FILTER_DIRECTED_RESET                                 1
#define RX_INT_FILTER_ENABLE_MSB                                     0
#define RX_INT_FILTER_ENABLE_LSB                                     0
#define RX_INT_FILTER_ENABLE_MASK                                    0x00000001
#define RX_INT_FILTER_ENABLE_GET(x)                                  (((x) & RX_INT_FILTER_ENABLE_MASK) >> RX_INT_FILTER_ENABLE_LSB)
#define RX_INT_FILTER_ENABLE_SET(x)                                  (((0 | (x)) << RX_INT_FILTER_ENABLE_LSB) & RX_INT_FILTER_ENABLE_MASK)
#define RX_INT_FILTER_ENABLE_RESET                                   1
#define RX_INT_FILTER_ADDRESS                                        0x862c
#define RX_INT_FILTER_HW_MASK                                        0x0007ffff
#define RX_INT_FILTER_SW_MASK                                        0x0007ffff
#define RX_INT_FILTER_HW_WRITE_MASK                                  0x00000000
#define RX_INT_FILTER_SW_WRITE_MASK                                  0x0007ffff
#define RX_INT_FILTER_RSTMASK                                        0xffffffff
#define RX_INT_FILTER_RESET                                          0x0007ffff

// 0x8630 (RX_INT_OVERFLOW)
#define RX_INT_OVERFLOW_STATUS_MSB                                   0
#define RX_INT_OVERFLOW_STATUS_LSB                                   0
#define RX_INT_OVERFLOW_STATUS_MASK                                  0x00000001
#define RX_INT_OVERFLOW_STATUS_GET(x)                                (((x) & RX_INT_OVERFLOW_STATUS_MASK) >> RX_INT_OVERFLOW_STATUS_LSB)
#define RX_INT_OVERFLOW_STATUS_SET(x)                                (((0 | (x)) << RX_INT_OVERFLOW_STATUS_LSB) & RX_INT_OVERFLOW_STATUS_MASK)
#define RX_INT_OVERFLOW_STATUS_RESET                                 1
#define RX_INT_OVERFLOW_ADDRESS                                      0x8630
#define RX_INT_OVERFLOW_HW_MASK                                      0x00000001
#define RX_INT_OVERFLOW_SW_MASK                                      0x00000001
#define RX_INT_OVERFLOW_HW_WRITE_MASK                                0x00000001
#define RX_INT_OVERFLOW_SW_WRITE_MASK                                0x00000001
#define RX_INT_OVERFLOW_RSTMASK                                      0xffffffff
#define RX_INT_OVERFLOW_RESET                                        0x00000001

// 0x8634 (RX_FILTER_THRESH0)
#define RX_FILTER_THRESH0_RSSI_HIGH_MSB                              31
#define RX_FILTER_THRESH0_RSSI_HIGH_LSB                              24
#define RX_FILTER_THRESH0_RSSI_HIGH_MASK                             0xff000000
#define RX_FILTER_THRESH0_RSSI_HIGH_GET(x)                           (((x) & RX_FILTER_THRESH0_RSSI_HIGH_MASK) >> RX_FILTER_THRESH0_RSSI_HIGH_LSB)
#define RX_FILTER_THRESH0_RSSI_HIGH_SET(x)                           (((0 | (x)) << RX_FILTER_THRESH0_RSSI_HIGH_LSB) & RX_FILTER_THRESH0_RSSI_HIGH_MASK)
#define RX_FILTER_THRESH0_RSSI_HIGH_RESET                            1
#define RX_FILTER_THRESH0_RSSI_LOW_MSB                               23
#define RX_FILTER_THRESH0_RSSI_LOW_LSB                               16
#define RX_FILTER_THRESH0_RSSI_LOW_MASK                              0x00ff0000
#define RX_FILTER_THRESH0_RSSI_LOW_GET(x)                            (((x) & RX_FILTER_THRESH0_RSSI_LOW_MASK) >> RX_FILTER_THRESH0_RSSI_LOW_LSB)
#define RX_FILTER_THRESH0_RSSI_LOW_SET(x)                            (((0 | (x)) << RX_FILTER_THRESH0_RSSI_LOW_LSB) & RX_FILTER_THRESH0_RSSI_LOW_MASK)
#define RX_FILTER_THRESH0_RSSI_LOW_RESET                             1
#define RX_FILTER_THRESH0_RATE_LOW_MSB                               15
#define RX_FILTER_THRESH0_RATE_LOW_LSB                               8
#define RX_FILTER_THRESH0_RATE_LOW_MASK                              0x0000ff00
#define RX_FILTER_THRESH0_RATE_LOW_GET(x)                            (((x) & RX_FILTER_THRESH0_RATE_LOW_MASK) >> RX_FILTER_THRESH0_RATE_LOW_LSB)
#define RX_FILTER_THRESH0_RATE_LOW_SET(x)                            (((0 | (x)) << RX_FILTER_THRESH0_RATE_LOW_LSB) & RX_FILTER_THRESH0_RATE_LOW_MASK)
#define RX_FILTER_THRESH0_RATE_LOW_RESET                             0
#define RX_FILTER_THRESH0_RATE_HIGH_MSB                              7
#define RX_FILTER_THRESH0_RATE_HIGH_LSB                              0
#define RX_FILTER_THRESH0_RATE_HIGH_MASK                             0x000000ff
#define RX_FILTER_THRESH0_RATE_HIGH_GET(x)                           (((x) & RX_FILTER_THRESH0_RATE_HIGH_MASK) >> RX_FILTER_THRESH0_RATE_HIGH_LSB)
#define RX_FILTER_THRESH0_RATE_HIGH_SET(x)                           (((0 | (x)) << RX_FILTER_THRESH0_RATE_HIGH_LSB) & RX_FILTER_THRESH0_RATE_HIGH_MASK)
#define RX_FILTER_THRESH0_RATE_HIGH_RESET                            0
#define RX_FILTER_THRESH0_ADDRESS                                    0x8634
#define RX_FILTER_THRESH0_HW_MASK                                    0xffffffff
#define RX_FILTER_THRESH0_SW_MASK                                    0xffffffff
#define RX_FILTER_THRESH0_HW_WRITE_MASK                              0x00000000
#define RX_FILTER_THRESH0_SW_WRITE_MASK                              0xffffffff
#define RX_FILTER_THRESH0_RSTMASK                                    0xffffffff
#define RX_FILTER_THRESH0_RESET                                      0x01010000

// 0x8638 (RX_FILTER_THRESH1)
#define RX_FILTER_THRESH1_LENGTH_LOW_MSB                             23
#define RX_FILTER_THRESH1_LENGTH_LOW_LSB                             12
#define RX_FILTER_THRESH1_LENGTH_LOW_MASK                            0x00fff000
#define RX_FILTER_THRESH1_LENGTH_LOW_GET(x)                          (((x) & RX_FILTER_THRESH1_LENGTH_LOW_MASK) >> RX_FILTER_THRESH1_LENGTH_LOW_LSB)
#define RX_FILTER_THRESH1_LENGTH_LOW_SET(x)                          (((0 | (x)) << RX_FILTER_THRESH1_LENGTH_LOW_LSB) & RX_FILTER_THRESH1_LENGTH_LOW_MASK)
#define RX_FILTER_THRESH1_LENGTH_LOW_RESET                           0
#define RX_FILTER_THRESH1_LENGTH_HIGH_MSB                            11
#define RX_FILTER_THRESH1_LENGTH_HIGH_LSB                            0
#define RX_FILTER_THRESH1_LENGTH_HIGH_MASK                           0x00000fff
#define RX_FILTER_THRESH1_LENGTH_HIGH_GET(x)                         (((x) & RX_FILTER_THRESH1_LENGTH_HIGH_MASK) >> RX_FILTER_THRESH1_LENGTH_HIGH_LSB)
#define RX_FILTER_THRESH1_LENGTH_HIGH_SET(x)                         (((0 | (x)) << RX_FILTER_THRESH1_LENGTH_HIGH_LSB) & RX_FILTER_THRESH1_LENGTH_HIGH_MASK)
#define RX_FILTER_THRESH1_LENGTH_HIGH_RESET                          4095
#define RX_FILTER_THRESH1_ADDRESS                                    0x8638
#define RX_FILTER_THRESH1_HW_MASK                                    0x00ffffff
#define RX_FILTER_THRESH1_SW_MASK                                    0x00ffffff
#define RX_FILTER_THRESH1_HW_WRITE_MASK                              0x00000000
#define RX_FILTER_THRESH1_SW_WRITE_MASK                              0x00ffffff
#define RX_FILTER_THRESH1_RSTMASK                                    0xffffffff
#define RX_FILTER_THRESH1_RESET                                      0x00000fff

// 0x863c (RX_PRIORITY_THRESH0)
#define RX_PRIORITY_THRESH0_RSSI_LOW_MSB                             31
#define RX_PRIORITY_THRESH0_RSSI_LOW_LSB                             24
#define RX_PRIORITY_THRESH0_RSSI_LOW_MASK                            0xff000000
#define RX_PRIORITY_THRESH0_RSSI_LOW_GET(x)                          (((x) & RX_PRIORITY_THRESH0_RSSI_LOW_MASK) >> RX_PRIORITY_THRESH0_RSSI_LOW_LSB)
#define RX_PRIORITY_THRESH0_RSSI_LOW_SET(x)                          (((0 | (x)) << RX_PRIORITY_THRESH0_RSSI_LOW_LSB) & RX_PRIORITY_THRESH0_RSSI_LOW_MASK)
#define RX_PRIORITY_THRESH0_RSSI_LOW_RESET                           1
#define RX_PRIORITY_THRESH0_RSSI_HIGH_MSB                            23
#define RX_PRIORITY_THRESH0_RSSI_HIGH_LSB                            16
#define RX_PRIORITY_THRESH0_RSSI_HIGH_MASK                           0x00ff0000
#define RX_PRIORITY_THRESH0_RSSI_HIGH_GET(x)                         (((x) & RX_PRIORITY_THRESH0_RSSI_HIGH_MASK) >> RX_PRIORITY_THRESH0_RSSI_HIGH_LSB)
#define RX_PRIORITY_THRESH0_RSSI_HIGH_SET(x)                         (((0 | (x)) << RX_PRIORITY_THRESH0_RSSI_HIGH_LSB) & RX_PRIORITY_THRESH0_RSSI_HIGH_MASK)
#define RX_PRIORITY_THRESH0_RSSI_HIGH_RESET                          1
#define RX_PRIORITY_THRESH0_RATE_LOW_MSB                             15
#define RX_PRIORITY_THRESH0_RATE_LOW_LSB                             8
#define RX_PRIORITY_THRESH0_RATE_LOW_MASK                            0x0000ff00
#define RX_PRIORITY_THRESH0_RATE_LOW_GET(x)                          (((x) & RX_PRIORITY_THRESH0_RATE_LOW_MASK) >> RX_PRIORITY_THRESH0_RATE_LOW_LSB)
#define RX_PRIORITY_THRESH0_RATE_LOW_SET(x)                          (((0 | (x)) << RX_PRIORITY_THRESH0_RATE_LOW_LSB) & RX_PRIORITY_THRESH0_RATE_LOW_MASK)
#define RX_PRIORITY_THRESH0_RATE_LOW_RESET                           0
#define RX_PRIORITY_THRESH0_RATE_HIGH_MSB                            7
#define RX_PRIORITY_THRESH0_RATE_HIGH_LSB                            0
#define RX_PRIORITY_THRESH0_RATE_HIGH_MASK                           0x000000ff
#define RX_PRIORITY_THRESH0_RATE_HIGH_GET(x)                         (((x) & RX_PRIORITY_THRESH0_RATE_HIGH_MASK) >> RX_PRIORITY_THRESH0_RATE_HIGH_LSB)
#define RX_PRIORITY_THRESH0_RATE_HIGH_SET(x)                         (((0 | (x)) << RX_PRIORITY_THRESH0_RATE_HIGH_LSB) & RX_PRIORITY_THRESH0_RATE_HIGH_MASK)
#define RX_PRIORITY_THRESH0_RATE_HIGH_RESET                          0
#define RX_PRIORITY_THRESH0_ADDRESS                                  0x863c
#define RX_PRIORITY_THRESH0_HW_MASK                                  0xffffffff
#define RX_PRIORITY_THRESH0_SW_MASK                                  0xffffffff
#define RX_PRIORITY_THRESH0_HW_WRITE_MASK                            0x00000000
#define RX_PRIORITY_THRESH0_SW_WRITE_MASK                            0xffffffff
#define RX_PRIORITY_THRESH0_RSTMASK                                  0xffffffff
#define RX_PRIORITY_THRESH0_RESET                                    0x01010000

// 0x8640 (RX_PRIORITY_THRESH1)
#define RX_PRIORITY_THRESH1_XCAST_RSSI_HIGH_MSB                      31
#define RX_PRIORITY_THRESH1_XCAST_RSSI_HIGH_LSB                      24
#define RX_PRIORITY_THRESH1_XCAST_RSSI_HIGH_MASK                     0xff000000
#define RX_PRIORITY_THRESH1_XCAST_RSSI_HIGH_GET(x)                   (((x) & RX_PRIORITY_THRESH1_XCAST_RSSI_HIGH_MASK) >> RX_PRIORITY_THRESH1_XCAST_RSSI_HIGH_LSB)
#define RX_PRIORITY_THRESH1_XCAST_RSSI_HIGH_SET(x)                   (((0 | (x)) << RX_PRIORITY_THRESH1_XCAST_RSSI_HIGH_LSB) & RX_PRIORITY_THRESH1_XCAST_RSSI_HIGH_MASK)
#define RX_PRIORITY_THRESH1_XCAST_RSSI_HIGH_RESET                    1
#define RX_PRIORITY_THRESH1_LENGTH_LOW_MSB                           23
#define RX_PRIORITY_THRESH1_LENGTH_LOW_LSB                           12
#define RX_PRIORITY_THRESH1_LENGTH_LOW_MASK                          0x00fff000
#define RX_PRIORITY_THRESH1_LENGTH_LOW_GET(x)                        (((x) & RX_PRIORITY_THRESH1_LENGTH_LOW_MASK) >> RX_PRIORITY_THRESH1_LENGTH_LOW_LSB)
#define RX_PRIORITY_THRESH1_LENGTH_LOW_SET(x)                        (((0 | (x)) << RX_PRIORITY_THRESH1_LENGTH_LOW_LSB) & RX_PRIORITY_THRESH1_LENGTH_LOW_MASK)
#define RX_PRIORITY_THRESH1_LENGTH_LOW_RESET                         0
#define RX_PRIORITY_THRESH1_LENGTH_HIGH_MSB                          11
#define RX_PRIORITY_THRESH1_LENGTH_HIGH_LSB                          0
#define RX_PRIORITY_THRESH1_LENGTH_HIGH_MASK                         0x00000fff
#define RX_PRIORITY_THRESH1_LENGTH_HIGH_GET(x)                       (((x) & RX_PRIORITY_THRESH1_LENGTH_HIGH_MASK) >> RX_PRIORITY_THRESH1_LENGTH_HIGH_LSB)
#define RX_PRIORITY_THRESH1_LENGTH_HIGH_SET(x)                       (((0 | (x)) << RX_PRIORITY_THRESH1_LENGTH_HIGH_LSB) & RX_PRIORITY_THRESH1_LENGTH_HIGH_MASK)
#define RX_PRIORITY_THRESH1_LENGTH_HIGH_RESET                        4095
#define RX_PRIORITY_THRESH1_ADDRESS                                  0x8640
#define RX_PRIORITY_THRESH1_HW_MASK                                  0xffffffff
#define RX_PRIORITY_THRESH1_SW_MASK                                  0xffffffff
#define RX_PRIORITY_THRESH1_HW_WRITE_MASK                            0x00000000
#define RX_PRIORITY_THRESH1_SW_WRITE_MASK                            0xffffffff
#define RX_PRIORITY_THRESH1_RSTMASK                                  0xffffffff
#define RX_PRIORITY_THRESH1_RESET                                    0x01000fff

// 0x8644 (RX_PRIORITY_THRESH2)
#define RX_PRIORITY_THRESH2_NULL_RSSI_HIGH_MSB                       31
#define RX_PRIORITY_THRESH2_NULL_RSSI_HIGH_LSB                       24
#define RX_PRIORITY_THRESH2_NULL_RSSI_HIGH_MASK                      0xff000000
#define RX_PRIORITY_THRESH2_NULL_RSSI_HIGH_GET(x)                    (((x) & RX_PRIORITY_THRESH2_NULL_RSSI_HIGH_MASK) >> RX_PRIORITY_THRESH2_NULL_RSSI_HIGH_LSB)
#define RX_PRIORITY_THRESH2_NULL_RSSI_HIGH_SET(x)                    (((0 | (x)) << RX_PRIORITY_THRESH2_NULL_RSSI_HIGH_LSB) & RX_PRIORITY_THRESH2_NULL_RSSI_HIGH_MASK)
#define RX_PRIORITY_THRESH2_NULL_RSSI_HIGH_RESET                     1
#define RX_PRIORITY_THRESH2_BEACON_RSSI_HIGH_MSB                     23
#define RX_PRIORITY_THRESH2_BEACON_RSSI_HIGH_LSB                     16
#define RX_PRIORITY_THRESH2_BEACON_RSSI_HIGH_MASK                    0x00ff0000
#define RX_PRIORITY_THRESH2_BEACON_RSSI_HIGH_GET(x)                  (((x) & RX_PRIORITY_THRESH2_BEACON_RSSI_HIGH_MASK) >> RX_PRIORITY_THRESH2_BEACON_RSSI_HIGH_LSB)
#define RX_PRIORITY_THRESH2_BEACON_RSSI_HIGH_SET(x)                  (((0 | (x)) << RX_PRIORITY_THRESH2_BEACON_RSSI_HIGH_LSB) & RX_PRIORITY_THRESH2_BEACON_RSSI_HIGH_MASK)
#define RX_PRIORITY_THRESH2_BEACON_RSSI_HIGH_RESET                   1
#define RX_PRIORITY_THRESH2_MGMT_RSSI_HIGH_MSB                       15
#define RX_PRIORITY_THRESH2_MGMT_RSSI_HIGH_LSB                       8
#define RX_PRIORITY_THRESH2_MGMT_RSSI_HIGH_MASK                      0x0000ff00
#define RX_PRIORITY_THRESH2_MGMT_RSSI_HIGH_GET(x)                    (((x) & RX_PRIORITY_THRESH2_MGMT_RSSI_HIGH_MASK) >> RX_PRIORITY_THRESH2_MGMT_RSSI_HIGH_LSB)
#define RX_PRIORITY_THRESH2_MGMT_RSSI_HIGH_SET(x)                    (((0 | (x)) << RX_PRIORITY_THRESH2_MGMT_RSSI_HIGH_LSB) & RX_PRIORITY_THRESH2_MGMT_RSSI_HIGH_MASK)
#define RX_PRIORITY_THRESH2_MGMT_RSSI_HIGH_RESET                     1
#define RX_PRIORITY_THRESH2_PRESP_RSSI_HIGH_MSB                      7
#define RX_PRIORITY_THRESH2_PRESP_RSSI_HIGH_LSB                      0
#define RX_PRIORITY_THRESH2_PRESP_RSSI_HIGH_MASK                     0x000000ff
#define RX_PRIORITY_THRESH2_PRESP_RSSI_HIGH_GET(x)                   (((x) & RX_PRIORITY_THRESH2_PRESP_RSSI_HIGH_MASK) >> RX_PRIORITY_THRESH2_PRESP_RSSI_HIGH_LSB)
#define RX_PRIORITY_THRESH2_PRESP_RSSI_HIGH_SET(x)                   (((0 | (x)) << RX_PRIORITY_THRESH2_PRESP_RSSI_HIGH_LSB) & RX_PRIORITY_THRESH2_PRESP_RSSI_HIGH_MASK)
#define RX_PRIORITY_THRESH2_PRESP_RSSI_HIGH_RESET                    1
#define RX_PRIORITY_THRESH2_ADDRESS                                  0x8644
#define RX_PRIORITY_THRESH2_HW_MASK                                  0xffffffff
#define RX_PRIORITY_THRESH2_SW_MASK                                  0xffffffff
#define RX_PRIORITY_THRESH2_HW_WRITE_MASK                            0x00000000
#define RX_PRIORITY_THRESH2_SW_WRITE_MASK                            0xffffffff
#define RX_PRIORITY_THRESH2_RSTMASK                                  0xffffffff
#define RX_PRIORITY_THRESH2_RESET                                    0x01010101

// 0x8648 (RX_PRIORITY_THRESH3)
#define RX_PRIORITY_THRESH3_PS_POLL_RSSI_HIGH_MSB                    15
#define RX_PRIORITY_THRESH3_PS_POLL_RSSI_HIGH_LSB                    8
#define RX_PRIORITY_THRESH3_PS_POLL_RSSI_HIGH_MASK                   0x0000ff00
#define RX_PRIORITY_THRESH3_PS_POLL_RSSI_HIGH_GET(x)                 (((x) & RX_PRIORITY_THRESH3_PS_POLL_RSSI_HIGH_MASK) >> RX_PRIORITY_THRESH3_PS_POLL_RSSI_HIGH_LSB)
#define RX_PRIORITY_THRESH3_PS_POLL_RSSI_HIGH_SET(x)                 (((0 | (x)) << RX_PRIORITY_THRESH3_PS_POLL_RSSI_HIGH_LSB) & RX_PRIORITY_THRESH3_PS_POLL_RSSI_HIGH_MASK)
#define RX_PRIORITY_THRESH3_PS_POLL_RSSI_HIGH_RESET                  1
#define RX_PRIORITY_THRESH3_PREQ_RSSI_HIGH_MSB                       7
#define RX_PRIORITY_THRESH3_PREQ_RSSI_HIGH_LSB                       0
#define RX_PRIORITY_THRESH3_PREQ_RSSI_HIGH_MASK                      0x000000ff
#define RX_PRIORITY_THRESH3_PREQ_RSSI_HIGH_GET(x)                    (((x) & RX_PRIORITY_THRESH3_PREQ_RSSI_HIGH_MASK) >> RX_PRIORITY_THRESH3_PREQ_RSSI_HIGH_LSB)
#define RX_PRIORITY_THRESH3_PREQ_RSSI_HIGH_SET(x)                    (((0 | (x)) << RX_PRIORITY_THRESH3_PREQ_RSSI_HIGH_LSB) & RX_PRIORITY_THRESH3_PREQ_RSSI_HIGH_MASK)
#define RX_PRIORITY_THRESH3_PREQ_RSSI_HIGH_RESET                     1
#define RX_PRIORITY_THRESH3_ADDRESS                                  0x8648
#define RX_PRIORITY_THRESH3_HW_MASK                                  0x0000ffff
#define RX_PRIORITY_THRESH3_SW_MASK                                  0x0000ffff
#define RX_PRIORITY_THRESH3_HW_WRITE_MASK                            0x00000000
#define RX_PRIORITY_THRESH3_SW_WRITE_MASK                            0x0000ffff
#define RX_PRIORITY_THRESH3_RSTMASK                                  0xffffffff
#define RX_PRIORITY_THRESH3_RESET                                    0x00000101

// 0x864c (RX_PRIORITY_OFFSET0)
#define RX_PRIORITY_OFFSET0_XCAST_RSSI_HIGH_MSB                      29
#define RX_PRIORITY_OFFSET0_XCAST_RSSI_HIGH_LSB                      24
#define RX_PRIORITY_OFFSET0_XCAST_RSSI_HIGH_MASK                     0x3f000000
#define RX_PRIORITY_OFFSET0_XCAST_RSSI_HIGH_GET(x)                   (((x) & RX_PRIORITY_OFFSET0_XCAST_RSSI_HIGH_MASK) >> RX_PRIORITY_OFFSET0_XCAST_RSSI_HIGH_LSB)
#define RX_PRIORITY_OFFSET0_XCAST_RSSI_HIGH_SET(x)                   (((0 | (x)) << RX_PRIORITY_OFFSET0_XCAST_RSSI_HIGH_LSB) & RX_PRIORITY_OFFSET0_XCAST_RSSI_HIGH_MASK)
#define RX_PRIORITY_OFFSET0_XCAST_RSSI_HIGH_RESET                    0
#define RX_PRIORITY_OFFSET0_RSSI_LOW_MSB                             23
#define RX_PRIORITY_OFFSET0_RSSI_LOW_LSB                             18
#define RX_PRIORITY_OFFSET0_RSSI_LOW_MASK                            0x00fc0000
#define RX_PRIORITY_OFFSET0_RSSI_LOW_GET(x)                          (((x) & RX_PRIORITY_OFFSET0_RSSI_LOW_MASK) >> RX_PRIORITY_OFFSET0_RSSI_LOW_LSB)
#define RX_PRIORITY_OFFSET0_RSSI_LOW_SET(x)                          (((0 | (x)) << RX_PRIORITY_OFFSET0_RSSI_LOW_LSB) & RX_PRIORITY_OFFSET0_RSSI_LOW_MASK)
#define RX_PRIORITY_OFFSET0_RSSI_LOW_RESET                           0
#define RX_PRIORITY_OFFSET0_RSSI_HIGH_MSB                            17
#define RX_PRIORITY_OFFSET0_RSSI_HIGH_LSB                            12
#define RX_PRIORITY_OFFSET0_RSSI_HIGH_MASK                           0x0003f000
#define RX_PRIORITY_OFFSET0_RSSI_HIGH_GET(x)                         (((x) & RX_PRIORITY_OFFSET0_RSSI_HIGH_MASK) >> RX_PRIORITY_OFFSET0_RSSI_HIGH_LSB)
#define RX_PRIORITY_OFFSET0_RSSI_HIGH_SET(x)                         (((0 | (x)) << RX_PRIORITY_OFFSET0_RSSI_HIGH_LSB) & RX_PRIORITY_OFFSET0_RSSI_HIGH_MASK)
#define RX_PRIORITY_OFFSET0_RSSI_HIGH_RESET                          0
#define RX_PRIORITY_OFFSET0_PHY_RATE_LOW_MSB                         11
#define RX_PRIORITY_OFFSET0_PHY_RATE_LOW_LSB                         6
#define RX_PRIORITY_OFFSET0_PHY_RATE_LOW_MASK                        0x00000fc0
#define RX_PRIORITY_OFFSET0_PHY_RATE_LOW_GET(x)                      (((x) & RX_PRIORITY_OFFSET0_PHY_RATE_LOW_MASK) >> RX_PRIORITY_OFFSET0_PHY_RATE_LOW_LSB)
#define RX_PRIORITY_OFFSET0_PHY_RATE_LOW_SET(x)                      (((0 | (x)) << RX_PRIORITY_OFFSET0_PHY_RATE_LOW_LSB) & RX_PRIORITY_OFFSET0_PHY_RATE_LOW_MASK)
#define RX_PRIORITY_OFFSET0_PHY_RATE_LOW_RESET                       0
#define RX_PRIORITY_OFFSET0_PHY_RATE_HIGH_MSB                        5
#define RX_PRIORITY_OFFSET0_PHY_RATE_HIGH_LSB                        0
#define RX_PRIORITY_OFFSET0_PHY_RATE_HIGH_MASK                       0x0000003f
#define RX_PRIORITY_OFFSET0_PHY_RATE_HIGH_GET(x)                     (((x) & RX_PRIORITY_OFFSET0_PHY_RATE_HIGH_MASK) >> RX_PRIORITY_OFFSET0_PHY_RATE_HIGH_LSB)
#define RX_PRIORITY_OFFSET0_PHY_RATE_HIGH_SET(x)                     (((0 | (x)) << RX_PRIORITY_OFFSET0_PHY_RATE_HIGH_LSB) & RX_PRIORITY_OFFSET0_PHY_RATE_HIGH_MASK)
#define RX_PRIORITY_OFFSET0_PHY_RATE_HIGH_RESET                      0
#define RX_PRIORITY_OFFSET0_ADDRESS                                  0x864c
#define RX_PRIORITY_OFFSET0_HW_MASK                                  0x3fffffff
#define RX_PRIORITY_OFFSET0_SW_MASK                                  0x3fffffff
#define RX_PRIORITY_OFFSET0_HW_WRITE_MASK                            0x00000000
#define RX_PRIORITY_OFFSET0_SW_WRITE_MASK                            0x3fffffff
#define RX_PRIORITY_OFFSET0_RSTMASK                                  0xffffffff
#define RX_PRIORITY_OFFSET0_RESET                                    0x00000000

// 0x8650 (RX_PRIORITY_OFFSET1)
#define RX_PRIORITY_OFFSET1_RTS_MSB                                  29
#define RX_PRIORITY_OFFSET1_RTS_LSB                                  24
#define RX_PRIORITY_OFFSET1_RTS_MASK                                 0x3f000000
#define RX_PRIORITY_OFFSET1_RTS_GET(x)                               (((x) & RX_PRIORITY_OFFSET1_RTS_MASK) >> RX_PRIORITY_OFFSET1_RTS_LSB)
#define RX_PRIORITY_OFFSET1_RTS_SET(x)                               (((0 | (x)) << RX_PRIORITY_OFFSET1_RTS_LSB) & RX_PRIORITY_OFFSET1_RTS_MASK)
#define RX_PRIORITY_OFFSET1_RTS_RESET                                0
#define RX_PRIORITY_OFFSET1_RETX_MSB                                 23
#define RX_PRIORITY_OFFSET1_RETX_LSB                                 18
#define RX_PRIORITY_OFFSET1_RETX_MASK                                0x00fc0000
#define RX_PRIORITY_OFFSET1_RETX_GET(x)                              (((x) & RX_PRIORITY_OFFSET1_RETX_MASK) >> RX_PRIORITY_OFFSET1_RETX_LSB)
#define RX_PRIORITY_OFFSET1_RETX_SET(x)                              (((0 | (x)) << RX_PRIORITY_OFFSET1_RETX_LSB) & RX_PRIORITY_OFFSET1_RETX_MASK)
#define RX_PRIORITY_OFFSET1_RETX_RESET                               0
#define RX_PRIORITY_OFFSET1_PRESP_RSSI_HIGH_MSB                      17
#define RX_PRIORITY_OFFSET1_PRESP_RSSI_HIGH_LSB                      12
#define RX_PRIORITY_OFFSET1_PRESP_RSSI_HIGH_MASK                     0x0003f000
#define RX_PRIORITY_OFFSET1_PRESP_RSSI_HIGH_GET(x)                   (((x) & RX_PRIORITY_OFFSET1_PRESP_RSSI_HIGH_MASK) >> RX_PRIORITY_OFFSET1_PRESP_RSSI_HIGH_LSB)
#define RX_PRIORITY_OFFSET1_PRESP_RSSI_HIGH_SET(x)                   (((0 | (x)) << RX_PRIORITY_OFFSET1_PRESP_RSSI_HIGH_LSB) & RX_PRIORITY_OFFSET1_PRESP_RSSI_HIGH_MASK)
#define RX_PRIORITY_OFFSET1_PRESP_RSSI_HIGH_RESET                    0
#define RX_PRIORITY_OFFSET1_LENGTH_LOW_MSB                           11
#define RX_PRIORITY_OFFSET1_LENGTH_LOW_LSB                           6
#define RX_PRIORITY_OFFSET1_LENGTH_LOW_MASK                          0x00000fc0
#define RX_PRIORITY_OFFSET1_LENGTH_LOW_GET(x)                        (((x) & RX_PRIORITY_OFFSET1_LENGTH_LOW_MASK) >> RX_PRIORITY_OFFSET1_LENGTH_LOW_LSB)
#define RX_PRIORITY_OFFSET1_LENGTH_LOW_SET(x)                        (((0 | (x)) << RX_PRIORITY_OFFSET1_LENGTH_LOW_LSB) & RX_PRIORITY_OFFSET1_LENGTH_LOW_MASK)
#define RX_PRIORITY_OFFSET1_LENGTH_LOW_RESET                         0
#define RX_PRIORITY_OFFSET1_LENGTH_HIGH_MSB                          5
#define RX_PRIORITY_OFFSET1_LENGTH_HIGH_LSB                          0
#define RX_PRIORITY_OFFSET1_LENGTH_HIGH_MASK                         0x0000003f
#define RX_PRIORITY_OFFSET1_LENGTH_HIGH_GET(x)                       (((x) & RX_PRIORITY_OFFSET1_LENGTH_HIGH_MASK) >> RX_PRIORITY_OFFSET1_LENGTH_HIGH_LSB)
#define RX_PRIORITY_OFFSET1_LENGTH_HIGH_SET(x)                       (((0 | (x)) << RX_PRIORITY_OFFSET1_LENGTH_HIGH_LSB) & RX_PRIORITY_OFFSET1_LENGTH_HIGH_MASK)
#define RX_PRIORITY_OFFSET1_LENGTH_HIGH_RESET                        0
#define RX_PRIORITY_OFFSET1_ADDRESS                                  0x8650
#define RX_PRIORITY_OFFSET1_HW_MASK                                  0x3fffffff
#define RX_PRIORITY_OFFSET1_SW_MASK                                  0x3fffffff
#define RX_PRIORITY_OFFSET1_HW_WRITE_MASK                            0x00000000
#define RX_PRIORITY_OFFSET1_SW_WRITE_MASK                            0x3fffffff
#define RX_PRIORITY_OFFSET1_RSTMASK                                  0xffffffff
#define RX_PRIORITY_OFFSET1_RESET                                    0x00000000

// 0x8654 (RX_PRIORITY_OFFSET2)
#define RX_PRIORITY_OFFSET2_BEACON_MSB                               29
#define RX_PRIORITY_OFFSET2_BEACON_LSB                               24
#define RX_PRIORITY_OFFSET2_BEACON_MASK                              0x3f000000
#define RX_PRIORITY_OFFSET2_BEACON_GET(x)                            (((x) & RX_PRIORITY_OFFSET2_BEACON_MASK) >> RX_PRIORITY_OFFSET2_BEACON_LSB)
#define RX_PRIORITY_OFFSET2_BEACON_SET(x)                            (((0 | (x)) << RX_PRIORITY_OFFSET2_BEACON_LSB) & RX_PRIORITY_OFFSET2_BEACON_MASK)
#define RX_PRIORITY_OFFSET2_BEACON_RESET                             0
#define RX_PRIORITY_OFFSET2_MGMT_MSB                                 23
#define RX_PRIORITY_OFFSET2_MGMT_LSB                                 18
#define RX_PRIORITY_OFFSET2_MGMT_MASK                                0x00fc0000
#define RX_PRIORITY_OFFSET2_MGMT_GET(x)                              (((x) & RX_PRIORITY_OFFSET2_MGMT_MASK) >> RX_PRIORITY_OFFSET2_MGMT_LSB)
#define RX_PRIORITY_OFFSET2_MGMT_SET(x)                              (((0 | (x)) << RX_PRIORITY_OFFSET2_MGMT_LSB) & RX_PRIORITY_OFFSET2_MGMT_MASK)
#define RX_PRIORITY_OFFSET2_MGMT_RESET                               0
#define RX_PRIORITY_OFFSET2_ATIM_MSB                                 17
#define RX_PRIORITY_OFFSET2_ATIM_LSB                                 12
#define RX_PRIORITY_OFFSET2_ATIM_MASK                                0x0003f000
#define RX_PRIORITY_OFFSET2_ATIM_GET(x)                              (((x) & RX_PRIORITY_OFFSET2_ATIM_MASK) >> RX_PRIORITY_OFFSET2_ATIM_LSB)
#define RX_PRIORITY_OFFSET2_ATIM_SET(x)                              (((0 | (x)) << RX_PRIORITY_OFFSET2_ATIM_LSB) & RX_PRIORITY_OFFSET2_ATIM_MASK)
#define RX_PRIORITY_OFFSET2_ATIM_RESET                               0
#define RX_PRIORITY_OFFSET2_PRESP_MSB                                11
#define RX_PRIORITY_OFFSET2_PRESP_LSB                                6
#define RX_PRIORITY_OFFSET2_PRESP_MASK                               0x00000fc0
#define RX_PRIORITY_OFFSET2_PRESP_GET(x)                             (((x) & RX_PRIORITY_OFFSET2_PRESP_MASK) >> RX_PRIORITY_OFFSET2_PRESP_LSB)
#define RX_PRIORITY_OFFSET2_PRESP_SET(x)                             (((0 | (x)) << RX_PRIORITY_OFFSET2_PRESP_LSB) & RX_PRIORITY_OFFSET2_PRESP_MASK)
#define RX_PRIORITY_OFFSET2_PRESP_RESET                              0
#define RX_PRIORITY_OFFSET2_XCAST_MSB                                5
#define RX_PRIORITY_OFFSET2_XCAST_LSB                                0
#define RX_PRIORITY_OFFSET2_XCAST_MASK                               0x0000003f
#define RX_PRIORITY_OFFSET2_XCAST_GET(x)                             (((x) & RX_PRIORITY_OFFSET2_XCAST_MASK) >> RX_PRIORITY_OFFSET2_XCAST_LSB)
#define RX_PRIORITY_OFFSET2_XCAST_SET(x)                             (((0 | (x)) << RX_PRIORITY_OFFSET2_XCAST_LSB) & RX_PRIORITY_OFFSET2_XCAST_MASK)
#define RX_PRIORITY_OFFSET2_XCAST_RESET                              0
#define RX_PRIORITY_OFFSET2_ADDRESS                                  0x8654
#define RX_PRIORITY_OFFSET2_HW_MASK                                  0x3fffffff
#define RX_PRIORITY_OFFSET2_SW_MASK                                  0x3fffffff
#define RX_PRIORITY_OFFSET2_HW_WRITE_MASK                            0x00000000
#define RX_PRIORITY_OFFSET2_SW_WRITE_MASK                            0x3fffffff
#define RX_PRIORITY_OFFSET2_RSTMASK                                  0xffffffff
#define RX_PRIORITY_OFFSET2_RESET                                    0x00000000

// 0x8658 (RX_PRIORITY_OFFSET3)
#define RX_PRIORITY_OFFSET3_PS_POLL_MSB                              29
#define RX_PRIORITY_OFFSET3_PS_POLL_LSB                              24
#define RX_PRIORITY_OFFSET3_PS_POLL_MASK                             0x3f000000
#define RX_PRIORITY_OFFSET3_PS_POLL_GET(x)                           (((x) & RX_PRIORITY_OFFSET3_PS_POLL_MASK) >> RX_PRIORITY_OFFSET3_PS_POLL_LSB)
#define RX_PRIORITY_OFFSET3_PS_POLL_SET(x)                           (((0 | (x)) << RX_PRIORITY_OFFSET3_PS_POLL_LSB) & RX_PRIORITY_OFFSET3_PS_POLL_MASK)
#define RX_PRIORITY_OFFSET3_PS_POLL_RESET                            0
#define RX_PRIORITY_OFFSET3_AMSDU_MSB                                23
#define RX_PRIORITY_OFFSET3_AMSDU_LSB                                18
#define RX_PRIORITY_OFFSET3_AMSDU_MASK                               0x00fc0000
#define RX_PRIORITY_OFFSET3_AMSDU_GET(x)                             (((x) & RX_PRIORITY_OFFSET3_AMSDU_MASK) >> RX_PRIORITY_OFFSET3_AMSDU_LSB)
#define RX_PRIORITY_OFFSET3_AMSDU_SET(x)                             (((0 | (x)) << RX_PRIORITY_OFFSET3_AMSDU_LSB) & RX_PRIORITY_OFFSET3_AMSDU_MASK)
#define RX_PRIORITY_OFFSET3_AMSDU_RESET                              0
#define RX_PRIORITY_OFFSET3_AMPDU_MSB                                17
#define RX_PRIORITY_OFFSET3_AMPDU_LSB                                12
#define RX_PRIORITY_OFFSET3_AMPDU_MASK                               0x0003f000
#define RX_PRIORITY_OFFSET3_AMPDU_GET(x)                             (((x) & RX_PRIORITY_OFFSET3_AMPDU_MASK) >> RX_PRIORITY_OFFSET3_AMPDU_LSB)
#define RX_PRIORITY_OFFSET3_AMPDU_SET(x)                             (((0 | (x)) << RX_PRIORITY_OFFSET3_AMPDU_LSB) & RX_PRIORITY_OFFSET3_AMPDU_MASK)
#define RX_PRIORITY_OFFSET3_AMPDU_RESET                              0
#define RX_PRIORITY_OFFSET3_EOSP_MSB                                 11
#define RX_PRIORITY_OFFSET3_EOSP_LSB                                 6
#define RX_PRIORITY_OFFSET3_EOSP_MASK                                0x00000fc0
#define RX_PRIORITY_OFFSET3_EOSP_GET(x)                              (((x) & RX_PRIORITY_OFFSET3_EOSP_MASK) >> RX_PRIORITY_OFFSET3_EOSP_LSB)
#define RX_PRIORITY_OFFSET3_EOSP_SET(x)                              (((0 | (x)) << RX_PRIORITY_OFFSET3_EOSP_LSB) & RX_PRIORITY_OFFSET3_EOSP_MASK)
#define RX_PRIORITY_OFFSET3_EOSP_RESET                               0
#define RX_PRIORITY_OFFSET3_MORE_MSB                                 5
#define RX_PRIORITY_OFFSET3_MORE_LSB                                 0
#define RX_PRIORITY_OFFSET3_MORE_MASK                                0x0000003f
#define RX_PRIORITY_OFFSET3_MORE_GET(x)                              (((x) & RX_PRIORITY_OFFSET3_MORE_MASK) >> RX_PRIORITY_OFFSET3_MORE_LSB)
#define RX_PRIORITY_OFFSET3_MORE_SET(x)                              (((0 | (x)) << RX_PRIORITY_OFFSET3_MORE_LSB) & RX_PRIORITY_OFFSET3_MORE_MASK)
#define RX_PRIORITY_OFFSET3_MORE_RESET                               0
#define RX_PRIORITY_OFFSET3_ADDRESS                                  0x8658
#define RX_PRIORITY_OFFSET3_HW_MASK                                  0x3fffffff
#define RX_PRIORITY_OFFSET3_SW_MASK                                  0x3fffffff
#define RX_PRIORITY_OFFSET3_HW_WRITE_MASK                            0x00000000
#define RX_PRIORITY_OFFSET3_SW_WRITE_MASK                            0x3fffffff
#define RX_PRIORITY_OFFSET3_RSTMASK                                  0xffffffff
#define RX_PRIORITY_OFFSET3_RESET                                    0x00000000

// 0x865c (RX_PRIORITY_OFFSET4)
#define RX_PRIORITY_OFFSET4_BEACON_RSSI_HIGH_MSB                     29
#define RX_PRIORITY_OFFSET4_BEACON_RSSI_HIGH_LSB                     24
#define RX_PRIORITY_OFFSET4_BEACON_RSSI_HIGH_MASK                    0x3f000000
#define RX_PRIORITY_OFFSET4_BEACON_RSSI_HIGH_GET(x)                  (((x) & RX_PRIORITY_OFFSET4_BEACON_RSSI_HIGH_MASK) >> RX_PRIORITY_OFFSET4_BEACON_RSSI_HIGH_LSB)
#define RX_PRIORITY_OFFSET4_BEACON_RSSI_HIGH_SET(x)                  (((0 | (x)) << RX_PRIORITY_OFFSET4_BEACON_RSSI_HIGH_LSB) & RX_PRIORITY_OFFSET4_BEACON_RSSI_HIGH_MASK)
#define RX_PRIORITY_OFFSET4_BEACON_RSSI_HIGH_RESET                   0
#define RX_PRIORITY_OFFSET4_MGMT_RSSI_HIGH_MSB                       23
#define RX_PRIORITY_OFFSET4_MGMT_RSSI_HIGH_LSB                       18
#define RX_PRIORITY_OFFSET4_MGMT_RSSI_HIGH_MASK                      0x00fc0000
#define RX_PRIORITY_OFFSET4_MGMT_RSSI_HIGH_GET(x)                    (((x) & RX_PRIORITY_OFFSET4_MGMT_RSSI_HIGH_MASK) >> RX_PRIORITY_OFFSET4_MGMT_RSSI_HIGH_LSB)
#define RX_PRIORITY_OFFSET4_MGMT_RSSI_HIGH_SET(x)                    (((0 | (x)) << RX_PRIORITY_OFFSET4_MGMT_RSSI_HIGH_LSB) & RX_PRIORITY_OFFSET4_MGMT_RSSI_HIGH_MASK)
#define RX_PRIORITY_OFFSET4_MGMT_RSSI_HIGH_RESET                     0
#define RX_PRIORITY_OFFSET4_BEACON_SSID_MSB                          17
#define RX_PRIORITY_OFFSET4_BEACON_SSID_LSB                          12
#define RX_PRIORITY_OFFSET4_BEACON_SSID_MASK                         0x0003f000
#define RX_PRIORITY_OFFSET4_BEACON_SSID_GET(x)                       (((x) & RX_PRIORITY_OFFSET4_BEACON_SSID_MASK) >> RX_PRIORITY_OFFSET4_BEACON_SSID_LSB)
#define RX_PRIORITY_OFFSET4_BEACON_SSID_SET(x)                       (((0 | (x)) << RX_PRIORITY_OFFSET4_BEACON_SSID_LSB) & RX_PRIORITY_OFFSET4_BEACON_SSID_MASK)
#define RX_PRIORITY_OFFSET4_BEACON_SSID_RESET                        0
#define RX_PRIORITY_OFFSET4_NULL_MSB                                 11
#define RX_PRIORITY_OFFSET4_NULL_LSB                                 6
#define RX_PRIORITY_OFFSET4_NULL_MASK                                0x00000fc0
#define RX_PRIORITY_OFFSET4_NULL_GET(x)                              (((x) & RX_PRIORITY_OFFSET4_NULL_MASK) >> RX_PRIORITY_OFFSET4_NULL_LSB)
#define RX_PRIORITY_OFFSET4_NULL_SET(x)                              (((0 | (x)) << RX_PRIORITY_OFFSET4_NULL_LSB) & RX_PRIORITY_OFFSET4_NULL_MASK)
#define RX_PRIORITY_OFFSET4_NULL_RESET                               0
#define RX_PRIORITY_OFFSET4_PREQ_MSB                                 5
#define RX_PRIORITY_OFFSET4_PREQ_LSB                                 0
#define RX_PRIORITY_OFFSET4_PREQ_MASK                                0x0000003f
#define RX_PRIORITY_OFFSET4_PREQ_GET(x)                              (((x) & RX_PRIORITY_OFFSET4_PREQ_MASK) >> RX_PRIORITY_OFFSET4_PREQ_LSB)
#define RX_PRIORITY_OFFSET4_PREQ_SET(x)                              (((0 | (x)) << RX_PRIORITY_OFFSET4_PREQ_LSB) & RX_PRIORITY_OFFSET4_PREQ_MASK)
#define RX_PRIORITY_OFFSET4_PREQ_RESET                               0
#define RX_PRIORITY_OFFSET4_ADDRESS                                  0x865c
#define RX_PRIORITY_OFFSET4_HW_MASK                                  0x3fffffff
#define RX_PRIORITY_OFFSET4_SW_MASK                                  0x3fffffff
#define RX_PRIORITY_OFFSET4_HW_WRITE_MASK                            0x00000000
#define RX_PRIORITY_OFFSET4_SW_WRITE_MASK                            0x3fffffff
#define RX_PRIORITY_OFFSET4_RSTMASK                                  0xffffffff
#define RX_PRIORITY_OFFSET4_RESET                                    0x00000000

// 0x8660 (RX_PRIORITY_OFFSET5)
#define RX_PRIORITY_OFFSET5_PS_POLL_RSSI_HIGH_MSB                    17
#define RX_PRIORITY_OFFSET5_PS_POLL_RSSI_HIGH_LSB                    12
#define RX_PRIORITY_OFFSET5_PS_POLL_RSSI_HIGH_MASK                   0x0003f000
#define RX_PRIORITY_OFFSET5_PS_POLL_RSSI_HIGH_GET(x)                 (((x) & RX_PRIORITY_OFFSET5_PS_POLL_RSSI_HIGH_MASK) >> RX_PRIORITY_OFFSET5_PS_POLL_RSSI_HIGH_LSB)
#define RX_PRIORITY_OFFSET5_PS_POLL_RSSI_HIGH_SET(x)                 (((0 | (x)) << RX_PRIORITY_OFFSET5_PS_POLL_RSSI_HIGH_LSB) & RX_PRIORITY_OFFSET5_PS_POLL_RSSI_HIGH_MASK)
#define RX_PRIORITY_OFFSET5_PS_POLL_RSSI_HIGH_RESET                  0
#define RX_PRIORITY_OFFSET5_PREQ_RSSI_HIGH_MSB                       11
#define RX_PRIORITY_OFFSET5_PREQ_RSSI_HIGH_LSB                       6
#define RX_PRIORITY_OFFSET5_PREQ_RSSI_HIGH_MASK                      0x00000fc0
#define RX_PRIORITY_OFFSET5_PREQ_RSSI_HIGH_GET(x)                    (((x) & RX_PRIORITY_OFFSET5_PREQ_RSSI_HIGH_MASK) >> RX_PRIORITY_OFFSET5_PREQ_RSSI_HIGH_LSB)
#define RX_PRIORITY_OFFSET5_PREQ_RSSI_HIGH_SET(x)                    (((0 | (x)) << RX_PRIORITY_OFFSET5_PREQ_RSSI_HIGH_LSB) & RX_PRIORITY_OFFSET5_PREQ_RSSI_HIGH_MASK)
#define RX_PRIORITY_OFFSET5_PREQ_RSSI_HIGH_RESET                     0
#define RX_PRIORITY_OFFSET5_NULL_RSSI_HIGH_MSB                       5
#define RX_PRIORITY_OFFSET5_NULL_RSSI_HIGH_LSB                       0
#define RX_PRIORITY_OFFSET5_NULL_RSSI_HIGH_MASK                      0x0000003f
#define RX_PRIORITY_OFFSET5_NULL_RSSI_HIGH_GET(x)                    (((x) & RX_PRIORITY_OFFSET5_NULL_RSSI_HIGH_MASK) >> RX_PRIORITY_OFFSET5_NULL_RSSI_HIGH_LSB)
#define RX_PRIORITY_OFFSET5_NULL_RSSI_HIGH_SET(x)                    (((0 | (x)) << RX_PRIORITY_OFFSET5_NULL_RSSI_HIGH_LSB) & RX_PRIORITY_OFFSET5_NULL_RSSI_HIGH_MASK)
#define RX_PRIORITY_OFFSET5_NULL_RSSI_HIGH_RESET                     0
#define RX_PRIORITY_OFFSET5_ADDRESS                                  0x8660
#define RX_PRIORITY_OFFSET5_HW_MASK                                  0x0003ffff
#define RX_PRIORITY_OFFSET5_SW_MASK                                  0x0003ffff
#define RX_PRIORITY_OFFSET5_HW_WRITE_MASK                            0x00000000
#define RX_PRIORITY_OFFSET5_SW_WRITE_MASK                            0x0003ffff
#define RX_PRIORITY_OFFSET5_RSTMASK                                  0xffffffff
#define RX_PRIORITY_OFFSET5_RESET                                    0x00000000

// 0x8664 (MAC_PCU_LAST_BEACON2_TSF)
#define MAC_PCU_LAST_BEACON2_TSF_VALUE_MSB                           31
#define MAC_PCU_LAST_BEACON2_TSF_VALUE_LSB                           0
#define MAC_PCU_LAST_BEACON2_TSF_VALUE_MASK                          0xffffffff
#define MAC_PCU_LAST_BEACON2_TSF_VALUE_GET(x)                        (((x) & MAC_PCU_LAST_BEACON2_TSF_VALUE_MASK) >> MAC_PCU_LAST_BEACON2_TSF_VALUE_LSB)
#define MAC_PCU_LAST_BEACON2_TSF_VALUE_SET(x)                        (((0 | (x)) << MAC_PCU_LAST_BEACON2_TSF_VALUE_LSB) & MAC_PCU_LAST_BEACON2_TSF_VALUE_MASK)
#define MAC_PCU_LAST_BEACON2_TSF_VALUE_RESET                         0
#define MAC_PCU_LAST_BEACON2_TSF_ADDRESS                             0x8664
#define MAC_PCU_LAST_BEACON2_TSF_HW_MASK                             0xffffffff
#define MAC_PCU_LAST_BEACON2_TSF_SW_MASK                             0xffffffff
#define MAC_PCU_LAST_BEACON2_TSF_HW_WRITE_MASK                       0xffffffff
#define MAC_PCU_LAST_BEACON2_TSF_SW_WRITE_MASK                       0x00000000
#define MAC_PCU_LAST_BEACON2_TSF_RSTMASK                             0xffffffff
#define MAC_PCU_LAST_BEACON2_TSF_RESET                               0x00000000

// 0x8668 (MAC_PCU_PHY_ERROR_AIFS)
#define MAC_PCU_PHY_ERROR_AIFS_MASK_ENABLE_MSB                       0
#define MAC_PCU_PHY_ERROR_AIFS_MASK_ENABLE_LSB                       0
#define MAC_PCU_PHY_ERROR_AIFS_MASK_ENABLE_MASK                      0x00000001
#define MAC_PCU_PHY_ERROR_AIFS_MASK_ENABLE_GET(x)                    (((x) & MAC_PCU_PHY_ERROR_AIFS_MASK_ENABLE_MASK) >> MAC_PCU_PHY_ERROR_AIFS_MASK_ENABLE_LSB)
#define MAC_PCU_PHY_ERROR_AIFS_MASK_ENABLE_SET(x)                    (((0 | (x)) << MAC_PCU_PHY_ERROR_AIFS_MASK_ENABLE_LSB) & MAC_PCU_PHY_ERROR_AIFS_MASK_ENABLE_MASK)
#define MAC_PCU_PHY_ERROR_AIFS_MASK_ENABLE_RESET                     0
#define MAC_PCU_PHY_ERROR_AIFS_ADDRESS                               0x8668
#define MAC_PCU_PHY_ERROR_AIFS_HW_MASK                               0x00000001
#define MAC_PCU_PHY_ERROR_AIFS_SW_MASK                               0x00000001
#define MAC_PCU_PHY_ERROR_AIFS_HW_WRITE_MASK                         0x00000000
#define MAC_PCU_PHY_ERROR_AIFS_SW_WRITE_MASK                         0x00000001
#define MAC_PCU_PHY_ERROR_AIFS_RSTMASK                               0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_RESET                                 0x00000000

// 0x866c (MAC_PCU_PHY_ERROR_AIFS_MASK)
#define MAC_PCU_PHY_ERROR_AIFS_MASK_VALUE_MSB                        31
#define MAC_PCU_PHY_ERROR_AIFS_MASK_VALUE_LSB                        0
#define MAC_PCU_PHY_ERROR_AIFS_MASK_VALUE_MASK                       0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_MASK_VALUE_GET(x)                     (((x) & MAC_PCU_PHY_ERROR_AIFS_MASK_VALUE_MASK) >> MAC_PCU_PHY_ERROR_AIFS_MASK_VALUE_LSB)
#define MAC_PCU_PHY_ERROR_AIFS_MASK_VALUE_SET(x)                     (((0 | (x)) << MAC_PCU_PHY_ERROR_AIFS_MASK_VALUE_LSB) & MAC_PCU_PHY_ERROR_AIFS_MASK_VALUE_MASK)
#define MAC_PCU_PHY_ERROR_AIFS_MASK_VALUE_RESET                      0
#define MAC_PCU_PHY_ERROR_AIFS_MASK_ADDRESS                          0x866c
#define MAC_PCU_PHY_ERROR_AIFS_MASK_HW_MASK                          0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_MASK_SW_MASK                          0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_MASK_HW_WRITE_MASK                    0x00000000
#define MAC_PCU_PHY_ERROR_AIFS_MASK_SW_WRITE_MASK                    0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_MASK_RSTMASK                          0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_MASK_RESET                            0x00000000

// 0x8670 (MAC_PCU_FILTER_RSSI_AVE)
#define MAC_PCU_FILTER_RSSI_AVE_RESET_MSB                            12
#define MAC_PCU_FILTER_RSSI_AVE_RESET_LSB                            12
#define MAC_PCU_FILTER_RSSI_AVE_RESET_MASK                           0x00001000
#define MAC_PCU_FILTER_RSSI_AVE_RESET_GET(x)                         (((x) & MAC_PCU_FILTER_RSSI_AVE_RESET_MASK) >> MAC_PCU_FILTER_RSSI_AVE_RESET_LSB)
#define MAC_PCU_FILTER_RSSI_AVE_RESET_SET(x)                         (((0 | (x)) << MAC_PCU_FILTER_RSSI_AVE_RESET_LSB) & MAC_PCU_FILTER_RSSI_AVE_RESET_MASK)
#define MAC_PCU_FILTER_RSSI_AVE_RESET_RESET                          0
#define MAC_PCU_FILTER_RSSI_AVE_ENABLE_MSB                           11
#define MAC_PCU_FILTER_RSSI_AVE_ENABLE_LSB                           11
#define MAC_PCU_FILTER_RSSI_AVE_ENABLE_MASK                          0x00000800
#define MAC_PCU_FILTER_RSSI_AVE_ENABLE_GET(x)                        (((x) & MAC_PCU_FILTER_RSSI_AVE_ENABLE_MASK) >> MAC_PCU_FILTER_RSSI_AVE_ENABLE_LSB)
#define MAC_PCU_FILTER_RSSI_AVE_ENABLE_SET(x)                        (((0 | (x)) << MAC_PCU_FILTER_RSSI_AVE_ENABLE_LSB) & MAC_PCU_FILTER_RSSI_AVE_ENABLE_MASK)
#define MAC_PCU_FILTER_RSSI_AVE_ENABLE_RESET                         0
#define MAC_PCU_FILTER_RSSI_AVE_NUM_FRAMES_EXPONENT_MSB              10
#define MAC_PCU_FILTER_RSSI_AVE_NUM_FRAMES_EXPONENT_LSB              8
#define MAC_PCU_FILTER_RSSI_AVE_NUM_FRAMES_EXPONENT_MASK             0x00000700
#define MAC_PCU_FILTER_RSSI_AVE_NUM_FRAMES_EXPONENT_GET(x)           (((x) & MAC_PCU_FILTER_RSSI_AVE_NUM_FRAMES_EXPONENT_MASK) >> MAC_PCU_FILTER_RSSI_AVE_NUM_FRAMES_EXPONENT_LSB)
#define MAC_PCU_FILTER_RSSI_AVE_NUM_FRAMES_EXPONENT_SET(x)           (((0 | (x)) << MAC_PCU_FILTER_RSSI_AVE_NUM_FRAMES_EXPONENT_LSB) & MAC_PCU_FILTER_RSSI_AVE_NUM_FRAMES_EXPONENT_MASK)
#define MAC_PCU_FILTER_RSSI_AVE_NUM_FRAMES_EXPONENT_RESET            5
#define MAC_PCU_FILTER_RSSI_AVE_AVE_VALUE_MSB                        7
#define MAC_PCU_FILTER_RSSI_AVE_AVE_VALUE_LSB                        0
#define MAC_PCU_FILTER_RSSI_AVE_AVE_VALUE_MASK                       0x000000ff
#define MAC_PCU_FILTER_RSSI_AVE_AVE_VALUE_GET(x)                     (((x) & MAC_PCU_FILTER_RSSI_AVE_AVE_VALUE_MASK) >> MAC_PCU_FILTER_RSSI_AVE_AVE_VALUE_LSB)
#define MAC_PCU_FILTER_RSSI_AVE_AVE_VALUE_SET(x)                     (((0 | (x)) << MAC_PCU_FILTER_RSSI_AVE_AVE_VALUE_LSB) & MAC_PCU_FILTER_RSSI_AVE_AVE_VALUE_MASK)
#define MAC_PCU_FILTER_RSSI_AVE_AVE_VALUE_RESET                      128
#define MAC_PCU_FILTER_RSSI_AVE_ADDRESS                              0x8670
#define MAC_PCU_FILTER_RSSI_AVE_HW_MASK                              0x00001fff
#define MAC_PCU_FILTER_RSSI_AVE_SW_MASK                              0x00001fff
#define MAC_PCU_FILTER_RSSI_AVE_HW_WRITE_MASK                        0x000010ff
#define MAC_PCU_FILTER_RSSI_AVE_SW_WRITE_MASK                        0x00001fff
#define MAC_PCU_FILTER_RSSI_AVE_RSTMASK                              0xffffffff
#define MAC_PCU_FILTER_RSSI_AVE_RESET                                0x00000580

// 0x8674 (MAC_PCU_TBD_FILTER)
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_RX_TS_MSB                     1
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_RX_TS_LSB                     1
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_RX_TS_MASK                    0x00000002
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_RX_TS_GET(x)                  (((x) & MAC_PCU_TBD_FILTER_USE_WBTIMER_RX_TS_MASK) >> MAC_PCU_TBD_FILTER_USE_WBTIMER_RX_TS_LSB)
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_RX_TS_SET(x)                  (((0 | (x)) << MAC_PCU_TBD_FILTER_USE_WBTIMER_RX_TS_LSB) & MAC_PCU_TBD_FILTER_USE_WBTIMER_RX_TS_MASK)
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_RX_TS_RESET                   0
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_TX_TS_MSB                     0
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_TX_TS_LSB                     0
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_TX_TS_MASK                    0x00000001
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_TX_TS_GET(x)                  (((x) & MAC_PCU_TBD_FILTER_USE_WBTIMER_TX_TS_MASK) >> MAC_PCU_TBD_FILTER_USE_WBTIMER_TX_TS_LSB)
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_TX_TS_SET(x)                  (((0 | (x)) << MAC_PCU_TBD_FILTER_USE_WBTIMER_TX_TS_LSB) & MAC_PCU_TBD_FILTER_USE_WBTIMER_TX_TS_MASK)
#define MAC_PCU_TBD_FILTER_USE_WBTIMER_TX_TS_RESET                   0
#define MAC_PCU_TBD_FILTER_ADDRESS                                   0x8674
#define MAC_PCU_TBD_FILTER_HW_MASK                                   0x00000003
#define MAC_PCU_TBD_FILTER_SW_MASK                                   0x00000003
#define MAC_PCU_TBD_FILTER_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_TBD_FILTER_SW_WRITE_MASK                             0x00000003
#define MAC_PCU_TBD_FILTER_RSTMASK                                   0xffffffff
#define MAC_PCU_TBD_FILTER_RESET                                     0x00000000

// 0x8678 (MAC_PCU_BT_ANT_SLEEP_EXTEND)
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_CNT_MSB                          15
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_CNT_LSB                          0
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_CNT_MASK                         0x0000ffff
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_CNT_GET(x)                       (((x) & MAC_PCU_BT_ANT_SLEEP_EXTEND_CNT_MASK) >> MAC_PCU_BT_ANT_SLEEP_EXTEND_CNT_LSB)
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_CNT_SET(x)                       (((0 | (x)) << MAC_PCU_BT_ANT_SLEEP_EXTEND_CNT_LSB) & MAC_PCU_BT_ANT_SLEEP_EXTEND_CNT_MASK)
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_CNT_RESET                        0
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_ADDRESS                          0x8678
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_HW_MASK                          0x0000ffff
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_SW_MASK                          0x0000ffff
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_HW_WRITE_MASK                    0x00000000
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_SW_WRITE_MASK                    0x0000ffff
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_RSTMASK                          0xffffffff
#define MAC_PCU_BT_ANT_SLEEP_EXTEND_RESET                            0x00000000

// 0x867c (MAC_ASE_AST_BASE_ADDR)
#define MAC_ASE_AST_BASE_ADDR_VALUE_MSB                              31
#define MAC_ASE_AST_BASE_ADDR_VALUE_LSB                              0
#define MAC_ASE_AST_BASE_ADDR_VALUE_MASK                             0xffffffff
#define MAC_ASE_AST_BASE_ADDR_VALUE_GET(x)                           (((x) & MAC_ASE_AST_BASE_ADDR_VALUE_MASK) >> MAC_ASE_AST_BASE_ADDR_VALUE_LSB)
#define MAC_ASE_AST_BASE_ADDR_VALUE_SET(x)                           (((0 | (x)) << MAC_ASE_AST_BASE_ADDR_VALUE_LSB) & MAC_ASE_AST_BASE_ADDR_VALUE_MASK)
#define MAC_ASE_AST_BASE_ADDR_VALUE_RESET                            0
#define MAC_ASE_AST_BASE_ADDR_ADDRESS                                0x867c
#define MAC_ASE_AST_BASE_ADDR_HW_MASK                                0xffffffff
#define MAC_ASE_AST_BASE_ADDR_SW_MASK                                0xffffffff
#define MAC_ASE_AST_BASE_ADDR_HW_WRITE_MASK                          0x00000000
#define MAC_ASE_AST_BASE_ADDR_SW_WRITE_MASK                          0xffffffff
#define MAC_ASE_AST_BASE_ADDR_RSTMASK                                0xffffffff
#define MAC_ASE_AST_BASE_ADDR_RESET                                  0x00000000

// 0x8680 (MAC_ASE_AST_SIZE)
#define MAC_ASE_AST_SIZE_VALUE_MSB                                   12
#define MAC_ASE_AST_SIZE_VALUE_LSB                                   0
#define MAC_ASE_AST_SIZE_VALUE_MASK                                  0x00001fff
#define MAC_ASE_AST_SIZE_VALUE_GET(x)                                (((x) & MAC_ASE_AST_SIZE_VALUE_MASK) >> MAC_ASE_AST_SIZE_VALUE_LSB)
#define MAC_ASE_AST_SIZE_VALUE_SET(x)                                (((0 | (x)) << MAC_ASE_AST_SIZE_VALUE_LSB) & MAC_ASE_AST_SIZE_VALUE_MASK)
#define MAC_ASE_AST_SIZE_VALUE_RESET                                 0
#define MAC_ASE_AST_SIZE_ADDRESS                                     0x8680
#define MAC_ASE_AST_SIZE_HW_MASK                                     0x00001fff
#define MAC_ASE_AST_SIZE_SW_MASK                                     0x00001fff
#define MAC_ASE_AST_SIZE_HW_WRITE_MASK                               0x00000000
#define MAC_ASE_AST_SIZE_SW_WRITE_MASK                               0x00001fff
#define MAC_ASE_AST_SIZE_RSTMASK                                     0xffffffff
#define MAC_ASE_AST_SIZE_RESET                                       0x00000000

// 0x8684 (MAC_ASE_SEARCH_CTRL)
#define MAC_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MSB                       31
#define MAC_ASE_SEARCH_CTRL_TIMEOUT_THRESH_LSB                       16
#define MAC_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MASK                      0xffff0000
#define MAC_ASE_SEARCH_CTRL_TIMEOUT_THRESH_GET(x)                    (((x) & MAC_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MASK) >> MAC_ASE_SEARCH_CTRL_TIMEOUT_THRESH_LSB)
#define MAC_ASE_SEARCH_CTRL_TIMEOUT_THRESH_SET(x)                    (((0 | (x)) << MAC_ASE_SEARCH_CTRL_TIMEOUT_THRESH_LSB) & MAC_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MASK)
#define MAC_ASE_SEARCH_CTRL_TIMEOUT_THRESH_RESET                     0
#define MAC_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MSB                     8
#define MAC_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_LSB                     8
#define MAC_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MASK                    0x00000100
#define MAC_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_GET(x)                  (((x) & MAC_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MASK) >> MAC_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_LSB)
#define MAC_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_SET(x)                  (((0 | (x)) << MAC_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_LSB) & MAC_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MASK)
#define MAC_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_RESET                   0
#define MAC_ASE_SEARCH_CTRL_MAX_SEARCH_MSB                           7
#define MAC_ASE_SEARCH_CTRL_MAX_SEARCH_LSB                           0
#define MAC_ASE_SEARCH_CTRL_MAX_SEARCH_MASK                          0x000000ff
#define MAC_ASE_SEARCH_CTRL_MAX_SEARCH_GET(x)                        (((x) & MAC_ASE_SEARCH_CTRL_MAX_SEARCH_MASK) >> MAC_ASE_SEARCH_CTRL_MAX_SEARCH_LSB)
#define MAC_ASE_SEARCH_CTRL_MAX_SEARCH_SET(x)                        (((0 | (x)) << MAC_ASE_SEARCH_CTRL_MAX_SEARCH_LSB) & MAC_ASE_SEARCH_CTRL_MAX_SEARCH_MASK)
#define MAC_ASE_SEARCH_CTRL_MAX_SEARCH_RESET                         0
#define MAC_ASE_SEARCH_CTRL_ADDRESS                                  0x8684
#define MAC_ASE_SEARCH_CTRL_HW_MASK                                  0xffff01ff
#define MAC_ASE_SEARCH_CTRL_SW_MASK                                  0xffff01ff
#define MAC_ASE_SEARCH_CTRL_HW_WRITE_MASK                            0x00000000
#define MAC_ASE_SEARCH_CTRL_SW_WRITE_MASK                            0xffff01ff
#define MAC_ASE_SEARCH_CTRL_RSTMASK                                  0xffffffff
#define MAC_ASE_SEARCH_CTRL_RESET                                    0x00000000

// 0x8688 (MAC_ASE_HASH_CTRL)
#define MAC_ASE_HASH_CTRL_CACHE_INVALIDATE_MSB                       23
#define MAC_ASE_HASH_CTRL_CACHE_INVALIDATE_LSB                       23
#define MAC_ASE_HASH_CTRL_CACHE_INVALIDATE_MASK                      0x00800000
#define MAC_ASE_HASH_CTRL_CACHE_INVALIDATE_GET(x)                    (((x) & MAC_ASE_HASH_CTRL_CACHE_INVALIDATE_MASK) >> MAC_ASE_HASH_CTRL_CACHE_INVALIDATE_LSB)
#define MAC_ASE_HASH_CTRL_CACHE_INVALIDATE_SET(x)                    (((0 | (x)) << MAC_ASE_HASH_CTRL_CACHE_INVALIDATE_LSB) & MAC_ASE_HASH_CTRL_CACHE_INVALIDATE_MASK)
#define MAC_ASE_HASH_CTRL_CACHE_INVALIDATE_RESET                     0
#define MAC_ASE_HASH_CTRL_CACHE_DISABLE_MSB                          22
#define MAC_ASE_HASH_CTRL_CACHE_DISABLE_LSB                          22
#define MAC_ASE_HASH_CTRL_CACHE_DISABLE_MASK                         0x00400000
#define MAC_ASE_HASH_CTRL_CACHE_DISABLE_GET(x)                       (((x) & MAC_ASE_HASH_CTRL_CACHE_DISABLE_MASK) >> MAC_ASE_HASH_CTRL_CACHE_DISABLE_LSB)
#define MAC_ASE_HASH_CTRL_CACHE_DISABLE_SET(x)                       (((0 | (x)) << MAC_ASE_HASH_CTRL_CACHE_DISABLE_LSB) & MAC_ASE_HASH_CTRL_CACHE_DISABLE_MASK)
#define MAC_ASE_HASH_CTRL_CACHE_DISABLE_RESET                        0
#define MAC_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MSB                   21
#define MAC_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_LSB                   21
#define MAC_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MASK                  0x00200000
#define MAC_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_GET(x)                (((x) & MAC_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MASK) >> MAC_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_LSB)
#define MAC_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_SET(x)                (((0 | (x)) << MAC_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_LSB) & MAC_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MASK)
#define MAC_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_RESET                 0
#define MAC_ASE_HASH_CTRL_HASH_SEL_MSB                               20
#define MAC_ASE_HASH_CTRL_HASH_SEL_LSB                               20
#define MAC_ASE_HASH_CTRL_HASH_SEL_MASK                              0x00100000
#define MAC_ASE_HASH_CTRL_HASH_SEL_GET(x)                            (((x) & MAC_ASE_HASH_CTRL_HASH_SEL_MASK) >> MAC_ASE_HASH_CTRL_HASH_SEL_LSB)
#define MAC_ASE_HASH_CTRL_HASH_SEL_SET(x)                            (((0 | (x)) << MAC_ASE_HASH_CTRL_HASH_SEL_LSB) & MAC_ASE_HASH_CTRL_HASH_SEL_MASK)
#define MAC_ASE_HASH_CTRL_HASH_SEL_RESET                             1
#define MAC_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MSB                       19
#define MAC_ASE_HASH_CTRL_HASH_MCAST_SHIFT_LSB                       16
#define MAC_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MASK                      0x000f0000
#define MAC_ASE_HASH_CTRL_HASH_MCAST_SHIFT_GET(x)                    (((x) & MAC_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MASK) >> MAC_ASE_HASH_CTRL_HASH_MCAST_SHIFT_LSB)
#define MAC_ASE_HASH_CTRL_HASH_MCAST_SHIFT_SET(x)                    (((0 | (x)) << MAC_ASE_HASH_CTRL_HASH_MCAST_SHIFT_LSB) & MAC_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MASK)
#define MAC_ASE_HASH_CTRL_HASH_MCAST_SHIFT_RESET                     2
#define MAC_ASE_HASH_CTRL_HASH_XOR_MSB                               15
#define MAC_ASE_HASH_CTRL_HASH_XOR_LSB                               0
#define MAC_ASE_HASH_CTRL_HASH_XOR_MASK                              0x0000ffff
#define MAC_ASE_HASH_CTRL_HASH_XOR_GET(x)                            (((x) & MAC_ASE_HASH_CTRL_HASH_XOR_MASK) >> MAC_ASE_HASH_CTRL_HASH_XOR_LSB)
#define MAC_ASE_HASH_CTRL_HASH_XOR_SET(x)                            (((0 | (x)) << MAC_ASE_HASH_CTRL_HASH_XOR_LSB) & MAC_ASE_HASH_CTRL_HASH_XOR_MASK)
#define MAC_ASE_HASH_CTRL_HASH_XOR_RESET                             43981
#define MAC_ASE_HASH_CTRL_ADDRESS                                    0x8688
#define MAC_ASE_HASH_CTRL_HW_MASK                                    0x00ffffff
#define MAC_ASE_HASH_CTRL_SW_MASK                                    0x00ffffff
#define MAC_ASE_HASH_CTRL_HW_WRITE_MASK                              0x00800000
#define MAC_ASE_HASH_CTRL_SW_WRITE_MASK                              0x00ffffff
#define MAC_ASE_HASH_CTRL_RSTMASK                                    0xffffffff
#define MAC_ASE_HASH_CTRL_RESET                                      0x0012abcd

// 0x868c (MAC_PCU_BSSID3_L32)
#define MAC_PCU_BSSID3_L32_ADDR_MSB                                  31
#define MAC_PCU_BSSID3_L32_ADDR_LSB                                  0
#define MAC_PCU_BSSID3_L32_ADDR_MASK                                 0xffffffff
#define MAC_PCU_BSSID3_L32_ADDR_GET(x)                               (((x) & MAC_PCU_BSSID3_L32_ADDR_MASK) >> MAC_PCU_BSSID3_L32_ADDR_LSB)
#define MAC_PCU_BSSID3_L32_ADDR_SET(x)                               (((0 | (x)) << MAC_PCU_BSSID3_L32_ADDR_LSB) & MAC_PCU_BSSID3_L32_ADDR_MASK)
#define MAC_PCU_BSSID3_L32_ADDR_RESET                                0
#define MAC_PCU_BSSID3_L32_ADDRESS                                   0x868c
#define MAC_PCU_BSSID3_L32_HW_MASK                                   0xffffffff
#define MAC_PCU_BSSID3_L32_SW_MASK                                   0xffffffff
#define MAC_PCU_BSSID3_L32_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_BSSID3_L32_SW_WRITE_MASK                             0xffffffff
#define MAC_PCU_BSSID3_L32_RSTMASK                                   0xffffffff
#define MAC_PCU_BSSID3_L32_RESET                                     0x00000000

// 0x8690 (MAC_PCU_BSSID3_U16)
#define MAC_PCU_BSSID3_U16_ENABLE_MSB                                16
#define MAC_PCU_BSSID3_U16_ENABLE_LSB                                16
#define MAC_PCU_BSSID3_U16_ENABLE_MASK                               0x00010000
#define MAC_PCU_BSSID3_U16_ENABLE_GET(x)                             (((x) & MAC_PCU_BSSID3_U16_ENABLE_MASK) >> MAC_PCU_BSSID3_U16_ENABLE_LSB)
#define MAC_PCU_BSSID3_U16_ENABLE_SET(x)                             (((0 | (x)) << MAC_PCU_BSSID3_U16_ENABLE_LSB) & MAC_PCU_BSSID3_U16_ENABLE_MASK)
#define MAC_PCU_BSSID3_U16_ENABLE_RESET                              0
#define MAC_PCU_BSSID3_U16_ADDR_MSB                                  15
#define MAC_PCU_BSSID3_U16_ADDR_LSB                                  0
#define MAC_PCU_BSSID3_U16_ADDR_MASK                                 0x0000ffff
#define MAC_PCU_BSSID3_U16_ADDR_GET(x)                               (((x) & MAC_PCU_BSSID3_U16_ADDR_MASK) >> MAC_PCU_BSSID3_U16_ADDR_LSB)
#define MAC_PCU_BSSID3_U16_ADDR_SET(x)                               (((0 | (x)) << MAC_PCU_BSSID3_U16_ADDR_LSB) & MAC_PCU_BSSID3_U16_ADDR_MASK)
#define MAC_PCU_BSSID3_U16_ADDR_RESET                                0
#define MAC_PCU_BSSID3_U16_ADDRESS                                   0x8690
#define MAC_PCU_BSSID3_U16_HW_MASK                                   0x0001ffff
#define MAC_PCU_BSSID3_U16_SW_MASK                                   0x0001ffff
#define MAC_PCU_BSSID3_U16_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_BSSID3_U16_SW_WRITE_MASK                             0x0001ffff
#define MAC_PCU_BSSID3_U16_RSTMASK                                   0xffffffff
#define MAC_PCU_BSSID3_U16_RESET                                     0x00000000

// 0x8694 (MAC_PCU_BSSID4_L32)
#define MAC_PCU_BSSID4_L32_ADDR_MSB                                  31
#define MAC_PCU_BSSID4_L32_ADDR_LSB                                  0
#define MAC_PCU_BSSID4_L32_ADDR_MASK                                 0xffffffff
#define MAC_PCU_BSSID4_L32_ADDR_GET(x)                               (((x) & MAC_PCU_BSSID4_L32_ADDR_MASK) >> MAC_PCU_BSSID4_L32_ADDR_LSB)
#define MAC_PCU_BSSID4_L32_ADDR_SET(x)                               (((0 | (x)) << MAC_PCU_BSSID4_L32_ADDR_LSB) & MAC_PCU_BSSID4_L32_ADDR_MASK)
#define MAC_PCU_BSSID4_L32_ADDR_RESET                                0
#define MAC_PCU_BSSID4_L32_ADDRESS                                   0x8694
#define MAC_PCU_BSSID4_L32_HW_MASK                                   0xffffffff
#define MAC_PCU_BSSID4_L32_SW_MASK                                   0xffffffff
#define MAC_PCU_BSSID4_L32_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_BSSID4_L32_SW_WRITE_MASK                             0xffffffff
#define MAC_PCU_BSSID4_L32_RSTMASK                                   0xffffffff
#define MAC_PCU_BSSID4_L32_RESET                                     0x00000000

// 0x8698 (MAC_PCU_BSSID4_U16)
#define MAC_PCU_BSSID4_U16_ENABLE_MSB                                16
#define MAC_PCU_BSSID4_U16_ENABLE_LSB                                16
#define MAC_PCU_BSSID4_U16_ENABLE_MASK                               0x00010000
#define MAC_PCU_BSSID4_U16_ENABLE_GET(x)                             (((x) & MAC_PCU_BSSID4_U16_ENABLE_MASK) >> MAC_PCU_BSSID4_U16_ENABLE_LSB)
#define MAC_PCU_BSSID4_U16_ENABLE_SET(x)                             (((0 | (x)) << MAC_PCU_BSSID4_U16_ENABLE_LSB) & MAC_PCU_BSSID4_U16_ENABLE_MASK)
#define MAC_PCU_BSSID4_U16_ENABLE_RESET                              0
#define MAC_PCU_BSSID4_U16_ADDR_MSB                                  15
#define MAC_PCU_BSSID4_U16_ADDR_LSB                                  0
#define MAC_PCU_BSSID4_U16_ADDR_MASK                                 0x0000ffff
#define MAC_PCU_BSSID4_U16_ADDR_GET(x)                               (((x) & MAC_PCU_BSSID4_U16_ADDR_MASK) >> MAC_PCU_BSSID4_U16_ADDR_LSB)
#define MAC_PCU_BSSID4_U16_ADDR_SET(x)                               (((0 | (x)) << MAC_PCU_BSSID4_U16_ADDR_LSB) & MAC_PCU_BSSID4_U16_ADDR_MASK)
#define MAC_PCU_BSSID4_U16_ADDR_RESET                                0
#define MAC_PCU_BSSID4_U16_ADDRESS                                   0x8698
#define MAC_PCU_BSSID4_U16_HW_MASK                                   0x0001ffff
#define MAC_PCU_BSSID4_U16_SW_MASK                                   0x0001ffff
#define MAC_PCU_BSSID4_U16_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_BSSID4_U16_SW_WRITE_MASK                             0x0001ffff
#define MAC_PCU_BSSID4_U16_RSTMASK                                   0xffffffff
#define MAC_PCU_BSSID4_U16_RESET                                     0x00000000

// 0x869c (MAC_PCU_RX_FILTER2)
#define MAC_PCU_RX_FILTER2_BSSID_BASED_UNICAST_MSB                   3
#define MAC_PCU_RX_FILTER2_BSSID_BASED_UNICAST_LSB                   0
#define MAC_PCU_RX_FILTER2_BSSID_BASED_UNICAST_MASK                  0x0000000f
#define MAC_PCU_RX_FILTER2_BSSID_BASED_UNICAST_GET(x)                (((x) & MAC_PCU_RX_FILTER2_BSSID_BASED_UNICAST_MASK) >> MAC_PCU_RX_FILTER2_BSSID_BASED_UNICAST_LSB)
#define MAC_PCU_RX_FILTER2_BSSID_BASED_UNICAST_SET(x)                (((0 | (x)) << MAC_PCU_RX_FILTER2_BSSID_BASED_UNICAST_LSB) & MAC_PCU_RX_FILTER2_BSSID_BASED_UNICAST_MASK)
#define MAC_PCU_RX_FILTER2_BSSID_BASED_UNICAST_RESET                 0
#define MAC_PCU_RX_FILTER2_ADDRESS                                   0x869c
#define MAC_PCU_RX_FILTER2_HW_MASK                                   0x0000000f
#define MAC_PCU_RX_FILTER2_SW_MASK                                   0x0000000f
#define MAC_PCU_RX_FILTER2_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_RX_FILTER2_SW_WRITE_MASK                             0x0000000f
#define MAC_PCU_RX_FILTER2_RSTMASK                                   0xffffffff
#define MAC_PCU_RX_FILTER2_RESET                                     0x00000000

// 0x86a0 (MAC_PCU_RTT_CTRL)
#define MAC_PCU_RTT_CTRL_ALLOW_HT_VHT_ACK_BA_MSB                     16
#define MAC_PCU_RTT_CTRL_ALLOW_HT_VHT_ACK_BA_LSB                     16
#define MAC_PCU_RTT_CTRL_ALLOW_HT_VHT_ACK_BA_MASK                    0x00010000
#define MAC_PCU_RTT_CTRL_ALLOW_HT_VHT_ACK_BA_GET(x)                  (((x) & MAC_PCU_RTT_CTRL_ALLOW_HT_VHT_ACK_BA_MASK) >> MAC_PCU_RTT_CTRL_ALLOW_HT_VHT_ACK_BA_LSB)
#define MAC_PCU_RTT_CTRL_ALLOW_HT_VHT_ACK_BA_SET(x)                  (((0 | (x)) << MAC_PCU_RTT_CTRL_ALLOW_HT_VHT_ACK_BA_LSB) & MAC_PCU_RTT_CTRL_ALLOW_HT_VHT_ACK_BA_MASK)
#define MAC_PCU_RTT_CTRL_ALLOW_HT_VHT_ACK_BA_RESET                   0
#define MAC_PCU_RTT_CTRL_ACTION_MSB                                  15
#define MAC_PCU_RTT_CTRL_ACTION_LSB                                  8
#define MAC_PCU_RTT_CTRL_ACTION_MASK                                 0x0000ff00
#define MAC_PCU_RTT_CTRL_ACTION_GET(x)                               (((x) & MAC_PCU_RTT_CTRL_ACTION_MASK) >> MAC_PCU_RTT_CTRL_ACTION_LSB)
#define MAC_PCU_RTT_CTRL_ACTION_SET(x)                               (((0 | (x)) << MAC_PCU_RTT_CTRL_ACTION_LSB) & MAC_PCU_RTT_CTRL_ACTION_MASK)
#define MAC_PCU_RTT_CTRL_ACTION_RESET                                1
#define MAC_PCU_RTT_CTRL_CATEGORY_MSB                                7
#define MAC_PCU_RTT_CTRL_CATEGORY_LSB                                0
#define MAC_PCU_RTT_CTRL_CATEGORY_MASK                               0x000000ff
#define MAC_PCU_RTT_CTRL_CATEGORY_GET(x)                             (((x) & MAC_PCU_RTT_CTRL_CATEGORY_MASK) >> MAC_PCU_RTT_CTRL_CATEGORY_LSB)
#define MAC_PCU_RTT_CTRL_CATEGORY_SET(x)                             (((0 | (x)) << MAC_PCU_RTT_CTRL_CATEGORY_LSB) & MAC_PCU_RTT_CTRL_CATEGORY_MASK)
#define MAC_PCU_RTT_CTRL_CATEGORY_RESET                              11
#define MAC_PCU_RTT_CTRL_ADDRESS                                     0x86a0
#define MAC_PCU_RTT_CTRL_HW_MASK                                     0x0001ffff
#define MAC_PCU_RTT_CTRL_SW_MASK                                     0x0001ffff
#define MAC_PCU_RTT_CTRL_HW_WRITE_MASK                               0x00000000
#define MAC_PCU_RTT_CTRL_SW_WRITE_MASK                               0x0001ffff
#define MAC_PCU_RTT_CTRL_RSTMASK                                     0xffffffff
#define MAC_PCU_RTT_CTRL_RESET                                       0x0000010b

// 0x86a4 (MAC_PCU_PHY_ERROR_CODE)
#define MAC_PCU_PHY_ERROR_CODE_VALUE_MSB                             7
#define MAC_PCU_PHY_ERROR_CODE_VALUE_LSB                             0
#define MAC_PCU_PHY_ERROR_CODE_VALUE_MASK                            0x000000ff
#define MAC_PCU_PHY_ERROR_CODE_VALUE_GET(x)                          (((x) & MAC_PCU_PHY_ERROR_CODE_VALUE_MASK) >> MAC_PCU_PHY_ERROR_CODE_VALUE_LSB)
#define MAC_PCU_PHY_ERROR_CODE_VALUE_SET(x)                          (((0 | (x)) << MAC_PCU_PHY_ERROR_CODE_VALUE_LSB) & MAC_PCU_PHY_ERROR_CODE_VALUE_MASK)
#define MAC_PCU_PHY_ERROR_CODE_VALUE_RESET                           0
#define MAC_PCU_PHY_ERROR_CODE_ADDRESS                               0x86a4
#define MAC_PCU_PHY_ERROR_CODE_HW_MASK                               0x000000ff
#define MAC_PCU_PHY_ERROR_CODE_SW_MASK                               0x000000ff
#define MAC_PCU_PHY_ERROR_CODE_HW_WRITE_MASK                         0x000000ff
#define MAC_PCU_PHY_ERROR_CODE_SW_WRITE_MASK                         0x000000ff
#define MAC_PCU_PHY_ERROR_CODE_RSTMASK                               0xffffffff
#define MAC_PCU_PHY_ERROR_CODE_RESET                                 0x00000000

// 0x86a8 (MAC_PCU_PHY_ERROR_EIFS_MASK_CONT)
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_VALUE_MSB                   31
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_VALUE_LSB                   0
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_VALUE_MASK                  0xffffffff
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_VALUE_GET(x)                (((x) & MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_VALUE_MASK) >> MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_VALUE_LSB)
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_VALUE_SET(x)                (((0 | (x)) << MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_VALUE_LSB) & MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_VALUE_MASK)
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_VALUE_RESET                 0
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_ADDRESS                     0x86a8
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_HW_MASK                     0xffffffff
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_SW_MASK                     0xffffffff
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_HW_WRITE_MASK               0x00000000
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_SW_WRITE_MASK               0xffffffff
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_RSTMASK                     0xffffffff
#define MAC_PCU_PHY_ERROR_EIFS_MASK_CONT_RESET                       0x00000000

// 0x86ac (MAC_PCU_PHY_ERROR_AIFS_MASK_CONT)
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_VALUE_MSB                   31
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_VALUE_LSB                   0
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_VALUE_MASK                  0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_VALUE_GET(x)                (((x) & MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_VALUE_MASK) >> MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_VALUE_LSB)
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_VALUE_SET(x)                (((0 | (x)) << MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_VALUE_LSB) & MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_VALUE_MASK)
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_VALUE_RESET                 0
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_ADDRESS                     0x86ac
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_HW_MASK                     0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_SW_MASK                     0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_HW_WRITE_MASK               0x00000000
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_SW_WRITE_MASK               0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_RSTMASK                     0xffffffff
#define MAC_PCU_PHY_ERROR_AIFS_MASK_CONT_RESET                       0x00000000

// 0x86b0 (MAC_PCU_PHY_ERR_CNT_2_MASK_CONT)
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_VALUE_MSB                    31
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_VALUE_LSB                    0
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_VALUE_MASK                   0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_VALUE_GET(x)                 (((x) & MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_VALUE_MASK) >> MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_VALUE_LSB)
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_VALUE_SET(x)                 (((0 | (x)) << MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_VALUE_LSB) & MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_VALUE_MASK)
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_VALUE_RESET                  0
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_ADDRESS                      0x86b0
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_HW_MASK                      0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_SW_MASK                      0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_HW_WRITE_MASK                0x00000000
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_SW_WRITE_MASK                0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_RSTMASK                      0xffffffff
#define MAC_PCU_PHY_ERR_CNT_2_MASK_CONT_RESET                        0x00000000

// 0x86b4 (MAC_PCU_PHY_ERR_CNT_3_MASK_CONT)
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_VALUE_MSB                    31
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_VALUE_LSB                    0
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_VALUE_MASK                   0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_VALUE_GET(x)                 (((x) & MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_VALUE_MASK) >> MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_VALUE_LSB)
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_VALUE_SET(x)                 (((0 | (x)) << MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_VALUE_LSB) & MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_VALUE_MASK)
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_VALUE_RESET                  0
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_ADDRESS                      0x86b4
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_HW_MASK                      0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_SW_MASK                      0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_HW_WRITE_MASK                0x00000000
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_SW_WRITE_MASK                0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_RSTMASK                      0xffffffff
#define MAC_PCU_PHY_ERR_CNT_3_MASK_CONT_RESET                        0x00000000

// 0x86b8 (MAC_PCU_PHY_DATA_LENGTH_THRESH)
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_ENABLE_MSB                    16
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_ENABLE_LSB                    16
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_ENABLE_MASK                   0x00010000
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_ENABLE_GET(x)                 (((x) & MAC_PCU_PHY_DATA_LENGTH_THRESH_ENABLE_MASK) >> MAC_PCU_PHY_DATA_LENGTH_THRESH_ENABLE_LSB)
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_ENABLE_SET(x)                 (((0 | (x)) << MAC_PCU_PHY_DATA_LENGTH_THRESH_ENABLE_LSB) & MAC_PCU_PHY_DATA_LENGTH_THRESH_ENABLE_MASK)
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_ENABLE_RESET                  0
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_VALUE_MSB                     13
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_VALUE_LSB                     0
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_VALUE_MASK                    0x00003fff
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_VALUE_GET(x)                  (((x) & MAC_PCU_PHY_DATA_LENGTH_THRESH_VALUE_MASK) >> MAC_PCU_PHY_DATA_LENGTH_THRESH_VALUE_LSB)
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_VALUE_SET(x)                  (((0 | (x)) << MAC_PCU_PHY_DATA_LENGTH_THRESH_VALUE_LSB) & MAC_PCU_PHY_DATA_LENGTH_THRESH_VALUE_MASK)
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_VALUE_RESET                   100
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_ADDRESS                       0x86b8
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_HW_MASK                       0x00013fff
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_SW_MASK                       0x00013fff
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_HW_WRITE_MASK                 0x00000000
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_SW_WRITE_MASK                 0x00013fff
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_RSTMASK                       0xffffffff
#define MAC_PCU_PHY_DATA_LENGTH_THRESH_RESET                         0x00000064

// 0x86bc (MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT)
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_VALUE_MSB                    31
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_VALUE_LSB                    0
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_VALUE_MASK                   0xffffffff
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_VALUE_GET(x)                 (((x) & MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_VALUE_MASK) >> MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_VALUE_LSB)
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_VALUE_SET(x)                 (((0 | (x)) << MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_VALUE_LSB) & MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_VALUE_MASK)
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_VALUE_RESET                  2024
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_ADDRESS                      0x86bc
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_HW_MASK                      0xffffffff
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_SW_MASK                      0xffffffff
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_HW_WRITE_MASK                0x00000000
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_SW_WRITE_MASK                0xffffffff
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_RSTMASK                      0xffffffff
#define MAC_PCU_SEC_CHANNEL_TX_PIFS_CNT_RESET                        0x000007e8

// 0x86c0 (MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT)
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_VALUE_MSB                    31
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_VALUE_LSB                    0
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_VALUE_MASK                   0xffffffff
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_VALUE_GET(x)                 (((x) & MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_VALUE_MASK) >> MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_VALUE_LSB)
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_VALUE_SET(x)                 (((0 | (x)) << MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_VALUE_LSB) & MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_VALUE_MASK)
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_VALUE_RESET                  2640
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_ADDRESS                      0x86c0
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_HW_MASK                      0xffffffff
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_SW_MASK                      0xffffffff
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_HW_WRITE_MASK                0x00000000
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_SW_WRITE_MASK                0xffffffff
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_RSTMASK                      0xffffffff
#define MAC_PCU_SEC_CHANNEL_RX_PIFS_CNT_RESET                        0x00000a50

// 0xe000 (MAC_PCU_BUF_0)
#define MAC_PCU_BUF_0_DATA_MSB                                       31
#define MAC_PCU_BUF_0_DATA_LSB                                       0
#define MAC_PCU_BUF_0_DATA_MASK                                      0xffffffff
#define MAC_PCU_BUF_0_DATA_GET(x)                                    (((x) & MAC_PCU_BUF_0_DATA_MASK) >> MAC_PCU_BUF_0_DATA_LSB)
#define MAC_PCU_BUF_0_DATA_SET(x)                                    (((0 | (x)) << MAC_PCU_BUF_0_DATA_LSB) & MAC_PCU_BUF_0_DATA_MASK)
#define MAC_PCU_BUF_0_DATA_RESET                                     0
#define MAC_PCU_BUF_0_ADDRESS                                        0xe000
#define MAC_PCU_BUF_ADDRESS                                          MAC_PCU_BUF_0_ADDRESS
#define MAC_PCU_BUF_0_HW_MASK                                        0xffffffff
#define MAC_PCU_BUF_0_SW_MASK                                        0xffffffff
#define MAC_PCU_BUF_0_HW_WRITE_MASK                                  0x00000000
#define MAC_PCU_BUF_0_SW_WRITE_MASK                                  0xffffffff
#define MAC_PCU_BUF_0_RSTMASK                                        0x00000000
#define MAC_PCU_BUF_0_RESET                                          0x00000000

// Skip e004 (MAC_PCU_BUF_1) - fffc (MAC_PCU_BUF_2047) for brevity

#endif /* _MAC_PCU_REG_H_ */
