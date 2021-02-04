// This is an auto-generated file from input/cmdRxDcoHandler.s


#ifdef USE_TLV2_EXTCMD

#include "tlv2Inc.h"
#include "cmdRxDcoHandler.h"

void* initRXDCOGROUPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_RXDCOGROUP_PARMS  *pRXDCOGROUPParms = (CMD_RXDCOGROUP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pRXDCOGROUPParms->cmdIdRxDcoGroup = pParmDict[PARM_CMDIDRXDCOGROUP].v.valU8;
    pRXDCOGROUPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pRXDCOGROUPParms->bbDcocRange = pParmDict[PARM_BBDCOCRANGE].v.valU8;
    pRXDCOGROUPParms->rfDcocRange = pParmDict[PARM_RFDCOCRANGE].v.valU8;
    pRXDCOGROUPParms->chainMask = pParmDict[PARM_CHAINMASK].v.valU8;
    pRXDCOGROUPParms->lpbkMode = pParmDict[PARM_LPBKMODE].v.valU8;
    pRXDCOGROUPParms->rfFirst = pParmDict[PARM_RFFIRST].v.valU8;
    pRXDCOGROUPParms->initLUT = pParmDict[PARM_INITLUT].v.valU8;
    pRXDCOGROUPParms->rfOvrd = pParmDict[PARM_RFOVRD].v.valU8;
    pRXDCOGROUPParms->bbOvrd = pParmDict[PARM_BBOVRD].v.valU8;
    pRXDCOGROUPParms->numGain = pParmDict[PARM_NUMGAIN].v.valU8;
    pRXDCOGROUPParms->band = pParmDict[PARM_BAND].v.valU8;
    pRXDCOGROUPParms->chain = pParmDict[PARM_CHAIN].v.valU8;
    pRXDCOGROUPParms->rfBB = pParmDict[PARM_RFBB].v.valU8;
    pRXDCOGROUPParms->depth = pParmDict[PARM_DEPTH].v.valU8;
    pRXDCOGROUPParms->useCosimSetting = pParmDict[PARM_USECOSIMSETTING].v.valU8;
    memset(pRXDCOGROUPParms->gainLut, 0, sizeof(pRXDCOGROUPParms->gainLut));
    memset(pRXDCOGROUPParms->rfDocLut, 0, sizeof(pRXDCOGROUPParms->rfDocLut));
    memset(pRXDCOGROUPParms->bbDocLut, 0, sizeof(pRXDCOGROUPParms->bbDocLut));
    memset(pRXDCOGROUPParms->inputTable2SwProcessing, 0, sizeof(pRXDCOGROUPParms->inputTable2SwProcessing));
    pRXDCOGROUPParms->sleepTime = pParmDict[PARM_SLEEPTIME].v.valU16;
    pRXDCOGROUPParms->threshold = pParmDict[PARM_THRESHOLD].v.valU16;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_CMDIDRXDCOGROUP, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->cmdIdRxDcoGroup)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->phyId)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BBDCOCRANGE, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->bbDcocRange)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RFDCOCRANGE, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->rfDcocRange)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINMASK, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->chainMask)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LPBKMODE, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->lpbkMode)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RFFIRST, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->rfFirst)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_INITLUT, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->initLUT)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RFOVRD, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->rfOvrd)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BBOVRD, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->bbOvrd)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMGAIN, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->numGain)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BAND, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->band)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAIN, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->chain)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RFBB, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->rfBB)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DEPTH, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->depth)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_USECOSIMSETTING, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->useCosimSetting)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GAINLUT, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->gainLut)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RFDOCLUT, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->rfDocLut)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BBDOCLUT, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->bbDocLut)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_INPUTTABLE2SWPROCESSING, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->inputTable2SwProcessing)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SLEEPTIME, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->sleepTime)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_THRESHOLD, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPParms->threshold)) - (A_UINT32)pRXDCOGROUPParms), pParmsOffset);
    return((void*) pRXDCOGROUPParms);
}

static RXDCOGROUP_OP_FUNC RXDCOGROUPOpFunc = NULL;

TLV2_API void registerRXDCOGROUPHandler(RXDCOGROUP_OP_FUNC fp)
{
    RXDCOGROUPOpFunc = fp;
}

A_BOOL RXDCOGROUPOp(void *pParms)
{
    CMD_RXDCOGROUP_PARMS *pRXDCOGROUPParms = (CMD_RXDCOGROUP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("RXDCOGROUPOp: cmdIdRxDcoGroup %u\n", pRXDCOGROUPParms->cmdIdRxDcoGroup);
    A_PRINTF("RXDCOGROUPOp: phyId %u\n", pRXDCOGROUPParms->phyId);
    A_PRINTF("RXDCOGROUPOp: bbDcocRange %u\n", pRXDCOGROUPParms->bbDcocRange);
    A_PRINTF("RXDCOGROUPOp: rfDcocRange %u\n", pRXDCOGROUPParms->rfDcocRange);
    A_PRINTF("RXDCOGROUPOp: chainMask %u\n", pRXDCOGROUPParms->chainMask);
    A_PRINTF("RXDCOGROUPOp: lpbkMode %u\n", pRXDCOGROUPParms->lpbkMode);
    A_PRINTF("RXDCOGROUPOp: rfFirst %u\n", pRXDCOGROUPParms->rfFirst);
    A_PRINTF("RXDCOGROUPOp: initLUT %u\n", pRXDCOGROUPParms->initLUT);
    A_PRINTF("RXDCOGROUPOp: rfOvrd %u\n", pRXDCOGROUPParms->rfOvrd);
    A_PRINTF("RXDCOGROUPOp: bbOvrd %u\n", pRXDCOGROUPParms->bbOvrd);
    A_PRINTF("RXDCOGROUPOp: numGain %u\n", pRXDCOGROUPParms->numGain);
    A_PRINTF("RXDCOGROUPOp: band %u\n", pRXDCOGROUPParms->band);
    A_PRINTF("RXDCOGROUPOp: chain %u\n", pRXDCOGROUPParms->chain);
    A_PRINTF("RXDCOGROUPOp: rfBB %u\n", pRXDCOGROUPParms->rfBB);
    A_PRINTF("RXDCOGROUPOp: depth %u\n", pRXDCOGROUPParms->depth);
    A_PRINTF("RXDCOGROUPOp: useCosimSetting %u\n", pRXDCOGROUPParms->useCosimSetting);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 20 entries
    {
        A_PRINTF("RXDCOGROUPOp: gainLut %u\n", pRXDCOGROUPParms->gainLut[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 80 entries
    {
        A_PRINTF("RXDCOGROUPOp: rfDocLut %u\n", pRXDCOGROUPParms->rfDocLut[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 80 entries
    {
        A_PRINTF("RXDCOGROUPOp: bbDocLut %u\n", pRXDCOGROUPParms->bbDocLut[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 100 entries
    {
        A_PRINTF("RXDCOGROUPOp: inputTable2SwProcessing %u\n", pRXDCOGROUPParms->inputTable2SwProcessing[i]);
    }
    A_PRINTF("RXDCOGROUPOp: sleepTime %u\n", pRXDCOGROUPParms->sleepTime);
    A_PRINTF("RXDCOGROUPOp: threshold %u\n", pRXDCOGROUPParms->threshold);
#endif //_DEBUG

    if (NULL != RXDCOGROUPOpFunc) {
        (*RXDCOGROUPOpFunc)(pRXDCOGROUPParms);
    }
    return(TRUE);
}

void* initRXDCOGROUPRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_RXDCOGROUPRSP_PARMS  *pRXDCOGROUPRSPParms = (CMD_RXDCOGROUPRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pRXDCOGROUPRSPParms->cmdIdRxDcoGroup = pParmDict[PARM_CMDIDRXDCOGROUP].v.valU8;
    pRXDCOGROUPRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pRXDCOGROUPRSPParms->bbDcocRange = pParmDict[PARM_BBDCOCRANGE].v.valU8;
    pRXDCOGROUPRSPParms->rfDcocRange = pParmDict[PARM_RFDCOCRANGE].v.valU8;
    pRXDCOGROUPRSPParms->chainMask = pParmDict[PARM_CHAINMASK].v.valU8;
    pRXDCOGROUPRSPParms->lpbkMode = pParmDict[PARM_LPBKMODE].v.valU8;
    pRXDCOGROUPRSPParms->rfFirst = pParmDict[PARM_RFFIRST].v.valU8;
    pRXDCOGROUPRSPParms->initLUT = pParmDict[PARM_INITLUT].v.valU8;
    pRXDCOGROUPRSPParms->rfOvrd = pParmDict[PARM_RFOVRD].v.valU8;
    pRXDCOGROUPRSPParms->bbOvrd = pParmDict[PARM_BBOVRD].v.valU8;
    pRXDCOGROUPRSPParms->numGain = pParmDict[PARM_NUMGAIN].v.valU8;
    pRXDCOGROUPRSPParms->band = pParmDict[PARM_BAND].v.valU8;
    pRXDCOGROUPRSPParms->chain = pParmDict[PARM_CHAIN].v.valU8;
    pRXDCOGROUPRSPParms->rfBB = pParmDict[PARM_RFBB].v.valU8;
    pRXDCOGROUPRSPParms->depth = pParmDict[PARM_DEPTH].v.valU8;
    pRXDCOGROUPRSPParms->padding = pParmDict[PARM_PADDING].v.valU8;
    pRXDCOGROUPRSPParms->executionTime = pParmDict[PARM_EXECUTIONTIME].v.valU32;
    memset(pRXDCOGROUPRSPParms->gainLut, 0, sizeof(pRXDCOGROUPRSPParms->gainLut));
    pRXDCOGROUPRSPParms->dcoI = pParmDict[PARM_DCOI].v.valU16;
    pRXDCOGROUPRSPParms->dcoQ = pParmDict[PARM_DCOQ].v.valU16;
    memset(pRXDCOGROUPRSPParms->rfDocLut, 0, sizeof(pRXDCOGROUPRSPParms->rfDocLut));
    memset(pRXDCOGROUPRSPParms->bbDocLut, 0, sizeof(pRXDCOGROUPRSPParms->bbDocLut));
    memset(pRXDCOGROUPRSPParms->hwProcessedTable, 0, sizeof(pRXDCOGROUPRSPParms->hwProcessedTable));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_CMDIDRXDCOGROUP, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->cmdIdRxDcoGroup)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->phyId)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BBDCOCRANGE, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->bbDcocRange)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RFDCOCRANGE, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->rfDcocRange)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINMASK, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->chainMask)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LPBKMODE, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->lpbkMode)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RFFIRST, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->rfFirst)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_INITLUT, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->initLUT)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RFOVRD, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->rfOvrd)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BBOVRD, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->bbOvrd)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMGAIN, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->numGain)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BAND, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->band)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAIN, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->chain)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RFBB, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->rfBB)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DEPTH, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->depth)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PADDING, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->padding)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_EXECUTIONTIME, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->executionTime)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GAINLUT, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->gainLut)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DCOI, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->dcoI)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DCOQ, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->dcoQ)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RFDOCLUT, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->rfDocLut)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BBDOCLUT, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->bbDocLut)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_HWPROCESSEDTABLE, (A_UINT32)(((A_UINT32)&(pRXDCOGROUPRSPParms->hwProcessedTable)) - (A_UINT32)pRXDCOGROUPRSPParms), pParmsOffset);
    return((void*) pRXDCOGROUPRSPParms);
}

static RXDCOGROUPRSP_OP_FUNC RXDCOGROUPRSPOpFunc = NULL;

TLV2_API void registerRXDCOGROUPRSPHandler(RXDCOGROUPRSP_OP_FUNC fp)
{
    RXDCOGROUPRSPOpFunc = fp;
}

A_BOOL RXDCOGROUPRSPOp(void *pParms)
{
    CMD_RXDCOGROUPRSP_PARMS *pRXDCOGROUPRSPParms = (CMD_RXDCOGROUPRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("RXDCOGROUPRSPOp: cmdIdRxDcoGroup %u\n", pRXDCOGROUPRSPParms->cmdIdRxDcoGroup);
    A_PRINTF("RXDCOGROUPRSPOp: phyId %u\n", pRXDCOGROUPRSPParms->phyId);
    A_PRINTF("RXDCOGROUPRSPOp: bbDcocRange %u\n", pRXDCOGROUPRSPParms->bbDcocRange);
    A_PRINTF("RXDCOGROUPRSPOp: rfDcocRange %u\n", pRXDCOGROUPRSPParms->rfDcocRange);
    A_PRINTF("RXDCOGROUPRSPOp: chainMask %u\n", pRXDCOGROUPRSPParms->chainMask);
    A_PRINTF("RXDCOGROUPRSPOp: lpbkMode %u\n", pRXDCOGROUPRSPParms->lpbkMode);
    A_PRINTF("RXDCOGROUPRSPOp: rfFirst %u\n", pRXDCOGROUPRSPParms->rfFirst);
    A_PRINTF("RXDCOGROUPRSPOp: initLUT %u\n", pRXDCOGROUPRSPParms->initLUT);
    A_PRINTF("RXDCOGROUPRSPOp: rfOvrd %u\n", pRXDCOGROUPRSPParms->rfOvrd);
    A_PRINTF("RXDCOGROUPRSPOp: bbOvrd %u\n", pRXDCOGROUPRSPParms->bbOvrd);
    A_PRINTF("RXDCOGROUPRSPOp: numGain %u\n", pRXDCOGROUPRSPParms->numGain);
    A_PRINTF("RXDCOGROUPRSPOp: band %u\n", pRXDCOGROUPRSPParms->band);
    A_PRINTF("RXDCOGROUPRSPOp: chain %u\n", pRXDCOGROUPRSPParms->chain);
    A_PRINTF("RXDCOGROUPRSPOp: rfBB %u\n", pRXDCOGROUPRSPParms->rfBB);
    A_PRINTF("RXDCOGROUPRSPOp: depth %u\n", pRXDCOGROUPRSPParms->depth);
    A_PRINTF("RXDCOGROUPRSPOp: padding %u\n", pRXDCOGROUPRSPParms->padding);
    A_PRINTF("RXDCOGROUPRSPOp: executionTime %u\n", pRXDCOGROUPRSPParms->executionTime);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 20 entries
    {
        A_PRINTF("RXDCOGROUPRSPOp: gainLut %u\n", pRXDCOGROUPRSPParms->gainLut[i]);
    }
    A_PRINTF("RXDCOGROUPRSPOp: dcoI %u\n", pRXDCOGROUPRSPParms->dcoI);
    A_PRINTF("RXDCOGROUPRSPOp: dcoQ %u\n", pRXDCOGROUPRSPParms->dcoQ);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 80 entries
    {
        A_PRINTF("RXDCOGROUPRSPOp: rfDocLut %u\n", pRXDCOGROUPRSPParms->rfDocLut[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 80 entries
    {
        A_PRINTF("RXDCOGROUPRSPOp: bbDocLut %u\n", pRXDCOGROUPRSPParms->bbDocLut[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 100 entries
    {
        A_PRINTF("RXDCOGROUPRSPOp: hwProcessedTable %u\n", pRXDCOGROUPRSPParms->hwProcessedTable[i]);
    }
#endif //_DEBUG

    if (NULL != RXDCOGROUPRSPOpFunc) {
        (*RXDCOGROUPRSPOpFunc)(pRXDCOGROUPRSPParms);
    }
    return(TRUE);
}

#endif
