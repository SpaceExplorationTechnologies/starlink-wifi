/*!
  @file tcmd.c

  @brief
  This file contains main control logic for HALPHY FTM mode test.



*/

/*===========================================================================

  Copyright (c) 2013-2014 Qualcomm Atheros, Inc. All Rights Reserved

  Qualcomm Atheros Confidential and Proprietary.

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Atheros, Inc and all rights therein are expressly reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Atheros, Inc.

===========================================================================*/


/*===========================================================================


                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header: //components/src/wlanfw_halphy_tools.cnss/1.0/target/utf/tcmd_utf/tcmd.c#60 $

when       who     what, where, why
--------------------------------------------------------------------------------
10/13/14   kma      Updated interface API which disables/enables DPD cal
08/26/14   kumarpra    Disable DPD when doing Rx
08/22/14   menglili    Added rssi report adjustment based on Rx gain cal results.

08/20/14   kma     Use DPD enable API to set DPD cal flag and removed unnecessary
                   reset API call
11/15/14   hrashid	Cascade QCA9884  flag for UTF RAM alloc init

===========================================================================*/
#include "mac_trc_reg.h"
#include "mac_ampi_reg.h"
#include <athdefs.h>
#include <utf_dev.h>
#include <if_athvar.h>
#include <sw_version.h>
#include <osapi.h>
#include <soc/soc.h>
#include <testcmd.h>
#include <wlan_scheduler.h>
#include <tcmd_api.h>
#include <whal_api.h>
#include <queue.h>
#include <if_split.h>
#include <regDb.h>
#ifdef SUPPORT_11N
#include "ar6000_internal.h"
#endif
// rx callbacks
#include "utfCallback.h"
#include "whalExtensionGeneric.h"
#include "hal_tcmd.h"
#include "ar6000_tcmd.h"
#include "ar6000_desc.h"
#include "tcmd_tx.h"
#include "tcmd_rx.h"
#include "efuse_api.h"
#include "otpstream_api.h"
#include "halphy_mc_paprd.h"

#include "utf.h"
#include "cmdStream.h"
#include "parseBinCmdStream.h"

#include "hw/mac_hwsch_reg.h"

#ifndef UTFSIM
#include <wmi_tcmd.h>
#else
#include "tcmd_if_rfsim.h"
#endif

#include "qcache_api.h"
#include "codeswap_api.h"

#include "tcmdHostInternal.h"

#if !defined(FPGA)
#if defined(AR9888)
#include "hw/radio_peregrine.h"
#include <qc98xx_eeprom.h>
#endif
#endif

#define WHAL_VHT160_CHANNEL_CENTER_SHIFT 40 /* MHz */

extern HALPHY_PAPRD_STRUCT *pPaprdStruct;
extern WHAL_PAPRD_INDIRECTION_TABLE   *pWhalPaprdIndirectionTable;
extern HALPHY_PAPRD_DEVICE_SETTING paprd_cal_setting;


#if (1) /* to get the definition of whal internal function "whalDoCalibration" */
#include "ar6000_reset.h"
extern WHAL_RESET_INDIRECTION_TABLE *pWhalResetIndirectionTable;
#endif

#if (1) /* to get the definition of tx send internal interrupt handle */
#include "ar_wal_tx_internal.h"
#endif

/*
 * MACROS
 */
#ifdef TCMD_DEBUG
static A_UINT32 tcmd_debug = 1;
#define TCMD_PRINTF(args...)         if(tcmd_debug) A_PRINTF(args);
#else
#define TCMD_PRINTF(args...)
#endif

#define TCMD_ATH_TXBUF        8
#define TCMD_ATH_RXBUF        1

#define TCMD_TXQ              0
#define DEFAULT_NOISE_FLOOR   -96
#define A_FREQ_MIN_11P                  5835
#define A_FREQ_MAX_11P                  5925
/* 4.9G HALF rate for IEEE 802.11j
 * http://bonnie/system/standards/docs-ieee-802.11/802.11j-2004.pdf page 40
*/
#define HALF_RATE_4P9G_MIN              4915
#define HALF_RATE_4P9G_MAX              4945

