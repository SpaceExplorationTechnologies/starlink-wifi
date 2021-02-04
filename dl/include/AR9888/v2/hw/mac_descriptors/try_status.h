// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _TRY_STATUS_H_
#define _TRY_STATUS_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	timestamp[22:0], underrun[23], series[24], reserved_0[25], rts_bw[27:26], packet_bw[29:28], tx_rts[30], tx_packet[31]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_TRY_STATUS 1

struct try_status {
    volatile uint32_t timestamp                       : 23, //[22:0]
                      underrun                        :  1, //[23]
                      series                          :  1, //[24]
                      reserved_0                      :  1, //[25]
                      rts_bw                          :  2, //[27:26]
                      packet_bw                       :  2, //[29:28]
                      tx_rts                          :  1, //[30]
                      tx_packet                       :  1; //[31]
};

/*

timestamp
			The TSF value at the start of packet transmission minus 2
			usec for BB/radio latency.   23 bits is sufficient to
			indicate up to 8 sec before it wraps.  In the case of RTS
			enabled frames, it indicates the transmission time of the
			data frame.  RTS and CTS time and 2x SIFS time must be
			subtracted to indicate the RTS start time.  For CTS enabled
			frames subtract CTS time and SIFS time to indicate CTS start
			time.

underrun
			Indicates that an underrun occurred during the transmission
			attempt.

series
			Indicates the rate series of this attempt:
			0: series 0
			1: Series 1

reserved_0
			Reserved.

rts_bw
			Indicates the bandwidth used to transmit RTS.  Only valid if
			the 'rts_en' bit is also set.
			0: 20 MHz
			1: 40 MHz
			2: 80 MHz
			3: 160 MHz (Not supported in WiFi 1.0)

packet_bw
			Indicates the bandwidth used to transmit data paket.  Only
			valid if the packet bit is also set.
			0: 20 MHz
			1: 40 MHz
			2: 80 MHz
			3: 160 MHz (Not supported in WiFi 1.0)

tx_rts
			Try attempt used RTS sequence.

tx_packet
			Try attempt included a data transmission.
*/


/* Description		TRY_STATUS_0_TIMESTAMP
			The TSF value at the start of packet transmission minus 2
			usec for BB/radio latency.   23 bits is sufficient to
			indicate up to 8 sec before it wraps.  In the case of RTS
			enabled frames, it indicates the transmission time of the
			data frame.  RTS and CTS time and 2x SIFS time must be
			subtracted to indicate the RTS start time.  For CTS enabled
			frames subtract CTS time and SIFS time to indicate CTS start
			time.
*/
#define TRY_STATUS_0_TIMESTAMP_OFFSET                                0x00000000
#define TRY_STATUS_0_TIMESTAMP_LSB                                   0
#define TRY_STATUS_0_TIMESTAMP_MASK                                  0x007fffff

/* Description		TRY_STATUS_0_UNDERRUN
			Indicates that an underrun occurred during the transmission
			attempt.
*/
#define TRY_STATUS_0_UNDERRUN_OFFSET                                 0x00000000
#define TRY_STATUS_0_UNDERRUN_LSB                                    23
#define TRY_STATUS_0_UNDERRUN_MASK                                   0x00800000

/* Description		TRY_STATUS_0_SERIES
			Indicates the rate series of this attempt:
			0: series 0
			1: Series 1
*/
#define TRY_STATUS_0_SERIES_OFFSET                                   0x00000000
#define TRY_STATUS_0_SERIES_LSB                                      24
#define TRY_STATUS_0_SERIES_MASK                                     0x01000000

/* Description		TRY_STATUS_0_RESERVED_0
			Reserved.
*/
#define TRY_STATUS_0_RESERVED_0_OFFSET                               0x00000000
#define TRY_STATUS_0_RESERVED_0_LSB                                  25
#define TRY_STATUS_0_RESERVED_0_MASK                                 0x02000000

/* Description		TRY_STATUS_0_RTS_BW
			Indicates the bandwidth used to transmit RTS.  Only valid if
			the 'rts_en' bit is also set.
			0: 20 MHz
			1: 40 MHz
			2: 80 MHz
			3: 160 MHz (Not supported in WiFi 1.0)
*/
#define TRY_STATUS_0_RTS_BW_OFFSET                                   0x00000000
#define TRY_STATUS_0_RTS_BW_LSB                                      26
#define TRY_STATUS_0_RTS_BW_MASK                                     0x0c000000

/* Description		TRY_STATUS_0_PACKET_BW
			Indicates the bandwidth used to transmit data paket.  Only
			valid if the packet bit is also set.
			0: 20 MHz
			1: 40 MHz
			2: 80 MHz
			3: 160 MHz (Not supported in WiFi 1.0)
*/
#define TRY_STATUS_0_PACKET_BW_OFFSET                                0x00000000
#define TRY_STATUS_0_PACKET_BW_LSB                                   28
#define TRY_STATUS_0_PACKET_BW_MASK                                  0x30000000

/* Description		TRY_STATUS_0_TX_RTS
			Try attempt used RTS sequence.
*/
#define TRY_STATUS_0_TX_RTS_OFFSET                                   0x00000000
#define TRY_STATUS_0_TX_RTS_LSB                                      30
#define TRY_STATUS_0_TX_RTS_MASK                                     0x40000000

/* Description		TRY_STATUS_0_TX_PACKET
			Try attempt included a data transmission.
*/
#define TRY_STATUS_0_TX_PACKET_OFFSET                                0x00000000
#define TRY_STATUS_0_TX_PACKET_LSB                                   31
#define TRY_STATUS_0_TX_PACKET_MASK                                  0x80000000


#endif // _TRY_STATUS_H_
