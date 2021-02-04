// This is an auto-generated file from input/cmdCustOtpSpaceGetSize.s
#ifndef _CMDCUSTOTPSPACEGETSIZE_H_
#define _CMDCUSTOTPSPACEGETSIZE_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct getcustotpsizersp_parms {
    A_UINT32	otpCustSize;
} __ATTRIB_PACK CMD_GETCUSTOTPSIZERSP_PARMS;

typedef void (*GETCUSTOTPSIZE_OP_FUNC)(void *pParms);
typedef void (*GETCUSTOTPSIZERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initGETCUSTOTPSIZEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GETCUSTOTPSIZEOp(void *pParms);

void* initGETCUSTOTPSIZERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GETCUSTOTPSIZERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDCUSTOTPSPACEGETSIZE_H_
