// This is an auto-generated file from input\cmdGenWaveformHandler.s

#ifdef USE_TLV2_EXTCMD

#ifndef _CMDGENWAVEFORMHANDLER_H_
#define _CMDGENWAVEFORMHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct genwaveform_parms {
    A_UINT16	waveformIndex;
    A_UINT8	phyId;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_GENWAVEFORM_PARMS;

typedef struct genwaveformrsp_parms {
    A_UINT16	dataI[2048];
    A_UINT16	dataQ[2048];
    A_UINT8	status;
    A_UINT8	phyId;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_GENWAVEFORMRSP_PARMS;

typedef void (*GENWAVEFORM_OP_FUNC)(void *pParms);
typedef void (*GENWAVEFORMRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initGENWAVEFORMOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GENWAVEFORMOp(void *pParms);

void* initGENWAVEFORMRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GENWAVEFORMRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDGENWAVEFORMHANDLER_H_

#endif
