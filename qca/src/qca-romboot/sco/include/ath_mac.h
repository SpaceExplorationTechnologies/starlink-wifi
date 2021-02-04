/*
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _AG7240_H
#define _AG7240_H

/*
 * h/w descriptor
 */
typedef struct {
	unsigned int	pkt_start_addr,
			is_empty	:  1,
			res1		: 10,
			ftpp_override	:  5,
			res2		:  4,
			pkt_size	: 12,
			next_desc;
} ath_gmac_desc_t;

#define NO_OF_TX_FIFOS			8
#define NO_OF_RX_FIFOS			8

typedef struct {
	ath_gmac_desc_t		*fifo_tx[NO_OF_TX_FIFOS],
				*fifo_rx[NO_OF_RX_FIFOS];
	struct eth_device	*dev;
	u32			next_tx,
				next_rx,
				link,
				duplex,
				speed,
				mac_unit,
				mac_base;
} ath_gmac_softc_t;

#define ath_gmac_reg_wr(_mac, _x, _y)	ath_reg_wr(((_x) + _mac->mac_base), (_y))
#define ath_gmac_reg_rd(_mac, _x)	ath_reg_rd(((_x) + _mac->mac_base))

#define ath_gmac_reg_rmw_set(_mac, _x, _y)	\
	ath_reg_rmw_set(((_x) + _mac->mac_base ), (_y))
#define ath_gmac_reg_rmw_clear(_mac, _x, _y)	\
	ath_reg_rmw_clear(((_x) + _mac->mac_base), (_y))

/*
 * spd is _1000BASET, _100BASET etc. defined in include/miiphy.h
 */
#define mii_reg(_mac)	(ETH_CFG_ADDRESS + ((_mac)->mac_unit * 4))
#define mii_if(_mac)	(((_mac)->mac_unit == 0) ? mii0_if : mii1_if)

#define ag7240_set_mii_ctrl_speed(_mac, _spd)	do {	\
	ath_reg_rmw_clear(mii_reg(_mac), (3 << 4));	\
	ath_reg_rmw_set(mii_reg(_mac), ((_spd) << 4));	\
} while (0)

#if defined (CFG_MII0_GMII)
#define ath_get_mii_if()		0
#elif defined (CFG_MII0_MII)
#define ath_get_mii_if()		0
#elif defined (CFG_MII0_RGMII)
#define ath_get_mii_if()		0
#elif defined (CFG_MII0_RMII)
#define ath_get_mii_if()		0
#endif

#define MAX_WAIT			1000

/*
 * Config/Mac Register definitions
 */
#define ATH_MAC_CFG1			0x00
#define ATH_MAC_CFG2			0x04
#define ATH_MAC_IFCTL			0x38

/*
 * fifo control registers
 */
#define ATH_MAC_FIFO_CFG_0		0x48
#define ATH_MAC_FIFO_CFG_1		0x4c
#define ATH_MAC_FIFO_CFG_2		0x50
#define ATH_MAC_FIFO_CFG_3		0x54
#define ATH_MAC_FIFO_CFG_4		0x58
#define ATH_MAC_FIFO_CFG_5		0x5c
#define ATH_BYTE_PER_CLK_EN		(1 << 19)

#define ATH_MAC_FIFO_RAM_0		0x60
#define ATH_MAC_FIFO_RAM_1		0x64
#define ATH_MAC_FIFO_RAM_2		0x68
#define ATH_MAC_FIFO_RAM_3		0x6c
#define ATH_MAC_FIFO_RAM_4		0x70
#define ATH_MAC_FIFO_RAM_5		0x74
#define ATH_MAC_FIFO_RAM_6		0x78
#define ATH_MAC_FIFO_RAM_7		0x7c

/*
 * fields
 */
#define ATH_MAC_CFG1_SOFT_RST		(1 << 31)
#define ATH_MAC_CFG1_LOOPBACK		(1 << 8)
#define ATH_MAC_CFG1_RX_EN		(1 << 2)
#define ATH_MAC_CFG1_TX_EN		(1 << 0)

#define ATH_MAC_CFG2_FDX		(1 << 0)
#define ATH_MAC_CFG2_PAD_CRC_EN		(1 << 2)
#define ATH_MAC_CFG2_LEN_CHECK		(1 << 4)
#define ATH_MAC_CFG2_HUGE_FRAME_EN	(1 << 5)
#define ATH_MAC_CFG2_IF_1000		(1 << 9)
#define ATH_MAC_CFG2_IF_10_100		(1 << 8)

#define ATH_MAC_IFCTL_SPEED		(1 << 16)

/*
 * DMA (tx/rx) register defines
 */
