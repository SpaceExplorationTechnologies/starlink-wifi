/*
 * Copyright (c) 2012, 2015-2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * 2012, 2015-2016 Qualcomm Atheros, Inc.
 */
//------------------------------------------------------------------------------
// Copyright (c) 2011 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

/**
 * @file htt.h
 *
 * @details the public header file of HTT layer
 */

#ifndef _HTT_H_
#define _HTT_H_

#include <htt_deps.h> /* A_UINT32, etc. */

#ifndef offsetof
#define offsetof(type, field)   ((unsigned int)(&((type *)0)->field))
#endif

/*
 * HTT version history:
 * 1.0 initial numbered version
 * 1.1 modifications to STATS messages.
 *     These modifications are not backwards compatible, but since the
 *     STATS messages themselves are non-essential (they are for debugging),
 *     the 1.1 version of the HTT message library as a whole is compatible
 *     with the 1.0 version.
 * 1.2 reset mask IE added to STATS_REQ message
 * 1.3 stat config IE added to STATS_REQ message
 *----
 * 2.0 FW rx PPDU desc added to RX_IND message
 * 2.1 Enable msdu_ext/frag_desc banking change for WIFI2.0
 * 2.2 add HTT_DBG_STATS_RESET_INFO and HTT_DBG_STATS_MAC_WDOG_INFO
 */
#define HTT_CURRENT_VERSION_MAJOR 2
#define HTT_CURRENT_VERSION_MINOR 2

#define HTT_NUM_TX_FRAG_DESC  1024

#define HTT_WIFI_IP_VERSION(x,y) ((x) == (y))

#define HTT_CHECK_SET_VAL(field, val) \
    A_ASSERT(!((val) & ~((field ## _M) >> (field ## _S))))

#define HTT_INVALID_PEER    0xffff

#define HTT_NON_QOS_TID     16
#define HTT_INVALID_TID     31

/*
 * htt_dbg_stats_type -
 * bit positions for each stats type within a stats type bitmask
 * The bitmask contains 24 bits.
 */
enum htt_dbg_stats_type {
    HTT_DBG_STATS_WAL_PDEV_TXRX      = 0,  /* bit 0 -> 0x1 */
    HTT_DBG_STATS_RX_REORDER         = 1,  /* bit 1 -> 0x2 */
    HTT_DBG_STATS_RX_RATE_INFO       = 2,  /* bit 2 -> 0x4 */
    HTT_DBG_STATS_TX_PPDU_LOG        = 3,  /* bit 3 -> 0x8 */
    HTT_DBG_STATS_TX_RATE_INFO       = 4,  /* bit 4 -> 0x10 */
    HTT_DBG_STATS_TIDQ               = 5,  /* bit 5 -> 0x20 */
    HTT_DBG_STATS_TXBF_INFO          = 6,  /* bit 6 -> 0x40 */
    HTT_DBG_STATS_SND_INFO           = 7,  /* bit 7 -> 0x80 */
    HTT_DBG_STATS_ERROR_INFO         = 8,  /* bit 8  -> 0x100 */
    HTT_DBG_STATS_TX_SELFGEN_INFO    = 9,  /* bit 9  -> 0x200 */
    HTT_DBG_STATS_TX_MU_INFO         = 10, /* bit 10 -> 0x400 */
    HTT_DBG_STATS_SIFS_RESP_INFO     = 11, /* bit 11 -> 0x800 */
    HTT_DBG_STATS_RESET_INFO         = 12, /* bit 12 -> 0x1000 */
    HTT_DBG_STATS_MAC_WDOG_INFO      = 13, /* bit 13 -> 0x2000 */
    HTT_DBG_STATS_TX_DESC_INFO       = 14, /* bit 14 -> 0x4000 */
    HTT_DBG_STATS_TX_FETCH_MGR_INFO  = 15, /* bit 15 -> 0x8000 */
    HTT_DBG_STATS_TX_PFSCHED_INFO    = 16, /* bit 16 -> 0x10000 */
    HTT_DBG_STATS_TX_PATH_STATS_INFO = 17, /* bit 17 -> 0x20000 */
    HTT_DBG_STATS_HALPHY_INFO        = 18, /* bit 18 -> 0x40000 */
    HTT_DBG_STATS_COEX_INFO          = 19, /* bit 19 -> 0x80000 */
    /* bits 20-23 currently reserved */

    /* keep this last */
    HTT_DBG_NUM_STATS
};

/*=== host -> target messages ===============================================*/

enum htt_h2t_msg_type {
    HTT_H2T_MSG_TYPE_VERSION_REQ = 0x0,
    HTT_H2T_MSG_TYPE_TX_FRM      = 0x1,
    HTT_H2T_MSG_TYPE_RX_RING_CFG = 0x2,
    HTT_H2T_MSG_TYPE_STATS_REQ   = 0x3,
    HTT_H2T_MSG_TYPE_SYNC        = 0x4,
#if defined(TEMP_AGGR_CFG)
    HTT_H2T_MSG_TYPE_AGGR_CFG    = 0x5,
#endif
    HTT_H2T_MSG_TYPE_FRAG_DESC_BANK_CFG = 0x6,
    HTT_H2T_MSG_TYPE_MGMT_TX     = 0x7,
    /*
     * skip to 0xb to maintain compatibility with
     * wlanfw_cmn.1.0.0 that uses 0x8-0xa
     */
    HTT_H2T_MSG_TYPE_TX_FETCH_RESP  = 0xb,
    /*
     * Host uses this HTT message to trigger a FW assert
     * when a WMI copy engine is stuck.
     */
    HTT_H2T_MSG_TYPE_ASSERT      = 0xc,


    /* keep this last */
    HTT_H2T_NUM_MSGS
};

/*
 * HTT host to target message type -
 * stored in bits 7:0 of the first word of the message
 */
#define HTT_H2T_MSG_TYPE_M      0xff
#define HTT_H2T_MSG_TYPE_S      0

#define HTT_H2T_MSG_TYPE_SET(word, msg_type)           \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_H2T_MSG_TYPE, msg_type); \
        (word) |= ((msg_type) << HTT_H2T_MSG_TYPE_S);  \
    } while (0)
#define HTT_H2T_MSG_TYPE_GET(word) \
    (((word) & HTT_H2T_MSG_TYPE_M) >> HTT_H2T_MSG_TYPE_S)

/**
 * @brief target -> host version number request message definition
 *
 *     |31            24|23            16|15             8|7              0|
 *     |----------------+----------------+----------------+----------------|
 *     |                     reserved                     |    msg type    |
 *     |-------------------------------------------------------------------|
 *
 * Header fields:
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as a version number request message
 *     Value: 0x0
 */

#define HTT_VER_REQ_BYTES 4

/**
 * @brief General specification of the tx frame contents
 *
 * @details
 * for efficiency, the HTT packet type values correspond
 * to the bit positions of the WAL packet type values, so the
 * translation is a simple shift operation.
 */
enum htt_pkt_type {
    htt_pkt_type_raw = 0,
    htt_pkt_type_native_wifi = 1,
    htt_pkt_type_ethernet = 2,

    /* keep this last */
    htt_pkt_num_types
};

/* TBDXXX: figure out a reasonable number */
#define HTT_HL_DATA_SVC_PIPE_DEPTH         16
#define HTT_LL_DATA_SVC_PIPE_DEPTH         40

/**
 * @brief HTT tx MSDU descriptor
 *
 * @details
 *  The HTT tx MSDU descriptor is created by the host HTT SW for each
 *  tx MSDU.  The HTT tx MSDU descriptor contains the information that
 *  the target firmware needs for the FW's tx processing, particularly
 *  for creating the HW msdu descriptor.
 *  The same HTT tx descriptor is used for HL and LL systems, though
 *  a few fields within the tx descriptor are used only by LL or
 *  only by HL.
 *  The HTT tx descriptor is defined in two manners: by a struct with
 *  bitfields, and by a series of [dword offset, bit mask, bit shift]
 *  definitions.
 *  The target should use the struct def, for simplicitly and clarity,
 *  but the host shall use the bit-mast + bit-shift defs, to be endian-
 *  neutral.  Specifically, the host shall use the get/set macros built
 *  around the mask + shift defs.
 */
#define HTT_TX_MSDU_DESC_RAW_SUBTYPE_80211_HDR_S   0
#define HTT_TX_MSDU_DESC_RAW_SUBTYPE_80211_HDR_M   0x1
#define HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_AGGR_S     1
#define HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_AGGR_M     0x2
#define HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_ENCRYPT_S  2
#define HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_ENCRYPT_M  0x4
#define HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_CLASSIFY_S 3
#define HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_CLASSIFY_M 0x8

#define HTT_TX_MSDU_DESC_SUBTYPE_DMS_S   4
#define HTT_TX_MSDU_DESC_SUBTYPE_DMS_M   0x10

PREPACK struct htt_tx_msdu_desc_t
{
    /* DWORD 0: flags and meta-data */
    A_UINT32
        msg_type: 8, /* HTT_H2T_MSG_TYPE_TX_FRM */

        /* pkt_subtype -
         * Detailed specification of the tx frame contents, extending the
         * general specification provided by pkt_type.
         * FIX THIS: ADD COMPLETE SPECS FOR THIS FIELDS VALUE, e.g.
         *     pkt_type    | pkt_subtype
         *     ==============================================================
         *     802.3       | bit 4: 0x0 - non DMS packet
         *                 |        0x1 - DMS packet
         *     ------------+-------------------------------------------------
         *     native WiFi | bit 4: 0x0 - non DMS packet
         *                 |        0x1 - DMS packet
         *     ------------+-------------------------------------------------
         *     mgmt        | 0x0 - 802.11 MAC header absent
         *                 | 0x1 - 802.11 MAC header present
         *     ------------+-------------------------------------------------
         *     raw         | bit 0: 0x0 - 802.11 MAC header absent
         *                 |        0x1 - 802.11 MAC header present
         *                 | bit 1: 0x0 - allow aggregation
         *                 |        0x1 - don't allow aggregation
         *                 | bit 2: 0x0 - perform encryption
         *                 |        0x1 - don't perform encryption
         *                 | bit 3: 0x0 - perform tx classification / queuing
         *                 |        0x1 - don't perform tx classification;
         *                 |              insert the frame into the "misc"
         *                 |              tx queue
         *                 | bit 4: 0x0 - non DMS packet
         *                 |        0x1 - DMS packet
         */
        pkt_subtype: 5,

        /* pkt_type -
         * General specification of the tx frame contents.
         * The htt_pkt_type enum should be used to specify and check the
         * value of this field.
         */
        pkt_type: 3,

        /* vdev_id -
         * ID for the vdev that is sending this tx frame.
         * For certain non-standard packet types, e.g. pkt_type == raw
         * and (pkt_subtype >> 3) == 1, this field is not relevant/valid.
         * This field is used primarily for determining where to queue
         * broadcast and multicast frames.
         */
#define HTT_TX_VDEV_ID_WORD 0
#define HTT_TX_VDEV_ID_MASK 0x3f
#define HTT_TX_VDEV_ID_SHIFT 16
        vdev_id: 6,

        #define HTT_TX_EXT_TID_DEFAULT              0
		#define HTT_TX_EXT_TID_NON_QOS_MCAST_BCAST 16
        #define HTT_TX_EXT_TID_MGMT                17
        #define HTT_TX_EXT_TID_NONPAUSE            19
        #define HTT_TX_EXT_TID_INVALID             31
        /* ext_tid -
         * The extended traffic ID.
         * If the TID is unknown, the extended TID is set to
         * HTT_TX_EXT_TID_INVALID.
         * If the tx frame is QoS data, then the extended TID has the 0-15
         * value of the QoS TID.
         * If the tx frame is non-QoS data, then the extended TID is set to
         * HTT_TX_EXT_TID_NON_QOS.
         * If the tx frame is multicast or broadcast, then the extended TID
         * is set to HTT_TX_EXT_TID_MCAST_BCAST.
         */
        ext_tid: 5,

        /* postponed -
         * This flag indicates whether the tx frame has been downloaded to
         * the target before but discarded by the target, and now is being
         * downloaded again; or if this is a new frame that is being
         * downloaded for the first time.
         * This flag allows the target to determine the correct order for
         * transmitting new vs. old frames.
         * value: 0 -> new frame, 1 -> re-send of a previously sent frame
         * This flag only applies to HL systems, since in LL systems,
         * the tx flow control is handled entirely within the target.
         */
        postponed: 1,

        /* more_in_batch -
         * This flag indicates that this frame is followed by other tx frames
         * that are in the process of being downloaded, and should arrive
         * in the target imminently.
         * This flag can be used by the target's tx scheduler to decide
         * whether to transmit the frame now, or to wait for the following
         * frames to arrive, to see if a more efficient (aggregate)
         * transmission can be formed once the subsequent frames arrive.
         * This flag only applies to HL systems, since in LL systems,
         * all tx descriptors are immediately downloaded.
         */
        more_in_batch: 1,

        /* cksum_offload -
         * This flag indicates whether checksum offload is enabled or not
         * for this frame. Target FW use this flag to turn on HW checksumming
         *  0x0 - No checksum offload
         *  0x1 - L3 header checksum only
         *  0x2 - L4 checksum only
         *  0x3 - L3 header checksum + L4 checksum
         */
        cksum_offload: 2,

        #define HTT_TX_L3_CKSUM_OFFLOAD      1
        #define HTT_TX_L4_CKSUM_OFFLOAD      2

        extention_valid: 1; /* MSDU descriptor extention valid */

        /* DWORD 1: MSDU length and ID */
#define HTT_TX_MSDU_LEN_DWORD 1
#define HTT_TX_MSDU_LEN_MASK 0xffff;
        A_UINT32
            len: 16, /* MSDU length, in bytes */
            id:  16; /* MSDU ID used to identify the MSDU to the host, and this id is used to calculate
                      * fragmentation descriptor pointer inside the target based on the base address,
                      * configured inside the target.
                      */

        /* DWORD 2: fragmentation descriptor bus address */
        /* frags_desc_ptr -
         * The fragmentation descriptor pointer tells the HW's MAC DMA
         * where the tx frame's fragments reside in memory.
         * This field only applies to LL systems, since in HL systems the
         * (degenerate single-fragment) fragmentation descriptor is created
         * within the target.
         */
        A_UINT32 frags_desc_ptr;

        /* DWORD 3: peerid */
        /*
         * Peer ID : Target can use this value to know which peer-id packet
         *           destined to.
         *           It's intended to be specified by host in case of NAWDS.
         */
        A_UINT32 peerid;

        /* Reason reserved is commented is increasing the htt structure size
         * leads to some wierd issues. Contact Raj/Kyeyoon for more info
         * A_UINT32 reserved_dword3_bits0_31;
         */
} POSTPACK;

/*Introducing new htt descriptor for mesh vap to send host specified  rates */
PREPACK struct htt_tx_mesh_msdu_desc_t
{
    /* DWORD 0: flags and meta-data */
    A_UINT32
        msg_type: 8, /* HTT_H2T_MSG_TYPE_TX_FRM */

        /* pkt_subtype -
         * Detailed specification of the tx frame contents, extending the
         * general specification provided by pkt_type.
         * FIX THIS: ADD COMPLETE SPECS FOR THIS FIELDS VALUE, e.g.
         *     pkt_type    | pkt_subtype
         *     ==============================================================
         *     802.3       | bit 0: reserved
         *                 | bit 1: reserved
         *                 | bit 2: 0x0 - use default encryption
         *                 |        0x1 - no encryption
         *                 | bit 3: reserved
         *                 | bit 4: reserved
         *     ------------+-------------------------------------------------
         *     native WiFi | n/a
         *     ------------+-------------------------------------------------
         *     mgmt        | 0x0 - 802.11 MAC header absent
         *                 | 0x1 - 802.11 MAC header present
         *     ------------+-------------------------------------------------
         *     raw         | bit 0: 0x0 - 802.11 MAC header absent
         *                 |        0x1 - 802.11 MAC header present
         *                 | bit 1: 0x0 - allow aggregation
         *                 |        0x1 - don't allow aggregation
         *                 | bit 2: 0x0 - perform encryption
         *                 |        0x1 - don't perform encryption
         *                 | bit 3: 0x0 - perform tx classification / queuing
         *                 |        0x1 - don't perform tx classification;
         *                 |              insert the frame into the "misc"
         *                 |              tx queue
         *                 | bit 4: reserved
         */
        pkt_subtype: 5,

        /* pkt_type -
         * General specification of the tx frame contents.
         * The htt_pkt_type enum should be used to specify and check the
         * value of this field.
         */
        pkt_type: 3,

        /* vdev_id -
         * ID for the vdev that is sending this tx frame.
         * For certain non-standard packet types, e.g. pkt_type == raw
         * and (pkt_subtype >> 3) == 1, this field is not relevant/valid.
         * This field is used primarily for determining where to queue
         * broadcast and multicast frames.
         */
#define HTT_TX_VDEV_ID_WORD 0
#define HTT_TX_VDEV_ID_MASK 0x3f
#define HTT_TX_VDEV_ID_SHIFT 16
        vdev_id: 6,

        #define HTT_TX_EXT_TID_DEFAULT              0
		#define HTT_TX_EXT_TID_NON_QOS_MCAST_BCAST 16
        #define HTT_TX_EXT_TID_MGMT                17
        #define HTT_TX_EXT_TID_NONPAUSE            19
        #define HTT_TX_EXT_TID_INVALID             31
        /* ext_tid -
         * The extended traffic ID.
         * If the TID is unknown, the extended TID is set to
         * HTT_TX_EXT_TID_INVALID.
         * If the tx frame is QoS data, then the extended TID has the 0-15
         * value of the QoS TID.
         * If the tx frame is non-QoS data, then the extended TID is set to
         * HTT_TX_EXT_TID_NON_QOS.
         * If the tx frame is multicast or broadcast, then the extended TID
         * is set to HTT_TX_EXT_TID_MCAST_BCAST.
         */
        ext_tid: 5,

        /* postponed -
         * This flag indicates whether the tx frame has been downloaded to
         * the target before but discarded by the target, and now is being
         * downloaded again; or if this is a new frame that is being
         * downloaded for the first time.
         * This flag allows the target to determine the correct order for
         * transmitting new vs. old frames.
         * value: 0 -> new frame, 1 -> re-send of a previously sent frame
         * This flag only applies to HL systems, since in LL systems,
         * the tx flow control is handled entirely within the target.
         */
        postponed: 1,

        /* more_in_batch -
         * This flag indicates that this frame is followed by other tx frames
         * that are in the process of being downloaded, and should arrive
         * in the target imminently.
         * This flag can be used by the target's tx scheduler to decide
         * whether to transmit the frame now, or to wait for the following
         * frames to arrive, to see if a more efficient (aggregate)
         * transmission can be formed once the subsequent frames arrive.
         * This flag only applies to HL systems, since in LL systems,
         * all tx descriptors are immediately downloaded.
         */
        more_in_batch: 1,

        /* cksum_offload -
         * This flag indicates whether checksum offload is enabled or not
         * for this frame. Target FW use this flag to turn on HW checksumming
         *  0x0 - No checksum offload
         *  0x1 - L3 header checksum only
         *  0x2 - L4 checksum only
         *  0x3 - L3 header checksum + L4 checksum
         */
        cksum_offload: 2,

        #define HTT_TX_L3_CKSUM_OFFLOAD      1
        #define HTT_TX_L4_CKSUM_OFFLOAD      2

        extention_valid: 1; /* MSDU descriptor extention valid */

        /* DWORD 1: MSDU length and ID */
#define HTT_TX_MSDU_LEN_DWORD 1
#define HTT_TX_MSDU_LEN_MASK 0xffff;
        A_UINT32
            len: 16, /* MSDU length, in bytes */
            id:  16; /* MSDU ID used to identify the MSDU to the host, and this id is used to calculate
                      * fragmentation descriptor pointer inside the target based on the base address,
                      * configured inside the target.
                      */

        /* DWORD 2: fragmentation descriptor bus address */
        /* frags_desc_ptr -
         * The fragmentation descriptor pointer tells the HW's MAC DMA
         * where the tx frame's fragments reside in memory.
         * This field only applies to LL systems, since in HL systems the
         * (degenerate single-fragment) fragmentation descriptor is created
         * within the target.
         */
        A_UINT32 frags_desc_ptr;

        /* DWORD 3: peerid */
        /*
         * Peer ID : Target can use this value to know which peer-id packet
         *           destined to.
         *           It's intended to be specified by host in case of NAWDS.
         */
        A_UINT32 peerid;

        /* Reason reserved is commented is increasing the htt structure size
         * leads to some wierd issues. Contact Raj/Kyeyoon for more info
         * A_UINT32 reserved_dword3_bits0_31;
         */
        /* Rate information */
        A_UINT32
      	   power              : 8,   /* units of the power field is dbm */
           mcs                : 4,    /* mcs = 0 ~ 9 */
           nss                : 2,    /* 0 = 1 nss, 1 = 2 nss, 2 = 3 nss, 3 = 4 nss */
           pream_type         : 2,    /* 0 = WIFI_RATECODE_PREAM_OFDM,
                                         1 = WIFI_RATECODE_PREAM_CCK,
                                         2 = WIFI_RATECODE_PREAM_HT ,
                                         3 = WIFI_RATECODE_PREAM_VHT */
           num_retries        : 4,    /* 0 ~ 15 */
           dyn_bw             : 1,    /* 0 = static bw, 1 = dynamic bw */
           bw                 : 3,    /* valid only if dyn_bw == 0 (static bw).
                                      (0 = 20 mhz, 1 = 40 mhz, 2 = 80 mhz, 3 = 160 mhz , 4 = 80+80mhz) */
           valid_power        : 1,   /*  power info field has valid power. */
           valid_rate         : 1,    /*  mcs,nss,pream_type fields have valid rates. */
           valid_num_retries  : 1,    /*  num_retries field has valid value */
           valid_dyn_bw       : 1,    /*  dyn_bw field has valid value */
           valid_bw           : 1,    /*   bw field has valid value */

           any_valid          : 1,    /* 1 : htt_tx_msdu_desc_t contains valid tx meta data */
           key_id             : 2;    /* key index 0 to 3 for per packet key rotation */
} POSTPACK;

enum WIFI_RATECODE_PREAM_TYPE {
     WIFI_RATECODE_PREAM_OFDM,
     WIFI_RATECODE_PREAM_CCK,
     WIFI_RATECODE_PREAM_HT,
     WIFI_RATECODE_PREAM_VHT,
};

/* valid_mask bit representation passed in htt_tx_msdu_desc_t */
enum {
    DATA_TX_POWER_VALID_S,
    DATA_TX_RATE_VALID_S,
    DATA_TX_NUM_RETRIES_VALID_S,
    DATA_TX_DYN_BW_VALID_S,
    DATA_TX_BW_VALID_S,
};

/* decriptor information for Management frame*/
#define HTT_MGMT_FRM_HDR_DOWNLOAD_LEN    32
extern A_UINT32 mgmt_hdr_len;
PREPACK struct htt_mgmt_tx_desc_t {
    A_UINT32    msg_type;
    A_UINT32    frag_paddr; /* DMAble address of the data */
    A_UINT32    desc_id;    /* returned to host during completion
                             * to free the meory*/
    A_UINT32    len;    /* Fragment length */
    A_UINT32    vdev_id; /* virtual device ID*/
    A_UINT8     hdr[HTT_MGMT_FRM_HDR_DOWNLOAD_LEN]; /* frm header */

    A_UINT32
            tx_params_power :           8,
            tx_params_mcs :             4,          /* mcs = 0 ~ 9; mcs, nss and pream_type should be provided at the same time */
            tx_params_nss :             2,          /* nss = 0 ~ 3 */
            tx_params_pream_type:       2,          /* OFDM, CCK, HT or VHT */
            tx_params_num_retries :     4,
            tx_params_dyn_bw :          1,          /* 0 means static bw */
            tx_params_bw :              2,          /* param valid only if tx_params_dyn_bw = 0 implying static bw */
            tx_params_valid_mask :      6,
            tx_params_frame_type :      1,          /* data: 0 */
            tx_extension_valid:         1,          /* 1 means this mgmt_tx_desc contains valid tx meta data*/
            tx_encryption_set:          1;
} POSTPACK;

/* the following validity flags are inside the tx_params_valid_mask field */
#define HTT_MGMT_TX_DESC_PARAMS_VALID_POWER      0x1
#define HTT_MGMT_TX_DESC_PARAMS_VALID_RATE       0x2  /* if set, means mcs, nss and pream_type are all valid */
#define HTT_MGMT_TX_DESC_PARAMS_VALID_RETRIES    0x4
#define HTT_MGMT_TX_DESC_PARAMS_VALID_DYN_BW     0x8
#define HTT_MGMT_TX_DESC_PARAMS_VALID_BW         0x10
#define HTT_MGMT_TX_DESC_PARAMS_VALID_RESERVED   0x20

#define HTT_MGMT_TX_DESC_PARAMS_POWER_LSB        0
#define HTT_MGMT_TX_DESC_PARAMS_POWER_MASK       0x000000ff
#define HTT_MGMT_TX_DESC_PARAMS_MCS_LSB          8
#define HTT_MGMT_TX_DESC_PARAMS_MCS_MASK         0x00000f00
#define HTT_MGMT_TX_DESC_PARAMS_NSS_LSB          12
#define HTT_MGMT_TX_DESC_PARAMS_NSS_MASK         0x00003000
#define HTT_MGMT_TX_DESC_PARAMS_PREAM_TYPE_LSB   14
#define HTT_MGMT_TX_DESC_PARAMS_PREAM_TYPE_MASK  0x0000c000
#define HTT_MGMT_TX_DESC_PARAMS_NUM_RETRIES_LSB  16
#define HTT_MGMT_TX_DESC_PARAMS_NUM_RETRIES_MASK 0x000f0000
#define HTT_MGMT_TX_DESC_PARAMS_DYN_BW_LSB       20
/* temporary - maintain an alias for backwards-compatibility */
#define HTT_MGMT_TX_DESC_PARAMS_DYN_BW \
    HTT_MGMT_TX_DESC_PARAMS_DYN_BW_LSB
#define HTT_MGMT_TX_DESC_PARAMS_DYN_BW_MASK      0x00100000
#define HTT_MGMT_TX_DESC_PARAMS_BW_LSB           21
/* temporary - maintain an alias for backwards-compatibility */
#define HTT_MGMT_TX_DESC_PARAMS_BW \
   HTT_MGMT_TX_DESC_PARAMS_BW_LSB
#define HTT_MGMT_TX_DESC_PARAMS_BW_MASK          0x00600000
#define HTT_MGMT_TX_DESC_PARAMS_VALID_LSB        23
#define HTT_MGMT_TX_DESC_PARAMS_VALID_MASK       0x1f800000
#define HTT_MGMT_TX_DESC_PARAMS_FRAME_TYPE_LSB   29
#define HTT_MGMT_TX_DESC_PARAMS_FRAME_TYPE_MASK  0x20000000
#define HTT_MGMT_TX_DESC_PARAMS_EXTENSION_LSB    30
#define HTT_MGMT_TX_DESC_PARAMS_EXTENSION_MASK   0x40000000
/* temporary - maintain an alias for backwards-compatibility */
#define HTT_MGMT_TX_DESC_PARAMS_EXTENTION_MASK \
    HTT_MGMT_TX_DESC_PARAMS_EXTENSION_MASK
#define HTT_MGMT_TX_DESC_PARAMS_ENCRYPTION_SET_LSB 31
#define HTT_MGMT_TX_DESC_PARAMS_ENCRYPTION_SET_MASK 0x80000000

#define HTT_MGMT_TX_DESC_PARAMS_VALID_GET(x, y)      ((x) & HTT_MGMT_TX_DESC_PARAMS_VALID_##y)
#define HTT_MGMT_TX_DESC_APRAMS_EXTENTION_GET(x)     ((x) & HTT_MGMT_TX_DESC_PARAMS_EXTENTION_MASK)

#define HTT_MGMT_TX_DESC_PARAMS_POWER_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_POWER_MASK) >> HTT_MGMT_TX_DESC_PARAMS_POWER_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_POWER_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_POWER_LSB)); \
    } while (0)

#define HTT_MGMT_TX_DESC_PARAMS_MCS_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_MCS_MASK) >> HTT_MGMT_TX_DESC_PARAMS_MCS_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_MCS_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_MCS_LSB)); \
    } while (0)

#define HTT_MGMT_TX_DESC_PARAMS_NSS_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_NSS_MASK) >> HTT_MGMT_TX_DESC_PARAMS_NSS_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_NSS_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_NSS_LSB)); \
    } while (0)

#define HTT_MGMT_TX_DESC_PARAMS_PREAM_TYPE_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_PREAM_TYPE_MASK) >> HTT_MGMT_TX_DESC_PARAMS_PREAM_TYPE_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_PREAM_TYPE_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_PREAM_TYPE_LSB)); \
    } while (0)

#define HTT_MGMT_TX_DESC_PARAMS_NUM_RETRIES_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_NUM_RETRIES_MASK) >> HTT_MGMT_TX_DESC_PARAMS_NUM_RETRIES_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_NUM_RETRIES_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_NUM_RETRIES_LSB)); \
    } while (0)

#define HTT_MGMT_TX_DESC_PARAMS_DYN_BW_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_DYN_BW_MASK) >> HTT_MGMT_TX_DESC_PARAMS_DYN_BW_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_DYN_BW_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_DYN_BW_LSB)); \
    } while (0)

#define HTT_MGMT_TX_DESC_PARAMS_BW_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_BW_MASK) >> HTT_MGMT_TX_DESC_PARAMS_BW_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_BW_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_BW_LSB)); \
    } while (0)

#define HTT_MGMT_TX_DESC_PARAMS_VALID_MASK_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_VALID_MASK) >> HTT_MGMT_TX_DESC_PARAMS_VALID_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_VALID_MASK_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_VALID_LSB)); \
    } while (0)

#define HTT_MGMT_TX_DESC_PARAMS_FRAME_TYPE_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_FRAME_TYPE_MASK) >> HTT_MGMT_TX_DESC_PARAMS_FRAME_TYPE_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_FRAME_TYPE_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_FRAME_TYPE_LSB)); \
    } while (0)

#define HTT_MGMT_TX_DESC_PARAMS_EXTENSION_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_EXTENSION_MASK) >> HTT_MGMT_TX_DESC_PARAMS_EXTENSION_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_EXTENSION_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_EXTENSION_LSB)); \
    } while (0)

#define HTT_MGMT_TX_DESC_PARAMS_ENCRYPTION_SET_GET(_var) \
    (((_var) & HTT_MGMT_TX_DESC_PARAMS_ENCRYPTION_SET_MASK) >> HTT_MGMT_TX_DESC_PARAMS_ENCRYPTION_SET_LSB)
#define HTT_MGMT_TX_DESC_PARAMS_ENCRYPTION_SET_SET(_var, _val)            \
    do {                                                \
        ((_var) |= ((_val) << HTT_MGMT_TX_DESC_PARAMS_ENCRYPTION_SET_LSB)); \
    } while (0)


PREPACK struct htt_mgmt_tx_compl_ind {
    A_UINT32    desc_id;
    A_UINT32    status;
    A_UINT32    ppdu_id;
    A_UINT32    ack_rssi:  8,
                reserved: 24; /* needs to be set to 0x0 */
} POSTPACK;

/**
 * @brief target -> host MGMT TX completion indication message definition
 *
 * @details
 * The following diagram shows the format of the TX completion indication sent
 * from the target to the host
 *
 *          |31    26|25|24|                                      |7        0|
 *          |----------------------------------------------------------------|
 * header:  | rsvd   | P| A|            reserved                  | msg_type |
 *          |----------------------------------------------------------------|
 * payload: |                                desc_id                         |
 *          |----------------------------------------------------------------|
 *          |                                status                          |
 *          |----------------------------------------------------------------|
 *          |                                ppdu_id                         |
 *          |----------------------------------------------------------------|
 *          |             reserved                                | ack_rssi |
 *          |----------------------------------------------------------------|
 * Where:
 *     A = ack_rssi_filled flag indicating the valid ACK-RSSI fields
 *     P = p-id flag indicating PPDU-ID is valid
 *
 * The following field definitions describe the format of the TX completion
 * indication sent from the target to the host
 * Header fields:
 * - msg_type
 *   Bits 7:0
 *   Purpose: identifies this as HTT MGMT TX completion indication
 *   Value: 0xe
 * - ack_rssi_filled
 *   Bit 24
 *   Purpose: To know ack rssi is valid or not.
 *   Value: 0 - ack rssi field is not valid.
 *          1 - ack rssi field is valid.
 * - p-id
 *   Bit 25
 *   Purpose: To know PPDU-ID is valid or not.
 *   Value: 0 - PPDU-ID field is not valid.
 *          1 - PPDU-ID field is valid.
 *
 * Payload fields:
 * - desc_id
 *   Bits 31:0
 *   Purpose: this ID is used to track the Tx buffer in host
 *   Value: 0 to "size of host MSDU descriptor pool - 1"
 * - status
 *   Bits 31:0
 *   Purpose: the TX completion status of payload fragmentations descriptors
 *   Value: could be HTT_TX_COMPL_IND_STAT_OK or HTT_TX_COMPL_IND_STAT_DISCARD
 * - PPDU-ID
 *   Bits 31:0
 *   Purpose: This ID is used to allow the host to correlate the tx_status
 *            of each packet sent through packet log DMA engine and the MSDU
 *            completion message of each packet sent through HTT DMA engine.
 *            Valid only if p-id is set.
 * - ack-rssi
 *   Bits 7:0
 *   Purpose: Carries ack rssi value of msdu.
 *            Valid only if ack_rssi_filled is set.
 *   Value: avg RSSI across all chain, value in db units w.r.t. noise floor.
 * - reserved
 *   Bits 31:8
 *   Value: Set to 0.
 */

/*
 * This SDU header size comes from the summation of the following:
 *  1. Max of:
 *     a.  Native WiFi header, for native WiFi frames: 24 bytes
 *         (frame control, duration / ID, addr1, addr2, addr3, seq ctrl, addr4)
 *     b.  802.11 header, for raw frames: 36 bytes
 *         (frame control, duration / ID, addr1, addr2, addr3, seq ctrl, addr4,
 *         QoS header, HT header)
 *     c.  802.3 header, for ethernet frames: 14 bytes
 *         (destination address, source address, ethertype / length)
 *  2. Max of:
 *     a.  IPv4 header, up through the DiffServ Code Point: 2 bytes
 *     b.  IPv6 header, up through the Traffic Class: 2 bytes
 *  3. 802.1Q VLAN header: 4 bytes
 *  4. LLC/SNAP header: 8 bytes
 */
#define HTT_TX_HDR_SIZE_NATIVE_WIFI 30
#define HTT_TX_HDR_SIZE_802_11_RAW 36
#define HTT_TX_HDR_SIZE_ETHERNET 14

#define HTT_TX_HDR_SIZE_OUTER_HDR_MAX HTT_TX_HDR_SIZE_802_11_RAW
A_COMPILE_TIME_ASSERT(
    htt_encap_hdr_size_max_check_nwifi,
    HTT_TX_HDR_SIZE_OUTER_HDR_MAX >= HTT_TX_HDR_SIZE_NATIVE_WIFI);
A_COMPILE_TIME_ASSERT(
    htt_encap_hdr_size_max_check_enet,
    HTT_TX_HDR_SIZE_OUTER_HDR_MAX >= HTT_TX_HDR_SIZE_ETHERNET);

#define HTT_HL_TX_HDR_SIZE_IP 1600    /* also include payload */
#define HTT_LL_TX_HDR_SIZE_IP 38      /* up to the end of UDP header for IPv4 case */
//#define HTT_LL_TX_HDR_SIZE_IP 16      /* up to the end of UDP header for IPv4 case */


#define HTT_TX_HDR_SIZE_802_1Q 4
#define HTT_TX_HDR_SIZE_LLC_SNAP 8


#define HTT_COMMON_TX_FRM_HDR_LEN \
     (HTT_TX_HDR_SIZE_OUTER_HDR_MAX + \
     HTT_TX_HDR_SIZE_802_1Q + \
     HTT_TX_HDR_SIZE_LLC_SNAP)

#define HTT_HL_TX_FRM_HDR_LEN \
     (HTT_COMMON_TX_FRM_HDR_LEN + HTT_HL_TX_HDR_SIZE_IP)

#define HTT_LL_TX_FRM_HDR_LEN \
     (HTT_COMMON_TX_FRM_HDR_LEN + HTT_LL_TX_HDR_SIZE_IP)

#define HTT_TX_DESC_LEN  sizeof(struct htt_tx_msdu_desc_t)

/* dword 0 */
#define HTT_TX_DESC_PKT_SUBTYPE_OFFSET_BYTES 0
#define HTT_TX_DESC_PKT_SUBTYPE_OFFSET_DWORD 0
#define HTT_TX_DESC_PKT_SUBTYPE_M      0x00001f00
#define HTT_TX_DESC_PKT_SUBTYPE_S      8

#define HTT_TX_DESC_NO_ENCRYPT_OFFSET_BYTES 0
#define HTT_TX_DESC_NO_ENCRYPT_OFFSET_DWORD 0
#define HTT_TX_DESC_NO_ENCRYPT_M      0x00000400
#define HTT_TX_DESC_NO_ENCRYPT_S      10
#define HTT_TX_DESC_PKT_TYPE_OFFSET_BYTES 0
#define HTT_TX_DESC_PKT_TYPE_OFFSET_DWORD 0
#define HTT_TX_DESC_PKT_TYPE_M         0x0000e000
#define BE_INV_HTT_TX_DESC_PKT_TYPE_M  0xFF1FFFFF
#define HTT_TX_DESC_PKT_TYPE_S         13
#define BE_HTT_TX_DESC_PKT_TYPE_S      21

#define HTT_TX_DESC_VDEV_ID_OFFSET_BYTES 0
#define HTT_TX_DESC_VDEV_ID_OFFSET_DWORD 0
#define HTT_TX_DESC_VDEV_ID_M          0x003f0000
#define HTT_TX_DESC_VDEV_ID_S          16

#define HTT_TX_DESC_EXT_TID_OFFSET_BYTES 0
#define HTT_TX_DESC_EXT_TID_OFFSET_DWORD 0
#define HTT_TX_DESC_EXT_TID_M          0x07c00000
#define HTT_TX_DESC_EXT_TID_S          22

#define HTT_TX_DESC_POSTPONED_OFFSET_BYTES 0
#define HTT_TX_DESC_POSTPONED_OFFSET_DWORD 0
#define HTT_TX_DESC_POSTPONED_M        0x08000000
#define HTT_TX_DESC_POSTPONED_S        27

#define HTT_TX_DESC_MORE_BATCH_OFFSET_BYTES 0
#define HTT_TX_DESC_MORE_BATCH_OFFSET_DWORD 0
#define HTT_TX_DESC_MORE_BATCH_M       0x10000000
#define HTT_TX_DESC_MORE_BATCH_S       28

#define HTT_TX_DESC_CKSUM_OFFLOAD_OFFSET_BYTES 0
#define HTT_TX_DESC_CKSUM_OFFLOAD_OFFSET_DWORD 0
#define HTT_TX_DESC_CKSUM_OFFLOAD_M 0x60000000
#define HTT_TX_DESC_CKSUM_OFFLOAD_S 29

/* dword 1 */
#define HTT_TX_DESC_FRM_LEN_OFFSET_BYTES 4
#define HTT_TX_DESC_FRM_LEN_OFFSET_DWORD 1
#define HTT_TX_DESC_FRM_LEN_M          0x0000ffff
#define HTT_TX_DESC_FRM_LEN_S          0

#define HTT_TX_DESC_FRM_ID_OFFSET_BYTES 4
#define HTT_TX_DESC_FRM_ID_OFFSET_DWORD 1
#define HTT_TX_DESC_FRM_ID_M           0xffff0000
#define HTT_TX_DESC_FRM_ID_S           16

/* dword 2 */
#define HTT_TX_DESC_FRAGS_DESC_PADDR_OFFSET_BYTES 8
#define HTT_TX_DESC_FRAGS_DESC_PADDR_OFFSET_DWORD 2
#define HTT_TX_DESC_FRAGS_DESC_PADDR_M 0xffffffff
#define HTT_TX_DESC_FRAGS_DESC_PADDR_S 0

/* dword 3 */
#define HTT_TX_DESC_PEERID_DESC_PADDR_OFFSET_BYTES 12
#define HTT_TX_DESC_PEERID_DESC_PADDR_OFFSET_DWORD 3
#define HTT_TX_DESC_PEERID_DESC_PADDR_M 0xffffffff
#define HTT_TX_DESC_PEERID_DESC_PADDR_S 0
#define HTT_TX_DESC_PKT_SUBTYPE_GET(_var) \
    (((_var) & HTT_TX_DESC_PKT_SUBTYPE_M) >> HTT_TX_DESC_PKT_SUBTYPE_S)
#define HTT_TX_DESC_PKT_SUBTYPE_SET(_var, _val)            \
    do {                                                   \
        HTT_CHECK_SET_VAL(HTT_TX_DESC_PKT_SUBTYPE, _val);  \
        ((_var) |= ((_val) << HTT_TX_DESC_PKT_SUBTYPE_S)); \
    } while (0)

#define HTT_TX_DESC_PKT_TYPE_GET(_var) \
    (((_var) & HTT_TX_DESC_PKT_TYPE_M) >> HTT_TX_DESC_PKT_TYPE_S)
#define HTT_TX_DESC_PKT_TYPE_SET(_var, _val)            \
    do {                                                \
        HTT_CHECK_SET_VAL(HTT_TX_DESC_PKT_TYPE, _val);  \
        ((_var) |= ((_val) << HTT_TX_DESC_PKT_TYPE_S)); \
    } while (0)

#define HTT_TX_DESC_VDEV_ID_GET(_var) \
    (((_var) & HTT_TX_DESC_VDEV_ID_M) >> HTT_TX_DESC_VDEV_ID_S)
#define HTT_TX_DESC_VDEV_ID_SET(_var, _val)            \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_TX_DESC_VDEV_ID, _val);  \
        ((_var) |= ((_val) << HTT_TX_DESC_VDEV_ID_S)); \
    } while (0)

#define HTT_TX_DESC_EXT_TID_GET(_var) \
    (((_var) & HTT_TX_DESC_EXT_TID_M) >> HTT_TX_DESC_EXT_TID_S)
#define HTT_TX_DESC_EXT_TID_SET(_var, _val)            \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_TX_DESC_EXT_TID, _val);  \
        ((_var) |= ((_val) << HTT_TX_DESC_EXT_TID_S)); \
    } while (0)

#define HTT_TX_DESC_POSTPONED_GET(_var) \
    (((_var) & HTT_TX_DESC_POSTPONED_M) >> HTT_TX_DESC_POSTPONED_S)
#define HTT_TX_DESC_POSTPONED_SET(_var, _val)            \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_TX_DESC_POSTPONED, _val);  \
        ((_var) |= ((_val) << HTT_TX_DESC_POSTPONED_S)); \
    } while (0)

#define HTT_TX_DESC_FRM_LEN_GET(_var) \
    (((_var) & HTT_TX_DESC_FRM_LEN_M) >> HTT_TX_DESC_FRM_LEN_S)
#define HTT_TX_DESC_FRM_LEN_SET(_var, _val)            \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_TX_DESC_FRM_LEN, _val);  \
        ((_var) |= ((_val) << HTT_TX_DESC_FRM_LEN_S)); \
    } while (0)

#define HTT_TX_DESC_FRM_ID_GET(_var) \
    (((_var) & HTT_TX_DESC_FRM_ID_M) >> HTT_TX_DESC_FRM_ID_S)
#define HTT_TX_DESC_FRM_ID_SET(_var, _val)            \
    do {                                              \
        HTT_CHECK_SET_VAL(HTT_TX_DESC_FRM_ID, _val);  \
        ((_var) |= ((_val) << HTT_TX_DESC_FRM_ID_S)); \
    } while (0)

#define HTT_TX_DESC_CKSUM_OFFLOAD_GET(_var) \
    (((_var) & HTT_TX_DESC_CKSUM_OFFLOAD_M) >> HTT_TX_DESC_CKSUM_OFFLOAD_S)
#define HTT_TX_DESC_CKSUM_OFFLOAD_SET(_var, _val)            \
    do {                                              \
        HTT_CHECK_SET_VAL(HTT_TX_DESC_CKSUM_OFFLOAD, _val);  \
        ((_var) |= ((_val) << HTT_TX_DESC_CKSUM_OFFLOAD_S)); \
    } while (0)

#define OL_HTT_TX_DESC_SUBTYPE(_htt_tx_desc, _sub_type)                        \
    do  {                                                                      \
        u_int32_t *word0;                                                      \
                                                                               \
        word0 = (u_int32_t *) (_htt_tx_desc);                                  \
        /* clear old value */                                                  \
        *word0 &= ~(HTT_TX_DESC_PKT_SUBTYPE_M);                                \
        /* write new value */                                                  \
        HTT_TX_DESC_PKT_SUBTYPE_SET(*word0, (_sub_type));                      \
    } while (0)

#define TX_DESC_TSO_INFO_SIZE (4 * sizeof(int))

#define HTT_TX_DESC_CLR_TSO_INFO(_var)       \
    adf_os_mem_set(_var, 0, TX_DESC_TSO_INFO_SIZE);

/**
 * @brief MAC DMA rx ring setup specification
 * @details
 *  To allow for dynamic rx ring reconfiguration and to avoid race
 *  conditions, the host SW never directly programs the MAC DMA rx ring(s)
 *  it uses.  Instead, it sends this message to the target, indicating how
 *  the rx ring used by the host should be set up and maintained.
 *  The message consists of a 4-octet header followed by 1 or 2 rx ring setup
 *  specifications.
 *
 *            |31                           16|15            8|7             0|
 *            |---------------------------------------------------------------|
 * header:    |            reserved           |   num rings   |    msg type   |
 *            |---------------------------------------------------------------|
 * payload 1: |             FW_IDX shadow register physical address           |
 *            |---------------------------------------------------------------|
 *            |                   rx ring base physical address               |
 *            |---------------------------------------------------------------|
 *            |      rx ring buffer size      |        rx ring length         |
 *            |---------------------------------------------------------------|
 *            |      FW_IDX initial value     |         enabled flags         |
 *            |---------------------------------------------------------------|
 *            |      MSDU payload offset      |     802.11 header offset      |
 *            |---------------------------------------------------------------|
 *            |        PPDU end offset        |       PPDU start offset       |
 *            |---------------------------------------------------------------|
 *            |        MPDU end offset        |       MPDU start offset       |
 *            |---------------------------------------------------------------|
 *            |        MSDU end offset        |       MSDU start offset       |
 *            |---------------------------------------------------------------|
 *            |        frag info offset       |      rx attention offset      |
 *            |---------------------------------------------------------------|
 * payload 2, if present, has the same format as payload 1
 * Header fields:
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as an rx ring configuration message
 *     Value: 0x2
 *   - NUM_RINGS
 *     Bits 15:8
 *     Purpose: indicates whether the host is setting up one rx ring or two
 *     Value: 1 or 2
 * Payload:
 *   - IDX_SHADOW_REG_PADDR
 *     Bits 31:0
 *     Value: physical address of the host's FW_IDX shadow register
 *   - RING_BASE_PADDR
 *     Bits 31:0
 *     Value: physical address of the host's rx ring
 *   - RING_LEN
 *     Bits 15:0
 *     Value: number of elements in the rx ring
 *   - RING_BUF_SZ
 *     Bits 31:16
 *     Value: size of the buffers reference by the rx ring, in byte units
 *   - ENABLED_FLAGS
 *     Bits 15:0
 *     Value: 1-bit flags to show whether different rx fields are enabled
 *         bit  0: 802.11 header enabled (1) or disabled (0)
 *         bit  1: MSDU payload  enabled (1) or disabled (0)
 *         bit  2: PPDU start    enabled (1) or disabled (0)
 *         bit  3: PPDU end      enabled (1) or disabled (0)
 *         bit  4: MPDU start    enabled (1) or disabled (0)
 *         bit  5: MPDU end      enabled (1) or disabled (0)
 *         bit  6: MSDU start    enabled (1) or disabled (0)
 *         bit  7: MSDU end      enabled (1) or disabled (0)
 *         bit  8: rx attention  enabled (1) or disabled (0)
 *         bit  9: frag info     enabled (1) or disabled (0)
 *         bit 10: unicast rx    enabled (1) or disabled (0)
 *         bit 11: multicast rx  enabled (1) or disabled (0)
 *         bit 12: ctrl rx       enabled (1) or disabled (0)
 *         bit 13: mgmt rx       enabled (1) or disabled (0)
 *         bit 14: null rx       enabled (1) or disabled (0)
 *         bit 15: phy data rx   enabled (1) or disabled (0)
 *   - IDX_INIT_VAL
 *     Bits 31:16
 *     Purpose: Specify the initial value for the FW_IDX.
 *     Value: the number of buffers initially present in the host's rx ring
 *   - OFFSET_802_11_HDR
 *     Bits 15:0
 *     Value: offset in QUAD-bytes of 802.11 header from the buffer start
 *   - OFFSET_MSDU_PAYLOAD
 *     Bits 31:16
 *     Value: offset in QUAD-bytes of MSDU payload from the buffer start
 *   - OFFSET_PPDU_START
 *     Bits 15:0
 *     Value: offset in QUAD-bytes of PPDU start rx desc from the buffer start
 *   - OFFSET_PPDU_END
 *     Bits 31:16
 *     Value: offset in QUAD-bytes of PPDU end rx desc from the buffer start
 *   - OFFSET_MPDU_START
 *     Bits 15:0
 *     Value: offset in QUAD-bytes of MPDU start rx desc from the buffer start
 *   - OFFSET_MPDU_END
 *     Bits 31:16
 *     Value: offset in QUAD-bytes of MPDU end rx desc from the buffer start
 *   - OFFSET_MSDU_START
 *     Bits 15:0
 *     Value: offset in QUAD-bytes of MSDU start rx desc from the buffer start
 *   - OFFSET_MSDU_END
 *     Bits 31:16
 *     Value: offset in QUAD-bytes of MSDU end rx desc from the buffer start
 *   - OFFSET_RX_ATTN
 *     Bits 15:0
 *     Value: offset in QUAD-bytes of rx attention word from the buffer start
 *   - OFFSET_FRAG_INFO
 *     Bits 31:16
 *     Value: offset in QUAD-bytes of frag info table
 */
/* header fields */
#define HTT_RX_RING_CFG_NUM_RINGS_M      0xff00
#define HTT_RX_RING_CFG_NUM_RINGS_S      8
/* payload fields */
#define HTT_RX_RING_CFG_IDX_SHADOW_REG_PADDR_M 0xffffffff
#define HTT_RX_RING_CFG_IDX_SHADOW_REG_PADDR_S 0
#define HTT_RX_RING_CFG_BASE_PADDR_M      0xffffffff
#define HTT_RX_RING_CFG_BASE_PADDR_S      0
#define HTT_RX_RING_CFG_LEN_M             0xffff
#define HTT_RX_RING_CFG_LEN_S             0
#define HTT_RX_RING_CFG_BUF_SZ_M          0xffff0000
#define HTT_RX_RING_CFG_BUF_SZ_S          16
#define HTT_RX_RING_CFG_ENABLED_802_11_HDR_M   0x1
#define HTT_RX_RING_CFG_ENABLED_802_11_HDR_S   0
#define HTT_RX_RING_CFG_ENABLED_MSDU_PAYLD_M   0x2
#define HTT_RX_RING_CFG_ENABLED_MSDU_PAYLD_S   1
#define HTT_RX_RING_CFG_ENABLED_PPDU_START_M   0x4
#define HTT_RX_RING_CFG_ENABLED_PPDU_START_S   2
#define HTT_RX_RING_CFG_ENABLED_PPDU_END_M     0x8
#define HTT_RX_RING_CFG_ENABLED_PPDU_END_S     3
#define HTT_RX_RING_CFG_ENABLED_MPDU_START_M   0x10
#define HTT_RX_RING_CFG_ENABLED_MPDU_START_S   4
#define HTT_RX_RING_CFG_ENABLED_MPDU_END_M     0x20
#define HTT_RX_RING_CFG_ENABLED_MPDU_END_S     5
#define HTT_RX_RING_CFG_ENABLED_MSDU_START_M   0x40
#define HTT_RX_RING_CFG_ENABLED_MSDU_START_S   6
#define HTT_RX_RING_CFG_ENABLED_MSDU_END_M     0x80
#define HTT_RX_RING_CFG_ENABLED_MSDU_END_S     7
#define HTT_RX_RING_CFG_ENABLED_RX_ATTN_M      0x100
#define HTT_RX_RING_CFG_ENABLED_RX_ATTN_S      8
#define HTT_RX_RING_CFG_ENABLED_FRAG_INFO_M    0x200
#define HTT_RX_RING_CFG_ENABLED_FRAG_INFO_S    9
#define HTT_RX_RING_CFG_ENABLED_UCAST_M        0x400
#define HTT_RX_RING_CFG_ENABLED_UCAST_S        10
#define HTT_RX_RING_CFG_ENABLED_MCAST_M        0x800
#define HTT_RX_RING_CFG_ENABLED_MCAST_S        11
#define HTT_RX_RING_CFG_ENABLED_CTRL_M         0x1000
#define HTT_RX_RING_CFG_ENABLED_CTRL_S         12
#define HTT_RX_RING_CFG_ENABLED_MGMT_M         0x2000
#define HTT_RX_RING_CFG_ENABLED_MGMT_S         13
#define HTT_RX_RING_CFG_ENABLED_NULL_M         0x4000
#define HTT_RX_RING_CFG_ENABLED_NULL_S         14
#define HTT_RX_RING_CFG_ENABLED_PHY_M          0x8000
#define HTT_RX_RING_CFG_ENABLED_PHY_S          15
#define HTT_RX_RING_CFG_IDX_INIT_VAL_M         0xffff0000
#define HTT_RX_RING_CFG_IDX_INIT_VAL_S         16
#define HTT_RX_RING_CFG_OFFSET_802_11_HDR_M    0xffff
#define HTT_RX_RING_CFG_OFFSET_802_11_HDR_S    0
#define HTT_RX_RING_CFG_OFFSET_MSDU_PAYLD_M    0xffff0000
#define HTT_RX_RING_CFG_OFFSET_MSDU_PAYLD_S    16
#define HTT_RX_RING_CFG_OFFSET_PPDU_START_M    0xffff
#define HTT_RX_RING_CFG_OFFSET_PPDU_START_S    0
#define HTT_RX_RING_CFG_OFFSET_PPDU_END_M      0xffff0000
#define HTT_RX_RING_CFG_OFFSET_PPDU_END_S      16
#define HTT_RX_RING_CFG_OFFSET_MPDU_START_M    0xffff
#define HTT_RX_RING_CFG_OFFSET_MPDU_START_S    0
#define HTT_RX_RING_CFG_OFFSET_MPDU_END_M      0xffff0000
#define HTT_RX_RING_CFG_OFFSET_MPDU_END_S      16
#define HTT_RX_RING_CFG_OFFSET_MSDU_START_M    0xffff
#define HTT_RX_RING_CFG_OFFSET_MSDU_START_S    0
#define HTT_RX_RING_CFG_OFFSET_MSDU_END_M      0xffff0000
#define HTT_RX_RING_CFG_OFFSET_MSDU_END_S      16
#define HTT_RX_RING_CFG_OFFSET_RX_ATTN_M       0xffff
#define HTT_RX_RING_CFG_OFFSET_RX_ATTN_S       0
#define HTT_RX_RING_CFG_OFFSET_FRAG_INFO_M     0xffff0000
#define HTT_RX_RING_CFG_OFFSET_FRAG_INFO_S     16

#define HTT_RX_RING_CFG_HDR_BYTES 4
#define HTT_RX_RING_CFG_PAYLD_BYTES 36
#define HTT_RX_RING_CFG_BYTES(num_rings) \
    (HTT_RX_RING_CFG_HDR_BYTES + (num_rings) * HTT_RX_RING_CFG_PAYLD_BYTES)


#define HTT_RX_RING_CFG_NUM_RINGS_GET(_var) \
    (((_var) & HTT_RX_RING_CFG_NUM_RINGS_M) >> HTT_RX_RING_CFG_NUM_RINGS_S)
#define HTT_RX_RING_CFG_NUM_RINGS_SET(_var, _val)            \
    do {                                                     \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_NUM_RINGS, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_NUM_RINGS_S)); \
    } while (0)

/* degenerate case for 32-bit fields */
#define HTT_RX_RING_CFG_IDX_SHADOW_REG_PADDR_GET(_var) (_var)
#define HTT_RX_RING_CFG_IDX_SHADOW_REG_PADDR_SET(_var, _val) (_var) = (_val)

/* degenerate case for 32-bit fields */
#define HTT_RX_RING_CFG_BASE_PADDR_GET(_var) (_var)
#define HTT_RX_RING_CFG_BASE_PADDR_SET(_var, _val) (_var) = (_val)

#define HTT_RX_RING_CFG_LEN_GET(_var) \
    (((_var) & HTT_RX_RING_CFG_LEN_M) >> HTT_RX_RING_CFG_LEN_S)
#define HTT_RX_RING_CFG_LEN_SET(_var, _val)            \
    do {                                                    \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_LEN, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_LEN_S)); \
    } while (0)

#define HTT_RX_RING_CFG_BUF_SZ_GET(_var) \
    (((_var) & HTT_RX_RING_CFG_BUF_SZ_M) >> HTT_RX_RING_CFG_BUF_SZ_S)
#define HTT_RX_RING_CFG_BUF_SZ_SET(_var, _val)            \
    do {                                                       \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_BUF_SZ, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_BUF_SZ_S)); \
    } while (0)

#define HTT_RX_RING_CFG_IDX_INIT_VAL_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_IDX_INIT_VAL_M) >> \
    HTT_RX_RING_CFG_IDX_INIT_VAL_S)
#define HTT_RX_RING_CFG_IDX_INIT_VAL_SET(_var, _val)            \
    do {                                                        \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_IDX_INIT_VAL, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_IDX_INIT_VAL_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_802_11_HDR_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_802_11_HDR_M) >> \
    HTT_RX_RING_CFG_ENABLED_802_11_HDR_S)
#define HTT_RX_RING_CFG_ENABLED_802_11_HDR_SET(_var, _val)            \
    do {                                                              \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_802_11_HDR, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_802_11_HDR_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_MSDU_PAYLD_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_MSDU_PAYLD_M) >> \
    HTT_RX_RING_CFG_ENABLED_MSDU_PAYLD_S)
#define HTT_RX_RING_CFG_ENABLED_MSDU_PAYLD_SET(_var, _val)            \
    do {                                                              \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_MSDU_PAYLD, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_MSDU_PAYLD_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_PPDU_START_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_PPDU_START_M) >> \
    HTT_RX_RING_CFG_ENABLED_PPDU_START_S)
#define HTT_RX_RING_CFG_ENABLED_PPDU_START_SET(_var, _val)            \
    do {                                                              \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_PPDU_START, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_PPDU_START_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_PPDU_END_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_PPDU_END_M) >> \
    HTT_RX_RING_CFG_ENABLED_PPDU_END_S)
#define HTT_RX_RING_CFG_ENABLED_PPDU_END_SET(_var, _val)            \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_PPDU_END, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_PPDU_END_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_MPDU_START_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_MPDU_START_M) >> \
    HTT_RX_RING_CFG_ENABLED_MPDU_START_S)
#define HTT_RX_RING_CFG_ENABLED_MPDU_START_SET(_var, _val)            \
    do {                                                              \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_MPDU_START, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_MPDU_START_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_MPDU_END_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_MPDU_END_M) >> \
    HTT_RX_RING_CFG_ENABLED_MPDU_END_S)
#define HTT_RX_RING_CFG_ENABLED_MPDU_END_SET(_var, _val)            \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_MPDU_END, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_MPDU_END_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_MSDU_START_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_MSDU_START_M) >> \
    HTT_RX_RING_CFG_ENABLED_MSDU_START_S)
#define HTT_RX_RING_CFG_ENABLED_MSDU_START_SET(_var, _val)            \
    do {                                                              \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_MSDU_START, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_MSDU_START_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_MSDU_END_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_MSDU_END_M) >> \
    HTT_RX_RING_CFG_ENABLED_MSDU_END_S)
#define HTT_RX_RING_CFG_ENABLED_MSDU_END_SET(_var, _val)            \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_MSDU_END, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_MSDU_END_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_RX_ATTN_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_RX_ATTN_M) >> \
    HTT_RX_RING_CFG_ENABLED_RX_ATTN_S)
#define HTT_RX_RING_CFG_ENABLED_RX_ATTN_SET(_var, _val)            \
    do {                                                           \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_RX_ATTN, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_RX_ATTN_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_FRAG_INFO_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_FRAG_INFO_M) >> \
    HTT_RX_RING_CFG_ENABLED_FRAG_INFO_S)
#define HTT_RX_RING_CFG_ENABLED_FRAG_INFO_SET(_var, _val)            \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_FRAG_INFO, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_FRAG_INFO_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_UCAST_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_UCAST_M) >> \
    HTT_RX_RING_CFG_ENABLED_UCAST_S)
#define HTT_RX_RING_CFG_ENABLED_UCAST_SET(_var, _val)            \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_UCAST, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_UCAST_S)); \
    } while (0)

#define HTT_RX_RING_CFG_ENABLED_MCAST_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_MCAST_M) >> \
    HTT_RX_RING_CFG_ENABLED_MCAST_S)
#define HTT_RX_RING_CFG_ENABLED_MCAST_SET(_var, _val)            \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_MCAST, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_MCAST_S)); \
    } while (0)
#define HTT_RX_RING_CFG_ENABLED_CTRL_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_CTRL_M) >> \
    HTT_RX_RING_CFG_ENABLED_CTRL_S)
#define HTT_RX_RING_CFG_ENABLED_CTRL_SET(_var, _val)            \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_CTRL, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_CTRL_S)); \
    } while (0)
#define HTT_RX_RING_CFG_ENABLED_MGMT_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_MGMT_M) >> \
    HTT_RX_RING_CFG_ENABLED_MGMT_S)
#define HTT_RX_RING_CFG_ENABLED_MGMT_SET(_var, _val)            \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_MGMT, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_MGMT_S)); \
    } while (0)
#define HTT_RX_RING_CFG_ENABLED_NULL_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_NULL_M) >> \
    HTT_RX_RING_CFG_ENABLED_NULL_S)
#define HTT_RX_RING_CFG_ENABLED_NULL_SET(_var, _val)            \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_NULL, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_NULL_S)); \
    } while (0)
#define HTT_RX_RING_CFG_ENABLED_PHY_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_ENABLED_PHY_M) >> \
    HTT_RX_RING_CFG_ENABLED_PHY_S)
#define HTT_RX_RING_CFG_ENABLED_PHY_SET(_var, _val)            \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_ENABLED_PHY, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_ENABLED_PHY_S)); \
    } while (0)

#define HTT_RX_RING_CFG_OFFSET_802_11_HDR_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_OFFSET_802_11_HDR_M) >> \
    HTT_RX_RING_CFG_OFFSET_802_11_HDR_S)
#define HTT_RX_RING_CFG_OFFSET_802_11_HDR_SET(_var, _val)            \
    do {                                                                  \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_OFFSET_802_11_HDR, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_OFFSET_802_11_HDR_S)); \
    } while (0)

#define HTT_RX_RING_CFG_OFFSET_MSDU_PAYLD_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_OFFSET_MSDU_PAYLD_M) >> \
    HTT_RX_RING_CFG_OFFSET_MSDU_PAYLD_S)
#define HTT_RX_RING_CFG_OFFSET_MSDU_PAYLD_SET(_var, _val)            \
    do {                                                                  \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_OFFSET_MSDU_PAYLD, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_OFFSET_MSDU_PAYLD_S)); \
    } while (0)

#define HTT_RX_RING_CFG_OFFSET_PPDU_START_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_OFFSET_PPDU_START_M) >> \
    HTT_RX_RING_CFG_OFFSET_PPDU_START_S)
#define HTT_RX_RING_CFG_OFFSET_PPDU_START_SET(_var, _val)            \
    do {                                                                  \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_OFFSET_PPDU_START, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_OFFSET_PPDU_START_S)); \
    } while (0)

#define HTT_RX_RING_CFG_OFFSET_PPDU_END_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_OFFSET_PPDU_END_M) >> \
    HTT_RX_RING_CFG_OFFSET_PPDU_END_S)
#define HTT_RX_RING_CFG_OFFSET_PPDU_END_SET(_var, _val)            \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_OFFSET_PPDU_END, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_OFFSET_PPDU_END_S)); \
    } while (0)

#define HTT_RX_RING_CFG_OFFSET_MPDU_START_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_OFFSET_MPDU_START_M) >> \
    HTT_RX_RING_CFG_OFFSET_MPDU_START_S)
#define HTT_RX_RING_CFG_OFFSET_MPDU_START_SET(_var, _val)            \
    do {                                                                  \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_OFFSET_MPDU_START, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_OFFSET_MPDU_START_S)); \
    } while (0)

#define HTT_RX_RING_CFG_OFFSET_MPDU_END_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_OFFSET_MPDU_END_M) >> \
    HTT_RX_RING_CFG_OFFSET_MPDU_END_S)
#define HTT_RX_RING_CFG_OFFSET_MPDU_END_SET(_var, _val)            \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_OFFSET_MPDU_END, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_OFFSET_MPDU_END_S)); \
    } while (0)

#define HTT_RX_RING_CFG_OFFSET_MSDU_START_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_OFFSET_MSDU_START_M) >> \
    HTT_RX_RING_CFG_OFFSET_MSDU_START_S)
#define HTT_RX_RING_CFG_OFFSET_MSDU_START_SET(_var, _val)            \
    do {                                                                  \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_OFFSET_MSDU_START, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_OFFSET_MSDU_START_S)); \
    } while (0)

#define HTT_RX_RING_CFG_OFFSET_MSDU_END_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_OFFSET_MSDU_END_M) >> \
    HTT_RX_RING_CFG_OFFSET_MSDU_END_S)
#define HTT_RX_RING_CFG_OFFSET_MSDU_END_SET(_var, _val)            \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_OFFSET_MSDU_END, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_OFFSET_MSDU_END_S)); \
    } while (0)

#define HTT_RX_RING_CFG_OFFSET_RX_ATTN_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_OFFSET_RX_ATTN_M) >> \
    HTT_RX_RING_CFG_OFFSET_RX_ATTN_S)
#define HTT_RX_RING_CFG_OFFSET_RX_ATTN_SET(_var, _val)            \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_OFFSET_RX_ATTN, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_OFFSET_RX_ATTN_S)); \
    } while (0)

#define HTT_RX_RING_CFG_OFFSET_FRAG_INFO_GET(_var)    \
    (((_var) & HTT_RX_RING_CFG_OFFSET_FRAG_INFO_M) >> \
    HTT_RX_RING_CFG_OFFSET_FRAG_INFO_S)
#define HTT_RX_RING_CFG_OFFSET_FRAG_INFO_SET(_var, _val)            \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_RING_CFG_OFFSET_FRAG_INFO, _val);  \
        ((_var) |= ((_val) << HTT_RX_RING_CFG_OFFSET_FRAG_INFO_S)); \
    } while (0)

/**
 * @brief host -> target FW statistics retrieve
 *
 * @details
 * The following field definitions describe the format of the HTT host
 * to target FW stats retrieve message. The message specifies the type of
 * stats host wants to retrieve.
 *
 * |31          24|23          16|15           8|7            0|
 * |-----------------------------------------------------------|
 * |        stats types request bitmask         |   msg type   |
 * |-----------------------------------------------------------|
 * |         stats types reset bitmask          | reserved  |EF|
 * |-----------------------------------------------------------|
 * |  stats type  |               config value                 |
 * |-----------------------------------------------------------|
 * |                        cookie LSBs                        |
 * |-----------------------------------------------------------|
 * |                        cookie MSBs                        |
 * |-----------------------------------------------------------|
 * :          reserved (extension fields)       :    VAP ID    :
 * '- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -'
 * Header fields:
 *  - MSG_TYPE
 *    Bits 7:0
 *    Purpose: identifies this is a stats upload request message
 *    Value: 0x3
 *  - UPLOAD_TYPES
 *    Bits 31:8
 *    Purpose: identifies which types of FW statistics to upload
 *    Value: mask with bits set in positions defined by htt_dbg_stats_type
 *  - Extension Flag
 *    Bit 0
 *    Purpose: indicate whether a message extension is present (bytes 20-23)
 *    Value: 0 -> no extension is present (the message is 20 bytes)
 *           1 -> an extension is present (the message is 24 bytes)
 *  - RESET_TYPES
 *    Bits 31:8
 *    Purpose: identifies which types of FW statistics to reset
 *    Value: mask with bits set in positions defined by htt_dbg_stats_type
 *  - CFG_VAL
 *    Bits 23:0
 *    Purpose: give an opaque configuration value to the specified stats type
 *    Value: stats-type specific configuration value
 *        if stats type == tx PPDU log, then CONFIG_VAL has the format:
 *            bits  7:0  - how many per-MPDU byte counts to include in a record
 *            bits 15:8  - how many per-MPDU MSDU counts to include in a record
 *            bits 23:16 - how many per-MSDU byte counts to include in a record
 *  - CFG_STAT_TYPE
 *    Bits 31:24
 *    Purpose: specify which stats type (if any) the config value applies to
 *    Value: htt_dbg_stats_type value, or 0xff if the message doesn't have
 *        a valid configuration specification
 *  - COOKIE_LSBS
 *    Bits 31:0
 *    Purpose: Provide a mechanism to match a target->host stats confirmation
 *        message with its preceding host->target stats request message.
 *    Value: LSBs of the opaque cookie specified by the host-side requestor
 *  - COOKIE_MSBS
 *    Bits 31:0
 *    Purpose: Provide a mechanism to match a target->host stats confirmation
 *        message with its preceding host->target stats request message.
 *    Value: MSBs of the opaque cookie specified by the host-side requestor
 *  - VAP_ID
 *    Bits 7:0
 *    Purpose: If stats are being requested for a single VAP, then this field
 *        specifies which VAP's stats are desired.
 *        NOTE: Rather than directly holding VAP ID, this field holds
 *        VAP ID + 1.  This offset-by-one is used to distinguish between
 *        a VAP ID of 0 (in which case this field will contain the value 1),
 *        versus an invalid / unspecified VAP ID (in which case this field
 *        will contain the value 0, and consolidated stats for all VAPs will
 *        be reported).
 *    Value: 0  for invalid / unspecified VAP ID, or else VAP ID + 1
 */

#define HTT_H2T_STATS_REQ_MSG_SZ                    20 /* bytes */
#define HTT_H2T_STATS_REQ_MSG_EXTN1_SZ              24 /* bytes */

#define HTT_H2T_STATS_HEADER_EXTN_FLG_M                 0x00000001
#define HTT_H2T_STATS_HEADER_EXTN_FLG_S                 0
#define HTT_H2T_STATS_HEADER_EXTN_FLG_SET(word, val)           \
    do {                                                       \
        HTT_CHECK_SET_VAL(HTT_H2T_STATS_HEADER_EXTN_FLG, val); \
        (word) |= ((val) << HTT_H2T_STATS_HEADER_EXTN_FLG_S);  \
    } while (0)
#define HTT_H2T_STATS_HEADER_EXTN_FLG_GET(word) \
    (((word) & HTT_H2T_STATS_HEADER_EXTN_FLG_M) >> HTT_H2T_STATS_HEADER_EXTN_FLG_S)

#define HTT_H2T_STATS_REQ_VAP_ID_M     0x000000ff
#define HTT_H2T_STATS_REQ_VAP_ID_S     0

#define HTT_H2T_STATS_REQ_VAP_ID_SET(word, vap_id)           \
    do {                                                     \
        HTT_CHECK_SET_VAL(HTT_H2T_STATS_REQ_VAP_ID, vap_id); \
        (word) |= ((vap_id) << HTT_H2T_STATS_REQ_VAP_ID_S);  \
    } while (0)
#define HTT_H2T_STATS_REQ_VAP_ID_GET(word) \
    (((word) & HTT_H2T_STATS_REQ_VAP_ID_M) >> HTT_H2T_STATS_REQ_VAP_ID_S)

#define HTT_H2T_STATS_REQ_CFG_STAT_TYPE_INVALID     0xff

#define HTT_H2T_STATS_REQ_UPLOAD_TYPES_M            0xffffff00
#define HTT_H2T_STATS_REQ_UPLOAD_TYPES_S            8

#define HTT_H2T_STATS_REQ_RESET_TYPES_M             0xffffff00
#define HTT_H2T_STATS_REQ_RESET_TYPES_S             8

#define HTT_H2T_STATS_REQ_CFG_VAL_M                 0x00ffffff
#define HTT_H2T_STATS_REQ_CFG_VAL_S                 0

#define HTT_H2T_STATS_REQ_CFG_STAT_TYPE_M           0xff000000
#define HTT_H2T_STATS_REQ_CFG_STAT_TYPE_S           24

#define HTT_H2T_STATS_REQ_UPLOAD_TYPES_GET(_var)     \
    (((_var) & HTT_H2T_STATS_REQ_UPLOAD_TYPES_M) >>  \
     HTT_H2T_STATS_REQ_UPLOAD_TYPES_S)
#define HTT_H2T_STATS_REQ_UPLOAD_TYPES_SET(_var, _val)            \
    do {                                                          \
        HTT_CHECK_SET_VAL(HTT_H2T_STATS_REQ_UPLOAD_TYPES, _val);  \
        ((_var) |= ((_val) << HTT_H2T_STATS_REQ_UPLOAD_TYPES_S)); \
    } while (0)

#define HTT_H2T_STATS_REQ_RESET_TYPES_GET(_var)     \
    (((_var) & HTT_H2T_STATS_REQ_RESET_TYPES_M) >>  \
     HTT_H2T_STATS_REQ_RESET_TYPES_S)
#define HTT_H2T_STATS_REQ_RESET_TYPES_SET(_var, _val)            \
    do {                                                         \
        HTT_CHECK_SET_VAL(HTT_H2T_STATS_REQ_RESET_TYPES, _val);  \
        ((_var) |= ((_val) << HTT_H2T_STATS_REQ_RESET_TYPES_S)); \
    } while (0)

#define HTT_H2T_STATS_REQ_CFG_VAL_GET(_var)     \
    (((_var) & HTT_H2T_STATS_REQ_CFG_VAL_M) >>  \
     HTT_H2T_STATS_REQ_CFG_VAL_S)
#define HTT_H2T_STATS_REQ_CFG_VAL_SET(_var, _val)            \
    do {                                                         \
        HTT_CHECK_SET_VAL(HTT_H2T_STATS_REQ_CFG_VAL, _val);  \
        ((_var) |= ((_val) << HTT_H2T_STATS_REQ_CFG_VAL_S)); \
    } while (0)

#define HTT_H2T_STATS_REQ_CFG_STAT_TYPE_GET(_var)     \
    (((_var) & HTT_H2T_STATS_REQ_CFG_STAT_TYPE_M) >>  \
     HTT_H2T_STATS_REQ_CFG_STAT_TYPE_S)
#define HTT_H2T_STATS_REQ_CFG_STAT_TYPE_SET(_var, _val)            \
    do {                                                         \
        HTT_CHECK_SET_VAL(HTT_H2T_STATS_REQ_CFG_STAT_TYPE, _val);  \
        ((_var) |= ((_val) << HTT_H2T_STATS_REQ_CFG_STAT_TYPE_S)); \
    } while (0)

/**
 * @brief host -> target HTT out-of-band sync request
 *
 * @details
 *  The HTT SYNC tells the target to suspend processing of subsequent
 *  HTT host-to-target messages until some other target agent locally
 *  informs the target HTT FW that the current sync counter is equal to
 *  or greater than (in a modulo sense) the sync counter specified in
 *  the SYNC message.
 *  This allows other host-target components to synchronize their operation
 *  with HTT, e.g. to ensure that tx frames don't get transmitted until a
 *  security key has been downloaded to and activated by the target.
 *  In the absence of any explicit synchronization counter value
 *  specification, the target HTT FW will use zero as the default current
 *  sync value.
 *
 * |31          24|23          16|15           8|7            0|
 * |-----------------------------------------------------------|
 * |          reserved           |  sync count  |   msg type   |
 * |-----------------------------------------------------------|
 * Header fields:
 *  - MSG_TYPE
 *    Bits 7:0
 *    Purpose: identifies this as a sync message
 *    Value: 0x4
 *  - SYNC_COUNT
 *    Bits 15:8
 *    Purpose: specifies what sync value the HTT FW will wait for from
 *        an out-of-band specification to resume its operation
 *    Value: in-band sync counter value to compare against the out-of-band
 *        counter spec.
 *        The HTT target FW will suspend its host->target message processing
 *        as long as
 *        0 < (in-band sync counter - out-of-band sync counter) & 0xff < 128
 */

#define HTT_H2T_SYNC_MSG_SZ                 4

#define HTT_H2T_SYNC_COUNT_M                0x0000ff00
#define HTT_H2T_SYNC_COUNT_S                8

#define HTT_H2T_SYNC_COUNT_GET(_var)        \
    (((_var) & HTT_H2T_SYNC_COUNT_M) >>     \
     HTT_H2T_SYNC_COUNT_S)
#define HTT_H2T_SYNC_COUNT_SET(_var, _val)            \
    do {                                              \
        HTT_CHECK_SET_VAL(HTT_H2T_SYNC_COUNT, _val);  \
        ((_var) |= ((_val) << HTT_H2T_SYNC_COUNT_S)); \
    } while (0)


#if defined(TEMP_AGGR_CFG)
/**
 * @brief HTT aggregation configuration
 */
#define HTT_AGGR_CFG_MSG_SZ                     8

#define HTT_AGGR_CFG_MAX_NUM_AMPDU_SUBFRM_M     0xff00
#define HTT_AGGR_CFG_MAX_NUM_AMPDU_SUBFRM_S     8
#define HTT_AGGR_CFG_MAX_NUM_AMSDU_SUBFRM_M     0x1f0000
#define HTT_AGGR_CFG_MAX_NUM_AMSDU_SUBFRM_S     16

#define HTT_AGGR_CFG_MAX_NUM_AMPDU_SUBFRM_GET(_var) \
    (((_var) & HTT_AGGR_CFG_MAX_NUM_AMPDU_SUBFRM_M) >> \
     HTT_AGGR_CFG_MAX_NUM_AMPDU_SUBFRM_S)
#define HTT_AGGR_CFG_MAX_NUM_AMPDU_SUBFRM_SET(_var, _val) \
    do {                                                     \
        HTT_CHECK_SET_VAL(HTT_AGGR_CFG_MAX_NUM_AMPDU_SUBFRM, _val);  \
        ((_var) |= ((_val) << HTT_AGGR_CFG_MAX_NUM_AMPDU_SUBFRM_S)); \
    } while (0)

#define HTT_AGGR_CFG_MAX_NUM_AMSDU_SUBFRM_GET(_var) \
    (((_var) & HTT_AGGR_CFG_MAX_NUM_AMSDU_SUBFRM_M) >> \
     HTT_AGGR_CFG_MAX_NUM_AMSDU_SUBFRM_S)
#define HTT_AGGR_CFG_MAX_NUM_AMSDU_SUBFRM_SET(_var, _val) \
    do {                                                     \
        HTT_CHECK_SET_VAL(HTT_AGGR_CFG_MAX_NUM_AMSDU_SUBFRM, _val);  \
        ((_var) |= ((_val) << HTT_AGGR_CFG_MAX_NUM_AMSDU_SUBFRM_S)); \
    } while (0)
#endif


/**
 * @brief host -> target Fetch Response
 *
 * @details
 * The following field definitions describe the format of the HTT host
 * to target fetch Response message.
 * The message contains Response ID that is to be replayed by the target
 * in the Fetch Confirmation message, followed by the fetch sequence
 * number that was sent in the HTT_T2H_MSG_TYPE_TX_FETCH_IND message,
 * followed by the number of fetch records that this response message
 * contains, followed by the dialog token that was sent in the
 * HTT_T2H_MSG_TYPE_TX_FETCH_IND message.
 * The fields following the Dialog Token field, are identical to the
 * HTT_T2H_MSG_TYPE_TX_FETCH_IND message,
 * with the fields reflecting the actual number of packets & bytes that
 * are downloaded by the host.
 * If there are 0 packets downloaded for a peer/tid by the host, it
 * should set the num_pkts & num_bytes for that peer/tid as 0.
 * If there are 0 packets downloaded for all the peer/tid, the host
 * should set the num_pkts and num_bytes as 0 for all the peer/tid
 * and send the Fetch Response message to target.
 *
 *
 * |31                         16|15    12|11  8|7   5|4       0|
 * |------------------------------------------------------------|
 * |           RESP_ID           |    RSVD      |    msg type   |
 * |------------------------------------------------------------|
 * |     NUM_FETCH_RECORDS       |     FETCH_SEQ_NUMBER         |
 * |------------------------------------------------------------|
 * |                          DIALOG_TOKEN                      |
 * |------------------------------------------------------------|
 * |        NUM_PKTS             |  TIDNO |       PEERID        |
 * |------------------------------------------------------------|
 * |                          NUM_BYTES                         |
 * |------------------------------------------------------------|
 * |                            ...                             |
 * |------------------------------------------------------------|
 * |        NUM_PKTS             |  TIDNO |       PEERID        |
 * |------------------------------------------------------------|
 * |                          NUM_BYTES                         |
 * |------------------------------------------------------------|
 * Header fields:
 *  - MSG_TYPE (HTT_H2T_MSG_TYPE_TX_FETCH_RESP)
 *    Bits 7:0
 *    Value: 0xb
 *  - RESP_ID
 *    Bits 16:31
 *    Purpose: Specifies a response id that is to be replayed by
 *        the target in the HTT_T2H_MSG_TYPE_TX_FETCH_CONF message or in
 *        a resp_id record piggy-backed inside a future
 *        HTT_T2H_MSG_TYPE_TX_FETCH_IND.
 *  - FETCH_SEQ_NUMBER
 *    Bits 15:0
 *    Purpose: Replay of the sequence number from the corresponding
 *         HTT_T2H_MSG_TYPE_TX_FETCH_IND message.
 *  - NUM_FETCH_RECORDS
 *    Bits 31:16
 *    Purpose: Provide a mechanism to specify the number of records that
 *         this message contains.
 *  - DIALOG TOKEN
 *    Bits 31:0
 *    Purpose: Provide a mechanism to echo back the dialog token from
 *          the corresponding HTT_T2H_MSG_TYPE_TX_FETCH_IND message.
 *  - PEERID
 *    Bits 11:0
 *    Purpose: Provide a mechanism to specify the peerid for which
 *          the num_pkts & num_bytes are indicated.
 *  - TIDNO
 *    Bits 15:12
 *    Purpose : Provide a mechanism to specify the tidno for which
 *          the num_pkts & num_bytes are indicated.
 *  - NUM_PKTS
 *    Bits 31:16
 *    Purpose: Provide a mechanism to specify the # of MSDUs (in units of 1)
 *           that have been downloaded from the specified tx queue. Should be specified
 *           as 0 to indicate that no packets have been downloaded.
 *  - NUM_BYTES
 *    Bits 31:0
 *    Purpose : Provide a mechanism to specify the # of bytes (in units of 1)
 *           that have been downloaded from the specified tx queue. Should be specified
 *           as 0 to indicate that no bytes have been downloaded.
 */

PREPACK struct htt_tx_fetch_resp_t {
      /** word 0
       * msg_type:     8,
       * reserved0:    8;
       * resp_id:      16;
       */
    A_UINT32 word0;
      /** word 1
       * fetch_seq_num: 16,
       * num_fetch_records: 16;
       */
    A_UINT32 word1;
      /** word 2
       * Dialog token
       */
    A_UINT32 word2;

    struct {
          /** word 0
           * peerid: 12,
           * tidno: 4,
           * num_pkts: 16;
           */
        A_UINT32 word0;
          /* word 1
           * num_bytes:32;
           */
        A_UINT32 num_bytes;
    } fetch_resp_record[1];
} POSTPACK;


#define HTT_H2T_TX_FETCH_RESP_ID_M 0xffff0000
#define HTT_H2T_TX_FETCH_RESP_ID_S 16

#define HTT_H2T_TX_FETCH_RESP_SEQ_NUM_M 0xffff
#define HTT_H2T_TX_FETCH_RESP_SEQ_NUM_S 0

#define HTT_H2T_TX_FETCH_RESP_NUM_FETCH_RECORDS_M 0xffff0000
#define HTT_H2T_TX_FETCH_RESP_NUM_FETCH_RECORDS_S 16

#define HTT_H2T_TX_FETCH_RESP_PEERID_M 0xfff
#define HTT_H2T_TX_FETCH_RESP_PEERID_S 0

#define HTT_H2T_TX_FETCH_RESP_TIDNO_M 0xf000
#define HTT_H2T_TX_FETCH_RESP_TIDNO_S 12

#define HTT_H2T_TX_FETCH_RESP_NUM_PKTS_M 0xffff0000
#define HTT_H2T_TX_FETCH_RESP_NUM_PKTS_S 16

#define HTT_H2T_TX_FETCH_RESP_ID_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_H2T_TX_FETCH_RESP_ID, value); \
        (word) |= ((value) << HTT_H2T_TX_FETCH_RESP_ID_S);  \
    } while (0)

#define HTT_H2T_TX_FETCH_RESP_ID_GET(word) \
    (((word) & HTT_H2T_TX_FETCH_RESP_ID_M) >> HTT_H2T_TX_FETCH_RESP_ID_S)

#define HTT_H2T_TX_FETCH_RESP_SEQ_NUM_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_H2T_TX_FETCH_RESP_SEQ_NUM, value); \
        (word) |= ((value) << HTT_H2T_TX_FETCH_RESP_SEQ_NUM_S);  \
    } while (0)

#define HTT_H2T_TX_FETCH_RESP_SEQ_NUM_GET(word) \
    (((word) & HTT_H2T_TX_FETCH_RESP_SEQ_NUM_M) >> \
    HTT_H2T_TX_FETCH_RESP_SEQ_NUM_S)

#define HTT_H2T_TX_FETCH_RESP_NUM_FETCH_RECORDS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_H2T_TX_FETCH_RESP_NUM_FETCH_RECORDS, value); \
        (word) |= ((value) << HTT_H2T_TX_FETCH_RESP_NUM_FETCH_RECORDS_S);  \
    } while (0)

#define HTT_H2T_TX_FETCH_RESP_NUM_FETCH_RECORDS_GET(word) \
    (((word) & HTT_H2T_TX_FETCH_RESP_NUM_FETCH_RECORDS_M) >> \
    HTT_H2T_TX_FETCH_RESP_NUM_FETCH_RECORDS_S )

#define HTT_H2T_TX_FETCH_RESP_PEERID_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_H2T_TX_FETCH_RESP_PEERID, value); \
        (word) |= ((value) << HTT_H2T_TX_FETCH_RESP_PEERID_S);  \
    } while (0)

#define HTT_H2T_TX_FETCH_RESP_PEERID_GET(word) \
    (((word) & HTT_H2T_TX_FETCH_RESP_PEERID_M) >> \
    HTT_H2T_TX_FETCH_RESP_PEERID_S)

#define HTT_H2T_TX_FETCH_RESP_TIDNO_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_H2T_TX_FETCH_RESP_TIDNO, value); \
        (word) |= ((value) << HTT_H2T_TX_FETCH_RESP_TIDNO_S);  \
    } while (0)

#define HTT_H2T_TX_FETCH_RESP_TIDNO_GET(word) \
    (((word) & HTT_H2T_TX_FETCH_RESP_TIDNO_M) >> HTT_H2T_TX_FETCH_RESP_TIDNO_S)

#define HTT_H2T_TX_FETCH_RESP_NUM_PKTS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_H2T_TX_FETCH_RESP_NUM_PKTS, value); \
        (word) |= ((value) << HTT_H2T_TX_FETCH_RESP_NUM_PKTS_S);  \
    } while (0)

#define HTT_H2T_TX_FETCH_RESP_NUM_PKTS_GET(word) \
    (((word) & HTT_H2T_TX_FETCH_RESP_NUM_PKTS_M) >> \
    HTT_H2T_TX_FETCH_RESP_NUM_PKTS_S)


/*=== target -> host messages ===============================================*/


enum htt_t2h_msg_type {
    HTT_T2H_MSG_TYPE_VERSION_CONF     = 0x0,
    HTT_T2H_MSG_TYPE_RX_IND           = 0x1,
    HTT_T2H_MSG_TYPE_RX_FLUSH         = 0x2,
    HTT_T2H_MSG_TYPE_PEER_MAP         = 0x3,
    HTT_T2H_MSG_TYPE_PEER_UNMAP       = 0x4,
    HTT_T2H_MSG_TYPE_RX_ADDBA         = 0x5,
    HTT_T2H_MSG_TYPE_RX_DELBA         = 0x6,
    HTT_T2H_MSG_TYPE_TX_COMPL_IND     = 0x7,
    HTT_T2H_MSG_TYPE_PKTLOG           = 0x8,
    HTT_T2H_MSG_TYPE_STATS_CONF       = 0x9,
    HTT_T2H_MSG_TYPE_RX_FRAG_IND      = 0xa,
    HTT_T2H_MSG_TYPE_SEC_IND          = 0xb,
    HTT_T2H_MSG_TYPE_RC_UPDATE_IND    = 0xc,
    HTT_T2H_MSG_TYPE_TX_INSPECT_IND   = 0xd,
    HTT_T2H_MSG_TYPE_MGMT_TX_COMPL_IND= 0xe,
    HTT_T2H_MSG_TYPE_CHAN_CHANGE      = 0xf,
    HTT_T2H_MSG_TYPE_TX_CREDIT_UPDATE_IND   = 0x10,
    HTT_T2H_MSG_TYPE_RX_PN_IND              = 0x11,
    HTT_T2H_MSG_TYPE_RX_OFFLOAD_DELIVER_IND = 0x12,
    HTT_T2H_MSG_TYPE_TEST             = 0x13,
    HTT_T2H_MSG_TYPE_EN_STATS         = 0x14,
    HTT_T2H_MSG_TYPE_AGGR_CONF        = 0x15,
    HTT_T2H_MSG_TYPE_TX_FETCH_IND     = 0x16,
    HTT_T2H_MSG_TYPE_TX_FETCH_CONF    = 0x17,
    HTT_T2H_MSG_TYPE_STATS_NOUPLOAD   = 0x18,
    /*
     * leave 0x19 through 0x2f unused to avoid introducing additional
     * conflicts between this Beeliner htt.h and the regular
     * wlanfw_cmn.1.0.0 htt.h
     */
    HTT_T2H_MSG_TYPE_TX_MODE_SWITCH_IND = 0x30,
    /*
     * TEMPORARY ALIAS - until all references to the old message name
     * (HTT_T2H_MSG_TYPE_TX_LOW_LATENCY_IND) are updated to instead use
     * the new message name (HTT_T2H_MSG_TYPE_TX_MODE_SWITCH_IND), keep
     * the old message name as an alias for the new message name.
     */
    #define HTT_T2H_MSG_TYPE_TX_LOW_LATENCY_IND \
        HTT_T2H_MSG_TYPE_TX_MODE_SWITCH_IND
    HTT_T2H_MSG_TYPE_PEER_STATS_IND = 0x31,
    /* Message of type htt_cfr_dump_compl_ind. This message will be sent to
     * userspace whenever a CFR dump is copied to Host allocated memory, which
     * was allocated through WMI_CHANNEL_CAPTURE_HOST_MEM_REQ_ID.
     */
    HTT_T2H_MSG_TYPE_CFR_DUMP_COMPL_IND = 0x32,


    /* keep this last */
    HTT_T2H_NUM_MSGS
};

/*
 * HTT target to host message type -
 * stored in bits 7:0 of the first word of the message
 */
#define HTT_T2H_MSG_TYPE_M      0xff
#define HTT_T2H_MSG_TYPE_S      0

#define HTT_T2H_MSG_TYPE_SET(word, msg_type)           \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_T2H_MSG_TYPE, msg_type); \
        (word) |= ((msg_type) << HTT_T2H_MSG_TYPE_S);  \
    } while (0)
#define HTT_T2H_MSG_TYPE_GET(word) \
    (((word) & HTT_T2H_MSG_TYPE_M) >> HTT_T2H_MSG_TYPE_S)

/**
 * @brief target -> host version number confirmation message definition
 *
 *     |31            24|23            16|15             8|7              0|
 *     |----------------+----------------+----------------+----------------|
 *     |    reserved    |  major number  |  minor number  |    msg type    |
 *     |-------------------------------------------------------------------|
 *
 * Header fields:
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as a version number confirmation message
 *     Value: 0x0
 *   - VER_MINOR
 *     Bits 15:8
 *     Purpose: Specify the minor number of the HTT message library version
 *         in use by the target firmware.
 *         The minor number specifies the specific revision within a range
 *         of fundamentally compatible HTT message definition revisions.
 *         Compatible revisions involve adding new messages or perhaps
 *         adding new fields to existing messages, in a backwards-compatible
 *         manner.
 *         Incompatible revisions involve changing the message type values,
 *         or redefining existing messages.
 *     Value: minor number
 *   - VER_MAJOR
 *     Bits 15:8
 *     Purpose: Specify the major number of the HTT message library version
 *         in use by the target firmware.
 *         The major number specifies the family of minor revisions that are
 *         fundamentally compatible with each other, but not with prior or
 *         later families.
 *     Value: major number
 */

#define HTT_VER_CONF_MINOR_M      0x0000ff00
#define HTT_VER_CONF_MINOR_S      8
#define HTT_VER_CONF_MAJOR_M      0x00ff0000
#define HTT_VER_CONF_MAJOR_S      16


#define HTT_VER_CONF_MINOR_SET(word, value)                              \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_VER_CONF_MINOR, value);                    \
        (word) |= (value)  << HTT_VER_CONF_MINOR_S;                      \
    } while (0)
#define HTT_VER_CONF_MINOR_GET(word) \
    (((word) & HTT_VER_CONF_MINOR_M) >> HTT_VER_CONF_MINOR_S)

#define HTT_VER_CONF_MAJOR_SET(word, value)                              \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_VER_CONF_MAJOR, value);                    \
        (word) |= (value)  << HTT_VER_CONF_MAJOR_S;                      \
    } while (0)
#define HTT_VER_CONF_MAJOR_GET(word) \
    (((word) & HTT_VER_CONF_MAJOR_M) >> HTT_VER_CONF_MAJOR_S)


#define HTT_VER_CONF_BYTES 4

PREPACK struct htt_rx_ind_hdr_prefix_t
{
    A_UINT32 /* word 0 */
        msg_type:      8,
        ext_tid:       5,
        release_valid: 1,
        flush_valid:   1,
        reserved0:     1,
        peer_id:       16;

    A_UINT32 /* word 1 */
        flush_start_seq_num:   6,
        flush_end_seq_num:     6,
        release_start_seq_num: 6,
        release_end_seq_num:   6,
        num_mpdu_ranges:       8;
} POSTPACK;

#define HTT_RX_IND_HDR_PREFIX_BYTES (sizeof(struct htt_rx_ind_hdr_prefix_t))
#define HTT_RX_IND_HDR_PREFIX_SIZE32 (HTT_RX_IND_HDR_PREFIX_BYTES >> 2)

PREPACK struct htt_rx_ppdu_desc_t
{
    #define HTT_RX_IND_PPDU_OFFSET_WORD_RSSI_CMB              0
    #define HTT_RX_IND_PPDU_OFFSET_WORD_TIMESTAMP_SUBMICROSEC 0
    #define HTT_RX_IND_PPDU_OFFSET_WORD_PHY_ERR_CODE          0
    #define HTT_RX_IND_PPDU_OFFSET_WORD_PHY_ERR               0
    #define HTT_RX_IND_PPDU_OFFSET_WORD_LEGACY_RATE           0
    #define HTT_RX_IND_PPDU_OFFSET_WORD_LEGACY_RATE_SEL       0
    #define HTT_RX_IND_PPDU_OFFSET_WORD_END_VALID             0
    #define HTT_RX_IND_PPDU_OFFSET_WORD_START_VALID           0
    A_UINT32 /* word 0 */
        rssi_cmb: 8,
        timestamp_submicrosec: 8,
        phy_err_code: 8,
        phy_err: 1,
        legacy_rate: 4,
        legacy_rate_sel: 1,
        end_valid: 1,
        start_valid: 1;

    #define HTT_RX_IND_PPDU_OFFSET_WORD_RSSI0 1
    union {
        A_UINT32 /* word 1 */
            rssi0_pri20: 8,
            rssi0_ext20: 8,
            rssi0_ext40: 8,
            rssi0_ext80: 8;
       A_UINT32 rssi0; /* access all 20/40/80 per-bandwidth RSSIs together */
    } u0;

    #define HTT_RX_IND_PPDU_OFFSET_WORD_RSSI1 2
    union {
        A_UINT32 /* word 2 */
            rssi1_pri20: 8,
            rssi1_ext20: 8,
            rssi1_ext40: 8,
            rssi1_ext80: 8;
       A_UINT32 rssi1; /* access all 20/40/80 per-bandwidth RSSIs together */
    } u1;

    #define HTT_RX_IND_PPDU_OFFSET_WORD_RSSI2 3
    union {
        A_UINT32 /* word 3 */
            rssi2_pri20: 8,
            rssi2_ext20: 8,
            rssi2_ext40: 8,
            rssi2_ext80: 8;
       A_UINT32 rssi2; /* access all 20/40/80 per-bandwidth RSSIs together */
    } u2;

    #define HTT_RX_IND_PPDU_OFFSET_WORD_RSSI3 4
    union {
        A_UINT32 /* word 4 */
            rssi3_pri20: 8,
            rssi3_ext20: 8,
            rssi3_ext40: 8,
            rssi3_ext80: 8;
       A_UINT32 rssi3; /* access all 20/40/80 per-bandwidth RSSIs together */
    } u3;

    #define HTT_RX_IND_PPDU_OFFSET_WORD_TSF32 5
    A_UINT32 tsf32; /* word 5 */

    #define HTT_RX_IND_PPDU_OFFSET_WORD_TIMESTAMP_MICROSEC 6
    A_UINT32 timestamp_microsec; /* word 6 */

    #define HTT_RX_IND_PPDU_OFFSET_WORD_PREAMBLE_TYPE 7
    #define HTT_RX_IND_PPDU_OFFSET_WORD_VHT_SIG_A1    7
    A_UINT32 /* word 7 */
        vht_sig_a1: 24,
        preamble_type: 8;

    #define HTT_RX_IND_PPDU_OFFSET_WORD_VHT_SIG_A2    8
    A_UINT32 /* word 8 */
        vht_sig_a2: 24,
        reserved0: 8;
} POSTPACK;

#define HTT_RX_PPDU_DESC_BYTES (sizeof(struct htt_rx_ppdu_desc_t))
#define HTT_RX_PPDU_DESC_SIZE32 (HTT_RX_PPDU_DESC_BYTES >> 2)

PREPACK struct htt_rx_ind_hdr_suffix_t
{
    A_UINT32 /* word 0 */
        fw_rx_desc_bytes: 16,
        reserved0: 16;
} POSTPACK;

#define HTT_RX_IND_HDR_SUFFIX_BYTES (sizeof(struct htt_rx_ind_hdr_suffix_t))
#define HTT_RX_IND_HDR_SUFFIX_SIZE32 (HTT_RX_IND_HDR_SUFFIX_BYTES >> 2)

PREPACK struct htt_rx_ind_hdr_t
{
    struct htt_rx_ind_hdr_prefix_t prefix;
    struct htt_rx_ppdu_desc_t      rx_ppdu_desc;
    struct htt_rx_ind_hdr_suffix_t suffix;
} POSTPACK;

#define HTT_RX_IND_HDR_BYTES (sizeof(struct htt_rx_ind_hdr_t))
#define HTT_RX_IND_HDR_SIZE32 (HTT_RX_IND_HDR_BYTES >> 2)

/* confirm that HTT_RX_IND_HDR_BYTES is a multiple of 4 */
A_COMPILE_TIME_ASSERT(HTT_RX_IND_hdr_size_quantum,
    (HTT_RX_IND_HDR_BYTES & 0x3) == 0);

/*
 * HTT_RX_IND_FW_RX_PPDU_DESC_BYTE_OFFSET:
 * the offset into the HTT rx indication message at which the
 * FW rx PPDU descriptor resides
 */
#define HTT_RX_IND_FW_RX_PPDU_DESC_BYTE_OFFSET HTT_RX_IND_HDR_PREFIX_BYTES

/*
 * HTT_RX_IND_HDR_SUFFIX_BYTE_OFFSET:
 * the offset into the HTT rx indication message at which the
 * header suffix (FW rx MSDU byte count) resides
 */
#define HTT_RX_IND_HDR_SUFFIX_BYTE_OFFSET \
    (HTT_RX_IND_FW_RX_PPDU_DESC_BYTE_OFFSET + HTT_RX_PPDU_DESC_BYTES)

/*
 * HTT_RX_IND_FW_RX_DESC_BYTE_OFFSET:
 * the offset into the HTT rx indication message at which the per-MSDU
 * information starts
 * Words 0-7 are the message header; Words 8-11 contain the length of the
 * per-MSDU information portion of the message.  The per-MSDU info itself
 * starts at Word 12.
 */
/* The HTT header format varies between the types of indication messages,
 * be sure to use correct header,macro and offset
 */
#define HTT_RX_IND_FW_RX_DESC_BYTE_OFFSET HTT_RX_IND_HDR_BYTES


/**
 * @brief target -> host rx indication message definition
 *
 * @details
 * The following field definitions describe the format of the rx indication
 * message sent from the target to the host.
 * The message consists of three major sections:
 * 1.  a fixed-length header
 * 2.  a variable-length list of firmware rx MSDU descriptors
 * 3.  one or more 4-octet MPDU range information elements
 * The fixed length header itself has two sub-sections
 * 1.  the message meta-information, including identification of the
 *     sender and type of the received data, and a 4-octet flush/release IE
 * 2.  the firmware rx PPDU descriptor
 *
 * The format of the message is depicted below.
 * in this depiction, the following abbreviations are used for information
 * elements within the message:
 *   - SV - start valid: this flag is set if the FW rx PPDU descriptor
 *          elements associated with the PPDU start are valid.
 *          Specifically, the following fields are valid only if SV is set:
 *              RSSI (all variants), L, legacy rate, preamble type, service,
 *              VHT-SIG-A
 *   - EV - end valid: this flag is set if the FW rx PPDU descriptor
 *          elements associated with the PPDU end are valid.
 *          Specifically, the following fields are valid only if EV is set:
 *              P, PHY err code, TSF, microsec / sub-microsec timestamp
 *   - L  - Legacy rate selector - if legacy rates are used, this flag
 *          indicates whether the rate is from a CCK (L == 1) or OFDM
 *          (L == 0) PHY.
 *   - P  - PHY error flag - boolean indication of whether the rx frame had
 *          a PHY error
 *
 * |31            24|23         18|17|16|15|14|13|12|11|10|9|8|7|6|5|4       0|
 * |----------------+-------------------+---------------------+---------------|
 * |                  peer ID           |  |RV|FV| ext TID    |   msg type    |
 * |--------------------------------------------------------------------------|
 * |      num       |   release   |     release     |    flush    |   flush   |
 * |      MPDU      |     end     |      start      |     end     |   start   |
 * |     ranges     |   seq num   |     seq num     |   seq num   |  seq num  |
 * |==========================================================================|
 * |S|E|L| legacy |P|   PHY err code    |     sub-microsec    |    combined   |
 * |V|V| |  rate  | |                   |       timestamp     |       RSSI    |
 * |--------------------------------------------------------------------------|
 * | RSSI rx0 ext80 |  RSSI rx0 ext40   |    RSSI rx0  ext20  | RSSI rx0 pri20|
 * |--------------------------------------------------------------------------|
 * | RSSI rx1 ext80 |  RSSI rx1 ext40   |    RSSI rx1  ext20  | RSSI rx1 pri20|
 * |--------------------------------------------------------------------------|
 * | RSSI rx2 ext80 |  RSSI rx2 ext40   |    RSSI rx2  ext20  | RSSI rx2 pri20|
 * |--------------------------------------------------------------------------|
 * | RSSI rx3 ext80 |  RSSI rx3 ext40   |    RSSI rx3  ext20  | RSSI rx3 pri20|
 * |--------------------------------------------------------------------------|
 * |                                  TSF LSBs                                |
 * |--------------------------------------------------------------------------|
 * |                             microsec timestamp                           |
 * |--------------------------------------------------------------------------|
 * | preamble type  |                    HT-SIG / VHT-SIG-A1                  |
 * |--------------------------------------------------------------------------|
 * |    service     |                    HT-SIG / VHT-SIG-A2                  |
 * |==========================================================================|
 * |             reserved               |          FW rx desc bytes           |
 * |--------------------------------------------------------------------------|
 * |     MSDU Rx    |      MSDU Rx      |        MSDU Rx      |    MSDU Rx    |
 * |     desc B3    |      desc B2      |        desc B1      |    desc B0    |
 * |--------------------------------------------------------------------------|
 * :                                    :                                     :
 * |--------------------------------------------------------------------------|
 * |                          alignment                       |    MSDU Rx    |
 * |                           padding                        |    desc Bn    |
 * |--------------------------------------------------------------------------|
 * |              reserved              |  MPDU range status  |   MPDU count  |
 * |--------------------------------------------------------------------------|
 * :              reserved              :  MPDU range status  :   MPDU count  :
 * :- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - :
 *
 * Header fields:
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as an rx indication message
 *     Value: 0x1
 *   - EXT_TID
 *     Bits 12:8
 *     Purpose: identify the traffic ID of the rx data, including
 *         special "extended" TID values for multicast, broadcast, and
 *         non-QoS data frames
 *     Value: 0-15 for regular TIDs, or >= 16 for bcast/mcast/non-QoS
 *   - FLUSH_VALID (FV)
 *     Bit 13
 *     Purpose: indicate whether the flush IE (start/end sequence numbers)
 *         is valid
 *     Value:
 *         1 -> flush IE is valid and needs to be processed
 *         0 -> flush IE is not valid and should be ignored
 *   - REL_VALID (RV)
 *     Bit 13
 *     Purpose: indicate whether the release IE (start/end sequence numbers)
 *         is valid
 *     Value:
 *         1 -> release IE is valid and needs to be processed
 *         0 -> release IE is not valid and should be ignored
 *   - PEER_ID
 *     Bits 31:16
 *     Purpose: Identify, by ID, which peer sent the rx data
 *     Value: ID of the peer who sent the rx data
 *   - FLUSH_SEQ_NUM_START
 *     Bits 5:0
 *     Purpose: Indicate the start of a series of MPDUs to flush
 *         Not all MPDUs within this series are necessarily valid - the host
 *         must check each sequence number within this range to see if the
 *         corresponding MPDU is actually present.
 *         This field is only valid if the FV bit is set.
 *     Value:
 *         The sequence number for the first MPDUs to check to flush.
 *         The sequence number is masked by 0x3f.
 *   - FLUSH_SEQ_NUM_END
 *     Bits 11:6
 *     Purpose: Indicate the end of a series of MPDUs to flush
 *     Value:
 *         The sequence number one larger than the sequence number of the
 *         last MPDU to check to flush.
 *         The sequence number is masked by 0x3f.
 *         Not all MPDUs within this series are necessarily valid - the host
 *         must check each sequence number within this range to see if the
 *         corresponding MPDU is actually present.
 *         This field is only valid if the FV bit is set.
 *   - REL_SEQ_NUM_START
 *     Bits 5:0
 *     Purpose: Indicate the start of a series of MPDUs to release.
 *         All MPDUs within this series are present and valid - the host
 *         need not check each sequence number within this range to see if
 *         the corresponding MPDU is actually present.
 *         This field is only valid if the RV bit is set.
 *     Value:
 *         The sequence number for the first MPDUs to check to release.
 *         The sequence number is masked by 0x3f.
 *   - REL_SEQ_NUM_END
 *     Bits 11:6
 *     Purpose: Indicate the end of a series of MPDUs to release.
 *     Value:
 *         The sequence number one larger than the sequence number of the
 *         last MPDU to check to release.
 *         The sequence number is masked by 0x3f.
 *         All MPDUs within this series are present and valid - the host
 *         need not check each sequence number within this range to see if
 *         the corresponding MPDU is actually present.
 *         This field is only valid if the RV bit is set.
 *
 * Rx PPDU descriptor fields:
 *   - RSSI_CMB
 *     Bits 7:0
 *     Purpose: Combined RSSI from all active rx chains, across the active
 *         bandwidth.
 *     Value: RSSI dB units w.r.t. noise floor
 *   - TIMESTAMP_SUBMICROSEC
 *     Bits 15:8
 *     Purpose: high-resolution timestamp
 *     Value:
 *         Sub-microsecond time of PPDU reception.
 *         This timestamp ranges from [0,MAC clock MHz).
 *         This timestamp can be used in conjunction with TIMESTAMP_MICROSEC
 *         to form a high-resolution, large range rx timestamp.
 *   - PHY_ERR_CODE
 *     Bits 23:16
 *     Purpose:
 *         If the rx frame processing resulted in a PHY error, indicate what
 *         type of rx PHY error occurred.
 *     Value:
 *         This field is valid if the "P" (PHY_ERR) flag is set.
 *         TBD: document/specify the values for this field
 *   - PHY_ERR
 *     Bit 24
 *     Purpose: indicate whether the rx PPDU had a PHY error
 *     Value: 0 -> no rx PHY error, 1 -> rx PHY error encountered
 *   - LEGACY_RATE
 *     Bits 28:25
 *     Purpose:
 *         If the rx frame used a legacy rate rather than a HT or VHT rate,
 *         specify which rate was used.
 *     Value:
 *         The LEGACY_RATE field's value depends on the "L" (LEGACY_RATE_SEL)
 *         flag.
 *         If LEGACY_RATE_SEL is 0:
 *             0x8: OFDM 48 Mbps
 *             0x9: OFDM 24 Mbps
 *             0xA: OFDM 12 Mbps
 *             0xB: OFDM 6 Mbps
 *             0xC: OFDM 54 Mbps
 *             0xD: OFDM 36 Mbps
 *             0xE: OFDM 18 Mbps
 *             0xF: OFDM 9 Mbps
 *         If LEGACY_RATE_SEL is 1:
 *             0x8: CCK 11 Mbps long preamble
 *             0x9: CCK 5.5 Mbps long preamble
 *             0xA: CCK 2 Mbps long preamble
 *             0xB: CCK 1 Mbps long preamble
 *             0xC: CCK 11 Mbps short preamble
 *             0xD: CCK 5.5 Mbps short preamble
 *             0xE: CCK 2 Mbps short preamble
 *   - LEGACY_RATE_SEL
 *     Bit 29
 *     Purpose: if rx used a legacy rate, specify whether it was OFDM or CCK
 *     Value:
 *         This field is valid if the PREAMBLE_TYPE field indicates the rx
 *         used a legacy rate.
 *         0 -> OFDM, 1 -> CCK
 *   - END_VALID
 *     Bit 30
 *     Purpose: Indicate whether the FW rx PPDU desc fields associated with
 *         the start of the PPDU are valid.  Specifically, the following
 *         fields are only valid if END_VALID is set:
 *         PHY_ERR, PHY_ERR_CODE, TSF32, TIMESTAMP_MICROSEC,
 *         TIMESTAMP_SUBMICROSEC
 *     Value:
 *         0 -> rx PPDU desc end fields are not valid
 *         1 -> rx PPDU desc end fields are valid
 *   - START_VALID
 *     Bit 31
 *     Purpose: Indicate whether the FW rx PPDU desc fields associated with
 *         the end of the PPDU are valid.  Specifically, the following
 *         fields are only valid if START_VALID is set:
 *         RSSI, LEGACY_RATE_SEL, LEGACY_RATE, PREAMBLE_TYPE, SERVICE,
 *         VHT-SIG-A
 *     Value:
 *         0 -> rx PPDU desc start fields are not valid
 *         1 -> rx PPDU desc start fields are valid
 *   - RSSI0_PRI20
 *     Bits 7:0
 *     Purpose: RSSI from chain 0 on the primary 20 MHz channel
 *     Value: RSSI dB units w.r.t. noise floor
 *
 *   - RSSI0_EXT20
 *     Bits 7:0
 *     Purpose: RSSI from chain 0 on the bonded extension 20 MHz channel
 *         (if the rx bandwidth was >= 40 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI0_EXT40
 *     Bits 7:0
 *     Purpose: RSSI from chain 0 on the bonded extension 40 MHz channel
 *         (if the rx bandwidth was >= 80 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI0_EXT80
 *     Bits 7:0
 *     Purpose: RSSI from chain 0 on the bonded extension 80 MHz channel
 *         (if the rx bandwidth was >= 160 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *
 *   - RSSI1_PRI20
 *     Bits 7:0
 *     Purpose: RSSI from chain 1 on the primary 20 MHz channel
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI1_EXT20
 *     Bits 7:0
 *     Purpose: RSSI from chain 1 on the bonded extension 20 MHz channel
 *         (if the rx bandwidth was >= 40 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI1_EXT40
 *     Bits 7:0
 *     Purpose: RSSI from chain 1 on the bonded extension 40 MHz channel
 *         (if the rx bandwidth was >= 80 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI1_EXT80
 *     Bits 7:0
 *     Purpose: RSSI from chain 1 on the bonded extension 80 MHz channel
 *         (if the rx bandwidth was >= 160 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *
 *   - RSSI2_PRI20
 *     Bits 7:0
 *     Purpose: RSSI from chain 2 on the primary 20 MHz channel
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI2_EXT20
 *     Bits 7:0
 *     Purpose: RSSI from chain 2 on the bonded extension 20 MHz channel
 *         (if the rx bandwidth was >= 40 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI2_EXT40
 *     Bits 7:0
 *     Purpose: RSSI from chain 2 on the bonded extension 40 MHz channel
 *         (if the rx bandwidth was >= 80 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI2_EXT80
 *     Bits 7:0
 *     Purpose: RSSI from chain 2 on the bonded extension 80 MHz channel
 *         (if the rx bandwidth was >= 160 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *
 *   - RSSI3_PRI20
 *     Bits 7:0
 *     Purpose: RSSI from chain 3 on the primary 20 MHz channel
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI3_EXT20
 *     Bits 7:0
 *     Purpose: RSSI from chain 3 on the bonded extension 20 MHz channel
 *         (if the rx bandwidth was >= 40 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI3_EXT40
 *     Bits 7:0
 *     Purpose: RSSI from chain 3 on the bonded extension 40 MHz channel
 *         (if the rx bandwidth was >= 80 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *   - RSSI3_EXT80
 *     Bits 7:0
 *     Purpose: RSSI from chain 3 on the bonded extension 80 MHz channel
 *         (if the rx bandwidth was >= 160 MHz)
 *     Value: RSSI dB units w.r.t. noise floor
 *
 *   - TSF32
 *     Bits 31:0
 *     Purpose: specify the time the rx PPDU was received, in TSF units
 *     Value: 32 LSBs of the TSF
 *   - TIMESTAMP_MICROSEC
 *     Bits 31:0
 *     Purpose: specify the time the rx PPDU was received, in microsecond units
 *     Value: PPDU rx time, in microseconds
 *   - VHT_SIG_A1
 *     Bits 23:0
 *     Purpose: Provide the HT-SIG (initial 24 bits) or VHT-SIG-A1 field
 *         from the rx PPDU
 *     Value:
 *         If PREAMBLE_TYPE specifies VHT, then this field contains the
 *         VHT-SIG-A1 data.
 *         If PREAMBLE_TYPE specifies HT, then this field contains the
 *         first 24 bits of the HT-SIG data.
 *         Otherwise, this field is invalid.
 *         Refer to the the 802.11 protocol for the definition of the
 *         HT-SIG and VHT-SIG-A1 fields
 *   - VHT_SIG_A2
 *     Bits 23:0
 *     Purpose: Provide the HT-SIG (final 24 bits) or VHT-SIG-A2 field
 *         from the rx PPDU
 *     Value:
 *         If PREAMBLE_TYPE specifies VHT, then this field contains the
 *         VHT-SIG-A2 data.
 *         If PREAMBLE_TYPE specifies HT, then this field contains the
 *         last 24 bits of the HT-SIG data.
 *         Otherwise, this field is invalid.
 *         Refer to the the 802.11 protocol for the definition of the
 *         HT-SIG and VHT-SIG-A2 fields
 *   - PREAMBLE_TYPE
 *     Bits 31:24
 *     Purpose: indicate the PHY format of the received burst
 *     Value:
 *         0x4: Legacy (OFDM/CCK)
 *         0x8: HT
 *         0x9: HT with TxBF
 *         0xC: VHT
 *         0xD: VHT with TxBF
 *   - SERVICE
 *     Bits 31:24
 *     Purpose: TBD
 *     Value: TBD
 *
 * Rx MSDU descriptor fields:
 *   - FW_RX_DESC_BYTES
 *     Bits 15:0
 *     Purpose: Indicate how many bytes in the Rx indication are used for
 *         FW Rx descriptors
 *
 * Payload fields:
 *   - MPDU_COUNT
 *     Bits 7:0
 *     Purpose: Indicate how many sequential MPDUs share the same status.
 *         All MPDUs within the indicated list are from the same RA-TA-TID.
 *   - MPDU_STATUS
 *     Bits 15:8
 *     Purpose: Indicate whether the (group of sequential) MPDU(s) were
 *         received successfully.
 *     Value:
 *         0x1: success
 *         0x2: FCS error
 *         0x3: duplicate error
 *         0x4: replay error
 *         0x5: invalid peer
 */
