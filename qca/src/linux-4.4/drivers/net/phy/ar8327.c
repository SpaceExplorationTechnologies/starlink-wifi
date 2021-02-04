/*
 * ar8327.c: AR8216 switch driver
 *
 * Copyright (c) 2017 The Linux Foundation. All rights reserved.
 * Copyright (C) 2009 Felix Fietkau <nbd@openwrt.org>
 * Copyright (C) 2011-2012 Gabor Juhos <juhosg@openwrt.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/list.h>
#include <linux/bitops.h>
#include <linux/switch.h>
#include <linux/delay.h>
#include <linux/phy.h>
#include <linux/lockdep.h>
#include <linux/ar8216_platform.h>
#include <linux/workqueue.h>
#include <linux/of_device.h>
#include <linux/leds.h>
#include <linux/mdio.h>

#include "ar8216.h"
#include "ar8327.h"

extern const struct ar8xxx_mib_desc ar8236_mibs[39];
extern const struct switch_attr ar8xxx_sw_attr_vlan[1];

static u32
ar8327_get_pad_cfg(struct ar8327_pad_cfg *cfg)
{
	u32 t;

	if (!cfg)
		return 0;

	t = 0;
	switch (cfg->mode) {
	case AR8327_PAD_NC:
		break;

	case AR8327_PAD_MAC2MAC_MII:
		t = AR8327_PAD_MAC_MII_EN;
		if (cfg->rxclk_sel)
			t |= AR8327_PAD_MAC_MII_RXCLK_SEL;
		if (cfg->txclk_sel)
			t |= AR8327_PAD_MAC_MII_TXCLK_SEL;
		break;

	case AR8327_PAD_MAC2MAC_GMII:
		t = AR8327_PAD_MAC_GMII_EN;
		if (cfg->rxclk_sel)
			t |= AR8327_PAD_MAC_GMII_RXCLK_SEL;
		if (cfg->txclk_sel)
			t |= AR8327_PAD_MAC_GMII_TXCLK_SEL;
		break;

	case AR8327_PAD_MAC_SGMII:
		t = AR8327_PAD_SGMII_EN;

		/* WAR for the QUalcomm Atheros AP136 board.
		 * It seems that RGMII TX/RX delay settings needs to be
		 * applied for SGMII mode as well, The ethernet is not
		 * reliable without this.
		 */
		t |= cfg->txclk_delay_sel << AR8327_PAD_RGMII_TXCLK_DELAY_SEL_S;
		t |= cfg->rxclk_delay_sel << AR8327_PAD_RGMII_RXCLK_DELAY_SEL_S;
		if (cfg->rxclk_delay_en)
			t |= AR8327_PAD_RGMII_RXCLK_DELAY_EN;
		if (cfg->txclk_delay_en)
			t |= AR8327_PAD_RGMII_TXCLK_DELAY_EN;

		if (cfg->sgmii_delay_en)
			t |= AR8327_PAD_SGMII_DELAY_EN;

		break;

	case AR8327_PAD_MAC2PHY_MII:
		t = AR8327_PAD_PHY_MII_EN;
		if (cfg->rxclk_sel)
			t |= AR8327_PAD_PHY_MII_RXCLK_SEL;
		if (cfg->txclk_sel)
			t |= AR8327_PAD_PHY_MII_TXCLK_SEL;
		break;

	case AR8327_PAD_MAC2PHY_GMII:
		t = AR8327_PAD_PHY_GMII_EN;
		if (cfg->pipe_rxclk_sel)
			t |= AR8327_PAD_PHY_GMII_PIPE_RXCLK_SEL;
		if (cfg->rxclk_sel)
			t |= AR8327_PAD_PHY_GMII_RXCLK_SEL;
		if (cfg->txclk_sel)
			t |= AR8327_PAD_PHY_GMII_TXCLK_SEL;
		break;

	case AR8327_PAD_MAC_RGMII:
		t = AR8327_PAD_RGMII_EN;
		t |= cfg->txclk_delay_sel << AR8327_PAD_RGMII_TXCLK_DELAY_SEL_S;
		t |= cfg->rxclk_delay_sel << AR8327_PAD_RGMII_RXCLK_DELAY_SEL_S;
		if (cfg->rxclk_delay_en)
			t |= AR8327_PAD_RGMII_RXCLK_DELAY_EN;
		if (cfg->txclk_delay_en)
			t |= AR8327_PAD_RGMII_TXCLK_DELAY_EN;
		break;

	case AR8327_PAD_PHY_GMII:
		t = AR8327_PAD_PHYX_GMII_EN;
		break;

	case AR8327_PAD_PHY_RGMII:
		t = AR8327_PAD_PHYX_RGMII_EN;
		break;

	case AR8327_PAD_PHY_MII:
		t = AR8327_PAD_PHYX_MII_EN;
		break;
	}

	return t;
}

static void ar8327_phy_manu_ctrl_en(struct ar8xxx_priv *priv,
				    int phy_addr, bool enable)
{
	u16 phy_val = 0;

	ar8xxx_phy_dbg_read(priv, phy_addr, AR8327_PHY_DEBUG_0, &phy_val);
	if (enable)
		phy_val |= AR8327_PHY_MANU_CTRL_EN;
	else
		phy_val &= (~AR8327_PHY_MANU_CTRL_EN);
	ar8xxx_phy_dbg_write(priv, phy_addr, AR8327_PHY_DEBUG_0, phy_val);
}

static void
ar8327_phy_fixup(struct ar8xxx_priv *priv, int phy)
{
	ushort phy_val;
	struct mii_bus *bus;

	if(chip_is_ar8327(priv)) {
		switch (priv->chip_rev) {
		case 1:
			/* For 100M waveform */
			ar8xxx_phy_dbg_write(priv, phy, 0, 0x02ea);
			/* Turn on Gigabit clock */
			ar8xxx_phy_dbg_write(priv, phy, 0x3d, 0x68a0);
			break;

		case 2:
			ar8xxx_phy_mmd_write(priv, phy, 0x7, 0x3c);
			ar8xxx_phy_mmd_write(priv, phy, 0x4007, 0x0);
			/* fallthrough */
		case 4:
			ar8xxx_phy_mmd_write(priv, phy, 0x3, 0x800d);
			ar8xxx_phy_mmd_write(priv, phy, 0x4003, 0x803f);

			ar8xxx_phy_dbg_write(priv, phy, 0x3d, 0x6860);
			ar8xxx_phy_dbg_write(priv, phy, 0x5, 0x2c46);
			ar8xxx_phy_dbg_write(priv, phy, 0x3c, 0x6000);
			break;
		}
	}

	bus = priv->mii_bus;
	/* enable phy prefer multi-port mode */
	phy_val = mdiobus_read(bus, phy, MII_CTRL1000);
	phy_val |= (ADVERTISE_MULTI_PORT_PREFER | ADVERTISE_1000FULL);
	mdiobus_write(bus, phy, MII_CTRL1000, phy_val);

	/* enable extended next page. 0:enable, 1:disable */
	phy_val = mdiobus_read(bus, phy, MII_ADVERTISE);
	phy_val &= (~(ADVERTISE_RESV));
	mdiobus_write(bus, phy, MII_ADVERTISE, phy_val);

	ar8327_phy_manu_ctrl_en(priv, phy, false);
}

static void ar8327_phy_powerdown(struct ar8xxx_priv *priv)
{
	int i;
	u16 phy_val;
	struct mii_bus *bus;

	bus = priv->phy->bus;

	for (i = 1; i < AR8327_NUM_PORTS - 1; i++) {
		mdiobus_write(bus, i, MII_BMCR, BMCR_SPEED1000 | BMCR_FULLDPLX);

		ar8xxx_phy_dbg_read(priv, i, AR8327_PHY_DEBUG_GREEN, &phy_val);
		phy_val &= (~(AR8327_PHY_GATE_CLK_IN1000));
		ar8xxx_phy_dbg_write(priv, i, AR8327_PHY_DEBUG_GREEN, phy_val);

		/* PHY will stop the tx clock for a while when link is down
		 *	1. bit13 = 0, speed up link down tx_clk
		 *	2. bit10 = 0, speed up speed mode change to 2'b10 tx_clk
		 */
		ar8xxx_phy_dbg_read(priv, i,
				    AR8327_PHY_DEBUG_HIB_CTRL, &phy_val);
		phy_val &= ~(AR8327_PHY_HIB_CTRL_SEL_RST_80U |
				AR8327_PHY_HIB_CTRL_EN_ANY_CHANGE);
		ar8xxx_phy_dbg_write(priv, i,
				     AR8327_PHY_DEBUG_HIB_CTRL, phy_val);
	}
}

static u32
ar8327_get_port_init_status(struct ar8327_port_cfg *cfg)
{
	u32 t;

	if (!cfg->force_link)
		return AR8216_PORT_STATUS_LINK_AUTO;

	t = AR8216_PORT_STATUS_TXMAC | AR8216_PORT_STATUS_RXMAC;
	t |= cfg->duplex ? AR8216_PORT_STATUS_DUPLEX : 0;
	t |= cfg->rxpause ? AR8216_PORT_STATUS_RXFLOW : 0;
	t |= cfg->txpause ? AR8216_PORT_STATUS_TXFLOW : 0;

	switch (cfg->speed) {
	case AR8327_PORT_SPEED_10:
		t |= AR8216_PORT_SPEED_10M;
		break;
	case AR8327_PORT_SPEED_100:
		t |= AR8216_PORT_SPEED_100M;
		break;
	case AR8327_PORT_SPEED_1000:
		t |= AR8216_PORT_SPEED_1000M;
		break;
	}

	return t;
}

#define AR8327_LED_ENTRY(_num, _reg, _shift) \
	[_num] = { .reg = (_reg), .shift = (_shift) }

static const struct ar8327_led_entry
ar8327_led_map[AR8327_NUM_LEDS] = {
	AR8327_LED_ENTRY(AR8327_LED_PHY0_0, 0, 14),
	AR8327_LED_ENTRY(AR8327_LED_PHY0_1, 1, 14),
	AR8327_LED_ENTRY(AR8327_LED_PHY0_2, 2, 14),

	AR8327_LED_ENTRY(AR8327_LED_PHY1_0, 3, 8),
	AR8327_LED_ENTRY(AR8327_LED_PHY1_1, 3, 10),
	AR8327_LED_ENTRY(AR8327_LED_PHY1_2, 3, 12),

	AR8327_LED_ENTRY(AR8327_LED_PHY2_0, 3, 14),
	AR8327_LED_ENTRY(AR8327_LED_PHY2_1, 3, 16),
	AR8327_LED_ENTRY(AR8327_LED_PHY2_2, 3, 18),

	AR8327_LED_ENTRY(AR8327_LED_PHY3_0, 3, 20),
	AR8327_LED_ENTRY(AR8327_LED_PHY3_1, 3, 22),
	AR8327_LED_ENTRY(AR8327_LED_PHY3_2, 3, 24),

	AR8327_LED_ENTRY(AR8327_LED_PHY4_0, 0, 30),
	AR8327_LED_ENTRY(AR8327_LED_PHY4_1, 1, 30),
	AR8327_LED_ENTRY(AR8327_LED_PHY4_2, 2, 30),
};

static void
ar8327_set_led_pattern(struct ar8xxx_priv *priv, unsigned int led_num,
		       enum ar8327_led_pattern pattern)
{
	const struct ar8327_led_entry *entry;

	entry = &ar8327_led_map[led_num];
	ar8xxx_rmw(priv, AR8327_REG_LED_CTRL(entry->reg),
		   (3 << entry->shift), pattern << entry->shift);
}

static void
ar8327_led_work_func(struct work_struct *work)
{
	struct ar8327_led *aled;
	u8 pattern;

	aled = container_of(work, struct ar8327_led, led_work);

	spin_lock(&aled->lock);
	pattern = aled->pattern;
	spin_unlock(&aled->lock);

	ar8327_set_led_pattern(aled->sw_priv, aled->led_num,
			       pattern);
}

static void
ar8327_led_schedule_change(struct ar8327_led *aled, u8 pattern)
{
	if (aled->pattern == pattern)
		return;

	aled->pattern = pattern;
	schedule_work(&aled->led_work);
}

static inline struct ar8327_led *
led_cdev_to_ar8327_led(struct led_classdev *led_cdev)
{
	return container_of(led_cdev, struct ar8327_led, cdev);
}

static int
ar8327_led_blink_set(struct led_classdev *led_cdev,
		     unsigned long *delay_on,
		     unsigned long *delay_off)
{
	struct ar8327_led *aled = led_cdev_to_ar8327_led(led_cdev);

	if (*delay_on == 0 && *delay_off == 0) {
		*delay_on = 125;
		*delay_off = 125;
	}

	if (*delay_on != 125 || *delay_off != 125) {
		/* The hardware only supports blinking at 4Hz. Fall back
		 * to software implementation in other cases.
		 */
		return -EINVAL;
	}

	spin_lock(&aled->lock);

	aled->enable_hw_mode = false;
	ar8327_led_schedule_change(aled, AR8327_LED_PATTERN_BLINK);

	spin_unlock(&aled->lock);

	return 0;
}

static void
ar8327_led_set_brightness(struct led_classdev *led_cdev,
			  enum led_brightness brightness)
{
	struct ar8327_led *aled = led_cdev_to_ar8327_led(led_cdev);
	u8 pattern;
	bool active;

	active = (brightness != LED_OFF);
	active ^= aled->active_low;

	pattern = (active) ? AR8327_LED_PATTERN_ON :
			     AR8327_LED_PATTERN_OFF;

	spin_lock(&aled->lock);

	aled->enable_hw_mode = false;
	ar8327_led_schedule_change(aled, pattern);

	spin_unlock(&aled->lock);
}

static ssize_t
ar8327_led_enable_hw_mode_show(struct device *dev,
			       struct device_attribute *attr,
			       char *buf)
{
	struct led_classdev *led_cdev = dev_get_drvdata(dev);
	struct ar8327_led *aled = led_cdev_to_ar8327_led(led_cdev);
	ssize_t ret = 0;

	spin_lock(&aled->lock);
	ret += sprintf(buf, "%d\n", aled->enable_hw_mode);
	spin_unlock(&aled->lock);

	return ret;
}

static ssize_t
ar8327_led_enable_hw_mode_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf,
				size_t size)
{
	struct led_classdev *led_cdev = dev_get_drvdata(dev);
	struct ar8327_led *aled = led_cdev_to_ar8327_led(led_cdev);
	u8 pattern;
	u8 value;
	int ret;

	ret = kstrtou8(buf, 10, &value);
	if (ret < 0)
		return -EINVAL;

	spin_lock(&aled->lock);

	aled->enable_hw_mode = !!value;
	if (aled->enable_hw_mode)
		pattern = AR8327_LED_PATTERN_RULE;
	else
		pattern = AR8327_LED_PATTERN_OFF;

	ar8327_led_schedule_change(aled, pattern);

	spin_unlock(&aled->lock);

	return size;
}

static DEVICE_ATTR(enable_hw_mode,  S_IRUGO | S_IWUSR,
		   ar8327_led_enable_hw_mode_show,
		   ar8327_led_enable_hw_mode_store);

static int
ar8327_led_register(struct ar8327_led *aled)
{
	int ret;

	ret = led_classdev_register(NULL, &aled->cdev);
	if (ret < 0)
		return ret;

	if (aled->mode == AR8327_LED_MODE_HW) {
		ret = device_create_file(aled->cdev.dev,
					 &dev_attr_enable_hw_mode);
		if (ret)
			goto err_unregister;
	}

	return 0;

err_unregister:
	led_classdev_unregister(&aled->cdev);
	return ret;
}

static void
ar8327_led_unregister(struct ar8327_led *aled)
{
	if (aled->mode == AR8327_LED_MODE_HW)
		device_remove_file(aled->cdev.dev, &dev_attr_enable_hw_mode);

	led_classdev_unregister(&aled->cdev);
	cancel_work_sync(&aled->led_work);
}

static int
ar8327_led_create(struct ar8xxx_priv *priv,
		  const struct ar8327_led_info *led_info)
{
	struct ar8327_data *data = priv->chip_data;
	struct ar8327_led *aled;
	int ret;

	if (!IS_ENABLED(CONFIG_AR8216_PHY_LEDS))
		return 0;

	if (!led_info->name)
		return -EINVAL;

	if (led_info->led_num >= AR8327_NUM_LEDS)
		return -EINVAL;

	aled = kzalloc(sizeof(*aled) + strlen(led_info->name) + 1,
		       GFP_KERNEL);
	if (!aled)
		return -ENOMEM;

	aled->sw_priv = priv;
	aled->led_num = led_info->led_num;
	aled->active_low = led_info->active_low;
	aled->mode = led_info->mode;

	if (aled->mode == AR8327_LED_MODE_HW)
		aled->enable_hw_mode = true;

	aled->name = (char *)(aled + 1);
	strcpy(aled->name, led_info->name);

	aled->cdev.name = aled->name;
	aled->cdev.brightness_set = ar8327_led_set_brightness;
	aled->cdev.blink_set = ar8327_led_blink_set;
	aled->cdev.default_trigger = led_info->default_trigger;

	spin_lock_init(&aled->lock);
	mutex_init(&aled->mutex);
	INIT_WORK(&aled->led_work, ar8327_led_work_func);

	ret = ar8327_led_register(aled);
	if (ret)
		goto err_free;

	data->leds[data->num_leds++] = aled;

	return 0;

err_free:
	kfree(aled);
	return ret;
}

static void
ar8327_led_destroy(struct ar8327_led *aled)
{
	ar8327_led_unregister(aled);
	kfree(aled);
}

static void
ar8327_leds_init(struct ar8xxx_priv *priv)
{
	struct ar8327_data *data = priv->chip_data;
	unsigned i;

	if (!IS_ENABLED(CONFIG_AR8216_PHY_LEDS))
		return;

	for (i = 0; i < data->num_leds; i++) {
		struct ar8327_led *aled;

		aled = data->leds[i];

		if (aled->enable_hw_mode)
			aled->pattern = AR8327_LED_PATTERN_RULE;
		else
			aled->pattern = AR8327_LED_PATTERN_OFF;

		ar8327_set_led_pattern(priv, aled->led_num, aled->pattern);
	}
}

static void
ar8327_leds_cleanup(struct ar8xxx_priv *priv)
{
	struct ar8327_data *data = priv->chip_data;
	unsigned i;

	if (!IS_ENABLED(CONFIG_AR8216_PHY_LEDS))
		return;

	for (i = 0; i < data->num_leds; i++) {
		struct ar8327_led *aled;

		aled = data->leds[i];
		ar8327_led_destroy(aled);
	}

	kfree(data->leds);
}

static int
ar8327_hw_config_pdata(struct ar8xxx_priv *priv,
		       struct ar8327_platform_data *pdata)
{
	struct ar8327_led_cfg *led_cfg;
	struct ar8327_data *data = priv->chip_data;
	u32 pos, new_pos;
	u32 t;

	if (!pdata)
		return -EINVAL;

	priv->get_port_link = pdata->get_port_link;

	data->port0_status = ar8327_get_port_init_status(&pdata->port0_cfg);
	data->port6_status = ar8327_get_port_init_status(&pdata->port6_cfg);

	t = ar8327_get_pad_cfg(pdata->pad0_cfg);
	if (chip_is_ar8337(priv) && !pdata->pad0_cfg->mac06_exchange_dis)
		t |= AR8337_PAD_MAC06_EXCHANGE_EN;
	ar8xxx_write(priv, AR8327_REG_PAD0_MODE, t);

	t = ar8327_get_pad_cfg(pdata->pad5_cfg);
	ar8xxx_write(priv, AR8327_REG_PAD5_MODE, t);
	t = ar8327_get_pad_cfg(pdata->pad6_cfg);
	ar8xxx_write(priv, AR8327_REG_PAD6_MODE, t);

	pos = ar8xxx_read(priv, AR8327_REG_POWER_ON_STRIP);
	new_pos = pos;

	led_cfg = pdata->led_cfg;
	if (led_cfg) {
		if (led_cfg->open_drain)
			new_pos |= AR8327_POWER_ON_STRIP_LED_OPEN_EN;
		else
			new_pos &= ~AR8327_POWER_ON_STRIP_LED_OPEN_EN;

		ar8xxx_write(priv, AR8327_REG_LED_CTRL0, led_cfg->led_ctrl0);
		ar8xxx_write(priv, AR8327_REG_LED_CTRL1, led_cfg->led_ctrl1);
		ar8xxx_write(priv, AR8327_REG_LED_CTRL2, led_cfg->led_ctrl2);
		ar8xxx_write(priv, AR8327_REG_LED_CTRL3, led_cfg->led_ctrl3);

		if (new_pos != pos)
			new_pos |= AR8327_POWER_ON_STRIP_POWER_ON_SEL;
	}

	if (pdata->sgmii_cfg) {
		t = pdata->sgmii_cfg->sgmii_ctrl;
		if (priv->chip_rev == 1)
			t |= AR8327_SGMII_CTRL_EN_PLL |
			     AR8327_SGMII_CTRL_EN_RX |
			     AR8327_SGMII_CTRL_EN_TX;
		else
			t &= ~(AR8327_SGMII_CTRL_EN_PLL |
			       AR8327_SGMII_CTRL_EN_RX |
			       AR8327_SGMII_CTRL_EN_TX);

		ar8xxx_write(priv, AR8327_REG_SGMII_CTRL, t);

		if (pdata->sgmii_cfg->serdes_aen)
			new_pos &= ~AR8327_POWER_ON_STRIP_SERDES_AEN;
		else
			new_pos |= AR8327_POWER_ON_STRIP_SERDES_AEN;
	}

	ar8xxx_write(priv, AR8327_REG_POWER_ON_STRIP, new_pos);

	if (pdata->leds && pdata->num_leds) {
		int i;

		data->leds = kzalloc(pdata->num_leds * sizeof(void *),
				     GFP_KERNEL);
		if (!data->leds)
			return -ENOMEM;

		for (i = 0; i < pdata->num_leds; i++)
			ar8327_led_create(priv, &pdata->leds[i]);
	}

	return 0;
}

#ifdef CONFIG_OF
static int
ar8327_hw_config_of(struct ar8xxx_priv *priv, struct device_node *np)
{
	struct ar8327_data *data = priv->chip_data;
	const __be32 *paddr;
	int len;
	int i;

	paddr = of_get_property(np, "qca,ar8327-initvals", &len);
	if (!paddr || len < (2 * sizeof(*paddr)))
		return -EINVAL;

	len /= sizeof(*paddr);

	for (i = 0; i < len - 1; i += 2) {
		u32 reg;
		u32 val;

		reg = be32_to_cpup(paddr + i);
		val = be32_to_cpup(paddr + i + 1);

		switch (reg) {
		case AR8327_REG_PORT_STATUS(0):
			data->port0_status = val;
			break;
		case AR8327_REG_PORT_STATUS(6):
			data->port6_status = val;
			break;
		default:
			ar8xxx_write(priv, reg, val);
			break;
		}
	}

	return 0;
}
#else
static inline int
ar8327_hw_config_of(struct ar8xxx_priv *priv, struct device_node *np)
{
	return -EINVAL;
}
#endif

static int
ar8327_hw_init(struct ar8xxx_priv *priv)
{
	int ret;
	u32 value;

	ar8327_phy_powerdown(priv);

	priv->chip_data = kzalloc(sizeof(struct ar8327_data), GFP_KERNEL);
	if (!priv->chip_data)
		return -ENOMEM;

	if (priv->phy->dev.of_node)
		ret = ar8327_hw_config_of(priv, priv->phy->dev.of_node);
	else
		ret = ar8327_hw_config_pdata(priv,
					     priv->phy->dev.platform_data);

	if (ret)
		return ret;

	value = ar8xxx_read(priv, AR8327_REG_MODULE_EN);
	value &= ~AR8327_MODULE_EN_QM_ERR;
	value &= ~AR8327_MODULE_EN_LOOKUP_ERR;
	ar8xxx_write(priv, AR8327_REG_MODULE_EN, value);

	ar8327_leds_init(priv);

	return 0;
}

static void
ar8327_cleanup(struct ar8xxx_priv *priv)
{
	ar8327_leds_cleanup(priv);
}

static void
ar8327_init_globals(struct ar8xxx_priv *priv)
{
	struct ar8327_data *data = priv->chip_data;
	u32 t;
	int i;

	/* enable CPU port and disable mirror port */
	t = AR8327_FWD_CTRL0_CPU_PORT_EN |
	    AR8327_FWD_CTRL0_MIRROR_PORT;
	ar8xxx_write(priv, AR8327_REG_FWD_CTRL0, t);

	/* forward multicast and broadcast frames to CPU */
	t = (AR8327_PORTS_ALL << AR8327_FWD_CTRL1_UC_FLOOD_S) |
	    (AR8327_PORTS_ALL << AR8327_FWD_CTRL1_MC_FLOOD_S) |
	    (AR8327_PORTS_ALL << AR8327_FWD_CTRL1_BC_FLOOD_S);
	ar8xxx_write(priv, AR8327_REG_FWD_CTRL1, t);

	/* setup MTU */
	ar8xxx_rmw(priv, AR8327_REG_MAX_FRAME_SIZE,
		   AR8327_MAX_FRAME_SIZE_MTU, 1518 + 8 + 2);

	/* Enable MIB counters */
	ar8xxx_reg_set(priv, AR8327_REG_MODULE_EN,
		       AR8327_MODULE_EN_MIB);

	/* Disable EEE on all phy's due to stability issues */
	for (i = 0; i < AR8XXX_NUM_PHYS; i++)
		data->eee[i] = false;

	/* Updating HOL registers and RGMII delay settings
	 * with the values suggested by QCA switch team
	 */

	if (chip_is_ar8337(priv)) {
		ar8xxx_write(priv, AR8327_REG_PAD5_MODE,
			AR8327_PAD_RGMII_RXCLK_DELAY_EN);

		ar8xxx_write(priv, 0x970, 0x1e864443);
		ar8xxx_write(priv, 0x974, 0x000001c6);
		ar8xxx_write(priv, 0x978, 0x19008643);
		ar8xxx_write(priv, 0x97c, 0x000001c6);
		ar8xxx_write(priv, 0x980, 0x19008643);
		ar8xxx_write(priv, 0x984, 0x000001c6);
		ar8xxx_write(priv, 0x988, 0x19008643);
		ar8xxx_write(priv, 0x98c, 0x000001c6);
		ar8xxx_write(priv, 0x990, 0x19008643);
		ar8xxx_write(priv, 0x994, 0x000001c6);
		ar8xxx_write(priv, 0x998, 0x1e864443);
		ar8xxx_write(priv, 0x99c, 0x000001c6);
		ar8xxx_write(priv, 0x9a0, 0x1e864443);
		ar8xxx_write(priv, 0x9a4, 0x000001c6);

	}

	if (chip_is_ar8327(priv))
		ar8xxx_write(priv, AR8327_REG_GLOBAL_FC_THRESH,
				AR8327_GLOBAL_FC_THRESH_DFLT_VAL);

	/* Disable NAT/NAPT */
	t = ar8xxx_read(priv, AR8327_REG_NAT_CTRL);
	t &= ~(AR8327_HNAPT_EN | AR8327_HNAT_EN);
	ar8xxx_write(priv, AR8327_REG_NAT_CTRL, t);
}

static void
ar8327_init_port(struct ar8xxx_priv *priv, int port)
{
	struct ar8327_data *data = priv->chip_data;
	u32 t;

	if (port == AR8216_PORT_CPU)
		t = data->port0_status;
	else if (port == 6)
		t = data->port6_status;
	else {
		t = ar8xxx_read(priv, AR8327_REG_PORT_STATUS(port));
		t &= (~(AR8216_PORT_STATUS_LINK_AUTO |
			AR8327_PORT_STATUS_DUPLEX |
			AR8327_PORT_STATUS_SPEED));
		t |= (AR8327_PORT_STATUS_DUPLEX | AR8327_SPEED_1000M);
	}

	ar8xxx_write(priv, AR8327_REG_PORT_STATUS(port),
		t & (~(AR8216_PORT_STATUS_TXMAC | AR8216_PORT_STATUS_RXMAC)));
	udelay(800);
	ar8xxx_write(priv, AR8327_REG_PORT_STATUS(port), t);

	ar8xxx_write(priv, AR8327_REG_PORT_HEADER(port), 0);

	t = 1 << AR8327_PORT_VLAN0_DEF_SVID_S;
	t |= 1 << AR8327_PORT_VLAN0_DEF_CVID_S;
	ar8xxx_write(priv, AR8327_REG_PORT_VLAN0(port), t);

	t = AR8327_PORT_VLAN1_OUT_MODE_UNTOUCH << AR8327_PORT_VLAN1_OUT_MODE_S;
	ar8xxx_write(priv, AR8327_REG_PORT_VLAN1(port), t);

	t = AR8327_PORT_LOOKUP_LEARN;
	t |= AR8216_PORT_STATE_FORWARD << AR8327_PORT_LOOKUP_STATE_S;
	ar8xxx_write(priv, AR8327_REG_PORT_LOOKUP(port), t);
}

static u32
ar8327_read_port_status(struct ar8xxx_priv *priv, int port)
{
	u32 t;

	t = ar8xxx_read(priv, AR8327_REG_PORT_STATUS(port));
	/* map the flow control autoneg result bits to the flow control bits
	 * used in forced mode to allow ar8216_read_port_link detect
	 * flow control properly if autoneg is used
	 */
	if (t & AR8216_PORT_STATUS_LINK_UP &&
	    t & AR8216_PORT_STATUS_LINK_AUTO) {
		t &= ~(AR8216_PORT_STATUS_TXFLOW | AR8216_PORT_STATUS_RXFLOW);
		if (t & AR8327_PORT_STATUS_TXFLOW_AUTO)
			t |= AR8216_PORT_STATUS_TXFLOW;
		if (t & AR8327_PORT_STATUS_RXFLOW_AUTO)
			t |= AR8216_PORT_STATUS_RXFLOW;
	}

	return t;
}

static u32
ar8327_read_port_eee_status(struct ar8xxx_priv *priv, int port)
{
	int phy;
	u16 t;

	if (port >= priv->dev.ports)
		return 0;

	if (port == 0 || port == 6)
		return 0;

	phy = port - 1;

	/* EEE Ability Auto-negotiation Result */
	ar8xxx_phy_mmd_write(priv, phy, 0x7, 0x8000);
	t = ar8xxx_phy_mmd_read(priv, phy, 0x4007);

	return mmd_eee_adv_to_ethtool_adv_t(t);
}

