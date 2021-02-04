#if !defined(_CMD_RX_STATUS_H)
#define _CMD_RX_STATUS_H

// ---------------------------
// Important: There can ONLY be one typedef struct per each cmd parameter structure
//    Parser is not intelligent enough and needs this guarantee.
//

#include "parmBinTemplate.h"

//#define MCHAIN_UTF 	3
//#define MSTREAM_UTF 	3

typedef enum {
    _rxStatusParm_code_numOfReports=0,
    _rxStatusParm_code_totalPackets,
    _rxStatusParm_code_goodPackets,
    _rxStatusParm_code_otherError,
    _rxStatusParm_code_crcPackets,
    _rxStatusParm_code_decrypErrors,
    _rxStatusParm_code_rateBit,
    _rxStatusParm_code_startTime,
    _rxStatusParm_code_endTime,
    _rxStatusParm_code_byteCount,
    _rxStatusParm_code_dontCount,
    _rxStatusParm_code_rssi,
    _rxStatusParm_code_rssic0,
    _rxStatusParm_code_rssic1,
    _rxStatusParm_code_rssic2,
    _rxStatusParm_code_rssic3,
    _rxStatusParm_code_rssie0,
    _rxStatusParm_code_rssie1,
    _rxStatusParm_code_rssie2,
    _rxStatusParm_code_rssie3,
    _rxStatusParm_code_evm0,
    _rxStatusParm_code_evm1,
    _rxStatusParm_code_evm2,
    _rxStatusParm_code_evm3,
    _rxStatusParm_code_badrssi,
    _rxStatusParm_code_badrssic0,
    _rxStatusParm_code_badrssic1,
    _rxStatusParm_code_badrssic2,
    _rxStatusParm_code_badrssic3,
    _rxStatusParm_code_badrssie0,
    _rxStatusParm_code_badrssie1,
    _rxStatusParm_code_badrssie2,
    _rxStatusParm_code_badrssie3,
    _rxStatusParm_code_badevm0,
    _rxStatusParm_code_badevm1,
    _rxStatusParm_code_badevm2,
    _rxStatusParm_code_badevm3,
    _rxStatusParm_code_noisefloor0,
    _rxStatusParm_code_noisefloor1,
    _rxStatusParm_code_noisefloor2,
    _rxStatusParm_code_noisefloor3, 
    _rxStatusParm_code_pilotevm0,
    _rxStatusParm_code_pilotevm1,
    _rxStatusParm_code_pilotevm2,
    _rxStatusParm_code_pilotevm3,
    _rxStatusParm_code_pilotevm4,
    _rxStatusParm_code_pilotevm5,
    _rxStatusParm_code_pilotevm6,
    _rxStatusParm_code_pilotevm7,
    _rxStatusParm_code_pilotevm8,
    _rxStatusParm_code_pilotevm9,
    _rxStatusParm_code_pilotevm10,
    _rxStatusParm_code_pilotevm11,
    _rxStatusParm_code_pilotevm12,
    _rxStatusParm_code_pilotevm13,
    _rxStatusParm_code_pilotevm14,
    _rxStatusParm_code_pilotevm15,
	
} CMD_RXSTATUS_PARMS_CODE;

typedef struct _rxStatusParm {
    A_UINT32 numOfReports;
    A_UINT32 totalPackets;
    A_UINT32 goodPackets;
    A_UINT32 otherError;
    A_UINT32 crcPackets;
    A_UINT32 decrypErrors;
    A_UINT32 rateBit;

    A_UINT32 startTime;
    A_UINT32 endTime;
    A_UINT32 byteCount;
    A_UINT32 dontCount;

    A_INT32 rssi;
    A_INT32 rssic[ 4];
    A_INT32 rssie[ 4];

    A_INT32 evm[ 4];

    A_INT32 badrssi;
    A_INT32 badrssic[ 4];
    A_INT32 badrssie[ 4];

    A_INT32 badevm[ 4];
    A_INT32 noisefloor[ 4];
    A_INT32 pilotevm[ 16];

} __ATTRIB_PACK _CMD_RXSTATUS_PARMS;

extern _PARM_BIN_TEMPLATE _rxStatusParm_bin_template[];

#endif // #if !defined(_CMD_RXSTATUS_PARMS_H)

