// This is an auto-generated file from input\cmdLMRxInitHandler.s
#include "tlv2Inc.h"
#include "cmdLMRxInitHandler.h"

void* initLMRXINITOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_LMRXINIT_PARMS  *pLMRXINITParms = (CMD_LMRXINIT_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pLMRXINITParms->rxMode = pParmDict[PARM_RXMODE].v.valU8;
    pLMRXINITParms->bandwidth = pParmDict[PARM_BANDWIDTH].v.valU8;
    pLMRXINITParms->antenna = pParmDict[PARM_ANTENNA].v.valU8;
    pLMRXINITParms->enANI = pParmDict[PARM_ENANI].v.valU8;
    pLMRXINITParms->ack = pParmDict[PARM_ACK].v.valU8;
    pLMRXINITParms->broadcast = pParmDict[PARM_BROADCAST].v.valU8;
    pLMRXINITParms->lpl = pParmDict[PARM_LPL].v.valU8;
    pLMRXINITParms->antswitch1 = pParmDict[PARM_ANTSWITCH1].v.valU8;
    pLMRXINITParms->antswitch2 = pParmDict[PARM_ANTSWITCH2].v.valU8;
    memset(pLMRXINITParms->pad3, 0, sizeof(pLMRXINITParms->pad3));
    pLMRXINITParms->spectralScan = pParmDict[PARM_SPECTRALSCAN].v.valU16;
    pLMRXINITParms->noiseFloor = pParmDict[PARM_NOISEFLOOR].v.valS16;
    for (i = 0; i < 2 ; i++)
    {
        pLMRXINITParms->regDmn[i] = pParmDict[PARM_REGDMN].v.ptU16[i];
    }
    pLMRXINITParms->expectedPkts = pParmDict[PARM_EXPECTEDPKTS].v.valU32;
    pLMRXINITParms->otpWriteFlag = pParmDict[PARM_OTPWRITEFLAG].v.valU32;
    pLMRXINITParms->flags = pParmDict[PARM_FLAGS].v.valU32;
    for (i = 0; i < 6 ; i++)
    {
        pLMRXINITParms->bssid[i] = pParmDict[PARM_BSSID].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pLMRXINITParms->staAddr[i] = pParmDict[PARM_STAADDR].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pLMRXINITParms->btAddr[i] = pParmDict[PARM_BTADDR].v.ptU8[i];
    }

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_RXMODE, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->rxMode)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BANDWIDTH, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->bandwidth)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTENNA, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->antenna)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ENANI, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->enANI)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ACK, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->ack)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BROADCAST, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->broadcast)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LPL, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->lpl)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTSWITCH1, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->antswitch1)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTSWITCH2, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->antswitch2)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD3, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->pad3)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SPECTRALSCAN, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->spectralScan)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NOISEFLOOR, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->noiseFloor)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_REGDMN, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->regDmn)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_EXPECTEDPKTS, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->expectedPkts)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OTPWRITEFLAG, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->otpWriteFlag)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FLAGS, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->flags)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BSSID, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->bssid)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STAADDR, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->staAddr)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BTADDR, (A_UINT32)(((A_UINT32)&(pLMRXINITParms->btAddr)) - (A_UINT32)pLMRXINITParms), pParmsOffset);
    return((void*) pLMRXINITParms);
}

static LMRXINIT_OP_FUNC LMRXINITOpFunc = NULL;

TLV2_API void registerLMRXINITHandler(LMRXINIT_OP_FUNC fp)
{
    LMRXINITOpFunc = fp;
}

A_BOOL LMRXINITOp(void *pParms)
{
    CMD_LMRXINIT_PARMS *pLMRXINITParms = (CMD_LMRXINIT_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMRXINITOp: rxMode %u\n", pLMRXINITParms->rxMode);
    A_PRINTF("LMRXINITOp: bandwidth %u\n", pLMRXINITParms->bandwidth);
    A_PRINTF("LMRXINITOp: antenna %u\n", pLMRXINITParms->antenna);
    A_PRINTF("LMRXINITOp: enANI %u\n", pLMRXINITParms->enANI);
    A_PRINTF("LMRXINITOp: ack %u\n", pLMRXINITParms->ack);
    A_PRINTF("LMRXINITOp: broadcast %u\n", pLMRXINITParms->broadcast);
    A_PRINTF("LMRXINITOp: lpl %u\n", pLMRXINITParms->lpl);
    A_PRINTF("LMRXINITOp: antswitch1 %u\n", pLMRXINITParms->antswitch1);
    A_PRINTF("LMRXINITOp: antswitch2 %u\n", pLMRXINITParms->antswitch2);
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("LMRXINITOp: pad3 %u\n", pLMRXINITParms->pad3[i]);
    }
    A_PRINTF("LMRXINITOp: spectralScan %u\n", pLMRXINITParms->spectralScan);
    A_PRINTF("LMRXINITOp: noiseFloor %d\n", pLMRXINITParms->noiseFloor);
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("LMRXINITOp: regDmn 0x%x\n", pLMRXINITParms->regDmn[i]);
    }
    A_PRINTF("LMRXINITOp: expectedPkts %u\n", pLMRXINITParms->expectedPkts);
    A_PRINTF("LMRXINITOp: otpWriteFlag 0x%x\n", pLMRXINITParms->otpWriteFlag);
    A_PRINTF("LMRXINITOp: flags 0x%x\n", pLMRXINITParms->flags);
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("LMRXINITOp: bssid 0x%x\n", pLMRXINITParms->bssid[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("LMRXINITOp: staAddr 0x%x\n", pLMRXINITParms->staAddr[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("LMRXINITOp: btAddr 0x%x\n", pLMRXINITParms->btAddr[i]);
    }
#endif //_DEBUG

    if (NULL != LMRXINITOpFunc) {
        (*LMRXINITOpFunc)(pLMRXINITParms);
    }
    return(TRUE);
}

void* initLMRXINITRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_LMRXINITRSP_PARMS  *pLMRXINITRSPParms = (CMD_LMRXINITRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pLMRXINITRSPParms->cmdId = pParmDict[PARM_CMDID].v.valU16;
    pLMRXINITRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pLMRXINITRSPParms->pad1 = pParmDict[PARM_PAD1].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_CMDID, (A_UINT32)(((A_UINT32)&(pLMRXINITRSPParms->cmdId)) - (A_UINT32)pLMRXINITRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pLMRXINITRSPParms->status)) - (A_UINT32)pLMRXINITRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD1, (A_UINT32)(((A_UINT32)&(pLMRXINITRSPParms->pad1)) - (A_UINT32)pLMRXINITRSPParms), pParmsOffset);
    return((void*) pLMRXINITRSPParms);
}

static LMRXINITRSP_OP_FUNC LMRXINITRSPOpFunc = NULL;

TLV2_API void registerLMRXINITRSPHandler(LMRXINITRSP_OP_FUNC fp)
{
    LMRXINITRSPOpFunc = fp;
}

A_BOOL LMRXINITRSPOp(void *pParms)
{
    CMD_LMRXINITRSP_PARMS *pLMRXINITRSPParms = (CMD_LMRXINITRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMRXINITRSPOp: cmdId %u\n", pLMRXINITRSPParms->cmdId);
    A_PRINTF("LMRXINITRSPOp: status %u\n", pLMRXINITRSPParms->status);
    A_PRINTF("LMRXINITRSPOp: pad1 %u\n", pLMRXINITRSPParms->pad1);
#endif //_DEBUG

    if (NULL != LMRXINITRSPOpFunc) {
        (*LMRXINITRSPOpFunc)(pLMRXINITRSPParms);
    }
    return(TRUE);
}
