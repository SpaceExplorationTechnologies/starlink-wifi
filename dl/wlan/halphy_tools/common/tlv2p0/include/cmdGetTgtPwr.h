// This is an auto-generated file from input/cmdGetTgtPwr.s
#ifndef _CMDGETTGTPWR_H_
#define _CMDGETTGTPWR_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct gettgtpwr_parms {
    A_UINT8	phyId;
    A_UINT8	userMode;
    A_UINT16	freq;
    A_UINT32	rateBit;
} __ATTRIB_PACK CMD_GETTGTPWR_PARMS;

typedef struct gettgtpwrrsp_parms {
    A_UINT8	phyId;
    A_UINT8	tgtPwr;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_GETTGTPWRRSP_PARMS;

typedef void (*GETTGTPWR_OP_FUNC)(void *pParms);
typedef void (*GETTGTPWRRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initGETTGTPWROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GETTGTPWROp(void *pParms);

void* initGETTGTPWRRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GETTGTPWRRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDGETTGTPWR_H_
