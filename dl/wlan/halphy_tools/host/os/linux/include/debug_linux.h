//------------------------------------------------------------------------------
// Copyright (c) 2004-2010 Atheros Communications Inc.
// All rights reserved.
//
// $ATH_LICENSE_HOSTSDK0_C$
//
// Author(s): ="Atheros"
//------------------------------------------------------------------------------
/*
 *  Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved. 
 *
 *  Qualcomm is a trademark of Qualcomm Technologies Incorporated, registered in the United
 *  States and other countries.  All Qualcomm Technologies Incorporated trademarks are used with
 *  permission.  Atheros is a trademark of Qualcomm Atheros, Inc., registered in
 *  the United States and other countries.  Other products and brand names may be
 *  trademarks or registered trademarks of their respective owners. 
 */

#ifndef _DEBUG_LINUX_H_
#define _DEBUG_LINUX_H_

    /* macro to remove parens */
#define ATH_PRINTX_ARG(arg...) arg

#ifdef DEBUG
    /* NOTE: the AR_DEBUG_PRINTF macro is defined here to handle special handling of variable arg macros
     * which may be compiler dependent. */
#define AR_DEBUG_PRINTF(mask, args) do {        \
    if (GET_ATH_MODULE_DEBUG_VAR_MASK(ATH_MODULE_NAME) & (mask)) {                    \
        A_LOGGER(mask, ATH_MODULE_NAME, ATH_PRINTX_ARG args);    \
    }                                            \
} while (0)
#else
    /* on non-debug builds, keep in error and warning messages in the driver, all other
     * message tracing will get compiled out */
#define AR_DEBUG_PRINTF(mask, args) \
    if ((mask) & (ATH_DEBUG_ERR | ATH_DEBUG_WARN)) { A_PRINTF(ATH_PRINTX_ARG args); }

#endif

    /* compile specific macro to get the function name string */
#define _A_FUNCNAME_  __func__


#endif /* _DEBUG_LINUX_H_ */
