/*
 * Copyright (c) 2013, 2016 The Linux Foundation. All rights reserved.
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

#include <asm/addrspace.h>
#include <asm/types.h>
#include <fwd.h>
#include <apb_map.h>
#include <ath_mac.h>
#include <ath_chip.h>
#include <gmac_fwd.h>
#include <rom.addrs.h>

#define SGMII_LINK_WAR_MAX_TRY 10
#define SGMII_DEBUG_ADDRESS                                          0x18070058
#define MR_AN_CONTROL_PHY_RESET_MSB                                  15
#define MR_AN_CONTROL_PHY_RESET_LSB                                  15
#define MR_AN_CONTROL_PHY_RESET_MASK                                 0x00008000
#define MR_AN_CONTROL_PHY_RESET_GET(x)                               (((x) & MR_AN_CONTROL_PHY_RESET_MASK) >> MR_AN_CONTROL_PHY_RESET_LSB)
#define MR_AN_CONTROL_PHY_RESET_SET(x)                               (((x) << MR_AN_CONTROL_PHY_RESET_LSB) & MR_AN_CONTROL_PHY_RESET_MASK)
#define MR_AN_CONTROL_PHY_RESET_RESET                                0x0 // 0
#define MR_AN_CONTROL_LOOPBACK_MSB                                   14
#define MR_AN_CONTROL_LOOPBACK_LSB                                   14
#define MR_AN_CONTROL_LOOPBACK_MASK                                  0x00004000
#define MR_AN_CONTROL_LOOPBACK_GET(x)                                (((x) & MR_AN_CONTROL_LOOPBACK_MASK) >> MR_AN_CONTROL_LOOPBACK_LSB)
#define MR_AN_CONTROL_LOOPBACK_SET(x)                                (((x) << MR_AN_CONTROL_LOOPBACK_LSB) & MR_AN_CONTROL_LOOPBACK_MASK)
#define MR_AN_CONTROL_LOOPBACK_RESET                                 0x0 // 0
#define MR_AN_CONTROL_SPEED_SEL0_MSB                                 13
#define MR_AN_CONTROL_SPEED_SEL0_LSB                                 13
#define MR_AN_CONTROL_SPEED_SEL0_MASK                                0x00002000
#define MR_AN_CONTROL_SPEED_SEL0_GET(x)                              (((x) & MR_AN_CONTROL_SPEED_SEL0_MASK) >> MR_AN_CONTROL_SPEED_SEL0_LSB)
#define MR_AN_CONTROL_SPEED_SEL0_SET(x)                              (((x) << MR_AN_CONTROL_SPEED_SEL0_LSB) & MR_AN_CONTROL_SPEED_SEL0_MASK)
#define MR_AN_CONTROL_SPEED_SEL0_RESET                               0x0 // 0
#define MR_AN_CONTROL_AN_ENABLE_MSB                                  12
#define MR_AN_CONTROL_AN_ENABLE_LSB                                  12
#define MR_AN_CONTROL_AN_ENABLE_MASK                                 0x00001000
#define MR_AN_CONTROL_AN_ENABLE_GET(x)                               (((x) & MR_AN_CONTROL_AN_ENABLE_MASK) >> MR_AN_CONTROL_AN_ENABLE_LSB)
#define MR_AN_CONTROL_AN_ENABLE_SET(x)                               (((x) << MR_AN_CONTROL_AN_ENABLE_LSB) & MR_AN_CONTROL_AN_ENABLE_MASK)
#define MR_AN_CONTROL_AN_ENABLE_RESET                                0x1 // 1
#define MR_AN_CONTROL_POWER_DOWN_MSB                                 11
#define MR_AN_CONTROL_POWER_DOWN_LSB                                 11
#define MR_AN_CONTROL_POWER_DOWN_MASK                                0x00000800
#define MR_AN_CONTROL_POWER_DOWN_GET(x)                              (((x) & MR_AN_CONTROL_POWER_DOWN_MASK) >> MR_AN_CONTROL_POWER_DOWN_LSB)
#define MR_AN_CONTROL_POWER_DOWN_SET(x)                              (((x) << MR_AN_CONTROL_POWER_DOWN_LSB) & MR_AN_CONTROL_POWER_DOWN_MASK)
#define MR_AN_CONTROL_POWER_DOWN_RESET                               0x0 // 0
#define MR_AN_CONTROL_RESTART_AN_MSB                                 9
#define MR_AN_CONTROL_RESTART_AN_LSB                                 9
#define MR_AN_CONTROL_RESTART_AN_MASK                                0x00000200
#define MR_AN_CONTROL_RESTART_AN_GET(x)                              (((x) & MR_AN_CONTROL_RESTART_AN_MASK) >> MR_AN_CONTROL_RESTART_AN_LSB)
#define MR_AN_CONTROL_RESTART_AN_SET(x)                              (((x) << MR_AN_CONTROL_RESTART_AN_LSB) & MR_AN_CONTROL_RESTART_AN_MASK)
#define MR_AN_CONTROL_RESTART_AN_RESET                               0x0 // 0
#define MR_AN_CONTROL_DUPLEX_MODE_MSB                                8
#define MR_AN_CONTROL_DUPLEX_MODE_LSB                                8
#define MR_AN_CONTROL_DUPLEX_MODE_MASK                               0x00000100
#define MR_AN_CONTROL_DUPLEX_MODE_GET(x)                             (((x) & MR_AN_CONTROL_DUPLEX_MODE_MASK) >> MR_AN_CONTROL_DUPLEX_MODE_LSB)
#define MR_AN_CONTROL_DUPLEX_MODE_SET(x)                             (((x) << MR_AN_CONTROL_DUPLEX_MODE_LSB) & MR_AN_CONTROL_DUPLEX_MODE_MASK)
#define MR_AN_CONTROL_DUPLEX_MODE_RESET                              0x1 // 1
#define MR_AN_CONTROL_SPEED_SEL1_MSB                                 6
#define MR_AN_CONTROL_SPEED_SEL1_LSB                                 6
#define MR_AN_CONTROL_SPEED_SEL1_MASK                                0x00000040
#define MR_AN_CONTROL_SPEED_SEL1_GET(x)                              (((x) & MR_AN_CONTROL_SPEED_SEL1_MASK) >> MR_AN_CONTROL_SPEED_SEL1_LSB)
#define MR_AN_CONTROL_SPEED_SEL1_SET(x)                              (((x) << MR_AN_CONTROL_SPEED_SEL1_LSB) & MR_AN_CONTROL_SPEED_SEL1_MASK)
#define MR_AN_CONTROL_SPEED_SEL1_RESET                               0x1 // 1
#define MR_AN_CONTROL_ADDRESS                                        0x1807001c

#define SGMII_CONFIG_BERT_ENABLE_MSB                                 14
#define SGMII_CONFIG_BERT_ENABLE_LSB                                 14
#define SGMII_CONFIG_BERT_ENABLE_MASK                                0x00004000
#define SGMII_CONFIG_BERT_ENABLE_GET(x)                              (((x) & SGMII_CONFIG_BERT_ENABLE_MASK) >> SGMII_CONFIG_BERT_ENABLE_LSB)
#define SGMII_CONFIG_BERT_ENABLE_SET(x)                              (((x) << SGMII_CONFIG_BERT_ENABLE_LSB) & SGMII_CONFIG_BERT_ENABLE_MASK)
#define SGMII_CONFIG_BERT_ENABLE_RESET                               0x0 // 0
#define SGMII_CONFIG_PRBS_ENABLE_MSB                                 13
#define SGMII_CONFIG_PRBS_ENABLE_LSB                                 13
#define SGMII_CONFIG_PRBS_ENABLE_MASK                                0x00002000
#define SGMII_CONFIG_PRBS_ENABLE_GET(x)                              (((x) & SGMII_CONFIG_PRBS_ENABLE_MASK) >> SGMII_CONFIG_PRBS_ENABLE_LSB)
#define SGMII_CONFIG_PRBS_ENABLE_SET(x)                              (((x) << SGMII_CONFIG_PRBS_ENABLE_LSB) & SGMII_CONFIG_PRBS_ENABLE_MASK)
#define SGMII_CONFIG_PRBS_ENABLE_RESET                               0x0 // 0
#define SGMII_CONFIG_MDIO_COMPLETE_MSB                               12
#define SGMII_CONFIG_MDIO_COMPLETE_LSB                               12
#define SGMII_CONFIG_MDIO_COMPLETE_MASK                              0x00001000
#define SGMII_CONFIG_MDIO_COMPLETE_GET(x)                            (((x) & SGMII_CONFIG_MDIO_COMPLETE_MASK) >> SGMII_CONFIG_MDIO_COMPLETE_LSB)
#define SGMII_CONFIG_MDIO_COMPLETE_SET(x)                            (((x) << SGMII_CONFIG_MDIO_COMPLETE_LSB) & SGMII_CONFIG_MDIO_COMPLETE_MASK)
#define SGMII_CONFIG_MDIO_COMPLETE_RESET                             0x0 // 0
#define SGMII_CONFIG_MDIO_PULSE_MSB                                  11
#define SGMII_CONFIG_MDIO_PULSE_LSB                                  11
#define SGMII_CONFIG_MDIO_PULSE_MASK                                 0x00000800
#define SGMII_CONFIG_MDIO_PULSE_GET(x)                               (((x) & SGMII_CONFIG_MDIO_PULSE_MASK) >> SGMII_CONFIG_MDIO_PULSE_LSB)
#define SGMII_CONFIG_MDIO_PULSE_SET(x)                               (((x) << SGMII_CONFIG_MDIO_PULSE_LSB) & SGMII_CONFIG_MDIO_PULSE_MASK)
#define SGMII_CONFIG_MDIO_PULSE_RESET                                0x0 // 0
#define SGMII_CONFIG_MDIO_ENABLE_MSB                                 10
#define SGMII_CONFIG_MDIO_ENABLE_LSB                                 10
#define SGMII_CONFIG_MDIO_ENABLE_MASK                                0x00000400
#define SGMII_CONFIG_MDIO_ENABLE_GET(x)                              (((x) & SGMII_CONFIG_MDIO_ENABLE_MASK) >> SGMII_CONFIG_MDIO_ENABLE_LSB)
#define SGMII_CONFIG_MDIO_ENABLE_SET(x)                              (((x) << SGMII_CONFIG_MDIO_ENABLE_LSB) & SGMII_CONFIG_MDIO_ENABLE_MASK)
#define SGMII_CONFIG_MDIO_ENABLE_RESET                               0x0 // 0
#define SGMII_CONFIG_NEXT_PAGE_LOADED_MSB                            9
#define SGMII_CONFIG_NEXT_PAGE_LOADED_LSB                            9
#define SGMII_CONFIG_NEXT_PAGE_LOADED_MASK                           0x00000200
#define SGMII_CONFIG_NEXT_PAGE_LOADED_GET(x)                         (((x) & SGMII_CONFIG_NEXT_PAGE_LOADED_MASK) >> SGMII_CONFIG_NEXT_PAGE_LOADED_LSB)
#define SGMII_CONFIG_NEXT_PAGE_LOADED_SET(x)                         (((x) << SGMII_CONFIG_NEXT_PAGE_LOADED_LSB) & SGMII_CONFIG_NEXT_PAGE_LOADED_MASK)
#define SGMII_CONFIG_NEXT_PAGE_LOADED_RESET                          0x0 // 0
#define SGMII_CONFIG_REMOTE_PHY_LOOPBACK_MSB                         8
#define SGMII_CONFIG_REMOTE_PHY_LOOPBACK_LSB                         8
#define SGMII_CONFIG_REMOTE_PHY_LOOPBACK_MASK                        0x00000100
#define SGMII_CONFIG_REMOTE_PHY_LOOPBACK_GET(x)                      (((x) & SGMII_CONFIG_REMOTE_PHY_LOOPBACK_MASK) >> SGMII_CONFIG_REMOTE_PHY_LOOPBACK_LSB)
#define SGMII_CONFIG_REMOTE_PHY_LOOPBACK_SET(x)                      (((x) << SGMII_CONFIG_REMOTE_PHY_LOOPBACK_LSB) & SGMII_CONFIG_REMOTE_PHY_LOOPBACK_MASK)
#define SGMII_CONFIG_REMOTE_PHY_LOOPBACK_RESET                       0x0 // 0
#define SGMII_CONFIG_SPEED_MSB                                       7
#define SGMII_CONFIG_SPEED_LSB                                       6
#define SGMII_CONFIG_SPEED_MASK                                      0x000000c0
#define SGMII_CONFIG_SPEED_GET(x)                                    (((x) & SGMII_CONFIG_SPEED_MASK) >> SGMII_CONFIG_SPEED_LSB)
#define SGMII_CONFIG_SPEED_SET(x)                                    (((x) << SGMII_CONFIG_SPEED_LSB) & SGMII_CONFIG_SPEED_MASK)
#define SGMII_CONFIG_SPEED_RESET                                     0x0 // 0
#define SGMII_CONFIG_FORCE_SPEED_MSB                                 5
#define SGMII_CONFIG_FORCE_SPEED_LSB                                 5
#define SGMII_CONFIG_FORCE_SPEED_MASK                                0x00000020
#define SGMII_CONFIG_FORCE_SPEED_GET(x)                              (((x) & SGMII_CONFIG_FORCE_SPEED_MASK) >> SGMII_CONFIG_FORCE_SPEED_LSB)
#define SGMII_CONFIG_FORCE_SPEED_SET(x)                              (((x) << SGMII_CONFIG_FORCE_SPEED_LSB) & SGMII_CONFIG_FORCE_SPEED_MASK)
#define SGMII_CONFIG_FORCE_SPEED_RESET                               0x0 // 0
#define SGMII_CONFIG_MR_REG4_CHANGED_MSB                             4
#define SGMII_CONFIG_MR_REG4_CHANGED_LSB                             4
#define SGMII_CONFIG_MR_REG4_CHANGED_MASK                            0x00000010
#define SGMII_CONFIG_MR_REG4_CHANGED_GET(x)                          (((x) & SGMII_CONFIG_MR_REG4_CHANGED_MASK) >> SGMII_CONFIG_MR_REG4_CHANGED_LSB)
#define SGMII_CONFIG_MR_REG4_CHANGED_SET(x)                          (((x) << SGMII_CONFIG_MR_REG4_CHANGED_LSB) & SGMII_CONFIG_MR_REG4_CHANGED_MASK)
#define SGMII_CONFIG_MR_REG4_CHANGED_RESET                           0x0 // 0
#define SGMII_CONFIG_ENABLE_SGMII_TX_PAUSE_MSB                       3
#define SGMII_CONFIG_ENABLE_SGMII_TX_PAUSE_LSB                       3
#define SGMII_CONFIG_ENABLE_SGMII_TX_PAUSE_MASK                      0x00000008
#define SGMII_CONFIG_ENABLE_SGMII_TX_PAUSE_GET(x)                    (((x) & SGMII_CONFIG_ENABLE_SGMII_TX_PAUSE_MASK) >> SGMII_CONFIG_ENABLE_SGMII_TX_PAUSE_LSB)
#define SGMII_CONFIG_ENABLE_SGMII_TX_PAUSE_SET(x)                    (((x) << SGMII_CONFIG_ENABLE_SGMII_TX_PAUSE_LSB) & SGMII_CONFIG_ENABLE_SGMII_TX_PAUSE_MASK)
#define SGMII_CONFIG_ENABLE_SGMII_TX_PAUSE_RESET                     0x0 // 0
#define SGMII_CONFIG_MODE_CTRL_MSB                                   2
#define SGMII_CONFIG_MODE_CTRL_LSB                                   0
#define SGMII_CONFIG_MODE_CTRL_MASK                                  0x00000007
#define SGMII_CONFIG_MODE_CTRL_GET(x)                                (((x) & SGMII_CONFIG_MODE_CTRL_MASK) >> SGMII_CONFIG_MODE_CTRL_LSB)
#define SGMII_CONFIG_MODE_CTRL_SET(x)                                (((x) << SGMII_CONFIG_MODE_CTRL_LSB) & SGMII_CONFIG_MODE_CTRL_MASK)
#define SGMII_CONFIG_MODE_CTRL_RESET                                 0x0 // 0
#define SGMII_CONFIG_ADDRESS                                         0x18070034

#define SGMII_RESET_HW_RX_125M_N_MSB                                 4
#define SGMII_RESET_HW_RX_125M_N_LSB                                 4
#define SGMII_RESET_HW_RX_125M_N_MASK                                0x00000010
#define SGMII_RESET_HW_RX_125M_N_GET(x)                              (((x) & SGMII_RESET_HW_RX_125M_N_MASK) >> SGMII_RESET_HW_RX_125M_N_LSB)
#define SGMII_RESET_HW_RX_125M_N_SET(x)                              (((x) << SGMII_RESET_HW_RX_125M_N_LSB) & SGMII_RESET_HW_RX_125M_N_MASK)
#define SGMII_RESET_HW_RX_125M_N_RESET                               0x0 // 0
#define SGMII_RESET_TX_125M_N_MSB                                    3
#define SGMII_RESET_TX_125M_N_LSB                                    3
#define SGMII_RESET_TX_125M_N_MASK                                   0x00000008
#define SGMII_RESET_TX_125M_N_GET(x)                                 (((x) & SGMII_RESET_TX_125M_N_MASK) >> SGMII_RESET_TX_125M_N_LSB)
#define SGMII_RESET_TX_125M_N_SET(x)                                 (((x) << SGMII_RESET_TX_125M_N_LSB) & SGMII_RESET_TX_125M_N_MASK)
#define SGMII_RESET_TX_125M_N_RESET                                  0x0 // 0
#define SGMII_RESET_RX_125M_N_MSB                                    2
#define SGMII_RESET_RX_125M_N_LSB                                    2
#define SGMII_RESET_RX_125M_N_MASK                                   0x00000004
#define SGMII_RESET_RX_125M_N_GET(x)                                 (((x) & SGMII_RESET_RX_125M_N_MASK) >> SGMII_RESET_RX_125M_N_LSB)
#define SGMII_RESET_RX_125M_N_SET(x)                                 (((x) << SGMII_RESET_RX_125M_N_LSB) & SGMII_RESET_RX_125M_N_MASK)
#define SGMII_RESET_RX_125M_N_RESET                                  0x0 // 0
#define SGMII_RESET_TX_CLK_N_MSB                                     1
#define SGMII_RESET_TX_CLK_N_LSB                                     1
#define SGMII_RESET_TX_CLK_N_MASK                                    0x00000002
#define SGMII_RESET_TX_CLK_N_GET(x)                                  (((x) & SGMII_RESET_TX_CLK_N_MASK) >> SGMII_RESET_TX_CLK_N_LSB)
#define SGMII_RESET_TX_CLK_N_SET(x)                                  (((x) << SGMII_RESET_TX_CLK_N_LSB) & SGMII_RESET_TX_CLK_N_MASK)
#define SGMII_RESET_TX_CLK_N_RESET                                   0x0 // 0
#define SGMII_RESET_RX_CLK_N_MSB                                     0
#define SGMII_RESET_RX_CLK_N_LSB                                     0
#define SGMII_RESET_RX_CLK_N_MASK                                    0x00000001
#define SGMII_RESET_RX_CLK_N_GET(x)                                  (((x) & SGMII_RESET_RX_CLK_N_MASK) >> SGMII_RESET_RX_CLK_N_LSB)
#define SGMII_RESET_RX_CLK_N_SET(x)                                  (((x) << SGMII_RESET_RX_CLK_N_LSB) & SGMII_RESET_RX_CLK_N_MASK)
#define SGMII_RESET_RX_CLK_N_RESET                                   0x0 // 0
#define SGMII_RESET_ADDRESS                                          0x18070014


#define here()		hh(__FILE__, __LINE__)
#define hh(a, b)	serial_puts(a ## b ## "\n")

#define ath_gmac_unit2mac(_unit)	(&ath_gmac_mac)
#define ath_gmac_name2mac(name)		ath_gmac_unit2mac(name)
	//strcmp(name,"eth0") ? ath_gmac_unit2mac(1) : ath_gmac_unit2mac(0)

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
#define __gmac_mdelay(_msecs)	udelay((_msecs) * 1000)

void fwd_tgt_recv(ath_gmac_softc_t * mac, a_uint8_t * rxbuf, int datalen);

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
#define MAX_RX_PKT_SIZE		1096
#define MAX_TX_PKTS 1
#define MAX_RX_PKTS 2

volatile a_uint8_t *NetRxPackets[MAX_RX_PKTS];	/* Receive packets */
volatile a_uint8_t *NetTxPackets[MAX_TX_PKTS];	/* Receive packets */

