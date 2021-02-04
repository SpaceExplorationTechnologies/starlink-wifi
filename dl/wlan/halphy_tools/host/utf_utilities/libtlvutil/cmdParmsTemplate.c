#include <stdio.h>
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
#include "cmdParmsTemplate.h"
#include "cmd2ParmTemplate.h"
#include "cmdOpCodeTemplate.h"
#include "parmTxtTemplate.h"

// This is not auto-generated, as in the case of _cmd_txParmsTxtTemplate.c, update the Template
_TESTFLOW_CMD_PARM_TEMPLATE TestFlowCmd2ParmTemplate[] = {
    {NUM_OF__rxParm,  _rxParm_txt_template},                    // _OP_SYNC
    {NUM_OF__txParm,  _txParm_txt_template},                    // _OP_TX
    {NUM_OF__rxParm,  _rxParm_txt_template},                    // _OP_RX
    {NUM_OF__calParm, _calParm_txt_template},                   // _OP_CAL
    {NUM_OF__calDoneParm, _calDoneParm_txt_template},           // _OP_CAL_DONE
    {NUM_OF__pmParm, _pmParm_txt_template},                     // _OP_PM
    {NUM_OF__rspGenericParm, _rspGenericParm_txt_template},     // _OP_GENERIC_RSP
    {NUM_OF__submitreportParm, _submitreportParm_txt_template}, // _OP_SUBMIT_REPORT_RSP
    {NUM_OF__nartCmdParm, _nartCmdParm_txt_template},           // _OP_GENERIC_NART_CMD
    {NUM_OF__nartRspParm, _nartRspParm_txt_template},           // _OP_GENERIC_NART_RSP
    {NUM_OF__txStatusParm, _txStatusParm_txt_template},         // _OP_TX_STATUS
    {NUM_OF__rxStatusParm, _rxStatusParm_txt_template},         // _OP_RX_STATUS
}; 

static _PARM_BIN_TEMPLATE *txCmdOpCodeTemplate();
static _PARM_BIN_TEMPLATE *rxCmdOpCodeTemplate();
static _PARM_BIN_TEMPLATE *calCmdOpCodeTemplate();
static _PARM_BIN_TEMPLATE *calDoneCmdOpCodeTemplate();
static _PARM_BIN_TEMPLATE *pmCmdOpCodeTemplate();
static _PARM_BIN_TEMPLATE *rspGenericOpCodeTemplate();
static _PARM_BIN_TEMPLATE *rspSubmitReportOpCodeTemplate();
static _PARM_BIN_TEMPLATE *nartCmdOpCodeTemplate();
static _PARM_BIN_TEMPLATE *nartRspOpCodeTemplate();
static _PARM_BIN_TEMPLATE *txStatusOpCodeTemplate();
static _PARM_BIN_TEMPLATE *rxStatusOpCodeTemplate();

//Update the CmdOpCodeTemplate when you add new opCode..
_CMD_OPCODE_HANDLERS CmdOpCodeTemplate[] = {
    /*_OP_RESERVED*/     {rxCmdOpCodeTemplate},
    /*_OP_TX*/           {txCmdOpCodeTemplate},
    /*_OP_RX*/           {rxCmdOpCodeTemplate},
    /*_OP_CAL*/          {calCmdOpCodeTemplate},
    /*_OP_CALDONE*/      {calDoneCmdOpCodeTemplate},
    /*_OP_PM*/           {pmCmdOpCodeTemplate},
    /*_OP_GENERIC_RSP*/  {rspGenericOpCodeTemplate},
    /*_OP_SUBMIT_REPORT_RSP*/  {rspSubmitReportOpCodeTemplate},
    /*_OP_GENERIC_NART_CMD*/  {nartCmdOpCodeTemplate},
    /*_OP_GENERIC_NART_RSP*/  {nartRspOpCodeTemplate},
    /*_OP_TX_STATUS*/  {txStatusOpCodeTemplate},
    /*_OP_RX_STATUS*/  {rxStatusOpCodeTemplate},
};

static _PARM_BIN_TEMPLATE *txCmdOpCodeTemplate()
{
        return _txParm_bin_template;
}

static _PARM_BIN_TEMPLATE *rxCmdOpCodeTemplate()
{
        return _rxParm_bin_template;
}

static _PARM_BIN_TEMPLATE *calCmdOpCodeTemplate()
{
        return _calParm_bin_template;
}

static _PARM_BIN_TEMPLATE *calDoneCmdOpCodeTemplate()
{
        return _calDoneParm_bin_template;
}

static _PARM_BIN_TEMPLATE *pmCmdOpCodeTemplate()
{
        return _pmParm_bin_template;
}

static _PARM_BIN_TEMPLATE *rspGenericOpCodeTemplate()
{
        return _rspGenericParm_bin_template;
}

static _PARM_BIN_TEMPLATE *rspSubmitReportOpCodeTemplate()
{
        return _submitreportParm_bin_template;
}

static _PARM_BIN_TEMPLATE *nartCmdOpCodeTemplate()
{
        return _nartCmdParm_bin_template;
}

static _PARM_BIN_TEMPLATE *nartRspOpCodeTemplate()
{
        return _nartRspParm_bin_template;
}

static _PARM_BIN_TEMPLATE *txStatusOpCodeTemplate()
{
        return _txStatusParm_bin_template;
}

static _PARM_BIN_TEMPLATE *rxStatusOpCodeTemplate()
{
        return _rxStatusParm_bin_template;
}

A_UINT8 getCmdOpCodeTemplateSize()
{
    return (sizeof(CmdOpCodeTemplate)/sizeof(_CMD_OPCODE_HANDLERS));
}

