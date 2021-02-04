#if !defined(_SUBMIT_REPORT_PARM_TEMPLATE)
#define _SUBMIT_REPORT_PARM_TEMPLATE

// ---------------------------
// Important: There can ONLY be one typedef struct per each cmd parameter structure
//    Parser is not intelligent enough and needs this guarantee.
//

//#include "parmBinTemplate.h"
//
//

typedef enum {
    _submitreportParm_code_totalpkt=0,
    _submitreportParm_code_rssi,                     
    _submitreportParm_code_crcerrorpkt,                         
    _submitreportParm_code_secerrorpkt,
    _submitreportParm_code_rcMask0,
    _submitreportParm_code_rcMask1,
    _submitreportParm_code_rcSGMask0,
    _submitreportParm_code_rcSGMask1,
    _submitreportParm_code_rateCnt0,
    _submitreportParm_code_rateCnt1,
    _submitreportParm_code_rateCnt2,
    _submitreportParm_code_rateCnt3,
    _submitreportParm_code_rateCnt4,
    _submitreportParm_code_rateCnt5,
    _submitreportParm_code_rateCnt6,
    _submitreportParm_code_rateCnt7,
    _submitreportParm_code_rateCnt8,
    _submitreportParm_code_rateCnt9,
    _submitreportParm_code_rateCnt10,
    _submitreportParm_code_rateCnt11,
    _submitreportParm_code_rateCnt12,
    _submitreportParm_code_rateCnt13,
    _submitreportParm_code_rateCnt14,
    _submitreportParm_code_rateCnt15,
    _submitreportParm_code_rateCnt16,
    _submitreportParm_code_rateCnt17,
    _submitreportParm_code_rateCnt18,
    _submitreportParm_code_rateCnt19,
    _submitreportParm_code_rateCnt20,
    _submitreportParm_code_rateCnt21,
    _submitreportParm_code_rateCnt22,
    _submitreportParm_code_rateCnt23,
} SUBMITREPORT_PARMS_CODE;

typedef struct _submitreportParm {
    A_UINT32  totalpkt;
    A_INT32   rssiInDBm;
    A_UINT32  crcErrPkt;
    A_UINT32  secErrPkt;
    A_UINT32  shortGuard;
    A_UINT32  rcMask[ 2 ];
    A_UINT32  rateCnt[ 32 ]; 

    A_UINT32  rcMask11ac[ 4 ]; /* 11AC */
    A_UINT32  rateCnt11ac[ 54 ]; 
} __ATTRIB_PACK _SUBMITREPORT_PARMS;

extern _PARM_BIN_TEMPLATE _submitreportParm_bin_template[]; 

#endif // #if !defined(_SUBMIT_REPORT_PARM_TEMPLATE)

