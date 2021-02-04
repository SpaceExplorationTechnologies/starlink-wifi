/*
 * Copyright (c) 2011-2012, 2014-2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#ifndef _FW_RX_DESC_H
#define _FW_RX_DESC_H
#include <fw_rx_desc_deps.h>
/*
 * This struct defines the basic MSDU rx descriptor created by FW.
 */
struct fw_rx_desc_base {
    union {
        struct {
            A_UINT8 discard  : 1,
                    forward  : 1,
                    any_err  : 1,
                    dup_err  : 1,
                    reserved : 1,
                    inspect  : 1,
                    extension: 2;
        }bits;
        A_UINT8     val;
    }u;
};


#define FW_RX_DESC_DISCARD_M 0x1
#define FW_RX_DESC_DISCARD_S 0
#define FW_RX_DESC_FORWARD_M 0x2
#define FW_RX_DESC_FORWARD_S 1
#define FW_RX_DESC_INSPECT_M 0x20
#define FW_RX_DESC_INSPECT_S 5
#define FW_RX_DESC_EXT_M     0xc0
#define FW_RX_DESC_EXT_S     6

#define FW_RX_DESC_CNT_2_BYTES(_fw_desc_cnt)    (_fw_desc_cnt)

enum {
    FW_RX_DESC_EXT_NONE          = 0,
    FW_RX_DESC_EXT_LRO_ONLY,
    FW_RX_DESC_EXT_LRO_AND_OTHER,
    FW_RX_DESC_EXT_OTHER
};

#define FW_RX_DESC_DISCARD_GET(_var) \
    (((_var) & FW_RX_DESC_DISCARD_M) >> FW_RX_DESC_DISCARD_S)
#define FW_RX_DESC_DISCARD_SET(_var, _val) \
    ((_var) |= ((_val) << FW_RX_DESC_DISCARD_S))

#define FW_RX_DESC_FORWARD_GET(_var) \
    (((_var) & FW_RX_DESC_FORWARD_M) >> FW_RX_DESC_FORWARD_S)
#define FW_RX_DESC_FORWARD_SET(_var, _val) \
    ((_var) |= ((_val) << FW_RX_DESC_FORWARD_S))

#define FW_RX_DESC_INSPECT_GET(_var) \
    (((_var) & FW_RX_DESC_INSPECT_M) >> FW_RX_DESC_INSPECT_S)
#define FW_RX_DESC_INSPECT_SET(_var, _val) \
    ((_var) |= ((_val) << FW_RX_DESC_INSPECT_S))

#define FW_RX_DESC_EXT_GET(_var) \
    (((_var) & FW_RX_DESC_EXT_M) >> FW_RX_DESC_EXT_S)
#define FW_RX_DESC_EXT_SET(_var, _val) \
    ((_var) |= ((_val) << FW_RX_DESC_EXT_S))

#endif
