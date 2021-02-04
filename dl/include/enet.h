/*
 * Copyright (c) 2012, 2017 Qualcomm Technology, Inc.
 * All Rights Reserved.
 * 2012 Qualcomm Atheros, Inc.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
#ifndef _ENET__H_
#define _ENET__H_

#if defined(ATH_TARGET)
#include <osapi.h>   /* A_UINT8 */
#else
#include <a_types.h> /* A_UINT8 */
#endif


#define ETHERNET_ADDR_LEN 6 /* bytes */
#define ETHERNET_TYPE_LEN 2 /* bytes - length of the Ethernet type field */

struct ethernet_hdr_t {
    A_UINT8 dest_addr[ETHERNET_ADDR_LEN];
    A_UINT8 src_addr[ETHERNET_ADDR_LEN];
    A_UINT8 ethertype[2];
};

#define ETHERNET_HDR_LEN (sizeof(struct ethernet_hdr_t))

struct llc_snap_hdr_t {
    A_UINT8 dsap;
    A_UINT8 ssap;
    A_UINT8 cntl;
    A_UINT8 org_code[3];
    A_UINT8 ethertype[2];
};

#define LLC_SNAP_HDR_LEN (sizeof(struct llc_snap_hdr_t))
#define LLC_SNAP_HDR_OFFSET_ETHERTYPE \
    (offsetof(struct llc_snap_hdr_t, ethertype[0]))

#ifndef ETHERTYPE_IPV4
#define ETHERTYPE_IPV4  0x0800 /* Internet Protocol, Version 4 (IPv4) */
#endif

#ifndef ETHERTYPE_ARP
#define ETHERTYPE_ARP   0x0806 /* Address Resolution Protocol (ARP) */
#endif

#ifndef ETHERTYPE_RARP
#define ETHERTYPE_RARP  0x8035 /* Reverse Address Resolution Protocol (RARP) */
#endif

#ifndef ETHERTYPE_SNMP
#define ETHERTYPE_SNMP  0x814C /* Simple Network Management Protocol (SNMP) */
#endif

#ifndef ETHERTYPE_IPV6
#define ETHERTYPE_IPV6  0x86DD /* Internet Protocol, Version 6 (IPv6) */
#endif


#endif /* _ENET__H_ */
