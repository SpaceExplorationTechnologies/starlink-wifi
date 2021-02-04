/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// hw.c - contain the access hrdware routines 

// Copyright (c) 2001 Atheros Communications, Inc., All Rights Reserved
// $ATH_LICENSE_TARGET_C$

#include <athdefs.h>
#include <utf_dev.h>
#include <testcmd.h>

#include "osapi.h"
#include "dk_common.h"
#include "dk_client.h"
#include "dk_cmds.h"
#include "dkkernel.h"
#include "ar6000defs.h"
#include "soc/soc.h"
//#include "hw/gpio_reg.h"

#include "hw.h"
#include "flash_ops.h"
#include "dk_ver.h"
#ifdef AR6K
#include "ar6000defs.h"
#endif
#include "ar6000_phyReg.h"
#include "ar6000_internal.h"
#if defined(VENUS_EMULATION_ARES)
#include "hw/gpio_reg.h"
#include "hw/analog_intf_ares_reg.h"
#endif // #if defined(VENUS_EMULATION_ARES)

#include "efuse_api.h"
#if !defined(IPQ4019)
#include "otpstream_api.h"
#endif

#include "tcmd_api.h"

#define MERCURY_ASIC 1

#define CORE_CLOCK_ADDRESS  CORE_CLK_CTRL_ADDRESS
#if defined(AR6320)
#define MDK_CRC_POLYNOMIAL 0xedb88320 
#endif //AR6320

// FORWARD DECLARATIONS
static void hwClose(MDK_WLAN_DEV_INFO *pdevInfo);
void hwInit(MDK_WLAN_DEV_INFO *pdevInfo, A_UINT32 resetMask);

void deviceCleanup(A_UINT16 devIndex);

// global variables
MDK_WLAN_DRV_INFO	globDrvInfo;				
MDK_WLAN_DEV_INFO pDevInfoArray[MAX_CLIENTS_SUPPORTED]; 	/* Array of devinfo pointers */
struct dkDevInfo pdkInfo[MAX_CLIENTS_SUPPORTED];   	/* pointer to structure containing info for dk */
A_UINT8 *cal_offset;

#if defined(AR6320)
A_UINT32 mdk_crc32_table[256];   
#endif //AR6320

A_UINT32 sleep_control_reg, cpu_clk_reg, core_clk_reg, clk_control_reg, ldo_volt_reg, ldo_a_volt_reg, sdio_ldo_volt_reg, core_pad_enable_reg, sdio_wrapper_reg;
//static A_UINT32 system_sleep_reg;

void uDelay(A_INT32 val) {
   //A_UINT32 iIndex, jIndex=1;

   A_DELAY_USECS(val);
   return;

}

#if defined(AR6320)
void initCrcTable() {
    A_UINT32 n, k, c;

    for (n = 0; n < 256; n++) {
        c = n;
        for (k = 0; k < 8; k++) {
            if (c & 1)
                c = MDK_CRC_POLYNOMIAL ^ (c >> 1);
            else
                c = c >> 1;
        }
        mdk_crc32_table[n] = c;
    }
}
#endif //AR6320

/**************************************************************************
* envInit - performs any intialization needed by the environment
*
* RETURNS: A_OK always
*/
A_STATUS envInit
(
    	A_BOOL debugMode
)
{
#if !defined(AR6004_Emulation)
    WHAL_STRUCT *pWhalStruct;
    A_UINT8                     ic_myaddr[IEEE80211_ADDR_LEN];
#endif


    //A_UINT32 flash_size;
    globDrvInfo.devCount = 0;

    if (!(tcmd_state.flags & 0x4)) {
    A_PRINTF("brd Data\n");
    cal_offset = A_BOARD_DATA_ADDR();
    tcmd_state.flags |= 0x4;
    }
    kpInit();

#if !defined(AR6004_Emulation)
    // WHAL initialization
    if (!(tcmd_state.flags & 0x2)) {
    A_PRINTF("whalAttach\n");
    pWhalStruct = whalAttach(cal_offset, ic_myaddr);

    A_ASSERT (pWhalStruct != NULL);
    //whalRamPatchInit(pWhalStruct, ic_boardMode); // only for AR6002

    WHAL_INI_MODULE_INSTALL();
    whal_ini_init(whalGetBoardFlags());
    
    tcmd_state.flags |= 0x2;
    }
#endif

    // setup efuse/OTP steam
    EFUSEW_MODULE_INSTALL(); /* additional write support for eFuse */
#if !defined(IPQ4019)    
    OTPSTREAM_MODULE_INSTALL();

#ifdef FIXME_WIFI2
    otpstream_init();
#endif
#endif

    // done
    return A_OK;
}

void envCleanup
(
    	A_BOOL closeDriver
)
{

	globDrvInfo.devCount = 0;

	if (closeDriver) {
		kpExit();
	}
}


/**************************************************************************
* deviceInit - performs any initialization needed for a device
*
* Perform the initialization needed for a device.  This includes creating a 
* devInfo structure and initializing its contents
*
* RETURNS: A_OK if successful, A_ERROR if not
*/
A_STATUS deviceInit
(
    	A_UINT16 devIndex, // index of globalDrvInfo which to add device to 
		A_UINT16 device_fn
)
{
    MDK_WLAN_DEV_INFO *pdevInfo;
 	A_INT32      kpHandle;
	KP_CLIENT_INFO kpClientInfo;
	int iIndex;
//    A_UINT16 spi_select = sysFlashRead(EEPROM_CONFIG_REG) & SPI_SELECT_OFFSET;
	
	for(iIndex=0;iIndex<MAX_CLIENTS_SUPPORTED;iIndex++) {
	   pDevInfoArray[iIndex].pdkInfo = &(pdkInfo[iIndex]);
       globDrvInfo.pDevInfoArray[iIndex] = &pDevInfoArray[iIndex];
	}
    pdevInfo = globDrvInfo.pDevInfoArray[devIndex];
    //uiPrintf("DeviceInit for %d\n", devIndex);
	//zero out the pdkInfo struct
    A_MEMZERO(pdevInfo->pdkInfo, sizeof(DK_DEV_INFO));

	kpHandle = kpOpen(devIndex);            
    	if (kpHandle < 0) {
            uiPrintf("Error: Unable to open plugin!\n");
		    return A_ERROR;
	    }
	pdevInfo->kpHandle = kpHandle;	
	
	if (kpGetClientInfo(kpHandle,&kpClientInfo) < 0) {
            	uiPrintf("Error: Unable to get client info\n");
		kpClose(kpHandle);
		return A_ERROR;
	}


	pdevInfo->pdkInfo->f2Mapped = 0x1;
	pdevInfo->pdkInfo->devMapped = 0x1;
   	pdevInfo->pdkInfo->devIndex = devIndex;
	pdevInfo->pdkInfo->f2MapAddress = kpClientInfo.regPhyAddr;
	pdevInfo->pdkInfo->regVirAddr = kpClientInfo.regVirAddr;
	pdevInfo->pdkInfo->regMapRange = kpClientInfo.regRange;
	pdevInfo->pdkInfo->aregPhyAddr[0] = pdevInfo->pdkInfo->f2MapAddress;
	pdevInfo->pdkInfo->aregVirAddr[0] = pdevInfo->pdkInfo->regVirAddr;
	pdevInfo->pdkInfo->aregRange[0] = pdevInfo->pdkInfo->regMapRange;
	pdevInfo->pdkInfo->memPhyAddr = kpClientInfo.memPhyAddr;
	pdevInfo->pdkInfo->memVirAddr = kpClientInfo.memVirAddr;
	pdevInfo->pdkInfo->memSize = kpClientInfo.memSize;
	pdevInfo->pdkInfo->haveEvent = 0;
	pdevInfo->pdkInfo->numBars = 1;
	pdevInfo->pdkInfo->device_fn = 0;
	pdevInfo->pdkInfo->printPciWrites = 0;
	//pdevInfo->pdkInfo->version = PREDATOR_CLIENT_MAJ_VER << 4 | PREDATOR_CLIENT_MIN_VER;
	pdevInfo->pdkInfo->version = (ART_BUILD_NUM << 16) | (ART_VERSION_MAJOR << 4) | ART_VERSION_MINOR;

	uiPrintf("Allocated %d Mem at %x \n",pdevInfo->pdkInfo->memSize,pdevInfo->pdkInfo->memVirAddr);
	uiPrintf("Register: %x : range = %x\n",pdevInfo->pdkInfo->f2MapAddress, pdevInfo->pdkInfo->regMapRange);

    globDrvInfo.devCount++;

//	apRegWrite32(0xa0c00020, 0x0);
//	apRegWrite32(0xa0b10008, apRegRead32(0xa0b10008) | 0x8000);

	hwInit(pdevInfo, BUS_RESET|MAC_RESET|BB_RESET);

#if defined(AR6320)
	initCrcTable();
#endif //AR6320
	return A_OK;
}

