#if !defined(_GEN_TXBIN_CMDTLV_H)
#define  _GEN_TXBIN_CMDTLV_H

#ifdef _WINDOWS
    #ifdef LIBTLVUTIL_DLL
		#define LIBTLVUTILDLLSPEC __declspec(dllexport)
	#else
		#define LIBTLVUTILDLLSPEC __declspec(dllimport)
	#endif
#else
	#define LIBTLVUTILDLLSPEC
#endif

// exposed API for host/target 
LIBTLVUTILDLLSPEC A_BOOL createCommand(A_UINT8 opCode);
LIBTLVUTILDLLSPEC A_BOOL addParameterToCommand(A_UINT8 *key, A_UINT8 *data);
LIBTLVUTILDLLSPEC A_BOOL addParameterToCommandWithLen(A_UINT8 *key, A_UINT8 *data, A_UINT16 dataLen);
LIBTLVUTILDLLSPEC A_BOOL commandComplete(A_UINT8 **rCmdStream, A_UINT32 *len );

#endif

