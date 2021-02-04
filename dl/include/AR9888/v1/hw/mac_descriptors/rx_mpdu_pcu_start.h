// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _RX_MPDU_PCU_START_H_
#define _RX_MPDU_PCU_START_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	peer_idx[10:0], fr_ds[11], to_ds[12], encrypted[13], retry[14], txbf_h_info[15], seq_num[27:16], encrypt_type[31:28]
//	1	pn_31_0[31:0]
//	2	pn_63_32[31:0]
//	3	pn_95_64[31:0]
//	4	pn_127_96[31:0]
//	5	key_id_octet[7:0], pre_delim_err[8], reserved_5[27:9], tid[31:28]
//	6	mpdu_length[13:0], first_mpdu[14], mcast_bcast[15], peer_idx_not_found[16], peer_idx_timeout[17], power_mgmt[18], non_qos[19], null_data[20], mgmt_type[21], ctrl_type[22], more_data[23], eosp[24], fragment[25], order[26], u_apsd_trigger[27], encrypt_required[28], directed[29], reserved_6[31:30]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RX_MPDU_PCU_START 7

struct rx_mpdu_pcu_start {
    volatile uint32_t peer_idx                        : 11, //[10:0]
                      fr_ds                           :  1, //[11]
                      to_ds                           :  1, //[12]
                      encrypted                       :  1, //[13]
                      retry                           :  1, //[14]
                      txbf_h_info                     :  1, //[15]
                      seq_num                         : 12, //[27:16]
                      encrypt_type                    :  4; //[31:28]
    volatile uint32_t pn_31_0                         : 32; //[31:0]
    volatile uint32_t pn_63_32                        : 32; //[31:0]
    volatile uint32_t pn_95_64                        : 32; //[31:0]
    volatile uint32_t pn_127_96                       : 32; //[31:0]
    volatile uint32_t key_id_octet                    :  8, //[7:0]
                      pre_delim_err                   :  1, //[8]
                      reserved_5                      : 19, //[27:9]
                      tid                             :  4; //[31:28]
    volatile uint32_t mpdu_length                     : 14, //[13:0]
                      first_mpdu                      :  1, //[14]
                      mcast_bcast                     :  1, //[15]
                      peer_idx_not_found              :  1, //[16]
                      peer_idx_timeout                :  1, //[17]
                      power_mgmt                      :  1, //[18]
                      non_qos                         :  1, //[19]
                      null_data                       :  1, //[20]
                      mgmt_type                       :  1, //[21]
                      ctrl_type                       :  1, //[22]
                      more_data                       :  1, //[23]
                      eosp                            :  1, //[24]
                      fragment                        :  1, //[25]
                      order                           :  1, //[26]
                      u_apsd_trigger                  :  1, //[27]
                      encrypt_required                :  1, //[28]
                      directed                        :  1, //[29]
                      reserved_6                      :  2; //[31:30]
};

/*

peer_idx
			The peer index indicates the index of the AST entry
			corresponding to this MPDU.

fr_ds
			Set if the from DS bit is set in the frame control.

to_ds
			Set if the to DS bit is set in the frame control.

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
			The sequence number from the 802.11 header.

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
				pn[127:0] are valid.

pn_63_32
			Bits [63:32] of the PN number.   See description for
			pn_31_0.

pn_95_64
			

pn_127_96
			Bits [127:96] of the PN number.  See description for
			pn_31_0.

key_id_octet
			The key ID octet from the IV.

pre_delim_err
			Indicates that the first delimiter had a FCS failure.  Only
			valid when first_mpdu and first_msdu are set.

reserved_5
			Reserved: HW should fill with zero.  FW should ignore.

tid
			The TID field in the QoS control field

mpdu_length
			MPDU length before decapsulation.

first_mpdu
			See definition in RX attention descriptor

mcast_bcast
			See definition in RX attention descriptor

peer_idx_not_found
			See definition in RX attention descriptor

peer_idx_timeout
			See definition in RX attention descriptor

power_mgmt
			See definition in RX attention descriptor

non_qos
			See definition in RX attention descriptor

null_data
			See definition in RX attention descriptor

mgmt_type
			See definition in RX attention descriptor

ctrl_type
			See definition in RX attention descriptor

more_data
			See definition in RX attention descriptor

eosp
			See definition in RX attention descriptor

fragment
			See definition in RX attention descriptor

order
			See definition in RX attention descriptor

u_apsd_trigger
			See definition in RX attention descriptor

encrypt_required
			See definition in RX attention descriptor

directed
			See definition in RX attention descriptor

reserved_6
			Reserved: HW should fill with zero.  FW should ignore.
*/


/* Description		RX_MPDU_PCU_START_0_PEER_IDX
			The peer index indicates the index of the AST entry
			corresponding to this MPDU.
*/
#define RX_MPDU_PCU_START_0_PEER_IDX_OFFSET                          0x00000000
#define RX_MPDU_PCU_START_0_PEER_IDX_LSB                             0
#define RX_MPDU_PCU_START_0_PEER_IDX_MASK                            0x000007ff

/* Description		RX_MPDU_PCU_START_0_FR_DS
			Set if the from DS bit is set in the frame control.
*/
#define RX_MPDU_PCU_START_0_FR_DS_OFFSET                             0x00000000
#define RX_MPDU_PCU_START_0_FR_DS_LSB                                11
#define RX_MPDU_PCU_START_0_FR_DS_MASK                               0x00000800

/* Description		RX_MPDU_PCU_START_0_TO_DS
			Set if the to DS bit is set in the frame control.
*/
#define RX_MPDU_PCU_START_0_TO_DS_OFFSET                             0x00000000
#define RX_MPDU_PCU_START_0_TO_DS_LSB                                12
#define RX_MPDU_PCU_START_0_TO_DS_MASK                               0x00001000

/* Description		RX_MPDU_PCU_START_0_ENCRYPTED
			Protected bit from the frame control.  Only valid when
			first_msdu is set.
*/
#define RX_MPDU_PCU_START_0_ENCRYPTED_OFFSET                         0x00000000
#define RX_MPDU_PCU_START_0_ENCRYPTED_LSB                            13
#define RX_MPDU_PCU_START_0_ENCRYPTED_MASK                           0x00002000

/* Description		RX_MPDU_PCU_START_0_RETRY
			Retry bit from the frame control.  Only valid when
			first_msdu is set.
*/
#define RX_MPDU_PCU_START_0_RETRY_OFFSET                             0x00000000
#define RX_MPDU_PCU_START_0_RETRY_LSB                                14
#define RX_MPDU_PCU_START_0_RETRY_MASK                               0x00004000

/* Description		RX_MPDU_PCU_START_0_TXBF_H_INFO
			The MPDU data will contain H information.  Primarily used
			for debug.
*/
#define RX_MPDU_PCU_START_0_TXBF_H_INFO_OFFSET                       0x00000000
#define RX_MPDU_PCU_START_0_TXBF_H_INFO_LSB                          15
#define RX_MPDU_PCU_START_0_TXBF_H_INFO_MASK                         0x00008000

/* Description		RX_MPDU_PCU_START_0_SEQ_NUM
			The sequence number from the 802.11 header.
*/
#define RX_MPDU_PCU_START_0_SEQ_NUM_OFFSET                           0x00000000
#define RX_MPDU_PCU_START_0_SEQ_NUM_LSB                              16
#define RX_MPDU_PCU_START_0_SEQ_NUM_MASK                             0x0fff0000

/* Description		RX_MPDU_PCU_START_0_ENCRYPT_TYPE
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
*/
#define RX_MPDU_PCU_START_0_ENCRYPT_TYPE_OFFSET                      0x00000000
#define RX_MPDU_PCU_START_0_ENCRYPT_TYPE_LSB                         28
#define RX_MPDU_PCU_START_0_ENCRYPT_TYPE_MASK                        0xf0000000

/* Description		RX_MPDU_PCU_START_1_PN_31_0
			Bits [31:0] of the PN number extracted from the IV field
			WEP: IV = {key_id_octet, pn2, pn1, pn0}.  Only pn[23:0] is
				valid.
			TKIP: IV = {pn5, pn4, pn3, pn2, key_id_octet, pn0,
				WEPSeed[1], pn1}.  Only pn[47:0] is valid.
			AES-CCM: IV = {pn5, pn4, pn3, pn2, key_id_octet, 0x0, pn1,
				pn0}.  Only pn[47:0] is valid.
			WAPI: IV = {key_id_octet, 0x0, pn15, pn14, pn13, pn12, pn11,
				pn10, pn9, pn8, pn7, pn6, pn5, pn4, pn3, pn2, pn1, pn0}. 
				pn[127:0] are valid.
*/
#define RX_MPDU_PCU_START_1_PN_31_0_OFFSET                           0x00000004
#define RX_MPDU_PCU_START_1_PN_31_0_LSB                              0
#define RX_MPDU_PCU_START_1_PN_31_0_MASK                             0xffffffff

/* Description		RX_MPDU_PCU_START_2_PN_63_32
			Bits [63:32] of the PN number.   See description for
			pn_31_0.
*/
#define RX_MPDU_PCU_START_2_PN_63_32_OFFSET                          0x00000008
#define RX_MPDU_PCU_START_2_PN_63_32_LSB                             0
#define RX_MPDU_PCU_START_2_PN_63_32_MASK                            0xffffffff

/* Description		RX_MPDU_PCU_START_3_PN_95_64
			
*/
#define RX_MPDU_PCU_START_3_PN_95_64_OFFSET                          0x0000000c
#define RX_MPDU_PCU_START_3_PN_95_64_LSB                             0
#define RX_MPDU_PCU_START_3_PN_95_64_MASK                            0xffffffff

/* Description		RX_MPDU_PCU_START_4_PN_127_96
			Bits [127:96] of the PN number.  See description for
			pn_31_0.
*/
#define RX_MPDU_PCU_START_4_PN_127_96_OFFSET                         0x00000010
#define RX_MPDU_PCU_START_4_PN_127_96_LSB                            0
#define RX_MPDU_PCU_START_4_PN_127_96_MASK                           0xffffffff

/* Description		RX_MPDU_PCU_START_5_KEY_ID_OCTET
			The key ID octet from the IV.
*/
#define RX_MPDU_PCU_START_5_KEY_ID_OCTET_OFFSET                      0x00000014
#define RX_MPDU_PCU_START_5_KEY_ID_OCTET_LSB                         0
#define RX_MPDU_PCU_START_5_KEY_ID_OCTET_MASK                        0x000000ff

/* Description		RX_MPDU_PCU_START_5_PRE_DELIM_ERR
			Indicates that the first delimiter had a FCS failure.  Only
			valid when first_mpdu and first_msdu are set.
*/
#define RX_MPDU_PCU_START_5_PRE_DELIM_ERR_OFFSET                     0x00000014
#define RX_MPDU_PCU_START_5_PRE_DELIM_ERR_LSB                        8
#define RX_MPDU_PCU_START_5_PRE_DELIM_ERR_MASK                       0x00000100

/* Description		RX_MPDU_PCU_START_5_RESERVED_5
			Reserved: HW should fill with zero.  FW should ignore.
*/
#define RX_MPDU_PCU_START_5_RESERVED_5_OFFSET                        0x00000014
#define RX_MPDU_PCU_START_5_RESERVED_5_LSB                           9
#define RX_MPDU_PCU_START_5_RESERVED_5_MASK                          0x0ffffe00

/* Description		RX_MPDU_PCU_START_5_TID
			The TID field in the QoS control field
*/
#define RX_MPDU_PCU_START_5_TID_OFFSET                               0x00000014
#define RX_MPDU_PCU_START_5_TID_LSB                                  28
#define RX_MPDU_PCU_START_5_TID_MASK                                 0xf0000000

/* Description		RX_MPDU_PCU_START_6_MPDU_LENGTH
			MPDU length before decapsulation.
*/
#define RX_MPDU_PCU_START_6_MPDU_LENGTH_OFFSET                       0x00000018
#define RX_MPDU_PCU_START_6_MPDU_LENGTH_LSB                          0
#define RX_MPDU_PCU_START_6_MPDU_LENGTH_MASK                         0x00003fff

