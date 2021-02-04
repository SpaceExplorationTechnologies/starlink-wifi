
#include "commonInc.h"
#include "cmdStream.h"
#include "tlv2Inc.h"
#include "parseBinCmdStream.h"
#include "cmdStreamCommon.h"
#include "tlvCmdRspInternal.h"
#include "tlvCmdRsp.h"

extern void * pParamPtr_ch;


/* UTF data object, only one instance */
TLV_CMDRSP_DATA TlvCmdRspData, *pTlvCmdRspData=&TlvCmdRspData;

pCmdProcessingEntry binCmdsProcessing[] = {
    NULL,    // not used
    NULL,    // version 1, cmdProcessingEntry
    NULL,    // version 2, cmdProcessingEntry_v2
    NULL,    // version 3, cmdProcessingEntry_v3
};

pBinCmdStreamParser binCmdStreamParser[] = {
    NULL,    // version 0, not used, 0 is difficult to tell
    NULL,    // version 1, binCmdStreamParser_Ver1
    NULL,    // version 2, binCmdStreamParser_Ver2
    NULL,    // version 3, binCmdStreamParser_Ver3
};

A_BOOL bindBinCmdProcessing(pCmdProcessingEntry pf, int version)
{
    if (version > CMD_STREAM_VER_LATEST) {
        return(FALSE);
    }
    binCmdsProcessing[version] = pf;
    return(TRUE);
}

A_BOOL bindBinCmdStreamParser(pBinCmdStreamParser pf, int version)
{
    if (version > CMD_STREAM_VER_LATEST) {
        A_PRINTF_ALWAYS("v %d %d\n", version, CMD_STREAM_VER_LATEST);
        return(FALSE);
    }
    //A_PRINTF_ALWAYS("b %d 0x%x\n", version,pf);
    binCmdStreamParser[version] = pf;
    return(TRUE);
}

#ifdef QTIP
TLV2_API A_UINT32 read_A_UINT32_offsetFromStream(A_UINT32 offset)
{
	return *((int*)pParamPtr_ch + offset);
}

TLV2_API A_UINT32 read_A_UINT32(A_UINT32 * address)
{
	return *(address);
}

TLV2_API void prtStream(char *stream, int streamLen) 
{
	int n;
	for (n=0; n<streamLen; n++)
	{
		if (n == 0)	printf("    \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
		if (n%4 == 0) printf("%3d \xb3", n);
		printf(" %02x",(unsigned char)stream[n]); 
		if (n%4 == 3) printf(" \xb3 %u\n", *((unsigned int *)&stream[n-3]));
		if (n == streamLen - 1) printf("    \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
	}
}

char data_cache[PARM_BUF_LEN_MAX];

TLV2_API char* cmdStreamParsingAndProcessing_wrapper(A_UINT8 *cmdStreamBuf, A_UINT32 cmdStreamLen, A_UINT16 *payloadLen, A_BOOL* status)
{
	*status = cmdStreamParsingAndProcessing(cmdStreamBuf, cmdStreamLen, &data_cache, payloadLen);
	//prtStream(data_cache, *payloadLen);
	return data_cache;
}
#endif

//
// Architectural Note:
//   all host interface specific function needs to call this function with cmdStream and length
//
//   HostIF.hostIFProcessing(void) {
//      // host IF specific cmdStream fetch
//      // e.g. rawHTC, through call back htcRecvDone/htcReadCmd
//      //      testScript, by reading a memory location
//      // Outcome of this step is the cmdStreamBuf and cmdStreamLen
//      hostIFCmdStreamFetch(A_UINT8 **cmdStreamBuf, A_UINT32 *cmdStreamLen);
//
//      // parse the cmd stream by calling the standard parsingAnd Processing function
//      cmdStreamParsingAndProcessing(A_UINT8 *cmdStreamBuf, A_UINT32 cmdStreamLen)
//
//  If the host IF is the callback type like HTC, the HostIF.hostIFProcessing will be NULL,
//  but the actual function will be embedded in the callback.
//
//  pPayload and length are here for bypass, for example.
//
A_BOOL cmdStreamParsingAndProcessingInternal(A_UINT8 *cmdStreamBuf, A_UINT32 cmdStreamLen, A_UINT8 **pPayload, A_UINT16 *payloadLen, A_UINT8 *numRemainSegs) 
{
    // cmd stream parser  --------------------
    A_BOOL rc=TRUE;
    //_TESTFLOW_CMD_STREAM_HEADER *pCmdStreamHeader = (_TESTFLOW_CMD_STREAM_HEADER *)&(cmdStreamBuf[0]);
    _TESTFLOW_CMD_STREAM_HEADER *pCmdStreamHeader; 

    pCmdStreamHeader = (_TESTFLOW_CMD_STREAM_HEADER *)&(cmdStreamBuf[0]);
    //A_PRINTF_ALWAYS("cmdV %d %d\n", pCmdStreamHeader->version, CMD_STREAM_VER_LATEST);
    // check the binary cmd stream version
    if (pCmdStreamHeader->version > CMD_STREAM_VER_LATEST) {
        A_PRINTF_ALWAYS("unsupported cmd stream version %d\n", (int)pCmdStreamHeader->version);
        return(FALSE);
    }

    // parse cmd stream
    if (NULL != binCmdStreamParser[pCmdStreamHeader->version]) {
        rc = (binCmdStreamParser[pCmdStreamHeader->version])(cmdStreamBuf, cmdStreamLen, pPayload, payloadLen, numRemainSegs);
    }

    // cmd processing --------------------
    if (NULL != binCmdsProcessing[pCmdStreamHeader->version]) {
        (binCmdsProcessing[pCmdStreamHeader->version])();
    }

    return(TRUE);
}

TLV2_API A_BOOL cmdStreamParsingAndProcessing(A_UINT8 *cmdStreamBuf, A_UINT32 cmdStreamLen, A_UINT8 **pPayload, A_UINT16 *payloadLen) 
{
    A_UINT8 numRemainSegs;
    return (cmdStreamParsingAndProcessingInternal(cmdStreamBuf,cmdStreamLen, pPayload, payloadLen, &numRemainSegs));
}

TLV2_API A_BOOL cmdStreamParsingAndProcessingExt(A_UINT8 *cmdStreamBuf, A_UINT32 cmdStreamLen, A_UINT8 **pPayload, A_UINT16 *payloadLen, A_UINT8 *numRemainSegs) 
{
    return (cmdStreamParsingAndProcessingInternal(cmdStreamBuf,cmdStreamLen, pPayload, payloadLen, numRemainSegs));
}

FETCH_CMD_STREAM FetchCmdStream = NULL;

void bindFetchCmdStream(FETCH_CMD_STREAM fp)
{
    FetchCmdStream = fp;
}

A_BOOL tlvParser(A_UINT8 *buf)
{
    A_UINT32 cmdStreamLen;
    A_UINT8 *pCmdStream;  // 10312010 untested
    A_UINT8 *pPayload;
    A_UINT16 payloadLen;

    if (FetchCmdStream != NULL) {
        (FetchCmdStream)(buf, &pCmdStream, &cmdStreamLen);

        if (cmdStreamLen) {
            // parse the cmd stream by calling the standard parsingAnd Processing function
            cmdStreamParsingAndProcessing(pCmdStream, cmdStreamLen, &pPayload, &payloadLen);
        }

    }

    return(0);
}

void fakeFetchCmdStream(A_UINT8 *buf, A_UINT8 **pCmdStream, A_UINT32 *cmdStreamLen)
{
    TESTFLOW_CMD_STREAM_V2 *cmdStream;
    *pCmdStream = buf;
    // get the length 
    cmdStream = (TESTFLOW_CMD_STREAM_V2 *)buf;
    *cmdStreamLen = sizeof(TESTFLOW_CMD_STREAM_HEADER_V2) + cmdStream->cmdStreamHeader.length;
}


