// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _PEER_ENTRY_H_
#define _PEER_ENTRY_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	qcu_filter[15:0], key_type[19:16], power_save[20], a_msdu_wds_ad3_ad4[23:21], u_apsd_mask[31:24]
//	1	mac_addr_a_31_0[31:0]
//	2	mac_addr_a_47_32[15:0], mac_addr_b_15_0[31:16]
//	3	mac_addr_b_47_16[31:0]
//	4	temporal_key_31_0[31:0]
//	5	temporal_key_63_32[31:0]
//	6	temporal_key_95_64[31:0]
//	7	temporal_key_127_96[31:0]
//	8	temporal_key_159_128[31:0]
//	9	temporal_key_191_160[31:0]
//	10	temporal_key_223_192[31:0]
//	11	temporal_key_255_224[31:0]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_PEER_ENTRY 12

struct peer_entry {
    volatile uint32_t qcu_filter                      : 16, //[15:0]
                      key_type                        :  4, //[19:16]
                      power_save                      :  1, //[20]
                      a_msdu_wds_ad3_ad4              :  3, //[23:21]
                      u_apsd_mask                     :  8; //[31:24]
    volatile uint32_t mac_addr_a_31_0                 : 32; //[31:0]
    volatile uint32_t mac_addr_a_47_32                : 16, //[15:0]
                      mac_addr_b_15_0                 : 16; //[31:16]
    volatile uint32_t mac_addr_b_47_16                : 32; //[31:0]
    volatile uint32_t temporal_key_31_0               : 32; //[31:0]
    volatile uint32_t temporal_key_63_32              : 32; //[31:0]
    volatile uint32_t temporal_key_95_64              : 32; //[31:0]
    volatile uint32_t temporal_key_127_96             : 32; //[31:0]
    volatile uint32_t temporal_key_159_128            : 32; //[31:0]
    volatile uint32_t temporal_key_191_160            : 32; //[31:0]
    volatile uint32_t temporal_key_223_192            : 32; //[31:0]
    volatile uint32_t temporal_key_255_224            : 32; //[31:0]
};

/*

qcu_filter
			Bitmap which indicates which queues need to be filtered by
			HW.  HW will read the peer table entry for every retry and
			honor these bits for every retry.  WiFi 1.0 supports
			qcu_filter[9:0].  The remaining bits are reserved for future
			expansion.

key_type
			The key_type indicates the cipher suite corresponding to
			this peer entry:
			0: WEP 40-bit
			1: WEP 104-bit
			2: TKIP without MIC
			3: WEP 128-bit
			4: TKIP with MIC
			5: WAPI
			6: AES-CCM
			7: No cipher

power_save
			Indicates that this station is in power save state and TX
			frames should be filtered.

a_msdu_wds_ad3_ad4
			Determines the selection of AD3 and AD4 for A-MSDU 4 address
			frames (WDS):
			000: AD3 = AD_A, AD4 = AD_A
			001: AD3 = AD_A, AD4 = AD_B
			010: AD3 = AD_B, AD4 = AD_A
			011: AD3 = AD_B, AD4 = AD_B
			100: AD3 = DA, AD4 = SA
			1XX: Invalid

u_apsd_mask
			Indicates the TID values map to U-APSD triggers.  Only TID
			values of 0-7 are considered valid.  This value is a bitmask
			where the lowest bit corresponds to TID of 0 and the highest
			bit corresponds to TID of 7.  For example, the value 0x35
			indicates TID 0, 2, 4, and 5 are U-APSD triggers.

mac_addr_a_31_0
			Lower 32 bits of the MAC address A used by HW for
			encapsulating 802.11

mac_addr_a_47_32
			Upper 16 bits of the MAC address A used by HW for
			encapsulating 802.11

mac_addr_b_15_0
			Lower 16 bits of the MAC address B used by HW for
			encapsulating 802.11

mac_addr_b_47_16
			Upper 32 bits of the MAC address B used by HW for
			encapsulating 802.11

temporal_key_31_0
			First 32 bits of the temporal key material.  The temporal
			key for WEP 40-bit uses the first 40 bits, WEP 104-bit uses
			the first 104 bits, WEP 128-bit uses all 128 bits, TKIP
			with/without MIC uses 128 bits, WAPI uses all 128 bits, and
			AES-CCM uses all 128 bits.

temporal_key_63_32
			Second 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.

temporal_key_95_64
			Third 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.

temporal_key_127_96
			Fourth 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.

temporal_key_159_128
			Fifth 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.  For TKIP this is the TX
			MIC key[31:0].

temporal_key_191_160
			Final 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.  For TKIP this is the TX
			MIC key[63:32].

temporal_key_223_192
			Final 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.  For TKIP this is the RX
			MIC key[31:0].

temporal_key_255_224
			Final 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.  For TKIP this is the RX
			MIC key[63:32].
*/


