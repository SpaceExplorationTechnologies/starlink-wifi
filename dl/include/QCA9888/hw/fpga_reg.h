/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _FPGA_REG_H_
#define _FPGA_REG_H_


#ifndef __FPGA_REG_BASE_ADDRESS
#define __FPGA_REG_BASE_ADDRESS (0x18120)
#endif


// 0x0 (FPGA_REG1)
#define FPGA_REG1_FPGA_FAKE_PA_SEL_0_LSB                                       30
#define FPGA_REG1_FPGA_FAKE_PA_SEL_0_MSB                                       31
#define FPGA_REG1_FPGA_FAKE_PA_SEL_0_MASK                                      0xc0000000
#define FPGA_REG1_FPGA_FAKE_PA_SEL_0_GET(x)                                    (((x) & FPGA_REG1_FPGA_FAKE_PA_SEL_0_MASK) >> FPGA_REG1_FPGA_FAKE_PA_SEL_0_LSB)
#define FPGA_REG1_FPGA_FAKE_PA_SEL_0_SET(x)                                    (((0 | (x)) << FPGA_REG1_FPGA_FAKE_PA_SEL_0_LSB) & FPGA_REG1_FPGA_FAKE_PA_SEL_0_MASK)
#define FPGA_REG1_FPGA_FAKE_PA_SEL_0_RESET                                     0x0
#define FPGA_REG1_FPGA_FAKE_PA_SEL_1_LSB                                       28
#define FPGA_REG1_FPGA_FAKE_PA_SEL_1_MSB                                       29
#define FPGA_REG1_FPGA_FAKE_PA_SEL_1_MASK                                      0x30000000
#define FPGA_REG1_FPGA_FAKE_PA_SEL_1_GET(x)                                    (((x) & FPGA_REG1_FPGA_FAKE_PA_SEL_1_MASK) >> FPGA_REG1_FPGA_FAKE_PA_SEL_1_LSB)
#define FPGA_REG1_FPGA_FAKE_PA_SEL_1_SET(x)                                    (((0 | (x)) << FPGA_REG1_FPGA_FAKE_PA_SEL_1_LSB) & FPGA_REG1_FPGA_FAKE_PA_SEL_1_MASK)
#define FPGA_REG1_FPGA_FAKE_PA_SEL_1_RESET                                     0x0
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_0_LSB                                      21
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_0_MSB                                      27
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_0_MASK                                     0xfe00000
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_0_GET(x)                                   (((x) & FPGA_REG1_FPGA_RXIQ_COEFF_I_0_MASK) >> FPGA_REG1_FPGA_RXIQ_COEFF_I_0_LSB)
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_0_SET(x)                                   (((0 | (x)) << FPGA_REG1_FPGA_RXIQ_COEFF_I_0_LSB) & FPGA_REG1_FPGA_RXIQ_COEFF_I_0_MASK)
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_0_RESET                                    0x0
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_0_LSB                                      14
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_0_MSB                                      20
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_0_MASK                                     0x1fc000
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_0_GET(x)                                   (((x) & FPGA_REG1_FPGA_RXIQ_COEFF_Q_0_MASK) >> FPGA_REG1_FPGA_RXIQ_COEFF_Q_0_LSB)
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_0_SET(x)                                   (((0 | (x)) << FPGA_REG1_FPGA_RXIQ_COEFF_Q_0_LSB) & FPGA_REG1_FPGA_RXIQ_COEFF_Q_0_MASK)
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_0_RESET                                    0x0
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_1_LSB                                      7
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_1_MSB                                      13
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_1_MASK                                     0x3f80
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_1_GET(x)                                   (((x) & FPGA_REG1_FPGA_RXIQ_COEFF_I_1_MASK) >> FPGA_REG1_FPGA_RXIQ_COEFF_I_1_LSB)
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_1_SET(x)                                   (((0 | (x)) << FPGA_REG1_FPGA_RXIQ_COEFF_I_1_LSB) & FPGA_REG1_FPGA_RXIQ_COEFF_I_1_MASK)
#define FPGA_REG1_FPGA_RXIQ_COEFF_I_1_RESET                                    0x0
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_1_LSB                                      0
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_1_MSB                                      6
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_1_MASK                                     0x7f
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_1_GET(x)                                   (((x) & FPGA_REG1_FPGA_RXIQ_COEFF_Q_1_MASK) >> FPGA_REG1_FPGA_RXIQ_COEFF_Q_1_LSB)
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_1_SET(x)                                   (((0 | (x)) << FPGA_REG1_FPGA_RXIQ_COEFF_Q_1_LSB) & FPGA_REG1_FPGA_RXIQ_COEFF_Q_1_MASK)
#define FPGA_REG1_FPGA_RXIQ_COEFF_Q_1_RESET                                    0x0
#define FPGA_REG1_ADDRESS                                                      (0x0 + __FPGA_REG_BASE_ADDRESS)
#define FPGA_REG1_RSTMASK                                                      0xffffffff
#define FPGA_REG1_RESET                                                        0x0

