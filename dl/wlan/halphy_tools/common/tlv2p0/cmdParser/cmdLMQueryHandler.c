// This is an auto-generated file from input\cmdLMQueryHandler.s
#include "tlv2Inc.h"
#include "cmdLMQueryHandler.h"

void* initLMQUERYOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_LMQUERY_PARMS  *pLMQUERYParms = (CMD_LMQUERY_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pLMQUERYParms->lm_cmdId = pParmDict[PARM_LM_CMDID].v.valU8;
    memset(pLMQUERYParms->pad3, 0, sizeof(pLMQUERYParms->pad3));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_LM_CMDID, (A_UINT32)(((A_UINT32)&(pLMQUERYParms->lm_cmdId)) - (A_UINT32)pLMQUERYParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD3, (A_UINT32)(((A_UINT32)&(pLMQUERYParms->pad3)) - (A_UINT32)pLMQUERYParms), pParmsOffset);
    return((void*) pLMQUERYParms);
}

static LMQUERY_OP_FUNC LMQUERYOpFunc = NULL;

TLV2_API void registerLMQUERYHandler(LMQUERY_OP_FUNC fp)
{
    LMQUERYOpFunc = fp;
}

A_BOOL LMQUERYOp(void *pParms)
{
    CMD_LMQUERY_PARMS *pLMQUERYParms = (CMD_LMQUERY_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMQUERYOp: lm_cmdId %u\n", pLMQUERYParms->lm_cmdId);
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("LMQUERYOp: pad3 %u\n", pLMQUERYParms->pad3[i]);
    }
#endif //_DEBUG

    if (NULL != LMQUERYOpFunc) {
        (*LMQUERYOpFunc)(pLMQUERYParms);
    }
    return(TRUE);
}

void* initLMQUERYRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_LMQUERYRSP_PARMS  *pLMQUERYRSPParms = (CMD_LMQUERYRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pLMQUERYRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pLMQUERYRSPParms->lm_cmdId = pParmDict[PARM_LM_CMDID].v.valU8;
    memset(pLMQUERYRSPParms->pad2, 0, sizeof(pLMQUERYRSPParms->pad2));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pLMQUERYRSPParms->status)) - (A_UINT32)pLMQUERYRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_CMDID, (A_UINT32)(((A_UINT32)&(pLMQUERYRSPParms->lm_cmdId)) - (A_UINT32)pLMQUERYRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD2, (A_UINT32)(((A_UINT32)&(pLMQUERYRSPParms->pad2)) - (A_UINT32)pLMQUERYRSPParms), pParmsOffset);
    return((void*) pLMQUERYRSPParms);
}

static LMQUERYRSP_OP_FUNC LMQUERYRSPOpFunc = NULL;

TLV2_API void registerLMQUERYRSPHandler(LMQUERYRSP_OP_FUNC fp)
{
    LMQUERYRSPOpFunc = fp;
}

A_BOOL LMQUERYRSPOp(void *pParms)
{
    CMD_LMQUERYRSP_PARMS *pLMQUERYRSPParms = (CMD_LMQUERYRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMQUERYRSPOp: status %u\n", pLMQUERYRSPParms->status);
    A_PRINTF("LMQUERYRSPOp: lm_cmdId %u\n", pLMQUERYRSPParms->lm_cmdId);
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("LMQUERYRSPOp: pad2 %u\n", pLMQUERYRSPParms->pad2[i]);
    }
#endif //_DEBUG

    if (NULL != LMQUERYRSPOpFunc) {
        (*LMQUERYRSPOpFunc)(pLMQUERYRSPParms);
    }
    return(TRUE);
}
