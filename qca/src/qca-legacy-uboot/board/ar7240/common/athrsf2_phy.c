/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
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

#include <config.h>
#include <linux/types.h>
#include <common.h>
#include <miiphy.h>
#include "phy.h"
#include <asm/addrspace.h>
#include "ar7240_soc.h"
#include "athrsf1_phy.h"

#define MODULE_NAME "ATHRSF2_PHY"

#define ATHR_LAN_PORT_VLAN          1
#define ATHR_WAN_PORT_VLAN          2
#define ENET_UNIT_LAN 1
#define ENET_UNIT_WAN 0

#define TRUE    1
#define FALSE   0

#define ATHR_PHY_MAX 5
#define ATHR_PHY0_ADDR   0x0
#define ATHR_PHY1_ADDR   0x1
#define ATHR_PHY2_ADDR   0x2
#define ATHR_PHY3_ADDR   0x3
#define ATHR_PHY4_ADDR   0x4
#define ATHR_PHY5_ADDR   0x5

#define ATHR_DEBUG_PORT_ADDRESS          29
#define ATHR_DEBUG_PORT_DATA             30

/*
 * Track per-PHY port information.
 */
typedef struct {
    BOOL   isEnetPort;       /* normal enet port */
    BOOL   isPhyAlive;       /* last known state of link */
    int    ethUnit;          /* MAC associated with this phy port */
    uint32_t phyBase;
    uint32_t phyAddr;          /* PHY registers associated with this phy port */
    uint32_t VLANTableSetting; /* Value to be written to VLAN table */
} athrPhyInfo_t;

/*
 * Per-PHY information, indexed by PHY unit number.
 */

static athrPhyInfo_t athrPhyInfo[] = {
    {TRUE,   /* port 1 -- LAN port 1 */
     FALSE,
     ENET_UNIT_WAN,
     0,                /* phy Base */
     ATHR_PHY5_ADDR,
     ATHR_LAN_PORT_VLAN
    },

};

#define ATHR_IS_ENET_PORT(phyUnit) (athrPhyInfo[phyUnit].isEnetPort)
#define ATHR_IS_PHY_ALIVE(phyUnit) (athrPhyInfo[phyUnit].isPhyAlive)
#define ATHR_ETHUNIT(phyUnit) (athrPhyInfo[phyUnit].ethUnit)
#define ATHR_PHYBASE(phyUnit) (athrPhyInfo[phyUnit].phyBase)
#define ATHR_PHYADDR(phyUnit) (athrPhyInfo[phyUnit].phyAddr)
#define ATHR_VLAN_TABLE_SETTING(phyUnit) (athrPhyInfo[phyUnit].VLANTableSetting)

#define ATHR_IS_ETHUNIT(phyUnit, ethUnit) \
            (ATHR_IS_ENET_PORT(phyUnit) &&        \
            ATHR_ETHUNIT(phyUnit) == (ethUnit))

#define ATHR_IS_WAN_PORT(phyUnit) (!(ATHR_ETHUNIT(phyUnit)==ENET_UNIT_LAN))
 
/* Forward references */
BOOL athr_phy_is_link_alive(int phyUnit);

void athr_enable_linkIntrs(int ethUnit) 
{
    return;
}

