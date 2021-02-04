//#include <sys/types.h>
//#include <sys/file.h>
//#include <sys/ioctl.h>
//#include <sys/socket.h>
//#include <linux/types.h>
//#include <linux/if.h>
//#include <linux/wireless.h>

#include <basetyps.h>
#include <stdlib.h>
#include <wtypes.h>
#include <setupapi.h>
#include <initguid.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>
//#include <getopt.h>
//#include <err.h>
#include <errno.h>
#include <time.h>
#include <Windows.h>
#include <winioctl.h>

#include "art2_client.h"
#include "os_if.h"
#include "device_msg.h"
#include "art2_shared.h"

/*
 * Linux uses __BIG_ENDIAN and __LITTLE_ENDIAN while BSD uses _foo
 * and an explicit _BYTE_ORDER.  Sorry, BSD got there first--define
 * things in the BSD way...
 */
#ifndef _LITTLE_ENDIAN
#define _LITTLE_ENDIAN  1234    /* LSB first: i386, vax */
#endif
#ifndef _BIG_ENDIAN
#define _BIG_ENDIAN     4321    /* MSB first: 68000, ibm, net */
#endif
//#include <asm/byteorder.h>
#if defined(__LITTLE_ENDIAN)
#define _BYTE_ORDER     _LITTLE_ENDIAN
#elif defined(__BIG_ENDIAN)
#define _BYTE_ORDER     _BIG_ENDIAN
#else
//#error "Please fix asm/byteorder.h"
#endif

//#include <ieee80211_external.h>

#define ATH_XIOCTL_UNIFIED_UTF_CMD      0x1000
#define ATH_XIOCTL_UNIFIED_UTF_RSP      0x1001

#define CMD_TIMEOUT   (5 *1000)	// 10s

typedef struct {
    int sock;
    //struct ifreq ifr;
    //char ifname[IFNAMSIZ];
    void (*rx_cb)(void *buf);
    unsigned char initialized;
    unsigned char timeout;
    //struct sigevent sev;
    //timer_t timer;
} INIT_STRUCT;

static INIT_STRUCT initCfg;
static unsigned char responseBuf[2048+8];
static UINT timerId = 0;
static UINT gUtfCmdEvtDumpEnabled = 0;

extern HANDLE DevHandle;
extern HANDLE ghDevArrivalEvent;


//static void timer_expire(union sigval sig)
void CALLBACK timer_expire(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
    printf("Timer Expired..\n");
    initCfg.timeout = 1;
}

int cmd_set_timer()
{
	timerId = SetTimer(NULL, 0, CMD_TIMEOUT, timer_expire);
	if (timerId == 0)
	{
		printf ("No timer is available.\n");
		return -1;
	}
    return 0;
}

int cmd_stop_timer()
{
	KillTimer(NULL, timerId);
    return 0;
}

DEVDRVIF_API void *cmd_getDevHandle ()
{
	return DevHandle;
}

DWORD WINAPI InitThreadProc(LPVOID param)
{
	return probe_device();
}

BOOL WINAPI DllMain(
  __in  HINSTANCE hinstDLL,
  __in  DWORD fdwReason,
  __in  LPVOID lpvReserved
)
{
	HANDLE hThread;

	if( DLL_PROCESS_ATTACH == fdwReason )
	{
		if( gUtfCmdEvtDumpEnabled )
		{
			prepare_for_cmd_evt_dump();
		}
		hThread = CreateThread(
				NULL,					//LPSECURITY_ATTRIBUTES 
				0,						//dwStackSize
				InitThreadProc,				//lpStartAddress
				NULL,	//lpParameter
				0/*CREATE_SUSPENDED*/,	//dwCreationFlags
				NULL				//lpThreadId 
				);
		CloseHandle(hThread);
		return TRUE;
	}
	else if( DLL_PROCESS_DETACH == fdwReason )
	{
		if( gUtfCmdEvtDumpEnabled )
		{
			clearup_for_cmd_evt_dump();
		}
        return TRUE;
	}
}

DEVDRVIF_API DWORD probe_device()
{
	DWORD dwRet;

	ghDevArrivalEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if( NULL == ghDevArrivalEvent )
	{
		printf("Failed to create device arrival event object.\n");
		return -1;
	}

	/*
		We need to try opening the device first in case it was plugged
		before devdrfif.dll gets loaded
	*/
	dwRet = OpenArt2Device( &DevHandle );
	if( ERROR_SUCCESS == dwRet )
	{
		printf("Art2 device detected, setting global device arrival event.\n");
		SetEvent( ghDevArrivalEvent );
	}
	else
	{
		printf("OpenArt2Device() returns %08X.\n", dwRet );
	}
    
	printf("Setting up device event notification callbacks...\n");
	InitDevMsg(NULL);

	printf("devdrvif.dll armed for device notification.\n");
    return dwRet;
}

DEVDRVIF_API int cmd_init (char *ifname, void (*rx_cb)(void *buf))
{
	DWORD				dwRet = ERROR_SUCCESS;
	PART2_IO_REQ_HEADER pIoReqHeader = NULL;
    int                 nRetry;

    if ( initCfg.initialized )
        return -1;

    // wait for InitThreadProc() running
    for (nRetry = 0; nRetry < 10; nRetry++)
    {

	    dwRet = WaitForDeviceReady();
        if (dwRet != ERROR_NOT_ENOUGH_MEMORY)
        {
            break;
        }
        printf("Retry... ");
        Sleep(10);
    }
    if (dwRet != ERROR_SUCCESS)
        return -1;

	// device is open successfully
	initCfg.initialized = 1;

	initCfg.rx_cb = rx_cb;

    return 0;
}

DEVDRVIF_API int cmd_end ()
{
	DWORD dwRet = ERROR_SUCCESS;

	initCfg.initialized = 0;
	return dwRet;
}

HANDLE ghDumpMutex = NULL;

void prepare_for_cmd_evt_dump()
{
	ghDumpMutex = CreateMutex( 
        NULL,              // default security attributes
        FALSE,             // initially not owned
        NULL);             // unnamed mutex

    if (ghDumpMutex == NULL) 
    {
        printf("CreateMutex error: %08X\n", GetLastError());
    }
}

void clearup_for_cmd_evt_dump()
{
	if( ghDumpMutex )
	{
		CloseHandle(ghDumpMutex);
		ghDumpMutex = NULL;
	}
}

void lock_dump()
{
	DWORD dwWaitResult;
	
	if( ghDumpMutex == NULL )
	{
		printf("ghDumpMutex NULL!!");
		return;
	}
	
	dwWaitResult = WaitForSingleObject( 
            ghDumpMutex,    // handle to mutex
            INFINITE);		// no time-out interval
 
	switch (dwWaitResult) 
    {
        // Got ownership of the mutex
        case WAIT_OBJECT_0: 
	        break; 

        default:
			printf("Failed to acquire ownerhsip of ghDumpMutex, error=%08X.\n", GetLastError());
			break;
    }
}

void unlock_dump()
{
	BOOL ret;

	if( ghDumpMutex == NULL )
	{
		printf("ghDumpMutex NULL!!");
		return;
	}
	
	ret = ReleaseMutex( ghDumpMutex );
	if( !ret )
	{
		printf("Failed to release ownerhsip of ghDumpMutex, error=%08X.\n", GetLastError());
	}
}

void dump_cmd(unsigned char *buf, int len)
{
	static cmd_counter = 0;
	
	lock_dump();

	printf(
		"CMD(%08X, %04d)==>\n", 
		++cmd_counter, 
		len
		);
		
	dump_hex( buf, len );

	printf(	"==>\n"	);

	unlock_dump();
}

void dump_evt(unsigned char *buf, int len)
{
	static evt_counter = 0;

	lock_dump();

	printf(
		"EVT(%08X, %04d)<==\n",
		++evt_counter,
		len
		);

	dump_hex( buf, len );

	printf(	"<==\n"	);

	unlock_dump();
}

void dump_hex(unsigned char *buf, int len)
{
#define NUM_BYTES_EACH_LINE 16
	int i = 0;
	while( i < len )
	{
		printf("%02X ", buf[i]);
		if( ++i % NUM_BYTES_EACH_LINE == 0 )
		{
			putchar('\n');
		}
	}
	putchar('\n');
}

DEVDRVIF_API void cmd_send (void *buf, int len, unsigned char responseNeeded )
{
    int error = 0;
	PART2_IO_REQ_HEADER IoReqHeader;
	DWORD dwRet;
	ULONG bytesRet;

    if (!initCfg.initialized)
       return;

    memset(&responseBuf, 0, sizeof(responseBuf));
	
	IoReqHeader = (PART2_IO_REQ_HEADER)buf;
	IoReqHeader->RequestId = ART2_REQ_ID_UTF_CMD;
	IoReqHeader->InputContentLength = len;

	if( gUtfCmdEvtDumpEnabled )
	{
		dump_cmd( 
			(unsigned char *)(IoReqHeader + 1), 
			len 
			);
	}

	dwRet = Art2DeviceIoctl( 
					DevHandle,
					ART2_DEV_IOCTL_REQUEST,
					(PUCHAR)IoReqHeader,
					sizeof(ART2_IO_REQ_HEADER) + IoReqHeader->InputContentLength,
					NULL,
					0,
					&bytesRet
					);
	
#if 0
    *(unsigned int *)buf = ATH_XIOCTL_UNIFIED_UTF_CMD;
    *((unsigned int *)buf + 1) = len;

    initCfg.ifr.ifr_data = (void *)buf;

    if (ioctl(initCfg.sock, SIOCIOCTLTX99, &initCfg.ifr) < 0) {
       err(1, "ioctl");
       return;
    }
#endif

    if (responseNeeded) 
    {

        cmd_set_timer();
    
		IoReqHeader->RequestId = ART2_REQ_ID_UTF_RSP;
		IoReqHeader->InputContentLength = 0;

        //*(unsigned int *)responseBuf = ATH_XIOCTL_UNIFIED_UTF_RSP;
        //initCfg.ifr.ifr_data = (void *)responseBuf;

        while (1)
        {
			dwRet = Art2DeviceIoctl(
						DevHandle,
						ART2_DEV_IOCTL_REQUEST,
						(PUCHAR)IoReqHeader,
						sizeof(ART2_IO_REQ_HEADER) + IoReqHeader->InputContentLength,
						responseBuf,
						sizeof(responseBuf),
						&bytesRet
						);

            //error = ioctl(initCfg.sock, SIOCIOCTLTX99, &initCfg.ifr);

            if ( initCfg.timeout )
            {
                //memset(&responseBuf, 0, sizeof(responseBuf));
                //initCfg.ifr.ifr_data = responseBuf;
                break;
            }

            if ( dwRet != ERROR_SUCCESS /*error < 0*/ )
            {
                if ( EAGAIN != dwRet /*errno == EAGAIN*/ )
				{
					//Sleep(5);//TRANG - delay for now to test with FPGA. Might not need later
                    continue;
				}
                else
                {
                    printf("errno %d\n",errno);
                    //initCfg.ifr.ifr_data = responseBuf;
                    break;
                }
            }

            break;
        }

        if(!initCfg.timeout)
        {
            cmd_stop_timer(); 
            initCfg.timeout = 0;
			if( gUtfCmdEvtDumpEnabled )
			{
				dump_evt( responseBuf+4, bytesRet-4 );
			}
        }
        if ( initCfg.rx_cb != NULL )
            initCfg.rx_cb(responseBuf);
    }
}

