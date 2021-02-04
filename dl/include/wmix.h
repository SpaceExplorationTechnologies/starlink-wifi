/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// <copyright file="wmix.h" company="Atheros">
//    Copyright (c) 2004-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

/*
 * This file contains extensions of the WMI protocol specified in the
 * Wireless Module Interface (WMI).  It includes definitions of all
 * extended commands and events.  Extensions include useful commands
 * that are not directly related to wireless activities.  They may
 * be hardware-specific, and they might not be supported on all
 * implementations.
 *
 * Extended WMIX commands are encapsulated in a WMI message with
 * cmd=WMI_EXTENSION_CMD.
 */

#ifndef _WMIX_H_
#define _WMIX_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ATH_TARGET
#include "athstartpack.h"
#endif

#include "dbglog.h"

/*
 * Extended WMI commands are those that are needed during wireless
 * operation, but which are not really wireless commands.  This allows,
 * for instance, platform-specific commands.  Extended WMI commands are
 * embedded in a WMI command message with WMI_COMMAND_ID=WMI_EXTENSION_CMDID.
 * Extended WMI events are similarly embedded in a WMI event message with
 * WMI_EVENT_ID=WMI_EXTENSION_EVENTID.
 */
typedef PREPACK struct {
    A_UINT32    commandId;
} POSTPACK WMIX_CMD_HDR;

typedef enum {
    WMIX_DSETOPEN_REPLY_CMDID           = 0x2001,
    WMIX_DSETDATA_REPLY_CMDID,
    WMIX_HB_CHALLENGE_RESP_CMDID,
    WMIX_DBGLOG_CFG_MODULE_CMDID,
    WMIX_PROF_CFG_CMDID,                 /* 0x200a */
    WMIX_PROF_ADDR_SET_CMDID,
    WMIX_PROF_START_CMDID,
    WMIX_PROF_STOP_CMDID,
    WMIX_PROF_COUNT_GET_CMDID,
} WMIX_COMMAND_ID;

typedef enum {
    WMIX_DSETOPENREQ_EVENTID            = 0x3001,
    WMIX_DSETCLOSE_EVENTID,
    WMIX_DSETDATAREQ_EVENTID,
    WMIX_HB_CHALLENGE_RESP_EVENTID,
    WMIX_DBGLOG_EVENTID,
    WMIX_PROF_COUNT_EVENTID,
    WMIX_PKTLOG_EVENTID,
} WMIX_EVENT_ID;

/*
 * =============DataSet support=================
 */

/*
 * WMIX_DSETOPENREQ_EVENTID
 * DataSet Open Request Event
 */
typedef PREPACK struct {
    A_UINT32 dset_id;
    A_UINT32 targ_dset_handle;  /* echo'ed, not used by Host, */
    A_UINT32 targ_reply_fn;     /* echo'ed, not used by Host, */
    A_UINT32 targ_reply_arg;    /* echo'ed, not used by Host, */
} POSTPACK WMIX_DSETOPENREQ_EVENT;

/*
 * WMIX_DSETCLOSE_EVENTID
 * DataSet Close Event
 */
typedef PREPACK struct {
    A_UINT32 access_cookie;
} POSTPACK WMIX_DSETCLOSE_EVENT;

/*
 * WMIX_DSETDATAREQ_EVENTID
 * DataSet Data Request Event
 */
typedef PREPACK struct {
    A_UINT32 access_cookie;
    A_UINT32 offset;
    A_UINT32 length;
    A_UINT32 targ_buf;         /* echo'ed, not used by Host, */
    A_UINT32 targ_reply_fn;    /* echo'ed, not used by Host, */
    A_UINT32 targ_reply_arg;   /* echo'ed, not used by Host, */
} POSTPACK WMIX_DSETDATAREQ_EVENT;

typedef PREPACK struct {
    A_UINT32              status;
    A_UINT32              targ_dset_handle;
    A_UINT32              targ_reply_fn;
    A_UINT32              targ_reply_arg;
    A_UINT32              access_cookie;
    A_UINT32              size;
    A_UINT32              version;
} POSTPACK WMIX_DSETOPEN_REPLY_CMD;

typedef PREPACK struct {
    A_UINT32              status;
    A_UINT32              targ_buf;
    A_UINT32              targ_reply_fn;
    A_UINT32              targ_reply_arg;
    A_UINT32              length;
    A_UINT8               buf[1];
} POSTPACK WMIX_DSETDATA_REPLY_CMD;


/*
 * =============Error Detection support=================
 */

/*
 * WMIX_HB_CHALLENGE_RESP_CMDID
 * Heartbeat Challenge Response command
 */
typedef PREPACK struct {
    A_UINT32              cookie;
    A_UINT32              source;
} POSTPACK WMIX_HB_CHALLENGE_RESP_CMD;

/*
 * WMIX_HB_CHALLENGE_RESP_EVENTID
 * Heartbeat Challenge Response Event
 */
#define WMIX_HB_CHALLENGE_RESP_EVENT WMIX_HB_CHALLENGE_RESP_CMD

typedef PREPACK struct {
    struct dbglog_config_s config;
} POSTPACK WMIX_DBGLOG_CFG_MODULE_CMD;

/*
 * =============Target Profiling support=================
 */

typedef PREPACK struct {
    A_UINT32 period; /* Time (in 30.5us ticks) between samples */
    A_UINT32 nbins;
} POSTPACK WMIX_PROF_CFG_CMD;

typedef PREPACK struct {
    A_UINT32 addr;
} POSTPACK WMIX_PROF_ADDR_SET_CMD;

/*
 * Target responds to Hosts's earlier WMIX_PROF_COUNT_GET_CMDID request
 * using a WMIX_PROF_COUNT_EVENT with
 *   addr set to the next address
 *   count set to the corresponding count
 */
typedef PREPACK struct {
    A_UINT32              addr;
    A_UINT32              count;
} POSTPACK WMIX_PROF_COUNT_EVENT;

#ifndef ATH_TARGET
#include "athendpack.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* _WMIX_H_ */


