// This is an auto-generated file from input\sysCmdTestData.s
#ifdef USE_TLV2_SYSCMD

#include "tlv2Inc.h"
#include "sysCmdTestData.h"

void* initTESTDATAOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    SYSCMD_TESTDATA_PARMS  *pTESTDATAParms = (SYSCMD_TESTDATA_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    memset(pTESTDATAParms->data1, 0, sizeof(pTESTDATAParms->data1));
    memset(pTESTDATAParms->data2, 0, sizeof(pTESTDATAParms->data2));
    memset(pTESTDATAParms->data3, 0, sizeof(pTESTDATAParms->data3));
    memset(pTESTDATAParms->data4, 0, sizeof(pTESTDATAParms->data4));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)SYSPARM_DATA1, (A_UINT32)(((A_UINT32)&(pTESTDATAParms->data1)) - (A_UINT32)pTESTDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_DATA2, (A_UINT32)(((A_UINT32)&(pTESTDATAParms->data2)) - (A_UINT32)pTESTDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_DATA3, (A_UINT32)(((A_UINT32)&(pTESTDATAParms->data3)) - (A_UINT32)pTESTDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_DATA4, (A_UINT32)(((A_UINT32)&(pTESTDATAParms->data4)) - (A_UINT32)pTESTDATAParms), pParmsOffset);
    return((void*) pTESTDATAParms);
}

static TESTDATA_OP_FUNC TESTDATAOpFunc = NULL;

TLV2_API void registerTESTDATAHandler(TESTDATA_OP_FUNC fp)
{
    TESTDATAOpFunc = fp;
}

A_BOOL TESTDATAOp(void *pParms)
{
    SYSCMD_TESTDATA_PARMS *pTESTDATAParms = (SYSCMD_TESTDATA_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    for (i = 0; i < 8 ; i++) // can be modified to print up to 1024 entries
    {
        A_PRINTF("TESTDATAOp: data1 0x%x\n", pTESTDATAParms->data1[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 1024 entries
    {
        A_PRINTF("TESTDATAOp: data2 0x%x\n", pTESTDATAParms->data2[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 1024 entries
    {
        A_PRINTF("TESTDATAOp: data3 0x%x\n", pTESTDATAParms->data3[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 1024 entries
    {
        A_PRINTF("TESTDATAOp: data4 0x%x\n", pTESTDATAParms->data4[i]);
    }
#endif //_DEBUG

    if (NULL != TESTDATAOpFunc) {
        (*TESTDATAOpFunc)(pTESTDATAParms);
    }
    return(TRUE);
}

void* initTESTDATARSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    SYSCMD_TESTDATARSP_PARMS  *pTESTDATARSPParms = (SYSCMD_TESTDATARSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pTESTDATARSPParms->status32 = pParmDict[SYSPARM_STATUS32-SYSPARM_FIRST_IDX].v.valU32;
    memset(pTESTDATARSPParms->data1, 0, sizeof(pTESTDATARSPParms->data1));
    memset(pTESTDATARSPParms->data2, 0, sizeof(pTESTDATARSPParms->data2));
    memset(pTESTDATARSPParms->data3, 0, sizeof(pTESTDATARSPParms->data3));
    memset(pTESTDATARSPParms->data4, 0, sizeof(pTESTDATARSPParms->data4));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)SYSPARM_STATUS32, (A_UINT32)(((A_UINT32)&(pTESTDATARSPParms->status32)) - (A_UINT32)pTESTDATARSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_DATA1, (A_UINT32)(((A_UINT32)&(pTESTDATARSPParms->data1)) - (A_UINT32)pTESTDATARSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_DATA2, (A_UINT32)(((A_UINT32)&(pTESTDATARSPParms->data2)) - (A_UINT32)pTESTDATARSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_DATA3, (A_UINT32)(((A_UINT32)&(pTESTDATARSPParms->data3)) - (A_UINT32)pTESTDATARSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)SYSPARM_DATA4, (A_UINT32)(((A_UINT32)&(pTESTDATARSPParms->data4)) - (A_UINT32)pTESTDATARSPParms), pParmsOffset);
    return((void*) pTESTDATARSPParms);
}

static TESTDATARSP_OP_FUNC TESTDATARSPOpFunc = NULL;

TLV2_API void registerTESTDATARSPHandler(TESTDATARSP_OP_FUNC fp)
{
    TESTDATARSPOpFunc = fp;
}

A_BOOL TESTDATARSPOp(void *pParms)
{
    SYSCMD_TESTDATARSP_PARMS *pTESTDATARSPParms = (SYSCMD_TESTDATARSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TESTDATARSPOp: status32 %u\n", pTESTDATARSPParms->status32);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 1024 entries
    {
        A_PRINTF("TESTDATARSPOp: data1 0x%x\n", pTESTDATARSPParms->data1[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 1024 entries
    {
        A_PRINTF("TESTDATARSPOp: data2 0x%x\n", pTESTDATARSPParms->data2[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 1024 entries
    {
        A_PRINTF("TESTDATARSPOp: data3 0x%x\n", pTESTDATARSPParms->data3[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 1024 entries
    {
        A_PRINTF("TESTDATARSPOp: data4 0x%x\n", pTESTDATARSPParms->data4[i]);
    }
#endif //_DEBUG

    if (NULL != TESTDATARSPOpFunc) {
        (*TESTDATARSPOpFunc)(pTESTDATARSPParms);
    }
    return(TRUE);
}


#endif //USE_TLV2_SYSCMD
