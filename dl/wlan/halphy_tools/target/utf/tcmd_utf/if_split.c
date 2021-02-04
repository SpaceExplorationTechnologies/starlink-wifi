/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*-
 * Copyright (c) 2002-2006 Atheros Communications, Inc.
 * All rights reserved.
 * $ATH_LICENSE_TARGET_C$
 *
 * This file contains some of functions required for TCMD, duplicated
 * from $WORKAREA/target/wlan/if_ath.c
 */

#include <athdefs.h>
#include <osapi.h>
#include "dset_api.h"
#include "whal_api.h"
#include "htc_api.h"
#include "utf_dev.h"
#include "if_athvar.h"
#include <ieee80211.h>
#include <wlan_scheduler.h>
#include <if_split.h>
#include "tcmd_api.h"
#include "whalExtensionGeneric.h"
#include "hal_tcmd.h"
#include <ar_wal.h>
#include "tcmd_internal.h"
#if defined (AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
#include <qc900b_eeprom.h>
#include "ar6000_reset.h"
#else
#include <qc98xx_eeprom.h>
#endif 
#include "cmdRspParmsDict.h"
#include "cmdRspParmsInternal.h"
#include "cmdTPCCALHandler.h"
#include "cmdTPCCALPWRHandler.h"
#include "tpcCal.h"
#include "cmdRxGainCalHandler.h"
#include "cmdProcessTlv2.h"

#include "rxGainCal.h"
#include "xtalCal.h"
#include "custOTPCmds.h"
#include "getDPDComplete.h"
#include "setRegDmn.h"
#include "getTgtPwr.h"
#include "pcieConfig.h"
#include "dpdTuning.h"
#include "genericUtfCmd.h"

/*
 * Definitions
 */

/*
 * Function Prototypes.
 */
static struct ath_txq *ath_txq_setup(wlan_tcmd_dev_t*, int, int, int);

/*
 * Function Definitions
 */

extern void tcmd_wal_setup(wlan_tcmd_dev_t *dev);
extern A_INT32 wlan_intr_handler(void *data);

extern void setup_pkt_buffer_tx();
extern void setup_pkt_buffer_rx();

/*
 * Interface initialization. Picked only the stuff required for  TCMD application.
 */
extern int tcmd_desc_alloc(wlan_tcmd_dev_t *dev);
extern void tcmd_enable(void);
#if defined (AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
#include "eeprom_i2c_api.h"
struct eeprom_i2c_api_s *eeprom_i2c_api;
/* used for debugging eeprom structure*/
QC90XX_EEPROM *gpEeprom;
extern A_UINT32 gAllocSram;
extern A_UINT32 gMissionMode;
#endif
#if defined(QCA9888)
extern A_UINT32 g_dbg_hi_desired_cpu_speed_hz;
#endif
int
tcmd_attach(wlan_tcmd_dev_t *dev, A_UINT8 *macAddr)
{
    /* Large struct to keep cal data in RAM */
    A_UINT8 *calData;
   #if defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
	QC90XX_EEPROM *pEeprom;
    #else
	QC98XX_EEPROM *pEeprom;
    #endif
    DPRINTF(dev, ATH_DEBUG_ANY, "%s: \n", __func__);

#if defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
    {
#if 0
        A_UINT32 reset_control, temp;
        reset_control = A_RTC_WLAN_REG_READ(WIFI_RESET_CONTROL_ADDRESS);
        reset_control &= ~(WIFI_RESET_CONTROL_MAC_WARM_RST_MASK |
                           WIFI_RESET_CONTROL_MAC_COLD_RST_MASK);
        reset_control &= ~(WIFI_RESET_CONTROL_BB_WARM_RST_MASK |
                           WIFI_RESET_CONTROL_BB_COLD_RST_MASK);
        A_RTC_WLAN_REG_WRITE(WIFI_RESET_CONTROL_ADDRESS, reset_control);
        //(void)A_RTC_WLAN_REG_READ(WLAN_RESET_CONTROL_ADDRESS); /* flush */
        temp = A_RTC_WLAN_REG_READ(WIFI_RESET_CONTROL_ADDRESS);
        A_UINT32 reset_control;

        /* TODO HALPHY, Bring Radio/SRIF out of reset. */
        reset_control = A_RTC_WLAN_REG_READ(WIFI_RESET_CONTROL_ADDRESS);
        reset_control &= ~(WIFI_RESET_CONTROL_RADIO_SRESET_MASK);
        A_RTC_WLAN_REG_WRITE(WIFI_RESET_CONTROL_ADDRESS, reset_control);
        (void)A_RTC_WLAN_REG_READ(WLAN_RESET_CONTROL_ADDRESS); /* flush */

        /* TODO HALPHY, Program Radio registers using SRIF. */
        whalProgRadioTables();

        reset_control = A_RTC_WLAN_REG_READ(WIFI_RESET_CONTROL_ADDRESS);
        /* MAC/BB cold reset.*/
        reset_control &= ~(WIFI_RESET_CONTROL_MAC_COLD_RST_MASK);
        reset_control &= ~(WIFI_RESET_CONTROL_BB_WARM_RST_MASK |
                           WIFI_RESET_CONTROL_BB_COLD_RST_MASK |
                           WIFI_RESET_CONTROL_MAC_WARM_RST_MASK);
        A_RTC_WLAN_REG_WRITE(WIFI_RESET_CONTROL_ADDRESS, reset_control);
        (void)A_RTC_WLAN_REG_READ(WLAN_RESET_CONTROL_ADDRESS); /* flush */

        whalWaitReg(WIFI_RESET_CONTROL_ADDRESS, WIFI_RESET_CONTROL_MAC_COLD_RST_MASK, 0);
#endif
    }
#endif

    gAllocSram = 0;
    gMissionMode = 0;
#if defined(QCA9888)	
    g_dbg_hi_desired_cpu_speed_hz = 200000000;  // it is used to fixed asert issue in FTM mode.
#endif	
    if (!(tcmd_state.flags & _UTF_BOARD_DATA_READ))
    {
        calData = A_BOARD_DATA_ADDR();
        tcmd_state.flags |= _UTF_BOARD_DATA_READ;
	    #if defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
		pEeprom = (QC90XX_EEPROM *) calData;
		gpEeprom = pEeprom;
	#else
		pEeprom = (QC98XX_EEPROM *) calData;
	#endif
	    
        A_PRINTF("Tempalte Id %d\n",pEeprom->baseEepHeader.template_version);

        A_PRINTF("mac addr %x %x %x %x ",pEeprom->baseEepHeader.macAddr[0],
                                         pEeprom->baseEepHeader.macAddr[1],
                                         pEeprom->baseEepHeader.macAddr[2],
                                         pEeprom->baseEepHeader.macAddr[3]);

        A_PRINTF("%x %x\n",pEeprom->baseEepHeader.macAddr[4], pEeprom->baseEepHeader.macAddr[5]);
    }

    /*
     * Attach the hal and verify ABI compatibility by checking
     * the hal's ABI signature against the one the driver was
     * compiled with.  A mismatch indicates the driver was
     * built with an ah.h that does not correspond to the hal
     * module loaded in the kernel.
     */

#if defined(AR9888) && !defined(AR9888_VER1)
    extern void whal_pre_init_callback(WHAL_STRUCT *);
    whalPreInitFn = whal_pre_init_callback;
#endif

    if (!(tcmd_state.flags & _UTF_HAL_ATTACHED))
    {
        extern WHAL_STRUCT *pWhalStruct;
        wal_pdev_info dev_info;
        calData = A_BOARD_DATA_ADDR();

        dev_info.bd_data = calData;

#define FIXME_WIFI2
#ifdef FIXME_WIFI2
        A_ENABLE_DEBUG_PRINT();
#endif

#if defined(QCA9984) && defined(FPGA)
        extern int cmnos_cpu_speed;
        extern A_UINT32 get_cpu_freq_in_hz();
        cmnos_cpu_speed = get_cpu_freq_in_hz();
#endif

        if (wal_dev_init(&dev_info) != WAL_EOK) {
            A_ASSERT_ALWAYS(0);
        }

#if 0
        // wal_install will call whalAttach which will initialize pWhalStruct
        dev_config.bd_data = calData;
        if (wal_install(&dev_config) != WAL_EOK)
        {
            A_ASSERT_ALWAYS(0);
        }
#endif

        A_ASSERT (pWhalStruct != NULL);

        WHAL_INI_MODULE_INSTALL();

#if defined (AR900B) || defined(QCA9984) || defined(QCA9888)
	eeprom_i2c_module_install(&eeprom_i2c_api);
#endif
	
#if defined(AR6320)
        WAL_COEX_MODULE_INSTALL();
        SM_MODULE_INSTALL();
#endif

        /* Install WHAL patches */
#if !defined(FPGA)
#if (defined(AR900B) && ((TARGET_VER == 1) || (TARGET_VER == 2)))   \
    || (defined(QCA9984) && (TARGET_VER == 1))  \
    || (defined(IPQ4019) && (TARGET_VER == 1)) 
        extern void install_patches(void);
        install_patches();
#endif
#endif
        whal_ini_init(whalGetBoardFlags());

        tcmd_wal_setup(dev);
        tcmd_state.flags |= _UTF_HAL_ATTACHED;

        dev->ic_boardMode = dev_info.cap_flags;
    }

    // wal_install will call whalReset, no need to do it here again
//    whalEnableAni(FALSE);
#if !defined(AR6320) && !defined(AR900B) && !defined(QCA9984) && !defined(IPQ4019) && !defined(QCA9888)
    whalGetAntSwitchTbl();/* save the original switch table */
    whalResetBRssi(WHAL_REG_TSF1);/* reset beacon rssi register, this will be used in whal ANI routine */
#endif //AR6320
    A_MEMZERO((void*)&_PostWhalResetSettings, sizeof(_PostWhalResetSettings));

    /* init the TPC module */
    initTPC();
    initCmdProcessTlv2();
	
    /* init the rxGainCal module */
    initRxGainCal();
    initXtalCal();

    /* init the customer OTP space */
    initWriteCustOtpSpace();
    initReadCustOtpSpace();
    initGetCustOtpSize();

    /* init the get DPD Complete flag */
    iniGetDPDComplete();
    /* init the setRegDmn cmd*/
    initSetRegDmn();
    /* init the getTgtPwr cmd*/
    initGetTgtPwr();

    /* init DPD tuning cmd */
    iniDpdTuning();

    /* init the pcie config cmd */
    initSetPcieConfigParams();

    /* init Generic UTF cmd */
    initGenericUtfCmd();

// if it's HOSTIF_WMI, or TS_W_WMI, it's called as HTC CB
#if !defined(_UTF_HOSTIF_WMI) && !defined(_UTF_HOSTIF_TS_W_WMI)
    //A_PRINTF("tcmd_enable in tmcd_attach\n");
    tcmd_enable();
#endif

    setup_pkt_buffer_tx();
    setup_pkt_buffer_rx();

    return A_OK;
}

/*
 * Setup a h/w transmit queue.
 */
static struct ath_txq *
ath_txq_setup(wlan_tcmd_dev_t *dev, int qtype, int subtype, int ac)
{

#define N(a)    (sizeof(a)/sizeof(a[0]))
    WHAL_TXQ_INFO qi;
    int qnum;
    TCMD_TXRX * pTcmdTxRx = dev->pTcmdTxRx;

    A_MEMZERO(&qi, sizeof(qi));
    qi.tqiSubtype = subtype;
    qi.tqiTid1 = WMM_AC_TO_TID1(ac);
    qi.tqiTid2 = WMM_AC_TO_TID2(ac);
    qi.tqiAifs = WHAL_TXQ_USEDEFAULT;
    qi.tqiCwmin = WHAL_TXQ_USEDEFAULT;
    qi.tqiCwmax = WHAL_TXQ_USEDEFAULT;

    /* mike: do we need this? */
    qi.tqiFlags =
              TXQ_FLAG_TXOKINT_ENABLE
            | TXQ_FLAG_TXERRINT_ENABLE
            | TXQ_FLAG_TXDESCINT_ENABLE
            | TXQ_FLAG_RDYTIME_EXP_POLICY_ENABLE
            ;
    qnum = whalAllocateTxQueue(qtype);
    if (qnum == -1) {
        /*
         * NB: don't print a message, this happens
         * normally on parts with too few tx queues
         */
        return NULL;
    }
    A_ASSERT (qnum < N(pTcmdTxRx->sc_txq));
    ///// TBD ????? TRUE
    whalSetTxQueueProps(qnum, &qi, FALSE);
    //whalSetTxQueueProps(qnum, &qi, TRUE);

    if (!ATH_TXQ_SETUP(pTcmdTxRx, qnum)) {
        struct ath_txq *txq = &pTcmdTxRx->sc_txq[qnum];

        txq->axq_qnum = qnum;
        STAILQ_INIT(&txq->axq_q);
        txq->axq_depth = 0;
        txq->axq_totalqueued = 0;
        pTcmdTxRx->sc_txqsetup |= 1<<qnum;
    }
    return &pTcmdTxRx->sc_txq[qnum];
#undef N
}
/*
 * Setup a hardware data transmit queue for the specified
 * access control.  The hal may not support all requested
 * queues in which case it will return a reference to a
 * previously setup queue.  We record the mapping from ac's
 * to h/w queues for use by ath_tx_start and also track
 * the set of h/w queues being used to optimize work in the
 * transmit interrupt handler and related routines.
 */
int
ath_tx_setup(wlan_tcmd_dev_t *dev, int ac, int haltype)
{
#define N(a)    (sizeof(a)/sizeof(a[0]))
    struct ath_txq *txq;

    A_ASSERT(ac < N(dev->pTcmdTxRx->sc_ac2q));

    txq = ath_txq_setup(dev, WHAL_TX_QUEUE_DATA, haltype, ac);
    if (txq != NULL) {
        dev->pTcmdTxRx->sc_ac2q[ac] = txq;
        dev->pTcmdTxRx->sc_qnum2ac[txq->axq_qnum] = ac;
        return 1;
    } else
        return 0;
#undef N
}

