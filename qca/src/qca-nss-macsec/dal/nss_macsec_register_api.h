/*
 * Copyright (c) 2014, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _NSS_MACSEC_REGISTER_API_H_
#define _NSS_MACSEC_REGISTER_API_H_

#define EGRESS_BASE_ADDR    0x0
#define EMAC1_BASE_ADDR    0x8000
#define EMAC2_BASE_ADDR    0x108000
#define INGRESS_BASE_ADDR    0x100000

#define IG_CTL_FILT_TABLE_TYPE  0
#define IG_CTL_FILT_ENTRY_LEN   3
#define IG_CTL_FILT_INDEX_MIN   0
#define IG_CTL_FILT_INDEX_MAX   23

#define IG_PRC_LUT_TABLE_TYPE   1
#define IG_PRC_LUT_ENTRY_LEN    10
#define IG_PRC_LUT_INDEX_MIN    0
#define IG_PRC_LUT_INDEX_MAX    47

#define IG_SAK_TABLE_TYPE       2
#define IG_SAK_ENTRY_LEN        4
#define IG_SAK_INDEX_MIN        32
#define IG_SAK_INDEX_MAX        63

#define IG_SC_TABLE_TYPE        3
#define IG_SC_ENTRY_LEN         4
#define IG_SC_INDEX_MIN         0
#define IG_SC_INDEX_MAX         31

#define IG_SA_TABLE_TYPE        3
#define IG_SA_ENTRY_LEN         4
#define IG_SA_INDEX_MIN         32
#define IG_SA_INDEX_MAX         63

#define IG_POC_LUT_TABLE_TYPE   4
#define IG_POC_LUT_ENTRY_LEN    4
#define IG_POC_LUT_INDEX_MIN    0
#define IG_POC_LUT_INDEX_MAX    47

#define IG_SMIB_TABLE_TYPE      6
#define IG_SMIB_ENTRY_LEN       12
#define IG_SMIB_INDEX_MIN       0
#define IG_SMIB_INDEX_MAX       31
#define IG_SMIB_COMMON_INDEX_MIN  384
#define IG_SMIB_COMMON_INDEX_MAX  399

#define EG_CTL_FILT_TABLE_TYPE  0
#define EG_CTL_FILT_ENTRY_LEN   3
#define EG_CTL_FILT_INDEX_MIN   0
#define EG_CTL_FILT_INDEX_MAX   23

#define EG_CLASS_LUT_TABLE_TYPE       1
#define EG_CLASS_LUT_ENTRY_LEN		14
#define EG_CLASS_LUT_INDEX_MIN        0
#define EG_CLASS_LUT_INDEX_MAX        47

#define EG_SC_TABLE_TYPE        2
#define EG_SC_ENTRY_LEN         4
#define EG_SC_INDEX_MIN         0
#define EG_SC_INDEX_MAX         31

#define EG_SA_TABLE_TYPE        2
#define EG_SA_ENTRY_LEN         4
#define EG_SA_INDEX_MIN         32
#define EG_SA_INDEX_MAX         63

#define EG_SAK_TABLE_TYPE       2
#define EG_SAK_ENTRY_LEN        4
#define EG_SAK_INDEX_MIN        64
#define EG_SAK_INDEX_MAX        95

#define EG_SMIB_TABLE_TYPE      3
#define EG_SMIB_ENTRY_LEN       8
#define EG_SMIB_INDEX_MIN       0
#define EG_SMIB_INDEX_MAX       31
#define EG_SMIB_COMMON_INDEX_MIN  256
#define EG_SMIB_COMMON_INDEX_MAX  261

#define TABLE_WRITE_OP 0x2
#define TABLE_READ_OP  0x1

#define DAL_OK   0
#define DAL_NOT_SUPPORT  1

#define  DAL_MAC_ADDR_LEN   6

#define DAL_ERR     0xffffffff

#define MEM_ACCESS_WAIT_TICK 65536
#define REG_TYPE_RO      0	/*read only */
#define REG_TYPE_WO      1	/*write only */
#define REG_TYPE_RW      2	/*read/write */
#define REG_TYPE_RC      3	/*read to clear */
#define REG_TYPE_W1C     4	/*write 1 to clear */
#define REG_TYPE_RW1C    5	/*read/write 1 to clear */
#define REG_TYPE_UNKONWN 6	/*unknown */

#define SW_BIT_MASK_U32(nr) (~(0xFFFFFFFF << (nr)))
#define SW_FIELD_MASK_U32(offset, len) \
	((SW_BIT_MASK_U32(len) << (offset)))
#define SW_FIELD_MASK_NOT_U32(offset,len) \
    (~(SW_BIT_MASK_U32(len) << (offset)))
#define SW_REG_SET_BY_FIELD_U32(reg_value, field_value, bit_offset, field_len)\
    do { \
        (reg_value) = \
            (((reg_value) & SW_FIELD_MASK_NOT_U32((bit_offset),(field_len))) \
              | (((field_value) & SW_BIT_MASK_U32(field_len)) << (bit_offset)));\
    } while (0)

#define MACADDR_LEN            6

struct mac_t {
	unsigned char addr[MACADDR_LEN];
};

int dal_reg_read(unsigned int dev_id, unsigned int reg_addr,
		 unsigned int *pvalue);
int dal_reg_write(unsigned int dev_id, unsigned int reg_addr,
		  unsigned int value);
int dal_reg_tbl_read(unsigned int dev_id, unsigned int reg_addr,
		     unsigned int *pvalue, unsigned int width);
int dal_reg_tbl_write(unsigned int dev_id, unsigned int reg_addr,
		      unsigned int *pvalue, unsigned int width);

int dal_var_field_get(unsigned int field_offset,
		      unsigned int field_len,
		      unsigned int *pFieldValue, unsigned int value);
int dal_var_field_set(unsigned int field_offset,
		      unsigned int field_len,
		      unsigned int fieldValue, unsigned int *pValue);

struct igsy_l2sec_version {
	unsigned int igsy_l2sec_id:16;
	unsigned int igsy_l2sec_version:8;
	unsigned int igsy_l2sec_revision:8;
};

union igsy_l2sec_version_u {
	unsigned int val;
	struct igsy_l2sec_version bf;
};

struct insy_prescale {
	unsigned int insy_prescale:32;
};

union insy_prescale_u {
	unsigned int val;
	struct insy_prescale bf;
};

struct csr_igsy_vlan_tpid0 {
	unsigned int csr_igsy_vlan_tpid0:16;
	unsigned int _reserved0:16;
};

union csr_igsy_vlan_tpid0_u {
	unsigned int val;
	struct csr_igsy_vlan_tpid0 bf;
};

struct csr_igsy_vlan_tpid1 {
	unsigned int csr_igsy_vlan_tpid1:16;
	unsigned int _reserved0:16;
};

union csr_igsy_vlan_tpid1_u {
	unsigned int val;
	struct csr_igsy_vlan_tpid1 bf;
};

struct csr_igsy_vlan_cp_tag {
	unsigned int csr_igsy_vlan_cp_tag_map_table:24;
	unsigned int csr_igsy_vlan_cp_tag_def_up:3;
	unsigned int csr_igsy_vlan_cp_tag_stag_up_en:1;
	unsigned int csr_igsy_vlan_cp_tag_qtag_up_en:1;
	unsigned int csr_igsy_vlan_cp_tag_q_in_q:1;
	unsigned int csr_igsy_vlan_cp_tag_parse_stag:1;
	unsigned int csr_igsy_vlan_cp_tag_parse_qtag:1;
};

union csr_igsy_vlan_cp_tag_u {
	unsigned int val;
	struct csr_igsy_vlan_cp_tag bf;
};

struct csr_igsy_mtu {
	unsigned int csr_igsy_mtu:16;
	unsigned int unctrl_csr_igsy_mtu:16;
};

union csr_igsy_mtu_u {
	unsigned int val;
	struct csr_igsy_mtu bf;
};

struct csr_igsy_ctrl {
	unsigned int csr_insy_swrst:1;
	unsigned int csr_insy_operpointtopoint:1;
	unsigned int csr_insy_create_sci:1;
	unsigned int csr_insy_mask_sl_err:1;
	unsigned int csr_insy_drop_kay_pkt:1;
	unsigned int csr_insy_drop_igprc_miss:1;
	unsigned int csr_insy_check_icv:1;
	unsigned int csr_insy_clear_glbl_time:1;
	unsigned int csr_insy_clr_cnt:1;
	unsigned int csr_insy_high_priority:1;
	unsigned int csr_insy_remove_sectag:1;
	unsigned int csr_insy_global_validate_frames:2;
	unsigned int csr_insy_icv_msblsb_8bytes:1;
	unsigned int _reserved0:18;
};

union csr_igsy_ctrl_u {
	unsigned int val;
	struct csr_igsy_ctrl bf;
};

struct csr_insy_sa_thr {
	unsigned int csr_insy_sa_thr:32;
};

union csr_insy_sa_thr_u {
	unsigned int val;
	struct csr_insy_sa_thr bf;
};

struct insy_fmt_csr_debug {
	unsigned int insy_pfmt_csr_debug:8;
	unsigned int gen_pktfmt_padins_csr_debug:6;
	unsigned int _reserved0:18;
};

union insy_fmt_csr_debug_u {
	unsigned int val;
	struct insy_fmt_csr_debug bf;
};

struct insy_rpy_csr_debug {
	unsigned int insy_rpy_csr_debug:9;
	unsigned int gen_pktfmt_rem_csr_debug:6;
	unsigned int insy_pktfmt_remlast_csr_debug:4;
	unsigned int _reserved0:13;
};

union insy_rpy_csr_debug_u {
	unsigned int val;
	struct insy_rpy_csr_debug bf;
};

struct insy_aes_gcm_counter_incr_csr_debug {
	unsigned int insy_aes_gcm_counter_incr_csr_debug:32;
};

union insy_aes_gcm_counter_incr_csr_debug_u {
	unsigned int val;
	struct insy_aes_gcm_counter_incr_csr_debug bf;
};

struct insy_gcm_mult_data_cnt_csr_debug {
	unsigned int insy_gcm_mult_data_cnt_csr_debug:2;
	unsigned int _reserved0:30;
};

union insy_gcm_mult_data_cnt_csr_debug_u {
	unsigned int val;
	struct insy_gcm_mult_data_cnt_csr_debug bf;
};

struct insy_gcm_mult_lena_lsb_csr_debug {
	unsigned int iinsy_gcm_mult_lena_lsb_csr_debug:32;
};

union insy_gcm_mult_lena_lsb_csr_debug_u {
	unsigned int val;
	struct insy_gcm_mult_lena_lsb_csr_debug bf;
};

struct insy_gcm_mult_lena_msb_csr_debug {
	unsigned int iinsy_gcm_mult_lena_msb_csr_debug:32;
};

union insy_gcm_mult_lena_msb_csr_debug_u {
	unsigned int val;
	struct insy_gcm_mult_lena_msb_csr_debug bf;
};

struct insy_gcm_mult_lenc_lsb_csr_debug {
	unsigned int iinsy_gcm_mult_lenc_lsb_csr_debug:32;
};

union insy_gcm_mult_lenc_lsb_csr_debug_u {
	unsigned int val;
	struct insy_gcm_mult_lenc_lsb_csr_debug bf;
};

struct insy_gcm_mult_lenc_msb_csr_debug {
	unsigned int iinsy_gcm_mult_lenc_msb_csr_debug:32;
};

union insy_gcm_mult_lenc_msb_csr_debug_u {
	unsigned int val;
	struct insy_gcm_mult_lenc_msb_csr_debug bf;
};

struct igsy_csr_busy_signal {
	unsigned int insy_dp_busy:1;
	unsigned int insy_pfmt_busy:1;
	unsigned int insy_aes_ctr_busy:1;
	unsigned int insy_rpy_busy:1;
	unsigned int insy_gbuf_busy:1;
	unsigned int insy_lkup_busy:1;
	unsigned int insy_igpoc_busy:1;
	unsigned int _reserved0:25;
};

union igsy_csr_busy_signal_u {
	unsigned int val;
	struct igsy_csr_busy_signal bf;
};

struct insy_sctrl_drop_en {
	unsigned int insy_sctrl_drop_en:32;
};

union insy_sctrl_drop_en_u {
	unsigned int val;
	struct insy_sctrl_drop_en bf;
};

struct insy_ectrl_en {
	unsigned int insy_ectrl_en:32;
};

union insy_ectrl_en_u {
	unsigned int val;
	struct insy_ectrl_en bf;
};

struct insy_emac_regs {
	unsigned int en_gen_pause:1;
	unsigned int power_down_emac2:1;
	unsigned int resetemac2:1;
	unsigned int _reserved0:29;
};

union insy_emac_regs_u {
	unsigned int val;
	struct insy_emac_regs bf;
};

struct insy_sci_default_entry_lsb {
	unsigned int insy_sci_default_entry_lsb:32;
};

union insy_sci_default_entry_lsb_u {
	unsigned int val;
	struct insy_sci_default_entry_lsb bf;
};

struct insy_sci_default_entry_msb {
	unsigned int insy_sci_default_entry_msb:32;
};

union insy_sci_default_entry_msb_u {
	unsigned int val;
	struct insy_sci_default_entry_msb bf;
};

struct igsy_int {
	unsigned int igsy_int:1;
	unsigned int sa_exp_pulse_int:1;
	unsigned int sa_thr_pulse_in:1;
	unsigned int icv_err_pulse_int:1;
	unsigned int rpy_err_pulse_int:1;
	unsigned int insy_mib_sat_int:1;
	unsigned int ecc_err_int:1;
	unsigned int ec_bit_err_int:1;
	unsigned int igpoc_miss_int:1;
	unsigned int _reserved0:23;
};

union igsy_int_u {
	unsigned int val;
	struct igsy_int bf;
};

struct igsy_int_en {
	unsigned int igsy_int_en:1;
	unsigned int sa_exp_pulse_int_en:1;
	unsigned int sa_thr_pulse_int_en:1;
	unsigned int icv_err_pulse_int_en:1;
	unsigned int rpy_err_pulse_int_en:1;
	unsigned int insy_mib_sat_int_en:1;
	unsigned int ecc_err_int_en:1;
	unsigned int ec_bit_err_int_en:1;
	unsigned int gpoc_miss_int_en:1;
	unsigned int _reserved0:23;
};

union igsy_int_en_u {
	unsigned int val;
	struct igsy_int_en bf;
};

struct icv_err_reg {
	unsigned int icv_err_reg:32;
};

union icv_err_reg_u {
	unsigned int val;
	struct icv_err_reg bf;
};

struct rpy_err_reg {
	unsigned int rpy_err_reg:32;
};

union rpy_err_reg_u {
	unsigned int val;
	struct rpy_err_reg bf;
};

struct igsy_sa_exp {
	unsigned int igsy_sa_exp:32;
};

union igsy_sa_exp_u {
	unsigned int val;
	struct igsy_sa_exp bf;
};

struct igsy_sa_thr {
	unsigned int igsy_sa_thr:32;
};

union igsy_sa_thr_u {
	unsigned int val;
	struct igsy_sa_thr bf;
};

struct igecc_err_reg {
	unsigned int ecc_err_reg:32;
};

union igecc_err_reg_u {
	unsigned int val;
	struct igecc_err_reg bf;
};

