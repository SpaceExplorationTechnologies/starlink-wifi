/* ListModeCommon.h
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
// This is an auto-generated file from input/cmdLMTxHandler.s
#ifndef _CMDLISTMODECOMMON_H_
#define _CMDLISTMODECOMMON_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "osapi.h"
#include "wlantype.h"
#include "halphy_cal.h"
#include "halphy_internal.h"
#include "whalExtensionGeneric.h"
#include "hal_tcmd.h"
#include "wmi_tcmd.h"

#include "cmdStream.h"
#include "cmdAllParms.h"
#include "cmdTxParms.h"
#include "parmBinTemplate.h"
#include "parseBinCmdStream.h"
#include "cmdProcessingSM.h"

#include "tcmdHostInternal.h"
#include "utf_dev.h"
#include "testcmd.h"
#include "utf.h"
#include "cmdRspParmsDict.h"
#include "cmdRspParmsInternal.h"
#include "tlv2Inc.h"
/* added LM related header files*/
#include "cmdLMHWCALHandler.h"
#include "cmdLMHWCALRSPHandler.h"
#include "cmdLMTxHandler.h"
#include "cmdLMChannelListAndRspHandler.h"
#include "cmdLMTxInitHandler.h"
#include "cmdLMRxInitHandler.h"
#include "cmdLMGoHandler.h"
#include "cmdLMQueryHandler.h"
/* end of adding LM related header files*/
#include "halphy_mc_paprd.h"
#include "ar_wal_rc.h"
#include "tcmd_api.h"
#include <otpstream_api.h>
#include <otpstream_id.h> /* replaces local SECTION_ID definitions */
#define A_PRINTF_ONCE A_CMN(printf._printf)
typedef enum {
    LMHWCAL_OK                     = 0,        //    LMHWCAL    ok
    LMGO_OK                           = 0,        //    LMGO_OK    ok
    LMHWCAL_FAILURE             = 1,       //     LMHWCAL failure
    LMHWCalNUMOVR               = 2,
    LMCHANNLENUMOVR           = 3,
    LMALLOCMEMERROR           = 4,
    LMGO_FAILURE                  = 5,        //    LMGO_FALIED    ok
}LMHWCalERRORCODE;

typedef enum {
    LMCHANNELLISTFIRST          = 0x1,        //    FIRST CHANNEL LIST
    LMCHANNELLISTMORE          = 0X2,       //     MORE LMCHANNELLIST
}LMCHANNELLISTCODE;

typedef struct lmHWCalList {
    A_UINT8	phyId;
    A_UINT8	wlanMode;
    A_UINT16	chainMask;
    A_UINT16	freq;
    A_UINT16	freq2;
    struct lmHWCalList *next;
}__ATTRIB_PACK LMHWCALLIST;
#if 0
typedef struct lmChannelList {
    A_UINT8	phyId;
    A_UINT8	wlanMode;
    A_UINT8	txPower;
    A_UINT8   pad1;
    A_UINT16	chainMask;
    A_UINT16	freq;
    A_UINT16	freq2;
    A_UINT16	rateIndex;
} __ATTRIB_PACK LMCHANNELLIST;

#endif
typedef struct lmHWCalNum {
    A_UINT16	singleChainNum;
    A_UINT16	fullChainNum;
}LMHWCALNUM;

#define MAX_LM_CHANNELLIST_INDEX  10
#define MAX_LM_CHANNELLIST_PER_EACH  100
#define  LM_HWCAL_COMPLETE_TIMEOUT_SHORT 350
#define  LM_HWCAL_COMPLETE_TIMEOUT_LONG 850

#define  LM_GO_COMPLETE_TIMEOUT_OFF 50
#define  LM_GO_COMPLETE_TIMEOUT_ON  1000

#define IS_VHT80_PLUS_80_CONTIGUOUS(freq1, freq2) \
(((80 == ((freq1) - (freq2))) || (80 == ((freq2) - (freq1)))) ? 1 : 0)

#define IS_2G_FREQ(freq)  ((freq < 4800) ? 1 : 0)

void freeLMHWCalList(void);
A_UINT8 pushNodeToCalList(LMHWCALLIST ** head, A_UINT16 freq,  A_UINT16 freq2, A_UINT16 chainMask, A_UINT16 wlanMode, A_UINT16 phyId);
 A_UINT32 createLMHWCalListFromFreqMaskModePhyId(A_UINT16 freq,  A_UINT16 freq2, A_UINT16 chainMask, A_UINT16 wlanMode, A_UINT16 phyId);
void printHWCALList(void);
void LMHWCalProcessing(void);
void reverseCalList(LMHWCALLIST ** head);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLMLISTMODECOMMON_H_
