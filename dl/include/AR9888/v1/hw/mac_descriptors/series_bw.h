// Copyright (c) 2012 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _SERIES_BW_H_
#define _SERIES_BW_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	ppdu_dur[13:0], txbf_en[14], legacy_vht_bw[15], chain_mask[19:16], tpc[25:20], rts_enable[26], cts_enable[27], short_gi[29:28], ldpc[31:30]
//	1	num_vht_mac_pad[19:0], stbc[20], reserved_1[23:21], rate[27:24], nss[29:28], preamble_type[31:30]
//	2	psdu_octet[19:0], ppdu_sym[30:20], reserved_2[31]
//	3	min_mpdu_spacing[9:0], reserved_3a[15:10], num_of_mpdu[22:16], reserved_3b[23], fixed_delimiters[31:24]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_SERIES_BW 4

struct series_bw {
    volatile uint32_t ppdu_dur                        : 14, //[13:0]
                      txbf_en                         :  1, //[14]
                      legacy_vht_bw                   :  1, //[15]
                      chain_mask                      :  4, //[19:16]
                      tpc                             :  6, //[25:20]
                      rts_enable                      :  1, //[26]
                      cts_enable                      :  1, //[27]
                      short_gi                        :  2, //[29:28]
                      ldpc                            :  2; //[31:30]
    volatile uint32_t num_vht_mac_pad                 : 20, //[19:0]
                      stbc                            :  1, //[20]
                      reserved_1                      :  3, //[23:21]
                      rate                            :  4, //[27:24]
                      nss                             :  2, //[29:28]
                      preamble_type                   :  2; //[31:30]
    volatile uint32_t psdu_octet                      : 20, //[19:0]
                      ppdu_sym                        : 11, //[30:20]
                      reserved_2                      :  1; //[31]
    volatile uint32_t min_mpdu_spacing                : 10, //[9:0]
                      reserved_3a                     :  6, //[15:10]
                      num_of_mpdu                     :  7, //[22:16]
                      reserved_3b                     :  1, //[23]
                      fixed_delimiters                :  8; //[31:24]
};

/*

ppdu_dur
			Duration of PPDU in units of usec.  Used by PCU to generate
			the duration field for RTS/CTS enabled frames.  It includes
			the L-preamble time and optionally the HT/VHT preamble time.
			It is also used to determine the L-SIG length for 11n and
			11ac packets.

txbf_en
			If txbf_en is set this packet is to be beamformed.  Used by
			MAC to set the 'Beamformed' bit in VHT-SIG-A.

legacy_vht_bw
			When FW queues legacy control frames such as BAR, PS-Poll,
			CF-End, NDPA (future), and BR Poll (future), if the
			legacy_vht_bw bit is set then it will use the VHT BW
			mechanism which uses 3 bits of the service field to indicate
			bandwidth and the TA multcast bit will be set. If this bit
			is clear then normal service field is used.  Generated
			frames such as RTS, self-CTS and NDP (future) do not depend
			on legacy_vht_bw.  This field is normally clear.

chain_mask
			Indicates the active chains.  The chain_mask[0] indicates
			chain 0 is active, chain_mask[1] indicates chain 1 is
			active, etc.

tpc
			Transmit power control.  Used by baseband.

rts_enable
			If set RTS CTS packet exchange is required before data
			packet transmission.  Used by PCU.

cts_enable
			If set self-CTS packet exchange is required before data
			packet transmission.  Used by PCU.  Series 0 for bandwidth
			20 MHz.

short_gi
			If short_gi[0] is set this packet uses short guard interval.
			If short_gi[1] is set the number of payload symbols mod 10
			is 9.  This resolves the ambiguity packet with 2 adjacent
			symbol counts could map to the same L-SIG length. 
			Short_gi[0] is used by PCU to set the HT-SIG SHORT_GI field.
			Used by PCU.

ldpc
			If ldpc[0] is set this packet uses LDPC encoding.  If
			ldpc[1] is set this packet required at least an extra symbol
			(only used for 11ac).  ldpc[0] is used by PCU to set the
			HT-SIG FEC CODING field.  ldpc[1:0] is used to set the
			VHT-SIG Coding field.  Used by PCU.

num_vht_mac_pad
			Number of MAC pad bytes after the end of the last MPDU.  The
			vht_ppdu_bit_length = service_bits + psdu_octet * 8 +
			num_vht_mac_pad * 8 + tail_bits + phy_pad_bits

stbc
			If set STBC is enabled for HT or VHT frames.  Used by PCU to
			set the HT-SIG STBC[0] field.  HT-SIG STBC[1] field will
			always  be set to 0.  Used by PCU to set the VHT-SIG-A STBC
			field.

reserved_1
			Reserved.  Not used by HW.
			<legal:0>

rate
			Rate:
			For preamble_type == 0 (OFDM)
			0: OFDM 48 Mbps
			1: OFDM 24 Mbps
			2: OFDM 12 Mbps
			3: OFDM 6 Mbps
			4: OFDM 54 Mbps
			5: OFDM 36 Mbps
			6: OFDM 18 Mbps
			7: OFDM 9 Mbps
			For preamble_type ==1 (CCK)
			0: CCK 11 Mbps Long
			1: CCK 5.5 Mbps Long
			2: CCK 2 Mbps Long
			3: CCK 1 Mbps Long
			4: CCK 11 Mbps Short
			5: CCK 5.5 Mbps Short
			6: CCK 2 Mbps Short
			For preamble_type == 2 (HT)
			0: HT MCS 0 (BPSK 1/2)
			1: HT MCS 1 (QPSK 1/2)
			2: HT MCS 2 (QPSK 3/4)
			3: HT MCS 3 (16-QAM 1/2)
			4: HT MCS 4 (16-QAM 3/4)
			5: HT MCS 5 (64-QAM 2/3)
			6: HT MCS 6 (64-QAM 3/4)
			7: HT MCS 7 (64-QAM 5/6)
			Note: to get higher MCS's use the nss field to indicate the
				number of streams.
			For preamble_type == 3 (VHT)
			0: VHT MCS 0 (BPSK 1/2)
			1: VHT MCS 1 (QPSK 1/2)
			2: VHT MCS 2 (QPSK 3/4)
			3: VHT MCS 3 (16-QAM 1/2)
			4: VHT MCS 4 (16-QAM 3/4)
			5: VHT MCS 5 (64-QAM 2/3)
			6: VHT MCS 6 (64-QAM 3/4)
			7: VHT MCS 7 (64-QAM 5/6)
			8: VHT MCS 8 (256-QAM 3/4)
			9: VHT MCS 9 (256-QAM 5/6)
			Note there are several illegal VHT rates due to fractional
				number of bits per symbol.  Below are the illegal rates for
				4 streams and lower:
			20 MHz, 1 stream, MCS 9
			20 MHz, 2 stream, MCS 9
			20 MHz, 4 stream, MCS 9
			80 MHz, 3 stream, MCS 6
			160 MHz, 3 stream, MCS 9
			160 MHz, 4 stream, MCS 7
			Used by PCU.
			<legal:0-9>

nss
			Indicates the number of streams
			0 indicates 1 stream
			1 indicates 2 streams
			2 indicates 3 streams
			3 indicates 4 streams (Not supported in WiFi 1.0)
			Used by PCU.
			<legal:0-2>

preamble_type
			Indicates the encoding of the MCS field
			0: OFDM
			1: CCK
			2: HT
			3: VHT

psdu_octet
			PSDU length in octets which includes all useful data in a
			packet which does not include:
			Service (16 bits)
			Pad data after the last non-zero length MPDU (0 to 3 bytes)
			Zero length EOF MPDU (4 bytes each)
			Tail (0 for LDPC and Nes * 6 for BCC) where Nes is the
				number of encoders
			PHY pad
			For 11n packets the HT-SIG HT length field will be the same
				as psdu_octets.  For 11ac packets the VHT-SIG-B length is
				ceiling (apep_len / 4).  This length field is in units of 4
				octets.  Used by PCU.

ppdu_sym
			Number of symbols in PPDU after all preambles: legacy, HT
			and/or VHT  

reserved_2
			Reserved.  Not used by HW.
			<legal:0>

min_mpdu_spacing
			Minimum number of dwords in an MPDU.  If the actual MPDU
			size is smaller than this, the PCU will insert zero-length
			delimiters after this MPDU to compensate for the difference.
			For example at a PHY rate of 1.3 Gbps if the receiver is
			capable of receiving only 1 MPDU every 16 usec, then this
			field should be set to 649.  This means that if the MPDU
			length is shorter than 2596 bytes then additional zero
			length delimiter and MAC byte padding should be added to get
			to a combined byte count of 2596 bytes.  This does not the
			non-zero length delimiter.

reserved_3a
			Reserved.  Not used by HW.
			<legal:0>

num_of_mpdu
			Number of MPDU.  According to the 802.11 standard values
			larger than 64 are not supported.

reserved_3b
			Reserved.  Not used by HW.
			<legal:0>

fixed_delimiters
			A fixed number of zero-length delimiters to add after this
			MPDU.  The actual number of zero-length delimiters will be
			maximum of this field and the amount based on the
			min_mpdu_spacing field.
*/


/* Description		SERIES_BW_0_PPDU_DUR
			Duration of PPDU in units of usec.  Used by PCU to generate
			the duration field for RTS/CTS enabled frames.  It includes
			the L-preamble time and optionally the HT/VHT preamble time.
			It is also used to determine the L-SIG length for 11n and
			11ac packets.
*/
#define SERIES_BW_0_PPDU_DUR_OFFSET                                  0x00000000
#define SERIES_BW_0_PPDU_DUR_LSB                                     0
#define SERIES_BW_0_PPDU_DUR_MASK                                    0x00003fff

/* Description		SERIES_BW_0_TXBF_EN
			If txbf_en is set this packet is to be beamformed.  Used by
			MAC to set the 'Beamformed' bit in VHT-SIG-A.
*/
#define SERIES_BW_0_TXBF_EN_OFFSET                                   0x00000000
#define SERIES_BW_0_TXBF_EN_LSB                                      14
#define SERIES_BW_0_TXBF_EN_MASK                                     0x00004000

/* Description		SERIES_BW_0_LEGACY_VHT_BW
			When FW queues legacy control frames such as BAR, PS-Poll,
			CF-End, NDPA (future), and BR Poll (future), if the
			legacy_vht_bw bit is set then it will use the VHT BW
			mechanism which uses 3 bits of the service field to indicate
			bandwidth and the TA multcast bit will be set. If this bit
			is clear then normal service field is used.  Generated
			frames such as RTS, self-CTS and NDP (future) do not depend
			on legacy_vht_bw.  This field is normally clear.
*/
#define SERIES_BW_0_LEGACY_VHT_BW_OFFSET                             0x00000000
#define SERIES_BW_0_LEGACY_VHT_BW_LSB                                15
#define SERIES_BW_0_LEGACY_VHT_BW_MASK                               0x00008000

/* Description		SERIES_BW_0_CHAIN_MASK
			Indicates the active chains.  The chain_mask[0] indicates
			chain 0 is active, chain_mask[1] indicates chain 1 is
			active, etc.
*/
#define SERIES_BW_0_CHAIN_MASK_OFFSET                                0x00000000
#define SERIES_BW_0_CHAIN_MASK_LSB                                   16
#define SERIES_BW_0_CHAIN_MASK_MASK                                  0x000f0000

/* Description		SERIES_BW_0_TPC
			Transmit power control.  Used by baseband.
*/
#define SERIES_BW_0_TPC_OFFSET                                       0x00000000
#define SERIES_BW_0_TPC_LSB                                          20
#define SERIES_BW_0_TPC_MASK                                         0x03f00000

/* Description		SERIES_BW_0_RTS_ENABLE
			If set RTS CTS packet exchange is required before data
			packet transmission.  Used by PCU.
*/
#define SERIES_BW_0_RTS_ENABLE_OFFSET                                0x00000000
#define SERIES_BW_0_RTS_ENABLE_LSB                                   26
#define SERIES_BW_0_RTS_ENABLE_MASK                                  0x04000000

/* Description		SERIES_BW_0_CTS_ENABLE
			If set self-CTS packet exchange is required before data
			packet transmission.  Used by PCU.  Series 0 for bandwidth
			20 MHz.
*/
#define SERIES_BW_0_CTS_ENABLE_OFFSET                                0x00000000
#define SERIES_BW_0_CTS_ENABLE_LSB                                   27
#define SERIES_BW_0_CTS_ENABLE_MASK                                  0x08000000

/* Description		SERIES_BW_0_SHORT_GI
			If short_gi[0] is set this packet uses short guard interval.
			If short_gi[1] is set the number of payload symbols mod 10
			is 9.  This resolves the ambiguity packet with 2 adjacent
			symbol counts could map to the same L-SIG length. 
			Short_gi[0] is used by PCU to set the HT-SIG SHORT_GI field.
			Used by PCU.
*/
#define SERIES_BW_0_SHORT_GI_OFFSET                                  0x00000000
#define SERIES_BW_0_SHORT_GI_LSB                                     28
#define SERIES_BW_0_SHORT_GI_MASK                                    0x30000000

/* Description		SERIES_BW_0_LDPC
			If ldpc[0] is set this packet uses LDPC encoding.  If
			ldpc[1] is set this packet required at least an extra symbol
			(only used for 11ac).  ldpc[0] is used by PCU to set the
			HT-SIG FEC CODING field.  ldpc[1:0] is used to set the
			VHT-SIG Coding field.  Used by PCU.
*/
#define SERIES_BW_0_LDPC_OFFSET                                      0x00000000
#define SERIES_BW_0_LDPC_LSB                                         30
#define SERIES_BW_0_LDPC_MASK                                        0xc0000000

/* Description		SERIES_BW_1_NUM_VHT_MAC_PAD
			Number of MAC pad bytes after the end of the last MPDU.  The
			vht_ppdu_bit_length = service_bits + psdu_octet * 8 +
			num_vht_mac_pad * 8 + tail_bits + phy_pad_bits
*/
#define SERIES_BW_1_NUM_VHT_MAC_PAD_OFFSET                           0x00000004
#define SERIES_BW_1_NUM_VHT_MAC_PAD_LSB                              0
#define SERIES_BW_1_NUM_VHT_MAC_PAD_MASK                             0x000fffff

/* Description		SERIES_BW_1_STBC
			If set STBC is enabled for HT or VHT frames.  Used by PCU to
			set the HT-SIG STBC[0] field.  HT-SIG STBC[1] field will
			always  be set to 0.  Used by PCU to set the VHT-SIG-A STBC
			field.
*/
#define SERIES_BW_1_STBC_OFFSET                                      0x00000004
#define SERIES_BW_1_STBC_LSB                                         20
#define SERIES_BW_1_STBC_MASK                                        0x00100000

/* Description		SERIES_BW_1_RESERVED_1
			Reserved.  Not used by HW.
			<legal:0>
*/
#define SERIES_BW_1_RESERVED_1_OFFSET                                0x00000004
#define SERIES_BW_1_RESERVED_1_LSB                                   21
#define SERIES_BW_1_RESERVED_1_MASK                                  0x00e00000

/* Description		SERIES_BW_1_RATE
			Rate:
			For preamble_type == 0 (OFDM)
			0: OFDM 48 Mbps
			1: OFDM 24 Mbps
			2: OFDM 12 Mbps
			3: OFDM 6 Mbps
			4: OFDM 54 Mbps
			5: OFDM 36 Mbps
			6: OFDM 18 Mbps
			7: OFDM 9 Mbps
			For preamble_type ==1 (CCK)
			0: CCK 11 Mbps Long
			1: CCK 5.5 Mbps Long
			2: CCK 2 Mbps Long
			3: CCK 1 Mbps Long
			4: CCK 11 Mbps Short
			5: CCK 5.5 Mbps Short
			6: CCK 2 Mbps Short
			For preamble_type == 2 (HT)
			0: HT MCS 0 (BPSK 1/2)
			1: HT MCS 1 (QPSK 1/2)
			2: HT MCS 2 (QPSK 3/4)
			3: HT MCS 3 (16-QAM 1/2)
			4: HT MCS 4 (16-QAM 3/4)
			5: HT MCS 5 (64-QAM 2/3)
			6: HT MCS 6 (64-QAM 3/4)
			7: HT MCS 7 (64-QAM 5/6)
			Note: to get higher MCS's use the nss field to indicate the
				number of streams.
			For preamble_type == 3 (VHT)
			0: VHT MCS 0 (BPSK 1/2)
			1: VHT MCS 1 (QPSK 1/2)
			2: VHT MCS 2 (QPSK 3/4)
			3: VHT MCS 3 (16-QAM 1/2)
			4: VHT MCS 4 (16-QAM 3/4)
			5: VHT MCS 5 (64-QAM 2/3)
			6: VHT MCS 6 (64-QAM 3/4)
			7: VHT MCS 7 (64-QAM 5/6)
			8: VHT MCS 8 (256-QAM 3/4)
			9: VHT MCS 9 (256-QAM 5/6)
			Note there are several illegal VHT rates due to fractional
				number of bits per symbol.  Below are the illegal rates for
				4 streams and lower:
			20 MHz, 1 stream, MCS 9
			20 MHz, 2 stream, MCS 9
			20 MHz, 4 stream, MCS 9
			80 MHz, 3 stream, MCS 6
			160 MHz, 3 stream, MCS 9
			160 MHz, 4 stream, MCS 7
			Used by PCU.
			<legal:0-9>
*/
#define SERIES_BW_1_RATE_OFFSET                                      0x00000004
#define SERIES_BW_1_RATE_LSB                                         24
#define SERIES_BW_1_RATE_MASK                                        0x0f000000

/* Description		SERIES_BW_1_NSS
			Indicates the number of streams
			0 indicates 1 stream
			1 indicates 2 streams
			2 indicates 3 streams
			3 indicates 4 streams (Not supported in WiFi 1.0)
			Used by PCU.
			<legal:0-2>
*/
#define SERIES_BW_1_NSS_OFFSET                                       0x00000004
#define SERIES_BW_1_NSS_LSB                                          28
#define SERIES_BW_1_NSS_MASK                                         0x30000000

/* Description		SERIES_BW_1_PREAMBLE_TYPE
			Indicates the encoding of the MCS field
			0: OFDM
			1: CCK
			2: HT
			3: VHT
*/
#define SERIES_BW_1_PREAMBLE_TYPE_OFFSET                             0x00000004
#define SERIES_BW_1_PREAMBLE_TYPE_LSB                                30
#define SERIES_BW_1_PREAMBLE_TYPE_MASK                               0xc0000000

