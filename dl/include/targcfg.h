//------------------------------------------------------------------------------
// <copyright file="wmi_unified.h" company="Atheros">
//    Copyright (c) 2004-2010 Qualcomm Atheros Inc.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#ifndef __TARGCFG_H__
#define __TARGCFG_H__

#if defined(ATH_TARGET)
#include <osapi.h>   /* A_UINT32 */
#else
#include <a_types.h> /* A_UINT32 */
#endif

typedef struct _targcfg_t {
    A_UINT32 num_vdev;
    A_UINT32 num_peers;
    A_UINT32 num_peer_ast;
    A_UINT32 num_peer_keys;
    A_UINT32 num_peer_tid;
    A_UINT32 num_mcast_keys;
    A_UINT32 num_tx;
    A_UINT32 num_rx;
    A_UINT32 num_mgmt_tx;
    A_UINT32 num_mgmt_rx;
    A_UINT32 tx_chain_mask;
    A_UINT32 rx_chain_mask;
    A_UINT32 override; /* Override target with the values supplied above */
} targcfg_t;

#endif /* __TARGCFG_H__ */
