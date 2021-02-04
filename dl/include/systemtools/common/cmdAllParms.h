#if !defined(_CMD_ALL_PARMS_H)
#define  _CMD_ALL_PARMS_H

#include "cmdTxParms.h"
#include "cmdRxParms.h"
#include "cmdCalParms.h"
#include "cmdCalDoneParms.h"
#include "cmdPmParms.h"
#include "cmdNartGenericCmdParms.h"
#include "rspGenericParms.h"
#include "submitReportParms.h"
#include "cmdNartGenericRspParms.h"
#include "cmdTxStatus.h"
#include "cmdRxStatus.h"

typedef struct _cmdAllParms {
    
    union {
        _CMD_TX_PARMS  _cmdTxParms; 
        _CMD_RX_PARMS  _cmdRxParms; 
        _CMD_CAL_PARMS _cmdCalParms; 
	_CMD_CAL_DONE_PARMS _cmdCalDoneParms;
	_CMD_PM_PARMS _cmdPmParms;
        _CMD_NARTCMD_PARMS _cmdNartCmdParms;
    } __ATTRIB_PACK _cmdParmU;

} __ATTRIB_PACK _CMD_ALL_PARMS;

#endif //#if !defined(_CMD_ALL_PARMS_H)

