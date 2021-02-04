// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _TX_MSDU_END_H_
#define _TX_MSDU_END_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	chksum_offset[13:0], chksum_upper[14], chksum_replace_en[15], reserved_0[31:16]
//	1	chksum_dword[31:0]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_TX_MSDU_END 2

struct tx_msdu_end {
    volatile uint32_t chksum_offset                   : 14, //[13:0]
                      chksum_upper                    :  1, //[14]
                      chksum_replace_en               :  1, //[15]
                      reserved_0                      : 16; //[31:16]
    volatile uint32_t chksum_dword                    : 32; //[31:0]
};

/*

chksum_offset
			Indicates the dword offset of the chksum_dword from the
			start of the packet.

chksum_upper
			Indicates that the TCP/UDP checksum is in the upper 16 bits
			of the chksum_dword or the lower 16 bits of the
			chksum_dword.  (TBD: Is this really needed?)

chksum_replace_en
			If set indicates that the chksum_dword should replace the
			existing dword in the TX PCU buffer.

reserved_0
			Reserved

chksum_dword
			The TCP/UDP checksum is actual 16 bits; however, it is
			difficult to write a 16 bit quantity to the PCU TX buffer. 
			So this dword includes the 16 bit TCP/UDP checksum and the
			16 bits field which is adjacent to the checksum.  The PCU
			will take this 32 field and replace the existing 32 field in
			the PCU TX buffer where the TCP/UDP checksum is located.
*/


/* Description		TX_MSDU_END_0_CHKSUM_OFFSET
			Indicates the dword offset of the chksum_dword from the
			start of the packet.
*/
#define TX_MSDU_END_0_CHKSUM_OFFSET_OFFSET                           0x00000000
#define TX_MSDU_END_0_CHKSUM_OFFSET_LSB                              0
#define TX_MSDU_END_0_CHKSUM_OFFSET_MASK                             0x00003fff

/* Description		TX_MSDU_END_0_CHKSUM_UPPER
			Indicates that the TCP/UDP checksum is in the upper 16 bits
			of the chksum_dword or the lower 16 bits of the
			chksum_dword.  (TBD: Is this really needed?)
*/
#define TX_MSDU_END_0_CHKSUM_UPPER_OFFSET                            0x00000000
#define TX_MSDU_END_0_CHKSUM_UPPER_LSB                               14
#define TX_MSDU_END_0_CHKSUM_UPPER_MASK                              0x00004000

/* Description		TX_MSDU_END_0_CHKSUM_REPLACE_EN
			If set indicates that the chksum_dword should replace the
			existing dword in the TX PCU buffer.
*/
#define TX_MSDU_END_0_CHKSUM_REPLACE_EN_OFFSET                       0x00000000
#define TX_MSDU_END_0_CHKSUM_REPLACE_EN_LSB                          15
#define TX_MSDU_END_0_CHKSUM_REPLACE_EN_MASK                         0x00008000

/* Description		TX_MSDU_END_0_RESERVED_0
			Reserved
*/
#define TX_MSDU_END_0_RESERVED_0_OFFSET                              0x00000000
#define TX_MSDU_END_0_RESERVED_0_LSB                                 16
#define TX_MSDU_END_0_RESERVED_0_MASK                                0xffff0000

/* Description		TX_MSDU_END_1_CHKSUM_DWORD
			The TCP/UDP checksum is actual 16 bits; however, it is
			difficult to write a 16 bit quantity to the PCU TX buffer. 
			So this dword includes the 16 bit TCP/UDP checksum and the
			16 bits field which is adjacent to the checksum.  The PCU
			will take this 32 field and replace the existing 32 field in
			the PCU TX buffer where the TCP/UDP checksum is located.
*/
#define TX_MSDU_END_1_CHKSUM_DWORD_OFFSET                            0x00000004
#define TX_MSDU_END_1_CHKSUM_DWORD_LSB                               0
#define TX_MSDU_END_1_CHKSUM_DWORD_MASK                              0xffffffff


#endif // _TX_MSDU_END_H_
