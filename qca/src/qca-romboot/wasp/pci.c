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
#include <ar934x_soc.h>
#include "dt_defs.h"
#include "rom.addrs.h"

static int  ar7240_local_write_config(int where, int size, uint32_t value);

static int
ar7240_local_write_config(int where, int size, uint32_t value)
{
	ar7240_reg_wr((AR7240_PCI_CRP + where),value);
	return 0;
}


#define pci_udelay(n)	do { uint32_t i; /* printf("--- %s[%d] udelay(%u)\n", __func__, __LINE__, n); */ for (i = 0; i < ((n)/10); i++) udelay(10); } while (0)

int pci_init_board (void)
{
	uint32_t cmd = 0, reg_val;


	//printf("%s: PCIe PLL 0x%x\n", __func__, mips3_cp0_count_read());
	//printf("%s: PCIe PLL 0x%x  0xb8000008 =  0x%08x\n", __func__, mips3_cp0_count_read(), ar7240_reg_rd(0xb8040008));

	pci_udelay(100000);
	//count ++;

	if ((ar7240_reg_rd(WASP_BOOTSTRAP_REG) & WASP_REF_CLK_25) == 0) {
		ar7240_reg_wr_nf(AR934X_PCIE_PLL_DITHER_DIV_MAX,
			PCIE_PLL_DITHER_DIV_MAX_EN_DITHER_SET(0) |
			PCIE_PLL_DITHER_DIV_MAX_USE_MAX_SET(1) |
			PCIE_PLL_DITHER_DIV_MAX_DIV_MAX_INT_SET(0x20) |
			PCIE_PLL_DITHER_DIV_MAX_DIV_MAX_FRAC_SET(0));
	}

	ar7240_reg_rmw_set(AR7240_RESET, AR7240_RESET_PCIE);	// core in reset
	pci_udelay(10000);
	ar7240_reg_rmw_set(AR7240_RESET, AR7240_RESET_PCIE_PHY);// phy in reset
	pci_udelay(10000);
	ar7240_reg_rmw_clear(RST_MISC2_ADDRESS, RST_MISC2_PERSTN_RCPHY_SET(1)); // pci phy analog in reset
	pci_udelay(10000);
	ar7240_reg_wr(0x180f0000, 0x1ffc0);			// ltssm is disabled
	pci_udelay(100);
	ar7240_reg_wr_nf(AR7240_PCI_LCL_RESET, 0);	// End point in reset
	pci_udelay(100000);


	//ar7240_reg_rmw_clear(AR7240_RESET, AR7240_RESET_PCIE_PHY);

	if ((ar7240_reg_rd(RST_REVISION_ID_ADDRESS) & 0xf) == 0) {
		ar7240_reg_wr_nf(AR934X_PCIE_PLL_CONFIG,
			PCIE_PLL_CONFIG_REFDIV_SET(1) |
			PCIE_PLL_CONFIG_BYPASS_SET(1) |
			PCIE_PLL_CONFIG_PLLPWD_SET(1));
		pci_udelay(10000);
		ar7240_reg_wr_nf(AR934X_PCIE_PLL_CONFIG,
			PCIE_PLL_CONFIG_REFDIV_SET(1) |
			PCIE_PLL_CONFIG_BYPASS_SET(1) |
			PCIE_PLL_CONFIG_PLLPWD_SET(0));
		pci_udelay(1000);
		ar7240_reg_wr_nf(AR934X_PCIE_PLL_CONFIG,
			ar7240_reg_rd(AR934X_PCIE_PLL_CONFIG) &
			(~PCIE_PLL_CONFIG_BYPASS_SET(1)));
		pci_udelay(1000);
	} else {
		ar7240_reg_wr_nf(AR934X_PCIE_PLL_CONFIG,
			PCIE_PLL_CONFIG_REFDIV_SET(2) |
			PCIE_PLL_CONFIG_BYPASS_SET(1) |
			PCIE_PLL_CONFIG_PLLPWD_SET(1));
		pci_udelay(10000);

		if ((ar7240_reg_rd(WASP_BOOTSTRAP_REG) & WASP_REF_CLK_25) == 0) {
			ar7240_reg_wr_nf(0xb8116c00, (0x5 << 27) | (160 << 18) | 0);
		} else {
			ar7240_reg_wr_nf(0xb8116c00, (0x2 << 27) | (0x28 << 18) | 0);
		}
		do {
			ar7240_reg_wr_nf(0xb8116c04, (0x1 << 30) | (0x4 << 26) | (0x32 << 19) | (1 << 16) | (3 << 13) | (0x1e << 7));
			ar7240_reg_wr_nf(0xb8116c08, (6 << 23));
			pci_udelay(10000);
			ar7240_reg_wr_nf(0xb8116c04, (0x1 << 30) | (0x4 << 26) | (0x32 << 19) | (3 << 13) | (0x1e << 7));

			ar7240_reg_rmw_clear(KSEG1ADDR(PCIe_DPLL3_ADDRESS), PCIe_DPLL3_DO_MEAS_SET(1));
			ar7240_reg_rmw_set(KSEG1ADDR(PCIe_DPLL3_ADDRESS), PCIe_DPLL3_DO_MEAS_SET(1));

			ar7240_reg_wr(0xb804000c, 1 << 2);

			pci_udelay(1000);

			while (((cmd = ar7240_reg_rd(PCIe_DPLL4_ADDRESS)) & PCIe_DPLL4_MEAS_DONE_SET(1)) == 0) {
				printf("0x%x 0x%x 0x%x\n", KSEG1ADDR(PCIe_DPLL4_ADDRESS), cmd);
				pci_udelay(10);
			}

			{ int i; for (i = 0; i < 100; i++) udelay(10); }

		} while ((cmd = PCIe_DPLL3_SQSUM_DVC_GET(ar7240_reg_rd(PCIe_DPLL3_ADDRESS))) >= 0x40000);

		ar7240_reg_rmw_clear(AR934X_PCIE_PLL_CONFIG, PCIE_PLL_CONFIG_PLLPWD_SET(1));
		pci_udelay(10000);
		ar7240_reg_rmw_clear(AR934X_PCIE_PLL_CONFIG, PCIE_PLL_CONFIG_BYPASS_SET(1));
		pci_udelay(10000);

		//run_command("md 0xb8116c00 4", 0);
	}
	ar7240_reg_rmw_set(RST_MISC2_ADDRESS, RST_MISC2_PERSTN_RCPHY_SET(1)); // pci phy analog out of reset
	pci_udelay(10000);

	ar7240_reg_rmw_clear(AR7240_RESET, AR7240_RESET_PCIE_PHY);	// phy out of reset
	pci_udelay(10000);

	ar7240_reg_rmw_clear(AR7240_RESET, AR7240_RESET_PCIE);	// core out of reset
	pci_udelay(1000);

	cmd = PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER | PCI_COMMAND_INVALIDATE |
	      PCI_COMMAND_PARITY|PCI_COMMAND_SERR|PCI_COMMAND_FAST_BACK;

	ar7240_local_write_config(PCI_COMMAND, 4, cmd);		// pci cmd reg init
	ar7240_local_write_config(0x20, 4, 0x1ff01000);		// membase setting
	ar7240_local_write_config(0x24, 4, 0x1ff01000);		// prefetch membase setting


	ar7240_reg_wr(PCIE_APP_ADDRESS, 0x1ffc1);		// ltssm enable
	pci_udelay(100000);

	ar7240_reg_wr_nf(AR7240_PCI_LCL_RESET, 4);		// EP out of reset
	pci_udelay(100000);


	/*
	 *  Delay increased from 100 to 1000, so as to
	 *  get the correct status from PCI LCL RESET register
	 */
	pci_udelay(100000);

	/*
	 * Check if the WLAN PCI-E H/W is present, If the
	 * WLAN H/W is not present, skip the PCI platform
	 * initialization code and return
	 */

	if (((ar7240_reg_rd(AR7240_PCI_LCL_RESET)) & 0x1) == 0x0) {
		printf("*** Warning *** : PCIe WLAN Module not found !!!\n");
		return;
	}

        ar7240_reg_wr((AR7240_PCI_DEV_CFGBASE + 0x10), 0xffff);

	return 0;
}

