/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */


//------------------------------------------------------------------------------
// <copyright file="athstartpack.h" company="Atheros">
//    Copyright (c) 2004-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// start compiler-specific structure packing
//
// Author(s): ="Atheros"
//==============================================================================
#ifndef _ATHSTARTPACK_H
#define _ATHSTARTPACK_H

#ifdef VXWORKS
#endif /* VXWORKS */

#if defined(LINUX) || defined(__linux__)
#if 0
#ifndef PREPACK
#define PREPACK
#endif /* PREPACK */
#ifndef POSTPACK
#ifdef __GNUC__
#define POSTPACK __attribute__ ((packed))
#else
#define POSTPACK
#endif /* POSTPACK */
#endif /* __GNUC__ */
#else
#include <a_osapi.h>
#endif
#endif /* LINUX */

#ifdef QNX
#endif /* QNX */

#ifdef INTEGRITY
#include "integrity/athstartpack_integrity.h"
#endif /* INTEGRITY */

#ifdef NUCLEUS
#endif /* NUCLEUS */

#ifdef ATHR_WM_NWF
#include "../os/windows/include/athstartpack.h"
#define PREPACK
#endif

#ifdef ATHR_CE_LEGACY
#include "../os/windows/include/athstartpack.h"
#endif /* WINCE */

#ifdef ATHR_WIN_NWF
#ifndef PREPACK
#define PREPACK __declspec(align(1))
#endif
#ifndef POSTPACK
#define POSTPACK
#endif
//#include <pshpack1.h>
#endif

#if __LONG_MAX__ == __INT_MAX__
/* 32-bit compilation */
#define PREPACK64
#define POSTPACK64
#else
/* 64-bit compilation */
#define PREPACK64 PREPACK
#define POSTPACK64 POSTPACK
#endif

#endif /* _ATHSTARTPACK_H */
