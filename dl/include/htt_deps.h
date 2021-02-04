/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// Copyright (c) 2011 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

/**
 * @file htt_deps.h
 *
 * @details
 *     include other header files that htt.h depends on
 */

#ifndef _HTT_DEPS_H
#define _HTT_DEPS_H

#if defined(ATH_TARGET)
#include <osapi.h>      /* A_UINT32 */
#else
#include <a_types.h>    /* A_UINT32 */
#include <a_osapi.h>    /* PREPACK, POSTPACK */
#endif
#ifdef ATHR_WIN_NWF
#pragma warning( disable:4214 ) //bit field types other than int
#endif
#include "wlan_defs.h"

#endif
