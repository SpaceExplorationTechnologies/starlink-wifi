/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// <copyright file="regdump.h" company="Atheros">
//    Copyright (c) 2004-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#ifndef __REGDUMP_H__
#define __REGDUMP_H__

#ifndef ATH_TARGET
#include "athstartpack.h"
#endif

#include "soc_regdump.h"

#if !defined(__ASSEMBLER__)
/*
 * Target CPU state at the time of failure is reflected
 * in a register dump, which the Host can fetch through
 * the diagnostic window.
 */
PREPACK struct register_dump_s {
    A_UINT32 target_id;               /* Target ID */
    A_UINT32 assline;                 /* Line number (if assertion failure) */
    A_UINT32 pc;                      /* Program Counter at time of exception */
    A_UINT32 badvaddr;                /* Virtual address causing exception */
    CPU_exception_frame_t exc_frame;  /* CPU-specific exception info */

    /* Could copy top of stack here, too.... */
} POSTPACK;
#endif /* __ASSEMBLER__ */

#ifndef ATH_TARGET
#include "athendpack.h"
#endif

#endif /* __REGDUMP_H__ */
