/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 *
 * Secondary GLUT Self Calibration
 */

#include "tlv2Inc.h"
#include "halphy_internal.h"
//#include "hal_tcmd.h"
#include "wmi_tcmd.h"
#include "tcmdHostInternal.h"
#include "utf_dev.h"
#include "testcmd.h"
#include "utf.h"
#include "ar6000_eeprom.h"
#include "cmdGenericUtfCmdHandler.h"
#include "genericUtfCmd.h"
#include "secGlutCal.h"
#include "codeswap_api.h"

//#define A_PRINTF_ONCE A_CMN(printf._printf)  // lim_debug
#define NUM_SEC_CHAINS WHAL_NUM_CHAINS_SIZE/2

A_UINT8 secGlutState = SECONDARY_GLUT_CAL_STATE_INIT;
A_UINT16 freqList[NUM_CHAN1_FREQ] = {5210,5290,5530,5610,5690,5775};
A_UINT8 chainMaskList[NUM_SEC_CHAINS] = {5,10};
A_UINT8 freqIdxPri = 0;
A_UINT8 freqIdxSec = 0;
A_UINT8 chainMaskIdx = 0;
A_INT16 reqPwr=0;

#if defined(QCA9984)
extern A_BOOL gSecGlutCal;
#endif
extern TCMD_CONT_TX tx_tcmdParms;
extern wlan_tcmd_dev_t utf_dev;
extern AR6000_EEPROM_STRUCT eepromStruct;
A_INT8 gainIndexBiasTable[WHAL_NUM_CHAINS_SIZE/2][NUM_CHAN1_FREQ][NUM_CHAN2_FREQ];

