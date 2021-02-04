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
extern void ar7240_sys_frequency(u32 *cpu_freq, u32 *ddr_freq, u32 *ahb_freq);

#ifdef CFG_ATHRS26_PHY
extern int athrs26_phy_setup(int unit);
extern int athrs26_phy_is_up(int unit);
extern int athrs26_phy_is_fdx(int unit);
extern int athrs26_phy_speed(int unit);
extern void athrs26_reg_init(void);
extern void athrs26_reg_init_lan(void);
extern int athrs26_mdc_check(void);
#endif

#ifdef CFG_ATHRS27_PHY
extern int athrs27_phy_setup(int unit);
extern int athrs27_phy_is_up(int unit);
extern int athrs27_phy_is_fdx(int unit);
extern int athrs27_phy_speed(int unit);
extern void athrs27_reg_init(void);
extern void athrs27_reg_init_lan(void);
extern int athrs27_mdc_check(void);
#endif

#ifdef CONFIG_F1E_PHY
extern int athr_phy_setup(int unit);
extern int athr_phy_is_up(int unit);
extern int athr_phy_is_fdx(int unit);
extern int athr_phy_speed(int unit);
extern void athr_reg_init(void);
#endif

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

void ag7240_mii_setup(ag7240_mac_t *mac)
{
    u32 mgmt_cfg_val;
    u32 cpu_freq,ddr_freq,ahb_freq;
    u32 check_cnt;
#ifdef CFG_ATHRS27_PHY
    if (is_wasp()) {
        printf("WASP ----> S27 PHY \n");
        mgmt_cfg_val = 2;
        ar7240_reg_wr(0xb8050024, 0x271);	// 25MHz ref clock
        //ar7240_reg_wr(0xb8050024, 0x570);	// 40MHz ref clock
        ag7240_reg_wr(ag7240_macs[1], AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val | (1 << 31));
        ag7240_reg_wr(ag7240_macs[1], AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val);
        return;
    }
#endif
#ifdef CONFIG_AR7242_S16_PHY
    if (is_wasp()) {
        printf("WASP  ----> S16 PHY *\n");
        mgmt_cfg_val = 4;
        if(mac->mac_unit == 0)
            ar7240_reg_wr(AG7240_ETH_CFG, AG7240_ETH_CFG_RGMII_GE0);

        ar7240_reg_rmw_clear(AG7240_ETH_SWITCH_CLK_SPARE, (1 << 6));
        ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val | (1 << 31));
        ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val);

        return;
    }
#endif
#ifdef CONFIG_F1E_PHY
    if (is_wasp()) {
        printf("WASP  ----> F1 PHY *\n");
        mgmt_cfg_val = 6;
        if(mac->mac_unit == 0)
            ar7240_reg_wr(AG7240_ETH_CFG, AG7240_ETH_CFG_RGMII_GE0);

        ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val | (1 << 31));
        ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val);

        return;
    }
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
            /* Virian */
            mgmt_cfg_val = 0x4;
            ag7240_reg_wr(ag7240_macs[1], AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val | (1 << 31));
            ag7240_reg_wr(ag7240_macs[1], AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val);
            printf("Virian MDC CFG Value ==> %x\n",mgmt_cfg_val);

        }
      else if(is_ar933x()){
                //GE0 receives Rx/Tx clock, and use S26 phy
                ar7240_reg_rmw_set(AG7240_ETH_CFG, AG7240_ETH_CFG_MII_GE0_SLAVE);
                mgmt_cfg_val = 0xF;
                if (mac->mac_unit == 1) {
                        check_cnt = 0;
                        while (check_cnt++ < 10) {
                                ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val | (1 << 31));
                                ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val);
#ifdef CFG_ATHRS26_PHY
                                if(athrs26_mdc_check() == 0)
                                        break;
#endif
                        }
                        if(check_cnt == 11)
                                printf("%s: MDC check failed\n", __func__);
                }
      }
        else { /* Python 1.0 & 1.1 */
             if (mac->mac_unit == 0) {
                     check_cnt = 0;
                     while (check_cnt++ < 10) {
                             ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val | (1 << 31));
                             ag7240_reg_wr(mac, AG7240_MAC_MII_MGMT_CFG, mgmt_cfg_val);
#ifdef CFG_ATHRS26_PHY
                             if(athrs26_mdc_check() == 0)
                                     break;
#endif
                     }
                     if(check_cnt == 11)
                             printf("%s: MDC check failed\n", __func__);
             }
        }
 
    }
}

