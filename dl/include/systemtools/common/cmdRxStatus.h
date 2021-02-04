#if !defined(_CMD_RX_STATUS_H)
#define _CMD_RX_STATUS_H

// ---------------------------
// Important: There can ONLY be one typedef struct per each cmd parameter structure
//    Parser is not intelligent enough and needs this guarantee.
//

#include "parmBinTemplate.h"

#define MCHAIN_UTF 	3
#define MSTREAM_UTF 	3

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
    _rxStatusParm_code_rssie0,
    _rxStatusParm_code_rssie1,
    _rxStatusParm_code_rssie2,
    _rxStatusParm_code_evm0,
    _rxStatusParm_code_evm1,
    _rxStatusParm_code_evm2,
    _rxStatusParm_code_badrssi,
    _rxStatusParm_code_badrssic0,
    _rxStatusParm_code_badrssic1,
    _rxStatusParm_code_badrssic2,
    _rxStatusParm_code_badrssie0,
    _rxStatusParm_code_badrssie1,
    _rxStatusParm_code_badrssie2,
    _rxStatusParm_code_badevm0,
    _rxStatusParm_code_badevm1,
    _rxStatusParm_code_badevm2,
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
    A_INT32 rssic[ 3];
    A_INT32 rssie[ 3];

    A_INT32 evm[ 3];

    A_INT32 badrssi;
    A_INT32 badrssic[ 3];
    A_INT32 badrssie[ 3];

    A_INT32 badevm[ 3];

} __ATTRIB_PACK _CMD_RXSTATUS_PARMS;

extern _PARM_BIN_TEMPLATE _rxStatusParm_bin_template[];

#endif // #if !defined(_CMD_RXSTATUS_PARMS_H)