a_uint16_t ath_gmac_miiphy_read(char *, a_uint32_t, a_uint8_t);
void ath_gmac_miiphy_write(char *, a_uint32_t, a_uint8_t, a_uint16_t);

ath_gmac_softc_t ath_gmac_mac;

extern int athrs26_phy_setup(int unit);
extern int athrs26_phy_is_up(int unit);
extern int athrs26_phy_is_fdx(int unit);
extern int athrs26_phy_speed(int unit);
extern void athrs26_reg_init(void);
extern void athrs26_reg_init_lan(void);
extern int athrs26_mdc_check(void);

static int
ath_gmac_send(ath_gmac_softc_t * mac, volatile void *packet, int length)
{
	ath_gmac_desc_t *f = mac->fifo_tx[mac->next_tx];

	f->res1 = f->res2 = 0;
	f->pkt_size = length;
	f->pkt_start_addr = PHYSADDR(packet);

	ath_gmac_tx_give_to_dma(f);
#if 0
	flush_cache((u32) packet, length);
#endif
	ath_gmac_reg_wr(mac, ATH_DMA_TX_DESC, PHYSADDR(f));
	ath_gmac_reg_wr(mac, ATH_DMA_TX_CTRL, ATH_TXE);

#if 0
	for (i = 0; i < MAX_WAIT; i++) {
		udelay(10);
		if (!ath_gmac_tx_owned_by_dma(f))
			break;
	}
	if (i == MAX_WAIT)
		printf("Tx Timed out\n");
	f->pkt_start_addr = 0;
	f->pkt_size = 0;
#else
	while (ath_gmac_tx_owned_by_dma(f))
		printf(".");

	printf("*");
#endif


	if (++mac->next_tx >= MAX_TX_PKTS)
		mac->next_tx = 0;

	return (0);
}

