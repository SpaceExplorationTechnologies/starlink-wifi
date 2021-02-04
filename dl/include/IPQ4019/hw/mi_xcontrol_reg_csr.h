/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _MI_XCONTROL_REG_CSR_H_
#define _MI_XCONTROL_REG_CSR_H_


#ifndef __MI_XCONTROL_REG_CSR_BASE_ADDRESS
#define __MI_XCONTROL_REG_CSR_BASE_ADDRESS (0x49380)
#endif


// 0x0 (XCTRL_0)
#define XCTRL_0_XCTRL_EN_BIAS_LSB                                              31
#define XCTRL_0_XCTRL_EN_BIAS_MSB                                              31
#define XCTRL_0_XCTRL_EN_BIAS_MASK                                             0x80000000
#define XCTRL_0_XCTRL_EN_BIAS_GET(x)                                           (((x) & XCTRL_0_XCTRL_EN_BIAS_MASK) >> XCTRL_0_XCTRL_EN_BIAS_LSB)
#define XCTRL_0_XCTRL_EN_BIAS_SET(x)                                           (((0 | (x)) << XCTRL_0_XCTRL_EN_BIAS_LSB) & XCTRL_0_XCTRL_EN_BIAS_MASK)
#define XCTRL_0_XCTRL_EN_BIAS_RESET                                            0x0
#define XCTRL_0_XCTRL_ISEL_IC_LSB                                              28
#define XCTRL_0_XCTRL_ISEL_IC_MSB                                              30
#define XCTRL_0_XCTRL_ISEL_IC_MASK                                             0x70000000
#define XCTRL_0_XCTRL_ISEL_IC_GET(x)                                           (((x) & XCTRL_0_XCTRL_ISEL_IC_MASK) >> XCTRL_0_XCTRL_ISEL_IC_LSB)
#define XCTRL_0_XCTRL_ISEL_IC_SET(x)                                           (((0 | (x)) << XCTRL_0_XCTRL_ISEL_IC_LSB) & XCTRL_0_XCTRL_ISEL_IC_MASK)
#define XCTRL_0_XCTRL_ISEL_IC_RESET                                            0x3
#define XCTRL_0_XCTRL_ISEL_IR_LSB                                              25
#define XCTRL_0_XCTRL_ISEL_IR_MSB                                              27
#define XCTRL_0_XCTRL_ISEL_IR_MASK                                             0xe000000
#define XCTRL_0_XCTRL_ISEL_IR_GET(x)                                           (((x) & XCTRL_0_XCTRL_ISEL_IR_MASK) >> XCTRL_0_XCTRL_ISEL_IR_LSB)
#define XCTRL_0_XCTRL_ISEL_IR_SET(x)                                           (((0 | (x)) << XCTRL_0_XCTRL_ISEL_IR_LSB) & XCTRL_0_XCTRL_ISEL_IR_MASK)
#define XCTRL_0_XCTRL_ISEL_IR_RESET                                            0x3
#define XCTRL_0_ISEL_IC25_XPA0_LSB                                             22
#define XCTRL_0_ISEL_IC25_XPA0_MSB                                             24
#define XCTRL_0_ISEL_IC25_XPA0_MASK                                            0x1c00000
#define XCTRL_0_ISEL_IC25_XPA0_GET(x)                                          (((x) & XCTRL_0_ISEL_IC25_XPA0_MASK) >> XCTRL_0_ISEL_IC25_XPA0_LSB)
#define XCTRL_0_ISEL_IC25_XPA0_SET(x)                                          (((0 | (x)) << XCTRL_0_ISEL_IC25_XPA0_LSB) & XCTRL_0_ISEL_IC25_XPA0_MASK)
#define XCTRL_0_ISEL_IC25_XPA0_RESET                                           0x3
#define XCTRL_0_ISEL_IC25_XPA1_LSB                                             19
#define XCTRL_0_ISEL_IC25_XPA1_MSB                                             21
#define XCTRL_0_ISEL_IC25_XPA1_MASK                                            0x380000
#define XCTRL_0_ISEL_IC25_XPA1_GET(x)                                          (((x) & XCTRL_0_ISEL_IC25_XPA1_MASK) >> XCTRL_0_ISEL_IC25_XPA1_LSB)
#define XCTRL_0_ISEL_IC25_XPA1_SET(x)                                          (((0 | (x)) << XCTRL_0_ISEL_IC25_XPA1_LSB) & XCTRL_0_ISEL_IC25_XPA1_MASK)
#define XCTRL_0_ISEL_IC25_XPA1_RESET                                           0x3
#define XCTRL_0_ISEL_IC25_XPA2_LSB                                             16
#define XCTRL_0_ISEL_IC25_XPA2_MSB                                             18
#define XCTRL_0_ISEL_IC25_XPA2_MASK                                            0x70000
#define XCTRL_0_ISEL_IC25_XPA2_GET(x)                                          (((x) & XCTRL_0_ISEL_IC25_XPA2_MASK) >> XCTRL_0_ISEL_IC25_XPA2_LSB)
#define XCTRL_0_ISEL_IC25_XPA2_SET(x)                                          (((0 | (x)) << XCTRL_0_ISEL_IC25_XPA2_LSB) & XCTRL_0_ISEL_IC25_XPA2_MASK)
#define XCTRL_0_ISEL_IC25_XPA2_RESET                                           0x3
#define XCTRL_0_ISEL_IC25_XPA3_LSB                                             13
#define XCTRL_0_ISEL_IC25_XPA3_MSB                                             15
#define XCTRL_0_ISEL_IC25_XPA3_MASK                                            0xe000
#define XCTRL_0_ISEL_IC25_XPA3_GET(x)                                          (((x) & XCTRL_0_ISEL_IC25_XPA3_MASK) >> XCTRL_0_ISEL_IC25_XPA3_LSB)
#define XCTRL_0_ISEL_IC25_XPA3_SET(x)                                          (((0 | (x)) << XCTRL_0_ISEL_IC25_XPA3_LSB) & XCTRL_0_ISEL_IC25_XPA3_MASK)
#define XCTRL_0_ISEL_IC25_XPA3_RESET                                           0x3
#define XCTRL_0_ISEL_IR25_XPA0_LSB                                             10
#define XCTRL_0_ISEL_IR25_XPA0_MSB                                             12
#define XCTRL_0_ISEL_IR25_XPA0_MASK                                            0x1c00
#define XCTRL_0_ISEL_IR25_XPA0_GET(x)                                          (((x) & XCTRL_0_ISEL_IR25_XPA0_MASK) >> XCTRL_0_ISEL_IR25_XPA0_LSB)
#define XCTRL_0_ISEL_IR25_XPA0_SET(x)                                          (((0 | (x)) << XCTRL_0_ISEL_IR25_XPA0_LSB) & XCTRL_0_ISEL_IR25_XPA0_MASK)
#define XCTRL_0_ISEL_IR25_XPA0_RESET                                           0x3
#define XCTRL_0_ISEL_IR25_XPA1_LSB                                             7
#define XCTRL_0_ISEL_IR25_XPA1_MSB                                             9
#define XCTRL_0_ISEL_IR25_XPA1_MASK                                            0x380
#define XCTRL_0_ISEL_IR25_XPA1_GET(x)                                          (((x) & XCTRL_0_ISEL_IR25_XPA1_MASK) >> XCTRL_0_ISEL_IR25_XPA1_LSB)
#define XCTRL_0_ISEL_IR25_XPA1_SET(x)                                          (((0 | (x)) << XCTRL_0_ISEL_IR25_XPA1_LSB) & XCTRL_0_ISEL_IR25_XPA1_MASK)
#define XCTRL_0_ISEL_IR25_XPA1_RESET                                           0x3
#define XCTRL_0_ISEL_IR25_XPA2_LSB                                             4
#define XCTRL_0_ISEL_IR25_XPA2_MSB                                             6
#define XCTRL_0_ISEL_IR25_XPA2_MASK                                            0x70
#define XCTRL_0_ISEL_IR25_XPA2_GET(x)                                          (((x) & XCTRL_0_ISEL_IR25_XPA2_MASK) >> XCTRL_0_ISEL_IR25_XPA2_LSB)
#define XCTRL_0_ISEL_IR25_XPA2_SET(x)                                          (((0 | (x)) << XCTRL_0_ISEL_IR25_XPA2_LSB) & XCTRL_0_ISEL_IR25_XPA2_MASK)
#define XCTRL_0_ISEL_IR25_XPA2_RESET                                           0x3
#define XCTRL_0_ISEL_IR25_XPA3_LSB                                             1
#define XCTRL_0_ISEL_IR25_XPA3_MSB                                             3
#define XCTRL_0_ISEL_IR25_XPA3_MASK                                            0xe
#define XCTRL_0_ISEL_IR25_XPA3_GET(x)                                          (((x) & XCTRL_0_ISEL_IR25_XPA3_MASK) >> XCTRL_0_ISEL_IR25_XPA3_LSB)
#define XCTRL_0_ISEL_IR25_XPA3_SET(x)                                          (((0 | (x)) << XCTRL_0_ISEL_IR25_XPA3_LSB) & XCTRL_0_ISEL_IR25_XPA3_MASK)
#define XCTRL_0_ISEL_IR25_XPA3_RESET                                           0x3
#define XCTRL_0_RESERVED_0_LSB                                                 0
#define XCTRL_0_RESERVED_0_MSB                                                 0
#define XCTRL_0_RESERVED_0_MASK                                                0x1
#define XCTRL_0_RESERVED_0_GET(x)                                              (((x) & XCTRL_0_RESERVED_0_MASK) >> XCTRL_0_RESERVED_0_LSB)
#define XCTRL_0_RESERVED_0_SET(x)                                              (((0 | (x)) << XCTRL_0_RESERVED_0_LSB) & XCTRL_0_RESERVED_0_MASK)
#define XCTRL_0_RESERVED_0_RESET                                               0x0
#define XCTRL_0_ADDRESS                                                        (0x0 + __MI_XCONTROL_REG_CSR_BASE_ADDRESS)
#define XCTRL_0_RSTMASK                                                        0xffffffff
#define XCTRL_0_RESET                                                          0x36db6db6

// 0x4 (XCTRL_1)
#define XCTRL_1_XPA_MODE_LSB                                                   28
#define XCTRL_1_XPA_MODE_MSB                                                   31
#define XCTRL_1_XPA_MODE_MASK                                                  0xf0000000
#define XCTRL_1_XPA_MODE_GET(x)                                                (((x) & XCTRL_1_XPA_MODE_MASK) >> XCTRL_1_XPA_MODE_LSB)
#define XCTRL_1_XPA_MODE_SET(x)                                                (((0 | (x)) << XCTRL_1_XPA_MODE_LSB) & XCTRL_1_XPA_MODE_MASK)
#define XCTRL_1_XPA_MODE_RESET                                                 0xf
#define XCTRL_1_XPA_PULLDOWN_LSB                                               24
#define XCTRL_1_XPA_PULLDOWN_MSB                                               27
#define XCTRL_1_XPA_PULLDOWN_MASK                                              0xf000000
#define XCTRL_1_XPA_PULLDOWN_GET(x)                                            (((x) & XCTRL_1_XPA_PULLDOWN_MASK) >> XCTRL_1_XPA_PULLDOWN_LSB)
#define XCTRL_1_XPA_PULLDOWN_SET(x)                                            (((0 | (x)) << XCTRL_1_XPA_PULLDOWN_LSB) & XCTRL_1_XPA_PULLDOWN_MASK)
#define XCTRL_1_XPA_PULLDOWN_RESET                                             0x0
#define XCTRL_1_XPABIASLVL0_LSB                                                20
#define XCTRL_1_XPABIASLVL0_MSB                                                23
#define XCTRL_1_XPABIASLVL0_MASK                                               0xf00000
#define XCTRL_1_XPABIASLVL0_GET(x)                                             (((x) & XCTRL_1_XPABIASLVL0_MASK) >> XCTRL_1_XPABIASLVL0_LSB)
#define XCTRL_1_XPABIASLVL0_SET(x)                                             (((0 | (x)) << XCTRL_1_XPABIASLVL0_LSB) & XCTRL_1_XPABIASLVL0_MASK)
#define XCTRL_1_XPABIASLVL0_RESET                                              0xf
#define XCTRL_1_XPABIASLVL1_LSB                                                16
#define XCTRL_1_XPABIASLVL1_MSB                                                19
#define XCTRL_1_XPABIASLVL1_MASK                                               0xf0000
#define XCTRL_1_XPABIASLVL1_GET(x)                                             (((x) & XCTRL_1_XPABIASLVL1_MASK) >> XCTRL_1_XPABIASLVL1_LSB)
#define XCTRL_1_XPABIASLVL1_SET(x)                                             (((0 | (x)) << XCTRL_1_XPABIASLVL1_LSB) & XCTRL_1_XPABIASLVL1_MASK)
#define XCTRL_1_XPABIASLVL1_RESET                                              0xf
#define XCTRL_1_XPABIASLVL2_LSB                                                12
#define XCTRL_1_XPABIASLVL2_MSB                                                15
#define XCTRL_1_XPABIASLVL2_MASK                                               0xf000
#define XCTRL_1_XPABIASLVL2_GET(x)                                             (((x) & XCTRL_1_XPABIASLVL2_MASK) >> XCTRL_1_XPABIASLVL2_LSB)
#define XCTRL_1_XPABIASLVL2_SET(x)                                             (((0 | (x)) << XCTRL_1_XPABIASLVL2_LSB) & XCTRL_1_XPABIASLVL2_MASK)
#define XCTRL_1_XPABIASLVL2_RESET                                              0xf
#define XCTRL_1_XPABIASLVL3_LSB                                                8
#define XCTRL_1_XPABIASLVL3_MSB                                                11
#define XCTRL_1_XPABIASLVL3_MASK                                               0xf00
#define XCTRL_1_XPABIASLVL3_GET(x)                                             (((x) & XCTRL_1_XPABIASLVL3_MASK) >> XCTRL_1_XPABIASLVL3_LSB)
#define XCTRL_1_XPABIASLVL3_SET(x)                                             (((0 | (x)) << XCTRL_1_XPABIASLVL3_LSB) & XCTRL_1_XPABIASLVL3_MASK)
#define XCTRL_1_XPABIASLVL3_RESET                                              0xf
#define XCTRL_1_XPA_TESTBUF_CTRL_LSB                                           5
#define XCTRL_1_XPA_TESTBUF_CTRL_MSB                                           7
#define XCTRL_1_XPA_TESTBUF_CTRL_MASK                                          0xe0
#define XCTRL_1_XPA_TESTBUF_CTRL_GET(x)                                        (((x) & XCTRL_1_XPA_TESTBUF_CTRL_MASK) >> XCTRL_1_XPA_TESTBUF_CTRL_LSB)
#define XCTRL_1_XPA_TESTBUF_CTRL_SET(x)                                        (((0 | (x)) << XCTRL_1_XPA_TESTBUF_CTRL_LSB) & XCTRL_1_XPA_TESTBUF_CTRL_MASK)
#define XCTRL_1_XPA_TESTBUF_CTRL_RESET                                         0x1
#define XCTRL_1_RESERVED_0_LSB                                                 0
#define XCTRL_1_RESERVED_0_MSB                                                 4
#define XCTRL_1_RESERVED_0_MASK                                                0x1f
#define XCTRL_1_RESERVED_0_GET(x)                                              (((x) & XCTRL_1_RESERVED_0_MASK) >> XCTRL_1_RESERVED_0_LSB)
#define XCTRL_1_RESERVED_0_SET(x)                                              (((0 | (x)) << XCTRL_1_RESERVED_0_LSB) & XCTRL_1_RESERVED_0_MASK)
#define XCTRL_1_RESERVED_0_RESET                                               0x0
#define XCTRL_1_ADDRESS                                                        (0x4 + __MI_XCONTROL_REG_CSR_BASE_ADDRESS)
#define XCTRL_1_RSTMASK                                                        0xffffffff
#define XCTRL_1_RESET                                                          0xf0ffff20

