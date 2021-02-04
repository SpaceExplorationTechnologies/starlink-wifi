/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _MERLIN_REG_SEL_H_
#define _MERLIN_REG_SEL_H_


#ifndef __MERLIN_REG_SEL_BASE_ADDRESS
#define __MERLIN_REG_SEL_BASE_ADDRESS (0x1f000)
#endif


// 0x0 (MERLIN_RADIO_SEL)
#define MERLIN_RADIO_SEL_SPARE_LSB                                             1
#define MERLIN_RADIO_SEL_SPARE_MSB                                             31
#define MERLIN_RADIO_SEL_SPARE_MASK                                            0xfffffffe
#define MERLIN_RADIO_SEL_SPARE_GET(x)                                          (((x) & MERLIN_RADIO_SEL_SPARE_MASK) >> MERLIN_RADIO_SEL_SPARE_LSB)
#define MERLIN_RADIO_SEL_SPARE_SET(x)                                          (((0 | (x)) << MERLIN_RADIO_SEL_SPARE_LSB) & MERLIN_RADIO_SEL_SPARE_MASK)
#define MERLIN_RADIO_SEL_SPARE_RESET                                           0x0
#define MERLIN_RADIO_SEL_RADIO_SEL_LSB                                         0
#define MERLIN_RADIO_SEL_RADIO_SEL_MSB                                         0
#define MERLIN_RADIO_SEL_RADIO_SEL_MASK                                        0x1
#define MERLIN_RADIO_SEL_RADIO_SEL_GET(x)                                      (((x) & MERLIN_RADIO_SEL_RADIO_SEL_MASK) >> MERLIN_RADIO_SEL_RADIO_SEL_LSB)
#define MERLIN_RADIO_SEL_RADIO_SEL_SET(x)                                      (((0 | (x)) << MERLIN_RADIO_SEL_RADIO_SEL_LSB) & MERLIN_RADIO_SEL_RADIO_SEL_MASK)
#define MERLIN_RADIO_SEL_RADIO_SEL_RESET                                       0x0
#define MERLIN_RADIO_SEL_ADDRESS                                               (0x0 + __MERLIN_REG_SEL_BASE_ADDRESS)
#define MERLIN_RADIO_SEL_RSTMASK                                               0xffffffff
#define MERLIN_RADIO_SEL_RESET                                                 0x0



#endif /* _MERLIN_REG_SEL_H_ */
