#include "tlv2Inc.h"
#include "commonInc.h"

#include "athdefs.h"
#include <utf_dev.h>
#include "art_utf_common.h"
#include "tcmd_api.h"
#include "parmBinTemplate.h"
#include "parseBinCmdStream.h"
#include "cmdAllParms.h"
#include "cmdProcessingSM.h"

#include "osapi.h"
#include "dk_cmds.h"
#include "tcmdHostInternal.h"
#include "commonHwIF.h"
#include "wmi_tcmd.h"
#include "tcmd_api.h"
#include "halphy_reset.h"

#define PHY_CCA_MAX_GOOD_VAL -50
#define NUM_MAX_CHAINS 16
#define DEFAULT_NF_VALUE_NON_SUPPORTED_CHAIN 0x100003E7    // 999 in Hex and most significant byte has been set to 1 to indicate negative

//-----------------------------------------------------------------------------
// External Variables
//-----------------------------------------------------------------------------

extern A_UINT32 currentDevIndex;
extern wlan_tcmd_dev_t utf_dev;
extern _CMD_ALL_PARMS _cmdParms;
extern TCMD_CONT_TX tx_tcmdParms;
extern TCMD_CONT_RX rx_tcmdParms;
extern tcmd_link_trx tcmdLinkTRx;
extern A_UINT8 dataPayload[];
extern A_UINT8 report_Static[];

//-----------------------------------------------------------------------------
// External Functions
//-----------------------------------------------------------------------------

extern A_UINT32 isValidReg(A_UINT32 addr);
extern _CMDPROC_RC txCmdProcessor(_CMD_ALL_PARMS *parms);
extern A_BOOL txDataStatsReport(A_UINT32 rIdx, A_BOOL flagTxDone, A_UINT8 *outBuf);
extern _CMDPROC_RC rxCmdProcessor(_CMD_ALL_PARMS *parms);
extern A_BOOL rxDataStatsReport(A_UINT32 rIdx, A_UINT8 *outBuf);
extern _CMDPROC_RC rxCmdProcessor_common(_CMD_ALL_PARMS *parms, A_UINT32 expectedPkts, _CMDPROC_EVENT evt, A_BOOL callerHandleRsp);
extern void setRates4Report (TCMD_CONT_RX *contRx, A_UINT32 *pShortGuard, A_UINT32 *pShortGuard11AC,
					A_UINT32 *pRateMask0, A_UINT32 *pRateMask1, A_UINT32 *rate11ACMask, A_UINT32 *pRate11AC4x4Mask);
extern void setRxNotifyInfo (A_UINT32 expectedPkts, _CMDPROC_EVENT evt);

extern void initLMGOHandler(void);
extern void initLMTXInitHandler(void);
extern void initLMQueryHandler(void);
extern void initLMChannelListHandler(void);
extern void initLMRXInitHandler(void);
//-----------------------------------------------------------------------------
// Local Variables
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Function Definitions
//-----------------------------------------------------------------------------


//SRAM_TEXT
void memReadHandler (void *parm)
{
	CMD_MEMREAD_PARMS *pParms = (CMD_MEMREAD_PARMS *)parm;
	TESTFLOW_CMD_STREAM_V2 *pCmdStream;
	A_UINT8 *rCmdStream = NULL;
	A_UINT32 cmdStreamLen=0;
	A_UINT8 rvalue[256];
	A_INT32 mem_offset, status = CMD_OK, b;

	if (pParms->memaddress % pParms->valuetype != 0)
	{
		status = COMMS_ERR_BAD_OFFSET;
	}
	else
	{
	    A_PRINTF("mr address=0x%x, numbytes=%d, valuetype=%d\n", pParms->memaddress, pParms->numbytes, pParms->valuetype);

		for (b = 0; b < pParms->numbytes; b++)
		{
			mem_offset = (pParms->memaddress + b) % 4;
			A_UINT32 temp = hwMemRead32((A_UINT16)currentDevIndex, pParms->memaddress + b - mem_offset);
			rvalue[b] = (temp >> (8*(3-mem_offset))) & 0x000000FF;
		}
	}

	pCmdStream = createCmdRsp(CMD_MEMREADRSP, 12, PARM_VALUETYPE, pParms->valuetype, PARM_MEMADDRESS, pParms->memaddress, PARM_NUMBYTES, pParms->numbytes, PARM_STATUS, status, PARM_MEMVALUE, 255, 0, rvalue);
	if (pCmdStream)
	{
		cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
		rCmdStream = (A_UINT8 *)pCmdStream;

		wmi_tc_cmds_reply_event(utf_dev.wmi, cmdStreamLen, CMD_MEMREADRSP, (A_INT8*)rCmdStream);
    }
    return;
}


