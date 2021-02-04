// This is an auto-generated file from input\cmdLMRxInitHandler.s
#ifndef _CMDLMRXINITHANDLER_H_
#define _CMDLMRXINITHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct lmrxinit_parms {
    A_UINT8	rxMode;
    A_UINT8	bandwidth;
    A_UINT8	antenna;
    A_UINT8	enANI;
    A_UINT8	ack;
    A_UINT8	broadcast;
    A_UINT8	lpl;
    A_UINT8	antswitch1;
    A_UINT8	antswitch2;
    A_UINT8	pad3[3];
    A_UINT16	spectralScan;
    A_INT16	noiseFloor;
    A_UINT16	regDmn[2];
    A_UINT32	expectedPkts;
    A_UINT32	otpWriteFlag;
    A_UINT32	flags;
    A_UINT8	bssid[6];
    A_UINT8	staAddr[6];
    A_UINT8	btAddr[6];
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_LMRXINIT_PARMS;

typedef struct lmrxinitrsp_parms {
    A_UINT16	cmdId;
    A_UINT8	status;
    A_UINT8	pad1;
} __ATTRIB_PACK CMD_LMRXINITRSP_PARMS;

typedef void (*LMRXINIT_OP_FUNC)(void *pParms);
typedef void (*LMRXINITRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initLMRXINITOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMRXINITOp(void *pParms);

void* initLMRXINITRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMRXINITRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLMRXINITHANDLER_H_
