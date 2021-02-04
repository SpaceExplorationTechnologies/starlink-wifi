/*
 **************************************************************************
 * Copyright (c) 2017-2018, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 **************************************************************************
 */

 /**
  * @file nss_wifili_if.h
  *	NSS TO HLOS interface definitions.
  *	NOTE: Here we will use wifili as a reference to
  *	the IPQ807x Wi-Fi object.
  */
#ifndef __NSS_WIFILI_H
#define __NSS_WIFILI_H

 /**
  * @addtogroup nss_wifili_subsystem
  * @{
  */

#define NSS_WIFILI_MAX_SRNG_REG_GROUPS_MSG 2
				/**< Maximum srng (ring) register groups. */
#define NSS_WIFILI_MAX_NUMBER_OF_PAGE_MSG 32
				/**< Maximum number of pages allocated from host. */
#define NSS_WIFILI_MAX_TCL_DATA_RINGS_MSG 4
				/**< Maximum number of Transmit Classifier data ring for NSS. */
#define NSS_WIFILI_MAX_REO_DATA_RINGS_MSG 4
				/**< Maximum number of Reorder (reo) data ring for NSS. */
#define NSS_WIFILI_SOC_PER_PACKET_METADATA_OFFSET 4
				/**< Metadata area for storing Rx statistics. */
#define NSS_WIFILI_MAX_TXDESC_POOLS_MSG 4
				/**< Maximum number of Tx Descriptor software pools. */
#define NSS_WIFILI_MAX_TX_EXT_DESC_POOLS_MSG 4
				/**< Maximum number of Tx Descriptor Extended software pools. */
#define NSS_WIFILI_MAX_PDEV_NUM_MSG 3
				/**< Maximum number of pdev devices. */
#define NSS_WIFILI_MAX_MCS 12
				/**< Maximum Modulaton And Coding Scheme (MCS) count. */
#define NSS_WIFILI_MAX_MCS_11A 8
				/**< Maximum MCS for 11a mode. */
#define NSS_WIFILI_MAX_MCS_11B 7
				/**< Maximum MCS for 11b mode. */
#define NSS_WIFILI_MAX_MCS_11AC 10
				/**< Maximum MCS for 11ac mode. */
#define NSS_WIFILI_MAX_MCS_11AX 10
				/**< Maximum MCS for 11ax mode. */
#define NSS_WIFILI_SS_COUNT 8
				/**< Maximum spatial streams count. */
#define NSS_WIFILI_SUPPORTED_BW 4
				/**< Maximum number of bandwidth supported. */
#define NSS_WIFILI_REPT_MU_MIMO 1
#define NSS_WIFILI_REPT_MU_OFDMA_MIMO 3
#define NSS_WIFILI_SUPPORTED_RECEPTION_TYPES 4
				/**< Maximum supported reception types. */
#define NSS_WIFILI_SOC_PER_PACKET_METADATA_SIZE 60
				/**< Metadata area total size. */
#define NSS_WIFILI_MEC_PEER_ID 0xDEAD
				/**< MEC (Multicast echo check) peer ID. */
#define NSS_WIFILI_MIC_KEY_LEN 8
				/**< MIC (Message integrity code) key length. */

/**
 * nss_wifili_wme_stream_classes
 *	WME stream classes.
 */
enum nss_wifili_wme_stream_classes {
	NSS_WIFILI_WME_AC_BE,	/**< Best effort. */
	NSS_WIFILI_WME_AC_BK,	/**< Background. */
	NSS_WIFILI_WME_AC_VI,	/**< Video. */
	NSS_WIFILI_WME_AC_VO,	/**< Voice. */
	NSS_WIFILI_WME_AC_MAX	/**< Maximum AC Value. */
};

/**
 * nss_wifili_packet_type
 *	Different Packet Types.
 */
enum nss_wifili_packet_type {
	NSS_WIFILI_DOT11_A,		/**< 802.11a packet type. */
	NSS_WIFILI_DOT11_B,		/**< 802.11b packet type. */
	NSS_WIFILI_DOT11_N,		/**< 802.11n packet type. */
	NSS_WIFILI_DOT11_AC,		/**< 802.11ac packet type. */
	NSS_WIFILI_DOT11_AX ,		/**< 802.11ax packet type. */
	NSS_WIFILI_DOT11_MAX		/**< Maximum 802.11 packet types. */
};

/*
 * nss_wifili_decap_pkt_type
 *	Different Decapsulation packet types
 */
enum wifili_decap_pkt_type {
	NSS_WIFILI_DECAP_TYPE_RAW,		/**< Raw packet type. */
	NSS_WIFILI_DECAP_TYPE_NATIVE_WIFI,	/**< Native Wi-Fi packet type. */
	NSS_WIFILI_DECAP_TYPE_ETHERNET,		/**< Ethernet packet type. */
	NSS_WIFILI_DECAP_TYPE_MAX,		/**< Maximum packet type. */
};

/**
 * nss_wifili_msg_types
 *	NSS wifili messages.
 */
enum nss_wifili_msg_types {
	NSS_WIFILI_INIT_MSG,
	NSS_WIFILI_SOC_RESET_MSG,
	NSS_WIFILI_PDEV_INIT_MSG,
	NSS_WIFILI_PDEV_DEINIT_MSG,
	NSS_WIFILI_START_MSG,
	NSS_WIFILI_STOP_MSG,
	NSS_WIFILI_PEER_CREATE_MSG,
	NSS_WIFILI_PEER_DELETE_MSG,
	NSS_WIFILI_SEND_PEER_MEMORY_REQUEST_MSG,
	NSS_WIFILI_PEER_FREELIST_APPEND_MSG,
	NSS_WIFILI_STATS_MSG,
	NSS_WIFILI_WDS_VENDOR_MSG,
	NSS_WIFILI_PEER_STATS_MSG,
	NSS_WIFILI_WDS_PEER_ADD_MSG,
	NSS_WIFILI_WDS_PEER_DEL_MSG,
	NSS_WIFILI_WDS_PEER_MAP_MSG,
	NSS_WIFILI_WDS_ACTIVE_INFO_MSG,
	NSS_WIFILI_STATS_CFG_MSG,
	NSS_WIFILI_TID_REOQ_SETUP_MSG,
	NSS_WIFILI_RADIO_CMD_MSG,
	NSS_WIFILI_LINK_DESC_INFO_MSG,
	NSS_WIFILI_PEER_SECURITY_TYPE_MSG,
	NSS_WIFILI_MAX_MSG
};

/**
 * nss_wifili_error_types
 *	Wifili error message types for functions.
 */
enum nss_wifili_error_types {
	NSS_WIFILI_EMSG_NONE,
			/**< No error. */
	NSS_WIFILI_EMSG_RINGS_INIT_FAIL,
			/**< Device ring initialization failure. */
	NSS_WIFILI_EMSG_PDEV_INIT_IMPROPER_STATE_FAIL,
			/**< Radio initialization failure due to improper state of device. */
	NSS_WIFILI_EMSG_PDEV_INIT_INVALID_RADIOID_FAIL,
			/**< Radio initialization failed due to invalid radio ID. */
	NSS_WIFILI_EMSG_PDEV_RESET_INVALID_RADIOID_FAIL,
			/**< Radio reset failed due to invalid radio ID. */
	NSS_WIFILI_EMSG_START_IMPROPER_STATE_FAIL,
			/**< Device start failure due to improper state. */
	NSS_WIFILI_EMSG_PEER_CREATE_FAIL,
			/**< Peer creation failure. */
	NSS_WIFILI_EMSG_PEER_DELETE_FAIL,
			/**< Peer delete failure. */
	NSS_WIFILI_EMSG_HASHMEM_INIT_FAIL,
			/**< Peer hash memory initialization failure. */
	NSS_WIFILI_EMSG_PEER_FREELIST_APPEND_FAIL,
			/**< Peer freelist append failure. */
	NSS_WIFILI_EMSG_PEER_CREATE_INVALID_VDEVID_FAIL,
			/**< Peer creation failure due to invalid vdev ID. */
	NSS_WIFILI_EMSG_PEER_CREATE_INVALID_PEER_ID_FAIL,
			/**< Peer creation failure due to invalid peer ID. */
	NSS_WIFILI_EMSG_PEER_CREATE_VDEV_NULL_FAIL,
			/**< Peer creation failure due to null vdev. */
	NSS_WIFILI_EMSG_PEER_CREATE_PDEV_NULL_FAIL,
			/**< Peer creation failure due to null peer. */
	NSS_WIFILI_EMSG_PEER_CREATE_ALLOC_FAIL,
			/**< Peer creation failure due to memory allocation failure. */
	NSS_WIFILI_EMSG_PEER_DELETE_VAPID_INVALID_FAIL,
			/**< Peer delete failure due to invalid vdev_ID. */
	NSS_WIFILI_EMSG_PEER_DELETE_INVALID_PEERID_FAIL,
			/**< Peer delete failure due to invalid peer ID. */
	NSS_WIFILI_EMSG_PEER_DELETE_VDEV_NULL_FAIL,
			/**< Peer delete failure due to null vdev. */
	NSS_WIFILI_EMSG_PEER_DELETE_PDEV_NULL_FAIL,
			/**< Peer creation failure due to null vdev. */
	NSS_WIFILI_EMSG_PEER_DELETE_PEER_NULL_FAIL,
			/**< Peer creation failure due to null peer. */
	NSS_WIFILI_EMSG_PEER_DELETE_PEER_CORRUPTED_FAIL,
			/**< Peer creation failure due to corrupted peer. */
	NSS_WIFILI_EMSG_GROUP0_TIMER_ALLOC_FAIL,
			/**< Timer allocation failure. */
	NSS_WIFILI_EMSG_INSUFFICIENT_WT_FAIL,
			/**< Insufficient worker thread error. */
	NSS_WIFILI_EMSG_INVALID_NUM_TCL_RING_FAIL,
			/**< Invlalid number of Transmit Classifier ring provided in initialization message. */
	NSS_WIFILI_EMSG_INVALID_NUM_REO_DST_RING_FAIL,
			/**< Invalid number of reorder destination ring in initialization message. */
	NSS_WIFILI_EMSG_HAL_SRNG_SOC_ALLOC_FAIL,
			/**< Srng SoC memory allocation failure. */
	NSS_WIFILI_EMSG_HAL_TCL_SRNG_ALLOC_FAIL,
			/**< Transmit Classifier srng ring allocation failure. */
	NSS_WIFILI_EMSG_HAL_TXCOMP_SRNG_ALLOC_FAIL,
			/**< Txcomp srng ring allocation failure. */
	NSS_WIFILI_EMSG_HAL_REODST_SRNG_ALLOC_FAIL,
			/**< Reorder destination srng ring allocation failure. */
	NSS_WIFILI_EMSG_HAL_REOREINJECT_SRNG_ALLOC_FAIL,
			/**< Reorder reinject srng ring allocation failure. */
	NSS_WIFILI_EMSG_HAL_RXRELEASE_SRNG_ALLOC_FAIL,
			/**< Rx release srng ring allocation failure. */
	NSS_WIFILI_EMSG_HAL_RXEXCP_SRNG_ALLOC_FAIL,
			/**< Rx exception srng ring allocation failure. */
	NSS_WIFILI_EMSG_HAL_TX_MEMALLOC_FAIL,
			/**< Tx HAL (hardware abstraction layer) srng ring allocation failure. */
	NSS_WIFILI_EMSG_HAL_TX_INVLID_POOL_NUM_FAIL,
			/**< Invalid pool number in initialization message. */
	NSS_WIFILI_EMSG_HAL_TX_INVALID_PAGE_NUM_FAIL,
			/**< Invalid page numner in initialization message. */
	NSS_WIFILI_EMSG_HAL_TX_DESC_MEM_ALLOC_FAIL,
			/**< Tx descriptor memory allocation failure. */
	NSS_WIFILI_EMSG_HAL_RX_MEMALLOC_FAIL,
			/**< Rx memory allocation failure. */
	NSS_WIFILI_EMSG_PDEV_RXDMA_RING_ALLOC_FAIL,
			/**< Rx DMA ring allocation failed. */
	NSS_WIFILI_EMSG_NAWDSEN_PEERID_INVALID,
			/**< Peer NAWDS enable failure due to invalid peer ID. */
	NSS_WIFILI_EMSG_NAWDSEN_PEER_NULL,
			/**< Peer NAWDS enable failure due to peer being null. */
	NSS_WIFILI_EMSG_NAWDSEN_PEER_CORRUPTED,
			/**< Peer NAWDS enable failure due to corrupted peer. */
	NSS_WIFILI_EMSG_WDS_PEER_CFG_FAIL,
			/**< WDS peer configuration failure. */
	NSS_WIFILI_EMSG_RESET_NO_STOP,
			/**< Reset issued without stopping the device. */
	NSS_WIFILI_EMSG_HAL_SRNG_INVALID_RING_BASE_FAIL,
			/**< Ring base address is invalid. */
	NSS_WIFILI_EMSG_PDEV_RX_INIT_FAIL,
			/**< Pdev Rx initialization failure. */
	NSS_WIFILI_EMESG_AST_ADD_FAIL,
			/**< AST entry addition failure for connected peer. */
	NSS_WIFILI_EMESG_AST_REMOVE_FAIL,
			/**< AST entry removal failure for connected peer. */
	NSS_WIFILI_EMESG_WDS_ADD_FAIL,
			/**< WDS peer AST entry addition failure. */
	NSS_WIFILI_EMESG_WDS_REMOVE_FAIL,
			/**< WDS peer AST entry removal failure. */
	NSS_WIFILI_EMESG_WDS_MAP_FAIL,
			/**< WDS peer AST entry hardware index mapping failure. */
	NSS_WIFILI_EMSG_WDS_INVALID_PEERID_FAIL,
			 /**< Invalid peer id passed in WDS messages. */
	NSS_WIFILI_EMSG_WDS_DUPLICATE_AST_INDEX_PEER_ID_FAIL,
			/**< AST entry index is already filled. */
	NSS_WIFILI_EMSG_PEER_SECURITY_PEER_NULL_FAIL,
			/**< Security message failed as peer is null for a peer ID. */
	NSS_WIFILI_EMSG_PEER_SECURITY_PEER_CORRUPTED_FAIL,
			/**< Security message failed as peer is corrupted. */
	NSS_WIFILI_EMSG_UNKNOWN
			/**< Unknown error message. */
};

/**
 * nss_wifili_soc_extended_data_types
 *	Enumeration of extended data type to host.
 */
enum nss_wifili_soc_extended_data_types {
	NSS_WIFILI_SOC_EXT_DATA_PKT_TYPE_NONE,		/**< Packet type is none. */
	NSS_WIFILI_SOC_EXT_DATA_PKT_MSDU_LINK_DESC,	/**< Packet type is MSDU link descriptor. */
	NSS_WIFILI_SOC_EXT_DATA_PKT_INVALID_PEER,	/**< Packet type is invalid peer. */
	NSS_WIFILI_SOC_EXT_DATA_PKT_MIC_ERROR,		/**< Packet received with MIC error. */
	NSS_WIFILI_SOC_EXT_DATA_PKT_TYPE_MAX		/**< Maximum extended data types. */
};

/**
 * nss_wifili_radio_cmd
 *	Wi-Fi radio commands for wifili.
 */
enum nss_wifili_radio_cmd {
	NSS_WIFILI_RADIO_TX_CAPTURE_CMD,			/**< Enable Tx capture. */
	NSS_WIFILI_RADIO_MAX_CMD
};

/**
 * nss_wifili_hal_srng_info
 *	Wifili HAL srng information.
 */
struct nss_wifili_hal_srng_info{
	uint8_t ring_id;
			/**< Ring ID. */
	uint8_t mac_id;
			/**< Pdev ID. */
	uint8_t resv[2];
	uint32_t ring_base_paddr;
			/**< Physical base address of the ring. */
	uint32_t num_entries;
			/**< Number of entries in ring. */
	uint32_t flags;	/**< Miscellaneous flags. */
	uint32_t ring_dir;
			/**< Ring direction: source or destination. */
	uint32_t entry_size;
			/**< Ring entry size. */
	uint32_t low_threshold;
			/**< Low threshold – in number of ring entries (valid for source rings only). */
	uint32_t hwreg_base[NSS_WIFILI_MAX_SRNG_REG_GROUPS_MSG];
			/**< Hardware ring base address. */
};

/**
 * nss_wifili_hal_srng_soc_msg
 *	Wifili hal srng message.
 */
