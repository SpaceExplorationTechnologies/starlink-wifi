/*
 * Copyright (c) 2012 - 2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * 2012 - 2016 Qualcomm Atheros, Inc.
 */
/* dk_client.c - contians functions related to dk_client side of application */

/*
 * Copyright (c) 2000 Atheros Communications, Inc., All Rights Reserved
 * $ATH_LICENSE_TARGET_C$
 */

/* $Id: //depot/sw/branches/qca_main_wifi2.0/perf_pwr_offload/drivers/target/apps/utf/wmiHostIF/legHostIF.c#7 $ */

/*
DESCRIPTION
Contains functions related to dk_client side of application.  Including the main
function, the stuff for the communications channel etc.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "athdefs.h"
#include <utf_dev.h>
#include "art_utf_common.h"
#include "tcmd_api.h"

#include "osapi.h"
#include "dk_cmds.h"
#include "dk_client.h"
#include "dk_ver.h"

#include "hw.h"
#include "commonHwIF.h"
#include "common_defs.h"
#include "whalExtensionGeneric.h"
#include "hal_tcmd.h"
#include "ar6000_phyReg.h"
#include "ar6000_internal.h"

#include "efuse_api.h"
#if !defined(IPQ4019)
#include "otpstream_api.h"
#endif
#include "wmi_tcmd.h"
#include "tcmdHostInternal.h"
#include "cmdTxParms.h"
#include "utfCallback.h"
#include "ar6000_desc.h"
#include "cmdCalParms.h"
//#include "hal_tcmd.h"
//#include "art_utf_common.h"

#include "cmdAllParms.h"
#include "cmdOpcodes.h"
#include "genTxBinCmdTlv.h"

#include <wal_rx.h>
#include "tlv2Inc.h"
#include "cmdTPCCALHandler.h"
#include "cmdTPCCALPWRHandler.h"
#include "tpcCal.h"
#include "rxGainCal.h"
#include "halphy_api.h"
#include "halphy_cal.h"

#if defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
#include "eeprom_i2c_api.h"
#include "boardData.h"
#endif

typedef unsigned int u_int32_t;
typedef unsigned char u_int8_t;

#define SWAP32(_x) ((u_int32_t)(                       \
                    (((const u_int8_t *)(&_x))[3]) |        \
                    (((const u_int8_t *)(&_x))[2]<< 8) |    \
                    (((const u_int8_t *)(&_x))[1]<<16) |    \
                    (((const u_int8_t *)(&_x))[0]<<24)))

extern A_UINT32 swapEnable;


// thread info

#define MAX_CLIENTS_PER_THREAD 1

#define MAX_RDPWR        27  /* copy from haldemos */
#define uiPrintf A_PRINTF

// Globals, as ar6000 does not support malloc 
//PIPE_CMD gPipeBuffer;
//CMD_REPLY gReplyCmd;
//EVENT_QUEUE isrEventQ;
//EVENT_QUEUE triggerEventQ;
//EVENT_QUEUE dsrQ;

extern _VALUES_OF_INTEREST ValuesOfInterest;
extern A_UINT8 *cal_offset;
extern _AthDataRate Mask2Rate[RATE_MASK_ROW_MAX][RATE_MASK_BIT_MAX];
extern A_UINT32 HT40_RateMask[RATE_MASK_ROW_MAX];
#if defined(_CCK_MODE_DONOT_MATTER)
extern A_UINT32 CCK_RateMask[RATE_MASK_ROW_MAX];
#endif

A_UINT32 sleep_enable=0;
A_UINT32 sent_bytes=0, received_bytes=0;
extern TCMD_CONT_TX tx_tcmdParms;
extern TCMD_CONT_RX rx_tcmdParms;
tcmd_link_trx tcmdLinkTRx;

/* added for large bulk i2c write process*/
A_UINT32 stamp[2];
_CMD_NARTCMD_PARMS gEepromCmd;
#define MAX_TCMD_DATA_LENGTH  1024
A_BOOL eep_write_done = TRUE;
A_BOOL eep_write_check_ok = TRUE;
A_BOOL first_command = TRUE;
A_UINT16 gOffset;/* offset to the eeprom structure */
A_UINT16 gBlockSize;/* number of bytes in the Data */
A_UINT32 statusEepWrite = 0;
static A_UINT32 eep_write_complete_timeout = 300;
static A_TIMER eep_write_complete_timer;

#ifndef MALLOC_ABSENT
#else
//#include "global_vars.h"
#endif

#define INVALID_ENTRY          -1
#define WMAC_FUNCTION  0
#define UART_FUNCTION  1
#define USB_FUNCTION   2
#define SDIO_FUNCTION   3
#define MAX_POOL_STAT  10 

#define MDK_MAX_NUM_DEVICES	4
#define UART_FN_DEV_START_NUM  (UART_FUNCTION * MDK_MAX_NUM_DEVICES)
#define USB_FN_DEV_START_NUM  USB_FUNCTION
#define SDIO_FN_DEV_START_NUM  USB_FN_DEV_START_NUM

#define MAX_DATA_LENGTH  512
#define  TCMD_11AC3x3_MAX_RATES   150
#define TCMD_INVALID_RATEBIT 0xffffffff

#define MAX_BLOCK_SIZE  1000

#define PHY_CCA_MAX_GOOD_VAL -50
#define NUM_MAX_CHAINS 16
#define DEFAULT_NF_VALUE_NON_SUPPORTED_CHAIN 0x100003E7    // 999 in Hex and most significant byte has been set to 1 to indicate negative

extern  A_UINT32 mdk_crc32_table[256]; 
void deviceCleanup (A_UINT16 devIndex);

//A_UINT8 otp_test_data[2048];


typedef struct {
    unsigned char *buf;
    int avail;
} POOL_STAT_STRUCT;

POOL_STAT_STRUCT statPool[MAX_POOL_STAT];

struct dkThreadInfo {
    A_INT32       inUse;
    A_UINT32      threadId;
    PIPE_CMD      *PipeBuffer_p;
    CMD_REPLY     *ReplyCmd_p;
    A_UINT32      devIndex;
    A_INT32       devNum;
    A_UINT32      numClients;
    A_UINT32      currentDevIndex;
};

struct dkThreadInfo dkThreadArray;
struct dkThreadInfo *dkThread;
int numThreads;

A_UINT32 rxRssiEvmSamplesGood[TCMD_MAX_RATES];
A_UINT32 rxRssiEvmSamplesBad[TCMD_MAX_RATES];
A_UINT32 txRssiEvmSamples[TCMD_MAX_RATES];

// FORWARD DECLARATIONS
extern void uDelay(A_INT32 val);
extern A_STATUS commandDispatch(wlan_tcmd_dev_t *dev, struct dkThreadInfo *dkThread);
void sendNartResponse (wlan_tcmd_dev_t *dev,A_UINT32 cmdId,A_UINT8 *buf, A_UINT32 length, A_UINT32 status);

#if 0
static A_INT32  addClientToThread ( struct dkThreadInfo *dkThread, A_UINT16  devIndex, A_UINT32  devNum);
static void removeClientFromThread
(
	struct dkThreadInfo *dkThread,
	A_UINT16  devIndex
);
#endif

void initThreadInfo(void); 

//#define _TEST_UTF_SIZE
#if defined(_TEST_UTF_SIZE)
MDK_WLAN_DRV_INFO	globDrvInfo;	
A_STATUS envInit ( A_BOOL debugMode) { return A_OK; }
A_STATUS deviceInit ( A_UINT16 devIndex, A_UINT16 device_fn) { return A_OK; }
A_UINT32 hwMemRead32 ( A_UINT16 devIndex, A_UINT32 address ) { return 0; }
void hwMemWrite32 ( A_UINT16 devIndex, A_UINT32 address,         A_UINT32 value           ) { return;} 
A_UINT32 hwCfgRead32 ( A_UINT16 devIndex, A_UINT32 address                    ) { return 0; }
A_INT16 hwMemReadBlock ( A_UINT16 devIndex, A_UCHAR    *pBuffer, A_UINT32 physAddr, A_UINT32 length) { return 0;}
A_INT16 hwMemWriteBlock ( A_UINT16 devIndex, A_UCHAR  *pBuffer, A_UINT32 length, A_UINT32 *pPhysAddr) { return 0;}
A_INT16 hwCreateEvent ( A_UINT16 devIndex, PIPE_CMD *pCmd) { return 0;}
A_INT16 hwCreateEvt ( A_UINT16 devIndex, A_UINT32 type, A_UINT32 persistent, A_UINT32 param1, A_UINT32 param2, A_UINT32 param3, A_UINT16 eventID, A_UINT16 f2Handle) { return 0};

A_INT16 hwGetNextEvent ( A_UINT16 devIndex, void *pBuf) { return 0;}
void deviceCleanup (  	A_UINT16 devIndex        ) {return;}
void hwInit(MDK_WLAN_DEV_INFO *pdevInfo, A_UINT32 resetMask) {return;}
void deep_sleep(A_UINT32 se) {return;}
#endif

extern A_UINT8 dataPayload[];
A_UINT8 *replyBuf = NULL;
static A_UINT32 replyLength = 0;
A_UINT32 currentDevIndex = 0;
extern void wmi_tc_cmds_reply_event(struct wmi_info *wi, A_UINT16 len, A_UINT8 version, A_INT8* buf);


void free_pool_stat_buf( char * buf);
unsigned char* get_pool_stat_buf() ;
void free_all_stat_buf();
void current_pool_stat_buf();
void return_all_stat_buf();
void alloc_pool_stat_init ();

void eep_write_complete_timer_handler(A_HANDLE handler, void *data);

/**************************************************************************
* main - main function
*
* RETURNS: N/A
*/

//        envCleanup(TRUE);

void initLegHostIFCmdsSupport(void) //A_INT32 rawHTCAttach(A_INT32 debugMode)
{
    // display our startup message
    //A_PRINTF("Attach legacy i/f ...\n");

    // perform environment initialization
    if ( A_ERROR == envInit((A_BOOL)0) ) {
        return;
    }

    dkThread = &dkThreadArray;
    initThreadInfo();

    /* move down to avoid delay the Cmd buffer link to dkThread 
     * which maybe cause the ASSERT failed 
     */
  
    return;
}

void tcReadCmds(A_UINT8 *cmdBuf, A_UINT16 len) 
{
    return;
}

A_INT32 htcDispatchCmd(wlan_tcmd_dev_t *dev)
{
    return(0);
}

A_UINT32 createEventCmd()
{
    A_UINT32 ret=0;

/// Create ISR event..
    if(hwCreateEvt(currentDevIndex,0x10,1,0,0,0,0,0) == -1)
    {
        uiPrintf("Failed call to hwCreateEvent()\n");
        ret =COMMS_ERR_EVENT_CREATE_FAIL;
    }

    return(ret);
}

/**************************************************************************
* processInitF2Cmd - Process INIT_F2_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/

A_UINT32 processInitF2Cmd(_CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT16 device_fn,restoreDevIndex=0;
    A_UINT32 devNum = 0,ret=0;
    //A_UINT32 i=0;
    A_UINT32 eepromAddr = 0;

    MDK_WLAN_DEV_INFO *pdevInfo;
    A_UINT32 devIndex = pCmd->param1;
#if 0
    A_UINT32 num = pCmd->param2;

    A_PRINTF("num %d\n",num);

    for(i=0;i<num;i++)
    {
        if (i % 16 == 0) A_PRINTF_ALWAYS("\n");
        A_PRINTF_ALWAYS("0x%02x ",pCmd->data[i]);
    }

    A_PRINTF_ALWAYS("\n");

    A_PRINTF("param3 %d\n",pCmd->param3);
#endif

    device_fn = WMAC_FUNCTION;

    if (devIndex >= SDIO_FN_DEV_START_NUM)  {
        devIndex = devIndex - SDIO_FN_DEV_START_NUM;
        restoreDevIndex = 1;
    }
    
    /* validate the F2 required; see that it is a valid index */
    if (devIndex > WLAN_MAX_DEV ) {
    /* don't have a large enough array to accommodate this device */
        uiPrintf("Error: devInfo array not large enough, only support %d devices\n", WLAN_MAX_DEV);
	return(COMMS_ERR_INDEX_TOO_LARGE);
    }

    if (devIndex == 0) {
	uiPrintf("index 0\n");
	return(COMMS_ERR_DEV_INIT_FAIL);
    }

    devIndex = devIndex - 1;
#if defined(AR6320)
    deviceCleanup(devIndex);
#endif //AR6320
    if (A_FAILED(deviceInit((A_UINT16)devIndex, device_fn)) ) {
	uiPrintf("deviceInit?\n");
	return(COMMS_ERR_DEV_INIT_FAIL);
    }

#if 0
    /// Keep this for backward compatibility...
    if (addClientToThread(dkThread,(A_UINT16)devIndex,devNum) < 0) {
        uiPrintf("addClientToThread?\n");
        return(COMMS_ERR_DEV_INIT_FAIL);
    }
#endif

    pdevInfo = globDrvInfo.pDevInfoArray[devIndex];
    if (restoreDevIndex)  {
        pdevInfo->pdkInfo->devIndex = devIndex + SDIO_FN_DEV_START_NUM;
        restoreDevIndex = 0;
    }

    currentDevIndex = devIndex;
    A_MEMZERO((void*)&_PostWhalResetSettings, sizeof(_PostWhalResetSettings));

    ret = createEventCmd(); // Implicitly create eventCmd, without NART sending..
    if ( ret != 0 )
        return ret;

    *((A_UINT32 *)replyBuf) = (devNum | 0x10000000);

#if defined(AR6002_REV4)
    A_MEMCPY(replyBuf+4, pdevInfo->pdkInfo, sizeof(DK_DEV_INFO));
    replyLength = 4 + sizeof(DK_DEV_INFO);
#else
    *(((A_UINT32 *)replyBuf)+1) = pdevInfo->pdkInfo->memPhyAddr;
    *(((A_UINT32 *)replyBuf)+2) = pdevInfo->pdkInfo->memSize;
	A_TARGET_ID_GET((((A_UINT32 *)replyBuf)+3));
    eepromAddr = (A_UINT32)A_BOARD_DATA_ADDR();
    *(((A_UINT32 *)replyBuf)+4) = eepromAddr;

    // No longer send back the long packet, rather make up on the host.
    //A_MEMCPY(replyBuf+16, pdevInfo->pdkInfo, sizeof(DK_DEV_INFO));
    replyLength = 20;
#endif //AR6002_REV4

#if 0
    for(i=0;i<12;i++)
        A_PRINTF_ALWAYS("%x ",replyBuf[i]);
    A_PRINTF_ALWAYS("\n");
#endif

    return (0);
}

A_UINT32 isValidReg(A_UINT32 addr)
{
    /* check that the register is within the range of registers */
#if defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
    if (!IS_VALID_REG(addr))
#else
    /* in Mckinley, because we took out the offset, this is a absolute address, so we have to prevent it from reading something below the SOC address */
    if ((addr > MAX_REG_OFFSET) || ((RTC_SOC_BASE_ADDRESS > 0) && (addr < RTC_SOC_BASE_ADDRESS)))
#endif
    {
        A_PRINTF("invalid reg offset 0x%x\n", addr);
        return(COMMS_ERR_BAD_OFFSET);
    }
    return CMD_OK;
}

/**************************************************************************
* processRegReadCmd - Process REG_READ_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processRegReadCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    MDK_WLAN_DEV_INFO    *pdevInfo;
    A_UINT32 status;

    pdevInfo = globDrvInfo.pDevInfoArray[currentDevIndex];
    
//    A_PRINTF("rr 0x%x\n", pCmd->param1);
    if ((status = isValidReg(pCmd->param1)) != CMD_OK)
    {
    	return status;
    }

    /* read the register */
    *((A_UINT32 *)replyBuf) = hwMemRead32((A_UINT16)currentDevIndex,pCmd->param1);

    replyLength = 4;

    return(0);
}

/**************************************************************************
* processRegWriteCmd - Process REG_WRITE_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processRegWriteCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    MDK_WLAN_DEV_INFO    *pdevInfo;
    A_UINT32 status;

    pdevInfo = globDrvInfo.pDevInfoArray[currentDevIndex];
    
    //A_PRINTF("rw 0x%x 0x%x\n", pCmd->param1, pCmd->param2);
    if ((status = isValidReg(pCmd->param1)) != CMD_OK)
    {
    	return status;
    }

    /* write the register */
    hwMemWrite32((A_UINT16)currentDevIndex, pCmd->param1, pCmd->param2);
  
    return(0);
}
/**************************************************************************
* processMemReadCmd - Process MEM_READ_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processMemReadCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    /* read the memory */
    switch(pCmd->param2)
    {
        case 32:
            *((A_UINT32 *)replyBuf) = hwMemRead32(currentDevIndex,pCmd->param1);
            replyLength = 4;
            break;
        default:
            return(COMMS_ERR_BAD_MEM_SIZE);
    }

    return(0);
}

/**************************************************************************
* processMemWriteCmd - Process MEM_WRITE_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processMemWriteCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    /* write the register */
    switch(pCmd->param3)
        {
        case 32:
            hwMemWrite32(currentDevIndex,pCmd->param1, pCmd->param2);
            break;
        default:
            return(COMMS_ERR_BAD_MEM_SIZE);
        }

    return(0);
}

#if defined(AR6320)
/**************************************************************************
* processTargetMemClearCmd - Process TARGET_MEM_CLEAR_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processTargetMemClearCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    hwMemClear(currentDevIndex,pCmd->param1, pCmd->param2); 
    
    return(0);
}

/**************************************************************************
* processTargetCalCRCCmd - Process TARGET_CAL_CRC_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processTargetCalCRCCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    A_UCHAR     *memPtr;
    A_UINT32     index;
    A_UINT32     memcrc = 0xFFFFFFFF;
        
 
    memPtr = (A_UCHAR *)((A_UINT32 *)pCmd->param1);
    for (index = 0; index < pCmd->param2; index++) {
        memcrc = mdk_crc32_table[(memcrc ^ *(memPtr + index)) & 0xff] ^ (memcrc >> 8);
    }
  

    *((A_UINT32 *)replyBuf) = memcrc ^ 0xffffffff;
    A_PRINTF ("crc vaule=0x%x\n",*((A_UINT32 *)replyBuf));

    replyLength = 4;
    return(0);
}
#endif //AR6320

/**************************************************************************
 * * processCfgReadCmd - Process CFG_READ_CMD command
 * *
 * * RETURNS: 0 processed OK, an Error code if it is not
 * */
A_UINT32 processCfgReadCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    /* read the register */
    switch(pCmd->param2)
        {
        case 32:
            *((A_UINT32 *)replyBuf) = hwCfgRead32(currentDevIndex, pCmd->param1);
            replyLength = 4;
            break;
        default:
            return(COMMS_ERR_BAD_CFG_SIZE);
        }

    return(0);
}

/**************************************************************************
* processMemReadBlockCmd - Process MEM_READ_BLOCK_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processMemReadBlockCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    /* check that the size is appropriate before we access */
    if( pCmd->param2 > MAX_DATA_LENGTH )
    {
        uiPrintf("Err cmd len not equal to size of MEM_READ_BLOCK_CMD\n");
        return(COMMS_ERR_BAD_LENGTH);
    }

    /* read the memory */
    if(hwMemReadBlock(currentDevIndex, replyBuf, pCmd->param1,pCmd->param2) == -1)
    {
        uiPrintf("Failed call to hwMemReadBlock()\n");
        return(COMMS_ERR_READ_BLOCK_FAIL);
    }

    replyLength = pCmd->param3;

    return(0);
}

/**************************************************************************
* processMemWriteBlockCmd - Process MEM_WRITE_BLOCK_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processMemWriteBlockCmd (_CMD_NARTCMD_PARMS *pCmd)
{
#ifdef ENDIAN_SWAP
     pCmd->param1 = ltob_l(pCmd->param1);
     pCmd->param2 = ltob_l(pCmd->param2);
#endif

#ifdef PREDATOR // Just to avoid mac endian register programming
// Currently this functions writes the byte array starting from the
// phyaddr, therefore endianness free

// swap from little endian to big endian
#ifdef ENDIAN_SWAP
{
    int noWords;
    int i;
    A_UINT32 *wordPtr;

    noWords =   pCmd->param2/sizeof(A_UINT32);
    wordPtr = (A_UINT32 *)pCmd->data;
    for (i=0;i<noWords;i++)
    {
    	*(wordPtr + i) = ltob_l(*(wordPtr + i));
    }
}
#endif

#endif

    /* write the memory */
    if(hwMemWriteBlock(currentDevIndex,pCmd->data, 
				   pCmd->param2, 
				   &(pCmd->param1)) == -1)
    {
        uiPrintf("Failed call to hwMemWriteBlock()\n");
        return(COMMS_ERR_WRITE_BLOCK_FAIL);
    }

    /* copy the address into the return buffer */
    *(A_UINT32 *)replyBuf = pCmd->param1;
    replyLength = 4;

    return(0);
}

/**************************************************************************
* processStickyWriteCmd - Process STICKY_WRITE_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
* count(4byte)||Addr1(4bytes)Value1(4bytes)Mask1(4bytes)||Add2(4bytes)Value2(4bytes)Mask(4bytes)||......
*/
A_UINT32 processStickyWriteCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32       *pBuf;
    A_UINT32      i,j;
    A_UINT32 mode, addressMode, count;
    A_UINT32 status = CMD_OK;

    /* check that the size is appropriate before we access */
    if( pCmd->param1 > MAX_DATA_LENGTH )
    {
        A_PRINTF("cmd len != STICKY_WRITE_CMD\n");
        return(COMMS_ERR_BAD_LENGTH);
    }

    pBuf = (A_UINT32*)pCmd->data;
    A_PRINTF("numOfStickyWrite=%d\n",pCmd->param2);
    //uiPrintf("unused=%d\n",pCmd->param3);
    //uiPrintf("pCmd->data 0x%x\n",pCmd->data);
    //uiPrintf("pCmd 0x%x\n",pCmd);

    pBuf++;
    //search for the whole _PostWhalResetSettings.addrMode array to look for an empty spot
    j = 0;
    while ((j < MAX_UTF_CAL_WRITE_REG) && _PostWhalResetSettings.addrMode[j])
    {
        j++;
    }
    
    for (i=0; i<pCmd->param2; i++,j++) {
        if (_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero >= MAX_UTF_CAL_WRITE_REG)
            break;
        //for (j=0;j<MAX_UTF_CAL_WRITE_REG;j++)
        //{/* search for the whole array to look for an empty spot */
        //    if (_PostWhalResetSettings.addrMode[j] == 0) {
                //A_PRINTF("StickyWrite[%d] Addr=0x%08x Value=0x%08x Mask=0x%08x\n",j,*pBuf,*(pBuf+2),*(pBuf+1));
                addressMode = *(pBuf+0);
                if ((status = isValidReg(addressMode & CONFIG_ADDR_ADDRESS_MASK)) != CMD_OK)
                {
                	break;
                }
                mode = (addressMode & CONFIG_ADDR_MODE_MASK) >> CONFIG_ADDR_MODE_SHIFT;
                count = GET_LENGTH_CONFIG_ENTRY_32B(mode) - 1;
                if (j + count >= MAX_UTF_CAL_WRITE_REG)
                {
	                status = COMMS_ERR_ALLOC_FAIL;
	                break;
                }
                addressMode &= (~CONFIG_ADDR_MODE_MASK);

                if (mode == OTP_CONFIG_MODE_COMMON)
                {
	                addressMode |= (_UTF_NO_MODAL << ADDRMODE_MODAL_SHIFT);
                 	_PostWhalResetSettings.addrMode[j] = addressMode;
                 	_PostWhalResetSettings.mask[j]     = *(pBuf+1);
                 	_PostWhalResetSettings.value[j]    = *(pBuf+2);
                 	_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero++;
               	}
                else if (mode == OTP_CONFIG_MODE_2MODAL)
                {
                    if (j + 1 >= MAX_UTF_CAL_WRITE_REG) // This is already checked above, but add the check here again to avoid Klockwork error
                    {
    	                status = COMMS_ERR_ALLOC_FAIL;
    	                break;
                    }
                  	_PostWhalResetSettings.addrMode[j] = addressMode | (_UTF_11G << ADDRMODE_MODAL_SHIFT);
                	_PostWhalResetSettings.mask[j]     = *(pBuf+1);
                	_PostWhalResetSettings.value[j]    = *(pBuf+2);
                 	_PostWhalResetSettings.addrMode[++j] = addressMode | (_UTF_11A << ADDRMODE_MODAL_SHIFT);
                	_PostWhalResetSettings.mask[j]     = *(pBuf+1);
                	_PostWhalResetSettings.value[j]    = *(pBuf+3);
                	_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero += 2;
               	}
                else //if (mode == OTP_CONFIG_MODE_5MODAL)
                {
                    if (j + 4 >= MAX_UTF_CAL_WRITE_REG) // This is already checked above, but add the check here again to avoid Klockwork error
                    {
    	                status = COMMS_ERR_ALLOC_FAIL;
    	                break;
                    }
                  	_PostWhalResetSettings.addrMode[j] = addressMode | (_UTF_11G_LEG_HT20 << ADDRMODE_MODAL_SHIFT);
                	_PostWhalResetSettings.mask[j]     = *(pBuf+1);
                	_PostWhalResetSettings.value[j]    = *(pBuf+2);
                 	_PostWhalResetSettings.addrMode[++j] = addressMode | (_UTF_11G_HT40 << ADDRMODE_MODAL_SHIFT);
                	_PostWhalResetSettings.mask[j]     = *(pBuf+1);
                	_PostWhalResetSettings.value[j]    = *(pBuf+3);
                 	_PostWhalResetSettings.addrMode[++j] = addressMode | (_UTF_11A_LEG_HT20 << ADDRMODE_MODAL_SHIFT);
                	_PostWhalResetSettings.mask[j]     = *(pBuf+1);
                	_PostWhalResetSettings.value[j]    = *(pBuf+4);
                 	_PostWhalResetSettings.addrMode[++j] = addressMode | (_UTF_11A_HT40 << ADDRMODE_MODAL_SHIFT);
                	_PostWhalResetSettings.mask[j]     = *(pBuf+1);
                	_PostWhalResetSettings.value[j]    = *(pBuf+5);
                 	_PostWhalResetSettings.addrMode[++j] = addressMode | (_UTF_11A_VHT80 << ADDRMODE_MODAL_SHIFT);
                	_PostWhalResetSettings.mask[j]     = *(pBuf+1);
                	_PostWhalResetSettings.value[j]    = *(pBuf+6);
                	_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero += 5;
                }
                pBuf += (count + 2);    //number of values + 1 for register + 1 for mask
                //break;
            //}
        //}
    }
    if (_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero)
    {
        _PostWhalResetSettings.pPostProc = whalStickyCmdResetPostProcessing;
        A_PRINTF("set pPostProc\n");
    }
    return(status);
}

/**************************************************************************
* processStickyClearCmd - Process STICKY_CLEAR_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
* count(4byte)||Addr1(4bytes)Mask1(4bytes)||Add2(4bytes)Mask(4bytes)||......
*/
A_UINT32 processStickyClearCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32       *pBuf;
    A_UINT32      i,j,k;
    A_UINT32      numOfRegs, count;

    pBuf = (A_UINT32*)pCmd->data;
    numOfRegs = pCmd->param2;
    A_PRINTF("numOfStickyClear=%d\n",numOfRegs);
    if (numOfRegs == 0xffffffff) {/* clear all */
        for (i=0;i<MAX_UTF_CAL_WRITE_REG;i++)
        {
            _PostWhalResetSettings.addrMode[i] = 0;
            _PostWhalResetSettings.value[i] = 0;
            _PostWhalResetSettings.mask[i] = 0;
        }
        _PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero = 0;
        return 0;
    }

    if (numOfRegs > MAX_UTF_CAL_WRITE_REG) {
        numOfRegs = MAX_UTF_CAL_WRITE_REG;
    }
    
    pBuf++;
    for (i=0;i<numOfRegs;i++) 
    {
        for (j=0;j<_PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero;j++)
        {/* look for all the entries to see if there is one matches */
            if ((_PostWhalResetSettings.addrMode[j] & ADDRMODE_ADDR_MASK) == (*pBuf & ADDRMODE_ADDR_MASK) && _PostWhalResetSettings.mask[j] == *(pBuf+1)) /* if both addr and mask are matching then FOUND */
            {
                count = (_PostWhalResetSettings.addrMode[j] & ADDRMODE_MODAL_MASK) >> ADDRMODE_MODAL_SHIFT;
 				count = count == _UTF_NO_MODAL ? 1 : (count == _UTF_11G ? 2 : 5);
 				
 				// Remove the next count elements
                for (k = j+count; k < _PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero+count; j++, k++)
                {
        			//A_PRINTF("StickyClear[%d] Addr=0x%x Mask=0x%x\n",j,*pBuf,*(pBuf+1));
                	_PostWhalResetSettings.addrMode[j] = _PostWhalResetSettings.addrMode[k];
					_PostWhalResetSettings.value[j] = _PostWhalResetSettings.value[k];
					_PostWhalResetSettings.mask[j] = _PostWhalResetSettings.mask[k];
                }
                _PostWhalResetSettings.numOfRegs_AlsoMeantPostProcInstalledIfNonZero -= count;
                break;
            }
        }
        pBuf += 2;
    }

    return(0);
}

/**************************************************************************
* processCloseDeviceCmd - Close Device
*
*/

A_UINT32 processCloseDeviceCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT16 devIndex = currentDevIndex;

    // Close low level structs for this device
    if (devIndex != (A_UINT16)-1) {
        deviceCleanup(devIndex);
    }

#if 0
    removeClientFromThread(dkThread, devIndex);
#endif
    return 0;
}

/**************************************************************************
* processHwReset - Hw Reset
*
*/

A_UINT32 processHwReset (_CMD_NARTCMD_PARMS *pCmd)
{
    MDK_WLAN_DEV_INFO    *pdevInfo;

    pdevInfo = globDrvInfo.pDevInfoArray[currentDevIndex];
    hwInit(pdevInfo, pCmd->param1);

    *((A_UINT32 *)replyBuf) = 0x000c12ff;
    replyLength = 4;

    return(0);
}

/**************************************************************************
* processResetDeviceCmd - reset the device and initialize all registers
*
*/

A_UINT32 processResetDeviceCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    WHAL_CHANNEL chan;

    //#ifdef ENDIAN_SWAP
    //pCmd->CMD_U.RESET_DEVICE_CMD.freq = ltob_l(pCmd->CMD_U.RESET_DEVICE_CMD.freq);
    //pCmd->CMD_U.RESET_DEVICE_CMD.turbo  = ltob_l(pCmd->CMD_U.RESET_DEVICE_CMD.turbo);
    //#endif

    /*// tbd?? also need to support mode to MODE_11NA_HT20   MODE_11NG_HT20  MODE_11NA_HT40 MODE_11NG_HT40
    // one way is to pass mode down to DUT
    if ((pCmd->CMD_U.RESET_DEVICE_CMD.freq >= 2412) && 
        (pCmd->CMD_U.RESET_DEVICE_CMD.freq <= 2484) ) 
        chan.wlanMode = MODE_11G;
    else if ((pCmd->CMD_U.RESET_DEVICE_CMD.freq >= 4900) && 
             (pCmd->CMD_U.RESET_DEVICE_CMD.freq < 6000) ) 
        chan.wlanMode = MODE_11A;
    else { //if (chan.wlanMode == MODE_UNKNOWN)
        *((A_UINT32 *)replyBuf) = A_ERROR;
        return A_ERROR;
    }*/

    //pCmd->param1; //channel
    //pCmd->param2; //tcmd wlanMode
    //pCmd->param1 = 5220; /// FORCE channel to be 5G and VHT20...
    //pCmd->param2 = 5;
    tcmd_get_channel(pCmd->param1, pCmd->param2, 0, &chan, pCmd->param1);

    if (chan.phy_mode == MODE_UNKNOWN) {
        A_PRINTF("Invalid mode freq %d wlanMode %d\n",pCmd->param1,pCmd->param2);
    }
    else {
        tcmd_whalReset(&chan);
        tcmd_state.freq = chan.mhz;
        tcmd_state.tcmdMode = TCMD_STATUS_ENABLE;
        tcmd_state.wlanMode = pCmd->param2;
        tcmd_state.bandwidth = 0;
    }
    
    *((A_UINT32 *)replyBuf) = 0;
    return 0;
}

A_UINT32 processGetRefClkSpeedCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    A_PRINTF("Ref Clk value %d\n",A_REFCLK_SPEED_GET()); 
    *((A_UINT32 *)replyBuf) = A_REFCLK_SPEED_GET();
    replyLength = 4;

    return(0);
}

A_UINT32 processSleepCmd (_CMD_NARTCMD_PARMS *pCmd)
{
#ifdef ENDIAN_SWAP
	pCmd->param1 = ltob_l(pCmd->param1);
#endif

	//sleep_enable=1;
	deep_sleep(pCmd->param1);
/*
	switch(pCmd->param1) {
		case 1:
			sleep_enable=1;
			deep_sleep();
			break;
		case 0:
			sleep_enable=0;
			break;
	}
*/

    return(0);
}


#define MYBUF_LENGTH OTPSTREAM_MAXSZ
#if 0
static A_UINT8 mybuf[MYBUF_LENGTH];
void efuseDump(void)
{
        int i, j;
        int efuse_sz;

        efuse_sz = efuse_size() & ~0xf;

        for (i=0; i<efuse_sz; i+=16) {
            efuse_read(i, mybuf, 16);
            for (j=0; j<16; j++) {
                A_PRINTF("%x ", mybuf[j], mybuf[j]);
            }
            A_PRINTF("\n");
        }
}
#endif

A_UINT8 bufReadBack[MAX_BLOCK_SIZE];
void eep_write_complete_timer_handler(A_HANDLE handler, void *data)
{
    //struct stEepromWrite * pstEepWrite = (struct stEepromWrite *) &stEepWrite;
    //wlan_tcmd_dev_t *dev = (wlan_tcmd_dev_t *)(pstEepWrite->dev);
    _CMD_NARTCMD_PARMS *pCmd = (_CMD_NARTCMD_PARMS *)&gEepromCmd;
    A_UCHAR *pBuf;
    A_UINT16 bytesToWrite = 0;/* number of bytes in the Data */
    A_UINT32 cmdId = pCmd->commandId;
	//A_PRINTF("CMDID=%d\n", cmdId);
	
    switch (cmdId) {
        case M_EEEPROM_BLOCK_ERASE_ID:
	   pBuf = (A_UINT8 *)pCmd->data;
	   if (gBlockSize > MAX_BLOCK_SIZE) {
	    	bytesToWrite = MAX_BLOCK_SIZE;
	    }
	    else {
	    	bytesToWrite = gBlockSize;
	   }
	   statusEepWrite |= eeprom_block_write(gOffset, pBuf, bytesToWrite);
	   gOffset += bytesToWrite;
	    if (gBlockSize <= MAX_BLOCK_SIZE) {//last write cycle
	        
		A_PRINTF_ALWAYS("last erase cycle!\n");
		eep_write_done = TRUE;
		A_DELETE_TIMER(&eep_write_complete_timer);
		    A_PRINTF_ALWAYS("E: stamp0=%d, stamp1=%d\n", stamp[0], A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS));
	    } else  {
		gBlockSize -= MAX_BLOCK_SIZE;
		//A_PRINTF_ALWAYS("gBlockSize needed to erase %d!\n", gBlockSize);
		//trigger timer for next block writing
		A_TIMEOUT_MS(&eep_write_complete_timer, eep_write_complete_timeout, 0);

	    }
	   break;
        case M_WRITE_FW_BD_ID:
	    //A_UINT8 *ptr_orig = utfGetBoardDataPtr();
	
	    if (gBlockSize > MAX_BLOCK_SIZE) {
	    	bytesToWrite = MAX_BLOCK_SIZE;
	    }
	    else {
	    	bytesToWrite = gBlockSize;
	    }
    
	    // Recalculate Checksum before writing
	    utfRecalBoardDataChecksum();

	    pBuf = (A_UINT8 *)utfGetBoardDataPtr();
	   
	    statusEepWrite |= eeprom_block_write(gOffset, pBuf + gOffset, bytesToWrite);
	   
	    //read it back and compare what we've written with RAM 
/*	    A_UINT32 statusEepRead = 0;
	    statusEepRead |= eeprom_block_read(gOffset, bufReadBack, bytesToWrite);

	    if (statusEepRead || statusEepWrite || memcmp((void *)(pBuf + gOffset), (void *)bufReadBack, bytesToWrite)) {
	   	A_PRINTF_ALWAYS("RAM and eeprom not identical after written\n");
		eep_write_check_ok = FALSE;  
		eep_write_done = TRUE;
	 
		A_DELETE_TIMER(&eep_write_complete_timer);

		return;
	    }
*/
	    gOffset += bytesToWrite;

	    if (gBlockSize <= MAX_BLOCK_SIZE) {//last write cycle
	        //compare checksum again
		/*statusEepRead |= eeprom_block_read(0, bufReadBack, 4);

		if (statusEepRead || memcmp((void *)eeprom, (void *)bufReadBack, 4))
		{
		    A_PRINTF("checksum of boardData file and eeprom not identical\n");
		    eep_write_check_ok = FALSE;            
		}
		*/
		A_PRINTF_ALWAYS("last write cycle!\n");
		eep_write_done = TRUE;
		eep_write_check_ok = TRUE;
		A_DELETE_TIMER(&eep_write_complete_timer);
		A_PRINTF_ALWAYS("w: stamp0=%d, stamp1=%d\n", stamp[0], A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS));
	    }
	    else {//more data to write
	    	gBlockSize -= MAX_BLOCK_SIZE;
		//A_PRINTF_ALWAYS("gBlockSize needed to writ%d!\n", gBlockSize);
		//trigger timer for next block writing
		A_TIMEOUT_MS(&eep_write_complete_timer, eep_write_complete_timeout, 0);
	    }
	    break;
	default:
		   A_TIMEOUT_MS(&eep_write_complete_timer, eep_write_complete_timeout, 0);
	    break;	    
    }
}

/**************************************************************************
* processEfuseReadCmd - Process OTP_READ_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processEfuseReadCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    /* read the memory */
    efuse_enable_read();
    efuse_read(pCmd->param2, (A_UCHAR *)(replyBuf+1), pCmd->param1);
    efuse_disable();
    replyBuf[0] = pCmd->param1 &0xff;   // tbd?: how do we know efuse_read succeded
    replyLength = (pCmd->param1 &0xff) + 1;

#if 0
    if((pCmd->param1%4) != 0)
    {
        padCount=4-(pCmd->param1%4);
        A_PRINTF("EfuseReadCmd len = %x, pad=%x\n", pCmd->param1, padCount);
        for (j=0;j<padCount;j++)
        {
                replyBuf[pCmd->param1+j] = 0;
        }
        replyLength = replyLength + padCount;
    }

#endif

#if 0 // No need swap even attached host is big endian, but need padding for reported data.
    if(swapEnable==1)
    {
        A_UINT32 i, byte4, swappedByte4;
        //for(i=0;i<(pCmd->param1+padCount)/4;i++)
        for(i=0;i<(pCmd->param1)/4;i++)
        {
            byte4 =*((A_UINT32 *)&replyBuf[4*i]);
            swappedByte4 = SWAP32(byte4);
            *((A_UINT32 *)&replyBuf[4*i]) = swappedByte4;
        }
    }
#endif

    /* for testing only */
#if defined(TESTINLY_ONLY)
    {
    int i;
    for(i=0; i<(pCmd->CMD_U.EFUSE_READ_CMD.length+1); i++) {
        A_PRINTF("%x ", replyBuf[i]);
    }
    A_PRINTF("\n");
    }
 
    {
    A_STATUS    status;
    A_UCHAR buf[16] = {0xFF, 0x01, 0xa2, 0xf3, 0xd4, 0x05, 0x26, 0x67, 0x08, 0xb9, 0x0a, 0x4b, 0x5c, 0x0d, 0x6e, 0xaf};
    A_UINT32 nbytes;
    status = efuse_write(pCmd->param1, buf, 16, &nbytes);
    if (A_OK == status) {
        //A_PRINTF("wrote ATE bytes, status %d\n", status); 
    }
    else
        //A_PRINTF("wrote ATE bytes failed, status %d\n", status); 
    }
#endif

#if 0 //defined(_DEBUG)
    efuseDump();
#endif
        
    return(0);
}

