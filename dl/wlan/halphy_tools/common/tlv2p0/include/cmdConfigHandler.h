// This is an auto-generated file from input/cmdConfigHandler.s
#ifndef _CMDCONFIGHANDLER_H_
#define _CMDCONFIGHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct config_parms {
    A_UINT8	phyId;
    A_UINT8	wlanMode;
    A_UINT16	freq;
    A_UINT16	freq2;
    A_UINT8	bandwidth;
    A_UINT8	rate;
} __ATTRIB_PACK CMD_CONFIG_PARMS;

typedef void (*CONFIG_OP_FUNC)(void *pParms);

// Exposed functions

void* initCONFIGOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CONFIGOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDCONFIGHANDLER_H_
