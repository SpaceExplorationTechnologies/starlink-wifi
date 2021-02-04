//-----------------------------------------------------------------------------

/*
 * Copyright (c) 2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#include "tlv2Inc.h"
#include "halphy_internal.h"
#include "hal_tcmd.h"
#include "wmi_tcmd.h"
#include "tcmdHostInternal.h"
#include "utf_dev.h"
#include "testcmd.h"
#include "utf.h"
#include "cmdTPCCALHandler.h"
#include "cmdTPCCALPWRHandler.h"
#include "tpcCal.h"
#include "tcmd_api.h"
#include "codeswap_api.h"
#include "ar6000_eeprom.h"

#if defined(QCA9888)
// enable dpd in tpc olpc power calibration related stuff
#include "halphy_mc_paprd.h"
extern WHAL_PAPRD_INDIRECTION_TABLE   *pWhalPaprdIndirectionTable;
extern A_UINT32 getboardFlags();
TPC_OLPC_DPD_TUNING olpc_dpd_tuning;
#endif


// defines
#define NO_TPC_CAL  0
#define OLPC_SCHEME 1
#define CLPC_SCHEME 2
// TBD??
extern wlan_tcmd_dev_t utf_dev;
extern _CHIP_SPECIFIC_FUNC ChipFunc;
extern tcmd_tx_stat_t tcmdTxStat;
extern tcmd_state_t tcmd_state;
extern void utfRxStop(wlan_tcmd_dev_t *dev);
// function prototypes
extern void utfTxStop(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern void tcmd_cont_tx_cmd(wlan_tcmd_dev_t *dev, TCMD_CONT_TX *contTx);
extern void tcmd_cont_tx_data(wlan_tcmd_dev_t *dev, A_UINT32 dataRate,
                              A_UINT32 txPwr, A_UINT32 antenna,
                              A_UINT16 pktSz, A_UINT16 txPattern,
                              A_UINT32 PatternLength, A_UCHAR *pPatternData,
                              A_UINT32 aifswait, A_BOOL  retries,
                              A_BOOL txType, A_UINT32 shortGuard, A_UINT32 chainMask, A_BOOL disableContinuousTx,
                              A_UINT32 numPkts, A_UINT32 broadcast, A_UCHAR *srcmac, A_UCHAR *dstmac,
                              A_UCHAR *bssid, A_UINT32 numAggregates,A_UINT32 miscFlags);

#ifndef FPGA
extern A_BOOL gFTMCalInProgress;
#if defined(AR900B_HW_V2_WAR_RXPCU_HANG)
extern A_UINT32 g_enable_wdog_reset_trig;
#endif
#endif

extern void setRxDeaf(A_UINT32 dataRate);

CAL_LOOP *tpcCALLoop(void);

#define A_PRINTF_ONCE A_CMN(printf._printf)
#define MASK2CHAIN(x) ((x != 8)  ? (x >> 1) : 3)

extern A_UINT8 *getPreTxCalGainIdxPtr(A_UINT8 is2GHz);
extern A_INT8 *getPreTxCalDacGainPtr(A_UINT8 is2GHz);
extern A_UINT8 *getPreTxCalPaConfig(A_UINT8 is2GHz);
extern A_UINT8 *getPreTxCalPwrTarget(A_UINT8 is2GHz);
extern A_UINT8 *getPreTxCalPdadcTarget(A_UINT8 is2GHz);
extern A_UINT8 getTxPwrOffset(A_UINT8 is2GHz);
extern A_UINT8 *getPretxCalTgtPwrPtr(A_UINT8 is2GHz);
extern A_BOOL gEnableFastChannelChange;
extern A_UINT8 getTpcFlag(A_UINT8 is2GHz);

static void nextCAL(CAL_LOOP_NEXT_ACTION nextAction, CAL_LOOP *nextLoop);
static CAL_LOOP *getNextLoop(CAL_LOOP_NEXT_ACTION *nextAction);
static void sendCALDATA2Host(wlan_tcmd_dev_t *dev);
static void send2HostNextCAL(wlan_tcmd_dev_t *dev, CAL_LOOP *nextLoop);

// globals & static
SRAM_DATA
unsigned char  TLV_TXPARM_QDART_DEFAULT_BSSID[6]     = {0x50, 0x55, 0x55, 0x55, 0x55, 0x05};
SRAM_DATA
unsigned char  TLV_TXPARM_QDART_DEFAULT_TXSTATION[6] = {0x20, 0x22, 0x22, 0x22, 0x22, 0x02};
SRAM_DATA
unsigned char  TLV_TXPARM_QDART_DEFAULT_RXSTATION[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

extern TCMD_CONT_TX tx_tcmdParms;
//
// TPC calibration flow
//
// for testing only, the configuration data should come out of the board data file
//static A_UINT8 numTpcCALChans2G_dflt=3;
//static A_UINT8 numTpcCALChans5G_dflt=1;
#if 0
SRAM_DATA
//static A_UINT8 TpcCalChans2G_dflt[] = {112, 142, 172};
static A_UINT8 TpcCalChans2G_dflt[] = {};
SRAM_DATA
static A_UINT8 numTpcCALChans2G_dflt=(sizeof(TpcCalChans2G_dflt) / sizeof(A_UINT8));
SRAM_DATA
//static A_UINT8 TpcCalChans5G_dflt[] = {76, 96, 104, 140, 156, 164, 178, 186};
static A_UINT8 TpcCalChans5G_dflt[] = {76, 88, 92, 104, 140, 160, 180 , 189};
//static A_UINT8 TpcCalChans5G_dflt[] = {};
//static A_UINT8 TpcCalChans5G_dflt[] = {76, 92, 140, 160};
//static A_UINT8 TpcCalChans5G_dflt[] = {76, 140};
//static A_UINT8 TpcCalChans5G_dflt[] = {140};
SRAM_DATA
static A_UINT8 numTpcCALChans5G_dflt=(sizeof(TpcCalChans5G_dflt) / sizeof(A_UINT8));
//static A_UINT8 TpcCalChans5G_dflt[8] = {76};
//static A_UINT8 TpcCalChans5G_dflt[8] = {140};
SRAM_DATA
static A_UINT8 txCalGainIdx5G_dflt[] = {3,5,7,9,11,13,15,17,19,21,23,25,27};        //regular power
//static A_UINT8 txCalGainIdx5G_dflt[] = {1,3,5,7,9,11,13,15,17,19,21,23,25};  //best for low power/-ve testing
SRAM_DATA
static A_UINT8 txCalGainIdx2G_dflt[] = {5,7,9,11,13,15,17,19, 21,23,25,27,29};  //regular power
//static A_UINT8 txCalGainIdx2G_dflt[] = {3,5,7,9,11,13,15,17,19, 21,23,25,27};  //negative powers
SRAM_DATA
static A_INT8  txCalDacGain_dflt[] = {-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8};
SRAM_DATA
static A_UINT8 txCalPaCfg_dflt[]   = {0,0,0,0,1,1,2,2,3,4,5,6,7};
SRAM_DATA
static A_INT16 tgtMeasPwr_dflt_5G[] = {160, 132,104, 72, 40};      //regular power targets
//static A_INT16 tgtMeasPwr_dflt_5G[] = {160, 120,80, 40, 0};  //new targets for better accuracy below 0dbm
SRAM_DATA
static A_INT16 tgtMeasPwr_dflt_2G[] = {160, 132,104, 72, 40};      //regular power targets
//static A_INT16 tgtMeasPwr_dflt_2G[] = {160, 120,80, 40, 0};  //new targets for better accuracy below 0dbm
SRAM_DATA
int Max_CAL_Gains_Selected_4_GLUT = (sizeof(tgtMeasPwr_dflt_5G) / sizeof(A_INT16));
SRAM_DATA
static A_UINT8 tgtPdadc_dflt[] = {200, 125,80, 50, 30};
SRAM_DATA
int Max_CAL_Gains_Selected_4_PLUT = (sizeof(tgtPdadc_dflt) / sizeof(A_UINT8));
#endif  //0

extern int Max_TX_CAL_Gain_ID_5G, Max_TX_CAL_TGTPWR_ID_5G; //= (sizeof(txCalGainIdx5G_dflt) / sizeof(A_UINT8));
extern int Max_TX_CAL_Gain_ID_2G, Max_TX_CAL_TGTPWR_ID_2G; // = (sizeof(txCalGainIdx2G_dflt) / sizeof(A_UINT8));

SRAM_DATA
//static A_UINT8 chainMasks_dflt[]={0x1, 0x3, 0x7, 0xF};
//static A_UINT8 chainMasks_dflt[]={0xf, 0xf, 0xf, 0xF};
//static A_UINT8 chainMasks_dflt[]={0x1, 0x3, 0x5, 0x9};
static A_UINT8 chainMasks_dflt[]={0x1, 0x2, 0x4, 0x8};
SRAM_DATA
int Max_Num_Chains = (sizeof(chainMasks_dflt) / sizeof(A_UINT8));
SRAM_DATA
static A_UINT8 TPCScheme[]={NO_TPC_CAL, OLPC_SCHEME, CLPC_SCHEME};
//static A_TIMER tcmd_CAL_timer;
SRAM_DATA
static A_UINT8 TxPwrOffset_2G=0*8;  // 0dBm
SRAM_DATA
static A_UINT8 TxPwrOffset_5G=0*8;  // 0dBm
SRAM_DATA
/* static */ A_UINT8 DA_Gain_Settings[TPC_NUM_BAND][MAX_TX_CAL_GAIN_IDX] =
{ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 7, 6, 7, 6, 7, 7, 7, 7},
  {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 3, 3, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7} };

#ifndef FPGA
extern const A_UINT8 tbl_10log10[256];
#endif


SRAM_DATA
TPC_CAL_CFG                    tpcCfg[TPC_NUM_BAND];
SRAM_DATA
TPC_CAL_RESULT                 tpcCalResult[TPC_NUM_BAND][MAX_CAL_CHANS];
SRAM_DATA
TPC_CAL_POSTPROCESSED_RESULT   tpcCalPostProcResult[TPC_NUM_BAND][MAX_CAL_CHANS];

SRAM_DATA
TPC_CAL_STATE                  TpcCalState;

SRAM_DATA
static CAL_LOOP *nextLoop=NULL;
SRAM_DATA
static CAL_LOOP_NEXT_ACTION nextAction=PROG_NONE;

extern AR6000_EEPROM_STRUCT eepromStruct;

/*
 * Get TPC configuration from the board data file
 */
