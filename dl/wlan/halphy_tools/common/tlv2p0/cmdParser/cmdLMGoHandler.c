// This is an auto-generated file from input\cmdLMGoHandler.s
#include "tlv2Inc.h"
#include "cmdLMGoHandler.h"

void* initLMGOOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_LMGO_PARMS  *pLMGOParms = (CMD_LMGO_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pLMGOParms->lm_cmdId = pParmDict[PARM_LM_CMDID].v.valU8;
    memset(pLMGOParms->pad3, 0, sizeof(pLMGOParms->pad3));
    pLMGOParms->timeOn = pParmDict[PARM_TIMEON].v.valU16;
    pLMGOParms->timeOff = pParmDict[PARM_TIMEOFF].v.valU16;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_LM_CMDID, (A_UINT32)(((A_UINT32)&(pLMGOParms->lm_cmdId)) - (A_UINT32)pLMGOParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD3, (A_UINT32)(((A_UINT32)&(pLMGOParms->pad3)) - (A_UINT32)pLMGOParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TIMEON, (A_UINT32)(((A_UINT32)&(pLMGOParms->timeOn)) - (A_UINT32)pLMGOParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TIMEOFF, (A_UINT32)(((A_UINT32)&(pLMGOParms->timeOff)) - (A_UINT32)pLMGOParms), pParmsOffset);
    return((void*) pLMGOParms);
}

static LMGO_OP_FUNC LMGOOpFunc = NULL;

TLV2_API void registerLMGOHandler(LMGO_OP_FUNC fp)
{
    LMGOOpFunc = fp;
}

A_BOOL LMGOOp(void *pParms)
{
    CMD_LMGO_PARMS *pLMGOParms = (CMD_LMGO_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMGOOp: lm_cmdId %u\n", pLMGOParms->lm_cmdId);
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("LMGOOp: pad3 %u\n", pLMGOParms->pad3[i]);
    }
    A_PRINTF("LMGOOp: timeOn %u\n", pLMGOParms->timeOn);
    A_PRINTF("LMGOOp: timeOff %u\n", pLMGOParms->timeOff);
#endif //_DEBUG

    if (NULL != LMGOOpFunc) {
        (*LMGOOpFunc)(pLMGOParms);
    }
    return(TRUE);
}

void* initLMGORSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_LMGORSP_PARMS  *pLMGORSPParms = (CMD_LMGORSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pLMGORSPParms->lm_cmdId = pParmDict[PARM_LM_CMDID].v.valU8;
    pLMGORSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    memset(pLMGORSPParms->pad2, 0, sizeof(pLMGORSPParms->pad2));
    pLMGORSPParms->timeOn = pParmDict[PARM_TIMEON].v.valU16;
    pLMGORSPParms->timeOff = pParmDict[PARM_TIMEOFF].v.valU16;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_LM_CMDID, (A_UINT32)(((A_UINT32)&(pLMGORSPParms->lm_cmdId)) - (A_UINT32)pLMGORSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pLMGORSPParms->status)) - (A_UINT32)pLMGORSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD2, (A_UINT32)(((A_UINT32)&(pLMGORSPParms->pad2)) - (A_UINT32)pLMGORSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TIMEON, (A_UINT32)(((A_UINT32)&(pLMGORSPParms->timeOn)) - (A_UINT32)pLMGORSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TIMEOFF, (A_UINT32)(((A_UINT32)&(pLMGORSPParms->timeOff)) - (A_UINT32)pLMGORSPParms), pParmsOffset);
    return((void*) pLMGORSPParms);
}

static LMGORSP_OP_FUNC LMGORSPOpFunc = NULL;

TLV2_API void registerLMGORSPHandler(LMGORSP_OP_FUNC fp)
{
    LMGORSPOpFunc = fp;
}

A_BOOL LMGORSPOp(void *pParms)
{
    CMD_LMGORSP_PARMS *pLMGORSPParms = (CMD_LMGORSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMGORSPOp: lm_cmdId %u\n", pLMGORSPParms->lm_cmdId);
    A_PRINTF("LMGORSPOp: status %u\n", pLMGORSPParms->status);
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("LMGORSPOp: pad2 %u\n", pLMGORSPParms->pad2[i]);
    }
    A_PRINTF("LMGORSPOp: timeOn %u\n", pLMGORSPParms->timeOn);
    A_PRINTF("LMGORSPOp: timeOff %u\n", pLMGORSPParms->timeOff);
#endif //_DEBUG

    if (NULL != LMGORSPOpFunc) {
        (*LMGORSPOpFunc)(pLMGORSPParms);
    }
    return(TRUE);
}
