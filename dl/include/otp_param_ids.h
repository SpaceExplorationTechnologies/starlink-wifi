/*
 * Copyright (c) 2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef _OTP_PARAM_IDS_H_
#define _OTP_PARAM_IDS_H_

/* Input OTP param from host */
typedef enum {
    OTP_PARAM_SKIP_MAC_ADDR             = 1,
    OTP_PARAM_SKIP_REG_DOMAIN           = 2,
    OTP_PARAM_SKIP_OTPSTREAM_ID_CAL_5G  = 4,
    OTP_PARAM_SKIP_OTPSTREAM_ID_CAL_2G  = 8,
    OTP_PARAM_GET_CHIPVER_BID           = 0x10,
    OTP_PARAM_USE_GOLDENTEMPLATE        = 0x20,
    OTP_PARAM_USE_OTP                   = 0x40,
    OTP_PARAM_SKIP_EEPROM               = 0x80,
    OTP_PARAM_EEPROM_SECTION_MAC        = 0x100,
    OTP_PARAM_EEPROM_SECTION_REGDMN     = 0x200,
    OTP_PARAM_EEPROM_SECTION_CAL        = 0x400,
    OTP_PARAM_OTP_SECTION_MAC           = 0x800,
    OTP_PARAM_OTP_SECTION_REGDMN        = 0x1000,
    OTP_PARAM_OTP_SECTION_CAL           = 0x2000,
    OTP_PARAM_SKIP_OTP                  = 0x4000,
    OTP_PARAM_GET_BID_FROM_FLASH        = 0x8000,
    OTP_PARAM_FLASH_SECTION_ALL         = 0x10000,
    OTP_PARAM_FLASH_ALL                 = 0x20000,
    OTP_PARAM_GET_EXTENDED_BID          = 0x40000,
    OTP_PARAM_APPLY_PMU_DISABLE         = 0x80000000
} OTP_PARAM_ID;

/* Return status to host */
enum {
    RET_SUCCESS                     = 0,
    RET_BOARD_DATA_NOT_INITALIZED   = 1,
    RET_NO_OTP_DATA                 = 2,
    RET_FAILURE                     = 3,
    RET_OTP_BOARD_VERSION_MISMATCH1 = 4,
    RET_OTP_BOARD_VERSION_MISMATCH2 = 5,
    RET_OTP_VERSION_UNSUPPORTED     = 6,
    RET_ZEROCAL_NO_ATE_DATA         = 7,
    RET_ZEROCAL_SUCCESS             = 8,
    RET_ZEROCAL_FAILURE             = 9,
};

#define RET_BOARDID_NOTFOUND    0
#define RET_BOARDID_LSB         10
#define RET_BOARDID_MASK        0x1f
#define RET_VER_LSB             15
#define RET_VER_MASK            0x7
#define RET_EBDF_SUPPORT_LSB    18
#define RET_EBDF_SUPPORT_MASK   0x1
#define APPEND_VER_BID(ret,ver,id)      (((ver & RET_VER_MASK) << RET_VER_LSB) + ((id & RET_BOARDID_MASK) << RET_BOARDID_LSB) + ret)
#define APPEND_EBDF_SUPPORT(ret,ebdf)   (((ebdf & RET_EBDF_SUPPORT_MASK) << RET_EBDF_SUPPORT_LSB) + ret)

#endif //_OTP_PARAM_IDS_H_
