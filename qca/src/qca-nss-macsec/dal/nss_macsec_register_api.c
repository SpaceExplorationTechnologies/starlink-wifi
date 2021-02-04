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

#include "nss_macsec_register.h"
#include "nss_macsec_register_api.h"

#define NSS_MACSEC_NUM		3
#define NSS_MACSEC_REG_LEN	0x200000

int nss_macsec_reg_read(unsigned int dev_id, unsigned int reg_addr,
			unsigned int *pvalue);
int nss_macsec_reg_write(unsigned int dev_id, unsigned int reg_addr,
			 unsigned int pvalue);

int dal_reg_read(unsigned int dev_id, unsigned int reg_addr,
		 unsigned int *pvalue)
{
	if ((dev_id >= NSS_MACSEC_NUM) || (reg_addr >= NSS_MACSEC_REG_LEN)) {
#if 0
		osal_print
		    ("Make sure input parameters are correct: dev_id:%d reg_addr:0x%x\n",
		     dev_id, reg_addr);
#endif
		return -1;
	}
	nss_macsec_reg_read(dev_id, reg_addr, pvalue);
	return 0;
}

int dal_reg_write(unsigned int dev_id, unsigned int reg_addr,
		  unsigned int value)
{
	if ((dev_id >= NSS_MACSEC_NUM) || (reg_addr >= NSS_MACSEC_REG_LEN)) {
#if 0
		osal_print
		    ("Make sure input parameters are correct: dev_id:%d reg_addr:0x%x\n",
		     dev_id, reg_addr);
#endif
		return -1;
	}
	nss_macsec_reg_write(dev_id, reg_addr, value);
	return 0;
}

int dal_reg_tbl_read(unsigned int dev_id, unsigned int reg_addr,
		     unsigned int *pvalue, unsigned int width)
{
	unsigned int i = 0;
	unsigned int addr = reg_addr;
	unsigned int *dst = pvalue;

	for (i = 0; i < width; i++) {
		dal_reg_read(dev_id, addr, dst);
		addr += sizeof(unsigned int);
		dst++;
	}
	return 0;
}

int dal_reg_tbl_write(unsigned int dev_id, unsigned int reg_addr,
		      unsigned int *pvalue, unsigned int width)
{
	unsigned int i = 0;
	unsigned int addr = reg_addr;
	unsigned int *src = pvalue;

	for (i = 0; i < width; i++) {
		dal_reg_write(dev_id, addr, *src);
		addr += sizeof(unsigned int);
		src++;
	}
	return 0;
}

int dal_var_field_get(unsigned int field_offset,
		      unsigned int field_len,
		      unsigned int *pFieldValue, unsigned int value)
{
	if ((field_len == 0x20) && (0 == field_offset)) {
		*pFieldValue = value;
	} else {
		*pFieldValue =
		    (value >> field_offset) & (SW_BIT_MASK_U32(field_len));
	}

	return DAL_OK;
}

int dal_var_field_set(unsigned int field_offset,
		      unsigned int field_len,
		      unsigned int fieldValue, unsigned int *pValue)
{
	if ((field_len == 0x20) && (0 == field_offset)) {
		*pValue = fieldValue;
	} else {
		SW_REG_SET_BY_FIELD_U32(*pValue, fieldValue, field_offset,
					field_len);
	}

	return DAL_OK;
}

int ingress_reg_get(unsigned int dev_id,
		    unsigned int reg_addr, unsigned int *pvalue)
{
	return dal_reg_read(dev_id, reg_addr + INGRESS_BASE_ADDR, pvalue);
}

int ingress_reg_tbl_get(unsigned int dev_id,
			unsigned int reg_addr,
			unsigned int *pvalue, unsigned int width)
{
	return dal_reg_tbl_read(dev_id, reg_addr + INGRESS_BASE_ADDR,
				pvalue, width);
}

int ingress_reg_set(unsigned int dev_id,
		    unsigned int reg_addr, unsigned int value)
{
	return dal_reg_write(dev_id, reg_addr + INGRESS_BASE_ADDR, value);
}

int ingress_reg_tbl_set(unsigned int dev_id,
			unsigned int reg_addr,
			unsigned int *pvalue, unsigned int width)
{
	return dal_reg_tbl_write(dev_id, reg_addr + INGRESS_BASE_ADDR,
				 pvalue, width);
}

int igsy_l2sec_version_get(unsigned int dev_id,
			   union igsy_l2sec_version_u *value)
{
	return ingress_reg_get(dev_id, IGSY_L2SEC_VERSION_ADDRESS, &value->val);
}

int igsy_l2sec_version_set(unsigned int dev_id,
			   union igsy_l2sec_version_u *value)
{
	return DAL_NOT_SUPPORT;
}

int insy_prescale_get(unsigned int dev_id, union insy_prescale_u *value)
{
	return ingress_reg_get(dev_id, INSY_PRESCALE_ADDRESS, &value->val);
}

int insy_prescale_set(unsigned int dev_id, union insy_prescale_u *value)
{
	return ingress_reg_set(dev_id, INSY_PRESCALE_ADDRESS, value->val);
}

int csr_igsy_vlan_tpid0_get(unsigned int dev_id,
			    union csr_igsy_vlan_tpid0_u *value)
{
	return ingress_reg_get(dev_id, CSR_IGSY_VLAN_TPID0_ADDRESS,
			       &value->val);
}

int csr_igsy_vlan_tpid0_set(unsigned int dev_id,
			    union csr_igsy_vlan_tpid0_u *value)
{
	return ingress_reg_set(dev_id, CSR_IGSY_VLAN_TPID0_ADDRESS, value->val);
}

int csr_igsy_vlan_tpid1_get(unsigned int dev_id,
			    union csr_igsy_vlan_tpid1_u *value)
{
	return ingress_reg_get(dev_id, CSR_IGSY_VLAN_TPID1_ADDRESS,
			       &value->val);
}

int csr_igsy_vlan_tpid1_set(unsigned int dev_id,
			    union csr_igsy_vlan_tpid1_u *value)
{
	return ingress_reg_set(dev_id, CSR_IGSY_VLAN_TPID1_ADDRESS, value->val);
}

int csr_igsy_vlan_cp_tag_get(unsigned int dev_id,
			     union csr_igsy_vlan_cp_tag_u *value)
{
	return ingress_reg_get(dev_id, CSR_IGSY_VLAN_CP_TAG_ADDRESS,
			       &value->val);
}

int csr_igsy_vlan_cp_tag_set(unsigned int dev_id,
			     union csr_igsy_vlan_cp_tag_u *value)
{
	return ingress_reg_set(dev_id, CSR_IGSY_VLAN_CP_TAG_ADDRESS,
			       value->val);
}

int csr_igsy_mtu_get(unsigned int dev_id, union csr_igsy_mtu_u *value)
{
	return ingress_reg_get(dev_id, CSR_IGSY_MTU_ADDRESS, &value->val);
}

int csr_igsy_mtu_set(unsigned int dev_id, union csr_igsy_mtu_u *value)
{
	return ingress_reg_set(dev_id, CSR_IGSY_MTU_ADDRESS, value->val);
}

int csr_igsy_ctrl_get(unsigned int dev_id, union csr_igsy_ctrl_u *value)
{
	return ingress_reg_get(dev_id, CSR_IGSY_CTRL_ADDRESS, &value->val);
}

int csr_igsy_ctrl_set(unsigned int dev_id, union csr_igsy_ctrl_u *value)
{
	return ingress_reg_set(dev_id, CSR_IGSY_CTRL_ADDRESS, value->val);
}

int csr_insy_sa_thr_get(unsigned int dev_id, union csr_insy_sa_thr_u *value)
{
	return ingress_reg_get(dev_id, CSR_INSY_SA_THR_ADDRESS, &value->val);
}

int csr_insy_sa_thr_set(unsigned int dev_id, union csr_insy_sa_thr_u *value)
{
	return ingress_reg_set(dev_id, CSR_INSY_SA_THR_ADDRESS, value->val);
}

int insy_fmt_csr_debug_get(unsigned int dev_id,
			   union insy_fmt_csr_debug_u *value)
{
	return ingress_reg_get(dev_id, INSY_FMT_CSR_DEBUG_ADDRESS, &value->val);
}

int insy_fmt_csr_debug_set(unsigned int dev_id,
			   union insy_fmt_csr_debug_u *value)
{
	return DAL_NOT_SUPPORT;
}

int insy_rpy_csr_debug_get(unsigned int dev_id,
			   union insy_rpy_csr_debug_u *value)
{
	return ingress_reg_get(dev_id, INSY_RPY_CSR_DEBUG_ADDRESS, &value->val);
}

int insy_rpy_csr_debug_set(unsigned int dev_id,
			   union insy_rpy_csr_debug_u *value)
{
	return DAL_NOT_SUPPORT;
}

int insy_aes_gcm_counter_incr_csr_debug_get(unsigned int dev_id,
					    union
					    insy_aes_gcm_counter_incr_csr_debug_u
					    *value)
{
	return ingress_reg_get(dev_id,
			       INSY_AES_GCM_COUNTER_INCR_CSR_DEBUG_ADDRESS,
			       &value->val);
}

int insy_aes_gcm_counter_incr_csr_debug_set(unsigned int dev_id,
					    union
					    insy_aes_gcm_counter_incr_csr_debug_u
					    *value)
{
	return DAL_NOT_SUPPORT;
}

int insy_gcm_mult_data_cnt_csr_debug_get(unsigned int dev_id,
					 union
					 insy_gcm_mult_data_cnt_csr_debug_u
					 *value)
{
	return ingress_reg_get(dev_id, INSY_GCM_MULT_DATA_CNT_CSR_DEBUG_ADDRESS,
			       &value->val);
}

int insy_gcm_mult_data_cnt_csr_debug_set(unsigned int dev_id,
					 union
					 insy_gcm_mult_data_cnt_csr_debug_u
					 *value)
{
	return DAL_NOT_SUPPORT;
}

int insy_gcm_mult_lena_lsb_csr_debug_get(unsigned int dev_id,
					 union
					 insy_gcm_mult_lena_lsb_csr_debug_u
					 *value)
{
	return ingress_reg_get(dev_id, INSY_GCM_MULT_LENA_LSB_CSR_DEBUG_ADDRESS,
			       &value->val);
}

int insy_gcm_mult_lena_lsb_csr_debug_set(unsigned int dev_id,
					 union
					 insy_gcm_mult_lena_lsb_csr_debug_u
					 *value)
{
	return DAL_NOT_SUPPORT;
}

int insy_gcm_mult_lena_msb_csr_debug_get(unsigned int dev_id,
					 union
					 insy_gcm_mult_lena_msb_csr_debug_u
					 *value)
{
	return ingress_reg_get(dev_id, INSY_GCM_MULT_LENA_MSB_CSR_DEBUG_ADDRESS,
			       &value->val);
}

int insy_gcm_mult_lena_msb_csr_debug_set(unsigned int dev_id,
					 union
					 insy_gcm_mult_lena_msb_csr_debug_u
					 *value)
{
	return DAL_NOT_SUPPORT;
}

int insy_gcm_mult_lenc_lsb_csr_debug_get(unsigned int dev_id,
					 union
					 insy_gcm_mult_lenc_lsb_csr_debug_u
					 *value)
{
	return ingress_reg_get(dev_id, INSY_GCM_MULT_LENC_LSB_CSR_DEBUG_ADDRESS,
			       &value->val);
}

int insy_gcm_mult_lenc_lsb_csr_debug_set(unsigned int dev_id,
					 union
					 insy_gcm_mult_lenc_lsb_csr_debug_u
					 *value)
{
	return DAL_NOT_SUPPORT;
}

int insy_gcm_mult_lenc_msb_csr_debug_get(unsigned int dev_id,
					 union
					 insy_gcm_mult_lenc_msb_csr_debug_u
					 *value)
{
	return ingress_reg_get(dev_id, INSY_GCM_MULT_LENC_MSB_CSR_DEBUG_ADDRESS,
			       &value->val);
}

int insy_gcm_mult_lenc_msb_csr_debug_set(unsigned int dev_id,
					 union
					 insy_gcm_mult_lenc_msb_csr_debug_u
					 *value)
{
	return DAL_NOT_SUPPORT;
}

int igsy_csr_busy_signal_get(unsigned int dev_id,
			     union igsy_csr_busy_signal_u *value)
{
	return ingress_reg_get(dev_id, IGSY_CSR_BUSY_SIGNAL_ADDRESS,
			       &value->val);
}

int igsy_csr_busy_signal_set(unsigned int dev_id,
			     union igsy_csr_busy_signal_u *value)
{
	return DAL_NOT_SUPPORT;
}

int insy_sctrl_drop_en_get(unsigned int dev_id,
			   union insy_sctrl_drop_en_u *value)
{
	return ingress_reg_get(dev_id, INSY_SCTRL_DROP_EN_ADDRESS, &value->val);
}

int insy_sctrl_drop_en_set(unsigned int dev_id,
			   union insy_sctrl_drop_en_u *value)
{
	return ingress_reg_set(dev_id, INSY_SCTRL_DROP_EN_ADDRESS, value->val);
}

int insy_ectrl_en_get(unsigned int dev_id, union insy_ectrl_en_u *value)
{
	return ingress_reg_get(dev_id, INSY_ECTRL_EN_ADDRESS, &value->val);
}

int insy_ectrl_en_set(unsigned int dev_id, union insy_ectrl_en_u *value)
{
	return ingress_reg_set(dev_id, INSY_ECTRL_EN_ADDRESS, value->val);
}

int insy_emac_regs_get(unsigned int dev_id, union insy_emac_regs_u *value)
{
	return ingress_reg_get(dev_id, INSY_EMAC_REGS_ADDRESS, &value->val);
}

int insy_emac_regs_set(unsigned int dev_id, union insy_emac_regs_u *value)
{
	return ingress_reg_set(dev_id, INSY_EMAC_REGS_ADDRESS, value->val);
}

int insy_sci_default_entry_lsb_get(unsigned int dev_id,
				   union insy_sci_default_entry_lsb_u *value)
{
	return ingress_reg_get(dev_id, INSY_SCI_DEFAULT_ENTRY_LSB_ADDRESS,
			       &value->val);
}

int insy_sci_default_entry_lsb_set(unsigned int dev_id,
				   union insy_sci_default_entry_lsb_u *value)
{
	return ingress_reg_set(dev_id, INSY_SCI_DEFAULT_ENTRY_LSB_ADDRESS,
			       value->val);
}

int insy_sci_default_entry_msb_get(unsigned int dev_id,
				   union insy_sci_default_entry_msb_u *value)
{
	return ingress_reg_get(dev_id, INSY_SCI_DEFAULT_ENTRY_MSB_ADDRESS,
			       &value->val);
}

int insy_sci_default_entry_msb_set(unsigned int dev_id,
				   union insy_sci_default_entry_msb_u *value)
{
	return ingress_reg_set(dev_id, INSY_SCI_DEFAULT_ENTRY_MSB_ADDRESS,
			       value->val);
}

int igsy_int_get(unsigned int dev_id, union igsy_int_u *value)
{
	return ingress_reg_get(dev_id, IGSY_INT_ADDRESS, &value->val);
}

int igsy_int_set(unsigned int dev_id, union igsy_int_u *value)
{
	return ingress_reg_set(dev_id, IGSY_INT_ADDRESS, value->val);
}

int igsy_int_en_get(unsigned int dev_id, union igsy_int_en_u *value)
{
	return ingress_reg_get(dev_id, IGSY_INT_EN_ADDRESS, &value->val);
}

int igsy_int_en_set(unsigned int dev_id, union igsy_int_en_u *value)
{
	return ingress_reg_set(dev_id, IGSY_INT_EN_ADDRESS, value->val);
}

int icv_err_reg_get(unsigned int dev_id, union icv_err_reg_u *value)
{
	return ingress_reg_get(dev_id, ICV_ERR_REG_ADDRESS, &value->val);
}

int icv_err_reg_set(unsigned int dev_id, union icv_err_reg_u *value)
{
	return ingress_reg_set(dev_id, ICV_ERR_REG_ADDRESS, value->val);
}

int rpy_err_reg_get(unsigned int dev_id, union rpy_err_reg_u *value)
{
	return ingress_reg_get(dev_id, RPY_ERR_REG_ADDRESS, &value->val);
}

int rpy_err_reg_set(unsigned int dev_id, union rpy_err_reg_u *value)
{
	return ingress_reg_set(dev_id, RPY_ERR_REG_ADDRESS, value->val);
}

int igsy_sa_exp_get(unsigned int dev_id, union igsy_sa_exp_u *value)
{
	return ingress_reg_get(dev_id, IGSY_SA_EXP_ADDRESS, &value->val);
}

int igsy_sa_exp_set(unsigned int dev_id, union igsy_sa_exp_u *value)
{
	return ingress_reg_set(dev_id, IGSY_SA_EXP_ADDRESS, value->val);
}

int igsy_sa_thr_get(unsigned int dev_id, union igsy_sa_thr_u *value)
{
	return ingress_reg_get(dev_id, IGSY_SA_THR_ADDRESS, &value->val);
}

int igsy_sa_thr_set(unsigned int dev_id, union igsy_sa_thr_u *value)
{
	return ingress_reg_set(dev_id, IGSY_SA_THR_ADDRESS, value->val);
}

int igecc_err_reg_get(unsigned int dev_id, union igecc_err_reg_u *value)
{
	return ingress_reg_get(dev_id, IGECC_ERR_REG_ADDRESS, &value->val);
}

int igecc_err_reg_set(unsigned int dev_id, union igecc_err_reg_u *value)
{
	return ingress_reg_set(dev_id, IGECC_ERR_REG_ADDRESS, value->val);
}

int igprc_ecc_err1_addr_get(unsigned int dev_id,
			    union igprc_ecc_err1_addr_u *value)
{
	return ingress_reg_get(dev_id, IGPRC_ECC_ERR1_ADDR_ADDRESS,
			       &value->val);
}

int igprc_ecc_err1_addr_set(unsigned int dev_id,
			    union igprc_ecc_err1_addr_u *value)
{
	return ingress_reg_set(dev_id, IGPRC_ECC_ERR1_ADDR_ADDRESS, value->val);
}

int igprc_ecc_err2_addr_get(unsigned int dev_id,
			    union igprc_ecc_err2_addr_u *value)
{
	return ingress_reg_get(dev_id, IGPRC_ECC_ERR2_ADDR_ADDRESS,
			       &value->val);
}

int igprc_ecc_err2_addr_set(unsigned int dev_id,
			    union igprc_ecc_err2_addr_u *value)
{
	return ingress_reg_set(dev_id, IGPRC_ECC_ERR2_ADDR_ADDRESS, value->val);
}

int iglkup_ctlf_ecc_err_addr_get(unsigned int dev_id,
				 union iglkup_ctlf_ecc_err_addr_u *value)
{
	return ingress_reg_get(dev_id, IGLKUP_CTLF_ECC_ERR_ADDR_ADDRESS,
			       &value->val);
}

int iglkup_ctlf_ecc_err_addr_set(unsigned int dev_id,
				 union iglkup_ctlf_ecc_err_addr_u *value)
{
	return ingress_reg_set(dev_id, IGLKUP_CTLF_ECC_ERR_ADDR_ADDRESS,
			       value->val);
}

int pfmt_ecc_err_addr_get(unsigned int dev_id, union pfmt_ecc_err_addr_u *value)
{
	return ingress_reg_get(dev_id, PFMT_ECC_ERR_ADDR_ADDRESS, &value->val);
}

int pfmt_ecc_err_addr_set(unsigned int dev_id, union pfmt_ecc_err_addr_u *value)
{
	return ingress_reg_set(dev_id, PFMT_ECC_ERR_ADDR_ADDRESS, value->val);
}

int irpy_sc_sa_ecc_err_addr_get(unsigned int dev_id,
				union irpy_sc_sa_ecc_err_addr_u *value)
{
	return ingress_reg_get(dev_id, IRPY_SC_SA_ECC_ERR_ADDR_ADDRESS,
			       &value->val);
}

int irpy_sc_sa_ecc_err_addr_set(unsigned int dev_id,
				union irpy_sc_sa_ecc_err_addr_u *value)
{
	return ingress_reg_set(dev_id, IRPY_SC_SA_ECC_ERR_ADDR_ADDRESS,
			       value->val);
}

int igpoc_ctlf_ecc_err_addr_get(unsigned int dev_id,
				union igpoc_ctlf_ecc_err_addr_u *value)
{
	return ingress_reg_get(dev_id, IGPOC_CTLF_ECC_ERR_ADDR_ADDRESS,
			       &value->val);
}

int igpoc_ctlf_ecc_err_addr_set(unsigned int dev_id,
				union igpoc_ctlf_ecc_err_addr_u *value)
{
	return ingress_reg_set(dev_id, IGPOC_CTLF_ECC_ERR_ADDR_ADDRESS,
			       value->val);
}

int igpoc_ecc_err1_addr_get(unsigned int dev_id,
			    union igpoc_ecc_err1_addr_u *value)
{
	return ingress_reg_get(dev_id, IGPOC_ECC_ERR1_ADDR_ADDRESS,
			       &value->val);
}

int igpoc_ecc_err1_addr_set(unsigned int dev_id,
			    union igpoc_ecc_err1_addr_u *value)
{
	return ingress_reg_set(dev_id, IGPOC_ECC_ERR1_ADDR_ADDRESS, value->val);
}

int igpoc_ecc_err2_addr_get(unsigned int dev_id,
			    union igpoc_ecc_err2_addr_u *value)
{
	return ingress_reg_get(dev_id, IGPOC_ECC_ERR2_ADDR_ADDRESS,
			       &value->val);
}

int igpoc_ecc_err2_addr_set(unsigned int dev_id,
			    union igpoc_ecc_err2_addr_u *value)
{
	return ingress_reg_set(dev_id, IGPOC_ECC_ERR2_ADDR_ADDRESS, value->val);
}

int igsy_smib_ecc_err_addr_get(unsigned int dev_id,
			       union igsy_smib_ecc_err_addr_u *value)
{
	return ingress_reg_get(dev_id, IGSY_SMIB_ECC_ERR_ADDR_ADDRESS,
			       &value->val);
}

int igsy_smib_ecc_err_addr_set(unsigned int dev_id,
			       union igsy_smib_ecc_err_addr_u *value)
{
	return ingress_reg_set(dev_id, IGSY_SMIB_ECC_ERR_ADDR_ADDRESS,
			       value->val);
}

int ig_table_cmd_get(unsigned int dev_id, union ig_table_cmd_u *value)
{
	return ingress_reg_get(dev_id, IG_TABLE_CMD_ADDRESS, &value->val);
}

int ig_table_cmd_set(unsigned int dev_id, union ig_table_cmd_u *value)
{
	return ingress_reg_set(dev_id, IG_TABLE_CMD_ADDRESS, value->val);
}

int ig_table_data_get(unsigned int dev_id, union ig_table_data_u *value)
{
	return ingress_reg_get(dev_id, IG_TABLE_DATA_ADDRESS, &value->val);
}

int ig_table_data_set(unsigned int dev_id, union ig_table_data_u *value)
{
	return ingress_reg_set(dev_id, IG_TABLE_DATA_ADDRESS, value->val);
}