/* header fields */
#define HTT_RX_IND_EXT_TID_M      0x1f00
#define HTT_RX_IND_EXT_TID_S      8
#define HTT_RX_IND_FLUSH_VALID_M  0x2000
#define HTT_RX_IND_FLUSH_VALID_S  13
#define HTT_RX_IND_REL_VALID_M    0x4000
#define HTT_RX_IND_REL_VALID_S    14
#define HTT_RX_IND_PEER_ID_M      0xffff0000
#define HTT_RX_IND_PEER_ID_S      16

#define HTT_RX_IND_FLUSH_SEQ_NUM_START_M 0x3f
#define HTT_RX_IND_FLUSH_SEQ_NUM_START_S 0
#define HTT_RX_IND_FLUSH_SEQ_NUM_END_M   0xfc0
#define HTT_RX_IND_FLUSH_SEQ_NUM_END_S   6
#define HTT_RX_IND_REL_SEQ_NUM_START_M   0x3f000
#define HTT_RX_IND_REL_SEQ_NUM_START_S   12
#define HTT_RX_IND_REL_SEQ_NUM_END_M     0xfc0000
#define HTT_RX_IND_REL_SEQ_NUM_END_S     18
#define HTT_RX_IND_NUM_MPDU_RANGES_M     0xff000000
#define HTT_RX_IND_NUM_MPDU_RANGES_S     24

/* rx PPDU descriptor fields */
#define HTT_RX_IND_RSSI_CMB_M              0x000000ff
#define HTT_RX_IND_RSSI_CMB_S              0
#define HTT_RX_IND_TIMESTAMP_SUBMICROSEC_M 0x0000ff00
#define HTT_RX_IND_TIMESTAMP_SUBMICROSEC_S 8
#define HTT_RX_IND_PHY_ERR_CODE_M          0x00ff0000
#define HTT_RX_IND_PHY_ERR_CODE_S          16
#define HTT_RX_IND_PHY_ERR_M               0x01000000
#define HTT_RX_IND_PHY_ERR_S               24
#define HTT_RX_IND_LEGACY_RATE_M           0x1e000000
#define HTT_RX_IND_LEGACY_RATE_S           25
#define HTT_RX_IND_LEGACY_RATE_SEL_M       0x20000000
#define HTT_RX_IND_LEGACY_RATE_SEL_S       29
#define HTT_RX_IND_END_VALID_M             0x40000000
#define HTT_RX_IND_END_VALID_S             30
#define HTT_RX_IND_START_VALID_M           0x80000000
#define HTT_RX_IND_START_VALID_S           31

#define HTT_RX_IND_RSSI_PRI20_M            0x000000ff
#define HTT_RX_IND_RSSI_PRI20_S            0
#define HTT_RX_IND_RSSI_EXT20_M            0x0000ff00
#define HTT_RX_IND_RSSI_EXT20_S            8
#define HTT_RX_IND_RSSI_EXT40_M            0x00ff0000
#define HTT_RX_IND_RSSI_EXT40_S            16
#define HTT_RX_IND_RSSI_EXT80_M            0xff000000
#define HTT_RX_IND_RSSI_EXT80_S            24

#define HTT_RX_IND_VHT_SIG_A1_M            0x00ffffff
#define HTT_RX_IND_VHT_SIG_A1_S            0
#define HTT_RX_IND_VHT_SIG_A2_M            0x00ffffff
#define HTT_RX_IND_VHT_SIG_A2_S            0
#define HTT_RX_IND_PREAMBLE_TYPE_M         0xff000000
#define HTT_RX_IND_PREAMBLE_TYPE_S         24
#define HTT_RX_IND_SERVICE_M               0xff000000
#define HTT_RX_IND_SERVICE_S               24

/* rx MSDU descriptor fields */
#define HTT_RX_IND_FW_RX_DESC_BYTES_M   0xffff
#define HTT_RX_IND_FW_RX_DESC_BYTES_S   0

/* payload fields */
#define HTT_RX_IND_MPDU_COUNT_M    0xff
#define HTT_RX_IND_MPDU_COUNT_S    0
#define HTT_RX_IND_MPDU_STATUS_M   0xff00
#define HTT_RX_IND_MPDU_STATUS_S   8


#define HTT_RX_IND_EXT_TID_SET(word, value)                              \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_EXT_TID, value);                    \
        (word) |= (value)  << HTT_RX_IND_EXT_TID_S;                      \
    } while (0)
#define HTT_RX_IND_EXT_TID_GET(word) \
    (((word) & HTT_RX_IND_EXT_TID_M) >> HTT_RX_IND_EXT_TID_S)

#define HTT_RX_IND_FLUSH_VALID_SET(word, value)                          \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_FLUSH_VALID, value);                \
        (word) |= (value)  << HTT_RX_IND_FLUSH_VALID_S;                  \
    } while (0)
#define HTT_RX_IND_FLUSH_VALID_GET(word) \
    (((word) & HTT_RX_IND_FLUSH_VALID_M) >> HTT_RX_IND_FLUSH_VALID_S)

#define HTT_RX_IND_REL_VALID_SET(word, value)                            \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_REL_VALID, value);                  \
        (word) |= (value)  << HTT_RX_IND_REL_VALID_S;                    \
    } while (0)
#define HTT_RX_IND_REL_VALID_GET(word) \
    (((word) & HTT_RX_IND_REL_VALID_M) >> HTT_RX_IND_REL_VALID_S)

#define HTT_RX_IND_PEER_ID_SET(word, value)                              \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_PEER_ID, value);                    \
        (word) |= (value)  << HTT_RX_IND_PEER_ID_S;                      \
    } while (0)
#define HTT_RX_IND_PEER_ID_GET(word) \
    (((word) & HTT_RX_IND_PEER_ID_M) >> HTT_RX_IND_PEER_ID_S)


#define HTT_RX_IND_FW_RX_DESC_BYTES_SET(word, value)                     \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_FW_RX_DESC_BYTES, value);           \
        (word) |= (value)  << HTT_RX_IND_FW_RX_DESC_BYTES_S;             \
    } while (0)
#define HTT_RX_IND_FW_RX_DESC_BYTES_GET(word) \
    (((word) & HTT_RX_IND_FW_RX_DESC_BYTES_M) >> HTT_RX_IND_FW_RX_DESC_BYTES_S)


#define HTT_RX_IND_FLUSH_SEQ_NUM_START_SET(word, value)              \
    do {                                                             \
        HTT_CHECK_SET_VAL(HTT_RX_IND_FLUSH_SEQ_NUM_START, value);    \
        (word) |= (value)  << HTT_RX_IND_FLUSH_SEQ_NUM_START_S;      \
    } while (0)
#define HTT_RX_IND_FLUSH_SEQ_NUM_START_GET(word)                     \
     (((word) & HTT_RX_IND_FLUSH_SEQ_NUM_START_M) >>                 \
      HTT_RX_IND_FLUSH_SEQ_NUM_START_S)

#define HTT_RX_IND_FLUSH_SEQ_NUM_END_SET(word, value)                \
    do {                                                             \
        HTT_CHECK_SET_VAL(HTT_RX_IND_FLUSH_SEQ_NUM_END, value);      \
        (word) |= (value)  << HTT_RX_IND_FLUSH_SEQ_NUM_END_S;        \
    } while (0)
#define HTT_RX_IND_FLUSH_SEQ_NUM_END_GET(word)                       \
    (((word) & HTT_RX_IND_FLUSH_SEQ_NUM_END_M) >>                    \
    HTT_RX_IND_FLUSH_SEQ_NUM_END_S)

#define HTT_RX_IND_REL_SEQ_NUM_START_SET(word, value)                \
    do {                                                             \
        HTT_CHECK_SET_VAL(HTT_RX_IND_REL_SEQ_NUM_START, value);      \
        (word) |= (value)  << HTT_RX_IND_REL_SEQ_NUM_START_S;        \
    } while (0)
#define HTT_RX_IND_REL_SEQ_NUM_START_GET(word)                       \
     (((word) & HTT_RX_IND_REL_SEQ_NUM_START_M) >>                   \
      HTT_RX_IND_REL_SEQ_NUM_START_S)

#define HTT_RX_IND_REL_SEQ_NUM_END_SET(word, value)                  \
    do {                                                             \
        HTT_CHECK_SET_VAL(HTT_RX_IND_REL_SEQ_NUM_END, value);        \
        (word) |= (value)  << HTT_RX_IND_REL_SEQ_NUM_END_S;          \
    } while (0)
#define HTT_RX_IND_REL_SEQ_NUM_END_GET(word)                         \
    (((word) & HTT_RX_IND_REL_SEQ_NUM_END_M) >>                      \
    HTT_RX_IND_REL_SEQ_NUM_END_S)

#define HTT_RX_IND_NUM_MPDU_RANGES_SET(word, value)                  \
    do {                                                             \
        HTT_CHECK_SET_VAL(HTT_RX_IND_NUM_MPDU_RANGES, value);        \
        (word) |= (value)  << HTT_RX_IND_NUM_MPDU_RANGES_S;          \
    } while (0)
#define HTT_RX_IND_NUM_MPDU_RANGES_GET(word)                         \
    (((word) & HTT_RX_IND_NUM_MPDU_RANGES_M) >>                      \
    HTT_RX_IND_NUM_MPDU_RANGES_S)

/* FW rx PPDU descriptor fields */
#define HTT_RX_IND_RSSI_CMB_SET(word, value)           \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_RX_IND_RSSI_CMB, value); \
        (word) |= (value)  << HTT_RX_IND_RSSI_CMB_S;   \
    } while (0)
#define HTT_RX_IND_RSSI_CMB_GET(word)    \
    (((word) & HTT_RX_IND_RSSI_CMB_M) >> \
    HTT_RX_IND_RSSI_CMB_S)

#define HTT_RX_IND_TIMESTAMP_SUBMICROSEC_SET(word, value)           \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_IND_TIMESTAMP_SUBMICROSEC, value); \
        (word) |= (value)  << HTT_RX_IND_TIMESTAMP_SUBMICROSEC_S;   \
    } while (0)
#define HTT_RX_IND_TIMESTAMP_SUBMICROSEC_GET(word)    \
    (((word) & HTT_RX_IND_TIMESTAMP_SUBMICROSEC_M) >> \
    HTT_RX_IND_TIMESTAMP_SUBMICROSEC_S)

#define HTT_RX_IND_PHY_ERR_CODE_SET(word, value)           \
    do {                                                        \
        HTT_CHECK_SET_VAL(HTT_RX_IND_PHY_ERR_CODE, value); \
        (word) |= (value)  << HTT_RX_IND_PHY_ERR_CODE_S;   \
    } while (0)
#define HTT_RX_IND_PHY_ERR_CODE_GET(word)    \
    (((word) & HTT_RX_IND_PHY_ERR_CODE_M) >> \
    HTT_RX_IND_PHY_ERR_CODE_S)

#define HTT_RX_IND_PHY_ERR_SET(word, value)           \
    do {                                                   \
        HTT_CHECK_SET_VAL(HTT_RX_IND_PHY_ERR, value); \
        (word) |= (value)  << HTT_RX_IND_PHY_ERR_S;   \
    } while (0)
#define HTT_RX_IND_PHY_ERR_GET(word)    \
    (((word) & HTT_RX_IND_PHY_ERR_M) >> \
    HTT_RX_IND_PHY_ERR_S)

#define HTT_RX_IND_LEGACY_RATE_SET(word, value)           \
    do {                                                       \
        HTT_CHECK_SET_VAL(HTT_RX_IND_LEGACY_RATE, value); \
        (word) |= (value)  << HTT_RX_IND_LEGACY_RATE_S;   \
    } while (0)
#define HTT_RX_IND_LEGACY_RATE_GET(word)    \
    (((word) & HTT_RX_IND_LEGACY_RATE_M) >> \
    HTT_RX_IND_LEGACY_RATE_S)

#define HTT_RX_IND_LEGACY_RATE_SEL_SET(word, value)           \
    do {                                                           \
        HTT_CHECK_SET_VAL(HTT_RX_IND_LEGACY_RATE_SEL, value); \
        (word) |= (value)  << HTT_RX_IND_LEGACY_RATE_SEL_S;   \
    } while (0)
#define HTT_RX_IND_LEGACY_RATE_SEL_GET(word)    \
    (((word) & HTT_RX_IND_LEGACY_RATE_SEL_M) >> \
    HTT_RX_IND_LEGACY_RATE_SEL_S)

#define HTT_RX_IND_END_VALID_SET(word, value)           \
    do {                                                     \
        HTT_CHECK_SET_VAL(HTT_RX_IND_END_VALID, value); \
        (word) |= (value)  << HTT_RX_IND_END_VALID_S;   \
    } while (0)
#define HTT_RX_IND_END_VALID_GET(word)    \
    (((word) & HTT_RX_IND_END_VALID_M) >> \
    HTT_RX_IND_END_VALID_S)

#define HTT_RX_IND_START_VALID_SET(word, value)           \
    do {                                                       \
        HTT_CHECK_SET_VAL(HTT_RX_IND_START_VALID, value); \
        (word) |= (value)  << HTT_RX_IND_START_VALID_S;   \
    } while (0)
#define HTT_RX_IND_START_VALID_GET(word)    \
    (((word) & HTT_RX_IND_START_VALID_M) >> \
    HTT_RX_IND_START_VALID_S)

#define HTT_RX_IND_RSSI_PRI20_SET(word, value)           \
    do {                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_RSSI_PRI20, value); \
        (word) |= (value)  << HTT_RX_IND_RSSI_PRI20_S;   \
    } while (0)
#define HTT_RX_IND_RSSI_PRI20_GET(word)    \
    (((word) & HTT_RX_IND_RSSI_PRI20_M) >> \
    HTT_RX_IND_RSSI_PRI20_S)

#define HTT_RX_IND_RSSI_EXT20_SET(word, value)           \
    do {                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_RSSI_EXT20, value); \
        (word) |= (value)  << HTT_RX_IND_RSSI_EXT20_S;   \
    } while (0)
#define HTT_RX_IND_RSSI_EXT20_GET(word)    \
    (((word) & HTT_RX_IND_RSSI_EXT20_M) >> \
    HTT_RX_IND_RSSI_EXT20_S)

#define HTT_RX_IND_RSSI_EXT40_SET(word, value)           \
    do {                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_RSSI_EXT40, value); \
        (word) |= (value)  << HTT_RX_IND_RSSI_EXT40_S;   \
    } while (0)
#define HTT_RX_IND_RSSI_EXT40_GET(word)    \
    (((word) & HTT_RX_IND_RSSI_EXT40_M) >> \
    HTT_RX_IND_RSSI_EXT40_S)

#define HTT_RX_IND_RSSI_EXT80_SET(word, value)           \
    do {                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_RSSI_EXT80, value); \
        (word) |= (value)  << HTT_RX_IND_RSSI_EXT80_S;   \
    } while (0)
#define HTT_RX_IND_RSSI_EXT80_GET(word)    \
    (((word) & HTT_RX_IND_RSSI_EXT80_M) >> \
    HTT_RX_IND_RSSI_EXT80_S)

#define HTT_RX_IND_VHT_SIG_A1_SET(word, value)           \
    do {                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_VHT_SIG_A1, value); \
        (word) |= (value)  << HTT_RX_IND_VHT_SIG_A1_S;   \
    } while (0)
#define HTT_RX_IND_VHT_SIG_A1_GET(word)    \
    (((word) & HTT_RX_IND_VHT_SIG_A1_M) >> \
    HTT_RX_IND_VHT_SIG_A1_S)

#define HTT_RX_IND_VHT_SIG_A2_SET(word, value)           \
    do {                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_IND_VHT_SIG_A2, value); \
        (word) |= (value)  << HTT_RX_IND_VHT_SIG_A2_S;   \
    } while (0)
#define HTT_RX_IND_VHT_SIG_A2_GET(word)    \
    (((word) & HTT_RX_IND_VHT_SIG_A2_M) >> \
    HTT_RX_IND_VHT_SIG_A2_S)

#define HTT_RX_IND_PREAMBLE_TYPE_SET(word, value)           \
    do {                                                    \
        HTT_CHECK_SET_VAL(HTT_RX_IND_PREAMBLE_TYPE, value); \
        (word) |= (value)  << HTT_RX_IND_PREAMBLE_TYPE_S;   \
    } while (0)
#define HTT_RX_IND_PREAMBLE_TYPE_GET(word)    \
    (((word) & HTT_RX_IND_PREAMBLE_TYPE_M) >> \
    HTT_RX_IND_PREAMBLE_TYPE_S)

#define HTT_RX_IND_SERVICE_SET(word, value)           \
    do {                                              \
        HTT_CHECK_SET_VAL(HTT_RX_IND_SERVICE, value); \
        (word) |= (value)  << HTT_RX_IND_SERVICE_S;   \
    } while (0)
#define HTT_RX_IND_SERVICE_GET(word)    \
    (((word) & HTT_RX_IND_SERVICE_M) >> \
    HTT_RX_IND_SERVICE_S)


#define HTT_RX_IND_MPDU_COUNT_SET(word, value)                          \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_IND_MPDU_COUNT, value);                \
        (word) |= (value)  << HTT_RX_IND_MPDU_COUNT_S;                  \
    } while (0)
#define HTT_RX_IND_MPDU_COUNT_GET(word) \
    (((word) & HTT_RX_IND_MPDU_COUNT_M) >> HTT_RX_IND_MPDU_COUNT_S)

#define HTT_RX_IND_MPDU_STATUS_SET(word, value)                         \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_IND_MPDU_STATUS, value);               \
        (word) |= (value)  << HTT_RX_IND_MPDU_STATUS_S;                 \
    } while (0)
#define HTT_RX_IND_MPDU_STATUS_GET(word) \
    (((word) & HTT_RX_IND_MPDU_STATUS_M) >> HTT_RX_IND_MPDU_STATUS_S)

enum htt_rx_ind_mpdu_status {
    HTT_RX_IND_MPDU_STATUS_UNKNOWN = 0x0,
    HTT_RX_IND_MPDU_STATUS_OK,
    HTT_RX_IND_MPDU_STATUS_ERR_FCS,
    HTT_RX_IND_MPDU_STATUS_ERR_DUP,
    HTT_RX_IND_MPDU_STATUS_ERR_REPLAY,
    HTT_RX_IND_MPDU_STATUS_ERR_INV_PEER,
    HTT_RX_IND_MPDU_STATUS_UNAUTH_PEER, /* only accept EAPOL frames */
    HTT_RX_IND_MPDU_STATUS_OUT_OF_SYNC,
    HTT_RX_IND_MPDU_STATUS_MGMT_CTRL, /* Non-data in promiscous mode */
    HTT_RX_IND_MPDU_STATUS_TKIP_MIC_ERR,
    HTT_RX_IND_MPDU_STATUS_DECRYPT_ERR,
    HTT_RX_IND_MPDU_STATUS_MPDU_LENGTH_ERR,
    /*
     * MISC: discard for unspecified reasons.
     * Leave this enum value last.
     */
    HTT_RX_IND_MPDU_STATUS_ERR_MISC = 0xFF
};

#define HTT_RX_IND_HL_BYTES                               \
    (HTT_RX_IND_HDR_BYTES +                               \
     4 /* single FW rx MSDU descriptor, plus padding */ + \
     4 /* single MPDU range information element */)
#define HTT_RX_IND_HL_SIZE32 (HTT_RX_IND_HL_BYTES >> 2)

// Could we use one macro entry?
#define HTT_WORD_SET(word, field, value) \
    do { \
        HTT_CHECK_SET_VAL(field, value); \
        (word) |= ((value) << field ## _S); \
    } while (0)
#define HTT_WORD_GET(word, field) \
    (((word) & field ## _M) >> field ## _S)

PREPACK struct hl_htt_rx_ind_base {
    A_UINT32 rx_ind_msg[HTT_RX_IND_HL_SIZE32];    /* algin with LL case rx indication message, but reduced to 5 words */
} POSTPACK;

/*
 * HTT_RX_IND_HL_RX_DESC_BASE_OFFSET
 * Currently, we use a resv field in hl_htt_rx_ind_base to store some
 * HL host needed info. The field is just after the msdu fw rx desc.
 */
#define HTT_RX_IND_HL_RX_DESC_BASE_OFFSET (HTT_RX_IND_FW_RX_DESC_BYTE_OFFSET + 1)
struct htt_rx_ind_hl_rx_desc_t {
    A_UINT8 ver;
    A_UINT8 len;
    struct {
        A_UINT8
            first_msdu: 1,
            last_msdu: 1,
            c3_failed: 1,
            c4_failed: 1,
            ipv6: 1,
            tcp: 1,
            udp: 1,
            reserved: 1;
    } flags;
};

#define HTT_RX_IND_HL_RX_DESC_VER_OFFSET \
    (HTT_RX_IND_HL_RX_DESC_BASE_OFFSET \
     + offsetof(struct htt_rx_ind_hl_rx_desc_t, ver))
#define HTT_RX_IND_HL_RX_DESC_VER 0

#define HTT_RX_IND_HL_RX_DESC_LEN_OFFSET \
    (HTT_RX_IND_HL_RX_DESC_BASE_OFFSET \
     + offsetof(struct htt_rx_ind_hl_rx_desc_t, len))

#define HTT_RX_IND_HL_FLAG_OFFSET \
    (HTT_RX_IND_HL_RX_DESC_BASE_OFFSET \
     + offsetof(struct htt_rx_ind_hl_rx_desc_t, flags))

#define HTT_RX_IND_HL_FLAG_FIRST_MSDU   (0x01 << 0)
#define HTT_RX_IND_HL_FLAG_LAST_MSDU    (0x01 << 1)
#define HTT_RX_IND_HL_FLAG_C3_FAILED    (0x01 << 2) // L3 checksum failed
#define HTT_RX_IND_HL_FLAG_C4_FAILED    (0x01 << 3) // L4 checksum failed
#define HTT_RX_IND_HL_FLAG_IPV6         (0x01 << 4) // is ipv6, or else ipv4
#define HTT_RX_IND_HL_FLAG_TCP          (0x01 << 5) // is tcp
#define HTT_RX_IND_HL_FLAG_UDP          (0x01 << 6) // is udp
/* This structure is used in HL, the basic descriptor information
 * used by host. the structure is translated by FW from HW desc
 * or generated by FW. But in HL monitor mode, the host would use
 * the same structure with LL.
 */
PREPACK struct hl_htt_rx_desc_base {
    A_UINT32
        seq_num:12,
        encrypted:1,
        resv0:3,
        mcast_bcast:1,
        fragment:1,
        resv1:14;
    A_UINT32
        pn_31_0;
    union {
        struct {
            A_UINT16 pn_47_32;
            A_UINT16 pn_63_48;
        } pn16;
        A_UINT32 pn_63_32;
    } u0;
    A_UINT32
        pn_95_64;
    A_UINT32
        pn_127_96;
} POSTPACK;

#define HL_RX_DESC_SIZE         (sizeof(struct hl_htt_rx_desc_base))
#define HL_RX_DESC_SIZE_DWORD   (HL_RX_STD_DESC_SIZE >> 2)

#define HTT_HL_RX_DESC_MPDU_SEQ_NUM_M       0xfff
#define HTT_HL_RX_DESC_MPDU_SEQ_NUM_S       0
#define HTT_HL_RX_DESC_MPDU_ENC_M           0x1000
#define HTT_HL_RX_DESC_MPDU_ENC_S           12
#define HTT_HL_RX_DESC_MCAST_BCAST_M        0x10000
#define HTT_HL_RX_DESC_MCAST_BCAST_S        16
#define HTT_HL_RX_DESC_FRAGMENT_M           0x20000
#define HTT_HL_RX_DESC_FRAGMENT_S           17

#define HTT_HL_RX_DESC_PN_OFFSET            offsetof(struct hl_htt_rx_desc_base, pn_31_0)
#define HTT_HL_RX_DESC_PN_WORD_OFFSET       (HTT_HL_RX_DESC_PN_OFFSET >> 2)

/*
 * @brief target -> host rx reorder flush message definition
 *
 * @details
 * The following field definitions describe the format of the rx flush
 * message sent from the target to the host.
 * The message consists of a 4-octet header, followed by one or more
 * 4-octet payload information elements.
 *
 *     |31           24|23                            8|7            0|
 *     |--------------------------------------------------------------|
 *     |       TID     |          peer ID              |   msg type   |
 *     |--------------------------------------------------------------|
 *     |  seq num end  | seq num start |  MPDU status  |   reserved   |
 *     |--------------------------------------------------------------|
 * First DWORD:
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as an rx flush message
 *     Value: 0x2
 *   - PEER_ID
 *     Bits 23:8 (only bits 18:8 actually used)
 *     Purpose: identify which peer's rx data is being flushed
 *     Value: (rx) peer ID
 *   - TID
 *     Bits 31:24 (only bits 27:24 actually used)
 *     Purpose: Specifies which traffic identifier's rx data is being flushed
 *     Value: traffic identifier
 * Second DWORD:
 *   - MPDU_STATUS
 *     Bits 15:8
 *     Purpose:
 *         Indicate whether the flushed MPDUs should be discarded or processed.
 *     Value:
 *         0x1:   send the MPDUs from the rx reorder buffer to subsequent
 *                stages of rx processing
 *         other: discard the MPDUs
 *         It is anticipated that flush messages will always have
 *         MPDU status == 1, but the status flag is included for
 *         flexibility.
 *   - SEQ_NUM_START
 *     Bits 23:16
 *     Purpose:
 *         Indicate the start of a series of consecutive MPDUs being flushed.
 *         Not all MPDUs within this range are necessarily valid - the host
 *         must check each sequence number within this range to see if the
 *         corresponding MPDU is actually present.
 *     Value:
 *         The sequence number for the first MPDU in the sequence.
 *         This sequence number is the 6 LSBs of the 802.11 sequence number.
 *   - SEQ_NUM_END
 *     Bits 30:24
 *     Purpose:
 *         Indicate the end of a series of consecutive MPDUs being flushed.
 *     Value:
 *         The sequence number one larger than the sequence number of the
 *         last MPDU being flushed.
 *         This sequence number is the 6 LSBs of the 802.11 sequence number.
 *         The range of MPDUs from [SEQ_NUM_START,SEQ_NUM_END-1] inclusive
 *         are to be released for further rx processing.
 *         Not all MPDUs within this range are necessarily valid - the host
 *         must check each sequence number within this range to see if the
 *         corresponding MPDU is actually present.
 */
/* first DWORD */
#define HTT_RX_FLUSH_PEER_ID_M  0xffff00
#define HTT_RX_FLUSH_PEER_ID_S  8
#define HTT_RX_FLUSH_TID_M      0xff000000
#define HTT_RX_FLUSH_TID_S      24
/* second DWORD */
#define HTT_RX_FLUSH_MPDU_STATUS_M   0x0000ff00
#define HTT_RX_FLUSH_MPDU_STATUS_S   8
#define HTT_RX_FLUSH_SEQ_NUM_START_M 0x00ff0000
#define HTT_RX_FLUSH_SEQ_NUM_START_S 16
#define HTT_RX_FLUSH_SEQ_NUM_END_M   0xff000000
#define HTT_RX_FLUSH_SEQ_NUM_END_S   24

#define HTT_RX_FLUSH_BYTES 8

#define HTT_RX_FLUSH_PEER_ID_SET(word, value)                           \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_FLUSH_PEER_ID, value);                 \
        (word) |= (value)  << HTT_RX_FLUSH_PEER_ID_S;                   \
    } while (0)
#define HTT_RX_FLUSH_PEER_ID_GET(word) \
    (((word) & HTT_RX_FLUSH_PEER_ID_M) >> HTT_RX_FLUSH_PEER_ID_S)

#define HTT_RX_FLUSH_TID_SET(word, value)                               \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_FLUSH_TID, value);                     \
        (word) |= (value)  << HTT_RX_FLUSH_TID_S;                       \
    } while (0)
#define HTT_RX_FLUSH_TID_GET(word) \
    (((word) & HTT_RX_FLUSH_TID_M) >> HTT_RX_FLUSH_TID_S)

#define HTT_RX_FLUSH_MPDU_STATUS_SET(word, value)                       \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_FLUSH_MPDU_STATUS, value);             \
        (word) |= (value)  << HTT_RX_FLUSH_MPDU_STATUS_S;               \
    } while (0)
#define HTT_RX_FLUSH_MPDU_STATUS_GET(word) \
    (((word) & HTT_RX_FLUSH_MPDU_STATUS_M) >> HTT_RX_FLUSH_MPDU_STATUS_S)

#define HTT_RX_FLUSH_SEQ_NUM_START_SET(word, value)                     \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_FLUSH_SEQ_NUM_START, value);           \
        (word) |= (value)  << HTT_RX_FLUSH_SEQ_NUM_START_S;             \
    } while (0)
#define HTT_RX_FLUSH_SEQ_NUM_START_GET(word) \
    (((word) & HTT_RX_FLUSH_SEQ_NUM_START_M) >> HTT_RX_FLUSH_SEQ_NUM_START_S)

#define HTT_RX_FLUSH_SEQ_NUM_END_SET(word, value)                       \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_FLUSH_SEQ_NUM_END, value);             \
        (word) |= (value)  << HTT_RX_FLUSH_SEQ_NUM_END_S;               \
    } while (0)
#define HTT_RX_FLUSH_SEQ_NUM_END_GET(word) \
    (((word) & HTT_RX_FLUSH_SEQ_NUM_END_M) >> HTT_RX_FLUSH_SEQ_NUM_END_S)

#define HTT_RX_PN_IND_PEER_ID_M  0xffff00
#define HTT_RX_PN_IND_PEER_ID_S  8
#define HTT_RX_PN_IND_TID_M      0xff000000
#define HTT_RX_PN_IND_TID_S      24
/* second DWORD */
#define HTT_RX_PN_IND_SEQ_NUM_START_M 0x000000ff
#define HTT_RX_PN_IND_SEQ_NUM_START_S 0
#define HTT_RX_PN_IND_SEQ_NUM_END_M   0x0000ff00
#define HTT_RX_PN_IND_SEQ_NUM_END_S   8
#define HTT_RX_PN_IND_PN_IE_CNT_M     0x00ff0000
#define HTT_RX_PN_IND_PN_IE_CNT_S     16

#define HTT_RX_PN_IND_BYTES 8

#define HTT_RX_PN_IND_PEER_ID_SET(word, value)                           \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_PN_IND_PEER_ID, value);                 \
        (word) |= (value)  << HTT_RX_PN_IND_PEER_ID_S;                   \
    } while (0)
#define HTT_RX_PN_IND_PEER_ID_GET(word) \
    (((word) & HTT_RX_PN_IND_PEER_ID_M) >> HTT_RX_PN_IND_PEER_ID_S)

#define HTT_RX_PN_IND_EXT_TID_SET(word, value)                               \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_PN_IND_TID, value);                     \
        (word) |= (value)  << HTT_RX_PN_IND_TID_S;                       \
    } while (0)
#define HTT_RX_PN_IND_EXT_TID_GET(word) \
    (((word) & HTT_RX_PN_IND_TID_M) >> HTT_RX_PN_IND_TID_S)

#define HTT_RX_PN_IND_SEQ_NUM_START_SET(word, value)                     \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_PN_IND_SEQ_NUM_START, value);           \
        (word) |= (value)  << HTT_RX_PN_IND_SEQ_NUM_START_S;             \
    } while (0)
#define HTT_RX_PN_IND_SEQ_NUM_START_GET(word) \
    (((word) & HTT_RX_PN_IND_SEQ_NUM_START_M) >> HTT_RX_PN_IND_SEQ_NUM_START_S)

#define HTT_RX_PN_IND_SEQ_NUM_END_SET(word, value)                       \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_PN_IND_SEQ_NUM_END, value);             \
        (word) |= (value)  << HTT_RX_PN_IND_SEQ_NUM_END_S;               \
    } while (0)
#define HTT_RX_PN_IND_SEQ_NUM_END_GET(word) \
    (((word) & HTT_RX_PN_IND_SEQ_NUM_END_M) >> HTT_RX_PN_IND_SEQ_NUM_END_S)

#define HTT_RX_PN_IND_PN_IE_CNT_SET(word, value)                         \
    do {                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_PN_IND_PN_IE_CNT, value);               \
        (word) |= (value) << HTT_RX_PN_IND_PN_IE_CNT_S;                  \
    } while(0)
#define HTT_RX_PN_IND_PN_IE_CNT_GET(word)   \
    (((word) & HTT_RX_PN_IND_PN_IE_CNT_M) >> HTT_RX_PN_IND_PN_IE_CNT_S)
#define HTT_RX_PN_IND_BYTES 8
#define HTT_RX_OFFLOAD_DELIVER_IND_HDR_BYTES          4
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_HDR_BYTES     7

#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_CNT_M         0xffff0000
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_CNT_S         16
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_LEN_M         0x0000ffff
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_LEN_S         0
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_PEER_ID_M     0xffff0000
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_PEER_ID_S     16
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_VDEV_ID_M     0x000000ff
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_VDEV_ID_S     0
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_TID_M         0x0000ff00
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_TID_S         8
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_DESC_M        0x00ff0000
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_DESC_S        16

#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_CNT_GET(word)                                             \
    (((word) & HTT_RX_OFFLOAD_DELIVER_IND_MSDU_CNT_M) >> HTT_RX_OFFLOAD_DELIVER_IND_MSDU_CNT_S)
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_CNT_SET(word, value)                                      \
    do {                                                                                        \
        HTT_CHECK_SET_VAL(HTT_RX_OFFLOAD_DELIVER_IND_MSDU_CNT, value);                            \
        (word) |= (value) << HTT_RX_OFFLOAD_DELIVER_IND_MSDU_CNT_S;                               \
    } while(0)                                                                                  \

#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_LEN_GET(word)                                                 \
    (((word) & HTT_RX_OFFLOAD_DELIVER_IND_MSDU_LEN_M) >> HTT_RX_OFFLOAD_DELIVER_IND_MSDU_LEN_S)
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_LEN_SET(word, value)                                          \
    do {                                                                                                 \
        HTT_CHECK_SET_VAL(HTT_RX_OFFLOAD_DELIVER_IND_MSDU_LEN, value);                                \
        (word) |= (value) << HTT_RX_OFFLOAD_DELIVER_IND_MSDU_LEN_S;                                   \
    } while(0)                                                                                           \

#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_PEER_ID_GET(word)                                             \
    (((word) & HTT_RX_OFFLOAD_DELIVER_IND_MSDU_PEER_ID_M) >> HTT_RX_OFFLOAD_DELIVER_IND_MSDU_PEER_ID_S)
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_PEER_ID_SET(word, value)                                      \
    do {                                                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_OFFLOAD_DELIVER_IND_MSDU_PEER_ID, value);                            \
        (word) |= (value) << HTT_RX_OFFLOAD_DELIVER_IND_MSDU_PEER_ID_S;                               \
    } while(0)                                                                                      \

#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_VDEV_ID_GET(word)                                             \
    (((word) & HTT_RX_OFFLOAD_DELIVER_IND_MSDU_VDEV_ID_M) >> HTT_RX_OFFLOAD_DELIVER_IND_MSDU_VDEV_ID_S)
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_VDEV_ID_SET(word, value)                                      \
    do {                                                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_OFFLOAD_DELIVER_IND_MSDU_VDEV_ID, value);                            \
        (word) |= (value) << HTT_RX_OFFLOAD_DELIVER_IND_MSDU_VDEV_ID_S;                               \
    } while(0)                                                                                      \

#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_TID_GET(word)                                                 \
    (((word) & HTT_RX_OFFLOAD_DELIVER_IND_MSDU_TID_M) >> HTT_RX_OFFLOAD_DELIVER_IND_MSDU_TID_S)
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_TID_SET(word, value)                                          \
    do {                                                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_OFFLOAD_DELIVER_IND_MSDU_TID, value);                                \
        (word) |= (value) << HTT_RX_OFFLOAD_DELIVER_IND_MSDU_TID_S;                                   \
    } while(0)                                                                                      \

#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_DESC_GET(word)                                                 \
    (((word) & HTT_RX_OFFLOAD_DELIVER_IND_MSDU_DESC_M) >> HTT_RX_OFFLOAD_DELIVER_IND_MSDU_DESC_S)
#define HTT_RX_OFFLOAD_DELIVER_IND_MSDU_DESC_SET(word, value)                                          \
    do {                                                                                            \
        HTT_CHECK_SET_VAL(HTT_RX_OFFLOAD_DELIVER_IND_MSDU_DESC, value);                                \
        (word) |= (value) << HTT_RX_OFFLOAD_DELIVER_IND_MSDU_DESC_S;                                   \
    } while(0)                                                                                      \

/**
 * @brief target -> host rx connection map/unmap message definition
 *
 * @details
 * The following diagram shows the format of the rx conn map message sent
 * from the target to the host.  This layout assumes the target operates
 * as little-endian.
 *
 * |31             24|23             16|15              8|7               0|
 * |-----------------------------------------------------------------------|
 * |              peer ID              |     VDEV ID     |     msg type    |
 * |-----------------------------------------------------------------------|
 * |    MAC addr 3   |    MAC addr 2   |    MAC addr 1   |    MAC addr 0   |
 * |-----------------------------------------------------------------------|
 * |              reserved             |    MAC addr 5   |    MAC addr 4   |
 * |-----------------------------------------------------------------------|
 *
 *
 * The following diagram shows the format of the rx conn unmap message sent
 * from the target to the host.
 *
 * |31             24|23             16|15              8|7               0|
 * |-----------------------------------------------------------------------|
 * |              peer ID              |     reserved    |     msg type    |
 * |-----------------------------------------------------------------------|
 *
 * The following field definitions describe the format of the rx conn map
 * and conn unmap messages sent from the target to the host.
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as an rx conn map or conn unmap message
 *     Value: conn map -> 0x3, conn unmap -> 0x4
 *   - VDEV_ID (conn map only)
 *     Bits 15:8
 *     Purpose: Indicates which virtual device the connection is associated
 *         with.
 *     Value: vdev ID (used in the host to look up the vdev object)
 *   - PEER_ID
 *     Bits 31:16
 *     Purpose: The peer ID (index) that WAL is allocating (map) or
 *         freeing (unmap)
 *     Value: (rx) peer ID
 *   - MAC_ADDR_L32 (conn map only)
 *     Bits 31:0
 *     Purpose: Identifies which peer node the peer ID is for.
 *     Value: lower 4 bytes of peer node's MAC address
 *   - MAC_ADDR_U16 (conn map only)
 *     Bits 15:0
 *     Purpose: Identifies which peer node the peer ID is for.
 *     Value: upper 2 bytes of peer node's MAC address
 */
#define HTT_RX_PEER_MAP_VDEV_ID_M       0xff00
#define HTT_RX_PEER_MAP_VDEV_ID_S       8
#define HTT_RX_PEER_MAP_PEER_ID_M      0xffff0000
#define HTT_RX_PEER_MAP_PEER_ID_S      16
#define HTT_RX_PEER_MAP_MAC_ADDR_L32_M 0xffffffff
#define HTT_RX_PEER_MAP_MAC_ADDR_L32_S 0
#define HTT_RX_PEER_MAP_MAC_ADDR_U16_M 0xffff
#define HTT_RX_PEER_MAP_MAC_ADDR_U16_S 0

#define HTT_RX_PEER_MAP_VAP_ID_SET HTT_RX_PEER_MAP_VDEV_ID_SET /* deprecated */
#define HTT_RX_PEER_MAP_VDEV_ID_SET(word, value)                         \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_PEER_MAP_VDEV_ID, value);               \
        (word) |= (value)  << HTT_RX_PEER_MAP_VDEV_ID_S;                 \
    } while (0)
#define HTT_RX_PEER_MAP_VAP_ID_GET HTT_RX_PEER_MAP_VDEV_ID_GET /* deprecated */
#define HTT_RX_PEER_MAP_VDEV_ID_GET(word) \
    (((word) & HTT_RX_PEER_MAP_VDEV_ID_M) >> HTT_RX_PEER_MAP_VDEV_ID_S)

#define HTT_RX_PEER_MAP_PEER_ID_SET(word, value)                        \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_PEER_MAP_PEER_ID, value);              \
        (word) |= (value)  << HTT_RX_PEER_MAP_PEER_ID_S;                \
    } while (0)
#define HTT_RX_PEER_MAP_PEER_ID_GET(word) \
    (((word) & HTT_RX_PEER_MAP_PEER_ID_M) >> HTT_RX_PEER_MAP_PEER_ID_S)

#define HTT_RX_PEER_MAP_MAC_ADDR_OFFSET 4 /* bytes */

#define HTT_RX_PEER_MAP_BYTES 12


#define HTT_RX_PEER_UNMAP_PEER_ID_M   HTT_RX_PEER_MAP_PEER_ID_M
#define HTT_RX_PEER_UNMAP_PEER_ID_S   HTT_RX_PEER_MAP_PEER_ID_S

#define HTT_RX_PEER_UNMAP_PEER_ID_SET HTT_RX_PEER_MAP_PEER_ID_SET
#define HTT_RX_PEER_UNMAP_PEER_ID_GET HTT_RX_PEER_MAP_PEER_ID_GET

#define HTT_RX_PEER_UNMAP_BYTES 4

enum htt_sec_type {
    htt_sec_type_none,
    htt_sec_type_wep128,
    htt_sec_type_wep104,
    htt_sec_type_wep40,
    htt_sec_type_tkip,
    htt_sec_type_tkip_nomic,
    htt_sec_type_aes_ccmp,
    htt_sec_type_wapi,
    htt_sec_type_aes_ccmp_256,
    htt_sec_type_aes_gcmp,
    htt_sec_type_aes_gcmp_256,

    /* keep this last! */
    htt_num_sec_types
};

/**
 * @brief target -> host message specifying security parameters
 *
 * @details
 *  The following diagram shows the format of the security specification
 *  message sent from the target to the host.
 *  This security specification message tells the host whether a PN check is
 *  necessary on rx data frames, and if so, how large the PN counter is.
 *  This message also tells the host about the security processing to apply
 *  to defragmented rx frames - specifically, whether a Message Integrity
 *  Check is required, and the Michael key to use.
 *
 * |31             24|23          16|15|14              8|7               0|
 * |-----------------------------------------------------------------------|
 * |              peer ID           | U|  security type  |     msg type    |
 * |-----------------------------------------------------------------------|
 * |                           Michael Key K0                              |
 * |-----------------------------------------------------------------------|
 * |                           Michael Key K1                              |
 * |-----------------------------------------------------------------------|
 * |                           WAPI RSC Low0                               |
 * |-----------------------------------------------------------------------|
 * |                           WAPI RSC Low1                               |
 * |-----------------------------------------------------------------------|
 * |                           WAPI RSC Hi0                                |
 * |-----------------------------------------------------------------------|
 * |                           WAPI RSC Hi1                                |
 * |-----------------------------------------------------------------------|
 *
 * The following field definitions describe the format of the security
 * indication message sent from the target to the host.
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as a security specification message
 *     Value: 0xb
 *   - SEC_TYPE
 *     Bits 14:8
 *     Purpose: specifies which type of security applies to the peer
 *     Value: htt_sec_type enum value
 *   - UNICAST
 *     Bit 15
 *     Purpose: whether this security is applied to unicast or multicast data
 *     Value: 1 -> unicast, 0 -> multicast
 *   - PEER_ID
 *     Bits 31:16
 *     Purpose: The ID number for the peer the security specification is for
 *     Value: peer ID
 *   - MICHAEL_KEY_K0
 *     Bits 31:0
 *     Purpose: 4-byte word that forms the 1st half of the TKIP Michael key
 *     Value: Michael Key K0 (if security type is TKIP)
 *   - MICHAEL_KEY_K1
 *     Bits 31:0
 *     Purpose: 4-byte word that forms the 2nd half of the TKIP Michael key
 *     Value: Michael Key K1 (if security type is TKIP)
 *   - WAPI_RSC_LOW0
 *     Bits 31:0
 *     Purpose: 4-byte word that forms the 1st quarter of the 16 byte WAPI RSC
 *     Value: WAPI RSC Low0 (if security type is WAPI)
 *   - WAPI_RSC_LOW1
 *     Bits 31:0
 *     Purpose: 4-byte word that forms the 2nd quarter of the 16 byte WAPI RSC
 *     Value: WAPI RSC Low1 (if security type is WAPI)
 *   - WAPI_RSC_HI0
 *     Bits 31:0
 *     Purpose: 4-byte word that forms the 3rd quarter of the 16 byte WAPI RSC
 *     Value: WAPI RSC Hi0 (if security type is WAPI)
 *   - WAPI_RSC_HI1
 *     Bits 31:0
 *     Purpose: 4-byte word that forms the 4th quarter of the 16 byte WAPI RSC
 *     Value: WAPI RSC Hi1 (if security type is WAPI)
 */

#define HTT_SEC_IND_SEC_TYPE_M     0x00007f00
#define HTT_SEC_IND_SEC_TYPE_S     8
#define HTT_SEC_IND_UNICAST_M      0x00008000
#define HTT_SEC_IND_UNICAST_S      15
#define HTT_SEC_IND_PEER_ID_M      0xffff0000
#define HTT_SEC_IND_PEER_ID_S      16

#define HTT_SEC_IND_SEC_TYPE_SET(word, value)                       \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_SEC_IND_SEC_TYPE, value);             \
        (word) |= (value)  << HTT_SEC_IND_SEC_TYPE_S;               \
    } while (0)
#define HTT_SEC_IND_SEC_TYPE_GET(word) \
    (((word) & HTT_SEC_IND_SEC_TYPE_M) >> HTT_SEC_IND_SEC_TYPE_S)

#define HTT_SEC_IND_UNICAST_SET(word, value)                        \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_SEC_IND_UNICAST, value);              \
        (word) |= (value)  << HTT_SEC_IND_UNICAST_S;                \
    } while (0)
#define HTT_SEC_IND_UNICAST_GET(word) \
    (((word) & HTT_SEC_IND_UNICAST_M) >> HTT_SEC_IND_UNICAST_S)

#define HTT_SEC_IND_PEER_ID_SET(word, value)                        \
    do {                                                            \
        HTT_CHECK_SET_VAL(HTT_SEC_IND_PEER_ID, value);              \
        (word) |= (value)  << HTT_SEC_IND_PEER_ID_S;                \
    } while (0)
#define HTT_SEC_IND_PEER_ID_GET(word) \
    (((word) & HTT_SEC_IND_PEER_ID_M) >> HTT_SEC_IND_PEER_ID_S)


#define HTT_SEC_IND_BYTES 28


/**
 * @brief target -> host rx ADDBA / DELBA message definitions
 *
 * @details
 * The following diagram shows the format of the rx ADDBA message sent
 * from the target to the host:
 *
 * |31                      20|19  16|15              8|7               0|
 * |---------------------------------------------------------------------|
 * |          peer ID         |  TID |   window size   |     msg type    |
 * |---------------------------------------------------------------------|
 *
 * The following diagram shows the format of the rx DELBA message sent
 * from the target to the host:
 *
 * |31                      20|19  16|15              8|7               0|
 * |---------------------------------------------------------------------|
 * |          peer ID         |  TID |     reserved    |     msg type    |
 * |---------------------------------------------------------------------|
 *
 * The following field definitions describe the format of the rx ADDBA
 * and DELBA messages sent from the target to the host.
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as an rx ADDBA or DELBA message
 *     Value: ADDBA -> 0x5, DELBA -> 0x6
 *   - WIN_SIZE
 *     Bits 15:8 (ADDBA only)
 *     Purpose: Specifies the length of the block ack window (max = 64).
 *     Value:
 *         block ack window length specified by the received ADDBA
 *         management message.
 *   - TID
 *     Bits 19:16
 *     Purpose: Specifies which traffic identifier the ADDBA / DELBA is for.
 *     Value:
 *         TID specified by the received ADDBA or DELBA management message.
 *   - PEER_ID
 *     Bits 31:20
 *     Purpose: Identifies which peer sent the ADDBA / DELBA.
 *     Value:
 *         ID (hash value) used by the host for fast,  direct lookup of
 *         host SW peer info, including rx reorder states.
 */
#define HTT_RX_ADDBA_WIN_SIZE_M  0xff00
#define HTT_RX_ADDBA_WIN_SIZE_S  8
#define HTT_RX_ADDBA_TID_M       0xf0000
#define HTT_RX_ADDBA_TID_S       16
#define HTT_RX_ADDBA_PEER_ID_M   0xfff00000
#define HTT_RX_ADDBA_PEER_ID_S   20

#define HTT_RX_ADDBA_WIN_SIZE_SET(word, value)                          \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_ADDBA_WIN_SIZE, value);                \
        (word) |= (value)  << HTT_RX_ADDBA_WIN_SIZE_S;                  \
    } while (0)
#define HTT_RX_ADDBA_WIN_SIZE_GET(word) \
    (((word) & HTT_RX_ADDBA_WIN_SIZE_M) >> HTT_RX_ADDBA_WIN_SIZE_S)

#define HTT_RX_ADDBA_TID_SET(word, value)                               \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_ADDBA_TID, value);                     \
        (word) |= (value)  << HTT_RX_ADDBA_TID_S;                       \
    } while (0)
#define HTT_RX_ADDBA_TID_GET(word) \
    (((word) & HTT_RX_ADDBA_TID_M) >> HTT_RX_ADDBA_TID_S)

#define HTT_RX_ADDBA_PEER_ID_SET(word, value)                           \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_ADDBA_PEER_ID, value);                 \
        (word) |= (value)  << HTT_RX_ADDBA_PEER_ID_S;                   \
    } while (0)
#define HTT_RX_ADDBA_PEER_ID_GET(word) \
    (((word) & HTT_RX_ADDBA_PEER_ID_M) >> HTT_RX_ADDBA_PEER_ID_S)

#define HTT_RX_ADDBA_BYTES 4


#define HTT_RX_DELBA_TID_M         HTT_RX_ADDBA_TID_M
#define HTT_RX_DELBA_TID_S         HTT_RX_ADDBA_TID_S
#define HTT_RX_DELBA_PEER_ID_M     HTT_RX_ADDBA_PEER_ID_M
#define HTT_RX_DELBA_PEER_ID_S     HTT_RX_ADDBA_PEER_ID_S

#define HTT_RX_DELBA_TID_SET       HTT_RX_ADDBA_TID_SET
#define HTT_RX_DELBA_TID_GET       HTT_RX_ADDBA_TID_GET
#define HTT_RX_DELBA_PEER_ID_SET   HTT_RX_ADDBA_PEER_ID_SET
#define HTT_RX_DELBA_PEER_ID_GET   HTT_RX_ADDBA_PEER_ID_GET

#define HTT_RX_DELBA_BYTES 4

/**
 * @brief target -> host TX completion indication message definition
 *
 * @details
 * The following diagram shows the format of the TX completion indication sent
 * from the target to the host
 *
 *          |31  27|26|25|24|23             16|  15 |14 11|10   8|7        0|
 *          |---------------------------------------------------------------|
 * header:  | rsvd |PA| P| A|      num        | t_i | tid |status| msg_type |
 *          |---------------------------------------------------------------|
 * payload: |            MSDU1 ID             |        MSDU0 ID             |
 *          |---------------------------------------------------------------|
 *          :            MSDU-N ID            :        MSDU2 ID             :
 *          |---------------------------------------------------------------|
 *          :          MSDU1 ACK-RSSI         |      MSDU0 ACK-RSSI         :
 *          |---------------------------------------------------------------|
 *          :          MSDU-N ACK-RSSI        :      MSDU2 ACK-RSSI         :
 *          - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - 
 *          |             PEER ID             |         PPDU ID             |
 *          |---------------------------------------------------------------|

 * Where:
 *     A = ack_rssi_filled flag indicating the presence of ACK-RSSI fields
 *         following the MSDU ID fields
 *     P = pp-id flag indicating the presence of PPDU-ID and peer-ID fields
 *         following the MSDU ID and ACK-RSSI fields
 *     PA = peer ID presence flag indicating the presence of valid peer-ID +
 *         dummy PPDU-ID fields following the MSDU ID and ACK-RSSI fields
 *
 * The following field definitions describe the format of the TX completion
 * indication sent from the target to the host
 * Header fields:
 * - msg_type
 *   Bits 7:0
 *   Purpose: identifies this as HTT TX completion indication
 *   Value: 0x7
 * - status
 *   Bits 10:8
 *   Purpose: the TX completion status of payload fragmentations descriptors
 *   Value: could be HTT_TX_COMPL_IND_STAT_OK or HTT_TX_COMPL_IND_STAT_DISCARD
 * - tid
 *   Bits 14:11
 *   Purpose: the tid associated with those fragmentation descriptors. It is
 *            valid or not, depending on the tid_invalid bit.
 *   Value: 0 to 15
 * - tid_invalid
 *   Bits 15:15
 *   Purpose: this bit indicates whether the tid field is valid or not
 *   Value: 0 indicates valid; 1 indicates invalid
 * - num
 *   Bits 23:16
 *   Purpose: the number of payload in this indication
 *   Value: 1 to 255
 * - ack_rssi_filled
 *   Bit 24
 *   Purpose: To know ack rssi packing status. This filed will be set
 *            only when status ok. ACK RSSI space will only be part of
 *            the message if it's actualy filled in with valid ACK RSSI
 *   Value: 0 - ack rssi is not packed in the message.
 *          1 - ack rssi is packed after msdu ids.
 * - pp-id
 *   Bit 25
 *   Purpose: To know PPDU-ID & PEER-ID packing status. This flag will be set
 *            only when TX_DATA_CAPTURE is enabled. PPDU-ID & PEER-ID fields
 *            will only be appended to the message when TX_DATA_CAPTURE is
 *            enabled.
 *   Value: 0 - PPDU-ID & PEER-ID fields are not appended to the message.
 *          1 - PPDU-ID & PEER-ID fields are appended after MSDU ID and
 *              ack-RSSI fields
 * - Peer ID Present (PA)
 *   Bit 26
 *   Purpose: To know PPDU-ID & PEER-ID packing status. This flag will be set
 *            only when TX_DATA_CAPTURE is not enabled.
 *   Value: 0 - PPDU-ID field is not appended to the message.
 *          1 - PEER-ID field is updated with ast index but PPDU-ID field is
 *              set to 0 to the message.
 *
 * Payload fields:
 * - hmsdu_id
 *   Bits 15:0
 *   Purpose: this ID is used to track the Tx buffer in host
 *   Value: 0 to "size of host MSDU descriptor pool - 1"
 * - msdu-ack-rssi
 *   Bits 15:0
 *   Purpose: Carries ack rssi value of msdu id.
 *            Valid only if ack_rssi_filled is set.
 * - PPDU-ID
 *   Bits 15:0
 *   Purpose: This ID is used to allow the host to correlate the tx_status
 *            of each packet sent through packet log DMA engine and the MSDU
 *            completion message of each packet sent through HTT DMA engine.
 * - PEER-ID
 *   Bits 31:16
 *   Purpose: This ID also serves a similar purpose to PPDU-ID.
 *            Also it helps in mapping the MSDUs to corresponding peer
 */

#define HTT_TX_COMPL_IND_STATUS_S      8
#define HTT_TX_COMPL_IND_STATUS_M      0x700
#define HTT_TX_COMPL_IND_TID_S         11
#define HTT_TX_COMPL_IND_TID_M         0x7800
#define HTT_TX_COMPL_IND_TID_INV_S     15
#define HTT_TX_COMPL_IND_TID_INV_M     0x8000
#define HTT_TX_COMPL_IND_NUM_S         16
#define HTT_TX_COMPL_IND_NUM_M         0xff0000
#define HTT_TX_COMPL_IND_ACK_RSSI_PRESENT_S   24
#define HTT_TX_COMPL_IND_ACK_RSSI_PRESENT_M   0x1000000
#define HTT_TX_COMPL_IND_PPDU_PEER_ID_PRESENT_S 25
#define HTT_TX_COMPL_IND_PPDU_PEER_ID_PRESENT_M 0x2000000
#define HTT_TX_COMPL_IND_PEER_ID_PRESENT_S 26
#define HTT_TX_COMPL_IND_PEER_ID_PRESENT_M 0x4000000
#define HTT_TX_COMPL_IND_PPDU_ID_S  0
#define HTT_TX_COMPL_IND_PPDU_ID_M  0x0000ffff
#define HTT_TX_COMPL_IND_PEER_ID_S  16
#define HTT_TX_COMPL_IND_PEER_ID_M  0xffff0000

#define HTT_TX_COMPL_IND_STATUS_SET(_info, _val)                        \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_TX_COMPL_IND_STATUS, _val);               \
        ((_info) |= ((_val) << HTT_TX_COMPL_IND_STATUS_S));             \
    } while (0)
#define HTT_TX_COMPL_IND_STATUS_GET(_info)                              \
    (((_info) & HTT_TX_COMPL_IND_STATUS_M) >> HTT_TX_COMPL_IND_STATUS_S)
#define HTT_TX_COMPL_IND_NUM_SET(_info, _val)                           \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_TX_COMPL_IND_NUM, _val);                  \
        ((_info) |= ((_val) << HTT_TX_COMPL_IND_NUM_S));                \
    } while (0)
#define HTT_TX_COMPL_IND_NUM_GET(_info)                             \
    (((_info) & HTT_TX_COMPL_IND_NUM_M) >> HTT_TX_COMPL_IND_NUM_S)
#define HTT_TX_COMPL_IND_TID_SET(_info, _val)                           \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_TX_COMPL_IND_TID, _val);                  \
        ((_info) |= ((_val) << HTT_TX_COMPL_IND_TID_S));                \
    } while (0)
#define HTT_TX_COMPL_IND_TID_GET(_info)                             \
    (((_info) & HTT_TX_COMPL_IND_TID_M) >> HTT_TX_COMPL_IND_TID_S)
#define HTT_TX_COMPL_IND_TID_INV_SET(_info, _val)                       \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_TX_COMPL_IND_TID_INV, _val);              \
        ((_info) |= ((_val) << HTT_TX_COMPL_IND_TID_INV_S));            \
    } while (0)
#define HTT_TX_COMPL_IND_TID_INV_GET(_info)                         \
    (((_info) & HTT_TX_COMPL_IND_TID_INV_M) >>                      \
     HTT_TX_COMPL_IND_TID_INV_S)

#define HTT_TX_COMPL_IND_ACK_RSSI_PRESENT_SET(_info, _val)              \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_TX_COMPL_IND_ACK_RSSI_PRESENT, _val);     \
        ((_info) |= ((_val) << HTT_TX_COMPL_IND_ACK_RSSI_PRESENT_S));   \
    } while (0)

#define HTT_TX_COMPL_IND_ACK_RSSI_PRESENT_GET(_info)                     \
        (((_info) & HTT_TX_COMPL_IND_ACK_RSSI_PRESENT_M) >> HTT_TX_COMPL_IND_ACK_RSSI_PRESENT_S)

#define HTT_TX_COMPL_IND_PPDU_PEER_ID_PRESENT_SET(_info, _val) \
    do { \
        HTT_CHECK_SET_VAL(HTT_TX_COMPL_IND_PPDU_PEER_ID_PRESENT, _val); \
        ((_info) |= ((_val) << HTT_TX_COMPL_IND_PPDU_PEER_ID_PRESENT_S)); \
    } while (0)

#define HTT_TX_COMPL_IND_PPDU_PEER_ID_PRESENT_GET(_info) \
        (((_info) & HTT_TX_COMPL_IND_PPDU_PEER_ID_PRESENT_M) >> HTT_TX_COMPL_IND_PPDU_PEER_ID_PRESENT_S)

#define HTT_TX_COMPL_IND_PEER_ID_PRESENT_SET(_info, _val) \
    do { \
        HTT_CHECK_SET_VAL(HTT_TX_COMPL_IND_PEER_ID_PRESENT, _val); \
        ((_info) |= ((_val) << HTT_TX_COMPL_IND_PEER_ID_PRESENT_S)); \
    } while (0)
 
#define HTT_TX_COMPL_IND_PEER_ID_PRESENT_GET(_info) \
        (((_info) & HTT_TX_COMPL_IND_PEER_ID_PRESENT_M) >> HTT_TX_COMPL_IND_PEER_ID_PRESENT_S)

#define HTT_TX_COMPL_IND_PPDU_ID_SET(_info, _val) \
    do { \
        HTT_CHECK_SET_VAL(HTT_TX_COMPL_IND_PPDU_ID, _val); \
        ((_info) |= ((_val) << HTT_TX_COMPL_IND_PPDU_ID_S)); \
    } while (0)

#define HTT_TX_COMPL_IND_PPDU_ID_GET(_info, _val) \
      (((_info) & HTT_TX_COMPL_IND_PPDU_ID_M) >> HTT_TX_COMPL_IND_PPDU_ID_S)

#define HTT_TX_COMPL_IND_PEER_ID_SET(_info, _val) \
    do { \
        HTT_CHECK_SET_VAL(HTT_TX_COMPL_IND_PEER_ID, _val); \
        ((_info) |= ((_val) << HTT_TX_COMPL_IND_PEER_ID_S)); \
    } while (0)

#define HTT_TX_COMPL_IND_PEER_ID_GET(_info, _val) \
      (((_info) & HTT_TX_COMPL_IND_PEER_ID_M) >> HTT_TX_COMPL_IND_PEER_ID_S)


#define HTT_TX_COMPL_CTXT_SZ                sizeof(A_UINT16)
#define HTT_TX_COMPL_CTXT_NUM(_bytes)       ((_bytes) >> 1)

#define HTT_TX_COMPL_INV_MSDU_ID            0xffff

#define HTT_TX_COMPL_IND_STAT_OK          0
#define HTT_TX_COMPL_IND_STAT_DISCARD     1
#define HTT_TX_COMPL_IND_STAT_NO_ACK      2
#define HTT_TX_COMPL_IND_STAT_POSTPONE    3

PREPACK struct htt_tx_compl_ind_base {
    A_UINT32 hdr;
    A_UINT16 payload[1/*or more*/];
} POSTPACK;


/**
 * @brief target -> host rate-control update indication message
 *
 * @details
 * The following diagram shows the format of the RC Update message
 * sent from the target to the host, while processing the tx-completion
 * of a transmitted PPDU.
 *
 *          |31          24|23           16|15            8|7            0|
 *          |-------------------------------------------------------------|
 *          |            peer ID           |    vdev ID    |    msg_type  |
 *          |-------------------------------------------------------------|
 *          |  MAC addr 3  |  MAC addr 2   |   MAC addr 1  |  MAC addr 0  |
 *          |-------------------------------------------------------------|
 *          |   reserved   |   num elems   |   MAC addr 5  |  MAC addr 4  |
 *          |-------------------------------------------------------------|
 *          |                              :                              |
 *          :         HTT_RC_TX_DONE_PARAMS (DWORD-aligned)               :
 *          |                              :                              |
 *          |-------------------------------------------------------------|
 *          |                              :                              |
 *          :         HTT_RC_TX_DONE_PARAMS (DWORD-aligned)               :
 *          |                              :                              |
 *          |-------------------------------------------------------------|
 *          :                                                             :
 *          - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 */

typedef struct {
    A_UINT32 rate_code; /* rate code, bw, chain mask sgi */
    A_UINT32 rate_code_flags;
    A_UINT32 flags;       /* Encodes information such as excessive
                                                  retransmission, aggregate, some info
                                                  from .11 frame control,
                                                  STBC, LDPC, (SGI and Tx Chain Mask
                                                  are encoded in ptx_rc->flags field),
                                                  AMPDU truncation (BT/time based etc.),
                                                  RTS/CTS attempt  */

    A_UINT32 num_enqued;  /* # of MPDUs (for non-AMPDU 1) for this rate */
    A_UINT32 num_retries; /* Total # of transmission attempt for this rate */
    A_UINT32 num_failed;  /* # of failed MPDUs in A-MPDU, 0 otherwise */
    A_UINT32 ack_rssi;    /* ACK RSSI: b'7..b'0 avg RSSI across all chain */
    A_UINT32 time_stamp ; /* ACK timestamp (helps determine age) */
    A_UINT32 is_probe;   /* Valid if probing. Else, 0 */
} HTT_RC_TX_DONE_PARAMS;

#define HTT_RC_UPDATE_CTXT_SZ     (sizeof(HTT_RC_TX_DONE_PARAMS)) /* bytes */
#define HTT_RC_UPDATE_HDR_SZ      (12) /* bytes */

#define HTT_RC_UPDATE_MAC_ADDR_OFFSET   (4) /* bytes */
#define HTT_RC_UPDATE_MAC_ADDR_LENGTH   IEEE80211_ADDR_LEN /* bytes */

#define HTT_RC_UPDATE_VDEVID_S    8
#define HTT_RC_UPDATE_VDEVID_M    0xff00
#define HTT_RC_UPDATE_PEERID_S    16
#define HTT_RC_UPDATE_PEERID_M    0xffff0000

#define HTT_RC_UPDATE_NUM_ELEMS_S   16
#define HTT_RC_UPDATE_NUM_ELEMS_M   0x00ff0000

#define HTT_RC_UPDATE_VDEVID_SET(_info, _val)              \
    do {                                                   \
        HTT_CHECK_SET_VAL(HTT_RC_UPDATE_VDEVID, _val);     \
        ((_info) |= ((_val) << HTT_RC_UPDATE_VDEVID_S));   \
    } while (0)

#define HTT_RC_UPDATE_VDEVID_GET(_info)                    \
    (((_info) & HTT_RC_UPDATE_VDEVID_M) >> HTT_RC_UPDATE_VDEVID_S)

#define HTT_RC_UPDATE_PEERID_SET(_info, _val)              \
    do {                                                   \
        HTT_CHECK_SET_VAL(HTT_RC_UPDATE_PEERID, _val);     \
        ((_info) |= ((_val) << HTT_RC_UPDATE_PEERID_S));   \
    } while (0)

#define HTT_RC_UPDATE_PEERID_GET(_info)                    \
    (((_info) & HTT_RC_UPDATE_PEERID_M) >> HTT_RC_UPDATE_PEERID_S)

#define HTT_RC_UPDATE_NUM_ELEMS_SET(_info, _val)            \
    do {                                                    \
        HTT_CHECK_SET_VAL(HTT_RC_UPDATE_NUM_ELEMS, _val);   \
        ((_info) |= ((_val) << HTT_RC_UPDATE_NUM_ELEMS_S)); \
    } while (0)

#define HTT_RC_UPDATE_NUM_ELEMS_GET(_info)                  \
    (((_info) & HTT_RC_UPDATE_NUM_ELEMS_M) >> HTT_RC_UPDATE_NUM_ELEMS_S)


/**
 * @brief target -> host rx fragment indication message definition
 *
 * @details
 * The following field definitions describe the format of the rx fragment
 * indication message sent from the target to the host.
 * The rx fragment indication message shares the format of the
 * rx indication message, but not all fields from the rx indication message
 * are relevant to the rx fragment indication message.
 *
 *
 *     |31       24|23         18|17|16|15|14|13|12|11|10|9|8|7|6|5|4     0|
 *     |-----------+-------------------+---------------------+-------------|
 *     |             peer ID           |     |FV| ext TID    |  msg type   |
 *     |-------------------------------------------------------------------|
 *     |                                           |    flush    |  flush  |
 *     |                                           |     end     |  start  |
 *     |                                           |   seq num   | seq num |
 *     |-------------------------------------------------------------------|
 *     |           reserved            |         FW rx desc bytes          |
 *     |-------------------------------------------------------------------|
 *     |                                                     | FW MSDU Rx  |
 *     |                                                     |   desc B0   |
 *     |-------------------------------------------------------------------|
 * Header fields:
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as an rx fragment indication message
 *     Value: 0xa
 *   - EXT_TID
 *     Bits 12:8
 *     Purpose: identify the traffic ID of the rx data, including
 *         special "extended" TID values for multicast, broadcast, and
 *         non-QoS data frames
 *     Value: 0-15 for regular TIDs, or >= 16 for bcast/mcast/non-QoS
 *   - FLUSH_VALID (FV)
 *     Bit 13
 *     Purpose: indicate whether the flush IE (start/end sequence numbers)
 *         is valid
 *     Value:
 *         1 -> flush IE is valid and needs to be processed
 *         0 -> flush IE is not valid and should be ignored
 *   - PEER_ID
 *     Bits 31:16
 *     Purpose: Identify, by ID, which peer sent the rx data
 *     Value: ID of the peer who sent the rx data
 *   - FLUSH_SEQ_NUM_START
 *     Bits 5:0
 *     Purpose: Indicate the start of a series of MPDUs to flush
 *         Not all MPDUs within this series are necessarily valid - the host
 *         must check each sequence number within this range to see if the
 *         corresponding MPDU is actually present.
 *         This field is only valid if the FV bit is set.
 *     Value:
 *         The sequence number for the first MPDUs to check to flush.
 *         The sequence number is masked by 0x3f.
 *   - FLUSH_SEQ_NUM_END
 *     Bits 11:6
 *     Purpose: Indicate the end of a series of MPDUs to flush
 *     Value:
 *         The sequence number one larger than the sequence number of the
 *         last MPDU to check to flush.
 *         The sequence number is masked by 0x3f.
 *         Not all MPDUs within this series are necessarily valid - the host
 *         must check each sequence number within this range to see if the
 *         corresponding MPDU is actually present.
 *         This field is only valid if the FV bit is set.
 * Rx descriptor fields:
 *   - FW_RX_DESC_BYTES
 *     Bits 15:0
 *     Purpose: Indicate how many bytes in the Rx indication are used for
 *         FW Rx descriptors
 *     Value: 1
 */
#define HTT_RX_FRAG_IND_EXT_TID_SET     HTT_RX_IND_EXT_TID_SET
#define HTT_RX_FRAG_IND_EXT_TID_GET     HTT_RX_IND_EXT_TID_GET

#define HTT_RX_FRAG_IND_PEER_ID_SET     HTT_RX_IND_PEER_ID_SET
#define HTT_RX_FRAG_IND_PEER_ID_GET     HTT_RX_IND_PEER_ID_GET

#define HTT_RX_FRAG_IND_FLUSH_VALID_SET HTT_RX_IND_FLUSH_VALID_SET
#define HTT_RX_FRAG_IND_FLUSH_VALID_GET HTT_RX_IND_FLUSH_VALID_GET

#define HTT_RX_FRAG_IND_FLUSH_SEQ_NUM_START_SET \
    HTT_RX_IND_FLUSH_SEQ_NUM_START_SET
#define HTT_RX_FRAG_IND_FLUSH_SEQ_NUM_START_GET \
    HTT_RX_IND_FLUSH_SEQ_NUM_START_GET

#define HTT_RX_FRAG_IND_FLUSH_SEQ_NUM_END_SET \
    HTT_RX_IND_FLUSH_SEQ_NUM_END_SET
#define HTT_RX_FRAG_IND_FLUSH_SEQ_NUM_END_GET \
    HTT_RX_IND_FLUSH_SEQ_NUM_END_GET

#define HTT_RX_FRAG_IND_BYTES                 \
    (4 /* msg hdr */ +                        \
     4 /* flush spec */ +                     \
     4 /* (unused) FW rx desc bytes spec */ + \
     4 /* FW rx desc */)

/**
 * @brief target -> host test message definition
 *
 * @details
 * The following field definitions describe the format of the test
 * message sent from the target to the host.
 * The message consists of a 4-octet header, followed by a variable
 * number of 32-bit integer values, followed by a variable number
 * of 8-bit character values.
 *
 * |31                         16|15           8|7            0|
 * |-----------------------------------------------------------|
 * |          num chars          |   num ints   |   msg type   |
 * |-----------------------------------------------------------|
 * |                           int 0                           |
 * |-----------------------------------------------------------|
 * |                           int 1                           |
 * |-----------------------------------------------------------|
 * |                            ...                            |
 * |-----------------------------------------------------------|
 * |    char 3    |    char 2    |    char 1    |    char 0    |
 * |-----------------------------------------------------------|
 * |              |              |      ...     |    char 4    |
 * |-----------------------------------------------------------|
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as a test message
 *     Value: HTT_MSG_TYPE_TEST
 *   - NUM_INTS
 *     Bits 15:8
 *     Purpose: indicate how many 32-bit integers follow the message header
 *   - NUM_CHARS
 *     Bits 31:16
 *     Purpose: indicate how many 8-bit charaters follow the series of integers
 */
#define HTT_RX_TEST_NUM_INTS_M   0xff00
#define HTT_RX_TEST_NUM_INTS_S   8
#define HTT_RX_TEST_NUM_CHARS_M  0xffff0000
#define HTT_RX_TEST_NUM_CHARS_S  16

#define HTT_RX_TEST_NUM_INTS_SET(word, value)                           \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_TEST_NUM_INTS, value);                 \
        (word) |= (value)  << HTT_RX_TEST_NUM_INTS_S;                   \
    } while (0)
#define HTT_RX_TEST_NUM_INTS_GET(word) \
    (((word) & HTT_RX_TEST_NUM_INTS_M) >> HTT_RX_TEST_NUM_INTS_S)

#define HTT_RX_TEST_NUM_CHARS_SET(word, value)                          \
    do {                                                                \
        HTT_CHECK_SET_VAL(HTT_RX_TEST_NUM_CHARS, value);                \
        (word) |= (value)  << HTT_RX_TEST_NUM_CHARS_S;                  \
    } while (0)
#define HTT_RX_TEST_NUM_CHARS_GET(word) \
    (((word) & HTT_RX_TEST_NUM_CHARS_M) >> HTT_RX_TEST_NUM_CHARS_S)

/**
 * @brief target -> host packet log message
 *
 * @details
 * The following field definitions describe the format of the packet log
 * message sent from the target to the host.
 * The message consists of a 4-octet header,followed by a variable number
 * of 32-bit character values.
 *
 * |31          24|23          16|15           8|7            0|
 * |-----------------------------------------------------------|
 * |              |              |              |   msg type   |
 * |-----------------------------------------------------------|
 * |                        payload                            |
 * |-----------------------------------------------------------|
 *   - MSG_TYPE
 *     Bits 7:0
 *     Purpose: identifies this as a test message
 *     Value: HTT_MSG_TYPE_PACKETLOG
 */
PREPACK struct htt_pktlog_msg {
    A_UINT32    header;
    A_UINT32   payload[1/* or more */];
} POSTPACK;


/*
 * Rx reorder statistics
 * NB: all the fields must be defined in 4 octets size.
 */
