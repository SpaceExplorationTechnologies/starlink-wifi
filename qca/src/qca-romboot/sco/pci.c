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

typedef unsigned int uint32_t;

static int
ath_local_write_config(int where, int size, u32 value)
{
	ath_reg_wr((PCIE_RC_REG_0_ADDRESS + where), value);
	return 0;
}

static int
ath_local_write_config_rc2(int where, int size, u32 value)
{
	ath_reg_wr((PCIERC_RC_REG_0_ADDRESS + where), value);
	return 0;
}

void
pci_rc2_init_board (void)
{
	uint32_t	cmd;

	ath_reg_rmw_set(RST_RESET2_ADDRESS, RST_RESET2_PCIE2_PHY_RESET_SET(1));
	udelay(10000);

	ath_reg_rmw_set(RST_RESET2_ADDRESS, RST_RESET2_PCIE2_RESET_SET(1));
	udelay(10000);

	ath_reg_rmw_clear(RST_MISC2_ADDRESS, RST_MISC2_PERSTN_RCPHY2_SET(1));
	udelay(10000);

	ath_reg_wr_nf(PCIE2_RESET_ADDRESS, 0);	// Put endpoint in reset
	udelay(100000);

	ath_reg_rmw_set(RST_MISC2_ADDRESS, RST_MISC2_PERSTN_RCPHY2_SET(1));
	udelay(10000);

	ath_reg_rmw_clear(RST_RESET2_ADDRESS, RST_RESET_PCIE_PHY_RESET_SET(1));
	udelay(10000);

	ath_reg_rmw_clear(RST_RESET2_ADDRESS, RST_RESET_PCIE_RESET_SET(1));
	udelay(10000);

	ath_reg_wr_nf(PCIE2_APP_ADDRESS, PCIE2_APP_PCIE2_BAR_MSN_SET(1) |
					PCIE2_APP_CFG_BE_SET(0xf) |
					PCIE2_APP_SLV_RESP_ERR_MAP_SET(0x3f) |
					PCIE2_APP_LTSSM_ENABLE_SET(1));

	cmd = PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER | PCI_COMMAND_INVALIDATE |
		PCI_COMMAND_PARITY | PCI_COMMAND_SERR | PCI_COMMAND_FAST_BACK;

	ath_local_write_config_rc2(PCI_COMMAND, 4, cmd);
	ath_local_write_config_rc2(0x20, 4, 0x1ff01000);
	ath_local_write_config_rc2(0x24, 4, 0x1ff01000);

	ath_reg_wr_nf(PCIE2_RESET_ADDRESS, 4);	// Pull endpoint out of reset
	udelay(100000);

	/*
	 * Check if the WLAN PCI-E H/W is present, If the
	 * WLAN H/W is not present, skip the PCI platform
	 * initialization code and return
	 */
	if (((ath_reg_rd(PCIE2_RESET_ADDRESS)) & 0x1) == 0x0) {
		printf("*** Warning *** : PCIe WLAN Module not found !!!\n");
		return;
	}
}

int pci_init_board (void)
{
#ifdef CONFIG_ATH_EMULATION
	printf("--- Skipping %s for emulation\n", __func__);
#else
	uint32_t cmd;

	// common for rc1 and rc2
	ath_reg_wr_nf(PCIE_PLL_DITHER_DIV_MAX_ADDRESS,
		PCIE_PLL_DITHER_DIV_MAX_EN_DITHER_SET(1) |
		PCIE_PLL_DITHER_DIV_MAX_USE_MAX_SET(1) |
		PCIE_PLL_DITHER_DIV_MAX_DIV_MAX_INT_SET(0x14) |
		PCIE_PLL_DITHER_DIV_MAX_DIV_MAX_FRAC_SET(0x3ff));

	ath_reg_wr_nf(PCIE_PLL_DITHER_DIV_MIN_ADDRESS,
		PCIE_PLL_DITHER_DIV_MIN_DIV_MIN_INT_SET(0x14));

	ath_reg_wr_nf(PCIE_PLL_CONFIG_ADDRESS,
		PCIE_PLL_CONFIG_REFDIV_SET(1) |
		PCIE_PLL_CONFIG_BYPASS_SET(1) |
		PCIE_PLL_CONFIG_PLLPWD_SET(1));
	udelay(10000);


	ath_reg_rmw_clear(PCIE_PLL_CONFIG_ADDRESS, PCIE_PLL_CONFIG_PLLPWD_SET(1));
	udelay(1000);
	ath_reg_rmw_clear(PCIE_PLL_CONFIG_ADDRESS, PCIE_PLL_CONFIG_BYPASS_SET(1));
	udelay(1000);

	if (!(ath_reg_rd(RST_BOOTSTRAP_ADDRESS) & RST_BOOTSTRAP_PCIE_RC_EP_SELECT_MASK)) {
		pci_rc2_init_board();
		return 0;
	}

	ath_reg_rmw_set(RST_RESET_ADDRESS, RST_RESET_PCIE_PHY_RESET_SET(1));
	udelay(10000);

	ath_reg_rmw_set(RST_RESET_ADDRESS, RST_RESET_PCIE_RESET_SET(1));
	udelay(10000);

	ath_reg_rmw_clear(RST_MISC2_ADDRESS, RST_MISC2_PERSTN_RCPHY_SET(1));
	udelay(10000);

	ath_reg_wr_nf(PCIE_RESET_ADDRESS, 0);	// Put endpoint in reset
	udelay(100000);

	ath_reg_rmw_set(RST_MISC2_ADDRESS, RST_MISC2_PERSTN_RCPHY_SET(1));
	udelay(10000);

	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_PCIE_PHY_RESET_SET(1));
	udelay(10000);

	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_PCIE_RESET_SET(1));
	udelay(10000);

	ath_reg_wr_nf(PCIE_APP_ADDRESS, PCIE_APP_PCIE_BAR_MSN_SET(1) |
					PCIE_APP_CFG_BE_SET(0xf) |
					PCIE_APP_SLV_RESP_ERR_MAP_SET(0x3f) |
					PCIE_APP_LTSSM_ENABLE_SET(1));

	cmd = PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER | PCI_COMMAND_INVALIDATE |
		PCI_COMMAND_PARITY | PCI_COMMAND_SERR | PCI_COMMAND_FAST_BACK;

	ath_local_write_config(PCI_COMMAND, 4, cmd);
	ath_local_write_config(0x20, 4, 0x1ff01000);
	ath_local_write_config(0x24, 4, 0x1ff01000);

	ath_reg_wr_nf(PCIE_RESET_ADDRESS, 4);	// Pull endpoint out of reset
	udelay(100000);

	/* training reset */
	ath_reg_rmw_set(PCIE_APP_ADDRESS, PCIE_APP_INIT_RST_SET(1));
	udelay(1000);

	/*
	 * Check if the WLAN PCI-E H/W is present, If the
	 * WLAN H/W is not present, skip the PCI platform
	 * initialization code and return
	 */
	if (((ath_reg_rd(PCIE_RESET_ADDRESS)) & 0x1) == 0x0) {
		printf("*** Warning *** : PCIe WLAN Module not found !!!\n");
	}

	pci_rc2_init_board();

#endif /* CONFIG_ATH_EMULATION */

	return 0;
}
