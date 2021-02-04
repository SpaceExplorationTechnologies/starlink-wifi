// This is an auto-generated file from input/cmdCustOtpSpaceRead.s
#ifndef _CMDCUSTOTPSPACEREAD_H_
#define _CMDCUSTOTPSPACEREAD_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct readcustotpspacersp_parms {
    A_UINT8	custData[24];
} __ATTRIB_PACK CMD_READCUSTOTPSPACERSP_PARMS;

typedef void (*READCUSTOTPSPACE_OP_FUNC)(void *pParms);
typedef void (*READCUSTOTPSPACERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initREADCUSTOTPSPACEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL READCUSTOTPSPACEOp(void *pParms);

void* initREADCUSTOTPSPACERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL READCUSTOTPSPACERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDCUSTOTPSPACEREAD_H_
