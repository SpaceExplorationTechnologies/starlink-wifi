/*
 * qca_85xx_sw.c: QCA 85xx switch driver
 *
 * Copyright (c) 2015-2017 The Linux Foundation. All rights reserved.
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
 */

#include <linux/version.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/platform_device.h>
#include <linux/vmalloc.h>
#include <linux/qca_85xx_sw.h>
#include <linux/debugfs.h>
#include <linux/phy.h>
#include <uapi/linux/switch.h>
#include <linux/switch.h>
#include <linux/aq_phy.h>
#include <linux/of.h>
#include <linux/of_net.h>
#include <linux/of_irq.h>
#include <linux/of_platform.h>
#include <linux/of_address.h>
#include <linux/reset.h>
#include "qca_85xx_sw_regdef.h"

#define QCA_85XX_SW_MAX_REG_SIZE 16

struct of_device_id dt_qca_85xx_sw[] = {
	{ .compatible =  "qcom,qca-85xx-sw" },
	{},
};
MODULE_DEVICE_TABLE(of, dt_qca_85xx_sw);

/* MIB Descriptor */
struct qca_85xx_sw_mib_desc {
	unsigned int size;
	unsigned int offset;
	const char *name;
};

 /* 85xx chipset specific data */
struct qca_85xx_sw_chip {
	int (*hw_init)(struct qca_85xx_sw_platform_data *pdata);
	uint32_t max_qsgmii_if;
	uint32_t max_sgmii_plus_if;
	uint32_t max_ge_if;
};

/* 85xx private data */
struct qca_85xx_sw_priv {
	struct switch_dev dev;
	uint32_t (*read)(uint32_t reg_addr);
	void (*write)(uint32_t reg_addr, uint32_t val);
	struct mii_bus *mdio_bus;
	struct net_device *eth_dev;
	const struct qca_85xx_sw_chip *chip;

	uint32_t reg_val;		/* Hold the result of the previous
					   debug-fs based register read op */

	uint32_t reg_addr;		/* Hold the register address for the
					   previous debug-fs based register
					   read op */
	uint32_t sgmii_plus_link_speed;	/* SGMII+ if link speed */
	uint32_t sgmii_plus_duplex;	/* SFMII+ if link duplex */
	uint32_t sgmii_plus_port_num;	/* SGMII+ if port number */
	struct dentry *top_dentry;	/* Top dentry */
	struct dentry *write_dentry;	/* write-reg file dentry */
	struct dentry *read_dentry;	/* read-reg file dentry */

	/* VLAN enable */
	bool vlan_enable;

	/* VLAN tag ID configured for VLANs */
	uint16_t vlan_tag_id[QCA_85XX_MAX_VLANS];

	/* Member ports for port VLANs */
	uint32_t vlan_port_map[QCA_85XX_MAX_VLANS];

	/* Bitmap of tagged ports */
	uint32_t vlan_tagged_ports_bm;

	/* Port VLAN ID for each port */
	uint16_t port_vlan_id[QCA_85XX_MAX_PORTS];

	/* MIB Descritor table */
	const struct qca_85xx_sw_mib_desc *mib;

	/* Number of MIB counters */
	unsigned num_mib_counters;

	/* Buffer used for MIB get op */
	char port_mib[2048];

};

struct qca_85xx_sw_priv *priv;

/* MIB Descriptor table */
static const struct qca_85xx_sw_mib_desc qca_85xx_mib[] = {
	MIB_DESC(1, MIB_STATS_RX_BROAD, "RxBroad"),
	MIB_DESC(1, MIB_STATS_RX_PAUSE, "RxPause"),
	MIB_DESC(1, MIB_STATS_RX_MULTI, "RxMulti"),
	MIB_DESC(1, MIB_STATS_RX_FCS_ERR, "RxFcsErr"),
	MIB_DESC(1, MIB_STATS_RX_ALIGN_ERR, "RxAlignErr"),
	MIB_DESC(1, MIB_STATS_RX_JUMBO_FCS_ERR, "RxJumboFcsErr"),
	MIB_DESC(1, MIB_STATS_RX_JUMBO_ALIGN_ERR, "RxJumboAlignErr"),
	MIB_DESC(1, MIB_STATS_RX_PKT_64B, "Rx64Byte"),
	MIB_DESC(1, MIB_STATS_RX_PKT_65_127B, "Rx_65_to_127_Byte"),
	MIB_DESC(1, MIB_STATS_RX_PKT_128_255B, "Rx_128_to_255_Byte"),
	MIB_DESC(1, MIB_STATS_RX_PKT_256_511B, "Rx_256_to_511_Byte"),
	MIB_DESC(1, MIB_STATS_RX_PKT_512_1023B, "Rx_512_to_1023_Byte"),
	MIB_DESC(1, MIB_STATS_RX_PKT_1024_1518B, "Rx_1024_to_1518_Byte"),
	MIB_DESC(1, MIB_STATS_RX_PKT_1519_XB, "Rx_1519_or more_Byte"),
	MIB_DESC(1, MIB_STATS_RX_TOO_LONG, "RxTooLong"),
	MIB_DESC(2, MIB_STATS_RX_GOOD_BYTE, "RxGoodByte"),
	MIB_DESC(2, MIB_STATS_RX_BAD_BYTE, "RxBadByte"),
	MIB_DESC(1, MIB_STATS_RX_OVER_FLOW, "RxOverFlow"),
	MIB_DESC(1, MIB_STATS_RX_RUNT_NUM, "RxRuntNum"),
	MIB_DESC(1, MIB_STATS_RX_RUNT_BYTE, "RxRuntByte"),
	MIB_DESC(1, MIB_STATS_RX_FRAG_NUM, "RxFragNum"),
	MIB_DESC(1, MIB_STATS_RX_FRAG_BYTE, "RxFragByte"),
	MIB_DESC(1, MIB_STATS_TX_BROAD, "TxBroad"),
	MIB_DESC(1, MIB_STATS_TX_PAUSE, "TxPause"),
	MIB_DESC(1, MIB_STATS_TX_MULTI, "TxMulti"),
	MIB_DESC(1, MIB_STATS_TX_UNDER_RUN, "TxUnderRun"),
	MIB_DESC(1, MIB_STATS_TX_PKT_64B, "Tx64Byte"),
	MIB_DESC(1, MIB_STATS_TX_PKT_65_127B, "Tx_65_to_127_Byte"),
	MIB_DESC(1, MIB_STATS_TX_PKT_128_255B, "Tx_128_to_255_Byte"),
	MIB_DESC(1, MIB_STATS_TX_PKT_256_511B, "Tx_256_to_511_Byte"),
	MIB_DESC(1, MIB_STATS_TX_PKT_512_1023B, "Tx_512_to_1023_Byte"),
	MIB_DESC(1, MIB_STATS_TX_PKT_1024_1518B, "Tx_1024_to_1518_Byte"),
	MIB_DESC(1, MIB_STATS_TX_PKT_1519_XB, "Tx_1519_or more_Byte"),
	MIB_DESC(2, MIB_STATS_TX_BYTE, "TxByte"),
	MIB_DESC(1, MIB_STATS_TX_COLLISION, "TxCollision"),
	MIB_DESC(1, MIB_STATS_TX_ABORTCOL, "TxAbortCol"),
	MIB_DESC(1, MIB_STATS_TX_MULTICOL, "TxMultiCol"),
	MIB_DESC(1, MIB_STATS_TX_SINGLECOL, "TxSingleCol"),
	MIB_DESC(1, MIB_STATS_TX_EXCESSIVE_DEFER, "TxExcDefer"),
	MIB_DESC(1, MIB_STATS_TX_DEFER, "TxDefer"),
	MIB_DESC(1, MIB_STATS_TX_LATE_COL, "TxLateCol"),
};

/*
 * Identify the new link speed and duplex setting for the SGMII+ if link, and
 * and force the SGMII+ speed/duplex accordingly
 */
static void qca_85xx_sw_sgmii_plus_if_change_speed(struct net_device *dev)
{
	uint32_t val, sgmii_ctrl0_val;
	int curr_speed = dev->phydev->speed;
	int curr_duplex = dev->phydev->duplex;

	if (curr_speed == priv->sgmii_plus_link_speed &&
	    curr_duplex == priv->sgmii_plus_duplex)
		return;

	switch (curr_speed) {
	case SPEED_2500:
		/* Set port 27 into SGMII+ Mode(2.5 Gig speed) */
		val = priv->read(GLOBAL_CTRL_1);
		val |= GLOBAL_CTRL_1_PORT_27_SGMII_PLUS_EN;
		val &= ~(GLOBAL_CTRL_1_PORT_27_SGMII_EN);
		priv->write(GLOBAL_CTRL_1, val);
		break;
	case SPEED_1000:
	case SPEED_100:
		if (priv->sgmii_plus_link_speed != SPEED_1000 &&
			priv->sgmii_plus_link_speed != SPEED_100) {
			/* Set port 27 into SGMII Mode(100/1000Mbps speed) */
			val = priv->read(GLOBAL_CTRL_1);
			val |= GLOBAL_CTRL_1_PORT_27_SGMII_EN;
			val &= ~(GLOBAL_CTRL_1_PORT_27_SGMII_PLUS_EN);
			priv->write(GLOBAL_CTRL_1, val);
		}
		break;
	default:
		priv->sgmii_plus_link_speed = SPEED_UNKNOWN;
		return;
	}

	/*
	 * Configure MAC<->PHY auto-negotiation/speed settings.
	 * Speed 2500 => Auto-negotiation is off, force speed is on
	 * Speed 100/1000 => Auto-negotiation is on, force speed is off
	 */
	sgmii_ctrl0_val = priv->read(SGMII_CTRL0_PORT27);
	val = priv->read(port_status_cfg(priv->sgmii_plus_port_num));

	/* Clear the previous speed, duplex, settings */
	sgmii_ctrl0_val &= ~(SGMII_CTRL0_SGMII_MODE_MAC |
			     SGMII_CTRL0_FORCE_SPEED_100 |
			     SGMII_CTRL0_FORCE_SPEED_1000 |
			     SGMII_CTRL0_FORCE_DUPLEX_FULL |
			     SGMII_CTRL0_MR_AN_EN |
			     SGMII_CTRL0_FORCE_MODE_EN);

	val &= ~(PORT_STATUS_FORCE_SPEED_100 |
		 PORT_STATUS_FORCE_SPEED_1000 |
		 PORT_STATUS_FORCE_DUPLEX_FULL);

	if (curr_speed != SPEED_100) {
		/* Enable 1000Mbps speed and duplex setting */
		val |= PORT_STATUS_FORCE_SPEED_1000 |
		       PORT_STATUS_FORCE_DUPLEX_FULL;
		sgmii_ctrl0_val |= SGMII_CTRL0_FORCE_SPEED_1000 |
				   SGMII_CTRL0_FORCE_DUPLEX_FULL;
	}

	if (curr_speed == SPEED_2500) {
		/* Disable auto-neg, enable force mode */
		sgmii_ctrl0_val |= SGMII_CTRL0_FORCE_MODE_EN;
	} else if (curr_speed == SPEED_1000) {
		/* Enable auto-neg, disable force mode */
		sgmii_ctrl0_val |= SGMII_CTRL0_MR_AN_EN;
	} else {
		/* Force the 100Mbps link speed and duplex setting */
		sgmii_ctrl0_val |= SGMII_CTRL0_SGMII_MODE_MAC |
				   SGMII_CTRL0_FORCE_SPEED_100 |
				   SGMII_CTRL0_MR_AN_EN;

		val |= PORT_STATUS_FORCE_SPEED_100;

		if (curr_duplex) {
			/* Set 100Mbps Full Duplex */
			sgmii_ctrl0_val |= SGMII_CTRL0_FORCE_DUPLEX_FULL;
			val |=  PORT_STATUS_FORCE_DUPLEX_FULL;
		}
	}

	priv->write(port_status_cfg(priv->sgmii_plus_port_num), val);
	priv->write(SGMII_CTRL0_PORT27, sgmii_ctrl0_val);
	priv->sgmii_plus_link_speed = curr_speed;
	priv->sgmii_plus_duplex = curr_duplex;
}

 /* Configure a QSGMII interface */
static int qca_85xx_sw_init_qsgmii_port(struct qca_85xx_sw_qsgmii_cfg *qcfg)
{
	uint32_t val, ch0_val, sd_clk_sel_val;
	uint32_t ch0_ctrl_addr, ch1_ctrl_addr, ch2_ctrl_addr, ch3_ctrl_addr;
	bool part_b = false;
	int group_num;

	if (qcfg->port_base > (priv->chip->max_qsgmii_if * 4))
		return -EINVAL;

	switch (qcfg->port_base) {
	case QCA_85XX_SW_PORT_1:
		group_num = 0;
		break;
	case QCA_85XX_SW_PORT_9:
		group_num = 1;
		break;
	case QCA_85XX_SW_PORT_17:
		group_num = 2;
		break;
	case QCA_85XX_SW_PORT_5:
		group_num = 0;
		part_b = true;
		break;
	case QCA_85XX_SW_PORT_13:
		group_num = 1;
		part_b = true;
		break;
	case QCA_85XX_SW_PORT_21:
		group_num = 2;
		part_b = true;
		break;
	default:
		return -EINVAL;
	}

	if (part_b) {
		ch0_ctrl_addr = QSGMII_5_CTRL0(group_num);
		ch1_ctrl_addr = QSGMII_6_CTRL0(group_num);
		ch2_ctrl_addr = QSGMII_7_CTRL0(group_num);
		ch3_ctrl_addr = QSGMII_8_CTRL0(group_num);
	} else {
		ch0_ctrl_addr = QSGMII_1_CTRL0(group_num);
		ch1_ctrl_addr = QSGMII_2_CTRL0(group_num);
		ch2_ctrl_addr = QSGMII_3_CTRL0(group_num);
		ch3_ctrl_addr = QSGMII_4_CTRL0(group_num);
	}

	val = priv->read(ch0_ctrl_addr);
	if (qcfg->is_speed_forced == false)
		val &= ~(QSGMII_CTRL_FORCE_SPEED | QSGMII_CTRL_FORCE_LINK_UP);
	else {
		val |= QSGMII_CTRL_FORCE_SPEED | QSGMII_CTRL_FORCE_LINK_UP;
		if (qcfg->forced_speed == SPEED_1000)
			val |= QSGMII_CTRL_FORCE_SPEED_1000
				| QSGMII_CTRL_FORCE_DUPLEX_FULL;
		else if (qcfg->forced_speed == SPEED_100)
			val |= QSGMII_CTRL_FORCE_SPEED_100;
		else if (qcfg->forced_speed == SPEED_10)
			val |= QSGMII_CTRL_FORCE_SPEED_10;
		else
			return -EINVAL;

		if (qcfg->forced_speed != SPEED_1000) {
			if (qcfg->forced_duplex == DUPLEX_FULL)
				val |= QSGMII_CTRL_FORCE_DUPLEX_FULL;
			else
				val &= ~QSGMII_CTRL_FORCE_DUPLEX_FULL;
		}
	}

	/* Force the speed if necessary, set the SGMII mode, link up bit */
	val = val & (~(QSGMII_CTRL_QSGMII_MODE_MAC
		| QSGMII_CTRL_QSGMII_MODE_PHY));
	ch0_val = val | QSGMII_CTRL_QSGMII_MODE_MAC;

	priv->write(ch0_ctrl_addr, ch0_val);
	priv->write(ch1_ctrl_addr, val);
	priv->write(ch2_ctrl_addr, val);
	priv->write(ch3_ctrl_addr, val);

	/* Turn off auto-neg in port_status_cfg */
	val = priv->read(port_status_cfg(qcfg->port_base + 1));

	if (qcfg->is_speed_forced == false) {
		/* Enable  Auto-negotiation */
		val |= PORT_STATUS_AUTONEG_EN;
	} else {
		/* Disable Auto-negotiation */
		val &= ~(PORT_STATUS_AUTONEG_EN
				| PORT_STATUS_AUTO_FLOW_CTRL_EN
				| PORT_STATUS_TX_HALF_FLOW_EN
				| PORT_STATUS_RX_FLOW_EN
				| PORT_STATUS_TX_FLOW_EN);
		val |= (PORT_STATUS_RXMAC_EN | PORT_STATUS_TXMAC_EN);

		/* Force the speed and duplex as configured */
		if (qcfg->forced_speed == SPEED_1000)
			val |= PORT_STATUS_FORCE_SPEED_1000 |
			       PORT_STATUS_FORCE_DUPLEX_FULL;
		else if (qcfg->forced_speed == SPEED_100)
			val |= PORT_STATUS_FORCE_SPEED_100;
		else if (qcfg->forced_speed == SPEED_10)
			val |= PORT_STATUS_FORCE_SPEED_10;
		else
			return -EINVAL;

		if (qcfg->forced_speed != SPEED_1000) {
			if (qcfg->forced_duplex == DUPLEX_FULL)
				val |= PORT_STATUS_FORCE_DUPLEX_FULL;
			else
				val &= ~PORT_STATUS_FORCE_DUPLEX_FULL;
		}
	}

	priv->write(port_status_cfg(qcfg->port_base + 1), val);
	priv->write(port_status_cfg(qcfg->port_base + 2), val);
	priv->write(port_status_cfg(qcfg->port_base + 3), val);
	priv->write(port_status_cfg(qcfg->port_base + 4), val);

	/* Set QSGMII mode in GLOBAL_CTRL_1 */
	val = priv->read(GLOBAL_CTRL_1);
	val &= ~(GLOBAL_CTRL_1_MAC1_SGMII_EN << (qcfg->port_base/4));
	priv->write(GLOBAL_CTRL_1, val);

	 /* Enable SD clock selects for the QSGMII port */
	sd_clk_sel_val = priv->read(SD_CLK_SEL);
	sd_clk_sel_val |= (SD_CLK_SEL_QSGMII_1_RX << (qcfg->port_base/4));
	priv->write(SD_CLK_SEL, sd_clk_sel_val);

	return 0;
}

/* Configure a SGMII/SGMII+ interface */
static int qca_85xx_sw_init_sgmii_port(enum qca_85xx_sw_gmac_port port,
					struct qca_85xx_sw_sgmii_cfg *sgmii_cfg)
{
	uint32_t val, sgmii_ctrl0_reg, sgmii_ctrl0_val, sd_clk_sel_val;

	/* Set the port to either SGMII or SGMII+ mode in GLOBAL_CTRL_1 */
	val = priv->read(GLOBAL_CTRL_1);

	sd_clk_sel_val = priv->read(SD_CLK_SEL);
	switch (port) {
	case QCA_85XX_SW_PORT_26:
		sgmii_ctrl0_reg = SGMII_CTRL0_PORT26;
		sd_clk_sel_val |= SD_CLK_SEL_SGMII_PORT26_RX;
		if (sgmii_cfg->port_mode == QCA_85XX_SW_PORT_MODE_SGMII_PLUS) {
			val |= GLOBAL_CTRL_1_PORT_26_SGMII_PLUS_EN;
			val &= ~(GLOBAL_CTRL_1_PORT_26_SGMII_EN);
		} else {
			val |= GLOBAL_CTRL_1_PORT_26_SGMII_EN;
			val &= ~(GLOBAL_CTRL_1_PORT_26_SGMII_PLUS_EN);
		}
		break;
	case QCA_85XX_SW_PORT_27:
		sd_clk_sel_val |= SD_CLK_SEL_SGMII_PORT27_RX;
		sgmii_ctrl0_reg = SGMII_CTRL0_PORT27;
		if (sgmii_cfg->port_mode == QCA_85XX_SW_PORT_MODE_SGMII_PLUS) {
			val |= GLOBAL_CTRL_1_PORT_27_SGMII_PLUS_EN;
			val &= ~(GLOBAL_CTRL_1_PORT_27_SGMII_EN);
		} else {
			val |= GLOBAL_CTRL_1_PORT_27_SGMII_EN;
			val &= ~(GLOBAL_CTRL_1_PORT_27_SGMII_PLUS_EN);
		}
		break;
	case QCA_85XX_SW_PORT_28:
		sd_clk_sel_val |= SD_CLK_SEL_SGMII_PORT28_RX;
		sgmii_ctrl0_reg = SGMII_CTRL0_PORT28;
		if (sgmii_cfg->port_mode == QCA_85XX_SW_PORT_MODE_SGMII_PLUS) {
			val |= GLOBAL_CTRL_1_PORT_28_SGMII_PLUS_EN;
			val &= ~(GLOBAL_CTRL_1_PORT_28_SGMII_EN);
		} else {
			val |= GLOBAL_CTRL_1_PORT_28_SGMII_EN;
			val &= ~(GLOBAL_CTRL_1_PORT_28_SGMII_PLUS_EN);
		}
		break;
	case QCA_85XX_SW_PORT_29:
		sd_clk_sel_val |= SD_CLK_SEL_SGMII_PORT29_RX;
		sgmii_ctrl0_reg = SGMII_CTRL0_PORT29;
		if (sgmii_cfg->port_mode == QCA_85XX_SW_PORT_MODE_SGMII_PLUS) {
			val |= GLOBAL_CTRL_1_PORT_29_SGMII_PLUS_EN;
			val &= ~(GLOBAL_CTRL_1_PORT_29_SGMII_EN);
		} else {
			val |= GLOBAL_CTRL_1_PORT_29_SGMII_EN;
			val &= ~(GLOBAL_CTRL_1_PORT_29_SGMII_PLUS_EN);
		}
		break;
	default:
		return -EINVAL;
	}

	priv->write(GLOBAL_CTRL_1, val);

	/* Enable SGMII Rx clock select */
	priv->write(SD_CLK_SEL, sd_clk_sel_val);

	/* Set the MAC-mode settings in SGMII_CTRL0 register */
	sgmii_ctrl0_val = priv->read(sgmii_ctrl0_reg);

	/* Place the SGMII mode into MAC mode */
	/* for SGMII ports and 1000Base-X for SGMII+ */
	if (sgmii_cfg->port_mode != QCA_85XX_SW_PORT_MODE_SGMII_PLUS)
		sgmii_ctrl0_val |= SGMII_CTRL0_SGMII_MODE_MAC;
	else
		sgmii_ctrl0_val &= ~(SGMII_CTRL0_SGMII_MODE_PHY
				| SGMII_CTRL0_SGMII_MODE_MAC);

	val = priv->read(port_status_cfg(port));

	/* Settings to force speed if configured */
	if (sgmii_cfg->is_speed_forced == false) {
		val |= PORT_STATUS_AUTONEG_EN;
		sgmii_ctrl0_val |= SGMII_CTRL0_MR_AN_EN;
		sgmii_ctrl0_val &= ~SGMII_CTRL0_FORCE_MODE_EN;
	} else {
		/* Disable Auto-negotiation */
		val &= ~(PORT_STATUS_AUTONEG_EN
				| PORT_STATUS_AUTO_FLOW_CTRL_EN
				| PORT_STATUS_TX_HALF_FLOW_EN
				| PORT_STATUS_RX_FLOW_EN
				| PORT_STATUS_TX_FLOW_EN);
		val |= (PORT_STATUS_RXMAC_EN | PORT_STATUS_TXMAC_EN);

		sgmii_ctrl0_val &= ~SGMII_CTRL0_MR_AN_EN;
		sgmii_ctrl0_val |= SGMII_CTRL0_FORCE_MODE_EN;

		/* Force the speed and duplex as configured */
		switch (sgmii_cfg->forced_speed) {
		case SPEED_1000:
		case SPEED_2500:
			val |= PORT_STATUS_FORCE_SPEED_1000
				| PORT_STATUS_FORCE_DUPLEX_FULL;
			sgmii_ctrl0_val |= SGMII_CTRL0_FORCE_SPEED_1000
					| SGMII_CTRL0_FORCE_DUPLEX_FULL;
			break;
		case SPEED_100:
			val |= PORT_STATUS_FORCE_SPEED_100;
			sgmii_ctrl0_val |= SGMII_CTRL0_FORCE_SPEED_100;
			break;
		case SPEED_10:
			val |= PORT_STATUS_FORCE_SPEED_10;
			sgmii_ctrl0_val |= SGMII_CTRL0_FORCE_SPEED_10;
			break;
		default:
			return -EINVAL;
		}

		if ((sgmii_cfg->forced_speed != SPEED_1000)
			&& (sgmii_cfg->forced_speed != SPEED_2500)) {
			if (sgmii_cfg->forced_duplex == DUPLEX_FULL)
				val |= PORT_STATUS_FORCE_DUPLEX_FULL;
			else {
				val &= ~PORT_STATUS_FORCE_DUPLEX_FULL;
				sgmii_ctrl0_val &= ~SGMII_CTRL0_FORCE_DUPLEX_FULL;
			}
		}
	}

	priv->write(port_status_cfg(port), val);
	priv->write(sgmii_ctrl0_reg, sgmii_ctrl0_val);

	/* Serdes control settings */
	if (sgmii_cfg->port_mode == QCA_85XX_SW_PORT_MODE_SGMII_PLUS) {
		priv->write(XAUI_SGMII_SERDES13_CTRL0, 0x01e2023e);
		priv->write(XAUI_SGMII_SERDES13_CTRL1, 0x4c93ff0);
		priv->sgmii_plus_port_num = port;
	}

	return 0;
}

/* Configure a trunk (Link-Aggregated) interface */
static int qca_85xx_sw_trunk_enable(struct qca_85xx_sw_trunk_cfg *trunk_cfg)
{
	uint32_t val = 0, i = 0, shift_val = 0;
	uint32_t trunk_table_entry_no = 0;
	uint32_t trunk_table_entry_addr, table_entry_val = 0;
	uint32_t port_bit_map = 0;
	uint32_t next_port_num = 0;

	if (trunk_cfg->trunk_id > (QCA_85XX_MAX_TRUNKS - 1))
		return -EINVAL;

	/* Enable trunk failover */
	val = priv->read(L2_MISC_CTRL);
	priv->write(L2_MISC_CTRL, val | FAILOVER_EN);

	/* Set the trunk hash key selection method */
	priv->write(TRUNK_HASH_KEY_SEL, trunk_cfg->trunk_hash_policy);

	/* Enable the trunk slave ports */
	for (i = QCA_85XX_SW_PORT_1; i <= QCA_85XX_SW_PORT_29; i++) {

		if ((i > priv->chip->max_ge_if) && (i < QCA_85XX_SW_PORT_26))
			continue;

		if (trunk_cfg->trunk_ports_bit_map & (1 << i))
			priv->write(port_trunk_cfg(i),
				    (PORT_TRUNK_EN | trunk_cfg->trunk_id));
	}

	/* Set the trunk member ports in the TRUNK_GROUP_MEM table */
	port_bit_map = trunk_cfg->trunk_ports_bit_map;

	/* The TRUNK_GROUP_MEM table has 8 member slots all of which need to be
	 * filled. So, cycle through the trunk port members list until we have
	 * filled all the 8 port entries of the table entry.
	 */
	while (trunk_table_entry_no < QCA_85XX_MAX_TRUNKS) {
		/* Get the next port number */
		next_port_num = ffs(port_bit_map) - 1;
		port_bit_map &= ~(1 << next_port_num);
		shift_val = (trunk_table_entry_no
			* TRUNK_MEM_PORT_ID_SHIFT_LEN) % 32;

		/* Configure the table entries */
		switch (trunk_table_entry_no) {
		case 0:
		case 1:
		case 2:
			trunk_table_entry_addr = trunk_group_mem_0(trunk_cfg->trunk_id);
			table_entry_val = priv->read(trunk_table_entry_addr);
			priv->write(trunk_table_entry_addr,
			table_entry_val
			| (next_port_num << shift_val));
			break;
		case 3:
		case 4:
			trunk_table_entry_addr = trunk_group_mem_1(trunk_cfg->trunk_id);
			table_entry_val = priv->read(trunk_table_entry_addr);
			priv->write(trunk_table_entry_addr,
			table_entry_val
			| (next_port_num << shift_val));
			break;
		case 5:
			trunk_table_entry_addr = trunk_group_mem_1(trunk_cfg->trunk_id);
			table_entry_val = priv->read(trunk_table_entry_addr);
			priv->write(trunk_table_entry_addr,
			table_entry_val
			| ((next_port_num & 0xF) << shift_val));

			if (next_port_num > 0xF) {
				trunk_table_entry_addr = trunk_group_mem_2(trunk_cfg->trunk_id);
				table_entry_val = priv->read(trunk_table_entry_addr);
				priv->write(trunk_table_entry_addr,
				table_entry_val
				| ((next_port_num & 0x30) >> 4));
			}

			break;
		case 6:
		case 7:
			trunk_table_entry_addr = trunk_group_mem_2(trunk_cfg->trunk_id);
			table_entry_val = priv->read(trunk_table_entry_addr);
			priv->write(trunk_table_entry_addr,
			table_entry_val
			| (next_port_num << shift_val));
			break;
		}

		trunk_table_entry_no++;

		if (port_bit_map == 0)
			port_bit_map = trunk_cfg->trunk_ports_bit_map;
	}

	/* Enable the trunk slave ports bit map */
	priv->write(trunk_local_port_mem(trunk_cfg->trunk_id),
		trunk_cfg->trunk_ports_bit_map);

	return 0;
}

/* Enable VLAN filters and STP forwarding */
void qca_85xx_sw_enable_port_defaults(void)
{
	uint32_t stp_grp_reg_val_0 = 0, stp_grp_reg_val_1 = 0;
	uint32_t port_vlan_fltr = 0;
	int i;

	/* Enable STP forwarding, and enable VLAN filters */
	for (i = QCA_85XX_SW_PORT_1; i <= QCA_85XX_SW_PORT_29; i++) {
		if (i < 16)
			stp_grp_reg_val_0 |= (PORT_FORWARDING << (i*2));
		else
			stp_grp_reg_val_1 |= (PORT_FORWARDING << ((i-16) * 2));

		port_vlan_fltr &=  ~(1 << i);
	}

	priv->write(spanning_tree_group_reg_0(0), stp_grp_reg_val_0);
	priv->write(spanning_tree_group_reg_1(0), stp_grp_reg_val_1);
	priv->write(PORT_VLAN_FLTR, port_vlan_fltr);
}

/* Configure a Port VLAN group */
int qca_85xx_port_vlan_group_enable(uint16_t vlan_id, uint32_t port_bit_map)
{
	int next_port_num = 0, pbm;
	uint16_t in_vlan_entry_num;
	uint32_t in_vlan_w0_addr, in_vlan_w1_addr, in_vlan_w2_addr;
	uint32_t in_vlan_w0_val = 0, in_vlan_w1_val = 0, in_vlan_w2_val = 0;
	uint32_t vlan_op_val = 0, vlan_op_data_0_val = 0, vlan_op_data_1_val = 0;
	uint32_t port_eg_vlan_ctrl_addr, port_eg_vlan_ctrl_val = 0;
	uint32_t eg_vlan_tag_addr, eg_vlan_tag_val = 0;

	pr_debug("qca_85xx_sw: VLAN enable for vlan_id = %d, port-map = 0x%x, vlan-tagged-ports map = 0x%x\n",
			vlan_id, port_bit_map, priv->vlan_tagged_ports_bm);

	if (vlan_id > QCA_85XX_VLAN_ID_MAX)
		return -EINVAL;

	/* Program IN_VLAN_TRANSLATION table */
	in_vlan_entry_num = IN_VLAN_ENTRY_LOWEST_PRIO;

	/* If the VLAN is not a tagged VLAN group, then we assign
	 * a default ingress port VLAN translation for all the ports
	 * in the VLAN
	 */
	if ((port_bit_map & priv->vlan_tagged_ports_bm) == port_bit_map) {
		pr_debug("qca_85xx_sw: No ingress VLAN translation for vlan-id %d, port-map = 0x%x\n",
				vlan_id, port_bit_map);
		goto post_ingress;
	}

	pbm = port_bit_map;

	/* Cycle through the port members list and update the IN_VLAN_TRANSLATION
	 * table entry for each port
	 */
	while (pbm) {
		next_port_num = ffs(pbm) - 1;
		pbm &= ~(1 << next_port_num);

		in_vlan_w0_addr = in_vlan_table_word_0(next_port_num, in_vlan_entry_num);
		in_vlan_w1_addr = in_vlan_table_word_1(next_port_num, in_vlan_entry_num);
		in_vlan_w2_addr = in_vlan_table_word_2(next_port_num, in_vlan_entry_num);

		/* Write table entry word 0 */
		in_vlan_w0_val |= (CVID_SEARCH_KEY_VALUE_UNTAGGED << CKEY_VID_SHIFT_LEN);
		priv->write(in_vlan_w0_addr, in_vlan_w0_val);

		/* Write table entry word 1 */
		in_vlan_w1_val |= (vlan_id << XLT_CVID_SHIFT_LEN);
		in_vlan_w1_val |= (XLT_CVID_EN | CKEY_VID_INCL);
		priv->write(in_vlan_w1_addr, in_vlan_w1_val);

		/* Write table entry word 2 */
		in_vlan_w2_val |= (IN_VLAN_TABLE_ENTRY_VALID | SA_LRN_EN |
				  (CVLAN_ASSIGN_ALL_FRAMES << CKEY_FMT_SHIFT_LEN));
		priv->write(in_vlan_w2_addr, in_vlan_w2_val);
	}

post_ingress:
	/* Program VLAN table entry */
	vlan_op_data_0_val = port_bit_map;
	priv->write(VLAN_OP_DATA_0, vlan_op_data_0_val);

	vlan_op_data_1_val |= (LRN_EN | VLAN_TABLE_ENTRY_VALID);
	priv->write(VLAN_OP_DATA_1, vlan_op_data_1_val);

	vlan_op_val |= (vlan_id | (VLAN_OP_TYPE_ADD_ONE << VLAN_OP_SHIFT_VAL));
	priv->write(VLAN_OPERATION, vlan_op_val);
	vlan_op_val |= VLAN_OP_START;
	priv->write(VLAN_OPERATION, vlan_op_val);

	usleep_range(1000, 10000);

	if (priv->read(VLAN_OPERATION) & VLAN_BUSY) {
		pr_debug(KERN_ERR "qca_85xx_sw: VLAN entry add operation timed out\n");
		return -ETIMEDOUT;
	}

	/* Program Egress VLAN table */
	eg_vlan_tag_addr = eg_vlan_tag(vlan_id);
	eg_vlan_tag_val |= EG_VLAN_TAG_TABLE_ENTRY_VALID;

	pbm = port_bit_map;
	while (pbm) {
		next_port_num = ffs(pbm) - 1;
		if (priv->vlan_tagged_ports_bm & (1 << next_port_num))
			eg_vlan_tag_val |= (1 << next_port_num);
		pbm &= ~(1 << next_port_num);
	}

	priv->write(eg_vlan_tag_addr, eg_vlan_tag_val);

	port_eg_vlan_ctrl_val |= (PORT_TAG_CONTROL_VID_LOOKUP_VID
				  | PORT_EG_VLAN_CTRL_RESERVED
				  | (PORT_EG_VLAN_TYPE_MODE_UNMODIFIED
					  << PORT_EG_VLAN_TYPE_MODE_SHIFT_LEN));
	pbm = port_bit_map;
	while (pbm) {
		next_port_num = ffs(pbm) - 1;
		pbm &= ~(1 << next_port_num);
		port_eg_vlan_ctrl_addr = port_eg_vlan_ctrl(next_port_num);
		priv->write(port_eg_vlan_ctrl_addr, port_eg_vlan_ctrl_val);
	}

	return 0;
}

/* Initialize VLAN information tables */
static void qca_85xx_sw_init_vlan_tables(void)
{
	int i;

	priv->vlan_tagged_ports_bm = 0;

	for (i = 0; i < QCA_85XX_MAX_PORTS; i++)
		priv->port_vlan_id[i] = 0;

	for (i = 0; i < QCA_85XX_MAX_VLANS; i++) {
		priv->vlan_port_map[i] = 0;
		priv->vlan_tag_id[i] = 0;
	}
}

/* Initialize the 8511 chipset */
static int qca8511_hw_init(struct qca_85xx_sw_platform_data *pdata)
{
	uint32_t val = 0;
	int ret = 0;

	/* Issue software reset and restore registers to default values */
	val = priv->read(GLOBAL_CTRL_0);
	val |= (GLOBAL_CTRL_0_REG_RST_EN | GLOBAL_CTRL_0_SOFT_RST);
	priv->write(GLOBAL_CTRL_0, val);

	usleep_range(1000, 10000);

	/* Is the reset complete? */
	if (priv->read(GLOBAL_CTRL_0) & GLOBAL_CTRL_0_SOFT_RST) {
		printk(KERN_ERR "qca_85xx_sw: software reset timed out\n");
		return -ETIMEDOUT;
	}

	/* Configuring QSGMII interface */
	if (pdata->qsgmii_cfg.port_mode == QCA_85XX_SW_PORT_MODE_QSGMII) {
		ret = qca_85xx_sw_init_qsgmii_port(&pdata->qsgmii_cfg);
		if (ret != 0)
			return ret;
	}

	/* Configure SGMII/SGMII+ interfaces */
	if (pdata->port_24_cfg.port_mode != QCA_85XX_SW_PORT_MODE_NOT_CONFIGURED) {
		ret = qca_85xx_sw_init_sgmii_port(QCA_85XX_SW_PORT_24,
			&pdata->port_24_cfg);
		if (ret != 0)
			return ret;
	}

	if (pdata->port_25_cfg.port_mode != QCA_85XX_SW_PORT_MODE_NOT_CONFIGURED) {
		ret = qca_85xx_sw_init_sgmii_port(QCA_85XX_SW_PORT_25,
			&pdata->port_25_cfg);
		if (ret != 0)
			return ret;
	}

	if (pdata->port_26_cfg.port_mode != QCA_85XX_SW_PORT_MODE_NOT_CONFIGURED) {
		ret = qca_85xx_sw_init_sgmii_port(QCA_85XX_SW_PORT_26,
			&pdata->port_26_cfg);
		if (ret != 0)
			return ret;
	}

	if (pdata->port_27_cfg.port_mode != QCA_85XX_SW_PORT_MODE_NOT_CONFIGURED) {
		ret = qca_85xx_sw_init_sgmii_port(QCA_85XX_SW_PORT_27,
			&pdata->port_27_cfg);
		if (ret != 0)
			return ret;
	}

	if (pdata->port_28_cfg.port_mode != QCA_85XX_SW_PORT_MODE_NOT_CONFIGURED) {
		ret = qca_85xx_sw_init_sgmii_port(QCA_85XX_SW_PORT_28,
			&pdata->port_28_cfg);
		if (ret != 0)
			return ret;
	}

	if (pdata->port_29_cfg.port_mode != QCA_85XX_SW_PORT_MODE_NOT_CONFIGURED) {
		ret = qca_85xx_sw_init_sgmii_port(QCA_85XX_SW_PORT_29,
			&pdata->port_29_cfg);
		if (ret != 0)
			return ret;
	}

	/* Configure trunk (Link aggregated) interfaces */
	if (pdata->trunk_cfg.is_trunk_enabled == true) {
		ret = qca_85xx_sw_trunk_enable(&pdata->trunk_cfg);
		if (ret != 0)
			return ret;
	}

	/* Configure port VLANs */
	qca_85xx_sw_enable_port_defaults();

	printk(KERN_INFO "qca_85xx_sw: 8511 switch initialized\n");

	return ret;
}

struct qca_85xx_sw_chip qca8511_chip = {
	.hw_init = qca8511_hw_init,
	.max_qsgmii_if = 2,
	.max_sgmii_plus_if = 4,
	.max_ge_if = 8,
};

/* Netdev notifier callback to inform the change of state of a netdevice */
static int qca_85xx_sw_netdev_notifier_callback(struct notifier_block *this,
						unsigned long event, void *ptr)
{
	struct net_device *dev = netdev_notifier_info_to_dev(ptr);

	if (dev != priv->eth_dev)
		return NOTIFY_DONE;

	if (!netif_carrier_ok(dev))
		return NOTIFY_DONE;

	switch (event) {
	case NETDEV_UP:
	case NETDEV_CHANGE:
		qca_85xx_sw_sgmii_plus_if_change_speed(dev);
		break;
	case NETDEV_DOWN:
	default:
		break;
	}

	return NOTIFY_DONE;
}

/* Switch register read routine */
static uint32_t qca_85xx_sw_mii_read(uint32_t reg_addr)
{
	struct mii_bus *bus = priv->mdio_bus;
	uint32_t reg_word_addr;
	uint32_t phy_addr, tmp_val, reg_val;
	uint16_t phy_val;
	uint8_t phy_reg;

	/* Change reg_addr to 32-bit aligned */
	reg_word_addr = (reg_addr & 0xfffffffc);

	/* Configure register high address */
	phy_addr = 0x18 | (reg_word_addr >> 29);
	phy_reg = (reg_word_addr & 0x1f000000) >> 24;

	/* Bit 23-8 of reg address */
	phy_val = (uint16_t) ((reg_word_addr >> 8) & 0xffff);
	mdiobus_write(bus, phy_addr, phy_reg, phy_val);

	/* For some registers such as MIBs, since it is read/clear,
	 * we should read the lower 16-bit register then the higher one
	 */

	/* Read register in lower address
	 * Bit 7-5 of reg address
	 */
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7);

	/*  Bit 4-0 of reg address */
	phy_reg = (uint8_t) (reg_word_addr & 0x1f);
	reg_val = (uint32_t) mdiobus_read(bus, phy_addr, phy_reg);

	/* Read register in higher address
	 * Bit 7-5 of reg address
	 */

	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7);

	/* Bit4-0 of reg address */
	phy_reg = (uint8_t) ((reg_word_addr & 0x1f) | 0x2);
	tmp_val = (uint32_t) mdiobus_read(bus, phy_addr, phy_reg);
	reg_val |= (tmp_val << 16);

	return reg_val;
}

/* Switch register write routine */
static void qca_85xx_sw_mii_write(uint32_t reg_addr, uint32_t reg_val)
{
	struct mii_bus *bus = priv->mdio_bus;
	uint32_t reg_word_addr;
	uint32_t phy_addr;
	uint16_t phy_val;
	uint8_t phy_reg;

	/* Change reg_addr to 16-bit word address,
	 * 32-bit aligned
	 */
	reg_word_addr = (reg_addr & 0xfffffffc);

	/* configure register high address */
	phy_addr = 0x18 | (reg_word_addr >> 29);
	phy_reg = (reg_word_addr & 0x1f000000) >> 24;

	/* Bit23-8 of reg address */
	phy_val = (uint16_t) ((reg_word_addr >> 8) & 0xffff);
	mdiobus_write(bus, phy_addr, phy_reg, phy_val);

	/* For some registers such as ARL and VLAN, since they include BUSY bit
	 * in lower address, we should write the higher 16-bit register then the
	 * lower one
	 */

	/* write register in higher address
	 *  bit7-5 of reg address
	 */
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7);

	/* bit4-0 of reg address */
	phy_reg = (uint8_t) (reg_word_addr & 0x1f);

	/* lowest 16bit data */
	phy_val = (uint16_t) (reg_val & 0xffff);
	mdiobus_write(bus, phy_addr, phy_reg, phy_val);

	/* write register in lower address
	 * bit7-5 of reg address
	 */
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7);

	/* Bit4-0 of reg address */
	phy_reg = (uint8_t) ((reg_word_addr & 0x1f) | 0x2);

	/* Highest 16bit data */
	phy_val = (uint16_t) ((reg_val >> 16) & 0xffff);
	mdiobus_write(bus, phy_addr, phy_reg, phy_val);
}

/* Check for a valid range of switch register */
static bool qca_85xx_sw_check_valid_reg(uint32_t reg_addr)
{
	return true;
}

/* Copy a string and return number of char copied */
static int qca_85xx_sw_copy_str(char *src, char *dest, int size)
{
	int index = 0;

	if ((size <= 0) || !src || !dest)
		return -1;

	while (*src != ' ' && *src != '\0' && *src != '\n' && index < (size - 1)) {
		dest[index] = *src;
		src++;
		index++;
	}

	dest[index] = '\0';
	return index;
}

/* read from debug-fs file */
static ssize_t qca_85xx_sw_read_reg_get(struct file *fp, char __user *ubuf,
					size_t sz, loff_t *ppos)
{
	char lbuf[40];
	int bytes_read;

	if (!priv)
		return -EFAULT;

	snprintf(lbuf, sizeof(lbuf),
		"0x%x: 0x%x\n",
		priv->reg_addr,
		priv->reg_val);

	bytes_read = simple_read_from_buffer(ubuf,
			sz, ppos,
			lbuf,
			strlen(lbuf));

	return bytes_read;
}

/* Write into the file and read back the switch register */
static ssize_t qca_85xx_sw_read_reg_set(struct file *fp, const char __user *ubuf,
					size_t sz, loff_t *ppos)
{
	char lbuf[32];
	size_t lbuf_size;
	char *curr_ptr = lbuf;
	unsigned long reg_addr = 0;
	uint32_t reg_val = 0;
	bool is_reabable = false;

	if (!priv)
		return -EFAULT;

	lbuf_size = min(sz, (sizeof(lbuf) - 1));

	if (copy_from_user(lbuf, ubuf, lbuf_size)) {
		pr_debug("Failed in copy_from_user\n");
		return -EFAULT;
	}

	lbuf[lbuf_size] = 0;

	while ((*curr_ptr == ' ') && (curr_ptr < &lbuf[lbuf_size]))
		curr_ptr++;

	if (curr_ptr == &lbuf[lbuf_size])
		return -EINVAL;

	if (kstrtoul(curr_ptr, 16, &reg_addr)) {
		pr_debug("Invalid register address input\n");
		return -EINVAL;
	}

	/* Read into PHY reg and store value in previous reg read */
	is_reabable = qca_85xx_sw_check_valid_reg(reg_addr);
	if (is_reabable) {
		priv->reg_addr = reg_addr;
		reg_val = qca_85xx_sw_mii_read(reg_addr);
		priv->reg_val = reg_val;
		return lbuf_size;
	}

	pr_debug("Non-readable register address input\n");
	return -EINVAL;
}

/* Debug-fs function to write a switch register */
static ssize_t qca_85xx_sw_write_reg_set(struct file *fp, const char __user *ubuf,
					 size_t sz, loff_t *ppos)
{
	char lbuf[32];
	char first[QCA_85XX_SW_MAX_REG_SIZE];
	char second[QCA_85XX_SW_MAX_REG_SIZE];
	size_t lbuf_size;
	char *curr_ptr = lbuf;
	unsigned long reg_addr = 0;
	unsigned long reg_val = 0;
	bool is_writeable = false;
	int ret;

	if (!priv)
		return -EFAULT;

	lbuf_size = min(sz, (sizeof(lbuf) - 1));

	if (copy_from_user(lbuf, ubuf, lbuf_size)) {
		pr_debug("Failed in copy_from_user\n");
		return -EFAULT;
	}

	lbuf[lbuf_size] = 0;

	while ((*curr_ptr == ' ') && (curr_ptr < &lbuf[lbuf_size]))
		curr_ptr++;

	if (curr_ptr == &lbuf[lbuf_size])
		return -EINVAL;

	ret = qca_85xx_sw_copy_str(curr_ptr, first, QCA_85XX_SW_MAX_REG_SIZE);
	if (ret <= 0)
		return -EINVAL;

	if (kstrtoul(first, 16, &reg_addr) < 0)
		return -EINVAL;

	curr_ptr += ret;
	while ((*curr_ptr == ' ') && (curr_ptr < &lbuf[lbuf_size]))
		curr_ptr++;

	if (curr_ptr == &lbuf[lbuf_size])
		return -EINVAL;

	ret = qca_85xx_sw_copy_str(curr_ptr, second, QCA_85XX_SW_MAX_REG_SIZE);
	if (ret <= 0)
		return -EINVAL;

	if (kstrtoul(curr_ptr, 16, &reg_val)) {
		pr_debug("Invalid register address input\n");
		return -EINVAL;
	}

	/* Check for a valid range of register before writing */
	is_writeable = qca_85xx_sw_check_valid_reg(reg_addr);
	if (is_writeable) {
		qca_85xx_sw_mii_write(reg_addr, reg_val);
		return lbuf_size;
	}

	pr_debug("Non-writable register address input\n");
	return -EINVAL;
}

static const struct file_operations qca_85xx_sw_read_reg_ops = {
	.open = simple_open,
	.read = qca_85xx_sw_read_reg_get,
	.write = qca_85xx_sw_read_reg_set,
	.llseek = no_llseek,
};

static const struct file_operations qca_85xx_sw_write_reg_ops = {
	.open = simple_open,
	.write = qca_85xx_sw_write_reg_set,
	.llseek = no_llseek,
};

/* Init Netdev notifier event callback to notify any change in netdevice
 * attached with an external PHY
 */
static struct notifier_block qca_85xx_netdev_notifier __read_mostly = {
	.notifier_call		= qca_85xx_sw_netdev_notifier_callback,
};

/* Create debug-fs qca_85xx_sw dir and files */
static int qca_85xx_sw_init_debugfs_entries(void)
{
	priv->top_dentry = debugfs_create_dir("qca-85xx-sw", NULL);
	if (priv->top_dentry == NULL) {
		printk(KERN_ERR "qca_85xx_sw: Failed to create qca-85xx-sw directory in debugfs\n");
		return -1;
	}

	priv->write_dentry = debugfs_create_file("write-reg", 0400,
						priv->top_dentry,
						priv, &qca_85xx_sw_write_reg_ops);

	if (unlikely(priv->write_dentry == NULL)) {
		printk(KERN_ERR "qca_85xx_sw: Failed to create qca-85xx-sw/write-reg file in debugfs\n");
		debugfs_remove_recursive(priv->top_dentry);
		return -1;
	}

	priv->read_dentry = debugfs_create_file("read-reg", 0400,
						priv->top_dentry,
						priv, &qca_85xx_sw_read_reg_ops);

	if (unlikely(priv->read_dentry == NULL)) {
		printk(KERN_ERR "qca_85xx_sw: Failed to create qca-85xx-sw/read-reg file in debugfs\n");
		debugfs_remove_recursive(priv->top_dentry);
		return -1;
	}

	priv->reg_val = 0;
	priv->reg_addr = 0;

	return 0;
}

/* Find the ethernet netdevice attached to the SGMII+ Interface */
static struct net_device *qca_85xx_sw_get_eth_dev(
		struct platform_device *pdev, struct qca_85xx_sw_platform_data *pdata)
{
	struct mii_bus *miibus;
	struct phy_device *phydev;
	struct device *dev;
	uint8_t phy_id[MII_BUS_ID_SIZE + 3];
	struct device_node *np = NULL;
	struct device_node *mdio_node = NULL;
	struct platform_device *mdio_plat = NULL;
	const __be32 *prop = NULL;

	np = of_node_get(pdev->dev.of_node);

	/* Get MDIO BUS pointer */
	prop = of_get_property(np, "sgmii-plus-if-phy-mdiobus", NULL);
	if (!prop) {
		pr_debug("%s: cannot get 'mdiobus' property\n", __func__);
		return NULL;
	}

	mdio_node = of_find_node_by_phandle(be32_to_cpup(prop));
	if (!mdio_node) {
		pr_debug("%s: cannot find mdio node by phandle\n", __func__);
		return NULL;
	}

	mdio_plat = of_find_device_by_node(mdio_node);
	if (!mdio_plat) {
		pr_debug("%s: cannot find platform device from mdio node\n", __func__);
		return NULL;
	}

	miibus = dev_get_drvdata(&mdio_plat->dev);
	if (!miibus) {
		pr_debug("%s: cannot get mdio bus reference from device data\n", __func__);
		return NULL;
	}

	of_node_put(np);

	 /* create a phyid using MDIO bus id and MDIO bus address of phy */
	snprintf(phy_id, MII_BUS_ID_SIZE + 3,
				PHY_ID_FMT,
				miibus->id,
				pdata->sgmii_plus_if_phy_addr);

	dev = bus_find_device_by_name(&mdio_bus_type, NULL, phy_id);
	if (!dev)
		return NULL;

	phydev = to_phy_device(dev);
	if (!phydev)
		return NULL;

	return phydev->attached_dev;
}

/* Set VLAN enable flag */
static int qca_85xx_sw_set_vlan(struct switch_dev *dev,
				const struct switch_attr *attr,
				struct switch_val *val)
{
	if (val->value.i)
		priv->vlan_enable = true;
	else
		priv->vlan_enable = false;

	return 0;
}

/* Get VLAN enable flag */
static int qca_85xx_sw_get_vlan(struct switch_dev *dev,
				const struct switch_attr *attr,
				struct switch_val *val)
{
	if (priv->vlan_enable == true)
		val->value.i = 1;
	else
		val->value.i = 0;

	return 0;
}

/* Issue MIB operation on a port */
static int qca_85xx_sw_issue_mib_op(int port, enum qca_85xx_sw_mib_op mib_op)
{
	uint32_t op, val;

	switch (mib_op) {
	case MIB_CAPTURE:
		op = MIB_OP_TYPE_CAPTURE;
		break;
	case MIB_CAPTURE_AND_CLEAR:
		op = MIB_OP_TYPE_CAPTURE_AND_CLEAR;
		break;
	case MIB_FLUSH:
		op = MIB_OP_TYPE_FLUSH;
		break;
	default:
		return -EINVAL;
	}

	val = port;
	priv->write(MIB_OPERATION, val);
	val |= (op | MIB_BUSY);
	priv->write(MIB_OPERATION, val);

	usleep_range(1000, 10000);

	if (priv->read(MIB_OPERATION) & MIB_BUSY) {
		pr_debug(KERN_ERR "qca_85xx_sw: MIB flush operation timed out\n");
		return -ETIMEDOUT;
	}

	return 0;
}

