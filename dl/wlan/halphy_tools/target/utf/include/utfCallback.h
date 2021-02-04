#if !defined(_UTF_CALLBACK_H)
#define  _UTF_CALLBACK_H 
//
//
// Notes:
//    Callback order is not maintained due to add and remove operation.
//    This is a very rudimentary implementation with a few callbacks in mind.
//
#define MAX_CALLBACK_FUNC 1*4

typedef void (*_pCALLBACK_FUNC)(void *pInput, void *pReturn);
typedef void (*_pCALL_DURING_REGISTER_FUNC)(void *pInput);

typedef struct _callback {
    _pCALLBACK_FUNC    pCallback;
    void*              pInput;
    void*              pReturn;
} _CALLBACK_FUNC;

extern _CALLBACK_FUNC RxCallbackFuncs[MAX_CALLBACK_FUNC]; 

extern A_BOOL registerCallback(_pCALLBACK_FUNC funcCallback, _pCALL_DURING_REGISTER_FUNC func4Reg, void *pData);
extern void deregisterCallback(_pCALLBACK_FUNC func);
extern void registerTxCallback(_pCALLBACK_FUNC funcCallback, void *pData);
extern void deregisterTxCallback(void);

// for tcmd internal consumption
void runThroughCallback( void *tcmdRxStat);
void runTxCallback( void *tcmdTxStat);

#endif //#if !defined(_UTF_CALLBACK_H)


