/*!
  @file tcmd.c

  @brief
  This file contains main control logic for HALPHY FTM mode test.



*/

/*===========================================================================

  Copyright (c) 2013 - 2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
 
  2013 - 2016 Qualcomm Atheros, Inc.

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

$Header: //components/rel/wlanfw_halphy_tools.cnss/1.12.0/target/utf/tcmd_utf/tcmd.c#1 $

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
#include "rand_mac_addr_tbl.h" /* a table of random STA mac addrs */
#include "efuse_api.h"
#include "otpstream_api.h"
#include "halphy_mc_paprd.h"
#include "utf_cal.h"
#include "halphy_cal.h"

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

extern A_UINT32 g_dbg_txop_burst_limit;

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
#define TCMD_DEFAULT_CHAINMASK 0x0

#if defined(QCA9888) || \
   (!defined(FPGA) && (defined(AR900B) || defined(QCA9984) || defined(IPQ4019)))
#undef  DISABLE_RX
#else
#define  DISABLE_RX
#endif

extern A_BOOL g_xtal_cal_flag;
extern A_BOOL g_do_full_cal_flag;
extern int g_listmode;
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
int g_tx_timeout_count = 0;
extern A_BOOL gDeafMode;
extern A_INT8 getChain(A_UINT8 chMask);
/*
 * LOCAL DECLARATION
 */
wlan_tcmd_dev_t utf_dev;
tcmd_state_t tcmd_state;
static A_INT32 noise_floor = DEFAULT_NOISE_FLOOR;
tcmd_rx_stat_t tcmdRxStat;
tcmd_tx_stat_t tcmdTxStat;
static WLAN_PHY_MODE curWlanMode = MODE_11G;
static A_BOOL auto_deep_sleep_mode = FALSE;
static A_UCHAR rxFilterMAC[IEEE80211_ADDR_LEN]={0x01, 0x00, 0x00, 0xC0, 0xFF, 0xEE};
static A_UINT8 stop_tx = 0;
static A_UINT32 tcmd_tx_complete_timeout = 0;
static A_TIMER tcmd_tx_complete_timer;
static A_UINT8 tcmd_txchain_mask = 0xF;
static A_BOOL isChannelSetupOk = TRUE;
static A_UINT16 tcmd_default_freq = TCMD_DEFAULT_FREQ_5G;
extern A_BOOL gForceTxPwrMode;
//#ifndef WHAL_MAX_HOME_CHANNEL
#define WHAL_MAX_HOME_CHANNEL 2
static WHAL_CHANNEL homeChan[WHAL_MAX_HOME_CHANNEL];
//#endif

/*
 * External declarations
 */
/* memTable is a memory pool that pre-assigned for MDK
 * here we are re-using this memory pool for tcmd's txbuf, athbuf, rxbuf and ringstatusbuf
 * as MDK and tcmd will not be running simultaneous */
#ifdef UTFSIM
A_UCHAR memTable[NUM_TEST_PKTS][PKT_SEG1_LEN];
#else
extern A_UCHAR memTable[0][0];
#endif
extern struct frame_enacap_config g_encap_cfg;

extern _VALUES_OF_INTEREST ValuesOfInterest;
extern A_BOOL hostTlvCmdProcess;

extern void cmdProcessingEntry(void);
extern A_BOOL waitForNfCalToComplete;
extern A_UINT32 whalConfigFlag;

A_BOOL gEnableFastChannelChange = FALSE;
#ifndef FPGA
extern A_BOOL gFTMCalInProgress;
#endif

#ifndef IS_MAC_NULL
#define IS_MAC_NULL(mac) (mac[0]==0 && mac[1]==0 && mac[2]==0 && mac[3]==0 && mac[4]==0 && mac[5]==0)
#endif
#ifndef IS_MAC_BCAST
#define IS_MAC_BCAST(mac) (*mac==0xff)
#endif

/*
 * LOCAL PROTOTYPES
 */
#define _USE_TX_INT 0
#define _USE_RX_INT 0
#if defined(_USE_RX_INT)
A_STATUS tcmd_rx_complete_handler(void *ctxt, A_UINT32 data_len, A_UINT32 rate_index,
                                  A_UCHAR rsStatus, struct wal_rx_status *mpdu_status);
#endif
#if defined(_USE_TX_INT)
A_STATUS tcmd_tx_complete_handler(void *txt, A_UINT32 total_pkts, A_UINT32 good_pkts, void *hw_status, void *sw_status);
#endif

void tcmd_tx_complete_timer_handler(A_HANDLE handler, void *data);

A_STATUS tcmd_setup_channel(wlan_tcmd_dev_t *dev, A_BOOL doIt, A_UINT32 freq, A_UINT32 wlanMode, A_UINT32 bandwidth, A_UINT32 freq2, A_UINT32 chain);
static void tcmd_cont_tx_sine(wlan_tcmd_dev_t *dev, A_UINT32 freq,
                              A_UINT32 dataRate, A_UINT32 txPwr, A_UINT32 antenna, A_UINT32 chainmask);
#if 0 // Allan
static void tcmd_create_txpkt(wlan_tcmd_dev_t *dev,
                              A_UINT32 dataBodyLength, A_UINT8  Pattern, A_UINT32 seqNo, A_UINT32 qos,
                              A_UINT32 broadcast, A_UCHAR *srcmac, A_UCHAR *dstmac, A_UCHAR *bssid, A_UINT8 *pPktAddress, //packet buffer start address
                              A_UINT32 *pPktSize,        //return size
                              A_UINT32 txType, A_UINT32 first);
#endif
static void tcmd_cont_tx_data(wlan_tcmd_dev_t *dev, TCMD_CONT_TX * contTx ,A_UINT32 aifswait, A_BOOL disableContinuousTx,  A_UINT32 numPkts);
static void tcmd_cont_data_tx_stop(wlan_tcmd_dev_t *dev);
static void tcmd_cont_sine_tx_stop(wlan_tcmd_dev_t *dev);
static A_UINT32 tcmd_cont_rx_begin(wlan_tcmd_dev_t *dev, TCMD_CONT_RX_ACT act,
                               A_UINT32 freq, A_UINT32 antenna, A_UINT32 wlanMode, A_UINT32 bandwidth, A_UINT32 ack, A_UINT32 rxChain, A_UINT32 freq2);
static void tcmd_stop_cont_rx(wlan_tcmd_dev_t *dev);
static void tcmd_cont_tx_cwtone(wlan_tcmd_dev_t *dev, A_UINT32 freq, A_UINT8 gainIdx, A_UINT32 chainmask);
static void tcmd_cont_tx_clpcpkt(wlan_tcmd_dev_t *dev, A_UINT32 freq, A_UINT8 gainIdx, A_UINT32 chainmask, A_INT8 dacGain, A_UINT8 paCfg, A_UINT8 tpcm);

#ifdef AR6002_REV2
static void tcmd_stabilize_power(wlan_tcmd_dev_t *dev, A_UINT32 freq,
                                 A_UINT32 dataRate, A_UINT32 txPwr, A_UINT32 antenna);
#endif

//void tcmd_cont_tx_cmd(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *);
//void tcmd_cont_rx_cmd(wlan_tcmd_dev_t *dev, TCMD_CONT_RX *);
void tcmd_pm_cmd(wlan_tcmd_dev_t *dev, TCMD_PM *);
void tcmd_pm_awake();
static void tcmd_pm_sleep();
static A_STATUS
tcmd_setup_channel_real(wlan_tcmd_dev_t *dev, A_UINT32 freq, A_UINT32 wlanMode, A_UINT32 bandwidth, A_BOOL doIt, A_UINT32 freq2, A_UINT32 chain);
void tcmd_reset_pre_callback(WHAL_CHANNEL *curChan, A_UINT32 resetCause);
void tcmd_reset_post_callback(WHAL_CHANNEL *curChan, A_UINT32 resetCause);

/*
 * FUNCTION DEFINITIONS
 */


/*
 * After bringing up the BSP, the os calls app_start() which would call
 * tcmd_main().
 */

//#if defined(AR900B) && (TARGET_VER == 1) && !defined(FPGA) && !defined(A_SIMOS_DEVHOST)
#if (defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888))  && !defined(A_SIMOS_DEVHOST)
void utf_allocram_init(void)
{
    A_UINT32 astart;
    A_UINT32 asize;
    int rval;
 extern char ALLOC_IRAM_EXTERN;

#if defined(CONFIG_SRAM)
    extern char ALLOC_SRAM_EXTERN;
#endif

        A_ALLOCRAM_INIT(0, 0);
    /* Initialize the IRAM allocation arena. Note that the ld script files
     * that define _eiram_data Dword-align that value.
     */
                                   /* Initialize the IRAM allocation arena. Note that the ld script files
     * that define _eiram_data Dword-align that value.
     */
    astart = (A_UINT32)alloc_iram_arena_start;
    asize = (TARG_IRAM_START + TARG_IRAM_SZ) - astart;
    rval = A_ALLOCRAM_SECONDARY_ARENA_INIT((void *)astart, asize, ALLOCRAM_IRAM_ARENA);
    A_ASSERT(ALLOCRAM_IRAM_ARENA == rval);

#if defined(CONFIG_INTERFACE_MEMORY)
    if (A_IS_HIGH_LATENCY_INTERCONNECT()) {
        A_ALLOCRAM_SECONDARY_ARENA_INIT(
            (void *)INTF_ALLOCRAM_START, INTF_ALLOCRAM_SZ_HL, ALLOCRAM_INTERFACE_ARENA);
    } /*else {
        A_ALLOCRAM_SECONDARY_ARENA_INIT(
            (void *)INTF_ALLOCRAM_START, INTF_ALLOCRAM_SZ_LL, ALLOCRAM_INTERFACE_ARENA);
    }*/
#endif

#if defined(CONFIG_SRAM)
    /* Initialize the SRAM allocation arena. Note that the ld script files
     * that define _esram_data Dword-align that value.
     */
    astart = (A_UINT32)alloc_sram_arena_start;
    asize = (TARG_SRAM_START + TARG_SRAM_SZ) - astart;
    rval = A_ALLOCRAM_SECONDARY_ARENA_INIT((void *)astart, asize, ALLOCRAM_SRAM_ARENA);


#endif
}
#endif
extern void utf_hif_module_install();
void
tcmd_main(void)
{
    A_UINT8 macAddr[6];
//TODO CASCADE supposrt this when patches needed
#if defined(AR900B) && (TARGET_VER == 1)  //  there is no patch for V2.0 currently, will support it in mac_core component later
    extern void install_phase0_patches(void);
    install_phase0_patches();
#endif

    //A_PRINTF_ALWAYS("utf ver - 0x%x - %s-%s\n",
    //         AR6K_SW_VERSION,__DATE__, __TIME__);

    if (!(tcmd_state.flags & _UTF_RAM_ALLOCATED))
    {
//#if defined(AR900B) && (TARGET_VER == 1) && !defined(FPGA) && !defined(A_SIMOS_DEVHOST)
#if (defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)) && !defined(A_SIMOS_DEVHOST)
	utf_allocram_init();
#else
	A_ALLOCRAM_INIT(0, 0);
#endif
        tcmd_state.flags |= _UTF_RAM_ALLOCATED;
    }

    codeswap_init();
    utf_hif_module_install();

    /* Initialize WMITCMD ctrl path - WMITCMD will register the service with
       HTC */
    tcmd_attach(&utf_dev, macAddr);
#if defined(DBGLOG_FTM_SUPPORT)
    if (HOST_INTEREST_DBGLOG_IS_ENABLED()) {
        DBGLOG_MODULE_INSTALL();
    }
#endif
#if defined(_UTF_HOSTIF_TS_W_WMI)
    utf_dev.wmi = wmiTcmdInit(&utf_dev);
#endif
}


extern A_UINT32 g_waltest_ast_max_sta;
/* This is the MAC address that comes from EEPROM */
unsigned char MY_MAC_ADDR[6] =  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
/* This is the MAC address of the TXing STA */
unsigned char SA_ADDR[6] =  {0x00, 0x03, 0x7F, 0x03, 0x40, 0x33};
/* This is the MAC address of the RXing STA */
unsigned char DA_ADDR[6] =  {0x00, 0x03, 0x7F, 0x11, 0x12, 0x13};
/* This is the common BSS address for the two peers */
unsigned char BSS_ADDR[6] = {0x01, 0x00, 0x00, 0xCA, 0xFF, 0xEE};
/* This is the broadcast address*/
unsigned char BCAST_ADDR[6] = {0xFF,0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
/* This is the MAC address of the WDS destination */
unsigned char WDS_DA_ADDR[6] =  {0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0};

wal_ast_config_param g_waltest_ast_config = {
        .num_ast_entries = 32,
        .max_skid = 32,
        .ignore_mac31_0 = 1,
        .hash_ctrl_disable = 1};

extern int waltest_tx_comp_buf_get(void *test_ctxt, A_UINT16 **frag_desc_list_buf, int num_elems);
extern void waltest_tx_comp_indicate(void *test_ctxt, A_UINT16 *frag_desc_list_buf, int num_elems,
                int tid_num, A_UINT32 msg_type);

/* Attach a pdev */
void tcmd_wal_setup(wlan_tcmd_dev_t *dev)
{
    wal_pdev_t *pdev;
    WHAL_CHANNEL chan;
    wal_pdev_param dev_param;
    wal_pdev_config_param config_param;
    unsigned char *macaddr = MY_MAC_ADDR;
    WHAL_DEV_CAPS_STRUCT dev_cap;

    g_dbg_txop_burst_limit = 0;
    waitForNfCalToComplete = TRUE;
    whalConfigFlag = whalConfigFlag | WHAL_CONFIG_NF_WAR | WHAL_CONFIG_CAL_WAR;

    A_MEMZERO(&config_param, sizeof(config_param));

#define MAX_PEER_ENTRIES 2
#define MAX_TID_ENTRIES  24
#define MAX_AST_ENTRIES  2
#define MAX_VDEV_ENTRIES 4
#define MAX_SKID_LEN 32

    config_param.num_vdev_entries=MAX_VDEV_ENTRIES;

    memcpy(&config_param.ast_param, &g_waltest_ast_config,
        sizeof(g_waltest_ast_config));
    config_param.num_peer_entries=MAX_PEER_ENTRIES;
    config_param.num_peer_key_entries=MAX_PEER_ENTRIES*4;
    config_param.num_tid_entries=MAX_TID_ENTRIES;
    config_param.tx_chain_mask=0xF;
    config_param.rx_chain_mask=0xF;
    config_param.num_registered_handlers = 20;
    config_param.num_vdev_registered_handlers = 4;
    config_param.num_peer_registered_handlers = 4;
    config_param.rx_decap_mode = WAL_PKT_TYPE_RAW;
    config_param.num_mcast_groups = 0;
    config_param.num_mcast_table_elems = 0;
    config_param.tx_dbg_log_size = 0;
    config_param.mcast2ucast_mode = 0; /* disabled */
    config_param.num_msdu_desc =1100;
    config_param.max_frag_entries = 10;
    config_param.iphdr_pad_config = 1;          //VJ's change
#if defined(CONFIG_MU_MIMO_FTM_SUPPORT)
    config_param.prefetch_config = 0;
#endif

#undef MAX_PEER_ENTRIES
#undef MAX_TID_ENTRIES
#undef MAX_AST_ENTRIES
#undef MAX_VDEV_ENTRIES
#undef MAX_SKID_LEN

    dev_param.dev_base_addr = (void *) 0x1000;
    dev_param.ic_opmode = WHAL_M_STA;
    dev_param.macaddr = macaddr;

    whalGetDeviceCaps(&dev_cap);
    if (dev_cap.supported_bands == WHAL_WLAN_11G_CAPABILITY) {
	    tcmd_default_freq = TCMD_DEFAULT_FREQ_2G;
    	chan.phy_mode = TCMD_DEFAULT_WLAN_MODE_2G;
    }
    else {
	    tcmd_default_freq = TCMD_DEFAULT_FREQ_5G;
	    chan.phy_mode = TCMD_DEFAULT_WLAN_MODE_5G;
    }
    chan.max_reg_power = 30;
    chan.mhz = tcmd_default_freq;
    chan.flags = 0;
    chan.band_center_freq1 = chan.mhz;
    chan.band_center_freq2 = chan.mhz;
    dev_param.pChan = &chan;

    wal_dev_attach(&pdev, &dev_param, &config_param);

//    whalDisableInterrupts(WHAL_INT_BB_PANIC);

    if (!pdev) {
         A_PRINTF("pdev attach Failed \n");
         A_ASSERT(FALSE);
         return;
    }

#if defined(CONFIG_MU_MIMO_FTM_SUPPORT)
    qcache_init(pdev,config_param.num_peer_entries,g_waltest_ast_config.num_ast_entries);
#endif

    pdev->reset_cause_bitmap &= ~PDEV_RESET_CONSEC_FAILURE;

    tx_send_install_txcomp_buf_req(pdev,
                                waltest_tx_comp_buf_get, NULL);

    tx_send_install_txcomp_indicate(pdev,
                                waltest_tx_comp_indicate, NULL);

    /* install rate lookup for wal tx module */
    //tx_send_install_rate_ctrl_query(pdev, rc_query_rate_info, NULL);
    whalSetRateControlCallback(wal_rc_dbg_txdone_stats);
    /* install rate lookup for wal tx module */
    wal_rc_install_rate_ctrl_query(pdev, wal_rc_query_rate_info, NULL);
    wal_rc_enable_dyn_bw(pdev, TRUE);

    dev->pWhalStruct = pdev->whal;
    dev->pdev = pdev;
    curWlanMode = chan.phy_mode;

    /* Stop Receive */
#if !defined(AR900B) && !defined(QCA9984) && !defined(IPQ4019) && !defined(QCA9888)
    whalStopPcuReceive();
    whalStopDmaReceive();
#endif

    wal_phy_dev_fast_wake_request(pdev);
    //wal_rx_ring_setup(pdev, WAL_RX_RING_LOCAL_PKT, sizeof(struct rxbf_data), 0, 10);
    //wal_rx_ring_setup(pdev, WAL_RX_RING_LOCAL_PKT, sizeof(struct rxbf_data), 0, 4);
    wal_rx_ring_setup(pdev, WAL_RX_RING_LOCAL_PKT, sizeof(struct rxbf_data), 0, 20);
}

#if !defined(FPGA) && defined(QCA9984)

#define WHAL_FULLCAL_CHUNK_LENGTH 6*1024
A_UINT32 g_tcmdCalBufData[WHAL_FULLCAL_CHUNK_LENGTH];

//SRAM_TEXT
static A_STATUS
tcmd_SaveFullCalData(WHAL_CHANNEL *currChan, A_UINT8 chainIdx)
{
	A_STATUS status = A_ERROR;

	A_MEMSET(g_tcmdCalBufData,0xFF,sizeof(g_tcmdCalBufData));
	void *ptr;
	A_UINT32 totalSize=0,len=0,chanNum=0,is2GHz,temperature, nMode, nChainMask;
//    if (!g_do_full_cal_flag)  return A_OK;
  if (g_listmode == 0) return A_ERROR;

	if (!currChan){
		return A_ERROR;
	}
	is2GHz = IS_CHAN_2GHZ(currChan);
	chanNum = WHAL_FREQ2NUM(currChan->mhz,is2GHz);

    if (WHAL_IS_CHAN_20MHZ(currChan)) nMode = 0;
    else if (WHAL_IS_CHAN_40MHZ(currChan)) nMode = 1;
    else if (WHAL_IS_CHAN_80MHZ(currChan)) nMode = 2;
    else if (WHAL_IS_CHAN_160MHZ(currChan)) nMode = 3;


//	A_PRINTF_ONCE("Chain 0x%x Chan %d\n",chainIdx,chanNum);

	// Store temp with data
	temperature = whalGetCurrentTemp() & 0xff;

	// Clear channel cache data
	//utf_cal_clear_channel_data(chanNum);
    utf_cal_clear_channel_data(chanNum);
	totalSize = 4
			+ sizeof(TCMD_TXIQ_SAVE2MEM_DATA)
			+ sizeof(TCMD_TXCL_SAVE2MEM_DATA)
			+ sizeof(TCMD_RXDCO_SAVE2MEM_DATA)
			+ sizeof(TCMD_RXIQ_SAVE2MEM_DATA)
			+ sizeof(TCMD_RXFILT_SAVE2MEM_DATA)
			;
	g_tcmdCalBufData[0] = (totalSize & 0xffff) | (temperature << 16);

	ptr = &g_tcmdCalBufData[1] + len/4;
	len += whalSaveTxIQToMem_tcmd(ptr,chainIdx);

	ptr = &g_tcmdCalBufData[1] + len/4;
	len += whalSaveRxDcoToMem_tcmd(ptr,chainIdx);

	ptr = &g_tcmdCalBufData[1] + len/4;
	len += whalSaveRxIQToMem_tcmd(ptr,chainIdx);

	ptr = &g_tcmdCalBufData[1] + len/4;
	len += whalSaveTxClToMem_tcmd(ptr,chainIdx);

	ptr = &g_tcmdCalBufData[1] + len/4;
	len += whalSaveRxFiltCalToMem_tcmd(ptr,chainIdx);


	// Store second chunk of data
    nChainMask = 0x1 << chainIdx;

	status = utf_cal_store_data(chanNum,(A_UINT32)&g_tcmdCalBufData[0],
			WHAL_FULLCAL_CHUNK_LENGTH, WHAL_FULLCAL_CHUNK_LENGTH, 0, nChainMask, nMode);

//	A_UINT32 i;
//	for(i=0;i<100;i++){
//		if(i%8==0)
//			A_PRINTF_ONCE("\n");
//		A_PRINTF_ONCE("0x%08x| ",g_tcmdCalBufData[i]);
//	}
//	A_PRINTF_ONCE("\n");


	return status;
}

extern TCMD_CAL_SAVE2MEM_TABLE *g_tcmdCalData;
//SRAM_TEXT
static A_STATUS
tcmd_RestoreFullCalData(WHAL_CHANNEL *currChan, A_UINT8 chainIdx)
{
	//	A_UINT32 i;
	A_STATUS status = A_ERROR;
  //A_INT32 cal_time_stamp[2] = {0,0};

  if (g_listmode == 0) return A_ERROR;

	//cal_time_stamp[0] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
	//whalPreRestoreCal_tcmd();

	A_UINT32 calSize=0,offset=0,is2GHz=0,chanNum=0, nMode;
	A_UINT32 storedTemp = 0;
	A_INT32 deltaTemp = 0;
	void* ptr;

	if (!currChan){
		return A_ERROR;
	}
	is2GHz = IS_CHAN_2GHZ(currChan);
	chanNum = WHAL_FREQ2NUM(currChan->mhz,is2GHz);

    if (WHAL_IS_CHAN_20MHZ(currChan)) nMode = 0;
    else if (WHAL_IS_CHAN_40MHZ(currChan)) nMode = 1;
    else if (WHAL_IS_CHAN_80MHZ(currChan)) nMode = 2;
    else if (WHAL_IS_CHAN_160MHZ(currChan)) nMode = 3;

	A_MEMSET(g_tcmdCalBufData,0,sizeof(g_tcmdCalBufData));

	//Get first chunk data
	status = utf_cal_get_data(chanNum,(A_UINT32)&g_tcmdCalBufData,
			WHAL_FULLCAL_CHUNK_LENGTH,WHAL_FULLCAL_CHUNK_LENGTH, 0, (0x1 << chainIdx), nMode);


if (g_tcmdCalBufData[0] == 0 || status != A_OK)
{
//       g_do_full_cal_flag = TRUE;
       // A_PRINTF_ONCE("-----Restore failed, reCal at  chain %d \n", chainIdx);
		return A_ERROR;
}

//	A_PRINTF_ONCE("-----Restore----- chain %d \n",chainIdx);
//	A_UINT32 i;
//	for(i=0;i<100;i++){
//		if(i%8==0)
//			A_PRINTF_ONCE("\n");
//		A_PRINTF_ONCE("0x%08x| ",g_tcmdCalBufData[i]);
//	}
//	A_PRINTF_ONCE("\n");

	// Check if temperature has changed
//if(g_do_full_cal_flag) {
	storedTemp = (g_tcmdCalBufData[0] >> 16) & 0xff;
	deltaTemp = (whalGetCurrentTemp() & 0xff) - storedTemp;

//	if ((deltaTemp > 45) || (deltaTemp < -45))
//		return A_ERROR;


	//WHAL_CALSAVE_TXIQ1
	ptr = &g_tcmdCalBufData[1];
	calSize = sizeof(TCMD_TXIQ_SAVE2MEM_DATA);
	g_tcmdCalData = (TCMD_CAL_SAVE2MEM_TABLE*)ptr;
	whalRestoreCalPrepare_tcmd(WHAL_CALSAVE_TXIQ1,currChan,chainIdx);

	// Restore second set of cals
	//RXIQ
	ptr = &g_tcmdCalBufData[1] + offset;
	calSize = sizeof(TCMD_RXDCO_SAVE2MEM_DATA);
	g_tcmdCalData = (TCMD_CAL_SAVE2MEM_TABLE*)ptr;
//	whalDoRxDcoCal(FALSE,1)
	whalRestoreCalPrepare_tcmd(WHAL_CALSAVE_RXDCO,currChan,chainIdx);

	//WHAL_CALSAVE_RXIQ1
	offset += calSize/4;
	ptr = &g_tcmdCalBufData[1] + offset;
	calSize = sizeof(TCMD_RXIQ_SAVE2MEM_DATA);
	g_tcmdCalData = (TCMD_CAL_SAVE2MEM_TABLE*)ptr;
	whalRestoreCalPrepare_tcmd(WHAL_CALSAVE_RXIQ1,currChan,chainIdx);

	//WHAL_CALSAVE_TXCL1
	offset += calSize/4;
	ptr = &g_tcmdCalBufData[1] + offset;
	calSize = sizeof(TCMD_TXCL_SAVE2MEM_DATA);
	g_tcmdCalData = (TCMD_CAL_SAVE2MEM_TABLE*)ptr;
	whalRestoreCalPrepare_tcmd(WHAL_CALSAVE_TXCL1,currChan,chainIdx);

	//WHAL_CALSAVE_RXFILT
	offset += calSize/4;
	ptr = &g_tcmdCalBufData[1] + offset;
	calSize = sizeof(TCMD_RXFILT_SAVE2MEM_DATA);
	g_tcmdCalData = (TCMD_CAL_SAVE2MEM_TABLE*)ptr;
	whalRestoreCalPrepare_tcmd(WHAL_CALSAVE_RXFILT,currChan,chainIdx);

	//	PKTDT
//	if  (whalDoPkDetCal() == WHAL_PKDET_CAL_PASS)
//		whalDoPkDetCalSave();
//	else
//		A_PRINTF("Pkdet Cal failed\n");


	//whalPaprdRecal(currChan->mhz);
  // whalNfForceWrite();

	whalPostRestoreCal_tcmd();

	//cal_time_stamp[1] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
	//A_PRINTF_ONCE("tcmd_RestoreFullCalData Reset time = %d\n",cal_time_stamp[1]-cal_time_stamp[0]);

	//DPD

	return status;
}
#endif
A_STATUS tcmd_whalReset(WHAL_CHANNEL *chan)
{
    A_STATUS status = A_OK;
    //A_INT32 cal_time_stamp[4] = {0,0};
    //g_do_full_cal_flag = TRUE;
	//cal_time_stamp[0] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
    if (_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero)
    {
        whalResetRegisterCallback(WHAL_RESET_PRE_CAL_CALLBACK, tcmd_reset_pre_callback);
        whalResetRegisterCallback(WHAL_RESET_POST_CAL_CALLBACK, tcmd_reset_post_callback);
    }
    //cal_time_stamp[1] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);

    #if !defined(FPGA) && defined(QCA9984)
    A_UINT8 idx = 0;
    whalPreRestoreCal_tcmd();

	for(idx=0; idx<4; idx++)
	{
        if((tcmd_txchain_mask>>idx) & 0x1)
		{
          	status |= tcmd_RestoreFullCalData(chan,idx);

		}
	}
    //cal_time_stamp[2] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
	if (status != A_OK || g_do_full_cal_flag == TRUE) { // g_do_full_cal_flag ==TRUE is used for forced hw cal
 		if (whalReset(chan, 0, WHAL_RESTORE_SW_SETTINGS, WHAL_RESET_CAUSE_CHANNEL_CHANGE) == FALSE)
		{
			status = A_ERROR;
		}
		else
		{
			for(idx=0; idx<4; idx++)
			{
				if((tcmd_txchain_mask>>idx) & 0x1)
				{
					status = tcmd_SaveFullCalData(chan,idx);
                    if (status == A_ERROR) A_PRINTF_ONCE("-----CAL Save failed, reCal at  chain %d \n", idx);
				}
			}
		}
	}
    else {
        if (whalReset(chan, 0, WHAL_RESTORE_SW_SETTINGS, WHAL_RESET_CAUSE_CHANNEL_CHANGE) == FALSE)
        {
                status = A_ERROR;
        }
    }
#else
    g_do_full_cal_flag = TRUE;
    if (whalReset(chan, 0, WHAL_RESTORE_SW_SETTINGS, WHAL_RESET_CAUSE_CHANNEL_CHANGE) == FALSE)
    {
        status = A_ERROR;
    }
#endif
	//cal_time_stamp[3] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
/*
    if (g_do_full_cal_flag)
        A_PRINTF_ONCE("do hw cal t10=%d, t20=%d, t30=%d\n",cal_time_stamp[1]-cal_time_stamp[0], cal_time_stamp[2]-cal_time_stamp[0], cal_time_stamp[3]-cal_time_stamp[0]);
    else
        A_PRINTF_ONCE("don't do cal t10=%d, t20=%d, t30=%d\n",cal_time_stamp[1]-cal_time_stamp[0], cal_time_stamp[2]-cal_time_stamp[0], cal_time_stamp[3]-cal_time_stamp[0]);
*/
    if (_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero)
    {
        whalResetRegisterCallback(WHAL_RESET_PRE_CAL_CALLBACK, NULL);
        whalResetRegisterCallback(WHAL_RESET_POST_CAL_CALLBACK, NULL);
    }

    return status;
}


/*
 * Post HTC initialization, HTC calls this registered function.
 */
void
tcmd_enable(void)
{
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
    wlan_tcmd_dev_t *dev = &utf_dev;
#endif

    //TCMD_PRINTF("%s\n", __func__);
    A_MEMZERO(&tcmdRxStat, sizeof(struct tcmd_rx_stat_t));
    A_MEMZERO(&tcmdTxStat, sizeof(struct tcmd_tx_stat_t));

    // add callback, for now
    A_MEMZERO((void*)&(RxCallbackFuncs[0]), sizeof(RxCallbackFuncs));

    tcmd_link_trx_init();

    /*
     * Set the defaults
     * - H/W to awake
     * - TCMD mode to ENABLE
     */
    whalSetPowerMode(WHAL_PM_AWAKE);
    tcmd_state.tcmdMode = TCMD_STATUS_ENABLE;
    tcmd_state.freq = tcmd_default_freq;
    tcmd_state.wlanMode = TCMD_WLAN_MODE_INVALID;
    tcmd_state.chain = TCMD_DEFAULT_CHAINMASK;
    tcmd_state.freq2 = tcmd_default_freq;

    // Setup default src, dst and bssid for RX
    A_MEMCPY(tcmd_state.srcAddr, SA_ADDR, IEEE80211_ADDR_LEN);
    A_MEMCPY(tcmd_state.macAddr, DA_ADDR, IEEE80211_ADDR_LEN);
    A_MEMCPY(tcmd_state.bssid, BSS_ADDR, IEEE80211_ADDR_LEN);

    /* Enter sleep if configured for auto mode */
    tcmd_pm_sleep();

    /* Indicate to host, that we are ready to accept test cmds */
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
    wmi_tcmd_ready_event(dev->wmi, MY_MAC_ADDR);

    // enable legHostIF cmds support
    initLegHostIFCmdsSupport();
#endif
}

#if 0
static A_UINT32 EfuseDumpPos = 0;
static A_INT32 processTScmds( wlan_tcmd_dev_t *dev, TC_CMDS *tCmds, A_UINT16 len)
{
    A_STATUS status;
    //A_PRINTF("processTScmds\n");
    if (TC_CMDS_TS == tCmds->hdr.act) {
#if 0
        A_UINT32 j;
        A_PRINTF("TS(%d) not ready: ", tCmds->hdr.u.parm.version);
        for (j=0;j<tCmds->hdr.u.parm.length;j++) {
            A_PRINTF("%x ", tCmds->buf[j]);
        }
        A_PRINTF("\n");
#endif
        // reference hostIFProcessing in utf.c
        //     if (cmdStreamLen) {
        //         // parse the cmd stream by calling the standard parsingAnd Processing function
        //         cmdStreamParsingAndProcessing(pCmdStream, cmdStreamLen, &pPayload, &payloadLen);
        //                                 }
        //
    }
    else if ((TC_CMDS_TPCCAL == tCmds->hdr.act) || (TC_CMDS_TPCCAL_WITH_OTPWRITE == tCmds->hdr.act))  {
        //A_PRINTF("CAL ...\n");
        // Call calTxPwr logic here

#if 0 // NOT YET: pending NART/UTF passing CAL data mechanism
        // write to OTP
        if (TC_CMDS_TPCCAL_WITH_OTPWRITE== tCmds->hdr.act) {
            // write OTP
        }
#endif

        // Pass thermCAL to host thermCAL
        {
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
        wmi_tc_cmds_reply_event(dev->wmi, sizeof(ValuesOfInterest), tCmds->hdr.act /*tCmds->hdr.u.parm.version*/, (void*)&ValuesOfInterest);
#endif
        }

    }
    else if ( TC_CMDS_OTPDUMP == tCmds->hdr.act) {
        A_STATUS status;
        A_UCHAR     replyBuf[4*(TC_CMDS_SIZE_MAX+1)];
        A_UCHAR     buf[TC_CMDS_SIZE_MAX+1];
        A_UINT32    nbytes=0;
        A_BOOL      doneReadingOTP=FALSE;
        A_UINT32    bufIdx;

        //A_PRINTF("OTP Read ...d\n");
        bufIdx=0;
        otpstream_reset(OTPSTREAM_READ);
        while (!doneReadingOTP) {
            nbytes =0;
            status = otpstream_read((A_UCHAR *)buf, OTPSTREAM_MAXSZ, &nbytes);
            if (A_OK == status) {
                //A_PRINTF("optread ok len %d\n", nbytes);
                A_MEMCPY(&(replyBuf[bufIdx]), buf, nbytes);
                bufIdx += nbytes;
            }
            else {
                //A_PRINTF("end of otp data %d, len %d\n", status, nbytes);
                doneReadingOTP = TRUE;
            }
        }
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
        if (bufIdx) {
            wmi_tc_cmds_reply_event(dev->wmi, bufIdx, tCmds->hdr.act /*tCmds->hdr.u.parm.version*/, (A_INT8 *)replyBuf);
        }
#endif
    }
    else if ( TC_CMDS_EFUSEDUMP == tCmds->hdr.act) {
        A_UCHAR     replyBuf[TC_CMDS_SIZE_MAX+1];
        A_UINT32    bufIdx;
        A_UINT32 length, i, efuse_sz;
        A_UCHAR buf[EFUSE_MAX_NUM_BYTES +1];

        //A_PRINTF("Efuse Read ...d\n");

        bufIdx=0;
        A_MEMZERO(replyBuf, sizeof(replyBuf));
        //efuse_sz = EFUSE_MAX_NUM_BYTES;
        efuse_sz = EfuseDumpPos + TC_CMDS_SIZE_MAX+1;
        if (efuse_sz >= EFUSE_MAX_NUM_BYTES) {
            efuse_sz=TC_CMDS_SIZE_MAX+1;
            EfuseDumpPos = 0;
        }

        //for (i=0; i<efuse_sz; i+=16)
        for (i=EfuseDumpPos; i<efuse_sz; i+=16) {
            length = 16;
            efuse_read(i, buf, length);
            A_MEMCPY(&(replyBuf[bufIdx]), buf, length);
            bufIdx += length;
#if 0
            if (bufIdx == TC_CMDS_SIZE_MAX +1) {
                A_PRINTF("Efuse Read ...%d\n", bufIdx);
                wmi_tc_cmds_reply_event(dev->wmi, bufIdx, tCmds->hdr.u.parm.version, (A_INT8 *)&replyBuf[0]);
                bufIdx = 0;
                A_MEMZERO(replyBuf, sizeof(replyBuf));
            }
#endif
        }
        A_PRINTF("%d B from %d to %d \n",bufIdx, EfuseDumpPos, efuse_sz);
        EfuseDumpPos += efuse_sz;
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
        if (bufIdx) {
            wmi_tc_cmds_reply_event(dev->wmi, bufIdx, tCmds->hdr.act/* tCmds->hdr.u.parm.version*/, (A_INT8 *)&replyBuf[0]);
        }
#endif
    }
    else if (TC_CMDS_EFUSEWRITE == tCmds->hdr.act) {
        A_UCHAR     replyBuf[TC_CMDS_SIZE_MAX+1];
        A_UINT16    pos,len;
        A_UINT32    i;
        A_STATUS    status;
        A_UINT32    nbytes;

        A_MEMCPY(&pos,tCmds->buf,2);
        A_MEMCPY(&len,tCmds->buf+2,2);
        A_PRINTF("efuse write pos %d len %d buf ",pos,len);
        for (i=0;i<len;i++)
        {
            A_PRINTF("0x%x ",tCmds->buf[4+i]);
        }
        A_PRINTF("\n");

        efuse_enable_write();
        status = efuse_write(pos, &tCmds->buf[4], len, &nbytes);
        efuse_disable();
        if (A_OK == status) {
            A_PRINTF("efuse write succeed\n");
            A_MEMCPY(replyBuf, tCmds->buf, len+4);
            wmi_tc_cmds_reply_event(dev->wmi, len+4, tCmds->hdr.act, (A_INT8 *)&replyBuf[0]);
        }
        else {
            A_PRINTF("efuse write failed\n");
            wmi_tc_cmds_reply_event(dev->wmi, 0, tCmds->hdr.act, (A_INT8 *)&replyBuf[0]);
        }
    }
    else if ( TC_CMDS_OTPSTREAMWRITE == tCmds->hdr.act) {
        A_STATUS status;
        //A_PRINTF("OTP write ...\n");
        otpstream_reset(OTPSTREAM_WRITE);
        status = otpstream_write((A_UINT8 *)tCmds->buf, tCmds->hdr.u.parm.length);
        if (A_OK == status) {
            A_PRINTF("otpstream write %d bytes\n", tCmds->hdr.u.parm.length);
        }
        else {
            A_PRINTF("otpstream_write %d bytes failed %d\n", tCmds->hdr.u.parm.length, status);
        }
    }
    else {
        A_PRINTF("shouldnot be here\n");
    }

    return(status);
}
#endif


static A_INT32 tc_cmds_cmd( wlan_tcmd_dev_t *dev,
    TC_CMDS *cmdsBuf,
    A_UINT16 *len,
    A_UINT8  *buf,
    A_UINT8  *version )
{
    TC_CMDS *cmdBuf = (TC_CMDS*)cmdsBuf;
    A_INT32             rc=-1;
    static A_UINT8      rBuffer[TC_CMDS_SIZE_MAX+1];
    static A_UINT32     rBufferIndex=0;

    //A_PRINTF("tc_cmds_cmd\n");
    if (cmdBuf->hdr.u.parm.length != cmdBuf->hdr.u.parm.bufLen) {
        A_MEMCPY(rBuffer+rBufferIndex, cmdBuf->buf, cmdBuf->hdr.u.parm.bufLen);
        rBufferIndex += cmdBuf->hdr.u.parm.bufLen;
        if (rBufferIndex == cmdBuf->hdr.u.parm.length) {
            //buf = (((A_UINT8 *)(dkThread->PipeBuffer_p))+sizeof(dkThread->PipeBuffer_p->cmdLen)) ;
	    //A_MEMCPY(buf, rBuffer, dkThread->PipeBuffer_p->cmdLen);
	    A_MEMCPY(buf, rBuffer, cmdBuf->hdr.u.parm.length);
            rBufferIndex = 0;
            A_MEMZERO(rBuffer, sizeof(rBuffer));
        }
    }
    else {
        //buf = (((A_UINT8 *)(dkThread->PipeBuffer_p))+sizeof(dkThread->PipeBuffer_p->cmdLen)) ;
	//A_MEMCPY(buf, cmdBuf->buf, dkThread->PipeBuffer_p->cmdLen);
	A_MEMCPY(buf, cmdBuf->buf, cmdBuf->hdr.u.parm.length);
    }

    // if the whole cmd is done
    if (!rBufferIndex) {
        //dkThread->PipeBuffer_p->cmdLen = cmdBuf->hdr.u.parm.length;
        *len = cmdBuf->hdr.u.parm.length;
        *version = cmdBuf->hdr.u.parm.version;
        rc=0;  // indicating cmd done

#if 0
        A_UINT32 i;
        A_PRINTF("CMDS:id %d len %d, ver %d, buf ", cmdBuf->hdr.testCmdId, cmdBuf->hdr.u.parm.length, cmdBuf->hdr.u.parm.version);
        for (i=0;i<cmdBuf->hdr.u.parm.length;i++) {
            A_PRINTF("%x", buf[i]);
        }
        A_PRINTF("\n");
#endif
#if 0
        { // echo  for testing, real response tbd
        replyLen=*len;
        if (replyLen > TC_CMDS_SIZE_MAX) replyLen=TC_CMDS_SIZE_MAX;
        A_MEMZERO(replyBuf, sizeof(replyBuf));
        A_MEMCPY(replyBuf, buf, replyLen);

#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
        wmi_tc_cmds_reply_event(dev->wmi, replyLen, cmdBuf->hdr.u.parm.version, replyBuf);
#endif
        }
#endif
    }

    return(rc);
}

void processTLVPacket(A_UINT8 *buf, A_UINT32 length)
{
    A_UINT8 *pPayload = NULL;
    A_UINT16 payloadLen=0;

    hostTlvCmdProcess = TRUE;
    cmdStreamParsingAndProcessing(buf, length, &pPayload, &payloadLen);
/*call the new API
    parseBinCmdStream((A_UINT8*)buf, length, &pPayload, &payloadLen);
    cmdProcessingEntry();
*/
}

/*
 * Parse the received command to determine the test cmd, since
 * all the test commands are pass via single WMI cmd
 */
static void forceTxGain4Bringup(A_UINT16 pcDac)
{
    //A_PRINTF("%s: pcDac %d\n", __func__, pcDac);
    whalForceTxGain(pcDac);
    //whalDoCalibration(TRUE); /* for force gain, we do calibration again after forceGain to avoid carrier leakage */
    //A_PRINTF("%s done: pcDac %d\n", __func__, pcDac);
}

static void forceTxTgtPwr4Bringup(A_UINT16 tgtPwr)
{
    whalForceTxTgtPwr(tgtPwr, tcmd_txchain_mask);
    //whalDoCalibration(TRUE); /* for force gain, we do calibration again after forceGain to avoid carrier leakage */
    //A_PRINTF("%s done: pcDac %d\n", __func__, pcDac);
}

static void forceTxGainIdx4Bringup(A_UINT16 pcDac)
{
    A_UINT8 gainIdx;
    A_INT8  dacGain;
#if defined(AR6320)
    A_UINT8 paConfig;
#endif
    gainIdx = (A_UINT8)(pcDac >> 8);
    dacGain = (A_INT8)(pcDac & 0xff);

#if defined(AR9888)
    whalForceTxGainIdx(gainIdx, dacGain, tcmd_txchain_mask);
#elif defined(AR6320)
    paConfig = gainIdx & 0x07;
    gainIdx  = gainIdx >> 3;
    whalForceTxGainIdx(paConfig, gainIdx, dacGain, tcmd_txchain_mask);
    A_PRINTF("paconfig:%d,gainidx:%d,dacgain:%d\n",paConfig, gainIdx, dacGain);
#endif
    //whalDoCalibration(TRUE); /* for force gain, we do calibration again after forceGain to avoid carrier leakage */
    //A_PRINTF("%s done: pcDac %d\n", __func__, pcDac);
}


static void postSetPwrProcSetTgtPwr(A_UINT16 pcDac)
{
    /*
     * intentionally leave this function blank, just want to get
     * _PostWhalResetSettings.pPostSetPwrProc to be not NULL
     * as in whalSetTxPowerLimitPlus if _PostWhalResetSettings.pPostSetPwrProc is not NULL
     * then target power routine will be used
     */
}

void tcmdReadValuesOfInterest(_VALUES_OF_INTEREST *values)
{
	#if 0
	/*for TT debug purpose with tcmd*/
	A_INT16 temp0, temp1, temp2, temp3;
	whalEepromGetCurrentTempInDec(&temp0, &temp1, &temp2, &temp3);
	A_PRINTF_ALWAYS("temp0=%d, temp1=%d, temp2=%d, temp3=%d\n", temp0, temp1, temp2, temp3);
	#endif
    //values->thermCAL = whalGetCurrentTemp();
}

A_STATUS
tcmd_parse_cmd(wlan_tcmd_dev_t * dev, A_UINT8 * buf, A_UINT32 dataLength)
{
    A_UINT32 testCmdId = *(A_UINT32 *)&(buf[0]);

    switch(testCmdId)
    {
#if 0
        case TCMD_CONT_TX_ID:
            //TCMD_PRINTF("Contx\n");
//#define _WHY_TWICE_
#if defined(_WHY_TWICE_)
            {
            static A_UINT32 firstSineCmd=1;
            if (firstSineCmd && ((((TCMD_CONT_TX *)buf)->mode) == TCMD_CONT_TX_SINE))
            {
                firstSineCmd=0;
                tcmd_cont_tx_cmd(dev, (TCMD_CONT_TX *)buf);
            }
            }
#endif //#if defined(_WHY_TWICE_)
            tcmd_cont_tx_cmd(dev, (TCMD_CONT_TX *)buf);
         break;
        case TCMD_CONT_RX_ID:
            //TCMD_PRINTF("ContRx\n");
            if (tcmd_cont_rx_cmd(dev, (TCMD_CONT_RX *)buf)) {/* if reply is needed then */
                wmi_tcmd_cont_rx_reply_event(dev->wmi,sizeof(TCMD_CONT_RX),buf);
            }

         break;
#endif
        case  TC_CMD_TLV_ID:
            {
                processTLVPacket(buf,dataLength);
            }
            break;
        case  TC_CMDS_ID:
            //TCMD_PRINTF("CMDS mode dev 0x%x\n", dev);
            {
            A_UINT16 cmdLen;
            A_UINT8  cmdBuf[TC_CMDS_SIZE_MAX+1], version;
            TC_CMDS *tCmds = (TC_CMDS *)buf;
            if (!tc_cmds_cmd(dev, (TC_CMDS *)buf, &cmdLen, cmdBuf, &version)) {
                if (TC_CMDS_VERSION_MDK == version) {
                    //A_UINT32 j;
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
#if 0
                    A_PRINTF("MDK CMDS(%d) not tested: ", version);
                    for (j=0;j<cmdLen;j++) {
                        A_PRINTF("%x ", cmdBuf[j]);
                    }
                    A_PRINTF("\n");
#endif
                    tcReadCmds(cmdBuf, cmdLen);
                    htcDispatchCmd(dev);
#endif
                }
                else if (TC_CMDS_VERSION_TS == version ) {
                    if ( TC_CMDS_TLV == tCmds->hdr.act) {
                        processTLVPacket((A_UINT8*)tCmds->buf,tCmds->hdr.u.parm.length);
                    }
#if 0
                    else
                        processTScmds(dev, (TC_CMDS*)&buf[0], cmdLen);
#endif
                }
                else {
                    //A_PRINTF("invalid ver %d\n", version);
                }
            }
            else {
                //A_PRINTF(".cmd not done\n");
            }
            }
            break;
        default:
            //A_PRINTF("Invalid cmd\n");
            return (A_ERROR);
         break;
    }
    return(A_OK);
}

void tcmd_tx_complete_timer_handler(A_HANDLE handler, void *data)
{
    wlan_tcmd_dev_t *dev = (wlan_tcmd_dev_t *) data;

    A_UNTIMEOUT(&tcmd_tx_complete_timer);
    A_DELETE_TIMER(&tcmd_tx_complete_timer);
    tcmd_tx_complete_timeout = 0;
    stop_tx = 2;

    utfTxStop(dev,NULL);
    tcmd_state.tcmdTxGo = TCMD_CONT_TX_OFF;
    tcmd_state.tcmdRxGo = TCMD_CONT_RX_OFF;
    A_MEMZERO(&tcmdTxStat, sizeof(struct tcmd_tx_stat_t));
    tcmdLinkTRx.currentTx++;
    tcmdLinkTx(dev);/* see if there is a need to transmite another rate */
}

/*
 * Callback handler, called for every pkt tx'ed
 */
#if defined(_USE_TX_INT)
A_STATUS
tcmd_tx_complete_handler(void *txt, A_UINT32 total_pkts, A_UINT32 good_pkts, void *hw_status, void *sw_status)
{
    if (tcmd_state.tcmdTxGo == 0)
    {
        //TCMD_PRINTF("tcmd_tx_irq: spurious tx irq \n");
        return A_ERROR;
    }
    whalDisableInterrupts(WHAL_INT_TX);
    //A_PRINTF("total_pkts = %d  good_pkts = %d\n", total_pkts, good_pkts);

    tcmdTxStat.totalPkt++;
    tcmdTxStat.okPkt++;

    tcmdReadValuesOfInterest((_VALUES_OF_INTEREST *)&ValuesOfInterest);

    // callback registered func
    runTxCallback((void*)&tcmdTxStat);
    processTxDataStats(g_encap_cfg.pkt_len, total_pkts, good_pkts, hw_status, sw_status);
    if (stop_tx)
    {
        stop_tx = 2;
        whalEnableInterrupts(WHAL_INT_TX);
        return  0;
    }
    else if (tcmd_state.numTxPkts)
    {
        if (tcmdTxStat.totalPkt >= tcmd_state.numTxPkts)
        {
            if (!tcmd_state.disContTx && !tcmd_tx_complete_timeout)
            {
            #if defined(FPGA)
			tcmd_tx_complete_timeout = 10; // msec
			#else
                    tcmd_tx_complete_timeout = 0;//1000; // msec
			#endif
                A_INIT_TIMER(&tcmd_tx_complete_timer, tcmd_tx_complete_timer_handler, (void *) txt);
                A_TIMEOUT_MS(&tcmd_tx_complete_timer, tcmd_tx_complete_timeout, 0);
            }
            else
               stop_tx = 2;
	    whalEnableInterrupts(WHAL_INT_TX);
            return 0;
        }
    }
    whalEnableInterrupts(WHAL_INT_TX);
    return 1;
}
#endif // #if defined(_USE_TX_INT)

#if defined(_USE_RX_INT)
/*
 * Callback handler, called for every pkt received from the air.
 */
A_STATUS
tcmd_rx_complete_handler(void *ctxt, A_UINT32 data_len, A_UINT32 rate_index,
                         A_UCHAR rsStatus, struct wal_rx_status *mpdu_status)
{
    struct rx_attention *attention = &mpdu_status->rx_desc.attention;
    struct rx_ppdu_start *ppdu_start = &mpdu_status->rx_desc.ppdu_start;
    static A_UINT32 aggRateCnt = 0;

    if (tcmd_state.tcmdRxGo == 0)
    {
        //TCMD_PRINTF("tcmd_rx_irq: spurious rx irq \n");
        return A_ERROR;
    }

    if (rate_index >= TCMD_MAX_RATES)
        return A_OK;

    processRxDataStats(rate_index, data_len, rsStatus, mpdu_status);

    tcmdRxStat.totalPkt++;
    if (rsStatus & WHAL_RXERR_CRC)
    {
        //TCMD_PRINTF("tcmd_rx_irq: CRCErr \n");
        tcmdRxStat.crcErrPkt++;
        return A_OK;
    }
    else if (rsStatus & WHAL_RXERR_PHY)
    {
        //TCMD_PRINTF("tcmd_rx_irq: PhyErr \n");
        tcmdRxStat.phyErrPkt ++;
        return A_OK;
    }
    else if (rsStatus)
    {
//#if !defined(QCA9984)    // this is not PHY related issue. Need to address later.
        //TCMD_PRINTF("tcmd_rx_irq: SecErr \n");
        tcmdRxStat.secErrPkt ++;
        return A_OK;
//#endif
    }

    tcmdRxStat.okPkt++;
    if (!(attention->first_mpdu && attention->last_mpdu))
    {
        /* if this is an aggregated packet then we will need to check if this is the last sub-frame first,
         * as only the last sub-frame has the complete status
         */

        if (!attention->last_mpdu)
        {
            /* if this is not the last frame then increment this internal counter but do not update the rate report */
            aggRateCnt++;
            return A_OK; /* return from here as rIdx and rssi are invalid for sub-frame */
        }
        else
        {
            /* if this is the last sub-frame then all the prior sub-frame counters will be accumulated into the rate report */
            tcmdRxStat.rateCnt[rate_index] += aggRateCnt;
            tcmdRxStat.rssiInDBm += ppdu_start->rssi_comb * aggRateCnt;

            tcmdRxStat.rssic[0] += ppdu_start->rssi_pri_chain0 * aggRateCnt;
            tcmdRxStat.rssic[1] += ppdu_start->rssi_pri_chain1 * aggRateCnt;
            tcmdRxStat.rssic[2] += ppdu_start->rssi_pri_chain2 * aggRateCnt;
            tcmdRxStat.rssic[3] += ppdu_start->rssi_pri_chain3 * aggRateCnt;
            aggRateCnt = 0;
        }
    }

    tcmdRxStat.rateCnt[rate_index]++;
#if 0 //Allan
#ifdef SUPPORT_11N
    if (ds->dsRxStat.rsRate.flags & WHAL_RC_FLAG_SGI)
        tcmdRxStat.rateCntShortGuard[rate_index]++;
#endif
#endif
    tcmdRxStat.rssiInDBm += ppdu_start->rssi_comb;

    tcmdRxStat.rssic[0] += ppdu_start->rssi_pri_chain0;
    tcmdRxStat.rssic[1] += ppdu_start->rssi_pri_chain1;
    tcmdRxStat.rssic[2] += ppdu_start->rssi_pri_chain2;
    tcmdRxStat.rssic[3] += ppdu_start->rssi_pri_chain3;

#if 0
    TCMD_PRINTF("rx pkt: %d, ok pkt: %d, rssiInDBm %d \n", tcmdRxStat.totalPkt, tcmdRxStat.okPkt, tcmdRxStat.rssiInDBm);
#endif

    // execute registered callbacks, notebly OTA
    runThroughCallback((void*)&tcmdRxStat);
    return A_OK;
}
#endif // #if defined(_USE_RX_INT)

/*
 * Local function definitions
 */


/* Set to default value if host not specify it */
void
tcmd_cont_tx_set_default(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx)
{

    if(contTx->freq == 0 ){
        contTx->freq = tcmd_default_freq;
        contTx->freq2 = tcmd_default_freq;
    }
    if(contTx->pktSz == 0){
        contTx->pktSz = TCMD_DEFAULT_TXPKTSZ;
    }
}

void
tcmd_get_channel(A_UINT32 freq, A_UINT32 wlanMode, A_UINT32 bandwidth, WHAL_CHANNEL *chan, A_UINT32 freq2)
{
    chan->band_center_freq1 = freq; /* another offset */
    chan->band_center_freq2 = freq2;
    chan->max_reg_power = TCMD_MAX_RDPWR;  /*copy from haldemo.c chanArray.*/
#ifdef SUPPORT_11N
    chan->flags = 0;
#endif

    chan->mhz = chan->band_center_freq1;
#ifdef SUPPORT_11N
    /* Let's set phy_mode based on 5G first, change it later if it's for 2G to simplify the coding. */
    chan->phy_mode = MODE_UNKNOWN;
    switch (wlanMode)
    {
        case TCMD_WLAN_MODE_NOHT:
            chan->phy_mode = MODE_11A;
            break;

        case TCMD_WLAN_MODE_HT20:
            chan->phy_mode = MODE_11NA_HT20;
            break;

        case TCMD_WLAN_MODE_HT40PLUS:
            chan->phy_mode = MODE_11NA_HT40;
            chan->mhz -= WHAL_HT40_CHANNEL_CENTER_SHIFT;
            break;

        case TCMD_WLAN_MODE_HT40MINUS:
            chan->phy_mode = MODE_11NA_HT40;
            chan->mhz += WHAL_HT40_CHANNEL_CENTER_SHIFT;
            break;

#ifdef SUPPORT_VHT
        case TCMD_WLAN_MODE_VHT20:
            chan->phy_mode = MODE_11NA_HT20;
            break;

        case TCMD_WLAN_MODE_VHT40PLUS:
            chan->phy_mode = MODE_11NA_HT40;
            chan->mhz -= WHAL_HT40_CHANNEL_CENTER_SHIFT;
            break;

        case TCMD_WLAN_MODE_VHT40MINUS:
            chan->phy_mode = MODE_11NA_HT40;
            chan->mhz += WHAL_HT40_CHANNEL_CENTER_SHIFT;
            break;

        case TCMD_WLAN_MODE_VHT80_0:
            chan->phy_mode = MODE_11AC_VHT80;
            chan->mhz = chan->mhz - WHAL_HT40_CHANNEL_CENTER_SHIFT - 20;
            break;

        case TCMD_WLAN_MODE_VHT80_1:
            chan->phy_mode = MODE_11AC_VHT80;
            chan->mhz -= WHAL_HT40_CHANNEL_CENTER_SHIFT;
            break;

        case TCMD_WLAN_MODE_VHT80_2:
            chan->phy_mode = MODE_11AC_VHT80;
            chan->mhz += WHAL_HT40_CHANNEL_CENTER_SHIFT;
            break;

        case TCMD_WLAN_MODE_VHT80_3:
            chan->phy_mode = MODE_11AC_VHT80;
            chan->mhz = chan->mhz + WHAL_HT40_CHANNEL_CENTER_SHIFT + 20;
            break;

        case TCMD_WLAN_MODE_VHT80P80:
	        chan->phy_mode = MODE_11AC_VHT80_80;
            chan->mhz -= WHAL_HT40_CHANNEL_CENTER_SHIFT;
	        break;

        case TCMD_WLAN_MODE_VHT160:
            chan->phy_mode = MODE_11AC_VHT160;
            chan->mhz -= WHAL_HT40_CHANNEL_CENTER_SHIFT;
            chan->band_center_freq2 = chan->band_center_freq1 + WHAL_VHT160_CHANNEL_CENTER_SHIFT;
            chan->band_center_freq1 -= WHAL_VHT160_CHANNEL_CENTER_SHIFT;
            break;

        case TCMD_WLAN_MODE_VHT80P80_0:
        case TCMD_WLAN_MODE_VHT80P80_1:
        case TCMD_WLAN_MODE_VHT80P80_2:
        case TCMD_WLAN_MODE_VHT80P80_3:
        case TCMD_WLAN_MODE_VHT80P80_4:
        case TCMD_WLAN_MODE_VHT80P80_5:
        case TCMD_WLAN_MODE_VHT80P80_6:
        case TCMD_WLAN_MODE_VHT80P80_7:
            chan->phy_mode = MODE_11AC_VHT80_80;
            chan->mhz += (wlanMode - TCMD_WLAN_MODE_VHT80P80_7 + 4)*20 - WHAL_HT40_CHANNEL_CENTER_SHIFT + WHAL_VHT160_CHANNEL_CENTER_SHIFT;
            if (chan->band_center_freq1 > chan->band_center_freq2)
            {
               chan->mhz -= 2*WHAL_VHT160_CHANNEL_CENTER_SHIFT;
            }
            break;

        case TCMD_WLAN_MODE_VHT160_0:
        case TCMD_WLAN_MODE_VHT160_1:
        case TCMD_WLAN_MODE_VHT160_2:
        case TCMD_WLAN_MODE_VHT160_3:
        case TCMD_WLAN_MODE_VHT160_4:
        case TCMD_WLAN_MODE_VHT160_5:
        case TCMD_WLAN_MODE_VHT160_6:
        case TCMD_WLAN_MODE_VHT160_7:
            chan->phy_mode = MODE_11AC_VHT160;
            chan->band_center_freq2 = chan->band_center_freq1 + WHAL_VHT160_CHANNEL_CENTER_SHIFT;
            chan->band_center_freq1 -= WHAL_VHT160_CHANNEL_CENTER_SHIFT;
            chan->mhz = chan->band_center_freq1 + (wlanMode - TCMD_WLAN_MODE_VHT160_7 + 4)*20 - WHAL_HT40_CHANNEL_CENTER_SHIFT + WHAL_VHT160_CHANNEL_CENTER_SHIFT;
            break;

        default:
            A_PRINTF_ALWAYS("wlanMode1? %d\n", wlanMode);
            break;
#endif
    }

    A_PRINTF_ALWAYS("get_ch wlanMode: %d pri: %d f1: %d f2 %d\n", wlanMode, chan->mhz, chan->band_center_freq1, chan->band_center_freq2);

#else
    chan->phy_mode = MODE_11A;
#endif

    if (freq == BG_FREQ_MAX ||
        ((freq < BG_FREQ_MAX) && (freq >= BG_FREQ_MIN) && !((freq - BG_FREQ_MIN) % 5)))
    {
#ifdef SUPPORT_11N
        chan->phy_mode = MODE_UNKNOWN;
        switch (wlanMode)
        {
            case TCMD_WLAN_MODE_NOHT:
                chan->phy_mode = MODE_11G;
                break;

            case TCMD_WLAN_MODE_HT20:
                chan->phy_mode = MODE_11NG_HT20;
                break;

            case TCMD_WLAN_MODE_HT40PLUS:
            case TCMD_WLAN_MODE_HT40MINUS:
                chan->phy_mode = MODE_11NG_HT40;
                break;

            case TCMD_WLAN_MODE_CCK:
                chan->phy_mode = MODE_11B;
                break;

#ifdef SUPPORT_VHT
            case TCMD_WLAN_MODE_VHT20:
                chan->phy_mode = MODE_11AC_VHT20_2G;
                break;

            case TCMD_WLAN_MODE_VHT40PLUS:
            case TCMD_WLAN_MODE_VHT40MINUS:
                chan->phy_mode = MODE_11AC_VHT40_2G;
                break;

            case TCMD_WLAN_MODE_VHT80_0:
            case TCMD_WLAN_MODE_VHT80_1:
            case TCMD_WLAN_MODE_VHT80_2:
            case TCMD_WLAN_MODE_VHT80_3:
                chan->phy_mode = MODE_11AC_VHT80_2G;
                break;
            default:
                A_PRINTF_ALWAYS("wlanMode? %d\n", wlanMode);
                break;
#endif
        }
#else
        chan->phy_mode = MODE_11G;
#endif
#if defined(AR900B) || defined(QCA9984)
#if defined(FPGA)
///TODO: Added work-around for testing in FPGA
        if ((wlanMode != TCMD_WLAN_MODE_VHT160) && (wlanMode != TCMD_WLAN_MODE_VHT80P80)) {
        chan->phy_mode = MODE_11NG_HT20;
        } else {
			chan->phy_mode = MODE_11AC_VHT160;
			chan->mhz += WHAL_HT40_CHANNEL_CENTER_SHIFT;
        }
#endif
#endif
    }
    else if ((freq >= A_FREQ_MIN) && (freq <= A_FREQ_MAX) && !((freq - A_FREQ_MIN) % 5)) /* from 4920 to 5825*/
    {
        /* enable half/quarter rate for 5G only */
        if (HALF_SPEED_MODE == bandwidth) {
            chan->flags = WHAL_CHANNEL_HALF_RATE;
        }
        else if (QUARTER_SPEED_MODE == bandwidth) {
            chan->flags = WHAL_CHANNEL_QUARTER_RATE;
        }
    }
    else if ((freq >= A_FREQ_MIN_11P) && (freq <= A_FREQ_MAX_11P))
    {
        /* enable half rate for 11P for only 20MHz mode */
        if (wlanMode == TCMD_WLAN_MODE_NOHT || wlanMode == TCMD_WLAN_MODE_HT20 || wlanMode == TCMD_WLAN_MODE_VHT20) {

            if (HALF_SPEED_MODE == bandwidth){
                chan->flags = WHAL_CHANNEL_HALF_RATE;
            } else if (QUARTER_SPEED_MODE == bandwidth){
                chan->flags = WHAL_CHANNEL_QUARTER_RATE;
            }
        }
    }
    else if ((freq >= 4942) && (freq <= 4987) && !((freq - 4942) % 5) && (QUARTER_SPEED_MODE == bandwidth)) // 5 Mhz
    {
        chan->flags = WHAL_CHANNEL_QUARTER_RATE;
    }
    else if ((freq == HALF_RATE_4P9G_MIN) && (HALF_SPEED_MODE == bandwidth)) /* So far channel 183(4915) is only for half rate */
    {
        chan->flags = WHAL_CHANNEL_HALF_RATE;
    }
    else
    {
        A_PRINTF_ALWAYS("Invalid frequency %d.\n", freq);
        chan->phy_mode = MODE_UNKNOWN;
    }



   return;
}

WLAN_PHY_MODE
tcmd_get_curmode()
{
    return curWlanMode;
}

static void
tcmd_set_curmode(WLAN_PHY_MODE mode)
{
    curWlanMode = mode;
    //A_PRINTF("..curMode %d\n", curWlanMode);
    return;
}

static void
tcmd_set_deepsleep_mode(A_BOOL enable)
{
    if (tcmd_state.deepSleepEn == enable) {
        return;
    }

    if (enable) {
        /* Power down MAC during deep sleep */
        whalPwrOnOffMAC(enable);
        whalSetPowerMode(WHAL_PM_FULL_SLEEP);
    } else {
        whalSetPowerMode(WHAL_PM_AWAKE);
        whalPwrOnOffMAC(enable);
        tcmd_whalReset(NULL);
    }

    tcmd_state.deepSleepEn = enable;

    return;
}

void tcmd_pm_awake()
{
    if (tcmd_state.tcmdMode == TCMD_STATUS_DEEPSLEEP)
    {
        //TCMD_PRINTF("exit deepsleep \n");
        tcmd_set_deepsleep_mode(FALSE);
    }
    else if (tcmd_state.tcmdMode == TCMD_STATUS_SLEEP)
    {
        //TCMD_PRINTF("exit sleep \n");
        whalSetPowerMode(WHAL_PM_AWAKE);
    }
    else if (auto_deep_sleep_mode)
    {
        //TCMD_PRINTF("exit auto deepsleep \n");
        tcmd_set_deepsleep_mode(FALSE);
    }

    return;
}

static void
tcmd_pm_sleep()
{
    if (tcmd_state.tcmdMode == TCMD_STATUS_DEEPSLEEP) {
        //TCMD_PRINTF("enter deepsleep \n");
        tcmd_set_deepsleep_mode(TRUE);
    } else if (tcmd_state.tcmdMode == TCMD_STATUS_SLEEP) {
        //TCMD_PRINTF("enter sleep \n");
        whalSetPowerMode(WHAL_PM_FULL_SLEEP);
    } else if (auto_deep_sleep_mode) {
        //TCMD_PRINTF("enter auto deepsleep \n");
        tcmd_set_deepsleep_mode(TRUE);
    }

    return;
}

//
// Frame mode with finite packekt
//
void utfTxStop(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx)
{
#if 0
    static int loop=1;
extern void qc900bTestFns(void);
    if ((loop++%3)) {
        qc900bTestFns();
        return;
    }
#endif

    if (tcmd_state.tcmdTxGo)
    {
        if (tcmd_state.tcmdTxGo == TCMD_CONT_TX_SINE)
            tcmd_cont_sine_tx_stop(dev);
        else
            tcmd_cont_data_tx_stop(dev);
        tcmd_state.tcmdTxGo = TCMD_CONT_TX_OFF;
        tcmd_pm_sleep();
    }
    else
    {
        //A_PRINTF("%s state %d mismatch\n", __func__, tcmd_state.tcmdTxGo);
    }

    return;
}
#define UTF_TX_DEFAULT_NUM_PACKETS 100
static void utfTxSetupDefault(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx)
{
    if(contTx->freq == 0 ) {
        contTx->freq = tcmd_default_freq;
    }
    if(contTx->pktSz == 0){
        contTx->pktSz = TCMD_DEFAULT_TXPKTSZ;
    }
//    contTx->mode = TCMD_CONT_TX_FRAME;
#if 0  // tbd??
    if (!contTx->numPackets) {
        contTx->numPackets = UTF_TX_DEFAULT_NUM_PACKETS;
    }
#endif
#ifndef SUPPORT_11N
    contTx->shortGuard = 0;
#endif
    return;
}

void utfTxChannelSetup(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx)
{
    tcmd_pm_awake();
    // force defaults
    utfTxSetupDefault(dev, contTx);

#if 0
    A_PRINTF("%s: id%d txM%d ch%d rt%d pwr%d ant%d ani%d scr%d aif%d pkS%d txPt%d sg%d nPks%d wiM%d\n",
                __func__,contTx->testCmdId, contTx->mode, contTx->freq, contTx->dataRate,  contTx->txPwr,
                contTx->antenna, contTx->enANI, contTx->scramblerOff,
                contTx->aifsn, contTx->pktSz, contTx->txPattern, contTx->shortGuard,
                contTx->numPackets, contTx->wlanMode);
#endif

#if 0 // Allan
    if(contTx->enANI) {
       whalEnableAni(TRUE);
    }else {
       whalEnableAni(FALSE);
    }
#endif

    // set MAC addr, so no need to do MAC again and reset
    whalSetMacAddress(rxFilterMAC);
#if 0
    A_PRINTF("setmac: 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
        rxFilterMAC[0], rxFilterMAC[1], rxFilterMAC[2], rxFilterMAC[3], rxFilterMAC[4], rxFilterMAC[5]);
#endif
     //if (A_OK != tcmd_setup_channel_real(dev, contTx->freq, contTx->wlanMode, TRUE))
    if (A_OK != tcmd_setup_channel(dev, TRUE, contTx->freq, contTx->wlanMode, contTx->bandwidth, contTx->freq2, contTx->txChain))
        return;

    whalSetupAntenna(contTx->antenna);
    whalSetTxPowerLimit((A_UINT16)contTx->txPwr, 0);
    whalSetTxPowerLimit((A_UINT16)contTx->txPwr, 1);

    if (contTx->scramblerOff) {
        whalDisableScramble(TRUE);
    } else {
        whalDisableScramble(FALSE);
    }

//    tcmd_state.tcmdTxGo = TCMD_CONT_TX_FRAME;

    //A_PRINTF("-utfTxChannelSetup\n");
    return;
}

void
setRxDeaf(A_UINT32 dataRate)
{


    OS_REG_RMW_FIELD(PHY_BB_CCA_B0_ADDRESS,PHY_BB_CCA_B0_THR_CCA,0x7f);
    OS_REG_RMW_FIELD(PHY_BB_EXT_CHAN_PWR_THR_1_ADDRESS,PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40,0x7f);
    OS_REG_RMW_FIELD(PHY_BB_TEST_CONTROLS_ADDRESS,PHY_BB_TEST_CONTROLS_FORCE_AGC_CLEAR,1);
    OS_REG_RMW_FIELD(PHY_BB_TIMING_CONTROL_5_ADDRESS,PHY_BB_TIMING_CONTROL_5_CYCPWR_THR1,0x7f);
    OS_REG_RMW_FIELD(PHY_BB_TIMING_CONTROL_5_ADDRESS,PHY_BB_TIMING_CONTROL_5_RSSI_THR1A,0x7f);

    OS_REG_RMW_FIELD(PHY_BB_TIMING_CONTROL_6_ADDRESS,PHY_BB_TIMING_CONTROL_6_OFDM_XCORR_THRESH,0x3f);
    OS_REG_RMW_FIELD(PHY_BB_TIMING_CONTROL_6_ADDRESS,PHY_BB_TIMING_CONTROL_6_OFDM_XCORR_THRESH_HI_RSSI,0x3f);
    OS_REG_RMW_FIELD(PHY_BB_SELF_CORR_LOW_ADDRESS,PHY_BB_SELF_CORR_LOW_USE_SELF_CORR_LOW,0x0);
    OS_REG_RMW_FIELD(PHY_BB_FIND_SIGNAL_ADDRESS,PHY_BB_FIND_SIGNAL_FIRSTEP,0x3f);
    OS_REG_RMW_FIELD(PHY_BB_FIND_SIGNAL_ADDRESS,PHY_BB_FIND_SIGNAL_RELSTEP,0x3f);
    OS_REG_RMW_FIELD(PHY_BB_FIND_SIGNAL2_ADDRESS,PHY_BB_FIND_SIGNAL2_RELPWR,0x7E);

}

static void utfTxStartInternal(wlan_tcmd_dev_t *dev, TCMD_CONT_TX * contTx , A_UINT32 aifswait, A_BOOL disableContinuousTx,  A_UINT32 numPkts);

void utfTxStart(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx)
{
//#define  _WHY_TWICE_SINGLE_TONE
#if defined(_WHY_TWICE_SINGLE_TONE)
    {
    static A_UINT32 firstSineCmd=1;
    if (firstSineCmd && (contTx->mode) == TCMD_CONT_TX_SINE)
    {
        firstSineCmd=0;
        tcmd_cont_tx_cmd(dev, (TCMD_CONT_TX *)contTx);
    }
    }
#endif ///#if defined(_WHY_TWICE_SINGLE_TONE)

    tcmd_cont_tx_cmd(dev, (TCMD_CONT_TX *)contTx);
}

A_UINT32 getTx99PktSz(A_UINT32 rateIdx)
{
	A_UINT32 retSize;
	if (rateIdx <= 11) // CCK and Legacy
		retSize = 1500;
	else if (rateIdx <= 59){ // 11n rates
		if ((rateIdx-12) % 8 == 0) // MCS0
			retSize = 4000;
		else if ((rateIdx-12) % 8 == 1) // MCS1
			retSize = 8000;
		else if ((rateIdx-12) % 8 == 2) // MCS2
			retSize = 10000;
		else
			retSize = 16000;
	}
	else if (rateIdx <= 149){ // 11ac rates
		if (rateIdx % 10 == 0) // MCS0
			retSize = 4000;
		else if (rateIdx % 10 == 1) // MCS1
			retSize = 8000;
		else if (rateIdx % 10 == 2) // MCS2
			retSize = 10000;
		else
			retSize = 16000;
	}
	else if (rateIdx <= 152){ // CCK extended
		retSize = 1500;
	}
	else // All 4SS rates
		retSize = 16000;

	return retSize;
}

A_BOOL isCckRate(A_UINT32 dataRate)
{
    if ( (dataRate == ATH_RATE_1M) ||
         (dataRate == ATH_RATE_2M) ||
         (dataRate == ATH_RATE_5_5M) ||
         (dataRate == ATH_RATE_11M))
    {
        return TRUE;
    }

    return FALSE;
}

extern struct frame_enacap_config g_encap_cfg;
void waltestDpdSetup(wlan_tcmd_dev_t *dev)
{
    g_encap_cfg.sa_addr = SA_ADDR;
    g_encap_cfg.da_addr = SA_ADDR;
    g_encap_cfg.bss_addr = SA_ADDR;

    waltest_tx(dev->pdev, dev, NULL, NULL);

}


extern void ar6000SingleCarrierRestore();
#if defined(QCA9984)
extern void update_bdf_commonparams_from_ebdf (WHAL_CHANNEL *chan);
#endif

void tcmd_cont_tx_cmd(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx)
{
    A_UINT16 adjustedTwiceTxPwr = TCMD_MAX_RATE_POWER;
    A_BOOL waitForTxComplete = TRUE;
    gDPDCalDone = FALSE;
    gForceTxPwrMode = FALSE;
    gDeafMode       = FALSE;

    if (contTx == NULL)
    {
        TCMD_PRINTF("contx is null\n" );
        return;
    }

#if defined(QCA9984)
    WHAL_CHANNEL chan;
    tcmd_get_channel(contTx->freq,contTx->wlanMode, contTx->bandwidth, &chan, contTx->freq2);

    update_bdf_commonparams_from_ebdf (&chan);
#endif
    
    // Disable fast channel for tx99 and txframe
    if (contTx->mode == TCMD_CONT_TX_TX99 || contTx->mode == TCMD_CONT_TX_FRAME)
    	gEnableFastChannelChange = FALSE;

    //Disable DPD enable on all chains
    whalPaprdHwDisable();

#if 0
    A_PRINTF("%s: id%d txM%d ch%d rt%d\n", __func__,
                contTx->testCmdId, contTx->mode, contTx->freq, contTx->dataRate);

    A_PRINTF("aif%d pkS%d txPt%d sg%d nPks%d\n",
                contTx->aifsn, contTx->pktSz, contTx->txPattern, contTx->shortGuard,
                contTx->numPackets);

    A_PRINTF("wiM%d bc%d txPwr%d\n",contTx->wlanMode,contTx->broadcast,contTx->txPwr);
#endif

    if (contTx->miscFlags & TCMD_GO_MASK)
    {
    	if (tcmd_state.tcmdTxGo == TCMD_CONT_TX_OFF)
    	{
    		return;
    	}
    	else
    	{
    		goto tcmd_cont_tx_cmd_label1;
    	}
    }

    if (contTx->mode >> 8)/* using bit 8 to indicate if the tx should wait for the tx to complete, 1=do not wait, 0=wait */
        waitForTxComplete = FALSE;
    contTx->mode &= 0xff;

    if (contTx->mode == TCMD_CONT_TX_OFF)
    {
        //A_PRINTF("%s: contTx_off\n", __func__);
        utfTxStop(dev, contTx);
        tcmd_state.tcmdTxGo = TCMD_CONT_TX_OFF;
        tcmd_state.tcmdRxGo = TCMD_CONT_RX_OFF;
        A_MEMZERO(&tcmdTxStat, sizeof(struct tcmd_tx_stat_t));
        return;
    }

    if (!(contTx->miscFlags & TCMD_GO_MASK) && tcmd_state.tcmdTxGo)
    {
        //A_PRINTF("%s: contTx_off GO\n", __func__);
        utfTxStop(dev, contTx);
        tcmd_state.tcmdTxGo = TCMD_CONT_TX_OFF;
        tcmd_state.tcmdRxGo = TCMD_CONT_RX_OFF;
        A_MEMZERO(&tcmdTxStat, sizeof(struct tcmd_tx_stat_t));
    }

    /*Enable/disable DPD cal based on FTM cmd*/
    if ((contTx->miscFlags & PAPRD_ENA_MASK) && (!isCckRate(contTx->dataRate)))
    {
        // if BDF doesn't support DPD, tool can't enable DPD.
        if (isDPDEnableInBDF()) {
            whalPaprdEnableCal(TRUE);

            if (contTx->tpcm == TPC_FORCED_GAINIDX) {
                whalPaprdForceTxPaDacGain(contTx->gainIdx, contTx->txChain, contTx->dacGain, contTx->paConfig);
            }

        } else {
            whalPaprdEnableCal(FALSE);
        }
    }
    else
    {
        whalPaprdEnableCal(FALSE);
    }

    // Get max packet length for Tx99
#if !defined(FPGA)
    if (contTx->mode == TCMD_CONT_TX_TX99)
    {
    	contTx->pktSz = getTx99PktSz(contTx->dataRate);
    	contTx->agg = 63;
    }
#endif

    if (contTx->mode == TCMD_CONT_TX_SINE || contTx->mode == TCMD_CONT_TX_CWTONE)
    {
        g_xtal_cal_flag = TRUE;
        whalEnableAni(FALSE);
    }
    else
    {
        g_xtal_cal_flag = FALSE;
        whalEnableAni(TRUE);
    }

#ifndef SUPPORT_11N
    contTx->shortGuard = 0;
#endif

    // forced gain Index needs to be per chain...
    tcmd_txchain_mask = contTx->txChain;

    // forced gain
    if (contTx->tpcm == TPC_FORCED_GAIN)         { _PostWhalResetSettings.pPostSetPwrProc = forceTxGain4Bringup; }
    else if (contTx->tpcm == TPC_FORCED_GAINIDX) { _PostWhalResetSettings.pPostSetPwrProc = forceTxGainIdx4Bringup; }
    else if (contTx->tpcm == TPC_FORCED_TGTPWR)  { _PostWhalResetSettings.pPostSetPwrProc = forceTxTgtPwr4Bringup; }
    else if (contTx->tpcm == TPC_TGT_PWR)        { _PostWhalResetSettings.pPostSetPwrProc = postSetPwrProcSetTgtPwr; }
    else                                         { _PostWhalResetSettings.pPostSetPwrProc = NULL; }

    if (TCMD_CONT_TX_SINE == contTx->mode)
    {
        contTx->dataRate = 0;
    }

    tcmd_pm_awake();
    tcmd_cont_tx_set_default(dev, contTx);

    g_encap_cfg.chain_mask = contTx->txChain;
	waltestDpdSetup(dev);

    wal_rc_set_hw_chainmasks(dev->pdev, contTx->txChain, contTx->txChain);

    //if (A_OK != k_real(dev, contTx->freq, contTx->wlanMode, contTx->bandwidth, TRUE)) {/* reset device no matter what */
#if defined(CONFIG_BB)
    if (A_OK != tcmd_setup_channel(dev, TRUE, contTx->freq, contTx->wlanMode, contTx->bandwidth, contTx->freq2, contTx->txChain))
    {
	A_PRINTF_ALWAYS("%s: setup chan failed\n", __func__);
	return;
    }

#endif

    if (contTx->tpcm == TPC_TX_PWR)
    	gForceTxPwrMode = TRUE;

    if (contTx->mode == TCMD_CONT_TX_TX99)
      gDeafMode = TRUE;


    whalSetupAntenna(contTx->antenna);
    //adjustedTwiceTxPwr = (A_UINT32)contTx->txPwr * 2;
    adjustedTwiceTxPwr = (A_UINT16)contTx->txPwr;
    if (contTx->tpcm == TPC_FORCED_GAINIDX) {
        A_UINT16 gainIdxDacGain=0;
#if defined(AR9888)
        gainIdxDacGain = ((contTx->gainIdx) << 8) | ((A_UINT8) contTx->dacGain);
#else
        gainIdxDacGain = ((contTx->gainIdx) << 11) | ((contTx->paConfig & 0x7) << 8) | ((A_UINT8) contTx->dacGain);
#endif
        // to fit the registered call prototype
        adjustedTwiceTxPwr = gainIdxDacGain;
    }
#if defined(AR900B) || defined(QCA9984) || defined(QCA9618) || defined(IPQ4019) || defined(QCA9888)
    if (contTx->tpcm == TPC_FORCED_GLUTIDX) {
        adjustedTwiceTxPwr = 0;
        A_UINT16 gainIdx,paConfig,chain;
        chain = getChain(tcmd_txchain_mask);
        whalPaprdReadGlut(chain, contTx->gainIdx, &gainIdx, &paConfig);

        contTx->gainIdx  = gainIdx;
        contTx->paConfig = paConfig;
        contTx->dacGain  = -8;
        adjustedTwiceTxPwr = ((contTx->gainIdx) << 11) | ((contTx->paConfig & 0x7) << 8) | ((A_UINT8) contTx->dacGain);
        //A_PRINTF_ALWAYS_1("GLUT gain Idx %d dac gain %d paconfig %d adjustedTwiceTxPwr %d\n",contTx->gainIdx,contTx->dacGain,contTx->paConfig,adjustedTwiceTxPwr);
    }
#endif

    //FJC add.  If forcing gain, then don't call this?
#if defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
    if ((contTx->tpcm == TPC_FORCED_GAINIDX || contTx->tpcm == TPC_FORCED_GLUTIDX) && contTx->mode != TCMD_CONT_TX_SINE){
		contTx->mode = TCMD_CONT_TX_CLPCPKT;
    } else {
    	//FJC this was always being called before
        adjustedTwiceTxPwr = whalSetTxPowerLimitPlus(adjustedTwiceTxPwr);
    }

 /*   if ((TPC_FORCED_TGTPWR == contTx->tpcm) || (TPC_TGT_PWR == contTx->tpcm)) {
        adjustedTwiceTxPwr = whalSetTxPowerLimitPlus(adjustedTwiceTxPwr);
    } else if (contTx->tpcm == TPC_FORCED_GAINIDX) {
        //FJC add - try to force it down James path
        if (TCMD_CONT_TX_TX99 == contTx->mode) {
    		contTx->mode = TCMD_CONT_TX_CLPCPKT;
    	}
    }
*/
#else
    adjustedTwiceTxPwr = whalSetTxPowerLimitPlus(adjustedTwiceTxPwr);
#endif
    /////whalPaprdConfig(TRUE, contTx->freq, (WHAL_PAPRD_CONFIG_WAIT_FOR_COMPLETION | WHAL_PAPRD_CONFIG_ALWAYS_PERFORM_CAL));

    if (contTx->scramblerOff)
    {
        whalDisableScramble(TRUE);
    }
    else
    {
        whalDisableScramble(FALSE);
    }

tcmd_cont_tx_cmd_label1:

    switch (contTx->mode)
    {
        case TCMD_CONT_TX_SINE:
            tcmd_state.tcmdTxGo = TCMD_CONT_TX_SINE;
            tcmd_cont_tx_sine(dev, contTx->freq, contTx->dataRate, contTx->gainIdx, contTx->antenna, contTx->txChain);
            /* since adjustedTwiceTxPwr always returns a fix value TX_PWR_DEFAULT if forceGain,
             * so for single tone, we have to pass in contTx->txPwr(instead of adjustedTwiceTxPwr) so the power will be adjustable */
            break;

        case TCMD_CONT_TX_CWTONE:
            tcmd_state.tcmdTxGo = TCMD_CONT_TX_CWTONE;
            //A_PRINTF("get in cwtone mode\n");
            //tcmd_cont_tx_data(dev, contTx->dataRate, adjustedTwiceTxPwr, contTx->antenna, contTx->pktSz, contTx->txPattern, contTx->nPattern, contTx->dataPattern, 0, 1, contTx->mode, contTx->shortGuard, contTx->txChain,FALSE,1, contTx->broadcast, contTx->txStation, contTx->rxStation, contTx->bssid, contTx->agg,contTx->miscFlags);


            tcmd_cont_tx_cwtone(dev, contTx->freq, contTx->gainIdx, contTx->txChain);
            //tcmd_cont_tx_data(dev, contTx->dataRate, adjustedTwiceTxPwr, contTx->antenna, contTx->pktSz, contTx->txPattern, contTx->nPattern, contTx->dataPattern, 0, 1, contTx->mode, contTx->shortGuard, contTx->txChain,FALSE,0, contTx->broadcast, contTx->txStation, contTx->rxStation, contTx->bssid, contTx->agg,contTx->miscFlags);

            //A_INIT_TIMER(&tcmd_tx_read_pdadc_timer, tcmd_tx_readpdadc_timer_handler, 0);
            //A_TIMEOUT_MS(&tcmd_tx_read_pdadc_timer, 10, 0);
            break;

        case TCMD_CONT_TX_CLPCPKT:
            tcmd_state.tcmdTxGo = TCMD_CONT_TX_CLPCPKT;
            tcmd_cont_tx_clpcpkt(dev, contTx->freq, contTx->gainIdx, contTx->txChain, contTx->dacGain, contTx->paConfig, contTx->tpcm);
#if 1
			tcmd_cont_tx_data(dev, contTx, 0, TRUE, contTx->numPackets);
#else
            tcmd_cont_tx_data(dev, contTx->dataRate, adjustedTwiceTxPwr, contTx->antenna, contTx->pktSz, contTx->txPattern, contTx->nPattern, contTx->dataPattern, 0, 1, contTx->mode, contTx->shortGuard, contTx->txChain,TRUE/*FALSE*/,contTx->numPackets/*0*/, contTx->broadcast, contTx->txStation, contTx->rxStation, contTx->bssid, contTx->agg,contTx->miscFlags);
#endif			

//            A_PRINTF_ALWAYS("clpcpkt mode d\n");
            //A_INIT_TIMER(&tcmd_tx_read_pdadc_timer, tcmd_tx_readpdadc_timer_handler, 0);
            //A_TIMEOUT_MS(&tcmd_tx_read_pdadc_timer, 10, 0);

            break;

        case TCMD_CONT_TX_FRAME:
            tcmd_state.tcmdTxGo = TCMD_CONT_TX_FRAME;
            //contTx->txPwr = adjustedTwiceTxPwr;
            if (contTx->numPackets)
            {
#if 1
			tcmd_cont_tx_data(dev, contTx, contTx->aifsn, waitForTxComplete, contTx->numPackets);
#else
             tcmd_cont_tx_data(dev, contTx->dataRate, adjustedTwiceTxPwr, contTx->antenna, contTx->pktSz, contTx->txPattern, contTx->nPattern, contTx->dataPattern, contTx->aifsn, 1, contTx->mode, contTx->shortGuard, contTx->txChain, waitForTxComplete, contTx->numPackets, contTx->broadcast, contTx->txStation, contTx->rxStation, contTx->bssid, contTx->agg,contTx->miscFlags);
#endif			 
            }
            else
            {
#if 1
			tcmd_cont_tx_data(dev, contTx, contTx->aifsn, FALSE, 0);
#else 			
             tcmd_cont_tx_data(dev, contTx->dataRate, adjustedTwiceTxPwr, contTx->antenna, contTx->pktSz, contTx->txPattern, contTx->nPattern, contTx->dataPattern, contTx->aifsn, 1, contTx->mode, contTx->shortGuard, contTx->txChain, FALSE, 0, contTx->broadcast, contTx->txStation, contTx->rxStation, contTx->bssid, contTx->agg,contTx->miscFlags);
#endif			 
            }
            break;

        case TCMD_CONT_TX_TX99:
            tcmd_state.tcmdTxGo = contTx->mode;
            //contTx->txPwr = adjustedTwiceTxPwr;
            //contTx->numPackets = 0;
#if 1
			tcmd_cont_tx_data(dev, contTx, 0, FALSE, contTx->numPackets);
#else
            tcmd_cont_tx_data(dev, contTx->dataRate, adjustedTwiceTxPwr, contTx->antenna, contTx->pktSz, contTx->txPattern, contTx->nPattern, contTx->dataPattern, 0, 1, contTx->mode, contTx->shortGuard, contTx->txChain, FALSE,contTx->numPackets, contTx->broadcast, contTx->txStation, contTx->rxStation, contTx->bssid, contTx->agg,contTx->miscFlags);
#endif		   
            break;

        case TCMD_CONT_TX_TX100:
            tcmd_state.tcmdTxGo = contTx->mode;
            //contTx->txPwr = adjustedTwiceTxPwr;
            //contTx->numPackets = 0;
#if 1
			tcmd_cont_tx_data(dev, contTx, 0, FALSE, 0);
#else
     		tcmd_cont_tx_data(dev, contTx->dataRate, adjustedTwiceTxPwr, contTx->antenna, contTx->pktSz, contTx->txPattern, contTx->nPattern, contTx->dataPattern, 0, 1, contTx->mode, contTx->shortGuard, contTx->txChain,FALSE,0, contTx->broadcast, contTx->txStation, contTx->rxStation, contTx->bssid, contTx->agg,contTx->miscFlags);
#endif			
            break;

        default:
            A_PRINTF ("%stcmd_cont_txunsupport mode! \n", __func__);
            break;
    }

    if (contTx->miscFlags & BANDEDGE_HC_MASK)
    {
          whalEepromBandEdgeEnableHC();
    }

    #if defined(QCA9888)
    if(whalPaprdTpcOlpcTuningEnableGet()){
        whalDoDPDCalibration(TRUE);
    }
    #endif
}
/*
 * Further sub categorize mode of Rx and call appropriate implementation.
 */

A_UINT32 tcmd_cont_rx_cmd(wlan_tcmd_dev_t *dev, TCMD_CONT_RX *contRx)
{
    gForceTxPwrMode = FALSE;
    gDPDCalDone = FALSE;
    A_INT8 success = 1;

#ifdef TCMD_DEBUG
    A_UINT32 rateIndex;
#endif

#if defined(QCA9984)
    WHAL_CHANNEL chan;
    tcmd_get_channel(contRx->u.para.freq,contRx->u.para.wlanMode, contRx->u.para.bandwidth, &chan, contRx->u.para.freq2);

    update_bdf_commonparams_from_ebdf(&chan);
#endif

    whalPaprdEnableCal(FALSE);
#if defined(IPQ4019) || defined(QCA9888) || defined(QCA9984) || defined(AR900B)
    gEnableFastChannelChange = FALSE;
#else
    gEnableFastChannelChange = TRUE;
#endif
    //Restore analog registers changed by tone tx
    ar6000SingleCarrierRestore();

#if 0
    //TCMD_PRINTF("+%s\n",__func__);
    if (contRx->act == TCMD_CONT_RX_PROMIS) {
        A_PRINTF ("tcmd_cont_rx promis: freq %d antenna %d\n ",
                    contRx->u.para.freq, contRx->u.para.antenna);
    } else if (contRx->act == TCMD_CONT_RX_FILTER) {
        A_PRINTF ("tcmd_cont_rx filter: freq %d antenna %d\n ",
                    contRx->u.para.freq, contRx->u.para.antenna);
    } else if (contRx->act == TCMD_CONT_RX_SETMAC) {
        A_PRINTF ("tcmd_cont_rx setmac: %02x %02x %02x %02x %02x %02x \n",
                    contRx->u.mac.addr[0], contRx->u.mac.addr[1], contRx->u.mac.addr[2],
                    contRx->u.mac.addr[3], contRx->u.mac.addr[4], contRx->u.mac.addr[5]);
    } else if (contRx->act == TCMD_CONT_RX_SET_ANT_SWITCH_TABLE) {
        A_PRINTF ("tcmd_cont_rx setant switch table: %x %x \n",
                    contRx->u.antswitchtable.antswitch1,
                    contRx->u.antswitchtable.antswitch2);
    }
#endif

    tcmd_pm_awake();

    tcmd_txchain_mask = contRx->u.para.rxChain;

    switch (contRx->act) {
    case TCMD_CONT_RX_PROMIS:
    case TCMD_CONT_RX_FILTER:
#if 0 // Allan
        if(contRx->enANI) {
            whalEnableAni(TRUE);
         }else {
            whalEnableAni(FALSE);
         }
#endif
        /* switch off Tx before begin */
    	if (tcmd_state.tcmdRxGo == TCMD_CONT_RX_ON && tcmd_state.tcmdTxGo == TCMD_CONT_TX_OFF)
    		utfRxStop(&utf_dev);
    	if (tcmd_state.tcmdRxGo == TCMD_CONT_RX_TX_ON || tcmd_state.tcmdTxGo != TCMD_CONT_TX_OFF)
        {
            utfTxStop(dev, NULL);
            tcmd_state.tcmdTxGo = TCMD_CONT_TX_OFF;
            tcmd_state.tcmdRxGo = TCMD_CONT_RX_OFF;
            A_MEMZERO(&tcmdTxStat, sizeof(struct tcmd_tx_stat_t));
        }
     	success = tcmd_cont_rx_begin(dev, contRx->act, contRx->u.para.freq, contRx->u.para.antenna, contRx->u.para.wlanMode, contRx->u.para.bandwidth, contRx->u.para.ack, contRx->u.para.rxChain, contRx->u.para.freq2);
        break;
    case TCMD_CONT_RX_REPORT:
        tcmd_stop_cont_rx(dev);
//      tcmd_state.tcmdRxGo = 0;
//	start_rx_status = 0;
//#if 1
#ifdef TCMD_DEBUG
        A_PRINTF("cont rx report: totalPkt = %d  okPkt = %d  crcErrPkt = %d\n",
            tcmdRxStat.totalPkt, tcmdRxStat.okPkt, tcmdRxStat.crcErrPkt);
        A_PRINTF("                phyErrPkt = %d  secErrPkt = %d rssiInDBm = %d\n",
            tcmdRxStat.phyErrPkt, tcmdRxStat.secErrPkt, tcmdRxStat.rssiInDBm);
        if(tcmdRxStat.okPkt > 0){
			A_PRINTF("rssiInDBmAvg = %d,NF = %d\n", tcmdRxStat.rssiInDBm/(A_INT32)tcmdRxStat.okPkt, noise_floor);
			A_PRINTF("CRC: %d,PHY:%d,SEC:%d\n", tcmdRxStat.crcErrPkt, tcmdRxStat.phyErrPkt,tcmdRxStat.secErrPkt);
        }
#endif
#ifdef TCMD_DEBUG
        //A_PRINTF("\nPacket received on rates\n");
        for (rateIndex = 0; rateIndex < TCMD_MAX_RATES; rateIndex++)
        {
            if (tcmdRxStat.rateCnt[rateIndex]) {
#ifdef SUPPORT_11N
                A_PRINTF("rate[%d] %d (SG: %d)\n",rateIndex, tcmdRxStat.rateCnt[rateIndex],tcmdRxStat.rateCntShortGuard[rateIndex]);
#else
                A_PRINTF("rate[%d] %d \n",rateIndex, tcmdRxStat.rateCnt[rateIndex]);
#endif
            }
        }
#endif



#if defined(_UTF_HOSTIF_TS_W_WMI)
        contRx->u.report.totalPkt = tcmdRxStat.okPkt;
        contRx->u.report.rssiInDBm = tcmdRxStat.rssiInDBm;
        contRx->u.report.crcErrPkt = tcmdRxStat.crcErrPkt;
        contRx->u.report.secErrPkt = tcmdRxStat.secErrPkt;
        A_MEMCPY(contRx->u.report.rateCnt, tcmdRxStat.rateCnt, sizeof(contRx->u.report.rateCnt));
#ifdef SUPPORT_11N
        A_MEMCPY(contRx->u.report.rateCntShortGuard, tcmdRxStat.rateCntShortGuard, sizeof(contRx->u.report.rateCntShortGuard));
#endif
#ifdef SUPPORT_11N
/*        wmi_tcmd_cont_rx_report_event(dev->wmi, tcmdRxStat.okPkt,
                                     tcmdRxStat.rssiInDBm, tcmdRxStat.crcErrPkt, tcmdRxStat.secErrPkt, tcmdRxStat.rateCnt, tcmdRxStat.rateCntShortGuard);*/
#else
/*        wmi_tcmd_cont_rx_report_event(dev->wmi, tcmdRxStat.okPkt,
                                     tcmdRxStat.rssiInDBm, tcmdRxStat.crcErrPkt, tcmdRxStat.secErrPkt, tcmdRxStat.rateCnt, NULL);*/
#endif
#endif //#if defined(_UTF_HOSTIF_TS_W_WMI)

        //TCMD_PRINTF ("tcmd_cont_rx_cmd: cont_rx report event done\n");
        tcmd_pm_sleep();
        A_MEMZERO(&tcmdRxStat, sizeof(struct tcmd_rx_stat_t));
        return 1;/* this tells the caller to send the rx report, if the requester is tcmd */
        break;
    case TCMD_CONT_RX_SETMAC:
        if (!IS_MAC_NULL(contRx->u.mac.addr))
            A_MEMCPY(tcmd_state.macAddr, contRx->u.mac.addr, IEEE80211_ADDR_LEN);

        if (!IS_MAC_NULL(contRx->u.mac.bssid))
            A_MEMCPY(tcmd_state.bssid, contRx->u.mac.bssid, IEEE80211_ADDR_LEN);
        break;
    case TCMD_CONT_RX_SET_ANT_SWITCH_TABLE:
        whalSetAntSwitchTbl(contRx->u.antswitchtable.antswitch1, contRx->u.antswitchtable.antswitch2);
        break;
    default:
        //A_PRINTF ("tcmd_cont_rx: unsupport act! \n");
        break;
    }

    if(success == A_ERROR)
       return 1;
    else
       return 0;

    //return 0;
}

void tcmd_pm_cmd(wlan_tcmd_dev_t *dev, TCMD_PM *pm )
{
    WHAL_CHANNEL chan;
    chan.mhz = tcmd_default_freq;
    if (tcmd_default_freq == TCMD_DEFAULT_FREQ_2G)
	chan.phy_mode = TCMD_DEFAULT_WLAN_MODE_2G;
    else
	chan.phy_mode = TCMD_DEFAULT_WLAN_MODE_5G;

    chan.max_reg_power = TCMD_MAX_RDPWR;  /*copy from haldemo.c chanArray.*/
    chan.flags = 0;
    chan.band_center_freq1 = chan.mhz;
    chan.band_center_freq2 = chan.mhz;
    //TCMD_PRINTF ("tcmd_pm: mode %d \n", pm->mode);

    if (tcmd_state.tcmdMode == pm->mode) {
        return;
    }

    /*
     * Disable auto sleep mode if host starts controlling the PM mode
     */
    auto_deep_sleep_mode = FALSE;

    tcmd_pm_awake();
    if (pm->mode == TCMD_PM_WAKEUP) {
        tcmd_state.tcmdMode = TCMD_STATUS_ENABLE;
    } else if ((pm->mode == TCMD_PM_SLEEP) || (pm->mode == TCMD_PM_DEEPSLEEP))
    {
        /* make sure no tx/rx on-going */
        if (tcmd_state.tcmdTxGo == TCMD_CONT_TX_SINE) {
            tcmd_cont_sine_tx_stop(dev);
            tcmd_state.tcmdTxGo = TCMD_CONT_TX_OFF;
        } else if (tcmd_state.tcmdTxGo != TCMD_CONT_TX_OFF) {
            tcmd_cont_data_tx_stop(dev);
            tcmd_state.tcmdTxGo = TCMD_CONT_TX_OFF;
        } else if (tcmd_state.tcmdRxGo) {
            tcmd_stop_cont_rx(dev);
            tcmd_state.tcmdRxGo = TCMD_CONT_RX_OFF;
        }

        tcmd_whalReset(&chan);
        if (pm->mode == TCMD_PM_SLEEP) {
            tcmd_state.tcmdMode = TCMD_STATUS_SLEEP;
        } else {
            tcmd_state.tcmdMode = TCMD_STATUS_DEEPSLEEP;
        }
        tcmd_pm_sleep();
    }
}
/*
 * Based on the filter settings, start listening to the pkts on the air.
 * By starting the dma receive engine, MAC will call the registered
 * call back functions every pkt that matches the filtering option.
 */
static A_UINT32
tcmd_cont_rx_begin(wlan_tcmd_dev_t *dev, TCMD_CONT_RX_ACT act, A_UINT32 freq, A_UINT32 antenna, A_UINT32 wlanMode, A_UINT32 bandwidth, A_UINT32 ack, A_UINT32 rxChain, A_UINT32 freq2)
{
    A_UINT32 rfilt;

    gDeafMode = FALSE;
    waltest_rx_restore(utf_dev.pdev);
     if (tcmd_state.tcmdRxGo != TCMD_CONT_RX_TX_ON)
     {
        if (rxChain == 0) rxChain = 1;
            wal_rc_set_hw_chainmasks(dev->pdev, 1, rxChain);
     }

    g_xtal_cal_flag = FALSE;
     //wal_rc_set_hw_chainmasks(dev->pdev, 1, rxChain);

    whalEnableAni(0);
#ifndef FPGA
    gFTMCalInProgress = FALSE;
#endif

#if defined(CONFIG_BB)
    if (tcmd_state.tcmdRxGo != 2) {
    	if (A_OK != tcmd_setup_channel(dev, FALSE, freq, wlanMode, bandwidth, freq2, rxChain))
            return 1;
    }
#endif
    noise_floor = whalGetNf();
    if (!noise_floor)
       noise_floor = DEFAULT_NOISE_FLOOR;

    if (tcmd_state.tcmdRxGo != TCMD_CONT_RX_TX_ON) {
        g_encap_cfg.sa_addr = tcmd_state.srcAddr;
        g_encap_cfg.da_addr = tcmd_state.macAddr;
        g_encap_cfg.bss_addr = tcmd_state.bssid;
        g_encap_cfg.chain_mask = (A_UINT8) rxChain;
    }
#if defined(_USE_RX_INT)
    if (tcmd_state.tcmdRxGo == TCMD_CONT_RX_OFF || tcmd_state.tcmdRxGo == TCMD_CONT_RX_TX_ON)
    {
        waltest_rx(utf_dev.pdev, &utf_dev, tcmd_rx_complete_handler, NULL);
        if (tcmd_state.tcmdTxGo == TCMD_CONT_TX_OFF)
            tcmd_state.tcmdRxGo = TCMD_CONT_RX_ON;
    }
#endif


    /* set filter */
    if (act == TCMD_CONT_RX_FILTER) {
        rfilt =  WHAL_RX_FILTER_UCAST |  WHAL_RX_FILTER_BCAST |  WHAL_RX_FILTER_MCAST
                | WHAL_RX_FILTER_FROM_TO_DS;
        whalSetRxFilter(rfilt);
    }
    else if (act == TCMD_CONT_RX_PROMIS)
        /* Promiscuous mode */
        whalSetRxFilter(WHAL_RX_FILTER_PROM);

    whalEnableMibCounters(TRUE);
    whalEnableInterrupts(WHAL_INT_RX);
    whalSetGlobalRxRingEnable(TRUE);
    whalStartPcuReceive();
    whalStartDmaReceive();      /* enable recv descriptors */

    return 0;
}

/*
 * Stop the continous rx. Undo whatever start function did.
 */
static void
tcmd_stop_cont_rx(wlan_tcmd_dev_t *dev)
{
#if !defined(AR900B) && !defined(QCA9984) && !defined(IPQ4019) && !defined(QCA9888)
    // Restore analog registers changed due to xtal cal if valid
    ar6000SingleCarrierRestore();

    waltest_rx_detach(utf_dev.pdev);

    gDeafMode = FALSE;

    /* Stop Receive */
    //whalSetRxFilter(0);
    OS_REG_WRITE(MAC_PCU_RX_FILTER_ADDRESS, 0);
    OS_REG_WRITE(MAC_PCU_RX_FILTER2_ADDRESS, 0);
    whalStopPcuReceive();
    whalStopDmaReceive();
    whalDisableInterrupts(WHAL_INT_RX);
#else
    if (whalPaprdGetState() != PAPRD_CAL_SM_IDLE)
    {
        A_PRINTF_ALWAYS("TX stop is received while DPD cal is in progress and abort cal. Transmitted training packet is %d\n",
                        pPaprdStruct->transmitted_training_packets);
        whalPaprdSetState(PAPRD_CAL_SM_TEARDOWN_TRAINING);
        whalPaprdCalibrationSM();
    }
    //utf_dev.pdev->rx_filter = whalGetRxFilter();
    //whalSetRxFilter(0);
    //OS_REG_WRITE(MAC_PCU_RX_FILTER_ADDRESS, 0);
    //OS_REG_WRITE(MAC_PCU_RX_FILTER2_ADDRESS, 0);
    //if (!whalStopTxDma(1000))
         //A_ASSERT(FALSE);

    //whalStopPcuReceive();
    waltest_rx_detach(utf_dev.pdev);
    whalDisableInterrupts(WHAL_INT_RX);
#endif
}

/*
 * setup 2.4/5 GHz channels
 */

//extern RXGAIN_CAL_DATA gRxGainCal4Chan;

A_STATUS
tcmd_setup_channel(wlan_tcmd_dev_t *dev, A_BOOL doIt, A_UINT32 freq, A_UINT32 wlanMode, A_UINT32 bandwidth, A_UINT32 freq2, A_UINT32 Chain)
{
    // for now, bringup testing, enable reset for channel change ...
    // Otherwise, single carrier doesn't work
    //return(tcmd_setup_channel_real(dev, freq, wlanMode, bandwidth, FALSE));
    // get and update the Rx Gain cal data for the channel struc in global
#if (defined(AR900B) || defined(QCA9984) || defined(QCA9888) || defined(IPQ4019)) && !defined(FPGA)
	ar900BGetRxGainCalData4Chan(freq);
#endif
	//TODO CASCADE  QCA9948?
    return(tcmd_setup_channel_real(dev, freq, wlanMode, bandwidth, doIt, freq2, Chain));
}

void tcmd_reset_pre_callback(WHAL_CHANNEL *curChan, A_UINT32 resetCause)
{
    A_UINT8 prePost = 0;
    unsigned long pParam[2];

    // process pre-cal sticky writes
    if (_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero)
    {
        if (_PostWhalResetSettings.pPostProc)
        {
            pParam[0] = (unsigned long)curChan;
            pParam[1] = (unsigned long)prePost;
            //A_PRINTF("tcmd_reset_pre_callback - chan = 0x%08x\n", curChan);
            (_PostWhalResetSettings.pPostProc)(pParam);
        }
    }
}

void tcmd_reset_post_callback(WHAL_CHANNEL *curChan, A_UINT32 resetCause)
{
    A_UINT8 prePost = 1;
    unsigned long pParam[2];

    // process post-cal sticky writes
    if (_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero)
    {
        if (_PostWhalResetSettings.pPostProc)
        {
            pParam[0] = (unsigned long)curChan;
            pParam[1] = (unsigned long)prePost;
            //A_PRINTF("tcmd_reset_post_callback - chan = 0x%08x\n", curChan);
            (_PostWhalResetSettings.pPostProc)(pParam);
        }
    }
}

static A_STATUS
tcmd_setup_channel_real(wlan_tcmd_dev_t *dev, A_UINT32 freq, A_UINT32 wlanMode, A_UINT32 bandwidth, A_BOOL doIt, A_UINT32 freq2, A_UINT32 Chain)
{
    static A_UCHAR previousMode = MODE_UNKNOWN;
    WHAL_CHANNEL chan;

#if !defined(FPGA)
#if defined(AR9888)
    AR6000_EEPROM *pEeprom;
#endif
#endif

#if defined(DBGLOG_FTM_SUPPORT)
    DBGLOG_RECORD_LOG(WLAN_MODULE_FTM, -1, FTM_DBGID_SETUP_CHANNEL, DBGLOG_UTF, 5, 0xCCCC, freq, freq2, bandwidth, Chain);
#endif

    if (!doIt) {
    if ((freq == tcmd_state.freq) && (freq2 == tcmd_state.freq2) && (wlanMode == tcmd_state.wlanMode) && (bandwidth == tcmd_state.bandwidth) && (Chain == tcmd_state.chain)) {
        return A_OK;
    }
    }
    // set the state
    tcmd_state.freq = freq;
    tcmd_state.freq2 = freq2;
    tcmd_state.wlanMode = wlanMode;
    tcmd_state.bandwidth = bandwidth;
    tcmd_state.chain = Chain;

    tcmd_get_channel(freq, wlanMode, bandwidth, &chan, freq2);
    if (chan.phy_mode == MODE_UNKNOWN) {
        A_PRINTF_ALWAYS("%s\n mode unknown %d", __func__, wlanMode);
        return A_ERROR;
    }

#if !defined(FPGA)
#if defined(AR9888)
    pEeprom = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();
    if (pEeprom)
    {
        WHAL_REG_DOMAIN regDmn;
        A_UINT8  rdCtl[2];
        regDmn = pEeprom->baseEepHeader.regDmn[0];
        if (regDmn == 0x10) // US reg domain
        {
            rdCtl[0] = rdCtl[1] = 0x10; // FCC
            whalSetRegulatoryDomain(regDmn, rdCtl);
        }
    }
#endif
#endif

//#define _WHEN_FAST_CHANNEL_CHANGE_IS_TESTED
//#if defined(_WHEN_FAST_CHANNEL_CHANGE_IS_TESTED)
    A_BOOL bReset;

if (gEnableFastChannelChange )
{
    A_UINT8 i;
    A_BOOL newHomeCh = TRUE;
    static A_UINT8 homeChCnt = 0;
    for (i = 0; i < WHAL_MAX_HOME_CHANNEL; i++) {
        if (chan.band_center_freq1 == homeChan[i].band_center_freq1) {
            newHomeCh = FALSE;
            break;
        }
    }
    if (newHomeCh) {
        i = homeChCnt % WHAL_MAX_HOME_CHANNEL;
        whalSetHomeChannel(&homeChan[i], FALSE);
        whalSetHomeChannel(&chan, TRUE);
        A_MEMCPY(&homeChan[i], &chan, sizeof(WHAL_CHANNEL));
        homeChCnt++;
    }
}
//#else
else
{
    whalSetHomeChannel(&homeChan[0], FALSE);
    whalSetHomeChannel(&chan, TRUE);
    A_MEMCPY(&homeChan[0], &chan, sizeof(WHAL_CHANNEL));
}
//#endif


    isChannelSetupOk = TRUE;
    whalPaprdValidateChannel(&chan, 1);
//#if defined(_WHEN_FAST_CHANNEL_CHANGE_IS_TESTED)
if ( gEnableFastChannelChange )
{
    if (whalChannelSwitch(&chan, 0, &bReset) == FALSE)
    {
        A_PRINTF("channel change failed...\n");
        //A_PRINTF("reset ch%d maxpwr%d mod%d flag0x%x\n", chan.mhz, chan.max_reg_power, chan.phy_mode, chan.flags);
        if (tcmd_whalReset(&chan) != A_OK)
        {
            A_PRINTF("tcmd_setup_channel failed\n");
            isChannelSetupOk = FALSE;
        }
    }
    //waltest_rx_restore(utf_dev.pdev);
}
//#else
else
{
    if (tcmd_whalReset(&chan) != A_OK)
    {
        A_PRINTF_ALWAYS("tcmd_whalReset failed\n");
        isChannelSetupOk = FALSE;
    }
}
//#endif //#if defined(_WHEN_FAST_CHANNEL_CHANGE_IS_TESTED)



#if defined(AR9888)
    //A_PRINTF("%s setting LOforcedon to 1\n", __func__);
    /* force LOforcedon value to 1 */
    A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_RXTX_B0_RXTX2_ADDRESS, PHY_ANALOG_RXTX_B0_RXTX2_LOFORCEDON, 1);
#if (WHAL_RX_NUM_CHAIN > 1)
    A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_RXTX_B1_RXTX2_ADDRESS, PHY_ANALOG_RXTX_B1_RXTX2_LOFORCEDON, 1);
#endif
#if (WHAL_RX_NUM_CHAIN > 2)
    A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_RXTX_B2_RXTX2_ADDRESS, PHY_ANALOG_RXTX_B2_RXTX2_LOFORCEDON, 1);
#endif
#endif

    tcmd_set_curmode(chan.phy_mode);
    /*
    * This routine save the original switch table,it should not change during operation,otherwise
    * we can't specify the ANT to TX/RX in ar6000SetupAntenna(),as the value in registers may be toggled
    * in previous commandas.It should be called after ath_hal_reset() called,that's,after board values read
    * from EEPROM/Flash and programed to registers.
    */
    if (previousMode != chan.phy_mode){
        whalGetAntSwitchTbl();
        previousMode = chan.phy_mode;
    }

    return A_OK;
}

//#define _TX_POLL_DELAY      10000 //100000
#define _TX_POLL_DELAY      1000 //100000
#define _TX_INTERVAL_DELAY  1000  //10000
#define _TX_POLL_LOOPS      100
#define TX_TIMEOUT_COUNT 100000000

WHAL_TXQ_INFO  qInfo;
static void utfTxStartInternal(wlan_tcmd_dev_t *dev, TCMD_CONT_TX * contTx ,A_UINT32 aifswait, A_BOOL disableContinuousTx,  A_UINT32 numPkts)
{
    A_UINT32 rfilt;
    A_UINT32  param_value;
    WHAL_RC_FLAGS rc_flags;
    A_UINT32 ttPkts;

    //A_PRINTF("%d, %d, %d, %d, %d, %d\n", contTx->dataRate, txPwr, antenna, contTx->pktSz, contTx->txPattern, contTx->nPattern);
    //A_PRINTF("%d, %d, %d, %d, %d\n", contTx->dataPattern[0], aifswait, retries , contTx->mode, contTx->shortGuard);
    //A_PRINTF("0x%x, %d, %d, %d, %d\n", contTx->txChain, disableContinuousTx,  numPkts, stopTxAfterDoneNumPkts, contTx->broadcast);
    //A_PRINTF("%d, %d, %d, %d, 0x%x\n", contTx->txStation[5], contTx->rxStation[5], contTx->bssid[5], contTx->agg, contTx->miscFlags);

	
    rfilt =  WHAL_RX_FILTER_UCAST |  WHAL_RX_FILTER_BCAST;

    // Restore analog registers changed due to xtal cal if valid
    ar6000SingleCarrierRestore();

    if (contTx->miscFlags & TCMD_GO_MASK)
    {
    	goto tx_go;
    }
    if (IS_MAC_NULL(contTx->txStation))
        g_encap_cfg.sa_addr = SA_ADDR;
    else
        g_encap_cfg.sa_addr = contTx->txStation;
    if (IS_MAC_NULL(contTx->rxStation))
        g_encap_cfg.da_addr = DA_ADDR;
    else
        g_encap_cfg.da_addr = contTx->rxStation;
    if (IS_MAC_NULL(contTx->bssid))
        g_encap_cfg.bss_addr = BSS_ADDR;
    else
        g_encap_cfg.bss_addr = contTx->bssid;

#if defined(_USE_TX_INT)
    waltest_tx(utf_dev.pdev, &utf_dev, tcmd_tx_complete_handler, NULL);
#endif

    //A_PRINTF("contTx->pktSz utfTx %d bc %d\n",contTx->pktSz,contTx->broadcast);
    g_encap_cfg.pkt_len = contTx->pktSz;
    g_encap_cfg.pattern = contTx->txPattern;
    g_encap_cfg.pattern_length = contTx->nPattern;
    g_encap_cfg.pattern_data = contTx->dataPattern;
    g_encap_cfg.is_broadcast = contTx->broadcast ? TRUE : FALSE;
    g_encap_cfg.chain_mask = (A_UINT8) contTx->txChain;
    g_encap_cfg.num_desc = 1;
    g_encap_cfg.num_aggr = 0;
    g_encap_cfg.data_rate = contTx->dataRate;
    if (contTx->txPattern == PN15_PATTERN)
    {
        g_encap_cfg.num_desc = 4;/*Length of PN15 is larger than MAX buffer, split it to 4 frame*/
    }
    else if (contTx->agg > 1)
    {
        g_encap_cfg.num_aggr = contTx->agg;
    }
    if (g_encap_cfg.num_desc > NUM_TEST_PKTS)
        g_encap_cfg.num_desc = NUM_TEST_PKTS;
    if (g_encap_cfg.num_aggr > PKTS_PER_TID)
        g_encap_cfg.num_aggr = PKTS_PER_TID;

    /* setup txq based on passed in parameters */
    //wal_phy_dev_set_param(utf_dev.pdev, WAL_PDEV_IFS, aifswait);
    //NOTE: we will use qnum 1 instead of 0...
    whalGetTxQueueProps(7/* q*/, &qInfo);
    qInfo.tqiAifs = aifswait;
    qInfo.tqiCwmin = 0;
    qInfo.tqiCwmax = 0;
    whalSetTxQueueProps(7/*q*/, &qInfo, TRUE);

    if ( g_encap_cfg.vdev != NULL )
    {
        rc_flags = wal_rc_get_vdev_rc_flags(g_encap_cfg.vdev);

        param_value = contTx->miscFlags & DESC_LDPC_ENA_MASK;

//A_PRINTF("LDPC %d\n",param_value);

        if (param_value)
        {
//A_PRINTF("Set LDPC\n");
            rc_flags |= WHAL_RC_FLAG_LDPC;
        }
        else
        {
//A_PRINTF("Clear LDPC\n");
            rc_flags &= ~WHAL_RC_FLAG_LDPC;
        }

        param_value = contTx->miscFlags & DESC_STBC_ENA_MASK;

//A_PRINTF("STBC %d\n",param_value);

        if (param_value)
        {
//A_PRINTF("Set STBC\n");
            rc_flags |= WHAL_RC_FLAG_STBC;
        }
        else
        {
//A_PRINTF("Clear STBC\n");
            rc_flags &= ~WHAL_RC_FLAG_STBC;
        }

        param_value = contTx->shortGuard;

//A_PRINTF("contTx->shortGuard %d\n",param_value);

        if (param_value)
        {
//A_PRINTF("Set SGI\n");
            WHAL_RC_FLAG_SET_GI(rc_flags, WHAL_GI_400);
        }
        else
        {
//A_PRINTF("Clear SGI\n");
            WHAL_RC_FLAG_SET_GI(rc_flags, WHAL_GI_800);
        }

        wal_rc_set_vdev_rc_flags(g_encap_cfg.vdev, rc_flags);
    }

    /* Set up the basic filters */
//    rfilt =  WHAL_RX_FILTER_UCAST |  WHAL_RX_FILTER_BCAST |  WHAL_RX_FILTER_MCAST
//                | WHAL_RX_FILTER_FROM_TO_DS;

    rfilt =  WHAL_RX_FILTER_UCAST |  WHAL_RX_FILTER_BCAST;

    A_MEMZERO(&tcmdTxStat, sizeof(struct tcmd_tx_stat_t));
    tcmd_state.numTxPkts = numPkts;
    tcmd_state.disContTx = disableContinuousTx;
    if (contTx->miscFlags & TCMD_SETTUP_MASK)
    {
    	return;
    }
tx_go:
    stop_tx = 0;



#ifndef DISABLE_RX
    //waltest_rx(utf_dev.pdev, &utf_dev, NULL, NULL);
    if (tcmd_state.tcmdRxGo == TCMD_CONT_RX_OFF || tcmd_state.tcmdRxGo == TCMD_CONT_RX_ON)
    {
        waltest_rx(utf_dev.pdev, &utf_dev, tcmd_rx_complete_handler, NULL);
        if (tcmd_state.tcmdRxGo == TCMD_CONT_RX_OFF)
            tcmd_state.tcmdRxGo = TCMD_CONT_RX_TX_ON;
    }
#if defined(IPQ4019) || defined(QCA9888)
	if(contTx->mode != TCMD_CONT_TX_TX99) // For Target assert issue occurred at Besra and Dakota
#endif	
        whalSetRxFilter(rfilt);
    whalEnableMibCounters(TRUE);
    whalStartPcuReceive();   /* re-enable PCU/DMA engine */
    whalStartDmaReceive();      /* enable recv descriptors */
    whalEnableInterrupts(WHAL_INT_RX);
#endif

    if(contTx->mode == TCMD_CONT_TX_TX99) // TX99 only
     	setRxDeaf(contTx->dataRate);

    whalEnableInterrupts(WHAL_INT_TX);
    g_tx_timeout_count = 0;
    waltest_tx_start();
   // return;
    if (!disableContinuousTx || !numPkts) {

			//check that we at least started transmitting packets before returning
#if 1
 #if !defined(A_SIMOS_DEVHOST)
        while (tcmdTxStat.totalPkt < 2)
        {   //should this number be configurable?
                   WHAL_INT gIntrPending;
                   whalGetPendingInterrupts(&gIntrPending);
                   //A_PRINTF("gIntrPending tcmd = %d\n", gIntrPending);
                   tx_send_completion_hdlr(utf_dev.pdev);
                   if (++g_tx_timeout_count > TX_TIMEOUT_COUNT) break;
        }
#endif
#endif
        if (g_tx_timeout_count > TX_TIMEOUT_COUNT) {
            A_PRINTF("Tx Failed tcmdTxStat.totalPkt = %d\n", tcmdTxStat.totalPkt);
            return;
        }
    }

return;
    ttPkts = tcmdTxStat.totalPkt;
    while (ttPkts < tcmd_state.numTxPkts )
    {
#if !defined(A_SIMOS_DEVHOST)
        WHAL_INT gIntrPending;

        whalGetPendingInterrupts(&gIntrPending);
//        A_PRINTF("gIntrPending tcmd = %d\n", gIntrPending);
        tx_send_completion_hdlr(utf_dev.pdev);
#endif
        ttPkts = tcmdTxStat.totalPkt; // to avoid Klockwork error
    }

    stop_tx = 2;
    utfTxStop(dev, NULL);
    tcmd_state.tcmdTxGo = TCMD_CONT_TX_OFF;
    tcmd_state.tcmdRxGo = TCMD_CONT_RX_OFF;
    A_MEMZERO(&tcmdTxStat, sizeof(struct tcmd_tx_stat_t));
    return;
}


