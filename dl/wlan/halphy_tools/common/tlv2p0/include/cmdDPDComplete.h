// This is an auto-generated file from input\cmdDPDComplete.s
#ifndef _CMDDPDCOMPLETE_H_
#define _CMDDPDCOMPLETE_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct getdpdcomplete_parms {
    A_UINT8	phyId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_GETDPDCOMPLETE_PARMS;

typedef struct getdpdcompletersp_parms {
    A_UINT8	dpdComplete;
    A_UINT8	phyId;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_GETDPDCOMPLETERSP_PARMS;

typedef void (*GETDPDCOMPLETE_OP_FUNC)(void *pParms);
typedef void (*GETDPDCOMPLETERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initGETDPDCOMPLETEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GETDPDCOMPLETEOp(void *pParms);

void* initGETDPDCOMPLETERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GETDPDCOMPLETERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDDPDCOMPLETE_H_
