// This is an auto-generated file from input\cmdXtalCalHandler.s
#include "tlv2Inc.h"
#include "cmdXtalCalHandler.h"

void* initXTALCALPROCOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_XTALCALPROC_PARMS  *pXTALCALPROCParms = (CMD_XTALCALPROC_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pXTALCALPROCParms->capIn = pParmDict[PARM_CAPIN].v.valU8;
    pXTALCALPROCParms->capOut = pParmDict[PARM_CAPOUT].v.valU8;
    pXTALCALPROCParms->ctrlFlag = pParmDict[PARM_CTRLFLAG].v.valU8;
    pXTALCALPROCParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_CAPIN, (A_UINT32)(((A_UINT32)&(pXTALCALPROCParms->capIn)) - (A_UINT32)pXTALCALPROCParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CAPOUT, (A_UINT32)(((A_UINT32)&(pXTALCALPROCParms->capOut)) - (A_UINT32)pXTALCALPROCParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CTRLFLAG, (A_UINT32)(((A_UINT32)&(pXTALCALPROCParms->ctrlFlag)) - (A_UINT32)pXTALCALPROCParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pXTALCALPROCParms->phyId)) - (A_UINT32)pXTALCALPROCParms), pParmsOffset);
    return((void*) pXTALCALPROCParms);
}

static XTALCALPROC_OP_FUNC XTALCALPROCOpFunc = NULL;

TLV2_API void registerXTALCALPROCHandler(XTALCALPROC_OP_FUNC fp)
{
    XTALCALPROCOpFunc = fp;
}

A_BOOL XTALCALPROCOp(void *pParms)
{
    CMD_XTALCALPROC_PARMS *pXTALCALPROCParms = (CMD_XTALCALPROC_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("XTALCALPROCOp: capIn %u\n", pXTALCALPROCParms->capIn);
    A_PRINTF("XTALCALPROCOp: capOut %u\n", pXTALCALPROCParms->capOut);
    A_PRINTF("XTALCALPROCOp: ctrlFlag %u\n", pXTALCALPROCParms->ctrlFlag);
    A_PRINTF("XTALCALPROCOp: phyId %u\n", pXTALCALPROCParms->phyId);
#endif //_DEBUG

    if (NULL != XTALCALPROCOpFunc) {
        (*XTALCALPROCOpFunc)(pXTALCALPROCParms);
    }
    return(TRUE);
}

void* initXTALCALPROCRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_XTALCALPROCRSP_PARMS  *pXTALCALPROCRSPParms = (CMD_XTALCALPROCRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pXTALCALPROCRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pXTALCALPROCRSPParms->capValMin = pParmDict[PARM_CAPVALMIN].v.valU8;
    pXTALCALPROCRSPParms->capValMax = pParmDict[PARM_CAPVALMAX].v.valU8;
    pXTALCALPROCRSPParms->capIn = pParmDict[PARM_CAPIN].v.valU8;
    pXTALCALPROCRSPParms->capOut = pParmDict[PARM_CAPOUT].v.valU8;
    pXTALCALPROCRSPParms->pllLocked = pParmDict[PARM_PLLLOCKED].v.valU8;
    pXTALCALPROCRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pXTALCALPROCRSPParms->status)) - (A_UINT32)pXTALCALPROCRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CAPVALMIN, (A_UINT32)(((A_UINT32)&(pXTALCALPROCRSPParms->capValMin)) - (A_UINT32)pXTALCALPROCRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CAPVALMAX, (A_UINT32)(((A_UINT32)&(pXTALCALPROCRSPParms->capValMax)) - (A_UINT32)pXTALCALPROCRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CAPIN, (A_UINT32)(((A_UINT32)&(pXTALCALPROCRSPParms->capIn)) - (A_UINT32)pXTALCALPROCRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CAPOUT, (A_UINT32)(((A_UINT32)&(pXTALCALPROCRSPParms->capOut)) - (A_UINT32)pXTALCALPROCRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PLLLOCKED, (A_UINT32)(((A_UINT32)&(pXTALCALPROCRSPParms->pllLocked)) - (A_UINT32)pXTALCALPROCRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pXTALCALPROCRSPParms->phyId)) - (A_UINT32)pXTALCALPROCRSPParms), pParmsOffset);
    return((void*) pXTALCALPROCRSPParms);
}

static XTALCALPROCRSP_OP_FUNC XTALCALPROCRSPOpFunc = NULL;

TLV2_API void registerXTALCALPROCRSPHandler(XTALCALPROCRSP_OP_FUNC fp)
{
    XTALCALPROCRSPOpFunc = fp;
}

A_BOOL XTALCALPROCRSPOp(void *pParms)
{
    CMD_XTALCALPROCRSP_PARMS *pXTALCALPROCRSPParms = (CMD_XTALCALPROCRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("XTALCALPROCRSPOp: status %u\n", pXTALCALPROCRSPParms->status);
    A_PRINTF("XTALCALPROCRSPOp: capValMin %u\n", pXTALCALPROCRSPParms->capValMin);
    A_PRINTF("XTALCALPROCRSPOp: capValMax %u\n", pXTALCALPROCRSPParms->capValMax);
    A_PRINTF("XTALCALPROCRSPOp: capIn %u\n", pXTALCALPROCRSPParms->capIn);
    A_PRINTF("XTALCALPROCRSPOp: capOut %u\n", pXTALCALPROCRSPParms->capOut);
    A_PRINTF("XTALCALPROCRSPOp: pllLocked %u\n", pXTALCALPROCRSPParms->pllLocked);
    A_PRINTF("XTALCALPROCRSPOp: phyId %u\n", pXTALCALPROCRSPParms->phyId);
#endif //_DEBUG

    if (NULL != XTALCALPROCRSPOpFunc) {
        (*XTALCALPROCRSPOpFunc)(pXTALCALPROCRSPParms);
    }
    return(TRUE);
}
