// This is an auto-generated file from input\sysCmdTestData.s

#ifndef _SYSCMDTESTDATA_H_
#define _SYSCMDTESTDATA_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64


#ifdef USE_TLV2_SYSCMD

typedef struct testdata_parms {
    A_UINT8	data1[1024];
    A_UINT8	data2[1024];
    A_UINT8	data3[1024];
    A_UINT8	data4[1024];
} __ATTRIB_PACK SYSCMD_TESTDATA_PARMS;

typedef struct testdatarsp_parms {
    A_UINT32	status32;
    A_UINT8	data1[1024];
    A_UINT8	data2[1024];
    A_UINT8	data3[1024];
    A_UINT8	data4[1024];
} __ATTRIB_PACK SYSCMD_TESTDATARSP_PARMS;

typedef void (*TESTDATA_OP_FUNC)(void *pParms);
typedef void (*TESTDATARSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initTESTDATAOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TESTDATAOp(void *pParms);

void* initTESTDATARSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TESTDATARSPOp(void *pParms);

#endif //USE_TLV2_SYSCMD

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_SYSCMDTESTDATA_H_
