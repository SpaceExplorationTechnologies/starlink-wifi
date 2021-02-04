/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 * $Id: //depot/sw/branches/qca_main_wifi2.0/perf_pwr_offload/drivers/target/apps/utf/AR6004/main.c#2 $
 *
 * Copyright (c) 2000-2003 Atheros Communications, Inc., All Rights Reserved
 * $ATH_LICENSE_TARGET_C$
 */
#include "osapi.h"
#include <stdio.h>
#include "dk_common.h"

#if 0
// Globals, as ar6000 does not support malloc 
PIPE_CMD gPipeBuffer;
CMD_REPLY gReplyCmd;
OS_SOCK_INFO osSock;
#endif
EVENT_QUEUE isrEventQ;
EVENT_QUEUE triggerEventQ;
EVENT_QUEUE dsrQ;

#if 0
extern void mdk_init(int arg0);


void app_start(void)
{
   int wdt;

    if (!A_INIT()) {
        A_PRINTF("A_INIT() FAILED.\n");
        //return;
    }

	A_WDT_DISABLE(&wdt);
	mdk_init(0);	// 1 - enable debug	0 - disable debug

}



void mdk_init(int arg0)
{
   mdk_main(arg0, 0);
}
#endif

