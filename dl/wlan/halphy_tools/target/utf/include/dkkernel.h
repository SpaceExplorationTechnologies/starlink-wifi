/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// dkkernel.h - contians definitons of dkkernel structres 

// Copyright (c) 2000 Atheros Communications, Inc., All Rights Reserved
// $ATH_LICENSE_TARGET_C$

#ifndef	__INCdkkernelh
#define	__INCdkkernelh

#include "event.h"
#include "hw.h"

#define INVALID_CLIENT 	     -1

typedef struct kpClient {
	A_INT32 cliId;
	A_INT32 busy;
	A_UINT32 regPhyAddr;
	A_UINT32 regVirAddr;
	A_UINT32 regRange;
	A_UINT32 memPhyAddr;
	A_UINT32 memVirAddr;
	A_UINT32 memSize;
	A_UINT32 irqLevel;
	EVENT_QUEUE *isrEventQ;
	EVENT_QUEUE *triggeredQ;
	EVENT_QUEUE *dsrQ;
	EVENT_ARRAY eventArray;
} KP_CLIENT;

typedef struct kpClientInfo {
	A_UINT32 regPhyAddr;
	A_UINT32 regVirAddr;
	A_UINT32 regRange;
	A_UINT32 memPhyAddr;
	A_UINT32 memVirAddr;
	A_UINT32 memSize;
	A_UINT32 irqLevel;
} KP_CLIENT_INFO;


#define VALID_CLIENT(x) ((x)->cliId != INVALID_CLIENT)
#define BUSY_CLIENT(x) ((x)->busy != 0)

A_INT32 kpInit(void);

void kpExit(void);

A_INT32 kpOpen
(	
	A_UINT16 devIndex
);

void kpClose
(
	A_UINT32 kpHandle
);

A_INT32 kpGetClientInfo
(
	A_UINT32 kpHandle,
	KP_CLIENT_INFO *kpClientInfo
);

A_INT16 kpCreateEvent
(
	A_UINT32 kpHandle,
    	A_UINT32 type, 
    	A_UINT32 persistent, 
    	A_UINT32 param1,
    	A_UINT32 param2,
    	A_UINT32 param3,
    	EVT_HANDLE eventHandle
);

void kpGetNextEvent	
(
	A_UINT32 kpHandle,
	EVENT_STRUCT *pEvent
);

void kpCfgWrite
(
	A_UINT32 kpHandle,	
	A_UINT32 address,                    /* the address to write */
	A_UINT32 size,
	A_UINT32 data                        /* value to write */
);

A_INT32 kpCfgRead
(
 	A_UINT32 kpHandle,
    	A_UINT32 address,                    /* the address to read from */
	A_UINT32 size,
	A_UINT32 *data
);

//event type definitions
#define INTERRUPT_F2    1
#define TIMEOUT         4
#define ISR_INTERRUPT   0x10
#define DEFAULT_TIMEOUT 0xff

#endif // __INCdkkernelh


