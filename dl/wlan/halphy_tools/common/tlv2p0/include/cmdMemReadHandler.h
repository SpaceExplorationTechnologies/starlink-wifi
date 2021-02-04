// This is an auto-generated file from input/cmdMemReadHandler.s
#ifndef _CMDMEMREADHANDLER_H_
#define _CMDMEMREADHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct memread_parms {
    A_UINT32	memaddress;
    A_UINT8	numbytes;
    A_UINT8	valuetype;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_MEMREAD_PARMS;

typedef struct memreadrsp_parms {
    A_UINT32	memaddress;
    A_UINT8	memvalue[255];
    A_UINT8	numbytes;
    A_UINT8	valuetype;
    A_UINT8	status;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_MEMREADRSP_PARMS;

typedef void (*MEMREAD_OP_FUNC)(void *pParms);
typedef void (*MEMREADRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initMEMREADOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL MEMREADOp(void *pParms);

void* initMEMREADRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL MEMREADRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDMEMREADHANDLER_H_
