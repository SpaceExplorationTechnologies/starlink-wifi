// This is an auto-generated file from input\cmdCalCalTimeHandler.s

#ifdef USE_TLV2_EXTCMD

#include "tlv2Inc.h"
#include "cmdCalCalTimeHandler.h"

void* initCALCALTIMEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_CALCALTIME_PARMS  *pCALCALTIMEParms = (CMD_CALCALTIME_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pCALCALTIMEParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pCALCALTIMEParms->calOp = pParmDict[PARM_CALOP].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pCALCALTIMEParms->phyId)) - (A_UINT32)pCALCALTIMEParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CALOP, (A_UINT32)(((A_UINT32)&(pCALCALTIMEParms->calOp)) - (A_UINT32)pCALCALTIMEParms), pParmsOffset);
    return((void*) pCALCALTIMEParms);
}

static CALCALTIME_OP_FUNC CALCALTIMEOpFunc = NULL;

TLV2_API void registerCALCALTIMEHandler(CALCALTIME_OP_FUNC fp)
{
    CALCALTIMEOpFunc = fp;
}

A_BOOL CALCALTIMEOp(void *pParms)
{
    CMD_CALCALTIME_PARMS *pCALCALTIMEParms = (CMD_CALCALTIME_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("CALCALTIMEOp: phyId %u\n", pCALCALTIMEParms->phyId);
    A_PRINTF("CALCALTIMEOp: calOp %u\n", pCALCALTIMEParms->calOp);
#endif //_DEBUG

    if (NULL != CALCALTIMEOpFunc) {
        (*CALCALTIMEOpFunc)(pCALCALTIMEParms);
    }
    return(TRUE);
}

void* initCALCALTIMERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i; 	//for initializing array parameter
    CMD_CALCALTIMERSP_PARMS  *pCALCALTIMERSPParms = (CMD_CALCALTIMERSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = 0;	//assign a number to avoid warning in case i is not used

    // Populate the parm structure with initial values
    pCALCALTIMERSPParms->elapsedTime = pParmDict[PARM_ELAPSEDTIME].v.valU32;
    pCALCALTIMERSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pCALCALTIMERSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_ELAPSEDTIME, (A_UINT32)(((A_UINT32)&(pCALCALTIMERSPParms->elapsedTime)) - (A_UINT32)pCALCALTIMERSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pCALCALTIMERSPParms->status)) - (A_UINT32)pCALCALTIMERSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pCALCALTIMERSPParms->phyId)) - (A_UINT32)pCALCALTIMERSPParms), pParmsOffset);
    return((void*) pCALCALTIMERSPParms);
}

static CALCALTIMERSP_OP_FUNC CALCALTIMERSPOpFunc = NULL;

TLV2_API void registerCALCALTIMERSPHandler(CALCALTIMERSP_OP_FUNC fp)
{
    CALCALTIMERSPOpFunc = fp;
}

A_BOOL CALCALTIMERSPOp(void *pParms)
{
    CMD_CALCALTIMERSP_PARMS *pCALCALTIMERSPParms = (CMD_CALCALTIMERSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("CALCALTIMERSPOp: elapsedTime %u\n", pCALCALTIMERSPParms->elapsedTime);
    A_PRINTF("CALCALTIMERSPOp: status %u\n", pCALCALTIMERSPParms->status);
    A_PRINTF("CALCALTIMERSPOp: phyId %u\n", pCALCALTIMERSPParms->phyId);
#endif //_DEBUG

    if (NULL != CALCALTIMERSPOpFunc) {
        (*CALCALTIMERSPOpFunc)(pCALCALTIMERSPParms);
    }
    return(TRUE);
}

#endif
