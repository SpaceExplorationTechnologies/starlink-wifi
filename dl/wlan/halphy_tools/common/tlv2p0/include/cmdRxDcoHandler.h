// This is an auto-generated file from input/cmdRxDcoHandler.s


#ifdef USE_TLV2_EXTCMD

#ifndef _CMDRXDCOHANDLER_H_
#define _CMDRXDCOHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct rxdcogroup_parms {
    A_UINT8	cmdIdRxDcoGroup;
    A_UINT8	phyId;
    A_UINT8	bbDcocRange;
    A_UINT8	rfDcocRange;
    A_UINT8	chainMask;
    A_UINT8	lpbkMode;
    A_UINT8	rfFirst;
    A_UINT8	initLUT;
    A_UINT8	rfOvrd;
    A_UINT8	bbOvrd;
    A_UINT8	numGain;
    A_UINT8	band;
    A_UINT8	chain;
    A_UINT8	rfBB;
    A_UINT8	depth;
    A_UINT8	useCosimSetting;
    A_UINT16	gainLut[20];
    A_UINT16	rfDocLut[80];
    A_UINT16	bbDocLut[80];
    A_UINT16	inputTable2SwProcessing[100];
    A_UINT16	sleepTime;
    A_UINT16	threshold;
} __ATTRIB_PACK CMD_RXDCOGROUP_PARMS;

typedef struct rxdcogrouprsp_parms {
    A_UINT8	cmdIdRxDcoGroup;
    A_UINT8	phyId;
    A_UINT8	bbDcocRange;
    A_UINT8	rfDcocRange;
    A_UINT8	chainMask;
    A_UINT8	lpbkMode;
    A_UINT8	rfFirst;
    A_UINT8	initLUT;
    A_UINT8	rfOvrd;
    A_UINT8	bbOvrd;
    A_UINT8	numGain;
    A_UINT8	band;
    A_UINT8	chain;
    A_UINT8	rfBB;
    A_UINT8	depth;
    A_UINT8	padding;
    A_UINT32	executionTime;
    A_UINT16	gainLut[20];
    A_UINT16	dcoI;
    A_UINT16	dcoQ;
    A_UINT16	rfDocLut[80];
    A_UINT16	bbDocLut[80];
    A_UINT16	hwProcessedTable[100];
} __ATTRIB_PACK CMD_RXDCOGROUPRSP_PARMS;

typedef void (*RXDCOGROUP_OP_FUNC)(void *pParms);
typedef void (*RXDCOGROUPRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initRXDCOGROUPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXDCOGROUPOp(void *pParms);

void* initRXDCOGROUPRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXDCOGROUPRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDRXDCOHANDLER_H_

#endif
