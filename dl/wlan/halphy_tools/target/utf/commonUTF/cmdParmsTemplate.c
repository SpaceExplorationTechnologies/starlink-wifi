#include <stdio.h>


#include "parmTxtTemplate.h"
#include "cmd2ParmTemplate.h"
#include "cmdParmsTemplate.h"

// This is not auto-generated, as in the case of _cmd_txParmsTxtTemplate.c
_TESTFLOW_CMD_PARM_TEMPLATE TestFlowCmd2ParmTemplate[] = {
    {0, NULL},         // _OP_SYNC
    {0, NULL },        // _OP_TX
    {0, NULL},         // _OP_RX
    {0, NULL},         // _OP_CAL
    {0, NULL},         // _OP_CAL_DONE
    {0, NULL},         // _OP_PM
    {NUM_OF__rspGenericParm, _rspGenericParm_txt_template},        // _OP_GENERIC_RSP
    {NUM_OF__submitreportParm, _submitreportParm_txt_template},    // _OP_SUBMIT_REPORT_RSP
    {0, NULL},         // _OP_GENERIC_NART_CMD
    {NUM_OF__nartRspParm, _nartRspParm_txt_template},         // _OP_GENERIC_NART_RSP
    {NUM_OF__txStatusParm, _txStatusParm_txt_template},           // _OP_TX_STATUS
    {NUM_OF__rxStatusParm, _rxStatusParm_txt_template},           // _OP_RX_STATUS
}; 

