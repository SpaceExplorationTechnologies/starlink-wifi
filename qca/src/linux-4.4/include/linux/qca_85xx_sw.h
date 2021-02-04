/*
 * QCA 85xx switch driver platform data
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

#ifndef QCA_85XX_SW_H
#define QCA_85XX_SW_H

#define QCA_85XX_MAX_TRUNKS	8
#define QCA_85XX_MAX_PORTS	30
#define QCA_85XX_VLAN_ID_MAX	4094
#define QCA_85XX_MAX_VLANS	4095

/* Device IDS for the 85xx switch family */
enum {
	QCA_85XX_SW_ID_QCA8511 = 0x01,
	QCA_85XX_SW_ID_QCA8512 = 0x02,
	QCA_85XX_SW_ID_QCA8513 = 0x03,
	QCA_85XX_SW_ID_QCA8519 = 0x04,
};

/* GMAC port modes */
enum qca_85xx_sw_port_mode {
	QCA_85XX_SW_PORT_MODE_NOT_CONFIGURED = 0,
	QCA_85XX_SW_PORT_MODE_QSGMII = 1,
	QCA_85XX_SW_PORT_MODE_SGMII = 2,
	QCA_85XX_SW_PORT_MODE_SGMII_PLUS = 3,
	QCA_85XX_SW_PORT_MODE_XAUI = 4,
};

/* QSGMII port platform configuration data */
struct qca_85xx_sw_qsgmii_cfg {
	enum qca_85xx_sw_port_mode port_mode;
	uint32_t port_base;
	bool is_speed_forced;
	uint32_t forced_speed;
	uint32_t forced_duplex;
};

/* SGMII port platform configuration data */
struct qca_85xx_sw_sgmii_cfg {
	enum qca_85xx_sw_port_mode port_mode;
	bool is_speed_forced;
	uint32_t forced_speed;
	uint32_t forced_duplex;
};

/* Platform configuration data for LAG trunk */
struct qca_85xx_sw_trunk_cfg {
	bool is_trunk_enabled;
	uint32_t trunk_id;
	uint32_t trunk_hash_policy;
	uint32_t trunk_ports_bit_map;
};

/* 85xx Switch platform configuration */
struct qca_85xx_sw_platform_data {
	const char	*mdio_bus_name;
	const char	*sgmii_plus_if_mdio_bus_name;
	int		mdio_bus_id;
	int		sgmii_plus_if_phy_mdio_bus_id;
	uint32_t	sgmii_plus_if_phy_addr;
	uint32_t	chip_id;
	struct qca_85xx_sw_qsgmii_cfg qsgmii_cfg;
	struct qca_85xx_sw_sgmii_cfg port_24_cfg;
	struct qca_85xx_sw_sgmii_cfg port_25_cfg;
	struct qca_85xx_sw_sgmii_cfg port_26_cfg;
	struct qca_85xx_sw_sgmii_cfg port_27_cfg;
	struct qca_85xx_sw_sgmii_cfg port_28_cfg;
	struct qca_85xx_sw_sgmii_cfg port_29_cfg;
	struct qca_85xx_sw_trunk_cfg trunk_cfg;
};

/* 85xx Switch GMAC port IDs */
enum qca_85xx_sw_gmac_port {
	QCA_85XX_SW_PORT_1 = 1,
	QCA_85XX_SW_PORT_5 = 5,
	QCA_85XX_SW_PORT_9 = 9,
	QCA_85XX_SW_PORT_13 = 13,
	QCA_85XX_SW_PORT_17 = 17,
	QCA_85XX_SW_PORT_21 = 21,
	QCA_85XX_SW_PORT_23 = 23,
	QCA_85XX_SW_PORT_24 = 24,
	QCA_85XX_SW_PORT_25 = 25,
	QCA_85XX_SW_PORT_26 = 26,
	QCA_85XX_SW_PORT_27 = 27,
	QCA_85XX_SW_PORT_28 = 28,
	QCA_85XX_SW_PORT_29 = 29,
};

/* Bit definitions for TRUNK_HASH_KEY_SEL register */
#define TRUNK_L4_DST_PORT_INCL	0x1	/* Include L4 dst port for trunk hash */
#define TRUNK_L4_SRC_PORT_INCL	0x2	/* Include L4 src port for trunk hash */
#define TRUNK_DST_IP_INCL	0x4	/* Include dst IP address for trunk hash */
#define TRUNK_SRC_IP_INCL	0x8	/* Include src IP address for trunk hash */
#define TRUNK_L2_PROT_INCL	0x10	/* Include L2 protocol for trunk hash */
#define TRUNK_MAC_DA_INCL	0x20	/* Include dst MAC address for trunk hash */
#define TRUNK_MAC_SA_INCL	0x40	/* Include src MAC address for trunk hash */
#define TRUNK_SRC_PORT_INCL	0x80	/* Include GMAC src port ID for trunk hash */

#endif /* QCA_85XX_SW_H */
