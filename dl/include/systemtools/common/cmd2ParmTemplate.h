#if !defined(_CMD_2_PARM_TEMPLATE_H)
#define _CMD_2_PARM_TEMPLATE_H

#include "parmTxtTemplate.h"

typedef struct _testFlowCmdParmTemplate {
    A_UINT32                     numParms;
    _TESTFLOW_TXT_PARM_TEMPLATE *parmTemplate;
} __ATTRIB_PACK _TESTFLOW_CMD_PARM_TEMPLATE;

#endif // #if !defined(_CMD_2_PARM_TEMPLATE_H)

