// This is an auto-generated file from input/cmdSetRegDmn.s
#ifndef _CMDSETREGDMN_H_
#define _CMDSETREGDMN_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct setregdmn_parms {
    A_UINT16	regDmn[2];
} __ATTRIB_PACK CMD_SETREGDMN_PARMS;

typedef void (*SETREGDMN_OP_FUNC)(void *pParms);
typedef void (*SETREGDMNRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initSETREGDMNOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETREGDMNOp(void *pParms);

void* initSETREGDMNRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETREGDMNRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDSETREGDMN_H_
