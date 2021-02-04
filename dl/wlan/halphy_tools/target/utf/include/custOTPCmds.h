/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#if !defined(_CUSTOTPCMDS_H)
#define _CUSTOTPCMDS_H

#define CUSTOMER_OTP_OFFSET 0x558
//#define CUSTOMER_OTP_OFFSET 0x4A
#define CUSTOMER_OTP_SIZE 24

void initWriteCustOtpSpace(void);
void initReadCustOtpSpace(void);
void initGetCustOtpSize(void);
#endif //#if !defined(_CUSTOTPCMDS_H)


