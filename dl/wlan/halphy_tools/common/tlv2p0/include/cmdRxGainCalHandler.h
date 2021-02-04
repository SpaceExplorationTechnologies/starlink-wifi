/*
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

// This is an auto-generated file from input\cmdRegReadHandler_v0.s
#ifndef _CMDRXGAINCALHANDLER_H_
#define _CMDRXGAINCALHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct rxgaincal_parms {
    A_UINT8	radioId;
    A_UINT8	chainIdx;   
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_RXGAINCAL_PARMS;

typedef struct rxgaincalrsp_parms {
    A_UINT8	radioId;
    A_UINT8	status;
    A_UINT8	band;
    A_INT8	refISS;
    A_UINT8	rate;
    A_UINT8	bandWidth;
    A_UINT8	chanIdx;
    A_UINT8	chainIdx;
    A_UINT16	numPackets;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_RXGAINCALRSP_PARMS;

typedef struct rxgaincal_sigl_done_parms {
    A_UINT8	radioId;
    A_UINT8	status;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_RXGAINCAL_SIGL_DONE_PARMS;

typedef struct rxgaincalrsp_done_parms {
    A_UINT8	radioId;
    A_UINT8	status;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_RXGAINCALRSP_DONE_PARMS;

typedef void (*RXGAINCAL_OP_FUNC)(void *pParms);
typedef void (*RXGAINCALRSP_OP_FUNC)(void *pParms);
typedef void (*RXGAINCAL_SIGL_DONE_OP_FUNC)(void *pParms);
typedef void (*RXGAINCALRSP_DONE_OP_FUNC)(void *pParms);

// Exposed functions

void* initRXGAINCALOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXGAINCALOp(void *pParms);

void* initRXGAINCALRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXGAINCALRSPOp(void *pParms);

void* initRXGAINCAL_SIGL_DONEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXGAINCAL_SIGL_DONEOp(void *pParms);

void* initRXGAINCALRSP_DONEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXGAINCALRSP_DONEOp(void *pParms);
#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDRXGAINCALHANDLER_H_

