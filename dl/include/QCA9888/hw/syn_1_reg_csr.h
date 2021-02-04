/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _SYN_1_REG_CSR_H_
#define _SYN_1_REG_CSR_H_


#ifndef __SYN_1_REG_CSR_BASE_ADDRESS
#define __SYN_1_REG_CSR_BASE_ADDRESS (0x47780)
#endif


// 0x0 (SYN_LODIST_0)
#define SYN_LODIST_0_LO_HB_GEN_THRSH1_LSB                                      26
#define SYN_LODIST_0_LO_HB_GEN_THRSH1_MSB                                      31
#define SYN_LODIST_0_LO_HB_GEN_THRSH1_MASK                                     0xfc000000
#define SYN_LODIST_0_LO_HB_GEN_THRSH1_GET(x)                                   (((x) & SYN_LODIST_0_LO_HB_GEN_THRSH1_MASK) >> SYN_LODIST_0_LO_HB_GEN_THRSH1_LSB)
#define SYN_LODIST_0_LO_HB_GEN_THRSH1_SET(x)                                   (((0 | (x)) << SYN_LODIST_0_LO_HB_GEN_THRSH1_LSB) & SYN_LODIST_0_LO_HB_GEN_THRSH1_MASK)
#define SYN_LODIST_0_LO_HB_GEN_THRSH1_RESET                                    0x2
#define SYN_LODIST_0_LO_HB_GEN_THRSH2_LSB                                      20
#define SYN_LODIST_0_LO_HB_GEN_THRSH2_MSB                                      25
#define SYN_LODIST_0_LO_HB_GEN_THRSH2_MASK                                     0x3f00000
#define SYN_LODIST_0_LO_HB_GEN_THRSH2_GET(x)                                   (((x) & SYN_LODIST_0_LO_HB_GEN_THRSH2_MASK) >> SYN_LODIST_0_LO_HB_GEN_THRSH2_LSB)
#define SYN_LODIST_0_LO_HB_GEN_THRSH2_SET(x)                                   (((0 | (x)) << SYN_LODIST_0_LO_HB_GEN_THRSH2_LSB) & SYN_LODIST_0_LO_HB_GEN_THRSH2_MASK)
#define SYN_LODIST_0_LO_HB_GEN_THRSH2_RESET                                    0x6
#define SYN_LODIST_0_LO_HB_GEN_THRSH3_LSB                                      14
#define SYN_LODIST_0_LO_HB_GEN_THRSH3_MSB                                      19
#define SYN_LODIST_0_LO_HB_GEN_THRSH3_MASK                                     0xfc000
#define SYN_LODIST_0_LO_HB_GEN_THRSH3_GET(x)                                   (((x) & SYN_LODIST_0_LO_HB_GEN_THRSH3_MASK) >> SYN_LODIST_0_LO_HB_GEN_THRSH3_LSB)
#define SYN_LODIST_0_LO_HB_GEN_THRSH3_SET(x)                                   (((0 | (x)) << SYN_LODIST_0_LO_HB_GEN_THRSH3_LSB) & SYN_LODIST_0_LO_HB_GEN_THRSH3_MASK)
#define SYN_LODIST_0_LO_HB_GEN_THRSH3_RESET                                    0xa
#define SYN_LODIST_0_LO_HB_GEN_THRSH4_LSB                                      8
#define SYN_LODIST_0_LO_HB_GEN_THRSH4_MSB                                      13
#define SYN_LODIST_0_LO_HB_GEN_THRSH4_MASK                                     0x3f00
#define SYN_LODIST_0_LO_HB_GEN_THRSH4_GET(x)                                   (((x) & SYN_LODIST_0_LO_HB_GEN_THRSH4_MASK) >> SYN_LODIST_0_LO_HB_GEN_THRSH4_LSB)
#define SYN_LODIST_0_LO_HB_GEN_THRSH4_SET(x)                                   (((0 | (x)) << SYN_LODIST_0_LO_HB_GEN_THRSH4_LSB) & SYN_LODIST_0_LO_HB_GEN_THRSH4_MASK)
#define SYN_LODIST_0_LO_HB_GEN_THRSH4_RESET                                    0xf
#define SYN_LODIST_0_LO_HB_GEN_THRSH5_LSB                                      2
#define SYN_LODIST_0_LO_HB_GEN_THRSH5_MSB                                      7
#define SYN_LODIST_0_LO_HB_GEN_THRSH5_MASK                                     0xfc
#define SYN_LODIST_0_LO_HB_GEN_THRSH5_GET(x)                                   (((x) & SYN_LODIST_0_LO_HB_GEN_THRSH5_MASK) >> SYN_LODIST_0_LO_HB_GEN_THRSH5_LSB)
#define SYN_LODIST_0_LO_HB_GEN_THRSH5_SET(x)                                   (((0 | (x)) << SYN_LODIST_0_LO_HB_GEN_THRSH5_LSB) & SYN_LODIST_0_LO_HB_GEN_THRSH5_MASK)
#define SYN_LODIST_0_LO_HB_GEN_THRSH5_RESET                                    0x15
#define SYN_LODIST_0_RESERVED_0_LSB                                            0
#define SYN_LODIST_0_RESERVED_0_MSB                                            1
#define SYN_LODIST_0_RESERVED_0_MASK                                           0x3
#define SYN_LODIST_0_RESERVED_0_GET(x)                                         (((x) & SYN_LODIST_0_RESERVED_0_MASK) >> SYN_LODIST_0_RESERVED_0_LSB)
#define SYN_LODIST_0_RESERVED_0_SET(x)                                         (((0 | (x)) << SYN_LODIST_0_RESERVED_0_LSB) & SYN_LODIST_0_RESERVED_0_MASK)
#define SYN_LODIST_0_RESERVED_0_RESET                                          0x0
#define SYN_LODIST_0_ADDRESS                                                   (0x0 + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_LODIST_0_RSTMASK                                                   0xffffffff
#define SYN_LODIST_0_RESET                                                     0x8628f54

// 0x4 (SYN_LODIST_1)
#define SYN_LODIST_1_LO_HB_GEN_THRSH6_LSB                                      26
#define SYN_LODIST_1_LO_HB_GEN_THRSH6_MSB                                      31
#define SYN_LODIST_1_LO_HB_GEN_THRSH6_MASK                                     0xfc000000
#define SYN_LODIST_1_LO_HB_GEN_THRSH6_GET(x)                                   (((x) & SYN_LODIST_1_LO_HB_GEN_THRSH6_MASK) >> SYN_LODIST_1_LO_HB_GEN_THRSH6_LSB)
#define SYN_LODIST_1_LO_HB_GEN_THRSH6_SET(x)                                   (((0 | (x)) << SYN_LODIST_1_LO_HB_GEN_THRSH6_LSB) & SYN_LODIST_1_LO_HB_GEN_THRSH6_MASK)
#define SYN_LODIST_1_LO_HB_GEN_THRSH6_RESET                                    0x1b
#define SYN_LODIST_1_LO_HB_GEN_THRSH7_LSB                                      20
#define SYN_LODIST_1_LO_HB_GEN_THRSH7_MSB                                      25
#define SYN_LODIST_1_LO_HB_GEN_THRSH7_MASK                                     0x3f00000
#define SYN_LODIST_1_LO_HB_GEN_THRSH7_GET(x)                                   (((x) & SYN_LODIST_1_LO_HB_GEN_THRSH7_MASK) >> SYN_LODIST_1_LO_HB_GEN_THRSH7_LSB)
#define SYN_LODIST_1_LO_HB_GEN_THRSH7_SET(x)                                   (((0 | (x)) << SYN_LODIST_1_LO_HB_GEN_THRSH7_LSB) & SYN_LODIST_1_LO_HB_GEN_THRSH7_MASK)
#define SYN_LODIST_1_LO_HB_GEN_THRSH7_RESET                                    0x22
#define SYN_LODIST_1_LO_LB_GEN_THRSH1_LSB                                      14
#define SYN_LODIST_1_LO_LB_GEN_THRSH1_MSB                                      19
#define SYN_LODIST_1_LO_LB_GEN_THRSH1_MASK                                     0xfc000
#define SYN_LODIST_1_LO_LB_GEN_THRSH1_GET(x)                                   (((x) & SYN_LODIST_1_LO_LB_GEN_THRSH1_MASK) >> SYN_LODIST_1_LO_LB_GEN_THRSH1_LSB)
#define SYN_LODIST_1_LO_LB_GEN_THRSH1_SET(x)                                   (((0 | (x)) << SYN_LODIST_1_LO_LB_GEN_THRSH1_LSB) & SYN_LODIST_1_LO_LB_GEN_THRSH1_MASK)
#define SYN_LODIST_1_LO_LB_GEN_THRSH1_RESET                                    0x0
#define SYN_LODIST_1_LO_LB_GEN_THRSH2_LSB                                      8
#define SYN_LODIST_1_LO_LB_GEN_THRSH2_MSB                                      13
#define SYN_LODIST_1_LO_LB_GEN_THRSH2_MASK                                     0x3f00
#define SYN_LODIST_1_LO_LB_GEN_THRSH2_GET(x)                                   (((x) & SYN_LODIST_1_LO_LB_GEN_THRSH2_MASK) >> SYN_LODIST_1_LO_LB_GEN_THRSH2_LSB)
#define SYN_LODIST_1_LO_LB_GEN_THRSH2_SET(x)                                   (((0 | (x)) << SYN_LODIST_1_LO_LB_GEN_THRSH2_LSB) & SYN_LODIST_1_LO_LB_GEN_THRSH2_MASK)
#define SYN_LODIST_1_LO_LB_GEN_THRSH2_RESET                                    0x0
#define SYN_LODIST_1_LO_LB_GEN_THRSH3_LSB                                      2
#define SYN_LODIST_1_LO_LB_GEN_THRSH3_MSB                                      7
#define SYN_LODIST_1_LO_LB_GEN_THRSH3_MASK                                     0xfc
#define SYN_LODIST_1_LO_LB_GEN_THRSH3_GET(x)                                   (((x) & SYN_LODIST_1_LO_LB_GEN_THRSH3_MASK) >> SYN_LODIST_1_LO_LB_GEN_THRSH3_LSB)
#define SYN_LODIST_1_LO_LB_GEN_THRSH3_SET(x)                                   (((0 | (x)) << SYN_LODIST_1_LO_LB_GEN_THRSH3_LSB) & SYN_LODIST_1_LO_LB_GEN_THRSH3_MASK)
#define SYN_LODIST_1_LO_LB_GEN_THRSH3_RESET                                    0x0
#define SYN_LODIST_1_RESERVED_0_LSB                                            0
#define SYN_LODIST_1_RESERVED_0_MSB                                            1
#define SYN_LODIST_1_RESERVED_0_MASK                                           0x3
#define SYN_LODIST_1_RESERVED_0_GET(x)                                         (((x) & SYN_LODIST_1_RESERVED_0_MASK) >> SYN_LODIST_1_RESERVED_0_LSB)
#define SYN_LODIST_1_RESERVED_0_SET(x)                                         (((0 | (x)) << SYN_LODIST_1_RESERVED_0_LSB) & SYN_LODIST_1_RESERVED_0_MASK)
#define SYN_LODIST_1_RESERVED_0_RESET                                          0x0
#define SYN_LODIST_1_ADDRESS                                                   (0x4 + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_LODIST_1_RSTMASK                                                   0xffffffff
#define SYN_LODIST_1_RESET                                                     0x6e200000

