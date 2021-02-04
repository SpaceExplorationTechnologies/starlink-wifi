/* 
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
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
 * 
 */

#include <config.h>
#include <common.h>
#include <malloc.h>
#include <net.h>
#include <command.h>
#include <asm/io.h>
#include <asm/addrspace.h>
#include <asm/types.h>
#include "ar7240_soc.h"
#include "ag7240.h"
#include "ag7240_phy.h"

#if (CONFIG_COMMANDS & CFG_CMD_MII)
#include <miiphy.h>
#endif
#define ag7240_unit2mac(_unit)     ag7240_macs[(_unit)]
#define ag7240_name2mac(name)	   strcmp(name,"eth0") ? ag7240_unit2mac(1) : ag7240_unit2mac(0)

uint16_t ag7240_miiphy_read(char *devname, uint32_t phaddr,
	       uint8_t reg);
void  ag7240_miiphy_write(char *devname, uint32_t phaddr,
	        uint8_t reg, uint16_t data);

ag7240_mac_t *ag7240_macs[CFG_AG7240_NMACS];

extern int athrs26_phy_setup(int unit);
extern int athrs26_phy_is_up(int unit);
extern int athrs26_phy_is_fdx(int unit);
extern int athrs26_phy_speed(int unit);
extern void athrs26_reg_init(void);
extern void athrs26_reg_init_lan(void);
extern void ar7240_sys_frequency(u32 *cpu_freq, u32 *ddr_freq, u32 *ahb_freq);
extern int athrs26_mdc_check(void);

#ifdef CONFIG_HORNET_EMU
#include "hornet.h"

void ar8021_phy_setup(u32 ethUnit, u32 phyUnit);
uint32_t ar8021_phy_is_link_alive(u32 ethUnit, u32 phyUnit);
uint32_t ar8021_phy_is_fdx(u32 ethUnit, u32 phyUnit);
uint32_t ar8021_phy_speed(u32 ethUnit, u32 phyUnit);
#endif /* CONFIG_HORNET_EMU */

static int
ag7240_send(struct eth_device *dev, volatile void *packet, int length)
{
    int i;

    ag7240_mac_t *mac = (ag7240_mac_t *)dev->priv;

    ag7240_desc_t *f = mac->fifo_tx[mac->next_tx];

    f->pkt_size = length;
    f->res1 = 0;
    f->pkt_start_addr = virt_to_phys(packet);

    ag7240_tx_give_to_dma(f);
    flush_cache((u32) packet, length);
    ag7240_reg_wr(mac, AG7240_DMA_TX_DESC, virt_to_phys(f));
    ag7240_reg_wr(mac, AG7240_DMA_TX_CTRL, AG7240_TXE);

    for (i = 0; i < MAX_WAIT; i++) {
        udelay(10);
        if (!ag7240_tx_owned_by_dma(f))
            break;
    }
    if (i == MAX_WAIT)
        printf("Tx Timed out\n");

    f->pkt_start_addr = 0;
    f->pkt_size = 0;

    if (++mac->next_tx >= NO_OF_TX_FIFOS)
        mac->next_tx = 0;

    return (0);
}

static int ag7240_recv(struct eth_device *dev)
{
    int length;
    ag7240_desc_t *f;
    ag7240_mac_t *mac;

    mac = (ag7240_mac_t *)dev->priv;

    for (;;) {
        f = mac->fifo_rx[mac->next_rx];
        if (ag7240_rx_owned_by_dma(f))
            break;

        length = f->pkt_size;

        NetReceive(NetRxPackets[mac->next_rx] , length - 4);
        flush_cache((u32) NetRxPackets[mac->next_rx] , PKTSIZE_ALIGN);

        ag7240_rx_give_to_dma(f);

        if (++mac->next_rx >= NO_OF_RX_FIFOS)
            mac->next_rx = 0;
    }

    if (!(ag7240_reg_rd(mac, AG7240_DMA_RX_CTRL))) {
        ag7240_reg_wr(mac, AG7240_DMA_RX_DESC, virt_to_phys(f));
        ag7240_reg_wr(mac, AG7240_DMA_RX_CTRL, 1);
    }

    return (0);
}

static void ag7240_hw_start(ag7240_mac_t *mac)
{
    u32 cpu_freq,ddr_freq,ahb_freq;
    u32 mgmt_cfg_val;
    u32 check_cnt,revid_val;

    if(mac->mac_unit)
    {
        ag7240_reg_wr(mac, AG7240_MAC_CFG1, (AG7240_MAC_CFG1_RX_EN |
            AG7240_MAC_CFG1_TX_EN));
        ag7240_reg_rmw_set(mac, AG7240_MAC_CFG2, (AG7240_MAC_CFG2_PAD_CRC_EN |
            AG7240_MAC_CFG2_LEN_CHECK | AG7240_MAC_CFG2_IF_1000));
    }
    else {

    ag7240_reg_wr(mac, AG7240_MAC_CFG1, (AG7240_MAC_CFG1_RX_EN |
		    AG7240_MAC_CFG1_TX_EN));

    ag7240_reg_rmw_set(mac, AG7240_MAC_CFG2, (AG7240_MAC_CFG2_PAD_CRC_EN |
		         AG7240_MAC_CFG2_LEN_CHECK));
   }

#ifdef AR7240_EMU
    printf("AG7240_MAC_FIFO_CFG_4\n");
    ag7240_reg_rmw_set(mac, AG7240_MAC_FIFO_CFG_4, 0x3ffff);
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_1, 0x10ffff);
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_2, 0xAAA0555);
#else
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_1, 0xfff0000);
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_2, 0x1fff);
#endif
if ((ar7240_reg_rd(AR7240_REV_ID) & AR7240_REV_ID_MASK) == AR7240_REV_1_2) {
        mgmt_cfg_val = 0x2;
        if (mac->mac_unit == 0) {
            ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val | (1 << 31));
            ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val);
        }
    }
    else {
        ar7240_sys_frequency(&cpu_freq, &ddr_freq, &ahb_freq);
        switch (ahb_freq/1000000) {
            case 150:
                     mgmt_cfg_val = 0x7;
                     break;
            case 175:
                     mgmt_cfg_val = 0x5;
                     break;
            case 200:
                     mgmt_cfg_val = 0x4;
                     break;
            case 210:
                      mgmt_cfg_val = 0x9;
                      break;
            case 220:
                      mgmt_cfg_val = 0x9;
                      break;
            default:
                     mgmt_cfg_val = 0x7;
        }
        if ((is_ar7241() || is_ar7242())) {

            /* External MII mode */
            if (mac->mac_unit == 0 && is_ar7242()) {
                mgmt_cfg_val = 0x6;
                ar7240_reg_rmw_set(AG7240_ETH_CFG, AG7240_ETH_CFG_RGMII_GE0);
                ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val | (1 << 31));
                ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val);
            }
#ifndef CONFIG_HORNET_EMU
            /* Virian */
            mgmt_cfg_val = 0x4;
            ag7240_reg_wr(ag7240_macs[1], AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val | (1 << 31));
            ag7240_reg_wr(ag7240_macs[1], AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val);
            printf("Virian MDC CFG Value ==> %x\n",mgmt_cfg_val);
#endif

        }
        else { /* Python 1.0 & 1.1 */
            if (mac->mac_unit == 0) {
                check_cnt = 0;
                while (check_cnt++ < 10) {
                    ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val | (1 << 31));
                    ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val);
                    if(athrs26_mdc_check() == 0)
                        break;
                }
                if(check_cnt == 11)
                    printf("%s: MDC check failed\n", __func__);
            }
        }
    }
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_0, 0x1f00);

    ag7240_reg_rmw_set(mac, AG7240_MAC_FIFO_CFG_4, 0x3ffff);

    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_1, 0x10ffff);
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_2, 0xAAA0555);

    /* 
     * Setting Drop CRC Errors, Pause Frames,Length Error frames 
     * and Multi/Broad cast frames. 
     */

#ifdef CONFIG_HORNET_EMU
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_5, 0xbefff);
#else
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_5, 0x7eccf);
#endif

    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_3, 0x1f00140);

    printf(": cfg1 %#x cfg2 %#x\n", ag7240_reg_rd(mac, AG7240_MAC_CFG1),
        ag7240_reg_rd(mac, AG7240_MAC_CFG2));

}

static int ag7240_check_link(ag7240_mac_t *mac)
{
    u32 link, duplex, speed, fdx;

#ifdef CONFIG_HORNET_EMU
    link   = ar8021_phy_is_link_alive(0, GE0_AR8021_PHY_ADDR);
    duplex = ar8021_phy_is_fdx(0, GE0_AR8021_PHY_ADDR);
    speed  = ar8021_phy_speed(0, GE0_AR8021_PHY_ADDR);
#else
    ag7240_phy_link(mac->mac_unit, &link);
    ag7240_phy_duplex(mac->mac_unit, &duplex);
    ag7240_phy_speed(mac->mac_unit, &speed);
#endif

    mac->link = link;
#ifdef SUPPORT_PLC
    if(strcmp(mac->dev->name, "eth0") == 0) {
        printf("ag7240_check_link: %s link forced down\n",mac->dev->name);
        return 0;
    }
#endif

    if(!mac->link) {
        printf("%s link down\n",mac->dev->name);
        return 0;
    }

    switch (speed)
    {
       case _1000BASET:
           ag7240_set_mac_if(mac, 1);
           ag7240_reg_rmw_set(mac, AG7240_MAC_FIFO_CFG_5, (1 << 19));
           if (is_ar7242() && (mac->mac_unit == 0))
               ar7240_reg_wr(AR7242_ETH_XMII_CONFIG,0x1c000000);
           break;

       case _100BASET:
           ag7240_set_mac_if(mac, 0);
           ag7240_set_mac_speed(mac, 1);
           ag7240_reg_rmw_clear(mac, AG7240_MAC_FIFO_CFG_5, (1 << 19));
#ifndef CONFIG_HORNET_EMU
           if (is_ar7242() && (mac->mac_unit == 0))
               ar7240_reg_wr(AR7242_ETH_XMII_CONFIG,0x0101);
#endif
           break;

       case _10BASET:
           ag7240_set_mac_if(mac, 0);
           ag7240_set_mac_speed(mac, 0);
           ag7240_reg_rmw_clear(mac, AG7240_MAC_FIFO_CFG_5, (1 << 19));
           if (is_ar7242() && (mac->mac_unit == 0))
               ar7240_reg_wr(AR7242_ETH_XMII_CONFIG,0x1616);
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

    ag7240_set_mac_duplex(mac,duplex);

    return 1;
}

/*
 * For every command we re-setup the ring and start with clean h/w rx state
 */
static int ag7240_clean_rx(struct eth_device *dev, bd_t * bd)
{

    int i;
    ag7240_desc_t *fr;
    ag7240_mac_t *mac = (ag7240_mac_t*)dev->priv;

    if (!ag7240_check_link(mac))
        return 0;

    mac->next_rx = 0;
    for (i = 0; i < NO_OF_RX_FIFOS; i++) {
        fr = mac->fifo_rx[i];
        fr->pkt_start_addr = virt_to_phys(NetRxPackets[i]);
        flush_cache((u32) NetRxPackets[i], PKTSIZE_ALIGN);
        ag7240_rx_give_to_dma(fr);
    }

    ag7240_reg_wr(mac, AG7240_DMA_RX_DESC, virt_to_phys(mac->fifo_rx[0]));
    ag7240_reg_wr(mac, AG7240_DMA_RX_CTRL, AG7240_RXE);	/* rx start */
    udelay(1000 * 1000);


    return 1;

}

static int ag7240_alloc_fifo(int ndesc, ag7240_desc_t ** fifo)
{
    int i;
    u32 size;
    uchar *p = NULL;

    size = sizeof(ag7240_desc_t) * ndesc;
    size += CFG_CACHELINE_SIZE - 1;

    if ((p = malloc(size)) == NULL) {
        printf("Cant allocate fifos\n");
        return -1;
    }

    p = (uchar *) (((u32) p + CFG_CACHELINE_SIZE - 1) &
	   ~(CFG_CACHELINE_SIZE - 1));
    p = UNCACHED_SDRAM(p);

    for (i = 0; i < ndesc; i++)
        fifo[i] = (ag7240_desc_t *) p + i;

    return 0;
}

static int ag7240_setup_fifos(ag7240_mac_t *mac)
{
    int i;

    if (ag7240_alloc_fifo(NO_OF_TX_FIFOS, mac->fifo_tx))
        return 1;

    for (i = 0; i < NO_OF_TX_FIFOS; i++) {
        mac->fifo_tx[i]->next_desc = (i == NO_OF_TX_FIFOS - 1) ?
            virt_to_phys(mac->fifo_tx[0]) : virt_to_phys(mac->fifo_tx[i + 1]);
        ag7240_tx_own(mac->fifo_tx[i]);
    }

    if (ag7240_alloc_fifo(NO_OF_RX_FIFOS, mac->fifo_rx))
        return 1;

    for (i = 0; i < NO_OF_RX_FIFOS; i++) {
        mac->fifo_rx[i]->next_desc = (i == NO_OF_RX_FIFOS - 1) ?
            virt_to_phys(mac->fifo_rx[0]) : virt_to_phys(mac->fifo_rx[i + 1]);
    }

    return (1);
}

static void ag7240_halt(struct eth_device *dev)
{
    ag7240_mac_t *mac = (ag7240_mac_t *)dev->priv;
    ag7240_reg_wr(mac, AG7240_DMA_RX_CTRL, 0);
    while (ag7240_reg_rd(mac, AG7240_DMA_RX_CTRL));
}

unsigned char *
ag7240_mac_addr_loc(void)
{
	extern flash_info_t flash_info[];

#ifdef BOARDCAL
    /*
    ** BOARDCAL environmental variable has the address of the cal sector
    */
    
    return ((unsigned char *)BOARDCAL);
    
#else
	/* MAC address is store in the 2nd 4k of last sector */
	return ((unsigned char *)
		(KSEG1ADDR(AR7240_SPI_BASE) + (4 * 1024) +
		flash_info[0].size - (64 * 1024) /* sector_size */ ));
#endif
}

static void ag7240_get_ethaddr(struct eth_device *dev)
{
    unsigned char *eeprom;
    unsigned char *mac = dev->enetaddr;

    eeprom = ag7240_mac_addr_loc();

    if (strcmp(dev->name, "eth0") == 0) {
        memcpy(mac, eeprom, 6);
    } else if (strcmp(dev->name, "eth1") == 0) {
        eeprom += 6;
        memcpy(mac, eeprom, 6);
    } else {
        printf("%s: unknown ethernet device %s\n", __func__, dev->name);
        return;
    }

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
        printf("Fetching MAC Address from 0x%p\n", __func__, eeprom);
    }
}


