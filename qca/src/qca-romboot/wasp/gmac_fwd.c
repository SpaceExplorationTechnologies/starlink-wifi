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

//#include <common.h>
//#include <malloc.h>
//#include <net.h>
#include "asm/addrspace.h"
#include "asm/types.h"
#include "fwd.h"
#include <ar934x_soc.h>
#include "ag7240.h"
#include "gmac_fwd.h"
#include "rom.addrs.h"
//#include "ag7240_phy.h"
//#include <hornet_api.h>


#define here()		hh(__FILE__, __LINE__)
#define hh(a, b)	serial_puts(a ## b ## "\n")

#define ag7240_unit2mac(_unit)     ag7240_macs[(_unit)]
#define ag7240_name2mac(name)	   strcmp(name,"eth0") ? ag7240_unit2mac(1) : ag7240_unit2mac(0)

#define PKT_ALIGN 32

fwd_tgt_softc_t fwd_sc;

__gmac_params_t gmac_params = { {0} };

/*********************************GMAC softC************************/

typedef struct __gmac_softc {
	__gmac_hdr_t hdr;
	a_uint16_t gran;
} __gmac_softc_t;

/***********************************Globals********************************/
/**
 * @brief Engines are fixed
 */
__gmac_softc_t gmac_sc = {
	.gran = GMAC_MAX_PKT_LEN
};
a_uint8_t gmac_addr[ETH_ALEN]	= { 0x00, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa };
a_uint8_t bcast_addr[ETH_ALEN]	= { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

/*********************************DEFINES**********************************/
#define __gmac_mdelay(_msecs)   udelay((_msecs) * 1000)

void fwd_tgt_recv(ag7240_mac_t * mac, a_uint8_t * rxbuf, int datalen);

void
mdio_release_lock(unsigned char extra_flags)
{
	mii_reg_write_32(MDIO_REG_TO_OFFSET(mdio_lock_reg),
			 (extra_flags << 8) | MDIO_OWN_HST);
}

int
mdio_read_block(unsigned char *ptr, int len)
{
	a_uint16_t val;
	int j = 0, next_read_reg = 1;

	for (j = 0; j < len;) {
		val = mii_reg_read_32(MDIO_REG_TO_OFFSET(next_read_reg));
		//A_PRINTF("mdio_read_block, -RD- %x- %x\n", next_read_reg, val);
		if ((j == len - 1) && (len % 2)) {
			/* last odd word */
			ptr[j] = (val & 0x00ff);
		} else {
			ptr[j] = (val & 0xff00) >> 8;
			ptr[j + 1] = (val & 0x00ff);
		}
		j += 2;
		next_read_reg += 1;
	}
	return 0;
}

int mdio_wait_for_lock(void)
{
	volatile a_uint16_t val;

	val = mii_reg_read_32(MDIO_REG_TO_OFFSET(mdio_lock_reg));
	while (!(val & MDIO_OWN_TGT)) {
		val = mii_reg_read_32(MDIO_REG_TO_OFFSET(mdio_lock_reg));
	}
	//A_PRINTF("mdio_wait_for_lock - len %x %x\n", val);
	return ((val & 0xff00) >> 8);

}

int mdio_copy_bytes(unsigned char *to, int length)
{
	int cwindex = 0;
	int ilen = 0;

	while (cwindex < length) {
		ilen = mdio_wait_for_lock();
		//A_PRINTF("Bytes to read %d\n", ilen);
		mdio_read_block(to + cwindex, ilen);
		cwindex += ilen;
		mdio_release_lock(0);
	}
	return cwindex;
}

/**
 * memcpy - Copy one area of memory to another
 * @dest: Where to copy to
 * @src: Where to copy from
 * @count: The size of the area.
 *
 * You should not use this function to access IO space, use memcpy_toio()
 * or memcpy_fromio() instead.
 */
static void *memcpy(void *dest, const void *src, int count)
{
	char *tmp = (char *)dest, *s = (char *)src;

	while (count--)
		*tmp++ = *s++;

	return dest;
}

/**
 * memset - Fill a region of memory with the given value
 * @s: Pointer to the start of the area.
 * @c: The byte to fill the area with
 * @count: The size of the area.
 *
 * Do not use memset() to access IO space, use memset_io() instead.
 */
static void *memset(void *s, int c, int count)
{
	char *xs = (char *)s;

	while (count--)
		*xs++ = c;

	return s;
}

void
gmac_rom_read_mac(a_uint8_t mac_addr[])
{
	memcpy(mac_addr, gmac_addr, ETH_ALEN);
}

void
__gmac_prep_ethhdr(__gmac_hdr_t * hdr, a_uint8_t * dst)
{
	memcpy(hdr->eth.dst, dst, ETH_ALEN);
	hdr->eth.etype = ETH_P_ATH;
}

a_bool_t
__is_ath_header(__gmac_softc_t * sc, a_uint8_t * buf)
{
	__gmac_hdr_t *hdr = gmac_hdr(buf);

	if (hdr->ath.proto != sc->hdr.ath.proto)
		return A_FALSE;

	return A_TRUE;
}

#define MAX_TX_PKT_SIZE		64
#define MAX_RX_PKT_SIZE		1536             /* for vlc fix */
#define MAX_TX_PKTS 1
#define MAX_RX_PKTS 2

volatile a_uint8_t *NetRxPackets[MAX_RX_PKTS];	/* Receive packets */
volatile a_uint8_t *NetTxPackets[MAX_TX_PKTS];	/* Receive packets */

a_uint16_t ag7240_miiphy_read(char *, a_uint32_t, a_uint8_t);
void ag7240_miiphy_write(char *, a_uint32_t, a_uint8_t, a_uint16_t);

ag7240_mac_t ag7240_mac;

extern int athrs26_phy_setup(int unit);
extern int athrs26_phy_is_up(int unit);
extern int athrs26_phy_is_fdx(int unit);
extern int athrs26_phy_speed(int unit);
extern void athrs26_reg_init(void);
extern void athrs26_reg_init_lan(void);
extern int athrs26_mdc_check(void);

static int
ag7240_send(ag7240_mac_t * mac, volatile void *packet, int length)
{
	//int i;

	ag7240_desc_t *f = &mac->fifo_tx[mac->next_tx];

	f->pkt_size = length;
	f->res1 = 0;
	f->pkt_start_addr = PHYSADDR(packet);

	ag7240_tx_give_to_dma(f);
#if 0
	flush_cache((u32) packet, length);
#endif
	ag7240_reg_wr(mac, AG7240_DMA_TX_DESC, PHYSADDR(f));
	ag7240_reg_wr(mac, AG7240_DMA_TX_CTRL, AG7240_TXE);

#if 0
	for (i = 0; i < MAX_WAIT; i++) {
		udelay(10);
		if (!ag7240_tx_owned_by_dma(f))
			break;
	}
	if (i == MAX_WAIT)
		printf("Tx Timed out\n");
	f->pkt_start_addr = 0;
	f->pkt_size = 0;
#else
	while (ag7240_tx_owned_by_dma(f))
		printf(".");

	printf("*");
#endif


	if (++mac->next_tx >= MAX_TX_PKTS)
		mac->next_tx = 0;

	return (0);
}

static int ag7240_fwd_recv(ag7240_mac_t * mac)
{
	int length;
	ag7240_desc_t *f;
	__gmac_softc_t *sc = &gmac_sc;
#if 0
	ag7240_mac_t *mac;

	mac = (ag7240_mac_t *) dev->priv;
#endif

	for (;;) {
		f = &mac->fifo_rx[mac->next_rx];
		if (ag7240_rx_owned_by_dma(f))
			break;

		length = f->pkt_size;

		if (__is_ath_header
		    (sc, (a_uint8_t *) NetRxPackets[mac->next_rx])) {
			fwd_tgt_recv(mac,
				     (a_uint8_t *) (NetRxPackets[mac->next_rx] +
						    GMAC_HLEN),
				     (length - GMAC_HLEN - 4));
		}
#if 0
		flush_cache((u32) NetRxPackets[mac->next_rx], PKTSIZE_ALIGN);
#endif

		ag7240_rx_give_to_dma(f);

		if (++mac->next_rx >= MAX_RX_PKTS)
			mac->next_rx = 0;
	}

	if (!(ag7240_reg_rd(mac, AG7240_DMA_RX_CTRL))) {
		ag7240_reg_wr(mac, AG7240_DMA_RX_DESC, PHYSADDR(f));
		ag7240_reg_wr(mac, AG7240_DMA_RX_CTRL, 1);
	}

	return (0);
}

static void ag7240_hw_start(ag7240_mac_t * mac)
{
#if 0
	u32 mask;

	ar7240_reg_wr(0xb804006c,0x2);

	mask = ar7240_reg_rd(0xb8040030);
	ar7240_reg_wr(0xb8040030, (mask & ~(0xff << 16)));

	mask = ar7240_reg_rd(0x18040000);
	ar7240_reg_wr(0x18040000, (mask | 0x4));

	mask = ar7240_reg_rd(0x18040008);
	ar7240_reg_wr(0x18040008, mask | 0x4);
	__gmac_mdelay(10);
	ar7240_reg_wr(0x18040008, mask & ~(0x4));

	printf("Ethernet DCM out of reset\n");
#endif
#if ROMBOOTDRV_SUPPORT_GMAC_1000M

	ag7240_reg_wr(mac, AG7240_MAC_CFG2, 0x7215);   //Enable MII/GMII Interface  (1000 mbps) ..Full duplex

	ag7240_reg_wr(mac, AG7240_MAC_IFCTL, 0x00000);

	ag7240_reg_wr(mac, AG7240_MAC_CFG1, 0x0000003f);   // for 1000 mbps mode

	ag7240_reg_wr(mac, AG7240_GE_MAC_ADDR1, 0xAAAAAAAA); //ethernet mac address
	ag7240_reg_wr(mac, AG7240_GE_MAC_ADDR2, 0xAAAA0000); //ethernet mac address

	ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, 0x6);

	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_0, 0x001d1f00); // Enable the FIFO modules

	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_1, 0x10ffff);
	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_2, 0x015500aa); /*for 1000 mbps mode */
	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_3, 0x1f00140);

	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_4, 0x3ffff); /*for 1000 mbps */

    //ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_5, 0xe6b82); /*for 1000 mbps mode */
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_5, 0xe6082); /*for bdcast multicast fix */

    ar7240_reg_wr(AR7240_MII0_CTRL, 0x000c0001); /*for 1000 mbps mode */

    ar7240_reg_wr(AR934X_ETH_XMII, 0x86000000);          /*For 1000 mbps */
