/*++

Copyright (c) 2012 Qualcomm-Atheros Communications Inc.  

    All rights reserved.

Module Name:

	art2_client.h

Abstract:

    functions ART2 specific

Revision History:

    2012-04-10 created by Wade Song

Notes:

--*/

#ifndef _ART2_CLIENT_
#define _ART2_CLIENT_

#include <Windows.h>
#include "anwiioctl.h"

DWORD
Art2ReadTargetMem(
	HANDLE	DevHandle,
	ULONG 	Address,
	ULONG 	Length,
	PUCHAR 	ReadBuffer,
	PULONG	BytesRet
	);

DWORD
Art2WriteTargetMem(
	HANDLE 	DevHandle,
	ULONG 	Address,
	ULONG	Length,
	PUCHAR 	WriteBuffer
	);

DWORD
Art2ReadTargetRegister(
	HANDLE 	DevHandle,
	ULONG 	Address,
	PULONG 	ReadBuffer
	);

DWORD
Art2WriteTargetRegister(
	HANDLE 	DevHandle,
	ULONG 	Address,
	ULONG 	RegContent
	);

DWORD
Art2StartFwDownloading(
	HANDLE 	DevHandle,
	DWORD 	FwDlFlags
	);

DWORD
Art2ConcludeBmi(
	HANDLE 	DevHandle
	);


DWORD
Art2ReadPciConfigSpace(
	HANDLE	DevHandle,
	ULONG 	Offset
	);

DWORD
Art2WritePciConfigSpace(
	HANDLE 	DevHandle,
	ULONG 	Offset,
	ULONG 	Data
	);

	
DWORD 
ReadArt2Device( 
	HANDLE 	DevHandle, 
	PUCHAR 	InputBuffer, 
	ULONG 	InputBufferLength 
	);
	
DWORD 
WriteArt2Device( 
	HANDLE 	DevHandle, 
	PUCHAR 	OutputBuffer, 
	ULONG 	OutputBufferLength 
	);

PUCHAR
PrepareIoctlCmdBuffer( 
	DWORD 	IoReqCode, 
	PUCHAR 	CustomData, 
	ULONG 	CustomDataBufferLength 
	);

DWORD
MdkGetClientInfo(
	HANDLE 				DevHandle,
	pAnwiReturnContext 	ClientInfo
	);

DWORD
Art2GetInitStatus(
	HANDLE	DevHandle
	);


#endif //_ART2_CLIENT_