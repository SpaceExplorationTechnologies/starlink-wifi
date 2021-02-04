// This is an auto-generated file from input\cmdTxStatusHandler.s
#include "tlv2Inc.h"
#include "cmdTxStatusHandler.h"

void* initTXSTATUSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_TXSTATUS_PARMS  *pTXSTATUSParms = (CMD_TXSTATUS_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pTXSTATUSParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pTXSTATUSParms->stopTx = pParmDict[PARM_STOPTX].v.valU8;
    pTXSTATUSParms->needReport = pParmDict[PARM_NEEDREPORT].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pTXSTATUSParms->phyId)) - (A_UINT32)pTXSTATUSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STOPTX, (A_UINT32)(((A_UINT32)&(pTXSTATUSParms->stopTx)) - (A_UINT32)pTXSTATUSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NEEDREPORT, (A_UINT32)(((A_UINT32)&(pTXSTATUSParms->needReport)) - (A_UINT32)pTXSTATUSParms), pParmsOffset);
    return((void*) pTXSTATUSParms);
}

static TXSTATUS_OP_FUNC TXSTATUSOpFunc = NULL;

TLV2_API void registerTXSTATUSHandler(TXSTATUS_OP_FUNC fp)
{
    TXSTATUSOpFunc = fp;
}

A_BOOL TXSTATUSOp(void *pParms)
{
    CMD_TXSTATUS_PARMS *pTXSTATUSParms = (CMD_TXSTATUS_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TXSTATUSOp: phyId %u\n", pTXSTATUSParms->phyId);
    A_PRINTF("TXSTATUSOp: stopTx %u\n", pTXSTATUSParms->stopTx);
    A_PRINTF("TXSTATUSOp: needReport %u\n", pTXSTATUSParms->needReport);
#endif //_DEBUG

    if (NULL != TXSTATUSOpFunc) {
        (*TXSTATUSOpFunc)(pTXSTATUSParms);
    }
    return(TRUE);
}

void* initTXSTATUSRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_TXSTATUSRSP_PARMS  *pTXSTATUSRSPParms = (CMD_TXSTATUSRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pTXSTATUSRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pTXSTATUSRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pTXSTATUSRSPParms->numOfReports = pParmDict[PARM_NUMOFREPORTS].v.valU8;
    pTXSTATUSRSPParms->thermCal = pParmDict[PARM_THERMCAL].v.valU8;
    pTXSTATUSRSPParms->pdadc = pParmDict[PARM_PDADC].v.valU8;
    pTXSTATUSRSPParms->paCfg = pParmDict[PARM_PACFG].v.valU8;
    pTXSTATUSRSPParms->gainIdx = pParmDict[PARM_GAINIDX].v.valU8;
    pTXSTATUSRSPParms->dacGain = pParmDict[PARM_DACGAIN].v.valS8;
    pTXSTATUSRSPParms->totalPackets = pParmDict[PARM_TOTALPACKETS].v.valU32;
    pTXSTATUSRSPParms->goodPackets = pParmDict[PARM_GOODPACKETS].v.valU32;
    pTXSTATUSRSPParms->underruns = pParmDict[PARM_UNDERRUNS].v.valU32;
    pTXSTATUSRSPParms->otherError = pParmDict[PARM_OTHERERROR].v.valU32;
    pTXSTATUSRSPParms->excessRetries = pParmDict[PARM_EXCESSRETRIES].v.valU32;
    pTXSTATUSRSPParms->rateBit = pParmDict[PARM_RATEBIT].v.valU32;
    pTXSTATUSRSPParms->shortRetry = pParmDict[PARM_SHORTRETRY].v.valU32;
    pTXSTATUSRSPParms->longRetry = pParmDict[PARM_LONGRETRY].v.valU32;
    pTXSTATUSRSPParms->startTime = pParmDict[PARM_STARTTIME].v.valU32;
    pTXSTATUSRSPParms->endTime = pParmDict[PARM_ENDTIME].v.valU32;
    pTXSTATUSRSPParms->byteCount = pParmDict[PARM_BYTECOUNT].v.valU32;
    pTXSTATUSRSPParms->dontCount = pParmDict[PARM_DONTCOUNT].v.valU32;
    pTXSTATUSRSPParms->rssi = pParmDict[PARM_RSSI].v.valS32;
    for (i = 0; i < 4 ; i++)
    {
        pTXSTATUSRSPParms->rssic[i] = pParmDict[PARM_RSSIC].v.ptS32[i];
    }
    for (i = 0; i < 4 ; i++)
    {
        pTXSTATUSRSPParms->rssie[i] = pParmDict[PARM_RSSIE].v.ptS32[i];
    }

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->phyId)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->status)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMOFREPORTS, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->numOfReports)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_THERMCAL, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->thermCal)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PDADC, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->pdadc)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACFG, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->paCfg)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GAINIDX, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->gainIdx)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAIN, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->dacGain)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TOTALPACKETS, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->totalPackets)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GOODPACKETS, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->goodPackets)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_UNDERRUNS, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->underruns)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OTHERERROR, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->otherError)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_EXCESSRETRIES, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->excessRetries)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEBIT, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->rateBit)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SHORTRETRY, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->shortRetry)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LONGRETRY, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->longRetry)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STARTTIME, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->startTime)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ENDTIME, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->endTime)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BYTECOUNT, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->byteCount)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DONTCOUNT, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->dontCount)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RSSI, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->rssi)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RSSIC, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->rssic)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RSSIE, (A_UINT32)(((A_UINT32)&(pTXSTATUSRSPParms->rssie)) - (A_UINT32)pTXSTATUSRSPParms), pParmsOffset);
    return((void*) pTXSTATUSRSPParms);
}

static TXSTATUSRSP_OP_FUNC TXSTATUSRSPOpFunc = NULL;

TLV2_API void registerTXSTATUSRSPHandler(TXSTATUSRSP_OP_FUNC fp)
{
    TXSTATUSRSPOpFunc = fp;
}

A_BOOL TXSTATUSRSPOp(void *pParms)
{
    CMD_TXSTATUSRSP_PARMS *pTXSTATUSRSPParms = (CMD_TXSTATUSRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TXSTATUSRSPOp: phyId %u\n", pTXSTATUSRSPParms->phyId);
    A_PRINTF("TXSTATUSRSPOp: status %u\n", pTXSTATUSRSPParms->status);
    A_PRINTF("TXSTATUSRSPOp: numOfReports %u\n", pTXSTATUSRSPParms->numOfReports);
    A_PRINTF("TXSTATUSRSPOp: thermCal %u\n", pTXSTATUSRSPParms->thermCal);
    A_PRINTF("TXSTATUSRSPOp: pdadc %u\n", pTXSTATUSRSPParms->pdadc);
    A_PRINTF("TXSTATUSRSPOp: paCfg %u\n", pTXSTATUSRSPParms->paCfg);
    A_PRINTF("TXSTATUSRSPOp: gainIdx %u\n", pTXSTATUSRSPParms->gainIdx);
    A_PRINTF("TXSTATUSRSPOp: dacGain %d\n", pTXSTATUSRSPParms->dacGain);
    A_PRINTF("TXSTATUSRSPOp: totalPackets %u\n", pTXSTATUSRSPParms->totalPackets);
    A_PRINTF("TXSTATUSRSPOp: goodPackets %u\n", pTXSTATUSRSPParms->goodPackets);
    A_PRINTF("TXSTATUSRSPOp: underruns %u\n", pTXSTATUSRSPParms->underruns);
    A_PRINTF("TXSTATUSRSPOp: otherError %u\n", pTXSTATUSRSPParms->otherError);
    A_PRINTF("TXSTATUSRSPOp: excessRetries %u\n", pTXSTATUSRSPParms->excessRetries);
    A_PRINTF("TXSTATUSRSPOp: rateBit %u\n", pTXSTATUSRSPParms->rateBit);
    A_PRINTF("TXSTATUSRSPOp: shortRetry %u\n", pTXSTATUSRSPParms->shortRetry);
    A_PRINTF("TXSTATUSRSPOp: longRetry %u\n", pTXSTATUSRSPParms->longRetry);
    A_PRINTF("TXSTATUSRSPOp: startTime %u\n", pTXSTATUSRSPParms->startTime);
    A_PRINTF("TXSTATUSRSPOp: endTime %u\n", pTXSTATUSRSPParms->endTime);
    A_PRINTF("TXSTATUSRSPOp: byteCount %u\n", pTXSTATUSRSPParms->byteCount);
    A_PRINTF("TXSTATUSRSPOp: dontCount %u\n", pTXSTATUSRSPParms->dontCount);
    A_PRINTF("TXSTATUSRSPOp: rssi %d\n", pTXSTATUSRSPParms->rssi);
    for (i = 0; i < 4 ; i++)
    {
        A_PRINTF("TXSTATUSRSPOp: rssic %d\n", pTXSTATUSRSPParms->rssic[i]);
    }
    for (i = 0; i < 4 ; i++)
    {
        A_PRINTF("TXSTATUSRSPOp: rssie %d\n", pTXSTATUSRSPParms->rssie[i]);
    }
#endif //_DEBUG

    if (NULL != TXSTATUSRSPOpFunc) {
        (*TXSTATUSRSPOpFunc)(pTXSTATUSRSPParms);
    }
    return(TRUE);
}
