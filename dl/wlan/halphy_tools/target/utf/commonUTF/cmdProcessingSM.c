#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_HOST_SIM_TESTING)
#include "otaHostCommon.h"
#else
#include "osapi.h"
#endif
#include "wlantype.h"
#include "tcmdHostInternal.h"
//#include "cmdOpcodes.h"
#include "cmdStream.h"
#include "parmBinTemplate.h"
#include "parseBinCmdStream.h"
#include "cmdAllParms.h"
#include "cmdProcessingSM.h"
#include "testcmd.h"
#include "utf_dev.h"
#include "tcmd_api.h"
#include "utfCallback.h"

extern _CMD_HANDLERS CmdHandlers[]; 

_OP_2_STATE_EVT Op2StateEvt[_OP_TESTSCRIPT_LAST] = {
// _OP_SYNC
{RX_SYNC_STATE, EVT_RX_SYNC_CMD},
// _OP_TX
{TX_STATE, EVT_TX_CMD},
// _OP_RX
{RX_STATE, EVT_RX_CMD},
// _OP_CAL_
{CAL_OR_CHAR_STATE, EVT_CAL_CMD},
// _OP_CAL_DONE
{WAIT_4_CAL_DATA_STATE, EVT_CAL_DONE_CMD},
// _OP_PM
{PM_STATE, EVT_PM_CMD},
// _OP_GENERIC_RSP
{NULL_STATE, EVT_NULL},
// _OP_SUBMIT_REPORT_RSP
{NULL_STATE, EVT_NULL},
// _OP_GENERIC_NART_CMD
{NARTCMD_STATE, EVT_NART_CMD},
// _OP_GENERIC_NART_RSP
{NULL_STATE, EVT_NULL},
};// Op2StateEvt[_OP_TESTSCRIPT_LAST]


//
// Notes:
// 1. The "absolute beginning" position of the cmdQ is always at 0. This is when the test flow repeats
// or back to beginning after failure.
//
#if 0
// generic cmd event handler
static _CMDPROC_RC evtCmdHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    A_BOOL rc;
    _CMD_QUEUE *curCmdQ = pCmdStateInfo->pCmdStreamInfo->curCmdQueue;
    _CMDPROC_RC rcCmdProc=CMDPROC_RC_NULL;
    _CMD_OPCODES opCode = pCmdStateInfo->curCmd;
    A_UINT16 i=pCmdStateInfo->pCmdStreamInfo->curQBegin;
    //_P_CMD_PARMS parms;
    _CMD_ALL_PARMS *parms;

    // parsing cmd parms
    rc = (CmdHandlers[opCode]._CmdParmsParser)(curCmdQ[i].cmdParmBuf, &parms, curCmdQ[i].numOfParms);
    if (!rc) {
        A_PRINTF("Err parms, cmd %d\n", opCode);
        // cmd execution failure, due to stupid error
        return(CMDPROC_RC_SYNC_FAIL);
    }
    //
    rcCmdProc = (CmdHandlers[opCode]._CmdProcessor)(parms);
    return(rcCmdProc); 
} 
#endif
 
#if 0 
static _CMDPROC_RC evtCalCmdHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    A_PRINTF("%s\n", __func__);
    _CMDPROC_RC rcCmdProc = evtCmdHandler(pCmdStateInfo);
    if (CMDPROC_RC_SYNC_SUCC == rcCmdProc) {
        pCmdStateInfo->state = CAL_OR_CHAR_STATE; 
    }
    return(rcCmdProc);
}
#endif

static _CMDPROC_RC evtTxCmdHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    //A_PRINTF("%s\n", __func__);
    _CMDPROC_RC rcCmdProc = evtCmdHandler(pCmdStateInfo);
    if (CMDPROC_RC_SYNC_SUCC == rcCmdProc) {
        pCmdStateInfo->state = TX_STATE; // ?? TX_NORMAL state not needed?? 
        pCmdStateInfo->state = CMD_PROCESSING_STATE; // ?? TX_NORMAL state not needed?? 
    }
    return(rcCmdProc);
}

// RX_SYNC_STATE
static _CMDPROC_RC evtRxSyncCmdHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    _CMDPROC_RC rcCmdProc;
    //A_PRINTF("%s\n", __func__);
    rcCmdProc = evtCmdHandler(pCmdStateInfo);
    if (CMDPROC_RC_ASYNC == rcCmdProc) {
        pCmdStateInfo->state = RX_SYNC_STATE; 
    }
    return(rcCmdProc);
}