// function prototypes
extern void utfTxStop(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern void tcmd_cont_tx_cmd(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);

SRAM_TEXT
void secGlutCal_runTcmd(A_UINT16 freq1, A_UINT16 freq2, A_UINT8 chainMask,
		                A_UINT8 wlanMode, A_UINT8 rate, A_UINT8 tpcm, A_UINT8 pwr)
{
		unsigned char TLV_TXPARM_QDART_DEFAULT_TXSTATION[ATH_MAC_LEN] = {0x20, 0x22, 0x22, 0x22, 0x22, 0x02};
		unsigned char TLV_TXPARM_QDART_DEFAULT_BSSID[ATH_MAC_LEN]     = {0x50, 0x55, 0x55, 0x55, 0x55, 0x05};

		A_MEMSET(&tx_tcmdParms,0,sizeof(TCMD_CONT_TX));

		tx_tcmdParms.freq = freq1;
		tx_tcmdParms.freq2 = freq2;
		tx_tcmdParms.txChain= chainMask;

		tx_tcmdParms.wlanMode=wlanMode;
		tx_tcmdParms.dataRate=rate;
		tx_tcmdParms.txPwr=pwr;
		tx_tcmdParms.mode=TCMD_CONT_TX_FRAME;
		tx_tcmdParms.pktSz=1500;
		tx_tcmdParms.agg=1;

		tx_tcmdParms.tpcm=tpcm;
		tx_tcmdParms.gainIdx=1;
		tx_tcmdParms.numPackets=1;
		A_MEMCPY((void*)tx_tcmdParms.txStation, TLV_TXPARM_QDART_DEFAULT_TXSTATION, ATH_MAC_LEN);
		A_MEMCPY((void*)tx_tcmdParms.bssid, TLV_TXPARM_QDART_DEFAULT_BSSID, ATH_MAC_LEN);
		tx_tcmdParms.broadcast=1;

		tcmd_cont_tx_cmd(&utf_dev, &tx_tcmdParms);
}

SRAM_TEXT
A_INT16 secGlutCalRunSingle(A_UINT16 freq1, A_UINT16 freq2, A_UINT8 chainMask)
{
	A_UINT16 measPwr1=0;
#ifndef FPGA
	A_UINT8 secChainIdx;

	// Stop Tx
	utfTxStop(&utf_dev, NULL);

	// Measure power out of the secondary chain
	secChainIdx = (chainMask/4) + 1;
	measPwr1 = whalTpcGetGlutMeasPwr(freq2,1,secChainIdx);

	// Run VHT160/80p80 to program gluts
#if defined(QCA9984)
	gSecGlutCal = TRUE;
#endif
	whalTpcDisableCLPCErr(1);
	secGlutCal_runTcmd(freq1, freq2, chainMask, TCMD_WLAN_MODE_VHT80P80, 183, TPC_TX_PWR, measPwr1/4);

#endif
	return measPwr1;
}

//SRAM_TEXT
//void secGlutCalSM(CMD_GENERICUTFCMDRSP_PARMS *params)
CODESWAP_MARK_EVICTABLE(void, secGlutCalSM, CMD_GENERICUTFCMDRSP_PARMS *params)
{

#ifndef FPGA
	A_INT16 measPwr=0,measPwrDelta=0;
	A_CHAR  dbgMsg[24];
	A_UINT8  dbgMsgSize,i=0;
	A_UINT8 secChainIdx;

	HAL_REG_CAPABILITIES regCap;
	AR6000_EEPROM_STRUCT *pEepromStruct=&eepromStruct;

	A_INT8 tableVal = 0;

	switch (secGlutState){
	case SECONDARY_GLUT_CAL_STATE_INIT:
		// Initialize the SECONDARY GLUT CAL state machine
#if !defined(QCA9984) // Not supported for all projects other than QCA9984
		secGlutState = SECONDARY_GLUT_CAL_STATE_NOTSUPP;
		break;
#endif
		freqIdxPri = 0;
		freqIdxSec = 0;
		chainMaskIdx = 0;
		dbgMsgSize = 0;
#if defined(QCA9984)
		gSecGlutCal = FALSE;
#endif

		A_MEMSET(params->GenericUtfCmdRetData,0,sizeof(params->GenericUtfCmdRetData));
		A_MEMSET(dbgMsg,0,sizeof(dbgMsg));

		params->GenericUtfCmdDone = GENERICUTFCMD_INCOMP;
		params->GenericUtfCmdStatus = GENERICUTFCMD_STATUS_SUCCESS;
		secGlutState = SECONDARY_GLUT_CAL_STATE_CAL;

		// Get VHT160/80 capabilities
		whalGetRegCapabilities(&regCap);
		if (!((regCap.wireless_modes & REGDMN_MODE_11AC_VHT80_80) ||
				(regCap.wireless_modes & REGDMN_MODE_11AC_VHT160))){
			// Not supported
			secGlutState = SECONDARY_GLUT_CAL_STATE_NOTSUPP;
		}
		break;

	case SECONDARY_GLUT_CAL_STATE_CAL:
		i = 0;
		reqPwr = 0;

		params->GenericUtfCmdRetData[i++] = freqList[freqIdxPri];
		params->GenericUtfCmdRetData[i++] = freqList[freqIdxSec];
		params->GenericUtfCmdRetData[i++] = chainMaskList[chainMaskIdx];

		// Run CAL for this instance
		if (freqIdxPri != freqIdxSec){
			reqPwr = secGlutCalRunSingle(freqList[freqIdxPri],freqList[freqIdxSec],chainMaskList[chainMaskIdx]);
		}
		secGlutState = SECONDARY_GLUT_CAL_STATE_MEAS;

		// Round off
		params->GenericUtfCmdRetData[i++] = reqPwr;
		params->NumGenericUtfCmdRetData = 5;

		params->GenericUtfCmdDone = GENERICUTFCMD_INCOMP;
		params->GenericUtfCmdStatus = GENERICUTFCMD_STATUS_SUCCESS;

		break;

	case SECONDARY_GLUT_CAL_STATE_MEAS:
		i=0;
		measPwr = 0;
		A_MEMSET(params->GenericUtfCmdRetData,0,sizeof(params->GenericUtfCmdRetData));

		if (freqIdxPri != freqIdxSec){
			// Get Measurements
			secChainIdx = (chainMaskList[chainMaskIdx]/4) + 1;
			measPwr = whalTpcGetMeasPwrOutForChain(secChainIdx);

			measPwrDelta = reqPwr - measPwr;

			//Update the glutDelta
			measPwrDelta = measPwrDelta +4;
			tableVal = measPwrDelta/8;
			gainIndexBiasTable[chainMaskIdx][freqIdxPri][freqIdxSec] = tableVal;
		}

		params->GenericUtfCmdRetData[i++] = measPwr;
		params->GenericUtfCmdRetData[i++] = tableVal;
		params->NumGenericUtfCmdRetData = 5;

		// Check for state
		if ((freqIdxPri == NUM_CHAN1_FREQ-1) && (freqIdxSec == NUM_CHAN1_FREQ-1) && (chainMaskIdx == NUM_SEC_CHAINS-1))
			secGlutState = SECONDARY_GLUT_CAL_STATE_DONE;
		else
			secGlutState = SECONDARY_GLUT_CAL_STATE_CAL;

		// Update indices
		freqIdxSec++;

		if (freqIdxSec == NUM_CHAN1_FREQ){
			freqIdxSec = 0;
			freqIdxPri++;
			if (freqIdxPri == NUM_CHAN1_FREQ){
				freqIdxPri = 0;
				chainMaskIdx++;
			}
		}

		params->GenericUtfCmdDone = GENERICUTFCMD_INCOMP;
		params->GenericUtfCmdStatus = GENERICUTFCMD_STATUS_SUCCESS;

		break;

	case SECONDARY_GLUT_CAL_STATE_DONE:

		// Stop Tx
//		utfTxStop(&utf_dev, NULL);

		// ReEnable CLPC error update
		whalTpcDisableCLPCErr(0);

#if defined(QCA9984)
		gSecGlutCal = FALSE;
#endif

		//Update Secondary Calibration Flag
		pEepromStruct->pEeprom->baseEepHeader.opCapBrdFlags.secGlutCalFlag = 1;

		//Update secondary channel table
	    A_MEMCPY(pEepromStruct->pEeprom->secondChannelGLUTOffset,gainIndexBiasTable,sizeof(gainIndexBiasTable));

		dbgMsgSize = 5;
		params->NumGenericUtfCmdRetData = 5 + dbgMsgSize;
		A_MEMSET(params->GenericUtfCmdRetData,0,sizeof(params->GenericUtfCmdRetData));
		A_STRNCPY(dbgMsg," Done",dbgMsgSize);
		A_MEMCPY(&params->GenericUtfCmdRetData[5],dbgMsg,dbgMsgSize);

		params->GenericUtfCmdDone = GENERICUTFCMD_DONE;
		params->GenericUtfCmdStatus = GENERICUTFCMD_STATUS_SUCCESS;
		secGlutState = SECONDARY_GLUT_CAL_STATE_INIT;
		break;

	case SECONDARY_GLUT_CAL_STATE_NOTSUPP:
#if defined(QCA9984)
		gSecGlutCal = FALSE;
#endif
		A_MEMSET(params->GenericUtfCmdRetData,0,sizeof(params->GenericUtfCmdRetData));
		dbgMsgSize = 14;
		params->NumGenericUtfCmdRetData = 5 + dbgMsgSize;
		A_STRNCPY(dbgMsg," Not Supported",dbgMsgSize);
		A_MEMCPY(&params->GenericUtfCmdRetData[5],dbgMsg,dbgMsgSize);

		params->GenericUtfCmdDone = GENERICUTFCMD_DONE;
		params->GenericUtfCmdStatus = GENERICUTFCMD_STATUS_FAILURE;
		secGlutState = SECONDARY_GLUT_CAL_STATE_INIT;
		break;

	case SECONDARY_GLUT_CAL_STATE_ERROR:
#if defined(QCA9984)
		gSecGlutCal = FALSE;
#endif
		A_MEMSET(params->GenericUtfCmdRetData,0,sizeof(params->GenericUtfCmdRetData));
		dbgMsgSize = 11;
		A_STRNCPY(dbgMsg," Cal Failed",dbgMsgSize);
		params->NumGenericUtfCmdRetData = 5 + dbgMsgSize;
		A_MEMCPY(&params->GenericUtfCmdRetData[5],dbgMsg,dbgMsgSize);

		params->GenericUtfCmdDone = GENERICUTFCMD_DONE;
		params->GenericUtfCmdStatus = GENERICUTFCMD_STATUS_FAILURE;
		secGlutState = SECONDARY_GLUT_CAL_STATE_INIT;
		break;

	default:
		params->GenericUtfCmdDone = GENERICUTFCMD_DONE;
		params->GenericUtfCmdStatus = GENERICUTFCMD_STATUS_FAILURE;
		secGlutState = SECONDARY_GLUT_CAL_STATE_INIT;
		break;
	}
#endif
	return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void ,secGlutCalSM, CMD_GENERICUTFCMDRSP_PARMS *);
extern void secGlutCalSM(CMD_GENERICUTFCMDRSP_PARMS *params);
