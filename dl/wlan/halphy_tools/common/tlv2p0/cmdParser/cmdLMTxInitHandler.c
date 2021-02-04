// This is an auto-generated file from input/cmdLMTxInitHandler.s
#include "tlv2Inc.h"
#include "cmdLMTxInitHandler.h"

void* initLMTXINITOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_LMTXINIT_PARMS  *pLMTXINITParms = (CMD_LMTXINIT_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pLMTXINITParms->txMode = pParmDict[PARM_TXMODE].v.valU8;
    pLMTXINITParms->bandwidth = pParmDict[PARM_BANDWIDTH].v.valU8;
    pLMTXINITParms->gI = pParmDict[PARM_GI].v.valU8;
    pLMTXINITParms->antenna = pParmDict[PARM_ANTENNA].v.valU8;
    pLMTXINITParms->enANI = pParmDict[PARM_ENANI].v.valU8;
    pLMTXINITParms->scramblerOff = pParmDict[PARM_SCRAMBLEROFF].v.valU8;
    pLMTXINITParms->aifsn = pParmDict[PARM_AIFSN].v.valU8;
    pLMTXINITParms->broadcast = pParmDict[PARM_BROADCAST].v.valU8;
    pLMTXINITParms->agg = pParmDict[PARM_AGG].v.valU8;
    pLMTXINITParms->shortGuard = pParmDict[PARM_SHORTGUARD].v.valU8;
    pLMTXINITParms->dutyCycle = pParmDict[PARM_DUTYCYCLE].v.valU8;
    pLMTXINITParms->nPattern = pParmDict[PARM_NPATTERN].v.valU8;
    pLMTXINITParms->tpcm = pParmDict[PARM_TPCM].v.valU8;
    pLMTXINITParms->gainIdx = pParmDict[PARM_GAINIDX].v.valU8;
    pLMTXINITParms->dacGain = pParmDict[PARM_DACGAIN].v.valS8;
    pLMTXINITParms->dacGainEnd = pParmDict[PARM_DACGAINEND].v.valS8;
    pLMTXINITParms->dacGainStep = pParmDict[PARM_DACGAINSTEP].v.valS8;
    pLMTXINITParms->paConfig = pParmDict[PARM_PACONFIG].v.valU8;
    pLMTXINITParms->paConfigEnd = pParmDict[PARM_PACONFIGEND].v.valU8;
    pLMTXINITParms->paConfigStep = pParmDict[PARM_PACONFIGSTEP].v.valU8;
    memset(pLMTXINITParms->dataPattern, 0, sizeof(pLMTXINITParms->dataPattern));
    for (i = 0; i < 6 ; i++)
    {
        pLMTXINITParms->bssid[i] = pParmDict[PARM_BSSID].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pLMTXINITParms->txStation[i] = pParmDict[PARM_TXSTATION].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pLMTXINITParms->rxStation[i] = pParmDict[PARM_RXSTATION].v.ptU8[i];
    }
    memset(pLMTXINITParms->pad2, 0, sizeof(pLMTXINITParms->pad2));
    pLMTXINITParms->txNumPackets = pParmDict[PARM_TXNUMPACKETS].v.valU16;
    pLMTXINITParms->txPattern = pParmDict[PARM_TXPATTERN].v.valU16;
    pLMTXINITParms->flags = pParmDict[PARM_FLAGS].v.valU32;
    pLMTXINITParms->ir = pParmDict[PARM_IR].v.valU32;
    pLMTXINITParms->pktSz = pParmDict[PARM_PKTSZ].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_TXMODE, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->txMode)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BANDWIDTH, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->bandwidth)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GI, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->gI)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTENNA, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->antenna)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ENANI, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->enANI)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SCRAMBLEROFF, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->scramblerOff)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_AIFSN, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->aifsn)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BROADCAST, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->broadcast)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_AGG, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->agg)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SHORTGUARD, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->shortGuard)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DUTYCYCLE, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->dutyCycle)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NPATTERN, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->nPattern)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TPCM, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->tpcm)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GAINIDX, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->gainIdx)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAIN, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->dacGain)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAINEND, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->dacGainEnd)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAINSTEP, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->dacGainStep)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACONFIG, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->paConfig)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACONFIGEND, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->paConfigEnd)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACONFIGSTEP, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->paConfigStep)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DATAPATTERN, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->dataPattern)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BSSID, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->bssid)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXSTATION, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->txStation)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RXSTATION, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->rxStation)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD2, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->pad2)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXNUMPACKETS, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->txNumPackets)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXPATTERN, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->txPattern)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FLAGS, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->flags)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_IR, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->ir)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PKTSZ, (A_UINT32)(((A_UINT32)&(pLMTXINITParms->pktSz)) - (A_UINT32)pLMTXINITParms), pParmsOffset);
    return((void*) pLMTXINITParms);
}

static LMTXINIT_OP_FUNC LMTXINITOpFunc = NULL;

TLV2_API void registerLMTXINITHandler(LMTXINIT_OP_FUNC fp)
{
    LMTXINITOpFunc = fp;
}

