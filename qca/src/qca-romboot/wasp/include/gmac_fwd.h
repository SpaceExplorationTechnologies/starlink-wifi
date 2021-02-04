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

#ifndef __GMAC_FWD_H
#define __GMAC_FWD_H

#include "asm/types.h"
#include "fwd.h"

#define ETH_ALEN 6
#define GMAC_MAX_PKT_LEN 2048
#define GMAC_DISCV_WAIT  2000

#define hif_gmac_sc(_hdl)   (__gmac_softc_t *)(_hdl)
#define gmac_hdr(_buf) ((__gmac_hdr_t *)(_buf)) 
#define GMAC_HLEN           (sizeof(struct __gmac_hdr))

#define ATH_P_BOOT           0x12 /*Magpie GMAC 18 for boot downloader*/
#define ATH_P_NORM           0x13 /*Magpie GMAC 19 for HTC & others*/

#define ETH_P_ATH               0x88bd



/*************************GMAC Data types*******************************/
typedef enum __gmac_pkt_type{
    GMAC_PKT_IS_BCAST,
    GMAC_PKT_IS_UCAST
}__gmac_pkt_type_t;

struct __ethhdr{
    unsigned char   dst[ETH_ALEN];/*destination eth addr */
    unsigned char   src[ETH_ALEN]; /*source ether addr*/
    a_uint16_t      etype;/*ether type*/
}__attribute__((packed));
/**
 * @brief this is will be in big endian format
 */
struct __athhdr{
#ifdef LITTLE_ENDIAN
    a_uint8_t   proto:6,
                res:2;
#else
    a_uint8_t   res:2,
                proto:6;
#endif
    a_uint8_t   res_lo;
    a_uint16_t  res_hi;
}__attribute__((packed));

typedef struct __gmac_hdr{
    struct  __ethhdr   eth;
    struct  __athhdr   ath;
    a_uint16_t         align_pad;/*pad it for 4 byte boundary*/
}__attribute__((packed))  __gmac_hdr_t;

typedef struct __gmac_params {
    a_uint8_t     mac_addr[ETH_ALEN]; /* MAC Address */
    a_uint8_t     chip_type;    /* Act as MAC or PHY */
    a_uint8_t     link_speed;   /* RGMII Speed 10/100/1000 Mbps */
    a_uint16_t    rgmii_delay;  /* Delay no, small, medium, huge */
    a_uint16_t    dump_pkt;     /* Dump the received packet on target */
    a_uint16_t    dump_pkt_lim; /* Dump packet limit */
}__gmac_params_t;

#endif /* __GMAC_FWD_H */