/* Description		RX_MPDU_PCU_START_6_FIRST_MPDU
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_FIRST_MPDU_OFFSET                        0x00000018
#define RX_MPDU_PCU_START_6_FIRST_MPDU_LSB                           14
#define RX_MPDU_PCU_START_6_FIRST_MPDU_MASK                          0x00004000

/* Description		RX_MPDU_PCU_START_6_MCAST_BCAST
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_MCAST_BCAST_OFFSET                       0x00000018
#define RX_MPDU_PCU_START_6_MCAST_BCAST_LSB                          15
#define RX_MPDU_PCU_START_6_MCAST_BCAST_MASK                         0x00008000

/* Description		RX_MPDU_PCU_START_6_PEER_IDX_NOT_FOUND
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_PEER_IDX_NOT_FOUND_OFFSET                0x00000018
#define RX_MPDU_PCU_START_6_PEER_IDX_NOT_FOUND_LSB                   16
#define RX_MPDU_PCU_START_6_PEER_IDX_NOT_FOUND_MASK                  0x00010000

/* Description		RX_MPDU_PCU_START_6_PEER_IDX_TIMEOUT
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_PEER_IDX_TIMEOUT_OFFSET                  0x00000018
#define RX_MPDU_PCU_START_6_PEER_IDX_TIMEOUT_LSB                     17
#define RX_MPDU_PCU_START_6_PEER_IDX_TIMEOUT_MASK                    0x00020000

/* Description		RX_MPDU_PCU_START_6_POWER_MGMT
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_POWER_MGMT_OFFSET                        0x00000018
#define RX_MPDU_PCU_START_6_POWER_MGMT_LSB                           18
#define RX_MPDU_PCU_START_6_POWER_MGMT_MASK                          0x00040000

/* Description		RX_MPDU_PCU_START_6_NON_QOS
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_NON_QOS_OFFSET                           0x00000018
#define RX_MPDU_PCU_START_6_NON_QOS_LSB                              19
#define RX_MPDU_PCU_START_6_NON_QOS_MASK                             0x00080000

/* Description		RX_MPDU_PCU_START_6_NULL_DATA
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_NULL_DATA_OFFSET                         0x00000018
#define RX_MPDU_PCU_START_6_NULL_DATA_LSB                            20
#define RX_MPDU_PCU_START_6_NULL_DATA_MASK                           0x00100000

/* Description		RX_MPDU_PCU_START_6_MGMT_TYPE
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_MGMT_TYPE_OFFSET                         0x00000018
#define RX_MPDU_PCU_START_6_MGMT_TYPE_LSB                            21
#define RX_MPDU_PCU_START_6_MGMT_TYPE_MASK                           0x00200000

/* Description		RX_MPDU_PCU_START_6_CTRL_TYPE
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_CTRL_TYPE_OFFSET                         0x00000018
#define RX_MPDU_PCU_START_6_CTRL_TYPE_LSB                            22
#define RX_MPDU_PCU_START_6_CTRL_TYPE_MASK                           0x00400000

/* Description		RX_MPDU_PCU_START_6_MORE_DATA
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_MORE_DATA_OFFSET                         0x00000018
#define RX_MPDU_PCU_START_6_MORE_DATA_LSB                            23
#define RX_MPDU_PCU_START_6_MORE_DATA_MASK                           0x00800000

/* Description		RX_MPDU_PCU_START_6_EOSP
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_EOSP_OFFSET                              0x00000018
#define RX_MPDU_PCU_START_6_EOSP_LSB                                 24
#define RX_MPDU_PCU_START_6_EOSP_MASK                                0x01000000

/* Description		RX_MPDU_PCU_START_6_FRAGMENT
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_FRAGMENT_OFFSET                          0x00000018
#define RX_MPDU_PCU_START_6_FRAGMENT_LSB                             25
#define RX_MPDU_PCU_START_6_FRAGMENT_MASK                            0x02000000

/* Description		RX_MPDU_PCU_START_6_ORDER
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_ORDER_OFFSET                             0x00000018
#define RX_MPDU_PCU_START_6_ORDER_LSB                                26
#define RX_MPDU_PCU_START_6_ORDER_MASK                               0x04000000

/* Description		RX_MPDU_PCU_START_6_U_APSD_TRIGGER
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_U_APSD_TRIGGER_OFFSET                    0x00000018
#define RX_MPDU_PCU_START_6_U_APSD_TRIGGER_LSB                       27
#define RX_MPDU_PCU_START_6_U_APSD_TRIGGER_MASK                      0x08000000

/* Description		RX_MPDU_PCU_START_6_ENCRYPT_REQUIRED
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_ENCRYPT_REQUIRED_OFFSET                  0x00000018
#define RX_MPDU_PCU_START_6_ENCRYPT_REQUIRED_LSB                     28
#define RX_MPDU_PCU_START_6_ENCRYPT_REQUIRED_MASK                    0x10000000

/* Description		RX_MPDU_PCU_START_6_DIRECTED
			See definition in RX attention descriptor
*/
#define RX_MPDU_PCU_START_6_DIRECTED_OFFSET                          0x00000018
#define RX_MPDU_PCU_START_6_DIRECTED_LSB                             29
#define RX_MPDU_PCU_START_6_DIRECTED_MASK                            0x20000000

/* Description		RX_MPDU_PCU_START_6_RESERVED_6
			Reserved: HW should fill with zero.  FW should ignore.
*/
#define RX_MPDU_PCU_START_6_RESERVED_6_OFFSET                        0x00000018
#define RX_MPDU_PCU_START_6_RESERVED_6_LSB                           30
#define RX_MPDU_PCU_START_6_RESERVED_6_MASK                          0xc0000000


#endif // _RX_MPDU_PCU_START_H_