// 0x4 (FPGA_REG2)
#define FPGA_REG2_FPGA_ADC_DC_I_0_LSB                                          26
#define FPGA_REG2_FPGA_ADC_DC_I_0_MSB                                          31
#define FPGA_REG2_FPGA_ADC_DC_I_0_MASK                                         0xfc000000
#define FPGA_REG2_FPGA_ADC_DC_I_0_GET(x)                                       (((x) & FPGA_REG2_FPGA_ADC_DC_I_0_MASK) >> FPGA_REG2_FPGA_ADC_DC_I_0_LSB)
#define FPGA_REG2_FPGA_ADC_DC_I_0_SET(x)                                       (((0 | (x)) << FPGA_REG2_FPGA_ADC_DC_I_0_LSB) & FPGA_REG2_FPGA_ADC_DC_I_0_MASK)
#define FPGA_REG2_FPGA_ADC_DC_I_0_RESET                                        0x0
#define FPGA_REG2_FPGA_ADC_DC_Q_0_LSB                                          20
#define FPGA_REG2_FPGA_ADC_DC_Q_0_MSB                                          25
#define FPGA_REG2_FPGA_ADC_DC_Q_0_MASK                                         0x3f00000
#define FPGA_REG2_FPGA_ADC_DC_Q_0_GET(x)                                       (((x) & FPGA_REG2_FPGA_ADC_DC_Q_0_MASK) >> FPGA_REG2_FPGA_ADC_DC_Q_0_LSB)
#define FPGA_REG2_FPGA_ADC_DC_Q_0_SET(x)                                       (((0 | (x)) << FPGA_REG2_FPGA_ADC_DC_Q_0_LSB) & FPGA_REG2_FPGA_ADC_DC_Q_0_MASK)
#define FPGA_REG2_FPGA_ADC_DC_Q_0_RESET                                        0x0
#define FPGA_REG2_FPGA_FIFO_DELAY_0_LSB                                        16
#define FPGA_REG2_FPGA_FIFO_DELAY_0_MSB                                        19
#define FPGA_REG2_FPGA_FIFO_DELAY_0_MASK                                       0xf0000
#define FPGA_REG2_FPGA_FIFO_DELAY_0_GET(x)                                     (((x) & FPGA_REG2_FPGA_FIFO_DELAY_0_MASK) >> FPGA_REG2_FPGA_FIFO_DELAY_0_LSB)
#define FPGA_REG2_FPGA_FIFO_DELAY_0_SET(x)                                     (((0 | (x)) << FPGA_REG2_FPGA_FIFO_DELAY_0_LSB) & FPGA_REG2_FPGA_FIFO_DELAY_0_MASK)
#define FPGA_REG2_FPGA_FIFO_DELAY_0_RESET                                      0x0
#define FPGA_REG2_FPGA_ADC_DC_I_1_LSB                                          10
#define FPGA_REG2_FPGA_ADC_DC_I_1_MSB                                          15
#define FPGA_REG2_FPGA_ADC_DC_I_1_MASK                                         0xfc00
#define FPGA_REG2_FPGA_ADC_DC_I_1_GET(x)                                       (((x) & FPGA_REG2_FPGA_ADC_DC_I_1_MASK) >> FPGA_REG2_FPGA_ADC_DC_I_1_LSB)
#define FPGA_REG2_FPGA_ADC_DC_I_1_SET(x)                                       (((0 | (x)) << FPGA_REG2_FPGA_ADC_DC_I_1_LSB) & FPGA_REG2_FPGA_ADC_DC_I_1_MASK)
#define FPGA_REG2_FPGA_ADC_DC_I_1_RESET                                        0x0
#define FPGA_REG2_FPGA_ADC_DC_Q_1_LSB                                          4
#define FPGA_REG2_FPGA_ADC_DC_Q_1_MSB                                          9
#define FPGA_REG2_FPGA_ADC_DC_Q_1_MASK                                         0x3f0
#define FPGA_REG2_FPGA_ADC_DC_Q_1_GET(x)                                       (((x) & FPGA_REG2_FPGA_ADC_DC_Q_1_MASK) >> FPGA_REG2_FPGA_ADC_DC_Q_1_LSB)
#define FPGA_REG2_FPGA_ADC_DC_Q_1_SET(x)                                       (((0 | (x)) << FPGA_REG2_FPGA_ADC_DC_Q_1_LSB) & FPGA_REG2_FPGA_ADC_DC_Q_1_MASK)
#define FPGA_REG2_FPGA_ADC_DC_Q_1_RESET                                        0x0
#define FPGA_REG2_FPGA_FIFO_DELAY_1_LSB                                        0
#define FPGA_REG2_FPGA_FIFO_DELAY_1_MSB                                        3
#define FPGA_REG2_FPGA_FIFO_DELAY_1_MASK                                       0xf
#define FPGA_REG2_FPGA_FIFO_DELAY_1_GET(x)                                     (((x) & FPGA_REG2_FPGA_FIFO_DELAY_1_MASK) >> FPGA_REG2_FPGA_FIFO_DELAY_1_LSB)
#define FPGA_REG2_FPGA_FIFO_DELAY_1_SET(x)                                     (((0 | (x)) << FPGA_REG2_FPGA_FIFO_DELAY_1_LSB) & FPGA_REG2_FPGA_FIFO_DELAY_1_MASK)
#define FPGA_REG2_FPGA_FIFO_DELAY_1_RESET                                      0x0
#define FPGA_REG2_ADDRESS                                                      (0x4 + __FPGA_REG_BASE_ADDRESS)
#define FPGA_REG2_RSTMASK                                                      0xffffffff
#define FPGA_REG2_RESET                                                        0x0