#else

	ag7240_reg_wr(mac, AG7240_MAC_CFG2, 0x7135);   //Enable MII/GMII Interface  (10 -> MII) ..Full duplex

	ag7240_reg_wr(mac, AG7240_MAC_IFCTL, 0x00000);

	// ag7240_reg_wr(mac, GE0_MAC_CONFIG_1,0x105);   // Transmit & receive Enable, 8th bit for Loopback enable
	ag7240_reg_wr(mac, AG7240_MAC_CFG1, 0x5);   // Transmit & receive Enable, 8th bit for Loopback enable

	ag7240_reg_wr(mac, AG7240_GE_MAC_ADDR1, 0xAAAAAAAA); //ethernet mac address
	ag7240_reg_wr(mac, AG7240_GE_MAC_ADDR2, 0xAAAA0000); //ethernet mac address

	ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, 0x7);

	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_0, 0x1f00); // Enable the FIFO modules
	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_1, 0x10ffff);
	// --	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_2, 0x015500aa);
	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_3, 0x1f00140);
	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_4, 0x1010);
	// --	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_4, 0x3ffff);
	// ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_5, 0xbefef);
	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_5, 0xbefff);
	// --	ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_5, 0x66b82);

	ar7240_reg_wr(AR7240_MII0_CTRL, 1);

	ar7240_reg_wr(AR934X_ETH_XMII, (1 << 31) | (3 << 28)| 0x0101);
#endif
}

#if 0
static int ag7240_check_link(ag7240_mac_t * mac)
{
	u32 link, duplex, speed, fdx;

	ag7240_phy_link(mac->mac_unit, &link);
	ag7240_phy_duplex(mac->mac_unit, &duplex);
	ag7240_phy_speed(mac->mac_unit, &speed);

	mac->link = link;
	if (!mac->link) {
		printf("%s link down\n", mac->dev->name);
		return 0;
	}

	switch (speed) {
	case _1000BASET:
		ag7240_set_mac_if(mac, 1);
		ag7240_reg_rmw_set(mac, AG7240_MAC_FIFO_CFG_5, (1 << 19));
		if (is_ar7242() && (mac->mac_unit == 0)) {
			ar7240_reg_wr(AR7242_ETH_XMII_CONFIG, 0x1c000000);
		}
		break;

	case _100BASET:
		ag7240_set_mac_if(mac, 0);
		ag7240_set_mac_speed(mac, 1);
		ag7240_reg_rmw_clear(mac, AG7240_MAC_FIFO_CFG_5, (1 << 19));
		if (is_ar7242() && (mac->mac_unit == 0))
			ar7240_reg_wr(AR7242_ETH_XMII_CONFIG, 0x0101);
		break;

	case _10BASET:
		ag7240_set_mac_if(mac, 0);
		ag7240_set_mac_speed(mac, 0);
		ag7240_reg_rmw_clear(mac, AG7240_MAC_FIFO_CFG_5, (1 << 19));
		if (is_ar7242() && (mac->mac_unit == 0))
			ar7240_reg_wr(AR7242_ETH_XMII_CONFIG, 0x1616);
		break;

	default:
		printf("Invalid speed detected\n");
		return 0;
	}

	if (mac->link && (duplex == mac->duplex) && (speed == mac->speed))
		return 1;

	mac->duplex = duplex;
	mac->speed = speed;

	printf("dup %d speed %d\n", duplex, speed);

	ag7240_set_mac_duplex(mac, duplex);

	return 1;
}
#endif

