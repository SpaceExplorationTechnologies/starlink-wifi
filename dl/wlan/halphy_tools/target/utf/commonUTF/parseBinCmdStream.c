#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#if defined(_HOST_SIM_TESTING)
#include "otaHostCommon.h"
#else
#include "osapi.h"
#endif
#include "wlantype.h"
#include "cmdStream.h"
#include "parmBinTemplate.h"
#include "parseBinCmdStream.h"
#include "testUtil.h"
//#include "cmdOpcodes.h"
#include "cmdStream.h"
#include "cmdAllParms.h"
#include "cmdProcessingSM.h"
//#include "cmdRspParmsInternal.h"
#include "tlvCmdRspInternal.h"
#include "tlvCmdRsp.h"
#include "codeswap_api.h"

SRAM_DATA
_PARSED_BIN_CMD_STREAM_INFO CmdStreamInfo;

#if defined(_FOR_HOST_TESTING)
char dbgFile[KEY_SIZE_MAX];
FILE *fpDbg;
#endif

#if defined(_DEBUG)
#define _STATIC
#else
#define _STATIC static
#endif
#if defined(_DEBUG)
_STATIC void prtCmdQueue(_PARSED_BIN_CMD_STREAM_INFO *pCmdQ)
{
#if 0
    A_UINT8 qPos=0;
    //A_PRINTF("hd %x hdDep %x numCmd %d hdExt %x ", pCmdQ->header, pCmdQ->headerDepValue, pCmdQ->numOfCmds, pCmdQ->headerExtended);
    A_PRINTF("hd %x numCmd %d hdExt %x ", pCmdQ->header, pCmdQ->numOfCmds, pCmdQ->headerExtended);
    A_PRINTF("cQB %d cQE %d dQB %d dQE %d\n", pCmdQ->curQBegin, pCmdQ->curQEnd, pCmdQ->doneQBegin, pCmdQ->doneQEnd);
    A_PRINTF("cQ: ");
    for (qPos = pCmdQ->curQBegin;qPos < pCmdQ->curQEnd; qPos++) {
        A_PRINTF(" op %d nP %d ", pCmdQ->curCmdQueue[qPos].opCode, pCmdQ->curCmdQueue[qPos].numOfParms);
    }
    A_PRINTF("\n");
    A_PRINTF("dQ: ");
    for (qPos = pCmdQ->doneQBegin;qPos < pCmdQ->doneQEnd; qPos++) {
        A_PRINTF(" op %d nP %d ", pCmdQ->doneCmdQueue[qPos].opCode, pCmdQ->doneCmdQueue[qPos].numOfParms);
    }
    A_PRINTF("\n");
#endif
}

#if 0
_STATIC void prtCmdStream1(A_UINT8 *stream, A_UINT32 streamLen)
{
    int i,num=0;
    A_PRINTF_ALWAYS("..stream: \n");
    for (i=0;i<streamLen;i++) {
        A_PRINTF_ALWAYS("%x ", stream[i]);
        num++;
        if (!(num % 16)) A_PRINTF_ALWAYS("\n");
    }
    A_PRINTF_ALWAYS("\n");
#if defined(_FOR_HOST_TESTING)
    if( (fpDbg = fopen( dbgFile, "w")) == NULL ) {
        printf("Failed to open %s \n", dbgFile);
        return(FALSE);
    }
    fprintf(fpDbg, "..stream: ");
    for (i=0;i<streamLen;i++) {
        fprintf(fpDbg, "%x ", stream[i]);
    }
    fprintf(fpDbg, "\n");

#endif
    return;
}
#endif
#endif

#if defined(_FOR_HOST_TESTING)
extern A_BOOL parseCmdParms(_CMD_OPCODES opCode, A_UINT8 *cmdParmBuf, A_UINT8 numOfParms);
extern A_BOOL startParseCmdStream(A_UINT8 header, A_UINT16 headerDepValue, A_UINT32 headerExtended);
#endif

//SRAM_TEXT
//static A_BOOL binCmdStreamParser_Ver1(A_UINT8 *stream, A_UINT32 readStreamLen, A_UINT8 **pPayload, A_UINT16 *payloadLen, A_UINT8 *numRemainSegs)
CODESWAP_MARK_EVICTABLE(A_BOOL, binCmdStreamParser_Ver1,A_UINT8 *stream, A_UINT32 readStreamLen, A_UINT8 **pPayload, A_UINT16 *payloadLen, A_UINT8 *numRemainSegs)
{
    A_BOOL rc=TRUE;
    A_UINT16 *pHalf=(A_UINT16*)stream;
    _TESTFLOW_CMD_STREAM *cmdStream;
    A_UINT16 streamLen;
    A_UINT16 payloadPos, cmdIdx;
    A_UINT8 *payload;
    _ONE_CMD_HEADER *oneCmdHeader;
    _CMD_QUEUE *curCmdQ;

    //prtCmdStream1(stream, readStreamLen);

    // checkSum verification
    cmdStream=(_TESTFLOW_CMD_STREAM *)stream;
    streamLen = sizeof(_TESTFLOW_CMD_STREAM_HEADER) + cmdStream->cmdStreamHeader.length;
    if (readStreamLen != streamLen) {
        //_printf("Incorrect stream length %d, should be %d\n", readStreamLen, streamLen);
        return(FALSE);
    }

    if (!verifyChecksum(pHalf, streamLen/2)) {
        A_PRINTF("Incorrect checksum\n");
        return(FALSE);
    }

    // bypass cmd processing for legacy suport, e.g. ART
    if (( cmdStream->cmdStreamHeader.header & CMD_STERAM_HEADER_EXTENDED_RESERVED) &&
        ( cmdStream->cmdStreamHeader.headerExtended & CMD_STREAM_HEADER_EXTENDED_BYTESTREAM_BYPASS)) {
        *pPayload = cmdStream->payload;
        *payloadLen = cmdStream->cmdStreamHeader.length;
        return(TRUE);
#if 0
        if (HostIF.pBypassCmdStreamParser) {
            rc = (HostIF.pBypassCmdStreamParser)();
            if (!rc) return(rc);
        }
        else {
            //_printf("byteBypass func missing\n");
            return(FALSE);
        }
#endif
    }

    // normal processing ...
    // store header info, for now only repeated testing control
    memset((void*)&CmdStreamInfo, 0, sizeof(CmdStreamInfo));
    CmdStreamInfo.header = cmdStream->cmdStreamHeader.header;
    CmdStreamInfo.headerDepValue = cmdStream->cmdStreamHeader.headerDepValue;
    CmdStreamInfo.headerExtended = cmdStream->cmdStreamHeader.headerExtended;

#if defined(_FOR_HOST_TESTING)
    startParseCmdStream((A_UINT8) cmdStream->cmdStreamHeader.header,
        (A_UINT16)cmdStream->cmdStreamHeader.headerDepValue,
        (A_UINT32)cmdStream->cmdStreamHeader.headerExtended);
#endif

    // parse cmd payload, based on cmd opcode, numOfParms, cmdParmsBinTemplate.c, and total length
    // output: fill cmd queue
    *payloadLen = (A_UINT16)(cmdStream->cmdStreamHeader.length);
    cmdIdx= CmdStreamInfo.curQEnd;
    payload = cmdStream->payload;
    payloadPos =0;
    while ((payloadPos +1) < *payloadLen) {
        oneCmdHeader = (_ONE_CMD_HEADER*)&(payload[payloadPos]);
        curCmdQ = &(CmdStreamInfo.curCmdQueue[cmdIdx]);
        curCmdQ->opCode = oneCmdHeader->opCode;
        curCmdQ->numOfParms = oneCmdHeader->numOfParms;
        /* Check numOfParms to avoid BSOD */
        if (curCmdQ->numOfParms <= 0)
            break;
        payloadPos += sizeof(_ONE_CMD_HEADER);
        curCmdQ->cmdParmBuf = &(payload[payloadPos]);   // rely on CmdStreamBuf, global

#if defined(_FOR_HOST_TESTING)
        parseCmdParms(oneCmdHeader->opCode, curCmdQ->cmdParmBuf, (A_UINT8) oneCmdHeader->numOfParms);
#endif

        cmdIdx++;
        if (!(cmdIdx - CmdStreamInfo.curQBegin)) {
            //_printf("cmd queue end %d caught up with begin %d, overflow queue size %d\n", cmdIdx, CmdStreamInfo.curQBegin, CMD_QUEUE_MAX);
            cmdIdx--;
        }
        payloadPos += curCmdQ->numOfParms * sizeof(_PARM_ONEOF);
    }
    CmdStreamInfo.numOfCmds  = (A_UINT8)(cmdIdx);
    CmdStreamInfo.curQEnd    = cmdIdx;

#if defined(_DEBUG)
    prtCmdQueue(&CmdStreamInfo);
#endif // #if defined(_DEBUG)

    return(rc);
}
CODESWAP_DEFINE_WRAPPER_NONVOIDRET(CODESWAP_ARENA_IRAM, A_BOOL, binCmdStreamParser_Ver1, A_UINT8 *, A_UINT32 , A_UINT8 **, A_UINT16 *, A_UINT8 *);
extern A_BOOL binCmdStreamParser_Ver1(A_UINT8 *stream, A_UINT32 readStreamLen, A_UINT8 **pPayload, A_UINT16 *payloadLen, A_UINT8 *numRemainSegs);
#if 0
//typedef A_BOOL (*pBinCmdStreamParser)(A_UINT8 *stream, A_UINT32 readStreamLen, A_UINT8 **pPayload, A_UINT16 *payloadLen);
extern pBinCmdStreamParser binCmdStreamParser[];
pBinCmdStreamParser binCmdStreamParser[] = {
    NULL,                         // version 0, not used, 0 is difficult to tell
    binCmdStreamParser_Ver1,      // version 1
};

