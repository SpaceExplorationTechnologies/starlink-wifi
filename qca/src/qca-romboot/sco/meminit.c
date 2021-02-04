/*
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <asm/types.h>
#include <asm/addrspace.h>
#include <apb_map.h>
#include <ath_chip.h>
#include "rom.addrs.h"

#define uint8_t		__u8
#define uint16_t	__u16
#define uint32_t	__u32

#define prmsg		printf

/*
 * We check for size in 4M increments
 */
#define ATH_MAX_DDR_SIZE		(256 * 1024 * 1024)
#define ATH_DDR_SIZE_INCR		(4 * 1024 * 1024)

int
ath_ddr_find_size(void)
{
	uint8_t  *p = (uint8_t *)KSEG1, pat = 0x77;
	int i;

#define max_i		(ATH_MAX_DDR_SIZE / ATH_DDR_SIZE_INCR)

	*p = pat;

	for(i = 1; (i < max_i); i++) {
		*(p + i * ATH_DDR_SIZE_INCR) = (uint8_t)(i);
		if (*p != pat) {
			break;
		}
	}

	return ((i < max_i) ? (i * ATH_DDR_SIZE_INCR) : ATH_MAX_DDR_SIZE);
}

void
ath_usb1_initial_config(void)
{
#define unset(a)	(~(a))

	ath_reg_wr_nf(SWITCH_CLOCK_SPARE_ADDRESS,
		ath_reg_rd(SWITCH_CLOCK_SPARE_ADDRESS) |
		SWITCH_CLOCK_SPARE_USB_REFCLK_FREQ_SEL_SET(5));
	udelay(1000);

	ath_reg_rmw_set(RST_RESET_ADDRESS,
				RST_RESET_USB_PHY_SUSPEND_OVERRIDE_SET(1));
	udelay(1000);
	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_USB_PHY_RESET_SET(1));
	udelay(1000);
	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_USB_PHY_ARESET_SET(1));
	udelay(1000);
	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_USB_HOST_RESET_SET(1));
	udelay(1000);

	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_USB_PHY_PLL_PWD_EXT_SET(1));
	udelay(10);

	ath_reg_rmw_set(RST_RESET2_ADDRESS, RST_RESET2_USB1_EXT_PWR_SEQ_SET(1));
	udelay(10);
}

void
ath_usb2_initial_config(void)
{
	ath_reg_rmw_set(RST_RESET2_ADDRESS, RST_RESET2_USB2_MODE_SET(1));
	udelay(10);
	ath_reg_rmw_set(RST_RESET2_ADDRESS,
				RST_RESET2_USB_PHY2_SUSPEND_OVERRIDE_SET(1));
	udelay(1000);
	ath_reg_rmw_clear(RST_RESET2_ADDRESS, RST_RESET2_USB_PHY2_RESET_SET(1));
	udelay(1000);
	ath_reg_rmw_clear(RST_RESET2_ADDRESS, RST_RESET2_USB_PHY2_ARESET_SET(1));
	udelay(1000);
	ath_reg_rmw_clear(RST_RESET2_ADDRESS, RST_RESET2_USB_HOST2_RESET_SET(1));
	udelay(1000);

	ath_reg_rmw_clear(RST_RESET2_ADDRESS, RST_RESET2_USB_PHY2_PLL_PWD_EXT_SET(1));
	udelay(10);

	ath_reg_rmw_set(RST_RESET2_ADDRESS, RST_RESET2_USB2_EXT_PWR_SEQ_SET(1));
	udelay(10);
}


