/*
 * Copyright (c) 2012 - 2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * 2012 - 2016 Qualcomm Atheros, Inc.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

#if defined(_HOST_SIM_TESTING)
#include "otaHostCommon.h"
#else
#include "osapi.h"
#endif
#include "wlantype.h"
#include "tcmdHostInternal.h"

//#include "cmdOpcodes.h"
#include "cmdStream.h"
#include "parmBinTemplate.h"
#include "parseBinCmdStream.h"
#include "cmdAllParms.h"
#include "cmdProcessingSM.h"
#include "testcmd.h"
#include "utf_dev.h"
#include "tcmd_api.h"
#include "utfCallback.h"
#include "whalExtensionGeneric.h"
#include "hal_tcmd.h"
#include "maskRateCommon.h"
#include "cmdOpcodes.h"
#include "genTxBinCmdTlv.h"
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
#ifndef UTFSIM
#include <wmi_tcmd.h>
#else
#include "tcmd_if_rfsim.h"
#endif
#endif


#define _2G_READY
#define  RATES_11_N   60
#define  TCMD_11AC3x3_MAX_RATES   150

#define CHAN_2G 3000
#define CHAN_5G 4800

//#if (1) /* to get the definition of whal internal function "whalDoCalibration" */
//#include "ar6000_reset.h"
//extern WHAL_RESET_INDIRECTION_TABLE *pWhalResetIndirectionTable;
//#endif
extern _VALUES_OF_INTEREST ValuesOfInterest;
//#include "common_defs.h"

// ----------------- Some Notes -------------
    // cmd processing
    // cmdqueue 1 cmd at a time,
    //    cmdopcode -> cmdParmParser
    //    cmdParmParser knows the exact cmdParm structure
    //    based on cmd parm template that contains offset and size, update the cmd parm structure
    //    finally calls cmd processing routine with the cmd parm structure.
    //
    // based on cmd stream execution mode: (i.e. repeat n/indefinite times )
    //                     tester response, (no need, if we insert RX SYNC cmd
    //                     host respons (no need, since host can control from its end)
    //
    // cmd execution failure handling: back 2 steps
    // For failed test mode, copy 2 last entries from executedCmdQueue over to curCmdQueue.
    //
    // extream case of timeout, abort testing sequence ... and send back failure
    //
    // curCmdQueue, executedCmdQueue
    // once curCmdQueue is empty, depending on repeated test or not, copy all executeCmdQueue over to curCmdQueue
    //
    //
// ------------------------------------------

extern _OP_2_STATE_EVT Op2StateEvt[];

extern wlan_tcmd_dev_t utf_dev;

void rxSyncTimeout(A_HANDLE alarm, void *data);
void rxTimeout(A_HANDLE alarm, void *data);

extern _CMDPROC_STATE_INFO CmdStateInfo;

#if defined(AR900B)
extern A_UINT32 g_opFlags;
#endif

// the instance to modify
_CMD_ALL_PARMS _cmdParms;
TCMD_CONT_TX tx_tcmdParms;
TCMD_CONT_RX rx_tcmdParms;

A_BOOL hostTlvCmdProcess = FALSE;

extern A_UINT8 g_rx_opflags;

#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
extern A_UINT32 processTxStatusStartPerRate(wlan_tcmd_dev_t *dev,_CMD_TX_PARMS *parms);
extern A_UINT32 processRxStatusStartCmd (wlan_tcmd_dev_t *dev,_CMD_RX_PARMS *pRxParms);
extern void processNartCommand (wlan_tcmd_dev_t *dev,_CMD_NARTCMD_PARMS *parms);
#endif

static void txCAL(TCMD_CONT_TX *pTcmdParms); 

/*
 * This function converts rate to the bit position number in the bitmask
 */
A_UINT32 Rate2MaskBitNo[MASK_RATE_MAX] = {
    0, /* ATH_RATE_1M */    //0
    1, /* ATH_RATE_2M */
    3, /* ATH_RATE_5_5M */
    5, /* ATH_RATE_11M */   //3

    8, /* ATH_RATE_6M */    //4
    9, /* ATH_RATE_9M */
    10, /* ATH_RATE_12M */
    11, /* ATH_RATE_18M */
    12, /* ATH_RATE_24M */
    13, /* ATH_RATE_36M */
    14, /* ATH_RATE_48M */
    15, /* ATH_RATE_54M */  //11

    16, /* ATH_RATE_6_5M */ 
    17, /* ATH_RATE_13M */
    18, /* ATH_RATE_19_5M */
    19, /* ATH_RATE_26M */
    20, /* ATH_RATE_39M */
    21, /* ATH_RATE_52M */
    22, /* ATH_RATE_58_5M */
    23, /* ATH_RATE_65M */  //19

//#if (WHAL_RX_NUM_CHAIN > 1)
    32, /* ATH_RATE_HT20_MCS8_13M */  
    33, /* ATH_RATE_HT20_MCS9_26M */
    34, /* ATH_RATE_HT20_MCS10_39M */
    35, /* ATH_RATE_HT20_MCS11_52M */
    36, /* ATH_RATE_HT20_MCS12_78M */
    37, /* ATH_RATE_HT20_MCS13_104M */
    38, /* ATH_RATE_HT20_MCS14_107M (117M) */
    39, /* ATH_RATE_HT20_MCS15_130M */  //27
//#endif

//#if (WHAL_RX_NUM_CHAIN > 2)
    48, /* ATH_RATE_HT20_MCS16_19_5M */
    49, /* ATH_RATE_HT20_MCS17_39M */
    50, /* ATH_RATE_HT20_MCS18_58_5M */
    51, /* ATH_RATE_HT20_MCS19_78M */
    52, /* ATH_RATE_HT20_MCS20_117M */
    53, /* ATH_RATE_HT20_MCS21_156M */
    54, /* ATH_RATE_HT20_MCS22_175_5M */
    55, /* ATH_RATE_HT20_MCS23_195M */    //35
//#endif

    24, /* ATH_RATE_HT40_13_5M */
    25, /* ATH_RATE_HT40_27M */
    26, /* ATH_RATE_HT40_40_5M */
    27, /* ATH_RATE_HT40_54M */
    28, /* ATH_RATE_HT40_81M */
    29, /* ATH_RATE_HT40_108M */
    30, /* ATH_RATE_HT40_121_5M */
    31, /* ATH_RATE_HT40_135M */    //43

//#if (WHAL_RX_NUM_CHAIN > 1)
    40, /* ATH_RATE_HT40_MCS8_27M */
    41, /* ATH_RATE_HT40_MCS9_54M */
    42, /* ATH_RATE_HT40_MCS10_81M */
    43, /* ATH_RATE_HT40_MCS11_108M */
    44, /* ATH_RATE_HT40_MCS12_162M */
    45, /* ATH_RATE_HT40_MCS13_216M */
    46, /* ATH_RATE_HT40_MCS14_243M */
    47, /* ATH_RATE_HT40_MCS15_270M */  //51
//#endif

//#if (WHAL_RX_NUM_CHAIN > 2)
    56, /* ATH_RATE_HT40_MCS16_40_5M */
    57, /* ATH_RATE_HT40_MCS17_81M */
    58, /* ATH_RATE_HT40_MCS18_121_5M */
    59, /* ATH_RATE_HT40_MCS19_162M */
    60, /* ATH_RATE_HT40_MCS20_243M */
    61, /* ATH_RATE_HT40_MCS21_324M */
    62, /* ATH_RATE_HT40_MCS22_364_5M */
    63, /* ATH_RATE_HT40_MCS23_405M */    //59
//#endif

/// 11AC ..
#if defined(AR9888) || defined(AR6320) || defined(AR900B)  || defined(QCA9984) || defined(QCA9888) || defined(IPQ4019)
//VHT20S1
    64, //ATH_RATE_VHT20_NSS1_MCS0,	//60
    65, //ATH_RATE_VHT20_NSS1_MCS1,
    66, //ATH_RATE_VHT20_NSS1_MCS2,
    67, //ATH_RATE_VHT20_NSS1_MCS3,
    68, //ATH_RATE_VHT20_NSS1_MCS4,
    69, //ATH_RATE_VHT20_NSS1_MCS5,
    70, //ATH_RATE_VHT20_NSS1_MCS6,
    71, //ATH_RATE_VHT20_NSS1_MCS7,
    72, //ATH_RATE_VHT20_NSS1_MCS8,
    73, //ATH_RATE_VHT20_NSS1_MCS9,	//69
//#if (WHAL_RX_NUM_CHAIN > 1)
//VHT20S2
    100, //ATH_RATE_VHT20_NSS2_MCS0,	//70
    101, //ATH_RATE_VHT20_NSS2_MCS1,
    102, //ATH_RATE_VHT20_NSS2_MCS2,
    103, //ATH_RATE_VHT20_NSS2_MCS3,
    104, //ATH_RATE_VHT20_NSS2_MCS4,
    105, //ATH_RATE_VHT20_NSS2_MCS5,
    106, //ATH_RATE_VHT20_NSS2_MCS6,
    107, //ATH_RATE_VHT20_NSS2_MCS7,
    108, //ATH_RATE_VHT20_NSS2_MCS8,
    109, //ATH_RATE_VHT20_NSS2_MCS9,	//79
//#endif
//#if (WHAL_RX_NUM_CHAIN > 2)
//VHT20S3
    136, //ATH_RATE_VHT20_NSS3_MCS0,	//80
    137, //ATH_RATE_VHT20_NSS3_MCS1,
    138, //ATH_RATE_VHT20_NSS3_MCS2,
    139, //ATH_RATE_VHT20_NSS3_MCS3,
    140, //ATH_RATE_VHT20_NSS3_MCS4,
    141, //ATH_RATE_VHT20_NSS3_MCS5,
    142, //ATH_RATE_VHT20_NSS3_MCS6,
    143, //ATH_RATE_VHT20_NSS3_MCS7,
    144, //ATH_RATE_VHT20_NSS3_MCS8,
    145, //ATH_RATE_VHT20_NSS3_MCS9,	//89
//#endif
//VHT40S1
    76, //ATH_RATE_VHT40_NSS1_MCS0,	//90
    77, //ATH_RATE_VHT40_NSS1_MCS1,
    78, //ATH_RATE_VHT40_NSS1_MCS2,
    79, //ATH_RATE_VHT40_NSS1_MCS3,
    80, //ATH_RATE_VHT40_NSS1_MCS4,
    81, //ATH_RATE_VHT40_NSS1_MCS5,
    82, //ATH_RATE_VHT40_NSS1_MCS6,
    83, //ATH_RATE_VHT40_NSS1_MCS7,
    84, //ATH_RATE_VHT40_NSS1_MCS8,
    85, //ATH_RATE_VHT40_NSS1_MCS9,	//99
//#if (WHAL_RX_NUM_CHAIN > 1)
//VHT40S2
    112, //ATH_RATE_VHT40_NSS2_MCS0,	//100
    113, //ATH_RATE_VHT40_NSS2_MCS1,
    114, //ATH_RATE_VHT40_NSS2_MCS2,
    115, //ATH_RATE_VHT40_NSS2_MCS3,
    116, //ATH_RATE_VHT40_NSS2_MCS4,
    117, //ATH_RATE_VHT40_NSS2_MCS5,
    118, //ATH_RATE_VHT40_NSS2_MCS6,
    119, //ATH_RATE_VHT40_NSS2_MCS7,
    120, //ATH_RATE_VHT40_NSS2_MCS8,
    121, //ATH_RATE_VHT40_NSS2_MCS9,	//109
//#endif
//#if (WHAL_RX_NUM_CHAIN > 2)
//VHT40S3
    148, //ATH_RATE_VHT40_NSS3_MCS0,	//110
    149, //ATH_RATE_VHT40_NSS3_MCS1,
    150, //ATH_RATE_VHT40_NSS3_MCS2,
    151, //ATH_RATE_VHT40_NSS3_MCS3,
    152, //ATH_RATE_VHT40_NSS3_MCS4,
    153, //ATH_RATE_VHT40_NSS3_MCS5,
    154, //ATH_RATE_VHT40_NSS3_MCS6,
    155, //ATH_RATE_VHT40_NSS3_MCS7,
    156, //ATH_RATE_VHT40_NSS3_MCS8,	
    157, //ATH_RATE_VHT40_NSS3_MCS9,	//119
//#endif
//VHT80S1
    88, //ATH_RATE_VHT80_NSS1_MCS0,	//120
    89, //ATH_RATE_VHT80_NSS1_MCS1,
    90, //ATH_RATE_VHT80_NSS1_MCS2,
    91, //ATH_RATE_VHT80_NSS1_MCS3,
    92, //ATH_RATE_VHT80_NSS1_MCS4,
    93, //ATH_RATE_VHT80_NSS1_MCS5,
    94, //ATH_RATE_VHT80_NSS1_MCS6,
    95, //ATH_RATE_VHT80_NSS1_MCS7,
    96, //ATH_RATE_VHT80_NSS1_MCS8,
    97, //ATH_RATE_VHT80_NSS1_MCS9,	//129
//#if (WHAL_RX_NUM_CHAIN > 1)
//VHT80S2
    124, //ATH_RATE_VHT80_NSS2_MCS0,	//130
    125, //ATH_RATE_VHT80_NSS2_MCS1,
    126, //ATH_RATE_VHT80_NSS2_MCS2,
    127, //ATH_RATE_VHT80_NSS2_MCS3,
    128, //ATH_RATE_VHT80_NSS2_MCS4,
    129, //ATH_RATE_VHT80_NSS2_MCS5,
    130, //ATH_RATE_VHT80_NSS2_MCS6,
    131, //ATH_RATE_VHT80_NSS2_MCS7,
    132, //ATH_RATE_VHT40_NSS2_MCS8,
    133, //ATH_RATE_VHT40_NSS2_MCS9,	//139
//#endif
//#if (WHAL_RX_NUM_CHAIN > 2)
//VHT80S3
    160, //ATH_RATE_VHT80_NSS3_MCS0,	//140
    161, //ATH_RATE_VHT80_NSS3_MCS1,
    162, //ATH_RATE_VHT80_NSS3_MCS2,
    163, //ATH_RATE_VHT80_NSS3_MCS3,
    164, //ATH_RATE_VHT80_NSS3_MCS4,
    165, //ATH_RATE_VHT80_NSS3_MCS5,
    166, //ATH_RATE_VHT80_NSS3_MCS6,
    167, //ATH_RATE_VHT80_NSS3_MCS7,
    168, //ATH_RATE_VHT80_NSS3_MCS8,
    169, //ATH_RATE_VHT80_NSS3_MCS9,	//149
//#endif
#endif // defined(AR9888) || defined(AR6320) || defined(AR900B)
    2, /* ATH_RATE_2M SHORT CCK */	//150
    4, /* ATH_RATE_5_5M SHORT CCK */	//151
    6, /* ATH_RATE_11M SHORT CCK */	//152
#if defined(AR900B) || defined(QCA9984) || defined(QCA9888)
//#if (WHAL_RX_NUM_CHAIN > 3)
    192, //ATH_RATE_VHT20_NSS4_MCS0 	change from 172 to 192 according to Mask2Rate table//153
    193, //ATH_RATE_VHT20_NSS4_MCS1 
    194, //ATH_RATE_VHT20_NSS4_MCS2 
    195, //ATH_RATE_VHT20_NSS4_MCS3 
    196, //ATH_RATE_VHT20_NSS4_MCS4 
    197, //ATH_RATE_VHT20_NSS4_MCS5 
    198, //ATH_RATE_VHT20_NSS4_MCS6 
    199, //ATH_RATE_VHT20_NSS4_MCS7 
    200, //ATH_RATE_VHT20_NSS4_MCS8 
    201, //ATH_RATE_VHT20_NSS4_MCS9 	//162
    202, //ATH_RATE_VHT40_NSS4_MCS0 	//163
    203, //ATH_RATE_VHT40_NSS4_MCS1 
    204, //ATH_RATE_VHT40_NSS4_MCS2 
    205, //ATH_RATE_VHT40_NSS4_MCS3 
    206, //ATH_RATE_VHT40_NSS4_MCS4 
    207, //ATH_RATE_VHT40_NSS4_MCS5 
    208, //ATH_RATE_VHT40_NSS4_MCS6 
    209, //ATH_RATE_VHT40_NSS4_MCS7 
    210, //ATH_RATE_VHT40_NSS4_MCS8 
    211, //ATH_RATE_VHT40_NSS4_MCS9 	//172
    212, //ATH_RATE_VHT80_NSS4_MCS0 	//173
    213, //ATH_RATE_VHT80_NSS4_MCS1 
    214, //ATH_RATE_VHT80_NSS4_MCS2 
    215, //ATH_RATE_VHT80_NSS4_MCS3 
    216, //ATH_RATE_VHT80_NSS4_MCS4 
    217, //ATH_RATE_VHT80_NSS4_MCS5 
    218, //ATH_RATE_VHT80_NSS4_MCS6 
    219, //ATH_RATE_VHT80_NSS4_MCS7 
    220, //ATH_RATE_VHT80_NSS4_MCS8 
    221, //ATH_RATE_VHT80_NSS4_MCS9 	//182
//#endif
#endif
#if defined(QCA9984) || defined(QCA9888)
    224, //ATH_RATE_VHT160_NSS1_MCS0, //183
    225, //ATH_RATE_VHT160_NSS1_MCS1,
    226, //ATH_RATE_VHT160_NSS1_MCS2,
    227, //ATH_RATE_VHT160_NSS1_MCS3,
    228, //ATH_RATE_VHT160_NSS1_MCS4,
    229, //ATH_RATE_VHT160_NSS1_MCS5,
    230, //ATH_RATE_VHT160_NSS1_MCS6,
    231, //ATH_RATE_VHT160_NSS1_MCS7,
    232, //ATH_RATE_VHT160_NSS1_MCS8,
    233, //ATH_RATE_VHT160_NSS1_MCS9,

    234, //ATH_RATE_VHT160_NSS2_MCS0,	  
    235, //ATH_RATE_VHT160_NSS2_MCS1,	  
    236, //ATH_RATE_VHT160_NSS2_MCS2,	 
    237, //ATH_RATE_VHT160_NSS2_MCS3,	
    238, //ATH_RATE_VHT160_NSS2_MCS4,	  
    239, //ATH_RATE_VHT160_NSS2_MCS5, 
    240, //ATH_RATE_VHT160_NSS2_MCS6,	 
    241, //ATH_RATE_VHT160_NSS2_MCS7,	  
    242, //ATH_RATE_VHT160_NSS2_MCS8,	  
    243, //ATH_RATE_VHT160_NSS2_MCS9,	//202

    256, //ATH_RATE_HT20_MCS24,		//203
    257, //ATH_RATE_HT20_MCS25,
    258, //ATH_RATE_HT20_MCS26,
    259, //ATH_RATE_HT20_MCS27,
    260, //ATH_RATE_HT20_MCS28,
    261, //ATH_RATE_HT20_MCS29,
    262, //ATH_RATE_HT20_MCS30,
    263, //ATH_RATE_HT20_MCS31,		//210

    264, //ATH_RATE_HT40_MCS24,		//211
    265, //ATH_RATE_HT40_MCS25,
    266, //ATH_RATE_HT40_MCS26,
    267, //ATH_RATE_HT40_MCS27,
    268, //ATH_RATE_HT40_MCS28,
    269, //ATH_RATE_HT40_MCS29,
    270, //ATH_RATE_HT40_MCS30,
    271, //ATH_RATE_HT40_MCS31,		//218
#endif
};


// TBD?? This should go away !!
// Also ensure the reasonable and consistent defaults with tcmd
static void setupRxParms(_CMD_RX_PARMS *utfParms, TCMD_CONT_RX *tcmdParms)
{
    tcmdParms->u.para.freq     = utfParms->channel;
    tcmdParms->act           = utfParms->rxMode;
    tcmdParms->enANI         = utfParms->enANI;
    tcmdParms->u.para.antenna  = utfParms->antenna;
    tcmdParms->u.para.wlanMode = utfParms->wlanMode;
    tcmdParms->u.para.rxChain = utfParms->rxChain;
    tcmdParms->u.para.bandwidth = utfParms->bandwidth;
    tcmdParms->u.para.bc = utfParms->bc;
    tcmdParms->u.para.ack = utfParms->ack;
    tcmdParms->u.para.lpl = utfParms->lpl;
    tcmdParms->u.para.freq2 = utfParms->channel2;

	//A_PRINTF("%s:ch1-ch2-setupRx: %d-%d\n", __func__ ,tcmdParms->u.para.freq, tcmdParms->u.para.freq2);
    //A_PRINTF("setup Rx Parms ACT %d channel %d\n",tcmdParms->act,tcmdParms->u.para.freq); 

    if ( tcmdParms->act == TCMD_CONT_RX_SET_ANT_SWITCH_TABLE ) {
        tcmdParms->u.antswitchtable.antswitch1 = utfParms->antswitch1;
        tcmdParms->u.antswitchtable.antswitch2 = utfParms->antswitch2;
    }

    if (tcmdParms->act == TCMD_CONT_RX_SETMAC) {
        A_MEMCPY((void*)&(tcmdParms->u.mac.addr[0]), (void*)&(utfParms->addr[0]), ATH_MAC_LEN);
        A_MEMCPY((void*)&(tcmdParms->u.mac.bssid[0]), (void*)&(utfParms->bssid[0]), ATH_MAC_LEN);
        A_MEMCPY((void*)&(tcmdParms->u.mac.btaddr[0]), (void*)&(utfParms->btaddr[0]), ATH_MAC_LEN);
    }

    return;
}

void sendResponse(wlan_tcmd_dev_t *dev);
void sendRxReportResponse(wlan_tcmd_dev_t *dev,TCMD_CONT_RX *contRx);
#if 0
void printRxStats(TCMD_CONT_RX *contRx);

void printRxStats(TCMD_CONT_RX *contRx)
{
     A_UINT32 i = 0;
     A_PRINTF_ALWAYS("totalPkt %d\n",contRx->u.report.totalPkt);
     A_PRINTF_ALWAYS("rssiInDBm %d\n",contRx->u.report.rssiInDBm);
     A_PRINTF_ALWAYS("crcErrPkt %d\n",contRx->u.report.crcErrPkt);
     A_PRINTF_ALWAYS("secErrPkt %d\n",contRx->u.report.secErrPkt);

     A_PRINTF_ALWAYS("RateCnt.. \n");
     for(i=0;i<TCMD_MAX_RATES;i++)
         A_PRINTF_ALWAYS("%d ",contRx->u.report.rateCnt[i]);
     A_PRINTF_ALWAYS("\n");

     A_PRINTF_ALWAYS("RateCnt Short Guard.. \n");
     for(i=0;i<TCMD_MAX_RATES;i++)
         A_PRINTF_ALWAYS("%d ",contRx->u.report.rateCntShortGuard[i]);
     A_PRINTF_ALWAYS("\n");
}
#endif

static _RX_NOTIFY_INFO RxNotifyInfo;

void setRxNotifyInfo (A_UINT32 expectedPkts, _CMDPROC_EVENT evt)
{
	if (hostTlvCmdProcess == FALSE)
	{
		// register call back
		A_MEMZERO((void*)&RxNotifyInfo, sizeof(RxNotifyInfo));
		RxNotifyInfo.expectedPkts = expectedPkts;
		RxNotifyInfo.evt2Notify   = evt;
		RxNotifyInfo.shouldHaveNotifiedTimes = 0;
		//A_PRINTF("..set RxNotify count cleard %d\n", RxNotifyInfo.shouldHaveNotifiedTimes);
		registerCallback(rxNotify, rxNotifyReg, &RxNotifyInfo);
	}
}

_CMDPROC_RC rxCmdProcessor_common(_CMD_ALL_PARMS *parms, A_UINT32 expectedPkts, _CMDPROC_EVENT evt, A_BOOL callerHandleRsp)
{
    _CMDPROC_RC rc=CMDPROC_RC_ASYNC;
    _CMD_RX_PARMS *rxParms=(_CMD_RX_PARMS*)&(parms->_cmdParmU._cmdRxParms);
    wlan_tcmd_dev_t *dev=&utf_dev;
    A_UINT32 ret=0;

    // setup rx
    //A_PRINTF("rx ch %d evt %d wlanM %d ant %d expPk %d\n", rxParms->channel, evt, rxParms->wlanMode, rxParms->antenna, rxParms->expectedPkts);
    //A_PRINTF("mac %x:%x:%x:", rxParms->addr[0], rxParms->addr[1], rxParms->addr[2]);
    //A_PRINTF("%x:%x:%x\n", rxParms->addr[3], rxParms->addr[4], rxParms->addr[5]);
    // for now, make up the rx parameters, TBD?? improve this
    // first set mac
    memset(&rx_tcmdParms,0,sizeof(rx_tcmdParms));

    setupRxParms(rxParms, (TCMD_CONT_RX *)&rx_tcmdParms);
 
    if (hostTlvCmdProcess == FALSE)
    {
        rx_tcmdParms.act = TCMD_CONT_RX_SETMAC;
        memcpy((void*)&(rx_tcmdParms.u.mac.addr[0]), (void*)&(rxParms->addr[0]), ATH_MAC_LEN);
        utfRxCmd(dev, (TCMD_CONT_RX *)&rx_tcmdParms);

        // second, set rx
        setupRxParms(rxParms, &rx_tcmdParms);
        rx_tcmdParms.act = TCMD_CONT_RX_FILTER;
    }

//// Check for rxstatus per rate flag ...
//// For now NART.. will send this
    if ( rxParms->flags & RX_STATUS_PER_RATE_MASK )
    {
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
        A_UINT32 act = rx_tcmdParms.act;

        rx_tcmdParms.act = TCMD_CONT_RX_SETMAC;

        memcpy((void*)&(rx_tcmdParms.u.mac.addr[0]), (void*)&(rxParms->addr[0]), ATH_MAC_LEN);
        memcpy((void*)&(rx_tcmdParms.u.mac.bssid[0]), (void*)&(rxParms->bssid[0]), ATH_MAC_LEN);

        utfRxCmd(dev, (TCMD_CONT_RX *)&rx_tcmdParms);

        setupRxParms(rxParms, &rx_tcmdParms);

        processRxStatusStartCmd(dev,rxParms);

        rx_tcmdParms.act = act;

        g_rx_opflags = rxParms->flags & NF_IN_DBM_MASK;
#endif
    }

    ret = utfRxCmd(dev, (TCMD_CONT_RX *)&rx_tcmdParms);

    if (callerHandleRsp)
    {
    	return (rc);
    }
    if (hostTlvCmdProcess == TRUE)
    {
        if ( ret == 1 ) {
            //printRxStats(&rx_tcmdParms);
            sendRxReportResponse(dev,&rx_tcmdParms);
            g_rx_opflags = 0;
        }
        else {
            sendResponse(dev);
        }
    }

    setRxNotifyInfo(expectedPkts, evt);

    // start a timer
    //A_PRINTF("timer started ...\n");
    //A_TIMEOUT_MS(&CmdStateInfo.rxSyncTimer, RX_SYNC_CMD_TIMEOUT_MS, FALSE); 

    // TBD?? potentially, either CMDPROC_RC_SYNC_FAIL or CMDPROC_RC_ASYNC
    //
    return(rc);
}

static _CMDPROC_RC rxCmdProcessor_sync(_CMD_ALL_PARMS *parms, A_UINT32 expectedPkts, _CMDPROC_EVENT evt)
{
    _CMDPROC_RC rc=CMDPROC_RC_ASYNC;
    _CMD_RX_PARMS *rxParms=(_CMD_RX_PARMS*)&(parms->_cmdParmU._cmdRxParms);
    TCMD_CONT_RX tcmdParms;
    wlan_tcmd_dev_t *dev=&utf_dev;

    // setup rx
    //A_PRINTF("rx ch %d evt %d wlanM %d ant %d expPk %d mac %x:%x:%x:%x:%x:%x\n", rxParms->channel, evt, rxParms->wlanMode, rxParms->antenna, rxParms->expectedPkts, rxParms->addr[0],rxParms->addr[1], rxParms->addr[2], rxParms->addr[3], rxParms->addr[4], rxParms->addr[5]);
    // for now, make up the rx parameters, TBD?? improve this
    // first set mac
    setupRxParms(rxParms, &tcmdParms);
    tcmdParms.act = TCMD_CONT_RX_SETMAC;
    memcpy((void*)&(tcmdParms.u.mac.addr[0]), (void*)&(rxParms->addr[0]), ATH_MAC_LEN);
    utfRxCmd(dev, (TCMD_CONT_RX *)&tcmdParms);

    // second, set rx
    setupRxParms(rxParms, &tcmdParms);
    tcmdParms.act = TCMD_CONT_RX_FILTER;
    utfRxCmd(dev, (TCMD_CONT_RX *)&tcmdParms);
 
    // register call back
    A_MEMZERO((void*)&RxNotifyInfo, sizeof(RxNotifyInfo));
    RxNotifyInfo.expectedPkts = expectedPkts;
    RxNotifyInfo.evt2Notify   = evt;
    RxNotifyInfo.shouldHaveNotifiedTimes = 0;
    //A_PRINTF("..set RxNotify count cleard %d\n", RxNotifyInfo.shouldHaveNotifiedTimes);
    registerCallback(rxNotify, rxNotifyReg, &RxNotifyInfo);

    // start a timer
    //A_PRINTF("timer started ...\n");
    //A_TIMEOUT_MS(&CmdStateInfo.rxSyncTimer, RX_SYNC_CMD_TIMEOUT_MS, FALSE); 

    // TBD?? potentially, either CMDPROC_RC_SYNC_FAIL or CMDPROC_RC_ASYNC
    return(rc);
}

static _CMDPROC_RC rxSyncCmdProcessor(_CMD_ALL_PARMS *parms)
{
    _CMDPROC_RC rc=CMDPROC_RC_ASYNC;
    //A_PRINTF("%s\n", __func__);
    rc = rxCmdProcessor_sync(parms, RX_SYNC_EXPECTED_NUM_PACKETS, EVT_RX_SYNC_AVAIL);
    //
    // start a timer
    //A_PRINTF("timer started ...\n");
    A_TIMEOUT_MS(&CmdStateInfo.rxSyncTimer, RX_SYNC_CMD_TIMEOUT_MS, FALSE); 

    return(rc);
}

static _CMDPROC_RC rxCmdProcessor(_CMD_ALL_PARMS *parms)
{
    _CMDPROC_RC rc=CMDPROC_RC_ASYNC;
    _CMD_RX_PARMS *rxParms=(_CMD_RX_PARMS*)&(parms->_cmdParmU._cmdRxParms);
    //A_PRINTF("%s\n", __func__);
    //
#if defined(AR900B)
    if(!(rxParms->rxMode == TCMD_CONT_RX_REPORT))
    {
    	if((rxParms->channel < CHAN_2G) && (g_opFlags == 1))
    	{
    		// 2G channel is selected, but boardOpflags is set for 5G, rx should be stopped
    		return 0;
    	}
    	if((rxParms->channel > CHAN_5G) && (g_opFlags == 2))
    	{
    		// 5G channel is selected, but boardOpflags is set for 2G, rx should be stopped
    		return 0;
    	}
    }
#endif

    rc = rxCmdProcessor_common(parms, rxParms->expectedPkts, EVT_RX_AVAIL, FALSE);
    //
    // start a timer
    //A_PRINTF("rx timer ...\n");
    if (hostTlvCmdProcess == FALSE)
        A_TIMEOUT_MS(&CmdStateInfo.rxTimer, RX_CMD_TIMEOUT_MS, FALSE); 

    // TBD?? potentially, either CMDPROC_RC_SYNC_FAIL, or RC_ASYNC
    return(rc);
}

static _CMDPROC_RC pmCmdProcessor(_CMD_ALL_PARMS *parms)
{
    _CMDPROC_RC rc=CMDPROC_RC_ASYNC;
    _CMD_PM_PARMS *pmParms=(_CMD_PM_PARMS*)&(parms->_cmdParmU._cmdPmParms);
    TCMD_PM tcmdParms;
    wlan_tcmd_dev_t *dev=&utf_dev;

    memset(&tcmdParms,0,sizeof(tcmdParms));

    tcmdParms.testCmdId = 0;
    tcmdParms.mode = pmParms->mode;

    utfPmCmd(dev, (TCMD_PM*)&tcmdParms);

    if ( hostTlvCmdProcess == TRUE )
        sendResponse(dev);

    return(rc);
}


static _CMDPROC_RC nartCmdProcessor(_CMD_ALL_PARMS *parms)
{
    _CMDPROC_RC rc=CMDPROC_RC_ASYNC;

#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
    wlan_tcmd_dev_t *dev=&utf_dev;
    _CMD_NARTCMD_PARMS *pParms=(_CMD_NARTCMD_PARMS*)&(parms->_cmdParmU._cmdNartCmdParms);
    processNartCommand(dev,pParms);
#endif

    return(rc);
}

#define DEFAULT_PWRGAIN_BEFORE_PARSED 20 
#define _DEFAULT_CHAIN_MASK 0x3
static void setupTxParms(_CMD_TX_PARMS *utfParms, TCMD_CONT_TX *tcmdParms)
{
    memset(tcmdParms,0,sizeof(TCMD_CONT_TX));

    tcmdParms->dutycycle = utfParms->dutyCycle;
    tcmdParms->mode = utfParms->txMode;
    tcmdParms->freq = utfParms->channel;
    /*tcmdParms->dataRate = utfParms->6;  // to be set later
    tcmdParms->txPwr = utfParms->14; */
    tcmdParms->antenna = utfParms->antenna;
    tcmdParms->enANI = utfParms->enANI;
    tcmdParms->scramblerOff = utfParms->scramblerOff;
    tcmdParms->aifsn = utfParms->aifsn;
    tcmdParms->pktSz = utfParms->pktSz;
    tcmdParms->txPattern = utfParms->txPattern;
    tcmdParms->shortGuard = utfParms->shortGuard;
    tcmdParms->numPackets = utfParms->numPackets;
    tcmdParms->wlanMode = utfParms->wlanMode;
    tcmdParms->tpcm = utfParms->tpcm;

    tcmdParms->miscFlags = utfParms->flags;
    tcmdParms->agg = utfParms->agg;
    tcmdParms->bandwidth = utfParms->bandwidth;/* automatic */
    tcmdParms->broadcast = utfParms->broadcast;

    // before pwrGain is extracted, a default value, not really useful
    tcmdParms->txPwr = DEFAULT_PWRGAIN_BEFORE_PARSED; 
    tcmdParms->dataRate = ATH_RATE_6M;
    tcmdParms->testCmdId = 0;
    tcmdParms->retries = 0; //??
    
    tcmdParms->gainIdx = (A_UINT8)utfParms->gainIdx;
    tcmdParms->dacGain = (A_INT8)utfParms->dacGain;
    tcmdParms->paConfig = (A_UINT8)utfParms->paConfig;

    A_MEMCPY(tcmdParms->bssid,utfParms->bssid,ATH_MAC_LEN);
    A_MEMCPY(tcmdParms->txStation,utfParms->txStation,ATH_MAC_LEN);
    A_MEMCPY(tcmdParms->rxStation,utfParms->rxStation,ATH_MAC_LEN);

    tcmdParms->nPattern = utfParms->nPattern;
    tcmdParms->freq2 = utfParms->channel2;
    A_MEMCPY(tcmdParms->dataPattern,utfParms->dataPattern,MPATTERN);

	
    //A_PRINTF("%s:ch1-ch2-bw-mode:setupTx: %d-%d-%d-%d\n", __func__, tcmdParms->freq, tcmdParms->freq2, tcmdParms->bandwidth, tcmdParms->wlanMode);

    return;
}

static void extractPwrGain(A_UINT32 bitPos, A_UINT32 maskRow, A_UINT32 *pwrGainStart, 
                              A_UINT32 *pwrGainEnd, A_UINT32 *pwrGainStep, A_BOOL is11Ac, A_BOOL is4x4Rate)
{
    _CMD_TX_PARMS *txParms=(_CMD_TX_PARMS*)&(_cmdParms._cmdParmU._cmdTxParms);
    A_UINT32 shift, row;
    shift = (bitPos % PWRGAIN_PER_PWRGAIN_ROW) * (PWRGAIN_PER_MASK_ROW);
    row = (bitPos / PWRGAIN_PER_PWRGAIN_ROW) + maskRow * (PWRGAIN_PER_MASK_ROW);

    if ( is11Ac == TRUE ) {
        if ( is4x4Rate == FALSE ) {
            *pwrGainStart = (txParms->pwrGnACStart[row] >> shift) & PWRGAIN_MASK;
        }
        else {
            *pwrGainStart = (txParms->pwrGnAC4x4[row] >> shift) & PWRGAIN_MASK;
        }
        *pwrGainEnd   = txParms->pwrGnACEnd;
        *pwrGainStep  = txParms->pwrGnACStep;
    }
    else { 
        *pwrGainStart = (txParms->pwrGainStart[row] >> shift) & PWRGAIN_MASK;
        *pwrGainEnd   = (txParms->pwrGainEnd[row] >> shift) & PWRGAIN_MASK;
        *pwrGainStep  = (txParms->pwrGainStep[row] >> shift) & PWRGAIN_MASK;
    }

    //NEGATE(*pwrGainStart);
    //NEGATE(*pwrGainEnd);   
    //NEGATE(*pwrGainStep);
    //A_PRINTF("row%d shift%d pStart%d pEnd%d pStep%d\n", row, shift, *pwrGainStart, *pwrGainEnd, *pwrGainStep);
    return;
}

A_UINT32 HT40_RateMask[RATE_MASK_ROW_MAX] = {
    0xFF000000,
    0xFF00FF00,
};

#if defined(_CCK_MODE_DONOT_MATTER)
A_UINT32 CCK_RateMask[RATE_MASK_ROW_MAX] = {
    0x0000007F,
    0x00000000,
};
#endif

//#define _USE_OLD_WAY 
//static _TX_NOTIFY_INFO TxNotifyInfo;
#define _MAX_NUM_TX_CHAINS 4
#define _MAX_NUM_TX_COMBINATION 1 

_CMDPROC_RC txCmdProcessor(_CMD_ALL_PARMS *parms)
{
    _CMDPROC_RC rc=CMDPROC_RC_SYNC_SUCC;
    _CMD_TX_PARMS *txParms=(_CMD_TX_PARMS*)&(parms->_cmdParmU._cmdTxParms);
    A_UINT32 rateMask;
    A_UINT32 i, k, index;
    A_UINT32 bit0 = 0x00000001;
    A_UINT32 dataRate = 0;
    wlan_tcmd_dev_t *dev=&utf_dev;
    A_UINT32 pwrGain, pwrGainStart, pwrGainEnd, pwrGainStep;    // pwrGain in 1/2dB step
    A_BOOL ret = FALSE;
    A_BOOL is11AcRate = FALSE;
    A_BOOL is4x4Rate = FALSE;

    // not overwrite tx_tcmdParms if this is an tx command with "go" option
    if (txParms->flags & TCMD_GO_MASK)
    {
    	tx_tcmdParms.miscFlags = txParms->flags;
    }
    else
    {
    	setupTxParms(txParms, (TCMD_CONT_TX *)&tx_tcmdParms);
    }
#if defined(AR900B)    
    if (!(tx_tcmdParms.mode == TCMD_CONT_TX_OFF))
    { /* otherwise causes TX Off hang bug */
    	if((txParms->channel < CHAN_2G) && (g_opFlags == 1))
    	{
    		// 2G channel is selected, but boardOpflags is set for 5G, rx should be stopped
    		return 0;
    	}
    	if((txParms->channel > CHAN_5G) && (g_opFlags == 2))
    	{
    		// 5G channel is selected, but boardOpflags is set for 2G, rx should be stopped
    		return 0;
    	}
    }
#endif
    
    // per channel reset
    //utfTxChannelSetup(dev, (TCMD_CONT_TX *)&tx_tcmdParms);

    if ( tx_tcmdParms.numPackets == 0xFFFFFFFF ) // -1
    {
        tx_tcmdParms.numPackets = 0;
        txParms->numPackets = 0;
    }

    if ( tx_tcmdParms.miscFlags & TX_STATUS_PER_RATE_MASK )
    {
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
#if 0
        ///TODO..for now use only one txchain per index...
        int chainIdx,numTx=0;
        tx_tcmdParms.txChain = 0;
        for (chainIdx = 0; chainIdx < _MAX_NUM_TX_CHAINS; chainIdx++)
        {
            if (txParms->txChain[chainIdx] & (1<<numTx)) {
                tx_tcmdParms.txChain |= (1<<chainIdx);
             }
        }
#endif
        tx_tcmdParms.txChain = txParms->txChain[0];
 

        processTxStatusStartPerRate(dev,txParms);
#endif
        ret = TRUE;
    }
    if ( hostTlvCmdProcess == TRUE )
        sendResponse(dev);

    if ( ret == TRUE )
        return rc;

    is11AcRate = FALSE;
    // parse the tx cmd, and calling tcmd tx command
    //RATE_MASK_ROW_MAX
    for (k=0; k<RATE_MASK_ROW_MAX; k++) {
        if ( k < RATE_MASK_ROW_MAX_11N ) {
            is11AcRate = FALSE;
            rateMask=txParms->rateMask[k];
            index = k;
        }
        else {
            if ( k == (RATE_MASK_ROW_MAX-3) ) {
                rateMask = txParms->rtMaskAC4x4;
				
				A_PRINTF("lim_debug rtMaskAC4x4 0x%x \n", rateMask);
		if (!rateMask && (txParms->rateBitIndex[0] >=  k * 32))
		{
		
			rateMask = txParms->rateBitIndex[0] - k * 32;
			rateMask = (0x1 << rateMask);
			
			//A_PRINTF("%s: rateBitIndex %d rateMask %d\n", __func__, txParms->rateBitIndex[0], rateMask);
		}
                index = 0;
                is4x4Rate = TRUE;
	    }
            else if ( k == (RATE_MASK_ROW_MAX-2) ) {   // cacscade
            
                rateMask = txParms->rtMaskAC160;
                
				//A_PRINTF("%s: rtMaskAC160 0x%x \n", __func__, rateMask);

                index = 0;	
                is4x4Rate = TRUE;          // waiting for power settings for Cascade 
            }
            else if ( k == (RATE_MASK_ROW_MAX-1) ) {   // 11n 4x4

                rateMask = txParms->rateBitIndex8;
                index = 0;
                is4x4Rate = TRUE;          // waiting for power settings for Cascade
            }
            else { 
                index = k - RATE_MASK_ROW_MAX_11N;
                rateMask =txParms->rateMask11AC[index];
            }
            is11AcRate = TRUE;
        }

        i=0; bit0=0x00000001;
        while (rateMask) {
            if (bit0 & rateMask) {
                rateMask &= ~bit0;
	        dataRate = (int)Mask2Rate[k][i];
	
                //A_PRINTF("dataRate %d\n",dataRate);

                extractPwrGain(i,index, &pwrGainStart, &pwrGainEnd, &pwrGainStep,is11AcRate,is4x4Rate);

                if (is11AcRate == FALSE ) {
                    if ( hostTlvCmdProcess == FALSE ) {
                        if (bit0 & HT40_RateMask[k]) {
                            if (TCMD_WLAN_MODE_HT40MINUS != tx_tcmdParms.wlanMode) {
                                tx_tcmdParms.wlanMode = TCMD_WLAN_MODE_HT40MINUS;
                                //utfTxChannelSetup(dev, (TCMD_CONT_TX *)&tx_tcmdParms);
                            }
                        }
#if defined(_CCK_MODE_DONOT_MATTER)
                        else if (bit0 & CCK_RateMask[k]) {
                            if (TCMD_WLAN_MODE_CCK != tx_tcmdParms.wlanMode) {
                                tx_tcmdParms.wlanMode = TCMD_WLAN_MODE_CCK;
                                //utfTxChannelSetup(dev, (TCMD_CONT_TX *)&tx_tcmdParms);
                            }
                        }
#endif
                        else {
                            if (TCMD_WLAN_MODE_HT20 != tx_tcmdParms.wlanMode) {
                                tx_tcmdParms.wlanMode = TCMD_WLAN_MODE_HT20;
                                //utfTxChannelSetup(dev, (TCMD_CONT_TX *)&tx_tcmdParms);
                            }
                        }
                    }
                }

                if (dataRate == ATH_RATE_2M || dataRate == ATH_RATE_5_5M || dataRate == ATH_RATE_11M){ /* CCK rates */
                    if (!(i&1)) /* even number indicates short preamble, see Mask2Rate array for details */
                        dataRate += (TCMD_11AC3x3_MAX_RATES - 1);
                        /* use last three rates (151/152/153) in the rate table for shortPreamble */
                }

                tx_tcmdParms.dataRate = dataRate;

                //A_PRINTF("..prep tx gainSt %d gainEn %d gainStep %d\n", pwrGainStart,pwrGainEnd,pwrGainStep);
#if 0
                if (CmdStateInfo.testConfig & TEST_CONFIG_CAL) {            
                        int chainIdx;
                        int numChains;
                        //if (txParms->txChain[MAX_TX_CHAIN -1]) numChains = MAX_TX_CHAIN -1;
                        //else 
                            numChains=3;  // default to 3
                        tx_tcmdParms.txChain = 0;
                        tx_tcmdParms.aifsn = 0;
                        for (chainIdx=0;chainIdx<numChains;chainIdx++) {
                            //tx_tcmdParms.txChain = chainIdx + 1;  // chainMask
                            tx_tcmdParms.txChain = (1 << chainIdx);  // chainMask
                            A_PRINTF("CAL: ch%d pwr%d rate%d nPk%d chain%d\n", tx_tcmdParms.freq, tx_tcmdParms.txPwr, tx_tcmdParms.dataRate, tx_tcmdParms.numPackets, tx_tcmdParms.txChain);
                            
                            utfTxStart(dev, (TCMD_CONT_TX *)&tx_tcmdParms);
                        }
                }
#endif
                for (pwrGain=pwrGainStart;pwrGain<=pwrGainEnd;pwrGain +=pwrGainStep) {
                    //tx_tcmdParms.txPwr = (pwrGain / 2);
                    tx_tcmdParms.txPwr = pwrGain;
                    //A_PRINTF("ch %d pwr %d rate %d numPkt %d mask %d\n", tx_tcmdParms.freq, tx_tcmdParms.txPwr, tx_tcmdParms.dataRate, tx_tcmdParms.numPackets, tx_tcmdParms.txChain);
                    // for CAL, automatically tx one chain at a time  
                    //if (CmdStateInfo.testConfig & TEST_CONFIG_CAL) {            
#if 0
                        int chainIdx;
                        int numChains;
                        //if (txParms->txChain[MAX_TX_CHAIN -1]) numChains = MAX_TX_CHAIN -1;
                        //else 
                            numChains=3;  // default to 3
                        tx_tcmdParms.txChain = 0;
                        tx_tcmdParms.aifsn = 0;
                        for (chainIdx=0;chainIdx<numChains;chainIdx++) {
                            //tx_tcmdParms.txChain = chainIdx + 1;  // chainMask
                            tx_tcmdParms.txChain = (1 << chainIdx);  // chainMask
                            A_PRINTF("CAL: ch%d pwr%d rate%d nPk%d chain%d\n", tx_tcmdParms.freq, tx_tcmdParms.txPwr, tx_tcmdParms.dataRate, tx_tcmdParms.numPackets, tx_tcmdParms.txChain);
                            
                            utfTxStart(dev, (TCMD_CONT_TX *)&tx_tcmdParms);
                        }
#endif
                    //}
                    //else {
#if 0
                        int chainIdx;
                        int numTx;
#endif

                        //A_PRINTF("txChain0 0x%x,txChain1 0x%x, txChain2 0x%x, txChain3 0x%x\n",txParms->txChain[0],txParms->txChain[1],txParms->txChain[2],txParms->txChain[3]);

                        tx_tcmdParms.txChain = txParms->txChain[0];

                        if (tx_tcmdParms.txChain) {
			     if (tx_tcmdParms.mode == TCMD_CONT_TX_FRAME)
					tx_tcmdParms.mode |= 0x100;/* do not wait for tx complete, setting this flag then the transmit status will be polled in the interrupt */
                           //A_PRINTF("%s txCmdPro ch%d pwr%d rate%d nPk%d chain%d\n", __func__, tx_tcmdParms.freq, tx_tcmdParms.txPwr, tx_tcmdParms.dataRate, tx_tcmdParms.numPackets, tx_tcmdParms.txChain);
                            utfTxStart(dev, (TCMD_CONT_TX *)&tx_tcmdParms);
                            A_PRINTF("ch%d pwr%d rate%d nPk%d cn%d\n", tx_tcmdParms.freq, tx_tcmdParms.txPwr, tx_tcmdParms.dataRate, tx_tcmdParms.numPackets, tx_tcmdParms.txChain);
                            }

#if 0
                        for (numTx=0; numTx < _MAX_NUM_TX_COMBINATION; numTx++) {
                            tx_tcmdParms.txChain = 0;
                            for (chainIdx = 0; chainIdx < _MAX_NUM_TX_CHAINS; chainIdx++)
                            {
                                if (txParms->txChain[chainIdx] & (1<<numTx)) {
                                    tx_tcmdParms.txChain |= (1<<chainIdx);
                                }
                            }
                            if (tx_tcmdParms.txChain) {
			          if (tx_tcmdParms.mode == TCMD_CONT_TX_FRAME)
					tx_tcmdParms.mode |= 0x100;/* do not wait for tx complete, setting this flag then the transmit status will be polled in the interrupt */
                                utfTxStart(dev, (TCMD_CONT_TX *)&tx_tcmdParms);
                                A_PRINTF("ch%d pwr%d rate%d nPk%d cn%d\n", tx_tcmdParms.freq, tx_tcmdParms.txPwr, tx_tcmdParms.dataRate, tx_tcmdParms.numPackets, tx_tcmdParms.txChain);
                                //A_PRINTF("thermCal=%d\n", ValuesOfInterest.thermCAL);
                            }
                        }
#endif

                    //}

                    // cont Tx support, only 1 rate
                    if (!txParms->numPackets) {break;}
                }

                // cont Tx support, only 1 rate
                if (!txParms->numPackets) {break;}
            }
            
            bit0 = bit0 << 1;i++;
        }
        // cont Tx support, only 1 rate
        /// No need to check numPackets here..
        //if (!txParms->numPackets) {break;}
    }

   // if (!(txParms->flags & TCMD_SETTUP_MASK) && txParms->numPackets) //#if !defined(_OLD_WAY)
    //    utfTxStop(dev,(TCMD_CONT_TX *)&tx_tcmdParms);

    return(rc);
} 

void sendResponse(wlan_tcmd_dev_t *dev)
{
    A_BOOL ret = FALSE;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 val = A_OK;

    ret = createCommand(_OP_GENERIC_RSP);

    if ( ret == TRUE ) {
        val = A_OK;
        ret = addParameterToCommand((A_UINT8*)"status",(A_UINT8*)&val);
        if ( ret == TRUE ) {
            ret = commandComplete(&rCmdStream, &cmdStreamLen );
            if ( ret == TRUE ) {
                 // Now let's send the response..
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
                 wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,_OP_GENERIC_RSP,(A_INT8*)rCmdStream);
#endif
            }
         }
    }
}

void getMask2RateFromRateIndex (A_UINT32 index, A_UINT32 *rateMaskRow, A_UINT32 *rateMaskBit) {
    A_UINT32 rateBitIndex=0;
    rateBitIndex = Rate2MaskBitNo[index];
    
    *rateMaskRow = rateBitIndex/32;

    if (*rateMaskRow >= 1 ){
        *rateMaskBit = rateBitIndex-(32* (*rateMaskRow));
    }
    else{
         *rateMaskBit = rateBitIndex;
    }

    if (rateBitIndex > 63 )
        *rateMaskRow = *rateMaskRow - 2;
}

//Input parms, buffer, integer value (buf should have enough space..)
//Concatenate buffer and integer value (strcat... not found)
//No sprintf...
void getConcatBuf(char *buf, int i, int len, int maxLen)
{
    int digitlen=0;
    char digits[2];

    if ( i == 0 ) {
        if ((len+1) >= maxLen)
        {
        	//A_PRINTF("getConcatBuf error len (%d) > maxLen (%d)\n", len, maxLen);
        	A_ASSERT(FALSE);
        	return;
        }
        buf[len] = 0x30;
        len++;
        buf[len] = 0;
        return;
    }

    while (i) {
        digits[digitlen] = (i%10);
        digitlen++;
        i = i /10;
    }

    while (digitlen) {
        if ((len+1) >= maxLen)
        {
        	//A_PRINTF("getConcatBuf error len (%d) > maxLen (%d)\n", len, maxLen);
        	A_ASSERT(FALSE);
        	return;
        }
        buf[len] = digits[digitlen-1]+0x30;
        len++;
        digitlen--;
    }

    buf[len] = 0;
}

void setIndex(A_UINT32 *highIndex, A_UINT32 *lowIndex,A_UINT32 offset ) 
{
    A_UINT32 value;

    if ( offset > 64 )
        return;

    if ( offset > 31 ) {
        value = 1 << offset;
        *highIndex = *highIndex | value;
    }
    else {
        value = 1 << (offset - 32);
        *lowIndex = *lowIndex | value;
    }
}

A_UINT8 report_Static[2048];

void setRates4Report (TCMD_CONT_RX *contRx, A_UINT32 *pShortGuard, A_UINT32 *pShortGuard11AC,
					A_UINT32 *pRateMask0, A_UINT32 *pRateMask1, A_UINT32 *rate11ACMask, A_UINT32 *pRate11AC4x4Mask)
{
    A_UINT32 value = 0,i=0;
    A_UINT32 rateBitIndex=0;
    A_UINT32 row=0,mask=0;
    A_UINT32 rateCnt;
    A_UINT32 rate11AC4x4Mask;
    A_UINT16 *rxReportCnt;

    rate11AC4x4Mask = 0;
    rxReportCnt = (A_UINT16*)&report_Static[0];

    //11n Rates..
	for(i=0;i<RATES_11_N;i++)
	{
		rateBitIndex = Rate2MaskBitNo[i];

		rateCnt = contRx->u.report.rateCnt[i];
	//    A_PRINTF("11n< rateBitIndex %d rateMask %d cnt %d\n",rateBitIndex,i,rateCnt);
		if (rateCnt) {
		//    A_PRINTF("11n< rateBitIndex %d rateMask %d cnt %d\n",rateBitIndex,i,rateCnt);
			setIndex(pRateMask1,pRateMask0,rateBitIndex);
		}
		else
		{
			rateCnt = contRx->u.report.rateCntShortGuard[i];
			if ( rateCnt ) {
				setIndex(pRateMask1,pRateMask0,rateBitIndex);
				setIndex(&pShortGuard[1], &pShortGuard[0], rateBitIndex);
			}
		}

		rxReportCnt[rateBitIndex] = rateCnt;
	}

	memset(rate11ACMask,0,sizeof(A_UINT32)*4);
    memset(pShortGuard11AC, 0, sizeof(A_UINT32)*5);

	//11AC.. rates
	for(i=RATES_11_N;i<TCMD_11AC3x3_MAX_RATES;i++)
	{
		rateBitIndex = Rate2MaskBitNo[i];

		rateCnt = contRx->u.report.rateCnt[i];

		getMask2RateFromRateIndex(i,&row,&mask);
	// A_PRINTF("11AC rateBitIndex %d rateMask %d cnt %d\n",rateBitIndex,i,rateCnt);
		if (rateCnt) {
			//A_PRINTF("11AC rateBitIndex %d rateMask %d cnt %d\n",rateBitIndex,i,rateCnt);
			value = 1 << mask;
			rate11ACMask[row] = rate11ACMask[row] | value;
		}
		else
		{
			rateCnt = contRx->u.report.rateCntShortGuard[i];
			if ( rateCnt ) {
				value = 1 << mask;
				rate11ACMask[row] = rate11ACMask[row] | value;
				pShortGuard11AC[row] = pShortGuard11AC[row] | value;
			}
		}

		rxReportCnt[rateBitIndex] = rateCnt;
	}

	//11AC 4x4.. rates
	for(i=(TCMD_11AC3x3_MAX_RATES + 3); i<TCMD_MAX_RATES;i++)
	{
		rateBitIndex = Rate2MaskBitNo[i];
		// A_PRINTF("4x4 11AC rateBitIndex %d rateMask %d cnt --bEFORE\n",rateBitIndex,i);
		rateCnt = contRx->u.report.rateCnt[i];
	// A_PRINTF("4x4 11AC rateBitIndex %d rateMask %d cnt %d\n",rateBitIndex,i,rateCnt);
		getMask2RateFromRateIndex(i,&row,&mask);

		if (rateCnt) {
		    value = 1 << mask;
		    *pRate11AC4x4Mask |= value;
	//A_PRINTF("4x4 11AC rateBitIndex %d rateMask %d cnt %d, rate11AC4x4Mask =%x\n",rateBitIndex, mask,rateCnt, rate11AC4x4Mask);

		}
		else
		{
			rateCnt = contRx->u.report.rateCntShortGuard[i];
			if ( rateCnt ) {
				value = 1 << mask;
				*pRate11AC4x4Mask |= value;
				pShortGuard11AC[4] |= value;
			}
		}

		rxReportCnt[rateBitIndex] = rateCnt;
	}

	/// CCK short
	//for(i=(TCMD_MAX_RATES-3);i<TCMD_MAX_RATES;i++)
	for(i=TCMD_11AC3x3_MAX_RATES;i<(TCMD_11AC3x3_MAX_RATES+3);i++)
	{
		rateBitIndex = Rate2MaskBitNo[i];

		rateCnt = contRx->u.report.rateCnt[i];
	//A_PRINTF("CCK rateBitIndex %d rateMask %d cnt %d\n",rateBitIndex,i,rateCnt);
		if (rateCnt) {
			//A_PRINTF("CCK rateBitIndex %d rateMask %d cnt %d\n",rateBitIndex,i,rateCnt);
			setIndex(pRateMask1,pRateMask0,rateBitIndex);
		}
		else
		{
			rateCnt = contRx->u.report.rateCntShortGuard[i];
			if ( rateCnt ) {
				setIndex(pRateMask1,pRateMask0,rateBitIndex);
				setIndex(&pShortGuard[1], &pShortGuard[0], rateBitIndex);
			}
		}

		rxReportCnt[rateBitIndex] = rateCnt;
	}
}

void sendRxReportResponse(wlan_tcmd_dev_t *dev,TCMD_CONT_RX *contRx)
{
    A_BOOL ret = FALSE;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 value = 0,i=0;
    A_INT32 rssi=0;
    A_UINT8 rateCntBuf[25];
    A_UINT32 j=0;
    A_UINT32 rateMask0=0,rateMask1=0;
    A_UINT32 rate11ACMask[4];
    A_UINT32 rate11AC4x4Mask = 0;
    A_UINT16 *rxReportCnt;
    A_UINT32 shortGuard[2], shortGuard11AC[5];

    ret = createCommand(_OP_SUBMIT_REPORT_RSP);

    rxReportCnt = NULL;

    if ( ret == TRUE )
    {
        //A_PRINTF_ALWAYS("totalPkt %d rssInDm %d crcErrPkt %d secErrPkt %d\n",contRx->u.report.totalPkt,
        //           contRx->u.report.rssiInDBm,contRx->u.report.crcErrPkt,contRx->u.report.secErrPkt);

        value = contRx->u.report.totalPkt;
        ret = addParameterToCommand((A_UINT8*)"totalpkt",(A_UINT8*)&value);
        rssi = contRx->u.report.rssiInDBm;
        ret = addParameterToCommand((A_UINT8*)"rssiInDBm",(A_UINT8*)&rssi);
        value = contRx->u.report.crcErrPkt;
        ret = addParameterToCommand((A_UINT8*)"crcErrPkt",(A_UINT8*)&value);
        value = contRx->u.report.secErrPkt;
        ret = addParameterToCommand((A_UINT8*)"secErrPkt",(A_UINT8*)&value);

        rxReportCnt = (A_UINT16*)&report_Static[0];//(A_UINT16 *)A_ALLOCRAM(250 * sizeof(A_UINT16));

        if( rxReportCnt == NULL ){
           // A_PRINTF("No Memory...\n");
            return;
        }

        memset(rxReportCnt,0,(222 * sizeof(A_UINT16)));
        //memset(rxReportCnt,0,(202 * sizeof(A_UINT16)));
          
        setRates4Report(contRx, shortGuard, shortGuard11AC, &rateMask0, &rateMask1, rate11ACMask, &rate11AC4x4Mask);

        addParameterToCommand((A_UINT8*)"rcMask0",(A_UINT8*)&rateMask0);
        addParameterToCommand((A_UINT8*)"rcMask1",(A_UINT8*)&rateMask1);

        //A_PRINTF("rcMask0 %x rateMask1 %x\n",rateMask0,rateMask1);

        for(i=0;i<4;i++) {
            memset(rateCntBuf,0,sizeof(rateCntBuf));
            A_STRNCPY((char*)rateCntBuf,"rcMask11ac", sizeof(rateCntBuf));
            getConcatBuf((char*)rateCntBuf,i, A_STRLEN(rateCntBuf), sizeof(rateCntBuf));

            addParameterToCommand((A_UINT8*)rateCntBuf,(A_UINT8*)&rate11ACMask[i]);
            //A_PRINTF("rcMask11ac%d %x\n",i,rate11ACMask[i]);
        }

        j = 0;
        for(i=0;i<32;i++) {
            memset(rateCntBuf,0,sizeof(rateCntBuf));
            A_STRNCPY((char*)rateCntBuf,"rateCnt", sizeof(rateCntBuf));
            getConcatBuf((char*)rateCntBuf,i, A_STRLEN(rateCntBuf), sizeof(rateCntBuf));
	    //A_PRINTF("rateCnt %d rateCnt0 %d\n",rxReportCnt[j+1],rxReportCnt[j]);
            value = (rxReportCnt[j+1] << 16) | rxReportCnt[j];
            if ( value ) {
                //A_PRINTF("rateCnt %d rateCnt0 %d\n",rxReportCnt[j+1],rxReportCnt[j]);
                ret = addParameterToCommand((A_UINT8*)rateCntBuf,(A_UINT8*)&value);
                //A_PRINTF("Insert rate %s value %x\n",rateCntBuf,value);
            }
            j = j+2;
        }

        j = 64;
        for(i=0;i<54;i++) {
            memset(rateCntBuf,0,sizeof(rateCntBuf));
            A_STRNCPY((char*)rateCntBuf,"rateCnt11ac", sizeof(rateCntBuf));
            getConcatBuf((char*)rateCntBuf,i, A_STRLEN(rateCntBuf), sizeof(rateCntBuf));

            value = rxReportCnt[j+1] << 16 | rxReportCnt[j];
	    //A_PRINTF_ALWAYS("Insert rate %s value %d\n",rateCntBuf,value);
		
            if ( value ) {
                ret = addParameterToCommand((A_UINT8*)rateCntBuf,(A_UINT8*)&value);
                //A_PRINTF_ALWAYS("Insert rate %s value %d\n",rateCntBuf,value);
            }
            j = j + 2;
        }
	
	//A_PRINTF_ALWAYS("rcMaskac4x4 =%x\n", rate11AC4x4Mask);
	
        addParameterToCommand((A_UINT8*)"rcMaskac4x4",(A_UINT8*)&rate11AC4x4Mask);
	
	

        j = 192;   // 172;
        for(i=0;i<15;i++) {
            memset(rateCntBuf,0,sizeof(rateCntBuf));
            A_STRNCPY((char*)rateCntBuf,"rtCntac4x4", sizeof(rateCntBuf));
            getConcatBuf((char*)rateCntBuf,i, A_STRLEN(rateCntBuf), sizeof(rateCntBuf));

            value = rxReportCnt[j+1] << 16 | rxReportCnt[j];
	    if ( value ) {
                ret = addParameterToCommand((A_UINT8*)rateCntBuf,(A_UINT8*)&value);
             //   A_PRINTF_ALWAYS("rtCntac4x4 insert rate %s value %d\n",rateCntBuf,value);
            }
            j = j + 2;
        }



        ret = addParameterToCommand((A_UINT8*)"shortGuard",(A_UINT8*)&shortGuard);

        if ( ret == TRUE )
        { 
            ret = commandComplete(&rCmdStream, &cmdStreamLen );
            if ( ret == TRUE )
            {
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
                 wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,_OP_SUBMIT_REPORT_RSP,(A_INT8*)rCmdStream);
#endif
             }
         }

         //A_FREE(rxReportCnt);
     }
}

// tx cmd parms template
static _CMD_TX_PARMS _txCmdParms =
{
    2412,                // channel;
    //TCMD_CONT_TX_SINE,
    //TCMD_CONT_TX_TX99,   // txMode;
    TCMD_CONT_TX_FRAME,   // txMode;
   {0x00008000,          // rateMask0;
    0x0},                // rateMask1;

    // start power/gain
   {0x1c1c1c1c,          // pwrGainStart0;       // cck 
    0x1c1c1c1c,          // pwrGainStart1;       // cck 
    0x1c1c1c1c,          // pwrGainStart2;       // ofdm
    0x1a1a1c1c,          // pwrGainStart3;       // ofdm
    0x20202020,          // pwrGainStart4;       // ht20-1
    0x181c1e20,          // pwrGainStart5;       // ht20-1
    0x1e1e1e1e,          // pwrGainStart6;       // ht40-1
    0x181a1c1e,          // pwrGainStart7;       // ht40-1
    0x20202020,          // pwrGainStart8;       // ht20-2
    0x181c1e20,          // pwrGainStart9;       // ht20-2
    0x1e1e1e1e,          // pwrGainStart10;       // ht40-2
    0x181a1c1e,          // pwrGainStart11;       // ht40-2
    0x20202020,          // pwrGainStart12;       // ht20-3
    0x181c1e20,          // pwrGainStart13;       // ht20-3
    0x1e1e1e1e,          // pwrGainStart14;       // ht40-3
    0x181a1c1e},         // pwrGainStart15;       // ht40-3

    // end power/gain
   {0x1c1c1c1c,          // pwrGainEnd0;       // cck 
    0x1c1c1c1c,          // pwrGainEnd1;       // cck 
    0x1c1c1c1c,          // pwrGainEnd2;       // ofdm
    0x1a1a1c1c,          // pwrGainEnd3;       // ofdm
    0x20202020,          // pwrGainEnd4;       // ht20-1
    0x181c1e20,          // pwrGainEnd5;       // ht20-1
    0x1e1e1e1e,          // pwrGainEnd6;       // ht40-1
    0x181a1c1e,          // pwrGainEnd7;       // ht40-1
    0x20202020,          // pwrGainEnd8;       // ht20-2
    0x181c1e20,          // pwrGainEnd9;       // ht20-2
    0x1e1e1e1e,          // pwrGainEnd10;       // ht40-2
    0x181a1c1e,          // pwrGainEnd11;       // ht40-2
    0x20202020,          // pwrGainEnd12;       // ht20-3
    0x181c1e20,          // pwrGainEnd13;       // ht20-3
    0x1e1e1e1e,          // pwrGainEnd14;       // ht40-3
    0x181a1c1e},         // pwrGainEnd15;       // ht40-3

    // pwrGain step
   {0x01010101,          // pwrGainStep0;        // cck 
    0x01010101,          // pwrGainStep1;        // cck 
    0x01010101,          // pwrGainStep2;        // ofdm
    0x01010101,          // pwrGainStep3;        // ofdm 
    0x01010101,          // pwrGainStep4;        // ht20-1
    0x01010101,          // pwrGainStep5;        // ht20-1
    0x01010101,          // pwrGainStep6;        // ht40-1
    0x01010101,          // pwrGainStep7;        // ht40-1
    0x01010101,          // pwrGainStep8;        // ht20-2
    0x01010101,          // pwrGainStep9;        // ht20-2 
    0x01010101,          // pwrGainStep10;       // ht40-2 
    0x01010101,          // pwrGainStep11;       // ht40-2
    0x01010101,          // pwrGainStep12;       // ht20-3
    0x01010101,          // pwrGainStep13;       // ht20-3
    0x01010101,          // pwrGainStep14;       // ht40-3
    0x01010101},         // pwrGainSetp15;       // ht40-3

    0,                   // antenna;
    0,                   // enANI;
    0,                   // scramblerOff;
    0,                   // aifsn;
    0,                   // pktSz;
    0,                   // txPattern;
    0,                   // shortGuard;
    0,                   // numPackets;
    1, //MODE_11G,            // wlanMode;
   {0x5,                 // txChain0;
    0x6,                 // txChain1;
    0x0,                 // txChain2;
    0x0},                // txChain3;
    TPC_TX_PWR,          // tpcm;
    0,                   // flags;
    1,                   // agg;
    0,                   // broadcast;
    0,                   // bandwidth;
    {0x01, 0x00, 0x00, 0xCA, 0xFF, 0xEE}, //bssid[ATH_MAC_LEN];
    {0x00, 0x03, 0x7F, 0x03, 0x40, 0x33}, //txStation[ATH_MAC_LEN];
    {0x00, 0x03, 0x7F, 0x11, 0x12, 0x13}, //rxStation[ATH_MAC_LEN];0xff, 0xff, 0xff, 0xff, 0xff, 0xff
    {0x00,0x00}, //A_UCHAR reserved;
    0, // dutyCycle
    0, // pattern
    0, // reserved1
    {0}, // dataPattern
    {0x8, //rateBitIndex0
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF}, //rateBitIndex7
    {0x1C, //tx power0
    0xF,
    0xF,
    0xF,
    0xF,
    0xF,
    0xF,
    0xF}, //tx power7
    {0x3E8, // pkt length0
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0}, //pkt length7
    {0x1, //aggregation0
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0}, //aggregration7
    0x0, //ir
    {0x0, //rateMask11AC0
    0x0,
    0x0,
    0x0}, //rateMask11AC3
    // start power/gain 11ac
   {0x1c1c1c1c,          // pwrGnACStart0; 
    0x1c1c1c1c,          // pwrGnACStart1; 
    0x1c1c1c1c,          // pwrGnACStart2;
    0x1c1c1c1c,          // pwrGnACStart3
    0x1c1c1c1c,          // pwrGnACStart4;
    0x1c1c1c1c,          // pwrGnACStart5;
    0x1c1c1c1c,          // pwrGnACStart6;
    0x1c1c1c1c,          // pwrGnACStart7;
    0x1c1c1c1c,          // pwrGnACStart8;
    0x1c1c1c1c,          // pwrGnACStart9;
    0x1c1c1c1c,          // pwrGnACStart10;
    0x1c1c1c1c,          // pwrGnACStart11;
    0x1c1c1c1c,          // pwrGnACStart12;
    0x1c1c1c1c,          // pwrGnACStart13;
    0x1c1c1c1c,          // pwrGnACStart14;
    0x1c1c1c1c,          // pwrGnACStart15;
    0x1c1c1c1c,          // pwrGnACStart16; 
    0x1c1c1c1c,          // pwrGnACStart17;
    0x1c1c1c1c,          // pwrGnACStart18;
    0x1c1c1c1c,          // pwrGnACStart19;
    0x1c1c1c1c,          // pwrGnACStart20;
    0x1c1c1c1c,          // pwrGnACStart21;
    0x1c1c1c1c,          // pwrGnACStart22;
    0x1c1c1c1c,          // pwrGnACStart23;
    0x1c1c1c1c,          // pwrGnACStart24;
    0x1c1c1c1c,          // pwrGnACStart25;
    0x1c1c1c1c},         // pwrGnACStart26;
    0x1c, //pwrEnd  sweep 11AC??
    0x1,  //pwrStep sweep 11AC??
    15,    //gainIdx
    0,    //dacGain
    0,    //paConfig
    0,    //reserved2
    0,    //rtMaskAC4x4
   {0x1c1c1c1c,          // pwrGnAC4x40; 
    0x1c1c1c1c,          // pwrGnAC4x41; 
    0x1c1c1c1c,          // pwrGnAC4x42;
    0x1c1c1c1c,          // pwrGnAC4x43;
    0x1c1c1c1c,          // pwrGnAC4x44;
    0x1c1c1c1c,          // pwrGnAC4x45;
    0x1c1c1c1c,          // pwrGnAC4x46;
    0x1c1c1c1c,          // pwrGnAC4x47;
    0x1c1c1c1c},         // pwrGnAC4x48;
};

// rx cmd parms template
// This is only needed because whalSetMac doesn't seem to work ...
static _CMD_RX_PARMS _rxSyncCmdParms={
    2412, //A_UINT32  channel;
    TCMD_CONT_RX_FILTER,//1, //TCMD_CONT_RX_FILTER, //A_UINT32  rxMode; //act;
    //TCMD_CONT_RX_PROMIS,//1, //TCMD_CONT_RX_FILTER, //A_UINT32  rxMode; //act;
    0, //A_UINT32  enANI;
    0, //A_UINT32  antenna;
    1, //MODE_11G, //A_UINT32  wlanMode;
    7, //RX chain, 
    1, //expectedPackets
    1, //ack
    1, //A_UINT32 bc
    0, //A_UINT32  bandwidth;
    0, //A_UNT32   lpl;
    0, //A_UINT32  antswitch1;
    0, //A_UINT32  antswitch2;
    {0x00, 0x03, 0x7F, 0x11, 0x12, 0x13}, //A_UCHAR   addr[ATH_MAC_LEN];
    {0x01, 0x00, 0x00, 0xCA, 0xFF, 0xEE}, //A_UCHAR   bssid[ATH_MAC_LEN];
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, //A_UCHAR   btaddr[ATH_MAC_LEN];
    {0x00,0x00}, //A_UCHAR reserved;
    {0x00,0x00}, //A_UCHAR regDmn;
    0, //A_UINT32 otpWriteFlag;
    0, //A_UINT32 flags;
    {0x00008000,0x0,0x0,0x0,0x0,0x0},      // rateMask0,rateMask1,rateMask2,rateMask3,rateMask4,rateMask5,
    0,
    0,
    0,    //rateMask6
    0,    //rateMask7
    2412, //channel2 for Cascade
    0,    //rateMask8
};

static _CMD_RX_PARMS _rxCmdParms={
    2412, //A_UINT32  channel;
    TCMD_CONT_RX_FILTER,//1, //TCMD_CONT_RX_FILTER, //A_UINT32  rxMode; //act;
    //TCMD_CONT_RX_PROMIS,//1, //TCMD_CONT_RX_FILTER, //A_UINT32  rxMode; //act;
    0, //A_UINT32  enANI;
    0, //A_UINT32  antenna;
    1, //MODE_11G, //A_UINT32  wlanMode;
    7, //RX chain, 
    1, //expectedPackets
    1, //ack
    1, //A_UINT32 bc
    0, //A_UINT32  bandwidth;
    0, //A_UNT32   lpl;
    0, //A_UINT32  antswitch1;
    0, //A_UINT32  antswitch2;
    {0x00, 0x03, 0x7F, 0x11, 0x12, 0x13}, //A_UCHAR   addr[ATH_MAC_LEN];
    {0x01, 0x00, 0x00, 0xCA, 0xFF, 0xEE}, //A_UCHAR   bssid[ATH_MAC_LEN];
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, //A_UCHAR   btaddr[ATH_MAC_LEN];
    {0x00,0x00}, //A_UCHAR reserved;
    {0x00,0x00}, //A_UCHAR regDmn;
    0, //A_UINT32 otpWriteFlag;
    0, //A_UINT32 flags;
    {0x00008000,0x0,0x0,0x0,0x0,0x0},      // rateMask0,rateMask1,rateMask2,rateMask3,rateMask4,rateMask5
    0,
    0,
    0,    //rateMask6
    0,    //rateMask7
    2412, //channel2 for Cascade
    0,    //rateMask8
};

// There isn't any default values for calCmdParms
//static _CMD_CAL_PARMS _calCmdParms; 

static A_BOOL cmdParmsParser_common(A_UINT8 *cmdParmBuf, _CMD_ALL_PARMS **parms, A_UINT8 numOfParms, void*cmdParms, _PARM_BIN_TEMPLATE *_parm_bin_template)
{
    _PARM_ONEOF   *oneParm;
    A_UINT32 pos, offset,shift;
    size_t   size;
    A_UINT32  parmCode, parmType;
    A_UINT8 *parmValStart;
    A_INT32  i;

    pos=0;
    for (i=0;i<numOfParms;i++) {
        oneParm = (_PARM_ONEOF *)(&cmdParmBuf[pos]);
        parmCode = oneParm->parmCode;
        parmType = oneParm->parmType;

        offset = _parm_bin_template[parmCode].offset;
        size   = _parm_bin_template[parmCode].len;
        shift = 0;

        if ((A_UINT8)_PARM_U8 == parmType || _PARM_S8 == parmType)
            parmValStart = (A_UINT8 *)&(oneParm->parmValue.addr[0]);
        else if ((A_UINT8)_PARM_DATA == parmType) {
            parmValStart = (A_UINT8 *)&cmdParmBuf[pos + sizeof(_PARM_ONEOF)];
            shift = size = oneParm->parmValue.value.val16;
        }
        else if ((A_UINT8)_PARM_U16 == parmType || _PARM_S16 == parmType)
            parmValStart = (A_UINT8 *)&(oneParm->parmValue.value.val16);
        else 
            parmValStart = (A_UINT8 *)&(oneParm->parmValue.value.val32);

        A_MEMCPY((void*)(((A_UINT8 *)cmdParms)+offset), (void*)parmValStart, size);

        //A_PRINTF("tx pC %d pT %d of %d si %d\n", parmCode, parmType, offset, size);  

        pos += sizeof(_PARM_ONEOF);
        pos += shift;
    }
    
    *parms = (_CMD_ALL_PARMS *)&_cmdParms;

#if 0
	{	
		_CMD_RX_PARMS *ptr_test;
		int ii;
		A_UINT8 *ptr_b;
		ptr_test = (_CMD_RX_PARMS *)&_cmdParms;
		
		A_PRINTF("%s:ch1-ch2-rx-size: %d-%d-%d-%d-%d\n",__func__, ptr_test->channel, ptr_test->channel2, ptr_test->wlanMode, sizeof(_CMD_RX_PARMS), ptr_test->rateMask7);  
	
		ptr_b = (A_UINT8 *)&_cmdParms;

	    A_PRINTF("%s:dump buf in byte:\n",__func__);
		for (ii=0; ii< 128; ii++)
		{
			if (ii%8 == 0)
			A_PRINTF("\n"); 
			A_PRINTF("0x%02x ", *ptr_b++);   
		}
		
		A_PRINTF("\n"); 
	 }
#endif

	 //A_PRINTF("%s:ch1-ch2-Tx-Rxmode: %d-%d-%d-%d-%d-%d\n", __func__ ,_cmdParms._cmdParmU._cmdTxParms.channel, _cmdParms._cmdParmU._cmdTxParms.channel2, _cmdParms._cmdParmU._cmdTxParms.txMode, _cmdParms._cmdParmU._cmdRxParms.channel2, _cmdParms._cmdParmU._cmdRxParms.rxMode);  

    return(TRUE);
}

static A_BOOL txCmdParmsParser(A_UINT8 *cmdParmBuf, _CMD_ALL_PARMS **parms, A_UINT8 numOfParms)
{
	_CMD_TX_PARMS *txCmdParms = (_CMD_TX_PARMS *)&(_cmdParms._cmdParmU._cmdTxParms);
    memset((void*)txCmdParms,0, sizeof(_CMD_TX_PARMS));
    memcpy((void*)txCmdParms, (void*)&_txCmdParms, sizeof(_CMD_TX_PARMS));
    return(cmdParmsParser_common(cmdParmBuf, parms, numOfParms, (void*)txCmdParms, _txParm_bin_template));
}


// The only reason for separate rxCmd/rxSyncCmdParmsParser is the set mac addr doesn't work in HAL
static A_BOOL rxSyncCmdParmsParser(A_UINT8 *cmdParmBuf, _CMD_ALL_PARMS **parms, A_UINT8 numOfParms)
{
    _CMD_RX_PARMS *rxCmdParms = (_CMD_RX_PARMS *)&(_cmdParms._cmdParmU._cmdRxParms);
    memset((void*)rxCmdParms,0, sizeof(_CMD_RX_PARMS));
    memcpy((void*)rxCmdParms, (void*)&_rxSyncCmdParms, sizeof(_CMD_RX_PARMS));
    return(cmdParmsParser_common(cmdParmBuf, parms, numOfParms, (void*)rxCmdParms, _rxParm_bin_template));
}

static A_BOOL rxCmdParmsParser(A_UINT8 *cmdParmBuf, _CMD_ALL_PARMS **parms, A_UINT8 numOfParms)
{
    _CMD_RX_PARMS *rxCmdParms = (_CMD_RX_PARMS *)&(_cmdParms._cmdParmU._cmdRxParms);
    memset((void*)rxCmdParms,0, sizeof(_CMD_RX_PARMS));
    memcpy((void*)rxCmdParms, (void*)&_rxCmdParms, sizeof(_CMD_RX_PARMS));
    return(cmdParmsParser_common(cmdParmBuf, parms, numOfParms, (void*)rxCmdParms, _rxParm_bin_template));
}

static A_BOOL pmCmdParmsParser(A_UINT8 *cmdParmBuf, _CMD_ALL_PARMS **parms, A_UINT8 numOfParms)
{
    _CMD_PM_PARMS *pmCmdParms = (_CMD_PM_PARMS *)&(_cmdParms._cmdParmU._cmdPmParms);
    memset((void*)pmCmdParms,0, sizeof(_CMD_PM_PARMS));
    return(cmdParmsParser_common(cmdParmBuf, parms, numOfParms, (void*)pmCmdParms, _pmParm_bin_template));
}

static A_BOOL nartCmdParmsParser(A_UINT8 *cmdParmBuf, _CMD_ALL_PARMS **parms, A_UINT8 numOfParms)
{
    _CMD_NARTCMD_PARMS *pCmdParms = (_CMD_NARTCMD_PARMS *)&(_cmdParms._cmdParmU._cmdNartCmdParms);
    memset((void*)pCmdParms,0, sizeof(_CMD_NARTCMD_PARMS));
    return(cmdParmsParser_common(cmdParmBuf, parms, numOfParms, (void*)pCmdParms, _nartCmdParm_bin_template));
}

//    - CMD_CAL_DONE as a command event is sent to CMD_PROCESSING_STATE and proper event handler is called.
//    - The evtCalDoneCmdHandler calls generic evtHandler, which searches CmdHandlers based on opCode.
//    - The cmdCalDoneProcessor does the following:
//      - undo whalReset behavior modification at the beginning of CAL
//      - start a poll time for CAL data
//      - returns SYNC_CMD success
//    - evtCalDoneCmdProcessor then moves the state to WAIT_4_CAL_DATA_STATE, and indicate _CMDPROC_END.
//
static _CMDPROC_RC calDoneCmdProcessor(_CMD_ALL_PARMS *parms)
{
    //A_PRINTF("%s\n", __func__);
    wlan_tcmd_dev_t *dev=&utf_dev;

    // undo what CAL has done
    A_MEMZERO((void*)&_PostWhalResetSettings, sizeof(_PostWhalResetSettings));

    // start the CAL data poll timer
    A_TIMEOUT_MS(&CmdStateInfo.calDataPollTimer, CAL_DATA_POLL_PERIOD_MS, FALSE); 

    CmdStateInfo.testConfig &= ~TEST_CONFIG_CAL;             

    if ( hostTlvCmdProcess == TRUE )
        sendResponse(dev);

    return(CMDPROC_RC_ASYNC);
}

static void whalPostSetPwrProc4CAL(A_UINT16 pcDac)
{
    // setup for forced gain tx or tgt power measurement
    if (!(CmdStateInfo.testConfig & TEST_CONFIG_CAL_W_TGTPWR)) {
        //A_PRINTF("forceG%d\n", pcDac);
        // TBD? Need chainMask info???
        whalForceTxGain(pcDac);
        //whalDoCalibration(TRUE);
    }
    if (CmdStateInfo.testConfig & TEST_CONFIG_CAL) {            
        // setup for olpc CAL
        whalPostResetSetupOlpcCAL(0);
    }
}

static void whalPostResetProc4CAL(void* data)
{
    // setup for olpc CAL
    whalPostResetSetupOlpcCAL(data);

    // overwrite reset ini register values, e.g. eep
    whalPostResetRegOverwrite(data);
}

/* For Peregrine bring-up, before TS functionality is fully restored, borrow this existing CAL command to
 * sweep, characterize, and CAL.
 * This is really a hack, and will be done properly through test script once the dust settles.
 */
#define _4_PERE_BRINGUP_BEFORE_TS_READY_TOBE_REMOVED_AFTER
#if defined(_4_PERE_BRINGUP_BEFORE_TS_READY_TOBE_REMOVED_AFTER)
#include "calTxPwrConfig.code"

#if 0
static void txCAL_old(_CMD_ALL_PARMS *parms)
{
    _CMD_TX_PARMS *txParms=(_CMD_TX_PARMS*)&(parms->_cmdParmU._cmdTxParms);
    wlan_tcmd_dev_t *dev=&utf_dev;

    setupTxParms(txParms, &tx_tcmdParms);

    tx_tcmdParms.dataRate = ATH_RATE_6_5M;

    //if (CmdStateInfo.testConfig & TEST_CONFIG_CAL) 
    {            
                        int chainIdx;
                        tx_tcmdParms.txChain = 0;
                        tx_tcmdParms.aifsn = 0;
                        for (chainIdx=0;chainIdx<NumCALChainMasks;chainIdx++) {
                            tx_tcmdParms.txChain = CALChainMaskList[chainIdx];  // chainMask
                            A_PRINTF("CAL: ch%d pwr%d rate%d nPk%d chain%d\n", tx_tcmdParms.freq, tx_tcmdParms.txPwr, tx_tcmdParms.dataRate, tx_tcmdParms.numPackets, tx_tcmdParms.txChain);
                            
                            utfTxStart(dev, (TCMD_CONT_TX *)&tx_tcmdParms);
                            //A_DELAY_USECS(1000000);

                            utfTxStop(dev,(TCMD_CONT_TX *)&tx_tcmdParms);
                            A_DELAY_USECS(800000);
                        }
    }

    return;
} 
#endif

#if 0
static void setup2Use_txCmdProcessor(A_UINT32 channel, A_UINT32 *rateMask, A_UINT32 *rateMask11AC, A_UINT32 *txChain, A_UINT32 gainIdx, A_INT32 dac)
{
    _CMD_TX_PARMS txCmdParms; 
    _CMD_ALL_PARMS *pCmdParms = (_CMD_ALL_PARMS*)&txCmdParms;
    A_MEMZERO((void*)&txCmdParms, sizeof(_CMD_TX_PARMS));
    A_MEMCPY((void*)&txCmdParms, (void*)&_txCmdParms, sizeof(_CMD_TX_PARMS));

    /* setup relevant field for forced gain idx mode */
    txCmdParms.channel = channel;

    A_MEMCPY((void*)&(txCmdParms.rateMask[0]), (void*)&(rateMask[0]),  sizeof(txCmdParms.rateMask));
    A_MEMCPY((void*)&(txCmdParms.rateMask11AC[0]), (void*)&(rateMask11AC[0]),  sizeof(txCmdParms.rateMask11AC));
    A_MEMCPY((void*)&(txCmdParms.txChain[0]), (void*)&(txChain[0]), sizeof(txCmdParms.txChain));

    txCmdParms.tpcm = TPC_FORCED_GAINIDX; 
    txCmdParms.gainIdx = (A_UINT16)gainIdx;
    txCmdParms.dacGain = (A_INT16)dac; 
    txCmdParms.numPackets = _CAL_TX_NUM_PACKETS;

    /* simply call txCmdProcessor, a hack */
    A_PRINTF_ALWAYS("ch:%d, rates:0x%x 0x%x ", (int)txCmdParms.channel, (int)txCmdParms.rateMask[0], (int)txCmdParms.rateMask[1]);
    A_PRINTF_ALWAYS("0x%x 0x%x 0x%x 0x%x, ",  (int)txCmdParms.rateMask11AC[0], (int)txCmdParms.rateMask11AC[1], (int)txCmdParms.rateMask11AC[2], (int)txCmdParms.rateMask11AC[3]);
    A_PRINTF_ALWAYS("chain: 0x%x 0x%x 0x%x %d %d\n",  (int)txCmdParms.txChain[0], (int)txCmdParms.txChain[1], 
       (int)txCmdParms.txChain[2], (int)txCmdParms.gainIdx, (int)txCmdParms.dacGain);

    txCAL_old(pCmdParms);

}
#endif

// set up txCmdProcessor to work
static void makeupRateMasks(A_UINT32 *rateMask, A_UINT32 *rateMask11AC)
{
    // TBD? 4 testing CAL, for now
    rateMask[0] = 0x00010000;
#if 0
    for (k=0; k<NumCALRates; k++) {
        dataRate = CALRateList[k];
    }
#endif
}

#if 0
static void makeupChainMasks(A_UINT32 *txChain)
{
    // TBD?? "hard code txChain 4 testing CAL, for now
    txChain[0] = 0x00000001;
    txChain[1] = 0x00000002;
    txChain[2] = 0x00000004;
#if 0
    for (jj=0; jj<NumCALChainMasks; jj++) {
        chainMask = CALChainMaskList[jj];
    }
#endif
}
#endif
static void txCAL(TCMD_CONT_TX *pTcmdParms) 
{
    wlan_tcmd_dev_t *dev=&utf_dev;
    //A_PRINTF("CAL: ch%d gainIdx %d dac %d rate%d nPk%d chain 0x%x\n", pTcmdParms->freq, pTcmdParms->gainIdx, pTcmdParms->dacGain, pTcmdParms->dataRate, pTcmdParms->numPackets, pTcmdParms->txChain);
    A_PRINTF("CAL: ch%d gainIdx %d dac %d chain 0x%x\n", pTcmdParms->freq, pTcmdParms->gainIdx, pTcmdParms->dacGain, pTcmdParms->txChain);
    // TBD?? can be optimized to not reset
    utfTxStart(dev, (TCMD_CONT_TX *)pTcmdParms);

    utfTxStop(dev,(TCMD_CONT_TX *)pTcmdParms);
    A_DELAY_USECS(800000);
}

static void calByForcedGainIdxPerBand(_CHANNEL_LIST *pCALChannelList, A_UINT32 numCALChannels)
{
    A_UINT32 ii, jj; 
    A_UINT32 rateMask[RATE_MASK_ROW_MAX_11N];
    A_UINT32 rateMask11AC[RATE_MASK_ROW_MAX_11AC];
    A_UINT32 txChain[MAX_TX_CHAIN];
    _CMD_TX_PARMS txCmdParms; 
    _CMD_ALL_PARMS *pCmdParms = (_CMD_ALL_PARMS*)&txCmdParms;
    _CMD_TX_PARMS *txParms=(_CMD_TX_PARMS*)&(pCmdParms->_cmdParmU._cmdTxParms);
    TCMD_CONT_TX tx_tcmdParms;

    A_MEMZERO((void*)&txCmdParms, sizeof(_CMD_TX_PARMS));
    A_MEMCPY((void*)&txCmdParms, (void*)&_txCmdParms, sizeof(_CMD_TX_PARMS));

    // make up rate mask
    A_MEMZERO((void*)rateMask, sizeof(rateMask));
    A_MEMZERO((void*)rateMask11AC, sizeof(rateMask11AC));
    makeupRateMasks(rateMask, rateMask11AC);

    // make up chain mask
    A_MEMZERO((void*)txChain, sizeof(txChain));

    /* setup relevant field for forced gain idx mode */
    A_MEMCPY((void*)&(txCmdParms.rateMask[0]), (void*)&(rateMask[0]),  sizeof(txCmdParms.rateMask));
    A_MEMCPY((void*)&(txCmdParms.rateMask11AC[0]), (void*)&(rateMask11AC[0]),  sizeof(txCmdParms.rateMask11AC));
    A_MEMCPY((void*)&(txCmdParms.txChain[0]), (void*)&(txChain[0]), sizeof(txCmdParms.txChain));

    txCmdParms.tpcm = TPC_FORCED_GAINIDX; 
    txCmdParms.numPackets = _CAL_TX_NUM_PACKETS;

    // ready to loop
    for (ii=0;ii<numCALChannels;ii++) {
        txCmdParms.channel = pCALChannelList[ii].channel;
        for (jj=0;jj<pCALChannelList[ii].numChainMasks;jj++) {
       
            // point A
            txCmdParms.gainIdx = (A_UINT16)pCALChannelList[ii].calChainMasksList[jj].gainIdx.gainIdx_ptA;
            txCmdParms.dacGain = (A_INT16)pCALChannelList[ii].dac.dac_ptA;

            setupTxParms(txParms, &tx_tcmdParms);
            tx_tcmdParms.txChain = pCALChannelList[ii].calChainMasksList[jj].chainMask;
            tx_tcmdParms.aifsn = 0;
            tx_tcmdParms.dataRate = ATH_RATE_6_5M;

            //A_PRINTF("A:ch%d mask 0x%x gainIdx%d dac%d\n", tx_tcmdParms.freq, tx_tcmdParms.txChain, tx_tcmdParms.gainIdx, tx_tcmdParms.dacGain);
            txCAL(&tx_tcmdParms);

            // point B
            txCmdParms.gainIdx = (A_UINT16)pCALChannelList[ii].calChainMasksList[jj].gainIdx.gainIdx_ptB;
            txCmdParms.dacGain = (A_INT16)pCALChannelList[ii].dac.dac_ptB;

            setupTxParms(txParms, &tx_tcmdParms);
            tx_tcmdParms.txChain = pCALChannelList[ii].calChainMasksList[jj].chainMask;
            tx_tcmdParms.aifsn = 0;
            tx_tcmdParms.dataRate = ATH_RATE_6_5M;

            //A_PRINTF("B:ch%d mask 0x%x gainIdx%d dac%d\n", tx_tcmdParms.freq, tx_tcmdParms.txChain, tx_tcmdParms.gainIdx, tx_tcmdParms.dacGain);
            txCAL(&tx_tcmdParms);
        }
    }
} 

#if 0
static void calByForcedGainIdxPerBand_old(_CHANNEL_LIST *pCALChannelList, A_UINT32 numCALChannels)
{
        A_UINT32 ii, j; 
        A_UINT32 channel;
        A_UINT32 gainIdx;    
        A_INT32  dac;
        A_UINT32 rateMask[RATE_MASK_ROW_MAX_11N];
        A_UINT32 rateMask11AC[RATE_MASK_ROW_MAX_11AC];
        A_UINT32 txChain[MAX_TX_CHAIN];

        // make up rate mask
        A_MEMZERO((void*)rateMask, sizeof(rateMask));
        A_MEMZERO((void*)rateMask11AC, sizeof(rateMask11AC));
        makeupRateMasks(rateMask, rateMask11AC);

        // make up chain mask
        A_MEMZERO((void*)txChain, sizeof(txChain));
        makeupChainMasks(txChain);

        // ready to loop
        for (ii=0;ii<numCALChannels;ii++) {
            channel= pCALChannelList[ii].channel;
                    for (j=0;j<NumCALGainIdxes;j++) {
                        gainIdx=CALGainIdxList[j];
                        //for (kk=0;kk<NumCALDACValues;kk++) {
                        dac=CALDACValues[j];
                        //    dac=CALDACValues[kk];
                            
                            // set up txCmdProcessor to work
                            setup2Use_txCmdProcessor(channel, rateMask, rateMask11AC, txChain, gainIdx, dac);
                        //}
                    }
        }
} 
#endif

static void calByForcedGainIdx(void)
{
#if defined(_2G_READY)
    calByForcedGainIdxPerBand(CALChannelList2G, NumCALChannels2G);
#endif //#if defined(_2G_READY)

    //A_PRINTF_ALWAYS("cal 5g %d\n", NumCALChannels5G);
    calByForcedGainIdxPerBand(CALChannelList5G, NumCALChannels5G);
}
#endif /* #if defined(_4_PERE_BRINGUP_BEFORE_TS_READY_TOBE_REMOVED_AFTER) */

static _CMDPROC_RC calCmdProcessor(_CMD_ALL_PARMS *parms)
{
    _CMDPROC_RC rc=CMDPROC_RC_SYNC_SUCC;
    //_CMD_CAL_PARMS *calParms=(_CMD_CAL_PARMS*)&(parms->_cmdParmU._cmdCalParms);
    //A_PRINTF("%s\n", __func__);
    CmdStateInfo.testConfig |= TEST_CONFIG_CAL;             

    // TBD: not sure the following needs to be set
    _PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero = 1; // non-zero
    _PostWhalResetSettings.pPostProc = whalPostResetProc4CAL; // built in flexibility for bench characterization
    _PostWhalResetSettings.pPostSetPwrProc = whalPostSetPwrProc4CAL;

#if defined(_4_PERE_BRINGUP_BEFORE_TS_READY_TOBE_REMOVED_AFTER)
    //A_PRINTF_ALWAYS("cal f %d\n", calParms->addrMode[0]);
    calByForcedGainIdx();
#if 0
    if (TCMD_CAL_BY_FORCED_GAIN_IDX == calParms->addrMode[0]) {
        calByForcedGainIdx();
    }
    else {
        // TBD
    }
#endif
#else
    A_UINT32 i;
    wlan_tcmd_dev_t *dev=&utf_dev;

    // setup for forced gain tx measurement
    // to be done by testscript tx cmds following this ...

    // setup registers
    A_MEMZERO((void*)&_PostWhalResetSettings, sizeof(_PostWhalResetSettings));
    for (i=0;i<MAX_UTF_CAL_WRITE_REG;i++) {
        if (calParms->addrMode[i]) {
            _PostWhalResetSettings.addrMode[i] = calParms->addrMode[i];
            _PostWhalResetSettings.value[i]    = calParms->value[i];
            _PostWhalResetSettings.mask[i]     = calParms->mask[i];
        }
        else {
            break;
        }
    }
    _PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero = i;

    // 
    _PostWhalResetSettings.pPostProc = whalPostResetProc4CAL; // built in flexibility for bench characterization
    _PostWhalResetSettings.pPostSetPwrProc = whalPostSetPwrProc4CAL;

    if ( hostTlvCmdProcess == TRUE )
        sendResponse(dev);
#endif /*#if defined(_4_PERE_BRINGUP_BEFORE_TS_READY_TOBE_REMOVED_AFTER)*/

    return(rc);
}


static A_BOOL calCmdParmsParser(A_UINT8 *cmdParmBuf, _CMD_ALL_PARMS **parms, A_UINT8 numOfParms)
{
    _CMD_CAL_PARMS *calCmdParms = (_CMD_CAL_PARMS *)&(_cmdParms._cmdParmU._cmdCalParms);
    memset((void*)calCmdParms,0, sizeof(_CMD_CAL_PARMS));
    //memcpy((void*)calCmdParms, (void*)&_calCmdParms, sizeof(_CMD_CAL_PARMS));
    return(cmdParmsParser_common(cmdParmBuf, parms, numOfParms, (void*)calCmdParms, _calParm_bin_template));
}

#if 0
static A_BOOL calDoneCmdParmsParser(A_UINT8 *cmdParmBuf, _CMD_ALL_PARMS **parms, A_UINT8 numOfParms)
{
    return(TRUE);
}
#endif


//
// Architectural notes:
// The opcode based parsing and cmd processing. The real stuff happens here.
// The SM is a generic engine that hums without any specific knowledge what needs to be done for each cmd.
//
_CMD_HANDLERS CmdHandlers[_OP_TESTSCRIPT_LAST] = 
{
    /*_OP_SYNC */            		{rxSyncCmdProcessor, rxSyncCmdParmsParser},
    /*_OP_TX*/               		{txCmdProcessor, txCmdParmsParser},
    /*_OP_RX*/               		{rxCmdProcessor, rxCmdParmsParser},
    /*_OP_CAL*/              		{calCmdProcessor, calCmdParmsParser},
    /*_OP_CALDONE*/          		{calDoneCmdProcessor, NULL},
    /*_OP_PM*/               		{pmCmdProcessor, pmCmdParmsParser},
    /*_OP_GENERIC_RSP*/           	{NULL, NULL},
    /*_OP_SUBMIT_REPORT_RSP */          {NULL, NULL},
    /*_OP_GENERIC_NART_CMD */           {nartCmdProcessor, nartCmdParmsParser},
    /*_OP_GENERIC_NART_RSP */           {NULL, NULL},
};
#if defined(_HOST_SIM_TESTING)
#define A_MEMZERO  memset
#endif

