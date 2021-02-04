/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//-----------------------------------------------------------------------------
// calProc.h - Process calibration header include and definitions 
//
// Copyright (c) 2004 Atheros Communications, Inc., All Rights Reserved
//-----------------------------------------------------------------------------

#ifndef _UTF_H
#define _UTF_H

typedef struct _chipSpecificFunc_struct {
    void   (*chipAttach)(void);
    void   (*txFunc)(void);
    void   (*genCalData)(void);
    void   (*applyCalData)(void);
    void   (*genRxGainCalData)(void);

} _CHIP_SPECIFIC_FUNC;

typedef struct _hostIF_struct {
    //A_INT32 (*hostIFAttach)(A_INT32 debugMode, A_UINT16 port);
    void (*hostIFAttach)(void);
    A_BOOL (*hostIFCmdStreamFetch)(A_UINT8 *buf, A_UINT8 **pCmdStream, A_UINT32 *cmdStreamLen);
    A_INT32 (*hostIFProcessing)(A_UINT8 *buf);
} _HOSTIF_INFO;


//
// -----------------------------------------------------------------------------
// Architectural Notes: 
//    When providing support to a new chip or host IF, the following must be provided.
//
// 
// The Chip must provide this function
extern void registerOneChip(void);
// -------------
// The Host IF provides this function
extern void registerOneHostIF(void);
/* int i;
    for (i=0;i<HOSTIF_MAX;i++) {
        if (NULL != HostIFRegFunc[i]) {
            (hostIFRegFunc[i])();
        }           
    } */


//
// -----------------------------------------------------------------------------
// Architectural Notes: 
//   Functions that should be called by the chip and the host interface.
//
// ---------------------
//   all host interface specific function needs to call the function with cmdStream and length
SRAM_TEXT
A_BOOL cmdStreamParsingAndProcessing(A_UINT8 *cmdStreamBuf, A_UINT32 streamLen, A_UINT8 **payload, A_UINT16 *payloadLen);

void registerOneChip(void);
void registerOneHostIF(void);
void bindHostIFFunc(_HOSTIF_INFO *hostFunc);
void bindChipSpecificFunc(_CHIP_SPECIFIC_FUNC *fns);

A_INT32 hostIFProcessing(A_UINT8 *buf);

#endif //_UTF_H
