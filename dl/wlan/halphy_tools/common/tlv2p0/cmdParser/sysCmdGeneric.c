// This is an auto-generated file from input/sysCmdGeneric.s

#ifdef USE_TLV2_SYSCMD

#include "tlv2Inc.h"
#include "sysCmdGeneric.h"

void* initGENERICOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    SYSCMD_GENERIC_PARMS  *pGENERICParms = (SYSCMD_GENERIC_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pGENERICParms->generic_param_cmdID = pParmDict[SYSPARM_GENERIC_PARAM_CMDID-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICParms->generic_param_01 = pParmDict[SYSPARM_GENERIC_PARAM_01-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICParms->generic_param_02 = pParmDict[SYSPARM_GENERIC_PARAM_02-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICParms->generic_param_03 = pParmDict[SYSPARM_GENERIC_PARAM_03-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICParms->generic_param_04 = pParmDict[SYSPARM_GENERIC_PARAM_04-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICParms->generic_param_05 = pParmDict[SYSPARM_GENERIC_PARAM_05-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICParms->generic_param_06 = pParmDict[SYSPARM_GENERIC_PARAM_06-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICParms->generic_param_07 = pParmDict[SYSPARM_GENERIC_PARAM_07-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICParms->generic_param_08 = pParmDict[SYSPARM_GENERIC_PARAM_08-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICParms->generic_param_09 = pParmDict[SYSPARM_GENERIC_PARAM_09-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICParms->generic_param_10 = pParmDict[SYSPARM_GENERIC_PARAM_10-SYSPARM_FIRST_IDX].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_CMDID, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_cmdID)) - (A_UINT32)pGENERICParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_01, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_01)) - (A_UINT32)pGENERICParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_02, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_02)) - (A_UINT32)pGENERICParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_03, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_03)) - (A_UINT32)pGENERICParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_04, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_04)) - (A_UINT32)pGENERICParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_05, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_05)) - (A_UINT32)pGENERICParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_06, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_06)) - (A_UINT32)pGENERICParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_07, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_07)) - (A_UINT32)pGENERICParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_08, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_08)) - (A_UINT32)pGENERICParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_09, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_09)) - (A_UINT32)pGENERICParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_10, (A_UINT32)(((A_UINT32)&(pGENERICParms->generic_param_10)) - (A_UINT32)pGENERICParms), pParmsOffset);
    return((void*) pGENERICParms);
}

static GENERIC_OP_FUNC GENERICOpFunc = NULL;

TLV2_API void registerGENERICHandler(GENERIC_OP_FUNC fp)
{
    GENERICOpFunc = fp;
}

A_BOOL GENERICOp(void *pParms)
{
    SYSCMD_GENERIC_PARMS *pGENERICParms = (SYSCMD_GENERIC_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("GENERICOp: generic_param_cmdID %u\n", pGENERICParms->generic_param_cmdID);
    A_PRINTF("GENERICOp: generic_param_01 %u\n", pGENERICParms->generic_param_01);
    A_PRINTF("GENERICOp: generic_param_02 %u\n", pGENERICParms->generic_param_02);
    A_PRINTF("GENERICOp: generic_param_03 %u\n", pGENERICParms->generic_param_03);
    A_PRINTF("GENERICOp: generic_param_04 %u\n", pGENERICParms->generic_param_04);
    A_PRINTF("GENERICOp: generic_param_05 %u\n", pGENERICParms->generic_param_05);
    A_PRINTF("GENERICOp: generic_param_06 %u\n", pGENERICParms->generic_param_06);
    A_PRINTF("GENERICOp: generic_param_07 %u\n", pGENERICParms->generic_param_07);
    A_PRINTF("GENERICOp: generic_param_08 %u\n", pGENERICParms->generic_param_08);
    A_PRINTF("GENERICOp: generic_param_09 %u\n", pGENERICParms->generic_param_09);
    A_PRINTF("GENERICOp: generic_param_10 %u\n", pGENERICParms->generic_param_10);
#endif //_DEBUG

    if (NULL != GENERICOpFunc) {
        (*GENERICOpFunc)(pGENERICParms);
    }
    return(TRUE);
}

void* initGENERICRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    SYSCMD_GENERICRSP_PARMS  *pGENERICRSPParms = (SYSCMD_GENERICRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pGENERICRSPParms->generic_param_cmdID = pParmDict[SYSPARM_GENERIC_PARAM_CMDID-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICRSPParms->generic_param_01 = pParmDict[SYSPARM_GENERIC_PARAM_01-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICRSPParms->generic_param_02 = pParmDict[SYSPARM_GENERIC_PARAM_02-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICRSPParms->generic_param_03 = pParmDict[SYSPARM_GENERIC_PARAM_03-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICRSPParms->generic_param_04 = pParmDict[SYSPARM_GENERIC_PARAM_04-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICRSPParms->generic_param_05 = pParmDict[SYSPARM_GENERIC_PARAM_05-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICRSPParms->generic_param_06 = pParmDict[SYSPARM_GENERIC_PARAM_06-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICRSPParms->generic_param_07 = pParmDict[SYSPARM_GENERIC_PARAM_07-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICRSPParms->generic_param_08 = pParmDict[SYSPARM_GENERIC_PARAM_08-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICRSPParms->generic_param_09 = pParmDict[SYSPARM_GENERIC_PARAM_09-SYSPARM_FIRST_IDX].v.valU32;
    pGENERICRSPParms->generic_param_10 = pParmDict[SYSPARM_GENERIC_PARAM_10-SYSPARM_FIRST_IDX].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_CMDID, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_cmdID)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_01, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_01)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_02, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_02)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_03, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_03)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_04, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_04)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_05, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_05)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_06, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_06)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_07, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_07)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_08, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_08)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_09, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_09)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_GENERIC_PARAM_10, (A_UINT32)(((A_UINT32)&(pGENERICRSPParms->generic_param_10)) - (A_UINT32)pGENERICRSPParms), pParmsOffset);
    return((void*) pGENERICRSPParms);
}

static GENERICRSP_OP_FUNC GENERICRSPOpFunc = NULL;

TLV2_API void registerGENERICRSPHandler(GENERICRSP_OP_FUNC fp)
{
    GENERICRSPOpFunc = fp;
}

A_BOOL GENERICRSPOp(void *pParms)
{
    SYSCMD_GENERICRSP_PARMS *pGENERICRSPParms = (SYSCMD_GENERICRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("GENERICRSPOp: generic_param_cmdID %u\n", pGENERICRSPParms->generic_param_cmdID);
    A_PRINTF("GENERICRSPOp: generic_param_01 %u\n", pGENERICRSPParms->generic_param_01);
    A_PRINTF("GENERICRSPOp: generic_param_02 %u\n", pGENERICRSPParms->generic_param_02);
    A_PRINTF("GENERICRSPOp: generic_param_03 %u\n", pGENERICRSPParms->generic_param_03);
    A_PRINTF("GENERICRSPOp: generic_param_04 %u\n", pGENERICRSPParms->generic_param_04);
    A_PRINTF("GENERICRSPOp: generic_param_05 %u\n", pGENERICRSPParms->generic_param_05);
    A_PRINTF("GENERICRSPOp: generic_param_06 %u\n", pGENERICRSPParms->generic_param_06);
    A_PRINTF("GENERICRSPOp: generic_param_07 %u\n", pGENERICRSPParms->generic_param_07);
    A_PRINTF("GENERICRSPOp: generic_param_08 %u\n", pGENERICRSPParms->generic_param_08);
    A_PRINTF("GENERICRSPOp: generic_param_09 %u\n", pGENERICRSPParms->generic_param_09);
    A_PRINTF("GENERICRSPOp: generic_param_10 %u\n", pGENERICRSPParms->generic_param_10);
#endif //_DEBUG

    if (NULL != GENERICRSPOpFunc) {
        (*GENERICRSPOpFunc)(pGENERICRSPParms);
    }
    return(TRUE);
}

#endif
