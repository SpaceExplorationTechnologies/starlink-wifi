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
    _submitreportParm_code_rateCnt24,
    _submitreportParm_code_rateCnt25,
    _submitreportParm_code_rateCnt26,
    _submitreportParm_code_rateCnt27,
    _submitreportParm_code_rateCnt28,
    _submitreportParm_code_rateCnt29,
    _submitreportParm_code_rateCnt30,
    _submitreportParm_code_rateCnt31,

    _submitreportParm_code_rcMask11ac0,
    _submitreportParm_code_rcMask11ac1,
    _submitreportParm_code_rcMask11ac2,
    _submitreportParm_code_rcMask11ac3,
    
    _submitreportParm_code_rateCnt11ac0,
    _submitreportParm_code_rateCnt11ac1,
    _submitreportParm_code_rateCnt11ac2,
    _submitreportParm_code_rateCnt11ac3,
    _submitreportParm_code_rateCnt11ac4,
    _submitreportParm_code_rateCnt11ac5,
    _submitreportParm_code_rateCnt11ac6,
    _submitreportParm_code_rateCnt11ac7,
    _submitreportParm_code_rateCnt11ac8,
    _submitreportParm_code_rateCnt11ac9,
    _submitreportParm_code_rateCnt11ac10,
    _submitreportParm_code_rateCnt11ac11,
    _submitreportParm_code_rateCnt11ac12,
    _submitreportParm_code_rateCnt11ac13,
    _submitreportParm_code_rateCnt11ac14,
    _submitreportParm_code_rateCnt11ac15,
    _submitreportParm_code_rateCnt11ac16,
    _submitreportParm_code_rateCnt11ac17,
    _submitreportParm_code_rateCnt11ac18,
    _submitreportParm_code_rateCnt11ac19,
    _submitreportParm_code_rateCnt11ac20,
    _submitreportParm_code_rateCnt11ac21,
    _submitreportParm_code_rateCnt11ac22,
    _submitreportParm_code_rateCnt11ac23,
    _submitreportParm_code_rateCnt11ac24,
    _submitreportParm_code_rateCnt11ac25,
    _submitreportParm_code_rateCnt11ac26,
    _submitreportParm_code_rateCnt11ac27,
    _submitreportParm_code_rateCnt11ac28,
    _submitreportParm_code_rateCnt11ac29,
    _submitreportParm_code_rateCnt11ac30,
    _submitreportParm_code_rateCnt11ac31,
    _submitreportParm_code_rateCnt11ac32,
    _submitreportParm_code_rateCnt11ac33,
    _submitreportParm_code_rateCnt11ac34,
    _submitreportParm_code_rateCnt11ac35,
    _submitreportParm_code_rateCnt11ac36,
    _submitreportParm_code_rateCnt11ac37,
    _submitreportParm_code_rateCnt11ac38,
    _submitreportParm_code_rateCnt11ac39,
    _submitreportParm_code_rateCnt11ac40,
    _submitreportParm_code_rateCnt11ac41,
    _submitreportParm_code_rateCnt11ac42,
    _submitreportParm_code_rateCnt11ac43,
    _submitreportParm_code_rateCnt11ac44,
    _submitreportParm_code_rateCnt11ac45,
    _submitreportParm_code_rateCnt11ac46,
    _submitreportParm_code_rateCnt11ac47,
    _submitreportParm_code_rateCnt11ac48,
    _submitreportParm_code_rateCnt11ac49,
    _submitreportParm_code_rateCnt11ac50,
    _submitreportParm_code_rateCnt11ac51,
    _submitreportParm_code_rateCnt11ac52,
    _submitreportParm_code_rateCnt11ac53,
    
    _submitreportParm_code_rcMaskac4x4,
    _submitreportParm_code_rtCntac4x4_0,
    _submitreportParm_code_rtCntac4x4_1,
    _submitreportParm_code_rtCntac4x4_2,
    _submitreportParm_code_rtCntac4x4_3,
    _submitreportParm_code_rtCntac4x4_4,
    _submitreportParm_code_rtCntac4x4_5,
    _submitreportParm_code_rtCntac4x4_6,
    _submitreportParm_code_rtCntac4x4_7,
    _submitreportParm_code_rtCntac4x4_8,
    _submitreportParm_code_rtCntac4x4_9,
    _submitreportParm_code_rtCntac4x4_10,
    _submitreportParm_code_rtCntac4x4_11,
    _submitreportParm_code_rtCntac4x4_12,
    _submitreportParm_code_rtCntac4x4_13,
    _submitreportParm_code_rtCntac4x4_14,

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

    A_UINT32  rcMaskac4x4;      /* 4x4 */
    A_UINT32  rtCntac4x4[ 15 ];

} __ATTRIB_PACK _SUBMITREPORT_PARMS;

extern _PARM_BIN_TEMPLATE _submitreportParm_bin_template[]; 

#endif // #if !defined(_SUBMIT_REPORT_PARM_TEMPLATE)

