#if !defined(_CMD_SETREG_PARM_TEMPLATE)
#define _CMD_SETREG_PARM_TEMPLATE

// ---------------------------
// Important: There can ONLY be one typedef struct per each cmd parameter structure
//    Parser is not intelligent enough and needs this guarantee.
//

//#include "parmBinTemplate.h"

typedef enum {
    _setRegParm_code_regAddr=0,
    _setRegParm_code_value,
    _setRegParm_code_flag,
} CMD_SETREG_PARMS_CODE;

typedef struct _setRegParm {
    A_UINT32  regAddr;
    A_UINT32  value;
    A_UINT16  flag;
} __ATTRIB_PACK _CMD_SETREG_PARMS;


extern _PARM_BIN_TEMPLATE _setRegParm_bin_template[]; 

#endif // #if !defined(_CMD_SETREG_PARM_TEMPLATE)

