/* Copyright (c) 2014, 2016 The Linux Foundation. All rights reserved.
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

#define MACH_TYPE_IPQ806X_RUMI3		3961
#define MACH_TYPE_IPQ806X_TB726		3962
#define MACH_TYPE_IPQ806X_AP144		3963
#define MACH_TYPE_IPQ806X_DB149		4699
#define MACH_TYPE_IPQ806X_DB149_1XX	4811
#define MACH_TYPE_IPQ806X_DB147		4703
#define MACH_TYPE_IPQ806X_AP148		4704
#define MACH_TYPE_IPQ806X_AP145		4810
#define MACH_TYPE_IPQ806X_AP145_1XX	4812
#define MACH_TYPE_IPQ806X_AP148_1XX	4913
#define MACH_TYPE_IPQ806X_DB149_2XX	4917
#define MACH_TYPE_IPQ806X_STORM		4936
#define MACH_TYPE_IPQ806X_AP160		4971
#define MACH_TYPE_IPQ806X_AP160_2XX	4991
#define MACH_TYPE_IPQ806X_AP161		4972
#define MACH_TYPE_IPQ806X_AK01_1XX	5020

typedef struct {
	int gpio;
	unsigned int func;
	unsigned int out;
	unsigned int pull;
	unsigned int drvstr;
	unsigned int oe;
} gpio_func_data_t;

typedef struct {
	unsigned int m_value;
	unsigned int n_value;
	unsigned int d_value;
} clk_mnd_t;

/* SPI Mode */

typedef enum {
	NOR_SPI_MODE_0,
	NOR_SPI_MODE_1,
	NOR_SPI_MODE_2,
	NOR_SPI_MODE_3,
} spi_mode;

/* SPI GSBI Bus number */

typedef enum {
	GSBI_BUS_5 = 0,
	GSBI_BUS_6,
	GSBI_BUS_7,
} spi_gsbi_bus_num;

/* SPI Chip selects */

typedef enum {
	SPI_CS_0 ,
	SPI_CS_1,
	SPI_CS_2,
	SPI_CS_3,
} spi_cs;

/* Flash Types */

typedef enum {
	ONLY_NAND,
	ONLY_NOR,
	NAND_NOR,
	NOR_MMC,
} flash_desc;

#define NO_OF_DBG_UART_GPIOS		2
#define NO_OF_I2C_GPIOS			2
#define MAX_CONF_NAME			5


#define SPI_NOR_FLASH_VENDOR_MICRON	0x1
#define SPI_NOR_FLASH_VENDOR_SPANSION	0x2

#define TCSR_USB_CONTROLLER_TYPE_SEL	0x1A4000B0
#define USB_CONT_TYPE_USB_20	0x2

#define S17_RGMII0_1_8V			(1 << 19)
#define S17_RGMII1_1_8V			(1 << 18)

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
	PHY_INTERFACE_MODE_NONE /* Must be last */
} phy_interface_t;

#define MDIO_NAME_LEN 32

/* SPI parameters */
typedef struct {
	spi_mode mode;
	spi_gsbi_bus_num bus_number;
	spi_cs chip_select;
	int vendor;
} spinorflash_params_t;

typedef struct {
	uint count;
	uint8_t addr[7];
} ipq_gmac_phy_addr_t;

typedef struct {
	uint base;
	int unit;
	uint is_macsec;
	uint mac_pwr0;
	uint mac_pwr1;
	uint mac_conn_to_phy;
	phy_interface_t phy;
	ipq_gmac_phy_addr_t phy_addr;
	const char phy_name[MDIO_NAME_LEN];
} ipq_gmac_board_cfg_t;

typedef struct {
	uint base;
	uint gsbi_base;
	uint uart_dm_base;
	clk_mnd_t uart_mnd_value;
	gpio_func_data_t *dbg_uart_gpio;
} uart_cfg_t;

#define IPQ_GMAC_NMACS		4
#define IPQ_UART_MAX		2

#ifdef CONFIG_IPQ806X_PCI
#define PCI_MAX_DEVICES		3

typedef struct {
	gpio_func_data_t 		*pci_rst_gpio;
	uint32_t			parf;
	uint32_t			elbi;
	uint32_t			pcie20;
	uint32_t			axi_bar_start;
	uint32_t			axi_bar_size;
	uint32_t			pcie_rst;
	clk_offset_t			*pci_clks;
	uint32_t			axi_conf;
	int 				linkup;
} pcie_params_t;

void board_pci_init(void);
#endif /* CONFIG_IPQ806X_PCI */

typedef struct {
	unsigned int machid;
	unsigned int ddr_size;
	unsigned int clk_dummy;
	clk_mnd_t usb_core_mnd_value;
	clk_mnd_t usb_utmi_mnd_value;
	unsigned int gmac_gpio_count;
	gpio_func_data_t *gmac_gpio;
	ipq_gmac_board_cfg_t gmac_cfg[IPQ_GMAC_NMACS];
	uart_cfg_t uart_cfg[IPQ_UART_MAX];
	uart_cfg_t *console_uart_cfg;
	gpio_func_data_t *switch_gpio;
	gpio_func_data_t *reset_switch_gpio;
	gpio_func_data_t *reset_ak01_gmac_gpio;
	gpio_func_data_t *ar8033_gpio;
	flash_desc flashdesc;
	spinorflash_params_t flash_param;
#ifdef CONFIG_IPQ806X_I2C
	unsigned int i2c_gsbi;
	unsigned int i2c_gsbi_base;
	clk_mnd_t i2c_mnd_value;
	gpio_func_data_t i2c_gpio[NO_OF_I2C_GPIOS];
#endif
#ifdef CONFIG_IPQ806X_PCI
	pcie_params_t	pcie_cfg[PCI_MAX_DEVICES];
	unsigned int wifi_pcie_power_gpio_cnt;
	gpio_func_data_t *wifi_pcie_power_gpio[PCI_MAX_DEVICES];
#endif
	gpio_func_data_t *emmc_gpio;
	unsigned int emmc_gpio_count;

	const char *dtb_config_name[MAX_CONF_NAME];
} board_ipq806x_params_t;

extern board_ipq806x_params_t *gboard_param;

board_ipq806x_params_t *get_board_param(unsigned int machid);
void ipq_configure_gpio(gpio_func_data_t *gpio, int count);
int ipq_athrs17_init();
void gpio_tlmm_config(uint32_t gpio, uint8_t func,
		uint8_t dir, uint8_t pull,
		uint8_t drvstr, uint32_t enable);

#endif
