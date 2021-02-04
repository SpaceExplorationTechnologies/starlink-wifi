/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#include "tlv2Inc.h"
#include "halphy_internal.h"
//#include "hal_tcmd.h"
#include "wmi_tcmd.h"
#include "tcmdHostInternal.h"
#include "utf_dev.h"
#include "testcmd.h"
#include "utf.h"
//#include "cmdRspParmsDict.h"
//#include "cmdRspParmsInternal.h"
//#include "tlv2Api.h"
#include "tcmd_api.h"
#include "cmdGenericUtfCmdHandler.h"
#include "genericUtfCmd.h"
#include "secGlutCal.h"

extern wlan_tcmd_dev_t utf_dev;

/* -------------------------------------------------
 * FUNCTION:  genericUtfCmd()
 *
 * NOTE:
 *      Generic UTF command
 * --------------------------------------------------
 */

SRAM_TEXT
void genericUtfCmd(void *pParm)
{
    A_UINT32 				tmpCmdCode;
	int 					tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 				*rCmdStream = NULL;
    A_UINT32 				cmdStreamLen = 0;

    CMD_GENERICUTFCMDRSP_PARMS rspParams;
#ifndef FPGA
    CMD_GENERICUTFCMD_PARMS* 	cmdParm;
    cmdParm = (CMD_GENERICUTFCMD_PARMS*)pParm;
	A_CHAR  dbgMsg[24];
	A_UINT8  dbgMsgSize;

    switch (cmdParm->GenericUtfCmdID){

    	case GENERICUTFCMD_ID_SECGLUTCAL:
			secGlutCalSM(&rspParams);
			break;

		default:
			dbgMsgSize = 20;
			rspParams.NumGenericUtfCmdRetData = 5 + dbgMsgSize;
			A_MEMSET(rspParams.GenericUtfCmdRetData,0,sizeof(rspParams.GenericUtfCmdRetData));
			A_STRNCPY(dbgMsg," CmdId Not Supported",dbgMsgSize);
			A_MEMCPY(&rspParams.GenericUtfCmdRetData[5],dbgMsg,dbgMsgSize);

			rspParams.GenericUtfCmdStatus = GENERICUTFCMD_STATUS_FAILURE;
			rspParams.GenericUtfCmdDone = GENERICUTFCMD_DONE;
			break;
    }


#endif
	tmpCmdCode = CMD_GENERICUTFCMDRSP;
	tmpParaLen = 10;
	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
			PARM_GENERICUTFCMDDONE, rspParams.GenericUtfCmdDone,
			PARM_GENERICUTFCMDSTATUS, rspParams.GenericUtfCmdStatus,
			PARM_NUMGENERICUTFCMDRETDATA, rspParams.NumGenericUtfCmdRetData,
			PARM_GENERICUTFCMDRETDATA, rspParams.NumGenericUtfCmdRetData, 0, &rspParams.GenericUtfCmdRetData
			 );

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);

}


// Init Get Target Power module
SRAM_TEXT
void initGenericUtfCmd(void)
{
	registerGENERICUTFCMDHandler(genericUtfCmd);
    return;
}


