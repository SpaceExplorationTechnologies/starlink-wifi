/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#if !defined(_TEST_CMD_STREAM_H)
#define _TEST_CMD_STREAM_H

#include "cmdOpcodes.h"
#include "cmdStreamCommon.h"

// one parm -----------
// parm structure: parmType(4b)|parmCode(12b) parmReserved(2B) parmValue(4B)
#define MAX_NUM_VALUES  ATH_MAC_LEN

typedef enum {
    _PARM_RESERVED = 0,
    _PARM_U8,
    _PARM_U16,
    _PARM_U32,
    _PARM_S8,
    _PARM_S16,
    _PARM_S32,
    _PARM_DATA,
} _PARM_TYPE;

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif
typedef struct _parmVal {
    A_UINT32    val16;
    A_UINT32    val32;
} __ATTRIB_PACK _PARM_VAL;
#if defined(WIN32) || defined(WIN64)
#pragma pack (pop)
#endif	

typedef struct _parmOneOf {
    A_UINT32     parmCode;
    A_UINT32     parmType;
    union {
        A_UINT8 addr[MAX_NUM_VALUES+2];
        _PARM_VAL value;
    } parmValue;
} __ATTRIB_PACK  _PARM_ONEOF;
#define PARM_ONEOF_SIZE_V1      sizeof(struct _parmOneOf)
#define PARM_ONEOF_SIZE         PARM_ONEOF_SIZE_V1
#define PARM_NUM_MAX            ((PARM_BUF_LEN_MAX) / (PARM_ONEOF_SIZE))

// one cmd -----------
// command structure: cmdOpcode(1B) numOfParms(1B) parm1(8B) ... parmN(8B)
// refer to "cmdOpcodes.h"
typedef struct _oneCmdHeader {
    A_UINT32     opCode;
    A_UINT32     numOfParms;
} __ATTRIB_PACK _ONE_CMD_HEADER;

//typedef struct _cmdOneOf {
//    _ONE_CMD_HEADER  cmdHeader;
//    union {
//        A_UINT8      parmBuf[PARM_BUF_LEN_MAX];
//        _PARM_ONEOF  parm[PARM_NUM_MAX];
//    }                parms;
//} __ATTRIB_PACK  _CMD_ONEOF;
//#define CMD_ONOF_SIZE  sizeof(struct _cmdOnOf)


#endif // #if !defined(_TEST_CMD_STREAM_H)

