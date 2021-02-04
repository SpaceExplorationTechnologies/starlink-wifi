// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _CE_DST_DESC_H_
#define _CE_DST_DESC_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	dst_ptr[31:0]
//	1	dst_buf_len[15:0], reserved_1a[16], reserved_1b[17], meta_data[31:18]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_CE_DST_DESC 2

struct ce_dst_desc {
    volatile uint32_t dst_ptr                         : 32; //[31:0]
    volatile uint32_t dst_buf_len                     : 16, //[15:0]
                      reserved_1a                     :  1, //[16]
                      reserved_1b                     :  1, //[17]
                      meta_data                       : 14; //[31:18]
};

/*

dst_ptr
			Pointer to the destination buffer.  Written by FW/SW.

dst_buf_len
			Buffer length of the source buffer in units of octets. 
			Written by HW.

reserved_1a
			Reserved: HW will write this field.  FW should ignore.

reserved_1b
			Reserved: HW will write this field.  FW should ignore.

meta_data
			Unused by HW.  Copied from source descriptor to destination
			descriptor.  Only the meta_data from the first source
			descriptor will be copied if the gather bit is set.  Written
			by HW.
*/


/* Description		CE_DST_DESC_0_DST_PTR
			Pointer to the destination buffer.  Written by FW/SW.
*/
#define CE_DST_DESC_0_DST_PTR_OFFSET                                 0x00000000
#define CE_DST_DESC_0_DST_PTR_LSB                                    0
#define CE_DST_DESC_0_DST_PTR_MASK                                   0xffffffff

/* Description		CE_DST_DESC_1_DST_BUF_LEN
			Buffer length of the source buffer in units of octets. 
			Written by HW.
*/
#define CE_DST_DESC_1_DST_BUF_LEN_OFFSET                             0x00000004
#define CE_DST_DESC_1_DST_BUF_LEN_LSB                                0
#define CE_DST_DESC_1_DST_BUF_LEN_MASK                               0x0000ffff

/* Description		CE_DST_DESC_1_RESERVED_1A
			Reserved: HW will write this field.  FW should ignore.
*/
#define CE_DST_DESC_1_RESERVED_1A_OFFSET                             0x00000004
#define CE_DST_DESC_1_RESERVED_1A_LSB                                16
#define CE_DST_DESC_1_RESERVED_1A_MASK                               0x00010000

/* Description		CE_DST_DESC_1_RESERVED_1B
			Reserved: HW will write this field.  FW should ignore.
*/
#define CE_DST_DESC_1_RESERVED_1B_OFFSET                             0x00000004
#define CE_DST_DESC_1_RESERVED_1B_LSB                                17
#define CE_DST_DESC_1_RESERVED_1B_MASK                               0x00020000

/* Description		CE_DST_DESC_1_META_DATA
			Unused by HW.  Copied from source descriptor to destination
			descriptor.  Only the meta_data from the first source
			descriptor will be copied if the gather bit is set.  Written
			by HW.
*/
#define CE_DST_DESC_1_META_DATA_OFFSET                               0x00000004
#define CE_DST_DESC_1_META_DATA_LSB                                  18
#define CE_DST_DESC_1_META_DATA_MASK                                 0xfffc0000


#endif // _CE_DST_DESC_H_
