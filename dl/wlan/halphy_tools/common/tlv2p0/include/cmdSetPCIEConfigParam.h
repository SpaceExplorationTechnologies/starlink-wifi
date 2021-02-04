// This is an auto-generated file from input/cmdSetPCIEConfigParam.s
#ifndef _CMDSETPCIECONFIGPARAM_H_
#define _CMDSETPCIECONFIGPARAM_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct setpcieconfigparams_parms {
    A_UINT32	pcieAddr;
    A_UINT32	pcieValue;
    A_UINT32	size;
    A_UINT8	operation;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_SETPCIECONFIGPARAMS_PARMS;

typedef void (*SETPCIECONFIGPARAMS_OP_FUNC)(void *pParms);
typedef void (*SETPCIECONFIGPARAMSRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initSETPCIECONFIGPARAMSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETPCIECONFIGPARAMSOp(void *pParms);

void* initSETPCIECONFIGPARAMSRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETPCIECONFIGPARAMSRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDSETPCIECONFIGPARAM_H_
