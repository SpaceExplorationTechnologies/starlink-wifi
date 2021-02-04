// This is an auto-generated file from input/sysCmdGeneric.s

#ifndef _SYSCMDGENERIC_H_
#define _SYSCMDGENERIC_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64


#ifdef USE_TLV2_SYSCMD

typedef struct generic_parms {
    A_UINT32	generic_param_cmdID;
    A_UINT32	generic_param_01;
    A_UINT32	generic_param_02;
    A_UINT32	generic_param_03;
    A_UINT32	generic_param_04;
    A_UINT32	generic_param_05;
    A_UINT32	generic_param_06;
    A_UINT32	generic_param_07;
    A_UINT32	generic_param_08;
    A_UINT32	generic_param_09;
    A_UINT32	generic_param_10;
} __ATTRIB_PACK SYSCMD_GENERIC_PARMS;

typedef struct genericrsp_parms {
    A_UINT32	generic_param_cmdID;
    A_UINT32	generic_param_01;
    A_UINT32	generic_param_02;
    A_UINT32	generic_param_03;
    A_UINT32	generic_param_04;
    A_UINT32	generic_param_05;
    A_UINT32	generic_param_06;
    A_UINT32	generic_param_07;
    A_UINT32	generic_param_08;
    A_UINT32	generic_param_09;
    A_UINT32	generic_param_10;
} __ATTRIB_PACK SYSCMD_GENERICRSP_PARMS;

typedef void (*GENERIC_OP_FUNC)(void *pParms);
typedef void (*GENERICRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initGENERICOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GENERICOp(void *pParms);

void* initGENERICRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GENERICRSPOp(void *pParms);

#endif //USE_TLV2_SYSCMD

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_SYSCMDGENERIC_H_

