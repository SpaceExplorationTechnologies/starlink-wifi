/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef __REG_TIERED_CHN1_TABLE_MAP_H__
#define __REG_TIERED_CHN1_TABLE_MAP_H__

#include "tiered_chn1_table_map_macro.h"

struct chn1_table_map {
  volatile unsigned int pad__0[0x20];             /*        0x0 - 0x80       */
  volatile u_int32_t BB_paprd_power_at_am2am_cal_b1;
                                                  /*       0x80 - 0x84       */
  volatile u_int32_t BB_paprd_valid_obdb_b1;      /*       0x84 - 0x88       */
  volatile unsigned int pad__1[0x1e];             /*       0x88 - 0x100      */
  volatile u_int32_t BB_chn1_tables_dummy_2;      /*      0x100 - 0x104      */
  volatile unsigned int pad__2[0x1e3];            /*      0x104 - 0x890      */
  volatile u_int32_t BB_txiqcorr_txpath_coef_b1[16];
                                                  /*      0x890 - 0x8d0      */
  volatile u_int32_t BB_txiqcorr_rxpath_coef_b1[16];
                                                  /*      0x8d0 - 0x910      */
  volatile u_int32_t BB_rxiqcorr_rxpath_coef_b1[16];
                                                  /*      0x910 - 0x950      */
  volatile u_int32_t BB_rxiqcorr_txpath_coef_b1[16];
                                                  /*      0x950 - 0x990      */
  volatile unsigned int pad__3[0x2c];             /*      0x990 - 0xa40      */
  volatile u_int32_t BB_rxcal_tx_iqcorr_idx_7_0_b1;
                                                  /*      0xa40 - 0xa44      */
  volatile u_int32_t BB_rxcal_tx_iqcorr_idx_15_8_b1;
                                                  /*      0xa44 - 0xa48      */
  volatile u_int32_t BB_rxcal_tx_iqcorr_idx_23_16_b1;
                                                  /*      0xa48 - 0xa4c      */
  volatile u_int32_t BB_rxcal_tx_iqcorr_idx_31_24_b1;
                                                  /*      0xa4c - 0xa50      */
  volatile unsigned int pad__4[0x4];              /*      0xa50 - 0xa60      */
  volatile u_int32_t BB_paprd_sm_sig_gain_table_0_2_b1;
                                                  /*      0xa60 - 0xa64      */
  volatile u_int32_t BB_paprd_sm_sig_gain_table_3_5_b1;
                                                  /*      0xa64 - 0xa68      */
  volatile u_int32_t BB_paprd_sm_sig_gain_table_0_2_sec80_b1;
                                                  /*      0xa68 - 0xa6c      */
  volatile u_int32_t BB_paprd_peftbl_sel_b1;      /*      0xa6c - 0xa70      */
  volatile u_int32_t BB_preemp_coef_tbl0_set0_b1; /*      0xa70 - 0xa74      */
  volatile u_int32_t BB_preemp_coef_tbl0_set1_b1; /*      0xa74 - 0xa78      */
  volatile u_int32_t BB_preemp_coef_tbl0_set2_b1; /*      0xa78 - 0xa7c      */
  volatile u_int32_t BB_preemp_coef_tbl0_set3_b1; /*      0xa7c - 0xa80      */
  volatile u_int32_t BB_preemp_coef_tbl0_set4_b1; /*      0xa80 - 0xa84      */
  volatile u_int32_t BB_preemp_coef_tbl0_set5_b1; /*      0xa84 - 0xa88      */
  volatile u_int32_t BB_preemp_coef_tbl0_set6_b1; /*      0xa88 - 0xa8c      */
  volatile u_int32_t BB_preemp_coef_tbl0_set7_b1; /*      0xa8c - 0xa90      */
  volatile u_int32_t BB_preemp_coef_tbl0_set8_b1; /*      0xa90 - 0xa94      */
  volatile u_int32_t BB_preemp_coef_tbl1_set0_b1; /*      0xa94 - 0xa98      */
  volatile u_int32_t BB_preemp_coef_tbl1_set1_b1; /*      0xa98 - 0xa9c      */
  volatile u_int32_t BB_preemp_coef_tbl1_set2_b1; /*      0xa9c - 0xaa0      */
  volatile u_int32_t BB_preemp_coef_tbl1_set3_b1; /*      0xaa0 - 0xaa4      */
  volatile u_int32_t BB_preemp_coef_tbl1_set4_b1; /*      0xaa4 - 0xaa8      */
  volatile u_int32_t BB_preemp_coef_tbl1_set5_b1; /*      0xaa8 - 0xaac      */
  volatile u_int32_t BB_preemp_coef_tbl1_set6_b1; /*      0xaac - 0xab0      */
  volatile u_int32_t BB_preemp_coef_tbl1_set7_b1; /*      0xab0 - 0xab4      */
  volatile u_int32_t BB_preemp_coef_tbl1_set8_b1; /*      0xab4 - 0xab8      */
  volatile u_int32_t BB_paprd_bw_table_dpdoff_b1; /*      0xab8 - 0xabc      */
  volatile u_int32_t BB_paprd_bw_table_1_0_b1;    /*      0xabc - 0xac0      */
  volatile u_int32_t BB_paprd_bw_table_3_2_b1;    /*      0xac0 - 0xac4      */
  volatile u_int32_t BB_paprd_bw_table_5_4_b1;    /*      0xac4 - 0xac8      */
  volatile u_int32_t BB_tx_notch_coef_b1;         /*      0xac8 - 0xacc      */
  volatile u_int32_t BB_tx_notch_dpd_en_b1;       /*      0xacc - 0xad0      */
  volatile unsigned int pad__5[0xc];              /*      0xad0 - 0xb00      */
  volatile u_int32_t BB_tx_plybck_ctrl_0_b1;      /*      0xb00 - 0xb04      */
  volatile unsigned int pad__6[0x8];              /*      0xb04 - 0xb24      */
  volatile u_int32_t BB_ibfcal_phasecorrection_chn1;
                                                  /*      0xb24 - 0xb28      */
  volatile u_int32_t BB_ibfcal_rffe_comp_g0_chn1; /*      0xb28 - 0xb2c      */
  volatile u_int32_t BB_ibfcal_rffe_comp_g1_chn1; /*      0xb2c - 0xb30      */
  volatile u_int32_t BB_ibfcal_rffe_comp_g2_chn1; /*      0xb30 - 0xb34      */
  volatile u_int32_t BB_ibfcal_rffe_comp_g3_chn1; /*      0xb34 - 0xb38      */
  volatile u_int32_t BB_ibfcal_rffe_comp_g4_chn1; /*      0xb38 - 0xb3c      */
  volatile u_int32_t BB_ibfcal_rffe_comp_g5_chn1; /*      0xb3c - 0xb40      */
  volatile u_int32_t BB_ibfcal_rffe_comp_g6_chn1; /*      0xb40 - 0xb44      */
  volatile unsigned int pad__7[0x2f];             /*      0xb44 - 0xc00      */
  volatile u_int32_t BB_normrx_rxiq_corr_coeff_b1[160];
                                                  /*      0xc00 - 0xe80      */
  volatile u_int32_t BB_paprd_mem_tab_b1[768];    /*      0xe80 - 0x1a80     */
  volatile unsigned int pad__8[0x518];            /*     0x1a80 - 0x2ee0     */
  volatile u_int32_t BB_normtx_txiq_corr_coeff_b1[160];
                                                  /*     0x2ee0 - 0x3160     */
  volatile unsigned int pad__9[0x28];             /*     0x3160 - 0x3200     */
  volatile u_int32_t BB_chaninfo_tab_b1[256];     /*     0x3200 - 0x3600     */
  volatile unsigned int pad__10[0x152b];          /*     0x3600 - 0x8aac     */
  volatile u_int32_t BB_chn1_tables_dummy_1;      /*     0x8aac - 0x8ab0     */
};

struct tiered_chn1_table_map {
  struct chn1_table_map chn1_table_map;           /*        0x0 - 0x8a30     */
  volatile unsigned int pad__0[0x20];             /*     0x8a30 - 0x8ab0     */
};

#endif /* __REG_TIERED_CHN1_TABLE_MAP_H__ */
