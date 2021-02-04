// This file is auto-updated when a sys command is added to the dictionary by running cmdRspDictGenSrc.exe


#include "tlv2Inc.h"
#include "cmdHandlers.h"

// Notes:
// 
// TBD??? "dynamic" loading of the modules?
// Potentially we could allocate enough space for "dynamic" binding of the handlers, modularize them
//
// SysCmdHandlerTbl
// Note:
//     1. rspGeneration of the RSP should be NULL, otherwise, it will be response for RSP, an infinite loop

CMD_HANDLER_ENTRY SysCmdHandlerTbl[] = {

#ifdef USE_TLV2_SYSCMD

    {NULL, NULL, NULL},
    {initSETCHANNELOpParms, SETCHANNELOp, NULL},
    {initSETCHANNELRSPOpParms, SETCHANNELRSPOp, NULL},
    {initTESTDATAOpParms, TESTDATAOp, NULL},
    {initTESTDATARSPOpParms, TESTDATARSPOp, NULL},
    {initGENERICOpParms, GENERICOp, NULL},
    {initGENERICRSPOpParms, GENERICRSPOp, NULL},
    
#endif //USE_TLV2_SYSCMD


//auto-updated marker - this line should be the last in the table (DON'T REMOVE THIS LINE)	
};

A_UINT32 MaxSysCmdHandlers = sizeof(SysCmdHandlerTbl) / sizeof(CMD_HANDLER_ENTRY);


