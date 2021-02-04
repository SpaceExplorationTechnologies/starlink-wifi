// This is an auto-generated file from input/cmdLMHWCALRSPHandler.s
#include "tlv2Inc.h"
#include "cmdLMHWCALRSPHandler.h"

void* initLMHWCALRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_LMHWCALRSP_PARMS  *pLMHWCALRSPParms = (CMD_LMHWCALRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pLMHWCALRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pLMHWCALRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pLMHWCALRSPParms->hwCalTime = pParmDict[PARM_HWCALTIME].v.valU16;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pLMHWCALRSPParms->phyId)) - (A_UINT32)pLMHWCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pLMHWCALRSPParms->status)) - (A_UINT32)pLMHWCALRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_HWCALTIME, (A_UINT32)(((A_UINT32)&(pLMHWCALRSPParms->hwCalTime)) - (A_UINT32)pLMHWCALRSPParms), pParmsOffset);
    return((void*) pLMHWCALRSPParms);
}

static LMHWCALRSP_OP_FUNC LMHWCALRSPOpFunc = NULL;

TLV2_API void registerLMHWCALRSPHandler(LMHWCALRSP_OP_FUNC fp)
{
    LMHWCALRSPOpFunc = fp;
}

A_BOOL LMHWCALRSPOp(void *pParms)
{
    CMD_LMHWCALRSP_PARMS *pLMHWCALRSPParms = (CMD_LMHWCALRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMHWCALRSPOp: phyId %u\n", pLMHWCALRSPParms->phyId);
    A_PRINTF("LMHWCALRSPOp: status %u\n", pLMHWCALRSPParms->status);
    A_PRINTF("LMHWCALRSPOp: hwCalTime %u\n", pLMHWCALRSPParms->hwCalTime);
#endif //_DEBUG

    if (NULL != LMHWCALRSPOpFunc) {
        (*LMHWCALRSPOpFunc)(pLMHWCALRSPParms);
    }
    return(TRUE);
}
