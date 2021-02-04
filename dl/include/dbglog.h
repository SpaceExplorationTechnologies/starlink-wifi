/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// <copyright file="dbglog.h" company="Atheros">
//    Copyright (c) 2004-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#ifndef _DBGLOG_H_
#define _DBGLOG_H_


#include "wlan_module_ids.h"
#ifndef ATH_TARGET
#include "athstartpack.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define DBGLOG_TIMESTAMP_OFFSET          0
#define DBGLOG_TIMESTAMP_MASK            0xFFFFFFFF /* Bit 0-15. Contains bit
                                                       8-23 of the LF0 timer */
#define DBGLOG_DBGID_OFFSET              0
#define DBGLOG_DBGID_MASK                0x000003FF /* Bit 0-9 */
#define DBGLOG_DBGID_NUM_MAX             256 /* Upper limit is width of mask */

#define DBGLOG_MODULEID_OFFSET           10
#define DBGLOG_MODULEID_MASK             0x0003FC00 /* Bit 10-17 */
#define DBGLOG_MODULEID_NUM_MAX          32 /* Upper limit is width of mask */

#define DBGLOG_VAPID_OFFSET              18
#define DBGLOG_VAPID_MASK                0x03FC0000 /* Bit 20-25*/
#define DBGLOG_VAPID_NUM_MAX             16 

#define DBGLOG_NUM_ARGS_OFFSET             26
#define DBGLOG_NUM_ARGS_MASK               0xFC000000 /* Bit 26-31 */
#define DBGLOG_NUM_ARGS_MAX                5 /* it is limited bcoz of limitations
                                              with Xtensa tool */

#define DBGLOG_MODULE_LOG_ENABLE_OFFSET    0
#define DBGLOG_MODULE_LOG_ENABLE_MASK      0xFFFFFFFF

#define DBGLOG_VAP_LOG_ENABLE_OFFSET	   0
#define DBGLOG_VAP_LOG_ENABLE_MASK	   0x0000FFFF

#define DBGLOG_REPORTING_ENABLE_OFFSET     16
#define DBGLOG_REPORTING_ENABLE_MASK       0x00010000

#define DBGLOG_TIMESTAMP_RESOLUTION_OFFSET 17
#define DBGLOG_TIMESTAMP_RESOLUTION_MASK   0x000E0000

#define DBGLOG_REPORT_SIZE_OFFSET          20
#define DBGLOG_REPORT_SIZE_MASK            0x0FF00000

#define DBGLOG_LOG_LVL_ENABLE_OFFSET	   28
#define DBGLOG_LOG_LVL_ENABLE_MASK	   0x70000000

#define DBGLOG_TIMER_ENABLE_OFFSET         31
#define DBGLOG_TIMER_ENABLE_MASK           0x80000000

#define DBGLOG_LOG_BUFFER_SIZE             1500
#define DBGLOG_DBGID_DEFINITION_LEN_MAX    90

#define DBGLOG_HOST_LOG_BUFFER_SIZE            DBGLOG_LOG_BUFFER_SIZE

#define DBGLOG_GET_DBGID(arg) \
    ((arg & DBGLOG_DBGID_MASK) >> DBGLOG_DBGID_OFFSET)

#define DBGLOG_GET_MODULEID(arg) \
    ((arg & DBGLOG_MODULEID_MASK) >> DBGLOG_MODULEID_OFFSET)

#define DBGLOG_GET_VAPID(arg) \
    ((arg & DBGLOG_VAPID_MASK) >> DBGLOG_VAPID_OFFSET)

#define DBGLOG_GET_NUMARGS(arg) \
    ((arg & DBGLOG_NUM_ARGS_MASK) >> DBGLOG_NUM_ARGS_OFFSET)

#define DBGLOG_GET_TIME_STAMP(arg) \
    ((arg & DBGLOG_TIMESTAMP_MASK) >> DBGLOG_TIMESTAMP_OFFSET)


/* Debug Log levels*/

typedef enum {
    DBGLOG_VERBOSE = 0,
    DBGLOG_INFO,
    DBGLOG_WARN2,
    DBGLOG_WARN,
    DBGLOG_ERR,
}DBGLOG_LOG_LVL; 

PREPACK struct dbglog_buf_s {
    struct dbglog_buf_s *next;
    A_UINT8             *buffer;
    A_UINT32             bufsize;
    A_UINT32             length;
    A_UINT32             count;
    A_UINT32             free;
} POSTPACK;

PREPACK struct dbglog_hdr_s {
    struct dbglog_buf_s *dbuf;
    A_UINT32             dropped;
} POSTPACK;

#define DBGLOG_MODULE_BITMAP_SIZE ((WLAN_MODULE_ID_MAX / 32) + 1)
#define DBGLOG_MAX_VAPID 15 /* 0-15 */
PREPACK struct dbglog_config_s {
    A_UINT32                    mod_id[DBGLOG_MODULE_BITMAP_SIZE]; /* bitmask to 							hold mod id config*/
    A_UINT32                    dbg_config; /* Mask to hold VAP,Log_lvl
                                               timestamp resl*/
} POSTPACK;

PREPACK struct dbglog_config_msg_s {
  struct dbglog_config_s    config;
  A_UINT32                  cfgvalid[DBGLOG_MODULE_BITMAP_SIZE + 1];
} POSTPACK;


#define DBGLOG_MODULE_ENABLE(cfgval, moduleid) \
    (cfgval[moduleid / 32] |= ((1 << ((moduleid / 32) ? (moduleid % 32): \
    moduleid)) & DBGLOG_MODULE_LOG_ENABLE_MASK))

#define DBGLOG_VAP_ENABLE(cfgval, vapid) \
    (cfgval |= ((1 << (vapid +  DBGLOG_VAP_LOG_ENABLE_OFFSET)) & \
    (DBGLOG_VAP_LOG_ENABLE_MASK)))

#define DBGLOG_LOG_LVL_ENABLE(cfgval, log_lvl) \
    (cfgval |= ((log_lvl << DBGLOG_LOG_LVL_ENABLE_OFFSET) & \
    (DBGLOG_LOG_LVL_ENABLE_MASK)))

#define DBGLOG_REPORTING_ENABLE(cfgval) \
    (cfgval |= ((1 << DBGLOG_REPORTING_ENABLE_OFFSET) & \
    (DBGLOG_REPORTING_ENABLE_MASK)))

#define DBGLOG_TIMESTAMP_RES_SET(cfgval, tsr) \
    (cfgval |= ((tsr << DBGLOG_TIMESTAMP_RESOLUTION_OFFSET) & \
    (DBGLOG_TIMESTAMP_RESOLUTION_MASK)))

#define DBGLOG_REPORT_SIZE_SET(cfgval, size) \
    (cfgval |= ((size << DBGLOG_REPORT_SIZE_OFFSET) & \
    (DBGLOG_REPORT_SIZE_MASK)))

#define DBGLOG_TIMER_ENABLE(cfgval) \
    (cfgval |= ((1 << DBGLOG_TIMER_ENABLE_OFFSET) & \
    (DBGLOG_TIMER_ENABLE_MASK)))

#ifdef __cplusplus
}
#endif

#ifndef ATH_TARGET
#include "athendpack.h"
#endif

#endif /* _DBGLOG_H_ */
