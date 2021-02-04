/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/* boardData.h - header file of functions related to board data*/

/* $Id:$ */

/*
DESCRIPTION
Contains functions related to board data.
*/

#ifndef _BOARD_DATA_H_
#define  _BOARD_DATA_H_

extern void utfRecalBoardDataChecksum();
extern A_UINT8 *utfGetBoardDataPtr();
extern A_UINT16 utfGetBoardDataSize();
extern void utfSetMacAddr(A_UINT8 *macAddr);
extern void utfGetMacAddr(A_UINT8 *macAddr);
extern void utfSetMcnNum(A_UINT8 *mcnNum);
extern void utfGetMcnNum(A_UINT8 *mcnNum);


#endif //_BOARD_DATA_H_