CODESWAP_MARK_EVICTABLE(void, getTPCCALCfgFromBoardData)
{
    /*
     *   take the default
     *   TBD? Integrate with Trang's code
     */
#define _TAKE_THE_DEFAULTS
#if defined(_TAKE_THE_DEFAULTS)
    A_UINT8 *txCalGainIdx5G_dflt, *txCalGainIdx2G_dflt;
    A_INT8 *txCalDacGain5G_dflt, *txCalDacGain2G_dflt;
    A_UINT8 *txCalPaCfg5G_dflt, *txCalPaCfg2G_dflt;
    A_UINT8 *tgtMeasPwr5G_dflt, *tgtMeasPwr2G_dflt;
    A_UINT8 *tgtPdadc5G_dflt, *tgtPdadc2G_dflt;
    A_UINT8 *tgtPwr5G_dflt, *tgtPwr2G_dflt;

    AR6000_EEPROM_STRUCT *pEepromStruct = &eepromStruct;
    AR6000_EEPROM *pEeprom = pEepromStruct->pEeprom;

    txCalGainIdx5G_dflt = getPreTxCalGainIdxPtr(FALSE);
    txCalGainIdx2G_dflt = getPreTxCalGainIdxPtr(TRUE);
    txCalDacGain5G_dflt = getPreTxCalDacGainPtr(FALSE);
    txCalDacGain2G_dflt = getPreTxCalDacGainPtr(TRUE);
    txCalPaCfg5G_dflt = getPreTxCalPaConfig(FALSE);
    txCalPaCfg2G_dflt = getPreTxCalPaConfig(TRUE);
    tgtMeasPwr5G_dflt = getPreTxCalPwrTarget(FALSE);
    tgtMeasPwr2G_dflt = getPreTxCalPwrTarget(TRUE);
    tgtPdadc5G_dflt = getPreTxCalPdadcTarget(FALSE);
    tgtPdadc2G_dflt = getPreTxCalPdadcTarget(TRUE);
    TxPwrOffset_2G = getTxPwrOffset(TRUE);
    TxPwrOffset_5G = getTxPwrOffset(FALSE);

    tgtPwr2G_dflt = getPretxCalTgtPwrPtr(TRUE);
    tgtPwr5G_dflt = getPretxCalTgtPwrPtr(FALSE);

    tpcCfg[0].band = TPC_5G;
    tpcCfg[1].band = TPC_2G;
    // LM
//#define _CAL_LM
#if defined(_CAL_LM)
    tpcCfg[0].tpcScheme = (TPC_OLPC | TPC_LM);
    tpcCfg[1].tpcScheme = (TPC_OLPC | TPC_LM);
#else
    tpcCfg[0].tpcScheme = (TPC_OLPC );
    tpcCfg[1].tpcScheme = (TPC_OLPC );
#endif
    //tpcCfg[0].numChan = numTpcCALChans5G_dflt;
    //tpcCfg[1].numChan = numTpcCALChans2G_dflt;
    memset((void*)&(tpcCfg[0].chans[0]), 0xff, sizeof(tpcCfg[0].chans));
    memset((void*)&(tpcCfg[1].chans[0]), 0xff, sizeof(tpcCfg[1].chans));

    // TBD? need a clean API to get all TPC cfg data
    {
    int i;
    A_UINT8  chans2G[MAX_CAL_CHANS_2G], chans5G[MAX_CAL_CHANS_5G];
extern void ar900BGetCALChans(A_UINT8 *chans2G, A_UINT8 *chans5G);
#define whalGetCALChans  ar900BGetCALChans
    whalGetCALChans(&(chans2G[0]), &(chans5G[0]));
    for (i=0;i<MAX_CAL_CHANS_2G;i++) {
        if (0xFF == chans2G[i]) break;
    }
    tpcCfg[1].numChan = i;
    for (i=0;i<MAX_CAL_CHANS_5G;i++) {
        if (0xFF == chans5G[i]) break;
    }
    tpcCfg[0].numChan = i;

#if 0
    //Temp workaround for beeliner, only support up to 8 channels for now
    if (tpcCfg[0].numChan > 8) {
    	tpcCfg[0].numChan = 8;
    }
#endif

#if 1

    // For dual band card, do not disable one band when both are enabled in BDF
    if ((pEeprom->baseEepHeader.opCapBrdFlags.opFlags & (WHAL_OPFLAGS_11A | WHAL_OPFLAGS_11G)) != WHAL_WLAN_11AG_CAPABILITY) {
        
        //Temp workaround for beeliner for board data files that erroneously have 2 and 5Ghz channels, for now assume 5GHz
        if (tpcCfg[1].numChan && tpcCfg[0].numChan) {
       	        //there are both 2 and 5GHz channels, so clear the 2GHz channels
    	        tpcCfg[1].numChan = 0;
        }
    }
#endif

    memcpy((void*)&(tpcCfg[0].chans[0]), (void*)&chans5G[0], (sizeof(chans5G[0]) * tpcCfg[0].numChan));
	memcpy((void*)&(tpcCfg[1].chans[0]), (void*)&chans2G[0], (sizeof(chans2G[0]) * tpcCfg[1].numChan));

#if 0
    A_PRINTF_ALWAYS("chans 5G: ");
    for (i=0;i<tpcCfg[0].numChan;i++) { A_PRINTF_ALWAYS("%d ", tpcCfg[0].chans[i]); }
    A_PRINTF_ALWAYS("chans 2G: ");
    for (i=0;i<tpcCfg[1].numChan;i++) { A_PRINTF_ALWAYS("%d ", tpcCfg[1].chans[i]); }
#endif

    }
#if 0
    memcpy((void*)&(tpcCfg[0].chans[0]), (void*)&TpcCalChans5G_dflt[0], sizeof(TpcCalChans5G_dflt));
    memcpy((void*)&(tpcCfg[1].chans[0]), (void*)&TpcCalChans2G_dflt[0], sizeof(TpcCalChans2G_dflt));
    { int i;
    A_PRINTF_ALWAYS("chans: ");
    for (i=0;i<numTpcCALChans5G_dflt;i++) {
        A_PRINTF_ALWAYS("%d ", tpcCfg[0].chans[i]);
    }
    }
    A_PRINTF_ALWAYS("\n");
#endif
    tpcCfg[TPC_5G].numChain = Max_Num_Chains; //MAX_NUM_CHAINS;
    tpcCfg[TPC_2G].numChain = Max_Num_Chains; //MAX_NUM_CHAINS;
    memcpy((void*)&(tpcCfg[TPC_5G].chainMasks[0]), (void*)&(chainMasks_dflt[0]), sizeof(chainMasks_dflt));
    memcpy((void*)&(tpcCfg[TPC_2G].chainMasks[0]), (void*)&(chainMasks_dflt[0]), sizeof(chainMasks_dflt));
extern void ar900BGetCALChainMasks(A_UINT8 *calMasks2G, A_UINT8 *numMasks2G, A_UINT8 *calMasks5G, A_UINT8 *numMasks5G);
#define whalGetCALChainMasks  ar900BGetCALChainMasks
	whalGetCALChainMasks(&(tpcCfg[TPC_2G].chainMasks[0]), &(tpcCfg[TPC_2G].numChain), &(tpcCfg[TPC_5G].chainMasks[0]), &(tpcCfg[TPC_5G].numChain));
    tpcCfg[TPC_5G].numGain = Max_TX_CAL_Gain_ID_5G;
//A_PRINTF_ONCE("After setting NumChain 5G = %d, chMask[0] = %x, chMsk[1] = %x\n", tpcCfg[TPC_5G].numChain, tpcCfg[TPC_5G].chainMasks[0], tpcCfg[TPC_5G].chainMasks[1]);
    tpcCfg[TPC_2G].numGain = Max_TX_CAL_Gain_ID_2G;
    tpcCfg[TPC_2G].numTgtPwrEst = Max_TX_CAL_TGTPWR_ID_2G;
    tpcCfg[TPC_5G].numTgtPwrEst = Max_TX_CAL_TGTPWR_ID_5G;
    memcpy((void*)&(tpcCfg[TPC_5G].tgtMeasPwr[0][0]), (void*)tgtMeasPwr5G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_5G].tgtMeasPwr[1][0]), (void*)tgtMeasPwr5G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_5G].tgtMeasPwr[2][0]), (void*)tgtMeasPwr5G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_5G].tgtMeasPwr[3][0]), (void*)tgtMeasPwr5G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtMeasPwr[0][0]), (void*)tgtMeasPwr2G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtMeasPwr[1][0]), (void*)tgtMeasPwr2G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtMeasPwr[2][0]), (void*)tgtMeasPwr2G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtMeasPwr[3][0]), (void*)tgtMeasPwr2G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_5G].tgtPdadc[0][0]), (void*)tgtPdadc5G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_5G].tgtPdadc[1][0]), (void*)tgtPdadc5G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_5G].tgtPdadc[2][0]), (void*)tgtPdadc5G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_5G].tgtPdadc[3][0]), (void*)tgtPdadc5G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtPdadc[0][0]), (void*)tgtPdadc2G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtPdadc[1][0]), (void*)tgtPdadc2G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtPdadc[2][0]), (void*)tgtPdadc2G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtPdadc[3][0]), (void*)tgtPdadc2G_dflt, NUM_CAL_GAINS_SELECTED_4_GLUT);
    memcpy((void*)&(tpcCfg[TPC_5G].gainIdx[0][0]), (void*)txCalGainIdx5G_dflt, Max_TX_CAL_Gain_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_5G].gainIdx[1][0]), (void*)txCalGainIdx5G_dflt, Max_TX_CAL_Gain_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_5G].gainIdx[2][0]), (void*)txCalGainIdx5G_dflt, Max_TX_CAL_Gain_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_5G].gainIdx[3][0]), (void*)txCalGainIdx5G_dflt, Max_TX_CAL_Gain_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_2G].gainIdx[0][0]), (void*)txCalGainIdx2G_dflt, Max_TX_CAL_Gain_ID_2G);
    memcpy((void*)&(tpcCfg[TPC_2G].gainIdx[1][0]), (void*)txCalGainIdx2G_dflt, Max_TX_CAL_Gain_ID_2G);
    memcpy((void*)&(tpcCfg[TPC_2G].gainIdx[2][0]), (void*)txCalGainIdx2G_dflt, Max_TX_CAL_Gain_ID_2G);
    memcpy((void*)&(tpcCfg[TPC_2G].gainIdx[3][0]), (void*)txCalGainIdx2G_dflt, Max_TX_CAL_Gain_ID_2G);
	#if defined(QCA9888)
    memcpy((void*)&(tpcCfg[TPC_5G].dacGain[0][0]), (void*)txCalDacGain5G_dflt, Max_TX_CAL_Gain_ID_5G);   //for now make assumption that #dacGains is same as gain indexes
    memcpy((void*)&(tpcCfg[TPC_5G].dacGain[1][0]), (void*)txCalDacGain5G_dflt, Max_TX_CAL_Gain_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_5G].dacGain[2][0]), (void*)txCalDacGain5G_dflt, Max_TX_CAL_Gain_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_5G].dacGain[3][0]), (void*)txCalDacGain5G_dflt, Max_TX_CAL_Gain_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_2G].dacGain[0][0]), (void*)txCalDacGain2G_dflt, Max_TX_CAL_Gain_ID_2G);
    memcpy((void*)&(tpcCfg[TPC_2G].dacGain[1][0]), (void*)txCalDacGain2G_dflt, Max_TX_CAL_Gain_ID_2G);
    memcpy((void*)&(tpcCfg[TPC_2G].dacGain[2][0]), (void*)txCalDacGain2G_dflt, Max_TX_CAL_Gain_ID_2G);
    memcpy((void*)&(tpcCfg[TPC_2G].dacGain[3][0]), (void*)txCalDacGain2G_dflt, Max_TX_CAL_Gain_ID_2G);
	#else
    memcpy((void*)&(tpcCfg[TPC_5G].dacGain[0][0]), (void*)txCalDacGain5G_dflt, WHAL_NUM_POINTS_TO_MEAS);   //for now make assumption that #dacGains is same as gain indexes
    memcpy((void*)&(tpcCfg[TPC_5G].dacGain[1][0]), (void*)txCalDacGain5G_dflt, WHAL_NUM_POINTS_TO_MEAS);
    memcpy((void*)&(tpcCfg[TPC_5G].dacGain[2][0]), (void*)txCalDacGain5G_dflt, WHAL_NUM_POINTS_TO_MEAS);
    memcpy((void*)&(tpcCfg[TPC_5G].dacGain[3][0]), (void*)txCalDacGain5G_dflt, WHAL_NUM_POINTS_TO_MEAS);
    memcpy((void*)&(tpcCfg[TPC_2G].dacGain[0][0]), (void*)txCalDacGain2G_dflt, WHAL_NUM_POINTS_TO_MEAS);
    memcpy((void*)&(tpcCfg[TPC_2G].dacGain[1][0]), (void*)txCalDacGain2G_dflt, WHAL_NUM_POINTS_TO_MEAS);
    memcpy((void*)&(tpcCfg[TPC_2G].dacGain[2][0]), (void*)txCalDacGain2G_dflt, WHAL_NUM_POINTS_TO_MEAS);
    memcpy((void*)&(tpcCfg[TPC_2G].dacGain[3][0]), (void*)txCalDacGain2G_dflt, WHAL_NUM_POINTS_TO_MEAS);
	#endif
    memcpy((void*)&(tpcCfg[TPC_5G].paCfg[0][0]),   (void*)txCalPaCfg5G_dflt, NUM_CAL_GAINS);           //Need to fix this?
    memcpy((void*)&(tpcCfg[TPC_5G].paCfg[1][0]),   (void*)txCalPaCfg5G_dflt, NUM_CAL_GAINS);
    memcpy((void*)&(tpcCfg[TPC_5G].paCfg[2][0]),   (void*)txCalPaCfg5G_dflt, NUM_CAL_GAINS);
    memcpy((void*)&(tpcCfg[TPC_5G].paCfg[3][0]),   (void*)txCalPaCfg5G_dflt, NUM_CAL_GAINS);
    memcpy((void*)&(tpcCfg[TPC_2G].paCfg[0][0]),   (void*)txCalPaCfg2G_dflt, NUM_CAL_GAINS);
    memcpy((void*)&(tpcCfg[TPC_2G].paCfg[1][0]),   (void*)txCalPaCfg2G_dflt, NUM_CAL_GAINS);
    memcpy((void*)&(tpcCfg[TPC_2G].paCfg[2][0]),   (void*)txCalPaCfg2G_dflt, NUM_CAL_GAINS);
    memcpy((void*)&(tpcCfg[TPC_2G].paCfg[3][0]),   (void*)txCalPaCfg2G_dflt, NUM_CAL_GAINS);

    memcpy((void*)&(tpcCfg[TPC_5G].tgtPwrEst[0][0]), (void*)tgtPwr5G_dflt, Max_TX_CAL_TGTPWR_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_5G].tgtPwrEst[1][0]), (void*)tgtPwr5G_dflt, Max_TX_CAL_TGTPWR_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_5G].tgtPwrEst[2][0]), (void*)tgtPwr5G_dflt, Max_TX_CAL_TGTPWR_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_5G].tgtPwrEst[3][0]), (void*)tgtPwr5G_dflt, Max_TX_CAL_TGTPWR_ID_5G);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtPwrEst[0][0]), (void*)tgtPwr2G_dflt, Max_TX_CAL_TGTPWR_ID_2G);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtPwrEst[1][0]), (void*)tgtPwr2G_dflt, Max_TX_CAL_TGTPWR_ID_2G);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtPwrEst[2][0]), (void*)tgtPwr2G_dflt, Max_TX_CAL_TGTPWR_ID_2G);
    memcpy((void*)&(tpcCfg[TPC_2G].tgtPwrEst[3][0]), (void*)tgtPwr2G_dflt, Max_TX_CAL_TGTPWR_ID_2G);

    tpcCfg[0].pdadcThresh = 210;
    tpcCfg[1].pdadcThresh = 210;
