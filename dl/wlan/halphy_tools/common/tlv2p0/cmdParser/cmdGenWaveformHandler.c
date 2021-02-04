// This is an auto-generated file from input\cmdGenWaveformHandler.s

#ifdef USE_TLV2_EXTCMD

#include "tlv2Inc.h"
#include "cmdGenWaveformHandler.h"

void* initGENWAVEFORMOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_GENWAVEFORM_PARMS  *pGENWAVEFORMParms = (CMD_GENWAVEFORM_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pGENWAVEFORMParms->waveformIndex = pParmDict[PARM_WAVEFORMINDEX].v.valU16;
    pGENWAVEFORMParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_WAVEFORMINDEX, (A_UINT32)(((A_UINT32)&(pGENWAVEFORMParms->waveformIndex)) - (A_UINT32)pGENWAVEFORMParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pGENWAVEFORMParms->phyId)) - (A_UINT32)pGENWAVEFORMParms), pParmsOffset);
    return((void*) pGENWAVEFORMParms);
}

static GENWAVEFORM_OP_FUNC GENWAVEFORMOpFunc = NULL;

TLV2_API void registerGENWAVEFORMHandler(GENWAVEFORM_OP_FUNC fp)
{
    GENWAVEFORMOpFunc = fp;
}

A_BOOL GENWAVEFORMOp(void *pParms)
{
    CMD_GENWAVEFORM_PARMS *pGENWAVEFORMParms = (CMD_GENWAVEFORM_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("GENWAVEFORMOp: waveformIndex %u\n", pGENWAVEFORMParms->waveformIndex);
    A_PRINTF("GENWAVEFORMOp: phyId %u\n", pGENWAVEFORMParms->phyId);
#endif //_DEBUG

    if (NULL != GENWAVEFORMOpFunc) {
        (*GENWAVEFORMOpFunc)(pGENWAVEFORMParms);
    }
    return(TRUE);
}

void* initGENWAVEFORMRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_GENWAVEFORMRSP_PARMS  *pGENWAVEFORMRSPParms = (CMD_GENWAVEFORMRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    memset(pGENWAVEFORMRSPParms->dataI, 0, sizeof(pGENWAVEFORMRSPParms->dataI));
    memset(pGENWAVEFORMRSPParms->dataQ, 0, sizeof(pGENWAVEFORMRSPParms->dataQ));
    pGENWAVEFORMRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pGENWAVEFORMRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_DATAI, (A_UINT32)(((A_UINT32)&(pGENWAVEFORMRSPParms->dataI)) - (A_UINT32)pGENWAVEFORMRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DATAQ, (A_UINT32)(((A_UINT32)&(pGENWAVEFORMRSPParms->dataQ)) - (A_UINT32)pGENWAVEFORMRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pGENWAVEFORMRSPParms->status)) - (A_UINT32)pGENWAVEFORMRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pGENWAVEFORMRSPParms->phyId)) - (A_UINT32)pGENWAVEFORMRSPParms), pParmsOffset);
    return((void*) pGENWAVEFORMRSPParms);
}

static GENWAVEFORMRSP_OP_FUNC GENWAVEFORMRSPOpFunc = NULL;

TLV2_API void registerGENWAVEFORMRSPHandler(GENWAVEFORMRSP_OP_FUNC fp)
{
    GENWAVEFORMRSPOpFunc = fp;
}

A_BOOL GENWAVEFORMRSPOp(void *pParms)
{
    CMD_GENWAVEFORMRSP_PARMS *pGENWAVEFORMRSPParms = (CMD_GENWAVEFORMRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    for (i = 0; i < 8 ; i++) // can be modified to print up to 2048 entries
    {
        A_PRINTF("GENWAVEFORMRSPOp: dataI 0x%x\n", pGENWAVEFORMRSPParms->dataI[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 2048 entries
    {
        A_PRINTF("GENWAVEFORMRSPOp: dataQ 0x%x\n", pGENWAVEFORMRSPParms->dataQ[i]);
    }
    A_PRINTF("GENWAVEFORMRSPOp: status %u\n", pGENWAVEFORMRSPParms->status);
    A_PRINTF("GENWAVEFORMRSPOp: phyId %u\n", pGENWAVEFORMRSPParms->phyId);
#endif //_DEBUG

    if (NULL != GENWAVEFORMRSPOpFunc) {
        (*GENWAVEFORMRSPOpFunc)(pGENWAVEFORMRSPParms);
    }
    return(TRUE);
}

#endif
