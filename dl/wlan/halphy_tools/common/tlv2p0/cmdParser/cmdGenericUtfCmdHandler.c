// This is an auto-generated file from input/cmdGenericUtfCmdHandler.s
#include "tlv2Inc.h"
#include "cmdGenericUtfCmdHandler.h"

void* initGENERICUTFCMDOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_GENERICUTFCMD_PARMS  *pGENERICUTFCMDParms = (CMD_GENERICUTFCMD_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pGENERICUTFCMDParms->Measurement = pParmDict[PARM_MEASUREMENT].v.valU32;
    memset(pGENERICUTFCMDParms->inParams, 0, sizeof(pGENERICUTFCMDParms->inParams));
    pGENERICUTFCMDParms->GenericUtfCmdID = pParmDict[PARM_GENERICUTFCMDID].v.valU16;
    pGENERICUTFCMDParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_MEASUREMENT, (A_UINT32)(((A_UINT32)&(pGENERICUTFCMDParms->Measurement)) - (A_UINT32)pGENERICUTFCMDParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_INPARAMS, (A_UINT32)(((A_UINT32)&(pGENERICUTFCMDParms->inParams)) - (A_UINT32)pGENERICUTFCMDParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GENERICUTFCMDID, (A_UINT32)(((A_UINT32)&(pGENERICUTFCMDParms->GenericUtfCmdID)) - (A_UINT32)pGENERICUTFCMDParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pGENERICUTFCMDParms->phyId)) - (A_UINT32)pGENERICUTFCMDParms), pParmsOffset);
    return((void*) pGENERICUTFCMDParms);
}

static GENERICUTFCMD_OP_FUNC GENERICUTFCMDOpFunc = NULL;

TLV2_API void registerGENERICUTFCMDHandler(GENERICUTFCMD_OP_FUNC fp)
{
    GENERICUTFCMDOpFunc = fp;
}

A_BOOL GENERICUTFCMDOp(void *pParms)
{
    CMD_GENERICUTFCMD_PARMS *pGENERICUTFCMDParms = (CMD_GENERICUTFCMD_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("GENERICUTFCMDOp: Measurement %u\n", pGENERICUTFCMDParms->Measurement);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 32 entries
    {
        A_PRINTF("GENERICUTFCMDOp: inParams %d\n", pGENERICUTFCMDParms->inParams[i]);
    }
    A_PRINTF("GENERICUTFCMDOp: GenericUtfCmdID %u\n", pGENERICUTFCMDParms->GenericUtfCmdID);
    A_PRINTF("GENERICUTFCMDOp: phyId %u\n", pGENERICUTFCMDParms->phyId);
#endif //_DEBUG

    if (NULL != GENERICUTFCMDOpFunc) {
        (*GENERICUTFCMDOpFunc)(pGENERICUTFCMDParms);
    }
    return(TRUE);
}

void* initGENERICUTFCMDRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_GENERICUTFCMDRSP_PARMS  *pGENERICUTFCMDRSPParms = (CMD_GENERICUTFCMDRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pGENERICUTFCMDRSPParms->GenericUtfCmdDone = pParmDict[PARM_GENERICUTFCMDDONE].v.valU8;
    pGENERICUTFCMDRSPParms->NumGenericUtfCmdRetData = pParmDict[PARM_NUMGENERICUTFCMDRETDATA].v.valU8;
    pGENERICUTFCMDRSPParms->GenericUtfCmdStatus = pParmDict[PARM_GENERICUTFCMDSTATUS].v.valU16;
    memset(pGENERICUTFCMDRSPParms->GenericUtfCmdRetData, 0, sizeof(pGENERICUTFCMDRSPParms->GenericUtfCmdRetData));
    pGENERICUTFCMDRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_GENERICUTFCMDDONE, (A_UINT32)(((A_UINT32)&(pGENERICUTFCMDRSPParms->GenericUtfCmdDone)) - (A_UINT32)pGENERICUTFCMDRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMGENERICUTFCMDRETDATA, (A_UINT32)(((A_UINT32)&(pGENERICUTFCMDRSPParms->NumGenericUtfCmdRetData)) - (A_UINT32)pGENERICUTFCMDRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GENERICUTFCMDSTATUS, (A_UINT32)(((A_UINT32)&(pGENERICUTFCMDRSPParms->GenericUtfCmdStatus)) - (A_UINT32)pGENERICUTFCMDRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GENERICUTFCMDRETDATA, (A_UINT32)(((A_UINT32)&(pGENERICUTFCMDRSPParms->GenericUtfCmdRetData)) - (A_UINT32)pGENERICUTFCMDRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pGENERICUTFCMDRSPParms->phyId)) - (A_UINT32)pGENERICUTFCMDRSPParms), pParmsOffset);
    return((void*) pGENERICUTFCMDRSPParms);
}

static GENERICUTFCMDRSP_OP_FUNC GENERICUTFCMDRSPOpFunc = NULL;

TLV2_API void registerGENERICUTFCMDRSPHandler(GENERICUTFCMDRSP_OP_FUNC fp)
{
    GENERICUTFCMDRSPOpFunc = fp;
}

A_BOOL GENERICUTFCMDRSPOp(void *pParms)
{
    CMD_GENERICUTFCMDRSP_PARMS *pGENERICUTFCMDRSPParms = (CMD_GENERICUTFCMDRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("GENERICUTFCMDRSPOp: GenericUtfCmdDone %u\n", pGENERICUTFCMDRSPParms->GenericUtfCmdDone);
    A_PRINTF("GENERICUTFCMDRSPOp: NumGenericUtfCmdRetData %u\n", pGENERICUTFCMDRSPParms->NumGenericUtfCmdRetData);
    A_PRINTF("GENERICUTFCMDRSPOp: GenericUtfCmdStatus %u\n", pGENERICUTFCMDRSPParms->GenericUtfCmdStatus);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 32 entries
    {
        A_PRINTF("GENERICUTFCMDRSPOp: GenericUtfCmdRetData %d\n", pGENERICUTFCMDRSPParms->GenericUtfCmdRetData[i]);
    }
    A_PRINTF("GENERICUTFCMDRSPOp: phyId %u\n", pGENERICUTFCMDRSPParms->phyId);
#endif //_DEBUG

    if (NULL != GENERICUTFCMDRSPOpFunc) {
        (*GENERICUTFCMDRSPOpFunc)(pGENERICUTFCMDRSPParms);
    }
    return(TRUE);
}
