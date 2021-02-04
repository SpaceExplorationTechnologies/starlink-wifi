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
#include "cmdCustOtpSpaceGetSize.h"
#include "cmdCustOtpSpaceRead.h"
#include "cmdCustOtpSpaceWrite.h"
#include "custOTPCmds.h"
#include <otpstream_api.h>
#include <otpstream_id.h> /* replaces local SECTION_ID definitions */
#include <efuse_api.h>

extern wlan_tcmd_dev_t utf_dev;

/* -------------------------------------------------
 * FUNCTION:  getCustOtpSize()
 *
 * NOTE:
 *      Get Customer Otp Size
 * --------------------------------------------------
 */

SRAM_TEXT
void getCustOtpSize(void *pParm)
{
#ifndef FPGA
    A_UINT32 tmpCmdCode;
	int tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;

	tmpCmdCode = CMD_GETCUSTOTPSIZERSP;
	tmpParaLen = 2;
	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
	         PARM_OTPCUSTSIZE, CUSTOMER_OTP_SIZE
			 );

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);
#endif
}


// Init Cust Otp  module
SRAM_TEXT
void initGetCustOtpSize(void)
{
	registerGETCUSTOTPSIZEHandler(getCustOtpSize);
    return;
}

#if 1
/* -------------------------------------------------
 * FUNCTION:  readCustOtpSpace()
 *
 * NOTE:
 *      Read Customer Otp Space
 * --------------------------------------------------
 */

SRAM_TEXT
void readCustOtpSpace(void *pParm)
{
#ifndef FPGA
    A_UINT32 tmpCmdCode;
	int tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT8 replyBuf[CUSTOMER_OTP_SIZE];

    efuse_enable_read();
    efuse_read(CUSTOMER_OTP_OFFSET, (A_UCHAR *)&replyBuf, CUSTOMER_OTP_SIZE);
    efuse_disable();

	tmpCmdCode = CMD_READCUSTOTPSPACERSP;
	tmpParaLen = 4;

	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
	         PARM_CUSTDATA, CUSTOMER_OTP_SIZE,0, &replyBuf
			 );

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);
#endif
}


// Init Cust Otp  module
SRAM_TEXT
void initReadCustOtpSpace(void)
{
	registerREADCUSTOTPSPACEHandler(readCustOtpSpace);
    return;
}


/* -------------------------------------------------
 * FUNCTION:  writeCustOtpSpace()
 *
 * NOTE:
 *      Write Customer Otp Space
 * --------------------------------------------------
 */

SRAM_TEXT
void writeCustOtpSpace(void *pParm)
{
#ifndef FPGA
    A_UINT32 tmpCmdCode;
	int tmpParaLen,writeStatus;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    CMD_WRITECUSTOTPSPACE_PARMS *writeParams = pParm;
    A_STATUS status;
    A_UINT32 nbytes,otpAddr;

    otpAddr = writeParams->offsetAddr + CUSTOMER_OTP_OFFSET;

	if (writeParams->offsetAddr > CUSTOMER_OTP_SIZE-1)
		writeStatus = 1;
	else if (writeParams->custDataSize > (CUSTOMER_OTP_SIZE - writeParams->offsetAddr))
		writeStatus = 1;
	else if (writeParams->custDataSize > CUSTOMER_OTP_SIZE)
		writeStatus = 1;
	else{
		efuse_enable_write();
		status = efuse_write(otpAddr, writeParams->custData,writeParams->custDataSize, &nbytes);
		efuse_disable();
		if (A_OK == status)
			writeStatus = 0;
		else
			writeStatus = 2;
	}

	tmpCmdCode = CMD_WRITECUSTOTPSPACERSP;
	tmpParaLen = 2;

	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
	         PARM_WRITESTATUS, writeStatus
			 );

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);
#endif
}


// Init Cust Otp  module
SRAM_TEXT
void initWriteCustOtpSpace(void)
{
	registerWRITECUSTOTPSPACEHandler(writeCustOtpSpace);
    return;
}

#endif