/**************************************************************************
* processEfuseWriteCmd - Process EFUSE_WRITE_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processEfuseWriteCmd(_CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32    nbytes;
    A_STATUS    status;

    efuse_enable_write();
    status = efuse_write(pCmd->param2, pCmd->data,pCmd->param1, &nbytes);
    efuse_disable();

//A_PRINTF("Efuse Write Cmd start Pos %d len %d status %d\n",pCmd->param2,pCmd->param1,status);
//A_PRINTF("Data %x %x\n",pCmd->data[0],pCmd->data[1]);

    if (A_OK == status) {
        replyBuf[0] = 0;
        A_PRINTF("efuse write succeed\n");
    }
    else {
        A_PRINTF("efuse write failed\n");
        return (COMMS_ERR_NO_EVENTS);
    }

#if defined(AR6002_REV4)
     replyLength = 0;
#else
     //replyLength = pCmd->param1;  // don't forget the 1st length byte   
#endif //AR6002_REV4


#if 0 //defined(_DEBUG)
    efuseDump();
#endif

    return(0);
}

/**************************************************************************
* processOtpReadCmd - Process OTP_READ_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 OTPSTREAM_READ_INIT_FLAG = 0;
A_UINT32 processOtpReadCmd (_CMD_NARTCMD_PARMS *pCmd)
{
#if defined(IPQ4019)
    //TODO
    return 0;
#else    
    A_UINT32    nbytes;
    A_STATUS    status;
    A_UINT16    padCount=0, j;

#if 0
  //  replyBuf[0] = 0;
   // return(0);


    /* read the memory */ 

    if(OTPSTREAM_READ_INIT_FLAG == 0) {
	    otpstream_reset(OTPSTREAM_READ);
	    OTPSTREAM_READ_INIT_FLAG =  1;
    }
    #endif 
    status = otpstream_read((A_UCHAR *)(replyBuf+4), (OTPSTREAM_MAXSZ *4), &nbytes);
    //A_PRINTF("optread status %d, len %d, otpstram_min_index=%d, otpstream_max_index=%d\n", status, nbytes, otpstream_min_index, otpstream_max_index);
	
    
    if (A_OK == status) {
#if 1
{
       if((nbytes%4) != 0)
       {
            padCount=4-(nbytes%4);
            for (j=0;j<padCount;j++)
            {
                replyBuf[4+nbytes+j] = 0;
             }
        }

        if(swapEnable==1)
        {
            A_UINT32 i, byte4, swappedByte4;
            for(i=0;i<(nbytes+padCount)/4;i++)
            {
                byte4 =*((A_UINT32 *)&replyBuf[4*(i+1)]);
                swappedByte4 = SWAP32(byte4);
                *((A_UINT32 *)&replyBuf[4*(i+1)]) = swappedByte4;
            }
        }
}
#endif
        memcpy(&replyBuf[0],&nbytes,sizeof(A_UINT32));
        replyLength = (nbytes + 4 + padCount);  //   
    }
    else {
        replyBuf[0] = 0;
#if defined(AR6320)
        replyLength = 4;  //   
#endif //AR6320
        //A_PRINTF("end of otp data %d, len %d\n", status, replyLength);
    }
    //A_PRINTF("end of otp data %d, len %d\n", status, replyLength);
    otpstream_fini();
    return(0);
#endif    
}

/**************************************************************************
* processOtpWriteCmd - Process OTP_WRITE_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 OTPSTREAM_WRITE_INIT_FLAG = 0;
A_UINT32 processOtpWriteCmd (_CMD_NARTCMD_PARMS *pCmd)
{
#if defined(IPQ4019)
    //TODO
    return COMMS_ERR_WRITE_BLOCK_FAIL;
#else    
	/*
    A_UINT32 i = 0; 

    A_PRINTF("otp write len %d\n",pCmd->param1);

    for(i=0;i<pCmd->param1;i++) {
        if (i && !(i %16) )
            A_PRINTF("\n"); 
        A_PRINTF("%x ",pCmd->data[i]);
    }
    A_PRINTF("\n");

    memcpy(otp_test_data,pCmd->data,pCmd->param1);
*/
    A_STATUS    status;
#if 0
    /* read the memory */
    //otpstream_reset(OTPSTREAM_WRITE);
    if(OTPSTREAM_WRITE_INIT_FLAG == 0) {
	otpstream_reset(OTPSTREAM_WRITE);
	OTPSTREAM_WRITE_INIT_FLAG = 1;
    }
#endif
    status = otpstream_write((A_UINT8 *)pCmd->data, pCmd->param1);
    otpstream_fini();
    //A_PRINTF("otpstream_write status(%d)\n", status);
    if (A_OK == status) {
        *((A_UINT32 *)replyBuf) = 0;
    }
    else {
        // tobe removed?? 
        //A_PRINTF("otpstream_write failed (%d)\n", status);
        *((A_UINT32 *)replyBuf) = 0;
        return(COMMS_ERR_WRITE_BLOCK_FAIL);
    }

    return(0);
#endif    
}


/**************************************************************************
* processOtpResetCmd - Process OTP_RESET_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processOtpResetCmd (_CMD_NARTCMD_PARMS *pCmd)
{
#if !defined(IPQ4019)    
    //A_PRINTF("otp reset %d\n", pCmd->param1);
    otpstream_reset((enum otpstream_op)pCmd->param1);
    *((A_UINT32 *)replyBuf) = 0;
#endif    

    return(0);
}

/**************************************************************************
* processOtpLoadCmd - Process OTP_LOAD_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processOtpLoadCmd (_CMD_NARTCMD_PARMS *pCmd)
{
///TODO???
#if defined(AR6002_REV6)
    A_INT32 otp_main(A_UINT32 param);
    otp_main(0);
#endif

    *((A_UINT32 *)replyBuf) = 0;

    return(0);
}

/* the reason why we need the numDs here is because of for an aggreated packet, only the last sub frame status is valid
 * all the other sub-frame don't have the status from hardware. 
 * so if this is aggregated packet(it will be the last sub-frame when entering here), 
 * then we need to count all the previous sub-frame into the report
 * with numDs we can know how many sub-frames totally are in this aggregated packets
 */

void processTxDataStats(A_UINT32 pkt_len, A_UINT32 total_pkts, A_UINT32 good_pkts, void *hwStatus, void *swStatus)
{
    TX_STATS_STRUCT_UTF *txStat;
    A_UINT32 rIdx = tcmdLinkTRx.currentTx;
    A_UINT32 length;
#ifdef FIXME_PKTINFO
    struct ppdu_status *hw_status = (struct ppdu_status *) hwStatus;
    WHAL_TX_DESC_STATUS *sw_status = (WHAL_TX_DESC_STATUS *) swStatus;
#endif

    if (rIdx >= TCMD_MAX_RATES)
        return;

    txStat = tcmdLinkTRx.txStats[rIdx];

    if (txStat == NULL)
        return;

    txStat->totalPackets += total_pkts;

    //if (hw_status->tx_ok)/* packet good */
    {
        length = good_pkts * pkt_len;
        txStat->goodPackets += good_pkts;
        txStat->byteCount += length;

#ifdef FIXME_PKTINFO
        if (txStat->startTime == 0)
        {
            txStat->dontCount += length;
            txStat->startTime = hw_status->wb_timestamp;
        }
        txStat->endTime = hw_status->wb_timestamp;
        txStat->rssi += hw_status->ack_rssi_ave;
#endif
        txRssiEvmSamples[rIdx]++;
    }
    //else
    {
#ifdef FIXME_PKTINFO
        if (sw_status->tsStatus & WHAL_TXERR_FIFO)
            txStat->underruns++;
        else if (sw_status->tsStatus & WHAL_TXERR_XRETRY)
            txStat->excessiveRetries++;
        else if (sw_status->tsStatus)
            txStat->otherError++;
#endif
    }

#ifdef FIXME_PKTINFO
    txStat->shortRetry += sw_status->tsShortRetry;
    txStat->longRetry += sw_status->tsLongRetry;
    txStat->thermCal= ValuesOfInterest.thermCAL;
#endif
    txStat->thermCal= ValuesOfInterest.thermCAL;
    return;
}

A_BOOL txDataStatsReport(A_UINT32 rIdx, A_BOOL flagTxDone, A_UINT8 *outBuf)
{
    TX_STATS_STRUCT_UTF *txStat = tcmdLinkTRx.txStats[rIdx];
    A_INT32 samples;

    if (txStat == NULL )
        return 0;

    if (flagTxDone == 1) {/* only requesting for the report that is done for transmitting */
          if (tcmdLinkTRx.currentTx <= rIdx)/* not done yet */
            return 0;
    } 

    samples = txRssiEvmSamples[rIdx];
    if (samples) {
        txStat->rssi /= samples;
        txStat->rssic[0] /= samples;
        txStat->rssic[1] /= samples;
        txStat->rssic[2] /= samples;
        txStat->rssie[0] /= samples;
        txStat->rssie[1] /= samples;
        txStat->rssie[2] /= samples;
    }

    A_MEMCPY(outBuf, txStat, sizeof(TX_STATS_STRUCT_UTF));
    txRssiEvmSamples[rIdx] = 0;

    if ( txStat != NULL )
    {
        //A_FREE(txStat);
        current_pool_stat_buf();
        return_all_stat_buf();

        tcmdLinkTRx.txStats[rIdx] = NULL;
    }
    //txStat->rateBit = TCMD_INVALID_RATEBIT;
    return 1;
}

#if 0
A_UINT8 processRxDescriptorRssiCtl1(WHAL_RX_DESC *ds)
{
    A_UINT8 rssic;
    AR6000_RX_DESC *ads = AR6000RXDESC(ds);
    
    rssic = (ads->dsStatus0 & 0x0000FF00) >> 8;
    return rssic;
}

A_UINT8 processRxDescriptorRssiCtl2(WHAL_RX_DESC *ds)
{
    A_UINT8 rssic;
    AR6000_RX_DESC *ads = AR6000RXDESC(ds);
    
    rssic = (ads->dsStatus0 & 0x00FF00) >> 16;
    return rssic;
}

A_UINT8 processRxDescriptorRssiExt1(WHAL_RX_DESC *ds)
{
    A_UINT8 rssie;
    AR6000_RX_DESC *ads = AR6000RXDESC(ds);
    
    rssie = (ads->dsStatus4 & 0x0000FF00) >> 8;
    return rssie;
}

A_UINT8 processRxDescriptorRssiExt2(WHAL_RX_DESC *ds)
{
    A_UINT8 rssie;
    AR6000_RX_DESC *ads = AR6000RXDESC(ds);
    
    rssie = (ads->dsStatus4 & 0x00FF0000) >> 16;
    return rssie;
}

A_INT32 processRxDescriptorEvm0(WHAL_RX_DESC *ds)
{
    A_INT32 evm;

    AR6000_RX_DESC *ads = AR6000RXDESC(ds);

    if(ds->dsRxStat.rsRate.flags & WHAL_RC_FLAG_40MHZ) {
        if ((ads->dsStatus5 & 0xff) !=80 && ((ads->dsStatus6 >> 8) & 0xff) !=80)
        	evm = ((ads->dsStatus5 & 0xff) + 
                  ((ads->dsStatus5 >> 8) & 0xff) + 
                  ((ads->dsStatus5 >> 16) & 0xff) + 
                  ((ads->dsStatus5 >> 24) & 0xff) + 
                  ((ads->dsStatus6 >> 0) & 0xff) + 
                  ((ads->dsStatus6 >> 8) & 0xff)) / 6;
        else
            evm = 0;
    } 
    else {
        if ((ads->dsStatus5 & 0xff) !=80)
            evm = ((ads->dsStatus5 & 0xff) + 
                  ((ads->dsStatus5 >> 8) & 0xff) + 
                  ((ads->dsStatus5 >> 16) & 0xff) + 
                  ((ads->dsStatus5 >> 24) & 0xff)) / 4;
        else
            evm=0;
    }
    return evm;
}

A_INT32 processRxDescriptorEvm1(WHAL_RX_DESC *ds)
{
    A_INT32 evm;

    AR6000_RX_DESC *ads = AR6000RXDESC(ds);

    if(ds->dsRxStat.rsRate.flags & WHAL_RC_FLAG_40MHZ) {
        if (((ads->dsStatus6 >> 16) & 0xff) !=80 && ((ads->dsStatus7 >> 24) & 0xff) !=80)
            evm =(((ads->dsStatus6 >> 16) & 0xff) + 
                  ((ads->dsStatus6 >> 24) & 0xff) + 
                  ((ads->dsStatus7 >> 0) & 0xff) + 
                  ((ads->dsStatus7 >> 8) & 0xff) + 
                  ((ads->dsStatus7 >> 16) & 0xff) +
                  ((ads->dsStatus7 >> 24) & 0xff)) / 6;
        else
            evm = 0;
    } 
    else {
        if ((ads->dsStatus6 & 0xff) !=80)
            evm = ((ads->dsStatus6 & 0xff) + 
                  ((ads->dsStatus6 >> 8) & 0xff) + 
                  ((ads->dsStatus6 >> 16) & 0xff) + 
                  ((ads->dsStatus6 >> 24) & 0xff)) / 4;
        else
            evm=0;
    }
    return evm;
}

A_INT32 processRxDescriptorEvm2(WHAL_RX_DESC *ds)
{
    A_INT32 evm;

    AR6000_RX_DESC *ads = AR6000RXDESC(ds);

    if(ds->dsRxStat.rsRate.flags & WHAL_RC_FLAG_40MHZ) {
        if ((ads->dsStatus8 & 0xff) !=80 && ((ads->dsStatus9 >> 8) & 0xff) !=80)
            evm =(((ads->dsStatus8 >> 0) & 0xff) +
                  ((ads->dsStatus8 >> 8) & 0xff) +
                  ((ads->dsStatus8 >> 16) & 0xff) +
                  ((ads->dsStatus8 >> 24) & 0xff) +
                  ((ads->dsStatus9 >> 0) & 0xff) +
                  ((ads->dsStatus9 >> 8) & 0xff)) / 6;
        else
            evm = 0;
    }
    else {
        if ((ads->dsStatus7 & 0xff) !=80)
            evm = ((ads->dsStatus7 & 0xff) +
                  ((ads->dsStatus7 >> 8) & 0xff) +
                  ((ads->dsStatus7 >> 16) & 0xff) +
                  ((ads->dsStatus7 >> 24) & 0xff)) / 4;
        else
            evm=0;
    }
    return evm;
}
#endif

static void copyLinkRxStatEntriesandZero(int destIdx, int sourceIdx)
{
    RX_STATS_STRUCT_UTF *rxStat_dst = tcmdLinkTRx.rxStats[destIdx];
    RX_STATS_STRUCT_UTF *rxStat_src = tcmdLinkTRx.rxStats[sourceIdx];

    if ( (rxStat_dst == NULL) || (rxStat_src == NULL) )
    {
    	//A_PRINTF("DestIdx %d sourceIdx %d\n",destIdx, sourceIdx);
	return;
    }
    else
    {
		rxStat_dst->totalPackets += rxStat_src->totalPackets;
		rxStat_dst->goodPackets += rxStat_src->goodPackets;
		rxStat_dst->crcPackets += rxStat_src->crcPackets;
		rxStat_dst->decrypErrors += rxStat_src->decrypErrors;
		rxStat_dst->otherError += rxStat_src->otherError;
		rxStat_dst->byteCount += rxStat_src->byteCount;
		if (rxStat_dst->startTime == 0) {
			rxStat_dst->dontCount += rxStat_src->dontCount;
		}

		rxStat_src->totalPackets = 0;
		rxStat_src->goodPackets = 0;
		rxStat_src->crcPackets = 0;
		rxStat_src->decrypErrors = 0;
		rxStat_src->otherError = 0;
		rxStat_src->byteCount = 0;
		rxStat_src->dontCount = 0;
    }
}

#define HT20 	0
#define HT40 	1
#define VHT20 	2
#define VHT40 	3
#define VHT80 	4
#define VHT80P80 5
#define VHT160 	 6    

#define DEFAULT_NOISE_FLOOR (-96)
///TODO: revisit this for 11AC...
#define RATE_UNKNOWN TCMD_MAX_RATES

extern RXGAIN_CAL_DATA_I gRxGainCal4Chan;

// Calculate the rssi compensation based on Norman abd Gerald's temp solution
A_INT32 rssiInDBMComp(A_UINT8 chainIdx, A_UINT8 rssiCombo) 
{ 
   A_INT32 rssiComp = 0;
   A_INT8 i;

   if (1 == rssiCombo)     // do average on 4 chains
   {   
       for (i=0; i<4; i++)
       {
	      rssiComp += (A_INT32)gRxGainCal4Chan.rxNFCalPowerDBm[i];
       }   
	   rssiComp = rssiComp / 4; 
   }
   else
   {
       rssiComp = (A_INT32)gRxGainCal4Chan.rxNFCalPowerDBm[chainIdx];
   }
   
   //A_PRINTF("lim_ rssiInDBMComp-rssiCombo:  chain %d rssiComp %d rssiCombo %d\n",chainIdx, rssiComp, rssiCombo);
   return (rssiComp);
}
extern A_UINT32 Rate2MaskBitNo[MASK_RATE_MAX];

A_UINT32 processRxDataStats(A_UINT32 rIdx, A_UINT32 frame_length, A_UCHAR rsStatus, struct wal_rx_status *status) 
{
    struct rx_attention *attention = &status->rx_desc.attention;
    struct rx_ppdu_start *ppdu_start = &status->rx_desc.ppdu_start;
    struct rx_ppdu_end *ppdu_end = &status->rx_desc.ppdu_end;
    RX_STATS_STRUCT_UTF *rxStat = tcmdLinkTRx.rxStats[rIdx];
    A_UINT32 rsTstamp;
    A_UINT32 chain;
    A_BOOL agg = 0;
    A_BOOL moreAgg = 0;
    A_UINT32 avgEvm = 0;
    A_UINT8 bandwidth = 0;
	int istream = 0;

    //A_PRINTF("rsStatus = %d \n", rsStatus);  
	
    if (rxStat == NULL)
    {
    	//A_PRINTF("rxStat==NULL\n");
        return 0;
    }

    if (!(attention->first_mpdu && attention->last_mpdu))
    {
        agg = 1;

        /* if this is an aggregated packet then we will need to check if this is the last sub-frame first, 
         * as only the last sub-frame has the complete status 
         */
        if (!attention->last_mpdu)
        {
 //           rxStat = tcmdLinkTRx.rxStats[RATE_UNKNOWN];/* all the sub-frame (except last one) information will be recorded in last entry in rxStats */
//            rxStat->rateBit = 0;/* set to something that is valid */
            moreAgg = 1;/* this is not the last sub-frame */
        }
    }

    if (agg && !moreAgg)
    {
        copyLinkRxStatEntriesandZero(rIdx, RATE_UNKNOWN);/* add in unknown rate information,that is the aggregrate-subframes information */
    }

    if (!moreAgg)
    {
        /* timestamp is only valid for regular frames and last sub-frame of an aggregate */
        rsTstamp = ppdu_end->wb_timestamp;
        if (rxStat->startTime == 0)
        {
            rxStat->startTime = rsTstamp;
            if (!rsStatus)
                rxStat->dontCount += frame_length;
        }
        rxStat->endTime = rsTstamp;
    }

    chain = ppdu_end->rx_antenna & 3;

    bandwidth = HT20;
   // A_PRINTF("rxStat->rateBit = %d \n", rxStat->rateBit);


    if ( rxStat->rateBit <= Rate2MaskBitNo[ATH_RATE_65M] ) { // HT20 or lower
        bandwidth = HT20;
    } 
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_HT40_13_5M] && rxStat->rateBit <= Rate2MaskBitNo[ATH_RATE_HT40_135M]) { // HT40
        bandwidth = HT40;
    } 
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_HT20_MCS8_13M] && rxStat->rateBit <= Rate2MaskBitNo[ATH_RATE_HT20_MCS15_130M]) { // HT20
        bandwidth = HT20;
    } 	
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_HT40_MCS8_27M] && rxStat->rateBit <= Rate2MaskBitNo[ATH_RATE_HT40_MCS15_270M]) { // HT40
        bandwidth = HT40;
    }	
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_HT20_MCS16_19_5M] && rxStat->rateBit <= Rate2MaskBitNo[ATH_RATE_HT20_MCS23_195M]) { // HT20
        bandwidth = HT20;
    }	
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_HT40_MCS16_40_5M] && rxStat->rateBit <= Rate2MaskBitNo[ATH_RATE_HT40_MCS23_405M]) { // HT40
        bandwidth = HT40;
    } 	
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_VHT20_NSS1_MCS0] && rxStat->rateBit <= Rate2MaskBitNo[ATH_RATE_VHT20_NSS1_MCS9]) { // VHT20
        bandwidth = VHT20;
    } 
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_VHT40_NSS1_MCS0] && rxStat->rateBit <= Rate2MaskBitNo[ATH_RATE_VHT40_NSS1_MCS9]) { // VHT40
        bandwidth = VHT40;
    } 
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_VHT80_NSS1_MCS0] && rxStat->rateBit <= Rate2MaskBitNo[ATH_RATE_VHT80_NSS1_MCS9]) { // VHT80
        bandwidth = VHT80;
    } 
   else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_VHT20_NSS2_MCS0] && rxStat->rateBit <=Rate2MaskBitNo[ATH_RATE_VHT20_NSS2_MCS9] ) { // VHT20
        bandwidth = VHT20;
    } 
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_VHT40_NSS2_MCS0] && rxStat->rateBit <=Rate2MaskBitNo[ATH_RATE_VHT40_NSS2_MCS9] ) { // VHT40
        bandwidth = VHT40;
    } 
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_VHT80_NSS2_MCS0] && rxStat->rateBit <=Rate2MaskBitNo[ATH_RATE_VHT80_NSS2_MCS9] ) { // VHT80
        bandwidth = VHT80;
    } 
   else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_VHT20_NSS3_MCS0] && rxStat->rateBit <=Rate2MaskBitNo[ATH_RATE_VHT20_NSS3_MCS9] ) { // VHT20
        bandwidth = VHT20;
    }	
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_VHT40_NSS3_MCS0] && rxStat->rateBit <=Rate2MaskBitNo[ATH_RATE_VHT40_NSS3_MCS9] ) { // VHT40
        bandwidth = VHT40;
    } 	
    else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_VHT80_NSS3_MCS0] && rxStat->rateBit <=Rate2MaskBitNo[ATH_RATE_VHT80_NSS3_MCS9] ) { // VHT80
        bandwidth = VHT80;
    } 	
	else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_VHT160_NSS1_MCS0] && rxStat->rateBit <=Rate2MaskBitNo[ATH_RATE_VHT160_NSS2_MCS5] ) { // VHT160 or 80P80  
        bandwidth = VHT160;
        //bandwidth = VHT80;     // the rssi calculation is same as HT80
    }
	else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_HT20_MCS24] && rxStat->rateBit <=Rate2MaskBitNo[ATH_RATE_HT20_MCS31] ) { // HT20
        bandwidth = HT20;
    }
	else if (rxStat->rateBit >= Rate2MaskBitNo[ATH_RATE_HT40_MCS24] && rxStat->rateBit <=Rate2MaskBitNo[ATH_RATE_HT40_MCS31] ) { // HT40
        bandwidth = HT40;
    }		

    rxStat->totalPackets++;
    if (!rsStatus)
    {
        rxStat->goodPackets++;
        rxStat->byteCount += frame_length;
        if (rxStat->startTime == 0)
            rxStat->dontCount += frame_length;

        if (!moreAgg)
        {
            A_INT32 noise_floor = whalGetNf();

			// using RXG calibration data
		    noise_floor = rssiInDBMComp(0, 1);
			
            if(!noise_floor) {
               noise_floor = DEFAULT_NOISE_FLOOR;
            }

            rxStat->rssi += (ppdu_start->rssi_comb + noise_floor);

			// using RXG calibration data
            rxStat->rssic[0] += (ppdu_start->rssi_pri_chain0 + rssiInDBMComp(0, 0));      		
            rxStat->rssie[0] += (ppdu_start->rssi_sec20_chain0);  // rssiInDBMComp(0));		
			
#ifdef TODO
            rxStat->rssie1[0] += ppdu_start->rssi_sec40_chain0;
            rxStat->rssie2[0] += ppdu_start->rssi_sec80_chain0;
#endif
            rxStat->rssic[1] += (ppdu_start->rssi_pri_chain1 + rssiInDBMComp(1, 0));
            rxStat->rssie[1] += ppdu_start->rssi_sec20_chain1;
#ifdef TODO
            rxStat->rssie1[1] += ppdu_start->rssi_chain1_sec40;
            rxStat->rssie2[1] += ppdu_start->rssi_chain1_sec80;
#endif
            rxStat->rssic[2] += (ppdu_start->rssi_pri_chain2 + rssiInDBMComp(2, 0));
            rxStat->rssie[2] += ppdu_start->rssi_sec20_chain2;

#ifdef TODO
            rxStat->rssie1[2] += ppdu_start->rssi_chain2_sec40;
            rxStat->rssie2[2] += ppdu_start->rssi_chain2_sec80;
#endif
            rxStat->rssic[3] += (ppdu_start->rssi_pri_chain3 + rssiInDBMComp(3, 0));
	    rxStat->rssie[3] += ppdu_start->rssi_sec20_chain3;

//A_PRINTF("chain %d rateBit %d bandwidth %d\n",chain,rxStat->rateBit,bandwidth);

//A_PRINTF("evm_p0 %d evm_p1 %d evm_p2 %d evm_p3 %d\n",ppdu_end->evm_p0 , ppdu_end->evm_p1 , ppdu_end->evm_p2 , ppdu_end->evm_p3);
//A_PRINTF("evm_p4 %d evm_p5 %d evm_p6 %d evm_p7 %d\n",ppdu_end->evm_p4 , ppdu_end->evm_p5 , ppdu_end->evm_p6 , ppdu_end->evm_p7);
		for(istream = chain; istream < MSTREAM_UTF; istream++){
                if ( (bandwidth == HT20) || (bandwidth == VHT20) )
                {
                    avgEvm = ( ((ppdu_end->evm_p0 >> (istream *8)) & 0xFF) + ((ppdu_end->evm_p1 >> (istream *8)) & 0xFF) + 
					((ppdu_end->evm_p2 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p3 >> (istream *8)) & 0xFF) )/4;
		    rxStat->pilotevm[istream][0] += ((ppdu_end->evm_p0 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][1] += ((ppdu_end->evm_p1 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][2] += ((ppdu_end->evm_p2 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][3] += ((ppdu_end->evm_p3 >> (istream *8)) & 0xFF);
			
                }
                else if ( (bandwidth == HT40) || (bandwidth == VHT40) )
                {
                    avgEvm = ( ((ppdu_end->evm_p0 >> (istream *8)) & 0xFF) + ((ppdu_end->evm_p1 >> (istream *8)) & 0xFF) + 
				((ppdu_end->evm_p2 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p3 >> (istream *8)) & 0xFF)  +
                                ((ppdu_end->evm_p4 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p5 >> (istream *8)) & 0xFF) )/6;
		    rxStat->pilotevm[istream][0] += ((ppdu_end->evm_p0 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][1] += ((ppdu_end->evm_p1 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][2] += ((ppdu_end->evm_p2 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][3] += ((ppdu_end->evm_p3 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][4] += ((ppdu_end->evm_p4 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][5] += ((ppdu_end->evm_p5 >> (istream *8)) & 0xFF);
		    
                }
                else if(bandwidth == VHT80)//VHT80
                {
                    avgEvm = ( ((ppdu_end->evm_p0 >> (istream *8)) & 0xFF) + ((ppdu_end->evm_p1 >> (istream *8)) & 0xFF)    + 
				((ppdu_end->evm_p2 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p3 >> (istream *8)) & 0xFF)  +
                                ((ppdu_end->evm_p4 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p5 >> (istream *8)) & 0xFF)  +
                                ((ppdu_end->evm_p6 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p7 >> (istream *8)) & 0xFF) )/8;
		    rxStat->pilotevm[istream][0] += ((ppdu_end->evm_p0 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][1] += ((ppdu_end->evm_p1 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][2] += ((ppdu_end->evm_p2 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][3] += ((ppdu_end->evm_p3 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][4] += ((ppdu_end->evm_p4 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][5] += ((ppdu_end->evm_p5 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][6] += ((ppdu_end->evm_p6 >> (istream *8)) & 0xFF);
		    rxStat->pilotevm[istream][7] += ((ppdu_end->evm_p7 >> (istream *8)) & 0xFF);
                } else { //VHT160 
                    avgEvm = ( ((ppdu_end->evm_p0 >> (istream *8)) & 0xFF) + ((ppdu_end->evm_p1 >> (istream *8)) & 0xFF)    + 
								((ppdu_end->evm_p2 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p3 >> (istream *8)) & 0xFF)  +
                                ((ppdu_end->evm_p4 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p5 >> (istream *8)) & 0xFF)  +
                                ((ppdu_end->evm_p6 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p7 >> (istream *8)) & 0xFF)  +
                                ((ppdu_end->evm_p8 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p9 >> (istream *8)) & 0xFF)  +
                                ((ppdu_end->evm_p10 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p11 >> (istream *8)) & 0xFF)  +
                                ((ppdu_end->evm_p12 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p13 >> (istream *8)) & 0xFF)  +
                                ((ppdu_end->evm_p14 >> (istream *8)) & 0xFF) + (( ppdu_end->evm_p15 >> (istream *8)) & 0xFF)  )/16;
								
					rxStat->pilotevm[istream][0] += ((ppdu_end->evm_p0 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][1] += ((ppdu_end->evm_p1 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][2] += ((ppdu_end->evm_p2 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][3] += ((ppdu_end->evm_p3 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][4] += ((ppdu_end->evm_p4 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][5] += ((ppdu_end->evm_p5 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][6] += ((ppdu_end->evm_p6 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][7] += ((ppdu_end->evm_p7 >> (istream *8)) & 0xFF);				

					rxStat->pilotevm[istream][8] += ((ppdu_end->evm_p8 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][9] += ((ppdu_end->evm_p9 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][10] += ((ppdu_end->evm_p10 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][11] += ((ppdu_end->evm_p11 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][12] += ((ppdu_end->evm_p12 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][13] += ((ppdu_end->evm_p13 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][14] += ((ppdu_end->evm_p14 >> (istream *8)) & 0xFF);
					rxStat->pilotevm[istream][15] += ((ppdu_end->evm_p15 >> (istream *8)) & 0xFF);					
				}
				
                rxStat->evm[istream] += avgEvm;//processRxDescriptorEvm0(ds);
//A_PRINTF("avgEvm %d rssic %d rssie %d\n",rxStat->evm[istream],rxStat->rssic[0],rxStat->rssie[0]);
        }
#if 0
            rxStat->evm[0] += ppdu_end->evm_p0;//processRxDescriptorEvm0(ds);
            rxStat->evm[1] += ppdu_end->evm_p1;//processRxDescriptorEvm1(ds);
            rxStat->evm[2] += ppdu_end->evm_p2;//processRxDescriptorEvm2(ds);
#endif

            rxRssiEvmSamplesGood[rIdx]++;
        }
    }
    else
    {
        if (rsStatus & WHAL_RXERR_CRC)
            rxStat->crcPackets++;
        else if (rsStatus & WHAL_RXERR_DECRYPT)
            rxStat->decrypErrors++;
        else
            rxStat->otherError++;

        if (!moreAgg) {
            rxRssiEvmSamplesBad[rIdx]++;
        }
    }
    return 1;
}

A_BOOL rxDataStatsReport(A_UINT32 rIdx, A_UINT8 *outBuf)
{
    RX_STATS_STRUCT_UTF *rxStat = tcmdLinkTRx.rxStats[rIdx];
    A_INT32 samples;
	int istream = 0, ipilot = 0;

    if (rxStat == NULL)/* if stats for this rate has been reported to host or host did not request it */
        return 0;

    samples = rxRssiEvmSamplesGood[rIdx];
    if (samples) {
        rxStat->rssi /= samples;
        rxStat->rssic[0] /= samples;
        rxStat->rssic[1] /= samples;
        rxStat->rssic[2] /= samples;
	rxStat->rssic[3] /= samples;
        rxStat->rssie[0] /= samples;
        rxStat->rssie[1] /= samples;
        rxStat->rssie[2] /= samples;
	rxStat->rssie[3] /= samples;
        rxStat->evm[0] /= samples;
        rxStat->evm[1] /= samples;
        rxStat->evm[2] /= samples;
	rxStat->evm[3] /= samples;
	
		for(istream = 0; istream < MSTREAM_UTF; istream++){
			for(ipilot = 0; ipilot < MAX_PILOT_UTF; ipilot++)
				rxStat->pilotevm[istream][ipilot] /= samples;
		}
    }

    samples = rxRssiEvmSamplesBad[rIdx];
    if (samples) {
        rxStat->badrssi /= samples;
        rxStat->badrssic[0] /= samples;
        rxStat->badrssic[1] /= samples;
        rxStat->badrssic[2] /= samples;
	rxStat->badrssic[3] /= samples;
        rxStat->badrssie[0] /= samples;
        rxStat->badrssie[1] /= samples;
        rxStat->badrssie[2] /= samples;
	rxStat->badrssie[3] /= samples;
        rxStat->badevm[0] /= samples;
        rxStat->badevm[1] /= samples;
        rxStat->badevm[2] /= samples;
	rxStat->badevm[3] /= samples;
    }

    A_MEMCPY(outBuf, rxStat, sizeof(RX_STATS_STRUCT_UTF));
    rxRssiEvmSamplesGood[rIdx] = 0;
    rxRssiEvmSamplesBad[rIdx] = 0;

    if ( rxStat != NULL )
    {
    
	//A_PRINTF("RXG rssiInDBMComp:  chain %d rssiComp %d\n",chainIdx, rssiComp );
        //A_FREE(rxStat);
        current_pool_stat_buf();
        return_all_stat_buf();
        tcmdLinkTRx.rxStats[rIdx] = NULL;
    }

//    rxStat->rateBit = TCMD_INVALID_RATEBIT;/* indicates this report is done */
    return 1;
}


void setupTcmdParms (TCMD_CONT_TX *pTcmdParms, TX_DATA_START_PARAMS *pParms)
{
    memcpy(pTcmdParms, pParms, sizeof(TCMD_CONT_TX));
    
    //pTcmdParms->miscFlags &= (~PAPRD_ENA_MASK);/* disabling PAPRD for NART for now */
}

void tcmd_link_trx_init()
{
    A_UINT32 i;
    static A_BOOL init = FALSE;

    if ( init == FALSE )
    {
        A_MEMZERO(&tcmdLinkTRx,sizeof(tcmd_link_trx));
        alloc_pool_stat_init();
    }
    else {
        return_all_stat_buf();
    }

    for (i=0;i<TCMD_MAX_RATES;i++)
    {
#if 0
        if ( init == TRUE )
        {
            if ( tcmdLinkTRx.rxStats[i] != NULL )
                //A_FREE(tcmdLinkTRx.rxStats[i]);

            if ( tcmdLinkTRx.txStats[i] != NULL )
                //A_FREE(tcmdLinkTRx.txStats[i]);
        }
#endif

        tcmdLinkTRx.rxStats[i]= NULL;
        tcmdLinkTRx.txStats[i]= NULL;
        /* default it to TCMD_INVALID_RATEBIT, if it's not the default value then 
           it means host requested report for it */
        rxRssiEvmSamplesGood[i] = 0;
        rxRssiEvmSamplesBad[i] = 0;
        txRssiEvmSamples[i] = 0;
        tcmdLinkTRx.txDataRates[i] = 0;
        tcmdLinkTRx.txPwr[i] = 0;
        tcmdLinkTRx.pktLength[i] = 0;
    }

    tcmdLinkTRx.currentTx = 0;
    tcmdLinkTRx.totalToTx = 0;

    init = TRUE;
}

void tcmdLinkTx(wlan_tcmd_dev_t *dev)
{
#if 0
    const WHAL_RATE_TABLE *rt;
#endif
    A_UINT32 dataRate;

    if (tcmdLinkTRx.currentTx >= tcmdLinkTRx.totalToTx) {
        return;
    }
    
    tx_tcmdParms.dataRate = tcmdLinkTRx.txDataRates[tcmdLinkTRx.currentTx];

    if (tx_tcmdParms.dataRate >= TCMD_11AC3x3_MAX_RATES &&  tx_tcmdParms.dataRate <= (TCMD_11AC3x3_MAX_RATES+2))// (TCMD_MAX_RATES-TCMD_NUM_CCK_RATES))/* CCK short preamble */
        dataRate = tx_tcmdParms.dataRate -  (TCMD_11AC3x3_MAX_RATES - 1); //(TCMD_MAX_RATES-TCMD_NUM_CCK_RATES);
    else
        dataRate = tx_tcmdParms.dataRate;

#if 0
    rt = whalGetRateTable(dev->ic_curmode);
    if (!RT_IS_HT(rt,dataRate)) {
#if defined(_CCK_MODE_DONOT_MATTER)
        if (RT_GET_PHY(rt,dataRate) == WHAL_MOD_IEEE80211_T_CCK) {
            tx_tcmdParms.wlanMode = TCMD_WLAN_MODE_CCK;
        else
#endif
            tx_tcmdParms.wlanMode = TCMD_WLAN_MODE_NOHT;
    }
#endif

    if (tx_tcmdParms.mode == TCMD_CONT_TX_FRAME)
        tx_tcmdParms.mode |= 0x100;/* do not wait for tx complete, setting this fiag then the transmit status will be polled in the interrupt */

/// FOR MPS
    tx_tcmdParms.txPwr = tcmdLinkTRx.txPwr[tcmdLinkTRx.currentTx];
    tx_tcmdParms.pktSz = tcmdLinkTRx.pktLength[tcmdLinkTRx.currentTx];

//A_PRINTF("bf: tcmd_cont_tx_cmd: txPwr %d pktSz %d currIdx %d\n",tx_tcmdParms.txPwr,tx_tcmdParms.pktSz,tcmdLinkTRx.currentTx);

#if 0
    if (tx_tcmdParms.txPwr < 0){
        /* somehow cart/nart is passing minus value if pcdac is not specified in cart, minus value causes tx problem */
        tx_tcmdParms.txPwr = 0;
    }
    if (!RT_IS_HT(rt,dataRate)) {/* if cck & legacy rates */
        /* aggreation only works on HT rates, 
         * if this is CCK/legacy rates then we need to multiply numPackets by aggregation number 
         * this is because Nart always sends numPackets=total/agg down to UTF 
         * so for CCK we will recover the numPackets back to equal to total */
        if (tx_tcmdParms.agg > 1)
            tx_tcmdParms.numPackets*=tx_tcmdParms.agg;
    }

    utfTxChannelSetup(dev, &tx_tcmdParms);
    utfTxStart(dev, &tx_tcmdParms);
#endif
    tcmd_cont_tx_cmd (dev, &tx_tcmdParms);
}

#define __HEADER_LENGTH 34
#define __MINIMUM_AIFS_TIME         84
#define __MAXIMUM_PAYLOAD_LENGTH  3000       
#define __SLOT_TIME 9
#define __SLOT_TIME_LONG 20
#define __SIFS_TIME 16
#define __PREAMBLE_TIME_CCK_SHORT  96
#define __PREAMBLE_TIME_CCK_LONG   192
#define __PREAMBLE_TIME_OFDM       20
#define __PREAMBLE_TIME_11AC_OFDM       40

/* Matched with _AthDataRate*/
const static A_UINT32 rateMbps[RATE_POWER_MAX_INDEX*32] =  {
		  1,   2,   5,  11,       //CCK
		  6,   9,  12,  18,  24,  36,   48,   54,               //OFDM
		  6,  13,  19,  26,  39,  52,   58,   65,               //HT20 MCS0-7
		 13,  26,  39,  52,  78, 104,  117,  130,               //HT20 MCS8-15
		 19,  39,  58,  78, 117, 156,  175,  195,               //HT20 MCS16-23
		 13,  27,  40,  54,  81, 108,  121,  135,               //HT40 MCS0-7
		 27,  54,  81, 108, 162, 216,  243,  270,               //HT40 MCS8-15
		 40,  81, 121, 162, 243, 324,  364,  405,               //HT40 MVC16-23
		  6,  13,  19,  26,  39,  52,   58,   65,   78,   86,   //vHT20 MCS0-9
		 13,  26,  39,  52,  78, 104,  117,  130,  156,  173,   //vHT20 MCS10-19
		 19,  39,  58,  78, 117, 156,  175,  195,  234,  260,   //vHT20 MCS20-29
		 13,  27,  40,  54,  81, 108,  121,  135,  162,  180,   //vHT40 MCS0-9
		 27,  54,  81, 108, 162, 216,  243,  270,  324,  360,   //vHT40 MCS10-19
		 40,  81, 121, 162, 243, 324,  364,  405,  486,  540,   //vHT40 MCS20-29
		 29,  58,  87, 117, 175, 234,  263,  292,  351,  390,   //vHT80 MCS0-9
		 58, 117, 175, 234, 351, 468,  526,  585,  702,  780,   //vHT80 MCS10-19
		 87, 175, 263, 351, 526, 702,  789,  877, 1053, 1170,   //vHT80 MCS20-29
		  2,   5,  11,
		 26,  52,  78, 104, 156, 208,  234,  260,  312,  344,   //vHT20 MCS30-39
		 54, 108, 162, 216, 324, 432,  486,  540,  648,  720,   //vHT40 MCS30-39
		117, 234, 351, 468, 702, 936, 1053, 1170, 1404, 1560,   //vHT80 MCS20-29
		 58, 117, 175, 234, 351, 468,  526,  585,  702,  780,   //vHT160 MCS0-9
		117, 234, 351, 468, 702, 936, 1053, 1170, 1404, 1560,   //vHT160 MCS10-19
    };

A_UINT32 processTxStatusStartPerRate (wlan_tcmd_dev_t *dev, _CMD_TX_PARMS *pTxParm)
{
    A_UINT32 k;
    A_UINT32 dataRate;
    A_UINT8 rateMaskRowOffset;
    A_UINT8 rateMaskIndex;
    A_UINT32 rateMaskInfo = 0;
    A_UINT32 txPower;
    A_UINT8 dutycycle=1;
    A_UINT8 preamble=__PREAMBLE_TIME_OFDM, slotime=__SLOT_TIME;

    tcmd_link_trx_init();
    dataRate = 0;
// FOR MPS
    for (k=0; k<RATE_POWER_MAX_INDEX; k++){


    	if (k == RATE_POWER_MAX_INDEX-1)
    		rateMaskInfo = (A_UINT32)pTxParm->rateBitIndex8;
    	else
    		rateMaskInfo = pTxParm->rateBitIndex[k];

         if (rateMaskInfo == 0xFF )
             break;
         rateMaskRowOffset = rateMaskInfo/32;

         if (rateMaskRowOffset >= 1 ){
             rateMaskIndex = rateMaskInfo-(32*rateMaskRowOffset);
         }
         else{
             rateMaskIndex = rateMaskInfo;
         }

#if 0
        if ( (rateMaskIndex >= RATE_MASK_BIT_MAX) || ( rateMaskRowOffset >= RATE_MASK_ROW_MAX) ) {
            uiPrintf("Invalid rateMaskIndex %d rowOffset %d\n",rateMaskIndex,rateMaskRowOffset);
            return(COMMS_ERR_BAD_OFFSET);
        }
#endif
        txPower = pTxParm->txPower[k];

        tcmdLinkTRx.txDataRates[tcmdLinkTRx.totalToTx] = dataRate = (int)Mask2Rate[rateMaskRowOffset][rateMaskIndex];
        tcmdLinkTRx.txPwr[tcmdLinkTRx.totalToTx] = txPower;
        tcmdLinkTRx.pktLength[tcmdLinkTRx.totalToTx] = pTxParm->pktLen[k];

       // if ( pTxParm->txMode != TCMD_CONT_TX_SINE ) {
            //tcmdLinkTRx.txStats[tcmdLinkTRx.totalToTx] = (TX_STATS_STRUCT_UTF*)A_ALLOCRAM(sizeof(TX_STATS_STRUCT_UTF));
            tcmdLinkTRx.txStats[tcmdLinkTRx.totalToTx] = (TX_STATS_STRUCT_UTF*)get_pool_stat_buf();
            tcmdLinkTRx.txStats[tcmdLinkTRx.totalToTx]->rateBit = (rateMaskRowOffset * 32) + rateMaskIndex;
        //}
//A_PRINTF("RateBit %d\n",pTxStat->rateBit);


       /* 1. set the binumber here so we don't need to do this again when sending report, it's easy to do it here too
 * as converting rate number back to bit position in the ratemask is a little bit more difficult than doing it here 
 *      * 2. use it to indicates that this is a rate that host wants the transmit report,
 **    if it's set to TCMD_INVALID_RATEBIT then that means host has no interest on that rate */
        if (dataRate == ATH_RATE_2M || dataRate == ATH_RATE_5_5M || dataRate == ATH_RATE_11M){ /* CCK rates */
        	preamble = __PREAMBLE_TIME_CCK_SHORT; /* dutycycle calculation */
        	if (!(rateMaskIndex&1)) {/* even number indicates short preamble, see Mask2Rate array for details */
                        tcmdLinkTRx.txDataRates[tcmdLinkTRx.totalToTx] += (TCMD_11AC3x3_MAX_RATES - 1); /* use rateIndex 150, 151, 152 in the rate table for CCK shortPreamble */
                        slotime = __SLOT_TIME_LONG; /* dutycycle calculation */
                        preamble = __PREAMBLE_TIME_CCK_LONG; /* dutycycle calculation */
        	}
        }

        if (++tcmdLinkTRx.totalToTx >= TCMD_MAX_RATES) {
           tcmdLinkTRx.totalToTx = 0;
        }

       // cont Tx support, only 1 rate
       if (!tx_tcmdParms.numPackets) {break;}
    }

    /* dutycycle calculation */
    dutycycle = pTxParm->dutyCycle;

    if(pTxParm->txMode == TCMD_CONT_TX_FRAME && dutycycle > 0) {

        A_UINT32 newPktSz, activeTime, inactiveTime, newDutyCycle;
        if(dutycycle > 99)dutycycle = 99;
        
        if(dataRate > ATH_RATE_HT40_MCS23_405M) /*11AC rates*/
            preamble = __PREAMBLE_TIME_11AC_OFDM;

        /* Assume one whole cycle takes 600us */
        activeTime = 600 * dutycycle / 100;
        if(activeTime<=preamble){
            newPktSz = 1;
        }else{
            newPktSz = ((activeTime - preamble)*rateMbps[dataRate])/8;
            if(newPktSz <= __HEADER_LENGTH){
                newPktSz = 1;
            }else{
                newPktSz -= __HEADER_LENGTH;
            }
        }
        
        if(newPktSz > __MAXIMUM_PAYLOAD_LENGTH)newPktSz=__MAXIMUM_PAYLOAD_LENGTH;
        
        activeTime = ((newPktSz+__HEADER_LENGTH)*8 / rateMbps[dataRate]) + preamble;
        inactiveTime = activeTime * (100-dutycycle) / dutycycle;
        if(inactiveTime > 1023)inactiveTime = 1023;
 
        if(inactiveTime>__MINIMUM_AIFS_TIME){
            tx_tcmdParms.aifsn = (inactiveTime-__SIFS_TIME)/__SLOT_TIME;
        }else{
            /* Setting aifsn to minimum still can's achieve the ratio, re-calculate packet size */
            tx_tcmdParms.aifsn = 0;
            inactiveTime = __MINIMUM_AIFS_TIME;
            activeTime = inactiveTime * dutycycle / (100-dutycycle) ;
            newPktSz = (activeTime - preamble) * rateMbps[dataRate] / 8 - __HEADER_LENGTH;
            if(newPktSz > __MAXIMUM_PAYLOAD_LENGTH)newPktSz=__MAXIMUM_PAYLOAD_LENGTH;
        }
        
        tcmdLinkTRx.pktLength[tcmdLinkTRx.currentTx] = newPktSz;
        activeTime = ((newPktSz+__HEADER_LENGTH)*8 / rateMbps[dataRate]) + preamble;
        newDutyCycle = tx_tcmdParms.aifsn?
            ((activeTime * 100)/((activeTime+(tx_tcmdParms.aifsn * __SLOT_TIME)))):
            ((activeTime * 100)/(activeTime+__MINIMUM_AIFS_TIME));
        tx_tcmdParms.agg = 1;
        
        A_PRINTF_ALWAYS("pktSz %d, activeTime %d, inactiveTime %d,\n", newPktSz, activeTime, inactiveTime);
        A_PRINTF_ALWAYS("input dutycycle %d, final dutycycle %d, aifsn %d\n", dutycycle, newDutyCycle, tx_tcmdParms.aifsn);
       
    }

    tcmdLinkTx(dev);

    return 0;
}

#undef __TX_FRAME_DURATION
#undef __SLOT_TIME
#undef __MAX_NUM_SLOTS
#undef __PREAMBLE_TIME_CCK_SHORT
#undef __PREAMBLE_TIME_CCK_LONG
#undef __PREAMBLE_TIME_OFDM
/**************************************************************************
* processTxDataStartCmd - Process TX_DATA_START_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processTxDataStartCmd (wlan_tcmd_dev_t *dev,_CMD_NARTCMD_PARMS *pCmd)
{
    TX_DATA_START_PARAMS *pParms;
    A_UINT32            k;
    A_UINT32            dataRate;
    A_UINT8 rateMaskRowOffset;
    A_UINT8 rateMaskIndex;
    A_UINT32 rateMaskInfo = 0;
    A_UINT8 txPower;
    TX_STATS_STRUCT_UTF *pTxStat;

    pParms = (TX_DATA_START_PARAMS*)pCmd->data;

    //A_PRINTF("mode %d numPackets %d freq %d txPwr %d\n",pParms->mode,pParms->numPackets,pParms->freq,pParms->txPower[0]);

    setupTcmdParms(&tx_tcmdParms, pParms);
    
    // Check for single carrier here
    if (pParms->mode == TCMD_CONT_TX_SINE)
    {
    	tcmd_cont_tx_cmd (dev, &tx_tcmdParms);
    	return 0;
    }
     							
#if 0
    deregisterTxCallback();
    registerTxCallback((void*)&processTxDataStats,&tx_tcmdParms);/* register for stats update call back */
#endif
    
    tcmd_link_trx_init();

/// FOR MPS
    for (k=0; k<RATE_POWER_MAX_INDEX; k++){
         rateMaskInfo = pParms->rateMaskBitPosition[k];

         if (rateMaskInfo == 0xFF )
             break;

        // A_PRINTF("rateMaskInfo %d\n",rateMaskInfo);

         rateMaskRowOffset = rateMaskInfo/32;

  	 if (rateMaskRowOffset >= 1 ){
             rateMaskIndex = rateMaskInfo-(32*rateMaskRowOffset);
         }
         else{
             rateMaskIndex = rateMaskInfo;
         }

#if 0
        if ( (rateMaskIndex >= RATE_MASK_BIT_MAX) || ( rateMaskRowOffset >= RATE_MASK_ROW_MAX) ) {
            uiPrintf("Invalid rateMaskIndex %d rowOffset %d\n",rateMaskIndex,rateMaskRowOffset);
            return(COMMS_ERR_BAD_OFFSET);
        }	
#endif

        txPower = pParms->txPower[k];

   	//uiPrintf("Rate mask row %d bit position %d tx Power %d\n",rateMaskRowOffset,rateMaskIndex,txPower);

        tcmdLinkTRx.txDataRates[tcmdLinkTRx.totalToTx] = dataRate = (int)Mask2Rate[rateMaskRowOffset][rateMaskIndex];

        //pTxStat = (TX_STATS_STRUCT_UTF*)A_ALLOCRAM (sizeof(TX_STATS_STRUCT_UTF));
        pTxStat = (TX_STATS_STRUCT_UTF*)get_pool_stat_buf();

        tcmdLinkTRx.txStats[tcmdLinkTRx.totalToTx] = pTxStat;
        if (pTxStat)
        {
        	pTxStat->rateBit = (rateMaskRowOffset * 32) + rateMaskIndex;
        }

        tcmdLinkTRx.txPwr[tcmdLinkTRx.totalToTx] = txPower;
        tcmdLinkTRx.pktLength[tcmdLinkTRx.totalToTx] = pParms->pktLength[k];

       /* 1. set the binumber here so we don't need to do this again when sending report, it's easy to do it here too
 * as converting rate number back to bit position in the ratemask is a little bit more difficult than doing it here 
 *      * 2. use it to indicates that this is a rate that host wants the transmit report,
 **    if it's set to TCMD_INVALID_RATEBIT then that means host has no interest on that rate */
        if (dataRate == ATH_RATE_2M || dataRate == ATH_RATE_5_5M || dataRate == ATH_RATE_11M){ /* CCK rates */
           if (!(rateMaskIndex&1)) /* even number indicates short preamble, see Mask2Rate array for details */
                        tcmdLinkTRx.txDataRates[tcmdLinkTRx.totalToTx] += (TCMD_11AC3x3_MAX_RATES - 1);/* use rateIndex 150, 151, 152 in the rate table for CCK shortPreamble */
        }

        if (++tcmdLinkTRx.totalToTx >= TCMD_MAX_RATES) {
           tcmdLinkTRx.totalToTx = 0;
        }

       // cont Tx support, only 1 rate
       if (!tx_tcmdParms.numPackets) {break;}
    }

    //uiPrintf("Total Tx %d\n",tcmdLinkTRx.totalToTx);

    tcmdLinkTx(dev);

    return 0;
}

void sendTxDataStatus(wlan_tcmd_dev_t *dev,A_UINT32 numOfReports)
{
    TX_STATS_STRUCT_UTF *pTxStats;
    A_BOOL ret = FALSE;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;

    pTxStats = (TX_STATS_STRUCT_UTF*)replyBuf;

    ret = createCommand(_OP_TX_STATUS);

    if ( ret == TRUE )
    {
        ret = addParameterToCommand((A_UINT8*)"numOfReports",(A_UINT8*)&numOfReports);

        if ( numOfReports ) {
            ret = addParameterToCommand((A_UINT8*)"totalPackets",(A_UINT8*)&pTxStats->totalPackets);
            ret = addParameterToCommand((A_UINT8*)"goodPackets",(A_UINT8*)&pTxStats->goodPackets);
            ret = addParameterToCommand((A_UINT8*)"underruns",(A_UINT8*)&pTxStats->underruns);
            ret = addParameterToCommand((A_UINT8*)"otherError",(A_UINT8*)&pTxStats->otherError);
            ret = addParameterToCommand((A_UINT8*)"excessRetries",(A_UINT8*)&pTxStats->excessiveRetries);

            ret = addParameterToCommand((A_UINT8*)"rateBit",(A_UINT8*)&pTxStats->rateBit);

            ret = addParameterToCommand((A_UINT8*)"shortRetry",(A_UINT8*)&pTxStats->shortRetry);
            ret = addParameterToCommand((A_UINT8*)"longRetry",(A_UINT8*)&pTxStats->longRetry);

            ret = addParameterToCommand((A_UINT8*)"startTime",(A_UINT8*)&pTxStats->startTime);
            ret = addParameterToCommand((A_UINT8*)"endTime",(A_UINT8*)&pTxStats->endTime);

            ret = addParameterToCommand((A_UINT8*)"byteCount",(A_UINT8*)&pTxStats->byteCount);
            ret = addParameterToCommand((A_UINT8*)"dontCount",(A_UINT8*)&pTxStats->dontCount);

            ret = addParameterToCommand((A_UINT8*)"rssi",(A_UINT8*)&pTxStats->rssi);

            ret = addParameterToCommand((A_UINT8*)"rssic0",(A_UINT8*)&pTxStats->rssic[0]);
            ret = addParameterToCommand((A_UINT8*)"rssic1",(A_UINT8*)&pTxStats->rssic[1]);
            ret = addParameterToCommand((A_UINT8*)"rssic2",(A_UINT8*)&pTxStats->rssic[2]);

            ret = addParameterToCommand((A_UINT8*)"rssie0",(A_UINT8*)&pTxStats->rssie[0]);
            ret = addParameterToCommand((A_UINT8*)"rssie1",(A_UINT8*)&pTxStats->rssie[1]);
            ret = addParameterToCommand((A_UINT8*)"rssie2",(A_UINT8*)&pTxStats->rssie[2]);

            ret = addParameterToCommand((A_UINT8*)"thermCal",(A_UINT8*)&pTxStats->thermCal);

            //FIX ME fill fix for host test befor chip back
            pTxStats->pdadc = 0;
            pTxStats->paCfg = 0x3;
            pTxStats->gainIdx = 15;
            pTxStats->dacGain = 20;

            ret = addParameterToCommand((A_UINT8*)"pdadc",(A_UINT8*)&pTxStats->pdadc);
            ret = addParameterToCommand((A_UINT8*)"paCfg",(A_UINT8*)&pTxStats->paCfg);
            ret = addParameterToCommand((A_UINT8*)"gainIdx",(A_UINT8*)&pTxStats->gainIdx);
            ret = addParameterToCommand((A_UINT8*)"dacGain",(A_UINT8*)&pTxStats->dacGain);
        }
    }

    if ( ret == TRUE )
    {
        ret = commandComplete(&rCmdStream, &cmdStreamLen );
        if ( ret == TRUE )
        {
            //A_PRINTF_ALWAYS("Response %d\n",_OP_TX_STATUS);
             // Now let's send the response..
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
             wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,_OP_TX_STATUS,(A_INT8*)rCmdStream);
#endif
        }
     }
}

/**************************************************************************
* processTxDataStopCmd - Process TX_DATA_STOP_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processTxDataStopCmd (wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32 numOfReports=0;
    A_UINT32 i;

    A_INT32 needReport = pCmd->param1;

    //A_PRINTF("needReport %d\n", needReport);

#if 0
    doeregisterTxCallback();
#endif

    /* return report */
    numOfReports = 0;

    // if we need report then we send 
    // cont_tx_off first and then
    // send the report
    // otherwise.. we just send the response
    // first and then handle cont_tx_off
    if (needReport)
    {
        tx_tcmdParms.mode = TCMD_CONT_TX_OFF;
        tcmd_cont_tx_cmd (dev, &tx_tcmdParms);

        for (i=0;i<tcmdLinkTRx.totalToTx;i++)
        {
            if (txDataStatsReport(i, 0, replyBuf)) {
                numOfReports++;
                break;/* return one report at a time */
            }
        }

        sendTxDataStatus(dev,numOfReports);
    }
    else
    {
        sendTxDataStatus(dev,numOfReports);

        tx_tcmdParms.mode = TCMD_CONT_TX_OFF;
        tcmd_cont_tx_cmd (dev, &tx_tcmdParms);
    }
    return 0;
}

/**************************************************************************
* processTxDataStatusCmd - Process TX_DATA_STATUS_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processTxDataStatusCmd (wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32 numOfReports;
    A_UINT32 i;

    // return report
    numOfReports = 0;
    if (tx_tcmdParms.numPackets) {
        for (i=0;i<tcmdLinkTRx.totalToTx;i++)
        {
            if (txDataStatsReport(i, 1, replyBuf)) {/* only send the report that is done transmitting */
                numOfReports++;
                break;/* return one report at a time */
            }
        }
    }

    sendTxDataStatus(dev,numOfReports);

    return 0;
}

/**************************************************************************
* processRxDataStartCmd - Process command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processRxStatusStartCmd (wlan_tcmd_dev_t *dev,_CMD_RX_PARMS *pRxParms)
{
    A_UINT32            rateMask,i,k;
    A_UINT32            bit0 = 0x00000001;
    A_UINT32            dataRate;

    tcmd_link_trx_init();
    /* process the bit masks to see what rates host want the report */
    for (k=0; k<RATE_MASK_ROW_MAX; k++)
    {
    	if (k == (RATE_MASK_ROW_MAX-3))
    		rateMask = pRxParms->rateMask6;
    	else if (k == (RATE_MASK_ROW_MAX-2))
        	rateMask = pRxParms->rateMask7;
        else if (k == (RATE_MASK_ROW_MAX-1))
        	rateMask = pRxParms->rateMask8;
		else
			rateMask = pRxParms->rateMask[k];
	
        i=0; bit0=0x00000001;
	//A_PRINTF("row=%d, rateMask=%x\n", k, rateMask);    
        while (rateMask)
        {
            if (bit0 & rateMask)
            {
                rateMask &= ~bit0;
                dataRate = Mask2Rate[k][i];
		//A_PRINTF("k=%d, i=%d: CCK dataRate = %d \n", k, i, dataRate);
		    
                if (dataRate == ATH_RATE_2M || dataRate == ATH_RATE_5_5M || dataRate == ATH_RATE_11M){ /* CCK rates */
		   //A_PRINTF("BF: CCK dataRate = %d, ATH_RATE_5_5M=%d\n", dataRate, ATH_RATE_5_5M);
                    if (!(i&1)) /* even number indicates short preamble, see Mask2Rate array for details */
			     dataRate += (TCMD_11AC3x3_MAX_RATES - 1); /* use rateIndex 150, 151, 152 in the rate table for CCK shortPreamble */
		    //A_PRINTF("AF: CCK dataRate = %d\n", dataRate);
		}

                //tcmdLinkTRx.rxStats[dataRate] = (RX_STATS_STRUCT_UTF*)A_ALLOCRAM(sizeof(RX_STATS_STRUCT_UTF));
                tcmdLinkTRx.rxStats[dataRate] = (RX_STATS_STRUCT_UTF*)get_pool_stat_buf();
                tcmdLinkTRx.rxStats[dataRate]->rateBit = k * 32 + i;
		//A_PRINTF("dataRate=%d, rateBit=%d\n", dataRate, tcmdLinkTRx.rxStats[dataRate]->rateBit);
                /* setting the bitnumber here has two purposes:
                 * 1. we don't need to do this again when sending report, it's easy to do it here too
                 *    as converting rate number back to bit position in the ratemask is a little bit more difficult than doing it here
                 * 2. use it to indicates that this is a rate that host wants the receive report,
                 *    if it's set to TCMD_INVALID_RATEBIT then that means host has no interest on that rate */
            }
            bit0 = bit0 << 1;
	    i++;
        }
    }

    return 0;
}


/**************************************************************************
* processRxDataStartCmd - Process RX_DATA_START_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processRxDataStartCmd (wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    RX_DATA_START_PARAMS *pParms;
    TCMD_CONT_RX        tcmdRxParms;
    A_UINT32            rateMask,i,k;
    A_UINT32            bit0 = 0x00000001;
    A_UINT32            dataRate;
    
    pParms = (RX_DATA_START_PARAMS*)(pCmd->data);

    // set rx MAC
    tcmdRxParms.act = TCMD_CONT_RX_SETMAC;
    memcpy(tcmdRxParms.u.mac.addr, pParms->rxStation, ATH_MAC_LEN);
    memcpy(tcmdRxParms.u.mac.bssid, pParms->bssid, ATH_MAC_LEN);
    tcmd_cont_rx_cmd(dev, &tcmdRxParms);
   
    tcmd_link_trx_init();
    /* process the bit masks to see what rates host want the report */
    for (k=0; k<RATE_MASK_ROW_MAX; k++)
    {
     	rateMask = pParms->rateMask[k];
	
        i=0; bit0=0x00000001;
        while (rateMask)
        {
            if (bit0 & rateMask)
            {
                rateMask &= ~bit0;
                dataRate = Mask2Rate[k][i];
                if (dataRate == ATH_RATE_2M || dataRate == ATH_RATE_5_5M || dataRate == ATH_RATE_11M){ /* CCK rates */
                    if (!(i&1)) /* even number indicates short preamble, see Mask2Rate array for details */
			dataRate += (TCMD_11AC3x3_MAX_RATES - 1); /* use rateIndex 150, 151, 152 in the rate table for CCK shortPreamble */
		}
   
                //tcmdLinkTRx.rxStats[dataRate] = (RX_STATS_STRUCT_UTF*)A_ALLOCRAM (sizeof(RX_STATS_STRUCT_UTF));
                tcmdLinkTRx.rxStats[dataRate] = (RX_STATS_STRUCT_UTF*)get_pool_stat_buf();;
                tcmdLinkTRx.rxStats[dataRate]->rateBit = k*32+i;
                /* setting the bitnumber here has two purposes:
                 * 1. we don't need to do this again when sending report, it's easy to do it here too
                 *    as converting rate number back to bit position in the ratemask is a little bit more difficult than doing it here
                 * 2. use it to indicates that this is a rate that host wants the receive report,
                 *    if it's set to TCMD_INVALID_RATEBIT then that means host has no interest on that rate */
            }          
            bit0 = bit0 << 1;i++;
        }
    }    

    // start rx
    tcmdRxParms.act = pParms->promiscuous ? TCMD_CONT_RX_PROMIS : TCMD_CONT_RX_FILTER;
    //tcmdRxParms.enANI = pParms->enANI;
    tcmdRxParms.enANI = FALSE;/* disable ANI for now as ANI feature has bug which affects sensitivity testing */
    tcmdRxParms.u.para.freq = pParms->freq;
    tcmdRxParms.u.para.freq2 = pParms->freq2;   
    tcmdRxParms.u.para.antenna = pParms->antenna;
    tcmdRxParms.u.para.wlanMode = pParms->wlanMode;
    tcmdRxParms.u.para.ack = 1;
    tcmdRxParms.u.para.rxChain = pParms->rxChain;
    tcmdRxParms.u.para.bc = pParms->broadcast;
    tcmdRxParms.u.para.bandwidth = pParms->bandwidth;
    tcmdRxParms.u.para.lpl = 0;/* do not enable LPL */
    return tcmd_cont_rx_cmd(dev, &tcmdRxParms);

    
    //return 0;
}

A_UINT8 g_rx_opflags = 0;
void sendRxDataStatus(wlan_tcmd_dev_t *dev,A_UINT32 numOfReports)
{
    RX_STATS_STRUCT_UTF *pRxStats;
    A_BOOL ret = FALSE;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;
	A_INT32 pilotevm_post[MAX_PILOT_UTF];
	int ipilot = 0;

    pRxStats = (RX_STATS_STRUCT_UTF*)replyBuf;

    ret = createCommand(_OP_RX_STATUS);
  //  A_PRINTF("g_rx_in_counter= %d, RxP=%d, TPts=%d, G=%d, TCMD_MAX_RATES=%d \n", g_rx_in_counter, numOfReports, pRxStats->totalPackets, pRxStats->goodPackets, TCMD_MAX_RATES);
  //  A_PRINTF("rateBit= %d, crcPackets=%d, decrypErrors=%d, g_rsStatus=%x\n", pRxStats->rateBit, pRxStats->crcPackets, pRxStats->decrypErrors, g_rsStatus);
    if ( ret == TRUE )
    {
        ret = addParameterToCommand((A_UINT8*)"numOfReports",(A_UINT8*)&numOfReports);

        if (numOfReports) {
            ret = addParameterToCommand((A_UINT8*)"totalPackets",(A_UINT8*)&pRxStats->totalPackets);
            ret = addParameterToCommand((A_UINT8*)"goodPackets",(A_UINT8*)&pRxStats->goodPackets);
            ret = addParameterToCommand((A_UINT8*)"otherError",(A_UINT8*)&pRxStats->otherError);
            ret = addParameterToCommand((A_UINT8*)"crcPackets",(A_UINT8*)&pRxStats->crcPackets);
            ret = addParameterToCommand((A_UINT8*)"decrypErrors",(A_UINT8*)&pRxStats->decrypErrors);
            ret = addParameterToCommand((A_UINT8*)"rateBit",(A_UINT8*)&pRxStats->rateBit);

            ret = addParameterToCommand((A_UINT8*)"startTime",(A_UINT8*)&pRxStats->startTime);
            ret = addParameterToCommand((A_UINT8*)"endTime",(A_UINT8*)&pRxStats->endTime);
            ret = addParameterToCommand((A_UINT8*)"byteCount",(A_UINT8*)&pRxStats->byteCount);
            ret = addParameterToCommand((A_UINT8*)"dontCount",(A_UINT8*)&pRxStats->dontCount);

            ret = addParameterToCommand((A_UINT8*)"rssi",(A_UINT8*)&pRxStats->rssi);
            ret = addParameterToCommand((A_UINT8*)"rssic0",(A_UINT8*)&pRxStats->rssic[0]);
            ret = addParameterToCommand((A_UINT8*)"rssic1",(A_UINT8*)&pRxStats->rssic[1]);
            ret = addParameterToCommand((A_UINT8*)"rssic2",(A_UINT8*)&pRxStats->rssic[2]);
	    ret = addParameterToCommand((A_UINT8*)"rssic3",(A_UINT8*)&pRxStats->rssic[3]);

            ret = addParameterToCommand((A_UINT8*)"rssie0",(A_UINT8*)&pRxStats->rssie[0]);
            ret = addParameterToCommand((A_UINT8*)"rssie1",(A_UINT8*)&pRxStats->rssie[1]);
            ret = addParameterToCommand((A_UINT8*)"rssie2",(A_UINT8*)&pRxStats->rssie[2]);
	    ret = addParameterToCommand((A_UINT8*)"rssie3",(A_UINT8*)&pRxStats->rssie[3]);

//A_PRINTF("avgEvm0 %d avgEvm1 %d avgEvm2 %d\n",pRxStats->evm[0],pRxStats->evm[1],pRxStats->evm[2]);
            ret = addParameterToCommand((A_UINT8*)"evm0",(A_UINT8*)&pRxStats->evm[0]);
            ret = addParameterToCommand((A_UINT8*)"evm1",(A_UINT8*)&pRxStats->evm[1]);
            ret = addParameterToCommand((A_UINT8*)"evm2",(A_UINT8*)&pRxStats->evm[2]);
	    ret = addParameterToCommand((A_UINT8*)"evm3",(A_UINT8*)&pRxStats->evm[3]);

            ret = addParameterToCommand((A_UINT8*)"badrssi",(A_UINT8*)&pRxStats->badrssi);

            ret = addParameterToCommand((A_UINT8*)"badrssic0",(A_UINT8*)&pRxStats->badrssic[0]);
            ret = addParameterToCommand((A_UINT8*)"badrssic1",(A_UINT8*)&pRxStats->badrssic[1]);
            ret = addParameterToCommand((A_UINT8*)"badrssic2",(A_UINT8*)&pRxStats->badrssic[2]);
	    ret = addParameterToCommand((A_UINT8*)"badrssic3",(A_UINT8*)&pRxStats->badrssic[3]);

            ret = addParameterToCommand((A_UINT8*)"badrssie0",(A_UINT8*)&pRxStats->badrssie[0]);
            ret = addParameterToCommand((A_UINT8*)"badrssie1",(A_UINT8*)&pRxStats->badrssie[1]);
            ret = addParameterToCommand((A_UINT8*)"badrssie2",(A_UINT8*)&pRxStats->badrssie[2]);
	    ret = addParameterToCommand((A_UINT8*)"badrssie3",(A_UINT8*)&pRxStats->badrssie[3]);
	    
            ret = addParameterToCommand((A_UINT8*)"badevm0",(A_UINT8*)&pRxStats->badevm[0]);
            ret = addParameterToCommand((A_UINT8*)"badevm1",(A_UINT8*)&pRxStats->badevm[1]);
            ret = addParameterToCommand((A_UINT8*)"badevm2",(A_UINT8*)&pRxStats->badevm[2]);
	    ret = addParameterToCommand((A_UINT8*)"badevm3",(A_UINT8*)&pRxStats->badevm[3]);
        
            if( g_rx_opflags & NF_IN_DBM_MASK) {
                pRxStats->noisefloor[0]= rssiInDBMComp(0, 0);
                pRxStats->noisefloor[1]= rssiInDBMComp(1, 0);
                pRxStats->noisefloor[2]= rssiInDBMComp(2, 0);
                pRxStats->noisefloor[3]= rssiInDBMComp(3, 0);
                g_rx_opflags = 0;
            }else {
                pRxStats->noisefloor[0]= whalGetCalibrationNf(0);
                pRxStats->noisefloor[1]= whalGetCalibrationNf(1); 
                pRxStats->noisefloor[2]= whalGetCalibrationNf(2); 
                pRxStats->noisefloor[3]= whalGetCalibrationNf(3); 
            }

            ret = addParameterToCommand((A_UINT8*)"noisefloor0",(A_UINT8*)&pRxStats->noisefloor[0]);
            ret = addParameterToCommand((A_UINT8*)"noisefloor1",(A_UINT8*)&pRxStats->noisefloor[1]);
            ret = addParameterToCommand((A_UINT8*)"noisefloor2",(A_UINT8*)&pRxStats->noisefloor[2]);
            ret = addParameterToCommand((A_UINT8*)"noisefloor3",(A_UINT8*)&pRxStats->noisefloor[3]);
		for(ipilot = 0; ipilot < MAX_PILOT_UTF; ipilot++){
			pilotevm_post[ipilot] = ((pRxStats->pilotevm[3][ipilot] & 0xff ) << 24) + ((pRxStats->pilotevm[2][ipilot] & 0xff) << 16) + ((pRxStats->pilotevm[1][ipilot] & 0xff) << 8) + (pRxStats->pilotevm[0][ipilot] & 0xff);
		}
	    
	    ret = addParameterToCommand((A_UINT8*)"pilotevm0",(A_UINT8*)&pilotevm_post[0]);
            ret = addParameterToCommand((A_UINT8*)"pilotevm1",(A_UINT8*)&pilotevm_post[1]);
            ret = addParameterToCommand((A_UINT8*)"pilotevm2",(A_UINT8*)&pilotevm_post[2]);
	    ret = addParameterToCommand((A_UINT8*)"pilotevm3",(A_UINT8*)&pilotevm_post[3]);
            ret = addParameterToCommand((A_UINT8*)"pilotevm4",(A_UINT8*)&pilotevm_post[4]);
            ret = addParameterToCommand((A_UINT8*)"pilotevm5",(A_UINT8*)&pilotevm_post[5]);
	    ret = addParameterToCommand((A_UINT8*)"pilotevm6",(A_UINT8*)&pilotevm_post[6]);
            ret = addParameterToCommand((A_UINT8*)"pilotevm7",(A_UINT8*)&pilotevm_post[7]);
			
	    ret = addParameterToCommand((A_UINT8*)"pilotevm8",(A_UINT8*)&pilotevm_post[8]);
            ret = addParameterToCommand((A_UINT8*)"pilotevm9",(A_UINT8*)&pilotevm_post[9]);
            ret = addParameterToCommand((A_UINT8*)"pilotevm10",(A_UINT8*)&pilotevm_post[10]);
	    ret = addParameterToCommand((A_UINT8*)"pilotevm11",(A_UINT8*)&pilotevm_post[11]);
            ret = addParameterToCommand((A_UINT8*)"pilotevm12",(A_UINT8*)&pilotevm_post[12]);
            ret = addParameterToCommand((A_UINT8*)"pilotevm13",(A_UINT8*)&pilotevm_post[13]);
	    ret = addParameterToCommand((A_UINT8*)"pilotevm14",(A_UINT8*)&pilotevm_post[14]);
            ret = addParameterToCommand((A_UINT8*)"pilotevm15",(A_UINT8*)&pilotevm_post[15]);
        }
    }
    else {
        A_PRINTF("Compose failed...\n");
    }

    if ( ret == TRUE )
    {
        ret = commandComplete(&rCmdStream, &cmdStreamLen );
        if ( ret == TRUE )
        {
             // Now let's send the response..
           // A_PRINTF_ALWAYS("Response %d\n",_OP_RX_STATUS);
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
//	   A_PRINTF_ALWAYS("wmi_tc_cmds_reply_event -->Response %d\n",_OP_RX_STATUS);
             wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,_OP_TX_STATUS,(A_INT8*)rCmdStream);
//	     A_PRINTF("pRxStats->rssi=%d\n, noise_floor=%d", pRxStats->rssi,  whalGetNf());
#endif
        }
        else
        {
            A_PRINTF("Command Complete failed...\n");
        }
     }
     else {
         A_PRINTF("Command Complete failed...\n");
     }
}

/**************************************************************************
* processRxDataStopCmd - Process RX_DATA_STOP_CMD command
*
* RETURNS: 0 processed OK, an Error code if it is not
*/
A_UINT32 processRxDataStopCmd (wlan_tcmd_dev_t *dev,  _CMD_NARTCMD_PARMS *pCmd)
{
    TCMD_CONT_RX        tcmdRxParms;
    A_UINT32            numOfReports=0;
    A_UINT32            i;

    /* return report */
    for (i=0;i<TCMD_MAX_RATES;i++)
    {
        if (rxDataStatsReport(i,replyBuf))
        {
            numOfReports++;
            break;/* return one report at the time */
        }
    }

    // stop rx
    tcmdRxParms.act = TCMD_CONT_RX_REPORT;
    tcmd_cont_rx_cmd(dev, &tcmdRxParms);

    sendRxDataStatus(dev,numOfReports);
    
    return 0;
}

//**************************************************************************
/* 
 * processRxDataStatusCmd - Process RX_DATA_STATUS_CMD command
 * RX_DATA_STATUS_CMD should come after RX_DATA_STOP_CMD
 *
 * RETURNS: 0 processed OK, an Error code if it is not
 */
A_UINT32 processRxDataStatusCmd (wlan_tcmd_dev_t *dev,  _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32  numOfReports =0;
    A_UINT32            i;

    for (i=0;i<TCMD_MAX_RATES;i++)
    {
        if (rxDataStatsReport(i,replyBuf))
        {
            numOfReports++;
            break;/* return one report at the time */
        }
    }

    sendRxDataStatus(dev,numOfReports);

    return 0;
}

//**************************************************************************
/* 
 * processEepromWriteItemsCmd - Process M_EEPROM_WRITE_ITEMS_CMD command
 * RETURNS: 0 processed OK, an Error code if it is not
 */
A_UINT32 processEepromWriteItemsCmd (_CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32 numOfItems;
    A_UCHAR *pBuf;
    A_UINT16 offset;/* offset to the eeprom structure */
    A_UINT16 size;/* number of bytes in the Data */
    A_UINT16 i;
    A_UINT8 *eeprom=NULL;
    
    if (tcmd_state.flags & _UTF_BOARD_DATA_READ)
        eeprom = A_BOARD_DATA_ADDR();
    else {
        uiPrintf("eepromWrite address not available\n");
        return 0;
    }

    numOfItems = pCmd->param1;
    pBuf = pCmd->data;
    //A_PRINTF("processEepromWriteItemsCmd : numOfItems=%d, EEPROM addr=0x%x\n", numOfItems,eeprom);
    
    for (i = 0; i < numOfItems; ++i)
    {
        offset = (A_UINT16)pBuf[0] | ((A_UINT16)pBuf[1] << 8);
        size = pBuf[2];
        A_MEMCPY(eeprom+offset,&pBuf[3],size);
#if 0
        A_UINT16 j;
        A_PRINTF("write EEPROM[%04x],size=0x%x,data=", offset, size);
        for (j = 3; j < ((size < 10) ? size+3 : 13); ++j)
        {
            A_PRINTF("0x%02x ", pBuf[j]);
        }
        A_PRINTF("\n");
#endif
        pBuf += size + 3; 
    }
    return 0;
}

#if defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
/*
Param1 ? totalSize of eeprom structure. 
Param2 ? offset from the base of eeprom
Param3 ? Block length, number of bytes in the current stream/block. 
Data ? 
*/

//**************************************************************************
void sendEepromResponse (wlan_tcmd_dev_t *dev, A_UINT32 cmdId, A_UINT8 *buf, A_UINT32 length, A_UINT32 block_length, A_UINT32 status)
{
    A_BOOL ret = FALSE;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;

    ret = createCommand(_OP_GENERIC_NART_RSP);

    if ( ret == TRUE )
    {
        ret = addParameterToCommand((A_UINT8*)"commandId",(A_UINT8*)&cmdId);

        if ( ret == FALSE )
            A_PRINTF("add commandId failed\n");

        ret = addParameterToCommand((A_UINT8*)"status",(A_UINT8*)&status);

        if ( ret == FALSE )
            A_PRINTF("add status failed\n");

        ret = addParameterToCommand((A_UINT8*)"length",(A_UINT8*)&length);

        if ( ret == FALSE )
            A_PRINTF("add length failed\n");

        if (block_length)
        {
            ret = addParameterToCommandWithLen((A_UINT8*)"data",(A_UINT8*)buf, block_length);

            if ( ret == FALSE )
                A_PRINTF("add data failed\n");
        }

        if ( ret == TRUE )
        {
            ret = commandComplete(&rCmdStream, &cmdStreamLen );

            //A_PRINTF("stream length ..%d\n",cmdStreamLen);

            if ( ret == TRUE )
            {
                 //A_PRINTF("Command Id Response..%d\n",cmdId);

                 // Now let's send the response..
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
                 wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,_OP_GENERIC_NART_RSP,(A_INT8*)rCmdStream);
#endif
            }
         }
         else
         { 
             A_PRINTF("add Param failed sendEepromResponse\n");
         }
    }

}

//**************************************************************************
/* 
 * processEepromWriteCmd - Process M_EEEPROM_BLOCK_WRITE_CMD command
 * RETURNS: 0 processed OK, an Error code if it is not
 */
A_UINT32 numOfEepromRead = 0; 
A_UINT32 numOfEepromWrite = 0; 
A_UINT32 status_w = 0;
A_UINT32 processEepromWriteCmd (wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT16 totalSize;
    A_UINT8 *pBuf;
    A_UINT16 offset;/* offset to the eeprom structure */
    A_UINT16 blockSize;/* number of bytes in the Data */
      
    totalSize = pCmd->param1;
    offset = pCmd->param2;
    blockSize = pCmd->param3;
     if (totalSize > utfGetBoardDataSize() || (offset + blockSize) > utfGetBoardDataSize() || blockSize > 1000) {
        A_PRINTF("eepromWrite Size not available %d\n", totalSize);
	A_MEMCPY(replyBuf, (A_UINT8 *)&blockSize, 2);
        A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
	status_w = 1;
       sendNartResponse (dev,pCmd->commandId, replyBuf, 4,  1);
    
        return 0;
    }

    pBuf = (A_UINT8 *)pCmd->data;
    
    status_w = eeprom_block_write(offset, pBuf,  blockSize);
    A_MEMCPY(replyBuf, (A_UINT8 *)&blockSize, 2);
    A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
   sendNartResponse (dev,pCmd->commandId, replyBuf, 4,  0);
    
    return 0;
}

//**************************************************************************
/* 
 * processEepromReadCmd - Process M_EEEPROM_BLOCK_READ_CMD command
 * RETURNS: 0 processed OK, an Error code if it is not
 */
A_UINT32 processEepromReadCmd (wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT16 totalSize;
     A_UINT8 *pBuf;
    //A_UINT32 *pBuf;
    A_UINT16 offset;/* offset to the eeprom structure */
    A_UINT16 blockSize;/* number of bytes in the Data */
    A_UINT32 status = 0;
      
    replyBuf = &dataPayload[0];
    totalSize = pCmd->param1;
    offset = pCmd->param2;
    blockSize = pCmd->param3;
	
    if (totalSize > utfGetBoardDataSize() || (offset + blockSize) > utfGetBoardDataSize()  || blockSize > 1000) {
        A_PRINTF("eepromRead Size not available %d\n", totalSize);
	A_MEMCPY(replyBuf, (A_UINT8 *)&blockSize, 2);
        A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
        sendNartResponse (dev,pCmd->commandId, replyBuf, 4,  1);
        return 0;
    }
    //pBuf = (A_UINT8 *)pCmd->data;
    A_MEMCPY(replyBuf, (A_UINT8 *)&blockSize, 2);
    A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
    pBuf = (A_UINT8 *)(replyBuf+4);
    status = eeprom_block_read(offset, pBuf,  blockSize);
    status = 0;
    /*
    A_MEMCPY(replyBuf, (A_UINT8 *)&offset, 4);
    A_MEMCPY(replyBuf + 4 , pBuf, blockSize);
    */
    
   // sendEepromResponse (dev, pCmd->commandId, replyBuf, totalSize, blockSize + 4, status);
    sendNartResponse (dev,pCmd->commandId, replyBuf, blockSize + 4,  status);
        
    return 0;
}

//**************************************************************************
/* 
 * processEepromEraseCmd - Process M_EEEPROM_BLOCK_ERASE_CMD command
 * RETURNS: 0 processed OK, an Error code if it is not
 */
 #if 0
A_UINT32 processEepromEraseCmd (wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT16 totalSize;
     A_UINT8 *pBuf;
    A_UINT16 offset;/* offset to the eeprom structure */
    A_UINT16 blockSize;/* number of bytes in the Data */
    A_UINT16 loop;
    A_UINT16 total;
    A_UINT16 subblockSize;/* if blockSize is greater thant MAX_BLOCK_SIZE, calculate subblock size via Mod operation */

    totalSize = pCmd->param1;
    offset = pCmd->param2;
    blockSize = pCmd->param3;

    if (totalSize > utfGetBoardDataSize() || (offset + blockSize) > utfGetBoardDataSize()) {
        //A_PRINTF("eepromErase Size not available %d\n", totalSize);
        A_MEMCPY(replyBuf, (A_UINT8 *)&blockSize, 2);
        A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
        status_w = 1;
        sendNartResponse (dev,pCmd->commandId, replyBuf, 4,  1);

        return 0;
    }

    //split blockSize per MAX_BLOCK_SIZE 
    total = blockSize / MAX_BLOCK_SIZE;
    subblockSize = blockSize % MAX_BLOCK_SIZE;
    A_MEMSET(pCmd->data, 0xff, MAX_BLOCK_SIZE);

    if (total > 0)
    {
	//padding eeprom content with 0xff
	pBuf = (A_UINT8 *)pCmd->data;

    	for (loop = 0; loop < total; loop++)
    	{
            status_w = eeprom_block_write(offset, pBuf, MAX_BLOCK_SIZE);
            offset += MAX_BLOCK_SIZE;
    	}
	
    }
    if (subblockSize > 0) 
	status_w = eeprom_block_write(offset, pBuf, subblockSize);

    A_MEMCPY(replyBuf, (A_UINT8 *)&blockSize, 2);
    A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
    sendNartResponse (dev,pCmd->commandId, replyBuf, 4,  0);

    return 0;
}
#endif

 #if 1
A_UINT32 processEepromEraseCmd (wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT16 totalSize;
     A_UINT8 *pBuf;
    A_UINT16 offset;/* offset to the eeprom structure */
    A_UINT16 blockSize;/* number of bytes in the Data */
    A_UINT16 loop;
    A_UINT16 total;
    A_UINT16 subblockSize;/* if blockSize is greater thant MAX_BLOCK_SIZE, calculate subblock size via Mod operation */

    status_w = 0;
    totalSize = pCmd->param1;
    offset = pCmd->param2;
    blockSize = pCmd->param3;
    A_MEMCPY(replyBuf, (A_UINT8 *)&blockSize, 2);
    A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
    
    if(first_command && eep_write_done &&  detect_i2c_eeprom() == TRUE) {
		if (totalSize > utfGetBoardDataSize() || (offset + blockSize) > utfGetBoardDataSize()) {
			//A_PRINTF("eepromErase Size not available %d\n", totalSize);
			status_w = 1;
			replyBuf[4] = 2;
			//sendNartResponse (dev,pCmd->commandId, replyBuf, 4,  1);
		}
		if (totalSize == utfGetBoardDataSize() && blockSize > (4 * MAX_BLOCK_SIZE) && (offset +blockSize) <=utfGetBoardDataSize()) {
			stamp[0] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
			//A_PRINTF("eepromErase blockSize %d\n", blockSize);
			gOffset = offset;/* offset to the eeprom structure */
			gBlockSize = blockSize;/* number of bytes in the Data */
			first_command = FALSE;
			eep_write_done = FALSE;
			status_w = 1;
			A_MEMSET(gEepromCmd.data, 0xff, MAX_BLOCK_SIZE);
			gEepromCmd.commandId = pCmd->commandId;
			statusEepWrite = 0;
			replyBuf[4] = 1;
			//A_INIT_TIMER(&eep_write_complete_timer, eep_write_complete_timer_handler, (void *) &stEepWrite);
			A_INIT_TIMER(&eep_write_complete_timer, eep_write_complete_timer_handler, NULL);
	                
	                A_TIMEOUT_MS(&eep_write_complete_timer, 100, 0);
			
		}
		else {
			//A_PRINTF("eepromErase offset=%d, blocksz= %d\n", offset, blockSize);
			    //split blockSize per MAX_BLOCK_SIZE 
			    total = blockSize / MAX_BLOCK_SIZE;
			    subblockSize = blockSize % MAX_BLOCK_SIZE;
			    A_MEMSET(pCmd->data, 0xff, MAX_BLOCK_SIZE);
			    pBuf = (A_UINT8 *)pCmd->data;
			    if (total > 0)
			    {
				//padding eeprom content with 0xff
				for (loop = 0; loop < total; loop++) {
				    status_w |= eeprom_block_write(offset, pBuf, MAX_BLOCK_SIZE);
				    offset += MAX_BLOCK_SIZE;
				}
				
			    }
			    if (subblockSize > 0) 
				status_w |= eeprom_block_write(offset, pBuf, subblockSize);
				if (status_w) replyBuf[4] = 2;
			 //   sendNartResponse (dev,pCmd->commandId, replyBuf, 4,  0);
		}
   } else   if((gEepromCmd.commandId == pCmd->commandId) && eep_write_done && !first_command) {
	status_w = 0;
	first_command = TRUE;
	replyBuf[4] = 0;
	//sendNartResponse (dev,pCmd->commandId, replyBuf, 4,  1);
   } else {
	//A_PRINTF("didn't finish erase, or Other Opers didn't finish,  old_cmdId=%d, cur_cmdId=%d\n", gEepromCmd.commandId, pCmd->commandId);
        status_w = 1;
	replyBuf[4] = 1;
   }
   
    if ( statusEepWrite!= 0)
	replyBuf[4] = 2;
    sendNartResponse (dev,pCmd->commandId, replyBuf, 5,  status_w);
    return 0;
}
#endif

//**************************************************************************
/* 
 * processEepromCheckCmd - Process M_EEEPROM_BLOCK_CHECK_CMD command
 * RETURNS: 0 processed OK, an Error code if it is not
 */
A_UINT32 processEepromCheckCmd (wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT16 totalSize;
     A_UINT8 *pBuf;
    A_UINT16 offset;/* offset to the eeprom structure */
    A_UINT16 blockSize;/* number of bytes in the Data */
    A_UINT16 loop;
    A_UINT16 total;
    A_UINT32 status = 0;
    A_UINT16 subblockSize;/* if blockSize is greater thant MAX_BLOCK_SIZE, calculate subblock size via Mod operation */
    A_UINT8 *eeprom = NULL;
    A_UINT8 ret = 0;

    eeprom = utfGetBoardDataPtr();
    totalSize = pCmd->param1;
    offset = pCmd->param2; 
    blockSize = pCmd->param3;
    A_MEMCPY(replyBuf, (A_UINT8 *)&blockSize, 2);
    A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
    
    if (totalSize > utfGetBoardDataSize() || (offset + blockSize) > utfGetBoardDataSize()) 
    {
        A_PRINTF("total=%d, offset=%d, block=%d\n", totalSize, offset, blockSize);
        ret = 2;
	replyBuf[4] = ret;
	status = 1;
        sendNartResponse (dev,pCmd->commandId, replyBuf, 5,  status);

        return 0;
    }

    //checksum sanity check
    pBuf = (A_UINT8 *)pCmd->data;

    if (offset > 2)
    {
	status |= eeprom_block_read(0, pBuf, 4);

        if (memcmp((void *)eeprom, (void *)pBuf, 4))
        {
	    A_PRINTF("checksum of bdata and eeprom not the same\n");
            ret = 1; //checksum in boardData file and eeprom mismatches.
	    status = 1;
	    replyBuf[4] = ret;
   	    sendNartResponse (dev,pCmd->commandId, replyBuf, 5, status);

    	    return 0;
        }
    }
    else
    {
	//for instance, offset:0,blockSize:2, in this case, check CRC and return directly.
	if ((offset + blockSize) < 4)
	{
	    status |= eeprom_block_read(0, pBuf, 4);

            if (memcmp((void *)eeprom, (void *)pBuf, 4))
            {
            	A_PRINTF("checksum of boardData file and eeprom not identical\n");
		status = 1;
            	ret = 1; //checksum in boardData file and eeprom mismatches.
            }

            replyBuf[4] = ret;
            sendNartResponse (dev,pCmd->commandId, replyBuf, 5, status);

            return 0;
	}

    }

    total = blockSize / MAX_BLOCK_SIZE;
    subblockSize = blockSize % MAX_BLOCK_SIZE;
    if (total > 0)
    {
	for (loop = 0; loop < total; loop++)
    	{
	    
	    status |= eeprom_block_read(offset, pBuf, MAX_BLOCK_SIZE);
	    
            if (memcmp((void *)(eeprom + offset), (void *)pBuf, MAX_BLOCK_SIZE))
            {
            	ret = 1; //contents in boardData file and eeprom mismatches.
        	break;
            }

            offset += MAX_BLOCK_SIZE;
    	}
    }
    if (subblockSize > 0)
    {
       
        status |= eeprom_block_read(offset, pBuf, subblockSize);
        if (memcmp((void *)(eeprom + offset), (void *)pBuf, subblockSize))
            ret = 1; //contents in boardData file and eeprom mismatched.
    }

    replyBuf[4] = ret;
    sendNartResponse (dev,pCmd->commandId, replyBuf, 5, status);

    return 0;
}

A_UINT8 NV_MACADDR[6];

A_UINT32 processNVSetMacAddrCmd(wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32 status = 0;
   
    replyLength = 0;
    replyBuf = &dataPayload[0];
   
    if (pCmd->param1 > 1024) 
	 status = 1;
    else 
         status = 0;
	 
    if (status == 0)
    {
    	if((pCmd->data[4] >= 1) && (pCmd->data[0] == 0x1) &&
    			(pCmd->data[1] == 0x8) && (pCmd->data[2] == 0x4) &&
    			(pCmd->data[3] == 0x6))
    	{
    		utfSetMacAddr(&pCmd->data[5]);
		utfGetMacAddr(NV_MACADDR);
    	}

    }  
    
    sendNartResponse (dev, pCmd->commandId, replyBuf, replyLength,  status);
   
    if (status == 0) utfRecalBoardDataChecksum();
      
    return 0;
}

A_UINT32 processNVGetMacAddrCmd(wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32 status = 0;

    replyLength = 0;
    replyBuf = &dataPayload[0];
    utfGetMacAddr(replyBuf);
    replyLength += 6;
    sendNartResponse (dev, pCmd->commandId, replyBuf, replyLength,  status);
   
    return 0;
}

A_UINT8 NV_MCNNUM[20];
A_UINT32 processNVSetMcnNumCmd(wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32 status = 0;

    replyLength = 0;
    replyBuf = &dataPayload[0];

    if (pCmd->param1 >1024)
	status = 1;
    else
        status = 0;
    if(status == 0)
    {
	if((pCmd->data[4] >=1) && (pCmd->data[0] == 0x1) &&
			(pCmd->data[1] == 0x8) && (pCmd->data[2] == 0x4) &&
			(pCmd->data[3] == 0x6))
	{
		utfSetMcnNum(&pCmd->data[5]);
		utfGetMcnNum(NV_MCNNUM);
	}
    }
    sendNartResponse (dev, pCmd->commandId, replyBuf, replyLength, status);
    if (status == 0) utfRecalBoardDataChecksum();

    return 0;
}

A_UINT32 processNVGetMcnNumCmd(wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32 status = 0;

    replyLength = 0;
    replyBuf = &dataPayload[0];
    utfGetMcnNum(replyBuf);
    replyLength += 20;
    sendNartResponse (dev, pCmd->commandId, replyBuf, replyLength,  status);

    return 0;
}

A_UINT32 processGetTxOfflinePower(wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
   WHAL_CHANNEL chan;
   A_UINT8 regDmn = 1, txChainMask, NSSMask; 
   
   A_UINT16 MaxTxPowerPerRange, MaxTxPowerPerTP;
  /*./attestcmd --gettxpwr(1) txfreq(2) mode(3) bflag(4) txchain(5) nss(6) 
		value = atoi(argv[2]);
		buf[0] = value &0xff; 
		buf[1] = (value >> 8) &0xff; 
		buf[2] = atoi(argv[3])&0xff;
		buf[3] = atoi(argv[4])&0x1;
		buf[4] = atoi(argv[5])&0xf;
		buf[5] = atoi(argv[6])&0xf;*/
		
    A_UINT32 status = 0, rcflags;
    
    chan.mhz = chan.band_center_freq1 = chan.band_center_freq2 = pCmd->data[0] |  (pCmd->data[1] <<8);
    chan.phy_mode = pCmd->data[2];
    if (chan.phy_mode == 4)
    chan.mhz =  chan.band_center_freq1;
    if (chan.phy_mode == 6)
    chan.mhz =  chan.band_center_freq1 + 10;
    if (chan.phy_mode == 10)
    chan.mhz =  chan.band_center_freq1 - 30;
    chan.max_reg_power = 63;
    chan.antenna_max = 1;
    A_MEMCPY(&rcflags,  &(pCmd->data[3]), 4);
    
    txChainMask = pCmd->data[7];
    NSSMask =  0x1 << (pCmd->data[8] - 1);
    //whalEepromGetTxPowerPerChannelMode(&chan, rcflags, regDmn, txChainMask, NSSMask, &MaxTxPowerPerRange, &MaxTxPowerPerTP);
    whalEepromGetTxPowerPerChannelMode(&chan,  rcflags, regDmn, txChainMask, NSSMask, &MaxTxPowerPerRange, &MaxTxPowerPerTP);
								
    A_MEMCPY(replyBuf, &MaxTxPowerPerRange, 2);
    A_MEMCPY(replyBuf + 2, &MaxTxPowerPerTP, 2);
    sendNartResponse (dev, pCmd->commandId, replyBuf, 4,  status);
           
    return 0;
}

/*
a new TLV command for writing BoardData to persistent memory
Parm1 = memory type. 0=eeprom, 1=otp . For now we will use only for eeprom write.
Parm2 = Number of sector/segments. When it is 0, we will write entire BOARD_DATA space. 
Parm3 = compress or not. 0=no compress and 1=compress.
*/
#if 0
A_UINT32 processNVBoardDataCommitCmd(wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
	A_UINT32 status = 0;
	A_INT32 offset, remaining;
	A_UINT8 *ptr;
	/*
	*/
	replyLength = 0;
	replyBuf = &dataPayload[0];

	if ((pCmd->param1 == 0) &&  (pCmd->param2 == 0)&& (pCmd->param3 == 0)) {
		ptr = utfGetBoardDataPtr();
		remaining= utfGetBoardDataSize();
		offset = 0;
		sendNartResponse (dev, pCmd->commandId, replyBuf, replyLength,  status);
		if (detect_i2c_eeprom() == TRUE) {
			while (remaining > 0) {
				if (remaining > 1000) {
					status = eeprom_block_write(offset,  ptr, 1000);
					if (status != 0) break;
					offset += 1000;
					ptr += 1000;
					remaining -= 1000;
				}
				else {
					status = eeprom_block_write(offset,  ptr, remaining);
					break;
				}
			}
		} 
		else status = 1;
	}
	else {// to be done 
	        status = 1;
	}

	if (status == 1) sendNartResponse (dev, pCmd->commandId, replyBuf, replyLength,  status);
	
	return 0;
}
#endif 

#if 1 // new implementation
A_UINT32 processNVBoardDataCommitCmd(wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
	A_UINT32 status = 0;
	
	replyLength = 5;
	replyBuf = &dataPayload[0];
        if (eep_write_done && first_command) {   
		if ((pCmd->param1 == 0) &&  (pCmd->param2 == 0)&& (pCmd->param3 == 0) && detect_i2c_eeprom() == TRUE) {
			stamp[0] = A_RTC_WLAN_REG_READ(MAC_PCU_WBTIMER_1_ADDRESS);
			gOffset = 0;
			gBlockSize = utfGetBoardDataSize();
			A_MEMCPY(replyBuf, &gBlockSize, 2);
			A_MEMCPY(replyBuf + 2, &gOffset, 2);
			first_command = FALSE;
			eep_write_done = FALSE;
			//status = 1;
			gEepromCmd.commandId=pCmd->commandId;
			statusEepWrite = 0;
			dataPayload[4] = 1;
			A_INIT_TIMER(&eep_write_complete_timer, eep_write_complete_timer_handler, NULL);
			//A_INIT_TIMER(&eep_write_complete_timer, eep_write_complete_timer_handler, (void *) &stEepWrite);
	                A_TIMEOUT_MS(&eep_write_complete_timer, 100, 0);
		} else {// to be done 
			dataPayload[4] = 3;
			status = 1;
		}
       } else if(gEepromCmd.commandId == pCmd->commandId && !eep_write_done) {
		dataPayload[4] = 1;
	} else if(gEepromCmd.commandId == pCmd->commandId && eep_write_done && !first_command) {
		first_command = TRUE;
		if (statusEepWrite == 0) {
		    status  = 0;
		    dataPayload[4] = 0;
		}
		else {
			status = 1;
			dataPayload[4] = 2;
		}
	}  else  { 
		   A_PRINTF(" Not write done, or other eeprom operation didn't finish0,  old_cmdId=%d, cur_cmdId=%d\n", gEepromCmd.commandId, pCmd->commandId);
		   status  = 1;
		   dataPayload[4] = 3;
	}

	status = 0;
	sendNartResponse (dev, pCmd->commandId, replyBuf, replyLength,  status);
	
	return 0;
}
#endif 
/*
For send command: (_OP_GENERIC_NART_CMD = 8)
commandId	M_ READ_FW_BD_ID
Param1	total size
Param2	offset
Param3	block size(up to 1000 bytes)  for block read;
data	Ignore
 
For response command: (_OP_GENERIC_NART_RSP = 9)
commandId	M_READ_FW_BD_ID
status	Status  0 if OK; error otherwise
length	Data payload length: length=4 for error reading, or blocksize + 4

data	Blocksize(2bytes)+offset(2bytes)+ payload  of blockbdata (up to 1000 bytes)
*/ 
A_UINT32 processCalBoardDataCmd(wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
	A_UINT32 status = 0;
	A_INT16 offset,  blocksize, totalsize;
	A_UINT8 *ptr;
	A_UINT16 bdSize;
	
	replyLength = 0;
	replyBuf = &dataPayload[0];
	ptr = utfGetBoardDataPtr();
	bdSize = utfGetBoardDataSize();

	//Recalculating Checksum before sending to QDART
	utfRecalBoardDataChecksum();
	
	totalsize = pCmd->param1;
	offset =  pCmd->param2;
	blocksize = pCmd->param3;
	
	if (totalsize > bdSize)
	{
		status = 1;
		A_MEMCPY(replyBuf, (A_UINT8 *)&blocksize, 2);
		A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
		sendNartResponse (dev, pCmd->commandId, replyBuf, 4,  status);
	}
	else 
	{
		if ((offset >= 0) && (blocksize <= 1000) && (blocksize + blocksize) <= totalsize)
		{
			status = 0;
			ptr += offset;
			A_MEMCPY(replyBuf, (A_UINT8 *)&blocksize, 2);
			A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
			A_MEMCPY(replyBuf + 4 , ptr, blocksize);
			sendNartResponse (dev, pCmd->commandId, replyBuf, blocksize + 4,  status);
		}
		else
		{
			status = 1;
			A_MEMCPY(replyBuf, (A_UINT8 *)&blocksize, 2);
			A_MEMCPY(replyBuf + 2, (A_UINT8 *)&offset, 2);
			sendNartResponse (dev, pCmd->commandId, replyBuf, 4,  status);
		}
	}
	
	return 0;
}

#endif   //===>#if defined(AR900B)
//**************************************************************************

/**************************************************************************
* processNoiseFloorReadCmd - Process NOISE_FLOOR_READ command
*
* RETURNS: Noise floor values for all chains 
*/
A_UINT32 processNoiseFloorReadCmd (wlan_tcmd_dev_t *dev, _CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32 status;
    A_UINT32 ch_idx = 0;
    A_UINT32 wlanMode = TCMD_WLAN_MODE_VHT20;
    WHAL_CHANNEL chan;
    A_INT32 nf[16] = {0};
    A_INT16 temp;
    A_BOOL chain_enable[16] = {0};
    A_UINT32 cca[] = {
            PHY_BB_CCA_B0_ADDRESS,
    #if (WHAL_RX_NUM_CHAIN > 1)
            PHY_BB_CCA_B1_ADDRESS,
    #endif
    #if (WHAL_RX_NUM_CHAIN > 2)
            PHY_BB_CCA_B2_ADDRESS,
    #endif
    #if (WHAL_RX_NUM_CHAIN > 3)
            PHY_BB_CCA_B3_ADDRESS,
    #endif
    };

    if(pCmd->param2 == 1)
    {
        //Enable chain 1
        chain_enable[0] = 1;
        
    } 
    else if(pCmd->param2 == 2)
    {
        //Enable chain 2
        chain_enable[1] = 1;
    }
    else if(pCmd->param2 == 3)
    {
        //Enable chain 1,2
        chain_enable[0] = 1;
        chain_enable[1] = 1;
    }
    else if(pCmd->param2 == 4)
    {
        //Enable chain 3
        chain_enable[2] = 1;        
    }
    else if(pCmd->param2 == 5)
    {
        //Enable chain 1,3
        chain_enable[0] = 1;
        chain_enable[2] = 1;
    }
    else if(pCmd->param2 == 6)
    {
        //Enable chain 2,3
        chain_enable[1] = 1;
        chain_enable[2] = 1;
    }
    else if(pCmd->param2 == 7)
    {
        //Enable chain 1,2,3
        chain_enable[0] = 1;
        chain_enable[1] = 1;
        chain_enable[2] = 1;
    }
    else if(pCmd->param2 == 8)
    {
        //Enable chain 4
        chain_enable[3] = 1;
    }
    else if(pCmd->param2 == 9)
    {
        //Enable chain 1,4
        chain_enable[0] = 1;
        chain_enable[3] = 1;
    }
    else if(pCmd->param2 == 10)
    {
       //Enable chain 2,4
       chain_enable[1] = 1;
       chain_enable[3] = 1;        
    }
    else if(pCmd->param2 == 11)
    {
       //Enable chain 1,2,4
       chain_enable[0] = 1;
       chain_enable[1] = 1;
       chain_enable[3] = 1;
    }
    else if(pCmd->param2 == 12)
    {
       //Enable chain 3,4
       chain_enable[2] = 1;
       chain_enable[3] = 1;
    }
    else if(pCmd->param2 == 13)
    {
       //Enable chain 1,3,4
       chain_enable[0] = 1;
       chain_enable[1] = 1;
       chain_enable[3] = 1;
    }
    else if(pCmd->param2 == 14)
    {
       //Enable chain 2,3,4
       chain_enable[1] = 1;
       chain_enable[2] = 1;
       chain_enable[3] = 1;
    }    
    else if(pCmd->param2 == 15)
    {
        //Enable chain 1,2,3,4
        chain_enable[0] = 1;
        chain_enable[1] = 1;
        chain_enable[2] = 1;
        chain_enable[3] = 1;
    }
    
    tcmd_get_channel(pCmd->param1, wlanMode, 0, &chan, pCmd->param1);

    // do full phy reset
    if (whalReset(&chan, 0, WHAL_RESTORE_SW_SETTINGS, WHAL_RESET_CAUSE_FULL_RESET) == FALSE)
    {
        status = A_ERROR;
    }

    /* read the noise floor value from register for all chains */
    for (ch_idx = 0; ch_idx < NUM_MAX_CHAINS; ch_idx++)
    {
       	if((chain_enable[ch_idx] == 1) && (ch_idx < (sizeof(cca)/sizeof(cca[0]))))
       	{
              if ((OS_REG_READ(PHY_BB_AGC_CONTROL_ADDRESS) & PHY_BB_AGC_CONTROL_DO_NOISEFLOOR_MASK) == 0)
              {
       	      	   nf[ch_idx] = temp = MS(OS_REG_READ(cca[ch_idx]), PHY_BB_CCA_B0_MINCCAPWR_0);
				   if (temp & 0x100) temp = temp | (A_UINT16)0xFF00;
                   if (temp == PHY_CCA_MAX_GOOD_VAL)
                   {
                         /* This is the case when NF Could not converge due to high Interference but HW clears the NF cal complete bit */
					     nf[ch_idx] = 0;
				   }
				   // If negative say -100, it will be encoded as 0x10000064, if positive say 100, it will be decoded as 0x00000064
				   if(temp < 0)
				   {
					   nf[ch_idx] = ((0 - temp) | 0x10000000);
				   }
			  }
			  else
			  {
				  /*Request to return 0 if NF CAL does not converge during the dwell time for host to handle further ?*/
				  nf[ch_idx] = 0;
			  }

      	}
      	else
        {
       	       nf[ch_idx] = DEFAULT_NF_VALUE_NON_SUPPORTED_CHAIN;
        }

    }
    
    replyLength = 64;        
    A_MEMCPY((A_UINT32 *)replyBuf, nf, replyLength);
 
    status = 0;
    sendNartResponse (dev, pCmd->commandId, replyBuf, replyLength, status);

    return(0);
}

void sendNartResponse (wlan_tcmd_dev_t *dev,A_UINT32 cmdId,A_UINT8 *buf, A_UINT32 length, A_UINT32 status)
{
    A_BOOL ret = FALSE;
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0;

    ret = createCommand(_OP_GENERIC_NART_RSP);

    if ( ret == TRUE )
    {
        ret = addParameterToCommand((A_UINT8*)"commandId",(A_UINT8*)&cmdId);

        if ( ret == FALSE )
            A_PRINTF("add commandId failed\n");

        ret = addParameterToCommand((A_UINT8*)"status",(A_UINT8*)&status);

        if ( ret == FALSE )
            A_PRINTF("add status failed\n");

        ret = addParameterToCommand((A_UINT8*)"length",(A_UINT8*)&length);

        if ( ret == FALSE )
            A_PRINTF("add length failed\n");

        if (length)
        {
            ret = addParameterToCommandWithLen((A_UINT8*)"data",(A_UINT8*)buf,length);

            if ( ret == FALSE )
                A_PRINTF("add data failed\n");
        }

        if ( ret == TRUE )
        {
            ret = commandComplete(&rCmdStream, &cmdStreamLen );

            //A_PRINTF("stream length ..%d\n",cmdStreamLen);

            if ( ret == TRUE )
            {
                 //A_PRINTF("Command Id Response..%d\n",cmdId);

                 // Now let's send the response..
#if defined(_UTF_HOSTIF_TS_W_WMI) || defined(_UTF_HOSTIF_WMI)
                 wmi_tc_cmds_reply_event(dev->wmi,cmdStreamLen,_OP_GENERIC_NART_RSP,(A_INT8*)rCmdStream);
#endif
            }
         }
         else
         { 
             A_PRINTF("add Param failed sendNartResponse\n");
         }
    }

}

void processNartCommand (wlan_tcmd_dev_t *dev,_CMD_NARTCMD_PARMS *pCmd)
{
    A_UINT32 cmdId = pCmd->commandId;
    A_UINT32 status = 0;
    A_BOOL sendResponse = TRUE;
    //A_BOOL printCmdId = TRUE;


    replyLength = 0;
    if ( replyBuf == NULL )
        replyBuf = &dataPayload[0];
#if 0
    if ( (cmdId == M_TX_DATA_STATUS_CMD_ID) || (cmdId == M_TX_DATA_STOP_CMD_ID) || (cmdId == M_RX_DATA_STATUS_CMD_ID) || (cmdId == M_RX_DATA_STOP_CMD_ID) )
        printCmdId = FALSE;

    if ( printCmdId == TRUE )
        A_PRINTF("!Command Id Got!!!..%d\n",cmdId);
#endif

    switch (cmdId) {
	case INIT_F2_CMD_ID:
	    status = processInitF2Cmd(pCmd);
	    break;
        case MEM_READ_CMD_ID:
            status = processMemReadCmd(pCmd);
            break;
        case MEM_WRITE_CMD_ID:
            status = processMemWriteCmd(pCmd);
            break;
        case REG_READ_CMD_ID:
            status = processRegReadCmd(pCmd);
            break;
        case REG_WRITE_CMD_ID:
            status = processRegWriteCmd(pCmd);
            break;
        case CFG_READ_CMD_ID:
            status = processCfgReadCmd(pCmd);
            break;
        case MEM_READ_BLOCK_CMD_ID:
            status = processMemReadBlockCmd(pCmd);
            break;
        case MEM_WRITE_BLOCK_CMD_ID:
            status = processMemWriteBlockCmd(pCmd);
            break;
        case M_STICKY_WRITE_CMD_ID:
            status = processStickyWriteCmd(pCmd);
            break;
        case M_STICKY_CLEAR_CMD_ID:
            status = processStickyClearCmd(pCmd);
            break;
        case M_CLOSE_DEVICE_CMD_ID:
            status = processCloseDeviceCmd(pCmd);
            break;
        case M_HW_RESET_CMD_ID:
            status = processHwReset(pCmd);
            break;
        case GET_REF_CLK_SPEED_CMD_ID:
            status = processGetRefClkSpeedCmd(pCmd);
            break;
        case SLEEP_CMD_ID:
            status = processSleepCmd(pCmd);
            break;
        case M_RESET_DEVICE_CMD_ID:
            status = processResetDeviceCmd(pCmd);
            break;
        case OTP_READ_CMD_ID:
            status = processOtpReadCmd(pCmd);
            break;
        case OTP_WRITE_CMD_ID:
            status = processOtpWriteCmd(pCmd);
            break;
        case OTP_RESET_CMD_ID:
            status = processOtpResetCmd(pCmd);
            break;
        case OTP_LOAD_CMD_ID:
            status = processOtpLoadCmd(pCmd);
            break;
        case EFUSE_READ_CMD_ID:
            status = processEfuseReadCmd(pCmd);
            break;
        case M_EEPROM_WRITE_ITEMS_CMD_ID:
            status = processEepromWriteItemsCmd(pCmd);
            break;
        case EFUSE_WRITE_CMD_ID:
            status = processEfuseWriteCmd(pCmd);
            break;
        case M_TX_DATA_START_CMD_ID:
            status = processTxDataStartCmd(dev,pCmd);
            replyLength = 0;
            break;
        case M_TX_DATA_STOP_CMD_ID:
            status = processTxDataStopCmd(dev,pCmd);
            sendResponse = FALSE; //Status response will be send in the function itself..
            break;
        case M_TX_DATA_STATUS_CMD_ID:
            status = processTxDataStatusCmd(dev,pCmd);
            sendResponse = FALSE; //Status response will be send in the function itself..
            break;
        case M_RX_DATA_START_CMD_ID:
	    status = processRxDataStartCmd(dev,pCmd); 
            replyLength = 0;
            break;
        case M_RX_DATA_STOP_CMD_ID:
	    status = processRxDataStopCmd(dev,pCmd);
            sendResponse = FALSE; //Status response will be send in the function itself..
            break;
        case M_RX_DATA_STATUS_CMD_ID:
	    status = processRxDataStatusCmd(dev,pCmd);
            sendResponse = FALSE; //Status response will be send in the function itself..
            break;
        case DISCONNECT_PIPE_CMD_ID:
        case CLOSE_PIPE_CMD_ID:
            status = 0;
            break;
#if defined(AR6320)
        case TARGET_MEM_CLEAR_CMD_ID:
            status = processTargetMemClearCmd(pCmd);
            break;
        case TARGET_CAL_CRC_CMD_ID:
            status = processTargetCalCRCCmd(pCmd);
            break;
#endif //AR6320
#if defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
	case M_EEEPROM_BLOCK_READ_ID:
            status = processEepromReadCmd(dev, pCmd);
	    sendResponse = FALSE; //Status response will be send in the function itself..
            break;
        case M_EEEPROM_BLOCK_WRITE_ID:
            status = processEepromWriteCmd(dev, pCmd);
	    sendResponse = FALSE; //Status response will be send in the function itself..
            break;
	case M_EEEPROM_BLOCK_ERASE_ID:
	    status = processEepromEraseCmd(dev, pCmd);
            sendResponse = FALSE; //Status response will be send in the function itself..
            break;
	case M_EEEPROM_BLOCK_CHECK_ID:
            status = processEepromCheckCmd(dev, pCmd);
            sendResponse = FALSE; //Status response will be send in the function itself..
	    break;
    case NV_SET_MAC_ADDR_CMD_ID:
            status = processNVSetMacAddrCmd(dev, pCmd);
	    sendResponse = FALSE; //Status response will be send in the function itself..
            break;
    case NV_GET_MAC_ADDR_CMD_ID:
            status = processNVGetMacAddrCmd(dev, pCmd);
	    sendResponse = FALSE; //Status response will be send in the function itself..
	    break;
    case M_WRITE_FW_BD_ID:  //a new TLV command for writing BoardData to persistent memory
  	    status = processNVBoardDataCommitCmd(dev, pCmd);
	    sendResponse = FALSE; //Status response will be send in the function itself..
	    break;
    case M_READ_FW_BD_ID:  //a new TLV command for reading cal BoardData to QSPR
	    status = processCalBoardDataCmd(dev, pCmd);
	    sendResponse = FALSE; //Status response will be send in the function itself..
	    break;
    case GET_TX_OFFLINE_POWER_ID:
            status = processGetTxOfflinePower(dev, pCmd);
	    sendResponse = FALSE; //Status response will be send in the function itself..
	    break;
    case M_READ_FW_BD_SIZE_ID:
	    {
		    A_UINT16 totalbdatasize = utfGetBoardDataSize();
		    status = 0;
		    replyLength = 2;
		    replyBuf = &dataPayload[0];
		    A_MEMCPY(replyBuf, (A_UINT8 *)&totalbdatasize, 2);
		    sendResponse =  TRUE;
	    }
	    break;
    case NV_SET_MCN_NUM_CMD_ID:
            status = processNVSetMcnNumCmd(dev, pCmd);
	    sendResponse = FALSE; //Status response will be send in the function itself..
            break;
    case NV_GET_MCN_NUM_CMD_ID:
            status = processNVGetMcnNumCmd(dev, pCmd);
            sendResponse = FALSE; //Status response will be send in the function itself..
            break;
    case NOISE_FLOOR_READ_CMD_ID:
            status = processNoiseFloorReadCmd(dev, pCmd);
            sendResponse = FALSE; //Status response will be send in the function itself..
            break;
#endif 
        default:
            status = 1;
            break;
   }

   status = status << COMMS_ERR_SHIFT;
   sleep_enable = 0;
  
   if ( sendResponse == TRUE )
       sendNartResponse(dev,cmdId,replyBuf,replyLength,status);
}

void initThreadInfo(void) 
{
    dkThread->inUse = 0;
    dkThread->threadId = 0;
    dkThread->PipeBuffer_p = NULL;
    dkThread->ReplyCmd_p = NULL;
    dkThread->numClients = 0;
    dkThread->currentDevIndex = (A_UINT32)INVALID_ENTRY;

    dkThread->devIndex = (A_UINT32)INVALID_ENTRY;
    dkThread->devNum = INVALID_ENTRY;
	
    return;	
}

void alloc_pool_stat_init ()
{
    int i=0,size;
    int *index;

    size = sizeof (TX_STATS_STRUCT_UTF);

    if (size < sizeof (RX_STATS_STRUCT_UTF) )
    {
        size = sizeof (RX_STATS_STRUCT_UTF);
    }

    for(i=0;i<MAX_POOL_STAT;i++)
    {
       //statPool[i].buf = (unsigned char *)malloc(size + sizeof(int)); 
       statPool[i].buf = (unsigned char *)A_ALLOCRAM(size + sizeof(int)); 
       index = (int *)&statPool[i].buf[0];
       *index = i;
       statPool[i].avail = 1;
    }
}

void return_all_stat_buf()
{
    int i=0;
    for(i=0;i<MAX_POOL_STAT;i++)
    {
        statPool[i].avail = 1;
    }
}

void current_pool_stat_buf()
{
    int i=0,cnt=0;
    for(i=0;i<MAX_POOL_STAT;i++)
    {
        if (statPool[i].avail)
            cnt++;
    }

    //A_PRINTF("Cnt available %d\n",cnt);
}

void free_all_stat_buf()
{
    int i=0;
    for(i=0;i<MAX_POOL_STAT;i++)
    {
        if (statPool[i].avail)
        {
            A_FREE(statPool[i].buf);
            statPool[i].avail = 0;
            statPool[i].buf = NULL;
        }
    }
}

unsigned char* get_pool_stat_buf() 
{
    int i=0,size;
    size = sizeof (TX_STATS_STRUCT_UTF);

    if (size < sizeof (RX_STATS_STRUCT_UTF) )
    {
        size = sizeof (RX_STATS_STRUCT_UTF);
    }

    for(i=0;i<MAX_POOL_STAT;i++)
    {
        if ( statPool[i].avail )
        {
            statPool[i].avail = 0;
            //A_PRINTF("Index Alloc %d\n",i);

            memset(&statPool[i].buf[sizeof(int)],0,size);

            return (&statPool[i].buf[sizeof(int)]);
        }
    }

    return NULL;
}

void free_pool_stat_buf( char * buf)
{
    int index;

    buf = buf - sizeof(int); 

    index = *(int *)&(buf[0]);

    if (index >= MAX_POOL_STAT )
    {
        A_PRINTF("Invalid free Index not valid!!!\n");
        return;
    }
   
    A_PRINTF("Index free %d\n",index);

    statPool[index].avail = 1;
}
