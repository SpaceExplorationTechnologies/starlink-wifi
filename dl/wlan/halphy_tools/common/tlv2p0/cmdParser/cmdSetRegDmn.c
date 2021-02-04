// This is an auto-generated file from input/cmdSetRegDmn.s
#include "tlv2Inc.h"
#include "cmdSetRegDmn.h"

void* initSETREGDMNOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_SETREGDMN_PARMS  *pSETREGDMNParms = (CMD_SETREGDMN_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    for (i = 0; i < 2 ; i++)
    {
        pSETREGDMNParms->regDmn[i] = pParmDict[PARM_REGDMN].v.ptU16[i];
    }

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_REGDMN, (A_UINT32)(((A_UINT32)&(pSETREGDMNParms->regDmn)) - (A_UINT32)pSETREGDMNParms), pParmsOffset);
    return((void*) pSETREGDMNParms);
}

static SETREGDMN_OP_FUNC SETREGDMNOpFunc = NULL;

TLV2_API void registerSETREGDMNHandler(SETREGDMN_OP_FUNC fp)
{
    SETREGDMNOpFunc = fp;
}

A_BOOL SETREGDMNOp(void *pParms)
{
    CMD_SETREGDMN_PARMS *pSETREGDMNParms = (CMD_SETREGDMN_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("SETREGDMNOp: regDmn 0x%x\n", pSETREGDMNParms->regDmn[i]);
    }
#endif //_DEBUG

    if (NULL != SETREGDMNOpFunc) {
        (*SETREGDMNOpFunc)(pSETREGDMNParms);
    }
    return(TRUE);
}

void* initSETREGDMNRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    return(NULL);
}

static SETREGDMNRSP_OP_FUNC SETREGDMNRSPOpFunc = NULL;

TLV2_API void registerSETREGDMNRSPHandler(SETREGDMNRSP_OP_FUNC fp)
{
    SETREGDMNRSPOpFunc = fp;
}

A_BOOL SETREGDMNRSPOp(void *pParms)
{
    if (NULL != SETREGDMNRSPOpFunc) {
        (*SETREGDMNRSPOpFunc)(NULL);
    }
    return(TRUE);
}