int ig_indirect_table_set(unsigned int dev_id,
			  unsigned int table_type,
			  unsigned int index,
			  unsigned int entry_len, unsigned int *pentry)
{
	unsigned int cmd = 0;

	/* Update Table data */
	ingress_reg_tbl_set(dev_id, IG_TABLE_DATA_ADDRESS, pentry, entry_len);

	/* Update Command word */
	cmd = (TABLE_WRITE_OP << 30) | (table_type << 12) | index;
	ig_table_cmd_set(dev_id, (union ig_table_cmd_u *)&cmd);

	return 0;
}

int ig_indirect_table_get(unsigned int dev_id,
			  unsigned int table_type,
			  unsigned int index,
			  unsigned int entry_len, unsigned int *pentry)
{
	unsigned int cmd = 0;

	/* Update Command word */
	cmd = (TABLE_READ_OP << 30) | (table_type << 12) | index;
	ig_table_cmd_set(dev_id, (union ig_table_cmd_u *)&cmd);

	/* Read Table data */
	ingress_reg_tbl_get(dev_id, IG_TABLE_DATA_ADDRESS, pentry, entry_len);

	return 0;
}

int ig_ctl_filt_table_set(unsigned int dev_id,
			  unsigned int index, unsigned int *pentry)
{
	if ((index < IG_CTL_FILT_INDEX_MIN) || (index > IG_CTL_FILT_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_set(dev_id, IG_CTL_FILT_TABLE_TYPE, index,
				     IG_CTL_FILT_ENTRY_LEN, pentry);
}

int ig_ctl_filt_table_get(unsigned int dev_id,
			  unsigned int index, unsigned int *pentry)
{
	if ((index < IG_CTL_FILT_INDEX_MIN) || (index > IG_CTL_FILT_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_get(dev_id, IG_CTL_FILT_TABLE_TYPE, index,
				     IG_CTL_FILT_ENTRY_LEN, pentry);
}

int ig_prc_lut_table_set(unsigned int dev_id,
			 unsigned int index, unsigned int *pentry)
{
	if ((index < IG_PRC_LUT_INDEX_MIN) || (index > IG_PRC_LUT_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_set(dev_id, IG_PRC_LUT_TABLE_TYPE, index,
				     IG_PRC_LUT_ENTRY_LEN, pentry);
}

int ig_prc_lut_table_get(unsigned int dev_id,
			 unsigned int index, unsigned int *pentry)
{
	if ((index < IG_PRC_LUT_INDEX_MIN) || (index > IG_PRC_LUT_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_get(dev_id, IG_PRC_LUT_TABLE_TYPE, index,
				     IG_PRC_LUT_ENTRY_LEN, pentry);
}

int ig_sc_table_set(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry)
{
	if ((index < IG_SC_INDEX_MIN) || (index > IG_SC_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_set(dev_id, IG_SC_TABLE_TYPE, index,
				     IG_SC_ENTRY_LEN, pentry);
}

int ig_sc_table_get(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry)
{
	if ((index < IG_SC_INDEX_MIN) || (index > IG_SC_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_get(dev_id, IG_SC_TABLE_TYPE, index,
				     IG_SC_ENTRY_LEN, pentry);
}

int ig_sa_table_set(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry)
{
	if ((index < IG_SA_INDEX_MIN) || (index > IG_SA_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_set(dev_id, IG_SA_TABLE_TYPE, index,
				     IG_SA_ENTRY_LEN, pentry);
}

int ig_sa_table_get(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry)
{
	if ((index < IG_SA_INDEX_MIN) || (index > IG_SA_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_get(dev_id, IG_SA_TABLE_TYPE, index,
				     IG_SA_ENTRY_LEN, pentry);
}

int ig_sak_table_set(unsigned int dev_id,
		     unsigned int index, unsigned int *pentry)
{
	if ((index < IG_SAK_INDEX_MIN) || (index > IG_SAK_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_set(dev_id, IG_SAK_TABLE_TYPE, index,
				     IG_SAK_ENTRY_LEN, pentry);
}

int ig_sak_table_get(unsigned int dev_id,
		     unsigned int index, unsigned int *pentry)
{
	if ((index < IG_SAK_INDEX_MIN) || (index > IG_SAK_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_get(dev_id, IG_SAK_TABLE_TYPE, index,
				     IG_SAK_ENTRY_LEN, pentry);
}

int ig_poc_lut_table_set(unsigned int dev_id,
			 unsigned int index, unsigned int *pentry)
{
	if ((index < IG_POC_LUT_INDEX_MIN) || (index > IG_POC_LUT_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_set(dev_id, IG_POC_LUT_TABLE_TYPE, index,
				     IG_POC_LUT_ENTRY_LEN, pentry);
}

int ig_poc_lut_table_get(unsigned int dev_id,
			 unsigned int index, unsigned int *pentry)
{
	if ((index < IG_POC_LUT_INDEX_MIN) || (index > IG_POC_LUT_INDEX_MAX)) {
		return -1;
	}

	return ig_indirect_table_get(dev_id, IG_POC_LUT_TABLE_TYPE, index,
				     IG_POC_LUT_ENTRY_LEN, pentry);
}

int ig_smib_table_sc_sa_get(unsigned int dev_id,
			    unsigned int index, unsigned int *pentry)
{
	int i;
	int entry_offset = 0;
	unsigned int cmd = 0;

	if ((index < IG_SMIB_INDEX_MIN) || (index > IG_SMIB_INDEX_MAX)) {
		return -1;
	}

	for (i = 0; i < IG_SMIB_ENTRY_LEN; i++) {
		/* Update Command word */
		cmd =
		    (TABLE_READ_OP << 30) | (IG_SMIB_TABLE_TYPE << 12) |
		    ((index * IG_SMIB_ENTRY_LEN) + i);
		ig_table_cmd_set(dev_id, (union ig_table_cmd_u *)&cmd);

		/* Read Table data */
		ingress_reg_tbl_get(dev_id, IG_TABLE_DATA_ADDRESS,
				    (pentry + entry_offset), 2);
		entry_offset += 2;
	}

	return 0;
}

int ig_smib_table_common_get(unsigned int dev_id, unsigned int *pentry)
{
	int i;
	int entry_offset = 0;
	unsigned int cmd = 0;

	for (i = IG_SMIB_COMMON_INDEX_MIN; i < IG_SMIB_COMMON_INDEX_MAX + 1; i++) {
		/* Update Command word */
		cmd = (TABLE_READ_OP << 30) | (IG_SMIB_TABLE_TYPE << 12) | i;
		ig_table_cmd_set(dev_id, (union ig_table_cmd_u *)&cmd);

		/* Read Table data */
		ingress_reg_tbl_get(dev_id, IG_TABLE_DATA_ADDRESS,
				    (pentry + entry_offset), 2);
		entry_offset += 2;
	}

	return 0;
}

int egress_reg_get(unsigned int dev_id,
		   unsigned int reg_addr, unsigned int *pvalue)
{
	return dal_reg_read(dev_id, reg_addr + EGRESS_BASE_ADDR, pvalue);
}

int egress_reg_tbl_get(unsigned int dev_id,
		       unsigned int reg_addr,
		       unsigned int *pvalue, unsigned int width)
{
	return dal_reg_tbl_read(dev_id, reg_addr + EGRESS_BASE_ADDR,
				pvalue, width);
}

int egress_reg_set(unsigned int dev_id,
		   unsigned int reg_addr, unsigned int value)
{
	return dal_reg_write(dev_id, reg_addr + EGRESS_BASE_ADDR, value);
}

int egress_reg_tbl_set(unsigned int dev_id,
		       unsigned int reg_addr,
		       unsigned int *pvalue, unsigned int width)
{
	return dal_reg_tbl_write(dev_id, reg_addr + EGRESS_BASE_ADDR,
				 pvalue, width);
}

int egsy_l2sec_version_get(unsigned int dev_id,
			   union egsy_l2sec_version_u *value)
{
	return egress_reg_get(dev_id, EGSY_L2SEC_VERSION_ADDRESS, &value->val);
}

int egsy_l2sec_version_set(unsigned int dev_id,
			   union egsy_l2sec_version_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_l2sec_control_get(unsigned int dev_id,
			   union egsy_l2sec_control_u *value)
{
	return egress_reg_get(dev_id, EGSY_L2SEC_CONTROL_ADDRESS, &value->val);
}

int egsy_l2sec_control_set(unsigned int dev_id,
			   union egsy_l2sec_control_u *value)
{
	return egress_reg_set(dev_id, EGSY_L2SEC_CONTROL_ADDRESS, value->val);
}

int egsy_prescale_get(unsigned int dev_id, union egsy_prescale_u *value)
{
	return egress_reg_get(dev_id, EGSY_PRESCALE_ADDRESS, &value->val);
}

int egsy_prescale_set(unsigned int dev_id, union egsy_prescale_u *value)
{
	return egress_reg_set(dev_id, EGSY_PRESCALE_ADDRESS, value->val);
}

int csr_egsy_vlan_tpid0_get(unsigned int dev_id,
			    union csr_egsy_vlan_tpid0_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_VLAN_TPID0_ADDRESS, &value->val);
}

int csr_egsy_vlan_tpid0_set(unsigned int dev_id,
			    union csr_egsy_vlan_tpid0_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_VLAN_TPID0_ADDRESS, value->val);
}

int csr_egsy_vlan_tpid1_get(unsigned int dev_id,
			    union csr_egsy_vlan_tpid1_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_VLAN_TPID1_ADDRESS, &value->val);
}

int csr_egsy_vlan_tpid1_set(unsigned int dev_id,
			    union csr_egsy_vlan_tpid1_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_VLAN_TPID1_ADDRESS, value->val);
}

int csr_egsy_vlan_cp_tag_get(unsigned int dev_id,
			     union csr_egsy_vlan_cp_tag_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_VLAN_CP_TAG_ADDRESS,
			      &value->val);
}

int csr_egsy_vlan_cp_tag_set(unsigned int dev_id,
			     union csr_egsy_vlan_cp_tag_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_VLAN_CP_TAG_ADDRESS, value->val);
}

int csr_egsy_pn_thr_get(unsigned int dev_id, union csr_egsy_pn_thr_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_PN_THR_ADDRESS, &value->val);
}

int csr_egsy_pn_thr_set(unsigned int dev_id, union csr_egsy_pn_thr_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_PN_THR_ADDRESS, value->val);
}

int csr_egsy_mtu_get(unsigned int dev_id, union csr_egsy_mtu_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_MTU_ADDRESS, &value->val);
}

int csr_egsy_mtu_set(unsigned int dev_id, union csr_egsy_mtu_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_MTU_ADDRESS, value->val);
}

int csr_egsy_gcm_datain0_get(unsigned int dev_id,
			     union csr_egsy_gcm_datain0_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_DATAIN0_ADDRESS,
			      &value->val);
}

int csr_egsy_gcm_datain0_set(unsigned int dev_id,
			     union csr_egsy_gcm_datain0_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_DATAIN0_ADDRESS, value->val);
}

int csr_egsy_gcm_datain1_get(unsigned int dev_id,
			     union csr_egsy_gcm_datain1_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_DATAIN1_ADDRESS,
			      &value->val);
}

int csr_egsy_gcm_datain1_set(unsigned int dev_id,
			     union csr_egsy_gcm_datain1_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_DATAIN1_ADDRESS, value->val);
}

int csr_egsy_gcm_datain2_get(unsigned int dev_id,
			     union csr_egsy_gcm_datain2_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_DATAIN2_ADDRESS,
			      &value->val);
}

int csr_egsy_gcm_datain2_set(unsigned int dev_id,
			     union csr_egsy_gcm_datain2_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_DATAIN2_ADDRESS, value->val);
}

int csr_egsy_gcm_datain3_get(unsigned int dev_id,
			     union csr_egsy_gcm_datain3_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_DATAIN3_ADDRESS,
			      &value->val);
}

int csr_egsy_gcm_datain3_set(unsigned int dev_id,
			     union csr_egsy_gcm_datain3_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_DATAIN3_ADDRESS, value->val);
}

int csr_egsy_gcm_key0_get(unsigned int dev_id, union csr_egsy_gcm_key0_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_KEY0_ADDRESS, &value->val);
}

int csr_egsy_gcm_key0_set(unsigned int dev_id, union csr_egsy_gcm_key0_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_KEY0_ADDRESS, value->val);
}

int csr_egsy_gcm_key1_get(unsigned int dev_id, union csr_egsy_gcm_key1_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_KEY1_ADDRESS, &value->val);
}

int csr_egsy_gcm_key1_set(unsigned int dev_id, union csr_egsy_gcm_key1_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_KEY1_ADDRESS, value->val);
}

int csr_egsy_gcm_key2_get(unsigned int dev_id, union csr_egsy_gcm_key2_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_KEY2_ADDRESS, &value->val);
}

