/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef __REG_CHIP_TOP_REG_FPGA_MAP_H__
#define __REG_CHIP_TOP_REG_FPGA_MAP_H__

#include "chip_top_reg_fpga_map_macro.h"

struct pcie_local_reg {
  volatile u_int32_t RTC_STATE;                   /*        0x0 - 0x4        */
  volatile u_int32_t PCIE_SOC_WAKE;               /*        0x4 - 0x8        */
  volatile u_int32_t SOC_GLOBAL_RESET;            /*        0x8 - 0xc        */
  volatile unsigned int pad__0;                   /*        0xc - 0x10       */
  volatile u_int32_t PCIE_LOCAL_CTRL_OBS_MUX;     /*       0x10 - 0x14       */
  volatile u_int32_t PCIE_DEBUG_LOCAL;            /*       0x14 - 0x18       */
  volatile u_int32_t PCIE_BAR_VALID;              /*       0x18 - 0x1c       */
  volatile u_int32_t PCIE_SOC_RDY_STATUS;         /*       0x1c - 0x20       */
};

struct agc_reg_map {
  volatile u_int32_t BB_settling_time;            /*        0x0 - 0x4        */
  volatile u_int32_t BB_gain_force_max_gains_b0;  /*        0x4 - 0x8        */
  volatile u_int32_t BB_gains_min_offsets;        /*        0x8 - 0xc        */
  volatile u_int32_t BB_desired_sigsize;          /*        0xc - 0x10       */
  volatile u_int32_t BB_find_signal;              /*       0x10 - 0x14       */
  volatile u_int32_t BB_agc;                      /*       0x14 - 0x18       */
  volatile u_int32_t BB_ext_atten_switch_ctl_b0;  /*       0x18 - 0x1c       */
  volatile u_int32_t BB_cca_b0;                   /*       0x1c - 0x20       */
  volatile u_int32_t BB_cca_ctrl_2_b0;            /*       0x20 - 0x24       */
  volatile u_int32_t BB_restart;                  /*       0x24 - 0x28       */
  volatile u_int32_t BB_multichain_gain_ctrl;     /*       0x28 - 0x2c       */
  volatile u_int32_t BB_ext_chan_pwr_thr_1;       /*       0x2c - 0x30       */
  volatile u_int32_t BB_ext_bw_pwr_thr;           /*       0x30 - 0x34       */
  volatile u_int32_t BB_ext_bw_pwr_thr_2;         /*       0x34 - 0x38       */
  volatile u_int32_t BB_rifs_srch;                /*       0x38 - 0x3c       */
  volatile u_int32_t BB_peak_det_ctrl_1;          /*       0x3c - 0x40       */
  volatile u_int32_t BB_peak_det_ctrl_2;          /*       0x40 - 0x44       */
  volatile u_int32_t BB_rx_gain_bounds_1;         /*       0x44 - 0x48       */
  volatile u_int32_t BB_rx_gain_bounds_2;         /*       0x48 - 0x4c       */
  volatile u_int32_t BB_peak_det_cal_ctrl;        /*       0x4c - 0x50       */
  volatile u_int32_t BB_agc_dig_dc_ctrl;          /*       0x50 - 0x54       */
  volatile u_int32_t BB_bt_coex_1;                /*       0x54 - 0x58       */
  volatile u_int32_t BB_bt_coex_2;                /*       0x58 - 0x5c       */
  volatile u_int32_t BB_bt_coex_3;                /*       0x5c - 0x60       */
  volatile u_int32_t BB_bt_coex_4;                /*       0x60 - 0x64       */
  volatile u_int32_t BB_bt_coex_5;                /*       0x64 - 0x68       */
  volatile u_int32_t BB_dyn_adc_size_ctrl;        /*       0x68 - 0x6c       */
  volatile u_int32_t BB_rx_lo_dccal_ctrl;         /*       0x6c - 0x70       */
  volatile u_int32_t BB_adc_capture;              /*       0x70 - 0x74       */
  volatile u_int32_t BB_find_signal_2;            /*       0x74 - 0x78       */
  volatile u_int32_t BB_peak_det_ctrl_3;          /*       0x78 - 0x7c       */
  volatile u_int32_t BB_find_signal2;             /*       0x7c - 0x80       */
  volatile u_int32_t BB_srch_fft_ctrl_1;          /*       0x80 - 0x84       */
  volatile u_int32_t BB_srch_fft_ctrl_2;          /*       0x84 - 0x88       */
  volatile u_int32_t BB_srch_fft_ctrl_3;          /*       0x88 - 0x8c       */
  volatile u_int32_t BB_srch_fft_ctrl_4;          /*       0x8c - 0x90       */
  volatile u_int32_t BB_radar_chirp_detect;       /*       0x90 - 0x94       */
  volatile unsigned int pad__0;                   /*       0x94 - 0x98       */
  volatile u_int32_t BB_spectral_scan_2;          /*       0x98 - 0x9c       */
  volatile u_int32_t BB_spectral_scan_3;          /*       0x9c - 0xa0       */
  volatile u_int32_t BB_agc_timeout_1;            /*       0xa0 - 0xa4       */
  volatile u_int32_t BB_adcsat_ctrl_1;            /*       0xa4 - 0xa8       */
  volatile u_int32_t BB_adcsat_ctrl_2;            /*       0xa8 - 0xac       */
  volatile u_int32_t BB_agc_spare_01;             /*       0xac - 0xb0       */
  volatile u_int32_t BB_agc_ht_stf_ctrl_1;        /*       0xb0 - 0xb4       */
  volatile u_int32_t BB_agc_ht_stf_ctrl_2;        /*       0xb4 - 0xb8       */
  volatile u_int32_t BB_agc_ht_stf_ctrl_3;        /*       0xb8 - 0xbc       */
  volatile u_int32_t BB_radar_lb_control;         /*       0xbc - 0xc0       */
  volatile u_int32_t BB_radar_pulse_thres1;       /*       0xc0 - 0xc4       */
  volatile u_int32_t BB_radar_pulse_thres2;       /*       0xc4 - 0xc8       */
  volatile u_int32_t BB_ss_gain_ctrl_1;           /*       0xc8 - 0xcc       */
  volatile u_int32_t BB_ob_chirp_ctrl;            /*       0xcc - 0xd0       */
  volatile u_int32_t BB_agc_rtt_ctrl;             /*       0xd0 - 0xd4       */
  volatile unsigned int pad__1[0x27];             /*       0xd4 - 0x170      */
  volatile u_int32_t BB_rx_gain_nf_en;            /*      0x170 - 0x174      */
  volatile unsigned int pad__2[0x3];              /*      0x174 - 0x180      */
  volatile u_int32_t BB_rssi_b0;                  /*      0x180 - 0x184      */
  volatile unsigned int pad__3;                   /*      0x184 - 0x188      */
  volatile u_int32_t BB_agc_dig_dc_status_b0;     /*      0x188 - 0x18c      */
  volatile unsigned int pad__4[0x5];              /*      0x18c - 0x1a0      */
  volatile u_int32_t BB_dc_cal_status_b0;         /*      0x1a0 - 0x1a4      */
  volatile u_int32_t BB_dc_cal_status_2_b0;       /*      0x1a4 - 0x1a8      */
  volatile u_int32_t BB_dc_cal_status_3_b0;       /*      0x1a8 - 0x1ac      */
  volatile u_int32_t BB_dc_cal_status_4_b0;       /*      0x1ac - 0x1b0      */
  volatile u_int32_t BB_rx_gain_nf_b0;            /*      0x1b0 - 0x1b4      */
  volatile unsigned int pad__5[0x3];              /*      0x1b4 - 0x1c0      */
  volatile u_int32_t BB_bbb_sig_detect;           /*      0x1c0 - 0x1c4      */
  volatile u_int32_t BB_bbb_dagc_ctrl;            /*      0x1c4 - 0x1c8      */
  volatile u_int32_t BB_iqcorr_ctrl_cck;          /*      0x1c8 - 0x1cc      */
  volatile u_int32_t BB_cck_spur_mit;             /*      0x1cc - 0x1d0      */
  volatile u_int32_t BB_mrc_cck_ctrl;             /*      0x1d0 - 0x1d4      */
  volatile u_int32_t BB_cck_blocker_det;          /*      0x1d4 - 0x1d8      */
  volatile u_int32_t BB_bk_corr_settings;         /*      0x1d8 - 0x1dc      */
  volatile unsigned int pad__6;                   /*      0x1dc - 0x1e0      */
  volatile u_int32_t BB_cck_blocker_det2;         /*      0x1e0 - 0x1e4      */
  volatile u_int32_t BB_detection_mask_cntl;      /*      0x1e4 - 0x1e8      */
  volatile unsigned int pad__7[0x6];              /*      0x1e8 - 0x200      */
  volatile u_int32_t BB_rx_ocgain[128];           /*      0x200 - 0x400      */
};

struct chn_reg_map {
  volatile u_int32_t BB_timing_controls_1;        /*        0x0 - 0x4        */
  volatile u_int32_t BB_timing_controls_2;        /*        0x4 - 0x8        */
  volatile u_int32_t BB_timing_controls_3;        /*        0x8 - 0xc        */
  volatile u_int32_t BB_timing_control_4;         /*        0xc - 0x10       */
  volatile u_int32_t BB_timing_control_5;         /*       0x10 - 0x14       */
  volatile u_int32_t BB_timing_control_6;         /*       0x14 - 0x18       */
  volatile u_int32_t BB_timing_control_11;        /*       0x18 - 0x1c       */
  volatile u_int32_t BB_spur_mask_controls;       /*       0x1c - 0x20       */
  volatile u_int32_t BB_find_signal_low;          /*       0x20 - 0x24       */
  volatile u_int32_t BB_sfcorr;                   /*       0x24 - 0x28       */
  volatile u_int32_t BB_self_corr_low;            /*       0x28 - 0x2c       */
  volatile unsigned int pad__0;                   /*       0x2c - 0x30       */
  volatile u_int32_t BB_timing_control_13;        /*       0x30 - 0x34       */
  volatile u_int32_t BB_radar_detection;          /*       0x34 - 0x38       */
  volatile u_int32_t BB_radar_detection_2;        /*       0x38 - 0x3c       */
  volatile u_int32_t BB_extension_radar;          /*       0x3c - 0x40       */
  volatile u_int32_t BB_ibf_ctrl;                 /*       0x40 - 0x44       */
  volatile unsigned int pad__1[0x3];              /*       0x44 - 0x50       */
  volatile u_int32_t BB_chn_spare_01;             /*       0x50 - 0x54       */
  volatile u_int32_t BB_timing_controls_2a;       /*       0x54 - 0x58       */
  volatile u_int32_t BB_rx_notch_cntl_2_pri_b0;   /*       0x58 - 0x5c       */
  volatile u_int32_t BB_rx_notch_cntl_3_pri_b0;   /*       0x5c - 0x60       */
  volatile u_int32_t BB_rx_notch_cntl_4_pri_b0;   /*       0x60 - 0x64       */
  volatile u_int32_t BB_rx_notch_cntl_5_pri_b0;   /*       0x64 - 0x68       */
  volatile u_int32_t BB_rx_notch_cntl_2_ext_b0;   /*       0x68 - 0x6c       */
  volatile u_int32_t BB_rx_notch_cntl_3_ext_b0;   /*       0x6c - 0x70       */
  volatile u_int32_t BB_rx_notch_cntl_4_ext_b0;   /*       0x70 - 0x74       */
  volatile u_int32_t BB_rx_notch_cntl_5_ext_b0;   /*       0x74 - 0x78       */
  volatile unsigned int pad__2[0x2];              /*       0x78 - 0x80       */
  volatile u_int32_t BB_multichain_control;       /*       0x80 - 0x84       */
  volatile u_int32_t BB_per_chain_ht_csd;         /*       0x84 - 0x88       */
  volatile u_int32_t BB_pre_emphasis_bw20_b0;     /*       0x88 - 0x8c       */
  volatile u_int32_t BB_pre_emphasis_bw40_b0;     /*       0x8c - 0x90       */
  volatile u_int32_t BB_pre_emphasis_bw80_b0;     /*       0x90 - 0x94       */
  volatile u_int32_t BB_chn_tables_intf_addr;     /*       0x94 - 0x98       */
  volatile u_int32_t BB_chn_tables_intf_data;     /*       0x98 - 0x9c       */
  volatile u_int32_t BB_phydbg_control1;          /*       0x9c - 0xa0       */
  volatile u_int32_t BB_phydbg_control2;          /*       0xa0 - 0xa4       */
  volatile u_int32_t BB_tstdac_constant;          /*       0xa4 - 0xa8       */
  volatile u_int32_t BB_spur_report_b0;           /*       0xa8 - 0xac       */
  volatile unsigned int pad__3[0x4];              /*       0xac - 0xbc       */
  volatile u_int32_t BB_green_tx_control_1;       /*       0xbc - 0xc0       */
  volatile u_int32_t BB_iq_adc_meas_0_b0;         /*       0xc0 - 0xc4       */
  volatile u_int32_t BB_iq_adc_meas_1_b0;         /*       0xc4 - 0xc8       */
  volatile u_int32_t BB_iq_adc_meas_2_b0;         /*       0xc8 - 0xcc       */
  volatile u_int32_t BB_iq_adc_meas_3_b0;         /*       0xcc - 0xd0       */
  volatile u_int32_t BB_tx_phase_ramp_b0;         /*       0xd0 - 0xd4       */
  volatile u_int32_t BB_adc_gain_corr_b0;         /*       0xd4 - 0xd8       */
  volatile u_int32_t BB_adc_dc_corr_b0;           /*       0xd8 - 0xdc       */
  volatile u_int32_t BB_rx_iq_corr_b0;            /*       0xdc - 0xe0       */
  volatile u_int32_t BB_rx_iq_corr_loopback_b0;   /*       0xe0 - 0xe4       */
  volatile u_int32_t BB_paprd_am2am_mask;         /*       0xe4 - 0xe8       */
  volatile u_int32_t BB_paprd_am2pm_mask;         /*       0xe8 - 0xec       */
  volatile u_int32_t BB_paprd_ht40_mask;          /*       0xec - 0xf0       */
  volatile u_int32_t BB_paprd_ctrl0_b0;           /*       0xf0 - 0xf4       */
  volatile u_int32_t BB_paprd_ctrl1_b0;           /*       0xf4 - 0xf8       */
  volatile u_int32_t BB_paprd_ctrl2_b0;           /*       0xf8 - 0xfc       */
  volatile u_int32_t BB_paprd_vht80_mask;         /*       0xfc - 0x100      */
  volatile u_int32_t BB_phydbg_mem_addr;          /*      0x100 - 0x104      */
  volatile u_int32_t BB_phydbg_mem_data;          /*      0x104 - 0x108      */
  volatile u_int32_t BB_btcf_config;              /*      0x108 - 0x10c      */
  volatile u_int32_t BB_btcf_th_config;           /*      0x10c - 0x110      */
  volatile u_int32_t BB_btcf_dcn_config;          /*      0x110 - 0x114      */
  volatile u_int32_t BB_btcf_tim_cpature;         /*      0x114 - 0x118      */
  volatile u_int32_t BB_btcf_idx_cpature;         /*      0x118 - 0x11c      */
  volatile u_int32_t BB_btcf_fftstartstore;       /*      0x11c - 0x120      */
  volatile unsigned int pad__4[0x2];              /*      0x120 - 0x128      */
  volatile u_int32_t BB_btcf_pwr_atmin_169;       /*      0x128 - 0x12c      */
  volatile u_int32_t BB_bcf_offscnt_atmin_169;    /*      0x12c - 0x130      */
  volatile u_int32_t BB_btcf_abort_cnt;           /*      0x130 - 0x134      */
  volatile unsigned int pad__5;                   /*      0x134 - 0x138      */
  volatile u_int32_t BB_bcf_minstore_br1;         /*      0x138 - 0x13c      */
  volatile u_int32_t BB_bcf_minstore_br2;         /*      0x13c - 0x140      */
  volatile u_int32_t BB_tx_overlap_window;        /*      0x140 - 0x144      */
  volatile u_int32_t BB_per_chain_legacy_csd;     /*      0x144 - 0x148      */
  volatile u_int32_t BB_fdtg_control0;            /*      0x148 - 0x14c      */
  volatile u_int32_t BB_fdtg_control1;            /*      0x14c - 0x150      */
  volatile u_int32_t BB_fdtg_ss0_data_b0;         /*      0x150 - 0x154      */
  volatile u_int32_t BB_fdtg_ss1_data_b0;         /*      0x154 - 0x158      */
  volatile u_int32_t BB_fdtg_ss2_data_b0;         /*      0x158 - 0x15c      */
  volatile u_int32_t BB_paprd_am2am_mask2;        /*      0x15c - 0x160      */
  volatile u_int32_t BB_paprd_am2pm_mask2;        /*      0x160 - 0x164      */
  volatile u_int32_t BB_paprd_ht40_mask2;         /*      0x164 - 0x168      */
  volatile u_int32_t BB_paprd_vht80_mask2;        /*      0x168 - 0x16c      */
  volatile u_int32_t BB_spur_ctrl1_pri_b0;        /*      0x16c - 0x170      */
  volatile u_int32_t BB_spur_ctrl2_pri_b0;        /*      0x170 - 0x174      */
  volatile u_int32_t BB_spur_ctrl1_ext_b0;        /*      0x174 - 0x178      */
  volatile u_int32_t BB_spur_ctrl2_ext_b0;        /*      0x178 - 0x17c      */
  volatile u_int32_t BB_fdtg_ss3_data_b0;         /*      0x17c - 0x180      */
  volatile u_int32_t BB_fdtg_control2;            /*      0x180 - 0x184      */
  volatile u_int32_t BB_pdc_a1_0_m0;              /*      0x184 - 0x188      */
  volatile u_int32_t BB_pdc_b1_0_m0;              /*      0x188 - 0x18c      */
  volatile u_int32_t BB_pdc_b2_0_m0;              /*      0x18c - 0x190      */
  volatile u_int32_t BB_pdc_a1_0_m1;              /*      0x190 - 0x194      */
  volatile u_int32_t BB_pdc_b1_0_m1;              /*      0x194 - 0x198      */
  volatile u_int32_t BB_pdc_b2_0_m1;              /*      0x198 - 0x19c      */
  volatile u_int32_t BB_pdc_a1_0_m2;              /*      0x19c - 0x1a0      */
  volatile u_int32_t BB_pdc_b1_0_m2;              /*      0x1a0 - 0x1a4      */
  volatile u_int32_t BB_pdc_b2_0_m2;              /*      0x1a4 - 0x1a8      */
  volatile u_int32_t BB_pdc_step_p1_0;            /*      0x1a8 - 0x1ac      */
  volatile u_int32_t BB_pdc_step_p2_0;            /*      0x1ac - 0x1b0      */
  volatile u_int32_t BB_pdc_gap_time_0;           /*      0x1b0 - 0x1b4      */
  volatile u_int32_t BB_pdc_time_0;               /*      0x1b4 - 0x1b8      */
  volatile u_int32_t BB_pdc_disable;              /*      0x1b8 - 0x1bc      */
  volatile u_int32_t BB_pdc_num_p1_max;           /*      0x1bc - 0x1c0      */
  volatile u_int32_t BB_pdc_num_p2_max;           /*      0x1c0 - 0x1c4      */
  volatile u_int32_t BB_pdc_gap_th1;              /*      0x1c4 - 0x1c8      */
  volatile u_int32_t BB_pdc_gap_th2;              /*      0x1c8 - 0x1cc      */
  volatile u_int32_t BB_pdc_dly_tl;               /*      0x1cc - 0x1d0      */
  volatile u_int32_t BB_pdc_gap_tl;               /*      0x1d0 - 0x1d4      */
  volatile u_int32_t BB_pdc_tl;                   /*      0x1d4 - 0x1d8      */
  volatile u_int32_t BB_pdc_num_step_p1;          /*      0x1d8 - 0x1dc      */
};

struct sm_reg_map {
  volatile unsigned int pad__0;                   /*        0x0 - 0x4        */
  volatile u_int32_t BB_gen_controls;             /*        0x4 - 0x8        */
  volatile u_int32_t BB_modes_select;             /*        0x8 - 0xc        */
  volatile u_int32_t BB_active;                   /*        0xc - 0x10       */
  volatile u_int32_t BB_spare_01;                 /*       0x10 - 0x14       */
  volatile unsigned int pad__1[0x5];              /*       0x14 - 0x28       */
  volatile u_int32_t BB_spectral_scan;            /*       0x28 - 0x2c       */
  volatile unsigned int pad__2;                   /*       0x2c - 0x30       */
  volatile u_int32_t BB_search_start_delay;       /*       0x30 - 0x34       */
  volatile u_int32_t BB_max_rx_length;            /*       0x34 - 0x38       */
  volatile u_int32_t BB_frame_control;            /*       0x38 - 0x3c       */
  volatile u_int32_t BB_rfbus_request;            /*       0x3c - 0x40       */
  volatile u_int32_t BB_rfbus_grant;              /*       0x40 - 0x44       */
  volatile u_int32_t BB_rifs;                     /*       0x44 - 0x48       */
  volatile u_int32_t BB_pmi_debug_status;         /*       0x48 - 0x4c       */
  volatile unsigned int pad__3;                   /*       0x4c - 0x50       */
  volatile u_int32_t BB_rx_clear_delay;           /*       0x50 - 0x54       */
  volatile u_int32_t BB_analog_power_on_time;     /*       0x54 - 0x58       */
  volatile u_int32_t BB_tx_timing_1;              /*       0x58 - 0x5c       */
  volatile u_int32_t BB_tx_timing_2;              /*       0x5c - 0x60       */
  volatile u_int32_t BB_tx_timing_3;              /*       0x60 - 0x64       */
  volatile u_int32_t BB_xpa_timing_control;       /*       0x64 - 0x68       */
  volatile u_int32_t BB_warm_tx;                  /*       0x68 - 0x6c       */
  volatile u_int32_t BB_en_power_optim;           /*       0x6c - 0x70       */
  volatile unsigned int pad__4[0x4];              /*       0x70 - 0x80       */
  volatile u_int32_t BB_misc_pa_control;          /*       0x80 - 0x84       */
  volatile u_int32_t BB_switch_table_chn_b0;      /*       0x84 - 0x88       */
  volatile u_int32_t BB_switch_table_com1;        /*       0x88 - 0x8c       */
  volatile u_int32_t BB_switch_table_com2;        /*       0x8c - 0x90       */
  volatile unsigned int pad__5[0x4];              /*       0x90 - 0xa0       */
  volatile u_int32_t BB_multichain_enable;        /*       0xa0 - 0xa4       */
  volatile u_int32_t BB_rx_notch_cntl_0;          /*       0xa4 - 0xa8       */
  volatile u_int32_t BB_rx_notch_cntl_1;          /*       0xa8 - 0xac       */
  volatile unsigned int pad__6[0x4];              /*       0xac - 0xbc       */
  volatile u_int32_t BB_vht160mode_debug;         /*       0xbc - 0xc0       */
  volatile u_int32_t BB_cal_chain_mask;           /*       0xc0 - 0xc4       */
  volatile u_int32_t BB_agc_control;              /*       0xc4 - 0xc8       */
  volatile u_int32_t BB_iq_adc_cal_mode;          /*       0xc8 - 0xcc       */
  volatile u_int32_t BB_fcal_1;                   /*       0xcc - 0xd0       */
  volatile u_int32_t BB_fcal_2_b0;                /*       0xd0 - 0xd4       */
  volatile u_int32_t BB_dft_tone_ctrl_b0;         /*       0xd4 - 0xd8       */
  volatile u_int32_t BB_cl_cal_ctrl;              /*       0xd8 - 0xdc       */
  volatile u_int32_t BB_cl_map_0_b0;              /*       0xdc - 0xe0       */
  volatile u_int32_t BB_cl_map_1_b0;              /*       0xe0 - 0xe4       */
  volatile u_int32_t BB_cl_map_2_b0;              /*       0xe4 - 0xe8       */
  volatile u_int32_t BB_cl_map_3_b0;              /*       0xe8 - 0xec       */
  volatile unsigned int pad__7[0x5];              /*       0xec - 0x100      */
  volatile u_int32_t BB_cl_tab_b0[16];            /*      0x100 - 0x140      */
  volatile u_int32_t BB_synth_control;            /*      0x140 - 0x144      */
  volatile u_int32_t BB_addac_clk_select;         /*      0x144 - 0x148      */
  volatile u_int32_t BB_pll_cntl;                 /*      0x148 - 0x14c      */
  volatile u_int32_t BB_analog_swap;              /*      0x14c - 0x150      */
  volatile u_int32_t BB_addac_parallel_control;   /*      0x150 - 0x154      */
  volatile u_int32_t BB_force_clock;              /*      0x154 - 0x158      */
  volatile u_int32_t BB_force_analog;             /*      0x158 - 0x15c      */
  volatile u_int32_t BB_force_ss_ctrl;            /*      0x15c - 0x160      */
  volatile u_int32_t BB_test_controls;            /*      0x160 - 0x164      */
  volatile u_int32_t BB_test_controls_status;     /*      0x164 - 0x168      */
  volatile u_int32_t BB_tstdac;                   /*      0x168 - 0x16c      */
  volatile u_int32_t BB_channel_status;           /*      0x16c - 0x170      */
  volatile u_int32_t BB_chaninfo_ctrl;            /*      0x170 - 0x174      */
  volatile u_int32_t BB_chan_info_noise_pwr_b0;   /*      0x174 - 0x178      */
  volatile u_int32_t BB_chan_info_gain_diff;      /*      0x178 - 0x17c      */
  volatile u_int32_t BB_chan_info_fine_timing;    /*      0x17c - 0x180      */
  volatile u_int32_t BB_chan_info_gain_b0;        /*      0x180 - 0x184      */
  volatile u_int32_t BB_rtt_corr_value;           /*      0x184 - 0x188      */
  volatile u_int32_t BB_nf_dcoff_b0;              /*      0x188 - 0x18c      */
  volatile u_int32_t BB_chan_info_fine_ppm;       /*      0x18c - 0x190      */
  volatile u_int32_t BB_scrambler_seed;           /*      0x190 - 0x194      */
  volatile u_int32_t BB_bbb_tx_ctrl;              /*      0x194 - 0x198      */
  volatile u_int32_t BB_bbb_txfir_0;              /*      0x198 - 0x19c      */
  volatile u_int32_t BB_bbb_txfir_1;              /*      0x19c - 0x1a0      */
  volatile u_int32_t BB_bbb_txfir_2;              /*      0x1a0 - 0x1a4      */
  volatile u_int32_t BB_heavy_clip_0;             /*      0x1a4 - 0x1a8      */
  volatile u_int32_t BB_heavy_clip_1;             /*      0x1a8 - 0x1ac      */
  volatile u_int32_t BB_heavy_clip_2;             /*      0x1ac - 0x1b0      */
  volatile u_int32_t BB_heavy_clip_3;             /*      0x1b0 - 0x1b4      */
  volatile u_int32_t BB_sm_hist_0;                /*      0x1b4 - 0x1b8      */
  volatile u_int32_t BB_sm_hist_1;                /*      0x1b8 - 0x1bc      */
  volatile u_int32_t BB_rtt_cntl;                 /*      0x1bc - 0x1c0      */
  volatile u_int32_t BB_heavy_clip_4;             /*      0x1c0 - 0x1c4      */
  volatile u_int32_t BB_heavy_clip_5;             /*      0x1c4 - 0x1c8      */
  volatile u_int32_t BB_heavy_clip_6;             /*      0x1c8 - 0x1cc      */
  volatile u_int32_t BB_heavy_clip_7;             /*      0x1cc - 0x1d0      */
  volatile u_int32_t BB_rtt_pbd_stat;             /*      0x1d0 - 0x1d4      */
  volatile u_int32_t BB_rtt_location_pri80;       /*      0x1d4 - 0x1d8      */
  volatile unsigned int pad__8;                   /*      0x1d8 - 0x1dc      */
  volatile u_int32_t BB_rtt_tx_phase;             /*      0x1dc - 0x1e0      */
  volatile unsigned int pad__9[0x4];              /*      0x1e0 - 0x1f0      */
  volatile u_int32_t BB_powertx_max_sub;          /*      0x1f0 - 0x1f4      */
  volatile unsigned int pad__10;                  /*      0x1f4 - 0x1f8      */
  volatile u_int32_t BB_tpc_1;                    /*      0x1f8 - 0x1fc      */
  volatile u_int32_t BB_tpc_2;                    /*      0x1fc - 0x200      */
  volatile u_int32_t BB_tpc_3;                    /*      0x200 - 0x204      */
  volatile u_int32_t BB_tpc_4_b0;                 /*      0x204 - 0x208      */
  volatile u_int32_t BB_tpc_5;                    /*      0x208 - 0x20c      */
  volatile u_int32_t BB_tpc_6;                    /*      0x20c - 0x210      */
  volatile u_int32_t BB_tpc_7;                    /*      0x210 - 0x214      */
  volatile u_int32_t BB_tpc_8;                    /*      0x214 - 0x218      */
  volatile u_int32_t BB_tpc_9;                    /*      0x218 - 0x21c      */
  volatile u_int32_t BB_tpc_10;                   /*      0x21c - 0x220      */
  volatile u_int32_t BB_tpc_11_b0;                /*      0x220 - 0x224      */
  volatile u_int32_t BB_tpc_12_b0;                /*      0x224 - 0x228      */
  volatile u_int32_t BB_tpc_13;                   /*      0x228 - 0x22c      */
  volatile u_int32_t BB_tpc_14;                   /*      0x22c - 0x230      */
  volatile u_int32_t BB_tpc_15;                   /*      0x230 - 0x234      */
  volatile unsigned int pad__11;                  /*      0x234 - 0x238      */
  volatile u_int32_t BB_tpc_17;                   /*      0x238 - 0x23c      */
  volatile u_int32_t BB_tpc_18;                   /*      0x23c - 0x240      */
  volatile u_int32_t BB_tpc_19_b0;                /*      0x240 - 0x244      */
  volatile unsigned int pad__12;                  /*      0x244 - 0x248      */
  volatile u_int32_t BB_therm_adc_1_b0;           /*      0x248 - 0x24c      */
  volatile u_int32_t BB_therm_adc_2;              /*      0x24c - 0x250      */
  volatile u_int32_t BB_therm_adc_3_b0;           /*      0x250 - 0x254      */
  volatile u_int32_t BB_therm_adc_4_b0;           /*      0x254 - 0x258      */
  volatile u_int32_t BB_tx_forced_gain;           /*      0x258 - 0x25c      */
  volatile u_int32_t BB_tpc_stat_0_b0;            /*      0x25c - 0x260      */
  volatile u_int32_t BB_tpc_stat_1_b0;            /*      0x260 - 0x264      */
  volatile u_int32_t BB_tpc_stat_2_b0;            /*      0x264 - 0x268      */
  volatile u_int32_t BB_tpc_max_mu_dac;           /*      0x268 - 0x26c      */
  volatile u_int32_t BB_tpc_min_mu_dac;           /*      0x26c - 0x270      */
  volatile u_int32_t BB_tpc_mu_ctrl;              /*      0x270 - 0x274      */
  volatile u_int32_t BB_tpc_stat_3_b0;            /*      0x274 - 0x278      */
  volatile u_int32_t BB_tpc_20;                   /*      0x278 - 0x27c      */
  volatile u_int32_t BB_tpc_21;                   /*      0x27c - 0x280      */
  volatile u_int32_t BB_tpc_22;                   /*      0x280 - 0x284      */
  volatile u_int32_t BB_tpc_23;                   /*      0x284 - 0x288      */
  volatile u_int32_t BB_tbtpa_en;                 /*      0x288 - 0x28c      */
  volatile u_int32_t BB_tbtpa_mode;               /*      0x28c - 0x290      */
  volatile u_int32_t BB_mcs_mask;                 /*      0x290 - 0x294      */
  volatile u_int32_t BB_tempthr;                  /*      0x294 - 0x298      */
  volatile u_int32_t BB_pwrthr;                   /*      0x298 - 0x29c      */
  volatile u_int32_t BB_betam;                    /*      0x29c - 0x2a0      */
  volatile u_int32_t BB_max_target_power_adjust;  /*      0x2a0 - 0x2a4      */
  volatile u_int32_t BB_pkttimeout_high;          /*      0x2a4 - 0x2a8      */
  volatile u_int32_t BB_therm_mask;               /*      0x2a8 - 0x2ac      */
  volatile u_int32_t BB_alpha_therm0;             /*      0x2ac - 0x2b0      */
  volatile unsigned int pad__13;                  /*      0x2b0 - 0x2b4      */
  volatile u_int32_t BB_alpha_therm1;             /*      0x2b4 - 0x2b8      */
  volatile u_int32_t BB_alpha_therm2;             /*      0x2b8 - 0x2bc      */
  volatile u_int32_t BB_sec80_alpha_therm0;       /*      0x2bc - 0x2c0      */
  volatile u_int32_t BB_sec80_alpha_therm1;       /*      0x2c0 - 0x2c4      */
  volatile u_int32_t BB_sec80_alpha_therm2;       /*      0x2c4 - 0x2c8      */
  volatile u_int32_t BB_fcs_alpha_therm0;         /*      0x2c8 - 0x2cc      */
  volatile u_int32_t BB_fcs_alpha_therm1;         /*      0x2cc - 0x2d0      */
  volatile u_int32_t BB_fcs_alpha_therm2;         /*      0x2d0 - 0x2d4      */
  volatile u_int32_t BB_pkttimeout_mid;           /*      0x2d4 - 0x2d8      */
  volatile u_int32_t BB_power_offset0;            /*      0x2d8 - 0x2dc      */
  volatile u_int32_t BB_power_offset1;            /*      0x2dc - 0x2e0      */
  volatile u_int32_t BB_power_offset2;            /*      0x2e0 - 0x2e4      */
  volatile u_int32_t BB_sec80_power_offset0;      /*      0x2e4 - 0x2e8      */
  volatile u_int32_t BB_sec80_power_offset1;      /*      0x2e8 - 0x2ec      */
  volatile u_int32_t BB_sec80_power_offset2;      /*      0x2ec - 0x2f0      */
  volatile u_int32_t BB_fcs_power_offset0;        /*      0x2f0 - 0x2f4      */
  volatile u_int32_t BB_fcs_power_offset1;        /*      0x2f4 - 0x2f8      */
  volatile u_int32_t BB_fcs_power_offset2;        /*      0x2f8 - 0x2fc      */
  volatile u_int32_t BB_estimated_therm;          /*      0x2fc - 0x300      */
  volatile u_int32_t BB_tx_clken_stagger_ctrl;    /*      0x300 - 0x304      */
  volatile unsigned int pad__14[0x1f];            /*      0x304 - 0x380      */
  volatile u_int32_t BB_rrt_ctrl;                 /*      0x380 - 0x384      */
  volatile u_int32_t BB_rrt_table_sw_intf_b0;     /*      0x384 - 0x388      */
  volatile u_int32_t BB_rrt_table_sw_intf_1_b0;   /*      0x388 - 0x38c      */
  volatile unsigned int pad__15[0x2e];            /*      0x38c - 0x444      */
  volatile u_int32_t BB_txiqcal_control_0;        /*      0x444 - 0x448      */
  volatile u_int32_t BB_txiqcal_control_1;        /*      0x448 - 0x44c      */
  volatile u_int32_t BB_txiqcal_control_2;        /*      0x44c - 0x450      */
  volatile u_int32_t BB_txiqcal_control_3;        /*      0x450 - 0x454      */
  volatile u_int32_t BB_txiqcal_control_4;        /*      0x454 - 0x458      */
  volatile unsigned int pad__16[0x6];             /*      0x458 - 0x470      */
  volatile u_int32_t BB_cal_rxbb_gain_tbl_0;      /*      0x470 - 0x474      */
  volatile u_int32_t BB_cal_rxbb_gain_tbl_4;      /*      0x474 - 0x478      */
  volatile u_int32_t BB_cal_rxbb_gain_tbl_8;      /*      0x478 - 0x47c      */
  volatile u_int32_t BB_cal_rxbb_gain_tbl_12;     /*      0x47c - 0x480      */
  volatile u_int32_t BB_cal_rxbb_gain_tbl_16;     /*      0x480 - 0x484      */
  volatile u_int32_t BB_cal_rxbb_gain_tbl_20;     /*      0x484 - 0x488      */
  volatile u_int32_t BB_cal_rxbb_gain_tbl_24;     /*      0x488 - 0x48c      */
  volatile u_int32_t BB_txiqcal_status_b0;        /*      0x48c - 0x490      */
  volatile u_int32_t BB_cal_rxbb_tia_gain_tbl_1;  /*      0x490 - 0x494      */
  volatile u_int32_t BB_cal_rxbb_tia_gain_tbl_2;  /*      0x494 - 0x498      */
  volatile unsigned int pad__17[0x5];             /*      0x498 - 0x4ac      */
  volatile u_int32_t BB_rxiqcal_status_b0;        /*      0x4ac - 0x4b0      */
  volatile unsigned int pad__18[0x8];             /*      0x4b0 - 0x4d0      */
  volatile u_int32_t BB_hsprd_train_cntl_0;       /*      0x4d0 - 0x4d4      */
  volatile unsigned int pad__19[0x6];             /*      0x4d4 - 0x4ec      */
  volatile u_int32_t BB_pefcal_cntl_0;            /*      0x4ec - 0x4f0      */
  volatile u_int32_t BB_pefcal_cntl_1;            /*      0x4f0 - 0x4f4      */
  volatile u_int32_t BB_pefcal_cntl_2;            /*      0x4f4 - 0x4f8      */
  volatile u_int32_t BB_preemp_cntl_0;            /*      0x4f8 - 0x4fc      */
  volatile u_int32_t BB_preemp_cntl_1;            /*      0x4fc - 0x500      */
  volatile u_int32_t BB_paprd_bw_cntl_0;          /*      0x500 - 0x504      */
  volatile u_int32_t BB_rxiqcal_control_0;        /*      0x504 - 0x508      */
  volatile u_int32_t BB_tx_notch_cntl_0;          /*      0x508 - 0x50c      */
  volatile unsigned int pad__20;                  /*      0x50c - 0x510      */
  volatile u_int32_t BB_dbg_mask_agc;             /*      0x510 - 0x514      */
  volatile u_int32_t BB_dbg_mask_rxsm;            /*      0x514 - 0x518      */
  volatile u_int32_t BB_dbg_mask_txsm;            /*      0x518 - 0x51c      */
  volatile u_int32_t BB_dbg_mask_tctl;            /*      0x51c - 0x520      */
  volatile u_int32_t BB_dbg_mask_vit;             /*      0x520 - 0x524      */
  volatile u_int32_t BB_dbg_mask_dfs;             /*      0x524 - 0x528      */
  volatile u_int32_t BB_dbg_mask_cal;             /*      0x528 - 0x52c      */
  volatile u_int32_t BB_dbg_mask_tpc;             /*      0x52c - 0x530      */
  volatile u_int32_t BB_dbg_mask_svd;             /*      0x530 - 0x534      */
  volatile u_int32_t BB_dbg_mask_mpi;             /*      0x534 - 0x538      */
  volatile u_int32_t BB_dbg_mask_pmi;             /*      0x538 - 0x53c      */
  volatile u_int32_t BB_dbg_bus_sel_sm;           /*      0x53c - 0x540      */
  volatile u_int32_t BB_txa_state_history;        /*      0x540 - 0x544      */
  volatile u_int32_t BB_txb_state_history;        /*      0x544 - 0x548      */
  volatile u_int32_t BB_tlv_state_history;        /*      0x548 - 0x54c      */
  volatile unsigned int pad__21;                  /*      0x54c - 0x550      */
  volatile u_int32_t BB_ibfcal_rfcntl;            /*      0x550 - 0x554      */
  volatile u_int32_t BB_tpc_error_count;          /*      0x554 - 0x558      */
  volatile unsigned int pad__22;                  /*      0x558 - 0x55c      */
  volatile u_int32_t BB_rxsm_state_history;       /*      0x55c - 0x560      */
  volatile u_int32_t BB_rxsm_cck_state_history;   /*      0x560 - 0x564      */
  volatile u_int32_t BB_cntm_state_history;       /*      0x564 - 0x568      */
  volatile u_int32_t BB_agc_state_history;        /*      0x568 - 0x56c      */
  volatile u_int32_t BB_packet_counter_tx_legacy; /*      0x56c - 0x570      */
  volatile u_int32_t BB_packet_counter_tx_ht;     /*      0x570 - 0x574      */
  volatile u_int32_t BB_packet_counter_rx_legacy; /*      0x574 - 0x578      */
  volatile u_int32_t BB_packet_counter_rx_ht;     /*      0x578 - 0x57c      */
  volatile u_int32_t BB_packet_counter_mimo;      /*      0x57c - 0x580      */
  volatile u_int32_t BB_packet_counter_mu;        /*      0x580 - 0x584      */
  volatile u_int32_t BB_debug_register1;          /*      0x584 - 0x588      */
  volatile u_int32_t BB_debug_register2;          /*      0x588 - 0x58c      */
  volatile u_int32_t BB_debug_register3;          /*      0x58c - 0x590      */
  volatile unsigned int pad__23[0xc];             /*      0x590 - 0x5c0      */
  volatile u_int32_t BB_watchdog_status;          /*      0x5c0 - 0x5c4      */
  volatile u_int32_t BB_watchdog_ctrl_1;          /*      0x5c4 - 0x5c8      */
  volatile u_int32_t BB_watchdog_ctrl_2;          /*      0x5c8 - 0x5cc      */
  volatile u_int32_t BB_bluetooth_cntl;           /*      0x5cc - 0x5d0      */
  volatile unsigned int pad__24;                  /*      0x5d0 - 0x5d4      */
  volatile u_int32_t BB_phyonly_control;          /*      0x5d4 - 0x5d8      */
  volatile unsigned int pad__25;                  /*      0x5d8 - 0x5dc      */
  volatile u_int32_t BB_eco_ctrl;                 /*      0x5dc - 0x5e0      */
  volatile u_int32_t BB_watchdog_status_B;        /*      0x5e0 - 0x5e4      */
  volatile u_int32_t BB_tlv_ctrl1;                /*      0x5e4 - 0x5e8      */
  volatile u_int32_t BB_phy_rx_timeout;           /*      0x5e8 - 0x5ec      */
  volatile u_int32_t BB_tx_phase_dither;          /*      0x5ec - 0x5f0      */
  volatile u_int32_t BB_tables_intf_addr_b0;      /*      0x5f0 - 0x5f4      */
  volatile u_int32_t BB_tables_intf_data_b0;      /*      0x5f4 - 0x5f8      */
  volatile u_int32_t BB_watchdog_status_C;        /*      0x5f8 - 0x5fc      */
  volatile u_int32_t BB_watchdog_status_D;        /*      0x5fc - 0x600      */
};

struct rxb_reg_map {
  volatile u_int32_t BB_rxb_rx_reset;             /*        0x0 - 0x4        */
  volatile u_int32_t BB_rxb_rx_config_1;          /*        0x4 - 0x8        */
  volatile u_int32_t BB_rxb_rx_config_2;          /*        0x8 - 0xc        */
  volatile u_int32_t BB_rxb_rx_disables;          /*        0xc - 0x10       */
  volatile u_int32_t BB_rxb_rx_diversity_mode;    /*       0x10 - 0x14       */
  volatile u_int32_t BB_rxb_rx_ssfd_lsfd;         /*       0x14 - 0x18       */
  volatile u_int32_t BB_rxb_rx_sig_svc_errors;    /*       0x18 - 0x1c       */
  volatile u_int32_t BB_rxb_rx_crc_errors;        /*       0x1c - 0x20       */
  volatile u_int32_t BB_rxb_rx_bytes;             /*       0x20 - 0x24       */
  volatile u_int32_t BB_rxb_mpi_sof_eof;          /*       0x24 - 0x28       */
  volatile u_int32_t BB_rxb_start_abort;          /*       0x28 - 0x2c       */
  volatile u_int32_t BB_rxb_dynsel_ant0_ant1;     /*       0x2c - 0x30       */
  volatile u_int32_t BB_rxb_dynsel_ant2_ant3;     /*       0x30 - 0x34       */
  volatile u_int32_t BB_rxb_dynsel_all_ant;       /*       0x34 - 0x38       */
  volatile u_int32_t BB_force_clken_cck;          /*       0x38 - 0x3c       */
  volatile u_int32_t BB_rxb_spare_01;             /*       0x3c - 0x40       */
};

struct agc1_reg_map {
  volatile unsigned int pad__0;                   /*        0x0 - 0x4        */
  volatile u_int32_t BB_gain_force_max_gains_b1;  /*        0x4 - 0x8        */
  volatile unsigned int pad__1[0x4];              /*        0x8 - 0x18       */
  volatile u_int32_t BB_ext_atten_switch_ctl_b1;  /*       0x18 - 0x1c       */
  volatile u_int32_t BB_cca_b1;                   /*       0x1c - 0x20       */
  volatile u_int32_t BB_cca_ctrl_2_b1;            /*       0x20 - 0x24       */
  volatile u_int32_t BB_cca_ext80_b1;             /*       0x24 - 0x28       */
  volatile unsigned int pad__2[0x56];             /*       0x28 - 0x180      */
  volatile u_int32_t BB_rssi_b1;                  /*      0x180 - 0x184      */
  volatile unsigned int pad__3;                   /*      0x184 - 0x188      */
  volatile u_int32_t BB_agc_dig_dc_status_b1;     /*      0x188 - 0x18c      */
  volatile unsigned int pad__4[0x5];              /*      0x18c - 0x1a0      */
  volatile u_int32_t BB_dc_cal_status_b1;         /*      0x1a0 - 0x1a4      */
  volatile u_int32_t BB_dc_cal_status_2_b1;       /*      0x1a4 - 0x1a8      */
  volatile u_int32_t BB_dc_cal_status_3_b1;       /*      0x1a8 - 0x1ac      */
  volatile u_int32_t BB_dc_cal_status_4_b1;       /*      0x1ac - 0x1b0      */
  volatile u_int32_t BB_rx_gain_nf_b1;            /*      0x1b0 - 0x1b4      */
  volatile unsigned int pad__5[0x13];             /*      0x1b4 - 0x200      */
  volatile u_int32_t BB_rx_ocgain2[128];          /*      0x200 - 0x400      */
};

struct chn1_reg_map {
  volatile unsigned int pad__0[0x16];             /*        0x0 - 0x58       */
  volatile u_int32_t BB_rx_notch_cntl_2_pri_b1;   /*       0x58 - 0x5c       */
  volatile u_int32_t BB_rx_notch_cntl_3_pri_b1;   /*       0x5c - 0x60       */
  volatile u_int32_t BB_rx_notch_cntl_4_pri_b1;   /*       0x60 - 0x64       */
  volatile u_int32_t BB_rx_notch_cntl_5_pri_b1;   /*       0x64 - 0x68       */
  volatile u_int32_t BB_rx_notch_cntl_2_ext_b1;   /*       0x68 - 0x6c       */
  volatile u_int32_t BB_rx_notch_cntl_3_ext_b1;   /*       0x6c - 0x70       */
  volatile u_int32_t BB_rx_notch_cntl_4_ext_b1;   /*       0x70 - 0x74       */
  volatile u_int32_t BB_rx_notch_cntl_5_ext_b1;   /*       0x74 - 0x78       */
  volatile unsigned int pad__1[0x4];              /*       0x78 - 0x88       */
  volatile u_int32_t BB_pre_emphasis_bw20_b1;     /*       0x88 - 0x8c       */
  volatile u_int32_t BB_pre_emphasis_bw40_b1;     /*       0x8c - 0x90       */
  volatile u_int32_t BB_pre_emphasis_bw80_b1;     /*       0x90 - 0x94       */
  volatile u_int32_t BB_chn1_tables_intf_addr;    /*       0x94 - 0x98       */
  volatile u_int32_t BB_chn1_tables_intf_data;    /*       0x98 - 0x9c       */
  volatile unsigned int pad__2[0x3];              /*       0x9c - 0xa8       */
  volatile u_int32_t BB_spur_report_b1;           /*       0xa8 - 0xac       */
  volatile unsigned int pad__3[0x5];              /*       0xac - 0xc0       */
  volatile u_int32_t BB_iq_adc_meas_0_b1;         /*       0xc0 - 0xc4       */
  volatile u_int32_t BB_iq_adc_meas_1_b1;         /*       0xc4 - 0xc8       */
  volatile u_int32_t BB_iq_adc_meas_2_b1;         /*       0xc8 - 0xcc       */
  volatile u_int32_t BB_iq_adc_meas_3_b1;         /*       0xcc - 0xd0       */
  volatile u_int32_t BB_tx_phase_ramp_b1;         /*       0xd0 - 0xd4       */
  volatile u_int32_t BB_adc_gain_corr_b1;         /*       0xd4 - 0xd8       */
  volatile u_int32_t BB_adc_dc_corr_b1;           /*       0xd8 - 0xdc       */
  volatile unsigned int pad__4;                   /*       0xdc - 0xe0       */
  volatile u_int32_t BB_rx_iq_corr_loopback_b1;   /*       0xe0 - 0xe4       */
  volatile unsigned int pad__5[0x3];              /*       0xe4 - 0xf0       */
  volatile u_int32_t BB_paprd_ctrl0_b1;           /*       0xf0 - 0xf4       */
  volatile u_int32_t BB_paprd_ctrl1_b1;           /*       0xf4 - 0xf8       */
  volatile u_int32_t BB_paprd_ctrl2_b1;           /*       0xf8 - 0xfc       */
  volatile u_int32_t BB_paprd_ctrl0_sec80_b1;     /*       0xfc - 0x100      */
  volatile u_int32_t BB_paprd_ctrl2_sec80_b1;     /*      0x100 - 0x104      */
  volatile unsigned int pad__6[0x13];             /*      0x104 - 0x150      */
  volatile u_int32_t BB_fdtg_ss0_data_b1;         /*      0x150 - 0x154      */
  volatile u_int32_t BB_fdtg_ss1_data_b1;         /*      0x154 - 0x158      */
  volatile u_int32_t BB_fdtg_ss2_data_b1;         /*      0x158 - 0x15c      */
  volatile unsigned int pad__7[0x4];              /*      0x15c - 0x16c      */
  volatile u_int32_t BB_spur_ctrl1_pri_b1;        /*      0x16c - 0x170      */
  volatile u_int32_t BB_spur_ctrl2_pri_b1;        /*      0x170 - 0x174      */
  volatile u_int32_t BB_spur_ctrl1_ext_b1;        /*      0x174 - 0x178      */
  volatile u_int32_t BB_spur_ctrl2_ext_b1;        /*      0x178 - 0x17c      */
  volatile u_int32_t BB_fdtg_ss3_data_b1;         /*      0x17c - 0x180      */
  volatile unsigned int pad__8;                   /*      0x180 - 0x184      */
  volatile u_int32_t BB_pdc_a1_1_m0;              /*      0x184 - 0x188      */
  volatile u_int32_t BB_pdc_b1_1_m0;              /*      0x188 - 0x18c      */
  volatile u_int32_t BB_pdc_b2_1_m0;              /*      0x18c - 0x190      */
  volatile u_int32_t BB_pdc_a1_1_m1;              /*      0x190 - 0x194      */
  volatile u_int32_t BB_pdc_b1_1_m1;              /*      0x194 - 0x198      */
  volatile u_int32_t BB_pdc_b2_1_m1;              /*      0x198 - 0x19c      */
  volatile u_int32_t BB_pdc_a1_1_m2;              /*      0x19c - 0x1a0      */
  volatile u_int32_t BB_pdc_b1_1_m2;              /*      0x1a0 - 0x1a4      */
  volatile u_int32_t BB_pdc_b2_1_m2;              /*      0x1a4 - 0x1a8      */
  volatile u_int32_t BB_pdc_step_p1_1;            /*      0x1a8 - 0x1ac      */
  volatile u_int32_t BB_pdc_step_p2_1;            /*      0x1ac - 0x1b0      */
  volatile u_int32_t BB_pdc_gap_time_1;           /*      0x1b0 - 0x1b4      */
  volatile u_int32_t BB_pdc_time_1;               /*      0x1b4 - 0x1b8      */
};

struct sm1_reg_map {
  volatile unsigned int pad__0[0x21];             /*        0x0 - 0x84       */
  volatile u_int32_t BB_switch_table_chn_b1;      /*       0x84 - 0x88       */
  volatile unsigned int pad__1[0x12];             /*       0x88 - 0xd0       */
  volatile u_int32_t BB_fcal_2_b1;                /*       0xd0 - 0xd4       */
  volatile u_int32_t BB_dft_tone_ctrl_b1;         /*       0xd4 - 0xd8       */
  volatile unsigned int pad__2;                   /*       0xd8 - 0xdc       */
  volatile u_int32_t BB_cl_map_0_b1;              /*       0xdc - 0xe0       */
  volatile u_int32_t BB_cl_map_1_b1;              /*       0xe0 - 0xe4       */
  volatile u_int32_t BB_cl_map_2_b1;              /*       0xe4 - 0xe8       */
  volatile u_int32_t BB_cl_map_3_b1;              /*       0xe8 - 0xec       */
  volatile unsigned int pad__3[0x5];              /*       0xec - 0x100      */
  volatile u_int32_t BB_cl_tab_b1[16];            /*      0x100 - 0x140      */
  volatile unsigned int pad__4[0xd];              /*      0x140 - 0x174      */
  volatile u_int32_t BB_chan_info_noise_pwr_b1;   /*      0x174 - 0x178      */
  volatile unsigned int pad__5[0x2];              /*      0x178 - 0x180      */
  volatile u_int32_t BB_chan_info_gain_b1;        /*      0x180 - 0x184      */
  volatile unsigned int pad__6;                   /*      0x184 - 0x188      */
  volatile u_int32_t BB_nf_dcoff_b1;              /*      0x188 - 0x18c      */
  volatile unsigned int pad__7[0x1e];             /*      0x18c - 0x204      */
  volatile u_int32_t BB_tpc_4_b1;                 /*      0x204 - 0x208      */
  volatile unsigned int pad__8[0x6];              /*      0x208 - 0x220      */
  volatile u_int32_t BB_tpc_11_b1;                /*      0x220 - 0x224      */
  volatile u_int32_t BB_tpc_12_b1;                /*      0x224 - 0x228      */
  volatile unsigned int pad__9[0x6];              /*      0x228 - 0x240      */
  volatile u_int32_t BB_tpc_19_b1;                /*      0x240 - 0x244      */
  volatile unsigned int pad__10;                  /*      0x244 - 0x248      */
  volatile u_int32_t BB_therm_adc_1_b1;           /*      0x248 - 0x24c      */
  volatile unsigned int pad__11;                  /*      0x24c - 0x250      */
  volatile u_int32_t BB_therm_adc_3_b1;           /*      0x250 - 0x254      */
  volatile u_int32_t BB_therm_adc_4_b1;           /*      0x254 - 0x258      */
  volatile unsigned int pad__12;                  /*      0x258 - 0x25c      */
  volatile u_int32_t BB_tpc_stat_0_b1;            /*      0x25c - 0x260      */
  volatile u_int32_t BB_tpc_stat_1_b1;            /*      0x260 - 0x264      */
  volatile u_int32_t BB_tpc_stat_2_b1;            /*      0x264 - 0x268      */
  volatile unsigned int pad__13[0x3];             /*      0x268 - 0x274      */
  volatile u_int32_t BB_tpc_stat_3_b1;            /*      0x274 - 0x278      */
  volatile unsigned int pad__14[0x43];            /*      0x278 - 0x384      */
  volatile u_int32_t BB_rrt_table_sw_intf_b1;     /*      0x384 - 0x388      */
  volatile u_int32_t BB_rrt_table_sw_intf_1_b1;   /*      0x388 - 0x38c      */
  volatile unsigned int pad__15[0x40];            /*      0x38c - 0x48c      */
  volatile u_int32_t BB_txiqcal_status_b1;        /*      0x48c - 0x490      */
  volatile unsigned int pad__16[0x7];             /*      0x490 - 0x4ac      */
  volatile u_int32_t BB_rxiqcal_status_b1;        /*      0x4ac - 0x4b0      */
  volatile unsigned int pad__17[0x50];            /*      0x4b0 - 0x5f0      */
  volatile u_int32_t BB_tables_intf_addr_b1;      /*      0x5f0 - 0x5f4      */
  volatile u_int32_t BB_tables_intf_data_b1;      /*      0x5f4 - 0x5f8      */
};

struct agc4_reg_map {
  volatile u_int32_t BB_dummy_agc_bcast[128];     /*        0x0 - 0x200      */
};

struct chn4_reg_map {
  volatile u_int32_t BB_dummy_chn_bcast[64];      /*        0x0 - 0x100      */
};

struct sm4_reg_map {
  volatile u_int32_t BB_dummy_sm_bcast[384];      /*        0x0 - 0x600      */
};

struct svd_reg_map {
  volatile u_int32_t BB_TXBF_DBG;                 /*        0x0 - 0x4        */
  volatile u_int32_t BB_TXBF;                     /*        0x4 - 0x8        */
  volatile u_int32_t BB_txbf_premmse_ctrl;        /*        0x8 - 0xc        */
  volatile u_int32_t BB_txbf_premmse_snr;         /*        0xc - 0x10       */
  volatile u_int32_t BB_txbf_bfee_rx_ctrl;        /*       0x10 - 0x14       */
  volatile u_int32_t BB_txbf_implicit_rx_ctrl;    /*       0x14 - 0x18       */
  volatile unsigned int pad__0[0x3a];             /*       0x18 - 0x100      */
  volatile u_int32_t BB_TXBF_SM;                  /*      0x100 - 0x104      */
  volatile u_int32_t BB_TXBF1_CNTL;               /*      0x104 - 0x108      */
  volatile u_int32_t BB_TXBF2_CNTL;               /*      0x108 - 0x10c      */
  volatile u_int32_t BB_TXBF3_CNTL;               /*      0x10c - 0x110      */
  volatile u_int32_t BB_TXBF4_CNTL;               /*      0x110 - 0x114      */
  volatile u_int32_t BB_TXBF5_CNTL;               /*      0x114 - 0x118      */
  volatile u_int32_t BB_TXBF6_CNTL;               /*      0x118 - 0x11c      */
  volatile u_int32_t BB_TXBF7_CNTL;               /*      0x11c - 0x120      */
  volatile u_int32_t BB_TXBF8_CNTL;               /*      0x120 - 0x124      */
  volatile u_int32_t BB_TXBF_DBG2;                /*      0x124 - 0x128      */
  volatile unsigned int pad__1[0x4b6];            /*      0x128 - 0x1400     */
  volatile u_int32_t BB_SVD_MEM0[242];            /*     0x1400 - 0x17c8     */
  volatile unsigned int pad__2[0xe];              /*     0x17c8 - 0x1800     */
  volatile u_int32_t BB_SVD_MEM1[242];            /*     0x1800 - 0x1bc8     */
  volatile unsigned int pad__3[0x10e];            /*     0x1bc8 - 0x2000     */
  volatile u_int32_t BB_svd_spare_01;             /*     0x2000 - 0x2004     */
};

struct mrc_reg_map {
  volatile u_int32_t BB_timing_control_3a;        /*        0x0 - 0x4        */
  volatile u_int32_t BB_ldpc_cntl1;               /*        0x4 - 0x8        */
  volatile u_int32_t BB_ldpc_cntl2;               /*        0x8 - 0xc        */
  volatile u_int32_t BB_vit_spur_mask_A;          /*        0xc - 0x10       */
  volatile u_int32_t BB_vit_spur_mask_B;          /*       0x10 - 0x14       */
  volatile u_int32_t BB_pilot_spur_mask;          /*       0x14 - 0x18       */
  volatile u_int32_t BB_chan_spur_mask;           /*       0x18 - 0x1c       */
  volatile u_int32_t BB_short_gi_delta_slope;     /*       0x1c - 0x20       */
  volatile u_int32_t BB_ml_cntl1;                 /*       0x20 - 0x24       */
  volatile u_int32_t BB_ml_cntl2;                 /*       0x24 - 0x28       */
  volatile u_int32_t BB_tstadc;                   /*       0x28 - 0x2c       */
  volatile u_int32_t BB_vit_spur_mask_C;          /*       0x2c - 0x30       */
  volatile u_int32_t BB_vit_spur_mask_D;          /*       0x30 - 0x34       */
  volatile u_int32_t BB_pilot_spur_mask_CD;       /*       0x34 - 0x38       */
  volatile u_int32_t BB_chan_spur_mask_CD;        /*       0x38 - 0x3c       */
  volatile u_int32_t BB_vit_spur_mask_E;          /*       0x3c - 0x40       */
  volatile u_int32_t BB_vit_spur_mask_F;          /*       0x40 - 0x44       */
  volatile u_int32_t BB_pilot_spur_mask_EF;       /*       0x44 - 0x48       */
  volatile u_int32_t BB_chan_spur_mask_EF;        /*       0x48 - 0x4c       */
  volatile u_int32_t BB_vit_spur_mask_G;          /*       0x4c - 0x50       */
  volatile u_int32_t BB_vit_spur_mask_H;          /*       0x50 - 0x54       */
  volatile u_int32_t BB_pilot_spur_mask_GH;       /*       0x54 - 0x58       */
  volatile u_int32_t BB_chan_spur_mask_GH;        /*       0x58 - 0x5c       */
  volatile u_int32_t BB_ldpc_cntl3;               /*       0x5c - 0x60       */
  volatile u_int32_t BB_ldpc_cntl4;               /*       0x60 - 0x64       */
  volatile u_int32_t BB_gid_upa_entry_0_to_15;    /*       0x64 - 0x68       */
  volatile u_int32_t BB_gid_upa_entry_16_to_31;   /*       0x68 - 0x6c       */
  volatile u_int32_t BB_gid_upa_entry_32_to_47;   /*       0x6c - 0x70       */
  volatile u_int32_t BB_gid_upa_entry_48_to_63;   /*       0x70 - 0x74       */
  volatile u_int32_t BB_lsig_reliability_cntl;    /*       0x74 - 0x78       */
  volatile u_int32_t BB_mmse_cntl;                /*       0x78 - 0x7c       */
  volatile u_int32_t BB_ldpc_cntl5;               /*       0x7c - 0x80       */
  volatile u_int32_t BB_mmse_cntl2;               /*       0x80 - 0x84       */
  volatile u_int32_t BB_mmse_cntl3;               /*       0x84 - 0x88       */
  volatile u_int32_t BB_packet_bw_det_cntl;       /*       0x88 - 0x8c       */
  volatile u_int32_t BB_ml_cntl3;                 /*       0x8c - 0x90       */
  volatile u_int32_t BB_pbs_cntl;                 /*       0x90 - 0x94       */
  volatile u_int32_t BB_ste_coarse_tim_cntl_1;    /*       0x94 - 0x98       */
  volatile u_int32_t BB_ste_coarse_tim_cntl_2;    /*       0x98 - 0x9c       */
  volatile u_int32_t BB_ste_coarse_tim_cntl_3;    /*       0x9c - 0xa0       */
  volatile u_int32_t BB_delta_slope_coef_man_corr_sg;
                                                  /*       0xa0 - 0xa4       */
  volatile u_int32_t BB_delta_slope_coef_man_corr;
                                                  /*       0xa4 - 0xa8       */
  volatile u_int32_t BB_cfo_corr_scale_frac;      /*       0xa8 - 0xac       */
  volatile u_int32_t BB_gain_ratio_cntl;          /*       0xac - 0xb0       */
  volatile unsigned int pad__0[0x14];             /*       0xb0 - 0x100      */
  volatile u_int32_t BB_ldpc_cntl6;               /*      0x100 - 0x104      */
  volatile u_int32_t BB_ldpc_cntl7;               /*      0x104 - 0x108      */
  volatile u_int32_t BB_ldpc_cntl8;               /*      0x108 - 0x10c      */
  volatile u_int32_t BB_ldpc_cntl9;               /*      0x10c - 0x110      */
  volatile u_int32_t BB_mrc_spare_01;             /*      0x110 - 0x114      */
};

struct bb_reg_map {
  struct agc_reg_map bb_agc_reg_map;              /*        0x0 - 0x400      */
  struct chn_reg_map bb_chn_reg_map;              /*      0x400 - 0x5dc      */
  volatile unsigned int pad__0[0x9];              /*      0x5dc - 0x600      */
  struct sm_reg_map bb_sm_reg_map;                /*      0x600 - 0xbfc      */
  volatile unsigned int pad__1;                   /*      0xbfc - 0xc00      */
  struct rxb_reg_map bb_rxb_reg_map;              /*      0xc00 - 0xc40      */
  volatile unsigned int pad__2[0xf0];             /*      0xc40 - 0x1000     */
  struct agc1_reg_map bb_agc1_reg_map;            /*     0x1000 - 0x13fc     */
  volatile unsigned int pad__3;                   /*     0x13fc - 0x1400     */
  struct chn1_reg_map bb_chn1_reg_map;            /*     0x1400 - 0x1560     */
  volatile unsigned int pad__4[0x28];             /*     0x1560 - 0x1600     */
  struct sm1_reg_map bb_sm1_reg_map;              /*     0x1600 - 0x1b74     */
  volatile unsigned int pad__5[0x923];            /*     0x1b74 - 0x4000     */
  struct agc4_reg_map bb_agc4_reg_map;            /*     0x4000 - 0x4200     */
  volatile unsigned int pad__6[0x80];             /*     0x4200 - 0x4400     */
  struct chn4_reg_map bb_chn4_reg_map;            /*     0x4400 - 0x4500     */
  volatile unsigned int pad__7[0x40];             /*     0x4500 - 0x4600     */
  struct sm4_reg_map bb_sm4_reg_map;              /*     0x4600 - 0x4c00     */
  volatile unsigned int pad__8[0x100];            /*     0x4c00 - 0x5000     */
  struct svd_reg_map bb_svd_reg_map;              /*     0x5000 - 0x7004     */
  volatile unsigned int pad__9[0x3ff];            /*     0x7004 - 0x8000     */
  struct mrc_reg_map bb_mrc_reg_map;              /*     0x8000 - 0x8114     */
};

struct fpga_reg {
  volatile u_int32_t FPGA_REG1;                   /*        0x0 - 0x4        */
  volatile u_int32_t FPGA_REG2;                   /*        0x4 - 0x8        */
  volatile u_int32_t FPGA_REG3;                   /*        0x8 - 0xc        */
};

struct merlin_reg_sel {
  volatile u_int32_t MERLIN_RADIO_SEL;            /*        0x0 - 0x4        */
};

struct emu_phy_reg {
  volatile u_int32_t PHY_CTRL_0;                  /*        0x0 - 0x4        */
  volatile u_int32_t PHY_CTRL_1;                  /*        0x4 - 0x8        */
  volatile u_int32_t PHY_CTRL_2;                  /*        0x8 - 0xc        */
  volatile u_int32_t PHY_CTRL_3;                  /*        0xc - 0x10       */
  volatile u_int32_t PHY_CTRL_4;                  /*       0x10 - 0x14       */
  volatile u_int32_t PHY_CTRL_5;                  /*       0x14 - 0x18       */
  volatile u_int32_t PHY_CTRL_6;                  /*       0x18 - 0x1c       */
  volatile u_int32_t PHY_CTRL_7;                  /*       0x1c - 0x20       */
  volatile u_int32_t PHY_CTRL_8;                  /*       0x20 - 0x24       */
  volatile u_int32_t PHY_STOMP_PRI_CLR;           /*       0x24 - 0x28       */
  volatile u_int32_t PHY_STOMP_PRI_BUSY;          /*       0x28 - 0x2c       */
  volatile u_int32_t PHY_STOMP_SEC20_CLR;         /*       0x2c - 0x30       */
  volatile u_int32_t PHY_STOMP_SEC20_BUSY;        /*       0x30 - 0x34       */
  volatile u_int32_t PHY_STOMP_SEC40_CLR;         /*       0x34 - 0x38       */
  volatile u_int32_t PHY_STOMP_SEC40_BUSY;        /*       0x38 - 0x3c       */
  volatile u_int32_t PHY_STOMP_SEC80_CLR;         /*       0x3c - 0x40       */
  volatile u_int32_t PHY_STOMP_SEC80_BUSY;        /*       0x40 - 0x44       */
  volatile u_int32_t PHY_DATA_0;                  /*       0x44 - 0x48       */
  volatile u_int32_t PHY_DATA_1;                  /*       0x48 - 0x4c       */
  volatile u_int32_t PHY_DATA_2;                  /*       0x4c - 0x50       */
  volatile u_int32_t PHY_DATA_3;                  /*       0x50 - 0x54       */
  volatile u_int32_t PHY_DATA_4;                  /*       0x54 - 0x58       */
  volatile u_int32_t PHY_DATA_5;                  /*       0x58 - 0x5c       */
  volatile u_int32_t PHY_DATA_6;                  /*       0x5c - 0x60       */
  volatile u_int32_t PHY_DATA_7;                  /*       0x60 - 0x64       */
  volatile u_int32_t PHY_DATA_8;                  /*       0x64 - 0x68       */
  volatile u_int32_t PHY_DATA_9;                  /*       0x68 - 0x6c       */
  volatile unsigned int pad__0;                   /*       0x6c - 0x70       */
  volatile u_int32_t PHY_DATA_GP_USR[4];          /*       0x70 - 0x80       */
  volatile u_int32_t PHY_STATUS;                  /*       0x80 - 0x84       */
  volatile u_int32_t CHN_CTRL_0;                  /*       0x84 - 0x88       */
  volatile unsigned int pad__1[0x2];              /*       0x88 - 0x90       */
  volatile u_int32_t CHN_CTRL_1[4];               /*       0x90 - 0xa0       */
  volatile u_int32_t CHN_CTRL_2[4];               /*       0xa0 - 0xb0       */
  volatile u_int32_t TLVI_TX_PHY_DESC;            /*       0xb0 - 0xb4       */
  volatile u_int32_t TLVI_TX_SERVICE;             /*       0xb4 - 0xb8       */
  volatile u_int32_t TLVI_MAC_PKT_END;            /*       0xb8 - 0xbc       */
  volatile u_int32_t TLVI_VECTOR_XFER_START;      /*       0xbc - 0xc0       */
  volatile u_int32_t TLVI_TLV_TERMINATE;          /*       0xc0 - 0xc4       */
  volatile u_int32_t TLVI_TX_EXPECT_CBF;          /*       0xc4 - 0xc8       */
  volatile u_int32_t TLVI_TX_CBF_OFFSET;          /*       0xc8 - 0xcc       */
  volatile u_int32_t TLVI_TX_BF_PARAMS;           /*       0xcc - 0xd0       */
  volatile u_int32_t TLVI_TX_EXPECT_NDP;          /*       0xd0 - 0xd4       */
  volatile u_int32_t TLVI_PHY_OFF;                /*       0xd4 - 0xd8       */
  volatile u_int32_t TLVI_PHY_ON;                 /*       0xd8 - 0xdc       */
  volatile u_int32_t TLVO_SVD_READY;              /*       0xdc - 0xe0       */
  volatile u_int32_t TLVO_VECTOR_FRAGMENT;        /*       0xe0 - 0xe4       */
  volatile u_int32_t TLVO_RX_PHY_PPDU_END;        /*       0xe4 - 0xe8       */
  volatile u_int32_t TLVO_RX_PKT_END;             /*       0xe8 - 0xec       */
  volatile u_int32_t TLVO_RX_SERVICE;             /*       0xec - 0xf0       */
  volatile u_int32_t TLVO_RX_EVM;                 /*       0xf0 - 0xf4       */
  volatile u_int32_t TLVO_RX_RSSI_HT;             /*       0xf4 - 0xf8       */
  volatile u_int32_t TLVO_RX_RSSI_LEGACY;         /*       0xf8 - 0xfc       */
};

struct merlin2_0_radio_reg {
  volatile u_int32_t MERLIN_RXTXBB1_CH1;          /*        0x0 - 0x4        */
  volatile u_int32_t MERLIN_RXTXBB2_CH1;          /*        0x4 - 0x8        */
  volatile u_int32_t MERLIN_RXTXBB3_CH1;          /*        0x8 - 0xc        */
  volatile u_int32_t MERLIN_RXTXBB4_CH1;          /*        0xc - 0x10       */
  volatile u_int32_t MERLIN_RF2G1_CH1;            /*       0x10 - 0x14       */
  volatile u_int32_t MERLIN_RF2G2_CH1;            /*       0x14 - 0x18       */
  volatile u_int32_t MERLIN_RF5G1_CH1;            /*       0x18 - 0x1c       */
  volatile u_int32_t MERLIN_RF5G2_CH1;            /*       0x1c - 0x20       */
  volatile u_int32_t MERLIN_RF5G3_CH1;            /*       0x20 - 0x24       */
  volatile u_int32_t MERLIN_RXTXBB1_CH0;          /*       0x24 - 0x28       */
  volatile u_int32_t MERLIN_RXTXBB2_CH0;          /*       0x28 - 0x2c       */
  volatile u_int32_t MERLIN_RXTXBB3_CH0;          /*       0x2c - 0x30       */
  volatile u_int32_t MERLIN_RXTXBB4_CH0;          /*       0x30 - 0x34       */
  volatile u_int32_t MERLIN_RF2G1_CH0;            /*       0x34 - 0x38       */
  volatile u_int32_t MERLIN_RF2G2_CH0;            /*       0x38 - 0x3c       */
  volatile u_int32_t MERLIN_RF5G1_CH0;            /*       0x3c - 0x40       */
  volatile u_int32_t MERLIN_RF5G2_CH0;            /*       0x40 - 0x44       */
  volatile u_int32_t MERLIN_RF5G3_CH0;            /*       0x44 - 0x48       */
  volatile u_int32_t MERLIN_SYNTH1;               /*       0x48 - 0x4c       */
  volatile u_int32_t MERLIN_SYNTH2;               /*       0x4c - 0x50       */
  volatile u_int32_t MERLIN_SYNTH3;               /*       0x50 - 0x54       */
  volatile u_int32_t MERLIN_SYNTH4;               /*       0x54 - 0x58       */
  volatile u_int32_t MERLIN_SYNTH5;               /*       0x58 - 0x5c       */
  volatile u_int32_t MERLIN_SYNTH6;               /*       0x5c - 0x60       */
  volatile u_int32_t MERLIN_SYNTH7;               /*       0x60 - 0x64       */
  volatile u_int32_t MERLIN_SYNTH8;               /*       0x64 - 0x68       */
  volatile u_int32_t MERLIN_SYNTH9;               /*       0x68 - 0x6c       */
  volatile u_int32_t MERLIN_SYNTH10;              /*       0x6c - 0x70       */
  volatile u_int32_t MERLIN_SYNTH11;              /*       0x70 - 0x74       */
  volatile u_int32_t MERLIN_BIAS1;                /*       0x74 - 0x78       */
  volatile u_int32_t MERLIN_BIAS2;                /*       0x78 - 0x7c       */
  volatile u_int32_t MERLIN_BIAS3;                /*       0x7c - 0x80       */
  volatile u_int32_t MERLIN_BIAS4;                /*       0x80 - 0x84       */
  volatile u_int32_t MERLIN_GAIN0;                /*       0x84 - 0x88       */
  volatile u_int32_t MERLIN_GAIN1;                /*       0x88 - 0x8c       */
  volatile u_int32_t MERLIN_TOP0;                 /*       0x8c - 0x90       */
  volatile u_int32_t MERLIN_TOP1;                 /*       0x90 - 0x94       */
  volatile u_int32_t MERLIN_TOP2;                 /*       0x94 - 0x98       */
  volatile u_int32_t MERLIN_TOP3;                 /*       0x98 - 0x9c       */
};

struct mac_pdg_reg {
  volatile u_int32_t PDG_FSM_STATUS;              /*        0x0 - 0x4        */
  volatile u_int32_t PDG_TESTBUS_LS;              /*        0x4 - 0x8        */
  volatile u_int32_t PDG_TESTBUS_MS;              /*        0x8 - 0xc        */
  volatile u_int32_t PDG_DBG_COUNTERS;            /*        0xc - 0x10       */
  volatile u_int32_t PDG_CONFIG;                  /*       0x10 - 0x14       */
  volatile u_int32_t PDG_SCRAMBLING_OVERIDE;      /*       0x14 - 0x18       */
  volatile u_int32_t PDG_RESPONSE_CHAIN_MASK;     /*       0x18 - 0x1c       */
  volatile u_int32_t PDG_RESPONSE_PAPRD_CHAIN_MASK;
                                                  /*       0x1c - 0x20       */
  volatile u_int32_t PDG_WATCHDOG;                /*       0x20 - 0x24       */
  volatile u_int32_t PDG_DEBUG_MODULE_SELECT;     /*       0x24 - 0x28       */
  volatile unsigned int pad__0;                   /*       0x28 - 0x2c       */
  volatile u_int32_t PDG_CLOCK_GATE_DISABLE;      /*       0x2c - 0x30       */
  volatile unsigned int pad__1[0x4];              /*       0x30 - 0x40       */
  volatile u_int32_t PDG_SLOT_TIME;               /*       0x40 - 0x44       */
  volatile u_int32_t PDG_FEATURE_ENABLE;          /*       0x44 - 0x48       */
  volatile u_int32_t PDG_MCP;                     /*       0x48 - 0x4c       */
  volatile u_int32_t PDG_EVENT_DEBUG_SELECT1;     /*       0x4c - 0x50       */
  volatile u_int32_t PDG_EVENT_DEBUG_SELECT2;     /*       0x50 - 0x54       */
  volatile u_int32_t PDG_EVENT_DEBUG_SELECT3;     /*       0x54 - 0x58       */
  volatile u_int32_t PDG_EVENT_MASK_31_0;         /*       0x58 - 0x5c       */
  volatile u_int32_t PDG_EVENT_MASK_64_32;        /*       0x5c - 0x60       */
  volatile u_int32_t PDG_OFDM_11A_PKT_PHY_LIMIT;  /*       0x60 - 0x64       */
  volatile u_int32_t PDG_OFDM_11NAC_PKT_PHY_LIMIT;
                                                  /*       0x64 - 0x68       */
  volatile u_int32_t PDG_CBF_RESPONSE_PHY_DESC_CFG;
                                                  /*       0x68 - 0x6c       */
  volatile u_int32_t PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG;
                                                  /*       0x6c - 0x70       */
  volatile u_int32_t PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG;
                                                  /*       0x70 - 0x74       */
  volatile u_int32_t PDG_OFDM_RESPONSE_PHY_DESC_CFG;
                                                  /*       0x74 - 0x78       */
  volatile u_int32_t PDG_CCK_RESPONSE_PHY_DESC_CFG;
                                                  /*       0x78 - 0x7c       */
  volatile u_int32_t PDG_RESPONSE_RTT_CHAIN_MASK; /*       0x7c - 0x80       */
  volatile u_int32_t PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK;
                                                  /*       0x80 - 0x84       */
  volatile u_int32_t PDG_CCK_PKT_PHY_LIMIT;       /*       0x84 - 0x88       */
};

struct mac_txdma_reg {
  volatile u_int32_t MSDU_INFO_FETCH_CFG;         /*        0x0 - 0x4        */
  volatile u_int32_t TXDATA_FETCH_CFG;            /*        0x4 - 0x8        */
  volatile u_int32_t TXDMA_ERROR_OLE_CFG;         /*        0x8 - 0xc        */
  volatile u_int32_t WATCHDOG;                    /*        0xc - 0x10       */
  volatile u_int32_t TXDMA_TRACEBUS;              /*       0x10 - 0x14       */
  volatile u_int32_t PROG_IDX_SIZE;               /*       0x14 - 0x18       */
  volatile u_int32_t TXDMA_TRACEBUS_READ_UPPER;   /*       0x18 - 0x1c       */
  volatile u_int32_t TXDMA_TRACEBUS_READ_LOWER;   /*       0x1c - 0x20       */
  volatile u_int32_t DATA_SWAP;                   /*       0x20 - 0x24       */
  volatile u_int32_t DEBUG_COUNTER_ENABLE;        /*       0x24 - 0x28       */
  volatile u_int32_t DEBUG_FES_SETUP;             /*       0x28 - 0x2c       */
  volatile u_int32_t DEBUG_FLUSH;                 /*       0x2c - 0x30       */
  volatile u_int32_t DEBUG_FES_STATUS;            /*       0x30 - 0x34       */
  volatile u_int32_t DEBUG_FLUSH_REQ;             /*       0x34 - 0x38       */
  volatile u_int32_t DEBUG_MPDU;                  /*       0x38 - 0x3c       */
  volatile u_int32_t DEBUG_MSDU_DATA_DWORDS;      /*       0x3c - 0x40       */
  volatile u_int32_t DEBUG_STATES_0;              /*       0x40 - 0x44       */
  volatile u_int32_t DEBUG_STATES_1;              /*       0x44 - 0x48       */
  volatile u_int32_t TXDMA_EVENTBUS_31_0;         /*       0x48 - 0x4c       */
  volatile u_int32_t TXDMA_EVENTBUS_63_32;        /*       0x4c - 0x50       */
  volatile u_int32_t TXDMA_ERROR_AXI_CFG;         /*       0x50 - 0x54       */
  volatile u_int32_t TXDMA_CLK_GATE_DISABLE;      /*       0x54 - 0x58       */
  volatile u_int32_t TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST;
                                                  /*       0x58 - 0x5c       */
};

struct mac_rxdma_reg {
  volatile u_int32_t RXDMA_CFG_RING0_0;           /*        0x0 - 0x4        */
  volatile u_int32_t RXDMA_CFG_RING0_1;           /*        0x4 - 0x8        */
  volatile u_int32_t RXDMA_CFG_RING0_2;           /*        0x8 - 0xc        */
  volatile u_int32_t RXDMA_CFG_RING0_3;           /*        0xc - 0x10       */
  volatile u_int32_t RXDMA_CFG_RING0_4;           /*       0x10 - 0x14       */
  volatile u_int32_t RXDMA_CFG_RING0_5;           /*       0x14 - 0x18       */
  volatile u_int32_t RXDMA_CFG_RING0_6;           /*       0x18 - 0x1c       */
  volatile u_int32_t RXDMA_CFG_RING0_7;           /*       0x1c - 0x20       */
  volatile u_int32_t RXDMA_CFG_RING1_0;           /*       0x20 - 0x24       */
  volatile u_int32_t RXDMA_CFG_RING1_1;           /*       0x24 - 0x28       */
  volatile u_int32_t RXDMA_CFG_RING1_2;           /*       0x28 - 0x2c       */
  volatile u_int32_t RXDMA_CFG_RING1_3;           /*       0x2c - 0x30       */
  volatile u_int32_t RXDMA_CFG_RING1_4;           /*       0x30 - 0x34       */
  volatile u_int32_t RXDMA_CFG_RING1_5;           /*       0x34 - 0x38       */
  volatile u_int32_t RXDMA_CFG_RING1_6;           /*       0x38 - 0x3c       */
  volatile u_int32_t RXDMA_CFG_RING1_7;           /*       0x3c - 0x40       */
  volatile u_int32_t RXDMA_CFG_RING2_0;           /*       0x40 - 0x44       */
  volatile u_int32_t RXDMA_CFG_RING2_1;           /*       0x44 - 0x48       */
  volatile u_int32_t RXDMA_CFG_RING2_2;           /*       0x48 - 0x4c       */
  volatile u_int32_t RXDMA_CFG_RING2_3;           /*       0x4c - 0x50       */
  volatile u_int32_t RXDMA_CFG_RING2_4;           /*       0x50 - 0x54       */
  volatile u_int32_t RXDMA_CFG_RING2_5;           /*       0x54 - 0x58       */
  volatile u_int32_t RXDMA_CFG_RING2_6;           /*       0x58 - 0x5c       */
  volatile u_int32_t RXDMA_CFG_RING2_7;           /*       0x5c - 0x60       */
  volatile u_int32_t RXDMA_CFG_RING3_0;           /*       0x60 - 0x64       */
  volatile u_int32_t RXDMA_CFG_RING3_1;           /*       0x64 - 0x68       */
  volatile u_int32_t RXDMA_CFG_RING3_2;           /*       0x68 - 0x6c       */
  volatile u_int32_t RXDMA_CFG_RING3_3;           /*       0x6c - 0x70       */
  volatile u_int32_t RXDMA_CFG_RING3_4;           /*       0x70 - 0x74       */
  volatile u_int32_t RXDMA_CFG_RING3_5;           /*       0x74 - 0x78       */
  volatile u_int32_t RXDMA_CFG_RING3_6;           /*       0x78 - 0x7c       */
  volatile u_int32_t RXDMA_CFG_RING3_7;           /*       0x7c - 0x80       */
  volatile u_int32_t RXDMA_EN_ACT_0;              /*       0x80 - 0x84       */
  volatile u_int32_t RXDMA_EN_ACT_1;              /*       0x84 - 0x88       */
  volatile u_int32_t RXDMA_EN_ACT_2;              /*       0x88 - 0x8c       */
  volatile u_int32_t RXDMA_EN_ACT_3;              /*       0x8c - 0x90       */
  volatile u_int32_t RXDMA_IDX_0;                 /*       0x90 - 0x94       */
  volatile u_int32_t RXDMA_IDX_1;                 /*       0x94 - 0x98       */
  volatile u_int32_t RXDMA_IDX_2;                 /*       0x98 - 0x9c       */
  volatile u_int32_t RXDMA_IDX_3;                 /*       0x9c - 0xa0       */
  volatile u_int32_t RXDMA_CFG_MISC_0;            /*       0xa0 - 0xa4       */
  volatile u_int32_t RXDMA_CFG_MISC_1;            /*       0xa4 - 0xa8       */
  volatile u_int32_t RXDMA_CFG_MISC_2;            /*       0xa8 - 0xac       */
  volatile u_int32_t RXDMA_FETCH_IDX_0;           /*       0xac - 0xb0       */
  volatile u_int32_t RXDMA_FETCH_IDX_1;           /*       0xb0 - 0xb4       */
  volatile u_int32_t RXDMA_FETCH_IDX_2;           /*       0xb4 - 0xb8       */
  volatile u_int32_t RXDMA_FETCH_IDX_3;           /*       0xb8 - 0xbc       */
  volatile u_int32_t RXDMA_GLOBAL_RER;            /*       0xbc - 0xc0       */
  volatile u_int32_t RXDMA_SOFT_RST;              /*       0xc0 - 0xc4       */
  volatile u_int32_t RXDMA_WDOG;                  /*       0xc4 - 0xc8       */
  volatile u_int32_t RXDMA_TESTBUS_SAMPLE;        /*       0xc8 - 0xcc       */
  volatile u_int32_t RXDMA_TRACEBUS_CTRL;         /*       0xcc - 0xd0       */
  volatile u_int32_t RXDMA_CLOCK_GATE;            /*       0xd0 - 0xd4       */
  volatile u_int32_t RXDMA_EVENT_MASK_31_0;       /*       0xd4 - 0xd8       */
};

struct mac_ole_reg {
  volatile u_int32_t OLE_L2_WLAN_LLC_0;           /*        0x0 - 0x4        */
  volatile u_int32_t OLE_L2_WLAN_LLC_1;           /*        0x4 - 0x8        */
  volatile u_int32_t OLE_L2_WLAN_LLC_2;           /*        0x8 - 0xc        */
  volatile u_int32_t OLE_L2_WLAN_LLC_3;           /*        0xc - 0x10       */
  volatile u_int32_t OLE_L2_WLAN_LLC_4;           /*       0x10 - 0x14       */
  volatile u_int32_t OLE_L2_WLAN_LLC_5;           /*       0x14 - 0x18       */
  volatile u_int32_t OLE_L2_WLAN_LLC_6;           /*       0x18 - 0x1c       */
  volatile unsigned int pad__0;                   /*       0x1c - 0x20       */
  volatile u_int32_t OLE_RX_CONFIG;               /*       0x20 - 0x24       */
  volatile u_int32_t OLE_RX_CONFIG_RING0;         /*       0x24 - 0x28       */
  volatile u_int32_t OLE_RX_CONFIG_RING1;         /*       0x28 - 0x2c       */
  volatile u_int32_t OLE_RX_CONFIG_RING2;         /*       0x2c - 0x30       */
  volatile u_int32_t OLE_RX_CONFIG_RING3;         /*       0x30 - 0x34       */
  volatile u_int32_t OLE_DECAP_CONFIG;            /*       0x34 - 0x38       */
  volatile u_int32_t OLE_HEADER_PADDING;          /*       0x38 - 0x3c       */
  volatile u_int32_t OLE_DECAP_TABLE_0_HALF1;     /*       0x3c - 0x40       */
  volatile u_int32_t OLE_DECAP_TABLE_0_HALF2;     /*       0x40 - 0x44       */
  volatile u_int32_t OLE_DECAP_TABLE_1_HALF1;     /*       0x44 - 0x48       */
  volatile u_int32_t OLE_DECAP_TABLE_1_HALF2;     /*       0x48 - 0x4c       */
  volatile u_int32_t OLE_DECAP_TABLE_2_HALF1;     /*       0x4c - 0x50       */
  volatile u_int32_t OLE_DECAP_TABLE_2_HALF2;     /*       0x50 - 0x54       */
  volatile u_int32_t OLE_DECAP_TABLE_3_HALF1;     /*       0x54 - 0x58       */
  volatile u_int32_t OLE_DECAP_TABLE_3_HALF2;     /*       0x58 - 0x5c       */
  volatile u_int32_t OLE_DECAP_TABLE_4_HALF1;     /*       0x5c - 0x60       */
  volatile u_int32_t OLE_DECAP_TABLE_4_HALF2;     /*       0x60 - 0x64       */
  volatile u_int32_t OLE_DECAP_TABLE_5_HALF1;     /*       0x64 - 0x68       */
  volatile u_int32_t OLE_DECAP_TABLE_5_HALF2;     /*       0x68 - 0x6c       */
  volatile u_int32_t OLE_DECAP_TABLE_6_HALF1;     /*       0x6c - 0x70       */
  volatile u_int32_t OLE_DECAP_TABLE_6_HALF2;     /*       0x70 - 0x74       */
  volatile u_int32_t OLE_DECAP_TABLE_7_HALF1;     /*       0x74 - 0x78       */
  volatile u_int32_t OLE_DECAP_TABLE_7_HALF2;     /*       0x78 - 0x7c       */
  volatile u_int32_t OLE_ASE_AST_BASE_ADDR;       /*       0x7c - 0x80       */
  volatile u_int32_t OLE_ASE_AST_SIZE;            /*       0x80 - 0x84       */
  volatile u_int32_t OLE_ASE_SEARCH_CTRL;         /*       0x84 - 0x88       */
  volatile u_int32_t OLE_ASE_HASH_CTRL;           /*       0x88 - 0x8c       */
  volatile u_int32_t OLE_CONFIG;                  /*       0x8c - 0x90       */
  volatile u_int32_t OLE_PN_SHIFT_FACTOR;         /*       0x90 - 0x94       */
  volatile u_int32_t OLE_RX_CLASSIFY_ETHERNET_0;  /*       0x94 - 0x98       */
  volatile u_int32_t OLE_RX_CLASSIFY_ETHERNET_1;  /*       0x98 - 0x9c       */
  volatile u_int32_t OLE_RX_CLASSIFY_ETHERNET_2;  /*       0x9c - 0xa0       */
  volatile u_int32_t OLE_RX_CLASSIFY_ETHERNET_3;  /*       0xa0 - 0xa4       */
  volatile unsigned int pad__1[0x7];              /*       0xa4 - 0xc0       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_0;   /*       0xc0 - 0xc4       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_1;   /*       0xc4 - 0xc8       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_2;   /*       0xc8 - 0xcc       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_3;   /*       0xcc - 0xd0       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_4;   /*       0xd0 - 0xd4       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_5;   /*       0xd4 - 0xd8       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_6;   /*       0xd8 - 0xdc       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_7;   /*       0xdc - 0xe0       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_8;   /*       0xe0 - 0xe4       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_9;   /*       0xe4 - 0xe8       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_10;  /*       0xe8 - 0xec       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_11;  /*       0xec - 0xf0       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_12;  /*       0xf0 - 0xf4       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_13;  /*       0xf4 - 0xf8       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_14;  /*       0xf8 - 0xfc       */
  volatile u_int32_t OLE_RX_L3_IPV6_EXTN_HDR_15;  /*       0xfc - 0x100      */
  volatile u_int32_t OLE_BUF_STAT;                /*      0x100 - 0x104      */
  volatile u_int32_t OLE_RX_AMSDU_LIMIT;          /*      0x104 - 0x108      */
  volatile unsigned int pad__2;                   /*      0x108 - 0x10c      */
  volatile u_int32_t OLE_LRO;                     /*      0x10c - 0x110      */
  volatile u_int32_t OLE_IPV6_CRC_OPTIONS_EN;     /*      0x110 - 0x114      */
  volatile u_int32_t OLE_IPV6_CRC_OPTIONS_HEADERS0;
                                                  /*      0x114 - 0x118      */
  volatile u_int32_t OLE_IPV6_CRC_OPTIONS_HEADERS1;
                                                  /*      0x118 - 0x11c      */
  volatile u_int32_t OLE_TX_WATCHDOG;             /*      0x11c - 0x120      */
  volatile u_int32_t OLE_RX_WATCHDOG;             /*      0x120 - 0x124      */
  volatile u_int32_t OLE_WATCHDOG_INTR_STATUS;    /*      0x124 - 0x128      */
  volatile u_int32_t OLE_DEBUG_1;                 /*      0x128 - 0x12c      */
  volatile u_int32_t OLE_DEBUGBUS_CONTROL;        /*      0x12c - 0x130      */
  volatile u_int32_t OLE_TX_FIFO_STATUS;          /*      0x130 - 0x134      */
  volatile u_int32_t OLE_CLOCK_GATE;              /*      0x134 - 0x138      */
  volatile u_int32_t OLE_EVENT_BUS_MASK0;         /*      0x138 - 0x13c      */
  volatile u_int32_t OLE_EVENT_BUS_MASK1;         /*      0x13c - 0x140      */
};

struct mac_mcmn_reg {
  volatile u_int32_t MCMN_ISR_P;                  /*        0x0 - 0x4        */
  volatile u_int32_t MCMN_ISR_S0;                 /*        0x4 - 0x8        */
  volatile u_int32_t MCMN_ISR_S1;                 /*        0x8 - 0xc        */
  volatile u_int32_t MCMN_ISR_S2;                 /*        0xc - 0x10       */
  volatile u_int32_t MCMN_ISR_S3;                 /*       0x10 - 0x14       */
  volatile u_int32_t MCMN_ISR_S4;                 /*       0x14 - 0x18       */
  volatile u_int32_t MCMN_ISR_S5;                 /*       0x18 - 0x1c       */
  volatile u_int32_t MCMN_ISR_S6;                 /*       0x1c - 0x20       */
  volatile u_int32_t MCMN_ISR_S7;                 /*       0x20 - 0x24       */
  volatile u_int32_t MCMN_ISR_S8;                 /*       0x24 - 0x28       */
  volatile u_int32_t MCMN_ISR_S9;                 /*       0x28 - 0x2c       */
  volatile u_int32_t MCMN_ISR_S10;                /*       0x2c - 0x30       */
  volatile u_int32_t MCMN_IMR_P;                  /*       0x30 - 0x34       */
  volatile u_int32_t MCMN_IMR_S0;                 /*       0x34 - 0x38       */
  volatile u_int32_t MCMN_IMR_S1;                 /*       0x38 - 0x3c       */
  volatile u_int32_t MCMN_IMR_S2;                 /*       0x3c - 0x40       */
  volatile u_int32_t MCMN_IMR_S3;                 /*       0x40 - 0x44       */
  volatile u_int32_t MCMN_IMR_S4;                 /*       0x44 - 0x48       */
  volatile u_int32_t MCMN_IMR_S5;                 /*       0x48 - 0x4c       */
  volatile u_int32_t MCMN_IMR_S6;                 /*       0x4c - 0x50       */
  volatile u_int32_t MCMN_IMR_S7;                 /*       0x50 - 0x54       */
  volatile u_int32_t MCMN_IMR_S8;                 /*       0x54 - 0x58       */
  volatile u_int32_t MCMN_IMR_S9;                 /*       0x58 - 0x5c       */
  volatile u_int32_t MCMN_IMR_S10;                /*       0x5c - 0x60       */
  volatile unsigned int pad__0[0x2];              /*       0x60 - 0x68       */
  volatile u_int32_t MPDU_LINK_DESC_BASE_ADDR[2]; /*       0x68 - 0x70       */
  volatile u_int32_t MPDU_LINK_DESC_MIN_IDX[2];   /*       0x70 - 0x78       */
  volatile u_int32_t MPDU_LINK_DESC_MAX_IDX[2];   /*       0x78 - 0x80       */
  volatile u_int32_t MPDU_LINK_EXT_DESC_SWAP;     /*       0x80 - 0x84       */
  volatile u_int32_t MSDU_LINK_DESC_SWAP;         /*       0x84 - 0x88       */
  volatile u_int32_t MPDU_LINK_EXT_DESC_BASE_ADDR;
                                                  /*       0x88 - 0x8c       */
  volatile unsigned int pad__1;                   /*       0x8c - 0x90       */
  volatile u_int32_t MSDU_LINK_DESC_BASE_ADDR;    /*       0x90 - 0x94       */
  volatile unsigned int pad__2[0x3];              /*       0x94 - 0xa0       */
  volatile u_int32_t MSDU_LINK_EXT_DESC_BASE_ADDR[16];
                                                  /*       0xa0 - 0xe0       */
  volatile u_int32_t MSDU_LINK_EXT_DESC_MIN_IDX[16];
                                                  /*       0xe0 - 0x120      */
  volatile u_int32_t MSDU_LINK_EXT_DESC_MAX_IDX[16];
                                                  /*      0x120 - 0x160      */
  volatile u_int32_t MSDU_LINK_EXT_DESC_SWAP[16]; /*      0x160 - 0x1a0      */
  volatile u_int32_t MAX_AXI_RD_BURST_SIZE;       /*      0x1a0 - 0x1a4      */
  volatile u_int32_t MAC_PCU_STA_ADDR_L32;        /*      0x1a4 - 0x1a8      */
  volatile u_int32_t MAC_PCU_STA_ADDR_U16;        /*      0x1a8 - 0x1ac      */
  volatile u_int32_t MAC_PCU_BSSID_L32;           /*      0x1ac - 0x1b0      */
  volatile u_int32_t MAC_PCU_BSSID_U16;           /*      0x1b0 - 0x1b4      */
  volatile u_int32_t MAC_PCU_DIAG_SW;             /*      0x1b4 - 0x1b8      */
  volatile u_int32_t MAC_PCU_AZIMUTH_MODE;        /*      0x1b8 - 0x1bc      */
  volatile unsigned int pad__3[0x2];              /*      0x1bc - 0x1c4      */
  volatile u_int32_t MAC_PCU_WARM_TX_CONTROL;     /*      0x1c4 - 0x1c8      */
  volatile u_int32_t MCMN_GO_TO_IDLE;             /*      0x1c8 - 0x1cc      */
  volatile unsigned int pad__4[0x5];              /*      0x1cc - 0x1e0      */
  volatile u_int32_t TESTBUS_SELECT;              /*      0x1e0 - 0x1e4      */
  volatile u_int32_t MPDU_LINK_DESC_SWAP;         /*      0x1e4 - 0x1e8      */
  volatile u_int32_t MCMN_ISR_RX_OK;              /*      0x1e8 - 0x1ec      */
  volatile u_int32_t MCMN_IMR_RX_OK;              /*      0x1ec - 0x1f0      */
  volatile u_int32_t MCMN_ISR_SIFS_RESP;          /*      0x1f0 - 0x1f4      */
  volatile u_int32_t MCMN_IMR_SIFS_RESP;          /*      0x1f4 - 0x1f8      */
  volatile u_int32_t MCMN_ISR_TX_OK;              /*      0x1f8 - 0x1fc      */
  volatile u_int32_t MCMN_IMR_TX_OK;              /*      0x1fc - 0x200      */
  volatile u_int32_t MCMN_WOCLR_ISR_P_EN;         /*      0x200 - 0x204      */
  volatile u_int32_t MAC_PCU_CYCLE_CNT;           /*      0x204 - 0x208      */
  volatile u_int32_t MAC_PCU_MIB_CNT_CTRL;        /*      0x208 - 0x20c      */
  volatile u_int32_t MCMN_ISR_S11;                /*      0x20c - 0x210      */
  volatile u_int32_t MCMN_IMR_S11;                /*      0x210 - 0x214      */
  volatile u_int32_t MCMN_EVENT_TRACE_BUS_SELECT; /*      0x214 - 0x218      */
  volatile u_int32_t MCMN_APB_CLK_DISABLE;        /*      0x218 - 0x21c      */
  volatile u_int32_t MCMN_ECO_SPARE;              /*      0x21c - 0x220      */
  volatile u_int32_t MCMN_CLK_GATE_DISABLE;       /*      0x220 - 0x224      */
  volatile u_int32_t MCMN_EVENTBUS_BLOCK_MASK;    /*      0x224 - 0x228      */
  volatile u_int32_t MCMN_SW_EVENTBUS;            /*      0x228 - 0x22c      */
  volatile u_int32_t MCMN_MEM_CNTL_0;             /*      0x22c - 0x230      */
  volatile u_int32_t MCMN_MEM_CNTL_1;             /*      0x230 - 0x234      */
  volatile u_int32_t MCMN_MAC_IDLE;               /*      0x234 - 0x238      */
  volatile u_int32_t MAC_PCU_RX_FRAME_CNT;        /*      0x238 - 0x23c      */
  volatile u_int32_t MAC_PCU_TX_FRAME_CNT;        /*      0x23c - 0x240      */
  volatile u_int32_t MAC_PCU_RX_CLEAR_CNT;        /*      0x240 - 0x244      */
  volatile unsigned int pad__5;                   /*      0x244 - 0x248      */
  volatile u_int32_t MCMN_EVENTBUS_MASK0;         /*      0x248 - 0x24c      */
  volatile u_int32_t MCMN_EVENTBUS_MASK1;         /*      0x24c - 0x250      */
};

