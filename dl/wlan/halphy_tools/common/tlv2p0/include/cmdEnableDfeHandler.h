// This is an auto-generated file from input\cmdEnableDfeHandler.s
#ifndef _CMDENABLEDFEHANDLER_H_
#define _CMDENABLEDFEHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct enabledfe_parms {
    A_UINT8	phyId;
    A_UINT8	enable;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_ENABLEDFE_PARMS;

typedef struct enabledfersp_parms {
    A_UINT8	phyId;
    A_UINT8	status;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_ENABLEDFERSP_PARMS;

typedef void (*ENABLEDFE_OP_FUNC)(void *pParms);
typedef void (*ENABLEDFERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initENABLEDFEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL ENABLEDFEOp(void *pParms);

void* initENABLEDFERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL ENABLEDFERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDENABLEDFEHANDLER_H_
