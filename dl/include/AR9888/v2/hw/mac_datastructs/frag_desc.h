// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _FRAG_DESC_H_
#define _FRAG_DESC_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	buf_ptr[31:0]
//	1	buf_len[15:0], reserved[31:16]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_FRAG_DESC 2

struct frag_desc {
    volatile uint32_t buf_ptr                         : 32; //[31:0]
    volatile uint32_t buf_len                         : 16, //[15:0]
                      reserved                        : 16; //[31:16]
};

/*

buf_ptr
			Buffer pointer of this fragment of the MSDU.  There is no
			restriction on the byte alignment: buf_ptr does not need to
			start on a dword boundary.

buf_len
			Buffer length in units of octets

reserved
			Reserved: Unused by HW
*/


/* Description		FRAG_DESC_0_BUF_PTR
			Buffer pointer of this fragment of the MSDU.  There is no
			restriction on the byte alignment: buf_ptr does not need to
			start on a dword boundary.
*/
#define FRAG_DESC_0_BUF_PTR_OFFSET                                   0x00000000
#define FRAG_DESC_0_BUF_PTR_LSB                                      0
#define FRAG_DESC_0_BUF_PTR_MASK                                     0xffffffff

/* Description		FRAG_DESC_1_BUF_LEN
			Buffer length in units of octets
*/
#define FRAG_DESC_1_BUF_LEN_OFFSET                                   0x00000004
#define FRAG_DESC_1_BUF_LEN_LSB                                      0
#define FRAG_DESC_1_BUF_LEN_MASK                                     0x0000ffff

/* Description		FRAG_DESC_1_RESERVED
			Reserved: Unused by HW
*/
#define FRAG_DESC_1_RESERVED_OFFSET                                  0x00000004
#define FRAG_DESC_1_RESERVED_LSB                                     16
#define FRAG_DESC_1_RESERVED_MASK                                    0xffff0000


#endif // _FRAG_DESC_H_
