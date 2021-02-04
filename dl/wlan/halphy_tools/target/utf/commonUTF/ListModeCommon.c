/* <<ListModeCommon.c>>
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
/* This is common APIs for List Mode processing*/
#include "ListModeCommon.h"
LMHWCALNUM hwCalNum;

LMHWCALLIST *pLMHead = NULL, *g_currentLM = NULL;
A_TIMER lm_common_complete_timer;

//SRAM_TEXT
void freeLMHWCalList(void)
{
    LMHWCALLIST *next, *current =  pLMHead;
    if (current == 0) return;
    while (current) {
        next = current->next;
        A_FREE(current);
        current = NULL;
        current = next;
    }
    pLMHead = NULL;
}

//SRAM_TEXT
A_UINT8 pushNodeToCalList(LMHWCALLIST ** head, A_UINT16 freq,  A_UINT16 freq2, A_UINT16 chainMask, A_UINT16 wlanMode, A_UINT16 phyId)
{
    LMHWCALLIST *current = *head;
    A_BOOL hasDuplicate = FALSE;

   // if (wlanMode <= TCMD_WLAN_MODE_VHT20) wlanMode = TCMD_WLAN_MODE_NOHT;

    while (current != NULL)
    {
        if (current->freq == freq && current->freq2 == freq2 && current->chainMask == chainMask && current->wlanMode == wlanMode && current->phyId == phyId)
        {
            hasDuplicate = TRUE;
            break;
        }
       current = current->next;
    }

    if (hasDuplicate) return 0;

    LMHWCALLIST * newNode = (LMHWCALLIST *)A_ALLOCRAM(sizeof(LMHWCALLIST));
    /* now we can add a new variable */
    newNode = A_ALLOCRAM(sizeof(LMHWCALLIST));
    newNode->freq = freq;
    newNode->freq2 = freq2;
    newNode->chainMask = chainMask;
    newNode->wlanMode = wlanMode;
    newNode->phyId = phyId;
    newNode->next = *head;
    *head = newNode;

    return 1;
}

/* Function to reverse the linked list */
void reverseCalList(LMHWCALLIST ** head)
{
    LMHWCALLIST* prev   = NULL;
    LMHWCALLIST* current = *head;
    LMHWCALLIST* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

//SRAM_TEXT
 A_UINT32 createLMHWCalListFromFreqMaskModePhyId(A_UINT16 freq,  A_UINT16 freq2, A_UINT16 chainMask, A_UINT16 wlanMode, A_UINT16 phyId)
{
    A_UINT32 ret = 0;

    if (freq == 65535 || freq == 0) return ret;

    if  (( wlanMode >= TCMD_WLAN_MODE_VHT80P80 && ( chainMask == 5 || chainMask == 6 || chainMask == 9 || chainMask == 10 || chainMask == 15)) ||
          (wlanMode < TCMD_WLAN_MODE_VHT80P80))
    {
        ret = pushNodeToCalList(&pLMHead, freq,  freq2,  chainMask, wlanMode, phyId);
    }
   // A_PRINTF_ONCE("ret = %d singleChainNum=%d, fullChainNum=%d\n", ret, hwCalNum.singleChainNum, hwCalNum.fullChainNum);

    if (ret == 1) {
        if (chainMask == 0x1 || chainMask == 0x2 || chainMask == 0x4 || chainMask == 0x8)
                hwCalNum.singleChainNum += 1;
        else
            hwCalNum.fullChainNum += 1;
    }

    return ret;
}

SRAM_TEXT
void printHWCALList(void)
{
    LMHWCALLIST *current = pLMHead;
    while (current != NULL)
    {
        A_PRINTF_ONCE("HWCALLIST -- Freq: %d,chainMask:%d, wlanMode:%d\n",
        current->freq,
        current->chainMask, current->wlanMode);
        current = current->next;
    }

}