// reference ar6000WlanHwReset
void hwInit(MDK_WLAN_DEV_INFO *pdevInfo, A_UINT32 resetMask)
{

#if 0
    volatile A_UINT32 reg;
    reg = A_RTC_REG_READ(QUADRATURE_ADDRESS);
    reg &= ~QUADRATURE_DAC_MASK;
    reg |= QUADRATURE_DAC_SET(2);
    A_RTC_REG_WRITE(QUADRATURE_ADDRESS, reg); 

#if defined(VENUS_EMULATION_ARES)
    A_ANALOG_REG_WRITE(PHY_ANALOG_RXTX2_ADDRESS, 0xFFB08065);

    /* force ADC ON */
    A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_RXTX3_ADDRESS, PHY_ANALOG_RXTX3_ADCPWD_OVR, 0x1);
    A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_TOP1_ADDRESS, PHY_ANALOG_TOP1_CLKMOD_RSTB, 0x1);
    A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_TOP4_ADDRESS, PHY_ANALOG_TOP4_ADCPWD_OVR, 0x1);

    A_ANALOG_REG_WRITE(PHY_ANALOG_RXTX3_ADDRESS, 0x80080410);
    /* Set 4 for OFDM and 0 for CCK */
    A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_RXTX3_ADDRESS, PHY_ANALOG_RXTX3_SPARE3, 0x4);

    /* Clear GPIO19 */
    A_GPIO_REG_WRITE(WLAN_GPIO_ENABLE_W1TS_ADDRESS, WLAN_GPIO_ENABLE_W1TS_DATA_SET(1 << 19));
    A_GPIO_REG_WRITE(WLAN_GPIO_OUT_W1TC_ADDRESS, WLAN_GPIO_OUT_W1TC_DATA_SET(1 << 19));

    /* Set pll bypass */
    A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_TOP1_ADDRESS, PHY_ANALOG_TOP1_PLLBYPASS, 0x1);

    /* Program pll */
    A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_TOP1_ADDRESS, PHY_ANALOG_TOP1_REFDIV, 0x5);
#if 0 // tbd?? determine the band?
    if ((chan != NULL) && (bandArray[chan->wlanMode] ==  A_BAND_5GHZ)) {
        A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_TOP1_ADDRESS, PHY_ANALOG_TOP1_DIV, 0x28);
    } else {
#endif
        A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_TOP1_ADDRESS, PHY_ANALOG_TOP1_DIV, 0x2c);
    //}

    /* clear pll bypass */
    A_ANALOG_REG_RMW_FIELD(PHY_ANALOG_TOP1_ADDRESS, PHY_ANALOG_TOP1_PLLBYPASS, 0x0);
    A_DELAY_USECS(100);

    /* Set GPIO19 */
    A_GPIO_REG_WRITE(WLAN_GPIO_OUT_W1TS_ADDRESS, WLAN_GPIO_OUT_W1TS_DATA_SET(1 << 19));
    A_DELAY_USECS(1000);

#endif   // #if defined(VENUS_EMULATION_ARES)

    /* Disable PHY before reset */
    OS_REG_WRITE(PHY_BB_ACTIVE_ADDRESS, 0);

    A_RESET_MAC();
    A_RESET_BB();

    WHAL_MAC_WAKEUP();
    //MAC_WAKEUP();

#if defined(FPGA)
    uDelay(1000);
#endif

#if defined(FPGA)
#else
#endif
#endif
}

