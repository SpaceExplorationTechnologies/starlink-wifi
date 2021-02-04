#if !defined(_TPCCAL_H)
#define _TPCCAL_H


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
#ifndef FPGA
#include "qc900b_eeprom.h"
#else
#define WHAL_NUM_POINTS_TO_MEAS 32
#endif

/*
 * defines
 */
extern int Max_TX_CAL_Gain_ID;
#if !defined(NUM_CAL_GAINS_2G)
#define NUM_CAL_GAINS_2G  13
#define NUM_CAL_GAINS_5G  13
#endif
#define NO_TPC_CAL     0
#define TPC_CLPC       0x01
#define TPC_OLPC       0x02
#define TPC_SCPC       0x04
#define TPC_LM         0x80    // else ping-pong mode
#define MAX_CAL_CHANS_2G   12
#define MAX_CAL_CHANS_5G   32
#define MAX_CAL_CHANS      MAX_CAL_CHANS_5G

#define CAL_FLOW_LM     1

#define DAC_GAIN_DFLT  -8
#define PA_CFG_DFLT     0
#define MEAS_SKIP		0XFFF

//TBD? reuse the MAX CHAINS defined somewhere already
extern int Max_Num_Chains;

#define MAX_NUM_MEASUREMENTS ((NUM_CAL_GAINS_2G + NUM_CAL_GAINS_5G) * MAX_NUM_CHAINS)

#define MAX_CAL_DATA_SIZE_2G   256
#define MAX_CAL_DATA_SIZE_5G   512

#define MAX_CAL_GAINS_SELECTED_4_GLUT  5
#define MAX_CAL_CHANS      MAX_CAL_CHANS_5G

#define CAL_FLOW_LM     1

#define DAC_GAIN_DFLT  -8
#define PA_CFG_DFLT     0

//TBD? reuse the MAX CHAINS defined somewhere already
extern int Max_Num_Chains;

#define MAX_CAL_GAINS_SELECTED_4_GLUT  5
#define MAX_CAL_GAINS_SELECTED_4_PLUT  5

/*----------------------------------------------
 *    Data
 */
/*
 * TPC CAL state data
 */

/* TBD: CAL tx parm, shouldn't be here? */
typedef struct {
    A_UINT8     band;
    A_UINT8     chan;
    A_UINT8     chain;
    A_UINT8     chainMask;
    A_UINT8     gainIdx;
    A_INT8      dacGain;
    A_UINT8     paCfg;
    A_UINT8     tgtPwrEst;
    A_UINT8     future[0];
} FORCED_GAIN_TX_PARM;

typedef struct {
    A_UINT8    numBand;
    A_UINT8    idxChan;
    A_UINT8    idxChain;
    A_INT8     idxCalPt;
	A_UINT8	   gainSearchDone;
    A_UINT8    calFail;
    A_UINT8    calAttempts;
	A_UINT8	   failedGain;
} CAL_LOOP;

typedef struct {
    WHAL_CHANNEL curCALChan;
    A_UINT8      freqInByte;
    A_UINT8      calBand;
    A_UINT8      pad[2];
    FORCED_GAIN_TX_PARM txParm;
    CAL_LOOP     calLoop;
} TPC_CAL_STATE;

#if defined(QCA9888)
typedef struct {
    A_UINT8	tuning_gain[WHAL_NUM_POINTS_TO_MEAS];
    A_UINT8	tpc_got_power[WHAL_NUM_POINTS_TO_MEAS];
}TPC_OLPC_DPD_TUNING;
#endif

typedef enum {
    PROG_NONE=0,
    PROG_CHAIN_MASK,
    PROG_CHAN,
    PROG_BAND,
} CAL_LOOP_NEXT_ACTION;
/*
 *  TPC CAL configuration from the board data file
 */
#if !defined(NUM_CAL_GAINS_SELECTED_4_GLUT)
#define NUM_CAL_GAINS_SELECTED_4_GLUT      5
#define NUM_CAL_GAINS_SELECTED_4_PLUT      5
#endif
#define NUM_CAL_GAINS                     NUM_CAL_GAINS_5G
typedef struct {
    A_UINT8  band;
    A_UINT8  tpcScheme;
    A_UINT8  numChan;
    A_UINT8  chans[MAX_CAL_CHANS];  // MAX_CAL_CHANS = MAX(MAX_CAL_CHANS_2G, MAX_CAL_CHANS_5G);
    A_UINT8  numChain;
    A_UINT8  chainMasks[MAX_NUM_CHAINS];
    A_UINT8  numTgtPwrEst;
    A_UINT8  numGain;
    A_UINT8  tgtMeasPwr[MAX_NUM_CHAINS][NUM_CAL_GAINS_SELECTED_4_GLUT];
    A_UINT8  tgtPdadc[MAX_NUM_CHAINS][NUM_CAL_GAINS_SELECTED_4_GLUT];
    A_UINT8  gainIdx[MAX_NUM_CHAINS][WHAL_NUM_POINTS_TO_MEAS];
    A_INT8   dacGain[MAX_NUM_CHAINS][WHAL_NUM_POINTS_TO_MEAS];
    A_UINT8  paCfg[MAX_NUM_CHAINS][WHAL_NUM_POINTS_TO_MEAS];
    A_UINT8  tgtPwrEst[MAX_NUM_CHAINS][WHAL_NUM_POINTS_TO_MEAS];
    A_UINT8  pdadcThresh;
} TPC_CAL_CFG;

/*
 *  TPC CAL measured data
 */
typedef struct {
    A_INT16  measPwr[MAX_NUM_CHAINS][WHAL_NUM_POINTS_TO_MEAS];
    A_UINT8  pdadc[MAX_NUM_CHAINS][WHAL_NUM_POINTS_TO_MEAS];
    A_UINT8  numValidMeas[MAX_NUM_CHAINS];
    A_UINT8  startPwrIdx[MAX_NUM_CHAINS];
    A_UINT8  thermCal[MAX_NUM_CHAINS];
    A_UINT8  voltCal[MAX_NUM_CHAINS];
    A_UINT8  chan;
} TPC_CAL_RESULT;


/*
 *  TPC CAL post processed data
 */
typedef struct {
    A_INT16  measPwr[MAX_NUM_CHAINS][NUM_CAL_GAINS_SELECTED_4_GLUT];
    A_UINT8  gainIdx[MAX_NUM_CHAINS][NUM_CAL_GAINS_SELECTED_4_GLUT];
    A_INT8   dacGain[MAX_NUM_CHAINS][NUM_CAL_GAINS_SELECTED_4_GLUT];
    A_UINT8  paCfg[MAX_NUM_CHAINS][NUM_CAL_GAINS_SELECTED_4_GLUT];
    A_INT8   minDacGain[MAX_NUM_CHAINS][NUM_CAL_GAINS_SELECTED_4_GLUT];
    A_INT8   maxDacGain[MAX_NUM_CHAINS][NUM_CAL_GAINS_SELECTED_4_GLUT];
} TPC_CAL_POSTPROCESSED_RESULT_OLPC;

typedef struct {
    A_INT16  measPwr[MAX_NUM_CHAINS][NUM_CAL_GAINS_SELECTED_4_PLUT];
    A_UINT8  pdadc[MAX_NUM_CHAINS][NUM_CAL_GAINS_SELECTED_4_PLUT];
} TPC_CAL_POSTPROCESSED_RESULT_CLPC;

typedef struct {
    TPC_CAL_POSTPROCESSED_RESULT_OLPC olpc;
    TPC_CAL_POSTPROCESSED_RESULT_CLPC clpc;
} TPC_CAL_POSTPROCESSED_RESULT;


/*
 * Data structure for board data update, and generate board data file
 */
typedef struct {
    A_UINT32  offset2G_OLPC;
    A_UINT32  length2G_OLPC;
    A_UINT32  offset5G_OLPC;
    A_UINT32  length5G_OLPC;
    A_UINT32  offset2G_CLPC;
    A_UINT32  length2G_CLPC;
    A_UINT32  offset5G_CLPC;
    A_UINT32  length5G_CLPC;
    A_UINT8   calData2G_OLPC[MAX_CAL_DATA_SIZE_2G];
    A_UINT8   calData5G_OLPC[MAX_CAL_DATA_SIZE_5G];
    A_UINT8   calData2G_CLPC[MAX_CAL_DATA_SIZE_2G];
    A_UINT8   calData5G_CLPC[MAX_CAL_DATA_SIZE_5G];
} GEN_CAL_DATA;


/*----------------------------------------------
 *    Exported functions
 */

extern TPC_CAL_STATE  TpcCalState;

// function prototypes

// 1st level cmds responding to host I/F
/* CAL cmd processor */
void tpcCAL(void *pParms);

/* Respond to txPwr command */
void getCALPwrMeasurement(CMD_TPCCALPWR_PARMS *pParms);

/* init */
void initTPC(void);

#define  TPCCAL_DONE_MASK   0x80
#define  TPCCAL_CALDATA     0x01
#define  TPCCAL_CALINFO     0x02

#endif //#if !defined(_TPCCAL_H)

