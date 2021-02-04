/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
#include "ListModeCommon.h"
extern TCMD_CONT_RX rx_tcmdParms;
extern wlan_tcmd_dev_t utf_dev;
extern int g_listmode;

void send2HostLMRxInitRsp(wlan_tcmd_dev_t *dev,  A_UINT8 status)
{
#ifndef FPGA
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 tmpParaLen = 4;
    A_UINT32 tmpCmdCode = CMD_LMRXINITRSP;

	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
                                                                                                    PARM_CMDID, CMD_LMRXINIT,
                                                                                                    PARM_STATUS, status);

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(dev->wmi, cmdStreamLen, tmpCmdCode, (A_INT8*)rCmdStream);
#endif
    return;
}


static void lmSetupRxParms(CMD_LMRXINIT_PARMS *pParms, TCMD_CONT_RX *tcmdParms)
{
    memset(tcmdParms, 0, sizeof(TCMD_CONT_RX));
    tcmdParms->act           = pParms->rxMode;
    tcmdParms->enANI         = pParms->enANI;
    tcmdParms->u.para.antenna  = pParms->antenna;
    tcmdParms->u.para.bandwidth = pParms->bandwidth;
    tcmdParms->u.para.bc = pParms->broadcast;
    tcmdParms->u.para.ack = pParms->ack;
    tcmdParms->u.para.lpl = pParms->lpl;
    if ( tcmdParms->act == TCMD_CONT_RX_SET_ANT_SWITCH_TABLE ) {
        tcmdParms->u.antswitchtable.antswitch1 = pParms->antswitch1;
        tcmdParms->u.antswitchtable.antswitch2 = pParms->antswitch2;
    }

    if (tcmdParms->act  == TCMD_CONT_RX_SETMAC) {
        A_MEMCPY((void*)&(tcmdParms->u.mac.addr[0]), (void*)&(pParms->staAddr[0]), ATH_MAC_LEN);
        A_MEMCPY((void*)&(tcmdParms->u.mac.bssid[0]), (void*)&(pParms->bssid[0]), ATH_MAC_LEN);
        A_MEMCPY((void*)&(tcmdParms->u.mac.btaddr[0]), (void*)&(pParms->btAddr[0]), ATH_MAC_LEN);
    }

    return;
}


void LMTLV2RxInitHandler (void *parms)
{
	CMD_LMRXINIT_PARMS *pParms  = (CMD_LMRXINIT_PARMS *)parms;

    lmSetupRxParms(pParms, &rx_tcmdParms);

    if (pParms->rxMode == TCMD_CONT_RX_PROMIS)
        send2HostLMRxInitRsp(&utf_dev,  0);
    else
        send2HostLMRxInitRsp(&utf_dev,  1);
    g_listmode = 1;
}

// Init LMHWCal  module
SRAM_TEXT
void initLMRXInitHandler(void)
{
    registerLMRXINITHandler(LMTLV2RxInitHandler);
    return;
}

