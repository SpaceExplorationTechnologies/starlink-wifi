#include <stdio.h>

#if defined(_HOST_SIM_TESTING)
#include "otaHostCommon.h"
#else
#include "osapi.h"
#endif
#include "wlantype.h"

A_BOOL verifyChecksum(A_UINT16* stream, A_UINT32 len)
{
    A_UINT16 i,sum=0;
    for (i=0;i<len;i++) { sum ^= *stream++; }
    if (0xffff != sum) return(FALSE);
    return(TRUE);
}
    

A_UINT16 computeChecksumOnly(A_UINT16 *pHalf, A_UINT16 length)
{
    A_UINT16 sum = 0, i;
    for (i = 0; i < length; i++) { sum ^= *pHalf++; }
    return(sum);
}