SRAM_TEXT
A_BOOL parseBinCmdStream(A_UINT8 *stream, A_UINT32 readStreamLen, A_UINT8 **pPayload, A_UINT16 *payloadLen)
{
    A_BOOL rc=TRUE;
    _TESTFLOW_CMD_STREAM_HEADER *pCmdStreamHeader = (_TESTFLOW_CMD_STREAM_HEADER *)&(stream[0]);

    // check the binary cmd stream version
    if (pCmdStreamHeader->version > CMD_STREAM_VER_LATEST) {
        //_printf("unsupported cmd stream version %d\n", pCmdStreamHeader->version);
        return(FALSE);
    }

    if (NULL != binCmdStreamParser[pCmdStreamHeader->version]) {
        rc = (binCmdStreamParser[pCmdStreamHeader->version])(stream, readStreamLen, pPayload, payloadLen);
    }

    return(rc);
}
#endif

#if defined(_FOR_HOST_TESTING)
static A_UINT8 CmdStreamBuf[CMD_PAYLOAD_LEN_MAX];
A_BOOL readBinStreamFile(char *fileName, A_UINT8 **pReadCmdStream, A_UINT32 *readStreamLen)
{
    A_BOOL rc=FALSE;
    A_UINT32 numBytes;
    FILE *fp;

    *readStreamLen=0;
    //_printf("readBinStreamFile %s\n",fileName);
    if( (fp = fopen(fileName, "rb")) == NULL) {
        //_printf("Could not open %s to read\n", fileName);
        return FALSE;
    }

    //numBytes = fread((A_UINT8 *)&CmdStreamBuf[0], 1, CMD_PAYLOAD_LEN_MAX, fp);
    numBytes = fread((A_UINT8 *)CmdStreamBuf, 1, sizeof(CmdStreamBuf), fp);
    //_printf("Read %d from %s\n", numBytes, fileName);
    if (feof(fp)) {
        //_printf("Reached eof, read %d from %s\n", numBytes, fileName);
        rc = TRUE;
    }
    else if (ferror(fp)) {
        //_printf("Error reading %s\n", fileName);
        rc = FALSE;
    }
    else { /*_printf("Unknown fread rc\n"); */rc = FALSE; }

    if (fp) fclose(fp);
    if (rc) {
        *readStreamLen = numBytes;
        *pReadCmdStream = &CmdStreamBuf[0];
    }
    return(rc);
}
#endif //#if defined(_FOR_HOST_TESTING)

#define _PARSER_BIN_CMD_STREAM_API_ONLY
#if !defined(_PARSER_BIN_CMD_STREAM_API_ONLY)
int main(int argc, char *argv[])
{
    A_UINT32 readStreamLen;
    A_UINT16 payloadLen;
    A_UINT8  *pReadCmdStream, *pPayload;

    if (2 != argc) {
        printf("Usage: parseBinCmdStrea <bin test steam file>\n");
        return(0);
    }

    sprintf(dbgFile, "dbg_%s.txt", argv[1]);

    if (!readBinStreamFile(argv[1], &pReadCmdStream, &readStreamLen)) {
        printf("Error reading cmd bin %s\n", argv[1]);
        return(-1);
    }

    if (!parseBinCmdStream((A_UINT8 *)pReadCmdStream, readStreamLen, &pPayload, &payloadLen)) {
        printf("Error parsing cmd stream\n");
        return(-1);
    }

    if (fpDbg) fclose(fpDbg);

    return(0);
}
#endif //#if !defined(_PARSER_BIN_CMD_STREAM_API_ONLY)


//
// Exposed API
extern void cmdProcessingEntry(void);
SRAM_TEXT
A_BOOL addTLV1p0BinCmdParser(void)
{
    if (!(bindBinCmdStreamParser(binCmdStreamParser_Ver1, CMD_STREAM_VER1))) {
        return(FALSE);
    }

    if (!(bindBinCmdProcessing(cmdProcessingEntry, CMD_STREAM_VER1))) {
        return(FALSE);
    }

    // no separate cmdProcessing for TLV2p0
    return(TRUE);
}
