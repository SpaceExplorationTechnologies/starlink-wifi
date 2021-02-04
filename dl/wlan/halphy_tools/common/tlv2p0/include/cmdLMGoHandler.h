// This is an auto-generated file from input\cmdLMGoHandler.s
#ifndef _CMDLMGOHANDLER_H_
#define _CMDLMGOHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct lmgo_parms {
    A_UINT8	lm_cmdId;
    A_UINT8	pad3[3];
    A_UINT16	timeOn;
    A_UINT16	timeOff;
} __ATTRIB_PACK CMD_LMGO_PARMS;

typedef struct lmgorsp_parms {
    A_UINT8	lm_cmdId;
    A_UINT8	status;
    A_UINT8	pad2[2];
    A_UINT16	timeOn;
    A_UINT16	timeOff;
} __ATTRIB_PACK CMD_LMGORSP_PARMS;

typedef void (*LMGO_OP_FUNC)(void *pParms);
typedef void (*LMGORSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initLMGOOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMGOOp(void *pParms);

void* initLMGORSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMGORSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLMGOHANDLER_H_
