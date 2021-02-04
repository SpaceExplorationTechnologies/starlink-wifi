#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wlantype.h"
#include "otaHostCommon.h"
#include "parmTxtTemplate.h"
#include "cmdOpcodes.h"
#include "cmdStream.h"
#include "cmd2ParmTemplate.h"
#include "cmdParmsTemplate.h"

typedef enum {
    TESTFLOW_CMD=0,
    TESTFLOW_PARM,
    TESTFLOW_CONFIG,
    TESTFLOW_DONE,
} TESTFLOW_PARSER_STATE;

extern _TESTFLOW_CMD_PARM_TEMPLATE TestFlowCmd2ParmTemplate[];
 
static A_BOOL searchTestFlowParmTemplate(char *key, _TESTFLOW_TXT_PARM_TEMPLATE *parmTemplate, A_UINT32 numOfTemplateParms, A_UINT16 *parmCode, A_UINT16 *parmType, A_UINT16 *parmSize) 
{
    int i;
    for (i=0;i<numOfTemplateParms;i++) {
        if (0 == strcmp(key, parmTemplate[i].parm)) {
            *parmCode=i;
            *parmType = parmTemplate[i].parmType;
            *parmSize = parmTemplate[i].len;
            return(TRUE);
        }
    }
    return(FALSE);
}

// Read test flow file 
// exposed API for other host applications
static  _TESTFLOW_CMD_STREAM testCmdStream;
static  int                  testCmdStreamLen;
A_BOOL parseTestFlowTxtCreateCmdStream(char *fileName, int *cmdStreamLen, A_UINT8 **rCmdStream)
{
    FILE *fStream;
    char lineBuf[LINEBUF_SIZE], *pLine;
    char delimiters[] = " =,;\t\n\r/";
    char key[KEY_SIZE_MAX];
    A_INT32 cmdStreamPos=0, curCmdTotalLen;
    A_UINT8 curCmdOpcode, lastCmdOpcode, lastNumParms;
    TESTFLOW_PARSER_STATE parserState;
    _TESTFLOW_TXT_PARM_TEMPLATE *parmTemplate;
    A_UINT32 numOfTemplateParms;
    _CMD_ONEOF oneCmd;
    A_UINT16 sum, parmCode, parmType, parmSize;
    A_UINT32 parmIdx, value[MAX_NUM_VALUES], i;
    A_UINT8 *cmdStream;
    int rc;

    if( (fStream = fopen( fileName, "r")) == NULL ) {
        printf("Failed to open %s - the MACID will not be written\n", fileName);
        return(FALSE);
    }
    memset((void*)&testCmdStream, 0, sizeof(testCmdStream));
    testCmdStreamLen = 0;
    testCmdStream.cmdStreamHeader.version = CMD_STREAM_VER1;
    testCmdStream.cmdStreamHeader.header = 0;
    testCmdStream.cmdStreamHeader.headerDepValue = 0;
    testCmdStream.cmdStreamHeader.headerExtended  = 0;
    testCmdStream.cmdStreamHeader.checkSum = 0;
 
    memset((void*)&oneCmd, 0, sizeof(oneCmd));
    cmdStreamPos = 0;
    curCmdOpcode = _OP_TEST_CONFIG;
    parmIdx =0;
    parserState = TESTFLOW_CMD;
    parmTemplate = NULL;
    numOfTemplateParms = 0;

    while(fgets(lineBuf, LINEBUF_SIZE-1, fStream) != NULL) {
        pLine = lineBuf;

        while(isspace(*pLine)) pLine++;

        if(*pLine == '#') {
            continue;
        }
    
        pLine = strtok(pLine, delimiters);
        if (pLine == NULL) { continue; }

        memset((void*)key, 0, sizeof(key));
        if (!sscanf(pLine, "%s", key)) {
            printf("Error reading key out of %s\n", pLine);
            continue;
        }

        for (i=0;i<MAX_NUM_VALUES;i++) {
            pLine = strtok(NULL, delimiters);
            if (NULL == pLine) break;
            if(*pLine == '#') { continue; }
            if (pLine[0] == '0' && ( pLine[1] == 'x' || pLine[1] == 'X')) {
                rc = sscanf(pLine, "%x", &(value[i]));
            }
            else {
                rc = sscanf(pLine, "%d", &(value[i]));
            }
            if (!rc) {
        	printf("Warning reading value out of %s\n", pLine);
        	continue;
            }
        }

        if (0 == strcmp(key, "op")) {
            lastCmdOpcode = curCmdOpcode;
            lastNumParms = (A_UINT8)parmIdx;
            curCmdOpcode = (A_UINT8)value[0];
            if (_OP_TEST_CONFIG != curCmdOpcode && curCmdOpcode >= _OP_MAX) {
                printf("Error, opcode out of range %d\n", curCmdOpcode);
                continue;
            }

            // special handling of test config
            //
            if (_OP_TEST_CONFIG == curCmdOpcode) {
                // finish all config settings until next "op"
                parserState = TESTFLOW_CONFIG;
            }
            else {
                if (TESTFLOW_CONFIG == parserState) {
                    parserState = TESTFLOW_CMD;
                    // no current or last command to complete, simply
                    // flow to cmd state
                }
                if (TESTFLOW_PARM == parserState ) {
                    // completes the curent or last command, 
                    oneCmd.cmdHeader.opCode = lastCmdOpcode;
                    oneCmd.cmdHeader.numOfParms = lastNumParms;
                    curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
                    memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
                    cmdStreamPos += curCmdTotalLen;

                    // flows to 
                    parserState = TESTFLOW_CMD;
                }
                // catch above two cases, during state transition ...
                if (TESTFLOW_CMD == parserState) {
                    // beginning of a test flow command
                    parmTemplate         = TestFlowCmd2ParmTemplate[curCmdOpcode].parmTemplate;
                    numOfTemplateParms   = TestFlowCmd2ParmTemplate[curCmdOpcode].numParms;
                    parmIdx = 0;
                    memset((void*)&oneCmd, 0, sizeof(oneCmd));

                    // moving to
                    parserState = TESTFLOW_PARM;
                    
                }
            }
        }
        else {
           // must be a parm
           if (TESTFLOW_CONFIG == parserState) {
               if (0 == strcmp(key, "header")) {
                   testCmdStream.cmdStreamHeader.header = (A_UINT8)value[0];
               }
               else if (0 == strcmp(key, "headerDepValue")) {
                   testCmdStream.cmdStreamHeader.headerDepValue = (A_UINT16)value[0];
               }
               else if (0 == strcmp(key, "headerExtended")) {
                   testCmdStream.cmdStreamHeader.headerExtended = (A_UINT32)value[0];
               }
               else { 
                   printf("Error reading test config %s\n", key);
               }
           }
           else if (TESTFLOW_PARM == parserState) {
               if (searchTestFlowParmTemplate(key, parmTemplate, numOfTemplateParms, &parmCode, &parmType, &parmSize)) {
                   oneCmd.parms.parm[parmIdx].parmCode  = (A_UINT8)parmCode;
                   oneCmd.parms.parm[parmIdx].parmType  = (A_UINT8)parmType;
                   if (_PARM_U8 == parmType || _PARM_S8 == parmType ) {
                       for (i=0;i<parmSize;i++) {
                           oneCmd.parms.parm[parmIdx].parmValue.addr[i] = (A_UINT8)value[i];
                       }
                   }
                   else if (_PARM_U16 == parmType || _PARM_S16 == parmType ) {
                       oneCmd.parms.parm[parmIdx].parmValue.value.val16 = (A_UINT16)value[0];
                   }
                   else if (_PARM_U32 == parmType || _PARM_S32 == parmType ) {
                       oneCmd.parms.parm[parmIdx].parmValue.value.val32 = (A_UINT32)value[0];
                   }
                   else {
                       printf("Unknown parm type %d\n", parmType);
                       oneCmd.parms.parm[parmIdx].parmValue.value.val32 = (A_UINT32)value[0];
                   }
                   parmIdx++;
               }
           }
           else {
               printf("Error: encounter parm while not in parm parsing state, %s %d\n", key, parserState);
               continue;
           } 
        } 
        memset((void*)&lineBuf, 0, sizeof(lineBuf));

    } // End of line parsing

    // last cmd
    if (TESTFLOW_PARM == parserState) {
        // one command completed, 
        oneCmd.cmdHeader.opCode = curCmdOpcode;
        oneCmd.cmdHeader.numOfParms = parmIdx;
        curCmdTotalLen = oneCmd.cmdHeader.numOfParms * sizeof(_PARM_ONEOF) + sizeof(_ONE_CMD_HEADER);
        memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&oneCmd, curCmdTotalLen); 
        cmdStreamPos += curCmdTotalLen;

        // flows to 
        parserState = TESTFLOW_DONE;
    }
    if (fStream) fclose(fStream);

    // get the whole cmd stream ready.
    // either pass the whole stream down the host/dut interface, or write to a binary file
    cmdStream = (A_UINT8 *)&testCmdStream;
    testCmdStream.cmdStreamHeader.length = cmdStreamPos;
    *cmdStreamLen = testCmdStreamLen = testCmdStream.cmdStreamHeader.length +sizeof(_TESTFLOW_CMD_STREAM_HEADER); 

    // computer checksum
    sum = computeChecksumOnly((A_UINT16*)cmdStream, (*cmdStreamLen)/2);
    testCmdStream.cmdStreamHeader.checkSum = 0xFFFF ^ sum;
    
    *rCmdStream = cmdStream;

    return(TRUE);
}

A_BOOL writeCmdStream2BinFile(char *fileName, int streamLen, A_UINT8 *stream)
{
    FILE *fp;
    int i;
    if ( (fp = fopen(fileName, "wb")) == NULL) {
        printf("Error: open to write bin %s \n", fileName);
        return FALSE;
    }
    if (streamLen != fwrite((A_UINT8 *)stream, 1, streamLen, fp)) {
        printf("Error: writing to %s\n", fileName);
    }
    if (fp) fclose(fp);

    printf("..stream: ");
    for (i=0;i<streamLen;i++) {
        printf("%x ", stream[i]);
    }
    printf("\n");

    return(TRUE);
}

// Input: a byte stream, 
// Output: CmdStream with header bypass the cmd parser
extern A_BOOL createCmdStream4ByteStreamBypass(A_UINT8 *byteStream, A_UINT16 byteStreamLen, A_UINT16 *cmdStreamLen, A_UINT8 **rCmdStream);

// Usage:
//    genTestSeq.out <testFlow.txt>  => <testFlow.bin>
//    
#define  _GEN_CMDSTREAM_MODE 
#if defined(_GEN_CMDSTREAM_MODE)
int main(int argc, char *argv[])
{
    char outFile[FILENAME_SIZE], inFile[FILENAME_SIZE];
    int cmdStreamLen;
    A_BOOL rc;
    A_UINT8 *cmdStream;
    char *pLine;

    if ((2 != argc) && (3 != argc)) {
        printf("Usage: genTestSeq.out <testFlow text> (<testFlow binary>)\n");
        return(0);
    }
    strcpy((void*)inFile, (void*)argv[1]);
    if (3 == argc) {
        sprintf(outFile, ".output/%s.bin", argv[2]);
    }
    else {
        char tmpStr[FILENAME_SIZE];
        strcpy(tmpStr, argv[1]);
        pLine = tmpStr;
        if (NULL != strchr(tmpStr, '/')) {
            pLine = strtok(pLine, "/");
            pLine=strtok(NULL, "."); 
        }
        else {
            pLine=strtok(pLine, ".");
        }
        sprintf(outFile, ".output/%s.bin", pLine);
    }
    if (parseTestFlowTxtCreateCmdStream(inFile, &cmdStreamLen, &cmdStream)) {
        if (!writeCmdStream2BinFile(outFile, cmdStreamLen, cmdStream)) {
            return(-1);
        }
    }
    return(0);
}
#endif //#if !defined(_GEN_CMDSTREAM_MODE)

// for testing
//#define  _TESTING_THE_FLOW 
#if defined(_TESTING_THE_FLOW)
int main(void)
{
    A_BOOL rc;
    A_UINT16 cmdStreamLen, payloadLen;
    A_UINT8 *rCmdStream, *pPayload;
    A_UINT8 byteStream[20]={1,2,3,4,5,6,7,8,9,10,'a','b','c','d','e','f','g','h','i','j'};
    rc = createCmdStream4ByteStreamBypass(byteStream, 20, &cmdStreamLen, &rCmdStream);
    rc = parseBinCmdStream(rCmdStream, cmdStreamLen, &pPayload, &payloadLen);

    return(0);
}
#endif //#if defined(_TESTING_THE_FLOW)


