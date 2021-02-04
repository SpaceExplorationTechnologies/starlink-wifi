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
#include "cmdGetTgtPwr.h"
#include "getTgtPwr.h"
#include "whal_internal.h"
#include "codeswap_api.h"

extern wlan_tcmd_dev_t utf_dev;

#if (NUM_SPATIAL_STREAM > 3)
#define RATE_HT20_INDEX_MAX   RATE_HT20_31
#define RATE_VHT20_INDEX_MAX  RATE_VHT20_MCS9_NSS4
#define RATE_HT40_INDEX_MAX   RATE_HT40_31
#define RATE_VHT40_INDEX_MAX  RATE_VHT40_MCS9_NSS4
#define RATE_VHT80_INDEX_MAX  RATE_VHT80_MCS9_NSS4

#elif (NUM_SPATIAL_STREAM > 2)
#define RATE_HT20_INDEX_MAX   RATE_HT20_23
#define RATE_VHT20_INDEX_MAX  RATE_VHT20_MCS9_NSS3
#define RATE_HT40_INDEX_MAX   RATE_HT40_23
#define RATE_VHT40_INDEX_MAX  RATE_VHT40_MCS9_NSS3
#define RATE_VHT80_INDEX_MAX  RATE_VHT80_MCS9_NSS3

#elif (NUM_SPATIAL_STREAM > 1)
#define RATE_HT20_INDEX_MAX   RATE_HT20_15
#define RATE_VHT20_INDEX_MAX  RATE_VHT20_MCS9_NSS2
#define RATE_HT40_INDEX_MAX   RATE_HT40_15
#define RATE_VHT40_INDEX_MAX  RATE_VHT40_MCS9_NSS2
#define RATE_VHT80_INDEX_MAX  RATE_VHT80_MCS9_NSS2

#else
#define RATE_HT20_INDEX_MAX   RATE_HT20_7
#define RATE_VHT20_INDEX_MAX  RATE_VHT20_MCS9_NSS1
#define RATE_HT40_INDEX_MAX   RATE_HT40_7
#define RATE_VHT40_INDEX_MAX  RATE_VHT40_MCS9_NSS1
#define RATE_VHT80_INDEX_MAX  RATE_VHT80_MCS9_NSS1
#endif

#ifndef FPGA
#include "ar6000_eeprom.h"
#include "qc900b_eeprom.h"
/* Array to convert rate index from test to whal rate index */
A_UINT8 tcmdIdx2ratesArrIdx[] = {
		RATE_1,
		RATE_2,
		RATE_2,   // dummy place holder
		RATE_5_5,
		RATE_5_5, // dummy place holder
		RATE_11,
		RATE_11, // dummy place holder
		RATE_11, // dummy place holder
		RATE_6,
		RATE_9,
		RATE_12,
		RATE_18,
		RATE_24,
		RATE_36,
		RATE_48,
		RATE_54,
		RATE_HT20_0,
		RATE_HT20_1,
		RATE_HT20_2,
		RATE_HT20_3,
		RATE_HT20_4,
		RATE_HT20_5,
		RATE_HT20_6,
		RATE_HT20_7,
		RATE_HT40_0,
		RATE_HT40_1,
		RATE_HT40_2,
		RATE_HT40_3,
		RATE_HT40_4,
		RATE_HT40_5,
		RATE_HT40_6,
		RATE_HT40_7,
#if (NUM_SPATIAL_STREAM > 1)
		RATE_HT20_8,
		RATE_HT20_9,
		RATE_HT20_10,
		RATE_HT20_11,
		RATE_HT20_12,
		RATE_HT20_13,
		RATE_HT20_14,
		RATE_HT20_15,
		RATE_HT40_8,
		RATE_HT40_9,
		RATE_HT40_10,
		RATE_HT40_11,
		RATE_HT40_12,
		RATE_HT40_13,
		RATE_HT40_14,
		RATE_HT40_15,
#else
    RATE_HT20_7,
		RATE_HT20_7,
		RATE_HT20_7,
		RATE_HT20_7,
		RATE_HT20_7,
		RATE_HT20_7,
		RATE_HT20_7,
		RATE_HT20_7,
		RATE_HT40_7,
		RATE_HT40_7, //40
		RATE_HT40_7,
		RATE_HT40_7,
		RATE_HT40_7,
		RATE_HT40_7,
		RATE_HT40_7,
		RATE_HT40_7,
#endif

#if (NUM_SPATIAL_STREAM > 2)
		RATE_HT20_16,
		RATE_HT20_17,
		RATE_HT20_18,
		RATE_HT20_19,
		RATE_HT20_20,
		RATE_HT20_21,
		RATE_HT20_22,
		RATE_HT20_23,

		RATE_HT40_16,
		RATE_HT40_17,
		RATE_HT40_18,
		RATE_HT40_19,
		RATE_HT40_20,
		RATE_HT40_21,
		RATE_HT40_22,
		RATE_HT40_23,
#else
		RATE_HT20_7,
		RATE_HT20_7,
		RATE_HT20_7,
  	RATE_HT20_7, //50
		RATE_HT20_7,
		RATE_HT20_7,
		RATE_HT20_7,
		RATE_HT20_7,

		RATE_HT40_7,
		RATE_HT40_7,
		RATE_HT40_7,
		RATE_HT40_7,
		RATE_HT40_7,
  	RATE_HT40_7, //60
		RATE_HT40_7,
		RATE_HT40_7,
#endif

		RATE_VHT20_MCS0_NSS1,
		RATE_VHT20_MCS1_NSS1,
		RATE_VHT20_MCS2_NSS1,
		RATE_VHT20_MCS3_NSS1,
		RATE_VHT20_MCS4_NSS1,
		RATE_VHT20_MCS5_NSS1,
		RATE_VHT20_MCS6_NSS1,
		RATE_VHT20_MCS7_NSS1,
		RATE_VHT20_MCS8_NSS1,
		RATE_VHT20_MCS9_NSS1,
		RATE_VHT20_MCS9_NSS1, // dummy place holder
		RATE_VHT20_MCS9_NSS1, // dummy place holder
		RATE_VHT40_MCS0_NSS1,
		RATE_VHT40_MCS1_NSS1,
		RATE_VHT40_MCS2_NSS1,
		RATE_VHT40_MCS3_NSS1,
		RATE_VHT40_MCS4_NSS1,
		RATE_VHT40_MCS5_NSS1,
		RATE_VHT40_MCS6_NSS1,
		RATE_VHT40_MCS7_NSS1,
		RATE_VHT40_MCS8_NSS1,
		RATE_VHT40_MCS9_NSS1,
		RATE_VHT40_MCS9_NSS1, // dummy place holder
		RATE_VHT40_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS0_NSS1,
		RATE_VHT80_MCS1_NSS1,
		RATE_VHT80_MCS2_NSS1,
		RATE_VHT80_MCS3_NSS1,
		RATE_VHT80_MCS4_NSS1,
		RATE_VHT80_MCS5_NSS1,
		RATE_VHT80_MCS6_NSS1,
		RATE_VHT80_MCS7_NSS1,
		RATE_VHT80_MCS8_NSS1,
		RATE_VHT80_MCS9_NSS1,
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder

#if (NUM_SPATIAL_STREAM > 1)
		RATE_VHT20_MCS0_NSS2,
		RATE_VHT20_MCS1_NSS2,
		RATE_VHT20_MCS2_NSS2,
		RATE_VHT20_MCS3_NSS2,
		RATE_VHT20_MCS4_NSS2,
		RATE_VHT20_MCS5_NSS2,
		RATE_VHT20_MCS6_NSS2,
		RATE_VHT20_MCS7_NSS2,
		RATE_VHT20_MCS8_NSS2,
		RATE_VHT20_MCS9_NSS2,
		RATE_VHT20_MCS9_NSS2, // dummy place holder
		RATE_VHT20_MCS9_NSS2, // dummy place holder
		RATE_VHT40_MCS0_NSS2,
		RATE_VHT40_MCS1_NSS2,
		RATE_VHT40_MCS2_NSS2,
		RATE_VHT40_MCS3_NSS2,
		RATE_VHT40_MCS4_NSS2,
		RATE_VHT40_MCS5_NSS2,
		RATE_VHT40_MCS6_NSS2,
		RATE_VHT40_MCS7_NSS2,
		RATE_VHT40_MCS8_NSS2,
		RATE_VHT40_MCS9_NSS2,
		RATE_VHT40_MCS9_NSS2, // dummy place holder
		RATE_VHT40_MCS9_NSS2, // dummy place holder
		RATE_VHT80_MCS0_NSS2,
		RATE_VHT80_MCS1_NSS2,
		RATE_VHT80_MCS2_NSS2,
		RATE_VHT80_MCS3_NSS2,
		RATE_VHT80_MCS4_NSS2,
		RATE_VHT80_MCS5_NSS2,
		RATE_VHT80_MCS6_NSS2,
		RATE_VHT80_MCS7_NSS2,
		RATE_VHT80_MCS8_NSS2,
		RATE_VHT80_MCS9_NSS2,
		RATE_VHT80_MCS9_NSS2, // dummy place holder
		RATE_VHT80_MCS9_NSS2, // dummy place holder
#else
		RATE_VHT20_MCS0_NSS1,
		RATE_VHT20_MCS1_NSS1, //100
		RATE_VHT20_MCS2_NSS1,
		RATE_VHT20_MCS3_NSS1,
		RATE_VHT20_MCS4_NSS1,
		RATE_VHT20_MCS5_NSS1,
		RATE_VHT20_MCS6_NSS1,
		RATE_VHT20_MCS7_NSS1,
		RATE_VHT20_MCS8_NSS1,
		RATE_VHT20_MCS9_NSS1,
		RATE_VHT20_MCS9_NSS1, // dummy place holder
		RATE_VHT20_MCS9_NSS1, // dummy place holder //110
		RATE_VHT40_MCS0_NSS1,
		RATE_VHT40_MCS1_NSS1,
		RATE_VHT40_MCS2_NSS1,
		RATE_VHT40_MCS3_NSS1,
		RATE_VHT40_MCS4_NSS1,
		RATE_VHT40_MCS5_NSS1,
		RATE_VHT40_MCS6_NSS1,
		RATE_VHT40_MCS7_NSS1,
		RATE_VHT40_MCS8_NSS1,
		RATE_VHT40_MCS9_NSS1, //120
		RATE_VHT40_MCS9_NSS1, // dummy place holder
		RATE_VHT40_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS0_NSS1,
		RATE_VHT80_MCS1_NSS1,
		RATE_VHT80_MCS2_NSS1,
		RATE_VHT80_MCS3_NSS1,
		RATE_VHT80_MCS4_NSS1,
		RATE_VHT80_MCS5_NSS1,
		RATE_VHT80_MCS6_NSS1,
		RATE_VHT80_MCS7_NSS1, //130
		RATE_VHT80_MCS8_NSS1,
		RATE_VHT80_MCS9_NSS1,
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
#endif
#if (NUM_SPATIAL_STREAM > 2)
		RATE_VHT20_MCS0_NSS3,
		RATE_VHT20_MCS1_NSS3,
		RATE_VHT20_MCS2_NSS3,
		RATE_VHT20_MCS3_NSS3,
		RATE_VHT20_MCS4_NSS3,
		RATE_VHT20_MCS5_NSS3,
		RATE_VHT20_MCS6_NSS3,
		RATE_VHT20_MCS7_NSS3,
		RATE_VHT20_MCS8_NSS3,
		RATE_VHT20_MCS9_NSS3,
		RATE_VHT20_MCS9_NSS3, // dummy place holder
		RATE_VHT20_MCS9_NSS3, // dummy place holder
		RATE_VHT40_MCS0_NSS3,
		RATE_VHT40_MCS1_NSS3,
		RATE_VHT40_MCS2_NSS3,
		RATE_VHT40_MCS3_NSS3,
		RATE_VHT40_MCS4_NSS3,
		RATE_VHT40_MCS5_NSS3,
		RATE_VHT40_MCS6_NSS3,
		RATE_VHT40_MCS7_NSS3,
		RATE_VHT40_MCS8_NSS3,
		RATE_VHT40_MCS9_NSS3,
		RATE_VHT40_MCS9_NSS3, // dummy place holder
		RATE_VHT40_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS0_NSS3,
		RATE_VHT80_MCS1_NSS3,
		RATE_VHT80_MCS2_NSS3,
		RATE_VHT80_MCS3_NSS3,
		RATE_VHT80_MCS4_NSS3,
		RATE_VHT80_MCS5_NSS3,
		RATE_VHT80_MCS6_NSS3,
		RATE_VHT80_MCS7_NSS3,
		RATE_VHT80_MCS8_NSS3,
		RATE_VHT80_MCS9_NSS3,
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
		RATE_VHT80_MCS9_NSS3, // dummy place holder
#else
		RATE_VHT20_MCS0_NSS1,
		RATE_VHT20_MCS1_NSS1,
		RATE_VHT20_MCS2_NSS1,
		RATE_VHT20_MCS3_NSS1,
		RATE_VHT20_MCS4_NSS1,
		RATE_VHT20_MCS5_NSS1,
		RATE_VHT20_MCS6_NSS1,
		RATE_VHT20_MCS7_NSS1,
		RATE_VHT20_MCS8_NSS1,
		RATE_VHT20_MCS9_NSS1,
		RATE_VHT20_MCS9_NSS1, // dummy place holder
		RATE_VHT20_MCS9_NSS1, // dummy place holder
		RATE_VHT40_MCS0_NSS1,
		RATE_VHT40_MCS1_NSS1,
		RATE_VHT40_MCS2_NSS1,
		RATE_VHT40_MCS3_NSS1,
		RATE_VHT40_MCS4_NSS1,
		RATE_VHT40_MCS5_NSS1,
		RATE_VHT40_MCS6_NSS1,
		RATE_VHT40_MCS7_NSS1,
		RATE_VHT40_MCS8_NSS1,
		RATE_VHT40_MCS9_NSS1,
		RATE_VHT40_MCS9_NSS1, // dummy place holder
		RATE_VHT40_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS0_NSS1,
		RATE_VHT80_MCS1_NSS1,
		RATE_VHT80_MCS2_NSS1,
		RATE_VHT80_MCS3_NSS1,
		RATE_VHT80_MCS4_NSS1,
		RATE_VHT80_MCS5_NSS1,
		RATE_VHT80_MCS6_NSS1,
		RATE_VHT80_MCS7_NSS1,
		RATE_VHT80_MCS8_NSS1,
		RATE_VHT80_MCS9_NSS1,
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
		RATE_VHT80_MCS9_NSS1, // dummy place holder
#endif
#if (NUM_SPATIAL_STREAM > 3)
		RATE_VHT20_MCS0_NSS4,
		RATE_VHT20_MCS1_NSS4,
		RATE_VHT20_MCS2_NSS4,
		RATE_VHT20_MCS3_NSS4,
		RATE_VHT20_MCS4_NSS4,
		RATE_VHT20_MCS5_NSS4,
		RATE_VHT20_MCS6_NSS4,
		RATE_VHT20_MCS7_NSS4,
		RATE_VHT20_MCS8_NSS4,
		RATE_VHT20_MCS9_NSS4,
		RATE_VHT40_MCS0_NSS4,
		RATE_VHT40_MCS1_NSS4,
		RATE_VHT40_MCS2_NSS4,
		RATE_VHT40_MCS3_NSS4,
		RATE_VHT40_MCS4_NSS4,
		RATE_VHT40_MCS5_NSS4,
		RATE_VHT40_MCS6_NSS4,
		RATE_VHT40_MCS7_NSS4,
		RATE_VHT40_MCS8_NSS4,
		RATE_VHT40_MCS9_NSS4,
		RATE_VHT80_MCS0_NSS4,
		RATE_VHT80_MCS1_NSS4,
		RATE_VHT80_MCS2_NSS4,
		RATE_VHT80_MCS3_NSS4,
		RATE_VHT80_MCS4_NSS4,
		RATE_VHT80_MCS5_NSS4,
		RATE_VHT80_MCS6_NSS4,
		RATE_VHT80_MCS7_NSS4,
		RATE_VHT80_MCS8_NSS4,
		RATE_VHT80_MCS9_NSS4,
#else
		RATE_VHT20_MCS0_NSS1,
		RATE_VHT20_MCS1_NSS1,
		RATE_VHT20_MCS2_NSS1,
		RATE_VHT20_MCS3_NSS1,
		RATE_VHT20_MCS4_NSS1,
		RATE_VHT20_MCS5_NSS1,
		RATE_VHT20_MCS6_NSS1,
		RATE_VHT20_MCS7_NSS1,
		RATE_VHT20_MCS8_NSS1,
		RATE_VHT20_MCS9_NSS1,
		RATE_VHT40_MCS0_NSS1,
		RATE_VHT40_MCS1_NSS1,
		RATE_VHT40_MCS2_NSS1,
		RATE_VHT40_MCS3_NSS1,
		RATE_VHT40_MCS4_NSS1,
		RATE_VHT40_MCS5_NSS1,
		RATE_VHT40_MCS6_NSS1,
		RATE_VHT40_MCS7_NSS1,
		RATE_VHT40_MCS8_NSS1,
		RATE_VHT40_MCS9_NSS1,
		RATE_VHT80_MCS0_NSS1,
		RATE_VHT80_MCS1_NSS1,
		RATE_VHT80_MCS2_NSS1,
		RATE_VHT80_MCS3_NSS1,
		RATE_VHT80_MCS4_NSS1,
		RATE_VHT80_MCS5_NSS1,
		RATE_VHT80_MCS6_NSS1,
		RATE_VHT80_MCS7_NSS1,
		RATE_VHT80_MCS8_NSS1,
		RATE_VHT80_MCS9_NSS1,
#endif
#if !(defined(AR900B) || defined(IPQ4019))
		RATE_VHT160_MCS0_NSS1, // dummy
		RATE_VHT160_MCS0_NSS1, // dummy
		RATE_VHT160_MCS0_NSS1,
		RATE_VHT160_MCS1_NSS1,
		RATE_VHT160_MCS2_NSS1,
		RATE_VHT160_MCS3_NSS1,
		RATE_VHT160_MCS4_NSS1,
		RATE_VHT160_MCS5_NSS1,
		RATE_VHT160_MCS6_NSS1,
		RATE_VHT160_MCS7_NSS1,
		RATE_VHT160_MCS8_NSS1,
		RATE_VHT160_MCS9_NSS1,
		#if !defined(QCA9888)
		RATE_VHT160_MCS0_NSS2,
		RATE_VHT160_MCS1_NSS2,
		RATE_VHT160_MCS2_NSS2,
		RATE_VHT160_MCS3_NSS2,
		RATE_VHT160_MCS4_NSS2,
		RATE_VHT160_MCS5_NSS2,
		RATE_VHT160_MCS6_NSS2,
		RATE_VHT160_MCS7_NSS2,
		RATE_VHT160_MCS8_NSS2,
		RATE_VHT160_MCS9_NSS2,
		#endif
#endif

};

extern AR6000_EEPROM_STRUCT eepromStruct;
#endif

/* -------------------------------------------------
 * FUNCTION:  getTgtPwr()
 *
 * NOTE:
 *      Get target power from FW
 * --------------------------------------------------
 */

//SRAM_TEXT
//void getTgtPwr(void *pParm)
CODESWAP_MARK_EVICTABLE(void, getTgtPwr, void *pParm)
{
    A_UINT32 				tmpCmdCode;
	int 					tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 				*rCmdStream = NULL;
    A_UINT32 				cmdStreamLen = 0;
    A_UINT32 				tgtPwr = CMD_GET_TGTPWR_INVALID;
#ifndef FPGA
    CMD_GETTGTPWR_PARMS* 	cmdParm;
    A_UINT16 				rtTbl[RATE_MAX];
    WHAL_CHANNEL 			chan;
    A_UINT32 				rateIdx;
    WLAN_PHY_MODE 			mode=0;
    A_BOOL 					is2GHz;

    cmdParm = (CMD_GETTGTPWR_PARMS*)pParm;
    rateIdx = cmdParm->rateBit;

    /* Convert tcmd rate to rates array rate index */
    if (rateIdx < sizeof(tcmdIdx2ratesArrIdx)){
		rateIdx = tcmdIdx2ratesArrIdx[rateIdx];

		/* Setup channel based on freq/rate */
		chan.mhz = (A_UINT16)cmdParm->freq;
		chan.band_center_freq1 = (A_UINT16)cmdParm->freq;
		chan.band_center_freq2 = (A_UINT16)cmdParm->freq;
        chan.max_reg_power = TCMD_MAX_RDPWR;

		is2GHz = (cmdParm->freq < 2500) ? TRUE : FALSE;

		if(rateIdx <= RATE_1)
			mode = MODE_11B;
		else if(rateIdx <= RATE_9)
			mode = is2GHz? MODE_11G:MODE_11A;
		else if(rateIdx <= RATE_HT20_INDEX_MAX)
			mode = is2GHz? MODE_11NG_HT20:MODE_11NA_HT20;
		else if(rateIdx <= RATE_HT40_INDEX_MAX)
			mode = is2GHz? MODE_11NG_HT40:MODE_11NA_HT40;
		else if(rateIdx <= RATE_VHT20_INDEX_MAX)
			mode = is2GHz? MODE_11AC_VHT20_2G:MODE_11AC_VHT20;
		else if(rateIdx <= RATE_VHT40_INDEX_MAX)
			mode = is2GHz? MODE_11AC_VHT40_2G:MODE_11AC_VHT40;
		else if (rateIdx <= RATE_VHT80_INDEX_MAX)
			mode = MODE_11AC_VHT80;
#if !(defined(AR900B) || defined(IPQ4019))
		else
			mode = MODE_11AC_VHT160;
#endif

		chan.phy_mode = mode;

        /* Get Rate Table */
//        memcpy(rtTbl, eepromStruct.tpcConfig.ratesArray, sizeof(rtTbl));
		whalSetOffLinePowerPerRateTable(&chan,rtTbl,63);

		/* Get SU or MU targets */
#ifdef TGTPWR_SCHEME_NSS
		if (cmdParm->userMode == 1){
			tgtPwr = (rtTbl[rateIdx] >> TGTPWR_MU_LOC_LSB) & TGTPWR_SU_MU_MASK;
		}
		else{
			tgtPwr = rtTbl[rateIdx] & TGTPWR_SU_MU_MASK;
		}
#else
		tgtPwr = rtTbl[rateIdx];
#endif
    }
    else{
    	tgtPwr = CMD_GET_TGTPWR_INVALID;
    }
#endif

	tmpCmdCode = CMD_GETTGTPWRRSP;
	tmpParaLen = 2;
	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
	         PARM_TGTPWR, tgtPwr
			 );

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);

}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void ,getTgtPwr, void *);
extern void getTgtPwr(void *pParm);

// Init Get Target Power module
SRAM_TEXT
void initGetTgtPwr(void)
{
	registerGETTGTPWRHandler(getTgtPwr);
    return;
}


