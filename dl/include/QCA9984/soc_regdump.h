/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// Copyright (c) 2006-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#ifndef __SOC_REGDUMP_H__
#define __SOC_REGDUMP_H__

/* TBDXXX: This whole file blindly ripped off from AR6004 */

#if !defined(__ASSEMBLER__)
/*
 * XTensa CPU state
 * This must match the state saved by the target exception handler.
 */
struct XTensa_exception_frame_s {
    A_UINT32 xt_pc;
    A_UINT32 xt_ps;
    A_UINT32 xt_sar;
    A_UINT32 xt_vpri;
    A_UINT32 xt_a2;
    A_UINT32 xt_a3;
    A_UINT32 xt_a4;
    A_UINT32 xt_a5;
    A_UINT32 xt_exccause;
    A_UINT32 xt_lcount;
    A_UINT32 xt_lbeg;
    A_UINT32 xt_lend;

    A_UINT32 epc1, epc2, epc3, epc4;

    /* Extra info to simplify post-mortem stack walkback */
#define SOC_REGDUMP_FRAMES 10
    struct {
        A_UINT32 a0;  /* pc */
        A_UINT32 a1;  /* sp */
        A_UINT32 a2;
        A_UINT32 a3;
    } wb[SOC_REGDUMP_FRAMES];
};
typedef struct XTensa_exception_frame_s CPU_exception_frame_t; 
#define RD_SIZE sizeof(CPU_exception_frame_t)

#endif
#endif /* __SOC_REGDUMP_H__ */
