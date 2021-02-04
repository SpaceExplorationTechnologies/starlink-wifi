#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_HOST_SIM_TESTING)
#include "otaHostCommon.h"
#else
#include "osapi.h"
#endif
#include "parmTxtTemplate.h"
#include "cmdOpcodes.h"
#include "cmdStream.h"
#include "cmd2ParmTemplate.h"
#include "cmdParmsTemplate.h"

#include "genTxBinCmdTlv.h"
#include "testcmd.h"

#define SWAP32(_x) ((u_int32_t)(                       \
                    (((const u_int8_t *)(&_x))[0]) |        \
                    (((const u_int8_t *)(&_x))[1]<< 8) |    \
                    (((const u_int8_t *)(&_x))[2]<<16) |    \
                    (((const u_int8_t *)(&_x))[3]<<24)))

#define MAX_SIZE 4

typedef enum {
    TESTFLOW_CMD=0,
    TESTFLOW_PARM,
    TESTFLOW_CONFIG,
    TESTFLOW_DONE,
} TESTFLOW_PARSER_STATE;

extern _TESTFLOW_CMD_PARM_TEMPLATE TestFlowCmd2ParmTemplate[];
extern A_UINT16 computeChecksumOnly(A_UINT16 *pHalf, A_UINT16 length);
 
A_BOOL searchTestFlowParmTemplate(char *key, _TESTFLOW_TXT_PARM_TEMPLATE *parmTemplate, A_UINT32 numOfTemplateParms, A_UINT32 *parmCode, A_UINT32 *parmType, A_UINT32 *parmSize) 
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
static  _TESTFLOW_CMD_STREAM testCmdStream;
static A_INT32 cmdStreamPos=0;
static A_UINT8 curCmdOpcode;
static TESTFLOW_PARSER_STATE parserState;
_TESTFLOW_TXT_PARM_TEMPLATE *parmTemplate;
static A_UINT32 numOfTemplateParms,parmIdx;
static A_UINT8 *cmdStream;
static A_BOOL commandCreated = FALSE;

A_BOOL addCommand(A_UINT8 opCode);

LIBTLVUTILDLLSPEC A_BOOL createCommand(A_UINT8 opCode)
{
    A_BOOL ret = TRUE;

    if (_OP_TEST_CONFIG != opCode && opCode >= _OP_MAX) {
        printf("Error, opcode out of range %d\n", opCode);
        return FALSE;
    }

    if (commandCreated == TRUE)
    {
        printf("Error: command opCode not completed\n");
        return FALSE;
    }
 
    memset((void*)&testCmdStream, 0, sizeof(testCmdStream));

    testCmdStream.cmdStreamHeader.cmdId = TC_CMD_TLV_ID;
    testCmdStream.cmdStreamHeader.version = CMD_STREAM_VER1;
    testCmdStream.cmdStreamHeader.header = 0;
    testCmdStream.cmdStreamHeader.headerDepValue = 0;
    testCmdStream.cmdStreamHeader.headerExtended  = 0;
    testCmdStream.cmdStreamHeader.checkSum = 0;
 
    cmdStreamPos = sizeof(_ONE_CMD_HEADER);
    curCmdOpcode = _OP_TEST_CONFIG;
    parmIdx =0;
    parserState = TESTFLOW_CMD;
    parmTemplate = NULL;
    numOfTemplateParms = 0;
    commandCreated = TRUE;

    ret = addCommand(opCode);

    return ret;
}

A_BOOL addCommand(A_UINT8 opCode)
{
    if ( commandCreated == FALSE )
    {
        printf("Error: Command NOT created\n");
        return FALSE;
    }

    if (_OP_TEST_CONFIG != opCode && opCode >= _OP_MAX) {
        printf("Error, opcode out of range %d\n", opCode);
	    return FALSE;
    }

    curCmdOpcode = (A_UINT8)opCode;

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

        // catch above two cases, during state transition ...
        if (TESTFLOW_CMD == parserState) {
            // beginning of a test flow command
            parmTemplate         = TestFlowCmd2ParmTemplate[curCmdOpcode].parmTemplate;
            numOfTemplateParms   = TestFlowCmd2ParmTemplate[curCmdOpcode].numParms;
            parmIdx = 0;
            // moving to
            parserState = TESTFLOW_PARM;
            
        }
    }
    return TRUE;
}

LIBTLVUTILDLLSPEC A_BOOL addParameterToCommand(A_UINT8 *key, A_UINT8 *value)
{
    return (addParameterToCommandWithLen(key,value,0));
}

LIBTLVUTILDLLSPEC A_BOOL addParameterToCommandWithLen(A_UINT8 *key, A_UINT8 *value, A_UINT16 dataLen)
{
   A_UINT32 parmCode, parmType, parmSize;
   A_UINT32 i=0,j,len,padCount;
   _PARM_ONEOF parmOne;

   memset(&parmOne,0,sizeof(_PARM_ONEOF)); 
    if ( commandCreated == FALSE )
    {
        printf("Error: Command NOT created\n");
        return FALSE;
    }

   if (TESTFLOW_CONFIG == parserState) {
       if (0 == strcmp((char*)key, "header")) {
           testCmdStream.cmdStreamHeader.header = (A_UINT8)value[0];
       }
       else if (0 == strcmp((char*)key, "headerDepValue")) {
           memcpy(&testCmdStream.cmdStreamHeader.headerDepValue,value,sizeof(A_UINT16));
       }
       else if (0 == strcmp((char*)key, "headerExtended")) {
           memcpy(&testCmdStream.cmdStreamHeader.headerExtended,value,sizeof(A_UINT32));
       }
       else { 
           printf("Error reading test config %s\n", key);
       }
   }
   else if (TESTFLOW_PARM == parserState) {
       if (searchTestFlowParmTemplate((char*)key, parmTemplate, numOfTemplateParms, &parmCode, &parmType, &parmSize)) {
           parmOne.parmCode  = (A_UINT32)parmCode;
           parmOne.parmType  = (A_UINT32)parmType;

           if (_PARM_U8 == parmType || _PARM_S8 == parmType ) {
               if ( parmSize <= MAX_SIZE ) {
                   for (i=0;i<parmSize;i++) {
                       parmOne.parmValue.addr[i] = (A_UINT8)value[i];
                   }

                   padCount = 0;
                   if((parmSize%4) != 0)
                   {
                        padCount=4-(parmSize%4);
                        for (j=0;j<padCount;j++)
                        {
                            parmOne.parmValue.addr[parmSize+j] = 0;
                        }
                   }


#ifdef ARCH_BIG_ENDIAN
// Swap payload here based on 32bit boundary
                    {
                        A_UINT32 byte4, swappedByte4;
                        for(i=0; i<(parmSize+padCount)/4; i++)
                        {
                            byte4 = *((A_UINT32 *)&parmOne.parmValue.addr[i*4]);
                            swappedByte4=SWAP32(byte4);
                            *((A_UINT32 *)&parmOne.parmValue.addr[i*4]) = swappedByte4;
                        }
                    }
#endif

               }
               else {
                   if ( dataLen ) {
                       if ( dataLen > parmSize ) {
                           printf("Given dataLen %d is greater than parmSize %d\n",(int)dataLen,(int)parmSize);
                           return FALSE;
                       }
                   }
                   else {
                       dataLen = parmSize;
                   }

                   parmOne.parmType = _PARM_DATA;
                   parmOne.parmValue.value.val16 = dataLen;
                   parmOne.parmValue.value.val32 = 0;
               }
           }
           else if (_PARM_U16 == parmType) {
               A_UINT32 temp;
               A_UINT16 t1;
               memcpy(&t1, value, 2);
               temp=(A_UINT32)t1;
               memcpy(&parmOne.parmValue.value.val16,&temp,sizeof(A_UINT32));
           }
           else if (_PARM_S16 == parmType ) {
               A_INT32 temp;
               A_INT16 t1;
               memcpy(&t1, value, 2);
               temp=(A_INT32)t1;
               memcpy(&parmOne.parmValue.value.val16,&temp,sizeof(A_INT32));
           }
           else if (_PARM_U32 == parmType || _PARM_S32 == parmType ) {
               memcpy(&parmOne.parmValue.value.val32,value,sizeof(A_UINT32));
           }
           else {
               printf("Unknown parm type %d\n", (int)parmType);
               return FALSE;
           }

           if ( parmOne.parmType == _PARM_DATA )
               len = cmdStreamPos + sizeof(_PARM_ONEOF) + dataLen;
           else
               len = cmdStreamPos + sizeof(_PARM_ONEOF);

           if (len > CMD_PAYLOAD_LEN_MAX) {
               printf("len is greater than CMD PAYLOAD MAX %d\n",(int)len);
               return FALSE;
           }

           if ((sizeof(_PARM_ONEOF) <= sizeof(testCmdStream.payload)) && (cmdStreamPos >= 0))
           {
           	memcpy((void*)&(testCmdStream.payload[cmdStreamPos]), (void*)&parmOne,sizeof(_PARM_ONEOF));
           	cmdStreamPos = cmdStreamPos + sizeof(_PARM_ONEOF);
           }
           if ( parmOne.parmType == _PARM_DATA ) {

               for (i=0;i<dataLen;i++) {
                   testCmdStream.payload[cmdStreamPos + i] = (A_UINT8)value[i];
               }
               padCount = 0;
               if((dataLen%4) != 0)
               {
                    //padding of zero is required
                    padCount = 4-(dataLen%4);
                    for(j=0; j<padCount; j++)
                        testCmdStream.payload[cmdStreamPos+dataLen+j] = 0x0;
               }

#ifdef ARCH_BIG_ENDIAN
// Swap payload here based on 32bit boundary
                {
                    A_UINT32 byte4, swappedByte4;
                    for(i=cmdStreamPos/4; i<(cmdStreamPos+dataLen+padCount)/4; i++)
                    {
                        byte4 = *((A_UINT32 *)&testCmdStream.payload[i*4]);
                        swappedByte4=SWAP32(byte4);
                        *((A_UINT32 *)&testCmdStream.payload[i*4]) = swappedByte4;
                    }
                }
#endif

               cmdStreamPos = cmdStreamPos + dataLen + padCount;
           }

           parmIdx++;
       }
   }
   else {
       printf("Error: encounter parm while not in parm parsing state, %s %d\n", key, parserState);
       return FALSE;
   } 

    return TRUE;
}

LIBTLVUTILDLLSPEC A_BOOL commandComplete(A_UINT8 **rCmdStream, A_UINT32 *cmdStreamLen )
{
    A_UINT16 sum;
    A_BOOL ret = TRUE;
    _ONE_CMD_HEADER cmdHeader;
    A_UINT32 i=0;

    cmdHeader.opCode = curCmdOpcode;
    cmdHeader.numOfParms = parmIdx;

    memcpy((void*)&(testCmdStream.payload[0]), (void*)&cmdHeader, sizeof(_ONE_CMD_HEADER)); 

    // flows to 
    parserState = TESTFLOW_DONE;

    // get the whole cmd stream ready.
    // either pass the whole stream down the host/dut interface, or write to a binary file
    cmdStream = (A_UINT8 *)&testCmdStream;
    testCmdStream.cmdStreamHeader.length = cmdStreamPos;
    *cmdStreamLen = testCmdStream.cmdStreamHeader.length +sizeof(_TESTFLOW_CMD_STREAM_HEADER); 

    // computer checksum
    sum = computeChecksumOnly((A_UINT16*)cmdStream, (*cmdStreamLen)/2);
    testCmdStream.cmdStreamHeader.checkSum = 0xFFFF ^ sum;

    commandCreated = FALSE;

    *rCmdStream = cmdStream;

#if 0
    printf("%s[%d] cmdStream ...",__func__,__LINE__);
    for(i=0;i<*cmdStreamLen;i++)
    {
        if (i % 16 == 0) printf("\n");
        printf("%x ",cmdStream[i]);
    }
    printf("\n");
#endif

    return ret;
}