int ag7240_enet_initialize(bd_t * bis)
{
    struct eth_device *dev[CFG_AG7240_NMACS];
    u32 mask, mac_h, mac_l;
    int i;

    printf("ag7240_enet_initialize...\n");

#ifdef CONFIG_MACH_HORNET
    ar7240_reg_wr(HORNET_BOOTSTRAP_STATUS, ar7240_reg_rd(HORNET_BOOTSTRAP_STATUS) & ~HORNET_BOOTSTRAP_MDIO_SLAVE_MASK);
#endif

    for (i = 0;i < CFG_AG7240_NMACS;i++) {

    if ((dev[i] = (struct eth_device *) malloc(sizeof (struct eth_device))) == NULL) {
        puts("malloc failed\n");
        return 0;
    }
	
    if ((ag7240_macs[i] = (ag7240_mac_t *) malloc(sizeof (ag7240_mac_t))) == NULL) {
        puts("malloc failed\n");
        return 0;
    }

    memset(ag7240_macs[i], 0, sizeof(ag7240_macs[i]));
    memset(dev[i], 0, sizeof(dev[i]));

    sprintf(dev[i]->name, "eth%d", i);
    ag7240_get_ethaddr(dev[i]);
    
    ag7240_macs[i]->mac_unit = i;
    ag7240_macs[i]->mac_base = i ? AR7240_GE1_BASE : AR7240_GE0_BASE ;
    ag7240_macs[i]->dev = dev[i];

    dev[i]->iobase = 0;
    dev[i]->init = ag7240_clean_rx;
    dev[i]->halt = ag7240_halt;
    dev[i]->send = ag7240_send;
    dev[i]->recv = ag7240_recv;
    dev[i]->priv = (void *)ag7240_macs[i];
    }
    for (i = 0;i < CFG_AG7240_NMACS;i++) {

    eth_register(dev[i]);

#if (CONFIG_COMMANDS & CFG_CMD_MII)
    miiphy_register(dev[i]->name, ag7240_miiphy_read, ag7240_miiphy_write);
#endif
    if(!i) {
        mask = (AR7240_RESET_GE0_MAC | AR7240_RESET_GE0_PHY |
                AR7240_RESET_GE1_MAC | AR7240_RESET_GE1_PHY);

    if ((is_ar7241() || is_ar7242())) 
	mask = mask | AR7240_RESET_GE0_MDIO | AR7240_RESET_GE1_MDIO;


        ar7240_reg_rmw_set(AR7240_RESET, mask);
        udelay(1000 * 100);

        ar7240_reg_rmw_clear(AR7240_RESET, mask);
        udelay(1000 * 100);

    udelay(10 * 1000);
    }
    ag7240_hw_start(ag7240_macs[i]);
    ag7240_setup_fifos(ag7240_macs[i]);

    udelay(100 * 1000);

    {
        unsigned char *mac = dev[i]->enetaddr;

        printf("%s: %02x:%02x:%02x:%02x:%02x:%02x\n", dev[i]->name,
               mac[0] & 0xff, mac[1] & 0xff, mac[2] & 0xff,
               mac[3] & 0xff, mac[4] & 0xff, mac[5] & 0xff);
    }
    mac_l = (dev[i]->enetaddr[4] << 8) | (dev[i]->enetaddr[5]);
    mac_h = (dev[i]->enetaddr[0] << 24) | (dev[i]->enetaddr[1] << 16) |
        (dev[i]->enetaddr[2] << 8) | (dev[i]->enetaddr[3] << 0);

    ag7240_reg_wr(ag7240_macs[i], AG7240_GE_MAC_ADDR1, mac_l);
    ag7240_reg_wr(ag7240_macs[i], AG7240_GE_MAC_ADDR2, mac_h);

    /* if using header for register configuration, we have to     */
    /* configure s26 register after frame transmission is enabled */

#ifdef CONFIG_HORNET_EMU
    ar8021_phy_setup(0, GE0_AR8021_PHY_ADDR);
#else
    if (ag7240_macs[i]->mac_unit == 0) { /* WAN Phy */
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
#endif
    printf("%s up\n",dev[i]->name);
    }

    return 1;
}

#if (CONFIG_COMMANDS & CFG_CMD_MII)
uint16_t
ag7240_miiphy_read(char *devname, uint32_t phy_addr, uint8_t reg)
{
    ag7240_mac_t *mac   = ag7240_name2mac(devname);
    uint16_t      addr  = (phy_addr << AG7240_ADDR_SHIFT) | reg, val;
    volatile int           rddata;
    uint16_t      ii = 0x1000;

    ag7240_reg_wr(mac, AG7240_MII_MGMT_CMD, 0x0);
    ag7240_reg_wr(mac, AG7240_MII_MGMT_ADDRESS, addr);
    ag7240_reg_wr(mac, AG7240_MII_MGMT_CMD, AG7240_MGMT_CMD_READ);

    do
    {
        udelay(5);
        rddata = ag7240_reg_rd(mac, AG7240_MII_MGMT_IND) & 0x1;
    }while(rddata && --ii);

    val = ag7240_reg_rd(mac, AG7240_MII_MGMT_STATUS);
    ag7240_reg_wr(mac, AG7240_MII_MGMT_CMD, 0x0);

    return val;
}

void
ag7240_miiphy_write(char *devname, uint32_t phy_addr, uint8_t reg, uint16_t data)
{
    ag7240_mac_t *mac = ag7240_name2mac(devname);
    uint16_t      addr  = (phy_addr << AG7240_ADDR_SHIFT) | reg;
    volatile int rddata;
    uint16_t      ii = 0x1000;

    ag7240_reg_wr(mac, AG7240_MII_MGMT_ADDRESS, addr);
    ag7240_reg_wr(mac, AG7240_MII_MGMT_CTRL, data);

    do
    {
        rddata = ag7240_reg_rd(mac, AG7240_MII_MGMT_IND) & 0x1;
    }while(rddata && --ii);
}
#endif		/* CONFIG_COMMANDS & CFG_CMD_MII */

#ifdef CONFIG_HORNET_EMU
void
ar8021_phy_setup(u32 ethUnit, u32 phyUnit)
{
    uint32_t phyid1, phyid2;

    phyid1 = ag7240_miiphy_read(ag7240_unit2name(ethUnit), phyUnit, 0x2);
    phyid2 = ag7240_miiphy_read(ag7240_unit2name(ethUnit), phyUnit, 0x3);

    printf("%s Phy ID %x:%x\n", __FUNCTION__, phyid1, phyid2);

    udelay(1000*1000);

    ar7240_reg_rmw_set(AR7240_GPIO_BASE, 0x20);
    ar7240_reg_rmw_set(AR7240_GPIO_BASE + 0x8, 0x20);

    udelay(1000*1000);
    ar7240_reg_rmw_clear(AR7240_GPIO_BASE + 0x8, 0x20);

    udelay(1000*1000);
}

uint32_t
ar8021_phy_is_link_alive(u32 ethUnit, u32 phyUnit)
{
    uint32_t phyHwStatus;

    phyHwStatus = ag7240_miiphy_read(ag7240_unit2name(ethUnit), phyUnit, 0x11);

    if (phyHwStatus & ATHR_STATUS_LINK_PASS)
       return 1;

    return 0;
}

uint32_t
ar8021_phy_speed(uint32_t ethUnit, uint32_t phyUnit)
{
    uint32_t phyHwStatus;

    phyHwStatus = ag7240_miiphy_read(ag7240_unit2name(ethUnit), phyUnit, 0x11);

    {
        phyHwStatus = ((phyHwStatus & ATHER_STATUS_LINK_MASK) >>
                       ATHER_STATUS_LINK_SHIFT);

        switch(phyHwStatus) {
        case 0:
            return _10BASET;
        case 1:
            return _100BASET;
        case 2:
            return _1000BASET;
        default:
            printf("Unkown speed read!\n");
        }
    }

    return _10BASET;
}

uint32_t
ar8021_phy_is_fdx(u32 ethUnit, u32 phyUnit)
{
    uint32_t phyHwStatus;

    phyHwStatus = ag7240_miiphy_read(ag7240_unit2name(ethUnit), phyUnit, 0x11);

    if (phyHwStatus & ATHER_STATUS_FULL_DEPLEX)
       return 1;

    return 0;
}
#endif /* CONFIG_HORNET_EMU */
