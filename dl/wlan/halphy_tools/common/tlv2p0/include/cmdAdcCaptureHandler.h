// This is an auto-generated file from input\cmdAdcCaptureHandler.s

#ifdef USE_TLV2_EXTCMD


#ifndef _CMDADCCAPTUREHANDLER_H_
#define _CMDADCCAPTUREHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct adccapture_parms {
    A_UINT32	length;
    A_UINT8	phyId;
    A_UINT8	adcId;
    A_UINT8	modeId;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_ADCCAPTURE_PARMS;

typedef struct adccapturersp_parms {
    A_UINT16	dataI[2048];
    A_UINT16	dataQ[2048];
    A_UINT8	status;
    A_UINT8	phyId;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_ADCCAPTURERSP_PARMS;

typedef void (*ADCCAPTURE_OP_FUNC)(void *pParms);
typedef void (*ADCCAPTURERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initADCCAPTUREOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL ADCCAPTUREOp(void *pParms);

void* initADCCAPTURERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL ADCCAPTURERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDADCCAPTUREHANDLER_H_

#endif

