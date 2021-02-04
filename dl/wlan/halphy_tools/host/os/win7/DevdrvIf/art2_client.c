/*++

Copyright (c) 2012 Qualcomm-Atheros Communications Inc.  

    All rights reserved.

Module Name:

	art2_client.c

Abstract:

    functions ART2 specific

Revision History:

    2012-04-10 created by Wade Song

Notes:

--*/


#include <basetyps.h>
#include <stdlib.h>
#include <wtypes.h>
#include <setupapi.h>
#include <initguid.h>
#include <stdio.h>
#include <string.h>
#include "art2_shared.h"
#include "art2_client.h"
#include "device_msg.h"


#define GLOBAL_IOCTL_BUFFER_LENGTH (1024*200)
#define GLOBAL_INPUT_BUFFER_LENGTH 1024

UCHAR GlobalIoctlBuffer[GLOBAL_IOCTL_BUFFER_LENGTH];
UCHAR GlobalInputBuffer[GLOBAL_INPUT_BUFFER_LENGTH];
PART2_IO_REQ_HEADER gArt2IoReqHeader = (PART2_IO_REQ_HEADER)GlobalIoctlBuffer;

BOOL GlobalConfig_PerformDevIoctl = TRUE;

INT wmain()
{
	HANDLE				DevHandle = NULL;
	DWORD				dwRet = ERROR_SUCCESS;
	PART2_IO_REQ_HEADER pIoReqHeader = NULL;

	/* Target offset of hi_boadr_data */
	ULONG 				TargetMemAddress = 0x400854;
	ULONG 				TargetMemLength = 4;

	/* Should be 0x401cb0 */
	ULONG 				TargetMemContent;

	/* PCIE_INTR_CAUSE (0x900C) */
	ULONG 				TargetRegAddress = 0x900C;
	ULONG 				TargetRegContent;
	ULONG 				BytesRet;

#ifdef ART2_CLIENT_FOR_MDK
	anwiReturnContext 	MdkRetContext;
	pAnwiOutClientInfo 	pOutCliInfo;
#endif

	dwRet = OpenArt2Device( &DevHandle );

	if( ERROR_SUCCESS != dwRet )
	{
		printf("Failed to open ART2 device, error = %08X\n", dwRet );		
		goto ErrorEx;
	}

	if( NULL == DevHandle )
	{
		printf("OpenArt2Device() returns invalid device handle\n");
		goto ErrorEx;
	}

	printf(
		"Performing target memory reading, addr: %08X, len: %d.\n"
		"Push any key to continue...\n",
		TargetMemAddress,
		TargetMemLength
		);

	getchar();

	dwRet = Art2ReadTargetMem(
				DevHandle,
				TargetMemAddress,
				TargetMemLength,
				(PUCHAR)&TargetMemContent,
				&BytesRet
				);

	if( ERROR_SUCCESS != dwRet )
	{
		goto ErrorEx;
	}

	printf(
		"Performing target memory writing, addr: %08X, len: %d, content: %08X.\n"
		"Push any key to continue...\n",
		TargetMemAddress,
		TargetMemLength,
		TargetMemContent
				);

	getchar();
	
	dwRet = Art2WriteTargetMem(
				DevHandle,
				TargetMemAddress,
				TargetMemLength,
				(PUCHAR)&TargetMemContent
				);

	if( ERROR_SUCCESS != dwRet )
	{
		goto ErrorEx;
	}

	printf(
		"Performing target register reading, addr: %08X.\n"
		"Push any key to continue...\n",
		TargetRegAddress,
		sizeof(ULONG),
		&TargetRegContent
		);

	getchar();

	dwRet = Art2ReadTargetRegister(
					DevHandle,
				TargetRegAddress,
				&TargetRegContent
					);

	if( ERROR_SUCCESS != dwRet )
	{
		goto ErrorEx;
	}

	printf(
		"Performing target register writing, addr: %08X, content: %08X.\n"
		"Push any key to continue...\n",
		TargetRegAddress,
		TargetRegContent
		);

	getchar();

	dwRet = Art2WriteTargetRegister(
				DevHandle,
				TargetRegAddress,
				TargetRegContent
				);

	if( ERROR_SUCCESS != dwRet )
	{
		goto ErrorEx;
	}

#ifdef ART2_CLIENT_FOR_MDK
	printf(
		"MDK client getting device info...\n"
		"Push any key to continue...\n"
		);

	getchar();

	memset( &MdkRetContext, 0, sizeof(anwiReturnContext) );
	
	dwRet = MdkGetClientInfo(
				DevHandle,
				&MdkRetContext
				);
	
	pOutCliInfo = (pAnwiOutClientInfo)MdkRetContext.context;

	printf(
		"MDK device op returns\n"
		"ARegPhyAddr: %p, ARegRange: %d, ARegVirAddr: %p\n"
		"IRQ level: %d, NumBars: %d\n"
		"RegPhyAddr: %p, RegRange: %d, RegVirAddr: %p\n"
		"ResType: %d.\n",
		pOutCliInfo->aregPhyAddr,
		pOutCliInfo->aregRange,
		pOutCliInfo->aregVirAddr,
		pOutCliInfo->irqLevel,
		pOutCliInfo->numBars,
		pOutCliInfo->regPhyAddr,
		pOutCliInfo->regRange,
		pOutCliInfo->regVirAddr,
		pOutCliInfo->res_type
		);

	printf(
		"Kernel mapped memory info list:\n"
		);

#ifdef ART2_MDK_MEM_ALLOC_FLEX
	for( i = 0; i < MAX_NUM_MEM_MAPS; i++ )
	{
		printf(
			"MemPhyAddr: %p, MemSize: %d, MemVirAddr: %p.\n",
			pOutCliInfo->k2u_map[i].memPhyAddr,
			pOutCliInfo->k2u_map[i].memSize,
			pOutCliInfo->k2u_map[i].memVirAddr
			);
	}
#else
	printf(
		"MemPhyAddr: %p, MemSize: %d, MemVirAddr: %p.\n",
		pOutCliInfo->memPhyAddr,
		pOutCliInfo->memSize,
		pOutCliInfo->memVirAddr
		);
#endif //ART2_MDK_MEM_ALLOC_FLEX

#else
		printf(
		"Triggering firmware downloading sequence...\n"
		"Push any key to continue...\n"
			);

	getchar();

	dwRet = Art2StartFwDownloading(
				DevHandle,
				ART2_FW_DL_BOARD_DATA |
				ART2_FW_DL_UTF
				);

	if( ERROR_SUCCESS != dwRet )
	{
		goto ErrorEx;
	}

	printf(
		"Concluding BMI boot sequence...\n"
		"Push any key to continue...\n"
		);

	getchar();

	dwRet = Art2ConcludeBmi(DevHandle);

#endif //ART2_CLIENT_FOR_MDK

ErrorEx:

	if( DevHandle )
	{
		CloseArt2Device( DevHandle );
	}
}

DWORD 
ReadArt2Device( 
	HANDLE 	DevHandle, 
	PUCHAR 	InputBuffer, 
	ULONG 	InputBufferLength 
	)
{
	DWORD dwRet = ERROR_SUCCESS;
	/*
		Not implemented due to ART2 does not require
		reading data/event from device through ReadFile() API
	*/
	return dwRet;
}

DWORD 
WriteArt2Device( 
	HANDLE 	DevHandle, 
	PUCHAR 	OutputBuffer, 
	ULONG 	OutputBufferLength 
	)
{
	DWORD dwRet = ERROR_SUCCESS;
	/*
		Not implemented due to ART2 does not require
		wirting data/commands to device through WriteFile() API
	*/
	return dwRet;
}

PUCHAR 
PrepareIoctlCmdBuffer( 
	DWORD 		IoReqCode, 
	PUCHAR 		CustomData, 
	ULONG 		CustomDataBufferLength
	)
{
	DWORD dwRet = ERROR_SUCCESS;
	PART2_IO_REQ_HEADER IoReqHeader = NULL;

	if( (NULL == CustomData) )
	{
		return NULL;
	}

	IoReqHeader = (PART2_IO_REQ_HEADER)CustomData;
	IoReqHeader->RequestId = IoReqCode;
	IoReqHeader->InputContentLength = 
		CustomDataBufferLength + sizeof(ART2_IO_REQ_HEADER);

	return (PUCHAR)(IoReqHeader + 1);
}


DWORD
Art2ReadTargetMem(
	HANDLE	DevHandle,
	ULONG 	Address,
	ULONG 	Length,
	PUCHAR 	ReadBuffer,
	PULONG	BytesRet
	)
{
	PART2_MEM_CONTEXT mem_context;

	mem_context = (PART2_MEM_CONTEXT)PrepareIoctlCmdBuffer(
		ART2_REQ_ID_READ_MEM,
		GlobalIoctlBuffer,
		sizeof(ART2_MEM_CONTEXT)
		);

	mem_context->Address = Address;
	mem_context->Length = Length;

	return Art2DeviceIoctl(
				DevHandle,
				gArt2IoReqHeader->RequestId,
				(PUCHAR)gArt2IoReqHeader,
				gArt2IoReqHeader->InputContentLength,
				(PUCHAR)ReadBuffer,
				Length,
				BytesRet
				);
}

DWORD
Art2WriteTargetMem(
	HANDLE 	DevHandle,
	ULONG 	Address,
	ULONG	Length,
	PUCHAR 	WriteBuffer
	)
{
	PART2_MEM_CONTEXT mem_context;

	mem_context = (PART2_MEM_CONTEXT)PrepareIoctlCmdBuffer(
		ART2_REQ_ID_WRITE_MEM,
		GlobalIoctlBuffer,
		sizeof(ART2_MEM_CONTEXT) + Length
		);

	mem_context->Address = Address;
	mem_context->Length = Length;

	memcpy( 
		(PUCHAR)(mem_context+1),
		WriteBuffer,
		Length
		);

	return Art2DeviceIoctl(
				DevHandle,
				gArt2IoReqHeader->RequestId,
				(PUCHAR)gArt2IoReqHeader,
				gArt2IoReqHeader->InputContentLength,
				NULL,
				0,
				NULL
				);
}

DWORD
Art2ReadTargetRegister(
	HANDLE 	DevHandle,
	ULONG 	Address,
	PULONG 	ReadBuffer
	)
{
	PART2_REG_CONTEXT reg_context;
	ULONG BytesRet = 0;

	reg_context = (PART2_REG_CONTEXT)PrepareIoctlCmdBuffer(
		ART2_REQ_ID_READ_REG,
		GlobalIoctlBuffer,
		sizeof(ART2_REG_CONTEXT)
		);

	reg_context->Address = Address;
	reg_context->Param = sizeof(ULONG);

	return Art2DeviceIoctl(
				DevHandle,
				gArt2IoReqHeader->RequestId,
				(PUCHAR)gArt2IoReqHeader,
				gArt2IoReqHeader->InputContentLength,
				(PUCHAR)ReadBuffer,
				sizeof(ULONG),
				&BytesRet
				);
}

DWORD
Art2WriteTargetRegister(
	HANDLE 	DevHandle,
	ULONG 	Address,
	ULONG 	RegContent
	)
{
	PART2_REG_CONTEXT reg_context;

	reg_context = (PART2_REG_CONTEXT)PrepareIoctlCmdBuffer(
		ART2_REQ_ID_WRITE_REG,
		GlobalIoctlBuffer,
		sizeof(ART2_REG_CONTEXT)
		);

	reg_context->Address = Address;
	reg_context->Param = RegContent;

	return Art2DeviceIoctl(
				DevHandle,
				gArt2IoReqHeader->RequestId,
				(PUCHAR)gArt2IoReqHeader,
				gArt2IoReqHeader->InputContentLength,
				NULL,
				0,
				NULL
				);
	
}

DWORD
Art2StartFwDownloading(
	HANDLE 	DevHandle,
	DWORD 	FwDlFlags
	)
{
	PDWORD Flags = (PDWORD)PrepareIoctlCmdBuffer(
		ART2_REQ_ID_DL_FW,
		GlobalIoctlBuffer,
		sizeof(FwDlFlags)
		);

	*Flags = FwDlFlags;
	
	return Art2DeviceIoctl(
				DevHandle,
				gArt2IoReqHeader->RequestId,
				(PUCHAR)gArt2IoReqHeader,
				gArt2IoReqHeader->InputContentLength,
				NULL,
				0,
				NULL
				);	
}

DWORD
Art2ConcludeBmi(
	HANDLE 	DevHandle
	)
{
	PrepareIoctlCmdBuffer(
		ART2_REQ_ID_BMI_DONE,
		GlobalIoctlBuffer,
		0
		);

	return Art2DeviceIoctl(
				DevHandle,
				gArt2IoReqHeader->RequestId,
				(PUCHAR)gArt2IoReqHeader,
				gArt2IoReqHeader->InputContentLength,
				NULL,
				0,
				NULL
				);	
}

DWORD
Art2ReadPciConfigSpace(
	HANDLE	DevHandle,
	ULONG 	Offset
	)
{
	DWORD Data = 0;
	ULONG BytesRet = 0;
	DWORD dwRet;
	PART2_PCI_CFG_CONTEXT cfg_context;
	
	cfg_context = (PART2_PCI_CFG_CONTEXT)PrepareIoctlCmdBuffer(
		ART2_REQ_ID_READ_CFG,
		GlobalIoctlBuffer,
		sizeof(ART2_PCI_CFG_CONTEXT)
		);

	cfg_context->Offset = Offset;
	cfg_context->Length = sizeof(Data);
	
	dwRet = Art2DeviceIoctl(
				DevHandle,
				ART2_REQ_ID_READ_CFG,
				(PUCHAR)gArt2IoReqHeader,
				gArt2IoReqHeader->InputContentLength,
				(PUCHAR)&Data,
				sizeof(Data),
				&BytesRet
				);

	return Data;
}

DWORD
Art2WritePciConfigSpace(
	HANDLE 	DevHandle,
	ULONG 	Offset,
	ULONG 	Data
	)
{
	DWORD dwRet = ERROR_SUCCESS;
	PART2_PCI_CFG_CONTEXT cfg_context;

	cfg_context = (PART2_PCI_CFG_CONTEXT)PrepareIoctlCmdBuffer(
		ART2_REQ_ID_WRITE_CFG,
		GlobalIoctlBuffer,
		sizeof(ART2_PCI_CFG_CONTEXT) + sizeof(Data)
		);

	cfg_context->Offset = Offset;
	cfg_context->Length = sizeof(Data);
	*(PULONG)(cfg_context+1) = Data;

	dwRet = Art2DeviceIoctl(
				DevHandle,
				ART2_REQ_ID_WRITE_CFG,
				(PUCHAR)gArt2IoReqHeader,
				gArt2IoReqHeader->InputContentLength,
				NULL,
				0,
				NULL
				);

	return dwRet;
}

DWORD
MdkGetClientInfo(
	HANDLE 				DevHandle,
	pAnwiReturnContext 	RetContext
	)
{
	BOOL 	bRet;
	ULONG 	BytesReturned = 0;
	anwiInClientInfo 	InCliInfo;

	memset( &InCliInfo, 0, sizeof(anwiInClientInfo) );
	
	bRet = DeviceIoControl( DevHandle, 
							IOCTL_ANWI_GET_CLIENT_INFO,
							&InCliInfo,
							sizeof(anwiInClientInfo),
							RetContext,
							sizeof(anwiReturnContext),
							&BytesReturned,
							NULL );

	return bRet ? ERROR_SUCCESS : GetLastError();
}

DWORD
Art2GetInitStatus(
	HANDLE	DevHandle
	)
{
	DWORD Data = 0;
	ULONG BytesRet = 0;
	DWORD dwRet;
	PART2_PCI_CFG_CONTEXT cfg_context;
	
	PrepareIoctlCmdBuffer(
		ART2_REQ_ID_GET_INIT_STAT,
		GlobalIoctlBuffer,
		0
		);
	
	dwRet = Art2DeviceIoctl(
				DevHandle,
				ART2_REQ_ID_GET_INIT_STAT,
				(PUCHAR)gArt2IoReqHeader,
				gArt2IoReqHeader->InputContentLength,
				(PUCHAR)&Data,
				sizeof(Data),
				&BytesRet
				);

	return Data;
}