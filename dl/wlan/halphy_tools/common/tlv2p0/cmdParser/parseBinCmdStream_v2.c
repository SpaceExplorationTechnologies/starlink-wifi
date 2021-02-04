
#include "commonInc.h"
#include "cmdStream.h"
#include "tlv2Inc.h"
#include "parseBinCmdStream.h"
#include "tlvCmdRspInternal.h"
#include "tlvCmdRsp.h"
#include "cmdHandlers.h"
#include "testUtil.h"

void * pParamPtr_ch = NULL;
HALPHY_TOOLS_MEM internalRcvPayload = {NULL, 0, FALSE};

#if defined(_DEBUG_TLV2)
_STATIC void prtCmdStream(A_UINT8 *stream, A_UINT32 streamLen) 
{
    A_UINT32 i,num=0;
    A_UINT32 *pt32=(A_UINT32 *)stream;
    A_PRINTF_ALWAYS("ver2..stream: ");
    for (i=0;i<streamLen;i+=4) {
        //printf("%d ", stream[i]);
        pt32=(A_UINT32 *)&(stream[i]);
        A_PRINTF_ALWAYS("%d ", (int)(*pt32));
        num++;
        if (!(num % 8)) A_PRINTF_ALWAYS("\n");
    }
    A_PRINTF_ALWAYS("\n");
    return;
}
#else
#define prtCmdStream(x,y)
#endif

#define copyArray(type)       \
{                             \
    type temp;                \
    for (i=0;i<numElem;i++) { \
        temp = (type) payload[payloadPos++]; \
        memcpy((void*)(((type *)((char*)(*pParmStruct)+offset)) +beginPos +i), (void*)&temp, sizeof(temp)); \
    } \
}

#define copyValue(type) \
{ \
    type temp=(type)value; \
    memcpy((void*)((char*)(*pParmStruct)+offset), (void*)&temp, sizeof(temp)); \
}

