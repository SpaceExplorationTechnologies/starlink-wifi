// This is an auto-generated file from input\cmdMoreSegmentHandler.s
#ifndef _CMDMORESEGMENTHANDLER_H_
#define _CMDMORESEGMENTHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct moresegment_parms {
    A_UINT16	cmdId;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_MORESEGMENT_PARMS;

typedef struct moresegmentrsp_parms {
    A_UINT16	cmdId;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_MORESEGMENTRSP_PARMS;

typedef void (*MORESEGMENT_OP_FUNC)(void *pParms);
typedef void (*MORESEGMENTRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initMORESEGMENTOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL MORESEGMENTOp(void *pParms);

void* initMORESEGMENTRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL MORESEGMENTRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDMORESEGMENTHANDLER_H_
