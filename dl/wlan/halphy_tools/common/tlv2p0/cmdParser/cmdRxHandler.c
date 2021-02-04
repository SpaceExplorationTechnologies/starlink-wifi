// This is an auto-generated file from input\cmdRxHandler.s
#include "tlv2Inc.h"
#include "cmdRxHandler.h"

void* initRXOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_RX_PARMS  *pRXParms = (CMD_RX_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pRXParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pRXParms->rxMode = pParmDict[PARM_RXMODE].v.valU8;
    pRXParms->freq = pParmDict[PARM_FREQ].v.valU16;
    pRXParms->freq2 = pParmDict[PARM_FREQ2].v.valU16;
    pRXParms->chainMask = pParmDict[PARM_CHAINMASK].v.valU8;
    pRXParms->wlanMode = pParmDict[PARM_WLANMODE].v.valU8;
    pRXParms->bandwidth = pParmDict[PARM_BANDWIDTH].v.valU8;
    pRXParms->antenna = pParmDict[PARM_ANTENNA].v.valU8;
    pRXParms->enANI = pParmDict[PARM_ENANI].v.valU8;
    pRXParms->ack = pParmDict[PARM_ACK].v.valU8;
    pRXParms->broadcast = pParmDict[PARM_BROADCAST].v.valU8;
    pRXParms->lpl = pParmDict[PARM_LPL].v.valU8;
    pRXParms->antswitch1 = pParmDict[PARM_ANTSWITCH1].v.valU8;
    pRXParms->antswitch2 = pParmDict[PARM_ANTSWITCH2].v.valU8;
    for (i = 0; i < 2 ; i++)
    {
        pRXParms->pad2[i] = pParmDict[PARM_PAD2].v.ptU8[i];
    }
    pRXParms->spectralScan = pParmDict[PARM_SPECTRALSCAN].v.valU16;
    pRXParms->noiseFloor = pParmDict[PARM_NOISEFLOOR].v.valS16;
    for (i = 0; i < 2 ; i++)
    {
        pRXParms->regDmn[i] = pParmDict[PARM_REGDMN].v.ptU16[i];
    }
    pRXParms->expectedPkts = pParmDict[PARM_EXPECTEDPKTS].v.valU32;
    pRXParms->otpWriteFlag = pParmDict[PARM_OTPWRITEFLAG].v.valU32;
    pRXParms->flags = pParmDict[PARM_FLAGS].v.valU32;
    for (i = 0; i < 3 ; i++)
    {
        pRXParms->rateMask[i] = pParmDict[PARM_RATEMASK].v.ptU32[i];
    }
    for (i = 0; i < 5 ; i++)
    {
        pRXParms->rateMask11AC[i] = pParmDict[PARM_RATEMASK11AC].v.ptU32[i];
    }
    pRXParms->rateMaskAC160 = pParmDict[PARM_RATEMASKAC160].v.valU32;
    for (i = 0; i < 6 ; i++)
    {
        pRXParms->bssid[i] = pParmDict[PARM_BSSID].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pRXParms->staAddr[i] = pParmDict[PARM_STAADDR].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pRXParms->btAddr[i] = pParmDict[PARM_BTADDR].v.ptU8[i];
    }

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pRXParms->phyId)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RXMODE, (A_UINT32)(((A_UINT32)&(pRXParms->rxMode)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ, (A_UINT32)(((A_UINT32)&(pRXParms->freq)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ2, (A_UINT32)(((A_UINT32)&(pRXParms->freq2)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINMASK, (A_UINT32)(((A_UINT32)&(pRXParms->chainMask)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_WLANMODE, (A_UINT32)(((A_UINT32)&(pRXParms->wlanMode)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BANDWIDTH, (A_UINT32)(((A_UINT32)&(pRXParms->bandwidth)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTENNA, (A_UINT32)(((A_UINT32)&(pRXParms->antenna)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ENANI, (A_UINT32)(((A_UINT32)&(pRXParms->enANI)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ACK, (A_UINT32)(((A_UINT32)&(pRXParms->ack)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BROADCAST, (A_UINT32)(((A_UINT32)&(pRXParms->broadcast)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LPL, (A_UINT32)(((A_UINT32)&(pRXParms->lpl)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTSWITCH1, (A_UINT32)(((A_UINT32)&(pRXParms->antswitch1)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTSWITCH2, (A_UINT32)(((A_UINT32)&(pRXParms->antswitch2)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD2, (A_UINT32)(((A_UINT32)&(pRXParms->pad2)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SPECTRALSCAN, (A_UINT32)(((A_UINT32)&(pRXParms->spectralScan)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NOISEFLOOR, (A_UINT32)(((A_UINT32)&(pRXParms->noiseFloor)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_REGDMN, (A_UINT32)(((A_UINT32)&(pRXParms->regDmn)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_EXPECTEDPKTS, (A_UINT32)(((A_UINT32)&(pRXParms->expectedPkts)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OTPWRITEFLAG, (A_UINT32)(((A_UINT32)&(pRXParms->otpWriteFlag)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FLAGS, (A_UINT32)(((A_UINT32)&(pRXParms->flags)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASK, (A_UINT32)(((A_UINT32)&(pRXParms->rateMask)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASK11AC, (A_UINT32)(((A_UINT32)&(pRXParms->rateMask11AC)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASKAC160, (A_UINT32)(((A_UINT32)&(pRXParms->rateMaskAC160)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BSSID, (A_UINT32)(((A_UINT32)&(pRXParms->bssid)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STAADDR, (A_UINT32)(((A_UINT32)&(pRXParms->staAddr)) - (A_UINT32)pRXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BTADDR, (A_UINT32)(((A_UINT32)&(pRXParms->btAddr)) - (A_UINT32)pRXParms), pParmsOffset);
    return((void*) pRXParms);
}

static RX_OP_FUNC RXOpFunc = NULL;

TLV2_API void registerRXHandler(RX_OP_FUNC fp)
{
    RXOpFunc = fp;
}

A_BOOL RXOp(void *pParms)
{
    CMD_RX_PARMS *pRXParms = (CMD_RX_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("RXOp: phyId %u\n", pRXParms->phyId);
    A_PRINTF("RXOp: rxMode %u\n", pRXParms->rxMode);
    A_PRINTF("RXOp: freq %u\n", pRXParms->freq);
    A_PRINTF("RXOp: freq2 %u\n", pRXParms->freq2);
    A_PRINTF("RXOp: chainMask 0x%x\n", pRXParms->chainMask);
    A_PRINTF("RXOp: wlanMode %u\n", pRXParms->wlanMode);
    A_PRINTF("RXOp: bandwidth %u\n", pRXParms->bandwidth);
    A_PRINTF("RXOp: antenna %u\n", pRXParms->antenna);
    A_PRINTF("RXOp: enANI %u\n", pRXParms->enANI);
    A_PRINTF("RXOp: ack %u\n", pRXParms->ack);
    A_PRINTF("RXOp: broadcast %u\n", pRXParms->broadcast);
    A_PRINTF("RXOp: lpl %u\n", pRXParms->lpl);
    A_PRINTF("RXOp: antswitch1 %u\n", pRXParms->antswitch1);
    A_PRINTF("RXOp: antswitch2 %u\n", pRXParms->antswitch2);
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("RXOp: pad2 %u\n", pRXParms->pad2[i]);
    }
    A_PRINTF("RXOp: spectralScan %u\n", pRXParms->spectralScan);
    A_PRINTF("RXOp: noiseFloor %d\n", pRXParms->noiseFloor);
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("RXOp: regDmn 0x%x\n", pRXParms->regDmn[i]);
    }
    A_PRINTF("RXOp: expectedPkts %u\n", pRXParms->expectedPkts);
    A_PRINTF("RXOp: otpWriteFlag 0x%x\n", pRXParms->otpWriteFlag);
    A_PRINTF("RXOp: flags 0x%x\n", pRXParms->flags);
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("RXOp: rateMask 0x%x\n", pRXParms->rateMask[i]);
    }
    for (i = 0; i < 5 ; i++)
    {
        A_PRINTF("RXOp: rateMask11AC 0x%x\n", pRXParms->rateMask11AC[i]);
    }
    A_PRINTF("RXOp: rateMaskAC160 0x%x\n", pRXParms->rateMaskAC160);
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("RXOp: bssid 0x%x\n", pRXParms->bssid[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("RXOp: staAddr 0x%x\n", pRXParms->staAddr[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("RXOp: btAddr 0x%x\n", pRXParms->btAddr[i]);
    }
#endif //_DEBUG

    if (NULL != RXOpFunc) {
        (*RXOpFunc)(pRXParms);
    }
    return(TRUE);
}

void* initRXRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_RXRSP_PARMS  *pRXRSPParms = (CMD_RXRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pRXRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pRXRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pRXRSPParms->rxMode = pParmDict[PARM_RXMODE].v.valU8;
    pRXRSPParms->pad1 = pParmDict[PARM_PAD1].v.valU8;
    pRXRSPParms->rssiInDBm = pParmDict[PARM_RSSIINDBM].v.valS32;
    pRXRSPParms->totalPackets = pParmDict[PARM_TOTALPACKETS].v.valU32;
    pRXRSPParms->crcPackets = pParmDict[PARM_CRCPACKETS].v.valU32;
    pRXRSPParms->secErrPkt = pParmDict[PARM_SECERRPKT].v.valU32;
    for (i = 0; i < 2 ; i++)
    {
        pRXRSPParms->rateMask[i] = pParmDict[PARM_RATEMASK].v.ptU32[i];
    }
    for (i = 0; i < 5 ; i++)
    {
        pRXRSPParms->rateMask11AC[i] = pParmDict[PARM_RATEMASK11AC].v.ptU32[i];
    }
    memset(pRXRSPParms->rateCnt, 0, sizeof(pRXRSPParms->rateCnt));
    memset(pRXRSPParms->rateCnt11ac, 0, sizeof(pRXRSPParms->rateCnt11ac));
    memset(pRXRSPParms->rateShortG, 0, sizeof(pRXRSPParms->rateShortG));
    memset(pRXRSPParms->rateShortG11ac, 0, sizeof(pRXRSPParms->rateShortG11ac));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pRXRSPParms->phyId)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pRXRSPParms->status)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RXMODE, (A_UINT32)(((A_UINT32)&(pRXRSPParms->rxMode)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD1, (A_UINT32)(((A_UINT32)&(pRXRSPParms->pad1)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RSSIINDBM, (A_UINT32)(((A_UINT32)&(pRXRSPParms->rssiInDBm)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TOTALPACKETS, (A_UINT32)(((A_UINT32)&(pRXRSPParms->totalPackets)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CRCPACKETS, (A_UINT32)(((A_UINT32)&(pRXRSPParms->crcPackets)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SECERRPKT, (A_UINT32)(((A_UINT32)&(pRXRSPParms->secErrPkt)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASK, (A_UINT32)(((A_UINT32)&(pRXRSPParms->rateMask)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASK11AC, (A_UINT32)(((A_UINT32)&(pRXRSPParms->rateMask11AC)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATECNT, (A_UINT32)(((A_UINT32)&(pRXRSPParms->rateCnt)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATECNT11AC, (A_UINT32)(((A_UINT32)&(pRXRSPParms->rateCnt11ac)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATESHORTG, (A_UINT32)(((A_UINT32)&(pRXRSPParms->rateShortG)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATESHORTG11AC, (A_UINT32)(((A_UINT32)&(pRXRSPParms->rateShortG11ac)) - (A_UINT32)pRXRSPParms), pParmsOffset);
    return((void*) pRXRSPParms);
}

static RXRSP_OP_FUNC RXRSPOpFunc = NULL;

TLV2_API void registerRXRSPHandler(RXRSP_OP_FUNC fp)
{
    RXRSPOpFunc = fp;
}

A_BOOL RXRSPOp(void *pParms)
{
    CMD_RXRSP_PARMS *pRXRSPParms = (CMD_RXRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("RXRSPOp: phyId %u\n", pRXRSPParms->phyId);
    A_PRINTF("RXRSPOp: status %u\n", pRXRSPParms->status);
    A_PRINTF("RXRSPOp: rxMode %u\n", pRXRSPParms->rxMode);
    A_PRINTF("RXRSPOp: pad1 0x%x\n", pRXRSPParms->pad1);
    A_PRINTF("RXRSPOp: rssiInDBm %d\n", pRXRSPParms->rssiInDBm);
    A_PRINTF("RXRSPOp: totalPackets %u\n", pRXRSPParms->totalPackets);
    A_PRINTF("RXRSPOp: crcPackets %u\n", pRXRSPParms->crcPackets);
    A_PRINTF("RXRSPOp: secErrPkt %u\n", pRXRSPParms->secErrPkt);
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("RXRSPOp: rateMask 0x%x\n", pRXRSPParms->rateMask[i]);
    }
    for (i = 0; i < 5 ; i++)
    {
        A_PRINTF("RXRSPOp: rateMask11AC 0x%x\n", pRXRSPParms->rateMask11AC[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 32 entries
    {
        A_PRINTF("RXRSPOp: rateCnt %u\n", pRXRSPParms->rateCnt[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 69 entries
    {
        A_PRINTF("RXRSPOp: rateCnt11ac %u\n", pRXRSPParms->rateCnt11ac[i]);
    }
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("RXRSPOp: rateShortG 0x%x\n", pRXRSPParms->rateShortG[i]);
    }
    for (i = 0; i < 5 ; i++)
    {
        A_PRINTF("RXRSPOp: rateShortG11ac 0x%x\n", pRXRSPParms->rateShortG11ac[i]);
    }
#endif //_DEBUG

    if (NULL != RXRSPOpFunc) {
        (*RXRSPOpFunc)(pRXRSPParms);
    }
    return(TRUE);
}
