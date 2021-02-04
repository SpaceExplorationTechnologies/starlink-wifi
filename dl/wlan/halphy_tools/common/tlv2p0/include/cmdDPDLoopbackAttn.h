// This is an auto-generated file from input\cmdDPDLoopbackAttn.s
#ifndef _CMDDPDLOOPBACKATTN_H_
#define _CMDDPDLOOPBACKATTN_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct dpdloopbackattn_parms {
    A_UINT8	phyId;
    A_INT8	DPDLoopbackAttn;
    A_UINT8	glutIdx;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_DPDLOOPBACKATTN_PARMS;

typedef struct dpdloopbackattnrsp_parms {
    A_UINT8	phyId;
    A_UINT8	status;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_DPDLOOPBACKATTNRSP_PARMS;

typedef void (*DPDLOOPBACKATTN_OP_FUNC)(void *pParms);
typedef void (*DPDLOOPBACKATTNRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initDPDLOOPBACKATTNOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL DPDLOOPBACKATTNOp(void *pParms);

void* initDPDLOOPBACKATTNRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL DPDLOOPBACKATTNRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDDPDLOOPBACKATTN_H_
