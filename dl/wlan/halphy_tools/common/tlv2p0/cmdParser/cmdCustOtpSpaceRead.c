// This is an auto-generated file from input/cmdCustOtpSpaceRead.s
#include "tlv2Inc.h"
#include "cmdCustOtpSpaceRead.h"

void* initREADCUSTOTPSPACEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    return(NULL);
}

static READCUSTOTPSPACE_OP_FUNC READCUSTOTPSPACEOpFunc = NULL;

TLV2_API void registerREADCUSTOTPSPACEHandler(READCUSTOTPSPACE_OP_FUNC fp)
{
    READCUSTOTPSPACEOpFunc = fp;
}

A_BOOL READCUSTOTPSPACEOp(void *pParms)
{
    if (NULL != READCUSTOTPSPACEOpFunc) {
        (*READCUSTOTPSPACEOpFunc)(NULL);
    }
    return(TRUE);
}

void* initREADCUSTOTPSPACERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_READCUSTOTPSPACERSP_PARMS  *pREADCUSTOTPSPACERSPParms = (CMD_READCUSTOTPSPACERSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    memset(pREADCUSTOTPSPACERSPParms->custData, 0, sizeof(pREADCUSTOTPSPACERSPParms->custData));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_CUSTDATA, (A_UINT32)(((A_UINT32)&(pREADCUSTOTPSPACERSPParms->custData)) - (A_UINT32)pREADCUSTOTPSPACERSPParms), pParmsOffset);
    return((void*) pREADCUSTOTPSPACERSPParms);
}

static READCUSTOTPSPACERSP_OP_FUNC READCUSTOTPSPACERSPOpFunc = NULL;

TLV2_API void registerREADCUSTOTPSPACERSPHandler(READCUSTOTPSPACERSP_OP_FUNC fp)
{
    READCUSTOTPSPACERSPOpFunc = fp;
}

A_BOOL READCUSTOTPSPACERSPOp(void *pParms)
{
    CMD_READCUSTOTPSPACERSP_PARMS *pREADCUSTOTPSPACERSPParms = (CMD_READCUSTOTPSPACERSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    for (i = 0; i < 8 ; i++) // can be modified to print up to 23 entries
    {
        A_PRINTF("READCUSTOTPSPACERSPOp: custData %u\n", pREADCUSTOTPSPACERSPParms->custData[i]);
    }
#endif //_DEBUG

    if (NULL != READCUSTOTPSPACERSPOpFunc) {
        (*READCUSTOTPSPACERSPOpFunc)(pREADCUSTOTPSPACERSPParms);
    }
    return(TRUE);
}
