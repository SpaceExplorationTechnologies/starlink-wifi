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
#include "cmdStream.h"
#include "cmdAllParms.h"
#include "cmdProcessingSM.h"
#include "cmd2ParmTemplate.h"
#include "cmdOpCodeTemplate.h"
#include "parseRxBinCmdTlv.h"

extern _TESTFLOW_CMD_PARM_TEMPLATE TestFlowCmd2ParmTemplate[];
extern A_BOOL searchTestFlowParmTemplate(char *key, _TESTFLOW_TXT_PARM_TEMPLATE *parmTemplate, A_UINT32 numOfTemplateParms, A_UINT32 *parmCode, A_UINT32 *parmType, A_UINT32 *parmSize);

extern _CMD_OPCODE_HANDLERS CmdOpCodeTemplate[];
static A_UINT8 numOfParms=0;
static A_UINT8 opCodeTLV=0;
static _TESTFLOW_CMD_STREAM *cmdStream;

static A_BOOL binCmdStreamParser_Ver1(A_UINT8 *stream, A_UINT32 readStreamLen)
{
    A_BOOL rc=TRUE;
    A_UINT16 *pHalf=(A_UINT16*)stream;
    A_UINT16 streamLen;
    A_UINT16 payloadPos, cmdIdx;
    A_UINT8 *payload;
    _ONE_CMD_HEADER *oneCmdHeader;

    // checkSum verification
    cmdStream=(_TESTFLOW_CMD_STREAM *)stream;
    streamLen = sizeof(_TESTFLOW_CMD_STREAM_HEADER) + cmdStream->cmdStreamHeader.length;

    if (readStreamLen != streamLen) {
        printf("Incorrect stream length %d, should be %d\n", (int)readStreamLen, (int)streamLen);
        return(FALSE);
    }

    if (!verifyChecksum(pHalf, streamLen/2)) {
        printf("Incorrect checksum\n");
        return(FALSE);
    }

    // bypass cmd processing for legacy suport, e.g. ART
    if (( cmdStream->cmdStreamHeader.header & CMD_STERAM_HEADER_EXTENDED_RESERVED) &&
        ( cmdStream->cmdStreamHeader.headerExtended & CMD_STREAM_HEADER_EXTENDED_BYTESTREAM_BYPASS)) {
        return(TRUE);
    }

    oneCmdHeader = (_ONE_CMD_HEADER*) &cmdStream->payload[0];

    opCodeTLV = oneCmdHeader->opCode;
    numOfParms = oneCmdHeader->numOfParms;

    return(rc);
}

typedef A_BOOL (*pBinCmdStreamParser)(A_UINT8 *stream, A_UINT32 readStreamLen);
pBinCmdStreamParser binCmdStreamParserTLV[] = {
    NULL,                         // version 0, not used, 0 is difficult to tell
    binCmdStreamParser_Ver1,      // version 1
    NULL,
    NULL,
};

static A_BOOL parseBinCmdStreamTLV(A_UINT8 *stream, A_UINT32 readStreamLen)
{
    A_BOOL rc=TRUE;
    _TESTFLOW_CMD_STREAM_HEADER *pCmdStreamHeader = (_TESTFLOW_CMD_STREAM_HEADER *)&(stream[0]);

    // check the binary cmd stream version
    if (pCmdStreamHeader->version > CMD_STREAM_VER_LATEST) {
        //_printf("unsupported cmd stream version %d\n", pCmdStreamHeader->version);
        return(FALSE);
    }

    if ((NULL != binCmdStreamParserTLV[pCmdStreamHeader->version]) && (pCmdStreamHeader->version <= CMD_STREAM_VER_LATEST)) {
        rc = (binCmdStreamParserTLV[pCmdStreamHeader->version])(stream, readStreamLen);
    }

    return(rc);
}

static A_BOOL cmdParmsParser(_PARM_BIN_TEMPLATE *_parm_bin_template, 
                       A_UINT32 parmCode_tlv, A_UINT32 parmType_tlv, A_UINT32 parmSize_tlv, A_UINT8 **data, A_UINT32 *len)
{
    _PARM_ONEOF   *oneParm;
    A_UINT32 pos, offset;
    size_t   size;
    A_UINT32  parmCode, parmType,parmModType;
    A_INT32  i;
    A_UINT8 *parmBuf = (A_UINT8*)cmdStream;

    pos=sizeof(_ONE_CMD_HEADER)+sizeof(_TESTFLOW_CMD_STREAM_HEADER);

    for (i=0;i<numOfParms;i++) {
        oneParm = (_PARM_ONEOF *)(&parmBuf[pos]);
        parmCode = oneParm->parmCode;
        parmModType = parmType = oneParm->parmType;

        if(parmModType == _PARM_DATA) {
            parmModType = _PARM_U8;
        }

        size   = _parm_bin_template[parmCode].len;
        offset = 0;
       
        if ( (parmCode == parmCode_tlv) && (parmModType == parmType_tlv) && (size == parmSize_tlv)) {
        	if ((A_UINT8)_PARM_U8 == parmType || _PARM_S8 == parmType)
            	    *data = (A_UINT8 *)&(oneParm->parmValue.addr[0]);
        	else if ((A_UINT8)_PARM_DATA == parmType) {
            	    *data = (A_UINT8 *)&parmBuf[pos + sizeof(_PARM_ONEOF) ];
                    size = offset = oneParm->parmValue.value.val16;
                }
        	else if ((A_UINT8)_PARM_U16 == parmType || _PARM_S16 == parmType) {
            	    *data = (A_UINT8 *)&(oneParm->parmValue.value.val16);
                }
        	else {
            	    *data = (A_UINT8 *)&(oneParm->parmValue.value.val32);
                }

		*len = size;

                return TRUE;
	}

        pos += sizeof(_PARM_ONEOF);
        pos += offset;
    }

    return(FALSE);
}

LIBTLVUTILDLLSPEC A_BOOL getParams(A_UINT8 *key, A_UINT8 **data, A_UINT32 *len)
{
	_TESTFLOW_TXT_PARM_TEMPLATE *parmTemplate;
        A_UINT32 numOfTemplateParms;
	A_UINT32 parmCode, parmType, parmSize;
        A_UINT8 *cmdParmBuf;
        _PARM_BIN_TEMPLATE *parmBinTemplate;
        A_BOOL rc = TRUE;
        A_UINT8 opCodeLenHandled=0;

	if ( (opCodeTLV == 0) || (numOfParms ==0) ) {
		printf("Response not initialized...\n");
		return FALSE;
	}

	parmTemplate         = TestFlowCmd2ParmTemplate[opCodeTLV].parmTemplate;
	numOfTemplateParms   = TestFlowCmd2ParmTemplate[opCodeTLV].numParms;

	if (searchTestFlowParmTemplate((char*)key, parmTemplate, numOfTemplateParms, &parmCode, &parmType, &parmSize)) {
                opCodeLenHandled = getCmdOpCodeTemplateSize();
                if ( opCodeTLV <= opCodeLenHandled ) {
	            parmBinTemplate = (CmdOpCodeTemplate[opCodeTLV]._CmdOpCodeTemplate)();
	            rc = cmdParmsParser(parmBinTemplate, parmCode, parmType, parmSize, data, len);
                }
                else {
                    return FALSE;
                }
	}
	else {
		return FALSE;
	}
     
	return rc;
}

LIBTLVUTILDLLSPEC A_BOOL initResponse(A_UINT8 *stream, A_UINT32 len, A_UINT8 *opCode)
{
	A_BOOL ret = TRUE;

        opCodeTLV = 0;
	ret = parseBinCmdStreamTLV(stream,len);
	*opCode = opCodeTLV; 

        return ret;
}
