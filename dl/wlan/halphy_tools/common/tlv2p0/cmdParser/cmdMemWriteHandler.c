// This is an auto-generated file from input/cmdMemWriteHandler.s
#include "tlv2Inc.h"
#include "cmdMemWriteHandler.h"

void* initMEMWRITEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_MEMWRITE_PARMS  *pMEMWRITEParms = (CMD_MEMWRITE_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pMEMWRITEParms->memaddress = pParmDict[PARM_MEMADDRESS].v.valU32;
    pMEMWRITEParms->numbytes = pParmDict[PARM_NUMBYTES].v.valU8;
    memset(pMEMWRITEParms->memvalue, 0, sizeof(pMEMWRITEParms->memvalue));
    pMEMWRITEParms->valuetype = pParmDict[PARM_VALUETYPE].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_MEMADDRESS, (A_UINT32)(((A_UINT32)&(pMEMWRITEParms->memaddress)) - (A_UINT32)pMEMWRITEParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMBYTES, (A_UINT32)(((A_UINT32)&(pMEMWRITEParms->numbytes)) - (A_UINT32)pMEMWRITEParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_MEMVALUE, (A_UINT32)(((A_UINT32)&(pMEMWRITEParms->memvalue)) - (A_UINT32)pMEMWRITEParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_VALUETYPE, (A_UINT32)(((A_UINT32)&(pMEMWRITEParms->valuetype)) - (A_UINT32)pMEMWRITEParms), pParmsOffset);
    return((void*) pMEMWRITEParms);
}

static MEMWRITE_OP_FUNC MEMWRITEOpFunc = NULL;

TLV2_API void registerMEMWRITEHandler(MEMWRITE_OP_FUNC fp)
{
    MEMWRITEOpFunc = fp;
}

A_BOOL MEMWRITEOp(void *pParms)
{
    CMD_MEMWRITE_PARMS *pMEMWRITEParms = (CMD_MEMWRITE_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("MEMWRITEOp: memaddress 0x%x\n", pMEMWRITEParms->memaddress);
    A_PRINTF("MEMWRITEOp: numbytes %u\n", pMEMWRITEParms->numbytes);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 255 entries
    {
        A_PRINTF("MEMWRITEOp: memvalue 0x%x\n", pMEMWRITEParms->memvalue[i]);
    }
    A_PRINTF("MEMWRITEOp: valuetype %u\n", pMEMWRITEParms->valuetype);
#endif //_DEBUG

    if (NULL != MEMWRITEOpFunc) {
        (*MEMWRITEOpFunc)(pMEMWRITEParms);
    }
    return(TRUE);
}

void* initMEMWRITERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_MEMWRITERSP_PARMS  *pMEMWRITERSPParms = (CMD_MEMWRITERSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pMEMWRITERSPParms->memaddress = pParmDict[PARM_MEMADDRESS].v.valU32;
    pMEMWRITERSPParms->numbytes = pParmDict[PARM_NUMBYTES].v.valU8;
    pMEMWRITERSPParms->valuetype = pParmDict[PARM_VALUETYPE].v.valU8;
    pMEMWRITERSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_MEMADDRESS, (A_UINT32)(((A_UINT32)&(pMEMWRITERSPParms->memaddress)) - (A_UINT32)pMEMWRITERSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMBYTES, (A_UINT32)(((A_UINT32)&(pMEMWRITERSPParms->numbytes)) - (A_UINT32)pMEMWRITERSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_VALUETYPE, (A_UINT32)(((A_UINT32)&(pMEMWRITERSPParms->valuetype)) - (A_UINT32)pMEMWRITERSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pMEMWRITERSPParms->status)) - (A_UINT32)pMEMWRITERSPParms), pParmsOffset);
    return((void*) pMEMWRITERSPParms);
}

static MEMWRITERSP_OP_FUNC MEMWRITERSPOpFunc = NULL;

TLV2_API void registerMEMWRITERSPHandler(MEMWRITERSP_OP_FUNC fp)
{
    MEMWRITERSPOpFunc = fp;
}

A_BOOL MEMWRITERSPOp(void *pParms)
{
    CMD_MEMWRITERSP_PARMS *pMEMWRITERSPParms = (CMD_MEMWRITERSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("MEMWRITERSPOp: memaddress 0x%x\n", pMEMWRITERSPParms->memaddress);
    A_PRINTF("MEMWRITERSPOp: numbytes %u\n", pMEMWRITERSPParms->numbytes);
    A_PRINTF("MEMWRITERSPOp: valuetype %u\n", pMEMWRITERSPParms->valuetype);
    A_PRINTF("MEMWRITERSPOp: status %u\n", pMEMWRITERSPParms->status);
#endif //_DEBUG

    if (NULL != MEMWRITERSPOpFunc) {
        (*MEMWRITERSPOpFunc)(pMEMWRITERSPParms);
    }
    return(TRUE);
}