/* Description		PEER_ENTRY_0_QCU_FILTER
			Bitmap which indicates which queues need to be filtered by
			HW.  HW will read the peer table entry for every retry and
			honor these bits for every retry.  WiFi 1.0 supports
			qcu_filter[9:0].  The remaining bits are reserved for future
			expansion.
*/
#define PEER_ENTRY_0_QCU_FILTER_OFFSET                               0x00000000
#define PEER_ENTRY_0_QCU_FILTER_LSB                                  0
#define PEER_ENTRY_0_QCU_FILTER_MASK                                 0x0000ffff

/* Description		PEER_ENTRY_0_KEY_TYPE
			The key_type indicates the cipher suite corresponding to
			this peer entry:
			0: WEP 40-bit
			1: WEP 104-bit
			2: TKIP without MIC
			3: WEP 128-bit
			4: TKIP with MIC
			5: WAPI
			6: AES-CCM
			7: No cipher
*/
#define PEER_ENTRY_0_KEY_TYPE_OFFSET                                 0x00000000
#define PEER_ENTRY_0_KEY_TYPE_LSB                                    16
#define PEER_ENTRY_0_KEY_TYPE_MASK                                   0x000f0000

/* Description		PEER_ENTRY_0_POWER_SAVE
			Indicates that this station is in power save state and TX
			frames should be filtered.
*/
#define PEER_ENTRY_0_POWER_SAVE_OFFSET                               0x00000000
#define PEER_ENTRY_0_POWER_SAVE_LSB                                  20
#define PEER_ENTRY_0_POWER_SAVE_MASK                                 0x00100000

/* Description		PEER_ENTRY_0_A_MSDU_WDS_AD3_AD4
			Determines the selection of AD3 and AD4 for A-MSDU 4 address
			frames (WDS):
			000: AD3 = AD_A, AD4 = AD_A
			001: AD3 = AD_A, AD4 = AD_B
			010: AD3 = AD_B, AD4 = AD_A
			011: AD3 = AD_B, AD4 = AD_B
			100: AD3 = DA, AD4 = SA
			1XX: Invalid
*/
#define PEER_ENTRY_0_A_MSDU_WDS_AD3_AD4_OFFSET                       0x00000000
#define PEER_ENTRY_0_A_MSDU_WDS_AD3_AD4_LSB                          21
#define PEER_ENTRY_0_A_MSDU_WDS_AD3_AD4_MASK                         0x00e00000

/* Description		PEER_ENTRY_0_U_APSD_MASK
			Indicates the TID values map to U-APSD triggers.  Only TID
			values of 0-7 are considered valid.  This value is a bitmask
			where the lowest bit corresponds to TID of 0 and the highest
			bit corresponds to TID of 7.  For example, the value 0x35
			indicates TID 0, 2, 4, and 5 are U-APSD triggers.
*/
#define PEER_ENTRY_0_U_APSD_MASK_OFFSET                              0x00000000
#define PEER_ENTRY_0_U_APSD_MASK_LSB                                 24
#define PEER_ENTRY_0_U_APSD_MASK_MASK                                0xff000000

/* Description		PEER_ENTRY_1_MAC_ADDR_A_31_0
			Lower 32 bits of the MAC address A used by HW for
			encapsulating 802.11
*/
#define PEER_ENTRY_1_MAC_ADDR_A_31_0_OFFSET                          0x00000004
#define PEER_ENTRY_1_MAC_ADDR_A_31_0_LSB                             0
#define PEER_ENTRY_1_MAC_ADDR_A_31_0_MASK                            0xffffffff

/* Description		PEER_ENTRY_2_MAC_ADDR_A_47_32
			Upper 16 bits of the MAC address A used by HW for
			encapsulating 802.11
*/
#define PEER_ENTRY_2_MAC_ADDR_A_47_32_OFFSET                         0x00000008
#define PEER_ENTRY_2_MAC_ADDR_A_47_32_LSB                            0
#define PEER_ENTRY_2_MAC_ADDR_A_47_32_MASK                           0x0000ffff

/* Description		PEER_ENTRY_2_MAC_ADDR_B_15_0
			Lower 16 bits of the MAC address B used by HW for
			encapsulating 802.11
*/
#define PEER_ENTRY_2_MAC_ADDR_B_15_0_OFFSET                          0x00000008
#define PEER_ENTRY_2_MAC_ADDR_B_15_0_LSB                             16
#define PEER_ENTRY_2_MAC_ADDR_B_15_0_MASK                            0xffff0000

