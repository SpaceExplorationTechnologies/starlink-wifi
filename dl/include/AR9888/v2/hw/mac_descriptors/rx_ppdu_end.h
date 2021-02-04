// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _RX_PPDU_END_H_
#define _RX_PPDU_END_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	evm_p0[31:0]
//	1	evm_p1[31:0]
//	2	evm_p2[31:0]
//	3	evm_p3[31:0]
//	4	evm_p4[31:0]
//	5	evm_p5[31:0]
//	6	evm_p6[31:0]
//	7	evm_p7[31:0]
//	8	evm_p8[31:0]
//	9	evm_p9[31:0]
//	10	evm_p10[31:0]
//	11	evm_p11[31:0]
//	12	evm_p12[31:0]
//	13	evm_p13[31:0]
//	14	evm_p14[31:0]
//	15	evm_p15[31:0]
//	16	tsf_timestamp[31:0]
//	17	wb_timestamp[31:0]
//	18	locationing_timestamp[7:0], phy_err_code[15:8], phy_err[16], rx_location[17], txbf_h_info[18], reserved_18[31:19]
//	19	rx_antenna[23:0], tx_ht_vht_ack[24], bb_captured_channel[25], reserved_19[31:26]
//	20	bb_length[15:0], reserved_20[30:16], ppdu_done[31]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RX_PPDU_END 21

struct rx_ppdu_end {
    volatile uint32_t evm_p0                          : 32; //[31:0]
    volatile uint32_t evm_p1                          : 32; //[31:0]
    volatile uint32_t evm_p2                          : 32; //[31:0]
    volatile uint32_t evm_p3                          : 32; //[31:0]
    volatile uint32_t evm_p4                          : 32; //[31:0]
    volatile uint32_t evm_p5                          : 32; //[31:0]
    volatile uint32_t evm_p6                          : 32; //[31:0]
    volatile uint32_t evm_p7                          : 32; //[31:0]
    volatile uint32_t evm_p8                          : 32; //[31:0]
    volatile uint32_t evm_p9                          : 32; //[31:0]
    volatile uint32_t evm_p10                         : 32; //[31:0]
    volatile uint32_t evm_p11                         : 32; //[31:0]
    volatile uint32_t evm_p12                         : 32; //[31:0]
    volatile uint32_t evm_p13                         : 32; //[31:0]
    volatile uint32_t evm_p14                         : 32; //[31:0]
    volatile uint32_t evm_p15                         : 32; //[31:0]
    volatile uint32_t tsf_timestamp                   : 32; //[31:0]
    volatile uint32_t wb_timestamp                    : 32; //[31:0]
    volatile uint32_t locationing_timestamp           :  8, //[7:0]
                      phy_err_code                    :  8, //[15:8]
                      phy_err                         :  1, //[16]
                      rx_location                     :  1, //[17]
                      txbf_h_info                     :  1, //[18]
                      reserved_18                     : 13; //[31:19]
    volatile uint32_t rx_antenna                      : 24, //[23:0]
                      tx_ht_vht_ack                   :  1, //[24]
                      bb_captured_channel             :  1, //[25]
                      reserved_19                     :  6; //[31:26]
    volatile uint32_t bb_length                       : 16, //[15:0]
                      reserved_20                     : 15, //[30:16]
                      ppdu_done                       :  1; //[31]
};

/*

evm_p0
			EVM for pilot 0.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p1
			EVM for pilot 1.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p2
			EVM for pilot 2.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p3
			EVM for pilot 3.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p4
			EVM for pilot 4.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p5
			EVM for pilot 5.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p6
			EVM for pilot 6.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p7
			EVM for pilot 7.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p8
			EVM for pilot 8.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p9
			EVM for pilot 9.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p10
			EVM for pilot 10.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p11
			EVM for pilot 11.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p12
			EVM for pilot 12.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p13
			EVM for pilot 13.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p14
			EVM for pilot 14.  Contain EVM for streams: 0, 1, 2 and 3.

evm_p15
			EVM for pilot 15.  Contain EVM for streams: 0, 1, 2 and 3.

tsf_timestamp
			Receive TSF timestamp sampled on the rising edge of
			rx_clear.  For PHY errors this may be the current TSF when
			phy_error is asserted if the rx_clear does not assert before
			the end of the PHY error.

wb_timestamp
			WLAN/BT timestamp is a 1 usec resolution timestamp which
			does not get updated based on receive beacon like TSF.  The
			same rules for capturing tsf_timestamp are used to capture
			the wb_timestamp.

locationing_timestamp
			Timestamp used for locationing.  This timestamp is used to
			indicate fractions of usec.  For example if the MAC clock is
			running at 80 MHz, the timestamp will increment every 12.5
			nsec.  The value starts at 0 and increments to 79 and
			returns to 0 and repeats.  This information is valid for
			every PPDU.  This information can be used in conjunction
			with wb_timestamp to capture large delta times.

phy_err_code
			See the 1.10.8.1.2 for the list of the PHY error codes.

phy_err
			Indicates a PHY error was detected for this PPDU.

rx_location
			Indicates that location information was requested.  TBD: I'm
			not sure what the application for this is.

txbf_h_info
			Indicates that the packet data carries H information which
			is used for TxBF debug.

reserved_18
			Reserved: HW should fill with 0, FW should ignore.

rx_antenna
			Receive antenna value

tx_ht_vht_ack
			Indicates that a HT or VHT Ack/BA frame was transmitted in
			response to this receive packet.

bb_captured_channel
			Indicates that the BB has captured a channel dump.  FW can
			then read the channel dump memory.  This may indicate that
			the channel was captured either based on PCU setting the
			capture_channel bit  BB descriptor or FW setting the
			capture_channel mode bit.

reserved_19
			Reserved: HW should fill with 0, FW should ignore.

bb_length
			Indicates the number of bytes of baseband information for
			PPDUs where the BB descriptor preamble type is 0x80 to 0xFF
			which indicates that this is not a normal PPDU but rather
			contains baseband debug information.

reserved_20
			Reserved: HW should fill with 0, FW should ignore.

ppdu_done
			PPDU end status is only valid when ppdu_done bit is set. 
			Every time HW sets this bit in memory FW/SW must clear this
			bit in memory.  FW will initialize all the ppdu_done dword
			to 0.
*/


/* Description		RX_PPDU_END_0_EVM_P0
			EVM for pilot 0.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_0_EVM_P0_OFFSET                                  0x00000000
#define RX_PPDU_END_0_EVM_P0_LSB                                     0
#define RX_PPDU_END_0_EVM_P0_MASK                                    0xffffffff

/* Description		RX_PPDU_END_1_EVM_P1
			EVM for pilot 1.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_1_EVM_P1_OFFSET                                  0x00000004
#define RX_PPDU_END_1_EVM_P1_LSB                                     0
#define RX_PPDU_END_1_EVM_P1_MASK                                    0xffffffff

/* Description		RX_PPDU_END_2_EVM_P2
			EVM for pilot 2.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_2_EVM_P2_OFFSET                                  0x00000008
#define RX_PPDU_END_2_EVM_P2_LSB                                     0
#define RX_PPDU_END_2_EVM_P2_MASK                                    0xffffffff

/* Description		RX_PPDU_END_3_EVM_P3
			EVM for pilot 3.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_3_EVM_P3_OFFSET                                  0x0000000c
#define RX_PPDU_END_3_EVM_P3_LSB                                     0
#define RX_PPDU_END_3_EVM_P3_MASK                                    0xffffffff

/* Description		RX_PPDU_END_4_EVM_P4
			EVM for pilot 4.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_4_EVM_P4_OFFSET                                  0x00000010
#define RX_PPDU_END_4_EVM_P4_LSB                                     0
#define RX_PPDU_END_4_EVM_P4_MASK                                    0xffffffff

/* Description		RX_PPDU_END_5_EVM_P5
			EVM for pilot 5.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_5_EVM_P5_OFFSET                                  0x00000014
#define RX_PPDU_END_5_EVM_P5_LSB                                     0
#define RX_PPDU_END_5_EVM_P5_MASK                                    0xffffffff

/* Description		RX_PPDU_END_6_EVM_P6
			EVM for pilot 6.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_6_EVM_P6_OFFSET                                  0x00000018
#define RX_PPDU_END_6_EVM_P6_LSB                                     0
#define RX_PPDU_END_6_EVM_P6_MASK                                    0xffffffff

/* Description		RX_PPDU_END_7_EVM_P7
			EVM for pilot 7.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_7_EVM_P7_OFFSET                                  0x0000001c
#define RX_PPDU_END_7_EVM_P7_LSB                                     0
#define RX_PPDU_END_7_EVM_P7_MASK                                    0xffffffff

/* Description		RX_PPDU_END_8_EVM_P8
			EVM for pilot 8.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_8_EVM_P8_OFFSET                                  0x00000020
#define RX_PPDU_END_8_EVM_P8_LSB                                     0
#define RX_PPDU_END_8_EVM_P8_MASK                                    0xffffffff

/* Description		RX_PPDU_END_9_EVM_P9
			EVM for pilot 9.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_9_EVM_P9_OFFSET                                  0x00000024
#define RX_PPDU_END_9_EVM_P9_LSB                                     0
#define RX_PPDU_END_9_EVM_P9_MASK                                    0xffffffff

/* Description		RX_PPDU_END_10_EVM_P10
			EVM for pilot 10.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_10_EVM_P10_OFFSET                                0x00000028
#define RX_PPDU_END_10_EVM_P10_LSB                                   0
#define RX_PPDU_END_10_EVM_P10_MASK                                  0xffffffff

/* Description		RX_PPDU_END_11_EVM_P11
			EVM for pilot 11.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_11_EVM_P11_OFFSET                                0x0000002c
#define RX_PPDU_END_11_EVM_P11_LSB                                   0
#define RX_PPDU_END_11_EVM_P11_MASK                                  0xffffffff

/* Description		RX_PPDU_END_12_EVM_P12
			EVM for pilot 12.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_12_EVM_P12_OFFSET                                0x00000030
#define RX_PPDU_END_12_EVM_P12_LSB                                   0
#define RX_PPDU_END_12_EVM_P12_MASK                                  0xffffffff

/* Description		RX_PPDU_END_13_EVM_P13
			EVM for pilot 13.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_13_EVM_P13_OFFSET                                0x00000034
#define RX_PPDU_END_13_EVM_P13_LSB                                   0
#define RX_PPDU_END_13_EVM_P13_MASK                                  0xffffffff

/* Description		RX_PPDU_END_14_EVM_P14
			EVM for pilot 14.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_14_EVM_P14_OFFSET                                0x00000038
#define RX_PPDU_END_14_EVM_P14_LSB                                   0
#define RX_PPDU_END_14_EVM_P14_MASK                                  0xffffffff

/* Description		RX_PPDU_END_15_EVM_P15
			EVM for pilot 15.  Contain EVM for streams: 0, 1, 2 and 3.
*/
#define RX_PPDU_END_15_EVM_P15_OFFSET                                0x0000003c
#define RX_PPDU_END_15_EVM_P15_LSB                                   0
#define RX_PPDU_END_15_EVM_P15_MASK                                  0xffffffff

