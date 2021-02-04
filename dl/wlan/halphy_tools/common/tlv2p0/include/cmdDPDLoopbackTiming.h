// This is an auto-generated file from input\cmdDPDLoopbackTiming.s
#ifndef _CMDDPDLOOPBACKTIMING_H_
#define _CMDDPDLOOPBACKTIMING_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct dpdloopbacktiming_parms {
    A_UINT8	phyId;
    A_UINT8	DPDTimingIdx;
    A_INT8	DPDLoopbackAttn;
    A_UINT8	glutIdx;
} __ATTRIB_PACK CMD_DPDLOOPBACKTIMING_PARMS;

typedef struct dpdloopbacktimingrsp_parms {
    A_UINT8	phyId;
    A_UINT8	status;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_DPDLOOPBACKTIMINGRSP_PARMS;

typedef void (*DPDLOOPBACKTIMING_OP_FUNC)(void *pParms);
typedef void (*DPDLOOPBACKTIMINGRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initDPDLOOPBACKTIMINGOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL DPDLOOPBACKTIMINGOp(void *pParms);

void* initDPDLOOPBACKTIMINGRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL DPDLOOPBACKTIMINGRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDDPDLOOPBACKTIMING_H_
