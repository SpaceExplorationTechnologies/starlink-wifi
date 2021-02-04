// This is an auto-generated file from input/cmdMemWriteHandler.s
#ifndef _CMDMEMWRITEHANDLER_H_
#define _CMDMEMWRITEHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct memwrite_parms {
    A_UINT32	memaddress;
    A_UINT8	numbytes;
    A_UINT8	memvalue[255];
    A_UINT8	valuetype;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_MEMWRITE_PARMS;

typedef struct memwritersp_parms {
    A_UINT32	memaddress;
    A_UINT8	numbytes;
    A_UINT8	valuetype;
    A_UINT8	status;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_MEMWRITERSP_PARMS;

typedef void (*MEMWRITE_OP_FUNC)(void *pParms);
typedef void (*MEMWRITERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initMEMWRITEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL MEMWRITEOp(void *pParms);

void* initMEMWRITERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL MEMWRITERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDMEMWRITEHANDLER_H_
