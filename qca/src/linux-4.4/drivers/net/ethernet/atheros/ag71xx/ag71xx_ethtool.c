/*
 *  Atheros AR71xx built-in ethernet mac driver
 *
 *  Copyright (c) 2016 The Linux Foundation. All rights reserved.
 *  Copyright (C) 2008-2010 Gabor Juhos <juhosg@openwrt.org>
 *  Copyright (C) 2008 Imre Kaloz <kaloz@openwrt.org>
 *
 *  Based on Atheros' AG7100 driver
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include "ag71xx.h"

static int ag71xx_ethtool_get_settings(struct net_device *dev,
				       struct ethtool_cmd *cmd)
{
	struct ag71xx *ag = netdev_priv(dev);
	struct phy_device *phydev = ag->phy_dev;
	ag71xx_sgmii_speed_t speed;
	ag71xx_sgmii_duplex_t duplex;

	if (ag71xx_sgmii_flag_get()) {
		cmd->autoneg = AUTONEG_DISABLE;
		cmd->supported = (SUPPORTED_10baseT_Half   |
			   SUPPORTED_10baseT_Full   |
			   SUPPORTED_100baseT_Half  |
			   SUPPORTED_100baseT_Full  |
			   SUPPORTED_1000baseT_Full);
		ag71xx_sgmii_get_link(ag, &speed, &duplex);
		if (speed == AG71XX_SGMII_SPEED_1000T)
			cmd->speed = SPEED_1000;
		else if (speed == AG71XX_SGMII_SPEED_100T)
			cmd->speed = SPEED_100;
		else
			cmd->speed = SPEED_10;
		if (duplex == AG71XX_SGMII_FULL_DUPLEX)
			cmd->duplex = DUPLEX_FULL;
		else
			cmd->duplex = DUPLEX_HALF;
		return 0;
	}

	if (!phydev)
		return -ENODEV;

	return phy_ethtool_gset(phydev, cmd);
}

static int ag71xx_ethtool_set_settings(struct net_device *dev,
				       struct ethtool_cmd *cmd)
{
	struct ag71xx *ag = netdev_priv(dev);
	struct phy_device *phydev = ag->phy_dev;
	ag71xx_sgmii_speed_t speed;
	ag71xx_sgmii_duplex_t duplex;

	if (cmd->autoneg == AUTONEG_DISABLE && ag71xx_sgmii_flag_get()) {
		if (cmd->speed == SPEED_1000) {
			if (cmd->duplex == DUPLEX_FULL) {
				speed = AG71XX_SGMII_SPEED_1000T;
				duplex = AG71XX_SGMII_FULL_DUPLEX;
			} else {
				return -EINVAL;
			}
		} else if (cmd->speed == SPEED_100) {
			if (cmd->duplex == DUPLEX_FULL)
				duplex = AG71XX_SGMII_FULL_DUPLEX;
			else
				duplex = AG71XX_SGMII_HALF_DUPLEX;
			speed = AG71XX_SGMII_SPEED_100T;
		} else {
			if (cmd->duplex == DUPLEX_FULL)
				duplex = AG71XX_SGMII_FULL_DUPLEX;
			else
				duplex = AG71XX_SGMII_HALF_DUPLEX;
			speed = AG71XX_SGMII_SPEED_10T;
		}
		ag71xx_sgmii_set_link(ag, speed, duplex);
		return 0;
	}

	if (!phydev)
		return -ENODEV;

	return phy_ethtool_sset(phydev, cmd);
}

static void ag71xx_ethtool_get_drvinfo(struct net_device *dev,
				       struct ethtool_drvinfo *info)
{
	struct ag71xx *ag = netdev_priv(dev);

	strcpy(info->driver, ag->pdev->dev.driver->name);
	strcpy(info->version, AG71XX_DRV_VERSION);
	strcpy(info->bus_info, dev_name(&ag->pdev->dev));
}

static u32 ag71xx_ethtool_get_msglevel(struct net_device *dev)
{
	struct ag71xx *ag = netdev_priv(dev);

	return ag->msg_enable;
}

static void ag71xx_ethtool_set_msglevel(struct net_device *dev, u32 msg_level)
{
	struct ag71xx *ag = netdev_priv(dev);

	ag->msg_enable = msg_level;
}

static void ag71xx_ethtool_get_ringparam(struct net_device *dev,
					 struct ethtool_ringparam *er)
{
	struct ag71xx *ag = netdev_priv(dev);

	er->tx_max_pending = AG71XX_TX_RING_SIZE_MAX;
	er->rx_max_pending = AG71XX_RX_RING_SIZE_MAX;
	er->rx_mini_max_pending = 0;
	er->rx_jumbo_max_pending = 0;

	er->tx_pending = ag->tx_ring.size;
	er->rx_pending = ag->rx_ring.size;
	er->rx_mini_pending = 0;
	er->rx_jumbo_pending = 0;
}

/* Return the next largest power of 2. */
static int ag71xx_next_power_of_2(unsigned int i)
{
	i--;
	i = (i >> 1) | i;
	i = (i >> 2) | i;
	i = (i >> 4) | i;
	i = (i >> 8) | i;
	i = (i >> 16) | i;
	i++;

	return i;
}

