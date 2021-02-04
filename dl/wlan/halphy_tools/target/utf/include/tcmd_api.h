/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 * Copyright (c) 2006 Atheros Communications Inc.
 * All rights reserved.
 * $ATH_LICENSE_TARGET_C$
 *
 * This file contains the api for test commands on target.
 *
 * $Id:
 *
 */

#ifndef _TCMD_API_H_
#define _TCMD_API_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <athdefs.h>
#include "testcmd.h"
#include "utf_dev.h"
#include "codeswap_api.h"

typedef struct tcmd_tx_stat_t {
        A_UINT32                   totalPkt;
        A_UINT32                   okPkt;
        A_UINT32                   crcErrPkt;
        A_UINT32                   phyErrPkt;
        A_UINT32                   secErrPkt;
} tcmd_tx_stat_t;

typedef struct tcmd_rx_stat_t {
        A_UINT32                   totalPkt;
        A_UINT32                   okPkt;
        A_INT32                    rssiInDBm;
        A_INT32                    rssi;
        A_UINT32                   crcErrPkt;
        A_UINT32                   phyErrPkt;
        A_UINT32                   secErrPkt;
        A_UINT16                   rateCnt[TCMD_MAX_RATES];
#ifdef SUPPORT_11N
        A_UINT16                   rateCntShortGuard[TCMD_MAX_RATES];
#endif
        A_INT32                    rssic[MCHAIN_UTF];
} tcmd_rx_stat_t;

#ifndef MRETRY
#define MRETRY 16
#endif
#ifndef MSTREAM
#define MSTREAM 2
#endif
#ifndef MEVM
#define MEVM 100
#endif
#ifndef MCHAIN
#define MCHAIN 1
#endif
#ifndef MRSSI
#define MRSSI 100
#endif

#define TCMD_MAX_RDPWR        31  /* copy from haldemos */

typedef struct tcmd_nart_tx_stat_t
{
    A_UINT32 goodPackets;
    A_UINT32 underruns;
    A_UINT32 otherError;
    A_UINT32 excessiveRetries;
    //
    // retry histogram
    //
    A_INT32 shortRetry[MRETRY];
    A_INT32 longRetry[MRETRY];

    A_UINT32 newThroughput;
    A_UINT32 startTime;
    A_UINT32 endTime;
    A_UINT32 byteCount;
    A_UINT32 dontCount;
    //
    // rssi histogram for good packets
    //
    A_INT32 rssi[MRSSI];
    A_INT32 rssic[MCHAIN][MRSSI];
    A_INT32 rssie[MCHAIN][MRSSI];
    //
    // evm histogram for good packets
    //
    A_INT32 evm[MSTREAM][MEVM];
    //
    // rssi histogram for bad packets
    A_INT32 badrssi[MRSSI];
    A_INT32 badrssic[MCHAIN][MRSSI];
    A_INT32 badrssie[MCHAIN][MRSSI];
    //
    // evm histogram for bad packets
    //
    A_INT32 badevm[MSTREAM][MEVM];

} tcmd_nart_tx_stat_t;

typedef struct tcmd_nart_rx_stat_t
{
    A_UINT32 goodPackets;
    A_UINT32 otherError;
    A_UINT32 crcPackets;
    A_UINT32 singleDups;
    A_UINT32 multipleDups;
    A_UINT32 bitMiscompares;
    A_UINT32 bitErrorCompares;
    A_UINT32 ppmMin;
    A_UINT32 ppmMax;
    A_UINT32 ppmAvg;
    A_UINT32 decrypErrors;

    // Added for RX tput calculation
    A_UINT32 rxThroughPut;
    A_UINT32 startTime;
    A_UINT32 endTime;
    A_UINT32 byteCount;
    A_UINT32 dontCount;
    //
    // rssi histogram for good packets
    //
    A_INT32 rssi[MRSSI];
    A_INT32 rssic[MCHAIN][MRSSI];
    A_INT32 rssie[MCHAIN][MRSSI];
    //
    // evm histogram for good packets
    //
    A_INT32 evm[MSTREAM][MEVM];
    //
    // rssi histogram for bad packets
    //
    A_INT32 badrssi[MRSSI];
    A_INT32 badrssic[MCHAIN][MRSSI];
    A_INT32 badrssie[MCHAIN][MRSSI];
    //
    // evm histogram for bad packets
    //
    A_INT32 badevm[MSTREAM][MEVM];

    A_UINT32 Chain0AntSel[2];
    A_UINT32 Chain1AntSel[2];
    A_UINT32 Chain0AntReq[2];
    A_UINT32 Chain1AntReq[2];
    A_UINT32 ChainStrong[2];

} tcmd_nart_rx_stat_t;


typedef enum {
    TCMD_STATUS_DISABLE = 0,
    TCMD_STATUS_ENABLE,  /* equals to awake */
    TCMD_STATUS_SLEEP,
    TCMD_STATUS_DEEPSLEEP
} TCMD_MODE;

#define  _UTF_RAM_ALLOCATED     0x01
#define  _UTF_HAL_ATTACHED      0x02
#define  _UTF_BOARD_DATA_READ   0x04
typedef struct tcmd_state_t {
      TCMD_MODE  tcmdMode;
      A_UINT32   freq;
      A_UINT32   wlanMode;
      A_UINT32   bandwidth;
      A_UINT32   dataRate;
      A_UINT8    tcmdTxGo;
      A_UINT8    tcmdRxGo;
      A_UINT8    deepSleepEn;
      A_UINT8    flags;
      A_UINT32   numTxPkts;
      A_UINT8    srcAddr[IEEE80211_ADDR_LEN];
      A_UINT8    macAddr[IEEE80211_ADDR_LEN];
      A_UINT8    bssid[IEEE80211_ADDR_LEN];
      A_BOOL     disContTx;
      A_UINT32   chain;
      A_UINT32   freq2;
}tcmd_state_t;

typedef struct tcmd_link_trx {
    A_UINT32 totalToTx;                   /* total number of rates to be transmited */
    A_UINT32 currentTx;
    TX_STATS_STRUCT_UTF *txStats[TCMD_MAX_RATES];
    RX_STATS_STRUCT_UTF *rxStats[TCMD_MAX_RATES+1];/* reserved one rate for unknown rate */
    A_UINT8 txDataRates[TCMD_MAX_RATES + 3];    /* data rate array with all the rates to be transmited */
    A_UINT8 txPwr[TCMD_MAX_RATES + 3]; /* 153 + 3*/ /* 4B align */
    A_UINT16 pktLength[TCMD_MAX_RATES + 3 ];
}tcmd_link_trx;

#define TCMD_NUM_CCK_RATES 4 /* 1M, 2M, 5.5M, 11M */

//#define FREQ2FBIN(x,y) ((y) ? ((x) - 2300) : (((x) - 4800) / 5))
//#define FBIN2FREQ(x,y) ((y) ? ((x) + 2300) : (((x) * 5) + 4800))

extern tcmd_rx_stat_t tcmdRxStat;
extern tcmd_state_t tcmd_state;

extern A_STATUS tcmd_parse_cmd(wlan_tcmd_dev_t *dev, A_UINT8 *buf, A_UINT32 length);
extern void tcmd_enable(void);
extern void tcmd_cont_tx_cmd(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *);
extern void tcmd_get_channel(A_UINT32 freq, A_UINT32 wlanMode, A_UINT32 bandwidth, WHAL_CHANNEL *chan, A_UINT32 freq2);
extern A_STATUS tcmd_whalReset(WHAL_CHANNEL *chan);
extern A_UINT32 tcmd_cont_rx_cmd(wlan_tcmd_dev_t *dev, TCMD_CONT_RX *);
extern void tcmd_pm_cmd(wlan_tcmd_dev_t *dev, TCMD_PM *pm );
extern WLAN_PHY_MODE tcmd_get_curmode(void);
extern void utfTxChannelSetup(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern void utfTxStart(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern void utfTxStop(wlan_tcmd_dev_t *dev,TCMD_CONT_TX *contTx);
extern void utfTxStartNoPoll(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern A_UINT32 utfContRxStart(wlan_tcmd_dev_t *dev, TCMD_CONT_RX *contRx);
extern void utfRxStop(wlan_tcmd_dev_t *dev);


#ifdef __cplusplus
} //extern "C" {
#endif

#endif
