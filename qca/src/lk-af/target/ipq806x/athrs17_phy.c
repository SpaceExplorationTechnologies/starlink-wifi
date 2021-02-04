/*
 * Copyright (c) 2013-2016 The Linux Foundation. All rights reserved.
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

/*
 * Manage the atheros ethernet PHY.
 *
 * All definitions in this file are operating system independent!
 */

#include <platform/iomap.h>
#include <sys/types.h>
#include <target/board.h>
#include <reg.h>
#include <debug.h>
#include <platform.h>
#include <platform/timer.h>

/* MII address register definitions */
#define MII_DATA_REG_ADDR			(0x14)
#define MII_ADDR_REG_ADDR                       (0x10)
#define MIIADDRSHIFT				(11)
#define MII_ADDRMSK				(0x1F << 11)
#define MIIREGSHIFT				(6)
#define MII_REGMSK                              (0x1F << 6)
#define MII_BUSY				(1 << 0)
#define MII_WRITE                               (1 << 1)
#define MII_CLKRANGE_250_300M			(0x14)
#define MII_MDIO_TIMEOUT                        (10000)

/*S17 address register definitions */
#define S17_MASK_CTRL_SOFT_RET		(1 << 31)
#define S17_MASK_CTRL_REG               0x0000
#define S17_GLOBAL_INT0_REG             0x0020
#define S17_P0STATUS_REG                0x007c
#define S17_P1STATUS_REG                0x0080
#define S17_P2STATUS_REG                0x0084
#define S17_P3STATUS_REG                0x0088
#define S17_P4STATUS_REG                0x008c
#define S17_P5STATUS_REG                0x0090
#define S17_P6STATUS_REG                0x0094

#define S17_GLOBAL_INT0_ACL_INI_INT        (1<<29)
#define S17_GLOBAL_INT0_LOOKUP_INI_INT     (1<<28)
#define S17_GLOBAL_INT0_QM_INI_INT         (1<<27)
#define S17_GLOBAL_INT0_MIB_INI_INT        (1<<26)
#define S17_GLOBAL_INT0_OFFLOAD_INI_INT    (1<<25)
#define S17_GLOBAL_INT0_HARDWARE_INI_DONE  (1<<24)


#define S17_GLOBAL_INITIALIZED_STATUS 				\
			(					\
			S17_GLOBAL_INT0_ACL_INI_INT | 		\
			S17_GLOBAL_INT0_LOOKUP_INI_INT | 	\
			S17_GLOBAL_INT0_QM_INI_INT | 		\
			S17_GLOBAL_INT0_MIB_INI_INT | 		\
			S17_GLOBAL_INT0_OFFLOAD_INI_INT |	\
			S17_GLOBAL_INT0_HARDWARE_INI_DONE	\
			)


uint32_t s17_ipq_mdio_read(uint phy_addr, uint reg_offset, ushort *data)
{
	uint32_t reg_base = NSS_GMAC0_BASE;
	uint32_t timeout = MII_MDIO_TIMEOUT;
	uint32_t miiaddr;
	time_t start = current_time();
	uint32_t ret_val;

	miiaddr = (((phy_addr << MIIADDRSHIFT) & MII_ADDRMSK) |
	((reg_offset << MIIREGSHIFT) & MII_REGMSK));

	miiaddr |= (MII_BUSY | MII_CLKRANGE_250_300M);
	writel(miiaddr, (reg_base + MII_ADDR_REG_ADDR));
	udelay(10);

	while ((current_time() - start) < timeout) {
		if (!(readl(reg_base + MII_ADDR_REG_ADDR) & MII_BUSY)) {
			ret_val = readl(reg_base + MII_DATA_REG_ADDR);
			if (data != NULL)
				*data = ret_val;
			return ret_val;
		}
		udelay(1000);
	}
	return -1;
}

uint32_t s17_ipq_mdio_write(uint phy_addr, uint reg_offset, ushort data)
{
	const uint reg_base = NSS_GMAC0_BASE;
	const uint timeout = MII_MDIO_TIMEOUT;
	uint32_t miiaddr;
	time_t start = current_time();

	writel(data, (reg_base + MII_DATA_REG_ADDR));

	miiaddr = (((phy_addr << MIIADDRSHIFT) & MII_ADDRMSK) |
			((reg_offset << MIIREGSHIFT) & MII_REGMSK) |
			(MII_WRITE));

	miiaddr |= (MII_BUSY | MII_CLKRANGE_250_300M);
	writel(miiaddr, (reg_base + MII_ADDR_REG_ADDR));
	udelay(10);

	while ((current_time() - start) < timeout) {
		if (!(readl(reg_base + MII_ADDR_REG_ADDR) & MII_BUSY)) {
			return 0;
		}
		udelay(1000);
	}
	return -1;
}
/******************************************************************************
 * FUNCTION DESCRIPTION: Read switch internal register.
 *                       Switch internal register is accessed through the
 *                       MDIO interface. MDIO access is only 16 bits wide so
 *                       it needs the two time access to complete the internal
 *                       register access.
 * INPUT               : register address
 * OUTPUT              : Register value
 *
 *****************************************************************************/