int csr_egsy_gcm_key2_set(unsigned int dev_id, union csr_egsy_gcm_key2_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_KEY2_ADDRESS, value->val);
}

int csr_egsy_gcm_key3_get(unsigned int dev_id, union csr_egsy_gcm_key3_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_KEY3_ADDRESS, &value->val);
}

int csr_egsy_gcm_key3_set(unsigned int dev_id, union csr_egsy_gcm_key3_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_KEY3_ADDRESS, value->val);
}

int csr_egsy_gcm_iv0_get(unsigned int dev_id, union csr_egsy_gcm_iv0_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_IV0_ADDRESS, &value->val);
}

int csr_egsy_gcm_iv0_set(unsigned int dev_id, union csr_egsy_gcm_iv0_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_IV0_ADDRESS, value->val);
}

int csr_egsy_gcm_iv1_get(unsigned int dev_id, union csr_egsy_gcm_iv1_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_IV1_ADDRESS, &value->val);
}

int csr_egsy_gcm_iv1_set(unsigned int dev_id, union csr_egsy_gcm_iv1_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_IV1_ADDRESS, value->val);
}

int csr_egsy_gcm_iv2_get(unsigned int dev_id, union csr_egsy_gcm_iv2_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_IV2_ADDRESS, &value->val);
}

int csr_egsy_gcm_iv2_set(unsigned int dev_id, union csr_egsy_gcm_iv2_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_IV2_ADDRESS, value->val);
}

int csr_egsy_gcm_iv3_get(unsigned int dev_id, union csr_egsy_gcm_iv3_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_IV3_ADDRESS, &value->val);
}

int csr_egsy_gcm_iv3_set(unsigned int dev_id, union csr_egsy_gcm_iv3_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_IV3_ADDRESS, value->val);
}

int csr_egsy_gcm_hashin0_get(unsigned int dev_id,
			     union csr_egsy_gcm_hashin0_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_HASHIN0_ADDRESS,
			      &value->val);
}

int csr_egsy_gcm_hashin0_set(unsigned int dev_id,
			     union csr_egsy_gcm_hashin0_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_HASHIN0_ADDRESS, value->val);
}

int csr_egsy_gcm_hashin1_get(unsigned int dev_id,
			     union csr_egsy_gcm_hashin1_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_HASHIN1_ADDRESS,
			      &value->val);
}

int csr_egsy_gcm_hashin1_set(unsigned int dev_id,
			     union csr_egsy_gcm_hashin1_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_HASHIN1_ADDRESS, value->val);
}

int csr_egsy_gcm_hashin2_get(unsigned int dev_id,
			     union csr_egsy_gcm_hashin2_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_HASHIN2_ADDRESS,
			      &value->val);
}

int csr_egsy_gcm_hashin2_set(unsigned int dev_id,
			     union csr_egsy_gcm_hashin2_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_HASHIN2_ADDRESS, value->val);
}

int csr_egsy_gcm_hashin3_get(unsigned int dev_id,
			     union csr_egsy_gcm_hashin3_u *value)
{
	return egress_reg_get(dev_id, CSR_EGSY_GCM_HASHIN3_ADDRESS,
			      &value->val);
}

int csr_egsy_gcm_hashin3_set(unsigned int dev_id,
			     union csr_egsy_gcm_hashin3_u *value)
{
	return egress_reg_set(dev_id, CSR_EGSY_GCM_HASHIN3_ADDRESS, value->val);
}

int egsy_gcm_csr_dataout0_get(unsigned int dev_id,
			      union egsy_gcm_csr_dataout0_u *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_CSR_DATAOUT0_ADDRESS,
			      &value->val);
}

int egsy_gcm_csr_dataout0_set(unsigned int dev_id,
			      union egsy_gcm_csr_dataout0_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsygcm_csr_dataout1_get(unsigned int dev_id,
			     union egsygcm_csr_dataout1_u *value)
{
	return egress_reg_get(dev_id, EGSYGCM_CSR_DATAOUT1_ADDRESS,
			      &value->val);
}

int egsygcm_csr_dataout1_set(unsigned int dev_id,
			     union egsygcm_csr_dataout1_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_csr_dataout2_get(unsigned int dev_id,
			      union egsy_gcm_csr_dataout2_u *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_CSR_DATAOUT2_ADDRESS,
			      &value->val);
}

int egsy_gcm_csr_dataout2_set(unsigned int dev_id,
			      union egsy_gcm_csr_dataout2_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_csr_dataout3_get(unsigned int dev_id,
			      union egsy_gcm_csr_dataout3_u *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_CSR_DATAOUT3_ADDRESS,
			      &value->val);
}

int egsy_gcm_csr_dataout3_set(unsigned int dev_id,
			      union egsy_gcm_csr_dataout3_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_csr_hashout0_get(unsigned int dev_id,
			      union egsy_gcm_csr_hashout0_u *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_CSR_HASHOUT0_ADDRESS,
			      &value->val);
}

int egsy_gcm_csr_hashout0_set(unsigned int dev_id,
			      union egsy_gcm_csr_hashout0_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_csr_hashout1_get(unsigned int dev_id,
			      union egsy_gcm_csr_hashout1_u *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_CSR_HASHOUT1_ADDRESS,
			      &value->val);
}

int egsy_gcm_csr_hashout1_set(unsigned int dev_id,
			      union egsy_gcm_csr_hashout1_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_csr_hashout2_get(unsigned int dev_id,
			      union egsy_gcm_csr_hashout2_u *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_CSR_HASHOUT2_ADDRESS,
			      &value->val);
}

int egsy_gcm_csr_hashout2_set(unsigned int dev_id,
			      union egsy_gcm_csr_hashout2_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_csr_hashout3_get(unsigned int dev_id,
			      union egsy_gcm_csr_hashout3_u *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_CSR_HASHOUT3_ADDRESS,
			      &value->val);
}

int egsy_gcm_csr_hashout3_set(unsigned int dev_id,
			      union egsy_gcm_csr_hashout3_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_egebuf_csr_debug_get(unsigned int dev_id,
			      union egsy_egebuf_csr_debug_u *value)
{
	return egress_reg_get(dev_id, EGSY_EGEBUF_CSR_DEBUG_ADDRESS,
			      &value->val);
}

int egsy_egebuf_csr_debug_set(unsigned int dev_id,
			      union egsy_egebuf_csr_debug_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_pfmt_csr_debug_get(unsigned int dev_id,
			    union egsy_pfmt_csr_debug_u *value)
{
	return egress_reg_get(dev_id, EGSY_PFMT_CSR_DEBUG_ADDRESS, &value->val);
}

int egsy_pfmt_csr_debug_set(unsigned int dev_id,
			    union egsy_pfmt_csr_debug_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_mult_lena_lsb_csr_debug_get(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lena_lsb_csr_debug_u
					 *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_MULT_LENA_LSB_CSR_DEBUG_ADDRESS,
			      &value->val);
}

int egsy_gcm_mult_lena_lsb_csr_debug_set(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lena_lsb_csr_debug_u
					 *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_mult_lena_msb_csr_debug_get(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lena_msb_csr_debug_u
					 *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_MULT_LENA_MSB_CSR_DEBUG_ADDRESS,
			      &value->val);
}

int egsy_gcm_mult_lena_msb_csr_debug_set(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lena_msb_csr_debug_u
					 *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_mult_lenc_lsb_csr_debug_get(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lenc_lsb_csr_debug_u
					 *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_MULT_LENC_LSB_CSR_DEBUG_ADDRESS,
			      &value->val);
}

int egsy_gcm_mult_lenc_lsb_csr_debug_set(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lenc_lsb_csr_debug_u
					 *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_mult_lenc_msb_csr_debug_get(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lenc_msb_csr_debug_u
					 *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_MULT_LENC_MSB_CSR_DEBUG_ADDRESS,
			      &value->val);
}

int egsy_gcm_mult_lenc_msb_csr_debug_set(unsigned int dev_id,
					 union
					 egsy_gcm_mult_lenc_msb_csr_debug_u
					 *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_gcm_mult_data_cnt_csr_debug_get(unsigned int dev_id,
					 union
					 egsy_gcm_mult_data_cnt_csr_debug_u
					 *value)
{
	return egress_reg_get(dev_id, EGSY_GCM_MULT_DATA_CNT_CSR_DEBUG_ADDRESS,
			      &value->val);
}

int egsy_gcm_mult_data_cnt_csr_debug_set(unsigned int dev_id,
					 union
					 egsy_gcm_mult_data_cnt_csr_debug_u
					 *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_aes_gcm_counter_incr_csr_debug_get(unsigned int dev_id,
					    union
					    egsy_aes_gcm_counter_incr_csr_debug_u
					    *value)
{
	return egress_reg_get(dev_id,
			      EGSY_AES_GCM_COUNTER_INCR_CSR_DEBUG_ADDRESS,
			      &value->val);
}

int egsy_aes_gcm_counter_incr_csr_debug_set(unsigned int dev_id,
					    union
					    egsy_aes_gcm_counter_incr_csr_debug_u
					    *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_csr_busy_signal_get(unsigned int dev_id,
			     union egsy_csr_busy_signal_u *value)
{
	return egress_reg_get(dev_id, EGSY_CSR_BUSY_SIGNAL_ADDRESS,
			      &value->val);
}

int egsy_csr_busy_signal_set(unsigned int dev_id,
			     union egsy_csr_busy_signal_u *value)
{
	return DAL_NOT_SUPPORT;
}

int egsy_macsec_spare_reg1_get(unsigned int dev_id,
			       union egsy_macsec_spare_reg1_u *value)
{
	return egress_reg_get(dev_id, EGSY_MACSEC_SPARE_REG1_ADDRESS,
			      &value->val);
}

int egsy_macsec_spare_reg1_set(unsigned int dev_id,
			       union egsy_macsec_spare_reg1_u *value)
{
	return egress_reg_set(dev_id, EGSY_MACSEC_SPARE_REG1_ADDRESS,
			      value->val);
}

int egsy_sctrl_drop_en_get(unsigned int dev_id,
			   union egsy_sctrl_drop_en_u *value)
{
	return egress_reg_get(dev_id, EGSY_SCTRL_DROP_EN_ADDRESS, &value->val);
}

int egsy_sctrl_drop_en_set(unsigned int dev_id,
			   union egsy_sctrl_drop_en_u *value)
{
	return egress_reg_set(dev_id, EGSY_SCTRL_DROP_EN_ADDRESS, value->val);
}

int egsy_ectrl_enable_get(unsigned int dev_id, union egsy_ectrl_enable_u *value)
{
	return egress_reg_get(dev_id, EGSY_ECTRL_ENABLE_ADDRESS, &value->val);
}

int egsy_ectrl_enable_set(unsigned int dev_id, union egsy_ectrl_enable_u *value)
{
	return egress_reg_set(dev_id, EGSY_ECTRL_ENABLE_ADDRESS, value->val);
}

int egsy_emac_regs_get(unsigned int dev_id, union egsy_emac_regs_u *value)
{
	return egress_reg_get(dev_id, EGSY_EMAC_REGS_ADDRESS, &value->val);
}

int egsy_emac_regs_set(unsigned int dev_id, union egsy_emac_regs_u *value)
{
	return egress_reg_set(dev_id, EGSY_EMAC_REGS_ADDRESS, value->val);
}

int egsy_int_get(unsigned int dev_id, union egsy_int_u *value)
{
	return egress_reg_get(dev_id, EGSY_INT_ADDRESS, &value->val);
}

int egsy_int_set(unsigned int dev_id, union egsy_int_u *value)
{
	return egress_reg_set(dev_id, EGSY_INT_ADDRESS, value->val);
}

int egsy_int_en_get(unsigned int dev_id, union egsy_int_en_u *value)
{
	return egress_reg_get(dev_id, EGSY_INT_EN_ADDRESS, &value->val);
}

int egsy_int_en_set(unsigned int dev_id, union egsy_int_en_u *value)
{
	return egress_reg_set(dev_id, EGSY_INT_EN_ADDRESS, value->val);
}

int egsy_sa_exp_get(unsigned int dev_id, union egsy_sa_exp_u *value)
{
	return egress_reg_get(dev_id, EGSY_SA_EXP_ADDRESS, &value->val);
}

int egsy_sa_exp_set(unsigned int dev_id, union egsy_sa_exp_u *value)
{
	return egress_reg_set(dev_id, EGSY_SA_EXP_ADDRESS, value->val);
}

int egsy_sa_thr_get(unsigned int dev_id, union egsy_sa_thr_u *value)
{
	return egress_reg_get(dev_id, EGSY_SA_THR_ADDRESS, &value->val);
}

int egsy_sa_thr_set(unsigned int dev_id, union egsy_sa_thr_u *value)
{
	return egress_reg_set(dev_id, EGSY_SA_THR_ADDRESS, value->val);
}

int egecc_err_reg_get(unsigned int dev_id, union egecc_err_reg_u *value)
{
	return egress_reg_get(dev_id, EGECC_ERR_REG_ADDRESS, &value->val);
}

int egecc_err_reg_set(unsigned int dev_id, union egecc_err_reg_u *value)
{
	return egress_reg_set(dev_id, EGECC_ERR_REG_ADDRESS, value->val);
}

int egprc_ecc_err1_addr_get(unsigned int dev_id,
			    union egprc_ecc_err1_addr_u *value)
{
	return egress_reg_get(dev_id, EGPRC_ECC_ERR1_ADDR_ADDRESS, &value->val);
}

int egprc_ecc_err1_addr_set(unsigned int dev_id,
			    union egprc_ecc_err1_addr_u *value)
{
	return egress_reg_set(dev_id, EGPRC_ECC_ERR1_ADDR_ADDRESS, value->val);
}

int egprc_ecc_err2_addr_get(unsigned int dev_id,
			    union egprc_ecc_err2_addr_u *value)
{
	return egress_reg_get(dev_id, EGPRC_ECC_ERR2_ADDR_ADDRESS, &value->val);
}

int egprc_ecc_err2_addr_set(unsigned int dev_id,
			    union egprc_ecc_err2_addr_u *value)
{
	return egress_reg_set(dev_id, EGPRC_ECC_ERR2_ADDR_ADDRESS, value->val);
}

int eglkup_ctlf_ecc_err_addr_get(unsigned int dev_id,
				 union eglkup_ctlf_ecc_err_addr_u *value)
{
	return egress_reg_get(dev_id, EGLKUP_CTLF_ECC_ERR_ADDR_ADDRESS,
			      &value->val);
}

int eglkup_ctlf_ecc_err_addr_set(unsigned int dev_id,
				 union eglkup_ctlf_ecc_err_addr_u *value)
{
	return egress_reg_set(dev_id, EGLKUP_CTLF_ECC_ERR_ADDR_ADDRESS,
			      value->val);
}

int pfmt_sc_sa_ecc_err_addr_get(unsigned int dev_id,
				union pfmt_sc_sa_ecc_err_addr_u *value)
{
	return egress_reg_get(dev_id, PFMT_SC_SA_ECC_ERR_ADDR_ADDRESS,
			      &value->val);
}

int pfmt_sc_sa_ecc_err_addr_set(unsigned int dev_id,
				union pfmt_sc_sa_ecc_err_addr_u *value)
{
	return egress_reg_set(dev_id, PFMT_SC_SA_ECC_ERR_ADDR_ADDRESS,
			      value->val);
}

int egsy_smib_ecc_err_addr_get(unsigned int dev_id,
			       union egsy_smib_ecc_err_addr_u *value)
{
	return egress_reg_get(dev_id, EGSY_SMIB_ECC_ERR_ADDR_ADDRESS,
			      &value->val);
}

int egsy_smib_ecc_err_addr_set(unsigned int dev_id,
			       union egsy_smib_ecc_err_addr_u *value)
{
	return egress_reg_set(dev_id, EGSY_SMIB_ECC_ERR_ADDR_ADDRESS,
			      value->val);
}

int egsy_enable_ecc_get(unsigned int dev_id, union egsy_enable_ecc_u *value)
{
	return egress_reg_get(dev_id, EGSY_ENABLE_ECC_ADDRESS, &value->val);
}

int egsy_enable_ecc_set(unsigned int dev_id, union egsy_enable_ecc_u *value)
{
	return egress_reg_set(dev_id, EGSY_ENABLE_ECC_ADDRESS, value->val);
}

int eg_table_cmd_get(unsigned int dev_id, union eg_table_cmd_u *value)
{
	return egress_reg_get(dev_id, EG_TABLE_CMD_ADDRESS, &value->val);
}

int eg_table_cmd_set(unsigned int dev_id, union eg_table_cmd_u *value)
{
	return egress_reg_set(dev_id, EG_TABLE_CMD_ADDRESS, value->val);
}

int eg_table_data_get(unsigned int dev_id, union eg_table_data_u *value)
{
	return egress_reg_get(dev_id, EG_TABLE_DATA_ADDRESS, &value->val);
}

int eg_table_data_set(unsigned int dev_id, union eg_table_data_u *value)
{
	return egress_reg_set(dev_id, EG_TABLE_DATA_ADDRESS, value->val);
}

int eg_indirect_table_set(unsigned int dev_id,
			  unsigned int table_type,
			  unsigned int index,
			  unsigned int entry_len, unsigned int *pentry)
{
	unsigned int cmd = 0;

	/* Update Table data */
	egress_reg_tbl_set(dev_id, EG_TABLE_DATA_ADDRESS, pentry, entry_len);

	/* Update Command word */
	cmd = (TABLE_WRITE_OP << 30) | (table_type << 12) | index;
	eg_table_cmd_set(dev_id, (union eg_table_cmd_u *)&cmd);

	return 0;
}

int eg_indirect_table_get(unsigned int dev_id,
			  unsigned int table_type,
			  unsigned int index,
			  unsigned int entry_len, unsigned int *pentry)
{
	unsigned int cmd = 0;

	/* Update Command word */
	cmd = (TABLE_READ_OP << 30) | (table_type << 12) | index;
	eg_table_cmd_set(dev_id, (union eg_table_cmd_u *)&cmd);

	/* Read Table data */
	egress_reg_tbl_get(dev_id, EG_TABLE_DATA_ADDRESS, pentry, entry_len);

	return 0;
}

int eg_ctl_filt_table_set(unsigned int dev_id,
			  unsigned int index, unsigned int *pentry)
{
	if ((index < EG_CTL_FILT_INDEX_MIN) || (index > EG_CTL_FILT_INDEX_MAX)) {
		return -1;
	}

	return eg_indirect_table_set(dev_id, EG_CTL_FILT_TABLE_TYPE, index,
				     EG_CTL_FILT_ENTRY_LEN, pentry);
}

int eg_ctl_filt_table_get(unsigned int dev_id,
			  unsigned int index, unsigned int *pentry)
{
	if ((index < EG_CTL_FILT_INDEX_MIN) || (index > EG_CTL_FILT_INDEX_MAX)) {
		return -1;
	}

	return eg_indirect_table_get(dev_id, EG_CTL_FILT_TABLE_TYPE, index,
				     EG_CTL_FILT_ENTRY_LEN, pentry);
}

int eg_class_lut_table_set(unsigned int dev_id,
			   unsigned int index, unsigned int *pentry)
{
	if ((index < EG_CLASS_LUT_INDEX_MIN)
	    || (index > EG_CLASS_LUT_INDEX_MAX)) {
		return -1;
	}

	return eg_indirect_table_set(dev_id, EG_CLASS_LUT_TABLE_TYPE, index,
				     EG_CLASS_LUT_ENTRY_LEN, pentry);
}

int eg_class_lut_table_get(unsigned int dev_id,
			   unsigned int index, unsigned int *pentry)
{
	if ((index < EG_CLASS_LUT_INDEX_MIN)
	    || (index > EG_CLASS_LUT_INDEX_MAX)) {
		return -1;
	}

	return eg_indirect_table_get(dev_id, EG_CLASS_LUT_TABLE_TYPE, index,
				     EG_CLASS_LUT_ENTRY_LEN, pentry);
}

int eg_sc_table_set(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry)
{
	if ((index < EG_SC_INDEX_MIN) || (index > EG_SC_INDEX_MAX)) {
		return -1;
	}

	return eg_indirect_table_set(dev_id, EG_SC_TABLE_TYPE, index,
				     EG_SC_ENTRY_LEN, pentry);
}

int eg_sc_table_get(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry)
{
	if ((index < EG_SC_INDEX_MIN) || (index > EG_SC_INDEX_MAX)) {
		return -1;
	}

	return eg_indirect_table_get(dev_id, EG_SC_TABLE_TYPE, index,
				     EG_SC_ENTRY_LEN, pentry);
}

int eg_sa_table_set(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry)
{
	if ((index < EG_SA_INDEX_MIN) || (index > EG_SA_INDEX_MAX)) {
		return -1;
	}

	return eg_indirect_table_set(dev_id, EG_SA_TABLE_TYPE, index,
				     EG_SA_ENTRY_LEN, pentry);
}

int eg_sa_table_get(unsigned int dev_id,
		    unsigned int index, unsigned int *pentry)
{
	if ((index < EG_SA_INDEX_MIN) || (index > EG_SA_INDEX_MAX)) {
		return -1;
	}

	return eg_indirect_table_get(dev_id, EG_SA_TABLE_TYPE, index,
				     EG_SA_ENTRY_LEN, pentry);
}

int eg_sak_table_set(unsigned int dev_id,
		     unsigned int index, unsigned int *pentry)
{
	if ((index < EG_SAK_INDEX_MIN) || (index > EG_SAK_INDEX_MAX)) {
		return -1;
	}

	return eg_indirect_table_set(dev_id, EG_SAK_TABLE_TYPE, index,
				     EG_SAK_ENTRY_LEN, pentry);
}

int eg_sak_table_get(unsigned int dev_id,
		     unsigned int index, unsigned int *pentry)
{
	if ((index < EG_SAK_INDEX_MIN) || (index > EG_SAK_INDEX_MAX)) {
		return -1;
	}

	return eg_indirect_table_get(dev_id, EG_SAK_TABLE_TYPE, index,
				     EG_SAK_ENTRY_LEN, pentry);
}

int eg_smib_table_sc_sa_get(unsigned int dev_id,
			    unsigned int index, unsigned int *pentry)
{
	int i;
	int entry_offset = 0;
	unsigned int cmd = 0;

	if ((index < EG_SMIB_INDEX_MIN) || (index > EG_SMIB_INDEX_MAX)) {
		return -1;
	}

	for (i = 0; i < EG_SMIB_ENTRY_LEN; i++) {
		/* Update Command word */
		cmd =
		    (TABLE_READ_OP << 30) | (EG_SMIB_TABLE_TYPE << 12) |
		    ((index * 8) + i);
		eg_table_cmd_set(dev_id, (union eg_table_cmd_u *)&cmd);

		/* Read Table data */
		egress_reg_tbl_get(dev_id, EG_TABLE_DATA_ADDRESS,
				   (pentry + entry_offset), 2);
		entry_offset += 2;
	}

	return 0;
}

int eg_smib_table_common_get(unsigned int dev_id, unsigned int *pentry)
{
	int i;
	int entry_offset = 0;
	unsigned int cmd = 0;

	for (i = EG_SMIB_COMMON_INDEX_MIN; i < EG_SMIB_COMMON_INDEX_MAX + 1; i++) {
		/* Update Command word */
		cmd = (TABLE_READ_OP << 30) | (EG_SMIB_TABLE_TYPE << 12) | i;
		eg_table_cmd_set(dev_id, (union eg_table_cmd_u *)&cmd);

		/* Read Table data */
		egress_reg_tbl_get(dev_id, EG_TABLE_DATA_ADDRESS,
				   (pentry + entry_offset), 2);
		entry_offset += 2;
	}

	return 0;
}

int emac1_reg_get(unsigned int dev_id,
		  unsigned int reg_addr, unsigned int *pvalue)
{
	return dal_reg_read(dev_id, reg_addr + EMAC1_BASE_ADDR, pvalue);
}

int emac1_reg_tbl_get(unsigned int dev_id,
		      unsigned int reg_addr,
		      unsigned int *pvalue, unsigned int width)
{
	return dal_reg_tbl_read(dev_id, reg_addr + EMAC1_BASE_ADDR,
				pvalue, width);
}

int emac1_reg_set(unsigned int dev_id,
		  unsigned int reg_addr, unsigned int value)
{
	return dal_reg_write(dev_id, reg_addr + EMAC1_BASE_ADDR, value);
}

int emac1_reg_tbl_set(unsigned int dev_id,
		      unsigned int reg_addr,
		      unsigned int *pvalue, unsigned int width)
{
	return dal_reg_tbl_write(dev_id, reg_addr + EMAC1_BASE_ADDR,
				 pvalue, width);
}

int emac1_rev_get(unsigned int dev_id, union emac1_rev_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_REV_ADDRESS, &value->val);
}

int emac1_rev_set(unsigned int dev_id, union emac1_rev_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_scratch_get(unsigned int dev_id, union emac1_scratch_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_SCRATCH_ADDRESS, &value->val);
}

int emac1_scratch_set(unsigned int dev_id, union emac1_scratch_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_SCRATCH_ADDRESS, value->val);
}

int emac1_command_config_get(unsigned int dev_id,
			     union emac1_command_config_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_COMMAND_CONFIG_ADDRESS, &value->val);
}

int emac1_command_config_set(unsigned int dev_id,
			     union emac1_command_config_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_COMMAND_CONFIG_ADDRESS, value->val);
}

int emac1_mac_0_get(unsigned int dev_id, union emac1_mac_0_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_MAC_0_ADDRESS, &value->val);
}

int emac1_mac_0_set(unsigned int dev_id, union emac1_mac_0_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_MAC_0_ADDRESS, value->val);
}

