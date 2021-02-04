#include <stdio.h>
#include "osapi.h"
#include "wlantype.h"
#include "utf.h"

extern void wmiIFAttach(void);

// Must provided function
#if defined(_UTF_HOSTIF_WMI)
void registerOneHostIF(void)
{
    //A_PRINTF("WMI I/F ..\n");

    _HOSTIF_INFO hostInfo = {
        wmiIFAttach,
        NULL,
        NULL,
    };
    bindHostIFFunc(&hostInfo);
    return;
}
#endif