#define ATH_DMA_TX_CTRL			0x180
#define ATH_DMA_TX_DESC			0x184
#define ATH_DMA_TX_STATUS		0x188
#define ATH_DMA_RX_CTRL			0x18c
#define ATH_DMA_RX_DESC			0x190
#define ATH_DMA_RX_STATUS		0x194
#define ATH_DMA_INTR_MASK		0x198
#define ATH_DMA_INTR			0x19c

/*
 * tx/rx ctrl and status bits
 */
#define ATH_TXE				(1 << 0)
#define ATH_TX_STATUS_PKTCNT_SHIFT	16
#define ATH_TX_STATUS_PKT_SENT		0x1
#define ATH_TX_STATUS_URN		0x2
#define ATH_TX_STATUS_BUS_ERROR		0x8

#define ATH_RXE				(1 << 0)

#define ATH_RX_STATUS_PKTCNT_MASK	0xff0000
#define ATH_RX_STATUS_PKT_RCVD		(1 << 0)
#define ATH_RX_STATUS_OVF		(1 << 2)
#define ATH_RX_STATUS_BUS_ERROR		(1 << 3)

/*
 * Int and int mask
 */
#define ATH_INTR_TX			(1 << 0)
#define ATH_INTR_TX_URN			(1 << 1)
#define ATH_INTR_TX_BUS_ERROR		(1 << 3)
#define ATH_INTR_RX			(1 << 4)
#define ATH_INTR_RX_OVF			(1 << 6)
#define ATH_INTR_RX_BUS_ERROR		(1 << 7)

/*
 * MII registers
 */
#define ATH_MAC_MII_MGMT_CFG		0x20
#define ATH_MGMT_CFG_CLK_DIV_20		0x07

#define ATH_MII_MGMT_CMD		0x24
#define ATH_MGMT_CMD_READ		0x1

#define ATH_MII_MGMT_ADDRESS		0x28
#define ATH_ADDR_SHIFT			8

#define ATH_MII_MGMT_CTRL		0x2c
#define ATH_MII_MGMT_STATUS		0x30

#define ATH_MII_MGMT_IND		0x34
#define ATH_MGMT_IND_BUSY		(1 << 0)
#define ATH_MGMT_IND_INVALID		(1 << 2)

#define ATH_GE_MAC_ADDR1		0x40
#define ATH_GE_MAC_ADDR2		0x44

/*
 * ownership of descriptors between DMA and cpu
 */
#define ath_gmac_rx_owned_by_dma(_ds)	((_ds)->is_empty == 1)
#define ath_gmac_rx_give_to_dma(_ds)	((_ds)->is_empty = 1)
#define ath_gmac_tx_owned_by_dma(_ds)	((_ds)->is_empty == 0)
#define ath_gmac_tx_give_to_dma(_ds)	((_ds)->is_empty = 0)
#define ath_gmac_tx_own(_ds)		((_ds)->is_empty = 1)

/*
 * link settings
 */
#define ath_set_mac_duplex(_mac, _fdx)	do {					\
	if ((_fdx))								\
		ath_gmac_reg_rmw_set(_mac, ATH_MAC_CFG2, ATH_MAC_CFG2_FDX)	\
	else									\
		ath_gmac_reg_rmw_clear(_mac, ATH_MAC_CFG2, ATH_MAC_CFG2_FDX)	\
} while (0)

#define ath_set_mac_if(_mac, _isXGMII)	do {			\
	ath_gmac_reg_rmw_clear(_mac, ATH_MAC_CFG2,		\
				ATH_MAC_CFG2_IF_1000 |		\
				ATH_MAC_CFG2_IF_10_100);	\
	if ((_isXGMII)) {					\
		ath_gmac_reg_rmw_set(_mac, ATH_MAC_CFG2,	\
				ATH_MAC_CFG2_IF_1000);		\
		ath_gmac_reg_rmw_set(_mac, ATH_MAC_FIFO_CFG_5,	\
				ATH_BYTE_PER_CLK_EN);		\
	} else {						\
		ath_gmac_reg_rmw_set(_mac, ATH_MAC_CFG2,	\
				ATH_MAC_CFG2_IF_10_100);	\
		ath_gmac_reg_rmw_clear(_mac, ATH_MAC_FIFO_CFG_5,\
				ATH_BYTE_PER_CLK_EN);		\
	}							\
} while (0)

#define ath_set_mac_speed(_mac, _is100)	do {			\
	if ((_is100))						\
		ath_gmac_reg_rmw_set(_mac, ATH_MAC_IFCTL,	\
				ATH_MAC_IFCTL_SPEED)		\
	else							\
		ath_gmac_reg_rmw_clear(_mac, ATH_MAC_IFCTL,	\
				ATH_MAC_IFCTL_SPEED)		\
} while (0)

#endif