//SRAM_TEXT
void memWriteHandler (void *parm)
{
	CMD_MEMWRITE_PARMS *pParms  = (CMD_MEMWRITE_PARMS *)parm;
	TESTFLOW_CMD_STREAM_V2 *pCmdStream;
	A_UINT8 *rCmdStream = NULL;
	A_UINT32 cmdStreamLen=0, status = CMD_OK, b, mem_offset;

	if (pParms->memaddress % pParms->valuetype != 0)
	{
		status = COMMS_ERR_BAD_OFFSET;
	}
	else
	{
		A_PRINTF("mw address=0x%x, numbytes=%d, valuetype=%d\n", pParms->memaddress, pParms->numbytes, pParms->valuetype);

		for (b = 0; b < pParms->numbytes; b++)
		{
			mem_offset = (pParms->memaddress + b) % 4;
			// read current value
			A_UINT32 temp = hwMemRead32((A_UINT16)currentDevIndex, pParms->memaddress + b - mem_offset);
			// mask in new bytes
			temp = temp & ~(0xFF000000 >> (8*mem_offset));
			temp = temp | (pParms->memvalue[b] << (8*(3-mem_offset)));
			// write back
			hwMemWrite32((A_UINT16)currentDevIndex, pParms->memaddress + b - mem_offset, temp);

		}
	}

	pCmdStream = createCmdRsp(CMD_MEMWRITERSP, 8, PARM_NUMBYTES, pParms->numbytes, PARM_VALUETYPE, pParms->valuetype, PARM_MEMADDRESS, pParms->memaddress,  PARM_STATUS, status);
	if (pCmdStream)
	{
		cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
		rCmdStream = (A_UINT8 *)pCmdStream;

		wmi_tc_cmds_reply_event(utf_dev.wmi, cmdStreamLen, CMD_MEMWRITERSP, (A_INT8*)rCmdStream);
	}
	return;
}

//SRAM_TEXT
void regReadHandler (void *parm)
{
	CMD_REGREAD_PARMS *pParms = (CMD_REGREAD_PARMS *)parm;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 value = 0xDEADBEEF, status = CMD_OK;

    A_PRINTF("rr 0x%x\n", pParms->regaddress);
    if ((status = isValidReg(pParms->regaddress)) != CMD_OK || pParms->regaddress % 0x04 != 0)
    {
    	status = COMMS_ERR_BAD_OFFSET;
    }
    else
    {
		/* read the register */
		value = hwMemRead32((A_UINT16)currentDevIndex, pParms->regaddress);
		A_PRINTF("reg = 0x%x\n", value);
    }
	pCmdStream = createCmdRsp(CMD_REGREADRSP, 4, PARM_STATUS, status, PARM_REGVALUE, value);

	if (pCmdStream)
	{
		cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
		rCmdStream = (A_UINT8 *)pCmdStream;

		wmi_tc_cmds_reply_event(utf_dev.wmi, cmdStreamLen, CMD_REGREADRSP, (A_INT8*)rCmdStream);
	}
  	return;
}

//SRAM_TEXT
void regWriteHandler (void *parm)
{
	CMD_REGWRITE_PARMS *pParms  = (CMD_REGWRITE_PARMS *)parm;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 status = CMD_OK;

    A_PRINTF("rw 0x%x 0x%x\n", pParms->regaddress, pParms->regvalue);
    if ((status = isValidReg(pParms->regaddress)) != CMD_OK || pParms->regaddress % 0x04 != 0)
    {
    	status = COMMS_ERR_BAD_OFFSET;
    }
    else
    {
    	/* write the register */
    	hwMemWrite32((A_UINT16)currentDevIndex, pParms->regaddress, pParms->regvalue);
    }

	pCmdStream = createCmdRsp(CMD_REGWRITERSP, 2, PARM_STATUS, status);
	if (pCmdStream)
	{
		cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
		rCmdStream = (A_UINT8 *)pCmdStream;

		wmi_tc_cmds_reply_event(utf_dev.wmi, cmdStreamLen, CMD_REGWRITERSP, (A_INT8*)rCmdStream);
	}
  	return;
}

void sendBasicRsp (A_UINT16 cmdId, A_UINT8 phyId, A_UINT8 status)
{
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;

    pCmdStream = createCmdRsp(CMD_BASICRSP, 6,
    				PARM_CMDID, cmdId,
					PARM_PHYID, phyId,
					PARM_STATUS, status);
    if (pCmdStream)
    {
    	cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    	rCmdStream = (A_UINT8 *)pCmdStream;

    	wmi_tc_cmds_reply_event(utf_dev.wmi, cmdStreamLen, CMD_REGREADRSP, (A_INT8*)rCmdStream);
    }
	return;
}

//SRAM_TEXT
void txHandler (void *parms)
{
	CMD_TX_PARMS *pParms  = (CMD_TX_PARMS *)parms;
	_CMD_TX_PARMS *pTxParms = (_CMD_TX_PARMS *)&_cmdParms;
	_CMDPROC_RC rc;

	A_PRINTF("tlv2 txHandler 0x%x\n", (A_UINT32)parms);
	A_MEMSET(pTxParms, 0, sizeof(_CMD_ALL_PARMS));

	pTxParms->channel = pParms->freq;
	pTxParms->txMode = pParms->txMode;
	A_MEMCPY(pTxParms->rateMask, pParms->rateMask, sizeof(A_UINT32) * RATE_MASK_ROW_MAX_11N);
	A_MEMCPY(pTxParms->pwrGainStart, pParms->pwrGainStart, sizeof(A_INT32) * PWRGAIN_ROW_MAX);
	A_MEMCPY(pTxParms->pwrGainEnd, pParms->pwrGainEnd, sizeof(A_INT32) * PWRGAIN_ROW_MAX);
	A_MEMCPY(pTxParms->pwrGainStep, pParms->pwrGainStep, sizeof(A_INT32) * PWRGAIN_ROW_MAX);
    pTxParms->antenna = pParms->antenna;
    pTxParms->enANI = pParms->enANI;
    pTxParms->scramblerOff = pParms->scramblerOff;
    pTxParms->aifsn = pParms->aifsn;
    pTxParms->pktSz = pParms->pktSz;
    pTxParms->txPattern = pParms->txPattern;
    pTxParms->shortGuard = pParms->shortGuard;
    pTxParms->numPackets = pParms->txNumPackets;
    pTxParms->wlanMode = pParms->wlanMode;
    pTxParms->txChain[0] = pParms->chainMask;
    pTxParms->tpcm = pParms->tpcm;
    pTxParms->flags = pParms->flags;
    pTxParms->agg = pParms->agg;
    pTxParms->broadcast = pParms->broadcast;
    pTxParms->bandwidth = pParms->bandwidth;
    A_MEMCPY(pTxParms->bssid, pParms->bssid, ATH_MAC_LEN);
    A_MEMCPY(pTxParms->txStation, pParms->txStation, ATH_MAC_LEN);
    A_MEMCPY(pTxParms->rxStation, pParms->rxStation, ATH_MAC_LEN);

    pTxParms->dutyCycle = pParms->dutyCycle;
    pTxParms->nPattern = pParms->nPattern;

    A_MEMCPY(pTxParms->dataPattern, pParms->dataPattern, MPATTERN);
    pTxParms->ir = pParms->ir;

    A_MEMCPY(pTxParms->rateMask11AC, pParms->rateMask11AC, sizeof(A_UINT32) * RATE_MASK_ROW_MAX_11AC);
    pTxParms->rtMaskAC4x4 = pParms->rateMask11AC[4];
    A_MEMCPY(pTxParms->pwrGnACStart, pParms->pwrGainStart11AC, sizeof(A_INT32) * PWRGAIN_11AC_ROW_MAX);
    A_MEMCPY(pTxParms->pwrGnAC4x4, &(pParms->pwrGainStart11AC[PWRGAIN_11AC_ROW_MAX]), sizeof(A_INT32) * PWRGAIN_11_AC_ROW_4x4_MAX);
    pTxParms->pwrGnACEnd = pParms->pwrGainEnd11AC[0] & PWRGAIN_MASK;
    pTxParms->pwrGnACStep = pParms->pwrGainStep11AC[0] & PWRGAIN_MASK;

    pTxParms->gainIdx = pParms->gainIdx;
    pTxParms->dacGain = pParms->dacGain;
    pTxParms->paConfig = pParms->paConfig;

    rc = txCmdProcessor((_CMD_ALL_PARMS *)pTxParms);

    sendBasicRsp (CMD_TX, pParms->phyId, (rc == CMDPROC_RC_SYNC_SUCC ? CMD_OK : 0xff));
}

void tlv2SendTxStatus(wlan_tcmd_dev_t *dev, A_UINT8 phyId, A_UINT32 numOfReports, A_UINT8 *replyBuf)
{
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    TX_STATS_STRUCT_UTF *pTxStats;
    A_UINT8 status = CMD_OK;

    pTxStats = (TX_STATS_STRUCT_UTF*)replyBuf;

    tlv2CreateCmdHeader(CMD_TXSTATUSRSP);
    tlv2AddParms (6, PARM_PHYID, phyId, PARM_STATUS, status, PARM_NUMOFREPORTS, numOfReports);
    if (numOfReports)
    {
    	tlv2AddParms(44, PARM_THERMCAL, pTxStats->thermCal,
					PARM_PDADC, pTxStats->pdadc,
					PARM_PACFG, pTxStats->paCfg,
					PARM_GAINIDX, pTxStats->gainIdx,
					PARM_DACGAIN, pTxStats->dacGain,
					PARM_TOTALPACKETS, pTxStats->totalPackets,
					PARM_GOODPACKETS, pTxStats->goodPackets,
					PARM_UNDERRUNS, pTxStats->underruns,
					PARM_OTHERERROR, pTxStats->otherError,
					PARM_EXCESSRETRIES, pTxStats->excessiveRetries,
					PARM_RATEBIT, pTxStats->rateBit,
					PARM_SHORTRETRY, pTxStats->shortRetry,
					PARM_LONGRETRY, pTxStats->longRetry,
					PARM_STARTTIME, pTxStats->startTime,
					PARM_ENDTIME, pTxStats->endTime,
					PARM_BYTECOUNT, pTxStats->byteCount,
					PARM_DONTCOUNT, pTxStats->dontCount,
					PARM_RSSI, pTxStats->rssi,
					PARM_RSSIC, MCHAIN_UTF, 0, pTxStats->rssic,
					PARM_RSSIE, MCHAIN_UTF, 0, pTxStats->rssie);
    }
    pCmdStream = tlv2CompleteCmdRsp();
    if (pCmdStream)
    {
    	cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    	rCmdStream = (A_UINT8 *)pCmdStream;

    	wmi_tc_cmds_reply_event(dev->wmi, cmdStreamLen, CMD_TXSTATUSRSP, (A_INT8*)rCmdStream);
    }
}

void txStatusHandler (void *parms)
{
	CMD_TXSTATUS_PARMS *pParms = (CMD_TXSTATUS_PARMS *)parms;
    A_UINT32 numOfReports=0;
    A_UINT32 i;
    A_UINT8 *replyBuf = &dataPayload[0];
    wlan_tcmd_dev_t *dev = &utf_dev;

    // if we need report then we send
    // cont_tx_off first and then
    // send the report
    // otherwise.. we just send the response
    // first and then handle cont_tx_off
    if (pParms->needReport)
    {
    	if (pParms->stopTx)
    	{
    		tx_tcmdParms.mode = TCMD_CONT_TX_OFF;
    		tcmd_cont_tx_cmd (dev, &tx_tcmdParms);
    	}
    	if (tx_tcmdParms.numPackets) {
			for (i=0;i<tcmdLinkTRx.totalToTx;i++)
			{
				if (txDataStatsReport(i, 0, replyBuf)) {
					numOfReports++;
					break;/* return one report at a time */
				}
			}
    	}
        tlv2SendTxStatus(dev, pParms->phyId, numOfReports, replyBuf);
    }
    else
    {
        tlv2SendTxStatus(dev, pParms->phyId, numOfReports, replyBuf);
        if (pParms->stopTx)
        {
        	tx_tcmdParms.mode = TCMD_CONT_TX_OFF;
        	tcmd_cont_tx_cmd (dev, &tx_tcmdParms);
        }
    }
}

void tlv2SendRxRsp(wlan_tcmd_dev_t *dev, A_UINT8 phyId, A_UINT8 status, A_UINT8 rxMode)
{
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 i, j;
    A_UINT32 shortGuard[2], shortGuard11AC[5];
    A_UINT32 rateMask[2] = {0};
    A_UINT32 rate11ACMask[5] = {0};
    A_UINT32 rateCnt[69] = {0};
    A_UINT16 *rxReportCnt;
    TCMD_CONT_RX *contRx = &rx_tcmdParms;

	A_PRINTF("tlv2SendRxRsp status %d, sndrpt %d\n", status, (rxMode == TCMD_CONT_RX_REPORT));
    tlv2CreateCmdHeader(CMD_RXRSP);
    tlv2AddParms (6, PARM_PHYID, phyId, PARM_STATUS, status, PARM_RXMODE, rxMode);

    if ((status != CMD_OK) || (rxMode != TCMD_CONT_RX_REPORT))
    {
	    pCmdStream = tlv2CompleteCmdRsp();
	    if (pCmdStream)
	    {
	    	cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
	    	rCmdStream = (A_UINT8 *)pCmdStream;

	    	wmi_tc_cmds_reply_event(dev->wmi, cmdStreamLen, CMD_RXRSP, (A_INT8*)rCmdStream);
	    }
	    return;
    }


	A_PRINTF("totalPkt %d rssInDm %d crcErrPkt %d secErrPkt %d\n",contRx->u.report.totalPkt,
			   contRx->u.report.rssiInDBm,contRx->u.report.crcErrPkt,contRx->u.report.secErrPkt);

    rxReportCnt = (A_UINT16 *)&report_Static[0];//(A_UINT16 *)A_ALLOCRAM(250 * sizeof(A_UINT16));
	memset(rxReportCnt, 0, (222 * sizeof(A_UINT16)));

    setRates4Report(contRx, shortGuard, shortGuard11AC, &rateMask[0], &rateMask[1], rate11ACMask, &rate11ACMask[4]);

    tlv2AddParms (24, PARM_TOTALPACKETS, contRx->u.report.totalPkt,
    				PARM_RSSIINDBM1, contRx->u.report.rssiInDBm,
    				PARM_CRCPACKETS, contRx->u.report.crcErrPkt,
    				PARM_SECERRPKT, contRx->u.report.secErrPkt,
    				PARM_RATEMASK, 2, 0, rateMask,
    				PARM_RATEMASK11AC, 5, 0, rate11ACMask,
    				PARM_RATESHORTG, 2, 0, shortGuard,
    				PARM_RATESHORTG11AC, 5, 0, shortGuard11AC);

    j = 0;
	for(i = 0; i < 32; i++)
	{
		rateCnt[i] = (rxReportCnt[j+1] << 16) | rxReportCnt[j];
		j = j+2;
	}
	tlv2AddParms (4, PARM_RATECNT, 32, 0, rateCnt);

	j = 64;
	for(i = 0; i < 54; i++) {
		rateCnt[i] = rxReportCnt[j+1] << 16 | rxReportCnt[j];
		j = j + 2;
	}

	j = 192;   // 172;
	for(i = 54; i < 69; i++) {
		rateCnt[i] = rxReportCnt[j+1] << 16 | rxReportCnt[j];
		j = j + 2;
	}
	tlv2AddParms (4, PARM_RATECNT11AC, 69, 0, rateCnt);

    pCmdStream = tlv2CompleteCmdRsp();
    if (pCmdStream)
    {
    	cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    	rCmdStream = (A_UINT8 *)pCmdStream;

    	wmi_tc_cmds_reply_event(dev->wmi, cmdStreamLen, CMD_RXSTATUSRSP, (A_INT8*)rCmdStream);
    }
}

void rxHandler (void *parms)
{
	CMD_RX_PARMS *pParms  = (CMD_RX_PARMS *)parms;
	_CMD_RX_PARMS *pRxParms = (_CMD_RX_PARMS *)&_cmdParms;
	_CMDPROC_RC rc;
    A_UINT8 status = CMD_OK;
    wlan_tcmd_dev_t *dev = &utf_dev;

	A_PRINTF("tlv2 rxHandler 0x%x\n", (A_UINT32)parms);
	A_MEMSET(pRxParms, 0, sizeof(_CMD_ALL_PARMS));

    pRxParms->channel = pParms->freq;
    pRxParms->rxMode = pParms->rxMode;
    pRxParms->enANI = pParms->enANI;
    pRxParms->antenna = pParms->antenna;
    pRxParms->wlanMode = pParms->wlanMode;
    pRxParms->rxChain = pParms->chainMask;
    pRxParms->expectedPkts = pParms->expectedPkts;
    pRxParms->ack = pParms->ack;
    pRxParms->bc = pParms->broadcast;
    pRxParms->bandwidth = pParms->bandwidth;
    pRxParms->lpl = pParms->lpl;
    pRxParms->antswitch1 = pParms->antswitch1;
    pRxParms->antswitch2 = pParms->antswitch2;
    A_MEMCPY(pRxParms->addr, pParms->staAddr, ATH_MAC_LEN);
    A_MEMCPY(pRxParms->bssid, pParms->bssid, ATH_MAC_LEN);
    A_MEMCPY(pRxParms->btaddr, pParms->btAddr, ATH_MAC_LEN);
    pRxParms->regDmn[0] = pParms->regDmn[0];
    pRxParms->regDmn[1] = pParms->regDmn[1];
    pRxParms->otpWriteFlag = pParms->otpWriteFlag;

    pRxParms->flags = pParms->flags;
    pRxParms->rateMask[0] = pParms->rateMask[0];
    pRxParms->rateMask[1] = pParms->rateMask[1];
    pRxParms->rateMask[2] = pParms->rateMask11AC[0];
    pRxParms->rateMask[3] = pParms->rateMask11AC[1];
    pRxParms->rateMask[4] = pParms->rateMask11AC[2];
    pRxParms->rateMask[5] = pParms->rateMask11AC[3];
    pRxParms->rateMask6 = pParms->rateMask11AC[4];
    pRxParms->spectralScan = pParms->spectralScan;
    pRxParms->noiseFloor = pParms->noiseFloor;

    rc = rxCmdProcessor_common((_CMD_ALL_PARMS *)pRxParms, pRxParms->expectedPkts, EVT_RX_AVAIL, TRUE);

    if (rc != CMDPROC_RC_ASYNC)
    {
    	status = 0xff;
    }
    tlv2SendRxRsp(dev, pParms->phyId, status, pParms->rxMode);
    setRxNotifyInfo(pRxParms->expectedPkts, EVT_RX_AVAIL);
}

void tlv2SendRxStatus(wlan_tcmd_dev_t *dev, A_UINT8 phyId, A_UINT32 numOfReports, A_UINT8 *replyBuf)
{
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    RX_STATS_STRUCT_UTF *pRxStats;
    A_UINT8 status = CMD_OK;

    pRxStats = (RX_STATS_STRUCT_UTF*)replyBuf;

    tlv2CreateCmdHeader(CMD_RXSTATUSRSP);
    tlv2AddParms (6, PARM_PHYID, phyId, PARM_STATUS, status, PARM_NUMOFREPORTS, numOfReports);
    if (numOfReports)
    {
    	tlv2AddParms(48, PARM_TOTALPACKETS, pRxStats->totalPackets,
    					PARM_GOODPACKETS, pRxStats->goodPackets,
    					PARM_OTHERERROR, pRxStats->otherError,
    					PARM_CRCPACKETS, pRxStats->crcPackets,
    					PARM_DECRYPERRORS, pRxStats->decrypErrors,
    					PARM_RATEBIT, pRxStats->rateBit,
    					PARM_STARTTIME, pRxStats->startTime,
    					PARM_ENDTIME, pRxStats->endTime,
    					PARM_BYTECOUNT, pRxStats->byteCount,
    					PARM_DONTCOUNT, pRxStats->dontCount,
    					PARM_RSSI, pRxStats->rssi,
    					PARM_RSSIC, MCHAIN_UTF, 0, pRxStats->rssic,
    					PARM_RSSIE, MCHAIN_UTF, 0, pRxStats->rssie,
    					PARM_BADRSSI, pRxStats->badrssi,
    					PARM_BADRSSIC, MCHAIN_UTF, 0, pRxStats->badrssic,
    					PARM_BADRSSIE, MCHAIN_UTF, 0, pRxStats->badrssie,
    					PARM_EVM, MCHAIN_UTF, 0, pRxStats->evm,
    					PARM_BADEVM, MCHAIN_UTF, 0, pRxStats->badevm);
    }
    pCmdStream = tlv2CompleteCmdRsp();
    if (pCmdStream)
    {
    	cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    	rCmdStream = (A_UINT8 *)pCmdStream;

    	wmi_tc_cmds_reply_event(dev->wmi, cmdStreamLen, CMD_RXSTATUSRSP, (A_INT8*)rCmdStream);
    }
}

void rxStatusHandler (void *parms)
{
	CMD_RXSTATUS_PARMS *pParms  = (CMD_RXSTATUS_PARMS *)parms;
    TCMD_CONT_RX        tcmdRxParms;
    A_UINT32            numOfReports=0;
    A_UINT8 *replyBuf = &dataPayload[0];
    wlan_tcmd_dev_t *dev = &utf_dev;
    //A_UINT32            i;
#if 0
    /* return report */
    for (i = 0; i < TCMD_MAX_RATES; i++)
    {
        if (rxDataStatsReport(i, replyBuf))
        {
            numOfReports++;
            break;/* return one report at the time */
        }
    }
#endif
    //if (pParms->stopRx)
    //{
    	tcmdRxParms.act = TCMD_CONT_RX_REPORT;
    	tcmd_cont_rx_cmd(dev, &tcmdRxParms);
    //}
    tlv2SendRxStatus(dev, pParms->phyId, numOfReports, replyBuf);
}

void hwCalPre(A_UINT32 resetCause, A_BOOL bHomeChan) {
#if !defined(FPGA)
    whalPreCal(resetCause, bHomeChan);
    whalIQCalIni();
#endif
}

void hwCalPost(A_UINT32 resetCause, A_BOOL bHomeChan, A_UINT8 doNoiseFloorCal) {
#if !defined(FPGA)
    whalPostCal(resetCause, bHomeChan);
    if (whalPostCalSetReg)
        whalPostCalSetReg();
    else
        A_PRINTF_ALWAYS("whalPostCalSetReg is NULL \n");

    A_DELAY_USECS(1000);
    if (doNoiseFloorCal) {
        whalNfLoadCal();
        A_DELAY_USECS(400);
        whalNfStartCal();
    }
#endif
}