#endif

#if defined(_FETCH_FROM_BRDDATA)
#endif //#if defined(_FETCH_FROM_BRDDATA)

    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void, getTPCCALCfgFromBoardData);
extern void getTPCCALCfgFromBoardData();

SRAM_DATA
A_UINT8 freq2G[MAX_CAL_CHANS];
SRAM_DATA
A_UINT8 freq5G[MAX_CAL_CHANS];
SRAM_TEXT
static void send2Host(wlan_tcmd_dev_t *dev)
{
    /*
     * Send the CAL channels to host to measure the power
     * total measurements should be:
     *    (numChan2G + numChan5G) * numChains
     */
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    int i;
    for (i=0;i<tpcCfg[TPC_2G].numChan;i++) {
        freq2G[i] = tpcCfg[TPC_2G].chans[i];
    }
    for (i=0;i<tpcCfg[TPC_5G].numChan;i++) {
        freq5G[i] = tpcCfg[TPC_5G].chans[i];
    }

    pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp(CMD_TPCCALRSP, 18, PARM_NUMFREQ2G, tpcCfg[TPC_2G].numChan,
        PARM_NUMFREQ5G, tpcCfg[TPC_5G].numChan, PARM_NUMCHAIN, tpcCfg[TPC_2G].numChain,
        PARM_NUMCALPT2G, tpcCfg[TPC_2G].numGain, PARM_FREQ2G, tpcCfg[TPC_2G].numChan, 0, &(freq2G[0]),
        PARM_FREQ5G, tpcCfg[TPC_5G].numChan, 0, &(freq5G[0]),
        PARM_MISCFLAGS, (TPCCAL_CALINFO));

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

//    A_PRINTF_ALWAYS("2Host len %d, stream 0x%x\n", cmdStreamLen, (int)rCmdStream);
    wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,CMD_TPCCALRSP,(A_INT8*)rCmdStream);

    return;
}

#if 0
SRAM_TEXT
static void configOLPC_freqIndependent(void)
{
    // Any freq independent settings
    return;
}

SRAM_TEXT
static void configCLPC_freqIndependent(void)
{
    // Any freq independent settings
    //whalSetTpcForceClpcPacket(freq, gainIdx, 1);
}
#endif

//extern void
//tcmd_get_channel(A_UINT32 freq, A_UINT32 wlanMode, A_UINT32 bandwidth, WHAL_CHANNEL *chan);
SRAM_TEXT
static void tpcFullReset(A_UINT8 freq)
{
#if 0
    WHAL_CHANNEL chan;

    tcmd_get_channel(freq, 0, 0, &chan);
    whalReset(&chan, 0, WHAL_RESTORE_SW_SETTINGS, WHAL_RESET_CAUSE_CHANNEL_CHANGE);
#endif
    return;
}

SRAM_TEXT
static void tpcProgSynth(A_UINT8 freq)
{
    // TBD?
    tpcFullReset(freq);
    return;
}

SRAM_TEXT
static void updateTPCState(A_UINT8 freqInByte, A_UINT8 band)
{
    TpcCalState.freqInByte = freqInByte;
    TpcCalState.calBand = band;

    // update current chan info
}

#if 0
static void setForcedGain(FORCED_GAIN_TX_PARM *txParm)
{
    whalSetTpcForceClpcPacket(txParm->chan, txParm->gainIdx, 1);
}
#endif

SRAM_TEXT
static void progChainMask(A_UINT8 chainMask)
{
    // TBD??
    return;
}

SRAM_TEXT
static void configChan(A_UINT8 freq, A_UINT8 band)
{
    if (band != TpcCalState.calBand) {
        /* call full reset */
        //A_PRINTF_ALWAYS("fR %d %d %d\n", band,TpcCalState.calBand,freq);
        tpcFullReset(freq);
    }
    else {
        //A_PRINTF_ALWAYS("pSync %d %d %d\n", band,TpcCalState.calBand,freq);
        tpcProgSynth(freq);
    }

    // update TPCState
    updateTPCState(freq, band);

    // any channel dependent configuration
    //whalSetTpcForceClpcPacket(freq, gainIdx, 1);

    return;
}

SRAM_TEXT
static A_BOOL setCCA(void)
{
//extern void ar6000DisableCCA(void);
//    ar6000DisableCCA();
    whalEnableAni(TRUE);
    whalSetAniOfdmImmunLevel(15);
    setRxDeaf(4);
    return(TRUE);
}

SRAM_TEXT
static A_BOOL txDone(void)
{
    //TBD?
    return(TRUE);
}

SRAM_TEXT
static void ftmTxStop(FORCED_GAIN_TX_PARM *txParm)
{
    //A_PRINTF_ALWAYS("txSp\n");
    utfTxStop(&utf_dev, NULL);
    return;
}

/*SRAM_TEXT
static void ftmTxStart(FORCED_GAIN_TX_PARM *txParms)
*/
CODESWAP_MARK_EVICTABLE(void, ftmTxStart, FORCED_GAIN_TX_PARM *txParms)
{
    // TBD??
    int count=1000;
    A_UINT8 prevTxDone=0, CCASet=0;

	if (tcmd_state.tcmdRxGo == TCMD_CONT_RX_ON && tcmd_state.tcmdTxGo == TCMD_CONT_TX_OFF)
		utfRxStop(&utf_dev);
	if (tcmd_state.tcmdRxGo == TCMD_CONT_RX_TX_ON || tcmd_state.tcmdTxGo != TCMD_CONT_TX_OFF)
		ftmTxStop(txParms);

    while (count-- >0) {
        if (txDone()) {
            prevTxDone=1;
            break;
        }
    }
    count=1000;
    while (count-- >0) {
        if (setCCA()) {
            CCASet =1;
            break;
        }
    }

    if ((1==prevTxDone) && (1==CCASet)) {
//cascade   	A_DELAY_USECS(200000);

        //TCMD_CONT_TX contTx;
        A_MEMSET(&tx_tcmdParms,0,sizeof(TCMD_CONT_TX));
        tx_tcmdParms.freq = BYTE2FREQ((txParms->chan), (TPC_2G == txParms->band));
        tx_tcmdParms.wlanMode=TCMD_WLAN_MODE_HT20;
        tx_tcmdParms.bandwidth=0;
        tx_tcmdParms.dataRate=4;
        tx_tcmdParms.txPwr=28;
        tx_tcmdParms.antenna=0;
        tx_tcmdParms.pktSz=1500;
        tx_tcmdParms.aifsn=0;
        tx_tcmdParms.txPattern=1;
        tx_tcmdParms.nPattern=0;
        //tx_tcmdParms.dataPattern={0};
        tx_tcmdParms.mode=TCMD_CONT_TX_CLPCPKT | 0x100;
        tx_tcmdParms.shortGuard=0;
        //tx_tcmdParms.txChain=0xf;
        //tx_tcmdParms.txChain=0x3;
        tx_tcmdParms.txChain= txParms->chainMask;
        tx_tcmdParms.broadcast=1;
        if ((tpcCfg[0].tpcScheme & TPC_LM) || (tpcCfg[1].tpcScheme & TPC_LM)) {
            tx_tcmdParms.numPackets=500;
        }
        else {
            tx_tcmdParms.numPackets=0;
        }
        //tx_tcmdParms.numPackets=0;
        if (txParms->gainIdx >= MAX_TX_CAL_GAIN_IDX) txParms->gainIdx = MAX_TX_CAL_GAIN_IDX - 1;

        tx_tcmdParms.gainIdx = txParms->gainIdx;
        tx_tcmdParms.dacGain = txParms->dacGain;
        tx_tcmdParms.paConfig = txParms->paCfg;
        A_MEMCPY((void*)tx_tcmdParms.rxStation, TLV_TXPARM_QDART_DEFAULT_RXSTATION, ATH_MAC_LEN);
        A_MEMCPY((void*)tx_tcmdParms.txStation, TLV_TXPARM_QDART_DEFAULT_TXSTATION, ATH_MAC_LEN);
        A_MEMCPY((void*)tx_tcmdParms.bssid, TLV_TXPARM_QDART_DEFAULT_BSSID, ATH_MAC_LEN);
        tx_tcmdParms.agg=0;//1;
        #if defined(QCA9888)
        if(whalPaprdTpcOlpcTuningEnableGet()){
            int i = 0;

            tx_tcmdParms.miscFlags|=PAPRD_ENA_MASK ;
            tx_tcmdParms.tpcm = TPC_FORCED_GAINIDX;

            for (i = 0; i < WHAL_NUM_POINTS_TO_MEAS; i++){
                if(olpc_dpd_tuning.tuning_gain[i] == 0){
                    olpc_dpd_tuning.tuning_gain[i] = txParms->gainIdx;
                    break;
                }
            }

        } else {
            tx_tcmdParms.miscFlags=0;
            tx_tcmdParms.tpcm=0;
        }
        #else
            tx_tcmdParms.miscFlags=0;
        #endif
//      A_PRINTF_ALWAYS("txS %d %d %d\n", txParms->gainIdx, txParms->dacGain, txParms->paCfg);
        //tcmd_cont_tx_data(&utf_dev, ATH_RATE_6_5M, 28, 0, 1500, 4, 0, 0, 0, 1, 2, 0, txParms->chainMask, FALSE, 0, 1, TLV_TXPARM_QDART_DEFAULT_TXSTATION, TLV_TXPARM_QDART_DEFAULT_RXSTATION, TLV_TXPARM_QDART_DEFAULT_BSSID, 1, 0);
        tcmd_cont_tx_cmd(&utf_dev, &tx_tcmdParms);
//        A_PRINTF_ALWAYS("tx d\n");
    }

    return;
}

#if defined(QCA9888)
SRAM_TEXT
A_BOOL OlpcDpdTuningPowerDoneGet(A_UINT8 gainIdx)
{
    int i = 0;
    for(i = 0; i < WHAL_NUM_POINTS_TO_MEAS; i++){
        if(olpc_dpd_tuning.tuning_gain[i] == gainIdx)
            return olpc_dpd_tuning.tpc_got_power[i];
    }

    return 0;
}

SRAM_TEXT
A_BOOL OlpcDpdTuningPowerDoneSet(A_UINT8 gainIdx)
{
    int i = 0;
    for(i = 0; i < WHAL_NUM_POINTS_TO_MEAS; i++){
        if(olpc_dpd_tuning.tuning_gain[i] == gainIdx)
        olpc_dpd_tuning.tpc_got_power[i] = 1;
    }

    return 0;
}

SRAM_TEXT
void InitOlpcDpdTuningStruct()
{
    int i = 0;

    for(i = 0; i < WHAL_NUM_POINTS_TO_MEAS; i++){
        olpc_dpd_tuning.tuning_gain[i] = 0;
        olpc_dpd_tuning.tpc_got_power[i] = 0;
    }
}
#endif

CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void, ftmTxStart, FORCED_GAIN_TX_PARM *);
extern void ftmTxStart(FORCED_GAIN_TX_PARM *txParms);

/*
 * CAL cmd processor
 */
SRAM_TEXT
void tpcCAL(void *parms)
{
/*
 * OLPC CAL scheme
 *
 * 1. Configure OLPC,
 * 1.1 the first point: txGainIdx, DAC, paConfig
 * 1.2 the second point: how many dB off from the 1st
 * 1.3 the thrid point: how many dB off from the 2nd
 * 1.4 the fourth ...
 * 1.5 the fifth ...
 * 2. Ensure DPD off, tx on the 1st point
 *    mesure the power, compare with targeted power
 *    vomppute adjustment
 * 3. tx with the new gain IDX on the 1st point,
 *    simply note the measured power, no more comparison
 * 4. back off per configuration for the 2nd point,
 *    computer the new gain
 *    tx with the computed gain, record the measured power
 * 5. repeat for the rest points
 *
 * The list mode handshake could be designed as following:
 *     Ctrl                            DUT
 *           ->pwrMeasAvail(0)         getFirstPwrMeasurement
 *           <-ch/chain/#meas
 *           ->startTx                 txPerChan
 *           ...tx
 *           <-done
 *           ->pwrMeasAvail(results)   getCALPwrMeasurement
 *           <-ch/chain/#meas
 *           ...DUT may DPD training   doDPDTraining, if configured so
 *           ->startTx                 txPerChan
 *           ...tx
 *           <-done
 *           ->pwrMeasAvail(results)   getCALPwrMeasurement
 *           <-AllDone
 *           ->pwrMeasAvail(0)         ...
 *
 */

/*
 * CLPC CAL scheme
 *
 * 1. CAL GLUT table (basically OLPC CAL)
 * 2. Configure CLPC, 1dB backoff from the PSAT point
 * 3. Find the PSAT transition point
 * 4. Start from there, back off 1dB, to get 10 points
 *    the measured power and pdadc reading
 *    for HalPhy to populatel the PLUT table
 * 5. HalPhy computes ALUT based on the ?? (refer to ar6320_tpc_config.c)
 *
 */

    //FORCED_GAIN_TX_PARM txParm;
    //A_UINT32            adc;
    //int i,j,k,band, n;
    int i, n;
    A_UINT8 tpcScheme;
    CMD_TPCCAL_PARMS *pParms = (CMD_TPCCAL_PARMS *)parms;

    /*
     * Init TPC CAL relevant, e.g. state
     */
    memset((void*)&TpcCalState, 0, sizeof(TPC_CAL_STATE));
    // TBD: ?? for now, to keep the compiler happy
    pParms->radioId = 0;
    n=0;

    // get TPC calibration settings from the board data file
    /*
       1. CLPC or OLPC;
       2. Number of CAL channels (always TPC CAL per chain);
     */
    memset((void *)tpcCfg, 0, sizeof(tpcCfg));
    //memset((void *)&(tpcCfg[0].chans[0]), 0xff, MAX_CAL_CHANS_5G);
    //memset((void *)&(tpcCfg[1].chans[0]), 0xff, MAX_CAL_CHANS_2G);
    getTPCCALCfgFromBoardData();

    // determine TPC flow, LM or ping-poong
    // else ping-pong mode by default

    // Inform the ctrl the total number of measurements
    /* total power measurement:
     *    numChans2G * numChains * numGains2G + numChans5G * numChains * numGains5G
     */
    if ((tpcCfg[0].tpcScheme & TPC_LM) || (tpcCfg[1].tpcScheme & TPC_LM)) {
        send2Host(&utf_dev);
    }

    /*
     * Setup per TPC scheme
     */
    gEnableFastChannelChange = TRUE;
#ifndef FPGA
    gFTMCalInProgress = TRUE;
	//whalEepromSetCalVersion();
#if defined(AR900B_HW_V2_WAR_RXPCU_HANG)
    g_enable_wdog_reset_trig = 0;
#endif
	#if defined(QCA9888)
	InitOlpcDpdTuningStruct();
	whalPaprdTpcOlpcTuningEnableSet(0);

	if (getboardFlags() & WHAL_BOARD_TPC_OLPC_ENABLE_PAPRD_5G){
	    gEnableFastChannelChange = FALSE;
        //hard code
	    whalPaprdTpcOlpcTuningEnableSet(1);
	}

	#endif
#endif

    for (i=0, tpcScheme=TPCScheme[i]; i<2; i++) {
        switch (tpcScheme) {
            case NO_TPC_CAL:
                break;
            case CLPC_SCHEME:
//                configCLPC_freqIndependent();
                break;
            case OLPC_SCHEME:
//                configOLPC_freqIndependent();
                break;
        }
    }

    /*
     * Loop through channels, chains, hopefully by changing minimal,
     * e.g. program chain mask for chains, synthesizer only for channel change
     */
    if ((tpcCfg[0].tpcScheme & TPC_LM) || (tpcCfg[1].tpcScheme & TPC_LM)) {
        tpcCALLoop();
    }
    else {  // ping pong mode
        if (NULL != (nextLoop = getNextLoop(&nextAction))) {
            // TBD: start tx
            nextCAL(nextAction, nextLoop);

            // send next CAL action
            send2HostNextCAL(&utf_dev, nextLoop);
        }
    }

    return;
}

SRAM_TEXT
static void send2HostNextCAL(wlan_tcmd_dev_t *dev, CAL_LOOP *nextLoop)
{
    /*
     * Send the CAL channels to host to measure the power
     * total measurements should be:
     *    (numChan2G + numChan5G) * numChains
     */
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    A_UINT8 numChan2G=0, numChan5G=0, numChain=0, numCalPt=0, gainVal[5], chainMask[5], tgtPwrEst[5];
    A_INT8 dacGain[5];

    #if defined(QCA9888)
	memset(&tgtPwrEst[0], 0, 5);
    if(whalPaprdTpcOlpcTuningEnableGet()){
        if(!whalPaprdTrainingCompleted()){
            //A_PRINTF_ALWAYS("\n  %s => dpd training gainIdx %d...NOT YET.....\n", __FUNCTION__, TpcCalState.txParm.gainIdx);
            return ;
        }
    }
    #endif
    gainVal[0] = TpcCalState.txParm.gainIdx;
    chainMask[0] = TpcCalState.txParm.chainMask;
    dacGain[0] = TpcCalState.txParm.dacGain;
    tgtPwrEst[0] = TpcCalState.txParm.tgtPwrEst;
    #if defined(QCA9888)
    if(whalPaprdTpcOlpcTuningEnableGet()){
        memset(&tgtPwrEst[1], 0, 4);
    }
    #endif

    if (TPC_2G == nextLoop->numBand) {
        freq2G[0] = tpcCfg[TPC_2G].chans[nextLoop->idxChan];
        numChan2G=1;
        numChain= tpcCfg[TPC_2G].numChain;
        numCalPt= tpcCfg[TPC_2G].numGain;
    }
    else if (TPC_5G == nextLoop->numBand) {
        freq5G[0] = tpcCfg[TPC_5G].chans[nextLoop->idxChan];
        numChan5G=1;
        numChain= tpcCfg[TPC_5G].numChain;
        numCalPt= tpcCfg[TPC_5G].numGain;
    }
    pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp(CMD_TPCCALRSP, 42,
                PARM_NUMFREQ2G, numChan2G, PARM_FREQ2G, numChan2G, 0, &(freq2G[0]),
                PARM_NUMFREQ5G, numChan5G, PARM_FREQ5G, numChan5G, 0, &(freq5G[0]),
                PARM_MISCFLAGS, (TPCCAL_CALINFO),
                PARM_TXGAINS2G, 1, 0, &(gainVal[0]),
                PARM_TXGAINS5G, 1, 0, &(gainVal[0]),
                PARM_DACGAINS2G, 1, 0, &(dacGain[0]),
                PARM_DACGAINS5G, 1, 0, &(dacGain[0]),
                PARM_CHAINMASKS, 1, 0, &(chainMask[0]),
                PARM_TGTPWR2G, 1, 0, &(tgtPwrEst[0]),
                PARM_TGTPWR5G, 1, 0, &(tgtPwrEst[0]));

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

  //  A_PRINTF_ALWAYS("send2HostNextCAL @@@@@@@@@@@@@@@@ gainVal =  %d, chainMask 0x%x, dacGain = %d\n", gainVal[0], chainMask[0], dacGain[0]);
  //  A_PRINTF_ALWAYS("2Host len %d, stream 0x%x, PARM_TGTPWR2G=%d, PARM_TGTPWR5G=%d\n", cmdStreamLen, (int)rCmdStream, targetPwr[0], targetPwr[0]);
    wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,CMD_TPCCALRSP,(A_INT8*)rCmdStream);

    return;
}

SRAM_TEXT
CAL_LOOP *tpcCALLoop(void)
{
    #if defined(QCA9888)
    if(whalPaprdTpcOlpcTuningEnableGet()){
        if(!whalPaprdTrainingCompleted()){
            //A_PRINTF_ALWAYS("\n %s => dpd training gainIdx %d...NOT YET.....\n", __FUNCTION__, TpcCalState.txParm.gainIdx);
            return nextLoop;
        }
        if(!OlpcDpdTuningPowerDoneGet(TpcCalState.txParm.gainIdx)){
            //A_PRINTF_ALWAYS("\n %s => power got gainIdx %d...NOT YET.....\n", __FUNCTION__, TpcCalState.txParm.gainIdx);
            send2HostNextCAL(&utf_dev, nextLoop);
            return nextLoop;
        }
    }
    #endif

    if ((tpcCfg[0].tpcScheme & TPC_LM) || (tpcCfg[1].tpcScheme & TPC_LM)) {
        while (NULL != (nextLoop = getNextLoop(&nextAction))) {
#if 0
            A_PRINTF_ALWAYS("next AI %d: band %d ch %d chain %d calPt %d\n", nextAction, nextLoop->numBand,
                nextLoop->idxChan, nextLoop->idxChain, nextLoop->idxCalPt);
#endif
            nextCAL(nextAction, nextLoop);
        }
    }
    else {
        // if nextLoop is not NULL, there is tx going on, stop it
        if (NULL != nextLoop) {
            ftmTxStop(&(TpcCalState.txParm));
        }

        if (NULL != (nextLoop = getNextLoop(&nextAction))) {
//            A_PRINTF_ALWAYS("next cal\n");
            nextCAL(nextAction, nextLoop);
            // send next CAL action
            send2HostNextCAL(&utf_dev, nextLoop);
        }
        else {
            // send all CAL data
//            A_PRINTF_ALWAYS("cal data\n");
			//FJC this is only needed in LM
			if ((tpcCfg[TPC_2G].tpcScheme & TPC_LM) || (tpcCfg[TPC_5G].tpcScheme & TPC_LM)) {
            	sendCALDATA2Host(&utf_dev);
			}
        }
#if 0
        if (NULL != nextLoop) {
            nextCAL(nextAction, nextLoop);
            if (NULL != (nextLoop = getNextLoop(&nextAction))) {
                A_PRINTF_ALWAYS("next cal\n");
                // send next CAL action
                send2HostNextCAL(&utf_dev, nextLoop);
            }
            else {
                // send all CAL data
                A_PRINTF_ALWAYS("cal data\n");
                sendCALDATA2Host(&utf_dev);
            }
        }
        else { A_PRINTF_ALWAYS("next lp null\n"); }
#endif
    }
    return(nextLoop);
}