#ifdef CONFIG_ATH_EMULATION
void
ath_emu_mem_config(uint32_t interface)
{
	switch(interface) {
	case HIF_NAND:
	case HIF_USB:
		ath_reg_wr(DDR_CONFIG_ADDRESS, 0x6fbc8890);		udelay(100);
		ath_reg_wr(DDR_CONFIG2_ADDRESS, 0x91d0e6a8);		udelay(100);
		ath_reg_wr(DDR_MODE_REGISTER_ADDRESS, 0x163);		udelay(100);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x1);			udelay(100);
		//ath_reg_wr(DDR_EXTENDED_MODE_REGISTER_ADDRESS, 0x0);	udelay(100);
		ath_reg_wr(DDR_EXTENDED_MODE_REGISTER_ADDRESS, 0x1);	udelay(200);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x2);			udelay(100);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x8);			udelay(100);
		ath_reg_wr(DDR_MODE_REGISTER_ADDRESS, 0x63);		udelay(100);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x1);			udelay(100);
		ath_reg_wr(DDR_REFRESH_ADDRESS, 0x4270);		udelay(100);
		ath_reg_wr(TAP_CONTROL_0_ADDRESS, 0x05);		udelay(100);
		ath_reg_wr(TAP_CONTROL_1_ADDRESS, 0x05);		udelay(100);
		ath_reg_wr(TAP_CONTROL_2_ADDRESS, 0x05);		udelay(100);
		ath_reg_wr(TAP_CONTROL_3_ADDRESS, 0x05);		udelay(100);
		ath_reg_wr(DDR_RD_DATA_THIS_CYCLE_ADDRESS, 0xffff);	udelay(100);
		ath_reg_wr(DDR_CTL_CONFIG_ADDRESS, 0x2);		udelay(100);
		break;

	case HIF_PCIE:
		ath_reg_wr(DDR_CONFIG_ADDRESS, 0x6fbc8890);
		ath_reg_wr(DDR_CONFIG2_ADDRESS, 0x91d0e6a8);
		ath_reg_wr(DDR_MODE_REGISTER_ADDRESS, 0x163);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x1);
		//ath_reg_wr(DDR_EXTENDED_MODE_REGISTER_ADDRESS, 0x0);
		ath_reg_wr(DDR_EXTENDED_MODE_REGISTER_ADDRESS, 0x1);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x2);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x8);
		ath_reg_wr(DDR_MODE_REGISTER_ADDRESS, 0x63);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x1);
		ath_reg_wr(DDR_REFRESH_ADDRESS, 0x4270);
		ath_reg_wr(TAP_CONTROL_0_ADDRESS, 0x05);
		ath_reg_wr(TAP_CONTROL_1_ADDRESS, 0x05);
		ath_reg_wr(TAP_CONTROL_2_ADDRESS, 0x05);
		ath_reg_wr(TAP_CONTROL_3_ADDRESS, 0x05);
		ath_reg_wr(DDR_RD_DATA_THIS_CYCLE_ADDRESS, 0xffff);
		ath_reg_wr(DDR_CTL_CONFIG_ADDRESS, 0x2);
		break;

	case HIF_GMAC:
		ath_reg_wr(DDR_CONFIG_ADDRESS, 0x67bc8890);
		ath_reg_wr(DDR_CONFIG2_ADDRESS, 0x95d0e6a8);
		ath_reg_wr(DDR_MODE_REGISTER_ADDRESS, 0x163);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x1);
		//ath_reg_wr(DDR_EXTENDED_MODE_REGISTER_ADDRESS, 0x0);
		ath_reg_wr(DDR_EXTENDED_MODE_REGISTER_ADDRESS, 0x1);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x2);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x8);
		ath_reg_wr(DDR_MODE_REGISTER_ADDRESS, 0x63);
		ath_reg_wr(DDR_CONTROL_ADDRESS, 0x1);
		ath_reg_wr(DDR_REFRESH_ADDRESS, 0x4310);
		ath_reg_wr(TAP_CONTROL_0_ADDRESS, 0x0);
		ath_reg_wr(TAP_CONTROL_1_ADDRESS, 0x0);
		ath_reg_wr(TAP_CONTROL_2_ADDRESS, 0x0);
		ath_reg_wr(TAP_CONTROL_3_ADDRESS, 0x0);
		ath_reg_wr(DDR_RD_DATA_THIS_CYCLE_ADDRESS, 0xffff);
		//ath_reg_wr(DDR_CTL_CONFIG_ADDRESS, 0x2);
		break;
	}

	return;
}
#else	// CONFIG_ATH_EMULATION

inline int
ath_ram_type(uint32_t bs)
{
	if (RST_BOOTSTRAP_DDR_SELECT_GET(bs)) {
		return ATH_MEM_DDR1;
	} else {
		return ATH_MEM_DDR2;
	}
}

#define CFG_DDR2_SCORPION_CAS_LATENCY	4

