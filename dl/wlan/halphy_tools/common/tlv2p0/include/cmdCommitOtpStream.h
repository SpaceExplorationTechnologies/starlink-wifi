// This is an auto-generated file from input/cmdCommitOtpStream.s
#ifndef _CMDCOMMITOTPSTREAM_H_
#define _CMDCOMMITOTPSTREAM_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef void (*COMMITOTPSTREAM_OP_FUNC)(void *pParms);
typedef void (*COMMITOTPSTREAMRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initCOMMITOTPSTREAMOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL COMMITOTPSTREAMOp(void *pParms);

void* initCOMMITOTPSTREAMRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL COMMITOTPSTREAMRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDCOMMITOTPSTREAM_H_
