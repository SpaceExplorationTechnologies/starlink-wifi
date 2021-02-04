// This is an auto-generated file from input\cmdTPCCALHandler.s
#include "tlv2Inc.h"
#include "cmdTPCCALHandler.h"

void* initTPCCALOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_TPCCAL_PARMS  *pTPCCALParms = (CMD_TPCCAL_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pTPCCALParms->radioId = pParmDict[PARM_RADIOID].v.valU8;
    pTPCCALParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_RADIOID, (A_UINT32)(((A_UINT32)&(pTPCCALParms->radioId)) - (A_UINT32)pTPCCALParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pTPCCALParms->phyId)) - (A_UINT32)pTPCCALParms), pParmsOffset);
    return((void*) pTPCCALParms);
}

static TPCCAL_OP_FUNC TPCCALOpFunc = NULL;

TLV2_API void registerTPCCALHandler(TPCCAL_OP_FUNC fp)
{
    TPCCALOpFunc = fp;
}

A_BOOL TPCCALOp(void *pParms)
{
    CMD_TPCCAL_PARMS *pTPCCALParms = (CMD_TPCCAL_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TPCCALOp: radioId %u\n", pTPCCALParms->radioId);
    A_PRINTF("TPCCALOp: phyId %u\n", pTPCCALParms->phyId);
#endif //_DEBUG

    if (NULL != TPCCALOpFunc) {
        (*TPCCALOpFunc)(pTPCCALParms);
    }
    return(TRUE);
}

void* initTPCCALRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_TPCCALRSP_PARMS  *pTPCCALRSPParms = (CMD_TPCCALRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pTPCCALRSPParms->radioId = pParmDict[PARM_RADIOID].v.valU8;
    pTPCCALRSPParms->chanFreq = pParmDict[PARM_CHANFREQ].v.valU8;
    pTPCCALRSPParms->numFreq2G = pParmDict[PARM_NUMFREQ2G].v.valU8;
    memset(pTPCCALRSPParms->freq2G, 0, sizeof(pTPCCALRSPParms->freq2G));
    for (i = 0; i < 3 ; i++)
    {
        pTPCCALRSPParms->freq2G[i] = pParmDict[PARM_FREQ2G].v.ptU8[i];
    }
    pTPCCALRSPParms->numFreq5G = pParmDict[PARM_NUMFREQ5G].v.valU8;
    memset(pTPCCALRSPParms->freq5G, 0, sizeof(pTPCCALRSPParms->freq5G));
    for (i = 0; i < 8 ; i++)
    {
        pTPCCALRSPParms->freq5G[i] = pParmDict[PARM_FREQ5G].v.ptU8[i];
    }
    pTPCCALRSPParms->numChain = pParmDict[PARM_NUMCHAIN].v.valU8;
    memset(pTPCCALRSPParms->chainMasks, 0, sizeof(pTPCCALRSPParms->chainMasks));
    for (i = 0; i < 2 ; i++)
    {
        pTPCCALRSPParms->chainMasks[i] = pParmDict[PARM_CHAINMASKS].v.ptU8[i];
    }
    pTPCCALRSPParms->numCALPt2G = pParmDict[PARM_NUMCALPT2G].v.valU8;
    for (i = 0; i < 13 ; i++)
    {
        pTPCCALRSPParms->tgtPwr2G[i] = pParmDict[PARM_TGTPWR2G].v.ptS16[i];
    }
    for (i = 0; i < 13 ; i++)
    {
        pTPCCALRSPParms->CALPt2G[i] = pParmDict[PARM_CALPT2G].v.ptU8[i];
    }
    for (i = 0; i < 13 ; i++)
    {
        pTPCCALRSPParms->txGains2G[i] = pParmDict[PARM_TXGAINS2G].v.ptU8[i];
    }
    for (i = 0; i < 13 ; i++)
    {
        pTPCCALRSPParms->dacGains2G[i] = pParmDict[PARM_DACGAINS2G].v.ptU8[i];
    }
    for (i = 0; i < 13 ; i++)
    {
        pTPCCALRSPParms->paCfg2G[i] = pParmDict[PARM_PACFG2G].v.ptU8[i];
    }
    pTPCCALRSPParms->numCALPt5G = pParmDict[PARM_NUMCALPT5G].v.valU8;
    for (i = 0; i < 13 ; i++)
    {
        pTPCCALRSPParms->CALPt5G[i] = pParmDict[PARM_CALPT5G].v.ptU8[i];
    }
    for (i = 0; i < 13 ; i++)
    {
        pTPCCALRSPParms->tgtPwr5G[i] = pParmDict[PARM_TGTPWR5G].v.ptS16[i];
    }
    for (i = 0; i < 13 ; i++)
    {
        pTPCCALRSPParms->txGains5G[i] = pParmDict[PARM_TXGAINS5G].v.ptU8[i];
    }
    for (i = 0; i < 13 ; i++)
    {
        pTPCCALRSPParms->dacGains5G[i] = pParmDict[PARM_DACGAINS5G].v.ptU8[i];
    }
    for (i = 0; i < 13 ; i++)
    {
        pTPCCALRSPParms->paCfg5G[i] = pParmDict[PARM_PACFG5G].v.ptU8[i];
    }
    pTPCCALRSPParms->miscFlags = pParmDict[PARM_MISCFLAGS].v.valU8;
    pTPCCALRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_RADIOID, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->radioId)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHANFREQ, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->chanFreq)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMFREQ2G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->numFreq2G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ2G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->freq2G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMFREQ5G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->numFreq5G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ5G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->freq5G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMCHAIN, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->numChain)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINMASKS, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->chainMasks)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMCALPT2G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->numCALPt2G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TGTPWR2G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->tgtPwr2G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CALPT2G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->CALPt2G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXGAINS2G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->txGains2G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAINS2G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->dacGains2G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACFG2G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->paCfg2G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMCALPT5G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->numCALPt5G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CALPT5G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->CALPt5G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TGTPWR5G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->tgtPwr5G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXGAINS5G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->txGains5G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAINS5G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->dacGains5G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACFG5G, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->paCfg5G)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_MISCFLAGS, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->miscFlags)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pTPCCALRSPParms->phyId)) - (A_UINT32)pTPCCALRSPParms), pParmsOffset);
    return((void*) pTPCCALRSPParms);
}

