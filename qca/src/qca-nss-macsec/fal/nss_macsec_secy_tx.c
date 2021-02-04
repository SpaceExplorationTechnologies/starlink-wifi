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

#include "nss_macsec_types.h"
#include "nss_macsec_register_api.h"
#include "nss_macsec.h"
#include "nss_macsec_secy.h"
#include "nss_macsec_utility.h"
#include "nss_macsec_secy_tx.h"

u32 nss_macsec_secy_tx_reg_get(u32 secy_id, u32 addr, u32 *pvalue)
{
	return egress_reg_get(secy_id, addr, pvalue);
}

u32 nss_macsec_secy_tx_reg_set(u32 secy_id, u32 addr, u32 value)
{
	return egress_reg_set(secy_id, addr, value);
}

u32 nss_macsec_secy_tx_drop_sc_sa_invalid_get(u32 secy_id, bool *penable)
{
	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) && (penable != NULL));

	SHR_RET_ON_ERR(egsy_l2sec_control_get(secy_id, &ctrl));
	*penable = ctrl.bf.csr_egsy_drop_sasc_invalid;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_drop_sc_sa_invalid_set(u32 secy_id, bool enable)
{
	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK(secy_id < FAL_SECY_ID_NUM);

	SHR_RET_ON_ERR(egsy_l2sec_control_get(secy_id, &ctrl));

	if (ctrl.bf.csr_egsy_drop_sasc_invalid != enable) {
		ctrl.bf.csr_egsy_drop_sasc_invalid = enable;
		SHR_RET_ON_ERR(egsy_l2sec_control_set(secy_id, &ctrl));
	}

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_unmatched_use_sc_0_get(u32 secy_id, bool *penable)
{
	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) && (penable != NULL));

	SHR_RET_ON_ERR(egsy_l2sec_control_get(secy_id, &ctrl));
	*penable = ctrl.bf.csr_unmatched_use_sc_0;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_unmatched_use_sc_0_set(u32 secy_id, bool enable)
{
	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK(secy_id < FAL_SECY_ID_NUM);

	SHR_RET_ON_ERR(egsy_l2sec_control_get(secy_id, &ctrl));

	if (ctrl.bf.csr_unmatched_use_sc_0 != enable) {
		ctrl.bf.csr_unmatched_use_sc_0 = enable;
		SHR_RET_ON_ERR(egsy_l2sec_control_set(secy_id, &ctrl));
	}

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_gcm_start_get(u32 secy_id, bool *penable)
{
	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) && (penable != NULL));

	SHR_RET_ON_ERR(egsy_l2sec_control_get(secy_id, &ctrl));
	*penable = ctrl.bf.csr_egsy_gcm_start;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_gcm_start_set(u32 secy_id, bool enable)
{
	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK(secy_id < FAL_SECY_ID_NUM);

	SHR_RET_ON_ERR(egsy_l2sec_control_get(secy_id, &ctrl));

	if (ctrl.bf.csr_egsy_gcm_start != enable) {
		ctrl.bf.csr_egsy_gcm_start = enable;
		SHR_RET_ON_ERR(egsy_l2sec_control_set(secy_id, &ctrl));
	}

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_drop_class_miss_get(u32 secy_id, bool *penable)
{
	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) && (penable != NULL));

	SHR_RET_ON_ERR(egsy_l2sec_control_get(secy_id, &ctrl));
	*penable = ctrl.bf.csr_egsy_drop_egprc_miss;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_drop_class_miss_set(u32 secy_id, bool enable)
{
	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK(secy_id < FAL_SECY_ID_NUM);

	SHR_RET_ON_ERR(egsy_l2sec_control_get(secy_id, &ctrl));

	if (ctrl.bf.csr_egsy_drop_egprc_miss != enable) {
		ctrl.bf.csr_egsy_drop_egprc_miss = enable;
		SHR_RET_ON_ERR(egsy_l2sec_control_set(secy_id, &ctrl));
	}

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_drop_kay_pkt_get(u32 secy_id, bool *penable)
{
	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) && (penable != NULL));

	SHR_RET_ON_ERR(egsy_l2sec_control_get(secy_id, &ctrl));
	*penable = ctrl.bf.csr_egsy_drop_kay_pkt;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_drop_kay_pkt_set(u32 secy_id, bool enable)
{
	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK(secy_id < FAL_SECY_ID_NUM);

	SHR_RET_ON_ERR(egsy_l2sec_control_get(secy_id, &ctrl));

	if (ctrl.bf.csr_egsy_drop_kay_pkt != enable) {
		ctrl.bf.csr_egsy_drop_kay_pkt = enable;
		SHR_RET_ON_ERR(egsy_l2sec_control_set(secy_id, &ctrl));
	}

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_ctl_filt_get(u32 secy_id, u32 filt_id,
				    fal_tx_ctl_filt_t *pfilt)
{
	struct eg_ctl_filt ctl_entry;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(filt_id < FAL_TX_CTL_FILT_HW_NUM) && (pfilt != NULL));

	SHR_RET_ON_ERR(eg_ctl_filt_table_get
		       (secy_id, filt_id, (u32 *) (&ctl_entry)));

	memset(pfilt, 0, sizeof(fal_tx_ctl_filt_t));
	pfilt->bypass = !(ctl_entry.action);
	pfilt->match_type = ctl_entry.match_type;
	pfilt->match_mask = ctl_entry.match_mask;
	pfilt->ether_type_da_range = ctl_entry.ethertype_da_range;
	pfilt->sa_da_addr[0] = (u8)(ctl_entry.sa_da_1>>8);
	pfilt->sa_da_addr[1] = (u8)(ctl_entry.sa_da_1);
	pfilt->sa_da_addr[2] = (u8)(ctl_entry.sa_da_0>>24);
	pfilt->sa_da_addr[3] = (u8)(ctl_entry.sa_da_0>>16);
	pfilt->sa_da_addr[4] = (u8)(ctl_entry.sa_da_0>>8);
	pfilt->sa_da_addr[5] = (u8)(ctl_entry.sa_da_0);

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_ctl_filt_set(u32 secy_id, u32 filt_id,
				    fal_tx_ctl_filt_t *pfilt)
{
	struct eg_ctl_filt ctl_entry;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(filt_id < FAL_TX_CTL_FILT_NUM) && (pfilt != NULL));

	memset(&ctl_entry, 0, sizeof(ctl_entry));

	ctl_entry.action = !(pfilt->bypass);
	ctl_entry.match_type = pfilt->match_type;
	ctl_entry.match_mask = pfilt->match_mask;
	ctl_entry.ethertype_da_range = pfilt->ether_type_da_range;
	ctl_entry.sa_da_0 = (pfilt->sa_da_addr[2]<<24)|
				(pfilt->sa_da_addr[3]<<16)|
				(pfilt->sa_da_addr[4]<<8)|pfilt->sa_da_addr[5];
	ctl_entry.sa_da_1 = (pfilt->sa_da_addr[0]<<8)|pfilt->sa_da_addr[1];

/*
osal_print("sa_da_addr = %02x:%02x:%02x:%02x:%02x:%02x\r\n",
           pfilt->sa_da_addr[0],
           pfilt->sa_da_addr[1],
           pfilt->sa_da_addr[2],
           pfilt->sa_da_addr[3],
           pfilt->sa_da_addr[4],
           pfilt->sa_da_addr[5]
           );
osal_print("ctl_entry.match_mask = 0x%04x\r\n", ctl_entry.match_mask);
osal_print("*(u32 *)(&(pfilt->sa_da_addr[0])) = 0x%08x\r\n", *(u32 *)(&(pfilt->sa_da_addr[0])));
osal_print("ctl_entry.sa_da_0 = 0x%08x\r\n", ctl_entry.sa_da_0);
osal_print("*(u16 *)(&(pfilt->sa_da_addr[4])) = 0x%08x\r\n", *(u16 *)(&(pfilt->sa_da_addr[4])));
osal_print("ctl_entry.sa_da_1 = 0x%04x\r\n", ctl_entry.sa_da_1);
*/

	SHR_RET_ON_ERR(eg_ctl_filt_table_set
		       (secy_id, filt_id, (u32 *) (&ctl_entry)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_ctl_filt_clear(u32 secy_id, u32 filt_id)
{
	struct eg_ctl_filt ctl_entry;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM)
			&& (filt_id < FAL_TX_CTL_FILT_NUM));

	memset(&ctl_entry, 0, sizeof(union eg_ctl_filt_u));

	SHR_RET_ON_ERR(eg_ctl_filt_table_set
		       (secy_id, filt_id, (u32 *) (&ctl_entry)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_ctl_filt_clear_all(u32 secy_id)
{
	int i;

	SHR_PARAM_CHECK(secy_id < FAL_SECY_ID_NUM);

	for (i = 0; i < FAL_TX_CTL_FILT_NUM; i++) {
		nss_macsec_secy_tx_ctl_filt_clear(secy_id, i);
	}

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_class_lut_get(u32 secy_id, u32 index,
				     fal_tx_class_lut_t *pentry)
{
	struct eg_class_lut egc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(index < FAL_TX_CLASS_LUT_NUM) && (pentry != NULL));

	SHR_RET_ON_ERR(eg_class_lut_table_get(secy_id, index, (u32 *) (&egc)));

	memset(pentry, 0, sizeof(fal_tx_class_lut_t));

	pentry->valid = egc.valid;
	pentry->action = egc.action;
	pentry->channel = fal_tx_sc_id_2_channel(secy_id, egc.sc_index);

	pentry->da_mask = egc.da_mask;
	pentry->da[5] = egc.da_0;
	pentry->da[4] = (u8)egc.da_1;
	pentry->da[3] = (u8)(egc.da_1>>8);
	pentry->da[2] = (u8)(egc.da_1>>16);
	pentry->da[1] = (u8)(egc.da_1>>24);
	pentry->da[0] = egc.da_2;

	pentry->sa_mask = egc.sa_mask;
	pentry->sa[5] = (u8)egc.sa_0;
	pentry->sa[4] = (u8)(egc.sa_0>>8);
	pentry->sa[3] = (u8)(egc.sa_0>>16);
	pentry->sa[2] = (u8)(egc.sa_1);
	pentry->sa[1] = (u8)(egc.sa_1>>8);
	pentry->sa[0] = (u8)(egc.sa_1>>16);

	pentry->ether_type_mask = egc.ethertype_mask;
	pentry->ether_type = (egc.ethertype_1 << 8) + egc.ethertype_0;

	pentry->udf0_valid = egc.byte0_mask;
	pentry->udf0_location =
	    ((egc.byte0_location_1) << 3) + egc.byte0_location_0;
	pentry->udf0_byte = egc.byte0;

	pentry->udf1_valid = egc.byte1_mask;
	pentry->udf1_location = egc.byte1_location;
	pentry->udf1_byte = egc.byte1;

	pentry->udf2_valid = egc.byte2_mask;
	pentry->udf2_location = egc.byte2_location;
	pentry->udf2_byte = egc.byte2;

	pentry->udf3_valid = egc.byte3_mask;
	pentry->udf3_location = egc.byte3_location;
	pentry->udf3_byte = egc.byte3;

	pentry->vlan_valid_mask = egc.vlan_valid_mask;
	pentry->vlan_valid = egc.vlan_valid;

	pentry->vlan_up_mask = egc.vlan_up_mask;
	pentry->vlan_up = egc.vlan_up;

	pentry->vlan_id_mask = egc.vlan_id_mask;
	pentry->vlan_id = egc.vlan_id;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_class_lut_set(u32 secy_id, u32 index,
				     fal_tx_class_lut_t *pentry)
{
	struct eg_class_lut egc;
	u8 *psci = NULL;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(index < FAL_TX_CLASS_LUT_NUM) && (pentry != NULL));

	memset(&egc, 0, sizeof(egc));

	//tiger: other fields

	egc.valid = (pentry->valid) ? 1 : 0;
	egc.action = pentry->action;
	egc.sc_index = fal_tx_channel_2_sc_id(secy_id, pentry->channel);

	psci = g_secy_cfg[secy_id].tx_sc[pentry->channel].sci;

	egc.sci_2 = (psci[0]<<16)|(psci[1]<<8)|psci[2];
	egc.sci_1 = (psci[3]<<24)|(psci[4]<<16)|(psci[5]<<8)|psci[6];
	egc.sci_0 = psci[7];

	egc.da_mask = pentry->da_mask & 0x3f;
	egc.da_0 = pentry->da[5];
	egc.da_1 = (pentry->da[1]<<24)|(pentry->da[2]<<16)|(pentry->da[3]<<8)|(pentry->da[4]);
	egc.da_2 = pentry->da[0];

	egc.sa_mask = pentry->sa_mask & 0x3f;
	egc.sa_0 = (pentry->sa[3]<<16)|(pentry->sa[4]<<8)|(pentry->sa[5]);
	egc.sa_1 = (pentry->sa[0]<<16)|(pentry->sa[1]<<8)|(pentry->sa[2]);

	egc.ethertype_mask = pentry->ether_type_mask & 0x3;
	egc.ethertype_1 = (pentry->ether_type & 0xff00) >> 8;
	egc.ethertype_0 = pentry->ether_type & 0x00ff;

	egc.byte0_mask = (pentry->udf0_valid) ? 1 : 0;
	egc.byte0_location_0 = pentry->udf0_location & 0x7;
	egc.byte0_location_1 = (pentry->udf0_location >>3) & 0x7;
	egc.byte0 = pentry->udf0_byte;

	egc.byte1_mask = (pentry->udf1_valid) ? 1 : 0;
	egc.byte1_location = pentry->udf1_location & 0x3f;
	egc.byte1 = pentry->udf1_byte;

	egc.byte2_mask = (pentry->udf2_valid) ? 1 : 0;
	egc.byte2_location = pentry->udf2_location & 0x3f;
	egc.byte2 = pentry->udf2_byte;

	egc.byte3_mask = (pentry->udf3_valid) ? 1 : 0;
	egc.byte3_location = pentry->udf3_location & 0x3f;
	egc.byte3 = pentry->udf3_byte;

	egc.vlan_valid_mask = pentry->vlan_valid_mask & 0x1;
	egc.vlan_valid = (pentry->vlan_valid) ? 1 : 0;

	egc.vlan_up_mask = pentry->vlan_up_mask & 0x1;
	egc.vlan_up = pentry->vlan_up & 0x7;

	egc.vlan_id_mask = pentry->vlan_id_mask & 0x3;
	egc.vlan_id = pentry->vlan_id;

	if (FAL_SECY_SC_SA_MODE(secy_id) == FAL_SC_SA_MAP_1_1)
		egc.sc_sa_association = 0x3;
	else if (FAL_SECY_SC_SA_MODE(secy_id) == FAL_SC_SA_MAP_1_2)
		egc.sc_sa_association = 0x2;
	else if (FAL_SECY_SC_SA_MODE(secy_id) == FAL_SC_SA_MAP_1_4)
		egc.sc_sa_association = 0x0;

	SHR_RET_ON_ERR(eg_class_lut_table_set(secy_id, index, (u32 *) (&egc)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_class_lut_clear(u32 secy_id, u32 index)
{
	struct eg_class_lut egc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(index < FAL_TX_CLASS_LUT_NUM));

	memset(&egc, 0, sizeof(egc));

	SHR_RET_ON_ERR(eg_class_lut_table_set(secy_id, index, (u32 *) (&egc)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_class_lut_clear_all(u32 secy_id)
{
	int i;

	for (i = 0; i < FAL_TX_CLASS_LUT_NUM; i++) {
		nss_macsec_secy_tx_class_lut_clear(secy_id, i);
	}

	return ERROR_OK;
}

static u32 nss_macsec_secy_tx_class_lut_sci_update(u32 secy_id,
		u8 sc_id, u8 *sci)
{
	int i;
	struct eg_class_lut egc;

	memset(&egc, 0 , sizeof(egc));

	for (i = 0; i < FAL_TX_CLASS_LUT_NUM; i++) {
		SHR_RET_ON_ERR(eg_class_lut_table_get(secy_id, i,
				(u32 *)(&egc)));
		if (egc.sc_index == sc_id) {
			egc.sci_2 = (sci[0]<<16)|(sci[1]<<8)|sci[2];
			egc.sci_1 =
				(sci[3]<<24)|(sci[4]<<16)|(sci[5]<<8)|sci[6];
			egc.sci_0 = sci[7];
			SHR_RET_ON_ERR(eg_class_lut_table_set(secy_id, i,
					(u32 *)(&egc)));
		}
	}

	return ERROR_OK;
}


u32 nss_macsec_secy_tx_sc_create(u32 secy_id, u32 channel,
				 u8 *psci, u32 sci_len)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(psci != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	memset(&sc, 0, sizeof(sc));
	sc.valid = 1;
	sc.sak_len = 0;		/* 128 bits */

	SHR_RET_ON_ERR(eg_sc_table_set(secy_id, sc_id, (u32 *) (&sc)));
/*
	osal_print("%s[%d]\r\n", __FUNCTION__, __LINE__);
	osal_print("sci: %02x%02x%02x%02x:%02x%02x%02x%02x\r\n",
		   psci[0], psci[1], psci[2], psci[3], psci[4], psci[5],
		   psci[6], psci[7]);
*/
	memcpy(g_secy_cfg[secy_id].tx_sc[channel].sci, psci,
	       ((sci_len > FAL_SCI_LEN) ? FAL_SCI_LEN : sci_len));

	nss_macsec_secy_tx_class_lut_sci_update(secy_id, sc_id, psci);

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_en_get(u32 secy_id, u32 channel, bool *penable)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(penable != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	*penable = sc.valid;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_en_set(u32 secy_id, u32 channel, bool enable)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	if (sc.valid != (enable ? 1 : 0)) {
		sc.valid = (enable ? 1 : 0);
		SHR_RET_ON_ERR(eg_sc_table_set(secy_id, sc_id, (u32 *) (&sc)));
	}

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_del(u32 secy_id, u32 channel)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	memset(&sc, 0, sizeof(sc));
	SHR_RET_ON_ERR(eg_sc_table_set(secy_id, sc_id, (u32 *) (&sc)));

	memset(g_secy_cfg[secy_id].tx_sc[channel].sci, 0, FAL_SCI_LEN);

	//tiger: delete all class entries point to this SC?

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_del_all(u32 secy_id)
{
	u32 sc_id = 0;
	struct eg_sc sc;
	int ret = 0;

	SHR_PARAM_CHECK(secy_id < FAL_SECY_ID_NUM);

	memset(&sc, 0, sizeof(sc));

	for (sc_id = EG_SC_INDEX_MIN; sc_id <= EG_SC_INDEX_MAX; sc_id++) {
		ret += eg_sc_table_set(secy_id, sc_id, (u32 *) (&sc));
	}

	return ret;
}

u32 nss_macsec_secy_tx_sc_an_get(u32 secy_id, u32 channel, u32 *pan)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(pan != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	*pan = sc.current_an;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_an_set(u32 secy_id, u32 channel, u32 an)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	sc.current_an = an;
	SHR_RET_ON_ERR(eg_sc_table_set(secy_id, sc_id, (u32 *) (&sc)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_an_roll_over_en_get(u32 secy_id, u32 channel,
					      bool *penable)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(penable != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	*penable = sc.enable_an_roll_over;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_an_roll_over_en_set(u32 secy_id, u32 channel,
					      bool enable)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	sc.enable_an_roll_over = enable ? 1 : 0;
	SHR_RET_ON_ERR(eg_sc_table_set(secy_id, sc_id, (u32 *) (&sc)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_in_used_get(u32 secy_id, u32 channel,
				      bool *p_in_used)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(p_in_used != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	*p_in_used = sc.receiving;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_tci_7_2_get(u32 secy_id, u32 channel, u8 *ptci)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(ptci != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	*ptci = sc.tci_7_2;

	return ERROR_OK;
}

static int nss_macsec_tci_check(u8 tci)
{
	if((tci & 0x1c) != 0x8 &&
		(tci & 0x1c) != 0x10 &&
		(tci & 0x1c) != 0x14)
		return ERROR_PARAM;
	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_tci_7_2_set(u32 secy_id, u32 channel, u8 tci)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(nss_macsec_tci_check(tci) == ERROR_OK));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	sc.tci_7_2 = tci & 0x3f;
	SHR_RET_ON_ERR(eg_sc_table_set(secy_id, sc_id, (u32 *) (&sc)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_confidentiality_offset_get(u32 secy_id, u32 channel,
						     u32 *poffset)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(poffset != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	*poffset = sc.confidentiality_offset;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_confidentiality_offset_set(u32 secy_id, u32 channel,
						     u32 offset)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	sc.confidentiality_offset = offset & 0xff;
	SHR_RET_ON_ERR(eg_sc_table_set(secy_id, sc_id, (u32 *) (&sc)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_protect_get(u32 secy_id, u32 channel, bool *penable)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(penable != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	*penable = sc.protect_frames;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_protect_set(u32 secy_id, u32 channel, bool enable)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	sc.protect_frames = enable ? 1 : 0;
	SHR_RET_ON_ERR(eg_sc_table_set(secy_id, sc_id, (u32 *) (&sc)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_sci_get(u32 secy_id, u32 channel,
				  u8 *psci, u32 sci_len)
{
	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(psci != NULL));

	memcpy(psci, g_secy_cfg[secy_id].tx_sc[channel].sci,
	       ((sci_len > FAL_SCI_LEN) ? FAL_SCI_LEN : sci_len));
/*
	osal_print("%s[%d]\r\n", __FUNCTION__, __LINE__);
	osal_print("sci: %02x%02x%02x%02x:%02x%02x%02x%02x\r\n",
		   psci[0], psci[1], psci[2], psci[3], psci[4], psci[5],
		   psci[6], psci[7]);
*/
	return ERROR_OK;
}

/*
u32 nss_macsec_secy_tx_sc_sci_set(u32 secy_id, u32 channel, u8 *psci)
{
    SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
                    (channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
                    (psci != NULL));

    memcpy(g_secy_cfg[secy_id].tx_sci[channel], psci, FAL_SCI_LEN);

    return ERROR_OK;
}
*/
u32 nss_macsec_secy_tx_sc_start_stop_time_get(u32 secy_id, u32 channel,
					      u32 *p_start_time,
					      u32 *p_stop_time)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(p_start_time != NULL) && (p_stop_time != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	*p_start_time = sc.start_time;
	*p_stop_time = sc.stop_time;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sc_start_stop_time_set(u32 secy_id, u32 channel,
					      u32 start_time, u32 stop_time)
{
	u32 sc_id = 0;
	struct eg_sc sc;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);

	SHR_RET_ON_ERR(eg_sc_table_get(secy_id, sc_id, (u32 *) (&sc)));

	sc.start_time = start_time;
	sc.stop_time = stop_time;
	SHR_RET_ON_ERR(eg_sc_table_set(secy_id, sc_id, (u32 *) (&sc)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sa_create(u32 secy_id, u32 channel, u32 an)
{
	u32 sc_id = 0;
	u32 sa_id = 0;
	struct eg_sa sa;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sa_id = EG_SA_INDEX_MIN + sc_id + an;

	memset(&sa, 0, sizeof(sa));
	sa.valid = 1;

	SHR_RET_ON_ERR(eg_sa_table_set(secy_id, sa_id, (u32 *) (&sa)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sa_en_get(u32 secy_id, u32 channel, u32 an,
				 bool *penable)
{
	u32 sc_id = 0;
	u32 sa_id = 0;
	struct eg_sa sa;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)) &&
			(penable != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sa_id = EG_SA_INDEX_MIN + sc_id + an;

	SHR_RET_ON_ERR(eg_sa_table_get(secy_id, sa_id, (u32 *) (&sa)));
	*penable = sa.valid;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sa_en_set(u32 secy_id, u32 channel, u32 an, bool enable)
{
	u32 sc_id = 0;
	u32 sa_id = 0;
	struct eg_sa sa;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sa_id = EG_SA_INDEX_MIN + sc_id + an;

	SHR_RET_ON_ERR(eg_sa_table_get(secy_id, sa_id, (u32 *) (&sa)));

	sa.valid = enable;
	SHR_RET_ON_ERR(eg_sa_table_set(secy_id, sa_id, (u32 *) (&sa)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sa_del(u32 secy_id, u32 channel, u32 an)
{
	u32 sc_id = 0;
	u32 sa_id = 0;
	struct eg_sa sa;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sa_id = EG_SA_INDEX_MIN + sc_id + an;

	memset(&sa, 0, sizeof(sa));
	//tiger: fresh?

	SHR_RET_ON_ERR(eg_sa_table_set(secy_id, sa_id, (u32 *) (&sa)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sa_del_all(u32 secy_id)
{
	int i = 0;
	struct eg_sa sa;

	memset(&sa, 0, sizeof(sa));

	for (i = EG_SA_INDEX_MIN; i <= EG_SA_INDEX_MAX; i++) {
		SHR_RET_ON_ERR(eg_sa_table_set(secy_id, i, (u32 *) (&sa)));
	}

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sa_next_pn_get(u32 secy_id, u32 channel,
				      u32 an, u32 *p_next_pn)
{
	u32 sc_id = 0;
	u32 sa_id = 0;
	struct eg_sa sa;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)) &&
			(p_next_pn != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sa_id = EG_SA_INDEX_MIN + sc_id + an;

	SHR_RET_ON_ERR(eg_sa_table_get(secy_id, sa_id, (u32 *) (&sa)));

	*p_next_pn = sa.next_pn;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sa_next_pn_set(u32 secy_id, u32 channel,
				      u32 an, u32 next_pn)
{
	u32 sc_id = 0;
	u32 sa_id = 0;
	struct eg_sa sa;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sa_id = EG_SA_INDEX_MIN + sc_id + an;

	SHR_RET_ON_ERR(eg_sa_table_get(secy_id, sa_id, (u32 *) (&sa)));

	sa.next_pn = next_pn;
	SHR_RET_ON_ERR(eg_sa_table_set(secy_id, sa_id, (u32 *) (&sa)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sa_in_used_get(u32 secy_id, u32 channel,
				      u32 an, bool *p_in_used)
{
	u32 sc_id = 0;
	u32 sa_id = 0;
	struct eg_sa sa;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)) &&
			(p_in_used != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sa_id = EG_SA_INDEX_MIN + sc_id + an;

	SHR_RET_ON_ERR(eg_sa_table_get(secy_id, sa_id, (u32 *) (&sa)));

	*p_in_used = (sa.fresh == 0);	//tiger: fresh is for in used status or NOT?

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sa_start_stop_time_get(u32 secy_id, u32 channel, u32 an,
					      u32 *p_start_time,
					      u32 *p_stop_time)
{
	u32 sc_id = 0;
	u32 sa_id = 0;
	struct eg_sa sa;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)) &&
			(p_start_time != NULL) && (p_stop_time != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sa_id = EG_SA_INDEX_MIN + sc_id + an;

	SHR_RET_ON_ERR(eg_sa_table_get(secy_id, sa_id, (u32 *) (&sa)));

	*p_start_time = sa.start_time;
	*p_stop_time = sa.stop_time;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sa_start_stop_time_set(u32 secy_id, u32 channel, u32 an,
					      u32 start_time, u32 stop_time)
{
	u32 sc_id = 0;
	u32 sa_id = 0;
	struct eg_sa sa;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sa_id = EG_SA_INDEX_MIN + sc_id + an;

	SHR_RET_ON_ERR(eg_sa_table_get(secy_id, sa_id, (u32 *) (&sa)));

	sa.start_time = start_time;
	sa.stop_time = stop_time;
	SHR_RET_ON_ERR(eg_sa_table_set(secy_id, sa_id, (u32 *) (&sa)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sak_get(u32 secy_id, u32 channel,
			       u32 an, fal_tx_sak_t *pentry)
{
	u32 sc_id = 0;
	u32 sak_id = 0;
	struct eg_sak sak;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)) &&
			(pentry != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sak_id = EG_SAK_INDEX_MIN + sc_id + an;

	SHR_RET_ON_ERR(eg_sak_table_get(secy_id, sak_id, (u32 *) (&sak)));

	memcpy(pentry->sak, &sak, FAL_SAK_DEFAULT_LEN);

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sak_set(u32 secy_id, u32 channel,
			       u32 an, fal_tx_sak_t *pentry)
{
	u32 sc_id = 0;
	u32 sak_id = 0;
	struct eg_sak sak;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(channel < FAL_SECY_CHANNEL_NUM(secy_id)) &&
			(an < FAL_SECY_SA_NUM_PER_SC(secy_id)) &&
			(pentry != NULL));

	sc_id = fal_tx_channel_2_sc_id(secy_id, channel);
	sak_id = EG_SAK_INDEX_MIN + sc_id + an;

	memcpy(&sak, pentry->sak, FAL_SAK_DEFAULT_LEN);
	SHR_RET_ON_ERR(eg_sak_table_set(secy_id, sak_id, (u32 *) (&sak)));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_qtag_parse_get(u32 secy_id, fal_tx_vlan_parse_t *pentry)
{
	union csr_egsy_vlan_cp_tag_u value;
	union csr_egsy_vlan_tpid1_u tpid;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(pentry != NULL));

	value.val = 0;
	SHR_RET_ON_ERR(csr_egsy_vlan_cp_tag_get(secy_id,  &value));
	pentry->parse_en = value.bf.csr_egsy_vlan_cp_tag_parse_qtag;

	tpid.val = 0;
	SHR_RET_ON_ERR(csr_egsy_vlan_tpid1_get(secy_id, &tpid));
	pentry->tpid = tpid.bf.csr_egsy_vlan_tpid1;

	return ERROR_OK;
}


u32 nss_macsec_secy_tx_qtag_parse_set(u32 secy_id, fal_tx_vlan_parse_t *pentry)
{
	union csr_egsy_vlan_cp_tag_u value;
	union csr_egsy_vlan_tpid1_u tpid;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(pentry != NULL));

	value.val = 0;
	SHR_RET_ON_ERR(csr_egsy_vlan_cp_tag_get(secy_id,  &value));
	value.bf.csr_egsy_vlan_cp_tag_parse_qtag = pentry->parse_en;
	SHR_RET_ON_ERR(csr_egsy_vlan_cp_tag_set(secy_id,  &value));

	tpid.val = 0;
	tpid.bf.csr_egsy_vlan_tpid1 = pentry->tpid;
	SHR_RET_ON_ERR(csr_egsy_vlan_tpid1_set(secy_id, &tpid));

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_stag_parse_get(u32 secy_id, fal_tx_vlan_parse_t *pentry)
{
	union csr_egsy_vlan_cp_tag_u value;
	union csr_egsy_vlan_tpid0_u tpid;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(pentry != NULL));

	value.val = 0;
	SHR_RET_ON_ERR(csr_egsy_vlan_cp_tag_get(secy_id,  &value));
	pentry->parse_en = value.bf.csr_egsy_vlan_cp_tag_parse_stag;

	tpid.val = 0;
	SHR_RET_ON_ERR(csr_egsy_vlan_tpid0_get(secy_id, &tpid));
	pentry->tpid = tpid.bf.csr_egsy_vlan_tpid0;
	return ERROR_OK;
}



u32 nss_macsec_secy_tx_stag_parse_set(u32 secy_id, fal_tx_vlan_parse_t *pentry)
{
	union csr_egsy_vlan_cp_tag_u value;
	union csr_egsy_vlan_tpid0_u tpid;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM) &&
			(pentry != NULL));

	value.val = 0;
	SHR_RET_ON_ERR(csr_egsy_vlan_cp_tag_get(secy_id,  &value));
	value.bf.csr_egsy_vlan_cp_tag_parse_stag = pentry->parse_en;
	SHR_RET_ON_ERR(csr_egsy_vlan_cp_tag_set(secy_id,  &value));

	tpid.val = 0;
	tpid.bf.csr_egsy_vlan_tpid0 = pentry->tpid;
	SHR_RET_ON_ERR(csr_egsy_vlan_tpid0_set(secy_id, &tpid));

	return ERROR_OK;
}


u32 nss_macsec_secy_tx_pn_threshold_get(u32 secy_id, u32 *p_pn_threshold)
{
	union csr_egsy_pn_thr_u value;

	value.val = 0;
	SHR_RET_ON_ERR(csr_egsy_pn_thr_get(secy_id, &value));

	*p_pn_threshold = value.bf.csr_pn_thr;

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_pn_threshold_set(u32 secy_id, u32 pn_threshold)
{
	union csr_egsy_pn_thr_u value;

	value.val = 0;
	value.bf.csr_pn_thr = pn_threshold;

	SHR_RET_ON_ERR(csr_egsy_pn_thr_set(secy_id, &value));

	return ERROR_OK;
}