struct nss_wifili_hal_srng_soc_msg {
	uint32_t dev_base_addr;
			/**< Base address of wlan dev. */
	uint32_t shadow_rdptr_mem_addr;
			/**< Shadow read pointer address. */
	uint32_t shadow_wrptr_mem_addr;
			/**< Shadow write pointer address. */
};

/**
 * nss_wifili_tx_desc_init_msg
 *	Wifili software descriptor pool initialization message.
 */
struct nss_wifili_tx_desc_init_msg {
	uint32_t num_tx_desc;
			/**< Count of the software descriptors. */
	uint32_t num_tx_desc_ext;
			/**< Count of software extented descriptors. */
	uint32_t num_pool;
			/**< Number of descriptor pools. */
	uint32_t memory_addr[NSS_WIFILI_MAX_NUMBER_OF_PAGE_MSG];
			/**< Memory start address of each page. */
	uint32_t memory_size[NSS_WIFILI_MAX_NUMBER_OF_PAGE_MSG];
			/**< Memory size. */
	uint32_t num_memaddr;
			/**< Number of memory address. */
	uint32_t ext_desc_page_num;
			/**< Extended descriptor page number. */
};

/**
 * nss_wifili_init_msg
 *	Wifili SoC initialization message.
 */
struct nss_wifili_init_msg {
	struct nss_wifili_hal_srng_soc_msg hssm;
	uint8_t num_tcl_data_rings;
			/**< Number of Transmit Classifier data rings. */
	uint8_t num_reo_dest_rings;
			/**< Number of reorder rings. */
	uint8_t flags;
			/**< Flags for SoC initialization */
	uint8_t resv[1];
			/**< Reserve for alignment. */
	struct nss_wifili_hal_srng_info tcl_ring_info[NSS_WIFILI_MAX_TCL_DATA_RINGS_MSG];
			/**< Transmit Classifier data ring configuration information. */
	struct nss_wifili_hal_srng_info tx_comp_ring[NSS_WIFILI_MAX_TCL_DATA_RINGS_MSG];
			/**< Tx completion ring configuration information. */
	struct nss_wifili_hal_srng_info reo_dest_ring[NSS_WIFILI_MAX_REO_DATA_RINGS_MSG];
			/**< Reorder destination ring configuration information. */
	struct nss_wifili_hal_srng_info reo_exception_ring;
			/**< Reorder exception ring configuration information. */
	struct nss_wifili_hal_srng_info rx_rel_ring;
			/**< WBM (Wireless Buffer manager) release ring configuration information. */
	struct nss_wifili_hal_srng_info reo_reinject_ring;
			/**< Reinject ring configuration information. */
	struct nss_wifili_tx_desc_init_msg wtdim;
			/**< Tx descriptor initialization message. */
};

/**
 * nss_wifili_pdev_deinit_msg
 *	Wifili pdev deinit message.
 */
struct nss_wifili_pdev_deinit_msg {
	uint32_t ifnum;	/**< NSS interface number of pdev. */
};

/**
 * nss_wifili_pdev_init_msg
 *	Wifili pdev initialization message.
 */
struct nss_wifili_pdev_init_msg {
	struct nss_wifili_hal_srng_info rxdma_ring;
			/**< MAC (Media Access Point) ring configuration. */
	uint32_t radio_id;
			/**< MAC radio ID. */
	uint32_t hwmode;
			/**< MAC hardware mode. */
};

/**
 * nss_wifili_peer_msg
 *	Wifili peer creation message.
 */
struct nss_wifili_peer_msg {
	uint8_t peer_mac_addr[6];
			/**< Peer MAC address. */
	uint16_t vdev_id;
			/**< VAP ID. */
	uint16_t peer_id;
			/**< Peer ID. */
	uint16_t hw_ast_idx;
			/**< Hardware address search table index. */
	uint8_t is_nawds;
			/**< NAWDS enabled for peer. */
	uint32_t nss_peer_mem;
			/**< Holds peer memory adderss for NSS. */
};

/**
 * nss_wifili_peer_freelist_append_msg
 *	Peer memory request.
 */
struct nss_wifili_peer_freelist_append_msg {
	uint32_t addr;
			/**< Starting address of peer_freelist pool. */
	uint32_t length;
			/**< Length of peer freelist pool. */
	uint32_t num_peers;
			/**< Maximum number of peer entries supported in pool. */
};

/**
 * nss_wifili_wds_extn_peer_cfg_msg
 *	Configuration information when the WDS vendor extension is enabled.
 */
struct nss_wifili_wds_extn_peer_cfg_msg {
	uint8_t peer_mac_addr[ETH_ALEN];	/**< Peer MAC address. */
	uint8_t wds_flags;			/**< WDS flags populated from the host. */
	uint8_t reserved;			/**< Alignment padding. */
	uint16_t peer_id;			/**< Peer ID. */
};

/**
 * nss_wifili_tx_stats
 *	Tx statistics.
 */
struct nss_wifili_tx_stats {
	uint32_t tx_enqueue_dropped;
			/**< Tx enqueue drop count. */
	uint32_t tx_enqueue_cnt;
			/**< Tx enqueue succesful count. */
	uint32_t tx_dequeue_cnt;
			/**< Tx dequeue count. */
	uint32_t tx_send_fail_cnt;
			/**< Hardware send failure count. */
	uint32_t inv_peer;
			/**< Invalid peer enqueue count. */
	uint32_t inv_peer_drop_byte_cnt;
			/**< Invalid peer drop byte count. */
	uint32_t tx_input_pkt;
			/**< Tx packets ready to sent. */
	uint32_t tx_processed_pkt;
			/**< Tx numner of packets sent. */
	uint32_t tx_processed_bytes;
			/**< Tx number of bytes processed. */

};

/**
 * nss_wifili_rx_stats
 *	Rx statistics.
 */
struct nss_wifili_rx_stats {
	uint32_t rx_msdu_err;
					/**< Rx msdu error count. */
	uint32_t rx_inv_peer;
					/**< Rx invalid peer count. */
	uint32_t rx_scatter_inv_peer;
					/**< Rx scatter invalid peer count. */
	uint32_t rx_wds_learn_send;
					/**< WDS source port learn packet. */
	uint32_t rx_wds_learn_send_fail;
					/**< WDS source port learn exception send failure count. */
	uint32_t rx_send_dropped;
					/**< Rx send dropped count. */
	uint32_t rx_deliver_cnt;
					/**< Rx deliver count to next node. */
	uint32_t rx_deliver_cnt_fail;
					/**< Rx deliver count failure. */
	uint32_t rx_intra_bss_ucast_send;
					/**< Intra-BSS unicast sent count. */
	uint32_t rx_intra_bss_ucast_send_fail;
					/**< Intra-BSS unicast send failure count. */
	uint32_t rx_intra_bss_mcast_send;
					/**< Intra-BSS mcast send count. */
	uint32_t rx_intra_bss_mcast_send_fail;
					/**< Intra-BSS mcast send failure count. */
	uint32_t rx_sg_recv_send;
					/**< Rx scatter-gather receive send count. */
	uint32_t rx_sg_recv_fail;
					/**< Rx scatter-gather receive failure count. */
	uint32_t rx_me_pkts;		/**< Rx multicast echo packets count. */
	uint32_t rx_inv_tid;		/**< Rx invalid TID. */

	/*
	 * TODO: Move per tid based.
	 */
	uint32_t rx_frag_inv_sc;		/**< Rx invalid frame sequence control. */
	uint32_t rx_frag_inv_fc;		/**< Rx invalid frame control count. */
	uint32_t rx_non_frag_err;		/**< Rx non-fragment received in fragmention. */
	uint32_t rx_repeat_fragno;		/**< Rx fragment retry counters. */
	uint32_t rx_ooo_frag;			/**< Rx out-of-order fragments count. */
	uint32_t rx_ooo_frag_seq;		/**< Rx out-of-order sequence count. */
	uint32_t rx_all_frag_rcv;		/**< Rx all fragments received count. */
	uint32_t rx_frag_deliver;		/**< Rx fragment deliver counters. */
};

/**
 * nss_wifili_tx_tcl_ring_stats
 *	Transmit Classifier ring specific statistics.
 */
struct nss_wifili_tx_tcl_ring_stats {
	uint32_t tcl_no_hw_desc;	/**< Number of Transmit Classifier hardware descriptors. */
	uint32_t tcl_ring_full;		/**< Number of times Transmit Classifier ring full. */
	uint32_t tcl_ring_sent;		/**< Total number of ring sent. */
};

/**
 * nss_wifili_tx_comp_ring_stats
 *	Tx completion ring statistics.
 */
struct nss_wifili_tx_comp_ring_stats {
	uint32_t invalid_bufsrc;	/**< Tx comp (Completion) ring descriptor invalid buffer source. */
	uint32_t invalid_cookie;	/**< Tx comletion ring descriptor has invalid cookies. */
	uint32_t hw_ring_empty;		/**< Tx completion hardware ring empty. */
	uint32_t ring_reaped;		/**< Tx completion successfull ring reaped. */

};

/**
 * nss_wifili_tx_sw_pool_stats
 *	Tx completion sw statistics.
 */
struct nss_wifili_tx_sw_pool_stats {
	uint32_t desc_alloc;			/**< Tx descriptor software pool descriptor in use. */
	uint32_t desc_alloc_fail;		/**< Tx descriptor software pool allocation failure . */
	uint32_t desc_already_allocated;	/**< Tx descriptor re-allocation for allocated descriptor. */
	uint32_t desc_invalid_free;		/**< Tx descriptor freeing of allocated descriptor. */
	uint32_t tx_rel_src_fw;			/**< Tx descriptor source is firmware. */
	uint32_t tx_rel_ext_desc;		/**< Tx descriptor scatter-gather. */
	uint32_t tx_rel_tx_desc;		/**< Tx descriptor source is hardware*/
	uint32_t tx_rel_no_pb;			/**< Tx descriptor has pbuf present. */
};

/**
 * wifili_tx_ext_sw_pool_stats
 *	Tx extended descriptor pool.
 */
struct nss_wifili_tx_ext_sw_pool_stats {
	uint32_t desc_alloc;			/**< Tx extend (scatter gather) descriptor in use. */
	uint32_t desc_alloc_fail;		/**< Tx extend descriptor allocation failure. */
	uint32_t desc_already_allocated;	/**< Tx extend descriptor already allocated. */
	uint32_t desc_invalid_free;		/**< Tx descriptor invalid source. */

};

/**
 * nss_wifili_rx_wbm_ring_stats
 *	WBM (Wireless Buffer Manager) release ring statistics.
 */
struct nss_wifili_rx_wbm_ring_stats {
	uint32_t invalid_buf_mgr;		/**< Invalid buffer manager. */
	uint32_t err_src_rxdma;			/**< WBM source is Rx DMA ring. */
	uint32_t err_src_rxdma_code_inv;	/**< WBM source DMA reason unknown. */
	uint32_t err_src_reo;			/**< WBM source is reorder ring. */
	uint32_t err_src_reo_code_nullq;	/**< WBM source reorder ring because of null tlv. */
	uint32_t err_src_reo_code_inv;		/**< WBM source reorder ring reason unknown. */
	uint32_t err_src_invalid;		/**< WBM source is unknown. */
};

/**
 * nss_wifili_rx_reo_ring_stats
 * 	Reorder error statistics.
 */
struct nss_wifili_rx_reo_ring_stats {
	uint32_t ring_error;			/**< Reorder ring error. */
	uint32_t ring_reaped;			/**< Number of ring descriptor reaped. */
	uint32_t invalid_cookie;		/**< Number of invalid cookie. */
	uint32_t defrag_reaped;			/**< Rx defragment receive count. */
};

/**
 * nss_wifili_rx sw_pool_stats
 *	Wifili DMA sw pool statistics.
 */
struct nss_wifili_rx_sw_pool_stats {
	uint32_t rx_no_pb;			/**< Rx software descriptor number of buffer available. */
	uint32_t desc_alloc;			/**< Number of descriptor in use. */
	uint32_t desc_alloc_fail;		/**< Number of descriptor allocation failure. */
};

/**
 * nss_wifili_rx_dma_ring_stats
 *	Wifili Rx DMA ring statistics.
 */
struct nss_wifili_rx_dma_ring_stats {
	uint32_t rx_hw_desc_unavailable;	/**< Number of times hardware descriptor is unavailable. */
	uint32_t rx_buf_replenished;		/**< Number of buffers replenished. */
};

/**
 * nss_wifili_device_stats
 * 	Wifili specific statistics.
 */
struct nss_wifili_device_stats {
	struct nss_wifili_tx_tcl_ring_stats tcl_stats[NSS_WIFILI_MAX_TCL_DATA_RINGS_MSG];
									/**< Transmit Classifier ring statistics. */
	struct nss_wifili_tx_comp_ring_stats txcomp_stats[NSS_WIFILI_MAX_TCL_DATA_RINGS_MSG];
									/**< Tx completion ring stats. */
	struct nss_wifili_tx_sw_pool_stats tx_sw_pool_stats[NSS_WIFILI_MAX_TXDESC_POOLS_MSG];
									/**< Tx software pool statistics. */
	struct nss_wifili_tx_ext_sw_pool_stats tx_ext_sw_pool_stats[NSS_WIFILI_MAX_TX_EXT_DESC_POOLS_MSG];
									/**< Tx extended software pool statistics. */
	struct nss_wifili_tx_stats tx_data_stats[NSS_WIFILI_MAX_PDEV_NUM_MSG];
									/**< Tx data statistics for each pdev. */
	struct nss_wifili_rx_reo_ring_stats rxreo_stats[NSS_WIFILI_MAX_REO_DATA_RINGS_MSG];
									/**< Rx reorder ring statistics. */
	struct nss_wifili_rx_sw_pool_stats rx_sw_pool_stats[NSS_WIFILI_MAX_PDEV_NUM_MSG];
									/**< Rx DMA software pool statistics. */
	struct nss_wifili_rx_stats rx_data_stats[NSS_WIFILI_MAX_PDEV_NUM_MSG];
									/**< Rx data statistics for each pdev. */
	struct nss_wifili_rx_dma_ring_stats rxdma_stats[NSS_WIFILI_MAX_PDEV_NUM_MSG];
									/**< Rx DMA ring statistics. */
	struct nss_wifili_rx_wbm_ring_stats rxwbm_stats;
									/**< WBM ring statistics. */
};

/**
 * nss_wifili_stats_sync_msg
 *	Wifili SoC statistics synchronization message.
 */
struct nss_wifili_stats_sync_msg {
	struct nss_wifili_device_stats stats;
			/**< Device statistics. */
};

/**
 * nss_wifili_soc_linkdesc_per_packet_metadata
 *	Link descriptor per packet metadata.
 */
struct nss_wifili_soc_linkdesc_per_packet_metadata
{
	uint32_t desc_addr;	/**< Link descriptor address. */
};

/**
 * nss_wifili_soc_per_packet_metadata
 *	Per packet special data that has to be sent to host.
 */
struct nss_wifili_soc_per_packet_metadata {
	uint32_t pkt_type;	/**< Packet type. */

	/**
	 *  Link descriptor per packet metadata.
	 */
	union {
		struct nss_wifili_soc_linkdesc_per_packet_metadata linkdesc_metadata;
	} metadata;	/**< Per packet link descriptor metadata. */
};

/**
 * nss_wifili_tx_dropped
 *	Tx peer dropped packets.
 */
struct nss_wifili_tx_dropped {
	uint32_t fw_discard;		/**< Discarded by firmware. */
	uint32_t fw_discard_retired;	/**< Firmware discard retired. */
	uint32_t fw_discard_untransmitted;	/**< Firmware discard untransmitted. */
	uint32_t mpdu_age_out;		/**< Number of PDU aged out. */
};

/**
 * nss_wifili_tx_ctrl_stats
 *	Tx peer statistics.
 */
struct nss_wifili_tx_ctrl_stats {
	uint32_t ofdma; 		/**< Total number of OFDMA packets. */
	uint32_t non_amsdu_cnt; 	/**< Number of MSDUs with no MSDU level aggregation. */
	uint32_t amsdu_cnt;		/**< Number of MSDUs part of AMSDU. */
	struct nss_wifili_tx_dropped dropped;	/**< Tx peer dropped. */
};

/**
 * nss_wifili_peer_rx_err
 *	Rx peer errors.
 */
struct nss_wifili_rx_err {
	uint32_t mic_err;	/**< Rx MIC errors. */
	uint32_t decrypt_err;	/**< Rx Decryption errors. */
};

/**
 * nss_wifili_rx_ctrl_stats
 *	Peer Rx statistics.
 */
struct nss_wifili_rx_ctrl_stats {
	struct nss_wifili_rx_err err;			/**< Rx peer errors. */
	uint32_t reception_type[NSS_WIFILI_SUPPORTED_RECEPTION_TYPES];	/**< Reception type OS packets. */
	uint32_t non_amsdu_cnt;			/**< Number of MSDUs with no MSDU level aggregation. */
	uint32_t amsdu_cnt;			/**< Number of MSDUs part of AMSDU. */
	uint32_t mcast_rcv_cnt;			/**< Total number of multicast packets received. */
	uint32_t mcast_rcv_bytes;		/**< Total number of multicast bytes received. */
	uint32_t rx_recvd;			/**< Total Rx received count. */
	uint32_t rx_recvd_bytes;		/**< Total Rx received count. */
	uint32_t nawds_mcast_drop;		/**< Total NAWDS drop count. */
	uint32_t nawds_mcast_drop_bytes;	/**< Total NAWDS drop count. */
};

/**
 * nss_wifili_peer_ctrl_stats
 *	Wifili peer control statistics.
 */
struct nss_wifili_peer_ctrl_stats {
	uint32_t peer_id;	/**< Peer ID. */
	struct nss_wifili_tx_ctrl_stats tx;
				/**< Peer Tx control statistics. */
	struct nss_wifili_rx_ctrl_stats rx;
				/**< Peer Rx control statistics. */
};

/**
 * nss_wifili peer_stats
 *	Wifili peer statistics.
 */
struct nss_wifili_peer_stats {
	uint32_t npeers;	/**< Number of entries of peer statistics. */
	struct nss_wifili_peer_ctrl_stats wpcs[1];
				/**< Wifili peer control statistics. */
};

/**
 * nss_wifili_peer_stats_msg
 *	Wifili peer statistics message.
 */
struct nss_wifili_peer_stats_msg {
	struct nss_wifili_peer_stats stats;
			/**< Wifili peer statistics. */
};

/**
 * nss_wifili_wds_peer_msg
 *	Wi-Fi Wireless distribution system(WDS) peer-specific message.
 */
struct nss_wifili_wds_peer_msg {
	uint8_t dest_mac[ETH_ALEN];	/**< MAC address of the destination. */
	uint8_t peer_mac[ETH_ALEN];	/**< MAC address of the base peer. */
};

/**
 * nss_wifili_stats_cfg_msg
 *	Wifili stats enable/disable configuration message.
 */
struct nss_wifili_stats_cfg_msg {
	uint32_t cfg;	/**< Enable or disable configuration. */
};

/**
 * nss_wifili_wds_peer_map_msg
 *	Wi-Fi Wireless distribution system(WDS) peer-specific message.
 */
struct nss_wifili_wds_peer_map_msg {
	uint8_t dest_mac[ETH_ALEN];	/**< MAC address of the destination. */
	uint16_t peer_id;		/**< Connected peer ID for this WDS peer. */
	uint16_t ast_idx;		/**< AST (address search table) index for this peer in host. */
	uint8_t reserved[2];		/**< Reserved for 4-byte alignment padding. */
};

/**
 * nss_wifili_wds_active_info
 *	Wi-Fi WDS active information.
 */
struct nss_wifili_wds_active_info {
	uint16_t ast_idx;	/**< Hardware AST index. */
};

/**
 * nss_wifili_wds_active_info_msg
 *	Wi-Fi Wireless distribution system active information message.
 */
struct nss_wifili_wds_active_info_msg {
	uint16_t nentries;		/**< Number of WDS entries. */
	struct nss_wifili_wds_active_info info[1];
					/**< WDS active information. */
};

/**
 * nss_wifili_soc_linkdesc_buf_info_msg
 *	Link descriptor buffer addresss information.
 */
struct nss_wifili_soc_linkdesc_buf_info_msg {
	uint32_t buffer_addr_low;	/**< Link descriptor low address. */
	uint32_t buffer_addr_high;	/**< Link descriptor high address. */
};

/**
 * nss_wifili_peer_security_type_msg
 *	Wifili security type message.
 */
struct nss_wifili_peer_security_type_msg {
	uint16_t peer_id;			/**< Peer ID. */
	uint8_t pkt_type;			/**< Unicast or broadcast packet type. */
	uint8_t security_type;			/**< Security type. */
	uint8_t mic_key[NSS_WIFILI_MIC_KEY_LEN];
						/**< MIC key. */
};

/**
 * nss_wifili_reo_tidq_msg
 *	REO TID queue setup message.
 */
struct nss_wifili_reo_tidq_msg {
	uint32_t tid;		/**< TID (traffic identification) value. */
	uint16_t peer_id;	/**< Peer ID. */
};

/**
 * nss_wifili_radio_cmd_msg
 *	Wi-Fi radio specific special commands.
 */
struct nss_wifili_radio_cmd_msg {
	enum nss_wifili_radio_cmd cmd;
							/**< Type of command message. */
	uint32_t value;			/**< Value of the command. */
};

/**
 * nss_wifili_radio_cfg_msg
 *	Wi-Fi radio specific special configurations.
 */
struct nss_wifili_radio_cfg_msg {
	uint32_t radio_if_num;	/**< NSS assigned interface number for radio. */

	/**
	 * Wi-Fi radio specific special command message.
	 */
	union {
		struct nss_wifili_radio_cmd_msg radiocmdmsg;
							/**< Radio specific commands. */
	} radiomsg;	/**< Wi-Fi radio command message. */
};

/**
 * nss_wifili_msg
 *	Structure that describes wifili messages.
 */
struct nss_wifili_msg {
	struct nss_cmn_msg cm;                  /**< Common message header. */

