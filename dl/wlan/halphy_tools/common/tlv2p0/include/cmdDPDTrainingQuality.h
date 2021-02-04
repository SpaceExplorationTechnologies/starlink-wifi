// This is an auto-generated file from input/cmdDPDTrainingQuality.s
#ifndef _CMDDPDTRAININGQUALITY_H_
#define _CMDDPDTRAININGQUALITY_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct dpdtrainingquality_parms {
    A_UINT8	phyId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_DPDTRAININGQUALITY_PARMS;

typedef struct dpdtrainingqualityrsp_parms {
    A_UINT16	DPDTrainQual;
    A_UINT8	status;
    A_UINT8	phyId;
} __ATTRIB_PACK CMD_DPDTRAININGQUALITYRSP_PARMS;

typedef void (*DPDTRAININGQUALITY_OP_FUNC)(void *pParms);
typedef void (*DPDTRAININGQUALITYRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initDPDTRAININGQUALITYOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL DPDTRAININGQUALITYOp(void *pParms);

void* initDPDTRAININGQUALITYRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL DPDTRAININGQUALITYRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDDPDTRAININGQUALITY_H_
