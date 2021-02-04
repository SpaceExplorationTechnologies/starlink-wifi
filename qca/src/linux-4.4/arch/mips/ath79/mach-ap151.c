
/*
 * Qualcomm Atheros AP151 reference board support
 *
 * Copyright (c) 2014,2016 The Linux Foundation. All rights reserved.
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
#include <linux/ar8216_platform.h>

#include <asm/mach-ath79/ar71xx_regs.h>
#include <asm/mach-ath79/ath79.h>

#include "common.h"
#include "dev-ap9x-pci.h"
#include "dev-eth.h"
#include "dev-gpio-buttons.h"
#include "dev-leds-gpio.h"
#include "dev-m25p80.h"
#include "dev-usb.h"
#include "dev-wmac.h"
#include "machtypes.h"
#include "pci.h"

#define AP151_GPIO_LED_WLAN_2G          19
#define AP151_GPIO_LED_WPS              1

#define AP151_GPIO_LED_WAN              2
#define AP151_GPIO_LED_LAN1             15
#define AP151_GPIO_LED_LAN2             16
#define AP151_GPIO_LED_LAN3             21
#define AP151_GPIO_LED_LAN4             22

#define AP151_GPIO_BTN_WPS              14

#define AP151_KEYS_POLL_INTERVAL        20     /* msecs */
#define AP151_KEYS_DEBOUNCE_INTERVAL    (3 * AP151_KEYS_POLL_INTERVAL)

#define AP151_MAC0_OFFSET               0
#define AP151_MAC1_OFFSET               6
#define AP151_WMAC_CALDATA_OFFSET       0x1000

static struct gpio_led ap151_leds_gpio[] __initdata = {
	{
		.name           = "ap151:green:wps",
		.gpio           = AP151_GPIO_LED_WPS,
		.active_low     = 1,
	},
	{
		.name           = "ap151:green:wlan",
		.gpio           = AP151_GPIO_LED_WLAN_2G,
		.active_low     = 1,
	},
	{
		.name           = "ap151:green:wan",
		.gpio           = AP151_GPIO_LED_WAN,
		.active_low     = 1,
	},
	{
		.name           = "ap151:green:lan1",
		.gpio           = AP151_GPIO_LED_LAN1,
		.active_low     = 1,
	},
	{
		.name           = "ap151:green:lan2",
		.gpio           = AP151_GPIO_LED_LAN2,
		.active_low     = 1,
	},
	{
		.name           = "ap151:green:lan3",
		.gpio           = AP151_GPIO_LED_LAN3,
		.active_low     = 1,
	},
	{
		.name           = "ap151:green:lan4",
		.gpio           = AP151_GPIO_LED_LAN4,
		.active_low     = 1,
	},
};

static struct gpio_keys_button ap151_gpio_keys[] __initdata = {
	{
	.desc		= "wps button",
		.type		= EV_KEY,
		.code		= KEY_WPS_BUTTON,
		.debounce_interval = AP151_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= AP151_GPIO_BTN_WPS,
		.active_low	= 1,
	}
};

static void __init ap151_gpio_led_setup(void)
{
	ath79_gpio_direction_select(AP151_GPIO_LED_WAN, true);
	ath79_gpio_direction_select(AP151_GPIO_LED_LAN1, true);
	ath79_gpio_direction_select(AP151_GPIO_LED_LAN2, true);
	ath79_gpio_direction_select(AP151_GPIO_LED_LAN3, true);
	ath79_gpio_direction_select(AP151_GPIO_LED_LAN4, true);

	ath79_register_leds_gpio(-1, ARRAY_SIZE(ap151_leds_gpio),
			ap151_leds_gpio);
	ath79_register_gpio_keys_polled(-1, AP151_KEYS_POLL_INTERVAL,
			ARRAY_SIZE(ap151_gpio_keys),
			ap151_gpio_keys);
}

static void __init ap151_setup(void)
{
	u8 *art = (u8 *)KSEG1ADDR(0x1fff0000);

	ath79_register_m25p80(NULL);

	ap151_gpio_led_setup();

	ath79_register_usb();
	ath79_register_pci();

	ath79_register_wmac(art + AP151_WMAC_CALDATA_OFFSET, NULL);

	ath79_register_mdio(0, 0x0);
	ath79_register_mdio(1, 0x0);

	ath79_init_mac(ath79_eth0_data.mac_addr, art + AP151_MAC0_OFFSET, 0);
	ath79_init_mac(ath79_eth1_data.mac_addr, art + AP151_MAC1_OFFSET, 0);

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
}

MIPS_MACHINE(ATH79_MACH_AP151, "AP151", "Qualcomm Atheros AP151 reference board", ap151_setup);
