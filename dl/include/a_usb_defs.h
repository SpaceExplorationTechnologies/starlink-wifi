/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// Copyright (c) 2007-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================
/*
 *  Shared USB definitions 
 * 
 * 
 * 
 * 
 */
  
#ifndef __A_USB_DEFS_H__ 
#define __A_USB_DEFS_H__

#ifndef ATH_TARGET
#include "athstartpack.h"
#endif

/* USB endpoint definitions */

#define USB_EP_ADDR_APP_CTRL_IN          0x81
#define USB_EP_ADDR_APP_DATA_IN          0x82
#define USB_EP_ADDR_APP_DATA2_IN         0x83
#define USB_EP_ADDR_APP_INT_IN           0x84



#define USB_EP_ADDR_APP_CTRL_OUT         0x01
#define USB_EP_ADDR_APP_DATA_LP_OUT      0x02
#define USB_EP_ADDR_APP_DATA_MP_OUT      0x03
#define USB_EP_ADDR_APP_DATA_HP_OUT      0x04

#define USB_CONTROL_REQ_SEND_BMI_CMD        1
#define USB_CONTROL_REQ_RECV_BMI_RESP       2
#define USB_CONTROL_REQ_DIAG_CMD            3
#define USB_CONTROL_REQ_DIAG_RESP           4


//#define USB_CONTROL_MAX_BMI_TRANSFER_SIZE   64
#define USB_CONTROL_MAX_BMI_TRANSFER_SIZE   252

#define HIF_BMI_MAX_TRANSFER_SIZE           USB_CONTROL_MAX_BMI_TRANSFER_SIZE

#define USB_HS_BULK_MAXP_SIZE   0x200  //512 Bytes Maxp for High Speed for BULK EP
#define USB_FS_BULK_MAXP_SIZE   0x40   //64 Bytes Maxp for Full Speed for BULK EP



/* diagnostic command defnitions */
#define USB_CTRL_DIAG_CC_READ      0
#define USB_CTRL_DIAG_CC_WRITE     1

typedef PREPACK struct {
    A_UINT32    Cmd;            
    A_UINT32    Address;
    A_UINT32    Value;
    A_UINT32    _pad[1];
} POSTPACK USB_CTRL_DIAG_CMD_WRITE;

typedef PREPACK struct {
    A_UINT32    Cmd;            
    A_UINT32    Address;
} POSTPACK USB_CTRL_DIAG_CMD_READ;

typedef PREPACK struct {
    A_UINT32    ReadValue;
} POSTPACK USB_CTRL_DIAG_RESP_READ;

#define USB_CTRL_MAX_DIAG_CMD_SIZE  (sizeof(USB_CTRL_DIAG_CMD_WRITE))
#define USB_CTRL_MAX_DIAG_RESP_SIZE (sizeof(USB_CTRL_DIAG_RESP_READ))

#ifndef ATH_TARGET
#include "athendpack.h"
#endif

#endif
