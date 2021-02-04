/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#include "tlv2Inc.h"
#include "halphy_internal.h"
#include "wmi_tcmd.h"
#include "tcmdHostInternal.h"
#include "utf_dev.h"
#include "testcmd.h"
#include "utf.h"
#include "tcmd_api.h"
#include "custOTPCmds.h"
#include <otpstream_id.h>

#include "efuse_api.h"
#include "otpstream_api.h"

extern wlan_tcmd_dev_t utf_dev;
A_UINT8 otpData[32];

/* -------------------------------------------------
 * FUNCTION:  commitOtpStream()
 *
 * NOTE:
 *      Write  PCIE stream to OTP
 * --------------------------------------------------
 */
/*
SRAM_TEXT
void commitOtpStream(void *pParm)
{
    A_UINT32 				tmpCmdCode;
	int 					tmpParaLen;
    TESTFLOW_CMD_STREAM_V2  *pCmdStream;
    A_UINT8 				*rCmdStream = NULL;
    A_UINT32 				cmdStreamLen = 0;

	tmpCmdCode = CMD_COMMITOTPSTREAMRSP;
	tmpParaLen = 0;
	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen
			 );

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);
}


// Init Cust Otp  module
SRAM_TEXT
void initCommitOtpStream(void)
{
	registerCOMMITOTPSTREAMHandler(commitOtpStream);
    return;
}
*/

/* -------------------------------------------------
 * FUNCTION:  setPcieConfigParams()
 *
 * NOTE:
 *      Setup PCIE config params
 * --------------------------------------------------
 */

SRAM_TEXT
void setPcieConfigParams(void *pParm)
{
    A_UINT32 				tmpCmdCode;
	int 					tmpParaLen,writeStatus=0;
    TESTFLOW_CMD_STREAM_V2  *pCmdStream;
    A_UINT8 				*rCmdStream = NULL;
    A_UINT32 				cmdStreamLen=0;
#ifndef FPGA
#if defined(CONFIG_OTP_SUPPORT)
    A_STATUS 				status;
#endif
    A_UINT32 idx=0;

    CMD_SETPCIECONFIGPARAMS_PARMS 	*pcieParams = pParm;

    //Header
    otpData[idx++] = OTPSTREAM_ID_PCIE_CONFIG;

    //Meta header
    otpData[idx++] = (((pcieParams->operation+1) & 0xf) << 4) + (pcieParams->size &0xf);

    //Offset Field
    otpData[idx++] = (pcieParams->pcieAddr & 0xff00) >> 8 ;
    otpData[idx++] = pcieParams->pcieAddr & 0xff;

    //Data
    switch(pcieParams->size){
    	case 1:
    		otpData[idx++] = pcieParams->pcieValue & 0xff;
    		break;
    	case 2:
    		otpData[idx++] = (pcieParams->pcieValue & 0xff00) >> 8;
    		otpData[idx++] = (pcieParams->pcieValue & 0xff);
    		break;
    	case 4:
    		otpData[idx++] = (pcieParams->pcieValue & 0xff000000) >> 24;
    		otpData[idx++] = (pcieParams->pcieValue & 0x00ff0000) >> 16;
    		otpData[idx++] = (pcieParams->pcieValue & 0x0000ff00) >> 8;
    		otpData[idx++] = (pcieParams->pcieValue & 0x000000ff);
    		break;
    	default:
    		writeStatus = 1;
    		break;
    }
#if defined(CONFIG_OTP_SUPPORT)
    if (!writeStatus){
		/* read the memory */
		otpstream_reset(OTPSTREAM_WRITE);

		/* write to memory */
		otpstream_reset(OTPSTREAM_WRITE);
		status = otpstream_write(otpData, idx);
		otpstream_fini();

		if (A_OK != status)
			writeStatus = 1;
    }
#endif
#endif
	tmpCmdCode = CMD_SETPCIECONFIGPARAMS;
	tmpParaLen = 2;

	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
	         PARM_WRITESTATUS, writeStatus
			 );

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);
}


// Init Pcie Config  module
SRAM_TEXT
void initSetPcieConfigParams(void)
{
	registerSETPCIECONFIGPARAMSHandler(setPcieConfigParams);
    return;
}

