/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef BIN_SIGN_H_
#define BIN_SIGN_H_

/* Signed binary MetaData */
typedef struct {
    unsigned int magic_num;
    unsigned int total_len;
    unsigned int rampatch_len;
    unsigned int product_id;
    unsigned int patch_ver;
    unsigned short sign_format_ver;
    unsigned short sign_algorithm;
    unsigned short oem_id;
    unsigned char reserved[6];
} SIGN_HEADER_T;

#endif /*  BIN_SIGN_H_ */