struct igprc_ecc_err1_addr {
	unsigned int ecc_err_addr:32;
};

union igprc_ecc_err1_addr_u {
	unsigned int val;
	struct igprc_ecc_err1_addr bf;
};

struct igprc_ecc_err2_addr {
	unsigned int ecc_err_addr:32;
};

union igprc_ecc_err2_addr_u {
	unsigned int val;
	struct igprc_ecc_err2_addr bf;
};

struct iglkup_ctlf_ecc_err_addr {
	unsigned int ecc_err_addr:32;
};

union iglkup_ctlf_ecc_err_addr_u {
	unsigned int val;
	struct iglkup_ctlf_ecc_err_addr bf;
};

struct pfmt_ecc_err_addr {
	unsigned int ecc_err_addr:32;
};

union pfmt_ecc_err_addr_u {
	unsigned int val;
	struct pfmt_ecc_err_addr bf;
};

struct irpy_sc_sa_ecc_err_addr {
	unsigned int ecc_err_addr:32;
};

union irpy_sc_sa_ecc_err_addr_u {
	unsigned int val;
	struct irpy_sc_sa_ecc_err_addr bf;
};

struct igpoc_ctlf_ecc_err_addr {
	unsigned int ecc_err_addr:32;
};

union igpoc_ctlf_ecc_err_addr_u {
	unsigned int val;
	struct igpoc_ctlf_ecc_err_addr bf;
};

struct igpoc_ecc_err1_addr {
	unsigned int ecc_err_addr:32;
};

union igpoc_ecc_err1_addr_u {
	unsigned int val;
	struct igpoc_ecc_err1_addr bf;
};

struct igpoc_ecc_err2_addr {
	unsigned int ecc_err_addr:32;
};

union igpoc_ecc_err2_addr_u {
	unsigned int val;
	struct igpoc_ecc_err2_addr bf;
};

struct igsy_smib_ecc_err_addr {
	unsigned int ecc_err_addr:32;
};

union igsy_smib_ecc_err_addr_u {
	unsigned int val;
	struct igsy_smib_ecc_err_addr bf;
};

struct ig_table_cmd {
	unsigned int ig_table_cmd:32;
};

union ig_table_cmd_u {
	unsigned int val;
	struct ig_table_cmd bf;
};

struct ig_table_data {
	unsigned int ig_table_data:32;
};

union ig_table_data_u {
	unsigned int val;
	struct ig_table_data bf;
};

struct ig_ctl_filt {
	unsigned int sa_da_0:32;
	unsigned int sa_da_1:16;
	unsigned int ethertype_da_range:16;
	unsigned int match_mask:16;
	unsigned int match_type:4;
	unsigned int action:1;
	unsigned int _reserved0:11;
};

union ig_ctl_filt_u {
	unsigned int val[3];
	struct ig_ctl_filt bf;
};

struct ig_prc_lut {
	unsigned int sci_0:32;
	unsigned int sci_1:32;
	unsigned int tci:8;
	unsigned int encryption_offset:8;
	unsigned int ethertype:16;
	unsigned int snap_0:32;
	unsigned int snap_1:8;
	unsigned int llc:24;
	unsigned int sa_0:32;
	unsigned int sa_1:16;
	unsigned int da_0:16;
	unsigned int da_1:32;
	unsigned int lpbk_packet:1;
	unsigned int an_mask:2;
	unsigned int tci_7_2_mask:6;
	unsigned int sci_mask:8;
	unsigned int ethertype_mask:2;
	unsigned int snap_mask:5;
	unsigned int llc_mask:3;
	unsigned int dot2_encap:1;
	unsigned int sa_mask_0:4;
	unsigned int sa_mask_1:2;
	unsigned int da_mask:6;
	unsigned int lpbk_mask:1;
	unsigned int sc_index:5;
	unsigned int processing_dest:1;
	unsigned int action:2;
	unsigned int uncontrolled_port:1;
	unsigned int sci_from_table:1;
	unsigned int _reserved0:4;
	unsigned int valid:1;
	unsigned int _reserved1:8;
};

union ig_prc_lut_u {
	unsigned int val[10];
	struct ig_prc_lut bf;
};

struct ig_sc {
	unsigned int start_time:32;
	unsigned int stop_time:32;
	unsigned int validate_frames:2;
	unsigned int enable_reply_protect:1;
	unsigned int anti_replay_window_0:29;
	unsigned int anti_replay_window_1:3;
	unsigned int receiving:1;
	unsigned int fresh:1;
	unsigned int an_roll_over:1;
	unsigned int _reserved0:25;
	unsigned int valid:1;
};

union ig_sc_u {
	unsigned int val[4];
	struct ig_sc bf;
};

struct ig_sa {
	unsigned int start_time:32;
	unsigned int stop_time:32;
	unsigned int next_pn:32;
	unsigned int saturation_next_pn:1;
	unsigned int inuse:1;
	unsigned int rresh:1;
	unsigned int _reserved0:28;
	unsigned int valid:1;
};

union ig_sa_u {
	unsigned int val[4];
	struct ig_sa bf;
};

struct ig_sak {
	unsigned int sa_key_0:32;
	unsigned int sa_key_1:32;
	unsigned int sa_key_2:32;
	unsigned int sa_key_3:32;
};

union ig_sak_u {
	unsigned int val[4];
	struct ig_sak bf;
};

struct ig_poc_lut {
	unsigned int byte0:8;
	unsigned int byte1:8;
	unsigned int byte2:8;
	unsigned int byte3:8;
	unsigned int payload_ethertype:16;
	unsigned int ethertype_valid:1;
	unsigned int vlan_id:12;
	unsigned int vlan_up:3;
	unsigned int vlan_valid:1;
	unsigned int sai:5;
	unsigned int sai_hit:1;
	unsigned int payload_ethertype_mask:4;
	unsigned int byte3_location:6;
	unsigned int byte3_fieldmask:2;
	unsigned int byte2_location:6;
	unsigned int byte2_mask:2;
	unsigned int byte1_location_0:5;
	unsigned int byte1_location_1:1;
	unsigned int byte1_mask:2;
	unsigned int byte0_location:6;
	unsigned int byte0_mask:2;
	unsigned int ethertype_valid_mask:2;
	unsigned int vlan_id_mask:4;
	unsigned int vlan_up_mask:2;
	unsigned int vlan_valid_mask:2;
	unsigned int sai_mask:2;
	unsigned int sai_hit_mask:2;
	unsigned int first_level_action:1;
	unsigned int second_level_action:1;
	unsigned int _reserved0:4;
	unsigned int valid:1;
};

union ig_poc_lut_u {
	unsigned int val[4];
	struct ig_poc_lut bf;
};

struct ig_smib_sc_sa {
	unsigned int sa_untagged_hit_pkts_0:32;
	unsigned int sa_untagged_hit_pkts_1:32;
	unsigned int sa_hit_drop_redir_pkts_0:32;
	unsigned int sa_hit_drop_redir_pkts_1:32;
	unsigned int sa_not_using_sa_0:32;
	unsigned int sa_not_using_sa_1:32;
	unsigned int sa_unused_sa_0:32;
	unsigned int sa_unused_sa_1:32;
	unsigned int sa_not_valid_pkts_0:32;
	unsigned int sa_not_valid_pkts_1:32;
	unsigned int sa_invalid_pkts_0:32;
	unsigned int sa_invalid_pkts_1:32;
	unsigned int sa_ok_pkts_0:32;
	unsigned int sa_ok_pkts_1:32;
	unsigned int sa_late_pkts_0:32;
	unsigned int sa_late_pkts_1:32;
	unsigned int sa_delayed_pkts_0:32;
	unsigned int sa_delayed_pkts_1:32;
	unsigned int sa_unchecked_pkts_0:32;
	unsigned int sa_unchecked_pkts_1:32;
	unsigned int sa_validated_octets_0:32;
	unsigned int sa_validated_octets_1:32;
	unsigned int sa_decrypted_octets_0:32;
	unsigned int sa_decrypted_octets_1:32;
};

union ig_smib_sc_sa_u {
	unsigned int val[24];
	struct ig_smib_sc_sa bf;
};

struct ig_smib_common {
	unsigned int unctrl_prt_tx_octet_0:32;
	unsigned int unctrl_prt_tx_octet_1:32;
	unsigned int ctl_pkts_0:32;
	unsigned int ctl_pkts_1:32;
	unsigned int tagged_miss_pkts_0:32;
	unsigned int tagged_miss_pkts_1:32;
	unsigned int untagged_hit_pkts_0:32;
	unsigned int untagged_hit_pkts_1:32;
	unsigned int notag_pkts_0:32;
	unsigned int notag_pkts_1:32;
	unsigned int untagged_pkts_0:32;
	unsigned int untagged_pkts_1:32;
	unsigned int bad_tag_pkts_0:32;
	unsigned int bad_tag_pkts_1:32;
	unsigned int no_sci_pkts_0:32;
	unsigned int no_sci_pkts_1:32;
	unsigned int unknown_sci_pkts_0:32;
	unsigned int unknown_sci_pkts_1:32;
	unsigned int ctrl_prt_pass_pkts_0:32;
	unsigned int ctrl_prt_pass_pkts_1:32;
	unsigned int unctrl_prt_pass_pkts_0:32;
	unsigned int unctrl_prt_pass_pkts_1:32;
	unsigned int ctrl_prt_fail_pkts_0:32;
	unsigned int ctrl_prt_fail_pkts_1:32;
	unsigned int unctrl_prt_fail_pkts_0:32;
	unsigned int unctrl_prt_fail_pkts_1:32;
	unsigned int too_long_packets_0:32;
	unsigned int too_long_packets_1:32;
	unsigned int igpoc_ctl_pkts_0:32;
	unsigned int igpoc_ctl_pkts_1:32;
	unsigned int ecc_error_pkts_0:32;
	unsigned int ecc_error_pkts_1:32;
};

union ig_smib_common_u {
	unsigned int val[30];
	struct ig_smib_common bf;
};

struct egsy_l2sec_version {
	unsigned int egsy_l2sec_id:16;
	unsigned int egsy_l2sec_version:8;
	unsigned int egsy_l2sec_revision:8;
};

union egsy_l2sec_version_u {
	unsigned int val;
	struct egsy_l2sec_version bf;
};

struct egsy_l2sec_control {
	unsigned int csr_egsy_swrst:1;
	unsigned int csr_egsy_drop_kay_pkt:1;
	unsigned int csr_egsy_drop_egprc_miss:1;
	unsigned int csr_egsy_gcm_start:1;
	unsigned int csr_egsy_gcm_testmode:1;
	unsigned int csr_unmatched_use_sc_0:1;
	unsigned int csr_egsy_drop_sasc_invalid:1;
	unsigned int csr_egsy_expsectag_rep_sl:1;
	unsigned int csr_egsy_ext_clas_en:1;
	unsigned int csr_egsy_icv_msblsb_8bytes:1;
	unsigned int csr_egsy_high_priority:1;
	unsigned int csr_egsy_clr_cnt:1;
	unsigned int csr_egsy_clear_glbl_time:1;
	unsigned int _reserved0:19;
};

union egsy_l2sec_control_u {
	unsigned int val;
	struct egsy_l2sec_control bf;
};

struct egsy_prescale {
	unsigned int egsy_csr_prescale:32;
};

union egsy_prescale_u {
	unsigned int val;
	struct egsy_prescale bf;
};

struct csr_egsy_vlan_tpid0 {
	unsigned int csr_egsy_vlan_tpid0:16;
	unsigned int _reserved0:16;
};

union csr_egsy_vlan_tpid0_u {
	unsigned int val;
	struct csr_egsy_vlan_tpid0 bf;
};

struct csr_egsy_vlan_tpid1 {
	unsigned int csr_egsy_vlan_tpid1:16;
	unsigned int _reserved0:16;
};

union csr_egsy_vlan_tpid1_u {
	unsigned int val;
	struct csr_egsy_vlan_tpid1 bf;
};

struct csr_egsy_vlan_cp_tag {
	unsigned int csr_egsy_vlan_cp_tag_map_table:24;
	unsigned int csr_egsy_vlan_cp_tag_def_up:3;
	unsigned int csr_egsy_vlan_cp_tag_stag_up_en:1;
	unsigned int csr_egsy_vlan_cp_tag_qtag_up_en:1;
	unsigned int csr_egsy_vlan_cp_tag_q_in_q:1;
	unsigned int csr_egsy_vlan_cp_tag_parse_stag:1;
	unsigned int csr_egsy_vlan_cp_tag_parse_qtag:1;
};

union csr_egsy_vlan_cp_tag_u {
	unsigned int val;
	struct csr_egsy_vlan_cp_tag bf;
};

struct csr_egsy_pn_thr {
	unsigned int csr_pn_thr:32;
};

union csr_egsy_pn_thr_u {
	unsigned int val;
	struct csr_egsy_pn_thr bf;
};

struct csr_egsy_mtu {
	unsigned int csr_egsy_mtu:16;
	unsigned int unctrl_csr_egsy_mtu:16;
};

union csr_egsy_mtu_u {
	unsigned int val;
	struct csr_egsy_mtu bf;
};

struct csr_egsy_gcm_datain0 {
	unsigned int csr_egsy_gcm_data_in0:32;
};

union csr_egsy_gcm_datain0_u {
	unsigned int val;
	struct csr_egsy_gcm_datain0 bf;
};

struct csr_egsy_gcm_datain1 {
	unsigned int csr_egsy_gcm_data_in1:32;
};

union csr_egsy_gcm_datain1_u {
	unsigned int val;
	struct csr_egsy_gcm_datain1 bf;
};

struct csr_egsy_gcm_datain2 {
	unsigned int csr_egsy_gcm_data_in2:32;
};

union csr_egsy_gcm_datain2_u {
	unsigned int val;
	struct csr_egsy_gcm_datain2 bf;
};

struct csr_egsy_gcm_datain3 {
	unsigned int csr_egsy_gcm_data_in3:32;
};

union csr_egsy_gcm_datain3_u {
	unsigned int val;
	struct csr_egsy_gcm_datain3 bf;
};

struct csr_egsy_gcm_key0 {
	unsigned int csr_egsy_gcm_key0:32;
};

union csr_egsy_gcm_key0_u {
	unsigned int val;
	struct csr_egsy_gcm_key0 bf;
};

struct csr_egsy_gcm_key1 {
	unsigned int csr_egsy_gcm_key1:32;
};

union csr_egsy_gcm_key1_u {
	unsigned int val;
	struct csr_egsy_gcm_key1 bf;
};

struct csr_egsy_gcm_key2 {
	unsigned int csr_egsy_gcm_key2:32;
};

union csr_egsy_gcm_key2_u {
	unsigned int val;
	struct csr_egsy_gcm_key2 bf;
};

struct csr_egsy_gcm_key3 {
	unsigned int csr_egsy_gcm_key3:32;
};

union csr_egsy_gcm_key3_u {
	unsigned int val;
	struct csr_egsy_gcm_key3 bf;
};

struct csr_egsy_gcm_iv0 {
	unsigned int csr_egsy_gcm_iv0:32;
};

union csr_egsy_gcm_iv0_u {
	unsigned int val;
	struct csr_egsy_gcm_iv0 bf;
};

struct csr_egsy_gcm_iv1 {
	unsigned int csr_egsy_gcm_iv1:32;
};

union csr_egsy_gcm_iv1_u {
	unsigned int val;
	struct csr_egsy_gcm_iv1 bf;
};

struct csr_egsy_gcm_iv2 {
	unsigned int csr_egsy_gcm_iv2:32;
};

union csr_egsy_gcm_iv2_u {
	unsigned int val;
	struct csr_egsy_gcm_iv2 bf;
};

struct csr_egsy_gcm_iv3 {
	unsigned int csr_egsy_gcm_iv3:32;
};

union csr_egsy_gcm_iv3_u {
	unsigned int val;
	struct csr_egsy_gcm_iv3 bf;
};

struct csr_egsy_gcm_hashin0 {
	unsigned int csr_egsy_gcm_hashin0:32;
};

union csr_egsy_gcm_hashin0_u {
	unsigned int val;
	struct csr_egsy_gcm_hashin0 bf;
};

struct csr_egsy_gcm_hashin1 {
	unsigned int csr_egsy_gcm_hashin1:32;
};

union csr_egsy_gcm_hashin1_u {
	unsigned int val;
	struct csr_egsy_gcm_hashin1 bf;
};

struct csr_egsy_gcm_hashin2 {
	unsigned int csr_egsy_gcm_hashin2:32;
};

union csr_egsy_gcm_hashin2_u {
	unsigned int val;
	struct csr_egsy_gcm_hashin2 bf;
};

struct csr_egsy_gcm_hashin3 {
	unsigned int csr_egsy_gcm_hashin3:32;
};

union csr_egsy_gcm_hashin3_u {
	unsigned int val;
	struct csr_egsy_gcm_hashin3 bf;
};

struct egsy_gcm_csr_dataout0 {
	unsigned int egsy_gcm_csr_dataout0:32;
};

union egsy_gcm_csr_dataout0_u {
	unsigned int val;
	struct egsy_gcm_csr_dataout0 bf;
};

struct egsygcm_csr_dataout1 {
	unsigned int egsy_gcm_csr_dataout1:32;
};

union egsygcm_csr_dataout1_u {
	unsigned int val;
	struct egsygcm_csr_dataout1 bf;
};

struct egsy_gcm_csr_dataout2 {
	unsigned int egsy_gcm_csr_dataout2:32;
};

union egsy_gcm_csr_dataout2_u {
	unsigned int val;
	struct egsy_gcm_csr_dataout2 bf;
};

struct egsy_gcm_csr_dataout3 {
	unsigned int egsy_gcm_csr_dataout3:32;
};

union egsy_gcm_csr_dataout3_u {
	unsigned int val;
	struct egsy_gcm_csr_dataout3 bf;
};

struct egsy_gcm_csr_hashout0 {
	unsigned int egsy_gcm_csr_hashout0:32;
};

union egsy_gcm_csr_hashout0_u {
	unsigned int val;
	struct egsy_gcm_csr_hashout0 bf;
};

struct egsy_gcm_csr_hashout1 {
	unsigned int egsy_gcm_csr_hashout1:32;
};

union egsy_gcm_csr_hashout1_u {
	unsigned int val;
	struct egsy_gcm_csr_hashout1 bf;
};

struct egsy_gcm_csr_hashout2 {
	unsigned int egsy_gcm_csr_hashout2:32;
};

union egsy_gcm_csr_hashout2_u {
	unsigned int val;
	struct egsy_gcm_csr_hashout2 bf;
};

struct egsy_gcm_csr_hashout3 {
	unsigned int egsy_gcm_csr_hashout3:32;
};

union egsy_gcm_csr_hashout3_u {
	unsigned int val;
	struct egsy_gcm_csr_hashout3 bf;
};

struct egsy_egebuf_csr_debug {
	unsigned int gen_pktfmt_rem_csr_debug:6;
	unsigned int gen_pktfmt_remsw_csr_debug:6;
	unsigned int _reserved0:16;
};

union egsy_egebuf_csr_debug_u {
	unsigned int val;
	struct egsy_egebuf_csr_debug bf;
};

struct egsy_pfmt_csr_debug {
	unsigned int egsy_pktfmt_csr_debug:8;
	unsigned int egsy_pktfmt_sectag_ins_csr_debug:6;
	unsigned int gen_pktfmt_padins_csr_debug:6;
	unsigned int gen_pktfmt_rempad_csr_debug:4;
	unsigned int _reserved0:8;
};

union egsy_pfmt_csr_debug_u {
	unsigned int val;
	struct egsy_pfmt_csr_debug bf;
};

struct egsy_gcm_mult_lena_lsb_csr_debug {
	unsigned int egsy_gcm_mult_lena_lsb_csr_debug:32;
};

union egsy_gcm_mult_lena_lsb_csr_debug_u {
	unsigned int val;
	struct egsy_gcm_mult_lena_lsb_csr_debug bf;
};

struct egsy_gcm_mult_lena_msb_csr_debug {
	unsigned int egsy_gcm_mult_lena_msb_csr_debug:32;
};

union egsy_gcm_mult_lena_msb_csr_debug_u {
	unsigned int val;
	struct egsy_gcm_mult_lena_msb_csr_debug bf;
};

struct egsy_gcm_mult_lenc_lsb_csr_debug {
	unsigned int egsy_gcm_mult_lenc_lsb_csr_debug:32;
};

union egsy_gcm_mult_lenc_lsb_csr_debug_u {
	unsigned int val;
	struct egsy_gcm_mult_lenc_lsb_csr_debug bf;
};

struct egsy_gcm_mult_lenc_msb_csr_debug {
	unsigned int egsy_gcm_mult_lenc_msb_csr_debug:32;
};

union egsy_gcm_mult_lenc_msb_csr_debug_u {
	unsigned int val;
	struct egsy_gcm_mult_lenc_msb_csr_debug bf;
};

struct egsy_gcm_mult_data_cnt_csr_debug {
	unsigned int egsy_gcm_mult_data_cnt_csr_debug:2;
	unsigned int _reserved0:30;
};

union egsy_gcm_mult_data_cnt_csr_debug_u {
	unsigned int val;
	struct egsy_gcm_mult_data_cnt_csr_debug bf;
};

struct egsy_aes_gcm_counter_incr_csr_debug {
	unsigned int egsy_aes_gcm_counter_incr_csr_debug:32;
};

union egsy_aes_gcm_counter_incr_csr_debug_u {
	unsigned int val;
	struct egsy_aes_gcm_counter_incr_csr_debug bf;
};

struct egsy_csr_busy_signal {
	unsigned int egsy_dp_busy:1;
	unsigned int egsy_pfmt_busy:1;
	unsigned int egsy_aes_ctr_busy:1;
	unsigned int egsy_egebuf_busy:1;
	unsigned int egsy_gbuf_busy:1;
	unsigned int egsy_lkup_busy:1;
	unsigned int _reserved0:26;
};

union egsy_csr_busy_signal_u {
	unsigned int val;
	struct egsy_csr_busy_signal bf;
};

struct egsy_macsec_spare_reg1 {
	unsigned int egsy_macsec_spare_reg1:32;
};

union egsy_macsec_spare_reg1_u {
	unsigned int val;
	struct egsy_macsec_spare_reg1 bf;
};

struct egsy_sctrl_drop_en {
	unsigned int egsy_sctrl_drop_en:32;
};

union egsy_sctrl_drop_en_u {
	unsigned int val;
	struct egsy_sctrl_drop_en bf;
};

struct egsy_ectrl_enable {
	unsigned int egsy_ectrl_en:32;
};

union egsy_ectrl_enable_u {
	unsigned int val;
	struct egsy_ectrl_enable bf;
};

struct egsy_emac_regs {
	unsigned int en_gen_pause:1;
	unsigned int power_down_emac1:1;
	unsigned int resetemac1:1;
	unsigned int _reserved0:29;
};

union egsy_emac_regs_u {
	unsigned int val;
	struct egsy_emac_regs bf;
};

struct egsy_int {
	unsigned int egsy_int:1;
	unsigned int sa_exp_pulse_int:1;
	unsigned int sa_thr_pulse_int:1;
	unsigned int egsy_mib_sat_int:1;
	unsigned int ecc_err_int:1;
	unsigned int _reserved0:27;
};

union egsy_int_u {
	unsigned int val;
	struct egsy_int bf;
};

struct egsy_int_en {
	unsigned int egsy_int_en:1;
	unsigned int sa_exp_pulse_int_en:1;
	unsigned int sa_thr_pulse_int_en:1;
	unsigned int egsy_mib_sat_int_en:1;
	unsigned int ecc_err_int_en:1;
	unsigned int _reserved0:27;
};

union egsy_int_en_u {
	unsigned int val;
	struct egsy_int_en bf;
};

struct egsy_sa_exp {
	unsigned int egsy_sa_exp:32;
};

union egsy_sa_exp_u {
	unsigned int val;
	struct egsy_sa_exp bf;
};

struct egsy_sa_thr {
	unsigned int egsy_sa_thr:32;
};

union egsy_sa_thr_u {
	unsigned int val;
	struct egsy_sa_thr bf;
};

struct egecc_err_reg {
	unsigned int ecc_err_reg:32;
};

union egecc_err_reg_u {
	unsigned int val;
	struct egecc_err_reg bf;
};

struct egprc_ecc_err1_addr {
	unsigned int ecc_err_addr:32;
};

union egprc_ecc_err1_addr_u {
	unsigned int val;
	struct egprc_ecc_err1_addr bf;
};

struct egprc_ecc_err2_addr {
	unsigned int ecc_err_addr:32;
};

union egprc_ecc_err2_addr_u {
	unsigned int val;
	struct egprc_ecc_err2_addr bf;
};

struct eglkup_ctlf_ecc_err_addr {
	unsigned int ecc_err_addr:32;
};

union eglkup_ctlf_ecc_err_addr_u {
	unsigned int val;
	struct eglkup_ctlf_ecc_err_addr bf;
};

struct pfmt_sc_sa_ecc_err_addr {
	unsigned int ecc_err_addr:32;
};

union pfmt_sc_sa_ecc_err_addr_u {
	unsigned int val;
	struct pfmt_sc_sa_ecc_err_addr bf;
};

struct egsy_smib_ecc_err_addr {
	unsigned int ecc_err_addr:32;
};

union egsy_smib_ecc_err_addr_u {
	unsigned int val;
	struct egsy_smib_ecc_err_addr bf;
};

struct egsy_enable_ecc {
	unsigned int egsy_enable_ecc:32;
};

union egsy_enable_ecc_u {
	unsigned int val;
	struct egsy_enable_ecc bf;
};

struct eg_table_cmd {
	unsigned int eg_table_cmd:32;
};

union eg_table_cmd_u {
	unsigned int val;
	struct eg_table_cmd bf;
};

struct eg_table_data {
	unsigned int eg_table_data:32;
};

union eg_table_data_u {
	unsigned int val;
	struct eg_table_data bf;
};

struct eg_ctl_filt {
	unsigned int sa_da_0:32;
	unsigned int sa_da_1:16;
	unsigned int ethertype_da_range:16;
	unsigned int match_mask:16;
	unsigned int match_type:4;
	unsigned int action:1;
	unsigned int _reserved0:11;
};

union eg_ctl_filt_u {
	unsigned int val[3];
	struct eg_ctl_filt bf;
};

struct eg_class_lut {
	unsigned int vlan_id:12;
	unsigned int vlan_up:3;
	unsigned int vlan_valid:1;
	unsigned int byte3:8;
	unsigned int byte2:8;
	unsigned int byte1:8;
	unsigned int byte0:8;
	unsigned int tci:8;
	unsigned int sci_0:8;
	unsigned int sci_1:32;
	unsigned int sci_2:24;
	unsigned int ethertype_0:8;
	unsigned int ethertype_1:8;
	unsigned int snap_0:24;
	unsigned int snap_1:16;
	unsigned int llc_0:16;
	unsigned int llc_1:8;
	unsigned int sa_0:24;
	unsigned int sa_1:24;
	unsigned int da_0:8;
	unsigned int da_1:32;
	unsigned int da_2:8;
	unsigned int pn_0:24;
	unsigned int pn_1:8;
	unsigned int byte3_location:6;
	unsigned int byte3_mask:1;
	unsigned int byte2_location:6;
	unsigned int byte2_mask:1;
	unsigned int byte1_location:6;
	unsigned int byte1_mask:1;
	unsigned int byte0_location_0:3;
	unsigned int byte0_location_1:3;
	unsigned int byte0_mask:1;
	unsigned int vlan_id_mask:2;
	unsigned int vlan_up_mask:1;
	unsigned int vlan_valid_mask:1;
	unsigned int tci_mask:8;
	unsigned int sci_mask:8;
	unsigned int ethertype_mask:2;
	unsigned int snap_mask:5;
	unsigned int llc_mask_0:1;
	unsigned int llc_mask_1:2;
	unsigned int sa_mask:6;
	unsigned int da_mask:6;
	unsigned int pn_mask:4;
	unsigned int dot2_encap:1;
	unsigned int use_tci_sc_from_table:1;
	unsigned int use_tci_87543_from_table:1;
	unsigned int is_explicit_sectag:1;
	unsigned int sc_index:5;
	unsigned int sc_sa_association:2;
	unsigned int debug_loopback:1;
	unsigned int action:2;
	unsigned int _reserved0:3;
	unsigned int valid:1;
	unsigned int _reserved1:28;
};

union eg_class_lut_u {
	unsigned int val[14];
	struct eg_class_lut bf;
};

struct eg_sc {
	unsigned int start_time:32;
	unsigned int stop_time:32;
	unsigned int current_an:2;
	unsigned int enable_an_roll_over:1;
	unsigned int tci_7_2:6;
	unsigned int confidentiality_offset:8;
	unsigned int protect_frames:1;
	unsigned int receiving:1;
	unsigned int fresh:1;
	unsigned int sak_len:2;
	unsigned int _reserved0_0:10;
	unsigned int _reserved0_1:31;
	unsigned int valid:1;
};

union eg_sc_u {
	unsigned int val[4];
	struct eg_sc bf;
};

struct eg_sa {
	unsigned int start_time:32;
	unsigned int stop_time:32;
	unsigned int next_pn:32;
	unsigned int saturation_next_pn:1;
	unsigned int fresh:1;
	unsigned int _reserved0:29;
	unsigned int valid:1;
};

union eg_sa_u {
	unsigned int val[4];
	struct eg_sa bf;
};

struct eg_sak {
	unsigned int sa_key_0:32;
	unsigned int sa_key_1:32;
	unsigned int sa_key_2:32;
	unsigned int sa_key_3:32;
};

union eg_sak_u {
	unsigned int val[4];
	struct eg_sak bf;
};

struct eg_smib_sc_sa {
	unsigned int sa_hit_drop_redirect_0:32;
	unsigned int sa_hit_drop_redirect_1:32;
	unsigned int sa_protected2_pkts_0:32;
	unsigned int sa_protected2_pkts_1:32;
	unsigned int sa_protected_pkts_0:32;
	unsigned int sa_protected_pkts_1:32;
	unsigned int sa_encrypted_pkts_0:32;
	unsigned int sa_encrypted_pkts_1:32;
	unsigned int sc_protected_pkts_0:32;
	unsigned int sc_protected_pkts_1:32;
	unsigned int sc_encrypted_pkts_0:32;
	unsigned int sc_encrypted_pkts_1:32;
	unsigned int sc_protected_octets_0:32;
	unsigned int sc_protected_octets_1:32;
	unsigned int sc_encrypted_octets_0:32;
	unsigned int sc_encrypted_octets_1:32;
};

union eg_smib_sc_sa_u {
	unsigned int val[16];
	struct eg_smib_sc_sa bf;
};

struct eg_smib_common {
	unsigned int ctl_pkts_0:32;
	unsigned int ctl_pkts_1:32;
	unsigned int unknown_sa_pkts_0:32;
	unsigned int unknown_sa_pkts_1:32;
	unsigned int untagged_pkts_0:32;
	unsigned int untagged_pkts_1:32;
	unsigned int too_long_0:32;
	unsigned int too_long_1:32;
	unsigned int ecc_error_pkts_0:32;
	unsigned int ecc_error_pkts_1:32;
	unsigned int unctrl_hit_drop_redir_pkts_0:32;
	unsigned int unctrl_hit_drop_redir_pkts_1:32;
};

union eg_smib_common_u {
	unsigned int val[12];
	struct eg_smib_common bf;
};

struct emac1_rev {
	unsigned int morethanip_core_rveision:16;
	unsigned int customer_specific_revision:16;
};

union emac1_rev_u {
	unsigned int val;
	struct emac1_rev bf;
};

struct emac1_scratch {
	unsigned int scratch:32;
};

union emac1_scratch_u {
	unsigned int val;
	struct emac1_scratch bf;
};

struct emac1_command_config {
	unsigned int tx_ena:1;
	unsigned int rx_ena:1;
	unsigned int _reserved0:1;
	unsigned int eth_speed:1;
	unsigned int promis_en:1;
	unsigned int pad_en:1;
	unsigned int crc_fwd:1;
	unsigned int pause_fwd:1;
	unsigned int pause_ignore:1;
	unsigned int tx_addr_ins:1;
	unsigned int hd_ena:1;
	unsigned int excess_col:1;
	unsigned int late_col:1;
	unsigned int sw_reset:1;
	unsigned int mhash_sel:1;
	unsigned int loop_ena:1;
	unsigned int tx_addr_sel:3;
	unsigned int magic_ena:1;
	unsigned int sleep:1;
	unsigned int wakeup:1;
	unsigned int _reserved1:1;
	unsigned int cntl_frm_ena:1;
	unsigned int no_lgth_check:1;
	unsigned int ena_10:1;
	unsigned int rx_err_disc:1;
	unsigned int _reserved2:4;
	unsigned int cnt_reset:1;
};

union emac1_command_config_u {
	unsigned int val;
	struct emac1_command_config bf;
};

struct emac1_mac_0 {
	unsigned int mac_address_word0:32;
};

union emac1_mac_0_u {
	unsigned int val;
	struct emac1_mac_0 bf;
};

struct emac1_mac_1 {
	unsigned int mac_address_word1:16;
	unsigned int _reserved0:16;
};

union emac1_mac_1_u {
	unsigned int val;
	struct emac1_mac_1 bf;
};

struct emac1_frm_length {
	unsigned int max_frame_length:14;
	unsigned int _reserved0:18;
};

union emac1_frm_length_u {
	unsigned int val;
	struct emac1_frm_length bf;
};

struct emac1_pause_quant {
	unsigned int receive_pause_quanta:16;
	unsigned int _reserved0:16;
};

union emac1_pause_quant_u {
	unsigned int val;
	struct emac1_pause_quant bf;
};

struct emac1_rx_section_empty {
	unsigned int rx_section_empty:8;
	unsigned int _reserved0:24;
};

union emac1_rx_section_empty_u {
	unsigned int val;
	struct emac1_rx_section_empty bf;
};

struct emac1_rx_section_full {
	unsigned int rx_section_full:8;
	unsigned int _reserved0:24;
};

union emac1_rx_section_full_u {
	unsigned int val;
	struct emac1_rx_section_full bf;
};

struct emac1_tx_section_empty {
	unsigned int tx_section_empty:8;
	unsigned int _reserved0:24;
};

union emac1_tx_section_empty_u {
	unsigned int val;
	struct emac1_tx_section_empty bf;
};

struct emac1_tx_section_full {
	unsigned int tx_section_full:8;
	unsigned int _reserved0:24;
};

union emac1_tx_section_full_u {
	unsigned int val;
	struct emac1_tx_section_full bf;
};

struct emac1_rx_almost_empty {
	unsigned int rx_almost_empty:8;
	unsigned int _reserved0:24;
};

union emac1_rx_almost_empty_u {
	unsigned int val;
	struct emac1_rx_almost_empty bf;
};

struct emac1_rx_almost_full {
	unsigned int rx_almost_full:8;
	unsigned int _reserved0:24;
};

union emac1_rx_almost_full_u {
	unsigned int val;
	struct emac1_rx_almost_full bf;
};

struct emac1_tx_almost_empty {
	unsigned int tx_almost_empty:8;
	unsigned int _reserved0:24;
};

union emac1_tx_almost_empty_u {
	unsigned int val;
	struct emac1_tx_almost_empty bf;
};

struct emac1_tx_almost_full {
	unsigned int tx_almost_full:8;
	unsigned int _reserved0:24;
};

union emac1_tx_almost_full_u {
	unsigned int val;
	struct emac1_tx_almost_full bf;
};

struct emac1_mdio_addr0 {
	unsigned int mdio_addr0:5;
	unsigned int _reserved0:27;
};

union emac1_mdio_addr0_u {
	unsigned int val;
	struct emac1_mdio_addr0 bf;
};

struct emac1_mdio_addr1 {
	unsigned int mdio_addr1:5;
	unsigned int _reserved0:27;
};

union emac1_mdio_addr1_u {
	unsigned int val;
	struct emac1_mdio_addr1 bf;
};

struct emac1_reg_status {
	unsigned int read_timeout:1;
	unsigned int _reserved0:31;
};

union emac1_reg_status_u {
	unsigned int val;
	struct emac1_reg_status bf;
};

struct emac1_tx_ipg_length {
	unsigned int tx_ipg_length:5;
	unsigned int _reserved0:27;
};

union emac1_tx_ipg_length_u {
	unsigned int val;
	struct emac1_tx_ipg_length bf;
};

struct emac1_amacid {
	unsigned int mac_0:32;
	unsigned int mac_1:16;
	unsigned int _reserved0:16;
};

union emac1_amacid_u {
	unsigned int val[2];
	struct emac1_amacid bf;
};

struct emac1_aframestransmittedok {
	unsigned int aframestransmittedok:32;
};

union emac1_aframestransmittedok_u {
	unsigned int val;
	struct emac1_aframestransmittedok bf;
};

struct emac1_aframesreceivedok {
	unsigned int aframesreceivedok:32;
};

union emac1_aframesreceivedok_u {
	unsigned int val;
	struct emac1_aframesreceivedok bf;
};

struct emac1_aframechecksequenceerrors {
	unsigned int aframechecksequenceerrors:32;
};

union emac1_aframechecksequenceerrors_u {
	unsigned int val;
	struct emac1_aframechecksequenceerrors bf;
};

struct emac1_aalignmenterrors {
	unsigned int aalignmenterrors:32;
};

union emac1_aalignmenterrors_u {
	unsigned int val;
	struct emac1_aalignmenterrors bf;
};

struct emac1_aoctetstransmittedok {
	unsigned int aoctetstransmittedok:32;
};

union emac1_aoctetstransmittedok_u {
	unsigned int val;
	struct emac1_aoctetstransmittedok bf;
};

struct emac1_aoctetsreceivedok {
	unsigned int aoctetsreceivedok:32;
};

union emac1_aoctetsreceivedok_u {
	unsigned int val;
	struct emac1_aoctetsreceivedok bf;
};

struct emac1_atxpausemacctrlframes {
	unsigned int atxpausemacctrlframes:32;
};

union emac1_atxpausemacctrlframes_u {
	unsigned int val;
	struct emac1_atxpausemacctrlframes bf;
};

struct emac1_arxpausemacctrlframes {
	unsigned int arxpausemacctrlframes:32;
};

union emac1_arxpausemacctrlframes_u {
	unsigned int val;
	struct emac1_arxpausemacctrlframes bf;
};

struct emac1_ifinerrors {
	unsigned int ifinerrors:32;
};

union emac1_ifinerrors_u {
	unsigned int val;
	struct emac1_ifinerrors bf;
};

struct emac1_ifouterrors {
	unsigned int ifouterrors:32;
};

union emac1_ifouterrors_u {
	unsigned int val;
	struct emac1_ifouterrors bf;
};

struct emac1_ifinucastpkts {
	unsigned int ifinucastpkts:32;
};

union emac1_ifinucastpkts_u {
	unsigned int val;
	struct emac1_ifinucastpkts bf;
};

struct emac1_ifinmulticastpkts {
	unsigned int ifinmulticastpkts:32;
};

union emac1_ifinmulticastpkts_u {
	unsigned int val;
	struct emac1_ifinmulticastpkts bf;
};

struct emac1_ifinbroadcastpkts {
	unsigned int ifinbroadcastpkts:32;
};

union emac1_ifinbroadcastpkts_u {
	unsigned int val;
	struct emac1_ifinbroadcastpkts bf;
};

struct emac1_ifoutdiscards {
	unsigned int ifoutdiscards:32;
};

union emac1_ifoutdiscards_u {
	unsigned int val;
	struct emac1_ifoutdiscards bf;
};

struct emac1_ifoutucastpkts {
	unsigned int ifoutucastpkts:32;
};

union emac1_ifoutucastpkts_u {
	unsigned int val;
	struct emac1_ifoutucastpkts bf;
};

struct emac1_ifoutmulticastpkts {
	unsigned int ifoutmulticastpkts:32;
};

union emac1_ifoutmulticastpkts_u {
	unsigned int val;
	struct emac1_ifoutmulticastpkts bf;
};

struct emac1_ifoutbroadcastpkts {
	unsigned int ifoutbroadcastpkts:32;
};

union emac1_ifoutbroadcastpkts_u {
	unsigned int val;
	struct emac1_ifoutbroadcastpkts bf;
};

struct emac1_etherstatsdropevents {
	unsigned int etherstatsdropevents:32;
};

union emac1_etherstatsdropevents_u {
	unsigned int val;
	struct emac1_etherstatsdropevents bf;
};

struct emac1_etherstatsoctets {
	unsigned int etherstatsoctets:32;
};

union emac1_etherstatsoctets_u {
	unsigned int val;
	struct emac1_etherstatsoctets bf;
};

struct emac1_etherstatspkts {
	unsigned int etherstatspkts:32;
};

union emac1_etherstatspkts_u {
	unsigned int val;
	struct emac1_etherstatspkts bf;
};

struct emac1_etherstatsundersizepkts {
	unsigned int etherstatsundersizepkts:32;
};

union emac1_etherstatsundersizepkts_u {
	unsigned int val;
	struct emac1_etherstatsundersizepkts bf;
};

struct emac1_etherstatsoversizepkts {
	unsigned int etherstatsoversizepkts:32;
};

union emac1_etherstatsoversizepkts_u {
	unsigned int val;
	struct emac1_etherstatsoversizepkts bf;
};

struct emac1_etherstatspkts64octets {
	unsigned int etherstatspkts64octets:32;
};

union emac1_etherstatspkts64octets_u {
	unsigned int val;
	struct emac1_etherstatspkts64octets bf;
};

struct emac1_etherstatspkts65to127octets {
	unsigned int etherstatspkts65to127octets:32;
};

union emac1_etherstatspkts65to127octets_u {
	unsigned int val;
	struct emac1_etherstatspkts65to127octets bf;
};

struct emac1_etherstatspkts128to255octets {
	unsigned int etherstatspkts128to255octets:32;
};

union emac1_etherstatspkts128to255octets_u {
	unsigned int val;
	struct emac1_etherstatspkts128to255octets bf;
};

struct emac1_etherstatspkts256to511octets {
	unsigned int etherstatspkts256to511octets:32;
};

union emac1_etherstatspkts256to511octets_u {
	unsigned int val;
	struct emac1_etherstatspkts256to511octets bf;
};

struct emac1_etherstatspkts512to1023octets {
	unsigned int etherstatspkts512to1023octets:32;
};

union emac1_etherstatspkts512to1023octets_u {
	unsigned int val;
	struct emac1_etherstatspkts512to1023octets bf;
};

struct emac1_etherstatspkts1024to1518octets {
	unsigned int etherstatspkts1024to1518octets:32;
};

union emac1_etherstatspkts1024to1518octets_u {
	unsigned int val;
	struct emac1_etherstatspkts1024to1518octets bf;
};

struct emac1_etherstatspkts1519toxoctets {
	unsigned int etherstatspkts1519toxoctets:32;
};

union emac1_etherstatspkts1519toxoctets_u {
	unsigned int val;
	struct emac1_etherstatspkts1519toxoctets bf;
};

struct emac1_etherstatsjabbers {
	unsigned int etherstatsjabbers:32;
};

union emac1_etherstatsjabbers_u {
	unsigned int val;
	struct emac1_etherstatsjabbers bf;
};

struct emac1_etherstatsfragments {
	unsigned int etherstatsfragments:32;
};

union emac1_etherstatsfragments_u {
	unsigned int val;
	struct emac1_etherstatsfragments bf;
};

struct emac2_rev {
	unsigned int morethanip_core_rveision:16;
	unsigned int customer_specific_revision:16;
};

union emac2_rev_u {
	unsigned int val;
	struct emac2_rev bf;
};

struct emac2_scratch {
	unsigned int scratch:32;
};

union emac2_scratch_u {
	unsigned int val;
	struct emac2_scratch bf;
};

struct emac2_command_config {
	unsigned int tx_ena:1;
	unsigned int rx_ena:1;
	unsigned int _reserved0:1;
	unsigned int eth_speed:1;
	unsigned int promis_en:1;
	unsigned int pad_en:1;
	unsigned int crc_fwd:1;
	unsigned int pause_fwd:1;
	unsigned int pause_ignore:1;
	unsigned int tx_addr_ins:1;
	unsigned int hd_ena:1;
	unsigned int excess_col:1;
	unsigned int late_col:1;
	unsigned int sw_reset:1;
	unsigned int mhash_sel:1;
	unsigned int loop_ena:1;
	unsigned int tx_addr_sel:3;
	unsigned int magic_ena:1;
	unsigned int sleep:1;
	unsigned int wakeup:1;
	unsigned int _reserved1:1;
	unsigned int cntl_frm_ena:1;
	unsigned int no_lgth_check:1;
	unsigned int ena_10:1;
	unsigned int rx_err_disc:1;
	unsigned int _reserved2:4;
	unsigned int cnt_reset:1;
};

union emac2_command_config_u {
	unsigned int val;
	struct emac2_command_config bf;
};

struct emac2_mac_0 {
	unsigned int mac_address_word0:32;
};

union emac2_mac_0_u {
	unsigned int val;
	struct emac2_mac_0 bf;
};

struct emac2_mac_1 {
	unsigned int mac_address_word1:16;
	unsigned int _reserved0:16;
};

union emac2_mac_1_u {
	unsigned int val;
	struct emac2_mac_1 bf;
};

struct emac2_frm_length {
	unsigned int max_frame_length:14;
	unsigned int _reserved0:18;
};

union emac2_frm_length_u {
	unsigned int val;
	struct emac2_frm_length bf;
};

struct emac2_pause_quant {
	unsigned int receive_pause_quanta:16;
	unsigned int _reserved0:16;
};

union emac2_pause_quant_u {
	unsigned int val;
	struct emac2_pause_quant bf;
};

struct emac2_rx_section_empty {
	unsigned int rx_section_empty:8;
	unsigned int _reserved0:24;
};

union emac2_rx_section_empty_u {
	unsigned int val;
	struct emac2_rx_section_empty bf;
};

struct emac2_rx_section_full {
	unsigned int rx_section_full:8;
	unsigned int _reserved0:24;
};

union emac2_rx_section_full_u {
	unsigned int val;
	struct emac2_rx_section_full bf;
};

struct emac2_tx_section_empty {
	unsigned int tx_section_empty:8;
	unsigned int _reserved0:24;
};

union emac2_tx_section_empty_u {
	unsigned int val;
	struct emac2_tx_section_empty bf;
};

struct emac2_tx_section_full {
	unsigned int tx_section_full:8;
	unsigned int _reserved0:24;
};

union emac2_tx_section_full_u {
	unsigned int val;
	struct emac2_tx_section_full bf;
};

struct emac2_rx_almost_empty {
	unsigned int rx_almost_empty:8;
	unsigned int _reserved0:24;
};

union emac2_rx_almost_empty_u {
	unsigned int val;
	struct emac2_rx_almost_empty bf;
};

struct emac2_rx_almost_full {
	unsigned int rx_almost_full:8;
	unsigned int _reserved0:24;
};

union emac2_rx_almost_full_u {
	unsigned int val;
	struct emac2_rx_almost_full bf;
};

struct emac2_tx_almost_empty {
	unsigned int tx_almost_empty:8;
	unsigned int _reserved0:24;
};

union emac2_tx_almost_empty_u {
	unsigned int val;
	struct emac2_tx_almost_empty bf;
};

struct emac2_tx_almost_full {
	unsigned int tx_almost_full:8;
	unsigned int _reserved0:24;
};

union emac2_tx_almost_full_u {
	unsigned int val;
	struct emac2_tx_almost_full bf;
};

struct emac2_mdio_addr0 {
	unsigned int mdio_addr0:5;
	unsigned int _reserved0:27;
};

union emac2_mdio_addr0_u {
	unsigned int val;
	struct emac2_mdio_addr0 bf;
};

struct emac2_mdio_addr1 {
	unsigned int mdio_addr1:5;
	unsigned int _reserved0:27;
};

union emac2_mdio_addr1_u {
	unsigned int val;
	struct emac2_mdio_addr1 bf;
};

struct emac2_reg_status {
	unsigned int read_timeout:1;
	unsigned int _reserved0:31;
};

union emac2_reg_status_u {
	unsigned int val;
	struct emac2_reg_status bf;
};

struct emac2_tx_ipg_length {
	unsigned int tx_ipg_length:5;
	unsigned int _reserved0:27;
};

union emac2_tx_ipg_length_u {
	unsigned int val;
	struct emac2_tx_ipg_length bf;
};

struct emac2_amacid {
	unsigned int mac_0:32;
	unsigned int mac_1:16;
	unsigned int _reserved0:16;
};

union emac2_amacid_u {
	unsigned int val[2];
	struct emac2_amacid bf;
};

struct emac2_aframestransmittedok {
	unsigned int aframestransmittedok:32;
};

union emac2_aframestransmittedok_u {
	unsigned int val;
	struct emac2_aframestransmittedok bf;
};

struct emac2_aframesreceivedok {
	unsigned int aframesreceivedok:32;
};

union emac2_aframesreceivedok_u {
	unsigned int val;
	struct emac2_aframesreceivedok bf;
};

struct emac2_aframechecksequenceerrors {
	unsigned int aframechecksequenceerrors:32;
};

union emac2_aframechecksequenceerrors_u {
	unsigned int val;
	struct emac2_aframechecksequenceerrors bf;
};

struct emac2_aalignmenterrors {
	unsigned int aalignmenterrors:32;
};

union emac2_aalignmenterrors_u {
	unsigned int val;
	struct emac2_aalignmenterrors bf;
};

struct emac2_aoctetstransmittedok {
	unsigned int aoctetstransmittedok:32;
};

union emac2_aoctetstransmittedok_u {
	unsigned int val;
	struct emac2_aoctetstransmittedok bf;
};

struct emac2_aoctetsreceivedok {
	unsigned int aoctetsreceivedok:32;
};

union emac2_aoctetsreceivedok_u {
	unsigned int val;
	struct emac2_aoctetsreceivedok bf;
};

struct emac2_atxpausemacctrlframes {
	unsigned int atxpausemacctrlframes:32;
};

union emac2_atxpausemacctrlframes_u {
	unsigned int val;
	struct emac2_atxpausemacctrlframes bf;
};

struct emac2_arxpausemacctrlframes {
	unsigned int arxpausemacctrlframes:32;
};

union emac2_arxpausemacctrlframes_u {
	unsigned int val;
	struct emac2_arxpausemacctrlframes bf;
};

struct emac2_ifinerrors {
	unsigned int ifinerrors:32;
};

union emac2_ifinerrors_u {
	unsigned int val;
	struct emac2_ifinerrors bf;
};

struct emac2_ifouterrors {
	unsigned int ifouterrors:32;
};

union emac2_ifouterrors_u {
	unsigned int val;
	struct emac2_ifouterrors bf;
};

struct emac2_ifinucastpkts {
	unsigned int ifinucastpkts:32;
};

union emac2_ifinucastpkts_u {
	unsigned int val;
	struct emac2_ifinucastpkts bf;
};

struct emac2_ifinmulticastpkts {
	unsigned int ifinmulticastpkts:32;
};

union emac2_ifinmulticastpkts_u {
	unsigned int val;
	struct emac2_ifinmulticastpkts bf;
};

struct emac2_ifinbroadcastpkts {
	unsigned int ifinbroadcastpkts:32;
};

union emac2_ifinbroadcastpkts_u {
	unsigned int val;
	struct emac2_ifinbroadcastpkts bf;
};

struct emac2_ifoutdiscards {
	unsigned int ifoutdiscards:32;
};

union emac2_ifoutdiscards_u {
	unsigned int val;
	struct emac2_ifoutdiscards bf;
};

struct emac2_ifoutucastpkts {
	unsigned int ifoutucastpkts:32;
};

union emac2_ifoutucastpkts_u {
	unsigned int val;
	struct emac2_ifoutucastpkts bf;
};

struct emac2_ifoutmulticastpkts {
	unsigned int ifoutmulticastpkts:32;
};

union emac2_ifoutmulticastpkts_u {
	unsigned int val;
	struct emac2_ifoutmulticastpkts bf;
};

struct emac2_ifoutbroadcastpkts {
	unsigned int ifoutbroadcastpkts:32;
};

union emac2_ifoutbroadcastpkts_u {
	unsigned int val;
	struct emac2_ifoutbroadcastpkts bf;
};

struct emac2_etherstatsdropevents {
	unsigned int etherstatsdropevents:32;
};

union emac2_etherstatsdropevents_u {
	unsigned int val;
	struct emac2_etherstatsdropevents bf;
};

struct emac2_etherstatsoctets {
	unsigned int etherstatsoctets:32;
};

union emac2_etherstatsoctets_u {
	unsigned int val;
	struct emac2_etherstatsoctets bf;
};

struct emac2_etherstatspkts {
	unsigned int etherstatspkts:32;
};

union emac2_etherstatspkts_u {
	unsigned int val;
	struct emac2_etherstatspkts bf;
};

struct emac2_etherstatsundersizepkts {
	unsigned int etherstatsundersizepkts:32;
};

union emac2_etherstatsundersizepkts_u {
	unsigned int val;
	struct emac2_etherstatsundersizepkts bf;
};

struct emac2_etherstatsoversizepkts {
	unsigned int etherstatsoversizepkts:32;
};

union emac2_etherstatsoversizepkts_u {
	unsigned int val;
	struct emac2_etherstatsoversizepkts bf;
};

struct emac2_etherstatspkts64octets {
	unsigned int etherstatspkts64octets:32;
};

union emac2_etherstatspkts64octets_u {
	unsigned int val;
	struct emac2_etherstatspkts64octets bf;
};

struct emac2_etherstatspkts65to127octets {
	unsigned int etherstatspkts65to127octets:32;
};

union emac2_etherstatspkts65to127octets_u {
	unsigned int val;
	struct emac2_etherstatspkts65to127octets bf;
};

struct emac2_etherstatspkts128to255octets {
	unsigned int etherstatspkts128to255octets:32;
};

union emac2_etherstatspkts128to255octets_u {
	unsigned int val;
	struct emac2_etherstatspkts128to255octets bf;
};

struct emac2_etherstatspkts256to511octets {
	unsigned int etherstatspkts256to511octets:32;
};

union emac2_etherstatspkts256to511octets_u {
	unsigned int val;
	struct emac2_etherstatspkts256to511octets bf;
};

struct emac2_etherstatspkts512to1023octets {
	unsigned int etherstatspkts512to1023octets:32;
};

union emac2_etherstatspkts512to1023octets_u {
	unsigned int val;
	struct emac2_etherstatspkts512to1023octets bf;
};

struct emac2_etherstatspkts1024to1518octets {
	unsigned int etherstatspkts1024to1518octets:32;
};

union emac2_etherstatspkts1024to1518octets_u {
	unsigned int val;
	struct emac2_etherstatspkts1024to1518octets bf;
};

struct emac2_etherstatspkts1519toxoctets {
	unsigned int etherstatspkts1519toxoctets:32;
};

union emac2_etherstatspkts1519toxoctets_u {
	unsigned int val;
	struct emac2_etherstatspkts1519toxoctets bf;
};

struct emac2_etherstatsjabbers {
	unsigned int etherstatsjabbers:32;
};

union emac2_etherstatsjabbers_u {
	unsigned int val;
	struct emac2_etherstatsjabbers bf;
};

struct emac2_etherstatsfragments {
	unsigned int etherstatsfragments:32;
};

union emac2_etherstatsfragments_u {
	unsigned int val;
	struct emac2_etherstatsfragments bf;
};

int igsy_l2sec_version_get(unsigned int dev_id,
			   union igsy_l2sec_version_u *value);
int igsy_l2sec_version_set(unsigned int dev_id,
			   union igsy_l2sec_version_u *value);
int insy_prescale_get(unsigned int dev_id, union insy_prescale_u *value);
int insy_prescale_set(unsigned int dev_id, union insy_prescale_u *value);
int csr_igsy_vlan_tpid0_get(unsigned int dev_id,
			    union csr_igsy_vlan_tpid0_u *value);
int csr_igsy_vlan_tpid0_set(unsigned int dev_id,
			    union csr_igsy_vlan_tpid0_u *value);
int csr_igsy_vlan_tpid1_get(unsigned int dev_id,
			    union csr_igsy_vlan_tpid1_u *value);
int csr_igsy_vlan_tpid1_set(unsigned int dev_id,
			    union csr_igsy_vlan_tpid1_u *value);
int csr_igsy_vlan_cp_tag_get(unsigned int dev_id,
			     union csr_igsy_vlan_cp_tag_u *value);
int csr_igsy_vlan_cp_tag_set(unsigned int dev_id,
			     union csr_igsy_vlan_cp_tag_u *value);
int csr_igsy_mtu_get(unsigned int dev_id, union csr_igsy_mtu_u *value);
int csr_igsy_mtu_set(unsigned int dev_id, union csr_igsy_mtu_u *value);
int csr_igsy_ctrl_get(unsigned int dev_id, union csr_igsy_ctrl_u *value);
int csr_igsy_ctrl_set(unsigned int dev_id, union csr_igsy_ctrl_u *value);
int csr_insy_sa_thr_get(unsigned int dev_id, union csr_insy_sa_thr_u *value);
int csr_insy_sa_thr_set(unsigned int dev_id, union csr_insy_sa_thr_u *value);
int insy_fmt_csr_debug_get(unsigned int dev_id,
			   union insy_fmt_csr_debug_u *value);
int insy_fmt_csr_debug_set(unsigned int dev_id,
			   union insy_fmt_csr_debug_u *value);
int insy_rpy_csr_debug_get(unsigned int dev_id,
			   union insy_rpy_csr_debug_u *value);
int insy_rpy_csr_debug_set(unsigned int dev_id,
			   union insy_rpy_csr_debug_u *value);
int insy_aes_gcm_counter_incr_csr_debug_get(unsigned int dev_id,
					    union
					    insy_aes_gcm_counter_incr_csr_debug_u
					    *value);
int insy_aes_gcm_counter_incr_csr_debug_set(unsigned int dev_id,
					    union
					    insy_aes_gcm_counter_incr_csr_debug_u
					    *value);
int insy_gcm_mult_data_cnt_csr_debug_get(unsigned int dev_id,
					 union
					 insy_gcm_mult_data_cnt_csr_debug_u
					 *value);
int insy_gcm_mult_data_cnt_csr_debug_set(unsigned int dev_id,
					 union
					 insy_gcm_mult_data_cnt_csr_debug_u
					 *value);
int insy_gcm_mult_lena_lsb_csr_debug_get(unsigned int dev_id,
					 union
					 insy_gcm_mult_lena_lsb_csr_debug_u
					 *value);
int insy_gcm_mult_lena_lsb_csr_debug_set(unsigned int dev_id,
					 union
					 insy_gcm_mult_lena_lsb_csr_debug_u
					 *value);
int insy_gcm_mult_lena_msb_csr_debug_get(unsigned int dev_id,
					 union
					 insy_gcm_mult_lena_msb_csr_debug_u
					 *value);
int insy_gcm_mult_lena_msb_csr_debug_set(unsigned int dev_id,
					 union
					 insy_gcm_mult_lena_msb_csr_debug_u
					 *value);
int insy_gcm_mult_lenc_lsb_csr_debug_get(unsigned int dev_id,
					 union
					 insy_gcm_mult_lenc_lsb_csr_debug_u
					 *value);
int insy_gcm_mult_lenc_lsb_csr_debug_set(unsigned int dev_id,
					 union
					 insy_gcm_mult_lenc_lsb_csr_debug_u
					 *value);
int insy_gcm_mult_lenc_msb_csr_debug_get(unsigned int dev_id,
					 union
					 insy_gcm_mult_lenc_msb_csr_debug_u
					 *value);
int insy_gcm_mult_lenc_msb_csr_debug_set(unsigned int dev_id,
					 union
					 insy_gcm_mult_lenc_msb_csr_debug_u
					 *value);
int igsy_csr_busy_signal_get(unsigned int dev_id,
			     union igsy_csr_busy_signal_u *value);
int igsy_csr_busy_signal_set(unsigned int dev_id,
			     union igsy_csr_busy_signal_u *value);
int insy_sctrl_drop_en_get(unsigned int dev_id,
			   union insy_sctrl_drop_en_u *value);
int insy_sctrl_drop_en_set(unsigned int dev_id,
			   union insy_sctrl_drop_en_u *value);
int insy_ectrl_en_get(unsigned int dev_id, union insy_ectrl_en_u *value);
int insy_ectrl_en_set(unsigned int dev_id, union insy_ectrl_en_u *value);
int insy_emac_regs_get(unsigned int dev_id, union insy_emac_regs_u *value);
int insy_emac_regs_set(unsigned int dev_id, union insy_emac_regs_u *value);
int insy_sci_default_entry_lsb_get(unsigned int dev_id,
				   union insy_sci_default_entry_lsb_u *value);
int insy_sci_default_entry_lsb_set(unsigned int dev_id,
				   union insy_sci_default_entry_lsb_u *value);
int insy_sci_default_entry_msb_get(unsigned int dev_id,
				   union insy_sci_default_entry_msb_u *value);
int insy_sci_default_entry_msb_set(unsigned int dev_id,
				   union insy_sci_default_entry_msb_u *value);
int igsy_int_get(unsigned int dev_id, union igsy_int_u *value);
int igsy_int_set(unsigned int dev_id, union igsy_int_u *value);
int igsy_int_en_get(unsigned int dev_id, union igsy_int_en_u *value);
int igsy_int_en_set(unsigned int dev_id, union igsy_int_en_u *value);
int icv_err_reg_get(unsigned int dev_id, union icv_err_reg_u *value);
int icv_err_reg_set(unsigned int dev_id, union icv_err_reg_u *value);
int rpy_err_reg_get(unsigned int dev_id, union rpy_err_reg_u *value);
int rpy_err_reg_set(unsigned int dev_id, union rpy_err_reg_u *value);
int igsy_sa_exp_get(unsigned int dev_id, union igsy_sa_exp_u *value);
int igsy_sa_exp_set(unsigned int dev_id, union igsy_sa_exp_u *value);
int igsy_sa_thr_get(unsigned int dev_id, union igsy_sa_thr_u *value);
int igsy_sa_thr_set(unsigned int dev_id, union igsy_sa_thr_u *value);
int igecc_err_reg_get(unsigned int dev_id, union igecc_err_reg_u *value);
int igecc_err_reg_set(unsigned int dev_id, union igecc_err_reg_u *value);
int igprc_ecc_err1_addr_get(unsigned int dev_id,
			    union igprc_ecc_err1_addr_u *value);
int igprc_ecc_err1_addr_set(unsigned int dev_id,
			    union igprc_ecc_err1_addr_u *value);
int igprc_ecc_err2_addr_get(unsigned int dev_id,
			    union igprc_ecc_err2_addr_u *value);
int igprc_ecc_err2_addr_set(unsigned int dev_id,
			    union igprc_ecc_err2_addr_u *value);
int iglkup_ctlf_ecc_err_addr_get(unsigned int dev_id,
				 union iglkup_ctlf_ecc_err_addr_u *value);
int iglkup_ctlf_ecc_err_addr_set(unsigned int dev_id,
				 union iglkup_ctlf_ecc_err_addr_u *value);
int pfmt_ecc_err_addr_get(unsigned int dev_id,
			  union pfmt_ecc_err_addr_u *value);
int pfmt_ecc_err_addr_set(unsigned int dev_id,
			  union pfmt_ecc_err_addr_u *value);
int irpy_sc_sa_ecc_err_addr_get(unsigned int dev_id,
				union irpy_sc_sa_ecc_err_addr_u *value);
int irpy_sc_sa_ecc_err_addr_set(unsigned int dev_id,
				union irpy_sc_sa_ecc_err_addr_u *value);
int igpoc_ctlf_ecc_err_addr_get(unsigned int dev_id,
				union igpoc_ctlf_ecc_err_addr_u *value);
int igpoc_ctlf_ecc_err_addr_set(unsigned int dev_id,
				union igpoc_ctlf_ecc_err_addr_u *value);
int igpoc_ecc_err1_addr_get(unsigned int dev_id,
			    union igpoc_ecc_err1_addr_u *value);
int igpoc_ecc_err1_addr_set(unsigned int dev_id,
			    union igpoc_ecc_err1_addr_u *value);
int igpoc_ecc_err2_addr_get(unsigned int dev_id,
			    union igpoc_ecc_err2_addr_u *value);
int igpoc_ecc_err2_addr_set(unsigned int dev_id,
			    union igpoc_ecc_err2_addr_u *value);
int igsy_smib_ecc_err_addr_get(unsigned int dev_id,
			       union igsy_smib_ecc_err_addr_u *value);
int igsy_smib_ecc_err_addr_set(unsigned int dev_id,
			       union igsy_smib_ecc_err_addr_u *value);
int ig_table_cmd_get(unsigned int dev_id, union ig_table_cmd_u *value);
int ig_table_cmd_set(unsigned int dev_id, union ig_table_cmd_u *value);
int ig_table_data_get(unsigned int dev_id, union ig_table_data_u *value);
int ig_table_data_set(unsigned int dev_id, union ig_table_data_u *value);
int ig_ctl_filt_table_set(unsigned int dev_id,
			  unsigned int index, unsigned int *pentry);
int ig_ctl_filt_table_get(unsigned int dev_id,
			  unsigned int index, unsigned int *pentry);

int ig_prc_lut_table_set(unsigned int dev_id,
			 unsigned int index, unsigned int *pentry);
int ig_prc_lut_table_get(unsigned int dev_id,
			 unsigned int index, unsigned int *pentry);

int ig_sc_table_set(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry);
int ig_sc_table_get(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry);

int ig_sa_table_set(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry);
int ig_sa_table_get(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry);

int ig_sak_table_set(unsigned int dev_id,
		     unsigned int index, unsigned int *pentry);
int ig_sak_table_get(unsigned int dev_id,
		     unsigned int index, unsigned int *pentry);

int ig_poc_lut_table_set(unsigned int dev_id,
			 unsigned int index, unsigned int *pentry);
int ig_poc_lut_table_get(unsigned int dev_id,
			 unsigned int index, unsigned int *pentry);

int ig_smib_table_sc_sa_get(unsigned int dev_id,
			    unsigned int index, unsigned int *pentry);

int ig_smib_table_common_get(unsigned int dev_id, unsigned int *pentry);

int ingress_reg_get(unsigned int dev_id,
		    unsigned int reg_addr, unsigned int *pvalue);
int ingress_reg_set(unsigned int dev_id,
		    unsigned int reg_addr, unsigned int value);

int egsy_l2sec_version_get(unsigned int dev_id,
			   union egsy_l2sec_version_u *value);
int egsy_l2sec_version_set(unsigned int dev_id,
			   union egsy_l2sec_version_u *value);
int egsy_l2sec_control_get(unsigned int dev_id,
			   union egsy_l2sec_control_u *value);
int egsy_l2sec_control_set(unsigned int dev_id,
			   union egsy_l2sec_control_u *value);
int egsy_prescale_get(unsigned int dev_id, union egsy_prescale_u *value);
int egsy_prescale_set(unsigned int dev_id, union egsy_prescale_u *value);
int csr_egsy_vlan_tpid0_get(unsigned int dev_id,
			    union csr_egsy_vlan_tpid0_u *value);
int csr_egsy_vlan_tpid0_set(unsigned int dev_id,
			    union csr_egsy_vlan_tpid0_u *value);
int csr_egsy_vlan_tpid1_get(unsigned int dev_id,
			    union csr_egsy_vlan_tpid1_u *value);
int csr_egsy_vlan_tpid1_set(unsigned int dev_id,
			    union csr_egsy_vlan_tpid1_u *value);
int csr_egsy_vlan_cp_tag_get(unsigned int dev_id,
			     union csr_egsy_vlan_cp_tag_u *value);
int csr_egsy_vlan_cp_tag_set(unsigned int dev_id,
			     union csr_egsy_vlan_cp_tag_u *value);
int csr_egsy_pn_thr_get(unsigned int dev_id, union csr_egsy_pn_thr_u *value);
int csr_egsy_pn_thr_set(unsigned int dev_id, union csr_egsy_pn_thr_u *value);
int csr_egsy_mtu_get(unsigned int dev_id, union csr_egsy_mtu_u *value);
int csr_egsy_mtu_set(unsigned int dev_id, union csr_egsy_mtu_u *value);
int csr_egsy_gcm_datain0_get(unsigned int dev_id,
			     union csr_egsy_gcm_datain0_u *value);
int csr_egsy_gcm_datain0_set(unsigned int dev_id,
			     union csr_egsy_gcm_datain0_u *value);
int csr_egsy_gcm_datain1_get(unsigned int dev_id,
			     union csr_egsy_gcm_datain1_u *value);
int csr_egsy_gcm_datain1_set(unsigned int dev_id,
			     union csr_egsy_gcm_datain1_u *value);
int csr_egsy_gcm_datain2_get(unsigned int dev_id,
			     union csr_egsy_gcm_datain2_u *value);
int csr_egsy_gcm_datain2_set(unsigned int dev_id,
			     union csr_egsy_gcm_datain2_u *value);
int csr_egsy_gcm_datain3_get(unsigned int dev_id,
			     union csr_egsy_gcm_datain3_u *value);
int csr_egsy_gcm_datain3_set(unsigned int dev_id,
			     union csr_egsy_gcm_datain3_u *value);
int csr_egsy_gcm_key0_get(unsigned int dev_id,
			  union csr_egsy_gcm_key0_u *value);
int csr_egsy_gcm_key0_set(unsigned int dev_id,
			  union csr_egsy_gcm_key0_u *value);
int csr_egsy_gcm_key1_get(unsigned int dev_id,
			  union csr_egsy_gcm_key1_u *value);
int csr_egsy_gcm_key1_set(unsigned int dev_id,
			  union csr_egsy_gcm_key1_u *value);
int csr_egsy_gcm_key2_get(unsigned int dev_id,
			  union csr_egsy_gcm_key2_u *value);
int csr_egsy_gcm_key2_set(unsigned int dev_id,
			  union csr_egsy_gcm_key2_u *value);
int csr_egsy_gcm_key3_get(unsigned int dev_id,
			  union csr_egsy_gcm_key3_u *value);
int csr_egsy_gcm_key3_set(unsigned int dev_id,
			  union csr_egsy_gcm_key3_u *value);
int csr_egsy_gcm_iv0_get(unsigned int dev_id, union csr_egsy_gcm_iv0_u *value);
int csr_egsy_gcm_iv0_set(unsigned int dev_id, union csr_egsy_gcm_iv0_u *value);
int csr_egsy_gcm_iv1_get(unsigned int dev_id, union csr_egsy_gcm_iv1_u *value);
int csr_egsy_gcm_iv1_set(unsigned int dev_id, union csr_egsy_gcm_iv1_u *value);
int csr_egsy_gcm_iv2_get(unsigned int dev_id, union csr_egsy_gcm_iv2_u *value);
int csr_egsy_gcm_iv2_set(unsigned int dev_id, union csr_egsy_gcm_iv2_u *value);
int csr_egsy_gcm_iv3_get(unsigned int dev_id, union csr_egsy_gcm_iv3_u *value);
int csr_egsy_gcm_iv3_set(unsigned int dev_id, union csr_egsy_gcm_iv3_u *value);
int csr_egsy_gcm_hashin0_get(unsigned int dev_id,
			     union csr_egsy_gcm_hashin0_u *value);
int csr_egsy_gcm_hashin0_set(unsigned int dev_id,
			     union csr_egsy_gcm_hashin0_u *value);
int csr_egsy_gcm_hashin1_get(unsigned int dev_id,
			     union csr_egsy_gcm_hashin1_u *value);
int csr_egsy_gcm_hashin1_set(unsigned int dev_id,
			     union csr_egsy_gcm_hashin1_u *value);
int csr_egsy_gcm_hashin2_get(unsigned int dev_id,
			     union csr_egsy_gcm_hashin2_u *value);
int csr_egsy_gcm_hashin2_set(unsigned int dev_id,
			     union csr_egsy_gcm_hashin2_u *value);
int csr_egsy_gcm_hashin3_get(unsigned int dev_id,
			     union csr_egsy_gcm_hashin3_u *value);
int csr_egsy_gcm_hashin3_set(unsigned int dev_id,
			     union csr_egsy_gcm_hashin3_u *value);
int egsy_gcm_csr_dataout0_get(unsigned int dev_id,
			      union egsy_gcm_csr_dataout0_u *value);
int egsy_gcm_csr_dataout0_set(unsigned int dev_id,
			      union egsy_gcm_csr_dataout0_u *value);
int egsygcm_csr_dataout1_get(unsigned int dev_id,
			     union egsygcm_csr_dataout1_u *value);
int egsygcm_csr_dataout1_set(unsigned int dev_id,
			     union egsygcm_csr_dataout1_u *value);
int egsy_gcm_csr_dataout2_get(unsigned int dev_id,
			      union egsy_gcm_csr_dataout2_u *value);
int egsy_gcm_csr_dataout2_set(unsigned int dev_id,
			      union egsy_gcm_csr_dataout2_u *value);
int egsy_gcm_csr_dataout3_get(unsigned int dev_id,
			      union egsy_gcm_csr_dataout3_u *value);
int egsy_gcm_csr_dataout3_set(unsigned int dev_id,
			      union egsy_gcm_csr_dataout3_u *value);
int egsy_gcm_csr_hashout0_get(unsigned int dev_id,
			      union egsy_gcm_csr_hashout0_u *value);
int egsy_gcm_csr_hashout0_set(unsigned int dev_id,
			      union egsy_gcm_csr_hashout0_u *value);
int egsy_gcm_csr_hashout1_get(unsigned int dev_id,
			      union egsy_gcm_csr_hashout1_u *value);
int egsy_gcm_csr_hashout1_set(unsigned int dev_id,
			      union egsy_gcm_csr_hashout1_u *value);
int egsy_gcm_csr_hashout2_get(unsigned int dev_id,
			      union egsy_gcm_csr_hashout2_u *value);
int egsy_gcm_csr_hashout2_set(unsigned int dev_id,
			      union egsy_gcm_csr_hashout2_u *value);
int egsy_gcm_csr_hashout3_get(unsigned int dev_id,
			      union egsy_gcm_csr_hashout3_u *value);
int egsy_gcm_csr_hashout3_set(unsigned int dev_id,
			      union egsy_gcm_csr_hashout3_u *value);
int egsy_egebuf_csr_debug_get(unsigned int dev_id,
			      union egsy_egebuf_csr_debug_u *value);
int egsy_egebuf_csr_debug_set(unsigned int dev_id,
			      union egsy_egebuf_csr_debug_u *value);
int egsy_pfmt_csr_debug_get(unsigned int dev_id,
			    union egsy_pfmt_csr_debug_u *value);
int egsy_pfmt_csr_debug_set(unsigned int dev_id,
			    union egsy_pfmt_csr_debug_u *value);
int egsy_gcm_mult_lena_lsb_csr_debug_get(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lena_lsb_csr_debug_u
					 *value);
int egsy_gcm_mult_lena_lsb_csr_debug_set(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lena_lsb_csr_debug_u
					 *value);
int egsy_gcm_mult_lena_msb_csr_debug_get(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lena_msb_csr_debug_u
					 *value);
int egsy_gcm_mult_lena_msb_csr_debug_set(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lena_msb_csr_debug_u
					 *value);
int egsy_gcm_mult_lenc_lsb_csr_debug_get(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lenc_lsb_csr_debug_u
					 *value);
int egsy_gcm_mult_lenc_lsb_csr_debug_set(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lenc_lsb_csr_debug_u
					 *value);
int egsy_gcm_mult_lenc_msb_csr_debug_get(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lenc_msb_csr_debug_u
					 *value);
int egsy_gcm_mult_lenc_msb_csr_debug_set(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lenc_msb_csr_debug_u
					 *value);
int egsy_gcm_mult_data_cnt_csr_debug_get(unsigned int dev_id,
					 union
					 egsy_gcm_mult_data_cnt_csr_debug_u
					 *value);
int egsy_gcm_mult_data_cnt_csr_debug_set(unsigned int dev_id,
					 union
					 egsy_gcm_mult_data_cnt_csr_debug_u
					 *value);
int egsy_aes_gcm_counter_incr_csr_debug_get(unsigned int dev_id,
					    union
					    egsy_aes_gcm_counter_incr_csr_debug_u
					    *value);
int egsy_aes_gcm_counter_incr_csr_debug_set(unsigned int dev_id,
					    union
					    egsy_aes_gcm_counter_incr_csr_debug_u
					    *value);
int egsy_csr_busy_signal_get(unsigned int dev_id,
			     union egsy_csr_busy_signal_u *value);
int egsy_csr_busy_signal_set(unsigned int dev_id,
			     union egsy_csr_busy_signal_u *value);
int egsy_macsec_spare_reg1_get(unsigned int dev_id,
			       union egsy_macsec_spare_reg1_u *value);
int egsy_macsec_spare_reg1_set(unsigned int dev_id,
			       union egsy_macsec_spare_reg1_u *value);
int egsy_sctrl_drop_en_get(unsigned int dev_id,
			   union egsy_sctrl_drop_en_u *value);
int egsy_sctrl_drop_en_set(unsigned int dev_id,
			   union egsy_sctrl_drop_en_u *value);
int egsy_ectrl_enable_get(unsigned int dev_id,
			  union egsy_ectrl_enable_u *value);
int egsy_ectrl_enable_set(unsigned int dev_id,
			  union egsy_ectrl_enable_u *value);
int egsy_emac_regs_get(unsigned int dev_id, union egsy_emac_regs_u *value);
int egsy_emac_regs_set(unsigned int dev_id, union egsy_emac_regs_u *value);
int egsy_int_get(unsigned int dev_id, union egsy_int_u *value);
int egsy_int_set(unsigned int dev_id, union egsy_int_u *value);
int egsy_int_en_get(unsigned int dev_id, union egsy_int_en_u *value);
int egsy_int_en_set(unsigned int dev_id, union egsy_int_en_u *value);
int egsy_sa_exp_get(unsigned int dev_id, union egsy_sa_exp_u *value);
int egsy_sa_exp_set(unsigned int dev_id, union egsy_sa_exp_u *value);
int egsy_sa_thr_get(unsigned int dev_id, union egsy_sa_thr_u *value);
int egsy_sa_thr_set(unsigned int dev_id, union egsy_sa_thr_u *value);
int egecc_err_reg_get(unsigned int dev_id, union egecc_err_reg_u *value);
int egecc_err_reg_set(unsigned int dev_id, union egecc_err_reg_u *value);
int egprc_ecc_err1_addr_get(unsigned int dev_id,
			    union egprc_ecc_err1_addr_u *value);
int egprc_ecc_err1_addr_set(unsigned int dev_id,
			    union egprc_ecc_err1_addr_u *value);
int egprc_ecc_err2_addr_get(unsigned int dev_id,
			    union egprc_ecc_err2_addr_u *value);
int egprc_ecc_err2_addr_set(unsigned int dev_id,
			    union egprc_ecc_err2_addr_u *value);
int eglkup_ctlf_ecc_err_addr_get(unsigned int dev_id,
				 union eglkup_ctlf_ecc_err_addr_u *value);
int eglkup_ctlf_ecc_err_addr_set(unsigned int dev_id,
				 union eglkup_ctlf_ecc_err_addr_u *value);
int pfmt_sc_sa_ecc_err_addr_get(unsigned int dev_id,
				union pfmt_sc_sa_ecc_err_addr_u *value);
int pfmt_sc_sa_ecc_err_addr_set(unsigned int dev_id,
				union pfmt_sc_sa_ecc_err_addr_u *value);
int egsy_smib_ecc_err_addr_get(unsigned int dev_id,
			       union egsy_smib_ecc_err_addr_u *value);
int egsy_smib_ecc_err_addr_set(unsigned int dev_id,
			       union egsy_smib_ecc_err_addr_u *value);
int egsy_enable_ecc_get(unsigned int dev_id, union egsy_enable_ecc_u *value);
int egsy_enable_ecc_set(unsigned int dev_id, union egsy_enable_ecc_u *value);
int eg_table_cmd_get(unsigned int dev_id, union eg_table_cmd_u *value);
int eg_table_cmd_set(unsigned int dev_id, union eg_table_cmd_u *value);
int eg_table_data_get(unsigned int dev_id, union eg_table_data_u *value);
int eg_table_data_set(unsigned int dev_id, union eg_table_data_u *value);
int eg_ctl_filt_table_set(unsigned int dev_id,
			  unsigned int index, unsigned int *pentry);
int eg_ctl_filt_table_get(unsigned int dev_id,
			  unsigned int index, unsigned int *pentry);

int eg_class_lut_table_set(unsigned int dev_id,
			   unsigned int index, unsigned int *pentry);
int eg_class_lut_table_get(unsigned int dev_id,
			   unsigned int index, unsigned int *pentry);

int eg_sc_table_set(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry);
int eg_sc_table_get(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry);

int eg_sa_table_set(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry);
int eg_sa_table_get(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry);

int eg_sak_table_set(unsigned int dev_id,
		     unsigned int index, unsigned int *pentry);
int eg_sak_table_get(unsigned int dev_id,
		     unsigned int index, unsigned int *pentry);

int eg_smib_table_sc_sa_get(unsigned int dev_id,
			    unsigned int index, unsigned int *pentry);

int eg_smib_table_common_get(unsigned int dev_id, unsigned int *pentry);

int egress_reg_get(unsigned int dev_id,
		   unsigned int reg_addr, unsigned int *pvalue);
int egress_reg_set(unsigned int dev_id,
		   unsigned int reg_addr, unsigned int value);

int emac1_rev_get(unsigned int dev_id, union emac1_rev_u *value);
int emac1_rev_set(unsigned int dev_id, union emac1_rev_u *value);
int emac1_scratch_get(unsigned int dev_id, union emac1_scratch_u *value);
int emac1_scratch_set(unsigned int dev_id, union emac1_scratch_u *value);
int emac1_command_config_get(unsigned int dev_id,
			     union emac1_command_config_u *value);
int emac1_command_config_set(unsigned int dev_id,
			     union emac1_command_config_u *value);
int emac1_mac_0_get(unsigned int dev_id, union emac1_mac_0_u *value);
int emac1_mac_0_set(unsigned int dev_id, union emac1_mac_0_u *value);
int emac1_mac_1_get(unsigned int dev_id, union emac1_mac_1_u *value);
int emac1_mac_1_set(unsigned int dev_id, union emac1_mac_1_u *value);
int emac1_frm_length_get(unsigned int dev_id, union emac1_frm_length_u *value);
int emac1_frm_length_set(unsigned int dev_id, union emac1_frm_length_u *value);
int emac1_pause_quant_get(unsigned int dev_id,
			  union emac1_pause_quant_u *value);
int emac1_pause_quant_set(unsigned int dev_id,
			  union emac1_pause_quant_u *value);
int emac1_rx_section_empty_get(unsigned int dev_id,
			       union emac1_rx_section_empty_u *value);
int emac1_rx_section_empty_set(unsigned int dev_id,
			       union emac1_rx_section_empty_u *value);
int emac1_rx_section_full_get(unsigned int dev_id,
			      union emac1_rx_section_full_u *value);
int emac1_rx_section_full_set(unsigned int dev_id,
			      union emac1_rx_section_full_u *value);
int emac1_tx_section_empty_get(unsigned int dev_id,
			       union emac1_tx_section_empty_u *value);
int emac1_tx_section_empty_set(unsigned int dev_id,
			       union emac1_tx_section_empty_u *value);
int emac1_tx_section_full_get(unsigned int dev_id,
			      union emac1_tx_section_full_u *value);
int emac1_tx_section_full_set(unsigned int dev_id,
			      union emac1_tx_section_full_u *value);
int emac1_rx_almost_empty_get(unsigned int dev_id,
			      union emac1_rx_almost_empty_u *value);
int emac1_rx_almost_empty_set(unsigned int dev_id,
			      union emac1_rx_almost_empty_u *value);
int emac1_rx_almost_full_get(unsigned int dev_id,
			     union emac1_rx_almost_full_u *value);
int emac1_rx_almost_full_set(unsigned int dev_id,
			     union emac1_rx_almost_full_u *value);
int emac1_tx_almost_empty_get(unsigned int dev_id,
			      union emac1_tx_almost_empty_u *value);
int emac1_tx_almost_empty_set(unsigned int dev_id,
			      union emac1_tx_almost_empty_u *value);
int emac1_tx_almost_full_get(unsigned int dev_id,
			     union emac1_tx_almost_full_u *value);
int emac1_tx_almost_full_set(unsigned int dev_id,
			     union emac1_tx_almost_full_u *value);
int emac1_mdio_addr0_get(unsigned int dev_id, union emac1_mdio_addr0_u *value);
int emac1_mdio_addr0_set(unsigned int dev_id, union emac1_mdio_addr0_u *value);
int emac1_mdio_addr1_get(unsigned int dev_id, union emac1_mdio_addr1_u *value);
int emac1_mdio_addr1_set(unsigned int dev_id, union emac1_mdio_addr1_u *value);
int emac1_reg_status_get(unsigned int dev_id, union emac1_reg_status_u *value);
int emac1_reg_status_set(unsigned int dev_id, union emac1_reg_status_u *value);
int emac1_tx_ipg_length_get(unsigned int dev_id,
			    union emac1_tx_ipg_length_u *value);
int emac1_tx_ipg_length_set(unsigned int dev_id,
			    union emac1_tx_ipg_length_u *value);
int emac1_amacid_get(unsigned int dev_id, union emac1_amacid_u *value);
int emac1_amacid_set(unsigned int dev_id, union emac1_amacid_u *value);
int emac1_aframestransmittedok_get(unsigned int dev_id,
				   union emac1_aframestransmittedok_u *value);
int emac1_aframestransmittedok_set(unsigned int dev_id,
				   union emac1_aframestransmittedok_u *value);
int emac1_aframesreceivedok_get(unsigned int dev_id,
				union emac1_aframesreceivedok_u *value);
int emac1_aframesreceivedok_set(unsigned int dev_id,
				union emac1_aframesreceivedok_u *value);
int emac1_aframechecksequenceerrors_get(unsigned int dev_id,
					union emac1_aframechecksequenceerrors_u
					*value);
int emac1_aframechecksequenceerrors_set(unsigned int dev_id,
					union emac1_aframechecksequenceerrors_u
					*value);
int emac1_aalignmenterrors_get(unsigned int dev_id,
			       union emac1_aalignmenterrors_u *value);
int emac1_aalignmenterrors_set(unsigned int dev_id,
			       union emac1_aalignmenterrors_u *value);
int emac1_aoctetstransmittedok_get(unsigned int dev_id,
				   union emac1_aoctetstransmittedok_u *value);
int emac1_aoctetstransmittedok_set(unsigned int dev_id,
				   union emac1_aoctetstransmittedok_u *value);
int emac1_aoctetsreceivedok_get(unsigned int dev_id,
				union emac1_aoctetsreceivedok_u *value);
int emac1_aoctetsreceivedok_set(unsigned int dev_id,
				union emac1_aoctetsreceivedok_u *value);
int emac1_atxpausemacctrlframes_get(unsigned int dev_id,
				    union emac1_atxpausemacctrlframes_u *value);
int emac1_atxpausemacctrlframes_set(unsigned int dev_id,
				    union emac1_atxpausemacctrlframes_u *value);
int emac1_arxpausemacctrlframes_get(unsigned int dev_id,
				    union emac1_arxpausemacctrlframes_u *value);
int emac1_arxpausemacctrlframes_set(unsigned int dev_id,
				    union emac1_arxpausemacctrlframes_u *value);
int emac1_ifinerrors_get(unsigned int dev_id, union emac1_ifinerrors_u *value);
int emac1_ifinerrors_set(unsigned int dev_id, union emac1_ifinerrors_u *value);
int emac1_ifouterrors_get(unsigned int dev_id,
			  union emac1_ifouterrors_u *value);
int emac1_ifouterrors_set(unsigned int dev_id,
			  union emac1_ifouterrors_u *value);
int emac1_ifinucastpkts_get(unsigned int dev_id,
			    union emac1_ifinucastpkts_u *value);
int emac1_ifinucastpkts_set(unsigned int dev_id,
			    union emac1_ifinucastpkts_u *value);
int emac1_ifinmulticastpkts_get(unsigned int dev_id,
				union emac1_ifinmulticastpkts_u *value);
int emac1_ifinmulticastpkts_set(unsigned int dev_id,
				union emac1_ifinmulticastpkts_u *value);
int emac1_ifinbroadcastpkts_get(unsigned int dev_id,
				union emac1_ifinbroadcastpkts_u *value);
int emac1_ifinbroadcastpkts_set(unsigned int dev_id,
				union emac1_ifinbroadcastpkts_u *value);
int emac1_ifoutdiscards_get(unsigned int dev_id,
			    union emac1_ifoutdiscards_u *value);
int emac1_ifoutdiscards_set(unsigned int dev_id,
			    union emac1_ifoutdiscards_u *value);
int emac1_ifoutucastpkts_get(unsigned int dev_id,
			     union emac1_ifoutucastpkts_u *value);
int emac1_ifoutucastpkts_set(unsigned int dev_id,
			     union emac1_ifoutucastpkts_u *value);
int emac1_ifoutmulticastpkts_get(unsigned int dev_id,
				 union emac1_ifoutmulticastpkts_u *value);
int emac1_ifoutmulticastpkts_set(unsigned int dev_id,
				 union emac1_ifoutmulticastpkts_u *value);
int emac1_ifoutbroadcastpkts_get(unsigned int dev_id,
				 union emac1_ifoutbroadcastpkts_u *value);
int emac1_ifoutbroadcastpkts_set(unsigned int dev_id,
				 union emac1_ifoutbroadcastpkts_u *value);
int emac1_etherstatsdropevents_get(unsigned int dev_id,
				   union emac1_etherstatsdropevents_u *value);
int emac1_etherstatsdropevents_set(unsigned int dev_id,
				   union emac1_etherstatsdropevents_u *value);
int emac1_etherstatsoctets_get(unsigned int dev_id,
			       union emac1_etherstatsoctets_u *value);
int emac1_etherstatsoctets_set(unsigned int dev_id,
			       union emac1_etherstatsoctets_u *value);
int emac1_etherstatspkts_get(unsigned int dev_id,
			     union emac1_etherstatspkts_u *value);
int emac1_etherstatspkts_set(unsigned int dev_id,
			     union emac1_etherstatspkts_u *value);
int emac1_etherstatsundersizepkts_get(unsigned int dev_id,
				      union emac1_etherstatsundersizepkts_u
				      *value);
int emac1_etherstatsundersizepkts_set(unsigned int dev_id,
				      union emac1_etherstatsundersizepkts_u
				      *value);
int emac1_etherstatsoversizepkts_get(unsigned int dev_id,
				     union emac1_etherstatsoversizepkts_u
				     *value);
int emac1_etherstatsoversizepkts_set(unsigned int dev_id,
				     union emac1_etherstatsoversizepkts_u
				     *value);
int emac1_etherstatspkts64octets_get(unsigned int dev_id,
				     union emac1_etherstatspkts64octets_u
				     *value);
int emac1_etherstatspkts64octets_set(unsigned int dev_id,
				     union emac1_etherstatspkts64octets_u
				     *value);
int emac1_etherstatspkts65to127octets_get(unsigned int dev_id,
					  union
					  emac1_etherstatspkts65to127octets_u
					  *value);
int emac1_etherstatspkts65to127octets_set(unsigned int dev_id,
					  union
					  emac1_etherstatspkts65to127octets_u
					  *value);
int emac1_etherstatspkts128to255octets_get(unsigned int dev_id,
					   union
					   emac1_etherstatspkts128to255octets_u
					   *value);
int emac1_etherstatspkts128to255octets_set(unsigned int dev_id,
					   union
					   emac1_etherstatspkts128to255octets_u
					   *value);
int emac1_etherstatspkts256to511octets_get(unsigned int dev_id,
					   union
					   emac1_etherstatspkts256to511octets_u
					   *value);
int emac1_etherstatspkts256to511octets_set(unsigned int dev_id,
					   union
					   emac1_etherstatspkts256to511octets_u
					   *value);
int emac1_etherstatspkts512to1023octets_get(unsigned int dev_id,
					    union
					    emac1_etherstatspkts512to1023octets_u
					    *value);
int emac1_etherstatspkts512to1023octets_set(unsigned int dev_id,
					    union
					    emac1_etherstatspkts512to1023octets_u
					    *value);
int emac1_etherstatspkts1024to1518octets_get(unsigned int dev_id,
					     union
					     emac1_etherstatspkts1024to1518octets_u
					     *value);
int emac1_etherstatspkts1024to1518octets_set(unsigned int dev_id,
					     union
					     emac1_etherstatspkts1024to1518octets_u
					     *value);
int emac1_etherstatspkts1519toxoctets_get(unsigned int dev_id,
					  union
					  emac1_etherstatspkts1519toxoctets_u
					  *value);
int emac1_etherstatspkts1519toxoctets_set(unsigned int dev_id,
					  union
					  emac1_etherstatspkts1519toxoctets_u
					  *value);
int emac1_etherstatsjabbers_get(unsigned int dev_id,
				union emac1_etherstatsjabbers_u *value);
int emac1_etherstatsjabbers_set(unsigned int dev_id,
				union emac1_etherstatsjabbers_u *value);
int emac1_etherstatsfragments_get(unsigned int dev_id,
				  union emac1_etherstatsfragments_u *value);
int emac1_etherstatsfragments_set(unsigned int dev_id,
				  union emac1_etherstatsfragments_u *value);
int emac2_rev_get(unsigned int dev_id, union emac2_rev_u *value);
int emac2_rev_set(unsigned int dev_id, union emac2_rev_u *value);
int emac2_scratch_get(unsigned int dev_id, union emac2_scratch_u *value);
int emac2_scratch_set(unsigned int dev_id, union emac2_scratch_u *value);
int emac2_command_config_get(unsigned int dev_id,
			     union emac2_command_config_u *value);
int emac2_command_config_set(unsigned int dev_id,
			     union emac2_command_config_u *value);
int emac2_mac_0_get(unsigned int dev_id, union emac2_mac_0_u *value);
int emac2_mac_0_set(unsigned int dev_id, union emac2_mac_0_u *value);
int emac2_mac_1_get(unsigned int dev_id, union emac2_mac_1_u *value);
int emac2_mac_1_set(unsigned int dev_id, union emac2_mac_1_u *value);
int emac2_frm_length_get(unsigned int dev_id, union emac2_frm_length_u *value);
int emac2_frm_length_set(unsigned int dev_id, union emac2_frm_length_u *value);
int emac2_pause_quant_get(unsigned int dev_id,
			  union emac2_pause_quant_u *value);
int emac2_pause_quant_set(unsigned int dev_id,
			  union emac2_pause_quant_u *value);
int emac2_rx_section_empty_get(unsigned int dev_id,
			       union emac2_rx_section_empty_u *value);
int emac2_rx_section_empty_set(unsigned int dev_id,
			       union emac2_rx_section_empty_u *value);
int emac2_rx_section_full_get(unsigned int dev_id,
			      union emac2_rx_section_full_u *value);
int emac2_rx_section_full_set(unsigned int dev_id,
			      union emac2_rx_section_full_u *value);
int emac2_tx_section_empty_get(unsigned int dev_id,
			       union emac2_tx_section_empty_u *value);
int emac2_tx_section_empty_set(unsigned int dev_id,
			       union emac2_tx_section_empty_u *value);
int emac2_tx_section_full_get(unsigned int dev_id,
			      union emac2_tx_section_full_u *value);
int emac2_tx_section_full_set(unsigned int dev_id,
			      union emac2_tx_section_full_u *value);
int emac2_rx_almost_empty_get(unsigned int dev_id,
			      union emac2_rx_almost_empty_u *value);
int emac2_rx_almost_empty_set(unsigned int dev_id,
			      union emac2_rx_almost_empty_u *value);
int emac2_rx_almost_full_get(unsigned int dev_id,
			     union emac2_rx_almost_full_u *value);
int emac2_rx_almost_full_set(unsigned int dev_id,
			     union emac2_rx_almost_full_u *value);
int emac2_tx_almost_empty_get(unsigned int dev_id,
			      union emac2_tx_almost_empty_u *value);
int emac2_tx_almost_empty_set(unsigned int dev_id,
			      union emac2_tx_almost_empty_u *value);
int emac2_tx_almost_full_get(unsigned int dev_id,
			     union emac2_tx_almost_full_u *value);
int emac2_tx_almost_full_set(unsigned int dev_id,
			     union emac2_tx_almost_full_u *value);
int emac2_mdio_addr0_get(unsigned int dev_id, union emac2_mdio_addr0_u *value);
int emac2_mdio_addr0_set(unsigned int dev_id, union emac2_mdio_addr0_u *value);
int emac2_mdio_addr1_get(unsigned int dev_id, union emac2_mdio_addr1_u *value);
int emac2_mdio_addr1_set(unsigned int dev_id, union emac2_mdio_addr1_u *value);
int emac2_reg_status_get(unsigned int dev_id, union emac2_reg_status_u *value);
int emac2_reg_status_set(unsigned int dev_id, union emac2_reg_status_u *value);
int emac2_tx_ipg_length_get(unsigned int dev_id,
			    union emac2_tx_ipg_length_u *value);
int emac2_tx_ipg_length_set(unsigned int dev_id,
			    union emac2_tx_ipg_length_u *value);
int emac2_amacid_get(unsigned int dev_id, union emac2_amacid_u *value);
int emac2_amacid_set(unsigned int dev_id, union emac2_amacid_u *value);
int emac2_aframestransmittedok_get(unsigned int dev_id,
				   union emac2_aframestransmittedok_u *value);
int emac2_aframestransmittedok_set(unsigned int dev_id,
				   union emac2_aframestransmittedok_u *value);
int emac2_aframesreceivedok_get(unsigned int dev_id,
				union emac2_aframesreceivedok_u *value);
int emac2_aframesreceivedok_set(unsigned int dev_id,
				union emac2_aframesreceivedok_u *value);
int emac2_aframechecksequenceerrors_get(unsigned int dev_id,
					union emac2_aframechecksequenceerrors_u
					*value);
int emac2_aframechecksequenceerrors_set(unsigned int dev_id,
					union emac2_aframechecksequenceerrors_u
					*value);
int emac2_aalignmenterrors_get(unsigned int dev_id,
			       union emac2_aalignmenterrors_u *value);
int emac2_aalignmenterrors_set(unsigned int dev_id,
			       union emac2_aalignmenterrors_u *value);
int emac2_aoctetstransmittedok_get(unsigned int dev_id,
				   union emac2_aoctetstransmittedok_u *value);
int emac2_aoctetstransmittedok_set(unsigned int dev_id,
				   union emac2_aoctetstransmittedok_u *value);
int emac2_aoctetsreceivedok_get(unsigned int dev_id,
				union emac2_aoctetsreceivedok_u *value);
int emac2_aoctetsreceivedok_set(unsigned int dev_id,
				union emac2_aoctetsreceivedok_u *value);
int emac2_atxpausemacctrlframes_get(unsigned int dev_id,
				    union emac2_atxpausemacctrlframes_u *value);
int emac2_atxpausemacctrlframes_set(unsigned int dev_id,
				    union emac2_atxpausemacctrlframes_u *value);
int emac2_arxpausemacctrlframes_get(unsigned int dev_id,
				    union emac2_arxpausemacctrlframes_u *value);
int emac2_arxpausemacctrlframes_set(unsigned int dev_id,
				    union emac2_arxpausemacctrlframes_u *value);
int emac2_ifinerrors_get(unsigned int dev_id, union emac2_ifinerrors_u *value);
int emac2_ifinerrors_set(unsigned int dev_id, union emac2_ifinerrors_u *value);
int emac2_ifouterrors_get(unsigned int dev_id,
			  union emac2_ifouterrors_u *value);
int emac2_ifouterrors_set(unsigned int dev_id,
			  union emac2_ifouterrors_u *value);
int emac2_ifinucastpkts_get(unsigned int dev_id,
			    union emac2_ifinucastpkts_u *value);
int emac2_ifinucastpkts_set(unsigned int dev_id,
			    union emac2_ifinucastpkts_u *value);
int emac2_ifinmulticastpkts_get(unsigned int dev_id,
				union emac2_ifinmulticastpkts_u *value);
int emac2_ifinmulticastpkts_set(unsigned int dev_id,
				union emac2_ifinmulticastpkts_u *value);
int emac2_ifinbroadcastpkts_get(unsigned int dev_id,
				union emac2_ifinbroadcastpkts_u *value);
int emac2_ifinbroadcastpkts_set(unsigned int dev_id,
				union emac2_ifinbroadcastpkts_u *value);
int emac2_ifoutdiscards_get(unsigned int dev_id,
			    union emac2_ifoutdiscards_u *value);
int emac2_ifoutdiscards_set(unsigned int dev_id,
			    union emac2_ifoutdiscards_u *value);
int emac2_ifoutucastpkts_get(unsigned int dev_id,
			     union emac2_ifoutucastpkts_u *value);
int emac2_ifoutucastpkts_set(unsigned int dev_id,
			     union emac2_ifoutucastpkts_u *value);
int emac2_ifoutmulticastpkts_get(unsigned int dev_id,
				 union emac2_ifoutmulticastpkts_u *value);
int emac2_ifoutmulticastpkts_set(unsigned int dev_id,
				 union emac2_ifoutmulticastpkts_u *value);
int emac2_ifoutbroadcastpkts_get(unsigned int dev_id,
				 union emac2_ifoutbroadcastpkts_u *value);
int emac2_ifoutbroadcastpkts_set(unsigned int dev_id,
				 union emac2_ifoutbroadcastpkts_u *value);
int emac2_etherstatsdropevents_get(unsigned int dev_id,
				   union emac2_etherstatsdropevents_u *value);
int emac2_etherstatsdropevents_set(unsigned int dev_id,
				   union emac2_etherstatsdropevents_u *value);
int emac2_etherstatsoctets_get(unsigned int dev_id,
			       union emac2_etherstatsoctets_u *value);
int emac2_etherstatsoctets_set(unsigned int dev_id,
			       union emac2_etherstatsoctets_u *value);
int emac2_etherstatspkts_get(unsigned int dev_id,
			     union emac2_etherstatspkts_u *value);
int emac2_etherstatspkts_set(unsigned int dev_id,
			     union emac2_etherstatspkts_u *value);
int emac2_etherstatsundersizepkts_get(unsigned int dev_id,
				      union emac2_etherstatsundersizepkts_u
				      *value);
int emac2_etherstatsundersizepkts_set(unsigned int dev_id,
				      union emac2_etherstatsundersizepkts_u
				      *value);
int emac2_etherstatsoversizepkts_get(unsigned int dev_id,
				     union emac2_etherstatsoversizepkts_u
				     *value);
int emac2_etherstatsoversizepkts_set(unsigned int dev_id,
				     union emac2_etherstatsoversizepkts_u
				     *value);
int emac2_etherstatspkts64octets_get(unsigned int dev_id,
				     union emac2_etherstatspkts64octets_u
				     *value);
int emac2_etherstatspkts64octets_set(unsigned int dev_id,
				     union emac2_etherstatspkts64octets_u
				     *value);
int emac2_etherstatspkts65to127octets_get(unsigned int dev_id,
					  union
					  emac2_etherstatspkts65to127octets_u
					  *value);
int emac2_etherstatspkts65to127octets_set(unsigned int dev_id,
					  union
					  emac2_etherstatspkts65to127octets_u
					  *value);
int emac2_etherstatspkts128to255octets_get(unsigned int dev_id,
					   union
					   emac2_etherstatspkts128to255octets_u
					   *value);
int emac2_etherstatspkts128to255octets_set(unsigned int dev_id,
					   union
					   emac2_etherstatspkts128to255octets_u
					   *value);
int emac2_etherstatspkts256to511octets_get(unsigned int dev_id,
					   union
					   emac2_etherstatspkts256to511octets_u
					   *value);
int emac2_etherstatspkts256to511octets_set(unsigned int dev_id,
					   union
					   emac2_etherstatspkts256to511octets_u
					   *value);
int emac2_etherstatspkts512to1023octets_get(unsigned int dev_id,
					    union
					    emac2_etherstatspkts512to1023octets_u
					    *value);
int emac2_etherstatspkts512to1023octets_set(unsigned int dev_id,
					    union
					    emac2_etherstatspkts512to1023octets_u
					    *value);
int emac2_etherstatspkts1024to1518octets_get(unsigned int dev_id,
					     union
					     emac2_etherstatspkts1024to1518octets_u
					     *value);
int emac2_etherstatspkts1024to1518octets_set(unsigned int dev_id,
					     union
					     emac2_etherstatspkts1024to1518octets_u
					     *value);
int emac2_etherstatspkts1519toxoctets_get(unsigned int dev_id,
					  union
					  emac2_etherstatspkts1519toxoctets_u
					  *value);
int emac2_etherstatspkts1519toxoctets_set(unsigned int dev_id,
					  union
					  emac2_etherstatspkts1519toxoctets_u
					  *value);
int emac2_etherstatsjabbers_get(unsigned int dev_id,
				union emac2_etherstatsjabbers_u *value);
int emac2_etherstatsjabbers_set(unsigned int dev_id,
				union emac2_etherstatsjabbers_u *value);
int emac2_etherstatsfragments_get(unsigned int dev_id,
				  union emac2_etherstatsfragments_u *value);
int emac2_etherstatsfragments_set(unsigned int dev_id,
				  union emac2_etherstatsfragments_u *value);

#endif
