// This is an auto-generated file from input/cmdLMRxHandler.s
#ifndef _CMDLMRXHANDLER_H_
#define _CMDLMRXHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct lmrx_parms {
    A_UINT8	phyId;
    A_UINT8	rxMode;
    A_UINT8	lm_resvd1[2];
    A_UINT16	lm_freq[36];
    A_UINT16	lm_freq2[36];
    A_UINT8	lm_chainMask[36];
    A_UINT32	wlanModeMask[36];
    A_UINT32	wlanModeMaskExt[36];
    A_UINT8	lm_bandwidth[36];
    A_UINT8	antenna;
    A_UINT8	enANI;
    A_UINT8	ack;
    A_UINT8	broadcast;
    A_UINT8	lpl;
    A_UINT8	antswitch1;
    A_UINT8	antswitch2;
    A_UINT8	lm_resvd0;
    A_UINT16	spectralScan;
    A_INT16	noiseFloor;
    A_UINT16	regDmn[2];
    A_UINT32	expectedPkts;
    A_UINT32	otpWriteFlag;
    A_UINT32	flags;
    A_UINT32	rateMask[3];
    A_UINT32	rateMask11AC[5];
    A_UINT32	rateMaskAC160;
    A_UINT8	bssid[6];
    A_UINT8	staAddr[6];
    A_UINT8	btAddr[6];
    A_UINT8	pad2[2];
} __ATTRIB_PACK CMD_LMRX_PARMS;

typedef void (*LMRX_OP_FUNC)(void *pParms);

// Exposed functions

void* initLMRXOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMRXOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLMRXHANDLER_H_
