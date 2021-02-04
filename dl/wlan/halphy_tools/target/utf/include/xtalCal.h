/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#if !defined(_XTALCAL_H)
#define _XTALCAL_H

#define XTAL_OTP_CAPIN_BYTE_OFFSET 3
#define XTAL_OTP_CAPOUT_BYTE_OFFSET 4
#define XTAL_OTP_STATICS_REGION_LOCK_MASK 1
#define XTAL_OTP_CAPVALUE_MASK 0x7f

#if (TARGET_VER == 1) && defined (AR900B)
#define CAPOUT_WIDTH 7
#else
#define CAPOUT_WIDTH 6
#endif

#define CAPDAC_MIN 0
#define CAPDAC_MAX ((1<<CAPOUT_WIDTH)-1)

void initXtalCal(void);
#endif //#if !defined(_XTALCAL_H)


