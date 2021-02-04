/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */
 
#ifndef __OTP_LAYOUT_AR900B_H__
#define __OTP_LAYOUT_AR900B_H__

/*
**   This file contains the offsets in the otp used by bootrom / firmware.
** 
*/

#define Define_Otp_Offset(FieldName,Value)   enum { OTP_##FieldName##_OFFSET = Value };
#define Define_Otp_Size(FieldName,Value)   enum { OTP_##FieldName##_SIZE = Value };

//-- Bounds
Define_Otp_Offset(START,0x0);
Define_Otp_Offset(END,0x5FF);
Define_Otp_Size(MAX,0x600);

//-- Section 1
Define_Otp_Offset(KEY_SELECT,0x1F);
Define_Otp_Offset(NVRAM_PROD_MODE,0x1F);

//-- Section 2
Define_Otp_Offset(ANTI_ROLLBACK_COUNTER,0x587);
Define_Otp_Offset(OEM_ID_COMPLEMENT,0x58B);
Define_Otp_Offset(OEM_ID,0x58D);
Define_Otp_Offset(OEM_PRODUCT_FEATURE_CONTROL,0x58F);

// - Sizes 
Define_Otp_Size(ANTI_ROLLBACK_COUNTER,4);
Define_Otp_Size(OEM_ID,2);
Define_Otp_Size(OEM_PRODUCT_FEATURE_CONTROL,1);
Define_Otp_Size(KEY_SELECT,1);

// -- Masks
#define KEY_SEL_MASK                                    0x2
#define FEATURE_CONTROL_BIN_SIG_ENABLE_MASK				0x1
#define FEATURE_CONTROL_OEMID_ENABLE_MASK				0x2
#define OTP_NVRAM_PROD_MODE_MASK                        (1 << 2)

// - Reserved defines
#define OTP_MAX_NUM_BYTES       OTP_MAX_SIZE
#define OTP_HEAD_RESERVED_BYTES    32 /* At head, for options */
#define OTP_TAIL_RESERVED_BYTES    192 /* At tail, for ATE */


#endif // __OTP_LAYOUT_AR900B_H__
