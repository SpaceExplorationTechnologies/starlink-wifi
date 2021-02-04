// Copyright (c) 2012 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _PPDU_STATUS_H_
#define _PPDU_STATUS_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	ba_start_seq_num[11:0], tsf_time_filtered[12], wb_time_filtered[13], quiet_collision[14], ba_status[15], ba_look_ahead_offset[21:16], phy_error_filtered[22], used_warm_tx[23], power_save_filtered[24], reserved_0[26:25], adhoc_beacon_filtered[27], ba_look_ahead[28], peer_filtered[29], first_txop_filtered[30], tx_ok[31]
//	1	ba_bitmap_31_0[31:0]
//	2	ba_bitmap_63_32[31:0]
//	3	ack_location_timestamp[7:0], ack_wb_timestamp[31:8]
//	4	wb_timestamp[31:0]
//	5	data_tries_cnt_s0_bw20[3:0], data_tries_cnt_s0_bw40[7:4], data_tries_cnt_s0_bw80[11:8], data_tries_cnt_s0_bw160[15:12], data_tries_cnt_s1_bw20[19:16], data_tries_cnt_s1_bw40[23:20], data_tries_cnt_s1_bw80[27:24], data_tries_cnt_s1_bw160[31:28]
//	6	rts_tries_cnt_s0_bw20[3:0], rts_tries_cnt_s0_bw40[7:4], rts_tries_cnt_s0_bw80[11:8], rts_tries_cnt_s0_bw160[15:12], rts_tries_cnt_s1_bw20[19:16], rts_tries_cnt_s1_bw40[23:20], rts_tries_cnt_s1_bw80[27:24], rts_tries_cnt_s1_bw160[31:28]
//	7	ack_rssi_chain0_pri20[7:0], ack_rssi_chain0_sec20[15:8], ack_rssi_chain0_sec40[23:16], ack_rssi_chain0_sec80[31:24]
//	8	ack_rssi_chain1_pri20[7:0], ack_rssi_chain1_sec20[15:8], ack_rssi_chain1_sec40[23:16], ack_rssi_chain1_sec80[31:24]
//	9	ack_rssi_chain2_pri20[7:0], ack_rssi_chain2_sec20[15:8], ack_rssi_chain2_sec40[23:16], ack_rssi_chain2_sec80[31:24]
//	10	ack_rssi_chain3_pri20[7:0], ack_rssi_chain3_sec20[15:8], ack_rssi_chain3_sec40[23:16], ack_rssi_chain3_sec80[31:24]
//	11	ack_rssi_ave[7:0], locationing_timestamp[15:8], tx_qcu_num[19:16], agg_underrun[20], first_pkt_underrun[21], reserved_11a[22], qcu_paused[23], total_tries[28:24], reserved_11b[30:29], tx_done[31]
//	12	underrun_offset[5:0], reserved_12a[7:6], phy_error_code[15:8], reserved_12b[31:16]
//	13	reserved_13[31:0]
//	14	reserved_14[31:0]
//	15	reserved_15[31:0]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_PPDU_STATUS 16

struct ppdu_status {
    volatile uint32_t ba_start_seq_num                : 12, //[11:0]
                      tsf_time_filtered               :  1, //[12]
                      wb_time_filtered                :  1, //[13]
                      quiet_collision                 :  1, //[14]
                      ba_status                       :  1, //[15]
                      ba_look_ahead_offset            :  6, //[21:16]
                      phy_error_filtered              :  1, //[22]
                      used_warm_tx                    :  1, //[23]
                      power_save_filtered             :  1, //[24]
                      reserved_0                      :  2, //[26:25]
                      adhoc_beacon_filtered           :  1, //[27]
                      ba_look_ahead                   :  1, //[28]
                      peer_filtered                   :  1, //[29]
                      first_txop_filtered             :  1, //[30]
                      tx_ok                           :  1; //[31]
    volatile uint32_t ba_bitmap_31_0                  : 32; //[31:0]
    volatile uint32_t ba_bitmap_63_32                 : 32; //[31:0]
    volatile uint32_t ack_location_timestamp          :  8, //[7:0]
                      ack_wb_timestamp                : 24; //[31:8]
    volatile uint32_t wb_timestamp                    : 32; //[31:0]
    volatile uint32_t data_tries_cnt_s0_bw20          :  4, //[3:0]
                      data_tries_cnt_s0_bw40          :  4, //[7:4]
                      data_tries_cnt_s0_bw80          :  4, //[11:8]
                      data_tries_cnt_s0_bw160         :  4, //[15:12]
                      data_tries_cnt_s1_bw20          :  4, //[19:16]
                      data_tries_cnt_s1_bw40          :  4, //[23:20]
                      data_tries_cnt_s1_bw80          :  4, //[27:24]
                      data_tries_cnt_s1_bw160         :  4; //[31:28]
    volatile uint32_t rts_tries_cnt_s0_bw20           :  4, //[3:0]
                      rts_tries_cnt_s0_bw40           :  4, //[7:4]
                      rts_tries_cnt_s0_bw80           :  4, //[11:8]
                      rts_tries_cnt_s0_bw160          :  4, //[15:12]
                      rts_tries_cnt_s1_bw20           :  4, //[19:16]
                      rts_tries_cnt_s1_bw40           :  4, //[23:20]
                      rts_tries_cnt_s1_bw80           :  4, //[27:24]
                      rts_tries_cnt_s1_bw160          :  4; //[31:28]
    volatile uint32_t ack_rssi_chain0_pri20           :  8, //[7:0]
                      ack_rssi_chain0_sec20           :  8, //[15:8]
                      ack_rssi_chain0_sec40           :  8, //[23:16]
                      ack_rssi_chain0_sec80           :  8; //[31:24]
    volatile uint32_t ack_rssi_chain1_pri20           :  8, //[7:0]
                      ack_rssi_chain1_sec20           :  8, //[15:8]
                      ack_rssi_chain1_sec40           :  8, //[23:16]
                      ack_rssi_chain1_sec80           :  8; //[31:24]
    volatile uint32_t ack_rssi_chain2_pri20           :  8, //[7:0]
                      ack_rssi_chain2_sec20           :  8, //[15:8]
                      ack_rssi_chain2_sec40           :  8, //[23:16]
                      ack_rssi_chain2_sec80           :  8; //[31:24]
    volatile uint32_t ack_rssi_chain3_pri20           :  8, //[7:0]
                      ack_rssi_chain3_sec20           :  8, //[15:8]
                      ack_rssi_chain3_sec40           :  8, //[23:16]
                      ack_rssi_chain3_sec80           :  8; //[31:24]
    volatile uint32_t ack_rssi_ave                    :  8, //[7:0]
                      locationing_timestamp           :  8, //[15:8]
                      tx_qcu_num                      :  4, //[19:16]
                      agg_underrun                    :  1, //[20]
                      first_pkt_underrun              :  1, //[21]
                      reserved_11a                    :  1, //[22]
                      qcu_paused                      :  1, //[23]
                      total_tries                     :  5, //[28:24]
                      reserved_11b                    :  2, //[30:29]
                      tx_done                         :  1; //[31]
    volatile uint32_t underrun_offset                 :  6, //[5:0]
                      reserved_12a                    :  2, //[7:6]
                      phy_error_code                  :  8, //[15:8]
                      reserved_12b                    : 16; //[31:16]
    volatile uint32_t reserved_13                     : 32; //[31:0]
    volatile uint32_t reserved_14                     : 32; //[31:0]
    volatile uint32_t reserved_15                     : 32; //[31:0]
};

/*

ba_start_seq_num
			Starting block Ack sequence number of the response BA.  Only
			valid when 'ba_status' is set

tsf_time_filtered
			Indicates that this packet was filtered due to
			'tsf_filter_time' from the TX PPDU control descriptor
			exceeding the internal TSF timer value.

wb_time_filtered
			Indicates that this packet was filtered due to
			'wb_filter_time' from the TX PPDU control descriptor
			exceeding the internal WB timer value.

quiet_collision
			Indicates that this packet transmission attempt failed due
			to quiet collision.  This indicates that this attempt should
			be forgotten by the TX DMA and should not add to the retry
			count.  This is used by the TX DMA and will not be SW
			visible.

ba_status
			Set on successful reception of BA.  The 'ba_tid' contains
			the valid TID, 'ba_start_seq_num' contains the valid
			starting sequence number and 'ba_bitmap_0_31' and
			'ba_bitmap_32_63' contain valid bitmap for the received
			block Ack.

ba_look_ahead_offset
			Indicates the offset from the 'seq_num' (starting sequence
			number in the BA) of the last frame which was transmitted
			before truncated due to BT coexistance truncation.  This
			information is used by FW to mask out the failures in the BA
			bitmap status which should not be considered real failures
			for rate adaptation.  Only valid for A-MPDU aggregates and
			when the 'ba_look_ahead'  bit is set

phy_error_filtered
			The TX frame was filtered due to a PHY error.  See the
			phy_error_code field below.

used_warm_tx
			If set indicates that this PPDU was transmitted with warm
			TX.

power_save_filtered
			The TX frame was filtered due to the power_save bit being
			set in the peer table entry.

reserved_0
			Reserved: HW should fill with 0, FW should ignore.

adhoc_beacon_filtered
			Indicates that this PPDU was filtered due because the adhoc
			beacon was filtered since another STA's beacon was
			successfully received.

ba_look_ahead
			Indicate that truncation of the frame has occurred due to BT
			coexistence.  Will only be set in A-MPDU

peer_filtered
			Indicates that this packet was filtered due to the
			qcu_filter bit in the peer_entry and the qcu_num in the
			tx_ppdu_start. 

first_txop_filtered
			Indicates that this packet was filtered because this PPDU
			was the first PPDU of a TXOP and the full duration of the
			packet sequence exceeded the TXOP value.  Filter will only
			occur if the mode bit MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT
			is not set.

tx_ok
			Indicates successful packet transmit.  When no_ack is not
			set in the TX PPDU control descriptor, it indicates that a
			successful Ack was received for the non-A-MPDU or successful
			block Ack was received for the A-MPDU.

ba_bitmap_31_0
			The lower 32 bits of the response BA bitmap.
			Only valid when 'ba_status' is set.

ba_bitmap_63_32
			The upper 32 bits of the response BA bitmap.
			Only valid when 'ba_status' is set.

ack_location_timestamp
			Timestamp of the receive Ack/BA response frame used for
			locationing.  This timestamp is used to indicate fractions
			of usec.  For example if the MAC clock is running at 80 MHz,
			the timestamp will increment every 12.5 nsec.  The value
			starts at 0 and increments to 79 and returns to 0 and
			repeats.  This information is valid for every PPDU.  This
			information can be used in conjunction with
			ack_wb_timestamp.

ack_wb_timestamp
			Lower 24 bits of the WLAN/BT timestamp of the receive Ack/BA
			response frame.

wb_timestamp
			WLAN/BT timestamp is a 1 usec resolution timestamp which
			does not get updated based on receive beacon like TSF.

data_tries_cnt_s0_bw20
			Data tries count for rate series 0 at 20 MHz bandwidth.

data_tries_cnt_s0_bw40
			Data tries count for rate series 0 at 40 MHz bandwidth.

data_tries_cnt_s0_bw80
			Data tries count for rate series 0 at 80 MHz bandwidth.

data_tries_cnt_s0_bw160
			Data tries count for rate series 0 at 160 MHz bandwidth.

data_tries_cnt_s1_bw20
			Data tries count for rate series 1 at 20 MHz bandwidth.

data_tries_cnt_s1_bw40
			Data tries count for rate series 1 at 40 MHz bandwidth.

data_tries_cnt_s1_bw80
			Data tries count for rate series 1 at 80 MHz bandwidth.

data_tries_cnt_s1_bw160
			Data tries count for rate series 1 at 160 MHz bandwidth.

rts_tries_cnt_s0_bw20
			RTS tries count for rate series 0 at 20 MHz bandwidth.

rts_tries_cnt_s0_bw40
			RTS tries count for rate series 0 at 40 MHz bandwidth.

rts_tries_cnt_s0_bw80
			RTS tries count for rate series 0 at 80 MHz bandwidth.

rts_tries_cnt_s0_bw160
			RTS tries count for rate series 0 at 160 MHz bandwidth.

rts_tries_cnt_s1_bw20
			RTS tries count for rate series 1 at 20 MHz bandwidth.

rts_tries_cnt_s1_bw40
			RTS tries count for rate series 1 at 40 MHz bandwidth.

rts_tries_cnt_s1_bw80
			RTS tries count for rate series 1 at 80 MHz bandwidth.

rts_tries_cnt_s1_bw160
			RTS tries count for rate series 1 at 160 MHz bandwidth.

ack_rssi_chain0_pri20
			RSSI of Ack on chain 0 of primary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain0_sec20
			RSSI of Ack on chain 0 of secondary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain0_sec40
			RSSI of Ack on chain 0 of secondary 40 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain0_sec80
			RSSI of Ack on chain 0 of secondary 80 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain1_pri20
			RSSI of Ack on chain 1 of primary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain1_sec20
			RSSI of Ack on chain 1 of secondary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain1_sec40
			RSSI of Ack on chain 1 of secondary 40 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain1_sec80
			RSSI of Ack on chain 1 of secondary 80 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain2_pri20
			RSSI of Ack on chain 2 of primary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain2_sec20
			RSSI of Ack on chain 2 of secondary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain2_sec40
			RSSI of Ack on chain 2 of secondary 40 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain2_sec80
			RSSI of Ack on chain 2 of secondary 80 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain3_pri20
			RSSI of Ack on chain 3 of primary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain3_sec20
			RSSI of Ack on chain 3 of secondary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain3_sec40
			RSSI of Ack on chain 3 of secondary 40 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_chain3_sec80
			RSSI of Ack on chain 3 of secondary 80 MHz bandwidth.  Value
			of 0x80 indicates invalid.

ack_rssi_ave
			RSSI of Ack of all active chains and bandwidths.
			Value of 0x80 indicates invalid.

locationing_timestamp
			Timestamp used for locationing.  This timestamp is used to
			indicate fractions of usec.  For example if the MAC clock is
			running at 80 MHz, the timestamp will increment every 12.5
			nsec.  The value starts at 0 and increments to 79 and
			returns to 0 and repeats.  This information is valid for
			every PPDU.  This information can be used in conjunction
			with wb_timestamp to capture large delta times.

tx_qcu_num
			Indicates the QCU number of this status.  This is used by FW
			to identify the TX PPDU start descriptor associated with
			this TX PPDU end descriptor.

agg_underrun
			Indicates underrun during the transmission of an aggregate.

first_pkt_underrun
			Set when an underrun occurs on a stand-along packet or the
			first packet of an A-MPDU.

reserved_11a
			Reserved: HW should fill with 0, FW should ignore.

qcu_paused
			Indicates that this QCU has been paused due to excessive
			retry.  This pause condition is only possible when

total_tries
			Indicates the total number of tries.  For example if the
			total_tires is 3, then tries_01 and tries_02 will indicate
			the first 2 attempt and then tries_last will indicate the
			status of the last attempt.

reserved_11b
			Reserved: HW should fill with 0, FW should ignore.

tx_done
			Indicates the validity of the the tx_ppdu_end status
			information.  This bit must be in the last octet of
			tx_ppdu_end.

underrun_offset
			Indicates the offset from the 'seq_num' (starting sequence
			number in the BA) of the first frame which was not
			transmitted due to underrun condition.  This information can
			be used to diagnose underrun conditions.  This information
			can be used by FW to mask out the failure in the BA bitmap
			status which sould not be considered real failures for rate
			adaptation.  Only valid for A-MPDU aggregates and when the
			'agg_underrun' bit is set.

reserved_12a
			Reserved: HW should fill with 0, FW should ignore.

phy_error_code
			The PHY error code which caused the transmit frame to be
			filtered.
			0: ERROR_TX_UNDERRUN
			1: TX_CHAIN_MASK_ZERO
			2: TX_EXTRA_SYM_MISMATCH
			3: TX_VHT_LENGTH_NOT_MULTIPLE_OF_3
			8: TX_BW_MISMATCH
			9: TX_VHT_RATE_ILLEGAL
			All other encodings are reserved

reserved_12b
			Reserved: HW should fill with 0, FW should ignore.

reserved_13
			Reserved: HW should fill with 0, FW should ignore.

reserved_14
			Reserved: HW should fill with 0, FW should ignore.

reserved_15
			Reserved: HW should fill with 0, FW should ignore.
*/


/* Description		PPDU_STATUS_0_BA_START_SEQ_NUM
			Starting block Ack sequence number of the response BA.  Only
			valid when 'ba_status' is set
*/
#define PPDU_STATUS_0_BA_START_SEQ_NUM_OFFSET                        0x00000000
#define PPDU_STATUS_0_BA_START_SEQ_NUM_LSB                           0
#define PPDU_STATUS_0_BA_START_SEQ_NUM_MASK                          0x00000fff

/* Description		PPDU_STATUS_0_TSF_TIME_FILTERED
			Indicates that this packet was filtered due to
			'tsf_filter_time' from the TX PPDU control descriptor
			exceeding the internal TSF timer value.
*/
#define PPDU_STATUS_0_TSF_TIME_FILTERED_OFFSET                       0x00000000
#define PPDU_STATUS_0_TSF_TIME_FILTERED_LSB                          12
#define PPDU_STATUS_0_TSF_TIME_FILTERED_MASK                         0x00001000

/* Description		PPDU_STATUS_0_WB_TIME_FILTERED
			Indicates that this packet was filtered due to
			'wb_filter_time' from the TX PPDU control descriptor
			exceeding the internal WB timer value.
*/
#define PPDU_STATUS_0_WB_TIME_FILTERED_OFFSET                        0x00000000
#define PPDU_STATUS_0_WB_TIME_FILTERED_LSB                           13
#define PPDU_STATUS_0_WB_TIME_FILTERED_MASK                          0x00002000

/* Description		PPDU_STATUS_0_QUIET_COLLISION
			Indicates that this packet transmission attempt failed due
			to quiet collision.  This indicates that this attempt should
			be forgotten by the TX DMA and should not add to the retry
			count.  This is used by the TX DMA and will not be SW
			visible.
*/
#define PPDU_STATUS_0_QUIET_COLLISION_OFFSET                         0x00000000
#define PPDU_STATUS_0_QUIET_COLLISION_LSB                            14
#define PPDU_STATUS_0_QUIET_COLLISION_MASK                           0x00004000

/* Description		PPDU_STATUS_0_BA_STATUS
			Set on successful reception of BA.  The 'ba_tid' contains
			the valid TID, 'ba_start_seq_num' contains the valid
			starting sequence number and 'ba_bitmap_0_31' and
			'ba_bitmap_32_63' contain valid bitmap for the received
			block Ack.
*/
#define PPDU_STATUS_0_BA_STATUS_OFFSET                               0x00000000
#define PPDU_STATUS_0_BA_STATUS_LSB                                  15
#define PPDU_STATUS_0_BA_STATUS_MASK                                 0x00008000

/* Description		PPDU_STATUS_0_BA_LOOK_AHEAD_OFFSET
			Indicates the offset from the 'seq_num' (starting sequence
			number in the BA) of the last frame which was transmitted
			before truncated due to BT coexistance truncation.  This
			information is used by FW to mask out the failures in the BA
			bitmap status which should not be considered real failures
			for rate adaptation.  Only valid for A-MPDU aggregates and
			when the 'ba_look_ahead'  bit is set
*/
#define PPDU_STATUS_0_BA_LOOK_AHEAD_OFFSET_OFFSET                    0x00000000
#define PPDU_STATUS_0_BA_LOOK_AHEAD_OFFSET_LSB                       16
#define PPDU_STATUS_0_BA_LOOK_AHEAD_OFFSET_MASK                      0x003f0000

/* Description		PPDU_STATUS_0_PHY_ERROR_FILTERED
			The TX frame was filtered due to a PHY error.  See the
			phy_error_code field below.
*/
#define PPDU_STATUS_0_PHY_ERROR_FILTERED_OFFSET                      0x00000000
#define PPDU_STATUS_0_PHY_ERROR_FILTERED_LSB                         22
#define PPDU_STATUS_0_PHY_ERROR_FILTERED_MASK                        0x00400000

/* Description		PPDU_STATUS_0_USED_WARM_TX
			If set indicates that this PPDU was transmitted with warm
			TX.
*/
#define PPDU_STATUS_0_USED_WARM_TX_OFFSET                            0x00000000
#define PPDU_STATUS_0_USED_WARM_TX_LSB                               23
#define PPDU_STATUS_0_USED_WARM_TX_MASK                              0x00800000

/* Description		PPDU_STATUS_0_POWER_SAVE_FILTERED
			The TX frame was filtered due to the power_save bit being
			set in the peer table entry.
*/
#define PPDU_STATUS_0_POWER_SAVE_FILTERED_OFFSET                     0x00000000
#define PPDU_STATUS_0_POWER_SAVE_FILTERED_LSB                        24
#define PPDU_STATUS_0_POWER_SAVE_FILTERED_MASK                       0x01000000

/* Description		PPDU_STATUS_0_RESERVED_0
			Reserved: HW should fill with 0, FW should ignore.
*/
#define PPDU_STATUS_0_RESERVED_0_OFFSET                              0x00000000
#define PPDU_STATUS_0_RESERVED_0_LSB                                 25
#define PPDU_STATUS_0_RESERVED_0_MASK                                0x06000000

/* Description		PPDU_STATUS_0_ADHOC_BEACON_FILTERED
			Indicates that this PPDU was filtered due because the adhoc
			beacon was filtered since another STA's beacon was
			successfully received.
*/
#define PPDU_STATUS_0_ADHOC_BEACON_FILTERED_OFFSET                   0x00000000
#define PPDU_STATUS_0_ADHOC_BEACON_FILTERED_LSB                      27
#define PPDU_STATUS_0_ADHOC_BEACON_FILTERED_MASK                     0x08000000

/* Description		PPDU_STATUS_0_BA_LOOK_AHEAD
			Indicate that truncation of the frame has occurred due to BT
			coexistence.  Will only be set in A-MPDU
*/
#define PPDU_STATUS_0_BA_LOOK_AHEAD_OFFSET                           0x00000000
#define PPDU_STATUS_0_BA_LOOK_AHEAD_LSB                              28
#define PPDU_STATUS_0_BA_LOOK_AHEAD_MASK                             0x10000000

/* Description		PPDU_STATUS_0_PEER_FILTERED
			Indicates that this packet was filtered due to the
			qcu_filter bit in the peer_entry and the qcu_num in the
			tx_ppdu_start. 
*/
#define PPDU_STATUS_0_PEER_FILTERED_OFFSET                           0x00000000
#define PPDU_STATUS_0_PEER_FILTERED_LSB                              29
#define PPDU_STATUS_0_PEER_FILTERED_MASK                             0x20000000

/* Description		PPDU_STATUS_0_FIRST_TXOP_FILTERED
			Indicates that this packet was filtered because this PPDU
			was the first PPDU of a TXOP and the full duration of the
			packet sequence exceeded the TXOP value.  Filter will only
			occur if the mode bit MAC_PCU_MISC_MODE2_IGNORE_TXOP_1ST_PKT
			is not set.
*/
#define PPDU_STATUS_0_FIRST_TXOP_FILTERED_OFFSET                     0x00000000
#define PPDU_STATUS_0_FIRST_TXOP_FILTERED_LSB                        30
#define PPDU_STATUS_0_FIRST_TXOP_FILTERED_MASK                       0x40000000

/* Description		PPDU_STATUS_0_TX_OK
			Indicates successful packet transmit.  When no_ack is not
			set in the TX PPDU control descriptor, it indicates that a
			successful Ack was received for the non-A-MPDU or successful
			block Ack was received for the A-MPDU.
*/
#define PPDU_STATUS_0_TX_OK_OFFSET                                   0x00000000
#define PPDU_STATUS_0_TX_OK_LSB                                      31
#define PPDU_STATUS_0_TX_OK_MASK                                     0x80000000

/* Description		PPDU_STATUS_1_BA_BITMAP_31_0
			The lower 32 bits of the response BA bitmap.
			Only valid when 'ba_status' is set.
*/
#define PPDU_STATUS_1_BA_BITMAP_31_0_OFFSET                          0x00000004
#define PPDU_STATUS_1_BA_BITMAP_31_0_LSB                             0
#define PPDU_STATUS_1_BA_BITMAP_31_0_MASK                            0xffffffff

/* Description		PPDU_STATUS_2_BA_BITMAP_63_32
			The upper 32 bits of the response BA bitmap.
			Only valid when 'ba_status' is set.
*/
#define PPDU_STATUS_2_BA_BITMAP_63_32_OFFSET                         0x00000008
#define PPDU_STATUS_2_BA_BITMAP_63_32_LSB                            0
#define PPDU_STATUS_2_BA_BITMAP_63_32_MASK                           0xffffffff

/* Description		PPDU_STATUS_3_ACK_LOCATION_TIMESTAMP
			Timestamp of the receive Ack/BA response frame used for
			locationing.  This timestamp is used to indicate fractions
			of usec.  For example if the MAC clock is running at 80 MHz,
			the timestamp will increment every 12.5 nsec.  The value
			starts at 0 and increments to 79 and returns to 0 and
			repeats.  This information is valid for every PPDU.  This
			information can be used in conjunction with
			ack_wb_timestamp.
*/
#define PPDU_STATUS_3_ACK_LOCATION_TIMESTAMP_OFFSET                  0x0000000c
#define PPDU_STATUS_3_ACK_LOCATION_TIMESTAMP_LSB                     0
#define PPDU_STATUS_3_ACK_LOCATION_TIMESTAMP_MASK                    0x000000ff

/* Description		PPDU_STATUS_3_ACK_WB_TIMESTAMP
			Lower 24 bits of the WLAN/BT timestamp of the receive Ack/BA
			response frame.
*/
#define PPDU_STATUS_3_ACK_WB_TIMESTAMP_OFFSET                        0x0000000c
#define PPDU_STATUS_3_ACK_WB_TIMESTAMP_LSB                           8
#define PPDU_STATUS_3_ACK_WB_TIMESTAMP_MASK                          0xffffff00

/* Description		PPDU_STATUS_4_WB_TIMESTAMP
			WLAN/BT timestamp is a 1 usec resolution timestamp which
			does not get updated based on receive beacon like TSF.
*/
#define PPDU_STATUS_4_WB_TIMESTAMP_OFFSET                            0x00000010
#define PPDU_STATUS_4_WB_TIMESTAMP_LSB                               0
#define PPDU_STATUS_4_WB_TIMESTAMP_MASK                              0xffffffff

/* Description		PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW20
			Data tries count for rate series 0 at 20 MHz bandwidth.
*/
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW20_OFFSET                  0x00000014
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW20_LSB                     0
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW20_MASK                    0x0000000f

/* Description		PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW40
			Data tries count for rate series 0 at 40 MHz bandwidth.
*/
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW40_OFFSET                  0x00000014
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW40_LSB                     4
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW40_MASK                    0x000000f0

/* Description		PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW80
			Data tries count for rate series 0 at 80 MHz bandwidth.
*/
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW80_OFFSET                  0x00000014
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW80_LSB                     8
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW80_MASK                    0x00000f00

/* Description		PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW160
			Data tries count for rate series 0 at 160 MHz bandwidth.
*/
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW160_OFFSET                 0x00000014
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW160_LSB                    12
#define PPDU_STATUS_5_DATA_TRIES_CNT_S0_BW160_MASK                   0x0000f000

/* Description		PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW20
			Data tries count for rate series 1 at 20 MHz bandwidth.
*/
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW20_OFFSET                  0x00000014
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW20_LSB                     16
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW20_MASK                    0x000f0000

/* Description		PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW40
			Data tries count for rate series 1 at 40 MHz bandwidth.
*/
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW40_OFFSET                  0x00000014
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW40_LSB                     20
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW40_MASK                    0x00f00000

/* Description		PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW80
			Data tries count for rate series 1 at 80 MHz bandwidth.
*/
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW80_OFFSET                  0x00000014
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW80_LSB                     24
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW80_MASK                    0x0f000000

/* Description		PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW160
			Data tries count for rate series 1 at 160 MHz bandwidth.
*/
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW160_OFFSET                 0x00000014
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW160_LSB                    28
#define PPDU_STATUS_5_DATA_TRIES_CNT_S1_BW160_MASK                   0xf0000000

/* Description		PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW20
			RTS tries count for rate series 0 at 20 MHz bandwidth.
*/
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW20_OFFSET                   0x00000018
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW20_LSB                      0
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW20_MASK                     0x0000000f

/* Description		PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW40
			RTS tries count for rate series 0 at 40 MHz bandwidth.
*/
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW40_OFFSET                   0x00000018
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW40_LSB                      4
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW40_MASK                     0x000000f0

/* Description		PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW80
			RTS tries count for rate series 0 at 80 MHz bandwidth.
*/
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW80_OFFSET                   0x00000018
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW80_LSB                      8
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW80_MASK                     0x00000f00

/* Description		PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW160
			RTS tries count for rate series 0 at 160 MHz bandwidth.
*/
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW160_OFFSET                  0x00000018
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW160_LSB                     12
#define PPDU_STATUS_6_RTS_TRIES_CNT_S0_BW160_MASK                    0x0000f000

/* Description		PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW20
			RTS tries count for rate series 1 at 20 MHz bandwidth.
*/
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW20_OFFSET                   0x00000018
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW20_LSB                      16
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW20_MASK                     0x000f0000

/* Description		PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW40
			RTS tries count for rate series 1 at 40 MHz bandwidth.
*/
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW40_OFFSET                   0x00000018
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW40_LSB                      20
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW40_MASK                     0x00f00000

/* Description		PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW80
			RTS tries count for rate series 1 at 80 MHz bandwidth.
*/
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW80_OFFSET                   0x00000018
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW80_LSB                      24
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW80_MASK                     0x0f000000

/* Description		PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW160
			RTS tries count for rate series 1 at 160 MHz bandwidth.
*/
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW160_OFFSET                  0x00000018
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW160_LSB                     28
#define PPDU_STATUS_6_RTS_TRIES_CNT_S1_BW160_MASK                    0xf0000000

