// This is an auto-generated file from input/cmdLMHWCALRSPHandler.s
#ifndef _CMDLMHWCALRSPHANDLER_H_
#define _CMDLMHWCALRSPHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct lmhwcalrsp_parms {
    A_UINT8	phyId;
    A_UINT8	status;
    A_UINT16	hwCalTime;
} __ATTRIB_PACK CMD_LMHWCALRSP_PARMS;

typedef void (*LMHWCALRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initLMHWCALRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMHWCALRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLMHWCALRSPHANDLER_H_
