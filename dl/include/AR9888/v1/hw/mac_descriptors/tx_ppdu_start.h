// Copyright (c) 2012 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _TX_PPDU_START_H_
#define _TX_PPDU_START_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	msdu_desc_ptr[31:0]
//	1	peer_ptr[31:0]
//	2	start_seq_num[11:0], qcu_num[15:12], bw_in_service[17:16], strip_vlan[18], select_tsf[19], pause_on_peer[20], warm_tx[21], reserved_2[22], insert_timestamp32[23], timestamp32_offset[31:24]
//	3	seqnum_bitmap_31_0[31:0]
//	4	seqnum_bitmap_63_32[31:0]
//	5	start_pn_31_0[31:0]
//	6	start_pn_63_32[31:0]
//	7	start_pn_95_64[31:0]
//	8	start_pn_127_96[31:0]
//	9	pn_bitmap_31_0[31:0]
//	10	pn_bitmap_63_32[31:0]
//	11	wb_filter_time[31:0]
//	12	tsf_filter_time[31:0]
//	13	key_id_octet[7:0], frag_desc_swap[8], timestamp_select[9], pause_on_failure[10], pause_on_timeout[11], veol[12], low_rx_chain[13], more_rifs[14], ampdu[15], no_ack[16], location_mode[17], ignore_qcu_filter[18], replace_qos_ctl[19], replace_ht_vht_ctl[20], replace_dur[21], frame_type[25:22], gen_tpc[31:26]
//	14	burst_duration[14:0], dur_update_en[15], frame_control[31:16]
//	15	duration[15:0], qos_ctl[31:16]
//	16	ht_vht_ctl[31:0]
//	17	cv_ptr[31:0]
//	18	tx_antenna_s0[23:0], paprd_chain_mask[27:24], raw_update_seqnum[28], raw_already_encrypted[29], raw_update_iv[30], vmf[31]
//	19	tx_antenna_s1[23:0], rts_rate[27:24], rts_preamble_type[29:28], bb_capture_channel[30], reserved_19[31]
//	20	cv_len[15:0], tries_s0[19:16], tries_s1[23:20], valid_s0_bw20[24], valid_s0_bw40[25], valid_s0_bw80[26], valid_s0_bw160[27], valid_s1_bw20[28], valid_s1_bw40[29], valid_s1_bw80[30], valid_s1_bw160[31]
//	21-24	struct series_bw s0_bw20;
//	25-28	struct series_bw s0_bw40;
//	29-32	struct series_bw s0_bw80;
//	33-36	struct series_bw s0_bw160;
//	37-40	struct series_bw s1_bw20;
//	41-44	struct series_bw s1_bw40;
//	45-48	struct series_bw s1_bw80;
//	49-52	struct series_bw s1_bw160;
//	53	tx_ppdu_end_ptr[31:0]
//	54	partial_aid[8:0], reserved_54a[15:9], group_id[21:16], reserved_54b[30:22], txop_ps_not_allowed[31]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_TX_PPDU_START 55

struct tx_ppdu_start {
    volatile uint32_t msdu_desc_ptr                   : 32; //[31:0]
    volatile uint32_t peer_ptr                        : 32; //[31:0]
    volatile uint32_t start_seq_num                   : 12, //[11:0]
                      qcu_num                         :  4, //[15:12]
                      bw_in_service                   :  2, //[17:16]
                      strip_vlan                      :  1, //[18]
                      select_tsf                      :  1, //[19]
                      pause_on_peer                   :  1, //[20]
                      warm_tx                         :  1, //[21]
                      reserved_2                      :  1, //[22]
                      insert_timestamp32              :  1, //[23]
                      timestamp32_offset              :  8; //[31:24]
    volatile uint32_t seqnum_bitmap_31_0              : 32; //[31:0]
    volatile uint32_t seqnum_bitmap_63_32             : 32; //[31:0]
    volatile uint32_t start_pn_31_0                   : 32; //[31:0]
    volatile uint32_t start_pn_63_32                  : 32; //[31:0]
    volatile uint32_t start_pn_95_64                  : 32; //[31:0]
    volatile uint32_t start_pn_127_96                 : 32; //[31:0]
    volatile uint32_t pn_bitmap_31_0                  : 32; //[31:0]
    volatile uint32_t pn_bitmap_63_32                 : 32; //[31:0]
    volatile uint32_t wb_filter_time                  : 32; //[31:0]
    volatile uint32_t tsf_filter_time                 : 32; //[31:0]
    volatile uint32_t key_id_octet                    :  8, //[7:0]
                      frag_desc_swap                  :  1, //[8]
                      timestamp_select                :  1, //[9]
                      pause_on_failure                :  1, //[10]
                      pause_on_timeout                :  1, //[11]
                      veol                            :  1, //[12]
                      low_rx_chain                    :  1, //[13]
                      more_rifs                       :  1, //[14]
                      ampdu                           :  1, //[15]
                      no_ack                          :  1, //[16]
                      location_mode                   :  1, //[17]
                      ignore_qcu_filter               :  1, //[18]
                      replace_qos_ctl                 :  1, //[19]
                      replace_ht_vht_ctl              :  1, //[20]
                      replace_dur                     :  1, //[21]
                      frame_type                      :  4, //[25:22]
                      gen_tpc                         :  6; //[31:26]
    volatile uint32_t burst_duration                  : 15, //[14:0]
                      dur_update_en                   :  1, //[15]
                      frame_control                   : 16; //[31:16]
    volatile uint32_t duration                        : 16, //[15:0]
                      qos_ctl                         : 16; //[31:16]
    volatile uint32_t ht_vht_ctl                      : 32; //[31:0]
    volatile uint32_t cv_ptr                          : 32; //[31:0]
    volatile uint32_t tx_antenna_s0                   : 24, //[23:0]
                      paprd_chain_mask                :  4, //[27:24]
                      raw_update_seqnum               :  1, //[28]
                      raw_already_encrypted           :  1, //[29]
                      raw_update_iv                   :  1, //[30]
                      vmf                             :  1; //[31]
    volatile uint32_t tx_antenna_s1                   : 24, //[23:0]
                      rts_rate                        :  4, //[27:24]
                      rts_preamble_type               :  2, //[29:28]
                      bb_capture_channel              :  1, //[30]
                      reserved_19                     :  1; //[31]
    volatile uint32_t cv_len                          : 16, //[15:0]
                      tries_s0                        :  4, //[19:16]
                      tries_s1                        :  4, //[23:20]
                      valid_s0_bw20                   :  1, //[24]
                      valid_s0_bw40                   :  1, //[25]
                      valid_s0_bw80                   :  1, //[26]
                      valid_s0_bw160                  :  1, //[27]
                      valid_s1_bw20                   :  1, //[28]
                      valid_s1_bw40                   :  1, //[29]
                      valid_s1_bw80                   :  1, //[30]
                      valid_s1_bw160                  :  1; //[31]
    struct            series_bw                       s0_bw20;
    struct            series_bw                       s0_bw40;
    struct            series_bw                       s0_bw80;
    struct            series_bw                       s0_bw160;
    struct            series_bw                       s1_bw20;
    struct            series_bw                       s1_bw40;
    struct            series_bw                       s1_bw80;
    struct            series_bw                       s1_bw160;
    volatile uint32_t tx_ppdu_end_ptr                 : 32; //[31:0]
    volatile uint32_t partial_aid                     :  9, //[8:0]
                      reserved_54a                    :  7, //[15:9]
                      group_id                        :  6, //[21:16]
                      reserved_54b                    :  9, //[30:22]
                      txop_ps_not_allowed             :  1; //[31]
};

