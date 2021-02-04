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

#include <linux/kernel.h>
#include <linux/module.h>
#include "nss_macsec_types.h"
#include "nss_macsec_register_api.h"
#include "nss_macsec_os.h"
#include "nss_macsec_emac.h"
#include "nss_macsec_secy_tx.h"
#include "nss_macsec_secy_rx.h"
#include "nss_macsec_utility.h"
#include "nss_macsec_mib.h"
#include "nss_macsec_secy.h"

fal_secy_cfg_t g_secy_cfg[FAL_SECY_ID_NUM_MAX];

#define EG_SCTRL_DROP_EN 0x1
#define EG_ECTRL_ENABLE  0xF

#define IG_SCTRL_DROP_EN 0x7
#define IG_ECTRL_ENABLE  0x103F


u32 nss_macsec_secy_reset(u32 secy_id)
{

	union egsy_l2sec_control_u ctrl;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	//nss_macsec_emac_reset(secy_id);

	/* tiger: it seems the software reset does not work, because
	   the tables are not clean */
	egsy_l2sec_control_get(secy_id, &ctrl);
	ctrl.bf.csr_egsy_swrst = 1;
	SHR_RET_ON_ERR(egsy_l2sec_control_set(secy_id, &ctrl));

	//tiger: no ingress reset?

	return ERROR_OK;
}

u32 nss_macsec_secy_tx_sw_reset(u32 secy_id)	//tiger: is this API necessary?
{
	return ERROR_OK;
}

u32 nss_macsec_secy_init(u32 secy_id)
{
	union egsy_emac_regs_u eg_emac;
	union insy_emac_regs_u in_emac;
	union egsy_sctrl_drop_en_u eg_drop;
	union egsy_ectrl_enable_u  eg_enable;
	union insy_sctrl_drop_en_u ig_drop;
	union insy_ectrl_en_u      ig_enable;
	union csr_igsy_ctrl_u reg_val;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	/* EMAC 1 & 2 reset (include disable) */
	nss_macsec_emac_reset(secy_id);
	mdelay(100);		/* delay 100 ms */

	/* EMAC 1 & 2 init */
	nss_macsec_emac_init(secy_id);

	/* L2sec shadow init */
	/* g_secy_cfg[secy_id].enable should be 0 because the
	   GMAC bypass is enable when module init */ ;
	memset(&(g_secy_cfg[secy_id]), 0, sizeof(fal_secy_cfg_t));

	/* L2sec init */
	nss_macsec_secy_sc_sa_mapping_mode_set(secy_id, FAL_SC_SA_MAP_1_1);
	nss_macsec_secy_cipher_suite_set(secy_id, FAL_CIPHER_SUITE_AES_GCM_128);
	nss_macsec_secy_mtu_set(secy_id, FAL_SECY_DEFAULT_MTU);

	/* L2sec MIB clear */
	nss_macsec_secy_rx_mib_clear(secy_id);
	nss_macsec_secy_tx_mib_clear(secy_id);

	eg_drop.bf.egsy_sctrl_drop_en = EG_SCTRL_DROP_EN;
	egsy_sctrl_drop_en_set(secy_id, &eg_drop);
	/* Configure Egress E-control register */
	eg_enable.bf.egsy_ectrl_en = EG_ECTRL_ENABLE;
	egsy_ectrl_enable_set(secy_id, &eg_enable);

	ig_drop.bf.insy_sctrl_drop_en = IG_SCTRL_DROP_EN;
	insy_sctrl_drop_en_set(secy_id, &ig_drop);

	/* Configure Ingress E-control register */
	ig_enable.bf.insy_ectrl_en = IG_ECTRL_ENABLE;
	insy_ectrl_en_set(secy_id, &ig_enable);

	/* Configure Ingress remove macsec tag */
	csr_igsy_ctrl_get(secy_id, &reg_val);
	reg_val.bf.csr_insy_remove_sectag = 1;
	csr_igsy_ctrl_set(secy_id, &reg_val);


	eg_emac.val = 0;
	eg_emac.bf.en_gen_pause = 0;
	eg_emac.bf.power_down_emac1 = 1;
	eg_emac.bf.resetemac1 = 1;
	egsy_emac_regs_set(secy_id, &eg_emac);
	in_emac.val = 0;
	in_emac.bf.en_gen_pause = 0;
	in_emac.bf.power_down_emac2 = 1;
	in_emac.bf.resetemac2 = 1;
	insy_emac_regs_set(secy_id, &in_emac);

	// tiger: clean tables here?
	nss_macsec_secy_tx_ctl_filt_clear_all(secy_id);
	nss_macsec_secy_tx_class_lut_clear_all(secy_id);
	nss_macsec_secy_tx_sc_del_all(secy_id);
	nss_macsec_secy_tx_sa_del_all(secy_id);
	nss_macsec_secy_rx_ctl_filt_clear_all(secy_id);
	nss_macsec_secy_rx_prc_lut_clear_all(secy_id);
	nss_macsec_secy_rx_sc_del_all(secy_id);
	nss_macsec_secy_rx_sa_del_all(secy_id);

	// tiger: clean FIFO

	/* EMAC 1 & 2 enable */
	nss_macsec_emac_enable(secy_id, TRUE);

	return ERROR_OK;
}