#if 0
#define copyBinData(type, len) \
{  \
    A_UINT8 *binData = (A_UINT8 *)&(payload[payloadPos]); 
    
    memcpy((void*)((A_UINT8 *)(*pParmStruct)+offset), (void*)binData, len); 
    payloadPos += (len/4);
#endif

// Note:
//   Both the parm struct and parm offset tbl need to be built for every cmd during run time
// Area to create a cmd specific parm struct
static CMD_ALL_PARMS ParmsCommon;

// Indexed by parm key hash, stores parmCode and offset within the parm struct
static PARM_OFFSET_TBL ParmsOffset[KEY_HASH_RANGE];

A_BOOL getCmdDicHandlerTblPtrs(A_UINT32 cmdCode, A_UINT32 *cmdIdx, CMD_DICT **pCmdDict, CMD_HANDLER_ENTRY **pCmdHandlerTbl, A_UINT32 *maxParm)
{
    A_UINT32 maxCmdNum, maxCmdHandlerNum;

    if (cmdCode >= SYSCMD_FIRST_IDX)
    {
        *cmdIdx = cmdCode - SYSCMD_FIRST_IDX;
        *pCmdDict = SysCmdDict;
        *pCmdHandlerTbl = SysCmdHandlerTbl;
        maxCmdNum = MaxSysCmdDictEntries;
        maxCmdHandlerNum = MaxSysCmdHandlers;
        *maxParm = SYSPARM_MAX;
    }
    else
    {
        *cmdIdx = cmdCode;
        *pCmdDict = CmdDict;
        *pCmdHandlerTbl = CmdHandlerTbl;
        maxCmdNum = MaxCmdDictEntries;
        maxCmdHandlerNum = MaxCmdHandlers;
        *maxParm = PARM_MAX;
    }
    if (*cmdIdx >= maxCmdNum) 
    {
        A_PRINTF_ALWAYS("cmdCode %d > dict\n", cmdCode);
        return FALSE;
    }
    if (*cmdIdx >= maxCmdHandlerNum)
    { 
        A_PRINTF_ALWAYS("cmdCode %d > handlers\n", cmdCode);
        return FALSE; 
    }
    return TRUE;
}

// TLV2p0 parser
A_BOOL parmParser2p0(A_UINT32 cmdCode, A_UINT32 numParms, A_UINT32 *payload, void **pParmStruct) 
{
    A_BOOL rc=TRUE;
    A_UINT32 payloadPos;
    A_UINT32 parmCode, semCode;
    //A_UINT32 dataType; 
    A_BOOL   offsetValid;
    A_UINT8  keyHash;
    PARM_OFFSET_FIELDS *pParmOffsetFields; 
    A_UINT32 offset;
    A_UINT32 numElem, beginPos;
    A_UINT32 value;
    A_UINT32 numParmsParsed;
    A_UINT32 i;
    A_UINT32 cmdIdx, parmIdx, maxParm;
    CMD_DICT *pCmdDict;
    CMD_HANDLER_ENTRY *pCmdHandlerTbl;
    PARM_DICT *pParmDict;

    // after header, it's the 4B cmdCode and randNum

    memset((void*)&ParmsCommon, 0, sizeof(ParmsCommon));
    memset((void*)ParmsOffset, 0, sizeof(ParmsOffset));
    //A_PRINTF_ALWAYS("pOfSt %d, %d\n", sizeof(ParmsOffset), (int)ParmsOffset[2].pt);
    //A_PRINTF_ALWAYS("cmdCode %d\n", cmdCode);

    if (getCmdDicHandlerTblPtrs(cmdCode, &cmdIdx, &pCmdDict, &pCmdHandlerTbl, &maxParm) == FALSE)
    {
        return FALSE;
    }
    pParmDict = (cmdCode >= SYSCMD_FIRST_IDX) ? SysParmDict : ParmDict;

    if (NULL != pCmdHandlerTbl[cmdIdx].initParms ) {
        *pParmStruct = (pCmdHandlerTbl[cmdIdx].initParms)((A_UINT8 *)&ParmsCommon, &(ParmsOffset[0]), pParmDict);
    }
    else { A_PRINTF_ALWAYS("Null initParms\n"); return(FALSE);}

    if (NULL == *pParmStruct) {
    	if (numParms == 0)
    		return(TRUE);
    	else{
			A_PRINTF_ALWAYS("cannot build parm struct\n");
			return(FALSE);
    	}
    }
    numParmsParsed =0;
    payloadPos=0;
    while (numParmsParsed < numParms) {
        parmCode    = payload[payloadPos++];
        semCode     = payload[payloadPos++]; 
        parmIdx     = (parmCode > SYSPARM_FIRST_IDX) ? (parmCode - SYSPARM_FIRST_IDX) : parmCode;
        numParmsParsed++;
        //A_PRINTF_ALWAYS("parmCode %d semCode %d\n", (int)parmCode, (int)semCode);

        if (!(parmCode < maxParm)) { A_PRINTF_ALWAYS("parmCode %d exceeds dict, dropped\n", (int)parmCode); continue; }
        if (semCode != pParmDict[parmIdx].rand) { A_PRINTF_ALWAYS("parmRand mismatch %d %d %d, dropped\n", (int)parmCode, (int)semCode, (int)pParmDict[parmIdx].rand); continue; }

        keyHash = pParmDict[parmIdx].keyHash;
        pParmOffsetFields = ParmsOffset[keyHash].pt;
        offsetValid=FALSE;
        while (NULL != pParmOffsetFields) {
            if (pParmOffsetFields->parmCode == parmCode){
                offset = pParmOffsetFields->offset;
                offsetValid = TRUE;
                break;
            }
            else {
                pParmOffsetFields = pParmOffsetFields->next;
            }
        }

        //A_PRINTF_ALWAYS("parser, parmCode(%d of %d) = %d\n", numParmsParsed, numParms, parmCode);
        if (!offsetValid) { A_PRINTF_ALWAYS("parmCode %d not in offset table, dropped\n", (int)parmCode); continue; }

        if (DATATYPE_IS_ARRAY(pParmDict[parmIdx].dataType)) {
            // array
            numElem  = payload[payloadPos++];
            beginPos = payload[payloadPos++]; 
            switch (DATATYPE_TYPE(pParmDict[parmIdx].dataType)) {
                #define COPY_ARRAY(parmType, dataType) \
                    case parmType:  \
                        copyArray(dataType)  \
                        break;
                #include "copyArray.def" 
            }
        }
        else if (DATATYPE_IS_DATA(pParmDict[parmIdx].dataType)) {
            // binary data 
            A_UINT8 *binData;
            switch (DATATYPE_TYPE(pParmDict[parmIdx].dataType)) {
#if 0
                #define COPY_BINDATA(parmType, dataType) \
                    case parmType: \
                        copyBinData(dataType)  \
                        break;
                #include "copyBinData.def"
#endif
                case PARM_DATA_64:
                    binData = (A_UINT8 *)&(payload[payloadPos]); 
                    memcpy((void*)((A_UINT8 *)(*pParmStruct)+offset), (void*)binData, 64); 
                    payloadPos += (64/4);
                    break;
                case PARM_DATA_128:
                    binData = (A_UINT8 *)&(payload[payloadPos]); 
                    memcpy((void*)((A_UINT8 *)(*pParmStruct)+offset), (void*)binData, 128); 
                    payloadPos += (128/4);
                    break;
                case PARM_DATA_256:
                    binData = (A_UINT8 *)&(payload[payloadPos]); 
                    memcpy((void*)((A_UINT8 *)(*pParmStruct)+offset), (void*)binData, 256); 
                    payloadPos += (256/4);
                    break;
                case PARM_DATA_512:
                    binData = (A_UINT8 *)&(payload[payloadPos]); 
                    memcpy((void*)((A_UINT8 *)(*pParmStruct)+offset), (void*)binData, 512); 
                    payloadPos += (512/4);
                    break;
                case PARM_DATA_1024:
                    binData = (A_UINT8 *)&(payload[payloadPos]);
                    memcpy((void*)((A_UINT8 *)(*pParmStruct)+offset), (void*)binData, 1024); 
                    payloadPos += (1024/4);
                    break;
                default:
                    break;
            }
        }
        else {
            // singular value
            value = payload[payloadPos++]; 
            // convert to proper size, from 4B
            // overwrite the parm structure corresponding field
            switch (DATATYPE_TYPE(pParmDict[parmIdx].dataType)) {
                #define COPY_VALUE(parmType, dataType) \
                    case parmType:  \
                        copyValue(dataType)  \
                        break;
                #include "copyValue.def" 
            }
        }
    }
    //A_PRINTF_ALWAYS("d parmP %d %d\n", numParmsParsed, numParms);
    return(rc);
}

typedef enum {
    RSP_RESERVED=0,
    RSP_POSITIVE,
    RSP_NEGATIVE,
} RSP_TYPE;

typedef struct platformSpecificStuff {
    A_BOOL (*sendGenericRsp)(A_UINT32 cmdCode, void* pParmStruct, RSP_TYPE rsp); 
} PLATFORM_SPECIFIC;

static PLATFORM_SPECIFIC PlatformSpecific = {
    NULL,
};



TLV2_API void * getRspPtr()
{
    // wait till response  ---replyReceived
    void * temp;
    temp = pParamPtr_ch;
    pParamPtr_ch = NULL;
    return temp;
}


// The simple one cmd one rsp parser
static A_BOOL binCmdStreamParserVer2(A_UINT8 *stream, A_UINT32 readStreamLen, A_UINT8 **pPayload, A_UINT16 *payloadLen, A_UINT8 *numRemainSegs)
{
    A_BOOL rc=TRUE;
    TESTFLOW_CMD_STREAM_V2 *cmdStream;
    A_UINT32 payloadPos;
    A_UINT32 *payload ;
    void *pParmStruct; 
    A_UINT32 semCode, maxParm;
    _STATIC A_UINT32 *parmPayload;
    _STATIC A_UINT32 numParms;
    _STATIC CMD_DICT  *pCmdDict;
    _STATIC A_UINT32 cmdCode, cmdIdx;
    _STATIC CMD_HANDLER_ENTRY *pCmdHandlerTbl;
    _STATIC A_UINT32 expectedSegment = 0;
    _STATIC A_UINT32 expectedLen = 0;
    _STATIC A_UINT32 currentSegIdx = 0;
    A_UINT8 currentSegment;
    A_UINT8 numSegments;
    A_UINT16 segmentLen;
    A_BOOL segmented;
    CMD_MORESEGMENT_PARMS cmdMoreSegment;
 
    prtCmdStream(stream, readStreamLen);

    cmdStream=(TESTFLOW_CMD_STREAM_V2 *)stream;

    *payloadLen = (A_UINT16)(readStreamLen - sizeof(TESTFLOW_CMD_STREAM_HEADER_V2));

    segmented = (cmdStream->cmdStreamHeader.header & CMD_STREAM_HEADER_EXTENDED_SEGMENT) ? TRUE : FALSE;

    if (segmented)
    {
        numSegments = (cmdStream->cmdStreamHeader.headerExtended & CMD_STREAM_HEADER_EXTENDED_TOTAL_SEGMENTS_MASK) >>
                        CMD_STREAM_HEADER_EXTENDED_TOTAL_SEGMENTS_SHIFT;
        currentSegment = (cmdStream->cmdStreamHeader.headerExtended & CMD_STREAM_HEADER_EXTENDED_SEGMENT_NUM_MASK) >>
                        CMD_STREAM_HEADER_EXTENDED_SEGMENT_NUM_SHIFT;
        segmentLen = (cmdStream->cmdStreamHeader.headerExtended & CMD_STREAM_HEADER_EXTENDED_SEGMENT_LENGTH_MASK) >>
                        CMD_STREAM_HEADER_EXTENDED_SEGMENT_LENGTH_SHIFT;

        if ((expectedSegment != currentSegment) || (currentSegment >= numSegments))
        {
            A_PRINTF_ALWAYS("conflict in headerExtended, numSegments %u, currentSegment %u, expectedSegment %u\n",
                            numSegments, currentSegment, expectedSegment);
            halphyToolsMem (&internalRcvPayload, HALPHY_TOOLS_MEM_FREE, 0);
            return FALSE;
        }
        if (segmentLen != *payloadLen) 
        { 
            A_PRINTF_ALWAYS("cmdStream len mismatch, %u, %u\n", segmentLen, *payloadLen);
            halphyToolsMem (&internalRcvPayload, HALPHY_TOOLS_MEM_FREE, 0);
            return(FALSE);
        }

        // first segment
        if (0 == currentSegment)
        {
            expectedLen = cmdStream->cmdStreamHeader.length;

            // Allocate internalRcvPayload
            if (halphyToolsMem (&internalRcvPayload, HALPHY_TOOLS_MEM_ALLOC, expectedLen) == FALSE)
            {
                return FALSE;
            }
        }
        
        if (internalRcvPayload.size < (currentSegIdx + segmentLen))
        {
            A_PRINTF_ALWAYS("buffer overflowed, %u, %u\n", internalRcvPayload.size, (currentSegIdx + segmentLen));
            halphyToolsMem (&internalRcvPayload, HALPHY_TOOLS_MEM_FREE, 0);
            return(FALSE);
        }

        // store the stream payload to internalRcvPayload
        memcpy(&internalRcvPayload.pBuf[currentSegIdx], cmdStream->payload,  segmentLen);
        currentSegIdx += segmentLen;
        expectedSegment++;

        //last segment
        if ((currentSegment + 1) == numSegments)
        {
            if (currentSegIdx != expectedLen)
            {
                A_PRINTF_ALWAYS("totalLen len and expectedLen len mismatch, %u, %u\n", currentSegIdx, expectedLen);
                halphyToolsMem (&internalRcvPayload, HALPHY_TOOLS_MEM_FREE, 0);
                return FALSE;
            }
        }
        payload = (A_UINT32 *)internalRcvPayload.pBuf;
    }
    else
    {
        numSegments = 1;
        currentSegment = 0;
        if (cmdStream->cmdStreamHeader.length != *payloadLen) 
        { 
            A_PRINTF_ALWAYS("cmdStream len mismatch, %u, %u\n", cmdStream->cmdStreamHeader.length, *payloadLen); 
            return(FALSE);
        }
        payload = (A_UINT32 *)cmdStream->payload;
    }
    *numRemainSegs = numSegments - currentSegment - 1;
    //A_PRINTF("segment %d, numSegments %d, payloadLen %d\n", currentSegment, numSegments, *payloadLen);

    // first segment
    if (currentSegment == 0)
    {
        payloadPos = 0;

        // after header, it's the 4B cmdCode and randNum
        cmdCode = payload[payloadPos++];
        semCode = payload[payloadPos++]; 
        numParms = payload[payloadPos++]; 
        parmPayload = (A_UINT32 *)&(payload[payloadPos]);
        //A_PRINTF("cmdCode %d\n", cmdCode);

        if (getCmdDicHandlerTblPtrs(cmdCode, &cmdIdx, &pCmdDict, &pCmdHandlerTbl, &maxParm) == FALSE)
        {
            halphyToolsMem (&internalRcvPayload, HALPHY_TOOLS_MEM_FREE, 0);
            return FALSE;
        }
        if (semCode != pCmdDict[cmdIdx].rand) 
        { 
            A_PRINTF_ALWAYS("cmd rand mismatch code %d sc %d r %d\n", (int)cmdCode, (int)semCode, (int)pCmdDict[cmdIdx].rand);
            halphyToolsMem (&internalRcvPayload, HALPHY_TOOLS_MEM_FREE, 0);
            return(FALSE);
        }
    }

    // NOT the last segments, just call the handler of CMD_MORESEGMENTRSP
    // the programs (e.g tcmd, utf) should register a call back for this command
    if ((currentSegment + 1) < numSegments)
    {
        if (NULL != CmdHandlerTbl[CMD_MORESEGMENT].cmdProcessing) {
            cmdMoreSegment.cmdId = (A_UINT16)cmdCode;
            rc = CmdHandlerTbl[CMD_MORESEGMENT].cmdProcessing(&cmdMoreSegment);
        }
        return TRUE;
    }
    // last segment
    else
    {
        if (!(rc = parmParser2p0(cmdCode, numParms, parmPayload, &pParmStruct))) { A_PRINTF_ALWAYS("parm parsing error \n"); return(FALSE); }

        //-------------- get pointer....
        pParamPtr_ch = pParmStruct;
        *pPayload = pParmStruct;

        // call cmdHandler
        // How to pass in phyID? It should be a parameter in the parmStruct
        if (NULL != pCmdHandlerTbl[cmdIdx].cmdProcessing) {
            rc = pCmdHandlerTbl[cmdIdx].cmdProcessing((void*)pParmStruct);
        }

        // if cmdProcessing is succesful, 
        //     if CmdHandlerTbl.rsp is NULL, positive response
        //     else execute the rsp routine
        // else 
        //     negative response
        if (rc) {
            if (NULL == pCmdHandlerTbl[cmdIdx].rspGeneration) {
                // call bounded platform specific positive response, with cmd parmStruct for the eontext
                if (NULL != PlatformSpecific.sendGenericRsp) {
                    if (!(rc = PlatformSpecific.sendGenericRsp(cmdCode, (void*)pParmStruct, RSP_POSITIVE))) {
                        A_PRINTF_ALWAYS("sendRsp failed\n");
                        // nothing else can be done 
                    }
                }
            }
            else {
                // rspGeneration routine is provided with the cmd parmStruct to establish the context
                // likely it will fetch data on the target, and send response report back
                if (!(rc = pCmdHandlerTbl[cmdIdx].rspGeneration(cmdCode, (void*)pParmStruct))) {
                    A_PRINTF_ALWAYS("rspGeneration failed\n");
                }
            }
        }
        else {
            if (NULL != PlatformSpecific.sendGenericRsp) {
                if (!(rc = PlatformSpecific.sendGenericRsp(cmdCode, (void*)pParmStruct, RSP_NEGATIVE))) {
                    A_PRINTF_ALWAYS("sendRsp failed\n");
                }
            }
        }

        currentSegIdx = 0;
        expectedSegment = 0;
        halphyToolsMem (&internalRcvPayload, HALPHY_TOOLS_MEM_FREE, 0);
        return(rc);
    }
}

//
// Exposed API
TLV2_API A_BOOL addTLV2p0BinCmdParser(void)
{
    if (!(bindBinCmdStreamParser(binCmdStreamParserVer2, CMD_STREAM_VER2))) {
        return(FALSE);
    }

    // no separate cmdProcessing for TLV2p0
    return(TRUE);
}