/* Description		RX_PPDU_END_16_TSF_TIMESTAMP
			Receive TSF timestamp sampled on the rising edge of
			rx_clear.  For PHY errors this may be the current TSF when
			phy_error is asserted if the rx_clear does not assert before
			the end of the PHY error.
*/
#define RX_PPDU_END_16_TSF_TIMESTAMP_OFFSET                          0x00000040
#define RX_PPDU_END_16_TSF_TIMESTAMP_LSB                             0
#define RX_PPDU_END_16_TSF_TIMESTAMP_MASK                            0xffffffff

/* Description		RX_PPDU_END_17_WB_TIMESTAMP
			WLAN/BT timestamp is a 1 usec resolution timestamp which
			does not get updated based on receive beacon like TSF.  The
			same rules for capturing tsf_timestamp are used to capture
			the wb_timestamp.
*/
#define RX_PPDU_END_17_WB_TIMESTAMP_OFFSET                           0x00000044
#define RX_PPDU_END_17_WB_TIMESTAMP_LSB                              0
#define RX_PPDU_END_17_WB_TIMESTAMP_MASK                             0xffffffff

/* Description		RX_PPDU_END_18_LOCATIONING_TIMESTAMP
			Timestamp used for locationing.  This timestamp is used to
			indicate fractions of usec.  For example if the MAC clock is
			running at 80 MHz, the timestamp will increment every 12.5
			nsec.  The value starts at 0 and increments to 79 and
			returns to 0 and repeats.  This information is valid for
			every PPDU.  This information can be used in conjunction
			with wb_timestamp to capture large delta times.
*/
#define RX_PPDU_END_18_LOCATIONING_TIMESTAMP_OFFSET                  0x00000048
#define RX_PPDU_END_18_LOCATIONING_TIMESTAMP_LSB                     0
#define RX_PPDU_END_18_LOCATIONING_TIMESTAMP_MASK                    0x000000ff

/* Description		RX_PPDU_END_18_PHY_ERR_CODE
			See the 1.10.8.1.2 for the list of the PHY error codes.
*/
#define RX_PPDU_END_18_PHY_ERR_CODE_OFFSET                           0x00000048
#define RX_PPDU_END_18_PHY_ERR_CODE_LSB                              8
#define RX_PPDU_END_18_PHY_ERR_CODE_MASK                             0x0000ff00

/* Description		RX_PPDU_END_18_PHY_ERR
			Indicates a PHY error was detected for this PPDU.
*/
#define RX_PPDU_END_18_PHY_ERR_OFFSET                                0x00000048
#define RX_PPDU_END_18_PHY_ERR_LSB                                   16
#define RX_PPDU_END_18_PHY_ERR_MASK                                  0x00010000

/* Description		RX_PPDU_END_18_RX_LOCATION
			Indicates that location information was requested.  TBD: I'm
			not sure what the application for this is.
*/
#define RX_PPDU_END_18_RX_LOCATION_OFFSET                            0x00000048
#define RX_PPDU_END_18_RX_LOCATION_LSB                               17
#define RX_PPDU_END_18_RX_LOCATION_MASK                              0x00020000

/* Description		RX_PPDU_END_18_TXBF_H_INFO
			Indicates that the packet data carries H information which
			is used for TxBF debug.
*/
#define RX_PPDU_END_18_TXBF_H_INFO_OFFSET                            0x00000048
#define RX_PPDU_END_18_TXBF_H_INFO_LSB                               18
#define RX_PPDU_END_18_TXBF_H_INFO_MASK                              0x00040000

/* Description		RX_PPDU_END_18_RESERVED_18
			Reserved: HW should fill with 0, FW should ignore.
*/
#define RX_PPDU_END_18_RESERVED_18_OFFSET                            0x00000048
#define RX_PPDU_END_18_RESERVED_18_LSB                               19
#define RX_PPDU_END_18_RESERVED_18_MASK                              0xfff80000

/* Description		RX_PPDU_END_19_RX_ANTENNA
			Receive antenna value
*/
#define RX_PPDU_END_19_RX_ANTENNA_OFFSET                             0x0000004c
#define RX_PPDU_END_19_RX_ANTENNA_LSB                                0
#define RX_PPDU_END_19_RX_ANTENNA_MASK                               0x00ffffff

/* Description		RX_PPDU_END_19_TX_HT_VHT_ACK
			Indicates that a HT or VHT Ack/BA frame was transmitted in
			response to this receive packet.
*/
#define RX_PPDU_END_19_TX_HT_VHT_ACK_OFFSET                          0x0000004c
#define RX_PPDU_END_19_TX_HT_VHT_ACK_LSB                             24
#define RX_PPDU_END_19_TX_HT_VHT_ACK_MASK                            0x01000000

/* Description		RX_PPDU_END_19_BB_CAPTURED_CHANNEL
			Indicates that the BB has captured a channel dump.  FW can
			then read the channel dump memory.  This may indicate that
			the channel was captured either based on PCU setting the
			capture_channel bit  BB descriptor or FW setting the
			capture_channel mode bit.
*/
#define RX_PPDU_END_19_BB_CAPTURED_CHANNEL_OFFSET                    0x0000004c
#define RX_PPDU_END_19_BB_CAPTURED_CHANNEL_LSB                       25
#define RX_PPDU_END_19_BB_CAPTURED_CHANNEL_MASK                      0x02000000

/* Description		RX_PPDU_END_19_RESERVED_19
			Reserved: HW should fill with 0, FW should ignore.
*/
#define RX_PPDU_END_19_RESERVED_19_OFFSET                            0x0000004c
#define RX_PPDU_END_19_RESERVED_19_LSB                               26
#define RX_PPDU_END_19_RESERVED_19_MASK                              0xfc000000

/* Description		RX_PPDU_END_20_BB_LENGTH
			Indicates the number of bytes of baseband information for
			PPDUs where the BB descriptor preamble type is 0x80 to 0xFF
			which indicates that this is not a normal PPDU but rather
			contains baseband debug information.
*/
#define RX_PPDU_END_20_BB_LENGTH_OFFSET                              0x00000050
#define RX_PPDU_END_20_BB_LENGTH_LSB                                 0
#define RX_PPDU_END_20_BB_LENGTH_MASK                                0x0000ffff

/* Description		RX_PPDU_END_20_RESERVED_20
			Reserved: HW should fill with 0, FW should ignore.
*/
#define RX_PPDU_END_20_RESERVED_20_OFFSET                            0x00000050
#define RX_PPDU_END_20_RESERVED_20_LSB                               16
#define RX_PPDU_END_20_RESERVED_20_MASK                              0x7fff0000

/* Description		RX_PPDU_END_20_PPDU_DONE
			PPDU end status is only valid when ppdu_done bit is set. 
			Every time HW sets this bit in memory FW/SW must clear this
			bit in memory.  FW will initialize all the ppdu_done dword
			to 0.
*/
#define RX_PPDU_END_20_PPDU_DONE_OFFSET                              0x00000050
#define RX_PPDU_END_20_PPDU_DONE_LSB                                 31
#define RX_PPDU_END_20_PPDU_DONE_MASK                                0x80000000


#endif // _RX_PPDU_END_H_
