/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// ------------------------------------------------------------------
// Copyright (c) 2004-2007 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Atheros"
//===================================================================

#ifndef __EXTRA_MAC_HWSCH_REG_SW_H
#define __EXTRA_MAC_HWSCH_REG_SW_H
// THIS IS A SOFTWARE WRAPPER HEADER FILE

#include "../../hw/mac_hwsch_reg.h"

// 1 queue config per register
#define HWSCH_CMD_RING_BASE_ADDR(_i)              (HWSCH_CMD_RING_BASE_0_ADDRESS + ((_i)<<2))
#define HWSCH_CMD_RING_HEAD_ADDR(_i)              (HWSCH_CMD_RING_HEAD_0_ADDRESS + ((_i)<<2))
#define HWSCH_CMD_RING_TAIL_ADDR(_i)              (HWSCH_CMD_RING_TAIL_0_ADDRESS + ((_i)<<2))
#define HWSCH_CMD_RING_NUM_ENTRY_ADDR(_i)         (HWSCH_CMD_RING_NUM_ENTRY_0_ADDRESS + ((_i)<<2))
#define HWSCH_CMD_RING_THRESHOLD_ADDR(_i)         (HWSCH_CMD_RING_THRESHOLD_0_ADDRESS + ((_i)<<2))
#define HWSCH_BKOF_CNT_ADDR(_i)                   (HWSCH_BKOF_CNT_0_ADDRESS + ((_i)<<2))
#define HWSCH_CWMIN_CWMAX_ADDR(_i)                (HWSCH_SW_CW_MIN_CW_MAX_0_ADDRESS + ((_i)<<2))
#define HWSCH_CW_REG_CONTROL_FOR_BACKOFF_ADDR(_i) (HWSCH_CW_REG_CONTROL_FOR_BACKOFF_0_ADDRESS + ((_i)<<2))



// 2 queue config per register
#define HWSCH_DIFS_LIMIT_ADDR(_i)       (HWSCH_DIFS_LIMIT_1_0_ADDRESS + ((_i<<1) & 0xFFFC))
#define HWSCH_LFSR_DATA_ADDR(_i)        (HWSCH_LFSR_DATA_1_0_ADDRESS +  ((_i<<1) & 0xFFFC))


// 4 queue config per register
#define HWSCH_TXOP_CONTROL_ADDR(_i)                 (HWSCH_TXOP_CONTROL0_ADDRESS + ((_i)&0xFFFC))
#define HWSCH_TXOP_CONTROL_TXOP_SEL_MASK_RING(_q, _regR, _val)   \
        (((_regR) & ~((HWSCH_TXOP_CONTROL0_TXOP_SEL_MASK_RING0_MASK)<<(((_q)&0x3) * 0x8)))  \
         | (((_val) & HWSCH_TXOP_CONTROL0_TXOP_SEL_MASK_RING0_MASK)<<(((_q)&0x3) * 0x8))                             \
        )

#define TXOP_SEL_TBTT0_REMAINING   0x1
#define TXOP_SEL_TBTT1_REMAINING   0x2
#define TXOP_SEL_SCH_CMD_LIFETIME  0x4
#define TXOP_SEL_SCH_CMD_TXOP_CTRL 0x8
#define TXOP_SEL_BOUNDRY_TMR0_VAL  0x10   
#define TXOP_SEL_BOUNDRY_TMR1_VAL  0x20   
#define TXOP_SEL_BOUNDRY_TMR2_VAL  0x40   
#define TXOP_SEL_BOUNDRY_TMR3_VAL  0x80   

#define TXOP_DEFAULT_SELECT (TXOP_SEL_TBTT0_REMAINING | \
                             TXOP_SEL_TBTT1_REMAINING | \
                             TXOP_SEL_SCH_CMD_LIFETIME | \
                             TXOP_SEL_SCH_CMD_TXOP_CTRL)


// 8 queue config per register
#define HWSCH_FINAL_CCA_CONTROL_ADDR(_i)    (HWSCH_CCA_CONTROL_REG_5_ADDRESS + (((_i)&0xFFF8)>>1))
#define HWSCH_FINAL_CCA_CONTROL_CCA_SEL(_q, _regR, _val)   \
        (((_regR) & ~((HWSCH_CCA_CONTROL_REG_5_SW_MTU_FINAL_CCA_SEL0_MASK)<<(((_q)&0x7) << 0x2)))  \
         | (((_val) & HWSCH_CCA_CONTROL_REG_5_SW_MTU_FINAL_CCA_SEL0_MASK)<<(((_q)&0x7) << 0x2))                             \
        )

#define FINAL_CCA_SEL_IBSS_QUEUE 0x1
#define FINAL_CCA_SEL_NON_IBSS_QUEUE 0x3
#define FINAL_CCA_SEL_IBSS_DISABLED 0x0

#define HWSCH_LONG_SHORT_XMIT_LIMIT_BKOF_ADDR(_i) (HWSCH_LONG_SHORT_XMIT_LIMIT_BKOF_3_TO_0_ADDRESS + ((_i)&0xFFFC))
// Expect (l3,s3),(l2,s2),(l1,s1),(l0,s0) format
#define HWSCH_LONG_XMIT_LIMIT(_l, _q) ((_l & 0xf) << (((_q & 0x3) << 3) + 4))
#define HWSCH_SHRT_XMIT_LIMIT(_s, _q) ((_s & 0xf) << ((_q & 0x3) << 3))

#endif /*__MAC_HWSCH_REG_SW_H */



