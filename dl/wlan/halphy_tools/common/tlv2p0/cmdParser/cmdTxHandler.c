// This is an auto-generated file from input\cmdTxHandler.s
#include "tlv2Inc.h"
#include "cmdTxHandler.h"

void* initTXOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_TX_PARMS  *pTXParms = (CMD_TX_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pTXParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pTXParms->txMode = pParmDict[PARM_TXMODE].v.valU8;
    pTXParms->freq = pParmDict[PARM_FREQ].v.valU16;
    pTXParms->freq2 = pParmDict[PARM_FREQ2].v.valU16;
    pTXParms->chainMask = pParmDict[PARM_CHAINMASK].v.valU8;
    pTXParms->wlanMode = pParmDict[PARM_WLANMODE].v.valU8;
    pTXParms->bandwidth = pParmDict[PARM_BANDWIDTH].v.valU8;
    pTXParms->gI = pParmDict[PARM_GI].v.valU8;
    pTXParms->antenna = pParmDict[PARM_ANTENNA].v.valU8;
    pTXParms->enANI = pParmDict[PARM_ENANI].v.valU8;
    pTXParms->scramblerOff = pParmDict[PARM_SCRAMBLEROFF].v.valU8;
    pTXParms->aifsn = pParmDict[PARM_AIFSN].v.valU8;
    pTXParms->broadcast = pParmDict[PARM_BROADCAST].v.valU8;
    pTXParms->agg = pParmDict[PARM_AGG].v.valU8;
    pTXParms->shortGuard = pParmDict[PARM_SHORTGUARD].v.valU8;
    pTXParms->dutyCycle = pParmDict[PARM_DUTYCYCLE].v.valU8;
    pTXParms->flags = pParmDict[PARM_FLAGS].v.valU32;
    pTXParms->ir = pParmDict[PARM_IR].v.valU32;
    pTXParms->pktSz = pParmDict[PARM_PKTSZ].v.valU32;
    memset(pTXParms->dataPattern, 0, sizeof(pTXParms->dataPattern));
    for (i = 0; i < 1 ; i++)
    {
        pTXParms->dataPattern[i] = pParmDict[PARM_DATAPATTERN].v.ptU8[i];
    }
    pTXParms->txNumPackets = pParmDict[PARM_TXNUMPACKETS].v.valU16;
    pTXParms->txPattern = pParmDict[PARM_TXPATTERN].v.valU16;
    pTXParms->nPattern = pParmDict[PARM_NPATTERN].v.valU8;
    pTXParms->tpcm = pParmDict[PARM_TPCM].v.valU8;
    pTXParms->gainIdx = pParmDict[PARM_GAINIDX].v.valU8;
    pTXParms->dacGain = pParmDict[PARM_DACGAIN].v.valS8;
    pTXParms->dacGainEnd = pParmDict[PARM_DACGAINEND].v.valS8;
    pTXParms->dacGainStep = pParmDict[PARM_DACGAINSTEP].v.valS8;
    pTXParms->paConfig = pParmDict[PARM_PACONFIG].v.valU8;
    pTXParms->paConfigEnd = pParmDict[PARM_PACONFIGEND].v.valU8;
    pTXParms->paConfigStep = pParmDict[PARM_PACONFIGSTEP].v.valU8;
    for (i = 0; i < 3 ; i++)
    {
        pTXParms->pad3[i] = pParmDict[PARM_PAD3].v.ptU8[i];
    }
    for (i = 0; i < 3 ; i++)
    {
        pTXParms->rateMask[i] = pParmDict[PARM_RATEMASK].v.ptU32[i];
    }
    for (i = 0; i < 5 ; i++)
    {
        pTXParms->rateMask11AC[i] = pParmDict[PARM_RATEMASK11AC].v.ptU32[i];
    }
    pTXParms->rateMaskAC160 = pParmDict[PARM_RATEMASKAC160].v.valU32;
    for (i = 0; i < 24 ; i++)
    {
        pTXParms->pwrGainStart[i] = pParmDict[PARM_PWRGAINSTART].v.ptS32[i];
    }
    for (i = 0; i < 24 ; i++)
    {
        pTXParms->pwrGainEnd[i] = pParmDict[PARM_PWRGAINEND].v.ptS32[i];
    }
    for (i = 0; i < 24 ; i++)
    {
        pTXParms->pwrGainStep[i] = pParmDict[PARM_PWRGAINSTEP].v.ptS32[i];
    }
    for (i = 0; i < 40 ; i++)
    {
        pTXParms->pwrGainStart11AC[i] = pParmDict[PARM_PWRGAINSTART11AC].v.ptS32[i];
    }
    for (i = 0; i < 40 ; i++)
    {
        pTXParms->pwrGainEnd11AC[i] = pParmDict[PARM_PWRGAINEND11AC].v.ptS32[i];
    }
    for (i = 0; i < 40 ; i++)
    {
        pTXParms->pwrGainStep11AC[i] = pParmDict[PARM_PWRGAINSTEP11AC].v.ptS32[i];
    }
    for (i = 0; i < 8 ; i++)
    {
        pTXParms->pwrGainStartAC160[i] = pParmDict[PARM_PWRGAINSTARTAC160].v.ptS32[i];
    }
    for (i = 0; i < 8 ; i++)
    {
        pTXParms->pwrGainEndAC160[i] = pParmDict[PARM_PWRGAINENDAC160].v.ptS32[i];
    }
    for (i = 0; i < 8 ; i++)
    {
        pTXParms->pwrGainStepAC160[i] = pParmDict[PARM_PWRGAINSTEPAC160].v.ptS32[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pTXParms->bssid[i] = pParmDict[PARM_BSSID].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pTXParms->txStation[i] = pParmDict[PARM_TXSTATION].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pTXParms->rxStation[i] = pParmDict[PARM_RXSTATION].v.ptU8[i];
    }

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pTXParms->phyId)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXMODE, (A_UINT32)(((A_UINT32)&(pTXParms->txMode)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ, (A_UINT32)(((A_UINT32)&(pTXParms->freq)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ2, (A_UINT32)(((A_UINT32)&(pTXParms->freq2)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINMASK, (A_UINT32)(((A_UINT32)&(pTXParms->chainMask)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_WLANMODE, (A_UINT32)(((A_UINT32)&(pTXParms->wlanMode)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BANDWIDTH, (A_UINT32)(((A_UINT32)&(pTXParms->bandwidth)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GI, (A_UINT32)(((A_UINT32)&(pTXParms->gI)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTENNA, (A_UINT32)(((A_UINT32)&(pTXParms->antenna)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ENANI, (A_UINT32)(((A_UINT32)&(pTXParms->enANI)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SCRAMBLEROFF, (A_UINT32)(((A_UINT32)&(pTXParms->scramblerOff)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_AIFSN, (A_UINT32)(((A_UINT32)&(pTXParms->aifsn)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BROADCAST, (A_UINT32)(((A_UINT32)&(pTXParms->broadcast)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_AGG, (A_UINT32)(((A_UINT32)&(pTXParms->agg)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SHORTGUARD, (A_UINT32)(((A_UINT32)&(pTXParms->shortGuard)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DUTYCYCLE, (A_UINT32)(((A_UINT32)&(pTXParms->dutyCycle)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FLAGS, (A_UINT32)(((A_UINT32)&(pTXParms->flags)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_IR, (A_UINT32)(((A_UINT32)&(pTXParms->ir)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PKTSZ, (A_UINT32)(((A_UINT32)&(pTXParms->pktSz)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DATAPATTERN, (A_UINT32)(((A_UINT32)&(pTXParms->dataPattern)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXNUMPACKETS, (A_UINT32)(((A_UINT32)&(pTXParms->txNumPackets)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXPATTERN, (A_UINT32)(((A_UINT32)&(pTXParms->txPattern)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NPATTERN, (A_UINT32)(((A_UINT32)&(pTXParms->nPattern)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TPCM, (A_UINT32)(((A_UINT32)&(pTXParms->tpcm)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GAINIDX, (A_UINT32)(((A_UINT32)&(pTXParms->gainIdx)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAIN, (A_UINT32)(((A_UINT32)&(pTXParms->dacGain)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAINEND, (A_UINT32)(((A_UINT32)&(pTXParms->dacGainEnd)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAINSTEP, (A_UINT32)(((A_UINT32)&(pTXParms->dacGainStep)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACONFIG, (A_UINT32)(((A_UINT32)&(pTXParms->paConfig)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACONFIGEND, (A_UINT32)(((A_UINT32)&(pTXParms->paConfigEnd)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACONFIGSTEP, (A_UINT32)(((A_UINT32)&(pTXParms->paConfigStep)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD3, (A_UINT32)(((A_UINT32)&(pTXParms->pad3)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASK, (A_UINT32)(((A_UINT32)&(pTXParms->rateMask)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASK11AC, (A_UINT32)(((A_UINT32)&(pTXParms->rateMask11AC)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASKAC160, (A_UINT32)(((A_UINT32)&(pTXParms->rateMaskAC160)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTART, (A_UINT32)(((A_UINT32)&(pTXParms->pwrGainStart)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINEND, (A_UINT32)(((A_UINT32)&(pTXParms->pwrGainEnd)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTEP, (A_UINT32)(((A_UINT32)&(pTXParms->pwrGainStep)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTART11AC, (A_UINT32)(((A_UINT32)&(pTXParms->pwrGainStart11AC)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINEND11AC, (A_UINT32)(((A_UINT32)&(pTXParms->pwrGainEnd11AC)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTEP11AC, (A_UINT32)(((A_UINT32)&(pTXParms->pwrGainStep11AC)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTARTAC160, (A_UINT32)(((A_UINT32)&(pTXParms->pwrGainStartAC160)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINENDAC160, (A_UINT32)(((A_UINT32)&(pTXParms->pwrGainEndAC160)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTEPAC160, (A_UINT32)(((A_UINT32)&(pTXParms->pwrGainStepAC160)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BSSID, (A_UINT32)(((A_UINT32)&(pTXParms->bssid)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXSTATION, (A_UINT32)(((A_UINT32)&(pTXParms->txStation)) - (A_UINT32)pTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RXSTATION, (A_UINT32)(((A_UINT32)&(pTXParms->rxStation)) - (A_UINT32)pTXParms), pParmsOffset);
    return((void*) pTXParms);
}

static TX_OP_FUNC TXOpFunc = NULL;

TLV2_API void registerTXHandler(TX_OP_FUNC fp)
{
    TXOpFunc = fp;
}

A_BOOL TXOp(void *pParms)
{
    CMD_TX_PARMS *pTXParms = (CMD_TX_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TXOp: phyId %u\n", pTXParms->phyId);
    A_PRINTF("TXOp: txMode %u\n", pTXParms->txMode);
    A_PRINTF("TXOp: freq %u\n", pTXParms->freq);
    A_PRINTF("TXOp: freq2 %u\n", pTXParms->freq2);
    A_PRINTF("TXOp: chainMask 0x%x\n", pTXParms->chainMask);
    A_PRINTF("TXOp: wlanMode %u\n", pTXParms->wlanMode);
    A_PRINTF("TXOp: bandwidth %u\n", pTXParms->bandwidth);
    A_PRINTF("TXOp: gI %u\n", pTXParms->gI);
    A_PRINTF("TXOp: antenna %u\n", pTXParms->antenna);
    A_PRINTF("TXOp: enANI %u\n", pTXParms->enANI);
    A_PRINTF("TXOp: scramblerOff %u\n", pTXParms->scramblerOff);
    A_PRINTF("TXOp: aifsn %u\n", pTXParms->aifsn);
    A_PRINTF("TXOp: broadcast %u\n", pTXParms->broadcast);
    A_PRINTF("TXOp: agg %u\n", pTXParms->agg);
    A_PRINTF("TXOp: shortGuard %u\n", pTXParms->shortGuard);
    A_PRINTF("TXOp: dutyCycle %u\n", pTXParms->dutyCycle);
    A_PRINTF("TXOp: flags 0x%x\n", pTXParms->flags);
    A_PRINTF("TXOp: ir %u\n", pTXParms->ir);
    A_PRINTF("TXOp: pktSz %u\n", pTXParms->pktSz);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 40 entries
    {
        A_PRINTF("TXOp: dataPattern %u\n", pTXParms->dataPattern[i]);
    }
    A_PRINTF("TXOp: txNumPackets %u\n", pTXParms->txNumPackets);
    A_PRINTF("TXOp: txPattern %u\n", pTXParms->txPattern);
    A_PRINTF("TXOp: nPattern %u\n", pTXParms->nPattern);
    A_PRINTF("TXOp: tpcm %u\n", pTXParms->tpcm);
    A_PRINTF("TXOp: gainIdx %u\n", pTXParms->gainIdx);
    A_PRINTF("TXOp: dacGain %d\n", pTXParms->dacGain);
    A_PRINTF("TXOp: dacGainEnd %d\n", pTXParms->dacGainEnd);
    A_PRINTF("TXOp: dacGainStep %d\n", pTXParms->dacGainStep);
    A_PRINTF("TXOp: paConfig %u\n", pTXParms->paConfig);
    A_PRINTF("TXOp: paConfigEnd %u\n", pTXParms->paConfigEnd);
    A_PRINTF("TXOp: paConfigStep %u\n", pTXParms->paConfigStep);
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("TXOp: pad3 %u\n", pTXParms->pad3[i]);
    }
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("TXOp: rateMask 0x%x\n", pTXParms->rateMask[i]);
    }
    for (i = 0; i < 5 ; i++)
    {
        A_PRINTF("TXOp: rateMask11AC 0x%x\n", pTXParms->rateMask11AC[i]);
    }
    A_PRINTF("TXOp: rateMaskAC160 0x%x\n", pTXParms->rateMaskAC160);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 24 entries
    {
        A_PRINTF("TXOp: pwrGainStart 0x%x\n", pTXParms->pwrGainStart[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 24 entries
    {
        A_PRINTF("TXOp: pwrGainEnd 0x%x\n", pTXParms->pwrGainEnd[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 24 entries
    {
        A_PRINTF("TXOp: pwrGainStep 0x%x\n", pTXParms->pwrGainStep[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 40 entries
    {
        A_PRINTF("TXOp: pwrGainStart11AC 0x%x\n", pTXParms->pwrGainStart11AC[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 40 entries
    {
        A_PRINTF("TXOp: pwrGainEnd11AC 0x%x\n", pTXParms->pwrGainEnd11AC[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 40 entries
    {
        A_PRINTF("TXOp: pwrGainStep11AC 0x%x\n", pTXParms->pwrGainStep11AC[i]);
    }
    for (i = 0; i < 8 ; i++)
    {
        A_PRINTF("TXOp: pwrGainStartAC160 0x%x\n", pTXParms->pwrGainStartAC160[i]);
    }
    for (i = 0; i < 8 ; i++)
    {
        A_PRINTF("TXOp: pwrGainEndAC160 0x%x\n", pTXParms->pwrGainEndAC160[i]);
    }
    for (i = 0; i < 8 ; i++)
    {
        A_PRINTF("TXOp: pwrGainStepAC160 0x%x\n", pTXParms->pwrGainStepAC160[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("TXOp: bssid 0x%x\n", pTXParms->bssid[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("TXOp: txStation 0x%x\n", pTXParms->txStation[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("TXOp: rxStation 0x%x\n", pTXParms->rxStation[i]);
    }
#endif //_DEBUG

    if (NULL != TXOpFunc) {
        (*TXOpFunc)(pTXParms);
    }
    return(TRUE);
}
