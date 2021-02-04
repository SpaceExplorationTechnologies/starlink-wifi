/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#if !defined(_RXGAINCAL_H)
#define _RXGAINCAL_H

#define MAX_RXG_CAL_CHANS_2G   4
#define MAX_RXG_CAL_CHANS_5G   4

#ifndef MAX_RXG_CAL_CHANS
#define MAX_RXG_CAL_CHANS      (MAX_RXG_CAL_CHANS_5G)
#endif

#define MAX_NUM_CHAINS 4

#define RXGAINCAL_NUM_PACKETS 100
#define RXGAINCAL_SIG_IN_DBM_N80 -80
#define RXGAINCAL_CCA_INJSIG_IN_DBM_N62 -62


/*----------------------------------------------
 *    Data
 */

typedef struct {
    A_UINT8     band;
    A_UINT8     chan;
    A_UINT8     chain;
    A_UINT8     chainMask;
} FORCED_RX_PARM;


typedef struct {
    A_UINT8    numBand;
    A_UINT8    idxChan;
    A_UINT8    idxChain;
    A_INT8     idxCalPt;
} RXGAIN_CAL_LOOP;

typedef struct {
    WHAL_CHANNEL curCALChan;
    A_UINT8      freqInByte;
    A_UINT8      calBand;
    A_UINT8      status;
    FORCED_RX_PARM rxParm;
    CAL_LOOP calLoop;
} RXGAIN_CAL_STATE;

void initRxGainCal(void);

#if 0

typedef struct {
    A_UINT8  bandMask;
    A_INT8   refISS;	
    A_UINT8  rate;
    A_UINT8  bandWidth;
    A_UINT8  numChan;
    A_UINT8  numChain;
    A_UINT16 numPkts;
    A_UINT8  chans[MAX_RXG_CAL_CHANS];  
    A_UINT8  chainMasks[4]; //MAX_NUM_CHAINS];
} __ATTRIB_PACK RXGAIN_CAL_CFG;


#else

#define MAX_NUM_CHAINS 4

/*
 * Data structure for board data update, and generate board data file
 */
typedef struct {
    A_INT8    rxNFCalPowerDBr[MAX_NUM_CHAINS];            
    A_INT8    rxNFCalPowerDBm[MAX_NUM_CHAINS]; 
    A_UINT8   rxTempMeas[MAX_NUM_CHAINS];                          
    A_INT8    rxNFThermCalSlope[MAX_NUM_CHAINS];  
    A_INT8    minCcaThreshold[MAX_NUM_CHAINS];
} __ATTRIB_PACK RXGAIN_CAL_DATA_I;                                  //20B

typedef struct {
    A_UINT8  bandMask;
    A_INT8   refISS;
    A_UINT8  rate;
    A_UINT8  bandWidth;
    A_UINT8  numChan;
    A_UINT8  numChain;
    A_UINT16 numPkts;
    A_UINT8  chans[MAX_RXG_CAL_CHANS];
    A_UINT8  chainMasks[MAX_NUM_CHAINS];
} __ATTRIB_PACK RXGAIN_CAL_CFG_I;                                     //16B

typedef struct {
    RXGAIN_CAL_CFG_I      rxGainCalCfg;                           // 16B
    RXGAIN_CAL_DATA_I     rxGainCalResult[MAX_RXG_CAL_CHANS];     // 80B = 20B*4
} __ATTRIB_PACK RXGAIN_CAL_TABLE_I;

#endif

typedef struct {
    A_UINT8  bandMask;
    A_INT8   refISS;	
    A_UINT8  rate;
    A_UINT8  bandWidth;
    A_UINT8  Channel;
    A_UINT8  Chain;
    A_UINT16 numPkts;
} RXGAIN_CAL_RSP;

/*
 * Data structure for board data update, and generate board data file
 */



typedef enum {
    RX_PROG_NONE=0,
    RX_PROG_CHAIN_MASK,
    RX_PROG_CHAN,
    RX_PROG_BAND,
} RXCAL_LOOP_NEXT_ACTION;

typedef enum
{
    RF_SUBBAND_2_4_GHZ      = 0,
    RF_SUBBAND_5_LOW_GHZ    = 1,    //Low & Mid U-NII
    RF_SUBBAND_5_MID_GHZ    = 2,    //ETSI
    RF_SUBBAND_5_HIGH_GHZ   = 3,    //High U-NII
    RF_SUBBAND_4_9_GHZ      = 4,    //Japanese


    NUM_RF_SUBBANDS,

    MAX_RF_SUBBANDS,
    INVALID_RF_SUBBAND,

    RF_BAND_2_4_GHZ        = 0,
    RF_BAND_5_GHZ          = 1,
    NUM_RF_BANDS,
    BOTH_RF_BANDS,
    RF_SUBBAND_INVALID = 0x7FFFFFFF  /* define as 4 bytes data */
}RF_BANDS;

#endif //#if !defined(_RXGAINCAL_H)


