// This is an auto-generated file from input/cmdGetTgtPwr.s
#include "tlv2Inc.h"
#include "cmdGetTgtPwr.h"

void* initGETTGTPWROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_GETTGTPWR_PARMS  *pGETTGTPWRParms = (CMD_GETTGTPWR_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pGETTGTPWRParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pGETTGTPWRParms->userMode = pParmDict[PARM_USERMODE].v.valU8;
    pGETTGTPWRParms->freq = pParmDict[PARM_FREQ].v.valU16;
    pGETTGTPWRParms->rateBit = pParmDict[PARM_RATEBIT].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pGETTGTPWRParms->phyId)) - (A_UINT32)pGETTGTPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_USERMODE, (A_UINT32)(((A_UINT32)&(pGETTGTPWRParms->userMode)) - (A_UINT32)pGETTGTPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ, (A_UINT32)(((A_UINT32)&(pGETTGTPWRParms->freq)) - (A_UINT32)pGETTGTPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEBIT, (A_UINT32)(((A_UINT32)&(pGETTGTPWRParms->rateBit)) - (A_UINT32)pGETTGTPWRParms), pParmsOffset);
    return((void*) pGETTGTPWRParms);
}

static GETTGTPWR_OP_FUNC GETTGTPWROpFunc = NULL;

TLV2_API void registerGETTGTPWRHandler(GETTGTPWR_OP_FUNC fp)
{
    GETTGTPWROpFunc = fp;
}

A_BOOL GETTGTPWROp(void *pParms)
{
    CMD_GETTGTPWR_PARMS *pGETTGTPWRParms = (CMD_GETTGTPWR_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("GETTGTPWROp: phyId %u\n", pGETTGTPWRParms->phyId);
    A_PRINTF("GETTGTPWROp: userMode %u\n", pGETTGTPWRParms->userMode);
    A_PRINTF("GETTGTPWROp: freq %u\n", pGETTGTPWRParms->freq);
    A_PRINTF("GETTGTPWROp: rateBit %u\n", pGETTGTPWRParms->rateBit);
#endif //_DEBUG

    if (NULL != GETTGTPWROpFunc) {
        (*GETTGTPWROpFunc)(pGETTGTPWRParms);
    }
    return(TRUE);
}

void* initGETTGTPWRRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_GETTGTPWRRSP_PARMS  *pGETTGTPWRRSPParms = (CMD_GETTGTPWRRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pGETTGTPWRRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pGETTGTPWRRSPParms->tgtPwr = pParmDict[PARM_TGTPWR].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pGETTGTPWRRSPParms->phyId)) - (A_UINT32)pGETTGTPWRRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TGTPWR, (A_UINT32)(((A_UINT32)&(pGETTGTPWRRSPParms->tgtPwr)) - (A_UINT32)pGETTGTPWRRSPParms), pParmsOffset);
    return((void*) pGETTGTPWRRSPParms);
}

static GETTGTPWRRSP_OP_FUNC GETTGTPWRRSPOpFunc = NULL;

TLV2_API void registerGETTGTPWRRSPHandler(GETTGTPWRRSP_OP_FUNC fp)
{
    GETTGTPWRRSPOpFunc = fp;
}

A_BOOL GETTGTPWRRSPOp(void *pParms)
{
    CMD_GETTGTPWRRSP_PARMS *pGETTGTPWRRSPParms = (CMD_GETTGTPWRRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("GETTGTPWRRSPOp: phyId %u\n", pGETTGTPWRRSPParms->phyId);
    A_PRINTF("GETTGTPWRRSPOp: tgtPwr %u\n", pGETTGTPWRRSPParms->tgtPwr);
#endif //_DEBUG

    if (NULL != GETTGTPWRRSPOpFunc) {
        (*GETTGTPWRRSPOpFunc)(pGETTGTPWRRSPParms);
    }
    return(TRUE);
}