SRAM_TEXT
static CAL_LOOP *getNextLoop(CAL_LOOP_NEXT_ACTION *nextAction)
{
    CAL_LOOP *curLoop=&(TpcCalState.calLoop);
    static A_UINT8 veryFirstCalPt=1;
	#if defined(QCA9888)
    #if 0
    //enable dpd in tpc calibraion when power is above 10
    if(tpcCalResult[TpcCalState.calLoop.numBand][TpcCalState.calLoop.idxChan].measPwr[TpcCalState.calLoop.idxChain][TpcCalState.calLoop.idxCalPt] > 80){
        whalPaprdTpcOlpcTuningEnableSet(1);
    }
    #endif
	#endif
    *nextAction= PROG_NONE;
    if (1 == veryFirstCalPt) {
        veryFirstCalPt=0;
        curLoop->idxCalPt = -1;  // the very first point should start from -1
		curLoop->gainSearchDone = 0;
        *nextAction= PROG_BAND;
        curLoop->calFail = 0;
        curLoop->calAttempts = 0;
        curLoop->failedGain = 0xff;
    }

    if(curLoop->calFail) {
//        gEnableFastChannelChange = FALSE;
        //redo this measure and previous one
        if(curLoop->idxCalPt > 0) {
            curLoop->failedGain = curLoop->idxCalPt;
            curLoop->idxCalPt--;
        }
//A_PRINTF_ONCE("Faild Gain %d, new gain idx %d\n", curLoop->failedGain, curLoop->idxCalPt);
//A_DELAY_USECS(100000);

        curLoop->calAttempts++;
        if (curLoop->calAttempts > 5) {
#ifndef FPGA
            gFTMCalInProgress = FALSE;
#if defined(AR900B_HW_V2_WAR_RXPCU_HANG)
            g_enable_wdog_reset_trig = 1;
#endif
	        #if defined(QCA9888)
	        whalPaprdTpcOlpcTuningEnableSet(0);
	        #endif
#endif
            return(NULL);
        } else {
            return(curLoop);
        }
    } else {
        if((curLoop->failedGain == 0xff) || (curLoop->idxCalPt >= curLoop->failedGain)) {
            curLoop->calAttempts = 0;
            curLoop->failedGain = 0xff;
        }
    }

//    A_PRINTF_ALWAYS("bef, band %d ch %d numCh %d chain %d gain %d\n", curLoop->numBand, curLoop->idxChan, tpcCfg[curLoop->numBand].numChan, curLoop->idxChain, curLoop->idxCalPt);
    if (0 == tpcCfg[curLoop->numBand].numChan) {
        if (++(curLoop->numBand) >= TPC_NUM_BAND) {
//            A_PRINTF_ALWAYS("end loop0\n");
            return(NULL);
        }
        else {
            *nextAction = PROG_BAND;
            if (0 == tpcCfg[curLoop->numBand].numChan) {
//                A_PRINTF_ALWAYS("end loop1\n");
                return(NULL);
            }
        }
    }

    if ((++(curLoop->idxCalPt) < tpcCfg[curLoop->numBand].numGain) && (curLoop->gainSearchDone == 0)){
        //A_PRINTF_ONCE("inc calPt %d ch %d chn %d, numGain %d\n", curLoop->idxCalPt, curLoop->idxChan, curLoop->idxChain, tpcCfg[curLoop->numBand].numGain);
        return(curLoop);
    }
    else {
        curLoop->idxCalPt=0;
		curLoop->gainSearchDone=0;
        if (++(curLoop->idxChain) < tpcCfg[curLoop->numBand].numChain) {
            *nextAction = PROG_CHAIN_MASK;
//            A_PRINTF_ONCE("inc chain AI %d %d\n", *nextAction, curLoop->idxChain);
            return(curLoop);
        }
        else {
            curLoop->idxChain=0;
            if (++(curLoop->idxChan) < tpcCfg[curLoop->numBand].numChan) {
                *nextAction = PROG_CHAN;
//                A_PRINTF_ONCE("inc ch AI %d %d\n", *nextAction, curLoop->idxChan);
                return(curLoop);
            }
            else {
                curLoop->idxChan=0;
                curLoop->numBand++;
                if ((curLoop->numBand < TPC_NUM_BAND) && (0 != tpcCfg[curLoop->numBand].numChan)) {
                    *nextAction = PROG_BAND;
//                    A_PRINTF_ALWAYS("inc band AI %d %d\n", *nextAction, curLoop->numBand);
                    return(curLoop);
                }
                else {
//                    A_PRINTF_ALWAYS("end loop\n");
                    veryFirstCalPt=1;  //FJC - reset for next time
                    return(NULL);
                }
            }
        }
    }

    return(NULL);
}

SRAM_TEXT
static void nextCAL(CAL_LOOP_NEXT_ACTION nextAction, CAL_LOOP *nextLoop)
{
    A_UINT8 band, idxChan, idxChain, idxCalPt;
    A_UINT8 adcArr[4];
    A_UINT32 adc;

    band = TpcCalState.txParm.band = (nextLoop->numBand % 2);   // TPC_2G == 0,
    idxChan = nextLoop->idxChan;
    TpcCalState.txParm.chan = tpcCfg[nextLoop->numBand].chans[nextLoop->idxChan];
#if 0
    {int i;
    if (4 == TpcCalState.txParm.chan) {
        A_PRINTF_ALWAYS("chans: ");
        for (i=0;i<numTpcCALChans5G_dflt;i++) {
            A_PRINTF_ALWAYS("%d ", tpcCfg[0].chans[i]);
        }
    }
    }
#endif
    idxChain = TpcCalState.txParm.chain = nextLoop->idxChain;
    TpcCalState.txParm.chainMask = tpcCfg[nextLoop->numBand].chainMasks[nextLoop->idxChain];
    idxCalPt = nextLoop->idxCalPt;

    if (PROG_BAND == nextAction) {
        // full reset
        // whalRest
        tpcFullReset(tpcCfg[band].chans[idxChan]);
    }
    else if (PROG_CHAN == nextAction) {
        configChan(tpcCfg[band].chans[idxChan], band);
    }
    else if (PROG_CHAIN_MASK == nextAction) {
        progChainMask(tpcCfg[band].chainMasks[idxChain]);
    }

    #if defined(QCA9888)
    if(whalPaprdTpcOlpcTuningEnableGet()){
        if((PROG_BAND == nextAction) || (PROG_CHAN == nextAction) ||(PROG_CHAIN_MASK == nextAction)){
            InitOlpcDpdTuningStruct();
        }
    }
    #endif

    TpcCalState.txParm.gainIdx = tpcCfg[band].gainIdx[idxChain][idxCalPt];  //FJC changed chan to Chain
    //TpcCalState.txParm.gainIdx = 20;  // testing
    TpcCalState.txParm.dacGain = tpcCfg[band].dacGain[idxChain][idxCalPt];  //FJC changed chan to Chain
    if (idxCalPt >= tpcCfg[band].numTgtPwrEst)
        TpcCalState.txParm.tgtPwrEst = tpcCfg[band].tgtPwrEst[idxChain][tpcCfg[band].numTgtPwrEst - 1];
    else
        TpcCalState.txParm.tgtPwrEst = tpcCfg[band].tgtPwrEst[idxChain][idxCalPt];

    //TpcCalState.txParm.paCfg   = tpcCfg[band].paCfg[idxChain][idxCalPt];  //FJC changed chan to Chain
    TpcCalState.txParm.paCfg   = DA_Gain_Settings[band][TpcCalState.txParm.gainIdx];

//    A_PRINTF_ALWAYS("sG %d %d %d %d %d ", TpcCalState.txParm.band, TpcCalState.txParm.chan, TpcCalState.txParm.chain, TpcCalState.txParm.gainIdx, TpcCalState.txParm.dacGain);
//    A_PRINTF_ALWAYS("%d\n", TpcCalState.txParm.paCfg);
    //setForcedGain(&txParm);
    ftmTxStart(&(TpcCalState.txParm));

// 	A_DELAY_USECS(200000);
//FJC remove delay, waiting for 2 packets to start in utfTxStartInternal() A_DELAY_USECS(2000);
//	A_DELAY_USECS(2000);
//	A_PRINTF("num packets = %d\n", tcmdTxStat.totalPkt);

    // TBD: shouldonly need to checktx done, then read pdadc, NO delay !!!!!

    //A_PRINTF_ALWAYS("d done\n");
    // read pdet
    //whalGetPdetPdadcPacket(TpcCalState.txParm.chan, TpcCalState.txParm.chainMask, TpcCalState.txParm.dacGain,
    //   TpcCalState.txParm.paCfg, adcArr);
    if ((tpcCfg[TPC_2G].tpcScheme & TPC_LM) || (tpcCfg[TPC_5G].tpcScheme & TPC_LM)) {   //FJC - added this check, think only need this in LM
		whalGetPdetPdadcPacket(TpcCalState.txParm.chan, TpcCalState.txParm.chainMask, adcArr);
		//tpcCalResult[band][idxChan].pdadc[idxChain][idxCalPt] = (adc >> (idxChain << 3)) & 0xff;   // shift j*8
		tpcCalResult[band][idxChan].pdadc[idxChain][idxCalPt] = adcArr[idxChain];
	}

    //FJC - NOTE this printf seems to be important, without it UTF will crash (in the transmit packet handler/interrupt handler)
//    A_PRINTF_ALWAYS("************************************band %d ch %d chn %d calPt %d pdadc %d\n", band, idxChan, idxChain, idxCalPt,
//        tpcCalResult[band][idxChan].pdadc[idxChain][idxCalPt]);
//FJC   	A_DELAY_USECS(10000);
//FJC - take it out all together?   	A_DELAY_USECS(100);

    // read thermal, volt, for a chain
    if ((PROG_CHAIN_MASK == nextAction)||(PROG_CHAN == nextAction)||(PROG_BAND == nextAction)) {
        adc = whalGetCurrentTemp();
        tpcCalResult[band][idxChan].thermCal[MASK2CHAIN(TpcCalState.txParm.chainMask)] = (adc >> (MASK2CHAIN(TpcCalState.txParm.chainMask) << 3)) & 0xff;
//        A_PRINTF_ALWAYS("th[%d] 0x%x %x, adc=%x\n", idxChain, adc, tpcCalResult[band][idxChan].thermCal[idxChain], adc);
    }

    return;
}

static A_INT8 MinDACGain=-128;
static A_INT8 MaxDACGain=80;

#if !defined(QCA9888)
SRAM_TEXT
static A_INT16 interpolate(A_UINT8 gainTgt, A_UINT8 gainL, A_UINT8 gainR,
    A_INT16 pwrL, A_INT16 pwrR)
{
    A_INT16 pwrTgt;
    pwrTgt = pwrL + (gainTgt - gainL) * (pwrR - pwrL)/(gainR - gainL);

    return (pwrTgt);
}

//Takes the calibrated gain indexes and power values and interpolates between points
//expanded arrays are filled and number of expanded points is returned.
SRAM_TEXT
static A_UINT16 interpolateGainsandPwr(
    A_INT16 *pPwrValsIn, A_UINT8 *pGainValsIn, A_UINT16 numMeasuresIn,
    A_INT16 *pPwrValsOut, A_UINT8 *pGainValsOut)
{
    A_UINT8 numExpandedGains, gainIndex;
    A_UINT8 i, j;

    //i loops measured points
    //j loops expanded set of points
    numExpandedGains = pGainValsIn[numMeasuresIn-1] - pGainValsIn[0] + 1;

    for(j=0, i=0, gainIndex = pGainValsIn[0];
        gainIndex <= pGainValsIn[numMeasuresIn-1];
        j++, gainIndex++)
    {
        pGainValsOut[j] = gainIndex;
        if(gainIndex == pGainValsIn[i]) {
            pPwrValsOut[j] = pPwrValsIn[i];
            i++;
        } else if (i >= 1) {
            //won't come in here when i == 0, will be in if case
            pPwrValsOut[j] = interpolate(gainIndex, pGainValsIn[i-1], pGainValsIn[i],
                pPwrValsIn[i-1], pPwrValsIn[i]);
        }
//        A_PRINTF_ONCE("Interpolated values gIdx = %d pwr = %d\n",
//            pGainValsOut[j],
//            pPwrValsOut[j]);
    }
    return numExpandedGains;
}
#endif

CODESWAP_MARK_EVICTABLE(void, postProcessingOLPCCALData)
{
    int band, i, j, k, m,n, kk, l, nc;
	#if defined(QCA9888)
	int numValidMeas;
	#else
    A_UINT16 numValidMeas;
	#endif
    A_UINT8 tgtMeasPwrBackoff=0;
    A_INT8 *txCalDacGain_dflt;
    A_UINT8 txPwrOffset;
    A_INT16 modifiedTarget;
	#if !defined(QCA9888)
    A_INT16 interpolatedPwrMeasures[WHAL_NUM_POINTS_TO_MEAS];
    A_UINT8 gainIdx[WHAL_NUM_POINTS_TO_MEAS];
	#endif

//    A_PRINTF_ALWAYS("pp OLPC\n");

    for (band=TPC_5G;band<TPC_NUM_BAND;band++) {
    	txCalDacGain_dflt = getPreTxCalDacGainPtr(band==TPC_5G ? FALSE : TRUE);
        txPwrOffset = band==TPC_5G ? TxPwrOffset_5G : TxPwrOffset_2G;
        for (i=0;i<tpcCfg[band].numChan;i++) {
            tpcCalResult[band][i].chan = tpcCfg[band].chans[i];
            for (nc=0;nc<tpcCfg[band].numChain;nc++) {
        		j= MASK2CHAIN(tpcCfg[band].chainMasks[nc]);    //translate to the num of chain
                numValidMeas = tpcCalResult[band][i].numValidMeas[j];
				#if !defined(QCA9888)
                numValidMeas = interpolateGainsandPwr(&tpcCalResult[band][i].measPwr[j][0],
                    &tpcCfg[band].gainIdx[j][0], numValidMeas,
                    interpolatedPwrMeasures, gainIdx) % 32;
				#endif
                // determine a tgtMeasPwr backoff
#define MAX_ALLOWED_TGTMEASPWR_BACKOFF_ROUND 12
//                A_PRINTF_ALWAYS("meaPwr %d tgtPwr %d, bn %d ch %d chn %d, \n",
//                    tpcCalResult[band][i].measPwr[j][numValidMeas -1],
//                    tpcCfg[band].tgtMeasPwr[j][0], band, i,j);
//                A_PRINTF_ALWAYS("numValidMeas = %d\n", numValidMeas);
                for (l=0;l< MAX_ALLOWED_TGTMEASPWR_BACKOFF_ROUND;l++) {
					#if defined(QCA9888)
                    if (tpcCalResult[band][i].measPwr[j][numValidMeas -1] >= (tpcCfg[band].tgtMeasPwr[j][0] - (l *4))) {
                        break;
                    }
					#else
                    if(numValidMeas > 0) {
                        if (interpolatedPwrMeasures[numValidMeas -1] >= (tpcCfg[band].tgtMeasPwr[j][0] - (l *4))) {
                            break;
                        }
                    }

					#endif
                }
                tgtMeasPwrBackoff = l *4;
//                if (l) A_PRINTF_ALWAYS("bkof %d bn %d ch %d chn %d\n",l, band,i,j);

                // find a valid starting pwr
                tpcCalResult[band][i].startPwrIdx[j] = 0;
                #define EXCLUDE_LAST_SEVERAL_POINTS  6
                for (n=0;n<(numValidMeas - EXCLUDE_LAST_SEVERAL_POINTS/* 1*/);n++)
                {
					#if defined(QCA9888)
                    if (tpcCalResult[band][i].measPwr[j][n] >= tpcCalResult[band][i].measPwr[j][n +1]) {
                        tpcCalResult[band][i].startPwrIdx[j] = n+1;
                    }
					#else
                    if (interpolatedPwrMeasures[n] >= interpolatedPwrMeasures[n +1]) {
                        tpcCalResult[band][i].startPwrIdx[j] = n+1;
                    }
					#endif
                }
//                A_PRINTF_ALWAYS("stPwrIdx %d bn %d ch %d chn %d\n",tpcCalResult[band][i].startPwrIdx[j],band,i,j);

                for (k=0; k <= (NUM_CAL_GAINS_SELECTED_4_GLUT -1);k++) {
#if defined(IPQ4019) || defined(QCA9888)
                    //Based on algorithm team's advice, no more delta biasing in searching target power
                    modifiedTarget = tpcCfg[band].tgtMeasPwr[j][k];
#else
                    if(k == 0) {
                        modifiedTarget = tpcCfg[band].tgtMeasPwr[j][k];
                    } else {
                        modifiedTarget = (tpcCalPostProcResult[band][i].olpc.measPwr[j][k-1] - txPwrOffset)
                            - tpcCfg[band].tgtMeasPwr[j][k-1] + tpcCfg[band].tgtMeasPwr[j][k];
                    }
#endif

#if defined (QCA9984)
                    //if negative offset is being used, then don't modify the target as need to keep close to targets at lower powers
                    if(txPwrOffset) {
                        modifiedTarget = tpcCfg[band].tgtMeasPwr[j][k];
                    }
#endif
                    for (m=tpcCalResult[band][i].startPwrIdx[j];m<numValidMeas;m++)
                    {
						#if defined(QCA9888)
                        if ((tpcCalResult[band][i].measPwr[j][m] >= modifiedTarget) || (m == (numValidMeas -1)))
						#else
                        if ((interpolatedPwrMeasures[m] >= modifiedTarget) || (m == (numValidMeas -1)))
						#endif
                        {
                            if(tpcCalResult[band][i].measPwr[j][m] >= 0) {
								#if defined(QCA9888)
                                tpcCalPostProcResult[band][i].olpc.measPwr[j][k]    = tpcCalResult[band][i].measPwr[j][m] + txPwrOffset;
                                tpcCalPostProcResult[band][i].olpc.gainIdx[j][k]    = tpcCfg[band].gainIdx[j][m];
								#else
                                tpcCalPostProcResult[band][i].olpc.measPwr[j][k]    = interpolatedPwrMeasures[m] + txPwrOffset;
                                tpcCalPostProcResult[band][i].olpc.gainIdx[j][k]    = gainIdx[m];
								#endif
                                tpcCalPostProcResult[band][i].olpc.dacGain[j][k]    = tpcCfg[band].dacGain[j][m];
                                //tpcCalPostProcResult[band][i].olpc.paCfg[j][k]      = tpcCfg[band].paCfg[j][m];
                                tpcCalPostProcResult[band][i].olpc.paCfg[j][k]      = DA_Gain_Settings[band][tpcCalPostProcResult[band][i].olpc.gainIdx[j][k]];
                                tpcCalPostProcResult[band][i].olpc.minDacGain[j][k] = MinDACGain;
                                tpcCalPostProcResult[band][i].olpc.maxDacGain[j][k] = MaxDACGain;
                                break;
                            } else {
                                //A_PRINTF("Negative power %d k = %d, ch %d, chain %d\n",
								#if defined(QCA9888)
                                //    tpcCalResult[band][i].measPwr[j][m], k, i, j );
								#else
                                //    interpolatedPwrMeasures[m], k, i, j );
								#endif
                                continue;
                            }
#if 0
                            A_PRINTF("ch %d chn %d sel pwr %d gIdx %d dac %d\n",
                                tpcCalResult[band][i].chan, j,
                                tpcCalPostProcResult[band][i].olpc.measPwr[j][k],
                                tpcCalPostProcResult[band][i].olpc.gainIdx[j][k],
                                tpcCalPostProcResult[band][i].olpc.dacGain[j][k]);
#endif
                            // get out
                        }
                    } // for (m
                    if (m == numValidMeas) {
                        // can't find the proper entry
//                        A_PRINTF_ALWAYS("no entry 4 %d\n",k);
                    }
                } // for k
                // adjust minDacGain
                for (kk=0; kk<(NUM_CAL_GAINS_SELECTED_4_GLUT -1);kk++) {
                    tpcCalPostProcResult[band][i].olpc.minDacGain[j][kk] = (
                        txCalDacGain_dflt[0] - tpcCalPostProcResult[band][i].olpc.measPwr[j][kk]
                        + tpcCalPostProcResult[band][i].olpc.measPwr[j+1][kk] -8);
                }
            } // (for (j
        } // (for i
    } // (for band

    // TBD
    // Prepare OLPC data block

    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void, postProcessingOLPCCALData);
extern void postProcessingOLPCCALData();
/*
SRAM_TEXT
static void postProcessingCLPCCALData(void)*/
CODESWAP_MARK_EVICTABLE(void, postProcessingCLPCCALData)
{
//    A_PRINTF_ALWAYS("pp CLPC\n");

    int band, i, j, k, m, startHi, nc;
    int numValidMeas;
    A_UINT8 txPwrOffset;

#if 0
    A_PRINTF_ALWAYS("\npdadc tgt: ");
    for (k=0;k<NUM_CAL_GAINS_SELECTED_4_PLUT;k++) {
        A_PRINTF_ALWAYS("%d ", tpcCfg[0].tgtPdadc[0][k]);
    }
#endif

    for (band=TPC_5G; band<TPC_NUM_BAND; band++) {
        txPwrOffset = band==TPC_5G ? TxPwrOffset_5G : TxPwrOffset_2G;
        for (i=0;i<tpcCfg[band].numChan;i++) {
           for (nc=0;nc<tpcCfg[band].numChain;nc++) {
            	j= MASK2CHAIN(tpcCfg[band].chainMasks[nc]); //translate to chain num
                numValidMeas = tpcCalResult[band][i].numValidMeas[j];
#if 0
	A_PRINTF_ALWAYS("ch %d chn %d pdadc calpts (numValid=%d): ", tpcCalResult[band][i].chan, j, numValidMeas);
    for (m=(numValidMeas-1);m>=0;m--) {
        A_PRINTF_ALWAYS("%d ", tpcCalResult[band][i].pdadc[j][m]);
    }
#endif
                startHi =(numValidMeas -1);
                for (k=0;k<NUM_CAL_GAINS_SELECTED_4_PLUT;k++) {
                    for (m=startHi;m>=tpcCalResult[band][i].startPwrIdx[j];m--) {
                        if ((tpcCalResult[band][i].pdadc[j][m] <= tpcCfg[band].tgtPdadc[j][k]) && (tpcCalResult[band][i].measPwr[j][m] >= 0)) {
                            tpcCalPostProcResult[band][i].clpc.measPwr[j][k]    = tpcCalResult[band][i].measPwr[j][m] + txPwrOffset;
                            tpcCalPostProcResult[band][i].clpc.pdadc[j][k]      = tpcCalResult[band][i].pdadc[j][m];
                            startHi = m -1;
#if 0
                            A_PRINTF("ch %d chn %d sel pwr %d pdadc %d\n",
                                tpcCalResult[band][i].chan, j,
                                tpcCalPostProcResult[band][i].clpc.measPwr[j][k],
                                tpcCalPostProcResult[band][i].clpc.pdadc[j][k]);
#endif
                            break;
                        }
#if 0
                        if (tpcCalResult[band][i].pdadc[j][m] < tpcCfg[band].pdadcThresh) {
                            tpcCalPostProcResult[band][i].clpc.measPwr[j][k]    = tpcCalResult[band][i].measPwr[j][m];
                            tpcCalPostProcResult[band][i].clpc.pdadc[j][k]      = tpcCalResult[band][i].pdadc[j][m];
                            break;
                        }
#endif
                    } // for (m
                } // for (k=
            } // for (j=
        } // for (i=
    }

    // TBD
    // Prepare CLPC CAL data block

    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void, postProcessingCLPCCALData);
extern void postProcessingCLPCCALData();

/*
 * Respond to txPwr command
 */
#if 0
#define MAX_CAL_DATA_SIZE  64
SRAM_DATA
A_UINT8 calData2GOLPC[MAX_CAL_DATA_SIZE];
SRAM_DATA
A_UINT8 calData5GOLPC[MAX_CAL_DATA_SIZE];
SRAM_DATA
A_UINT8 calData2GCLPC[MAX_CAL_DATA_SIZE];
SRAM_DATA
A_UINT8 calData5GCLPC[MAX_CAL_DATA_SIZE];
#endif


SRAM_TEXT
static A_BOOL prepCalData(CMD_TPCCALPWR_PARMS *pParms)

{
    int band, i, j, k, nc;
    int count=0;
    A_BOOL validPwr = FALSE;

    if ((tpcCfg[TPC_2G].tpcScheme & TPC_LM) || (tpcCfg[TPC_5G].tpcScheme & TPC_LM)) {   //FJC - added this check, think only need this in LM

//        A_PRINTF_ALWAYS("numPwr %d %d\n", pParms->numMeasuredPwr, pParms->measuredPwr[0]);
	for (band=TPC_5G;band<TPC_NUM_BAND;band++) {
            for (i=0;i<tpcCfg[band].numChan;i++) {
                for (j=0;j<tpcCfg[band].numChain;j++) {
                    tpcCalResult[band][i].numValidMeas[j] =0;
                    validPwr = TRUE;
                    for (k=0;k<tpcCfg[band].numGain;k++) {
                        if (count<pParms->numMeasuredPwr) {
                            if (validPwr) {
                                tpcCalResult[band][i].measPwr[j][k] = pParms->measuredPwr[count];
                                (tpcCalResult[band][i].numValidMeas[j])++;

                                #define EXCLUDE_INITIAL_SEVERAL_POINTS  6
                                if ((k != (tpcCfg[band].numGain -1)) && (k >EXCLUDE_INITIAL_SEVERAL_POINTS ))   {
                                    #define PWR_DROP_THRESHOLD 40 // 5dB *8
                                    if (pParms->measuredPwr[count] > (pParms->measuredPwr[count +1] + PWR_DROP_THRESHOLD)) {
                                        validPwr = FALSE;
                                    }
                                }
                                count++;
                            }
                            else { count++; }
                        }
                        else {
                            return(FALSE);
                        }
                    }
                }
            }
        }
    }
    else { // ping-pong
	for (band=TPC_5G;band<TPC_NUM_BAND;band++) {
            for (i=0;i<tpcCfg[band].numChan;i++) {
                for (nc=0;nc<tpcCfg[band].numChain;nc++) {
                    j= MASK2CHAIN(tpcCfg[band].chainMasks[nc]); //translate to chain num
                    tpcCalResult[band][i].numValidMeas[j] =0;
                    validPwr = TRUE;
                    for (k=0;k<tpcCfg[band].numGain;k++) {
                        if (validPwr) {
							//check to see if we skipped some measurements
							if (tpcCalResult[band][i].measPwr[j][k] == MEAS_SKIP) {
								validPwr = FALSE;
								break;
							}
                            (tpcCalResult[band][i].numValidMeas[j])++;

                            #define EXCLUDE_INITIAL_SEVERAL_POINTS  6
                            if ((k >EXCLUDE_INITIAL_SEVERAL_POINTS) && (k != (tpcCfg[band].numGain -1))) {
                                #define PWR_DROP_THRESHOLD 40 // 5dB *8
                                if (tpcCalResult[band][i].measPwr[j][k] > (tpcCalResult[band][i].measPwr[j][k +1] + PWR_DROP_THRESHOLD )) {
                                    validPwr = FALSE;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return(TRUE);
}

extern GEN_CAL_DATA CalData;
SRAM_TEXT
static void sendCALDATA2Host(wlan_tcmd_dev_t *dev)
{
    /*
     * Send the CAL channels to host to measure the power
     * total measurements should be:
     *    (numChan2G + numChan5G) * numChains
     */
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    //A_UINT8 calData2G[64]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
    //A_UINT8 calData5G[64]={11,21,31,41,51,61,71,81,91,101,21,22,23,24,25,26,27,28,29,30,31,32,33,34};

    //memcpy((void*)&(calData2G[0]), (void *)&(tpcCalPostProcResult[TPC_2G][0]), sizeof(TPC_CAL_POSTPROCESSED_RESULT * tpcCfg[TPC_2G].numChan));
    //memcpy((void*)&(calData5G[0]), (void *)&(tpcCalPostProcResult[TPC_5G][0]), sizeof(TPC_CAL_POSTPROCESSED_RESULT * tpcCfg[TPC_5G].numChan));
#if defined(_CAL_LM)
    pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp(CMD_TPCCALDATA, 26, PARM_CALDATA2G, &(CalData.calData2G_OLPC[0]),
        PARM_CALDATA2GOFFSET, CalData.offset2G_OLPC, PARM_CALDATA2GLENGTH, CalData.length2G_OLPC,
        PARM_CALDATA5G, &(CalData.calData5G_OLPC[0]), PARM_CALDATA5GOFFSET, CalData.offset5G_OLPC,
        PARM_CALDATA5GLENGTH, CalData.length5G_OLPC, PARM_CALDATA2G_CLPC, &(CalData.calData2G_CLPC[0]),
        PARM_CALDATA2GOFFSET_CLPC, CalData.offset2G_CLPC, PARM_CALDATA2GLENGTH_CLPC, CalData.length2G_CLPC,
        PARM_CALDATA5G_CLPC, &(CalData.calData5G_CLPC[0]), PARM_CALDATA5GOFFSET_CLPC, CalData.offset5G_CLPC,
        PARM_CALDATA5GLENGTH_CLPC, CalData.length5G_CLPC, PARM_MISCFLAGS, (TPCCAL_DONE_MASK | TPCCAL_CALDATA));
#else
    if(TpcCalState.calLoop.calFail && TpcCalState.calLoop.calAttempts > 5) {
        //error out
        //A_PRINTF("Cal fail due to slope check\n");
        pCmdStream = NULL;
        return;
    }

    pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp(CMD_TPCCALDATA, 2,  PARM_MISCFLAGS, (TPCCAL_DONE_MASK | TPCCAL_CALDATA));
#endif
    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

//    A_PRINTF_ALWAYS("2Host len %d, stream 0x%x\n", cmdStreamLen, (int)rCmdStream);
    wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,CMD_TPCCALDATA,(A_INT8*)rCmdStream);
    whalEepromSetCalVersion();

    return;
}

SRAM_TEXT
static void genCalData4BrdData(void)
{
//    A_PRINTF_ALWAYS("genCALData\n");
    if (NULL != ChipFunc.genCalData) {
        (ChipFunc.genCalData)();
    }
    return;
}

SRAM_TEXT
static void applyCalDataFromBrdData(void)
{
#if 0
    A_PRINTF_ALWAYS("applyCALData 0x%x\n", ChipFunc.applyCalData);
    if (NULL != ChipFunc.applyCalData) {
        A_PRINTF_ALWAYS("1 applyCALData 0x%x\n", ChipFunc.applyCalData);
        (ChipFunc.applyCalData)();
    }
extern void ar900BApplyCalDataFromBrdData(void);
    ar900BApplyCalDataFromBrdData();
#endif
    return;
}

/*
SRAM_TEXT
static void writeCalData2Otp(void)
{
    return;
}
*/

SRAM_TEXT
void getCALPwrMeasurement(CMD_TPCCALPWR_PARMS *pParms)
{
    /*
     * Prep data, for post processing
     * outcome:
     *   txgain idx array
     *   measured Pout, per chain
     *   PDET reading, per chain
     */
    prepCalData(pParms);   //FJC_BUG: this does not work for ping pong mode since it is only 1 measure
                                                                //Actually, don't think need this in ping pong, fix in function

    /* post processing data */
    postProcessingOLPCCALData();

    if (getTpcFlag(TpcCalState.calBand) != 0x1 /* WHAL_TPC_CONFIG_OLPC */ ) {
    /* post processing data */
    postProcessingCLPCCALData();

    }
    /* generate CAL data for the board data*/
    genCalData4BrdData();

    /* apply CAL data from the board data */
    applyCalDataFromBrdData();

    /* write CAL data to OTP, if enabled
    writeCalData2Otp();
    */

    /* send host: CALDataOffset, CALDATALength, binaryCALDATA, for 2G, 5G, OLPC and CLPC */
    sendCALDATA2Host(&utf_dev);

    gEnableFastChannelChange = FALSE;

#ifndef FPGA
    gFTMCalInProgress = FALSE;
#if defined(AR900B_HW_V2_WAR_RXPCU_HANG)
    g_enable_wdog_reset_trig = 1;
#endif
    #if defined(QCA9888)
    whalPaprdTpcOlpcTuningEnableSet(0);
    #endif
#endif

    return;
}

#if defined(QCA9888)
void tpc_cal_dpd_cb(WHAL_CHANNEL *channel, A_UINT32 id)
{
    tpcCALLoop();
}
#endif

#if 0
void tcmd_CAL_timer_handler(A_HANDLE handler, void *data)
{
    A_UNTIMEOUT(&tcmd_CAL_timer);

    ftmTxStop(&(TpcCalState.txParm));

    A_PRINTF_ALWAYS("stop tx\n");
}
static A_TIMER tcmd_CAL_timer;
#endif
SRAM_TEXT
void tpcPwr(void *parms)
{
#ifndef FPGA
    A_UINT8 adcArr[4];
	A_UINT8 i;
    A_INT16 prevMeas, tmp2, tmp3, tmp4, slope=100;
    A_UINT16 tmp1;
    CMD_TPCCALPWR_PARMS *pParms = (CMD_TPCCALPWR_PARMS *)parms;
    #if defined(QCA9888)
    if(whalPaprdTpcOlpcTuningEnableGet()){
        if(!whalPaprdTrainingCompleted()){
            //Look at what is next
            if (NULL == tpcCALLoop()) {
                //            A_PRINTF_ALWAYS("p-p f\n");
                getCALPwrMeasurement(pParms);
            }
            return;
        }
    }
    #endif

	if ((tpcCfg[TPC_2G].tpcScheme & TPC_LM) || (tpcCfg[TPC_5G].tpcScheme & TPC_LM)) {
        // list most process the board data
        getCALPwrMeasurement(pParms);
    }
    else {
        // store the measured power
    	//FJC moved this to here rather than in else.
//    	A_PRINTF("####FJC: Got power from host %d, save for band %d, chan %d, chn %d, calPt %d\n", pParms->measuredPwr[0],
//    			TpcCalState.calLoop.numBand, TpcCalState.calLoop.idxChan, TpcCalState.calLoop.idxChain, TpcCalState.calLoop.idxCalPt);
        #if defined(QCA9888)
        if(whalPaprdTpcOlpcTuningEnableGet()){
            OlpcDpdTuningPowerDoneSet(TpcCalState.txParm.gainIdx);
        }
        #endif
        tpcCalResult[TpcCalState.calLoop.numBand][TpcCalState.calLoop.idxChan].measPwr[MASK2CHAIN(TpcCalState.txParm.chainMask)][TpcCalState.calLoop.idxCalPt] = pParms->measuredPwr[0];

        if (getTpcFlag(TpcCalState.calBand) != WHAL_TPC_CONFIG_OLPC) {
//FJC: For ping-pong want to read pdadc here #######################################
		//A_PRINTF("Reading pdadc after power\n");
	    whalGetPdetPdadcPacket(TpcCalState.txParm.chan, TpcCalState.txParm.chainMask, adcArr);
//        A_PRINTF("pdadc %d\n", adcArr[TpcCalState.calLoop.idxChain]);
		//tpcCalResult[band][idxChan].pdadc[idxChain][idxCalPt] = (adc >> (idxChain << 3)) & 0xff;   // shift j*8
        tpcCalResult[TpcCalState.calLoop.numBand][TpcCalState.calLoop.idxChan].pdadc[MASK2CHAIN(TpcCalState.txParm.chainMask)][TpcCalState.calLoop.idxCalPt] = adcArr[MASK2CHAIN(TpcCalState.txParm.chainMask)];

#if 1   //FJC Disable slope check for now.
        //Check that the power is increasing from last measurement
        TpcCalState.calLoop.calFail = 0;
        if (pParms->measuredPwr[0] < -400) {   //catch all mis-capture scenarios.
            TpcCalState.calLoop.calFail = 1;
//            A_PRINTF_ONCE("-999 power detected, setting error\n");
        }
         else if (TpcCalState.calLoop.idxCalPt > 0) {
            prevMeas = tpcCalResult[TpcCalState.calLoop.numBand][TpcCalState.calLoop.idxChan].measPwr[MASK2CHAIN(TpcCalState.txParm.chainMask)][TpcCalState.calLoop.idxCalPt - 1];
            if((pParms->measuredPwr[0] >= 40) /* 5dbm */ && (pParms->measuredPwr[0] <= 160 /* 20dbm */)) {
                if(pParms->measuredPwr[0] < prevMeas) {
                    TpcCalState.calLoop.calFail = 1;
//                    A_PRINTF_ONCE("Mid range power check failed cur %d, prev %d\n", pParms->measuredPwr[0], prevMeas);
                }
            } else {
                if(pParms->measuredPwr[0] < (prevMeas - 8)) {
                    TpcCalState.calLoop.calFail = 1;
//                    A_PRINTF_ONCE("low/hi range power check failed cur %d, prev %d\n", pParms->measuredPwr[0], prevMeas);
                }
            }

//A_PRINTF_ONCE("%x pwr %d\n", OS_REG_READ(0x10820), pParms->measuredPwr[0]);
//A_DELAY_USECS(100000);
            if((adcArr[MASK2CHAIN(TpcCalState.txParm.chainMask)] >= 20) && (adcArr[MASK2CHAIN(TpcCalState.txParm.chainMask)] < 200)/* && (TpcCalState.calLoop.calFail != 1) */) {
    	        //A_PRINTF("Checking slope: Got power from host %d, save for band %d, chan %d, chn %d, calPt %d\n", pParms->measuredPwr[0],
    			//    TpcCalState.calLoop.numBand, TpcCalState.calLoop.idxChan, TpcCalState.calLoop.idxChain, TpcCalState.calLoop.idxCalPt);
                //A_PRINTF("pdadc now %d, prev %d\n", adcArr[TpcCalState.calLoop.idxChain], tpcCalResult[TpcCalState.calLoop.numBand][TpcCalState.calLoop.idxChan].pdadc[TpcCalState.calLoop.idxChain][TpcCalState.calLoop.idxCalPt-1]);

                tmp3 = tbl_10log10[tpcCalResult[TpcCalState.calLoop.numBand][TpcCalState.calLoop.idxChan].pdadc[MASK2CHAIN(TpcCalState.txParm.chainMask)][TpcCalState.calLoop.idxCalPt]];
                tmp4 = tbl_10log10[tpcCalResult[TpcCalState.calLoop.numBand][TpcCalState.calLoop.idxChan].pdadc[MASK2CHAIN(TpcCalState.txParm.chainMask)][TpcCalState.calLoop.idxCalPt-1]];

                tmp1 = 100 * (tmp3 - tmp4);
                tmp2 = (pParms->measuredPwr[0] - prevMeas) * 2;

                if (tmp2 == 0) {
                    slope = tmp1;
                } else {
                    slope = tmp1/tmp2;
                }
//                A_PRINTF_ONCE("t1: %d t2: %d t3: %d t4: %d sl %d\n", tmp1, tmp2, tmp3, tmp4, slope);
                /*
                The slope for DC based CLPC is not better than RF based CLPC. The curve is close to linear.
                If applying this limit to check the slope, some of DUT can't meet. Now remove this check for DC based CLPC only.
                */
                if (getTpcFlag(TpcCalState.calBand) != 3 /*WHAL_TPC_CONFIG_CLPC_EXPDET*/)
                {
                    if ((slope > 140) || (slope < 60)) {
                        TpcCalState.calLoop.calFail = 1;
//                      A_PRINTF_ONCE("slope Failed %d\n", slope);
//                      A_DELAY_USECS(100000);
#if 0
                        //read pdadc a few times for debug
                        for(i = 0; i < 5; i++) {
                	        whalGetPdetPdadcPacket(TpcCalState.txParm.chan, TpcCalState.txParm.chainMask, adcArr);
//                          A_PRINTF_ONCE("slope Failed, pdadc reread[%d] = %d\n", i, adcArr[TpcCalState.calLoop.idxChain]);
                            A_DELAY_USECS(100000);
                        }
#endif
                    }
                }
            }

#if 0
            if(TpcCalState.calLoop.calFail) {
                //A_PRINTF_ONCE("Cal failed slope checks power from host %d, save for band %d, chan %d, chn %d, calPt %d", pParms->measuredPwr[0],
    			//TpcCalState.calLoop.numBand, TpcCalState.calLoop.idxChan, TpcCalState.calLoop.idxChain, TpcCalState.calLoop.idxCalPt);
              //  A_PRINTF_ONCE(" attempts = %d\n", TpcCalState.calLoop.calAttempts);
            }
#endif
        }
#endif

}

        //Check to see if we have reached highest expected power
		if((tpcCalResult[TpcCalState.calLoop.numBand][TpcCalState.calLoop.idxChan].measPwr[MASK2CHAIN(TpcCalState.txParm.chainMask)][TpcCalState.calLoop.idxCalPt]
		>= tpcCfg[TpcCalState.calLoop.numBand].tgtMeasPwr[MASK2CHAIN(TpcCalState.txParm.chainMask)][0])   && (TpcCalState.calLoop.calFail != 1)) {
			TpcCalState.calLoop.gainSearchDone = 1;

			//fill rest of powers up to indicate that measurements were not made.
			for (i = TpcCalState.calLoop.idxCalPt + 1; i < tpcCfg[TpcCalState.calLoop.numBand].numGain; i++)
			{
				tpcCalResult[TpcCalState.calLoop.numBand][TpcCalState.calLoop.idxChan].measPwr[MASK2CHAIN(TpcCalState.txParm.chainMask)][i] = MEAS_SKIP;
			}
		}

		//Look at what is next
        if (NULL == tpcCALLoop()) {
//            A_PRINTF_ALWAYS("p-p f\n");
            getCALPwrMeasurement(pParms);
        }
/*   FJC moving this to before loop call
 *         else {
            // store the measured power
        	A_PRINTF("####FJC: Got power from host %d\n", pParms->measuredPwr[0]);
            tpcCalResult[TpcCalState.calLoop.numBand][TpcCalState.calLoop.idxChan].measPwr[TpcCalState.calLoop.idxChain][TpcCalState.calLoop.idxCalPt] = pParms->measuredPwr[0];
        }
*/    }
      //whalEepromSetCalVersion();
#endif
    return;
}

// Init TPC module
SRAM_TEXT
void initTPC(void)
{
    // register the TPC module with the TLV handler
    registerTPCCALHandler(tpcCAL);
    registerTPCCALPWRHandler(tpcPwr);
    //registerTPCCALPWRHandler(getCALPwrMeasurement);

    //A_INIT_TIMER(&tcmd_CAL_timer, tcmd_CAL_timer_handler, 0);
#if defined(QCA9888)
    whalRegisterTPCCB(tpc_cal_dpd_cb);
#endif
#if defined(IPQ4019)
    A_UINT16 txGainTblIdx;
    A_UINT16 rxGainTblIdx;
    WHAL_CHANNEL chan;
    chan.phy_mode = MODE_11G; // this value is not important. just whalEepromGetTxRxGainIdx() needs this parameter to determine 2G and 5G
    whalEepromGetTxRxGainIdx(&chan, &txGainTblIdx, &rxGainTblIdx);
    if (txGainTblIdx == 1){
        DA_Gain_Settings[TPC_2G][20] = 3;
        DA_Gain_Settings[TPC_2G][21] = 3;
        DA_Gain_Settings[TPC_2G][22] = 3;
        DA_Gain_Settings[TPC_2G][23] = 3;
        DA_Gain_Settings[TPC_2G][24] = 3;
        DA_Gain_Settings[TPC_2G][25] = 4;
    } else if (txGainTblIdx == 2){
        DA_Gain_Settings[TPC_2G][20] = 4;
        DA_Gain_Settings[TPC_2G][21] = 4;
        DA_Gain_Settings[TPC_2G][22] = 4;
        DA_Gain_Settings[TPC_2G][23] = 4;
        DA_Gain_Settings[TPC_2G][24] = 4;
        DA_Gain_Settings[TPC_2G][25] = 4;
    }
#endif
    return;
}

/*
 * Ping-pong mode, thus the CAL loop used for both LM and ping-pong
 *
 */
#if 0
static void tpcCAL_loop(CMD_TPCCAL_PARMS *pParms)
{
    //FORCED_GAIN_TX_PARM txParm;
    A_UINT32            adc;
    int i,j,k,band, n;
    A_UINT8 tpcScheme;

    /*
     * Init TPC CAL relevant, e.g. state
     */
    memset((void*)&TpcCalState, 0, sizeof(TPC_CAL_STATE));
    // TBD: ?? for now, to keep the compiler happy
    pParms->radioId = 0;
    n=0;

    // get TPC calibration settings from the board data file
    /*
       1. CLPC or OLPC;
       2. Number of CAL channels (always TPC CAL per chain);
     */
    memset((void *)tpcCfg, 0, sizeof(tpcCfg));
    memset((void *)&(tpcCfg[0].chans[0]), 0xff, MAX_CAL_CHANS_2G);
    memset((void *)&(tpcCfg[1].chans[0]), 0xff, MAX_CAL_CHANS_5G);
    getTPCCALCfgFromBoardData();

    send2Host(&utf_dev);

    /*
     * Loop through channels, chains, hopefully by changing minimal,
     * e.g. program chain mask for chains, synthesizer only for channel change
     */
    for (band=TPC_2G;band<TPC_NUM_BAND;band++) {
        TpcCalState.txParm.band = band;
        //A_PRINTF_ALWAYS("band %d\n", band);
        for (i=0; i< tpcCfg[band].numChan; i++) {
            TpcCalState.txParm.chan = tpcCfg[band].chans[i];
            //A_PRINTF_ALWAYS("chan %d\n", txParm.chan);
            configChan(tpcCfg[band].chans[i], band);
            for (j=0;j<tpcCfg[band].numChain;j++) {
                TpcCalState.txParm.chain = j;
                TpcCalState.txParm.chainMask = tpcCfg[band].chainMasks[j];
                //A_PRINTF_ALWAYS("cn %d 0x%x\n", txParm.chain, txParm.chainMask);
                progChainMask(tpcCfg[band].chainMasks[j]);
                for (k=0;k<tpcCfg[band].numGain;k++) {
                    TpcCalState.txParm.gainIdx = tpcCfg[band].gainIdx[j][k];
                    TpcCalState.txParm.dacGain = tpcCfg[band].dacGain[j][k];
                    TpcCalState.txParm.paCfg   = tpcCfg[band].paCfg[j][k];

                    A_PRINTF_ALWAYS("sG %d %d %d %d %d %d\n", TpcCalState.txParm.band, TpcCalState.txParm.chan, TpcCalState.txParm.chain, TpcCalState.txParm.gainIdx, TpcCalState.txParm.dacGain, TpcCalState.txParm.paCfg);
                    //setForcedGain(&txParm);
                    ftmTxStart(&(TpcCalState.txParm));
                    //A_TIMEOUT_MS(&tcmd_CAL_timer, 15000, 0);

                    // stop the TX
                    //ftmTxStop(&(TpcCalState.txParm));

                    A_DELAY_USECS(10000);

                    // read pdet
                    adc = whalGetPdetPdadcPacket(TpcCalState.txParm.chan, TpcCalState.txParm.chainMask);
                    tpcCalResult[band][i].pdadc[j][k] = (adc >> (j << 3)) & 0xff;   // shift j*8

                    A_PRINTF_ALWAYS("pdadc 0x%x %d\n", adc, tpcCalResult[band][i].pdadc[j][k]);
                    A_DELAY_USECS(1000000);
                }
            }

            // read thermal, volt, for a chain
            adc = whalGetCurrentTemp();
            tpcCalResult[band][i].thermCal[j] = (adc >> (j << 3)) & 0xff;
            A_PRINTF_ALWAYS("th 0x%x %d\n", adc, tpcCalResult[band][i].thermCal[j]);
        }
    }

    return;
}
#endif

