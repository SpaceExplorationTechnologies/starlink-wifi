// This is an auto-generated file from input/cmdRxStatusHandler.s
#ifndef _CMDRXSTATUSHANDLER_H_
#define _CMDRXSTATUSHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct rxstatus_parms {
    A_UINT8	phyId;
    A_UINT8	stopRx;
    A_UINT16	freq;
    A_UINT16	freq2;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_RXSTATUS_PARMS;

typedef struct rxstatusrsp_parms {
    A_UINT8	phyId;
    A_UINT8	numOfReports;
    A_UINT8	pad2[2];
    A_UINT32	totalPackets;
    A_UINT32	goodPackets;
    A_UINT32	otherError;
    A_UINT32	crcPackets;
    A_UINT32	decrypErrors;
    A_UINT32	rateBit;
    A_UINT32	startTime;
    A_UINT32	endTime;
    A_UINT32	byteCount;
    A_UINT32	dontCount;
    A_INT32	rssi;
    A_INT32	rssic[4];
    A_INT32	rssie[4];
    A_INT32	badrssi;
    A_INT32	badrssic[4];
    A_INT32	badrssie[4];
    A_INT32	evm[4];
    A_INT32	badevm[4];
} __ATTRIB_PACK CMD_RXSTATUSRSP_PARMS;

typedef void (*RXSTATUS_OP_FUNC)(void *pParms);
typedef void (*RXSTATUSRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initRXSTATUSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXSTATUSOp(void *pParms);

void* initRXSTATUSRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXSTATUSRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDRXSTATUSHANDLER_H_
