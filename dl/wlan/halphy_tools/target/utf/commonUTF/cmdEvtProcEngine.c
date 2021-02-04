#include "osapi.h"
#include "wlantype.h"
#include "cmdStream.h"
#include "parmBinTemplate.h"
#include "parseBinCmdStream.h"
#include "cmdAllParms.h"
#include "cmdProcessingSM.h"

// ==================================================================================
//
// Interface Declaration 
//
//
// Exported functions
//
void cmdProcessingEntry(void);
void cmdProcessingThread(_CMDPROC_STATE_INFO *pCmdStateInfo);
_CMDPROC_RC evtCmdHandler(_CMDPROC_STATE_INFO *pCmdStateInfo);
_CMDPROC_RC cmdProcessingSM(_CMDPROC_STATE_INFO *stateInfo);

//
// Exported Data
//
_CMDPROC_STATE_INFO CmdStateInfo;


//
// Local section
//

static _CMDPROC_DECISION cmdProcessingEvt(_CMDPROC_STATE_INFO *pCmdStateInfo);
static _CMDPROC_DECISION cmdProcessingNextCmd(_CMDPROC_STATE_INFO *pCmdStateInfo);
static _CMDPROC_DECISION cmdProcessingEndofQueue(_CMDPROC_STATE_INFO *pCmdStateInfo);
static _CMDPROC_DECISION cmdProcessingFailure(_CMDPROC_STATE_INFO *pCmdStateInfo);
static _CMDPROC_DECISION cmdProcessingTimeout(_CMDPROC_STATE_INFO *pCmdStateInfo);

//
// ==================================================================================


// ==================================================================================
//
// Implementation section
//
// 
// Notes:
// Only supports:
// 1. go back to the beginning
//
static _CMDPROC_DECISION cmdProcessingTimeout(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    _CMDPROC_DECISION rcDecision=_CMDPROC_CONT;
    _PARSED_BIN_CMD_STREAM_INFO *pCmdStreamInfo = pCmdStateInfo->pCmdStreamInfo;

    // update state and set event for continuing, but may _CMDPROC_END 
    pCmdStateInfo->state = CMD_PROCESSING_STATE;
    pCmdStateInfo->curEvt   = EVT_CMD_DONE;

    // set a maximum
    if (MAX_CMD_FAILURE <= pCmdStateInfo->timeoutRetryCount) {
        A_PRINTF("Abort, cmd timeout %d times.\n", pCmdStateInfo->timeoutRetryCount);
        return(_CMDPROC_END);
    }
    else {
       pCmdStateInfo->timeoutRetryCount++;
    }

    // similar logic as failed cmd?
    if (FAIL_RETRY_BACK_N_STEPS == pCmdStateInfo->timeoutRetry) {
        if (pCmdStreamInfo->curQBegin < pCmdStateInfo->timeoutRetrySteps) { 
            pCmdStreamInfo->curQBegin = CMDPROC_QUEUE_ABSOLUTE_BEGIN;
            rcDecision=_CMDPROC_RESET;
        }
        else {
            pCmdStreamInfo->curQBegin -= pCmdStateInfo->timeoutRetrySteps;
        }
    }
    else if (FAIL_RETRY_NOT == pCmdStateInfo->timeoutRetry) { 
        rcDecision = _CMDPROC_END;
    }
    else { // default to timeout to beginning // if (FAIL_RETRY_FROM_BEGINNING == pCmdStateInfo->timeoutRetry) 
        pCmdStreamInfo->curQBegin = CMDPROC_QUEUE_ABSOLUTE_BEGIN;
        rcDecision=_CMDPROC_RESET;
    }

    return(rcDecision);

}

//
// Notes:
// The current implementation supports:
//    1. fail and back n steps;
//    2. fail and back to beginning;
//    3. fail and abort
//
static _CMDPROC_DECISION cmdProcessingFailure(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    _CMDPROC_DECISION rcDecision=_CMDPROC_CONT;
    _PARSED_BIN_CMD_STREAM_INFO *pCmdStreamInfo = pCmdStateInfo->pCmdStreamInfo;

    // update state and set event for continuing, but may _CMDPROC_END 
    pCmdStateInfo->state = CMD_PROCESSING_STATE;
    pCmdStateInfo->curEvt   = EVT_CMD_DONE;

    // set a maximum
    if (MAX_CMD_FAILURE <= pCmdStateInfo->failRetryCount) {
        A_PRINTF("Abort, cmd failed %d times.\n", pCmdStateInfo->failRetryCount);
        return(_CMDPROC_END);
    }
    else {
       pCmdStateInfo->failRetryCount++;
    }

    if (FAIL_RETRY_BACK_N_STEPS == pCmdStateInfo->failRetry) {
        if (pCmdStreamInfo->curQBegin < pCmdStateInfo->failRetrySteps) { 
            pCmdStreamInfo->curQBegin = CMDPROC_QUEUE_ABSOLUTE_BEGIN;
            rcDecision=_CMDPROC_RESET;
        }
        else {
            pCmdStreamInfo->curQBegin -= pCmdStateInfo->failRetrySteps;
        }
    }
    else if (FAIL_RETRY_FROM_BEGINNING == pCmdStateInfo->failRetry) {
        pCmdStreamInfo->curQBegin = CMDPROC_QUEUE_ABSOLUTE_BEGIN;
        rcDecision=_CMDPROC_RESET;
    }
    else {
        rcDecision = _CMDPROC_END;
    }
    return(rcDecision);
}

static _CMDPROC_DECISION cmdProcessingEndofQueue(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    _CMDPROC_DECISION rc=_CMDPROC_END;
    if (REPEAT_TEST_FINITE == pCmdStateInfo->repeatTesting) {
        if (pCmdStateInfo->repeatCount) {
            pCmdStateInfo->pCmdStreamInfo->curQBegin = CMDPROC_QUEUE_ABSOLUTE_BEGIN;
            pCmdStateInfo->repeatCount--;
            rc = _CMDPROC_RESET;
        }
        else {
            // do nothing
        }
    }
    else if (REPEAT_TEST_FOREVER ==  pCmdStateInfo->repeatTesting) {
        pCmdStateInfo->pCmdStreamInfo->curQBegin = CMDPROC_QUEUE_ABSOLUTE_BEGIN;
        rc = _CMDPROC_RESET;
    }
    else {
        // do nothing
    }
    return(rc);
}


static _CMDPROC_DECISION cmdProcessingNextCmd(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    _CMD_QUEUE *curCmdQ = pCmdStateInfo->pCmdStreamInfo->curCmdQueue;
    _CMDPROC_DECISION rcDecision=_CMDPROC_CONT;
    A_UINT8 i, opCode;

    // process next cmd
    if (pCmdStateInfo->pCmdStreamInfo->curQBegin != pCmdStateInfo->pCmdStreamInfo->curQEnd) {
        i = pCmdStateInfo->pCmdStreamInfo->curQBegin;
        opCode = pCmdStateInfo->curCmd = curCmdQ[i].opCode;

        // map opCode to state and event
        //pCmdStateInfo->nextState = COp2StateEvt[opCode].state;
        pCmdStateInfo->curEvt   = Op2StateEvt[opCode].evt;

        // event processing
        rcDecision = cmdProcessingEvt(pCmdStateInfo);
    }
    else {
        rcDecision = cmdProcessingEndofQueue(pCmdStateInfo);
    }
    
    return(rcDecision);
}


//
// tx_cmd, rx_cmd, rx_symc_cmd
// rx_sync_avail, rx_sync_timout, rx_avail, rx_timeout
static _CMDPROC_DECISION cmdProcessingEvt(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    _CMDPROC_DECISION rcDecision=_CMDPROC_CONT;
#if 0   // kept in case reviving it
    _CMDPROC_RC       rcCmdProc=RC_NULL;
    //
    // cmd processing
    rcCmdProc = cmdProcessingSM(pCmdStateInfo);
    if ((CMDPROC_RC_SYNC_SUCC == rcCmdProc) || (CMDPROC_RC_ASYNC_SUCC == rcCmdProc)) {
        rcDecision = _CMDPROC_CONT;
    }
    else if ((CMDPROC_RC_SYNC_FAIL == rcCmdProc) || (CMDPROC_RC_ASYNC_FAIL == rcCmdProc)) {
        A_PRINTF("Err cmd %d\n", opCode);
        rcDecision = cmdProcessingFailureHandler(pCmdStateInfo);
    }
    else if (CMDPROC_RC_ASYNC == rcCmdProc) {
        // we are done here, wait for the stimuli coming later
        // examples are RX operations, typically some procssing is done and a timer is started
        // later either the right results came back, e.g. rx'ed packet or timeout
        // in either case, a registered "callback" will call cmdProcessingThread.
        rcDecision = _CMDPROC_END;
    }
    else { // CMDPROC_RC_NULL, no action
        rcDecision = _CMDPROC_NULL;  // do nothing
    }
#endif
            _CMDPROC_RC  rcCmdProc= cmdProcessingSM(pCmdStateInfo);
            if ((CMDPROC_RC_SYNC_SUCC == rcCmdProc) || (CMDPROC_RC_ASYNC_SUCC == rcCmdProc)) {
                 rcDecision = _CMDPROC_CONT;
                 pCmdStateInfo->curEvt = EVT_CMD_DONE;
            }
            else if ((CMDPROC_RC_SYNC_FAIL == rcCmdProc) || (CMDPROC_RC_ASYNC_FAIL == rcCmdProc)) {
                 rcDecision = _CMDPROC_CONT;
                 A_PRINTF("Err cmd %d\n", pCmdStateInfo->curCmd);
                 pCmdStateInfo->curEvt = EVT_CMD_FAILURE;
            }
            else if (CMDPROC_RC_ASYNC_TIMEOUT == rcCmdProc) {
                 rcDecision = _CMDPROC_CONT;
                 pCmdStateInfo->curEvt = EVT_CMD_TIMEOUT;
            }
            else if (CMDPROC_RC_ASYNC == rcCmdProc) {
                // we are done here, wait for the stimuli coming later
                // examples are RX operations, typically some procssing is done and a timer is started
                // later either the right results came back, e.g. rx'ed packet or timeout
                // in either case, a registered "callback" will call cmdProcessingThread.
                rcDecision = _CMDPROC_END;
            }
            else { // CMDPROC_RC_NULL, no action
                rcDecision = _CMDPROC_NULL;  // do nothing
            }

    return(rcDecision);
}

//
// Notes:
// cmdProcessingThread is the cmd processing "thread", or super state. 
// It's written in this way to fit the single treaded ATHR OS
//
// The input is the event and state. 
// In essence, it is just another state, but implemented separately to make the cmdSM complete and exit
//
// Thread handles entry, internal cmd_done, cmd_failure, external event (avail, timeout)
//
// There should NOT be changes required for this piece. It's a simple engine.
void cmdProcessingThread(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    A_BOOL contCmdProcessing=TRUE;
    int count=10000;
    _CMDPROC_DECISION rcDecision=_CMDPROC_CONT;
    //
    while (contCmdProcessing && count--) {
        //
        // Architectural Notes:
        // 1. There are 4 broad command events entering this CMD_PROCESSING_STATE "super state",
        // entering_cmd_processing_from_beginning, cmd_done, timeout, cmd_failure, 
        // 2. The rest of events are processed accordingly by event handllers ???
        //A_PRINTF("evt %d state %d ..\n", pCmdStateInfo->curEvt, pCmdStateInfo->state);
        if (pCmdStateInfo->curEvt == EVT_CMD_FAILURE) {
            rcDecision = cmdProcessingFailure(pCmdStateInfo);
        }
        else if (pCmdStateInfo->curEvt == EVT_CMD_TIMEOUT) {
            rcDecision = cmdProcessingTimeout(pCmdStateInfo);
        }
        else if (pCmdStateInfo->curEvt == EVT_ENTRY_CMDPROC || pCmdStateInfo->curEvt == EVT_CMD_DONE) {
            rcDecision = cmdProcessingNextCmd(pCmdStateInfo);
        }
        else {
            // update state info too, based on event
            rcDecision = cmdProcessingEvt(pCmdStateInfo);
        }
 
        // either end the loop, or do nothing
        if ((_CMDPROC_END == rcDecision) || (_CMDPROC_NULL == rcDecision)) {
            contCmdProcessing = FALSE;
        }
        else if (_CMDPROC_CONT == rcDecision) { // _CMDPROC_CONT
            // advance cmdQ, reload count
            count=10000;
            pCmdStateInfo->pCmdStreamInfo->curQBegin++;
        }
        else { // _CMDPROC_RESET
            // don't advance curQ
        }
    }
}


//
// Entry point of cmd processing
// It's different from cmdProcessingThread which is the "thread" or super state
//
void cmdProcessingEntry(void)
{
#if defined(_HOST_SIM_TESTING)
    memset((void*)&CmdStateInfo, 0, sizeof(CmdStateInfo));
#else
    A_MEMZERO((void*)&CmdStateInfo, sizeof(CmdStateInfo));
#endif
    // create timers
    createTimers();

    if (CmdStreamInfo.header & CMD_STREAM_HEADER_REPEAT_TEST) {
        CmdStateInfo.repeatNum = (CmdStreamInfo.headerDepValue >> REPEAT_TEST_SHIFT) & REPEAT_TEST_MASK;
        if (CmdStateInfo.repeatNum) {
            CmdStateInfo.repeatTesting = REPEAT_TEST_FINITE; 
            CmdStateInfo.repeatCount = CmdStateInfo.repeatNum; 
        }
        else {
            CmdStateInfo.repeatTesting = REPEAT_TEST_FOREVER; 
        }
    }

    if (CmdStreamInfo.header & CMD_STREAM_HEADER_FAIL_RETRY) {
        CmdStateInfo.failRetrySteps = ((CmdStreamInfo.headerDepValue & FAIL_RETRY_MASK) >> FAIL_RETRY_SHIFT) & 0xF;
        if (CmdStateInfo.failRetrySteps) {
            CmdStateInfo.failRetry = REPEAT_TEST_FINITE; 
        }
        else {
            CmdStateInfo.failRetry = REPEAT_TEST_FOREVER; 
        }
    }

    if (CmdStreamInfo.header & CMD_STREAM_HEADER_TIMEOUT_RETRY) {
        CmdStateInfo.timeoutRetrySteps = ((CmdStreamInfo.headerDepValue & TIMEOUT_RETRY_MASK) >> TIMEOUT_RETRY_SHIFT) & 0xF;
        if (CmdStateInfo.timeoutRetrySteps) {
            CmdStateInfo.timeoutRetry = FAIL_RETRY_BACK_N_STEPS; 
        }
        else {
            CmdStateInfo.timeoutRetry = FAIL_RETRY_FROM_BEGINNING; 
        }
    }

    if (CmdStreamInfo.header & CMD_STREAM_HEADER_CAL_W_TGTPWR) {
        CmdStateInfo.testConfig |= TEST_CONFIG_CAL_W_TGTPWR;
    }

    // setup for starting cmd processing state machine
    CmdStateInfo.state = CMD_PROCESSING_STATE;
    CmdStateInfo.curEvt = EVT_ENTRY_CMDPROC;
    CmdStateInfo.pCmdStreamInfo = &CmdStreamInfo;

    // enter cmd processing "thread"
    cmdProcessingThread(&CmdStateInfo);

    return;
}

_CMDPROC_RC cmdProcessingSM(_CMDPROC_STATE_INFO *stateInfo)
{
    int i;
    _CMDPROC_RC rcCmdproc=CMDPROC_RC_NULL;
    _CMDPROC_STATE curState = stateInfo->state;

    // state processing ...
    for (i=0;i< CmdProcSM[stateInfo->state].numEvt;i++) {
        if (stateInfo->curEvt == ((CmdProcSM[stateInfo->state]).evtTbl[i]).evtHandled) {
            stateInfo->curEvtIdx = i; // save for later use
            if (((CmdProcSM[stateInfo->state]).evtTbl[i]).pCurStateProcessing) {
                //A_PRINTF("evt %d(idx %d) state %d to \n", stateInfo->curEvt, stateInfo->curEvtIdx, stateInfo->state);
                rcCmdproc = (((CmdProcSM[stateInfo->state]).evtTbl[i]).pCurStateProcessing)(stateInfo); 
                //A_PRINTF("=> %d\n", stateInfo->state);
            }
            break;
        }
    }
    if (i > CmdProcSM[curState].numEvt) {
        A_PRINTF("evt %d not handled in state %d\n", stateInfo->curEvt, stateInfo->state);
    }

    // update state in the evtCmdHandler
#if 0
    // move to next state regardless success or failure?
    if (SAME_STATE != CmdProcSM[curState].evtTbl[pCmdStateInfo->curEvtIdx].nextState) {
        pCmdStateInfo->state = CmdProcSM[curState].evtTbl[pCmdStateInfo->curEvtIdx].nextState; 
    }
#endif

    return(rcCmdproc);
}

//
// Notes:
// 1. The "absolute beginning" position of the cmdQ is always at 0. This is when the test flow repeats
// or back to beginning after failure.
//
// generic cmd event handler
_CMDPROC_RC evtCmdHandler(_CMDPROC_STATE_INFO *pCmdStateInfo)
{
    _CMD_QUEUE *curCmdQ = pCmdStateInfo->pCmdStreamInfo->curCmdQueue;
    _CMDPROC_RC rcCmdProc=CMDPROC_RC_NULL;
    _CMD_OPCODES opCode = pCmdStateInfo->curCmd;
    A_UINT16 i=pCmdStateInfo->pCmdStreamInfo->curQBegin;
    _CMD_ALL_PARMS *parms;
    _CMDPROC_STATE curState = pCmdStateInfo->state;

    //A_PRINTF("%s\n", __func__);
    if (CmdHandlers[opCode]._CmdParmsParser) {
        if (!(CmdHandlers[opCode]._CmdParmsParser)(curCmdQ[i].cmdParmBuf, &parms, curCmdQ[i].numOfParms)) {
            A_PRINTF("Err parser(cmd %d)\n", opCode); // cmd parsing failure, due to stupid error
            return(CMDPROC_RC_SYNC_FAIL);
        }
    }
      
    if (CmdHandlers[opCode]._CmdProcessor) {
        rcCmdProc = (CmdHandlers[opCode]._CmdProcessor)(parms);
        if (CMDPROC_RC_SYNC_FAIL == rcCmdProc || CMDPROC_RC_ASYNC_FAIL == rcCmdProc) {
            A_PRINTF("Err cmdProc(cmd %d)\n", opCode); // cmd execution failure, 
        }
    }
    
#if 1  
    // move to next state regardless success or failure?
    if (SAME_STATE != CmdProcSM[curState].evtTbl[pCmdStateInfo->curEvtIdx].nextState) {
        pCmdStateInfo->state = CmdProcSM[curState].evtTbl[pCmdStateInfo->curEvtIdx].nextState; 
    }
#endif

    return(rcCmdProc); 
} 
 