u32 nss_macsec_secy_sc_sa_mapping_mode_get(u32 secy_id,
					   fal_sc_sa_mapping_mode_e *pmode)
{
	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM)&& (pmode != NULL));

	*pmode = g_secy_cfg[secy_id].sc_sa_map_mode;

	return ERROR_OK;
}

u32 nss_macsec_secy_sc_sa_mapping_mode_set(u32 secy_id,
					   fal_sc_sa_mapping_mode_e mode)
{
	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	if (mode >= FAL_SC_SA_MAP_MAX) {
		return ERROR_PARAM;
	}

	g_secy_cfg[secy_id].sc_sa_map_mode = mode;

	return ERROR_OK;
}

u32 nss_macsec_secy_controlled_port_en_get(u32 secy_id, bool *penable)
{
	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	return ERROR_OK;
}

u32 nss_macsec_secy_controlled_port_en_set(u32 secy_id, bool enable)
{
	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	return ERROR_OK;
}

u32 nss_macsec_secy_ip_version_get(u32 secy_id, char *ver_str, u32 ver_str_len)
{
	union igsy_l2sec_version_u ig_ver;
	/* union egsy_l2sec_version_u eg_ver; */

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	igsy_l2sec_version_get(secy_id, &ig_ver);

	/* ig/eg version are same
	   egsy_l2sec_version_get(secy_id, &eg_ver);
	   osal_print("eg_ver=0x%x, ig_ver = 0x%x\r\n", eg_ver.val, ig_ver.val); */

	snprintf(ver_str, ver_str_len,
		 "ID:%d Version:%d Revision:%d",
		 ig_ver.bf.igsy_l2sec_id,
		 ig_ver.bf.igsy_l2sec_version, ig_ver.bf.igsy_l2sec_revision);

	return ERROR_OK;
}

u32 nss_macsec_secy_cipher_suite_get(u32 secy_id,
				     fal_cipher_suite_e *p_cipher_suite)
{
	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM)&& (p_cipher_suite != NULL));

	*p_cipher_suite = g_secy_cfg[secy_id].cipher_suite;

	return ERROR_OK;
}

u32 nss_macsec_secy_cipher_suite_set(u32 secy_id,
				     fal_cipher_suite_e cipher_suite)
{
	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	if (cipher_suite != FAL_CIPHER_SUITE_AES_GCM_128) {
		return ERROR_PARAM;
	}

	return ERROR_OK;
}

u32 nss_macsec_secy_mtu_get(u32 secy_id, u32 *pmtu)
{
	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM)&& (pmtu != NULL));

	*pmtu = g_secy_cfg[secy_id].mtu;

	return ERROR_OK;
}

u32 nss_macsec_secy_mtu_set(u32 secy_id, u32 mtu)
{
	union csr_egsy_mtu_u eg_mtu;
	union csr_igsy_mtu_u ig_mtu;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	if (mtu > FAL_TX_RX_MTU_MAX) {
		return ERROR_PARAM;
	}

	g_secy_cfg[secy_id].mtu = mtu;

	eg_mtu.bf.csr_egsy_mtu = mtu;
	eg_mtu.bf.unctrl_csr_egsy_mtu = mtu;
	csr_egsy_mtu_set(secy_id, &eg_mtu);
	ig_mtu.bf.csr_igsy_mtu = mtu;
	ig_mtu.bf.unctrl_csr_igsy_mtu = mtu;
	csr_igsy_mtu_set(secy_id, &ig_mtu);

	return ERROR_OK;
}

u32 nss_macsec_secy_en_get(u32 secy_id, bool *penable)
{
	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM)&& (penable != NULL));

	*penable = g_secy_cfg[secy_id].enable;

	return ERROR_OK;
}

u32 nss_macsec_secy_en_set(u32 secy_id, bool enable)
{
	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	if(nss_macsec_device_exist(secy_id) != ERROR_OK)
		return ERROR_ERROR;

	if (enable != g_secy_cfg[secy_id].enable) {
		if (enable) {
			nss_macsec_secy_init(secy_id);
		}

		/* call GMAC API to set by bypass status */
		nss_macsec_bypass_en_set(secy_id + 1, !enable);

		g_secy_cfg[secy_id].enable = enable;
	}

	return ERROR_OK;
}
