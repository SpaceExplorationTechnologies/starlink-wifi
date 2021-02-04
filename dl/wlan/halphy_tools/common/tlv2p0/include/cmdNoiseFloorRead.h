// This is an auto-generated file from cmdNoiseFloorRead.s
#ifndef _CMDNOISEFLOORREAD_H_
#define _CMDNOISEFLOORREAD_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct noisefloorread_parms {
    A_UINT16	freq;
    A_UINT16	chainMask;
    A_UINT8	phyId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_NOISEFLOORREAD_PARMS;

typedef struct noisefloorreadrsp_parms {
    A_UINT32	nfValues[16];
    A_UINT8	phyId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_NOISEFLOORREADRSP_PARMS;

typedef void (*NOISEFLOORREAD_OP_FUNC)(void *pParms);
typedef void (*NOISEFLOORREADRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initNOISEFLOORREADOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL NOISEFLOORREADOp(void *pParms);

void* initNOISEFLOORREADRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL NOISEFLOORREADRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDNOISEFLOORREAD_H_

