/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
#include "ListModeCommon.h"
//extern _CMD_ALL_PARMS _cmdParms;
extern TCMD_CONT_TX tx_tcmdParms;
extern wlan_tcmd_dev_t utf_dev;
extern int g_listmode;
//SRAM_TEXT
void send2HostLMTxInitRsp(wlan_tcmd_dev_t *dev,  A_UINT8 status)
{

#ifndef FPGA
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 tmpParaLen = 4;
    A_UINT32 tmpCmdCode = CMD_LMTXINITRSP;

	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
                                                                                                    PARM_CMDID, CMD_LMTXINIT,
                                                                                                    PARM_STATUS, status);

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(dev->wmi, cmdStreamLen, tmpCmdCode, (A_INT8*)rCmdStream);
#endif
    return;
}


static void lmSetupTxParms(CMD_LMTXINIT_PARMS *pParms, TCMD_CONT_TX *tcmdParms)
{
    memset(tcmdParms,0,sizeof(TCMD_CONT_TX));
    tcmdParms->dutycycle = pParms->dutyCycle;
    tcmdParms->mode = pParms->txMode;
    //tcmdParms->freq = pParms->channel;
    /*tcmdParms->dataRate = pParms->6;  // to be set later
    tcmdParms->txPwr = pParms->14; */
    tcmdParms->antenna = pParms->antenna;
    tcmdParms->enANI = pParms->enANI;
    tcmdParms->scramblerOff = pParms->scramblerOff;
    tcmdParms->aifsn = pParms->aifsn;
    tcmdParms->pktSz = pParms->pktSz;
    tcmdParms->txPattern = pParms->txPattern;
    tcmdParms->shortGuard = pParms->shortGuard;
    tcmdParms->numPackets = pParms->txNumPackets;
    //tcmdParms->wlanMode = pParms->wlanMode;
    tcmdParms->tpcm = pParms->tpcm;

    tcmdParms->miscFlags = pParms->flags;
    tcmdParms->agg = pParms->agg;
    tcmdParms->bandwidth = pParms->bandwidth;/* automatic */
    tcmdParms->broadcast = pParms->broadcast;

    // before pwrGain is extracted, a default value, not really useful
    //tcmdParms->txPwr = DEFAULT_PWRGAIN_BEFORE_PARSED;
    //tcmdParms->dataRate = ATH_RATE_6M;
    tcmdParms->testCmdId = 0;
    tcmdParms->retries = 0; //??

    tcmdParms->gainIdx = (A_UINT8)pParms->gainIdx;
    tcmdParms->dacGain = (A_INT8)pParms->dacGain;
    tcmdParms->paConfig = (A_UINT8)pParms->paConfig;

    A_MEMCPY(tcmdParms->bssid,pParms->bssid,ATH_MAC_LEN);
    A_MEMCPY(tcmdParms->txStation,pParms->txStation,ATH_MAC_LEN);
    A_MEMCPY(tcmdParms->rxStation,pParms->rxStation,ATH_MAC_LEN);

    tcmdParms->nPattern = pParms->nPattern;
    //tcmdParms->freq2 = pParms->channel2;
    A_MEMCPY(tcmdParms->dataPattern,pParms->dataPattern,MPATTERN);

    return;
}


void LMTLV2TxInitHandler (void *parms)
{
	//_CMDPROC_RC rc;
	//CMD_LMTXINIT_PARMS *pParms  = (CMD_LMTXINIT_PARMS *)parms;
    lmSetupTxParms((CMD_LMTXINIT_PARMS *)parms, &tx_tcmdParms);
    send2HostLMTxInitRsp(&utf_dev,  0);
    g_listmode = 1;
#if 0
   // wlan_tcmd_dev_t *dev = (wlan_tcmd_dev_t *)&utf_dev;

    _CMD_TX_PARMS *pTxParms = (_CMD_TX_PARMS *)&_cmdParms;
	A_MEMSET(pTxParms, 0, sizeof(_CMD_ALL_PARMS));

    pTxParms->txMode = pParms->txMode;
    pTxParms->bandwidth = pParms->bandwidth;
	pTxParms->antenna = pParms->antenna;
    pTxParms->enANI = pParms->enANI;
    pTxParms->scramblerOff = pParms->scramblerOff;
    pTxParms->aifsn = pParms->aifsn;
    pTxParms->pktSz = pParms->pktSz;
    pTxParms->txPattern = pParms->txPattern;
    pTxParms->shortGuard = pParms->shortGuard;
    pTxParms->numPackets = pParms->txNumPackets;
    pTxParms->tpcm = pParms->tpcm;
    pTxParms->flags = pParms->flags;
    pTxParms->agg = pParms->agg;
    pTxParms->broadcast = pParms->broadcast;
    A_MEMCPY(pTxParms->bssid, pParms->bssid, ATH_MAC_LEN);
    A_MEMCPY(pTxParms->txStation, pParms->txStation, ATH_MAC_LEN);
    A_MEMCPY(pTxParms->rxStation, pParms->rxStation, ATH_MAC_LEN);

    pTxParms->dutyCycle = pParms->dutyCycle;
    pTxParms->nPattern = pParms->nPattern;

    A_MEMCPY(pTxParms->dataPattern, pParms->dataPattern, MPATTERN);

    pTxParms->gainIdx = pParms->gainIdx;
    pTxParms->dacGain = pParms->dacGain;
    pTxParms->paConfig = pParms->paConfig;
#endif
}

// Init LMHWCal  module
SRAM_TEXT
void initLMTXInitHandler(void)
{
    registerLMTXINITHandler(LMTLV2TxInitHandler);
    //A_INIT_TIMER(&lm_common_complete_timer, lm_tx_complete_handler, NULL);
    return;
}

