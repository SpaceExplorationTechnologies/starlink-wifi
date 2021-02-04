// This is an auto-generated file from input/cmdSetPCIEConfigParam.s
#include "tlv2Inc.h"
#include "cmdSetPCIEConfigParam.h"

void* initSETPCIECONFIGPARAMSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_SETPCIECONFIGPARAMS_PARMS  *pSETPCIECONFIGPARAMSParms = (CMD_SETPCIECONFIGPARAMS_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pSETPCIECONFIGPARAMSParms->pcieAddr = pParmDict[PARM_PCIEADDR].v.valU32;
    pSETPCIECONFIGPARAMSParms->pcieValue = pParmDict[PARM_PCIEVALUE].v.valU32;
    pSETPCIECONFIGPARAMSParms->operation = pParmDict[PARM_OPERATION].v.valU8;
    pSETPCIECONFIGPARAMSParms->size = pParmDict[PARM_SIZE].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PCIEADDR, (A_UINT32)(((A_UINT32)&(pSETPCIECONFIGPARAMSParms->pcieAddr)) - (A_UINT32)pSETPCIECONFIGPARAMSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PCIEVALUE, (A_UINT32)(((A_UINT32)&(pSETPCIECONFIGPARAMSParms->pcieValue)) - (A_UINT32)pSETPCIECONFIGPARAMSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OPERATION, (A_UINT32)(((A_UINT32)&(pSETPCIECONFIGPARAMSParms->operation)) - (A_UINT32)pSETPCIECONFIGPARAMSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SIZE, (A_UINT32)(((A_UINT32)&(pSETPCIECONFIGPARAMSParms->size)) - (A_UINT32)pSETPCIECONFIGPARAMSParms), pParmsOffset);
    return((void*) pSETPCIECONFIGPARAMSParms);
}

static SETPCIECONFIGPARAMS_OP_FUNC SETPCIECONFIGPARAMSOpFunc = NULL;

TLV2_API void registerSETPCIECONFIGPARAMSHandler(SETPCIECONFIGPARAMS_OP_FUNC fp)
{
    SETPCIECONFIGPARAMSOpFunc = fp;
}

A_BOOL SETPCIECONFIGPARAMSOp(void *pParms)
{
    CMD_SETPCIECONFIGPARAMS_PARMS *pSETPCIECONFIGPARAMSParms = (CMD_SETPCIECONFIGPARAMS_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("SETPCIECONFIGPARAMSOp: pcieAddr %u\n", pSETPCIECONFIGPARAMSParms->pcieAddr);
    A_PRINTF("SETPCIECONFIGPARAMSOp: pcieValue %u\n", pSETPCIECONFIGPARAMSParms->pcieValue);
    A_PRINTF("SETPCIECONFIGPARAMSOp: operation %u\n", pSETPCIECONFIGPARAMSParms->operation);
    A_PRINTF("SETPCIECONFIGPARAMSOp: size %u\n", pSETPCIECONFIGPARAMSParms->size);
#endif //_DEBUG

    if (NULL != SETPCIECONFIGPARAMSOpFunc) {
        (*SETPCIECONFIGPARAMSOpFunc)(pSETPCIECONFIGPARAMSParms);
    }
    return(TRUE);
}

void* initSETPCIECONFIGPARAMSRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    return(NULL);
}

static SETPCIECONFIGPARAMSRSP_OP_FUNC SETPCIECONFIGPARAMSRSPOpFunc = NULL;

TLV2_API void registerSETPCIECONFIGPARAMSRSPHandler(SETPCIECONFIGPARAMSRSP_OP_FUNC fp)
{
    SETPCIECONFIGPARAMSRSPOpFunc = fp;
}

A_BOOL SETPCIECONFIGPARAMSRSPOp(void *pParms)
{
    if (NULL != SETPCIECONFIGPARAMSRSPOpFunc) {
        (*SETPCIECONFIGPARAMSRSPOpFunc)(NULL);
    }
    return(TRUE);
}
