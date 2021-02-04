// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _TX_PPDU_STATUS_H_
#define _TX_PPDU_STATUS_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	tx_ppdu_end_ptr[31:0]
//	1	struct try_status a_try;
//	2-17	struct ppdu_status stat;
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_TX_PPDU_STATUS 18

struct tx_ppdu_status {
    volatile uint32_t tx_ppdu_end_ptr                 : 32; //[31:0]
    struct            try_status                       a_try;
    struct            ppdu_status                       stat;
};

/*

tx_ppdu_end_ptr
			Pointer to the tx_ppdu_end descriptor status (PCU gets this
			field from the tx_ppdu_start descriptor)

struct try_status a_try
			1 dword of try information

struct ppdu_status stat
			16 dwords of transmit status
*/


/* Description		TX_PPDU_STATUS_0_TX_PPDU_END_PTR
			Pointer to the tx_ppdu_end descriptor status (PCU gets this
			field from the tx_ppdu_start descriptor)
*/
#define TX_PPDU_STATUS_0_TX_PPDU_END_PTR_OFFSET                      0x00000000
#define TX_PPDU_STATUS_0_TX_PPDU_END_PTR_LSB                         0
#define TX_PPDU_STATUS_0_TX_PPDU_END_PTR_MASK                        0xffffffff
#define TX_PPDU_STATUS_1_TRY_STATUS_A_TRY_OFFSET                     0x00000004
#define TX_PPDU_STATUS_1_TRY_STATUS_A_TRY_LSB                        0
#define TX_PPDU_STATUS_1_TRY_STATUS_A_TRY_MASK                       0xffffffff
#define TX_PPDU_STATUS_2_PPDU_STATUS_STAT_OFFSET                     0x00000008
#define TX_PPDU_STATUS_2_PPDU_STATUS_STAT_LSB                        0
#define TX_PPDU_STATUS_2_PPDU_STATUS_STAT_MASK                       0xffffffff
#define TX_PPDU_STATUS_3_PPDU_STATUS_STAT_OFFSET                     0x0000000c
#define TX_PPDU_STATUS_3_PPDU_STATUS_STAT_LSB                        0
#define TX_PPDU_STATUS_3_PPDU_STATUS_STAT_MASK                       0xffffffff
#define TX_PPDU_STATUS_4_PPDU_STATUS_STAT_OFFSET                     0x00000010
#define TX_PPDU_STATUS_4_PPDU_STATUS_STAT_LSB                        0
#define TX_PPDU_STATUS_4_PPDU_STATUS_STAT_MASK                       0xffffffff
#define TX_PPDU_STATUS_5_PPDU_STATUS_STAT_OFFSET                     0x00000014
#define TX_PPDU_STATUS_5_PPDU_STATUS_STAT_LSB                        0
#define TX_PPDU_STATUS_5_PPDU_STATUS_STAT_MASK                       0xffffffff
#define TX_PPDU_STATUS_6_PPDU_STATUS_STAT_OFFSET                     0x00000018
#define TX_PPDU_STATUS_6_PPDU_STATUS_STAT_LSB                        0
#define TX_PPDU_STATUS_6_PPDU_STATUS_STAT_MASK                       0xffffffff
#define TX_PPDU_STATUS_7_PPDU_STATUS_STAT_OFFSET                     0x0000001c
#define TX_PPDU_STATUS_7_PPDU_STATUS_STAT_LSB                        0
#define TX_PPDU_STATUS_7_PPDU_STATUS_STAT_MASK                       0xffffffff
#define TX_PPDU_STATUS_8_PPDU_STATUS_STAT_OFFSET                     0x00000020
#define TX_PPDU_STATUS_8_PPDU_STATUS_STAT_LSB                        0
#define TX_PPDU_STATUS_8_PPDU_STATUS_STAT_MASK                       0xffffffff
#define TX_PPDU_STATUS_9_PPDU_STATUS_STAT_OFFSET                     0x00000024
#define TX_PPDU_STATUS_9_PPDU_STATUS_STAT_LSB                        0
#define TX_PPDU_STATUS_9_PPDU_STATUS_STAT_MASK                       0xffffffff
#define TX_PPDU_STATUS_10_PPDU_STATUS_STAT_OFFSET                    0x00000028
#define TX_PPDU_STATUS_10_PPDU_STATUS_STAT_LSB                       0
#define TX_PPDU_STATUS_10_PPDU_STATUS_STAT_MASK                      0xffffffff
#define TX_PPDU_STATUS_11_PPDU_STATUS_STAT_OFFSET                    0x0000002c
#define TX_PPDU_STATUS_11_PPDU_STATUS_STAT_LSB                       0
#define TX_PPDU_STATUS_11_PPDU_STATUS_STAT_MASK                      0xffffffff
#define TX_PPDU_STATUS_12_PPDU_STATUS_STAT_OFFSET                    0x00000030
#define TX_PPDU_STATUS_12_PPDU_STATUS_STAT_LSB                       0
#define TX_PPDU_STATUS_12_PPDU_STATUS_STAT_MASK                      0xffffffff
#define TX_PPDU_STATUS_13_PPDU_STATUS_STAT_OFFSET                    0x00000034
#define TX_PPDU_STATUS_13_PPDU_STATUS_STAT_LSB                       0
#define TX_PPDU_STATUS_13_PPDU_STATUS_STAT_MASK                      0xffffffff
#define TX_PPDU_STATUS_14_PPDU_STATUS_STAT_OFFSET                    0x00000038
#define TX_PPDU_STATUS_14_PPDU_STATUS_STAT_LSB                       0
#define TX_PPDU_STATUS_14_PPDU_STATUS_STAT_MASK                      0xffffffff
#define TX_PPDU_STATUS_15_PPDU_STATUS_STAT_OFFSET                    0x0000003c
#define TX_PPDU_STATUS_15_PPDU_STATUS_STAT_LSB                       0
#define TX_PPDU_STATUS_15_PPDU_STATUS_STAT_MASK                      0xffffffff
#define TX_PPDU_STATUS_16_PPDU_STATUS_STAT_OFFSET                    0x00000040
#define TX_PPDU_STATUS_16_PPDU_STATUS_STAT_LSB                       0
#define TX_PPDU_STATUS_16_PPDU_STATUS_STAT_MASK                      0xffffffff
#define TX_PPDU_STATUS_17_PPDU_STATUS_STAT_OFFSET                    0x00000044
#define TX_PPDU_STATUS_17_PPDU_STATUS_STAT_LSB                       0
#define TX_PPDU_STATUS_17_PPDU_STATUS_STAT_MASK                      0xffffffff


#endif // _TX_PPDU_STATUS_H_
