// This is an auto-generated file from input\cmdMoreSegmentHandler.s
#include "tlv2Inc.h"
#include "cmdMoreSegmentHandler.h"

void* initMORESEGMENTOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_MORESEGMENT_PARMS  *pMORESEGMENTParms = (CMD_MORESEGMENT_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pMORESEGMENTParms->cmdId = pParmDict[PARM_CMDID].v.valU16;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_CMDID, (A_UINT32)(((A_UINT32)&(pMORESEGMENTParms->cmdId)) - (A_UINT32)pMORESEGMENTParms), pParmsOffset);
    return((void*) pMORESEGMENTParms);
}

static MORESEGMENT_OP_FUNC MORESEGMENTOpFunc = NULL;

TLV2_API void registerMORESEGMENTHandler(MORESEGMENT_OP_FUNC fp)
{
    MORESEGMENTOpFunc = fp;
}

A_BOOL MORESEGMENTOp(void *pParms)
{
    CMD_MORESEGMENT_PARMS *pMORESEGMENTParms = (CMD_MORESEGMENT_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("MORESEGMENTOp: cmdId %u\n", pMORESEGMENTParms->cmdId);
#endif //_DEBUG

    if (NULL != MORESEGMENTOpFunc) {
        (*MORESEGMENTOpFunc)(pMORESEGMENTParms);
    }
    return(TRUE);
}

void* initMORESEGMENTRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_MORESEGMENTRSP_PARMS  *pMORESEGMENTRSPParms = (CMD_MORESEGMENTRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pMORESEGMENTRSPParms->cmdId = pParmDict[PARM_CMDID].v.valU16;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_CMDID, (A_UINT32)(((A_UINT32)&(pMORESEGMENTRSPParms->cmdId)) - (A_UINT32)pMORESEGMENTRSPParms), pParmsOffset);
    return((void*) pMORESEGMENTRSPParms);
}

static MORESEGMENTRSP_OP_FUNC MORESEGMENTRSPOpFunc = NULL;

TLV2_API void registerMORESEGMENTRSPHandler(MORESEGMENTRSP_OP_FUNC fp)
{
    MORESEGMENTRSPOpFunc = fp;
}

A_BOOL MORESEGMENTRSPOp(void *pParms)
{
    CMD_MORESEGMENTRSP_PARMS *pMORESEGMENTRSPParms = (CMD_MORESEGMENTRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("MORESEGMENTRSPOp: cmdId %u\n", pMORESEGMENTRSPParms->cmdId);
#endif //_DEBUG

    if (NULL != MORESEGMENTRSPOpFunc) {
        (*MORESEGMENTRSPOpFunc)(pMORESEGMENTRSPParms);
    }
    return(TRUE);
}
