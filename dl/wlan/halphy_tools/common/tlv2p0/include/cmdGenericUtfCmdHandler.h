// This is an auto-generated file from input/cmdGenericUtfCmdHandler.s
#ifndef _CMDGENERICUTFCMDHANDLER_H_
#define _CMDGENERICUTFCMDHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct genericutfcmd_parms {
    A_UINT32	Measurement;
    A_INT32	inParams[32];
    A_UINT16	GenericUtfCmdID;
    A_UINT8	phyId;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_GENERICUTFCMD_PARMS;

typedef struct genericutfcmdrsp_parms {
    A_UINT8	GenericUtfCmdDone;
    A_UINT8	NumGenericUtfCmdRetData;
    A_UINT16	GenericUtfCmdStatus;
    A_INT32	GenericUtfCmdRetData[32];
    A_UINT8	phyId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_GENERICUTFCMDRSP_PARMS;

typedef void (*GENERICUTFCMD_OP_FUNC)(void *pParms);
typedef void (*GENERICUTFCMDRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initGENERICUTFCMDOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GENERICUTFCMDOp(void *pParms);

void* initGENERICUTFCMDRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GENERICUTFCMDRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDGENERICUTFCMDHANDLER_H_
