/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
#include "ListModeCommon.h"

/* for single chain, total hw cal time = 100 ms(setup channel prep) + 60 (DPDCAL) + 150 ms (TX/RXIQ, CL, NF, RXDCO...) => 350 ms
    for 4 chains, total hw cal time = 100 ms(setup channel prep) + 65 * 4  (DPDCAL) + 250 ms (TX/RXIQ, CL, NF, RXDCO...) => 600 ms
 A_PRINTF_ONCE NEED 100MS
    Above time estimation cannot have A_PRINTF in code, otherwise, it cannot be guranteed
*/
static A_UINT32 lm_hwfullcal_complete_timeout_short = LM_HWCAL_COMPLETE_TIMEOUT_SHORT;
static A_UINT32 lm_hwfullcal_complete_timeout_long = LM_HWCAL_COMPLETE_TIMEOUT_LONG;
//extern
//A_UINT32 LMHWCal_time_stamp[6];

extern A_TIMER lm_common_complete_timer;
void lm_hwfullcal_complete_handler(A_HANDLE handler, void *data);
extern HALPHY_PAPRD_STRUCT *pPaprdStruct;
extern WHAL_PAPRD_INDIRECTION_TABLE   *pWhalPaprdIndirectionTable;
extern HALPHY_PAPRD_DEVICE_SETTING paprd_cal_setting;

extern A_STATUS tcmd_setup_channel(wlan_tcmd_dev_t *dev, A_BOOL doIt, A_UINT32 freq, A_UINT32 wlanMode, A_UINT32 bandwidth, A_UINT32 freq2, A_UINT32 chain);
extern TCMD_CONT_TX tx_tcmdParms;
extern void utfTxStart(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern void  utfTxStop(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern void tcmd_cont_tx_cmd(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);

extern wlan_tcmd_dev_t utf_dev;
//extern tcmd_state_t tcmd_state;
//extern int g_do_tcmd_setup_channel_flag;
//void static send2HostLMHWCALParms(wlan_tcmd_dev_t *dev,  A_UINT8 status);
extern void tcmd_pm_awake();
extern A_UINT8 isDPDEnableInBDF(void);
extern void waltestDpdSetupLM(wlan_tcmd_dev_t *dev);
extern void waltestDpdDetachLM(wal_pdev_t *pdev);

//static int LM_PAPRD_CAL_TIMEOUT = 285;
//static  int lm_total_hwcal_count = 0;

extern A_BOOL gEnableFastChannelChange;
extern A_BOOL gDPDCalDone;
extern int g_listmode;
A_BOOL gDPDCalDoneLM = TRUE;
extern A_BOOL g_do_full_cal_flag;
extern LMHWCALLIST *pLMHead, *g_currentLM;
extern void tcmd_get_channel(A_UINT32 freq, A_UINT32 wlanMode, A_UINT32 bandwidth, WHAL_CHANNEL *chan, A_UINT32 freq2);
extern void ar6000SingleCarrierRestore();
extern LMHWCALNUM hwCalNum;

//SRAM_TEXT
void lm_hwfullcal_complete_handler(A_HANDLE handler, void *pParm)
{
    wlan_tcmd_dev_t *dev = (wlan_tcmd_dev_t *)&utf_dev;
    A_UINT8 errCode = LMHWCAL_OK;
    A_UINT8 bandwidth = 0;
    A_UNTIMEOUT(&lm_common_complete_timer);
    A_UINT32 dynamic_timeout = lm_hwfullcal_complete_timeout_short;

   // A_PRINTF_ONCE("gDPDCalDone=%d\n", gDPDCalDone);
    if (gDPDCalDone) gDPDCalDone = FALSE;

    if (g_currentLM != NULL)
    {
//            LMHWCal_time_stamp[0] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
       //    A_PRINTF_ONCE("gDPDCalDone=%d, g_currentLM->chainMask=%d\n", gDPDCalDone, g_currentLM->chainMask);
            gEnableFastChannelChange =  0;
            if (g_currentLM->chainMask == 1 || g_currentLM->chainMask == 2 ||
                g_currentLM->chainMask == 4 || g_currentLM->chainMask == 8)
                dynamic_timeout = lm_hwfullcal_complete_timeout_short;
            else
                dynamic_timeout = lm_hwfullcal_complete_timeout_long;

            if (g_currentLM->wlanMode >= TCMD_WLAN_MODE_VHT80P80)
                dynamic_timeout = (dynamic_timeout << 1);

            A_TIMEOUT_MS(&lm_common_complete_timer, dynamic_timeout, 0);
#if 1
            tcmd_pm_awake();
            wal_rc_set_hw_chainmasks(dev->pdev, g_currentLM->chainMask, g_currentLM->chainMask);
            if (A_OK != tcmd_setup_channel(dev, TRUE, g_currentLM->freq, g_currentLM->wlanMode, bandwidth, g_currentLM->freq2, g_currentLM->chainMask))
               errCode = LMHWCAL_FAILURE;
            //whalSetTxPowerLimit(30, 0);
          //  whalDoDPDCalibration(TRUE);
#endif
            g_currentLM = g_currentLM->next;
    }
    else
    {
        freeLMHWCalList();
        gDPDCalDoneLM = TRUE;
        waltestDpdDetachLM(dev->pdev);
        A_DELETE_TIMER(&lm_common_complete_timer);
    }

}

/* -------------------------------------------------
 * FUNCTION:  LMHWCalProc()
 *
 * NOTE:
 *      Handling the host LMHWCal cmds with parameters
 * --------------------------------------------------
 */

//SRAM_TEXT
void LMHWCalProcessing(void)
{

    wlan_tcmd_dev_t *dev = (wlan_tcmd_dev_t *)&utf_dev;

//    g_do_tcmd_setup_channel_flag = 0;
    gEnableFastChannelChange = FALSE;
    g_listmode = 1;
    
    utfTxStop(dev, &tx_tcmdParms);

    if (isDPDEnableInBDF()) {
            whalPaprdEnableCal(TRUE);
            if (tx_tcmdParms.tpcm == TPC_FORCED_GAINIDX) {
                whalPaprdForceTxPaDacGain(tx_tcmdParms.gainIdx, tx_tcmdParms.txChain, tx_tcmdParms.dacGain, tx_tcmdParms.paConfig);
            }

        } else {
            whalPaprdEnableCal(FALSE);
        }
    //whalPaprdEnableCal(FALSE);
    whalPaprdEnableCal(TRUE);

//    printHWCALList();
    g_currentLM = pLMHead;
    gDPDCalDone = FALSE;
   // tcmd_state.tcmdTxGo =0;
    //tcmd_state.tcmdRxGo = 0;
    whalPaprdHwDisable();
    // Restore analog registers changed due to xtal cal if valid
    ar6000SingleCarrierRestore();

    waltestDpdSetupLM(dev);

    whalEnableInterrupts(WHAL_INT_TX);
    g_do_full_cal_flag = TRUE;
    if (pLMHead != NULL)
    {
        gDPDCalDoneLM = FALSE;
        A_INIT_TIMER(&lm_common_complete_timer, lm_hwfullcal_complete_handler, NULL);
       A_TIMEOUT_MS(&lm_common_complete_timer, 0, 0);
    }
    else
    {
        waltestDpdDetachLM(dev->pdev);
    }

    return;
}