struct rx_reorder_stats {
    /* Non QoS MPDUs received */
    A_UINT32 deliver_non_qos;
    /* MPDUs received in-order */
    A_UINT32 deliver_in_order;
    /* Flush due to reorder timer expired */
    A_UINT32 deliver_flush_timeout;
    /* Flush due to move out of window */
    A_UINT32 deliver_flush_oow;
    /* Flush due to DELBA */
    A_UINT32 deliver_flush_delba;
    /* MPDUs dropped due to FCS error */
    A_UINT32 fcs_error;
    /* MPDUs dropped due to monitor mode non-data packet */
    A_UINT32 mgmt_ctrl;
    /* MPDUs dropped due to invalid peer */
    A_UINT32 invalid_peer;
    /* MPDUs dropped due to duplication (non aggregation) */
    A_UINT32 dup_non_aggr;
    /* MPDUs dropped due to processed before */
    A_UINT32 dup_past;
    /* MPDUs dropped due to duplicate in reorder queue */
    A_UINT32 dup_in_reorder;
    /* Reorder timeout happened */
    A_UINT32 reorder_timeout;
    /* invalid bar ssn */
    A_UINT32 invalid_bar_ssn;
    /* reorder reset due to bar ssn */
    A_UINT32 ssn_reset;

};

/*
 * htt_dbg_stats_status -
 * present -     The requested stats have been delivered in full.
 *               This indicates that either the stats information was contained
 *               in its entirety within this message, or else this message
 *               completes the delivery of the requested stats info that was
 *               partially delivered through earlier STATS_CONF messages.
 * partial -     The requested stats have been delivered in part.
 *               One or more subsequent STATS_CONF messages with the same
 *               cookie value will be sent to deliver the remainder of the
 *               information.
 * error -       The requested stats could not be delivered, for example due
 *               to a shortage of memory to construct a message holding the
 *               requested stats.
 * invalid -     The requested stat type is either not recognized, or the
 *               target is configured to not gather the stats type in question.
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * series_done - This special value indicates that no further stats info
 *               elements are present within a series of stats info elems
 *               (within a stats upload confirmation message).
 */
enum htt_dbg_stats_status {
    HTT_DBG_STATS_STATUS_PRESENT = 0,
    HTT_DBG_STATS_STATUS_PARTIAL = 1,
    HTT_DBG_STATS_STATUS_ERROR   = 2,
    HTT_DBG_STATS_STATUS_INVALID = 3,


    HTT_DBG_STATS_STATUS_SERIES_DONE = 7
};

/**
 * @brief target -> host statistics upload
 *
 * @details
 * The following field definitions describe the format of the HTT target
 * to host stats upload confirmation message.
 * The message contains a cookie echoed from the HTT host->target stats
 * upload request, which identifies which request the confirmation is
 * for, and a series of tag-length-value stats information elements.
 * The tag-length header for each stats info element also includes a
 * status field, to indicate whether the request for the stat type in
 * question was fully met, partially met, unable to be met, or invalid
 * (if the stat type in question is disabled in the target).
 * A special value of all 1's in this status field is used to indicate
 * the end of the series of stats info elements.
 *
 *
 * |31                         16|15           8|7   5|4       0|
 * |------------------------------------------------------------|
 * |             reserved        |    VAP ID    |    msg type   |
 * |------------------------------------------------------------|
 * |                        cookie LSBs                         |
 * |------------------------------------------------------------|
 * |                        cookie MSBs                         |
 * |------------------------------------------------------------|
 * |      stats entry length     |   reserved   |  S  |stat type|
 * |------------------------------------------------------------|
 * |                                                            |
 * |                  type-specific stats info                  |
 * |                                                            |
 * |------------------------------------------------------------|
 * |      stats entry length     |   reserved   |  S  |stat type|
 * |------------------------------------------------------------|
 * |                                                            |
 * |                  type-specific stats info                  |
 * |                                                            |
 * |------------------------------------------------------------|
 * |              n/a            |   reserved   | 111 |   n/a   |
 * |------------------------------------------------------------|
 * |                  reserved                  | series done   |
 * |------------------------------------------------------------|
 * Header fields:
 *  - MSG_TYPE
 *    Bits 7:0
 *    Purpose: identifies this is a statistics upload confirmation message
 *    Value: 0x9
 *  - VAP_ID
 *    Bits 15:8
 *    Purpose: If stats are being published for a single VAP, then this field
 *        specifies which VAP's stats are provided.
 *        NOTE: Rather than directly holding VAP ID, this field holds
 *        VAP ID + 1.  This offset-by-one is used to distinguish between
 *        a VAP ID of 0 (in which case this field will contain the value 1),
 *        versus an invalid / unspecified VAP ID (in which case this field
 *        will contain the value 0, and consolidated stats for all VAPs will
 *        be reported).
 *    Value: 0  for invalid / unspecified VAP ID, or else VAP ID + 1
 *  - COOKIE_LSBS
 *    Bits 31:0
 *    Purpose: Provide a mechanism to match a target->host stats confirmation
 *        message with its preceding host->target stats request message.
 *    Value: LSBs of the opaque cookie specified by the host-side requestor
 *  - COOKIE_MSBS
 *    Bits 31:0
 *    Purpose: Provide a mechanism to match a target->host stats confirmation
 *        message with its preceding host->target stats request message.
 *    Value: MSBs of the opaque cookie specified by the host-side requestor
 *
 * Stats Information Element tag-length header fields:
 *  - STAT_TYPE
 *    Bits 4:0
 *    Purpose: identifies the type of statistics info held in the
 *        following information element
 *    Value: htt_dbg_stats_type
 *  - STATUS
 *    Bits 7:5
 *    Purpose: indicate whether the requested stats are present
 *    Value: htt_dbg_stats_status, including a special value (0x7) to mark
 *        the completion of the stats entry series
 *  - LENGTH
 *    Bits 31:16
 *    Purpose: indicate the stats information size
 *    Value: This field specifies the number of bytes of stats information
 *       that follows the element tag-length header.
 *       It is expected but not required that this length is a multiple of
 *       4 bytes.  Even if the length is not an integer multiple of 4, the
 *       subsequent stats entry header will begin on a 4-byte aligned
 *       boundary.
 */

/*
 * HTT_T2H STATS_NOUPLOAD message:
 * The STATS_NOUPLOAD message confirms back to host that although the
 * host requested stats, no stats are available.
 * This message is used in the host to free the memory associated with the
 * stats request.
 *
 * |31                         16|15           8|7   5|4       0|
 * |------------------------------------------------------------|
 * |                  reserved                  |    msg type   |
 * |------------------------------------------------------------|
 * |                        cookie LSBs                         |
 * |------------------------------------------------------------|
 * |                        cookie MSBs                         |
 * |------------------------------------------------------------|
 */

#define HTT_T2H_STATS_NOUPLOAD_HDR_SIZE   12


#define HTT_T2H_STATS_CONF_HDR_SIZE       4

#define HTT_T2H_STATS_COOKIE_SIZE         8

#define HTT_T2H_STATS_CONF_TAIL_SIZE      4

#define HTT_T2H_STATS_CONF_TLV_HDR_SIZE   4

#define HTT_T2H_STATS_CONF_HDR_VAP_ID_M     0x0000ff00
#define HTT_T2H_STATS_CONF_HDR_VAP_ID_S     8

#define HTT_T2H_STATS_CONF_HDR_VAP_ID_SET(word, vapid)           \
    do {                                                         \
        HTT_CHECK_SET_VAL(HTT_T2H_STATS_CONF_HDR_VAP_ID, vapid); \
        (word) |= ((vapid) << HTT_T2H_STATS_CONF_HDR_VAP_ID_S);  \
    } while (0)
#define HTT_T2H_STATS_CONF_HDR_VAP_ID_GET(word) \
    (((word) & HTT_T2H_STATS_CONF_HDR_VAP_ID_M) >> HTT_T2H_STATS_CONF_HDR_VAP_ID_S)

#define HTT_T2H_STATS_CONF_TLV_TYPE_M     0x0000001f
#define HTT_T2H_STATS_CONF_TLV_TYPE_S     0
#define HTT_T2H_STATS_CONF_TLV_STATUS_M   0x000000e0
#define HTT_T2H_STATS_CONF_TLV_STATUS_S   5
#define HTT_T2H_STATS_CONF_TLV_LENGTH_M   0xffff0000
#define HTT_T2H_STATS_CONF_TLV_LENGTH_S   16

/* DWORD-0 */
#define HTT_T2H_EN_STATS_PEER_ID_M           0x00000fff
#define HTT_T2H_EN_STATS_PEER_ID_S           0
#define HTT_T2H_EN_STATS_ATF_TOKENS_M        0x0ffff000
#define HTT_T2H_EN_STATS_ATF_TOKENS_S        12
#define HTT_T2H_EN_STATS_USER_POS_M          0xf0000000
#define HTT_T2H_EN_STATS_USER_POS_S          28
/* DWORD-1 */
#define HTT_T2H_EN_STATS_PKT_TYPE_M          0x00000007
#define HTT_T2H_EN_STATS_PKT_TYPE_S          0
#define HTT_T2H_EN_STATS_TID_NUM_M           0x000000f8
#define HTT_T2H_EN_STATS_TID_NUM_S           3
#define HTT_T2H_EN_STATS_MPDUS_QUEUED_M      0X0000ff00
#define HTT_T2H_EN_STATS_MPDUS_QUEUED_S      8
#define HTT_T2H_EN_STATS_MPDUS_FAILED_M      0x00ff0000
#define HTT_T2H_EN_STATS_MPDUS_FAILED_S      16
#define HTT_T2H_EN_STATS_VAP_ID_M            0x0f000000
#define HTT_T2H_EN_STATS_VAP_ID_S            24
/* DWORD-2 */
#define HTT_T2H_EN_STATS_MPDUS_TRIED_M       0x000000ff
#define HTT_T2H_EN_STATS_MPDUS_TRIED_S       0
#define HTT_T2H_EN_STATS_TX_STATUS_M         0x0000ff00
#define HTT_T2H_EN_STATS_TX_STATUS_S         8
#define HTT_T2H_EN_STATS_STARTING_SEQ_NUM_M  0xffff0000
#define HTT_T2H_EN_STATS_STARTING_SEQ_NUM_S  16

/* DWORD-(3,4,5,6) */
#define HTT_T2H_EN_STATS_RSSI_SEC_80_M       0X000000ff
#define HTT_T2H_EN_STATS_RSSI_SEC_80_S       0
#define HTT_T2H_EN_STATS_RSSI_SEC_40_M       0x0000ff00
#define HTT_T2H_EN_STATS_RSSI_SEC_40_S       8
#define HTT_T2H_EN_STATS_RSSI_SEC_20_M       0x00ff0000
#define HTT_T2H_EN_STATS_RSSI_SEC_20_S       16
#define HTT_T2H_EN_STATS_RSSI_PRI_20_M       0xff000000
#define HTT_T2H_EN_STATS_RSSI_PRI_20_S       24
/* DWORD-7 */
#define HTT_T2H_EN_STATS_RATE_M              0x000000ff
#define HTT_T2H_EN_STATS_RATE_S              0
/* DWORD-8 */
#define HTT_T2H_EN_STATS_LONG_RETRIES_M      0x000000ff
#define HTT_T2H_EN_STATS_LONG_RETRIES_S      0
#define HTT_T2H_EN_STATS_SHORT_RETRIES_M     0x0000ff00
#define HTT_T2H_EN_STATS_SHORT_RETRIES_S     8
#define HTT_T2H_EN_STATS_IS_AGGREGATE_M      0x00010000
#define HTT_T2H_EN_STATS_IS_AGGREGATE_S      16
#define HTT_T2H_EN_STATS_IS_MCAST_M          0x00020000
#define HTT_T2H_EN_STATS_IS_MCAST_S          17
#define HTT_T2H_EN_STATS_START_MSDU_ID_M     0xfffc0000
#define HTT_T2H_EN_STATS_START_MSDU_ID_S     18
/* DWORD-9 */
#define HTT_T2H_EN_STATS_MSDU_SUCCESS_M      0x0000ffff
#define HTT_T2H_EN_STATS_MSDU_SUCCESS_S      0
#define HTT_T2H_EN_STATS_BW_IDX_M            0x00ff0000
#define HTT_T2H_EN_STATS_BW_IDX_S            16
#define HTT_T2H_EN_STATS_FLAGS_M             0xff000000
#define HTT_T2H_EN_STATS_FLAGS_S             24

#define HTT_T2H_STATS_CONF_TLV_TYPE_SET(word, value)             \
    do {                                                         \
        HTT_CHECK_SET_VAL(HTT_T2H_STATS_CONF_TLV_TYPE, value);   \
        (word) |= (value)  << HTT_T2H_STATS_CONF_TLV_TYPE_S;     \
    } while (0)
#define HTT_T2H_STATS_CONF_TLV_TYPE_GET(word) \
    (((word) & HTT_T2H_STATS_CONF_TLV_TYPE_M) >> \
    HTT_T2H_STATS_CONF_TLV_TYPE_S)

#define HTT_T2H_STATS_CONF_TLV_STATUS_SET(word, value)             \
    do {                                                         \
        HTT_CHECK_SET_VAL(HTT_T2H_STATS_CONF_TLV_STATUS, value);   \
        (word) |= (value)  << HTT_T2H_STATS_CONF_TLV_STATUS_S;     \
    } while (0)
#define HTT_T2H_STATS_CONF_TLV_STATUS_GET(word) \
    (((word) & HTT_T2H_STATS_CONF_TLV_STATUS_M) >> \
    HTT_T2H_STATS_CONF_TLV_STATUS_S)

#define HTT_T2H_STATS_CONF_TLV_LENGTH_SET(word, value)             \
    do {                                                         \
        HTT_CHECK_SET_VAL(HTT_T2H_STATS_CONF_TLV_LENGTH, value);   \
        (word) |= (value)  << HTT_T2H_STATS_CONF_TLV_LENGTH_S;     \
    } while (0)
#define HTT_T2H_STATS_CONF_TLV_LENGTH_GET(word) \
    (((word) & HTT_T2H_STATS_CONF_TLV_LENGTH_M) >> \
    HTT_T2H_STATS_CONF_TLV_LENGTH_S)

#define HL_HTT_FW_RX_DESC_RSVD_SIZE 18 // should equal to HTT_MAX_AGGR
#define HTT_HL_MAX_AGGR 18


#ifdef ENHANCED_STATS
typedef PREPACK struct {
    A_UINT32 peer_id;         /*peer id of peer used in tx*/
    A_UINT32 pkt_type:8,        /*data/beacon/local frame*/
             mpdus_queued:8,     /*Number if MPDUs enqued*/
             mpdus_failed:8,     /*Number of MPDUs failed*/
             rsvd2:8;

    A_UINT32 mpdus_tried:8,       /* Number of MPDUs tried */
             tx_status:8,         /* tx completion status/tx_error */
             starting_seq_num:16;      /*Starting sequence number  used by host to determine if BA window is moving*/

    A_UINT32 rssi[4];               /* rssis for all chains */
    A_UINT32 rate;                  /* rate at which the packet is transmitted */

    A_UINT32  long_retries:8,       /* number of data attempts */
              short_retries:8,    /* number of rts,self-cts attempts  */
              is_aggregate:1,     /* boolean -> aggregate frame */
              is_mcast:1,         /* boolean -> multicast frame */
              start_msdu_id:14;   /* starting msdu id for this ppdu */

    A_UINT32 msdu_success:16,     /* msdu success count */
             bw_idx:8,
             flags:8;


    A_UINT32 success_bytes;       /* total byte count sucessful */

    A_UINT32 ppdu_duration;

}POSTPACK ppdu_common_stats;

typedef PREPACK struct {
    A_UINT32 peer_id:12,        /** Peer id of STA used in tx */
             atf_tokens:16,     /** Valid only if _ATF_ENABLE_TID flag is set */
             user_pos:4;        /** User position for MU transmissions
                                 * 0 - default value
                                 * If EN_STATS_TX_MU flag is set
                                 * 0 - user0
                                 * 1 - user1
                                 * 2 - user2 */
    A_UINT32 pkt_type:3,        /** Data/beacon/local frm: EN_STATS_PKT_TYPE */
             tid_num:5,         /** Mgmt/non-pause/data AC type */
                                /* TID         AC
                                 * 0, 3     -> WMM_AC_BE
                                 * 1, 2     -> WMM_AC_BK
                                 * 4, 5     -> WMM_AC_VI
                                 * 6, 7     -> WMM_AC_VO
                                 * EXT_TID_NON_QOS_MCAST_BCAST    16
                                 * TX_EXT_TID_MGMT                17
                                 * TX_EXT_TID_NONPAUSE            19
                                 * TX_EXT_TID_INVALID             31
                                 */
             mpdus_queued:8,    /** Number of MPDUs currently enqued in TID */
             mpdus_failed:8,    /** Number of MPDUs failed in this PPDU */
             vap_id:4,          /** vdev id 0 - 15 */
             rsvd1:4;

    A_UINT32 mpdus_tried:8,       /** Number of MPDUs tried OTA (this PPDU) */
             tx_status:8,         /** Tx completion status/tx_error
                                    * 0     - Tx ok
                                    * 0x1   - Tx error Xretry
                                    * 0x2   - Tx error Filtered
                                    * >0x2  - misc Tx error
                                    * (see EN_STATS_TX_STATUS enum) */
             starting_seq_num:16; /** Starting sequence number  used by host to determine if BA window is moving*/

    A_UINT32 rssi[4];             /** rssis for all chains */
                                    /* tx ack rssi for all chains available.
                                     * units are dB w.r.t. noise floor
                                     * *** bit alignment ***
                                     * 24 - 31 -> rssi for primary 20,
                                     * 16 - 23 -> rssi for secondary 20,
                                     * 8 -  15 -> rssi for secondary 40,
                                     * 0 - 7 -> rssi for secondary 80 */
    A_UINT32 rate:8,              /** Ratecode at which the packet is transmitted */
                                    /** rate = (((_pream) << 6) | ((_nss) << 4) | (_rate))
                                     * PREAM_OFDM   - 0
                                     * PREAM_CCK    - 1
                                     * PREAM_HT     - 2
                                     * PREAM_VHT    - 3 */

             rsvd2:24;

    A_UINT32  long_retries:8,     /** Number of data attempts */
              short_retries:8,    /** Number of rts,self-cts attempts  */
              is_aggregate:1,     /** Boolean -> aggregate frame */
              is_mcast:1,         /** Boolean -> multicast frame */
              start_msdu_id:14;   /** Starting msdu id for this ppdu */

    A_UINT32 msdu_success:16,     /** MSDU success count */
             bw_idx:8,            /** 0 - 20Mhz, 1 -40Mhz, 2 - 80Mhz, 3 - 160Mhz */
             flags:8;


    A_UINT32 success_bytes;       /** Total byte count sucessful */

    A_UINT32 ppdu_duration;       /** Tx ppdu transmit time in us */

    union {
        /*
         * TEMPORARILY MAINTAIN OLD rsvd3 FIELD UNTIL ALL REFERENCES
         * TO IT ARE REMOVED.
         */
        A_UINT32 rsvd3;
        A_UINT32 ppdu_ack_timestamp;  /** timestamp (microsecond units) when the ack was received.
                                   *  Since the host doesn't know the reference time the timestamp
                                   *  is based on, the host can't determine the absolute time when
                                   *  a specific PPDU ack was received, but it can use the timestamps
                                   *  to find the relative time between mulitple PPDU acks.
                                   */
    };

} POSTPACK ppdu_common_stats_v2;

typedef PREPACK struct {
    A_UINT32 peer_id:12,        /** Peer id of STA used in tx */
             atf_tokens:16,     /** Valid only if _ATF_ENABLE_TID flag is set */
             user_pos:4;        /** User position for MU transmissions
                                 * 0 - default value
                                 * If EN_STATS_TX_MU flag is set
                                 * 0 - user0
                                 * 1 - user1
                                 * 2 - user2
                                 * 3-7 - reserved
                                 */
    A_UINT32 pkt_type:3,        /** Data/beacon/local frm: EN_STATS_PKT_TYPE */
             tid_num:5,         /** Mgmt/non-pause/data AC type */
                                /* TID         AC
                                 * 0, 3     -> WMM_AC_BE
                                 * 1, 2     -> WMM_AC_BK
                                 * 4, 5     -> WMM_AC_VI
                                 * 6, 7     -> WMM_AC_VO
                                 * EXT_TID_NON_QOS_MCAST_BCAST    16
                                 * TX_EXT_TID_MGMT                17
                                 * TX_EXT_TID_NONPAUSE            19
                                 * TX_EXT_TID_INVALID             31
                                 */
             mpdus_queued:8,    /** Number of MPDUs currently enqued in TID */
             mpdus_failed:8,    /** Number of MPDUs failed in this PPDU */
             vap_id:4,          /** vdev id 0 - 15 */
             rsvd1:4;

    A_UINT32 mpdus_tried:8,       /** Number of MPDUs tried OTA (this PPDU) */
             tx_status:8,         /** Tx completion status/tx_error
                                    * 0     - Tx ok
                                    * 0x1   - Tx error Xretry
                                    * 0x2   - Tx error Filtered
                                    * >0x2  - misc Tx error
                                    * (see EN_STATS_TX_STATUS enum) */
             starting_seq_num:16; /** Starting sequence number  used by host to determine if BA window is moving */

    A_UINT32 rssi[4];             /** rssis for all chains
                                   * tx ack rssi for all chains available.
                                   * units are dB w.r.t. noise floor
                                   * *** bit alignment ***
                                   * 24 - 31 -> rssi for primary 20,
                                   * 16 - 23 -> rssi for secondary 20,
                                   * 8 -  15 -> rssi for secondary 40,
                                   * 0 - 7 -> rssi for secondary 80 */
    A_UINT32 rate:8,              /** Ratecode at which the packet is transmitted
                                   * rate = (((_pream) << 6) | ((_nss) << 4) | (_rate))
                                   * PREAM_OFDM   - 0
                                   * PREAM_CCK    - 1
                                   * PREAM_HT     - 2
                                   * PREAM_VHT    - 3
                                   *
                                   * _nss: 0 = 1 NSS, 1 = 2 NSS, 2 = 3 NSS, 3 = 4 NSS */
             rsvd2:24;

    A_UINT32 long_retries:8,     /** Number of data attempts */
             short_retries:8,    /** Number of rts,self-cts attempts  */
             is_aggregate:1,     /** Boolean -> aggregate(MPDU) frame */
             is_mcast:1,         /** Boolean -> multicast frame */
             start_msdu_id:14;   /** Starting msdu id for this ppdu */

    A_UINT32 msdu_success:16,     /** MSDU success count */
             bw_idx:8,            /** 0 - 20Mhz, 1 -40Mhz, 2 - 80Mhz, 3 - 160Mhz
                                   *  4-255 reserved
                                   */
             flags:8;             /** Refer the enum Enhanced stats flags (EN_STATS_ enum) */

    A_UINT32 success_bytes;       /** Total byte count sucessful */

    A_UINT32 ppdu_duration;       /** Tx ppdu transmit time in us */

    A_UINT32 ppdu_ack_timestamp;  /** Timestamp(us) when the ack was received
                                   *  Reference timer for this time stamp
                                   *  is the system timer used by HW SCHD. It is
                                   *  intended to be used only for statistical
                                   *  activities.
                                   */

    A_UINT32 ppdu_bmap_enqueued_lo; /** bitmap of enqueued MPDUs (LSBs) */
    A_UINT32 ppdu_bmap_enqueued_hi; /** bitmap of enqueued MPDUs (MSBs) */

    A_UINT32 ppdu_bmap_tried_lo;    /** bitmap of MPDUs tried OTA (LSBs) */
    A_UINT32 ppdu_bmap_tried_hi;    /** bitmap of MPDUs tried OTA (MSBs) */

    A_UINT32 ppdu_bmap_failed_lo;   /** bitmap of unacked MPDUs (LSBs) */
    A_UINT32 ppdu_bmap_failed_hi;   /** bitmap of unacked MPDUs (MSBs) */

    A_UINT32 rsvd[5];

} POSTPACK ppdu_common_stats_v3;


typedef PREPACK struct {
    A_UINT32 is_training:8,         /* training packets indications */
             rsvd1:24;

    A_UINT32 tx_antenna;            /* antenna in which packet is transmitted */

    /* computed from smart antenna tx feedback info */
    A_UINT32 sa_pkt_stats;
    A_UINT32 sa_max_rates;
    A_UINT32 sa_goodput;

    //A_UINT8  num_comfeedbacks; /* number of combined feedbacks */
    //A_UINT32 combined_fb[2] ;  /*combined feedback */
}POSTPACK ppdu_sant_stats;

enum htt_t2h_en_stats_type {
    /* keep this alwyas first */
    HTT_T2H_EN_STATS_TYPE_START     = 0,

    /** ppdu_common_stats is the payload */
    HTT_T2H_EN_STATS_TYPE_COMMON    = 1,
    /** ppdu_sant_stats is the payload */
    HTT_T2H_EN_STATS_TYPE_SANT      = 2,
    /** ppdu_common_stats_v2 is the payload */
    HTT_T2H_EN_STATS_TYPE_COMMON_V2 = 3,
    /** ppdu_common_stats_v3 is the payload */
    HTT_T2H_EN_STATS_TYPE_COMMON_V3 = 4,

    /* Keep this last */
    HTT_T2H_EN_STATS_TYPE_END       = 0x1f,
};

enum htt_t2h_en_stats_status {
    /* Keep this first always */
    HTT_T2H_EN_STATS_STATUS_PARTIAL     = 0,
    HTT_T2H_EN_STATS_STATUS_PRESENT     = 1,
    HTT_T2H_EN_STATS_STATUS_ERROR       = 2,
    HTT_T2H_EN_STATS_STATUS_INVALID     = 3,


    /* keep this always last */
    HTT_T2H_EN_STATS_STATUS_SERIES_DONE         = 7,
};

#define EN_PEER_INVALID 0xFFF
#define SUCCESS_IDX_INVALID 255

/**
  * @brief target -> host enhanced stats message
  *
  * @details
  * The following field definitions describe the format of the enhanced stats
  * message sent from the target to the host.
  * The message consists of a 4-octet header,followed by a variable number
  * of 32-bit character values.
  *
  * |31          24|23          16|15           8|7            0|
  * |-----------------------------------------------------------|
  * |              |              |              |   msg type   |
  * |-----------------------------------------------------------|
  * |                        payload                            |
  * |-----------------------------------------------------------|
  *   - MSG_TYPE
  *     Bits 7:0
  *     Purpose: identifies this as a enhanced stats message
  *     Value: HTT_T2H_MSG_TYPE_EN_STATS
  */


PREPACK struct htt_en_stats_msg {
     A_UINT32    header;
     A_UINT32   payload[1/* or more */];
} POSTPACK;

#define HTT_T2H_EN_STATS_MAX_VER 3
#define EN_STATS_HTT_HTC_HDR_SIZE HTT_HTC_HDR_SIZE + sizeof(((struct htt_en_stats_msg *)0)->header)

#define HTT_T2H_EN_STATS_CONF_HDR_SIZE 4
#define HTT_T2H_EN_STATS_CONF_TLV_HDR_SIZE 4

#define HTT_T2H_EN_STATS_CONF_TLV_TYPE_M     0x0000001f
#define HTT_T2H_EN_STATS_CONF_TLV_TYPE_S     0
#define HTT_T2H_EN_STATS_CONF_TLV_STATUS_M   0x000000e0
#define HTT_T2H_EN_STATS_CONF_TLV_STATUS_S   5
#define HTT_T2H_EN_STATS_CONF_TLV_LENGTH_M   0xffff0000
#define HTT_T2H_EN_STATS_CONF_TLV_LENGTH_S   16


#define HTT_T2H_EN_STATS_CONF_TLV_TYPE_SET(word, value)             \
    do {                                                         \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_CONF_TLV_TYPE, value);   \
        (word) |= (value)  << HTT_T2H_EN_STATS_CONF_TLV_TYPE_S;     \
    } while (0)
#define HTT_T2H_EN_STATS_CONF_TLV_TYPE_GET(word) \
    (((word) & HTT_T2H_EN_STATS_CONF_TLV_TYPE_M) >> \
    HTT_T2H_EN_STATS_CONF_TLV_TYPE_S)

#define HTT_T2H_EN_STATS_CONF_TLV_STATUS_SET(word, value)             \
    do {                                                         \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_CONF_TLV_STATUS, value);   \
        (word) |= (value)  << HTT_T2H_EN_STATS_CONF_TLV_STATUS_S;     \
    } while (0)
#define HTT_T2H_EN_STATS_CONF_TLV_STATUS_GET(word) \
    (((word) & HTT_T2H_EN_STATS_CONF_TLV_STATUS_M) >> \
    HTT_T2H_EN_STATS_CONF_TLV_STATUS_S)

#define HTT_T2H_EN_STATS_CONF_TLV_LENGTH_SET(word, value)             \
    do {                                                         \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_CONF_TLV_LENGTH, value);   \
        (word) |= (value)  << HTT_T2H_EN_STATS_CONF_TLV_LENGTH_S;     \
    } while (0)
#define HTT_T2H_EN_STATS_CONF_TLV_LENGTH_GET(word) \
    (((word) & HTT_T2H_EN_STATS_CONF_TLV_LENGTH_M) >> \
    HTT_T2H_EN_STATS_CONF_TLV_LENGTH_S)

#define HTT_T2H_EN_STATS_PEER_ID_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_PEER_ID, value); \
        ((A_UINT32 *)(ppdu_stats))[0] |= (value)  << HTT_T2H_EN_STATS_PEER_ID_S; \
    } while (0)
#define HTT_T2H_EN_STATS_PEER_ID_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[0] & HTT_T2H_EN_STATS_PEER_ID_M) >> \
    HTT_T2H_EN_STATS_PEER_ID_S)

#define HTT_T2H_EN_STATS_ATF_TOKENS_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_ATF_TOKENS, value); \
        ((A_UINT32 *)(ppdu_stats))[0] |= (value)  << HTT_T2H_EN_STATS_ATF_TOKENS_S; \
    } while (0)
#define HTT_T2H_EN_STATS_ATF_TOKENS_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[0] & HTT_T2H_EN_STATS_ATF_TOKENS_M) >> \
    HTT_T2H_EN_STATS_ATF_TOKENS_S)

#define HTT_T2H_EN_STATS_USER_POS_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_USER_POS, value); \
        ((A_UINT32 *)(ppdu_stats))[0] |= (value)  << HTT_T2H_EN_STATS_USER_POS_S; \
    } while (0)
#define HTT_T2H_EN_STATS_USER_POS_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[0] & HTT_T2H_EN_STATS_USER_POS_M) >> \
    HTT_T2H_EN_STATS_USER_POS_S)

#define HTT_T2H_EN_STATS_PKT_TYPE_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_PKT_TYPE, value); \
        ((A_UINT32 *)(ppdu_stats))[1] |= (value)  << HTT_T2H_EN_STATS_PKT_TYPE_S; \
    } while (0)
#define HTT_T2H_EN_STATS_PKT_TYPE_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[1] & HTT_T2H_EN_STATS_PKT_TYPE_M) >> \
    HTT_T2H_EN_STATS_PKT_TYPE_S)

#define HTT_T2H_EN_STATS_TID_NUM_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_TID_NUM, value); \
        ((A_UINT32 *)(ppdu_stats))[1] |= (value)  << HTT_T2H_EN_STATS_TID_NUM_S; \
    } while (0)
#define HTT_T2H_EN_STATS_TID_NUM_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[1] & HTT_T2H_EN_STATS_TID_NUM_M) >> \
    HTT_T2H_EN_STATS_TID_NUM_S)

#define HTT_T2H_EN_STATS_MPDUS_QUEUED_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_MPDUS_QUEUED, value); \
        ((A_UINT32 *)(ppdu_stats))[1] |= (value)  << HTT_T2H_EN_STATS_MPDUS_QUEUED_S; \
    } while (0)
#define HTT_T2H_EN_STATS_MPDUS_QUEUED_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[1] & HTT_T2H_EN_STATS_MPDUS_QUEUED_M) >> \
    HTT_T2H_EN_STATS_MPDUS_QUEUED_S)

#define HTT_T2H_EN_STATS_MPDUS_FAILED_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_MPDUS_FAILED, value); \
        ((A_UINT32 *)(ppdu_stats))[1] |= (value)  << HTT_T2H_EN_STATS_MPDUS_FAILED_S; \
    } while (0)
#define HTT_T2H_EN_STATS_MPDUS_FAILED_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[1] & HTT_T2H_EN_STATS_MPDUS_FAILED_M) >> \
    HTT_T2H_EN_STATS_MPDUS_FAILED_S)

#define HTT_T2H_EN_STATS_VAP_ID_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_VAP_ID, value); \
        ((A_UINT32 *)(ppdu_stats))[1] |= (value)  << HTT_T2H_EN_STATS_VAP_ID_S; \
    } while (0)
#define HTT_T2H_EN_STATS_VAP_ID_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[1] & HTT_T2H_EN_STATS_VAP_ID_M) >> \
    HTT_T2H_EN_STATS_VAP_ID_S)

#define HTT_T2H_EN_STATS_MPDUS_TRIED_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_MPDUS_TRIED, value); \
        ((A_UINT32 *)(ppdu_stats))[2] |= (value)  << HTT_T2H_EN_STATS_MPDUS_TRIED_S; \
    } while (0)
#define HTT_T2H_EN_STATS_MPDUS_TRIED_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[2] & HTT_T2H_EN_STATS_MPDUS_TRIED_M) >> \
    HTT_T2H_EN_STATS_MPDUS_TRIED_S)

#define HTT_T2H_EN_STATS_TX_STATUS_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_TX_STATUS, value); \
        ((A_UINT32 *)(ppdu_stats))[2] |= (value)  << HTT_T2H_EN_STATS_TX_STATUS_S; \
    } while (0)
#define HTT_T2H_EN_STATS_TX_STATUS_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[2] & HTT_T2H_EN_STATS_TX_STATUS_M) >> \
    HTT_T2H_EN_STATS_TX_STATUS_S)

#define HTT_T2H_EN_STATS_STARTING_SEQ_NUM_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_STARTING_SEQ_NUM, value); \
        ((A_UINT32 *)(ppdu_stats))[2] |= (value)  << HTT_T2H_EN_STATS_STARTING_SEQ_NUM_S; \
    } while (0)
#define HTT_T2H_EN_STATS_STARTING_SEQ_NUM_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[2] & HTT_T2H_EN_STATS_STARTING_SEQ_NUM_M) >> \
    HTT_T2H_EN_STATS_STARTING_SEQ_NUM_S)

#define HTT_T2H_EN_STATS_RSSI_SEC_80_SET(ppdu_stats, chain_num, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_RSSI_SEC_80, value); \
        ((A_UINT32 *)(ppdu_stats))[3+(chain_num)] |= (value)  << HTT_T2H_EN_STATS_RSSI_SEC_80_S; \
    } while (0)
#define HTT_T2H_EN_STATS_RSSI_SEC_80_GET(ppdu_stats, chain_num) \
    ((((A_UINT32 *)(ppdu_stats))[3+(chain_num)] & HTT_T2H_EN_STATS_RSSI_SEC_80_M) >> \
    HTT_T2H_EN_STATS_RSSI_SEC_80_S)

#define HTT_T2H_EN_STATS_RSSI_SEC_40_SET(ppdu_stats, chain_num, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_RSSI_SEC_40, value); \
        ((A_UINT32 *)(ppdu_stats))[3+(chain_num)] |= (value)  << HTT_T2H_EN_STATS_RSSI_SEC_40_S; \
    } while (0)
#define HTT_T2H_EN_STATS_RSSI_SEC_40_GET(ppdu_stats, chain_num) \
    ((((A_UINT32 *)(ppdu_stats))[3+(chain_num)] & HTT_T2H_EN_STATS_RSSI_SEC_40_M) >> \
    HTT_T2H_EN_STATS_RSSI_SEC_40_S)

#define HTT_T2H_EN_STATS_RSSI_SEC_20_SET(ppdu_stats, chain_num, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_RSSI_SEC_20, value); \
        ((A_UINT32 *)(ppdu_stats))[3+(chain_num)] |= (value)  << HTT_T2H_EN_STATS_RSSI_SEC_20_S; \
    } while (0)
#define HTT_T2H_EN_STATS_RSSI_SEC_20_GET(ppdu_stats, chain_num) \
    ((((A_UINT32 *)(ppdu_stats))[3+(chain_num)] & HTT_T2H_EN_STATS_RSSI_SEC_20_M) >> \
    HTT_T2H_EN_STATS_RSSI_SEC_20_S)

#define HTT_T2H_EN_STATS_RSSI_PRI_20_SET(ppdu_stats, chain_num, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_RSSI_PRI_20, value); \
        ((A_UINT32 *)(ppdu_stats))[3+(chain_num)] |= (value)  << HTT_T2H_EN_STATS_RSSI_PRI_20_S; \
    } while (0)
#define HTT_T2H_EN_STATS_RSSI_PRI_20_GET(ppdu_stats, chain_num) \
    ((((A_UINT32 *)(ppdu_stats))[3+(chain_num)] & HTT_T2H_EN_STATS_RSSI_PRI_20_M) >> \
    HTT_T2H_EN_STATS_RSSI_PRI_20_S)

#define HTT_T2H_EN_STATS_RATE_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_RATE, value); \
        ((A_UINT32 *)(ppdu_stats))[7] |= (value)  << HTT_T2H_EN_STATS_RATE_S; \
    } while (0)
#define HTT_T2H_EN_STATS_RATE_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[7] & HTT_T2H_EN_STATS_RATE_M) >> \
    HTT_T2H_EN_STATS_RATE_S)

#define HTT_T2H_EN_STATS_LONG_RETRIES_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_LONG_RETRIES, value); \
        ((A_UINT32 *)(ppdu_stats))[8] |= (value)  << HTT_T2H_EN_STATS_LONG_RETRIES_S; \
    } while (0)
#define HTT_T2H_EN_STATS_LONG_RETRIES_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[8] & HTT_T2H_EN_STATS_LONG_RETRIES_M) >> \
    HTT_T2H_EN_STATS_LONG_RETRIES_S)

#define HTT_T2H_EN_STATS_SHORT_RETRIES_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_SHORT_RETRIES, value); \
        ((A_UINT32 *)(ppdu_stats))[8] |= (value)  << HTT_T2H_EN_STATS_SHORT_RETRIES_S; \
    } while (0)
#define HTT_T2H_EN_STATS_SHORT_RETRIES_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[8] & HTT_T2H_EN_STATS_SHORT_RETRIES_M) >> \
    HTT_T2H_EN_STATS_SHORT_RETRIES_S)