// 0x8 (SYN_LODIST_2)
#define SYN_LODIST_2_LO_LB_GEN_THRSH4_LSB                                      26
#define SYN_LODIST_2_LO_LB_GEN_THRSH4_MSB                                      31
#define SYN_LODIST_2_LO_LB_GEN_THRSH4_MASK                                     0xfc000000
#define SYN_LODIST_2_LO_LB_GEN_THRSH4_GET(x)                                   (((x) & SYN_LODIST_2_LO_LB_GEN_THRSH4_MASK) >> SYN_LODIST_2_LO_LB_GEN_THRSH4_LSB)
#define SYN_LODIST_2_LO_LB_GEN_THRSH4_SET(x)                                   (((0 | (x)) << SYN_LODIST_2_LO_LB_GEN_THRSH4_LSB) & SYN_LODIST_2_LO_LB_GEN_THRSH4_MASK)
#define SYN_LODIST_2_LO_LB_GEN_THRSH4_RESET                                    0x2
#define SYN_LODIST_2_LO_LB_GEN_THRSH5_LSB                                      20
#define SYN_LODIST_2_LO_LB_GEN_THRSH5_MSB                                      25
#define SYN_LODIST_2_LO_LB_GEN_THRSH5_MASK                                     0x3f00000
#define SYN_LODIST_2_LO_LB_GEN_THRSH5_GET(x)                                   (((x) & SYN_LODIST_2_LO_LB_GEN_THRSH5_MASK) >> SYN_LODIST_2_LO_LB_GEN_THRSH5_LSB)
#define SYN_LODIST_2_LO_LB_GEN_THRSH5_SET(x)                                   (((0 | (x)) << SYN_LODIST_2_LO_LB_GEN_THRSH5_LSB) & SYN_LODIST_2_LO_LB_GEN_THRSH5_MASK)
#define SYN_LODIST_2_LO_LB_GEN_THRSH5_RESET                                    0x7
#define SYN_LODIST_2_LO_LB_GEN_THRSH6_LSB                                      14
#define SYN_LODIST_2_LO_LB_GEN_THRSH6_MSB                                      19
#define SYN_LODIST_2_LO_LB_GEN_THRSH6_MASK                                     0xfc000
#define SYN_LODIST_2_LO_LB_GEN_THRSH6_GET(x)                                   (((x) & SYN_LODIST_2_LO_LB_GEN_THRSH6_MASK) >> SYN_LODIST_2_LO_LB_GEN_THRSH6_LSB)
#define SYN_LODIST_2_LO_LB_GEN_THRSH6_SET(x)                                   (((0 | (x)) << SYN_LODIST_2_LO_LB_GEN_THRSH6_LSB) & SYN_LODIST_2_LO_LB_GEN_THRSH6_MASK)
#define SYN_LODIST_2_LO_LB_GEN_THRSH6_RESET                                    0xd
#define SYN_LODIST_2_LO_LB_GEN_THRSH7_LSB                                      8
#define SYN_LODIST_2_LO_LB_GEN_THRSH7_MSB                                      13
#define SYN_LODIST_2_LO_LB_GEN_THRSH7_MASK                                     0x3f00
#define SYN_LODIST_2_LO_LB_GEN_THRSH7_GET(x)                                   (((x) & SYN_LODIST_2_LO_LB_GEN_THRSH7_MASK) >> SYN_LODIST_2_LO_LB_GEN_THRSH7_LSB)
#define SYN_LODIST_2_LO_LB_GEN_THRSH7_SET(x)                                   (((0 | (x)) << SYN_LODIST_2_LO_LB_GEN_THRSH7_LSB) & SYN_LODIST_2_LO_LB_GEN_THRSH7_MASK)
#define SYN_LODIST_2_LO_LB_GEN_THRSH7_RESET                                    0x13
#define SYN_LODIST_2_LO_DIST_THRSH1_LSB                                        2
#define SYN_LODIST_2_LO_DIST_THRSH1_MSB                                        7
#define SYN_LODIST_2_LO_DIST_THRSH1_MASK                                       0xfc
#define SYN_LODIST_2_LO_DIST_THRSH1_GET(x)                                     (((x) & SYN_LODIST_2_LO_DIST_THRSH1_MASK) >> SYN_LODIST_2_LO_DIST_THRSH1_LSB)
#define SYN_LODIST_2_LO_DIST_THRSH1_SET(x)                                     (((0 | (x)) << SYN_LODIST_2_LO_DIST_THRSH1_LSB) & SYN_LODIST_2_LO_DIST_THRSH1_MASK)
#define SYN_LODIST_2_LO_DIST_THRSH1_RESET                                      0x3
#define SYN_LODIST_2_RESERVED_0_LSB                                            0
#define SYN_LODIST_2_RESERVED_0_MSB                                            1
#define SYN_LODIST_2_RESERVED_0_MASK                                           0x3
#define SYN_LODIST_2_RESERVED_0_GET(x)                                         (((x) & SYN_LODIST_2_RESERVED_0_MASK) >> SYN_LODIST_2_RESERVED_0_LSB)
#define SYN_LODIST_2_RESERVED_0_SET(x)                                         (((0 | (x)) << SYN_LODIST_2_RESERVED_0_LSB) & SYN_LODIST_2_RESERVED_0_MASK)
#define SYN_LODIST_2_RESERVED_0_RESET                                          0x0
#define SYN_LODIST_2_ADDRESS                                                   (0x8 + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_LODIST_2_RSTMASK                                                   0xffffffff
#define SYN_LODIST_2_RESET                                                     0x873530c

// 0xc (SYN_LODIST_3)
#define SYN_LODIST_3_LO_DIST_THRSH2_LSB                                        26
#define SYN_LODIST_3_LO_DIST_THRSH2_MSB                                        31
#define SYN_LODIST_3_LO_DIST_THRSH2_MASK                                       0xfc000000
#define SYN_LODIST_3_LO_DIST_THRSH2_GET(x)                                     (((x) & SYN_LODIST_3_LO_DIST_THRSH2_MASK) >> SYN_LODIST_3_LO_DIST_THRSH2_LSB)
#define SYN_LODIST_3_LO_DIST_THRSH2_SET(x)                                     (((0 | (x)) << SYN_LODIST_3_LO_DIST_THRSH2_LSB) & SYN_LODIST_3_LO_DIST_THRSH2_MASK)
#define SYN_LODIST_3_LO_DIST_THRSH2_RESET                                      0x8
#define SYN_LODIST_3_LO_DIST_THRSH3_LSB                                        20
#define SYN_LODIST_3_LO_DIST_THRSH3_MSB                                        25
#define SYN_LODIST_3_LO_DIST_THRSH3_MASK                                       0x3f00000
#define SYN_LODIST_3_LO_DIST_THRSH3_GET(x)                                     (((x) & SYN_LODIST_3_LO_DIST_THRSH3_MASK) >> SYN_LODIST_3_LO_DIST_THRSH3_LSB)
#define SYN_LODIST_3_LO_DIST_THRSH3_SET(x)                                     (((0 | (x)) << SYN_LODIST_3_LO_DIST_THRSH3_LSB) & SYN_LODIST_3_LO_DIST_THRSH3_MASK)
#define SYN_LODIST_3_LO_DIST_THRSH3_RESET                                      0xd
#define SYN_LODIST_3_LO_DIST_THRSH4_LSB                                        14
#define SYN_LODIST_3_LO_DIST_THRSH4_MSB                                        19
#define SYN_LODIST_3_LO_DIST_THRSH4_MASK                                       0xfc000
#define SYN_LODIST_3_LO_DIST_THRSH4_GET(x)                                     (((x) & SYN_LODIST_3_LO_DIST_THRSH4_MASK) >> SYN_LODIST_3_LO_DIST_THRSH4_LSB)
#define SYN_LODIST_3_LO_DIST_THRSH4_SET(x)                                     (((0 | (x)) << SYN_LODIST_3_LO_DIST_THRSH4_LSB) & SYN_LODIST_3_LO_DIST_THRSH4_MASK)
#define SYN_LODIST_3_LO_DIST_THRSH4_RESET                                      0x13
#define SYN_LODIST_3_LO_DIST_THRSH5_LSB                                        8
#define SYN_LODIST_3_LO_DIST_THRSH5_MSB                                        13
#define SYN_LODIST_3_LO_DIST_THRSH5_MASK                                       0x3f00
#define SYN_LODIST_3_LO_DIST_THRSH5_GET(x)                                     (((x) & SYN_LODIST_3_LO_DIST_THRSH5_MASK) >> SYN_LODIST_3_LO_DIST_THRSH5_LSB)
#define SYN_LODIST_3_LO_DIST_THRSH5_SET(x)                                     (((0 | (x)) << SYN_LODIST_3_LO_DIST_THRSH5_LSB) & SYN_LODIST_3_LO_DIST_THRSH5_MASK)
#define SYN_LODIST_3_LO_DIST_THRSH5_RESET                                      0x19
#define SYN_LODIST_3_RESERVED_0_LSB                                            0
#define SYN_LODIST_3_RESERVED_0_MSB                                            7
#define SYN_LODIST_3_RESERVED_0_MASK                                           0xff
#define SYN_LODIST_3_RESERVED_0_GET(x)                                         (((x) & SYN_LODIST_3_RESERVED_0_MASK) >> SYN_LODIST_3_RESERVED_0_LSB)
#define SYN_LODIST_3_RESERVED_0_SET(x)                                         (((0 | (x)) << SYN_LODIST_3_RESERVED_0_LSB) & SYN_LODIST_3_RESERVED_0_MASK)
#define SYN_LODIST_3_RESERVED_0_RESET                                          0x0
#define SYN_LODIST_3_ADDRESS                                                   (0xc + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_LODIST_3_RSTMASK                                                   0xffffffff
#define SYN_LODIST_3_RESET                                                     0x20d4d900

// 0x10 (SYN_PAL_0)
#define SYN_PAL_0_PAL_START_LSB                                                31
#define SYN_PAL_0_PAL_START_MSB                                                31
#define SYN_PAL_0_PAL_START_MASK                                               0x80000000
#define SYN_PAL_0_PAL_START_GET(x)                                             (((x) & SYN_PAL_0_PAL_START_MASK) >> SYN_PAL_0_PAL_START_LSB)
#define SYN_PAL_0_PAL_START_SET(x)                                             (((0 | (x)) << SYN_PAL_0_PAL_START_LSB) & SYN_PAL_0_PAL_START_MASK)
#define SYN_PAL_0_PAL_START_RESET                                              0x0
#define SYN_PAL_0_PAL_DISABLE_LSB                                              30
#define SYN_PAL_0_PAL_DISABLE_MSB                                              30
#define SYN_PAL_0_PAL_DISABLE_MASK                                             0x40000000
#define SYN_PAL_0_PAL_DISABLE_GET(x)                                           (((x) & SYN_PAL_0_PAL_DISABLE_MASK) >> SYN_PAL_0_PAL_DISABLE_LSB)
#define SYN_PAL_0_PAL_DISABLE_SET(x)                                           (((0 | (x)) << SYN_PAL_0_PAL_DISABLE_LSB) & SYN_PAL_0_PAL_DISABLE_MASK)
#define SYN_PAL_0_PAL_DISABLE_RESET                                            0x0
#define SYN_PAL_0_PAL_COMP_REPEAT_LSB                                          28
#define SYN_PAL_0_PAL_COMP_REPEAT_MSB                                          29
#define SYN_PAL_0_PAL_COMP_REPEAT_MASK                                         0x30000000
#define SYN_PAL_0_PAL_COMP_REPEAT_GET(x)                                       (((x) & SYN_PAL_0_PAL_COMP_REPEAT_MASK) >> SYN_PAL_0_PAL_COMP_REPEAT_LSB)
#define SYN_PAL_0_PAL_COMP_REPEAT_SET(x)                                       (((0 | (x)) << SYN_PAL_0_PAL_COMP_REPEAT_LSB) & SYN_PAL_0_PAL_COMP_REPEAT_MASK)
#define SYN_PAL_0_PAL_COMP_REPEAT_RESET                                        0x0
#define SYN_PAL_0_PAL_COMP_CAL_DELAY_LSB                                       26
#define SYN_PAL_0_PAL_COMP_CAL_DELAY_MSB                                       27
#define SYN_PAL_0_PAL_COMP_CAL_DELAY_MASK                                      0xc000000
#define SYN_PAL_0_PAL_COMP_CAL_DELAY_GET(x)                                    (((x) & SYN_PAL_0_PAL_COMP_CAL_DELAY_MASK) >> SYN_PAL_0_PAL_COMP_CAL_DELAY_LSB)
#define SYN_PAL_0_PAL_COMP_CAL_DELAY_SET(x)                                    (((0 | (x)) << SYN_PAL_0_PAL_COMP_CAL_DELAY_LSB) & SYN_PAL_0_PAL_COMP_CAL_DELAY_MASK)
#define SYN_PAL_0_PAL_COMP_CAL_DELAY_RESET                                     0x0
#define SYN_PAL_0_PAL_COMP_START_DELAY_LSB                                     23
#define SYN_PAL_0_PAL_COMP_START_DELAY_MSB                                     25
#define SYN_PAL_0_PAL_COMP_START_DELAY_MASK                                    0x3800000
#define SYN_PAL_0_PAL_COMP_START_DELAY_GET(x)                                  (((x) & SYN_PAL_0_PAL_COMP_START_DELAY_MASK) >> SYN_PAL_0_PAL_COMP_START_DELAY_LSB)
#define SYN_PAL_0_PAL_COMP_START_DELAY_SET(x)                                  (((0 | (x)) << SYN_PAL_0_PAL_COMP_START_DELAY_LSB) & SYN_PAL_0_PAL_COMP_START_DELAY_MASK)
#define SYN_PAL_0_PAL_COMP_START_DELAY_RESET                                   0x2
#define SYN_PAL_0_PAL_COMP_DUR_LSB                                             21
#define SYN_PAL_0_PAL_COMP_DUR_MSB                                             22
#define SYN_PAL_0_PAL_COMP_DUR_MASK                                            0x600000
#define SYN_PAL_0_PAL_COMP_DUR_GET(x)                                          (((x) & SYN_PAL_0_PAL_COMP_DUR_MASK) >> SYN_PAL_0_PAL_COMP_DUR_LSB)
#define SYN_PAL_0_PAL_COMP_DUR_SET(x)                                          (((0 | (x)) << SYN_PAL_0_PAL_COMP_DUR_LSB) & SYN_PAL_0_PAL_COMP_DUR_MASK)
#define SYN_PAL_0_PAL_COMP_DUR_RESET                                           0x1
#define SYN_PAL_0_PAL_LB_MODE_LSB                                              18
#define SYN_PAL_0_PAL_LB_MODE_MSB                                              20
#define SYN_PAL_0_PAL_LB_MODE_MASK                                             0x1c0000
#define SYN_PAL_0_PAL_LB_MODE_GET(x)                                           (((x) & SYN_PAL_0_PAL_LB_MODE_MASK) >> SYN_PAL_0_PAL_LB_MODE_LSB)
#define SYN_PAL_0_PAL_LB_MODE_SET(x)                                           (((0 | (x)) << SYN_PAL_0_PAL_LB_MODE_LSB) & SYN_PAL_0_PAL_LB_MODE_MASK)
#define SYN_PAL_0_PAL_LB_MODE_RESET                                            0x0
#define SYN_PAL_0_PAL_DISABLE_RST3_HB_LSB                                      17
#define SYN_PAL_0_PAL_DISABLE_RST3_HB_MSB                                      17
#define SYN_PAL_0_PAL_DISABLE_RST3_HB_MASK                                     0x20000
#define SYN_PAL_0_PAL_DISABLE_RST3_HB_GET(x)                                   (((x) & SYN_PAL_0_PAL_DISABLE_RST3_HB_MASK) >> SYN_PAL_0_PAL_DISABLE_RST3_HB_LSB)
#define SYN_PAL_0_PAL_DISABLE_RST3_HB_SET(x)                                   (((0 | (x)) << SYN_PAL_0_PAL_DISABLE_RST3_HB_LSB) & SYN_PAL_0_PAL_DISABLE_RST3_HB_MASK)
#define SYN_PAL_0_PAL_DISABLE_RST3_HB_RESET                                    0x0
#define SYN_PAL_0_PAL_DISABLE_RST3_LB_LSB                                      16
#define SYN_PAL_0_PAL_DISABLE_RST3_LB_MSB                                      16
#define SYN_PAL_0_PAL_DISABLE_RST3_LB_MASK                                     0x10000
#define SYN_PAL_0_PAL_DISABLE_RST3_LB_GET(x)                                   (((x) & SYN_PAL_0_PAL_DISABLE_RST3_LB_MASK) >> SYN_PAL_0_PAL_DISABLE_RST3_LB_LSB)
#define SYN_PAL_0_PAL_DISABLE_RST3_LB_SET(x)                                   (((0 | (x)) << SYN_PAL_0_PAL_DISABLE_RST3_LB_LSB) & SYN_PAL_0_PAL_DISABLE_RST3_LB_MASK)
#define SYN_PAL_0_PAL_DISABLE_RST3_LB_RESET                                    0x0
#define SYN_PAL_0_PAL_DISABLE_RST2_LB_LSB                                      15
#define SYN_PAL_0_PAL_DISABLE_RST2_LB_MSB                                      15
#define SYN_PAL_0_PAL_DISABLE_RST2_LB_MASK                                     0x8000
#define SYN_PAL_0_PAL_DISABLE_RST2_LB_GET(x)                                   (((x) & SYN_PAL_0_PAL_DISABLE_RST2_LB_MASK) >> SYN_PAL_0_PAL_DISABLE_RST2_LB_LSB)
#define SYN_PAL_0_PAL_DISABLE_RST2_LB_SET(x)                                   (((0 | (x)) << SYN_PAL_0_PAL_DISABLE_RST2_LB_LSB) & SYN_PAL_0_PAL_DISABLE_RST2_LB_MASK)
#define SYN_PAL_0_PAL_DISABLE_RST2_LB_RESET                                    0x0
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_HB_LSB                                 14
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_HB_MSB                                 14
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_HB_MASK                                0x4000
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_HB_GET(x)                              (((x) & SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_HB_MASK) >> SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_HB_LSB)
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_HB_SET(x)                              (((0 | (x)) << SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_HB_LSB) & SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_HB_MASK)
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_HB_RESET                               0x0
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_LB_LSB                                 13
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_LB_MSB                                 13
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_LB_MASK                                0x2000
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_LB_GET(x)                              (((x) & SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_LB_MASK) >> SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_LB_LSB)
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_LB_SET(x)                              (((0 | (x)) << SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_LB_LSB) & SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_LB_MASK)
#define SYN_PAL_0_PAL_DISABLE_FLIP_MDIV_LB_RESET                               0x1
#define SYN_PAL_0_PAL_DISABLE_FLIP_RTX_LSB                                     12
#define SYN_PAL_0_PAL_DISABLE_FLIP_RTX_MSB                                     12
#define SYN_PAL_0_PAL_DISABLE_FLIP_RTX_MASK                                    0x1000
#define SYN_PAL_0_PAL_DISABLE_FLIP_RTX_GET(x)                                  (((x) & SYN_PAL_0_PAL_DISABLE_FLIP_RTX_MASK) >> SYN_PAL_0_PAL_DISABLE_FLIP_RTX_LSB)
#define SYN_PAL_0_PAL_DISABLE_FLIP_RTX_SET(x)                                  (((0 | (x)) << SYN_PAL_0_PAL_DISABLE_FLIP_RTX_LSB) & SYN_PAL_0_PAL_DISABLE_FLIP_RTX_MASK)
#define SYN_PAL_0_PAL_DISABLE_FLIP_RTX_RESET                                   0x0
#define SYN_PAL_0_PAL_IGNORE_PALOUT_HB_LSB                                     11
#define SYN_PAL_0_PAL_IGNORE_PALOUT_HB_MSB                                     11
#define SYN_PAL_0_PAL_IGNORE_PALOUT_HB_MASK                                    0x800
#define SYN_PAL_0_PAL_IGNORE_PALOUT_HB_GET(x)                                  (((x) & SYN_PAL_0_PAL_IGNORE_PALOUT_HB_MASK) >> SYN_PAL_0_PAL_IGNORE_PALOUT_HB_LSB)
#define SYN_PAL_0_PAL_IGNORE_PALOUT_HB_SET(x)                                  (((0 | (x)) << SYN_PAL_0_PAL_IGNORE_PALOUT_HB_LSB) & SYN_PAL_0_PAL_IGNORE_PALOUT_HB_MASK)
#define SYN_PAL_0_PAL_IGNORE_PALOUT_HB_RESET                                   0x0
#define SYN_PAL_0_PAL_IGNORE_PALOUT_LB_LSB                                     10
#define SYN_PAL_0_PAL_IGNORE_PALOUT_LB_MSB                                     10
#define SYN_PAL_0_PAL_IGNORE_PALOUT_LB_MASK                                    0x400
#define SYN_PAL_0_PAL_IGNORE_PALOUT_LB_GET(x)                                  (((x) & SYN_PAL_0_PAL_IGNORE_PALOUT_LB_MASK) >> SYN_PAL_0_PAL_IGNORE_PALOUT_LB_LSB)
#define SYN_PAL_0_PAL_IGNORE_PALOUT_LB_SET(x)                                  (((0 | (x)) << SYN_PAL_0_PAL_IGNORE_PALOUT_LB_LSB) & SYN_PAL_0_PAL_IGNORE_PALOUT_LB_MASK)
#define SYN_PAL_0_PAL_IGNORE_PALOUT_LB_RESET                                   0x0
#define SYN_PAL_0_PAL_LORST_DIV3_OVR_LSB                                       8
#define SYN_PAL_0_PAL_LORST_DIV3_OVR_MSB                                       9
#define SYN_PAL_0_PAL_LORST_DIV3_OVR_MASK                                      0x300
#define SYN_PAL_0_PAL_LORST_DIV3_OVR_GET(x)                                    (((x) & SYN_PAL_0_PAL_LORST_DIV3_OVR_MASK) >> SYN_PAL_0_PAL_LORST_DIV3_OVR_LSB)
#define SYN_PAL_0_PAL_LORST_DIV3_OVR_SET(x)                                    (((0 | (x)) << SYN_PAL_0_PAL_LORST_DIV3_OVR_LSB) & SYN_PAL_0_PAL_LORST_DIV3_OVR_MASK)
#define SYN_PAL_0_PAL_LORST_DIV3_OVR_RESET                                     0x0
#define SYN_PAL_0_PAL_LORST_DIV2_OVR_LSB                                       6
#define SYN_PAL_0_PAL_LORST_DIV2_OVR_MSB                                       7
#define SYN_PAL_0_PAL_LORST_DIV2_OVR_MASK                                      0xc0
#define SYN_PAL_0_PAL_LORST_DIV2_OVR_GET(x)                                    (((x) & SYN_PAL_0_PAL_LORST_DIV2_OVR_MASK) >> SYN_PAL_0_PAL_LORST_DIV2_OVR_LSB)
#define SYN_PAL_0_PAL_LORST_DIV2_OVR_SET(x)                                    (((0 | (x)) << SYN_PAL_0_PAL_LORST_DIV2_OVR_LSB) & SYN_PAL_0_PAL_LORST_DIV2_OVR_MASK)
#define SYN_PAL_0_PAL_LORST_DIV2_OVR_RESET                                     0x0
#define SYN_PAL_0_PAL_FLIP_MDIV_RESET_LSB                                      5
#define SYN_PAL_0_PAL_FLIP_MDIV_RESET_MSB                                      5
#define SYN_PAL_0_PAL_FLIP_MDIV_RESET_MASK                                     0x20
#define SYN_PAL_0_PAL_FLIP_MDIV_RESET_GET(x)                                   (((x) & SYN_PAL_0_PAL_FLIP_MDIV_RESET_MASK) >> SYN_PAL_0_PAL_FLIP_MDIV_RESET_LSB)
#define SYN_PAL_0_PAL_FLIP_MDIV_RESET_SET(x)                                   (((0 | (x)) << SYN_PAL_0_PAL_FLIP_MDIV_RESET_LSB) & SYN_PAL_0_PAL_FLIP_MDIV_RESET_MASK)
#define SYN_PAL_0_PAL_FLIP_MDIV_RESET_RESET                                    0x0
#define SYN_PAL_0_PAL_FLIP_RXDIV_RESET_LSB                                     4
#define SYN_PAL_0_PAL_FLIP_RXDIV_RESET_MSB                                     4
#define SYN_PAL_0_PAL_FLIP_RXDIV_RESET_MASK                                    0x10
#define SYN_PAL_0_PAL_FLIP_RXDIV_RESET_GET(x)                                  (((x) & SYN_PAL_0_PAL_FLIP_RXDIV_RESET_MASK) >> SYN_PAL_0_PAL_FLIP_RXDIV_RESET_LSB)
#define SYN_PAL_0_PAL_FLIP_RXDIV_RESET_SET(x)                                  (((0 | (x)) << SYN_PAL_0_PAL_FLIP_RXDIV_RESET_LSB) & SYN_PAL_0_PAL_FLIP_RXDIV_RESET_MASK)
#define SYN_PAL_0_PAL_FLIP_RXDIV_RESET_RESET                                   0x0
#define SYN_PAL_0_PAL_FLIP_TXDIV_RESET_LSB                                     3
#define SYN_PAL_0_PAL_FLIP_TXDIV_RESET_MSB                                     3
#define SYN_PAL_0_PAL_FLIP_TXDIV_RESET_MASK                                    0x8
#define SYN_PAL_0_PAL_FLIP_TXDIV_RESET_GET(x)                                  (((x) & SYN_PAL_0_PAL_FLIP_TXDIV_RESET_MASK) >> SYN_PAL_0_PAL_FLIP_TXDIV_RESET_LSB)
#define SYN_PAL_0_PAL_FLIP_TXDIV_RESET_SET(x)                                  (((0 | (x)) << SYN_PAL_0_PAL_FLIP_TXDIV_RESET_LSB) & SYN_PAL_0_PAL_FLIP_TXDIV_RESET_MASK)
#define SYN_PAL_0_PAL_FLIP_TXDIV_RESET_RESET                                   0x0
#define SYN_PAL_0_PAL_FLIP_MDIV_CLR_EN_LSB                                     2
#define SYN_PAL_0_PAL_FLIP_MDIV_CLR_EN_MSB                                     2
#define SYN_PAL_0_PAL_FLIP_MDIV_CLR_EN_MASK                                    0x4
#define SYN_PAL_0_PAL_FLIP_MDIV_CLR_EN_GET(x)                                  (((x) & SYN_PAL_0_PAL_FLIP_MDIV_CLR_EN_MASK) >> SYN_PAL_0_PAL_FLIP_MDIV_CLR_EN_LSB)
#define SYN_PAL_0_PAL_FLIP_MDIV_CLR_EN_SET(x)                                  (((0 | (x)) << SYN_PAL_0_PAL_FLIP_MDIV_CLR_EN_LSB) & SYN_PAL_0_PAL_FLIP_MDIV_CLR_EN_MASK)
#define SYN_PAL_0_PAL_FLIP_MDIV_CLR_EN_RESET                                   0x1
#define SYN_PAL_0_PAL_FLIP_RTXDIV_CLR_EN_LSB                                   1
#define SYN_PAL_0_PAL_FLIP_RTXDIV_CLR_EN_MSB                                   1
#define SYN_PAL_0_PAL_FLIP_RTXDIV_CLR_EN_MASK                                  0x2
#define SYN_PAL_0_PAL_FLIP_RTXDIV_CLR_EN_GET(x)                                (((x) & SYN_PAL_0_PAL_FLIP_RTXDIV_CLR_EN_MASK) >> SYN_PAL_0_PAL_FLIP_RTXDIV_CLR_EN_LSB)
#define SYN_PAL_0_PAL_FLIP_RTXDIV_CLR_EN_SET(x)                                (((0 | (x)) << SYN_PAL_0_PAL_FLIP_RTXDIV_CLR_EN_LSB) & SYN_PAL_0_PAL_FLIP_RTXDIV_CLR_EN_MASK)
#define SYN_PAL_0_PAL_FLIP_RTXDIV_CLR_EN_RESET                                 0x1
#define SYN_PAL_0_PAL_START_SEL_LSB                                            0
#define SYN_PAL_0_PAL_START_SEL_MSB                                            0
#define SYN_PAL_0_PAL_START_SEL_MASK                                           0x1
#define SYN_PAL_0_PAL_START_SEL_GET(x)                                         (((x) & SYN_PAL_0_PAL_START_SEL_MASK) >> SYN_PAL_0_PAL_START_SEL_LSB)
#define SYN_PAL_0_PAL_START_SEL_SET(x)                                         (((0 | (x)) << SYN_PAL_0_PAL_START_SEL_LSB) & SYN_PAL_0_PAL_START_SEL_MASK)
#define SYN_PAL_0_PAL_START_SEL_RESET                                          0x0
#define SYN_PAL_0_ADDRESS                                                      (0x10 + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_PAL_0_RSTMASK                                                      0xffffffff
#define SYN_PAL_0_RESET                                                        0x1202006

// 0x14 (SYN_PAL_1)
#define SYN_PAL_1_PAL_FLIP_DATA_LSB                                            20
#define SYN_PAL_1_PAL_FLIP_DATA_MSB                                            31
#define SYN_PAL_1_PAL_FLIP_DATA_MASK                                           0xfff00000
#define SYN_PAL_1_PAL_FLIP_DATA_GET(x)                                         (((x) & SYN_PAL_1_PAL_FLIP_DATA_MASK) >> SYN_PAL_1_PAL_FLIP_DATA_LSB)
#define SYN_PAL_1_PAL_FLIP_DATA_SET(x)                                         (((0 | (x)) << SYN_PAL_1_PAL_FLIP_DATA_LSB) & SYN_PAL_1_PAL_FLIP_DATA_MASK)
#define SYN_PAL_1_PAL_FLIP_DATA_RESET                                          0x0
#define SYN_PAL_1_PAL_FLIP_START_LSB                                           19
#define SYN_PAL_1_PAL_FLIP_START_MSB                                           19
#define SYN_PAL_1_PAL_FLIP_START_MASK                                          0x80000
#define SYN_PAL_1_PAL_FLIP_START_GET(x)                                        (((x) & SYN_PAL_1_PAL_FLIP_START_MASK) >> SYN_PAL_1_PAL_FLIP_START_LSB)
#define SYN_PAL_1_PAL_FLIP_START_SET(x)                                        (((0 | (x)) << SYN_PAL_1_PAL_FLIP_START_LSB) & SYN_PAL_1_PAL_FLIP_START_MASK)
#define SYN_PAL_1_PAL_FLIP_START_RESET                                         0x0
#define SYN_PAL_1_RESERVED_0_LSB                                               12
#define SYN_PAL_1_RESERVED_0_MSB                                               18
#define SYN_PAL_1_RESERVED_0_MASK                                              0x7f000
#define SYN_PAL_1_RESERVED_0_GET(x)                                            (((x) & SYN_PAL_1_RESERVED_0_MASK) >> SYN_PAL_1_RESERVED_0_LSB)
#define SYN_PAL_1_RESERVED_0_SET(x)                                            (((0 | (x)) << SYN_PAL_1_RESERVED_0_LSB) & SYN_PAL_1_RESERVED_0_MASK)
#define SYN_PAL_1_RESERVED_0_RESET                                             0x0
#define SYN_PAL_1_PAL_CH_SEL_DTEST0_LSB                                        10
#define SYN_PAL_1_PAL_CH_SEL_DTEST0_MSB                                        11
#define SYN_PAL_1_PAL_CH_SEL_DTEST0_MASK                                       0xc00
#define SYN_PAL_1_PAL_CH_SEL_DTEST0_GET(x)                                     (((x) & SYN_PAL_1_PAL_CH_SEL_DTEST0_MASK) >> SYN_PAL_1_PAL_CH_SEL_DTEST0_LSB)
#define SYN_PAL_1_PAL_CH_SEL_DTEST0_SET(x)                                     (((0 | (x)) << SYN_PAL_1_PAL_CH_SEL_DTEST0_LSB) & SYN_PAL_1_PAL_CH_SEL_DTEST0_MASK)
#define SYN_PAL_1_PAL_CH_SEL_DTEST0_RESET                                      0x0
#define SYN_PAL_1_PAL_CH_SEL_DTEST1_LSB                                        8
#define SYN_PAL_1_PAL_CH_SEL_DTEST1_MSB                                        9
#define SYN_PAL_1_PAL_CH_SEL_DTEST1_MASK                                       0x300
#define SYN_PAL_1_PAL_CH_SEL_DTEST1_GET(x)                                     (((x) & SYN_PAL_1_PAL_CH_SEL_DTEST1_MASK) >> SYN_PAL_1_PAL_CH_SEL_DTEST1_LSB)
#define SYN_PAL_1_PAL_CH_SEL_DTEST1_SET(x)                                     (((0 | (x)) << SYN_PAL_1_PAL_CH_SEL_DTEST1_LSB) & SYN_PAL_1_PAL_CH_SEL_DTEST1_MASK)
#define SYN_PAL_1_PAL_CH_SEL_DTEST1_RESET                                      0x0
#define SYN_PAL_1_PAL_DTEST0_LSB                                               4
#define SYN_PAL_1_PAL_DTEST0_MSB                                               7
#define SYN_PAL_1_PAL_DTEST0_MASK                                              0xf0
#define SYN_PAL_1_PAL_DTEST0_GET(x)                                            (((x) & SYN_PAL_1_PAL_DTEST0_MASK) >> SYN_PAL_1_PAL_DTEST0_LSB)
#define SYN_PAL_1_PAL_DTEST0_SET(x)                                            (((0 | (x)) << SYN_PAL_1_PAL_DTEST0_LSB) & SYN_PAL_1_PAL_DTEST0_MASK)
#define SYN_PAL_1_PAL_DTEST0_RESET                                             0x0
#define SYN_PAL_1_PAL_DTEST1_LSB                                               0
#define SYN_PAL_1_PAL_DTEST1_MSB                                               3
#define SYN_PAL_1_PAL_DTEST1_MASK                                              0xf
#define SYN_PAL_1_PAL_DTEST1_GET(x)                                            (((x) & SYN_PAL_1_PAL_DTEST1_MASK) >> SYN_PAL_1_PAL_DTEST1_LSB)
#define SYN_PAL_1_PAL_DTEST1_SET(x)                                            (((0 | (x)) << SYN_PAL_1_PAL_DTEST1_LSB) & SYN_PAL_1_PAL_DTEST1_MASK)
#define SYN_PAL_1_PAL_DTEST1_RESET                                             0x0
#define SYN_PAL_1_ADDRESS                                                      (0x14 + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_PAL_1_RSTMASK                                                      0xffffffff
#define SYN_PAL_1_RESET                                                        0x0

// 0x18 (SYN_VA)
#define SYN_VA_VA_HB_EN_LSB                                                    31
#define SYN_VA_VA_HB_EN_MSB                                                    31
#define SYN_VA_VA_HB_EN_MASK                                                   0x80000000
#define SYN_VA_VA_HB_EN_GET(x)                                                 (((x) & SYN_VA_VA_HB_EN_MASK) >> SYN_VA_VA_HB_EN_LSB)
#define SYN_VA_VA_HB_EN_SET(x)                                                 (((0 | (x)) << SYN_VA_VA_HB_EN_LSB) & SYN_VA_VA_HB_EN_MASK)
#define SYN_VA_VA_HB_EN_RESET                                                  0x0
#define SYN_VA_VA_LB_EN_LSB                                                    30
#define SYN_VA_VA_LB_EN_MSB                                                    30
#define SYN_VA_VA_LB_EN_MASK                                                   0x40000000
#define SYN_VA_VA_LB_EN_GET(x)                                                 (((x) & SYN_VA_VA_LB_EN_MASK) >> SYN_VA_VA_LB_EN_LSB)
#define SYN_VA_VA_LB_EN_SET(x)                                                 (((0 | (x)) << SYN_VA_VA_LB_EN_LSB) & SYN_VA_VA_LB_EN_MASK)
#define SYN_VA_VA_LB_EN_RESET                                                  0x0
#define SYN_VA_VA_START_LSB                                                    29
#define SYN_VA_VA_START_MSB                                                    29
#define SYN_VA_VA_START_MASK                                                   0x20000000
#define SYN_VA_VA_START_GET(x)                                                 (((x) & SYN_VA_VA_START_MASK) >> SYN_VA_VA_START_LSB)
#define SYN_VA_VA_START_SET(x)                                                 (((0 | (x)) << SYN_VA_VA_START_LSB) & SYN_VA_VA_START_MASK)
#define SYN_VA_VA_START_RESET                                                  0x0
#define SYN_VA_VA_BIAS_TGT_LSB                                                 24
#define SYN_VA_VA_BIAS_TGT_MSB                                                 28
#define SYN_VA_VA_BIAS_TGT_MASK                                                0x1f000000
#define SYN_VA_VA_BIAS_TGT_GET(x)                                              (((x) & SYN_VA_VA_BIAS_TGT_MASK) >> SYN_VA_VA_BIAS_TGT_LSB)
#define SYN_VA_VA_BIAS_TGT_SET(x)                                              (((0 | (x)) << SYN_VA_VA_BIAS_TGT_LSB) & SYN_VA_VA_BIAS_TGT_MASK)
#define SYN_VA_VA_BIAS_TGT_RESET                                               0x14
#define SYN_VA_VA_SETTIME_LSB                                                  22
#define SYN_VA_VA_SETTIME_MSB                                                  23
#define SYN_VA_VA_SETTIME_MASK                                                 0xc00000
#define SYN_VA_VA_SETTIME_GET(x)                                               (((x) & SYN_VA_VA_SETTIME_MASK) >> SYN_VA_VA_SETTIME_LSB)
#define SYN_VA_VA_SETTIME_SET(x)                                               (((0 | (x)) << SYN_VA_VA_SETTIME_LSB) & SYN_VA_VA_SETTIME_MASK)
#define SYN_VA_VA_SETTIME_RESET                                                0x1
#define SYN_VA_VA_SAMPLE_LSB                                                   20
#define SYN_VA_VA_SAMPLE_MSB                                                   21
#define SYN_VA_VA_SAMPLE_MASK                                                  0x300000
#define SYN_VA_VA_SAMPLE_GET(x)                                                (((x) & SYN_VA_VA_SAMPLE_MASK) >> SYN_VA_VA_SAMPLE_LSB)
#define SYN_VA_VA_SAMPLE_SET(x)                                                (((0 | (x)) << SYN_VA_VA_SAMPLE_LSB) & SYN_VA_VA_SAMPLE_MASK)
#define SYN_VA_VA_SAMPLE_RESET                                                 0x1
#define SYN_VA_VA_STEP_LSB                                                     18
#define SYN_VA_VA_STEP_MSB                                                     19
#define SYN_VA_VA_STEP_MASK                                                    0xc0000
#define SYN_VA_VA_STEP_GET(x)                                                  (((x) & SYN_VA_VA_STEP_MASK) >> SYN_VA_VA_STEP_LSB)
#define SYN_VA_VA_STEP_SET(x)                                                  (((0 | (x)) << SYN_VA_VA_STEP_LSB) & SYN_VA_VA_STEP_MASK)
#define SYN_VA_VA_STEP_RESET                                                   0x1
#define SYN_VA_RESERVED_0_LSB                                                  2
#define SYN_VA_RESERVED_0_MSB                                                  17
#define SYN_VA_RESERVED_0_MASK                                                 0x3fffc
#define SYN_VA_RESERVED_0_GET(x)                                               (((x) & SYN_VA_RESERVED_0_MASK) >> SYN_VA_RESERVED_0_LSB)
#define SYN_VA_RESERVED_0_SET(x)                                               (((0 | (x)) << SYN_VA_RESERVED_0_LSB) & SYN_VA_RESERVED_0_MASK)
#define SYN_VA_RESERVED_0_RESET                                                0x0
#define SYN_VA_EN_VCO_FREQCAL_LSB                                              0
#define SYN_VA_EN_VCO_FREQCAL_MSB                                              1
#define SYN_VA_EN_VCO_FREQCAL_MASK                                             0x3
#define SYN_VA_EN_VCO_FREQCAL_GET(x)                                           (((x) & SYN_VA_EN_VCO_FREQCAL_MASK) >> SYN_VA_EN_VCO_FREQCAL_LSB)
#define SYN_VA_EN_VCO_FREQCAL_SET(x)                                           (((0 | (x)) << SYN_VA_EN_VCO_FREQCAL_LSB) & SYN_VA_EN_VCO_FREQCAL_MASK)
#define SYN_VA_EN_VCO_FREQCAL_RESET                                            0x3
#define SYN_VA_ADDRESS                                                         (0x18 + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_VA_RSTMASK                                                         0xffffffff
#define SYN_VA_RESET                                                           0x14540003

