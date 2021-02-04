// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _RX_FRAG_INFO_H_
#define _RX_FRAG_INFO_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	ring0_more_count[7:0], ring1_more_count[15:8], ring2_more_count[23:16], ring3_more_count[31:24]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RX_FRAG_INFO 1

struct rx_frag_info {
    volatile uint32_t ring0_more_count                :  8, //[7:0]
                      ring1_more_count                :  8, //[15:8]
                      ring2_more_count                :  8, //[23:16]
                      ring3_more_count                :  8; //[31:24]
};

/*

ring0_more_count
			Indicates the number of more buffers associated with RX DMA
			ring 0.  Field is filled in by the RX_DMA.

ring1_more_count
			Indicates the number of more buffers associated with RX DMA
			ring 1. Field is filled in by the RX_DMA.

ring2_more_count
			Indicates the number of more buffers associated with RX DMA
			ring 2. Field is filled in by the RX_DMA.

ring3_more_count
			Indicates the number of more buffers associated with RX DMA
			ring 3. Field is filled in by the RX_DMA.
*/


/* Description		RX_FRAG_INFO_0_RING0_MORE_COUNT
			Indicates the number of more buffers associated with RX DMA
			ring 0.  Field is filled in by the RX_DMA.
*/
#define RX_FRAG_INFO_0_RING0_MORE_COUNT_OFFSET                       0x00000000
#define RX_FRAG_INFO_0_RING0_MORE_COUNT_LSB                          0
#define RX_FRAG_INFO_0_RING0_MORE_COUNT_MASK                         0x000000ff

/* Description		RX_FRAG_INFO_0_RING1_MORE_COUNT
			Indicates the number of more buffers associated with RX DMA
			ring 1. Field is filled in by the RX_DMA.
*/
#define RX_FRAG_INFO_0_RING1_MORE_COUNT_OFFSET                       0x00000000
#define RX_FRAG_INFO_0_RING1_MORE_COUNT_LSB                          8
#define RX_FRAG_INFO_0_RING1_MORE_COUNT_MASK                         0x0000ff00

/* Description		RX_FRAG_INFO_0_RING2_MORE_COUNT
			Indicates the number of more buffers associated with RX DMA
			ring 2. Field is filled in by the RX_DMA.
*/
#define RX_FRAG_INFO_0_RING2_MORE_COUNT_OFFSET                       0x00000000
#define RX_FRAG_INFO_0_RING2_MORE_COUNT_LSB                          16
#define RX_FRAG_INFO_0_RING2_MORE_COUNT_MASK                         0x00ff0000

/* Description		RX_FRAG_INFO_0_RING3_MORE_COUNT
			Indicates the number of more buffers associated with RX DMA
			ring 3. Field is filled in by the RX_DMA.
*/
#define RX_FRAG_INFO_0_RING3_MORE_COUNT_OFFSET                       0x00000000
#define RX_FRAG_INFO_0_RING3_MORE_COUNT_LSB                          24
#define RX_FRAG_INFO_0_RING3_MORE_COUNT_MASK                         0xff000000


#endif // _RX_FRAG_INFO_H_