void athr_disable_linkIntrs(int ethUnit) 
{
	return;
}
void athr_auto_neg(int ethUnit,int phyUnit) 
{ 
    int timeout = 0;
    uint16_t phyHwStatus;
    int phyBase = 0,phyAddr =0;
    
    phyUnit = 0;
    phyBase = ATHR_PHYBASE(phyUnit);
    phyAddr = ATHR_PHYADDR(phyUnit);

    if(!is_emu()) {
       phy_reg_write(ethUnit, phyUnit , ATHR_PHY_CONTROL, ATHR_CTRL_AUTONEGOTIATION_ENABLE | ATHR_CTRL_SOFTWARE_RESET);

       printf("ATHR_AUTONEG_ADVERT:%X\n",phy_reg_read(phyBase, phyAddr,ATHR_AUTONEG_ADVERT));
       printf("ATHR_1000BASET_CONTROL:%X\n",phy_reg_read(phyBase, phyAddr,ATHR_1000BASET_CONTROL));
       printf("ATHR_PHY_CONTROL:%X\n",phy_reg_read(phyBase, phyAddr,ATHR_PHY_CONTROL));
    }
    else {
       phy_reg_write(phyBase, phyAddr, ATHR_AUTONEG_ADVERT, ATHR_ADVERTISE_ALL);
       /* Do not advertise 1000 */
       phy_reg_write(phyBase, phyAddr, ATHR_1000BASET_CONTROL,0x0);
       phy_reg_write(phyBase, phyAddr, ATHR_PHY_CONTROL, ATHR_CTRL_AUTONEGOTIATION_ENABLE | ATHR_CTRL_SOFTWARE_RESET);
    }

   /*
     * Wait up to 3 seconds for ALL associated PHYs to finish
     * autonegotiation.  The only way we get out of here sooner is
     * if ALL PHYs are connected AND finish autonegotiation.
     */
    timeout=20;
    for (;;) {
        phyHwStatus = phy_reg_read(phyBase, phyAddr, ATHR_PHY_CONTROL);

        if (ATHR_RESET_DONE(phyHwStatus)) {
            printf(MODULE_NAME": Port %d, Neg Success\n", phyUnit);
            break;
        }
        if (timeout == 0) {
            printf(MODULE_NAME": Port %d, Negogiation timeout\n", phyUnit);
            break;
        }
        if (--timeout == 0) {
            printf(MODULE_NAME": Port %d, Negogiation timeout\n", phyUnit);
            break;
        }

        mdelay(150);
    }

    printf(MODULE_NAME": unit %d phy addr %x ", phyBase, phyAddr);
}

/******************************************************************************
*
* athr_phy_is_link_alive - test to see if the specified link is alive
*
* RETURNS:
*    TRUE  --> link is alive
*    FALSE --> link is down
*/
BOOL
athr_phy_is_link_alive(int phyUnit)
{
	uint16_t phyHwStatus;
	uint32_t phyBase;
	uint32_t phyAddr;

	phyBase = ATHR_PHYBASE(phyUnit);
	phyAddr = ATHR_PHYADDR(phyUnit);

	phyHwStatus = phy_reg_read(phyBase, phyAddr, ATHR_PHY_SPEC_STATUS);

	if (phyHwStatus & ATHR_STATUS_LINK_PASS) {
		return TRUE;
	}

	return FALSE;
}

/******************************************************************************
*
* athr_phy_setup - reset and setup the PHY associated with
* the specified MAC unit number.
*
* Resets the associated PHY port.
*
* RETURNS:
*    TRUE  --> associated PHY is alive
*    FALSE --> no LINKs on this ethernet unit
*/

BOOL
athr_phy_setup(int ethUnit)
{
	int       phyUnit = 0;
	int       liveLinks = 0;

	athr_auto_neg(ethUnit,phyUnit);

	if (athr_phy_is_link_alive(phyUnit)) {
		liveLinks++;
		ATHR_IS_PHY_ALIVE(phyUnit) = TRUE;
	} else {
		ATHR_IS_PHY_ALIVE(phyUnit) = FALSE;
	}
	return (liveLinks > 0);
}

/******************************************************************************
*
* athr_phy_is_fdx - Determines whether the phy ports associated with the
* specified device are FULL or HALF duplex.
*
* RETURNS:
*    1 --> FULL
*    0 --> HALF
*/
int
athr_phy_is_fdx(int ethUnit,int phyUnit)
{
    uint32_t  phyBase;
    uint32_t  phyAddr;
    uint16_t  phyHwStatus;
    int       ii = 200;

    phyUnit = 0;

    if (athr_phy_is_link_alive(phyUnit)) {

         phyBase = ATHR_PHYBASE(phyUnit);
         phyAddr = ATHR_PHYADDR(phyUnit);

         do {
                phyHwStatus = phy_reg_read(phyBase, phyAddr,ATHR_PHY_SPEC_STATUS);
                mdelay(10);
          } while((!(phyHwStatus & ATHR_STATUS_RESOVLED)) && --ii);
          
          if (phyHwStatus & ATHER_STATUS_FULL_DUPLEX) {
                return TRUE;
          }
    }
    return FALSE;
}