void hwClose
(
	MDK_WLAN_DEV_INFO *pdevInfo
)
{
#if  0
	A_UINT32      reg;//, reg_pci;
	reg = A_RTC_REG_READ(RESET_CONTROL_ADDRESS);
	reg |= RESET_CONTROL_MAC_WARM_RST_SET(1);
	A_RTC_REG_WRITE(RESET_CONTROL_ADDRESS, reg);
	uDelay(100);
	  //uiPrintf("exit hwClose\n");
#endif

}


/**************************************************************************
* deviceCleanup - performs any memory cleanup needed for a device
*
* Perform any cleanup needed for a device.  This includes deleting any 
* memory allocated by a device.
*
* RETURNS: 1 if successful, 0 if not
*/
void deviceCleanup
(  	
	A_UINT16 devIndex        
)
{
	MDK_WLAN_DEV_INFO *pdevInfo;

	pdevInfo = globDrvInfo.pDevInfoArray[devIndex];

	hwClose(pdevInfo);
	/* free the DK_DEV_INFO struct */
	kpClose(pdevInfo->kpHandle);

	globDrvInfo.devCount--;
}


/**************************************************************************
* checkRegSpace - Check to see if an address sits in the setup register space
*
* This internal routine checks to see if an address lies in the register space
*
* RETURNS: A_OK to signify a valid address or A_ENOENT
*/
A_STATUS checkRegSpace
(
	MDK_WLAN_DEV_INFO *pdevInfo,
	A_UINT32      address
)
{
	if((address >= pdevInfo->pdkInfo->f2MapAddress) &&
		(address < pdevInfo->pdkInfo->f2MapAddress + pdevInfo->pdkInfo->regMapRange)) {
		return A_OK;
	} else {
		return A_ENOENT;
	}
    return(A_OK);  /* keep compiler happy */
}

/**************************************************************************
* checkMemSpace - Check to see if an address sits in the setup physical memory space
* 
* This internal routine checks to see if an address lies in the physical memory space
*
* RETURNS: A_OK to signify a valid address or A_ENOENT
*/
A_STATUS checkMemSpace
(
	MDK_WLAN_DEV_INFO *pdevInfo,
	A_UINT32      address
)
{
	if ((address >= pdevInfo->pdkInfo->memPhyAddr) &&
	    (address < (pdevInfo->pdkInfo->memPhyAddr + pdevInfo->pdkInfo->memSize))) {
		return A_OK;
	} else {
		return A_ENOENT;
	}
    return(A_OK);  /* keep compiler happy */
}

/**************************************************************************
* hwMemRead32 - read an 32 bit value
*
* This routine will read the register pointed by the address 
* and return the value or read the memory pointed by the
* address.
*
* RETURNS: the value read
*/
A_UINT32 hwMemRead32
(
	A_UINT16 devIndex,
    	A_UINT32 address                  
)
{
    A_UINT32 value=0xdeadbeef;
    value = A_SOC_ADDR_READ(address); 
    return value;
}

#if defined(AR6320)
void hwMemClear
(
    A_UINT16 devIndex,
    A_UINT32 address,
    A_UINT32 numBytes
)
{
    A_MEMZERO(address, numBytes);
    return;
}
#endif //AR6320

/**************************************************************************
* hwMemWrite32 - write a 32 bit value
*
* This routine will write the value into the register pointed 
* by the address or write into the memory pointed by the address.
*
* RETURNS: N/A
*/
void hwMemWrite32
(
	A_UINT16 devIndex,
    	A_UINT32 address,         
    	A_UINT32 value           
)
{ 
    A_SOC_ADDR_WRITE(address, value); 
    return;
}


/**************************************************************************
* hwMemWriteBlock -  Write a block of memory.
*
* Write a block of memory.
*
* RETURNS: 0 on success, -1 on error
*/
A_INT16 hwMemWriteBlock
(
	A_UINT16 devIndex,
 	A_UCHAR  *pBuffer,
 	A_UINT32 length,
 	A_UINT32 *pPhysAddr
)
{
    	A_UCHAR *pMem;             // pointer to area to be written 
	MDK_WLAN_DEV_INFO *pdevInfo;

	pdevInfo = globDrvInfo.pDevInfoArray[devIndex];

    	// first need to check that the phys address is within the allocated memory block.
       	// Need to make sure that the begin size and endsize match.  Will check all the 
       	// devices.  Only checking the memory block, will not allow registers to be accessed
       	// this way
         
	//check start and end addresswithin memory allocation
	if ((A_OK == checkMemSpace(pdevInfo, *pPhysAddr)) && (A_OK == checkMemSpace(pdevInfo, *pPhysAddr + length))) {
            /* get the virtual pointer to start and read */
            pMem = (A_UCHAR *) (pdevInfo->pdkInfo->memVirAddr + (*pPhysAddr - pdevInfo->pdkInfo->memPhyAddr));
            A_MEMCPY(pMem,pBuffer, length);
            return (0);
	}				

    	uiPrintf("Warning: (%x/%d) not within mem range (%x/%d)\n", *pPhysAddr, length, pdevInfo->pdkInfo->memPhyAddr, pdevInfo->pdkInfo->memSize);
    	return(-1);
}

/**************************************************************************
* hwMemReadBlock - Read a block of memory.
*
* Read a block of memory. 
*
* RETURNS: 0 on success, -1 on error
*/
A_INT16 hwMemReadBlock
(
	A_UINT16 devIndex,
 	A_UCHAR    *pBuffer,
 	A_UINT32 physAddr,
 	A_UINT32 length
)
{
    	A_UCHAR *pMem;                // pointer to area to be written 
	MDK_WLAN_DEV_INFO *pdevInfo;

	pdevInfo = globDrvInfo.pDevInfoArray[devIndex];
    	// first need to check that the phys address is within the allocated memory block.
       	// Need to make sure that the begin size and endsize match.  Will check all the 
       	// devices.  Only checking the memory block, will not allow registers to be accessed
       	// this way
     
	if ((A_OK == checkMemSpace(pdevInfo, physAddr)) && (A_OK == checkMemSpace(pdevInfo, physAddr + length))) {
            /* get the virtual pointer to start and read */
            pMem = (A_UCHAR *) (pdevInfo->pdkInfo->memVirAddr + (physAddr - pdevInfo->pdkInfo->memPhyAddr));
            A_MEMCPY(pBuffer, pMem, length);
            //uiPrintf("Memory Read Block @ %x : length = %d \n",(A_UINT32)physAddr,length);
            return (0);
	}				
	
   	// if got to here, then address is bad 
    	uiPrintf("Warning: (%x/%d) not within mem range (%x/%d)\n", physAddr, length, pdevInfo->pdkInfo->memPhyAddr, pdevInfo->pdkInfo->memSize);
    	return(-1);
}

void wake_up(A_HANDLE h, void *arg) {

    //A_PRINTF("wakeup\n");
#if 0
    A_UINT32 reg;
    reg = A_RTC_REG_READ(MAC_SLEEP_CONTROL_ADDRESS); 
    reg &= ~MAC_SLEEP_CONTROL_ENABLE_MASK;
    reg |= MAC_SLEEP_CONTROL_ENABLE_SET(0);  // 1: forced sleep, 2: normal wakeup, 0: forced wakeup
    A_RTC_REG_WRITE(MAC_SLEEP_CONTROL_ADDRESS, reg); 

    system_sleep_reg |= SYSTEM_SLEEP_DISABLE_MASK; 
    A_RTC_REG_WRITE(SYSTEM_SLEEP_ADDRESS, system_sleep_reg);
#endif
}

unsigned int val;

void deep_sleep(A_UINT32 se) {

#if 0
    A_UINT32 regVal;
    if (se) {
        //A_PRINTF("sle..\n");
        regVal = A_RTC_REG_READ(MAC_SLEEP_CONTROL_ADDRESS); 
        regVal &= ~MAC_SLEEP_CONTROL_ENABLE_MASK;
        regVal |= MAC_SLEEP_CONTROL_ENABLE_SET(1); 
        A_RTC_REG_WRITE(MAC_SLEEP_CONTROL_ADDRESS, regVal); 

        regVal = system_sleep_reg = A_RTC_REG_READ(SYSTEM_SLEEP_ADDRESS);
        regVal &= ~SYSTEM_SLEEP_DISABLE_MASK;
        A_RTC_REG_WRITE(SYSTEM_SLEEP_ADDRESS, regVal);
        //(void) A_RTC_REG_READ(SYSTEM_SLEEP_ADDRESS); /* flush */
        //asm volatile("waiti 0;");         
    } else {
        wake_up(0, NULL);
    }
#endif
}

/**************************************************************************
* hwCreateEvent - Create an event
*
* Used to create Interrupt Events
*
* RETURNS: 0 on success, -1 on error
*/

A_INT16 hwCreateEvent
(
	A_UINT16 devIndex,
	PIPE_CMD *pCmd
)
{
	A_INT16 ret;
	MDK_WLAN_DEV_INFO *pdevInfo;

	pdevInfo = globDrvInfo.pDevInfoArray[devIndex];
	pdevInfo->pdkInfo->haveEvent = 1;

	ret = kpCreateEvent(pdevInfo->kpHandle,
		      pCmd->CMD_U.CREATE_EVENT_CMD.type,
		      pCmd->CMD_U.CREATE_EVENT_CMD.persistent,
		      pCmd->CMD_U.CREATE_EVENT_CMD.param1,
		      pCmd->CMD_U.CREATE_EVENT_CMD.param2,
		      pCmd->CMD_U.CREATE_EVENT_CMD.param3,
		      pCmd->CMD_U.CREATE_EVENT_CMD.eventHandle);

	return (ret);
}

/**************************************************************************
* hwCreateEvent - Create an event
*
* Used to create Interrupt Events
*
* RETURNS: 0 on success, -1 on error
*/

A_INT16 hwCreateEvt
(
        A_UINT16 devIndex,
        A_UINT32 type,
        A_UINT32 persistent,
        A_UINT32 param1,
        A_UINT32 param2,
        A_UINT32 param3,
        A_UINT16 eventID,
        A_UINT16 f2Handle
)
{
        A_INT16 ret;
        MDK_WLAN_DEV_INFO *pdevInfo;
        EVT_HANDLE eventHandle;

        pdevInfo = globDrvInfo.pDevInfoArray[devIndex];
        pdevInfo->pdkInfo->haveEvent = 1;

        eventHandle.eventID = eventID;
        eventHandle.f2Handle = f2Handle;

        ret = kpCreateEvent(pdevInfo->kpHandle,
                      type,
                      persistent,
                      param1,
                      param2,
                      param3,
                      eventHandle);

        return (ret);
}


/**************************************************************************
* hwGetNextEvent - Get next event
*
* Call into kernel plugin to get the next event.
* Copy into called supplied buffer
*
* RETURNS: 0 on success, -1 on error
*/

A_INT16 hwGetNextEvent
(
	A_UINT16 devIndex,
	void *pBuf
)
{
	MDK_WLAN_DEV_INFO *pdevInfo;

	pdevInfo = globDrvInfo.pDevInfoArray[devIndex];

	((EVENT_STRUCT *)pBuf)->type = 0;

	kpGetNextEvent(pdevInfo->kpHandle,(EVENT_STRUCT *)pBuf);		
		
	return 0;
}


A_UINT32 hwCfgRead32
(
	A_UINT16 devIndex,
    	A_UINT32 address                    /* the address to read from */
)
{
    	A_UINT8 buf[4];
    	A_UINT32 *pValue = (A_UINT32 *) buf;
	MDK_WLAN_DEV_INFO *pdevInfo;

	pdevInfo = globDrvInfo.pDevInfoArray[devIndex];

	kpCfgRead(pdevInfo->kpHandle, address, 32, (A_UINT32 *)pValue);

	return (*pValue);
}

void hwCfgWrite32
(
	A_UINT16 devIndex,
	A_UINT32 address,                    /* the address to write */
	A_UINT32  value                        /* value to write */
)
{
	MDK_WLAN_DEV_INFO *pdevInfo;
	pdevInfo = globDrvInfo.pDevInfoArray[devIndex];

	kpCfgWrite(pdevInfo->kpHandle, address,  32, (A_UINT32)value);
	uiPrintf("Config write @ address %08x: %08x\n", address, value);
}

