// This is an auto-generated file from input/cmdLMHWCALHandler.s
#include "tlv2Inc.h"
#include "cmdLMHWCALHandler.h"

void* initLMHWCALOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_LMHWCAL_PARMS  *pLMHWCALParms = (CMD_LMHWCAL_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pLMHWCALParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    memset(pLMHWCALParms->lm_resvd0, 0, sizeof(pLMHWCALParms->lm_resvd0));
    memset(pLMHWCALParms->lm_freq, 0, sizeof(pLMHWCALParms->lm_freq));
    for (i = 0; i < 2 ; i++)
    {
        pLMHWCALParms->lm_freq[i] = pParmDict[PARM_LM_FREQ].v.ptU16[i];
    }
    memset(pLMHWCALParms->lm_freq2, 0, sizeof(pLMHWCALParms->lm_freq2));
    for (i = 0; i < 2 ; i++)
    {
        pLMHWCALParms->lm_freq2[i] = pParmDict[PARM_LM_FREQ2].v.ptU16[i];
    }
    memset(pLMHWCALParms->lm_chainMask, 0, sizeof(pLMHWCALParms->lm_chainMask));
    for (i = 0; i < 1 ; i++)
    {
        pLMHWCALParms->lm_chainMask[i] = pParmDict[PARM_LM_CHAINMASK].v.ptU8[i];
    }
    memset(pLMHWCALParms->wlanModeMask, 0, sizeof(pLMHWCALParms->wlanModeMask));
    for (i = 0; i < 1 ; i++)
    {
        pLMHWCALParms->wlanModeMask[i] = pParmDict[PARM_WLANMODEMASK].v.ptU32[i];
    }
    memset(pLMHWCALParms->wlanModeMaskExt, 0, sizeof(pLMHWCALParms->wlanModeMaskExt));
    memset(pLMHWCALParms->lm_bandwidth, 0, sizeof(pLMHWCALParms->lm_bandwidth));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pLMHWCALParms->phyId)) - (A_UINT32)pLMHWCALParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_RESVD0, (A_UINT32)(((A_UINT32)&(pLMHWCALParms->lm_resvd0)) - (A_UINT32)pLMHWCALParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_FREQ, (A_UINT32)(((A_UINT32)&(pLMHWCALParms->lm_freq)) - (A_UINT32)pLMHWCALParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_FREQ2, (A_UINT32)(((A_UINT32)&(pLMHWCALParms->lm_freq2)) - (A_UINT32)pLMHWCALParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_CHAINMASK, (A_UINT32)(((A_UINT32)&(pLMHWCALParms->lm_chainMask)) - (A_UINT32)pLMHWCALParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_WLANMODEMASK, (A_UINT32)(((A_UINT32)&(pLMHWCALParms->wlanModeMask)) - (A_UINT32)pLMHWCALParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_WLANMODEMASKEXT, (A_UINT32)(((A_UINT32)&(pLMHWCALParms->wlanModeMaskExt)) - (A_UINT32)pLMHWCALParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LM_BANDWIDTH, (A_UINT32)(((A_UINT32)&(pLMHWCALParms->lm_bandwidth)) - (A_UINT32)pLMHWCALParms), pParmsOffset);
    return((void*) pLMHWCALParms);
}

static LMHWCAL_OP_FUNC LMHWCALOpFunc = NULL;

TLV2_API void registerLMHWCALHandler(LMHWCAL_OP_FUNC fp)
{
    LMHWCALOpFunc = fp;
}

A_BOOL LMHWCALOp(void *pParms)
{
    CMD_LMHWCAL_PARMS *pLMHWCALParms = (CMD_LMHWCAL_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LMHWCALOp: phyId %u\n", pLMHWCALParms->phyId);
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("LMHWCALOp: lm_resvd0 %u\n", pLMHWCALParms->lm_resvd0[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMHWCALOp: lm_freq %u\n", pLMHWCALParms->lm_freq[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMHWCALOp: lm_freq2 %u\n", pLMHWCALParms->lm_freq2[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMHWCALOp: lm_chainMask 0x%x\n", pLMHWCALParms->lm_chainMask[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMHWCALOp: wlanModeMask 0x%x\n", pLMHWCALParms->wlanModeMask[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMHWCALOp: wlanModeMaskExt 0x%x\n", pLMHWCALParms->wlanModeMaskExt[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 36 entries
    {
        A_PRINTF("LMHWCALOp: lm_bandwidth %u\n", pLMHWCALParms->lm_bandwidth[i]);
    }
#endif //_DEBUG

    if (NULL != LMHWCALOpFunc) {
        (*LMHWCALOpFunc)(pLMHWCALParms);
    }
    return(TRUE);
}