/* Description		PEER_ENTRY_3_MAC_ADDR_B_47_16
			Upper 32 bits of the MAC address B used by HW for
			encapsulating 802.11
*/
#define PEER_ENTRY_3_MAC_ADDR_B_47_16_OFFSET                         0x0000000c
#define PEER_ENTRY_3_MAC_ADDR_B_47_16_LSB                            0
#define PEER_ENTRY_3_MAC_ADDR_B_47_16_MASK                           0xffffffff

/* Description		PEER_ENTRY_4_TEMPORAL_KEY_31_0
			First 32 bits of the temporal key material.  The temporal
			key for WEP 40-bit uses the first 40 bits, WEP 104-bit uses
			the first 104 bits, WEP 128-bit uses all 128 bits, TKIP
			with/without MIC uses 128 bits, WAPI uses all 128 bits, and
			AES-CCM uses all 128 bits.
*/
#define PEER_ENTRY_4_TEMPORAL_KEY_31_0_OFFSET                        0x00000010
#define PEER_ENTRY_4_TEMPORAL_KEY_31_0_LSB                           0
#define PEER_ENTRY_4_TEMPORAL_KEY_31_0_MASK                          0xffffffff

/* Description		PEER_ENTRY_5_TEMPORAL_KEY_63_32
			Second 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.
*/
#define PEER_ENTRY_5_TEMPORAL_KEY_63_32_OFFSET                       0x00000014
#define PEER_ENTRY_5_TEMPORAL_KEY_63_32_LSB                          0
#define PEER_ENTRY_5_TEMPORAL_KEY_63_32_MASK                         0xffffffff

/* Description		PEER_ENTRY_6_TEMPORAL_KEY_95_64
			Third 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.
*/
#define PEER_ENTRY_6_TEMPORAL_KEY_95_64_OFFSET                       0x00000018
#define PEER_ENTRY_6_TEMPORAL_KEY_95_64_LSB                          0
#define PEER_ENTRY_6_TEMPORAL_KEY_95_64_MASK                         0xffffffff

/* Description		PEER_ENTRY_7_TEMPORAL_KEY_127_96
			Fourth 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.
*/
#define PEER_ENTRY_7_TEMPORAL_KEY_127_96_OFFSET                      0x0000001c
#define PEER_ENTRY_7_TEMPORAL_KEY_127_96_LSB                         0
#define PEER_ENTRY_7_TEMPORAL_KEY_127_96_MASK                        0xffffffff

/* Description		PEER_ENTRY_8_TEMPORAL_KEY_159_128
			Fifth 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.  For TKIP this is the TX
			MIC key[31:0].
*/
#define PEER_ENTRY_8_TEMPORAL_KEY_159_128_OFFSET                     0x00000020
#define PEER_ENTRY_8_TEMPORAL_KEY_159_128_LSB                        0
#define PEER_ENTRY_8_TEMPORAL_KEY_159_128_MASK                       0xffffffff

/* Description		PEER_ENTRY_9_TEMPORAL_KEY_191_160
			Final 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.  For TKIP this is the TX
			MIC key[63:32].
*/
#define PEER_ENTRY_9_TEMPORAL_KEY_191_160_OFFSET                     0x00000024
#define PEER_ENTRY_9_TEMPORAL_KEY_191_160_LSB                        0
#define PEER_ENTRY_9_TEMPORAL_KEY_191_160_MASK                       0xffffffff

/* Description		PEER_ENTRY_10_TEMPORAL_KEY_223_192
			Final 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.  For TKIP this is the RX
			MIC key[31:0].
*/
#define PEER_ENTRY_10_TEMPORAL_KEY_223_192_OFFSET                    0x00000028
#define PEER_ENTRY_10_TEMPORAL_KEY_223_192_LSB                       0
#define PEER_ENTRY_10_TEMPORAL_KEY_223_192_MASK                      0xffffffff

/* Description		PEER_ENTRY_11_TEMPORAL_KEY_255_224
			Final 32 bits of the temporal key material.  See the
			description of temporal_key_31_0.  For TKIP this is the RX
			MIC key[63:32].
*/
#define PEER_ENTRY_11_TEMPORAL_KEY_255_224_OFFSET                    0x0000002c
#define PEER_ENTRY_11_TEMPORAL_KEY_255_224_LSB                       0
#define PEER_ENTRY_11_TEMPORAL_KEY_255_224_MASK                      0xffffffff


#endif // _PEER_ENTRY_H_
