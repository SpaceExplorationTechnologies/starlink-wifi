#include <stdio.h>
#include "osapi.h"
#include "wlantype.h"
#include "utf.h"
#include "testscriptIFInternal.h"

// Architectural notes:
//     Provide host IF specific functions, following the template.
//
// Must-be-provided function
// Following this template ...
extern void wmiIFAttach(void);

void registerOneHostIF(void)
{
#if 0
    A_PRINTF("Testscript I/F null ..\n");
    _HOSTIF_INFO hostInfo = {
        testscriptIFAttach,
        //wmiIFAttach,
        NULL,
        NULL,
    };
#else
    //A_PRINTF("Testscript I/F ..\n");

    _HOSTIF_INFO hostInfo = {
        testscriptIFAttach,
        testscriptIFCmdStreamFetch,
        hostIFProcessing, //testscriptIFProcessing,
    };
#endif
    bindHostIFFunc(&hostInfo);
    return;
}