/*
 * For every command we re-setup the ring and start with clean h/w rx state
 */
static int ag7240_clean_rx(ag7240_mac_t * mac)
{

	int i;
	ag7240_desc_t *fr;

#if 0
	if (!ag7240_check_link(mac))
		return 0;
#endif

	mac->next_rx = 0;
	for (i = 0; i < MAX_RX_PKTS; i++) {
		fr = &mac->fifo_rx[i];
		fr->pkt_start_addr = PHYSADDR(NetRxPackets[i]);
#if 0
		flush_cache((u32) NetRxPackets[i], MAX_PKT_SIZE);
#endif
		ag7240_rx_give_to_dma(fr);
	}

	ag7240_reg_wr(mac, AG7240_DMA_RX_DESC, PHYSADDR(&mac->fifo_rx[0]));
	ag7240_reg_wr(mac, AG7240_DMA_RX_CTRL, AG7240_RXE);	/* rx start */
	udelay(1000 * 1000);

	return 1;

}

ag7240_desc_t gmac_txfifo[MAX_TX_PKTS];
ag7240_desc_t gmac_rxfifo[MAX_RX_PKTS];

static int ag7240_setup_fifos(ag7240_mac_t * mac)
{
	int i;

	for (i = 0; i < MAX_TX_PKTS; i++) {
		mac->fifo_tx[i].next_desc = (i == MAX_TX_PKTS - 1) ?
		    PHYSADDR(&mac->fifo_tx[0]) : PHYSADDR(&mac->fifo_tx[i + 1]);
		ag7240_tx_own(&mac->fifo_tx[i]);
	}

	for (i = 0; i < MAX_RX_PKTS; i++) {
		mac->fifo_rx[i].next_desc = (i == MAX_RX_PKTS - 1) ?
		    PHYSADDR(&mac->fifo_rx[0]) : PHYSADDR(&mac->fifo_rx[i + 1]);
	}

	return (1);
}

