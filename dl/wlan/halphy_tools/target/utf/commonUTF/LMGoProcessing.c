/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
#include "ListModeCommon.h"
extern _AthDataRate Mask2Rate[RATE_MASK_ROW_MAX][RATE_MASK_BIT_MAX];

extern A_TIMER lm_common_complete_timer;
extern TCMD_CONT_TX tx_tcmdParms;
extern TCMD_CONT_RX rx_tcmdParms;
extern tcmd_tx_stat_t tcmdTxStat;
extern tcmd_rx_stat_t tcmdRxStat;
extern wlan_tcmd_dev_t utf_dev;
extern A_BOOL gEnableFastChannelChange;
static A_BOOL LMTxIsOn = FALSE;
static A_BOOL LMRxIsOn = FALSE;
int g_listmode = 0;
extern CMD_LMCHANNELLIST_PARMS g_lmChannelList;
static A_UINT32 currentChannelIdx = 0;
static A_UINT32 grouplIdx = 0;
static A_UINT32 currentTotalChannelIdx = 0;
extern A_UINT32 total_channel_list_num;
extern void  utfTxStop(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern void utfTxStart(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern void utfRxStop(wlan_tcmd_dev_t *dev);
extern void tcmd_cont_tx_cmd(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
void lm_tx_complete_handler(A_HANDLE handler, void *data);
extern A_BOOL gDPDCalDoneLM;
static A_UINT32 lm_go_complete_timeout_off = 500;
static A_UINT32 lm_go_complete_timeout_on =1000;
A_BOOL gLMTxDone = TRUE;
A_BOOL gLMRxDone = TRUE;
extern A_BOOL g_do_full_cal_flag;

SRAM_TEXT
void restoreChannelListfromHost(CMD_LMCHANNELLIST_PARMS *pChannelList, A_UINT32 grouplIdx)
{
}

//SRAM_TEXT
void lm_tx_complete_handler(A_HANDLE handler, void *pParm)
{
    TCMD_CONT_TX *tcmdParms = &tx_tcmdParms;
    A_UNTIMEOUT(&lm_common_complete_timer);
    A_UINT32 colIdx, rowIdx;
    //A_INT32 cal_time_stamp[2] = {0,0};
    if (currentChannelIdx < g_lmChannelList.lm_itemNum && currentTotalChannelIdx < total_channel_list_num && grouplIdx < MAX_LM_CHANNELLIST_INDEX)
    {
        gEnableFastChannelChange = FALSE;
        if (!LMTxIsOn) {
            //cal_time_stamp[0] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
            A_TIMEOUT_MS(&lm_common_complete_timer, lm_go_complete_timeout_on, 0);
            tcmdParms->freq = g_lmChannelList.lm_freq[currentChannelIdx];
            tcmdParms->freq2 = g_lmChannelList.lm_freq2[currentChannelIdx];
            tcmdParms->wlanMode = g_lmChannelList.lm_cbState[currentChannelIdx];
            tcmdParms->dataRate = g_lmChannelList.lm_rateIndex[currentChannelIdx];
            colIdx = (tcmdParms->dataRate % RATE_MASK_BIT_MAX);
            rowIdx =(tcmdParms->dataRate >> 5) % RATE_MASK_ROW_MAX;
            tcmdParms->dataRate = Mask2Rate[rowIdx][colIdx];
            tcmdParms->txPwr=g_lmChannelList.lm_txPower[currentChannelIdx];
            tcmdParms->txChain= g_lmChannelList.lm_chainMask[currentChannelIdx];
            if (tcmdParms->mode == TCMD_CONT_TX_FRAME)
                tcmdParms->mode |= 0x100;

            LMTxIsOn = TRUE;
            utfTxStart(&utf_dev, (TCMD_CONT_TX *)&tx_tcmdParms);
            //cal_time_stamp[1] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
        }
        else
        {
            A_TIMEOUT_MS(&lm_common_complete_timer, lm_go_complete_timeout_off, 0);
            currentChannelIdx++;
            currentTotalChannelIdx++;

            if (currentChannelIdx == g_lmChannelList.lm_itemNum && currentTotalChannelIdx < total_channel_list_num)
                restoreChannelListfromHost (&g_lmChannelList, grouplIdx++);

            if(tcmd_state.tcmdTxGo != TCMD_CONT_TX_OFF) {
                utfTxStop(&utf_dev, &tx_tcmdParms);
            }
            LMTxIsOn = FALSE;
        }
    }
    else
    {
        grouplIdx = 0;
        currentChannelIdx = 0;
        currentTotalChannelIdx = 0;
        currentChannelIdx = 0;
        A_DELETE_TIMER(&lm_common_complete_timer);
        if(tcmd_state.tcmdTxGo != TCMD_CONT_TX_OFF)
            utfTxStop(&utf_dev, &tx_tcmdParms);
        LMTxIsOn = FALSE;
        gLMTxDone = TRUE;
        g_listmode = 0;
    }
}
//SRAM_TEXT
void lm_rx_complete_handler(A_HANDLE handler, void *pParm)
{
    TCMD_CONT_RX *tcmdParms = &rx_tcmdParms;
    A_UNTIMEOUT(&lm_common_complete_timer);
    //A_INT32 cal_time_stamp[2] = {0,0};
    A_INT32 rateBitIndex, colIdx, rowIdx, rateIndex;

    if (currentChannelIdx < g_lmChannelList.lm_itemNum && currentTotalChannelIdx < total_channel_list_num && grouplIdx < MAX_LM_CHANNELLIST_INDEX)
    {
        gEnableFastChannelChange = FALSE;
        if (!LMRxIsOn) {
            //cal_time_stamp[0] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);

            A_TIMEOUT_MS(&lm_common_complete_timer, lm_go_complete_timeout_on, 0);
            tcmdParms->u.para.freq = g_lmChannelList.lm_freq[currentChannelIdx];
            tcmdParms->u.para.freq2 = g_lmChannelList.lm_freq2[currentChannelIdx];
            tcmdParms->u.para.wlanMode = g_lmChannelList.lm_cbState[currentChannelIdx];
            tcmdParms->u.para.rxChain= g_lmChannelList.lm_chainMask[currentChannelIdx];
            tcmdParms->act = TCMD_CONT_RX_PROMIS;
            LMRxIsOn = TRUE;
            utfRxCmd(&utf_dev, tcmdParms);

            //cal_time_stamp[1] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
        }
        else
        {
            A_TIMEOUT_MS(&lm_common_complete_timer, lm_go_complete_timeout_off, 0);
            rateBitIndex = g_lmChannelList.lm_rateIndex[currentChannelIdx];
            colIdx = rateBitIndex % RATE_MASK_BIT_MAX;
            rowIdx = (rateBitIndex >> 5) % RATE_MASK_ROW_MAX;
            rateIndex = Mask2Rate[rowIdx][colIdx];

            currentChannelIdx++;
            currentTotalChannelIdx++;

            if (currentChannelIdx == g_lmChannelList.lm_itemNum && currentTotalChannelIdx < total_channel_list_num)
                restoreChannelListfromHost (&g_lmChannelList, grouplIdx++);
            utfRxStop(&utf_dev);
#if 0
            if (tcmdRxStat.rateCnt[rateIndex]) {
                A_PRINTF_ONCE("rateBitIndex = %d, dataRate = %d\n", rateBitIndex, rateIndex);
                A_PRINTF_ONCE("cont rx report: totalPkt = %d  okPkt = %d  crcErrPkt = %d\n",
                                            tcmdRxStat.totalPkt, tcmdRxStat.okPkt, tcmdRxStat.crcErrPkt);
                A_PRINTF_ONCE("phyErrPkt = %d  secErrPkt = %d rssiInDBm = %d\n ",
                                            tcmdRxStat.phyErrPkt, tcmdRxStat.secErrPkt, tcmdRxStat.rssiInDBm);
                if(tcmdRxStat.okPkt > 0) {
                    A_PRINTF_ONCE("rssiInDBmAvg = %d: ", tcmdRxStat.rssiInDBm/(A_INT32)tcmdRxStat.okPkt);
                    A_PRINTF_ONCE("CRC: %d,PHY:%d,SEC:%d\n", tcmdRxStat.crcErrPkt, tcmdRxStat.phyErrPkt,tcmdRxStat.secErrPkt);
                }

#ifdef SUPPORT_11N
                A_PRINTF_ONCE("rate[%d] %d (SG: %d)\n",rateIndex, tcmdRxStat.rateCnt[rateIndex],tcmdRxStat.rateCntShortGuard[rateIndex]);
#else
                A_PRINTF_ONCE("rate[%d] = %d \n",rateIndex, tcmdRxStat.rateCnt[rateIndex]);
#endif
            }

#endif
            A_MEMZERO(&tcmdRxStat, sizeof(struct tcmd_rx_stat_t));
            LMRxIsOn = FALSE;
        }
    }
    else
    {
        grouplIdx = 0;
        currentChannelIdx = 0;
        currentTotalChannelIdx = 0;
        currentChannelIdx = 0;
        A_DELETE_TIMER(&lm_common_complete_timer);
        LMRxIsOn = FALSE;
        gLMRxDone = TRUE;
        g_listmode = 0;
    }
}

//SRAM_TEXT
void send2HostLMGoListRsp(wlan_tcmd_dev_t *dev,  A_UINT32 cmdId, A_UINT8 status, A_UINT16 timeOn, A_UINT16 timeOff)
{

#ifndef FPGA
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 tmpParaLen = 8;
    A_UINT32 tmpCmdCode = CMD_LMGORSP;

	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
                                                                                                    PARM_LM_CMDID, cmdId, //PARM_LM_CMDID_TX,
                                                                                                    PARM_STATUS, status,
                                                                                                    PARM_TIMEON, timeOn,
                                                                                                    PARM_TIMEOFF, timeOff);

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(dev->wmi, cmdStreamLen, tmpCmdCode, (A_INT8*)rCmdStream);
#endif
    return;
}

//SRAM_TEXT
void LMTLV2GOHandler (void *parms)
{
    A_UINT8 status = LMGO_OK;
    CMD_LMGO_PARMS *pLMGOParms = (CMD_LMGO_PARMS *)parms;

    lm_go_complete_timeout_on = LM_GO_COMPLETE_TIMEOUT_ON;
    lm_go_complete_timeout_off = LM_GO_COMPLETE_TIMEOUT_OFF;
    g_do_full_cal_flag = FALSE;

    if (!(gDPDCalDoneLM  && gLMTxDone && gLMRxDone))
    {
        status = LMGO_FAILURE;
        send2HostLMGoListRsp(&utf_dev,  pLMGOParms->lm_cmdId, status, lm_go_complete_timeout_on, lm_go_complete_timeout_off);
        return;
    }
  // A_PRINTF_ONCE("LMTLV2GOHandler --> lm_cmdId =%d, timeOn=%d, timeOff =%d \n",  pLMGOParms->lm_cmdId, pLMGOParms->timeOn, pLMGOParms->timeOff);
    if ((pLMGOParms->lm_cmdId == PARM_LM_CMDID_TX)  || (pLMGOParms->lm_cmdId == PARM_LM_CMDID_RX))
    {

        if (pLMGOParms->timeOn == 0)
            lm_go_complete_timeout_on = LM_GO_COMPLETE_TIMEOUT_ON;
        else
            lm_go_complete_timeout_on = pLMGOParms->timeOn ;

        if (pLMGOParms->timeOff == 0)
            lm_go_complete_timeout_off = LM_GO_COMPLETE_TIMEOUT_OFF;
        else
            lm_go_complete_timeout_off = pLMGOParms->timeOff ;

        gEnableFastChannelChange = 0;
        currentTotalChannelIdx = 0;
        grouplIdx = 0;
        restoreChannelListfromHost(&g_lmChannelList, grouplIdx++);
        if (g_lmChannelList.lm_itemNum > 0 && total_channel_list_num > 0)
        {
            g_listmode = 1;

            if (pLMGOParms->lm_cmdId == PARM_LM_CMDID_TX)
            {
                gLMTxDone = FALSE;
                A_INIT_TIMER(&lm_common_complete_timer, lm_tx_complete_handler, NULL);
            }
            else
            {
                gLMRxDone = FALSE;
                A_MEMZERO(&tcmdRxStat, sizeof(struct tcmd_rx_stat_t));
                A_INIT_TIMER(&lm_common_complete_timer, lm_rx_complete_handler, NULL);
            }
        }
        else {
                g_listmode = 0;
                status = LMGO_FAILURE;
        }

    }
    else
    {
        status = LMGO_FAILURE;
    }
  //  A_PRINTF_ONCE("LMTLV2GOHandler --> lm_cmdId =%d, timeOn=%d, timeOff =%d \n",  pLMGOParms->lm_cmdId, lm_go_complete_timeout_on, lm_go_complete_timeout_off);
    send2HostLMGoListRsp(&utf_dev,  pLMGOParms->lm_cmdId, status, lm_go_complete_timeout_on, lm_go_complete_timeout_off);

    if (status == LMGO_OK) A_TIMEOUT_MS(&lm_common_complete_timer, 0, 0);

    return;
}

// Init LMHWCal  module
SRAM_TEXT
void initLMGOHandler(void)
{
    registerLMGOHandler(LMTLV2GOHandler);
    return;
}