/*

msdu_desc_ptr
			Points to the first MSDU descriptor of PPDU.  Used by DMA.

peer_ptr
			Points to the peer table entry.  For transmissions which do
			not have an allocated peer table entry and use the RAW
			encapsulation and don't use encryption may leave this ptr as
			NULL.  Used by DMA.

start_seq_num
			Indicates the sequence number of the first MPDU in this
			PPDU.  Requires that all the MPDUs in the PPDU are
			transmitted in monotonically increasing sequence number. 
			Used by OLE to insert sequence number into the MAC header.

qcu_num
			Indicates which QCU is associated with this PPDU.  Valid
			values can be 0 to 9.  Used by the PCU to select which
			qcu_filter bit from the peer_entry is used to determine
			whether this frame should be filtered or not.  <legal:0-9>

bw_in_service
			This specifies the BW mode in the service field for legacy
			control packets:
			0: service[6:0] = 7 random bits filled by BB
			1: service[6:5] = BW and service[4:0] = 5 random bits filled
				by BB
			2: service[6:5] = BW and service[4] = static/dynamic based
				on MAC configuration register, and service[3:0] = 4 random
				bits filled by BB.
			3: reserved: This combination should never be used.

strip_vlan
			Strip the VLAN during encapsulation.  Used by the OLE.

select_tsf
			Select the TSF used for AWDL (insert_timestamp32),
			tbtt_remaining, and TSF used in the transmit status
			descriptor.  If select_tsf is 0 then TSF is selected if
			select_tsf is 1 then TSF2 is selected.

pause_on_peer
			If set and the peer_table indicates filter, then the QCU
			associated with this descriptor will be paused.  Used by
			QCU.

warm_tx
			If set this PPDU is allowed to use warm TX if possible.

reserved_2
			Reserved for future use.

insert_timestamp32
			Inserts lower 32 bits of the TSF into at an arbitrary offset
			in the packet.  Actually it adds the current value in the
			packet with the TSF and replaces the original field.  This
			will only applied to the first MPDU in a A-MPDU; although in
			real world applications it will only be used for stand-alone
			MPDU PPDU packets.

timestamp32_offset
			The octet offset from the start of the MPDU where the TSF
			should be added.

seqnum_bitmap_31_0
			The Lower 32 bits of the 64 bit sequence number bitmap. 
			This field is used to specify the sequence numbers of all
			the MPDU in this PPDU based on the 'start_seq_num' field. 
			Any time there is a 0 in the bitmap, the corresponding
			sequence number is skipped as we are following the MPDUs in
			the MPDU linked list.  For example: if start_seq_num is
			0x100 and seq_num_bitmap is 0x0123.  Then the transmit queue
			contains the MPDU: 0x100, 0x101, 0x105, 0x108.  Used by OLE
			to insert sequence number into the MAC header.

seqnum_bitmap_63_32
			Upper 32 bits of the 64 bit sequence number bitmap.  See
			description for seq_num_bitmap_31_0.

start_pn_31_0
			start_pn_a is bits [31:0] of the 128 bit starting PN (Packet
			Number) which is used in conjunction with the pn_bitmap and
			key_id_octet to form the IV.  pn# represents one of the
			octets of the start packet number:
			pn0[7:0] = start_pn_a[7:0] 
			pn1[7:0] = start_pn_a[15:8] 
			pn2[7:0] = start_pn_a[23:16] 
			pn3[7:0] = start_pn_a[31:24] 
			. . .
			pn15[7:0] = start_pn_d[127:120]
			The following is a list of cipher standards and their pn and
				key_id_octet usage.
			WEP: IV = {key_id_octet, pn2, pn1, pn0}
			TKIP: IV = {pn5, pn4, pn3, pn2, key_id_octet, pn0,
				WEPSeed[1], pn1}
			WEPSeed[1] is 0x7F & (pn1 | 0x20)
			AES-CCM: IV = {pn5, pn4, pn3, pn2, key_id_octet, 0x0, pn1,
				pn0}
			WAPI: IV = {pn15, pn14, pn13, pn12, pn11, pn10, pn9, pn8,
				pn7, pn6, pn5, pn4, pn3, pn2, pn1, pn0, 0x0, key_id_octet}
			This field is used by OLE to insert IV into the packet

start_pn_63_32
			Bits [63:32] of the 128 bit start PN.  See description for
			start_pn_31_0

start_pn_95_64
			Bits [95:64] of the 128 bit start PN.  See description for
			start_pn_31_0

start_pn_127_96
			Bits [127:96] of the 128 bit start PN.  See description for
			start_pn_31_0

pn_bitmap_31_0
			Lower 32 bits of the 64-bit packet number bitmap.  In
			concept the use of start_pn and pn_bitmap is very similar to
			start_seq_num and seq_num_bitmap.  The pn_shift_factor[3:0]
			is a register which indicates the increment in factors of
			2N.  This is necessary to provide different PN space for
			each TID.  PN should never be duplicated; however, it is
			allocated per destination not per TID like sequence numbers.
			If we allocated PN for each packet before the packets are
			split to the different connection queues, then the PN could
			not be represented as a start and bitmap.  By having the PN
			number space independent for each TID we can guarantee that
			the PN numbers for a connection queue will increment by the
			2pn_shift_factor for each subsequent packet.  This bitmap is
			not considered necessary because the seq_num_bitmap and the
			pn_bitmap should be identical, but this field exists just in
			case there is an issue.  Used by OLE to insert the IV into
			the packet.

pn_bitmap_63_32
			Upper 32 bits of the 64-bit packet number bitmap.  See
			description for pn_bitmap_31_0.

wb_filter_time
			If wb_filter_time is set to 0 the WB timer check and
			filtering is disabled; otherwise, if the WB timer is smaller
			than the wb_filter_time the packet will be filtered.  PCU
			uses this information.

tsf_filter_time
			If tsf_filter_time is set to 0 the TSF timer check and
			filtering is disabled; otherwise, if the TSF is smaller than
			the tsf_filter_time the packet will be filtered.  PCU uses
			this information.

key_id_octet
			The key_id_octet includes the key_id: key_id_octet[7:6] and
			the extended IV: key_id_octet[5] and reserved bits:
			key_id_octet[4:0].  Used by the OLE to create the IV field
			of the packet.

frag_desc_swap
			If set the fragmentation descriptor will be byte swapped for
			endian conversion.  Used by the DMA.

timestamp_select
			If set the WB timestamp is stored in the TX PPDU end status.
			If clear then the TSF timestamp is stored in the TX PPDU
			end status.  Used by the PCU.

pause_on_failure
			If set, when excessive retry occurs, first packet underrun
			or some other failure condition, the QCU associated with
			this packet will pause.  This may only be necessary for
			non-aggregated frames with STA which do not have BA
			capability.  Used by QCU.

pause_on_timeout
			If set and there is a filter condition triggered by timer
			expiry the subsequent packets in the QCU associated with
			this packet will pause.  The HW will set the QCU pause
			register and FW will need to re-enable the queue by setting
			the 'unpause' bit in the QCU (New register TBD) before the
			queue will start again.  Pause will not flush the existing
			TXDPs in the queue.  Used by QCU to pause.

veol
			If there is any bursting policy on this queue and the veol
			(virtual end of list) bit is set then the burst will be
			terminated following this transmission.  Used by QCU to
			terminate burst.

low_rx_chain
			Used for dynamic MIMO power save operation.  If set the RX
			chain setting to go back to single chain mode.  Used by PCU
			to generate BB descriptor.

more_rifs
			Used to transmit RIFS.  This feature is deprecated do not
			use.  Used by DMA for burst and PCU to generate rifs burst.

ampdu
			If set this frame is an A-MPDU aggregate and is not a
			stand-alone packet.  Used by PCU to generate 11n HT-SIG
			Aggregation bit.  Used by PCU to generate normal A-MPDU
			frames or used to generate the EOF delimiter in the first
			packet to indicate stand-alone frame.

no_ack
			If set indicates that after the transmission of this packet
			the PCU will not wait for Ack.  It is often used for
			multicast frames, RIFS, TxBF NDPA and NDP, etc.  Used by
			PCU.

location_mode
			If set after packet transmission, BB will return the
			location information.  Used by PCU to generate BB
			descriptor.

ignore_qcu_filter
			If set the MAC will ignore the filter indication in the peer
			table and transmit frame.  Used by PCU to decide whether to
			filter TX or not.

replace_qos_ctl
			If set the OLE will insert/replace the QoS control field in
			the MPDU.

replace_ht_vht_ctl
			If set the OLE will insert/replace the HT/VHT control field
			in the MPDU.

replace_dur
			If set the duration field described below replaces the
			duration field (dur) in the native WiFi format header.  For
			Ethernet II and 802.3 packet formats, the duration field in
			the 802.11 header will be replaced with the dur field in the
			descriptor even if this this bit is not set.  Used by the
			OLE.

frame_type
			Frame type indication.  Indicates what type of frame is
			being sent.  Supported values:
			0: default
			1: Reserved (Used to be used for ATIM)
			2: PS-Poll
			3: Beacon
			4: Probe response
			5-15: Reserved
			<legal:0,2,3,4>

gen_tpc
			TPC for generated frames such as RTS and self CTS and in the
			future NDP.

burst_duration
			Reserved additional time in the duration field beyond the
			completion of this packet transaction.  Used by PCU to
			generate duration field.

dur_update_en
			If set indicates that the 802.11 duration field will be
			replaced by the PCU.

frame_control
			802.11 Frame control field:
			fc [1:0]: Protocol Version
			fc [3:2]: Type
			fc [7:4]: Subtype
			fc [8]: To DS
			fc [9]: From DS
			fc [10]: More Frag
			fc [11]: Retry
			fc [12]: Pwr Mgt
			fc [13]: More Data
			fc [14]: Protected Frame
			fc [15]: Order
			Used by OLE during the encapsulation process for Native
				WiFi, Ethernet II, and 802.3.

duration
			Normally HW will update the 802.11 duration field (set
			update_dur_en descriptor to enable this behavior).  If it is
			not set then HW will insert this field into the duration
			field of the 802.11 header unless the packet is encapsulated
			in RAW format.  Note: when transmitting PS-Poll frames, this
			field will be set to the AID value and dur[15:14] set to
			0x3.  This field is inserted into the 802.11 header during
			the encapsulation process by the OLE.

qos_ctl
			QoS control field is valid if the type field is data and the
			upper bit of the subtype field is set.  The field decode is
			as below:
			qos_ctl[3:0]: TID
			qos_ctl[4]: EOSP (with some exceptions)
			qos_ctl[6:5]: Ack Policy
			0x0: Normal Ack or Implicit BAR
			0x1: No Ack
			0x2: No explicit Ack or PSMP Ack (not supported)
			0x3: Block Ack (Not supported)
			Qos_ctl[7]: A-MSDU Present (with some exceptions)
			Qos_ctl[15:8]: TXOP limit, AP PS buffer state, TXOP duration
				requested or queue size (Not supported)
			This field is inserted into the 802.11 header during the
				encapsulation process
			<legal[3:0]:0-7><legal[4]:0,1><legal[6:5]:0,
				1><legal[7]:0,1><legal[15:8]:0>

ht_vht_ctl
			If the Order bit is set then this frame includes the HT/VHT
			control field.  The HT control field is used for fast link
			adaptation, TxBF support, and RDG support.  WiFi 1.0 does
			not support FLA, RDG, and implicit TxBF.
			If ht_vht_ctl[0] is 0, this is a HT control field:
			ht_vht_ctl[15:0]: Link Adaptation Control (FLA)
			ht_vht_ctl[17:16]: Calibration Position (Implicit TxBF)
			ht_vht_ctl[19:18]: Calibration Sequence (Implicit TxBF)
			ht_vht_ctl[21:20]: Reserved
			ht_vht_ctl[23:22]: CSI/Steering (TxBF: NDP) Only set for
				transmit NDP Announcement frames.  (No support for staggered
				sounding). Only compressed beamforming is supported
			ht_vht_ctl[24]: NDP Announcement (TxBF: NDP).  Indicates
				that this is an NDP announcement frame.  The next PPDU after
				SIFS will be NDP.
			ht_vht_ctl[29:25]: Reserved
			ht_vht_ctl[30] AC Constraint (RDG)
			ht_vht_ctl[31] RDG/More PPDU (RDG)
			If ht_vht_ctl[0] is 1, this is a VHT control field
			No plan to support this in WiFi 1.0.  Used by OLE
			<legal[31:0]:0>

cv_ptr
			Points to the compressed V data structure.  Fetched by DMA
			and compressed V data structure will be consumed by the SVD
			in the BB.  Used by DMA.

tx_antenna_s0
			Sectored transmit antenna for series 0

paprd_chain_mask
			Information is the chain mask used by BB for calibration of
			the power amplifier (PA) predistortion (PRD) path.  Used by
			PCU to generate BB descriptor.  paprd_chain_mask[3] is
			reserved for WiFi 1.0

raw_update_seqnum
			If set the tx_ppdu_start seqnum mechanism is used to update
			the sequence number if the MPDU is in RAW format.  If clear,
			the sequence number in the MPDU is unchanged if the MPDU is
			in RAW format.

raw_already_encrypted
			If set it indicates that the RAW MPDU has already been
			encrypted and does not require HW encryption.  If clear and
			if the frame control indicates that this is a 'protected'
			MPDU and the peer key type indicates a cipher type then the
			HW is expected to encrypt this packet.

raw_update_iv
			If set the tx_ppdu_start IV mechanism is used to update the
			IV if the MPDU is in RAW format.  If clear, the IV in the
			MPDU is unchanged if the MPDU is in RAW format.

vmf
			If set enables VMF bursting (Virtual More Fragment) bursting
			which provides SIFS based bursting based on TXOP.  It also
			allows for the cancelling of RTS or self-CTS in the middle
			of a SIFS burst.

tx_antenna_s1
			Sectored transmit antenna for series 1

rts_rate
			Same format as the 'rate' field.  Only single stream RTS is
			possible.

rts_preamble_type
			Preamble type for the RTS frame.  Same format as the
			'preamble_type' field.

bb_capture_channel
			Indicate to the BB via the BB descriptor to capture the
			channel for a good receive packet.

reserved_19
			Reserved.  Not used by HW.
			<legal:0>

cv_len
			Number of octets in the compress V data structure to fetch. 
			Used by DMA.
			<legal:0-2047>

tries_s0
			Tries series 0 indicates the maximum number of transmission
			attempts at transmit series 0.  A transmission attempt
			includes RTS/CTS failure, data packet failure and data
			packet success.  Each try should correspond to a try_status
			in the tx_ppdu_end.  Used by PCU.  <legal:1-15>

tries_s1
			Tries series 1 indicates the maximum number of transmission
			attempts at transmit series 1.  A transmission attempt
			includes RTS/CTS failure, data packet failure and data
			packet success.  Each try should correspond to a try_status
			in the tx_ppdu_end.  Used by PCU.  <legal:0-15>

valid_s0_bw20
			Validity of the series 0 for bandwidth 20 MHz entry.  Used
			by PCU.

valid_s0_bw40
			Validity of the series 0 for bandwidth 40 MHz entry.  Used
			by PCU.

valid_s0_bw80
			Validity of the series 0 for bandwidth 80 MHz entry.  Used
			by PCU.

valid_s0_bw160
			Validity of the series 0 for bandwidth 160 MHz entry.  Used
			by PCU.
			<legal:0>

valid_s1_bw20
			Validity of the series 1 for bandwidth 20 MHz entry.  Used
			by PCU.

valid_s1_bw40
			Validity of the series 1 for bandwidth 40 MHz entry.  Used
			by PCU.

valid_s1_bw80
			Validity of the series 1 for bandwidth 80 MHz entry.  Used
			by PCU.

valid_s1_bw160
			Validity of the series 1 for bandwidth 160 MHz entry.  Used
			by PCU.
			<legal:0>

struct series_bw s0_bw20
			instance of series_bw structure for series 0 and bandwidth
			20 MHz.

struct series_bw s0_bw40
			instance of series_bw structure for series 0 and bandwidth
			40 MHz.

struct series_bw s0_bw80
			instance of series_bw structure for series 0 and bandwidth
			80 MHz.

struct series_bw s0_bw160
			instance of series_bw structure for series 0 and bandwidth
			160 MHz.
			<legal:0>

struct series_bw s1_bw20
			instance of series_bw structure for series 1 and bandwidth
			20 MHz.

struct series_bw s1_bw40
			instance of series_bw structure for series 1 and bandwidth
			40 MHz.

struct series_bw s1_bw80
			instance of series_bw structure for series 1 and bandwidth
			80 MHz.

struct series_bw s1_bw160
			instance of series_bw structure for series 1 and bandwidth
			160 MHz.
			<legal:0>

tx_ppdu_end_ptr
			The pointer to the buffer where the MAC will write the
			transmit status (tx_ppdu_end) associated with this PPDU.

partial_aid
			The partial AID field to be inserted into VHT SIG A.  Field
			is invalid for CCK, legacy OFDM, and HT rates.

reserved_54a
			Reserved.  Not used by HW.
			<legal:0>

group_id
			The group ID field is used in VHT SIG A.  Only legal values
			are 0 and 63 since MU is not supported.  If this is a PPDU
			is addressed to an AP or a mesh STA it is 0; otherwise, it
			is only 63. <legal:0,63>

reserved_54b
			Reserved.  Not used by HW.
			<legal:0>

txop_ps_not_allowed
			The 11ac standard says: 'Set to 0 by VHT AP if it allows
			non-AP VHT STAs in TXOP power save mode to enter Doze state
			during a TXOP.  Set to 1 otherwise.  The bit is reserved and
			set to 1 in VHT PPDUs transmitted by a non-AP VHT STA.' 
			There is no plan to support this feature.  This field should
			always be set to 1.
			<legal:1>
*/


/* Description		TX_PPDU_START_0_MSDU_DESC_PTR
			Points to the first MSDU descriptor of PPDU.  Used by DMA.
*/
#define TX_PPDU_START_0_MSDU_DESC_PTR_OFFSET                         0x00000000
#define TX_PPDU_START_0_MSDU_DESC_PTR_LSB                            0
#define TX_PPDU_START_0_MSDU_DESC_PTR_MASK                           0xffffffff

/* Description		TX_PPDU_START_1_PEER_PTR
			Points to the peer table entry.  For transmissions which do
			not have an allocated peer table entry and use the RAW
			encapsulation and don't use encryption may leave this ptr as
			NULL.  Used by DMA.
*/
#define TX_PPDU_START_1_PEER_PTR_OFFSET                              0x00000004
#define TX_PPDU_START_1_PEER_PTR_LSB                                 0
#define TX_PPDU_START_1_PEER_PTR_MASK                                0xffffffff

/* Description		TX_PPDU_START_2_START_SEQ_NUM
			Indicates the sequence number of the first MPDU in this
			PPDU.  Requires that all the MPDUs in the PPDU are
			transmitted in monotonically increasing sequence number. 
			Used by OLE to insert sequence number into the MAC header.
*/
#define TX_PPDU_START_2_START_SEQ_NUM_OFFSET                         0x00000008
#define TX_PPDU_START_2_START_SEQ_NUM_LSB                            0
#define TX_PPDU_START_2_START_SEQ_NUM_MASK                           0x00000fff

/* Description		TX_PPDU_START_2_QCU_NUM
			Indicates which QCU is associated with this PPDU.  Valid
			values can be 0 to 9.  Used by the PCU to select which
			qcu_filter bit from the peer_entry is used to determine
			whether this frame should be filtered or not.  <legal:0-9>
*/
#define TX_PPDU_START_2_QCU_NUM_OFFSET                               0x00000008
#define TX_PPDU_START_2_QCU_NUM_LSB                                  12
#define TX_PPDU_START_2_QCU_NUM_MASK                                 0x0000f000

/* Description		TX_PPDU_START_2_BW_IN_SERVICE
			This specifies the BW mode in the service field for legacy
			control packets:
			0: service[6:0] = 7 random bits filled by BB
			1: service[6:5] = BW and service[4:0] = 5 random bits filled
				by BB
			2: service[6:5] = BW and service[4] = static/dynamic based
				on MAC configuration register, and service[3:0] = 4 random
				bits filled by BB.
			3: reserved: This combination should never be used.
*/
#define TX_PPDU_START_2_BW_IN_SERVICE_OFFSET                         0x00000008
#define TX_PPDU_START_2_BW_IN_SERVICE_LSB                            16
#define TX_PPDU_START_2_BW_IN_SERVICE_MASK                           0x00030000

/* Description		TX_PPDU_START_2_STRIP_VLAN
			Strip the VLAN during encapsulation.  Used by the OLE.
*/
#define TX_PPDU_START_2_STRIP_VLAN_OFFSET                            0x00000008
#define TX_PPDU_START_2_STRIP_VLAN_LSB                               18
#define TX_PPDU_START_2_STRIP_VLAN_MASK                              0x00040000

/* Description		TX_PPDU_START_2_SELECT_TSF
			Select the TSF used for AWDL (insert_timestamp32),
			tbtt_remaining, and TSF used in the transmit status
			descriptor.  If select_tsf is 0 then TSF is selected if
			select_tsf is 1 then TSF2 is selected.
*/
#define TX_PPDU_START_2_SELECT_TSF_OFFSET                            0x00000008
#define TX_PPDU_START_2_SELECT_TSF_LSB                               19
#define TX_PPDU_START_2_SELECT_TSF_MASK                              0x00080000

/* Description		TX_PPDU_START_2_PAUSE_ON_PEER
			If set and the peer_table indicates filter, then the QCU
			associated with this descriptor will be paused.  Used by
			QCU.
*/
#define TX_PPDU_START_2_PAUSE_ON_PEER_OFFSET                         0x00000008
#define TX_PPDU_START_2_PAUSE_ON_PEER_LSB                            20
#define TX_PPDU_START_2_PAUSE_ON_PEER_MASK                           0x00100000

/* Description		TX_PPDU_START_2_WARM_TX
			If set this PPDU is allowed to use warm TX if possible.
*/
#define TX_PPDU_START_2_WARM_TX_OFFSET                               0x00000008
#define TX_PPDU_START_2_WARM_TX_LSB                                  21
#define TX_PPDU_START_2_WARM_TX_MASK                                 0x00200000

/* Description		TX_PPDU_START_2_RESERVED_2
			Reserved for future use.
*/
#define TX_PPDU_START_2_RESERVED_2_OFFSET                            0x00000008
#define TX_PPDU_START_2_RESERVED_2_LSB                               22
#define TX_PPDU_START_2_RESERVED_2_MASK                              0x00400000

/* Description		TX_PPDU_START_2_INSERT_TIMESTAMP32
			Inserts lower 32 bits of the TSF into at an arbitrary offset
			in the packet.  Actually it adds the current value in the
			packet with the TSF and replaces the original field.  This
			will only applied to the first MPDU in a A-MPDU; although in
			real world applications it will only be used for stand-alone
			MPDU PPDU packets.
*/
#define TX_PPDU_START_2_INSERT_TIMESTAMP32_OFFSET                    0x00000008
#define TX_PPDU_START_2_INSERT_TIMESTAMP32_LSB                       23
#define TX_PPDU_START_2_INSERT_TIMESTAMP32_MASK                      0x00800000

/* Description		TX_PPDU_START_2_TIMESTAMP32_OFFSET
			The octet offset from the start of the MPDU where the TSF
			should be added.
*/
#define TX_PPDU_START_2_TIMESTAMP32_OFFSET_OFFSET                    0x00000008
#define TX_PPDU_START_2_TIMESTAMP32_OFFSET_LSB                       24
#define TX_PPDU_START_2_TIMESTAMP32_OFFSET_MASK                      0xff000000

/* Description		TX_PPDU_START_3_SEQNUM_BITMAP_31_0
			The Lower 32 bits of the 64 bit sequence number bitmap. 
			This field is used to specify the sequence numbers of all
			the MPDU in this PPDU based on the 'start_seq_num' field. 
			Any time there is a 0 in the bitmap, the corresponding
			sequence number is skipped as we are following the MPDUs in
			the MPDU linked list.  For example: if start_seq_num is
			0x100 and seq_num_bitmap is 0x0123.  Then the transmit queue
			contains the MPDU: 0x100, 0x101, 0x105, 0x108.  Used by OLE
			to insert sequence number into the MAC header.
*/
#define TX_PPDU_START_3_SEQNUM_BITMAP_31_0_OFFSET                    0x0000000c
#define TX_PPDU_START_3_SEQNUM_BITMAP_31_0_LSB                       0
#define TX_PPDU_START_3_SEQNUM_BITMAP_31_0_MASK                      0xffffffff

/* Description		TX_PPDU_START_4_SEQNUM_BITMAP_63_32
			Upper 32 bits of the 64 bit sequence number bitmap.  See
			description for seq_num_bitmap_31_0.
*/
#define TX_PPDU_START_4_SEQNUM_BITMAP_63_32_OFFSET                   0x00000010
#define TX_PPDU_START_4_SEQNUM_BITMAP_63_32_LSB                      0
#define TX_PPDU_START_4_SEQNUM_BITMAP_63_32_MASK                     0xffffffff

/* Description		TX_PPDU_START_5_START_PN_31_0
			start_pn_a is bits [31:0] of the 128 bit starting PN (Packet
			Number) which is used in conjunction with the pn_bitmap and
			key_id_octet to form the IV.  pn# represents one of the
			octets of the start packet number:
			pn0[7:0] = start_pn_a[7:0] 
			pn1[7:0] = start_pn_a[15:8] 
			pn2[7:0] = start_pn_a[23:16] 
			pn3[7:0] = start_pn_a[31:24] 
			. . .
			pn15[7:0] = start_pn_d[127:120]
			The following is a list of cipher standards and their pn and
				key_id_octet usage.
			WEP: IV = {key_id_octet, pn2, pn1, pn0}
			TKIP: IV = {pn5, pn4, pn3, pn2, key_id_octet, pn0,
				WEPSeed[1], pn1}
			WEPSeed[1] is 0x7F & (pn1 | 0x20)
			AES-CCM: IV = {pn5, pn4, pn3, pn2, key_id_octet, 0x0, pn1,
				pn0}
			WAPI: IV = {pn15, pn14, pn13, pn12, pn11, pn10, pn9, pn8,
				pn7, pn6, pn5, pn4, pn3, pn2, pn1, pn0, 0x0, key_id_octet}
			This field is used by OLE to insert IV into the packet
*/
#define TX_PPDU_START_5_START_PN_31_0_OFFSET                         0x00000014
#define TX_PPDU_START_5_START_PN_31_0_LSB                            0
#define TX_PPDU_START_5_START_PN_31_0_MASK                           0xffffffff

/* Description		TX_PPDU_START_6_START_PN_63_32
			Bits [63:32] of the 128 bit start PN.  See description for
			start_pn_31_0
*/
#define TX_PPDU_START_6_START_PN_63_32_OFFSET                        0x00000018
#define TX_PPDU_START_6_START_PN_63_32_LSB                           0
#define TX_PPDU_START_6_START_PN_63_32_MASK                          0xffffffff

/* Description		TX_PPDU_START_7_START_PN_95_64
			Bits [95:64] of the 128 bit start PN.  See description for
			start_pn_31_0
*/
#define TX_PPDU_START_7_START_PN_95_64_OFFSET                        0x0000001c
#define TX_PPDU_START_7_START_PN_95_64_LSB                           0
#define TX_PPDU_START_7_START_PN_95_64_MASK                          0xffffffff

/* Description		TX_PPDU_START_8_START_PN_127_96
			Bits [127:96] of the 128 bit start PN.  See description for
			start_pn_31_0
*/
#define TX_PPDU_START_8_START_PN_127_96_OFFSET                       0x00000020
#define TX_PPDU_START_8_START_PN_127_96_LSB                          0
#define TX_PPDU_START_8_START_PN_127_96_MASK                         0xffffffff

/* Description		TX_PPDU_START_9_PN_BITMAP_31_0
			Lower 32 bits of the 64-bit packet number bitmap.  In
			concept the use of start_pn and pn_bitmap is very similar to
			start_seq_num and seq_num_bitmap.  The pn_shift_factor[3:0]
			is a register which indicates the increment in factors of
			2N.  This is necessary to provide different PN space for
			each TID.  PN should never be duplicated; however, it is
			allocated per destination not per TID like sequence numbers.
			If we allocated PN for each packet before the packets are
			split to the different connection queues, then the PN could
			not be represented as a start and bitmap.  By having the PN
			number space independent for each TID we can guarantee that
			the PN numbers for a connection queue will increment by the
			2pn_shift_factor for each subsequent packet.  This bitmap is
			not considered necessary because the seq_num_bitmap and the
			pn_bitmap should be identical, but this field exists just in
			case there is an issue.  Used by OLE to insert the IV into
			the packet.
*/
#define TX_PPDU_START_9_PN_BITMAP_31_0_OFFSET                        0x00000024
#define TX_PPDU_START_9_PN_BITMAP_31_0_LSB                           0
#define TX_PPDU_START_9_PN_BITMAP_31_0_MASK                          0xffffffff

/* Description		TX_PPDU_START_10_PN_BITMAP_63_32
			Upper 32 bits of the 64-bit packet number bitmap.  See
			description for pn_bitmap_31_0.
*/
#define TX_PPDU_START_10_PN_BITMAP_63_32_OFFSET                      0x00000028
#define TX_PPDU_START_10_PN_BITMAP_63_32_LSB                         0
#define TX_PPDU_START_10_PN_BITMAP_63_32_MASK                        0xffffffff

/* Description		TX_PPDU_START_11_WB_FILTER_TIME
			If wb_filter_time is set to 0 the WB timer check and
			filtering is disabled; otherwise, if the WB timer is smaller
			than the wb_filter_time the packet will be filtered.  PCU
			uses this information.
*/
#define TX_PPDU_START_11_WB_FILTER_TIME_OFFSET                       0x0000002c
#define TX_PPDU_START_11_WB_FILTER_TIME_LSB                          0
#define TX_PPDU_START_11_WB_FILTER_TIME_MASK                         0xffffffff

/* Description		TX_PPDU_START_12_TSF_FILTER_TIME
			If tsf_filter_time is set to 0 the TSF timer check and
			filtering is disabled; otherwise, if the TSF is smaller than
			the tsf_filter_time the packet will be filtered.  PCU uses
			this information.
*/
#define TX_PPDU_START_12_TSF_FILTER_TIME_OFFSET                      0x00000030
#define TX_PPDU_START_12_TSF_FILTER_TIME_LSB                         0
#define TX_PPDU_START_12_TSF_FILTER_TIME_MASK                        0xffffffff

/* Description		TX_PPDU_START_13_KEY_ID_OCTET
			The key_id_octet includes the key_id: key_id_octet[7:6] and
			the extended IV: key_id_octet[5] and reserved bits:
			key_id_octet[4:0].  Used by the OLE to create the IV field
			of the packet.
*/
#define TX_PPDU_START_13_KEY_ID_OCTET_OFFSET                         0x00000034
#define TX_PPDU_START_13_KEY_ID_OCTET_LSB                            0
#define TX_PPDU_START_13_KEY_ID_OCTET_MASK                           0x000000ff

/* Description		TX_PPDU_START_13_FRAG_DESC_SWAP
			If set the fragmentation descriptor will be byte swapped for
			endian conversion.  Used by the DMA.
*/
#define TX_PPDU_START_13_FRAG_DESC_SWAP_OFFSET                       0x00000034
#define TX_PPDU_START_13_FRAG_DESC_SWAP_LSB                          8
#define TX_PPDU_START_13_FRAG_DESC_SWAP_MASK                         0x00000100

/* Description		TX_PPDU_START_13_TIMESTAMP_SELECT
			If set the WB timestamp is stored in the TX PPDU end status.
			If clear then the TSF timestamp is stored in the TX PPDU
			end status.  Used by the PCU.
*/
#define TX_PPDU_START_13_TIMESTAMP_SELECT_OFFSET                     0x00000034
#define TX_PPDU_START_13_TIMESTAMP_SELECT_LSB                        9
#define TX_PPDU_START_13_TIMESTAMP_SELECT_MASK                       0x00000200

/* Description		TX_PPDU_START_13_PAUSE_ON_FAILURE
			If set, when excessive retry occurs, first packet underrun
			or some other failure condition, the QCU associated with
			this packet will pause.  This may only be necessary for
			non-aggregated frames with STA which do not have BA
			capability.  Used by QCU.
*/
#define TX_PPDU_START_13_PAUSE_ON_FAILURE_OFFSET                     0x00000034
#define TX_PPDU_START_13_PAUSE_ON_FAILURE_LSB                        10
#define TX_PPDU_START_13_PAUSE_ON_FAILURE_MASK                       0x00000400

/* Description		TX_PPDU_START_13_PAUSE_ON_TIMEOUT
			If set and there is a filter condition triggered by timer
			expiry the subsequent packets in the QCU associated with
			this packet will pause.  The HW will set the QCU pause
			register and FW will need to re-enable the queue by setting
			the 'unpause' bit in the QCU (New register TBD) before the
			queue will start again.  Pause will not flush the existing
			TXDPs in the queue.  Used by QCU to pause.
*/
#define TX_PPDU_START_13_PAUSE_ON_TIMEOUT_OFFSET                     0x00000034
#define TX_PPDU_START_13_PAUSE_ON_TIMEOUT_LSB                        11
#define TX_PPDU_START_13_PAUSE_ON_TIMEOUT_MASK                       0x00000800

/* Description		TX_PPDU_START_13_VEOL
			If there is any bursting policy on this queue and the veol
			(virtual end of list) bit is set then the burst will be
			terminated following this transmission.  Used by QCU to
			terminate burst.
*/
#define TX_PPDU_START_13_VEOL_OFFSET                                 0x00000034
#define TX_PPDU_START_13_VEOL_LSB                                    12
#define TX_PPDU_START_13_VEOL_MASK                                   0x00001000

/* Description		TX_PPDU_START_13_LOW_RX_CHAIN
			Used for dynamic MIMO power save operation.  If set the RX
			chain setting to go back to single chain mode.  Used by PCU
			to generate BB descriptor.
*/
#define TX_PPDU_START_13_LOW_RX_CHAIN_OFFSET                         0x00000034
#define TX_PPDU_START_13_LOW_RX_CHAIN_LSB                            13
#define TX_PPDU_START_13_LOW_RX_CHAIN_MASK                           0x00002000

/* Description		TX_PPDU_START_13_MORE_RIFS
			Used to transmit RIFS.  This feature is deprecated do not
			use.  Used by DMA for burst and PCU to generate rifs burst.
*/
#define TX_PPDU_START_13_MORE_RIFS_OFFSET                            0x00000034
#define TX_PPDU_START_13_MORE_RIFS_LSB                               14
#define TX_PPDU_START_13_MORE_RIFS_MASK                              0x00004000

/* Description		TX_PPDU_START_13_AMPDU
			If set this frame is an A-MPDU aggregate and is not a
			stand-alone packet.  Used by PCU to generate 11n HT-SIG
			Aggregation bit.  Used by PCU to generate normal A-MPDU
			frames or used to generate the EOF delimiter in the first
			packet to indicate stand-alone frame.
*/
#define TX_PPDU_START_13_AMPDU_OFFSET                                0x00000034
#define TX_PPDU_START_13_AMPDU_LSB                                   15
#define TX_PPDU_START_13_AMPDU_MASK                                  0x00008000

/* Description		TX_PPDU_START_13_NO_ACK
			If set indicates that after the transmission of this packet
			the PCU will not wait for Ack.  It is often used for
			multicast frames, RIFS, TxBF NDPA and NDP, etc.  Used by
			PCU.
*/
#define TX_PPDU_START_13_NO_ACK_OFFSET                               0x00000034
#define TX_PPDU_START_13_NO_ACK_LSB                                  16
#define TX_PPDU_START_13_NO_ACK_MASK                                 0x00010000

/* Description		TX_PPDU_START_13_LOCATION_MODE
			If set after packet transmission, BB will return the
			location information.  Used by PCU to generate BB
			descriptor.
*/
#define TX_PPDU_START_13_LOCATION_MODE_OFFSET                        0x00000034
#define TX_PPDU_START_13_LOCATION_MODE_LSB                           17
#define TX_PPDU_START_13_LOCATION_MODE_MASK                          0x00020000

/* Description		TX_PPDU_START_13_IGNORE_QCU_FILTER
			If set the MAC will ignore the filter indication in the peer
			table and transmit frame.  Used by PCU to decide whether to
			filter TX or not.
*/
#define TX_PPDU_START_13_IGNORE_QCU_FILTER_OFFSET                    0x00000034
#define TX_PPDU_START_13_IGNORE_QCU_FILTER_LSB                       18
#define TX_PPDU_START_13_IGNORE_QCU_FILTER_MASK                      0x00040000

/* Description		TX_PPDU_START_13_REPLACE_QOS_CTL
			If set the OLE will insert/replace the QoS control field in
			the MPDU.
*/
#define TX_PPDU_START_13_REPLACE_QOS_CTL_OFFSET                      0x00000034
#define TX_PPDU_START_13_REPLACE_QOS_CTL_LSB                         19
#define TX_PPDU_START_13_REPLACE_QOS_CTL_MASK                        0x00080000

/* Description		TX_PPDU_START_13_REPLACE_HT_VHT_CTL
			If set the OLE will insert/replace the HT/VHT control field
			in the MPDU.
*/
#define TX_PPDU_START_13_REPLACE_HT_VHT_CTL_OFFSET                   0x00000034
#define TX_PPDU_START_13_REPLACE_HT_VHT_CTL_LSB                      20
#define TX_PPDU_START_13_REPLACE_HT_VHT_CTL_MASK                     0x00100000

/* Description		TX_PPDU_START_13_REPLACE_DUR
			If set the duration field described below replaces the
			duration field (dur) in the native WiFi format header.  For
			Ethernet II and 802.3 packet formats, the duration field in
			the 802.11 header will be replaced with the dur field in the
			descriptor even if this this bit is not set.  Used by the
			OLE.
*/
#define TX_PPDU_START_13_REPLACE_DUR_OFFSET                          0x00000034
#define TX_PPDU_START_13_REPLACE_DUR_LSB                             21
#define TX_PPDU_START_13_REPLACE_DUR_MASK                            0x00200000

/* Description		TX_PPDU_START_13_FRAME_TYPE
			Frame type indication.  Indicates what type of frame is
			being sent.  Supported values:
			0: default
			1: Reserved (Used to be used for ATIM)
			2: PS-Poll
			3: Beacon
			4: Probe response
			5-15: Reserved
			<legal:0,2,3,4>
*/
#define TX_PPDU_START_13_FRAME_TYPE_OFFSET                           0x00000034
#define TX_PPDU_START_13_FRAME_TYPE_LSB                              22
#define TX_PPDU_START_13_FRAME_TYPE_MASK                             0x03c00000

/* Description		TX_PPDU_START_13_GEN_TPC
			TPC for generated frames such as RTS and self CTS and in the
			future NDP.
*/
#define TX_PPDU_START_13_GEN_TPC_OFFSET                              0x00000034
#define TX_PPDU_START_13_GEN_TPC_LSB                                 26
#define TX_PPDU_START_13_GEN_TPC_MASK                                0xfc000000

/* Description		TX_PPDU_START_14_BURST_DURATION
			Reserved additional time in the duration field beyond the
			completion of this packet transaction.  Used by PCU to
			generate duration field.
*/
#define TX_PPDU_START_14_BURST_DURATION_OFFSET                       0x00000038
#define TX_PPDU_START_14_BURST_DURATION_LSB                          0
#define TX_PPDU_START_14_BURST_DURATION_MASK                         0x00007fff

/* Description		TX_PPDU_START_14_DUR_UPDATE_EN
			If set indicates that the 802.11 duration field will be
			replaced by the PCU.
*/
#define TX_PPDU_START_14_DUR_UPDATE_EN_OFFSET                        0x00000038
#define TX_PPDU_START_14_DUR_UPDATE_EN_LSB                           15
#define TX_PPDU_START_14_DUR_UPDATE_EN_MASK                          0x00008000

/* Description		TX_PPDU_START_14_FRAME_CONTROL
			802.11 Frame control field:
			fc [1:0]: Protocol Version
			fc [3:2]: Type
			fc [7:4]: Subtype
			fc [8]: To DS
			fc [9]: From DS
			fc [10]: More Frag
			fc [11]: Retry
			fc [12]: Pwr Mgt
			fc [13]: More Data
			fc [14]: Protected Frame
			fc [15]: Order
			Used by OLE during the encapsulation process for Native
				WiFi, Ethernet II, and 802.3.
*/
#define TX_PPDU_START_14_FRAME_CONTROL_OFFSET                        0x00000038
#define TX_PPDU_START_14_FRAME_CONTROL_LSB                           16
#define TX_PPDU_START_14_FRAME_CONTROL_MASK                          0xffff0000

/* Description		TX_PPDU_START_15_DURATION
			Normally HW will update the 802.11 duration field (set
			update_dur_en descriptor to enable this behavior).  If it is
			not set then HW will insert this field into the duration
			field of the 802.11 header unless the packet is encapsulated
			in RAW format.  Note: when transmitting PS-Poll frames, this
			field will be set to the AID value and dur[15:14] set to
			0x3.  This field is inserted into the 802.11 header during
			the encapsulation process by the OLE.
*/
#define TX_PPDU_START_15_DURATION_OFFSET                             0x0000003c
#define TX_PPDU_START_15_DURATION_LSB                                0
#define TX_PPDU_START_15_DURATION_MASK                               0x0000ffff

/* Description		TX_PPDU_START_15_QOS_CTL
			QoS control field is valid if the type field is data and the
			upper bit of the subtype field is set.  The field decode is
			as below:
			qos_ctl[3:0]: TID
			qos_ctl[4]: EOSP (with some exceptions)
			qos_ctl[6:5]: Ack Policy
			0x0: Normal Ack or Implicit BAR
			0x1: No Ack
			0x2: No explicit Ack or PSMP Ack (not supported)
			0x3: Block Ack (Not supported)
			Qos_ctl[7]: A-MSDU Present (with some exceptions)
			Qos_ctl[15:8]: TXOP limit, AP PS buffer state, TXOP duration
				requested or queue size (Not supported)
			This field is inserted into the 802.11 header during the
				encapsulation process
			<legal[3:0]:0-7><legal[4]:0,1><legal[6:5]:0,
				1><legal[7]:0,1><legal[15:8]:0>
*/
#define TX_PPDU_START_15_QOS_CTL_OFFSET                              0x0000003c
#define TX_PPDU_START_15_QOS_CTL_LSB                                 16
#define TX_PPDU_START_15_QOS_CTL_MASK                                0xffff0000

/* Description		TX_PPDU_START_16_HT_VHT_CTL
			If the Order bit is set then this frame includes the HT/VHT
			control field.  The HT control field is used for fast link
			adaptation, TxBF support, and RDG support.  WiFi 1.0 does
			not support FLA, RDG, and implicit TxBF.
			If ht_vht_ctl[0] is 0, this is a HT control field:
			ht_vht_ctl[15:0]: Link Adaptation Control (FLA)
			ht_vht_ctl[17:16]: Calibration Position (Implicit TxBF)
			ht_vht_ctl[19:18]: Calibration Sequence (Implicit TxBF)
			ht_vht_ctl[21:20]: Reserved
			ht_vht_ctl[23:22]: CSI/Steering (TxBF: NDP) Only set for
				transmit NDP Announcement frames.  (No support for staggered
				sounding). Only compressed beamforming is supported
			ht_vht_ctl[24]: NDP Announcement (TxBF: NDP).  Indicates
				that this is an NDP announcement frame.  The next PPDU after
				SIFS will be NDP.
			ht_vht_ctl[29:25]: Reserved
			ht_vht_ctl[30] AC Constraint (RDG)
			ht_vht_ctl[31] RDG/More PPDU (RDG)
			If ht_vht_ctl[0] is 1, this is a VHT control field
			No plan to support this in WiFi 1.0.  Used by OLE
			<legal[31:0]:0>
*/
#define TX_PPDU_START_16_HT_VHT_CTL_OFFSET                           0x00000040
#define TX_PPDU_START_16_HT_VHT_CTL_LSB                              0
#define TX_PPDU_START_16_HT_VHT_CTL_MASK                             0xffffffff

/* Description		TX_PPDU_START_17_CV_PTR
			Points to the compressed V data structure.  Fetched by DMA
			and compressed V data structure will be consumed by the SVD
			in the BB.  Used by DMA.
*/
#define TX_PPDU_START_17_CV_PTR_OFFSET                               0x00000044
#define TX_PPDU_START_17_CV_PTR_LSB                                  0
#define TX_PPDU_START_17_CV_PTR_MASK                                 0xffffffff

/* Description		TX_PPDU_START_18_TX_ANTENNA_S0
			Sectored transmit antenna for series 0
*/
#define TX_PPDU_START_18_TX_ANTENNA_S0_OFFSET                        0x00000048
#define TX_PPDU_START_18_TX_ANTENNA_S0_LSB                           0
#define TX_PPDU_START_18_TX_ANTENNA_S0_MASK                          0x00ffffff

/* Description		TX_PPDU_START_18_PAPRD_CHAIN_MASK
			Information is the chain mask used by BB for calibration of
			the power amplifier (PA) predistortion (PRD) path.  Used by
			PCU to generate BB descriptor.  paprd_chain_mask[3] is
			reserved for WiFi 1.0
*/
#define TX_PPDU_START_18_PAPRD_CHAIN_MASK_OFFSET                     0x00000048
#define TX_PPDU_START_18_PAPRD_CHAIN_MASK_LSB                        24
#define TX_PPDU_START_18_PAPRD_CHAIN_MASK_MASK                       0x0f000000

/* Description		TX_PPDU_START_18_RAW_UPDATE_SEQNUM
			If set the tx_ppdu_start seqnum mechanism is used to update
			the sequence number if the MPDU is in RAW format.  If clear,
			the sequence number in the MPDU is unchanged if the MPDU is
			in RAW format.
*/
#define TX_PPDU_START_18_RAW_UPDATE_SEQNUM_OFFSET                    0x00000048
#define TX_PPDU_START_18_RAW_UPDATE_SEQNUM_LSB                       28
#define TX_PPDU_START_18_RAW_UPDATE_SEQNUM_MASK                      0x10000000

/* Description		TX_PPDU_START_18_RAW_ALREADY_ENCRYPTED
			If set it indicates that the RAW MPDU has already been
			encrypted and does not require HW encryption.  If clear and
			if the frame control indicates that this is a 'protected'
			MPDU and the peer key type indicates a cipher type then the
			HW is expected to encrypt this packet.
*/
#define TX_PPDU_START_18_RAW_ALREADY_ENCRYPTED_OFFSET                0x00000048
#define TX_PPDU_START_18_RAW_ALREADY_ENCRYPTED_LSB                   29
#define TX_PPDU_START_18_RAW_ALREADY_ENCRYPTED_MASK                  0x20000000

/* Description		TX_PPDU_START_18_RAW_UPDATE_IV
			If set the tx_ppdu_start IV mechanism is used to update the
			IV if the MPDU is in RAW format.  If clear, the IV in the
			MPDU is unchanged if the MPDU is in RAW format.
*/
#define TX_PPDU_START_18_RAW_UPDATE_IV_OFFSET                        0x00000048
#define TX_PPDU_START_18_RAW_UPDATE_IV_LSB                           30
#define TX_PPDU_START_18_RAW_UPDATE_IV_MASK                          0x40000000

/* Description		TX_PPDU_START_18_VMF
			If set enables VMF bursting (Virtual More Fragment) bursting
			which provides SIFS based bursting based on TXOP.  It also
			allows for the cancelling of RTS or self-CTS in the middle
			of a SIFS burst.
*/
#define TX_PPDU_START_18_VMF_OFFSET                                  0x00000048
#define TX_PPDU_START_18_VMF_LSB                                     31
#define TX_PPDU_START_18_VMF_MASK                                    0x80000000

/* Description		TX_PPDU_START_19_TX_ANTENNA_S1
			Sectored transmit antenna for series 1
*/
#define TX_PPDU_START_19_TX_ANTENNA_S1_OFFSET                        0x0000004c
#define TX_PPDU_START_19_TX_ANTENNA_S1_LSB                           0
#define TX_PPDU_START_19_TX_ANTENNA_S1_MASK                          0x00ffffff

/* Description		TX_PPDU_START_19_RTS_RATE
			Same format as the 'rate' field.  Only single stream RTS is
			possible.
*/
#define TX_PPDU_START_19_RTS_RATE_OFFSET                             0x0000004c
#define TX_PPDU_START_19_RTS_RATE_LSB                                24
#define TX_PPDU_START_19_RTS_RATE_MASK                               0x0f000000