static void ag7240_halt(ag7240_mac_t * mac)
{
	ag7240_reg_wr(mac, AG7240_DMA_RX_CTRL, 0);
	while (ag7240_reg_rd(mac, AG7240_DMA_RX_CTRL)) ;
}

#if 0
unsigned char *
ag7240_mac_addr_loc(void)
{
#ifdef BOARDCAL
	/*
	 ** BOARDCAL environmental variable has the address of the cal sector
	 */

	return ((unsigned char *)BOARDCAL);

#else
	extern flash_info_t flash_info[];

	/* MAC address is store in the 2nd 4k of last sector */
	return ((unsigned char *)
		(KSEG1ADDR(AR7240_SPI_BASE) + (4 * 1024) +
		 flash_info[0].size - (64 * 1024) /* sector_size */ ));
#endif
}

static void ag7240_get_ethaddr(unsigned char *mac)
{
	unsigned char *eeprom;

	eeprom = ag7240_mac_addr_loc();

	memcpy(mac, eeprom, 6);

	/* Use fixed address if the above address is invalid */
	if (mac[0] != 0x00 || (mac[0] == 0xff && mac[5] == 0xff)) {
		mac[0] = 0x00;
		mac[1] = 0x03;
		mac[2] = 0x7f;
		mac[3] = 0x09;
		mac[4] = 0x0b;
		mac[5] = 0xad;
		printf("No valid address in Flash. Using fixed address\n");
	} else {
		printf("Fetching MAC Address from eeprom\n");
	}
}
#endif

int ag7240_gmac_initialize()
{
	u32 mac_h, mac_l, mask;
	a_uint8_t mac[6];

	printf("ag7240_gmac_initialize...\n");

#if 0
	if ((ag7240_mac =
	     (ag7240_mac_t *) malloc(sizeof(ag7240_mac_t))) == NULL) {
		puts("malloc failed\n");
		return 0;
	}
#endif

	memset(&ag7240_mac, 0, sizeof(ag7240_mac));

#if 0
	sprintf(dev[i]->name, "eth%d", i);
#endif
	gmac_rom_read_mac(mac);

	ag7240_mac.mac_unit = 0;
	ag7240_mac.mac_base = AR7240_GE0_BASE;

#if 0
	ag7240_mac.dev = dev[i];

	dev[i]->iobase = 0;
	dev[i]->init = ag7240_clean_rx;
	dev[i]->halt = ag7240_halt;
	dev[i]->send = ag7240_send;
	dev[i]->recv = ag7240_recv;
	dev[i]->priv = (void *)ag7240_macs[i];
#endif

	mask = (AR7240_RESET_GE0_MAC | AR7240_RESET_GE0_PHY |
		AR7240_RESET_GE1_MAC | AR7240_RESET_GE1_PHY);

	ar7240_reg_rmw_set(AR7240_RESET, mask);
	udelay(1000 * 100);

#if 1
	mask = (AR7240_RESET_GE0_PHY | AR7240_RESET_GE1_PHY ); //remove the switch analog and switch out of reset, this gives clocks to internal gmac modules
	ar7240_reg_rmw_clear(AR7240_RESET, mask);
	udelay(1000 * 100);
	mask = (AR7240_RESET_GE0_MAC | AR7240_RESET_GE1_MAC ); //remove mac out of reset, GE1 mac need not be removed out of reset, as we don't use it, but since the code is there I did not change it.
	                                                       //by doing above sequence we make sure reset propagates after clock is stable.
	ar7240_reg_rmw_clear(AR7240_RESET, mask);
	udelay(1000 * 100);
#else
	ar7240_reg_rmw_clear(AR7240_RESET, mask);
	udelay(1000 * 100);

	udelay(10 * 1000);
#endif

	ag7240_hw_start(&ag7240_mac);
	ag7240_setup_fifos(&ag7240_mac);

	udelay(100 * 1000);

#if 0
	printf("ge0: %02x:%02x:%02x:%02x:%02x:%02x\n",
	       mac[0] & 0xff, mac[1] & 0xff, mac[2] & 0xff,
	       mac[3] & 0xff, mac[4] & 0xff, mac[5] & 0xff);
#endif

	mac_h = (mac[4] << 24) | (mac[5] << 16);
	mac_l = (mac[0] << 24) | (mac[1] << 16) | (mac[2] << 8) | (mac[3] << 0);

	ag7240_reg_wr((&ag7240_mac), AG7240_GE_MAC_ADDR1, mac_l);
	ag7240_reg_wr((&ag7240_mac), AG7240_GE_MAC_ADDR2, mac_h);

#if 0
	/* if using header for register configuration, we have to     */
	/* configure s26 register after frame transmission is enabled */

	if (ag7240_mac.mac_unit == 0) {	/* WAN Phy */
#ifdef CONFIG_AR7242_S16_PHY
		if (is_ar7242()) {
			athrs16_reg_init();
		} else
#endif
		{
			athrs26_reg_init();
		}
	} else {
		athrs26_reg_init_lan();
	}

	ag7240_phy_setup(ag7240_macs[i]->mac_unit);
	printf("%s up\n", dev[i]->name);
#endif

	return 1;
}

#if 0				/* (CONFIG_COMMANDS & CFG_CMD_MII) */
a_uint16_t
ag7240_miiphy_read(char *devname, a_uint32_t phy_addr, a_uint8_t reg)
{
	ag7240_mac_t *mac = ag7240_name2mac(devname);
	a_uint16_t addr = (phy_addr << AG7240_ADDR_SHIFT) | reg, val;
	volatile int rddata;
	a_uint16_t ii = 0x1000;

	ag7240_reg_wr(mac, AG7240_MII_MGMT_CMD, 0x0);
	ag7240_reg_wr(mac, AG7240_MII_MGMT_ADDRESS, addr);
	ag7240_reg_wr(mac, AG7240_MII_MGMT_CMD, AG7240_MGMT_CMD_READ);

	do {
		udelay(5);
		rddata = ag7240_reg_rd(mac, AG7240_MII_MGMT_IND) & 0x1;
	} while (rddata && --ii);

	val = ag7240_reg_rd(mac, AG7240_MII_MGMT_STATUS);
	ag7240_reg_wr(mac, AG7240_MII_MGMT_CMD, 0x0);

	return val;
}

void
ag7240_miiphy_write(char *devname, a_uint32_t phy_addr, a_uint8_t reg,
		    uint16_t data)
{
	ag7240_mac_t *mac = ag7240_name2mac(devname);
	a_uint16_t addr = (phy_addr << AG7240_ADDR_SHIFT) | reg;
	volatile int rddata;
	a_uint16_t ii = 0x1000;

	ag7240_reg_wr(mac, AG7240_MII_MGMT_ADDRESS, addr);
	ag7240_reg_wr(mac, AG7240_MII_MGMT_CTRL, data);

	do {
		rddata = ag7240_reg_rd(mac, AG7240_MII_MGMT_IND) & 0x1;
	} while (rddata && --ii);
}
#endif /* CONFIG_COMMANDS & CFG_CMD_MII */

a_status_t
__gmac_process_discv(ag7240_mac_t * mac, __gmac_softc_t * sc)
{
	a_status_t err = A_STATUS_OK;
	__gmac_hdr_t *buf_hdr;
	a_uint8_t *buf;
	ag7240_desc_t *f;

	f = &mac->fifo_rx[mac->next_rx];

	printf("inside __gmac_process_discv\n");
#if 0
	vbuf = dma_lib_reap_recv(DMA_ENGINE_RX0);
#endif

	buf = (a_uint8_t *) NetRxPackets[mac->next_rx];

	if (!__is_ath_header(sc, buf)) {
		printf("__gmac_process_discv: dropping the frame \n");
		err = A_STATUS_FAILED;
		goto done;
	} else {
		printf("__gmac_process_discv: received bytes \n");
	}
	buf_hdr = gmac_hdr(buf);

	memcpy(sc->hdr.eth.dst, buf_hdr->eth.src, ETH_ALEN);
#if 0

	__gmac_vbuf_pull_head(vbuf, GMAC_HLEN);

    /**
     * Application should do the return_recv
     */
	sc->indicate_pkt(NULL, vbuf, sc->htc_ctx);
#endif

	fwd_tgt_recv(mac, buf + GMAC_HLEN, f->pkt_size - (GMAC_HLEN + 4));

done:
	ag7240_rx_give_to_dma(f);

	if (++mac->next_rx >= MAX_RX_PKTS)
		mac->next_rx = 0;

	return err;
}

