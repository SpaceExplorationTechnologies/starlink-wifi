#if !defined(_GEN_TXBIN_CMDTLV_H)
#define  _GEN_TXBIN_CMDTLV_H

// exposed API for host/target 
A_BOOL createCommand(A_UINT8 opCode);
A_BOOL addParameterToCommand(A_UINT8 *key, A_UINT8 *data);
A_BOOL addParameterToCommandWithLen(A_UINT8 *key, A_UINT8 *data,A_UINT16 len);
A_BOOL commandComplete(A_UINT8 **rCmdStream, A_UINT32 *len );

#endif

