/*
 * AQ105 PHY driver header file
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

#ifndef AQ_PHY_H
#define AQ_PHY_H

/* AQ PHY stats register format structure */
struct aq_stats_reg {
	uint32_t regaddr_lsw;	/* Stats reg address, lower 16-Bit */
	uint32_t regaddr_msw;	/* Stats reg address, Upper 16-Bit */
	uint32_t regval;	/* Register Value */
};

/* AQ PHY stats structure */
struct aq_stats {
	struct aq_stats_reg line_tx_good; /* Line side good packets TXed */
	struct aq_stats_reg line_tx_bad;  /* Line side bad packets TXed */
	struct aq_stats_reg line_rx_good; /* Line side good packets RXed */
	struct aq_stats_reg line_rx_bad;  /* Line side bad packets RXed */
	struct aq_stats_reg sys_tx_good;  /* Sys side good packets TXed */
	struct aq_stats_reg sys_tx_bad;   /* Sys side bad packets TXed */
	struct aq_stats_reg sys_rx_good;  /* Sys side good packets RXed */
	struct aq_stats_reg sys_rx_bad;   /* Sys side bad packets RXed */
};

/* Board specific data structure */
struct aq_phy_platform_data {
	uint16_t phy_addr;		/* AQ PHY Address */
	uint32_t mdio_bus_id;		/* MDIO Bus number where AQ
					   PHY is connected */
	char *mdio_bus_name;		/* MDIO bus name */
};

/* AQ Phy Stats Registers addresses */
#define AQ_LINE_SIDE_TX_GOOD_REG_LSW  0X3C820
#define AQ_LINE_SIDE_TX_GOOD_REG_MSW  0X3C821
#define AQ_LINE_SIDE_TX_BAD_REG_LSW  0X3C822
#define AQ_LINE_SIDE_TX_BAD_REG_MSW  0X3C823

#define AQ_LINE_SIDE_RX_GOOD_REG_LSW  0X3E812
#define AQ_LINE_SIDE_RX_GOOD_REG_MSW  0X3E813
#define AQ_LINE_SIDE_RX_BAD_REG_LSW  0X3E814
#define AQ_LINE_SIDE_RX_BAD_REG_MSW  0X3E815

#define AQ_SYS_SIDE_TX_GOOD_REG_LSW  0X1DD303
#define AQ_SYS_SIDE_TX_GOOD_REG_MSW  0X1DD304
#define AQ_SYS_SIDE_TX_BAD_REG_LSW  0X1DD305
#define AQ_SYS_SIDE_TX_BAD_REG_MSW  0X1DD306

#define AQ_SYS_SIDE_RX_GOOD_REG_LSW  0X1DD282
#define AQ_SYS_SIDE_RX_GOOD_REG_MSW  0X1DD283
#define AQ_SYS_SIDE_RX_BAD_REG_LSW  0X1DD284
#define AQ_SYS_SIDE_RX_BAD_REG_MSW  0X1DD285

/*
 * The AQ device mask and ID. The last four bits comprise
 * the revision ID, while the rest of the bits comprise
 * the organization ID and the model ID
 */
#define AQ_DEVICE_ID_MASK 0xFFFFFFF0
#define AQ_DEVICE_ID 0x03a1b4a0

/* PMD Line side Rx signal detect register */
#define AQ_PHY_PMD_SIGNAL_DETECT_REG	0xa

/* Mask and Bit definition for AQ_PHY_PMD_SIGNAL_DETECT_REG */
#define AQ_PHY_PMD_SIGNAL_DETECT_MASK	0x1

/* Autonegotiation Vendor Status register */
#define AQ_PHY_LINK_REG		0xC800

/* Mask and Bit definition for AQ_PHY_LINK_REG */
#define AQ_PHY_LINK_DUPLEX_MASK	0x1
#define AQ_PHY_LINK_SPEED_10000	0x3
#define AQ_PHY_LINK_SPEED_5000	0x5
#define AQ_PHY_LINK_SPEED_2500	0x4
#define AQ_PHY_LINK_SPEED_1000	0x2
#define AQ_PHY_LINK_SPEED_100	0x1
#define AQ_PHY_LINK_SPEED_10	0x0

/* Line side link status register */
#define AQ_PHY_PMA_RX_LINK_CURRENT_STATUS_REG	0xE800

/* Mask and Bit definition for AQ_PHY_PMA_RX_LINK_CURRENT_STATUS_REG */
#define AQ_PHY_PMA_RX_LINK_CURRENT_STATUS_MASK	0x1

/* PMA reg to check FW is loaded properly and PHY is out of reset */
#define AQ_PHY_PMA_STANDARD_CTRL_1_REG	0

/* Mask and Bit definition for AQ_PHY_PMA_STANDARD_CTRL_1_REG */
#define AQ_PHY_PMA_STANDARD_CTRL_1_MASK	0x8000

/*
 * Maximum string length:
 * This should be equal to maximum string size of any stats
 * inclusive of stats value
 */
#define AQ_PHY_STATS_MAX_STR_LENGTH 50

/* Maximum number of lines to be printed at console device */
#define AQ_PHY_STATS_MAX_OUTPUT_LINE 10

#endif /*AQ_PHY_H */
