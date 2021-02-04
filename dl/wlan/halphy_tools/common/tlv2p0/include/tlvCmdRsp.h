#if !defined(__TLV_CMDRSP_H)
#define __TLV_CMDRSP_H

typedef void (*FETCH_CMD_STREAM)(A_UINT8 *buf, A_UINT8 **pCmdStream, A_UINT32 *cmdStreamLen);

/* Export module function prototypes */
A_BOOL tlvParser(A_UINT8 *buf);

/* function protytypes used by others */
A_BOOL bindBinCmdProcessing(pCmdProcessingEntry pf, int version);
A_BOOL bindBinCmdStreamParser(pBinCmdStreamParser pf, int version);
void bindFetchCmdStream(FETCH_CMD_STREAM fp);

#endif /*#if !defined(__TLV_CMDRSP_H)*/