/* Description		TX_PPDU_START_19_RTS_PREAMBLE_TYPE
			Preamble type for the RTS frame.  Same format as the
			'preamble_type' field.
*/
#define TX_PPDU_START_19_RTS_PREAMBLE_TYPE_OFFSET                    0x0000004c
#define TX_PPDU_START_19_RTS_PREAMBLE_TYPE_LSB                       28
#define TX_PPDU_START_19_RTS_PREAMBLE_TYPE_MASK                      0x30000000

/* Description		TX_PPDU_START_19_BB_CAPTURE_CHANNEL
			Indicate to the BB via the BB descriptor to capture the
			channel for a good receive packet.
*/
#define TX_PPDU_START_19_BB_CAPTURE_CHANNEL_OFFSET                   0x0000004c
#define TX_PPDU_START_19_BB_CAPTURE_CHANNEL_LSB                      30
#define TX_PPDU_START_19_BB_CAPTURE_CHANNEL_MASK                     0x40000000

/* Description		TX_PPDU_START_19_RESERVED_19
			Reserved.  Not used by HW.
			<legal:0>
*/
#define TX_PPDU_START_19_RESERVED_19_OFFSET                          0x0000004c
#define TX_PPDU_START_19_RESERVED_19_LSB                             31
#define TX_PPDU_START_19_RESERVED_19_MASK                            0x80000000

/* Description		TX_PPDU_START_20_CV_LEN
			Number of octets in the compress V data structure to fetch. 
			Used by DMA.
			<legal:0-2047>
*/
#define TX_PPDU_START_20_CV_LEN_OFFSET                               0x00000050
#define TX_PPDU_START_20_CV_LEN_LSB                                  0
#define TX_PPDU_START_20_CV_LEN_MASK                                 0x0000ffff

/* Description		TX_PPDU_START_20_TRIES_S0
			Tries series 0 indicates the maximum number of transmission
			attempts at transmit series 0.  A transmission attempt
			includes RTS/CTS failure, data packet failure and data
			packet success.  Each try should correspond to a try_status
			in the tx_ppdu_end.  Used by PCU.  <legal:1-15>
*/
#define TX_PPDU_START_20_TRIES_S0_OFFSET                             0x00000050
#define TX_PPDU_START_20_TRIES_S0_LSB                                16
#define TX_PPDU_START_20_TRIES_S0_MASK                               0x000f0000

/* Description		TX_PPDU_START_20_TRIES_S1
			Tries series 1 indicates the maximum number of transmission
			attempts at transmit series 1.  A transmission attempt
			includes RTS/CTS failure, data packet failure and data
			packet success.  Each try should correspond to a try_status
			in the tx_ppdu_end.  Used by PCU.  <legal:0-15>
*/
#define TX_PPDU_START_20_TRIES_S1_OFFSET                             0x00000050
#define TX_PPDU_START_20_TRIES_S1_LSB                                20
#define TX_PPDU_START_20_TRIES_S1_MASK                               0x00f00000

/* Description		TX_PPDU_START_20_VALID_S0_BW20
			Validity of the series 0 for bandwidth 20 MHz entry.  Used
			by PCU.
*/
#define TX_PPDU_START_20_VALID_S0_BW20_OFFSET                        0x00000050
#define TX_PPDU_START_20_VALID_S0_BW20_LSB                           24
#define TX_PPDU_START_20_VALID_S0_BW20_MASK                          0x01000000

/* Description		TX_PPDU_START_20_VALID_S0_BW40
			Validity of the series 0 for bandwidth 40 MHz entry.  Used
			by PCU.
*/
#define TX_PPDU_START_20_VALID_S0_BW40_OFFSET                        0x00000050
#define TX_PPDU_START_20_VALID_S0_BW40_LSB                           25
#define TX_PPDU_START_20_VALID_S0_BW40_MASK                          0x02000000

/* Description		TX_PPDU_START_20_VALID_S0_BW80
			Validity of the series 0 for bandwidth 80 MHz entry.  Used
			by PCU.
*/
#define TX_PPDU_START_20_VALID_S0_BW80_OFFSET                        0x00000050
#define TX_PPDU_START_20_VALID_S0_BW80_LSB                           26
#define TX_PPDU_START_20_VALID_S0_BW80_MASK                          0x04000000

/* Description		TX_PPDU_START_20_VALID_S0_BW160
			Validity of the series 0 for bandwidth 160 MHz entry.  Used
			by PCU.
			<legal:0>
*/
#define TX_PPDU_START_20_VALID_S0_BW160_OFFSET                       0x00000050
#define TX_PPDU_START_20_VALID_S0_BW160_LSB                          27
#define TX_PPDU_START_20_VALID_S0_BW160_MASK                         0x08000000

/* Description		TX_PPDU_START_20_VALID_S1_BW20
			Validity of the series 1 for bandwidth 20 MHz entry.  Used
			by PCU.
*/
#define TX_PPDU_START_20_VALID_S1_BW20_OFFSET                        0x00000050
#define TX_PPDU_START_20_VALID_S1_BW20_LSB                           28
#define TX_PPDU_START_20_VALID_S1_BW20_MASK                          0x10000000

/* Description		TX_PPDU_START_20_VALID_S1_BW40
			Validity of the series 1 for bandwidth 40 MHz entry.  Used
			by PCU.
*/
#define TX_PPDU_START_20_VALID_S1_BW40_OFFSET                        0x00000050
#define TX_PPDU_START_20_VALID_S1_BW40_LSB                           29
#define TX_PPDU_START_20_VALID_S1_BW40_MASK                          0x20000000

/* Description		TX_PPDU_START_20_VALID_S1_BW80
			Validity of the series 1 for bandwidth 80 MHz entry.  Used
			by PCU.
*/
#define TX_PPDU_START_20_VALID_S1_BW80_OFFSET                        0x00000050
#define TX_PPDU_START_20_VALID_S1_BW80_LSB                           30
#define TX_PPDU_START_20_VALID_S1_BW80_MASK                          0x40000000

