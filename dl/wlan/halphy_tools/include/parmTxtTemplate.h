#if !defined(_TEST_CMD_PARMS_TXT_TEMPLATE)
#define _TEST_CMD_PARMS_TXT_TEMPLATE

#include <string.h>
#if defined(_HOST_SIM_TESTING)
#include "otaHostCommon.h"
#else
#include "osapi.h"
#define KEY_SIZE_MAX 16
#endif
#include "wlantype.h"

typedef struct _testFlowTxtParmTemplate {
    char     parm[KEY_SIZE_MAX];
    A_UINT32 parmType;
    A_UINT32 offset;
    size_t   len;
} __ATTRIB_PACK _TESTFLOW_TXT_PARM_TEMPLATE;

#endif // #if !defined(_TEST_CMD_PARMS_TXT_TEMPLATE)

