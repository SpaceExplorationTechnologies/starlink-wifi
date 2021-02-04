/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifdef VXWORKS
#endif /* VXWORKS */

#if defined(LINUX) || defined(__linux__)
#endif /* LINUX */

#ifdef QNX
#endif /* QNX */

#ifdef INTEGRITY
#include "integrity/athendpack_integrity.h"
#endif /* INTEGRITY */

#ifdef NUCLEUS
#endif /* NUCLEUS */


#ifdef ATHR_WM_NWF
#include "../os/windows/include/athendpack.h"
#endif

#ifdef ATHR_CE_LEGACY
#include "../os/windows/include/athendpack.h"
#endif /* WINCE */

#ifdef ATHR_WIN_NWF
//#include <poppack.h>
#endif
