/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

/* dkkernel.c - contians dk kernel related functions  */

/*
 * Copyright (c) 2000 Atheros Communications, Inc., All Rights Reserved
 * $ATH_LICENSE_TARGET_C$
 */

#include "osapi.h"
#include "dk_common.h"
#include "dkkernel.h"
#include "event.h"
#include "ar6000defs.h"


// Hardcoded vendor and device ID
// TBD???
//#define AR6000_EMULATION_DEVICE_VENDOR_ID	0xf0d00cf3
#define AR6000_EMULATION_DEVICE_VENDOR_ID	( (SW_DEVICE_ID_VENUS<<16)| 0x0cf3)

#define AR6000_DEVICE_VENDOR_ID	( (SW_DEVICE_ID_DRAGON<<16)| 0x0cf3)
#define AR6003_DEVICE_VENDOR_ID	( (SW_DEVICE_ID_VENUS<<16)| 0x0cf3)

#define UNKNOWN_DEVICE_VENDOR_ID	0xffffffff
#define SUBSYSTEM_ID	0x6003

#define SUBSYSTEM_ID_OFFSET 	0xc

#if defined (AR9888)
#define MEM_SIZE (16 * 1024)
#elif defined (AR6320)
#define MEM_SIZE (32 * 1024)
#elif defined (AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888)
#define MEM_SIZE (16 * 1024)
#else 
#define MEM_SIZE (32 * 1024 * 2)
#endif //AR9888

A_old_intr_t old_intr;

extern EVENT_QUEUE isrEventQ;
extern EVENT_QUEUE triggerEventQ;
extern EVENT_QUEUE dsrQ;

// extern declarations
int mdk_interrupt(void *intParam);

// forward declarations
static void removeClient(A_UINT32 devIndex);

// global variables
KP_CLIENT kpClientTable[MAX_CLIENTS_SUPPORTED];
A_UCHAR memTable[MAX_CLIENTS_SUPPORTED][MEM_SIZE];
static A_INT32 mdk_intConnect
(
	KP_CLIENT *kpClient,
	A_UINT32 devIndex
)
{
	kpClient->irqLevel = 4;
	//A_INTR_DISABLE(&old_intr);
	//uiPrintf("mdk_intConnect:oi=%d\n", old_intr);
//        A_WMAC_INTR_ATTACH(mdk_interrupt, kpClient);
//        A_WMAC_INTR_UNMASK();
	//A_INTR_RESTORE(&old_intr);

	return 0;
}


static void mdk_intDisconnect
(
	KP_CLIENT *kpClient
)
{
	A_WMAC_INTR_DETACH();
    return;
}

static void initClient
(
	KP_CLIENT *kpClient
)
{
	kpClient->cliId = INVALID_CLIENT;
	kpClient->busy = 0;
	kpClient->regPhyAddr = 0;
	kpClient->regVirAddr = 0;
	kpClient->regRange = 0;
	kpClient->memPhyAddr = 0;
	kpClient->memVirAddr = 0;
	kpClient->memSize = 0;
	kpClient->irqLevel = 0;
	kpClient->isrEventQ = NULL;
	kpClient->triggeredQ = NULL;
	kpClient->dsrQ = NULL;
}

static A_INT32 initClientTable(void)
{
	A_UINT32 i;

	for (i=0;i<MAX_CLIENTS_SUPPORTED;i++) {
		kpClientTable[i].cliId = INVALID_CLIENT;
	}

	return 0;

}

static void cleanupClientTable(void)
{
	A_UINT32 i;


	for (i=0;i<MAX_CLIENTS_SUPPORTED;i++) {
		if (kpClientTable[i].cliId != INVALID_CLIENT) {
			removeClient(i);				
			kpClientTable[i].cliId = INVALID_CLIENT;	
		}
	}

}


static A_INT32 addClient
(
	A_UINT32 devIndex
)
{
	KP_CLIENT *kpClient;
	A_UINT32 *mem;

	kpClient = (KP_CLIENT *) &kpClientTable[devIndex];
	mem = (A_UINT32*) memTable[devIndex];

	if (VALID_CLIENT(kpClient)) {
		uiPrintf("can't add a client \n");
		return -1;
	}
	
	initClient(kpClient);
        kpClient->regPhyAddr = MAC_BASE_ADDRESS; 
	kpClient->regVirAddr = kpClient->regPhyAddr;
	kpClient->regRange = 65536;
	kpClient->memPhyAddr = (A_UINT32)mem;

	// devlib requires the memory to be cache aligned 
	kpClient->memPhyAddr = (kpClient->memPhyAddr + A_CACHE_LINE_SIZE - 1) 
					& (~(A_CACHE_LINE_SIZE - 1));
	// descriptor and frames requires uncached memory addresses
	kpClient->memPhyAddr = (A_UINT32) A_UNCACHED_ADDR(kpClient->memPhyAddr);
	kpClient->memVirAddr = kpClient->memPhyAddr;

/* For Venus, copied from wlan_buf.h ...
 * Convert between CPU and DMA addresses.  On AR6001 and
 * AR6002 REVs 1,2, and 3 software can use CPU addresses
 * in DMA descriptors and in registers that take DMA
 * addresses -- the hardware simply ignores the upper bits.
 * But on AR6002 REV4, the physical address space is larger
 * so this is no longer possible -- software must distinguish
 * between CPU and DMA addresses.
 */
#if defined(AR6002_REV4)
	kpClient->memPhyAddr &= 0x3FFFFF;  // Venus 
#endif

	kpClient->memSize = MEM_SIZE;

	kpClient->cliId = devIndex;

 	if (mdk_intConnect(kpClient,devIndex) < 0) {
  		uiPrintf("Unable to enable interrupt\n");
	      	return -1;
 	}


	return 0;
}

static void removeClient
(
	A_UINT32 devIndex
)
{
	KP_CLIENT *kpClient;

	kpClient = &kpClientTable[devIndex];
	if (!VALID_CLIENT(kpClient)) {
		uiPrintf("Cannot remove a client \n");
		return;
	}

	mdk_intDisconnect(kpClient);
	initClient(kpClient);
}

A_INT32 registerClient
(
	KP_CLIENT *kpClient
)
{
	if (!VALID_CLIENT(kpClient)) {
		uiPrintf("Cannot register a client \n");
		return -1; 
	}

	if (BUSY_CLIENT(kpClient)) {
		uiPrintf("Cannot register a busy client \n");
		return -1; 
	}

	kpClient->isrEventQ = &isrEventQ;
	kpClient->triggeredQ = &triggerEventQ;
	kpClient->dsrQ = &dsrQ;

	kpClient->busy = 1;

/*
A_PRINTF("busy=%d\n", kpClient->busy);
A_PRINTF("isrEventQ=%d\n", kpClient->isrEventQ);
A_PRINTF("triggeredQ=%d\n", kpClient->triggeredQ);
A_PRINTF("dsrQ=%d\n", kpClient->dsrQ);
*/

	initEventArray(&(kpClient->eventArray)); // Initaialize Event Array

	// enable interrupts
	hwInit(NULL, BUS_RESET|MAC_RESET|BB_RESET);
	return 0;
}

void unregisterClient
(
	KP_CLIENT *kpClient
)
{

	if (!BUSY_CLIENT(kpClient)) {
		uiPrintf("Cannot unregister a non-busy client \n");
		return; 
	}

	deleteEventQueue(kpClient->dsrQ,1);
	kpClient->dsrQ = NULL;

	deleteEventQueue(kpClient->triggeredQ,1);
	kpClient->triggeredQ = NULL;

	deleteEventQueue(kpClient->isrEventQ,1);
	kpClient->isrEventQ = NULL;

	kpClient->busy = 0;

	return;
}


A_INT32 kpInit(void)
{
	return initClientTable();
}

void kpExit(void)
{
	cleanupClientTable();
	return;
}

A_INT32 kpOpen
(
	A_UINT16 devIndex
)
{
	KP_CLIENT *kpClient;

	if (devIndex >= MAX_CLIENTS_SUPPORTED) {
		uiPrintf("Error: Not a valid client devIndex \n");
		return -1;
	}

	kpClient = &kpClientTable[devIndex];

	// Init client for the first time
	if (kpClient->cliId == INVALID_CLIENT) {
		if (addClient(devIndex) < 0) {
			uiPrintf("Error: cannot add client \n");
			return -1;
		}
	}

	if (registerClient(kpClient) < 0) {
		uiPrintf("Error: cannot register client \n");
		return -1;
	}

	return devIndex;
}


void kpClose
(
	A_UINT32 kpHandle
)
{
	KP_CLIENT *kpClient;

	kpClient = &kpClientTable[kpHandle];

	unregisterClient(kpClient);
	if (kpClientTable[kpHandle].cliId != INVALID_CLIENT) {
	    removeClient(kpHandle);				
	    kpClientTable[kpHandle].cliId = INVALID_CLIENT;	
    }
	return;
}

A_INT32 kpGetClientInfo
(
	A_UINT32 kpHandle,
	KP_CLIENT_INFO *kpClientInfo
)
{
	KP_CLIENT *kpClient;

	kpClient = &kpClientTable[kpHandle];
	if (!BUSY_CLIENT(kpClient)) {
		uiPrintf("Client not registered \n");
		return -1; 
	}
	
	kpClientInfo->regPhyAddr = kpClient->regPhyAddr;
	kpClientInfo->regVirAddr = kpClient->regVirAddr;
	kpClientInfo->regRange = kpClient->regRange;
	kpClientInfo->memPhyAddr = kpClient->memPhyAddr;
	kpClientInfo->memVirAddr = kpClient->memVirAddr;
	kpClientInfo->memSize = kpClient->memSize;
	kpClientInfo->irqLevel = kpClient->irqLevel;
	uiPrintf("kpGetClientInfo - memSize = 0x%x\n", kpClient->memSize);
	return 0;
}


A_INT16 kpCreateEvent
(
	A_UINT32 kpHandle,
    	A_UINT32 type, 
    	A_UINT32 persistent, 
    	A_UINT32 param1,
    	A_UINT32 param2,
    	A_UINT32 param3,
    	EVT_HANDLE eventHandle
)
{
    	EVENT_STRUCT  *pEvent;
	KP_CLIENT *kpClient;

	kpClient = &kpClientTable[kpHandle];
	if (!BUSY_CLIENT(kpClient)) {
		uiPrintf("Error: Client not registered \n");
		return -1; 
	}

   	 /* create the event structure and add to event queue */        
    	pEvent = createEvent(type, persistent, param1, param2, param3, eventHandle,&kpClient->eventArray,1);
    	if ( !pEvent ) {
        	uiPrintf("Error: Unable to create event, createEvent() failed!\n");
        	return(-1);
    	}

    	/* need to look at the event type to see which queue to add to */
    	switch ( type ) {
    		case ISR_INTERRUPT:
        	// if param1 is zero, we, by default, set the "ISR IMR" to pass everything
		uiPrintf("Isr event created \n");

        	if (0 == pEvent->param1 )
            		pEvent->param1 = 0xffffffff;

        	if (!pushEvent(pEvent, kpClient->isrEventQ,1) ) {
            		uiPrintf("Error: Unable to create event, pushEvent() failed!\n");
			freeEvent(pEvent,1); 	
  			return(-1);
        	}
    	}

    	return(0);
}

void kpGetNextEvent	
(
	A_UINT32 kpHandle,
	EVENT_STRUCT *pEvent
)
{
	EVENT_STRUCT *event;
	KP_CLIENT *kpClient;

	kpClient = &kpClientTable[kpHandle];
	if (!BUSY_CLIENT(kpClient)) {
		uiPrintf("Error: Client not registered \n");
		return; 
	}

	pEvent->type = 0;
	if (kpClient->triggeredQ->queueSize) {
                //A_PRINTF(".trgQ %d\n", kpClient->triggeredQ->queueSize);
		if(checkForEvents(kpClient->triggeredQ,1)) {
			event = popEvent(kpClient->triggeredQ,1);
			A_MEMCPY((void *)pEvent,(void *)event,sizeof(EVENT_STRUCT));
			freeEvent(event,1);
		}
	}

	return;
}

/**************************************************************************
*
* The config reads returns the expected value for some of the address, since
* the chip doesnt have a PCI configuration space. A default value is 
* returned for other addresses.
*
***************************************************************************/

A_INT32 kpCfgRead
(
 	A_UINT32 kpHandle,
    	A_UINT32 address,                    /* the address to read from */
	A_UINT32 size,
	A_UINT32 *data
)
{
    KP_CLIENT *kpClient;
    A_UINT32 value;
    A_UINT32 regVal;
    A_UINT32 majorVer;
    A_UINT32 minorVer;
    A_UINT32 device_vendor_id;
    A_UINT32 subsystem_vendor_id;
                

    kpClient = &kpClientTable[kpHandle];
    if (!BUSY_CLIENT(kpClient)) {
        uiPrintf("Error: Client not registered \n");
        return -1; 
    }

    // check for chip revision number
    //regVal = SOC_CHIP_ID_VERSION_GET(A_RTC_SOC_REG_READ(CHIP_ID_ADDRESS));
    regVal = SOC_CHIP_ID_VERSION_GET(A_RTC_SOC_REG_READ(SOC_CHIP_ID_ADDRESS));

    minorVer = ((regVal & REV_MIN_M) >> REV_MIN_S);
    majorVer = ((regVal & REV_MAJ_M) >> REV_MAJ_S);
    device_vendor_id = UNKNOWN_DEVICE_VENDOR_ID;
    //uiPrintf("getting subsystem id \n");
    //subsystem_vendor_id = sysFlashRead(SUBSYSTEM_ID_OFFSET);
    subsystem_vendor_id = SUBSYSTEM_ID;
    //uiPrintf("subsystem id=%x\n", subsystem_vendor_id);
                
    switch(majorVer) {
        case AR6000_EMULATION_MAJOR_REV0:
	    device_vendor_id = AR6000_EMULATION_DEVICE_VENDOR_ID;
	    break;
        case AR6000_MAJOR_REV0:
	    {
	    switch(minorVer) {
                 case AR6000_MINOR_REV0:
		     device_vendor_id = AR6000_DEVICE_VENDOR_ID;
		     break;
		 }
            }
		   break;
    }
    //A_PRINTF("Rev:%x:%x/%x:dvid=%x\n", regVal, majorVer, minorVer, device_vendor_id);

    if(address > MAX_CFG_OFFSET) {
        uiPrintf("Error:  cfgRead not a valid config offset\n");
        value = 0xdeadbeef;
    }
    else {
        switch (address & 0xfffffffc)
        {
	    case 0:
	        value = device_vendor_id;
	        break;
	    case 16:
	        value = kpClient->regPhyAddr;
	        break;
	    case 44:
	        value = subsystem_vendor_id;
	        break;
			case 60:
				value = kpClient->irqLevel;
				break;
			default:
				value = 0;
				break;
		}
		value = value >> (address & 3);
	}

	switch (size) 
	{
		case 8:
			value = value & 0x000000ff;
			break;
		case 16:
			value = value & 0x0000ffff;
			break;
		case 32:
			break;
	}
	*data = value;

    	return (0);
}

/**************************************************************************
* Configuration writes returns since FREEDOM doesnt have the PCI
* config space.
**************************************************************************/


void kpCfgWrite
(
	A_UINT32 kpHandle,	
	A_UINT32 address,                    /* the address to write */
	A_UINT32 size,
	A_UINT32 data                        /* value to write */
	
)
{
/*
	KP_CLIENT *kpClient;

	kpClient = &kpClientTable[kpHandle];
	if (!BUSY_CLIENT(kpClient)) {
		uiPrintf("Error: Client not registered \n");
		return; 
	}

	if(address > MAX_CFG_OFFSET) {
		uiPrintf("Error:  cfgWrite not a valid config offset\n");
	}
*/
	
	return;
}





