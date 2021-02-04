#include <stdio.h>

#include "osapi.h"
#include "wlantype.h"
#include "cmdStream.h"
#include "utf.h"
#include "testscriptIFInternal.h"
#include "utf_dev.h"

void testscriptIFAttach(void)
{
    //A_PRINTF("Attaching testscriptIF ...\n");
    //
#if defined(_UTF_HOST_IF_TS_ONLY)
#if defined(AR6002_REV42)
    {
        extern devh_t utf_dev;
        devh_t *dev=&utf_dev;

        void whal_install_patches(WHAL_STRUCT *);

        whal_install_patches(dev->pWhalStruct);
    }
#endif /* AR6002_REV42 */
#endif // #if defined(_UTF_HOST_IF_TS_ONLY)

    return;
}

//
// Architectural Notes:
//     This follows the template, which should similar among all host I/Fs.
//
A_BOOL testscriptIFCmdStreamFetch(A_UINT8 *buf, A_UINT8 **pCmdStream, A_UINT32 *cmdStreamLen)
{
    *pCmdStream=NULL;
    *cmdStreamLen =0;
//#define _FOR_TESTING
#if defined(_FOR_TESTING)
extern void composeACmdStream4Testing(A_UINT32 *cmdStreamLen, A_UINT8 **rCmdStream);
    composeACmdStream4Testing(cmdStreamLen, pCmdStream);

#else
    _TESTFLOW_CMD_STREAM *cmdStream;
    //
    // fetch from the memory location ...
    //A_PRINTF("ts loaded 0x%x addr 0x%x ", HOST_INTEREST->hi_test_apps_related, HOST_INTEREST->hi_ota_testscript);
    if ((HOST_INTEREST->hi_test_apps_related) & HI_TEST_APPS_TESTSCRIPT_LOADED) {
        *pCmdStream = (A_UINT8 *)HOST_INTEREST->hi_ota_testscript;

        // get the length 
        cmdStream = (_TESTFLOW_CMD_STREAM *)HOST_INTEREST->hi_ota_testscript;
        *cmdStreamLen = sizeof(_TESTFLOW_CMD_STREAM_HEADER) + cmdStream->cmdStreamHeader.length;
        //A_PRINTF(" pCmdStream 0x%x len %d\n", *pCmdStream, *cmdStreamLen);
    }
    else
    {
        *cmdStreamLen = 0;
    }
#endif

    // to make compiler happy ...
    buf = 0;

    return(TRUE);
}