// 0x8 (XCTRL_2)
#define XCTRL_2_XLNA2_OE_LS_LSB                                                28
#define XCTRL_2_XLNA2_OE_LS_MSB                                                31
#define XCTRL_2_XLNA2_OE_LS_MASK                                               0xf0000000
#define XCTRL_2_XLNA2_OE_LS_GET(x)                                             (((x) & XCTRL_2_XLNA2_OE_LS_MASK) >> XCTRL_2_XLNA2_OE_LS_LSB)
#define XCTRL_2_XLNA2_OE_LS_SET(x)                                             (((0 | (x)) << XCTRL_2_XLNA2_OE_LS_LSB) & XCTRL_2_XLNA2_OE_LS_MASK)
#define XCTRL_2_XLNA2_OE_LS_RESET                                              0x0
#define XCTRL_2_XLNA5_OE_LS_LSB                                                24
#define XCTRL_2_XLNA5_OE_LS_MSB                                                27
#define XCTRL_2_XLNA5_OE_LS_MASK                                               0xf000000
#define XCTRL_2_XLNA5_OE_LS_GET(x)                                             (((x) & XCTRL_2_XLNA5_OE_LS_MASK) >> XCTRL_2_XLNA5_OE_LS_LSB)
#define XCTRL_2_XLNA5_OE_LS_SET(x)                                             (((0 | (x)) << XCTRL_2_XLNA5_OE_LS_LSB) & XCTRL_2_XLNA5_OE_LS_MASK)
#define XCTRL_2_XLNA5_OE_LS_RESET                                              0x0
#define XCTRL_2_XLNA2_OE_OVR_EN_LSB                                            23
#define XCTRL_2_XLNA2_OE_OVR_EN_MSB                                            23
#define XCTRL_2_XLNA2_OE_OVR_EN_MASK                                           0x800000
#define XCTRL_2_XLNA2_OE_OVR_EN_GET(x)                                         (((x) & XCTRL_2_XLNA2_OE_OVR_EN_MASK) >> XCTRL_2_XLNA2_OE_OVR_EN_LSB)
#define XCTRL_2_XLNA2_OE_OVR_EN_SET(x)                                         (((0 | (x)) << XCTRL_2_XLNA2_OE_OVR_EN_LSB) & XCTRL_2_XLNA2_OE_OVR_EN_MASK)
#define XCTRL_2_XLNA2_OE_OVR_EN_RESET                                          0x0
#define XCTRL_2_XLNA5_OE_OVR_EN_LSB                                            22
#define XCTRL_2_XLNA5_OE_OVR_EN_MSB                                            22
#define XCTRL_2_XLNA5_OE_OVR_EN_MASK                                           0x400000
#define XCTRL_2_XLNA5_OE_OVR_EN_GET(x)                                         (((x) & XCTRL_2_XLNA5_OE_OVR_EN_MASK) >> XCTRL_2_XLNA5_OE_OVR_EN_LSB)
#define XCTRL_2_XLNA5_OE_OVR_EN_SET(x)                                         (((0 | (x)) << XCTRL_2_XLNA5_OE_OVR_EN_LSB) & XCTRL_2_XLNA5_OE_OVR_EN_MASK)
#define XCTRL_2_XLNA5_OE_OVR_EN_RESET                                          0x0
#define XCTRL_2_XLNA_MODE_LSB                                                  21
#define XCTRL_2_XLNA_MODE_MSB                                                  21
#define XCTRL_2_XLNA_MODE_MASK                                                 0x200000
#define XCTRL_2_XLNA_MODE_GET(x)                                               (((x) & XCTRL_2_XLNA_MODE_MASK) >> XCTRL_2_XLNA_MODE_LSB)
#define XCTRL_2_XLNA_MODE_SET(x)                                               (((0 | (x)) << XCTRL_2_XLNA_MODE_LSB) & XCTRL_2_XLNA_MODE_MASK)
#define XCTRL_2_XLNA_MODE_RESET                                                0x1
#define XCTRL_2_XLNA2_ATB_MODE_LSB                                             20
#define XCTRL_2_XLNA2_ATB_MODE_MSB                                             20
#define XCTRL_2_XLNA2_ATB_MODE_MASK                                            0x100000
#define XCTRL_2_XLNA2_ATB_MODE_GET(x)                                          (((x) & XCTRL_2_XLNA2_ATB_MODE_MASK) >> XCTRL_2_XLNA2_ATB_MODE_LSB)
#define XCTRL_2_XLNA2_ATB_MODE_SET(x)                                          (((0 | (x)) << XCTRL_2_XLNA2_ATB_MODE_LSB) & XCTRL_2_XLNA2_ATB_MODE_MASK)
#define XCTRL_2_XLNA2_ATB_MODE_RESET                                           0x0
#define XCTRL_2_XLNA5_ATB_MODE_LSB                                             19
#define XCTRL_2_XLNA5_ATB_MODE_MSB                                             19
#define XCTRL_2_XLNA5_ATB_MODE_MASK                                            0x80000
#define XCTRL_2_XLNA5_ATB_MODE_GET(x)                                          (((x) & XCTRL_2_XLNA5_ATB_MODE_MASK) >> XCTRL_2_XLNA5_ATB_MODE_LSB)
#define XCTRL_2_XLNA5_ATB_MODE_SET(x)                                          (((0 | (x)) << XCTRL_2_XLNA5_ATB_MODE_LSB) & XCTRL_2_XLNA5_ATB_MODE_MASK)
#define XCTRL_2_XLNA5_ATB_MODE_RESET                                           0x0
#define XCTRL_2_XLNA_INT2GND_OVR_LSB                                           17
#define XCTRL_2_XLNA_INT2GND_OVR_MSB                                           18
#define XCTRL_2_XLNA_INT2GND_OVR_MASK                                          0x60000
#define XCTRL_2_XLNA_INT2GND_OVR_GET(x)                                        (((x) & XCTRL_2_XLNA_INT2GND_OVR_MASK) >> XCTRL_2_XLNA_INT2GND_OVR_LSB)
#define XCTRL_2_XLNA_INT2GND_OVR_SET(x)                                        (((0 | (x)) << XCTRL_2_XLNA_INT2GND_OVR_LSB) & XCTRL_2_XLNA_INT2GND_OVR_MASK)
#define XCTRL_2_XLNA_INT2GND_OVR_RESET                                         0x0
#define XCTRL_2_RESERVED_0_LSB                                                 0
#define XCTRL_2_RESERVED_0_MSB                                                 16
#define XCTRL_2_RESERVED_0_MASK                                                0x1ffff
#define XCTRL_2_RESERVED_0_GET(x)                                              (((x) & XCTRL_2_RESERVED_0_MASK) >> XCTRL_2_RESERVED_0_LSB)
#define XCTRL_2_RESERVED_0_SET(x)                                              (((0 | (x)) << XCTRL_2_RESERVED_0_LSB) & XCTRL_2_RESERVED_0_MASK)
#define XCTRL_2_RESERVED_0_RESET                                               0x0
#define XCTRL_2_ADDRESS                                                        (0x8 + __MI_XCONTROL_REG_CSR_BASE_ADDRESS)
#define XCTRL_2_RSTMASK                                                        0xffffffff
#define XCTRL_2_RESET                                                          0x200000

// 0xc (XCTRL_3)
#define XCTRL_3_XLNA2_ON0_OVR_LSB                                              30
#define XCTRL_3_XLNA2_ON0_OVR_MSB                                              31
#define XCTRL_3_XLNA2_ON0_OVR_MASK                                             0xc0000000
#define XCTRL_3_XLNA2_ON0_OVR_GET(x)                                           (((x) & XCTRL_3_XLNA2_ON0_OVR_MASK) >> XCTRL_3_XLNA2_ON0_OVR_LSB)
#define XCTRL_3_XLNA2_ON0_OVR_SET(x)                                           (((0 | (x)) << XCTRL_3_XLNA2_ON0_OVR_LSB) & XCTRL_3_XLNA2_ON0_OVR_MASK)
#define XCTRL_3_XLNA2_ON0_OVR_RESET                                            0x0
#define XCTRL_3_XLNA2_ON1_OVR_LSB                                              28
#define XCTRL_3_XLNA2_ON1_OVR_MSB                                              29
#define XCTRL_3_XLNA2_ON1_OVR_MASK                                             0x30000000
#define XCTRL_3_XLNA2_ON1_OVR_GET(x)                                           (((x) & XCTRL_3_XLNA2_ON1_OVR_MASK) >> XCTRL_3_XLNA2_ON1_OVR_LSB)
#define XCTRL_3_XLNA2_ON1_OVR_SET(x)                                           (((0 | (x)) << XCTRL_3_XLNA2_ON1_OVR_LSB) & XCTRL_3_XLNA2_ON1_OVR_MASK)
#define XCTRL_3_XLNA2_ON1_OVR_RESET                                            0x0
#define XCTRL_3_XLNA2_ON2_OVR_LSB                                              26
#define XCTRL_3_XLNA2_ON2_OVR_MSB                                              27
#define XCTRL_3_XLNA2_ON2_OVR_MASK                                             0xc000000
#define XCTRL_3_XLNA2_ON2_OVR_GET(x)                                           (((x) & XCTRL_3_XLNA2_ON2_OVR_MASK) >> XCTRL_3_XLNA2_ON2_OVR_LSB)
#define XCTRL_3_XLNA2_ON2_OVR_SET(x)                                           (((0 | (x)) << XCTRL_3_XLNA2_ON2_OVR_LSB) & XCTRL_3_XLNA2_ON2_OVR_MASK)
#define XCTRL_3_XLNA2_ON2_OVR_RESET                                            0x0
#define XCTRL_3_XLNA2_ON3_OVR_LSB                                              24
#define XCTRL_3_XLNA2_ON3_OVR_MSB                                              25
#define XCTRL_3_XLNA2_ON3_OVR_MASK                                             0x3000000
#define XCTRL_3_XLNA2_ON3_OVR_GET(x)                                           (((x) & XCTRL_3_XLNA2_ON3_OVR_MASK) >> XCTRL_3_XLNA2_ON3_OVR_LSB)
#define XCTRL_3_XLNA2_ON3_OVR_SET(x)                                           (((0 | (x)) << XCTRL_3_XLNA2_ON3_OVR_LSB) & XCTRL_3_XLNA2_ON3_OVR_MASK)
#define XCTRL_3_XLNA2_ON3_OVR_RESET                                            0x0
#define XCTRL_3_XPA2_ON0_OVR_LSB                                               22
#define XCTRL_3_XPA2_ON0_OVR_MSB                                               23
#define XCTRL_3_XPA2_ON0_OVR_MASK                                              0xc00000
#define XCTRL_3_XPA2_ON0_OVR_GET(x)                                            (((x) & XCTRL_3_XPA2_ON0_OVR_MASK) >> XCTRL_3_XPA2_ON0_OVR_LSB)
#define XCTRL_3_XPA2_ON0_OVR_SET(x)                                            (((0 | (x)) << XCTRL_3_XPA2_ON0_OVR_LSB) & XCTRL_3_XPA2_ON0_OVR_MASK)
#define XCTRL_3_XPA2_ON0_OVR_RESET                                             0x0
#define XCTRL_3_XPA2_ON1_OVR_LSB                                               20
#define XCTRL_3_XPA2_ON1_OVR_MSB                                               21
#define XCTRL_3_XPA2_ON1_OVR_MASK                                              0x300000
#define XCTRL_3_XPA2_ON1_OVR_GET(x)                                            (((x) & XCTRL_3_XPA2_ON1_OVR_MASK) >> XCTRL_3_XPA2_ON1_OVR_LSB)
#define XCTRL_3_XPA2_ON1_OVR_SET(x)                                            (((0 | (x)) << XCTRL_3_XPA2_ON1_OVR_LSB) & XCTRL_3_XPA2_ON1_OVR_MASK)
#define XCTRL_3_XPA2_ON1_OVR_RESET                                             0x0
#define XCTRL_3_XPA2_ON2_OVR_LSB                                               18
#define XCTRL_3_XPA2_ON2_OVR_MSB                                               19
#define XCTRL_3_XPA2_ON2_OVR_MASK                                              0xc0000
#define XCTRL_3_XPA2_ON2_OVR_GET(x)                                            (((x) & XCTRL_3_XPA2_ON2_OVR_MASK) >> XCTRL_3_XPA2_ON2_OVR_LSB)
#define XCTRL_3_XPA2_ON2_OVR_SET(x)                                            (((0 | (x)) << XCTRL_3_XPA2_ON2_OVR_LSB) & XCTRL_3_XPA2_ON2_OVR_MASK)
#define XCTRL_3_XPA2_ON2_OVR_RESET                                             0x0
#define XCTRL_3_XPA2_ON3_OVR_LSB                                               16
#define XCTRL_3_XPA2_ON3_OVR_MSB                                               17
#define XCTRL_3_XPA2_ON3_OVR_MASK                                              0x30000
#define XCTRL_3_XPA2_ON3_OVR_GET(x)                                            (((x) & XCTRL_3_XPA2_ON3_OVR_MASK) >> XCTRL_3_XPA2_ON3_OVR_LSB)
#define XCTRL_3_XPA2_ON3_OVR_SET(x)                                            (((0 | (x)) << XCTRL_3_XPA2_ON3_OVR_LSB) & XCTRL_3_XPA2_ON3_OVR_MASK)
#define XCTRL_3_XPA2_ON3_OVR_RESET                                             0x0
#define XCTRL_3_XLNA5_ON0_OVR_LSB                                              14
#define XCTRL_3_XLNA5_ON0_OVR_MSB                                              15
#define XCTRL_3_XLNA5_ON0_OVR_MASK                                             0xc000
#define XCTRL_3_XLNA5_ON0_OVR_GET(x)                                           (((x) & XCTRL_3_XLNA5_ON0_OVR_MASK) >> XCTRL_3_XLNA5_ON0_OVR_LSB)
#define XCTRL_3_XLNA5_ON0_OVR_SET(x)                                           (((0 | (x)) << XCTRL_3_XLNA5_ON0_OVR_LSB) & XCTRL_3_XLNA5_ON0_OVR_MASK)
#define XCTRL_3_XLNA5_ON0_OVR_RESET                                            0x0
#define XCTRL_3_XLNA5_ON1_OVR_LSB                                              12
#define XCTRL_3_XLNA5_ON1_OVR_MSB                                              13
#define XCTRL_3_XLNA5_ON1_OVR_MASK                                             0x3000
#define XCTRL_3_XLNA5_ON1_OVR_GET(x)                                           (((x) & XCTRL_3_XLNA5_ON1_OVR_MASK) >> XCTRL_3_XLNA5_ON1_OVR_LSB)
#define XCTRL_3_XLNA5_ON1_OVR_SET(x)                                           (((0 | (x)) << XCTRL_3_XLNA5_ON1_OVR_LSB) & XCTRL_3_XLNA5_ON1_OVR_MASK)
#define XCTRL_3_XLNA5_ON1_OVR_RESET                                            0x0
#define XCTRL_3_XLNA5_ON2_OVR_LSB                                              10
#define XCTRL_3_XLNA5_ON2_OVR_MSB                                              11
#define XCTRL_3_XLNA5_ON2_OVR_MASK                                             0xc00
#define XCTRL_3_XLNA5_ON2_OVR_GET(x)                                           (((x) & XCTRL_3_XLNA5_ON2_OVR_MASK) >> XCTRL_3_XLNA5_ON2_OVR_LSB)
#define XCTRL_3_XLNA5_ON2_OVR_SET(x)                                           (((0 | (x)) << XCTRL_3_XLNA5_ON2_OVR_LSB) & XCTRL_3_XLNA5_ON2_OVR_MASK)
#define XCTRL_3_XLNA5_ON2_OVR_RESET                                            0x0
#define XCTRL_3_XLNA5_ON3_OVR_LSB                                              8
#define XCTRL_3_XLNA5_ON3_OVR_MSB                                              9
#define XCTRL_3_XLNA5_ON3_OVR_MASK                                             0x300
#define XCTRL_3_XLNA5_ON3_OVR_GET(x)                                           (((x) & XCTRL_3_XLNA5_ON3_OVR_MASK) >> XCTRL_3_XLNA5_ON3_OVR_LSB)
#define XCTRL_3_XLNA5_ON3_OVR_SET(x)                                           (((0 | (x)) << XCTRL_3_XLNA5_ON3_OVR_LSB) & XCTRL_3_XLNA5_ON3_OVR_MASK)
#define XCTRL_3_XLNA5_ON3_OVR_RESET                                            0x0
#define XCTRL_3_XPA5_ON0_OVR_LSB                                               6
#define XCTRL_3_XPA5_ON0_OVR_MSB                                               7
#define XCTRL_3_XPA5_ON0_OVR_MASK                                              0xc0
#define XCTRL_3_XPA5_ON0_OVR_GET(x)                                            (((x) & XCTRL_3_XPA5_ON0_OVR_MASK) >> XCTRL_3_XPA5_ON0_OVR_LSB)
#define XCTRL_3_XPA5_ON0_OVR_SET(x)                                            (((0 | (x)) << XCTRL_3_XPA5_ON0_OVR_LSB) & XCTRL_3_XPA5_ON0_OVR_MASK)
#define XCTRL_3_XPA5_ON0_OVR_RESET                                             0x0
#define XCTRL_3_XPA5_ON1_OVR_LSB                                               4
#define XCTRL_3_XPA5_ON1_OVR_MSB                                               5
#define XCTRL_3_XPA5_ON1_OVR_MASK                                              0x30
#define XCTRL_3_XPA5_ON1_OVR_GET(x)                                            (((x) & XCTRL_3_XPA5_ON1_OVR_MASK) >> XCTRL_3_XPA5_ON1_OVR_LSB)
#define XCTRL_3_XPA5_ON1_OVR_SET(x)                                            (((0 | (x)) << XCTRL_3_XPA5_ON1_OVR_LSB) & XCTRL_3_XPA5_ON1_OVR_MASK)
#define XCTRL_3_XPA5_ON1_OVR_RESET                                             0x0
#define XCTRL_3_XPA5_ON2_OVR_LSB                                               2
#define XCTRL_3_XPA5_ON2_OVR_MSB                                               3
#define XCTRL_3_XPA5_ON2_OVR_MASK                                              0xc
#define XCTRL_3_XPA5_ON2_OVR_GET(x)                                            (((x) & XCTRL_3_XPA5_ON2_OVR_MASK) >> XCTRL_3_XPA5_ON2_OVR_LSB)
#define XCTRL_3_XPA5_ON2_OVR_SET(x)                                            (((0 | (x)) << XCTRL_3_XPA5_ON2_OVR_LSB) & XCTRL_3_XPA5_ON2_OVR_MASK)
#define XCTRL_3_XPA5_ON2_OVR_RESET                                             0x0
#define XCTRL_3_XPA5_ON3_OVR_LSB                                               0
#define XCTRL_3_XPA5_ON3_OVR_MSB                                               1
#define XCTRL_3_XPA5_ON3_OVR_MASK                                              0x3
#define XCTRL_3_XPA5_ON3_OVR_GET(x)                                            (((x) & XCTRL_3_XPA5_ON3_OVR_MASK) >> XCTRL_3_XPA5_ON3_OVR_LSB)
#define XCTRL_3_XPA5_ON3_OVR_SET(x)                                            (((0 | (x)) << XCTRL_3_XPA5_ON3_OVR_LSB) & XCTRL_3_XPA5_ON3_OVR_MASK)
#define XCTRL_3_XPA5_ON3_OVR_RESET                                             0x0
#define XCTRL_3_ADDRESS                                                        (0xc + __MI_XCONTROL_REG_CSR_BASE_ADDRESS)
#define XCTRL_3_RSTMASK                                                        0xffffffff
#define XCTRL_3_RESET                                                          0x0

// 0x10 (XCTRL_4)
#define XCTRL_4_XCTRL_SPARE_LSB                                                0
#define XCTRL_4_XCTRL_SPARE_MSB                                                31
#define XCTRL_4_XCTRL_SPARE_MASK                                               0xffffffff
#define XCTRL_4_XCTRL_SPARE_GET(x)                                             (((x) & XCTRL_4_XCTRL_SPARE_MASK) >> XCTRL_4_XCTRL_SPARE_LSB)
#define XCTRL_4_XCTRL_SPARE_SET(x)                                             (((0 | (x)) << XCTRL_4_XCTRL_SPARE_LSB) & XCTRL_4_XCTRL_SPARE_MASK)
#define XCTRL_4_XCTRL_SPARE_RESET                                              0x0
#define XCTRL_4_ADDRESS                                                        (0x10 + __MI_XCONTROL_REG_CSR_BASE_ADDRESS)
#define XCTRL_4_RSTMASK                                                        0xffffffff
#define XCTRL_4_RESET                                                          0x0



#endif /* _MI_XCONTROL_REG_CSR_H_ */
