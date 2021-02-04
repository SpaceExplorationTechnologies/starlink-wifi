/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/* hwext.h - external declarations environment hardware access */

/*
 * Copyright (c) 2000 Atheros Communications, Inc., All Rights Reserved
 * $ATH_LICENSE_TARGET_C$
 */

/* 
modification history
--------------------
*/

#ifndef __INChwexth
#define __INChwexth

#include "hw.h"

/////////////////////////////////////
// function declarations

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


A_STATUS envInit
(
	A_BOOL debugMode
);

void envCleanup
(
	A_BOOL closeDriver
);

A_STATUS deviceInit
(
	A_UINT16 devIndex,
	A_UINT16 device_fn
);

void deviceCleanup
(
	A_UINT16 devIndex        
);

A_INT16 hwCreateEvent
(
	A_UINT16 devIndex,
	PIPE_CMD *pCmd
);

A_INT16 hwCreateEvt
(
        A_UINT16 devIndex,
        A_UINT32 type,
        A_UINT32 persistent,
        A_UINT32 param1,
        A_UINT32 param2,
        A_UINT32 param3,
        A_UINT16 eventID,
        A_UINT16 f2Handle
);


A_INT16 hwGetNextEvent
(
	A_UINT16 devIndex,
	void *pBuf
);

A_UINT32 hwMemRead32
(
	A_UINT16 devIndex,
	A_UINT32 memAddress
);

void hwMemWrite32
(
	A_UINT16 devIndex,
	A_UINT32 memAddress, 
	A_UINT32 writeValue
);

#if defined(AR6320)
void hwMemClear
(
    A_UINT16 devIndex,
    A_UINT32 memAddress,
    A_UINT32 numBytes
);
#endif //AR6320

A_UINT32 hwCfgRead32
(
        A_UINT16 devIndex,
        A_UINT32 address
);

A_INT16 hwMemWriteBlock
(
	A_UINT16 devIndex,
	A_UCHAR    *pBuffer,
	A_UINT32 length,
	A_UINT32 *pPhysAddr
);

A_INT16 hwMemReadBlock
(
	A_UINT16 devIndex,
	A_UCHAR    *pBuffer,
	A_UINT32 physAddr,
	A_UINT32 length
);

void hwInit
(
	MDK_WLAN_DEV_INFO *pdevInfo, A_UINT32 resetMask
);

void deep_sleep(A_UINT32 se) ;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INChwexth */
