/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#include "tlv2Inc.h"
#include "halphy_internal.h"
#include "hal_tcmd.h"
#include "wmi_tcmd.h"
#include "tcmdHostInternal.h"
#include "utf_dev.h"
#include "testcmd.h"
#include "utf.h"
#include "tpcCal.h"
#include "tcmd_api.h"
#include "cmdRxGainCalHandler.h"
#include "rxGainCal.h"
#include "codeswap_api.h"

extern wlan_tcmd_dev_t utf_dev;
extern _CHIP_SPECIFIC_FUNC ChipFunc;
extern tcmd_rx_stat_t tcmdRxStat;
extern A_INT32 g_NoiseFloorVal[WHAL_RX_NUM_CHAIN];

// function prototypes
CAL_LOOP *rxGainCalLoop(void);
static void nextCAL(CAL_LOOP_NEXT_ACTION nextActionRxCal, CAL_LOOP *nextLoopRxCal);
static CAL_LOOP *getNextLoop(CAL_LOOP_NEXT_ACTION *nextActionRxCal);
static void send2HostNextRxCal(wlan_tcmd_dev_t *dev, CAL_LOOP *nextLoopRxCal, A_UINT32 cmd, A_UINT8 errCode);
extern void ar900BGetRxGainCalCfg(void *pRxGainCalCfg2G, void *pRxGainCalCfg5G, void *pRxGainCalRlts2G, void *pRxGainCalRlts5G);

SRAM_DATA
RXGAIN_CAL_DATA_I gRxGainCal4Chan;

SRAM_DATA
RXGAIN_CAL_CFG_I    rxGainCalCfg[2] =
{
     /*
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
         } RXGAIN_CAL_CFG_I;
         */
 	{0x0, -80, 12, 20, 2, 4, RXGAINCAL_NUM_PACKETS,
     {112, 137, 0, 0},
     {0x1, 0x2, 0x4, 0x8}},

 	{0xff, -80, 12, 20, 4, 4, RXGAINCAL_NUM_PACKETS,
     {76, 96, 140, 156},
     {0x1, 0x2, 0x4, 0x8}},
};


CMD_RXGAINCALRSP_PARMS rxGainCalParms =
{   88,
    0,
    1,
    RXGAINCAL_SIG_IN_DBM_N80,
    12,
    20,
    140,
    1,
    RXGAINCAL_NUM_PACKETS,
    {0,0}
};


SRAM_DATA
RXGAIN_CAL_STATE                  rxGainCalState;

SRAM_DATA
static CAL_LOOP *nextLoopRxCal=NULL;

SRAM_DATA
static CAL_LOOP_NEXT_ACTION nextActionRxCal=PROG_NONE;

SRAM_DATA
static A_UINT8 veryFirstRxGainCal=1;

SRAM_DATA
static TCMD_CONT_RX contRx;

SRAM_DATA
static A_UINT8 numBandMax;

SRAM_DATA
RXGAIN_CAL_DATA_I  rxGainCalResult[NUM_RF_BANDS][MAX_CAL_CHANS];


/*
 * Get RXGAIN configuration from the board data file
 */


SRAM_TEXT
static void getRXGAINCALCfgFromBoardData(void)
{
    ar900BGetRxGainCalCfg(&(rxGainCalCfg[0]), &(rxGainCalCfg[1]), &(rxGainCalResult[0]), &(rxGainCalResult[1]));
    return;
}


SRAM_TEXT
static void updateRxGainCalState(A_UINT8 freqInByte, A_UINT8 band)
{
    rxGainCalState.freqInByte = freqInByte;
    rxGainCalState.calBand = band;
    // update current chan info
}

SRAM_TEXT
static void progChainMask(A_UINT8 chainMask)
{
    // TBD??
    return;
}

SRAM_TEXT
static void configChan(A_UINT8 freq, A_UINT8 band)
{

    // update Rx Gain Cal State
    updateRxGainCalState(freq, band);

    return;
}



#define HT20 	0
#define VHT20 	2

SRAM_TEXT
static void ftmRxStart(FORCED_RX_PARM *rxParms)
{
    //TCMD_CONT_RX contRx;
    memset((void*)&contRx, 0, sizeof(TCMD_CONT_RX));
    contRx.u.para.freq = BYTE2FREQ((rxParms->chan), (RF_BAND_2_4_GHZ == rxParms->band));
    contRx.u.para.wlanMode=TCMD_WLAN_MODE_VHT20;
    contRx.u.para.bandwidth=HT20;
    contRx.u.para.antenna=0;
    contRx.act = TCMD_CONT_RX_PROMIS;
    contRx.u.para.bc=1;
    contRx.u.para.ack=1;
    contRx.u.para.rxChain = rxParms->chainMask;
    contRx.u.para.lpl = 0;

    A_PRINTF_ALWAYS("freq %d rxChain %d \n", contRx.u.para.freq, contRx.u.para.rxChain);
	utfContRxStart(&utf_dev, &contRx);
	//A_DELAY_USECS(1000);	  // assume DPD is disabled in FTM calibration
    return;
}



SRAM_TEXT
static void ftmRxStatReport(void)
{
	if(tcmdRxStat.okPkt > 0) {
	    A_PRINTF("ON: rssic 0-3 %d %d %d %d\n", tcmdRxStat.rssic[0]/(A_INT32)tcmdRxStat.okPkt, tcmdRxStat.rssic[1]/(A_INT32)tcmdRxStat.okPkt,
										  tcmdRxStat.rssic[2]/(A_INT32)tcmdRxStat.okPkt, tcmdRxStat.rssic[3]/(A_INT32)tcmdRxStat.okPkt);
    }
    return;
}

extern void utfRxStop(wlan_tcmd_dev_t *dev);


SRAM_TEXT
static void ftmRxStop(void)
{
	ftmRxStatReport();
	utfRxStop(&utf_dev);
    return;
}


 /* -------------------------------------------------
 * FUNCTION:  rxGainCal()
 *
 * NOTE:
 *      Start the Rx Gain cal on Host cmd with parameters
 *      {ChainIdx, RadioID}
 * --------------------------------------------------
 */

SRAM_TEXT
void rxGainCal(void *pParm)
{

    CMD_RXGAINCAL_PARMS *pParms = (CMD_RXGAINCAL_PARMS *)pParm;

	// Init. of rxGainCalState
    memset((void*)&rxGainCalState, 0, sizeof(RXGAIN_CAL_STATE));
    memset((void*)&rxGainCalCfg, 0, sizeof(rxGainCalCfg));

    getRXGAINCALCfgFromBoardData();

    // validation of the parameters from HOST - requirements from Jason and Gerald
	A_PRINTF_ALWAYS("HOST->rxGainCal: radioID %d, Chain %d\n", pParms->radioId, pParms->chainIdx);

    rxGainCalParms.chainIdx = pParms->chainIdx;
	rxGainCalParms.radioId = pParms->radioId;

    veryFirstRxGainCal = 1;

	rxGainCalState.status = rxGainCalParms.chainIdx > (MAX_NUM_CHAINS - 1);
	rxGainCalState.calLoop.idxChain = pParms->chainIdx;

	if (rxGainCalState.status !=0)
	{
		//send2HostNextRxCal(&utf_dev, nextLoopRxCal, CMD_RXGAINCALRSP_DONE, 1);
		A_PRINTF_ALWAYS("H Error on chainIdx %d\n", rxGainCalParms.chainIdx);
	}
	else
	{
		//A_PRINTF_ALWAYS("Before:  nextLoopRxCal b-c-c %d % %d\n", nextLoopRxCal->numBand, nextLoopRxCal->idxChan, nextLoopRxCal->idxChain);
        if (NULL != (nextLoopRxCal = getNextLoop(&nextActionRxCal))) {

			//A_PRINTF_ALWAYS("1st after getNextLoop:  b-c-c %d %d %d\n", nextLoopRxCal->numBand, nextLoopRxCal->idxChan, nextLoopRxCal->idxChain);
            nextCAL(nextActionRxCal, nextLoopRxCal);
            // send next CAL action
            send2HostNextRxCal(&utf_dev, nextLoopRxCal, CMD_RXGAINCALRSP, 0);
        }
	}

    return;
}


/* -------------------------------------------------
* FUNCTION:  siglDoneRsp()
*
* NOTE:
*	   Start the Rx Gain cal on Host cmd with parameters
*	   {RadioID, statu}
* --------------------------------------------------
*/
//SRAM_TEXT
//void siglDoneRsp(void *pParm)
CODESWAP_MARK_EVICTABLE(void, siglDoneRsp, void *pParm)
{
	CMD_RXGAINCAL_SIGL_DONE_PARMS *pParms = (CMD_RXGAINCAL_SIGL_DONE_PARMS *)pParm;
    A_INT32 minCCAThreshold,PNFdBm, PNFdBr, rssiDBr;
	A_UINT8 adc;

	//A_PRINTF_ALWAYS("HOST->siglDoneRsp: radioID %d, status %d \n", pParms->radioId, pParms->status);

	rxGainCalParms.radioId = pParms->radioId;
	rxGainCalState.status = pParms->status;

	if (1 == veryFirstRxGainCal)
	{
		A_PRINTF_ALWAYS(" Host ERROR! \n");
		send2HostNextRxCal(&utf_dev, nextLoopRxCal, CMD_RXGAINCALRSP_DONE, 1);
		return;
	}

	if (rxGainCalState.status !=0)
	{
		A_PRINTF_ALWAYS(" HostStatus ERROR! \n");
		send2HostNextRxCal(&utf_dev, nextLoopRxCal, CMD_RXGAINCALRSP_DONE, 1);
		return;
	}

    if ((NULL != nextLoopRxCal)&& (0!=(A_INT32)tcmdRxStat.okPkt)) {

		rssiDBr = tcmdRxStat.rssic[nextLoopRxCal->idxChain]/(A_INT32)tcmdRxStat.okPkt;
		PNFdBm =  RXGAINCAL_SIG_IN_DBM_N80 - (A_INT8)rssiDBr;
		PNFdBr =  g_NoiseFloorVal[nextLoopRxCal->idxChain];
		minCCAThreshold = RXGAINCAL_CCA_INJSIG_IN_DBM_N62 + PNFdBr - PNFdBm;
        //A_PRINTF_ALWAYS("Before_on:  nextLoopRxCal b-c-c %d %d %d\n", nextLoopRxCal->numBand, nextLoopRxCal->idxChan, nextLoopRxCal->idxChain);
		rxGainCalResult[nextLoopRxCal->numBand][nextLoopRxCal->idxChan].rxNFCalPowerDBm[nextLoopRxCal->idxChain] = (A_INT8)PNFdBm;
		rxGainCalResult[nextLoopRxCal->numBand][nextLoopRxCal->idxChan].rxNFCalPowerDBr[nextLoopRxCal->idxChain] = (A_INT8)PNFdBr;
		rxGainCalResult[nextLoopRxCal->numBand][nextLoopRxCal->idxChan].minCcaThreshold[nextLoopRxCal->idxChain] = (A_INT8)minCCAThreshold;

        adc = whalGetCurrentTemp();
        rxGainCalResult[nextLoopRxCal->numBand][nextLoopRxCal->idxChan].rxTempMeas[nextLoopRxCal->idxChain] = (adc >> (nextLoopRxCal->idxChain >> 3)) & 0xff;

	    A_PRINTF("ON: minCCAThreshold %d,PNFdBm %d, PNFdBr %d, rssiDBr %d temp %d\n", minCCAThreshold,PNFdBm, PNFdBr, rssiDBr, (adc >> (nextLoopRxCal->idxChain >> 3)) & 0xff);

    }
	// set to new channel and get P_nf_dbr

#if 1
    // if nextLoop is not NULL, there is r going on, clear the rx stat.
    //if (NULL != nextLoopRxCal) {
    //    A_PRINTF_ALWAYS("Before:  nextLoopRxCal b-c-c %d %d %d\n", nextLoopRxCal->numBand, nextLoopRxCal->idxChan, nextLoopRxCal->idxChain);
    //}

    if (NULL != (nextLoopRxCal = getNextLoop(&nextActionRxCal))) {

	    //A_PRINTF_ALWAYS("After:  nextLoopRxCal b-c-c %d %d %d\n", nextLoopRxCal->numBand, nextLoopRxCal->idxChan, nextLoopRxCal->idxChain);
        nextCAL(nextActionRxCal, nextLoopRxCal);
        // send next CAL action
        send2HostNextRxCal(&utf_dev, nextLoopRxCal, CMD_RXGAINCALRSP, 0);
     }
     else {
        // send done to host and update BDF
	    send2HostNextRxCal(&utf_dev, nextLoopRxCal, CMD_RXGAINCALRSP_DONE, 0);
		veryFirstRxGainCal = 1;
     }
#endif

    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void, siglDoneRsp, void *);

SRAM_TEXT
static CAL_LOOP *getNextLoop(CAL_LOOP_NEXT_ACTION *nextActionRxCal)
{

    CAL_LOOP *curLoop=&(rxGainCalState.calLoop);
    //static A_UINT8 veryFirstRxGainCal=1;

    if (1 == veryFirstRxGainCal) {
        veryFirstRxGainCal=0;
        curLoop->idxChan=0xff;                 // the very first starting chain index should start from -1

       if (0xff==rxGainCalCfg[0].bandMask)
       {
           curLoop->numBand = 0;
           numBandMax = 1;
       }

       if (0xff==rxGainCalCfg[1].bandMask)
       {
           curLoop->numBand = 1;
           numBandMax = 2;
       }

       if ((0xff==rxGainCalCfg[0].bandMask) && (0xff==rxGainCalCfg[1].bandMask))
       {
           curLoop->numBand = 0;
           numBandMax = 2;
       }
    }

    *nextActionRxCal= PROG_NONE;

    //A_PRINTF_ALWAYS("loop bef, band %d ch %d numCh %d chain %d \n", curLoop->numBand, curLoop->idxChan, rxGainCalCfg[curLoop->numBand].numChan, curLoop->idxChain);
    if (0 == rxGainCalCfg[curLoop->numBand].numChan) {
        if (++(curLoop->numBand) >= numBandMax) {  //NUM_RF_BANDS) {
            A_PRINTF_ALWAYS("end loop0\n");
            return(NULL);
        }
        else {
            *nextActionRxCal = PROG_BAND;
            if (0 == rxGainCalCfg[curLoop->numBand].numChan) {
                A_PRINTF_ALWAYS("end loop1\n");
                return(NULL);
            }
        }
    }

#if 0
    if (++(curLoop->idxChain) < rxGainCalCfg[curLoop->numBand].numChain) {
        *nextActionRxCal = PROG_CHAIN_MASK;
        A_PRINTF_ALWAYS("inc chain AI %d %d\n", *nextActionRxCal, curLoop->idxChain);
        return(curLoop);
    }
    else
#endif
	{
        if (++(curLoop->idxChan) < rxGainCalCfg[curLoop->numBand].numChan) {
             *nextActionRxCal = PROG_CHAN;
             //A_PRINTF_ALWAYS("inc ch AI %d %d\n", *nextActionRxCal, curLoop->idxChan);
             return(curLoop);
         }
         else {
             curLoop->idxChan=0;
#if 1
             curLoop->numBand++;
             if ((curLoop->numBand < numBandMax) && (0 != rxGainCalCfg[curLoop->numBand].numChan)) {
                    *nextActionRxCal = PROG_BAND;
					//A_PRINTF_ALWAYS("PROBLEM: inc band %d ch %d numCh %d chain %d \n", curLoop->numBand, curLoop->idxChan, rxGainCalCfg[curLoop->numBand].numChan, curLoop->idxChain);   // lim_
                    //A_PRINTF_ALWAYS("inc band AI %d %d\n", *nextActionRxCal, curLoop->numBand);
                    return(curLoop);
              }
              else
#endif
              {
					//veryFirstRxGainCal=1;  // for test code reentry
					//ftmRxStop();
					curLoop->numBand--;   // move back to original one
					//A_PRINTF_ALWAYS("end loop band %d ch %d numCh %d chain %d \n", curLoop->numBand, curLoop->idxChan, rxGainCalCfg[curLoop->numBand].numChan, curLoop->idxChain);   // lim_
                    //A_PRINTF_ALWAYS("end loop\n");
                    return(NULL);
              }
         }
     }
    return(NULL);
}