static int
ar8327_atu_flush(struct ar8xxx_priv *priv)
{
	int ret;

	ret = ar8216_wait_bit(priv, AR8327_REG_ATU_FUNC,
			      AR8327_ATU_FUNC_BUSY, 0);
	if (!ret)
		ar8xxx_write(priv, AR8327_REG_ATU_FUNC,
			     AR8327_ATU_FUNC_OP_FLUSH |
			     AR8327_ATU_FUNC_BUSY);

	return ret;
}

static int
ar8327_atu_flush_port(struct ar8xxx_priv *priv, int port)
{
	u32 t;
	int ret;

	ret = ar8216_wait_bit(priv, AR8327_REG_ATU_FUNC,
			      AR8327_ATU_FUNC_BUSY, 0);
	if (!ret) {
		t = (port << AR8327_ATU_PORT_NUM_S);
		t |= AR8327_ATU_FUNC_OP_FLUSH_PORT;
		t |= AR8327_ATU_FUNC_BUSY;
		ar8xxx_write(priv, AR8327_REG_ATU_FUNC, t);
	}

	return ret;
}

static void
ar8327_vtu_op(struct ar8xxx_priv *priv, u32 op, u32 val)
{
	if (ar8216_wait_bit(priv, AR8327_REG_VTU_FUNC1,
			    AR8327_VTU_FUNC1_BUSY, 0))
		return;

	if ((op & AR8327_VTU_FUNC1_OP) == AR8327_VTU_FUNC1_OP_LOAD)
		ar8xxx_write(priv, AR8327_REG_VTU_FUNC0, val);

	op |= AR8327_VTU_FUNC1_BUSY;
	ar8xxx_write(priv, AR8327_REG_VTU_FUNC1, op);
}

static void
ar8327_vtu_flush(struct ar8xxx_priv *priv)
{
	ar8327_vtu_op(priv, AR8327_VTU_FUNC1_OP_FLUSH, 0);
}

static void
ar8327_vtu_load_vlan(struct ar8xxx_priv *priv, u32 vid, u32 port_mask)
{
	u32 op;
	u32 val;
	int i;

	op = AR8327_VTU_FUNC1_OP_LOAD | (vid << AR8327_VTU_FUNC1_VID_S);
	val = AR8327_VTU_FUNC0_VALID | AR8327_VTU_FUNC0_IVL;
	for (i = 0; i < AR8327_NUM_PORTS; i++) {
		u32 mode;

		if ((port_mask & BIT(i)) == 0)
			mode = AR8327_VTU_FUNC0_EG_MODE_NOT;
		else if (priv->vlan == 0)
			mode = AR8327_VTU_FUNC0_EG_MODE_KEEP;
		else if ((priv->vlan_tagged & BIT(i)) ||
			(priv->vlan_id[priv->pvid[i]] != vid))
			mode = AR8327_VTU_FUNC0_EG_MODE_TAG;
		else
			mode = AR8327_VTU_FUNC0_EG_MODE_UNTAG;

		val |= mode << AR8327_VTU_FUNC0_EG_MODE_S(i);
	}
	ar8327_vtu_op(priv, op, val);
}

static void
ar8327_setup_port(struct ar8xxx_priv *priv, int port, u32 members)
{
	u32 t;
	u32 egress, ingress;
	u32 pvid = priv->vlan_id[priv->pvid[port]];

	egress = AR8327_PORT_VLAN1_OUT_MODE_UNMOD;
	if (priv->vlan) {
		pvid = priv->vlan_id[priv->pvid[port]];
		if (priv->vlan_tagged & (1 << port))
			egress = AR8327_PORT_VLAN1_OUT_MODE_TAG;
		else
			egress = AR8327_PORT_VLAN1_OUT_MODE_UNTAG;
		ingress = AR8216_IN_SECURE;
	} else {
		pvid = 0;
		egress = AR8327_PORT_VLAN1_OUT_MODE_UNTOUCH;
		ingress = AR8216_IN_PORT_ONLY;
	}

	t = pvid << AR8327_PORT_VLAN0_DEF_SVID_S;
	t |= pvid << AR8327_PORT_VLAN0_DEF_CVID_S;
	ar8xxx_write(priv, AR8327_REG_PORT_VLAN0(port), t);

	t = AR8327_PORT_VLAN1_PORT_VLAN_PROP;
	t |= egress << AR8327_PORT_VLAN1_OUT_MODE_S;
	ar8xxx_write(priv, AR8327_REG_PORT_VLAN1(port), t);

	t = members;
	t |= AR8327_PORT_LOOKUP_LEARN;
	t |= ingress << AR8327_PORT_LOOKUP_IN_MODE_S;
	t |= AR8216_PORT_STATE_FORWARD << AR8327_PORT_LOOKUP_STATE_S;
	ar8xxx_write(priv, AR8327_REG_PORT_LOOKUP(port), t);

	t = ar8xxx_read(priv, AR8327_REG_ROUTE_EG_MODE);
	t &= (~(0x3 << AR8327_ROUTE_EG_MODE_S(port)));
	t |= egress << AR8327_ROUTE_EG_MODE_S(port);
	ar8xxx_write(priv, AR8327_REG_ROUTE_EG_MODE, t);
}

static int
ar8327_sw_get_ports(struct switch_dev *dev, struct switch_val *val)
{
	struct ar8xxx_priv *priv = swdev_to_ar8xxx(dev);
	u8 ports = priv->vlan_table[val->port_vlan];
	int i;

	val->len = 0;
	for (i = 0; i < dev->ports; i++) {
		struct switch_port *p;

		if (!(ports & (1 << i)))
			continue;

		p = &val->value.ports[val->len++];
		p->id = i;
		if (priv->vlan_tagged & (1 << i))
			p->flags = (1 << SWITCH_PORT_FLAG_TAGGED);
		else
			p->flags = 0;
	}
	return 0;
}

static int
ar8327_sw_set_ports(struct switch_dev *dev, struct switch_val *val)
{
	struct ar8xxx_priv *priv = swdev_to_ar8xxx(dev);
	u8 *vt = &priv->vlan_table[val->port_vlan];
	int i, j;

	*vt = 0;
	for (i = 0; i < val->len; i++) {
		struct switch_port *p = &val->value.ports[i];

		if (p->flags & (1 << SWITCH_PORT_FLAG_TAGGED)) {
			priv->vlan_tagged |= (1 << p->id);
		} else {
			priv->vlan_tagged &= ~(1 << p->id);
			priv->pvid[p->id] = val->port_vlan;

			/* make sure that untagged port does not
			 * appear in other vlans
			 */
			for (j = 0; j < AR8X16_MAX_VLANS; j++) {
				if (j == val->port_vlan)
					continue;
				priv->vlan_table[j] &= ~(1 << p->id);
			}
		}

		*vt |= 1 << p->id;
	}
	return 0;
}

static void
ar8327_set_mirror_regs(struct ar8xxx_priv *priv)
{
	int port;

	/* reset all mirror registers */
	ar8xxx_rmw(priv, AR8327_REG_FWD_CTRL0,
		   AR8327_FWD_CTRL0_MIRROR_PORT,
		   (0xF << AR8327_FWD_CTRL0_MIRROR_PORT_S));
	for (port = 0; port < AR8327_NUM_PORTS; port++) {
		ar8xxx_reg_clear(priv, AR8327_REG_PORT_LOOKUP(port),
			   AR8327_PORT_LOOKUP_ING_MIRROR_EN);

		ar8xxx_reg_clear(priv, AR8327_REG_PORT_HOL_CTRL1(port),
			   AR8327_PORT_HOL_CTRL1_EG_MIRROR_EN);
	}

	/* now enable mirroring if necessary */
	if (priv->source_port >= AR8327_NUM_PORTS ||
	    priv->monitor_port >= AR8327_NUM_PORTS ||
	    priv->source_port == priv->monitor_port) {
		return;
	}

	ar8xxx_rmw(priv, AR8327_REG_FWD_CTRL0,
		   AR8327_FWD_CTRL0_MIRROR_PORT,
		   (priv->monitor_port << AR8327_FWD_CTRL0_MIRROR_PORT_S));

	if (priv->mirror_rx)
		ar8xxx_reg_set(priv, AR8327_REG_PORT_LOOKUP(priv->source_port),
			   AR8327_PORT_LOOKUP_ING_MIRROR_EN);

	if (priv->mirror_tx)
		ar8xxx_reg_set(priv,
				AR8327_REG_PORT_HOL_CTRL1(priv->source_port),
				AR8327_PORT_HOL_CTRL1_EG_MIRROR_EN);
}

static int
ar8327_sw_set_eee(struct switch_dev *dev,
		  const struct switch_attr *attr,
		  struct switch_val *val)
{
	struct ar8xxx_priv *priv = swdev_to_ar8xxx(dev);
	struct ar8327_data *data = priv->chip_data;
	int port = val->port_vlan;
	int phy;

	if (port >= dev->ports)
		return -EINVAL;
	if (port == 0 || port == 6)
		return -EOPNOTSUPP;

	phy = port - 1;

	data->eee[phy] = !!(val->value.i);

	return 0;
}

static int
ar8327_sw_get_eee(struct switch_dev *dev,
		  const struct switch_attr *attr,
		  struct switch_val *val)
{
	struct ar8xxx_priv *priv = swdev_to_ar8xxx(dev);
	const struct ar8327_data *data = priv->chip_data;
	int port = val->port_vlan;
	int phy;

	if (port >= dev->ports)
		return -EINVAL;
	if (port == 0 || port == 6)
		return -EOPNOTSUPP;

	phy = port - 1;

	val->value.i = data->eee[phy];

	return 0;
}

static void
ar8327_wait_atu_ready(struct ar8xxx_priv *priv, u16 r2, u16 r1)
{
	int timeout = 20;

	while (ar8xxx_mii_read32(priv, r2, r1) & AR8327_ATU_FUNC_BUSY &&
		--timeout)
		udelay(10);

	if (!timeout)
		pr_err("ar8327: timeout waiting for atu to become ready\n");
}

static void ar8327_get_arl_entry(struct ar8xxx_priv *priv,
				 struct arl_entry *a,
				 u32 *status, enum arl_op op)
{
	struct mii_bus *bus = priv->mii_bus;
	u16 r2, page;
	u16 r1_data0, r1_data1, r1_data2, r1_func;
	u32 t, val0, val1, val2;
	int i;

	split_addr(AR8327_REG_ATU_DATA0, &r1_data0, &r2, &page);
	r2 |= 0x10;

	r1_data1 = (AR8327_REG_ATU_DATA1 >> 1) & 0x1e;
	r1_data2 = (AR8327_REG_ATU_DATA2 >> 1) & 0x1e;
	r1_func  = (AR8327_REG_ATU_FUNC >> 1) & 0x1e;

	switch (op) {
	case AR8XXX_ARL_INITIALIZE:
		/* all ATU registers are on the same page
		* therefore set page only once
		*/
		bus->write(bus, 0x18, 0, page);
		wait_for_page_switch();

		ar8327_wait_atu_ready(priv, r2, r1_func);

		ar8xxx_mii_write32(priv, r2, r1_data0, 0);
		ar8xxx_mii_write32(priv, r2, r1_data1, 0);
		ar8xxx_mii_write32(priv, r2, r1_data2, 0);
		break;
	case AR8XXX_ARL_GET_NEXT:
		ar8xxx_mii_write32(priv, r2, r1_func,
				   AR8327_ATU_FUNC_OP_GET_NEXT |
				   AR8327_ATU_FUNC_BUSY);
		ar8327_wait_atu_ready(priv, r2, r1_func);

		val0 = ar8xxx_mii_read32(priv, r2, r1_data0);
		val1 = ar8xxx_mii_read32(priv, r2, r1_data1);
		val2 = ar8xxx_mii_read32(priv, r2, r1_data2);

		*status = val2 & AR8327_ATU_STATUS;
		if (!*status)
			break;

		i = 0;
		t = AR8327_ATU_PORT0;
		while (!(val1 & t) && ++i < AR8327_NUM_PORTS)
			t <<= 1;

		a->port = i;
		a->mac[0] = (val0 & AR8327_ATU_ADDR0) >> AR8327_ATU_ADDR0_S;
		a->mac[1] = (val0 & AR8327_ATU_ADDR1) >> AR8327_ATU_ADDR1_S;
		a->mac[2] = (val0 & AR8327_ATU_ADDR2) >> AR8327_ATU_ADDR2_S;
		a->mac[3] = (val0 & AR8327_ATU_ADDR3) >> AR8327_ATU_ADDR3_S;
		a->mac[4] = (val1 & AR8327_ATU_ADDR4) >> AR8327_ATU_ADDR4_S;
		a->mac[5] = (val1 & AR8327_ATU_ADDR5) >> AR8327_ATU_ADDR5_S;
		break;
	}
}

static int
ar8327_sw_hw_apply(struct switch_dev *dev)
{
	struct ar8xxx_priv *priv = swdev_to_ar8xxx(dev);
	const struct ar8327_data *data = priv->chip_data;
	int ret, i;

	ret = ar8xxx_sw_hw_apply(dev);
	if (ret)
		return ret;

	for (i = 0; i < AR8XXX_NUM_PHYS; i++) {
		if (data->eee[i])
			ar8xxx_reg_clear(priv, AR8327_REG_EEE_CTRL,
			       AR8327_EEE_CTRL_DISABLE_PHY(i));
		else
			ar8xxx_reg_set(priv, AR8327_REG_EEE_CTRL,
			       AR8327_EEE_CTRL_DISABLE_PHY(i));
	}

	return 0;
}

static int
ar8327_sw_set_max_frame_size(struct switch_dev *dev,
			const struct switch_attr *attr,
			struct switch_val *val)
{
	struct ar8xxx_priv *priv = swdev_to_ar8xxx(dev);

	ar8xxx_rmw(priv, AR8327_REG_MAX_FRAME_SIZE,
			AR8327_MAX_FRAME_SIZE_MTU, val->value.i + 8 + 2);
	return 0;
}

static int
ar8327_sw_get_max_frame_size(struct switch_dev *dev,
			const struct switch_attr *attr,
			struct switch_val *val)
{
	u32 v;
	struct ar8xxx_priv *priv = swdev_to_ar8xxx(dev);

	v = ar8xxx_rmr(priv, AR8327_REG_MAX_FRAME_SIZE,
			AR8327_MAX_FRAME_SIZE_MTU);

	val->value.i = v;
	return 0;
}

#define AR8327_PORT_LINK_UP 1
#define AR8327_PORT_LINK_DOWN 0

#define AR8327_QM_NOT_EMPTY  1
#define AR8327_QM_EMPTY  0

static u32 port_link_up[AR8327_NUM_PORTS] = {0};

static u32 ar8327_port_old_link[AR8327_NUM_PORTS] = {0};
static u32 ar8327_port_old_speed[AR8327_NUM_PORTS] = {0};
static u32 ar8327_port_old_duplex[AR8327_NUM_PORTS] = {0};

static port_link_notify_func port_link_callback;

void ar8327_port_link_notify_register(port_link_notify_func func)
{
	u32 port_id;

	port_link_callback = func;

	for (port_id = 1; port_id < AR8327_NUM_PORTS - 1; port_id++) {
		if (ar8327_port_old_link[port_id] == AR8327_PORT_LINK_UP)
			(*func)(port_id, ar8327_port_old_link[port_id],
				ar8327_port_old_speed[port_id],
				ar8327_port_old_duplex[port_id]);
	}
}
EXPORT_SYMBOL(ar8327_port_link_notify_register);

