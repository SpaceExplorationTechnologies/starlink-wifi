/*
 * Atheros CUS531 reference board support
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

#include <linux/platform_device.h>
#include <linux/ath9k_platform.h>
#include <linux/ar8216_platform.h>
#include <asm/mach-ath79/ar71xx_regs.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/i2c.h>
#include <linux/i2c-gpio.h>

#include "common.h"
#include "dev-eth.h"
#include "dev-gpio-buttons.h"
#include "dev-leds-gpio.h"
#include "dev-m25p80.h"
#include "dev-spi.h"
#include "dev-usb.h"
#include "dev-wmac.h"
#include "dev-i2c.h"
#include "machtypes.h"
#include "pci.h"

#define CUS531_GPIO_SPI_CS0		5
#define CUS531_GPIO_SPI_CS1		11
#define CUS531_GPIO_LED_SYS		12
#define CUS531_GPIO_I2C_SCL		16
#define CUS531_GPIO_I2C_SDA		17

#define CUS531_GPIO_BTN_WPS		14

#define CUS531MP3_GPIO_BT_ACTIVE	0
#define CUS531MP3_GPIO_BT_PRIORITY	1
#define CUS531MP3_GPIO_WL_ACTIVE	2
#define CUS531MP3_GPIO_LED_WLAN		12
#define CUS531MP3_GPIO_LED_WAN		14
#define CUS531MP3_GPIO_BTN_WPS		4
#define CUS531MP3_GPIO_BTN_RESET	15

#define CUS531_GPIO_FUNC_MUX_WL_ACTIVE	53

#define CUS531_KEYS_POLL_INTERVAL	20
#define CUS531_KEYS_DEBOUNCE_INTERVAL	(3 * CUS531_KEYS_POLL_INTERVAL)

#define CUS531_MAC0_OFFSET		0
#define CUS531_MAC1_OFFSET		6
#define CUS531_WMAC_CALDATA_OFFSET	0x1000

static struct i2c_gpio_platform_data ath79_i2c_gpio_data = {
	.sda_pin = CUS531_GPIO_I2C_SDA,
	.scl_pin = CUS531_GPIO_I2C_SCL,
};

static struct gpio_led cus531_leds_gpio[] __initdata = {
	{
		.name		= "cus531:green:sys",
		.gpio		= CUS531_GPIO_LED_SYS,
		.active_low	= 1,
	},
};

static struct gpio_keys_button cus531_gpio_keys[] __initdata = {
	{
		.desc		= "WPS button",
		.type		= EV_KEY,
		.code		= KEY_WPS_BUTTON,
		.debounce_interval = CUS531_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= CUS531_GPIO_BTN_WPS,
		.active_low	= 1,
	},
};

static void __init cus531_gpio_setup(void)
{
	ath79_register_leds_gpio(-1,
				 ARRAY_SIZE(cus531_leds_gpio),
				 cus531_leds_gpio);
	ath79_register_gpio_keys_polled(-1, CUS531_KEYS_POLL_INTERVAL,
					ARRAY_SIZE(cus531_gpio_keys),
					cus531_gpio_keys);
}

static struct ath79_spi_controller_data cus531_spi0_cdata =
{
	.cs_type	= ATH79_SPI_CS_TYPE_INTERNAL,
	.is_flash	= true,
	.cs_line	= 0,
};

static struct ath79_spi_controller_data cus531_spi1_cdata =
{
	.cs_type	= ATH79_SPI_CS_TYPE_INTERNAL,
	.is_flash	= false,
	.cs_line	= 1,
};

static struct spi_board_info cus531_spi_info[] = {
	{
		.bus_num	= 0,
		.chip_select	= 0,
		.max_speed_hz	= 25000000,
		.modalias	= "m25p80",
		.controller_data = &cus531_spi0_cdata,
		.platform_data 	= NULL,
	},
	{
		.bus_num	= 0,
		.chip_select	= 1,
		.max_speed_hz   = 50000000,
		.modalias	= "ath79-spinand",
		.controller_data = &cus531_spi1_cdata,
		.platform_data 	= NULL,
	}
};

static struct ath79_spi_platform_data cus531_spi_data = {
	.bus_num		= 0,
	.num_chipselect		= 2,
        .word_banger            = true,
};

static void __init cus531_register_i2c_devices(
		struct i2c_board_info const *info)
{
	ath79_gpio_output_select(CUS531_GPIO_I2C_SDA, AR934X_GPIO_OUT_GPIO);
	ath79_gpio_output_select(CUS531_GPIO_I2C_SCL, AR934X_GPIO_OUT_GPIO);

	ath79_register_i2c(&ath79_i2c_gpio_data, info, info ? 1 : 0);
}

static void __init __cus531_common_setup(void)
{
	u8 *art = (u8 *) KSEG1ADDR(0x1fff0000);

	ath79_register_usb();

	ath79_register_wmac(art + CUS531_WMAC_CALDATA_OFFSET, NULL);

	ath79_register_mdio(0, 0x0);
	ath79_register_mdio(1, 0x0);

	ath79_init_mac(ath79_eth0_data.mac_addr, art + CUS531_MAC0_OFFSET, 0);
	ath79_init_mac(ath79_eth1_data.mac_addr, art + CUS531_MAC1_OFFSET, 0);

	/* WAN port */
	ath79_eth0_data.phy_if_mode = PHY_INTERFACE_MODE_MII;
	ath79_eth0_data.speed = SPEED_100;
	ath79_eth0_data.duplex = DUPLEX_FULL;
	ath79_eth0_data.phy_mask = BIT(4);
	ath79_register_eth(0);

	/* LAN ports */
	ath79_eth1_data.phy_if_mode = PHY_INTERFACE_MODE_GMII;
	ath79_eth1_data.speed = SPEED_1000;
	ath79_eth1_data.duplex = DUPLEX_FULL;
	ath79_switch_data.phy_poll_mask |= BIT(4);
	ath79_switch_data.phy4_mii_en = 1;
	ath79_register_eth(1);

	/* GPIO based S/W I2C master device */
	cus531_register_i2c_devices(NULL);
}

