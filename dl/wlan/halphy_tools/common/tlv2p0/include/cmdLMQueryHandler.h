// This is an auto-generated file from input\cmdLMQueryHandler.s
#ifndef _CMDLMQUERYHANDLER_H_
#define _CMDLMQUERYHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct lmquery_parms {
    A_UINT8	lm_cmdId;
    A_UINT8	pad3[3];
} __ATTRIB_PACK CMD_LMQUERY_PARMS;

typedef struct lmqueryrsp_parms {
    A_UINT8	status;
    A_UINT8	lm_cmdId;
    A_UINT8	pad2[2];
} __ATTRIB_PACK CMD_LMQUERYRSP_PARMS;

typedef void (*LMQUERY_OP_FUNC)(void *pParms);
typedef void (*LMQUERYRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initLMQUERYOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMQUERYOp(void *pParms);

void* initLMQUERYRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMQUERYRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLMQUERYHANDLER_H_
