// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _RX_PPDU_START_H_
#define _RX_PPDU_START_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	rssi_chain0_pri20[7:0], rssi_chain0_sec20[15:8], rssi_chain0_sec40[23:16], rssi_chain0_sec80[31:24]
//	1	rssi_chain1_pri20[7:0], rssi_chain1_sec20[15:8], rssi_chain1_sec40[23:16], rssi_chain1_sec80[31:24]
//	2	rssi_chain2_pri20[7:0], rssi_chain2_sec20[15:8], rssi_chain2_sec40[23:16], rssi_chain2_sec80[31:24]
//	3	rssi_chain3_pri20[7:0], rssi_chain3_sec20[15:8], rssi_chain3_sec40[23:16], rssi_chain3_sec80[31:24]
//	4	rssi_comb[7:0], reserved_4a[23:8], is_greenfield[24], reserved_4b[31:25]
//	5	l_sig_rate[3:0], l_sig_rate_select[4], l_sig_length[16:5], l_sig_parity[17], l_sig_tail[23:18], preamble_type[31:24]
//	6	ht_sig_vht_sig_a_1[23:0], reserved_6[31:24]
//	7	ht_sig_vht_sig_a_2[23:0], txbf_h_info[24], reserved_7[31:25]
//	8	vht_sig_b[28:0], reserved_8[31:29]
//	9	service[15:0], reserved_9[31:16]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RX_PPDU_START 10

struct rx_ppdu_start {
    volatile uint32_t rssi_chain0_pri20               :  8, //[7:0]
                      rssi_chain0_sec20               :  8, //[15:8]
                      rssi_chain0_sec40               :  8, //[23:16]
                      rssi_chain0_sec80               :  8; //[31:24]
    volatile uint32_t rssi_chain1_pri20               :  8, //[7:0]
                      rssi_chain1_sec20               :  8, //[15:8]
                      rssi_chain1_sec40               :  8, //[23:16]
                      rssi_chain1_sec80               :  8; //[31:24]
    volatile uint32_t rssi_chain2_pri20               :  8, //[7:0]
                      rssi_chain2_sec20               :  8, //[15:8]
                      rssi_chain2_sec40               :  8, //[23:16]
                      rssi_chain2_sec80               :  8; //[31:24]
    volatile uint32_t rssi_chain3_pri20               :  8, //[7:0]
                      rssi_chain3_sec20               :  8, //[15:8]
                      rssi_chain3_sec40               :  8, //[23:16]
                      rssi_chain3_sec80               :  8; //[31:24]
    volatile uint32_t rssi_comb                       :  8, //[7:0]
                      reserved_4a                     : 16, //[23:8]
                      is_greenfield                   :  1, //[24]
                      reserved_4b                     :  7; //[31:25]
    volatile uint32_t l_sig_rate                      :  4, //[3:0]
                      l_sig_rate_select               :  1, //[4]
                      l_sig_length                    : 12, //[16:5]
                      l_sig_parity                    :  1, //[17]
                      l_sig_tail                      :  6, //[23:18]
                      preamble_type                   :  8; //[31:24]
    volatile uint32_t ht_sig_vht_sig_a_1              : 24, //[23:0]
                      reserved_6                      :  8; //[31:24]
    volatile uint32_t ht_sig_vht_sig_a_2              : 24, //[23:0]
                      txbf_h_info                     :  1, //[24]
                      reserved_7                      :  7; //[31:25]
    volatile uint32_t vht_sig_b                       : 29, //[28:0]
                      reserved_8                      :  3; //[31:29]
    volatile uint32_t service                         : 16, //[15:0]
                      reserved_9                      : 16; //[31:16]
};

/*

rssi_chain0_pri20
			RSSI of RX PPDU on chain 0 of primary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain0_sec20
			RSSI of RX PPDU on chain 0 of secondary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain0_sec40
			RSSI of RX PPDU on chain 0 of secondary 40 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain0_sec80
			RSSI of RX PPDU on chain 0 of secondary 80 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain1_pri20
			RSSI of RX PPDU on chain 1 of primary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain1_sec20
			RSSI of RX PPDU on chain 1 of secondary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain1_sec40
			RSSI of RX PPDU on chain 1 of secondary 40 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain1_sec80
			RSSI of RX PPDU on chain 1 of secondary 80 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain2_pri20
			RSSI of RX PPDU on chain 2 of primary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain2_sec20
			RSSI of RX PPDU on chain 2 of secondary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain2_sec40
			RSSI of RX PPDU on chain 2 of secondary 40 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain2_sec80
			RSSI of RX PPDU on chain 2 of secondary 80 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain3_pri20
			RSSI of RX PPDU on chain 3 of primary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain3_sec20
			RSSI of RX PPDU on chain 3 of secondary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain3_sec40
			RSSI of RX PPDU on chain 3 of secondary 40 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_chain3_sec80
			RSSI of RX PPDU on chain 3 of secondary 80 MHz bandwidth. 
			Value of 0x80 indicates invalid.

rssi_comb
			The combined RSSI of RX PPDU of all active chains and
			bandwidths.  Value of 0x80 indicates invalid.

reserved_4a
			Reserved: HW should fill with 0, FW should ignore.

is_greenfield
			TBD Ask Felix: Do we really support this?

reserved_4b
			Reserved: HW should fill with 0, FW should ignore.

l_sig_rate
			If l_sig_rate_select is 0:
			0x8: OFDM 48 Mbps
			0x9: OFDM 24 Mbps
			0xA: OFDM 12 Mbps
			0xB: OFDM 6 Mbps
			0xC: OFDM 54 Mbps
			0xD: OFDM 36 Mbps
			0xE: OFDM 18 Mbps
			0xF: OFDM 9 Mbps
			If l_sig_rate_select is 1:
			0x8: CCK 11 Mbps long preamble
			0x9: CCK 5.5 Mbps long preamble
			0xA: CCK 2 Mbps long preamble
			0xB: CCK 1 Mbps long preamble
			0xC: CCK 11 Mbps short preamble
			0xD: CCK 5.5 Mbps short preamble
			0xE: CCK 2 Mbps short preamble

l_sig_rate_select
			Legacy signal rate select.  If set then l_sig_rate indicates
			CCK rates.  If clear then l_sig_rate indicates OFDM rates.

l_sig_length
			Length of legacy frame in octets.

l_sig_parity
			Odd parity over l_sig_rate and l_sig_length (TBD Does it
			cover l_sig_rate_select?)

l_sig_tail
			Tail bits for Viterbi decoder

preamble_type
			Indicates the type of preamble ahead:
			0x4: Legacy (OFDM/CCK)
			0x8: HT
			0x9: HT with TxBF
			0xC: VHT
			0xD: VHT with TxBF
			0x80 - 0xFF: Reserved for special baseband data types such
				as radar and spectral scan.

ht_sig_vht_sig_a_1
			If preamble_type == 0x8 or 0x9
			HT-SIG (first 24 bits)
			If preamble_type == 0xC or 0xD
			VHT-SIG A (first 24 bits)
			Else
			Reserved

reserved_6
			Reserved: HW should fill with 0, FW should ignore.

ht_sig_vht_sig_a_2
			If preamble_type == 0x8 or 0x9
			HT-SIG (last 24 bits)
			If preamble_type == 0xC or 0xD
			VHT-SIG A (last 24 bits)
			Else
			Reserved

txbf_h_info
			Indicates that the packet data carries H information which
			is used for TxBF debug.

reserved_7
			Reserved: HW should fill with 0, FW should ignore.

vht_sig_b
			WiFi 1.0 and WiFi 2.0 will likely have this field to be all
			0s since the BB does not plan on decoding VHT SIG-B.

reserved_8
			Reserved: HW should fill with 0, FW should ignore.

service
			Service field from BB for OFDM, HT and VHT packets.  CCK
			packets will have service field of 0.

reserved_9
			Reserved: HW should fill with 0, FW should ignore.
*/


/* Description		RX_PPDU_START_0_RSSI_CHAIN0_PRI20
			RSSI of RX PPDU on chain 0 of primary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_0_RSSI_CHAIN0_PRI20_OFFSET                     0x00000000
#define RX_PPDU_START_0_RSSI_CHAIN0_PRI20_LSB                        0
#define RX_PPDU_START_0_RSSI_CHAIN0_PRI20_MASK                       0x000000ff

/* Description		RX_PPDU_START_0_RSSI_CHAIN0_SEC20
			RSSI of RX PPDU on chain 0 of secondary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_0_RSSI_CHAIN0_SEC20_OFFSET                     0x00000000
#define RX_PPDU_START_0_RSSI_CHAIN0_SEC20_LSB                        8
#define RX_PPDU_START_0_RSSI_CHAIN0_SEC20_MASK                       0x0000ff00

/* Description		RX_PPDU_START_0_RSSI_CHAIN0_SEC40
			RSSI of RX PPDU on chain 0 of secondary 40 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_0_RSSI_CHAIN0_SEC40_OFFSET                     0x00000000
#define RX_PPDU_START_0_RSSI_CHAIN0_SEC40_LSB                        16
#define RX_PPDU_START_0_RSSI_CHAIN0_SEC40_MASK                       0x00ff0000

/* Description		RX_PPDU_START_0_RSSI_CHAIN0_SEC80
			RSSI of RX PPDU on chain 0 of secondary 80 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_0_RSSI_CHAIN0_SEC80_OFFSET                     0x00000000
#define RX_PPDU_START_0_RSSI_CHAIN0_SEC80_LSB                        24
#define RX_PPDU_START_0_RSSI_CHAIN0_SEC80_MASK                       0xff000000

/* Description		RX_PPDU_START_1_RSSI_CHAIN1_PRI20
			RSSI of RX PPDU on chain 1 of primary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_1_RSSI_CHAIN1_PRI20_OFFSET                     0x00000004
#define RX_PPDU_START_1_RSSI_CHAIN1_PRI20_LSB                        0
#define RX_PPDU_START_1_RSSI_CHAIN1_PRI20_MASK                       0x000000ff

/* Description		RX_PPDU_START_1_RSSI_CHAIN1_SEC20
			RSSI of RX PPDU on chain 1 of secondary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_1_RSSI_CHAIN1_SEC20_OFFSET                     0x00000004
#define RX_PPDU_START_1_RSSI_CHAIN1_SEC20_LSB                        8
#define RX_PPDU_START_1_RSSI_CHAIN1_SEC20_MASK                       0x0000ff00

/* Description		RX_PPDU_START_1_RSSI_CHAIN1_SEC40
			RSSI of RX PPDU on chain 1 of secondary 40 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_1_RSSI_CHAIN1_SEC40_OFFSET                     0x00000004
#define RX_PPDU_START_1_RSSI_CHAIN1_SEC40_LSB                        16
#define RX_PPDU_START_1_RSSI_CHAIN1_SEC40_MASK                       0x00ff0000

/* Description		RX_PPDU_START_1_RSSI_CHAIN1_SEC80
			RSSI of RX PPDU on chain 1 of secondary 80 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_1_RSSI_CHAIN1_SEC80_OFFSET                     0x00000004
#define RX_PPDU_START_1_RSSI_CHAIN1_SEC80_LSB                        24
#define RX_PPDU_START_1_RSSI_CHAIN1_SEC80_MASK                       0xff000000

/* Description		RX_PPDU_START_2_RSSI_CHAIN2_PRI20
			RSSI of RX PPDU on chain 2 of primary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_2_RSSI_CHAIN2_PRI20_OFFSET                     0x00000008
#define RX_PPDU_START_2_RSSI_CHAIN2_PRI20_LSB                        0
#define RX_PPDU_START_2_RSSI_CHAIN2_PRI20_MASK                       0x000000ff

/* Description		RX_PPDU_START_2_RSSI_CHAIN2_SEC20
			RSSI of RX PPDU on chain 2 of secondary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_2_RSSI_CHAIN2_SEC20_OFFSET                     0x00000008
#define RX_PPDU_START_2_RSSI_CHAIN2_SEC20_LSB                        8
#define RX_PPDU_START_2_RSSI_CHAIN2_SEC20_MASK                       0x0000ff00

/* Description		RX_PPDU_START_2_RSSI_CHAIN2_SEC40
			RSSI of RX PPDU on chain 2 of secondary 40 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_2_RSSI_CHAIN2_SEC40_OFFSET                     0x00000008
#define RX_PPDU_START_2_RSSI_CHAIN2_SEC40_LSB                        16
#define RX_PPDU_START_2_RSSI_CHAIN2_SEC40_MASK                       0x00ff0000

/* Description		RX_PPDU_START_2_RSSI_CHAIN2_SEC80
			RSSI of RX PPDU on chain 2 of secondary 80 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_2_RSSI_CHAIN2_SEC80_OFFSET                     0x00000008
#define RX_PPDU_START_2_RSSI_CHAIN2_SEC80_LSB                        24
#define RX_PPDU_START_2_RSSI_CHAIN2_SEC80_MASK                       0xff000000

/* Description		RX_PPDU_START_3_RSSI_CHAIN3_PRI20
			RSSI of RX PPDU on chain 3 of primary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_3_RSSI_CHAIN3_PRI20_OFFSET                     0x0000000c
#define RX_PPDU_START_3_RSSI_CHAIN3_PRI20_LSB                        0
#define RX_PPDU_START_3_RSSI_CHAIN3_PRI20_MASK                       0x000000ff

/* Description		RX_PPDU_START_3_RSSI_CHAIN3_SEC20
			RSSI of RX PPDU on chain 3 of secondary 20 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_3_RSSI_CHAIN3_SEC20_OFFSET                     0x0000000c
#define RX_PPDU_START_3_RSSI_CHAIN3_SEC20_LSB                        8
#define RX_PPDU_START_3_RSSI_CHAIN3_SEC20_MASK                       0x0000ff00

/* Description		RX_PPDU_START_3_RSSI_CHAIN3_SEC40
			RSSI of RX PPDU on chain 3 of secondary 40 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_3_RSSI_CHAIN3_SEC40_OFFSET                     0x0000000c
#define RX_PPDU_START_3_RSSI_CHAIN3_SEC40_LSB                        16
#define RX_PPDU_START_3_RSSI_CHAIN3_SEC40_MASK                       0x00ff0000

/* Description		RX_PPDU_START_3_RSSI_CHAIN3_SEC80
			RSSI of RX PPDU on chain 3 of secondary 80 MHz bandwidth. 
			Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_3_RSSI_CHAIN3_SEC80_OFFSET                     0x0000000c
#define RX_PPDU_START_3_RSSI_CHAIN3_SEC80_LSB                        24
#define RX_PPDU_START_3_RSSI_CHAIN3_SEC80_MASK                       0xff000000

/* Description		RX_PPDU_START_4_RSSI_COMB
			The combined RSSI of RX PPDU of all active chains and
			bandwidths.  Value of 0x80 indicates invalid.
*/
#define RX_PPDU_START_4_RSSI_COMB_OFFSET                             0x00000010
#define RX_PPDU_START_4_RSSI_COMB_LSB                                0
#define RX_PPDU_START_4_RSSI_COMB_MASK                               0x000000ff

/* Description		RX_PPDU_START_4_RESERVED_4A
			Reserved: HW should fill with 0, FW should ignore.
*/
#define RX_PPDU_START_4_RESERVED_4A_OFFSET                           0x00000010
#define RX_PPDU_START_4_RESERVED_4A_LSB                              8
#define RX_PPDU_START_4_RESERVED_4A_MASK                             0x00ffff00

/* Description		RX_PPDU_START_4_IS_GREENFIELD
			TBD Ask Felix: Do we really support this?
*/
#define RX_PPDU_START_4_IS_GREENFIELD_OFFSET                         0x00000010
#define RX_PPDU_START_4_IS_GREENFIELD_LSB                            24
#define RX_PPDU_START_4_IS_GREENFIELD_MASK                           0x01000000

/* Description		RX_PPDU_START_4_RESERVED_4B
			Reserved: HW should fill with 0, FW should ignore.
*/
#define RX_PPDU_START_4_RESERVED_4B_OFFSET                           0x00000010
#define RX_PPDU_START_4_RESERVED_4B_LSB                              25
#define RX_PPDU_START_4_RESERVED_4B_MASK                             0xfe000000

/* Description		RX_PPDU_START_5_L_SIG_RATE
			If l_sig_rate_select is 0:
			0x8: OFDM 48 Mbps
			0x9: OFDM 24 Mbps
			0xA: OFDM 12 Mbps
			0xB: OFDM 6 Mbps
			0xC: OFDM 54 Mbps
			0xD: OFDM 36 Mbps
			0xE: OFDM 18 Mbps
			0xF: OFDM 9 Mbps
			If l_sig_rate_select is 1:
			0x8: CCK 11 Mbps long preamble
			0x9: CCK 5.5 Mbps long preamble
			0xA: CCK 2 Mbps long preamble
			0xB: CCK 1 Mbps long preamble
			0xC: CCK 11 Mbps short preamble
			0xD: CCK 5.5 Mbps short preamble
			0xE: CCK 2 Mbps short preamble
*/
#define RX_PPDU_START_5_L_SIG_RATE_OFFSET                            0x00000014
#define RX_PPDU_START_5_L_SIG_RATE_LSB                               0
#define RX_PPDU_START_5_L_SIG_RATE_MASK                              0x0000000f

