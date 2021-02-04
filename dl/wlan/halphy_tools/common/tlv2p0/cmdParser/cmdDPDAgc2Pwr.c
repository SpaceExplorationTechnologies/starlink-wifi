// This is an auto-generated file from input\cmdDPDAgc2Pwr.s
#include "tlv2Inc.h"
#include "cmdDPDAgc2Pwr.h"

void* initDPDAGC2PWROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_DPDAGC2PWR_PARMS  *pDPDAGC2PWRParms = (CMD_DPDAGC2PWR_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pDPDAGC2PWRParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pDPDAGC2PWRParms->phyId)) - (A_UINT32)pDPDAGC2PWRParms), pParmsOffset);
    return((void*) pDPDAGC2PWRParms);
}

static DPDAGC2PWR_OP_FUNC DPDAGC2PWROpFunc = NULL;

TLV2_API void registerDPDAGC2PWRHandler(DPDAGC2PWR_OP_FUNC fp)
{
    DPDAGC2PWROpFunc = fp;
}

A_BOOL DPDAGC2PWROp(void *pParms)
{
    CMD_DPDAGC2PWR_PARMS *pDPDAGC2PWRParms = (CMD_DPDAGC2PWR_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("DPDAGC2PWROp: phyId %u\n", pDPDAGC2PWRParms->phyId);
#endif //_DEBUG

    if (NULL != DPDAGC2PWROpFunc) {
        (*DPDAGC2PWROpFunc)(pDPDAGC2PWRParms);
    }
    return(TRUE);
}

void* initDPDAGC2PWRRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_DPDAGC2PWRRSP_PARMS  *pDPDAGC2PWRRSPParms = (CMD_DPDAGC2PWRRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pDPDAGC2PWRRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pDPDAGC2PWRRSPParms->DPDAgc2Pwr = pParmDict[PARM_DPDAGC2PWR].v.valS8;
    pDPDAGC2PWRRSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pDPDAGC2PWRRSPParms->phyId)) - (A_UINT32)pDPDAGC2PWRRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DPDAGC2PWR, (A_UINT32)(((A_UINT32)&(pDPDAGC2PWRRSPParms->DPDAgc2Pwr)) - (A_UINT32)pDPDAGC2PWRRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pDPDAGC2PWRRSPParms->status)) - (A_UINT32)pDPDAGC2PWRRSPParms), pParmsOffset);
    return((void*) pDPDAGC2PWRRSPParms);
}

static DPDAGC2PWRRSP_OP_FUNC DPDAGC2PWRRSPOpFunc = NULL;

TLV2_API void registerDPDAGC2PWRRSPHandler(DPDAGC2PWRRSP_OP_FUNC fp)
{
    DPDAGC2PWRRSPOpFunc = fp;
}

A_BOOL DPDAGC2PWRRSPOp(void *pParms)
{
    CMD_DPDAGC2PWRRSP_PARMS *pDPDAGC2PWRRSPParms = (CMD_DPDAGC2PWRRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("DPDAGC2PWRRSPOp: phyId %u\n", pDPDAGC2PWRRSPParms->phyId);
    A_PRINTF("DPDAGC2PWRRSPOp: DPDAgc2Pwr %d\n", pDPDAGC2PWRRSPParms->DPDAgc2Pwr);
    A_PRINTF("DPDAGC2PWRRSPOp: status %u\n", pDPDAGC2PWRRSPParms->status);
#endif //_DEBUG

    if (NULL != DPDAGC2PWRRSPOpFunc) {
        (*DPDAGC2PWRRSPOpFunc)(pDPDAGC2PWRRSPParms);
    }
    return(TRUE);
}
