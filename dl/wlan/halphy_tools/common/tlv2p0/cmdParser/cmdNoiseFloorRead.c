// This is an auto-generated file from cmdNoiseFloorRead.s
#include "tlv2Inc.h"
#include "cmdNoiseFloorRead.h"

void* initNOISEFLOORREADOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_NOISEFLOORREAD_PARMS  *pNOISEFLOORREADParms = (CMD_NOISEFLOORREAD_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pNOISEFLOORREADParms->freq = pParmDict[PARM_FREQ].v.valU16;
    pNOISEFLOORREADParms->chainMask = pParmDict[PARM_CHAINMASK].v.valU16;
    pNOISEFLOORREADParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_FREQ, (A_UINT32)(((A_UINT32)&(pNOISEFLOORREADParms->freq)) - (A_UINT32)pNOISEFLOORREADParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINMASK, (A_UINT32)(((A_UINT32)&(pNOISEFLOORREADParms->chainMask)) - (A_UINT32)pNOISEFLOORREADParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pNOISEFLOORREADParms->phyId)) - (A_UINT32)pNOISEFLOORREADParms), pParmsOffset);
    return((void*) pNOISEFLOORREADParms);
}

static NOISEFLOORREAD_OP_FUNC NOISEFLOORREADOpFunc = NULL;

TLV2_API void registerNOISEFLOORREADHandler(NOISEFLOORREAD_OP_FUNC fp)
{
    NOISEFLOORREADOpFunc = fp;
}

A_BOOL NOISEFLOORREADOp(void *pParms)
{
    CMD_NOISEFLOORREAD_PARMS *pNOISEFLOORREADParms = (CMD_NOISEFLOORREAD_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("NOISEFLOORREADOp: freq %u\n", pNOISEFLOORREADParms->freq);
    A_PRINTF("NOISEFLOORREADOp: chainMask 0x%x\n", pNOISEFLOORREADParms->chainMask);
    A_PRINTF("NOISEFLOORREADOp: phyId %u\n", pNOISEFLOORREADParms->phyId);
#endif //_DEBUG

    if (NULL != NOISEFLOORREADOpFunc) {
        (*NOISEFLOORREADOpFunc)(pNOISEFLOORREADParms);
    }
    return(TRUE);
}

void* initNOISEFLOORREADRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_NOISEFLOORREADRSP_PARMS  *pNOISEFLOORREADRSPParms = (CMD_NOISEFLOORREADRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    memset(pNOISEFLOORREADRSPParms->nfValues, 0, sizeof(pNOISEFLOORREADRSPParms->nfValues));
    pNOISEFLOORREADRSPParms->nfValues[0] = pParmDict[PARM_NFVALUES].v.ptU32[0];
    pNOISEFLOORREADRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_NFVALUES, (A_UINT32)(((A_UINT32)&(pNOISEFLOORREADRSPParms->nfValues)) - (A_UINT32)pNOISEFLOORREADRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pNOISEFLOORREADRSPParms->phyId)) - (A_UINT32)pNOISEFLOORREADRSPParms), pParmsOffset);
    return((void*) pNOISEFLOORREADRSPParms);
}

static NOISEFLOORREADRSP_OP_FUNC NOISEFLOORREADRSPOpFunc = NULL;

TLV2_API void registerNOISEFLOORREADRSPHandler(NOISEFLOORREADRSP_OP_FUNC fp)
{
    NOISEFLOORREADRSPOpFunc = fp;
}

A_BOOL NOISEFLOORREADRSPOp(void *pParms)
{
    CMD_NOISEFLOORREADRSP_PARMS *pNOISEFLOORREADRSPParms = (CMD_NOISEFLOORREADRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    for (i = 0; i < 8 ; i++) // can be modified to print up to 16 entries
    {
        A_PRINTF("NOISEFLOORREADRSPOp: nfValues %u\n", pNOISEFLOORREADRSPParms->nfValues[i]);
    }
    A_PRINTF("NOISEFLOORREADRSPOp: phyId %u\n", pNOISEFLOORREADRSPParms->phyId);
#endif //_DEBUG

    if (NULL != NOISEFLOORREADRSPOpFunc) {
        (*NOISEFLOORREADRSPOpFunc)(pNOISEFLOORREADRSPParms);
    }
    return(TRUE);
}

