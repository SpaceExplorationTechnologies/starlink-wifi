/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
#ifndef _IPV4__H_
#define _IPV4__H_

#if defined(ATH_TARGET)
#include <osapi.h>   /* A_UINT8 */
#else
#include <a_types.h> /* A_UINT8 */
#endif

#define IPV4_ADDR_LEN 4 /* bytes */
struct ipv4_hdr_t {
    A_UINT8 ver_hdrlen;       /* version and hdr length */
    A_UINT8 tos;              /* type of service */
    A_UINT8 len[2];           /* total length */
    A_UINT8 id[2];
    A_UINT8 flags_fragoff[2]; /* flags and fragment offset field */
    A_UINT8 ttl;              /* time to live */
    A_UINT8 protocol;
    A_UINT8 hdr_checksum[2];
    A_UINT8 src_addr[IPV4_ADDR_LEN];
    A_UINT8 dst_addr[IPV4_ADDR_LEN];
};

#define IPV4_HDR_LEN (sizeof(struct ipv4_hdr_t))
#define IPV4_HDR_OFFSET_PROTOCOL (offsetof(struct ipv4_hdr_t, protocol))
#define IPV4_HDR_OFFSET_DST_ADDR (offsetof(struct ipv4_hdr_t, dst_addr[0]))

#endif /* _IPV4__H_ */