static int ag71xx_ethtool_set_ringparam(struct net_device *dev,
					struct ethtool_ringparam *er)
{
	struct ag71xx *ag = netdev_priv(dev);
	unsigned tx_size;
	unsigned rx_size;
	int err;

	if (er->rx_mini_pending != 0 ||
	    er->rx_jumbo_pending != 0 ||
	    er->rx_pending == 0 ||
	    er->tx_pending == 0)
		return -EINVAL;

	tx_size = er->tx_pending < AG71XX_TX_RING_SIZE_MAX ?
		  er->tx_pending : AG71XX_TX_RING_SIZE_MAX;
	tx_size = ag71xx_next_power_of_2(tx_size);

	rx_size = er->rx_pending < AG71XX_RX_RING_SIZE_MAX ?
		  er->rx_pending : AG71XX_RX_RING_SIZE_MAX;
	rx_size = ag71xx_next_power_of_2(rx_size);

	if (netif_running(dev)) {
		err = dev->netdev_ops->ndo_stop(dev);
		if (err)
			return err;
	}

	ag->tx_ring.size = tx_size;
	ag->tx_ring.mask = tx_size - 1;
	ag->rx_ring.size = rx_size;
	ag->rx_ring.mask = rx_size - 1;

	if (netif_running(dev))
		err = dev->netdev_ops->ndo_open(dev);

	return err;
}

static int ag71xx_ethtool_get_regs_len(struct net_device *netdev)
{
#define AG71XX_REGS_LEN 23
	return AG71XX_REGS_LEN * sizeof(u32);
}

static void ag71xx_ethtool_get_regs(struct net_device *netdev,
			struct ethtool_regs *regs, void *p)
{
	struct ag71xx *ag = netdev_priv(netdev);
	u32 *regs_buff = p;

	memset(p, 0, AG71XX_REGS_LEN * sizeof(u32));

	regs_buff[0]  = ag71xx_rr(ag, AG71XX_REG_MAC_CFG1);
	regs_buff[1]  = ag71xx_rr(ag, AG71XX_REG_MAC_CFG2);
	regs_buff[2]  = ag71xx_rr(ag, AG71XX_REG_MAC_IPG);
	regs_buff[3]  = ag71xx_rr(ag, AG71XX_REG_MAC_HDX);
	regs_buff[4]  = ag71xx_rr(ag, AG71XX_REG_MAC_MFL);
	regs_buff[5]  = 0xFFFFFFFF;
	regs_buff[6]  = 0xFFFFFFFF;
	regs_buff[7]  = 0xFFFFFFFF;
	regs_buff[8]  = ag71xx_rr(ag, AG71XX_REG_MII_CFG);
	regs_buff[9]  = 0xFFFFFFFF;
	regs_buff[10] = 0xFFFFFFFF;
	regs_buff[11] = 0xFFFFFFFF;
	regs_buff[12] = 0xFFFFFFFF;
	regs_buff[13] = 0xFFFFFFFF;
	regs_buff[14] = ag71xx_rr(ag, AG71XX_REG_MAC_IFCTL);
	regs_buff[15] = ag71xx_rr(ag, AG71XX_REG_MAC_ADDR1);
	regs_buff[16] = ag71xx_rr(ag, AG71XX_REG_MAC_ADDR2);
	regs_buff[17] = ag71xx_rr(ag, AG71XX_REG_FIFO_CFG0);
	regs_buff[18] = ag71xx_rr(ag, AG71XX_REG_FIFO_CFG1);
	regs_buff[19] = ag71xx_rr(ag, AG71XX_REG_FIFO_CFG2);
	regs_buff[20] = ag71xx_rr(ag, AG71XX_REG_FIFO_CFG3);
	regs_buff[21] = ag71xx_rr(ag, AG71XX_REG_FIFO_CFG4);
	regs_buff[22] = ag71xx_rr(ag, AG71XX_REG_FIFO_CFG5);
}

struct ethtool_ops ag71xx_ethtool_ops = {
	.set_settings	= ag71xx_ethtool_set_settings,
	.get_settings	= ag71xx_ethtool_get_settings,
	.get_drvinfo	= ag71xx_ethtool_get_drvinfo,
	.get_regs_len	= ag71xx_ethtool_get_regs_len,
	.get_regs	= ag71xx_ethtool_get_regs,
	.get_msglevel	= ag71xx_ethtool_get_msglevel,
	.set_msglevel	= ag71xx_ethtool_set_msglevel,
	.get_ringparam	= ag71xx_ethtool_get_ringparam,
	.set_ringparam	= ag71xx_ethtool_set_ringparam,
	.get_link	= ethtool_op_get_link,
};
