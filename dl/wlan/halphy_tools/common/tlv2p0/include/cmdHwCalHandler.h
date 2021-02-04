// This is an auto-generated file from input/cmdHwCalHandler.s
#ifndef _CMDHWCALHANDLER_H_
#define _CMDHWCALHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct hwcal_parms {
    A_UINT8	phyId;
    A_UINT8	calOp;
    A_UINT8	calOpFlag;
    A_UINT8	loopCnt;
    A_UINT8	chainMask;
    A_UINT8	loopBack;
    A_UINT8	saveCal;
    A_UINT8	noiseFloorCal;
    A_UINT8	calOpOrder[30];
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_HWCAL_PARMS;

typedef void (*HWCAL_OP_FUNC)(void *pParms);

// Exposed functions

void* initHWCALOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL HWCALOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDHWCALHANDLER_H_
