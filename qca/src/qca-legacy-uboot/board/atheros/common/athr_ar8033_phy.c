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
#include <atheros.h>
#include "athrs_ar8033_phy.h"


void
athrs_ar8033_mgmt_init(void)
{
    uint32_t rddata;


    rddata = ath_reg_rd(GPIO_IN_ENABLE3_ADDRESS)&
             ~GPIO_IN_ENABLE3_MII_GE1_MDI_MASK;
    rddata |= GPIO_IN_ENABLE3_MII_GE1_MDI_SET(19);
    ath_reg_wr(GPIO_IN_ENABLE3_ADDRESS, rddata);
    
    ath_reg_rmw_clear(GPIO_OE_ADDRESS, ATH_GPIO);

    ath_reg_rmw_clear(GPIO_OE_ADDRESS, ATH_GPIO17);

    
    rddata = ath_reg_rd(GPIO_OUT_FUNCTION4_ADDRESS) & 
             ~ (GPIO_FUNCTION4_MASK);

    rddata |= (GPIO_FUNCTION4_ENABLE);

    ath_reg_wr(GPIO_OUT_FUNCTION4_ADDRESS, rddata);

#ifdef ATH_MDC_GPIO
    rddata = ath_reg_rd(GPIO_OUT_FUNCTION3_ADDRESS) &
           ~ (GPIO_OUT_FUNCTION3_ENABLE_GPIO_14_MASK);

    rddata |= GPIO_OUT_FUNCTION3_ENABLE_GPIO_14_SET(0x21);

    ath_reg_wr(GPIO_OUT_FUNCTION3_ADDRESS, rddata);
#endif

}

int
athrs_ar8033_phy_setup(void  *arg)
{
    
    return 0;
}

int
athrs_ar8033_phy_is_fdx(int ethUnit)
{
   int phy_hw_status = 0x0;

   phy_hw_status = ath_reg_rd(SGMII_MAC_RX_CONFIG_ADDRESS);

   if (SGMII_MAC_RX_CONFIG_DUPLEX_MODE_GET(phy_hw_status) == 1) {
        return 1;
    } else if (SGMII_MAC_RX_CONFIG_DUPLEX_MODE_GET(phy_hw_status) == 0) {
        return 0;
    }

    return 0;

}

int
athrs_ar8033_phy_is_link_alive(int phyUnit)
{
   int phy_hw_status = 0x0;

   phy_hw_status = ath_reg_rd(SGMII_MAC_RX_CONFIG_ADDRESS);

   if (SGMII_MAC_RX_CONFIG_LINK_GET(phy_hw_status))
        return 1;
    else
        return 0;

  }

int
athrs_ar8033_phy_is_up(int ethUnit)
{
   int phy_hw_status = 0x0;

   phy_hw_status = ath_reg_rd(SGMII_MAC_RX_CONFIG_ADDRESS);
    if (SGMII_MAC_RX_CONFIG_LINK_GET(phy_hw_status))
        return 1;
    else
        return 0;

   
}
int
athrs_ar8033_phy_speed(int ethUnit)
{
   int phy_hw_status = 0x0,speed;

   phy_hw_status = ath_reg_rd(SGMII_MAC_RX_CONFIG_ADDRESS);

   speed = ((phy_hw_status & (3 << 10)) >> 10);

   switch (speed) {
        case 0:
                return _10BASET;
                break;
        case 1:
                return _100BASET;
                break;
        case 2:
                return _1000BASET;
                break;
        default:
                return -1;
                break;
   }

   return -1;

}


int 
athrs_ar8033_reg_init(void *arg)
{


	athrs_ar8033_mgmt_init();
	phy_reg_write(0x1,0x5, 0x1f, 0x101);



	printf("%s: Done %x \n",__func__, phy_reg_read(0x1,0x5,0x1f));
   
	return 0;
}