//#define TCMD_MAX_RDPWR        27  /* copy from haldemos */ //move to tcmd_api.h
#define TCMD_MAX_RATE_POWER   63
#define DEFAULT_REG_DOMAIN    0x4060
#define TCMD_DEFAULT_FREQ_2G     2412
#define TCMD_DEFAULT_FREQ_5G     5500
#define TCMD_DEFAULT_WLAN_MODE_2G   MODE_11NG_HT20
#define TCMD_DEFAULT_WLAN_MODE_5G   MODE_11NA_HT20
#define TCMD_DEFAULT_TXPWR_CUS88 0
#define TCMD_DEFAULT_TXPWR       10
#define TCMD_DEFAULT_TXPKTSZ     1500
#if defined(QCA9888) || \
   (!defined(FPGA) && (defined(AR900B) || defined(QCA9984) || defined(IPQ4019)))
#undef  DISABLE_RX
#else
#define  DISABLE_RX
#endif

extern A_BOOL g_xtal_cal_flag;
/*
 * External functions
 */
extern void tcReadCmds(A_UINT8 *cmdBuf, A_UINT16 len);
extern A_INT32 htcDispatchCmd(wlan_tcmd_dev_t *dev);
extern void initLegHostIFCmdsSupport(void);
extern void tcmdLinkTx(wlan_tcmd_dev_t *dev);
extern void tcmd_link_trx_init();
extern tcmd_link_trx tcmdLinkTRx;
extern A_UINT32 processRxDataStats(A_UINT32 rIdx, A_UINT32 frame_length, A_UCHAR rsStatus, struct wal_rx_status *status);
extern void processTxDataStats(A_UINT32 pkt_len, A_UINT32 total_pkts, A_UINT32 good_pkts, void *hw_status, void *sw_status);
extern void ar900BGetRxGainCalData4Chan(A_UINT32 freq);
extern A_UINT8 isDPDEnableInBDF(void);
extern A_BOOL gDPDCalDone;
extern A_BOOL gDeafMode;
extern A_INT8 getChain(A_UINT8 chMask);
/*
 * LOCAL DECLARATION
 */
extern wlan_tcmd_dev_t utf_dev;
extern tcmd_state_t tcmd_state;
extern struct frame_enacap_config g_encap_cfg;
extern struct waltest_ctxt g_waltest_ctxt;
extern void ar6000SingleCarrierRestore();
extern struct frame_enacap_config g_encap_cfg;

void waltestDpdSetupLM(wlan_tcmd_dev_t *dev)
{
    tcmd_state.tcmdTxGo =0;
    tcmd_state.tcmdRxGo = 0;
    whalPaprdHwDisable();
    // Restore analog registers changed due to xtal cal if valid
    ar6000SingleCarrierRestore();

    g_encap_cfg.sa_addr = SA_ADDR;
    g_encap_cfg.da_addr = DA_ADDR;
    g_encap_cfg.bss_addr = BSS_ADDR;

    waltest_tx(dev->pdev, dev, NULL, NULL);
    //waltest_tx(dev->pdev, dev, NULL, NULL);
    whalEnableInterrupts(WHAL_INT_TX);

}
extern struct waltest_rx_config g_waltest_rx_config;

void waltestDpdDetachLM(wal_pdev_t *pdev)
{
    struct waltest_ctxt *ctxt = &g_waltest_ctxt;

    if (ctxt->bss_peer)
    {
        wal_peer_free(ctxt->bss_peer);
        ctxt->bss_peer = NULL;
    }
    /* free peer and vdev */
	if(ctxt->vdev != NULL)
    {
        if (ctxt->peer)
            wal_peer_free(ctxt->peer);
        if (ctxt->vdev)
	        wal_vdev_detach(ctxt->vdev);
        ctxt->peer = NULL;
	    ctxt->vdev = NULL;
	    g_waltest_rx_config.vdev = NULL;
 	    g_waltest_rx_config.peer = NULL;
	    tcmd_state.tcmdRxGo = 0;
	    tcmd_state.tcmdTxGo = 0;
    }
    tcmd_state.tcmdTxGo = 0;
    whalDisableInterrupts(WHAL_INT_TX);
    whalEnableAni(TRUE);
}