static void tcmd_cont_tx_data(wlan_tcmd_dev_t *dev, TCMD_CONT_TX * contTx ,A_UINT32 aifswait, A_BOOL disableContinuousTx,  A_UINT32 numPkts)
{
	//TCMD_PRINTF("%s\n", __func__);
		utfTxStartInternal(dev, contTx, aifswait, disableContinuousTx, numPkts);
}

static void
tcmd_cont_data_tx_stop(wlan_tcmd_dev_t *dev)
{
    WHAL_CHANNEL chan;
    A_UINT8 stop;

    // Restore analog registers changed due to xtal cal if valid
    ar6000SingleCarrierRestore();

    if (whalPaprdGetState() != PAPRD_CAL_SM_IDLE)
    {
        A_PRINTF_ALWAYS("TX stop is received while DPD cal is in progress and abort cal. Transmitted training packet is %d\n",
                        pPaprdStruct->transmitted_training_packets);
        whalPaprdSetState(PAPRD_CAL_SM_TEARDOWN_TRAINING);
        whalPaprdCalibrationSM();
    }

    chan.mhz = tcmd_default_freq;

    if (tcmd_default_freq == TCMD_DEFAULT_FREQ_2G)
	chan.phy_mode = TCMD_DEFAULT_WLAN_MODE_2G;
    else
	chan.phy_mode = TCMD_DEFAULT_WLAN_MODE_5G;

    chan.max_reg_power = TCMD_MAX_RDPWR;  /*copy from haldemo.c chanArray.*/
#ifdef SUPPORT_11N
    chan.flags = 0;
#endif
    chan.band_center_freq1 = chan.mhz;
    chan.band_center_freq2 = chan.mhz;

    if (!stop_tx)
        stop_tx = 1;

    stop = stop_tx;
    while (stop != 2)
    {
#if !defined(A_SIMOS_DEVHOST)
        WHAL_INT gIntrPending;

        whalGetPendingInterrupts(&gIntrPending);
        tx_send_completion_hdlr(utf_dev.pdev);
#endif
        stop = stop_tx; //to avoid Klockwork error
    }

    utf_dev.pdev->rx_filter = whalGetRxFilter();
#ifndef DISABLE_RX
    whalStopPcuReceive();

    waltest_rx_detach(utf_dev.pdev);
#endif

    /* Stop Receive */
    //whalSetRxFilter(0);
//    OS_REG_WRITE(MAC_PCU_RX_FILTER_ADDRESS, 0);
//    OS_REG_WRITE(MAC_PCU_RX_FILTER2_ADDRESS, 0);

#if !defined(AR900B) && !defined(QCA9984) && !defined(IPQ4019) && !defined(QCA9888)
    whalStopPcuReceive();
    whalStopDmaReceive();
#endif

#ifdef FIXME_WIFI2
    if (!whalStopTxDma(1000))
    {
        //A_PRINTF("StopTxDMA failed, reset\n");
        tcmd_whalReset(&chan);
    }
#endif

    whalDisableInterrupts(WHAL_INT_TX);
#ifndef DISABLE_RX
    whalDisableInterrupts(WHAL_INT_RX);
#endif

#if defined(_USE_TX_INT)
    waltest_tx_detach(utf_dev.pdev);
#endif
    //A_PRINTF("totalPkt = %d\n", tcmdTxStat.totalPkt);
}

/* single carrier Tx, from ART code */
static void
tcmd_cont_tx_sine(wlan_tcmd_dev_t *dev, A_UINT32 freq, A_UINT32 dataRate, A_UINT32 txPwr, A_UINT32 antenna, A_UINT32 chainmask)
{
#ifdef AR6002_REV2
    A_UINT32 stbl1, stbl2;

    tcmd_stabilize_power(dev, freq, dataRate, txPwr, antenna);
    whalSingleCarrierConfig(&stbl1, &stbl2, antenna);
#else
    //tcmd_stabilize_power(dev, freq, dataRate, 7, antenna);
#endif
#ifdef AR6002_REV6
    whalSetWlanKeepAwakeCount(0);/* don't know why setting the count to 0 would make tx sine working */
#endif
    whalSingleCarrierEnable(freq, txPwr, chainmask);
}

static void
tcmd_cont_tx_cwtone(wlan_tcmd_dev_t *dev, A_UINT32 freq, A_UINT8 gainIdx, A_UINT32 chainmask)
{
#if defined(AR6320)
    A_UINT16 pdadc;

    whalSetTpcForceClpcWfm(freq, chainmask, gainIdx);
    //whalSetPdetDcOffset(freq, chainmask);
    //need add delay
    pdadc = whalGetPdetPdadcWfm(freq, chainmask);
    ValuesOfInterest.pdadc = pdadc;
    whalDisTpcForceClpcWfm(freq, chainmask);

#endif
    return;
}
extern A_UINT8 getTpcFlag(A_UINT8 is2GHz);
void
tcmd_cont_tx_clpcpkt(wlan_tcmd_dev_t *dev, A_UINT32 freq, A_UINT8 gainIdx, A_UINT32 chainmask, A_INT8 dacGain, A_UINT8 paCfg, A_UINT8 tpcm)
{
    A_UINT8 tpc_flag, clpcmode;
    A_UINT8 is2GHz = (freq > 2500) ? 0 : 1;

    clpcmode = 1;/*CLPC_MODE_EX_COUPLER*/

    tpc_flag =  getTpcFlag(is2GHz);
    if (tpc_flag == 3 /*WHAL_TPC_CONFIG_CLPC_EXPDET*/) {
        clpcmode = 2; /*CLPC_MODE_EX_COUPLER_PDET*/
    }
    //A_PRINTF_ALWAYS("%s tpc_flag=%d, clpcmode=%d\n", __func__, tpc_flag, clpcmode);

    if (tpc_flag == 1 /*WHAL_TPC_CONFIG_OLPC*/) {
        whalSetTpcForceOlpcPacket(freq, gainIdx, dacGain);
    } else {
        whalSetTpcForceClpcPacket(freq, chainmask, gainIdx, dacGain, paCfg, clpcmode, tpcm);
    }
    return;
}

