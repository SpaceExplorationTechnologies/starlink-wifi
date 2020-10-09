/*
 * Atheros CUS532K reference board support
 *
 * Copyright (c) 2015 The Linux Foundation. All rights reserved.
 * Copyright (c) 2012 Gabor Juhos <juhosg@openwrt.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#include <linux/pci.h>
#include <linux/phy.h>
#include <linux/platform_device.h>
#include <linux/ath9k_platform.h>
#include <linux/ar8216_platform.h>
#include <linux/platform/ar934x_nfc.h>
#include <linux/i2c.h>
#include <linux/i2c-gpio.h>

#include <asm/mach-ath79/ar71xx_regs.h>

#include "common.h"
#include "dev-ap9x-pci.h"
#include "dev-eth.h"
#include "dev-gpio-buttons.h"
#include "dev-leds-gpio.h"
#include "dev-m25p80.h"
#include "dev-nfc.h"
#include "dev-spi.h"
#include "dev-usb.h"
#include "dev-i2c.h"
#include "dev-wmac.h"
#include "machtypes.h"

#define CUS532K_GPIO_SPI_CS0		5
#define CUS532K_GPIO_SPI_CLK		6
#define CUS532K_GPIO_SPI_MOSI		7
#define CUS532K_GPIO_SPI_MISO		8
#define CUS532K_GPIO_WL_ACTIVE		12
#define CUS532K_GPIO_BT_ACTIVE		13
#define CUS532K_GPIO_BT_PRIORITY	14
#define CUS532K_GPIO_BT_ANT		15
#define CUS532K_GPIO_I2C_SCL		16
#define CUS532K_GPIO_I2C_SDA		17
#define CUS532K_GPIO_UART1_CTS		19
#define CUS532K_GPIO_UART1_TD		20
#define CUS532K_GPIO_UART1_RTS		21
#define CUS532K_GPIO_UART1_RD		22

static struct i2c_gpio_platform_data cus532k_i2c_gpio_data = {
	.sda_pin	= CUS532K_GPIO_I2C_SDA,
	.scl_pin	= CUS532K_GPIO_I2C_SCL,
};

static struct ath79_spi_controller_data ath79_spi_cdata =
{
	.cs_type = ATH79_SPI_CS_TYPE_INTERNAL,
	.cs_line = 0,
};

static struct ath79_spi_platform_data ath79_spi_data = {
	.bus_num = 0,
	.num_chipselect = 1,
};

static struct spi_board_info ath79_spi_info[] = {
	{
		.bus_num	= 0,
		.chip_select	= 0,
		.max_speed_hz	= 25000000,
		.modalias	= "spidev",
		.controller_data = &ath79_spi_cdata,
		.mode		= 0,
		.platform_data	= &ath79_spi_data,
	}
};

static void __init cus532k_setup(void)
{
	/* set up UART1 GPIO */
	ath79_gpio_output_select(CUS532K_GPIO_UART1_TD, AR934X_GPIO_OUT_MUX_UART1_TD);
	ath79_gpio_output_select(CUS532K_GPIO_UART1_RTS, AR934X_GPIO_OUT_MUX_UART1_RTS);
	ath79_gpio_input_select(CUS532K_GPIO_UART1_RD, AR934X_GPIO_IN_MUX_UART1_RD);
	ath79_gpio_input_select(CUS532K_GPIO_UART1_CTS, AR934X_GPIO_IN_MUX_UART1_CTS);

	ath79_gpio_direction_select(CUS532K_GPIO_UART1_TD, true);
	ath79_gpio_direction_select(CUS532K_GPIO_UART1_RTS, true);
	ath79_gpio_direction_select(CUS532K_GPIO_UART1_RD, false);
	ath79_gpio_direction_select(CUS532K_GPIO_UART1_CTS, false);

	ath79_gpio_direction_select(CUS532K_GPIO_WL_ACTIVE, true);
	ath79_gpio_direction_select(CUS532K_GPIO_BT_ACTIVE, false);
	ath79_gpio_direction_select(CUS532K_GPIO_BT_PRIORITY, false);

	ath79_gpio_output_select(CUS532K_GPIO_WL_ACTIVE,
				 AR934X_GPIO_OUT_MUX_RX_CLEAR_EXTERNAL);
	ath79_gpio_input_select(CUS532K_GPIO_BT_ACTIVE, AR934X_GPIO_IN_MUX_BT_ACTIVE);
	ath79_gpio_input_select(CUS532K_GPIO_BT_PRIORITY, AR934X_GPIO_IN_MUX_BT_PRIORITY);

	/* set up SPI GPIO */
	ath79_gpio_output_select(CUS532K_GPIO_SPI_CS0, AR934X_GPIO_OUT_MUX_SPI_CS0);
	ath79_gpio_output_select(CUS532K_GPIO_SPI_CLK, AR934X_GPIO_OUT_MUX_SPI_CLK);
	ath79_gpio_output_select(CUS532K_GPIO_SPI_MOSI, AR934X_GPIO_OUT_MUX_SPI_MOSI);
	ath79_gpio_input_select(CUS532K_GPIO_SPI_MISO, AR934X_GPIO_IN_MUX_SPI_MISO);

	ath79_gpio_direction_select(CUS532K_GPIO_SPI_CS0, true);
	ath79_gpio_direction_select(CUS532K_GPIO_SPI_CLK, true);
	ath79_gpio_direction_select(CUS532K_GPIO_SPI_MOSI, true);
	ath79_gpio_direction_select(CUS532K_GPIO_SPI_MISO, false);

	ath79_setup_ar934x_eth_cfg(AR934X_ETH_CFG_RGMII_GMAC0);
	ath79_register_mdio(1, 0x0);
	ath79_register_mdio(0, 0x0);
	/* GMAC1 is connected to ETH port */
	ath79_eth1_data.phy_if_mode = PHY_INTERFACE_MODE_GMII;
	ath79_eth1_data.speed = SPEED_1000;
	ath79_eth1_data.duplex = DUPLEX_FULL;
	ath79_register_eth(1);

	ath79_nfc_set_ecc_mode(AR934X_NFC_ECC_HW);
	ath79_register_nfc();

	ath79_register_usb();

	/* Set up the SPI device */
	ath79_register_spi(&ath79_spi_data, ath79_spi_info, 1);

	/* Set up the I2C device */
	ath79_register_i2c(&cus532k_i2c_gpio_data, NULL, 0);

	ath79_register_wmac_simple();
	ap91_pci_init_simple();
}

MIPS_MACHINE(ATH79_MACH_CUS532K, "CUS532K", "CUS532K board",
	     cus532k_setup);
