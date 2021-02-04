// This is an auto-generated file from input\cmdAdcCaptureHandler.s

#ifdef USE_TLV2_EXTCMD

#include "tlv2Inc.h"
#include "cmdAdcCaptureHandler.h"

void* initADCCAPTUREOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_ADCCAPTURE_PARMS  *pADCCAPTUREParms = (CMD_ADCCAPTURE_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pADCCAPTUREParms->length = pParmDict[PARM_LENGTH].v.valU32;
    pADCCAPTUREParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pADCCAPTUREParms->adcId = pParmDict[PARM_ADCID].v.valU8;
    pADCCAPTUREParms->modeId = pParmDict[PARM_MODEID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_LENGTH, (A_UINT32)(((A_UINT32)&(pADCCAPTUREParms->length)) - (A_UINT32)pADCCAPTUREParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pADCCAPTUREParms->phyId)) - (A_UINT32)pADCCAPTUREParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ADCID, (A_UINT32)(((A_UINT32)&(pADCCAPTUREParms->adcId)) - (A_UINT32)pADCCAPTUREParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_MODEID, (A_UINT32)(((A_UINT32)&(pADCCAPTUREParms->modeId)) - (A_UINT32)pADCCAPTUREParms), pParmsOffset);
    return((void*) pADCCAPTUREParms);
}

static ADCCAPTURE_OP_FUNC ADCCAPTUREOpFunc = NULL;

TLV2_API void registerADCCAPTUREHandler(ADCCAPTURE_OP_FUNC fp)
{
    ADCCAPTUREOpFunc = fp;
}

A_BOOL ADCCAPTUREOp(void *pParms)
{
    CMD_ADCCAPTURE_PARMS *pADCCAPTUREParms = (CMD_ADCCAPTURE_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("ADCCAPTUREOp: length %u\n", pADCCAPTUREParms->length);
    A_PRINTF("ADCCAPTUREOp: phyId %u\n", pADCCAPTUREParms->phyId);
    A_PRINTF("ADCCAPTUREOp: adcId %u\n", pADCCAPTUREParms->adcId);
    A_PRINTF("ADCCAPTUREOp: modeId %u\n", pADCCAPTUREParms->modeId);
#endif //_DEBUG

    if (NULL != ADCCAPTUREOpFunc) {
        (*ADCCAPTUREOpFunc)(pADCCAPTUREParms);
    }
    return(TRUE);
}

void* initADCCAPTURERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_ADCCAPTURERSP_PARMS  *pADCCAPTURERSPParms = (CMD_ADCCAPTURERSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    memset(pADCCAPTURERSPParms->dataI, 0, sizeof(pADCCAPTURERSPParms->dataI));
    memset(pADCCAPTURERSPParms->dataQ, 0, sizeof(pADCCAPTURERSPParms->dataQ));
    pADCCAPTURERSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pADCCAPTURERSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_DATAI, (A_UINT32)(((A_UINT32)&(pADCCAPTURERSPParms->dataI)) - (A_UINT32)pADCCAPTURERSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DATAQ, (A_UINT32)(((A_UINT32)&(pADCCAPTURERSPParms->dataQ)) - (A_UINT32)pADCCAPTURERSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pADCCAPTURERSPParms->status)) - (A_UINT32)pADCCAPTURERSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pADCCAPTURERSPParms->phyId)) - (A_UINT32)pADCCAPTURERSPParms), pParmsOffset);
    return((void*) pADCCAPTURERSPParms);
}

static ADCCAPTURERSP_OP_FUNC ADCCAPTURERSPOpFunc = NULL;

TLV2_API void registerADCCAPTURERSPHandler(ADCCAPTURERSP_OP_FUNC fp)
{
    ADCCAPTURERSPOpFunc = fp;
}

A_BOOL ADCCAPTURERSPOp(void *pParms)
{
    CMD_ADCCAPTURERSP_PARMS *pADCCAPTURERSPParms = (CMD_ADCCAPTURERSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    for (i = 0; i < 8 ; i++) // can be modified to print up to 2048 entries
    {
        A_PRINTF("ADCCAPTURERSPOp: dataI 0x%x\n", pADCCAPTURERSPParms->dataI[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 2048 entries
    {
        A_PRINTF("ADCCAPTURERSPOp: dataQ 0x%x\n", pADCCAPTURERSPParms->dataQ[i]);
    }
    A_PRINTF("ADCCAPTURERSPOp: status %u\n", pADCCAPTURERSPParms->status);
    A_PRINTF("ADCCAPTURERSPOp: phyId %u\n", pADCCAPTURERSPParms->phyId);
#endif //_DEBUG

    if (NULL != ADCCAPTURERSPOpFunc) {
        (*ADCCAPTURERSPOpFunc)(pADCCAPTURERSPParms);
    }
    return(TRUE);
}

#endif
