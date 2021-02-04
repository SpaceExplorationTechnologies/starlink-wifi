/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
#include "ListModeCommon.h"

extern LMHWCALLIST *pLMHead;
extern _CMD_ALL_PARMS _cmdParms;
extern wlan_tcmd_dev_t utf_dev;
extern LMHWCALNUM hwCalNum;
A_UINT32 total_channel_list_num = 0;
A_UINT32 total_hw_cal_num = 0;
CMD_LMCHANNELLIST_PARMS g_lmChannelList;
SRAM_TEXT
void storeChannelListToHost (CMD_LMCHANNELLIST_PARMS *pChannelList, int grouplIdx)
{
}

/* -------------------------------------------------
* FUNCTION:  send2HostLMChannelListRsp()
*
* NOTE:
*	   send channel list response info to host for process
* --------------------------------------------------
*/
//SRAM_TEXT
void send2HostLMChannelListRsp(wlan_tcmd_dev_t *dev,  A_UINT8 status, A_UINT8 totalHWCalNum, A_UINT16	 totalItemNum, A_UINT16	hwCalTime)
{
#ifndef FPGA
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT32 tmpParaLen = 8;
    A_UINT32 tmpCmdCode = CMD_LMCHANNELLISTRSP;

	pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
                                                                                                    PARM_STATUS, status,
                                                                                                    PARM_TOTALHWCALNUM, totalHWCalNum,
                                                                                                    PARM_TOTALITEMNUM, totalItemNum,
                                                                                                    PARM_HWCALTIME, hwCalTime);

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(dev->wmi, cmdStreamLen, tmpCmdCode, (A_INT8*)rCmdStream);
#endif
    return;
}

//SRAM_TEXT
void LMTLV2ChannelListHandler (void *parms)
{
	CMD_LMCHANNELLIST_PARMS  *pParms = (CMD_LMCHANNELLIST_PARMS *)parms;
    A_UINT8   ret, status = LMHWCAL_OK;
    A_UINT16 freq,   freq2,  chainMask,  wlanMode,  phyId;
    static int grouplIdx = 0;

    A_UINT8 chIdx = 0;
    A_UINT16 hwCalTime = 0;

    if (pParms->lm_flag & LMCHANNELLISTFIRST)
    {
        memset(&hwCalNum, 0, sizeof(LMHWCALNUM));
        freeLMHWCalList();
        total_channel_list_num = 0;
        total_hw_cal_num = 0;
    }

    memcpy(&g_lmChannelList, pParms, sizeof(CMD_LMCHANNELLIST_PARMS));

    if (pParms->lm_itemNum <= MAX_LM_CHANNELLIST_PER_EACH && grouplIdx < MAX_LM_CHANNELLIST_INDEX)
    {

      // A_PRINTF_ONCE("Parms->lm_itemNum =%d\n", pParms->lm_itemNum);

        for (chIdx = 0; chIdx < pParms->lm_itemNum; chIdx++)
        {
            status = LMHWCAL_OK;
            phyId =  pParms->lm_phyId[chIdx];
            wlanMode= pParms->lm_cbState[chIdx];
            chainMask= pParms->lm_chainMask[chIdx];
            freq= pParms->lm_freq[chIdx];
            freq2= pParms->lm_freq2[chIdx];
/*
             A_PRINTF_ONCE("chIdx=%d, phyId= %d, lm_rateIndex:%d, lm_txPower=%d ", chIdx,  phyId, pParms->lm_rateIndex[chIdx], pParms->lm_txPower[chIdx]);
             A_PRINTF_ONCE("freq:%d, freq2:%d, cb_state=%d, chainmask=%d \n ", freq, freq2, wlanMode, chainMask);
*/
            ret = createLMHWCalListFromFreqMaskModePhyId(freq,  freq2, chainMask, wlanMode, phyId);
            total_hw_cal_num += ret;
            total_channel_list_num++;
/*
            A_PRINTF_ONCE("ret = %d, total_hw_cal_num=%d, total_channel_list_num=%d, MAX_LM_CHANNEL_LIST_NUM=%d, ",
                            ret, total_hw_cal_num, total_channel_list_num, MAX_LM_CHANNEL_LIST_NUM);
            A_PRINTF_ONCE("MAX_LM_HWCAL_NUM = %d\n", MAX_LM_HWCAL_NUM);
*/
            if (total_channel_list_num > ((A_UINT32)MAX_LM_CHANNEL_LIST_NUM)) status |= LMCHANNLENUMOVR;
            if (total_hw_cal_num > ((A_UINT32)MAX_LM_HWCAL_NUM))  status |= LMHWCalNUMOVR;

            if (status != LMHWCAL_OK) break;

        }

        hwCalTime = hwCalNum.fullChainNum * LM_HWCAL_COMPLETE_TIMEOUT_LONG;
        hwCalTime += hwCalNum.singleChainNum * LM_HWCAL_COMPLETE_TIMEOUT_SHORT;
     //   A_PRINTF_ONCE("hwCalTime =%d, fullChainNum = %d, singleChainNum=%d\n", hwCalTime, hwCalNum.fullChainNum, hwCalNum.singleChainNum);

        /*store channel list to host */
        storeChannelListToHost (&g_lmChannelList, grouplIdx++);
        /*response to host for channel list information including hwcal time */
        send2HostLMChannelListRsp(&utf_dev,  status, total_hw_cal_num, total_channel_list_num, hwCalTime);

        if (!(pParms->lm_flag & LMCHANNELLISTMORE) && status == LMHWCAL_OK) {
        /* To start HWCAL, and if wants to save time, don't do  reverseCalList(&pLMHead); */
            LMHWCalProcessing();
        }
    }
    else
    {
        status |= LMCHANNLENUMOVR;
        hwCalTime = hwCalNum.fullChainNum * LM_HWCAL_COMPLETE_TIMEOUT_LONG;
        hwCalTime += hwCalNum.singleChainNum * LM_HWCAL_COMPLETE_TIMEOUT_SHORT;
        send2HostLMChannelListRsp(&utf_dev,  status, total_hw_cal_num, total_channel_list_num, hwCalTime);
    }
}

// Init LMHWCal  module
SRAM_TEXT
void initLMChannelListHandler(void)
{
    registerLMCHANNELLISTHandler(LMTLV2ChannelListHandler);
    return;
}

