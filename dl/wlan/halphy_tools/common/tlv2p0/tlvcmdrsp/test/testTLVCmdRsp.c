#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#if defined(_HOST_SIM_TESTING)
#include "tsCommon.h"
#else
#include "osapi.h"
#endif
#include "wlantype.h"
#include "cmdRspParmsInternal.h"
#include "cmdRspParmsDict.h"
#include "cmdStreamCommon.h"
#include "tlvCmdRspInternal.h"
#include "tlvCmdRsp.h"
#include "parseTSBinCmds.h"

void fakeFetchCmdStream(A_UINT8 *buf, A_UINT8 **pCmdStream, A_UINT32 *cmdStreamLen)
{
    TESTFLOW_CMD_STREAM_V2 *cmdStream;
    *pCmdStream = buf;
    // get the length 
    cmdStream = (TESTFLOW_CMD_STREAM_V2 *)buf;
    *cmdStreamLen = sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + cmdStream->cmdStreamHeader.length;
}

A_UINT8  array[]={0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa};
void testTLV2p0(void)
{
    TESTFLOW_CMD_STREAM_V2 *pCmdStream;

    // add TLV2p0
    // TBD?? should be based on a package config file
    addTLV2p0BinCmdParser();
    addTLV2p0Encoder(); 
    // for testing
    bindFetchCmdStream(fakeFetchCmdStream);

    // create a command stream, with example tx parms
    pCmdStream = (TESTFLOW_CMD_STREAM_V2 *)createCmdRsp(CMD_TX, 10, PARM_FREQ, (FREQ2BYTE_5G(5180)), PARM_CHAINMASK, 0x7, PARM_RATE, 6, PARM_FIELD2, 5, 3, &(array[0]));

    // parse the cmd stream, and verify the parms
    // get pCmdStream, and cmdStreamLen
    //    (HostIF.hostIFCmdStreamFetch)(buf, &pCmdStream, &cmdStreamLen);
    if (NULL != pCmdStream) {
        tlvParser((A_UINT8 *)pCmdStream);
    }

    return;
}

static void testTLV2p0TS(void)
{
    //addARCmdHandlers();

    // generate a TS file
    // parse this file

    return;
}

static void testTLV1p0TS(void)
{
    //addTSBinCmdParser();

    // generate a test sequence

    // parse the sequence

    return;
}

int main(void)
{
    testTLV2p0();

    testTLV1p0TS();

    testTLV2p0TS();

    return(0);
}