/* Description		RX_PPDU_START_5_L_SIG_RATE_SELECT
			Legacy signal rate select.  If set then l_sig_rate indicates
			CCK rates.  If clear then l_sig_rate indicates OFDM rates.
*/
#define RX_PPDU_START_5_L_SIG_RATE_SELECT_OFFSET                     0x00000014
#define RX_PPDU_START_5_L_SIG_RATE_SELECT_LSB                        4
#define RX_PPDU_START_5_L_SIG_RATE_SELECT_MASK                       0x00000010

/* Description		RX_PPDU_START_5_L_SIG_LENGTH
			Length of legacy frame in octets.
*/
#define RX_PPDU_START_5_L_SIG_LENGTH_OFFSET                          0x00000014
#define RX_PPDU_START_5_L_SIG_LENGTH_LSB                             5
#define RX_PPDU_START_5_L_SIG_LENGTH_MASK                            0x0001ffe0

/* Description		RX_PPDU_START_5_L_SIG_PARITY
			Odd parity over l_sig_rate and l_sig_length (TBD Does it
			cover l_sig_rate_select?)
*/
#define RX_PPDU_START_5_L_SIG_PARITY_OFFSET                          0x00000014
#define RX_PPDU_START_5_L_SIG_PARITY_LSB                             17
#define RX_PPDU_START_5_L_SIG_PARITY_MASK                            0x00020000

/* Description		RX_PPDU_START_5_L_SIG_TAIL
			Tail bits for Viterbi decoder
*/
#define RX_PPDU_START_5_L_SIG_TAIL_OFFSET                            0x00000014
#define RX_PPDU_START_5_L_SIG_TAIL_LSB                               18
#define RX_PPDU_START_5_L_SIG_TAIL_MASK                              0x00fc0000

/* Description		RX_PPDU_START_5_PREAMBLE_TYPE
			Indicates the type of preamble ahead:
			0x4: Legacy (OFDM/CCK)
			0x8: HT
			0x9: HT with TxBF
			0xC: VHT
			0xD: VHT with TxBF
			0x80 - 0xFF: Reserved for special baseband data types such
				as radar and spectral scan.
*/
#define RX_PPDU_START_5_PREAMBLE_TYPE_OFFSET                         0x00000014
#define RX_PPDU_START_5_PREAMBLE_TYPE_LSB                            24
#define RX_PPDU_START_5_PREAMBLE_TYPE_MASK                           0xff000000

/* Description		RX_PPDU_START_6_HT_SIG_VHT_SIG_A_1
			If preamble_type == 0x8 or 0x9
			HT-SIG (first 24 bits)
			If preamble_type == 0xC or 0xD
			VHT-SIG A (first 24 bits)
			Else
			Reserved
*/
#define RX_PPDU_START_6_HT_SIG_VHT_SIG_A_1_OFFSET                    0x00000018
#define RX_PPDU_START_6_HT_SIG_VHT_SIG_A_1_LSB                       0
#define RX_PPDU_START_6_HT_SIG_VHT_SIG_A_1_MASK                      0x00ffffff

/* Description		RX_PPDU_START_6_RESERVED_6
			Reserved: HW should fill with 0, FW should ignore.
*/
#define RX_PPDU_START_6_RESERVED_6_OFFSET                            0x00000018
#define RX_PPDU_START_6_RESERVED_6_LSB                               24
#define RX_PPDU_START_6_RESERVED_6_MASK                              0xff000000

/* Description		RX_PPDU_START_7_HT_SIG_VHT_SIG_A_2
			If preamble_type == 0x8 or 0x9
			HT-SIG (last 24 bits)
			If preamble_type == 0xC or 0xD
			VHT-SIG A (last 24 bits)
			Else
			Reserved
*/
#define RX_PPDU_START_7_HT_SIG_VHT_SIG_A_2_OFFSET                    0x0000001c
#define RX_PPDU_START_7_HT_SIG_VHT_SIG_A_2_LSB                       0
#define RX_PPDU_START_7_HT_SIG_VHT_SIG_A_2_MASK                      0x00ffffff

/* Description		RX_PPDU_START_7_TXBF_H_INFO
			Indicates that the packet data carries H information which
			is used for TxBF debug.
*/
#define RX_PPDU_START_7_TXBF_H_INFO_OFFSET                           0x0000001c
#define RX_PPDU_START_7_TXBF_H_INFO_LSB                              24
#define RX_PPDU_START_7_TXBF_H_INFO_MASK                             0x01000000

/* Description		RX_PPDU_START_7_RESERVED_7
			Reserved: HW should fill with 0, FW should ignore.
*/
#define RX_PPDU_START_7_RESERVED_7_OFFSET                            0x0000001c
#define RX_PPDU_START_7_RESERVED_7_LSB                               25
#define RX_PPDU_START_7_RESERVED_7_MASK                              0xfe000000

/* Description		RX_PPDU_START_8_VHT_SIG_B
			WiFi 1.0 and WiFi 2.0 will likely have this field to be all
			0s since the BB does not plan on decoding VHT SIG-B.
*/
#define RX_PPDU_START_8_VHT_SIG_B_OFFSET                             0x00000020
#define RX_PPDU_START_8_VHT_SIG_B_LSB                                0
#define RX_PPDU_START_8_VHT_SIG_B_MASK                               0x1fffffff

/* Description		RX_PPDU_START_8_RESERVED_8
			Reserved: HW should fill with 0, FW should ignore.
*/
#define RX_PPDU_START_8_RESERVED_8_OFFSET                            0x00000020
#define RX_PPDU_START_8_RESERVED_8_LSB                               29
#define RX_PPDU_START_8_RESERVED_8_MASK                              0xe0000000

/* Description		RX_PPDU_START_9_SERVICE
			Service field from BB for OFDM, HT and VHT packets.  CCK
			packets will have service field of 0.
*/
#define RX_PPDU_START_9_SERVICE_OFFSET                               0x00000024
#define RX_PPDU_START_9_SERVICE_LSB                                  0
#define RX_PPDU_START_9_SERVICE_MASK                                 0x0000ffff

/* Description		RX_PPDU_START_9_RESERVED_9
			Reserved: HW should fill with 0, FW should ignore.
*/
#define RX_PPDU_START_9_RESERVED_9_OFFSET                            0x00000024
#define RX_PPDU_START_9_RESERVED_9_LSB                               16
#define RX_PPDU_START_9_RESERVED_9_MASK                              0xffff0000


#endif // _RX_PPDU_START_H_
