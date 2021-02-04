// This is an auto-generated file from input/cmdLMRxHandler.s
#include "tlv2Inc.h"
#include "cmdLMRxHandler.h"

void* initLMRXOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_LMRX_PARMS  *pLMRXParms = (CMD_LMRX_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pLMRXParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pLMRXParms->rxMode = pParmDict[PARM_RXMODE].v.valU8;
    memset(pLMRXParms->lm_resvd1, 0, sizeof(pLMRXParms->lm_resvd1));
    memset(pLMRXParms->lm_freq, 0, sizeof(pLMRXParms->lm_freq));
    for (i = 0; i < 2 ; i++)
    {
        pLMRXParms->lm_freq[i] = pParmDict[PARM_LM_FREQ].v.ptU16[i];
    }
    memset(pLMRXParms->lm_freq2, 0, sizeof(pLMRXParms->lm_freq2));
    for (i = 0; i < 2 ; i++)
    {
        pLMRXParms->lm_freq2[i] = pParmDict[PARM_LM_FREQ2].v.ptU16[i];
    }
    memset(pLMRXParms->lm_chainMask, 0, sizeof(pLMRXParms->lm_chainMask));
    for (i = 0; i < 1 ; i++)
    {
        pLMRXParms->lm_chainMask[i] = pParmDict[PARM_LM_CHAINMASK].v.ptU8[i];
    }
    memset(pLMRXParms->wlanModeMask, 0, sizeof(pLMRXParms->wlanModeMask));
    for (i = 0; i < 1 ; i++)
    {
        pLMRXParms->wlanModeMask[i] = pParmDict[PARM_WLANMODEMASK].v.ptU32[i];
    }
    memset(pLMRXParms->wlanModeMaskExt, 0, sizeof(pLMRXParms->wlanModeMaskExt));
    memset(pLMRXParms->lm_bandwidth, 0, sizeof(pLMRXParms->lm_bandwidth));
    pLMRXParms->antenna = pParmDict[PARM_ANTENNA].v.valU8;
    pLMRXParms->enANI = pParmDict[PARM_ENANI].v.valU8;
    pLMRXParms->ack = pParmDict[PARM_ACK].v.valU8;
    pLMRXParms->broadcast = pParmDict[PARM_BROADCAST].v.valU8;
    pLMRXParms->lpl = pParmDict[PARM_LPL].v.valU8;
    pLMRXParms->antswitch1 = pParmDict[PARM_ANTSWITCH1].v.valU8;
    pLMRXParms->antswitch2 = pParmDict[PARM_ANTSWITCH2].v.valU8;
    pLMRXParms->lm_resvd0 = pParmDict[PARM_LM_RESVD0].v.valU8;
    pLMRXParms->spectralScan = pParmDict[PARM_SPECTRALSCAN].v.valU16;
    pLMRXParms->noiseFloor = pParmDict[PARM_NOISEFLOOR].v.valS16;
    memset(pLMRXParms->regDmn, 0, sizeof(pLMRXParms->regDmn));
    pLMRXParms->expectedPkts = pParmDict[PARM_EXPECTEDPKTS].v.valU32;
    pLMRXParms->otpWriteFlag = pParmDict[PARM_OTPWRITEFLAG].v.valU32;
    pLMRXParms->flags = pParmDict[PARM_FLAGS].v.valU32;
    for (i = 0; i < 3 ; i++)
    {
        pLMRXParms->rateMask[i] = pParmDict[PARM_RATEMASK].v.ptU32[i];
    }
    memset(pLMRXParms->rateMask11AC, 0, sizeof(pLMRXParms->rateMask11AC));
    pLMRXParms->rateMaskAC160 = pParmDict[PARM_RATEMASKAC160].v.valU32;
    for (i = 0; i < 6 ; i++)
    {
        pLMRXParms->bssid[i] = pParmDict[PARM_BSSID].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pLMRXParms->staAddr[i] = pParmDict[PARM_STAADDR].v.ptU8[i];
    }
    memset(pLMRXParms->btAddr, 0, sizeof(pLMRXParms->btAddr));
    memset(pLMRXParms->pad2, 0, sizeof(pLMRXParms->pad2));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pLMRXParms->phyId)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RXMODE, (A_UINT32)(((A_UINT32)&(pLMRXParms->rxMode)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_RESVD1, (A_UINT32)(((A_UINT32)&(pLMRXParms->lm_resvd1)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_FREQ, (A_UINT32)(((A_UINT32)&(pLMRXParms->lm_freq)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_FREQ2, (A_UINT32)(((A_UINT32)&(pLMRXParms->lm_freq2)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_CHAINMASK, (A_UINT32)(((A_UINT32)&(pLMRXParms->lm_chainMask)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_WLANMODEMASK, (A_UINT32)(((A_UINT32)&(pLMRXParms->wlanModeMask)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_WLANMODEMASKEXT, (A_UINT32)(((A_UINT32)&(pLMRXParms->wlanModeMaskExt)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_BANDWIDTH, (A_UINT32)(((A_UINT32)&(pLMRXParms->lm_bandwidth)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTENNA, (A_UINT32)(((A_UINT32)&(pLMRXParms->antenna)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ENANI, (A_UINT32)(((A_UINT32)&(pLMRXParms->enANI)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ACK, (A_UINT32)(((A_UINT32)&(pLMRXParms->ack)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BROADCAST, (A_UINT32)(((A_UINT32)&(pLMRXParms->broadcast)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LPL, (A_UINT32)(((A_UINT32)&(pLMRXParms->lpl)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTSWITCH1, (A_UINT32)(((A_UINT32)&(pLMRXParms->antswitch1)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTSWITCH2, (A_UINT32)(((A_UINT32)&(pLMRXParms->antswitch2)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_RESVD0, (A_UINT32)(((A_UINT32)&(pLMRXParms->lm_resvd0)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SPECTRALSCAN, (A_UINT32)(((A_UINT32)&(pLMRXParms->spectralScan)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NOISEFLOOR, (A_UINT32)(((A_UINT32)&(pLMRXParms->noiseFloor)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_REGDMN, (A_UINT32)(((A_UINT32)&(pLMRXParms->regDmn)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_EXPECTEDPKTS, (A_UINT32)(((A_UINT32)&(pLMRXParms->expectedPkts)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OTPWRITEFLAG, (A_UINT32)(((A_UINT32)&(pLMRXParms->otpWriteFlag)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FLAGS, (A_UINT32)(((A_UINT32)&(pLMRXParms->flags)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASK, (A_UINT32)(((A_UINT32)&(pLMRXParms->rateMask)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASK11AC, (A_UINT32)(((A_UINT32)&(pLMRXParms->rateMask11AC)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASKAC160, (A_UINT32)(((A_UINT32)&(pLMRXParms->rateMaskAC160)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BSSID, (A_UINT32)(((A_UINT32)&(pLMRXParms->bssid)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STAADDR, (A_UINT32)(((A_UINT32)&(pLMRXParms->staAddr)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BTADDR, (A_UINT32)(((A_UINT32)&(pLMRXParms->btAddr)) - (A_UINT32)pLMRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD2, (A_UINT32)(((A_UINT32)&(pLMRXParms->pad2)) - (A_UINT32)pLMRXParms), pParmsOffset);
    return((void*) pLMRXParms);
}

static LMRX_OP_FUNC LMRXOpFunc = NULL;

TLV2_API void registerLMRXHandler(LMRX_OP_FUNC fp)
{
    LMRXOpFunc = fp;
}

A_BOOL LMRXOp(void *pParms)
{
    CMD_LMRX_PARMS *pLMRXParms = (CMD_LMRX_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMRXOp: phyId %u\n", pLMRXParms->phyId);
    A_PRINTF("LMRXOp: rxMode %u\n", pLMRXParms->rxMode);
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("LMRXOp: lm_resvd1 %u\n", pLMRXParms->lm_resvd1[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMRXOp: lm_freq %u\n", pLMRXParms->lm_freq[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMRXOp: lm_freq2 %u\n", pLMRXParms->lm_freq2[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMRXOp: lm_chainMask 0x%x\n", pLMRXParms->lm_chainMask[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMRXOp: wlanModeMask 0x%x\n", pLMRXParms->wlanModeMask[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMRXOp: wlanModeMaskExt 0x%x\n", pLMRXParms->wlanModeMaskExt[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMRXOp: lm_bandwidth %u\n", pLMRXParms->lm_bandwidth[i]);
    }
    A_PRINTF("LMRXOp: antenna %u\n", pLMRXParms->antenna);
    A_PRINTF("LMRXOp: enANI %u\n", pLMRXParms->enANI);
    A_PRINTF("LMRXOp: ack %u\n", pLMRXParms->ack);
    A_PRINTF("LMRXOp: broadcast %u\n", pLMRXParms->broadcast);
    A_PRINTF("LMRXOp: lpl %u\n", pLMRXParms->lpl);
    A_PRINTF("LMRXOp: antswitch1 %u\n", pLMRXParms->antswitch1);
    A_PRINTF("LMRXOp: antswitch2 %u\n", pLMRXParms->antswitch2);
    A_PRINTF("LMRXOp: lm_resvd0 %u\n", pLMRXParms->lm_resvd0);
    A_PRINTF("LMRXOp: spectralScan %u\n", pLMRXParms->spectralScan);
    A_PRINTF("LMRXOp: noiseFloor %d\n", pLMRXParms->noiseFloor);
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("LMRXOp: regDmn 0x%x\n", pLMRXParms->regDmn[i]);
    }
    A_PRINTF("LMRXOp: expectedPkts %u\n", pLMRXParms->expectedPkts);
    A_PRINTF("LMRXOp: otpWriteFlag 0x%x\n", pLMRXParms->otpWriteFlag);
    A_PRINTF("LMRXOp: flags 0x%x\n", pLMRXParms->flags);
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("LMRXOp: rateMask 0x%x\n", pLMRXParms->rateMask[i]);
    }
    for (i = 0; i < 5 ; i++)
    {
        A_PRINTF("LMRXOp: rateMask11AC 0x%x\n", pLMRXParms->rateMask11AC[i]);
    }
    A_PRINTF("LMRXOp: rateMaskAC160 0x%x\n", pLMRXParms->rateMaskAC160);
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("LMRXOp: bssid 0x%x\n", pLMRXParms->bssid[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("LMRXOp: staAddr 0x%x\n", pLMRXParms->staAddr[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("LMRXOp: btAddr 0x%x\n", pLMRXParms->btAddr[i]);
    }
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("LMRXOp: pad2 %u\n", pLMRXParms->pad2[i]);
    }
#endif //_DEBUG

    if (NULL != LMRXOpFunc) {
        (*LMRXOpFunc)(pLMRXParms);
    }
    return(TRUE);
}
