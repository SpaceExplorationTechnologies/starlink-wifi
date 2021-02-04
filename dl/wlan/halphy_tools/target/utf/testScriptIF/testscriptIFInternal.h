#if !defined(_TESTSCRIPTIF_INTERNAL_H)
#define  _TESTSCRIPTIF_INTERNAL_H 

extern void testscriptIFAttach(void);
//extern A_INT32 testscriptIFProcessing(void);
extern A_BOOL testscriptIFCmdStreamFetch(A_UINT8 *buf, A_UINT8 **pCmdStream, A_UINT32 *cmdStreamLen);

#endif //* #if !defined(_TESTSCRIPTIF_INTERNAL_H)

