/* 
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved. 
 * Qualcomm Atheros Confidential and Proprietary. 
 * */

//------------------------------------------------------------------------------
// <copyright file="a_osapi.h" company="Atheros">
//    Copyright (c) 2004-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// This file contains the definitions of the basic atheros data types.
// It is used to map the data types in atheros files to a platform specific
// type.
//
// Author(s): ="Atheros"
//==============================================================================
#ifndef _A_OSAPI_H_
#define _A_OSAPI_H_

#if defined(__linux__) && !defined(LINUX_EMULATION)
#include "osapi_linux.h"
#endif

#ifdef ATHR_WM_NWF
#include "../os/windows/include/osapi.h"
#include "../os/windows/include/netbuf.h"
#endif

#ifdef ATHR_CE_LEGACY
#include "../os/windows/include/osapi.h"
#include "../os/windows/include/netbuf.h"
#endif

#ifdef REXOS
#include "../os/rexos/include/common/osapi_rexos.h"
#endif

#if defined ART_WIN
#include "../os/win_art/include/osapi_win.h"
#include "../os/win_art/include/netbuf.h"
#endif

#ifdef ATHR_WIN_NWF
#include "../os/win_nwf/include/osapi_win.h"
#endif

/*=== the following primitives have the same definition for all platforms ===*/

#define A_COMPILE_TIME_ASSERT(assertion_name, predicate) \
    typedef char assertion_name[(predicate) ? 1 : -1]

/*
 * If N is a power of 2, then N and N-1 are orthogonal
 * (N-1 has all the least-significant bits set which are zero in N)
 * so  N ^ (N-1) = (N << 1) - 1
 */
#define A_COMPILE_TIME_ASSERT_IS_PWR2(assertion_name, value) \
    A_COMPILE_TIME_ASSERT(assertion_name,                    \
        (((value) ^ ((value)-1)) == ((value) << 1) - 1))

#ifndef __ubicom32__
#define HIF_MALLOC_DIAGMEM(osdev, size, pa, context, retry) \
    OS_MALLOC_CONSISTENT(osdev, size, pa, context, retry)
#define HIF_FREE_DIAGMEM(osdev, size, vaddr, pa, context) \
    OS_FREE_CONSISTENT(osdev, size, vaddr, pa, context)
#define HIF_DIAGMEM_SYNC(osdev, pa, size, dir, context)
#else
#define HIF_MALLOC_DIAGMEM(osdev, size, pa, context, retry) \
    OS_MALLOC_NONCONSISTENT(osdev, size, pa, context, retry)
#define HIF_FREE_DIAGMEM(osdev, size, vaddr, pa, context) \
    OS_FREE_NONCONSISTENT(osdev, size, vaddr, pa, context)
#define HIF_DIAGMEM_SYNC(osdev, pa, size, dir, context) \
    OS_SYNC_SINGLE(osdev, pa, size, dir, context)
#endif /* ubicom32 */

#endif /* _OSAPI_H_ */
