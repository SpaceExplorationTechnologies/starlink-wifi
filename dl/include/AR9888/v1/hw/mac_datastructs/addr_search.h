// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _ADDR_SEARCH_H_
#define _ADDR_SEARCH_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	mac_addr_31_0[31:0]
//	1	mac_addr_47_32[15:0], key_id[17:16], mcast[18], next_hop[19], no_ack[20], reserved[30:21], valid[31]
//	2	peer_ptr[31:0]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_ADDR_SEARCH 3

struct addr_search {
    volatile uint32_t mac_addr_31_0                   : 32; //[31:0]
    volatile uint32_t mac_addr_47_32                  : 16, //[15:0]
                      key_id                          :  2, //[17:16]
                      mcast                           :  1, //[18]
                      next_hop                        :  1, //[19]
                      no_ack                          :  1, //[20]
                      reserved                        : 10, //[30:21]
                      valid                           :  1; //[31]
    volatile uint32_t peer_ptr                        : 32; //[31:0]
};

/*

mac_addr_31_0
			Lower 32 bits of the MAC address of the peer station.

mac_addr_47_32
			Upper 16 bits of the MAC address of the peer station.

key_id
			The key ID field from the IV

mcast
			If set indicates that this is a entry to associated with a
			multicast key

next_hop
			If set indicates that this STA is not attached directly but
			can be reached by forwarding to the next hop entry (not used
			by HW but forwarded via descriptor status for SW/FW).

no_ack
			If set indicates that Ack/BA should not be transmitted on
			receive of a packet from this STA.  A configuration mode
			register needs to also be set to enable this feature.

reserved
			Reserved: Not used by HW.

valid
			Indicates that this entry is valid.  FW should disable the
			address search engines and flush their caches if entries are
			being modified.

peer_ptr
			Pointer to the associated peer table entry
*/


/* Description		ADDR_SEARCH_0_MAC_ADDR_31_0
			Lower 32 bits of the MAC address of the peer station.
*/
#define ADDR_SEARCH_0_MAC_ADDR_31_0_OFFSET                           0x00000000
#define ADDR_SEARCH_0_MAC_ADDR_31_0_LSB                              0
#define ADDR_SEARCH_0_MAC_ADDR_31_0_MASK                             0xffffffff

/* Description		ADDR_SEARCH_1_MAC_ADDR_47_32
			Upper 16 bits of the MAC address of the peer station.
*/
#define ADDR_SEARCH_1_MAC_ADDR_47_32_OFFSET                          0x00000004
#define ADDR_SEARCH_1_MAC_ADDR_47_32_LSB                             0
#define ADDR_SEARCH_1_MAC_ADDR_47_32_MASK                            0x0000ffff

/* Description		ADDR_SEARCH_1_KEY_ID
			The key ID field from the IV
*/
#define ADDR_SEARCH_1_KEY_ID_OFFSET                                  0x00000004
#define ADDR_SEARCH_1_KEY_ID_LSB                                     16
#define ADDR_SEARCH_1_KEY_ID_MASK                                    0x00030000

/* Description		ADDR_SEARCH_1_MCAST
			If set indicates that this is a entry to associated with a
			multicast key
*/
#define ADDR_SEARCH_1_MCAST_OFFSET                                   0x00000004
#define ADDR_SEARCH_1_MCAST_LSB                                      18
#define ADDR_SEARCH_1_MCAST_MASK                                     0x00040000

/* Description		ADDR_SEARCH_1_NEXT_HOP
			If set indicates that this STA is not attached directly but
			can be reached by forwarding to the next hop entry (not used
			by HW but forwarded via descriptor status for SW/FW).
*/
#define ADDR_SEARCH_1_NEXT_HOP_OFFSET                                0x00000004
#define ADDR_SEARCH_1_NEXT_HOP_LSB                                   19
#define ADDR_SEARCH_1_NEXT_HOP_MASK                                  0x00080000

/* Description		ADDR_SEARCH_1_NO_ACK
			If set indicates that Ack/BA should not be transmitted on
			receive of a packet from this STA.  A configuration mode
			register needs to also be set to enable this feature.
*/
#define ADDR_SEARCH_1_NO_ACK_OFFSET                                  0x00000004
#define ADDR_SEARCH_1_NO_ACK_LSB                                     20
#define ADDR_SEARCH_1_NO_ACK_MASK                                    0x00100000

/* Description		ADDR_SEARCH_1_RESERVED
			Reserved: Not used by HW.
*/
#define ADDR_SEARCH_1_RESERVED_OFFSET                                0x00000004
#define ADDR_SEARCH_1_RESERVED_LSB                                   21
#define ADDR_SEARCH_1_RESERVED_MASK                                  0x7fe00000

/* Description		ADDR_SEARCH_1_VALID
			Indicates that this entry is valid.  FW should disable the
			address search engines and flush their caches if entries are
			being modified.
*/
#define ADDR_SEARCH_1_VALID_OFFSET                                   0x00000004
#define ADDR_SEARCH_1_VALID_LSB                                      31
#define ADDR_SEARCH_1_VALID_MASK                                     0x80000000

/* Description		ADDR_SEARCH_2_PEER_PTR
			Pointer to the associated peer table entry
*/
#define ADDR_SEARCH_2_PEER_PTR_OFFSET                                0x00000008
#define ADDR_SEARCH_2_PEER_PTR_LSB                                   0
#define ADDR_SEARCH_2_PEER_PTR_MASK                                  0xffffffff


#endif // _ADDR_SEARCH_H_
