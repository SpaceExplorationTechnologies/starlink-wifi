// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _CE_SRC_DESC_H_
#define _CE_SRC_DESC_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	src_ptr[31:0]
//	1	src_buf_len[15:0], gather[16], byte_swap[17], meta_data[31:18]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_CE_SRC_DESC 2

struct ce_src_desc {
    volatile uint32_t src_ptr                         : 32; //[31:0]
    volatile uint32_t src_buf_len                     : 16, //[15:0]
                      gather                          :  1, //[16]
                      byte_swap                       :  1, //[17]
                      meta_data                       : 14; //[31:18]
};

/*

src_ptr
			Pointer to the source buffer.  Written by FW/SW.

src_buf_len
			Buffer length of the source buffer in units of octets. 
			Written by FW/SW.

gather
			Enables gather of multiple copy engine source descriptors to
			one destination.  Written by FW/SW.

byte_swap
			Enable byte swap for endian conversion.  For each dword (4
			bytes), the byte 0 is swapped with byte 3 and byte 1 is
			swapped with byte 2.  Written by FW/SW.

meta_data
			Unused by HW.
*/


/* Description		CE_SRC_DESC_0_SRC_PTR
			Pointer to the source buffer.  Written by FW/SW.
*/
#define CE_SRC_DESC_0_SRC_PTR_OFFSET                                 0x00000000
#define CE_SRC_DESC_0_SRC_PTR_LSB                                    0
#define CE_SRC_DESC_0_SRC_PTR_MASK                                   0xffffffff

/* Description		CE_SRC_DESC_1_SRC_BUF_LEN
			Buffer length of the source buffer in units of octets. 
			Written by FW/SW.
*/
#define CE_SRC_DESC_1_SRC_BUF_LEN_OFFSET                             0x00000004
#define CE_SRC_DESC_1_SRC_BUF_LEN_LSB                                0
#define CE_SRC_DESC_1_SRC_BUF_LEN_MASK                               0x0000ffff

/* Description		CE_SRC_DESC_1_GATHER
			Enables gather of multiple copy engine source descriptors to
			one destination.  Written by FW/SW.
*/
#define CE_SRC_DESC_1_GATHER_OFFSET                                  0x00000004
#define CE_SRC_DESC_1_GATHER_LSB                                     16
#define CE_SRC_DESC_1_GATHER_MASK                                    0x00010000

/* Description		CE_SRC_DESC_1_BYTE_SWAP
			Enable byte swap for endian conversion.  For each dword (4
			bytes), the byte 0 is swapped with byte 3 and byte 1 is
			swapped with byte 2.  Written by FW/SW.
*/
#define CE_SRC_DESC_1_BYTE_SWAP_OFFSET                               0x00000004
#define CE_SRC_DESC_1_BYTE_SWAP_LSB                                  17
#define CE_SRC_DESC_1_BYTE_SWAP_MASK                                 0x00020000

/* Description		CE_SRC_DESC_1_META_DATA
			Unused by HW.
*/
#define CE_SRC_DESC_1_META_DATA_OFFSET                               0x00000004
#define CE_SRC_DESC_1_META_DATA_LSB                                  18
#define CE_SRC_DESC_1_META_DATA_MASK                                 0xfffc0000


#endif // _CE_SRC_DESC_H_
