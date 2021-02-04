#include <stdio.h>

#if !defined(_HOST_SIM_TESTING)
#include "osapi.h"
#else
#include <string.h>
typedef enum { FALSE, TRUE } A_BOOL ;
#endif
#include "wlantype.h"
#include "utfCallback.h"

//
// Notes:
//    Callback order is not maintained due to add and remove operation.
//    This is a very rudimentary implementation with a few callbacks in mind.
//

_CALLBACK_FUNC RxCallbackFuncs[MAX_CALLBACK_FUNC]; 
//_CALLBACK_FUNC TxCallbackFuncs[MAX_CALLBACK_FUNC]; 
_CALLBACK_FUNC TxCallbackFunc; 

A_BOOL registerCallback(_pCALLBACK_FUNC funcCallback, _pCALL_DURING_REGISTER_FUNC func4Reg, void *pData)
{
    int i;
    A_BOOL rc=TRUE;
    for (i=0;i<MAX_CALLBACK_FUNC;i++) {
        if (NULL == RxCallbackFuncs[i].pCallback) {
            //A_PRINTF(".add %x to %d\n", &funcCallback, i);
            RxCallbackFuncs[i].pCallback = funcCallback;
            RxCallbackFuncs[i].pInput = pData;
            RxCallbackFuncs[i].pReturn = NULL;
            if (NULL != func4Reg) {
                (func4Reg)(pData);
            }
            break;
        }
    }
    if (i > MAX_CALLBACK_FUNC) {
        rc=FALSE;
        //A_PRINTF("Failed to add callback\n");
    }
    return(rc);
}

void deregisterCallback(_pCALLBACK_FUNC func)
{
    int i;
    for (i=0;i<MAX_CALLBACK_FUNC;i++) {
        if (RxCallbackFuncs[i].pCallback == func) {
            //A_PRINTF(".dereg %x at %d\n", &func, i);
            RxCallbackFuncs[i].pCallback = NULL;
            RxCallbackFuncs[i].pInput = NULL;
            RxCallbackFuncs[i].pReturn = NULL;
            break;
        }
    }
    return;
}

void deregisterTxCallback(void)
{
    TxCallbackFunc.pCallback = NULL;
    TxCallbackFunc.pInput = NULL;
    TxCallbackFunc.pReturn = NULL;
    return;
}

void registerTxCallback(_pCALLBACK_FUNC funcCallback, void *pData)
{
    TxCallbackFunc.pCallback = funcCallback;
    TxCallbackFunc.pInput = pData;
    TxCallbackFunc.pReturn = NULL;
    return;
}

void runTxCallback( void *tcmdTxStat )
{
    //A_PRINTF("..tx callback ");
    if (NULL != TxCallbackFunc.pCallback) {
        TxCallbackFunc.pReturn = (void*)tcmdTxStat;
        (TxCallbackFunc.pCallback)(TxCallbackFunc.pInput, TxCallbackFunc.pReturn);
        //A_PRINTF(".. done\n");
    }
    return;
}

void runThroughCallback( void *tcmdRxStat )
{
    int i;
    //A_PRINTF("..r callbacks ");
    for (i=0;i<MAX_CALLBACK_FUNC;i++) {
        if (NULL != RxCallbackFuncs[i].pCallback) {
            //A_PRINTF(" %d ", i);
            RxCallbackFuncs[i].pReturn = (void*)tcmdRxStat;
            (RxCallbackFuncs[i].pCallback)(RxCallbackFuncs[i].pInput, RxCallbackFuncs[i].pReturn);
        }
    }
    //A_PRINTF("\n");
    return;
}

#if defined(_HOST_SIM_TESTING)
typedef struct _pTestData {
    int tt;
} _PTEST_DATA;
_PTEST_DATA pd1, pd2;
static void callbk1(void *pData) { printf("callbk1 %d\n", ((_PTEST_DATA *)pData)->tt); return; }
static void callbk2(void *pData) { printf("callbk2 %d\n", ((_PTEST_DATA *)pData)->tt); return; }
int main(void) {
#if defined(_HOST_SIM_TESTING)
    memset((void*)&(RxCallbackFuncs[0]), 0, sizeof(RxCallbackFuncs));
#else
    A_MEMZERO((void*)&(RxCallbackFuncs[0], sizeof(RxCallbackFuncs)));
#endif
    registerCallback(callbk1, &pd1);
    registerCallback(callbk2, &pd2);
    runThroughCallback();
    deregisterCallback(callbk1);
    deregisterCallback(callbk2);
    return(0);
}
#endif // #if defined(_HOST_SIM_TESTING)

