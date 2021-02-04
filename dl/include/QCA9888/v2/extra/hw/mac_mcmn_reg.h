/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// ------------------------------------------------------------------
// Copyright (c) 2004-2007 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Atheros"
//===================================================================

#ifndef __MAC_MCMN_REG_SW_H
#define __MAC_MCMN_REG_SW_H
// THIS IS A SOFTWARE WRAPPER HEADER FILE

#include "../../hw/mac_mcmn_reg.h"


#define MPDU_LINK_DESC_MIN_IDX_ADDR(_i)           (MPDU_LINK_DESC_MIN_IDX_ADDRESS + ((_i)<<2))
#define MPDU_LINK_DESC_MAX_IDX_ADDR(_i)           (MPDU_LINK_DESC_MAX_IDX_ADDRESS + ((_i)<<2))

#define MSDU_LINK_EXT_DESC_BASE_ADDR(_i)          (MSDU_LINK_EXT_DESC_BASE_ADDR_ADDRESS + ((_i)<<2))
#define MSDU_LINK_EXT_DESC_MIN_IDX_ADDR(_i)       (MSDU_LINK_EXT_DESC_MIN_IDX_ADDRESS + ((_i)<<2))
#define MSDU_LINK_EXT_DESC_MAX_IDX_ADDR(_i)       (MSDU_LINK_EXT_DESC_MAX_IDX_ADDRESS + ((_i)<<2))
#define MSDU_LINK_EXT_DESC_SWAP_ADDR(_i)          (MSDU_LINK_EXT_DESC_SWAP_ADDRESS + ((_i)<<2))

#endif /*__MAC_MCMN_REG_SW_H */



