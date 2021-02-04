#if !defined(_TEST_UTIL_H)
#define _TEST_UTIL_H

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(_PARSER_4_HOST)
#define _myprintf  printf
#else
#define _myprintf  //
#endif

//-----------------------------------------------------------------------------
// Checksum
//-----------------------------------------------------------------------------
A_BOOL verifyChecksum(A_UINT16* stream, A_UINT32 len);
A_UINT16 computeChecksumOnly(A_UINT16 *pHalf, A_UINT16 length);

//-----------------------------------------------------------------------------
// Memory allocation/deacllocation
//-----------------------------------------------------------------------------
typedef enum {
    HALPHY_TOOLS_MEM_ALLOC = 1,
    HALPHY_TOOLS_MEM_FREE,
} HALPHY_TOOLS_MEM_ENUM;

typedef struct halphy_tools_mem {
    A_UINT8     *pBuf;
    A_UINT32    size;
    A_BOOL      allocated;
} __ATTRIB_PACK HALPHY_TOOLS_MEM;

A_BOOL halphyToolsMem(HALPHY_TOOLS_MEM *pMem, HALPHY_TOOLS_MEM_ENUM act, A_UINT32 size);

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif // _TEST_UTIL_H