// 0x1c (SYN_KVCO)
#define SYN_KVCO_FREQCAL_KVCO_1_LSB                                            29
#define SYN_KVCO_FREQCAL_KVCO_1_MSB                                            31
#define SYN_KVCO_FREQCAL_KVCO_1_MASK                                           0xe0000000
#define SYN_KVCO_FREQCAL_KVCO_1_GET(x)                                         (((x) & SYN_KVCO_FREQCAL_KVCO_1_MASK) >> SYN_KVCO_FREQCAL_KVCO_1_LSB)
#define SYN_KVCO_FREQCAL_KVCO_1_SET(x)                                         (((0 | (x)) << SYN_KVCO_FREQCAL_KVCO_1_LSB) & SYN_KVCO_FREQCAL_KVCO_1_MASK)
#define SYN_KVCO_FREQCAL_KVCO_1_RESET                                          0x5
#define SYN_KVCO_FREQCAL_KVCO_2_LSB                                            26
#define SYN_KVCO_FREQCAL_KVCO_2_MSB                                            28
#define SYN_KVCO_FREQCAL_KVCO_2_MASK                                           0x1c000000
#define SYN_KVCO_FREQCAL_KVCO_2_GET(x)                                         (((x) & SYN_KVCO_FREQCAL_KVCO_2_MASK) >> SYN_KVCO_FREQCAL_KVCO_2_LSB)
#define SYN_KVCO_FREQCAL_KVCO_2_SET(x)                                         (((0 | (x)) << SYN_KVCO_FREQCAL_KVCO_2_LSB) & SYN_KVCO_FREQCAL_KVCO_2_MASK)
#define SYN_KVCO_FREQCAL_KVCO_2_RESET                                          0x4
#define SYN_KVCO_FREQCAL_KVCO_3_LSB                                            23
#define SYN_KVCO_FREQCAL_KVCO_3_MSB                                            25
#define SYN_KVCO_FREQCAL_KVCO_3_MASK                                           0x3800000
#define SYN_KVCO_FREQCAL_KVCO_3_GET(x)                                         (((x) & SYN_KVCO_FREQCAL_KVCO_3_MASK) >> SYN_KVCO_FREQCAL_KVCO_3_LSB)
#define SYN_KVCO_FREQCAL_KVCO_3_SET(x)                                         (((0 | (x)) << SYN_KVCO_FREQCAL_KVCO_3_LSB) & SYN_KVCO_FREQCAL_KVCO_3_MASK)
#define SYN_KVCO_FREQCAL_KVCO_3_RESET                                          0x3
#define SYN_KVCO_FREQCAL_KVCO_4_LSB                                            20
#define SYN_KVCO_FREQCAL_KVCO_4_MSB                                            22
#define SYN_KVCO_FREQCAL_KVCO_4_MASK                                           0x700000
#define SYN_KVCO_FREQCAL_KVCO_4_GET(x)                                         (((x) & SYN_KVCO_FREQCAL_KVCO_4_MASK) >> SYN_KVCO_FREQCAL_KVCO_4_LSB)
#define SYN_KVCO_FREQCAL_KVCO_4_SET(x)                                         (((0 | (x)) << SYN_KVCO_FREQCAL_KVCO_4_LSB) & SYN_KVCO_FREQCAL_KVCO_4_MASK)
#define SYN_KVCO_FREQCAL_KVCO_4_RESET                                          0x2
#define SYN_KVCO_FREQCAL_IBIAS_1_LSB                                           15
#define SYN_KVCO_FREQCAL_IBIAS_1_MSB                                           19
#define SYN_KVCO_FREQCAL_IBIAS_1_MASK                                          0xf8000
#define SYN_KVCO_FREQCAL_IBIAS_1_GET(x)                                        (((x) & SYN_KVCO_FREQCAL_IBIAS_1_MASK) >> SYN_KVCO_FREQCAL_IBIAS_1_LSB)
#define SYN_KVCO_FREQCAL_IBIAS_1_SET(x)                                        (((0 | (x)) << SYN_KVCO_FREQCAL_IBIAS_1_LSB) & SYN_KVCO_FREQCAL_IBIAS_1_MASK)
#define SYN_KVCO_FREQCAL_IBIAS_1_RESET                                         0x10
#define SYN_KVCO_FREQCAL_IBIAS_2_LSB                                           10
#define SYN_KVCO_FREQCAL_IBIAS_2_MSB                                           14
#define SYN_KVCO_FREQCAL_IBIAS_2_MASK                                          0x7c00
#define SYN_KVCO_FREQCAL_IBIAS_2_GET(x)                                        (((x) & SYN_KVCO_FREQCAL_IBIAS_2_MASK) >> SYN_KVCO_FREQCAL_IBIAS_2_LSB)
#define SYN_KVCO_FREQCAL_IBIAS_2_SET(x)                                        (((0 | (x)) << SYN_KVCO_FREQCAL_IBIAS_2_LSB) & SYN_KVCO_FREQCAL_IBIAS_2_MASK)
#define SYN_KVCO_FREQCAL_IBIAS_2_RESET                                         0x12
#define SYN_KVCO_FREQCAL_IBIAS_3_LSB                                           5
#define SYN_KVCO_FREQCAL_IBIAS_3_MSB                                           9
#define SYN_KVCO_FREQCAL_IBIAS_3_MASK                                          0x3e0
#define SYN_KVCO_FREQCAL_IBIAS_3_GET(x)                                        (((x) & SYN_KVCO_FREQCAL_IBIAS_3_MASK) >> SYN_KVCO_FREQCAL_IBIAS_3_LSB)
#define SYN_KVCO_FREQCAL_IBIAS_3_SET(x)                                        (((0 | (x)) << SYN_KVCO_FREQCAL_IBIAS_3_LSB) & SYN_KVCO_FREQCAL_IBIAS_3_MASK)
#define SYN_KVCO_FREQCAL_IBIAS_3_RESET                                         0x14
#define SYN_KVCO_FREQCAL_IBIAS_4_LSB                                           0
#define SYN_KVCO_FREQCAL_IBIAS_4_MSB                                           4
#define SYN_KVCO_FREQCAL_IBIAS_4_MASK                                          0x1f
#define SYN_KVCO_FREQCAL_IBIAS_4_GET(x)                                        (((x) & SYN_KVCO_FREQCAL_IBIAS_4_MASK) >> SYN_KVCO_FREQCAL_IBIAS_4_LSB)
#define SYN_KVCO_FREQCAL_IBIAS_4_SET(x)                                        (((0 | (x)) << SYN_KVCO_FREQCAL_IBIAS_4_LSB) & SYN_KVCO_FREQCAL_IBIAS_4_MASK)
#define SYN_KVCO_FREQCAL_IBIAS_4_RESET                                         0x16
#define SYN_KVCO_ADDRESS                                                       (0x1c + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_KVCO_RSTMASK                                                       0xffffffff
#define SYN_KVCO_RESET                                                         0xb1a84a96

// 0x20 (SYN_CLBS_0)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET0_LSB                                      25
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET0_MSB                                      31
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET0_MASK                                     0xfe000000
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET0_GET(x)                                   (((x) & SYN_CLBS_0_CLBS_OVLAP_OFFSET0_MASK) >> SYN_CLBS_0_CLBS_OVLAP_OFFSET0_LSB)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET0_SET(x)                                   (((0 | (x)) << SYN_CLBS_0_CLBS_OVLAP_OFFSET0_LSB) & SYN_CLBS_0_CLBS_OVLAP_OFFSET0_MASK)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET0_RESET                                    0x5d
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET1_LSB                                      20
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET1_MSB                                      24
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET1_MASK                                     0x1f00000
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET1_GET(x)                                   (((x) & SYN_CLBS_0_CLBS_OVLAP_OFFSET1_MASK) >> SYN_CLBS_0_CLBS_OVLAP_OFFSET1_LSB)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET1_SET(x)                                   (((0 | (x)) << SYN_CLBS_0_CLBS_OVLAP_OFFSET1_LSB) & SYN_CLBS_0_CLBS_OVLAP_OFFSET1_MASK)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET1_RESET                                    0x19
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET2_LSB                                      15
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET2_MSB                                      19
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET2_MASK                                     0xf8000
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET2_GET(x)                                   (((x) & SYN_CLBS_0_CLBS_OVLAP_OFFSET2_MASK) >> SYN_CLBS_0_CLBS_OVLAP_OFFSET2_LSB)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET2_SET(x)                                   (((0 | (x)) << SYN_CLBS_0_CLBS_OVLAP_OFFSET2_LSB) & SYN_CLBS_0_CLBS_OVLAP_OFFSET2_MASK)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET2_RESET                                    0x14
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET3_LSB                                      10
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET3_MSB                                      14
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET3_MASK                                     0x7c00
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET3_GET(x)                                   (((x) & SYN_CLBS_0_CLBS_OVLAP_OFFSET3_MASK) >> SYN_CLBS_0_CLBS_OVLAP_OFFSET3_LSB)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET3_SET(x)                                   (((0 | (x)) << SYN_CLBS_0_CLBS_OVLAP_OFFSET3_LSB) & SYN_CLBS_0_CLBS_OVLAP_OFFSET3_MASK)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET3_RESET                                    0xb
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET4_LSB                                      5
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET4_MSB                                      9
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET4_MASK                                     0x3e0
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET4_GET(x)                                   (((x) & SYN_CLBS_0_CLBS_OVLAP_OFFSET4_MASK) >> SYN_CLBS_0_CLBS_OVLAP_OFFSET4_LSB)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET4_SET(x)                                   (((0 | (x)) << SYN_CLBS_0_CLBS_OVLAP_OFFSET4_LSB) & SYN_CLBS_0_CLBS_OVLAP_OFFSET4_MASK)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET4_RESET                                    0xd
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET5_LSB                                      0
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET5_MSB                                      4
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET5_MASK                                     0x1f
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET5_GET(x)                                   (((x) & SYN_CLBS_0_CLBS_OVLAP_OFFSET5_MASK) >> SYN_CLBS_0_CLBS_OVLAP_OFFSET5_LSB)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET5_SET(x)                                   (((0 | (x)) << SYN_CLBS_0_CLBS_OVLAP_OFFSET5_LSB) & SYN_CLBS_0_CLBS_OVLAP_OFFSET5_MASK)
#define SYN_CLBS_0_CLBS_OVLAP_OFFSET5_RESET                                    0x7
#define SYN_CLBS_0_ADDRESS                                                     (0x20 + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_CLBS_0_RSTMASK                                                     0xffffffff
#define SYN_CLBS_0_RESET                                                       0xbb9a2da7

// 0x24 (SYN_CLBS_1)
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET6_LSB                                      29
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET6_MSB                                      31
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET6_MASK                                     0xe0000000
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET6_GET(x)                                   (((x) & SYN_CLBS_1_CLBS_OVLAP_OFFSET6_MASK) >> SYN_CLBS_1_CLBS_OVLAP_OFFSET6_LSB)
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET6_SET(x)                                   (((0 | (x)) << SYN_CLBS_1_CLBS_OVLAP_OFFSET6_LSB) & SYN_CLBS_1_CLBS_OVLAP_OFFSET6_MASK)
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET6_RESET                                    0x1
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET7_LSB                                      26
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET7_MSB                                      28
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET7_MASK                                     0x1c000000
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET7_GET(x)                                   (((x) & SYN_CLBS_1_CLBS_OVLAP_OFFSET7_MASK) >> SYN_CLBS_1_CLBS_OVLAP_OFFSET7_LSB)
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET7_SET(x)                                   (((0 | (x)) << SYN_CLBS_1_CLBS_OVLAP_OFFSET7_LSB) & SYN_CLBS_1_CLBS_OVLAP_OFFSET7_MASK)
#define SYN_CLBS_1_CLBS_OVLAP_OFFSET7_RESET                                    0x1
#define SYN_CLBS_1_CLBS_START_LSB                                              25
#define SYN_CLBS_1_CLBS_START_MSB                                              25
#define SYN_CLBS_1_CLBS_START_MASK                                             0x2000000
#define SYN_CLBS_1_CLBS_START_GET(x)                                           (((x) & SYN_CLBS_1_CLBS_START_MASK) >> SYN_CLBS_1_CLBS_START_LSB)
#define SYN_CLBS_1_CLBS_START_SET(x)                                           (((0 | (x)) << SYN_CLBS_1_CLBS_START_LSB) & SYN_CLBS_1_CLBS_START_MASK)
#define SYN_CLBS_1_CLBS_START_RESET                                            0x0
#define SYN_CLBS_1_CLBS_ENABLE_LSB                                             24
#define SYN_CLBS_1_CLBS_ENABLE_MSB                                             24
#define SYN_CLBS_1_CLBS_ENABLE_MASK                                            0x1000000
#define SYN_CLBS_1_CLBS_ENABLE_GET(x)                                          (((x) & SYN_CLBS_1_CLBS_ENABLE_MASK) >> SYN_CLBS_1_CLBS_ENABLE_LSB)
#define SYN_CLBS_1_CLBS_ENABLE_SET(x)                                          (((0 | (x)) << SYN_CLBS_1_CLBS_ENABLE_LSB) & SYN_CLBS_1_CLBS_ENABLE_MASK)
#define SYN_CLBS_1_CLBS_ENABLE_RESET                                           0x1
#define SYN_CLBS_1_CLBS_MODE_LSB                                               22
#define SYN_CLBS_1_CLBS_MODE_MSB                                               23
#define SYN_CLBS_1_CLBS_MODE_MASK                                              0xc00000
#define SYN_CLBS_1_CLBS_MODE_GET(x)                                            (((x) & SYN_CLBS_1_CLBS_MODE_MASK) >> SYN_CLBS_1_CLBS_MODE_LSB)
#define SYN_CLBS_1_CLBS_MODE_SET(x)                                            (((0 | (x)) << SYN_CLBS_1_CLBS_MODE_LSB) & SYN_CLBS_1_CLBS_MODE_MASK)
#define SYN_CLBS_1_CLBS_MODE_RESET                                             0x0
#define SYN_CLBS_1_CLBS_HYBRID_BDRY_LSB                                        19
#define SYN_CLBS_1_CLBS_HYBRID_BDRY_MSB                                        21
#define SYN_CLBS_1_CLBS_HYBRID_BDRY_MASK                                       0x380000
#define SYN_CLBS_1_CLBS_HYBRID_BDRY_GET(x)                                     (((x) & SYN_CLBS_1_CLBS_HYBRID_BDRY_MASK) >> SYN_CLBS_1_CLBS_HYBRID_BDRY_LSB)
#define SYN_CLBS_1_CLBS_HYBRID_BDRY_SET(x)                                     (((0 | (x)) << SYN_CLBS_1_CLBS_HYBRID_BDRY_LSB) & SYN_CLBS_1_CLBS_HYBRID_BDRY_MASK)
#define SYN_CLBS_1_CLBS_HYBRID_BDRY_RESET                                      0x5
#define SYN_CLBS_1_CLBS_STEPSIZE_LSB                                           18
#define SYN_CLBS_1_CLBS_STEPSIZE_MSB                                           18
#define SYN_CLBS_1_CLBS_STEPSIZE_MASK                                          0x40000
#define SYN_CLBS_1_CLBS_STEPSIZE_GET(x)                                        (((x) & SYN_CLBS_1_CLBS_STEPSIZE_MASK) >> SYN_CLBS_1_CLBS_STEPSIZE_LSB)
#define SYN_CLBS_1_CLBS_STEPSIZE_SET(x)                                        (((0 | (x)) << SYN_CLBS_1_CLBS_STEPSIZE_LSB) & SYN_CLBS_1_CLBS_STEPSIZE_MASK)
#define SYN_CLBS_1_CLBS_STEPSIZE_RESET                                         0x0
#define SYN_CLBS_1_CLBS_SETTIME_LSB                                            15
#define SYN_CLBS_1_CLBS_SETTIME_MSB                                            17
#define SYN_CLBS_1_CLBS_SETTIME_MASK                                           0x38000
#define SYN_CLBS_1_CLBS_SETTIME_GET(x)                                         (((x) & SYN_CLBS_1_CLBS_SETTIME_MASK) >> SYN_CLBS_1_CLBS_SETTIME_LSB)
#define SYN_CLBS_1_CLBS_SETTIME_SET(x)                                         (((0 | (x)) << SYN_CLBS_1_CLBS_SETTIME_LSB) & SYN_CLBS_1_CLBS_SETTIME_MASK)
#define SYN_CLBS_1_CLBS_SETTIME_RESET                                          0x3
#define SYN_CLBS_1_CLBS_SAMPLE_LSB                                             12
#define SYN_CLBS_1_CLBS_SAMPLE_MSB                                             14
#define SYN_CLBS_1_CLBS_SAMPLE_MASK                                            0x7000
#define SYN_CLBS_1_CLBS_SAMPLE_GET(x)                                          (((x) & SYN_CLBS_1_CLBS_SAMPLE_MASK) >> SYN_CLBS_1_CLBS_SAMPLE_LSB)
#define SYN_CLBS_1_CLBS_SAMPLE_SET(x)                                          (((0 | (x)) << SYN_CLBS_1_CLBS_SAMPLE_LSB) & SYN_CLBS_1_CLBS_SAMPLE_MASK)
#define SYN_CLBS_1_CLBS_SAMPLE_RESET                                           0x4
#define SYN_CLBS_1_CLBS_COMP_REPEAT_LSB                                        10
#define SYN_CLBS_1_CLBS_COMP_REPEAT_MSB                                        11
#define SYN_CLBS_1_CLBS_COMP_REPEAT_MASK                                       0xc00
#define SYN_CLBS_1_CLBS_COMP_REPEAT_GET(x)                                     (((x) & SYN_CLBS_1_CLBS_COMP_REPEAT_MASK) >> SYN_CLBS_1_CLBS_COMP_REPEAT_LSB)
#define SYN_CLBS_1_CLBS_COMP_REPEAT_SET(x)                                     (((0 | (x)) << SYN_CLBS_1_CLBS_COMP_REPEAT_LSB) & SYN_CLBS_1_CLBS_COMP_REPEAT_MASK)
#define SYN_CLBS_1_CLBS_COMP_REPEAT_RESET                                      0x1
#define SYN_CLBS_1_CLBS_MASK_SEL_LSB                                           8
#define SYN_CLBS_1_CLBS_MASK_SEL_MSB                                           9
#define SYN_CLBS_1_CLBS_MASK_SEL_MASK                                          0x300
#define SYN_CLBS_1_CLBS_MASK_SEL_GET(x)                                        (((x) & SYN_CLBS_1_CLBS_MASK_SEL_MASK) >> SYN_CLBS_1_CLBS_MASK_SEL_LSB)
#define SYN_CLBS_1_CLBS_MASK_SEL_SET(x)                                        (((0 | (x)) << SYN_CLBS_1_CLBS_MASK_SEL_LSB) & SYN_CLBS_1_CLBS_MASK_SEL_MASK)
#define SYN_CLBS_1_CLBS_MASK_SEL_RESET                                         0x2
#define SYN_CLBS_1_CLBS_DLL_EN_LSB                                             7
#define SYN_CLBS_1_CLBS_DLL_EN_MSB                                             7
#define SYN_CLBS_1_CLBS_DLL_EN_MASK                                            0x80
#define SYN_CLBS_1_CLBS_DLL_EN_GET(x)                                          (((x) & SYN_CLBS_1_CLBS_DLL_EN_MASK) >> SYN_CLBS_1_CLBS_DLL_EN_LSB)
#define SYN_CLBS_1_CLBS_DLL_EN_SET(x)                                          (((0 | (x)) << SYN_CLBS_1_CLBS_DLL_EN_LSB) & SYN_CLBS_1_CLBS_DLL_EN_MASK)
#define SYN_CLBS_1_CLBS_DLL_EN_RESET                                           0x1
#define SYN_CLBS_1_CLBS_DLL_PAL_EN_LSB                                         6
#define SYN_CLBS_1_CLBS_DLL_PAL_EN_MSB                                         6
#define SYN_CLBS_1_CLBS_DLL_PAL_EN_MASK                                        0x40
#define SYN_CLBS_1_CLBS_DLL_PAL_EN_GET(x)                                      (((x) & SYN_CLBS_1_CLBS_DLL_PAL_EN_MASK) >> SYN_CLBS_1_CLBS_DLL_PAL_EN_LSB)
#define SYN_CLBS_1_CLBS_DLL_PAL_EN_SET(x)                                      (((0 | (x)) << SYN_CLBS_1_CLBS_DLL_PAL_EN_LSB) & SYN_CLBS_1_CLBS_DLL_PAL_EN_MASK)
#define SYN_CLBS_1_CLBS_DLL_PAL_EN_RESET                                       0x1
#define SYN_CLBS_1_CLBS_PAL_EN_LSB                                             5
#define SYN_CLBS_1_CLBS_PAL_EN_MSB                                             5
#define SYN_CLBS_1_CLBS_PAL_EN_MASK                                            0x20
#define SYN_CLBS_1_CLBS_PAL_EN_GET(x)                                          (((x) & SYN_CLBS_1_CLBS_PAL_EN_MASK) >> SYN_CLBS_1_CLBS_PAL_EN_LSB)
#define SYN_CLBS_1_CLBS_PAL_EN_SET(x)                                          (((0 | (x)) << SYN_CLBS_1_CLBS_PAL_EN_LSB) & SYN_CLBS_1_CLBS_PAL_EN_MASK)
#define SYN_CLBS_1_CLBS_PAL_EN_RESET                                           0x1
#define SYN_CLBS_1_RESERVED_0_LSB                                              0
#define SYN_CLBS_1_RESERVED_0_MSB                                              4
#define SYN_CLBS_1_RESERVED_0_MASK                                             0x1f
#define SYN_CLBS_1_RESERVED_0_GET(x)                                           (((x) & SYN_CLBS_1_RESERVED_0_MASK) >> SYN_CLBS_1_RESERVED_0_LSB)
#define SYN_CLBS_1_RESERVED_0_SET(x)                                           (((0 | (x)) << SYN_CLBS_1_RESERVED_0_LSB) & SYN_CLBS_1_RESERVED_0_MASK)
#define SYN_CLBS_1_RESERVED_0_RESET                                            0x0
#define SYN_CLBS_1_ADDRESS                                                     (0x24 + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_CLBS_1_RSTMASK                                                     0xffffffff
#define SYN_CLBS_1_RESET                                                       0x2529c6e0

