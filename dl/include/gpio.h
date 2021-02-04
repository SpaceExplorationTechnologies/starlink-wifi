/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// Copyright (c) 2005-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#define AR6001_GPIO_PIN_COUNT 18
#define AR6002_GPIO_PIN_COUNT 18
#define AR6003_GPIO_PIN_COUNT 28
#define AR6004_GPIO_PIN_COUNT 57
#define AR6006_GPIO_PIN_COUNT 57
#define AR9888_GPIO_PIN_COUNT 24
#define AR6320_GPIO_PIN_COUNT 24 /* TODO: FixMe ROME, for version before Drop 3.2 */
#define AR6320_GPIO_PIN_COUNT_FINAL 33 /* TODO: for Drop 3.2, to make both Drop 3.1 and Drop 3.2 work */
#define AR900B_GPIO_PIN_COUNT 35
//TODO CASCADE confirm this with SOC
#define QCA9984_GPIO_PIN_COUNT 35
#define QCA9888_GPIO_PIN_COUNT 35
// TODO Dakota - remove GPIO since it is in SOC level
#define IPQ4019_GPIO_PIN_COUNT 0

/*
 * Values of gpioreg_id in the WMIX_GPIO_REGISTER_SET_CMDID and WMIX_GPIO_REGISTER_GET_CMDID
 * commands come in two flavors.  If the upper bit of gpioreg_id is CLEAR, then the
 * remainder is interpreted as one of these values.  This provides platform-independent
 * access to GPIO registers.  If the upper bit (GPIO_ID_OFFSET_FLAG) of gpioreg_id is SET,
 * then the remainder is interpreted as a platform-specific GPIO register offset.
 */
#define GPIO_ID_OUT             0x00000000
#define GPIO_ID_OUT_W1TS        0x00000001
#define GPIO_ID_OUT_W1TC        0x00000002
#define GPIO_ID_ENABLE          0x00000003
#define GPIO_ID_ENABLE_W1TS     0x00000004
#define GPIO_ID_ENABLE_W1TC     0x00000005
#define GPIO_ID_IN              0x00000006
#define GPIO_ID_STATUS          0x00000007
#define GPIO_ID_STATUS_W1TS     0x00000008
#define GPIO_ID_STATUS_W1TC     0x00000009
#define GPIO_ID_PIN0            0x0000000a
#define GPIO_ID_PIN(n)          (GPIO_ID_PIN0+(n))
#define GPIO_ID_NONE            0xffffffff

#define GPIO_ID_OFFSET_FLAG     0x80000000
#define GPIO_ID_REG_MASK        0x7fffffff
#define GPIO_ID_IS_OFFSET(reg_id) (((reg_id) & GPIO_ID_OFFSET_FLAG) != 0)
