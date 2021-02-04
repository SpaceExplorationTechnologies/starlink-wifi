// This is an auto-generated file from input/cmdLMTxHandler.s
#ifndef _CMDLMTXHANDLER_H_
#define _CMDLMTXHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct lmtx_parms {
    A_UINT8	phyId;
    A_UINT8	txMode;
    A_UINT8	lm_resvd1[2];
    A_UINT16	lm_freq[36];
    A_UINT16	lm_freq2[36];
    A_UINT8	lm_chainMask[36];
    A_UINT32	wlanModeMask[36];
    A_UINT32	wlanModeMaskExt[36];
    A_UINT8	lm_bandwidth[36];
    A_UINT8	gI;
    A_UINT8	antenna;
    A_UINT8	enANI;
    A_UINT8	scramblerOff;
    A_UINT8	aifsn;
    A_UINT8	broadcast;
    A_UINT8	agg;
    A_UINT8	shortGuard;
    A_UINT8	dutyCycle;
    A_UINT8	lm_resvd0[3];
    A_UINT32	flags;
    A_UINT32	ir;
    A_UINT32	pktSz;
    A_UINT8	dataPattern[40];
    A_UINT16	txNumPackets;
    A_UINT16	txPattern;
    A_UINT8	nPattern;
    A_UINT8	tpcm;
    A_UINT8	gainIdx;
    A_INT8	dacGain;
    A_INT8	dacGainEnd;
    A_INT8	dacGainStep;
    A_UINT8	paConfig;
    A_UINT8	paConfigEnd;
    A_UINT8	paConfigStep;
    A_UINT8	pad3[3];
    A_UINT32	rateMask[3];
    A_UINT32	rateMask11AC[5];
    A_UINT32	rateMaskAC160;
    A_INT32	pwrGainStart[24];
    A_INT32	pwrGainEnd[24];
    A_INT32	pwrGainStep[24];
    A_INT32	pwrGainStart11AC[40];
    A_INT32	pwrGainEnd11AC[40];
    A_INT32	pwrGainStep11AC[40];
    A_INT32	pwrGainStartAC160[8];
    A_INT32	pwrGainEndAC160[8];
    A_INT32	pwrGainStepAC160[8];
    A_UINT8	bssid[6];
    A_UINT8	txStation[6];
    A_UINT8	rxStation[6];
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_LMTX_PARMS;

typedef void (*LMTX_OP_FUNC)(void *pParms);

// Exposed functions

void* initLMTXOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMTXOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLMTXHANDLER_H_
