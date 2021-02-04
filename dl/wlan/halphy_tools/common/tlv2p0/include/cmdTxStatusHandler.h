// This is an auto-generated file from input\cmdTxStatusHandler.s
#ifndef _CMDTXSTATUSHANDLER_H_
#define _CMDTXSTATUSHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct txstatus_parms {
    A_UINT8	phyId;
    A_UINT8	stopTx;
    A_UINT8	needReport;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_TXSTATUS_PARMS;

typedef struct txstatusrsp_parms {
    A_UINT8	phyId;
    A_UINT8	status;
    A_UINT8	numOfReports;
    A_UINT8	thermCal;
    A_UINT8	pdadc;
    A_UINT8	paCfg;
    A_UINT8	gainIdx;
    A_INT8	dacGain;
    A_UINT32	totalPackets;
    A_UINT32	goodPackets;
    A_UINT32	underruns;
    A_UINT32	otherError;
    A_UINT32	excessRetries;
    A_UINT32	rateBit;
    A_UINT32	shortRetry;
    A_UINT32	longRetry;
    A_UINT32	startTime;
    A_UINT32	endTime;
    A_UINT32	byteCount;
    A_UINT32	dontCount;
    A_INT32	rssi;
    A_INT32	rssic[4];
    A_INT32	rssie[4];
} __ATTRIB_PACK CMD_TXSTATUSRSP_PARMS;

typedef void (*TXSTATUS_OP_FUNC)(void *pParms);
typedef void (*TXSTATUSRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initTXSTATUSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TXSTATUSOp(void *pParms);

void* initTXSTATUSRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TXSTATUSRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDTXSTATUSHANDLER_H_
