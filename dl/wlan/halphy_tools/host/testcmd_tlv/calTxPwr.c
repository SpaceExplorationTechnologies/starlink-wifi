//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdarg.h>
#include "wlantype.h"   /* typedefs for A_UINT16 etc.. */
#include "wlanproto.h"
//#include "linux_ansi.h"
#include <unistd.h>
#include <getopt.h>

#include "mInst.h"
#define SUPPORT_11N
#include "wlan_defs.h"

#if defined(_HOST_SIM_TESTING)
#include "otaHostCommon.h"
#else
#include "osapi.h"
#endif
#include "testUtil.h"
#include "tcmdHostInternal.h"
#include "qc98xx_eeprom.h"
#include "eepromUtil_ar6004.h"
//#include "CalDef.h"

#define POWER_T10(power)                    ((A_INT32)((power) * 8))
#define OLPCGAINDELTA_T10(power,gain)       (POWER_T10(power) - ((gain) * 5) + (_DESIRED_SCALE_MCS7 * 5))
#define OLPCGAINDELTA_T10X(power_t10,gain)  ((power_t10) - ((gain) * 5) + (_DESIRED_SCALE_MCS7 * 5))

// defines
#define _RING_BUFFER_SIZE  50000
#define _INVALID_PWR_LOWEND  -45
#define _INVALID_PWR_HIGHEND 30
#define _MAX_STORED_PWR  48
#define _MAX_CAL_TX_CHANNELS (WHAL_NUM_11G_CAL_PIERS + WHAL_NUM_11A_CAL_PIERS)
//#define _MAX_MEASUREMENT_PER_CHAN 10
#define _MAX_MEASUREMENT_PER_CHAN  MASK_RATE_MAX
#define _MAX_CALIBRATED_RATES (_MAX_CAL_TX_CHANNELS * _MAX_MEASUREMENT_PER_CHAN)

#define _DESIRED_SCALE_MCS7 0xE
#define _THERM_CAL_VAL      120
#define _VOLT_CAL_VAL       0

#define _MAX_KEY_LEN        100
#define _MAX_CHAINS         3
#define _VERIFY_CHAINS      3
#define FREQ2FBIN(x,y) ((y) ? ((x) - 2300) : (((x) - 4800) / 5))

#define _2G_READY

#ifdef LINUX
#define strnicmp strncmp
#endif

#define     _TX_SWEEP   0x00000001
#define     _TX_FOREVER 0x00000002
#define     _TX_VERIFY  0x00000004
static A_UINT32 configBitmap = 0;

#if 0
_AthDataRate Mask2Rate[RATE_MASK_ROW_MAX][RATE_MASK_BIT_MAX] = {
{
    ATH_RATE_1M, //1M
    ATH_RATE_2M,
    ATH_RATE_2M,
    ATH_RATE_5_5M,
    ATH_RATE_5_5M,
    ATH_RATE_11M,
    ATH_RATE_11M,
    ATH_RATE_11M, // none should be tx here
    
    ATH_RATE_6M,
    ATH_RATE_9M,
    ATH_RATE_12M,
    ATH_RATE_18M,
    ATH_RATE_24M,
    ATH_RATE_36M,
    ATH_RATE_48M,
    ATH_RATE_54M,

    ATH_RATE_6_5M,
    ATH_RATE_13M,
    ATH_RATE_19_5M,
    ATH_RATE_26M,
    ATH_RATE_39M,
    ATH_RATE_52M,
    ATH_RATE_58_5M,
    ATH_RATE_65M,

    ATH_RATE_HT40_13_5M,
    ATH_RATE_HT40_27M,
    ATH_RATE_HT40_40_5M,
    ATH_RATE_HT40_54M,
    ATH_RATE_HT40_81M,
    ATH_RATE_HT40_108M,
    ATH_RATE_HT40_121_5M,
    ATH_RATE_HT40_135M,
},

{
// should be MCS8 - 15 for HT20 and HT40
    ATH_RATE_6_5M,
    ATH_RATE_13M,
    ATH_RATE_19_5M,
    ATH_RATE_26M,
    ATH_RATE_39M,
    ATH_RATE_52M,
    ATH_RATE_58_5M,
    ATH_RATE_65M,

    ATH_RATE_HT40_13_5M,
    ATH_RATE_HT40_27M,
    ATH_RATE_HT40_40_5M,
    ATH_RATE_HT40_54M,
    ATH_RATE_HT40_81M,
    ATH_RATE_HT40_108M,
    ATH_RATE_HT40_121_5M,
    ATH_RATE_HT40_135M,
#if 0
    ATH_RATE_HT20_MCS8_13M,
    ATH_RATE_HT20_MCS9_26M,
    ATH_RATE_HT20_MCS10_39M,
    ATH_RATE_HT20_MCS11_52M,
    ATH_RATE_HT20_MCS12_78M,
    ATH_RATE_HT20_MCS13_104M,
    ATH_RATE_HT20_MCS14_107M,
    ATH_RATE_HT20_MCS15_130M,

    ATH_RATE_HT40_MCS8_27M,
    ATH_RATE_HT40_MCS9_54M,
    ATH_RATE_HT40_MCS10_81M,
    ATH_RATE_HT40_MCS11_108M,
    ATH_RATE_HT40_MCS12_162M,
    ATH_RATE_HT40_MCS13_216M,
    ATH_RATE_HT40_MCS14_243M,
    ATH_RATE_HT40_MCS15_270M,
#endif

// should be MCS16 - MCS23 for HT20, HT40, stream3, though not in ar6004
    ATH_RATE_6_5M,
    ATH_RATE_13M,
    ATH_RATE_19_5M,
    ATH_RATE_26M,
    ATH_RATE_39M,
    ATH_RATE_52M,
    ATH_RATE_58_5M,
    ATH_RATE_65M,

    ATH_RATE_HT40_13_5M,
    ATH_RATE_HT40_27M,
    ATH_RATE_HT40_40_5M,
    ATH_RATE_HT40_54M,
    ATH_RATE_HT40_81M,
    ATH_RATE_HT40_108M,
    ATH_RATE_HT40_121_5M,
    ATH_RATE_HT40_135M,
},

};
#endif


// share common code with utf, mainly configuration
#include "calTxPwrConfig.code"

typedef enum {
    _txPwrHuntFirst=0,
    _txPwrReady4First,
    _txPwrReadPhase,
} _TX_CAL_READ;

typedef struct _txPwrCALDataPerChan {
    A_INT32  pwr_t10;
    //A_INT32  olpcGainDelta_t10;
    A_UINT8  thermCalVal;
    A_UINT8  pad[3];
} _TX_PWR_CAL_DATA_PER_CHAN;

typedef struct _txPwrCALData {
    A_UINT32 channel;
    A_UINT32 wlanMode;
    A_UINT32 numMeasure;
    _TX_PWR_CAL_DATA_PER_CHAN txPwrDataPerChanChain[_MAX_MEASUREMENT_PER_CHAN][_MAX_CHAINS][_MAX_TX_GAIN_IDX_SIZE][_MAX_DAC_SIZE];  // potentially for different rates
} _TX_PWR_CAL_DATA;
   
// globals & static
_TX_PWR_CAL_DATA txPwrCAL[_MAX_CAL_TX_CHANNELS];
int _CALTxChanIdx=0;
A_INT32 devPM;
   
#define _NAME_MAX  48
//#define _LABEL_MAX  CUSTOMER_DATA_SIZE
#define _LABEL_MAX  16
typedef struct _calSetup {
    double         attenDUT2PM_5G;
    double         attenDUT2PM_2G;
    char           testflowBinFilename[_NAME_MAX];
    char           goldenBinFilename[_NAME_MAX];
    char           outputBinFilename[_NAME_MAX];
    char           label[_LABEL_MAX];
} _CAL_SETUP;
_CAL_SETUP  calSetup = {
    19.0,
    18.0,
    "calTestFlow.bin",
    "boardData_1_0.bin",
    "new_boardData_1_0.bin",
    "wbgf10_010_d0001",
};

// Local
static int _pBufTotalPwr=0;
static int _pBufRead=0;
static double power4Dbg[_RING_BUFFER_SIZE];
//static _CMD_ALL_PARMS _cmdParms; 
static FILE *dbgFp;

// function definitions

#define WHAL_IS_MODE_A(_c)       (((_c) == MODE_11A) || \
                                  ((_c) == MODE_11NA_HT20) || \
                                  ((_c) == MODE_11NA_HT40))
#define WHAL_IS_MODE_B(_c)       ((_c) == MODE_11B)
#define WHAL_IS_MODE_G(_c)       (((_c) == MODE_11G) || \
                                  ((_c) == MODE_11GONLY) || \
                                  ((_c) == MODE_11NG_HT20) || \
                                  ((_c) == MODE_11NG_HT40))

