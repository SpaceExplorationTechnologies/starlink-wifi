
/*
 * Qualcomm Atheros APJET01 reference board support
 *
 * Copyright (c) 2017 The Linux Foundation. All rights reserved.
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

#include "common.h"
#include "dev-m25p80.h"
#include "machtypes.h"
#include "pci.h"
#include "dev-eth.h"
#include "dev-gpio-buttons.h"
#include "dev-leds-gpio.h"
#include "dev-spi.h"
#include "dev-usb.h"
#include "dev-wmac.h"

#define APJET01_GPIO_LED_WLAN_2G	15

#define APJET01_GPIO_LED_LAN1             2
#define APJET01_GPIO_LED_LAN2             3
#define APJET01_GPIO_LED_LAN3             4
#define APJET01_GPIO_LED_LAN4             5

#define APJET01_GPIO_LED_USB		4

#define APJET01_GPIO_BTN_RESET            3
#define APJET01_GPIO_BTN_WPS              1
#define APJET01_KEYS_POLL_INTERVAL        20     /* msecs */
#define APJET01_KEYS_DEBOUNCE_INTERVAL    (3 * APJET01_KEYS_POLL_INTERVAL)

#define APJET01_MAC0_OFFSET               0
#define APJET01_MAC1_OFFSET               6
#define APJET01_WMAC_CALDATA_OFFSET       0x1000

#define APJET01_GPIO_MDC			9
#define APJET01_GPIO_MDIO			10

static struct gpio_led apjet01_leds_gpio[] __initdata = {
	{
		.name		= "apjet01:green:usb",
		.gpio		= APJET01_GPIO_LED_USB,
		.active_low	= 1,
	},
	{
		.name		= "apjet01:green:wlan",
		.gpio		= APJET01_GPIO_LED_WLAN_2G,
		.active_low	= 1,
	},
};

static struct gpio_keys_button apjet01_gpio_keys[] __initdata = {
	{
		.desc           = "WPS button",
		.type           = EV_KEY,
		.code           = KEY_WPS_BUTTON,
		.debounce_interval = APJET01_KEYS_DEBOUNCE_INTERVAL,
		.gpio           = APJET01_GPIO_BTN_WPS,
		.active_low     = 1,
	},
	{
		.desc           = "Reset button",
		.type           = EV_KEY,
		.code           = KEY_RESTART,
		.debounce_interval = APJET01_KEYS_DEBOUNCE_INTERVAL,
		.gpio           = APJET01_GPIO_BTN_RESET,
		.active_low     = 1,
	},
};

static struct ar8327_pad_cfg apjet01_ar8337_pad0_cfg = {
	.mode = AR8327_PAD_MAC_SGMII,
	.sgmii_delay_en = true,
};

static struct ar8327_platform_data apjet01_ar8337_data = {
	.pad0_cfg = &apjet01_ar8337_pad0_cfg,
	.port0_cfg = {
		.force_link = 1,
		.speed = AR8327_PORT_SPEED_1000,
		.duplex = 1,
		.txpause = 1,
		.rxpause = 1,
	},
};

static struct mdio_board_info apjet01_mdio0_info[] = {
	{
		.bus_id = "ag71xx-mdio.0",
		.phy_addr = 0,
		.platform_data = &apjet01_ar8337_data,
	},
};
#if 0
static void __init apjet01_mdio_setup(void)
{
	ath79_gpio_output_select(APJET01_GPIO_MDC,
				QCN550X_GPIO_OUT_MUX_GE0_MDC);
	ath79_gpio_output_select(APJET01_GPIO_MDIO,
			QCN550X_GPIO_OUT_MUX_GE0_MDO);

	ath79_register_mdio(0, 0x0);
}
#endif
static void __init apjet01_gmac_setup(void)
{
	void __iomem *base;
	u32 t;

	base = ioremap(QCA955X_GMAC_BASE, QCA955X_GMAC_SIZE);

	t = __raw_readl(base + QCA955X_GMAC_REG_ETH_CFG);

	t &= ~(QCA955X_ETH_CFG_RGMII_GMAC0 | QCA955X_ETH_CFG_SGMII_GMAC0);
	/* clear bit 0, then GMAC0 is SGMII*/
	t |= QCA955X_ETH_CFG_SGMII_GMAC0;

	__raw_writel(t, base + QCA955X_GMAC_REG_ETH_CFG);

	iounmap(base);
}

static void __init apjet01_setup(void)
{
	u8 *art = (u8 *) KSEG1ADDR(0x1fff0000);

	ath79_register_m25p80(NULL);

	ath79_register_leds_gpio(-1, ARRAY_SIZE(apjet01_leds_gpio),
				apjet01_leds_gpio);
	ath79_register_gpio_keys_polled(-1, APJET01_KEYS_POLL_INTERVAL,
					ARRAY_SIZE(apjet01_gpio_keys),
					apjet01_gpio_keys);

	ath79_register_usb();

	/* apjet01_mdio_setup(); */

	mdiobus_register_board_info(apjet01_mdio0_info,
				    ARRAY_SIZE(apjet01_mdio0_info));

	ath79_register_wmac(art + APJET01_WMAC_CALDATA_OFFSET, NULL);
	ath79_register_pci();

	apjet01_gmac_setup();

	/* GMAC0 is connected to an AR8337 switch */
	ath79_init_mac(ath79_eth0_data.mac_addr, art + APJET01_MAC0_OFFSET, 0);
	ath79_eth0_data.phy_if_mode = PHY_INTERFACE_MODE_SGMII;
	ath79_eth0_data.speed = SPEED_1000;
	ath79_eth0_data.duplex = DUPLEX_FULL;
	ath79_eth0_data.phy_mask = BIT(0);
	ath79_eth0_data.force_link = 1;
	ath79_eth0_data.mii_bus_dev = &ath79_mdio0_device.dev;
	ath79_eth0_pll_data.pll_1000 = 0x06000000;
	ath79_register_eth(0);
}

MIPS_MACHINE(ATH79_MACH_APJET01, "APJET01",
		"Qualcomm Atheros APJET01 reference board",
		apjet01_setup);
