// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _RX_MPDU_START_H_
#define _RX_MPDU_START_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	peer_idx[10:0], fr_ds[11], to_ds[12], encrypted[13], retry[14], txbf_h_info[15], seq_num[27:16], encrypt_type[31:28]
//	1	pn_31_0[31:0]
//	2	pn_47_32[15:0], directed[16], reserved_2[27:17], tid[31:28]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RX_MPDU_START 3

struct rx_mpdu_start {
    volatile uint32_t peer_idx                        : 11, //[10:0]
                      fr_ds                           :  1, //[11]
                      to_ds                           :  1, //[12]
                      encrypted                       :  1, //[13]
                      retry                           :  1, //[14]
                      txbf_h_info                     :  1, //[15]
                      seq_num                         : 12, //[27:16]
                      encrypt_type                    :  4; //[31:28]
    volatile uint32_t pn_31_0                         : 32; //[31:0]
    volatile uint32_t pn_47_32                        : 16, //[15:0]
                      directed                        :  1, //[16]
                      reserved_2                      : 11, //[27:17]
                      tid                             :  4; //[31:28]
};

/*

peer_idx
			The index of the address search table which associated with
			the peer table entry corresponding to this MPDU.  Only valid
			when first_msdu is set.

fr_ds
			Set if the from DS bit is set in the frame control.  Only
			valid when first_msdu is set.

to_ds
			Set if the to DS bit is set in the frame control.  Only
			valid when first_msdu is set.

encrypted
			Protected bit from the frame control.  Only valid when
			first_msdu is set.

retry
			Retry bit from the frame control.  Only valid when
			first_msdu is set.

txbf_h_info
			The MPDU data will contain H information.  Primarily used
			for debug.

seq_num
			The sequence number from the 802.11 header.  Only valid when
			first_msdu is set.

encrypt_type
			Indicates type of decrypt cipher used (as defined in the
			peer table)
			0: WEP40
			1: WEP104
			2: TKIP without MIC
			3: WEP128
			4: TKIP (WPA)
			5: WAPI
			6: AES-CCM (WPA2)
			7: No cipher
			Only valid when first_msdu_is set

pn_31_0
			Bits [31:0] of the PN number extracted from the IV field
			WEP: IV = {key_id_octet, pn2, pn1, pn0}.  Only pn[23:0] is
				valid.
			TKIP: IV = {pn5, pn4, pn3, pn2, key_id_octet, pn0,
				WEPSeed[1], pn1}.  Only pn[47:0] is valid.
			AES-CCM: IV = {pn5, pn4, pn3, pn2, key_id_octet, 0x0, pn1,
				pn0}.  Only pn[47:0] is valid.
			WAPI: IV = {key_id_octet, 0x0, pn15, pn14, pn13, pn12, pn11,
				pn10, pn9, pn8, pn7, pn6, pn5, pn4, pn3, pn2, pn1, pn0}. 
				The ext_wapi_pn[127:48] in the rx_msdu_misc descriptor and
				pn[47:0] are valid.
			Only valid when first_msdu is set.

pn_47_32
			Bits [47:32] of the PN number.   See description for
			pn_31_0.  The remaining PN fields are in the rx_msdu_end
			descriptor

directed
			See definition in RX attention descriptor

reserved_2
			Reserved: HW should fill with zero.  FW should ignore.

tid
			The TID field in the QoS control field
*/


/* Description		RX_MPDU_START_0_PEER_IDX
			The index of the address search table which associated with
			the peer table entry corresponding to this MPDU.  Only valid
			when first_msdu is set.
*/
#define RX_MPDU_START_0_PEER_IDX_OFFSET                              0x00000000
#define RX_MPDU_START_0_PEER_IDX_LSB                                 0
#define RX_MPDU_START_0_PEER_IDX_MASK                                0x000007ff

/* Description		RX_MPDU_START_0_FR_DS
			Set if the from DS bit is set in the frame control.  Only
			valid when first_msdu is set.
*/
#define RX_MPDU_START_0_FR_DS_OFFSET                                 0x00000000
#define RX_MPDU_START_0_FR_DS_LSB                                    11
#define RX_MPDU_START_0_FR_DS_MASK                                   0x00000800

/* Description		RX_MPDU_START_0_TO_DS
			Set if the to DS bit is set in the frame control.  Only
			valid when first_msdu is set.
*/
#define RX_MPDU_START_0_TO_DS_OFFSET                                 0x00000000
#define RX_MPDU_START_0_TO_DS_LSB                                    12
#define RX_MPDU_START_0_TO_DS_MASK                                   0x00001000

/* Description		RX_MPDU_START_0_ENCRYPTED
			Protected bit from the frame control.  Only valid when
			first_msdu is set.
*/
#define RX_MPDU_START_0_ENCRYPTED_OFFSET                             0x00000000
#define RX_MPDU_START_0_ENCRYPTED_LSB                                13
#define RX_MPDU_START_0_ENCRYPTED_MASK                               0x00002000