static int ath_gmac_fwd_recv(ath_gmac_softc_t * mac)
{
	int length;
	ath_gmac_desc_t *f;
	__gmac_softc_t *sc = &gmac_sc;

	for (;;) {
		f = mac->fifo_rx[mac->next_rx];
		if (ath_gmac_rx_owned_by_dma(f))
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

		ath_gmac_rx_give_to_dma(f);

		if (++mac->next_rx >= MAX_RX_PKTS)
			mac->next_rx = 0;
	}

	if (!(ath_gmac_reg_rd(mac, ATH_DMA_RX_CTRL))) {
		ath_gmac_reg_wr(mac, ATH_DMA_RX_DESC, PHYSADDR(f));
		ath_gmac_reg_wr(mac, ATH_DMA_RX_CTRL, 1);
	}

	return (0);
}

#if defined(ATH_SGMII_DOWNLOAD) || defined(ROMBOOTDRV_SUPPORT_GMAC_1000M)
void
athrs_sgmii_res_cal(void)
{
	unsigned int read_data, read_data_otp, otp_value, otp_per_val, rbias_per;
	unsigned int read_data_spi;
	unsigned int *address_spi = (unsigned int *)0xbffffffc;
	unsigned int rbias_pos_or_neg, res_cal_val;
	unsigned int sgmii_pos, sgmii_res_cal_value;
	unsigned int reversed_sgmii_value, use_value;

	ath_reg_wr(OTP_INTF2_ADDRESS, 0x7d);
	ath_reg_wr(OTP_LDO_CONTROL_ADDRESS, 0x0);

	while (ath_reg_rd(OTP_LDO_STATUS_ADDRESS) & OTP_LDO_STATUS_POWER_ON_MASK);

	read_data = ath_reg_rd(OTP_MEM_0_ADDRESS + 4);

	while (!(ath_reg_rd(OTP_STATUS0_ADDRESS) & OTP_STATUS0_EFUSE_READ_DATA_VALID_MASK));

	read_data_otp = ath_reg_rd(OTP_STATUS1_ADDRESS);

	if (read_data_otp & 0x1fff) {
		read_data = read_data_otp;
	} else {
		read_data_spi = *(address_spi);
		if ((read_data_spi & 0xffff0000) == 0x5ca10000) {
			read_data = read_data_spi;
		} else {
			read_data = read_data_otp;
		}
	}

	if (read_data & 0x00001000) {
		otp_value = (read_data & 0xfc0) >> 6;
	} else {
		otp_value = read_data & 0x3f;
	}

	if (otp_value > 31) {
		otp_per_val = 63 - otp_value;
		rbias_pos_or_neg = 1;
	} else {
		otp_per_val = otp_value;
		rbias_pos_or_neg = 0;
	}

	rbias_per = otp_per_val * 15;

	if (rbias_pos_or_neg == 1) {
		res_cal_val = (rbias_per + 34) / 21;
		sgmii_pos = 1;
	} else {
		if (rbias_per > 34) {
			res_cal_val = (rbias_per - 34) / 21;
			sgmii_pos = 0;
		} else {
			res_cal_val = (34 - rbias_per) / 21;
			sgmii_pos = 1;
		}
	}

	if (sgmii_pos == 1) {
		sgmii_res_cal_value = 8 + res_cal_val;
	} else {
		sgmii_res_cal_value = 8 - res_cal_val;
	}

	reversed_sgmii_value = 0;
	use_value = 0x8;
	reversed_sgmii_value = reversed_sgmii_value | ((sgmii_res_cal_value & use_value) >> 3);
	use_value = 0x4;
	reversed_sgmii_value = reversed_sgmii_value | ((sgmii_res_cal_value & use_value) >> 1);
	use_value = 0x2;
	reversed_sgmii_value = reversed_sgmii_value | ((sgmii_res_cal_value & use_value) << 1);
	use_value = 0x1;
	reversed_sgmii_value = reversed_sgmii_value | ((sgmii_res_cal_value & use_value) << 3);

	reversed_sgmii_value &= 0xf;

	printf("%s: cal value = 0x%x\n", __func__, reversed_sgmii_value);

	// To Check the locking of the SGMII PLL

	read_data = (ath_reg_rd(SGMII_SERDES_ADDRESS) &
				~SGMII_SERDES_RES_CALIBRATION_MASK) |
			SGMII_SERDES_RES_CALIBRATION_SET(reversed_sgmii_value);

	ath_reg_wr(SGMII_SERDES_ADDRESS, read_data);


	ath_reg_wr(ETH_SGMII_SERDES_ADDRESS,
			ETH_SGMII_SERDES_EN_LOCK_DETECT_MASK |
			ETH_SGMII_SERDES_PLL_REFCLK_SEL_MASK |
			ETH_SGMII_SERDES_EN_PLL_MASK);

	ath_reg_rmw_set(SGMII_SERDES_ADDRESS,
			SGMII_SERDES_CDR_BW_SET(3) |
			SGMII_SERDES_TX_DR_CTRL_SET(1) |
			SGMII_SERDES_PLL_BW_SET(1) |
			SGMII_SERDES_EN_SIGNAL_DETECT_SET(1) |
			SGMII_SERDES_FIBER_SDO_SET(1) |
			SGMII_SERDES_VCO_REG_SET(3));

	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_ETH_SGMII_ARESET_MASK);
	udelay(25);
	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_ETH_SGMII_RESET_MASK);

	while (!(ath_reg_rd(SGMII_SERDES_ADDRESS) & SGMII_SERDES_LOCK_DETECT_STATUS_MASK));
}
#endif /* ATH_SGMII_DOWNLOAD || ROMBOOTDRV_SUPPORT_GMAC_1000M */

#ifdef ATH_SGMII_DOWNLOAD
void athr_gmac_xmii_mac_setup(ath_gmac_softc_t * mac)
{
	int status=0, count=0;

	ath_reg_wr(MR_AN_CONTROL_ADDRESS, MR_AN_CONTROL_PHY_RESET_SET(1) |
					MR_AN_CONTROL_DUPLEX_MODE_SET(1) |
					MR_AN_CONTROL_SPEED_SEL1_SET(1));
	udelay(10);

	ath_reg_wr(SGMII_CONFIG_ADDRESS, SGMII_CONFIG_SPEED_SET(2) |
					SGMII_CONFIG_FORCE_SPEED_SET(1) |
					SGMII_CONFIG_MODE_CTRL_SET(2));

	ath_reg_wr(SGMII_RESET_ADDRESS, SGMII_RESET_RX_CLK_N_RESET);

	ath_reg_wr(SGMII_RESET_ADDRESS, SGMII_RESET_HW_RX_125M_N_SET(1));

	ath_reg_wr(SGMII_RESET_ADDRESS, SGMII_RESET_HW_RX_125M_N_SET(1) |
					SGMII_RESET_RX_125M_N_SET(1));

	ath_reg_wr(SGMII_RESET_ADDRESS, SGMII_RESET_HW_RX_125M_N_SET(1) |
			SGMII_RESET_TX_125M_N_SET(1) |
			SGMII_RESET_RX_125M_N_SET(1));

	ath_reg_wr(SGMII_RESET_ADDRESS, SGMII_RESET_HW_RX_125M_N_SET(1) |
			SGMII_RESET_TX_125M_N_SET(1) |
			SGMII_RESET_RX_125M_N_SET(1) |
			SGMII_RESET_RX_CLK_N_SET(1));

	ath_reg_wr(SGMII_RESET_ADDRESS, SGMII_RESET_HW_RX_125M_N_SET(1) |
			SGMII_RESET_TX_125M_N_SET(1) |
			SGMII_RESET_RX_125M_N_SET(1) |
			SGMII_RESET_RX_CLK_N_SET(1) |
			SGMII_RESET_TX_CLK_N_SET(1));

	ath_reg_rmw_clear(MR_AN_CONTROL_ADDRESS, MR_AN_CONTROL_PHY_RESET_SET(1));

	/*
	 * WAR::Across resets SGMII link status goes to weird
	 * state.
	 * if 0xb8070058 (SGMII_DEBUG register) reads other then 0x1f or 0x10
	 * for sure we are in bad  state.
	 * Issue a PHY reset in MR_AN_CONTROL_ADDRESS to keep going.
	 */

	status = (ath_reg_rd(SGMII_DEBUG_ADDRESS) & 0xff);
	while (!(status == 0xf || status == 0x10)) {

		ath_reg_rmw_set(MR_AN_CONTROL_ADDRESS, MR_AN_CONTROL_PHY_RESET_SET(1));
		udelay(100);
		ath_reg_rmw_clear(MR_AN_CONTROL_ADDRESS, MR_AN_CONTROL_PHY_RESET_SET(1));
		if (count++ == SGMII_LINK_WAR_MAX_TRY) {
			printf ("Max resets limit reached exiting...\n");
			break;
		}
		status = (ath_reg_rd(SGMII_DEBUG_ADDRESS) & 0xff);
	}


	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_GE1_MAC_RESET_MASK);

	ath_gmac_reg_wr(mac, ATH_MAC_CFG2, 0x7235);   //Enable MII/GMII Interface  (1000 mbps) ..Full duplex

	ath_gmac_reg_wr(mac, ATH_MAC_IFCTL, 0x00000);

	ath_gmac_reg_wr(mac, ATH_MAC_CFG1, 0x00000035);   // for 1000 mbps mode

	ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR1, 0xAAAAAAAA); //ethernet mac address
	ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR2, 0xAAAA0000); //ethernet mac address

	ath_gmac_reg_wr(mac, ATH_MAC_MII_MGMT_CFG, 0x6);

	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_0, 0x1f00); // Enable the FIFO modules

	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_1, 0x10ffff);
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_2, 0x015500aa); /*for 1000 mbps mode */
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_3, 0x1f00140);

	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_4, 0xfffff); /*for 1000 mbps */

	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_5, 0xe6b82); /*for 1000 mbps mode */

	ath_reg_wr(ETH_CFG_ADDRESS,	ETH_CFG_ETH_RXDV_DELAY_SET(0x3) |
					ETH_CFG_ETH_RXD_DELAY_SET(0x3) |
					ETH_CFG_RGMII_GE0_SET(0x1));

	ath_reg_wr(ETH_XMII_ADDRESS,	ETH_XMII_TX_INVERT_SET(0x1) |
					ETH_XMII_RX_DELAY_SET(0x2) |
					ETH_XMII_TX_DELAY_SET(0x1) |
					ETH_XMII_GIGE_SET(0x1));
}
#elif defined(ROMBOOTDRV_SUPPORT_GMAC_1000M)

#define ATH_RGMII_CAL
#ifdef ATH_RGMII_CAL

#define NUM_DESCRIPTORS		10	//Number of packets to be looped back
#define node_tx_buf_len		100	// No of bytes per packet to be looped back

#define DEBUG		0
#define DEBUG_1 	1

#define GE0_PEMSTAT_RBYT	(0x9c + ATH_GE0_BASE)
#define GE0_PEMSTAT_RPKT	(0xA0 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RFCS	(0xA4 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RMCA	(0xA8 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RBCA	(0xAC + ATH_GE0_BASE)
#define GE0_PEMSTAT_RXCF	(0xB0 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RXPF	(0xB4 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RXUO	(0xB8 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RALN	(0xBC + ATH_GE0_BASE)
#define GE0_PEMSTAT_RFLR	(0xC0 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RCDE	(0xC4 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RCSE	(0xC8 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RUND	(0xCC + ATH_GE0_BASE)
#define GE0_PEMSTAT_ROVR	(0xD0 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RFRG	(0xD4 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RJBR	(0xD8 + ATH_GE0_BASE)
#define GE0_PEMSTAT_RDRP	(0xDC + ATH_GE0_BASE)
#define GE0_PEMSTAT_TPKT	(0xE0 + ATH_GE0_BASE)

#define NUM_DESCS 10

typedef u32 uint32_t;
typedef u16 uint16_t;
typedef u8  uint8_t;

uint32_t athrs17_reg_read(uint32_t reg_addr);
void athrs17_reg_write(uint32_t reg_addr, uint32_t reg_val);

#define ath_gmac_unit2name(_unit) (_unit ?  "eth1" : "eth0")

#define phy_reg_read(base, addr, reg)   \
	ath_gmac_miiphy_read(ath_gmac_unit2name(base), addr, reg)

#define phy_reg_write(base, addr, reg, data)    \
	ath_gmac_miiphy_write(ath_gmac_unit2name(base), addr, reg, data)

uint16_t
ath_gmac_miiphy_read(char *devname, uint32_t phy_addr, uint8_t reg)
{
	ath_gmac_softc_t *mac   = ath_gmac_name2mac(devname);
	uint16_t      addr  = (phy_addr << ATH_ADDR_SHIFT) | reg, val;
	volatile int           rddata;
	uint16_t      ii = 0xFFFF;




	/*
	 * Check for previous transactions are complete. Added to avoid
	 * race condition while running at higher frequencies.
	 */
	do
	{
		udelay(5);
		rddata = ath_gmac_reg_rd(mac, ATH_MII_MGMT_IND) & 0x1;
	}while(rddata && --ii);

	if (ii == 0)
		printf("ERROR:%s:%d transaction failed\n",__func__,__LINE__);


	ath_gmac_reg_wr(mac, ATH_MII_MGMT_CMD, 0x0);
	ath_gmac_reg_wr(mac, ATH_MII_MGMT_ADDRESS, addr);
	ath_gmac_reg_wr(mac, ATH_MII_MGMT_CMD, ATH_MGMT_CMD_READ);

	do
	{
		udelay(5);
		rddata = ath_gmac_reg_rd(mac, ATH_MII_MGMT_IND) & 0x1;
	}while(rddata && --ii);

	if(ii==0)
		printf("Error!!! Leave ath_gmac_miiphy_read without polling correct status!\n");

	val = ath_gmac_reg_rd(mac, ATH_MII_MGMT_STATUS);
	ath_gmac_reg_wr(mac, ATH_MII_MGMT_CMD, 0x0);

	return val;
}

void
ath_gmac_miiphy_write(char *devname, uint32_t phy_addr, uint8_t reg, uint16_t data)
{
	ath_gmac_softc_t *mac   = ath_gmac_name2mac(devname);
	uint16_t      addr  = (phy_addr << ATH_ADDR_SHIFT) | reg;
	volatile int rddata;
	uint16_t      ii = 0xFFFF;


	/*
	 * Check for previous transactions are complete. Added to avoid
	 * race condition while running at higher frequencies.
	 */
	do {
		udelay(5);
		rddata = ath_gmac_reg_rd(mac, ATH_MII_MGMT_IND) & 0x1;
	} while (rddata && --ii);

	if (ii == 0)
		printf("ERROR:%s:%d transaction failed\n",__func__,__LINE__);

	ath_gmac_reg_wr(mac, ATH_MII_MGMT_ADDRESS, addr);
	ath_gmac_reg_wr(mac, ATH_MII_MGMT_CTRL, data);

	do {
		rddata = ath_gmac_reg_rd(mac, ATH_MII_MGMT_IND) & 0x1;
	} while (rddata && --ii);

	if (ii == 0)
		printf("Error!!! Leave ath_gmac_miiphy_write without polling correct status!\n");
}

void s17_reg_rmw(unsigned int reg_addr, unsigned int reg_val)
{
	reg_val |= athrs17_reg_read(reg_addr);
	athrs17_reg_write(reg_addr, reg_val);
}

uint32_t
athrs17_reg_read(uint32_t reg_addr)
{
	uint32_t reg_word_addr;
	uint32_t phy_addr, tmp_val, reg_val;
	uint16_t phy_val;
	uint8_t phy_reg;

	/* change reg_addr to 16-bit word address, 32-bit aligned */
	reg_word_addr = (reg_addr & 0xfffffffc) >> 1;

	/* configure register high address */
	phy_addr = 0x18;
	phy_reg = 0x0;
	phy_val = (uint16_t) ((reg_word_addr >> 8) & 0x1ff);  /* bit16-8 of reg address */
	phy_reg_write(0, phy_addr, phy_reg, phy_val);

	/* For some registers such as MIBs, since it is read/clear, we should */
	/* read the lower 16-bit register then the higher one */

	/* read register in lower address */
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7); /* bit7-5 of reg address */
	phy_reg = (uint8_t) (reg_word_addr & 0x1f);   /* bit4-0 of reg address */
	reg_val = (uint32_t) phy_reg_read(0, phy_addr, phy_reg);

	/* read register in higher address */
	reg_word_addr++;
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7); /* bit7-5 of reg address */
	phy_reg = (uint8_t) (reg_word_addr & 0x1f);   /* bit4-0 of reg address */
	tmp_val = (uint32_t) phy_reg_read(0, phy_addr, phy_reg);
	reg_val |= (tmp_val << 16);

	return reg_val;
}

void
athrs17_reg_write(uint32_t reg_addr, uint32_t reg_val)
{
	uint32_t reg_word_addr;
	uint32_t phy_addr;
	uint16_t phy_val;
	uint8_t phy_reg;

	/* change reg_addr to 16-bit word address, 32-bit aligned */
	reg_word_addr = (reg_addr & 0xfffffffc) >> 1;

	/* configure register high address */
	phy_addr = 0x18;
	phy_reg = 0x0;
	phy_val = (uint16_t) ((reg_word_addr >> 8) & 0x1ff);  /* bit16-8 of reg address */
	phy_reg_write(0, phy_addr, phy_reg, phy_val);

	/* For some registers such as ARL and VLAN, since they include BUSY bit */
	/* in lower address, we should write the higher 16-bit register then the */
	/* lower one */

	/* read register in higher address */
	reg_word_addr++;
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7); /* bit7-5 of reg address */
	phy_reg = (uint8_t) (reg_word_addr & 0x1f);   /* bit4-0 of reg address */
	phy_val = (uint16_t) ((reg_val >> 16) & 0xffff);
	phy_reg_write(0, phy_addr, phy_reg, phy_val);

	/* write register in lower address */
	reg_word_addr--;
	phy_addr = 0x10 | ((reg_word_addr >> 5) & 0x7); /* bit7-5 of reg address */
	phy_reg = (uint8_t) (reg_word_addr & 0x1f);   /* bit4-0 of reg address */
	phy_val = (uint16_t) (reg_val & 0xffff);
	phy_reg_write(0, phy_addr, phy_reg, phy_val);
}

void
init_s17_lpbk(void)
{
	int phyAddr = 0;
	unsigned int rddata;

#ifdef ATH_S17_MAC0_SGMII
	athrs17_reg_write(0x4   , 0x080080);
	athrs17_reg_write(0xc   , 0x07600000);
	athrs17_reg_write(0x94  , 0x000000fe); // 1gbps
	athrs17_reg_write(0x624 , 0x007f7f7f);
	printf ("Vlan config...\n");
	vlan_config();
#else
	athrs17_reg_write(0x624 , 0x003f3f3f);
	athrs17_reg_write(0x4   , 0x07500000);
	athrs17_reg_write(0xc   , 0x01000000);
#endif
	athrs17_reg_write(0x10  , 0x4000000);
	athrs17_reg_write(0x7c  , 0x000000fe); // 1gbps
	//athrs17_reg_write(0x7c  , 0x0000007d); // 100 mbps
	//athrs17_reg_write(0x7c  , 0x0000007c); // 10 mbps

#ifdef ATH_S17_MAC0_SGMII
	phyAddr = 4;
#else
	phyAddr = 0;
#endif
	// To enable loopback on single phy
	phy_reg_write(0, phyAddr, 0x0, 0xc140);
	for(rddata=0; rddata<1000; rddata++);
	phy_reg_write(0, phyAddr, 0x0, 0x4140);
	for(rddata=0; rddata<1000; rddata++);
	rddata = phy_reg_read(0, phyAddr, 0x0);
#ifdef DEBUG
	printf("s17 phy0 register value 0x%08x\n", rddata);
#endif
	// power down other phys
#ifdef ATH_S17_MAC0_SGMII
	phy_reg_write(0, 0x0, 0x0, 0x8800);
#else
	phy_reg_write(0, 0x4, 0x0, 0x8800);
#endif
	phy_reg_write(0, 0x1, 0x0, 0x8800);
	phy_reg_write(0, 0x2, 0x0, 0x8800);
	phy_reg_write(0, 0x3, 0x0, 0x8800);
	/* For 100M waveform */
	phy_reg_write(0, phyAddr, 0x1d, 0x18);
	phy_reg_write(0, phyAddr, 0x1e, 0x02ea);
	/* Turn On Gigabit Clock */
	phy_reg_write(0, phyAddr, 0x1d, 0x3d);
	phy_reg_write(0, phyAddr, 0x1e, 0x48a0);

	/* Enable flow control */
	s17_reg_rmw(0x80,0x30);
	s17_reg_rmw(0x84,0x30);
	s17_reg_rmw(0x88,0x30);
	s17_reg_rmw(0x8c,0x30);
	s17_reg_rmw(0x90,0x30);
}


int results[5] = { 0, 1, 1, 1, 0 };

int find;

void big_del(void)
{
	int i;
	for (i = 0; i < 10000; i++) ;
}

// This should tell us what the best of the 4 values is. It should also tell us what the longest sequence is.
// Since only four bits are used the best of 4 values can be easily arrived at by a truth table.
// Presently we have an algorithm though.
int find_value(void)
{
	int i;
	int start_ok = 9;
	int end_ok = 9;
	int longest_start_ok = 0;
	int longest_end_ok = 0;
	int longest_ok_cnt = -1;
	int first = 0;

	for (i = 0; i < 5; i++) {
#if DEBUG
		printf("results [%d]: %d\n", i, results[i]);
#endif
		if (results[i] == 1) {
			if (start_ok == 9) {
				start_ok = i;
				if (first == 0) {
					longest_start_ok = i;
					longest_end_ok = i;
					first = 1;
				}
			}
		}
		if (results[i] == 0) {
			if (end_ok == 9) {
				end_ok = i - 1;
			}
			if ((end_ok - start_ok) > longest_ok_cnt) {
				longest_start_ok = start_ok;
				longest_end_ok = end_ok;
				longest_ok_cnt = (end_ok - start_ok);
			}
			start_ok = 9;
			end_ok = 9;
		}
	}

#if DEBUG
	printf("FINAL VALUE - ");
#endif
	find = (longest_end_ok + longest_start_ok) / 2;
#if DEBUG
	printf("find - %d\n", find);
	printf("FINAL OK COUNT - %d\n", longest_ok_cnt + 1);
#endif
	return (longest_ok_cnt + 1);
}

int pkt_compare_data(void)
{
	unsigned int i, j;
	//unsigned int k,rddata;
	unsigned int node_rx_buf_len;
	//volatile unsigned int * node_tx_desc_ptr = (unsigned int *) 0xa0280000;
	volatile unsigned int *node_rx_desc_ptr = (unsigned int *)0xa0380000;
	unsigned int *node_tx_buf_addr = (unsigned int *)0xa0680000;
	unsigned int *node_rx_buf_addr = (unsigned int *)0xa0580000;
	unsigned int error = 0;
	unsigned pkt_err[NUM_DESCS];

	node_rx_buf_len = (*(node_rx_desc_ptr + 0x1) & 0xfff) - 0x4;
	// node_tx_buf_len = *(node_tx_desc_ptr + (NUM_DESCS-1)*0x3+0x1) & 0xfff;

	for (j = 0; j < NUM_DESCS; j++) {
		node_rx_buf_len = (*(node_rx_desc_ptr + (NUM_DESCS - 1) * 0x3 + 0x1) & 0xfff) - 0x4;
		pkt_err[j] = 0;
		for (i = 0; i < (node_rx_buf_len / 4); i++) {
			if (((*(node_rx_buf_addr + i + (j * 0x100))) != *(node_tx_buf_addr + i))) {
				error = error + 0x1;
				pkt_err[j] = 1;
			}
		}
		//node_rx_buf_addr = node_rx_buf_addr + 0x100;
	}
	if (error == 0) {
		return 0;
	} else {
		for (j = 0; j < NUM_DESCS; j++) {
			node_rx_buf_len = (*(node_rx_desc_ptr + (NUM_DESCS - 1) * 0x3 + 0x1) & 0xfff) - 0x4;
			if (pkt_err[j] == 1) {
#if DEBUG
				printf("PKT %d\n", j);
				printf("---------------------------------\n");

				for (i = 0; i < (node_rx_buf_len / 4); i++) {
					//if(((*(node_rx_buf_addr + i )) != *(node_tx_buf_addr + i)))
					if (((*(node_rx_buf_addr + i + (j * 0x100))) != *(node_tx_buf_addr + i))) {
						printf("->");
					} else {
						printf("  ");
					}
					printf("%x", (*(node_rx_buf_addr + i + (j * 0x100))));
					printf("  ");
					printf("%x\n", (*(node_tx_buf_addr + i)));
				}
				printf("---------------------------------\n");
#endif
			}
			//node_rx_buf_addr = node_rx_buf_addr + 0x100;
		}
		return 1;
	}
}

void athrs_rgmii_cal(ath_gmac_softc_t * mac)
{

	unsigned int i;
	unsigned int j;
	unsigned int k, l;
	unsigned int rddata = 0, error = 0;
	unsigned int node_rx_buf_len = 1600;
	volatile unsigned int *node_tx_desc_ptr = (unsigned int *)0xa0280000;
	volatile unsigned int *node_rx_desc_ptr = (unsigned int *)0xa0380000;
	unsigned int *node_rx_buf_addr = (unsigned int *)0xa0580000;
	unsigned int *node_tx_buf_addr = (unsigned int *)0xa0680000;
	unsigned int s17_tx_pkt = 0;
#if DEBUG
	unsigned int s17_rx_pkt = 0;
#endif
	unsigned int to;
	unsigned int pass = 1;
	unsigned int fail = 0;
	int lgst = 0;
	int old_lgst = 0;
	unsigned int xmii[16];
	unsigned int eth_cfg[16];
	unsigned int xmii_val = 0;
	unsigned int eth_cfg_val = 1;
	unsigned int tx_fix = 0;


	// GIGE Enable
	ath_reg_wr(ETH_XMII_ADDRESS,	ETH_XMII_TX_INVERT_SET(0x1) |
					ETH_XMII_RX_DELAY_SET(0x2) |
					ETH_XMII_TX_DELAY_SET(0x1) |
					ETH_XMII_GIGE_SET(0x1));

	while ((ath_reg_rd(SGMII_SERDES_ADDRESS) & SGMII_SERDES_LOCK_DETECT_STATUS_SET(1)) == 0) {
		printf("TEST: WAIT FOR LOCK\n");
	}

	big_del();

	// MAC INITS
	// RGMII Enable on GE0
	//eth_init();
	init_s17_lpbk();
	athrs17_reg_write(0x30, 1);

	ath_reg_wr(ETH_CFG_ADDRESS,	ETH_CFG_ETH_RXDV_DELAY_SET(0x3) |
					ETH_CFG_ETH_RXD_DELAY_SET(0x3) |
					ETH_CFG_RGMII_GE0_SET(0x1));

	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_GE0_MAC_RESET_MASK);	// Bringing GE0 out of RESET
	ath_gmac_reg_wr(mac, ATH_MAC_CFG2, 0x7235);	//for 1000mbps
	//ath_reg_wr(GE0_MAC_CONFIG_2,0x7135);  //for 100mbps
	ath_gmac_reg_wr(mac, ATH_MAC_IFCTL, 0x00000);
	ath_gmac_reg_wr(mac, ATH_MAC_CFG1, 0x005);
	//ath_reg_wr(GE0_MAC_CONFIG_1,0x105);  // For MAC Loopback
	ath_gmac_reg_wr(mac, ATH_DMA_INTR_MASK, 0);	// Disable interrupt mask
	ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR1, 0x003fffff);	//ethernet mac address
	ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR2, 0xfffe0000);	//ethernet mac address
	ath_gmac_reg_wr(mac, ATH_MAC_MII_MGMT_CFG, 0x6);	//clock/20= 2MHz
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_0, 0x1f00);	// Enable the FIFO modules
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_1, 0x10ffff);
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_3, 0x1f00140);
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_4, 0x1000);
	//ath_reg_wr(GE0_FIFO_CFG_REG_5, 0xbefff); //enable drop
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_5, 0xfffff);	//for 1000Mbps
	//ath_reg_wr(GE0_FIFO_CFG_REG_5, 0x7ffff);//for 100Mbps

	//************
	// PACKETS
	//***********

	// Initialise Data in Memory for TX and RX
	for (i = 0; i < node_tx_buf_len; i++)
		*(node_tx_buf_addr + i) = i | (i + 1) << 8 | (i + 2) << 16 | (i + 3) << 24;

#if DEBUG
	printf("TEST: Inits Done\n");
