// This is an auto-generated file from input\cmdDPDLoopbackAttn.s
#include "tlv2Inc.h"
#include "cmdDPDLoopbackAttn.h"

void* initDPDLOOPBACKATTNOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_DPDLOOPBACKATTN_PARMS  *pDPDLOOPBACKATTNParms = (CMD_DPDLOOPBACKATTN_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pDPDLOOPBACKATTNParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pDPDLOOPBACKATTNParms->DPDLoopbackAttn = pParmDict[PARM_DPDLOOPBACKATTN].v.valS8;
    pDPDLOOPBACKATTNParms->glutIdx = pParmDict[PARM_GLUTIDX].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKATTNParms->phyId)) - (A_UINT32)pDPDLOOPBACKATTNParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DPDLOOPBACKATTN, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKATTNParms->DPDLoopbackAttn)) - (A_UINT32)pDPDLOOPBACKATTNParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GLUTIDX, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKATTNParms->glutIdx)) - (A_UINT32)pDPDLOOPBACKATTNParms), pParmsOffset);
    return((void*) pDPDLOOPBACKATTNParms);
}

static DPDLOOPBACKATTN_OP_FUNC DPDLOOPBACKATTNOpFunc = NULL;

TLV2_API void registerDPDLOOPBACKATTNHandler(DPDLOOPBACKATTN_OP_FUNC fp)
{
    DPDLOOPBACKATTNOpFunc = fp;
}

A_BOOL DPDLOOPBACKATTNOp(void *pParms)
{
    CMD_DPDLOOPBACKATTN_PARMS *pDPDLOOPBACKATTNParms = (CMD_DPDLOOPBACKATTN_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("DPDLOOPBACKATTNOp: phyId %u\n", pDPDLOOPBACKATTNParms->phyId);
    A_PRINTF("DPDLOOPBACKATTNOp: DPDLoopbackAttn %d\n", pDPDLOOPBACKATTNParms->DPDLoopbackAttn);
    A_PRINTF("DPDLOOPBACKATTNOp: glutIdx %u\n", pDPDLOOPBACKATTNParms->glutIdx);
#endif //_DEBUG

    if (NULL != DPDLOOPBACKATTNOpFunc) {
        (*DPDLOOPBACKATTNOpFunc)(pDPDLOOPBACKATTNParms);
    }
    return(TRUE);
}

void* initDPDLOOPBACKATTNRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_DPDLOOPBACKATTNRSP_PARMS  *pDPDLOOPBACKATTNRSPParms = (CMD_DPDLOOPBACKATTNRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pDPDLOOPBACKATTNRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pDPDLOOPBACKATTNRSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKATTNRSPParms->phyId)) - (A_UINT32)pDPDLOOPBACKATTNRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pDPDLOOPBACKATTNRSPParms->status)) - (A_UINT32)pDPDLOOPBACKATTNRSPParms), pParmsOffset);
    return((void*) pDPDLOOPBACKATTNRSPParms);
}

static DPDLOOPBACKATTNRSP_OP_FUNC DPDLOOPBACKATTNRSPOpFunc = NULL;

TLV2_API void registerDPDLOOPBACKATTNRSPHandler(DPDLOOPBACKATTNRSP_OP_FUNC fp)
{
    DPDLOOPBACKATTNRSPOpFunc = fp;
}

A_BOOL DPDLOOPBACKATTNRSPOp(void *pParms)
{
    CMD_DPDLOOPBACKATTNRSP_PARMS *pDPDLOOPBACKATTNRSPParms = (CMD_DPDLOOPBACKATTNRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("DPDLOOPBACKATTNRSPOp: phyId %u\n", pDPDLOOPBACKATTNRSPParms->phyId);
    A_PRINTF("DPDLOOPBACKATTNRSPOp: status %u\n", pDPDLOOPBACKATTNRSPParms->status);
#endif //_DEBUG

    if (NULL != DPDLOOPBACKATTNRSPOpFunc) {
        (*DPDLOOPBACKATTNRSPOpFunc)(pDPDLOOPBACKATTNRSPParms);
    }
    return(TRUE);
}