/* Description		SERIES_BW_2_PSDU_OCTET
			PSDU length in octets which includes all useful data in a
			packet which does not include:
			Service (16 bits)
			Pad data after the last non-zero length MPDU (0 to 3 bytes)
			Zero length EOF MPDU (4 bytes each)
			Tail (0 for LDPC and Nes * 6 for BCC) where Nes is the
				number of encoders
			PHY pad
			For 11n packets the HT-SIG HT length field will be the same
				as psdu_octets.  For 11ac packets the VHT-SIG-B length is
				ceiling (apep_len / 4).  This length field is in units of 4
				octets.  Used by PCU.
*/
#define SERIES_BW_2_PSDU_OCTET_OFFSET                                0x00000008
#define SERIES_BW_2_PSDU_OCTET_LSB                                   0
#define SERIES_BW_2_PSDU_OCTET_MASK                                  0x000fffff

/* Description		SERIES_BW_2_PPDU_SYM
			Number of symbols in PPDU after all preambles: legacy, HT
			and/or VHT  
*/
#define SERIES_BW_2_PPDU_SYM_OFFSET                                  0x00000008
#define SERIES_BW_2_PPDU_SYM_LSB                                     20
#define SERIES_BW_2_PPDU_SYM_MASK                                    0x7ff00000

/* Description		SERIES_BW_2_RESERVED_2
			Reserved.  Not used by HW.
			<legal:0>
*/
#define SERIES_BW_2_RESERVED_2_OFFSET                                0x00000008
#define SERIES_BW_2_RESERVED_2_LSB                                   31
#define SERIES_BW_2_RESERVED_2_MASK                                  0x80000000

/* Description		SERIES_BW_3_MIN_MPDU_SPACING
			Minimum number of dwords in an MPDU.  If the actual MPDU
			size is smaller than this, the PCU will insert zero-length
			delimiters after this MPDU to compensate for the difference.
			For example at a PHY rate of 1.3 Gbps if the receiver is
			capable of receiving only 1 MPDU every 16 usec, then this
			field should be set to 649.  This means that if the MPDU
			length is shorter than 2596 bytes then additional zero
			length delimiter and MAC byte padding should be added to get
			to a combined byte count of 2596 bytes.  This does not the
			non-zero length delimiter.
*/
#define SERIES_BW_3_MIN_MPDU_SPACING_OFFSET                          0x0000000c
#define SERIES_BW_3_MIN_MPDU_SPACING_LSB                             0
#define SERIES_BW_3_MIN_MPDU_SPACING_MASK                            0x000003ff

/* Description		SERIES_BW_3_RESERVED_3A
			Reserved.  Not used by HW.
			<legal:0>
*/
#define SERIES_BW_3_RESERVED_3A_OFFSET                               0x0000000c
#define SERIES_BW_3_RESERVED_3A_LSB                                  10
#define SERIES_BW_3_RESERVED_3A_MASK                                 0x0000fc00

/* Description		SERIES_BW_3_NUM_OF_MPDU
			Number of MPDU.  According to the 802.11 standard values
			larger than 64 are not supported.
*/
#define SERIES_BW_3_NUM_OF_MPDU_OFFSET                               0x0000000c
#define SERIES_BW_3_NUM_OF_MPDU_LSB                                  16
#define SERIES_BW_3_NUM_OF_MPDU_MASK                                 0x007f0000

/* Description		SERIES_BW_3_RESERVED_3B
			Reserved.  Not used by HW.
			<legal:0>
*/
#define SERIES_BW_3_RESERVED_3B_OFFSET                               0x0000000c
#define SERIES_BW_3_RESERVED_3B_LSB                                  23
#define SERIES_BW_3_RESERVED_3B_MASK                                 0x00800000

/* Description		SERIES_BW_3_FIXED_DELIMITERS
			A fixed number of zero-length delimiters to add after this
			MPDU.  The actual number of zero-length delimiters will be
			maximum of this field and the amount based on the
			min_mpdu_spacing field.
*/
#define SERIES_BW_3_FIXED_DELIMITERS_OFFSET                          0x0000000c
#define SERIES_BW_3_FIXED_DELIMITERS_LSB                             24
#define SERIES_BW_3_FIXED_DELIMITERS_MASK                            0xff000000


#endif // _SERIES_BW_H_