// RX_STATE
static _CMDPROC_RC evtRxCmdHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    //A_PRINTF("%s\n", __func__);
    _CMDPROC_RC rcCmdProc = evtCmdHandler(pCmdStateInfo);
    if (CMDPROC_RC_ASYNC == rcCmdProc) {
        pCmdStateInfo->state = RX_STATE; 
    }
    return(rcCmdProc);
}


#if 0
// CMD_CAL
static _CMDPROC_RC evtCalDataAvailHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    return(evtCmdHandler(pCmdStateInfo));
}
#endif

// CMD_CAL_DATA_COMPUTE
// If CAL data available, process it and move back to CMD_PROCESSING_STATE,
// else 
//    re-start the timer and stay in this state, until some time (count)
static _CMDPROC_RC evtPollCalDataHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    //A_UNTIMEOUT(&pCmdStateInfo->calDataPollTimer); // stopped in the timeout handling routine
#if 0
    _TESTFLOW_CMD_STREAM *cmdStream;
    A_PRINTF("ts loaded %d addr 0x%x ", HOST_INTEREST->hi_ota_testscript_loaded, HOST_INTEREST->hi_ota_testscript);
    if (HOST_INTEREST->hi_ota_testscript_loaded) {
        *pCmdStream = (A_UINT8 *)HOST_INTEREST->hi_ota_testscript;

        // get the length 
        cmdStream = (_TESTFLOW_CMD_STREAM *)HOST_INTEREST->hi_ota_testscript;
        *cmdStreamLen = sizeof(_TESTFLOW_CMD_STREAM_HEADER) + cmdStream->cmdStreamHeader.length;
        A_PRINTF(" pCmdStream 0x%x len %d\n", *pCmdStream, *cmdStreamLen);
    }
#endif
    // fetch the CAL data
    A_PRINTF("cal data loaded 0x%x addr 0x%x ", HOST_INTEREST->hi_test_apps_related, HOST_INTEREST->hi_cal_data);
    if ((HOST_INTEREST->hi_test_apps_related) & HI_TEST_APPS_CAL_DATA_AVAIL) {
        //use the RAM location data to program OTP or update board data in RAM for subsequent verification (?how) 
        
        // move state back to CMD_PROCESSING_STATE
        pCmdStateInfo->state = CMD_PROCESSING_STATE; 

        return(CMDPROC_RC_ASYNC_SUCC);
    }
    else {
        // re-start the timer,
        A_TIMEOUT_MS(&(pCmdStateInfo->calDataPollTimer), CAL_DATA_POLL_PERIOD_MS, FALSE);

        // stay in the same state.
        return(CMDPROC_RC_NULL);
    }
}


static _CMDPROC_RC evtRxTimeoutHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    // timeout to do
    // 1. stop the timer
    // 2. deregister callback
    A_UNTIMEOUT(&pCmdStateInfo->rxTimer);
    deregisterCallback(rxNotify);

    // move state back to CMD_PROCESSING_STATE
    pCmdStateInfo->state = CMD_PROCESSING_STATE; 

    // simply return timeout
    return(CMDPROC_RC_ASYNC_TIMEOUT);
}


static _CMDPROC_RC evtRxSyncTimeoutHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    // timeout to do
    // 1. stop the timer
    // 2. deregister callback
    A_UNTIMEOUT(&pCmdStateInfo->rxSyncTimer);
    deregisterCallback(rxNotify);

    // move state back to CMD_PROCESSING_STATE
    pCmdStateInfo->state = CMD_PROCESSING_STATE; 

    // simply return timeout
    return(CMDPROC_RC_ASYNC_TIMEOUT);
}

static _CMDPROC_RC evtRxAvailHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    _CMDPROC_RC rcCmdProc;
    
    // TBD??
    // Determine rx data good or bad by rxStats??
#if defined(_HOST_SIM_TESTING)
#define _RX_DATA_GOOD 1
#else
#define _RX_DATA_GOOD 1
#endif
    if (_RX_DATA_GOOD) 
        rcCmdProc = CMDPROC_RC_ASYNC_SUCC;
    else
        rcCmdProc = CMDPROC_RC_ASYNC_FAIL;

    // stop the timer
    //A_PRINTF("stop rx timer ..\n");
    A_UNTIMEOUT(&pCmdStateInfo->rxTimer);

    // deregister the callback
    deregisterCallback(rxNotify);
    
    pCmdStateInfo->state = CMD_PROCESSING_STATE; 

    return(rcCmdProc);
}

//
// RX_SYNC_AVAIL
static _CMDPROC_RC evtRxSyncAvailHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    _CMDPROC_RC rcCmdProc;
    
    // TBD??
    // Determine rx sync good or bad by looking into the stat??
#if defined(_HOST_SIM_TESTING)
#define _SYNC_DATA_GOOD 1
#else
#define _SYNC_DATA_GOOD 1
#endif
    if (_SYNC_DATA_GOOD) 
        rcCmdProc = CMDPROC_RC_ASYNC_SUCC;
    else
        rcCmdProc = CMDPROC_RC_ASYNC_FAIL;

    // stop the timer
    //A_PRINTF("stop rx timer ..\n");
    A_UNTIMEOUT(&pCmdStateInfo->rxSyncTimer);

    // deregister the callback
    deregisterCallback(rxNotify);
    
    // transition to new state, since this is an event handler
    pCmdStateInfo->state = CMD_PROCESSING_STATE; 

    return(rcCmdProc);
}

//
// CMD processing State Machine
// 
// Architectural Notes:
// - Allows event/state specific evtXXXHandler for flexibility.
// - Normaly the generic eventCmdHandler can do the job, by calling opCode based
//   cmdParser and cmdProcessor.
//
_UTF_CMDPROCESS_SM_TABLE CmdProcSM[STATE_MAX] = {
// CMD_PROCESING has become the super state, or thread
{ // CMD_PROCESSING_STATE =0
    11, 
    {
    {EVT_RX_SYNC_CMD,   evtRxSyncCmdHandler,  RX_SYNC_STATE         },
    {EVT_TX_CMD,        evtTxCmdHandler,      SAME_STATE            },
    {EVT_RX_CMD,        evtRxCmdHandler,      RX_STATE              },
    {EVT_CAL_CMD,       evtCmdHandler,        SAME_STATE            },
    //{EVT_CAL_CMD,       evtCalCmdHandler,     CAL_OR_CHAR_STATE     },
    {EVT_CAL_DONE_CMD,  evtCmdHandler,        WAIT_4_CAL_DATA_STATE },
    {EVT_PM_CMD,        evtCmdHandler,        SAME_STATE },
    {EVT_NART_CMD,      evtCmdHandler,        SAME_STATE },
    
    // not really used
    {EVT_ENTRY_CMDPROC, NULL,                 NULL_STATE            },
    {EVT_CMD_DONE,      NULL,                 NULL_STATE            },
    {EVT_CMD_FAILURE,   NULL,                 NULL_STATE            },
    {EVT_CMD_TIMEOUT,   NULL,                 NULL_STATE            },
    },
}, 

{ // RX_SYNC_STATE =1
    2,
    {
    {EVT_RX_SYNC_AVAIL,   evtRxSyncAvailHandler,    CMD_PROCESSING_STATE     },                           
    {EVT_RX_SYNC_TIMEOUT, evtRxSyncTimeoutHandler,  CMD_PROCESSING_STATE     },                         
    },
},

{ // TX_STATE
    0,   // TX doesn't really have state transition
    {
    {EVT_TX_CMD, NULL, NULL_STATE},                       // EVT_NORMAL_TX
    },
}, 

{ // RX_STATE 
    2,
    {
    {EVT_RX_AVAIL,   evtRxAvailHandler,          CMD_PROCESSING_STATE     },
    {EVT_RX_TIMEOUT, evtRxTimeoutHandler,        CMD_PROCESSING_STATE     },                             
    },
},

{ // CAL_OR_CHAR_STATE 
    0,
    {
    {EVT_NULL, NULL, NULL_STATE},                         // EVT_CAL_POLL_DATA_PERIOD
    },
},

{ // WAIT_4_CAL_DATA_STATE
    1,
    {
    {EVT_POLL_CAL_DATA_TIMEOUT, evtPollCalDataHandler,  CMD_PROCESSING_STATE  },              // EVT_CAL_DATA_AVAIL
    },
},
{ // PM_STATE
    0,   // TX doesn't really have state transition
    {
    {EVT_PM_CMD, NULL, NULL_STATE},                       // EVT_NORMAL_PM
    },
}, 

};// CmdProcSM



