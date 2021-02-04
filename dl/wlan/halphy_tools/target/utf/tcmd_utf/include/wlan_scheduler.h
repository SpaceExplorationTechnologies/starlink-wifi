/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//
// Copyright (c) 2008 Atheros Communications Inc.
// All rights reserved.
// $ATH_LICENSE_TARGET_C$
//

#ifndef _WLAN_SCHEDULER_H
#define _WLAN_SCHEDULER_H

typedef A_STATUS (*wlanIntrCallBack)(wlan_tcmd_dev_t *dev);

/* We can register callback handler for particular interrupt cause
 * only allow one module to do registration for one interrup source
 */
extern A_STATUS
wlan_scheduler_event_register(wlan_tcmd_dev_t *dev, WHAL_INT event, wlanIntrCallBack callback);

extern int
wlan_intr_handler(void *data);

extern A_BOOL
wlan_is_intr_pending(WHAL_INT);

#endif
