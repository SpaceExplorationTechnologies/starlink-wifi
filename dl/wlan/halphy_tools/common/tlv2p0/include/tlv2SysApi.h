// This is an auto-updated file when a command is added to tlv2p0 using cmdRspDictGenSrc.exe
// DON'T manually modify the file but use cmdRspDictGenSrc.exe.

#ifndef _TLV2_SYS_API_H_
#define _TLV2_SYS_API_H_


#ifdef _WINDOWS
    #ifdef TLV2P0_EXPORTS
        #define TLV2_API __declspec(dllexport)
    #else
        #define TLV2_API __declspec(dllimport)
    #endif //TLV2P0_EXPORTS
#else
    #define TLV2_API
#endif //#ifdef _WINDOWS

/*
 * Exposed APIs
 *     A_BOOL createCmdRsp(A_UINT32 cmdCode, int numArgs, ...);
 *   
 *     numArgs: the number of arguments following.
 *
 *     Singular format:
 *         parmCode(4B) parmRand(4B) parmValue(4B)
 *
 *     All data types are promoted either to A_UINT32 or A_INT32, depending on sign
 *
 *     Array format:
 *         parmCode(4B) parmRand(4B) numElem(4B) beginPos(4B) value1(4B) ... value(numElem-1)(4B)
 *
 *     beginPos starts from 0
 *
 * Examples
 *     createCmdRsp(CMD_TX, 4, PARM_FREQ, 5320, PARM_CHAINMASK, 0x7); 
 *     
 *     An array example, which sends tx gain table entries, 12, 19, 24
 *         A_UINT8 txGainTbl[32]={0, 6, 12, 19, 24, ....};
 *         createCmdRsp(CMD_TX, 6, PARM_FREQ, 2412, PARM_TXGAINTBL, 3, 2, &(txGainTble[0])); 
 *
 *
 */

#ifdef USE_TLV2_SYSCMD

#include "sysCmdSetChannel.h"
TLV2_API void registerSETCHANNELHandler(SETCHANNEL_OP_FUNC fp);
TLV2_API void registerSETCHANNELRSPHandler(SETCHANNELRSP_OP_FUNC fp);

#include "sysCmdTestData.h"
TLV2_API void registerTESTDATAHandler(TESTDATA_OP_FUNC fp);
TLV2_API void registerTESTDATARSPHandler(TESTDATARSP_OP_FUNC fp);

#include "sysCmdGeneric.h"
TLV2_API void registerGENERICHandler(GENERIC_OP_FUNC fp);
TLV2_API void registerGENERICRSPHandler(GENERICRSP_OP_FUNC fp);

#endif //USE_TLV2_SYSCMD

#endif // _TLV2_SYS_API_H_ - This is the marker line. Don't modify or delete this line 
