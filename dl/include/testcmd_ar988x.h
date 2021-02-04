/*
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_HOSTSDK0_C$
 */

#if defined(AR9888)
#ifndef  TESTCMD_H_
#define  TESTCMD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "art_utf_common.h"

#define WMI_CMD_ID_SIZE   4
#define WMI_CMDS_SIZE_MAX 2048
#define TC_CMDS_GAP       16
// should add up to the same size as buf[WMI_CMDS_SIZE_MAX]
//#define TC_CMDS_SIZE_MAX  (WMI_CMDS_SIZE_MAX - sizeof(TC_CMDS_HDR) - WMI_CMD_ID_SIZE - TC_CMDS_GAP)  
#define TC_CMDS_SIZE_MAX  255

#define DESC_STBC_ENA_MASK          0x00000001
#define DESC_STBC_ENA_SHIFT         0
#define DESC_LDPC_ENA_MASK          0x00000002
#define DESC_LDPC_ENA_SHIFT         1
#define PAPRD_ENA_MASK              0x00000004
#define PAPRD_ENA_SHIFT             2
#define TX_STATUS_PER_RATE_MASK     0x00000008
#define TX_STATUS_PER_RATE_SHIFT    3
#define PROCESS_RATE_IN_ORDER_MASK  0x00000010
#define PROCESS_RATE_IN_ORDER_SHIFT 4
#define RX_STATUS_PER_RATE_MASK     0x00000020
#define RX_STATUS_PER_RATE_SHIFT    5

#define HALF_SPEED_MODE         50
#define QUARTER_SPEED_MODE      51

/* Continous tx
   mode : TCMD_CONT_TX_OFF - Disabling continous tx
          TCMD_CONT_TX_SINE - Enable continuous unmodulated tx
          TCMD_CONT_TX_FRAME- Enable continuous modulated tx
   freq : Channel freq in Mhz. (e.g 2412 for channel 1 in 11 g)
dataRate: 0 - 1 Mbps
          1 - 2 Mbps
          2 - 5.5 Mbps
          3 - 11 Mbps
          4 - 6 Mbps
          5 - 9 Mbps
          6 - 12 Mbps
          7 - 18 Mbps
          8 - 24 Mbps
          9 - 36 Mbps
         10 - 28 Mbps
         11 - 54 Mbps
  txPwr: twice the Tx power in dBm, actual dBm values of [5 -11] for unmod Tx,
      [5-14] for mod Tx
antenna:  1 - one antenna
          2 - two antenna
Note : Enable/disable continuous tx test cmd works only when target is awake.
*/

typedef enum {
    TPC_TX_PWR = 0,
    TPC_FORCED_GAIN,
    TPC_TGT_PWR,
    TPC_TX_FORCED_GAIN,
    TPC_FORCED_GAINIDX,
    TPC_FORCED_TGTPWR
} TPC_TYPE;

// ATENTION ATENTION... when you chnage this tructure, please also change 
// the structure TX_DATA_START_PARAMS in //olca/host/tools/systemtools/NARTHAL/common/dk_cmds.h
typedef PREPACK struct {
    A_UINT32                testCmdId;
    A_UINT32                mode;
    A_UINT32                freq;
    A_UINT32                dataRate;
    A_INT32                 txPwr;
    A_UINT32                antenna;
    A_UINT32                enANI;
    A_UINT32                scramblerOff;
    A_UINT32                aifsn;
    A_UINT32                pktSz;
    A_UINT32                txPattern;
    A_UINT32                shortGuard;
    A_UINT32                numPackets;
    A_UINT32                wlanMode;
    A_UINT32                lpreamble;
    A_UINT32	            txChain;
    A_UINT32                miscFlags;

    A_UINT32                broadcast;
    A_UCHAR                 bssid[ATH_MAC_LEN];
    A_UCHAR                 padX[2]; //Added for 4 byte alignment
    A_UINT32                bandwidth;
    A_UCHAR                 txStation[ATH_MAC_LEN];
    //A_UINT16                unUsed2;
    A_UCHAR                 rxStation[ATH_MAC_LEN];
    //A_UINT16                unUsed3;
    A_UINT32                tpcm;
    A_UINT32                retries;
    A_UINT32                agg;
    A_UINT32                nPattern;
    A_UCHAR                 dataPattern[MPATTERN]; // bytes to be written 
    A_INT16                 PsatPower2G_t10[2][PSAT_WHAL_NUM_11G_CAL_PIERS_MAX];//12B
    A_INT8                  PsatOfdmDelta2G_t10[2][PSAT_WHAL_NUM_11G_CAL_PIERS_MAX];//6B
    A_INT16                 PsatPower5G_t10[2][PSAT_WHAL_NUM_11A_CAL_PIERS_MAX]; //32B
    A_INT8                  PsatOfdmDelta5G_t10[2][PSAT_WHAL_NUM_11A_CAL_PIERS_MAX];//16B 
    A_UINT16                unUsed4;
    A_UINT32                rateMask[RATE_MASK_ROW_MAX];
    A_UINT32                ir;

    A_UINT16                 gainIdx;
    A_INT16                  dacGain;
    A_UINT32                forcedGainPad;
    A_UINT32				dutycycle;

} POSTPACK TCMD_CONT_TX;

#define TCMD_TXPATTERN_ZERONE                 0x1
#define TCMD_TXPATTERN_ZERONE_DIS_SCRAMBLE    0x2

/* Continuous Rx
 act: TCMD_CONT_RX_PROMIS - promiscuous mode (accept all incoming frames)
      TCMD_CONT_RX_FILTER - filter mode (accept only frames with dest
                                             address equal specified
                                             mac address (set via act =3)
      TCMD_CONT_RX_REPORT  off mode  (disable cont rx mode and get the
                                          report from the last cont
                                          Rx test)

     TCMD_CONT_RX_SETMAC - set MacAddr mode (sets the MAC address for the
                                                 target. This Overrides
                                                 the default MAC address.)

*/

typedef PREPACK struct {
    A_UINT32         testCmdId;
    A_UINT32        act;
    A_UINT32        enANI;
    PREPACK union {
        struct PREPACK TCMD_CONT_RX_PARA {
            A_UINT32    freq;
            A_UINT32    antenna;
            A_UINT32    wlanMode;
            A_UINT32   	ack;
            A_UINT32    rxChain;
            A_UINT32    bc;
            A_UINT32    bandwidth;
            A_UINT32    lpl;/* low power listen */
            A_UINT8    dataCheck;
            A_UINT8    unUsed[3];
        } POSTPACK para;
        struct PREPACK TCMD_CONT_RX_REPORT {
            A_UINT32    totalPkt;
            A_INT32     rssiInDBm;
            A_UINT32    crcErrPkt;
            A_UINT32    secErrPkt;
            A_UINT16    rateCnt[TCMD_MAX_RATES];
            A_UINT16    rateCntShortGuard[TCMD_MAX_RATES];
        } POSTPACK report;
        struct PREPACK TCMD_CONT_RX_MAC {
            A_UCHAR    addr[ATH_MAC_LEN];
            A_UCHAR    bssid[ATH_MAC_LEN];
            A_UCHAR    btaddr[ATH_MAC_LEN];     
            A_UINT16   regDmn[2];			
            A_UINT32   otpWriteFlag;
        } POSTPACK mac;
        struct PREPACK TCMD_CONT_RX_ANT_SWITCH_TABLE {
            A_UINT32                antswitch1;
            A_UINT32                antswitch2;
        }POSTPACK antswitchtable;
    } POSTPACK u;
} POSTPACK TCMD_CONT_RX;

/* Force sleep/wake  test cmd
 mode: TCMD_PM_WAKEUP - Wakeup the target
       TCMD_PM_SLEEP - Force the target to sleep.
 */
typedef enum {
    TCMD_PM_WAKEUP = 1, /* be consistent with target */
    TCMD_PM_SLEEP,
    TCMD_PM_DEEPSLEEP
} TCMD_PM_MODE;

typedef PREPACK struct {
    A_UINT32  testCmdId;
    A_UINT32  mode;
} POSTPACK TCMD_PM;

typedef enum {
    TC_CMDS_VERSION_RESERVED=0,
    TC_CMDS_VERSION_MDK,
    TC_CMDS_VERSION_TS,
    TC_CMDS_VERSION_LAST,
} TC_CMDS_VERSION;

typedef enum {
    TC_CMDS_TS =0,
    TC_CMDS_CAL,
    TC_CMDS_TPCCAL = TC_CMDS_CAL,
    TC_CMDS_TPCCAL_WITH_OTPWRITE,
    TC_CMDS_OTPDUMP,
    TC_CMDS_OTPSTREAMWRITE,    
    TC_CMDS_EFUSEDUMP,    
    TC_CMDS_EFUSEWRITE,    
    TC_CMDS_READTHERMAL,
    TC_CMDS_SET_BT_MODE,
    TC_CMDS_TLV,
    TC_CMDS_PSAT_CAL,
    TC_CMDS_PSAT_CAL_RESULT,
    TC_CMDS_CHAR_PSAT,
    TC_CMDS_CHAR_PSAT_RESULT,
} TC_CMDS_ACT;

typedef PREPACK struct {
    A_UINT32   testCmdId;
    A_UINT32   act;
    PREPACK union {
        A_UINT32  enANI;    // to be identical to CONT_RX struct
        struct PREPACK {
            A_UINT16   length;
            A_UINT8    version;  //The higher 4 bits are used in TCMD_WMI_ENHANCED_PIPE.
            A_UINT8    bufLen;
        } POSTPACK parm;
    } POSTPACK u;
} POSTPACK TC_CMDS_HDR;

typedef PREPACK struct {
    TC_CMDS_HDR  hdr;
#ifdef TCMD_WMI_ENHANCED_PIPE
    A_UINT8      buf[4*(TC_CMDS_SIZE_MAX+1)];
#else
    A_UINT8      buf[TC_CMDS_SIZE_MAX+1];
#endif //TCMD_WMI_ENHANCED_PIPE
} POSTPACK TC_CMDS;

#ifdef TCMD_WMI_ENHANCED_PIPE
typedef PREPACK struct {
    TC_CMDS_HDR  hdr;
    A_UINT8      buf[TC_CMDS_SIZE_MAX+1];
} POSTPACK TC_RESP_CMDS;
#endif //TCMD_WMI_ENHANCED_PIPE

typedef PREPACK struct {
    A_UINT32    testCmdId;
    A_UINT32    regAddr;
    A_UINT32    val;
    A_UINT16    flag;
} POSTPACK TCMD_SET_REG;

typedef enum {
    TCMD_CONT_TX_ID,
    TCMD_CONT_RX_ID,
    TCMD_PM_ID,
    TC_CMDS_ID,
    TCMD_SET_REG_ID,
    TC_CMD_TLV_ID,
    TCMD_CMDS_PSAT_CAL,
    TCMD_CMDS_PSAT_CAL_RESULT,
    TCMD_CMDS_CHAR_PSAT,
    TCMD_CMDS_CHAR_PSAT_RESULT,

    INVALID_CMD_ID=255,
} TCMD_ID;


//total 22B
typedef PREPACK struct {
    A_INT8  olpcGainDelta_diff; //1B ..McKinley not use
    A_INT8  olpcGainDelta_abs;  //1B
    A_UINT8 thermCalVal;        //1B
    A_UINT8 numTryBF;           //1B ..McKinley not use
    A_UINT32 cmac_olpc;         //4B
    A_UINT32 cmac_psat;         //4B
    A_UINT16 cmac_olpc_pcdac;   //2B, pcdac of target power
    A_UINT16 cmac_psat_pcdac;   //2B, pcdac of saturation power
    /*A_INT16*/A_INT8 desiredScaleAddCCK;//1B ..McKinley not use
    /*A_INT16*/A_INT8  desiredScaleAddQAM;//1B ..McKinley not use
    A_UINT16 psatParm;          //2B
    A_UINT8  chain;             //1B
    A_UINT8  freq;              //1B
} POSTPACK OLPCGAIN_THERM_DUPLET;


typedef PREPACK struct {
    OLPCGAIN_THERM_DUPLET olpcGainTherm2G[PSAT_WHAL_NUM_11G_CAL_PIERS_MAX]; //66B
    OLPCGAIN_THERM_DUPLET olpcGainTherm5G[PSAT_WHAL_NUM_11A_CAL_PIERS_MAX]; //176B
} POSTPACK PSAT_CAL_RESULTS;

// this struct doesn't exceed 255 bytes because of TC_CMDS_SIZE_MAX
#define _MAX_TX_GAIN_ENTRIES 32
typedef PREPACK struct {
    A_UINT32 cmac_i[_MAX_TX_GAIN_ENTRIES]; //128B
    A_UINT8  pcdac[_MAX_TX_GAIN_ENTRIES];  //32B

    A_UINT8  freq;                         //1B
    A_UINT8  an_txrf3_rdiv2g;              //1B
    A_UINT8  an_txrf3_pdpredist2g;         //1B
    A_UINT8  an_rxtx2_mxrgain;             //1B
    A_UINT8  an_rxrf_bias1_pwd_ic25mxr2gh; //1B
    A_UINT8  an_bias2_pwd_ic25rxrf;        //1B
    A_UINT8  an_bb1_i2v_curr2x;            //1B
    A_UINT8  an_txrf3_capdiv2g;            //1B
    A_UINT8  tx_chain_mask;                //1B

//A_UINT32 cmac_q[_MAX_TX_GAIN_ENTRIES];
} POSTPACK CHAR_PSAT_RESULTS;

typedef PREPACK union {
          TCMD_CONT_TX         contTx;
          TCMD_CONT_RX         contRx;
          TCMD_PM              pm;
          // New test cmds from ART/MDK ...
          TC_CMDS              tcCmds;          
          TCMD_SET_REG setReg;
          // for Psat
          CHAR_PSAT_RESULTS    CharPsatResults;
          PSAT_CAL_RESULTS     PsatCalResults;
} POSTPACK TEST_CMD;

typedef struct _VALUES_OF_INTEREST {
     A_UINT8 thermCAL;
     A_UINT8 future[3];
} _VALUES_OF_INTEREST;

typedef enum {
    TCMD_CAL_RESERVED=0,
    TCMD_CAL_SWEEP,
    TCMD_CAL_VERIFY,
    TCMD_CAL_BY_FORCED_GAIN_IDX,
    TCMD_CAL_BY_TGT_PWR,
} TCMD_CAL_TYPE;

#ifdef __cplusplus
}
#endif

#endif /* TESTCMD_H_ */
#endif
