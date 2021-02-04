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

#ifndef _WDS_ADDR_H_
#define _WDS_ADDR_H_


#include "wlan_module_ids.h"
#ifndef ATH_TARGET
#include "athstartpack.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct wds_table_entry {
    TAILQ_ENTRY(wds_table_entry)     wds_list;
    LIST_ENTRY(wds_table_entry)      wds_entry_hash;
    unsigned char                    peer_mac[6];
    unsigned char                    dest_mac[6];
    struct ieee80211vap              *vap;
};

struct wds_table {
    rwlock_t                         wds_table_lock;
    TAILQ_HEAD(, wds_table_entry)    wds_entry;
    ATH_LIST_HEAD(, wds_table_entry) wds_table_hash[32];
};

void
wds_table_init(struct wds_table *table);

void
wds_table_uninit(struct wds_table *table);

int
wds_find(ol_scn_t scn, unsigned char *dest_mac, unsigned char *peer_mac, struct ieee80211vap **vap);

void
wds_addr_init(wmi_unified_t wmi_handle);

void
wds_addr_detach(wmi_unified_t wmi_handle);

#ifdef __cplusplus
}
#endif

#ifndef ATH_TARGET
#include "athendpack.h"
#endif

#endif /* _WDS_ADDR_H_ */