struct mac_trc_reg {
  volatile u_int32_t MAC_TRC;                     /*        0x0 - 0x4        */
  volatile u_int32_t MAC_TRC_BUF_INIT;            /*        0x4 - 0x8        */
  volatile u_int32_t MAC_TRC_ADDR;                /*        0x8 - 0xc        */
  volatile u_int32_t MAC_TRC_WFT_CAPTURE_CTRL;    /*        0xc - 0x10       */
  volatile u_int32_t MAC_TRC_WFT_STATE_CTRL;      /*       0x10 - 0x14       */
  volatile u_int32_t MAC_TRC_TS1_CAPTURE_CTRL;    /*       0x14 - 0x18       */
  volatile u_int32_t MAC_TRC_TS1_STATE_CTRL;      /*       0x18 - 0x1c       */
  volatile u_int32_t MAC_TRC_TS1_TRIG_MASK;       /*       0x1c - 0x20       */
  volatile u_int32_t MAC_TRC_TS1_TRIG;            /*       0x20 - 0x24       */
  volatile u_int32_t MAC_TRC_TS2_CAPTURE_CTRL;    /*       0x24 - 0x28       */
  volatile u_int32_t MAC_TRC_TS2_STATE_CTRL;      /*       0x28 - 0x2c       */
  volatile u_int32_t MAC_TRC_TS2_TRIG_MASK;       /*       0x2c - 0x30       */
  volatile u_int32_t MAC_TRC_TS2_TRIG;            /*       0x30 - 0x34       */
  volatile u_int32_t MAC_TRC_TS3_CAPTURE_CTRL;    /*       0x34 - 0x38       */
  volatile u_int32_t MAC_TRC_TS3_STATE_CTRL;      /*       0x38 - 0x3c       */
  volatile u_int32_t MAC_TRC_TS3_TRIG_MASK;       /*       0x3c - 0x40       */
  volatile u_int32_t MAC_TRC_TS3_TRIG;            /*       0x40 - 0x44       */
  volatile u_int32_t MAC_TRC_TS4_CAPTURE_CTRL;    /*       0x44 - 0x48       */
  volatile u_int32_t MAC_TRC_TS4_STATE_CTRL;      /*       0x48 - 0x4c       */
  volatile u_int32_t MAC_TRC_TS4_TRIG_MASK;       /*       0x4c - 0x50       */
  volatile u_int32_t MAC_TRC_TS4_TRIG;            /*       0x50 - 0x54       */
  volatile u_int32_t MAC_TRC_TS5_CAPTURE_CTRL;    /*       0x54 - 0x58       */
  volatile u_int32_t MAC_TRC_TS5_STATE_CTRL;      /*       0x58 - 0x5c       */
  volatile u_int32_t MAC_TRC_TS5_TRIG_MASK;       /*       0x5c - 0x60       */
  volatile u_int32_t MAC_TRC_TS5_TRIG;            /*       0x60 - 0x64       */
  volatile u_int32_t MAC_TRC_CPU_ADDR;            /*       0x64 - 0x68       */
  volatile u_int32_t MAC_TRC_CPU_DATA;            /*       0x68 - 0x6c       */
  volatile u_int32_t MAC_TRC_STATUS_0;            /*       0x6c - 0x70       */
  volatile u_int32_t MAC_TRC_STATUS_1;            /*       0x70 - 0x74       */
  volatile u_int32_t MAC_TRC_STATUS_2;            /*       0x74 - 0x78       */
  volatile u_int32_t MAC_TRC_STATUS_3;            /*       0x78 - 0x7c       */
  volatile u_int32_t MAC_BB_OBS_BUS_SEL;          /*       0x7c - 0x80       */
  volatile u_int32_t MAC_TRC_CPU_DATA_READ_DATA_SEL;
                                                  /*       0x80 - 0x84       */
  volatile u_int32_t MAC_TRC_LANE_SWAP;           /*       0x84 - 0x88       */
  volatile u_int32_t MAC_TRC_CLK_GATE_DISABLE;    /*       0x88 - 0x8c       */
  volatile u_int32_t MAC_TRC_TIME_STAMP;          /*       0x8c - 0x90       */
};

struct mac_rxpcu_reg {
  volatile u_int32_t RXPCU_BSSID2_L32;            /*        0x0 - 0x4        */
  volatile u_int32_t RXPCU_BSSID2_U16;            /*        0x4 - 0x8        */
  volatile u_int32_t RXPCU_BSSID3_L32;            /*        0x8 - 0xc        */
  volatile u_int32_t RXPCU_BSSID3_U16;            /*        0xc - 0x10       */
  volatile u_int32_t RXPCU_BSSID4_L32;            /*       0x10 - 0x14       */
  volatile u_int32_t RXPCU_BSSID4_U16;            /*       0x14 - 0x18       */
  volatile u_int32_t RXPCU_ADDR1_MASK_L32;        /*       0x18 - 0x1c       */
  volatile u_int32_t RXPCU_ADDR1_MASK_U16;        /*       0x1c - 0x20       */
  volatile u_int32_t RXPCU_MCAST_FILTER_L32;      /*       0x20 - 0x24       */
  volatile u_int32_t RXPCU_MCAST_FILTER_U32;      /*       0x24 - 0x28       */
  volatile u_int32_t RXPCU_RX_FILTER;             /*       0x28 - 0x2c       */
  volatile u_int32_t RXPCU_RX_FILTER2;            /*       0x2c - 0x30       */
  volatile u_int32_t RXPCU_PHY_DATA_LENGTH_THRESH;
                                                  /*       0x30 - 0x34       */
  volatile u_int32_t RXPCU_BCN_RSSI_CTL;          /*       0x34 - 0x38       */
  volatile u_int32_t RXPCU_BCN_RSSI_CTL2;         /*       0x38 - 0x3c       */
  volatile u_int32_t RXPCU_BCN_RSSI_AVE;          /*       0x3c - 0x40       */
  volatile u_int32_t RXPCU_FILTER_RSSI_AVE;       /*       0x40 - 0x44       */
  volatile u_int32_t RXPCU_BA_BAR_CONTROL;        /*       0x44 - 0x48       */
  volatile u_int32_t RXPCU_RTT_CTRL;              /*       0x48 - 0x4c       */
  volatile u_int32_t RXPCU_XRSTMP;                /*       0x4c - 0x50       */
  volatile u_int32_t RXPCU_TXBF_CNTL;             /*       0x50 - 0x54       */
  volatile u_int32_t RXPCU_IMPLICIT_BF_CTRL;      /*       0x54 - 0x58       */
  volatile u_int32_t RXPCU_SEC_CHANNEL_RX_PIFS_CNT;
                                                  /*       0x58 - 0x5c       */
  volatile u_int32_t RXPCU_PROXY_STA;             /*       0x5c - 0x60       */
  volatile u_int32_t RXPCU_RX_ANTENNA;            /*       0x60 - 0x64       */
  volatile u_int32_t RXPCU_CLASS_1_FRAME_CFG1;    /*       0x64 - 0x68       */
  volatile u_int32_t RXPCU_NAV_CFG;               /*       0x68 - 0x6c       */
  volatile u_int32_t RXPCU_CLASS_1_FRAME_CFG2;    /*       0x6c - 0x70       */
  volatile u_int32_t RXPCU_DIRECT_CONNECT;        /*       0x70 - 0x74       */
  volatile u_int32_t RXPCU_LAST_BEACON_TSF;       /*       0x74 - 0x78       */
  volatile u_int32_t RXPCU_LAST_BEACON2_TSF;      /*       0x78 - 0x7c       */
  volatile u_int32_t RXPCU_HW_BCN_PROC1;          /*       0x7c - 0x80       */
  volatile u_int32_t RXPCU_HW_BCN_PROC2;          /*       0x80 - 0x84       */
  volatile u_int32_t RXPCU_DYM_MIMO_PWR_SAVE;     /*       0x84 - 0x88       */
  volatile u_int32_t RXPCU_POWER_SAVE_0;          /*       0x88 - 0x8c       */
  volatile u_int32_t RXPCU_POWER_SAVE_1;          /*       0x8c - 0x90       */
  volatile u_int32_t RXPCU_POWER_SAVE_2;          /*       0x90 - 0x94       */
  volatile u_int32_t RXPCU_POWER_SAVE_3;          /*       0x94 - 0x98       */
  volatile u_int32_t RXPCU_POWER_SAVE_4;          /*       0x98 - 0x9c       */
  volatile u_int32_t RXPCU_POWER_SAVE_5;          /*       0x9c - 0xa0       */
  volatile u_int32_t RXPCU_POWER_SAVE_6;          /*       0xa0 - 0xa4       */
  volatile u_int32_t RXPCU_POWER_SAVE_7;          /*       0xa4 - 0xa8       */
  volatile u_int32_t RXPCU_POWER_SAVE_8;          /*       0xa8 - 0xac       */
  volatile unsigned int pad__0;                   /*       0xac - 0xb0       */
  volatile u_int32_t RXPCU_RX_CLEAR_PHY_DLY_SEC20;
                                                  /*       0xb0 - 0xb4       */
  volatile u_int32_t RXPCU_RX_CLEAR_PHY_DLY_SEC40;
                                                  /*       0xb4 - 0xb8       */
  volatile u_int32_t RXPCU_RX_CLEAR_PHY_DLY_SEC80;
                                                  /*       0xb8 - 0xbc       */
  volatile u_int32_t RXPCU_AST_TIMEOUT;           /*       0xbc - 0xc0       */
  volatile u_int32_t RXPCU_ASE_AST_BASE_ADDR;     /*       0xc0 - 0xc4       */
  volatile u_int32_t RXPCU_ASE_AST_SIZE;          /*       0xc4 - 0xc8       */
  volatile u_int32_t RXPCU_ASE_SEARCH_CTRL;       /*       0xc8 - 0xcc       */
  volatile u_int32_t RXPCU_ASE_HASH_CTRL;         /*       0xcc - 0xd0       */
  volatile u_int32_t RXPCU_MISC_MODE;             /*       0xd0 - 0xd4       */
  volatile u_int32_t RXPCU_MISC_MODE2;            /*       0xd4 - 0xd8       */
  volatile u_int32_t RXPCU_MISC_MODE3;            /*       0xd8 - 0xdc       */
  volatile u_int32_t RXPCU_MISC_MODE4;            /*       0xdc - 0xe0       */
  volatile u_int32_t RXPCU_DIAGNOSTIC_MODE;       /*       0xe0 - 0xe4       */
  volatile u_int32_t RXPCU_WATCHDOG;              /*       0xe4 - 0xe8       */
  volatile u_int32_t RXPCU_MISC_MODE5;            /*       0xe8 - 0xec       */
  volatile unsigned int pad__1;                   /*       0xec - 0xf0       */
  volatile u_int32_t RXPCU_FCS_FAIL_CNT;          /*       0xf0 - 0xf4       */
  volatile u_int32_t RXPCU_BEACON_CNT;            /*       0xf4 - 0xf8       */
  volatile u_int32_t RXPCU_BEACON2_CNT;           /*       0xf8 - 0xfc       */
  volatile unsigned int pad__2[0x2];              /*       0xfc - 0x104      */
  volatile u_int32_t RXPCU_FILTER_OFDM_CNT;       /*      0x104 - 0x108      */
  volatile u_int32_t RXPCU_FILTER_CCK_CNT;        /*      0x108 - 0x10c      */
  volatile u_int32_t RXPCU_SIFS_RESP_STATUS;      /*      0x10c - 0x110      */
  volatile u_int32_t RXPCU_SIFS_RESP_STATUS2;     /*      0x110 - 0x114      */
  volatile u_int32_t RXPCU_SIFS_RESP_STATUS3;     /*      0x114 - 0x118      */
  volatile unsigned int pad__3[0x2];              /*      0x118 - 0x120      */
  volatile u_int32_t RXPCU_PHY_ERROR_MASK;        /*      0x120 - 0x124      */
  volatile u_int32_t RXPCU_PHY_ERROR_MASK_CONT;   /*      0x124 - 0x128      */
  volatile u_int32_t RXPCU_PHY_ERROR_EIFS_MASK;   /*      0x128 - 0x12c      */
  volatile u_int32_t RXPCU_PHY_ERROR_EIFS_MASK_CONT;
                                                  /*      0x12c - 0x130      */
  volatile u_int32_t RXPCU_PHY_ERROR_AIFS;        /*      0x130 - 0x134      */
  volatile u_int32_t RXPCU_PHY_ERROR_AIFS_MASK;   /*      0x134 - 0x138      */
  volatile u_int32_t RXPCU_PHY_ERROR_AIFS_MASK_CONT;
                                                  /*      0x138 - 0x13c      */
  volatile u_int32_t RXPCU_PHY_ERR_CNT_1;         /*      0x13c - 0x140      */
  volatile u_int32_t RXPCU_PHY_ERR_CNT_1_MASK;    /*      0x140 - 0x144      */
  volatile u_int32_t RXPCU_PHY_ERR_CNT_1_MASK_CONT;
                                                  /*      0x144 - 0x148      */
  volatile u_int32_t RXPCU_PHY_ERR_CNT_2;         /*      0x148 - 0x14c      */
  volatile u_int32_t RXPCU_PHY_ERR_CNT_2_MASK;    /*      0x14c - 0x150      */
  volatile u_int32_t RXPCU_PHY_ERR_CNT_2_MASK_CONT;
                                                  /*      0x150 - 0x154      */
  volatile u_int32_t RXPCU_PHY_ERR_CNT_3;         /*      0x154 - 0x158      */
  volatile u_int32_t RXPCU_PHY_ERR_CNT_3_MASK;    /*      0x158 - 0x15c      */
  volatile u_int32_t RXPCU_PHY_ERR_CNT_3_MASK_CONT;
                                                  /*      0x15c - 0x160      */
  volatile u_int32_t RXPCU_TEST_CFG;              /*      0x160 - 0x164      */
  volatile u_int32_t RXPCU_TESTBUS;               /*      0x164 - 0x168      */
  volatile u_int32_t RXPCU_FSM_STATUS;            /*      0x168 - 0x16c      */
  volatile u_int32_t RXPCU_SPARE_REG1;            /*      0x16c - 0x170      */
  volatile u_int32_t RXPCU_SPARE_REG2;            /*      0x170 - 0x174      */
  volatile u_int32_t RXPCU_PHY_INTF_TLV_CNT1;     /*      0x174 - 0x178      */
  volatile u_int32_t RXPCU_PHY_INTF_TLV_CNT2;     /*      0x178 - 0x17c      */
  volatile u_int32_t RXPCU_PHY_INTF_TLV_CNT3;     /*      0x17c - 0x180      */
  volatile unsigned int pad__4;                   /*      0x180 - 0x184      */
  volatile u_int32_t RXPCU_PHY_INTF_TLV_RCVD;     /*      0x184 - 0x188      */
  volatile unsigned int pad__5[0x2];              /*      0x188 - 0x190      */
  volatile u_int32_t RXPCU_TXPCU_INTF_TLV_CNT1;   /*      0x190 - 0x194      */
  volatile u_int32_t RXPCU_TXPCU_INTF_TLV_CNT2;   /*      0x194 - 0x198      */
  volatile u_int32_t RXPCU_TXPCU_INTF_TLV_CNT3;   /*      0x198 - 0x19c      */
  volatile u_int32_t RXPCU_TXPCU_INTF_TLV_CNT4;   /*      0x19c - 0x1a0      */
  volatile u_int32_t RXPCU_TXPCU_INTF_TLV_BITMAP; /*      0x1a0 - 0x1a4      */
  volatile unsigned int pad__6[0x3];              /*      0x1a4 - 0x1b0      */
  volatile u_int32_t RXPCU_CRYPTO_INTF_TLV_CNT1;  /*      0x1b0 - 0x1b4      */
  volatile u_int32_t RXPCU_TRIC_FSM_STATUS;       /*      0x1b4 - 0x1b8      */
  volatile u_int32_t RXPCU_TRIC_DEBUG_STATUS;     /*      0x1b8 - 0x1bc      */
  volatile unsigned int pad__7;                   /*      0x1bc - 0x1c0      */
  volatile u_int32_t RXPCU_DPSM_FSM_STATUS;       /*      0x1c0 - 0x1c4      */
  volatile u_int32_t RXPCU_DPSM_DEBUG_STATUS;     /*      0x1c4 - 0x1c8      */
  volatile unsigned int pad__8[0x2];              /*      0x1c8 - 0x1d0      */
  volatile u_int32_t RXPCU_RXSM_FSM_STATUS;       /*      0x1d0 - 0x1d4      */
  volatile u_int32_t RXPCU_PKT_DEBUG_CNT1;        /*      0x1d4 - 0x1d8      */
  volatile u_int32_t RXPCU_PKT_DEBUG_CNT2;        /*      0x1d8 - 0x1dc      */
  volatile u_int32_t RXPCU_EVENTBUS_MASK1;        /*      0x1dc - 0x1e0      */
  volatile u_int32_t RXPCU_EVENTBUS_MASK2;        /*      0x1e0 - 0x1e4      */
  volatile u_int32_t RXPCU_CMNTRIG_CFG;           /*      0x1e4 - 0x1e8      */
  volatile u_int32_t RXPCU_CMNTRIG_MASK_L32;      /*      0x1e8 - 0x1ec      */
  volatile u_int32_t RXPCU_CMNTRIG_MASK_U03;      /*      0x1ec - 0x1f0      */
  volatile u_int32_t RXPCU_CMNTRIG_MATCH_L32;     /*      0x1f0 - 0x1f4      */
  volatile u_int32_t RXPCU_CMNTRIG_MATCH_U03;     /*      0x1f4 - 0x1f8      */
  volatile u_int32_t RXPCU_CRYPTO_INTF_TLV_CNT2;  /*      0x1f8 - 0x1fc      */
  volatile unsigned int pad__9;                   /*      0x1fc - 0x200      */
  volatile u_int32_t RXPCU_MAX_RX_LENGTH_DATA;    /*      0x200 - 0x204      */
  volatile u_int32_t RXPCU_MAX_RX_LENGTH_CTRL;    /*      0x204 - 0x208      */
  volatile u_int32_t RXPCU_MAX_RX_LENGTH_MGMT;    /*      0x208 - 0x20c      */
  volatile u_int32_t RXPCU_MAX_RX_LENGTH_ERR_CNT; /*      0x20c - 0x210      */
  volatile u_int32_t RXPCU_CLKGATE_EN;            /*      0x210 - 0x214      */
  volatile u_int32_t RXPCU_PHY_ERROR_PROMISCUOUS_MASK;
                                                  /*      0x214 - 0x218      */
  volatile u_int32_t RXPCU_PHY_ERROR_PROMISCUOUS_MASK_CONT;
                                                  /*      0x218 - 0x21c      */
  volatile unsigned int pad__10[0x379];           /*      0x21c - 0x1000     */
  volatile u_int32_t RXPCU_RXBUF[2048];           /*     0x1000 - 0x3000     */
};

struct mac_txpcu_reg {
  volatile u_int32_t TXPCU_TIMEOUT;               /*        0x0 - 0x4        */
  volatile u_int32_t TXPCU_CV_LENGTH_TIMEOUT;     /*        0x4 - 0x8        */
  volatile u_int32_t TXPCU_WATCHDOG;              /*        0x8 - 0xc        */
  volatile u_int32_t TXPCU_INITIAL_CREDIT;        /*        0xc - 0x10       */
  volatile u_int32_t TXPCU_BASIC_RATE_SET0;       /*       0x10 - 0x14       */
  volatile u_int32_t TXPCU_BASIC_RATE_SET1;       /*       0x14 - 0x18       */
  volatile u_int32_t TXPCU_BASIC_RATE_SET2;       /*       0x18 - 0x1c       */
  volatile u_int32_t TXPCU_BASIC_RATE_SET3;       /*       0x1c - 0x20       */
  volatile u_int32_t TXPCU_BASIC_RATE_SET4;       /*       0x20 - 0x24       */
  volatile u_int32_t TXPCU_BASIC_SET;             /*       0x24 - 0x28       */
  volatile unsigned int pad__0[0x2];              /*       0x28 - 0x30       */
  volatile u_int32_t TXPCU_SIFS_TIMEOUT;          /*       0x30 - 0x34       */
  volatile u_int32_t TXPCU_PHY_TX_LATENCY;        /*       0x34 - 0x38       */
  volatile unsigned int pad__1;                   /*       0x38 - 0x3c       */
  volatile u_int32_t TXPCU_TX_ANT_CTL;            /*       0x3c - 0x40       */
  volatile unsigned int pad__2;                   /*       0x40 - 0x44       */
  volatile u_int32_t TXPCU_MGMT_SEQ;              /*       0x44 - 0x48       */
  volatile u_int32_t TXPCU_MISC_MODE;             /*       0x48 - 0x4c       */
  volatile u_int32_t TXPCU_RTT_CTRL;              /*       0x4c - 0x50       */
  volatile u_int32_t TXPCU_TXBUF_DRAIN_THRESHOLD; /*       0x50 - 0x54       */
  volatile u_int32_t TXPCU_CBF_RESP_CTL_20;       /*       0x54 - 0x58       */
  volatile u_int32_t TXPCU_CBF_RESP_CTL_40;       /*       0x58 - 0x5c       */
  volatile u_int32_t TXPCU_CBF_RESP_CTL_80;       /*       0x5c - 0x60       */
  volatile u_int32_t TXPCU_CBF_RESP_CTL_160;      /*       0x60 - 0x64       */
  volatile u_int32_t TXPCU_DYNAMIC_BW_CTL;        /*       0x64 - 0x68       */
  volatile u_int32_t TXPCU_TXBUF_CONTROL;         /*       0x68 - 0x6c       */
  volatile u_int32_t TXPCU_REQD_TLVS_WAIT_TIME;   /*       0x6c - 0x70       */
  volatile u_int32_t TXPCU_TIMEOUT_11AC_DATA_WAIT_TIME;
                                                  /*       0x70 - 0x74       */
  volatile u_int32_t TXPCU_DEBUG_STATE;           /*       0x74 - 0x78       */
  volatile u_int32_t TXPCU_DEBUG_TX_FES_0;        /*       0x78 - 0x7c       */
  volatile u_int32_t TXPCU_DEBUG_TX_FES_1;        /*       0x7c - 0x80       */
  volatile u_int32_t TXPCU_DEBUG_TX_FES_2;        /*       0x80 - 0x84       */
  volatile u_int32_t TXPCU_TRACEBUS_CTRL;         /*       0x84 - 0x88       */
  volatile u_int32_t TXPCU_DEBUG_TRACE_BUS_LOWER; /*       0x88 - 0x8c       */
  volatile u_int32_t TXPCU_DEBUG_TRACE_BUS_UPPER; /*       0x8c - 0x90       */
  volatile u_int32_t TXPCU_DEBUG_CREDIT_COUNTERS; /*       0x90 - 0x94       */
  volatile u_int32_t TXPCU_DEBUG_START_TX_CNT;    /*       0x94 - 0x98       */
  volatile u_int32_t TXPCU_DEBUG_TX_FLUSH_CNT;    /*       0x98 - 0x9c       */
  volatile u_int32_t TXPCU_DEBUG_RTS_SUCCESS_CNT; /*       0x9c - 0xa0       */
  volatile u_int32_t TXPCU_DEBUG_RTS_FAIL_CNT;    /*       0xa0 - 0xa4       */
  volatile u_int32_t TXPCU_DEBUG_ACK_SUCCESS_CNT; /*       0xa4 - 0xa8       */
  volatile u_int32_t TXPCU_DEBUG_ACK_FAIL_CNT;    /*       0xa8 - 0xac       */
  volatile u_int32_t TXPCU_DEBUG_MPDU_TX_FRAME_CNT;
                                                  /*       0xac - 0xb0       */
  volatile u_int32_t TXPCU_DEBUG_AMPDU_TX_FRAME_CNT;
                                                  /*       0xb0 - 0xb4       */
  volatile u_int32_t TXPCU_DEBUG_TX_PHY_ERROR_CNT;
                                                  /*       0xb4 - 0xb8       */
  volatile u_int32_t TXPCU_DEBUG_RX_FRAME_CNT;    /*       0xb8 - 0xbc       */
  volatile u_int32_t TXPCU_DEBUG_PDG_RESPONSE_CNT;
                                                  /*       0xbc - 0xc0       */
  volatile u_int32_t TXPCU_DEBUG_RESP_FRAME_SUCCESS_CNT;
                                                  /*       0xc0 - 0xc4       */
  volatile u_int32_t TXPCU_DEBUG_RESP_FRAME_FAIL_CNT;
                                                  /*       0xc4 - 0xc8       */
  volatile u_int32_t TXPCU_DEBUG_TX_FES_STATUS_UPDATE_CNT;
                                                  /*       0xc8 - 0xcc       */
  volatile u_int32_t TXPCU_SELF_GEN_ERROR;        /*       0xcc - 0xd0       */
  volatile u_int32_t TXPCU_EVENT_BUS_MASK0;       /*       0xd0 - 0xd4       */
  volatile u_int32_t TXPCU_EVENT_BUS_MASK1;       /*       0xd4 - 0xd8       */
  volatile u_int32_t TXPCU_CLOCK_GATE_DISABLE;    /*       0xd8 - 0xdc       */
  volatile u_int32_t TXPCU_DEBUG_RX_MESSAGE_TLV;  /*       0xdc - 0xe0       */
  volatile u_int32_t TXPCU_DEBUG_RX_MESSAGE_COUNT0;
                                                  /*       0xe0 - 0xe4       */
  volatile u_int32_t TXPCU_DEBUG_RX_MESSAGE_COUNT1;
                                                  /*       0xe4 - 0xe8       */
  volatile u_int32_t TXPCU_DEBUG_RX_MESSAGE_COUNT2;
                                                  /*       0xe8 - 0xec       */
  volatile u_int32_t TXPCU_DEBUG_TX_MESSAGE_COUNT0;
                                                  /*       0xec - 0xf0       */
  volatile u_int32_t TXPCU_DEBUG_TX_MESSAGE_COUNT1;
                                                  /*       0xf0 - 0xf4       */
  volatile u_int32_t TXPCU_DEBUG_TX_BFEE;         /*       0xf4 - 0xf8       */
  volatile unsigned int pad__3[0x3c2];            /*       0xf8 - 0x1000     */
  volatile u_int32_t TXPCU_TXBUF[2560];           /*     0x1000 - 0x3800     */
};

struct mac_ampi_reg {
  volatile u_int32_t AMPI_TX_SIFS_REG;            /*        0x0 - 0x4        */
  volatile u_int32_t AMPI_CURRENT_TIMESTAMP_REG;  /*        0x4 - 0x8        */
  volatile u_int32_t AMPI_PHY_TIMESTAMP1_REG;     /*        0x8 - 0xc        */
  volatile u_int32_t AMPI_PHY_TIMESTAMP2_REG;     /*        0xc - 0x10       */
  volatile u_int32_t AMPI_DEBUG_MODE_SELECT;      /*       0x10 - 0x14       */
  volatile u_int32_t AMPI_PHY_CLOCK_GATE_DISABLE; /*       0x14 - 0x18       */
  volatile u_int32_t AMPI_DEBUG_RX_ERROR_COUNT;   /*       0x18 - 0x1c       */
  volatile u_int32_t AMPI_DEBUG_TX_ERROR_COUNT;   /*       0x1c - 0x20       */
  volatile u_int32_t AMPI_STALE_TIMESTAMP_COUNT;  /*       0x20 - 0x24       */
  volatile u_int32_t AMPI_RX_SYNC_EVENT_COUNT;    /*       0x24 - 0x28       */
  volatile u_int32_t AMPI_INSERT_TIMESTAMP_COUNT; /*       0x28 - 0x2c       */
  volatile u_int32_t AMPI_FEATURE_DISABLE;        /*       0x2c - 0x30       */
  volatile u_int32_t AMPI_PHY_CAPTURED_TOA_REG;   /*       0x30 - 0x34       */
  volatile u_int32_t AMPI_PHY_CAPTURED_TOD_REG;   /*       0x34 - 0x38       */
  volatile unsigned int pad__0[0x1f8];            /*       0x38 - 0x818      */
  volatile u_int32_t AMPI_MAC_CLOCK_GATE_DISABLE; /*      0x818 - 0x81c      */
};

struct mac_crypto_reg {
  volatile u_int32_t AES_MUTE_MASK_0;             /*        0x0 - 0x4        */
  volatile u_int32_t AES_MUTE_MASK_1;             /*        0x4 - 0x8        */
  volatile u_int32_t MIC_QOS_CONTROL;             /*        0x8 - 0xc        */
  volatile u_int32_t MIC_QOS_SELECT;              /*        0xc - 0x10       */
  volatile u_int32_t ALT_AES_MUTE_MASK;           /*       0x10 - 0x14       */
  volatile u_int32_t Crypto_misc_Control;         /*       0x14 - 0x18       */
  volatile u_int32_t Crypto_SM_States;            /*       0x18 - 0x1c       */
  volatile u_int32_t Crypto_testbus_sel;          /*       0x1c - 0x20       */
  volatile u_int32_t Crypto_testbus_LSB;          /*       0x20 - 0x24       */
  volatile u_int32_t Crypto_testbus_MSB;          /*       0x24 - 0x28       */
  volatile u_int32_t DEBUG_Interrupt_Status;      /*       0x28 - 0x2c       */
  volatile u_int32_t Crypto_clock_gate_enable;    /*       0x2c - 0x30       */
  volatile u_int32_t WATCHDOG_TIMER_VALUE;        /*       0x30 - 0x34       */
  volatile u_int32_t Dbg_Crypto_counters_control; /*       0x34 - 0x38       */
  volatile u_int32_t Dbg_tx_mpdu_cnt;             /*       0x38 - 0x3c       */
  volatile u_int32_t Dbg_tx_encr_frame_cnt;       /*       0x3c - 0x40       */
  volatile u_int32_t Dbg_tx_flush_rcv_cnt;        /*       0x40 - 0x44       */
  volatile u_int32_t Dbg_tx_flush_req_cnt;        /*       0x44 - 0x48       */
  volatile u_int32_t Dbg_tx_abort_cnt;            /*       0x48 - 0x4c       */
  volatile u_int32_t Dbg_rx_mpdu_cnt;             /*       0x4c - 0x50       */
  volatile u_int32_t Dbg_rx_decr_frame_cnt;       /*       0x50 - 0x54       */
  volatile u_int32_t Dbg_rx_abort_cnt;            /*       0x54 - 0x58       */
  volatile u_int32_t Spare_Reg;                   /*       0x58 - 0x5c       */
  volatile u_int32_t FIPS_Control;                /*       0x5c - 0x60       */
  volatile u_int32_t FIPS_AES_KEY[8];             /*       0x60 - 0x80       */
  volatile u_int32_t FIPS_AES_DATA_IN[4];         /*       0x80 - 0x90       */
  volatile u_int32_t FIPS_AES_DATA_OUT[4];        /*       0x90 - 0xa0       */
  volatile u_int32_t EVENTBUS_MASK;               /*       0xa0 - 0xa4       */
  volatile u_int32_t WATCHDOG_TIMER_THRESHOLD;    /*       0xa4 - 0xa8       */
};

struct mac_hwsch_reg {
  volatile u_int32_t HWSCH_DIFS_LIMIT_1_0;        /*        0x0 - 0x4        */
  volatile u_int32_t HWSCH_DIFS_LIMIT_3_2;        /*        0x4 - 0x8        */
  volatile u_int32_t HWSCH_DIFS_LIMIT_5_4;        /*        0x8 - 0xc        */
  volatile u_int32_t HWSCH_DIFS_LIMIT_7_6;        /*        0xc - 0x10       */
  volatile u_int32_t HWSCH_DIFS_LIMIT_9_8;        /*       0x10 - 0x14       */
  volatile u_int32_t HWSCH_DIFS_LIMIT_11_10;      /*       0x14 - 0x18       */
  volatile u_int32_t HWSCH_DIFS_LIMIT_13_12;      /*       0x18 - 0x1c       */
  volatile u_int32_t HWSCH_DIFS_LIMIT_15_14;      /*       0x1c - 0x20       */
  volatile u_int32_t HWSCH_EIFS_PIFS_BCN_SLOT_LIMIT;
                                                  /*       0x20 - 0x24       */
  volatile u_int32_t HWSCH_EIFS_PIFS_BCN_SLOT_LIMIT_1;
                                                  /*       0x24 - 0x28       */
  volatile u_int32_t HWSCH_COEX_CTRL;             /*       0x28 - 0x2c       */
  volatile unsigned int pad__0;                   /*       0x2c - 0x30       */
  volatile u_int32_t HWSCH_NAV_CNT;               /*       0x30 - 0x34       */
  volatile u_int32_t HWSCH_SW_MTU_SHADOW_NAV_CNT; /*       0x34 - 0x38       */
  volatile u_int32_t HWSCH_BKOF_CNT_0_1;          /*       0x38 - 0x3c       */
  volatile unsigned int pad__1;                   /*       0x3c - 0x40       */
  volatile u_int32_t HWSCH_BKOF_CNT_2_3;          /*       0x40 - 0x44       */
  volatile unsigned int pad__2;                   /*       0x44 - 0x48       */
  volatile u_int32_t HWSCH_BKOF_CNT_4_5;          /*       0x48 - 0x4c       */
  volatile unsigned int pad__3;                   /*       0x4c - 0x50       */
  volatile u_int32_t HWSCH_BKOF_CNT_6_7;          /*       0x50 - 0x54       */
  volatile unsigned int pad__4;                   /*       0x54 - 0x58       */
  volatile u_int32_t HWSCH_BKOF_CNT_8_9;          /*       0x58 - 0x5c       */
  volatile unsigned int pad__5;                   /*       0x5c - 0x60       */
  volatile u_int32_t HWSCH_BKOF_CNT_10_11;        /*       0x60 - 0x64       */
  volatile unsigned int pad__6;                   /*       0x64 - 0x68       */
  volatile u_int32_t HWSCH_BKOF_CNT_12_13;        /*       0x68 - 0x6c       */
  volatile unsigned int pad__7;                   /*       0x6c - 0x70       */
  volatile u_int32_t HWSCH_BKOF_CNT_14_15;        /*       0x70 - 0x74       */
  volatile unsigned int pad__8;                   /*       0x74 - 0x78       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_0;
                                                  /*       0x78 - 0x7c       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_1;
                                                  /*       0x7c - 0x80       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_2;
                                                  /*       0x80 - 0x84       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_3;
                                                  /*       0x84 - 0x88       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_4;
                                                  /*       0x88 - 0x8c       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_5;
                                                  /*       0x8c - 0x90       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_6;
                                                  /*       0x90 - 0x94       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_7;
                                                  /*       0x94 - 0x98       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_8;
                                                  /*       0x98 - 0x9c       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_9;
                                                  /*       0x9c - 0xa0       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_10;
                                                  /*       0xa0 - 0xa4       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_11;
                                                  /*       0xa4 - 0xa8       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_12;
                                                  /*       0xa8 - 0xac       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_13;
                                                  /*       0xac - 0xb0       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_14;
                                                  /*       0xb0 - 0xb4       */
  volatile u_int32_t HWSCH_CW_REG_CONTROL_FOR_BACKOFF_15;
                                                  /*       0xb4 - 0xb8       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_0;    /*       0xb8 - 0xbc       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_1;    /*       0xbc - 0xc0       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_2;    /*       0xc0 - 0xc4       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_3;    /*       0xc4 - 0xc8       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_4;    /*       0xc8 - 0xcc       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_5;    /*       0xcc - 0xd0       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_6;    /*       0xd0 - 0xd4       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_7;    /*       0xd4 - 0xd8       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_8;    /*       0xd8 - 0xdc       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_9;    /*       0xdc - 0xe0       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_10;   /*       0xe0 - 0xe4       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_11;   /*       0xe4 - 0xe8       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_12;   /*       0xe8 - 0xec       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_13;   /*       0xec - 0xf0       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_14;   /*       0xf0 - 0xf4       */
  volatile u_int32_t HWSCH_SW_CW_MIN_CW_MAX_15;   /*       0xf4 - 0xf8       */
  volatile u_int32_t HWSCH_CW_ACTION_CTRL;        /*       0xf8 - 0xfc       */
  volatile unsigned int pad__9;                   /*       0xfc - 0x100      */
  volatile u_int32_t HWSCH_MTU_TIMEOUT_STATUS;    /*      0x100 - 0x104      */
  volatile unsigned int pad__10[0x2];             /*      0x104 - 0x10c      */
  volatile u_int32_t HWSCH_CCA_COUNTER0;          /*      0x10c - 0x110      */
  volatile u_int32_t HWSCH_CCA_COUNTER1;          /*      0x110 - 0x114      */
  volatile u_int32_t HWSCH_CCA_COUNTER2;          /*      0x114 - 0x118      */
  volatile u_int32_t HWSCH_CCA_CONTROL_REG_1;     /*      0x118 - 0x11c      */
  volatile u_int32_t HWSCH_CCA_CONTROL_REG_2;     /*      0x11c - 0x120      */
  volatile u_int32_t HWSCH_CCA_CONTROL_REG_3;     /*      0x120 - 0x124      */
  volatile u_int32_t HWSCH_CCA_CONTROL_REG_4;     /*      0x124 - 0x128      */
  volatile u_int32_t HWSCH_CCA_CONTROL_REG_5;     /*      0x128 - 0x12c      */
  volatile u_int32_t HWSCH_CCA_CONTROL_REG_6;     /*      0x12c - 0x130      */
  volatile u_int32_t HWSCH_MTU_GLOBAL_CONTROL;    /*      0x130 - 0x134      */
  volatile u_int32_t HWSCH_PREBKOFF_LIMITS;       /*      0x134 - 0x138      */
  volatile u_int32_t HWSCH_MTU_FOR_HMAC_CONTROLS; /*      0x138 - 0x13c      */
  volatile u_int32_t HWSCH_LFSR_DATA_1_0;         /*      0x13c - 0x140      */
  volatile u_int32_t HWSCH_LFSR_DATA_3_2;         /*      0x140 - 0x144      */
  volatile u_int32_t HWSCH_LFSR_DATA_5_4;         /*      0x144 - 0x148      */
  volatile u_int32_t HWSCH_LFSR_DATA_7_6;         /*      0x148 - 0x14c      */
  volatile u_int32_t HWSCH_LFSR_DATA_9_8;         /*      0x14c - 0x150      */
  volatile u_int32_t HWSCH_LFSR_DATA_11_10;       /*      0x150 - 0x154      */
  volatile u_int32_t HWSCH_LFSR_DATA_13_12;       /*      0x154 - 0x158      */
  volatile u_int32_t HWSCH_LFSR_DATA_15_14;       /*      0x158 - 0x15c      */
  volatile u_int32_t HWSCH_LONG_SHORT_XMIT_LIMIT_0;
                                                  /*      0x15c - 0x160      */
  volatile u_int32_t HWSCH_LONG_SHORT_XMIT_LIMIT_1;
                                                  /*      0x160 - 0x164      */
  volatile u_int32_t HWSCH_LONG_SHORT_XMIT_LIMIT_2;
                                                  /*      0x164 - 0x168      */
  volatile u_int32_t HWSCH_LONG_SHORT_XMIT_LIMIT_3;
                                                  /*      0x168 - 0x16c      */
  volatile u_int32_t HWSCH_SW_MTU_SIFS_LIMIT_FORINNAV;
                                                  /*      0x16c - 0x170      */
  volatile u_int32_t HWSCH_PRIMARY_CCA_HISTOGRAM_LOW;
                                                  /*      0x170 - 0x174      */
  volatile u_int32_t HWSCH_PRIMARY_CCA_HISTOGRAM_HIGH;
                                                  /*      0x174 - 0x178      */
  volatile u_int32_t HWSCH_SECONDARY_CCA_HISTOGRAM_LOW;
                                                  /*      0x178 - 0x17c      */
  volatile u_int32_t HWSCH_SECONDARY_CCA_HISTOGRAM_HIGH;
                                                  /*      0x17c - 0x180      */
  volatile u_int32_t HWSCH_TERTIARY_CCA_HISTOGRAM_LOW;
                                                  /*      0x180 - 0x184      */
  volatile u_int32_t HWSCH_TERTIARY_CCA_HISTOGRAM_HIGH;
                                                  /*      0x184 - 0x188      */
  volatile u_int32_t HWSCH_QUATERNARY_CCA_HISTOGRAM_LOW;
                                                  /*      0x188 - 0x18c      */
  volatile u_int32_t HWSCH_QUATERNARY_CCA_HISTOGRAM_HIGH;
                                                  /*      0x18c - 0x190      */
  volatile unsigned int pad__11[0x3];             /*      0x190 - 0x19c      */
  volatile u_int32_t HWSCH_SW_CCA_HISTOGRAM_MASK_MISC;
                                                  /*      0x19c - 0x1a0      */
  volatile u_int32_t HWSCH_CCA_SECONDARY_HISTOGRAM;
                                                  /*      0x1a0 - 0x1a4      */
  volatile u_int32_t HWSCH_CCA_TERTIARY_HISTOGRAM;
                                                  /*      0x1a4 - 0x1a8      */
  volatile u_int32_t HWSCH_CCA_QUATERNARY_HISTOGRAM;
                                                  /*      0x1a8 - 0x1ac      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_0;       /*      0x1ac - 0x1b0      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_1;       /*      0x1b0 - 0x1b4      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_2;       /*      0x1b4 - 0x1b8      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_3;       /*      0x1b8 - 0x1bc      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_4;       /*      0x1bc - 0x1c0      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_5;       /*      0x1c0 - 0x1c4      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_6;       /*      0x1c4 - 0x1c8      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_7;       /*      0x1c8 - 0x1cc      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_8;       /*      0x1cc - 0x1d0      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_9;       /*      0x1d0 - 0x1d4      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_10;      /*      0x1d4 - 0x1d8      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_11;      /*      0x1d8 - 0x1dc      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_12;      /*      0x1dc - 0x1e0      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_13;      /*      0x1e0 - 0x1e4      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_14;      /*      0x1e4 - 0x1e8      */
  volatile u_int32_t HWSCH_CMD_RING_BASE_15;      /*      0x1e8 - 0x1ec      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_0;  /*      0x1ec - 0x1f0      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_1;  /*      0x1f0 - 0x1f4      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_2;  /*      0x1f4 - 0x1f8      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_3;  /*      0x1f8 - 0x1fc      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_4;  /*      0x1fc - 0x200      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_5;  /*      0x200 - 0x204      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_6;  /*      0x204 - 0x208      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_7;  /*      0x208 - 0x20c      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_8;  /*      0x20c - 0x210      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_9;  /*      0x210 - 0x214      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_10; /*      0x214 - 0x218      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_11; /*      0x218 - 0x21c      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_12; /*      0x21c - 0x220      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_13; /*      0x220 - 0x224      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_14; /*      0x224 - 0x228      */
  volatile u_int32_t HWSCH_CMD_RING_NUM_ENTRY_15; /*      0x228 - 0x22c      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_0;       /*      0x22c - 0x230      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_1;       /*      0x230 - 0x234      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_2;       /*      0x234 - 0x238      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_3;       /*      0x238 - 0x23c      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_4;       /*      0x23c - 0x240      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_5;       /*      0x240 - 0x244      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_6;       /*      0x244 - 0x248      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_7;       /*      0x248 - 0x24c      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_8;       /*      0x24c - 0x250      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_9;       /*      0x250 - 0x254      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_10;      /*      0x254 - 0x258      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_11;      /*      0x258 - 0x25c      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_12;      /*      0x25c - 0x260      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_13;      /*      0x260 - 0x264      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_14;      /*      0x264 - 0x268      */
  volatile u_int32_t HWSCH_CMD_RING_HEAD_15;      /*      0x268 - 0x26c      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_0;       /*      0x26c - 0x270      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_1;       /*      0x270 - 0x274      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_2;       /*      0x274 - 0x278      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_3;       /*      0x278 - 0x27c      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_4;       /*      0x27c - 0x280      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_5;       /*      0x280 - 0x284      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_6;       /*      0x284 - 0x288      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_7;       /*      0x288 - 0x28c      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_8;       /*      0x28c - 0x290      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_9;       /*      0x290 - 0x294      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_10;      /*      0x294 - 0x298      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_11;      /*      0x298 - 0x29c      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_12;      /*      0x29c - 0x2a0      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_13;      /*      0x2a0 - 0x2a4      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_14;      /*      0x2a4 - 0x2a8      */
  volatile u_int32_t HWSCH_CMD_RING_TAIL_15;      /*      0x2a8 - 0x2ac      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_0;  /*      0x2ac - 0x2b0      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_1;  /*      0x2b0 - 0x2b4      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_2;  /*      0x2b4 - 0x2b8      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_3;  /*      0x2b8 - 0x2bc      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_4;  /*      0x2bc - 0x2c0      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_5;  /*      0x2c0 - 0x2c4      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_6;  /*      0x2c4 - 0x2c8      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_7;  /*      0x2c8 - 0x2cc      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_8;  /*      0x2cc - 0x2d0      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_9;  /*      0x2d0 - 0x2d4      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_10; /*      0x2d4 - 0x2d8      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_11; /*      0x2d8 - 0x2dc      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_12; /*      0x2dc - 0x2e0      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_13; /*      0x2e0 - 0x2e4      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_14; /*      0x2e4 - 0x2e8      */
  volatile u_int32_t HWSCH_CMD_RING_THRESHOLD_15; /*      0x2e8 - 0x2ec      */
  volatile u_int32_t HWSCH_STATUS_BASE;           /*      0x2ec - 0x2f0      */
  volatile u_int32_t HWSCH_STATUS_NUM_ENTRY;      /*      0x2f0 - 0x2f4      */
  volatile u_int32_t HWSCH_STATUS_HEAD;           /*      0x2f4 - 0x2f8      */
  volatile u_int32_t HWSCH_STATUS_TAIL;           /*      0x2f8 - 0x2fc      */
  volatile u_int32_t HWSCH_STATUS_RING_THRESHOLDS;
                                                  /*      0x2fc - 0x300      */
  volatile u_int32_t HWSCH_WATCHDOG_TIMER;        /*      0x300 - 0x304      */
  volatile u_int32_t HWSCH_AXI_TIMEOUT;           /*      0x304 - 0x308      */
  volatile u_int32_t HWSCH_CMD_RING_PAUSE;        /*      0x308 - 0x30c      */
  volatile u_int32_t HWSCH_FLUSH_CONTROL;         /*      0x30c - 0x310      */
  volatile u_int32_t HWSCH_SEND_FLUSH;            /*      0x310 - 0x314      */
  volatile u_int32_t HWSCH_FLUSH_STATUS;          /*      0x314 - 0x318      */
  volatile u_int32_t HWSCH_BOUNDARY_TIMER0;       /*      0x318 - 0x31c      */
  volatile u_int32_t HWSCH_BOUNDARY_TIMER1;       /*      0x31c - 0x320      */
  volatile u_int32_t HWSCH_BOUNDARY_TIMER2;       /*      0x320 - 0x324      */
  volatile u_int32_t HWSCH_BOUNDARY_TIMER3;       /*      0x324 - 0x328      */
  volatile u_int32_t HWSCH_TXOP_CONTROL0;         /*      0x328 - 0x32c      */
  volatile u_int32_t HWSCH_TXOP_CONTROL1;         /*      0x32c - 0x330      */
  volatile u_int32_t HWSCH_TXOP_CONTROL2;         /*      0x330 - 0x334      */
  volatile u_int32_t HWSCH_TXOP_CONTROL3;         /*      0x334 - 0x338      */
  volatile u_int32_t HWSCH_DEBUG_SELECT;          /*      0x338 - 0x33c      */
  volatile u_int32_t HWSCH_DEBUG_OBS_U32;         /*      0x33c - 0x340      */
  volatile u_int32_t HWSCH_DEBUG_OBS_L32;         /*      0x340 - 0x344      */
  volatile u_int32_t HWSCH_MGMT_STATS_CTRL;       /*      0x344 - 0x348      */
  volatile u_int32_t HWSCH_ACK_PASS_STATS;        /*      0x348 - 0x34c      */
  volatile u_int32_t HWSCH_RETRY_STATS;           /*      0x34c - 0x350      */
  volatile u_int32_t HWSCH_REQUEUE_STATS;         /*      0x350 - 0x354      */
  volatile u_int32_t HWSCH_FILTER_STATS;          /*      0x354 - 0x358      */
  volatile u_int32_t HWSCH_BSPLIT_STATS;          /*      0x358 - 0x35c      */
  volatile u_int32_t HWSCH_FLUSH_STATS;           /*      0x35c - 0x360      */
  volatile u_int32_t HWSCH_SEQEND_BIN_REG_0;      /*      0x360 - 0x364      */
  volatile u_int32_t HWSCH_SEQEND_BIN_REG_1;      /*      0x364 - 0x368      */
  volatile u_int32_t HWSCH_TLV_IF_STATS;          /*      0x368 - 0x36c      */
  volatile u_int32_t HWSCH_CMD_MGR_GLB_CTRL;      /*      0x36c - 0x370      */
  volatile u_int32_t HWSCH_WATCHDOG_STATUS;       /*      0x370 - 0x374      */
  volatile u_int32_t HWSCH_CLK_GATE_CONTROL;      /*      0x374 - 0x378      */
  volatile u_int32_t HWSCH_EVT_CTRL_MTU_MASK;     /*      0x378 - 0x37c      */
  volatile u_int32_t MAC_SCH_EVENT_MASK_31_0;     /*      0x37c - 0x380      */
  volatile u_int32_t MAC_SCH_EVENT_MASK_63_32;    /*      0x380 - 0x384      */
  volatile u_int32_t HWSCH_QUIET_FLUSH_STATS;     /*      0x384 - 0x388      */
  volatile u_int32_t HWSCH_INTERNAL_CTL;          /*      0x388 - 0x38c      */
};

struct mac_mxi_reg {
  volatile u_int32_t MXI_CFG_1;                   /*        0x0 - 0x4        */
  volatile u_int32_t MXI_CFG_2;                   /*        0x4 - 0x8        */
  volatile u_int32_t MXI_CFG_3;                   /*        0x8 - 0xc        */
  volatile u_int32_t MXI_CFG_4;                   /*        0xc - 0x10       */
  volatile u_int32_t MXI_CFG_5;                   /*       0x10 - 0x14       */
  volatile u_int32_t MXI_CFG_6;                   /*       0x14 - 0x18       */
  volatile u_int32_t MXI_CFG_7;                   /*       0x18 - 0x1c       */
  volatile u_int32_t MXI_CFG_8;                   /*       0x1c - 0x20       */
  volatile u_int32_t MXI_CFG_9;                   /*       0x20 - 0x24       */
  volatile u_int32_t MXI_CFG_10;                  /*       0x24 - 0x28       */
  volatile u_int32_t MXI_CFG_11;                  /*       0x28 - 0x2c       */
  volatile u_int32_t MXI_CFG_12;                  /*       0x2c - 0x30       */
  volatile u_int32_t MXI_STATUS;                  /*       0x30 - 0x34       */
  volatile u_int32_t MXI_RD_ERR_RESP;             /*       0x34 - 0x38       */
  volatile u_int32_t MXI_WR_ERR_RESP;             /*       0x38 - 0x3c       */
  volatile u_int32_t MXI_DEBUG_CUR_RD_MASTER;     /*       0x3c - 0x40       */
  volatile u_int32_t MXI_DEBUG_CUR_WR_MASTER;     /*       0x40 - 0x44       */
  volatile u_int32_t MXI_CLOCK_GATE_DISABLE;      /*       0x44 - 0x48       */
};

struct wmac_top_reg_map {
  volatile unsigned int pad__0[0x4000];           /*        0x0 - 0x10000    */
  struct mac_pdg_reg mac_pdg_reg;                 /*    0x10000 - 0x10088    */
  volatile unsigned int pad__1[0xde];             /*    0x10088 - 0x10400    */
  struct mac_txdma_reg mac_txdma_reg;             /*    0x10400 - 0x1045c    */
  volatile unsigned int pad__2[0xe9];             /*    0x1045c - 0x10800    */
  struct mac_rxdma_reg mac_rxdma_reg;             /*    0x10800 - 0x108d8    */
  volatile unsigned int pad__3[0xca];             /*    0x108d8 - 0x10c00    */
  struct mac_ole_reg mac_ole_reg;                 /*    0x10c00 - 0x10d40    */
  volatile unsigned int pad__4[0xb0];             /*    0x10d40 - 0x11000    */
  struct mac_mcmn_reg mac_mcmn_reg;               /*    0x11000 - 0x11250    */
  volatile unsigned int pad__5[0x26c];            /*    0x11250 - 0x11c00    */
  struct mac_trc_reg mac_trc_reg;                 /*    0x11c00 - 0x11c90    */
  volatile unsigned int pad__6[0xdc];             /*    0x11c90 - 0x12000    */
  struct mac_rxpcu_reg mac_rxpcu_reg;             /*    0x12000 - 0x15000    */
  volatile unsigned int pad__7[0x400];            /*    0x15000 - 0x16000    */
  struct mac_txpcu_reg mac_txpcu_reg;             /*    0x16000 - 0x19800    */
  volatile unsigned int pad__8[0x200];            /*    0x19800 - 0x1a000    */
  struct mac_ampi_reg mac_ampi_reg;               /*    0x1a000 - 0x1a81c    */
  volatile unsigned int pad__9[0x11f9];           /*    0x1a81c - 0x1f000    */
  struct mac_crypto_reg mac_crypto_reg;           /*    0x1f000 - 0x1f0a8    */
  volatile unsigned int pad__10[0xd6];            /*    0x1f0a8 - 0x1f400    */
  struct mac_hwsch_reg mac_hwsch_reg;             /*    0x1f400 - 0x1f78c    */
  volatile unsigned int pad__11[0x11d];           /*    0x1f78c - 0x1fc00    */
  struct mac_mxi_reg mac_mxi_reg;                 /*    0x1fc00 - 0x1fc48    */
};

struct mac_wificmn_reg {
  volatile u_int32_t WIFICMN_ISR_P;               /*        0x0 - 0x4        */
  volatile u_int32_t WIFICMN_ISR_S0;              /*        0x4 - 0x8        */
  volatile u_int32_t WIFICMN_ISR_S1;              /*        0x8 - 0xc        */
  volatile u_int32_t WIFICMN_ISR_S2;              /*        0xc - 0x10       */
  volatile u_int32_t WIFICMN_ISR_S3;              /*       0x10 - 0x14       */
  volatile u_int32_t WIFICMN_IMR_P;               /*       0x14 - 0x18       */
  volatile u_int32_t WIFICMN_IMR_P_CONTD;         /*       0x18 - 0x1c       */
  volatile u_int32_t WIFICMN_IMR_S0;              /*       0x1c - 0x20       */
  volatile u_int32_t WIFICMN_IMR_S1;              /*       0x20 - 0x24       */
  volatile unsigned int pad__0;                   /*       0x24 - 0x28       */
  volatile u_int32_t WIFICMN_IMR_S2;              /*       0x28 - 0x2c       */
  volatile u_int32_t WIFICMN_IMR_S3;              /*       0x2c - 0x30       */
  volatile u_int32_t WIFICMN_PCIE_BAR_REG;        /*       0x30 - 0x34       */
  volatile u_int32_t WIFICMN_CTRL_REG;            /*       0x34 - 0x38       */
  volatile u_int32_t WIFICMN_CPU_MEM;             /*       0x38 - 0x3c       */
  volatile u_int32_t WIFICMN_WOCLR_ISR_P_EN;      /*       0x3c - 0x40       */
  volatile u_int32_t WIFICMN_LF_HF_WDT_INT_STATUS;
                                                  /*       0x40 - 0x44       */
  volatile u_int32_t WIFICMN_SCRATCH_0;           /*       0x44 - 0x48       */
  volatile u_int32_t WIFICMN_SCRATCH_1;           /*       0x48 - 0x4c       */
  volatile u_int32_t WIFICMN_SCRATCH_2;           /*       0x4c - 0x50       */
  volatile u_int32_t WIFICMN_SCRATCH_3;           /*       0x50 - 0x54       */
  volatile u_int32_t WIFICMN_INT_STATUS;          /*       0x54 - 0x58       */
  volatile u_int32_t WIFICMN_INT_STATUS_CONTD;    /*       0x58 - 0x5c       */
  volatile u_int32_t WIFICMN_TESTBUS_SELECT;      /*       0x5c - 0x60       */
  volatile u_int32_t WIFICMN_OBS_SELECT;          /*       0x60 - 0x64       */
  volatile u_int32_t WIFICMN_OBS_BYTE_LANE_SELECT;
                                                  /*       0x64 - 0x68       */
  volatile u_int32_t WIFICMN_CLK_GATE_EN;         /*       0x68 - 0x6c       */
  volatile u_int32_t WIFICMN_PHY_TRACE_BUS_SEL;   /*       0x6c - 0x70       */
  volatile u_int32_t WIFICMN_EVENTBUS_SELECT;     /*       0x70 - 0x74       */
  volatile u_int32_t WIFICMN_ECO_SPARE_REG;       /*       0x74 - 0x78       */
  volatile u_int32_t WIFICMN_MCMN_CLK_GATE_DISABLE;
                                                  /*       0x78 - 0x7c       */
  volatile u_int32_t WIFICMN_MEM_CNTL;            /*       0x7c - 0x80       */
  volatile u_int32_t WIFICMN_PIFAXI_PRIORITY;     /*       0x80 - 0x84       */
};

struct wifi_timers_reg {
  volatile u_int32_t WIFI_TIMERS_SLP32_MODE;      /*        0x0 - 0x4        */
  volatile u_int32_t WIFI_TIMERS_SLP32_WAKE;      /*        0x4 - 0x8        */
  volatile u_int32_t WIFI_TIMERS_SLP32_INC;       /*        0x8 - 0xc        */
  volatile u_int32_t WIFI_TIMERS_SLP_MIB1;        /*        0xc - 0x10       */
  volatile u_int32_t WIFI_TIMERS_SLP_MIB2;        /*       0x10 - 0x14       */
  volatile u_int32_t WIFI_TIMERS_SLP_MIB3;        /*       0x14 - 0x18       */
  volatile u_int32_t WIFI_TIMERS_TSF_L32;         /*       0x18 - 0x1c       */
  volatile u_int32_t WIFI_TIMERS_TSF_U32;         /*       0x1c - 0x20       */
  volatile u_int32_t WIFI_TIMERS_WBTIMER_0;       /*       0x20 - 0x24       */
  volatile u_int32_t WIFI_TIMERS_WBTIMER_1;       /*       0x24 - 0x28       */
  volatile u_int32_t WIFI_TIMERS_GENERIC_TIMERS[16];
                                                  /*       0x28 - 0x68       */
  volatile u_int32_t WIFI_TIMERS_GENERIC_TIMERS_MODE;
                                                  /*       0x68 - 0x6c       */
  volatile u_int32_t WIFI_TIMERS_SLP1;            /*       0x6c - 0x70       */
  volatile u_int32_t WIFI_TIMERS_SLP2;            /*       0x70 - 0x74       */
  volatile u_int32_t WIFI_TIMERS_SLP3;            /*       0x74 - 0x78       */
  volatile u_int32_t WIFI_TIMERS_SLP4;            /*       0x78 - 0x7c       */
  volatile u_int32_t WIFI_TIMERS_DIRECT_CONNECT;  /*       0x7c - 0x80       */
  volatile unsigned int pad__0[0x3];              /*       0x80 - 0x8c       */
  volatile u_int32_t WIFI_TIMERS_RESET_TSF;       /*       0x8c - 0x90       */
  volatile u_int32_t WIFI_TIMERS_TSF2_L32;        /*       0x90 - 0x94       */
  volatile u_int32_t WIFI_TIMERS_TSF2_U32;        /*       0x94 - 0x98       */
  volatile u_int32_t WIFI_TIMERS_GENERIC_TIMERS2[16];
                                                  /*       0x98 - 0xd8       */
  volatile u_int32_t WIFI_TIMERS_GENERIC_TIMERS_MODE2;
                                                  /*       0xd8 - 0xdc       */
  volatile u_int32_t WIFI_TIMERS_TSF_THRESHOLD;   /*       0xdc - 0xe0       */
  volatile u_int32_t WIFI_TIMERS_GENERIC_TIMERS_TSF_SEL;
                                                  /*       0xe0 - 0xe4       */
  volatile u_int32_t WIFI_TIMERS_BMISS_TIMEOUT;   /*       0xe4 - 0xe8       */
  volatile u_int32_t WIFI_TIMERS_BMISS2_TIMEOUT;  /*       0xe8 - 0xec       */
  volatile u_int32_t WIFI_TIMERS_QUIET_TIME_2;    /*       0xec - 0xf0       */
  volatile u_int32_t WIFI_TIMERS_HCF_TIMEOUT;     /*       0xf0 - 0xf4       */
  volatile u_int32_t WIFI_TIMERS_MISC_MODE;       /*       0xf4 - 0xf8       */
  volatile u_int32_t WIFI_TIMERS_USEC_LATENCY;    /*       0xf8 - 0xfc       */
  volatile u_int32_t WIFI_TIMERS_MAX_CFP_DUR;     /*       0xfc - 0x100      */
};

struct wifi_pta_coex_reg {
  volatile u_int32_t PTA_COEX_BLUETOOTH_MODE;     /*        0x0 - 0x4        */
  volatile u_int32_t PTA_COEX_BLUETOOTH_MODE2;    /*        0x4 - 0x8        */
  volatile u_int32_t PTA_COEX_BLUETOOTH_MODE3;    /*        0x8 - 0xc        */
  volatile u_int32_t PTA_COEX_BLUETOOTH_MODE4;    /*        0xc - 0x10       */
  volatile u_int32_t PTA_COEX_BLUETOOTH_MODE5;    /*       0x10 - 0x14       */
  volatile u_int32_t PTA_COEX_BLUETOOTH_WBCNT_BT_ACTIVE;
                                                  /*       0x14 - 0x18       */
  volatile u_int32_t PTA_COEX_BLUETOOTH_WBCNT_BT_PRIORITY;
                                                  /*       0x18 - 0x1c       */
  volatile unsigned int pad__0;                   /*       0x1c - 0x20       */
  volatile u_int32_t PTA_COEX_BT_BT[64];          /*       0x20 - 0x120      */
  volatile u_int32_t PTA_COEX_BT_BT_ASYNC;        /*      0x120 - 0x124      */
  volatile u_int32_t PTA_COEX_BT_WL_1;            /*      0x124 - 0x128      */
  volatile u_int32_t PTA_COEX_BT_WL_2;            /*      0x128 - 0x12c      */
  volatile u_int32_t PTA_COEX_BT_WL_3;            /*      0x12c - 0x130      */
  volatile u_int32_t PTA_COEX_BT_WL_4;            /*      0x130 - 0x134      */
  volatile unsigned int pad__1;                   /*      0x134 - 0x138      */
  volatile u_int32_t PTA_COEX_QUIET_TIME_1;       /*      0x138 - 0x13c      */
  volatile u_int32_t PTA_COEX_BT_ANT_SLEEP_EXTEND;
                                                  /*      0x13c - 0x140      */
};

struct Wlan_CxM_reg_csr {
  volatile u_int32_t UART_DATA;                   /*        0x0 - 0x4        */
  volatile u_int32_t UART_CONTROL;                /*        0x4 - 0x8        */
  volatile u_int32_t UART_TX_FIFO1;               /*        0x8 - 0xc        */
  volatile u_int32_t UART_TX_FIFO2;               /*        0xc - 0x10       */
  volatile u_int32_t UART_RX_FIFO;                /*       0x10 - 0x14       */
  volatile u_int32_t UART_CLKDIV;                 /*       0x14 - 0x18       */
  volatile u_int32_t UART_INT;                    /*       0x18 - 0x1c       */
  volatile u_int32_t UART_INT_EN;                 /*       0x1c - 0x20       */
  volatile u_int32_t WB_CNT_FSYNC_RE;             /*       0x20 - 0x24       */
  volatile u_int32_t WB_CNT_ACTIVE_RE;            /*       0x24 - 0x28       */
  volatile u_int32_t WB_CNT_ACTIVE_FE;            /*       0x28 - 0x2c       */
  volatile u_int32_t WB_CNT_MWS_TX_RE;            /*       0x2c - 0x30       */
  volatile u_int32_t WB_CNT_MWS_TX_FE;            /*       0x30 - 0x34       */
  volatile u_int32_t WB_CNT_MWS_RX_RE;            /*       0x34 - 0x38       */
  volatile u_int32_t WB_CNT_MWS_RX_FE;            /*       0x38 - 0x3c       */
  volatile u_int32_t WB_CNT_RX_TYPE7;             /*       0x3c - 0x40       */
  volatile u_int32_t WB_CNT_RX_TYPE6;             /*       0x40 - 0x44       */
  volatile u_int32_t WB_CNT_RX_TYPE5;             /*       0x44 - 0x48       */
  volatile u_int32_t WB_CNT_RX_TYPE4;             /*       0x48 - 0x4c       */
  volatile u_int32_t WB_CNT_RX_TYPE3;             /*       0x4c - 0x50       */
  volatile u_int32_t WB_CNT_RX_TYPE2;             /*       0x50 - 0x54       */
  volatile u_int32_t WB_CNT_RX_TYPE1;             /*       0x54 - 0x58       */
  volatile u_int32_t WB_CNT_RX_TYPE0;             /*       0x58 - 0x5c       */
  volatile u_int32_t RX_CxM_MSG_CONTENT1;         /*       0x5c - 0x60       */
  volatile u_int32_t RX_CxM_MSG_CONTENT2;         /*       0x60 - 0x64       */
  volatile u_int32_t CxM_Ctrl1;                   /*       0x64 - 0x68       */
  volatile u_int32_t CxM_Ctrl2;                   /*       0x68 - 0x6c       */
  volatile u_int32_t CxM_Ctrl3;                   /*       0x6c - 0x70       */
  volatile u_int32_t CxM_Ctrl4;                   /*       0x70 - 0x74       */
  volatile u_int32_t Timer0_Int_Start;            /*       0x74 - 0x78       */
  volatile u_int32_t Timer0_Int_Period;           /*       0x78 - 0x7c       */
  volatile u_int32_t Timer1_Int_Start;            /*       0x7c - 0x80       */
  volatile u_int32_t Timer1_Int_Period;           /*       0x80 - 0x84       */
  volatile u_int32_t Tx_Grant_Thr1;               /*       0x84 - 0x88       */
  volatile u_int32_t Tx_Grant_Thr2;               /*       0x88 - 0x8c       */
  volatile u_int32_t Rx_Grant_Thr1;               /*       0x8c - 0x90       */
  volatile u_int32_t Rx_Grant_Thr2;               /*       0x90 - 0x94       */
  volatile u_int32_t Rx_Pri_Thr1;                 /*       0x94 - 0x98       */
  volatile u_int32_t Rx_Pri_Thr2;                 /*       0x98 - 0x9c       */
  volatile u_int32_t BT_Rx_Pri_Thr1;              /*       0x9c - 0xa0       */
  volatile u_int32_t BT_Rx_Pri_Thr2;              /*       0xa0 - 0xa4       */
};

struct wifi_lte_coex_reg {
  volatile u_int32_t LTE_COEX_CTRL;               /*        0x0 - 0x4        */
};

struct wifi_rtc_reg {
  volatile u_int32_t WIFI_RESET_CONTROL;          /*        0x0 - 0x4        */
  volatile u_int32_t WIFI_XTAL_CONTROL;           /*        0x4 - 0x8        */
  volatile unsigned int pad__0[0x2];              /*        0x8 - 0x10       */
  volatile u_int32_t WIFI_QUADRATURE;             /*       0x10 - 0x14       */
  volatile u_int32_t WIFI_PLL_CONTROL;            /*       0x14 - 0x18       */
  volatile u_int32_t WIFI_PLL_SETTLE;             /*       0x18 - 0x1c       */
  volatile u_int32_t WIFI_XTAL_SETTLE;            /*       0x1c - 0x20       */
  volatile u_int32_t WIFI_CLOCK_OUT;              /*       0x20 - 0x24       */
  volatile u_int32_t WIFI_BIAS_OVERRIDE;          /*       0x24 - 0x28       */
  volatile u_int32_t WIFI_RESET_CAUSE;            /*       0x28 - 0x2c       */
  volatile u_int32_t WIFI_SYSTEM_SLEEP;           /*       0x2c - 0x30       */
  volatile u_int32_t WIFI_MAC_SLEEP_CONTROL;      /*       0x30 - 0x34       */
  volatile u_int32_t WIFI_KEEP_AWAKE;             /*       0x34 - 0x38       */
  volatile u_int32_t WIFI_DERIVED_RTC_CLK;        /*       0x38 - 0x3c       */
  volatile u_int32_t WIFI_RTC_SYNC_DERIVED;       /*       0x3c - 0x40       */
  volatile u_int32_t LF_TIMER0;                   /*       0x40 - 0x44       */
  volatile u_int32_t LF_TIMER_COUNT0;             /*       0x44 - 0x48       */
  volatile u_int32_t LF_TIMER_CONTROL0;           /*       0x48 - 0x4c       */
  volatile u_int32_t LF_TIMER_STATUS0;            /*       0x4c - 0x50       */
  volatile u_int32_t LF_TIMER1;                   /*       0x50 - 0x54       */
  volatile u_int32_t LF_TIMER_COUNT1;             /*       0x54 - 0x58       */
  volatile u_int32_t LF_TIMER_CONTROL1;           /*       0x58 - 0x5c       */
  volatile u_int32_t LF_TIMER_STATUS1;            /*       0x5c - 0x60       */
  volatile u_int32_t LF_TIMER2;                   /*       0x60 - 0x64       */
  volatile u_int32_t LF_TIMER_COUNT2;             /*       0x64 - 0x68       */
  volatile u_int32_t LF_TIMER_CONTROL2;           /*       0x68 - 0x6c       */
  volatile u_int32_t LF_TIMER_STATUS2;            /*       0x6c - 0x70       */
  volatile u_int32_t LF_TIMER3;                   /*       0x70 - 0x74       */
  volatile u_int32_t LF_TIMER_COUNT3;             /*       0x74 - 0x78       */
  volatile u_int32_t LF_TIMER_CONTROL3;           /*       0x78 - 0x7c       */
  volatile u_int32_t LF_TIMER_STATUS3;            /*       0x7c - 0x80       */
  volatile u_int32_t HF_TIMER;                    /*       0x80 - 0x84       */
  volatile u_int32_t HF_TIMER_COUNT;              /*       0x84 - 0x88       */
  volatile u_int32_t HF_LF_COUNT;                 /*       0x88 - 0x8c       */
  volatile u_int32_t HF_TIMER_CONTROL;            /*       0x8c - 0x90       */
  volatile u_int32_t HF_TIMER_STATUS;             /*       0x90 - 0x94       */
  volatile u_int32_t WDT_CONTROL;                 /*       0x94 - 0x98       */
  volatile u_int32_t WDT_STATUS;                  /*       0x98 - 0x9c       */
  volatile u_int32_t WDT;                         /*       0x9c - 0xa0       */
  volatile unsigned int pad__1[0x258];            /*       0xa0 - 0xa00      */
  volatile u_int32_t WDT_COUNT;                   /*      0xa00 - 0xa04      */
  volatile u_int32_t WDT_RESET;                   /*      0xa04 - 0xa08      */
  volatile u_int32_t WIFI_SLEEP_OVERRIDE;         /*      0xa08 - 0xa0c      */
  volatile u_int32_t WMAC_SLEEP_OVERRIDE;         /*      0xa0c - 0xa10      */
  volatile u_int32_t BB_PLL_CONFIG;               /*      0xa10 - 0xa14      */
};

struct ce_reg_csr {
  volatile u_int32_t SR_BA;                       /*        0x0 - 0x4        */
  volatile u_int32_t SR_SIZE;                     /*        0x4 - 0x8        */
  volatile u_int32_t DR_BA;                       /*        0x8 - 0xc        */
  volatile u_int32_t DR_SIZE;                     /*        0xc - 0x10       */
  volatile u_int32_t CE_CTRL1;                    /*       0x10 - 0x14       */
  volatile u_int32_t CE_CTRL2;                    /*       0x14 - 0x18       */
  volatile u_int32_t CE_CMD;                      /*       0x18 - 0x1c       */
  volatile u_int32_t MSI_ADDR;                    /*       0x1c - 0x20       */
  volatile u_int32_t MSI_DATA;                    /*       0x20 - 0x24       */
  volatile u_int32_t TARGET_IE;                   /*       0x24 - 0x28       */
  volatile u_int32_t TARGET_IS;                   /*       0x28 - 0x2c       */
  volatile u_int32_t HOST_IE;                     /*       0x2c - 0x30       */
  volatile u_int32_t HOST_IS;                     /*       0x30 - 0x34       */
  volatile u_int32_t MISC_IE;                     /*       0x34 - 0x38       */
  volatile u_int32_t MISC_IS;                     /*       0x38 - 0x3c       */
  volatile u_int32_t SR_WR_INDEX;                 /*       0x3c - 0x40       */
  volatile u_int32_t DST_WR_INDEX;                /*       0x40 - 0x44       */
  volatile u_int32_t CURRENT_SRRI;                /*       0x44 - 0x48       */
  volatile u_int32_t CURRENT_DRRI;                /*       0x48 - 0x4c       */
  volatile u_int32_t SRC_WATERMARK;               /*       0x4c - 0x50       */
  volatile u_int32_t DST_WATERMARK;               /*       0x50 - 0x54       */
  volatile u_int32_t CE_DEBUG;                    /*       0x54 - 0x58       */
  volatile u_int32_t CE_WATCHDOG;                 /*       0x58 - 0x5c       */
};

struct ce_wrapper_reg_csr {
  volatile u_int32_t CE_WRAPPER_INTERRUPT_SUMMARY;
                                                  /*        0x0 - 0x4        */
  volatile u_int32_t NUM_AXI_OUTSTANDING;         /*        0x4 - 0x8        */
  volatile u_int32_t CE_WRAPPER_DEBUG;            /*        0x8 - 0xc        */
  volatile u_int32_t CPU_MEM_ADDR;                /*        0xc - 0x10       */
  volatile u_int32_t CPU_MEM_DATA;                /*       0x10 - 0x14       */
  volatile u_int32_t CE_WRAPPER_WDG_TMR_IS;       /*       0x14 - 0x18       */
  volatile u_int32_t CE_WRAPPER_WDG_TMR_IE;       /*       0x18 - 0x1c       */
};

struct rffe_m_csr {
  volatile u_int32_t rffe_inte;                   /*        0x0 - 0x4        */
  volatile u_int32_t rffe_intf;                   /*        0x4 - 0x8        */
  volatile u_int32_t rffe_stat;                   /*        0x8 - 0xc        */
  volatile u_int32_t rffe_cfg;                    /*        0xc - 0x10       */
  volatile u_int32_t rffe_ctrl;                   /*       0x10 - 0x14       */
  volatile u_int32_t rffe_data;                   /*       0x14 - 0x18       */
};

struct rtc_soc_reg {
  volatile u_int32_t SOC_RESET_CONTROL;           /*        0x0 - 0x4        */
  volatile unsigned int pad__0[0x7];              /*        0x4 - 0x20       */
  volatile u_int32_t SOC_CPU_CLOCK;               /*       0x20 - 0x24       */
  volatile unsigned int pad__1;                   /*       0x24 - 0x28       */
  volatile u_int32_t SOC_CLOCK_CONTROL;           /*       0x28 - 0x2c       */
  volatile u_int32_t SOC_INT_STATUS;              /*       0x2c - 0x30       */
  volatile u_int32_t SOC_RTC_CONTROL;             /*       0x30 - 0x34       */
  volatile u_int32_t SOC_RTC_TIME;                /*       0x34 - 0x38       */
  volatile u_int32_t SOC_RTC_DATE;                /*       0x38 - 0x3c       */
  volatile u_int32_t SOC_RTC_SET_TIME;            /*       0x3c - 0x40       */
  volatile u_int32_t SOC_RTC_SET_DATE;            /*       0x40 - 0x44       */
  volatile u_int32_t SOC_RTC_SET_ALARM;           /*       0x44 - 0x48       */
  volatile u_int32_t SOC_RTC_CONFIG;              /*       0x48 - 0x4c       */
  volatile u_int32_t SOC_RTC_ALARM_STATUS;        /*       0x4c - 0x50       */
  volatile u_int32_t SOC_RESET_CAUSE;             /*       0x50 - 0x54       */
  volatile unsigned int pad__2[0x20];             /*       0x54 - 0xd4       */
  volatile u_int32_t SOC_LPO_CAL_TIME;            /*       0xd4 - 0xd8       */
  volatile u_int32_t SOC_LPO_INIT_DIVIDEND_INT;   /*       0xd8 - 0xdc       */
  volatile u_int32_t SOC_LPO_INIT_DIVIDEND_FRACTION;
                                                  /*       0xdc - 0xe0       */
  volatile u_int32_t SOC_LPO_CAL;                 /*       0xe0 - 0xe4       */
  volatile u_int32_t SOC_LPO_CAL_TEST_CONTROL;    /*       0xe4 - 0xe8       */
  volatile u_int32_t SOC_LPO_CAL_TEST_STATUS;     /*       0xe8 - 0xec       */
  volatile u_int32_t SOC_CHIP_ID;                 /*       0xec - 0xf0       */
  volatile unsigned int pad__3[0x7];              /*       0xf0 - 0x10c      */
  volatile u_int32_t SOC_POWER_REG;               /*      0x10c - 0x110      */
  volatile u_int32_t SOC_CORE_CLK_CTRL;           /*      0x110 - 0x114      */
  volatile u_int32_t SOC_GPIO_WAKEUP_CONTROL;     /*      0x114 - 0x118      */
  volatile u_int32_t SOC_OTP_BITS;                /*      0x118 - 0x11c      */
  volatile unsigned int pad__4[0x5a];             /*      0x11c - 0x284      */
  volatile u_int32_t LP_PERF_COUNTER;             /*      0x284 - 0x288      */
  volatile u_int32_t LP_PERF_LIGHT_SLEEP;         /*      0x288 - 0x28c      */
  volatile u_int32_t LP_PERF_DEEP_SLEEP;          /*      0x28c - 0x290      */
  volatile u_int32_t LP_PERF_ON;                  /*      0x290 - 0x294      */
  volatile unsigned int pad__5[0x5];              /*      0x294 - 0x2a8      */
  volatile u_int32_t CHIP_MODE;                   /*      0x2a8 - 0x2ac      */
  volatile u_int32_t OTP;                         /*      0x2ac - 0x2b0      */
  volatile u_int32_t OTP_STATUS;                  /*      0x2b0 - 0x2b4      */
  volatile u_int32_t PMU;                         /*      0x2b4 - 0x2b8      */
  volatile u_int32_t PMU_BYPASS;                  /*      0x2b8 - 0x2bc      */
  volatile unsigned int pad__6[0x8];              /*      0x2bc - 0x2dc      */
  volatile u_int32_t THERM_CTRL1;                 /*      0x2dc - 0x2e0      */
  volatile u_int32_t THERM_CTRL2;                 /*      0x2e0 - 0x2e4      */
  volatile u_int32_t THERM_CTRL3;                 /*      0x2e4 - 0x2e8      */
  volatile u_int32_t THERM_CTRL4;                 /*      0x2e8 - 0x2ec      */
  volatile u_int32_t THERM_CTRL5;                 /*      0x2ec - 0x2f0      */
  volatile u_int32_t CPU_PLL_CONFIG1;             /*      0x2f0 - 0x2f4      */
  volatile u_int32_t CPU_PLL_CONFIG2;             /*      0x2f4 - 0x2f8      */
  volatile u_int32_t RTC_CAL_DIV_DEFAULT;         /*      0x2f8 - 0x2fc      */
  volatile u_int32_t RTC_SPARE0;                  /*      0x2fc - 0x300      */
  volatile u_int32_t RTC_SPARE1;                  /*      0x300 - 0x304      */
  volatile u_int32_t RTC_DSLP_CONFIG0;            /*      0x304 - 0x308      */
  volatile u_int32_t RTC_DSLP_CONFIG1;            /*      0x308 - 0x30c      */
  volatile u_int32_t XO_FAST_CHARGE_LPO_CNT;      /*      0x30c - 0x310      */
  volatile u_int32_t PCIE_RLOOP;                  /*      0x310 - 0x314      */
  volatile u_int32_t PCIE_PHY_RESET;              /*      0x314 - 0x318      */
};

struct soc_pcie_reg {
  volatile u_int32_t PCIE_DEBUG_LOW;              /*        0x0 - 0x4        */
  volatile u_int32_t PCIE_DEBUG_HIGH;             /*        0x4 - 0x8        */
  volatile u_int32_t PCIE_PM;                     /*        0x8 - 0xc        */
  volatile u_int32_t PCIE_CTRL;                   /*        0xc - 0x10       */
  volatile u_int32_t PCIE_NFTS;                   /*       0x10 - 0x14       */
  volatile u_int32_t PCIE_MSI_STATUS;             /*       0x14 - 0x18       */
  volatile u_int32_t PCIE_MSI_MASK;               /*       0x18 - 0x1c       */
  volatile u_int32_t PCIE_MSI_ADDR;               /*       0x1c - 0x20       */
  volatile u_int32_t PCIE_CO_ERR_CTR0;            /*       0x20 - 0x24       */
  volatile u_int32_t PCIE_CO_ERR_CTR1;            /*       0x24 - 0x28       */
  volatile u_int32_t PCIE_CO_ERR_CTR_CTRL;        /*       0x28 - 0x2c       */
  volatile u_int32_t PCIE_MISC_STATUS;            /*       0x2c - 0x30       */
  volatile u_int32_t PCIE_BAR0_START;             /*       0x30 - 0x34       */
  volatile u_int32_t PCIE_BAR0_LIMIT;             /*       0x34 - 0x38       */
  volatile u_int32_t AUTOCOMPL;                   /*       0x38 - 0x3c       */
  volatile u_int32_t NUM_READS_WR_PENDING;        /*       0x3c - 0x40       */
  volatile u_int32_t LOW_POWER_INT_ENABLE;        /*       0x40 - 0x44       */
  volatile u_int32_t LOW_POWER_INT_MASK;          /*       0x44 - 0x48       */
  volatile u_int32_t LOW_POWER_INT_STATUS;        /*       0x48 - 0x4c       */
  volatile u_int32_t LTR_CFG;                     /*       0x4c - 0x50       */
  volatile u_int32_t LTR_MSG;                     /*       0x50 - 0x54       */
  volatile u_int32_t LTR_REQ;                     /*       0x54 - 0x58       */
  volatile u_int32_t OBFF_STATUS;                 /*       0x58 - 0x5c       */
  volatile u_int32_t L1SS_OBS;                    /*       0x5c - 0x60       */
  volatile u_int32_t L1SS_OVRD;                   /*       0x60 - 0x64       */
  volatile unsigned int pad__0[0x3];              /*       0x64 - 0x70       */
  volatile u_int32_t PCIE_SCRATCH_0;              /*       0x70 - 0x74       */
  volatile u_int32_t PCIE_SCRATCH_1;              /*       0x74 - 0x78       */
  volatile u_int32_t VMI_MSG_LOW;                 /*       0x78 - 0x7c       */
  volatile u_int32_t VMI_MSG_HIGH;                /*       0x7c - 0x80       */
  volatile u_int32_t VMI_MSG_MISC;                /*       0x80 - 0x84       */
  volatile u_int32_t PCIE_DEBUG_EI;               /*       0x84 - 0x88       */
  volatile u_int32_t PCIE_L1SS_CTRL_STATUS_0;     /*       0x88 - 0x8c       */
  volatile u_int32_t PCIE_L1SS_CTRL_STATUS_1;     /*       0x8c - 0x90       */
  volatile u_int32_t PCIE_UNCORRECTABLE_ERROR_INT_ENABLE;
                                                  /*       0x90 - 0x94       */
  volatile u_int32_t PCIE_UNCORRECTABLE_ERROR_INT_MASK;
                                                  /*       0x94 - 0x98       */
  volatile u_int32_t PCIE_UNCORRECTABLE_ERROR_INT_STATUS;
                                                  /*       0x98 - 0x9c       */
  volatile u_int32_t PCIE_RX_NFTS_PATCH;          /*       0x9c - 0xa0       */
  volatile u_int32_t PCIE_RX_NFTS_TMO;            /*       0xa0 - 0xa4       */
  volatile u_int32_t LTR_LATENCY;                 /*       0xa4 - 0xa8       */
  volatile u_int32_t STATISTIC_CTRL;              /*       0xa8 - 0xac       */
  volatile u_int32_t STATISTIC_PERIOD_CNT;        /*       0xac - 0xb0       */
  volatile u_int32_t L1_TIME_CNT;                 /*       0xb0 - 0xb4       */
  volatile u_int32_t L1_1_TIME_CNT;               /*       0xb4 - 0xb8       */
  volatile u_int32_t L1_2_TIME_CNT;               /*       0xb8 - 0xbc       */
  volatile u_int32_t MSI_MAGIC;                   /*       0xbc - 0xc0       */
  volatile u_int32_t MSI_MAGIC_ADR;               /*       0xc0 - 0xc4       */
  volatile u_int32_t PCIE_AXI_BRIDGE_CTRL_CLIENT; /*       0xc4 - 0xc8       */
  volatile u_int32_t SOC_RDY_STATUS;              /*       0xc8 - 0xcc       */
  volatile u_int32_t PCIE_MISC_CTRL;              /*       0xcc - 0xd0       */
  volatile u_int32_t PCIE_IDLE_DLY;               /*       0xd0 - 0xd4       */
  volatile u_int32_t L1_ENTER_CNT;                /*       0xd4 - 0xd8       */
  volatile u_int32_t L1_1_ENTER_CNT;              /*       0xd8 - 0xdc       */
  volatile u_int32_t L1_2_ENTER_CNT;              /*       0xdc - 0xe0       */
  volatile u_int32_t PCIE_WRAP_INTR_MASK;         /*       0xe0 - 0xe4       */
  volatile u_int32_t PCIE_WRAP_INTR_HOST_MASK;    /*       0xe4 - 0xe8       */
  volatile u_int32_t PCIE_WRAP_INTR_STATUS;       /*       0xe8 - 0xec       */
  volatile u_int32_t EV144272;                    /*       0xec - 0xf0       */
  volatile u_int32_t PCIE_CTRL_EXT;               /*       0xf0 - 0xf4       */
};

struct soc_core_reg {
  volatile u_int32_t CORE_CTRL;                   /*        0x0 - 0x4        */
  volatile u_int32_t CORE_PM;                     /*        0x4 - 0x8        */
  volatile u_int32_t PCIE_INTR_ENABLE;            /*        0x8 - 0xc        */
  volatile u_int32_t PCIE_INTR_CAUSE;             /*        0xc - 0x10       */
  volatile u_int32_t PCIE_INTR_CLR;               /*       0x10 - 0x14       */
  volatile u_int32_t SCRATCH_0;                   /*       0x14 - 0x18       */
  volatile u_int32_t SCRATCH_1;                   /*       0x18 - 0x1c       */
  volatile u_int32_t SCRATCH_2;                   /*       0x1c - 0x20       */
  volatile u_int32_t SCRATCH_3;                   /*       0x20 - 0x24       */
  volatile u_int32_t WLAN_APB_ADDR_ERROR_CONTROL; /*       0x24 - 0x28       */
  volatile u_int32_t WLAN_APB_ADDR_ERROR_STATUS;  /*       0x28 - 0x2c       */
  volatile u_int32_t WLAN_APB_ADDR_ERROR_STATUS_WRITE;
                                                  /*       0x2c - 0x30       */
  volatile u_int32_t PMU_CTRL;                    /*       0x30 - 0x34       */
  volatile u_int32_t PCIE_TO_HOST_INTMASK;        /*       0x34 - 0x38       */
  volatile u_int32_t PCIE_CTRL_STATUS;            /*       0x38 - 0x3c       */
  volatile unsigned int pad__0;                   /*       0x3c - 0x40       */
  volatile u_int32_t PCIE_SW_PERST_N;             /*       0x40 - 0x44       */
};

struct athrUartCsr {
  volatile u_int32_t UartData;                    /*        0x0 - 0x4        */
  volatile u_int32_t UartCs;                      /*        0x4 - 0x8        */
  volatile u_int32_t UartClock;                   /*        0x8 - 0xc        */
  volatile u_int32_t UartInt;                     /*        0xc - 0x10       */
  volatile u_int32_t UartIntEn;                   /*       0x10 - 0x14       */
};

struct si_reg {
  volatile u_int32_t SI_CONFIG;                   /*        0x0 - 0x4        */
  volatile u_int32_t SI_CS;                       /*        0x4 - 0x8        */
  volatile u_int32_t SI_TX_DATA0;                 /*        0x8 - 0xc        */
  volatile u_int32_t SI_TX_DATA1;                 /*        0xc - 0x10       */
  volatile u_int32_t SI_RX_DATA0;                 /*       0x10 - 0x14       */
  volatile u_int32_t SI_RX_DATA1;                 /*       0x14 - 0x18       */
};

struct gpio_athr_wlan_reg {
  volatile u_int32_t WLAN_GPIO_OUT_LOW;           /*        0x0 - 0x4        */
  volatile u_int32_t WLAN_GPIO1_OUT_LOW;          /*        0x4 - 0x8        */
  volatile u_int32_t WLAN_GPIO_OUT_W1TS_LOW;      /*        0x8 - 0xc        */
  volatile u_int32_t WLAN_GPIO1_OUT_W1TS_LOW;     /*        0xc - 0x10       */
  volatile u_int32_t WLAN_GPIO_OUT_W1TC_LOW;      /*       0x10 - 0x14       */
  volatile u_int32_t WLAN_GPIO1_OUT_W1TC_LOW;     /*       0x14 - 0x18       */
  volatile u_int32_t WLAN_GPIO_ENABLE_LOW;        /*       0x18 - 0x1c       */
  volatile u_int32_t WLAN_GPIO1_ENABLE_LOW;       /*       0x1c - 0x20       */
  volatile u_int32_t WLAN_GPIO_ENABLE_W1TS_LOW;   /*       0x20 - 0x24       */
  volatile u_int32_t WLAN_GPIO1_ENABLE_W1TS_LOW;  /*       0x24 - 0x28       */
  volatile u_int32_t WLAN_GPIO_ENABLE_W1TC_LOW;   /*       0x28 - 0x2c       */
  volatile u_int32_t WLAN_GPIO1_ENABLE_W1TC_LOW;  /*       0x2c - 0x30       */
  volatile u_int32_t WLAN_GPIO_IN_LOW;            /*       0x30 - 0x34       */
  volatile u_int32_t WLAN_GPIO1_IN_LOW;           /*       0x34 - 0x38       */
  volatile u_int32_t WLAN_GPIO_STATUS_LOW;        /*       0x38 - 0x3c       */
  volatile u_int32_t WLAN_GPIO1_STATUS_LOW;       /*       0x3c - 0x40       */
  volatile u_int32_t WLAN_GPIO_STATUS_W1TS_LOW;   /*       0x40 - 0x44       */
  volatile u_int32_t WLAN_GPIO1_STATUS_W1TS_LOW;  /*       0x44 - 0x48       */
  volatile u_int32_t WLAN_GPIO_STATUS_W1TC_LOW;   /*       0x48 - 0x4c       */
  volatile u_int32_t WLAN_GPIO1_STATUS_W1TC_LOW;  /*       0x4c - 0x50       */
  volatile u_int32_t WLAN_GPIO_PIN0;              /*       0x50 - 0x54       */
  volatile u_int32_t WLAN_GPIO_PIN1;              /*       0x54 - 0x58       */
  volatile u_int32_t WLAN_GPIO_PIN2;              /*       0x58 - 0x5c       */
  volatile u_int32_t WLAN_GPIO_PIN3;              /*       0x5c - 0x60       */
  volatile u_int32_t WLAN_GPIO_PIN4;              /*       0x60 - 0x64       */
  volatile u_int32_t WLAN_GPIO_PIN5;              /*       0x64 - 0x68       */
  volatile u_int32_t WLAN_GPIO_PIN6;              /*       0x68 - 0x6c       */
  volatile u_int32_t WLAN_GPIO_PIN7;              /*       0x6c - 0x70       */
  volatile u_int32_t WLAN_GPIO_PIN8;              /*       0x70 - 0x74       */
  volatile u_int32_t WLAN_GPIO_PIN9;              /*       0x74 - 0x78       */
  volatile u_int32_t WLAN_GPIO_PIN10;             /*       0x78 - 0x7c       */
  volatile u_int32_t WLAN_GPIO_PIN11;             /*       0x7c - 0x80       */
  volatile u_int32_t WLAN_GPIO_PIN12;             /*       0x80 - 0x84       */
  volatile u_int32_t WLAN_GPIO_PIN13;             /*       0x84 - 0x88       */
  volatile u_int32_t WLAN_GPIO_PIN14;             /*       0x88 - 0x8c       */
  volatile u_int32_t WLAN_GPIO_PIN15;             /*       0x8c - 0x90       */
  volatile u_int32_t WLAN_GPIO_PIN16;             /*       0x90 - 0x94       */
  volatile u_int32_t WLAN_GPIO_PIN17;             /*       0x94 - 0x98       */
  volatile u_int32_t WLAN_GPIO_PIN18;             /*       0x98 - 0x9c       */
  volatile u_int32_t WLAN_GPIO_PIN19;             /*       0x9c - 0xa0       */
  volatile u_int32_t WLAN_GPIO_PIN20;             /*       0xa0 - 0xa4       */
  volatile u_int32_t WLAN_GPIO_PIN21;             /*       0xa4 - 0xa8       */
  volatile u_int32_t WLAN_GPIO_PIN22;             /*       0xa8 - 0xac       */
  volatile u_int32_t WLAN_GPIO_PIN23;             /*       0xac - 0xb0       */
  volatile u_int32_t WLAN_GPIO_PIN24;             /*       0xb0 - 0xb4       */
  volatile u_int32_t WLAN_GPIO_PIN25;             /*       0xb4 - 0xb8       */
  volatile u_int32_t WLAN_GPIO_PIN26;             /*       0xb8 - 0xbc       */
  volatile u_int32_t WLAN_GPIO_PIN27;             /*       0xbc - 0xc0       */
  volatile u_int32_t WLAN_GPIO_PIN28;             /*       0xc0 - 0xc4       */
  volatile u_int32_t WLAN_GPIO_PIN29;             /*       0xc4 - 0xc8       */
  volatile u_int32_t WLAN_GPIO_PIN30;             /*       0xc8 - 0xcc       */
  volatile u_int32_t WLAN_GPIO_PIN31;             /*       0xcc - 0xd0       */
  volatile u_int32_t WLAN_GPIO_PIN32;             /*       0xd0 - 0xd4       */
  volatile u_int32_t WLAN_GPIO_PIN33;             /*       0xd4 - 0xd8       */
  volatile u_int32_t WLAN_GPIO_PIN34;             /*       0xd8 - 0xdc       */
  volatile u_int32_t WLAN_GPIO_PIN35;             /*       0xdc - 0xe0       */
  volatile u_int32_t WL_SOC_APB;                  /*       0xe0 - 0xe4       */
  volatile u_int32_t WLAN_SIGMA_DELTA;            /*       0xe4 - 0xe8       */
  volatile u_int32_t WL_BOOTSTRAP;                /*       0xe8 - 0xec       */
  volatile u_int32_t WL_BOOTSTRAP1;               /*       0xec - 0xf0       */
  volatile u_int32_t SOC_DEBUG;                   /*       0xf0 - 0xf4       */
  volatile u_int32_t SPDT_CONTROL;                /*       0xf4 - 0xf8       */
  volatile u_int32_t CLOCK_OBS_MUX;               /*       0xf8 - 0xfc       */
  volatile u_int32_t PCIE;                        /*       0xfc - 0x100      */
  volatile u_int32_t WLAN_GPIO_PCIE;              /*      0x100 - 0x104      */
  volatile u_int32_t GPIO_SPARE0;                 /*      0x104 - 0x108      */
  volatile u_int32_t GPIO_SPARE1;                 /*      0x108 - 0x10c      */
  volatile u_int32_t DEBUG_BUS;                   /*      0x10c - 0x110      */
};

struct efuse_reg {
  volatile u_int32_t EFUSE_WR_ENABLE_REG;         /*        0x0 - 0x4        */
  volatile u_int32_t EFUSE_INT_ENABLE_REG;        /*        0x4 - 0x8        */
  volatile u_int32_t EFUSE_INT_STATUS_REG;        /*        0x8 - 0xc        */
  volatile u_int32_t BITMASK_WR_REG;              /*        0xc - 0x10       */
  volatile u_int32_t VDDQ_SETTLE_TIME_REG;        /*       0x10 - 0x14       */
  volatile u_int32_t VDDQ_HOLD_TIME_REG;          /*       0x14 - 0x18       */
  volatile u_int32_t RD_STROBE_PW_REG;            /*       0x18 - 0x1c       */
  volatile u_int32_t PG_STROBE_PW_REG;            /*       0x1c - 0x20       */
  volatile u_int32_t PGENB_SETUP_HOLD_TIME_REG;   /*       0x20 - 0x24       */
  volatile u_int32_t STROBE_PULSE_INTERVAL_REG;   /*       0x24 - 0x28       */
  volatile u_int32_t CSB_ADDR_LOAD_SETUP_HOLD_REG;
                                                  /*       0x28 - 0x2c       */
  volatile u_int32_t SUR_PD_CSB_REG;              /*       0x2c - 0x30       */
  volatile u_int32_t SUP_PS_CSB_REG;              /*       0x30 - 0x34       */
  volatile u_int32_t EFUSE_BUZY_STATUS_REG;       /*       0x34 - 0x38       */
  volatile unsigned int pad__0[0x1f2];            /*       0x38 - 0x800      */
  volatile u_int32_t EFUSE_INTF0[512];            /*      0x800 - 0x1000     */
  volatile u_int32_t EFUSE_INTF1[512];            /*     0x1000 - 0x1800     */
};

struct dbi_reg {
  volatile u_int32_t DBI_WINDOW_reg[4096];        /*        0x0 - 0x4000     */
};

struct pcie_phy_reg_csr {
  volatile u_int32_t pcie_phy_reg_1;              /*        0x0 - 0x4        */
  volatile u_int32_t pcie_phy_reg_2;              /*        0x4 - 0x8        */
  volatile u_int32_t pcie_phy_reg_3;              /*        0x8 - 0xc        */
  volatile u_int32_t pcie_phy_reg_4;              /*        0xc - 0x10       */
  volatile u_int32_t pcie_phy_reg_5;              /*       0x10 - 0x14       */
  volatile u_int32_t pcie_phy_reg_6;              /*       0x14 - 0x18       */
};

struct chip_top_reg_fpga_map {
  struct pcie_local_reg pcie_local_reg;           /*        0x0 - 0x20       */
  volatile unsigned int pad__0[0x3ff8];           /*       0x20 - 0x10000    */
  struct bb_reg_map bb_reg_map;                   /*    0x10000 - 0x18114    */
  volatile unsigned int pad__1[0x3];              /*    0x18114 - 0x18120    */
  struct fpga_reg fpga_reg;                       /*    0x18120 - 0x1812c    */
  volatile unsigned int pad__2[0x1bb5];           /*    0x1812c - 0x1f000    */
  struct merlin_reg_sel merlin_reg_sel;           /*    0x1f000 - 0x1f004    */
  volatile unsigned int pad__3[0x37f];            /*    0x1f004 - 0x1fe00    */
  struct emu_phy_reg emu_phy_reg;                 /*    0x1fe00 - 0x1fefc    */
  volatile unsigned int pad__4;                   /*    0x1fefc - 0x1ff00    */
  struct merlin2_0_radio_reg merlin2_0_radio_reg; /*    0x1ff00 - 0x1ff9c    */
  volatile unsigned int pad__5[0x19];             /*    0x1ff9c - 0x20000    */
  struct wmac_top_reg_map wmac_top_reg_map;       /*    0x20000 - 0x2fc48    */
  volatile unsigned int pad__6[0x40ee];           /*    0x2fc48 - 0x40000    */
  struct mac_wificmn_reg mac_wificmn_reg;         /*    0x40000 - 0x40084    */
  volatile unsigned int pad__7[0x3df];            /*    0x40084 - 0x41000    */
  struct wifi_timers_reg wifi_timers_reg;         /*    0x41000 - 0x41100    */
  volatile unsigned int pad__8[0x7c0];            /*    0x41100 - 0x43000    */
  struct wifi_pta_coex_reg wifi_pta_coex_reg;     /*    0x43000 - 0x43140    */
  volatile unsigned int pad__9[0xb0];             /*    0x43140 - 0x43400    */
  struct Wlan_CxM_reg_csr Wlan_CxM_reg_csr;       /*    0x43400 - 0x434a4    */
  volatile unsigned int pad__10[0xd7];            /*    0x434a4 - 0x43800    */
  struct wifi_lte_coex_reg wifi_lte_coex_reg;     /*    0x43800 - 0x43804    */
  volatile unsigned int pad__11[0x5ff];           /*    0x43804 - 0x45000    */
  struct wifi_rtc_reg wifi_rtc_reg;               /*    0x45000 - 0x45a14    */
  volatile unsigned int pad__12[0x117b];          /*    0x45a14 - 0x4a000    */
  struct ce_reg_csr ce_reg_csr_0;                 /*    0x4a000 - 0x4a05c    */
  volatile unsigned int pad__13[0xe9];            /*    0x4a05c - 0x4a400    */
  struct ce_reg_csr ce_reg_csr_1;                 /*    0x4a400 - 0x4a45c    */
  volatile unsigned int pad__14[0xe9];            /*    0x4a45c - 0x4a800    */
  struct ce_reg_csr ce_reg_csr_2;                 /*    0x4a800 - 0x4a85c    */
  volatile unsigned int pad__15[0xe9];            /*    0x4a85c - 0x4ac00    */
  struct ce_reg_csr ce_reg_csr_3;                 /*    0x4ac00 - 0x4ac5c    */
  volatile unsigned int pad__16[0xe9];            /*    0x4ac5c - 0x4b000    */
  struct ce_reg_csr ce_reg_csr_4;                 /*    0x4b000 - 0x4b05c    */
  volatile unsigned int pad__17[0xe9];            /*    0x4b05c - 0x4b400    */
  struct ce_reg_csr ce_reg_csr_5;                 /*    0x4b400 - 0x4b45c    */
  volatile unsigned int pad__18[0xe9];            /*    0x4b45c - 0x4b800    */
  struct ce_reg_csr ce_reg_csr_6;                 /*    0x4b800 - 0x4b85c    */
  volatile unsigned int pad__19[0xe9];            /*    0x4b85c - 0x4bc00    */
  struct ce_reg_csr ce_reg_csr_7;                 /*    0x4bc00 - 0x4bc5c    */
  volatile unsigned int pad__20[0xe9];            /*    0x4bc5c - 0x4c000    */
  struct ce_reg_csr ce_reg_csr_8;                 /*    0x4c000 - 0x4c05c    */
  volatile unsigned int pad__21[0xe9];            /*    0x4c05c - 0x4c400    */
  struct ce_reg_csr ce_reg_csr_9;                 /*    0x4c400 - 0x4c45c    */
  volatile unsigned int pad__22[0xe9];            /*    0x4c45c - 0x4c800    */
  struct ce_reg_csr ce_reg_csr_10;                /*    0x4c800 - 0x4c85c    */
  volatile unsigned int pad__23[0xe9];            /*    0x4c85c - 0x4cc00    */
  struct ce_reg_csr ce_reg_csr_11;                /*    0x4cc00 - 0x4cc5c    */
  volatile unsigned int pad__24[0xe9];            /*    0x4cc5c - 0x4d000    */
  struct ce_wrapper_reg_csr ce_wrapper_reg_csr;   /*    0x4d000 - 0x4d01c    */
  volatile unsigned int pad__25[0xbf9];           /*    0x4d01c - 0x50000    */
  struct rffe_m_csr rffe_m_csr;                   /*    0x50000 - 0x50018    */
  volatile unsigned int pad__26[0xbffa];          /*    0x50018 - 0x80000    */
  struct rtc_soc_reg rtc_soc_reg;                 /*    0x80000 - 0x80318    */
  volatile unsigned int pad__27[0x33a];           /*    0x80318 - 0x81000    */
  struct soc_pcie_reg soc_pcie_reg;               /*    0x81000 - 0x810f4    */
  volatile unsigned int pad__28[0x3c3];           /*    0x810f4 - 0x82000    */
  struct soc_core_reg soc_core_reg;               /*    0x82000 - 0x82044    */
  volatile unsigned int pad__29[0x3ef];           /*    0x82044 - 0x83000    */
  struct athrUartCsr athrUartCsr;                 /*    0x83000 - 0x83014    */
  volatile unsigned int pad__30[0x3fb];           /*    0x83014 - 0x84000    */
  struct si_reg si_reg;                           /*    0x84000 - 0x84018    */
  volatile unsigned int pad__31[0x3fa];           /*    0x84018 - 0x85000    */
  struct gpio_athr_wlan_reg gpio_athr_wlan_reg;   /*    0x85000 - 0x85110    */
  volatile unsigned int pad__32[0x3bc];           /*    0x85110 - 0x86000    */
  struct efuse_reg efuse_reg;                     /*    0x86000 - 0x87800    */
  volatile unsigned int pad__33[0x600];           /*    0x87800 - 0x89000    */
  struct dbi_reg dbi_reg;                         /*    0x89000 - 0x8d000    */
  struct pcie_phy_reg_csr pcie_phy_reg_csr;       /*    0x8d000 - 0x8d018    */
};

#endif /* __REG_CHIP_TOP_REG_FPGA_MAP_H__ */
