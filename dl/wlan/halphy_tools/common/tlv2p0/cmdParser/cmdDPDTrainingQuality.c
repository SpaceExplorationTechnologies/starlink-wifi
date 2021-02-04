// This is an auto-generated file from input/cmdDPDTrainingQuality.s
#include "tlv2Inc.h"
#include "cmdDPDTrainingQuality.h"

void* initDPDTRAININGQUALITYOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_DPDTRAININGQUALITY_PARMS  *pDPDTRAININGQUALITYParms = (CMD_DPDTRAININGQUALITY_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pDPDTRAININGQUALITYParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pDPDTRAININGQUALITYParms->phyId)) - (A_UINT32)pDPDTRAININGQUALITYParms), pParmsOffset);
    return((void*) pDPDTRAININGQUALITYParms);
}

static DPDTRAININGQUALITY_OP_FUNC DPDTRAININGQUALITYOpFunc = NULL;

TLV2_API void registerDPDTRAININGQUALITYHandler(DPDTRAININGQUALITY_OP_FUNC fp)
{
    DPDTRAININGQUALITYOpFunc = fp;
}

A_BOOL DPDTRAININGQUALITYOp(void *pParms)
{
    CMD_DPDTRAININGQUALITY_PARMS *pDPDTRAININGQUALITYParms = (CMD_DPDTRAININGQUALITY_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("DPDTRAININGQUALITYOp: phyId %u\n", pDPDTRAININGQUALITYParms->phyId);
#endif //_DEBUG

    if (NULL != DPDTRAININGQUALITYOpFunc) {
        (*DPDTRAININGQUALITYOpFunc)(pDPDTRAININGQUALITYParms);
    }
    return(TRUE);
}

void* initDPDTRAININGQUALITYRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_DPDTRAININGQUALITYRSP_PARMS  *pDPDTRAININGQUALITYRSPParms = (CMD_DPDTRAININGQUALITYRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pDPDTRAININGQUALITYRSPParms->DPDTrainQual = pParmDict[PARM_DPDTRAINQUAL].v.valU16;
    pDPDTRAININGQUALITYRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pDPDTRAININGQUALITYRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_DPDTRAINQUAL, (A_UINT32)(((A_UINT32)&(pDPDTRAININGQUALITYRSPParms->DPDTrainQual)) - (A_UINT32)pDPDTRAININGQUALITYRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pDPDTRAININGQUALITYRSPParms->status)) - (A_UINT32)pDPDTRAININGQUALITYRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pDPDTRAININGQUALITYRSPParms->phyId)) - (A_UINT32)pDPDTRAININGQUALITYRSPParms), pParmsOffset);
    return((void*) pDPDTRAININGQUALITYRSPParms);
}

static DPDTRAININGQUALITYRSP_OP_FUNC DPDTRAININGQUALITYRSPOpFunc = NULL;

TLV2_API void registerDPDTRAININGQUALITYRSPHandler(DPDTRAININGQUALITYRSP_OP_FUNC fp)
{
    DPDTRAININGQUALITYRSPOpFunc = fp;
}

A_BOOL DPDTRAININGQUALITYRSPOp(void *pParms)
{
    CMD_DPDTRAININGQUALITYRSP_PARMS *pDPDTRAININGQUALITYRSPParms = (CMD_DPDTRAININGQUALITYRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("DPDTRAININGQUALITYRSPOp: DPDTrainQual %u\n", pDPDTRAININGQUALITYRSPParms->DPDTrainQual);
    A_PRINTF("DPDTRAININGQUALITYRSPOp: status %u\n", pDPDTRAININGQUALITYRSPParms->status);
    A_PRINTF("DPDTRAININGQUALITYRSPOp: phyId %u\n", pDPDTRAININGQUALITYRSPParms->phyId);
#endif //_DEBUG

    if (NULL != DPDTRAININGQUALITYRSPOpFunc) {
        (*DPDTRAININGQUALITYRSPOpFunc)(pDPDTRAININGQUALITYRSPParms);
    }
    return(TRUE);
}
