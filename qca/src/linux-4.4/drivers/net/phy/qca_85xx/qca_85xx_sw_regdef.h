/*
 * QCA 85xx switch register definitions
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

#ifndef QCA_85XX_SW_REG_H
#define QCA_85XX_SW_REG_H

/* Register definitions */
#define GLOBAL_CTRL_0				0x0
#define GLOBAL_CTRL_1				0x8
#define SD_CLK_SEL				0x20
#define PORT_STATUS_CFG_PORT0			0x100
#define PORT_VLAN_FLTR				0x4054
#define VLAN_OPERATION				0x4060
#define VLAN_OP_DATA_0				0x4064
#define VLAN_OP_DATA_1				0x4068
#define PORT_EG_VLAN_CTRL			0x4600
#define L2_MISC_CTRL				0x6000
#define TRUNK_HASH_KEY_SEL			0x600c
#define PORT_TRUNK_CFG_PORT0			0x6800
#define MIB_OPERATION				0xe000
#define MIB_RX_DATA				0xe010
#define MIB_TX_DATA				0xe080
#define QSGMII_CTRL_GRP0_BASE			0x13000
#define SGMII_CTRL0_PORT26			0x13200	/* Control for SGMII ports  - Port 26 */
#define SGMII_CTRL0_PORT27			0x13220	/* Control for SGMII ports  - Port 27 */
#define SGMII_CTRL0_PORT28			0x13240	/* Control for SGMII ports  - Port 28 */
#define SGMII_CTRL0_PORT29			0x13260	/* Control for SGMII ports  - Port 29 */
#define XAUI_SGMII_SERDES13_CTRL0		0x1341c	/* Serdes controls for SGMII/SGMII+ Port 26 to 29 */
#define XAUI_SGMII_SERDES13_CTRL1		0x13420	/* Serdes controls for SGMII/SGMII+ Port 26 to 29 */
#define IN_VLAN_TRANSLATION_BASE_WORD_0		0xb0000
#define IN_VLAN_TRANSLATION_BASE_WORD_1		0xb0004
#define IN_VLAN_TRANSLATION_BASE_WORD_2		0xb0008
#define SPANNING_TREE_GROUP_REG_0_GROUP_0	0xd0000
#define SPANNING_TREE_GROUP_REG_1_GROUP_0	0xd0004
#define EG_VLAN_TAG_ENTRY_0			0x110000
#define TRUNK_GROUP_MEM_REG_0_TRUNK_ID_0	0x2e0000
#define TRUNK_GROUP_MEM_REG_1_TRUNK_ID_0	0x2e0004
#define TRUNK_GROUP_MEM_REG_2_TRUNK_ID_0	0x2e0008
#define TRUNK_LOCAL_PORT_MEM_TRUNK_ID_0		0x2b0000

/* Bit Definitions for GLOBAL_CTRL_0 */
#define GLOBAL_CTRL_0_SOFT_RST			0x80000000
#define GLOBAL_CTRL_0_REG_RST_EN		0x40000

/* Bit definitions for GLOBAL_CTRL_1 */
#define GLOBAL_CTRL_1_MAC1_SGMII_EN		0x4
#define GLOBAL_CTRL_1_PORT_26_SGMII_PLUS_EN	0x4000
#define GLOBAL_CTRL_1_PORT_26_SGMII_EN		0x8000
#define GLOBAL_CTRL_1_PORT_27_SGMII_PLUS_EN	0x10000
#define GLOBAL_CTRL_1_PORT_27_SGMII_EN		0x20000
#define GLOBAL_CTRL_1_PORT_28_SGMII_PLUS_EN	0x40000
#define GLOBAL_CTRL_1_PORT_28_SGMII_EN		0x80000
#define GLOBAL_CTRL_1_PORT_29_SGMII_PLUS_EN	0x100000
#define GLOBAL_CTRL_1_PORT_29_SGMII_EN		0x200000

/* Bit definitions for SD_CLK_SEL */
#define SD_CLK_SEL_QSGMII_1_RX			0x1
#define SD_CLK_SEL_SGMII_PORT26_RX		0x1000
#define SD_CLK_SEL_SGMII_PORT27_RX		0x2000
#define SD_CLK_SEL_SGMII_PORT28_RX		0x4000
#define SD_CLK_SEL_SGMII_PORT29_RX		0x8000

/* Bit definitions for PORT_STATUS_CFG */
#define port_status_cfg(n)	(PORT_STATUS_CFG_PORT0 + (n * 0x100))
#define PORT_STATUS_FORCE_SPEED_10	0x0
#define PORT_STATUS_FORCE_SPEED_100	0x1
#define PORT_STATUS_FORCE_SPEED_1000	0x2
#define PORT_STATUS_TXMAC_EN		0x4
#define PORT_STATUS_RXMAC_EN		0x8
#define PORT_STATUS_TX_FLOW_EN		0x10
#define PORT_STATUS_RX_FLOW_EN		0x20
#define PORT_STATUS_FORCE_DUPLEX_FULL	0x40
#define PORT_STATUS_TX_HALF_FLOW_EN	0x80
#define PORT_STATUS_AUTONEG_EN		0x200
#define PORT_STATUS_AUTO_FLOW_CTRL_EN	0x1000

/* Bit definitions for VLAN_OPERATION */
#define VLAN_OP_TYPE_ADD_ONE	0x0
#define VLAN_OP_SHIFT_VAL	27
#define VLAN_BUSY		0x80000000
#define VLAN_OP_START		VLAN_BUSY

/* Bit definitions for VLAN_OP_DATA_1 */
#define LRN_EN			0x800
#define SVL_ON			0x20000
#define VLAN_TABLE_ENTRY_VALID	0x40000

/* Bit definitions for PORT_EG_VLAN_CTRL */
#define port_eg_vlan_ctrl(n)	(PORT_EG_VLAN_CTRL + (n * 0x10))
#define PORT_EG_VLAN_TYPE_MODE_UNTAGGED		0x0
#define PORT_EG_VLAN_TYPE_MODE_UNMODIFIED	0x2
#define PORT_EG_VLAN_TYPE_MODE_SHIFT_LEN	0
#define PORT_TAG_CONTROL_VID_LOOKUP_VID		0x8
#define PORT_EG_VLAN_CTRL_RESERVED		0x30000

/* Bit definitions for PORT_VLAN_FLTR */
#define PORT_VLAN_FLTR_ALL_PORTS_FLTR_EN 0x0

/* Bit definitions for L2_MISC_CTRL */
#define FAILOVER_EN 0x40000

/* Bit definitions for IN_VLAN_TRANSLATION table entries */
#define in_vlan_table_word_0(m, n)	(IN_VLAN_TRANSLATION_BASE_WORD_0 + (m * 0x100) + (n * 0x10))
#define in_vlan_table_word_1(m, n)	(IN_VLAN_TRANSLATION_BASE_WORD_1 + (m * 0x100) + (n * 0x10))
#define in_vlan_table_word_2(m, n)	(IN_VLAN_TRANSLATION_BASE_WORD_2 + (m * 0x100) + (n * 0x10))
#define IN_VLAN_ENTRY_LOWEST_PRIO	0xF

/* Bit description for in_vlan_table word 0 */
#define CKEY_VID_SHIFT_LEN		0
#define CVID_SEARCH_KEY_VALUE_UNTAGGED	0x0

/* Bit description for in_vlan_table word 1 */
#define XLT_CVID_SHIFT_LEN		0
#define XLT_CVID_EN			0x1000
#define CKEY_VID_INCL			0x8000

/* Bit description for in_vlan_table word 2 */
#define CKEY_FMT_SHIFT_LEN		0
#define CVLAN_ASSIGN_ALL_FRAMES		0x3
#define SA_LRN_EN			0x20
#define IN_VLAN_TABLE_ENTRY_VALID	0x80

/* Bit Description for SPANNING_TREE_GROUP */
#define spanning_tree_group_reg_0(n) (SPANNING_TREE_GROUP_REG_0_GROUP_0 + (n * 0x10))
#define spanning_tree_group_reg_1(n) (SPANNING_TREE_GROUP_REG_1_GROUP_0 + (n * 0x10))
#define PORT_DISABLE	0x0
#define PORT_BLOCKING	0x1
#define PORT_LEARNING	0x2
#define PORT_FORWARDING	0x3

/* Bit description for EG_VLAN_TAG table entries */
#define eg_vlan_tag(n)	(EG_VLAN_TAG_ENTRY_0 + (n * 0x10))
#define EG_VLAN_TAG_TABLE_ENTRY_VALID	0x40000000

/* Bit definitions for TRUNK_GROUP_MEM table */
#define trunk_group_mem_0(n) (TRUNK_GROUP_MEM_REG_0_TRUNK_ID_0 + (n * 0x10))
#define trunk_group_mem_1(n) (TRUNK_GROUP_MEM_REG_1_TRUNK_ID_0 + (n * 0x10))
#define trunk_group_mem_2(n) (TRUNK_GROUP_MEM_REG_2_TRUNK_ID_0 + (n * 0x10))
#define TRUNK_MEM_PORT_ID_SHIFT_LEN	12

/* Bit definitions for TRUNK_LOCAL_PORT_MEM table entries */
#define trunk_local_port_mem(n) (TRUNK_LOCAL_PORT_MEM_TRUNK_ID_0 + (n * 0x10))

/* Bit definitions for PORT_TRUNK_CFG */
#define port_trunk_cfg(n)	(PORT_TRUNK_CFG_PORT0 + (n * 0x10))
#define PORT_TRUNK_ID_MASK	0x7
#define PORT_TRUNK_EN		0x20

/* Bit definitions for MIB_OPERATION */
#define MIB_OP_TYPE_SHIFT_LEN	29
#define MIB_OP_TYPE_CAPTURE		(0x0 << MIB_OP_TYPE_SHIFT_LEN)
#define MIB_OP_TYPE_CAPTURE_AND_CLEAR	(0x1 << MIB_OP_TYPE_SHIFT_LEN)
#define MIB_OP_TYPE_FLUSH		(0x2 << MIB_OP_TYPE_SHIFT_LEN)
#define MIB_BUSY			0x80000000

/* MIB Statistic Rx counters offsets from MIB_RX_DATA */
#define MIB_STATS_RX_BROAD		0x0
#define MIB_STATS_RX_PAUSE		0x4
#define MIB_STATS_RX_MULTI		0x8
#define MIB_STATS_RX_FCS_ERR		0xc
#define MIB_STATS_RX_ALIGN_ERR		0x10
#define MIB_STATS_RX_RESERVED0		0x14
#define MIB_STATS_RX_RESERVED1		0x18
#define MIB_STATS_RX_JUMBO_FCS_ERR	0x1c
#define MIB_STATS_RX_JUMBO_ALIGN_ERR	0x20
#define MIB_STATS_RX_PKT_64B		0x24
#define MIB_STATS_RX_PKT_65_127B	0x28
#define MIB_STATS_RX_PKT_128_255B	0x2c
#define MIB_STATS_RX_PKT_256_511B	0x30
#define MIB_STATS_RX_PKT_512_1023B	0x34
#define MIB_STATS_RX_PKT_1024_1518B	0x38
#define MIB_STATS_RX_PKT_1519_XB	0x3c
#define MIB_STATS_RX_TOO_LONG		0x40
#define MIB_STATS_RX_GOOD_BYTE		0x44
#define MIB_STATS_RX_BAD_BYTE		0x4c
#define MIB_STATS_RX_OVER_FLOW		0x54
#define MIB_STATS_RX_RUNT_NUM		0x170
#define MIB_STATS_RX_RUNT_BYTE		0x174
#define MIB_STATS_RX_FRAG_NUM		0x178
#define MIB_STATS_RX_FRAG_BYTE		0x17c

/* MIB Statistic Tx counters offsets from MIB_RX_DATA */
#define MIB_STATS_TX_BROAD		0x70
#define MIB_STATS_TX_PAUSE		0x74
#define MIB_STATS_TX_MULTI		0x78
#define MIB_STATS_TX_UNDER_RUN		0x7c
#define MIB_STATS_TX_PKT_64B		0x80
#define MIB_STATS_TX_PKT_65_127B	0x84
#define MIB_STATS_TX_PKT_128_255B	0x88
#define MIB_STATS_TX_PKT_256_511B	0x8c
#define MIB_STATS_TX_PKT_512_1023B	0x90
#define MIB_STATS_TX_PKT_1024_1518B	0x94
#define MIB_STATS_TX_PKT_1519_XB	0x98
#define MIB_STATS_TX_RESERVED0		0x9c
#define MIB_STATS_TX_BYTE		0xa0
#define MIB_STATS_TX_COLLISION		0xa8
#define MIB_STATS_TX_ABORTCOL		0xac
#define MIB_STATS_TX_MULTICOL		0xb0
#define MIB_STATS_TX_SINGLECOL		0xb4
#define MIB_STATS_TX_EXCESSIVE_DEFER	0xb8
#define MIB_STATS_TX_DEFER		0xbc
#define MIB_STATS_TX_LATE_COL		0xc0

