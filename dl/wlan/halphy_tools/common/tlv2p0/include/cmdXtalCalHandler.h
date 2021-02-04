// This is an auto-generated file from input\cmdXtalCalHandler.s
#ifndef _CMDXTALCALHANDLER_H_
#define _CMDXTALCALHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct xtalcalproc_parms {
    A_UINT8	capIn;
    A_UINT8	capOut;
    A_UINT8	ctrlFlag;
    A_UINT8	phyId;
} __ATTRIB_PACK CMD_XTALCALPROC_PARMS;

typedef struct xtalcalprocrsp_parms {
    A_UINT8	status;
    A_UINT8	capValMin;
    A_UINT8	capValMax;
    A_UINT8	capIn;
    A_UINT8	capOut;
    A_UINT8	pllLocked;
    A_UINT8	phyId;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_XTALCALPROCRSP_PARMS;

typedef void (*XTALCALPROC_OP_FUNC)(void *pParms);
typedef void (*XTALCALPROCRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initXTALCALPROCOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL XTALCALPROCOp(void *pParms);

void* initXTALCALPROCRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL XTALCALPROCRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDXTALCALHANDLER_H_
