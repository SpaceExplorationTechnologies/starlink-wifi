// This is an auto-generated file from input\cmdRegReadHandler.s
#ifndef _CMDREGREADHANDLER_H_
#define _CMDREGREADHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct regread_parms {
    A_UINT32	regaddress;
    A_UINT8	radioId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_REGREAD_PARMS;

typedef struct regreadrsp_parms {
    A_UINT32	regvalue;
    A_UINT8	radioId;
    A_UINT8	status;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_REGREADRSP_PARMS;

typedef void (*REGREAD_OP_FUNC)(void *pParms);
typedef void (*REGREADRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initREGREADOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL REGREADOp(void *pParms);

void* initREGREADRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL REGREADRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDREGREADHANDLER_H_
