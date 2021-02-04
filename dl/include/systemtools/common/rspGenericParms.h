#if !defined(_RSP_GENERIC_PARM_TEMPLATE)
#define _RSP_GENERIC_PARM_TEMPLATE

// ---------------------------
// Important: There can ONLY be one typedef struct per each cmd parameter structure
//    Parser is not intelligent enough and needs this guarantee.
//

//#include "parmBinTemplate.h"

typedef enum {
    _rspGenericParm_code_status=0,
    _rspGenericParm_code_value,
} RSP_GENERIC_PARMS_CODE;

typedef struct _rspGenericParm {
    A_UINT32  status;
    A_UINT32  value;
} __ATTRIB_PACK _RSP_GENERIC_PARMS;


extern _PARM_BIN_TEMPLATE _rspGenericParm_bin_template[]; 

#endif // #if !defined(_RSP_GENERIC_PARM_TEMPLATE)

