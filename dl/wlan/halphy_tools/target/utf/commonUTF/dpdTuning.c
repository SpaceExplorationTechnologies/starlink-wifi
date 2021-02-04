/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "osapi.h"
#include "wlantype.h"
#include "halphy_internal.h"
#include "hal_tcmd.h"
#include "wmi_tcmd.h"
#include "tcmdHostInternal.h"
#include "utf_dev.h"
#include "testcmd.h"
#include "utf.h"
#include "cmdRspParmsDict.h"
#include "cmdRspParmsInternal.h"
#include "tlv2Inc.h"
#include "tlv2Api.h"
#include "tcmd_api.h"
#include "cmdDPDLoopbackAttn.h"
#include "cmdDPDLoopbackTiming.h"
#include "dpdTuning.h"
#include <otpstream_api.h>
#include <otpstream_id.h> /* replaces local SECTION_ID definitions */
#include <efuse_api.h>
#include "halphy_mc_paprd.h"
#include "halphy_device_paprd.h"

extern wlan_tcmd_dev_t utf_dev;
extern HALPHY_PAPRD_STRUCT *pPaprdStruct;
extern WHAL_PAPRD_INDIRECTION_TABLE   *pWhalPaprdIndirectionTable;
extern TCMD_CONT_TX tx_tcmdParms;

extern int cmnos_printf(const char * format, ...);
#define A_PRINTF_ALWAYS_1                 cmnos_printf

#if 0
A_BOOL validate_dpdtune_atten( CMD_DPDLOOPBACKATTN_PARMS           *cmdParm )
{
    //cmdParm = (CMD_DPDLOOPBACKATTN_PARMS *)pParm;
    if ((cmdParm->glutIdx < 0) || (cmdParm->glutIdx > 4)) { 
         return (FALSE);
    }
    if ((cmdParm->DPDLoopbackAttn < 0) || (cmdParm->glutIdx > 8)) { 
         return (FALSE);
    }
    return (TRUE);
}
#endif

A_INT8 getChain(A_UINT8 chMask)
{
A_UINT8 chainMask[]={1,2,4,8};
A_UINT8 chainNum = 0;
    if ((chMask & (chMask-1)) == 0) {
      for (chainNum = 0; chainNum < WHAL_TX_NUM_CHAIN; chainNum++) {

        if (chMask & chainMask[chainNum]) {
           return (chainNum);
        }
      }
    }
  return (chainNum);
}

A_BOOL validate_dpdtuning_parms(A_UINT8 cmdCode, void *pParm)
{

   A_BOOL bRet = TRUE;
   CMD_DPDLOOPBACKTIMING_PARMS            *cmdParm; 
   CMD_DPDLOOPBACKATTN_PARMS              *cmdParm1;

   switch (cmdCode) 
   {

     case CMD_DPDLOOPBACKTIMING:

        cmdParm = (CMD_DPDLOOPBACKTIMING_PARMS *)pParm;

        if ((!cmdParm) || (cmdParm->DPDLoopbackAttn < 0) || (cmdParm->DPDLoopbackAttn > 7) ||
            (cmdParm->glutIdx > 4) || 
            (cmdParm->DPDTimingIdx < 10) || (cmdParm->DPDTimingIdx > 30))  
        { 
//         A_PRINTF_ALWAYS("validation failure : TimingIdx %d loopback %d glutIdx %d \n", cmdParm->DPDTimingIdx,cmdParm->DPDLoopbackAttn,cmdParm->glutIdx);
         bRet = FALSE;
        }

     break;

     case CMD_DPDLOOPBACKATTN:

        cmdParm1 = (CMD_DPDLOOPBACKATTN_PARMS *)pParm;

        if ((!cmdParm1) || (cmdParm1->DPDLoopbackAttn < 0) || (cmdParm1->DPDLoopbackAttn > 7) ||
            (cmdParm1->glutIdx > 4) ) 
        { 
 //        A_PRINTF_ALWAYS(" validation failure : loopback attenuation %d glutIdx %d \n", cmdParm1->DPDLoopbackAttn,cmdParm1->glutIdx);
         bRet = FALSE;
        }

     break;

     default:
         bRet = FALSE;
      break;

    }
//    if (bRet) dpdTuningCfg( 1 );
    return (bRet);
}


  SRAM_TEXT
void dpdTuningAtten(void *pParm)
{
    A_UINT32                            tmpCmdCode;
    int                                 tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8                             *rCmdStream = NULL;
    A_UINT32                            cmdStreamLen = 0;
    A_UINT8                             dpdStatus = DPD_SUCCESS; 
#ifndef FPGA
    CMD_DPDLOOPBACKATTN_PARMS           *cmdParm;
    A_UINT16 				rxmask = 0;
    A_UINT16 				txmask = 0;
    A_UINT8                             chains = 0;


    whalGetChainMasks(&txmask, &rxmask);
    chains = getChain(txmask);


       pPaprdStruct->dpdTuning.tuningFlags = 0;
       pPaprdStruct->dpdTuningEnable       = TRUE;

       cmdParm = (CMD_DPDLOOPBACKATTN_PARMS *)pParm;

       //A_PRINTF_ALWAYS_1("%s: loopbackAtten %d glutIdx %d flags %d\n", __func__,cmdParm->DPDLoopbackAttn,cmdParm->glutIdx,pPaprdStruct->dpdTuning.tuningFlags);

       if (validate_dpdtuning_parms(CMD_DPDLOOPBACKATTN,(void *)cmdParm)) { 

          pPaprdStruct->dpdTuning.loopback_attenuation = cmdParm->DPDLoopbackAttn;
          pPaprdStruct->dpdTuning.glutIdx              = cmdParm->glutIdx;
          pPaprdStruct->dpdTuning.chain_index          = chains;
          pPaprdStruct->dpdTuning.tuningFlags          = DPD_TUNING_AGC2PWR;

       //A_PRINTF_ALWAYS_1("validate : loopbackAtten %d glutIdx %d flags %d\n", cmdParm->DPDLoopbackAttn,cmdParm->glutIdx,pPaprdStruct->dpdTuning.tuningFlags);

       }
       else{
           dpdStatus = DPD_FAILURE;
       }
#endif

       /* Add delay before sending response for Test Node to settle */
       A_DELAY_USECS(200);

        tmpCmdCode = CMD_DPDLOOPBACKATTNRSP;
        tmpParaLen = 2;
        pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
                      PARM_STATUS, dpdStatus
                         );

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);

}

  SRAM_TEXT
void dpdTuningTimingIdx(void *pParm)
{
    A_UINT32                            tmpCmdCode;
    int                                 tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8                             *rCmdStream = NULL;
    A_UINT32                            cmdStreamLen = 0;
    A_UINT8                             dpdStatus = 0; 
#ifndef FPGA
    CMD_DPDLOOPBACKTIMING_PARMS         *cmdParm;
    A_UINT16 				rxmask = 0;
    A_UINT16 				txmask = 0;
    A_UINT8                             chains = 0;

    whalGetChainMasks(&txmask, &rxmask);
    chains = getChain(txmask);

        pPaprdStruct->dpdTuningEnable       = TRUE;
        pPaprdStruct->dpdTuning.tuningFlags = 0;

        cmdParm = (CMD_DPDLOOPBACKTIMING_PARMS *)pParm;
        // A_PRINTF_ALWAYS_1(" 1- chain (%d) TimingIdx : TimingIdx %d loopback %d\n", chains,cmdParm->DPDTimingIdx,cmdParm->DPDLoopbackAttn);
        //  A_PRINTF_ALWAYS(" glutIdx %d\n",cmdParm->glutIdx);

        if (validate_dpdtuning_parms(CMD_DPDLOOPBACKTIMING,(void *)pParm)) { 

           pPaprdStruct->dpdTuning.loopback_timing_idx  = cmdParm->DPDTimingIdx;
           pPaprdStruct->dpdTuning.loopback_attenuation = cmdParm->DPDLoopbackAttn;
           pPaprdStruct->dpdTuning.glutIdx              = cmdParm->glutIdx;
           pPaprdStruct->dpdTuning.chain_index          = chains;
           pPaprdStruct->dpdTuning.tuningFlags          = DPD_TUNING_TIMINGIDX;

        // A_PRINTF_ALWAYS("validate : TimingIdx %d loopback %d glutIdx %d\n", cmdParm->DPDTimingIdx,cmdParm->DPDLoopbackAttn,cmdParm->glutIdx);
        // A_PRINTF_ALWAYS("flags %d\n",pPaprdStruct->dpdTuning.tuningFlags);

        }
        else{
            dpdStatus = DPD_FAILURE;
        }
#endif
        /* Add delay before sending response for Test Node to settle */
        A_DELAY_USECS(200);

        tmpCmdCode = CMD_DPDLOOPBACKTIMINGRSP;
        tmpParaLen = 2;
        pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
                      PARM_STATUS, dpdStatus
                         );


    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;

    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);


}

  SRAM_TEXT
void dpdTuningTrainingQuality(void *pParm)
{
    A_UINT32                            tmpCmdCode;
    int                                 tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8                             *rCmdStream = NULL;
    A_UINT32                            cmdStreamLen = 0;
    A_UINT8                             dpdStatus = 0; 

    tmpCmdCode = CMD_DPDTRAININGQUALITYRSP;
    tmpParaLen = 4;
    pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
                      PARM_DPDTRAINQUAL, pPaprdStruct->dpdTuning.TrainingQ, PARM_STATUS, dpdStatus
                         );
   // A_PRINTF_ALWAYS("Training Q %d\n", pPaprdStruct->dpdTuning.TrainingQ);

    /* Add delay before sending response for Test Node to settle */
    A_DELAY_USECS(200);

    if ( pCmdStream == NULL )
        return;

    cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
    rCmdStream = (A_UINT8 *)pCmdStream;
   
    wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream); 

}

  SRAM_TEXT
void dpdTuningAgc2Pwr(void *pParm)
{
    A_UINT32                            tmpCmdCode;
    int                                 tmpParaLen;
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;
    A_UINT8                             *rCmdStream = NULL;
    A_UINT32                            cmdStreamLen = 0;
    A_UINT8                             dpdStatus = 0; 
#ifndef FPGA
    A_UINT16 				rxmask = 0;
    A_UINT16 				txmask = 0;
    A_UINT8                             chains = 0;


    whalGetChainMasks(&txmask, &rxmask);
    chains = getChain(txmask);

        pPaprdStruct->dpdTuningEnable       = TRUE;

#endif
        /* Add delay before sending response for Test Node to settle */
        A_DELAY_USECS(200);

        tmpCmdCode = CMD_DPDAGC2PWRRSP;
        tmpParaLen = 4;
        pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp((A_UINT32)tmpCmdCode, tmpParaLen,
                      PARM_DPDAGC2PWR, pPaprdStruct->dpdTuning.agc2pwr, PARM_STATUS, dpdStatus
                         );
//    A_PRINTF_ALWAYS("agc2pwr %d\n", pPaprdStruct->dpdTuning.agc2pwr);

        if ( pCmdStream == NULL )
            return;

        cmdStreamLen = (sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + pCmdStream->cmdStreamHeader.length);
        rCmdStream = (A_UINT8 *)pCmdStream;

        wmi_tc_cmds_reply_event(utf_dev.wmi,cmdStreamLen,tmpCmdCode,(A_INT8*)rCmdStream);

}

SRAM_TEXT
void  iniDpdTuningAtten(void)
{
	registerDPDLOOPBACKATTNHandler(dpdTuningAtten);
    return;
}

SRAM_TEXT
void iniDpdTuningTimingIdx(void)
{
	registerDPDLOOPBACKTIMINGHandler(dpdTuningTimingIdx);
    return;
}
SRAM_TEXT
void iniDpdTuningTrainingQuality(void)
{
	registerDPDTRAININGQUALITYHandler(dpdTuningTrainingQuality);
    return;
}
SRAM_TEXT
void iniDpdTuningAgc2Pwr(void)
{
	registerDPDAGC2PWRHandler(dpdTuningAgc2Pwr);
    return;
}
SRAM_TEXT
void  iniDpdTuning(void)
{
  iniDpdTuningTimingIdx();
  iniDpdTuningAtten();
  iniDpdTuningTrainingQuality();
  iniDpdTuningAgc2Pwr();
}

