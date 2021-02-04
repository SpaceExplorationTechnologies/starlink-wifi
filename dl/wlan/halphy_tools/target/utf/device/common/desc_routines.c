/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// Copyright (c) 2010 Atheros Communications Inc.
// All rights reserved.
// $ATH_LICENSE_TARGET_C$

#include "osapi.h"
#include "wlantype.h"
#include "hwext.h"



void createDescriptors(A_UINT32 devNumIndex, A_UINT32 descBaseAddress,  A_UINT32 descInfo, A_UINT32 bufAddrIncrement, A_UINT32 descOp, A_UINT32 *descWords) {
	A_UINT32 i, nextDescAddress, descAddress, bufAddr, nextBufAddr, tempVal;
    A_UINT32 lastDesc, descSize;
	A_UINT32 numDesc, numDescWords;
	A_UINT16 wordOffset, nDescOffset, intrBitOffset;
	A_BOOL   doDescOp;
	A_UCHAR frameBytes[ sizeof(MDK_PACKET_HEADER) + sizeof(WLAN_DATA_MAC_HEADER3)];
	A_BOOL  clearBuf;

	descAddress = descBaseAddress;
	nextDescAddress = descBaseAddress;

	numDesc = (descInfo & DESC_INFO_NUM_DESC_MASK)>>DESC_INFO_NUM_DESC_BIT_START;
	numDescWords = (descInfo & DESC_INFO_NUM_DESC_WORDS_MASK) >> DESC_INFO_NUM_DESC_WORDS_BIT_START;
    lastDesc = (descInfo & DESC_INFO_LAST_DESC_MASK)>> DESC_INFO_LAST_DESC_BIT_START;
	intrBitOffset = (descOp & DESC_OP_INTR_BIT_MASK) >> DESC_OP_INTR_BIT_START;
	wordOffset = (descOp & DESC_OP_WORD_OFFSET_BIT_MASK) >> DESC_OP_WORD_OFFSET_BIT_START;
	nDescOffset = (descOp & DESC_OP_NDESC_OFFSET_BIT_MASK) >> DESC_OP_NDESC_OFFSET_BIT_START;
	doDescOp = (wordOffset < numDescWords)?1:0;

	descSize = numDescWords * sizeof(A_UINT32);
	tempVal = bufAddrIncrement;
	clearBuf = (tempVal & BUF_ADDR_INC_CLEAR_BUF_BIT_MASK) >> BUF_ADDR_INC_CLEAR_BUF_BIT_START;
	bufAddrIncrement = (tempVal & ~BUF_ADDR_INC_CLEAR_BUF_BIT_MASK);


#ifdef DEBUG_MEMORY
uiPrintf("devNumIndex=%d\n", devNumIndex);
#endif

	bufAddr = descWords[1];
	nextBufAddr = bufAddr;

	if (clearBuf) {
	   for(i=0;i<( sizeof(MDK_PACKET_HEADER) + sizeof(WLAN_DATA_MAC_HEADER3) ) ; i++) {
		   frameBytes[i] = 0;
	   }
	   hwMemWriteBlock(devNumIndex, frameBytes,  (sizeof(MDK_PACKET_HEADER) + sizeof(WLAN_DATA_MAC_HEADER3)), &nextBufAddr);
	}

 	for(i=0;i<numDesc;i++) {

	  nextDescAddress = descBaseAddress + ((i+1) * descSize);
	  descWords[0] = nextDescAddress;
	  descWords[1] = nextBufAddr;

#ifdef DEBUG_MEMORY
uiPrintf("\ndI=%d:ND=%d:dba=%x:ndw=%d:da=%x:nda=%x:i=%d:lD=%d\n", devNumIndex, numDesc, descBaseAddress, numDescWords, descAddress, nextDescAddress, i, lastDesc);
#endif
//diag_printf("\ndI=%d:ND=%d:dba=%x:ndw=%d:da=%x:nda=%x:i=%d:lD=%d:wO=%d:dDO=%d:nDO=%d\n", devNumIndex, numDesc, descBaseAddress, numDescWords, descAddress, nextDescAddress, i, lastDesc, wordOffset, doDescOp, nDescOffset);
	  if (doDescOp && (i == nDescOffset)) {
		descWords[wordOffset] |= (1<<intrBitOffset);
//diag_printf("sI=%d:%X\n", wordOffset, descWords[wordOffset]);
	  }
	  else {
		descWords[wordOffset] &= ~(1<<intrBitOffset);
	  }

	  if (i == (numDesc-1)) {
	    switch(lastDesc) {
		  case LAST_DESC_NULL:
	     			descWords[0] = 0;
					break;
		  case LAST_DESC_NEXT:
	     			descWords[0] = nextDescAddress;
					break;
		  case LAST_DESC_LOOP:
	     			descWords[0] = descAddress;
					break;
	    }
	  }

#ifdef DEBUG_MEMORY
	{
	A_UINT32 iIndex, *dPtr,
	dPtr = (A_UINT32 *)descWords;
	iIndex=0;
   uiPrintf("word=", iIndex, dPtr[iIndex]);
for(iIndex=0;iIndex<numDescWords;iIndex++) {
   //diag_printf("word[%d]=%x\n", iIndex, dPtr[iIndex]);
   uiPrintf("%x:", dPtr[iIndex]);
}
uiPrintf("\n");
	}
#endif

	  hwMemWriteBlock(devNumIndex, (A_UCHAR *)descWords, numDescWords*sizeof(A_UINT32), &descAddress);
	  if (clearBuf && bufAddrIncrement) {
			hwMemWriteBlock(devNumIndex, frameBytes,  (sizeof(MDK_PACKET_HEADER) + sizeof(WLAN_DATA_MAC_HEADER3)), &nextBufAddr);
	  }
	  descAddress = nextDescAddress;
	  nextBufAddr = nextBufAddr + bufAddrIncrement;

	}


}

