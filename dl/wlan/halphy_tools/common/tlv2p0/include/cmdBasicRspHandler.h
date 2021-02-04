// This is an auto-generated file from input\cmdBasicRspHandler.s
#ifndef _CMDBASICRSPHANDLER_H_
#define _CMDBASICRSPHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct basicrsp_parms {
    A_UINT16	cmdId;
    A_UINT8	phyId;
    A_UINT8	status;
} __ATTRIB_PACK CMD_BASICRSP_PARMS;

typedef void (*BASICRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initBASICRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL BASICRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDBASICRSPHANDLER_H_