static void ag7240_hw_start(ag7240_mac_t *mac)
{

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
		         AG7240_MAC_CFG2_LEN_CHECK | AG7240_MAC_CFG2_IF_10_100));
   }
   ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_0, 0x1f00);

   ag7240_mii_setup(mac);

    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_1, 0x10ffff);
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_2, 0xAAA0555);

    ag7240_reg_rmw_set(mac, AG7240_MAC_FIFO_CFG_4, 0x3ffff);
    /* 
     * Setting Drop CRC Errors, Pause Frames,Length Error frames 
     * and Multi/Broad cast frames. 
     */
#ifdef AG7240_BROADCAST_ENABLE
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_5, 0xe6be2);
#else
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_5, 0x7eccf);
#endif
    ag7240_reg_wr(mac, AG7240_MAC_FIFO_CFG_3, 0x1f00140);

    printf(": cfg1 %#x cfg2 %#x\n", ag7240_reg_rd(mac, AG7240_MAC_CFG1),
        ag7240_reg_rd(mac, AG7240_MAC_CFG2));

}

static int ag7240_check_link(ag7240_mac_t *mac)
{
    u32 link, duplex, speed;

    ag7240_phy_link(mac->mac_unit, (int *)&link);
    ag7240_phy_duplex(mac->mac_unit, (int *)&duplex);
    ag7240_phy_speed(mac->mac_unit, (int *)&speed);

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
           if (is_ar7242() && (mac->mac_unit == 0)) {
               ar7240_reg_wr(AR7242_ETH_XMII_CONFIG,0x1c000000);
	   }
#ifdef CONFIG_F1E_PHY
           if (is_wasp() && (mac->mac_unit == 0)) {
               ar7240_reg_wr(AR7242_ETH_XMII_CONFIG,0x0e000000);
	   }
#else      
           if (is_wasp() && (mac->mac_unit == 0)) {
               ar7240_reg_wr(AR7242_ETH_XMII_CONFIG,0x06000000);
           }
#endif
           break;

       case _100BASET:
           ag7240_set_mac_if(mac, 0);
           ag7240_set_mac_speed(mac, 1);
           ag7240_reg_rmw_clear(mac, AG7240_MAC_FIFO_CFG_5, (1 << 19));
           if ((is_ar7242() || is_wasp()) && (mac->mac_unit == 0))
               ar7240_reg_wr(AR7242_ETH_XMII_CONFIG,0x0101);
           break;

       case _10BASET:
           ag7240_set_mac_if(mac, 0);
           ag7240_set_mac_speed(mac, 0);
           ag7240_reg_rmw_clear(mac, AG7240_MAC_FIFO_CFG_5, (1 << 19));
           if ((is_ar7242() || is_wasp()) && (mac->mac_unit == 0))
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
    if(!is_ar933x())
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
#ifndef BOARDCAL
    extern flash_info_t flash_info[];
#endif

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
#ifndef CONFIG_AR7240_EMU
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
#else
    if (1) {
#endif 
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

    if(is_ar933x() ) {
        u32 rd = 0x0;

        /* 
         * To get s26 out of reset, we have to...
         * bit0~bit3: has to be deasserted
         * bit4:      has to be asserted
         */
        rd = ar7240_reg_rd(AR7240_S26_CLK_CTRL_OFFSET) & ~(0x1f);
        rd |= 0x10;
        ar7240_reg_wr(AR7240_S26_CLK_CTRL_OFFSET, rd);

        if(ar7240_reg_rd(AR7240_RESET)!=0)
            ar7240_reg_wr(AR7240_RESET,0);
    }

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
#if(CONFIG_COMMANDS & CFG_CMD_MII)
        miiphy_register(dev[i]->name, ag7240_miiphy_read, ag7240_miiphy_write);
#endif

         ag7240_reg_rmw_set(ag7240_macs[i], AG7240_MAC_CFG1, AG7240_MAC_CFG1_SOFT_RST
                | AG7240_MAC_CFG1_RX_RST | AG7240_MAC_CFG1_TX_RST);

        if(!i) {
           mask = (AR7240_RESET_GE0_MAC | AR7240_RESET_GE0_PHY |
                    AR7240_RESET_GE1_MAC | AR7240_RESET_GE1_PHY);

           if (is_ar7241() || is_ar7242() ||  is_wasp()) {
                mask = mask | AR7240_RESET_GE0_MDIO | AR7240_RESET_GE1_MDIO;
                printf(" wasp  reset mask:%x \n",mask);
           }


           ar7240_reg_rmw_set(AR7240_RESET, mask);
           if(!is_ar933x())
               udelay(1000 * 100);

           ar7240_reg_rmw_clear(AR7240_RESET, mask);
           if(!is_ar933x())
               udelay(1000 * 100);

           if(!is_ar933x())
               udelay(10 * 1000);
        }

        ag7240_hw_start(ag7240_macs[i]);
        ag7240_setup_fifos(ag7240_macs[i]);

        if(!is_ar933x())
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

        if (ag7240_macs[i]->mac_unit == 0) { /* WAN Phy */
#ifdef CONFIG_AR7242_S16_PHY
            if (is_ar7242() || is_wasp()) {
                athrs16_reg_init();
            } else
#endif
            {
#ifdef CFG_ATHRS26_PHY
                athrs26_reg_init();
#endif
#ifdef CFG_ATHRS27_PHY
                printf("s27 reg init \n");
                athrs27_reg_init();
#endif
#ifdef CONFIG_F1E_PHY
               printf("F1Phy reg init \n");
               athr_reg_init();
#endif
            }
        } else {
#ifdef CFG_ATHRS26_PHY
                printf("athrs26_reg_init_lan\n");
                athrs26_reg_init_lan();
#endif
#ifdef CFG_ATHRS27_PHY
            printf("s27 reg init lan \n");
            athrs27_reg_init_lan();
#endif
        }

        ag7240_phy_setup(ag7240_macs[i]->mac_unit);
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
    uint16_t      ii = 0xFFFF;


    /*
     * Check for previous transactions are complete. Added to avoid
     * race condition while running at higher frequencies.
     */
    do
    {
        udelay(5);
        rddata = ag7240_reg_rd(mac, AG7240_MII_MGMT_IND) & 0x1;
    }while(rddata && --ii);

    if (ii == 0)
        printf("ERROR:%s:%d transaction failed\n",__func__,__LINE__);


    ag7240_reg_wr(mac, AG7240_MII_MGMT_CMD, 0x0);
    ag7240_reg_wr(mac, AG7240_MII_MGMT_ADDRESS, addr);
    ag7240_reg_wr(mac, AG7240_MII_MGMT_CMD, AG7240_MGMT_CMD_READ);

    do
    {
        udelay(5);
        rddata = ag7240_reg_rd(mac, AG7240_MII_MGMT_IND) & 0x1;
    }while(rddata && --ii);

   if(ii==0)
      printf("Error!!! Leave ag7240_miiphy_read without polling correct status!\n");

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
    uint16_t      ii = 0xFFFF;

     /*
     * Check for previous transactions are complete. Added to avoid
     * race condition while running at higher frequencies.
     */
    do
    {
        udelay(5);
        rddata = ag7240_reg_rd(mac, AG7240_MII_MGMT_IND) & 0x1;
    }while(rddata && --ii);

    if (ii == 0)
        printf("ERROR:%s:%d transaction failed\n",__func__,__LINE__);

    ag7240_reg_wr(mac, AG7240_MII_MGMT_ADDRESS, addr);
    ag7240_reg_wr(mac, AG7240_MII_MGMT_CTRL, data);

    do
    {
        rddata = ag7240_reg_rd(mac, AG7240_MII_MGMT_IND) & 0x1;
    }while(rddata && --ii);

    if(ii==0)
        printf("Error!!! Leave ag7240_miiphy_write without polling correct status!\n");
}
#endif		/* CONFIG_COMMANDS & CFG_CMD_MII */