/* CH0 Control for QSGMII0/QSGMII2/QSGMII4 */
#define QSGMII_1_CTRL0(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x0)

/* QSGMII settings for QSGMII0/QSGMII2/QSGMII4 */
#define QSGMII_1_CTRL1(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x4)

/* QSGMII settings for QSGMII0/QSGMII2/QSGMII4 */
#define QSGMII_1_CTRL2(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x8)

/* CH1 Control for QSGMII0/QSGMII2/QSGMII4 */
#define QSGMII_2_CTRL0(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0xc)

/* CH2 Control for QSGMII0/QSGMII2/QSGMII4 */
#define QSGMII_3_CTRL0(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x10)

/* CH3 Control for QSGMII0/QSGMII2/QSGMII4 */
#define QSGMII_4_CTRL0(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x14)

/* CH0 Control for QSGMII1/QSGMII3/QSGMII5 */
#define QSGMII_5_CTRL0(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x18)

/* QSGMII settings for QSGMII0/QSGMII2/QSGMII4 */
#define QSGMII_5_CTRL1(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x1c)

/* QSGMII settings for QSGMII0/QSGMII2/QSGMII4 */
#define QSGMII_5_CTRL2(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x20)

/* Register not defined */
#define QSGMII_RESERVED	0x24

/* CH1 Control for QSGMII1/QSGMII3/QSGMII5 */
#define QSGMII_6_CTRL0(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x28)

/* CH2 Control for QSGMII1/QSGMII3/QSGMII5 */
#define QSGMII_7_CTRL0(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x2c)

/* CH3 Control for QSGMII1/QSGMII3/QSGMII5 */
#define QSGMII_8_CTRL0(group)	(QSGMII_CTRL_GRP0_BASE + (0x50*group) + 0x30)

/* Bit definitions for QSGMII_1_CTRL0 */
#define QSGMII_CTRL_FORCE_DUPLEX_FULL	0x1
#define QSGMII_CTRL_FORCE_LINK_UP	0x2
#define QSGMII_CTRL_FORCE_SPEED_10	0x0
#define QSGMII_CTRL_FORCE_SPEED_100	0x4
#define QSGMII_CTRL_FORCE_SPEED_1000	0x8
#define QSGMII_CTRL_FORCE_SPEED		0x00200000
#define QSGMII_CTRL_QSGMII_MODE_PHY	0x00400000
#define QSGMII_CTRL_QSGMII_MODE_MAC	0x00800000

/* Bit definitions for SGMII_CTRL0 */
#define SGMII_CTRL0_FORCE_DUPLEX_FULL	0x1
#define SGMII_CTRL0_FORCE_SPEED_10	0x0
#define SGMII_CTRL0_FORCE_SPEED_100	0x4
#define SGMII_CTRL0_FORCE_SPEED_1000	0x8
#define SGMII_CTRL0_MR_AN_EN		0x400
#define SGMII_CTRL0_FORCE_MODE_EN	0x200000

#define SGMII_CTRL0_SGMII_MODE_1000BASE_X	0x0
#define SGMII_CTRL0_SGMII_MODE_PHY		0x400000
#define SGMII_CTRL0_SGMII_MODE_MAC		0x800000

/* MIB Operations */
enum qca_85xx_sw_mib_op {
	MIB_CAPTURE = 0,
	MIB_CAPTURE_AND_CLEAR = 1,
	MIB_FLUSH = 2,
};

#define MIB_DESC(_s, _o, _n)	\
	{			\
		.size = (_s),	\
		.offset = (_o),	\
		.name = (_n),	\
	}

#endif