int emac1_mac_1_get(unsigned int dev_id, union emac1_mac_1_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_MAC_1_ADDRESS, &value->val);
}

int emac1_mac_1_set(unsigned int dev_id, union emac1_mac_1_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_MAC_1_ADDRESS, value->val);
}

int emac1_frm_length_get(unsigned int dev_id, union emac1_frm_length_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_FRM_LENGTH_ADDRESS, &value->val);
}

int emac1_frm_length_set(unsigned int dev_id, union emac1_frm_length_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_FRM_LENGTH_ADDRESS, value->val);
}

int emac1_pause_quant_get(unsigned int dev_id, union emac1_pause_quant_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_PAUSE_QUANT_ADDRESS, &value->val);
}

int emac1_pause_quant_set(unsigned int dev_id, union emac1_pause_quant_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_PAUSE_QUANT_ADDRESS, value->val);
}

int emac1_rx_section_empty_get(unsigned int dev_id,
			       union emac1_rx_section_empty_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_RX_SECTION_EMPTY_ADDRESS,
			     &value->val);
}

int emac1_rx_section_empty_set(unsigned int dev_id,
			       union emac1_rx_section_empty_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_RX_SECTION_EMPTY_ADDRESS,
			     value->val);
}

int emac1_rx_section_full_get(unsigned int dev_id,
			      union emac1_rx_section_full_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_RX_SECTION_FULL_ADDRESS,
			     &value->val);
}

int emac1_rx_section_full_set(unsigned int dev_id,
			      union emac1_rx_section_full_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_RX_SECTION_FULL_ADDRESS, value->val);
}

int emac1_tx_section_empty_get(unsigned int dev_id,
			       union emac1_tx_section_empty_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_TX_SECTION_EMPTY_ADDRESS,
			     &value->val);
}

int emac1_tx_section_empty_set(unsigned int dev_id,
			       union emac1_tx_section_empty_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_TX_SECTION_EMPTY_ADDRESS,
			     value->val);
}

int emac1_tx_section_full_get(unsigned int dev_id,
			      union emac1_tx_section_full_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_TX_SECTION_FULL_ADDRESS,
			     &value->val);
}

int emac1_tx_section_full_set(unsigned int dev_id,
			      union emac1_tx_section_full_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_TX_SECTION_FULL_ADDRESS, value->val);
}

int emac1_rx_almost_empty_get(unsigned int dev_id,
			      union emac1_rx_almost_empty_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_RX_ALMOST_EMPTY_ADDRESS,
			     &value->val);
}

int emac1_rx_almost_empty_set(unsigned int dev_id,
			      union emac1_rx_almost_empty_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_RX_ALMOST_EMPTY_ADDRESS, value->val);
}

int emac1_rx_almost_full_get(unsigned int dev_id,
			     union emac1_rx_almost_full_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_RX_ALMOST_FULL_ADDRESS, &value->val);
}

int emac1_rx_almost_full_set(unsigned int dev_id,
			     union emac1_rx_almost_full_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_RX_ALMOST_FULL_ADDRESS, value->val);
}

int emac1_tx_almost_empty_get(unsigned int dev_id,
			      union emac1_tx_almost_empty_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_TX_ALMOST_EMPTY_ADDRESS,
			     &value->val);
}

int emac1_tx_almost_empty_set(unsigned int dev_id,
			      union emac1_tx_almost_empty_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_TX_ALMOST_EMPTY_ADDRESS, value->val);
}

int emac1_tx_almost_full_get(unsigned int dev_id,
			     union emac1_tx_almost_full_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_TX_ALMOST_FULL_ADDRESS, &value->val);
}

int emac1_tx_almost_full_set(unsigned int dev_id,
			     union emac1_tx_almost_full_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_TX_ALMOST_FULL_ADDRESS, value->val);
}

int emac1_mdio_addr0_get(unsigned int dev_id, union emac1_mdio_addr0_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_MDIO_ADDR0_ADDRESS, &value->val);
}

int emac1_mdio_addr0_set(unsigned int dev_id, union emac1_mdio_addr0_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_MDIO_ADDR0_ADDRESS, value->val);
}

int emac1_mdio_addr1_get(unsigned int dev_id, union emac1_mdio_addr1_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_MDIO_ADDR1_ADDRESS, &value->val);
}

int emac1_mdio_addr1_set(unsigned int dev_id, union emac1_mdio_addr1_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_MDIO_ADDR1_ADDRESS, value->val);
}

int emac1_reg_status_get(unsigned int dev_id, union emac1_reg_status_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_REG_STATUS_ADDRESS, &value->val);
}

int emac1_reg_status_set(unsigned int dev_id, union emac1_reg_status_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_tx_ipg_length_get(unsigned int dev_id,
			    union emac1_tx_ipg_length_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_TX_IPG_LENGTH_ADDRESS, &value->val);
}

int emac1_tx_ipg_length_set(unsigned int dev_id,
			    union emac1_tx_ipg_length_u *value)
{
	return emac1_reg_set(dev_id, EMAC1_TX_IPG_LENGTH_ADDRESS, value->val);
}

int emac1_amacid_get(unsigned int dev_id, union emac1_amacid_u *value)
{
	return emac1_reg_tbl_get(dev_id, EMAC1_AMACID_ADDRESS, value->val, 2);
}

int emac1_amacid_set(unsigned int dev_id, union emac1_amacid_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_aframestransmittedok_get(unsigned int dev_id,
				   union emac1_aframestransmittedok_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_AFRAMESTRANSMITTEDOK_ADDRESS,
			     &value->val);
}

int emac1_aframestransmittedok_set(unsigned int dev_id,
				   union emac1_aframestransmittedok_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_aframesreceivedok_get(unsigned int dev_id,
				union emac1_aframesreceivedok_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_AFRAMESRECEIVEDOK_ADDRESS,
			     &value->val);
}

int emac1_aframesreceivedok_set(unsigned int dev_id,
				union emac1_aframesreceivedok_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_aframechecksequenceerrors_get(unsigned int dev_id,
					union emac1_aframechecksequenceerrors_u
					*value)
{
	return emac1_reg_get(dev_id, EMAC1_AFRAMECHECKSEQUENCEERRORS_ADDRESS,
			     &value->val);
}

int emac1_aframechecksequenceerrors_set(unsigned int dev_id,
					union emac1_aframechecksequenceerrors_u
					*value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_aalignmenterrors_get(unsigned int dev_id,
			       union emac1_aalignmenterrors_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_AALIGNMENTERRORS_ADDRESS,
			     &value->val);
}

int emac1_aalignmenterrors_set(unsigned int dev_id,
			       union emac1_aalignmenterrors_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_aoctetstransmittedok_get(unsigned int dev_id,
				   union emac1_aoctetstransmittedok_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_AOCTETSTRANSMITTEDOK_ADDRESS,
			     &value->val);
}

int emac1_aoctetstransmittedok_set(unsigned int dev_id,
				   union emac1_aoctetstransmittedok_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_aoctetsreceivedok_get(unsigned int dev_id,
				union emac1_aoctetsreceivedok_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_AOCTETSRECEIVEDOK_ADDRESS,
			     &value->val);
}

int emac1_aoctetsreceivedok_set(unsigned int dev_id,
				union emac1_aoctetsreceivedok_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_atxpausemacctrlframes_get(unsigned int dev_id,
				    union emac1_atxpausemacctrlframes_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_ATXPAUSEMACCTRLFRAMES_ADDRESS,
			     &value->val);
}

int emac1_atxpausemacctrlframes_set(unsigned int dev_id,
				    union emac1_atxpausemacctrlframes_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_arxpausemacctrlframes_get(unsigned int dev_id,
				    union emac1_arxpausemacctrlframes_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_ARXPAUSEMACCTRLFRAMES_ADDRESS,
			     &value->val);
}

int emac1_arxpausemacctrlframes_set(unsigned int dev_id,
				    union emac1_arxpausemacctrlframes_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_ifinerrors_get(unsigned int dev_id, union emac1_ifinerrors_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_IFINERRORS_ADDRESS, &value->val);
}

int emac1_ifinerrors_set(unsigned int dev_id, union emac1_ifinerrors_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_ifouterrors_get(unsigned int dev_id, union emac1_ifouterrors_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_IFOUTERRORS_ADDRESS, &value->val);
}

int emac1_ifouterrors_set(unsigned int dev_id, union emac1_ifouterrors_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_ifinucastpkts_get(unsigned int dev_id,
			    union emac1_ifinucastpkts_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_IFINUCASTPKTS_ADDRESS, &value->val);
}

int emac1_ifinucastpkts_set(unsigned int dev_id,
			    union emac1_ifinucastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_ifinmulticastpkts_get(unsigned int dev_id,
				union emac1_ifinmulticastpkts_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_IFINMULTICASTPKTS_ADDRESS,
			     &value->val);
}

int emac1_ifinmulticastpkts_set(unsigned int dev_id,
				union emac1_ifinmulticastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_ifinbroadcastpkts_get(unsigned int dev_id,
				union emac1_ifinbroadcastpkts_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_IFINBROADCASTPKTS_ADDRESS,
			     &value->val);
}

int emac1_ifinbroadcastpkts_set(unsigned int dev_id,
				union emac1_ifinbroadcastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_ifoutdiscards_get(unsigned int dev_id,
			    union emac1_ifoutdiscards_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_IFOUTDISCARDS_ADDRESS, &value->val);
}

int emac1_ifoutdiscards_set(unsigned int dev_id,
			    union emac1_ifoutdiscards_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_ifoutucastpkts_get(unsigned int dev_id,
			     union emac1_ifoutucastpkts_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_IFOUTUCASTPKTS_ADDRESS, &value->val);
}

int emac1_ifoutucastpkts_set(unsigned int dev_id,
			     union emac1_ifoutucastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_ifoutmulticastpkts_get(unsigned int dev_id,
				 union emac1_ifoutmulticastpkts_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_IFOUTMULTICASTPKTS_ADDRESS,
			     &value->val);
}

int emac1_ifoutmulticastpkts_set(unsigned int dev_id,
				 union emac1_ifoutmulticastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_ifoutbroadcastpkts_get(unsigned int dev_id,
				 union emac1_ifoutbroadcastpkts_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_IFOUTBROADCASTPKTS_ADDRESS,
			     &value->val);
}

int emac1_ifoutbroadcastpkts_set(unsigned int dev_id,
				 union emac1_ifoutbroadcastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatsdropevents_get(unsigned int dev_id,
				   union emac1_etherstatsdropevents_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSDROPEVENTS_ADDRESS,
			     &value->val);
}

int emac1_etherstatsdropevents_set(unsigned int dev_id,
				   union emac1_etherstatsdropevents_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatsoctets_get(unsigned int dev_id,
			       union emac1_etherstatsoctets_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSOCTETS_ADDRESS,
			     &value->val);
}

int emac1_etherstatsoctets_set(unsigned int dev_id,
			       union emac1_etherstatsoctets_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatspkts_get(unsigned int dev_id,
			     union emac1_etherstatspkts_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSPKTS_ADDRESS, &value->val);
}

int emac1_etherstatspkts_set(unsigned int dev_id,
			     union emac1_etherstatspkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatsundersizepkts_get(unsigned int dev_id,
				      union emac1_etherstatsundersizepkts_u
				      *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSUNDERSIZEPKTS_ADDRESS,
			     &value->val);
}

int emac1_etherstatsundersizepkts_set(unsigned int dev_id,
				      union emac1_etherstatsundersizepkts_u
				      *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatsoversizepkts_get(unsigned int dev_id,
				     union emac1_etherstatsoversizepkts_u
				     *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSOVERSIZEPKTS_ADDRESS,
			     &value->val);
}

int emac1_etherstatsoversizepkts_set(unsigned int dev_id,
				     union emac1_etherstatsoversizepkts_u
				     *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatspkts64octets_get(unsigned int dev_id,
				     union emac1_etherstatspkts64octets_u
				     *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSPKTS64OCTETS_ADDRESS,
			     &value->val);
}

int emac1_etherstatspkts64octets_set(unsigned int dev_id,
				     union emac1_etherstatspkts64octets_u
				     *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatspkts65to127octets_get(unsigned int dev_id,
					  union
					  emac1_etherstatspkts65to127octets_u
					  *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSPKTS65TO127OCTETS_ADDRESS,
			     &value->val);
}

int emac1_etherstatspkts65to127octets_set(unsigned int dev_id,
					  union
					  emac1_etherstatspkts65to127octets_u
					  *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatspkts128to255octets_get(unsigned int dev_id,
					   union
					   emac1_etherstatspkts128to255octets_u
					   *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSPKTS128TO255OCTETS_ADDRESS,
			     &value->val);
}

int emac1_etherstatspkts128to255octets_set(unsigned int dev_id,
					   union
					   emac1_etherstatspkts128to255octets_u
					   *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatspkts256to511octets_get(unsigned int dev_id,
					   union
					   emac1_etherstatspkts256to511octets_u
					   *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSPKTS256TO511OCTETS_ADDRESS,
			     &value->val);
}

int emac1_etherstatspkts256to511octets_set(unsigned int dev_id,
					   union
					   emac1_etherstatspkts256to511octets_u
					   *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatspkts512to1023octets_get(unsigned int dev_id,
					    union
					    emac1_etherstatspkts512to1023octets_u
					    *value)
{
	return emac1_reg_get(dev_id,
			     EMAC1_ETHERSTATSPKTS512TO1023OCTETS_ADDRESS,
			     &value->val);
}

int emac1_etherstatspkts512to1023octets_set(unsigned int dev_id,
					    union
					    emac1_etherstatspkts512to1023octets_u
					    *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatspkts1024to1518octets_get(unsigned int dev_id,
					     union
					     emac1_etherstatspkts1024to1518octets_u
					     *value)
{
	return emac1_reg_get(dev_id,
			     EMAC1_ETHERSTATSPKTS1024TO1518OCTETS_ADDRESS,
			     &value->val);
}

int emac1_etherstatspkts1024to1518octets_set(unsigned int dev_id,
					     union
					     emac1_etherstatspkts1024to1518octets_u
					     *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatspkts1519toxoctets_get(unsigned int dev_id,
					  union
					  emac1_etherstatspkts1519toxoctets_u
					  *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSPKTS1519TOXOCTETS_ADDRESS,
			     &value->val);
}

int emac1_etherstatspkts1519toxoctets_set(unsigned int dev_id,
					  union
					  emac1_etherstatspkts1519toxoctets_u
					  *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatsjabbers_get(unsigned int dev_id,
				union emac1_etherstatsjabbers_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSJABBERS_ADDRESS,
			     &value->val);
}

int emac1_etherstatsjabbers_set(unsigned int dev_id,
				union emac1_etherstatsjabbers_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac1_etherstatsfragments_get(unsigned int dev_id,
				  union emac1_etherstatsfragments_u *value)
{
	return emac1_reg_get(dev_id, EMAC1_ETHERSTATSFRAGMENTS_ADDRESS,
			     &value->val);
}

int emac1_etherstatsfragments_set(unsigned int dev_id,
				  union emac1_etherstatsfragments_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_reg_get(unsigned int dev_id,
		  unsigned int reg_addr, unsigned int *pvalue)
{
	return dal_reg_read(dev_id, reg_addr + EMAC2_BASE_ADDR, pvalue);
}

int emac2_reg_tbl_get(unsigned int dev_id,
		      unsigned int reg_addr,
		      unsigned int *pvalue, unsigned int width)
{
	return dal_reg_tbl_read(dev_id, reg_addr + EMAC2_BASE_ADDR,
				pvalue, width);
}

int emac2_reg_set(unsigned int dev_id,
		  unsigned int reg_addr, unsigned int value)
{
	return dal_reg_write(dev_id, reg_addr + EMAC2_BASE_ADDR, value);
}

int emac2_reg_tbl_set(unsigned int dev_id,
		      unsigned int reg_addr,
		      unsigned int *pvalue, unsigned int width)
{
	return dal_reg_tbl_write(dev_id, reg_addr + EMAC2_BASE_ADDR,
				 pvalue, width);
}

int emac2_rev_get(unsigned int dev_id, union emac2_rev_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_REV_ADDRESS, &value->val);
}

int emac2_rev_set(unsigned int dev_id, union emac2_rev_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_scratch_get(unsigned int dev_id, union emac2_scratch_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_SCRATCH_ADDRESS, &value->val);
}

int emac2_scratch_set(unsigned int dev_id, union emac2_scratch_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_SCRATCH_ADDRESS, value->val);
}

int emac2_command_config_get(unsigned int dev_id,
			     union emac2_command_config_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_COMMAND_CONFIG_ADDRESS, &value->val);
}

int emac2_command_config_set(unsigned int dev_id,
			     union emac2_command_config_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_COMMAND_CONFIG_ADDRESS, value->val);
}

int emac2_mac_0_get(unsigned int dev_id, union emac2_mac_0_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_MAC_0_ADDRESS, &value->val);
}

int emac2_mac_0_set(unsigned int dev_id, union emac2_mac_0_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_MAC_0_ADDRESS, value->val);
}

int emac2_mac_1_get(unsigned int dev_id, union emac2_mac_1_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_MAC_1_ADDRESS, &value->val);
}

int emac2_mac_1_set(unsigned int dev_id, union emac2_mac_1_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_MAC_1_ADDRESS, value->val);
}

int emac2_frm_length_get(unsigned int dev_id, union emac2_frm_length_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_FRM_LENGTH_ADDRESS, &value->val);
}

int emac2_frm_length_set(unsigned int dev_id, union emac2_frm_length_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_FRM_LENGTH_ADDRESS, value->val);
}

int emac2_pause_quant_get(unsigned int dev_id, union emac2_pause_quant_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_PAUSE_QUANT_ADDRESS, &value->val);
}

int emac2_pause_quant_set(unsigned int dev_id, union emac2_pause_quant_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_PAUSE_QUANT_ADDRESS, value->val);
}

int emac2_rx_section_empty_get(unsigned int dev_id,
			       union emac2_rx_section_empty_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_RX_SECTION_EMPTY_ADDRESS,
			     &value->val);
}

int emac2_rx_section_empty_set(unsigned int dev_id,
			       union emac2_rx_section_empty_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_RX_SECTION_EMPTY_ADDRESS,
			     value->val);
}

int emac2_rx_section_full_get(unsigned int dev_id,
			      union emac2_rx_section_full_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_RX_SECTION_FULL_ADDRESS,
			     &value->val);
}

int emac2_rx_section_full_set(unsigned int dev_id,
			      union emac2_rx_section_full_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_RX_SECTION_FULL_ADDRESS, value->val);
}

int emac2_tx_section_empty_get(unsigned int dev_id,
			       union emac2_tx_section_empty_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_TX_SECTION_EMPTY_ADDRESS,
			     &value->val);
}

int emac2_tx_section_empty_set(unsigned int dev_id,
			       union emac2_tx_section_empty_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_TX_SECTION_EMPTY_ADDRESS,
			     value->val);
}

int emac2_tx_section_full_get(unsigned int dev_id,
			      union emac2_tx_section_full_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_TX_SECTION_FULL_ADDRESS,
			     &value->val);
}

int emac2_tx_section_full_set(unsigned int dev_id,
			      union emac2_tx_section_full_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_TX_SECTION_FULL_ADDRESS, value->val);
}

int emac2_rx_almost_empty_get(unsigned int dev_id,
			      union emac2_rx_almost_empty_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_RX_ALMOST_EMPTY_ADDRESS,
			     &value->val);
}

int emac2_rx_almost_empty_set(unsigned int dev_id,
			      union emac2_rx_almost_empty_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_RX_ALMOST_EMPTY_ADDRESS, value->val);
}

int emac2_rx_almost_full_get(unsigned int dev_id,
			     union emac2_rx_almost_full_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_RX_ALMOST_FULL_ADDRESS, &value->val);
}

int emac2_rx_almost_full_set(unsigned int dev_id,
			     union emac2_rx_almost_full_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_RX_ALMOST_FULL_ADDRESS, value->val);
}

int emac2_tx_almost_empty_get(unsigned int dev_id,
			      union emac2_tx_almost_empty_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_TX_ALMOST_EMPTY_ADDRESS,
			     &value->val);
}

int emac2_tx_almost_empty_set(unsigned int dev_id,
			      union emac2_tx_almost_empty_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_TX_ALMOST_EMPTY_ADDRESS, value->val);
}