/* -------------------------------------------------
 * FUNCTION:  nextCAL()
 *
 * NOTE:
 *      1) Configured to Rx mode with desired {band, channel, ChainMask}
 *      2) get P_nf_dbr
 *      3) Rsp host with DUT ready, next action
 * --------------------------------------------------
 */
SRAM_TEXT
static void nextCAL(CAL_LOOP_NEXT_ACTION nextActionRxCal, CAL_LOOP *nextLoopRxCal)
{

    A_UINT8 band, idxChan, idxChain;

    band = rxGainCalState.rxParm.band = nextLoopRxCal->numBand;  // = RF_BAND_5_GHZ;   // TPC_2G == 0,
    idxChan = nextLoopRxCal->idxChan;
    rxGainCalState.rxParm.chan = rxGainCalCfg[nextLoopRxCal->numBand].chans[nextLoopRxCal->idxChan];

    idxChain = rxGainCalState.rxParm.chain = nextLoopRxCal->idxChain;
    rxGainCalState.rxParm.chainMask = rxGainCalCfg[nextLoopRxCal->numBand].chainMasks[nextLoopRxCal->idxChain];

    if (PROG_BAND == nextActionRxCal) {
        // For future band change handling (?).  Maybe this should be handled in channel switch
    }
    else if (PROG_CHAN == nextActionRxCal) {
        configChan(rxGainCalCfg[band].chans[idxChan], band);
    }
    //else if (PROG_CHAIN_MASK == nextActionRxCal) {
        progChainMask(rxGainCalCfg[band].chainMasks[idxChain]);
    //}

    //rxGainCalState.rxParm.chain
	rxGainCalState.rxParm.chainMask = (1<<rxGainCalState.rxParm.chain);

    //A_PRINTF_ALWAYS("Status b-f-c-cm: %d %d %d 0x%x\n", rxGainCalState.rxParm.band, rxGainCalState.rxParm.chan, rxGainCalState.rxParm.chain, rxGainCalState.rxParm.chainMask);
    ftmRxStart(&(rxGainCalState.rxParm));
	//A_PRINTF_ALWAYS("**** SIGOFF-done-nextCAL - band_ch_chain %d %d %d*\n",band, idxChan, idxChain);

    // update report
	rxGainCalParms.chanIdx = idxChan;
	rxGainCalParms.band = band;

    return;
}

// Init RX Gain Cal  module
SRAM_TEXT
void initRxGainCal(void)
{
    // register the RX Gain Cal module with the TLV handler
    registerRXGAINCALHandler(rxGainCal);
	registerRXGAINCAL_SIGL_DONEHandler(siglDoneRsp);

    return;
}

SRAM_TEXT
static void genRxGainCalData4BrdData(void)
{
    A_PRINTF_ALWAYS("genCALData\n");
    if (NULL != ChipFunc.genCalData) {
        (ChipFunc.genRxGainCalData)();
    }
    return;
}

SRAM_TEXT
void postRxGainCalHandling(void)
{

    /* post processing data */


    /* generate CAL data for the board data*/
    genRxGainCalData4BrdData();

    /* apply CAL data from the board data */

    /* write CAL data to OTP, if enabled */

    /* send the cal data to host */
    //sendRxGainCalData2Host(&utf_dev);

    return;
}