DEVDRVIF_API int cmd_send2 (void *buf, int len, unsigned char *returnBuf, unsigned int *returnBufSize )
{
	PART2_IO_REQ_HEADER IoReqHeader;
	DWORD dwRet;
	ULONG bytesRet;
	int waitCounter;
	unsigned int maxReturnBufSize = *returnBufSize;

    if (!initCfg.initialized)
       return -1;

	memset(returnBuf, 0, maxReturnBufSize );
	
	IoReqHeader = (PART2_IO_REQ_HEADER)buf;
	IoReqHeader->RequestId = ART2_REQ_ID_UTF_CMD;
	IoReqHeader->InputContentLength = len;

	if( gUtfCmdEvtDumpEnabled )
	{
		dump_cmd( 
			(unsigned char *)(IoReqHeader + 1), 
			len 
			);
	}

	dwRet = Art2DeviceIoctl( 
					DevHandle,
					ART2_DEV_IOCTL_REQUEST,
					(PUCHAR)IoReqHeader,
					sizeof(ART2_IO_REQ_HEADER) + IoReqHeader->InputContentLength,
					NULL,
					0,
					&bytesRet
					);
	
	cmd_set_timer();
    
	IoReqHeader->RequestId = ART2_REQ_ID_UTF_RSP;
	IoReqHeader->InputContentLength = 0;

	waitCounter = 0;
	dwRet = -1;
	while( ( dwRet != (int) ERROR_SUCCESS ) && ( !initCfg.timeout ) )
	{
		dwRet = Art2DeviceIoctl(
						DevHandle,
						ART2_DEV_IOCTL_REQUEST,
						(PUCHAR)IoReqHeader,
						sizeof(ART2_IO_REQ_HEADER) + IoReqHeader->InputContentLength,
						returnBuf,
						maxReturnBufSize,
						&bytesRet
						);

		if ( bytesRet == 0 )
		{
			printf( ".waiting.." );
			waitCounter++;
			if ( ( waitCounter % 8 ) == 0 ) printf( "\n" );
			Sleep( 1 );
		}
			
		if ( initCfg.timeout )
		{
			printf( "Timeout while waiting for response\n" );
			break;
        }
	}

	if(!initCfg.timeout)
	{
		cmd_stop_timer(); 
        initCfg.timeout = 0;
		if( gUtfCmdEvtDumpEnabled )
		{
			dump_evt( returnBuf+4, bytesRet-4 );
		}
    }

	*returnBufSize = bytesRet; // return/set the number of bytes no matter what ( even if it is 0 ) 

	if ( dwRet != (int) ERROR_SUCCESS )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

DEVDRVIF_API int cmd_Art2ReadTargetMem (ULONG Address, ULONG Length, PUCHAR ReadBuffer)
{
	DWORD dwRet;
	ULONG BytesRet;

	dwRet = Art2ReadTargetMem(
				DevHandle,
				Address,
				Length,
				ReadBuffer,
				&BytesRet
				);

	if( ERROR_SUCCESS != dwRet )
	{
		printf ("cmd_Art2ReadTargetMem - Error\n");
		return -1;
	}
	return 0;
}

DEVDRVIF_API int cmd_Art2WriteTargetMem (ULONG Address, ULONG Length, PUCHAR WriteBuffer)
{
	DWORD dwRet;

	dwRet = Art2WriteTargetMem(
				DevHandle,
				Address,
				Length,
				WriteBuffer
				);

	if( ERROR_SUCCESS != dwRet )
	{
		printf ("cmd_Art2WriteTargetMem - Error\n");
		return -1;
	}
	return 0;
}

DEVDRVIF_API int cmd_Art2ReadTargetRegister (ULONG Address, PULONG ReadBuffer)
{
	DWORD dwRet;

	dwRet = Art2ReadTargetRegister(
				DevHandle,
				Address,
				ReadBuffer
				);

	if( ERROR_SUCCESS != dwRet )
	{
		printf ("cmd_Art2ReadTargetRegister - Error\n");
		return -1;
	}
	return 0;
}

DEVDRVIF_API int cmd_Art2WriteTargetRegister (ULONG Address, ULONG RegContent)
{
	DWORD dwRet;

	dwRet = Art2WriteTargetRegister(
				DevHandle,
				Address,
				RegContent
				);

	if( ERROR_SUCCESS != dwRet )
	{
		printf ("cmd_Art2WriteTargetRegister - Error\n");
		return -1;
	}
	return 0;
}

DEVDRVIF_API int cmd_Art2StartFwDownloading (DWORD FwDlFlags)
{
	DWORD dwRet;

	dwRet = Art2StartFwDownloading(DevHandle, FwDlFlags);

	if( ERROR_SUCCESS != dwRet )
	{
		printf ("cmd_Art2StartFwDownloading - Error\n");
		return -1;
	}
	return 0;
}

DEVDRVIF_API int cmd_Art2ConcludeBmi ()
{
	DWORD dwRet;

	dwRet = Art2ConcludeBmi(DevHandle);

	if( ERROR_SUCCESS != dwRet )
	{
		printf ("cmd_Art2StartFwDownloading - Error\n");
		return -1;
	}
	return 0;
}

DEVDRVIF_API int cmd_Art2GetInitStatus ()
{
	return Art2GetInitStatus(DevHandle);
}

DEVDRVIF_API DWORD cmd_Art2ReadPciConfigSpace (ULONG Offset)
{
    return Art2ReadPciConfigSpace(DevHandle, Offset);
}

DEVDRVIF_API DWORD cmd_Art2WritePciConfigSpace(ULONG Offset, ULONG Data)
{
    if (Art2WritePciConfigSpace(DevHandle, Offset, Data) != ERROR_SUCCESS)
    {
        printf ("cmd_Art2WritePciConfigSpace - Error\n");
		return -1;
	}
	return 0;
}
