#include <stdio.h>

#include "wlantype.h"
#include "otaHostCommon.h"
#include "parmTxtTemplate.h"
#include "cmd2ParmTemplate.h"
#include "cmdParmsTemplate.h"

// This is not auto-generated, as in the case of _cmd_txParmsTxtTemplate.c
_TESTFLOW_CMD_PARM_TEMPLATE TestFlowCmd2ParmTemplate[] = {
    {NUM_OF__rxParm,  _rxParm_txt_template},         // _OP_SYNC
    {NUM_OF__txParm,  _txParm_txt_template},         // _OP_TX
    {NUM_OF__rxParm,  _rxParm_txt_template},         // _OP_RX
    {NUM_OF__calParm, _calParm_txt_template},        // _OP_CAL
//    {NUM_OF__calDoneParm, _calDoneParm_txt_template},        // _OP_CAL
}; 