static int
ar8327_sw_reset_switch_after_qm_err(struct ar8xxx_priv *priv)
{
	int i;
	int ret;
	u32 value;
	struct mii_bus *bus;

	bus = priv->phy->bus;

	mutex_lock(&priv->reg_mutex);

	ar8327_init_globals(priv);

	for (i = 0; i < priv->dev.ports; i++)
		ar8327_init_port(priv, i);

	mutex_unlock(&priv->reg_mutex);

	ret = ar8327_sw_hw_apply(&priv->dev);

	ar8xxx_phy_init(priv);

	value = ar8xxx_read(priv, AR8327_REG_PORT_STATUS(0));
	value |= AR8216_PORT_STATUS_TXMAC | AR8216_PORT_STATUS_RXMAC;
	ar8xxx_write(priv, AR8327_REG_PORT_STATUS(0), value);

	return ret;
}

static
int ar8327_get_qm_status(struct ar8xxx_priv *priv, u32 port_id, u32 *qm_buffer)
{
	u32 reg;
	u32 qm_val;

	if (port_id < 0 || port_id > 6) {
		*qm_buffer = 0;
		return -1;
	}

	if (port_id < 4) {
		reg = AR8327_REG_QM_PORT0_3_QNUM;
		ar8xxx_write(priv, AR8327_REG_QM_DEBUG_ADDR, reg);
		qm_val = ar8xxx_read(priv, AR8327_REG_QM_DEBUG_VALUE);
		/* every 8 bits for each port */
		*qm_buffer = (qm_val >> (port_id * 8)) & 0xFF;
	} else {
		reg = AR8327_REG_QM_PORT4_6_QNUM;
		ar8xxx_write(priv, AR8327_REG_QM_DEBUG_ADDR, reg);
		qm_val = ar8xxx_read(priv, AR8327_REG_QM_DEBUG_VALUE);
		/* every 8 bits for each port */
		*qm_buffer = (qm_val >> ((port_id - 4) * 8)) & 0xFF;
	}

	return 0;
}

static void ar8327_phy_status_get(struct ar8xxx_priv *priv, u32 port_id,
				  u32 *speed, u32 *link, u32 *duplex)
{
	int port_phy_status;
	struct mii_bus *bus = priv->mii_bus;

	port_phy_status = mdiobus_read(bus, port_id - 1,
				       AR8327_PHY_SPEC_STATUS);

	*speed = ((port_phy_status & AR8327_PHY_SPEC_STATUS_SPEED) >> 14);
	*link = ((port_phy_status & AR8327_PHY_SPEC_STATUS_LINK) >> 10);
	*duplex = ((port_phy_status & AR8327_PHY_SPEC_STATUS_DUPLEX) >> 13);
}

static int ar8327_force_mac_speed_duplex(struct ar8xxx_priv *priv,
					 u32 port_id, u32 speed, u32 duplex)
{
	u32 reg, value;

	if (port_id < 1 || port_id > 5)
		return -1;
	if (priv->chip_ver == AR8XXX_VER_AR8337 ||
	    priv->chip_ver == AR8XXX_VER_AR8327) {
		reg = AR8327_REG_PORT_STATUS(port_id);
		value = ar8xxx_read(priv, reg);
		value &= ~(AR8327_PORT_STATUS_DUPLEX |
				AR8327_PORT_STATUS_SPEED);
		value |= speed;
		if (duplex == AR8327_DUPLEX_FULL)
			value |= AR8327_PORT_STATUS_DUPLEX;
		ar8xxx_write(priv, reg, value);
	}

	return 0;
}

static int ar8327_force_mac_status(struct ar8xxx_priv *priv,
				   u32 port_id, bool link_en)
{
	u32 reg, value;

	if (port_id < 1 || port_id > 5)
		return -1;
	if (priv->chip_ver == AR8XXX_VER_AR8337 ||
	    priv->chip_ver == AR8XXX_VER_AR8327) {
		reg = AR8327_REG_PORT_STATUS(port_id);
		value = ar8xxx_read(priv, reg);
		if (link_en)
			value |= AR8216_PORT_STATUS_LINK_AUTO;
		else
			value &= (~(AR8216_PORT_STATUS_LINK_AUTO));
		ar8xxx_write(priv, reg, value);
	}

	return 0;
}

static int ar8327_qm_error_check(struct ar8xxx_priv *priv)
{
	u32 value, qm_err_int;

	value = ar8xxx_read(priv, 0x24);
	qm_err_int = value & BIT(14);/*b14-QM_ERR_INT*/

	if (qm_err_int)
		return 1;

	ar8xxx_write(priv, 0x820, 0x0);
	value = ar8xxx_read(priv, 0x824);

	return value;
}

static int ar8327_qm_err_recovery(struct ar8xxx_priv *priv)
{
	memset(port_link_up, 0, sizeof(port_link_up));
	memset(ar8327_port_old_link, 0, sizeof(ar8327_port_old_link));
	memset(ar8327_port_old_speed, 0, sizeof(ar8327_port_old_speed));
	memset(ar8327_port_old_duplex, 0, sizeof(ar8327_port_old_duplex));

	ar8327_hw_init(priv);

	ar8327_sw_reset_switch_after_qm_err(priv);

	return 0;
}

static void ar8327_sw_port_link_change(struct ar8xxx_priv *priv,
				       u32 port_id, u32 link,
				       u32 speed, u32 duplex)
{
	u32 qm_buffer = 0;
	/* Up --> Down */
	if ((ar8327_port_old_link[port_id] == AR8327_PORT_LINK_UP) &&
	    (link == AR8327_PORT_LINK_DOWN)) {
		/* LINK_EN disable(MAC force mode) */
		ar8327_force_mac_status(priv, port_id, false);

		ar8327_phy_manu_ctrl_en(priv, port_id - 1, false);

		/* Check queue buffer */
		ar8327_get_qm_status(priv, port_id, &qm_buffer);
		if (qm_buffer == 0) {
			ar8327_force_mac_speed_duplex(priv, port_id,
						      AR8327_SPEED_1000M,
						      AR8327_DUPLEX_FULL);
		}
	} else if ((ar8327_port_old_link[port_id] == AR8327_PORT_LINK_DOWN) &&
		   (link == AR8327_PORT_LINK_UP)) {
		/* Down --> Up */
		if (port_link_up[port_id] < 1) {
			/* linkup need to wait for next cycle */
			++port_link_up[port_id];
			ar8327_get_qm_status(priv, port_id, &qm_buffer);
			if (qm_buffer) {
				ar8327_qm_err_recovery(priv);
				return;
			}
		} else {
			port_link_up[port_id] = 0;
			ar8327_force_mac_speed_duplex(priv, port_id,
						      speed, duplex);
			usleep_range(100, 200);
			ar8327_force_mac_status(priv, port_id, true);

			if (speed == 0x01) {
				/* PHY is link up 100M */
				ar8327_phy_manu_ctrl_en(priv, port_id - 1,
							true);
			}
		}
	}
}

static void ar8327_sw_link_function(struct ar8xxx_priv *priv)
{
	u32 port_id = 0;
	u32 value = 0;
	u32 link = 0, speed = 0, duplex = 0;

	if (!priv)
		return;
	/* if QM error, then do SW recovery, check link the next time */
	value = ar8327_qm_error_check(priv);
	if (value) {
		ar8327_qm_err_recovery(priv);
		return;
	}

	for (port_id = 1; port_id < AR8327_NUM_PORTS - 1; port_id++) {
		ar8327_phy_status_get(priv, port_id, &speed, &link, &duplex);

		if (link != ar8327_port_old_link[port_id]) {
			ar8327_sw_port_link_change(priv, port_id,
						   link, speed, duplex);

			if (port_link_up[port_id] == 0) {
				/* Save the current status */
				ar8327_port_old_speed[port_id] = speed;
				ar8327_port_old_link[port_id] = link;
				ar8327_port_old_duplex[port_id] = duplex;
				if (port_link_callback)
					(*port_link_callback)(port_id, link,
							      speed, duplex);
			}
		}
	}
}

