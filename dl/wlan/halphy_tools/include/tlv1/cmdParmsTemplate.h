#if !defined(_CMD_PARMS_TEMPLATE_H)
#define  _CMD_PARMS_TEMPLATE_H 

#if defined(_HOST_SIM_TESTING)
#include "_cmd_txParmTxtTemplate.h"
#include "_cmd_rxParmTxtTemplate.h"
#include "_cmd_calParmTxtTemplate.h"
#include "_cmd_calDoneParmTxtTemplate.h"
#include "_cmd_rspGenericParmTxtTemplate.h"
#include "_cmd_submitreportParmTxtTemplate.h"
#include "_cmd_pmParmTxtTemplate.h"
#include "_cmd_setRegParmTxtTemplate.h"
#include "_cmd_nartCmdParmTxtTemplate.h"
#include "_cmd_nartRspParmTxtTemplate.h"
#include "_cmd_txStatusParmTxtTemplate.h"
#include "_cmd_rxStatusParmTxtTemplate.h"
#else
#include "_cmd_rspGenericParmTxtTemplate.h"
#include "_cmd_submitreportParmTxtTemplate.h"
#include "_cmd_nartRspParmTxtTemplate.h"
#include "_cmd_txStatusParmTxtTemplate.h"
#include "_cmd_rxStatusParmTxtTemplate.h"
#endif

#endif // #if !defined(_CMD_PARMS_TEMPLATE_H)

