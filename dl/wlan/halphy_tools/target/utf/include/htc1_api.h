/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 * Copyright (c) 2007 Atheros Communications Inc.
 * All rights reserved.
 * $ATH_LICENSE_TARGET_C$
 *
 * This file contains definitions for hooking the legacy HTC 1.0 module.
 * Some additional APIs are provided to tune the HTC 1.0 module that are not available through
 * the current HTC 2.0 APIs.
 *  
 * 
 */
 
#ifndef HTC1_API_H_
#define HTC1_API_H_

#include <htc_api.h>

#if 0   /* move to .c file*/
extern A_UINT32 hi_htc_version;

#undef HTC_HDR_SZ
#define HTC_HDR_SZ          ((hi_htc_version < 2) ? 2 : 6 )
/* override HTC header size to use the HTC1.0 version */
#undef HTC_HDR_SZ
#define HTC_HDR_SZ  (UseHTC1()? 2 : 6)
#endif

    /* used by applications to hook in HTC 1.0 module dynamically */
#define HTC1_MODULE_INSTALL()    HTC1_module_Install(&_A_OS_INDIRECTION_TABLE->htc)

extern void HTC1_module_Install(struct htc_apis *pAPIs);

    /* set the static credits for the mailbox. This API must be called for each mailbox before
     * the initial call to HTC_ReturnBuffers().  The "Credits" parameter indicates the
     * number of credits to distribute for a mailbox.  This provides backward compatibility by implementing
     * an application-specific static credit distribution. */
extern void HTC1_SetMboxCredits(int Mbox, int Credits);


#endif /*HTC1_API_H_*/