static void __init cus531_common_setup(void)
{
	cus531_gpio_setup();
	__cus531_common_setup();
}

static void __init cus531_setup(void)
{
	ath79_register_m25p80(NULL);
	cus531_common_setup();
}

static void __init cus531_dual_setup(void)
{
	ath79_register_m25p80_multi(NULL);
	cus531_common_setup();
}

static void __init cus531_nand_setup(void)
{
	ath79_register_spi(&cus531_spi_data, cus531_spi_info, 2);
	cus531_common_setup();
}

static struct gpio_keys_button cus531mp3_gpio_keys[] __initdata = {
	{
		.desc		= "WPS button",
		.type		= EV_KEY,
		.code		= KEY_WPS_BUTTON,
		.debounce_interval = CUS531_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= CUS531MP3_GPIO_BTN_WPS,
		.active_low	= 0,
	},
	{
		.desc		= "RESET button",
		.type		= EV_KEY,
		.code		= KEY_RESTART,
		.debounce_interval = CUS531_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= CUS531MP3_GPIO_BTN_RESET,
		.active_low	= 1,
	},
};

static void __init cus531mp3_gpio_setup(void)
{
	/* enable LAN LED */
	ath79_gpio_direction_select(CUS531MP3_GPIO_LED_WAN, true);
	ath79_gpio_output_select(CUS531MP3_GPIO_LED_WAN,
				 QCA953X_GPIO_OUT_MUX_LED_LINK5);

	/* set WLAN LED pin */
	ath79_wmac_set_led_pin(CUS531MP3_GPIO_LED_WLAN);

	/* Disable JTAG for BT Coex pin */
	ath79_gpio_function_enable(AR934X_GPIO_FUNC_JTAG_DISABLE);

	ath79_gpio_direction_select(CUS531MP3_GPIO_WL_ACTIVE, true);
	ath79_gpio_direction_select(CUS531MP3_GPIO_BT_ACTIVE, false);
	ath79_gpio_direction_select(CUS531MP3_GPIO_BT_PRIORITY, false);

	ath79_gpio_output_select(CUS531MP3_GPIO_WL_ACTIVE,
				 CUS531_GPIO_FUNC_MUX_WL_ACTIVE);
	ath79_gpio_input_select(CUS531MP3_GPIO_BT_ACTIVE,
				AR934X_GPIO_IN_MUX_BT_ACTIVE);
	ath79_gpio_input_select(CUS531MP3_GPIO_BT_PRIORITY,
				AR934X_GPIO_IN_MUX_BT_PRIORITY);

	ath79_wmac_set_btcoex_pin(CUS531MP3_GPIO_BT_ACTIVE,
				  CUS531MP3_GPIO_BT_PRIORITY,
				  CUS531MP3_GPIO_WL_ACTIVE);

	ath79_register_gpio_keys_polled(-1, CUS531_KEYS_POLL_INTERVAL,
					ARRAY_SIZE(cus531mp3_gpio_keys),
					cus531mp3_gpio_keys);
}

static void __init cus531mp3_common_setup(void)
{
	cus531mp3_gpio_setup();
	ath79_register_pci();

	__cus531_common_setup();
}

static void __init cus531mp3_setup(void)
{
	ath79_register_m25p80(NULL);
	cus531mp3_common_setup();
}

static void __init cus531mp3_dual_setup(void)
{
	ath79_register_m25p80_multi(NULL);
	cus531mp3_common_setup();
}

static void __init cus531mp3_nand_setup(void)
{
	ath79_register_spi(&cus531_spi_data, cus531_spi_info, 2);
	cus531mp3_common_setup();
}

MIPS_MACHINE(ATH79_MACH_CUS531, "CUS531", "Qualcomm Atheros CUS531 reference board",
	     cus531_setup);
MIPS_MACHINE(ATH79_MACH_CUS531_DUAL, "CUS531-DUAL", "Qualcomm Atheros CUS531 dual reference board",
	     cus531_dual_setup);
MIPS_MACHINE(ATH79_MACH_CUS531_NAND, "CUS531-NAND", "Qualcomm Atheros CUS531 nand reference board",
	     cus531_nand_setup);
MIPS_MACHINE(ATH79_MACH_CUS531MP3, "CUS531MP3", "Qualcomm Atheros CUS531 MP3 reference board",
	     cus531mp3_setup);
MIPS_MACHINE(ATH79_MACH_CUS531MP3_DUAL, "CUS531MP3-DUAL", "Qualcomm Atheros CUS531 MP3 dual reference board",
	     cus531mp3_dual_setup);
MIPS_MACHINE(ATH79_MACH_CUS531MP3_NAND, "CUS531MP3-NAND", "Qualcomm Atheros CUS531 MP3 nand reference board",
	     cus531mp3_nand_setup);
