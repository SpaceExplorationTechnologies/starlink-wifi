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
#include "setRegDmn.h"
#include "cmdSetRegDmn.h"
#ifndef FPGA
#include "ar6000_eeprom.h"
extern AR6000_EEPROM_STRUCT eepromStruct;
#endif

extern wlan_tcmd_dev_t utf_dev;

/* -------------------------------------------------
 * FUNCTION:  setRegDmn()
 *
 * NOTE:
 *      Set the regulatory domain in memory
 * --------------------------------------------------
 */

SRAM_TEXT
void setRegDmn(void *pParm)
{
    A_UINT32 tmpCmdCode;
	int tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;

#ifndef FPGA
    CMD_SETREGDMN_PARMS *regDmnParams = pParm;
    AR6000_EEPROM_STRUCT *pEepromStruct=&eepromStruct;
    BASE_EEP_HEADER *pBaseEepHeader;
    pBaseEepHeader = &pEepromStruct->pEeprom->baseEepHeader;

    pBaseEepHeader->regDmn[0] = regDmnParams->regDmn[0];
    pBaseEepHeader->regDmn[1] = regDmnParams->regDmn[1];

#endif
	tmpCmdCode = CMD_SETREGDMNRSP;
	tmpParaLen = 0;
	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen
			 );

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);
}


// Init Get DPD complete module
SRAM_TEXT
void initSetRegDmn(void)
{
	registerSETREGDMNHandler(setRegDmn);
    return;
}

