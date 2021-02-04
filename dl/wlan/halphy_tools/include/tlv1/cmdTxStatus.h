#if !defined(_CMD_TX_STATUS_H)
#define _CMD_TX_STATUS_H

// ---------------------------
// Important: There can ONLY be one typedef struct per each cmd parameter structure
//    Parser is not intelligent enough and needs this guarantee.
//

#include "parmBinTemplate.h"

//#define MCHAIN_UTF 3

typedef enum {
    _txStatusParm_code_numOfReports=0,
    _txStatusParm_code_totalPackets,
    _txStatusParm_code_goodPackets,
    _txStatusParm_code_underruns,
    _txStatusParm_code_otherError,
    _txStatusParm_code_excessRetries,
    _txStatusParm_code_rateBit,
    _txStatusParm_code_shortRetry,
    _txStatusParm_code_longRetry,
    _txStatusParm_code_startTime,
    _txStatusParm_code_endTime,
    _txStatusParm_code_byteCount,
    _txStatusParm_code_dontCount,
    _txStatusParm_code_rssi,
    _txStatusParm_code_rssic0,
    _txStatusParm_code_rssic1,
    _txStatusParm_code_rssic2,
    _txStatusParm_code_rssie0,
    _txStatusParm_code_rssie1,
    _txStatusParm_code_rssie2,
    _txStatusParm_code_thermCal,
    _txStatusParm_code_pdadc,
    _txStatusParm_code_paCfg,
    _txStatusParm_code_gainIdx,
    _txStatusParm_code_dacGain,
} CMD_TXSTATUS_PARMS_CODE;

typedef struct _txStatusParm {
    A_UINT32 numOfReports;
    A_UINT32 totalPackets;
    A_UINT32 goodPackets;
    A_UINT32 underruns;
    A_UINT32 otherError;
    A_UINT32 excessRetries;
    A_UINT32 rateBit;
    A_INT32 shortRetry;
    A_INT32 longRetry;

    A_UINT32 startTime;
    A_UINT32 endTime;
    A_UINT32 byteCount;
    A_UINT32 dontCount;

    A_INT32 rssi;
    A_INT32 rssic[ 3 ];
    A_INT32 rssie[ 3 ];

    A_UINT32 thermCal;
    A_UINT32 pdadc;
    A_UINT32 paCfg;
    A_UINT32 gainIdx;
    A_INT32  dacGain;

} __ATTRIB_PACK _CMD_TXSTATUS_PARMS;

extern _PARM_BIN_TEMPLATE _txStatusParm_bin_template[];

#endif // #if !defined(_CMD_TXSTATUS_PARMS_H)

