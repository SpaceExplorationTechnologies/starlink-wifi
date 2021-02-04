/*
Copyright (c) 2012 Qualcomm-Atheros Communications Inc.  

    All rights reserved.

Module Name:

	art2_shared.h

Abstract:

    functions ART2 specific

Revision History:

    2012-04-03 created by Wade Song

Notes:

*/

#ifndef _ART2_SHARED_
#define _ART2_SHARED_


// device interface id {A35AB82A-FDAF-4680-8595-4E2A4ACBF46E}
DEFINE_GUID(ART2_DEV_INF_GUID, 0xA35AB82A, 0xFDAF, 0x4680, 0x85, 0x95, 0x4E, 0x2A, 0x4A,0xCB, 0xF4, 0x6E);

//GUID_DEVINTERFACE_NET
DEFINE_GUID(NetGuid,0xCAC88484,0x7515,0x4C03, 0x82, 0xE6, 0x71, 0xA8, 0x7A, 0xBA, 0xC3, 0x61);

//
// Device type           -- in the "User Defined" range."
//
#define ART2_IOCTL_TYPE_START 	50000


//
// The IOCTL function codes from 0x800 to 0xFFF are for END USER use.
//

/* ART2 WMI test command */
#define ART2_DEV_IOCTL_REQUEST \
    CTL_CODE( ART2_IOCTL_TYPE_START, 0x901, METHOD_OUT_DIRECT, FILE_ANY_ACCESS )


#define ART2_REQ_ID_UTF_CMD 		0x00000001
#define ART2_REQ_ID_UTF_RSP			0x00000002
#define ART2_REQ_ID_WMI_CMD 		0x00000003
#define ART2_REQ_ID_WMI_RSP			0x00000004
#define ART2_REQ_ID_READ_MEM 		0x00000005
#define ART2_REQ_ID_WRITE_MEM		0x00000006
#define ART2_REQ_ID_READ_REG		0x00000007
#define ART2_REQ_ID_WRITE_REG 		0x00000008
#define ART2_REQ_ID_DL_FW 			0x00000009
#define ART2_REQ_ID_BMI_DONE		0x0000000A
#define ART2_REQ_ID_READ_CFG		0x0000000B
#define ART2_REQ_ID_WRITE_CFG		0x0000000C
#define ART2_REQ_ID_GET_INIT_STAT	0x0000000D



#define ART2_REQ_ID_OTHER			0x000000FF


//
// Firmware downloading flags
//
#define ART2_FW_DL_BOARD_DATA		0x00000001
#define ART2_FW_DL_ATH_WLAN			0x00000002
#define ART2_FW_DL_PATCH			0x00000004
#define ART2_FW_DL_UTF				0x00000008


typedef struct _ART2_IO_REQ_HEADER
{
	ULONG 	RequestId;
	ULONG 	InputContentLength;

}ART2_IO_REQ_HEADER, *PART2_IO_REQ_HEADER;

typedef struct _ART2_MEM_CONTEXT
{
	ULONG 	Address;
	ULONG 	Length;
	
}ART2_MEM_CONTEXT, *PART2_MEM_CONTEXT;

typedef struct _ART2_REG_CONTEXT
{
	ULONG 	Address;
	ULONG 	Param;
	
}ART2_REG_CONTEXT, *PART2_REG_CONTEXT;

typedef struct _ART2_PCI_CFG_CONTEXT
{
	ULONG 	Offset;
	ULONG 	Length;

}ART2_PCI_CFG_CONTEXT, *PART2_PCI_CFG_CONTEXT;

#endif

