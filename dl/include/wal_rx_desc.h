/* 
 * Copyright (c) 2011-2012, 2014-2015 Qualcomm Atheros, Inc. 
 * All Rights Reserved. 
 * Qualcomm Atheros Confidential and Proprietary. 
 * $ATH_LICENSE_TARGET_C$
 */

#ifndef _WAL_RX_DESC__H_
#define _WAL_RX_DESC__H_


#if defined(ATH_TARGET)
#include <athdefs.h> /* A_UINT8 */
#else
#include <a_types.h> /* A_UINT8 */
#endif

/* HW rx descriptor definitions */
#if defined(ATH_TARGET) && defined(TARGET_VER)
#if defined(AR9888)
#include <hw/mac_descriptors/rx_attention.h>
#include <hw/mac_descriptors/rx_frag_info.h>
#include <hw/mac_descriptors/rx_msdu_start.h>
#include <hw/mac_descriptors/rx_msdu_end.h>
#include <hw/mac_descriptors/rx_mpdu_start.h>
#include <hw/mac_descriptors/rx_mpdu_end.h>
#include <hw/mac_descriptors/rx_ppdu_start.h>
#include <hw/mac_descriptors/rx_ppdu_end.h>
#else
#if defined(AR900B) || defined(QCA9984) || defined(IPQ4019) || defined(QCA9888) //FIXME_WIFI2 beeliner enbled by default (will be removed once we have target aware HTT)
#include <hw/interface/rx_location_info.h>
#include <hw/interface/rx_pkt_end.h>
#include <hw/interface/rx_phy_ppdu_end.h>
#include <hw/interface/rx_timing_offset.h>
#include <hw/interface/rx_location_info.h>
#endif
#include <hw/tlv/rx_attention.h>
#include <hw/tlv/rx_frag_info.h>
#include <hw/tlv/rx_msdu_start.h>
#include <hw/tlv/rx_msdu_end.h>
#include <hw/tlv/rx_mpdu_start.h>
#include <hw/tlv/rx_mpdu_end.h>
#include <hw/tlv/rx_ppdu_start.h>
#include <hw/tlv/rx_ppdu_end.h>
#endif

/*
 * This struct defines the basic descriptor information, which is
 * written by the 11ac HW MAC into the WAL's rx status descriptor
 * ring.
 */
struct hw_rx_desc_base {
    struct rx_attention  attention;
    struct rx_frag_info  frag_info;
    struct rx_mpdu_start mpdu_start;
    struct rx_msdu_start msdu_start;
    struct rx_msdu_end   msdu_end;
    struct rx_mpdu_end   mpdu_end;
    struct rx_ppdu_start ppdu_start;
    struct rx_ppdu_end   ppdu_end;
};
#endif

#include <fw_rx_desc.h>

#endif /* _WAL_RX_DESC__H_ */
