// This is an auto-generated file from input\cmdRxHandler.s
#ifndef _CMDRXHANDLER_H_
#define _CMDRXHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct rx_parms {
    A_UINT8	phyId;
    A_UINT8	rxMode;
    A_UINT16	freq;
    A_UINT16	freq2;
    A_UINT8	chainMask;
    A_UINT8	wlanMode;
    A_UINT8	bandwidth;
    A_UINT8	antenna;
    A_UINT8	enANI;
    A_UINT8	ack;
    A_UINT8	broadcast;
    A_UINT8	lpl;
    A_UINT8	antswitch1;
    A_UINT8	antswitch2;
    A_UINT8	pad2[2];
    A_UINT16	spectralScan;
    A_INT16	noiseFloor;
    A_UINT16	regDmn[2];
    A_UINT32	expectedPkts;
    A_UINT32	otpWriteFlag;
    A_UINT32	flags;
    A_UINT32	rateMask[3];
    A_UINT32	rateMask11AC[5];
    A_UINT32	rateMaskAC160;
    A_UINT8	bssid[6];
    A_UINT8	staAddr[6];
    A_UINT8	btAddr[6];
} __ATTRIB_PACK CMD_RX_PARMS;

typedef struct rxrsp_parms {
    A_UINT8	phyId;
    A_UINT8	status;
    A_UINT8	rxMode;
    A_UINT8	pad1;
    A_INT32	rssiInDBm;
    A_UINT32	totalPackets;
    A_UINT32	crcPackets;
    A_UINT32	secErrPkt;
    A_UINT32	rateMask[2];
    A_UINT32	rateMask11AC[5];
    A_UINT32	rateCnt[32];
    A_UINT32	rateCnt11ac[69];
    A_UINT32	rateShortG[2];
    A_UINT32	rateShortG11ac[5];
} __ATTRIB_PACK CMD_RXRSP_PARMS;

typedef void (*RX_OP_FUNC)(void *pParms);
typedef void (*RXRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initRXOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXOp(void *pParms);

void* initRXRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDRXHANDLER_H_
