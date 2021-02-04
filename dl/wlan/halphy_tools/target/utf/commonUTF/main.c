/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 * $Id: //depot/sw/branches/qca_main_wifi2.0/perf_pwr_offload/drivers/target/apps/utf/commonUTF/main.c#2 $
 *
 * Copyright (c) 2000-2003 Atheros Communications, Inc., All Rights Reserved
 * $ATH_LICENSE_TARGET_C$
 */
#include "osapi.h"

//extern void utf_init(int arg0);
//extern void tcmd_main(void);
extern void utf_main(void);


void app_start(void)
{
   int wdt;

    if (!A_INIT()) {
        A_PRINTF("A_INIT() FAILED.\n");
        //return;
    }

    A_WDT_DISABLE(&wdt);
    utf_main(); 

#if ((defined(AR900B)  && (TARGET_VER == 1)) || defined(QCA9888)) && !defined(FPGA)
    extern void install_patches_post_init(void);
    install_patches_post_init();    //tcmd_main();
#endif

}

