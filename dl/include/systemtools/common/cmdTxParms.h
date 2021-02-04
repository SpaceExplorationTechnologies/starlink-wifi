/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#if !defined(_CMD_TX_PARMS_H)
#define _CMD_TX_PARMS_H

// ---------------------------
// Important: There can ONLY be one typedef struct per each cmd parameter structure
//    Parser is not intelligent enough and needs this guarantee.
//

#include "art_utf_common.h"
#include "parmBinTemplate.h"


// pwrGainType
#define PWRGAINTYPE_TGTPWR       0x1
#define PWRGAINTYPE_FORCED_PWR   0x2
#define PWRGAINTYPE_FORCED_GAIN  0x4
#define PWRGAINTYPE_RESERVED     0x8
#define PWRGAINTYPE_SHIFT        28
#define PWRGAINTYPE_MASK         0xF

// pwrGainBase (Low and High), outdated, now 1B each with -127 to 127dBm, after considering sweeping power
#define PWRGAINBASE_SHIFT        28
#define PWRGAINBASE_MASK         0xF
#define PWRGAIN_COMBINE(low,high)    ((((high) << 8) & 0xF0) | ((low) & 0x0F))

// pwrGain: pwr 0.5dB step, gain(PCDAC) 1=0.5dB

// 
// Map data rate to power/gain
//
#define RATE_MASK_ROW_MAX_11N    2
#define RATE_MASK_BIT_MAX        32
#define PWRGAIN_11AC_ROW_MAX     27
#define RATE_MASK_ROW_MAX_11AC   4
#define PWRGAIN_ROW_MAX      ((RATE_MASK_ROW_MAX_11N * RATE_MASK_BIT_MAX) / 4)
#define PWRGAIN_MASK                  0xFF
#define PWRGAIN_MASK_SIGN_BIT_MASK    0x80  
#define NEGATE(x) (((x) & (PWRGAIN_MASK_SIGN_BIT_MASK)) ? ((x) = 128 - (x)) : (x))
#define PWRGAIN_PER_PWRGAIN_ROW      4
#define PWRGAIN_PER_MASK_ROW         8
#define MAX_TX_CHAIN                 4
#define LEN_PAD                      2

typedef enum {
    _txParm_code_channel=0,
    _txParm_code_txMode,
    _txParm_code_rateMask0,
    _txParm_code_rateMask1,
    _txParm_code_pwrGainStart0,   // cck 
    _txParm_code_pwrGainStart1,   // ofdm
    _txParm_code_pwrGainStart2,   // ht20-1
    _txParm_code_pwrGainStart3,   // ht40-1
    _txParm_code_pwrGainStart4,   // ht20-2
    _txParm_code_pwrGainStart5,   // ht40-2
    _txParm_code_pwrGainStart6,   // ht40-2
    _txParm_code_pwrGainStart7,   // ht40-2
    _txParm_code_pwrGainStart8,   // ht40-2
    _txParm_code_pwrGainStart9,   // ht40-2
    _txParm_code_pwrGainStart10,   // ht40-2
    _txParm_code_pwrGainStart11,   // ht40-2
    _txParm_code_pwrGainStart12,   // ht40-2
    _txParm_code_pwrGainStart13,   // ht40-2
    _txParm_code_pwrGainStart14,   // ht40-2
    _txParm_code_pwrGainStart15,   // ht40-2
    _txParm_code_pwrGainEnd0,     // cck 
    _txParm_code_pwrGainEnd1,     // ofdm
    _txParm_code_pwrGainEnd2,     // ht20-1
    _txParm_code_pwrGainEnd3,     // ht40-1
    _txParm_code_pwrGainEnd4,     // ht20-2
    _txParm_code_pwrGainEnd5,     // ht40-2
    _txParm_code_pwrGainEnd6,     // ht40-2
    _txParm_code_pwrGainEnd7,     // ht40-2
    _txParm_code_pwrGainEnd8,     // ht40-2
    _txParm_code_pwrGainEnd9,     // ht40-2
    _txParm_code_pwrGainEnd10,     // ht40-2
    _txParm_code_pwrGainEnd11,     // ht40-2
    _txParm_code_pwrGainEnd12,     // ht40-2
    _txParm_code_pwrGainEnd13,     // ht40-2
    _txParm_code_pwrGainEnd14,     // ht40-2
    _txParm_code_pwrGainEnd15,     // ht40-2
    _txParm_code_pwrGainStep0,    // cck 
    _txParm_code_pwrGainStep1,    // ofdm
    _txParm_code_pwrGainStep2,    // ht20-1
    _txParm_code_pwrGainStep3,    // ht40-1
    _txParm_code_pwrGainStep4,    // ht20-2
    _txParm_code_pwrGainStep5,    // ht40-2
    _txParm_code_pwrGainStep6,    // ht40-2
    _txParm_code_pwrGainStep7,    // ht40-2
    _txParm_code_pwrGainStep8,    // ht40-2
    _txParm_code_pwrGainStep9,    // ht40-2
    _txParm_code_pwrGainStep10,    // ht40-2
    _txParm_code_pwrGainStep11,    // ht40-2
    _txParm_code_pwrGainStep12,    // ht40-2
    _txParm_code_pwrGainStep13,    // ht40-2
    _txParm_code_pwrGainStep14,    // ht40-2
    _txParm_code_pwrGainStep15,    // ht40-2
    _txParm_code_antenna,
    _txParm_code_enANI,
    _txParm_code_scramblerOff,
    _txParm_code_aifsn,
    _txParm_code_pktSz,
    _txParm_code_txPattern,
    _txParm_code_shortGuard,
    _txParm_code_numPackets,
    _txParm_code_wlanMode,
    _txParm_code_txChain0,
    _txParm_code_txChain1,
    _txParm_code_txChain2,
    _txParm_code_txChain3,
    _txParm_code_tpcm,
    _txParm_code_flags,
    _txParm_code_agg,
    _txParm_code_broadcast,
    _txParm_code_bandwidth,
    _txParm_code_bssid,
    _txParm_code_txStation,
    _txParm_code_rxStation,
    _txParm_code_reserved,
    
    _txParm_code_dutyCycle,
    _txParm_code_pattern,
    _txParm_code_reserved1,
    //The above two might be required for AR6004..

    _txParm_code_rateMask11AC0,
    _txParm_code_rateMask11AC1,
    _txParm_code_rateMask11AC2,
    _txParm_code_rateMask11AC3,

    _txParm_code_pwrGain11AC0,
    _txParm_code_pwrGain11AC1,
    _txParm_code_pwrGain11AC2,
    _txParm_code_pwrGain11AC3,
    _txParm_code_pwrGain11AC4,
    _txParm_code_pwrGain11AC5,
    _txParm_code_pwrGain11AC6,
    _txParm_code_pwrGain11AC7,
    _txParm_code_pwrGain11AC8,
    _txParm_code_pwrGain11AC9,
    _txParm_code_pwrGain11AC10,
    _txParm_code_pwrGain11AC11,
    _txParm_code_pwrGain11AC12,
    _txParm_code_pwrGain11AC13,
    _txParm_code_pwrGain11AC14,
    _txParm_code_pwrGain11AC15,
    _txParm_code_pwrGain11AC16,
    _txParm_code_pwrGain11AC17,
    _txParm_code_pwrGain11AC18,
    _txParm_code_pwrGain11AC19,
    _txParm_code_pwrGain11AC20,
    _txParm_code_pwrGain11AC21,
    _txParm_code_pwrGain11AC22,
    _txParm_code_pwrGain11AC23,
    _txParm_code_pwrGain11AC24,
    _txParm_code_pwrGain11AC25,
    _txParm_code_pwrGain11AC26,

    _txParm_code_pwrgainsweep_step,
    _txParm_code_pwrgainsweep_end,
} CMD_TX_PARMS_CODE;

#if defined(_HOST_SIM_TESTING)
#define ATH_MAC_LEN  6
#endif

typedef struct _txParm {
    A_UINT32  channel;
    A_UINT32  txMode;
    A_UINT32  rateMask[RATE_MASK_ROW_MAX_11N/*2*/];
    A_INT32   pwrGainStart[PWRGAIN_ROW_MAX/*16*/];  
    A_INT32   pwrGainEnd[PWRGAIN_ROW_MAX/*16*/];
    A_INT32   pwrGainStep[PWRGAIN_ROW_MAX/*16*/];
    A_UINT32  antenna;
    A_UINT32  enANI;
    A_UINT32  scramblerOff;
    A_UINT32  aifsn;
    A_UINT32  pktSz;
    A_UINT32  txPattern;
    A_UINT32  shortGuard;
    A_UINT32  numPackets;
    A_UINT32  wlanMode;
    A_UINT32  txChain[MAX_TX_CHAIN/*4*/];
    A_UINT32  tpcm;
    A_UINT32  flags;
    A_UINT32  agg;
    A_UINT32  broadcast;
    A_UINT32  bandwidth;
    A_UINT8   bssid[ATH_MAC_LEN/*6*/];
    A_UINT8   txStation[ATH_MAC_LEN/*6*/];
    A_UINT8   rxStation[ATH_MAC_LEN/*6*/];
    A_UINT8   reserved[LEN_PAD/*2*/]; //Add to 4B padding

    A_UINT8   dutyCycle;
    A_UINT8   nPattern;
    A_UINT16  reserved1;

    A_UINT8   dataPattern[MPATTERN/*40*/]; 
    A_UINT16  rateBitIndex[RATE_POWER_MAX_INDEX/*8*/];
    A_UINT16  txPower[RATE_POWER_MAX_INDEX/*8*/];
    A_UINT16  pktLen[RATE_POWER_MAX_INDEX/*8*/];
    A_UINT16  aggPerRate[RATE_POWER_MAX_INDEX/*8*/];
    A_UINT32  ir;
    
    //The above is required for AR6004..
    A_UINT32  rateMask11AC[RATE_MASK_ROW_MAX_11AC/*4*/];
    A_INT32   pwrGnACStart[PWRGAIN_11AC_ROW_MAX/*27*/];
    A_UINT16  pwrGnACEnd;
    A_UINT16  pwrGnACStep;

    A_UINT16   gainIdx;
    A_INT16    dacGain;

} __ATTRIB_PACK _CMD_TX_PARMS;

extern _PARM_BIN_TEMPLATE _txParm_bin_template[];

#endif // #if !defined(_CMD_TX_PARMS_H)

