// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _TX_MSDU_START_H_
#define _TX_MSDU_START_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	msdu_frag_ptr[31:0]
//	1	next_msdu_ptr[31:0]
//	2	mpdu_len[13:0], wds[14], retry[15], first_msdu[16], last_msdu[17], l4_chksum_en[18], l3_chksum_en[19], encap_type[21:20], use_ad_b[22], toggle_eosp[23], toggle_power_mgmt[24], toggle_more_data[25], reserved[31:26]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_TX_MSDU_START 3

struct tx_msdu_start {
    volatile uint32_t msdu_frag_ptr                   : 32; //[31:0]
    volatile uint32_t next_msdu_ptr                   : 32; //[31:0]
    volatile uint32_t mpdu_len                        : 14, //[13:0]
                      wds                             :  1, //[14]
                      retry                           :  1, //[15]
                      first_msdu                      :  1, //[16]
                      last_msdu                       :  1, //[17]
                      l4_chksum_en                    :  1, //[18]
                      l3_chksum_en                    :  1, //[19]
                      encap_type                      :  2, //[21:20]
                      use_ad_b                        :  1, //[22]
                      toggle_eosp                     :  1, //[23]
                      toggle_power_mgmt               :  1, //[24]
                      toggle_more_data                :  1, //[25]
                      reserved                        :  6; //[31:26]
};

/*

msdu_frag_ptr
			Pointer to the table which has all the pointer / length
			tuples necessary to gather the buffer fragments to form an
			MSDU.  This data structure is called the MSDU fragmentation
			table.  FW will write the 'Number of MSDU buffers pointers'
			register which the MAC will use to fetch the appropriate
			number of fragment entries.  Each entry in the MSDU
			fragmentation table contains msdu_frag_ptr and buf_len.  Not
			all MSDU will require the maximum number of pointer/length
			tuples that HW will fetch.  The first tuple with
			msdu_frag_ptr of 0 indicates the end of the MSDU. 
			Associated Register 'MAX_NUMBER_OF_BUFFERS' indicates the
			maximum number of buf_ptr & buf_len tuple entries in the
			msdu_frag_table that HW will fetch to form a MSDU.  Used by
			the DMA.

next_msdu_ptr
			Pointer to next MSDU descriptor.  This will only be null at
			the end of the connection queue.  If this is null and the
			MAC thinks that additional MSDUs are required an error
			interrupt will be asserted.  Used by the DMA.

mpdu_len
			This field is overlaid: when SW passes it to FW, this field
			contains total MSDU length which is split over multiple
			buf_ptr's. FW will use this MSDU length to calculate MPDU
			length.  When FW passes it to HW, this field contains MPDU
			length, which covers everything, 802.11 header including QoS
			control, HT/VHT control, IV pad, IV, and ICV but not
			including the FCS.  (IV pad will be 0 to 2 bytes such that
			IV starts on a dword boundary).  FW will calculate mpdu_len
			and update this field.  The mpdu_len field is only valid for
			HW when first_msdu bit is set.   Used by the OLE during
			encapsulation.   Used by the PCU to form MPDU start
			delimiter by subtracting iv_pad and adding 4 for FCS.

wds
			If set the current packet is 4-address frame.  Required
			because an aggregate can include some frames with 3 address
			format and other frames with 4 address format.  The wds bit
			is only valid when first_msdu bit is set.  Used by the OLE
			during encapsulation.  Used by the PCU to determine offset
			of IV for encryption and to strip MAC header padding for
			transmission.

retry
			If set the retry bit in the frame control field of the
			802.11 header will be set.  If clear the retry bit in the
			frame control field will remain unchanged.  Used by the OLE
			during encapsulation.

first_msdu
			If set the current MSDU is the first MSDU in MPDU.  Used by
			the OLE during encapsulation.

last_msdu
			If set the current MSDU is the last MSDU in MPDU.  Used by
			the OLE during encapsulation.

l4_chksum_en
			If set the TCP/UDP checksum will be updated by HW.  Used by
			the OLE during encapsulation.

l3_chksum_en
			If set the IP checksum will be updated by HW.  Used by the
			OLE during encapsulation.  Unsupported in WiFi 1

encap_type
			Indicates the encapsulation that HW will perform:
			0: RAW: no encapsulation
			1: Native WiFi
			2: Ethernet 2 (DIX)
			3: 802.3 (uses SNAP/LLC)
			Used by the OLE during encapsulation.

use_ad_b
			Normally in AP mode the DA address is used as the RA.  This
			is normally fine but the use_ad_b bit should be set when DA
			is a multicast/broadcast address but we want to send this
			packet using the destination STA address which will be held
			in the mac_addr_b field of the peer descriptor.

toggle_eosp
			Toggle the EOSP bit in the QoS control field of the
			tx_ppdu_start descriptor.  Used by the OLE during
			encapsulation.

toggle_power_mgmt
			Toggle the power management bit in the frame control field
			of the tx_ppdu_start descriptor.  Used by the OLE during
			encapsulation.

toggle_more_data
			Toggle the A-MSDU bit in the QoS control field of the
			tx_ppdu_start descriptor.  Used by the OLE during
			encapsulation.

reserved
			Unused by hardware.  FW may use this for timestamp in units
			of msec to implement a time-to-live mechanism.
*/


/* Description		TX_MSDU_START_0_MSDU_FRAG_PTR
			Pointer to the table which has all the pointer / length
			tuples necessary to gather the buffer fragments to form an
			MSDU.  This data structure is called the MSDU fragmentation
			table.  FW will write the 'Number of MSDU buffers pointers'
			register which the MAC will use to fetch the appropriate
			number of fragment entries.  Each entry in the MSDU
			fragmentation table contains msdu_frag_ptr and buf_len.  Not
			all MSDU will require the maximum number of pointer/length
			tuples that HW will fetch.  The first tuple with
			msdu_frag_ptr of 0 indicates the end of the MSDU. 
			Associated Register 'MAX_NUMBER_OF_BUFFERS' indicates the
			maximum number of buf_ptr & buf_len tuple entries in the
			msdu_frag_table that HW will fetch to form a MSDU.  Used by
			the DMA.
*/
#define TX_MSDU_START_0_MSDU_FRAG_PTR_OFFSET                         0x00000000
#define TX_MSDU_START_0_MSDU_FRAG_PTR_LSB                            0
#define TX_MSDU_START_0_MSDU_FRAG_PTR_MASK                           0xffffffff

/* Description		TX_MSDU_START_1_NEXT_MSDU_PTR
			Pointer to next MSDU descriptor.  This will only be null at
			the end of the connection queue.  If this is null and the
			MAC thinks that additional MSDUs are required an error
			interrupt will be asserted.  Used by the DMA.
*/
#define TX_MSDU_START_1_NEXT_MSDU_PTR_OFFSET                         0x00000004
#define TX_MSDU_START_1_NEXT_MSDU_PTR_LSB                            0
#define TX_MSDU_START_1_NEXT_MSDU_PTR_MASK                           0xffffffff

/* Description		TX_MSDU_START_2_MPDU_LEN
			This field is overlaid: when SW passes it to FW, this field
			contains total MSDU length which is split over multiple
			buf_ptr's. FW will use this MSDU length to calculate MPDU
			length.  When FW passes it to HW, this field contains MPDU
			length, which covers everything, 802.11 header including QoS
			control, HT/VHT control, IV pad, IV, and ICV but not
			including the FCS.  (IV pad will be 0 to 2 bytes such that
			IV starts on a dword boundary).  FW will calculate mpdu_len
			and update this field.  The mpdu_len field is only valid for
			HW when first_msdu bit is set.   Used by the OLE during
			encapsulation.   Used by the PCU to form MPDU start
			delimiter by subtracting iv_pad and adding 4 for FCS.
*/
#define TX_MSDU_START_2_MPDU_LEN_OFFSET                              0x00000008
#define TX_MSDU_START_2_MPDU_LEN_LSB                                 0
#define TX_MSDU_START_2_MPDU_LEN_MASK                                0x00003fff

/* Description		TX_MSDU_START_2_WDS
			If set the current packet is 4-address frame.  Required
			because an aggregate can include some frames with 3 address
			format and other frames with 4 address format.  The wds bit
			is only valid when first_msdu bit is set.  Used by the OLE
			during encapsulation.  Used by the PCU to determine offset
			of IV for encryption and to strip MAC header padding for
			transmission.
*/
#define TX_MSDU_START_2_WDS_OFFSET                                   0x00000008
#define TX_MSDU_START_2_WDS_LSB                                      14
#define TX_MSDU_START_2_WDS_MASK                                     0x00004000

/* Description		TX_MSDU_START_2_RETRY
			If set the retry bit in the frame control field of the
			802.11 header will be set.  If clear the retry bit in the
			frame control field will remain unchanged.  Used by the OLE
			during encapsulation.
*/
#define TX_MSDU_START_2_RETRY_OFFSET                                 0x00000008
#define TX_MSDU_START_2_RETRY_LSB                                    15
#define TX_MSDU_START_2_RETRY_MASK                                   0x00008000

/* Description		TX_MSDU_START_2_FIRST_MSDU
			If set the current MSDU is the first MSDU in MPDU.  Used by
			the OLE during encapsulation.
*/
#define TX_MSDU_START_2_FIRST_MSDU_OFFSET                            0x00000008
#define TX_MSDU_START_2_FIRST_MSDU_LSB                               16
#define TX_MSDU_START_2_FIRST_MSDU_MASK                              0x00010000

/* Description		TX_MSDU_START_2_LAST_MSDU
			If set the current MSDU is the last MSDU in MPDU.  Used by
			the OLE during encapsulation.
*/
#define TX_MSDU_START_2_LAST_MSDU_OFFSET                             0x00000008
#define TX_MSDU_START_2_LAST_MSDU_LSB                                17
#define TX_MSDU_START_2_LAST_MSDU_MASK                               0x00020000

/* Description		TX_MSDU_START_2_L4_CHKSUM_EN
			If set the TCP/UDP checksum will be updated by HW.  Used by
			the OLE during encapsulation.
*/
#define TX_MSDU_START_2_L4_CHKSUM_EN_OFFSET                          0x00000008
#define TX_MSDU_START_2_L4_CHKSUM_EN_LSB                             18
#define TX_MSDU_START_2_L4_CHKSUM_EN_MASK                            0x00040000

/* Description		TX_MSDU_START_2_L3_CHKSUM_EN
			If set the IP checksum will be updated by HW.  Used by the
			OLE during encapsulation.  Unsupported in WiFi 1
*/
#define TX_MSDU_START_2_L3_CHKSUM_EN_OFFSET                          0x00000008
#define TX_MSDU_START_2_L3_CHKSUM_EN_LSB                             19
#define TX_MSDU_START_2_L3_CHKSUM_EN_MASK                            0x00080000

/* Description		TX_MSDU_START_2_ENCAP_TYPE
			Indicates the encapsulation that HW will perform:
			0: RAW: no encapsulation
			1: Native WiFi
			2: Ethernet 2 (DIX)
			3: 802.3 (uses SNAP/LLC)
			Used by the OLE during encapsulation.
*/
#define TX_MSDU_START_2_ENCAP_TYPE_OFFSET                            0x00000008
#define TX_MSDU_START_2_ENCAP_TYPE_LSB                               20
#define TX_MSDU_START_2_ENCAP_TYPE_MASK                              0x00300000

/* Description		TX_MSDU_START_2_USE_AD_B
			Normally in AP mode the DA address is used as the RA.  This
			is normally fine but the use_ad_b bit should be set when DA
			is a multicast/broadcast address but we want to send this
			packet using the destination STA address which will be held
			in the mac_addr_b field of the peer descriptor.
*/
#define TX_MSDU_START_2_USE_AD_B_OFFSET                              0x00000008
#define TX_MSDU_START_2_USE_AD_B_LSB                                 22
#define TX_MSDU_START_2_USE_AD_B_MASK                                0x00400000

/* Description		TX_MSDU_START_2_TOGGLE_EOSP
			Toggle the EOSP bit in the QoS control field of the
			tx_ppdu_start descriptor.  Used by the OLE during
			encapsulation.
*/
#define TX_MSDU_START_2_TOGGLE_EOSP_OFFSET                           0x00000008
#define TX_MSDU_START_2_TOGGLE_EOSP_LSB                              23
#define TX_MSDU_START_2_TOGGLE_EOSP_MASK                             0x00800000

/* Description		TX_MSDU_START_2_TOGGLE_POWER_MGMT
			Toggle the power management bit in the frame control field
			of the tx_ppdu_start descriptor.  Used by the OLE during
			encapsulation.
*/
#define TX_MSDU_START_2_TOGGLE_POWER_MGMT_OFFSET                     0x00000008
#define TX_MSDU_START_2_TOGGLE_POWER_MGMT_LSB                        24
#define TX_MSDU_START_2_TOGGLE_POWER_MGMT_MASK                       0x01000000

/* Description		TX_MSDU_START_2_TOGGLE_MORE_DATA
			Toggle the A-MSDU bit in the QoS control field of the
			tx_ppdu_start descriptor.  Used by the OLE during
			encapsulation.
*/
#define TX_MSDU_START_2_TOGGLE_MORE_DATA_OFFSET                      0x00000008
#define TX_MSDU_START_2_TOGGLE_MORE_DATA_LSB                         25
#define TX_MSDU_START_2_TOGGLE_MORE_DATA_MASK                        0x02000000

/* Description		TX_MSDU_START_2_RESERVED
			Unused by hardware.  FW may use this for timestamp in units
			of msec to implement a time-to-live mechanism.
*/
#define TX_MSDU_START_2_RESERVED_OFFSET                              0x00000008
#define TX_MSDU_START_2_RESERVED_LSB                                 26
#define TX_MSDU_START_2_RESERVED_MASK                                0xfc000000


#endif // _TX_MSDU_START_H_
