#if !defined(_CMD_RX_PARM_TEMPLATE)
#define _CMD_RX_PARM_TEMPLATE

// ---------------------------
// Important: There can ONLY be one typedef struct per each cmd parameter structure
//    Parser is not intelligent enough and needs this guarantee.
//

#include "parmBinTemplate.h"
#include "art_utf_common.h"

typedef enum {
    _rxParm_code_channel=0,
    _rxParm_code_act,
    _rxParm_code_enANI,
    _rxParm_code_antenna,
    _rxParm_code_wlanMode,
    _rxParm_code_rxChain,
    _rxParm_expectedPkts,
    _rxParm_code_ack,
    _rxParm_code_bc,
    _rxParm_code_bandwidth,
    _rxParm_code_lpl,
    _rxParm_code_antswitch1,
    _rxParm_code_antswitch2,
    _rxParm_code_addr,
    _rxParm_code_bssid,
    _rxParm_code_btaddr,
    _rxParm_code_reserved,
    _rxParm_code_regDmn0,
    _rxParm_code_regDmn1,
    _rxParm_code_otpWriteFlag,
    _rxParm_code_flags,
    _rxParm_code_rateMask0,
    _rxParm_code_rateMask1,
    _rxParm_code_rateMask2,
    _rxParm_code_rateMask3,
    _rxParm_code_rateMask4,
    _rxParm_code_rateMask5,
    _rxParm_code_spectralScan,	
    _rxParm_code_noiseFloor,
    _rxParm_code_rateMask6,
    _rxParm_code_rateMask7,
    _rxParm_code_channel2,
    _rxParm_code_rateMask8,
} CMD_RX_PARMS_CODE;

#if defined(_HOST_SIM_TESTING)
#define ATH_MAC_LEN  6
#endif

typedef struct _rxParm {
    A_UINT32  channel;
    A_UINT32  rxMode;// A_UINT32  act;
    A_UINT32  enANI;
    A_UINT32  antenna;
    A_UINT32  wlanMode;
    A_UINT32  rxChain;
    A_UINT32  expectedPkts;
    A_UINT32  ack;
    A_UINT32  bc;
    A_UINT32  bandwidth;
    A_UINT32  lpl;
    A_UINT32  antswitch1;
    A_UINT32  antswitch2;
    A_UCHAR   addr[ATH_MAC_LEN/*6*/];  
    A_UCHAR   bssid[ATH_MAC_LEN/*6*/];  
    A_UCHAR   btaddr[ATH_MAC_LEN/*6*/];  
    A_UCHAR   reserved[ 2 ]; // reserved to align 4B
    A_UINT16  regDmn[ 2 ];  
    A_UINT32  otpWriteFlag;

    A_UINT32  flags;
    A_UINT32  rateMask[(RATE_MASK_ROW_MAX-3)/*6*/];
    A_UINT16  spectralScan;
    A_INT16   noiseFloor;
    A_UINT32  rateMask6;
    A_UINT32  rateMask7;
    A_UINT32  channel2;
    A_UINT32  rateMask8;
} __ATTRIB_PACK _CMD_RX_PARMS;


extern _PARM_BIN_TEMPLATE _rxParm_bin_template[]; 

#endif // #if !defined(_CMD_RX_PARM_TEMPLATE)

