/*
 * Copyright (c) 2011, 2017 Qualcomm Technologies, Inc. All Rights Reserved.
 * 2011 Qualcomm Atheros, Inc.
 * Qualcomm Technologies Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#include <osapi.h>
#include "whal_api.h"
#include "whal_internal.h"
#include "ar6000_eeprom.h"
//#include "ar6320_eeprom.h"
#include "ar6000_phyReg.h"
#include "ar6000_internal.h"
#include "ar6000_phyReg.h"
#include "ar6000_desc.h"
//#include "hw/gpio_reg.h"
//#include "hw/wlan_coex_reg.h"
//#include "hw/radio_rome.h"
#include "efuse_api.h"
//#include "fwconfig_AR6320.h"
//#include "hw/chn_table_map.h"
//#include "hw/chn1_table_map.h"
#include "cmdRspParmsDict.h"
#include "cmdRspParmsInternal.h"
#include "cmdTPCCALHandler.h"
#include "cmdTPCCALPWRHandler.h"
#include "tpcCal.h"
#include "brdDataCmn.h"
#include "rxGainCal.h"
#include "radio_dtop_reg_csr.h"
#include "hw/sm_table_map.h"
#include "codeswap_api.h"

//whalGetCurTblIdx
#define MAX_HW_CAL_TABLE  2
#define RXGAINCAL_NUM_BAND  TPC_NUM_BAND

extern A_UINT8 cur_tbl_idx;

#define max(a,b) ((a) > (b) ?(a) : (b))
extern TPC_CAL_CFG                    tpcCfg[TPC_NUM_BAND];
extern TPC_CAL_RESULT                 tpcCalResult[TPC_NUM_BAND][MAX_CAL_CHANS];
extern TPC_CAL_POSTPROCESSED_RESULT   tpcCalPostProcResult[TPC_NUM_BAND][MAX_CAL_CHANS];
extern RXGAIN_CAL_DATA_I  rxGainCalResult[RXGAINCAL_NUM_BAND][MAX_CAL_CHANS];
extern RXGAIN_CAL_DATA_I gRxGainCal4Chan;

//#define A_PRINTF_ONCE A_CMN(printf._printf)
#define MASK2CHAIN(x) ((x != 8)  ? (x >> 1) : 3)

SRAM_DATA
int Max_TX_CAL_Gain_ID_5G, Max_TX_CAL_TGTPWR_ID_5G;
SRAM_DATA
int Max_TX_CAL_Gain_ID_2G, Max_TX_CAL_TGTPWR_ID_2G;


SRAM_DATA
GEN_CAL_DATA CalData;

#ifndef FPGA
#define CHAIN0_CHAN0_GLUT  BB_TPC_GLUT_SRAM_ADDRESS
#define CHAIN1_CHAN0_GLUT  (CHAIN0_CHAN0_GLUT + 0x88)
#define CHAIN2_CHAN0_GLUT  (CHAIN0_CHAN0_GLUT + 0x110)
#define CHAIN3_CHAN0_GLUT  (CHAIN0_CHAN0_GLUT + 0x198)
#define CHAIN0_CHAN1_GLUT  BB_TPC_GLUT_SRAM_ADDRESS + 0x34
#define CHAIN1_CHAN1_GLUT  (CHAIN0_CHAN1_GLUT + 0x88)
#define CHAIN2_CHAN1_GLUT  (CHAIN0_CHAN1_GLUT + 0x110)
#define CHAIN3_CHAN1_GLUT  (CHAIN0_CHAN1_GLUT + 0x198)

#define CHAIN0_CHAN0_PLUT   BB_TPC_PLUT_SRAM_ADDRESS
#define CHAIN1_CHAN0_PLUT  (CHAIN0_CHAN0_PLUT + 0x200)
#define CHAIN2_CHAN0_PLUT  (CHAIN0_CHAN0_PLUT + 0x400)
#define CHAIN3_CHAN0_PLUT  (CHAIN0_CHAN0_PLUT + 0x600)
#define CHAIN0_CHAN1_PLUT   BB_TPC_PLUT_SRAM_ADDRESS + 0x100
#define CHAIN1_CHAN1_PLUT  (CHAIN0_CHAN1_PLUT + 0x200)
#define CHAIN2_CHAN1_PLUT  (CHAIN0_CHAN1_PLUT + 0x400)
#define CHAIN3_CHAN1_PLUT  (CHAIN0_CHAN1_PLUT + 0x600)

#define CHAIN0_CHAN0_ALUT   BB_TPC_ALUT_SRAM_ADDRESS
#define CHAIN1_CHAN0_ALUT  (CHAIN0_CHAN0_ALUT + 0x80)
#define CHAIN2_CHAN0_ALUT  (CHAIN0_CHAN0_ALUT + 0x100)
#define CHAIN3_CHAN0_ALUT  (CHAIN0_CHAN0_ALUT + 0x180)
#define CHAIN0_CHAN1_ALUT   BB_TPC_ALUT_SRAM_ADDRESS + 0x40
#define CHAIN1_CHAN1_ALUT  (CHAIN0_CHAN1_ALUT + 0x80)
#define CHAIN2_CHAN1_ALUT  (CHAIN0_CHAN1_ALUT + 0x100)
#define CHAIN3_CHAN1_ALUT  (CHAIN0_CHAN1_ALUT + 0x180)

SRAM_RODATA
static A_UINT32 StartAddr_GLUT[MAX_HW_CAL_TABLE][4] = { {CHAIN0_CHAN0_GLUT, CHAIN1_CHAN0_GLUT, CHAIN2_CHAN0_GLUT, CHAIN3_CHAN0_GLUT},
                                                        {CHAIN0_CHAN1_GLUT, CHAIN1_CHAN1_GLUT, CHAIN2_CHAN1_GLUT, CHAIN3_CHAN1_GLUT} };
SRAM_RODATA
static A_UINT32 StartAddr_PLUT[MAX_HW_CAL_TABLE][4] = { {CHAIN0_CHAN0_PLUT, CHAIN1_CHAN0_PLUT, CHAIN2_CHAN0_PLUT, CHAIN3_CHAN0_PLUT},
                                                        {CHAIN0_CHAN1_PLUT, CHAIN1_CHAN1_PLUT, CHAIN2_CHAN1_PLUT, CHAIN3_CHAN1_PLUT} };
SRAM_RODATA
static A_UINT32 StartAddr_ALUT[MAX_HW_CAL_TABLE][4] = { {CHAIN0_CHAN0_ALUT, CHAIN1_CHAN0_ALUT, CHAIN2_CHAN0_ALUT, CHAIN3_CHAN0_ALUT},
                                                        {CHAIN0_CHAN1_ALUT, CHAIN1_CHAN1_ALUT, CHAIN2_CHAN1_ALUT, CHAIN3_CHAN1_ALUT} };
#endif

// function prototypes
void utfRecalBoardDataChecksum(void);
extern AR6000_EEPROM_STRUCT eepromStruct;

SRAM_TEXT
void ar900BGetCALChans(A_UINT8 *chans2G, A_UINT8 *chans5G)
{
    AR6000_EEPROM   *pBrdData;

    /* Populate the board data */
    pBrdData= (AR6000_EEPROM *) A_BOARD_DATA_ADDR();
#ifndef FPGA
    memcpy((void*)&(chans5G[0]), (void*)&(pBrdData->calFreqPier5G[0]), sizeof(pBrdData->calFreqPier5G));
    memcpy((void*)&(chans2G[0]), (void*)&(pBrdData->calFreqPier2G[0]), sizeof(pBrdData->calFreqPier2G));
#endif

    return;
}

SRAM_TEXT
void ar900BGetCALChainMasks(A_UINT8 *calMasks2G, A_UINT8 *numMasks2G, A_UINT8 *calMasks5G, A_UINT8 *numMasks5G)
{
    AR6000_EEPROM   *pBrdData;
#ifndef FPGA
    A_UINT8 chainMask, i,j;
    A_UINT8 calMask[MAX_NUM_CHAINS];
    A_UINT8 mask = 0x1;
#endif

    /* Populate the board data */
    pBrdData= (AR6000_EEPROM *) A_BOARD_DATA_ADDR();
#ifndef FPGA
    chainMask = pBrdData->baseEepHeader.txrxMask & 0xf;

    for(i = 0, j = 0; i < MAX_NUM_CHAINS; i++) {
    	if(mask & chainMask) {
    		calMask[j] = mask;
    		j++;
    	}
   		mask = mask << 1;
    }
    memcpy((void*)&(calMasks2G[0]), (void*)&(calMask[0]), j);
    *numMasks2G = j;
    memcpy((void*)&(calMasks5G[0]), (void*)&(calMask[0]), j);
    *numMasks5G = j;
#endif

    return;
}

/*
SRAM_TEXT
void ar900BGenCalData4BrdData(void)
*/
CODESWAP_MARK_EVICTABLE(void, ar900BGenCalData4BrdData)
{
#ifndef FPGA
    AR6000_EEPROM_STRUCT *pEepromStruct=&eepromStruct;
    BIMODAL_EEP_HEADER *pModal;
#if defined(_CAL_LM)	
    GEN_CAL_DATA *calData = &CalData;
#endif
    AR6000_EEPROM   *pBrdData;
    int band, i, j, k, nc, r=0;
    CAL_DATA_PER_FREQ_OLPC     *calPierData;
    CAL_DATA_PER_FREQ_CLPCF    *calPierData_CLPC;
    A_UINT16 *ptr_eeprom;
    A_UINT16 checksum = 0;
    A_UINT16 size;
    A_UINT8 minAntennaGain = 0, antenna_gain = 0;

    /*
     * Call chip specific function
     * Input: tpcPostProcessedResult, tpcCfg
     * Output: 2G CAL data, offset, length, and 5G CAL data, offset, length
     */

    /* Populate the board data */
    pBrdData= (AR6000_EEPROM *) A_BOARD_DATA_ADDR();
    for (band=TPC_5G/*TPC_2G*/;band<TPC_NUM_BAND;band++) {

        if (TPC_2G == band) {
            calPierData = &(pBrdData->calPierData2G[0]);
            calPierData_CLPC = &(pBrdData->calPierData2G_CLPC[0]);
            pModal = &(pEepromStruct->pEeprom->biModalHeader[1]);
        }
        else {
            calPierData = &(pBrdData->calPierData5G[0]);
            calPierData_CLPC = &(pBrdData->calPierData5G_CLPC[0]);
            pModal = &(pEepromStruct->pEeprom->biModalHeader[0]);
        }

        /* 
         * FR 38856 - Support different antenna Gain for per chain and per channel
         *
         * Get the antenna gain vales from BDF and add to the measured power for each chain and channel.
         * Measured power = measured power from calibration + (BDF antenna gain per chain - minimum of all chain)
         * This feature is controlled by BDF flag (enableAntennaGainPerChainChan)
         */

        for (i=0;i<tpcCfg[band].numChan;i++) {
            /* find the mimimum antenna gain among the chains */
            if(pModal->enableAntennaGainPerChainChan)
            {
                r=0;
                minAntennaGain = pModal->antennaGainPerChainChan[i][r];
                for(r=1; r < WHAL_NUM_CHAINS; r++)
                {
                    if (minAntennaGain > pModal->antennaGainPerChainChan[i][r])
                        minAntennaGain = pModal->antennaGainPerChainChan[i][r];
                }
            }

            for (nc=0;nc<tpcCfg[band].numChain;nc++) {
                j= MASK2CHAIN(tpcCfg[band].chainMasks[nc]);

                /* delta of antenna gain from BDF */
                if(pModal->enableAntennaGainPerChainChan)
                {
                    antenna_gain = pModal->antennaGainPerChainChan[i][j] - minAntennaGain;
                    antenna_gain = antenna_gain * 8;
                }

                for (k=0;k<NUM_CAL_GAINS_SELECTED_4_GLUT;k++) {
                    calPierData[i].calPerPoint_olpc[j][k].gUnit.pasetting = tpcCalPostProcResult[band][i].olpc.paCfg[j][k];
                    calPierData[i].calPerPoint_olpc[j][k].gUnit.txgainIdx = tpcCalPostProcResult[band][i].olpc.gainIdx[j][k];
                    /* Added antenna_gain to measured power as part of FR38856*/
                    calPierData[i].calPerPoint_olpc[j][k].meas_pwr = tpcCalPostProcResult[band][i].olpc.measPwr[j][k] + antenna_gain;

/*                    A_PRINTF_ALWAYS("%d %d %d\n",
                        calPierData[i].calPerPoint_olpc[j][k].gUnit.pasetting,
                        calPierData[i].calPerPoint_olpc[j][k].gUnit.txgainIdx,
                        calPierData[i].calPerPoint_olpc[j][k].meas_pwr);
*/                } // (for (k
                calPierData[i].dacGain[j]     = tpcCalPostProcResult[band][i].olpc.dacGain[j][0];
                calPierData[i].thermCalVal[j] = tpcCalResult[band][i].thermCal[j];

                for (k=0;k<NUM_CAL_GAINS_SELECTED_4_PLUT;k++) {
                    calPierData_CLPC[i].calPerPoint_clpcf[j][k].pdadc_read = tpcCalPostProcResult[band][i].clpc.pdadc[j][k];
                    /* Added antenna_gain to measured power as part of FR38856*/
                    calPierData_CLPC[i].calPerPoint_clpcf[j][k].meas_pwr = tpcCalPostProcResult[band][i].clpc.measPwr[j][k] + antenna_gain;
                }

            } // (for j
            calPierData[i].voltCalVal = tpcCalResult[band][i].voltCal[0]; // brd data not per chain
        } // (for i
    } // (for band

#if defined(_CAL_LM)
    /* Create the binary data stream, with offset and length */
    calData->offset2G_OLPC = ((A_UINT32)&(pBrdData->calPierData2G) - (A_UINT32)pBrdData);
    calData->length2G_OLPC = (A_UINT32) (sizeof(CAL_DATA_PER_FREQ_OLPC) * tpcCfg[TPC_2G].numChan);
//    A_PRINTF_ALWAYS("2G O off %d len %d siz %d numCh %d\n", calData->offset2G_OLPC, calData->length2G_OLPC,
//        sizeof(CAL_DATA_PER_FREQ_OLPC), tpcCfg[TPC_2G].numChan);
    if ( calData->length2G_OLPC ) {
        memcpy((void*)&(calData->calData2G_OLPC[0]), (void*)&(pBrdData->calPierData2G[0]), calData->length2G_OLPC);
    }

    calData->offset5G_OLPC = ((A_UINT32)&(pBrdData->calPierData5G) - (A_UINT32)pBrdData);
    calData->length5G_OLPC = (A_UINT32) (sizeof(CAL_DATA_PER_FREQ_OLPC) * tpcCfg[TPC_5G].numChan);
//    A_PRINTF_ALWAYS("5G O off %d len %d siz %d numCh %d\n", calData->offset5G_OLPC, calData->length5G_OLPC,
//        sizeof(CAL_DATA_PER_FREQ_OLPC), tpcCfg[TPC_5G].numChan);
    if (calData->length5G_OLPC) {
        memcpy((void*)&(calData->calData5G_OLPC[0]), (void*)&(pBrdData->calPierData5G[0]), calData->length5G_OLPC);
    }

    calData->offset2G_CLPC = ((A_UINT32)&(pBrdData->calPierData2G_CLPC) - (A_UINT32)pBrdData);
    calData->length2G_CLPC = (A_UINT32) (sizeof(CAL_DATA_PER_FREQ_CLPCF) * tpcCfg[TPC_2G].numChan);
//    A_PRINTF_ALWAYS("2G C off %d len %d siz %d numCh %d\n", calData->offset2G_CLPC, calData->length2G_CLPC,
//        sizeof(CAL_DATA_PER_FREQ_CLPCF), tpcCfg[TPC_2G].numChan);
    if (calData->length2G_CLPC) {
        memcpy((void*)&(calData->calData2G_CLPC[0]), (void*)&(pBrdData->calPierData2G_CLPC[0]), calData->length2G_CLPC);
    }

    calData->offset5G_CLPC = ((A_UINT32)&(pBrdData->calPierData5G_CLPC) - (A_UINT32)pBrdData);
    calData->length5G_CLPC = (A_UINT32) (sizeof(CAL_DATA_PER_FREQ_CLPCF) * tpcCfg[TPC_5G].numChan);
//    A_PRINTF_ALWAYS("5G C off %d len %d siz %d numCh %d\n", calData->offset5G_CLPC, calData->length5G_CLPC,
//        sizeof(CAL_DATA_PER_FREQ_CLPCF), tpcCfg[TPC_5G].numChan);
    if (calData->length5G_CLPC) {
        memcpy((void*)&(calData->calData5G_CLPC[0]), (void*)&(pBrdData->calPierData5G_CLPC[0]), calData->length5G_CLPC);
    }
#endif

    //recalculate the checksum?  FJC added - same functionality is done for write mac address, make common function?
    /* Clear current checksum and recalculate it */
    pBrdData->baseEepHeader.checksum = 0;
    ptr_eeprom = (A_UINT16 *)pBrdData;

    size = sizeof(QC90XX_EEPROM);
    for (i=0;i<size;i+=2) {
        checksum ^= *ptr_eeprom;
        ptr_eeprom++;
    }
    checksum = ~checksum;

    pBrdData->baseEepHeader.checksum = checksum;
#endif

    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void ,ar900BGenCalData4BrdData);
extern void ar900BGenCalData4BrdData();
/* -------------------------------------------------
* FUNCTION:  ar900BGetRxGainCalCfg()
*
* NOTE:
*	   get the Rx Gain cal cfg and defaults cal results from BDF
* --------------------------------------------------
*/
SRAM_TEXT
void ar900BGetRxGainCalCfg(void *pRxGainCalCfg2G, void *pRxGainCalCfg5G, void *pRxGainCalRlts2G, void *pRxGainCalRlts5G)
{
    AR6000_EEPROM   *pBrdData;

    /* Populate the board data */
    pBrdData= (AR6000_EEPROM *) A_BOARD_DATA_ADDR();

#ifndef FPGA
    // rx cal cfg data
    A_MEMCPY((void*)(pRxGainCalCfg5G), (void*)&(pBrdData->rxGainCalTbl[0].rxGainCalCfg), sizeof(pBrdData->rxGainCalTbl[0].rxGainCalCfg));
    A_MEMCPY((void*)(pRxGainCalCfg2G), (void*)&(pBrdData->rxGainCalTbl[1].rxGainCalCfg), sizeof(pBrdData->rxGainCalTbl[1].rxGainCalCfg));

	// cal results holder
    A_MEMCPY((void*)(pRxGainCalRlts5G), (void*)&(pBrdData->rxGainCalTbl[0].rxGainCalResult), sizeof(pBrdData->rxGainCalTbl[0].rxGainCalResult));
    A_MEMCPY((void*)(pRxGainCalRlts2G), (void*)&(pBrdData->rxGainCalTbl[1].rxGainCalResult), sizeof(pBrdData->rxGainCalTbl[1].rxGainCalResult));
#endif

    return;
}

/* -------------------------------------------------
* FUNCTION:  ar900BGetRxGainCalData4Chan()
*
* NOTE:
*	   get the Rx Gain cal data for the test channel from BDF
* --------------------------------------------------
*/
/*
SRAM_TEXT
void ar900BGetRxGainCalData4Chan(A_UINT32 freq)
*/
CODESWAP_MARK_EVICTABLE(void, ar900BGetRxGainCalData4Chan, A_UINT32 freq)
{
#ifndef FPGA
    AR6000_EEPROM   *pBrdData;
	A_UINT8 band = (freq > 4800)? 0:1;
	A_UINT8 chanIdx;
	RXGAIN_CAL_DATA  *pRxGainCalData;

    /* Populate the board data */
    pBrdData= (AR6000_EEPROM *) A_BOARD_DATA_ADDR();

	// Do nothing since there is no channel configured (in old BDF)
    if (0==pBrdData->rxGainCalTbl[band].rxGainCalCfg.chans[0]) return;

	// seletion of the cal data to use for the freq
    if (0 == band)
    {
       chanIdx = FREQ2BYTE_5G(freq);

       if (chanIdx <= pBrdData->rxGainCalTbl[band].rxGainCalCfg.chans[0])
       {
          chanIdx = 0;
       }
       else if (chanIdx <= pBrdData->rxGainCalTbl[band].rxGainCalCfg.chans[1])
       {
          chanIdx = 1;
       }
       else if (chanIdx <= pBrdData->rxGainCalTbl[band].rxGainCalCfg.chans[2])
       {
          chanIdx = 2;
       }
       else if (chanIdx <= (pBrdData->rxGainCalTbl[band].rxGainCalCfg.chans[3]+40))
       {
          chanIdx = 3;
       }

       // in case wrong data in BDF
       if (chanIdx >= MAX_RXG_CAL_CHANS)
       {
          A_PRINTF_ALWAYS("Wrong cal frequency in BDF!\n");
          return;
       }
    }
    else
    {
       chanIdx = FREQ2BYTE_2G(freq);

       if (chanIdx <= pBrdData->rxGainCalTbl[band].rxGainCalCfg.chans[0])
       {
          chanIdx = 0;
       }
       else if (chanIdx <= (pBrdData->rxGainCalTbl[band].rxGainCalCfg.chans[1]+40))
       {
          chanIdx = 1;
       }

       // in case wrong data in BDF
       if (chanIdx >= (MAX_RXG_CAL_CHANS-2))
       {
          A_PRINTF_ALWAYS("Wrong cal frequency in BDF!\n");
          return;
       }
    }

    pRxGainCalData = &(pBrdData->rxGainCalTbl[band].rxGainCalResult[chanIdx]);
    A_MEMCPY((void*)&gRxGainCal4Chan, (void*)pRxGainCalData, sizeof(RXGAIN_CAL_DATA));
#endif

    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void ,ar900BGetRxGainCalData4Chan, A_UINT32);
extern void ar900BGetRxGainCalData4Chan(A_UINT32 freq);

/* -------------------------------------------------
* FUNCTION:  ar900BGenRxGainCalData4BrdData()
*
* NOTE:
*	   update the Rx Gain cal data in BDF
* --------------------------------------------------
*/
SRAM_TEXT
void ar900BGenRxGainCalData4BrdData(void)
{
#ifndef FPGA
    AR6000_EEPROM   *pBrdData;
    int band;
    RXGAIN_CAL_DATA_I  *ptrData2G = (RXGAIN_CAL_DATA_I *)&(rxGainCalResult[0][0]);
    RXGAIN_CAL_DATA_I  *ptrData5G = (RXGAIN_CAL_DATA_I *)&(rxGainCalResult[1][0]);;
	RXGAIN_CAL_DATA  *pRxGainCalData;

    /* Populate the board data */
    pBrdData= (AR6000_EEPROM *) A_BOARD_DATA_ADDR();

    for (band=TPC_5G;band<RXGAINCAL_NUM_BAND;band++) {   // note: use TPC enum for 5G and 2G for consistency.  Should have a generic version

        if (TPC_2G == band) {
            pRxGainCalData = (RXGAIN_CAL_DATA *)&(pBrdData->rxGainCalTbl[1].rxGainCalResult[0]);
			A_MEMCPY((void*)pRxGainCalData, (void*)ptrData2G, sizeof(pBrdData->rxGainCalTbl[1].rxGainCalResult));
        }
        else {
            pRxGainCalData = (RXGAIN_CAL_DATA *)&(pBrdData->rxGainCalTbl[0].rxGainCalResult[0]);
			A_MEMCPY((void*)pRxGainCalData, (void*)ptrData5G, sizeof(pBrdData->rxGainCalTbl[0].rxGainCalResult));
        }

    } // (for band

    /* Clear current checksum and recalculate it */
	utfRecalBoardDataChecksum();

#endif
    return;
}

SRAM_TEXT
void ar900BGenXtalCapData4BrdData(A_UINT8 capIn, A_UINT8 capOut, A_UINT8 disXtalLocalFeature)
{
#ifndef FPGA
    //AR6000_EEPROM	*pBrdData = &eestruct;
    AR6000_EEPROM_STRUCT *pEepromStruct=&eepromStruct;
    BASE_EEP_HEADER *pBaseEepHeader;
    pBaseEepHeader = &pEepromStruct->pEeprom->baseEepHeader;

    /* update capin/capout in BDF*/
    pBaseEepHeader->param_for_tuning_caps = capOut;
    pBaseEepHeader->param_for_tuning_caps_1 = capIn;

    if (disXtalLocalFeature) pBaseEepHeader->opCapBrdFlags.featureEnable &= ~WHAL_FEATUREENABLE_TUNING_CAPS_MASK;
    //A_PRINTF_ALWAYS("HOST->xtalCalParms-BDF after: capIn %d, capOut %d \n", pBaseEepHeader->param_for_tuning_caps_1, pBaseEepHeader->param_for_tuning_caps);

	/* clear current checksum and recalculate it */
    utfRecalBoardDataChecksum();
#endif
}


SRAM_TEXT
void ar900BGetXtalCapDacFromBrdData(A_UINT8 *capIn, A_UINT8 *capOut)
{
#ifndef FPGA
    AR6000_EEPROM_STRUCT *pEepromStruct=&eepromStruct;
    BASE_EEP_HEADER *pBaseEepHeader;
    pBaseEepHeader = &pEepromStruct->pEeprom->baseEepHeader;

    /* get capin/capout from BDF*/
    *capOut = pBaseEepHeader->param_for_tuning_caps;
    *capIn = pBaseEepHeader->param_for_tuning_caps_1;
    A_PRINTF_ALWAYS("HOST->xtalCalParms-BDF: capInAddr %x %d %d\n", pBaseEepHeader, *capIn, *capOut);
#endif
}
#ifndef FPGA
SRAM_TEXT
static void clearGLUT(A_UINT32 startAddr)
{
#if 1
    int i, numCalPt = 8;

    for (i = 0; i < numCalPt; i++) {
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, startAddr);
        OS_REG_WRITE(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS, 0);
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, startAddr+4);
        OS_REG_WRITE(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS, 0);
        startAddr += 8;
    }
#endif
    return;
}
#endif

#ifndef FPGA
/*
SRAM_TEXT
static void programGLUT(CAL_DATA_PER_FREQ_OLPC *calPierData, A_UINT32 startAddr, A_UINT8 j)
*/
CODESWAP_MARK_EVICTABLE(void, programGLUT, CAL_DATA_PER_FREQ_OLPC *calPierData, A_UINT32 startAddr, A_UINT8 j)
{
#if 1
    int i, numCalPt = 5;
    A_UINT8 pwr, paCfg, gainIdx;
    A_INT8  dac, minDacGain, maxDacGain;
    A_UINT32 value;
    A_UINT16 clpcError;

#if 0
    // TBD? remove hard coding
    startAddr[TPC_2G][0] = 0x0db4;
    startAddr[TPC_2G][1] = 0x0e3c;
    startAddr[TPC_2G][2] = 0x0ec4;
    startAddr[TPC_2G][3] = 0x0f4c;
    startAddr[TPC_5G][0] = 0x0d80;
    startAddr[TPC_5G][1] = 0x0e08;
    startAddr[TPC_5G][2] = 0x0e90;
    startAddr[TPC_5G][3] = 0x0f18;
#endif

//    A_PRINTF_ALWAYS("PROGRAM GLUT: tgt pwr gnId pa dac minD maxD addr addr2\n");

    for (i = 0; i < numCalPt; i++) {
        paCfg     = calPierData[0].calPerPoint_olpc[j][i].gUnit.pasetting;
        gainIdx   = calPierData[0].calPerPoint_olpc[j][i].gUnit.txgainIdx;
        pwr       = calPierData[0].calPerPoint_olpc[j][i].meas_pwr;
        dac       = calPierData[0].dacGain[j];
        if (i < numCalPt-1) //KW fix
            minDacGain= dac - pwr + calPierData[0].calPerPoint_olpc[j][i+1].meas_pwr -8;
        maxDacGain= 80;
#if 0
        A_PRINTF_ALWAYS("%d %d %d %d %d ", tpcCfg[TPC_5G].tgtMeasPwr[j][i], pwr, gainIdx, paCfg, dac);
        A_PRINTF_ALWAYS("%d %d 0x%x 0x%x\n", minDacGain, maxDacGain, startAddr, startAddr+4);
#endif
        clpcError = 1024-96;
        value     = (((pwr &0xFF) << 10) | ((dac &0xFF) << 18)  | (clpcError & 0x3ff));
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, startAddr);
        OS_REG_WRITE(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS, value);
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, startAddr+4);
        value     = (((gainIdx &0xFF) << 3) | (paCfg & 0xFF) | ((minDacGain &0xff) << 8) | ((maxDacGain & 0xFF) << 16));
        OS_REG_WRITE(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS, value);
        startAddr += 8;
    }
#endif
    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void ,programGLUT, CAL_DATA_PER_FREQ_OLPC *, A_UINT32 , A_UINT8);
extern void programGLUT(CAL_DATA_PER_FREQ_OLPC *calPierData, A_UINT32 startAddr, A_UINT8 j);
#endif


#ifndef FPGA
SRAM_TEXT
static void program_PLUT(A_UINT32 startAddr, A_UINT8 chain, A_UINT8 band, A_UINT8 *plut)
{
    int i;
    A_UINT32 reg32;

//    A_PRINTF_ALWAYS("prog PLUT addr 0x%x\n", startAddr);



    //#$ctrl->{reg}->regWr("BB_tables_intf_addr_b0", ((1<<31) + $start_addr));
    for (i = 0; i < 256; i += 4) {
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, startAddr);
        reg32 = plut[i] | (plut[i+1] << 8) | (plut[i+2] << 16) | (plut[i+3] << 24);
//        A_PRINTF_ALWAYS("reg addr %x = %x\n", startAddr, reg32);
        OS_REG_WRITE(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS, reg32);
        startAddr += 4;
    }
}
#endif


#ifndef FPGA
   //# 10*log10 table, size 256 x 8 bits
#if 1
SRAM_RODATA
static A_UINT8 tbl_10log10[256] = {
     0 ,   0 ,   0 ,   0 ,   0 ,   0 ,   0 ,   7 ,  16 ,  25 ,  32 ,  39 ,  45 ,  50 ,  55 ,  60 ,  65 ,  69 ,  73 ,  77 ,  80 ,  84 ,
    87 ,  90 ,  93 ,  96 ,  98 , 101 , 104 , 106 , 108 , 111 , 113 , 115 , 117 , 119 , 121 , 123 , 125 , 127 , 128 , 130 , 132 , 133 ,
   135 , 137 , 138 , 140 , 141 , 142 , 144 , 145 , 147 , 148 , 149 , 150 , 152 , 153 , 154 , 155 , 157 , 158 , 159 , 160 , 161 , 162 ,
   163 , 164 , 165 , 166 , 167 , 168 , 169 , 170 , 171 , 172 , 173 , 174 , 175 , 176 , 176 , 177 , 178 , 179 , 180 , 181 , 182 , 182 ,
   183 , 184 , 185 , 185 , 186 , 187 , 188 , 188 , 189 , 190 , 191 , 191 , 192 , 193 , 193 , 194 , 195 , 195 , 196 , 197 , 197 , 198 ,
   199 , 199 , 200 , 200 , 201 , 202 , 202 , 203 , 204 , 204 , 205 , 205 , 206 , 206 , 207 , 208 , 208 , 209 , 209 , 210 , 210 , 211 ,
   211 , 212 , 212 , 213 , 213 , 214 , 214 , 215 , 215 , 216 , 216 , 217 , 217 , 218 , 218 , 219 , 219 , 220 , 220 , 221 , 221 , 222 ,
   222 , 222 , 223 , 223 , 224 , 224 , 225 , 225 , 226 , 226 , 226 , 227 , 227 , 228 , 228 , 228 , 229 , 229 , 230 , 230 , 230 , 231 ,
   231 , 232 , 232 , 232 , 233 , 233 , 234 , 234 , 234 , 235 , 235 , 235 , 236 , 236 , 237 , 237 , 237 , 238 , 238 , 238 , 239 , 239 ,
   239 , 240 , 240 , 241 , 241 , 241 , 242 , 242 , 242 , 243 , 243 , 243 , 244 , 244 , 244 , 245 , 245 , 245 , 246 , 246 , 246 , 246 ,
   247 , 247 , 247 , 248 , 248 , 248 , 249 , 249 , 249 , 250 , 250 , 250 , 250 , 251 , 251 , 251 , 252 , 252 , 252 , 253 , 253 , 253 ,
   253 , 254 , 254 , 254 , 255 , 255 , 255 , 255 , 255 , 255 , 255 , 255 , 255 , 255 };
#endif
#endif

#ifndef FPGA
/*
SRAM_TEXT
static void PLUT_generation(CAL_DATA_PER_FREQ_CLPCF *calPierData_CLPC, A_UINT8 *plut, A_UINT8 chain)
*/
CODESWAP_MARK_EVICTABLE(void, PLUT_generation, CAL_DATA_PER_FREQ_CLPCF *calPierData_CLPC, A_UINT8 *plut, A_UINT8 chain)
{
#if 1
    // # find Pout for each PDADC value.
    int i;
    int len = NUM_CAL_GAINS_SELECTED_4_PLUT;
    A_UINT8 k, PdadcMax, PdadcMin, pdadc, pdadc_hi, pdadc_lo, pout_hi, pout_lo, pout;

//    A_PRINTF_ALWAYS("PLUTGen\n");

    PdadcMax = 220;  //# define in board data
    PdadcMin = 5;   //# define in board data
    k = 0;
    for (i=255; i >=0; i--) {

        //# limit i within PdadcMin and PdadcMax
        if (i >= PdadcMax) {pdadc = PdadcMax;}
        else if (i <= PdadcMin) {pdadc = PdadcMin;}
        else {pdadc = i;}

        pdadc_hi = calPierData_CLPC[0].calPerPoint_clpcf[chain][k].pdadc_read;
        pout_hi  = calPierData_CLPC[0].calPerPoint_clpcf[chain][k].meas_pwr;
        pdadc_lo = calPierData_CLPC[0].calPerPoint_clpcf[chain][k +1].pdadc_read;
        pout_lo  = calPierData_CLPC[0].calPerPoint_clpcf[chain][k +1].meas_pwr;

        /*
        slope = (pout_hi - pout_lo) / (tbl_10log10[pdadc_hi] - tbl_10log10[pdadc_lo]);
        A_PRINTF_ALWAYS("s %d %d %d %d \n", pout_hi, pout_lo, pdadc_hi, pdadc_lo);
        A_PRINTF_ALWAYS("%d %d %d\n", slope, tbl_10log10[pdadc_hi], tbl_10log10[pdadc_lo]);
        */
        if (tbl_10log10[pdadc_hi] == tbl_10log10[pdadc_lo]) {
          pout = pout_hi;
        }
        else {
          if (pdadc >= pdadc_hi) {
            pout = pout_hi + (((pout_hi - pout_lo) * (tbl_10log10[pdadc]-tbl_10log10[pdadc_hi])) / (tbl_10log10[pdadc_hi] - tbl_10log10[pdadc_lo]));
            //A_PRINTF_ALWAYS("%d %d hi %d %d \n", i, pdadc, pout_hi, pout);
          }
          else {
            pout = pout_lo + (((pout_hi - pout_lo) * (tbl_10log10[pdadc]-tbl_10log10[pdadc_lo])) / (tbl_10log10[pdadc_hi] - tbl_10log10[pdadc_lo]));
            //A_PRINTF_ALWAYS("%d %d lo %d %d \n", i, pdadc, pout_lo, pout);
            if ((pdadc <= pdadc_lo) && (k < len-2)) { k = k + 1;}
          }
        }
        plut[i] = pout;
    }
#if 0
    for (i=0;i<256;i++) {
        A_PRINTF_ALWAYS("%d %d\n", i, plut[i]);
    }
#endif
    return;
#endif
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void ,PLUT_generation, CAL_DATA_PER_FREQ_CLPCF *, A_UINT8 *, A_UINT8 );
extern void PLUT_generation(CAL_DATA_PER_FREQ_CLPCF *calPierData_CLPC, A_UINT8 *plut, A_UINT8 chain);
#endif

//    # now we can enable CPLC now
#ifndef FPGA
/*
SRAM_TEXT
static void enableCLPC_Brd(void)
*/
CODESWAP_MARK_EVICTABLE(void, enableCLPC_Brd)
{
    A_UINT32 reg32;
    A_UINT8  dc_mode=0;

    //#$ctrl->{reg}->regWr("BB_heavy_clip_2.heavy_clip_enable", 0x3ff);
    //reg32 = OS_REG_READ(PHY_BB_POWERTX_MAX_SUB);
    reg32 = 0;
    OS_REG_WRITE(PHY_BB_POWERTX_MAX_SUB_ADDRESS, reg32);
    reg32 = (PHY_BB_POWERTX_MAX_SUB_POWERTX_SUB_FOR_2CHAIN_SET(0) |
             PHY_BB_POWERTX_MAX_SUB_USE_PER_PACKET_POWERTX_MAX_SET(1));
    OS_REG_WRITE(PHY_BB_POWERTX_MAX_SUB_ADDRESS, reg32);

    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS, PHY_BB_TPC_1_CLPC_ERR_UPDATE_DIS, 0);

    if (dc_mode == 0) {
        //# PDADC bias
        OS_REG_WRITE(PHY_BB_TPC_12_B0_ADDRESS, 0);
#if (NUM_SPATIAL_STREAM > 1)
        OS_REG_WRITE(PHY_BB_TPC_12_B1_ADDRESS, 0);
#if (NUM_SPATIAL_STREAM > 2)
        OS_REG_WRITE(PHY_BB_TPC_12_B2_ADDRESS, 0);
#if (NUM_SPATIAL_STREAM > 3)
        OS_REG_WRITE(PHY_BB_TPC_12_B3_ADDRESS, 0);
#endif
#endif
#endif
    }
    OS_REG_RMW_FIELD(PHY_BB_TPC_1_ADDRESS,  PHY_BB_TPC_1_PD_DC_SEL, dc_mode);
    OS_REG_RMW_FIELD(PHY_BB_TPC_2_ADDRESS,  PHY_BB_TPC_2_USE_FORCED_TARGET_POWER, 0);
    OS_REG_RMW_FIELD(PHY_BB_TPC_3_ADDRESS,  PHY_BB_TPC_3_TPC_CLK_GATE_ENABLE, 0);
    reg32 = OS_REG_READ(PHY_BB_TPC_7_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_7_ANA_SET_SEL_MASK | PHY_BB_TPC_7_ANA_SET_LST_MASK |
               PHY_BB_TPC_7_ANA_SET_FST_MASK | PHY_BB_TPC_7_TRY_NXT_SET_MASK |
               PHY_BB_TPC_7_GAIN_CALC_MODE_MASK | PHY_BB_TPC_7_OLPC_MODE_MASK |
               PHY_BB_TPC_7_TX_GAIN_TABLE_MAX_MASK | PHY_BB_TPC_7_CLPC_ATTN_EN_MASK);
    reg32 |=  (PHY_BB_TPC_7_ANA_SET_SEL_SET(1) | PHY_BB_TPC_7_ANA_SET_LST_SET(4) |
               PHY_BB_TPC_7_ANA_SET_FST_SET(0) | PHY_BB_TPC_7_TRY_NXT_SET_SET(1) |
               PHY_BB_TPC_7_GAIN_CALC_MODE_SET(2) | PHY_BB_TPC_7_OLPC_MODE_SET(0) |
               PHY_BB_TPC_7_TX_GAIN_TABLE_MAX_SET(31) | PHY_BB_TPC_7_CLPC_ATTN_EN_SET(0));
    OS_REG_WRITE(PHY_BB_TPC_7_ADDRESS, reg32);
    //OS_REG_RMW_FIELD(PHY_BB_TPC_17_ADDRESS, PHY_BB_tpc_17_MEAS_PWR_SW, 1); //# enable this for debugging purpose
    reg32 = OS_REG_READ(PHY_BB_TPC_17_ADDRESS);
    reg32 &= ~(PHY_BB_TPC_17_TPC_CL_ERR_CLIP_MASK | PHY_BB_TPC_17_TPC_CL_ERR_SCALE_MASK |
               PHY_BB_TPC_17_CL_ERR_IS_COMMON_MASK | PHY_BB_TPC_17_MEAS_PWR_SW_MASK);
    reg32 |=  (PHY_BB_TPC_17_TPC_CL_ERR_CLIP_SET(0x4) | PHY_BB_TPC_17_TPC_CL_ERR_SCALE_SET(0x10) |
               PHY_BB_TPC_17_CL_ERR_IS_COMMON_SET(0)  | PHY_BB_TPC_17_MEAS_PWR_SW_SET(1));
    OS_REG_WRITE(PHY_BB_TPC_17_ADDRESS, reg32);

    //#$ctrl->{reg}->regWr("WLAN_RESET_CONTROL.BB_WARM_RST", 1); # scale by 0.5
    //#$ctrl->{reg}->regWr("WLAN_RESET_CONTROL.BB_WARM_RST", 0); # scale by 0.5


    OS_REG_RMW_FIELD(PHY_BB_SYNTH_CONTROL_ADDRESS, PHY_BB_SYNTH_CONTROL_SEL_ALT_TABLES, cur_tbl_idx);
    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void , enableCLPC_Brd);
extern void enableCLPC_Brd();
#endif

#define MAX_NUM_ATTEN  15

#ifndef FPGA
/*
SRAM_TEXT
static void ALUT_generation(CAL_DATA_PER_FREQ_CLPCF *calPierData_CLPC, A_INT16 *pdet_atten_steps_8thdB, A_INT16 *pdet_atten_settings, A_UINT8 band, A_UINT8 chain)
*/
CODESWAP_MARK_EVICTABLE(void,  ALUT_generation, CAL_DATA_PER_FREQ_CLPCF *calPierData_CLPC, A_INT16 *pdet_atten_steps_8thdB, A_INT16 *pdet_atten_settings, A_UINT8 band, A_UINT8 chain)
{
    //# use max power when attenuator setting = 0 to compute attenuator setting needed
    // 1dB resolution, or idx
    A_INT16 targetIdxLo_1dB, targetIdxHi_1dB, ATTN_Cal_idx, tmp_1dB, k, i;
    // 1/8th dB resolution
    A_INT16 target_hi_8thdB, target_lo_8thdB;
    // 1/32th dB resolution
    A_INT16 pdet_atten_profile_32thdB[16], offset_32thdB, tmp_32thdB, pdet_atten_steps_32thdB[32];
    A_UINT8 *pdet_atten_profile_ref;
    A_UINT8 PDET_TIA_gain_8thdB, pdetRange_8thdb;
	AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();

    A_MEMZERO(pdet_atten_steps_32thdB, sizeof(pdet_atten_steps_32thdB));

    if (TPC_5G == band)
    {
    	ATTN_Cal_idx = pBrdData->preCalData5G.alutOffset;
    	pdetRange_8thdb = pBrdData->preCalData5G.pdetRange_8thdb;
    	pdet_atten_profile_ref = pBrdData->preCalData5G.pdetAttenProfile_32nddb;
    	PDET_TIA_gain_8thdB = pBrdData->preCalData5G.pdetTiaGainProfile_8thdb;
    }
    else
    {
    	ATTN_Cal_idx = pBrdData->preCalData2G.alutOffset;
    	pdetRange_8thdb = pBrdData->preCalData2G.pdetRange_8thdb;
    	pdet_atten_profile_ref = pBrdData->preCalData2G.pdetAttenProfile_32nddb;
    	PDET_TIA_gain_8thdB = pBrdData->preCalData2G.pdetTiaGainProfile_8thdb;
    }

    pdet_atten_profile_32thdB[0] = 0;
    for (i = 1; i < 16; i++) {
        pdet_atten_profile_32thdB[i] = pdet_atten_profile_32thdB[i-1] + pdet_atten_profile_ref[i-1];
    }

    offset_32thdB = pdet_atten_profile_32thdB[ATTN_Cal_idx];
    for (i = 0; i < 16; i++) {
        pdet_atten_profile_32thdB[i] = pdet_atten_profile_32thdB[i] - offset_32thdB;
    }

    target_hi_8thdB = (calPierData_CLPC[0].calPerPoint_clpcf[chain][0].meas_pwr) - pdetRange_8thdb;
    target_lo_8thdB = (calPierData_CLPC[0].calPerPoint_clpcf[chain][NUM_CAL_GAINS_SELECTED_4_PLUT -1].meas_pwr) + pdetRange_8thdb;

    if (target_hi_8thdB < target_lo_8thdB) {target_lo_8thdB = target_hi_8thdB;}
    target_lo_8thdB = max(target_lo_8thdB, (target_hi_8thdB -64));  //# to avoid target_lo is too low, hi-8dB

    /*
    ###########################################################################################
    # For entry target_lo_8thdB to target_hi_8thdB
    # TIA gain = low gain,
    # Attenuator index = ATTN_Cal_idx same as one used in calibration.
    ###########################################################################################
    */
    targetIdxLo_1dB = (target_lo_8thdB >> 3);
    targetIdxHi_1dB = (target_hi_8thdB >> 3);
//    A_PRINTF_ALWAYS("tgtIdxL %d H %d\n", targetIdxLo_1dB, targetIdxHi_1dB);
    for (i = targetIdxLo_1dB; (i <= targetIdxHi_1dB) && (i < 32); i++) {
        pdet_atten_settings[i] = ATTN_Cal_idx + 16;
        pdet_atten_steps_32thdB[i]    = 0;
    }

    /*
    ###########################################################################################
    # For entry target_hi_8thdB+1 to 31 (dBm)
    # TIA gain = low gain,
    # Attenuator index: Increased from ATTN_Cal_idx to 15.
    ###########################################################################################
    */
    for (i = targetIdxHi_1dB+1; (i >= 0)&&(i <= 31); i++) {
        tmp_1dB = i - targetIdxHi_1dB;
        tmp_32thdB = tmp_1dB <<5;
        k = ATTN_Cal_idx + tmp_1dB;
        if (k > 15) { k = 15;}

        if ((k > 0) && (tmp_32thdB < pdet_atten_profile_32thdB[k-1])) {
            k -= 1;
        } else if ((k >=0) && (k <= 14) && (tmp_32thdB > pdet_atten_profile_32thdB[k])) {
            k += 1;
        }

        //#$pdet_atten_settings[$i] = $k + 16;
        //#$pdet_atten_steps_32thdB[$i]    = $pdet_atten_profile_32thdB[$k];
        if (k >=0)
            tmp_32thdB = pdet_atten_profile_32thdB[k];
        //A_PRINTF_ALWAYS("ik tmp: %d %d %d\n", i, k, tmp_32thdB);
        //# Overflow protection
        if (i > 0){
            if ((k > 15) || (tmp_32thdB > (15 <<5))) {   //# (255-128)/8 = 15.875
                pdet_atten_settings[i] = pdet_atten_settings[i-1];
                pdet_atten_steps_32thdB[i]    = pdet_atten_steps_32thdB[i-1];
            } else {
                pdet_atten_settings[i] = k + 16;
                pdet_atten_steps_32thdB[i]    = tmp_32thdB;
            }
        }
    }

    /*
    ###########################################################################################
    # For entry target_lo_8thdB-1 to target_lo_8thdB-$ATTN_Cal_idx (dBm)
    # TIA gain = low gain,
    # Attenuator index: decreased from ATTN_Cal_idx-1 to 0.
    ###########################################################################################
    */
    k = ATTN_Cal_idx-1;
    for (i = targetIdxLo_1dB-1; i > targetIdxLo_1dB-1-ATTN_Cal_idx; i--) {
        //# $no protection because $i is unlikely be less than zero.
        pdet_atten_settings[i] = k + 16;
        pdet_atten_steps_32thdB[i]    = pdet_atten_profile_32thdB[k];
        k -= 1;
    }

    /*
    ###########################################################################################
    # For entry $target_lo_8thdB-1-$ATTN_Cal_idx to 0 (dBm)
    # TIA gain = high gain,
    # Attenuator index: decreased from X to 0
    ###########################################################################################
    */
    for (i = targetIdxLo_1dB -1 - ATTN_Cal_idx; i >= 0; i--) {
        tmp_1dB = i - targetIdxHi_1dB + (PDET_TIA_gain_8thdB >>3) ;
        tmp_32thdB = tmp_1dB <<5;
        k = ATTN_Cal_idx + tmp_1dB;

        if (k > 15) { k = 15;}
        if (k < 0 ) { k = 0; }

        if ((k > 0) && (tmp_32thdB < pdet_atten_profile_32thdB[k-1])) {
            k -= 1;
        } else if ((k <= 14) && (tmp_32thdB > pdet_atten_profile_32thdB[k])) {
            k += 1;
        }
        //A_PRINTF_ALWAYS("ik: %d %d\n", i, k);

        //# Overflow protection
        tmp_32thdB = (-20 << 5);
        while (tmp_32thdB < (-15 << 5)) {  //# -128/8 = -16
            tmp_32thdB = pdet_atten_profile_32thdB[k] - (PDET_TIA_gain_8thdB <<2);
            pdet_atten_settings[i] = k;
            pdet_atten_steps_32thdB[i]    = tmp_32thdB;
            k += 1;
        }

    }

    /*
    # 128 is introduced by hardware design to allow unsigned number only in ALUT table
    # need to ensure ALUT entry is 8 bit unsigned number
    */
    for (i=0; i < 32; i++) {
    	pdet_atten_steps_8thdB[i] = (pdet_atten_steps_32thdB[i] >>2) + 128;
    }

    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void , ALUT_generation,CAL_DATA_PER_FREQ_CLPCF *, A_INT16 *, A_INT16 *, A_UINT8 , A_UINT8 );
extern void ALUT_generation(CAL_DATA_PER_FREQ_CLPCF *calPierData_CLPC, A_INT16 *pdet_atten_steps_8thdB, A_INT16 *pdet_atten_settings, A_UINT8 band, A_UINT8 chain);
#endif

#ifndef FPGA
SRAM_TEXT
static void program_ALUT(A_UINT32 start_addr, A_INT16 *pdet_atten_steps, A_INT16 *pdet_atten_settings)
{
    A_UINT32 reg32;
    int i;

//    A_PRINTF_ALWAYS("prog ALUT 0x%x\n", start_addr);

    for (i = 0; i < 32; i +=2) {
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, start_addr);
//        A_PRINTF_ALWAYS("%d %d %d %d\n", pdet_atten_steps[i], pdet_atten_settings[i], pdet_atten_steps[i +1], pdet_atten_settings[i +1]);
        reg32 = pdet_atten_steps[i] | (pdet_atten_settings[i] << 8) | (pdet_atten_steps[i+1] << 13) | (pdet_atten_settings[i+1] << 21);
        //# step + setting << 8 + step << 13 + setting << 21
        OS_REG_WRITE(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS, reg32);
        start_addr += 4;
    }
}
#endif


// Testing function
/*
SRAM_TEXT
void ar900BApplyCalDataFromBrdData(void)
*/
CODESWAP_MARK_EVICTABLE(void, ar900BApplyCalDataFromBrdData)
{
#ifndef FPGA
    AR6000_EEPROM   *pBrdData;
    int band, i, j;
    CAL_DATA_PER_FREQ_OLPC   *calPierData;
    CAL_DATA_PER_FREQ_CLPCF  *calPierData_CLPC;
    A_UINT32 startAddr;
    A_UINT8  plut[256];
    A_INT16  pdet_atten_steps[32], pdet_atten_settings[32];

    /*
     * Call chip specific function
     * Input: tpcPostProcessedResult, tpcCfg
     * Output: 2G CAL data, offset, length, and 5G CAL data, offset, length
     */

    /* Populate the board data */
    pBrdData= (AR6000_EEPROM *) A_BOARD_DATA_ADDR();

    band=TPC_5G;

    calPierData = &(pBrdData->calPierData5G[0]);
    calPierData_CLPC = &(pBrdData->calPierData5G_CLPC[0]);

    i=0;
    for (j=0;j<tpcCfg[band].numChain;j++) {
        startAddr = StartAddr_GLUT[cur_tbl_idx][j];
        //A_PRINTF_ALWAYS("CALD 0x%x %d %d\n", startAddr, band,j);
        clearGLUT(startAddr);
        programGLUT(calPierData, startAddr, j);

        startAddr = StartAddr_PLUT[cur_tbl_idx][j];
        PLUT_generation(calPierData_CLPC, plut, j);
        program_PLUT(startAddr, j, band, plut);

        startAddr = StartAddr_ALUT[cur_tbl_idx][j];
        ALUT_generation(calPierData_CLPC, pdet_atten_steps, pdet_atten_settings, band, j);
        program_ALUT(startAddr, pdet_atten_steps, pdet_atten_settings);

#if 0
        A_PRINTF_ALWAYS("ALUT:\n");
        for (i=0;i<32;i++) {
            A_PRINTF_ALWAYS("%d %d %d\n", i, pdet_atten_settings[i], pdet_atten_steps[i]);
        }
#endif

    } // (for j

    enableCLPC_Brd();
#endif

    return;
}
CODESWAP_DEFINE_WRAPPER_VOIDRET(CODESWAP_ARENA_IRAM, void ,ar900BApplyCalDataFromBrdData);
extern void ar900BApplyCalDataFromBrdData();
#if 0
void read_GLUT_err(void)
{
    A_UINT32 start_addr, reg32, temp, err;
    int chain, i;
    int entries=5;
    A_UINT32 pwr, dac, pa, idx, min, max;
    A_UINT32 avg0, dc0, pwr0;

    for (chain=0;chain<4;chain++) {
        start_addr= StartAddr_GLUT[cur_tbl_idx][chain];

        for (i = 0 ; i < entries; i++) {
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, start_addr);
        reg32 = OS_REG_READ(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS);
        temp = PHY_BB_TABLES_INTF_DATA_B0_TABLES_DATA_0_GET(reg32);
        err= temp & 0x3FF;
        pwr= (temp>>10) & 0xFF;
        dac= (temp>>18) & 0xFF;
        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, start_addr+4);
        reg32 = OS_REG_READ(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS);
        temp = PHY_BB_TABLES_INTF_DATA_B0_TABLES_DATA_0_GET(reg32);
        pa= temp & 0x7;
        idx= (temp >> 3) % 0x1F;
        min= (temp >> 8) % 0xFF;
        max= (temp >> 16) & 0xFF;
        start_addr = start_addr + 8;
        A_PRINTF_ALWAYS("err %d pwr %d dac %d pa %d idx %d ",err,pwr,dac,pa,idx);
        A_PRINTF_ALWAYS("min %d max %d\n",min,max);
        }
    }

    reg32 = OS_REG_READ(PHY_BB_TPC_STAT_0_B0_ADDRESS);
    avg0 = PHY_BB_TPC_STAT_0_B0_PDACC_AVG_OUT_0_GET(reg32);
    dc0  = PHY_BB_TPC_STAT_0_B0_LATEST_DC_VALUE_0_GET(reg32);
    pwr0 = PHY_BB_TPC_STAT_0_B0_MEAS_PWR_OUT_0_GET(reg32);
    A_PRINTF_ALWAYS("avg0 %d dc0 %d pwr0 %d\n", avg0,dc0,pwr0);

    return;
}

void read_ALUT(void)
{
    int chain,i;
    A_UINT32 temp, start_addr;

    A_PRINTF_ALWAYS("ALUT:\n");
    for (chain=0;chain<4;chain++) {
        start_addr = StartAddr_ALUT[cur_tbl_idx][chain];

        OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, ((1<<31) | start_addr));
	for (i = 0; i < 32; i=i+2) {
	    temp = OS_REG_READ(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS);
	    A_PRINTF_ALWAYS("0x%x 0x%x %d %d %d\n", temp, (temp & 0xFF), ((temp << 8) & 0x1F), ((temp << 13) & 0xFF), ((temp << 21)&0x1F));
	}
    }
    return;
}


void read_PLUT(void)
{
    int i, chain;
    A_UINT32 temp, reg32, start_addr;

    A_PRINTF_ALWAYS("PLUT:\n");
    for (chain=0;chain<4;chain++) {
        start_addr = StartAddr_PLUT[cur_tbl_idx][chain];
        for (i = 0 ; i < 64; i++) {
            OS_REG_WRITE(PHY_BB_TABLES_INTF_ADDR_B0_ADDRESS, start_addr);
            reg32 = OS_REG_READ(PHY_BB_TABLES_INTF_DATA_B0_ADDRESS);
            temp = PHY_BB_TABLES_INTF_DATA_B0_TABLES_DATA_0_GET(reg32);
            A_PRINTF_ALWAYS("%d %d %d %d\n", (temp &0xFF), ((temp>>8)&0xFF), ((temp>>16)&0xFF), ((temp>>24)&0xFF));
            start_addr = start_addr + 4;
        }
    }
    return;
}

void qc900bTestFns(void)
{
    read_GLUT_err();
    read_PLUT();
    read_ALUT();
}
#endif

void utfRecalBoardDataChecksum()
{
#ifndef FPGA
    A_UINT32 i;
    A_UINT16 *ptr_eeprom;
    A_UINT16 checksum;
    A_UINT16 size;
    QC90XX_EEPROM *pEeprom = (QC90XX_EEPROM *)A_BOARD_DATA_ADDR();


    /* Clear current checksum and recalculate it */
    pEeprom->baseEepHeader.checksum = 0;
    ptr_eeprom = (A_UINT16 *)pEeprom;

    checksum = 0;
    size = sizeof(QC90XX_EEPROM);
    for (i=0;i<size;i+=2) {
        checksum ^= *ptr_eeprom;
        ptr_eeprom++;
    }
    checksum = ~checksum;

    pEeprom->baseEepHeader.checksum = checksum;
#endif //FPGA
    return;
}

A_UINT8 *utfGetBoardDataPtr()
{
#ifndef FPGA
    return ((A_UINT8 *)A_BOARD_DATA_ADDR());
#else
    return NULL;
#endif //FPGA
}

A_UINT16 utfGetBoardDataSize()
{
#ifndef FPGA
    return (sizeof(QC90XX_EEPROM));
#else
    return 0;
#endif //FPGA
}

void utfSetMacAddr(A_UINT8 *macAddr)
{
#ifndef FPGA
    QC90XX_EEPROM *pEeprom = (QC90XX_EEPROM *)A_BOARD_DATA_ADDR();

    A_MEMCPY((A_UINT8 *)(pEeprom->baseEepHeader.macAddr), macAddr, 6);
    pEeprom->baseEepHeader.nvMacFlag = 1;
#endif //FPGA
}

void utfGetMacAddr(A_UINT8 *macAddr)
{
#ifndef FPGA
    QC90XX_EEPROM *pEeprom = (QC90XX_EEPROM *)A_BOARD_DATA_ADDR();

    A_MEMCPY(macAddr, pEeprom->baseEepHeader.macAddr, 6);
#endif //FPGA
}

void utfSetMcnNum(A_UINT8 *mcnNum)
{
#ifndef FPGA
    QC90XX_EEPROM *pEeprom = (QC90XX_EEPROM *)A_BOARD_DATA_ADDR();

    A_MEMCPY((A_UINT8 *)(pEeprom->baseEepHeader.custData), mcnNum, 20);
#endif //FPGA
}

void utfGetMcnNum(A_UINT8 *mcnNum)
{
#ifndef FPGA
    QC90XX_EEPROM *pEeprom = (QC90XX_EEPROM *)A_BOARD_DATA_ADDR();

    A_MEMCPY(mcnNum, pEeprom->baseEepHeader.custData, 20);
#endif //FPGA
}

A_UINT8 txCalGainIdx5G_dflt[] = {3,5,7,9,11,13,15,17,19,21,23,25,27};        //regular power
SRAM_DATA
A_UINT8 txCalGainIdx2G_dflt[] = {5,7,9,11,13,15,17,19, 21,23,25,27,29};  //regular power
SRAM_TEXT
A_UINT8 *getPreTxCalGainIdxPtr(A_UINT8 is2GHz)
{
#ifndef FPGA
	AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();
    A_UINT8 *ptxCalGainIdxes;
    A_UINT8 i;

        if (is2GHz ? pBrdData->preCalData2G.valid : pBrdData->preCalData5G.valid)
        {
            ptxCalGainIdxes = is2GHz ? pBrdData->preCalData2G.gainIdxForCal : pBrdData->preCalData5G.gainIdxForCal;
            //calculate the number of indexes
            for (i = 0; i <= WHAL_NUM_POINTS_TO_MEAS; i++) {
                if (0xff == ptxCalGainIdxes[i]) {
                    if (is2GHz) {
                        Max_TX_CAL_Gain_ID_2G = i;
                    }
                    else {
                        Max_TX_CAL_Gain_ID_5G = i;
                    }
                    break;
                }
            }
	        return (ptxCalGainIdxes);
        }
        else {
            if (is2GHz)
                Max_TX_CAL_Gain_ID_2G = (sizeof(txCalGainIdx2G_dflt) / sizeof(A_UINT8));
            else
                Max_TX_CAL_Gain_ID_5G = (sizeof(txCalGainIdx5G_dflt) / sizeof(A_UINT8));

            return (is2GHz ? txCalGainIdx2G_dflt : txCalGainIdx5G_dflt);
        }

#else
	return (NULL);
#endif
}

SRAM_DATA
A_UINT8 txCalTgtPwr2G[] = {9, 12, 37, 56, 72, 96, 112, 128, 144, 160, 176, 192, 208};        //target  power for 2G: 1.125 ~26.0
SRAM_DATA
A_UINT8 txCalTgtPwr5G[] = {12, 37, 56, 72, 96, 112, 128, 144, 160, 176, 192, 208, 224};      //target power for 5G: 1.5~28.0
SRAM_TEXT
A_UINT8 *getPretxCalTgtPwrPtr(A_UINT8 is2GHz)
{
#ifndef FPGA

    A_UINT8 *ptxCalTgtPwr;
    AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();
    A_UINT8 i;

    if (pBrdData->baseEepHeader.opCapBrdFlags.flag2 & WHAL_FLAG2_TPC_CAL_TGT_PWR_GUIDE)
    {
        ptxCalTgtPwr = is2GHz ? pBrdData->preCalData2G.calDataTgtPwr : pBrdData->preCalData5G.calDataTgtPwr;
        //calculate the number of indexes
        for (i = 0; i <= WHAL_NUM_POINTS_TO_MEAS; i++) {
            if (0xff == ptxCalTgtPwr[i]) {
                if (is2GHz) {
                    Max_TX_CAL_TGTPWR_ID_2G = i;
                }
                else {
                    Max_TX_CAL_TGTPWR_ID_5G = i;
                }
                break;
            }
        }
	    return (ptxCalTgtPwr);
    }
    else {
        if (is2GHz)
            Max_TX_CAL_TGTPWR_ID_2G = (sizeof(txCalTgtPwr2G) / sizeof(A_UINT8));
        else
            Max_TX_CAL_TGTPWR_ID_5G = (sizeof(txCalTgtPwr5G) / sizeof(A_UINT8));

        return (is2GHz ? txCalTgtPwr2G : txCalTgtPwr5G);
    }
#endif

    return (NULL);
}


SRAM_DATA
A_INT8  txCalDacGain_dflt[] = {-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8};
SRAM_TEXT
A_INT8 *getPreTxCalDacGainPtr(A_UINT8 is2GHz)
{
#ifndef FPGA
	AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();


        if (is2GHz ? pBrdData->preCalData2G.valid : pBrdData->preCalData5G.valid)
	    return (is2GHz ? pBrdData->preCalData2G.dacGainForCal : pBrdData->preCalData5G.dacGainForCal);
        else
            return txCalDacGain_dflt;
#else
	return (txCalDacGain_dflt);
#endif
}

SRAM_DATA
A_UINT8 DA_Gain_Settings_dflt_5G[] =
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 7, 6, 7, 6, 7, 7, 7, 7};
A_UINT8 DA_Gain_Settings_dflt_2G[] =
{0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 3, 3, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7};
SRAM_TEXT
A_UINT8 *getPreTxCalPaConfig(A_UINT8 is2GHz)
{
#ifndef FPGA
	AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();

//A_PRINTF("##TJ is2g?:%d valid:%d bd:%d def:%d\n",is2GHz, pBrdData->preCalData2G.valid,pBrdData->preCalData2G.paConfigForCal[0],DA_Gain_Settings_dflt_2G[0]);
        if (is2GHz ? pBrdData->preCalData2G.valid : pBrdData->preCalData5G.valid)
	    return (is2GHz ? pBrdData->preCalData2G.paConfigForCal : pBrdData->preCalData5G.paConfigForCal);
        else
            return (is2GHz ? DA_Gain_Settings_dflt_2G : DA_Gain_Settings_dflt_5G);
#else
	return (NULL);
#endif
}

SRAM_DATA
A_UINT8 tgtMeasPwr_dflt_5G[] = {160, 132,104, 72, 40};      //regular power targets
SRAM_DATA
A_UINT8 tgtMeasPwr_dflt_2G[] = {160, 132,104, 72, 40};      //regular power targets
SRAM_TEXT
A_UINT8 *getPreTxCalPwrTarget(A_UINT8 is2GHz)
{
#ifndef FPGA
	AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();

        if (is2GHz ? pBrdData->preCalData2G.valid : pBrdData->preCalData5G.valid)
	    return (is2GHz ? pBrdData->preCalData2G.calPwrTargets : pBrdData->preCalData5G.calPwrTargets);
        else
            return (is2GHz ? tgtMeasPwr_dflt_2G : tgtMeasPwr_dflt_5G);
#else
	return (NULL);
#endif
}

SRAM_DATA
A_UINT8 tgtPdadc_dflt[] = {200, 125,80, 50, 30};
SRAM_TEXT
A_UINT8 *getPreTxCalPdadcTarget(A_UINT8 is2GHz)
{
#ifndef FPGA
	AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();

        if (is2GHz ? pBrdData->preCalData2G.valid : pBrdData->preCalData5G.valid)
	    return (is2GHz ? pBrdData->preCalData2G.calPdadcTargets : pBrdData->preCalData5G.calPdadcTargets);
        else
            return tgtPdadc_dflt;
#else
	return (NULL);
#endif
}

SRAM_DATA
A_UINT8 alutOffset_5G = 0;
SRAM_DATA
A_UINT8 alutOffset_2G = 4;
SRAM_TEXT
A_UINT8 getAlutOffset(A_UINT8 is2GHz)
{
#ifndef FPGA
	AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();

    if (is2GHz ? pBrdData->preCalData2G.valid : pBrdData->preCalData5G.valid)
		return (is2GHz ? pBrdData->preCalData2G.alutOffset : pBrdData->preCalData5G.alutOffset);
    else
        return (is2GHz ? alutOffset_2G : alutOffset_5G);
#else
	return (0);
#endif
}

SRAM_TEXT
A_UINT8 getTxPwrOffset(A_UINT8 is2GHz)
{
#ifndef FPGA
	AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();

    if ((is2GHz ? pBrdData->preCalData2G.valid : pBrdData->preCalData5G.valid) &&
        (pBrdData->baseEepHeader.opCapBrdFlags.boardFlags & WHAL_BOARD_ZERO_DBM))
		return (is2GHz ? pBrdData->preCalData2G.txPwrOffset : pBrdData->preCalData5G.txPwrOffset);
    else
        return (0);
#else
	return (0);
#endif
}

SRAM_TEXT
A_UINT8 getTpcFlag(A_UINT8 is2GHz)
{
#ifndef FPGA
    AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();
    A_UINT8 tpc_flag;
    tpc_flag = (is2GHz) ? (pBrdData->baseEepHeader.tpc_flag & WHAL_TPC_CONFIG_MASK):
                          ((pBrdData->baseEepHeader.tpc_flag >> WHAL_TPC_CONFIG_5G_LSB) & WHAL_TPC_CONFIG_MASK);
    return tpc_flag;
#else
    return (0);
#endif
}

SRAM_TEXT
A_UINT32 getboardFlags()
{
#ifndef FPGA
	AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();
	return pBrdData->baseEepHeader.opCapBrdFlags.boardFlags;
#else
	return (0);
#endif
}

SRAM_TEXT
A_UINT8 isDPDEnableInBDF(void)
{
 #ifndef FPGA
    AR6000_EEPROM *pBrdData = (AR6000_EEPROM *) A_BOARD_DATA_ADDR();
    return (pBrdData->baseEepHeader.dpdEnable);

 #else
    return (0);
 #endif
}

SRAM_TEXT
A_UINT8 getWhalNumChains(void)
{
 #ifndef FPGA
    return WHAL_NUM_CHAINS;
#else
    return (4);
#endif
}