#ifdef CONFIG_TB614
#	define DDR_CONFIG2_SWAP_A26_A27_VAL	(0x1)
#else
#	define DDR_CONFIG2_SWAP_A26_A27_VAL	(0x0)
#endif

#if CFG_DDR2_SCORPION_CAS_LATENCY == 4
#define CFG_DDR2_CONFIG_VAL			DDR_CONFIG_CAS_LATENCY_MSB_SET(0x1) | \
						DDR_CONFIG_OPEN_PAGE_SET(0x1) | \
						DDR_CONFIG_CAS_LATENCY_SET(0x1) | \
						DDR_CONFIG_TMRD_SET(0xf) | \
						DDR_CONFIG_TRFC_SET(0x15) | \
						DDR_CONFIG_TRRD_SET(0x7) | \
						DDR_CONFIG_TRP_SET(0x9) | \
						DDR_CONFIG_TRCD_SET(0x9) | \
						DDR_CONFIG_TRAS_SET(0x1b)

#define CFG_DDR2_CONFIG2_VAL			DDR_CONFIG2_HALF_WIDTH_LOW_SET(0x1) | \
						DDR_CONFIG2_SWAP_A26_A27_SET(DDR_CONFIG2_SWAP_A26_A27_VAL) | \
						DDR_CONFIG2_GATE_OPEN_LATENCY_SET(0x8) | \
						DDR_CONFIG2_TWTR_SET(0x15) | \
						DDR_CONFIG2_TRTP_SET(0x9) | \
						DDR_CONFIG2_TRTW_SET(0xe) | \
						DDR_CONFIG2_TWR_SET(0x1) | \
						DDR_CONFIG2_CKE_SET(0x1) | \
						DDR_CONFIG2_CNTL_OE_EN_SET(0x1) | \
						DDR_CONFIG2_BURST_LENGTH_SET(0x8)

#define CFG_DDR2_CONFIG3_VAL			0x0000000a
#define CFG_DDR2_EXT_MODE_VAL			0x402
#define CFG_DDR2_MODE_VAL_INIT			0x143
#define CFG_DDR2_MODE_VAL			0x43
#define CFG_DDR2_TAP_VAL			0x10
#define CFG_DDR2_EN_TWL_VAL			0x0000167d
#define CFG_DDR2_RD_DATA_THIS_CYCLE_VAL_16	0xffff
#define CFG_DDR2_RD_DATA_THIS_CYCLE_VAL_32	0xff

#elif CFG_DDR2_SCORPION_CAS_LATENCY == 5

#define CFG_DDR2_CONFIG_VAL			DDR_CONFIG_CAS_LATENCY_MSB_SET(0x1) | \
						DDR_CONFIG_OPEN_PAGE_SET(0x1) | \
						DDR_CONFIG_CAS_LATENCY_SET(0x4) | \
						DDR_CONFIG_TMRD_SET(0xf) | \
						DDR_CONFIG_TRFC_SET(0x15) | \
						DDR_CONFIG_TRRD_SET(0x7) | \
						DDR_CONFIG_TRP_SET(0x9) | \
						DDR_CONFIG_TRCD_SET(0x9) | \
						DDR_CONFIG_TRAS_SET(0x1b)

#define CFG_DDR2_CONFIG2_VAL			DDR_CONFIG2_HALF_WIDTH_LOW_SET(0x1) | \
						DDR_CONFIG2_SWAP_A26_A27_SET(DDR_CONFIG2_SWAP_A26_A27_VAL) | \
						DDR_CONFIG2_GATE_OPEN_LATENCY_SET(0xb) | \
						DDR_CONFIG2_TWTR_SET(0x15) | \
						DDR_CONFIG2_TRTP_SET(0x9) | \
						DDR_CONFIG2_TRTW_SET(0xe) | \
						DDR_CONFIG2_TWR_SET(0x1) | \
						DDR_CONFIG2_CKE_SET(0x1) | \
						DDR_CONFIG2_CNTL_OE_EN_SET(0x1) | \
						DDR_CONFIG2_BURST_LENGTH_SET(0x8)

