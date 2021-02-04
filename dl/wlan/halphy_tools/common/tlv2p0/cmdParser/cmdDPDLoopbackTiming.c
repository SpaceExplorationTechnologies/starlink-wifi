// This is an auto-generated file from input\cmdDPDLoopbackTiming.s
#include "tlv2Inc.h"
#include "cmdDPDLoopbackTiming.h"

void* initDPDLOOPBACKTIMINGOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_DPDLOOPBACKTIMING_PARMS  *pDPDLOOPBACKTIMINGParms = (CMD_DPDLOOPBACKTIMING_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pDPDLOOPBACKTIMINGParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pDPDLOOPBACKTIMINGParms->DPDTimingIdx = pParmDict[PARM_DPDTIMINGIDX].v.valU8;
    pDPDLOOPBACKTIMINGParms->DPDLoopbackAttn = pParmDict[PARM_DPDLOOPBACKATTN].v.valS8;
    pDPDLOOPBACKTIMINGParms->glutIdx = pParmDict[PARM_GLUTIDX].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKTIMINGParms->phyId)) - (A_UINT32)pDPDLOOPBACKTIMINGParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DPDTIMINGIDX, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKTIMINGParms->DPDTimingIdx)) - (A_UINT32)pDPDLOOPBACKTIMINGParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DPDLOOPBACKATTN, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKTIMINGParms->DPDLoopbackAttn)) - (A_UINT32)pDPDLOOPBACKTIMINGParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GLUTIDX, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKTIMINGParms->glutIdx)) - (A_UINT32)pDPDLOOPBACKTIMINGParms), pParmsOffset);
    return((void*) pDPDLOOPBACKTIMINGParms);
}

static DPDLOOPBACKTIMING_OP_FUNC DPDLOOPBACKTIMINGOpFunc = NULL;

TLV2_API void registerDPDLOOPBACKTIMINGHandler(DPDLOOPBACKTIMING_OP_FUNC fp)
{
    DPDLOOPBACKTIMINGOpFunc = fp;
}

A_BOOL DPDLOOPBACKTIMINGOp(void *pParms)
{
    CMD_DPDLOOPBACKTIMING_PARMS *pDPDLOOPBACKTIMINGParms = (CMD_DPDLOOPBACKTIMING_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("DPDLOOPBACKTIMINGOp: phyId %u\n", pDPDLOOPBACKTIMINGParms->phyId);
    A_PRINTF("DPDLOOPBACKTIMINGOp: DPDTimingIdx %u\n", pDPDLOOPBACKTIMINGParms->DPDTimingIdx);
    A_PRINTF("DPDLOOPBACKTIMINGOp: DPDLoopbackAttn %d\n", pDPDLOOPBACKTIMINGParms->DPDLoopbackAttn);
    A_PRINTF("DPDLOOPBACKTIMINGOp: glutIdx %u\n", pDPDLOOPBACKTIMINGParms->glutIdx);
#endif //_DEBUG

    if (NULL != DPDLOOPBACKTIMINGOpFunc) {
        (*DPDLOOPBACKTIMINGOpFunc)(pDPDLOOPBACKTIMINGParms);
    }
    return(TRUE);
}

void* initDPDLOOPBACKTIMINGRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_DPDLOOPBACKTIMINGRSP_PARMS  *pDPDLOOPBACKTIMINGRSPParms = (CMD_DPDLOOPBACKTIMINGRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pDPDLOOPBACKTIMINGRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pDPDLOOPBACKTIMINGRSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKTIMINGRSPParms->phyId)) - (A_UINT32)pDPDLOOPBACKTIMINGRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKTIMINGRSPParms->status)) - (A_UINT32)pDPDLOOPBACKTIMINGRSPParms), pParmsOffset);
    return((void*) pDPDLOOPBACKTIMINGRSPParms);
}

static DPDLOOPBACKTIMINGRSP_OP_FUNC DPDLOOPBACKTIMINGRSPOpFunc = NULL;

TLV2_API void registerDPDLOOPBACKTIMINGRSPHandler(DPDLOOPBACKTIMINGRSP_OP_FUNC fp)
{
    DPDLOOPBACKTIMINGRSPOpFunc = fp;
}

A_BOOL DPDLOOPBACKTIMINGRSPOp(void *pParms)
{
    CMD_DPDLOOPBACKTIMINGRSP_PARMS *pDPDLOOPBACKTIMINGRSPParms = (CMD_DPDLOOPBACKTIMINGRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("DPDLOOPBACKTIMINGRSPOp: phyId %u\n", pDPDLOOPBACKTIMINGRSPParms->phyId);
    A_PRINTF("DPDLOOPBACKTIMINGRSPOp: status %u\n", pDPDLOOPBACKTIMINGRSPParms->status);
#endif //_DEBUG

    if (NULL != DPDLOOPBACKTIMINGRSPOpFunc) {
        (*DPDLOOPBACKTIMINGRSPOpFunc)(pDPDLOOPBACKTIMINGRSPParms);
    }
    return(TRUE);
}
