// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _TX_PPDU_END_H_
#define _TX_PPDU_END_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0-15	struct try_list try_list;
//	16-31	struct ppdu_status stat;
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_TX_PPDU_END 32

struct tx_ppdu_end {
    struct            try_list                       try_list;
    struct            ppdu_status                       stat;
};

/*

struct try_list try_list
			16 dwords of tries information

struct ppdu_status stat
			16 dwords of transmit status
*/

#define TX_PPDU_END_0_TRY_LIST_TRY_LIST_OFFSET                       0x00000000
#define TX_PPDU_END_0_TRY_LIST_TRY_LIST_LSB                          0
#define TX_PPDU_END_0_TRY_LIST_TRY_LIST_MASK                         0xffffffff
#define TX_PPDU_END_1_TRY_LIST_TRY_LIST_OFFSET                       0x00000004
#define TX_PPDU_END_1_TRY_LIST_TRY_LIST_LSB                          0
#define TX_PPDU_END_1_TRY_LIST_TRY_LIST_MASK                         0xffffffff
#define TX_PPDU_END_2_TRY_LIST_TRY_LIST_OFFSET                       0x00000008
#define TX_PPDU_END_2_TRY_LIST_TRY_LIST_LSB                          0
#define TX_PPDU_END_2_TRY_LIST_TRY_LIST_MASK                         0xffffffff
#define TX_PPDU_END_3_TRY_LIST_TRY_LIST_OFFSET                       0x0000000c
#define TX_PPDU_END_3_TRY_LIST_TRY_LIST_LSB                          0
#define TX_PPDU_END_3_TRY_LIST_TRY_LIST_MASK                         0xffffffff
#define TX_PPDU_END_4_TRY_LIST_TRY_LIST_OFFSET                       0x00000010
#define TX_PPDU_END_4_TRY_LIST_TRY_LIST_LSB                          0
#define TX_PPDU_END_4_TRY_LIST_TRY_LIST_MASK                         0xffffffff
#define TX_PPDU_END_5_TRY_LIST_TRY_LIST_OFFSET                       0x00000014
#define TX_PPDU_END_5_TRY_LIST_TRY_LIST_LSB                          0
#define TX_PPDU_END_5_TRY_LIST_TRY_LIST_MASK                         0xffffffff
#define TX_PPDU_END_6_TRY_LIST_TRY_LIST_OFFSET                       0x00000018
#define TX_PPDU_END_6_TRY_LIST_TRY_LIST_LSB                          0
#define TX_PPDU_END_6_TRY_LIST_TRY_LIST_MASK                         0xffffffff
#define TX_PPDU_END_7_TRY_LIST_TRY_LIST_OFFSET                       0x0000001c
#define TX_PPDU_END_7_TRY_LIST_TRY_LIST_LSB                          0
#define TX_PPDU_END_7_TRY_LIST_TRY_LIST_MASK                         0xffffffff
#define TX_PPDU_END_8_TRY_LIST_TRY_LIST_OFFSET                       0x00000020
#define TX_PPDU_END_8_TRY_LIST_TRY_LIST_LSB                          0
#define TX_PPDU_END_8_TRY_LIST_TRY_LIST_MASK                         0xffffffff
#define TX_PPDU_END_9_TRY_LIST_TRY_LIST_OFFSET                       0x00000024
#define TX_PPDU_END_9_TRY_LIST_TRY_LIST_LSB                          0
#define TX_PPDU_END_9_TRY_LIST_TRY_LIST_MASK                         0xffffffff
#define TX_PPDU_END_10_TRY_LIST_TRY_LIST_OFFSET                      0x00000028
#define TX_PPDU_END_10_TRY_LIST_TRY_LIST_LSB                         0
#define TX_PPDU_END_10_TRY_LIST_TRY_LIST_MASK                        0xffffffff
#define TX_PPDU_END_11_TRY_LIST_TRY_LIST_OFFSET                      0x0000002c
#define TX_PPDU_END_11_TRY_LIST_TRY_LIST_LSB                         0
#define TX_PPDU_END_11_TRY_LIST_TRY_LIST_MASK                        0xffffffff
#define TX_PPDU_END_12_TRY_LIST_TRY_LIST_OFFSET                      0x00000030
#define TX_PPDU_END_12_TRY_LIST_TRY_LIST_LSB                         0
#define TX_PPDU_END_12_TRY_LIST_TRY_LIST_MASK                        0xffffffff
#define TX_PPDU_END_13_TRY_LIST_TRY_LIST_OFFSET                      0x00000034
#define TX_PPDU_END_13_TRY_LIST_TRY_LIST_LSB                         0
#define TX_PPDU_END_13_TRY_LIST_TRY_LIST_MASK                        0xffffffff
#define TX_PPDU_END_14_TRY_LIST_TRY_LIST_OFFSET                      0x00000038
#define TX_PPDU_END_14_TRY_LIST_TRY_LIST_LSB                         0
#define TX_PPDU_END_14_TRY_LIST_TRY_LIST_MASK                        0xffffffff
#define TX_PPDU_END_15_TRY_LIST_TRY_LIST_OFFSET                      0x0000003c
#define TX_PPDU_END_15_TRY_LIST_TRY_LIST_LSB                         0
#define TX_PPDU_END_15_TRY_LIST_TRY_LIST_MASK                        0xffffffff
#define TX_PPDU_END_16_PPDU_STATUS_STAT_OFFSET                       0x00000040
#define TX_PPDU_END_16_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_16_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_17_PPDU_STATUS_STAT_OFFSET                       0x00000044
#define TX_PPDU_END_17_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_17_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_18_PPDU_STATUS_STAT_OFFSET                       0x00000048
#define TX_PPDU_END_18_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_18_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_19_PPDU_STATUS_STAT_OFFSET                       0x0000004c
#define TX_PPDU_END_19_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_19_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_20_PPDU_STATUS_STAT_OFFSET                       0x00000050
#define TX_PPDU_END_20_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_20_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_21_PPDU_STATUS_STAT_OFFSET                       0x00000054
#define TX_PPDU_END_21_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_21_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_22_PPDU_STATUS_STAT_OFFSET                       0x00000058
#define TX_PPDU_END_22_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_22_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_23_PPDU_STATUS_STAT_OFFSET                       0x0000005c
#define TX_PPDU_END_23_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_23_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_24_PPDU_STATUS_STAT_OFFSET                       0x00000060
#define TX_PPDU_END_24_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_24_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_25_PPDU_STATUS_STAT_OFFSET                       0x00000064
#define TX_PPDU_END_25_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_25_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_26_PPDU_STATUS_STAT_OFFSET                       0x00000068
#define TX_PPDU_END_26_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_26_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_27_PPDU_STATUS_STAT_OFFSET                       0x0000006c
#define TX_PPDU_END_27_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_27_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_28_PPDU_STATUS_STAT_OFFSET                       0x00000070
#define TX_PPDU_END_28_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_28_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_29_PPDU_STATUS_STAT_OFFSET                       0x00000074
#define TX_PPDU_END_29_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_29_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_30_PPDU_STATUS_STAT_OFFSET                       0x00000078
#define TX_PPDU_END_30_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_30_PPDU_STATUS_STAT_MASK                         0xffffffff
#define TX_PPDU_END_31_PPDU_STATUS_STAT_OFFSET                       0x0000007c
#define TX_PPDU_END_31_PPDU_STATUS_STAT_LSB                          0
#define TX_PPDU_END_31_PPDU_STATUS_STAT_MASK                         0xffffffff


#endif // _TX_PPDU_END_H_