/******************************************************************************
*
* athr_phy_speed - Determines the speed of phy ports associated with the
* specified device.
*
* RETURNS:
*               AG7240_PHY_SPEED_10T, AG7240_PHY_SPEED_100T;
*               AG7240_PHY_SPEED_1000T;
*/

int
athr_phy_speed(int ethUnit,int phyUnit)
{
    uint16_t  phyHwStatus;
    uint32_t  phyBase;
    uint32_t  phyAddr;
    int       ii = 200;


    phyUnit = 0;
    if (athr_phy_is_link_alive(phyUnit)) {

        phyBase = ATHR_PHYBASE(phyUnit);
        phyAddr = ATHR_PHYADDR(phyUnit);
        do {
            phyHwStatus = phy_reg_read(phyBase, phyAddr,ATHR_PHY_SPEC_STATUS);
            mdelay(10);
        } while((!(phyHwStatus & ATHR_STATUS_RESOVLED)) && --ii);

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
            printf("Unkown speed read!!!!\n");
        }
    }

    //printf("athr_phy_speed: link down, returning 10t\n");
    return _10BASET;
}

/*****************************************************************************
*
* athr_phy_is_up -- checks for significant changes in PHY state.
*
* A "significant change" is:
*     dropped link (e.g. ethernet cable unplugged) OR
*     autonegotiation completed + link (e.g. ethernet cable plugged in)
*
* When a PHY is plugged in, phyLinkGained is called.
* When a PHY is unplugged, phyLinkLost is called.
*/

int
athr_phy_is_up(int ethUnit)
{
    int           phyUnit;
    uint16_t      phyHwStatus, phyHwControl;
    athrPhyInfo_t *lastStatus;
    int           linkCount   = 0;
    int           lostLinks   = 0;
    int           gainedLinks = 0;
    uint32_t      phyBase;
    uint32_t      phyAddr;

    for (phyUnit= 0; phyUnit < 1; phyUnit++) {

        phyBase = ATHR_PHYBASE(phyUnit);
        phyAddr = ATHR_PHYADDR(phyUnit);

        lastStatus = &athrPhyInfo[phyUnit];

        if (lastStatus->isPhyAlive) { /* last known link status was ALIVE */

             phyHwStatus = phy_reg_read(phyBase, ATHR_PHYADDR(phyUnit),ATHR_PHY_SPEC_STATUS);

            /* See if we've lost link */
            if (phyHwStatus & ATHR_STATUS_LINK_PASS) { /* check realtime link */
                linkCount++;
            } else {
                phyHwStatus = phy_reg_read(phyBase, ATHR_PHYADDR(phyUnit),ATHR_PHY_STATUS);
            /* If realtime failed check link in latch register before
	     * asserting link down.
             */
                if (phyHwStatus & ATHR_LATCH_LINK_PASS)     
                   linkCount++;
		else
                    lostLinks++;
                lastStatus->isPhyAlive = FALSE;
            }
        } else { /* last known link status was DEAD */

            /* Check for reset complete */

                phyHwStatus = phy_reg_read(phyBase, ATHR_PHYADDR(phyUnit),ATHR_PHY_STATUS);

            if (!ATHR_RESET_DONE(phyHwStatus))
                continue;

                phyHwControl = phy_reg_read(phyBase, ATHR_PHYADDR(phyUnit),ATHR_PHY_CONTROL);

            /* Check for AutoNegotiation complete */ 
           
            if ((!(phyHwControl & ATHR_CTRL_AUTONEGOTIATION_ENABLE)) 
                 || ATHR_AUTONEG_DONE(phyHwStatus)) {
                    phyHwStatus = phy_reg_read(phyBase, ATHR_PHYADDR(phyUnit),ATHR_PHY_SPEC_STATUS);

                    if (phyHwStatus & ATHR_STATUS_LINK_PASS) {
                        gainedLinks++;
                        linkCount++;
                        lastStatus->isPhyAlive = TRUE;
                   }  
            }
        }
    }
    return (linkCount);

}
/* Place holders */

int 
athr_reg_init(void *arg)
{
   /* Feed 50 Mhz internal clk */
   ar7240_reg_wr(AR7242_ETH_XMII_CONFIG,0x0);
   printf("F2 phy:%s\n",__func__);
   return 0;
}
