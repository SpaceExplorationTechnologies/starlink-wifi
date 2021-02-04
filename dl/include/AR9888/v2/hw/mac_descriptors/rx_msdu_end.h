// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _RX_MSDU_END_H_
#define _RX_MSDU_END_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	ip_hdr_chksum[15:0], tcp_udp_chksum[31:16]
//	1	key_id_octet[7:0], classification_filter[15:8], ext_wapi_pn_63_48[31:16]
//	2	ext_wapi_pn_95_64[31:0]
//	3	ext_wapi_pn_127_96[31:0]
//	4	reported_mpdu_length[13:0], first_msdu[14], last_msdu[15], reserved_3a[29:16], pre_delim_err[30], reserved_3b[31]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RX_MSDU_END 5

struct rx_msdu_end {
    volatile uint32_t ip_hdr_chksum                   : 16, //[15:0]
                      tcp_udp_chksum                  : 16; //[31:16]
    volatile uint32_t key_id_octet                    :  8, //[7:0]
                      classification_filter           :  8, //[15:8]
                      ext_wapi_pn_63_48               : 16; //[31:16]
    volatile uint32_t ext_wapi_pn_95_64               : 32; //[31:0]
    volatile uint32_t ext_wapi_pn_127_96              : 32; //[31:0]
    volatile uint32_t reported_mpdu_length            : 14, //[13:0]
                      first_msdu                      :  1, //[14]
                      last_msdu                       :  1, //[15]
                      reserved_3a                     : 14, //[29:16]
                      pre_delim_err                   :  1, //[30]
                      reserved_3b                     :  1; //[31]
};

/*

ip_hdr_chksum
			This can include the IP header checksum or the pseudo header
			checksum used by TCP/UDP checksum.

tcp_udp_chksum
			The value of the computed TCP/UDP checksum.  A mode bit
			selects whether this checksum is the full checksum or the
			partial checksum which does not include the pseudo header. 

key_id_octet
			The key ID octet from the IV.  Only valid when first_msdu is
			set.

classification_filter
			Indicates the number classification filter rule 

ext_wapi_pn_63_48
			Extension PN (packet number) which is only used by WAPI. 
			This corresponds to WAPI PN bits [63:48] (pn6 and pn7).  The
			WAPI PN bits [63:0] are in the pn field of the rx_mpdu_start
			descriptor.

ext_wapi_pn_95_64
			Extension PN (packet number) which is only used by WAPI. 
			This corresponds to WAPI PN bits [95:64] (pn8, pn9, pn10 and
			pn11).

ext_wapi_pn_127_96
			Extension PN (packet number) which is only used by WAPI. 
			This corresponds to WAPI PN bits [127:96] (pn12, pn13, pn14,
			pn15).

reported_mpdu_length
			MPDU length before decapsulation.  Only valid when
			first_msdu is set.  This field is taken directly from the
			length field of the A-MPDU delimiter or the preamble length
			field for non-A-MPDU frames.

first_msdu
			Indicates the first MSDU of A-MSDU.  If both first_msdu and
			last_msdu are set in the MSDU then this is a non-aggregated
			MSDU frame: normal MPDU.  Interior MSDU in an A-MSDU shall
			have both first_mpdu and last_mpdu bits set to 0.

last_msdu
			Indicates the last MSDU of the A-MSDU.  MPDU end status is
			only valid when last_msdu is set.

reserved_3a
			Reserved: HW should fill with zero.  FW should ignore.

pre_delim_err
			Indicates that the first delimiter had a FCS failure.  Only
			valid when first_mpdu and first_msdu are set.

reserved_3b
			Reserved: HW should fill with zero.  FW should ignore.
*/


/* Description		RX_MSDU_END_0_IP_HDR_CHKSUM
			This can include the IP header checksum or the pseudo header
			checksum used by TCP/UDP checksum.
*/
#define RX_MSDU_END_0_IP_HDR_CHKSUM_OFFSET                           0x00000000
#define RX_MSDU_END_0_IP_HDR_CHKSUM_LSB                              0
#define RX_MSDU_END_0_IP_HDR_CHKSUM_MASK                             0x0000ffff

/* Description		RX_MSDU_END_0_TCP_UDP_CHKSUM
			The value of the computed TCP/UDP checksum.  A mode bit
			selects whether this checksum is the full checksum or the
			partial checksum which does not include the pseudo header. 
*/
#define RX_MSDU_END_0_TCP_UDP_CHKSUM_OFFSET                          0x00000000
#define RX_MSDU_END_0_TCP_UDP_CHKSUM_LSB                             16
#define RX_MSDU_END_0_TCP_UDP_CHKSUM_MASK                            0xffff0000

/* Description		RX_MSDU_END_1_KEY_ID_OCTET
			The key ID octet from the IV.  Only valid when first_msdu is
			set.
*/
#define RX_MSDU_END_1_KEY_ID_OCTET_OFFSET                            0x00000004
#define RX_MSDU_END_1_KEY_ID_OCTET_LSB                               0
#define RX_MSDU_END_1_KEY_ID_OCTET_MASK                              0x000000ff

/* Description		RX_MSDU_END_1_CLASSIFICATION_FILTER
			Indicates the number classification filter rule 
*/
#define RX_MSDU_END_1_CLASSIFICATION_FILTER_OFFSET                   0x00000004
#define RX_MSDU_END_1_CLASSIFICATION_FILTER_LSB                      8
#define RX_MSDU_END_1_CLASSIFICATION_FILTER_MASK                     0x0000ff00

/* Description		RX_MSDU_END_1_EXT_WAPI_PN_63_48
			Extension PN (packet number) which is only used by WAPI. 
			This corresponds to WAPI PN bits [63:48] (pn6 and pn7).  The
			WAPI PN bits [63:0] are in the pn field of the rx_mpdu_start
			descriptor.
*/
#define RX_MSDU_END_1_EXT_WAPI_PN_63_48_OFFSET                       0x00000004
#define RX_MSDU_END_1_EXT_WAPI_PN_63_48_LSB                          16
#define RX_MSDU_END_1_EXT_WAPI_PN_63_48_MASK                         0xffff0000

/* Description		RX_MSDU_END_2_EXT_WAPI_PN_95_64
			Extension PN (packet number) which is only used by WAPI. 
			This corresponds to WAPI PN bits [95:64] (pn8, pn9, pn10 and
			pn11).
*/
#define RX_MSDU_END_2_EXT_WAPI_PN_95_64_OFFSET                       0x00000008
#define RX_MSDU_END_2_EXT_WAPI_PN_95_64_LSB                          0
#define RX_MSDU_END_2_EXT_WAPI_PN_95_64_MASK                         0xffffffff

/* Description		RX_MSDU_END_3_EXT_WAPI_PN_127_96
			Extension PN (packet number) which is only used by WAPI. 
			This corresponds to WAPI PN bits [127:96] (pn12, pn13, pn14,
			pn15).
*/
#define RX_MSDU_END_3_EXT_WAPI_PN_127_96_OFFSET                      0x0000000c
#define RX_MSDU_END_3_EXT_WAPI_PN_127_96_LSB                         0
#define RX_MSDU_END_3_EXT_WAPI_PN_127_96_MASK                        0xffffffff

/* Description		RX_MSDU_END_4_REPORTED_MPDU_LENGTH
			MPDU length before decapsulation.  Only valid when
			first_msdu is set.  This field is taken directly from the
			length field of the A-MPDU delimiter or the preamble length
			field for non-A-MPDU frames.
*/
#define RX_MSDU_END_4_REPORTED_MPDU_LENGTH_OFFSET                    0x00000010
#define RX_MSDU_END_4_REPORTED_MPDU_LENGTH_LSB                       0
#define RX_MSDU_END_4_REPORTED_MPDU_LENGTH_MASK                      0x00003fff

/* Description		RX_MSDU_END_4_FIRST_MSDU
			Indicates the first MSDU of A-MSDU.  If both first_msdu and
			last_msdu are set in the MSDU then this is a non-aggregated
			MSDU frame: normal MPDU.  Interior MSDU in an A-MSDU shall
			have both first_mpdu and last_mpdu bits set to 0.
*/
#define RX_MSDU_END_4_FIRST_MSDU_OFFSET                              0x00000010
#define RX_MSDU_END_4_FIRST_MSDU_LSB                                 14
#define RX_MSDU_END_4_FIRST_MSDU_MASK                                0x00004000

/* Description		RX_MSDU_END_4_LAST_MSDU
			Indicates the last MSDU of the A-MSDU.  MPDU end status is
			only valid when last_msdu is set.
*/
#define RX_MSDU_END_4_LAST_MSDU_OFFSET                               0x00000010
#define RX_MSDU_END_4_LAST_MSDU_LSB                                  15
#define RX_MSDU_END_4_LAST_MSDU_MASK                                 0x00008000

/* Description		RX_MSDU_END_4_RESERVED_3A
			Reserved: HW should fill with zero.  FW should ignore.
*/
#define RX_MSDU_END_4_RESERVED_3A_OFFSET                             0x00000010
#define RX_MSDU_END_4_RESERVED_3A_LSB                                16
#define RX_MSDU_END_4_RESERVED_3A_MASK                               0x3fff0000

/* Description		RX_MSDU_END_4_PRE_DELIM_ERR
			Indicates that the first delimiter had a FCS failure.  Only
			valid when first_mpdu and first_msdu are set.
*/
#define RX_MSDU_END_4_PRE_DELIM_ERR_OFFSET                           0x00000010
#define RX_MSDU_END_4_PRE_DELIM_ERR_LSB                              30
#define RX_MSDU_END_4_PRE_DELIM_ERR_MASK                             0x40000000

/* Description		RX_MSDU_END_4_RESERVED_3B
			Reserved: HW should fill with zero.  FW should ignore.
*/
#define RX_MSDU_END_4_RESERVED_3B_OFFSET                             0x00000010
#define RX_MSDU_END_4_RESERVED_3B_LSB                                31
#define RX_MSDU_END_4_RESERVED_3B_MASK                               0x80000000


#endif // _RX_MSDU_END_H_
