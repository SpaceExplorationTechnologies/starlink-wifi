//#pragma once

#include <Windows.h>
#include "anwiioctl.h"


void InitDevMsg(HANDLE hDevArrivalEvent);
void UninitDevMsg();
DWORD WaitForDeviceReady();
BOOL DeviceExists();

DWORD OpenArt2Device( PHANDLE OutputHandle );
DWORD CloseArt2Device( HANDLE DevHandle );

DWORD 
Art2DeviceIoctl(	
	HANDLE 	DevHandle, 
	DWORD 	IoctlCode, 
	PUCHAR 	CustomData, 
	ULONG 	CustomDataLength,
	PUCHAR 	OutputBuffer,
	ULONG 	OutputBufferLength,
	PULONG 	BytesRet
	);

BOOLEAN
OpenBusInterface (
    __in	HDEVINFO                    HardwareDeviceInfo,
    __in    PSP_DEVICE_INTERFACE_DATA   DeviceInterfaceData,
	__out	PHANDLE						OutputHandle
    );