static TPCCALRSP_OP_FUNC TPCCALRSPOpFunc = NULL;

TLV2_API void registerTPCCALRSPHandler(TPCCALRSP_OP_FUNC fp)
{
    TPCCALRSPOpFunc = fp;
}

A_BOOL TPCCALRSPOp(void *pParms)
{
    CMD_TPCCALRSP_PARMS *pTPCCALRSPParms = (CMD_TPCCALRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TPCCALRSPOp: radioId %u\n", pTPCCALRSPParms->radioId);
    A_PRINTF("TPCCALRSPOp: chanFreq %u\n", pTPCCALRSPParms->chanFreq);
    A_PRINTF("TPCCALRSPOp: numFreq2G %u\n", pTPCCALRSPParms->numFreq2G);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 14 entries
    {
        A_PRINTF("TPCCALRSPOp: freq2G %u\n", pTPCCALRSPParms->freq2G[i]);
    }
    A_PRINTF("TPCCALRSPOp: numFreq5G %u\n", pTPCCALRSPParms->numFreq5G);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 32 entries
    {
        A_PRINTF("TPCCALRSPOp: freq5G %u\n", pTPCCALRSPParms->freq5G[i]);
    }
    A_PRINTF("TPCCALRSPOp: numChain %u\n", pTPCCALRSPParms->numChain);
    for (i = 0; i < 4 ; i++)
    {
        A_PRINTF("TPCCALRSPOp: chainMasks 0x%x\n", pTPCCALRSPParms->chainMasks[i]);
    }
    A_PRINTF("TPCCALRSPOp: numCALPt2G %u\n", pTPCCALRSPParms->numCALPt2G);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 13 entries
    {
        A_PRINTF("TPCCALRSPOp: tgtPwr2G %d\n", pTPCCALRSPParms->tgtPwr2G[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 13 entries
    {
        A_PRINTF("TPCCALRSPOp: CALPt2G %u\n", pTPCCALRSPParms->CALPt2G[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 13 entries
    {
        A_PRINTF("TPCCALRSPOp: txGains2G %u\n", pTPCCALRSPParms->txGains2G[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 13 entries
    {
        A_PRINTF("TPCCALRSPOp: dacGains2G %u\n", pTPCCALRSPParms->dacGains2G[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 13 entries
    {
        A_PRINTF("TPCCALRSPOp: paCfg2G %u\n", pTPCCALRSPParms->paCfg2G[i]);
    }
    A_PRINTF("TPCCALRSPOp: numCALPt5G %u\n", pTPCCALRSPParms->numCALPt5G);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 13 entries
    {
        A_PRINTF("TPCCALRSPOp: CALPt5G %u\n", pTPCCALRSPParms->CALPt5G[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 13 entries
    {
        A_PRINTF("TPCCALRSPOp: tgtPwr5G %d\n", pTPCCALRSPParms->tgtPwr5G[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 13 entries
    {
        A_PRINTF("TPCCALRSPOp: txGains5G %u\n", pTPCCALRSPParms->txGains5G[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 13 entries
    {
        A_PRINTF("TPCCALRSPOp: dacGains5G %u\n", pTPCCALRSPParms->dacGains5G[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 13 entries
    {
        A_PRINTF("TPCCALRSPOp: paCfg5G %u\n", pTPCCALRSPParms->paCfg5G[i]);
    }
    A_PRINTF("TPCCALRSPOp: miscFlags 0x%x\n", pTPCCALRSPParms->miscFlags);
    A_PRINTF("TPCCALRSPOp: phyId %u\n", pTPCCALRSPParms->phyId);
#endif //_DEBUG

    if (NULL != TPCCALRSPOpFunc) {
        (*TPCCALRSPOpFunc)(pTPCCALRSPParms);
    }
    return(TRUE);
}