/* Description		PPDU_STATUS_7_ACK_RSSI_CHAIN0_PRI20
			RSSI of Ack on chain 0 of primary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_PRI20_OFFSET                   0x0000001c
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_PRI20_LSB                      0
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_PRI20_MASK                     0x000000ff

/* Description		PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC20
			RSSI of Ack on chain 0 of secondary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC20_OFFSET                   0x0000001c
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC20_LSB                      8
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC20_MASK                     0x0000ff00

/* Description		PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC40
			RSSI of Ack on chain 0 of secondary 40 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC40_OFFSET                   0x0000001c
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC40_LSB                      16
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC40_MASK                     0x00ff0000

/* Description		PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC80
			RSSI of Ack on chain 0 of secondary 80 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC80_OFFSET                   0x0000001c
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC80_LSB                      24
#define PPDU_STATUS_7_ACK_RSSI_CHAIN0_SEC80_MASK                     0xff000000

/* Description		PPDU_STATUS_8_ACK_RSSI_CHAIN1_PRI20
			RSSI of Ack on chain 1 of primary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_PRI20_OFFSET                   0x00000020
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_PRI20_LSB                      0
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_PRI20_MASK                     0x000000ff

/* Description		PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC20
			RSSI of Ack on chain 1 of secondary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC20_OFFSET                   0x00000020
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC20_LSB                      8
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC20_MASK                     0x0000ff00

/* Description		PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC40
			RSSI of Ack on chain 1 of secondary 40 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC40_OFFSET                   0x00000020
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC40_LSB                      16
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC40_MASK                     0x00ff0000

/* Description		PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC80
			RSSI of Ack on chain 1 of secondary 80 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC80_OFFSET                   0x00000020
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC80_LSB                      24
#define PPDU_STATUS_8_ACK_RSSI_CHAIN1_SEC80_MASK                     0xff000000

/* Description		PPDU_STATUS_9_ACK_RSSI_CHAIN2_PRI20
			RSSI of Ack on chain 2 of primary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_PRI20_OFFSET                   0x00000024
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_PRI20_LSB                      0
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_PRI20_MASK                     0x000000ff

/* Description		PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC20
			RSSI of Ack on chain 2 of secondary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC20_OFFSET                   0x00000024
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC20_LSB                      8
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC20_MASK                     0x0000ff00

/* Description		PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC40
			RSSI of Ack on chain 2 of secondary 40 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC40_OFFSET                   0x00000024
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC40_LSB                      16
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC40_MASK                     0x00ff0000

/* Description		PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC80
			RSSI of Ack on chain 2 of secondary 80 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC80_OFFSET                   0x00000024
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC80_LSB                      24
#define PPDU_STATUS_9_ACK_RSSI_CHAIN2_SEC80_MASK                     0xff000000

/* Description		PPDU_STATUS_10_ACK_RSSI_CHAIN3_PRI20
			RSSI of Ack on chain 3 of primary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_PRI20_OFFSET                  0x00000028
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_PRI20_LSB                     0
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_PRI20_MASK                    0x000000ff

/* Description		PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC20
			RSSI of Ack on chain 3 of secondary 20 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC20_OFFSET                  0x00000028
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC20_LSB                     8
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC20_MASK                    0x0000ff00

/* Description		PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC40
			RSSI of Ack on chain 3 of secondary 40 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC40_OFFSET                  0x00000028
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC40_LSB                     16
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC40_MASK                    0x00ff0000

/* Description		PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC80
			RSSI of Ack on chain 3 of secondary 80 MHz bandwidth.  Value
			of 0x80 indicates invalid.
*/
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC80_OFFSET                  0x00000028
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC80_LSB                     24
#define PPDU_STATUS_10_ACK_RSSI_CHAIN3_SEC80_MASK                    0xff000000

/* Description		PPDU_STATUS_11_ACK_RSSI_AVE
			RSSI of Ack of all active chains and bandwidths.
			Value of 0x80 indicates invalid.
*/
#define PPDU_STATUS_11_ACK_RSSI_AVE_OFFSET                           0x0000002c
#define PPDU_STATUS_11_ACK_RSSI_AVE_LSB                              0
#define PPDU_STATUS_11_ACK_RSSI_AVE_MASK                             0x000000ff

/* Description		PPDU_STATUS_11_LOCATIONING_TIMESTAMP
			Timestamp used for locationing.  This timestamp is used to
			indicate fractions of usec.  For example if the MAC clock is
			running at 80 MHz, the timestamp will increment every 12.5
			nsec.  The value starts at 0 and increments to 79 and
			returns to 0 and repeats.  This information is valid for
			every PPDU.  This information can be used in conjunction
			with wb_timestamp to capture large delta times.
*/
#define PPDU_STATUS_11_LOCATIONING_TIMESTAMP_OFFSET                  0x0000002c
#define PPDU_STATUS_11_LOCATIONING_TIMESTAMP_LSB                     8
#define PPDU_STATUS_11_LOCATIONING_TIMESTAMP_MASK                    0x0000ff00

/* Description		PPDU_STATUS_11_TX_QCU_NUM
			Indicates the QCU number of this status.  This is used by FW
			to identify the TX PPDU start descriptor associated with
			this TX PPDU end descriptor.
*/
#define PPDU_STATUS_11_TX_QCU_NUM_OFFSET                             0x0000002c
#define PPDU_STATUS_11_TX_QCU_NUM_LSB                                16
#define PPDU_STATUS_11_TX_QCU_NUM_MASK                               0x000f0000

/* Description		PPDU_STATUS_11_AGG_UNDERRUN
			Indicates underrun during the transmission of an aggregate.
*/
#define PPDU_STATUS_11_AGG_UNDERRUN_OFFSET                           0x0000002c
#define PPDU_STATUS_11_AGG_UNDERRUN_LSB                              20
#define PPDU_STATUS_11_AGG_UNDERRUN_MASK                             0x00100000

/* Description		PPDU_STATUS_11_FIRST_PKT_UNDERRUN
			Set when an underrun occurs on a stand-along packet or the
			first packet of an A-MPDU.
*/
#define PPDU_STATUS_11_FIRST_PKT_UNDERRUN_OFFSET                     0x0000002c
#define PPDU_STATUS_11_FIRST_PKT_UNDERRUN_LSB                        21
#define PPDU_STATUS_11_FIRST_PKT_UNDERRUN_MASK                       0x00200000

/* Description		PPDU_STATUS_11_RESERVED_11A
			Reserved: HW should fill with 0, FW should ignore.
*/
#define PPDU_STATUS_11_RESERVED_11A_OFFSET                           0x0000002c
#define PPDU_STATUS_11_RESERVED_11A_LSB                              22
#define PPDU_STATUS_11_RESERVED_11A_MASK                             0x00400000

/* Description		PPDU_STATUS_11_QCU_PAUSED
			Indicates that this QCU has been paused due to excessive
			retry.  This pause condition is only possible when
*/
#define PPDU_STATUS_11_QCU_PAUSED_OFFSET                             0x0000002c
#define PPDU_STATUS_11_QCU_PAUSED_LSB                                23
#define PPDU_STATUS_11_QCU_PAUSED_MASK                               0x00800000

/* Description		PPDU_STATUS_11_TOTAL_TRIES
			Indicates the total number of tries.  For example if the
			total_tires is 3, then tries_01 and tries_02 will indicate
			the first 2 attempt and then tries_last will indicate the
			status of the last attempt.
*/
#define PPDU_STATUS_11_TOTAL_TRIES_OFFSET                            0x0000002c
#define PPDU_STATUS_11_TOTAL_TRIES_LSB                               24
#define PPDU_STATUS_11_TOTAL_TRIES_MASK                              0x1f000000

/* Description		PPDU_STATUS_11_RESERVED_11B
			Reserved: HW should fill with 0, FW should ignore.
*/
#define PPDU_STATUS_11_RESERVED_11B_OFFSET                           0x0000002c
#define PPDU_STATUS_11_RESERVED_11B_LSB                              29
#define PPDU_STATUS_11_RESERVED_11B_MASK                             0x60000000

/* Description		PPDU_STATUS_11_TX_DONE
			Indicates the validity of the the tx_ppdu_end status
			information.  This bit must be in the last octet of
			tx_ppdu_end.
*/
#define PPDU_STATUS_11_TX_DONE_OFFSET                                0x0000002c
#define PPDU_STATUS_11_TX_DONE_LSB                                   31
#define PPDU_STATUS_11_TX_DONE_MASK                                  0x80000000

/* Description		PPDU_STATUS_12_UNDERRUN_OFFSET
			Indicates the offset from the 'seq_num' (starting sequence
			number in the BA) of the first frame which was not
			transmitted due to underrun condition.  This information can
			be used to diagnose underrun conditions.  This information
			can be used by FW to mask out the failure in the BA bitmap
			status which sould not be considered real failures for rate
			adaptation.  Only valid for A-MPDU aggregates and when the
			'agg_underrun' bit is set.
*/
#define PPDU_STATUS_12_UNDERRUN_OFFSET_OFFSET                        0x00000030
#define PPDU_STATUS_12_UNDERRUN_OFFSET_LSB                           0
#define PPDU_STATUS_12_UNDERRUN_OFFSET_MASK                          0x0000003f

/* Description		PPDU_STATUS_12_RESERVED_12A
			Reserved: HW should fill with 0, FW should ignore.
*/
#define PPDU_STATUS_12_RESERVED_12A_OFFSET                           0x00000030
#define PPDU_STATUS_12_RESERVED_12A_LSB                              6
#define PPDU_STATUS_12_RESERVED_12A_MASK                             0x000000c0

/* Description		PPDU_STATUS_12_PHY_ERROR_CODE
			The PHY error code which caused the transmit frame to be
			filtered.
			0: ERROR_TX_UNDERRUN
			1: TX_CHAIN_MASK_ZERO
			2: TX_EXTRA_SYM_MISMATCH
			3: TX_VHT_LENGTH_NOT_MULTIPLE_OF_3
			8: TX_BW_MISMATCH
			9: TX_VHT_RATE_ILLEGAL
			All other encodings are reserved
*/
#define PPDU_STATUS_12_PHY_ERROR_CODE_OFFSET                         0x00000030
#define PPDU_STATUS_12_PHY_ERROR_CODE_LSB                            8
#define PPDU_STATUS_12_PHY_ERROR_CODE_MASK                           0x0000ff00

/* Description		PPDU_STATUS_12_RESERVED_12B
			Reserved: HW should fill with 0, FW should ignore.
*/
#define PPDU_STATUS_12_RESERVED_12B_OFFSET                           0x00000030
#define PPDU_STATUS_12_RESERVED_12B_LSB                              16
#define PPDU_STATUS_12_RESERVED_12B_MASK                             0xffff0000

/* Description		PPDU_STATUS_13_RESERVED_13
			Reserved: HW should fill with 0, FW should ignore.
*/
#define PPDU_STATUS_13_RESERVED_13_OFFSET                            0x00000034
#define PPDU_STATUS_13_RESERVED_13_LSB                               0
#define PPDU_STATUS_13_RESERVED_13_MASK                              0xffffffff

/* Description		PPDU_STATUS_14_RESERVED_14
			Reserved: HW should fill with 0, FW should ignore.
*/
#define PPDU_STATUS_14_RESERVED_14_OFFSET                            0x00000038
#define PPDU_STATUS_14_RESERVED_14_LSB                               0
#define PPDU_STATUS_14_RESERVED_14_MASK                              0xffffffff

/* Description		PPDU_STATUS_15_RESERVED_15
			Reserved: HW should fill with 0, FW should ignore.
*/
#define PPDU_STATUS_15_RESERVED_15_OFFSET                            0x0000003c
#define PPDU_STATUS_15_RESERVED_15_LSB                               0
#define PPDU_STATUS_15_RESERVED_15_MASK                              0xffffffff


#endif // _PPDU_STATUS_H_
