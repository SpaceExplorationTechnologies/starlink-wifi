//------------------------------------------------------------------------------
//
// This file contains the definitions of the basic atheros data types.
// It is used to map the data types in atheros files to a platform specific
// type.
// Copyright (c) 2004-2017 Atheros Communications Inc.
// All rights reserved.
//
// $ATH_LICENSE_HOSTSDK0_C$
//
// Author(s): ="Atheros"
//------------------------------------------------------------------------------

/*
 * Copyright (c) 2013-2017 Qualcomm Technologies, Inc. All rights reserved.
 * 2013-2016 Qualcomm Atheros, Inc.
 * Qualcomm Technologies Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#ifndef _ATHTYPES_LINUX_H_
#define _ATHTYPES_LINUX_H_

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <sys/types.h>
#endif

typedef int8_t      A_INT8;
typedef int16_t     A_INT16;
typedef int32_t     A_INT32;
typedef int64_t     A_INT64;

typedef u_int8_t     A_UINT8;
typedef u_int16_t    A_UINT16;
typedef u_int32_t    A_UINT32;    /* Use this to declare data only */
typedef u_int64_t    A_UINT64;
typedef u_long       A_UINTL;    /* Use this to declare pointers, since pointers in 64 bit platform are of 8byte */

typedef int             A_BOOL;
typedef char            A_CHAR;
typedef unsigned char   A_UCHAR;
typedef unsigned long   A_ATH_TIMER;


#endif /* _ATHTYPES_LINUX_H_ */