/* Description		TX_PPDU_START_20_VALID_S1_BW160
			Validity of the series 1 for bandwidth 160 MHz entry.  Used
			by PCU.
			<legal:0>
*/
#define TX_PPDU_START_20_VALID_S1_BW160_OFFSET                       0x00000050
#define TX_PPDU_START_20_VALID_S1_BW160_LSB                          31
#define TX_PPDU_START_20_VALID_S1_BW160_MASK                         0x80000000
#define TX_PPDU_START_21_SERIES_BW_S0_BW20_OFFSET                    0x00000054
#define TX_PPDU_START_21_SERIES_BW_S0_BW20_LSB                       31
#define TX_PPDU_START_21_SERIES_BW_S0_BW20_MASK                      0xffffffff
#define TX_PPDU_START_22_SERIES_BW_S0_BW20_OFFSET                    0x00000058
#define TX_PPDU_START_22_SERIES_BW_S0_BW20_LSB                       31
#define TX_PPDU_START_22_SERIES_BW_S0_BW20_MASK                      0xffffffff
#define TX_PPDU_START_23_SERIES_BW_S0_BW20_OFFSET                    0x0000005c
#define TX_PPDU_START_23_SERIES_BW_S0_BW20_LSB                       31
#define TX_PPDU_START_23_SERIES_BW_S0_BW20_MASK                      0xffffffff
#define TX_PPDU_START_24_SERIES_BW_S0_BW20_OFFSET                    0x00000060
#define TX_PPDU_START_24_SERIES_BW_S0_BW20_LSB                       31
#define TX_PPDU_START_24_SERIES_BW_S0_BW20_MASK                      0xffffffff
#define TX_PPDU_START_25_SERIES_BW_S0_BW40_OFFSET                    0x00000064
#define TX_PPDU_START_25_SERIES_BW_S0_BW40_LSB                       31
#define TX_PPDU_START_25_SERIES_BW_S0_BW40_MASK                      0xffffffff
#define TX_PPDU_START_26_SERIES_BW_S0_BW40_OFFSET                    0x00000068
#define TX_PPDU_START_26_SERIES_BW_S0_BW40_LSB                       31
#define TX_PPDU_START_26_SERIES_BW_S0_BW40_MASK                      0xffffffff
#define TX_PPDU_START_27_SERIES_BW_S0_BW40_OFFSET                    0x0000006c
#define TX_PPDU_START_27_SERIES_BW_S0_BW40_LSB                       31
#define TX_PPDU_START_27_SERIES_BW_S0_BW40_MASK                      0xffffffff
#define TX_PPDU_START_28_SERIES_BW_S0_BW40_OFFSET                    0x00000070
#define TX_PPDU_START_28_SERIES_BW_S0_BW40_LSB                       31
#define TX_PPDU_START_28_SERIES_BW_S0_BW40_MASK                      0xffffffff
#define TX_PPDU_START_29_SERIES_BW_S0_BW80_OFFSET                    0x00000074
#define TX_PPDU_START_29_SERIES_BW_S0_BW80_LSB                       31
#define TX_PPDU_START_29_SERIES_BW_S0_BW80_MASK                      0xffffffff
#define TX_PPDU_START_30_SERIES_BW_S0_BW80_OFFSET                    0x00000078
#define TX_PPDU_START_30_SERIES_BW_S0_BW80_LSB                       31
#define TX_PPDU_START_30_SERIES_BW_S0_BW80_MASK                      0xffffffff
#define TX_PPDU_START_31_SERIES_BW_S0_BW80_OFFSET                    0x0000007c
#define TX_PPDU_START_31_SERIES_BW_S0_BW80_LSB                       31
#define TX_PPDU_START_31_SERIES_BW_S0_BW80_MASK                      0xffffffff
#define TX_PPDU_START_32_SERIES_BW_S0_BW80_OFFSET                    0x00000080
#define TX_PPDU_START_32_SERIES_BW_S0_BW80_LSB                       31
#define TX_PPDU_START_32_SERIES_BW_S0_BW80_MASK                      0xffffffff
#define TX_PPDU_START_33_SERIES_BW_S0_BW160_OFFSET                   0x00000084
#define TX_PPDU_START_33_SERIES_BW_S0_BW160_LSB                      31
#define TX_PPDU_START_33_SERIES_BW_S0_BW160_MASK                     0xffffffff
#define TX_PPDU_START_34_SERIES_BW_S0_BW160_OFFSET                   0x00000088
#define TX_PPDU_START_34_SERIES_BW_S0_BW160_LSB                      31
#define TX_PPDU_START_34_SERIES_BW_S0_BW160_MASK                     0xffffffff
#define TX_PPDU_START_35_SERIES_BW_S0_BW160_OFFSET                   0x0000008c
#define TX_PPDU_START_35_SERIES_BW_S0_BW160_LSB                      31
#define TX_PPDU_START_35_SERIES_BW_S0_BW160_MASK                     0xffffffff
#define TX_PPDU_START_36_SERIES_BW_S0_BW160_OFFSET                   0x00000090
#define TX_PPDU_START_36_SERIES_BW_S0_BW160_LSB                      31
#define TX_PPDU_START_36_SERIES_BW_S0_BW160_MASK                     0xffffffff
#define TX_PPDU_START_37_SERIES_BW_S1_BW20_OFFSET                    0x00000094
#define TX_PPDU_START_37_SERIES_BW_S1_BW20_LSB                       31
#define TX_PPDU_START_37_SERIES_BW_S1_BW20_MASK                      0xffffffff
#define TX_PPDU_START_38_SERIES_BW_S1_BW20_OFFSET                    0x00000098
#define TX_PPDU_START_38_SERIES_BW_S1_BW20_LSB                       31
#define TX_PPDU_START_38_SERIES_BW_S1_BW20_MASK                      0xffffffff
#define TX_PPDU_START_39_SERIES_BW_S1_BW20_OFFSET                    0x0000009c
#define TX_PPDU_START_39_SERIES_BW_S1_BW20_LSB                       31
#define TX_PPDU_START_39_SERIES_BW_S1_BW20_MASK                      0xffffffff
#define TX_PPDU_START_40_SERIES_BW_S1_BW20_OFFSET                    0x000000a0
#define TX_PPDU_START_40_SERIES_BW_S1_BW20_LSB                       31
#define TX_PPDU_START_40_SERIES_BW_S1_BW20_MASK                      0xffffffff
#define TX_PPDU_START_41_SERIES_BW_S1_BW40_OFFSET                    0x000000a4
#define TX_PPDU_START_41_SERIES_BW_S1_BW40_LSB                       31
#define TX_PPDU_START_41_SERIES_BW_S1_BW40_MASK                      0xffffffff
#define TX_PPDU_START_42_SERIES_BW_S1_BW40_OFFSET                    0x000000a8
#define TX_PPDU_START_42_SERIES_BW_S1_BW40_LSB                       31
#define TX_PPDU_START_42_SERIES_BW_S1_BW40_MASK                      0xffffffff
#define TX_PPDU_START_43_SERIES_BW_S1_BW40_OFFSET                    0x000000ac
#define TX_PPDU_START_43_SERIES_BW_S1_BW40_LSB                       31
#define TX_PPDU_START_43_SERIES_BW_S1_BW40_MASK                      0xffffffff
#define TX_PPDU_START_44_SERIES_BW_S1_BW40_OFFSET                    0x000000b0
#define TX_PPDU_START_44_SERIES_BW_S1_BW40_LSB                       31
#define TX_PPDU_START_44_SERIES_BW_S1_BW40_MASK                      0xffffffff
#define TX_PPDU_START_45_SERIES_BW_S1_BW80_OFFSET                    0x000000b4
#define TX_PPDU_START_45_SERIES_BW_S1_BW80_LSB                       31
#define TX_PPDU_START_45_SERIES_BW_S1_BW80_MASK                      0xffffffff
#define TX_PPDU_START_46_SERIES_BW_S1_BW80_OFFSET                    0x000000b8
#define TX_PPDU_START_46_SERIES_BW_S1_BW80_LSB                       31
#define TX_PPDU_START_46_SERIES_BW_S1_BW80_MASK                      0xffffffff
#define TX_PPDU_START_47_SERIES_BW_S1_BW80_OFFSET                    0x000000bc
#define TX_PPDU_START_47_SERIES_BW_S1_BW80_LSB                       31
#define TX_PPDU_START_47_SERIES_BW_S1_BW80_MASK                      0xffffffff
#define TX_PPDU_START_48_SERIES_BW_S1_BW80_OFFSET                    0x000000c0
#define TX_PPDU_START_48_SERIES_BW_S1_BW80_LSB                       31
#define TX_PPDU_START_48_SERIES_BW_S1_BW80_MASK                      0xffffffff
#define TX_PPDU_START_49_SERIES_BW_S1_BW160_OFFSET                   0x000000c4
#define TX_PPDU_START_49_SERIES_BW_S1_BW160_LSB                      31
#define TX_PPDU_START_49_SERIES_BW_S1_BW160_MASK                     0xffffffff
#define TX_PPDU_START_50_SERIES_BW_S1_BW160_OFFSET                   0x000000c8
#define TX_PPDU_START_50_SERIES_BW_S1_BW160_LSB                      31
#define TX_PPDU_START_50_SERIES_BW_S1_BW160_MASK                     0xffffffff
#define TX_PPDU_START_51_SERIES_BW_S1_BW160_OFFSET                   0x000000cc
#define TX_PPDU_START_51_SERIES_BW_S1_BW160_LSB                      31
#define TX_PPDU_START_51_SERIES_BW_S1_BW160_MASK                     0xffffffff
#define TX_PPDU_START_52_SERIES_BW_S1_BW160_OFFSET                   0x000000d0
#define TX_PPDU_START_52_SERIES_BW_S1_BW160_LSB                      31
#define TX_PPDU_START_52_SERIES_BW_S1_BW160_MASK                     0xffffffff

/* Description		TX_PPDU_START_53_TX_PPDU_END_PTR
			The pointer to the buffer where the MAC will write the
			transmit status (tx_ppdu_end) associated with this PPDU.
*/
#define TX_PPDU_START_53_TX_PPDU_END_PTR_OFFSET                      0x000000d4
#define TX_PPDU_START_53_TX_PPDU_END_PTR_LSB                         0
#define TX_PPDU_START_53_TX_PPDU_END_PTR_MASK                        0xffffffff

/* Description		TX_PPDU_START_54_PARTIAL_AID
			The partial AID field to be inserted into VHT SIG A.  Field
			is invalid for CCK, legacy OFDM, and HT rates.
*/
#define TX_PPDU_START_54_PARTIAL_AID_OFFSET                          0x000000d8
#define TX_PPDU_START_54_PARTIAL_AID_LSB                             0
#define TX_PPDU_START_54_PARTIAL_AID_MASK                            0x000001ff

/* Description		TX_PPDU_START_54_RESERVED_54A
			Reserved.  Not used by HW.
			<legal:0>
*/
#define TX_PPDU_START_54_RESERVED_54A_OFFSET                         0x000000d8
#define TX_PPDU_START_54_RESERVED_54A_LSB                            9
#define TX_PPDU_START_54_RESERVED_54A_MASK                           0x0000fe00

/* Description		TX_PPDU_START_54_GROUP_ID
			The group ID field is used in VHT SIG A.  Only legal values
			are 0 and 63 since MU is not supported.  If this is a PPDU
			is addressed to an AP or a mesh STA it is 0; otherwise, it
			is only 63. <legal:0,63>
*/
#define TX_PPDU_START_54_GROUP_ID_OFFSET                             0x000000d8
#define TX_PPDU_START_54_GROUP_ID_LSB                                16
#define TX_PPDU_START_54_GROUP_ID_MASK                               0x003f0000

/* Description		TX_PPDU_START_54_RESERVED_54B
			Reserved.  Not used by HW.
			<legal:0>
*/
#define TX_PPDU_START_54_RESERVED_54B_OFFSET                         0x000000d8
#define TX_PPDU_START_54_RESERVED_54B_LSB                            22
#define TX_PPDU_START_54_RESERVED_54B_MASK                           0x7fc00000

/* Description		TX_PPDU_START_54_TXOP_PS_NOT_ALLOWED
			The 11ac standard says: 'Set to 0 by VHT AP if it allows
			non-AP VHT STAs in TXOP power save mode to enter Doze state
			during a TXOP.  Set to 1 otherwise.  The bit is reserved and
			set to 1 in VHT PPDUs transmitted by a non-AP VHT STA.' 
			There is no plan to support this feature.  This field should
			always be set to 1.
			<legal:1>
*/
#define TX_PPDU_START_54_TXOP_PS_NOT_ALLOWED_OFFSET                  0x000000d8
#define TX_PPDU_START_54_TXOP_PS_NOT_ALLOWED_LSB                     31
#define TX_PPDU_START_54_TXOP_PS_NOT_ALLOWED_MASK                    0x80000000


#endif // _TX_PPDU_START_H_
