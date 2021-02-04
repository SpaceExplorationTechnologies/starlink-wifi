/*
 *  Atheros AR913X/AR933X SoC built-in WMAC device support
 *
 *  Copyright (C) 2008-2011 Gabor Juhos <juhosg@openwrt.org>
 *  Copyright (C) 2008 Imre Kaloz <kaloz@openwrt.org>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#ifndef _ATH79_DEV_WMAC_H
#define _ATH79_DEV_WMAC_H

void ath79_register_wmac(u8 *cal_data, u8 *mac_addr);
void ath79_register_wmac_simple(void);
void ath79_wmac_disable_2ghz(void);
void ath79_wmac_disable_5ghz(void);
void ath79_wmac_set_tx_gain_buffalo(void);
void ath79_wmac_set_ext_lna_gpio(unsigned chain, int gpio);
void ath79_wmac_set_led_pin(int gpio);

bool ar93xx_wmac_read_mac_address(u8 *dest);

#endif /* _ATH79_DEV_WMAC_H */