// 0x28 (SYN_SPARE_0)
#define SYN_SPARE_0_SYN_SPARE_0_LSB                                            0
#define SYN_SPARE_0_SYN_SPARE_0_MSB                                            31
#define SYN_SPARE_0_SYN_SPARE_0_MASK                                           0xffffffff
#define SYN_SPARE_0_SYN_SPARE_0_GET(x)                                         (((x) & SYN_SPARE_0_SYN_SPARE_0_MASK) >> SYN_SPARE_0_SYN_SPARE_0_LSB)
#define SYN_SPARE_0_SYN_SPARE_0_SET(x)                                         (((0 | (x)) << SYN_SPARE_0_SYN_SPARE_0_LSB) & SYN_SPARE_0_SYN_SPARE_0_MASK)
#define SYN_SPARE_0_SYN_SPARE_0_RESET                                          0x0
#define SYN_SPARE_0_ADDRESS                                                    (0x28 + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_SPARE_0_RSTMASK                                                    0xffffffff
#define SYN_SPARE_0_RESET                                                      0x0

// 0x2c (SYN_PAL_2)
#define SYN_PAL_2_PP_PAL_START_LSB                                             31
#define SYN_PAL_2_PP_PAL_START_MSB                                             31
#define SYN_PAL_2_PP_PAL_START_MASK                                            0x80000000
#define SYN_PAL_2_PP_PAL_START_GET(x)                                          (((x) & SYN_PAL_2_PP_PAL_START_MASK) >> SYN_PAL_2_PP_PAL_START_LSB)
#define SYN_PAL_2_PP_PAL_START_SET(x)                                          (((0 | (x)) << SYN_PAL_2_PP_PAL_START_LSB) & SYN_PAL_2_PP_PAL_START_MASK)
#define SYN_PAL_2_PP_PAL_START_RESET                                           0x0
#define SYN_PAL_2_PP_PAL_DISABLE_LSB                                           30
#define SYN_PAL_2_PP_PAL_DISABLE_MSB                                           30
#define SYN_PAL_2_PP_PAL_DISABLE_MASK                                          0x40000000
#define SYN_PAL_2_PP_PAL_DISABLE_GET(x)                                        (((x) & SYN_PAL_2_PP_PAL_DISABLE_MASK) >> SYN_PAL_2_PP_PAL_DISABLE_LSB)
#define SYN_PAL_2_PP_PAL_DISABLE_SET(x)                                        (((0 | (x)) << SYN_PAL_2_PP_PAL_DISABLE_LSB) & SYN_PAL_2_PP_PAL_DISABLE_MASK)
#define SYN_PAL_2_PP_PAL_DISABLE_RESET                                         0x0
#define SYN_PAL_2_PP_PAL_COMP_REPEAT_LSB                                       29
#define SYN_PAL_2_PP_PAL_COMP_REPEAT_MSB                                       29
#define SYN_PAL_2_PP_PAL_COMP_REPEAT_MASK                                      0x20000000
#define SYN_PAL_2_PP_PAL_COMP_REPEAT_GET(x)                                    (((x) & SYN_PAL_2_PP_PAL_COMP_REPEAT_MASK) >> SYN_PAL_2_PP_PAL_COMP_REPEAT_LSB)
#define SYN_PAL_2_PP_PAL_COMP_REPEAT_SET(x)                                    (((0 | (x)) << SYN_PAL_2_PP_PAL_COMP_REPEAT_LSB) & SYN_PAL_2_PP_PAL_COMP_REPEAT_MASK)
#define SYN_PAL_2_PP_PAL_COMP_REPEAT_RESET                                     0x0
#define SYN_PAL_2_PP_PAL_COMP_START_DELAY_LSB                                  26
#define SYN_PAL_2_PP_PAL_COMP_START_DELAY_MSB                                  28
#define SYN_PAL_2_PP_PAL_COMP_START_DELAY_MASK                                 0x1c000000
#define SYN_PAL_2_PP_PAL_COMP_START_DELAY_GET(x)                               (((x) & SYN_PAL_2_PP_PAL_COMP_START_DELAY_MASK) >> SYN_PAL_2_PP_PAL_COMP_START_DELAY_LSB)
#define SYN_PAL_2_PP_PAL_COMP_START_DELAY_SET(x)                               (((0 | (x)) << SYN_PAL_2_PP_PAL_COMP_START_DELAY_LSB) & SYN_PAL_2_PP_PAL_COMP_START_DELAY_MASK)
#define SYN_PAL_2_PP_PAL_COMP_START_DELAY_RESET                                0x1
#define SYN_PAL_2_PP_PAL_COMP_DUR_LSB                                          24
#define SYN_PAL_2_PP_PAL_COMP_DUR_MSB                                          25
#define SYN_PAL_2_PP_PAL_COMP_DUR_MASK                                         0x3000000
#define SYN_PAL_2_PP_PAL_COMP_DUR_GET(x)                                       (((x) & SYN_PAL_2_PP_PAL_COMP_DUR_MASK) >> SYN_PAL_2_PP_PAL_COMP_DUR_LSB)
#define SYN_PAL_2_PP_PAL_COMP_DUR_SET(x)                                       (((0 | (x)) << SYN_PAL_2_PP_PAL_COMP_DUR_LSB) & SYN_PAL_2_PP_PAL_COMP_DUR_MASK)
#define SYN_PAL_2_PP_PAL_COMP_DUR_RESET                                        0x1
#define SYN_PAL_2_VHT160_EARLY_TIME_LSB                                        22
#define SYN_PAL_2_VHT160_EARLY_TIME_MSB                                        23
#define SYN_PAL_2_VHT160_EARLY_TIME_MASK                                       0xc00000
#define SYN_PAL_2_VHT160_EARLY_TIME_GET(x)                                     (((x) & SYN_PAL_2_VHT160_EARLY_TIME_MASK) >> SYN_PAL_2_VHT160_EARLY_TIME_LSB)
#define SYN_PAL_2_VHT160_EARLY_TIME_SET(x)                                     (((0 | (x)) << SYN_PAL_2_VHT160_EARLY_TIME_LSB) & SYN_PAL_2_VHT160_EARLY_TIME_MASK)
#define SYN_PAL_2_VHT160_EARLY_TIME_RESET                                      0x0
#define SYN_PAL_2_VHT160_MODE1_OVR_LSB                                         20
#define SYN_PAL_2_VHT160_MODE1_OVR_MSB                                         21
#define SYN_PAL_2_VHT160_MODE1_OVR_MASK                                        0x300000
#define SYN_PAL_2_VHT160_MODE1_OVR_GET(x)                                      (((x) & SYN_PAL_2_VHT160_MODE1_OVR_MASK) >> SYN_PAL_2_VHT160_MODE1_OVR_LSB)
#define SYN_PAL_2_VHT160_MODE1_OVR_SET(x)                                      (((0 | (x)) << SYN_PAL_2_VHT160_MODE1_OVR_LSB) & SYN_PAL_2_VHT160_MODE1_OVR_MASK)
#define SYN_PAL_2_VHT160_MODE1_OVR_RESET                                       0x0
#define SYN_PAL_2_VHT160_MODE0_OVR_LSB                                         18
#define SYN_PAL_2_VHT160_MODE0_OVR_MSB                                         19
#define SYN_PAL_2_VHT160_MODE0_OVR_MASK                                        0xc0000
#define SYN_PAL_2_VHT160_MODE0_OVR_GET(x)                                      (((x) & SYN_PAL_2_VHT160_MODE0_OVR_MASK) >> SYN_PAL_2_VHT160_MODE0_OVR_LSB)
#define SYN_PAL_2_VHT160_MODE0_OVR_SET(x)                                      (((0 | (x)) << SYN_PAL_2_VHT160_MODE0_OVR_LSB) & SYN_PAL_2_VHT160_MODE0_OVR_MASK)
#define SYN_PAL_2_VHT160_MODE0_OVR_RESET                                       0x0
#define SYN_PAL_2_VHT160_EN_CH3_OVR_LSB                                        16
#define SYN_PAL_2_VHT160_EN_CH3_OVR_MSB                                        17
#define SYN_PAL_2_VHT160_EN_CH3_OVR_MASK                                       0x30000
#define SYN_PAL_2_VHT160_EN_CH3_OVR_GET(x)                                     (((x) & SYN_PAL_2_VHT160_EN_CH3_OVR_MASK) >> SYN_PAL_2_VHT160_EN_CH3_OVR_LSB)
#define SYN_PAL_2_VHT160_EN_CH3_OVR_SET(x)                                     (((0 | (x)) << SYN_PAL_2_VHT160_EN_CH3_OVR_LSB) & SYN_PAL_2_VHT160_EN_CH3_OVR_MASK)
#define SYN_PAL_2_VHT160_EN_CH3_OVR_RESET                                      0x0
#define SYN_PAL_2_VHT160_EN_CH2_OVR_LSB                                        14
#define SYN_PAL_2_VHT160_EN_CH2_OVR_MSB                                        15
#define SYN_PAL_2_VHT160_EN_CH2_OVR_MASK                                       0xc000
#define SYN_PAL_2_VHT160_EN_CH2_OVR_GET(x)                                     (((x) & SYN_PAL_2_VHT160_EN_CH2_OVR_MASK) >> SYN_PAL_2_VHT160_EN_CH2_OVR_LSB)
#define SYN_PAL_2_VHT160_EN_CH2_OVR_SET(x)                                     (((0 | (x)) << SYN_PAL_2_VHT160_EN_CH2_OVR_LSB) & SYN_PAL_2_VHT160_EN_CH2_OVR_MASK)
#define SYN_PAL_2_VHT160_EN_CH2_OVR_RESET                                      0x0
#define SYN_PAL_2_PP_PAL_DISABLE_FLIP_LSB                                      13
#define SYN_PAL_2_PP_PAL_DISABLE_FLIP_MSB                                      13
#define SYN_PAL_2_PP_PAL_DISABLE_FLIP_MASK                                     0x2000
#define SYN_PAL_2_PP_PAL_DISABLE_FLIP_GET(x)                                   (((x) & SYN_PAL_2_PP_PAL_DISABLE_FLIP_MASK) >> SYN_PAL_2_PP_PAL_DISABLE_FLIP_LSB)
#define SYN_PAL_2_PP_PAL_DISABLE_FLIP_SET(x)                                   (((0 | (x)) << SYN_PAL_2_PP_PAL_DISABLE_FLIP_LSB) & SYN_PAL_2_PP_PAL_DISABLE_FLIP_MASK)
#define SYN_PAL_2_PP_PAL_DISABLE_FLIP_RESET                                    0x0
#define SYN_PAL_2_PP_PAL_BIST_EN_LSB                                           12
#define SYN_PAL_2_PP_PAL_BIST_EN_MSB                                           12
#define SYN_PAL_2_PP_PAL_BIST_EN_MASK                                          0x1000
#define SYN_PAL_2_PP_PAL_BIST_EN_GET(x)                                        (((x) & SYN_PAL_2_PP_PAL_BIST_EN_MASK) >> SYN_PAL_2_PP_PAL_BIST_EN_LSB)
#define SYN_PAL_2_PP_PAL_BIST_EN_SET(x)                                        (((0 | (x)) << SYN_PAL_2_PP_PAL_BIST_EN_LSB) & SYN_PAL_2_PP_PAL_BIST_EN_MASK)
#define SYN_PAL_2_PP_PAL_BIST_EN_RESET                                         0x0
#define SYN_PAL_2_PP_PAL_BIST_START_LSB                                        11
#define SYN_PAL_2_PP_PAL_BIST_START_MSB                                        11
#define SYN_PAL_2_PP_PAL_BIST_START_MASK                                       0x800
#define SYN_PAL_2_PP_PAL_BIST_START_GET(x)                                     (((x) & SYN_PAL_2_PP_PAL_BIST_START_MASK) >> SYN_PAL_2_PP_PAL_BIST_START_LSB)
#define SYN_PAL_2_PP_PAL_BIST_START_SET(x)                                     (((0 | (x)) << SYN_PAL_2_PP_PAL_BIST_START_LSB) & SYN_PAL_2_PP_PAL_BIST_START_MASK)
#define SYN_PAL_2_PP_PAL_BIST_START_RESET                                      0x0
#define SYN_PAL_2_PAL_BIST_EN_LSB                                              10
#define SYN_PAL_2_PAL_BIST_EN_MSB                                              10
#define SYN_PAL_2_PAL_BIST_EN_MASK                                             0x400
#define SYN_PAL_2_PAL_BIST_EN_GET(x)                                           (((x) & SYN_PAL_2_PAL_BIST_EN_MASK) >> SYN_PAL_2_PAL_BIST_EN_LSB)
#define SYN_PAL_2_PAL_BIST_EN_SET(x)                                           (((0 | (x)) << SYN_PAL_2_PAL_BIST_EN_LSB) & SYN_PAL_2_PAL_BIST_EN_MASK)
#define SYN_PAL_2_PAL_BIST_EN_RESET                                            0x0
#define SYN_PAL_2_PAL_BIST_START_LSB                                           9
#define SYN_PAL_2_PAL_BIST_START_MSB                                           9
#define SYN_PAL_2_PAL_BIST_START_MASK                                          0x200
#define SYN_PAL_2_PAL_BIST_START_GET(x)                                        (((x) & SYN_PAL_2_PAL_BIST_START_MASK) >> SYN_PAL_2_PAL_BIST_START_LSB)
#define SYN_PAL_2_PAL_BIST_START_SET(x)                                        (((0 | (x)) << SYN_PAL_2_PAL_BIST_START_LSB) & SYN_PAL_2_PAL_BIST_START_MASK)
#define SYN_PAL_2_PAL_BIST_START_RESET                                         0x0
#define SYN_PAL_2_PAL_EN_ON_BS_LSB                                             8
#define SYN_PAL_2_PAL_EN_ON_BS_MSB                                             8
#define SYN_PAL_2_PAL_EN_ON_BS_MASK                                            0x100
#define SYN_PAL_2_PAL_EN_ON_BS_GET(x)                                          (((x) & SYN_PAL_2_PAL_EN_ON_BS_MASK) >> SYN_PAL_2_PAL_EN_ON_BS_LSB)
#define SYN_PAL_2_PAL_EN_ON_BS_SET(x)                                          (((0 | (x)) << SYN_PAL_2_PAL_EN_ON_BS_LSB) & SYN_PAL_2_PAL_EN_ON_BS_MASK)
#define SYN_PAL_2_PAL_EN_ON_BS_RESET                                           0x0
#define SYN_PAL_2_NPATH_BPF_BWSEL_LSB                                          6
#define SYN_PAL_2_NPATH_BPF_BWSEL_MSB                                          7
#define SYN_PAL_2_NPATH_BPF_BWSEL_MASK                                         0xc0
#define SYN_PAL_2_NPATH_BPF_BWSEL_GET(x)                                       (((x) & SYN_PAL_2_NPATH_BPF_BWSEL_MASK) >> SYN_PAL_2_NPATH_BPF_BWSEL_LSB)
#define SYN_PAL_2_NPATH_BPF_BWSEL_SET(x)                                       (((0 | (x)) << SYN_PAL_2_NPATH_BPF_BWSEL_LSB) & SYN_PAL_2_NPATH_BPF_BWSEL_MASK)
#define SYN_PAL_2_NPATH_BPF_BWSEL_RESET                                        0x0
#define SYN_PAL_2_NPATH_BPF_EN_LSB                                             5
#define SYN_PAL_2_NPATH_BPF_EN_MSB                                             5
#define SYN_PAL_2_NPATH_BPF_EN_MASK                                            0x20
#define SYN_PAL_2_NPATH_BPF_EN_GET(x)                                          (((x) & SYN_PAL_2_NPATH_BPF_EN_MASK) >> SYN_PAL_2_NPATH_BPF_EN_LSB)
#define SYN_PAL_2_NPATH_BPF_EN_SET(x)                                          (((0 | (x)) << SYN_PAL_2_NPATH_BPF_EN_LSB) & SYN_PAL_2_NPATH_BPF_EN_MASK)
#define SYN_PAL_2_NPATH_BPF_EN_RESET                                           0x0
#define SYN_PAL_2_XORCVR_EN_DBLER_SEC_LSB                                      4
#define SYN_PAL_2_XORCVR_EN_DBLER_SEC_MSB                                      4
#define SYN_PAL_2_XORCVR_EN_DBLER_SEC_MASK                                     0x10
#define SYN_PAL_2_XORCVR_EN_DBLER_SEC_GET(x)                                   (((x) & SYN_PAL_2_XORCVR_EN_DBLER_SEC_MASK) >> SYN_PAL_2_XORCVR_EN_DBLER_SEC_LSB)
#define SYN_PAL_2_XORCVR_EN_DBLER_SEC_SET(x)                                   (((0 | (x)) << SYN_PAL_2_XORCVR_EN_DBLER_SEC_LSB) & SYN_PAL_2_XORCVR_EN_DBLER_SEC_MASK)
#define SYN_PAL_2_XORCVR_EN_DBLER_SEC_RESET                                    0x0
#define SYN_PAL_2_XORCVR_DRV_SYN_ACLK_LSB                                      2
#define SYN_PAL_2_XORCVR_DRV_SYN_ACLK_MSB                                      3
#define SYN_PAL_2_XORCVR_DRV_SYN_ACLK_MASK                                     0xc
#define SYN_PAL_2_XORCVR_DRV_SYN_ACLK_GET(x)                                   (((x) & SYN_PAL_2_XORCVR_DRV_SYN_ACLK_MASK) >> SYN_PAL_2_XORCVR_DRV_SYN_ACLK_LSB)
#define SYN_PAL_2_XORCVR_DRV_SYN_ACLK_SET(x)                                   (((0 | (x)) << SYN_PAL_2_XORCVR_DRV_SYN_ACLK_LSB) & SYN_PAL_2_XORCVR_DRV_SYN_ACLK_MASK)
#define SYN_PAL_2_XORCVR_DRV_SYN_ACLK_RESET                                    0x0
#define SYN_PAL_2_XORCVR_DRV_SYN_DCLK_LSB                                      0
#define SYN_PAL_2_XORCVR_DRV_SYN_DCLK_MSB                                      1
#define SYN_PAL_2_XORCVR_DRV_SYN_DCLK_MASK                                     0x3
#define SYN_PAL_2_XORCVR_DRV_SYN_DCLK_GET(x)                                   (((x) & SYN_PAL_2_XORCVR_DRV_SYN_DCLK_MASK) >> SYN_PAL_2_XORCVR_DRV_SYN_DCLK_LSB)
#define SYN_PAL_2_XORCVR_DRV_SYN_DCLK_SET(x)                                   (((0 | (x)) << SYN_PAL_2_XORCVR_DRV_SYN_DCLK_LSB) & SYN_PAL_2_XORCVR_DRV_SYN_DCLK_MASK)
#define SYN_PAL_2_XORCVR_DRV_SYN_DCLK_RESET                                    0x0
#define SYN_PAL_2_ADDRESS                                                      (0x2c + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_PAL_2_RSTMASK                                                      0xffffffff
#define SYN_PAL_2_RESET                                                        0x5000000

// 0x30 (SYN_PAL_3)
#define SYN_PAL_3_PAL_DIV2FLIP_MDIV_START_LSB                                  28
#define SYN_PAL_3_PAL_DIV2FLIP_MDIV_START_MSB                                  31
#define SYN_PAL_3_PAL_DIV2FLIP_MDIV_START_MASK                                 0xf0000000
#define SYN_PAL_3_PAL_DIV2FLIP_MDIV_START_GET(x)                               (((x) & SYN_PAL_3_PAL_DIV2FLIP_MDIV_START_MASK) >> SYN_PAL_3_PAL_DIV2FLIP_MDIV_START_LSB)
#define SYN_PAL_3_PAL_DIV2FLIP_MDIV_START_SET(x)                               (((0 | (x)) << SYN_PAL_3_PAL_DIV2FLIP_MDIV_START_LSB) & SYN_PAL_3_PAL_DIV2FLIP_MDIV_START_MASK)
#define SYN_PAL_3_PAL_DIV2FLIP_MDIV_START_RESET                                0x0
#define SYN_PAL_3_PAL_DIV2FLIP_RXDIV_START_LSB                                 24
#define SYN_PAL_3_PAL_DIV2FLIP_RXDIV_START_MSB                                 27
#define SYN_PAL_3_PAL_DIV2FLIP_RXDIV_START_MASK                                0xf000000
#define SYN_PAL_3_PAL_DIV2FLIP_RXDIV_START_GET(x)                              (((x) & SYN_PAL_3_PAL_DIV2FLIP_RXDIV_START_MASK) >> SYN_PAL_3_PAL_DIV2FLIP_RXDIV_START_LSB)
#define SYN_PAL_3_PAL_DIV2FLIP_RXDIV_START_SET(x)                              (((0 | (x)) << SYN_PAL_3_PAL_DIV2FLIP_RXDIV_START_LSB) & SYN_PAL_3_PAL_DIV2FLIP_RXDIV_START_MASK)
#define SYN_PAL_3_PAL_DIV2FLIP_RXDIV_START_RESET                               0x0
#define SYN_PAL_3_PAL_DIV2FLIP_TXDIV_START_LSB                                 20
#define SYN_PAL_3_PAL_DIV2FLIP_TXDIV_START_MSB                                 23
#define SYN_PAL_3_PAL_DIV2FLIP_TXDIV_START_MASK                                0xf00000
#define SYN_PAL_3_PAL_DIV2FLIP_TXDIV_START_GET(x)                              (((x) & SYN_PAL_3_PAL_DIV2FLIP_TXDIV_START_MASK) >> SYN_PAL_3_PAL_DIV2FLIP_TXDIV_START_LSB)
#define SYN_PAL_3_PAL_DIV2FLIP_TXDIV_START_SET(x)                              (((0 | (x)) << SYN_PAL_3_PAL_DIV2FLIP_TXDIV_START_LSB) & SYN_PAL_3_PAL_DIV2FLIP_TXDIV_START_MASK)
#define SYN_PAL_3_PAL_DIV2FLIP_TXDIV_START_RESET                               0x0
#define SYN_PAL_3_PAL_DIV2FLIP_EN_OVR_LSB                                      18
#define SYN_PAL_3_PAL_DIV2FLIP_EN_OVR_MSB                                      19
#define SYN_PAL_3_PAL_DIV2FLIP_EN_OVR_MASK                                     0xc0000
#define SYN_PAL_3_PAL_DIV2FLIP_EN_OVR_GET(x)                                   (((x) & SYN_PAL_3_PAL_DIV2FLIP_EN_OVR_MASK) >> SYN_PAL_3_PAL_DIV2FLIP_EN_OVR_LSB)
#define SYN_PAL_3_PAL_DIV2FLIP_EN_OVR_SET(x)                                   (((0 | (x)) << SYN_PAL_3_PAL_DIV2FLIP_EN_OVR_LSB) & SYN_PAL_3_PAL_DIV2FLIP_EN_OVR_MASK)
#define SYN_PAL_3_PAL_DIV2FLIP_EN_OVR_RESET                                    0x0
#define SYN_PAL_3_RESERVED_0_LSB                                               0
#define SYN_PAL_3_RESERVED_0_MSB                                               17
#define SYN_PAL_3_RESERVED_0_MASK                                              0x3ffff
#define SYN_PAL_3_RESERVED_0_GET(x)                                            (((x) & SYN_PAL_3_RESERVED_0_MASK) >> SYN_PAL_3_RESERVED_0_LSB)
#define SYN_PAL_3_RESERVED_0_SET(x)                                            (((0 | (x)) << SYN_PAL_3_RESERVED_0_LSB) & SYN_PAL_3_RESERVED_0_MASK)
#define SYN_PAL_3_RESERVED_0_RESET                                             0x0
#define SYN_PAL_3_ADDRESS                                                      (0x30 + __SYN_1_REG_CSR_BASE_ADDRESS)
#define SYN_PAL_3_RSTMASK                                                      0xffffffff
#define SYN_PAL_3_RESET                                                        0x0



#endif /* _SYN_1_REG_CSR_H_ */
