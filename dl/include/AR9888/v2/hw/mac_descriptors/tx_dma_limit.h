// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _TX_DMA_LIMIT_H_
#define _TX_DMA_LIMIT_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	num_mpdu[6:0], reserved_0a[11:7], dma_abort[12], bw_select[14:13], reserved_0b[31:15]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_TX_DMA_LIMIT 1

struct tx_dma_limit {
    volatile uint32_t num_mpdu                        :  7, //[6:0]
                      reserved_0a                     :  5, //[11:7]
                      dma_abort                       :  1, //[12]
                      bw_select                       :  2, //[14:13]
                      reserved_0b                     : 17; //[31:15]
};

/*

num_mpdu
			Indicates the number of MPDUs to DMA to the PCU for the
			current PPDU.  The TX DMA does not know which bandwidth the
			PCU will select so it can not anticipate the number of MPDUs
			the PCU will need so it will start fetch as many MPDUs as it
			can and wait for the PCU to notify it of the actual number.

reserved_0a
			Reserved

dma_abort
			Indicates that the DMA should cancel any DMA in progress

bw_select
			Indicates which bandwidth was selected to transmit the data
			frame. 
			0: 20 MHz
			1: 40 MHz
			2: 80 MHz
			3: 160 MHz

reserved_0b
			Reserved
*/


/* Description		TX_DMA_LIMIT_0_NUM_MPDU
			Indicates the number of MPDUs to DMA to the PCU for the
			current PPDU.  The TX DMA does not know which bandwidth the
			PCU will select so it can not anticipate the number of MPDUs
			the PCU will need so it will start fetch as many MPDUs as it
			can and wait for the PCU to notify it of the actual number.
*/
#define TX_DMA_LIMIT_0_NUM_MPDU_OFFSET                               0x00000000
#define TX_DMA_LIMIT_0_NUM_MPDU_LSB                                  0
#define TX_DMA_LIMIT_0_NUM_MPDU_MASK                                 0x0000007f

/* Description		TX_DMA_LIMIT_0_RESERVED_0A
			Reserved
*/
#define TX_DMA_LIMIT_0_RESERVED_0A_OFFSET                            0x00000000
#define TX_DMA_LIMIT_0_RESERVED_0A_LSB                               7
#define TX_DMA_LIMIT_0_RESERVED_0A_MASK                              0x00000f80

/* Description		TX_DMA_LIMIT_0_DMA_ABORT
			Indicates that the DMA should cancel any DMA in progress
*/
#define TX_DMA_LIMIT_0_DMA_ABORT_OFFSET                              0x00000000
#define TX_DMA_LIMIT_0_DMA_ABORT_LSB                                 12
#define TX_DMA_LIMIT_0_DMA_ABORT_MASK                                0x00001000

/* Description		TX_DMA_LIMIT_0_BW_SELECT
			Indicates which bandwidth was selected to transmit the data
			frame. 
			0: 20 MHz
			1: 40 MHz
			2: 80 MHz
			3: 160 MHz
*/
#define TX_DMA_LIMIT_0_BW_SELECT_OFFSET                              0x00000000
#define TX_DMA_LIMIT_0_BW_SELECT_LSB                                 13
#define TX_DMA_LIMIT_0_BW_SELECT_MASK                                0x00006000

/* Description		TX_DMA_LIMIT_0_RESERVED_0B
			Reserved
*/
#define TX_DMA_LIMIT_0_RESERVED_0B_OFFSET                            0x00000000
#define TX_DMA_LIMIT_0_RESERVED_0B_LSB                               15
#define TX_DMA_LIMIT_0_RESERVED_0B_MASK                              0xffff8000


#endif // _TX_DMA_LIMIT_H_