	/**
	 * Payload of wifili message.
	 */
	union {
		struct nss_wifili_init_msg init;
				/**< Wi-Fi initialization data. */
		struct nss_wifili_pdev_init_msg pdevmsg;
				/**< Tx initialization data. */
		struct nss_wifili_pdev_deinit_msg pdevdeinit;
				/**< Tx de-initialization data. */
		struct nss_wifili_peer_msg peermsg;
				/**< Peer-specific data for the physical device. */
		struct nss_wifili_peer_freelist_append_msg peer_freelist_append;
				/**< Information for creating a peer freelist. */
		struct nss_wifili_stats_sync_msg wlsoc_stats;
				/**< Synchronization statistics. */
		struct nss_wifili_peer_stats_msg peer_stats;
				/**< Wifili peer statistics. */
		struct nss_wifili_wds_peer_msg wdspeermsg;
				/**< WDS peer-specific message. */
		struct nss_wifili_wds_peer_map_msg wdspeermapmsg;
				/**< WDS peer-mapping specific message. */
		struct nss_wifili_wds_active_info_msg wdsinfomsg;
				/**< WDS active information specific message. */
		struct nss_wifili_stats_cfg_msg scm;
				/**< Wifili peer statistics configuration message. */
		struct nss_wifili_reo_tidq_msg reotidqmsg;
				/**< REO TID queue setup message. */
		struct nss_wifili_radio_cfg_msg radiocfgmsg;
				/**< Radio command message. */
		struct nss_wifili_wds_extn_peer_cfg_msg wpeercfg;
				/**< WDS vendor configuration message. */
		struct nss_wifili_soc_linkdesc_buf_info_msg linkdescinfomsg;
				/**< Link descriptor buffer address information. */
		struct nss_wifili_peer_security_type_msg securitymsg;
				/**< Wifili peer security message. */
	} msg;
};

/**
 * nss_wifili_tx_msg
 *	Send wifili messages.
 *
 * @datatypes
 * nss_ctx_instance \n
 * nss_wifili_msg
 *
 * @param[in] nss_ctx NSS context.
 * @param[in] msg     NSS Wi-Fi message.
 *
 * @return
 * nss_tx_status_t Tx status
 */
extern nss_tx_status_t nss_wifili_tx_msg(struct nss_ctx_instance *nss_ctx, struct nss_wifili_msg *msg);

/**
 * nss_wifili_msg_callback_t
 *	Callback to receive wifili messages.
 *
 * @datatypes
 * nss_wifili_msg
 *
 * @param[in] app_data Application context of the message.
 * @param[in] msg      Message data.
 *
 * @return
 * void
 */
typedef void (*nss_wifili_msg_callback_t)(void *app_data, struct nss_wifili_msg *msg);

/**
 * nss_wifili_callback_t
 *	Callback to receive Wi-Fi data.
 *
 * @datatypes
 * net_device \n
 * sk_buff \n
 * napi_struct
 *
 *
 * @param[in] netdev  Pointer to the associated network device.
 * @param[in] skb     Pointer to the data socket buffer.
 * @param[in] napi    Pointer to the NAPI structure.
 *
 * @return
 * void
 */
typedef void (*nss_wifili_callback_t)(struct net_device *netdev, struct sk_buff *skb, struct napi_struct *napi);

/**
 * nss_register_wifili_if
 *	Register to send/receive wifili SoC messages to NSS.
 *
 * @datatypes
 * nss_wifili_callback_t \n
 * nss_wifili_msg_callback_t \n
 * net_device
 *
 * @param[in] if_num             NSS interface number.
 * @param[in] wifi_callback      Callback for the Wi-Fi virtual device data.
 * @param[in] wifi_ext_callback  Callback for the extended data.
 * @param[in] event_callback     Callback for the message.
 * @param[in] netdev             Pointer to the associated network device.
 * @param[in] features           Data socket buffer types supported by this
 *                               interface.
 *
 * @return
 * nss_ctx_instance* NSS context
 */
struct nss_ctx_instance *nss_register_wifili_if(uint32_t if_num, nss_wifili_callback_t wifi_callback,
			nss_wifili_callback_t wifi_ext_callback, nss_wifili_msg_callback_t event_callback, struct net_device *netdev, uint32_t features);

/**
 * nss_unregister_wifili_if
 *	Deregister wifili SoC interface with NSS.
 *
 * @param[in] if_num NSS interface number
 *
 * @return
 * void
 */
void nss_unregister_wifili_if(uint32_t if_num);

/**
 * nss_register_wifili_radio_if
 *	Register to send/receive wifili radio messages to NSS.
 *
 * @datatypes
 * nss_wifili_callback_t \n
 * nss_wifili_msg_callback_t \n
 * net_device
 *
 * @param[in] if_num             NSS interface number.
 * @param[in] wifi_callback      Callback for the Wi-Fi radio virtual device data.
 * @param[in] wifi_ext_callback  Callback for the extended data.
 * @param[in] event_callback     Callback for the message.
 * @param[in] netdev             Pointer to the associated network device.
 * @param[in] features           Data socket buffer types supported by this
 *                               interface.
 *
 * @return
 * nss_ctx_instance* NSS context
 */
struct nss_ctx_instance *nss_register_wifili_radio_if(uint32_t if_num, nss_wifili_callback_t wifi_callback,
			nss_wifili_callback_t wifi_ext_callback, nss_wifili_msg_callback_t event_callback, struct net_device *netdev, uint32_t features);

/**
 * nss_unregister_wifili_radio_if
 *	Deregister wifili radio interface with NSS.
 *
 * @param[in] if_num NSS interface number
 *
 * @return
 * void
 */
void nss_unregister_wifili_radio_if(uint32_t if_num);

/**
  * @}
  */

#endif /* __NSS_WIFILI_H */
