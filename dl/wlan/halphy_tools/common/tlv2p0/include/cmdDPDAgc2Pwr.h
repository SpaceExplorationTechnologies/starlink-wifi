// This is an auto-generated file from input\cmdDPDAgc2Pwr.s
#ifndef _CMDDPDAGC2PWR_H_
#define _CMDDPDAGC2PWR_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct dpdagc2pwr_parms {
    A_UINT8	phyId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_DPDAGC2PWR_PARMS;

typedef struct dpdagc2pwrrsp_parms {
    A_UINT8	phyId;
    A_INT8	DPDAgc2Pwr;
    A_UINT8	status;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_DPDAGC2PWRRSP_PARMS;

typedef void (*DPDAGC2PWR_OP_FUNC)(void *pParms);
typedef void (*DPDAGC2PWRRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initDPDAGC2PWROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL DPDAGC2PWROp(void *pParms);

void* initDPDAGC2PWRRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL DPDAGC2PWRRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDDPDAGC2PWR_H_