void hwCalHandler (void *parms)
{
	CMD_HWCAL_PARMS *pParms  = (CMD_HWCAL_PARMS *)parms;
    A_UINT32 status = CMD_OK;
    A_UINT32 resetCause = 0;
    A_BOOL bHomeChan = TRUE; //what should it be?
    A_UINT8 num_of_iteration;

    A_PRINTF_ALWAYS("tlv2 hwCalHandler\n");
    A_PRINTF_ALWAYS("Params: saveCal = %d; loopCnt = %d; NFC = %d\n", pParms->saveCal, pParms->loopCnt, pParms->noiseFloorCal);

    num_of_iteration = pParms->loopCnt;

    switch (pParms->calOp)
    {
		case HWCALOP_FULL_WHAL_RESET_CAL:
			A_PRINTF("HWCALOP_FULL_WHAL_RESET_CAL\n");
			break;
		case HWCALOP_WHAL_RESET_PART_1:
			A_PRINTF("HWCALOP_WHAL_RESET_PART_1\n");
			break;
		case HWCALOP_HW_RESET:
			A_PRINTF("HWCALOP_HW_RESET\n");
			break;
		case HWCALOP_PROGRAM_INI_TABLES:
			A_PRINTF("HWCALOP_PROGRAM_INI_TABLES\n");
			break;
		case HWCALOP_WHAL_RESET_PART_2:
			A_PRINTF("HWCALOP_WHAL_RESET_PART_2\n");
			break;
        case HWCALOP_FULL_CAL:
#ifndef FPGA
            A_PRINTF_ALWAYS("HWCALOP_FULL_CAL\n");
            if (whalDoFullCal) {
                whalDoFullCal(resetCause, bHomeChan);
            }
            else
                A_PRINTF_ALWAYS("whalDoFullCal is NULL!!!\n");
#endif
            break;
        case HWCALOP_RXDCO:
            //status = utfCalRxDco(num_of_chains,pBuf);
            A_PRINTF_ALWAYS("HWCALOP_RXDCO\n");

            hwCalPre(resetCause, bHomeChan);

            status = whalDoRxDcoCal(FALSE, 1); //(loopback = FALSE, osdac = 1)

            if (status == WHAL_RX_DC_CAL_PASS)
            {
                A_PRINTF_ALWAYS("status = %d: RxDco Cal SUCEEDED\n", status);

                if (bHomeChan && pParms->saveCal)
                {
                    if (whalDoRxDcoCalSaveAllChains)
                        whalDoRxDcoCalSaveAllChains();
                }

            }
            else
                A_PRINTF_ALWAYS("RxDco Cal failed\n");

            hwCalPost(resetCause, bHomeChan, pParms->noiseFloorCal);

            break;
        case HWCALOP_RXFILT:
            //status = utfCalRxFilt(num_of_chains,pBuf);
            A_PRINTF_ALWAYS("HWCALOP_RXFILT\n");

            hwCalPre(resetCause, bHomeChan);

            status = whalDoRxFiltCal();
            if (status == WHAL_RXFILT_CAL_PASS) {
                A_PRINTF_ALWAYS("Suceeded: status = %d\n", status);
                if (bHomeChan && pParms->saveCal)
                    whalDoRxFiltCalSave();
            }
            else
                A_PRINTF_ALWAYS("Failed: status = %d\n", status);

            hwCalPost(resetCause, bHomeChan, pParms->noiseFloorCal);

            break;
        case HWCALOP_RXIQ:
            //status = utfCalRxIQ(num_of_chains,pBuf);
            A_PRINTF_ALWAYS("HWCALOP_RXIQ\n");

            hwCalPre(resetCause, bHomeChan);

            status = whalRxIQCal(num_of_iteration);
            if (status == WHAL_RX_CAL_PASS) {
                A_PRINTF_ALWAYS("Suceeded: status = %d\n", status);
                if (bHomeChan && pParms->saveCal)
                    whalDoRxIQCalSave();
            }
            else
                A_PRINTF_ALWAYS("Failed: status = %d\n", status);

            hwCalPost(resetCause, bHomeChan, pParms->noiseFloorCal);

            break;
        case HWCALOP_TXIQ:
            //status = utfCalTxIQ(num_of_chains,pBuf);
            A_PRINTF_ALWAYS("HWCALOP_TXIQ\n");

            hwCalPre(resetCause, bHomeChan);

            status = whalTxIQCal(num_of_iteration);
            if (status == WHAL_TX_CAL_PASS) {
                A_PRINTF_ALWAYS("Suceeded: status = %d\n", status);
                if (bHomeChan && pParms->saveCal)
                    whalDoTxIQCalSave();
            }
            else
                A_PRINTF_ALWAYS("Failed: status = %d\n", status);

            hwCalPost(resetCause, bHomeChan, pParms->noiseFloorCal);

            break;
        case HWCALOP_TXCL:
            //status = utfCalTxCl(num_of_chains,pBuf);
            A_PRINTF_ALWAYS("HWCALOP_TXCL\n");

            hwCalPre(resetCause, bHomeChan);

            status = whalDoTxClCal(num_of_iteration);
            if (status == WHAL_CL_CAL_PASS) {
                A_PRINTF_ALWAYS("Suceeded: status = %d\n", status);
                if (bHomeChan && pParms->saveCal)
                    whalDoTxClCalSave();
            }
            else
                A_PRINTF_ALWAYS("Failed: status = %d\n", status);

            hwCalPost(resetCause, bHomeChan, pParms->noiseFloorCal);

            break;
        case HWCALOP_PKDET:
            //status = utfCalPkDet(num_of_chains,pBuf);
            A_PRINTF_ALWAYS("HWCALOP_PKDET\n");

            hwCalPre(resetCause, bHomeChan);

            status = whalDoPkDetCal();
            if (status == WHAL_PKDET_CAL_PASS) {
                A_PRINTF_ALWAYS("Suceeded: status = %d\n", status);
                if (bHomeChan && pParms->saveCal)
                    whalDoPkDetCalSave();
            }
            else
                A_PRINTF_ALWAYS("Failed: status = %d\n", status);

            hwCalPost(resetCause, bHomeChan, pParms->noiseFloorCal);

            break;
        case HWCALOP_WHAL_RESET_PART_3:
            A_PRINTF_ALWAYS("HWCALOP_WHAL_RESET_PART_3\n");

            break;
        case HWCALOP_NOISEFLOOR:
            A_PRINTF_ALWAYS("HWCALOP_NOISEFLOOR\n");
            whalNfLoadCal();
            A_DELAY_USECS(400);
            whalNfStartCal();

            break;
        case HWCALOP_DPD:
            A_PRINTF_ALWAYS("HWCALOP_DPD\n");

            break;
        case HWCALOP_LNA:
            A_PRINTF_ALWAYS("HWCALOP_LNA\n");

            break;
        default:
            break;
    }

    sendBasicRsp (CMD_HWCAL, pParms->phyId, status);
}

void noiseFloorReadHandler(void *param)
{
    CMD_NOISEFLOORREAD_PARMS *pParms = (CMD_NOISEFLOORREAD_PARMS *)param;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 ch_idx = 0;
    A_UINT32 wlanMode = TCMD_WLAN_MODE_VHT20;
    WHAL_CHANNEL chan;
    A_INT32 nf[16];
    A_BOOL chain_enable[16] = {0};
    A_INT32 temp;
    A_UINT32 cca[] = {
            PHY_BB_CCA_B0_ADDRESS,
    #if (WHAL_RX_NUM_CHAIN > 1)
            PHY_BB_CCA_B1_ADDRESS,
    #endif
    #if (WHAL_RX_NUM_CHAIN > 2)
            PHY_BB_CCA_B2_ADDRESS,
    #endif
    #if (WHAL_RX_NUM_CHAIN > 3)
            PHY_BB_CCA_B3_ADDRESS,
    #endif
    };
  
    if(pParms->chainMask == 1)
    {
        //Enable chain 1
        chain_enable[0] = 1;

    }
    else if(pParms->chainMask == 2)
    {
        //Enable chain 2
        chain_enable[1] = 1;
    }
    else if(pParms->chainMask == 3)
    {
        //Enable chain 1,2
        chain_enable[0] = 1;
        chain_enable[1] = 1;
    }
    else if(pParms->chainMask == 4)
    {
        //Enable chain 3
        chain_enable[2] = 1;
    }
    else if(pParms->chainMask == 5)
    {
        //Enable chain 1,3
        chain_enable[0] = 1;
        chain_enable[2] = 1;
    }
    else if(pParms->chainMask == 6)
    {
        //Enable chain 2,3
        chain_enable[1] = 1;
        chain_enable[2] = 1;
    }
    else if(pParms->chainMask == 7)
    {
        //Enable chain 1,2,3
        chain_enable[0] = 1;
        chain_enable[1] = 1;
        chain_enable[2] = 1;
    }
    else if(pParms->chainMask == 8)
    {
        //Enable chain 4
        chain_enable[3] = 1;
    }
    else if(pParms->chainMask == 9)
    {
        //Enable chain 1,4
        chain_enable[0] = 1;
        chain_enable[3] = 1;
    }
    else if(pParms->chainMask == 10)
    {
       //Enable chain 2,4
       chain_enable[1] = 1;
       chain_enable[3] = 1;
    }
    else if(pParms->chainMask == 11)
    {
       //Enable chain 1,2,4
       chain_enable[0] = 1;
       chain_enable[1] = 1;
       chain_enable[3] = 1;
    }
    else if(pParms->chainMask == 12)
    {
       //Enable chain 3,4
       chain_enable[2] = 1;
       chain_enable[3] = 1;
    }
    else if(pParms->chainMask == 13)
    {
       //Enable chain 1,3,4
       chain_enable[0] = 1;
       chain_enable[1] = 1;
       chain_enable[3] = 1;
    }
    else if(pParms->chainMask == 14)
    {
       //Enable chain 2,3,4
       chain_enable[1] = 1;
       chain_enable[2] = 1;
       chain_enable[3] = 1;
    }
    else if(pParms->chainMask == 15)
    {
        //Enable chain 1,2,3,4
        chain_enable[0] = 1;
        chain_enable[1] = 1;
        chain_enable[2] = 1;
        chain_enable[3] = 1;
    }

    tcmd_get_channel(pParms->freq, wlanMode, 0, &chan, pParms->freq);
    // do full phy reset
    whalReset(&chan, 0, WHAL_RESTORE_SW_SETTINGS, WHAL_RESET_CAUSE_FULL_RESET);

    /* read the noise floor value from register */
    for (ch_idx = 0; ch_idx < NUM_MAX_CHAINS; ch_idx++)
    {
        if(chain_enable[ch_idx] == 1 && (ch_idx < (sizeof(cca)/sizeof(cca[0]))))
        {
              if ((OS_REG_READ(PHY_BB_AGC_CONTROL_ADDRESS) & PHY_BB_AGC_CONTROL_DO_NOISEFLOOR_MASK) == 0)
              {
                   temp = nf[ch_idx] = MS(OS_REG_READ(cca[ch_idx]), PHY_BB_CCA_B0_MINCCAPWR_0);
                   if (temp & 0x100) temp = temp | (A_UINT32)0xFFFFFF00;
                   if (temp == PHY_CCA_MAX_GOOD_VAL)
                   {
                         /* This is the case when NF Could not converge due to high Interference but HW clears the NF cal complete bit */
					     nf[ch_idx] = 0;
				   }
				   // If negative say -100, it will be encoded as 0x10000064, if positive say 100, it will be decoded as 0x00000064
				   if(temp < 0)
				   {
					   nf[ch_idx] = ((0 - temp) | 0x10000000);
				   }
			  }
			  else
			  {
				  /*Request to return 0 if NF CAL does not converge during the dwell time for host to handle further ?*/
				  nf[ch_idx] = 0;
			  }

		}
		else
        {
               nf[ch_idx] = DEFAULT_NF_VALUE_NON_SUPPORTED_CHAIN; 
        }

    }

    pCmdStream = createCmdRsp(CMD_NOISEFLOORREADRSP, 2, PARM_NFVALUES, nf);

    if (pCmdStream)
    {
           cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
           rCmdStream = (A_UINT8 *)pCmdStream;

           wmi_tc_cmds_reply_event(utf_dev.wmi, cmdStreamLen, CMD_NOISEFLOORREADRSP, (A_INT8*)rCmdStream);
    }
    return;
}
 
//SRAM_TEXT
void initCmdProcessTlv2()
{
    registerREGREADHandler (regReadHandler);
    registerREGWRITEHandler (regWriteHandler);
    registerTXHandler (txHandler);
    registerTXSTATUSHandler (txStatusHandler);
    registerRXHandler (rxHandler);
    registerRXSTATUSHandler (rxStatusHandler);
    registerHWCALHandler (hwCalHandler);
    registerMEMWRITEHandler(memWriteHandler);
    registerMEMREADHandler(memReadHandler);
    initLMGOHandler();
    initLMTXInitHandler();
    initLMQueryHandler();
    initLMChannelListHandler();
    initLMRXInitHandler();
    registerNOISEFLOORREADHandler (noiseFloorReadHandler);
}
