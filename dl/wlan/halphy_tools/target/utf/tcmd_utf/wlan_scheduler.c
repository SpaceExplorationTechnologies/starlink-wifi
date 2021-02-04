/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 * Copyright (c) 2004-2005 Atheros Communications Inc.
 * All rights reserved.
 * $ATH_LICENSE_TARGET_C$
 *
 * This module implements the wlan scheduler
 *
 * $Id: //depot/sw/branches/qca_main_wifi2.0/perf_pwr_offload/drivers/target/apps/utf/tcmd_utf/wlan_scheduler.c#2 $
 */
#include <osapi.h>
#include <athdefs.h>
#include <wmi.h>
#include "utf_dev.h"
#include "whal_api.h"
#include "wlan_scheduler.h"

#define MAX_WALN_INTR_EVEN  12

static wlanIntrCallBack intrfnArray[MAX_WALN_INTR_EVEN];
static A_UINT32 gYieldMask;

#if 0
A_STATUS
wlan_scheduler_event_register(devh_t  *dev, WHAL_INT event, wlanIntrCallBack callback)
{
    A_UINT32    count = 0;

    while (event) {
        if (event & 1) {
            //A_PRINTF(".reg call %d\n", count);
            intrfnArray[count] = callback;
        }

        event >>= 1;
        count ++;
    }

    return A_OK;
}
#endif

A_INT32
wlan_intr_handler(void *data)
{
    wlan_tcmd_dev_t *dev;
    A_UINT32         masked = 0, pendingMask = 1;
    A_UINT32         count = 0;
    A_UINT32         ret = A_HANDLER_DONE;

    dev = (wlan_tcmd_dev_t *) data;

    whalGetPendingInterrupts(&masked);
    masked |= gYieldMask;
    //A_PRINTF(".mask %x\n", masked);

    while (masked) {
        if (masked & 1) {
            if (intrfnArray[count]) {
                if (intrfnArray[count](dev) == A_PENDING) {
                    gYieldMask |= pendingMask;
                    ret = A_HANDLER_YIELD;
                } else {
                    gYieldMask &= ~pendingMask;
                }
            }
        }

        masked >>= 1;
        pendingMask <<= 1;
        count ++;
    }

    return ret;
}
