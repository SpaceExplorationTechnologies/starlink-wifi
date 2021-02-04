/* Copyright (c) 2014, 2016, 2017 The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __TARGET_BOARD_H
#define __TARGET_BOARD_H

#include <board.h>

#define NO_OF_DBG_UART_GPIOS	2
#ifdef CONFIG_IPQ40XX_I2C
#define NO_OF_I2C_GPIOS		2
#endif
#define MAX_CONF_NAME		5


#define IPQ40XX_EDMA_DEV	1
#define IPQ40XX_EDMA_CFG_BASE 0xc080000

#define MACH_TYPE_IPQ40XX_AP_DK01_1_S1  0x8010200
#define MACH_TYPE_IPQ40XX_AP_DK01_1_C1  0x8010000
#define MACH_TYPE_IPQ40XX_AP_DK01_1_C2  0x8010100
#define MACH_TYPE_IPQ40XX_AP_DK04_1_C1  0x8010001
#define MACH_TYPE_IPQ40XX_AP_DK04_1_C4  0x8010301
#define MACH_TYPE_IPQ40XX_AP_DK04_1_C2  0x8010101
#define MACH_TYPE_IPQ40XX_AP_DK04_1_C3  0x8010201
#define MACH_TYPE_IPQ40XX_AP_DK04_1_C5  0x8010401
#define MACH_TYPE_IPQ40XX_AP_DK05_1_C1  0x8010007
#define MACH_TYPE_IPQ40XX_AP_DK06_1_C1  0x8010005
#define MACH_TYPE_IPQ40XX_AP_DK07_1_C1  0x8010006
#define MACH_TYPE_IPQ40XX_AP_DK07_1_C2  0x8010106
#define MACH_TYPE_IPQ40XX_DB_DK01_1_C1  0x1010002
#define MACH_TYPE_IPQ40XX_DB_DK02_1_C1  0x1010003
#define MACH_TYPE_IPQ40XX_TB832         0x1010004

#define TCSR_USB_CONTROLLER_TYPE_SEL	0x1A4000B0
#define USB_CONT_TYPE_USB_20	0x2
typedef enum {
	PHY_INTERFACE_MODE_MII,
	PHY_INTERFACE_MODE_GMII,
	PHY_INTERFACE_MODE_SGMII,
	PHY_INTERFACE_MODE_TBI,
	PHY_INTERFACE_MODE_RMII,
	PHY_INTERFACE_MODE_RGMII,
	PHY_INTERFACE_MODE_RGMII_ID,
	PHY_INTERFACE_MODE_RGMII_RXID,
	PHY_INTERFACE_MODE_RGMII_TXID,
	PHY_INTERFACE_MODE_RTBI,
	PHY_INTERFACE_MODE_XGMII,
	PHY_INTERFACE_MODE_QSGMII,
	PHY_INTERFACE_MODE_PSGMII,
	PHY_INTERFACE_MODE_NONE /* Must be last */
} phy_interface_t;


#define MDIO_NAME_LEN 32
typedef struct {
	uint count;
	uint8_t addr[7];
} ipq40xx_edma_phy_addr_t;

/* ipq40xx edma Paramaters */
typedef struct {
	uint base;
	int unit;
	uint mac_conn_to_phy;
	phy_interface_t phy;
	ipq40xx_edma_phy_addr_t phy_addr;
	const char phy_name[MDIO_NAME_LEN];
} ipq40xx_edma_board_cfg_t;

typedef struct {
	int gpio;
	unsigned int func;
	unsigned int out;
	unsigned int pull;
	unsigned int drvstr;
	unsigned int oe;
	unsigned int gpio_vm;
	unsigned int gpio_od_en;
	unsigned int gpio_pu_res;
} gpio_func_data_t;

typedef struct {
	uint base;
	uint gsbi_base;
	unsigned int uart_dm_base;
	gpio_func_data_t *dbg_uart_gpio;
} uart_cfg_t;

#ifdef CONFIG_IPQ40XX_I2C
typedef struct {
	unsigned int i2c_base;
	gpio_func_data_t *i2c_gpio;
} i2c_cfg_t;
#endif

#ifdef CONFIG_IPQ40XX_PCI
#define PCI_MAX_DEVICES	1

typedef struct {
	gpio_func_data_t	*pci_gpio;
	uint32_t		pci_gpio_count;
	uint32_t		parf;
	uint32_t		elbi;
	uint32_t		pcie20;
	uint32_t		axi_bar_start;
	uint32_t		axi_bar_size;
	uint32_t		pcie_rst;
	uint32_t		axi_conf;
	int			linkup;
} pcie_params_t;

void board_pci_init(void);
#endif /* CONFIG_IPQ40XX_PCI */

/* Board specific parameters */
typedef struct {
	unsigned int machid;
	unsigned int ddr_size;
	const char *mtdids;
	gpio_func_data_t *spi_nor_gpio;
	unsigned int spi_nor_gpio_count;
	gpio_func_data_t *nand_gpio;
	unsigned int nand_gpio_count;
	gpio_func_data_t *sw_gpio;
	unsigned int sw_gpio_count;
	gpio_func_data_t *rgmii_gpio;
	unsigned int rgmii_gpio_count;
	ipq40xx_edma_board_cfg_t edma_cfg[IPQ40XX_EDMA_DEV];
	uart_cfg_t *uart_cfg;
	uart_cfg_t *console_uart_cfg;
#ifdef CONFIG_IPQ40XX_I2C
	i2c_cfg_t *i2c_cfg;
#endif
	gpio_func_data_t *emmc_gpio;
	unsigned int emmc_gpio_count;
	unsigned int spi_nand_available;
	unsigned int nor_nand_available;
	unsigned int nor_emmc_available;
#ifdef CONFIG_IPQ40XX_PCI
	pcie_params_t pcie_cfg[PCI_MAX_DEVICES];
#endif
	const char *dtb_config_name[MAX_CONF_NAME];
} __attribute__ ((__packed__)) board_ipq40xx_params_t;

extern board_ipq40xx_params_t *gboard_param;

board_ipq40xx_params_t *get_board_param(unsigned int machid);
void ipq_configure_gpio(gpio_func_data_t *gpio, int count);
void target_mmc_deinit();
void clock_disable_mmc();
#endif
