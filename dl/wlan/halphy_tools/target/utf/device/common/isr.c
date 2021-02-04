/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/* isr.c - contians the ISR routine  */

/*
 * Copyright (c) 2000 Atheros Communications, Inc., All Rights Reserved
 * $ATH_LICENSE_TARGET_C$
 */

#include "osapi.h"
#include "dk_common.h"
#include "dkkernel.h"
#include "ar6000defs.h"
#include "flash_ops.h"

/*
 * mdk_interrupt - interrupt handler
 *
 * Read the interrupt status register and save it
 * Used by the ISR_INTERRUPT event.
 */

int mdk_interrupt
(
	void *intrParam
)
{
	KP_CLIENT *kpClient;
	A_UINT32 	regValue;
	A_UINT32	secISR[5];
    EVENT_STRUCT    *pEventCopy;
    EVENT_STRUCT    *pEventToPush = NULL;
    A_BOOL          bValidEvent;
	EVENT_QUEUE	*pIsrEventQ;
	EVENT_QUEUE	*pTriggeredQ;
	EVENT_STRUCT    *pEvent, *pDsrEvent;
	EVENT_QUEUE	*pDsrQ;
	A_UINT32 i;
    A_old_intr_t old_intr;

	A_INTR_DISABLE(&old_intr);


	kpClient = (KP_CLIENT *)intrParam;

	regValue = A_WMAC_REG_READ(F2_ISR_RAC);

        A_WMAC_REG_WRITE(F2_ISR, regValue);

	secISR[0] = A_WMAC_REG_READ(F2_ISR_S0_S);
	secISR[1] = A_WMAC_REG_READ(F2_ISR_S1_S);
	secISR[2] = A_WMAC_REG_READ(F2_ISR_S2_S);
	secISR[3] = A_WMAC_REG_READ(F2_ISR_S3_S);
	secISR[4] = A_WMAC_REG_READ(F2_ISR_S4_S);
    
	pDsrQ = kpClient->dsrQ;
	if (!BUSY_CLIENT(kpClient) && (pDsrQ != NULL)) {
	}
	else {
	   pEvent = getEvent(&kpClient->eventArray, 0);
	   if (pEvent)
	   {
           pEvent->result = regValue;
           for (i=0;i<5;i++) {
        	   pEvent->additionalParams[i] = secISR[i];
           }
           pEvent->free = 0;
           pushEvent(pEvent, pDsrQ, 0);
	   }
	}


	kpClient = (KP_CLIENT *)intrParam;
	pIsrEventQ = kpClient->isrEventQ;
	pTriggeredQ =	kpClient->triggeredQ;
	pDsrQ = kpClient->dsrQ;
	
    // start to scan the current queue of events
    pEvent = startQueueScan(pIsrEventQ,0);
    pDsrEvent = popEvent(pDsrQ,1);

    while ( pDsrEvent) {
    while ( pEvent ) {
		bValidEvent = FALSE;

        	switch ( pEvent->type ) {
        		case ISR_INTERRUPT:
           			if ( pDsrEvent->result & pEvent->param1 ) {
                			// return the complete ISR value (not anded with the mask)
                			pEvent->result = pDsrEvent->result;
					for (i=0;i<5;i++) {
						pEvent->additionalParams[i] = pDsrEvent->additionalParams[i];
					}
					bValidEvent    = TRUE;
            		}
            		break;
        		default:
           			uiPrintf("KernelPlugIn :: Illegal event type found in ISR event queue!\n");
            			break;
        	} // switch
        
        	if ( !bValidEvent ) {
            		pEvent = pEvent->pNext;
            		continue;
        	}

        	// put the event in the event triggered Q, either move or copy event, depending 
        	// on the persistent flag 
        	if ( pEvent->persistent ) {
            		pEventCopy = copyEvent(pEvent,&kpClient->eventArray,0);
            		if( !pEventCopy ) {
                		uiPrintf("Error: Unable to copy event in mdk_interrupt()!\n");
                                break;
            		}
            		pEventToPush = pEventCopy;
        	}
        	else {
            		if (!removeEvent(pEvent, pIsrEventQ, FALSE) ) {
                		uiPrintf("Error: Unable to remove event from ISR queue!\n");
                                break;
            		}
            		pEventToPush = pEvent;
        	}

        	// push the event onto the triggered queue
        	if (!pushEvent(pEventToPush, pTriggeredQ,0) ) {
            		uiPrintf("Error: Unable to push event onto triggered queue!\n");
                        break;
        	}
 	       
		// increment to next event 
        	pEvent = pEvent->pNext;
    	} // while ( pEvent )
	freeEvent(pDsrEvent, 1);
    pDsrEvent = popEvent(pDsrQ,1);
	A_INTR_RESTORE(&old_intr);
	} // while (pDsrEvent)

    	// stop scanning the queue
   if ( !stopQueueScan(pIsrEventQ,0) ) {
       	 	uiPrintf("Error: stopQueueScan() had problems!\n");
   }
  return 1;
}

