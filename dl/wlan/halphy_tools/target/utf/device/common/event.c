/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/* event.c - functions for event handling */

/*
 * Copyright (c) 2000 Atheros Communications, Inc., All Rights Reserved
 * $ATH_LICENSE_TARGET_C$
 */

#ident  "ACI $Id: //depot/sw/branches/qca_main_wifi2.0/perf_pwr_offload/drivers/target/apps/utf/AR6004/event.c#2 $, $Header: //depot/sw/branches/qca_main_wifi2.0/perf_pwr_offload/drivers/target/apps/utf/AR6004/event.c#2 $"

#ifndef AR6K
static  char *rcsid =  "ACI $Id: //depot/sw/branches/qca_main_wifi2.0/perf_pwr_offload/drivers/target/apps/utf/AR6004/event.c#2 $, $Header: //depot/sw/branches/qca_main_wifi2.0/perf_pwr_offload/drivers/target/apps/utf/AR6004/event.c#2 $";
#endif

/* 
modification history
--------------------
00a    05oct00    fjc    Created.
*/

/*
DESCRIPTION
Contains low level functions for event handling.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#ifdef KERPLUG
#include <ntddk.h>
#endif
#include "osapi.h"
#include "dk_common.h"
#include "event.h"
#include "lock.h"

#define printMsg A_PRINTF

#ifndef MALLOC_ABSENT
/**************************************************************************
* initEventQueue - Create and initialize an event queue
*
* This routine will allocate space for an empty event queue structure
* and perform initialization
*
* RETURNS: pointer to eventQueue if created, null otherwise
*/
EVENT_QUEUE *initEventQueue
    (
    void
    )
    {
    EVENT_QUEUE        *pQueue;
    
    /* allocate space for the eventQ struct */
    pQueue = (EVENT_QUEUE *)malloc(sizeof(EVENT_QUEUE));

    if(!pQueue)
        {
        printMsg("Error: Unable to allocate space for EVENT_QUEUE\n");
        return(NULL);
        }

    /* initialize the other members */
    pQueue->pHead = pQueue->pTail = NULL;
    pQueue->queueSize = 0;
    pQueue->queueScan = FALSE;

    return(pQueue);
    }

#else

/**************************************************************************
* initEventQueue - Create and initialize an event queue
*  /// Donot use MALLOC, but initialize the event queue passed as arg
* This routine will allocate space for an empty event queue structure
* and perform initialization
*
* RETURNS: pointer to eventQueue if created, null otherwise
*/
void initEventQueue
    (
    EVENT_QUEUE        *pQueue
    )
    {
    
    /* initialize the other members */
    pQueue->pHead = pQueue->pTail = NULL;
    pQueue->queueSize = 0;
    pQueue->queueScan = FALSE;
    }

#endif

/**************************************************************************
* deleteEventQueue - delete and cleanup a created event queue
*
* This routine will remove and delete all the event structures in the 
* queue then delete the eventQ structure.  Performs any other cleanup
* needed
*
* RETURNS: N/A
*/
void deleteEventQueue
    (
    EVENT_QUEUE *pQueue , /* pointer to the queue to delete */
    A_BOOL        protect   
    )
{
    EVENT_STRUCT *pNextEvent;
    
    if(!pQueue)
        return;
    
    /* cleanup the events in the queue */
    while (pQueue->pHead) {
        pNextEvent = pQueue->pHead->pNext;

	freeEvent(pQueue->pHead,protect);
	
        pQueue->queueSize--;
        pQueue->pHead = pNextEvent;
    }

#ifndef MALLOC_ABSENT
	/* free the memory held by the queue struct */
    A_FREE(pQueue);
#else
#endif

    return;
}



/****************************************************************
* initEventArray - Intiialize Event Array   
* Input          - eventArray , which is Initialized 
*/

void initEventArray(EVENT_ARRAY * eventArray)
{	
	int index;	
	for(index=0;index<EVENT_ARRAY_SIZE;index++)
	{
	 	eventArray->eventElement[index].free=1;
		eventArray->eventElement[index].eventArrayPtr=eventArray;
	}
}


/****************************************************************
* getEvent - Allocate an event from Input eventArray   
* Input    - eventArray , which is used , to allocate event
* Return   - if  (Free)  event reference
*            else        NULL;      
*/


EVENT_STRUCT *getEvent(EVENT_ARRAY * eventArray,A_BOOL protect)
{
	int index=0;

	while ((index <EVENT_ARRAY_SIZE ) && (eventArray->eventElement[index].free==0)) 
		index ++;

	if (index < EVENT_ARRAY_SIZE)
	{
	       eventArray->eventElement[index].free=0;
	        return  &eventArray->eventElement[index];
	}
	else
	{
	    uiPrintf("\n ERROR:: Static Allocation is not Enough, idx %d:size %d \n", index, EVENT_ARRAY_SIZE);		 	   
	}
	
	return NULL;	
}

/****************************************************************
* freeEvent - Free the input event    
* Input    - event , which has to be freed 
*/

void freeEvent(EVENT_STRUCT * event,A_BOOL protect) {
	
	if (event!=NULL) {
	   event->free=1;
	}
	
}



/**************************************************************************
* createEvent - Create an event
*
* This routine will allocate memory for an event and perform any 
* initialization.  Note that this does not add the event to any Q
*
* RETURNS: pointer to the event of NULL if error
*/
EVENT_STRUCT *createEvent
(
    	A_UINT32 type,          /* the event ID */
    	A_UINT32 persistent,    /* set if want a persistent event */
    	A_UINT32 param1,        /* optional args */
    	A_UINT32 param2,
    	A_UINT32 param3,
    	EVT_HANDLE eventHandle,  /* unique handle of event */
	EVENT_ARRAY *eventArray,
	A_BOOL        protect   
)
{
    	EVENT_STRUCT *pEvent;    /* pointer to event struct created */

	pEvent = (EVENT_STRUCT *)getEvent(eventArray,protect); // Allocate Event from eventArray

    	if(!pEvent)
        {
        	printMsg("Error: Unable to allocate memory in createEvent()!\n");
		return(NULL);
        }

    	/* perform initialization of members */
    	pEvent->type = type;
    	pEvent->persistent = persistent;
    	pEvent->param1 = param1;
    	pEvent->param2 = param2;
    	pEvent->param3 = param3;
    	pEvent->pNext = NULL;
    	pEvent->pLast = NULL;
    	pEvent->result = 0;

#ifdef MAUI
	{	
	A_UINT32 i;

		for (i=0;i<5;i++) {
			pEvent->additionalParams[i]=0;
		}
	}
#endif
    	pEvent->eventHandle = eventHandle;


    	return(pEvent);
}

/**************************************************************************
* copyEvent - Copy an event struct
*
* This routine will allocate memory for a new event and copy member 
* variables from existing event into new event
*
* RETURNS: pointer to the event of NULL if error
*/
EVENT_STRUCT *copyEvent
(
    	EVENT_STRUCT    *pExistingEvent,      /* pointer to event to copy */
	EVENT_ARRAY *eventArray ,
	A_BOOL        protect  
)
{
    	EVENT_STRUCT *pNewEvent;    /* pointer to event struct created */

    	if(!pExistingEvent)
        {
        	printMsg("Error: Illegal pointer passed to copyEvent!\n");
        	return(NULL);
        }
    	
	pNewEvent = (EVENT_STRUCT *)getEvent(eventArray,protect); // Allocate Event from eventArray
	
    	if(!pNewEvent)
        {
        	printMsg("Error: Unable to allocate memory for new event!\n"); 	
       	 	return(NULL);
        }

    	pNewEvent->type = pExistingEvent->type;
    	pNewEvent->persistent = pExistingEvent->persistent;
    	pNewEvent->param1 = pExistingEvent->param1;
    	pNewEvent->param2 = pExistingEvent->param2;
    	pNewEvent->param3 = pExistingEvent->param3;
    	pNewEvent->pNext = NULL;
    	pNewEvent->pLast = NULL;
    	pNewEvent->result = pExistingEvent->result;
#ifdef MAUI
	{	
	A_UINT32 i;

		for (i=0;i<5;i++) {
			pNewEvent->additionalParams[i]=pExistingEvent->additionalParams[i];
		}
	}
#endif
    	pNewEvent->eventHandle.eventID = pExistingEvent->eventHandle.eventID;
    	pNewEvent->eventHandle.f2Handle = pExistingEvent->eventHandle.f2Handle;
	
    	return(pNewEvent);
}

/**************************************************************************
* pushEvent - Put event at tail of eventQueue
*
* This routine will put the supplied event at the end of the specified Q.
* don't want any other threads accessing the Q while doing this, so need
* to obtain the Q mutex to be able to perform this operation
*
* RETURNS: 1 if successful, 0 if not
*/
A_UINT16 pushEvent
    (
    EVENT_STRUCT *pEvent,   /* pointer to event to add */
    EVENT_QUEUE  *pQueue ,   /* pointer to queue to add to */
    A_BOOL        protect  
    )
    {
    if(!pQueue || !pEvent)    
        {
        printMsg("Error: illegal pointer passed to pushEvent()!\n");
        return(0);
        }

    /* add the event to the tail */
    if(NULL == pQueue->pHead)
        {
        /* queue is empty, this will be the first item */
        pQueue->pHead = pEvent;
        pQueue->pTail = pEvent;    
        }
    else
        {
        pQueue->pTail->pNext = pEvent;
        pEvent->pLast = pQueue->pTail;
        pQueue->pTail = pEvent;
        }
        pQueue->queueSize++;

    return(1);
    }

/**************************************************************************
* popEvent - Pop an event from eventQueue head
*
* This routine will pop an event from the head of the specified Q.
* Don't want any other threads accessing the Q while doing this, so need
* to obtain the Q mutex to be able to perform this operation.
*
* RETURNS: pointer to event that was poped, null if fail
*/
EVENT_STRUCT *popEvent
    (
    EVENT_QUEUE  *pQueue ,       /* pointer to queue to add to */
    A_BOOL        protect  
    )
    {
    EVENT_STRUCT *pEvent;        /* event that will be poped from queue */
    
    A_ASSERT(pQueue);
	
    /* get the event from head and update pointers */
    pEvent = pQueue->pHead;
    if (pEvent)
        {
        /* ie the queue is not empty */
        pQueue->pHead = pEvent->pNext;    /* update head to point to next event */
        pEvent->pNext = NULL;            /* event no longer linked */

        if(!pQueue->pHead)
            {
            /* queue is now empty to make tail also null */
            pQueue->pTail = NULL;
            }
        else
            {
            pQueue->pHead->pLast = NULL;    /* head has no previous link */
            }
        pQueue->queueSize--;
        }
    return(pEvent);
    }


/**************************************************************************
* removeEvent - remove an event from eventQueue (anywhere)
*
* This routine will remove an event from anywhere (ie middle) in Q.
* The event to be removed is passed in.
* Don't want any other threads accessing the Q while doing this, so need
* to obtain the Q mutex to be able to perform this operation.
*
* RETURNS: 1 if removed, 0 if not
*/
A_UINT16 removeEvent
    (
    EVENT_STRUCT *pEvent,        /* event that will be removed from queue */
    EVENT_QUEUE  *pQueue,        /* pointer to queue to add to */
    A_BOOL        protect        /* set to true if should get mutex to protect queue
                                   access.  This can get called from middle of queue
                                   scanning, when we already have protection and don't
                                   need it again */
    )
    {
    
    if(!pQueue || !pEvent)    
        {
        printMsg("Error: illegal pointer passed to removeEvent()\n");
        return(0);
        }

    // first take care of previous member's forward link
    if ( pEvent->pLast )
        // this is not the head
        pEvent->pLast->pNext = pEvent->pNext;
    else
        // this is the head
        pQueue->pHead = pEvent->pNext;

    // next take care of next member's backward link
    if ( pEvent->pNext )
        // this is not the tail
        pEvent->pNext->pLast = pEvent->pLast;
    else
        // this is the tail
        pQueue->pTail = pEvent->pLast;

    /* clear event to be no longer linked */
    pEvent->pLast = NULL;
    pEvent->pNext = NULL;

    pQueue->queueSize--;

    return(1);
    }

/**************************************************************************
* startQueueScan - Allow caller to be able to scan the event queue
*
* This routine will obtain the mutex, so that the caller can safely scan
* the event queue. Note that this function does not release the mutex,
* called must call stopQueueScan to release.  A reminder message is 
* printed for debug purposes
*
* RETURNS: Return pointer to queue head if able to scan, null otherwise
*/
EVENT_STRUCT *startQueueScan
    (
    EVENT_QUEUE *pQueue,    /* Pointer to event queue to start scan */
    A_BOOL        protect  
    )
    {
    if(!pQueue)    
        {
        printMsg("Error: illegal pointer passed to startQueueScan()!\n");
        return(NULL);
        }
	
    		pQueue->queueScan = TRUE;
	
    return(pQueue->pHead);
    }

/**************************************************************************
* stopQueueScan - Stops a previously started Q scan
*
* This routine will release the mutex previously held by startQueueScan.
*
* RETURNS: Return 1 if successful, 0 if error
*/
A_UINT16 stopQueueScan
    (
    EVENT_QUEUE *pQueue,    /* Pointer to event queue to start scan */
    A_BOOL        protect  
    )
    {
    if(!pQueue)    
        {
        printMsg("Error: illegal pointer passed to stopQueueScan()!\n");
        return(0);
        }

    /* only release the mutex if we currently hold it, ie are in scan mode */
    if(pQueue->queueScan)
        {
        }
    else
        {
        printMsg("Mutex was not released, since not currently in scan mode\n");
        return(0);
        }

    pQueue->queueScan = FALSE;
    return(1);
    }

/**************************************************************************
* CheckForEvents - Check if queue has any events
*
* This routine will check to see if an event queue has any events in it.
* Need this to be a mutually exclusive operation so need to get mutex
*
* RETURNS: Return 1 if events, 0 if not or there are errors
*/
A_UINT16 checkForEvents
    (
    EVENT_QUEUE *pQueue ,    /* Pointer to event queue to start scan */
    A_BOOL        protect  
    )
    {
    A_UINT16    returnValue;

    if(!pQueue)    
        {
        printMsg("Error: illegal pointer passed to checkForEvents()\n");
        return(0);
        }

    if(!pQueue->pHead)
        {
        /* queue is empty, there are no events */
        returnValue = 0;
        }
    else
        {
        /* queue contains events */
        returnValue = 1;
        }

    return(returnValue);
    }