int emac2_tx_almost_full_get(unsigned int dev_id,
			     union emac2_tx_almost_full_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_TX_ALMOST_FULL_ADDRESS, &value->val);
}

int emac2_tx_almost_full_set(unsigned int dev_id,
			     union emac2_tx_almost_full_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_TX_ALMOST_FULL_ADDRESS, value->val);
}

int emac2_mdio_addr0_get(unsigned int dev_id, union emac2_mdio_addr0_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_MDIO_ADDR0_ADDRESS, &value->val);
}

int emac2_mdio_addr0_set(unsigned int dev_id, union emac2_mdio_addr0_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_MDIO_ADDR0_ADDRESS, value->val);
}

int emac2_mdio_addr1_get(unsigned int dev_id, union emac2_mdio_addr1_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_MDIO_ADDR1_ADDRESS, &value->val);
}

int emac2_mdio_addr1_set(unsigned int dev_id, union emac2_mdio_addr1_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_MDIO_ADDR1_ADDRESS, value->val);
}

int emac2_reg_status_get(unsigned int dev_id, union emac2_reg_status_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_REG_STATUS_ADDRESS, &value->val);
}

int emac2_reg_status_set(unsigned int dev_id, union emac2_reg_status_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_tx_ipg_length_get(unsigned int dev_id,
			    union emac2_tx_ipg_length_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_TX_IPG_LENGTH_ADDRESS, &value->val);
}

int emac2_tx_ipg_length_set(unsigned int dev_id,
			    union emac2_tx_ipg_length_u *value)
{
	return emac2_reg_set(dev_id, EMAC2_TX_IPG_LENGTH_ADDRESS, value->val);
}

int emac2_amacid_get(unsigned int dev_id, union emac2_amacid_u *value)
{
	return emac2_reg_tbl_get(dev_id, EMAC2_AMACID_ADDRESS, value->val, 2);
}

int emac2_amacid_set(unsigned int dev_id, union emac2_amacid_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_aframestransmittedok_get(unsigned int dev_id,
				   union emac2_aframestransmittedok_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_AFRAMESTRANSMITTEDOK_ADDRESS,
			     &value->val);
}

int emac2_aframestransmittedok_set(unsigned int dev_id,
				   union emac2_aframestransmittedok_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_aframesreceivedok_get(unsigned int dev_id,
				union emac2_aframesreceivedok_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_AFRAMESRECEIVEDOK_ADDRESS,
			     &value->val);
}

int emac2_aframesreceivedok_set(unsigned int dev_id,
				union emac2_aframesreceivedok_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_aframechecksequenceerrors_get(unsigned int dev_id,
					union emac2_aframechecksequenceerrors_u
					*value)
{
	return emac2_reg_get(dev_id, EMAC2_AFRAMECHECKSEQUENCEERRORS_ADDRESS,
			     &value->val);
}

int emac2_aframechecksequenceerrors_set(unsigned int dev_id,
					union emac2_aframechecksequenceerrors_u
					*value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_aalignmenterrors_get(unsigned int dev_id,
			       union emac2_aalignmenterrors_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_AALIGNMENTERRORS_ADDRESS,
			     &value->val);
}

int emac2_aalignmenterrors_set(unsigned int dev_id,
			       union emac2_aalignmenterrors_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_aoctetstransmittedok_get(unsigned int dev_id,
				   union emac2_aoctetstransmittedok_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_AOCTETSTRANSMITTEDOK_ADDRESS,
			     &value->val);
}

int emac2_aoctetstransmittedok_set(unsigned int dev_id,
				   union emac2_aoctetstransmittedok_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_aoctetsreceivedok_get(unsigned int dev_id,
				union emac2_aoctetsreceivedok_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_AOCTETSRECEIVEDOK_ADDRESS,
			     &value->val);
}

int emac2_aoctetsreceivedok_set(unsigned int dev_id,
				union emac2_aoctetsreceivedok_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_atxpausemacctrlframes_get(unsigned int dev_id,
				    union emac2_atxpausemacctrlframes_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_ATXPAUSEMACCTRLFRAMES_ADDRESS,
			     &value->val);
}

int emac2_atxpausemacctrlframes_set(unsigned int dev_id,
				    union emac2_atxpausemacctrlframes_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_arxpausemacctrlframes_get(unsigned int dev_id,
				    union emac2_arxpausemacctrlframes_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_ARXPAUSEMACCTRLFRAMES_ADDRESS,
			     &value->val);
}

int emac2_arxpausemacctrlframes_set(unsigned int dev_id,
				    union emac2_arxpausemacctrlframes_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_ifinerrors_get(unsigned int dev_id, union emac2_ifinerrors_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_IFINERRORS_ADDRESS, &value->val);
}

int emac2_ifinerrors_set(unsigned int dev_id, union emac2_ifinerrors_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_ifouterrors_get(unsigned int dev_id, union emac2_ifouterrors_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_IFOUTERRORS_ADDRESS, &value->val);
}

int emac2_ifouterrors_set(unsigned int dev_id, union emac2_ifouterrors_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_ifinucastpkts_get(unsigned int dev_id,
			    union emac2_ifinucastpkts_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_IFINUCASTPKTS_ADDRESS, &value->val);
}

int emac2_ifinucastpkts_set(unsigned int dev_id,
			    union emac2_ifinucastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_ifinmulticastpkts_get(unsigned int dev_id,
				union emac2_ifinmulticastpkts_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_IFINMULTICASTPKTS_ADDRESS,
			     &value->val);
}

int emac2_ifinmulticastpkts_set(unsigned int dev_id,
				union emac2_ifinmulticastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_ifinbroadcastpkts_get(unsigned int dev_id,
				union emac2_ifinbroadcastpkts_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_IFINBROADCASTPKTS_ADDRESS,
			     &value->val);
}

int emac2_ifinbroadcastpkts_set(unsigned int dev_id,
				union emac2_ifinbroadcastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_ifoutdiscards_get(unsigned int dev_id,
			    union emac2_ifoutdiscards_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_IFOUTDISCARDS_ADDRESS, &value->val);
}

int emac2_ifoutdiscards_set(unsigned int dev_id,
			    union emac2_ifoutdiscards_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_ifoutucastpkts_get(unsigned int dev_id,
			     union emac2_ifoutucastpkts_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_IFOUTUCASTPKTS_ADDRESS, &value->val);
}

int emac2_ifoutucastpkts_set(unsigned int dev_id,
			     union emac2_ifoutucastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_ifoutmulticastpkts_get(unsigned int dev_id,
				 union emac2_ifoutmulticastpkts_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_IFOUTMULTICASTPKTS_ADDRESS,
			     &value->val);
}

int emac2_ifoutmulticastpkts_set(unsigned int dev_id,
				 union emac2_ifoutmulticastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_ifoutbroadcastpkts_get(unsigned int dev_id,
				 union emac2_ifoutbroadcastpkts_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_IFOUTBROADCASTPKTS_ADDRESS,
			     &value->val);
}

int emac2_ifoutbroadcastpkts_set(unsigned int dev_id,
				 union emac2_ifoutbroadcastpkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatsdropevents_get(unsigned int dev_id,
				   union emac2_etherstatsdropevents_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSDROPEVENTS_ADDRESS,
			     &value->val);
}

int emac2_etherstatsdropevents_set(unsigned int dev_id,
				   union emac2_etherstatsdropevents_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatsoctets_get(unsigned int dev_id,
			       union emac2_etherstatsoctets_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSOCTETS_ADDRESS,
			     &value->val);
}

int emac2_etherstatsoctets_set(unsigned int dev_id,
			       union emac2_etherstatsoctets_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatspkts_get(unsigned int dev_id,
			     union emac2_etherstatspkts_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSPKTS_ADDRESS, &value->val);
}

int emac2_etherstatspkts_set(unsigned int dev_id,
			     union emac2_etherstatspkts_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatsundersizepkts_get(unsigned int dev_id,
				      union emac2_etherstatsundersizepkts_u
				      *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSUNDERSIZEPKTS_ADDRESS,
			     &value->val);
}

int emac2_etherstatsundersizepkts_set(unsigned int dev_id,
				      union emac2_etherstatsundersizepkts_u
				      *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatsoversizepkts_get(unsigned int dev_id,
				     union emac2_etherstatsoversizepkts_u
				     *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSOVERSIZEPKTS_ADDRESS,
			     &value->val);
}

int emac2_etherstatsoversizepkts_set(unsigned int dev_id,
				     union emac2_etherstatsoversizepkts_u
				     *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatspkts64octets_get(unsigned int dev_id,
				     union emac2_etherstatspkts64octets_u
				     *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSPKTS64OCTETS_ADDRESS,
			     &value->val);
}

int emac2_etherstatspkts64octets_set(unsigned int dev_id,
				     union emac2_etherstatspkts64octets_u
				     *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatspkts65to127octets_get(unsigned int dev_id,
					  union
					  emac2_etherstatspkts65to127octets_u
					  *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSPKTS65TO127OCTETS_ADDRESS,
			     &value->val);
}

int emac2_etherstatspkts65to127octets_set(unsigned int dev_id,
					  union
					  emac2_etherstatspkts65to127octets_u
					  *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatspkts128to255octets_get(unsigned int dev_id,
					   union
					   emac2_etherstatspkts128to255octets_u
					   *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSPKTS128TO255OCTETS_ADDRESS,
			     &value->val);
}

int emac2_etherstatspkts128to255octets_set(unsigned int dev_id,
					   union
					   emac2_etherstatspkts128to255octets_u
					   *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatspkts256to511octets_get(unsigned int dev_id,
					   union
					   emac2_etherstatspkts256to511octets_u
					   *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSPKTS256TO511OCTETS_ADDRESS,
			     &value->val);
}

int emac2_etherstatspkts256to511octets_set(unsigned int dev_id,
					   union
					   emac2_etherstatspkts256to511octets_u
					   *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatspkts512to1023octets_get(unsigned int dev_id,
					    union
					    emac2_etherstatspkts512to1023octets_u
					    *value)
{
	return emac2_reg_get(dev_id,
			     EMAC2_ETHERSTATSPKTS512TO1023OCTETS_ADDRESS,
			     &value->val);
}

int emac2_etherstatspkts512to1023octets_set(unsigned int dev_id,
					    union
					    emac2_etherstatspkts512to1023octets_u
					    *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatspkts1024to1518octets_get(unsigned int dev_id,
					     union
					     emac2_etherstatspkts1024to1518octets_u
					     *value)
{
	return emac2_reg_get(dev_id,
			     EMAC2_ETHERSTATSPKTS1024TO1518OCTETS_ADDRESS,
			     &value->val);
}

int emac2_etherstatspkts1024to1518octets_set(unsigned int dev_id,
					     union
					     emac2_etherstatspkts1024to1518octets_u
					     *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatspkts1519toxoctets_get(unsigned int dev_id,
					  union
					  emac2_etherstatspkts1519toxoctets_u
					  *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSPKTS1519TOXOCTETS_ADDRESS,
			     &value->val);
}

int emac2_etherstatspkts1519toxoctets_set(unsigned int dev_id,
					  union
					  emac2_etherstatspkts1519toxoctets_u
					  *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatsjabbers_get(unsigned int dev_id,
				union emac2_etherstatsjabbers_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSJABBERS_ADDRESS,
			     &value->val);
}

int emac2_etherstatsjabbers_set(unsigned int dev_id,
				union emac2_etherstatsjabbers_u *value)
{
	return DAL_NOT_SUPPORT;
}

int emac2_etherstatsfragments_get(unsigned int dev_id,
				  union emac2_etherstatsfragments_u *value)
{
	return emac2_reg_get(dev_id, EMAC2_ETHERSTATSFRAGMENTS_ADDRESS,
			     &value->val);
}

int emac2_etherstatsfragments_set(unsigned int dev_id,
				  union emac2_etherstatsfragments_u *value)
{
	return DAL_NOT_SUPPORT;
}
