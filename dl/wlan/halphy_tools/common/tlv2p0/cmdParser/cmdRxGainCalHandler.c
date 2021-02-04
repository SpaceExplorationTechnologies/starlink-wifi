/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

// This is an auto-generated file from input\cmdRegReadHandler_v0.s
#include "tlv2Inc.h"
#include "cmdRxGainCalHandler.h"

SRAM_TEXT
void* initRXGAINCALOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_RXGAINCAL_PARMS  *pRXGAINCALParms = (CMD_RXGAINCAL_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pRXGAINCALParms->radioId = pParmDict[PARM_RADIOID].v.valU8;
    pRXGAINCALParms->chainIdx = pParmDict[PARM_CHAINIDX].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_RADIOID, (A_UINT32)(((A_UINT32)&(pRXGAINCALParms->radioId)) - (A_UINT32)pRXGAINCALParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINIDX, (A_UINT32)(((A_UINT32)&(pRXGAINCALParms->chainIdx)) - (A_UINT32)pRXGAINCALParms), pParmsOffset);
    return((void*) pRXGAINCALParms);
}

SRAM_DATA
static RXGAINCAL_OP_FUNC RXGAINCALOpFunc = NULL;

SRAM_TEXT
TLV2_API void registerRXGAINCALHandler(RXGAINCAL_OP_FUNC fp)
{
    RXGAINCALOpFunc = fp;
}

SRAM_TEXT
A_BOOL RXGAINCALOp(void *pParms)
{
    CMD_RXGAINCAL_PARMS *pRXGAINCALParms = (CMD_RXGAINCAL_PARMS *)pParms;

#ifdef _DEBUG
    A_PRINTF("RXGAINCALOp: radioId %u\n", (int)pRXGAINCALParms->radioId);
    A_PRINTF("RXGAINCALOp: chainIdx %u\n", (int)pRXGAINCALParms->chainIdx);
#endif //_DEBUG

    if (NULL != RXGAINCALOpFunc) {
        (*RXGAINCALOpFunc)(pRXGAINCALParms);
    }
    return(TRUE);
}

SRAM_TEXT
void* initRXGAINCALRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_RXGAINCALRSP_PARMS  *pRXGAINCALRSPParms = (CMD_RXGAINCALRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pRXGAINCALRSPParms->radioId = pParmDict[PARM_RADIOID].v.valU8;
    pRXGAINCALRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pRXGAINCALRSPParms->band = pParmDict[PARM_BAND].v.valU8;
    pRXGAINCALRSPParms->refISS = pParmDict[PARM_REFISS].v.valS8;
    pRXGAINCALRSPParms->rate = pParmDict[PARM_RATE].v.valU8;
    pRXGAINCALRSPParms->bandWidth = pParmDict[PARM_BANDWIDTH].v.valU8;
    pRXGAINCALRSPParms->chanIdx = pParmDict[PARM_CHANIDX].v.valU8;
    pRXGAINCALRSPParms->chainIdx = pParmDict[PARM_CHAINIDX].v.valU8;
    pRXGAINCALRSPParms->numPackets = pParmDict[PARM_NUMPACKETS].v.valU16;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_RADIOID, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSPParms->radioId)) - (A_UINT32)pRXGAINCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSPParms->status)) - (A_UINT32)pRXGAINCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BAND, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSPParms->band)) - (A_UINT32)pRXGAINCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_REFISS, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSPParms->refISS)) - (A_UINT32)pRXGAINCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATE, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSPParms->rate)) - (A_UINT32)pRXGAINCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BANDWIDTH, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSPParms->bandWidth)) - (A_UINT32)pRXGAINCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHANIDX, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSPParms->chanIdx)) - (A_UINT32)pRXGAINCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINIDX, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSPParms->chainIdx)) - (A_UINT32)pRXGAINCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMPACKETS, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSPParms->numPackets)) - (A_UINT32)pRXGAINCALRSPParms), pParmsOffset);
    return((void*) pRXGAINCALRSPParms);
}

SRAM_DATA
static RXGAINCALRSP_OP_FUNC RXGAINCALRSPOpFunc = NULL;

SRAM_TEXT
TLV2_API void registerRXGAINCALRSPHandler(RXGAINCALRSP_OP_FUNC fp)
{
    RXGAINCALRSPOpFunc = fp;
}

SRAM_TEXT
A_BOOL RXGAINCALRSPOp(void *pParms)
{
    CMD_RXGAINCALRSP_PARMS *pRXGAINCALRSPParms = (CMD_RXGAINCALRSP_PARMS *)pParms;

#ifdef _DEBUG
    A_PRINTF("RXGAINCALRSPOp: radioId %u\n", (int)pRXGAINCALRSPParms->radioId);
    A_PRINTF("RXGAINCALRSPOp: status %u\n", (int)pRXGAINCALRSPParms->status);
    A_PRINTF("RXGAINCALRSPOp: band %u\n", (int)pRXGAINCALRSPParms->band);
    A_PRINTF("RXGAINCALRSPOp: refISS %d\n", (int)pRXGAINCALRSPParms->refISS);
    A_PRINTF("RXGAINCALRSPOp: rate %u\n", (int)pRXGAINCALRSPParms->rate);
    A_PRINTF("RXGAINCALRSPOp: bandWidth %u\n", (int)pRXGAINCALRSPParms->bandWidth);
    A_PRINTF("RXGAINCALRSPOp: chanIdx %u\n", (int)pRXGAINCALRSPParms->chanIdx);
    A_PRINTF("RXGAINCALRSPOp: chainIdx %u\n", (int)pRXGAINCALRSPParms->chainIdx);
    A_PRINTF("RXGAINCALRSPOp: numPackets %u\n", (int)pRXGAINCALRSPParms->numPackets);
#endif //_DEBUG

    if (NULL != RXGAINCALRSPOpFunc) {
        (*RXGAINCALRSPOpFunc)(pRXGAINCALRSPParms);
    }
    return(TRUE);
}