#endif
	// Set Up Transmit Descriptor Table

	for (i = 0; i < NUM_DESCRIPTORS; i++) {
		*(node_tx_desc_ptr + (i * 0x3)) = ((unsigned int)node_tx_buf_addr & 0x0fffffff);
		*(node_tx_desc_ptr + (i * 0x3) + 0x1) = (node_tx_buf_len & 0x7fffffff);

		if (i == (NUM_DESCRIPTORS - 1))
			*(node_tx_desc_ptr + (i * 0x3) + 0x2) = ((unsigned int)node_tx_desc_ptr & 0x0fffffff);
		else
			*(node_tx_desc_ptr + (i * 0x3) + 0x2) = ((unsigned int)node_tx_desc_ptr & 0x0fffffff) + (i * 0xc) + 0xc;
	}

	ath_gmac_reg_wr(mac, ATH_DMA_TX_DESC, ((unsigned int)node_tx_desc_ptr & 0x0fffffff));
	ath_gmac_reg_wr(mac, ATH_DMA_TX_STATUS, 0xfffffff);	// clear dma status

	for (i = 0; i < NUM_DESCRIPTORS; i++) {
		*(node_rx_desc_ptr + (i * 0x3)) = ((unsigned int)node_rx_buf_addr & 0x0fffffff);
		*(node_rx_desc_ptr + (i * 0x3) + 0x1) = (node_rx_buf_len & 0xfff) | (1 << 31);
		if (i == (NUM_DESCRIPTORS - 1))
			*(node_rx_desc_ptr + (i * 0x3) + 0x2) = ((unsigned int)node_rx_desc_ptr & 0x0fffffff);
		else
			*(node_rx_desc_ptr + (i * 0x3) + 0x2) = ((unsigned int)node_rx_desc_ptr & 0x0fffffff) + (i * 0xc) + 0xc;
		node_rx_buf_addr = node_rx_buf_addr + 0x100;

	}

	ath_gmac_reg_wr(mac, ATH_DMA_RX_DESC, ((unsigned int)node_rx_desc_ptr & 0x0fffffff));
	ath_gmac_reg_wr(mac, ATH_DMA_RX_STATUS, 0xfffffff);	// clear dma status

	k = 0;

	// Enable TX and RX MAC
	ath_gmac_reg_wr(mac, ATH_MAC_CFG1, 0x005);

	// This routine will go through 16 combinations to find the best value for TX_DELAY, GIGE_QUAD, TX_INVERT
	for (l = 0; l < 16; l++) {
		// initialize pass. this will be made zero if there is a failure in packet reception compare
		pass = 1;
		// fail due to checks in rx etc. this is not the same as !pass
		fail = 0;

		// GIGE_QUAD  - 0
		// TX_INVERT  - 0
		// TX_DELAY   - 0,1,2,3
		if (l < 4) {
			// GIGE Enable and TX_DELAY
			rddata = ETH_XMII_GIGE_SET(0x1) |
				ETH_XMII_TX_DELAY_SET(l);
			ath_reg_wr(ETH_XMII_ADDRESS, rddata);
			rddata = ath_reg_rd(ETH_XMII_ADDRESS);
#if DEBUG
			printf("TEST: ETH_XMII - 0x%08x\n", rddata);
#endif
		}
		// GIGE_QUAD  - 1
		// TX_INVERT  - 0
		// TX_DELAY   - 0,1,2,3
		if ((l < 8) && (l > 3)) {
			// GIGE Enable and TX_DELAY & GIGE_QUAD
			rddata = ETH_XMII_GIGE_QUAD_SET(0x1) |
				ETH_XMII_GIGE_SET(0x1) |
				ETH_XMII_TX_DELAY_SET(l);
			ath_reg_wr(ETH_XMII_ADDRESS, rddata);
			rddata = ath_reg_rd(ETH_XMII_ADDRESS);
#if DEBUG
			printf("TEST: ETH_XMII - 0x%08x\n", rddata);
#endif
		}
		// GIGE_QUAD  - 0
		// TX_INVERT  - 1
		// TX_DELAY   - 0,1,2,3
		if ((l < 12) && (l > 7)) {
			// GIGE Enable and TX_DELAY and TX_INVERT
			rddata = ETH_XMII_TX_INVERT_SET(0x1) |
				ETH_XMII_GIGE_SET(0x1) |
				ETH_XMII_TX_DELAY_SET(l);
			ath_reg_wr(ETH_XMII_ADDRESS, rddata);
			rddata = ath_reg_rd(ETH_XMII_ADDRESS);
#if DEBUG
			printf("TEST: ETH_XMII - 0x%08x\n", rddata);
#endif
		}
		// GIGE_QUAD  - 0
		// TX_INVERT  - 1
		// TX_DELAY   - 0,1,2,3
		if ((l < 16) && (l > 11)) {
			// GIGE Enable and TX_DELAY and TX_INVERT and GIGE_QUAD
			rddata = ETH_XMII_TX_INVERT_SET(0x1) |
				ETH_XMII_GIGE_QUAD_SET(0x1) |
				ETH_XMII_GIGE_SET(0x1) |
				ETH_XMII_TX_DELAY_SET(l);
			ath_reg_wr(ETH_XMII_ADDRESS, rddata);
			rddata = ath_reg_rd(ETH_XMII_ADDRESS);
#if DEBUG
			printf("TEST: ETH_XMII - 0x%08x\n", rddata);
#endif
		}
		xmii[l] = rddata;

		// counts when to print out counter stats
		k++;
		// Set Up Receive Descriptor Table
		node_rx_buf_len = 0x0;
		ath_gmac_reg_wr(mac, ATH_DMA_RX_CTRL, 0x1);	// enable dma rx
		ath_gmac_reg_wr(mac, ATH_DMA_TX_CTRL, 0x1);	// enable dma tx

		rddata = (*(node_tx_desc_ptr + (NUM_DESCRIPTORS - 1) * 0x3 + 0x1) & (1 << 31));
		while (rddata != (1 << 31))
			rddata = (*(node_tx_desc_ptr + (NUM_DESCRIPTORS - 1) * 0x3 + 0x1) & (1 << 31));
#if DEBUG
		printf("TEST: Tx Done \n");
#endif

		to = 0;
		rddata = (*(node_rx_desc_ptr + (NUM_DESCS - 1) * 0x3 + 0x1) & (1 << 31));
		while (rddata != 0x0) {
			rddata = (*(node_rx_desc_ptr + (NUM_DESCS - 1) * 0x3 + 0x1) & (1 << 31));
			to++;
			if (to > 100000) {
#if DEBUG
				printf("TEST: ERROR!! Atleast 1 packet in GE0 not seen.\n");
#endif
				fail = 1;
				break;
			}
		}
#if DEBUG
		printf("TEST: Rx Done \n");
#endif

		if (k % 1 == 0) {
			for (j = GE0_PEMSTAT_RBYT; j <= GE0_PEMSTAT_RDRP; j = j + 4) {
				rddata = ath_reg_rd(j);
				switch (j) {
#if DEBUG
				case GE0_PEMSTAT_RPKT:
					printf("TEST: RPKT - 0x%08x\n", rddata);
					break;
				case GE0_PEMSTAT_TPKT:
					printf("TEST: TPKT - 0x%08x\n", rddata);
					break;
#endif
				}
			}
#if DEBUG
#ifdef ATH_S17_MAC0_SGMII
			s17_rx_pkt = athrs17_reg_read(0x163c) + (athrs17_reg_read(0x1640) << 16);
#else
			s17_rx_pkt = athrs17_reg_read(0x103c) + (athrs17_reg_read(0x1040) << 16);
#endif
			printf("TEST: RPKT in S17 0x%08x\n", s17_rx_pkt);
#endif
#ifdef ATH_S17_MAC0_SGMII
			s17_tx_pkt = athrs17_reg_read(0x1684) + (athrs17_reg_read(0x1688) << 16);
#else
			s17_tx_pkt = athrs17_reg_read(0x1084) + (athrs17_reg_read(0x1088) << 16);
#endif
#if DEBUG
			printf("TEST: TPKT in S17 0x%08x\n", s17_tx_pkt);
#endif
			// Compare BYTES in TX
			if (s17_tx_pkt != 0x410) {
#if DEBUG
				printf("TEST: PKTS @ S17 - 0x%08x\n", rddata);
#endif
				pass = 0;
				fail = 1;
			}

		}
		if (fail == 0) {
			error = pkt_compare_data();
		}
		if (error == 0) {
#if DEBUG
			printf("TEST: PACKET COMPARISON PASS\n");
#endif
		} else {
#if DEBUG
			printf("TEST: ERROR!! PACKET COMPARISON FAIL\n");
#endif
			fail = 1;
		}

		for (i = 0; i < NUM_DESCRIPTORS; i++) {
			*(node_tx_desc_ptr + (i * 0x3) + 0x1) = (node_tx_buf_len & 0x7fffffff);
			*(node_rx_desc_ptr + (i * 0x3) + 0x1) = (node_rx_buf_len & 0xfff) | (1 << 31);
		}

		// populate results and find the optimum value of programming
		results[(l % 4)] = pass;
		if (((l % 4) == 3)) {
			lgst = find_value();
			if (lgst > old_lgst) {
				old_lgst = lgst;
				xmii_val = xmii[(l - 3) + find];
			}
		}
	}
#if DEBUG_1
	printf("TEST: FINAL REG VAL after TX Calibration - 0x%08x\n", xmii_val);
#endif
	tx_fix = xmii_val;

	old_lgst = 0;

	// Using the previously arrived at value of TX Calib we calibrate RX DELAYS. For this we use RX DAT and EN Delays
	for (l = 0; l < 16; l++) {
		// initialize pass. this will be made zero if there is a failure in packet reception compare
		pass = 1;
		// fail due to checks in rx etc. this is not the same as !pass
		fail = 0;
		rddata = ath_reg_rd(ETH_CFG_ADDRESS);
#if DEBUG
		printf("TEST: Initial ETH_CFG - 0x%08x\n", rddata);
#endif

		// RXD_DELAY  - l / 4 -> 0, 1, 2, 3
		// RXEN_DELAY - l / 4 -> 0, 1, 2, 3
		// RX_DELAY   - l & 3 -> 0, 1, 2, 3
		ath_reg_rmw_clear(ETH_CFG_ADDRESS,
					ETH_CFG_ETH_RXDV_DELAY_MASK |
					ETH_CFG_ETH_RXD_DELAY_MASK);
		ath_reg_rmw_set(ETH_CFG_ADDRESS,
					ETH_CFG_ETH_RXDV_DELAY_SET(l / 4) |
					ETH_CFG_ETH_RXD_DELAY_SET(l / 4));
		rddata = ath_reg_rd(ETH_CFG_ADDRESS);
#if DEBUG
		printf("TEST: ETH_CFG - 0x%08x\n", rddata);
#endif
		eth_cfg[l] = rddata;
		rddata = tx_fix | ETH_XMII_RX_DELAY_SET(l);
		ath_reg_wr(ETH_XMII_ADDRESS, rddata);

		xmii[l] = rddata;

		// counts when to print out counter stats
		k++;
		// Set Up Receive Descriptor Table
		node_rx_buf_len = 0x0;
		ath_gmac_reg_wr(mac, ATH_DMA_RX_CTRL, 0x1);	// enable dma rx
		ath_gmac_reg_wr(mac, ATH_DMA_TX_CTRL, 0x1);	// enable dma tx

		rddata = (*(node_tx_desc_ptr + (NUM_DESCRIPTORS - 1) * 0x3 + 0x1) & (1 << 31));
		while (rddata != (1 << 31))
			rddata = (*(node_tx_desc_ptr + (NUM_DESCRIPTORS - 1) * 0x3 + 0x1) & (1 << 31));
#if DEBUG
		printf("TEST: Tx Done \n");
#endif

		to = 0;
		rddata = (*(node_rx_desc_ptr + (NUM_DESCS - 1) * 0x3 + 0x1) & (1 << 31));
		while (rddata != 0x0) {
			rddata = (*(node_rx_desc_ptr + (NUM_DESCS - 1) * 0x3 + 0x1) & (1 << 31));
			to++;
			if (to > 100000) {
#if DEBUG
				printf("TEST: ERROR!! Atleast 1 packet in GE0 not seen.\n");
#endif
				// This check for RX.
				pass = 0;
				fail = 1;
				break;
			}
		}
#if DEBUG
		printf("TEST: Rx Done \n");
#endif

		if (k % 1 == 0) {
			for (j = GE0_PEMSTAT_RBYT; j <= GE0_PEMSTAT_RDRP; j = j + 4) {
				rddata = ath_reg_rd(j);
				switch (j) {
#if DEBUG
				case GE0_PEMSTAT_RPKT:
					printf("TEST: RPKT 0x%08x\n", rddata);
					break;
				case GE0_PEMSTAT_TPKT:
					printf("TEST: TPKT 0x%08x\n", rddata);
					break;
#endif
				}
			}
#if DEBUG
#ifdef ATH_S17_MAC0_SGMII
			s17_rx_pkt = athrs17_reg_read(0x163c) + (athrs17_reg_read(0x1640) << 16);
#else
			s17_rx_pkt = athrs17_reg_read(0x103c) + (athrs17_reg_read(0x1040) << 16);
#endif
			printf("TEST: RPKT in S17 0x%08x\n", s17_rx_pkt);
#endif
#ifdef ATH_S17_MAC0_SGMII
			s17_tx_pkt = athrs17_reg_read(0x1684) + (athrs17_reg_read(0x1688) << 16);
#else
			s17_tx_pkt = athrs17_reg_read(0x1084) + (athrs17_reg_read(0x1088) << 16);
#endif
#if DEBUG
			printf("TEST: TPKT in S17 0x%08x\n", s17_tx_pkt);
#endif
			// Compare BYTES in TX
			if (s17_tx_pkt != 0x410) {
#if DEBUG
				printf("TEST: PKTS @ S17 - 0x%08x\n", rddata);
#endif
				pass = 0;
				fail = 1;
			}

		}
		if (fail == 0) {
			error = pkt_compare_data();
		}
		if (error == 0) {
			//printf("TEST: PACKET COMPARISON PASS\n");
		} else {
#if DEBUG
			printf("TEST: ERROR!! PACKET COMPARISON FAIL\n");
#endif
			fail = 1;
			// Different from TX. This ensures packets are received back properly for a valid config.
			pass = 0;
		}

		for (i = 0; i < NUM_DESCRIPTORS; i++) {
			*(node_tx_desc_ptr + (i * 0x3) + 0x1) = (node_tx_buf_len & 0x7fffffff);
			*(node_rx_desc_ptr + (i * 0x3) + 0x1) = (node_rx_buf_len & 0xfff) | (1 << 31);
		}

		// populate results and find the optimum value of programming
		// For every set of 4 configurations find longest valid configs and number.
		results[(l % 4)] = pass;
		if (((l % 4) == 3)) {
			lgst = find_value();
			if (lgst > old_lgst) {
				old_lgst = lgst;
				xmii_val = xmii[(l - 3) + find];
				eth_cfg_val = eth_cfg[(l - 3) + find];
			}
		}
	}
	// And write to these registers.
#if DEBUG_1
	printf("TEST: FINAL XMII VAL after RX Calibration - 0x%08x\n", xmii_val);
#endif
	ath_reg_wr(ETH_XMII_ADDRESS, xmii_val);
#if DEBUG_1
	printf("TEST: FINAL ETH_CFG VAL after RX Calibration - 0x%08x\n", eth_cfg_val);
#endif
	ath_reg_wr(ETH_CFG_ADDRESS, eth_cfg_val);
	ath_gmac_reg_wr(mac,ATH_MAC_CFG1,1<<31);

}

#endif /* #ifdef RGMII_CAL */

void athr_gmac_xmii_mac_setup(ath_gmac_softc_t * mac)
{
#ifdef AP136_BOOTROM_TGT
  unsigned int rddata ;
#endif

	athrs_rgmii_cal(mac);

#ifdef AP136_BOOTROM_TGT
	ath_reg_wr(SWITCH_CLOCK_SPARE_ADDRESS , 0x520); //MDC source clock select

	ath_reg_wr(SGMII_SERDES_ADDRESS ,0x18870016);
	udelay(10);
	ath_reg_wr(ETH_SGMII_SERDES_ADDRESS ,0x7);
	udelay(10);

	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_ETH_SGMII_ARESET_SET(1));
	udelay(10);

	//GE0/GE1 MDIO,SGMII ARESET,SGMII RESET
	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_ETH_SGMII_RESET_SET(1)
					| RST_RESET_GE0_MDIO_RESET_SET(1)
					| RST_RESET_GE1_MDIO_RESET_SET(1));
	udelay(20);

	// GIGE Enable
	ath_reg_wr(ETH_XMII_ADDRESS ,0xA6000000);

	// Waiting for SGMII Lock Detect
	rddata = ath_reg_rd(SGMII_SERDES_ADDRESS);
	printf("WAIT FOR SGMII LOCK DETECT ");
	while ((rddata &0x8000)!= 0x8000){
		rddata = ath_reg_rd(SGMII_SERDES_ADDRESS);
		printf("#");
	}
	printf("\n");
	udelay(10);

	// MAC INITS
	// RGMII Enable on GE0
	//ath_reg_wr(0xb8070000, 0x3c001);
	ath_reg_wr(GMAC_MII0_CTRL, 0x3c001);

	rddata = ath_reg_rd(RST_RESET_ADDRESS);
	ath_reg_wr(RST_RESET_ADDRESS ,(rddata &  ~(1<<9))); // Bringing GE0 out of RESET
	ath_gmac_reg_wr(mac, ATH_MAC_CFG2 ,0x7235);  //for 1000mbps
	//reg_write(GE0_MAC_CONFIG_2,0x7135);  //for 100mbps
	ath_gmac_reg_wr(mac, ATH_MAC_IFCTL, 0x00000);
	ath_gmac_reg_wr(mac, ATH_MAC_CFG1, 0x005 );
	//reg_write(GE0_MAC_CONFIG_1,0x105);  // For MAC Loopback
	ath_gmac_reg_wr(mac, ATH_DMA_INTR_MASK, 0xDB); // Disable interrupt mask
	//ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR1,0x003fffff);  //ethernet mac address
	ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR1,0xAAAAAAAA );  //ethernet mac address
	//ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR2, 0xfffe0000);  //ethernet mac address
	ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR2, 0xAAAA0000 );  //ethernet mac address
	ath_gmac_reg_wr(mac, ATH_MAC_MII_MGMT_CFG, 0x6);  //clock/20= 2MHz
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_0, 0x1f00);  // Enable the FIFO modules
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_1, 0x10ffff);
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_3, 0x1f00140);
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_4, 0x1000);
	//reg_write(GE0_FIFO_CFG_REG_5, 0xbefff); //enable drop
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_5, 0xfffff);  //for 1000Mbps
	//reg_write(GE0_FIFO_CFG_REG_5, 0x7ffff);//for 100Mbps
	ath_gmac_reg_wr(mac, ATH_DMA_INTR_MASK, 0xDB); // Disable interrupt mask

#else // AP136_BOOTROM_TGT

	ath_gmac_reg_wr(mac, ATH_MAC_CFG2, 0x7235);   //Enable MII/GMII Interface  (1000 mbps) ..Full duplex

	ath_gmac_reg_wr(mac, ATH_MAC_IFCTL, 0x00000);

	ath_gmac_reg_wr(mac, ATH_MAC_CFG1, 0x0000003f);   // for 1000 mbps mode

	ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR1, 0xAAAAAAAA); //ethernet mac address
	ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR2, 0xAAAA0000); //ethernet mac address

	ath_gmac_reg_wr(mac, ATH_MAC_MII_MGMT_CFG, 0x6);

	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_0, 0x001d1f00); // Enable the FIFO modules

	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_1, 0x10ffff);
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_2, 0x015500aa); /*for 1000 mbps mode */
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_3, 0x1f00140);

	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_4, 0x3ffff); /*for 1000 mbps */

	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_5, 0xe6b82); /*for 1000 mbps mode */

	ath_reg_wr(ETH_CFG_ADDRESS, ETH_CFG_ETH_TXEN_DELAY_SET(3) |
					ETH_CFG_ETH_TXD_DELAY_SET(3) |
					ETH_CFG_RGMII_GE0_SET(1));

	ath_reg_wr(ETH_XMII_ADDRESS, ETH_XMII_TX_INVERT_SET(1) |
					ETH_XMII_GIGE_SET(1));
#endif
}
#else
void athr_gmac_xmii_mac_setup(ath_gmac_softc_t * mac)
{
	ath_gmac_reg_wr(mac, ATH_MAC_CFG1, 0x5);   // Transmit & receive Enable, 8th bit for Loopback enable

	ath_gmac_reg_wr(mac, ATH_MAC_CFG2, 0x7135);   //Enable MII/GMII Interface  (10 -> MII) ..Full duplex

	ath_gmac_reg_wr(mac, ATH_MAC_IFCTL, 0x00000);

	ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR1, 0xAAAAAAAA); //ethernet mac address
	ath_gmac_reg_wr(mac, ATH_GE_MAC_ADDR1, 0xAAAA0000); //ethernet mac address

	// ath_gmac_reg_wr(mac, ATH_MAC_MII_MGMT_CFG, 0x7); //changed,not required in the slave mode operation.

	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_0, 0x1f00); // Enable the FIFO modules
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_1, 0x10ffff);
	// --	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_2, 0x015500aa);
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_3, 0x1f00140);
	// --ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_4, 0x1010);
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_4, 0x3ffff);
	// ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_5, 0xbefef);
	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_5, 0x3efff);	// changed from befff
	// --	ath_gmac_reg_wr(mac, ATH_MAC_FIFO_CFG_5, 0x66b82);

#define mii_100_mode    0
#define rgmii_100_mode  !mii_100_mode

#if rgmii_100_mode
#	define ATH_ETH_CFG_VAL		ETH_CFG_RGMII_GE0_SET(1)
#	define ATH_ETH_XMII_VAL		ETH_XMII_TX_INVERT_SET(1) | \
					ETH_XMII_RX_DELAY_SET(3)
#elif mii_100_mode
#	define ATH_ETH_CFG_VAL		ETH_CFG_MII_CNTL_SPEED_SET(1) | \
					ETH_CFG_MII_GE0_MASTER_SET(1) | \
					ETH_CFG_MII_GE0_SET(1)
#	define ATH_ETH_XMII_VAL		ETH_XMII_PHASE0_COUNT_SET(1) | \
					ETH_XMII_PHASE1_COUNT_SET(1)
#else
#	error	"Invalid mode setting"
#endif

	ath_reg_wr(ETH_CFG_ADDRESS, ATH_ETH_CFG_VAL);

	printf("0x%x = 0x%x\n", ETH_CFG_ADDRESS, ATH_ETH_CFG_VAL);

#if !CONFIG_ATH_EMULATION
#if mii_100_mode
	ath_reg_wr(ETH_XMII_ADDRESS, ETH_XMII_PHASE1_COUNT_SET(1) |
					ETH_XMII_PHASE0_COUNT_SET(1));
	printf("0x%x = 0x%x\n", ETH_XMII_ADDRESS, ETH_XMII_PHASE1_COUNT_SET(1) |
					ETH_XMII_PHASE0_COUNT_SET(1));
#endif	// mii_100_mode
#endif	// CONFIG_ATH_EMULATION
}
#endif

