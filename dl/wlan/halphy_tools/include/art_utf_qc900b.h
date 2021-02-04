/*
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#ifndef _ART_UTF_QC900B_H_
#define _ART_UTF_QC900B_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef _WINDOWS
#pragma pack (push, 1)
#endif

//
// OTP defines and structures
//


#define OTP_CONFIG_MODE_UNKNOWN     0
#define OTP_CONFIG_MODE_COMMON      1
#define OTP_CONFIG_MODE_2MODAL      2      // 2G,5G
#define OTP_CONFIG_MODE_5MODAL      3      // 2G_VHT20, 2G_VHT40, 5G_VHT20, 5G_VHT40, 5G_VHT80

#define GET_LENGTH_CONFIG_ENTRY_32B(mode) (((mode) == OTP_CONFIG_MODE_5MODAL) ? 6 : (((mode) == OTP_CONFIG_MODE_2MODAL) ? 3 : 2))
#define GET_LENGTH_CONFIG_ENTRY_8B(mode) (sizeof(A_UINT32) * GET_LENGTH_CONFIG_ENTRY_32B(mode))


#ifdef _WINDOWS
#pragma pack (pop)
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ART_UTF_QC900B_H_ */