static int ag7240_check_recv(ag7240_mac_t * mac)
{
	ag7240_desc_t *f;

	f = &mac->fifo_rx[mac->next_rx];
	if (ag7240_rx_owned_by_dma(f))
		return 0;

	return 1;
}

void
gmac_discover(ag7240_mac_t * mac)
{
	a_status_t err = A_STATUS_FAILED;
	a_uint8_t *buf;
	__gmac_softc_t *sc = &gmac_sc;

    /**
     * Get a packet
     */
	buf = (a_uint8_t *) NetTxPackets[0];

    /**
     * Prepare the broadcast packet
     */
	__gmac_prep_ethhdr(&sc->hdr, bcast_addr);
	memcpy(buf, &sc->hdr, sizeof(sc->hdr));

	while (1) {
		printf("sending discovery ...\n");
		if (buf)
			ag7240_send(mac, buf, GMAC_HLEN);

		__gmac_mdelay(GMAC_DISCV_WAIT);

#if 0
		if (dma_lib_xmit_done(DMA_ENGINE_TX0))
			buf = dma_lib_reap_xmitted(DMA_ENGINE_TX0);
#endif

		while (ag7240_check_recv(mac) && err)
			err = __gmac_process_discv(mac, sc);

		if (!err)
			break;
#ifdef ENABLE_MDIO_CODE
		//gmac_handle_phy_emulation();
#endif
	}

#if 0
	adf_os_assert(buf);
#endif
}

a_status_t
fwd_tgt_process_last(a_uint32_t size, a_uint32_t cksum)
{
	int i, checksum = 0;
	a_uint32_t *image = (a_uint32_t *) fwd_sc.addr;

	for (i = 0; i < size; i += 4, image++)
		checksum = checksum ^ *image;

	if (checksum == cksum){
		return A_STATUS_OK;
		printf("image checksum validation success.\n");
	}
	else{
		printf("ERROR: image checksum validation failed!!!!");
		printf("len:%d received checksum:0x%x calculated checksum:0x%x\n", 
								size, cksum, checksum);
		return A_STATUS_FAILED;
	}
}

