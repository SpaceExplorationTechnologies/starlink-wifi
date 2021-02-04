/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
#ifndef _IPV6__H_
#define _IPV6__H_

#if defined(ATH_TARGET)
#include <osapi.h>   /* A_UINT8 */
#else
#include <a_types.h> /* A_UINT8 */
#endif

#define IPV6_ADDR_LEN 4 /* bytes */
struct ipv6_hdr_t {
    A_UINT8 ver_tclass_flowlabel; /* version, traffic class, and flow label */
    A_UINT8 pyld_len[2];          /* payload length */
    A_UINT8 next_hdr;
    A_UINT8 hop_limit;
    A_UINT8 src_addr[IPV6_ADDR_LEN];
    A_UINT8 dst_addr[IPV6_ADDR_LEN];
};

#define IPV6_HDR_LEN (sizeof(struct ipv6_hdr_t))
#define IPV6_HDR_OFFSET_NEXT_HDR (offsetof(struct ipv6_hdr_t, next_hdr))
#define IPV6_HDR_OFFSET_DST_ADDR (offsetof(struct ipv6_hdr_t, dst_addr[0]))

#endif /* _IPV6__H_ */
