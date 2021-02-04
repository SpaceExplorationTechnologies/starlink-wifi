/*
 *  Atheros AP81 board support
 *
 *  Copyright (C) 2009-2010 Gabor Juhos <juhosg@openwrt.org>
 *  Copyright (C) 2009 Imre Kaloz <kaloz@openwrt.org>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>

#include "dev-eth.h"
#include "dev-gpio-buttons.h"
#include "dev-leds-gpio.h"
#include "dev-m25p80.h"
#include "dev-usb.h"
#include "dev-wmac.h"
#include "machtypes.h"

#define AP81_GPIO_LED_STATUS	1
#define AP81_GPIO_LED_AOSS	3
#define AP81_GPIO_LED_WLAN	6
#define AP81_GPIO_LED_POWER	14

#define AP81_GPIO_BTN_SW4	12
#define AP81_GPIO_BTN_SW1	21

#define AP81_KEYS_POLL_INTERVAL		20	/* msecs */
#define AP81_KEYS_DEBOUNCE_INTERVAL	(3 * AP81_KEYS_POLL_INTERVAL)

#define AP81_CAL_DATA_ADDR	0x1fff1000

static struct gpio_led ap81_leds_gpio[] __initdata = {
	{
		.name		= "ap81:green:status",
		.gpio		= AP81_GPIO_LED_STATUS,
		.active_low	= 1,
	}, {
		.name		= "ap81:amber:aoss",
		.gpio		= AP81_GPIO_LED_AOSS,
		.active_low	= 1,
	}, {
		.name		= "ap81:green:wlan",
		.gpio		= AP81_GPIO_LED_WLAN,
		.active_low	= 1,
	}, {
		.name		= "ap81:green:power",
		.gpio		= AP81_GPIO_LED_POWER,
		.active_low	= 1,
	}
};

static struct gpio_keys_button ap81_gpio_keys[] __initdata = {
	{
		.desc		= "sw1",
		.type		= EV_KEY,
		.code		= BTN_0,
		.debounce_interval = AP81_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= AP81_GPIO_BTN_SW1,
		.active_low	= 1,
	} , {
		.desc		= "sw4",
		.type		= EV_KEY,
		.code		= BTN_1,
		.debounce_interval = AP81_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= AP81_GPIO_BTN_SW4,
		.active_low	= 1,
	}
};

static void __init ap81_setup(void)
{
	u8 *cal_data = (u8 *) KSEG1ADDR(AP81_CAL_DATA_ADDR);

	ath79_register_leds_gpio(-1, ARRAY_SIZE(ap81_leds_gpio),
				 ap81_leds_gpio);
	ath79_register_gpio_keys_polled(-1, AP81_KEYS_POLL_INTERVAL,
					ARRAY_SIZE(ap81_gpio_keys),
					ap81_gpio_keys);
	ath79_register_m25p80(NULL);
	ath79_register_wmac(cal_data, NULL);
	ath79_register_usb();

	ath79_register_mdio(0, 0x0);

	ath79_init_mac(ath79_eth0_data.mac_addr, cal_data, 0);
	ath79_eth0_data.phy_if_mode = PHY_INTERFACE_MODE_RMII;
	ath79_eth0_data.speed = SPEED_100;
	ath79_eth0_data.duplex = DUPLEX_FULL;
	ath79_eth0_data.has_ar8216 = 1;

	ath79_init_mac(ath79_eth1_data.mac_addr, cal_data, 1);
	ath79_eth1_data.phy_if_mode = PHY_INTERFACE_MODE_RMII;
	ath79_eth1_data.phy_mask = 0x10;

	ath79_register_eth(0);
	ath79_register_eth(1);
}

MIPS_MACHINE(ATH79_MACH_AP81, "AP81", "Atheros AP81 reference board",
	     ap81_setup);
