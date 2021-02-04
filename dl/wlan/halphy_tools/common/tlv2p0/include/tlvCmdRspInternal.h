#if !defined(__TLV_CMDRSP_INTERNAL_H)
#define __TLV_CMDRSP_INTERNAL_H

typedef A_BOOL (*pBinCmdStreamParser)(A_UINT8 *stream, A_UINT32 readStreamLen, A_UINT8 **pPayload, A_UINT16 *payloadLen, A_UINT8 *numRemainSegs);
typedef void   (*pCmdProcessingEntry)(void);

typedef struct tlvCmdRspData_struct {
    _PARSED_BIN_CMD_STREAM_INFO     CmdStreamInfo;
} TLV_CMDRSP_DATA; 
extern TLV_CMDRSP_DATA TlvCmdRspData, *pTlvCmdRspData;

#endif /*#if !defined(__TLV_CMDRSP_INTERNAL_H)*/
