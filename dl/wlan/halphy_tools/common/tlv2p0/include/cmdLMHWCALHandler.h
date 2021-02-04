// This is an auto-generated file from input/cmdLMHWCALHandler.s
#ifndef _CMDLMHWCALHANDLER_H_
#define _CMDLMHWCALHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct lmhwcal_parms {
    A_UINT8	phyId;
    A_UINT8	lm_resvd0[3];
    A_UINT16	lm_freq[36];
    A_UINT16	lm_freq2[36];
    A_UINT8	lm_chainMask[36];
    A_UINT32	wlanModeMask[36];
    A_UINT32	wlanModeMaskExt[36];
    A_UINT8	lm_bandwidth[36];
} __ATTRIB_PACK CMD_LMHWCAL_PARMS;

typedef void (*LMHWCAL_OP_FUNC)(void *pParms);

// Exposed functions

void* initLMHWCALOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LMHWCALOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLMHWCALHANDLER_H_
