// This is an auto-generated file from input/cmdLMTxInitHandler.s
#ifndef _CMDLMTXINITHANDLER_H_
#define _CMDLMTXINITHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct lmtxinit_parms {
    A_UINT8	txMode;
    A_UINT8	bandwidth;
    A_UINT8	gI;
    A_UINT8	antenna;
    A_UINT8	enANI;
    A_UINT8	scramblerOff;
    A_UINT8	aifsn;
    A_UINT8	broadcast;
    A_UINT8	agg;
    A_UINT8	shortGuard;
    A_UINT8	dutyCycle;
    A_UINT8	nPattern;
    A_UINT8	tpcm;
    A_UINT8	gainIdx;
    A_INT8	dacGain;
    A_INT8	dacGainEnd;
    A_INT8	dacGainStep;
    A_UINT8	paConfig;
    A_UINT8	paConfigEnd;
    A_UINT8	paConfigStep;
    A_UINT8	dataPattern[40];
    A_UINT8	bssid[6];
    A_UINT8	txStation[6];
    A_UINT8	rxStation[6];
    A_UINT8	pad2[2];
    A_UINT16	txNumPackets;
    A_UINT16	txPattern;
    A_UINT32	flags;
    A_UINT32	ir;
    A_UINT32	pktSz;
} __ATTRIB_PACK CMD_LMTXINIT_PARMS;

typedef struct lmtxinitrsp_parms {
    A_UINT16	cmdId;
    A_UINT8	status;
    A_UINT8	pad1;
} __ATTRIB_PACK CMD_LMTXINITRSP_PARMS;

typedef void (*LMTXINIT_OP_FUNC)(void *pParms);
typedef void (*LMTXINITRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initLMTXINITOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMTXINITOp(void *pParms);

void* initLMTXINITRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMTXINITRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLMTXINITHANDLER_H_