/* -------------------------------------------------
* FUNCTION:  send2HostNextRxCal()
*
* NOTE:
*	   send cal info to host for VSG setup and cal process
* --------------------------------------------------
*/
//SRAM_TEXT
//static void send2HostNextRxCal(wlan_tcmd_dev_t *dev, CAL_LOOP *nextLoopRxCal, A_UINT32 cmd, A_UINT8 errCode)
CODESWAP_MARK_EVICTABLE(void, send2HostNextRxCal, wlan_tcmd_dev_t *dev, CAL_LOOP *nextLoopRxCal, A_UINT32 cmd, A_UINT8 errCode)
{
    A_UINT32 tmpCmdCode;
	int tmpParaLen;

    /*
     * Send the CAL channels to host to measure the power
     * total measurements should be:
     *    (numChan2G + numChan5G) * numChains
     */
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
    //A_UINT8 numChain=0, chainMask[5];

    //chainMask[0] = rxGainCalState.rxParm.chainMask;

    switch (cmd)
	{

        case CMD_RXGAINCALRSP_DONE:
			 tmpCmdCode = CMD_RXGAINCALRSP_DONE;
			 tmpParaLen = 4;
			 rxGainCalParms.status = errCode;

			 pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
				   PARM_RADIOID, rxGainCalParms.radioId,
				   PARM_STATUS, rxGainCalParms.status);

			 // if there is no error, update the BDF contents
             if (0 ==rxGainCalParms.status)  postRxGainCalHandling();

             ftmRxStop();
		     break;

        case CMD_RXGAINCALRSP:
			 tmpCmdCode = CMD_RXGAINCALRSP;
			 tmpParaLen = 18;
			 rxGainCalParms.status = errCode;
			 rxGainCalParms.band = nextLoopRxCal->numBand;

			 if (RF_BAND_2_4_GHZ == nextLoopRxCal->numBand) {
				   rxGainCalParms.chanIdx = rxGainCalCfg[RF_BAND_2_4_GHZ].chans[nextLoopRxCal->idxChan];
				   //A_PRINTF_ALWAYS("**** 2G ***cmd_band_Ch_Chain: %d %d %d %d\n", tmpCmdCode, rxGainCalParms.band, rxGainCalParms.chanIdx, rxGainCalParms.chainIdx);
			 }
			 else if (RF_BAND_5_GHZ == nextLoopRxCal->numBand) {
				   rxGainCalParms.chanIdx = rxGainCalCfg[RF_BAND_5_GHZ].chans[nextLoopRxCal->idxChan];
				   //A_PRINTF_ALWAYS("**** 5G ***cmd_band_Ch_Chain: %d %d %d %d\n", tmpCmdCode, rxGainCalParms.band, rxGainCalParms.chanIdx, rxGainCalParms.chainIdx);
			 }

			 pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
			 PARM_RADIOID, rxGainCalParms.radioId,
			 PARM_STATUS, rxGainCalParms.status,
			 PARM_BAND, rxGainCalParms.band,
			 PARM_REFISS, rxGainCalParms.refISS,
			 PARM_RATE, rxGainCalParms.rate,
			 PARM_BANDWIDTH, rxGainCalParms.bandWidth,
			 PARM_CHANIDX, rxGainCalParms.chanIdx,
			 PARM_CHAINIDX,rxGainCalParms.chainIdx,
			 PARM_NUMPACKETS, rxGainCalParms.numPackets);

		     break;

		default:
			 A_PRINTF_ALWAYS(" UTF ERROR!\n");
			 return;
		  	 //break;
    }

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    A_PRINTF_ALWAYS("**** UTF2H CMD_RXGAINCALRSP ***cmd_band_Ch_Chain: %d %d %d %d\n", tmpCmdCode, rxGainCalParms.band, rxGainCalParms.chanIdx, rxGainCalParms.chainIdx);

    wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);

    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void, send2HostNextRxCal, wlan_tcmd_dev_t *, CAL_LOOP *, A_UINT32 , A_UINT8 );


