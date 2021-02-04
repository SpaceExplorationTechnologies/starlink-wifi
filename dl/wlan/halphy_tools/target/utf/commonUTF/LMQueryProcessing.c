/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
#include "ListModeCommon.h"
extern A_BOOL gDPDCalDoneLM;
extern A_BOOL gLMTxDone;
extern wlan_tcmd_dev_t utf_dev;

SRAM_TEXT
void send2HostLMQueryRsp(wlan_tcmd_dev_t *dev,  A_UINT16	cmdId, A_UINT8 status)
{

#ifndef FPGA
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 tmpParaLen = 4;
    A_UINT32 tmpCmdCode = CMD_LMQUERYRSP;

	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
                                                                                                    PARM_LM_CMDID, cmdId,
                                                                                                    PARM_STATUS, status);

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(dev->wmi, cmdStreamLen, tmpCmdCode, (A_INT8*)rCmdStream);
#endif
    return;
}

SRAM_TEXT
void LMTLV2QueryHandler (void *pParms)
{
    A_UINT8 status = LMGO_OK;
   CMD_LMQUERY_PARMS *pLMQUERYParms = (CMD_LMQUERY_PARMS *)pParms;

    A_PRINTF_ONCE("Query --> lm_cmdId =%d\n",  pLMQUERYParms->lm_cmdId);
    if (pLMQUERYParms->lm_cmdId == PARM_LM_CMDID_TX)
    {
        if (gLMTxDone) status = 0;
        else status = 1;
    }

    if (pLMQUERYParms->lm_cmdId == PARM_LM_CMDID_HWCAL)
    {
        if (gDPDCalDoneLM) status = 0;
        else status = 1;
    }
    send2HostLMQueryRsp(&utf_dev,  pLMQUERYParms->lm_cmdId,  status);

    return;
}

// Init LMHWCal  module
SRAM_TEXT
void initLMQueryHandler(void)
{
    registerLMQUERYHandler(LMTLV2QueryHandler);

    return;
}