#define HTT_T2H_EN_STATS_IS_AGGREGATE_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_IS_AGGREGATE, value); \
        ((A_UINT32 *)(ppdu_stats))[8] |= (value)  << HTT_T2H_EN_STATS_IS_AGGREGATE_S; \
    } while (0)
#define HTT_T2H_EN_STATS_IS_AGGREGATE_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[8] & HTT_T2H_EN_STATS_IS_AGGREGATE_M) >> \
    HTT_T2H_EN_STATS_IS_AGGREGATE_S)

#define HTT_T2H_EN_STATS_IS_MCAST_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_IS_MCAST, value); \
        ((A_UINT32 *)(ppdu_stats))[8] |= (value)  << HTT_T2H_EN_STATS_IS_MCAST_S; \
    } while (0)
#define HTT_T2H_EN_STATS_IS_MCAST_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[8] & HTT_T2H_EN_STATS_IS_MCAST_M) >> \
    HTT_T2H_EN_STATS_IS_MCAST_S)

#define HTT_T2H_EN_STATS_START_MSDU_ID_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_START_MSDU_ID, value); \
        ((A_UINT32 *)(ppdu_stats))[8] |= (value)  << HTT_T2H_EN_STATS_START_MSDU_ID_S; \
    } while (0)
#define HTT_T2H_EN_STATS_START_MSDU_ID_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[8] & HTT_T2H_EN_STATS_START_MSDU_ID_M) >> \
    HTT_T2H_EN_STATS_START_MSDU_ID_S)

#define HTT_T2H_EN_STATS_MSDU_SUCCESS_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_MSDU_SUCCESS, value); \
        ((A_UINT32 *)(ppdu_stats))[9] |= (value)  << HTT_T2H_EN_STATS_MSDU_SUCCESS_S; \
    } while (0)
#define HTT_T2H_EN_STATS_MSDU_SUCCESS_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[9] & HTT_T2H_EN_STATS_MSDU_SUCCESS_M) >> \
    HTT_T2H_EN_STATS_MSDU_SUCCESS_S)

#define HTT_T2H_EN_STATS_BW_IDX_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_BW_IDX, value); \
        ((A_UINT32 *)(ppdu_stats))[9] |= (value)  << HTT_T2H_EN_STATS_BW_IDX_S; \
    } while (0)
#define HTT_T2H_EN_STATS_BW_IDX_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[9] & HTT_T2H_EN_STATS_BW_IDX_M) >> \
    HTT_T2H_EN_STATS_BW_IDX_S)

#define HTT_T2H_EN_STATS_FLAGS_SET(ppdu_stats, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_EN_STATS_FLAGS, value); \
        ((A_UINT32 *)(ppdu_stats))[9] |= (value)  << HTT_T2H_EN_STATS_FLAGS_S; \
    } while (0)
#define HTT_T2H_EN_STATS_FLAGS_GET(ppdu_stats) \
    ((((A_UINT32 *)(ppdu_stats))[9] & HTT_T2H_EN_STATS_FLAGS_M) >> \
    HTT_T2H_EN_STATS_FLAGS_S)

/**
 * @brief target -> host enhanced statistics for every ppdu completion
 *
 * @details
 * The following field definitions describe the format of the HTT target
 * to host enhanced stats message.
 * The message contains an htt header of 4 bytes followed by a series of
 * tag-length-value stats information elements. The htt header is a 32
 * bit value with first 8 bits indicating the type of htt message from
 * target to host.
 * The tag-length header for each stats info element also includes a
 * status field, to indicate whether the stat type which is sent
 * fully filled, partially filled, unable to be fill, or invalid
 * (if the stat type is disabled in the target).
 * A special value of all 1's in this status field is used to indicate
 * the end of the series of stats info elements.
 *
 * |31                         16|15           8|7   5|4       0|
 * |------------------------------------------------------------|
 * |                  reserved                  | htt msg type  |
 * |------------------------------------------------------------|
 * |      stats entry length     |   reserved   |  S  |stat type|
 * |------------------------------------------------------------|
 * |                                                            |
 * |                  type-specific stats info                  |
 * |                                                            |
 * |------------------------------------------------------------|
 * |      stats entry length     |   reserved   |  S  |stat type|
 * |------------------------------------------------------------|
 * |                                                            |
 * |                  type-specific stats info                  |
 * |                                                            |
 * |------------------------------------------------------------|
 * |              n/a            |   reserved   | 111 |   n/a   |
 * |------------------------------------------------------------|
 * |                  reserved                  | series done   |
 * |------------------------------------------------------------|
 * Header fields:
 *  - MSG_TYPE
 *    Bits 7:0
 *    Purpose: identifies this is enhanced statistics message
 *    Value:
 *
 * Stats Information Element tag-length header fields:
 *  - STAT_TYPE
 *    Bits 4:0
 *    Purpose: identifies the type of statistics info held in the
 *        following information element
 *    Value: htt_en_stats_type
 *  - STATUS
 *    Bits 7:5
 *    Purpose: indicate whether the stats are present
 *    Value: htt_en_stats_status, including a special value (0x7) to mark
 *        the completion of the stats entry series
 *  - LENGTH
 *    Bits 31:16
 *    Purpose: indicate the stats information size
 *    Value: This field specifies the number of bytes of stats information
 *       that follows the element tag-length header.
 *       It is expected but not required that this length is a multiple of
 *       4 bytes.  Even if the length is not an integer multiple of 4, the
 *       subsequent stats entry header will begin on a 4-byte aligned
 *       boundary.
 */

/* Enhanced stats flags */

enum {
    /* set if TID is ATF enabled and has used it's token for Tx */
    EN_STATS_ATF_ENABLE_TID_S = 0,

    /** Tx status flags */
    EN_STATS_TX_ERR_S,      /* set for any Tx error, to invalidate
                             * msdu_success/success_bytes/start_msdu_id */
    EN_STATS_TX_MU_S,       /** If set Tx is MU2/3 transmission */
    EN_STATS_ATF_FREE_LOADER_S,

    /** Beacon error conditions */
    EN_STATS_BCN_HW_PAUSE_S,
    EN_STATS_BCN_HW_FILT_S,
    EN_STATS_BCN_SW_ABT_S = 6,

    EN_STATS_FLAG_MAX_S = 8
};

/** Enahnced stats pkt_type */
enum {
    EN_STATS_PKT_TYPE_DATA  = 0,
    EN_STATS_PKT_TYPE_MGMT  = 1,
    EN_STATS_PKT_TYPE_BCN   = 2,

    EN_STATS_PKT_TYPE_MAX   = 7,
};

enum {
    EN_STATS_TX_STATUS_OK       = 0x0, /* Tx ok - no error */
    EN_STATS_TX_STATUS_XRETRY   = 0x1, /* Excessive retries */
    EN_STATS_TX_STATUS_FILT     = 0x2, /* Blocked by Tx filtering */

    /** All other values are considered as unidentified Tx error */
};

#endif


/**
 * @brief host -> target FRAG DESCRIPTOR/MSDU_EXT DESC bank
 *
 * @details
 * The following field definitions describe the format of the HTT host
 * to target frag_desc/msdu_ext bank configuration message.
 * The message contains the based address and the min and max id of the
 * MSDU_EXT/FRAG_DESC that will be used by the HTT to map MSDU DESC and
 * MSDU_EXT/FRAG_DESC.
 * HTT will use id in HTT descriptor instead sending the frag_desc_ptr.
 * In peregrine the firmware will use fragment_desc_ptr but in WIFI2.0
 * the hardware does the mapping/translation.
 *
 * Total banks that can be configured is configured to 16.
 *
 * This should be called before any TX has been initiated by the HTT
 *
 * |31                         16|15    12| 11| 10|9  8|7      0|
 * |------------------------------------------------------------|
 * | DESC_SIZE    |  NUM_BANKS   |RES|qdep|val|SWP|pdev|msgtype |
 * |------------------------------------------------------------|
 * |                     BANK0_BASE_ADDRESS                     |
 * |------------------------------------------------------------|
 * |                            ...                             |
 * |------------------------------------------------------------|
 * |                    BANK15_BASE_ADDRESS                     |
 * |------------------------------------------------------------|
 * |       BANK0_MAX_ID          |       BANK0_MIN_ID           |
 * |------------------------------------------------------------|
 * |                            ...                             |
 * |------------------------------------------------------------|
 * |       BANK15_MAX_ID         |       BANK15_MIN_ID          |
 * |------------------------------------------------------------|
 * |                    HOST_Q_STATE_BUF_BASE_ADRR              |
 * |------------------------------------------------------------|
 * |         MAX_TID             |       MAX_PEER_ID            |
 * |------------------------------------------------------------|
 * |         RSVD                |    cnt_multiple   |  SIZE    |
 * |------------------------------------------------------------|
 * Header fields:
 *  - MSG_TYPE
 *    Bits 7:0
 *    Value: 0x6
 *  - valid
 *    Bit 11
 *    Purpose: Provide a mechanism to specify if the host_q_state_buf_base_addr,
 *        max_peer_id, max_tid, size, cnt_multiple are valid fields.
 *        valid = 1 --> host_q_state_buf_base_addr, max_peer_id, max_tid,
 *            size, cnt_multiple
 *    fields are present and valid.
 *        valid = 0 --> all of the above fields are either not present at all
 *            or are present but invalid.
 *  - qdep
 *    Bit 12
 *    Purpose: Mechanism to specify if the host txq depth is in frames or bytes.
 *  - BANKx_BASE_ADDRESS
 *    Bits 31:0
 *    Purpose: Provide a mechanism to specify the base address of the MSDU_EXT
 *         bank physical/bus address.
 *  - BANKx_MIN_ID
 *    Bits 15:0
 *    Purpose: Provide a mechanism to specify the min index that needs to
 *          mapped.
 *  - BANKx_MAX_ID
 *    Bits 31:16
 *    Purpose: Provide a mechanism to specify the max index that needs to
 *          mapped.
 *  - HOST_Q_STATE_BUF_BASE_ADDR
 *    Bits 31:0
 *    Purpose : Provide a mechanism to specify the bus address of the memory
 *           location where the host q state is stored.
 *  - MAX_PEER_ID
 *    Bits 15:0
 *    Purpose: Provide a mechanism to specify the max number of peer_ids for which
 *           the host allocates memory to store its q state information.
 *  - MAX_TID
 *    Bits 31:16
 *    Purpose: Provide a mechanism to specify the max number of tids for which
 *        the host allocates memory to store its q state information.
 *  - SIZE:
 *    Bits 7:0
 *    Purpose: Provide a mechanism to specify the number of bytes that the host
 *        allocates per peer/per tid to store the q state information.
 *  - cnt_multiple
 *    Bits 15:8
 *    Purpose: Provide a mechanism to specify the multiple in which the host
 *        counts the qdepth for a peer/tid. It could be multiples of 1,4,8 etc.
 */

/** @todo Compress the fields to fit MAX HTT Message size, until then configure to a
 *         safe value.
 *  @note MAX supported banks is 16.
 */
#define HTT_TX_MSDU_EXT_BANK_MAX 4

#define HTT_H2T_FRAG_DESC_BANK_PDEVID_M       0x300
#define HTT_H2T_FRAG_DESC_BANK_PDEVID_S       8

#define HTT_H2T_FRAG_DESC_BANK_SWAP_M         0x400
#define HTT_H2T_FRAG_DESC_BANK_SWAP_S         10

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_VALID_M 0x800
#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_VALID_S 11

#define HTT_H2T_FRAG_DESC_HOST_Q_DEPTH_TYPE_M  0x1000
#define HTT_H2T_FRAG_DESC_HOST_Q_DEPTH_TYPE_S  12

#define HTT_H2T_FRAG_DESC_BANK_NUM_BANKS_M    0xff0000
#define HTT_H2T_FRAG_DESC_BANK_NUM_BANKS_S    16

#define HTT_H2T_FRAG_DESC_BANK_DESC_SIZE_M    0xff000000
#define HTT_H2T_FRAG_DESC_BANK_DESC_SIZE_S    24

#define HTT_H2T_FRAG_DESC_BANK_MIN_IDX_M      0xffff
#define HTT_H2T_FRAG_DESC_BANK_MIN_IDX_S      0

#define HTT_H2T_FRAG_DESC_BANK_MAX_IDX_M      0xffff0000
#define HTT_H2T_FRAG_DESC_BANK_MAX_IDX_S      16

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_PEER_ID_M 0xffff
#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_PEER_ID_S 0

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_TID_M 0xffff0000
#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_TID_S 16

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_SIZE_BYTES_M 0xff
#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_SIZE_BYTES_S 0

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_CNT_MULTIPLE_M 0xff00
#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_CNT_MULTIPLE_S 8

#define HTT_H2T_FRAG_DESC_BANK_PDEVID_SET(word, value)           \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_BANK_PDEVID, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_BANK_PDEVID_S);  \
    } while (0)
#define HTT_H2T_FRAG_DESC_BANK_PDEVID_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_BANK_PDEVID_M) >> HTT_H2T_FRAG_DESC_BANK_PDEVID_S)

#define HTT_H2T_FRAG_DESC_BANK_SWAP_SET(word, value)           \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_BANK_SWAP, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_BANK_SWAP_S);  \
    } while (0)
#define HTT_H2T_FRAG_DESC_BANK_SWAP_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_BANK_SWAP_M) >> HTT_H2T_FRAG_DESC_BANK_SWAP_S)

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_VALID_SET(word, value)     \
    do {  \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_HOST_Q_STATE_VALID, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_HOST_Q_STATE_VALID_S); \
    } while (0)

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_VALID_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_HOST_Q_STATE_VALID_M) >> HTT_H2T_FRAG_DESC_HOST_Q_STATE_VALID_S)

#define HTT_H2T_FRAG_DESC_HOST_Q_DEPTH_TYPE_SET(word, value) \
    do {  \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_HOST_Q_DEPTH_TYPE, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_HOST_Q_DEPTH_TYPE_S); \
    } while (0)

#define HTT_H2T_FRAG_DESC_HOST_Q_DEPTH_TYPE_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_HOST_Q_DEPTH_TYPE_M) >> HTT_H2T_FRAG_DESC_HOST_Q_DEPTH_TYPE_S)

#define HTT_H2T_FRAG_DESC_BANK_NUM_BANKS_SET(word, value)           \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_BANK_NUM_BANKS, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_BANK_NUM_BANKS_S);  \
    } while (0)
#define HTT_H2T_FRAG_DESC_BANK_NUM_BANKS_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_BANK_NUM_BANKS_M) >> HTT_H2T_FRAG_DESC_BANK_NUM_BANKS_S)

#define HTT_H2T_FRAG_DESC_BANK_DESC_SIZE_SET(word, value)           \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_BANK_DESC_SIZE, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_BANK_DESC_SIZE_S);  \
    } while (0)
#define HTT_H2T_FRAG_DESC_BANK_DESC_SIZE_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_BANK_DESC_SIZE_M) >> HTT_H2T_FRAG_DESC_BANK_DESC_SIZE_S)

#define HTT_H2T_FRAG_DESC_BANK_MIN_IDX_SET(word, value)           \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_BANK_MIN_IDX, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_BANK_MIN_IDX_S);  \
    } while (0)
#define HTT_H2T_FRAG_DESC_BANK_MIN_IDX_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_BANK_MIN_IDX_M) >> HTT_H2T_FRAG_DESC_BANK_MIN_IDX_S)

#define HTT_H2T_FRAG_DESC_BANK_MAX_IDX_SET(word, value)           \
    do {                                               \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_BANK_MAX_IDX, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_BANK_MAX_IDX_S);  \
    } while (0)

#define HTT_H2T_FRAG_DESC_BANK_MAX_IDX_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_BANK_MAX_IDX_M) >> HTT_H2T_FRAG_DESC_BANK_MAX_IDX_S)

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_PEER_ID_SET(word, value) \
    do {  \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_PEER_ID, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_PEER_ID_S); \
    } while (0)

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_PEER_ID_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_PEER_ID_M) >> HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_PEER_ID_S)

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_TID_SET(word, value) \
    do {  \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_TID, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_TID_S); \
    } while (0)

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_TID_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_TID_M) >> HTT_H2T_FRAG_DESC_HOST_Q_STATE_MAX_TID_S)

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_SIZE_BYTES_SET(word, value) \
    do {  \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_SIZE_BYTES, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_SIZE_BYTES_S); \
    } while (0)

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_SIZE_BYTES_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_SIZE_BYTES_M) >> HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_SIZE_BYTES_S)

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_CNT_MULTIPLE_SET(word, value) \
    do {  \
        HTT_CHECK_SET_VAL(HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_CNT_MULTIPLE, value); \
        (word) |= ((value) << HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_CNT_MULTIPLE_S); \
    } while (0)

#define HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_CNT_MULTIPLE_GET(word) \
    (((word) & HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_CNT_MULTIPLE_M) >> HTT_H2T_FRAG_DESC_HOST_Q_STATE_QDEPTH_CNT_MULTIPLE_S)

enum {
    /* specify the host txq depth in bytes */
    host_q_state_txq_depth_bytes = 0,

    /* specify the host txq depth in frames */
    host_q_state_txq_depth_frames = 1,
};

PREPACK struct htt_tx_frag_desc_bank_cfg_t {
      /** word 0
       * msg_type:      8,
       * pdev_id:      2,
       * swap:         1,
       * host_q_state_info_valid: 1,
       * host_q_state_txq_depth_type: 1,
       * reserved0:    3,
       * num_banks:    8,
       * desc_size:    8;
       */
    A_UINT32 word0;
    A_UINT32 bank_base_address[HTT_TX_MSDU_EXT_BANK_MAX];
    A_UINT32 bank_info[HTT_TX_MSDU_EXT_BANK_MAX];
    A_UINT32 host_q_state_buf_base_addr;
      /** word10
       * max_peer_id:16,
       * max_tid :16;
       */
    A_UINT32 word10;
      /** word11
       * host_q_state_qdepth_size_bytes: 8,
       * host_q_state_qdepth_cnt_multiple : 8,
       * reserved: 16;
       */
    A_UINT32 word11;
} POSTPACK;

/**
 * @brief host -> target  channel change message
 *
 * @details
 * the meesage is generated by FW every time FW changes channel. This will be used by host mainly
 * to associate  RX frames to correct channel they were received on.
 * The following field definitions describe the format of the HTT target
 * to host channel change message.
 * |31                         16|15           8|7   5|4       0|
 * |------------------------------------------------------------|
 * |                  reserved                  |    MSG_TYPE   |
 * |------------------------------------------------------------|
 * |                        CHAN_MHZ                            |
 * |------------------------------------------------------------|
 * |                        BAND_CENTER_FREQ1                   |
 * |------------------------------------------------------------|
 * |                        BAND_CENTER_FREQ2                   |
 * |------------------------------------------------------------|
 * |                        CHAN_PHY_MODE                       |
 * |------------------------------------------------------------|
 * Header fields:
 *  - MSG_TYPE
 *    Bits 7:0
 *    Value: 0xf
 *  - CHAN_MHZ
 *    Bits 31:0
 *    Purpose: frequency of the primary 20mhz channel.
 *  - BAND_CENTER_FREQ1
 *    Bits 31:0
 *    Purpose: centre frequency of the full channel.
 *  - BAND_CENTER_FREQ2
 *    Bits 31:0
 *    Purpose: centre frequency2  of the channel.  is only valid for 11acvht 80plus80.
 *  - CHAN_PHY_MODE
 *    Bits 31:0
 *    Purpose: phy mode of the channel.
*/

PREPACK struct htt_chan_change_msg {
     A_UINT32 chan_mhz;   /* frequency in mhz */

     A_UINT32 band_center_freq1; /* Center frequency 1 in MHz*/

     A_UINT32 band_center_freq2; /* Center frequency 2 in MHz - valid only for 11acvht 80plus80 mode*/

     A_UINT32 chan_mode;  /* WLAN_PHY_MODE of the channel defined in wlan_defs.h */
} POSTPACK;
#define HTT_TX_CREDIT_MSG_BYTES 4
#define HTT_TX_CREDIT_SIGN_BIT_M       0x00000100
#define HTT_TX_CREDIT_SIGN_BIT_S       8
#define HTT_TX_CREDIT_DELTA_ABS_M      0xffff0000
#define HTT_TX_CREDIT_DELTA_ABS_S      16


#define HTT_TX_CREDIT_SIGN_BIT_SET(word, value)                              \
    do {                                                                     \
        HTT_CHECK_SET_VAL(HTT_TX_CREDIT_SIGN_BIT, value);                    \
        (word) |= (value)  << HTT_TX_CREDIT_SIGN_BIT_S;                      \
    } while (0)

#define HTT_TX_CREDIT_SIGN_BIT_GET(word) \
    (((word) & HTT_TX_CREDIT_SIGN_BIT_M) >> HTT_TX_CREDIT_SIGN_BIT_S)

#define HTT_TX_CREDIT_DELTA_ABS_SET(word, value)                              \
    do {                                                                      \
        HTT_CHECK_SET_VAL(HTT_TX_CREDIT_DELTA_ABS, value);                    \
        (word) |= (value)  << HTT_TX_CREDIT_DELTA_ABS_S;                      \
    } while (0)

#define HTT_TX_CREDIT_DELTA_ABS_GET(word) \
    (((word) & HTT_TX_CREDIT_DELTA_ABS_M) >> HTT_TX_CREDIT_DELTA_ABS_S)


#define HTT_TX_CREDIT_MSG_BYTES 4
#define HTT_TX_CREDIT_SIGN_BIT_POSITIVE  0x0
#define HTT_TX_CREDIT_SIGN_BIT_NEGATIVE  0x1

#define HTT_RX_CHAN_CHANGE_BYTES 20
#define HTC_HTT_TRANSMIT_HDRSIZE 24

/**
 * @brief target -> host TX Fetch Indication
 *
 * @details
 * The following field definitions describe the format of the HTT target
 * to host Tx Fetch Indication message.
 * The message is a variable length message prefixed with
 * sequence number to be echoed by the host at its queue buffer state,
 * a dialog token that is opaque to the host that needs to be echoed back
 * in the HTT_H2T_MSG_TYPE_TX_FETCH_RESP message by the host,
 * the number of resp_id records & fetch records that are contained in
 * the message, followed by the records themselves.
 * Each resp_id record carries a resp_id from a HTT_H2T_MSG_TYPE_TX_FETCH_RESP
 * Each fetch record is a (peerid, tidno, max_pkts, max_bytes) quadruple.
 *
 * |31                         16|15    12|11  8|7   5|4       0|
 * |------------------------------------------------------------|
 * |    FETCH_SEQ_NUMBER         |    RSVD      |    msg type   |
 * |------------------------------------------------------------|
 * |                          DIALOG_TOKEN                      |
 * |------------------------------------------------------------|
 * |     NUM_FETCH_RECORDS       |     NUM_RESP_ID_RECORDS      |
 * |------------------------------------------------------------|
 * |        MAX_PKTS             |  TIDNO |       PEERID        |
 * |------------------------------------------------------------|
 * |                          MAX_BYTES                         |
 * |------------------------------------------------------------|
 * |                            ...                             |
 * |------------------------------------------------------------|
 * |        MAX_PKTS             |  TIDNO |       PEERID        |
 * |------------------------------------------------------------|
 * |                          MAX_BYTES                         |
 * |------------------------------------------------------------|
 * |                           RESP_ID                          |
 * |------------------------------------------------------------|
 * |                            ...                             |
 * |------------------------------------------------------------|
 * |                           RESP_ID                          |
 * |------------------------------------------------------------|
 * Header fields:
 *  Word 0
 *  - MSG_TYPE (HTT_T2H_MSG_TYPE_TX_FETCH_IND)
 *    Bits 7:0
 *    Value: 0x16
 *  - FETCH_SEQ_NUMBER
 *    Bits 31:16
 *    Purpose: Provide a mechanism to specify a running seq num that the
 *          host can echo at its queue state buffer. This seq num is also
 *          echoed by the host in the HTT_H2T_MSG_TYPE_TX_FETCH_RESP message.
 *  Word 1
 *  - DIALOG_TOKEN
 *    Bits 31:0
 *    Purpose: Provides a mechanism for the target to encode some of the
 *    scheduling related parameters & timestamps that are opaque to the
 *    host & can be used from the HTT_H2T_MSG_TYPE_TX_FETCH_RESP message
 *    to measure latencies.
 *  Word 2
 *  - NUM_RESP_ID_RECORDS
 *    Bits 0:15
 *    Purpose: Specify number of resp_id records that this message contains.
 *  - NUM_FETCH_RECORDS
 *    Bits 31:16
 *    Purpose: Provide a mechanism to specify the number of records that
 *         this message contains.
 *  Word 3 onwards
 *  - PEERID
 *    Bits 11:0
 *    Purpose: Provide a mechanism to specify the peerid for which to
 *          fetch packets.
 *  - TIDNO
 *    Bits 15:12
 *    Purpose : Provide a mechanism to specify the tidno for which to
 *           fetch packets.
 *  - MAX_PKTS
 *    Bits 31:16
 *    Purpose: Provide a mechanism to specify the maximum # of MSDUs (in units of 1)
 *           to fetch from the specified tx queue. The host can download any number
 *           <= max number.
 *  - MAX_BYTES
 *    Bits 31:0
 *    Purpose : Provide a mechanism to specify the maximum # of bytes (in units of 1)
 *           to fetch from the specified tx queue. The host can download any number
 *           <= max_bytes
 *  - RESP_ID
 *    Bits 31:0
 *    Purpose : Allows the target to replay a resp_id cookie that it got from the host
 *            in a HTT_H2T_MSG_TYPE_TX_FETCH_RESP
 */

PREPACK struct htt_tx_fetch_respid_record_t {
    A_UINT32 resp_id;
} POSTPACK;

PREPACK struct htt_tx_fetch_ind_record_t {
    /** word 0
     * peerid: 12,
     * tidno: 4,
     * max_pkts: 16;
     */
    A_UINT32 word0;
    /** word 1
     * max_bytes:32;
     */
    A_UINT32 max_bytes;
} POSTPACK;

PREPACK struct htt_tx_fetch_ind_t {
      /** word 0
       * msg_type:     8,
       * reserved0:    8,
       * fetch_seq_num: 16;
       */
    A_UINT32 word0;
      /** word 1
       * dialog token
       */
    A_UINT32 word1;
      /** word 2
       * num_resp_id_records:16,
       * num_fetch_records: 16;
       */
    A_UINT32 word2;

    struct htt_tx_fetch_ind_record_t fetch_ind_record[1];
    /** (num_fetch_records-1)
     * fetch records followed by
     * num_resp_id_records
     */
} POSTPACK;

#define HTT_TX_FETCH_IND_RESP_ID_SZ sizeof(struct htt_tx_fetch_respid_record_t)
#define HTT_TX_FETCH_RECORD_SZ sizeof(struct htt_tx_fetch_ind_record_t)
#define HTT_TX_FETCH_IND_HDR_SZ 12 /* bytes */

#define HTT_T2H_TX_FETCH_IND_SEQ_NUM_M 0xffff0000
#define HTT_T2H_TX_FETCH_IND_SEQ_NUM_S 16

#define HTT_T2H_TX_FETCH_IND_NUM_RESP_ID_RECORDS_M 0xffff
#define HTT_T2H_TX_FETCH_IND_NUM_RESP_ID_RECORDS_S 0

#define HTT_T2H_TX_FETCH_IND_NUM_FETCH_RECORDS_M 0xffff0000
#define HTT_T2H_TX_FETCH_IND_NUM_FETCH_RECORDS_S 16

#define HTT_T2H_TX_FETCH_IND_PEERID_M 0xfff
#define HTT_T2H_TX_FETCH_IND_PEERID_S 0

#define HTT_T2H_TX_FETCH_IND_TIDNO_M 0xf000
#define HTT_T2H_TX_FETCH_IND_TIDNO_S 12

#define HTT_T2H_TX_FETCH_IND_MAX_PKTS_M 0xffff0000
#define HTT_T2H_TX_FETCH_IND_MAX_PKTS_S 16

#define HTT_T2H_TX_FETCH_IND_SEQ_NUM_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_FETCH_IND_SEQ_NUM, value); \
        (word) |= ((value) << HTT_T2H_TX_FETCH_IND_SEQ_NUM_S);  \
    } while (0)

#define HTT_T2H_TX_FETCH_IND_SEQ_NUM_GET(word) \
    (((word) & HTT_T2H_TX_FETCH_IND_SEQ_NUM_M) >> \
    HTT_T2H_TX_FETCH_IND_SEQ_NUM_S)

#define HTT_T2H_TX_FETCH_IND_NUM_RESP_ID_RECORDS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_FETCH_IND_NUM_RESP_ID_RECORDS, value); \
        (word) |= ((value) << HTT_T2H_TX_FETCH_IND_NUM_RESP_ID_RECORDS_S);  \
    } while (0)

#define HTT_T2H_TX_FETCH_IND_NUM_RESP_ID_RECORDS_GET(word) \
    (((word) & HTT_T2H_TX_FETCH_IND_NUM_RESP_ID_RECORDS_M) >> \
    HTT_T2H_TX_FETCH_IND_NUM_RESP_ID_RECORDS_S)

#define HTT_T2H_TX_FETCH_IND_NUM_FETCH_RECORDS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_FETCH_IND_NUM_FETCH_RECORDS, value); \
        (word) |= ((value) << HTT_T2H_TX_FETCH_IND_NUM_FETCH_RECORDS_S);  \
    } while (0)

#define HTT_T2H_TX_FETCH_IND_NUM_FETCH_RECORDS_GET(word) \
    (((word) & HTT_T2H_TX_FETCH_IND_NUM_FETCH_RECORDS_M) >> \
    HTT_T2H_TX_FETCH_IND_NUM_FETCH_RECORDS_S )

#define HTT_T2H_TX_FETCH_IND_PEERID_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_FETCH_IND_PEERID, value); \
        (word) |= ((value) << HTT_T2H_TX_FETCH_IND_PEERID_S);  \
    } while (0)

#define HTT_T2H_TX_FETCH_IND_PEERID_GET(word) \
    (((word) & HTT_T2H_TX_FETCH_IND_PEERID_M) >> HTT_T2H_TX_FETCH_IND_PEERID_S)

#define HTT_T2H_TX_FETCH_IND_TIDNO_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_FETCH_IND_TIDNO, value); \
        (word) |= ((value) << HTT_T2H_TX_FETCH_IND_TIDNO_S);  \
    } while (0)

#define HTT_T2H_TX_FETCH_IND_TIDNO_GET(word) \
    (((word) & HTT_T2H_TX_FETCH_IND_TIDNO_M) >> HTT_T2H_TX_FETCH_IND_TIDNO_S)

#define HTT_T2H_TX_FETCH_IND_MAX_PKTS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_FETCH_IND_MAX_PKTS, value); \
        (word) |= ((value) << HTT_T2H_TX_FETCH_IND_MAX_PKTS_S);  \
    } while (0)

#define HTT_T2H_TX_FETCH_IND_MAX_PKTS_GET(word) \
    (((word) & HTT_T2H_TX_FETCH_IND_MAX_PKTS_M) >> \
    HTT_T2H_TX_FETCH_IND_MAX_PKTS_S)

/**
 * @brief target -> host Fetch Confirmation
 *
 * @details
 * The following field definitions describe the format of the HTT target
 * to host Fetch Confirmation message. This message is used by the target
 * whenever the number of cached fetch resp_ids hit the max number of
 * resp_ids that can be cached at the target. Until then, the fetch
 * resp_ids would be cached and opportunistically piggybacked on the
 * HTT_T2H_MSG_TYPE_TX_FETCH_IND.
 * The message contains the number of resp_id records that are echoed
 * back in this message to the host.
 * The message contains the RESP_IDs replayed from the corresponding
 * HTT_H2T_MSG_TYPE_TX_FETCH_RESP messages that were received earlier &
 * outstanding to be echoed back to the host.
 *
 * Header fields:
 *  - MSG_TYPE (HTT_T2H_MSG_TYPE_TX_FETCH_CONF)
 *    Bits 7:0
 *    Value: 0x17
 *  - NUM_RESP_ID_RECORDS
 *    Bits 31:16
 *    Purpose: Specify number of resp_id records that this message contains.
 *
 * |31                         16|15    12|11  8|7   5|4       0|
 * |------------------------------------------------------------|
 * |    NUM_RESP_ID_RECORDS      |    RSVD      |   msg type    |
 * |------------------------------------------------------------|
 * |                           RESP_ID                          |
 * |------------------------------------------------------------|
 * |                            ...                             |
 * |------------------------------------------------------------|
 * |                           RESP_ID                          |
 * |------------------------------------------------------------|
 */

PREPACK struct htt_tx_fetch_conf_t {
      /** word 0
       * msg_type:     8,
       * reserved0:    8;
       * num_resp_id_records:16;
       */
    A_UINT32 word0;
    struct htt_tx_fetch_respid_record_t fetch_respid_record[1];
} POSTPACK;

#define HTT_TX_FETCH_CONF_HDR_SZ 4 /* bytes */
#define HTT_TX_FETCH_CONF_RESP_ID_SZ sizeof(struct htt_tx_fetch_respid_record_t)

#define HTT_T2H_TX_FETCH_CONF_NUM_RESP_ID_RECORDS_M 0xffff0000
#define HTT_T2H_TX_FETCH_CONF_NUM_RESP_ID_RECORDS_S 16

#define HTT_T2H_TX_FETCH_CONF_NUM_RESP_ID_RECORDS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_FETCH_CONF_NUM_RESP_ID_RECORDS, value); \
        (word) |= ((value) << HTT_T2H_TX_FETCH_CONF_NUM_RESP_ID_RECORDS_S);  \
    } while (0)

#define HTT_T2H_TX_FETCH_CONF_NUM_RESP_ID_RECORDS_GET(word) \
    (((word) & HTT_T2H_TX_FETCH_CONF_NUM_RESP_ID_RECORDS_M) >> \
    HTT_T2H_TX_FETCH_CONF_NUM_RESP_ID_RECORDS_S)


/* @brief target->host mode switch indication
 *
 * @details
 *    Available modes:
 *        1.  Mode 0 (PUSH MODE):
 *            Host pushes frames down to target normally until descriptors
 *            are available beyond which it may start queuing.
 *            The host does no tx classification.  Thus, if the host
 *            does any queuing, it doesn't queue tx frames per peer.
 *        2.  Mode 1 (PUSH-PULL MODE):
 *            Host pushes frames down to target till the global descriptor
 *            threshold (dynamically updated) is reached. Beyond this threshold
 *            the host starts queuing up the frames and presents the summary
 *            to target. Target sends fetch requests to host and pulls in the
 *            frames.
 *
 *    There are two purposes to this message:
 *        1. Mode switch indication for the whole radio (PDEV)
 *        2. Enable/Disable/Update per-peer and per-tid packet threshold to host
 *
 * 1. This message is used to indicate the host to switch between the modes.
 * The mode field specifies the new mode the target is now operating in.
 * The threshold is the number of frames (MSDUs) host would push
 * to firmware in push-pull mode beyond which it starts queuing.
 * The threshold field is valid only for push mode. The enable bit is
 * invalid in this message and the message does not have any per-peer records.
 *
 * 2. Whenever the target decides to reduce the number of fetch
 * indication/response/confirmation transactions, it will use this
 * message to indicate to the host how many packets the host can
 * directly download to the target per peer/tid - without the need
 * for the fetch messages. This is to reduce the total round trip
 * delay for packets when only fewer number of active flows exists.
 *
 * The target can turn this feature ON or OFF through the enable(EN) bit.
 * The message consists of records for each PEERID/TIDNO the maximum number
 * of packets that the host can download without waiting for the fetch
 * indication from the target.
 *
 * |31                      17|16|15    12|11  8|7   5|4       0|
 * |------------------------------------------------------------|
 * |    Num of Records        |EN|    RSVD      |    msg type   |
 * |------------------------------------------------------------|
 * |        RSVD                 |        THRESHOLD      | MODE |
 * |------------------------------------------------------------|
 * |  MAX_PKTS                   | TIDNO  |  PEERID             |
 * |------------------------------------------------------------|
 * |                          ...                               |
 * |------------------------------------------------------------|
 * |  MAX_PKTS                   | TIDNO  |  PEERID             |
 * |------------------------------------------------------------|
 */

/* TEMPORARY ALIAS */
#define htt_tx_low_latency_ind_record_t htt_tx_mode_switch_ind_record_t
PREPACK struct htt_tx_mode_switch_ind_record_t {
    /** word 0
     * peerid: 12,
     * tidno: 4,
     * max_pkts: 16;
     */
    A_UINT32 word0;
} POSTPACK;

/* TEMPORARY ALIAS */
#define htt_tx_low_latency_ind_t htt_tx_mode_switch_ind_t
PREPACK struct htt_tx_mode_switch_ind_t {
      /** word 0
       * msg_type:     8,
       * reserved0:    8,
       * enable bit:   1,
       * number of records: 15,
       */
    A_UINT32 word0;
      /** word 1
       * mode: 2,
       * threshold: 14,
       * reserved: 16,
       */
    A_UINT32 word1;

    struct htt_tx_mode_switch_ind_record_t low_latency_ind_record[1];

} POSTPACK;

#define HTT_TX_MODE_PUSH_NO_CLASSIFY 0
#define HTT_TX_MODE_PUSH_PULL 1

#define HTT_T2H_TX_MODE_SWITCH_IND_ID_SZ sizeof(struct htt_tx_mode_switch_ind_t)
#define HTT_T2H_TX_MODE_SWITCH_IND_RECORD_SZ sizeof(struct htt_tx_mode_switch_ind_record_t)
#define HTT_T2H_TX_MODE_SWITCH_IND_HDR_SZ 8 /* bytes */
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_ID_SZ \
    HTT_T2H_TX_MODE_SWITCH_IND_ID_SZ
#define HTT_T2H_TX_LOW_LATENCY_IND_RECORD_SZ \
    HTT_T2H_TX_MODE_SWITCH_IND_RECORD_SZ
#define HTT_T2H_TX_LOW_LATENCY_IND_HDR_SZ \
    HTT_T2H_TX_MODE_SWITCH_IND_HDR_SZ

#define HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_M 0x10000
#define HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_S 16
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_ENABLE_M \
    HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_M
#define HTT_T2H_TX_LOW_LATENCY_IND_ENABLE_S \
    HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_S

#define HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_M 0xfffe0000
#define HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_S 17
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_NUM_RECORDS_M \
    HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_M
#define HTT_T2H_TX_LOW_LATENCY_IND_NUM_RECORDS_S \
    HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_S

#define HTT_T2H_TX_MODE_SWITCH_IND_MODE_M 0x3
#define HTT_T2H_TX_MODE_SWITCH_IND_MODE_S 0

