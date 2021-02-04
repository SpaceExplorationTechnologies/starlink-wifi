/* 
 * Copyright (c) 2011 Qualcomm Atheros, Inc. 
 * All Rights Reserved. 
 * Qualcomm Atheros Confidential and Proprietary. 
 */

#ifndef _WAL_RX_RING__H_
#define _WAL_RX_RING__H_

#if defined(ATH_TARGET)
#include <athdefs.h>
#include <osapi.h>   /* A_COMPILE_TIME_ASSERT */
#else
#include <a_types.h>
#include <a_osapi.h> /* A_COMPILE_TIME_ASSERT */
#endif

#if defined(AR6004)
enum WAL_RX_RING_ID {
    WAL_RX_RING_LOCAL_PKT          = 0, /* Packets for normal priority */
    WAL_RX_RINGS_MANAGED, /* 2 */

    WAL_RX_RING_REMOTE_STATUS_PKT  = 1, /* Packets for high priority */

    WAL_RX_RINGS_TOTAL
};
#else
/*
 * Logical functional separation of the rings. In low latency interfaces
 * Ring2 and Ring3 are not managed by WAL. In high latency cases these
 * "remote" rings are phyiscally in local memory but could be treated as
 * remote and WAL could help in managing them
 */
/* Note: the ring_ids managed by WAL have to be at the start. */
enum WAL_RX_RING_ID {
    WAL_RX_RING_LOCAL_STATUS       = 0, /* Full status for *ALL* packets */
    WAL_RX_RING_LOCAL_PKT          = 1, /* Packets for local stack OR offload */
    WAL_RX_RINGS_MANAGED, /* 2 */

    WAL_RX_RING_REMOTE_STATUS_PKT  = 2, /* Data + status for host processing */
    /*
     * Ring is typically unused, but could be used either to place
     * rx descriptors in a separate (fast) area of host memory than
     * the regular host memory used for data within a low-latency
     * system, or for monitor / promiscuous mode.
     */
    WAL_RX_RING_REMOTE_STATUS_FAST = 3, /* Auxilary status-only ring */
    WAL_RX_RING_REMOTE_MONITOR     = 3, /* Auxilary promiscuous monitor ring */

    WAL_RX_RINGS_TOTAL
};

/*
 * Provide a #define equivalent of WAL_RX_RING_REMOTE_STATUS_PKT.
 * This allows the ring number to be used in C pre-processor macros
 * to generate the name of the MAC DMA register used for the remote
 * status + pkt ring.
 * Provide a sanity check that the enum value and #define value match.
 */
#define WAL_RX_RING_REMOTE_STATUS_PKT_CONST 2
A_COMPILE_TIME_ASSERT(
     rx_data_ring_id_check,
     WAL_RX_RING_REMOTE_STATUS_PKT == WAL_RX_RING_REMOTE_STATUS_PKT_CONST);
#endif

#endif /* _WAL_RX_RING__H_ */
