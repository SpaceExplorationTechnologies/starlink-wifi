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

#define POWER_T8(power)                    ((A_INT32)((power) * 8))
#define OLPCGAINDELTA_T10(power,gain)       (POWER_T8(power) - ((gain) * 5) + (_DESIRED_SCALE_MCS7 * 5))
#define OLPCGAINDELTA_T10X(power_t10,gain)  ((power_t10) - ((gain) * 5) + (_DESIRED_SCALE_MCS7 * 5))

// defines
#define _RING_BUFFER_SIZE  50000
#define _INVALID_PWR_LOWEND  -5
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
#include "calTxPwrConfig_v2.txt"

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
static int wrPtr, _pBufTotalPwr=0;
static int rdPtr, _pBufRead=0;
static double power4Dbg[_RING_BUFFER_SIZE];
//static _CMD_ALL_PARMS _cmdParms; 
static FILE *dbgFp, *dbgFPtr, *measPwrFp;
static int numMeasuredPwr=0;
typedef struct {
    A_INT16   pwr;
} MEASURED_PWR;
static MEASURED_PWR measuredPwr[2048];

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
#if 0
static A_BOOL readOneTxPwr(A_INT16 *txPwr_t8)
{
    A_BOOL rc=FALSE;
    _TX_CAL_READ txPwrReadState=_txPwrHuntFirst;
    double pwr; 
    A_INT16 storedPwr[_MAX_STORED_PWR];
    int i, _storedPwrIdx=0;
    A_BOOL gotPwrReading = FALSE;

    // TBD?? need to wrap
    while(_pBufRead != _pBufTotalPwr) {
        //pwr = power4Dbg[_pBufRead++] + atten + MIMO_2X2_COMP ; 
        pwr = power4Dbg[_pBufRead]; 
        _pBufRead = (_pBufRead +1) % _RING_BUFFER_SIZE; 

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
                storedPwr[_storedPwrIdx++] = POWER_T8(pwr);
            }
        }
    }
    if (gotPwrReading) {
        A_INT32 sum =0;
        for (i=0;i<_storedPwrIdx;i++) {
            sum += storedPwr[i];
        }
        *txPwr_t8 = sum / _storedPwrIdx;
        rc = TRUE;
    }
    return(rc);
}
#endif

static void retrieveTxPwr(void)
{
    double pwr; 
    A_INT16 storedPwr[_MAX_STORED_PWR];
    int i, _storedPwrIdx=0;

    if ( (dbgFPtr = fopen("_pwr4Debg_1.txt", "w")) == NULL) {
        printf("Error: open _pwr4Debug_1\n");
        return -1;
    }
    if ( (measPwrFp = fopen("_measPwr.txt", "w")) == NULL) {
        printf("Error: open _measPwr\n");
        return -1;
    }

    rdPtr = _pBufRead;
    wrPtr = _pBufTotalPwr;
    while(rdPtr != wrPtr) {
        pwr = power4Dbg[rdPtr]; 
        rdPtr = (rdPtr +1) % _RING_BUFFER_SIZE; 

        if ((_INVALID_PWR_LOWEND > pwr ) || (_INVALID_PWR_HIGHEND < pwr)) {
            if (_storedPwrIdx == 0) { // keep hunting
            }
            else {
                A_INT16 i, sum =0;
                for (i=0;i<_storedPwrIdx;i++) {
                    sum += storedPwr[i];
                    fprintf(dbgFPtr, "%d ", storedPwr[i]);
                }
                measuredPwr[numMeasuredPwr++].pwr = sum / _storedPwrIdx;
                fprintf(dbgFPtr, ": %d\n", (sum / _storedPwrIdx));
                fprintf(measPwrFp, "%d\n", (sum / _storedPwrIdx));
                _storedPwrIdx = 0;
            }
        }
        else {
            storedPwr[_storedPwrIdx++] = (A_INT16)(pwr * 8);
        }
    }
    if (dbgFPtr) fclose(dbgFPtr);
    if (measPwrFp) fclose(measPwrFp);
    return;
}

#if 0
void retrievePwr(void)
{
    A_INT16 pwr;
    int i;
    while (_pBufRead < _pBufTotalPwr) {
        if (readOneTxPwr(&pwr)) {
            (measuredPwr[numMeasuredPwr++]).pwr = pwr;
        }
    }

    printf("numMeasuredPwr %d\n", numMeasuredPwr);
    for (i=0;i<numMeasuredPwr;i++) {
        printf("%d ", (measuredPwr[i]).pwr);
        if (!(i % 40)) printf("\n");
    }
    printf("\n");

    return;
}
#endif


#define _MAX_QUIET_COUNT 60
void readAllPwr(void)
{
    //A_INT32 wdCounter=100000;
    A_UINT32 quietCount=_MAX_QUIET_COUNT;
    double pwr; 
    double  atten; 
    atten = calSetup.attenDUT2PM_2G; 
    printf("atten %f\n", atten);

    while(1) {  // need a watch dog? 
         
        pwr = pmMeasAvgPower(devPM, 0) + atten;
        printf("DUT-> %5.2f dBm\n",pwr); 
        power4Dbg[_pBufTotalPwr] = pwr;
        _pBufTotalPwr = (_pBufTotalPwr +1) % _RING_BUFFER_SIZE;

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
static void dumpTxPwr(void) 
{
    int i;
    printf("numMeasuredPwr %d\n", numMeasuredPwr);
    for (i=0;i<numMeasuredPwr;i++) {
        printf("%d ", (measuredPwr[i]).pwr);
        if (!(i % 40)) printf("\n");
    }
    printf("\n");

}

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
    retrieveTxPwr();
    dumpTxPwr();

    // "post-processing" power measurement
    //retrievePwr();
    
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
    
    rdPtr = _pBufRead;
    wrPtr = _pBufTotalPwr;
    i=0;
    while(rdPtr != wrPtr) {
        fprintf(dbgFp, "%f ", power4Dbg[i++]); 
        rdPtr = (rdPtr +1) % _RING_BUFFER_SIZE; 
    }

    // selected power
    fprintf(dbgFp, "\n\n Selected power\n");
    for (i=0;i<numMeasuredPwr;i++) {
        fprintf(dbgFp, "%d ", (measuredPwr[i]).pwr);
    }

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
#if 0
    if (!(configBitmap & _TX_SWEEP)) {
        computeCALData(&calSetup);
    }
#endif

    return 0;
}