#define CFG_DDR2_CONFIG3_VAL			0x0000000a
#define CFG_DDR2_EXT_MODE_VAL			0x402
#define CFG_DDR2_MODE_VAL_INIT			0x153
#define CFG_DDR2_MODE_VAL			0x53
#define CFG_DDR2_TAP_VAL			0x10
#define CFG_DDR2_EN_TWL_VAL			0x00001e7d
#define CFG_DDR2_RD_DATA_THIS_CYCLE_VAL_16	0xffff
#define CFG_DDR2_RD_DATA_THIS_CYCLE_VAL_32	0xff
#endif

#define CFG_DDR1_CONFIG_VAL			DDR_CONFIG_OPEN_PAGE_SET(0x1) | \
						DDR_CONFIG_CAS_LATENCY_SET(0x7) | \
						DDR_CONFIG_TMRD_SET(0x5) | \
						DDR_CONFIG_TRFC_SET(0x7) | \
						DDR_CONFIG_TRRD_SET(0x4) | \
						DDR_CONFIG_TRP_SET(0x6) | \
						DDR_CONFIG_TRCD_SET(0x6) | \
						DDR_CONFIG_TRAS_SET(0x10)

#define CFG_DDR1_CONFIG2_VAL			DDR_CONFIG2_HALF_WIDTH_LOW_SET(0x1) | \
						DDR_CONFIG2_GATE_OPEN_LATENCY_SET(0x6) | \
						DDR_CONFIG2_TWTR_SET(0xe) | \
						DDR_CONFIG2_TRTP_SET(0x8) | \
						DDR_CONFIG2_TRTW_SET(0xe) | \
						DDR_CONFIG2_TWR_SET(0xd) | \
						DDR_CONFIG2_CKE_SET(0x1) | \
						DDR_CONFIG2_CNTL_OE_EN_SET(0x1) | \
						DDR_CONFIG2_BURST_LENGTH_SET(0x8)
#define CFG_DDR1_CONFIG3_VAL			0x0
#define CFG_DDR1_EXT_MODE_VAL			0x0
#define CFG_DDR1_MODE_VAL_INIT			0x133
#define CFG_DDR1_MODE_VAL			0x33
#define CFG_DDR1_RD_DATA_THIS_CYCLE_VAL_16	0xffff
#define CFG_DDR1_RD_DATA_THIS_CYCLE_VAL_32	0xff
#define CFG_DDR1_TAP_VAL			0x20

#define CFG_DDR_CTL_CONFIG			DDR_CTL_CONFIG_SRAM_TSEL_SET(0x1) | \
						DDR_CTL_CONFIG_GE0_SRAM_SYNC_SET(0x1) | \
						DDR_CTL_CONFIG_GE1_SRAM_SYNC_SET(0x1) | \
						DDR_CTL_CONFIG_USB_SRAM_SYNC_SET(0x1) | \
						DDR_CTL_CONFIG_PCIE_SRAM_SYNC_SET(0x1) | \
						DDR_CTL_CONFIG_WMAC_SRAM_SYNC_SET(0x1) | \
						DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_SET(0x1) | \
						DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_SET(0x1)