static uint32_t
athrs17_reg_read(uint32_t reg_addr)
{
	uint32_t reg_word_addr;
	uint32_t phy_addr, tmp_val, reg_val;
	uint16_t phy_val;
	uint8_t phy_reg;

	/* change reg_addr to 16-bit word address, 32-bit aligned */
	reg_word_addr = (reg_addr & 0xfffffffc) >> 1;

	/* configure register high address */
	phy_addr = 0x18;
	phy_reg = 0x0;
	phy_val = (uint16_t) ((reg_word_addr >> 8) & 0x1ff);  /* bit16-8 of reg address */
	s17_ipq_mdio_write(phy_addr, phy_reg, phy_val);

	/*
	 * For some registers such as MIBs, since it is read/clear, we should
	 * read the lower 16-bit register then the higher one
	 */

	/* read register in lower address */
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7); /* bit7-5 of reg address */
	phy_reg = (uint8_t) (reg_word_addr & 0x1f);   /* bit4-0 of reg address */
	reg_val = (uint32_t) s17_ipq_mdio_read(phy_addr, phy_reg, NULL);

	/* read register in higher address */
	reg_word_addr++;
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7); /* bit7-5 of reg address */
	phy_reg = (uint8_t) (reg_word_addr & 0x1f);   /* bit4-0 of reg address */
	tmp_val = (uint32_t) s17_ipq_mdio_read(phy_addr, phy_reg, NULL);
	reg_val |= (tmp_val << 16);

	return reg_val;
}

/******************************************************************************
 * FUNCTION DESCRIPTION: Write switch internal register.
 *                       Switch internal register is accessed through the
 *                       MDIO interface. MDIO access is only 16 bits wide so
 *                       it needs the two time access to complete the internal
 *                       register access.
 * INPUT               : register address, value to be written
 * OUTPUT              : NONE
 *
 *****************************************************************************/
static void
athrs17_reg_write(uint32_t reg_addr, uint32_t reg_val)
{
	uint32_t reg_word_addr;
	uint32_t phy_addr;
	uint16_t phy_val;
	uint8_t phy_reg;

	/* change reg_addr to 16-bit word address, 32-bit aligned */
	reg_word_addr = (reg_addr & 0xfffffffc) >> 1;

	/* configure register high address */
	phy_addr = 0x18;
	phy_reg = 0x0;
	phy_val = (uint16_t) ((reg_word_addr >> 8) & 0x1ff);  /* bit16-8 of reg address */
	s17_ipq_mdio_write(phy_addr, phy_reg, phy_val);

	/*
	 * For some registers such as ARL and VLAN, since they include BUSY bit
	 * in lower address, we should write the higher 16-bit register then the
	 * lower one
	 */

	/* read register in higher address */
	reg_word_addr++;
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7); /* bit7-5 of reg address */
	phy_reg = (uint8_t) (reg_word_addr & 0x1f);   /* bit4-0 of reg address */
	phy_val = (uint16_t) ((reg_val >> 16) & 0xffff);
	s17_ipq_mdio_write(phy_addr, phy_reg, phy_val);

	/* write register in lower address */
	reg_word_addr--;
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7); /* bit7-5 of reg address */
	phy_reg = (uint8_t) (reg_word_addr & 0x1f);   /* bit4-0 of reg address */
	phy_val = (uint16_t) (reg_val & 0xffff);
	s17_ipq_mdio_write(phy_addr, phy_reg, phy_val);
}
/*******************************************************************
* FUNCTION DESCRIPTION: Reset S17 register
* INPUT: NONE
* OUTPUT: NONE
*******************************************************************/
int athrs17_init_switch()
{
	uint32_t data;
	uint32_t i = 0;

	/* Reset the switch before initialization */
	athrs17_reg_write(S17_MASK_CTRL_REG, S17_MASK_CTRL_SOFT_RET);
	do {
		udelay(10);
		data = athrs17_reg_read(S17_MASK_CTRL_REG);
	} while (data & S17_MASK_CTRL_SOFT_RET);

	do {
		udelay(10);
		data = athrs17_reg_read(S17_GLOBAL_INT0_REG);
		i++;
		if (i == 10)
			return -1;
	} while ((data & S17_GLOBAL_INITIALIZED_STATUS) != S17_GLOBAL_INITIALIZED_STATUS);
	return 0;
}

void athrs17_switch_disable_lookup()
{
	athrs17_reg_write(S17_P0STATUS_REG, 0x0);
        athrs17_reg_write(S17_P1STATUS_REG, 0x0);
        athrs17_reg_write(S17_P2STATUS_REG, 0x0);
        athrs17_reg_write(S17_P3STATUS_REG, 0x0);
        athrs17_reg_write(S17_P4STATUS_REG, 0x0);
        athrs17_reg_write(S17_P5STATUS_REG, 0x0);
        athrs17_reg_write(S17_P6STATUS_REG, 0x0);
 }
/*********************************************************************
 *
 * FUNCTION DESCRIPTION: This function invokes
 * 			SGMII switch init routines.
 * INPUT : NONE
 * OUTPUT: NONE
 *
**********************************************************************/
int ipq_athrs17_init()
{
	int ret;

	ret = athrs17_init_switch();
	if (ret != -1) {
		athrs17_switch_disable_lookup();
		dprintf (INFO, "S17c init  done\n");
	}

	return ret;
}