SRAM_TEXT
void* initRXGAINCAL_SIGL_DONEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_RXGAINCAL_SIGL_DONE_PARMS  *pRXGAINCAL_SIGL_DONEParms = (CMD_RXGAINCAL_SIGL_DONE_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pRXGAINCAL_SIGL_DONEParms->radioId = pParmDict[PARM_RADIOID].v.valU8;
    //pRXGAINCAL_SIGL_DONEParms->chainIdx = pParmDict[PARM_CHAINIDX].v.valU8;
    pRXGAINCAL_SIGL_DONEParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_RADIOID, (A_UINT32)(((A_UINT32)&(pRXGAINCAL_SIGL_DONEParms->radioId)) - (A_UINT32)pRXGAINCAL_SIGL_DONEParms), pParmsOffset);
   // fillParmOffsetTbl((A_UINT32)PARM_CHAINIDX, (A_UINT32)(((A_UINT32)&(pRXGAINCAL_SIGL_DONEParms->chainIdx)) - (A_UINT32)pRXGAINCAL_SIGL_DONEParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pRXGAINCAL_SIGL_DONEParms->status)) - (A_UINT32)pRXGAINCAL_SIGL_DONEParms), pParmsOffset);
    return((void*) pRXGAINCAL_SIGL_DONEParms);
}

SRAM_DATA
static RXGAINCAL_SIGL_DONE_OP_FUNC RXGAINCAL_SIGL_DONEOpFunc = NULL;

SRAM_TEXT
TLV2_API void registerRXGAINCAL_SIGL_DONEHandler(RXGAINCAL_SIGL_DONE_OP_FUNC fp)
{
    RXGAINCAL_SIGL_DONEOpFunc = fp;
}

SRAM_TEXT
A_BOOL RXGAINCAL_SIGL_DONEOp(void *pParms)
{
    CMD_RXGAINCAL_SIGL_DONE_PARMS *pRXGAINCAL_SIGL_DONEParms = (CMD_RXGAINCAL_SIGL_DONE_PARMS *)pParms;

#ifdef _DEBUG
    A_PRINTF_ALWAYS("RXGAINCAL_SIGL_DONEOp: radioId %d\n", (int)pRXGAINCAL_SIGL_DONEParms->radioId);
   // A_PRINTF_ALWAYS("RXGAINCAL_SIGL_DONEOp: chainIdx %d\n", (int)pRXGAINCAL_SIGL_DONEParms->chainIdx);
    A_PRINTF_ALWAYS("RXGAINCAL_SIGL_DONEOp: status %d\n", (int)pRXGAINCAL_SIGL_DONEParms->status);
#endif //_DEBUG

    if (NULL != RXGAINCAL_SIGL_DONEOpFunc) {
        (*RXGAINCAL_SIGL_DONEOpFunc)(pRXGAINCAL_SIGL_DONEParms);
    }
    return(TRUE);
}

SRAM_TEXT
void* initRXGAINCALRSP_DONEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_RXGAINCALRSP_DONE_PARMS  *pRXGAINCALRSP_DONEParms = (CMD_RXGAINCALRSP_DONE_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pRXGAINCALRSP_DONEParms->radioId = pParmDict[PARM_RADIOID].v.valU8;
    pRXGAINCALRSP_DONEParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_RADIOID, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSP_DONEParms->radioId)) - (A_UINT32)pRXGAINCALRSP_DONEParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pRXGAINCALRSP_DONEParms->status)) - (A_UINT32)pRXGAINCALRSP_DONEParms), pParmsOffset);
    return((void*) pRXGAINCALRSP_DONEParms);
}

SRAM_DATA
static RXGAINCALRSP_DONE_OP_FUNC RXGAINCALRSP_DONEOpFunc = NULL;

SRAM_TEXT
TLV2_API void registerRXGAINCALRSP_DONEHandler(RXGAINCALRSP_DONE_OP_FUNC fp)
{
    RXGAINCALRSP_DONEOpFunc = fp;
}

SRAM_TEXT
A_BOOL RXGAINCALRSP_DONEOp(void *pParms)
{
    CMD_RXGAINCALRSP_DONE_PARMS *pRXGAINCALRSP_DONEParms = (CMD_RXGAINCALRSP_DONE_PARMS *)pParms;

#ifdef _DEBUG
    A_PRINTF_ALWAYS("RXGAINCALRSP_DONEOp: radioId %d\n", (int)pRXGAINCALRSP_DONEParms->radioId);
    A_PRINTF_ALWAYS("RXGAINCALRSP_DONEOp: status %d\n", (int)pRXGAINCALRSP_DONEParms->status);
#endif //_DEBUG

    if (NULL != RXGAINCALRSP_DONEOpFunc) {
        (*RXGAINCALRSP_DONEOpFunc)(pRXGAINCALRSP_DONEParms);
    }
    return(TRUE);
}

