/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// Copyright (c) 2007-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#ifndef __WLAN_DSET_H__
#define __WLAN_DSET_H__

typedef PREPACK struct wow_config_dset {

    A_UINT8 valid_dset;
    A_UINT8 gpio_enable;
    A_UINT16 gpio_pin;
} POSTPACK WOW_CONFIG_DSET;

#endif