static void
tcmd_cont_sine_tx_stop(wlan_tcmd_dev_t *dev)
{
    WHAL_CHANNEL chan;

    // Restore analog registers changed due to xtal cal if valid
    ar6000SingleCarrierRestore();

    chan.mhz = tcmd_default_freq;
    if (tcmd_default_freq == TCMD_DEFAULT_FREQ_2G)
	chan.phy_mode = TCMD_DEFAULT_WLAN_MODE_2G;
    else
	chan.phy_mode = TCMD_DEFAULT_WLAN_MODE_5G;

    chan.max_reg_power = TCMD_MAX_RDPWR;  /*copy from haldemo.c chanArray.*/
#ifdef SUPPORT_11N
    chan.flags = 0;
#endif
    chan.band_center_freq1 = chan.mhz;
    chan.band_center_freq2 = chan.mhz;

#ifdef AR6002_REV6
    whalSetWlanKeepAwakeCount(3);/* recovering it to 3 so that tx frame can work */
#endif
    tcmd_whalReset(&chan);
}


#ifdef AR6002_REV2
static void
tcmd_stabilize_power(wlan_tcmd_dev_t *dev, A_UINT32 freq, A_UINT32 dataRate, A_UINT32 txPwr, A_UINT32 antenna)
{
    return;
}
#endif //#ifdef AR6002_REV2


void utfTxStart_WhyNotWorking(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx)
{

    A_UINT32 adjustedTwiceTxPwr;
    //if (A_OK != tcmd_setup_channel_real(dev, contTx->freq, contTx->wlanMode, contTx->bandwidth, TRUE))/* reset device no matter what */
    if (A_OK != tcmd_setup_channel(dev, TRUE, contTx->freq, contTx->wlanMode, contTx->bandwidth, contTx->freq2, contTx->txChain))
        return;

    adjustedTwiceTxPwr = whalSetTxPowerLimitPlus((A_UINT32)contTx->txPwr);

#if 1
	utfTxStartInternal(dev, contTx, contTx->aifsn, TRUE, contTx->numPackets);
#else	
    utfTxStartInternal(dev, contTx->dataRate, adjustedTwiceTxPwr, contTx->antenna,
        contTx->pktSz, contTx->txPattern, contTx->nPattern, contTx->dataPattern, contTx->aifsn, 1,
        contTx->mode, contTx->shortGuard, contTx->txChain, 1,
        contTx->numPackets, TRUE, contTx->broadcast, contTx->txStation, contTx->rxStation, contTx->bssid, contTx->agg,contTx->miscFlags);
#endif
}


// UTF internal API for testing and cal
A_UINT32 utfContRxStart(wlan_tcmd_dev_t *dev, TCMD_CONT_RX *contRx)
{
    // clean stat.
    A_MEMZERO(&tcmdRxStat, sizeof(struct tcmd_rx_stat_t));

    // start cont. rx
    return tcmd_cont_rx_cmd(dev, (TCMD_CONT_RX *)contRx);
}

void utfRxStop(wlan_tcmd_dev_t *dev)
{
    tcmd_stop_cont_rx(dev);
}