int /* ram type */
ath_ddr_initial_config(uint32_t refresh)
{
	int		ddr_config, ddr_config2, ddr_config3, mod_val,
			mod_val_init, cycle_val, tap_val, type, ctl_config;
	uint32_t	bootstrap;

	prmsg("\nsri\n");
	prmsg("Scorpion 1.%d\n", ath_reg_rd(RST_REVISION_ID_ADDRESS) & 0xf);

	bootstrap = ath_reg_rd(RST_BOOTSTRAP_ADDRESS);

	switch(type = ath_ram_type(bootstrap)) {
	case ATH_MEM_DDR2:
		ddr_config	= CFG_DDR2_CONFIG_VAL;
		ddr_config2	= CFG_DDR2_CONFIG2_VAL;
		ddr_config3	= CFG_DDR2_CONFIG3_VAL;
		mod_val_init	= CFG_DDR2_MODE_VAL_INIT;
		mod_val		= CFG_DDR2_MODE_VAL;
		tap_val		= CFG_DDR2_TAP_VAL;

		ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x10);
		udelay(10);
		ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x20);
		udelay(10);
		prmsg("%s(%d): (", __func__, __LINE__);

		if (RST_BOOTSTRAP_DDR_WIDTH_GET(bootstrap)) {
			prmsg("32");
			ctl_config =	CFG_DDR_CTL_CONFIG |
					DDR_CTL_CONFIG_PAD_DDR2_SEL_SET(0x1);

			cycle_val = CFG_DDR2_RD_DATA_THIS_CYCLE_VAL_32;
		} else {
			prmsg("16");
			ctl_config =	CFG_DDR_CTL_CONFIG |
					DDR_CTL_CONFIG_PAD_DDR2_SEL_SET(0x1) |
					DDR_CTL_CONFIG_HALF_WIDTH_SET(0x1);

			cycle_val = CFG_DDR2_RD_DATA_THIS_CYCLE_VAL_16;
		}

		ctl_config |= CPU_DDR_SYNC_MODE;

		ath_reg_wr_nf(DDR_CTL_CONFIG_ADDRESS, ctl_config);

		prmsg("bit) ddr2 init\n");
		udelay(10);
		break;
	case ATH_MEM_DDR1:
		ddr_config	= CFG_DDR1_CONFIG_VAL;
		ddr_config2	= CFG_DDR1_CONFIG2_VAL;
		ddr_config3	= CFG_DDR1_CONFIG3_VAL;
		mod_val_init	= CFG_DDR1_MODE_VAL_INIT;
		mod_val		= CFG_DDR1_MODE_VAL;
		tap_val		= CFG_DDR1_TAP_VAL;

		prmsg("%s(%d): (", __func__, __LINE__);
		if (RST_BOOTSTRAP_DDR_WIDTH_GET(bootstrap)) {
			prmsg("32");
			ctl_config = CFG_DDR_CTL_CONFIG;
			cycle_val = CFG_DDR1_RD_DATA_THIS_CYCLE_VAL_32;
		} else {
			prmsg("16");
			cycle_val = CFG_DDR1_RD_DATA_THIS_CYCLE_VAL_16;
			ctl_config = 0;
		}

		ctl_config |= CPU_DDR_SYNC_MODE;

		ath_reg_wr_nf(DDR_CTL_CONFIG_ADDRESS, ctl_config);
		udelay(10);
		prmsg("bit) ddr1 init\n");

		break;
	}

	ath_reg_wr_nf(DDR_RD_DATA_THIS_CYCLE_ADDRESS, cycle_val);
	udelay(100);
	ath_reg_wr_nf(DDR_BURST_ADDRESS, 0x74444444);
	udelay(100);
	ath_reg_wr_nf(DDR_BURST2_ADDRESS, 0x44444444);
	udelay(100);
	ath_reg_wr_nf(DDR_AHB_MASTER_TIMEOUT_MAX_ADDRESS, 0xfffff);
	udelay(100);
	ath_reg_wr_nf(DDR_CONFIG_ADDRESS, ddr_config);
	udelay(100);
	ath_reg_wr_nf(DDR_CONFIG2_ADDRESS, ddr_config2);
	udelay(100);
	ath_reg_wr(DDR_CONFIG_3_ADDRESS, ddr_config3);
	udelay(100);

	if (type == ATH_MEM_DDR2) {
		ath_reg_wr_nf(DDR2_CONFIG_ADDRESS, CFG_DDR2_EN_TWL_VAL);
		udelay(100);
	}

	ath_reg_wr_nf(DDR_CONFIG2_ADDRESS, ddr_config2 | 0x80);	// CKE Enable
	udelay(100);

	ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x8);	// Precharge
	udelay(10);

	if (type == ATH_MEM_DDR2) {
		ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x10);	// EMR2
		udelay(10);
		ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x20);	// EMR3
		udelay(10);
	}

	if (type == ATH_MEM_DDR1 || type == ATH_MEM_DDR2) {
		ath_reg_wr_nf(DDR_EXTENDED_MODE_REGISTER_ADDRESS, CFG_DDR2_EXT_MODE_VAL); // EMR DLL enable, Reduced Driver Impedance control, Differential DQS disabled
		udelay(100);
		ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x2); // EMR write
		udelay(10);
	}

	ath_reg_wr_nf(DDR_MODE_REGISTER_ADDRESS, mod_val_init);
	udelay(1000);

	ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x1);	// MR Write
	udelay(10);

	ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x8);	// Precharge
	udelay(10);

	ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x4);	// Auto Refresh
	udelay(10);

	ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x4);	// Auto Refresh
	udelay(10);

	// Issue MRS to remove DLL out-of-reset
	ath_reg_wr_nf(DDR_MODE_REGISTER_ADDRESS, mod_val);
	udelay(100);

	ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x1); // MR write
	udelay(100);

	if (type == ATH_MEM_DDR2) {
		ath_reg_wr_nf(DDR_EXTENDED_MODE_REGISTER_ADDRESS, 0x782);
		udelay(100);

		ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x2); // EMR write
		udelay(100);

		ath_reg_wr_nf(DDR_EXTENDED_MODE_REGISTER_ADDRESS, CFG_DDR2_EXT_MODE_VAL);
		udelay(100);

		ath_reg_wr_nf(DDR_CONTROL_ADDRESS, 0x2); // EMR write
		udelay(100);
	}

	ath_reg_wr_nf(DDR_REFRESH_ADDRESS, refresh);
	udelay(100);

	ath_reg_wr(TAP_CONTROL_0_ADDRESS, tap_val);
	ath_reg_wr(TAP_CONTROL_1_ADDRESS, tap_val);

	if (RST_BOOTSTRAP_DDR_WIDTH_GET(bootstrap)) {
		ath_reg_wr (TAP_CONTROL_2_ADDRESS, tap_val);
		ath_reg_wr (TAP_CONTROL_3_ADDRESS, tap_val);
	}

	if (type == ATH_MEM_DDR2) {
		ath_reg_wr(PMU1_ADDRESS, 0x633c8176);
		// Set DDR2 Voltage to 1.8 volts
		ath_reg_wr(PMU2_ADDRESS, PMU2_LDO_TUNE_SET(3) |
					 PMU2_PGM_SET(0x1));
	}

	/*
	 * Based on SGMII validation for stucks, packet errors were  observed and it was
	 * mostly due to noise pickup on SGMII lines. Switching regulator register is to
	 * be programmed with proper setting to avoid such stucks.
	 */
	ath_reg_rmw_clear(PMU1_ADDRESS, (7<<1));
	ath_reg_rmw_set(PMU1_ADDRESS, (1<<3));

	return type;
}

