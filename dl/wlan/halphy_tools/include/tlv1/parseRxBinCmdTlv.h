#if !defined(_PARSE_RXBIN_CMDTLV_H)
#define  _PARSE_RXBIN_CMDTLV_H

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
LIBTLVUTILDLLSPEC A_BOOL initResponse (A_UINT8 *stream, A_UINT32 len, A_UINT8 *opCode);
LIBTLVUTILDLLSPEC A_BOOL getParams(A_UINT8 *key, A_UINT8 **data, A_UINT32 *len);

#endif