A_BOOL LMTXINITOp(void *pParms)
{
    CMD_LMTXINIT_PARMS *pLMTXINITParms = (CMD_LMTXINIT_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMTXINITOp: txMode %u\n", pLMTXINITParms->txMode);
    A_PRINTF("LMTXINITOp: bandwidth %u\n", pLMTXINITParms->bandwidth);
    A_PRINTF("LMTXINITOp: gI %u\n", pLMTXINITParms->gI);
    A_PRINTF("LMTXINITOp: antenna %u\n", pLMTXINITParms->antenna);
    A_PRINTF("LMTXINITOp: enANI %u\n", pLMTXINITParms->enANI);
    A_PRINTF("LMTXINITOp: scramblerOff %u\n", pLMTXINITParms->scramblerOff);
    A_PRINTF("LMTXINITOp: aifsn %u\n", pLMTXINITParms->aifsn);
    A_PRINTF("LMTXINITOp: broadcast %u\n", pLMTXINITParms->broadcast);
    A_PRINTF("LMTXINITOp: agg %u\n", pLMTXINITParms->agg);
    A_PRINTF("LMTXINITOp: shortGuard %u\n", pLMTXINITParms->shortGuard);
    A_PRINTF("LMTXINITOp: dutyCycle %u\n", pLMTXINITParms->dutyCycle);
    A_PRINTF("LMTXINITOp: nPattern %u\n", pLMTXINITParms->nPattern);
    A_PRINTF("LMTXINITOp: tpcm %u\n", pLMTXINITParms->tpcm);
    A_PRINTF("LMTXINITOp: gainIdx %u\n", pLMTXINITParms->gainIdx);
    A_PRINTF("LMTXINITOp: dacGain %d\n", pLMTXINITParms->dacGain);
    A_PRINTF("LMTXINITOp: dacGainEnd %d\n", pLMTXINITParms->dacGainEnd);
    A_PRINTF("LMTXINITOp: dacGainStep %d\n", pLMTXINITParms->dacGainStep);
    A_PRINTF("LMTXINITOp: paConfig %u\n", pLMTXINITParms->paConfig);
    A_PRINTF("LMTXINITOp: paConfigEnd %u\n", pLMTXINITParms->paConfigEnd);
    A_PRINTF("LMTXINITOp: paConfigStep %u\n", pLMTXINITParms->paConfigStep);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 40 entries
    {
        A_PRINTF("LMTXINITOp: dataPattern %u\n", pLMTXINITParms->dataPattern[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("LMTXINITOp: bssid 0x%x\n", pLMTXINITParms->bssid[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("LMTXINITOp: txStation 0x%x\n", pLMTXINITParms->txStation[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("LMTXINITOp: rxStation 0x%x\n", pLMTXINITParms->rxStation[i]);
    }
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("LMTXINITOp: pad2 %u\n", pLMTXINITParms->pad2[i]);
    }
    A_PRINTF("LMTXINITOp: txNumPackets %u\n", pLMTXINITParms->txNumPackets);
    A_PRINTF("LMTXINITOp: txPattern %u\n", pLMTXINITParms->txPattern);
    A_PRINTF("LMTXINITOp: flags 0x%x\n", pLMTXINITParms->flags);
    A_PRINTF("LMTXINITOp: ir %u\n", pLMTXINITParms->ir);
    A_PRINTF("LMTXINITOp: pktSz %u\n", pLMTXINITParms->pktSz);
#endif //_DEBUG

    if (NULL != LMTXINITOpFunc) {
        (*LMTXINITOpFunc)(pLMTXINITParms);
    }
    return(TRUE);
}

void* initLMTXINITRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_LMTXINITRSP_PARMS  *pLMTXINITRSPParms = (CMD_LMTXINITRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pLMTXINITRSPParms->cmdId = pParmDict[PARM_CMDID].v.valU16;
    pLMTXINITRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pLMTXINITRSPParms->pad1 = pParmDict[PARM_PAD1].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_CMDID, (A_UINT32)(((A_UINT32)&(pLMTXINITRSPParms->cmdId)) - (A_UINT32)pLMTXINITRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pLMTXINITRSPParms->status)) - (A_UINT32)pLMTXINITRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD1, (A_UINT32)(((A_UINT32)&(pLMTXINITRSPParms->pad1)) - (A_UINT32)pLMTXINITRSPParms), pParmsOffset);
    return((void*) pLMTXINITRSPParms);
}

static LMTXINITRSP_OP_FUNC LMTXINITRSPOpFunc = NULL;

TLV2_API void registerLMTXINITRSPHandler(LMTXINITRSP_OP_FUNC fp)
{
    LMTXINITRSPOpFunc = fp;
}

A_BOOL LMTXINITRSPOp(void *pParms)
{
    CMD_LMTXINITRSP_PARMS *pLMTXINITRSPParms = (CMD_LMTXINITRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMTXINITRSPOp: cmdId %u\n", pLMTXINITRSPParms->cmdId);
    A_PRINTF("LMTXINITRSPOp: status %u\n", pLMTXINITRSPParms->status);
    A_PRINTF("LMTXINITRSPOp: pad1 %u\n", pLMTXINITRSPParms->pad1);
#endif //_DEBUG

    if (NULL != LMTXINITRSPOpFunc) {
        (*LMTXINITRSPOpFunc)(pLMTXINITRSPParms);
    }
    return(TRUE);
}