/* Description		RX_MPDU_START_0_RETRY
			Retry bit from the frame control.  Only valid when
			first_msdu is set.
*/
#define RX_MPDU_START_0_RETRY_OFFSET                                 0x00000000
#define RX_MPDU_START_0_RETRY_LSB                                    14
#define RX_MPDU_START_0_RETRY_MASK                                   0x00004000

/* Description		RX_MPDU_START_0_TXBF_H_INFO
			The MPDU data will contain H information.  Primarily used
			for debug.
*/
#define RX_MPDU_START_0_TXBF_H_INFO_OFFSET                           0x00000000
#define RX_MPDU_START_0_TXBF_H_INFO_LSB                              15
#define RX_MPDU_START_0_TXBF_H_INFO_MASK                             0x00008000

/* Description		RX_MPDU_START_0_SEQ_NUM
			The sequence number from the 802.11 header.  Only valid when
			first_msdu is set.
*/
#define RX_MPDU_START_0_SEQ_NUM_OFFSET                               0x00000000
#define RX_MPDU_START_0_SEQ_NUM_LSB                                  16
#define RX_MPDU_START_0_SEQ_NUM_MASK                                 0x0fff0000

/* Description		RX_MPDU_START_0_ENCRYPT_TYPE
			Indicates type of decrypt cipher used (as defined in the
			peer table)
			0: WEP40
			1: WEP104
			2: TKIP without MIC
			3: WEP128
			4: TKIP (WPA)
			5: WAPI
			6: AES-CCM (WPA2)
			7: No cipher
			Only valid when first_msdu_is set
*/
#define RX_MPDU_START_0_ENCRYPT_TYPE_OFFSET                          0x00000000
#define RX_MPDU_START_0_ENCRYPT_TYPE_LSB                             28
#define RX_MPDU_START_0_ENCRYPT_TYPE_MASK                            0xf0000000

/* Description		RX_MPDU_START_1_PN_31_0
			Bits [31:0] of the PN number extracted from the IV field
			WEP: IV = {key_id_octet, pn2, pn1, pn0}.  Only pn[23:0] is
				valid.
			TKIP: IV = {pn5, pn4, pn3, pn2, key_id_octet, pn0,
				WEPSeed[1], pn1}.  Only pn[47:0] is valid.
			AES-CCM: IV = {pn5, pn4, pn3, pn2, key_id_octet, 0x0, pn1,
				pn0}.  Only pn[47:0] is valid.
			WAPI: IV = {key_id_octet, 0x0, pn15, pn14, pn13, pn12, pn11,
				pn10, pn9, pn8, pn7, pn6, pn5, pn4, pn3, pn2, pn1, pn0}. 
				The ext_wapi_pn[127:48] in the rx_msdu_misc descriptor and
				pn[47:0] are valid.
			Only valid when first_msdu is set.
*/
#define RX_MPDU_START_1_PN_31_0_OFFSET                               0x00000004
#define RX_MPDU_START_1_PN_31_0_LSB                                  0
#define RX_MPDU_START_1_PN_31_0_MASK                                 0xffffffff

/* Description		RX_MPDU_START_2_PN_47_32
			Bits [47:32] of the PN number.   See description for
			pn_31_0.  The remaining PN fields are in the rx_msdu_end
			descriptor
*/
#define RX_MPDU_START_2_PN_47_32_OFFSET                              0x00000008
#define RX_MPDU_START_2_PN_47_32_LSB                                 0
#define RX_MPDU_START_2_PN_47_32_MASK                                0x0000ffff

/* Description		RX_MPDU_START_2_DIRECTED
			See definition in RX attention descriptor
*/
#define RX_MPDU_START_2_DIRECTED_OFFSET                              0x00000008
#define RX_MPDU_START_2_DIRECTED_LSB                                 16
#define RX_MPDU_START_2_DIRECTED_MASK                                0x00010000

/* Description		RX_MPDU_START_2_RESERVED_2
			Reserved: HW should fill with zero.  FW should ignore.
*/
#define RX_MPDU_START_2_RESERVED_2_OFFSET                            0x00000008
#define RX_MPDU_START_2_RESERVED_2_LSB                               17
#define RX_MPDU_START_2_RESERVED_2_MASK                              0x0ffe0000

/* Description		RX_MPDU_START_2_TID
			The TID field in the QoS control field
*/
#define RX_MPDU_START_2_TID_OFFSET                                   0x00000008
#define RX_MPDU_START_2_TID_LSB                                      28
#define RX_MPDU_START_2_TID_MASK                                     0xf0000000


#endif // _RX_MPDU_START_H_
