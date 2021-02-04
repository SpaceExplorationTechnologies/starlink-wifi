// This is an auto-generated file from input\cmdCalCalTimeHandler.s

#ifdef USE_TLV2_EXTCMD

#ifndef _CMDCALCALTIMEHANDLER_H_
#define _CMDCALCALTIMEHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct calcaltime_parms {
    A_UINT8	phyId;
    A_UINT8	calOp;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_CALCALTIME_PARMS;

typedef struct calcaltimersp_parms {
    A_UINT32	elapsedTime;
    A_UINT8	status;
    A_UINT8	phyId;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_CALCALTIMERSP_PARMS;

typedef void (*CALCALTIME_OP_FUNC)(void *pParms);
typedef void (*CALCALTIMERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initCALCALTIMEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CALCALTIMEOp(void *pParms);

void* initCALCALTIMERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CALCALTIMERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDCALCALTIMEHANDLER_H_

#endif
