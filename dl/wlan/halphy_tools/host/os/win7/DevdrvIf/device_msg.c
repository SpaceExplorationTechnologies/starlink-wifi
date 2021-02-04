#include <windows.h>
#include <winioctl.h>
#include <setupapi.h>
#include <Dbt.h>
#include <stdio.h>
#include <process.h>
#include <tchar.h>

#include "art2_shared.h"
#include "device_msg.h"
#include "os_if.h"


#define WM_CREATE_INIT WM_USER + 101

static HANDLE gRegHandle1 = INVALID_HANDLE_VALUE;
static HANDLE gRegHandle2 = INVALID_HANDLE_VALUE; //not used
static LPTSTR gWndName = "DeviceMsgWindow";
static HWND gHwnd = NULL;
static DWORD gThreadId = 0;

HANDLE ghDevArrivalEvent = NULL;
HANDLE DevHandle = NULL;

DWORD WaitForDeviceReady()
{
	DWORD dwRet;
	
	if( ghDevArrivalEvent != NULL )
	{
		dwRet = WaitForSingleObjectEx( ghDevArrivalEvent, INFINITE, TRUE );
		if( WAIT_OBJECT_0 == dwRet )
		{
			//printf("Device is ready!\n");
			return ERROR_SUCCESS;
		}

		printf("Unexpected error status: %08X.\n", dwRet);
		return dwRet;
	}

	/* Should never get here */
	printf("global device arrival event empty!!\n");
	return ERROR_NOT_ENOUGH_MEMORY;
}

BOOL DeviceExists()
{
	DWORD dwRet;

	if( ghDevArrivalEvent != NULL )
	{
		dwRet = WaitForSingleObject( ghDevArrivalEvent, 0 );
		if( WAIT_OBJECT_0 == dwRet )
		{
			printf("%08X returned by WaitForSingleObject\n", dwRet);
			return TRUE;
		}

		printf("Error status: %08X, device unplugged?!\n", dwRet);
		return FALSE;
	}

	/* Should never get here */
	printf("Fatal error: global device arrival event empty!!\n");
	return FALSE;

}

LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	DWORD dwRet;

	switch(msg)
	{
	case WM_CREATE_INIT:
		{
			 //use DBT_DEVTYP_DEVICEINTERFACE:ART2_DEV_INF_GUID to register
			DEV_BROADCAST_DEVICEINTERFACE dbcc = {0};
			dbcc.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
			dbcc.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
			dbcc.dbcc_classguid = ART2_DEV_INF_GUID; 	
			printf("WM_CREATE_INIT received!\n");
			gRegHandle1 = RegisterDeviceNotification(wnd, &dbcc, DEVICE_NOTIFY_WINDOW_HANDLE );
			 //Use device handle to register
			//DEV_BROADCAST_HANDLE dbce = {0};
			//dbce.dbch_size = sizeof(dbce);
			//dbce.dbch_handle = (HANDLE)wParam;
			//dbce.dbch_devicetype = DBT_DEVTYP_HANDLE;
			//gRegHandle2 = RegisterDeviceNotification(wnd, &dbce, DEVICE_NOTIFY_WINDOW_HANDLE);

		}
		break;
	case WM_DEVICECHANGE:
		{
			switch(wParam)
			{
			case DBT_CUSTOMEVENT:
				{
					PDEV_BROADCAST_HDR _temp = (PDEV_BROADCAST_HDR)lParam;
					if (_temp->dbch_devicetype == DBT_DEVTYP_HANDLE)
					{

					}
				}
				break;
			case DBT_DEVICEARRIVAL:
				{
					PDEV_BROADCAST_DEVICEINTERFACE pDevInterface = (PDEV_BROADCAST_DEVICEINTERFACE)lParam;
					if (pDevInterface->dbcc_devicetype == DBT_DEVTYP_DEVICEINTERFACE && IsEqualGUID(&pDevInterface->dbcc_classguid,&ART2_DEV_INF_GUID))
					{
						printf("DBT_DEVICEARRIVAL received!\n");

						if( DevHandle ) 
						{
							printf("Device opened before, closing it now...\n");
							CloseArt2Device( DevHandle );
							DevHandle = NULL;
						}

						dwRet = OpenArt2Device( &DevHandle );
						if( ERROR_SUCCESS != dwRet )
						{
							printf("Failed to open ART2 device, error = %08X\n", dwRet );
							return dwRet;
						}

						if( NULL == DevHandle )
						{
							printf("OpenArt2Device() returns invalid device handle\n");
							return dwRet;
						}

						if( ghDevArrivalEvent != INVALID_HANDLE_VALUE )
						{
							printf("Device plugged-in after plugging out.. Exiting nart\n");
							SetEvent( ghDevArrivalEvent );
							exit(-1);
						}
					}
				}
				break;
			case DBT_DEVICEQUERYREMOVE:
				{

				}
				break;
			case DBT_DEVICEREMOVECOMPLETE:
				{
					PDEV_BROADCAST_DEVICEINTERFACE pDevInterface = (PDEV_BROADCAST_DEVICEINTERFACE)lParam;
					if (pDevInterface->dbcc_devicetype == DBT_DEVTYP_DEVICEINTERFACE && IsEqualGUID(&pDevInterface->dbcc_classguid,&ART2_DEV_INF_GUID))
					{
						printf("DBT_DEVICEREMOVECOMPLETE received!\n");
						ResetEvent( ghDevArrivalEvent );
						if( DevHandle)
						{
							printf("Closing ART2 device handle!\n");
							CloseArt2Device(DevHandle);
							DevHandle = NULL;
						}
					}
				}
				break;
			default:
				break;
			}		
		}
		break;
	case WM_CLOSE:
		{
			if(gRegHandle1 != INVALID_HANDLE_VALUE)
			{
				UnregisterDeviceNotification(gRegHandle1);
			}
			if(gRegHandle2 != INVALID_HANDLE_VALUE)
			{
				UnregisterDeviceNotification(gRegHandle2);
			}
		}
		break;
	default:
		return DefWindowProc(wnd, msg, wParam, lParam);
	}

	return 1;
}

unsigned __stdcall ThreadProc( void * param)
{		
	WNDCLASSEX wcex = {0};
	WORD wrd;
	DWORD err;
	HANDLE hStartEvent;
	MSG _msg;

	printf("Setting up device notification window object...\n");
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hInstance = NULL;
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = "DeviceMsg";
	wcex.lpszClassName = gWndName;
	wrd = RegisterClassEx(&wcex);
	err = GetLastError();
	gHwnd = CreateWindow(gWndName, "", WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, NULL, NULL);
	err = GetLastError();
	if(gHwnd != NULL)
	{
		ShowWindow(gHwnd, SW_HIDE);
		UpdateWindow(gHwnd);
	}
	hStartEvent = (HANDLE)param;
	SetEvent(hStartEvent);
	
	printf("Entering message loop...\n");
	while(GetMessage(&_msg, 0, 0, 0))
	{
		switch(_msg.message)
		{
		case WM_CLOSE:
			SendMessage(gHwnd, WM_CLOSE, 0, 0);
			return 0;
		default:
			TranslateMessage(&_msg);
			DispatchMessage(&_msg);
			break;
		}
	}

	return 0;
}

void InitDevMsg( HANDLE hDevArrivalEvent )
{
	HANDLE hStartEvent = INVALID_HANDLE_VALUE;
	HANDLE hThread;
	
	hStartEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if( INVALID_HANDLE_VALUE == hStartEvent )
	{
		return;
	}

	printf("Launching device event monitor thread...\n");
	hThread = (HANDLE)_beginthreadex( 
				NULL,				// security
				0,					// stack_size
				ThreadProc,			// unsigned ( __stdcall *start_address )( void * )
				(LPVOID)hStartEvent,// arglist
				0,					// initflag
				NULL				// thrdaddr 
				);
	if(hThread != NULL)
	{
		printf("Monitor thread handle obtained, resuming thread...\n");
		//ResumeThread(hThread);
		//CloseHandle(hThread);
	}
	else
	{
		printf("Unable to create the thread.");
	}

	if(hStartEvent != INVALID_HANDLE_VALUE)
	{
		WaitForSingleObjectEx(hStartEvent, 10000, TRUE);
		printf("Monitor thread started.\n");
		if(gHwnd != NULL)
		{
			printf("Sending initialize message.\n");
			SendMessage(gHwnd, WM_CREATE_INIT, (WPARAM)NULL, (LPARAM)NULL);
		}
	}
	CloseHandle(hStartEvent);
}

void UninitDevMsg()
{
	PostThreadMessage(gThreadId, WM_CLOSE, 0, 0);
}

static DWORD OpenArt2DeviceOld( PHANDLE OutputHandle )
{
	HANDLE		handle = NULL;
	HDEVINFO	hardwareDeviceInfo;
	DWORD		dwRet = ERROR_SUCCESS;
	BOOL		bRet;

	SP_DEVICE_INTERFACE_DATA deviceInterfaceData;


    hardwareDeviceInfo = SetupDiGetClassDevs (
							(LPGUID)&ART2_DEV_INF_GUID,
							NULL, // Define no enumerator (global)
							NULL, // Define no
							(DIGCF_PRESENT |		// Only Devices present
							DIGCF_DEVICEINTERFACE)	// Function class devices.
							); 

    if(INVALID_HANDLE_VALUE == hardwareDeviceInfo)
    {
		dwRet = GetLastError();
        printf("SetupDiGetClassDevs failed: %x\n", dwRet);
        return dwRet;
    }

	deviceInterfaceData.cbSize = sizeof (SP_DEVICE_INTERFACE_DATA);

	bRet = SetupDiEnumDeviceInterfaces (hardwareDeviceInfo,
										0, // No care about specific PDOs
										(LPGUID)&ART2_DEV_INF_GUID,
										0, //
										&deviceInterfaceData 
										);
	if (bRet) 
	{
		bRet = OpenBusInterface(hardwareDeviceInfo, &deviceInterfaceData, OutputHandle);
    } 
	else if (ERROR_NO_MORE_ITEMS == GetLastError()) 
	{
        printf( "Error:Interface ART2_DEV_INF_GUID is not registered\n" );
		dwRet = ERROR_NO_MORE_ITEMS;
    }

	SetupDiDestroyDeviceInfoList (hardwareDeviceInfo);

	return dwRet;
}

DWORD OpenArt2Device( PHANDLE OutputHandle )
{
	DWORD		dwRet = ERROR_SUCCESS;
    HANDLE      hHandle;
	TCHAR		DevName[ 256 ];
    int         i;

	for (i = 0; i < 16; i++)
	{
		_stprintf_s( DevName, _countof(DevName), _T("\\\\.\\ATH_WIFIDEV.%02d"), i);
    	hHandle = CreateFile(
    		DevName,
    		GENERIC_READ | GENERIC_WRITE,
    		0,
    		NULL,
    		OPEN_EXISTING,
    		0,
    		NULL
    		);
    	if( hHandle == INVALID_HANDLE_VALUE )
    	{
            dwRet = GetLastError();
            printf("Open device %02d failed: 0x%x\n", i, dwRet);
    	}
        else
        {
            dwRet = ERROR_SUCCESS;
        	printf( "WLAN device opened!\n");
        	if( OutputHandle )
        	{
        		*OutputHandle = hHandle;
        	}
            break;
        }
	}
    if (dwRet != ERROR_SUCCESS)
    {
        printf("Error in opening device %s, try anopther device\n", DevName);
		dwRet = OpenArt2DeviceOld(OutputHandle);
    }
	return dwRet;
}


DWORD CloseArt2Device( HANDLE DevHandle )
{
	DWORD dwRet = ERROR_SUCCESS;

	CloseHandle( DevHandle );

	return dwRet ;
}

DWORD 
Art2DeviceIoctl( 
	HANDLE 		DevHandle, 
	DWORD 		IoctlCode, 
	PUCHAR 		CustomData, 
	ULONG 		CustomDataLength,
	PUCHAR 		OutputBuffer,
	ULONG 		OutputBufferLength,
	PULONG 		BytesRet
	)
{
	DWORD dwRet = ERROR_SUCCESS;
	BOOL bRet;
	ULONG BytesReturned = 0;

	WaitForDeviceReady();

	if( NULL == DevHandle || 
		0 == IoctlCode ||
		(NULL != CustomData && 0 == CustomDataLength) ||
		(NULL == CustomData && 0 != CustomDataLength) )
	{
		return ERROR_INVALID_PARAMETER;
	}

	bRet = DeviceIoControl( DevHandle, 
							ART2_DEV_IOCTL_REQUEST,
							CustomData,
							CustomDataLength,
							OutputBuffer,
							OutputBufferLength,
							&BytesReturned,
							NULL );

	if( FALSE == bRet )
	{
		dwRet = GetLastError();
		if (dwRet != ERROR_GEN_FAILURE)	//don't know why this errors keeps displayed, but the device still funstions after several tries.
		{
			printf("Failed to perform device I/O control, error = %08X\n", dwRet);
		}
		return dwRet;
	}
#ifdef _DEBUG
	//printf("Device I/O control finished, bytes ret: %d\n", BytesReturned);
#endif

	if( BytesRet )
	{
		*BytesRet = BytesReturned;
	}

	return dwRet;
}

BOOLEAN
OpenBusInterface (
    __in    HDEVINFO                    HardwareDeviceInfo,
    __in	PSP_DEVICE_INTERFACE_DATA   DeviceInterfaceData,
	__out	PHANDLE						OutputHandle
    )
{
    HANDLE                              file;
    PSP_DEVICE_INTERFACE_DETAIL_DATA    deviceInterfaceDetailData = NULL;
    ULONG                               predictedLength = 0;
    ULONG                               requiredLength = 0;

    //
    // Allocate a function class device data structure to receive the
    // information about this particular device.
    //

    SetupDiGetDeviceInterfaceDetail (
            HardwareDeviceInfo,
            DeviceInterfaceData,
            NULL, // probing so no output buffer yet
            0, // probing so output buffer length of zero
            &requiredLength,
            NULL); // not interested in the specific dev-node

	if( ERROR_INSUFFICIENT_BUFFER != GetLastError() ) 
	{
        printf(
			"Error in SetupDiGetDeviceInterfaceDetail%d\n",
            GetLastError()
			);
        return FALSE;
    }

    predictedLength = requiredLength;

    deviceInterfaceDetailData = malloc (predictedLength);

    if(deviceInterfaceDetailData) {
        deviceInterfaceDetailData->cbSize =
                      sizeof (SP_DEVICE_INTERFACE_DETAIL_DATA);
    } else {
        printf("Couldn't allocate %d bytes for device interface details.\n", predictedLength);
        return FALSE;
    }


    if (! SetupDiGetDeviceInterfaceDetail (
               HardwareDeviceInfo,
               DeviceInterfaceData,
               deviceInterfaceDetailData,
               predictedLength,
               &requiredLength,
               NULL)) {
        printf("Error in SetupDiGetDeviceInterfaceDetail\n");
        free (deviceInterfaceDetailData);
        return FALSE;
    }

    printf("Opening %ws\n", deviceInterfaceDetailData->DevicePath);

    file = CreateFile ( deviceInterfaceDetailData->DevicePath,
                        GENERIC_READ, // Only read access
                        0, // FILE_SHARE_READ | FILE_SHARE_WRITE
                        NULL, // no SECURITY_ATTRIBUTES structure
                        OPEN_EXISTING, // No special create flags
                        0, // No special attributes
                        NULL); // No template file

    if (INVALID_HANDLE_VALUE == file) {
        printf("CreateFile failed: 0x%x", GetLastError());
        free (deviceInterfaceDetailData);
        return FALSE;
    }

    printf("Bus interface opened!!!\n");

	if( OutputHandle )
	{
		*OutputHandle = file;
	}

    free (deviceInterfaceDetailData);
    return TRUE;
}