static void ath_gmac_hw_start(ath_gmac_softc_t * mac)
{
#if CONFIG_ATH_EMULATION
	u32 mask;

	ath_reg_wr(GPIO_FUNCTION_ADDRESS, 0x2);	// disable jtag

	//mask = ath_reg_rd(GPIO_OUT_FUNCTION1_ADDRESS);
	//ath_reg_wr(GPIO_OUT_FUNCTION1_ADDRESS, (mask & ~(0xff << 16)));
	ath_reg_rmw_clear(GPIO_OUT_FUNCTION1_ADDRESS,
		GPIO_OUT_FUNCTION1_ENABLE_GPIO_6_MASK);

	mask = ath_reg_rd(GPIO_OE_ADDRESS);
	ath_reg_wr(GPIO_OE_ADDRESS, (mask | 0x4));

	mask = ath_reg_rd(GPIO_OUT_ADDRESS);
	ath_reg_wr(GPIO_OUT_ADDRESS, mask | 0x4);
	udelay(10 * 1000);
	ath_reg_wr(GPIO_OUT_ADDRESS, mask & ~(0x4));
	udelay(10 * 1000);

	printf("Ethernet DCM out of reset\n");
#endif

#if defined(ATH_SGMII_DOWNLOAD) || defined(ROMBOOTDRV_SUPPORT_GMAC_1000M)
	athrs_sgmii_res_cal();
#endif

	athr_gmac_xmii_mac_setup(mac);

}

/*
 * For every command we re-setup the ring and start with clean h/w rx state
 */
static int ath_gmac_clean_rx(ath_gmac_softc_t * mac)
{

	int i;
	ath_gmac_desc_t *fr;
	mac->next_rx = 0;
	for (i = 0; i < MAX_RX_PKTS; i++) {
		fr = mac->fifo_rx[i];
		fr->pkt_start_addr = PHYSADDR(NetRxPackets[i]);
#if 0
		flush_cache((u32) NetRxPackets[i], MAX_PKT_SIZE);
#endif
		ath_gmac_rx_give_to_dma(fr);
	}

	ath_gmac_reg_wr(mac, ATH_DMA_RX_DESC, PHYSADDR(mac->fifo_rx[0]));
	ath_gmac_reg_wr(mac, ATH_DMA_RX_CTRL, ATH_RXE);	/* rx start */
	udelay(1000 * 1000);

	return 1;

}

ath_gmac_desc_t gmac_txfifo[MAX_TX_PKTS] __attribute__ ((aligned (PKT_ALIGN)));
ath_gmac_desc_t gmac_rxfifo[MAX_RX_PKTS] __attribute__ ((aligned (PKT_ALIGN)));

static int ath_gmac_setup_fifos(ath_gmac_softc_t * mac)
{
	int i;

	for (i = 0; i < MAX_TX_PKTS; i++) {
		mac->fifo_tx[i] = &gmac_txfifo[i];
		mac->fifo_tx[i]->next_desc = (i == MAX_TX_PKTS - 1) ?
		    PHYSADDR(mac->fifo_tx[0]) : PHYSADDR(&gmac_txfifo[i + 1]);
		ath_gmac_tx_own(mac->fifo_tx[i]);
	}

	for (i = 0; i < MAX_RX_PKTS; i++) {
		mac->fifo_rx[i] = &gmac_rxfifo[i];
		mac->fifo_rx[i]->next_desc = (i == MAX_RX_PKTS - 1) ?
		    PHYSADDR(mac->fifo_rx[0]) : PHYSADDR(&gmac_rxfifo[i + 1]);
		ath_gmac_rx_give_to_dma(mac->fifo_rx[i]);
	}

	return (1);
}

static void ath_gmac_halt(ath_gmac_softc_t * mac)
{
	ath_gmac_reg_wr(mac, ATH_DMA_RX_CTRL, 0);
	while (ath_gmac_reg_rd(mac, ATH_DMA_RX_CTRL));
}


int ath_gmac_gmac_initialize()
{
	u32 mac_h, mac_l, mask;
	a_uint8_t mac[6];

	printf("ath_gmac_gmac_initialize...\n");


	memset(&ath_gmac_mac, 0, sizeof(ath_gmac_mac));

	gmac_rom_read_mac(mac);

#ifdef AP136_BOOTROM_TGT
	ath_gmac_mac.mac_unit = 0;
	ath_gmac_mac.mac_base = ATH_GE0_BASE;
#else
	ath_gmac_mac.mac_unit = 1;
	ath_gmac_mac.mac_base = ATH_GE1_BASE;
#endif

#ifdef CONFIG_MACH_QCA955x
	// Put sgmii analog into reset
	ath_reg_rmw_set(RST_RESET_ADDRESS, RST_RESET_ETH_SGMII_ARESET_SET(1));
	udelay(10);

	// Enable PLL
	ath_reg_wr(ETH_SGMII_SERDES_ADDRESS,	ETH_SGMII_SERDES_EN_LOCK_DETECT_SET(1) |
						ETH_SGMII_SERDES_PLL_REFCLK_SEL_SET(1) |
						ETH_SGMII_SERDES_EN_PLL_SET(1));
	udelay(10);

	// VCO reg setting
	ath_reg_wr(SGMII_SERDES_ADDRESS,	SGMII_SERDES_CDR_BW_SET(3) |
						SGMII_SERDES_TX_DR_CTRL_SET(1) |
						SGMII_SERDES_PLL_BW_SET(1) |
						SGMII_SERDES_EN_SIGNAL_DETECT_SET(1) |
						SGMII_SERDES_FIBER_SDO_SET(1) |
						SGMII_SERDES_VCO_REG_SET(3) |
                				SGMII_SERDES_RES_CALIBRATION_SET(1));
	udelay(10);

	// Pull sgmii analog out of reset
	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_ETH_SGMII_ARESET_SET(1));
	udelay(10);

	ath_reg_rmw_set(RST_RESET_ADDRESS, RST_RESET_GE0_MAC_RESET_SET(1));
	udelay(1000 * 100);

	ath_reg_rmw_clear(RST_RESET_ADDRESS, RST_RESET_GE0_MAC_RESET_SET(1));
	udelay(1000 * 100);

	(void)mask;
#else
	mask = (AR7240_RESET_GE0_MAC | AR7240_RESET_GE0_PHY |
		AR7240_RESET_GE1_MAC | AR7240_RESET_GE1_PHY);

	ath_reg_rmw_set(RST_RESET_ADDRESS, mask);
	udelay(1000 * 100);

	ath_reg_rmw_clear(RST_RESET_ADDRESS, mask);
	udelay(1000 * 100);

	udelay(10 * 1000);
#endif
	ath_gmac_hw_start(&ath_gmac_mac);
	ath_gmac_setup_fifos(&ath_gmac_mac);

	udelay(100 * 1000);

#if 0
	printf("ge0: %02x:%02x:%02x:%02x:%02x:%02x\n",
		mac[0] & 0xff, mac[1] & 0xff, mac[2] & 0xff,
		mac[3] & 0xff, mac[4] & 0xff, mac[5] & 0xff);
#endif

	mac_h = (mac[4] << 24) | (mac[5] << 16);
	mac_l = (mac[0] << 24) | (mac[1] << 16) | (mac[2] << 8) | (mac[3] << 0);

	ath_gmac_reg_wr((&ath_gmac_mac), ATH_GE_MAC_ADDR1, mac_l);
	ath_gmac_reg_wr((&ath_gmac_mac), ATH_GE_MAC_ADDR2, mac_h);

	return 1;
}

a_status_t
__gmac_process_discv(ath_gmac_softc_t * mac, __gmac_softc_t * sc)
{
	a_status_t err = A_STATUS_OK;
	__gmac_hdr_t *buf_hdr;
	a_uint8_t *buf;
	ath_gmac_desc_t *f;

	f = mac->fifo_rx[mac->next_rx];

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

	/*
	 * Application should do the return_recv
	 */
	sc->indicate_pkt(NULL, vbuf, sc->htc_ctx);
#endif

	fwd_tgt_recv(mac, buf + GMAC_HLEN, f->pkt_size - (GMAC_HLEN + 4));

done:
	ath_gmac_rx_give_to_dma(f);

	if (++mac->next_rx >= MAX_RX_PKTS)
		mac->next_rx = 0;

	return err;
}

static int ath_gmac_check_recv(ath_gmac_softc_t * mac)
{
	ath_gmac_desc_t *f;

	f = mac->fifo_rx[mac->next_rx];
	if (ath_gmac_rx_owned_by_dma(f))
		return 0;

	return 1;
}

void
gmac_discover(ath_gmac_softc_t * mac)
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
			ath_gmac_send(mac, buf, GMAC_HLEN);

		__gmac_mdelay(GMAC_DISCV_WAIT);

#if 0
		if (dma_lib_xmit_done(DMA_ENGINE_TX0))
			buf = dma_lib_reap_xmitted(DMA_ENGINE_TX0);
#endif

		while (ath_gmac_check_recv(mac) && err)
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

	if (checksum == cksum)
		return A_STATUS_OK;
	else
		return A_STATUS_FAILED;
}

void fwd_tgt_recv(ath_gmac_softc_t * mac, a_uint8_t * rxbuf, int datalen)
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

	/* reach to the jump location */
	image++;
	eloc = *image;

	if (status == A_STATUS_OK)
		r->rsp = FWD_RSP_SUCCESS;
	else
		r->rsp = FWD_RSP_FAILED;

done:
#if 0
	HIF_send_buffer(fwd_sc.hif_handle, fwd_sc.tx_pipe, buf);
#endif

	ath_gmac_send(mac, buf, GMAC_HLEN + sizeof(fwd_rsp_t));

	ath_gmac_halt(mac);

	if (!more && (status == A_STATUS_OK)) {
		printf("\nimage receive completed.\n");
		if(eloc == 0) {
			/*
			 * eloc(execution address) is 0 means this is some data
			 * and CPU should not jump to the requested Address
			 */
			printf("\nThe last image received is not executable..");
			printf("Waiting to receive next image...\n");
		} else {
			/*
			 * Disable all interrupts. Else, kernel might get interrupts
			 * from here, before the driver is up and panic
			 */
			ath_gmac_reg_wr(mac, ATH_DMA_INTR_MASK, 0);
			/* Restore gpio state */
			ath_reg_wr(GPIO_OE_ADDRESS, 0x0026fb0b);
			printf("Calling 2nd stage\n");
			call_fw(1, eloc);
		}
	}
}

a_uint8_t gmac_rxbuf[MAX_RX_PKTS * MAX_RX_PKT_SIZE] __attribute__ ((aligned (PKT_ALIGN)));
a_uint8_t gmac_txbuf[MAX_TX_PKTS * MAX_TX_PKT_SIZE] __attribute__ ((aligned (PKT_ALIGN)));

void gmac_fwd_main(void)
{
	__gmac_softc_t *sc = &gmac_sc;
	int i;

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

	ath_gmac_gmac_initialize();

	gmac_rom_read_mac(sc->hdr.eth.src);

	ath_gmac_clean_rx(&ath_gmac_mac);

	gmac_discover(&ath_gmac_mac);

	while (1) {
		ath_gmac_fwd_recv(&ath_gmac_mac);
	}
}
