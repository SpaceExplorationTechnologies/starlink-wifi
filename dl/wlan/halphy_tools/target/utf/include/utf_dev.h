/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 * Copyright (c) 2004-2006 Atheros Communications Inc.
 * All rights reserved.
 * $ATH_LICENSE_TARGET_C$
 *
 * This is a subset of wlan_dev.h . It is used specifically for TCMD app. 
 * Inorder for devh_t to transparent with other modules ( wmi, hal), this
 * file has same names as in wlan_dev.h. Developers should include 
 * this file only for tcmd specific files.
 */

#ifndef _TCMD_DEV_H_
#define _TCMD_DEV_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <osapi.h>
#include <whal_api.h>
#include <wal.h>                
#include "ieee80211.h"

struct TCMD_TXRX;

#define UTF_HOST_MEM_REQ_FAST_CALIBRATION_SUPPORT 1
#define UTF_MAX_HOST_MEM_REQ ( 0 \
    + UTF_HOST_MEM_REQ_FAST_CALIBRATION_SUPPORT \
    )

typedef struct _wlan_tcmd_dev_t {
    WHAL_STRUCT                 *pWhalStruct;         /* Atheros WHAL */
    wal_pdev_t                  *pdev;
    struct TCMD_TXRX            *pTcmdTxRx;
    WHAL_OPMODE                  ic_opmode;
    WLAN_PHY_MODE                ic_curmode;
    A_UINT8                     ic_myaddr[IEEE80211_ADDR_LEN];
    struct wmi_info             *wmi;
    WHAL_WLAN_MODE_CAPABILITY   ic_boardMode;   /* wlan mode from eeprom */
    A_UINT16                    fixRateSetMask;
    wlan_host_mem_req           host_mem_req[UTF_MAX_HOST_MEM_REQ];
} wlan_tcmd_dev_t;


//extern wlan_vdev_t tcmd_dev;
extern wlan_tcmd_dev_t tcmd_dev;

#define IEEE80211_M_STA WHAL_M_STA
#define IEEE80211_M_IBSS WHAL_M_IBSS

#ifdef __cplusplus
}
#endif

#endif /* _TCMD_DEV_H_ */
