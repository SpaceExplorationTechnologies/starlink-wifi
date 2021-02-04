#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#if defined(_HOST_SIM_TESTING)
#include "tsCommon.h"
#else
#include "osapi.h"
#endif
#include "wlantype.h"

#include "cmdRspParmsInternal.h"
#include "cmdRspParmsDict.h"
#include "tlvCmdEncoder.h"

extern TESTFLOW_CMD_STREAM_V2  CmdStreamV2;
void dumpCmdStream(void)
{
    TESTFLOW_CMD_STREAM_V2 *pCmdStream= &CmdStreamV2;
    TESTFLOW_CMD_STREAM_HEADER_V2 *pCmdStreamHdr = &(pCmdStream->cmdStreamHeader);
    A_UINT32 streamPos;

    printf("hdr: cmdId 0x%x ver 0x%x payLen %d\n", (int)pCmdStreamHdr->cmdId, (int)pCmdStreamHdr->version, (int)pCmdStreamHdr->length); 
    streamPos=0;
    for (streamPos=0; streamPos< pCmdStreamHdr->length; streamPos++) {
        printf("0x%x ", (int)pCmdStream->payload[streamPos]); 
    }
    printf("done: byte dump\n");
    streamPos=0;
    for (streamPos=0; streamPos< pCmdStreamHdr->length; streamPos+=4) {
        printf("0x%x ", (int)pCmdStream->payload[streamPos]); 
    }
    printf("done: U32 dump\n");
}

A_UINT8  array[]={11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
int main(void)
{
    createCmdRsp(CMD_TX, 6, PARM_FREQ, 5180, PARM_CHAINMASK, 0x7, PARM_RATE, 6);
    dumpCmdStream();
    wait4Rsp(&rspStream);
    tlvParser(rspStream);

    createCmdRsp(CMD_TX, 10, PARM_FREQ, 5180, PARM_CHAINMASK, 0x7, PARM_RATE, 6, PARM_FIELD2, 5, 3, &(array[0]));
    dumpCmdStream();
    wait4Rsp(&rspStream);
    tlvParser(rspStream);

    return(0);
}