void fwd_tgt_recv(ag7240_mac_t * mac, a_uint8_t * rxbuf, int datalen)
{
	volatile a_uint8_t *buf;
	a_uint32_t len, offset, i, more, eloc;
	volatile a_uint32_t *image, *daddr;
	volatile fwd_cmd_t *c;
	volatile fwd_rsp_t *r;
	a_status_t status;
	__gmac_softc_t *sc = &gmac_sc;

	c = (fwd_cmd_t *) rxbuf;
	len = c->len;
	offset = c->offset;
	more = c->more_data;
	eloc = 0;
	image = (a_uint32_t *) (c + 1);
	status = 0;

	if (offset == 0) {
		printf("\nnew image loading started at address %x\n",
						(a_uint32_t) (*image));
		fwd_sc.addr = (a_uint32_t) (*image);
		image++;
	}

	daddr = (a_uint32_t *) (fwd_sc.addr + offset);

	if (!more) {
		len -= 4;
	}

	for (i = 0; i < len; i += 4) {
		*daddr = *image;
		image++;
		daddr++;
	}

#if 0
	desc = buf->desc_list;
	while (desc->next_desc != NULL)
		desc = desc->next_desc;
	desc->data_size -= seglen;
	buf->buf_length -= seglen;

	r = (fwd_rsp_t *) (desc->buf_addr + desc->data_offset +
			   desc->data_size);
	desc->data_size += sizeof(fwd_rsp_t);
	buf->buf_length += sizeof(fwd_rsp_t);
#endif
	/*
	 * Get a packet for sending response
	 */
	buf = (a_uint8_t *) NetTxPackets[0];

	memcpy((a_uint8_t *) buf, (a_uint8_t *) & sc->hdr, sizeof(sc->hdr));

	r = (fwd_rsp_t *) (buf + GMAC_HLEN);

	r->offset = c->offset;

	if (more) {
		r->rsp = FWD_RSP_ACK;
		goto done;
	}

	status = fwd_tgt_process_last(offset + len, *image);

	/* At the end, Also write CRC to memory. useful to validate DRAM data integrity */
	*daddr = *image;
	daddr++;
	image++;
	/* reach to the jump location */
	eloc = *image;

	if (status == A_STATUS_OK)
		r->rsp = FWD_RSP_SUCCESS;
	else
		r->rsp = FWD_RSP_FAILED;

done:
#if 0
	HIF_send_buffer(fwd_sc.hif_handle, fwd_sc.tx_pipe, buf);
#endif

	ag7240_send(mac, buf, GMAC_HLEN + sizeof(fwd_rsp_t));

	ag7240_halt(mac);

	if (!more && (status == A_STATUS_OK)) {
		printf("\nimage receive completed.\n");
		if(eloc == 0) {
			/*
			 * eloc(execution address) is 0 means this is some data 
			 * and CPU should not jump to the requested Address
			 */
			printf("\nThe last image received is not executable..");
			printf("Waiting to receive next image...\n");
		}
		else {
			/*
			 * Disable all interrupts. Else, kernel might get interrupts
			 * from here, before the driver is up and panic
			 */
			ag7240_reg_wr(mac, AG7240_DMA_INTR_MASK, 0);
			/* Restore gpio state */
			ar7240_reg_wr(0xb8040000, 0x0022f30b);
			printf("Calling 2nd stage\n");
			call_fw(1, eloc);
		}
	}
}

a_uint8_t gmac_rxbuf[MAX_RX_PKTS * MAX_RX_PKT_SIZE];
a_uint8_t gmac_txbuf[MAX_TX_PKTS * MAX_TX_PKT_SIZE];

void gmac_fwd_main()
{
	__gmac_softc_t *sc = &gmac_sc;
	int i;
#if 0
	a_uint8_t *rxbuf = malloc(MAX_RX_PKTS * MAX_PKT_SIZE);
	a_uint8_t *txbuf = malloc(MAX_TX_PKTS * MAX_PKT_SIZE);
#endif

	sc->hdr.ath.proto = ATH_P_BOOT;

	for (i = 0; i < MAX_RX_PKTS; i++) {
		NetRxPackets[i] =
		    (a_uint8_t
		     *) ((unsigned long)((gmac_rxbuf + i * MAX_RX_PKT_SIZE) +
					 PKT_ALIGN - 1) & ~(PKT_ALIGN - 1));
	}

	for (i = 0; i < MAX_TX_PKTS; i++) {
		NetTxPackets[i] =
		    (a_uint8_t
		     *) ((unsigned long)((gmac_txbuf + i * MAX_TX_PKT_SIZE) +
					 PKT_ALIGN - 1) & ~(PKT_ALIGN - 1));
	}

	/* Not using these parameters yet */
	printf("Receiving gmac params \n");
	mdio_release_lock(0);
	mdio_copy_bytes((unsigned char *)&gmac_params,
			sizeof(struct __gmac_params));

	ag7240_gmac_initialize();

	gmac_rom_read_mac(sc->hdr.eth.src);

	ag7240_clean_rx(&ag7240_mac);

	gmac_discover(&ag7240_mac);

	while (1) {
		ag7240_fwd_recv(&ag7240_mac);
	}
}