#define HTT_T2H_TX_MODE_SWITCH_IND_THRESHOLD_M 0xFFFC
#define HTT_T2H_TX_MODE_SWITCH_IND_THRESHOLD_S 2

#define HTT_T2H_TX_MODE_SWITCH_IND_PEERID_M 0xfff
#define HTT_T2H_TX_MODE_SWITCH_IND_PEERID_S 0
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_PEERID_M \
    HTT_T2H_TX_MODE_SWITCH_IND_PEERID_M
#define HTT_T2H_TX_LOW_LATENCY_IND_PEERID_S \
    HTT_T2H_TX_MODE_SWITCH_IND_PEERID_S

#define HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_M 0xf000
#define HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_S 12
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_TIDNO_M \
    HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_M
#define HTT_T2H_TX_LOW_LATENCY_IND_TIDNO_S \
    HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_S

#define HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_M 0xffff0000
#define HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_S 16
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_MAX_PKTS_M \
    HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_M
#define HTT_T2H_TX_LOW_LATENCY_IND_MAX_PKTS_S \
    HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_S

#define HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_MODE_SWITCH_IND_ENABLE, value); \
        (word) |= ((value) << HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_S);  \
    } while (0)
#define HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_GET(word) \
    (((word) & HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_M) >> \
    HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_S)
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_ENABLE_SET \
    HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_SET
#define HTT_T2H_TX_LOW_LATENCY_IND_ENABLE_GET \
    HTT_T2H_TX_MODE_SWITCH_IND_ENABLE_GET

#define HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS, value); \
        (word) |= ((value) << HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_S);  \
    } while (0)
#define HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_GET(word) \
    (((word) & HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_M) >> \
    HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_S)
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_NUM_RECORDS_SET \
    HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_SET
#define HTT_T2H_TX_LOW_LATENCY_IND_NUM_RECORDS_GET \
    HTT_T2H_TX_MODE_SWITCH_IND_NUM_RECORDS_GET

#define HTT_T2H_TX_MODE_SWITCH_IND_MODE_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_MODE_SWITCH_IND_MODE, value); \
        (word) |= ((value) << HTT_T2H_TX_MODE_SWITCH_IND_MODE_S);  \
    } while (0)
#define HTT_T2H_TX_MODE_SWITCH_IND_MODE_GET(word) \
    (((word) & HTT_T2H_TX_MODE_SWITCH_IND_MODE_M) >> \
    HTT_T2H_TX_MODE_SWITCH_IND_MODE_S)

#define HTT_T2H_TX_MODE_SWITCH_IND_THRESHOLD_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_MODE_SWITCH_IND_THRESHOLD, value); \
        (word) |= ((value) << HTT_T2H_TX_MODE_SWITCH_IND_THRESHOLD_S);  \
    } while (0)
#define HTT_T2H_TX_MODE_SWITCH_IND_THRESHOLD_GET(word) \
    (((word) & HTT_T2H_TX_MODE_SWITCH_IND_THRESHOLD_M) >> \
    HTT_T2H_TX_MODE_SWITCH_IND_THRESHOLD_S)

#define HTT_T2H_TX_MODE_SWITCH_IND_PEERID_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_MODE_SWITCH_IND_PEERID, value); \
        (word) |= ((value) << HTT_T2H_TX_MODE_SWITCH_IND_PEERID_S);  \
    } while (0)
#define HTT_T2H_TX_MODE_SWITCH_IND_PEERID_GET(word) \
    (((word) & HTT_T2H_TX_MODE_SWITCH_IND_PEERID_M) >> HTT_T2H_TX_MODE_SWITCH_IND_PEERID_S)
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_PEERID_SET \
    HTT_T2H_TX_MODE_SWITCH_IND_PEERID_SET
#define HTT_T2H_TX_LOW_LATENCY_IND_PEERID_GET \
    HTT_T2H_TX_MODE_SWITCH_IND_PEERID_GET

#define HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_MODE_SWITCH_IND_TIDNO, value); \
        (word) |= ((value) << HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_S);  \
    } while (0)
#define HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_GET(word) \
    (((word) & HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_M) >> HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_S)
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_TIDNO_SET \
    HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_SET
#define HTT_T2H_TX_LOW_LATENCY_IND_TIDNO_GET \
    HTT_T2H_TX_MODE_SWITCH_IND_TIDNO_GET

#define HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS, value); \
        (word) |= ((value) << HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_S);  \
    } while (0)
#define HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_GET(word) \
    (((word) & HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_M) >> \
    HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_S)
/* TEMPORARY ALIASES */
#define HTT_T2H_TX_LOW_LATENCY_IND_MAX_PKTS_SET \
    HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_SET
#define HTT_T2H_TX_LOW_LATENCY_IND_MAX_PKTS_GET \
    HTT_T2H_TX_MODE_SWITCH_IND_MAX_PKTS_GET

enum htt_t2h_peer_stats_version {
    HTT_T2H_PEER_STATS_V1   = 0x1,

    /* Always keep this last */
    HTT_T2H_PEER_STATS_MAX_VERSION = 0xFF
};

/**
 * @brief target -> host peer (PPDU) stats message
 *
 * @details
 * This message is generated by FW when FW is sending stats from FW to host
 * about one or more PPDUs that the FW has transmitted to one or more peers.
 * It is expected that stats for num_records PPDUs sent to a particular peer
 * will be included within one PEER_STATS message, but it is permissible to
 * upload PPDU stats from transmissions to multiple peers within a single
 * PEER_STATS message.
 *
 * The following field definitions describe the format of the HTT target
 * to host peer stats message.
 *       |31        24 |23            16|15 14|13|12 11|10 9| 8|7           0|
 *       |-------------------------------------------------------------------|
 *       |   version   | record dwords  |     num records      |  MSG_TYPE   |
 *       |-------------------------------------------------------------------|
 * rec 0 |                        ppdu successful bytes                      |
 * rec 0 |-------------------------------------------------------------------|
 * rec 0 |                        ppdu retry bytes                           |
 * rec 0 |-------------------------------------------------------------------|
 * rec 0 |                        ppdu failed bytes                          |
 * rec 0 |-------------------------------------------------------------------|
 * rec 0 |          peer id             |  R  | S|  BW | BA | A|  rate code  |
 * rec 0 |-------------------------------------------------------------------|
 * rec 0 |        retried MSDUs         |     successful MSDUs               |
 * rec 0 |-------------------------------------------------------------------|
 * rec 0 |         TX duration          |       failed MSDUs                 |
 * rec 0 |-------------------------------------------------------------------|
 * rec 0 |                           reserved1                               |
 * rec 0 |-------------------------------------------------------------------|
 * rec 0 |                           reserved2                               |
 *       |-------------------------------------------------------------------|
 *                                      ...
 *       |-------------------------------------------------------------------|
 * rec N |                        ppdu successful bytes                      |
 * rec N |-------------------------------------------------------------------|
 * rec N |                        ppdu retry bytes                           |
 * rec N |-------------------------------------------------------------------|
 * rec N |                        ppdu failed bytes                          |
 * rec N |-------------------------------------------------------------------|
 * rec N |          peer id             |  R  | S|  BW | BA | A|  rate code  |
 * rec N |-------------------------------------------------------------------|
 * rec N |        retried MSDUs         |     successful MSDUs               |
 * rec N |-------------------------------------------------------------------|
 * rec N |         TX duration          |       failed MSDUs                 |
 * rec N |-------------------------------------------------------------------|
 * rec N |                           reserved1                               |
 * rec N |-------------------------------------------------------------------|
 * rec N |                           reserved2                               |
 *       |-------------------------------------------------------------------|
 * where:
 *     A  = is A-MPDU flag
 *     BA = block-ack failure flags
 *     BW = bandwidth spec
 *     S  = SGI enabled spec
 *     R  = reserved
 * One htt_tx_peer_stats_ind instance will have stats for one PPDU,
 * num_records number of PPDU's information will be sent in one event.
 *
 * Header
 * ------
 * @msg_type         : HTT message type
 * @num_records      : Number of PPDU's stats in one event.
 * @record_dwords    : Length of each record in dword.
 * @version          : versioning for future purpose
 *                     (see htt_t2h_peer_stats_version enum)
 *
 * payload include below peer_stats information
 * --------------------------------------------
 * @tx_success_bytes : total successful bytes in the PPDU.
 * @tx_retry_bytes   : total retried bytes in the PPDU.
 * @tx_failed_bytes  : total failed bytes in the PPDU.
 * @tx_ratecode      : rate code used for the PPDU.
 * @is_ampdu         : Indicates PPDU is AMPDU or not.
 * @ba_ack_failed    : BA/ACK failed for this PPDU
 *                     b00 -> BA received
 *                     b01 -> BA failed once
 *                     b10 -> BA failed twice, when HW retry is enabled.
 * @bw               : BW
 *                     b00 -> 20 MHz
 *                     b01 -> 40 MHz
 *                     b10 -> 80 MHz
 *                     b11 -> 160 MHz (or 80+80)
 * @sgi              : SGI enabled
 * @reserved0        : reserved, for future use
 * @peer_id          : peer id
 * @tx_success_msdus : successful MSDUs
 * @tx_retry_msdus   : retried MSDUs
 * @tx_failed_msdus  : MSDUs dropped in FW after max retry
 * @tx_duration      : Tx duration for the PPDU (microsecond units)
 * @reserved1        : for future use - must be set to 0x0
 * @reserved2        : for future use - must be set to 0x0
 */
PREPACK struct htt_tx_peer_stats_ind {
     A_UINT32 tx_success_bytes;
     A_UINT32 tx_retry_bytes;
     A_UINT32 tx_failed_bytes;
     A_UINT32 tx_ratecode:       8,
              is_ampdu:          1,
              ba_ack_failed:     2,
              bw:                2,
              sgi:               1,
              reserved0:         2,
              peer_id:          16;
     A_UINT32 tx_success_msdus: 16,
              tx_retry_msdus:   16;
     A_UINT32 tx_failed_msdus:  16,
              tx_duration:      16;
     A_UINT32 reserved1;
     A_UINT32 reserved2;
} POSTPACK;

/* DWORD-4 within htt_tx_peer_stats_ind record */
#define HTT_T2H_PEER_STATS_TX_RATECODE_M        0X000000FF
#define HTT_T2H_PEER_STATS_TX_RATECODE_S        0
#define HTT_H2T_PEER_STATS_AMPDU_M              0X00000100
#define HTT_H2T_PEER_STATS_AMPDU_S              8
#define HTT_H2T_PEER_STATS_BA_ACK_FAILED_M      0x00000600
#define HTT_H2T_PEER_STATS_BA_ACK_FAILED_S      9
#define HTT_H2T_PEER_STATS_BW_M                 0x00001800
#define HTT_H2T_PEER_STATS_BW_S                 11
#define HTT_H2T_PEER_STATS_SGI_M                0x00002000
#define HTT_H2T_PEER_STATS_SGI_S                13
#define HTT_T2H_PEER_STATS_TX_PEER_ID_M         0XFFFF0000
#define HTT_T2H_PEER_STATS_TX_PEER_ID_S         16
/* DWORD-5 within htt_tx_peer_stats_ind record */
#define HTT_T2H_PEER_STATS_TX_SUCCESS_MSDUS_M   0X0000FFFF
#define HTT_T2H_PEER_STATS_TX_SUCCESS_MSDUS_S   0
#define HTT_T2H_PEER_STATS_TX_RETRY_MSDUS_M     0XFFFF0000
#define HTT_T2H_PEER_STATS_TX_RETRY_MSDUS_S     16
/* DWORD-6 within htt_tx_peer_stats_ind record */
#define HTT_T2H_PEER_STATS_TX_FAILED_MSDUS_M    0x0000FFFF
#define HTT_T2H_PEER_STATS_TX_FAILED_MSDUS_S    0
#define HTT_T2H_PEER_STATS_TX_DURATION_M        0XFFFF0000
#define HTT_T2H_PEER_STATS_TX_DURATION_S        16

#define HTT_T2H_PEER_STATS_TX_RATECODE_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_PEER_STATS_TX_RATECODE, value); \
        (word) |= (value)  << HTT_T2H_PEER_STATS_TX_RATECODE_S; \
    } while (0) \

#define HTT_T2H_PEER_STATS_TX_RATECODE_GET(word) \
        (((word) & HTT_T2H_PEER_STATS_TX_RATECODE_M) >> \
        HTT_T2H_PEER_STATS_TX_RATECODE_S)

#define HTT_T2H_PEER_STATS_AMPDU_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_PEER_STATS_AMPDU, value); \
        (word) |= (value)  << HTT_T2H_PEER_STATS_AMPDU_S; \
    } while (0) \

#define HTT_T2H_PEER_STATS_AMPDU_GET(word) \
        (((word) & HTT_T2H_PEER_STATS_AMPDU_M) >> \
        HTT_T2H_PEER_STATS_AMPDU_S)

#define HTT_T2H_PEER_STATS_BA_ACK_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_PEER_STATS_BA_ACK, value); \
        (word) |= (value)  << HTT_T2H_PEER_STATS_BA_ACK_S; \
    } while (0) \

#define HTT_T2H_PEER_STATS_BA_ACK_GET(word) \
        (((word) & HTT_T2H_PEER_STATS_BA_ACK_M) >> \
        HTT_T2H_PEER_STATS_AMPDU_S)

#define HTT_T2H_PEER_STATS_BW_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_PEER_STATS_BW, value); \
        (word) |= (value)  << HTT_T2H_PEER_STATS_BW_S; \
    } while (0) \

#define HTT_T2H_PEER_STATS_BW_GET(word) \
        (((word) & HTT_T2H_PEER_STATS_BW_M) >> \
        HTT_T2H_PEER_STATS_BW_S)

#define HTT_T2H_PEER_STATS_SGI_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_PEER_STATS_SGI, value); \
        (word) |= (value)  << HTT_T2H_PEER_STATS_SGI_S; \
    } while (0) \

#define HTT_T2H_PEER_STATS_SGI_GET(word) \
        (((word) & HTT_T2H_PEER_STATS_SGI_M) >> \
        HTT_T2H_PEER_STATS_SGI_S)

#define HTT_T2H_PEER_STATS_PEER_ID_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_PEER_STATS_PEER_ID, value); \
        (word) |= (value)  << HTT_T2H_PEER_STATS_PEER_ID_S; \
    } while (0)

#define HTT_T2H_PEER_STATS_PEER_ID_GET(word) \
        (((word) & HTT_T2H_PEER_STATS_PEER_ID_M) >> \
        HTT_T2H_PEER_STATS_PEER_ID_S)

#define HTT_T2H_PEER_STATS_TX_SUCCESS_MSDUS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_PEER_STATS_SUCCESS_MSDUS, value); \
        (word) |= (value)  << HTT_T2H_PEER_STATS_SUCCESS_MSDUS_S; \
    } while (0) \

#define HTT_T2H_PEER_STATS_TX_SUCCESS_MSDUS_GET(word) \
        (((word) & HTT_T2H_PEER_STATS_TX_SUCCESS_MSDUS_M) >> \
        HTT_T2H_PEER_STATS_TX_SUCCESS_PKTS_S)

#define HTT_T2H_PEER_STATS_TX_RETRY_MSDUS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_PEER_STATS_TX_RETRY_MSDUS, value); \
        (word) |= (value)  << HTT_T2H_PEER_STATS_TX_RETRY_MSDUS_S; \
    } while (0) \

#define HTT_T2H_PEER_STATS_TX_RETRY_MSDUS_GET(word) \
        (((word) & HTT_T2H_PEER_STATS_TX_RETRY_MSDUS_M) >> \
        HTT_T2H_PEER_STATS_TX_RETRY_PKTS_S)

#define HTT_T2H_PEER_STATS_TX_FAILED_PKTS_SET(word, value) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_PEER_STATS_TX_FAILED_MSDUS, value); \
        (word) |= (value)  << HTT_T2H_PEER_STATS_TX_FAILED_MSDUS_S; \
    } while (0) \

#define HTT_T2H_PEER_STATS_TX_FAILED_MSDUS_GET(word) \
        (((word) & HTT_T2H_PEER_STATS_TX_FAILED_MSDUS_M) >> \
        HTT_T2H_PEER_STATS_TX_FAILED_PKTS_S)

#define HTT_T2H_PEER_STATS_TX_DURATION_SET(word) \
    do { \
        HTT_CHECK_SET_VAL(HTT_T2H_PEER_STATS_TX_DURATION, value); \
        (word) |= (value)  << HTT_T2H_PEER_STATS_TX_DURATION_S; \
    } while (0)

#define HTT_T2H_PEER_STATS_TX_DURATION_GET(word) \
        (((word) & HTT_T2H_PEER_STATS_TX_DURATION_M) >> \
        HTT_T2H_PEER_STATS_TX_DURATION_CNT_S)


#define HTT_CFR_CAPTURE_MAGIC_PATTERN                0xCCCCCCCC
#define HTT_CFR_CAPTURE_READ_INDEX_OFFSET            0 /* bytes */
#define HTT_CFR_CAPTURE_SIZEOF_READ_INDEX_BYTES      4
#define HTT_CFR_CAPTURE_WRITE_INDEX_OFFSET /* bytes */ \
   (HTT_CFR_CAPTURE_READ_INDEX_OFFSET + HTT_CFR_CAPTURE_SIZEOF_READ_INDEX_BYTES)
#define HTT_CFR_CAPTURE_SIZEOF_WRITE_INDEX_BYTES     4
#define HTT_CFR_CAPTURE_SIZEOF_MAGIC_PATTERN_BYTES   4
/*
 * The read and write indices point to the data within the host buffer.
 * Because the first 4 bytes of the host buffer is used for the read index and
 * the next 4 bytes for the write index, the data itself starts at offset 8.
 * The read index and write index are the byte offsets from the base of the
 * meta-data buffer, and thus have a minimum value of 8 rather than 0.
 * Refer the ASCII text picture below.
 */
#define HTT_CFR_CAPTURE_INITIAL_RW_START_INDEX       \
   (HTT_CFR_CAPTURE_SIZEOF_READ_INDEX_BYTES +        \
    HTT_CFR_CAPTURE_SIZEOF_WRITE_INDEX_BYTES)

/*
 ***************************************************************************
 *
 * Layout when CFR capture message type is 'HTT_PEER_CFR_CAPTURE_MSG_TYPE_1'
 *
 ***************************************************************************
 *
 * The memory allocated by WMI_CHANNEL_CAPTURE_HOST_MEM_REQ_ID is used
 * in the below format. The HTT message 'htt_cfr_dump_compl_ind' is sent by
 * FW to Host whenever a CFR capture (CFR data1 or CFR data2 etc.,) is
 * written into the Host memory region mentioned below.
 *
 * Read index is updated by the Host. At any point of time, the read index will
 * indicate the index that will next be read by the Host. The read index is
 * in units of bytes offset from the base of the meta-data buffer.
 *
 * Write index is updated by the FW. At any point of time, the write index will
 * indicate from where the FW can start writing any new data. The write index is
 * in units of bytes offset from the base of the meta-data buffer.
 *
 * If the Host is not fast enough in reading the CFR data, any new capture data
 * would be dropped if there is no space left to write the new captures.
 *
 * The last 4 bytes of the memory region will have the magic pattern
 * HTT_CFR_CAPTURE_MAGIC_PATTERN. This can be used to ensure that the FW does
 * not overrun the host buffer.
 *
 *       ,--------------------.           read and write indices store the
 *       |                    |           byte offset from the base of the
 *       |           ,--------+--------.  meta-data buffer to the next
 *       |           |        |        |  location within the data buffer
 *       |           |        v        v  that will be read / written
 *   ************************************************************************
 *   *  Read     *   Write   *                                   *  Magic   *
 *   *  index    *   index   * CFR data1 ......  CFR data N      * pattern  *
 *   * (4 bytes) * (4 bytes) *                                   * (4 bytes)*
 *   ************************************************************************
 *                           |<---------- data buffer ---------->|
 *
 *   |<----------------- meta-data buffer allocated in Host ----------------|
 *
 * Note:
 *   - Considering the 4 bytes needed to store the Read index (R) and the
 *     Write index (W), the initial value is as follows:
 *     R = W = HTT_CFR_CAPTURE_INITIAL_RW_START_INDEX
 *   - Buffer empty condition:
 *     R = W
 *
 * Regarding CFR data format:
 * --------------------------
 *
 * Each CFR tone is stored in HW as 16-bits with the following format:
 * {bits[15:12], bits[11:6], bits[5:0]} =
 *                         {unsigned exponent (4 bits),
 *                         signed mantissa_real (6 bits),
 *                         signed mantissa_imag (6 bits)}
 *
 * CFR_real = mantissa_real * 2^(exponent-5)
 * CFR_imag = mantissa_imag * 2^(exponent-5)
 *
 *
 * The CFR data is written to the 16-bit unsigned output array (buff) in
 * ascending tone order. For example, the Legacy20 CFR is output as follows:
 *
 *        buff[0]: [CFR_exp[-26], CFR_mant_real[-26], CFR_mant_imag[-26]]
 *        buff[1]: [CFR_exp[-25], CFR_mant_real[-25], CFR_mant_imag[-25]]
 *                            .
 *                            .
 *                            .
 *        buff[N-2]: [CFR_exp[25], CFR_mant_real[25], CFR_mant_imag[25]]
 *        buff[N-1]: [CFR_exp[26], CFR_mant_real[26], CFR_mant_imag[26]]
 */

/* 2 word representation of MAC addr */
typedef struct {
    /* upper 4 bytes of MAC address */
    A_UINT32 mac_addr31to0;
    /* lower 2 bytes of MAC address.
     * These 16 bits are in bits 15:0 of this A_UINT32.
     */
    A_UINT32 mac_addr47to32;
} htt_mac_addr;

/* Bandwidth of peer CFR captures */
typedef enum {
    HTT_PEER_CFR_CAPTURE_BW_20MHZ    = 0,
    HTT_PEER_CFR_CAPTURE_BW_40MHZ    = 1,
    HTT_PEER_CFR_CAPTURE_BW_80MHZ    = 2,
    HTT_PEER_CFR_CAPTURE_BW_160MHZ   = 3,
    HTT_PEER_CFR_CAPTURE_BW_80_80MHZ = 4,
    HTT_PEER_CFR_CAPTURE_BW_MAX,
} HTT_PEER_CFR_CAPTURE_BW;

/* Mode of the peer CFR captures. The type of RX frame for which the CFR
 * was captured
 */
typedef enum {
    HTT_PEER_CFR_CAPTURE_MODE_LEGACY     = 0,
    HTT_PEER_CFR_CAPTURE_MODE_DUP_LEGACY = 1,
    HTT_PEER_CFR_CAPTURE_MODE_HT         = 2,
    HTT_PEER_CFR_CAPTURE_MODE_VHT        = 3,
    HTT_PEER_CFR_CAPTURE_MODE_MAX,
} HTT_PEER_CFR_CAPTURE_MODE;

typedef enum {
    /* This message type is currently used for the below purpose:
     *
     * - capture_method = WMI_PEER_CFR_CAPTURE_METHOD_NULL_FRAME in the
     *   wmi_peer_cfr_capture_cmd. The associated memory region gets allocated
     *   through WMI_CHANNEL_CAPTURE_HOST_MEM_REQ_ID
     */
    HTT_PEER_CFR_CAPTURE_MSG_TYPE_1  = 0x1,

    /* Always keep this last */
    HTT_PEER_CFR_CAPTURE_MSG_TYPE_MAX,
} HTT_PEER_CFR_CAPTURE_MSG_TYPE;

/**
 * @brief target -> host CFR dump completion indication message definition
 * htt_cfr_dump_compl_ind when the version is HTT_PEER_CFR_CAPTURE_MSG_TYPE_1.
 *
 * @details
 * The following diagram shows the format of the Channel Frequency Response
 * (CFR) dump completion indication. This inidcation is sent to the Host when
 * the channel capture of a peer is copied by Firmware into the Host memory
 *
 * **************************************************************************
 *
 *   Message format when the CFR capture message type is
 *   'HTT_PEER_CFR_CAPTURE_MSG_TYPE_1'
 *
 * **************************************************************************
 *
 *          |31                           16|15                   |7        0|
 *          |----------------------------------------------------------------|
 * header:  |                           reserved                  | msg_type |
 * word 0   |                                                     |          |
 *          |----------------------------------------------------------------|
 * payload: |                      cfr_capture_msg_type                      |
 * word 1   |                                                                |
 *          |----------------------------------------------------------------|
 *          | vdev_id | captype |   chbw   | sts | mode | capbw |S| req_id   |
 * word 2   |         |         |          |     |      |       | |          |
 *          |----------------------------------------------------------------|
 *          |                          mac_addr31to0                         |
 * word 3   |                                                                |
 *          |----------------------------------------------------------------|
 *          |      unused / reserved        |       mac_addr47to32           |
 * word 4   |                               |                                |
 *          |----------------------------------------------------------------|
 *          |                             index                              |
 * word 5   |                                                                |
 *          |----------------------------------------------------------------|
 *          |                             length                             |
 * word 6   |                                                                |
 *          |----------------------------------------------------------------|
 *          |                           timestamp                            |
 * word 7   |                                                                |
 *          |----------------------------------------------------------------|
 *          |                            counter                             |
 * word 8   |                                                                |
 *          |----------------------------------------------------------------|
 *          |                            chan_mhz                            |
 * word 9   |                                                                |
 *          |----------------------------------------------------------------|
 *          |                        band_center_freq1                       |
 * word 10  |                                                                |
 *          |----------------------------------------------------------------|
 *          |                        band_center_freq2                       |
 * word 11  |                                                                |
 *          |----------------------------------------------------------------|
 *          |                          chan_phy_mode                         |
 * word 12  |                                                                |
 *          |----------------------------------------------------------------|
 * where,
 * req_id  - memory request id (mem_req_id explained below)
 * S       - status field (status explained below)
 * capbw   - capture bandwidth (capture_bw explained below)
 * mode    - mode of capture (mode explained below)
 * sts     - space time streams (sts_count explained below)
 * chbw    - channel bandwidth (channel_bw explained below)
 * captype - capture type (cap_type explained below)
 *
 * The following field definitions describe the format of the CFR dump
 * completion indication sent from the target to the host
 *
 * Header fields:
 *
 * Word 0
 * - msg_type
 *   Bits 7:0
 *   Purpose: Identifies this as CFR TX completion indication
 *   Value: HTT_T2H_MSG_TYPE_CFR_DUMP_COMPL_IND
 * - reserved
 *   Bits 31:8
 *   Purpose: Reserved
 *   Value: 0
 *
 * Payload fields:
 *
 * Word 1
 * - cfr_capture_msg_type
 *   Bits 31:0
 *   Purpose: Contains the type of the message HTT_PEER_CFR_CAPTURE_MSG_TYPE
 *       to specify the format used for the remainder of the message
 *   Value: HTT_PEER_CFR_CAPTURE_MSG_TYPE_1
 *          (currently only MSG_TYPE_1 is defined)
 *
 * Word 2
 * - mem_req_id
 *   Bits 6:0
 *   Purpose: Contain the mem request id of the region where the CFR capture
 *       has been stored - of type WMI_HOST_MEM_REQ_ID
 *   Value: WMI_CHANNEL_CAPTURE_HOST_MEM_REQ_ID
 * - status
 *   Bit 7
 *   Purpose: Boolean value carrying the status of the CFR capture of the peer
 *   Value: 1 (True) - Successful; 0 (False) - Not successful
 * - capture_bw
 *   Bits 10:8
 *   Purpose: Carry the bandwidth of the CFR capture
 *   Value: Bandwidth of the CFR capture of type HTT_PEER_CFR_CAPTURE_BW
 * - mode
 *   Bits 13:11
 *   Purpose: Carry the mode of the rx frame for which the CFR was captured
 *   Value: Mode of the CFR capture of type HTT_PEER_CFR_CAPTURE_MODE
 * - sts_count
 *   Bits 16:14
 *   Purpose: Carry the number of space time streams
 *   Value: Number of space time streams
 * - channel_bw
 *   Bits 19:17
 *   Purpose: Carry the bandwidth of the channel of the vdev performing the
 *       measurement
 *   Value: Bandwidth of the channel (of type HTT_PEER_CFR_CAPTURE_BW)
 * - cap_type
 *   Bits 23:20
 *   Purpose: Carry the type of the capture
 *   Value: Capture type (of type WMI_PEER_CFR_CAPTURE_METHOD)
 * - vdev_id
 *   Bits 31:24
 *   Purpose: Carry the virtual device id
 *   Value: vdev ID
 *
 * Word 3
 * - mac_addr31to0
 *   Bits 31:0
 *   Purpose: Contain the bits 31:0 of the peer MAC address
 *   Value: Bits 31:0 of the peer MAC address
 *
 * Word 4
 * - mac_addr47to32
 *   Bits 15:0
 *   Purpose: Contain the bits 47:32 of the peer MAC address
 *   Value: Bits 47:32 of the peer MAC address
 *
 * Word 5
 * - index
 *   Bits 31:0
 *   Purpose: Contain the index at which this CFR dump was written in the Host
 *   allocated memory. This index is the number of bytes from the base address.
 *   Value: Index position
 *
 * Word 6
 * - length
 *   Bits 31:0
 *   Purpose: Carry the length of the CFR capture of the peer, in bytes
 *   Value: Length of the CFR capture of the peer
 *
 * Word 7
 * - timestamp
 *   Bits 31:0
 *   Purpose: Carry the time at which the CFR was captured in the hardware. The
 *   clock used for this timestamp is private to the target and not visible to
 *   the host i.e., Host can interpret only the relative timestamp deltas from
 *   one message to the next, but can't interpret the absolute timestamp from a
 *   single message.
 *   Value: Timestamp in microseconds
 *
 * Word 8
 * - counter
 *   Bits 31:0
 *   Purpose: Carry the count of the current CFR capture from FW. This is
 *   helpful to identify any drops in FW in any scenario (e.g., lack of space
 *   in host memory)
 *   Value: Count of the current CFR capture
 *
 * Word 9
 * - chan_mhz
 *   Bits 31:0
 *   Purpose: Carry the primary 20 MHz channel frequency in MHz of the VDEV
 *   Value: Primary 20 channel frequency
 *
 * Word 10
 * - band_center_freq1
 *   Bits 31:0
 *   Purpose: Carry the center frequency 1 in MHz of the VDEV
 *   Value: Center frequency 1 in MHz
 *
 * Word 11
 * - band_center_freq2
 *   Bits 31:0
 *   Purpose: Carry the center frequency 2 in MHz. valid only for 11acvht of
 *   the VDEV
 *   80plus80 mode
 *   Value: Center frequency 2 in MHz
 *
 * Word 12
 * - chan_phy_mode
 *   Bits 31:0
 *   Purpose: Carry the phy mode of the channel, of the VDEV
 *   Value: WLAN_PHY_MODE of the channel defined in wlan_defs.h
 */
PREPACK struct htt_cfr_dump_ind_type_1 {
    A_UINT32 mem_req_id:7,
             status:1,
             capture_bw:3,
             mode:3,
             sts_count:3,
             channel_bw:3,
             cap_type:4,
             vdev_id:8;
    htt_mac_addr addr;
    A_UINT32 index;
    A_UINT32 length;
    A_UINT32 timestamp;
    A_UINT32 counter;
    struct htt_chan_change_msg chan;
} POSTPACK;

PREPACK struct htt_cfr_dump_compl_ind {
    A_UINT32 msg_type; /* HTT_PEER_CFR_CAPTURE_MSG_TYPE */
    union {
        /* Message format when msg_type = HTT_PEER_CFR_CAPTURE_MSG_TYPE_1 */
        struct htt_cfr_dump_ind_type_1 htt_cfr_dump_compl_ind_type_1;
        /* If there is a need to change the memory layout and its associated
         * HTT indication format, a new CFR capture message type can be
         * introduced and added into this union.
         */
    };
} POSTPACK;

/*
 * Get / set macros for the bit fields within WORD-2 of htt_cfr_dump_compl_ind,
 * msg_type = HTT_PEER_CFR_CAPTURE_MSG_TYPE_1
 */
#define HTT_T2H_CFR_DUMP_TYPE1_MEM_REQ_ID_M        0X0000007F
#define HTT_T2H_CFR_DUMP_TYPE1_MEM_REQ_ID_S        0
#define HTT_T2H_CFR_DUMP_TYPE1_STATUS_M            0X00000080
#define HTT_T2H_CFR_DUMP_TYPE1_STATUS_S            7
#define HTT_T2H_CFR_DUMP_TYPE1_CAP_BW_M            0X00000700
#define HTT_T2H_CFR_DUMP_TYPE1_CAP_BW_S            8
#define HTT_T2H_CFR_DUMP_TYPE1_MODE_M              0X00003800
#define HTT_T2H_CFR_DUMP_TYPE1_MODE_S              11
#define HTT_T2H_CFR_DUMP_TYPE1_STS_M               0X0001C000
#define HTT_T2H_CFR_DUMP_TYPE1_STS_S               14
#define HTT_T2H_CFR_DUMP_TYPE1_CHAN_BW_M           0X000E0000
#define HTT_T2H_CFR_DUMP_TYPE1_CHAN_BW_S           17
#define HTT_T2H_CFR_DUMP_TYPE1_CAP_TYPE_M          0X00F00000
#define HTT_T2H_CFR_DUMP_TYPE1_CAP_TYPE_S          20
#define HTT_T2H_CFR_DUMP_TYPE1_VDEV_ID_M           0XFF000000
#define HTT_T2H_CFR_DUMP_TYPE1_VDEV_ID_S           24
 
#define HTT_T2H_CFR_DUMP_TYPE1_MEM_REQ_ID_SET(word, value) \
   do { \
          HTT_CHECK_SET_VAL(HTT_T2H_CFR_DUMP_TYPE1_MEM_REQ_ID, value); \
          (word) |= (value)  << HTT_T2H_CFR_DUMP_TYPE1_MEM_REQ_ID_S; \
      } while (0)
#define HTT_T2H_CFR_DUMP_TYPE1_MEM_REQ_ID_GET(word) \
       (((word) & HTT_T2H_CFR_DUMP_TYPE1_MEM_REQ_ID_M) >> \
           HTT_T2H_CFR_DUMP_TYPE1_MEM_REQ_ID_S)
 
#define HTT_T2H_CFR_DUMP_TYPE1_STATUS_SET(word, value) \
   do { \
          HTT_CHECK_SET_VAL(HTT_T2H_CFR_DUMP_TYPE1_STATUS, value); \
          (word) |= (value)  << HTT_T2H_CFR_DUMP_TYPE1_STATUS_S; \
      } while (0)
#define HTT_T2H_CFR_DUMP_TYPE1_STATUS_GET(word) \
      (((word) & HTT_T2H_CFR_DUMP_TYPE1_STATUS_M) >> \
          HTT_T2H_CFR_DUMP_TYPE1_STATUS_S)
 
#define HTT_T2H_CFR_DUMP_TYPE1_CAP_BW_SET(word, value) \
   do { \
          HTT_CHECK_SET_VAL(HTT_T2H_CFR_DUMP_TYPE1_CAP_BW, value); \
          (word) |= (value)  << HTT_T2H_CFR_DUMP_TYPE1_CAP_BW_S; \
      } while (0)
#define HTT_T2H_CFR_DUMP_TYPE1_CAP_BW_GET(word) \
        (((word) & HTT_T2H_CFR_DUMP_TYPE1_CAP_BW_M) >> \
           HTT_T2H_CFR_DUMP_TYPE1_CAP_BW_S)
 
#define HTT_T2H_CFR_DUMP_TYPE1_MODE_SET(word, value) \
   do { \
          HTT_CHECK_SET_VAL(HTT_T2H_CFR_DUMP_TYPE1_MODE, value); \
          (word) |= (value)  << HTT_T2H_CFR_DUMP_TYPE1_MODE_S; \
      } while (0)
#define HTT_T2H_CFR_DUMP_TYPE1_MODE_GET(word) \
        (((word) & HTT_T2H_CFR_DUMP_TYPE1_MODE_M) >> \
            HTT_T2H_CFR_DUMP_TYPE1_MODE_S)
 
#define HTT_T2H_CFR_DUMP_TYPE1_STS_SET(word, value) \
   do { \
          HTT_CHECK_SET_VAL(HTT_T2H_CFR_DUMP_TYPE1_STS, value); \
          (word) |= (value)  << HTT_T2H_CFR_DUMP_TYPE1_STS_S; \
      } while (0)
#define HTT_T2H_CFR_DUMP_TYPE1_STS_GET(word) \
        (((word) & HTT_T2H_CFR_DUMP_TYPE1_STS_M) >> \
            HTT_T2H_CFR_DUMP_TYPE1_STS_S)
 
#define HTT_T2H_CFR_DUMP_TYPE1_CHAN_BW_SET(word, value) \
   do { \
          HTT_CHECK_SET_VAL(HTT_T2H_CFR_DUMP_TYPE1_CHAN_BW, value); \
          (word) |= (value)  << HTT_T2H_CFR_DUMP_TYPE1_CHAN_BW_S; \
      } while (0)
#define HTT_T2H_CFR_DUMP_TYPE1_CHAN_BW_GET(word) \
        (((word) & HTT_T2H_CFR_DUMP_TYPE1_CHAN_BW_M) >> \
            HTT_T2H_CFR_DUMP_TYPE1_CHAN_BW_S)
 
#define HTT_T2H_CFR_DUMP_TYPE1_CAP_TYPE_SET(word, value) \
   do { \
          HTT_CHECK_SET_VAL(HTT_T2H_CFR_DUMP_TYPE1_CAP_TYPE, value); \
          (word) |= (value)  << HTT_T2H_CFR_DUMP_TYPE1_CAP_TYPE_S; \
      } while (0)
#define HTT_T2H_CFR_DUMP_TYPE1_CAP_TYPE_GET(word) \
        (((word) & HTT_T2H_CFR_DUMP_TYPE1_CAP_TYPE_M) >> \
            HTT_T2H_CFR_DUMP_TYPE1_CAP_TYPE_S)
 
#define HTT_T2H_CFR_DUMP_TYPE1_VDEV_ID_SET(word, value) \
   do { \
          HTT_CHECK_SET_VAL(HTT_T2H_CFR_DUMP_TYPE1_VDEV_ID, value); \
          (word) |= (value)  << HTT_T2H_CFR_DUMP_TYPE1_VDEV_ID_S; \
      } while (0)
#define HTT_T2H_CFR_DUMP_TYPE1_VDEV_ID_GET(word) \
        (((word) & HTT_T2H_CFR_DUMP_TYPE1_VDEV_ID_M) >> \
            HTT_T2H_CFR_DUMP_TYPE1_VDEV_ID_S)

#endif
