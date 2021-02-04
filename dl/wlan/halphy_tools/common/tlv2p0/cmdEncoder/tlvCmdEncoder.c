/*
 *   TLV cmd/rsp encoder
 *   -------------------
 *
 *   APIs:
 *       createCmdRsp()
 *
 *   How to ensure codes are consistent between two entities: random number as semantics code
 *   ----------------------------------------------------------------------------------------
 *
 *   The following command/response, and paramter dictionaries are not required to be
 *   always consistent between two entities.
 *   Though we could use build script to check duplicates, it's not the best guarantee 
 *   in cases the builds come from different branches. We do want to work towards a single
 *   branch, inevitably branching may happen, for example, a customer branch.
 *   
 *   Command/response code in the stream, total 4B
 *       cmdCode(4B)
 *       randomNumber(4B)
 *
 *   Command/Response code dictionary
 *   --------------------------------
 *       Refer to cmdRspParmsDic.h
 *       May later add distinction between FTM and MM exposure, i.e. some only for FTM
 *
 *   Parameter code dictionary 
 *   -------------------------
 *   Parameter codes have scope within a command/response. Across commands/responses, the parameter
 *   codes can be the same.
 *   The same random semantics codes are used to ensure the consistency between two entities.
 *
 *   The parameter code in the stream, total 4B
 *       parmCode(4B)
 *       randomNumber(4B)
 *
 *  The parameter type
 *      Singular vs. array
 *
 *  The basic parameter value type (either singular or array element)
 *      PARM_U32
 *      PARM_U16
 *      PARM_U8
 *      PARM_S32
 *      PARM_S16
 *      PARM_S8
 * 
 * Command/Response format
 * -----------------------
 *
 * The stream header is a shorter version of version 1 (TS), keeping only
 *     commandID and version.
 *
 * Each command/response stream contains ONLY ONE command or response.
 * It's expected that after sending command, it's blocked for response.
 *
 * All parameter values are promoted to A_UINT32 or A_INT32.
 * The parser needs to handle accordingly.
 *
 * Examples of stream
 *     - A single value cmd stream:
 * |cmdID(4B)|version(4B)|cmdCode(4B)|cmdRand(4B)|(parmCode1)(4B)|parmRand1(4B)|parmValue1(4B)|
 * 
 *     - An array value cmd stream:
 * |cmdID(4B)|version(4B)|cmdCode(4B)|cmdRand(4B)|(parmCode1)(4B)|parmRand1(4B)|numElem(4B)|beginPos(4B)|value1(4B)|value2(4B)|...value(numElem-1)(4B)|
 *
 *     Of course, the aggregation of the above two basic examples.
 *
 */

#include <stdarg.h>
#include "tlv2Inc.h"
#include "testcmd.h"
#include "tlvCmdEncoder.h"
#include "testUtil.h"


_STATIC TESTFLOW_CMD_STREAM_V2  CmdStreamV2;
_STATIC A_UINT32 streamPos = 0;
_STATIC A_UINT32 numParmsPos = 0;
_STATIC A_UINT32 numParms = 0;

HALPHY_TOOLS_MEM internalPayload = {NULL, 0, FALSE};
A_UINT8 *pInternalPayload = NULL;
_STATIC A_UINT32 numSegments;
_STATIC A_UINT8 currentSegment;
_STATIC A_UINT32 currentSegIdx;
_STATIC A_UINT32 maxSegmentSize;

#define encode_array(arrayType, dataInStreamType) \
{\
    arrayType *arr = (arrayType *)arrayLoc; \
    dataInStreamType temp; \
    for (i=0;i<numElem;i++) { \
        temp = (dataInStreamType) arr[beginPos++]; \
        memcpy((void*)&(pInternalPayload[streamPos]), (void*)&temp, sizeof(temp)); \
        streamPos +=4; \
    }\
}

#define ENCODE_VAL_UNSIGNED(type) \
{ \
    type temp = va_arg(args, type); \
    numArgs--; \
    memcpy((void*)&(pInternalPayload[streamPos]), (void*)&temp, sizeof(temp)); \
    streamPos +=4; \
}

#ifdef _HOST_SIM_TESTING
static void prtCmdStream(A_UINT8 *stream, A_UINT32 streamLen) 
{
    int i,num=0;
    A_UINT32 *pt32=(A_UINT32 *)stream;
    printf("ver2..stream: ");
    for (i=0;i<(int)streamLen;i+=4) {
        //printf("%d ", stream[i]);
        pt32=(A_UINT32 *)&(stream[i]);
        printf("%d ", (int)(*pt32));
        num++;
        if (!(num % 40)) printf("\n");
    }
    printf("\n");
    return;
}
#endif //_HOST_SIM_TESTING

static A_BOOL tlv2p0Enabled=FALSE;

A_BOOL addTLV2p0Encoder(void) 
{
    tlv2p0Enabled=TRUE;
    return TRUE;
}

TLV2_API int CmdStreamLen()
{
    int t;
    t = CmdStreamV2.cmdStreamHeader.length +  sizeof(TESTFLOW_CMD_STREAM_HEADER_V2);
    return t;
}

TLV_ENCODER_ENUM tlv2CreateCmdHeaderInternal(A_UINT32 maxSegSize, A_UINT32 maxStreamSize, A_UINT32 cmdCode)
{
    CMD_DICT *pCmdDict;
    A_UINT32 cmdIdx, maxCmdNum;

    if (!tlv2p0Enabled) {
        A_PRINTF_ALWAYS("TLV 2.0 encoder not on\n");
        return TLV_ENCODER_NOT_ON;
    }

    if (streamPos != 0)
    {
        A_PRINTF_ALWAYS("A TLV2 command contruction is already in progress.\n");
        return TLV_ENCODER_CONSTRUCTION_IN_PROGRESS;
    }
    if (maxSegSize > sizeof(CmdStreamV2.payload))
    {
        A_PRINTF_ALWAYS("A TLV2 requested segment size is too big.\n");
        return TLV_ENCODER_SEGMENT_SIZE_TOO_BIG;
    }

    if (cmdCode >= SYSCMD_FIRST_IDX)
    {
        cmdIdx = cmdCode - SYSCMD_FIRST_IDX;
        pCmdDict = SysCmdDict;
        maxCmdNum = MaxSysCmdDictEntries;
    }
    else
    {
        cmdIdx = cmdCode;
        pCmdDict = CmdDict;
        maxCmdNum = MaxCmdDictEntries;
    }
    if (cmdIdx >= maxCmdNum)
    {
        A_PRINTF_ALWAYS("cmdCode %d exceeds dict\n", cmdCode);
        return TLV_ENCODER_INVALID_CMD;
    }

    // If maxStreamSize is greater than maxSegSize, the whole stream might be bigger than the size of CmdStreamV2.payload buffer
    // Allocate an internal payload buffer to store the whole stream, then segment the stream, and send one by one until all sent
    if (maxStreamSize > maxSegSize)
    {
        if (halphyToolsMem (&internalPayload, HALPHY_TOOLS_MEM_ALLOC, maxStreamSize) == FALSE)
        {
            return TLV_ENCODER_NO_MEMORY_FOR_EXTENDED;
        }
        pInternalPayload = internalPayload.pBuf;
    }
    // If maxStreamSize is less than or equal to maxSegSize, then just form the stream in CmdStreamV2.payload
    else
    {
        pInternalPayload = CmdStreamV2.payload;
    }

    maxSegmentSize = maxSegSize;

    // Populate header
    memset((void*)&CmdStreamV2.cmdStreamHeader, 0, sizeof(CmdStreamV2.cmdStreamHeader));
    CmdStreamV2.cmdStreamHeader.cmdId   = TC_CMD_TLV_ID;
    CmdStreamV2.cmdStreamHeader.version = CMD_STREAM_VER2;

    // start payload
    streamPos = 0;
    // Add command code
    memcpy((void*)&(pInternalPayload[streamPos]), (void*)&cmdCode, sizeof(cmdCode));
    streamPos +=4;
    memcpy((void*)&(pInternalPayload[streamPos]), (void*)&(pCmdDict[cmdIdx].rand), sizeof(pCmdDict[cmdIdx].rand));
    streamPos +=4;
    numParmsPos = streamPos;
    //memcpy((void*)&(pInternalPayload[streamPos]), (void*)&numOfParms, sizeof(numOfParms));
    streamPos +=4;
    numParms = 0;
    return TLV_ENCODER_OK;
}

TLV2_API void tlv2CreateCmdHeader(A_UINT32 cmdCode)
{
    numSegments = 0;
    currentSegment = 0;
    currentSegIdx = 0;
    tlv2CreateCmdHeaderInternal(MAX_PAYLOAD_LEN, MAX_PAYLOAD_LEN, cmdCode);
}

TLV2_API TLV_ENCODER_ENUM tlv2CreateCmdHeaderExt(A_UINT32 maxSegSize, A_UINT32 maxStreamSize, A_UINT32 cmdCode)
{
    numSegments = 0;
    currentSegment = 0;
    currentSegIdx = 0;
    return (tlv2CreateCmdHeaderInternal(maxSegSize, maxStreamSize, cmdCode));
}

TLV_ENCODER_ENUM tlv2AddParmsInternal(int numArgs, va_list args, A_BOOL ext)
{
    A_UINT32 parmCode;
    PARM_DICT *pParmDict;
    A_UINT32 numElem, beginPos;
    A_UINT32 i;
    A_UINT32 valueType, arrayLoc, binDataLoc;
    A_UINT32 parmIdx, maxParmNum;
    A_UINT32 dataType;
    A_UINT32 maxPayload = ext ? internalPayload.size : sizeof(CmdStreamV2.payload);

    //A_PRINTF ("numArgs %d\n", numArgs);

    while(--numArgs >=0) {
        parmCode = va_arg(args, A_UINT32);
        if (parmCode >= SYSPARM_FIRST_IDX)
        {
            parmIdx = parmCode - SYSPARM_FIRST_IDX;
            maxParmNum = MaxSysParmDictEntries;
            pParmDict = SysParmDict;
        }
        else
        {
            parmIdx = parmCode;
            maxParmNum = MaxParmDictEntries;
            pParmDict = ParmDict;
        }
        if (parmIdx >= maxParmNum) 
        {
            va_end(args);
            A_PRINTF_ALWAYS("parmCode %d exceeds dict\n", parmCode);
            return TLV_ENCODER_INVALID_PARM;
        }

        // go through value(s): singular or array
        valueType = pParmDict[parmIdx].dataType;

        // array
        if (DATATYPE_IS_ARRAY(valueType)) {
            numElem   = va_arg(args, A_UINT32);
            beginPos  = va_arg(args, A_UINT32);
            arrayLoc  = va_arg(args, A_UINT32);
            numArgs -= 3;

            // 4-byte parmCode + 4-byte parmRand + 4-byte numElem + 4-byte beginPos + (4*numElem)-byte array
            if ((streamPos + 16 + numElem * 4) >= maxPayload)
            {
                A_PRINTF("TLV2 buffer overflow\n");
                return TLV_ENCODER_BUFFER_OVERFLOW;
            }
            // encode parmCode and its rand
            memcpy((void*)&(pInternalPayload[streamPos]), (void*)&parmCode, sizeof(parmCode));
            streamPos +=4;
            memcpy((void*)&(pInternalPayload[streamPos]), (void*)&(pParmDict[parmIdx].rand), sizeof(pParmDict[parmIdx].rand));
            streamPos +=4;
            // encode array numElem and beginPos
            memcpy((void*)&(pInternalPayload[streamPos]), (void*)&numElem, sizeof(numElem));
            streamPos +=4;
            memcpy((void*)&(pInternalPayload[streamPos]), (void*)&beginPos, sizeof(beginPos));
            streamPos +=4;
            // encode array elements one by one
            switch (DATATYPE_TYPE(valueType)) {
              #define ENCODE_ARRAY(parmType, dataType) \
                case parmType: \
                    encode_array(dataType, A_UINT32)  \
                    break;
              #include "encodeArray.def"
            }
        }
        else if (DATATYPE_IS_DATA(valueType)) {
            dataType = DATATYPE_TYPE(valueType);
            numElem = (dataType == PARM_DATA_64 ? 64 : 
                      (dataType == PARM_DATA_128 ? 128 :
                      (dataType == PARM_DATA_256 ? 256 :
                      (dataType == PARM_DATA_512 ? 512 :
                      (dataType == PARM_DATA_1024 ? 1024 : 2048)))));

            // 4-byte parmCode + 4-byte parmRand + numElem-byte data
            if ((streamPos + 8 + numElem) >= maxPayload)
            {
                A_PRINTF("TLV2 buffer overflow\n");
                return TLV_ENCODER_BUFFER_OVERFLOW;
            }
            // encode parmCode and its rand
            memcpy((void*)&(pInternalPayload[streamPos]), (void*)&parmCode, sizeof(parmCode));
            streamPos +=4;
            memcpy((void*)&(pInternalPayload[streamPos]), (void*)&(pParmDict[parmIdx].rand), sizeof(pParmDict[parmIdx].rand));
            streamPos +=4;

            // encode binary data block
            binDataLoc = va_arg(args, A_UINT32);
            numArgs--;
            switch (dataType) {
                case PARM_DATA_64:
                    memcpy((void*)&(pInternalPayload[streamPos]), (void*)((A_UINT8 *)binDataLoc), 64);
                    streamPos +=64;
                    break;
                case PARM_DATA_128:
                    memcpy((void*)&(pInternalPayload[streamPos]), (void*)((A_UINT8 *)binDataLoc), 128);
                    streamPos +=128;
                    break;
                case PARM_DATA_256:
                    memcpy((void*)&(pInternalPayload[streamPos]), (void*)((A_UINT8 *)binDataLoc), 256);
                    streamPos +=256;
                    break;
                case PARM_DATA_512:
                    memcpy((void*)&(pInternalPayload[streamPos]), (void*)((A_UINT8 *)binDataLoc), 512);
                    streamPos +=512;
                    break;
                case PARM_DATA_1024:
                    memcpy((void*)&(pInternalPayload[streamPos]), (void*)((A_UINT8 *)binDataLoc), 1024);
                    streamPos +=1024;
                    break;
                default:
                    break;
            }
        }
        // singular
        else {
            // 4-byte parmCode + 4-byte parmRand + 4-byte value
            if ((streamPos + 12) >= maxPayload)
            {
                A_PRINTF("TLV2 buffer overflow\n");
                return TLV_ENCODER_BUFFER_OVERFLOW;
            }
            // encode parmCode and its rand
            memcpy((void*)&(pInternalPayload[streamPos]), (void*)&parmCode, sizeof(parmCode));
            streamPos +=4;
            memcpy((void*)&(pInternalPayload[streamPos]), (void*)&(pParmDict[parmIdx].rand), sizeof(pParmDict[parmIdx].rand));
            streamPos +=4;

            switch (DATATYPE_TYPE(valueType)) {
                case PARM_U32:
                case PARM_U16:
                case PARM_U8:
                    // all unsigned types are promoted to A_UINT32, parser needs to convert correctly
                    ENCODE_VAL_UNSIGNED(A_UINT32)
                    break;
                case PARM_S32:
                case PARM_S16:
                case PARM_S8:
                    // all signed types are promoted to A_INT32, parser needs to convert correctly
                    ENCODE_VAL_UNSIGNED(A_INT32)
                    break;
            }
        }
        numParms++;
    }
    numSegments = streamPos / maxSegmentSize;
    if (streamPos % maxSegmentSize)
    {
        numSegments++;
    }
    return TLV_ENCODER_OK;
}

TLV2_API void tlv2AddParms(int numArgs, ...)
{
    va_list args;

    if (!tlv2p0Enabled) {
        A_PRINTF_ALWAYS("TLV 2.0 encoder not on\n");
        return;
    }
    if (streamPos == 0)
    {
    	A_PRINTF_ALWAYS("No TLV2 command has been constructed.\n");
    	return;
    }

    va_start(args, numArgs);
    tlv2AddParmsInternal(numArgs, args, FALSE);

    va_end(args);
}

TLV2_API TLV_ENCODER_ENUM tlv2AddParmsExt(int numArgs, ...)
{
    va_list args;
    TLV_ENCODER_ENUM retVal;

    if (!tlv2p0Enabled) {
        A_PRINTF_ALWAYS("TLV 2.0 encoder not on\n");
        return TLV_ENCODER_NOT_ON;
    }
    if (streamPos == 0)
    {
    	A_PRINTF_ALWAYS("No TLV2 command has been constructed.\n");
    	return TLV_ENCODER_CONSTRUCTION_IN_PROGRESS;
    }

    va_start(args, numArgs);
    retVal = tlv2AddParmsInternal(numArgs, args, TRUE);

    va_end(args);
    return retVal;
}

TLV2_API TESTFLOW_CMD_STREAM_V2 *tlv2CompleteCmdRspSegment(A_UINT16 *streamLen)
{
    A_UINT16 sum;
    A_UINT16 segmentLen;

    if (!tlv2p0Enabled) {
        A_PRINTF_ALWAYS("TLV 2.0 encoder not on\n");
        return(NULL);
    }
    if (streamPos == 0)
    {
    	A_PRINTF_ALWAYS("No TLV2 command has been constructed.\n");
    	return (NULL);
    }
    // add payload length
    CmdStreamV2.cmdStreamHeader.length = streamPos;

    // last segment
    if (currentSegment == (numSegments - 1)) 
    {
        segmentLen = (A_UINT16)(streamPos - currentSegIdx);
    }
    else
    {
        segmentLen = (A_UINT16)maxSegmentSize;
    }

    // set segment flags
    if (numSegments > 1)
    {
        CmdStreamV2.cmdStreamHeader.header |= CMD_STREAM_HEADER_EXTENDED_SEGMENT;
        CmdStreamV2.cmdStreamHeader.headerExtended = ((currentSegment << CMD_STREAM_HEADER_EXTENDED_SEGMENT_NUM_SHIFT) & CMD_STREAM_HEADER_EXTENDED_SEGMENT_NUM_MASK) |
                        ((numSegments << CMD_STREAM_HEADER_EXTENDED_TOTAL_SEGMENTS_SHIFT) & CMD_STREAM_HEADER_EXTENDED_TOTAL_SEGMENTS_MASK) |
                        ((segmentLen << CMD_STREAM_HEADER_EXTENDED_SEGMENT_LENGTH_SHIFT) & CMD_STREAM_HEADER_EXTENDED_SEGMENT_LENGTH_MASK);
    }
    
    // Copy to CmdStreamV2.payload only if pInternalPayload is dynamic allocated (ext is set)
    if (pInternalPayload != CmdStreamV2.payload)
    {
        memcpy(&CmdStreamV2.payload[0], &pInternalPayload[currentSegIdx], segmentLen);
    }

    if (currentSegment == 0)
    {
        // add numParms back to a location after cmdCode
        memcpy((void*)&(CmdStreamV2.payload[numParmsPos]), (void*)&numParms, sizeof(numParms));

        // Debug - print the TLV stream
        //A_PRINTF("cmdCode %d stream length %d segmentLen %d\n", *((A_UINT32 *)CmdStreamV2.payload), streamPos, segmentLen);
    }
    // Compute checksum
    sum = computeChecksumOnly((A_UINT16*)&CmdStreamV2, (A_UINT16)(sizeof(_TESTFLOW_CMD_STREAM_HEADER)+segmentLen)/2);
    CmdStreamV2.cmdStreamHeader.checkSum = 0xFFFF ^ sum;

#if 0
    for (i=0;i<*segmentLen;i++) {
        if ((i % 16) == 0) printf("\n");
        A_PRINTF_ALWAYS("%02x ", CmdStreamV2.payload[i]);
    }
    A_PRINTF_ALWAYS("\n");
    // end Debug
#endif //0

    currentSegIdx += segmentLen;

    //A_PRINTF ("currentSegment %u, numSegments %u\n", currentSegment, numSegments);
    if (++currentSegment == numSegments)
    {
        streamPos = 0;
        numParmsPos = 0;
        numParms = 0;
        halphyToolsMem(&internalPayload, HALPHY_TOOLS_MEM_FREE, 0);
    }
    *streamLen = segmentLen + sizeof(_TESTFLOW_CMD_STREAM_HEADER);
    return(&CmdStreamV2);
}

TLV2_API TESTFLOW_CMD_STREAM_V2 *tlv2CompleteCmdRsp()
{
    A_UINT16 streamLen;

    return(tlv2CompleteCmdRspSegment(&streamLen));
}

TLV2_API TESTFLOW_CMD_STREAM_V2 *createCmdRsp(A_UINT32 cmdCode, int numArgs, ...)
{
    va_list args_read;
    va_list args;
    TLV_ENCODER_ENUM error;
    A_UINT16 streamLen;

    numSegments = 0;
    currentSegment = 0;
    currentSegIdx = 0;

    if (TLV_ENCODER_OK != tlv2CreateCmdHeaderInternal(MAX_PAYLOAD_LEN, MAX_PAYLOAD_LEN, cmdCode))
    {
        return NULL;
    }

    // Add parameters one at a time
    if (numArgs < 0)
    {
        numArgs = 2;
        va_start(args_read, numArgs);
        numArgs = -va_arg(args_read, A_UINT32);
        args = va_arg(args_read, va_list);
        //A_PRINTF_ALWAYS("encoder, numArgs=%d\n", numArgs);
    }
    else
    {
        va_start(args, numArgs);
    }

    error = tlv2AddParmsInternal(numArgs, args, FALSE);
    va_end(args);

    if (TLV_ENCODER_OK != error)
    {
        streamPos = 0;
        numParmsPos = 0;
        numParms = 0;
        return NULL;
    }
    return(tlv2CompleteCmdRspSegment(&streamLen));
}

// return number of TLV2 stream segments
TLV2_API A_UINT32 createCmdRspExt(A_UINT32 maxSegSize, A_UINT32 maxStreamSize, A_UINT32 cmdCode, int numArgs, ...)
{
    va_list args_read;
    va_list args;
    TLV_ENCODER_ENUM error;

    numSegments = 0;
    currentSegment = 0;
    currentSegIdx = 0;

    if (TLV_ENCODER_OK != tlv2CreateCmdHeaderInternal(maxSegSize, maxStreamSize, cmdCode))
    {
        return 0;
    }

    // Add parameters one at a time
    if (numArgs < 0)
    {
        numArgs = 2;
        va_start(args_read, numArgs);
        numArgs = -va_arg(args_read, A_UINT32);
        args = va_arg(args_read, va_list);
        //A_PRINTF_ALWAYS("encoder, numArgs=%d\n", numArgs);
    }
    else
    {
        va_start(args, numArgs);
    }

    error = tlv2AddParmsInternal(numArgs, args, TRUE);
    va_end(args);

    if (TLV_ENCODER_OK != error)
    {
        streamPos = 0;
        numParmsPos = 0;
        numParms = 0;
    }
    return ((TLV_ENCODER_OK != error) ? 0 : numSegments);
}

TLV2_API TESTFLOW_CMD_STREAM_V2 *tlvGetNextStream(A_UINT32 *streamLen)
{
    TESTFLOW_CMD_STREAM_V2 *pStream;

    pStream = tlv2CompleteCmdRspSegment((A_UINT16 *)streamLen);
    return (pStream);
}