//
// Notes:
// callback func that needs to be registered with lower layer rx call, 
// e.g. tcmd cont_rx FILTER mode
// the lower layer provides a register function to notify interested parties
// void registerToBeNotified(evt), from tcmd layer, to add a func to the list
// void unregisterToBeNotified(evt), from tcmd layer, to remove a func from the list
// calling register, from cmdProcessing layer
// processing registered functions, from tcmd layer, process the list
#if 0
void rxSyncNotify(void *pInput, void *pReturn)
{
    static A_UINT16 alreadyNotfiedTimes = 0;
    _CMDPROC_STATE_INFO *pCmdStateInfo = &CmdStateInfo;

    if (!alreadyNotfiedTimes) { 
        pCmdStateInfo->curEvt = EVT_RX_SYNC_AVAIL; 
        cmdProcessingThread(pCmdStateInfo);
    }
    alreadyNotfiedTimes++;
    if (RX_SYNC_STATE != pCmdStateInfo->state) {
        alreadyNotfiedTimes=0;
    }

    return;
}
#endif

void rxSyncNotifySim(void)
{
    _CMDPROC_STATE_INFO *pCmdStateInfo = &CmdStateInfo;
    pCmdStateInfo->curEvt = EVT_RX_SYNC_AVAIL;
    cmdProcessingThread(pCmdStateInfo); 
}

void rxNotifyReg(void *pInput)
{
    _RX_NOTIFY_INFO *pCtrl = (_RX_NOTIFY_INFO *)pInput;
    _utfRxStat_t *tcmdRxStats = &tcmdRxStat;
    pCtrl->lastSnapshotPkts = tcmdRxStats->okPkt;

    return;
}

void rxNotify(void* pInput, void *pReturn)
{
    _RX_NOTIFY_INFO *pCtrl = (_RX_NOTIFY_INFO *)pInput;
    _utfRxStat_t *pRc = (_utfRxStat_t *)pReturn;
    _CMDPROC_STATE_INFO *pCmdStateInfo = &CmdStateInfo;

    //A_PRINTF(".rxNotify expect %d, last %d, now %d\n", pCtrl->expectedPkts, pCtrl->lastSnapshotPkts, pRc->okPkt); 
    if (pCtrl->expectedPkts <= (pRc->okPkt - pCtrl->lastSnapshotPkts)) {
#if 0
        pCmdStateInfo->curEvt = pCtrl->evt2Notify; 
        cmdProcessingThread(pCmdStateInfo);
#endif
        pCtrl->shouldHaveNotifiedTimes++;
        if (1 == pCtrl->shouldHaveNotifiedTimes) { 
            //A_PRINTF("..notify evt %d\n", pCtrl->evt2Notify);
            pCmdStateInfo->curEvt = pCtrl->evt2Notify; 
            cmdProcessingThread(pCmdStateInfo);
            // shouldHaveNotfiedTimes is cleared in the cmd processing during state transition
        }
        //A_PRINTF("..notifyC %d\n", pCtrl->shouldHaveNotifiedTimes);
    }

    return;
}


#if 0
/// txNotify doesn't run the "thead", simply check numPackets and stop tx, done and get out
void txNotify(void* pInput, void *pReturn)
{
    _TX_NOTIFY_INFO *pCtrl = (_TX_NOTIFY_INFO *)pInput;
    tcmd_tx_stat_t *pRc = (tcmd_tx_stat_t *)pReturn;
    TCMD_CONT_TX tcmdParms;
    wlan_tcmd_dev_t *dev=&utf_dev;

    if (pRc->totalPkt >= pCtrl->numPkts2Send) {
        // stop tx
        tcmdParms.mode = TCMD_CONT_TX_OFF;
        utfTxCmd(dev, (TCMD_CONT_TX *)&tcmdParms);
        A_PRINTF(".txNotify stop 2Send %d, now %d\n", pCtrl->numPkts2Send, pRc->totalPkt); 
        
        // deregister tx callback function
        deregisterTxCallback();
    }

    return;
}
#endif


void rxTimeout(A_HANDLE alarm, void *data)
{
    _CMDPROC_STATE_INFO *pCmdStateInfo = &CmdStateInfo;

    //A_PRINTF("stop rx timer ..\n");
    A_UNTIMEOUT(&pCmdStateInfo->rxTimer);

    pCmdStateInfo->curEvt = EVT_RX_TIMEOUT; 
    cmdProcessingThread(pCmdStateInfo);

    return;
}


void rxSyncTimeout(A_HANDLE alarm, void *data)
{
    _CMDPROC_STATE_INFO *pCmdStateInfo = &CmdStateInfo;

    //A_PRINTF("rxSync TO\n");
    A_UNTIMEOUT(&pCmdStateInfo->rxSyncTimer);

    pCmdStateInfo->curEvt = EVT_RX_SYNC_TIMEOUT; 
    cmdProcessingThread(pCmdStateInfo);

    return;
}


void calDataPollTimeout(A_HANDLE alarm, void *data)
{
    _CMDPROC_STATE_INFO *pCmdStateInfo = &CmdStateInfo;

    //A_PRINTF("rxSync TO\n");
    A_UNTIMEOUT(&pCmdStateInfo->calDataPollTimer);

    pCmdStateInfo->curEvt = EVT_POLL_CAL_DATA_TIMEOUT; 
    cmdProcessingThread(pCmdStateInfo);

    return;
}


void createTimers(void)
{
    A_INIT_TIMER(&CmdStateInfo.rxSyncTimer,       rxSyncTimeout, (void *)&CmdStateInfo); 
    A_INIT_TIMER(&CmdStateInfo.rxTimer,           rxTimeout,     (void *)&CmdStateInfo); 
    A_INIT_TIMER(&CmdStateInfo.calDataPollTimer,  calDataPollTimeout,     (void *)&CmdStateInfo); 
    return;
}

#define _DELAY_4_CAL 1300000
void delay4CAL(void)
{
    if (!(CmdStateInfo.testConfig & TEST_CONFIG_CAL_W_TGTPWR)) {
        A_DELAY_USECS(_DELAY_4_CAL);    
    }
    return;
}

#if defined(_HOST_SIM_TESTING)
int main(void) 
{
    int cmdStreamLen;
    A_UINT8 *pCmdStream;
    A_UINT8 *payload;
    A_UINT16 payloadLen;

    composeACmdStream4Testing(&cmdStreamLen, &pCmdStream);
    parseBinCmdStream(pCmdStream, cmdStreamLen, &payload, &payloadLen);  

    cmdProcessingEntry();

    // RX_SYNC_CMD ...
      
    // Notify RX_SYNC_AVAIL event
    //rxSyncNotify();

    // TX_CMD ...
    
    // Notify RX_SYNC_AVAIL event
    //rxSyncNotify();

    // RX_CMD ....
      
    // send RX_NORMAL ...
    //rxNotify();

    return(0);

}

#endif //#if defined(_HOST_SIM_TESTING)


// 
// Exercise of adding CAL into the current verify test flow
// This can serve as the base for UTF development guide
//
// First, let's design how CAL is done.
// Upon reading the _OP_CAL_OR_OLPC_CHAR command with all eep file register settings, 
//   UTF sets all these registers after HAL reset, and moves the state to _CMD_CAL state.
// Subsequent TX commands will need to ensure all registers are set per eep file after HAL reset, and
//   use forced gain mode.
//   Most likely, these TX commands loop through pcDac too. 
//   The same command can be used to sweep tx gain table for various characterization.
// Upon reading the _OP_CAL_OR_OLPC_CHAR_DONE command, the state is changed to _WAIT_4_CAL_DATA.
//   UTF will not set eep regiters from this point on.
//   UTF starts the WAIT_4_CAL_DATA timer.
// LP gathers all power measurements and writes them in a file, and calls a utility for post-process CAL data.
// This ATHR utility generates eeprom bin file based on the same bin file used by the DUT, and
//   moves CAL data to DUT for writing to OTP.
//   The utility basically write CAL data to a specific RAM loction, and sets a hi_board_CAL_data_available 
//   flag.
// Upon expiration of the WAIT_4_CAL_DATA timer, UTF checks hi_board_CAL_data_available flag, and fetches 
//   CAL data accordingly.
//   It then writes the CAL data to OTP.
//   Most importantly, UTF call HAL to update the board data based on OTP. But how???
//   UTF then moves the state to CMD_PROCSSING.
//
// How do we make the combined CAL and verification flow work?
//   The issue is how to update board data after CAL. 
//   One way is to execute the same OTP logic as in otp.bin.
//
// Or, we do not use combined CAL and verification flow. Simply run them separately.
//   
//
// Now the concrete steps in implementing the above CAL logic.
// _OP_CAL is a command from the test script, 
// it has a number of registers as parameters
//
// _OP_CAL is processed as a command, and the state transitions into _CMD_CAL state
//
// So here is what we need to do:
// 1. Add _OP_CAL as a command to the "cmdOpcodes.h"
// 2. Create cmdCalParms.h, following the naming conventions and syntax of cmdTxParms.h for auto-generation
//    of the txt and bin templates.
//    The txt template is used to create the binary test script
// 3. Copy cmdCalParms.h to utf_utilities/genParmTemplate, and run genParmTemplate.out cmdCalParms.h
// 4. Check the sanity of auto-generated _cmd_calParmTxtTemplate.[hc], _cmd_calParmBinTemplate.c
// 5. Add the created template to cmdParmsTemplate.c in genCmdStream, for binary test script generation.
// 5a.Add the created template to the make file in genCmdStream.
//    Now the binary testscript utility is ready.
//
// 5c.Create a test flow with _OP_CAL command.
//
// 6. May beef up verifyCmdStream for the new CAL cmd, but can hold off this one until firmware is done,
//    Then we can simply copy the calCmdParmsParser over here to enhance the verifyCmdStream utility.
// 6a.Pass _calParm_bin_template to cmdStreamParmsParsing.c,  i.e. implement calCmdParmsParser.
// 6b.Add _calParm_bin_template to makefile in verifyCmdStream.
// 6c.Add cmdCalParms.h to cmdAllParms.h
//
// 7. Now we turn our attention to firmware.
// 8. Copy _cmd_calParmBinTemplate.c to commonUTF.
// 8a.Copy cmdCalParms.h to include.
// 8b.Update all relevant .h files (cmdAllParms.h, etc.)
// 9. Add _cmd_calParmParser, and follow through parseCmd path and make sure it can parse the binary 
//    cmdStream that contains CAL cmd.
//
//10. Add op code processing ...
//    Entry through cmdProcessingEntry -> 
//
//      cmdProcessingThread(nextCmd) 
//        cmdProcessingNextCmd -> _CMDPROC_DECISION(_NULL, _CNT, _END, _RESET)
//          curCmdQ.opCode -> curEvt & state(?) -> 
//          cmdProcessingEvt(evt,?) ->  
//            {cmdProcessingSM -> 
//              SM evt handling (evtCalCmdHandler -> evtCmdHandler) -> _CMDPROC_RC (SYNC_SUCC/FAIL, ASYNC/SUCC/FAIL/TIMEOUT) -> cmdHandler(calCmdParser:basedOn Opcode + calCmdProcessor: setup CAL settings)
//              State=next state
//            }
//      => done return EVT_CMD_DONE
//    Almost all above is generic, only need to add
//      - Op2StateEvt mapping _OP_CAL to EVT_CAL_CMD and state (not used)
//      - add to SM, for CMD_PROCESSING_STATE, evtCalCmdHandler, 
//      - add cmdHandler (for _OP_CAL), (and calParmParser)
//        it doesn't do much, rather stores the register settings for later user.
//        - add whalReset post proc to overwrite register settings.
//        - modify cont tx behavor for open loop
//
//10a.Add _CMD_CAL_STATE, evtCalCmdHandler,  and calCmdProcessor to do the CAL logic. That's setting 
//    registers and moves
//    the state to _WAIT_4_CAL_DATA state.
//
//    Now Let's try the above procedure again while adding _CAL_DONE cmd, and WAIT_4_CAL_DATA_STATE,
//    and CAL_DATA_POLL evt.
//    The logic is the following:
//    Once CAL_DONE, 
//    - CMD_CAL_DONE as a command event is sent to CMD_PROCESSING_STATE and proper event handler is called.
//    - The evtCalDoneCmdHandler calls generic evtHandler, which searches CmdHandlers based on opCode.
//    - The cmdCalDoneProcessor does the following:
//      - undo whalReset behavior modification at the beginning of CAL
//      - start a poll time for CAL data
//      - returns SYNC_CMD success
//    - evtCalDoneCmdProcessor then moves the state to WAIT_4_CAL_DATA_STATE, and indicate _CMDPROC_END.
//
//    Now on the PC, LP creates a file with power measurements.
//    An ATHR utility is called to
//    - generate the eeprom bin file;
//    - "push" CAL data to DUT for OTP writig (and whatever) DUT wants to do with it.
//
//    On the DUT, the periodic CAL_DATA poll timer expires, a timeout event is sent to the WAIT_4_CAL_DATA_STATE
//    - CAL_DATA_POLL timeout event arrives at WAIT_4_CAL_DATA_STATE.
//    - evtCalDataAvailHandler calls generic evtHandler, which finds the cmdCalAvailProcessor based on opcode 
//      in CmdHandlers.
//    - cmdCalAvailProcessor does the following:
//      - fetches the CAL data from the RAM location;
//      - writes the CAL data to OTP, if enabled.
//      - updates the board data (? how) for subsequent verification, possibly.
//      - return ASYNC_SUCC
//    - evtCalDataAvailHandler then moves state to CMD_PROCESSING_STATE, and indicate _CMDPROC_END.
//
//11. Add _WAIT_4_CAL_DATA state.
//12. Create a wait_4_CAL_data timer with reasonable duration, say 1 min.
//13. Upon the timer expiration, UTF reads hi_board_CAL_data_avail flag, and if set, fetches CAL data
//    from hi_board_CAL_data location.
//    It then writes  CAL data to OTP.
//    UTF also updates board data with CAL data, just like OTP application. How?
//    The state is moved to _CMD_PROCESSING.
//14. _CAL_TX command will do the usual TX, except in open loop with the above register settings.
//    The same command can loop through pcdac's.
//15. Once DUT reads _CAL_DONE, it starts the timer and moves state to _CMD_PROCESSING state.
//16. LP gathers all CAL data and call ATHR utility to generate eeprom bin and passes CAL data to DUT
//    stll running. That's where the DUT periodically checks the location.
//17. So far, we added two states (_CMD_CAL, _WAIT_4_CAL_DATA), one timer, two commands (_OP_CAL,
//    _OP_CAL_DONE), two sets of cmd parser and processors, and enhanced _OP_TX to handle the olpc 
//    characterizatin and CAL case.  
//
//
// 