static const struct switch_attr ar8327_sw_attr_globals[] = {
	{
		.type = SWITCH_TYPE_INT,
		.name = "enable_vlan",
		.description = "Enable VLAN mode",
		.set = ar8xxx_sw_set_vlan,
		.get = ar8xxx_sw_get_vlan,
		.max = 1
	},
	{
		.type = SWITCH_TYPE_INT,
		.name = "max_frame_size",
		.description = "Max frame size can be rx and tx by mac",
		.set = ar8327_sw_set_max_frame_size,
		.get = ar8327_sw_get_max_frame_size,
		.max = 9018
	},
	{
		.type = SWITCH_TYPE_NOVAL,
		.name = "reset_mibs",
		.description = "Reset all MIB counters",
		.set = ar8xxx_sw_set_reset_mibs,
	},
	{
		.type = SWITCH_TYPE_INT,
		.name = "enable_mirror_rx",
		.description = "Enable mirroring of RX packets",
		.set = ar8xxx_sw_set_mirror_rx_enable,
		.get = ar8xxx_sw_get_mirror_rx_enable,
		.max = 1
	},
	{
		.type = SWITCH_TYPE_INT,
		.name = "enable_mirror_tx",
		.description = "Enable mirroring of TX packets",
		.set = ar8xxx_sw_set_mirror_tx_enable,
		.get = ar8xxx_sw_get_mirror_tx_enable,
		.max = 1
	},
	{
		.type = SWITCH_TYPE_INT,
		.name = "mirror_monitor_port",
		.description = "Mirror monitor port",
		.set = ar8xxx_sw_set_mirror_monitor_port,
		.get = ar8xxx_sw_get_mirror_monitor_port,
		.max = AR8327_NUM_PORTS - 1
	},
	{
		.type = SWITCH_TYPE_INT,
		.name = "mirror_source_port",
		.description = "Mirror source port",
		.set = ar8xxx_sw_set_mirror_source_port,
		.get = ar8xxx_sw_get_mirror_source_port,
		.max = AR8327_NUM_PORTS - 1
	},
	{
		.type = SWITCH_TYPE_STRING,
		.name = "arl_table",
		.description = "Get ARL table",
		.set = NULL,
		.get = ar8xxx_sw_get_arl_table,
	},
	{
		.type = SWITCH_TYPE_NOVAL,
		.name = "flush_arl_table",
		.description = "Flush ARL table",
		.set = ar8xxx_sw_set_flush_arl_table,
	},
};

static const struct switch_attr ar8327_sw_attr_port[] = {
	{
		.type = SWITCH_TYPE_NOVAL,
		.name = "reset_mib",
		.description = "Reset single port MIB counters",
		.set = ar8xxx_sw_set_port_reset_mib,
	},
	{
		.type = SWITCH_TYPE_STRING,
		.name = "mib",
		.description = "Get port's MIB counters",
		.set = NULL,
		.get = ar8xxx_sw_get_port_mib,
	},
	{
		.type = SWITCH_TYPE_INT,
		.name = "enable_eee",
		.description = "Enable EEE PHY sleep mode",
		.set = ar8327_sw_set_eee,
		.get = ar8327_sw_get_eee,
		.max = 1,
	},
	{
		.type = SWITCH_TYPE_NOVAL,
		.name = "flush_arl_table",
		.description = "Flush port's ARL table entries",
		.set = ar8xxx_sw_set_flush_port_arl_table,
	},
};

static const struct switch_dev_ops ar8327_sw_ops = {
	.attr_global = {
		.attr = ar8327_sw_attr_globals,
		.n_attr = ARRAY_SIZE(ar8327_sw_attr_globals),
	},
	.attr_port = {
		.attr = ar8327_sw_attr_port,
		.n_attr = ARRAY_SIZE(ar8327_sw_attr_port),
	},
	.attr_vlan = {
		.attr = ar8xxx_sw_attr_vlan,
		.n_attr = ARRAY_SIZE(ar8xxx_sw_attr_vlan),
	},
	.get_port_pvid = ar8xxx_sw_get_pvid,
	.set_port_pvid = ar8xxx_sw_set_pvid,
	.get_vlan_ports = ar8327_sw_get_ports,
	.set_vlan_ports = ar8327_sw_set_ports,
	.apply_config = ar8327_sw_hw_apply,
	.reset_switch = ar8xxx_sw_reset_switch,
	.get_port_link = ar8xxx_sw_get_port_link,
};

const struct ar8xxx_chip ar8327_chip = {
	.caps = AR8XXX_CAP_GIGE | AR8XXX_CAP_MIB_COUNTERS,
	.config_at_probe = true,
	.mii_lo_first = true,

	.name = "Atheros AR8327",
	.ports = AR8327_NUM_PORTS,
	.vlans = AR8X16_MAX_VLANS,
	.swops = &ar8327_sw_ops,

	.reg_port_stats_start = 0x1000,
	.reg_port_stats_length = 0x100,

	.hw_init = ar8327_hw_init,
	.cleanup = ar8327_cleanup,
	.init_globals = ar8327_init_globals,
	.init_port = ar8327_init_port,
	.setup_port = ar8327_setup_port,
	.read_port_status = ar8327_read_port_status,
	.read_port_eee_status = ar8327_read_port_eee_status,
	.atu_flush = ar8327_atu_flush,
	.atu_flush_port = ar8327_atu_flush_port,
	.vtu_flush = ar8327_vtu_flush,
	.vtu_load_vlan = ar8327_vtu_load_vlan,
	.phy_fixup = ar8327_phy_fixup,
	.set_mirror_regs = ar8327_set_mirror_regs,
	.get_arl_entry = ar8327_get_arl_entry,
	.sw_hw_apply = ar8327_sw_hw_apply,
	.sw_link_function = ar8327_sw_link_function,

	.num_mibs = ARRAY_SIZE(ar8236_mibs),
	.mib_decs = ar8236_mibs,
	.mib_func = AR8327_REG_MIB_FUNC
};

const struct ar8xxx_chip ar8337_chip = {
	.caps = AR8XXX_CAP_GIGE | AR8XXX_CAP_MIB_COUNTERS,
	.config_at_probe = true,
	.mii_lo_first = true,

	.name = "Atheros AR8337",
	.ports = AR8327_NUM_PORTS,
	.vlans = AR8X16_MAX_VLANS,
	.swops = &ar8327_sw_ops,

	.reg_port_stats_start = 0x1000,
	.reg_port_stats_length = 0x100,

	.hw_init = ar8327_hw_init,
	.cleanup = ar8327_cleanup,
	.init_globals = ar8327_init_globals,
	.init_port = ar8327_init_port,
	.setup_port = ar8327_setup_port,
	.read_port_status = ar8327_read_port_status,
	.read_port_eee_status = ar8327_read_port_eee_status,
	.atu_flush = ar8327_atu_flush,
	.atu_flush_port = ar8327_atu_flush_port,
	.vtu_flush = ar8327_vtu_flush,
	.vtu_load_vlan = ar8327_vtu_load_vlan,
	.phy_fixup = ar8327_phy_fixup,
	.set_mirror_regs = ar8327_set_mirror_regs,
	.get_arl_entry = ar8327_get_arl_entry,
	.sw_hw_apply = ar8327_sw_hw_apply,
	.sw_link_function = ar8327_sw_link_function,

	.num_mibs = ARRAY_SIZE(ar8236_mibs),
	.mib_decs = ar8236_mibs,
	.mib_func = AR8327_REG_MIB_FUNC
};

