// This is an auto-generated file from input/cmdCustOtpSpaceWrite.s
#include "tlv2Inc.h"
#include "cmdCustOtpSpaceWrite.h"

void* initWRITECUSTOTPSPACEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_WRITECUSTOTPSPACE_PARMS  *pWRITECUSTOTPSPACEParms = (CMD_WRITECUSTOTPSPACE_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pWRITECUSTOTPSPACEParms->offsetAddr = pParmDict[PARM_OFFSETADDR].v.valU8;
    memset(pWRITECUSTOTPSPACEParms->custData, 0, sizeof(pWRITECUSTOTPSPACEParms->custData));

    pWRITECUSTOTPSPACEParms->custDataSize = pParmDict[PARM_CUSTDATASIZE].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_OFFSETADDR, (A_UINT32)(((A_UINT32)&(pWRITECUSTOTPSPACEParms->offsetAddr)) - (A_UINT32)pWRITECUSTOTPSPACEParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CUSTDATA, (A_UINT32)(((A_UINT32)&(pWRITECUSTOTPSPACEParms->custData)) - (A_UINT32)pWRITECUSTOTPSPACEParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CUSTDATASIZE, (A_UINT32)(((A_UINT32)&(pWRITECUSTOTPSPACEParms->custDataSize)) - (A_UINT32)pWRITECUSTOTPSPACEParms), pParmsOffset);
    return((void*) pWRITECUSTOTPSPACEParms);
}

static WRITECUSTOTPSPACE_OP_FUNC WRITECUSTOTPSPACEOpFunc = NULL;

TLV2_API void registerWRITECUSTOTPSPACEHandler(WRITECUSTOTPSPACE_OP_FUNC fp)
{
    WRITECUSTOTPSPACEOpFunc = fp;
}

A_BOOL WRITECUSTOTPSPACEOp(void *pParms)
{
    CMD_WRITECUSTOTPSPACE_PARMS *pWRITECUSTOTPSPACEParms = (CMD_WRITECUSTOTPSPACE_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("WRITECUSTOTPSPACEOp: offsetAddr %u\n", pWRITECUSTOTPSPACEParms->offsetAddr);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 23 entries
    {
        A_PRINTF("WRITECUSTOTPSPACEOp: custData %u\n", pWRITECUSTOTPSPACEParms->custData[i]);
    }
    A_PRINTF("WRITECUSTOTPSPACEOp: custDataSize %u\n", pWRITECUSTOTPSPACEParms->custDataSize);
#endif //_DEBUG

    if (NULL != WRITECUSTOTPSPACEOpFunc) {
        (*WRITECUSTOTPSPACEOpFunc)(pWRITECUSTOTPSPACEParms);
    }
    return(TRUE);
}

void* initWRITECUSTOTPSPACERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_WRITECUSTOTPSPACERSP_PARMS  *pWRITECUSTOTPSPACERSPParms = (CMD_WRITECUSTOTPSPACERSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pWRITECUSTOTPSPACERSPParms->writeStatus = pParmDict[PARM_WRITESTATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_WRITESTATUS, (A_UINT32)(((A_UINT32)&(pWRITECUSTOTPSPACERSPParms->writeStatus)) - (A_UINT32)pWRITECUSTOTPSPACERSPParms), pParmsOffset);
    return((void*) pWRITECUSTOTPSPACERSPParms);
}

static WRITECUSTOTPSPACERSP_OP_FUNC WRITECUSTOTPSPACERSPOpFunc = NULL;

TLV2_API void registerWRITECUSTOTPSPACERSPHandler(WRITECUSTOTPSPACERSP_OP_FUNC fp)
{
    WRITECUSTOTPSPACERSPOpFunc = fp;
}

A_BOOL WRITECUSTOTPSPACERSPOp(void *pParms)
{
    CMD_WRITECUSTOTPSPACERSP_PARMS *pWRITECUSTOTPSPACERSPParms = (CMD_WRITECUSTOTPSPACERSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("WRITECUSTOTPSPACERSPOp: writeStatus %u\n", pWRITECUSTOTPSPACERSPParms->writeStatus);
#endif //_DEBUG

    if (NULL != WRITECUSTOTPSPACERSPOpFunc) {
        (*WRITECUSTOTPSPACERSPOpFunc)(pWRITECUSTOTPSPACERSPParms);
    }
    return(TRUE);
}