// measure power
#define MIMO_2X2_COMP 3.0
static A_BOOL readOneTxPwr(A_INT32 *txPwr_t10, A_UINT32 channel, A_UINT32 dataRate, A_UINT32 gainIdx, A_UINT32 txChain, A_UINT32 wlanMode, A_UINT32 dac )
{
    A_BOOL rc=FALSE;
    _TX_CAL_READ txPwrReadState=_txPwrHuntFirst;
    double pwr; 
    A_INT32 storedPwr[_MAX_STORED_PWR];
    int i, _storedPwrIdx=0;
    A_BOOL gotPwrReading = FALSE;
    double  atten=0; 

    //if (WHAL_IS_MODE_A(wlanMode)) atten = (calSetup.attenDUT2PM_5G - calSetup.attenDUT2PM_2G); 
    if (channel >= 4900)
    {
        /* for 5G channel use large attenuation */
        atten = (calSetup.attenDUT2PM_5G - calSetup.attenDUT2PM_2G);
    }

    while(_pBufRead < _pBufTotalPwr) {
        //pwr = power4Dbg[_pBufRead++] + atten + MIMO_2X2_COMP ; 
        pwr = power4Dbg[_pBufRead++] + atten; 

        if ((_INVALID_PWR_LOWEND > pwr ) || (_INVALID_PWR_HIGHEND < pwr)) {
            if (_txPwrHuntFirst == txPwrReadState) {
                // keep hunting
            } 
            else if (_txPwrReadPhase == txPwrReadState) {
                // back track 1 reading
                if (_storedPwrIdx > 1) {
                    _storedPwrIdx--;
                    _pBufRead--;
                }
                gotPwrReading = TRUE;
                break;  // we are done
            } 
            else if (_txPwrReady4First == txPwrReadState) {
                break;
            }
            else {
                printf("Unknown state %d\n", txPwrReadState);
                break;
            }
        }
        else {
            if (_txPwrHuntFirst == txPwrReadState) {
                txPwrReadState = _txPwrReady4First;  // skip 1st reading 
            }
            else if ( _txPwrReady4First == txPwrReadState) {  // starting 2nd reading
                txPwrReadState = _txPwrReadPhase; 
            }
            if ( _txPwrReadPhase == txPwrReadState) { // record since 2nd reading
                storedPwr[_storedPwrIdx++] = POWER_T10(pwr);
            }
        }
    }
    if (gotPwrReading) {
        A_INT32 sum =0;
        for (i=0;i<_storedPwrIdx;i++) {
            sum += storedPwr[i];
        }
        *txPwr_t10 = sum / _storedPwrIdx;
        rc = TRUE;
    }
    return(rc);
}

#if 0
static void extractPwrGain_new(A_UINT32 bitPos, A_UINT32 maskRow, A_UINT32 *pwrGainStart, A_UINT32 *pwrGainEnd, A_UINT32 *pwrGainStep, _CMD_TX_PARMS *txParms)
{
    A_UINT32 shift, row;
    shift = (bitPos % PWRGAIN_PER_PWRGAIN_ROW) * (PWRGAIN_PER_MASK_ROW);
    row = (bitPos / PWRGAIN_PER_PWRGAIN_ROW) + maskRow * (PWRGAIN_PER_MASK_ROW);
    *pwrGainStart = (txParms->pwrGainStart[row] >> shift) & PWRGAIN_MASK;
    *pwrGainEnd   = (txParms->pwrGainEnd[row] >> shift) & PWRGAIN_MASK;
    *pwrGainStep  = (txParms->pwrGainStep[row] >> shift) & PWRGAIN_MASK;
    NEGATE(*pwrGainStart);
    NEGATE(*pwrGainEnd);   
    NEGATE(*pwrGainStep);
    return;
}
#endif

#define _MAX_QUIET_COUNT 10
void readAllPwr(void)
{
    //A_INT32 wdCounter=100000;
    A_UINT32 quietCount=_MAX_QUIET_COUNT;
    double pwr; 
    double  atten = calSetup.attenDUT2PM_2G; 

    while(1) {  // need a watch dog? 
         
        pwr = pmMeasAvgPower(devPM, 0) + atten;
        printf("DUT-> %5.2f dBm\n",pwr); 
        power4Dbg[_pBufTotalPwr++] = pwr;

        if ((_INVALID_PWR_LOWEND > pwr ) || (_INVALID_PWR_HIGHEND < pwr)) {
            quietCount--;
            if (!(configBitmap & _TX_FOREVER)) {
                if (!quietCount) {
                    printf("Done %d\n", _pBufTotalPwr);
                    break;   // no more tx from DUT
                }
            }
        }
        else {
            quietCount=_MAX_QUIET_COUNT;
        }
    }
    return;
}

void postProcessPwrPerBand(_CHANNEL_LIST *pCALChannelList, A_UINT32 numCALChannels)
{
        A_UINT32 ii, k, /*kk,*/ jj; 
        A_UINT32 dataRate, channel;
        A_UINT32 gainIdx;    
        A_INT32  txPwr_t10;
        _TX_PWR_CAL_DATA *pTxPwrCAL;
        A_UINT32 chainIdx;
        A_UINT32 maxChainsActual;
        A_UINT32 chainMask;
        A_INT32  dac;

        if (configBitmap & _TX_VERIFY) {
            maxChainsActual = _VERIFY_CHAINS;
        } else {
            maxChainsActual = _MAX_CHAINS;
        }

        for (ii=0;ii<numCALChannels;ii++) {
            channel= pCALChannelList[ii].channel;
            pTxPwrCAL = &txPwrCAL[_CALTxChanIdx];
            _CALTxChanIdx++;
            pTxPwrCAL->channel = channel;
            pTxPwrCAL->wlanMode = pCALChannelList[ii].wlanMode;
            pTxPwrCAL->numMeasure = 0;
            for (k=0; k<NumCALRates; k++) {
                dataRate = CALRateList[k];
                for (jj=0; jj<pCALChannelList[ii].numChainMasks; jj++) {
                    chainMask = pCALChannelList[ii].calChainMasksList[jj].chainMask;
                    // For CAL only, it must be single chain, idx would be: chain 1->0, etc.
                    //chainIdx = chainMask -1;  // TBD: condtion on CAL only
                    chainIdx = (chainMask >> 1);  // TBD: condtion on CAL only
                    // for point A
                    /*for (j=0;j<NumCALGainIdxes;j++) */ {
                        gainIdx=pCALChannelList[ii].calChainMasksList[jj].gainIdx.gainIdx_ptA;
                        //for (kk=0;kk<NumCALDACValues;kk++) {
                            //dac=CALDACValues[kk];
                            dac=pCALChannelList[ii].dac.dac_ptA;
                            if (readOneTxPwr(&txPwr_t10, channel, dataRate, gainIdx, chainIdx, pTxPwrCAL->wlanMode, dac )) { 
                                if (configBitmap & _TX_VERIFY) {
                                    printf("chan %d rate %d chain %d gainIdx %d dac %d pwr %5.2f \n", 
                                           (int)channel, (int)dataRate, (int)chainIdx, (int)gainIdx, (int)dac, (float)txPwr_t10/8.0);
                                } else {
                                    printf("chan %d rate %d chain %d gainIdx %d dac %d pwr_t8 %d pwr %f\n", 
                                           (int)channel, (int)dataRate, (int)chainIdx, (int)gainIdx, (int)dac, (int)txPwr_t10, ((float)txPwr_t10)/8.0);
                                }

                                pTxPwrCAL->numMeasure++;   
                                pTxPwrCAL->txPwrDataPerChanChain[dataRate][chainIdx][gainIdx][_dacIdx(dac)].pwr_t10 = txPwr_t10;
                                pTxPwrCAL->txPwrDataPerChanChain[dataRate][chainIdx][gainIdx][_dacIdx(dac)].thermCalVal=0;//readOneThermCalVal()
                            }
                            else {
                                printf("Error: chan %d rate %d chain %d gain %d dac %d no valid power\n", (int)channel, (int)dataRate, (int)chainIdx, (int)gainIdx, (int)dac);
                            }
                        //}
                    }
                    // for point B
                    /*for (j=0;j<NumCALGainIdxes;j++) */ {
                        gainIdx=pCALChannelList[ii].calChainMasksList[jj].gainIdx.gainIdx_ptB;
                        //for (kk=0;kk<NumCALDACValues;kk++) {
                            //dac=CALDACValues[kk];
                            dac=pCALChannelList[ii].dac.dac_ptB;
                            if (readOneTxPwr(&txPwr_t10, channel, dataRate, gainIdx, chainIdx, pTxPwrCAL->wlanMode, dac )) { 
                                if (configBitmap & _TX_VERIFY) {
                                    printf("chan %d rate %d chain %d gainIdx %d dac %d pwr %5.2f \n", 
                                           (int)channel, (int)dataRate, (int)chainIdx, (int)gainIdx, (int)dac, (float)txPwr_t10/8.0);
                                } else {
                                    printf("chan %d rate %d chain %d gainIdx %d dac %d pwr_t8 %d pwr %f\n", 
                                           (int)channel, (int)dataRate, (int)chainIdx, (int)gainIdx, (int)dac, (int)txPwr_t10, ((float)txPwr_t10)/8.0);
                                }

                                pTxPwrCAL->numMeasure++;   
                                pTxPwrCAL->txPwrDataPerChanChain[dataRate][chainIdx][gainIdx][_dacIdx(dac)].pwr_t10 = txPwr_t10;
                                pTxPwrCAL->txPwrDataPerChanChain[dataRate][chainIdx][gainIdx][_dacIdx(dac)].thermCalVal=0;//readOneThermCalVal()
                            }
                            else {
                                printf("Error: chan %d rate %d chain %d gain %d dac %d no valid power\n", (int)channel, (int)dataRate, (int)chainIdx, (int)gainIdx, (int)dac);
                            }
                        //}
                    }
                }
            }
        }
} 

void postProcessAllPwr(void)
{
#if defined(_2G_READY)
    postProcessPwrPerBand(CALChannelList2G, NumCALChannels2G);
#endif //#if defined(_2G_READY)

    postProcessPwrPerBand(CALChannelList5G, NumCALChannels5G);
}


static void dumpAllPower(void)
{
    int i,j,chain, jj, kk;
    _TX_PWR_CAL_DATA *pTxPwrCAL;
    A_UINT32 gainIdx;
    A_INT32 dac;

    A_UINT32 maxChainsActual;

    if (configBitmap & _TX_VERIFY) {
        maxChainsActual = _VERIFY_CHAINS;
    } else {
        maxChainsActual = _MAX_CHAINS;
    }


    for (i=0;i<_CALTxChanIdx;i++) {
        pTxPwrCAL = &txPwrCAL[i];
        fprintf(dbgFp, "channel %d:\n", (int)pTxPwrCAL->channel);
        for (chain=0; chain < maxChainsActual; chain++) {
            fprintf(dbgFp, "    chain %d: rate gainIdx dac pwr_t10\n", chain);
            for (j=0;j<pTxPwrCAL->numMeasure;j++) {
                for (jj=0;jj<NumCALGainIdxes;jj++) {
                    gainIdx=CALGainIdxList[jj];
                    for (kk=0;kk<NumCALDACValues;kk++) {
                        dac=CALDACValues[kk];
                        fprintf(dbgFp, "%d               %d     %d     %d\n", 
                            (int)j, (int)gainIdx, (int)dac, 
                            (int)pTxPwrCAL->txPwrDataPerChanChain[j][chain][gainIdx][_dacIdx(dac)].pwr_t10);
                    }
                }
            }
        }
    }
}

#define _GAIN_T10_2_T2(x) (((x) < 0) ? ((x) - 5) : ((x) + 5))
#define _MAX_CALIBRATED_RATES_OTHER_THAN_6M  8
static _AthDataRate RatesCalibrated[] = {ATH_RATE_1M, ATH_RATE_11M, ATH_RATE_36M, ATH_RATE_54M, ATH_RATE_6_5M, ATH_RATE_65M, ATH_RATE_HT40_13_5M, ATH_RATE_HT40_135M};
static const A_UINT32 MaxRatesCalibrated = sizeof(RatesCalibrated)/sizeof(_AthDataRate); 
static void computeCALData(_CAL_SETUP *pCalSetup)
{
    int i, numCALFreq2G, numCALFreq5G;
    _TX_PWR_CAL_DATA *pTxPwrCAL;
    AR6000_EEPROM eepromData, *pEepromData=&eepromData;
    A_BOOL rc;
    int chain, chainIdx, idx;
    A_UINT32 gainIdx;
    A_INT32  dac;
    _CHANNEL_LIST *pCALChannelList; 

    // read in golden bin 
    rc = readCalDataFromFileBin(pCalSetup->goldenBinFilename, pEepromData);
    assert(rc);

    // apply CAL data selection algorithm ... TBD??
    // for now, fixed tx gain idx and DAC, _CALPointA and _CALPointB ...

    // update channels & fields
    numCALFreq2G = numCALFreq5G =0;
    pCALChannelList = CALChannelList2G;
    for (i=0;i<NumCALChannels2G;i++) {
        pTxPwrCAL = &txPwrCAL[i];
        for (chain=0;chain<pCALChannelList[i].numChainMasks;chain++) {  
            //chainIdx = CALChainMaskList[chain] -1;
            chainIdx = pCALChannelList[i].calChainMasksList[chain].chainMask >> 1;

            { // populate CAL data
                            pEepromData->calFreqPier2G[numCALFreq2G] = FREQ2FBIN(pTxPwrCAL->channel, 1);
                            pEepromData->calPierData2G[numCALFreq2G].thermCalVal = _THERM_CAL_VAL;
                            pEepromData->calPierData2G[numCALFreq2G].voltCalVal  = _VOLT_CAL_VAL;
                            gainIdx=pCALChannelList[i].calChainMasksList[chain].gainIdx.gainIdx_ptA;
                            dac=pCALChannelList[i].dac.dac_ptA;
                            pEepromData->calPierData2G[numCALFreq2G].calPerPoint[chainIdx].txgainIdx[0] = (A_UINT8)gainIdx;
                            pEepromData->calPierData2G[numCALFreq2G].dacGain[0]   = (A_INT8)dac;
                            pEepromData->calPierData2G[numCALFreq2G].calPerPoint[chainIdx].power_t8[0] = (A_INT16)pTxPwrCAL->txPwrDataPerChanChain[CALRateList[0]][chainIdx][gainIdx][_dacIdx(dac)].pwr_t10; 
                            gainIdx=pCALChannelList[i].calChainMasksList[chain].gainIdx.gainIdx_ptB;
                            dac=pCALChannelList[i].dac.dac_ptB;
                            pEepromData->calPierData2G[numCALFreq2G].calPerPoint[chainIdx].txgainIdx[1] = (A_UINT8)gainIdx;
                            pEepromData->calPierData2G[numCALFreq2G].dacGain[1]   = (A_INT8)dac;
                            pEepromData->calPierData2G[numCALFreq2G].calPerPoint[chainIdx].power_t8[1] = (A_INT16)pTxPwrCAL->txPwrDataPerChanChain[CALRateList[0]][chainIdx][gainIdx][_dacIdx(dac)].pwr_t10; 
            }
        }
        numCALFreq2G++;
    }
    pCALChannelList = CALChannelList5G; 
    //for (i=0;i<NumCALChannels5G;i++) {
    for (i=numCALFreq2G,idx=0;i<(NumCALChannels5G + numCALFreq2G);i++, idx++) {
        pTxPwrCAL = &txPwrCAL[i];
        for (chain=0;chain<pCALChannelList[idx].numChainMasks;chain++) {  
            //chainIdx = CALChainMaskList[chain] -1;
            chainIdx = pCALChannelList[idx].calChainMasksList[chain].chainMask >> 1;

            { // populate CAL data
                //printf("ch %d %d\n", pTxPwrCAL->channel, FREQ2FBIN(pTxPwrCAL->channel, 0));
                            pEepromData->calFreqPier5G[numCALFreq5G] = FREQ2FBIN(pTxPwrCAL->channel, 0);
                            pEepromData->calPierData5G[numCALFreq5G].thermCalVal = _THERM_CAL_VAL;
                            pEepromData->calPierData5G[numCALFreq5G].voltCalVal  = _VOLT_CAL_VAL;
                            gainIdx=pCALChannelList[idx].calChainMasksList[chain].gainIdx.gainIdx_ptA;
                            dac=pCALChannelList[idx].dac.dac_ptA;
                            pEepromData->calPierData5G[numCALFreq5G].calPerPoint[chainIdx].txgainIdx[0] = gainIdx;
                            pEepromData->calPierData5G[numCALFreq5G].dacGain[0]   = dac;
                            pEepromData->calPierData5G[numCALFreq5G].calPerPoint[chainIdx].power_t8[0] = 
                                pTxPwrCAL->txPwrDataPerChanChain[CALRateList[0]][chainIdx][gainIdx][_dacIdx(dac)].pwr_t10; 
                            gainIdx=pCALChannelList[idx].calChainMasksList[chain].gainIdx.gainIdx_ptB;
                            dac=pCALChannelList[idx].dac.dac_ptB;
                            pEepromData->calPierData5G[numCALFreq5G].calPerPoint[chainIdx].txgainIdx[1] = gainIdx;
                            pEepromData->calPierData5G[numCALFreq5G].dacGain[1]   = dac;
                            pEepromData->calPierData5G[numCALFreq5G].calPerPoint[chainIdx].power_t8[1] = 
                                pTxPwrCAL->txPwrDataPerChanChain[CALRateList[0]][chainIdx][gainIdx][_dacIdx(dac)].pwr_t10; 
            }
        }
        numCALFreq5G++;
    }
    // mark all other channels as unused
    for (i=numCALFreq2G;i<WHAL_NUM_11G_CAL_PIERS;i++) {
            pEepromData->calFreqPier2G[i] = 255;
    }
    for (i=numCALFreq5G;i<WHAL_NUM_11A_CAL_PIERS;i++) {
            pEepromData->calFreqPier5G[i] = 255;
    }

    // update label
    //memcpy((void*)&(pEepromData->baseEepHeader.custData[0]), pCalSetup->label, sizeof(pCalSetup->label));
    
    // Generate bin
    rc = genEepromBinFile(pCalSetup->outputBinFilename, pEepromData);
    assert(rc);

    return;
}

static A_BOOL parseSetupFile(_CAL_SETUP *pCalSetup)
{
    FILE *fStream;
    char lineBuf[MAX_LINE_BUF], *pLine;
    char delimiters[] = " \t\n\r;=";
    char calsetupFileName[48] ="calsetup.txt";
    A_BOOL rc=TRUE;

    if( (fStream = fopen( (const char*) calsetupFileName, "r")) == NULL ) {
        printf("Error open %s\n", calsetupFileName);
        return(FALSE);
    }

    while(fgets(lineBuf, (MAX_LINE_BUF - 2), fStream) != NULL) {
        pLine = lineBuf;

        while(isspace(*pLine)) pLine++;

        if(*pLine == '#') {
            continue;
        }
        else if(strnicmp("ATTEN_DUT_PM", pLine, strlen("ATTEN_DUT_PM")) == 0) {
            pLine = strchr(pLine, '=');
            pLine = strtok(pLine, delimiters);
            if(!sscanf(pLine, "%lf", &calSetup.attenDUT2PM_5G)) {
                printf("Unable to read the ATTEN_DUT_PM from %s\n", calsetupFileName);
            }
        }
        else if(strnicmp("11b_ATTEN_DUT_PM", pLine, strlen("11b_ATTEN_DUT_PM")) == 0) {
            pLine = strchr(pLine, '=');
            pLine = strtok(pLine, delimiters);
            if(!sscanf(pLine, "%lf", &(pCalSetup->attenDUT2PM_2G))) {
                printf("Unable to read the 11b_ATTEN_DUT_PM from %s\n", calsetupFileName);
            }
        }
        else if((strnicmp("TESTFLOW_BIN_FILENAME", pLine, strlen("TESTFLOW_BIN_FILENAME")) == 0) &&
	        ((pLine[strlen("TESTFLOW_BIN_FILENAME")] == ' ') || 
	         (pLine[strlen("TESTFLOW_BIN_FILENAME")] == '\t') ) ){
            pLine = strchr(pLine, '=');
            pLine = strtok(pLine, delimiters);
            if(!sscanf(pLine, "%s", pCalSetup->testflowBinFilename)) {
                printf("Unable to read the TESTFLOW_BIN_FILENAME from %s\n", calsetupFileName);
            }
            else {
            }
        }
        else if((strnicmp("GOLDEN_BIN_FILENAME", pLine, strlen("GOLDEN_BIN_FILENAME")) == 0) &&
	        ((pLine[strlen("GOLDEN_BIN_FILENAME")] == ' ') || 
	         (pLine[strlen("GOLDEN_BIN_FILENAME")] == '\t') ) ){
            pLine = strchr(pLine, '=');
            pLine = strtok(pLine, delimiters);
            if(!sscanf(pLine, "%s", pCalSetup->goldenBinFilename)) {
                printf("Unable to read the GOLDEN_BIN_FILENAME from %s\n", calsetupFileName);
            }
            else {
            }
        }
        else if((strnicmp("OUTPUT_BIN_FILENAME", pLine, strlen("OUTPUT_BIN_FILENAME")) == 0) &&
	        ((pLine[strlen("OUTPUT_BIN_FILENAME")] == ' ') || 
	         (pLine[strlen("OUTPUT_BIN_FILENAME")] == '\t') ) ){
            pLine = strchr(pLine, '=');
            pLine = strtok(pLine, delimiters);
            if(!sscanf(pLine, "%s", pCalSetup->outputBinFilename)) {
                printf("Unable to read the OUTPUT_BIN_FILENAME from %s\n", calsetupFileName);
            }
            else {
            }
        }
        else if((strnicmp("LABEL", pLine, strlen("LABEL")) == 0) &&
	        ((pLine[strlen("LABEL")] == ' ') || 
	         (pLine[strlen("LABEL")] == '\t') ) ){
            pLine = strchr(pLine, '=');
            pLine = strtok(pLine, delimiters);
            if(!sscanf(pLine, "%s", pCalSetup->label)) {
                printf("Unable to read the LABEL from %s\n", pCalSetup->label);
            }
            else {
            }
        }
    }  // End while (get line)
    fclose(fStream);
    return(rc);
}
/* parseSetupFile(_CAL_SETUP *pCalSetup) */


const char *progname;
const char commands[] =
"commands:\n\
--txsweep\n\
--forever\n\
--verify\n\
";

static void
usage(void)
{
    fprintf(stderr, "usage:\n%s [-i device] commands\n", progname);
    fprintf(stderr, "%s\n", commands);
    fprintf(stderr, "Incorrect usage");
}
    
static int processCmdLine(int argc, char **argv)
{
    int c;

    progname = argv[0];

    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"txsweep", 0, NULL, 't'},
            {"forever", 0, NULL, 'f'},
            {"verify",  0, NULL, 'v'},
            {0, 0, 0, 0}
        };

        c = getopt_long(argc, argv, "t",
                         long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
        case 't':
            configBitmap |= _TX_SWEEP;    
            break;
        case 'f':
            configBitmap |= _TX_FOREVER;    
            break;
        case 'v':
            configBitmap |= _TX_VERIFY;
            break;
        default:
            usage();
            break;
        }
    }

    return(0);
}


extern A_BOOL readBinStreamFile(char *fileName, A_UINT8 **pReadCmdStream, A_UINT32 *readStreamLen);

int main(int argc, char *argv[])
{
    // check argc/argv, but it's a TEST program ... move on.
    // 
    A_BOOL rc=FALSE;

    if (-1 == processCmdLine(argc, argv)) return -1;

    // parse calSetup.txt
    rc = parseSetupFile(&calSetup);
    assert(rc);

    // now we have all tx channels, ready for pwr reading
    //
    // setup PM
    devPM = pmInit(0, NRP_Z11);
    if (-1 == devPM) {
        return -1;
    }
    // measuer all power
    readAllPwr();

    // "post-processing" power measurement
    postProcessAllPwr();
    
    // 
    // off PM
    psClose();

#if defined(_DEBUG)
    {
    int i;
    if ( (dbgFp = fopen("_pwr4Debg.txt", "w")) == NULL) {
        printf("Error: open _pwr4Debug\n");
        return -1;
    }
    fprintf(dbgFp, "\n All measurement\n");
    for (i=0;i<_pBufTotalPwr;i++) {
        fprintf(dbgFp, "%f ", power4Dbg[i]); 
    }

    // selected power
    fprintf(dbgFp, "\n\n Selected power\n");
    dumpAllPower();

    if (dbgFp) fclose(dbgFp);
    }
#endif
 
    // computation of manuf CAL data, 1st version, 5/4/2011
    // For each channel, only MCS7 rate
    //     ensure olpc CAL settings: olpcGainDelta=0,alphaTherm=0,forcedGain
    //     olpcGainDelta = txPwr - pcDac + desiredScale

    // computation of manuf CAL data, 2nd version, 5/4/2011
    // For each channel,
    //     ensure olpc CAL settings: olpcGainDelta=0,alphaTherm=0,forcedGain
    //     For each rate, 
    //         olpcGainDelta = txPwr - pcDac + desiredScale
    //     Compare the olpcGainDelta vales for all rates
    //         pick the medium value
    //         adjust the desired scale of other rates: 
    //             desiredScale = pcDac - txPwr + (selected)olpcGainDelta
    if (!(configBitmap & _TX_SWEEP)) {
        computeCALData(&calSetup);
    }

    return 0;
}

