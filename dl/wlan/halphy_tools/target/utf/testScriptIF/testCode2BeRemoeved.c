#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_HOST_SIM_TESTING)
#include "otaHostCommon.h"
#else
#include "osapi.h"
#endif
#include "wlantype.h"

//#include "cmdOpcodes.h"
#include "cmdStream.h"

#if !defined(_HOST_SIM_TESTING)
#include "utf.h"
#include "testUtil.h"
#endif
#include "parmBinTemplate.h"
#include "parseBinCmdStream.h"
#include "cmdAllParms.h"
#include "cmdTxParms.h"
#include "cmdRxParms.h"
#include "cmdProcessingSM.h"
#include "testcmd.h"


//#define _FOR_TESTING
#if defined(_FOR_TESTING)
static  _TESTFLOW_CMD_STREAM testCmdStream;

void composeACmdStream4Testing(int *cmdStreamLen, A_UINT8 **rCmdStream)
{
    _CMD_ONEOF oneCmd;
    A_INT32 cmdStreamPos=0, curCmdTotalLen;
    A_UINT8 *cmdStream;
    A_UINT16 sum;

    memset((void*)&testCmdStream, 0, sizeof(testCmdStream));
    testCmdStream.cmdStreamHeader.version = CMD_STREAM_VER1;
    //testCmdStream.cmdStreamHeader.header = CMD_STREAM_HEADER_REPEAT_TEST | CMD_STREAM_HEADER_FAIL_RETRY;
    //testCmdStream.cmdStreamHeader.headerDepValue = ((2 << FAIL_RETRY_SHIFT) & FAIL_RETRY_MASK) | (5 & REPEAT_TEST_MASK);
    testCmdStream.cmdStreamHeader.header = 0;
    testCmdStream.cmdStreamHeader.headerDepValue = 0;
    testCmdStream.cmdStreamHeader.headerExtended  = 0;
    testCmdStream.cmdStreamHeader.checkSum = 0;
 
    cmdStreamPos = 0;

#if 1    //
    // _OP_SYNC
    memset((void*)&oneCmd, 0, sizeof(oneCmd));
    oneCmd.cmdHeader.opCode = 0;  // _OP_RX
    oneCmd.cmdHeader.numOfParms = 2;
    oneCmd.parms.parm[0].parmCode = _rxParm_code_channel; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmValue.value.val32 = 2412;
#if 0
    oneCmd.parms.parm[1].parmCode = _rxParm_code_act; // _rxParm_code_channel
    oneCmd.parms.parm[1].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[1].parmValue.value.val32 =TCMD_CONT_RX_FILTER;
#endif
    oneCmd.parms.parm[1].parmCode = _rxParm_code_addr; // _rxParm_code_addr
    oneCmd.parms.parm[1].parmType = _PARM_U8; // _rxParm_code_addr
    oneCmd.parms.parm[1].parmValue.addr[0] = 0x01;
    oneCmd.parms.parm[1].parmValue.addr[1] = 0x00;
    oneCmd.parms.parm[1].parmValue.addr[2] = 0x00;
    oneCmd.parms.parm[1].parmValue.addr[3] = 0xCA;
    oneCmd.parms.parm[1].parmValue.addr[4] = 0xFF;
    oneCmd.parms.parm[1].parmValue.addr[5] = 0xEE;

    curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
    memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
    cmdStreamPos += curCmdTotalLen;
#endif
#if 1
    //
    // _OP_TX
    memset((void*)&oneCmd, 0, sizeof(oneCmd));
    oneCmd.cmdHeader.opCode = 1;   // _OP_TX
    oneCmd.cmdHeader.numOfParms = 3;
    oneCmd.parms.parm[0].parmCode = _txParm_code_channel; // _txParm_code_channel
    oneCmd.parms.parm[0].parmType = _PARM_U32; // _txParm_code_channel
    oneCmd.parms.parm[0].parmValue.value.val32 = 2412;
    oneCmd.parms.parm[1].parmCode = _txParm_code_rateMask0; // _2txParm_code_rateMask0;
    oneCmd.parms.parm[1].parmType = _PARM_U32; // _txParm_code_rateMask0;
    //oneCmd.parms.parm[1].parmValue.value.val32 = 0x81818141; // _txParm_code_rateMask0;
    oneCmd.parms.parm[1].parmValue.value.val32 = 0x00008100; // _txParm_code_rateMask0;
    oneCmd.parms.parm[2].parmCode = _txParm_code_numPackets; 
    oneCmd.parms.parm[2].parmType = _PARM_U32; 
    oneCmd.parms.parm[2].parmValue.value.val32 = 44; 
    curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
    memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
    cmdStreamPos += curCmdTotalLen;
#endif
    //
    // _OP_RX
    memset((void*)&oneCmd, 0, sizeof(oneCmd));
    oneCmd.cmdHeader.opCode = 2;  // _OP_RX
    oneCmd.cmdHeader.numOfParms = 4;
    oneCmd.parms.parm[0].parmCode = _rxParm_code_channel; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmValue.value.val32 = 2412;
    oneCmd.parms.parm[1].parmCode = _rxParm_expectedPkts; // _rxParm_code_channel
    oneCmd.parms.parm[1].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[1].parmValue.value.val32 = 200;
    oneCmd.parms.parm[2].parmCode = _rxParm_code_addr; // _rxParm_code_addr
    oneCmd.parms.parm[2].parmType = _PARM_U8; // _rxParm_code_addr
    oneCmd.parms.parm[2].parmValue.addr[0] = 0x01;
    oneCmd.parms.parm[2].parmValue.addr[1] = 0x00;
    oneCmd.parms.parm[2].parmValue.addr[2] = 0x00;
    oneCmd.parms.parm[2].parmValue.addr[3] = 0xC0;
    oneCmd.parms.parm[2].parmValue.addr[4] = 0xFF;
    oneCmd.parms.parm[2].parmValue.addr[5] = 0xEE;
    oneCmd.parms.parm[3].parmCode = _rxParm_code_act; // _rxParm_code_channel
    oneCmd.parms.parm[3].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[3].parmValue.value.val32 = TCMD_CONT_RX_FILTER;
    curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
    memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
    cmdStreamPos += curCmdTotalLen;

#if 1
    // _OP_SYNC
    memset((void*)&oneCmd, 0, sizeof(oneCmd));
    oneCmd.cmdHeader.opCode = 0;  // _OP_RX
    oneCmd.cmdHeader.numOfParms = 2;
    oneCmd.parms.parm[0].parmCode = _rxParm_code_channel; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmValue.value.val32 = 2437;
    oneCmd.parms.parm[1].parmCode = _rxParm_code_addr; // _rxParm_code_addr
    oneCmd.parms.parm[1].parmType = _PARM_U8; // _rxParm_code_addr
    oneCmd.parms.parm[1].parmValue.addr[0] = 0x01;
    oneCmd.parms.parm[1].parmValue.addr[1] = 0x00;
    oneCmd.parms.parm[1].parmValue.addr[2] = 0x00;
    oneCmd.parms.parm[1].parmValue.addr[3] = 0xCA;
    oneCmd.parms.parm[1].parmValue.addr[4] = 0xFF;
    oneCmd.parms.parm[1].parmValue.addr[5] = 0xEE;
    curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
    memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
    cmdStreamPos += curCmdTotalLen;
#endif

    //
#if 1
    // _OP_TX
    memset((void*)&oneCmd, 0, sizeof(oneCmd));
    oneCmd.cmdHeader.opCode = 1;   // _OP_TX
    oneCmd.cmdHeader.numOfParms = 3;
    oneCmd.parms.parm[0].parmCode = _txParm_code_channel; // _txParm_code_channel
    oneCmd.parms.parm[0].parmType = _PARM_U32; // _txParm_code_channel
    oneCmd.parms.parm[0].parmValue.value.val32 = 2437;
    oneCmd.parms.parm[1].parmCode = _txParm_code_rateMask0; // _2txParm_code_rateMask0;
    oneCmd.parms.parm[1].parmType = _PARM_U32; // _txParm_code_rateMask0;
    //oneCmd.parms.parm[1].parmValue.value.val32 = 0x81818141; // _txParm_code_rateMask0;
    oneCmd.parms.parm[1].parmValue.value.val32 = 0x00008100; // _txParm_code_rateMask0;
    oneCmd.parms.parm[2].parmCode = _txParm_code_numPackets; 
    oneCmd.parms.parm[2].parmType = _PARM_U32; 
    oneCmd.parms.parm[2].parmValue.value.val32 = 44; 
    curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
    memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
    cmdStreamPos += curCmdTotalLen;
#endif

#if 1
    // _OP_RX
    memset((void*)&oneCmd, 0, sizeof(oneCmd));
    oneCmd.cmdHeader.opCode = 2;  // _OP_RX
    oneCmd.cmdHeader.numOfParms = 4;
    oneCmd.parms.parm[0].parmCode = _rxParm_code_channel; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmValue.value.val32 = 2437;
    oneCmd.parms.parm[1].parmCode = _rxParm_expectedPkts; // _rxParm_code_channel
    oneCmd.parms.parm[1].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[1].parmValue.value.val32 = 200;
    oneCmd.parms.parm[2].parmCode = _rxParm_code_addr; // _rxParm_code_addr
    oneCmd.parms.parm[2].parmType = _PARM_U8; // _rxParm_code_addr
    oneCmd.parms.parm[2].parmValue.addr[0] = 0x01;
    oneCmd.parms.parm[2].parmValue.addr[1] = 0x00;
    oneCmd.parms.parm[2].parmValue.addr[2] = 0x00;
    oneCmd.parms.parm[2].parmValue.addr[3] = 0xC0;
    oneCmd.parms.parm[2].parmValue.addr[4] = 0xFF;
    oneCmd.parms.parm[2].parmValue.addr[5] = 0xEE;
    oneCmd.parms.parm[3].parmCode = _rxParm_code_act; // _rxParm_code_channel
    oneCmd.parms.parm[3].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[3].parmValue.value.val32 = TCMD_CONT_RX_FILTER;
    curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
    memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
    cmdStreamPos += curCmdTotalLen;
#endif

#if 1
    // _OP_SYNC
    memset((void*)&oneCmd, 0, sizeof(oneCmd));
    oneCmd.cmdHeader.opCode = 0;  // _OP_RX
    oneCmd.cmdHeader.numOfParms = 2;
    oneCmd.parms.parm[0].parmCode = 0; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmValue.value.val32 = 2472;
    oneCmd.parms.parm[1].parmCode = _rxParm_code_addr; // _rxParm_code_addr
    oneCmd.parms.parm[1].parmType = _PARM_U8; // _rxParm_code_addr
    oneCmd.parms.parm[1].parmValue.addr[0] = 0x01;
    oneCmd.parms.parm[1].parmValue.addr[1] = 0x00;
    oneCmd.parms.parm[1].parmValue.addr[2] = 0x00;
    oneCmd.parms.parm[1].parmValue.addr[3] = 0xCA;
    oneCmd.parms.parm[1].parmValue.addr[4] = 0xFF;
    oneCmd.parms.parm[1].parmValue.addr[5] = 0xEE;
    curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
    memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
    cmdStreamPos += curCmdTotalLen;
#endif

#if 1
    // _OP_TX
    memset((void*)&oneCmd, 0, sizeof(oneCmd));
    oneCmd.cmdHeader.opCode = 1;   // _OP_TX
    oneCmd.cmdHeader.numOfParms = 3;
    oneCmd.parms.parm[0].parmCode = _txParm_code_channel; // _txParm_code_channel
    oneCmd.parms.parm[0].parmType = _PARM_U32; // _txParm_code_channel
    oneCmd.parms.parm[0].parmValue.value.val32 = 2472;
    oneCmd.parms.parm[1].parmCode = _txParm_code_rateMask0; // _2txParm_code_rateMask0;
    oneCmd.parms.parm[1].parmType = _PARM_U32; // _txParm_code_rateMask0;
    oneCmd.parms.parm[1].parmValue.value.val32 = 0x00008100; // _txParm_code_rateMask0;
    oneCmd.parms.parm[2].parmCode = _txParm_code_numPackets; 
    oneCmd.parms.parm[2].parmType = _PARM_U32; 
    oneCmd.parms.parm[2].parmValue.value.val32 = 44; 
    curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
    memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
    cmdStreamPos += curCmdTotalLen;
#endif
    //
    // _OP_RX
    memset((void*)&oneCmd, 0, sizeof(oneCmd));
    oneCmd.cmdHeader.opCode = 2;  // _OP_RX
    oneCmd.cmdHeader.numOfParms = 4;
    oneCmd.parms.parm[0].parmCode = _rxParm_code_channel; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[0].parmValue.value.val32 = 2472;
    oneCmd.parms.parm[1].parmCode = _rxParm_expectedPkts; // _rxParm_code_channel
    oneCmd.parms.parm[1].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[1].parmValue.value.val32 = 200;
    oneCmd.parms.parm[2].parmCode = _rxParm_code_addr; // _rxParm_code_addr
    oneCmd.parms.parm[2].parmType = _PARM_U8; // _rxParm_code_addr
    oneCmd.parms.parm[2].parmValue.addr[0] = 0x01;
    oneCmd.parms.parm[2].parmValue.addr[1] = 0x00;
    oneCmd.parms.parm[2].parmValue.addr[2] = 0x00;
    oneCmd.parms.parm[2].parmValue.addr[3] = 0xC0;
    oneCmd.parms.parm[2].parmValue.addr[4] = 0xFF;
    oneCmd.parms.parm[2].parmValue.addr[5] = 0xEE;
    oneCmd.parms.parm[3].parmCode = _rxParm_code_act; // _rxParm_code_channel
    oneCmd.parms.parm[3].parmType = _PARM_U32; // _rxParm_code_channel
    oneCmd.parms.parm[3].parmValue.value.val32 = TCMD_CONT_RX_FILTER;
    curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
    memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
    cmdStreamPos += curCmdTotalLen;

    // get the whole cmd stream ready.
    // either pass the whole stream down the host/dut interface, or write to a binary file
    cmdStream = (A_UINT8 *)&testCmdStream;
    testCmdStream.cmdStreamHeader.length = cmdStreamPos;
    *cmdStreamLen = testCmdStream.cmdStreamHeader.length +sizeof(_TESTFLOW_CMD_STREAM_HEADER); 

    // computer checksum
    sum = computeChecksumOnly((A_UINT16*)cmdStream, (*cmdStreamLen)/2);
    testCmdStream.cmdStreamHeader.checkSum = 0xFFFF ^ sum;
    
    *rCmdStream = cmdStream;

    return;
}

#endif
