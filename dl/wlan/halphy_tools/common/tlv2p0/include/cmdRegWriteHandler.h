// This is an auto-generated file from input\cmdRegWriteHandler.s
#ifndef _CMDREGWRITEHANDLER_H_
#define _CMDREGWRITEHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct regwrite_parms {
    A_UINT32	regaddress;
    A_UINT32	regvalue;
    A_UINT8	radioId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_REGWRITE_PARMS;

typedef struct regwritersp_parms {
    A_UINT32	status;
    A_UINT8	radioId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_REGWRITERSP_PARMS;

typedef void (*REGWRITE_OP_FUNC)(void *pParms);
typedef void (*REGWRITERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initREGWRITEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL REGWRITEOp(void *pParms);

void* initREGWRITERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL REGWRITERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDREGWRITEHANDLER_H_
