#ifndef _BRDDATACMN_H_
#define _BRDDATACMN_H_

#define MAX_PERIODIC_SERVICES           16
#define HALPHY_THERMAL_TIMER_TIMEOUT    5000
#define INVALID_THERM_VALUE             0
#define MIN_VALID_THERM_VALUE           85
#define MAX_VALID_THERM_VALUE           210
#define VALID_THERM(x)                  (((x) >= MIN_VALID_THERM_VALUE) && ((x) <= MAX_VALID_THERM_VALUE))

// supported cal timer interval: 1, 2, 3, 4 and 5 intervals
typedef enum {
    UPD_INT_1_IDX = 0,
    UPD_INT_2_IDX,
    UPD_INT_3_IDX,
    UPD_INT_4_IDX,
    UPD_INT_5_IDX,
    MAX_UPD_INT_IDX = (UPD_INT_5_IDX +1),
} UPD_INT_IDX;

typedef struct tempUpdateST {
    A_UINT8   currentTemp[WHAL_NUM_CHAINS];    // code, not in degree
    A_UINT8   chosenChain;
    //A_UINT8   numValidReading;
    A_UINT8   intervalCnt;
    //A_UINT8   pad[3];
} TEMP_UPDATE_ST;

typedef enum {
    UPD_INT_1  = 1,  
    UPD_INT_2  = 2, 
    UPD_INT_3  = 3,  
    UPD_INT_4  = 4, 
    UPD_INT_5  = 5, 
    UPD_INT_LAST = UPD_INT_5,
    MAX_UPD_INT  = UPD_INT_LAST,
} PERIODIC_UPDATE_INT;

// supported temp changes
#define TEMP_CHANGE_BASE_THRESHOLD  0

#define DELTA_0C                   0x01
#define DELTA_BASE_C               DELTA_0C
#define DELTA_10C_ABOVE_BASE       0x02
#define DELTA_20C_ABOVE_BASE       0x04
#define DELTA_30C_ABOVE_BASE       0x08
#define INVALID_TEMP_DELTA         0x0

#define ROUGHLY_10C                0x7     // depending on thermal ADC, for Rome, it's roughly 1.5degC/LSb

#define INVALID_SERVICE_HANDLE 0xFF
#define INVALID_SERVICE_HANDLE_IDX 0xFF
#define PERIODIC_SERVICE_HANDLE_IDX  A_UINT8
#define IDX_2G 0
#define IDX_5G 1

typedef void (*ServiceCB)(PERIODIC_SERVICE_HANDLE_IDX idx, void *parm, WHAL_CHANNEL *chan);

typedef struct serviceHandle {
    ServiceCB                       callBk;
    void                           *parm;
    PERIODIC_SERVICE_HANDLE_IDX     updIdx;
    PERIODIC_SERVICE_HANDLE_IDX     next;
    A_UINT8                         lastTemp[IDX_5G+1][WHAL_NUM_CHAINS];
    A_UINT8                         tempChangeNotified;
    A_UINT8                         pad[1];
} PERIODIC_SERVICE_HANDLE;

typedef struct {
    A_UINT8 txGainIdx;
    A_UINT8 measuredPwr;
    //A_UINT8 paSetting; 
    //A_UINT8 pdadc;
    A_UINT8 pad[2];
} TPCDATA_PER_POINT;

typedef struct {
    A_UINT8                   alphaTherm[WHAL_NUM_CHAINS];
    A_UINT8                   thermCal[WHAL_NUM_CHAINS];
    A_UINT8                   voltCal[WHAL_NUM_CHAINS];
    A_INT8                    dacGain[WHAL_NUM_CHAINS];
#ifndef FPGA
    TPCDATA_PER_POINT         calDataPerPoint[WHAL_NUM_CHAINS][WHAL_NUM_CAL_GAINS_OLPC];
#endif
    A_UINT8                   freq;
    A_UINT8                   curTemp;
    A_UINT8                   freqIdx;
    A_UINT8                   pad[1];
} CHIP_PER_FREQ_TPC_DATA;

typedef struct {
    A_UINT8      maxThermalCal[WHAL_NUM_CHAINS];
    A_UINT8      minThermalCal[WHAL_NUM_CHAINS];
    A_UINT8      alphaThermMaxThermalCal[WHAL_NUM_CHAINS];
    A_UINT8      alphaThermMinThermalCal[WHAL_NUM_CHAINS];
    A_UINT8      numCalFreq;
    A_UINT8      numCalGainPerFreq;
    A_UINT8      curTemp;
    A_UINT8      pad[1];
} CHIP_OVERALL_TPC_DATA;


typedef struct {
    CHIP_OVERALL_TPC_DATA          tpcDataOverall;
    CHIP_PER_FREQ_TPC_DATA         tpcDataPerFreq;
} CHIP_BRDDATA;

#define CLPC_2G     0x01   // 2G - Bit 0: 0 = OLPC; 1 = CLPC
#define CLPC_5G     0x02   // 5G - Bit 1: 0 = OLPC; 1 = CLPC

typedef struct {
    A_UINT8               txGainDeltaThreshOLPC;
    A_UINT8               txGainDeltaThreshCLPC;
    A_UINT8               tpcCfgBitmap;
    A_UINT8               pad;
} CHIP_TPC_CFG_DATA;

typedef struct {
    CHIP_TPC_CFG_DATA     tpcCfgData;
} CHIP_CFG_DATA;

#define MAX_TX_GAIN_ENTRIES  32
typedef struct {
    A_UINT8 txGainTbl[MAX_TX_GAIN_ENTRIES]; 
    A_UINT8 numEntries;
    A_UINT8 pad[3];
} CHIP_DATA;

//
// Function Declarations
//

void initPeriodicUpdateTimer(void);
void deregisterService(PERIODIC_SERVICE_HANDLE_IDX deRegHandleIdx);
PERIODIC_SERVICE_HANDLE_IDX registerService(ServiceCB fp, void *parm, UPD_INT_IDX updIdx, A_UINT8 tempDelta);  
//void periodicUpdate(WHAL_CHANNEL *chan);

   
#endif //_BRDDATACMN_H_

