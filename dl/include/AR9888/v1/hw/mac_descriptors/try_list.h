// Copyright (c) 2011 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  These definitions are tied to a particular hardware layout

#ifndef _TRY_LIST_H_
#define _TRY_LIST_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	struct try_status try_00;
//	1	struct try_status try_01;
//	2	struct try_status try_02;
//	3	struct try_status try_03;
//	4	struct try_status try_04;
//	5	struct try_status try_05;
//	6	struct try_status try_06;
//	7	struct try_status try_07;
//	8	struct try_status try_08;
//	9	struct try_status try_09;
//	10	struct try_status try_10;
//	11	struct try_status try_11;
//	12	struct try_status try_12;
//	13	struct try_status try_13;
//	14	struct try_status try_14;
//	15	struct try_status try_15;
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_TRY_LIST 16

struct try_list {
    struct            try_status                       try_00;
    struct            try_status                       try_01;
    struct            try_status                       try_02;
    struct            try_status                       try_03;
    struct            try_status                       try_04;
    struct            try_status                       try_05;
    struct            try_status                       try_06;
    struct            try_status                       try_07;
    struct            try_status                       try_08;
    struct            try_status                       try_09;
    struct            try_status                       try_10;
    struct            try_status                       try_11;
    struct            try_status                       try_12;
    struct            try_status                       try_13;
    struct            try_status                       try_14;
    struct            try_status                       try_15;
};

/*

struct try_status try_00
			Status for attempt #0.

struct try_status try_01
			Status for attempt #1.

struct try_status try_02
			Status for attempt #2.

struct try_status try_03
			Status for attempt #3.

struct try_status try_04
			Status for attempt #4.

struct try_status try_05
			Status for attempt #5.

struct try_status try_06
			Status for attempt #6.

struct try_status try_07
			Status for attempt #7.

struct try_status try_08
			Status for attempt #8.

struct try_status try_09
			Status for attempt #9.

struct try_status try_10
			Status for attempt #10.

struct try_status try_11
			Status for attempt #11.

struct try_status try_12
			Status for attempt #12.

struct try_status try_13
			Status for attempt #13.

struct try_status try_14
			Status for attempt #14.

struct try_status try_15
			Status for attempt #15.
*/

#define TRY_LIST_0_TRY_STATUS_TRY_00_OFFSET                          0x00000000
#define TRY_LIST_0_TRY_STATUS_TRY_00_LSB                             0
#define TRY_LIST_0_TRY_STATUS_TRY_00_MASK                            0xffffffff
#define TRY_LIST_1_TRY_STATUS_TRY_01_OFFSET                          0x00000004
#define TRY_LIST_1_TRY_STATUS_TRY_01_LSB                             0
#define TRY_LIST_1_TRY_STATUS_TRY_01_MASK                            0xffffffff
#define TRY_LIST_2_TRY_STATUS_TRY_02_OFFSET                          0x00000008
#define TRY_LIST_2_TRY_STATUS_TRY_02_LSB                             0
#define TRY_LIST_2_TRY_STATUS_TRY_02_MASK                            0xffffffff
#define TRY_LIST_3_TRY_STATUS_TRY_03_OFFSET                          0x0000000c
#define TRY_LIST_3_TRY_STATUS_TRY_03_LSB                             0
#define TRY_LIST_3_TRY_STATUS_TRY_03_MASK                            0xffffffff
#define TRY_LIST_4_TRY_STATUS_TRY_04_OFFSET                          0x00000010
#define TRY_LIST_4_TRY_STATUS_TRY_04_LSB                             0
#define TRY_LIST_4_TRY_STATUS_TRY_04_MASK                            0xffffffff
#define TRY_LIST_5_TRY_STATUS_TRY_05_OFFSET                          0x00000014
#define TRY_LIST_5_TRY_STATUS_TRY_05_LSB                             0
#define TRY_LIST_5_TRY_STATUS_TRY_05_MASK                            0xffffffff
#define TRY_LIST_6_TRY_STATUS_TRY_06_OFFSET                          0x00000018
#define TRY_LIST_6_TRY_STATUS_TRY_06_LSB                             0
#define TRY_LIST_6_TRY_STATUS_TRY_06_MASK                            0xffffffff
#define TRY_LIST_7_TRY_STATUS_TRY_07_OFFSET                          0x0000001c
#define TRY_LIST_7_TRY_STATUS_TRY_07_LSB                             0
#define TRY_LIST_7_TRY_STATUS_TRY_07_MASK                            0xffffffff
#define TRY_LIST_8_TRY_STATUS_TRY_08_OFFSET                          0x00000020
#define TRY_LIST_8_TRY_STATUS_TRY_08_LSB                             0
#define TRY_LIST_8_TRY_STATUS_TRY_08_MASK                            0xffffffff
#define TRY_LIST_9_TRY_STATUS_TRY_09_OFFSET                          0x00000024
#define TRY_LIST_9_TRY_STATUS_TRY_09_LSB                             0
#define TRY_LIST_9_TRY_STATUS_TRY_09_MASK                            0xffffffff
#define TRY_LIST_10_TRY_STATUS_TRY_10_OFFSET                         0x00000028
#define TRY_LIST_10_TRY_STATUS_TRY_10_LSB                            0
#define TRY_LIST_10_TRY_STATUS_TRY_10_MASK                           0xffffffff
#define TRY_LIST_11_TRY_STATUS_TRY_11_OFFSET                         0x0000002c
#define TRY_LIST_11_TRY_STATUS_TRY_11_LSB                            0
#define TRY_LIST_11_TRY_STATUS_TRY_11_MASK                           0xffffffff
#define TRY_LIST_12_TRY_STATUS_TRY_12_OFFSET                         0x00000030
#define TRY_LIST_12_TRY_STATUS_TRY_12_LSB                            0
#define TRY_LIST_12_TRY_STATUS_TRY_12_MASK                           0xffffffff
#define TRY_LIST_13_TRY_STATUS_TRY_13_OFFSET                         0x00000034
#define TRY_LIST_13_TRY_STATUS_TRY_13_LSB                            0
#define TRY_LIST_13_TRY_STATUS_TRY_13_MASK                           0xffffffff
#define TRY_LIST_14_TRY_STATUS_TRY_14_OFFSET                         0x00000038
#define TRY_LIST_14_TRY_STATUS_TRY_14_LSB                            0
#define TRY_LIST_14_TRY_STATUS_TRY_14_MASK                           0xffffffff
#define TRY_LIST_15_TRY_STATUS_TRY_15_OFFSET                         0x0000003c
#define TRY_LIST_15_TRY_STATUS_TRY_15_LSB                            0
#define TRY_LIST_15_TRY_STATUS_TRY_15_MASK                           0xffffffff


#endif // _TRY_LIST_H_