// 0x8 (FPGA_REG3)
#define FPGA_REG3_FPGA_ADC_CLK_SEL_1_LSB                                       4
#define FPGA_REG3_FPGA_ADC_CLK_SEL_1_MSB                                       5
#define FPGA_REG3_FPGA_ADC_CLK_SEL_1_MASK                                      0x30
#define FPGA_REG3_FPGA_ADC_CLK_SEL_1_GET(x)                                    (((x) & FPGA_REG3_FPGA_ADC_CLK_SEL_1_MASK) >> FPGA_REG3_FPGA_ADC_CLK_SEL_1_LSB)
#define FPGA_REG3_FPGA_ADC_CLK_SEL_1_SET(x)                                    (((0 | (x)) << FPGA_REG3_FPGA_ADC_CLK_SEL_1_LSB) & FPGA_REG3_FPGA_ADC_CLK_SEL_1_MASK)
#define FPGA_REG3_FPGA_ADC_CLK_SEL_1_RESET                                     0x0
#define FPGA_REG3_FPGA_ADC_CLK_SEL_0_LSB                                       2
#define FPGA_REG3_FPGA_ADC_CLK_SEL_0_MSB                                       3
#define FPGA_REG3_FPGA_ADC_CLK_SEL_0_MASK                                      0xc
#define FPGA_REG3_FPGA_ADC_CLK_SEL_0_GET(x)                                    (((x) & FPGA_REG3_FPGA_ADC_CLK_SEL_0_MASK) >> FPGA_REG3_FPGA_ADC_CLK_SEL_0_LSB)
#define FPGA_REG3_FPGA_ADC_CLK_SEL_0_SET(x)                                    (((0 | (x)) << FPGA_REG3_FPGA_ADC_CLK_SEL_0_LSB) & FPGA_REG3_FPGA_ADC_CLK_SEL_0_MASK)
#define FPGA_REG3_FPGA_ADC_CLK_SEL_0_RESET                                     0x0
#define FPGA_REG3_FPGA_RXIQ_ENABLE_LSB                                         0
#define FPGA_REG3_FPGA_RXIQ_ENABLE_MSB                                         1
#define FPGA_REG3_FPGA_RXIQ_ENABLE_MASK                                        0x3
#define FPGA_REG3_FPGA_RXIQ_ENABLE_GET(x)                                      (((x) & FPGA_REG3_FPGA_RXIQ_ENABLE_MASK) >> FPGA_REG3_FPGA_RXIQ_ENABLE_LSB)
#define FPGA_REG3_FPGA_RXIQ_ENABLE_SET(x)                                      (((0 | (x)) << FPGA_REG3_FPGA_RXIQ_ENABLE_LSB) & FPGA_REG3_FPGA_RXIQ_ENABLE_MASK)
#define FPGA_REG3_FPGA_RXIQ_ENABLE_RESET                                       0x0
#define FPGA_REG3_ADDRESS                                                      (0x8 + __FPGA_REG_BASE_ADDRESS)
#define FPGA_REG3_RSTMASK                                                      0x3f
#define FPGA_REG3_RESET                                                        0x0



#endif /* _FPGA_REG_H_ */