void ath_set_tuning_caps(void)
{
	ath_reg_wr(XTAL_ADDRESS,
			XTAL_TCXODET_SET(0x0) |
			XTAL_XTAL_CAPINDAC_SET(0x45) |
			XTAL_XTAL_CAPOUTDAC_SET(0x45) |
			XTAL_XTAL_DRVSTR_SET(0x3) |
			XTAL_XTAL_SHORTXIN_SET(0x0) |
			XTAL_XTAL_LOCALBIAS_SET(0x1) |
			XTAL_XTAL_PWDCLKD_SET(0x0) |
			XTAL_XTAL_BIAS2X_SET(0x0) |
			XTAL_XTAL_LBIAS2X_SET(0x0) |
			XTAL_XTAL_ATBVREG_SET(0x0) |
			XTAL_XTAL_OSCON_SET(0x1) |
			XTAL_XTAL_PWDCLKIN_SET(0x0) |
			XTAL_LOCAL_XTAL_SET(0x1) |
			XTAL_PWD_SWREGCLK_SET(0x0) |
			XTAL_SWREGCLK_EDGE_SEL_SET(0x0) |
			XTAL_SPARE_SET(0xf));

	return;
}

uint8_t tap_sweep[32], tap_center[32];
#define ATH_DDR_REFRESH_VAL	0X4138

int
ath_mem_config(void)
{
	unsigned int reg32;
	extern uint32_t *ath_ddr_tap_cal(void);

	ath_ddr_initial_config(ATH_DDR_REFRESH_VAL);

	ath_ddr_tap_cal();

	/* Take WMAC out of reset */
	reg32 = ath_reg_rd(RST_RESET_ADDRESS);
	reg32 = reg32 & ~RST_RESET_RTC_RESET_MASK;
	ath_reg_wr_nf(RST_RESET_ADDRESS, reg32);

	if (ATH_REF_CLK() == 25) {
		ath_reg_wr(SWITCH_CLOCK_SPARE_ADDRESS, 0x271);
	} else {
		ath_reg_wr(SWITCH_CLOCK_SPARE_ADDRESS, 0x570);
	}

	ath_set_tuning_caps();

	//ath_gpio_config();

	return ath_ddr_find_size();
}
#endif	// CONFIG_ATH_EMULATION
