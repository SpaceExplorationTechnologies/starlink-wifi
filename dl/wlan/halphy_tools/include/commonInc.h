#ifndef _COMMON_INC_H_
#define _COMMON_INC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#if defined(_HOST_SIM_TESTING)
#include "otaHostCommon.h"
#else
#include "osapi.h"
#endif
//#if !defined(TEST_FRAMEWORK)
#include "wlantype.h"
//#endif //!defined(TEST_FRAMEWORK)
#include "tsCommon.h"

#endif //_COMMON_INC_H_/