/* Reset MIB counters for all ports */
static int qca_85xx_sw_set_reset_mibs(struct switch_dev *dev,
				      const struct switch_attr *attr,
				      struct switch_val *val)
{
	int ret = 0, i;

	for (i = 0; i < QCA_85XX_MAX_PORTS; i++) {
		ret = qca_85xx_sw_issue_mib_op(i, MIB_FLUSH);
		if (ret != 0)
			return ret;
	}

	return ret;
}

/* Reset MIB counters for a port */
static int qca_85xx_sw_set_port_reset_mib(struct switch_dev *dev,
					  const struct switch_attr *attr,
					  struct switch_val *val)
{
	int port = val->port_vlan;

	if (port > dev->ports)
		return -EINVAL;

	return qca_85xx_sw_issue_mib_op(port, MIB_FLUSH);
}

/* Read MIB counters for a port */
static int qca_85xx_sw_get_port_mib(struct switch_dev *dev,
				    const struct switch_attr *attr,
				    struct switch_val *val)
{
	int port;
	int i, len = 0, ret = 0;
	char *buf = priv->port_mib;
	uint64_t counter_val, counter_high;
	uint32_t counter_addr = 0;

	port = val->port_vlan;

	if (port > dev->ports)
		return -EINVAL;

	len += snprintf(buf + len, sizeof(priv->port_mib) - len,
			"Port %d MIB counters:\n\n",
			port);

	ret = qca_85xx_sw_issue_mib_op(port, MIB_CAPTURE);
	if (ret != 0)
		return ret;

	for (i = 0; i < priv->num_mib_counters; i++) {
		counter_val = priv->read(MIB_RX_DATA + priv->mib[i].offset);
		if (priv->mib[i].size > 1) {
			counter_addr = MIB_RX_DATA + priv->mib[i].offset + 4;
			counter_high = priv->read(counter_addr);
			counter_val |= (counter_high << 32);
		}

		len += snprintf(buf + len, sizeof(priv->port_mib) - len,
				"%-25s: %llu\n",
				priv->mib[i].name,
				counter_val);
	}

	val->value.s = buf;
	val->len = len;

	return 0;
}

/* Set VLAN Tag ID for a VLAN */
static int qca_85xx_sw_set_vid(struct switch_dev *dev,
				const struct switch_attr *attr,
				struct switch_val *val)
{
	if (val->port_vlan > dev->vlans)
		return -EINVAL;

	if (val->value.i > dev->vlans)
		return -EINVAL;

	priv->vlan_tag_id[val->port_vlan] = val->value.i;

	return 0;
}

/* Get the VLAN Tag ID for a VLAN */
static int qca_85xx_sw_get_vid(struct switch_dev *dev,
				const struct switch_attr *attr,
				struct switch_val *val)
{
	if (val->port_vlan > dev->vlans)
		return -EINVAL;

	val->value.i = priv->vlan_tag_id[val->port_vlan];

	return 0;
}

/* Switch device global attributes */
static struct switch_attr qca_85xx_sw_globals[] = {
	{
		.type = SWITCH_TYPE_INT,
		.name = "enable_vlan",
		.description = "Enable VLAN mode",
		.set = qca_85xx_sw_set_vlan,
		.get = qca_85xx_sw_get_vlan,
		.max = 1
	},
	{
		.type = SWITCH_TYPE_NOVAL,
		.name = "reset_mibs",
		.description = "Reset all MIB counters",
		.set = qca_85xx_sw_set_reset_mibs,
		.get = NULL,
	},
};

/* Switch device per-port attributes */
static struct switch_attr qca_85xx_sw_port[] = {
	{
		.type = SWITCH_TYPE_NOVAL,
		.name = "reset_mib",
		.description = "Reset single port MIB counters",
		.set = qca_85xx_sw_set_port_reset_mib,
		.get = NULL,
	},
	{
		.type = SWITCH_TYPE_STRING,
		.name = "mib",
		.description = "Get port's MIB counters",
		.set = NULL,
		.get = qca_85xx_sw_get_port_mib,
	},
};

/* Switch device per-vlan attributes */
static struct switch_attr qca_85xx_sw_vlan[] = {
	{
		.type = SWITCH_TYPE_INT,
		.name = "vid",
		.description = "VLAN ID (0-4094)",
		.set = qca_85xx_sw_set_vid,
		.get = qca_85xx_sw_get_vid,
		.max = 4094,
	},
};

/* Set Port VLAN ID for a port */
static int qca_85xx_sw_set_pvid(struct switch_dev *dev, int port, int vlan)
{
	int i;

	if (vlan >= dev->vlans)
		return -EINVAL;

	if (port >= QCA_85XX_MAX_PORTS)
		return -EINVAL;

	priv->port_vlan_id[port] = vlan;

	/* Make sure that this port does not
	 * appear in other vlans
	 */
	for (i = 0; i < QCA_85XX_MAX_VLANS; i++) {
		if (i == vlan)
			continue;
		priv->vlan_port_map[i] &= ~(1 << port);
	}

	return 0;
}

/* Get Port VLAN ID for a port */
static int qca_85xx_sw_get_pvid(struct switch_dev *dev, int port, int *vlan)
{
	if (port >= QCA_85XX_MAX_PORTS)
		return -EINVAL;

	*vlan = priv->port_vlan_id[port];

	return 0;
}

/* Get the member ports for a port VLAN ID */
static int qca_85xx_sw_get_ports(struct switch_dev *dev, struct switch_val *val)
{
	uint32_t ports = priv->vlan_port_map[val->port_vlan];
	int i;

	val->len = 0;
	for (i = 1; i <= dev->ports; i++) {
		struct switch_port *p;

		if (!(ports & (1 << i)))
			continue;

		p = &val->value.ports[val->len++];
		p->id = i;
		if (priv->vlan_tagged_ports_bm & (1 << i))
			p->flags = (1 << SWITCH_PORT_FLAG_TAGGED);
		else
			p->flags = 0;
	}
	return 0;
}

/* Set the member ports for a port-VLAN */
static int qca_85xx_sw_set_ports(struct switch_dev *dev, struct switch_val *val)
{
	uint32_t *vt = &priv->vlan_port_map[val->port_vlan];
	uint32_t *vt_tagged, vid;
	int i, j;

	vid = priv->vlan_tag_id[val->port_vlan];
	vt_tagged = &priv->vlan_port_map[vid];

	*vt = 0;
	*vt_tagged = 0;

	for (i = 0; i < val->len; i++) {
		struct switch_port *p = &val->value.ports[i];

		if (p->flags & (1 << SWITCH_PORT_FLAG_TAGGED)) {
			*vt_tagged |= 1 << p->id;
			priv->vlan_tagged_ports_bm |= (1 << p->id);
		} else {
			priv->vlan_tagged_ports_bm &= ~(1 << p->id);
			priv->port_vlan_id[p->id] = val->port_vlan;

			/* Make sure that an untagged port does not
			 * appear in other vlans
			 */
			for (j = 0; j < QCA_85XX_MAX_VLANS; j++) {
				if (j == val->port_vlan)
					continue;
				priv->vlan_port_map[j] &= ~(1 << p->id);
			}

			*vt |= 1 << p->id;
		}
	}

	return 0;
}

/* Apply the configured settings */
static int qca_85xx_sw_hw_apply(struct switch_dev *dev)
{
	int i, ret = 0;

	for (i = 0; i < QCA_85XX_MAX_VLANS; i++) {
		if (priv->vlan_port_map[i] == 0)
			continue;
		ret = qca_85xx_port_vlan_group_enable(i,
							priv->vlan_port_map[i]);
		if (ret != 0)
			return ret;
	}

	return 0;
}

/* Switch software reset */
static int qca_85xx_sw_reset_switch(struct switch_dev *dev)
{
	/* Initialize VLAN tables */
	qca_85xx_sw_init_vlan_tables();

	return 0;
}

/* switch device operations */
static const struct switch_dev_ops qca_85xx_sw_ops = {
	.attr_global = {
		.attr = qca_85xx_sw_globals,
		.n_attr = ARRAY_SIZE(qca_85xx_sw_globals),
	},
	.attr_port = {
		.attr = qca_85xx_sw_port,
		.n_attr = ARRAY_SIZE(qca_85xx_sw_port),
	},
	.attr_vlan = {
		.attr = qca_85xx_sw_vlan,
		.n_attr = ARRAY_SIZE(qca_85xx_sw_vlan),
	},
	.get_port_pvid = qca_85xx_sw_get_pvid,
	.set_port_pvid = qca_85xx_sw_set_pvid,
	.get_vlan_ports = qca_85xx_sw_get_ports,
	.set_vlan_ports = qca_85xx_sw_set_ports,
	.apply_config = qca_85xx_sw_hw_apply,
	.reset_switch = qca_85xx_sw_reset_switch,
	.get_port_link = NULL,
	.get_reg_val = NULL,
	.set_reg_val = NULL,
};

static void qca_85xx_sw_of_get_pdata(struct device_node *np,
				     struct qca_85xx_sw_platform_data *pdata)
{

	uint32_t is_config_set = 0;

	of_property_read_u32(np,
		"qcom,sgmii-plus-if-phy-addr",
		&pdata->sgmii_plus_if_phy_addr);
	of_property_read_u32(np,
		"qcom,chip-id",
		&pdata->chip_id);
	of_property_read_u32(np,
		"qcom,qsgmii-cfg-port-mode",
		&pdata->qsgmii_cfg.port_mode);
	of_property_read_u32(np,
		"qcom,qsgmii-cfg-port-base",
		&pdata->qsgmii_cfg.port_base);

	of_property_read_u32(np,
		"qcom,qsgmii-cfg-is-speed-forced",
		&is_config_set);
	if (is_config_set == 1)
		pdata->qsgmii_cfg.is_speed_forced = true;
	else
		pdata->qsgmii_cfg.is_speed_forced = false;

	is_config_set = 0;
	of_property_read_u32(np,
		"qcom,qsgmii-cfg-forced-speed",
		&pdata->qsgmii_cfg.forced_speed);
	of_property_read_u32(np,
		"qcom,qsgmii-cfg-forced-duplex",
		&pdata->qsgmii_cfg.forced_duplex);
	of_property_read_u32(np,
		"qcom,port-26-cfg-port-mode",
		&pdata->port_26_cfg.port_mode);

	of_property_read_u32(np,
		"qcom,port-26-cfg-is-speed-forced",
		&is_config_set);
	if (is_config_set == 1)
		pdata->port_26_cfg.is_speed_forced = true;
	else
		pdata->port_26_cfg.is_speed_forced = false;

	is_config_set = 0;
	of_property_read_u32(np,
		"qcom,port-27-cfg-port-mode",
		&pdata->port_27_cfg.port_mode);

	of_property_read_u32(np,
		"qcom,port-27-cfg-is-speed-forced",
		&is_config_set);
	if (is_config_set == 1)
		pdata->port_27_cfg.is_speed_forced = true;
	else
		pdata->port_27_cfg.is_speed_forced = false;

	is_config_set = 0;
	of_property_read_u32(np,
		"qcom,port-27-cfg-forced-speed",
		&pdata->port_27_cfg.forced_speed);
	of_property_read_u32(np,
		"qcom,port-27-cfg-forced-duplex",
		&pdata->port_27_cfg.forced_duplex);

	of_property_read_u32(np,
		"qcom,trunk-cfg-is-trunk-enabled",
		&is_config_set);
	if (is_config_set == 1)
		pdata->trunk_cfg.is_trunk_enabled = true;
	else
		pdata->trunk_cfg.is_trunk_enabled = false;

	of_property_read_u32(np,
		"qcom,trunk-cfg-trunk-id",
		&pdata->trunk_cfg.trunk_id);
	of_property_read_u32(np,
		"qcom,trunk-cfg-trunk-hash-policy",
		&pdata->trunk_cfg.trunk_hash_policy);
	of_property_read_u32(np,
		"qcom,trunk-cfg-trunk-ports-bit-map",
		&pdata->trunk_cfg.trunk_ports_bit_map);
}

static int qca_85xx_sw_probe(struct platform_device *pdev)
{
	struct mii_bus *mdio_bus;
	bool sgmii_plus_link_state_notifier_registered = false;
	bool qca_85xx_sw_dev_registered = false;
	struct switch_dev *swdev;
	struct device_node *np = NULL;
	struct qca_85xx_sw_platform_data *pdata = NULL;
	struct device_node *mdio_node = NULL;
	struct platform_device *mdio_plat = NULL;
	const __be32 *prop = NULL;
	int ret = -1;

	pdata = vzalloc(sizeof(struct qca_85xx_sw_platform_data));
	if (pdata == NULL) {
		printk(KERN_ERR "qca_85xx_sw: Could not allocate memory for qca_85xx_sw platform data\n");
		return ret;
	}

	np = of_node_get(pdev->dev.of_node);
	qca_85xx_sw_of_get_pdata(np, pdata);

	priv = vzalloc(sizeof(struct qca_85xx_sw_priv));
	if (priv == NULL) {
		printk(KERN_ERR "qca_85xx_sw: Could not allocate private memory for 85xx driver\n");
		vfree(pdata);
		return ret;
	}

	if (pdata->chip_id == QCA_85XX_SW_ID_QCA8511) {
		priv->chip = &qca8511_chip;
		priv->read = qca_85xx_sw_mii_read;
		priv->write = qca_85xx_sw_mii_write;
	} else {
		printk(KERN_ERR "qca_85xx_sw: Unsupported 85xx switch chipset\n");
		goto err;
	}

	/* Get MDIO BUS pointer */
	prop = of_get_property(np, "mdiobus", NULL);
	if (!prop) {
		pr_debug("%s: cannot get 'mdiobus' property\n", __func__);
		goto err;
	}

	mdio_node = of_find_node_by_phandle(be32_to_cpup(prop));
	if (!mdio_node) {
		pr_debug("%s: cannot find mdio node by phandle\n", __func__);
		goto err;
	}

	mdio_plat = of_find_device_by_node(mdio_node);
	if (!mdio_plat) {
		pr_debug("%s: cannot find platform device from mdio node\n", __func__);
		goto err;
	}

	mdio_bus = dev_get_drvdata(&mdio_plat->dev);
	if (!mdio_bus) {
		pr_debug("%s: cannot get mdio bus reference from device data\n", __func__);
		goto err;
	}
	of_node_put(np);

	priv->mdio_bus = mdio_bus;

	/* Find the ethernet device we are bound to */
	priv->eth_dev = qca_85xx_sw_get_eth_dev(pdev, pdata);
	if (!priv->eth_dev) {
		printk(KERN_ERR "qca_85xx_sw: Could not find ethernet device\n");
		goto err;
	}

	/* Initialize the debug-fs entries */
	ret = qca_85xx_sw_init_debugfs_entries();
	if (ret < 0) {
		printk(KERN_ERR "qca_85xx_sw: Could not initialize debugfs entries\n");
		goto err;
	}

	ret = register_netdevice_notifier(&qca_85xx_netdev_notifier);
	if (ret != 0) {
		printk(KERN_ERR "qca_85xx_sw: Failed to register netdevice notifier %d\n", ret);
		goto err;
	}

	sgmii_plus_link_state_notifier_registered = true;

	/* Initialize VLAN tables */
	qca_85xx_sw_init_vlan_tables();

	/* Initialize MIB */
	priv->mib = qca_85xx_mib;
	priv->num_mib_counters = ARRAY_SIZE(qca_85xx_mib);
	priv->vlan_enable = true;

	swdev = &priv->dev;
	swdev->cpu_port = 0;
	swdev->ops = &qca_85xx_sw_ops;
	swdev->ports = QCA_85XX_MAX_PORTS;
	swdev->vlans = QCA_85XX_MAX_VLANS;
	if (pdata->chip_id == QCA_85XX_SW_ID_QCA8511)
		swdev->name = "QCA8511 Switch";

	ret = register_switch(&priv->dev, priv->eth_dev);
	if (ret) {
		printk(KERN_ERR "qca_85xx_sw: Error registering 85xx switch chipset\n");
		goto err;
	}

	qca_85xx_sw_dev_registered = true;

	ret = priv->chip->hw_init(pdata);
	if (ret != 0) {
		printk(KERN_ERR "qca_85xx_sw: Error initializing 85xx chipset\n");
		goto err;
	}

	priv->sgmii_plus_link_speed = SPEED_UNKNOWN;

	return 0;

err:
	if (qca_85xx_sw_dev_registered)
		unregister_switch(&priv->dev);

	if (sgmii_plus_link_state_notifier_registered)
		unregister_netdevice_notifier(&qca_85xx_netdev_notifier);

	if (priv->top_dentry != NULL)
		debugfs_remove_recursive(priv->top_dentry);

	if (priv->eth_dev)
		dev_put(priv->eth_dev);

	if (priv)
		vfree(priv);

	if (pdata)
		vfree(pdata);

	return ret;
}
static int qca_85xx_sw_remove(struct platform_device *pdev)
{
	unregister_switch(&priv->dev);

	/* Remove debugfs tree */
	if (likely(priv->top_dentry != NULL))
		debugfs_remove_recursive(priv->top_dentry);

	dev_put(priv->eth_dev);

	vfree(priv);

	unregister_netdevice_notifier(&qca_85xx_netdev_notifier);

	return 0;
}

static struct platform_driver qca_85xx_sw_driver = {
	.driver = {
		.name = "qca-85xx-sw",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(dt_qca_85xx_sw),
	},
	.probe = qca_85xx_sw_probe,
	.remove = qca_85xx_sw_remove,
};

int __init qca_85xx_sw_init(void)
{
	platform_driver_register(&qca_85xx_sw_driver);

	return 0;
}

void __exit qca_85xx_sw_exit(void)
{
	platform_driver_unregister(&qca_85xx_sw_driver);
}

module_init(qca_85xx_sw_init);
module_exit(qca_85xx_sw_exit);
MODULE_LICENSE("Dual BSD/GPL");
