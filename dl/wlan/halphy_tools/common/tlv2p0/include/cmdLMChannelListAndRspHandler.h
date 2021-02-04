// This is an auto-generated file from input\cmdLMChannelListAndRspHandler.s
#ifndef _CMDLMCHANNELLISTANDRSPHANDLER_H_
#define _CMDLMCHANNELLISTANDRSPHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct lmchannellist_parms {
    A_UINT8	lm_flag;
    A_UINT8	lm_itemNum;
    A_UINT8	pad2[2];
    A_UINT8	lm_cbState[100];
    A_UINT8	lm_chainMask[100];
    A_UINT8	lm_txPower[100];
    A_UINT8	lm_phyId[100];
    A_UINT16	lm_freq[100];
    A_UINT16	lm_freq2[100];
    A_UINT16	lm_rateIndex[100];
} __ATTRIB_PACK CMD_LMCHANNELLIST_PARMS;

typedef struct lmchannellistrsp_parms {
    A_UINT8	status;
    A_UINT8	totalHWCalNum;
    A_UINT16	totalItemNum;
    A_UINT16	hwCalTime;
    A_UINT8	pad2[2];
} __ATTRIB_PACK CMD_LMCHANNELLISTRSP_PARMS;

typedef void (*LMCHANNELLIST_OP_FUNC)(void *pParms);
typedef void (*LMCHANNELLISTRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initLMCHANNELLISTOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMCHANNELLISTOp(void *pParms);

void* initLMCHANNELLISTRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMCHANNELLISTRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLMCHANNELLISTANDRSPHANDLER_H_
