// This is an auto-generated file from input/cmdCustOtpSpaceWrite.s
#ifndef _CMDCUSTOTPSPACEWRITE_H_
#define _CMDCUSTOTPSPACEWRITE_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct writecustotpspace_parms {
    A_UINT8          offsetAddr;
    A_UINT8          pad[3];
    A_UINT8          custData[24];
    A_UINT32       custDataSize;
} __ATTRIB_PACK CMD_WRITECUSTOTPSPACE_PARMS;

typedef struct writecustotpspacersp_parms {
    A_UINT8	writeStatus;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_WRITECUSTOTPSPACERSP_PARMS;

typedef void (*WRITECUSTOTPSPACE_OP_FUNC)(void *pParms);
typedef void (*WRITECUSTOTPSPACERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initWRITECUSTOTPSPACEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL WRITECUSTOTPSPACEOp(void *pParms);

void* initWRITECUSTOTPSPACERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL WRITECUSTOTPSPACERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDCUSTOTPSPACEWRITE_H_
