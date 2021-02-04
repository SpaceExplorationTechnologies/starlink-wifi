/*
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#ifndef _ART_UTF_QC98XX_H_
#define _ART_UTF_QC98XX_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef _WINDOWS
#pragma pack (push, 1)
#endif

//
// OTP defines and structures
//

//#define CUSTOMER_DATA_SIZE          20      //TRANG leave here for now until common qc98xx_eeprom.h
#define QC98XX_OTP_VER_1             1
#define QC98XX_OTP_VER_2             2
#define QC98XX_OTP_APPL_ID_WLAN      1
#define QC98XX_OTP_USB_CONFIG        0xFC

#define EFUSE_MAX_NUM_BYTES        1024
#if defined(AR9888_VER1) || defined(QC98XXDLL)
#define EFUSE_HEAD_RESERVED_BYTES    10 /* At head, for options */
#else
#define EFUSE_HEAD_RESERVED_BYTES    36 /* At head, for options */
#endif //AR9888_VER1
#define EFUSE_TAIL_RESERVED_BYTES    96 /* At tail, for ATE */

#define OTP_CONFIG_MODE_UNKNOWN     0
#define OTP_CONFIG_MODE_COMMON      1
#define OTP_CONFIG_MODE_2MODAL      2      // 2G,5G
#define OTP_CONFIG_MODE_5MODAL      3      // 2G_VHT20, 2G_VHT40, 5G_VHT20, 5G_VHT40, 5G_VHT80

#define GET_LENGTH_CONFIG_ENTRY_32B(mode) (((mode) == OTP_CONFIG_MODE_5MODAL) ? 6 : (((mode) == OTP_CONFIG_MODE_2MODAL) ? 3 : 2))
#define GET_LENGTH_CONFIG_ENTRY_8B(mode) (sizeof(A_UINT32) * GET_LENGTH_CONFIG_ENTRY_32B(mode))

typedef struct Qc98xxOtpStreamHeader
{
    A_UINT8  applID;
    A_UINT8  version;
} __ATTRIB_PACK QC98XX_OTP_STREAM_HEADER;

#ifdef _WINDOWS
#pragma pack (pop)
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ART_UTF_QC98XX_H_ */

