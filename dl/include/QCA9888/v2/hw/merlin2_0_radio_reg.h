/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _MERLIN2_0_RADIO_REG_H_
#define _MERLIN2_0_RADIO_REG_H_


#ifndef __MERLIN2_0_RADIO_REG_BASE_ADDRESS
#define __MERLIN2_0_RADIO_REG_BASE_ADDRESS (0x1ff00)
#endif


// 0x0 (MERLIN_RXTXBB1_CH1)
#define MERLIN_RXTXBB1_CH1_SPARE_LSB                                           19
#define MERLIN_RXTXBB1_CH1_SPARE_MSB                                           31
#define MERLIN_RXTXBB1_CH1_SPARE_MASK                                          0xfff80000
#define MERLIN_RXTXBB1_CH1_SPARE_GET(x)                                        (((x) & MERLIN_RXTXBB1_CH1_SPARE_MASK) >> MERLIN_RXTXBB1_CH1_SPARE_LSB)
#define MERLIN_RXTXBB1_CH1_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB1_CH1_SPARE_LSB) & MERLIN_RXTXBB1_CH1_SPARE_MASK)
#define MERLIN_RXTXBB1_CH1_SPARE_RESET                                         0x0
#define MERLIN_RXTXBB1_CH1_FNOTCH_LSB                                          17
#define MERLIN_RXTXBB1_CH1_FNOTCH_MSB                                          18
#define MERLIN_RXTXBB1_CH1_FNOTCH_MASK                                         0x60000
#define MERLIN_RXTXBB1_CH1_FNOTCH_GET(x)                                       (((x) & MERLIN_RXTXBB1_CH1_FNOTCH_MASK) >> MERLIN_RXTXBB1_CH1_FNOTCH_LSB)
#define MERLIN_RXTXBB1_CH1_FNOTCH_SET(x)                                       (((0 | (x)) << MERLIN_RXTXBB1_CH1_FNOTCH_LSB) & MERLIN_RXTXBB1_CH1_FNOTCH_MASK)
#define MERLIN_RXTXBB1_CH1_FNOTCH_RESET                                        0x0
#define MERLIN_RXTXBB1_CH1_SEL_ATB_LSB                                         9
#define MERLIN_RXTXBB1_CH1_SEL_ATB_MSB                                         16
#define MERLIN_RXTXBB1_CH1_SEL_ATB_MASK                                        0x1fe00
#define MERLIN_RXTXBB1_CH1_SEL_ATB_GET(x)                                      (((x) & MERLIN_RXTXBB1_CH1_SEL_ATB_MASK) >> MERLIN_RXTXBB1_CH1_SEL_ATB_LSB)
#define MERLIN_RXTXBB1_CH1_SEL_ATB_SET(x)                                      (((0 | (x)) << MERLIN_RXTXBB1_CH1_SEL_ATB_LSB) & MERLIN_RXTXBB1_CH1_SEL_ATB_MASK)
#define MERLIN_RXTXBB1_CH1_SEL_ATB_RESET                                       0x0
#define MERLIN_RXTXBB1_CH1_PDDACINTERFACE_LSB                                  8
#define MERLIN_RXTXBB1_CH1_PDDACINTERFACE_MSB                                  8
#define MERLIN_RXTXBB1_CH1_PDDACINTERFACE_MASK                                 0x100
#define MERLIN_RXTXBB1_CH1_PDDACINTERFACE_GET(x)                               (((x) & MERLIN_RXTXBB1_CH1_PDDACINTERFACE_MASK) >> MERLIN_RXTXBB1_CH1_PDDACINTERFACE_LSB)
#define MERLIN_RXTXBB1_CH1_PDDACINTERFACE_SET(x)                               (((0 | (x)) << MERLIN_RXTXBB1_CH1_PDDACINTERFACE_LSB) & MERLIN_RXTXBB1_CH1_PDDACINTERFACE_MASK)
#define MERLIN_RXTXBB1_CH1_PDDACINTERFACE_RESET                                0x0
#define MERLIN_RXTXBB1_CH1_PDV2I_LSB                                           7
#define MERLIN_RXTXBB1_CH1_PDV2I_MSB                                           7
#define MERLIN_RXTXBB1_CH1_PDV2I_MASK                                          0x80
#define MERLIN_RXTXBB1_CH1_PDV2I_GET(x)                                        (((x) & MERLIN_RXTXBB1_CH1_PDV2I_MASK) >> MERLIN_RXTXBB1_CH1_PDV2I_LSB)
#define MERLIN_RXTXBB1_CH1_PDV2I_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB1_CH1_PDV2I_LSB) & MERLIN_RXTXBB1_CH1_PDV2I_MASK)
#define MERLIN_RXTXBB1_CH1_PDV2I_RESET                                         0x0
#define MERLIN_RXTXBB1_CH1_PDI2V_LSB                                           6
#define MERLIN_RXTXBB1_CH1_PDI2V_MSB                                           6
#define MERLIN_RXTXBB1_CH1_PDI2V_MASK                                          0x40
#define MERLIN_RXTXBB1_CH1_PDI2V_GET(x)                                        (((x) & MERLIN_RXTXBB1_CH1_PDI2V_MASK) >> MERLIN_RXTXBB1_CH1_PDI2V_LSB)
#define MERLIN_RXTXBB1_CH1_PDI2V_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB1_CH1_PDI2V_LSB) & MERLIN_RXTXBB1_CH1_PDI2V_MASK)
#define MERLIN_RXTXBB1_CH1_PDI2V_RESET                                         0x0
#define MERLIN_RXTXBB1_CH1_PDRXTXBB_LSB                                        5
#define MERLIN_RXTXBB1_CH1_PDRXTXBB_MSB                                        5
#define MERLIN_RXTXBB1_CH1_PDRXTXBB_MASK                                       0x20
#define MERLIN_RXTXBB1_CH1_PDRXTXBB_GET(x)                                     (((x) & MERLIN_RXTXBB1_CH1_PDRXTXBB_MASK) >> MERLIN_RXTXBB1_CH1_PDRXTXBB_LSB)
#define MERLIN_RXTXBB1_CH1_PDRXTXBB_SET(x)                                     (((0 | (x)) << MERLIN_RXTXBB1_CH1_PDRXTXBB_LSB) & MERLIN_RXTXBB1_CH1_PDRXTXBB_MASK)
#define MERLIN_RXTXBB1_CH1_PDRXTXBB_RESET                                      0x0
#define MERLIN_RXTXBB1_CH1_PDOFFSETLOQ_LSB                                     4
#define MERLIN_RXTXBB1_CH1_PDOFFSETLOQ_MSB                                     4
#define MERLIN_RXTXBB1_CH1_PDOFFSETLOQ_MASK                                    0x10
#define MERLIN_RXTXBB1_CH1_PDOFFSETLOQ_GET(x)                                  (((x) & MERLIN_RXTXBB1_CH1_PDOFFSETLOQ_MASK) >> MERLIN_RXTXBB1_CH1_PDOFFSETLOQ_LSB)
#define MERLIN_RXTXBB1_CH1_PDOFFSETLOQ_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB1_CH1_PDOFFSETLOQ_LSB) & MERLIN_RXTXBB1_CH1_PDOFFSETLOQ_MASK)
#define MERLIN_RXTXBB1_CH1_PDOFFSETLOQ_RESET                                   0x0
#define MERLIN_RXTXBB1_CH1_PDOFFSETHIQ_LSB                                     3
#define MERLIN_RXTXBB1_CH1_PDOFFSETHIQ_MSB                                     3
#define MERLIN_RXTXBB1_CH1_PDOFFSETHIQ_MASK                                    0x8
#define MERLIN_RXTXBB1_CH1_PDOFFSETHIQ_GET(x)                                  (((x) & MERLIN_RXTXBB1_CH1_PDOFFSETHIQ_MASK) >> MERLIN_RXTXBB1_CH1_PDOFFSETHIQ_LSB)
#define MERLIN_RXTXBB1_CH1_PDOFFSETHIQ_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB1_CH1_PDOFFSETHIQ_LSB) & MERLIN_RXTXBB1_CH1_PDOFFSETHIQ_MASK)
#define MERLIN_RXTXBB1_CH1_PDOFFSETHIQ_RESET                                   0x0
#define MERLIN_RXTXBB1_CH1_PDOFFSETI2V_LSB                                     2
#define MERLIN_RXTXBB1_CH1_PDOFFSETI2V_MSB                                     2
#define MERLIN_RXTXBB1_CH1_PDOFFSETI2V_MASK                                    0x4
#define MERLIN_RXTXBB1_CH1_PDOFFSETI2V_GET(x)                                  (((x) & MERLIN_RXTXBB1_CH1_PDOFFSETI2V_MASK) >> MERLIN_RXTXBB1_CH1_PDOFFSETI2V_LSB)
#define MERLIN_RXTXBB1_CH1_PDOFFSETI2V_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB1_CH1_PDOFFSETI2V_LSB) & MERLIN_RXTXBB1_CH1_PDOFFSETI2V_MASK)
#define MERLIN_RXTXBB1_CH1_PDOFFSETI2V_RESET                                   0x0
#define MERLIN_RXTXBB1_CH1_PDLOQ_LSB                                           1
#define MERLIN_RXTXBB1_CH1_PDLOQ_MSB                                           1
#define MERLIN_RXTXBB1_CH1_PDLOQ_MASK                                          0x2
#define MERLIN_RXTXBB1_CH1_PDLOQ_GET(x)                                        (((x) & MERLIN_RXTXBB1_CH1_PDLOQ_MASK) >> MERLIN_RXTXBB1_CH1_PDLOQ_LSB)
#define MERLIN_RXTXBB1_CH1_PDLOQ_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB1_CH1_PDLOQ_LSB) & MERLIN_RXTXBB1_CH1_PDLOQ_MASK)
#define MERLIN_RXTXBB1_CH1_PDLOQ_RESET                                         0x0
#define MERLIN_RXTXBB1_CH1_PDHIQ_LSB                                           0
#define MERLIN_RXTXBB1_CH1_PDHIQ_MSB                                           0
#define MERLIN_RXTXBB1_CH1_PDHIQ_MASK                                          0x1
#define MERLIN_RXTXBB1_CH1_PDHIQ_GET(x)                                        (((x) & MERLIN_RXTXBB1_CH1_PDHIQ_MASK) >> MERLIN_RXTXBB1_CH1_PDHIQ_LSB)
#define MERLIN_RXTXBB1_CH1_PDHIQ_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB1_CH1_PDHIQ_LSB) & MERLIN_RXTXBB1_CH1_PDHIQ_MASK)
#define MERLIN_RXTXBB1_CH1_PDHIQ_RESET                                         0x0
#define MERLIN_RXTXBB1_CH1_ADDRESS                                             (0x0 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RXTXBB1_CH1_RSTMASK                                             0xffffffff
#define MERLIN_RXTXBB1_CH1_RESET                                               0x0

// 0x4 (MERLIN_RXTXBB2_CH1)
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_LSB                              29
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_MSB                              31
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_MASK                             0xe0000000
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_GET(x)                           (((x) & MERLIN_RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_MASK) >> MERLIN_RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_LSB)
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_SET(x)                           (((0 | (x)) << MERLIN_RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_LSB) & MERLIN_RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_MASK)
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_RESET                            0x6
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_LSB                              26
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_MSB                              28
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_MASK                             0x1c000000
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_GET(x)                           (((x) & MERLIN_RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_MASK) >> MERLIN_RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_LSB)
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_SET(x)                           (((0 | (x)) << MERLIN_RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_LSB) & MERLIN_RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_MASK)
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_RESET                            0x6
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_LSB                             23
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_MSB                             25
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_MASK                            0x3800000
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_GET(x)                          (((x) & MERLIN_RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_MASK) >> MERLIN_RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_LSB)
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_SET(x)                          (((0 | (x)) << MERLIN_RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_LSB) & MERLIN_RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_MASK)
#define MERLIN_RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_RESET                           0x6
#define MERLIN_RXTXBB2_CH1_SPARE_LSB                                           21
#define MERLIN_RXTXBB2_CH1_SPARE_MSB                                           22
#define MERLIN_RXTXBB2_CH1_SPARE_MASK                                          0x600000
#define MERLIN_RXTXBB2_CH1_SPARE_GET(x)                                        (((x) & MERLIN_RXTXBB2_CH1_SPARE_MASK) >> MERLIN_RXTXBB2_CH1_SPARE_LSB)
#define MERLIN_RXTXBB2_CH1_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB2_CH1_SPARE_LSB) & MERLIN_RXTXBB2_CH1_SPARE_MASK)
#define MERLIN_RXTXBB2_CH1_SPARE_RESET                                         0x0
#define MERLIN_RXTXBB2_CH1_SHORTBUFFER_LSB                                     20
#define MERLIN_RXTXBB2_CH1_SHORTBUFFER_MSB                                     20
#define MERLIN_RXTXBB2_CH1_SHORTBUFFER_MASK                                    0x100000
#define MERLIN_RXTXBB2_CH1_SHORTBUFFER_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH1_SHORTBUFFER_MASK) >> MERLIN_RXTXBB2_CH1_SHORTBUFFER_LSB)
#define MERLIN_RXTXBB2_CH1_SHORTBUFFER_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH1_SHORTBUFFER_LSB) & MERLIN_RXTXBB2_CH1_SHORTBUFFER_MASK)
#define MERLIN_RXTXBB2_CH1_SHORTBUFFER_RESET                                   0x0
#define MERLIN_RXTXBB2_CH1_SELBUFFER_LSB                                       19
#define MERLIN_RXTXBB2_CH1_SELBUFFER_MSB                                       19
#define MERLIN_RXTXBB2_CH1_SELBUFFER_MASK                                      0x80000
#define MERLIN_RXTXBB2_CH1_SELBUFFER_GET(x)                                    (((x) & MERLIN_RXTXBB2_CH1_SELBUFFER_MASK) >> MERLIN_RXTXBB2_CH1_SELBUFFER_LSB)
#define MERLIN_RXTXBB2_CH1_SELBUFFER_SET(x)                                    (((0 | (x)) << MERLIN_RXTXBB2_CH1_SELBUFFER_LSB) & MERLIN_RXTXBB2_CH1_SELBUFFER_MASK)
#define MERLIN_RXTXBB2_CH1_SELBUFFER_RESET                                     0x0
#define MERLIN_RXTXBB2_CH1_SEL_DAC_TEST_LSB                                    18
#define MERLIN_RXTXBB2_CH1_SEL_DAC_TEST_MSB                                    18
#define MERLIN_RXTXBB2_CH1_SEL_DAC_TEST_MASK                                   0x40000
#define MERLIN_RXTXBB2_CH1_SEL_DAC_TEST_GET(x)                                 (((x) & MERLIN_RXTXBB2_CH1_SEL_DAC_TEST_MASK) >> MERLIN_RXTXBB2_CH1_SEL_DAC_TEST_LSB)
#define MERLIN_RXTXBB2_CH1_SEL_DAC_TEST_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB2_CH1_SEL_DAC_TEST_LSB) & MERLIN_RXTXBB2_CH1_SEL_DAC_TEST_MASK)
#define MERLIN_RXTXBB2_CH1_SEL_DAC_TEST_RESET                                  0x0
#define MERLIN_RXTXBB2_CH1_SEL_LOQ_TEST_LSB                                    17
#define MERLIN_RXTXBB2_CH1_SEL_LOQ_TEST_MSB                                    17
#define MERLIN_RXTXBB2_CH1_SEL_LOQ_TEST_MASK                                   0x20000
#define MERLIN_RXTXBB2_CH1_SEL_LOQ_TEST_GET(x)                                 (((x) & MERLIN_RXTXBB2_CH1_SEL_LOQ_TEST_MASK) >> MERLIN_RXTXBB2_CH1_SEL_LOQ_TEST_LSB)
#define MERLIN_RXTXBB2_CH1_SEL_LOQ_TEST_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB2_CH1_SEL_LOQ_TEST_LSB) & MERLIN_RXTXBB2_CH1_SEL_LOQ_TEST_MASK)
#define MERLIN_RXTXBB2_CH1_SEL_LOQ_TEST_RESET                                  0x0
#define MERLIN_RXTXBB2_CH1_SEL_HIQ_TEST_LSB                                    16
#define MERLIN_RXTXBB2_CH1_SEL_HIQ_TEST_MSB                                    16
#define MERLIN_RXTXBB2_CH1_SEL_HIQ_TEST_MASK                                   0x10000
#define MERLIN_RXTXBB2_CH1_SEL_HIQ_TEST_GET(x)                                 (((x) & MERLIN_RXTXBB2_CH1_SEL_HIQ_TEST_MASK) >> MERLIN_RXTXBB2_CH1_SEL_HIQ_TEST_LSB)
#define MERLIN_RXTXBB2_CH1_SEL_HIQ_TEST_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB2_CH1_SEL_HIQ_TEST_LSB) & MERLIN_RXTXBB2_CH1_SEL_HIQ_TEST_MASK)
#define MERLIN_RXTXBB2_CH1_SEL_HIQ_TEST_RESET                                  0x0
#define MERLIN_RXTXBB2_CH1_SEL_I2V_TEST_LSB                                    15
#define MERLIN_RXTXBB2_CH1_SEL_I2V_TEST_MSB                                    15
#define MERLIN_RXTXBB2_CH1_SEL_I2V_TEST_MASK                                   0x8000
#define MERLIN_RXTXBB2_CH1_SEL_I2V_TEST_GET(x)                                 (((x) & MERLIN_RXTXBB2_CH1_SEL_I2V_TEST_MASK) >> MERLIN_RXTXBB2_CH1_SEL_I2V_TEST_LSB)
#define MERLIN_RXTXBB2_CH1_SEL_I2V_TEST_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB2_CH1_SEL_I2V_TEST_LSB) & MERLIN_RXTXBB2_CH1_SEL_I2V_TEST_MASK)
#define MERLIN_RXTXBB2_CH1_SEL_I2V_TEST_RESET                                  0x0
#define MERLIN_RXTXBB2_CH1_CMSEL_LSB                                           13
#define MERLIN_RXTXBB2_CH1_CMSEL_MSB                                           14
#define MERLIN_RXTXBB2_CH1_CMSEL_MASK                                          0x6000
#define MERLIN_RXTXBB2_CH1_CMSEL_GET(x)                                        (((x) & MERLIN_RXTXBB2_CH1_CMSEL_MASK) >> MERLIN_RXTXBB2_CH1_CMSEL_LSB)
#define MERLIN_RXTXBB2_CH1_CMSEL_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB2_CH1_CMSEL_LSB) & MERLIN_RXTXBB2_CH1_CMSEL_MASK)
#define MERLIN_RXTXBB2_CH1_CMSEL_RESET                                         0x1
#define MERLIN_RXTXBB2_CH1_FILTERFC_LSB                                        8
#define MERLIN_RXTXBB2_CH1_FILTERFC_MSB                                        12
#define MERLIN_RXTXBB2_CH1_FILTERFC_MASK                                       0x1f00
#define MERLIN_RXTXBB2_CH1_FILTERFC_GET(x)                                     (((x) & MERLIN_RXTXBB2_CH1_FILTERFC_MASK) >> MERLIN_RXTXBB2_CH1_FILTERFC_LSB)
#define MERLIN_RXTXBB2_CH1_FILTERFC_SET(x)                                     (((0 | (x)) << MERLIN_RXTXBB2_CH1_FILTERFC_LSB) & MERLIN_RXTXBB2_CH1_FILTERFC_MASK)
#define MERLIN_RXTXBB2_CH1_FILTERFC_RESET                                      0x10
#define MERLIN_RXTXBB2_CH1_LOCALFILTERTUNING_LSB                               7
#define MERLIN_RXTXBB2_CH1_LOCALFILTERTUNING_MSB                               7
#define MERLIN_RXTXBB2_CH1_LOCALFILTERTUNING_MASK                              0x80
#define MERLIN_RXTXBB2_CH1_LOCALFILTERTUNING_GET(x)                            (((x) & MERLIN_RXTXBB2_CH1_LOCALFILTERTUNING_MASK) >> MERLIN_RXTXBB2_CH1_LOCALFILTERTUNING_LSB)
#define MERLIN_RXTXBB2_CH1_LOCALFILTERTUNING_SET(x)                            (((0 | (x)) << MERLIN_RXTXBB2_CH1_LOCALFILTERTUNING_LSB) & MERLIN_RXTXBB2_CH1_LOCALFILTERTUNING_MASK)
#define MERLIN_RXTXBB2_CH1_LOCALFILTERTUNING_RESET                             0x0
#define MERLIN_RXTXBB2_CH1_FILTERDOUBLEBW_LSB                                  6
#define MERLIN_RXTXBB2_CH1_FILTERDOUBLEBW_MSB                                  6
#define MERLIN_RXTXBB2_CH1_FILTERDOUBLEBW_MASK                                 0x40
#define MERLIN_RXTXBB2_CH1_FILTERDOUBLEBW_GET(x)                               (((x) & MERLIN_RXTXBB2_CH1_FILTERDOUBLEBW_MASK) >> MERLIN_RXTXBB2_CH1_FILTERDOUBLEBW_LSB)
#define MERLIN_RXTXBB2_CH1_FILTERDOUBLEBW_SET(x)                               (((0 | (x)) << MERLIN_RXTXBB2_CH1_FILTERDOUBLEBW_LSB) & MERLIN_RXTXBB2_CH1_FILTERDOUBLEBW_MASK)
#define MERLIN_RXTXBB2_CH1_FILTERDOUBLEBW_RESET                                0x0
#define MERLIN_RXTXBB2_CH1_PATH2HIQ_EN_LSB                                     5
#define MERLIN_RXTXBB2_CH1_PATH2HIQ_EN_MSB                                     5
#define MERLIN_RXTXBB2_CH1_PATH2HIQ_EN_MASK                                    0x20
#define MERLIN_RXTXBB2_CH1_PATH2HIQ_EN_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH1_PATH2HIQ_EN_MASK) >> MERLIN_RXTXBB2_CH1_PATH2HIQ_EN_LSB)
#define MERLIN_RXTXBB2_CH1_PATH2HIQ_EN_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH1_PATH2HIQ_EN_LSB) & MERLIN_RXTXBB2_CH1_PATH2HIQ_EN_MASK)
#define MERLIN_RXTXBB2_CH1_PATH2HIQ_EN_RESET                                   0x0
#define MERLIN_RXTXBB2_CH1_PATH1HIQ_EN_LSB                                     4
#define MERLIN_RXTXBB2_CH1_PATH1HIQ_EN_MSB                                     4
#define MERLIN_RXTXBB2_CH1_PATH1HIQ_EN_MASK                                    0x10
#define MERLIN_RXTXBB2_CH1_PATH1HIQ_EN_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH1_PATH1HIQ_EN_MASK) >> MERLIN_RXTXBB2_CH1_PATH1HIQ_EN_LSB)
#define MERLIN_RXTXBB2_CH1_PATH1HIQ_EN_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH1_PATH1HIQ_EN_LSB) & MERLIN_RXTXBB2_CH1_PATH1HIQ_EN_MASK)
#define MERLIN_RXTXBB2_CH1_PATH1HIQ_EN_RESET                                   0x1
#define MERLIN_RXTXBB2_CH1_PATH3LOQ_EN_LSB                                     3
#define MERLIN_RXTXBB2_CH1_PATH3LOQ_EN_MSB                                     3
#define MERLIN_RXTXBB2_CH1_PATH3LOQ_EN_MASK                                    0x8
#define MERLIN_RXTXBB2_CH1_PATH3LOQ_EN_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH1_PATH3LOQ_EN_MASK) >> MERLIN_RXTXBB2_CH1_PATH3LOQ_EN_LSB)
#define MERLIN_RXTXBB2_CH1_PATH3LOQ_EN_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH1_PATH3LOQ_EN_LSB) & MERLIN_RXTXBB2_CH1_PATH3LOQ_EN_MASK)
#define MERLIN_RXTXBB2_CH1_PATH3LOQ_EN_RESET                                   0x0
#define MERLIN_RXTXBB2_CH1_PATH2LOQ_EN_LSB                                     2
#define MERLIN_RXTXBB2_CH1_PATH2LOQ_EN_MSB                                     2
#define MERLIN_RXTXBB2_CH1_PATH2LOQ_EN_MASK                                    0x4
#define MERLIN_RXTXBB2_CH1_PATH2LOQ_EN_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH1_PATH2LOQ_EN_MASK) >> MERLIN_RXTXBB2_CH1_PATH2LOQ_EN_LSB)
#define MERLIN_RXTXBB2_CH1_PATH2LOQ_EN_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH1_PATH2LOQ_EN_LSB) & MERLIN_RXTXBB2_CH1_PATH2LOQ_EN_MASK)
#define MERLIN_RXTXBB2_CH1_PATH2LOQ_EN_RESET                                   0x0
#define MERLIN_RXTXBB2_CH1_PATH1LOQ_EN_LSB                                     1
#define MERLIN_RXTXBB2_CH1_PATH1LOQ_EN_MSB                                     1
#define MERLIN_RXTXBB2_CH1_PATH1LOQ_EN_MASK                                    0x2
#define MERLIN_RXTXBB2_CH1_PATH1LOQ_EN_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH1_PATH1LOQ_EN_MASK) >> MERLIN_RXTXBB2_CH1_PATH1LOQ_EN_LSB)
#define MERLIN_RXTXBB2_CH1_PATH1LOQ_EN_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH1_PATH1LOQ_EN_LSB) & MERLIN_RXTXBB2_CH1_PATH1LOQ_EN_MASK)
#define MERLIN_RXTXBB2_CH1_PATH1LOQ_EN_RESET                                   0x1
#define MERLIN_RXTXBB2_CH1_PATH_OVERRIDE_LSB                                   0
#define MERLIN_RXTXBB2_CH1_PATH_OVERRIDE_MSB                                   0
#define MERLIN_RXTXBB2_CH1_PATH_OVERRIDE_MASK                                  0x1
#define MERLIN_RXTXBB2_CH1_PATH_OVERRIDE_GET(x)                                (((x) & MERLIN_RXTXBB2_CH1_PATH_OVERRIDE_MASK) >> MERLIN_RXTXBB2_CH1_PATH_OVERRIDE_LSB)
#define MERLIN_RXTXBB2_CH1_PATH_OVERRIDE_SET(x)                                (((0 | (x)) << MERLIN_RXTXBB2_CH1_PATH_OVERRIDE_LSB) & MERLIN_RXTXBB2_CH1_PATH_OVERRIDE_MASK)
#define MERLIN_RXTXBB2_CH1_PATH_OVERRIDE_RESET                                 0x0
#define MERLIN_RXTXBB2_CH1_ADDRESS                                             (0x4 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RXTXBB2_CH1_RSTMASK                                             0xffffffff
#define MERLIN_RXTXBB2_CH1_RESET                                               0xdb003012

// 0x8 (MERLIN_RXTXBB3_CH1)
#define MERLIN_RXTXBB3_CH1_SPARE_LSB                                           27
#define MERLIN_RXTXBB3_CH1_SPARE_MSB                                           31
#define MERLIN_RXTXBB3_CH1_SPARE_MASK                                          0xf8000000
#define MERLIN_RXTXBB3_CH1_SPARE_GET(x)                                        (((x) & MERLIN_RXTXBB3_CH1_SPARE_MASK) >> MERLIN_RXTXBB3_CH1_SPARE_LSB)
#define MERLIN_RXTXBB3_CH1_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB3_CH1_SPARE_LSB) & MERLIN_RXTXBB3_CH1_SPARE_MASK)
#define MERLIN_RXTXBB3_CH1_SPARE_RESET                                         0x0
#define MERLIN_RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_LSB                          24
#define MERLIN_RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_MSB                          26
#define MERLIN_RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_MASK                         0x7000000
#define MERLIN_RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_GET(x)                       (((x) & MERLIN_RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_MASK) >> MERLIN_RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_LSB)
#define MERLIN_RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_SET(x)                       (((0 | (x)) << MERLIN_RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_LSB) & MERLIN_RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_MASK)
#define MERLIN_RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_RESET                        0x4
#define MERLIN_RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_LSB                              21
#define MERLIN_RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_MSB                              23
#define MERLIN_RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_MASK                             0xe00000
#define MERLIN_RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_GET(x)                           (((x) & MERLIN_RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_MASK) >> MERLIN_RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_LSB)
#define MERLIN_RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_SET(x)                           (((0 | (x)) << MERLIN_RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_LSB) & MERLIN_RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_MASK)
#define MERLIN_RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_RESET                            0x4
#define MERLIN_RXTXBB3_CH1_IBN_25U_I2V_CTRL_LSB                                18
#define MERLIN_RXTXBB3_CH1_IBN_25U_I2V_CTRL_MSB                                20
#define MERLIN_RXTXBB3_CH1_IBN_25U_I2V_CTRL_MASK                               0x1c0000
#define MERLIN_RXTXBB3_CH1_IBN_25U_I2V_CTRL_GET(x)                             (((x) & MERLIN_RXTXBB3_CH1_IBN_25U_I2V_CTRL_MASK) >> MERLIN_RXTXBB3_CH1_IBN_25U_I2V_CTRL_LSB)
#define MERLIN_RXTXBB3_CH1_IBN_25U_I2V_CTRL_SET(x)                             (((0 | (x)) << MERLIN_RXTXBB3_CH1_IBN_25U_I2V_CTRL_LSB) & MERLIN_RXTXBB3_CH1_IBN_25U_I2V_CTRL_MASK)
#define MERLIN_RXTXBB3_CH1_IBN_25U_I2V_CTRL_RESET                              0x4
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI1_CTRL_LSB                                15
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI1_CTRL_MSB                                17
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI1_CTRL_MASK                               0x38000
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI1_CTRL_GET(x)                             (((x) & MERLIN_RXTXBB3_CH1_IBN_25U_HI1_CTRL_MASK) >> MERLIN_RXTXBB3_CH1_IBN_25U_HI1_CTRL_LSB)
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI1_CTRL_SET(x)                             (((0 | (x)) << MERLIN_RXTXBB3_CH1_IBN_25U_HI1_CTRL_LSB) & MERLIN_RXTXBB3_CH1_IBN_25U_HI1_CTRL_MASK)
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI1_CTRL_RESET                              0x4
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI2_CTRL_LSB                                12
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI2_CTRL_MSB                                14
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI2_CTRL_MASK                               0x7000
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI2_CTRL_GET(x)                             (((x) & MERLIN_RXTXBB3_CH1_IBN_25U_HI2_CTRL_MASK) >> MERLIN_RXTXBB3_CH1_IBN_25U_HI2_CTRL_LSB)
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI2_CTRL_SET(x)                             (((0 | (x)) << MERLIN_RXTXBB3_CH1_IBN_25U_HI2_CTRL_LSB) & MERLIN_RXTXBB3_CH1_IBN_25U_HI2_CTRL_MASK)
#define MERLIN_RXTXBB3_CH1_IBN_25U_HI2_CTRL_RESET                              0x4
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO1_CTRL_LSB                                9
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO1_CTRL_MSB                                11
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO1_CTRL_MASK                               0xe00
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO1_CTRL_GET(x)                             (((x) & MERLIN_RXTXBB3_CH1_IBN_25U_LO1_CTRL_MASK) >> MERLIN_RXTXBB3_CH1_IBN_25U_LO1_CTRL_LSB)
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO1_CTRL_SET(x)                             (((0 | (x)) << MERLIN_RXTXBB3_CH1_IBN_25U_LO1_CTRL_LSB) & MERLIN_RXTXBB3_CH1_IBN_25U_LO1_CTRL_MASK)
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO1_CTRL_RESET                              0x4
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO2_CTRL_LSB                                6
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO2_CTRL_MSB                                8
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO2_CTRL_MASK                               0x1c0
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO2_CTRL_GET(x)                             (((x) & MERLIN_RXTXBB3_CH1_IBN_25U_LO2_CTRL_MASK) >> MERLIN_RXTXBB3_CH1_IBN_25U_LO2_CTRL_LSB)
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO2_CTRL_SET(x)                             (((0 | (x)) << MERLIN_RXTXBB3_CH1_IBN_25U_LO2_CTRL_LSB) & MERLIN_RXTXBB3_CH1_IBN_25U_LO2_CTRL_MASK)
#define MERLIN_RXTXBB3_CH1_IBN_25U_LO2_CTRL_RESET                              0x4
#define MERLIN_RXTXBB3_CH1_IBRN_12P5_CM_CTRL_LSB                               3
#define MERLIN_RXTXBB3_CH1_IBRN_12P5_CM_CTRL_MSB                               5
#define MERLIN_RXTXBB3_CH1_IBRN_12P5_CM_CTRL_MASK                              0x38
#define MERLIN_RXTXBB3_CH1_IBRN_12P5_CM_CTRL_GET(x)                            (((x) & MERLIN_RXTXBB3_CH1_IBRN_12P5_CM_CTRL_MASK) >> MERLIN_RXTXBB3_CH1_IBRN_12P5_CM_CTRL_LSB)
#define MERLIN_RXTXBB3_CH1_IBRN_12P5_CM_CTRL_SET(x)                            (((0 | (x)) << MERLIN_RXTXBB3_CH1_IBRN_12P5_CM_CTRL_LSB) & MERLIN_RXTXBB3_CH1_IBRN_12P5_CM_CTRL_MASK)
#define MERLIN_RXTXBB3_CH1_IBRN_12P5_CM_CTRL_RESET                             0x2
#define MERLIN_RXTXBB3_CH1_IBN_100U_TEST_CTRL_LSB                              0
#define MERLIN_RXTXBB3_CH1_IBN_100U_TEST_CTRL_MSB                              2
#define MERLIN_RXTXBB3_CH1_IBN_100U_TEST_CTRL_MASK                             0x7
#define MERLIN_RXTXBB3_CH1_IBN_100U_TEST_CTRL_GET(x)                           (((x) & MERLIN_RXTXBB3_CH1_IBN_100U_TEST_CTRL_MASK) >> MERLIN_RXTXBB3_CH1_IBN_100U_TEST_CTRL_LSB)
#define MERLIN_RXTXBB3_CH1_IBN_100U_TEST_CTRL_SET(x)                           (((0 | (x)) << MERLIN_RXTXBB3_CH1_IBN_100U_TEST_CTRL_LSB) & MERLIN_RXTXBB3_CH1_IBN_100U_TEST_CTRL_MASK)
#define MERLIN_RXTXBB3_CH1_IBN_100U_TEST_CTRL_RESET                            0x4
#define MERLIN_RXTXBB3_CH1_ADDRESS                                             (0x8 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RXTXBB3_CH1_RSTMASK                                             0xffffffff
#define MERLIN_RXTXBB3_CH1_RESET                                               0x4924914

// 0xc (MERLIN_RXTXBB4_CH1)
#define MERLIN_RXTXBB4_CH1_SPARE_LSB                                           31
#define MERLIN_RXTXBB4_CH1_SPARE_MSB                                           31
#define MERLIN_RXTXBB4_CH1_SPARE_MASK                                          0x80000000
#define MERLIN_RXTXBB4_CH1_SPARE_GET(x)                                        (((x) & MERLIN_RXTXBB4_CH1_SPARE_MASK) >> MERLIN_RXTXBB4_CH1_SPARE_LSB)
#define MERLIN_RXTXBB4_CH1_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB4_CH1_SPARE_LSB) & MERLIN_RXTXBB4_CH1_SPARE_MASK)
#define MERLIN_RXTXBB4_CH1_SPARE_RESET                                         0x0
#define MERLIN_RXTXBB4_CH1_LOCALOFFSET_LSB                                     30
#define MERLIN_RXTXBB4_CH1_LOCALOFFSET_MSB                                     30
#define MERLIN_RXTXBB4_CH1_LOCALOFFSET_MASK                                    0x40000000
#define MERLIN_RXTXBB4_CH1_LOCALOFFSET_GET(x)                                  (((x) & MERLIN_RXTXBB4_CH1_LOCALOFFSET_MASK) >> MERLIN_RXTXBB4_CH1_LOCALOFFSET_LSB)
#define MERLIN_RXTXBB4_CH1_LOCALOFFSET_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB4_CH1_LOCALOFFSET_LSB) & MERLIN_RXTXBB4_CH1_LOCALOFFSET_MASK)
#define MERLIN_RXTXBB4_CH1_LOCALOFFSET_RESET                                   0x0
#define MERLIN_RXTXBB4_CH1_OFSTCORRHII_LSB                                     25
#define MERLIN_RXTXBB4_CH1_OFSTCORRHII_MSB                                     29
#define MERLIN_RXTXBB4_CH1_OFSTCORRHII_MASK                                    0x3e000000
#define MERLIN_RXTXBB4_CH1_OFSTCORRHII_GET(x)                                  (((x) & MERLIN_RXTXBB4_CH1_OFSTCORRHII_MASK) >> MERLIN_RXTXBB4_CH1_OFSTCORRHII_LSB)
#define MERLIN_RXTXBB4_CH1_OFSTCORRHII_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB4_CH1_OFSTCORRHII_LSB) & MERLIN_RXTXBB4_CH1_OFSTCORRHII_MASK)
#define MERLIN_RXTXBB4_CH1_OFSTCORRHII_RESET                                   0x10
#define MERLIN_RXTXBB4_CH1_OFSTCORRHIQ_LSB                                     20
#define MERLIN_RXTXBB4_CH1_OFSTCORRHIQ_MSB                                     24
#define MERLIN_RXTXBB4_CH1_OFSTCORRHIQ_MASK                                    0x1f00000
#define MERLIN_RXTXBB4_CH1_OFSTCORRHIQ_GET(x)                                  (((x) & MERLIN_RXTXBB4_CH1_OFSTCORRHIQ_MASK) >> MERLIN_RXTXBB4_CH1_OFSTCORRHIQ_LSB)
#define MERLIN_RXTXBB4_CH1_OFSTCORRHIQ_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB4_CH1_OFSTCORRHIQ_LSB) & MERLIN_RXTXBB4_CH1_OFSTCORRHIQ_MASK)
#define MERLIN_RXTXBB4_CH1_OFSTCORRHIQ_RESET                                   0x10
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOI_LSB                                     15
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOI_MSB                                     19
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOI_MASK                                    0xf8000
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOI_GET(x)                                  (((x) & MERLIN_RXTXBB4_CH1_OFSTCORRLOI_MASK) >> MERLIN_RXTXBB4_CH1_OFSTCORRLOI_LSB)
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOI_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB4_CH1_OFSTCORRLOI_LSB) & MERLIN_RXTXBB4_CH1_OFSTCORRLOI_MASK)
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOI_RESET                                   0x10
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOQ_LSB                                     10
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOQ_MSB                                     14
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOQ_MASK                                    0x7c00
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOQ_GET(x)                                  (((x) & MERLIN_RXTXBB4_CH1_OFSTCORRLOQ_MASK) >> MERLIN_RXTXBB4_CH1_OFSTCORRLOQ_LSB)
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOQ_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB4_CH1_OFSTCORRLOQ_LSB) & MERLIN_RXTXBB4_CH1_OFSTCORRLOQ_MASK)
#define MERLIN_RXTXBB4_CH1_OFSTCORRLOQ_RESET                                   0x10
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VI_LSB                                    5
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VI_MSB                                    9
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VI_MASK                                   0x3e0
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VI_GET(x)                                 (((x) & MERLIN_RXTXBB4_CH1_OFSTCORRI2VI_MASK) >> MERLIN_RXTXBB4_CH1_OFSTCORRI2VI_LSB)
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VI_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB4_CH1_OFSTCORRI2VI_LSB) & MERLIN_RXTXBB4_CH1_OFSTCORRI2VI_MASK)
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VI_RESET                                  0x10
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VQ_LSB                                    0
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VQ_MSB                                    4
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VQ_MASK                                   0x1f
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VQ_GET(x)                                 (((x) & MERLIN_RXTXBB4_CH1_OFSTCORRI2VQ_MASK) >> MERLIN_RXTXBB4_CH1_OFSTCORRI2VQ_LSB)
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VQ_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB4_CH1_OFSTCORRI2VQ_LSB) & MERLIN_RXTXBB4_CH1_OFSTCORRI2VQ_MASK)
#define MERLIN_RXTXBB4_CH1_OFSTCORRI2VQ_RESET                                  0x10
#define MERLIN_RXTXBB4_CH1_ADDRESS                                             (0xc + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RXTXBB4_CH1_RSTMASK                                             0xffffffff
#define MERLIN_RXTXBB4_CH1_RESET                                               0x21084210

// 0x10 (MERLIN_RF2G1_CH1)
#define MERLIN_RF2G1_CH1_PDIC25U_LNA_LSB                                       29
#define MERLIN_RF2G1_CH1_PDIC25U_LNA_MSB                                       31
#define MERLIN_RF2G1_CH1_PDIC25U_LNA_MASK                                      0xe0000000
#define MERLIN_RF2G1_CH1_PDIC25U_LNA_GET(x)                                    (((x) & MERLIN_RF2G1_CH1_PDIC25U_LNA_MASK) >> MERLIN_RF2G1_CH1_PDIC25U_LNA_LSB)
#define MERLIN_RF2G1_CH1_PDIC25U_LNA_SET(x)                                    (((0 | (x)) << MERLIN_RF2G1_CH1_PDIC25U_LNA_LSB) & MERLIN_RF2G1_CH1_PDIC25U_LNA_MASK)
#define MERLIN_RF2G1_CH1_PDIC25U_LNA_RESET                                     0x3
#define MERLIN_RF2G1_CH1_DB_LSB                                                26
#define MERLIN_RF2G1_CH1_DB_MSB                                                28
#define MERLIN_RF2G1_CH1_DB_MASK                                               0x1c000000
#define MERLIN_RF2G1_CH1_DB_GET(x)                                             (((x) & MERLIN_RF2G1_CH1_DB_MASK) >> MERLIN_RF2G1_CH1_DB_LSB)
#define MERLIN_RF2G1_CH1_DB_SET(x)                                             (((0 | (x)) << MERLIN_RF2G1_CH1_DB_LSB) & MERLIN_RF2G1_CH1_DB_MASK)
#define MERLIN_RF2G1_CH1_DB_RESET                                              0x3
#define MERLIN_RF2G1_CH1_OB_LSB                                                23
#define MERLIN_RF2G1_CH1_OB_MSB                                                25
#define MERLIN_RF2G1_CH1_OB_MASK                                               0x3800000
#define MERLIN_RF2G1_CH1_OB_GET(x)                                             (((x) & MERLIN_RF2G1_CH1_OB_MASK) >> MERLIN_RF2G1_CH1_OB_LSB)
#define MERLIN_RF2G1_CH1_OB_SET(x)                                             (((0 | (x)) << MERLIN_RF2G1_CH1_OB_LSB) & MERLIN_RF2G1_CH1_OB_MASK)
#define MERLIN_RF2G1_CH1_OB_RESET                                              0x3
#define MERLIN_RF2G1_CH1_LOATB_SEL_LSB                                         20
#define MERLIN_RF2G1_CH1_LOATB_SEL_MSB                                         22
#define MERLIN_RF2G1_CH1_LOATB_SEL_MASK                                        0x700000
#define MERLIN_RF2G1_CH1_LOATB_SEL_GET(x)                                      (((x) & MERLIN_RF2G1_CH1_LOATB_SEL_MASK) >> MERLIN_RF2G1_CH1_LOATB_SEL_LSB)
#define MERLIN_RF2G1_CH1_LOATB_SEL_SET(x)                                      (((0 | (x)) << MERLIN_RF2G1_CH1_LOATB_SEL_LSB) & MERLIN_RF2G1_CH1_LOATB_SEL_MASK)
#define MERLIN_RF2G1_CH1_LOATB_SEL_RESET                                       0x0
#define MERLIN_RF2G1_CH1_RXATB_SEL_LSB                                         17
#define MERLIN_RF2G1_CH1_RXATB_SEL_MSB                                         19
#define MERLIN_RF2G1_CH1_RXATB_SEL_MASK                                        0xe0000
#define MERLIN_RF2G1_CH1_RXATB_SEL_GET(x)                                      (((x) & MERLIN_RF2G1_CH1_RXATB_SEL_MASK) >> MERLIN_RF2G1_CH1_RXATB_SEL_LSB)
#define MERLIN_RF2G1_CH1_RXATB_SEL_SET(x)                                      (((0 | (x)) << MERLIN_RF2G1_CH1_RXATB_SEL_LSB) & MERLIN_RF2G1_CH1_RXATB_SEL_MASK)
#define MERLIN_RF2G1_CH1_RXATB_SEL_RESET                                       0x0
#define MERLIN_RF2G1_CH1_TXATB_SEL_LSB                                         14
#define MERLIN_RF2G1_CH1_TXATB_SEL_MSB                                         16
#define MERLIN_RF2G1_CH1_TXATB_SEL_MASK                                        0x1c000
#define MERLIN_RF2G1_CH1_TXATB_SEL_GET(x)                                      (((x) & MERLIN_RF2G1_CH1_TXATB_SEL_MASK) >> MERLIN_RF2G1_CH1_TXATB_SEL_LSB)
#define MERLIN_RF2G1_CH1_TXATB_SEL_SET(x)                                      (((0 | (x)) << MERLIN_RF2G1_CH1_TXATB_SEL_LSB) & MERLIN_RF2G1_CH1_TXATB_SEL_MASK)
#define MERLIN_RF2G1_CH1_TXATB_SEL_RESET                                       0x0
#define MERLIN_RF2G1_CH1_LOCONTROL_LSB                                         13
#define MERLIN_RF2G1_CH1_LOCONTROL_MSB                                         13
#define MERLIN_RF2G1_CH1_LOCONTROL_MASK                                        0x2000
#define MERLIN_RF2G1_CH1_LOCONTROL_GET(x)                                      (((x) & MERLIN_RF2G1_CH1_LOCONTROL_MASK) >> MERLIN_RF2G1_CH1_LOCONTROL_LSB)
#define MERLIN_RF2G1_CH1_LOCONTROL_SET(x)                                      (((0 | (x)) << MERLIN_RF2G1_CH1_LOCONTROL_LSB) & MERLIN_RF2G1_CH1_LOCONTROL_MASK)
#define MERLIN_RF2G1_CH1_LOCONTROL_RESET                                       0x0
#define MERLIN_RF2G1_CH1_PACA_SEL_LSB                                          11
#define MERLIN_RF2G1_CH1_PACA_SEL_MSB                                          12
#define MERLIN_RF2G1_CH1_PACA_SEL_MASK                                         0x1800
#define MERLIN_RF2G1_CH1_PACA_SEL_GET(x)                                       (((x) & MERLIN_RF2G1_CH1_PACA_SEL_MASK) >> MERLIN_RF2G1_CH1_PACA_SEL_LSB)
#define MERLIN_RF2G1_CH1_PACA_SEL_SET(x)                                       (((0 | (x)) << MERLIN_RF2G1_CH1_PACA_SEL_LSB) & MERLIN_RF2G1_CH1_PACA_SEL_MASK)
#define MERLIN_RF2G1_CH1_PACA_SEL_RESET                                        0x2
#define MERLIN_RF2G1_CH1_PDIC25U_VGM_LSB                                       8
#define MERLIN_RF2G1_CH1_PDIC25U_VGM_MSB                                       10
#define MERLIN_RF2G1_CH1_PDIC25U_VGM_MASK                                      0x700
#define MERLIN_RF2G1_CH1_PDIC25U_VGM_GET(x)                                    (((x) & MERLIN_RF2G1_CH1_PDIC25U_VGM_MASK) >> MERLIN_RF2G1_CH1_PDIC25U_VGM_LSB)
#define MERLIN_RF2G1_CH1_PDIC25U_VGM_SET(x)                                    (((0 | (x)) << MERLIN_RF2G1_CH1_PDIC25U_VGM_LSB) & MERLIN_RF2G1_CH1_PDIC25U_VGM_MASK)
#define MERLIN_RF2G1_CH1_PDIC25U_VGM_RESET                                     0x3
#define MERLIN_RF2G1_CH1_REGLNA_BYPASS_LSB                                     7
#define MERLIN_RF2G1_CH1_REGLNA_BYPASS_MSB                                     7
#define MERLIN_RF2G1_CH1_REGLNA_BYPASS_MASK                                    0x80
#define MERLIN_RF2G1_CH1_REGLNA_BYPASS_GET(x)                                  (((x) & MERLIN_RF2G1_CH1_REGLNA_BYPASS_MASK) >> MERLIN_RF2G1_CH1_REGLNA_BYPASS_LSB)
#define MERLIN_RF2G1_CH1_REGLNA_BYPASS_SET(x)                                  (((0 | (x)) << MERLIN_RF2G1_CH1_REGLNA_BYPASS_LSB) & MERLIN_RF2G1_CH1_REGLNA_BYPASS_MASK)
#define MERLIN_RF2G1_CH1_REGLNA_BYPASS_RESET                                   0x0
#define MERLIN_RF2G1_CH1_REGLO_BYPASS_LSB                                      6
#define MERLIN_RF2G1_CH1_REGLO_BYPASS_MSB                                      6
#define MERLIN_RF2G1_CH1_REGLO_BYPASS_MASK                                     0x40
#define MERLIN_RF2G1_CH1_REGLO_BYPASS_GET(x)                                   (((x) & MERLIN_RF2G1_CH1_REGLO_BYPASS_MASK) >> MERLIN_RF2G1_CH1_REGLO_BYPASS_LSB)
#define MERLIN_RF2G1_CH1_REGLO_BYPASS_SET(x)                                   (((0 | (x)) << MERLIN_RF2G1_CH1_REGLO_BYPASS_LSB) & MERLIN_RF2G1_CH1_REGLO_BYPASS_MASK)
#define MERLIN_RF2G1_CH1_REGLO_BYPASS_RESET                                    0x0
#define MERLIN_RF2G1_CH1_SPARES_LSB                                            0
#define MERLIN_RF2G1_CH1_SPARES_MSB                                            5
#define MERLIN_RF2G1_CH1_SPARES_MASK                                           0x3f
#define MERLIN_RF2G1_CH1_SPARES_GET(x)                                         (((x) & MERLIN_RF2G1_CH1_SPARES_MASK) >> MERLIN_RF2G1_CH1_SPARES_LSB)
#define MERLIN_RF2G1_CH1_SPARES_SET(x)                                         (((0 | (x)) << MERLIN_RF2G1_CH1_SPARES_LSB) & MERLIN_RF2G1_CH1_SPARES_MASK)
#define MERLIN_RF2G1_CH1_SPARES_RESET                                          0x0
#define MERLIN_RF2G1_CH1_ADDRESS                                               (0x10 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RF2G1_CH1_RSTMASK                                               0xffffffff
#define MERLIN_RF2G1_CH1_RESET                                                 0x6d801300

// 0x14 (MERLIN_RF2G2_CH1)
#define MERLIN_RF2G2_CH1_PDLNA_LSB                                             31
#define MERLIN_RF2G2_CH1_PDLNA_MSB                                             31
#define MERLIN_RF2G2_CH1_PDLNA_MASK                                            0x80000000
#define MERLIN_RF2G2_CH1_PDLNA_GET(x)                                          (((x) & MERLIN_RF2G2_CH1_PDLNA_MASK) >> MERLIN_RF2G2_CH1_PDLNA_LSB)
#define MERLIN_RF2G2_CH1_PDLNA_SET(x)                                          (((0 | (x)) << MERLIN_RF2G2_CH1_PDLNA_LSB) & MERLIN_RF2G2_CH1_PDLNA_MASK)
#define MERLIN_RF2G2_CH1_PDLNA_RESET                                           0x0
#define MERLIN_RF2G2_CH1_PDDIV_LSB                                             30
#define MERLIN_RF2G2_CH1_PDDIV_MSB                                             30
#define MERLIN_RF2G2_CH1_PDDIV_MASK                                            0x40000000
#define MERLIN_RF2G2_CH1_PDDIV_GET(x)                                          (((x) & MERLIN_RF2G2_CH1_PDDIV_MASK) >> MERLIN_RF2G2_CH1_PDDIV_LSB)
#define MERLIN_RF2G2_CH1_PDDIV_SET(x)                                          (((0 | (x)) << MERLIN_RF2G2_CH1_PDDIV_LSB) & MERLIN_RF2G2_CH1_PDDIV_MASK)
#define MERLIN_RF2G2_CH1_PDDIV_RESET                                           0x0
#define MERLIN_RF2G2_CH1_PDPADRV_LSB                                           29
#define MERLIN_RF2G2_CH1_PDPADRV_MSB                                           29
#define MERLIN_RF2G2_CH1_PDPADRV_MASK                                          0x20000000
#define MERLIN_RF2G2_CH1_PDPADRV_GET(x)                                        (((x) & MERLIN_RF2G2_CH1_PDPADRV_MASK) >> MERLIN_RF2G2_CH1_PDPADRV_LSB)
#define MERLIN_RF2G2_CH1_PDPADRV_SET(x)                                        (((0 | (x)) << MERLIN_RF2G2_CH1_PDPADRV_LSB) & MERLIN_RF2G2_CH1_PDPADRV_MASK)
#define MERLIN_RF2G2_CH1_PDPADRV_RESET                                         0x0
#define MERLIN_RF2G2_CH1_PDPAOUT_LSB                                           28
#define MERLIN_RF2G2_CH1_PDPAOUT_MSB                                           28
#define MERLIN_RF2G2_CH1_PDPAOUT_MASK                                          0x10000000
#define MERLIN_RF2G2_CH1_PDPAOUT_GET(x)                                        (((x) & MERLIN_RF2G2_CH1_PDPAOUT_MASK) >> MERLIN_RF2G2_CH1_PDPAOUT_LSB)
#define MERLIN_RF2G2_CH1_PDPAOUT_SET(x)                                        (((0 | (x)) << MERLIN_RF2G2_CH1_PDPAOUT_LSB) & MERLIN_RF2G2_CH1_PDPAOUT_MASK)
#define MERLIN_RF2G2_CH1_PDPAOUT_RESET                                         0x0
#define MERLIN_RF2G2_CH1_PDREGLNA_LSB                                          27
#define MERLIN_RF2G2_CH1_PDREGLNA_MSB                                          27
#define MERLIN_RF2G2_CH1_PDREGLNA_MASK                                         0x8000000
#define MERLIN_RF2G2_CH1_PDREGLNA_GET(x)                                       (((x) & MERLIN_RF2G2_CH1_PDREGLNA_MASK) >> MERLIN_RF2G2_CH1_PDREGLNA_LSB)
#define MERLIN_RF2G2_CH1_PDREGLNA_SET(x)                                       (((0 | (x)) << MERLIN_RF2G2_CH1_PDREGLNA_LSB) & MERLIN_RF2G2_CH1_PDREGLNA_MASK)
#define MERLIN_RF2G2_CH1_PDREGLNA_RESET                                        0x0
#define MERLIN_RF2G2_CH1_PDREGLO_LSB                                           26
#define MERLIN_RF2G2_CH1_PDREGLO_MSB                                           26
#define MERLIN_RF2G2_CH1_PDREGLO_MASK                                          0x4000000
#define MERLIN_RF2G2_CH1_PDREGLO_GET(x)                                        (((x) & MERLIN_RF2G2_CH1_PDREGLO_MASK) >> MERLIN_RF2G2_CH1_PDREGLO_LSB)
#define MERLIN_RF2G2_CH1_PDREGLO_SET(x)                                        (((0 | (x)) << MERLIN_RF2G2_CH1_PDREGLO_LSB) & MERLIN_RF2G2_CH1_PDREGLO_MASK)
#define MERLIN_RF2G2_CH1_PDREGLO_RESET                                         0x0
#define MERLIN_RF2G2_CH1_PDVGM_LSB                                             25
#define MERLIN_RF2G2_CH1_PDVGM_MSB                                             25
#define MERLIN_RF2G2_CH1_PDVGM_MASK                                            0x2000000
#define MERLIN_RF2G2_CH1_PDVGM_GET(x)                                          (((x) & MERLIN_RF2G2_CH1_PDVGM_MASK) >> MERLIN_RF2G2_CH1_PDVGM_LSB)
#define MERLIN_RF2G2_CH1_PDVGM_SET(x)                                          (((0 | (x)) << MERLIN_RF2G2_CH1_PDVGM_LSB) & MERLIN_RF2G2_CH1_PDVGM_MASK)
#define MERLIN_RF2G2_CH1_PDVGM_RESET                                           0x0
#define MERLIN_RF2G2_CH1_PDRXLO_LSB                                            24
#define MERLIN_RF2G2_CH1_PDRXLO_MSB                                            24
#define MERLIN_RF2G2_CH1_PDRXLO_MASK                                           0x1000000
#define MERLIN_RF2G2_CH1_PDRXLO_GET(x)                                         (((x) & MERLIN_RF2G2_CH1_PDRXLO_MASK) >> MERLIN_RF2G2_CH1_PDRXLO_LSB)
#define MERLIN_RF2G2_CH1_PDRXLO_SET(x)                                         (((0 | (x)) << MERLIN_RF2G2_CH1_PDRXLO_LSB) & MERLIN_RF2G2_CH1_PDRXLO_MASK)
#define MERLIN_RF2G2_CH1_PDRXLO_RESET                                          0x0
#define MERLIN_RF2G2_CH1_PDTXLO_LSB                                            23
#define MERLIN_RF2G2_CH1_PDTXLO_MSB                                            23
#define MERLIN_RF2G2_CH1_PDTXLO_MASK                                           0x800000
#define MERLIN_RF2G2_CH1_PDTXLO_GET(x)                                         (((x) & MERLIN_RF2G2_CH1_PDTXLO_MASK) >> MERLIN_RF2G2_CH1_PDTXLO_LSB)
#define MERLIN_RF2G2_CH1_PDTXLO_SET(x)                                         (((0 | (x)) << MERLIN_RF2G2_CH1_PDTXLO_LSB) & MERLIN_RF2G2_CH1_PDTXLO_MASK)
#define MERLIN_RF2G2_CH1_PDTXLO_RESET                                          0x0
#define MERLIN_RF2G2_CH1_PDTXMIX_LSB                                           22
#define MERLIN_RF2G2_CH1_PDTXMIX_MSB                                           22
#define MERLIN_RF2G2_CH1_PDTXMIX_MASK                                          0x400000
#define MERLIN_RF2G2_CH1_PDTXMIX_GET(x)                                        (((x) & MERLIN_RF2G2_CH1_PDTXMIX_MASK) >> MERLIN_RF2G2_CH1_PDTXMIX_LSB)
#define MERLIN_RF2G2_CH1_PDTXMIX_SET(x)                                        (((0 | (x)) << MERLIN_RF2G2_CH1_PDTXMIX_LSB) & MERLIN_RF2G2_CH1_PDTXMIX_MASK)
#define MERLIN_RF2G2_CH1_PDTXMIX_RESET                                         0x0
#define MERLIN_RF2G2_CH1_PDIR25U_TXMIX_LSB                                     19
#define MERLIN_RF2G2_CH1_PDIR25U_TXMIX_MSB                                     21
#define MERLIN_RF2G2_CH1_PDIR25U_TXMIX_MASK                                    0x380000
#define MERLIN_RF2G2_CH1_PDIR25U_TXMIX_GET(x)                                  (((x) & MERLIN_RF2G2_CH1_PDIR25U_TXMIX_MASK) >> MERLIN_RF2G2_CH1_PDIR25U_TXMIX_LSB)
#define MERLIN_RF2G2_CH1_PDIR25U_TXMIX_SET(x)                                  (((0 | (x)) << MERLIN_RF2G2_CH1_PDIR25U_TXMIX_LSB) & MERLIN_RF2G2_CH1_PDIR25U_TXMIX_MASK)
#define MERLIN_RF2G2_CH1_PDIR25U_TXMIX_RESET                                   0x3
#define MERLIN_RF2G2_CH1_PDIR25U_TXPA_LSB                                      18
#define MERLIN_RF2G2_CH1_PDIR25U_TXPA_MSB                                      18
#define MERLIN_RF2G2_CH1_PDIR25U_TXPA_MASK                                     0x40000
#define MERLIN_RF2G2_CH1_PDIR25U_TXPA_GET(x)                                   (((x) & MERLIN_RF2G2_CH1_PDIR25U_TXPA_MASK) >> MERLIN_RF2G2_CH1_PDIR25U_TXPA_LSB)
#define MERLIN_RF2G2_CH1_PDIR25U_TXPA_SET(x)                                   (((0 | (x)) << MERLIN_RF2G2_CH1_PDIR25U_TXPA_LSB) & MERLIN_RF2G2_CH1_PDIR25U_TXPA_MASK)
#define MERLIN_RF2G2_CH1_PDIR25U_TXPA_RESET                                    0x0
#define MERLIN_RF2G2_CH1_PDIC25U_TXPA_LSB                                      15
#define MERLIN_RF2G2_CH1_PDIC25U_TXPA_MSB                                      17
#define MERLIN_RF2G2_CH1_PDIC25U_TXPA_MASK                                     0x38000
#define MERLIN_RF2G2_CH1_PDIC25U_TXPA_GET(x)                                   (((x) & MERLIN_RF2G2_CH1_PDIC25U_TXPA_MASK) >> MERLIN_RF2G2_CH1_PDIC25U_TXPA_LSB)
#define MERLIN_RF2G2_CH1_PDIC25U_TXPA_SET(x)                                   (((0 | (x)) << MERLIN_RF2G2_CH1_PDIC25U_TXPA_LSB) & MERLIN_RF2G2_CH1_PDIC25U_TXPA_MASK)
#define MERLIN_RF2G2_CH1_PDIC25U_TXPA_RESET                                    0x3
#define MERLIN_RF2G2_CH1_PDIC25U_TXRF_LSB                                      12
#define MERLIN_RF2G2_CH1_PDIC25U_TXRF_MSB                                      14
#define MERLIN_RF2G2_CH1_PDIC25U_TXRF_MASK                                     0x7000
#define MERLIN_RF2G2_CH1_PDIC25U_TXRF_GET(x)                                   (((x) & MERLIN_RF2G2_CH1_PDIC25U_TXRF_MASK) >> MERLIN_RF2G2_CH1_PDIC25U_TXRF_LSB)
#define MERLIN_RF2G2_CH1_PDIC25U_TXRF_SET(x)                                   (((0 | (x)) << MERLIN_RF2G2_CH1_PDIC25U_TXRF_LSB) & MERLIN_RF2G2_CH1_PDIC25U_TXRF_MASK)
#define MERLIN_RF2G2_CH1_PDIC25U_TXRF_RESET                                    0x3
#define MERLIN_RF2G2_CH1_PDIC25U_RXRF_LSB                                      9
#define MERLIN_RF2G2_CH1_PDIC25U_RXRF_MSB                                      11
#define MERLIN_RF2G2_CH1_PDIC25U_RXRF_MASK                                     0xe00
#define MERLIN_RF2G2_CH1_PDIC25U_RXRF_GET(x)                                   (((x) & MERLIN_RF2G2_CH1_PDIC25U_RXRF_MASK) >> MERLIN_RF2G2_CH1_PDIC25U_RXRF_LSB)
#define MERLIN_RF2G2_CH1_PDIC25U_RXRF_SET(x)                                   (((0 | (x)) << MERLIN_RF2G2_CH1_PDIC25U_RXRF_LSB) & MERLIN_RF2G2_CH1_PDIC25U_RXRF_MASK)
#define MERLIN_RF2G2_CH1_PDIC25U_RXRF_RESET                                    0x7
#define MERLIN_RF2G2_CH1_PDIC50U_DIV_LSB                                       6
#define MERLIN_RF2G2_CH1_PDIC50U_DIV_MSB                                       8
#define MERLIN_RF2G2_CH1_PDIC50U_DIV_MASK                                      0x1c0
#define MERLIN_RF2G2_CH1_PDIC50U_DIV_GET(x)                                    (((x) & MERLIN_RF2G2_CH1_PDIC50U_DIV_MASK) >> MERLIN_RF2G2_CH1_PDIC50U_DIV_LSB)
#define MERLIN_RF2G2_CH1_PDIC50U_DIV_SET(x)                                    (((0 | (x)) << MERLIN_RF2G2_CH1_PDIC50U_DIV_LSB) & MERLIN_RF2G2_CH1_PDIC50U_DIV_MASK)
#define MERLIN_RF2G2_CH1_PDIC50U_DIV_RESET                                     0x3
#define MERLIN_RF2G2_CH1_PDIC25U_VREGLO_LSB                                    3
#define MERLIN_RF2G2_CH1_PDIC25U_VREGLO_MSB                                    5
#define MERLIN_RF2G2_CH1_PDIC25U_VREGLO_MASK                                   0x38
#define MERLIN_RF2G2_CH1_PDIC25U_VREGLO_GET(x)                                 (((x) & MERLIN_RF2G2_CH1_PDIC25U_VREGLO_MASK) >> MERLIN_RF2G2_CH1_PDIC25U_VREGLO_LSB)
#define MERLIN_RF2G2_CH1_PDIC25U_VREGLO_SET(x)                                 (((0 | (x)) << MERLIN_RF2G2_CH1_PDIC25U_VREGLO_LSB) & MERLIN_RF2G2_CH1_PDIC25U_VREGLO_MASK)
#define MERLIN_RF2G2_CH1_PDIC25U_VREGLO_RESET                                  0x7
#define MERLIN_RF2G2_CH1_PDIR25U_VREGLO_LSB                                    0
#define MERLIN_RF2G2_CH1_PDIR25U_VREGLO_MSB                                    2
#define MERLIN_RF2G2_CH1_PDIR25U_VREGLO_MASK                                   0x7
#define MERLIN_RF2G2_CH1_PDIR25U_VREGLO_GET(x)                                 (((x) & MERLIN_RF2G2_CH1_PDIR25U_VREGLO_MASK) >> MERLIN_RF2G2_CH1_PDIR25U_VREGLO_LSB)
#define MERLIN_RF2G2_CH1_PDIR25U_VREGLO_SET(x)                                 (((0 | (x)) << MERLIN_RF2G2_CH1_PDIR25U_VREGLO_LSB) & MERLIN_RF2G2_CH1_PDIR25U_VREGLO_MASK)
#define MERLIN_RF2G2_CH1_PDIR25U_VREGLO_RESET                                  0x7
#define MERLIN_RF2G2_CH1_ADDRESS                                               (0x14 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RF2G2_CH1_RSTMASK                                               0xffffffff
#define MERLIN_RF2G2_CH1_RESET                                                 0x19beff

// 0x18 (MERLIN_RF5G1_CH1)
#define MERLIN_RF5G1_CH1_PDTXLO5_LSB                                           31
#define MERLIN_RF5G1_CH1_PDTXLO5_MSB                                           31
#define MERLIN_RF5G1_CH1_PDTXLO5_MASK                                          0x80000000
#define MERLIN_RF5G1_CH1_PDTXLO5_GET(x)                                        (((x) & MERLIN_RF5G1_CH1_PDTXLO5_MASK) >> MERLIN_RF5G1_CH1_PDTXLO5_LSB)
#define MERLIN_RF5G1_CH1_PDTXLO5_SET(x)                                        (((0 | (x)) << MERLIN_RF5G1_CH1_PDTXLO5_LSB) & MERLIN_RF5G1_CH1_PDTXLO5_MASK)
#define MERLIN_RF5G1_CH1_PDTXLO5_RESET                                         0x0
#define MERLIN_RF5G1_CH1_PDTXMIX5_LSB                                          30
#define MERLIN_RF5G1_CH1_PDTXMIX5_MSB                                          30
#define MERLIN_RF5G1_CH1_PDTXMIX5_MASK                                         0x40000000
#define MERLIN_RF5G1_CH1_PDTXMIX5_GET(x)                                       (((x) & MERLIN_RF5G1_CH1_PDTXMIX5_MASK) >> MERLIN_RF5G1_CH1_PDTXMIX5_LSB)
#define MERLIN_RF5G1_CH1_PDTXMIX5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH1_PDTXMIX5_LSB) & MERLIN_RF5G1_CH1_PDTXMIX5_MASK)
#define MERLIN_RF5G1_CH1_PDTXMIX5_RESET                                        0x0
#define MERLIN_RF5G1_CH1_PDTXBUF5_LSB                                          29
#define MERLIN_RF5G1_CH1_PDTXBUF5_MSB                                          29
#define MERLIN_RF5G1_CH1_PDTXBUF5_MASK                                         0x20000000
#define MERLIN_RF5G1_CH1_PDTXBUF5_GET(x)                                       (((x) & MERLIN_RF5G1_CH1_PDTXBUF5_MASK) >> MERLIN_RF5G1_CH1_PDTXBUF5_LSB)
#define MERLIN_RF5G1_CH1_PDTXBUF5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH1_PDTXBUF5_LSB) & MERLIN_RF5G1_CH1_PDTXBUF5_MASK)
#define MERLIN_RF5G1_CH1_PDTXBUF5_RESET                                        0x0
#define MERLIN_RF5G1_CH1_PDPADRV5_LSB                                          28
#define MERLIN_RF5G1_CH1_PDPADRV5_MSB                                          28
#define MERLIN_RF5G1_CH1_PDPADRV5_MASK                                         0x10000000
#define MERLIN_RF5G1_CH1_PDPADRV5_GET(x)                                       (((x) & MERLIN_RF5G1_CH1_PDPADRV5_MASK) >> MERLIN_RF5G1_CH1_PDPADRV5_LSB)
#define MERLIN_RF5G1_CH1_PDPADRV5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH1_PDPADRV5_LSB) & MERLIN_RF5G1_CH1_PDPADRV5_MASK)
#define MERLIN_RF5G1_CH1_PDPADRV5_RESET                                        0x0
#define MERLIN_RF5G1_CH1_PDPAOUT5_LSB                                          27
#define MERLIN_RF5G1_CH1_PDPAOUT5_MSB                                          27
#define MERLIN_RF5G1_CH1_PDPAOUT5_MASK                                         0x8000000
#define MERLIN_RF5G1_CH1_PDPAOUT5_GET(x)                                       (((x) & MERLIN_RF5G1_CH1_PDPAOUT5_MASK) >> MERLIN_RF5G1_CH1_PDPAOUT5_LSB)
#define MERLIN_RF5G1_CH1_PDPAOUT5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH1_PDPAOUT5_LSB) & MERLIN_RF5G1_CH1_PDPAOUT5_MASK)
#define MERLIN_RF5G1_CH1_PDPAOUT5_RESET                                        0x0
#define MERLIN_RF5G1_CH1_PACASCBIAS_LSB                                        25
#define MERLIN_RF5G1_CH1_PACASCBIAS_MSB                                        26
#define MERLIN_RF5G1_CH1_PACASCBIAS_MASK                                       0x6000000
#define MERLIN_RF5G1_CH1_PACASCBIAS_GET(x)                                     (((x) & MERLIN_RF5G1_CH1_PACASCBIAS_MASK) >> MERLIN_RF5G1_CH1_PACASCBIAS_LSB)
#define MERLIN_RF5G1_CH1_PACASCBIAS_SET(x)                                     (((0 | (x)) << MERLIN_RF5G1_CH1_PACASCBIAS_LSB) & MERLIN_RF5G1_CH1_PACASCBIAS_MASK)
#define MERLIN_RF5G1_CH1_PACASCBIAS_RESET                                      0x3
#define MERLIN_RF5G1_CH1_PWDTXPKD_LSB                                          22
#define MERLIN_RF5G1_CH1_PWDTXPKD_MSB                                          24
#define MERLIN_RF5G1_CH1_PWDTXPKD_MASK                                         0x1c00000
#define MERLIN_RF5G1_CH1_PWDTXPKD_GET(x)                                       (((x) & MERLIN_RF5G1_CH1_PWDTXPKD_MASK) >> MERLIN_RF5G1_CH1_PWDTXPKD_LSB)
#define MERLIN_RF5G1_CH1_PWDTXPKD_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH1_PWDTXPKD_LSB) & MERLIN_RF5G1_CH1_PWDTXPKD_MASK)
#define MERLIN_RF5G1_CH1_PWDTXPKD_RESET                                        0x7
#define MERLIN_RF5G1_CH1_DB5_LSB                                               19
#define MERLIN_RF5G1_CH1_DB5_MSB                                               21
#define MERLIN_RF5G1_CH1_DB5_MASK                                              0x380000
#define MERLIN_RF5G1_CH1_DB5_GET(x)                                            (((x) & MERLIN_RF5G1_CH1_DB5_MASK) >> MERLIN_RF5G1_CH1_DB5_LSB)
#define MERLIN_RF5G1_CH1_DB5_SET(x)                                            (((0 | (x)) << MERLIN_RF5G1_CH1_DB5_LSB) & MERLIN_RF5G1_CH1_DB5_MASK)
#define MERLIN_RF5G1_CH1_DB5_RESET                                             0x4
#define MERLIN_RF5G1_CH1_OB5_LSB                                               16
#define MERLIN_RF5G1_CH1_OB5_MSB                                               18
#define MERLIN_RF5G1_CH1_OB5_MASK                                              0x70000
#define MERLIN_RF5G1_CH1_OB5_GET(x)                                            (((x) & MERLIN_RF5G1_CH1_OB5_MASK) >> MERLIN_RF5G1_CH1_OB5_LSB)
#define MERLIN_RF5G1_CH1_OB5_SET(x)                                            (((0 | (x)) << MERLIN_RF5G1_CH1_OB5_LSB) & MERLIN_RF5G1_CH1_OB5_MASK)
#define MERLIN_RF5G1_CH1_OB5_RESET                                             0x4
#define MERLIN_RF5G1_CH1_TX5_ATB_SEL_LSB                                       13
#define MERLIN_RF5G1_CH1_TX5_ATB_SEL_MSB                                       15
#define MERLIN_RF5G1_CH1_TX5_ATB_SEL_MASK                                      0xe000
#define MERLIN_RF5G1_CH1_TX5_ATB_SEL_GET(x)                                    (((x) & MERLIN_RF5G1_CH1_TX5_ATB_SEL_MASK) >> MERLIN_RF5G1_CH1_TX5_ATB_SEL_LSB)
#define MERLIN_RF5G1_CH1_TX5_ATB_SEL_SET(x)                                    (((0 | (x)) << MERLIN_RF5G1_CH1_TX5_ATB_SEL_LSB) & MERLIN_RF5G1_CH1_TX5_ATB_SEL_MASK)
#define MERLIN_RF5G1_CH1_TX5_ATB_SEL_RESET                                     0x0
#define MERLIN_RF5G1_CH1_LO5CONTROL_LSB                                        12
#define MERLIN_RF5G1_CH1_LO5CONTROL_MSB                                        12
#define MERLIN_RF5G1_CH1_LO5CONTROL_MASK                                       0x1000
#define MERLIN_RF5G1_CH1_LO5CONTROL_GET(x)                                     (((x) & MERLIN_RF5G1_CH1_LO5CONTROL_MASK) >> MERLIN_RF5G1_CH1_LO5CONTROL_LSB)
#define MERLIN_RF5G1_CH1_LO5CONTROL_SET(x)                                     (((0 | (x)) << MERLIN_RF5G1_CH1_LO5CONTROL_LSB) & MERLIN_RF5G1_CH1_LO5CONTROL_MASK)
#define MERLIN_RF5G1_CH1_LO5CONTROL_RESET                                      0x0
#define MERLIN_RF5G1_CH1_REGLO_BYPASS5_LSB                                     11
#define MERLIN_RF5G1_CH1_REGLO_BYPASS5_MSB                                     11
#define MERLIN_RF5G1_CH1_REGLO_BYPASS5_MASK                                    0x800
#define MERLIN_RF5G1_CH1_REGLO_BYPASS5_GET(x)                                  (((x) & MERLIN_RF5G1_CH1_REGLO_BYPASS5_MASK) >> MERLIN_RF5G1_CH1_REGLO_BYPASS5_LSB)
#define MERLIN_RF5G1_CH1_REGLO_BYPASS5_SET(x)                                  (((0 | (x)) << MERLIN_RF5G1_CH1_REGLO_BYPASS5_LSB) & MERLIN_RF5G1_CH1_REGLO_BYPASS5_MASK)
#define MERLIN_RF5G1_CH1_REGLO_BYPASS5_RESET                                   0x0
#define MERLIN_RF5G1_CH1_PDREGLO5_LSB                                          10
#define MERLIN_RF5G1_CH1_PDREGLO5_MSB                                          10
#define MERLIN_RF5G1_CH1_PDREGLO5_MASK                                         0x400
#define MERLIN_RF5G1_CH1_PDREGLO5_GET(x)                                       (((x) & MERLIN_RF5G1_CH1_PDREGLO5_MASK) >> MERLIN_RF5G1_CH1_PDREGLO5_LSB)
#define MERLIN_RF5G1_CH1_PDREGLO5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH1_PDREGLO5_LSB) & MERLIN_RF5G1_CH1_PDREGLO5_MASK)
#define MERLIN_RF5G1_CH1_PDREGLO5_RESET                                        0x0
#define MERLIN_RF5G1_CH1_SPARE_LSB                                             0
#define MERLIN_RF5G1_CH1_SPARE_MSB                                             9
#define MERLIN_RF5G1_CH1_SPARE_MASK                                            0x3ff
#define MERLIN_RF5G1_CH1_SPARE_GET(x)                                          (((x) & MERLIN_RF5G1_CH1_SPARE_MASK) >> MERLIN_RF5G1_CH1_SPARE_LSB)
#define MERLIN_RF5G1_CH1_SPARE_SET(x)                                          (((0 | (x)) << MERLIN_RF5G1_CH1_SPARE_LSB) & MERLIN_RF5G1_CH1_SPARE_MASK)
#define MERLIN_RF5G1_CH1_SPARE_RESET                                           0x0
#define MERLIN_RF5G1_CH1_ADDRESS                                               (0x18 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RF5G1_CH1_RSTMASK                                               0xffffffff
#define MERLIN_RF5G1_CH1_RESET                                                 0x7e40000

// 0x1c (MERLIN_RF5G2_CH1)
#define MERLIN_RF5G2_CH1_REGFE_BYPASS5_LSB                                     31
#define MERLIN_RF5G2_CH1_REGFE_BYPASS5_MSB                                     31
#define MERLIN_RF5G2_CH1_REGFE_BYPASS5_MASK                                    0x80000000
#define MERLIN_RF5G2_CH1_REGFE_BYPASS5_GET(x)                                  (((x) & MERLIN_RF5G2_CH1_REGFE_BYPASS5_MASK) >> MERLIN_RF5G2_CH1_REGFE_BYPASS5_LSB)
#define MERLIN_RF5G2_CH1_REGFE_BYPASS5_SET(x)                                  (((0 | (x)) << MERLIN_RF5G2_CH1_REGFE_BYPASS5_LSB) & MERLIN_RF5G2_CH1_REGFE_BYPASS5_MASK)
#define MERLIN_RF5G2_CH1_REGFE_BYPASS5_RESET                                   0x0
#define MERLIN_RF5G2_CH1_PDREGFE5_LSB                                          30
#define MERLIN_RF5G2_CH1_PDREGFE5_MSB                                          30
#define MERLIN_RF5G2_CH1_PDREGFE5_MASK                                         0x40000000
#define MERLIN_RF5G2_CH1_PDREGFE5_GET(x)                                       (((x) & MERLIN_RF5G2_CH1_PDREGFE5_MASK) >> MERLIN_RF5G2_CH1_PDREGFE5_LSB)
#define MERLIN_RF5G2_CH1_PDREGFE5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G2_CH1_PDREGFE5_LSB) & MERLIN_RF5G2_CH1_PDREGFE5_MASK)
#define MERLIN_RF5G2_CH1_PDREGFE5_RESET                                        0x0
#define MERLIN_RF5G2_CH1_PDRXLO5_LSB                                           29
#define MERLIN_RF5G2_CH1_PDRXLO5_MSB                                           29
#define MERLIN_RF5G2_CH1_PDRXLO5_MASK                                          0x20000000
#define MERLIN_RF5G2_CH1_PDRXLO5_GET(x)                                        (((x) & MERLIN_RF5G2_CH1_PDRXLO5_MASK) >> MERLIN_RF5G2_CH1_PDRXLO5_LSB)
#define MERLIN_RF5G2_CH1_PDRXLO5_SET(x)                                        (((0 | (x)) << MERLIN_RF5G2_CH1_PDRXLO5_LSB) & MERLIN_RF5G2_CH1_PDRXLO5_MASK)
#define MERLIN_RF5G2_CH1_PDRXLO5_RESET                                         0x0
#define MERLIN_RF5G2_CH1_PDVGM5_LSB                                            28
#define MERLIN_RF5G2_CH1_PDVGM5_MSB                                            28
#define MERLIN_RF5G2_CH1_PDVGM5_MASK                                           0x10000000
#define MERLIN_RF5G2_CH1_PDVGM5_GET(x)                                         (((x) & MERLIN_RF5G2_CH1_PDVGM5_MASK) >> MERLIN_RF5G2_CH1_PDVGM5_LSB)
#define MERLIN_RF5G2_CH1_PDVGM5_SET(x)                                         (((0 | (x)) << MERLIN_RF5G2_CH1_PDVGM5_LSB) & MERLIN_RF5G2_CH1_PDVGM5_MASK)
#define MERLIN_RF5G2_CH1_PDVGM5_RESET                                          0x0
#define MERLIN_RF5G2_CH1_PDCSLNA5_LSB                                          27
#define MERLIN_RF5G2_CH1_PDCSLNA5_MSB                                          27
#define MERLIN_RF5G2_CH1_PDCSLNA5_MASK                                         0x8000000
#define MERLIN_RF5G2_CH1_PDCSLNA5_GET(x)                                       (((x) & MERLIN_RF5G2_CH1_PDCSLNA5_MASK) >> MERLIN_RF5G2_CH1_PDCSLNA5_LSB)
#define MERLIN_RF5G2_CH1_PDCSLNA5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G2_CH1_PDCSLNA5_LSB) & MERLIN_RF5G2_CH1_PDCSLNA5_MASK)
#define MERLIN_RF5G2_CH1_PDCSLNA5_RESET                                        0x0
#define MERLIN_RF5G2_CH1_PDRFVGA5_LSB                                          26
#define MERLIN_RF5G2_CH1_PDRFVGA5_MSB                                          26
#define MERLIN_RF5G2_CH1_PDRFVGA5_MASK                                         0x4000000
#define MERLIN_RF5G2_CH1_PDRFVGA5_GET(x)                                       (((x) & MERLIN_RF5G2_CH1_PDRFVGA5_MASK) >> MERLIN_RF5G2_CH1_PDRFVGA5_LSB)
#define MERLIN_RF5G2_CH1_PDRFVGA5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G2_CH1_PDRFVGA5_LSB) & MERLIN_RF5G2_CH1_PDRFVGA5_MASK)
#define MERLIN_RF5G2_CH1_PDRFVGA5_RESET                                        0x0
#define MERLIN_RF5G2_CH1_RX5_ATB_SEL_LSB                                       23
#define MERLIN_RF5G2_CH1_RX5_ATB_SEL_MSB                                       25
#define MERLIN_RF5G2_CH1_RX5_ATB_SEL_MASK                                      0x3800000
#define MERLIN_RF5G2_CH1_RX5_ATB_SEL_GET(x)                                    (((x) & MERLIN_RF5G2_CH1_RX5_ATB_SEL_MASK) >> MERLIN_RF5G2_CH1_RX5_ATB_SEL_LSB)
#define MERLIN_RF5G2_CH1_RX5_ATB_SEL_SET(x)                                    (((0 | (x)) << MERLIN_RF5G2_CH1_RX5_ATB_SEL_LSB) & MERLIN_RF5G2_CH1_RX5_ATB_SEL_MASK)
#define MERLIN_RF5G2_CH1_RX5_ATB_SEL_RESET                                     0x0
#define MERLIN_RF5G2_CH1_PDBIRTXMIX_LSB                                        20
#define MERLIN_RF5G2_CH1_PDBIRTXMIX_MSB                                        22
#define MERLIN_RF5G2_CH1_PDBIRTXMIX_MASK                                       0x700000
#define MERLIN_RF5G2_CH1_PDBIRTXMIX_GET(x)                                     (((x) & MERLIN_RF5G2_CH1_PDBIRTXMIX_MASK) >> MERLIN_RF5G2_CH1_PDBIRTXMIX_LSB)
#define MERLIN_RF5G2_CH1_PDBIRTXMIX_SET(x)                                     (((0 | (x)) << MERLIN_RF5G2_CH1_PDBIRTXMIX_LSB) & MERLIN_RF5G2_CH1_PDBIRTXMIX_MASK)
#define MERLIN_RF5G2_CH1_PDBIRTXMIX_RESET                                      0x4
#define MERLIN_RF5G2_CH1_PDBIRTXPA_LSB                                         17
#define MERLIN_RF5G2_CH1_PDBIRTXPA_MSB                                         19
#define MERLIN_RF5G2_CH1_PDBIRTXPA_MASK                                        0xe0000
#define MERLIN_RF5G2_CH1_PDBIRTXPA_GET(x)                                      (((x) & MERLIN_RF5G2_CH1_PDBIRTXPA_MASK) >> MERLIN_RF5G2_CH1_PDBIRTXPA_LSB)
#define MERLIN_RF5G2_CH1_PDBIRTXPA_SET(x)                                      (((0 | (x)) << MERLIN_RF5G2_CH1_PDBIRTXPA_LSB) & MERLIN_RF5G2_CH1_PDBIRTXPA_MASK)
#define MERLIN_RF5G2_CH1_PDBIRTXPA_RESET                                       0x4
#define MERLIN_RF5G2_CH1_PDBIR1_LSB                                            14
#define MERLIN_RF5G2_CH1_PDBIR1_MSB                                            16
#define MERLIN_RF5G2_CH1_PDBIR1_MASK                                           0x1c000
#define MERLIN_RF5G2_CH1_PDBIR1_GET(x)                                         (((x) & MERLIN_RF5G2_CH1_PDBIR1_MASK) >> MERLIN_RF5G2_CH1_PDBIR1_LSB)
#define MERLIN_RF5G2_CH1_PDBIR1_SET(x)                                         (((0 | (x)) << MERLIN_RF5G2_CH1_PDBIR1_LSB) & MERLIN_RF5G2_CH1_PDBIR1_MASK)
#define MERLIN_RF5G2_CH1_PDBIR1_RESET                                          0x4
#define MERLIN_RF5G2_CH1_PDBIR2_LSB                                            11
#define MERLIN_RF5G2_CH1_PDBIR2_MSB                                            13
#define MERLIN_RF5G2_CH1_PDBIR2_MASK                                           0x3800
#define MERLIN_RF5G2_CH1_PDBIR2_GET(x)                                         (((x) & MERLIN_RF5G2_CH1_PDBIR2_MASK) >> MERLIN_RF5G2_CH1_PDBIR2_LSB)
#define MERLIN_RF5G2_CH1_PDBIR2_SET(x)                                         (((0 | (x)) << MERLIN_RF5G2_CH1_PDBIR2_LSB) & MERLIN_RF5G2_CH1_PDBIR2_MASK)
#define MERLIN_RF5G2_CH1_PDBIR2_RESET                                          0x4
#define MERLIN_RF5G2_CH1_SPARE_LSB                                             0
#define MERLIN_RF5G2_CH1_SPARE_MSB                                             10
#define MERLIN_RF5G2_CH1_SPARE_MASK                                            0x7ff
#define MERLIN_RF5G2_CH1_SPARE_GET(x)                                          (((x) & MERLIN_RF5G2_CH1_SPARE_MASK) >> MERLIN_RF5G2_CH1_SPARE_LSB)
#define MERLIN_RF5G2_CH1_SPARE_SET(x)                                          (((0 | (x)) << MERLIN_RF5G2_CH1_SPARE_LSB) & MERLIN_RF5G2_CH1_SPARE_MASK)
#define MERLIN_RF5G2_CH1_SPARE_RESET                                           0x0
#define MERLIN_RF5G2_CH1_ADDRESS                                               (0x1c + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RF5G2_CH1_RSTMASK                                               0xffffffff
#define MERLIN_RF5G2_CH1_RESET                                                 0x492000

// 0x20 (MERLIN_RF5G3_CH1)
#define MERLIN_RF5G3_CH1_PDBICTXBUF_LSB                                        29
#define MERLIN_RF5G3_CH1_PDBICTXBUF_MSB                                        31
#define MERLIN_RF5G3_CH1_PDBICTXBUF_MASK                                       0xe0000000
#define MERLIN_RF5G3_CH1_PDBICTXBUF_GET(x)                                     (((x) & MERLIN_RF5G3_CH1_PDBICTXBUF_MASK) >> MERLIN_RF5G3_CH1_PDBICTXBUF_LSB)
#define MERLIN_RF5G3_CH1_PDBICTXBUF_SET(x)                                     (((0 | (x)) << MERLIN_RF5G3_CH1_PDBICTXBUF_LSB) & MERLIN_RF5G3_CH1_PDBICTXBUF_MASK)
#define MERLIN_RF5G3_CH1_PDBICTXBUF_RESET                                      0x4
#define MERLIN_RF5G3_CH1_PDBICTXPA_LSB                                         26
#define MERLIN_RF5G3_CH1_PDBICTXPA_MSB                                         28
#define MERLIN_RF5G3_CH1_PDBICTXPA_MASK                                        0x1c000000
#define MERLIN_RF5G3_CH1_PDBICTXPA_GET(x)                                      (((x) & MERLIN_RF5G3_CH1_PDBICTXPA_MASK) >> MERLIN_RF5G3_CH1_PDBICTXPA_LSB)
#define MERLIN_RF5G3_CH1_PDBICTXPA_SET(x)                                      (((0 | (x)) << MERLIN_RF5G3_CH1_PDBICTXPA_LSB) & MERLIN_RF5G3_CH1_PDBICTXPA_MASK)
#define MERLIN_RF5G3_CH1_PDBICTXPA_RESET                                       0x4
#define MERLIN_RF5G3_CH1_PDBICTXMIX_LSB                                        23
#define MERLIN_RF5G3_CH1_PDBICTXMIX_MSB                                        25
#define MERLIN_RF5G3_CH1_PDBICTXMIX_MASK                                       0x3800000
#define MERLIN_RF5G3_CH1_PDBICTXMIX_GET(x)                                     (((x) & MERLIN_RF5G3_CH1_PDBICTXMIX_MASK) >> MERLIN_RF5G3_CH1_PDBICTXMIX_LSB)
#define MERLIN_RF5G3_CH1_PDBICTXMIX_SET(x)                                     (((0 | (x)) << MERLIN_RF5G3_CH1_PDBICTXMIX_LSB) & MERLIN_RF5G3_CH1_PDBICTXMIX_MASK)
#define MERLIN_RF5G3_CH1_PDBICTXMIX_RESET                                      0x4
#define MERLIN_RF5G3_CH1_PDBIC1_LSB                                            20
#define MERLIN_RF5G3_CH1_PDBIC1_MSB                                            22
#define MERLIN_RF5G3_CH1_PDBIC1_MASK                                           0x700000
#define MERLIN_RF5G3_CH1_PDBIC1_GET(x)                                         (((x) & MERLIN_RF5G3_CH1_PDBIC1_MASK) >> MERLIN_RF5G3_CH1_PDBIC1_LSB)
#define MERLIN_RF5G3_CH1_PDBIC1_SET(x)                                         (((0 | (x)) << MERLIN_RF5G3_CH1_PDBIC1_LSB) & MERLIN_RF5G3_CH1_PDBIC1_MASK)
#define MERLIN_RF5G3_CH1_PDBIC1_RESET                                          0x4
#define MERLIN_RF5G3_CH1_PDBIC2_LSB                                            17
#define MERLIN_RF5G3_CH1_PDBIC2_MSB                                            19
#define MERLIN_RF5G3_CH1_PDBIC2_MASK                                           0xe0000
#define MERLIN_RF5G3_CH1_PDBIC2_GET(x)                                         (((x) & MERLIN_RF5G3_CH1_PDBIC2_MASK) >> MERLIN_RF5G3_CH1_PDBIC2_LSB)
#define MERLIN_RF5G3_CH1_PDBIC2_SET(x)                                         (((0 | (x)) << MERLIN_RF5G3_CH1_PDBIC2_LSB) & MERLIN_RF5G3_CH1_PDBIC2_MASK)
#define MERLIN_RF5G3_CH1_PDBIC2_RESET                                          0x4
#define MERLIN_RF5G3_CH1_PDBIC3_LSB                                            14
#define MERLIN_RF5G3_CH1_PDBIC3_MSB                                            16
#define MERLIN_RF5G3_CH1_PDBIC3_MASK                                           0x1c000
#define MERLIN_RF5G3_CH1_PDBIC3_GET(x)                                         (((x) & MERLIN_RF5G3_CH1_PDBIC3_MASK) >> MERLIN_RF5G3_CH1_PDBIC3_LSB)
#define MERLIN_RF5G3_CH1_PDBIC3_SET(x)                                         (((0 | (x)) << MERLIN_RF5G3_CH1_PDBIC3_LSB) & MERLIN_RF5G3_CH1_PDBIC3_MASK)
#define MERLIN_RF5G3_CH1_PDBIC3_RESET                                          0x4
#define MERLIN_RF5G3_CH1_PDBIBCLNA_LSB                                         11
#define MERLIN_RF5G3_CH1_PDBIBCLNA_MSB                                         13
#define MERLIN_RF5G3_CH1_PDBIBCLNA_MASK                                        0x3800
#define MERLIN_RF5G3_CH1_PDBIBCLNA_GET(x)                                      (((x) & MERLIN_RF5G3_CH1_PDBIBCLNA_MASK) >> MERLIN_RF5G3_CH1_PDBIBCLNA_LSB)
#define MERLIN_RF5G3_CH1_PDBIBCLNA_SET(x)                                      (((0 | (x)) << MERLIN_RF5G3_CH1_PDBIBCLNA_LSB) & MERLIN_RF5G3_CH1_PDBIBCLNA_MASK)
#define MERLIN_RF5G3_CH1_PDBIBCLNA_RESET                                       0x4
#define MERLIN_RF5G3_CH1_PDBIBCRFVGA_LSB                                       8
#define MERLIN_RF5G3_CH1_PDBIBCRFVGA_MSB                                       10
#define MERLIN_RF5G3_CH1_PDBIBCRFVGA_MASK                                      0x700
#define MERLIN_RF5G3_CH1_PDBIBCRFVGA_GET(x)                                    (((x) & MERLIN_RF5G3_CH1_PDBIBCRFVGA_MASK) >> MERLIN_RF5G3_CH1_PDBIBCRFVGA_LSB)
#define MERLIN_RF5G3_CH1_PDBIBCRFVGA_SET(x)                                    (((0 | (x)) << MERLIN_RF5G3_CH1_PDBIBCRFVGA_LSB) & MERLIN_RF5G3_CH1_PDBIBCRFVGA_MASK)
#define MERLIN_RF5G3_CH1_PDBIBCRFVGA_RESET                                     0x4
#define MERLIN_RF5G3_CH1_PDBIBCVGM_LSB                                         5
#define MERLIN_RF5G3_CH1_PDBIBCVGM_MSB                                         7
#define MERLIN_RF5G3_CH1_PDBIBCVGM_MASK                                        0xe0
#define MERLIN_RF5G3_CH1_PDBIBCVGM_GET(x)                                      (((x) & MERLIN_RF5G3_CH1_PDBIBCVGM_MASK) >> MERLIN_RF5G3_CH1_PDBIBCVGM_LSB)
#define MERLIN_RF5G3_CH1_PDBIBCVGM_SET(x)                                      (((0 | (x)) << MERLIN_RF5G3_CH1_PDBIBCVGM_LSB) & MERLIN_RF5G3_CH1_PDBIBCVGM_MASK)
#define MERLIN_RF5G3_CH1_PDBIBCVGM_RESET                                       0x4
#define MERLIN_RF5G3_CH1_SPARE_LSB                                             0
#define MERLIN_RF5G3_CH1_SPARE_MSB                                             4
#define MERLIN_RF5G3_CH1_SPARE_MASK                                            0x1f
#define MERLIN_RF5G3_CH1_SPARE_GET(x)                                          (((x) & MERLIN_RF5G3_CH1_SPARE_MASK) >> MERLIN_RF5G3_CH1_SPARE_LSB)
#define MERLIN_RF5G3_CH1_SPARE_SET(x)                                          (((0 | (x)) << MERLIN_RF5G3_CH1_SPARE_LSB) & MERLIN_RF5G3_CH1_SPARE_MASK)
#define MERLIN_RF5G3_CH1_SPARE_RESET                                           0x0
#define MERLIN_RF5G3_CH1_ADDRESS                                               (0x20 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RF5G3_CH1_RSTMASK                                               0xffffffff
#define MERLIN_RF5G3_CH1_RESET                                                 0x92492480

// 0x24 (MERLIN_RXTXBB1_CH0)
#define MERLIN_RXTXBB1_CH0_SPARE_LSB                                           19
#define MERLIN_RXTXBB1_CH0_SPARE_MSB                                           31
#define MERLIN_RXTXBB1_CH0_SPARE_MASK                                          0xfff80000
#define MERLIN_RXTXBB1_CH0_SPARE_GET(x)                                        (((x) & MERLIN_RXTXBB1_CH0_SPARE_MASK) >> MERLIN_RXTXBB1_CH0_SPARE_LSB)
#define MERLIN_RXTXBB1_CH0_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB1_CH0_SPARE_LSB) & MERLIN_RXTXBB1_CH0_SPARE_MASK)
#define MERLIN_RXTXBB1_CH0_SPARE_RESET                                         0x0
#define MERLIN_RXTXBB1_CH0_FNOTCH_LSB                                          17
#define MERLIN_RXTXBB1_CH0_FNOTCH_MSB                                          18
#define MERLIN_RXTXBB1_CH0_FNOTCH_MASK                                         0x60000
#define MERLIN_RXTXBB1_CH0_FNOTCH_GET(x)                                       (((x) & MERLIN_RXTXBB1_CH0_FNOTCH_MASK) >> MERLIN_RXTXBB1_CH0_FNOTCH_LSB)
#define MERLIN_RXTXBB1_CH0_FNOTCH_SET(x)                                       (((0 | (x)) << MERLIN_RXTXBB1_CH0_FNOTCH_LSB) & MERLIN_RXTXBB1_CH0_FNOTCH_MASK)
#define MERLIN_RXTXBB1_CH0_FNOTCH_RESET                                        0x0
#define MERLIN_RXTXBB1_CH0_SEL_ATB_LSB                                         9
#define MERLIN_RXTXBB1_CH0_SEL_ATB_MSB                                         16
#define MERLIN_RXTXBB1_CH0_SEL_ATB_MASK                                        0x1fe00
#define MERLIN_RXTXBB1_CH0_SEL_ATB_GET(x)                                      (((x) & MERLIN_RXTXBB1_CH0_SEL_ATB_MASK) >> MERLIN_RXTXBB1_CH0_SEL_ATB_LSB)
#define MERLIN_RXTXBB1_CH0_SEL_ATB_SET(x)                                      (((0 | (x)) << MERLIN_RXTXBB1_CH0_SEL_ATB_LSB) & MERLIN_RXTXBB1_CH0_SEL_ATB_MASK)
#define MERLIN_RXTXBB1_CH0_SEL_ATB_RESET                                       0x0
#define MERLIN_RXTXBB1_CH0_PDDACINTERFACE_LSB                                  8
#define MERLIN_RXTXBB1_CH0_PDDACINTERFACE_MSB                                  8
#define MERLIN_RXTXBB1_CH0_PDDACINTERFACE_MASK                                 0x100
#define MERLIN_RXTXBB1_CH0_PDDACINTERFACE_GET(x)                               (((x) & MERLIN_RXTXBB1_CH0_PDDACINTERFACE_MASK) >> MERLIN_RXTXBB1_CH0_PDDACINTERFACE_LSB)
#define MERLIN_RXTXBB1_CH0_PDDACINTERFACE_SET(x)                               (((0 | (x)) << MERLIN_RXTXBB1_CH0_PDDACINTERFACE_LSB) & MERLIN_RXTXBB1_CH0_PDDACINTERFACE_MASK)
#define MERLIN_RXTXBB1_CH0_PDDACINTERFACE_RESET                                0x0
#define MERLIN_RXTXBB1_CH0_PDV2I_LSB                                           7
#define MERLIN_RXTXBB1_CH0_PDV2I_MSB                                           7
#define MERLIN_RXTXBB1_CH0_PDV2I_MASK                                          0x80
#define MERLIN_RXTXBB1_CH0_PDV2I_GET(x)                                        (((x) & MERLIN_RXTXBB1_CH0_PDV2I_MASK) >> MERLIN_RXTXBB1_CH0_PDV2I_LSB)
#define MERLIN_RXTXBB1_CH0_PDV2I_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB1_CH0_PDV2I_LSB) & MERLIN_RXTXBB1_CH0_PDV2I_MASK)
#define MERLIN_RXTXBB1_CH0_PDV2I_RESET                                         0x0
#define MERLIN_RXTXBB1_CH0_PDI2V_LSB                                           6
#define MERLIN_RXTXBB1_CH0_PDI2V_MSB                                           6
#define MERLIN_RXTXBB1_CH0_PDI2V_MASK                                          0x40
#define MERLIN_RXTXBB1_CH0_PDI2V_GET(x)                                        (((x) & MERLIN_RXTXBB1_CH0_PDI2V_MASK) >> MERLIN_RXTXBB1_CH0_PDI2V_LSB)
#define MERLIN_RXTXBB1_CH0_PDI2V_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB1_CH0_PDI2V_LSB) & MERLIN_RXTXBB1_CH0_PDI2V_MASK)
#define MERLIN_RXTXBB1_CH0_PDI2V_RESET                                         0x0
#define MERLIN_RXTXBB1_CH0_PDRXTXBB_LSB                                        5
#define MERLIN_RXTXBB1_CH0_PDRXTXBB_MSB                                        5
#define MERLIN_RXTXBB1_CH0_PDRXTXBB_MASK                                       0x20
#define MERLIN_RXTXBB1_CH0_PDRXTXBB_GET(x)                                     (((x) & MERLIN_RXTXBB1_CH0_PDRXTXBB_MASK) >> MERLIN_RXTXBB1_CH0_PDRXTXBB_LSB)
#define MERLIN_RXTXBB1_CH0_PDRXTXBB_SET(x)                                     (((0 | (x)) << MERLIN_RXTXBB1_CH0_PDRXTXBB_LSB) & MERLIN_RXTXBB1_CH0_PDRXTXBB_MASK)
#define MERLIN_RXTXBB1_CH0_PDRXTXBB_RESET                                      0x0
#define MERLIN_RXTXBB1_CH0_PDOFFSETLOQ_LSB                                     4
#define MERLIN_RXTXBB1_CH0_PDOFFSETLOQ_MSB                                     4
#define MERLIN_RXTXBB1_CH0_PDOFFSETLOQ_MASK                                    0x10
#define MERLIN_RXTXBB1_CH0_PDOFFSETLOQ_GET(x)                                  (((x) & MERLIN_RXTXBB1_CH0_PDOFFSETLOQ_MASK) >> MERLIN_RXTXBB1_CH0_PDOFFSETLOQ_LSB)
#define MERLIN_RXTXBB1_CH0_PDOFFSETLOQ_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB1_CH0_PDOFFSETLOQ_LSB) & MERLIN_RXTXBB1_CH0_PDOFFSETLOQ_MASK)
#define MERLIN_RXTXBB1_CH0_PDOFFSETLOQ_RESET                                   0x0
#define MERLIN_RXTXBB1_CH0_PDOFFSETHIQ_LSB                                     3
#define MERLIN_RXTXBB1_CH0_PDOFFSETHIQ_MSB                                     3
#define MERLIN_RXTXBB1_CH0_PDOFFSETHIQ_MASK                                    0x8
#define MERLIN_RXTXBB1_CH0_PDOFFSETHIQ_GET(x)                                  (((x) & MERLIN_RXTXBB1_CH0_PDOFFSETHIQ_MASK) >> MERLIN_RXTXBB1_CH0_PDOFFSETHIQ_LSB)
#define MERLIN_RXTXBB1_CH0_PDOFFSETHIQ_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB1_CH0_PDOFFSETHIQ_LSB) & MERLIN_RXTXBB1_CH0_PDOFFSETHIQ_MASK)
#define MERLIN_RXTXBB1_CH0_PDOFFSETHIQ_RESET                                   0x0
#define MERLIN_RXTXBB1_CH0_PDOFFSETI2V_LSB                                     2
#define MERLIN_RXTXBB1_CH0_PDOFFSETI2V_MSB                                     2
#define MERLIN_RXTXBB1_CH0_PDOFFSETI2V_MASK                                    0x4
#define MERLIN_RXTXBB1_CH0_PDOFFSETI2V_GET(x)                                  (((x) & MERLIN_RXTXBB1_CH0_PDOFFSETI2V_MASK) >> MERLIN_RXTXBB1_CH0_PDOFFSETI2V_LSB)
#define MERLIN_RXTXBB1_CH0_PDOFFSETI2V_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB1_CH0_PDOFFSETI2V_LSB) & MERLIN_RXTXBB1_CH0_PDOFFSETI2V_MASK)
#define MERLIN_RXTXBB1_CH0_PDOFFSETI2V_RESET                                   0x0
#define MERLIN_RXTXBB1_CH0_PDLOQ_LSB                                           1
#define MERLIN_RXTXBB1_CH0_PDLOQ_MSB                                           1
#define MERLIN_RXTXBB1_CH0_PDLOQ_MASK                                          0x2
#define MERLIN_RXTXBB1_CH0_PDLOQ_GET(x)                                        (((x) & MERLIN_RXTXBB1_CH0_PDLOQ_MASK) >> MERLIN_RXTXBB1_CH0_PDLOQ_LSB)
#define MERLIN_RXTXBB1_CH0_PDLOQ_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB1_CH0_PDLOQ_LSB) & MERLIN_RXTXBB1_CH0_PDLOQ_MASK)
#define MERLIN_RXTXBB1_CH0_PDLOQ_RESET                                         0x0
#define MERLIN_RXTXBB1_CH0_PDHIQ_LSB                                           0
#define MERLIN_RXTXBB1_CH0_PDHIQ_MSB                                           0
#define MERLIN_RXTXBB1_CH0_PDHIQ_MASK                                          0x1
#define MERLIN_RXTXBB1_CH0_PDHIQ_GET(x)                                        (((x) & MERLIN_RXTXBB1_CH0_PDHIQ_MASK) >> MERLIN_RXTXBB1_CH0_PDHIQ_LSB)
#define MERLIN_RXTXBB1_CH0_PDHIQ_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB1_CH0_PDHIQ_LSB) & MERLIN_RXTXBB1_CH0_PDHIQ_MASK)
#define MERLIN_RXTXBB1_CH0_PDHIQ_RESET                                         0x0
#define MERLIN_RXTXBB1_CH0_ADDRESS                                             (0x24 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RXTXBB1_CH0_RSTMASK                                             0xffffffff
#define MERLIN_RXTXBB1_CH0_RESET                                               0x0

// 0x28 (MERLIN_RXTXBB2_CH0)
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_LSB                              29
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_MSB                              31
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_MASK                             0xe0000000
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_GET(x)                           (((x) & MERLIN_RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_MASK) >> MERLIN_RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_LSB)
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_SET(x)                           (((0 | (x)) << MERLIN_RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_LSB) & MERLIN_RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_MASK)
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_RESET                            0x6
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_LSB                              26
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_MSB                              28
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_MASK                             0x1c000000
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_GET(x)                           (((x) & MERLIN_RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_MASK) >> MERLIN_RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_LSB)
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_SET(x)                           (((0 | (x)) << MERLIN_RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_LSB) & MERLIN_RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_MASK)
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_RESET                            0x6
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_LSB                             23
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_MSB                             25
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_MASK                            0x3800000
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_GET(x)                          (((x) & MERLIN_RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_MASK) >> MERLIN_RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_LSB)
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_SET(x)                          (((0 | (x)) << MERLIN_RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_LSB) & MERLIN_RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_MASK)
#define MERLIN_RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_RESET                           0x6
#define MERLIN_RXTXBB2_CH0_SPARE_LSB                                           21
#define MERLIN_RXTXBB2_CH0_SPARE_MSB                                           22
#define MERLIN_RXTXBB2_CH0_SPARE_MASK                                          0x600000
#define MERLIN_RXTXBB2_CH0_SPARE_GET(x)                                        (((x) & MERLIN_RXTXBB2_CH0_SPARE_MASK) >> MERLIN_RXTXBB2_CH0_SPARE_LSB)
#define MERLIN_RXTXBB2_CH0_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB2_CH0_SPARE_LSB) & MERLIN_RXTXBB2_CH0_SPARE_MASK)
#define MERLIN_RXTXBB2_CH0_SPARE_RESET                                         0x0
#define MERLIN_RXTXBB2_CH0_SHORTBUFFER_LSB                                     20
#define MERLIN_RXTXBB2_CH0_SHORTBUFFER_MSB                                     20
#define MERLIN_RXTXBB2_CH0_SHORTBUFFER_MASK                                    0x100000
#define MERLIN_RXTXBB2_CH0_SHORTBUFFER_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH0_SHORTBUFFER_MASK) >> MERLIN_RXTXBB2_CH0_SHORTBUFFER_LSB)
#define MERLIN_RXTXBB2_CH0_SHORTBUFFER_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH0_SHORTBUFFER_LSB) & MERLIN_RXTXBB2_CH0_SHORTBUFFER_MASK)
#define MERLIN_RXTXBB2_CH0_SHORTBUFFER_RESET                                   0x0
#define MERLIN_RXTXBB2_CH0_SELBUFFER_LSB                                       19
#define MERLIN_RXTXBB2_CH0_SELBUFFER_MSB                                       19
#define MERLIN_RXTXBB2_CH0_SELBUFFER_MASK                                      0x80000
#define MERLIN_RXTXBB2_CH0_SELBUFFER_GET(x)                                    (((x) & MERLIN_RXTXBB2_CH0_SELBUFFER_MASK) >> MERLIN_RXTXBB2_CH0_SELBUFFER_LSB)
#define MERLIN_RXTXBB2_CH0_SELBUFFER_SET(x)                                    (((0 | (x)) << MERLIN_RXTXBB2_CH0_SELBUFFER_LSB) & MERLIN_RXTXBB2_CH0_SELBUFFER_MASK)
#define MERLIN_RXTXBB2_CH0_SELBUFFER_RESET                                     0x0
#define MERLIN_RXTXBB2_CH0_SEL_DAC_TEST_LSB                                    18
#define MERLIN_RXTXBB2_CH0_SEL_DAC_TEST_MSB                                    18
#define MERLIN_RXTXBB2_CH0_SEL_DAC_TEST_MASK                                   0x40000
#define MERLIN_RXTXBB2_CH0_SEL_DAC_TEST_GET(x)                                 (((x) & MERLIN_RXTXBB2_CH0_SEL_DAC_TEST_MASK) >> MERLIN_RXTXBB2_CH0_SEL_DAC_TEST_LSB)
#define MERLIN_RXTXBB2_CH0_SEL_DAC_TEST_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB2_CH0_SEL_DAC_TEST_LSB) & MERLIN_RXTXBB2_CH0_SEL_DAC_TEST_MASK)
#define MERLIN_RXTXBB2_CH0_SEL_DAC_TEST_RESET                                  0x0
#define MERLIN_RXTXBB2_CH0_SEL_LOQ_TEST_LSB                                    17
#define MERLIN_RXTXBB2_CH0_SEL_LOQ_TEST_MSB                                    17
#define MERLIN_RXTXBB2_CH0_SEL_LOQ_TEST_MASK                                   0x20000
#define MERLIN_RXTXBB2_CH0_SEL_LOQ_TEST_GET(x)                                 (((x) & MERLIN_RXTXBB2_CH0_SEL_LOQ_TEST_MASK) >> MERLIN_RXTXBB2_CH0_SEL_LOQ_TEST_LSB)
#define MERLIN_RXTXBB2_CH0_SEL_LOQ_TEST_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB2_CH0_SEL_LOQ_TEST_LSB) & MERLIN_RXTXBB2_CH0_SEL_LOQ_TEST_MASK)
#define MERLIN_RXTXBB2_CH0_SEL_LOQ_TEST_RESET                                  0x0
#define MERLIN_RXTXBB2_CH0_SEL_HIQ_TEST_LSB                                    16
#define MERLIN_RXTXBB2_CH0_SEL_HIQ_TEST_MSB                                    16
#define MERLIN_RXTXBB2_CH0_SEL_HIQ_TEST_MASK                                   0x10000
#define MERLIN_RXTXBB2_CH0_SEL_HIQ_TEST_GET(x)                                 (((x) & MERLIN_RXTXBB2_CH0_SEL_HIQ_TEST_MASK) >> MERLIN_RXTXBB2_CH0_SEL_HIQ_TEST_LSB)
#define MERLIN_RXTXBB2_CH0_SEL_HIQ_TEST_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB2_CH0_SEL_HIQ_TEST_LSB) & MERLIN_RXTXBB2_CH0_SEL_HIQ_TEST_MASK)
#define MERLIN_RXTXBB2_CH0_SEL_HIQ_TEST_RESET                                  0x0
#define MERLIN_RXTXBB2_CH0_SEL_I2V_TEST_LSB                                    15
#define MERLIN_RXTXBB2_CH0_SEL_I2V_TEST_MSB                                    15
#define MERLIN_RXTXBB2_CH0_SEL_I2V_TEST_MASK                                   0x8000
#define MERLIN_RXTXBB2_CH0_SEL_I2V_TEST_GET(x)                                 (((x) & MERLIN_RXTXBB2_CH0_SEL_I2V_TEST_MASK) >> MERLIN_RXTXBB2_CH0_SEL_I2V_TEST_LSB)
#define MERLIN_RXTXBB2_CH0_SEL_I2V_TEST_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB2_CH0_SEL_I2V_TEST_LSB) & MERLIN_RXTXBB2_CH0_SEL_I2V_TEST_MASK)
#define MERLIN_RXTXBB2_CH0_SEL_I2V_TEST_RESET                                  0x0
#define MERLIN_RXTXBB2_CH0_CMSEL_LSB                                           13
#define MERLIN_RXTXBB2_CH0_CMSEL_MSB                                           14
#define MERLIN_RXTXBB2_CH0_CMSEL_MASK                                          0x6000
#define MERLIN_RXTXBB2_CH0_CMSEL_GET(x)                                        (((x) & MERLIN_RXTXBB2_CH0_CMSEL_MASK) >> MERLIN_RXTXBB2_CH0_CMSEL_LSB)
#define MERLIN_RXTXBB2_CH0_CMSEL_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB2_CH0_CMSEL_LSB) & MERLIN_RXTXBB2_CH0_CMSEL_MASK)
#define MERLIN_RXTXBB2_CH0_CMSEL_RESET                                         0x1
#define MERLIN_RXTXBB2_CH0_FILTERFC_LSB                                        8
#define MERLIN_RXTXBB2_CH0_FILTERFC_MSB                                        12
#define MERLIN_RXTXBB2_CH0_FILTERFC_MASK                                       0x1f00
#define MERLIN_RXTXBB2_CH0_FILTERFC_GET(x)                                     (((x) & MERLIN_RXTXBB2_CH0_FILTERFC_MASK) >> MERLIN_RXTXBB2_CH0_FILTERFC_LSB)
#define MERLIN_RXTXBB2_CH0_FILTERFC_SET(x)                                     (((0 | (x)) << MERLIN_RXTXBB2_CH0_FILTERFC_LSB) & MERLIN_RXTXBB2_CH0_FILTERFC_MASK)
#define MERLIN_RXTXBB2_CH0_FILTERFC_RESET                                      0x10
#define MERLIN_RXTXBB2_CH0_LOCALFILTERTUNING_LSB                               7
#define MERLIN_RXTXBB2_CH0_LOCALFILTERTUNING_MSB                               7
#define MERLIN_RXTXBB2_CH0_LOCALFILTERTUNING_MASK                              0x80
#define MERLIN_RXTXBB2_CH0_LOCALFILTERTUNING_GET(x)                            (((x) & MERLIN_RXTXBB2_CH0_LOCALFILTERTUNING_MASK) >> MERLIN_RXTXBB2_CH0_LOCALFILTERTUNING_LSB)
#define MERLIN_RXTXBB2_CH0_LOCALFILTERTUNING_SET(x)                            (((0 | (x)) << MERLIN_RXTXBB2_CH0_LOCALFILTERTUNING_LSB) & MERLIN_RXTXBB2_CH0_LOCALFILTERTUNING_MASK)
#define MERLIN_RXTXBB2_CH0_LOCALFILTERTUNING_RESET                             0x0
#define MERLIN_RXTXBB2_CH0_FILTERDOUBLEBW_LSB                                  6
#define MERLIN_RXTXBB2_CH0_FILTERDOUBLEBW_MSB                                  6
#define MERLIN_RXTXBB2_CH0_FILTERDOUBLEBW_MASK                                 0x40
#define MERLIN_RXTXBB2_CH0_FILTERDOUBLEBW_GET(x)                               (((x) & MERLIN_RXTXBB2_CH0_FILTERDOUBLEBW_MASK) >> MERLIN_RXTXBB2_CH0_FILTERDOUBLEBW_LSB)
#define MERLIN_RXTXBB2_CH0_FILTERDOUBLEBW_SET(x)                               (((0 | (x)) << MERLIN_RXTXBB2_CH0_FILTERDOUBLEBW_LSB) & MERLIN_RXTXBB2_CH0_FILTERDOUBLEBW_MASK)
#define MERLIN_RXTXBB2_CH0_FILTERDOUBLEBW_RESET                                0x0
#define MERLIN_RXTXBB2_CH0_PATH2HIQ_EN_LSB                                     5
#define MERLIN_RXTXBB2_CH0_PATH2HIQ_EN_MSB                                     5
#define MERLIN_RXTXBB2_CH0_PATH2HIQ_EN_MASK                                    0x20
#define MERLIN_RXTXBB2_CH0_PATH2HIQ_EN_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH0_PATH2HIQ_EN_MASK) >> MERLIN_RXTXBB2_CH0_PATH2HIQ_EN_LSB)
#define MERLIN_RXTXBB2_CH0_PATH2HIQ_EN_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH0_PATH2HIQ_EN_LSB) & MERLIN_RXTXBB2_CH0_PATH2HIQ_EN_MASK)
#define MERLIN_RXTXBB2_CH0_PATH2HIQ_EN_RESET                                   0x0
#define MERLIN_RXTXBB2_CH0_PATH1HIQ_EN_LSB                                     4
#define MERLIN_RXTXBB2_CH0_PATH1HIQ_EN_MSB                                     4
#define MERLIN_RXTXBB2_CH0_PATH1HIQ_EN_MASK                                    0x10
#define MERLIN_RXTXBB2_CH0_PATH1HIQ_EN_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH0_PATH1HIQ_EN_MASK) >> MERLIN_RXTXBB2_CH0_PATH1HIQ_EN_LSB)
#define MERLIN_RXTXBB2_CH0_PATH1HIQ_EN_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH0_PATH1HIQ_EN_LSB) & MERLIN_RXTXBB2_CH0_PATH1HIQ_EN_MASK)
#define MERLIN_RXTXBB2_CH0_PATH1HIQ_EN_RESET                                   0x1
#define MERLIN_RXTXBB2_CH0_PATH3LOQ_EN_LSB                                     3
#define MERLIN_RXTXBB2_CH0_PATH3LOQ_EN_MSB                                     3
#define MERLIN_RXTXBB2_CH0_PATH3LOQ_EN_MASK                                    0x8
#define MERLIN_RXTXBB2_CH0_PATH3LOQ_EN_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH0_PATH3LOQ_EN_MASK) >> MERLIN_RXTXBB2_CH0_PATH3LOQ_EN_LSB)
#define MERLIN_RXTXBB2_CH0_PATH3LOQ_EN_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH0_PATH3LOQ_EN_LSB) & MERLIN_RXTXBB2_CH0_PATH3LOQ_EN_MASK)
#define MERLIN_RXTXBB2_CH0_PATH3LOQ_EN_RESET                                   0x0
#define MERLIN_RXTXBB2_CH0_PATH2LOQ_EN_LSB                                     2
#define MERLIN_RXTXBB2_CH0_PATH2LOQ_EN_MSB                                     2
#define MERLIN_RXTXBB2_CH0_PATH2LOQ_EN_MASK                                    0x4
#define MERLIN_RXTXBB2_CH0_PATH2LOQ_EN_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH0_PATH2LOQ_EN_MASK) >> MERLIN_RXTXBB2_CH0_PATH2LOQ_EN_LSB)
#define MERLIN_RXTXBB2_CH0_PATH2LOQ_EN_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH0_PATH2LOQ_EN_LSB) & MERLIN_RXTXBB2_CH0_PATH2LOQ_EN_MASK)
#define MERLIN_RXTXBB2_CH0_PATH2LOQ_EN_RESET                                   0x0
#define MERLIN_RXTXBB2_CH0_PATH1LOQ_EN_LSB                                     1
#define MERLIN_RXTXBB2_CH0_PATH1LOQ_EN_MSB                                     1
#define MERLIN_RXTXBB2_CH0_PATH1LOQ_EN_MASK                                    0x2
#define MERLIN_RXTXBB2_CH0_PATH1LOQ_EN_GET(x)                                  (((x) & MERLIN_RXTXBB2_CH0_PATH1LOQ_EN_MASK) >> MERLIN_RXTXBB2_CH0_PATH1LOQ_EN_LSB)
#define MERLIN_RXTXBB2_CH0_PATH1LOQ_EN_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB2_CH0_PATH1LOQ_EN_LSB) & MERLIN_RXTXBB2_CH0_PATH1LOQ_EN_MASK)
#define MERLIN_RXTXBB2_CH0_PATH1LOQ_EN_RESET                                   0x1
#define MERLIN_RXTXBB2_CH0_PATH_OVERRIDE_LSB                                   0
#define MERLIN_RXTXBB2_CH0_PATH_OVERRIDE_MSB                                   0
#define MERLIN_RXTXBB2_CH0_PATH_OVERRIDE_MASK                                  0x1
#define MERLIN_RXTXBB2_CH0_PATH_OVERRIDE_GET(x)                                (((x) & MERLIN_RXTXBB2_CH0_PATH_OVERRIDE_MASK) >> MERLIN_RXTXBB2_CH0_PATH_OVERRIDE_LSB)
#define MERLIN_RXTXBB2_CH0_PATH_OVERRIDE_SET(x)                                (((0 | (x)) << MERLIN_RXTXBB2_CH0_PATH_OVERRIDE_LSB) & MERLIN_RXTXBB2_CH0_PATH_OVERRIDE_MASK)
#define MERLIN_RXTXBB2_CH0_PATH_OVERRIDE_RESET                                 0x0
#define MERLIN_RXTXBB2_CH0_ADDRESS                                             (0x28 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RXTXBB2_CH0_RSTMASK                                             0xffffffff
#define MERLIN_RXTXBB2_CH0_RESET                                               0xdb003012

// 0x2c (MERLIN_RXTXBB3_CH0)
#define MERLIN_RXTXBB3_CH0_SPARE_LSB                                           27
#define MERLIN_RXTXBB3_CH0_SPARE_MSB                                           31
#define MERLIN_RXTXBB3_CH0_SPARE_MASK                                          0xf8000000
#define MERLIN_RXTXBB3_CH0_SPARE_GET(x)                                        (((x) & MERLIN_RXTXBB3_CH0_SPARE_MASK) >> MERLIN_RXTXBB3_CH0_SPARE_LSB)
#define MERLIN_RXTXBB3_CH0_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB3_CH0_SPARE_LSB) & MERLIN_RXTXBB3_CH0_SPARE_MASK)
#define MERLIN_RXTXBB3_CH0_SPARE_RESET                                         0x0
#define MERLIN_RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_LSB                          24
#define MERLIN_RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_MSB                          26
#define MERLIN_RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_MASK                         0x7000000
#define MERLIN_RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_GET(x)                       (((x) & MERLIN_RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_MASK) >> MERLIN_RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_LSB)
#define MERLIN_RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_SET(x)                       (((0 | (x)) << MERLIN_RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_LSB) & MERLIN_RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_MASK)
#define MERLIN_RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_RESET                        0x4
#define MERLIN_RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_LSB                              21
#define MERLIN_RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_MSB                              23
#define MERLIN_RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_MASK                             0xe00000
#define MERLIN_RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_GET(x)                           (((x) & MERLIN_RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_MASK) >> MERLIN_RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_LSB)
#define MERLIN_RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_SET(x)                           (((0 | (x)) << MERLIN_RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_LSB) & MERLIN_RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_MASK)
#define MERLIN_RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_RESET                            0x4
#define MERLIN_RXTXBB3_CH0_IBN_25U_I2V_CTRL_LSB                                18
#define MERLIN_RXTXBB3_CH0_IBN_25U_I2V_CTRL_MSB                                20
#define MERLIN_RXTXBB3_CH0_IBN_25U_I2V_CTRL_MASK                               0x1c0000
#define MERLIN_RXTXBB3_CH0_IBN_25U_I2V_CTRL_GET(x)                             (((x) & MERLIN_RXTXBB3_CH0_IBN_25U_I2V_CTRL_MASK) >> MERLIN_RXTXBB3_CH0_IBN_25U_I2V_CTRL_LSB)
#define MERLIN_RXTXBB3_CH0_IBN_25U_I2V_CTRL_SET(x)                             (((0 | (x)) << MERLIN_RXTXBB3_CH0_IBN_25U_I2V_CTRL_LSB) & MERLIN_RXTXBB3_CH0_IBN_25U_I2V_CTRL_MASK)
#define MERLIN_RXTXBB3_CH0_IBN_25U_I2V_CTRL_RESET                              0x4
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI1_CTRL_LSB                                15
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI1_CTRL_MSB                                17
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI1_CTRL_MASK                               0x38000
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI1_CTRL_GET(x)                             (((x) & MERLIN_RXTXBB3_CH0_IBN_25U_HI1_CTRL_MASK) >> MERLIN_RXTXBB3_CH0_IBN_25U_HI1_CTRL_LSB)
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI1_CTRL_SET(x)                             (((0 | (x)) << MERLIN_RXTXBB3_CH0_IBN_25U_HI1_CTRL_LSB) & MERLIN_RXTXBB3_CH0_IBN_25U_HI1_CTRL_MASK)
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI1_CTRL_RESET                              0x4
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI2_CTRL_LSB                                12
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI2_CTRL_MSB                                14
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI2_CTRL_MASK                               0x7000
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI2_CTRL_GET(x)                             (((x) & MERLIN_RXTXBB3_CH0_IBN_25U_HI2_CTRL_MASK) >> MERLIN_RXTXBB3_CH0_IBN_25U_HI2_CTRL_LSB)
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI2_CTRL_SET(x)                             (((0 | (x)) << MERLIN_RXTXBB3_CH0_IBN_25U_HI2_CTRL_LSB) & MERLIN_RXTXBB3_CH0_IBN_25U_HI2_CTRL_MASK)
#define MERLIN_RXTXBB3_CH0_IBN_25U_HI2_CTRL_RESET                              0x4
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO1_CTRL_LSB                                9
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO1_CTRL_MSB                                11
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO1_CTRL_MASK                               0xe00
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO1_CTRL_GET(x)                             (((x) & MERLIN_RXTXBB3_CH0_IBN_25U_LO1_CTRL_MASK) >> MERLIN_RXTXBB3_CH0_IBN_25U_LO1_CTRL_LSB)
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO1_CTRL_SET(x)                             (((0 | (x)) << MERLIN_RXTXBB3_CH0_IBN_25U_LO1_CTRL_LSB) & MERLIN_RXTXBB3_CH0_IBN_25U_LO1_CTRL_MASK)
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO1_CTRL_RESET                              0x4
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO2_CTRL_LSB                                6
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO2_CTRL_MSB                                8
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO2_CTRL_MASK                               0x1c0
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO2_CTRL_GET(x)                             (((x) & MERLIN_RXTXBB3_CH0_IBN_25U_LO2_CTRL_MASK) >> MERLIN_RXTXBB3_CH0_IBN_25U_LO2_CTRL_LSB)
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO2_CTRL_SET(x)                             (((0 | (x)) << MERLIN_RXTXBB3_CH0_IBN_25U_LO2_CTRL_LSB) & MERLIN_RXTXBB3_CH0_IBN_25U_LO2_CTRL_MASK)
#define MERLIN_RXTXBB3_CH0_IBN_25U_LO2_CTRL_RESET                              0x4
#define MERLIN_RXTXBB3_CH0_IBRN_12P5_CM_CTRL_LSB                               3
#define MERLIN_RXTXBB3_CH0_IBRN_12P5_CM_CTRL_MSB                               5
#define MERLIN_RXTXBB3_CH0_IBRN_12P5_CM_CTRL_MASK                              0x38
#define MERLIN_RXTXBB3_CH0_IBRN_12P5_CM_CTRL_GET(x)                            (((x) & MERLIN_RXTXBB3_CH0_IBRN_12P5_CM_CTRL_MASK) >> MERLIN_RXTXBB3_CH0_IBRN_12P5_CM_CTRL_LSB)
#define MERLIN_RXTXBB3_CH0_IBRN_12P5_CM_CTRL_SET(x)                            (((0 | (x)) << MERLIN_RXTXBB3_CH0_IBRN_12P5_CM_CTRL_LSB) & MERLIN_RXTXBB3_CH0_IBRN_12P5_CM_CTRL_MASK)
#define MERLIN_RXTXBB3_CH0_IBRN_12P5_CM_CTRL_RESET                             0x2
#define MERLIN_RXTXBB3_CH0_IBN_100U_TEST_CTRL_LSB                              0
#define MERLIN_RXTXBB3_CH0_IBN_100U_TEST_CTRL_MSB                              2
#define MERLIN_RXTXBB3_CH0_IBN_100U_TEST_CTRL_MASK                             0x7
#define MERLIN_RXTXBB3_CH0_IBN_100U_TEST_CTRL_GET(x)                           (((x) & MERLIN_RXTXBB3_CH0_IBN_100U_TEST_CTRL_MASK) >> MERLIN_RXTXBB3_CH0_IBN_100U_TEST_CTRL_LSB)
#define MERLIN_RXTXBB3_CH0_IBN_100U_TEST_CTRL_SET(x)                           (((0 | (x)) << MERLIN_RXTXBB3_CH0_IBN_100U_TEST_CTRL_LSB) & MERLIN_RXTXBB3_CH0_IBN_100U_TEST_CTRL_MASK)
#define MERLIN_RXTXBB3_CH0_IBN_100U_TEST_CTRL_RESET                            0x4
#define MERLIN_RXTXBB3_CH0_ADDRESS                                             (0x2c + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RXTXBB3_CH0_RSTMASK                                             0xffffffff
#define MERLIN_RXTXBB3_CH0_RESET                                               0x4924914

// 0x30 (MERLIN_RXTXBB4_CH0)
#define MERLIN_RXTXBB4_CH0_SPARE_LSB                                           31
#define MERLIN_RXTXBB4_CH0_SPARE_MSB                                           31
#define MERLIN_RXTXBB4_CH0_SPARE_MASK                                          0x80000000
#define MERLIN_RXTXBB4_CH0_SPARE_GET(x)                                        (((x) & MERLIN_RXTXBB4_CH0_SPARE_MASK) >> MERLIN_RXTXBB4_CH0_SPARE_LSB)
#define MERLIN_RXTXBB4_CH0_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_RXTXBB4_CH0_SPARE_LSB) & MERLIN_RXTXBB4_CH0_SPARE_MASK)
#define MERLIN_RXTXBB4_CH0_SPARE_RESET                                         0x0
#define MERLIN_RXTXBB4_CH0_LOCALOFFSET_LSB                                     30
#define MERLIN_RXTXBB4_CH0_LOCALOFFSET_MSB                                     30
#define MERLIN_RXTXBB4_CH0_LOCALOFFSET_MASK                                    0x40000000
#define MERLIN_RXTXBB4_CH0_LOCALOFFSET_GET(x)                                  (((x) & MERLIN_RXTXBB4_CH0_LOCALOFFSET_MASK) >> MERLIN_RXTXBB4_CH0_LOCALOFFSET_LSB)
#define MERLIN_RXTXBB4_CH0_LOCALOFFSET_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB4_CH0_LOCALOFFSET_LSB) & MERLIN_RXTXBB4_CH0_LOCALOFFSET_MASK)
#define MERLIN_RXTXBB4_CH0_LOCALOFFSET_RESET                                   0x0
#define MERLIN_RXTXBB4_CH0_OFSTCORRHII_LSB                                     25
#define MERLIN_RXTXBB4_CH0_OFSTCORRHII_MSB                                     29
#define MERLIN_RXTXBB4_CH0_OFSTCORRHII_MASK                                    0x3e000000
#define MERLIN_RXTXBB4_CH0_OFSTCORRHII_GET(x)                                  (((x) & MERLIN_RXTXBB4_CH0_OFSTCORRHII_MASK) >> MERLIN_RXTXBB4_CH0_OFSTCORRHII_LSB)
#define MERLIN_RXTXBB4_CH0_OFSTCORRHII_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB4_CH0_OFSTCORRHII_LSB) & MERLIN_RXTXBB4_CH0_OFSTCORRHII_MASK)
#define MERLIN_RXTXBB4_CH0_OFSTCORRHII_RESET                                   0x10
#define MERLIN_RXTXBB4_CH0_OFSTCORRHIQ_LSB                                     20
#define MERLIN_RXTXBB4_CH0_OFSTCORRHIQ_MSB                                     24
#define MERLIN_RXTXBB4_CH0_OFSTCORRHIQ_MASK                                    0x1f00000
#define MERLIN_RXTXBB4_CH0_OFSTCORRHIQ_GET(x)                                  (((x) & MERLIN_RXTXBB4_CH0_OFSTCORRHIQ_MASK) >> MERLIN_RXTXBB4_CH0_OFSTCORRHIQ_LSB)
#define MERLIN_RXTXBB4_CH0_OFSTCORRHIQ_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB4_CH0_OFSTCORRHIQ_LSB) & MERLIN_RXTXBB4_CH0_OFSTCORRHIQ_MASK)
#define MERLIN_RXTXBB4_CH0_OFSTCORRHIQ_RESET                                   0x10
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOI_LSB                                     15
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOI_MSB                                     19
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOI_MASK                                    0xf8000
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOI_GET(x)                                  (((x) & MERLIN_RXTXBB4_CH0_OFSTCORRLOI_MASK) >> MERLIN_RXTXBB4_CH0_OFSTCORRLOI_LSB)
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOI_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB4_CH0_OFSTCORRLOI_LSB) & MERLIN_RXTXBB4_CH0_OFSTCORRLOI_MASK)
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOI_RESET                                   0x10
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOQ_LSB                                     10
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOQ_MSB                                     14
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOQ_MASK                                    0x7c00
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOQ_GET(x)                                  (((x) & MERLIN_RXTXBB4_CH0_OFSTCORRLOQ_MASK) >> MERLIN_RXTXBB4_CH0_OFSTCORRLOQ_LSB)
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOQ_SET(x)                                  (((0 | (x)) << MERLIN_RXTXBB4_CH0_OFSTCORRLOQ_LSB) & MERLIN_RXTXBB4_CH0_OFSTCORRLOQ_MASK)
#define MERLIN_RXTXBB4_CH0_OFSTCORRLOQ_RESET                                   0x10
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VI_LSB                                    5
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VI_MSB                                    9
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VI_MASK                                   0x3e0
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VI_GET(x)                                 (((x) & MERLIN_RXTXBB4_CH0_OFSTCORRI2VI_MASK) >> MERLIN_RXTXBB4_CH0_OFSTCORRI2VI_LSB)
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VI_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB4_CH0_OFSTCORRI2VI_LSB) & MERLIN_RXTXBB4_CH0_OFSTCORRI2VI_MASK)
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VI_RESET                                  0x10
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VQ_LSB                                    0
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VQ_MSB                                    4
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VQ_MASK                                   0x1f
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VQ_GET(x)                                 (((x) & MERLIN_RXTXBB4_CH0_OFSTCORRI2VQ_MASK) >> MERLIN_RXTXBB4_CH0_OFSTCORRI2VQ_LSB)
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VQ_SET(x)                                 (((0 | (x)) << MERLIN_RXTXBB4_CH0_OFSTCORRI2VQ_LSB) & MERLIN_RXTXBB4_CH0_OFSTCORRI2VQ_MASK)
#define MERLIN_RXTXBB4_CH0_OFSTCORRI2VQ_RESET                                  0x10
#define MERLIN_RXTXBB4_CH0_ADDRESS                                             (0x30 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RXTXBB4_CH0_RSTMASK                                             0xffffffff
#define MERLIN_RXTXBB4_CH0_RESET                                               0x21084210

// 0x34 (MERLIN_RF2G1_CH0)
#define MERLIN_RF2G1_CH0_PDIC25U_LNA_LSB                                       29
#define MERLIN_RF2G1_CH0_PDIC25U_LNA_MSB                                       31
#define MERLIN_RF2G1_CH0_PDIC25U_LNA_MASK                                      0xe0000000
#define MERLIN_RF2G1_CH0_PDIC25U_LNA_GET(x)                                    (((x) & MERLIN_RF2G1_CH0_PDIC25U_LNA_MASK) >> MERLIN_RF2G1_CH0_PDIC25U_LNA_LSB)
#define MERLIN_RF2G1_CH0_PDIC25U_LNA_SET(x)                                    (((0 | (x)) << MERLIN_RF2G1_CH0_PDIC25U_LNA_LSB) & MERLIN_RF2G1_CH0_PDIC25U_LNA_MASK)
#define MERLIN_RF2G1_CH0_PDIC25U_LNA_RESET                                     0x3
#define MERLIN_RF2G1_CH0_DB_LSB                                                26
#define MERLIN_RF2G1_CH0_DB_MSB                                                28
#define MERLIN_RF2G1_CH0_DB_MASK                                               0x1c000000
#define MERLIN_RF2G1_CH0_DB_GET(x)                                             (((x) & MERLIN_RF2G1_CH0_DB_MASK) >> MERLIN_RF2G1_CH0_DB_LSB)
#define MERLIN_RF2G1_CH0_DB_SET(x)                                             (((0 | (x)) << MERLIN_RF2G1_CH0_DB_LSB) & MERLIN_RF2G1_CH0_DB_MASK)
#define MERLIN_RF2G1_CH0_DB_RESET                                              0x3
#define MERLIN_RF2G1_CH0_OB_LSB                                                23
#define MERLIN_RF2G1_CH0_OB_MSB                                                25
#define MERLIN_RF2G1_CH0_OB_MASK                                               0x3800000
#define MERLIN_RF2G1_CH0_OB_GET(x)                                             (((x) & MERLIN_RF2G1_CH0_OB_MASK) >> MERLIN_RF2G1_CH0_OB_LSB)
#define MERLIN_RF2G1_CH0_OB_SET(x)                                             (((0 | (x)) << MERLIN_RF2G1_CH0_OB_LSB) & MERLIN_RF2G1_CH0_OB_MASK)
#define MERLIN_RF2G1_CH0_OB_RESET                                              0x3
#define MERLIN_RF2G1_CH0_LOATB_SEL_LSB                                         20
#define MERLIN_RF2G1_CH0_LOATB_SEL_MSB                                         22
#define MERLIN_RF2G1_CH0_LOATB_SEL_MASK                                        0x700000
#define MERLIN_RF2G1_CH0_LOATB_SEL_GET(x)                                      (((x) & MERLIN_RF2G1_CH0_LOATB_SEL_MASK) >> MERLIN_RF2G1_CH0_LOATB_SEL_LSB)
#define MERLIN_RF2G1_CH0_LOATB_SEL_SET(x)                                      (((0 | (x)) << MERLIN_RF2G1_CH0_LOATB_SEL_LSB) & MERLIN_RF2G1_CH0_LOATB_SEL_MASK)
#define MERLIN_RF2G1_CH0_LOATB_SEL_RESET                                       0x0
#define MERLIN_RF2G1_CH0_RXATB_SEL_LSB                                         17
#define MERLIN_RF2G1_CH0_RXATB_SEL_MSB                                         19
#define MERLIN_RF2G1_CH0_RXATB_SEL_MASK                                        0xe0000
#define MERLIN_RF2G1_CH0_RXATB_SEL_GET(x)                                      (((x) & MERLIN_RF2G1_CH0_RXATB_SEL_MASK) >> MERLIN_RF2G1_CH0_RXATB_SEL_LSB)
#define MERLIN_RF2G1_CH0_RXATB_SEL_SET(x)                                      (((0 | (x)) << MERLIN_RF2G1_CH0_RXATB_SEL_LSB) & MERLIN_RF2G1_CH0_RXATB_SEL_MASK)
#define MERLIN_RF2G1_CH0_RXATB_SEL_RESET                                       0x0
#define MERLIN_RF2G1_CH0_TXATB_SEL_LSB                                         14
#define MERLIN_RF2G1_CH0_TXATB_SEL_MSB                                         16
#define MERLIN_RF2G1_CH0_TXATB_SEL_MASK                                        0x1c000
#define MERLIN_RF2G1_CH0_TXATB_SEL_GET(x)                                      (((x) & MERLIN_RF2G1_CH0_TXATB_SEL_MASK) >> MERLIN_RF2G1_CH0_TXATB_SEL_LSB)
#define MERLIN_RF2G1_CH0_TXATB_SEL_SET(x)                                      (((0 | (x)) << MERLIN_RF2G1_CH0_TXATB_SEL_LSB) & MERLIN_RF2G1_CH0_TXATB_SEL_MASK)
#define MERLIN_RF2G1_CH0_TXATB_SEL_RESET                                       0x0
#define MERLIN_RF2G1_CH0_LOCONTROL_LSB                                         13
#define MERLIN_RF2G1_CH0_LOCONTROL_MSB                                         13
#define MERLIN_RF2G1_CH0_LOCONTROL_MASK                                        0x2000
#define MERLIN_RF2G1_CH0_LOCONTROL_GET(x)                                      (((x) & MERLIN_RF2G1_CH0_LOCONTROL_MASK) >> MERLIN_RF2G1_CH0_LOCONTROL_LSB)
#define MERLIN_RF2G1_CH0_LOCONTROL_SET(x)                                      (((0 | (x)) << MERLIN_RF2G1_CH0_LOCONTROL_LSB) & MERLIN_RF2G1_CH0_LOCONTROL_MASK)
#define MERLIN_RF2G1_CH0_LOCONTROL_RESET                                       0x0
#define MERLIN_RF2G1_CH0_PACA_SEL_LSB                                          11
#define MERLIN_RF2G1_CH0_PACA_SEL_MSB                                          12
#define MERLIN_RF2G1_CH0_PACA_SEL_MASK                                         0x1800
#define MERLIN_RF2G1_CH0_PACA_SEL_GET(x)                                       (((x) & MERLIN_RF2G1_CH0_PACA_SEL_MASK) >> MERLIN_RF2G1_CH0_PACA_SEL_LSB)
#define MERLIN_RF2G1_CH0_PACA_SEL_SET(x)                                       (((0 | (x)) << MERLIN_RF2G1_CH0_PACA_SEL_LSB) & MERLIN_RF2G1_CH0_PACA_SEL_MASK)
#define MERLIN_RF2G1_CH0_PACA_SEL_RESET                                        0x2
#define MERLIN_RF2G1_CH0_PDIC25U_VGM_LSB                                       8
#define MERLIN_RF2G1_CH0_PDIC25U_VGM_MSB                                       10
#define MERLIN_RF2G1_CH0_PDIC25U_VGM_MASK                                      0x700
#define MERLIN_RF2G1_CH0_PDIC25U_VGM_GET(x)                                    (((x) & MERLIN_RF2G1_CH0_PDIC25U_VGM_MASK) >> MERLIN_RF2G1_CH0_PDIC25U_VGM_LSB)
#define MERLIN_RF2G1_CH0_PDIC25U_VGM_SET(x)                                    (((0 | (x)) << MERLIN_RF2G1_CH0_PDIC25U_VGM_LSB) & MERLIN_RF2G1_CH0_PDIC25U_VGM_MASK)
#define MERLIN_RF2G1_CH0_PDIC25U_VGM_RESET                                     0x3
#define MERLIN_RF2G1_CH0_REGLNA_BYPASS_LSB                                     7
#define MERLIN_RF2G1_CH0_REGLNA_BYPASS_MSB                                     7
#define MERLIN_RF2G1_CH0_REGLNA_BYPASS_MASK                                    0x80
#define MERLIN_RF2G1_CH0_REGLNA_BYPASS_GET(x)                                  (((x) & MERLIN_RF2G1_CH0_REGLNA_BYPASS_MASK) >> MERLIN_RF2G1_CH0_REGLNA_BYPASS_LSB)
#define MERLIN_RF2G1_CH0_REGLNA_BYPASS_SET(x)                                  (((0 | (x)) << MERLIN_RF2G1_CH0_REGLNA_BYPASS_LSB) & MERLIN_RF2G1_CH0_REGLNA_BYPASS_MASK)
#define MERLIN_RF2G1_CH0_REGLNA_BYPASS_RESET                                   0x0
#define MERLIN_RF2G1_CH0_REGLO_BYPASS_LSB                                      6
#define MERLIN_RF2G1_CH0_REGLO_BYPASS_MSB                                      6
#define MERLIN_RF2G1_CH0_REGLO_BYPASS_MASK                                     0x40
#define MERLIN_RF2G1_CH0_REGLO_BYPASS_GET(x)                                   (((x) & MERLIN_RF2G1_CH0_REGLO_BYPASS_MASK) >> MERLIN_RF2G1_CH0_REGLO_BYPASS_LSB)
#define MERLIN_RF2G1_CH0_REGLO_BYPASS_SET(x)                                   (((0 | (x)) << MERLIN_RF2G1_CH0_REGLO_BYPASS_LSB) & MERLIN_RF2G1_CH0_REGLO_BYPASS_MASK)
#define MERLIN_RF2G1_CH0_REGLO_BYPASS_RESET                                    0x0
#define MERLIN_RF2G1_CH0_SPARES_LSB                                            0
#define MERLIN_RF2G1_CH0_SPARES_MSB                                            5
#define MERLIN_RF2G1_CH0_SPARES_MASK                                           0x3f
#define MERLIN_RF2G1_CH0_SPARES_GET(x)                                         (((x) & MERLIN_RF2G1_CH0_SPARES_MASK) >> MERLIN_RF2G1_CH0_SPARES_LSB)
#define MERLIN_RF2G1_CH0_SPARES_SET(x)                                         (((0 | (x)) << MERLIN_RF2G1_CH0_SPARES_LSB) & MERLIN_RF2G1_CH0_SPARES_MASK)
#define MERLIN_RF2G1_CH0_SPARES_RESET                                          0x0
#define MERLIN_RF2G1_CH0_ADDRESS                                               (0x34 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RF2G1_CH0_RSTMASK                                               0xffffffff
#define MERLIN_RF2G1_CH0_RESET                                                 0x6d801300

// 0x38 (MERLIN_RF2G2_CH0)
#define MERLIN_RF2G2_CH0_PDLNA_LSB                                             31
#define MERLIN_RF2G2_CH0_PDLNA_MSB                                             31
#define MERLIN_RF2G2_CH0_PDLNA_MASK                                            0x80000000
#define MERLIN_RF2G2_CH0_PDLNA_GET(x)                                          (((x) & MERLIN_RF2G2_CH0_PDLNA_MASK) >> MERLIN_RF2G2_CH0_PDLNA_LSB)
#define MERLIN_RF2G2_CH0_PDLNA_SET(x)                                          (((0 | (x)) << MERLIN_RF2G2_CH0_PDLNA_LSB) & MERLIN_RF2G2_CH0_PDLNA_MASK)
#define MERLIN_RF2G2_CH0_PDLNA_RESET                                           0x0
#define MERLIN_RF2G2_CH0_PDDIV_LSB                                             30
#define MERLIN_RF2G2_CH0_PDDIV_MSB                                             30
#define MERLIN_RF2G2_CH0_PDDIV_MASK                                            0x40000000
#define MERLIN_RF2G2_CH0_PDDIV_GET(x)                                          (((x) & MERLIN_RF2G2_CH0_PDDIV_MASK) >> MERLIN_RF2G2_CH0_PDDIV_LSB)
#define MERLIN_RF2G2_CH0_PDDIV_SET(x)                                          (((0 | (x)) << MERLIN_RF2G2_CH0_PDDIV_LSB) & MERLIN_RF2G2_CH0_PDDIV_MASK)
#define MERLIN_RF2G2_CH0_PDDIV_RESET                                           0x0
#define MERLIN_RF2G2_CH0_PDPADRV_LSB                                           29
#define MERLIN_RF2G2_CH0_PDPADRV_MSB                                           29
#define MERLIN_RF2G2_CH0_PDPADRV_MASK                                          0x20000000
#define MERLIN_RF2G2_CH0_PDPADRV_GET(x)                                        (((x) & MERLIN_RF2G2_CH0_PDPADRV_MASK) >> MERLIN_RF2G2_CH0_PDPADRV_LSB)
#define MERLIN_RF2G2_CH0_PDPADRV_SET(x)                                        (((0 | (x)) << MERLIN_RF2G2_CH0_PDPADRV_LSB) & MERLIN_RF2G2_CH0_PDPADRV_MASK)
#define MERLIN_RF2G2_CH0_PDPADRV_RESET                                         0x0
#define MERLIN_RF2G2_CH0_PDPAOUT_LSB                                           28
#define MERLIN_RF2G2_CH0_PDPAOUT_MSB                                           28
#define MERLIN_RF2G2_CH0_PDPAOUT_MASK                                          0x10000000
#define MERLIN_RF2G2_CH0_PDPAOUT_GET(x)                                        (((x) & MERLIN_RF2G2_CH0_PDPAOUT_MASK) >> MERLIN_RF2G2_CH0_PDPAOUT_LSB)
#define MERLIN_RF2G2_CH0_PDPAOUT_SET(x)                                        (((0 | (x)) << MERLIN_RF2G2_CH0_PDPAOUT_LSB) & MERLIN_RF2G2_CH0_PDPAOUT_MASK)
#define MERLIN_RF2G2_CH0_PDPAOUT_RESET                                         0x0
#define MERLIN_RF2G2_CH0_PDREGLNA_LSB                                          27
#define MERLIN_RF2G2_CH0_PDREGLNA_MSB                                          27
#define MERLIN_RF2G2_CH0_PDREGLNA_MASK                                         0x8000000
#define MERLIN_RF2G2_CH0_PDREGLNA_GET(x)                                       (((x) & MERLIN_RF2G2_CH0_PDREGLNA_MASK) >> MERLIN_RF2G2_CH0_PDREGLNA_LSB)
#define MERLIN_RF2G2_CH0_PDREGLNA_SET(x)                                       (((0 | (x)) << MERLIN_RF2G2_CH0_PDREGLNA_LSB) & MERLIN_RF2G2_CH0_PDREGLNA_MASK)
#define MERLIN_RF2G2_CH0_PDREGLNA_RESET                                        0x0
#define MERLIN_RF2G2_CH0_PDREGLO_LSB                                           26
#define MERLIN_RF2G2_CH0_PDREGLO_MSB                                           26
#define MERLIN_RF2G2_CH0_PDREGLO_MASK                                          0x4000000
#define MERLIN_RF2G2_CH0_PDREGLO_GET(x)                                        (((x) & MERLIN_RF2G2_CH0_PDREGLO_MASK) >> MERLIN_RF2G2_CH0_PDREGLO_LSB)
#define MERLIN_RF2G2_CH0_PDREGLO_SET(x)                                        (((0 | (x)) << MERLIN_RF2G2_CH0_PDREGLO_LSB) & MERLIN_RF2G2_CH0_PDREGLO_MASK)
#define MERLIN_RF2G2_CH0_PDREGLO_RESET                                         0x0
#define MERLIN_RF2G2_CH0_PDVGM_LSB                                             25
#define MERLIN_RF2G2_CH0_PDVGM_MSB                                             25
#define MERLIN_RF2G2_CH0_PDVGM_MASK                                            0x2000000
#define MERLIN_RF2G2_CH0_PDVGM_GET(x)                                          (((x) & MERLIN_RF2G2_CH0_PDVGM_MASK) >> MERLIN_RF2G2_CH0_PDVGM_LSB)
#define MERLIN_RF2G2_CH0_PDVGM_SET(x)                                          (((0 | (x)) << MERLIN_RF2G2_CH0_PDVGM_LSB) & MERLIN_RF2G2_CH0_PDVGM_MASK)
#define MERLIN_RF2G2_CH0_PDVGM_RESET                                           0x0
#define MERLIN_RF2G2_CH0_PDRXLO_LSB                                            24
#define MERLIN_RF2G2_CH0_PDRXLO_MSB                                            24
#define MERLIN_RF2G2_CH0_PDRXLO_MASK                                           0x1000000
#define MERLIN_RF2G2_CH0_PDRXLO_GET(x)                                         (((x) & MERLIN_RF2G2_CH0_PDRXLO_MASK) >> MERLIN_RF2G2_CH0_PDRXLO_LSB)
#define MERLIN_RF2G2_CH0_PDRXLO_SET(x)                                         (((0 | (x)) << MERLIN_RF2G2_CH0_PDRXLO_LSB) & MERLIN_RF2G2_CH0_PDRXLO_MASK)
#define MERLIN_RF2G2_CH0_PDRXLO_RESET                                          0x0
#define MERLIN_RF2G2_CH0_PDTXLO_LSB                                            23
#define MERLIN_RF2G2_CH0_PDTXLO_MSB                                            23
#define MERLIN_RF2G2_CH0_PDTXLO_MASK                                           0x800000
#define MERLIN_RF2G2_CH0_PDTXLO_GET(x)                                         (((x) & MERLIN_RF2G2_CH0_PDTXLO_MASK) >> MERLIN_RF2G2_CH0_PDTXLO_LSB)
#define MERLIN_RF2G2_CH0_PDTXLO_SET(x)                                         (((0 | (x)) << MERLIN_RF2G2_CH0_PDTXLO_LSB) & MERLIN_RF2G2_CH0_PDTXLO_MASK)
#define MERLIN_RF2G2_CH0_PDTXLO_RESET                                          0x0
#define MERLIN_RF2G2_CH0_PDTXMIX_LSB                                           22
#define MERLIN_RF2G2_CH0_PDTXMIX_MSB                                           22
#define MERLIN_RF2G2_CH0_PDTXMIX_MASK                                          0x400000
#define MERLIN_RF2G2_CH0_PDTXMIX_GET(x)                                        (((x) & MERLIN_RF2G2_CH0_PDTXMIX_MASK) >> MERLIN_RF2G2_CH0_PDTXMIX_LSB)
#define MERLIN_RF2G2_CH0_PDTXMIX_SET(x)                                        (((0 | (x)) << MERLIN_RF2G2_CH0_PDTXMIX_LSB) & MERLIN_RF2G2_CH0_PDTXMIX_MASK)
#define MERLIN_RF2G2_CH0_PDTXMIX_RESET                                         0x0
#define MERLIN_RF2G2_CH0_PDIR25U_TXMIX_LSB                                     19
#define MERLIN_RF2G2_CH0_PDIR25U_TXMIX_MSB                                     21
#define MERLIN_RF2G2_CH0_PDIR25U_TXMIX_MASK                                    0x380000
#define MERLIN_RF2G2_CH0_PDIR25U_TXMIX_GET(x)                                  (((x) & MERLIN_RF2G2_CH0_PDIR25U_TXMIX_MASK) >> MERLIN_RF2G2_CH0_PDIR25U_TXMIX_LSB)
#define MERLIN_RF2G2_CH0_PDIR25U_TXMIX_SET(x)                                  (((0 | (x)) << MERLIN_RF2G2_CH0_PDIR25U_TXMIX_LSB) & MERLIN_RF2G2_CH0_PDIR25U_TXMIX_MASK)
#define MERLIN_RF2G2_CH0_PDIR25U_TXMIX_RESET                                   0x3
#define MERLIN_RF2G2_CH0_PDIR25U_TXPA_LSB                                      18
#define MERLIN_RF2G2_CH0_PDIR25U_TXPA_MSB                                      18
#define MERLIN_RF2G2_CH0_PDIR25U_TXPA_MASK                                     0x40000
#define MERLIN_RF2G2_CH0_PDIR25U_TXPA_GET(x)                                   (((x) & MERLIN_RF2G2_CH0_PDIR25U_TXPA_MASK) >> MERLIN_RF2G2_CH0_PDIR25U_TXPA_LSB)
#define MERLIN_RF2G2_CH0_PDIR25U_TXPA_SET(x)                                   (((0 | (x)) << MERLIN_RF2G2_CH0_PDIR25U_TXPA_LSB) & MERLIN_RF2G2_CH0_PDIR25U_TXPA_MASK)
#define MERLIN_RF2G2_CH0_PDIR25U_TXPA_RESET                                    0x0
#define MERLIN_RF2G2_CH0_PDIC25U_TXPA_LSB                                      15
#define MERLIN_RF2G2_CH0_PDIC25U_TXPA_MSB                                      17
#define MERLIN_RF2G2_CH0_PDIC25U_TXPA_MASK                                     0x38000
#define MERLIN_RF2G2_CH0_PDIC25U_TXPA_GET(x)                                   (((x) & MERLIN_RF2G2_CH0_PDIC25U_TXPA_MASK) >> MERLIN_RF2G2_CH0_PDIC25U_TXPA_LSB)
#define MERLIN_RF2G2_CH0_PDIC25U_TXPA_SET(x)                                   (((0 | (x)) << MERLIN_RF2G2_CH0_PDIC25U_TXPA_LSB) & MERLIN_RF2G2_CH0_PDIC25U_TXPA_MASK)
#define MERLIN_RF2G2_CH0_PDIC25U_TXPA_RESET                                    0x3
#define MERLIN_RF2G2_CH0_PDIC25U_TXRF_LSB                                      12
#define MERLIN_RF2G2_CH0_PDIC25U_TXRF_MSB                                      14
#define MERLIN_RF2G2_CH0_PDIC25U_TXRF_MASK                                     0x7000
#define MERLIN_RF2G2_CH0_PDIC25U_TXRF_GET(x)                                   (((x) & MERLIN_RF2G2_CH0_PDIC25U_TXRF_MASK) >> MERLIN_RF2G2_CH0_PDIC25U_TXRF_LSB)
#define MERLIN_RF2G2_CH0_PDIC25U_TXRF_SET(x)                                   (((0 | (x)) << MERLIN_RF2G2_CH0_PDIC25U_TXRF_LSB) & MERLIN_RF2G2_CH0_PDIC25U_TXRF_MASK)
#define MERLIN_RF2G2_CH0_PDIC25U_TXRF_RESET                                    0x3
#define MERLIN_RF2G2_CH0_PDIC25U_RXRF_LSB                                      9
#define MERLIN_RF2G2_CH0_PDIC25U_RXRF_MSB                                      11
#define MERLIN_RF2G2_CH0_PDIC25U_RXRF_MASK                                     0xe00
#define MERLIN_RF2G2_CH0_PDIC25U_RXRF_GET(x)                                   (((x) & MERLIN_RF2G2_CH0_PDIC25U_RXRF_MASK) >> MERLIN_RF2G2_CH0_PDIC25U_RXRF_LSB)
#define MERLIN_RF2G2_CH0_PDIC25U_RXRF_SET(x)                                   (((0 | (x)) << MERLIN_RF2G2_CH0_PDIC25U_RXRF_LSB) & MERLIN_RF2G2_CH0_PDIC25U_RXRF_MASK)
#define MERLIN_RF2G2_CH0_PDIC25U_RXRF_RESET                                    0x7
#define MERLIN_RF2G2_CH0_PDIC50U_DIV_LSB                                       6
#define MERLIN_RF2G2_CH0_PDIC50U_DIV_MSB                                       8
#define MERLIN_RF2G2_CH0_PDIC50U_DIV_MASK                                      0x1c0
#define MERLIN_RF2G2_CH0_PDIC50U_DIV_GET(x)                                    (((x) & MERLIN_RF2G2_CH0_PDIC50U_DIV_MASK) >> MERLIN_RF2G2_CH0_PDIC50U_DIV_LSB)
#define MERLIN_RF2G2_CH0_PDIC50U_DIV_SET(x)                                    (((0 | (x)) << MERLIN_RF2G2_CH0_PDIC50U_DIV_LSB) & MERLIN_RF2G2_CH0_PDIC50U_DIV_MASK)
#define MERLIN_RF2G2_CH0_PDIC50U_DIV_RESET                                     0x3
#define MERLIN_RF2G2_CH0_PDIC25U_VREGLO_LSB                                    3
#define MERLIN_RF2G2_CH0_PDIC25U_VREGLO_MSB                                    5
#define MERLIN_RF2G2_CH0_PDIC25U_VREGLO_MASK                                   0x38
#define MERLIN_RF2G2_CH0_PDIC25U_VREGLO_GET(x)                                 (((x) & MERLIN_RF2G2_CH0_PDIC25U_VREGLO_MASK) >> MERLIN_RF2G2_CH0_PDIC25U_VREGLO_LSB)
#define MERLIN_RF2G2_CH0_PDIC25U_VREGLO_SET(x)                                 (((0 | (x)) << MERLIN_RF2G2_CH0_PDIC25U_VREGLO_LSB) & MERLIN_RF2G2_CH0_PDIC25U_VREGLO_MASK)
#define MERLIN_RF2G2_CH0_PDIC25U_VREGLO_RESET                                  0x7
#define MERLIN_RF2G2_CH0_PDIR25U_VREGLO_LSB                                    0
#define MERLIN_RF2G2_CH0_PDIR25U_VREGLO_MSB                                    2
#define MERLIN_RF2G2_CH0_PDIR25U_VREGLO_MASK                                   0x7
#define MERLIN_RF2G2_CH0_PDIR25U_VREGLO_GET(x)                                 (((x) & MERLIN_RF2G2_CH0_PDIR25U_VREGLO_MASK) >> MERLIN_RF2G2_CH0_PDIR25U_VREGLO_LSB)
#define MERLIN_RF2G2_CH0_PDIR25U_VREGLO_SET(x)                                 (((0 | (x)) << MERLIN_RF2G2_CH0_PDIR25U_VREGLO_LSB) & MERLIN_RF2G2_CH0_PDIR25U_VREGLO_MASK)
#define MERLIN_RF2G2_CH0_PDIR25U_VREGLO_RESET                                  0x7
#define MERLIN_RF2G2_CH0_ADDRESS                                               (0x38 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RF2G2_CH0_RSTMASK                                               0xffffffff
#define MERLIN_RF2G2_CH0_RESET                                                 0x19beff

// 0x3c (MERLIN_RF5G1_CH0)
#define MERLIN_RF5G1_CH0_PDTXLO5_LSB                                           31
#define MERLIN_RF5G1_CH0_PDTXLO5_MSB                                           31
#define MERLIN_RF5G1_CH0_PDTXLO5_MASK                                          0x80000000
#define MERLIN_RF5G1_CH0_PDTXLO5_GET(x)                                        (((x) & MERLIN_RF5G1_CH0_PDTXLO5_MASK) >> MERLIN_RF5G1_CH0_PDTXLO5_LSB)
#define MERLIN_RF5G1_CH0_PDTXLO5_SET(x)                                        (((0 | (x)) << MERLIN_RF5G1_CH0_PDTXLO5_LSB) & MERLIN_RF5G1_CH0_PDTXLO5_MASK)
#define MERLIN_RF5G1_CH0_PDTXLO5_RESET                                         0x0
#define MERLIN_RF5G1_CH0_PDTXMIX5_LSB                                          30
#define MERLIN_RF5G1_CH0_PDTXMIX5_MSB                                          30
#define MERLIN_RF5G1_CH0_PDTXMIX5_MASK                                         0x40000000
#define MERLIN_RF5G1_CH0_PDTXMIX5_GET(x)                                       (((x) & MERLIN_RF5G1_CH0_PDTXMIX5_MASK) >> MERLIN_RF5G1_CH0_PDTXMIX5_LSB)
#define MERLIN_RF5G1_CH0_PDTXMIX5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH0_PDTXMIX5_LSB) & MERLIN_RF5G1_CH0_PDTXMIX5_MASK)
#define MERLIN_RF5G1_CH0_PDTXMIX5_RESET                                        0x0
#define MERLIN_RF5G1_CH0_PDTXBUF5_LSB                                          29
#define MERLIN_RF5G1_CH0_PDTXBUF5_MSB                                          29
#define MERLIN_RF5G1_CH0_PDTXBUF5_MASK                                         0x20000000
#define MERLIN_RF5G1_CH0_PDTXBUF5_GET(x)                                       (((x) & MERLIN_RF5G1_CH0_PDTXBUF5_MASK) >> MERLIN_RF5G1_CH0_PDTXBUF5_LSB)
#define MERLIN_RF5G1_CH0_PDTXBUF5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH0_PDTXBUF5_LSB) & MERLIN_RF5G1_CH0_PDTXBUF5_MASK)
#define MERLIN_RF5G1_CH0_PDTXBUF5_RESET                                        0x0
#define MERLIN_RF5G1_CH0_PDPADRV5_LSB                                          28
#define MERLIN_RF5G1_CH0_PDPADRV5_MSB                                          28
#define MERLIN_RF5G1_CH0_PDPADRV5_MASK                                         0x10000000
#define MERLIN_RF5G1_CH0_PDPADRV5_GET(x)                                       (((x) & MERLIN_RF5G1_CH0_PDPADRV5_MASK) >> MERLIN_RF5G1_CH0_PDPADRV5_LSB)
#define MERLIN_RF5G1_CH0_PDPADRV5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH0_PDPADRV5_LSB) & MERLIN_RF5G1_CH0_PDPADRV5_MASK)
#define MERLIN_RF5G1_CH0_PDPADRV5_RESET                                        0x0
#define MERLIN_RF5G1_CH0_PDPAOUT5_LSB                                          27
#define MERLIN_RF5G1_CH0_PDPAOUT5_MSB                                          27
#define MERLIN_RF5G1_CH0_PDPAOUT5_MASK                                         0x8000000
#define MERLIN_RF5G1_CH0_PDPAOUT5_GET(x)                                       (((x) & MERLIN_RF5G1_CH0_PDPAOUT5_MASK) >> MERLIN_RF5G1_CH0_PDPAOUT5_LSB)
#define MERLIN_RF5G1_CH0_PDPAOUT5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH0_PDPAOUT5_LSB) & MERLIN_RF5G1_CH0_PDPAOUT5_MASK)
#define MERLIN_RF5G1_CH0_PDPAOUT5_RESET                                        0x0
#define MERLIN_RF5G1_CH0_PACASCBIAS_LSB                                        25
#define MERLIN_RF5G1_CH0_PACASCBIAS_MSB                                        26
#define MERLIN_RF5G1_CH0_PACASCBIAS_MASK                                       0x6000000
#define MERLIN_RF5G1_CH0_PACASCBIAS_GET(x)                                     (((x) & MERLIN_RF5G1_CH0_PACASCBIAS_MASK) >> MERLIN_RF5G1_CH0_PACASCBIAS_LSB)
#define MERLIN_RF5G1_CH0_PACASCBIAS_SET(x)                                     (((0 | (x)) << MERLIN_RF5G1_CH0_PACASCBIAS_LSB) & MERLIN_RF5G1_CH0_PACASCBIAS_MASK)
#define MERLIN_RF5G1_CH0_PACASCBIAS_RESET                                      0x3
#define MERLIN_RF5G1_CH0_PWDTXPKD_LSB                                          22
#define MERLIN_RF5G1_CH0_PWDTXPKD_MSB                                          24
#define MERLIN_RF5G1_CH0_PWDTXPKD_MASK                                         0x1c00000
#define MERLIN_RF5G1_CH0_PWDTXPKD_GET(x)                                       (((x) & MERLIN_RF5G1_CH0_PWDTXPKD_MASK) >> MERLIN_RF5G1_CH0_PWDTXPKD_LSB)
#define MERLIN_RF5G1_CH0_PWDTXPKD_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH0_PWDTXPKD_LSB) & MERLIN_RF5G1_CH0_PWDTXPKD_MASK)
#define MERLIN_RF5G1_CH0_PWDTXPKD_RESET                                        0x7
#define MERLIN_RF5G1_CH0_DB5_LSB                                               19
#define MERLIN_RF5G1_CH0_DB5_MSB                                               21
#define MERLIN_RF5G1_CH0_DB5_MASK                                              0x380000
#define MERLIN_RF5G1_CH0_DB5_GET(x)                                            (((x) & MERLIN_RF5G1_CH0_DB5_MASK) >> MERLIN_RF5G1_CH0_DB5_LSB)
#define MERLIN_RF5G1_CH0_DB5_SET(x)                                            (((0 | (x)) << MERLIN_RF5G1_CH0_DB5_LSB) & MERLIN_RF5G1_CH0_DB5_MASK)
#define MERLIN_RF5G1_CH0_DB5_RESET                                             0x4
#define MERLIN_RF5G1_CH0_OB5_LSB                                               16
#define MERLIN_RF5G1_CH0_OB5_MSB                                               18
#define MERLIN_RF5G1_CH0_OB5_MASK                                              0x70000
#define MERLIN_RF5G1_CH0_OB5_GET(x)                                            (((x) & MERLIN_RF5G1_CH0_OB5_MASK) >> MERLIN_RF5G1_CH0_OB5_LSB)
#define MERLIN_RF5G1_CH0_OB5_SET(x)                                            (((0 | (x)) << MERLIN_RF5G1_CH0_OB5_LSB) & MERLIN_RF5G1_CH0_OB5_MASK)
#define MERLIN_RF5G1_CH0_OB5_RESET                                             0x4
#define MERLIN_RF5G1_CH0_TX5_ATB_SEL_LSB                                       13
#define MERLIN_RF5G1_CH0_TX5_ATB_SEL_MSB                                       15
#define MERLIN_RF5G1_CH0_TX5_ATB_SEL_MASK                                      0xe000
#define MERLIN_RF5G1_CH0_TX5_ATB_SEL_GET(x)                                    (((x) & MERLIN_RF5G1_CH0_TX5_ATB_SEL_MASK) >> MERLIN_RF5G1_CH0_TX5_ATB_SEL_LSB)
#define MERLIN_RF5G1_CH0_TX5_ATB_SEL_SET(x)                                    (((0 | (x)) << MERLIN_RF5G1_CH0_TX5_ATB_SEL_LSB) & MERLIN_RF5G1_CH0_TX5_ATB_SEL_MASK)
#define MERLIN_RF5G1_CH0_TX5_ATB_SEL_RESET                                     0x0
#define MERLIN_RF5G1_CH0_LO5CONTROL_LSB                                        12
#define MERLIN_RF5G1_CH0_LO5CONTROL_MSB                                        12
#define MERLIN_RF5G1_CH0_LO5CONTROL_MASK                                       0x1000
#define MERLIN_RF5G1_CH0_LO5CONTROL_GET(x)                                     (((x) & MERLIN_RF5G1_CH0_LO5CONTROL_MASK) >> MERLIN_RF5G1_CH0_LO5CONTROL_LSB)
#define MERLIN_RF5G1_CH0_LO5CONTROL_SET(x)                                     (((0 | (x)) << MERLIN_RF5G1_CH0_LO5CONTROL_LSB) & MERLIN_RF5G1_CH0_LO5CONTROL_MASK)
#define MERLIN_RF5G1_CH0_LO5CONTROL_RESET                                      0x0
#define MERLIN_RF5G1_CH0_REGLO_BYPASS5_LSB                                     11
#define MERLIN_RF5G1_CH0_REGLO_BYPASS5_MSB                                     11
#define MERLIN_RF5G1_CH0_REGLO_BYPASS5_MASK                                    0x800
#define MERLIN_RF5G1_CH0_REGLO_BYPASS5_GET(x)                                  (((x) & MERLIN_RF5G1_CH0_REGLO_BYPASS5_MASK) >> MERLIN_RF5G1_CH0_REGLO_BYPASS5_LSB)
#define MERLIN_RF5G1_CH0_REGLO_BYPASS5_SET(x)                                  (((0 | (x)) << MERLIN_RF5G1_CH0_REGLO_BYPASS5_LSB) & MERLIN_RF5G1_CH0_REGLO_BYPASS5_MASK)
#define MERLIN_RF5G1_CH0_REGLO_BYPASS5_RESET                                   0x0
#define MERLIN_RF5G1_CH0_PDREGLO5_LSB                                          10
#define MERLIN_RF5G1_CH0_PDREGLO5_MSB                                          10
#define MERLIN_RF5G1_CH0_PDREGLO5_MASK                                         0x400
#define MERLIN_RF5G1_CH0_PDREGLO5_GET(x)                                       (((x) & MERLIN_RF5G1_CH0_PDREGLO5_MASK) >> MERLIN_RF5G1_CH0_PDREGLO5_LSB)
#define MERLIN_RF5G1_CH0_PDREGLO5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G1_CH0_PDREGLO5_LSB) & MERLIN_RF5G1_CH0_PDREGLO5_MASK)
#define MERLIN_RF5G1_CH0_PDREGLO5_RESET                                        0x0
#define MERLIN_RF5G1_CH0_SPARE_LSB                                             0
#define MERLIN_RF5G1_CH0_SPARE_MSB                                             9
#define MERLIN_RF5G1_CH0_SPARE_MASK                                            0x3ff
#define MERLIN_RF5G1_CH0_SPARE_GET(x)                                          (((x) & MERLIN_RF5G1_CH0_SPARE_MASK) >> MERLIN_RF5G1_CH0_SPARE_LSB)
#define MERLIN_RF5G1_CH0_SPARE_SET(x)                                          (((0 | (x)) << MERLIN_RF5G1_CH0_SPARE_LSB) & MERLIN_RF5G1_CH0_SPARE_MASK)
#define MERLIN_RF5G1_CH0_SPARE_RESET                                           0x0
#define MERLIN_RF5G1_CH0_ADDRESS                                               (0x3c + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RF5G1_CH0_RSTMASK                                               0xffffffff
#define MERLIN_RF5G1_CH0_RESET                                                 0x7e40000

// 0x40 (MERLIN_RF5G2_CH0)
#define MERLIN_RF5G2_CH0_REGFE_BYPASS5_LSB                                     31
#define MERLIN_RF5G2_CH0_REGFE_BYPASS5_MSB                                     31
#define MERLIN_RF5G2_CH0_REGFE_BYPASS5_MASK                                    0x80000000
#define MERLIN_RF5G2_CH0_REGFE_BYPASS5_GET(x)                                  (((x) & MERLIN_RF5G2_CH0_REGFE_BYPASS5_MASK) >> MERLIN_RF5G2_CH0_REGFE_BYPASS5_LSB)
#define MERLIN_RF5G2_CH0_REGFE_BYPASS5_SET(x)                                  (((0 | (x)) << MERLIN_RF5G2_CH0_REGFE_BYPASS5_LSB) & MERLIN_RF5G2_CH0_REGFE_BYPASS5_MASK)
#define MERLIN_RF5G2_CH0_REGFE_BYPASS5_RESET                                   0x0
#define MERLIN_RF5G2_CH0_PDREGFE5_LSB                                          30
#define MERLIN_RF5G2_CH0_PDREGFE5_MSB                                          30
#define MERLIN_RF5G2_CH0_PDREGFE5_MASK                                         0x40000000
#define MERLIN_RF5G2_CH0_PDREGFE5_GET(x)                                       (((x) & MERLIN_RF5G2_CH0_PDREGFE5_MASK) >> MERLIN_RF5G2_CH0_PDREGFE5_LSB)
#define MERLIN_RF5G2_CH0_PDREGFE5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G2_CH0_PDREGFE5_LSB) & MERLIN_RF5G2_CH0_PDREGFE5_MASK)
#define MERLIN_RF5G2_CH0_PDREGFE5_RESET                                        0x0
#define MERLIN_RF5G2_CH0_PDRXLO5_LSB                                           29
#define MERLIN_RF5G2_CH0_PDRXLO5_MSB                                           29
#define MERLIN_RF5G2_CH0_PDRXLO5_MASK                                          0x20000000
#define MERLIN_RF5G2_CH0_PDRXLO5_GET(x)                                        (((x) & MERLIN_RF5G2_CH0_PDRXLO5_MASK) >> MERLIN_RF5G2_CH0_PDRXLO5_LSB)
#define MERLIN_RF5G2_CH0_PDRXLO5_SET(x)                                        (((0 | (x)) << MERLIN_RF5G2_CH0_PDRXLO5_LSB) & MERLIN_RF5G2_CH0_PDRXLO5_MASK)
#define MERLIN_RF5G2_CH0_PDRXLO5_RESET                                         0x0
#define MERLIN_RF5G2_CH0_PDVGM5_LSB                                            28
#define MERLIN_RF5G2_CH0_PDVGM5_MSB                                            28
#define MERLIN_RF5G2_CH0_PDVGM5_MASK                                           0x10000000
#define MERLIN_RF5G2_CH0_PDVGM5_GET(x)                                         (((x) & MERLIN_RF5G2_CH0_PDVGM5_MASK) >> MERLIN_RF5G2_CH0_PDVGM5_LSB)
#define MERLIN_RF5G2_CH0_PDVGM5_SET(x)                                         (((0 | (x)) << MERLIN_RF5G2_CH0_PDVGM5_LSB) & MERLIN_RF5G2_CH0_PDVGM5_MASK)
#define MERLIN_RF5G2_CH0_PDVGM5_RESET                                          0x0
#define MERLIN_RF5G2_CH0_PDCSLNA5_LSB                                          27
#define MERLIN_RF5G2_CH0_PDCSLNA5_MSB                                          27
#define MERLIN_RF5G2_CH0_PDCSLNA5_MASK                                         0x8000000
#define MERLIN_RF5G2_CH0_PDCSLNA5_GET(x)                                       (((x) & MERLIN_RF5G2_CH0_PDCSLNA5_MASK) >> MERLIN_RF5G2_CH0_PDCSLNA5_LSB)
#define MERLIN_RF5G2_CH0_PDCSLNA5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G2_CH0_PDCSLNA5_LSB) & MERLIN_RF5G2_CH0_PDCSLNA5_MASK)
#define MERLIN_RF5G2_CH0_PDCSLNA5_RESET                                        0x0
#define MERLIN_RF5G2_CH0_PDRFVGA5_LSB                                          26
#define MERLIN_RF5G2_CH0_PDRFVGA5_MSB                                          26
#define MERLIN_RF5G2_CH0_PDRFVGA5_MASK                                         0x4000000
#define MERLIN_RF5G2_CH0_PDRFVGA5_GET(x)                                       (((x) & MERLIN_RF5G2_CH0_PDRFVGA5_MASK) >> MERLIN_RF5G2_CH0_PDRFVGA5_LSB)
#define MERLIN_RF5G2_CH0_PDRFVGA5_SET(x)                                       (((0 | (x)) << MERLIN_RF5G2_CH0_PDRFVGA5_LSB) & MERLIN_RF5G2_CH0_PDRFVGA5_MASK)
#define MERLIN_RF5G2_CH0_PDRFVGA5_RESET                                        0x0
#define MERLIN_RF5G2_CH0_RX5_ATB_SEL_LSB                                       23
#define MERLIN_RF5G2_CH0_RX5_ATB_SEL_MSB                                       25
#define MERLIN_RF5G2_CH0_RX5_ATB_SEL_MASK                                      0x3800000
#define MERLIN_RF5G2_CH0_RX5_ATB_SEL_GET(x)                                    (((x) & MERLIN_RF5G2_CH0_RX5_ATB_SEL_MASK) >> MERLIN_RF5G2_CH0_RX5_ATB_SEL_LSB)
#define MERLIN_RF5G2_CH0_RX5_ATB_SEL_SET(x)                                    (((0 | (x)) << MERLIN_RF5G2_CH0_RX5_ATB_SEL_LSB) & MERLIN_RF5G2_CH0_RX5_ATB_SEL_MASK)
#define MERLIN_RF5G2_CH0_RX5_ATB_SEL_RESET                                     0x0
#define MERLIN_RF5G2_CH0_PDBIRTXMIX_LSB                                        20
#define MERLIN_RF5G2_CH0_PDBIRTXMIX_MSB                                        22
#define MERLIN_RF5G2_CH0_PDBIRTXMIX_MASK                                       0x700000
#define MERLIN_RF5G2_CH0_PDBIRTXMIX_GET(x)                                     (((x) & MERLIN_RF5G2_CH0_PDBIRTXMIX_MASK) >> MERLIN_RF5G2_CH0_PDBIRTXMIX_LSB)
#define MERLIN_RF5G2_CH0_PDBIRTXMIX_SET(x)                                     (((0 | (x)) << MERLIN_RF5G2_CH0_PDBIRTXMIX_LSB) & MERLIN_RF5G2_CH0_PDBIRTXMIX_MASK)
#define MERLIN_RF5G2_CH0_PDBIRTXMIX_RESET                                      0x4
#define MERLIN_RF5G2_CH0_PDBIRTXPA_LSB                                         17
#define MERLIN_RF5G2_CH0_PDBIRTXPA_MSB                                         19
#define MERLIN_RF5G2_CH0_PDBIRTXPA_MASK                                        0xe0000
#define MERLIN_RF5G2_CH0_PDBIRTXPA_GET(x)                                      (((x) & MERLIN_RF5G2_CH0_PDBIRTXPA_MASK) >> MERLIN_RF5G2_CH0_PDBIRTXPA_LSB)
#define MERLIN_RF5G2_CH0_PDBIRTXPA_SET(x)                                      (((0 | (x)) << MERLIN_RF5G2_CH0_PDBIRTXPA_LSB) & MERLIN_RF5G2_CH0_PDBIRTXPA_MASK)
#define MERLIN_RF5G2_CH0_PDBIRTXPA_RESET                                       0x4
#define MERLIN_RF5G2_CH0_PDBIR1_LSB                                            14
#define MERLIN_RF5G2_CH0_PDBIR1_MSB                                            16
#define MERLIN_RF5G2_CH0_PDBIR1_MASK                                           0x1c000
#define MERLIN_RF5G2_CH0_PDBIR1_GET(x)                                         (((x) & MERLIN_RF5G2_CH0_PDBIR1_MASK) >> MERLIN_RF5G2_CH0_PDBIR1_LSB)
#define MERLIN_RF5G2_CH0_PDBIR1_SET(x)                                         (((0 | (x)) << MERLIN_RF5G2_CH0_PDBIR1_LSB) & MERLIN_RF5G2_CH0_PDBIR1_MASK)
#define MERLIN_RF5G2_CH0_PDBIR1_RESET                                          0x4
#define MERLIN_RF5G2_CH0_PDBIR2_LSB                                            11
#define MERLIN_RF5G2_CH0_PDBIR2_MSB                                            13
#define MERLIN_RF5G2_CH0_PDBIR2_MASK                                           0x3800
#define MERLIN_RF5G2_CH0_PDBIR2_GET(x)                                         (((x) & MERLIN_RF5G2_CH0_PDBIR2_MASK) >> MERLIN_RF5G2_CH0_PDBIR2_LSB)
#define MERLIN_RF5G2_CH0_PDBIR2_SET(x)                                         (((0 | (x)) << MERLIN_RF5G2_CH0_PDBIR2_LSB) & MERLIN_RF5G2_CH0_PDBIR2_MASK)
#define MERLIN_RF5G2_CH0_PDBIR2_RESET                                          0x4
#define MERLIN_RF5G2_CH0_SPARE_LSB                                             0
#define MERLIN_RF5G2_CH0_SPARE_MSB                                             10
#define MERLIN_RF5G2_CH0_SPARE_MASK                                            0x7ff
#define MERLIN_RF5G2_CH0_SPARE_GET(x)                                          (((x) & MERLIN_RF5G2_CH0_SPARE_MASK) >> MERLIN_RF5G2_CH0_SPARE_LSB)
#define MERLIN_RF5G2_CH0_SPARE_SET(x)                                          (((0 | (x)) << MERLIN_RF5G2_CH0_SPARE_LSB) & MERLIN_RF5G2_CH0_SPARE_MASK)
#define MERLIN_RF5G2_CH0_SPARE_RESET                                           0x0
#define MERLIN_RF5G2_CH0_ADDRESS                                               (0x40 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RF5G2_CH0_RSTMASK                                               0xffffffff
#define MERLIN_RF5G2_CH0_RESET                                                 0x492000

// 0x44 (MERLIN_RF5G3_CH0)
#define MERLIN_RF5G3_CH0_PDBICTXBUF_LSB                                        29
#define MERLIN_RF5G3_CH0_PDBICTXBUF_MSB                                        31
#define MERLIN_RF5G3_CH0_PDBICTXBUF_MASK                                       0xe0000000
#define MERLIN_RF5G3_CH0_PDBICTXBUF_GET(x)                                     (((x) & MERLIN_RF5G3_CH0_PDBICTXBUF_MASK) >> MERLIN_RF5G3_CH0_PDBICTXBUF_LSB)
#define MERLIN_RF5G3_CH0_PDBICTXBUF_SET(x)                                     (((0 | (x)) << MERLIN_RF5G3_CH0_PDBICTXBUF_LSB) & MERLIN_RF5G3_CH0_PDBICTXBUF_MASK)
#define MERLIN_RF5G3_CH0_PDBICTXBUF_RESET                                      0x4
#define MERLIN_RF5G3_CH0_PDBICTXPA_LSB                                         26
#define MERLIN_RF5G3_CH0_PDBICTXPA_MSB                                         28
#define MERLIN_RF5G3_CH0_PDBICTXPA_MASK                                        0x1c000000
#define MERLIN_RF5G3_CH0_PDBICTXPA_GET(x)                                      (((x) & MERLIN_RF5G3_CH0_PDBICTXPA_MASK) >> MERLIN_RF5G3_CH0_PDBICTXPA_LSB)
#define MERLIN_RF5G3_CH0_PDBICTXPA_SET(x)                                      (((0 | (x)) << MERLIN_RF5G3_CH0_PDBICTXPA_LSB) & MERLIN_RF5G3_CH0_PDBICTXPA_MASK)
#define MERLIN_RF5G3_CH0_PDBICTXPA_RESET                                       0x4
#define MERLIN_RF5G3_CH0_PDBICTXMIX_LSB                                        23
#define MERLIN_RF5G3_CH0_PDBICTXMIX_MSB                                        25
#define MERLIN_RF5G3_CH0_PDBICTXMIX_MASK                                       0x3800000
#define MERLIN_RF5G3_CH0_PDBICTXMIX_GET(x)                                     (((x) & MERLIN_RF5G3_CH0_PDBICTXMIX_MASK) >> MERLIN_RF5G3_CH0_PDBICTXMIX_LSB)
#define MERLIN_RF5G3_CH0_PDBICTXMIX_SET(x)                                     (((0 | (x)) << MERLIN_RF5G3_CH0_PDBICTXMIX_LSB) & MERLIN_RF5G3_CH0_PDBICTXMIX_MASK)
#define MERLIN_RF5G3_CH0_PDBICTXMIX_RESET                                      0x4
#define MERLIN_RF5G3_CH0_PDBIC1_LSB                                            20
#define MERLIN_RF5G3_CH0_PDBIC1_MSB                                            22
#define MERLIN_RF5G3_CH0_PDBIC1_MASK                                           0x700000
#define MERLIN_RF5G3_CH0_PDBIC1_GET(x)                                         (((x) & MERLIN_RF5G3_CH0_PDBIC1_MASK) >> MERLIN_RF5G3_CH0_PDBIC1_LSB)
#define MERLIN_RF5G3_CH0_PDBIC1_SET(x)                                         (((0 | (x)) << MERLIN_RF5G3_CH0_PDBIC1_LSB) & MERLIN_RF5G3_CH0_PDBIC1_MASK)
#define MERLIN_RF5G3_CH0_PDBIC1_RESET                                          0x4
#define MERLIN_RF5G3_CH0_PDBIC2_LSB                                            17
#define MERLIN_RF5G3_CH0_PDBIC2_MSB                                            19
#define MERLIN_RF5G3_CH0_PDBIC2_MASK                                           0xe0000
#define MERLIN_RF5G3_CH0_PDBIC2_GET(x)                                         (((x) & MERLIN_RF5G3_CH0_PDBIC2_MASK) >> MERLIN_RF5G3_CH0_PDBIC2_LSB)
#define MERLIN_RF5G3_CH0_PDBIC2_SET(x)                                         (((0 | (x)) << MERLIN_RF5G3_CH0_PDBIC2_LSB) & MERLIN_RF5G3_CH0_PDBIC2_MASK)
#define MERLIN_RF5G3_CH0_PDBIC2_RESET                                          0x4
#define MERLIN_RF5G3_CH0_PDBIC3_LSB                                            14
#define MERLIN_RF5G3_CH0_PDBIC3_MSB                                            16
#define MERLIN_RF5G3_CH0_PDBIC3_MASK                                           0x1c000
#define MERLIN_RF5G3_CH0_PDBIC3_GET(x)                                         (((x) & MERLIN_RF5G3_CH0_PDBIC3_MASK) >> MERLIN_RF5G3_CH0_PDBIC3_LSB)
#define MERLIN_RF5G3_CH0_PDBIC3_SET(x)                                         (((0 | (x)) << MERLIN_RF5G3_CH0_PDBIC3_LSB) & MERLIN_RF5G3_CH0_PDBIC3_MASK)
#define MERLIN_RF5G3_CH0_PDBIC3_RESET                                          0x4
#define MERLIN_RF5G3_CH0_PDBIBCLNA_LSB                                         11
#define MERLIN_RF5G3_CH0_PDBIBCLNA_MSB                                         13
#define MERLIN_RF5G3_CH0_PDBIBCLNA_MASK                                        0x3800
#define MERLIN_RF5G3_CH0_PDBIBCLNA_GET(x)                                      (((x) & MERLIN_RF5G3_CH0_PDBIBCLNA_MASK) >> MERLIN_RF5G3_CH0_PDBIBCLNA_LSB)
#define MERLIN_RF5G3_CH0_PDBIBCLNA_SET(x)                                      (((0 | (x)) << MERLIN_RF5G3_CH0_PDBIBCLNA_LSB) & MERLIN_RF5G3_CH0_PDBIBCLNA_MASK)
#define MERLIN_RF5G3_CH0_PDBIBCLNA_RESET                                       0x4
#define MERLIN_RF5G3_CH0_PDBIBCRFVGA_LSB                                       8
#define MERLIN_RF5G3_CH0_PDBIBCRFVGA_MSB                                       10
#define MERLIN_RF5G3_CH0_PDBIBCRFVGA_MASK                                      0x700
#define MERLIN_RF5G3_CH0_PDBIBCRFVGA_GET(x)                                    (((x) & MERLIN_RF5G3_CH0_PDBIBCRFVGA_MASK) >> MERLIN_RF5G3_CH0_PDBIBCRFVGA_LSB)
#define MERLIN_RF5G3_CH0_PDBIBCRFVGA_SET(x)                                    (((0 | (x)) << MERLIN_RF5G3_CH0_PDBIBCRFVGA_LSB) & MERLIN_RF5G3_CH0_PDBIBCRFVGA_MASK)
#define MERLIN_RF5G3_CH0_PDBIBCRFVGA_RESET                                     0x4
#define MERLIN_RF5G3_CH0_PDBIBCVGM_LSB                                         5
#define MERLIN_RF5G3_CH0_PDBIBCVGM_MSB                                         7
#define MERLIN_RF5G3_CH0_PDBIBCVGM_MASK                                        0xe0
#define MERLIN_RF5G3_CH0_PDBIBCVGM_GET(x)                                      (((x) & MERLIN_RF5G3_CH0_PDBIBCVGM_MASK) >> MERLIN_RF5G3_CH0_PDBIBCVGM_LSB)
#define MERLIN_RF5G3_CH0_PDBIBCVGM_SET(x)                                      (((0 | (x)) << MERLIN_RF5G3_CH0_PDBIBCVGM_LSB) & MERLIN_RF5G3_CH0_PDBIBCVGM_MASK)
#define MERLIN_RF5G3_CH0_PDBIBCVGM_RESET                                       0x4
#define MERLIN_RF5G3_CH0_SPARE_LSB                                             0
#define MERLIN_RF5G3_CH0_SPARE_MSB                                             4
#define MERLIN_RF5G3_CH0_SPARE_MASK                                            0x1f
#define MERLIN_RF5G3_CH0_SPARE_GET(x)                                          (((x) & MERLIN_RF5G3_CH0_SPARE_MASK) >> MERLIN_RF5G3_CH0_SPARE_LSB)
#define MERLIN_RF5G3_CH0_SPARE_SET(x)                                          (((0 | (x)) << MERLIN_RF5G3_CH0_SPARE_LSB) & MERLIN_RF5G3_CH0_SPARE_MASK)
#define MERLIN_RF5G3_CH0_SPARE_RESET                                           0x0
#define MERLIN_RF5G3_CH0_ADDRESS                                               (0x44 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_RF5G3_CH0_RSTMASK                                               0xffffffff
#define MERLIN_RF5G3_CH0_RESET                                                 0x92492480

// 0x48 (MERLIN_SYNTH1)
#define MERLIN_SYNTH1_PWD_BIAS_LSB                                             31
#define MERLIN_SYNTH1_PWD_BIAS_MSB                                             31
#define MERLIN_SYNTH1_PWD_BIAS_MASK                                            0x80000000
#define MERLIN_SYNTH1_PWD_BIAS_GET(x)                                          (((x) & MERLIN_SYNTH1_PWD_BIAS_MASK) >> MERLIN_SYNTH1_PWD_BIAS_LSB)
#define MERLIN_SYNTH1_PWD_BIAS_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH1_PWD_BIAS_LSB) & MERLIN_SYNTH1_PWD_BIAS_MASK)
#define MERLIN_SYNTH1_PWD_BIAS_RESET                                           0x0
#define MERLIN_SYNTH1_PWD_CP_LSB                                               30
#define MERLIN_SYNTH1_PWD_CP_MSB                                               30
#define MERLIN_SYNTH1_PWD_CP_MASK                                              0x40000000
#define MERLIN_SYNTH1_PWD_CP_GET(x)                                            (((x) & MERLIN_SYNTH1_PWD_CP_MASK) >> MERLIN_SYNTH1_PWD_CP_LSB)
#define MERLIN_SYNTH1_PWD_CP_SET(x)                                            (((0 | (x)) << MERLIN_SYNTH1_PWD_CP_LSB) & MERLIN_SYNTH1_PWD_CP_MASK)
#define MERLIN_SYNTH1_PWD_CP_RESET                                             0x0
#define MERLIN_SYNTH1_PWD_VCMON_LSB                                            29
#define MERLIN_SYNTH1_PWD_VCMON_MSB                                            29
#define MERLIN_SYNTH1_PWD_VCMON_MASK                                           0x20000000
#define MERLIN_SYNTH1_PWD_VCMON_GET(x)                                         (((x) & MERLIN_SYNTH1_PWD_VCMON_MASK) >> MERLIN_SYNTH1_PWD_VCMON_LSB)
#define MERLIN_SYNTH1_PWD_VCMON_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH1_PWD_VCMON_LSB) & MERLIN_SYNTH1_PWD_VCMON_MASK)
#define MERLIN_SYNTH1_PWD_VCMON_RESET                                          0x0
#define MERLIN_SYNTH1_PWD_VCO_LSB                                              28
#define MERLIN_SYNTH1_PWD_VCO_MSB                                              28
#define MERLIN_SYNTH1_PWD_VCO_MASK                                             0x10000000
#define MERLIN_SYNTH1_PWD_VCO_GET(x)                                           (((x) & MERLIN_SYNTH1_PWD_VCO_MASK) >> MERLIN_SYNTH1_PWD_VCO_LSB)
#define MERLIN_SYNTH1_PWD_VCO_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH1_PWD_VCO_LSB) & MERLIN_SYNTH1_PWD_VCO_MASK)
#define MERLIN_SYNTH1_PWD_VCO_RESET                                            0x0
#define MERLIN_SYNTH1_PWD_PRESC_LSB                                            27
#define MERLIN_SYNTH1_PWD_PRESC_MSB                                            27
#define MERLIN_SYNTH1_PWD_PRESC_MASK                                           0x8000000
#define MERLIN_SYNTH1_PWD_PRESC_GET(x)                                         (((x) & MERLIN_SYNTH1_PWD_PRESC_MASK) >> MERLIN_SYNTH1_PWD_PRESC_LSB)
#define MERLIN_SYNTH1_PWD_PRESC_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH1_PWD_PRESC_LSB) & MERLIN_SYNTH1_PWD_PRESC_MASK)
#define MERLIN_SYNTH1_PWD_PRESC_RESET                                          0x0
#define MERLIN_SYNTH1_PWD_LOBUF2G_LSB                                          26
#define MERLIN_SYNTH1_PWD_LOBUF2G_MSB                                          26
#define MERLIN_SYNTH1_PWD_LOBUF2G_MASK                                         0x4000000
#define MERLIN_SYNTH1_PWD_LOBUF2G_GET(x)                                       (((x) & MERLIN_SYNTH1_PWD_LOBUF2G_MASK) >> MERLIN_SYNTH1_PWD_LOBUF2G_LSB)
#define MERLIN_SYNTH1_PWD_LOBUF2G_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH1_PWD_LOBUF2G_LSB) & MERLIN_SYNTH1_PWD_LOBUF2G_MASK)
#define MERLIN_SYNTH1_PWD_LOBUF2G_RESET                                        0x0
#define MERLIN_SYNTH1_PWD_LOBUF5G_LSB                                          25
#define MERLIN_SYNTH1_PWD_LOBUF5G_MSB                                          25
#define MERLIN_SYNTH1_PWD_LOBUF5G_MASK                                         0x2000000
#define MERLIN_SYNTH1_PWD_LOBUF5G_GET(x)                                       (((x) & MERLIN_SYNTH1_PWD_LOBUF5G_MASK) >> MERLIN_SYNTH1_PWD_LOBUF5G_LSB)
#define MERLIN_SYNTH1_PWD_LOBUF5G_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH1_PWD_LOBUF5G_LSB) & MERLIN_SYNTH1_PWD_LOBUF5G_MASK)
#define MERLIN_SYNTH1_PWD_LOBUF5G_RESET                                        0x0
#define MERLIN_SYNTH1_PWD_LODIV_LSB                                            24
#define MERLIN_SYNTH1_PWD_LODIV_MSB                                            24
#define MERLIN_SYNTH1_PWD_LODIV_MASK                                           0x1000000
#define MERLIN_SYNTH1_PWD_LODIV_GET(x)                                         (((x) & MERLIN_SYNTH1_PWD_LODIV_MASK) >> MERLIN_SYNTH1_PWD_LODIV_LSB)
#define MERLIN_SYNTH1_PWD_LODIV_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH1_PWD_LODIV_LSB) & MERLIN_SYNTH1_PWD_LODIV_MASK)
#define MERLIN_SYNTH1_PWD_LODIV_RESET                                          0x0
#define MERLIN_SYNTH1_PWD_LOMIX_LSB                                            23
#define MERLIN_SYNTH1_PWD_LOMIX_MSB                                            23
#define MERLIN_SYNTH1_PWD_LOMIX_MASK                                           0x800000
#define MERLIN_SYNTH1_PWD_LOMIX_GET(x)                                         (((x) & MERLIN_SYNTH1_PWD_LOMIX_MASK) >> MERLIN_SYNTH1_PWD_LOMIX_LSB)
#define MERLIN_SYNTH1_PWD_LOMIX_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH1_PWD_LOMIX_LSB) & MERLIN_SYNTH1_PWD_LOMIX_MASK)
#define MERLIN_SYNTH1_PWD_LOMIX_RESET                                          0x0
#define MERLIN_SYNTH1_PWUP_LOREF_LSB                                           22
#define MERLIN_SYNTH1_PWUP_LOREF_MSB                                           22
#define MERLIN_SYNTH1_PWUP_LOREF_MASK                                          0x400000
#define MERLIN_SYNTH1_PWUP_LOREF_GET(x)                                        (((x) & MERLIN_SYNTH1_PWUP_LOREF_MASK) >> MERLIN_SYNTH1_PWUP_LOREF_LSB)
#define MERLIN_SYNTH1_PWUP_LOREF_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH1_PWUP_LOREF_LSB) & MERLIN_SYNTH1_PWUP_LOREF_MASK)
#define MERLIN_SYNTH1_PWUP_LOREF_RESET                                         0x0
#define MERLIN_SYNTH1_VCOREGBYPASS_LSB                                         21
#define MERLIN_SYNTH1_VCOREGBYPASS_MSB                                         21
#define MERLIN_SYNTH1_VCOREGBYPASS_MASK                                        0x200000
#define MERLIN_SYNTH1_VCOREGBYPASS_GET(x)                                      (((x) & MERLIN_SYNTH1_VCOREGBYPASS_MASK) >> MERLIN_SYNTH1_VCOREGBYPASS_LSB)
#define MERLIN_SYNTH1_VCOREGBYPASS_SET(x)                                      (((0 | (x)) << MERLIN_SYNTH1_VCOREGBYPASS_LSB) & MERLIN_SYNTH1_VCOREGBYPASS_MASK)
#define MERLIN_SYNTH1_VCOREGBYPASS_RESET                                       0x0
#define MERLIN_SYNTH1_VCOREGLEVEL_LSB                                          19
#define MERLIN_SYNTH1_VCOREGLEVEL_MSB                                          20
#define MERLIN_SYNTH1_VCOREGLEVEL_MASK                                         0x180000
#define MERLIN_SYNTH1_VCOREGLEVEL_GET(x)                                       (((x) & MERLIN_SYNTH1_VCOREGLEVEL_MASK) >> MERLIN_SYNTH1_VCOREGLEVEL_LSB)
#define MERLIN_SYNTH1_VCOREGLEVEL_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH1_VCOREGLEVEL_LSB) & MERLIN_SYNTH1_VCOREGLEVEL_MASK)
#define MERLIN_SYNTH1_VCOREGLEVEL_RESET                                        0x1
#define MERLIN_SYNTH1_VCOBUFBIAS_LSB                                           17
#define MERLIN_SYNTH1_VCOBUFBIAS_MSB                                           18
#define MERLIN_SYNTH1_VCOBUFBIAS_MASK                                          0x60000
#define MERLIN_SYNTH1_VCOBUFBIAS_GET(x)                                        (((x) & MERLIN_SYNTH1_VCOBUFBIAS_MASK) >> MERLIN_SYNTH1_VCOBUFBIAS_LSB)
#define MERLIN_SYNTH1_VCOBUFBIAS_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH1_VCOBUFBIAS_LSB) & MERLIN_SYNTH1_VCOBUFBIAS_MASK)
#define MERLIN_SYNTH1_VCOBUFBIAS_RESET                                         0x1
#define MERLIN_SYNTH1_PWUP_VCOBUF_PD_LSB                                       16
#define MERLIN_SYNTH1_PWUP_VCOBUF_PD_MSB                                       16
#define MERLIN_SYNTH1_PWUP_VCOBUF_PD_MASK                                      0x10000
#define MERLIN_SYNTH1_PWUP_VCOBUF_PD_GET(x)                                    (((x) & MERLIN_SYNTH1_PWUP_VCOBUF_PD_MASK) >> MERLIN_SYNTH1_PWUP_VCOBUF_PD_LSB)
#define MERLIN_SYNTH1_PWUP_VCOBUF_PD_SET(x)                                    (((0 | (x)) << MERLIN_SYNTH1_PWUP_VCOBUF_PD_LSB) & MERLIN_SYNTH1_PWUP_VCOBUF_PD_MASK)
#define MERLIN_SYNTH1_PWUP_VCOBUF_PD_RESET                                     0x0
#define MERLIN_SYNTH1_PWUP_LOBUF2G_PD_LSB                                      15
#define MERLIN_SYNTH1_PWUP_LOBUF2G_PD_MSB                                      15
#define MERLIN_SYNTH1_PWUP_LOBUF2G_PD_MASK                                     0x8000
#define MERLIN_SYNTH1_PWUP_LOBUF2G_PD_GET(x)                                   (((x) & MERLIN_SYNTH1_PWUP_LOBUF2G_PD_MASK) >> MERLIN_SYNTH1_PWUP_LOBUF2G_PD_LSB)
#define MERLIN_SYNTH1_PWUP_LOBUF2G_PD_SET(x)                                   (((0 | (x)) << MERLIN_SYNTH1_PWUP_LOBUF2G_PD_LSB) & MERLIN_SYNTH1_PWUP_LOBUF2G_PD_MASK)
#define MERLIN_SYNTH1_PWUP_LOBUF2G_PD_RESET                                    0x0
#define MERLIN_SYNTH1_PWUP_LOBUF5G_PD_LSB                                      14
#define MERLIN_SYNTH1_PWUP_LOBUF5G_PD_MSB                                      14
#define MERLIN_SYNTH1_PWUP_LOBUF5G_PD_MASK                                     0x4000
#define MERLIN_SYNTH1_PWUP_LOBUF5G_PD_GET(x)                                   (((x) & MERLIN_SYNTH1_PWUP_LOBUF5G_PD_MASK) >> MERLIN_SYNTH1_PWUP_LOBUF5G_PD_LSB)
#define MERLIN_SYNTH1_PWUP_LOBUF5G_PD_SET(x)                                   (((0 | (x)) << MERLIN_SYNTH1_PWUP_LOBUF5G_PD_LSB) & MERLIN_SYNTH1_PWUP_LOBUF5G_PD_MASK)
#define MERLIN_SYNTH1_PWUP_LOBUF5G_PD_RESET                                    0x0
#define MERLIN_SYNTH1_PWUP_LODIV_PD_LSB                                        13
#define MERLIN_SYNTH1_PWUP_LODIV_PD_MSB                                        13
#define MERLIN_SYNTH1_PWUP_LODIV_PD_MASK                                       0x2000
#define MERLIN_SYNTH1_PWUP_LODIV_PD_GET(x)                                     (((x) & MERLIN_SYNTH1_PWUP_LODIV_PD_MASK) >> MERLIN_SYNTH1_PWUP_LODIV_PD_LSB)
#define MERLIN_SYNTH1_PWUP_LODIV_PD_SET(x)                                     (((0 | (x)) << MERLIN_SYNTH1_PWUP_LODIV_PD_LSB) & MERLIN_SYNTH1_PWUP_LODIV_PD_MASK)
#define MERLIN_SYNTH1_PWUP_LODIV_PD_RESET                                      0x0
#define MERLIN_SYNTH1_PWUP_LOMIX_PD_LSB                                        12
#define MERLIN_SYNTH1_PWUP_LOMIX_PD_MSB                                        12
#define MERLIN_SYNTH1_PWUP_LOMIX_PD_MASK                                       0x1000
#define MERLIN_SYNTH1_PWUP_LOMIX_PD_GET(x)                                     (((x) & MERLIN_SYNTH1_PWUP_LOMIX_PD_MASK) >> MERLIN_SYNTH1_PWUP_LOMIX_PD_LSB)
#define MERLIN_SYNTH1_PWUP_LOMIX_PD_SET(x)                                     (((0 | (x)) << MERLIN_SYNTH1_PWUP_LOMIX_PD_LSB) & MERLIN_SYNTH1_PWUP_LOMIX_PD_MASK)
#define MERLIN_SYNTH1_PWUP_LOMIX_PD_RESET                                      0x0
#define MERLIN_SYNTH1_MONITOR_FB_LSB                                           11
#define MERLIN_SYNTH1_MONITOR_FB_MSB                                           11
#define MERLIN_SYNTH1_MONITOR_FB_MASK                                          0x800
#define MERLIN_SYNTH1_MONITOR_FB_GET(x)                                        (((x) & MERLIN_SYNTH1_MONITOR_FB_MASK) >> MERLIN_SYNTH1_MONITOR_FB_LSB)
#define MERLIN_SYNTH1_MONITOR_FB_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH1_MONITOR_FB_LSB) & MERLIN_SYNTH1_MONITOR_FB_MASK)
#define MERLIN_SYNTH1_MONITOR_FB_RESET                                         0x0
#define MERLIN_SYNTH1_MONITOR_REF_LSB                                          10
#define MERLIN_SYNTH1_MONITOR_REF_MSB                                          10
#define MERLIN_SYNTH1_MONITOR_REF_MASK                                         0x400
#define MERLIN_SYNTH1_MONITOR_REF_GET(x)                                       (((x) & MERLIN_SYNTH1_MONITOR_REF_MASK) >> MERLIN_SYNTH1_MONITOR_REF_LSB)
#define MERLIN_SYNTH1_MONITOR_REF_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH1_MONITOR_REF_LSB) & MERLIN_SYNTH1_MONITOR_REF_MASK)
#define MERLIN_SYNTH1_MONITOR_REF_RESET                                        0x0
#define MERLIN_SYNTH1_MONITOR_FB_DIV2_LSB                                      9
#define MERLIN_SYNTH1_MONITOR_FB_DIV2_MSB                                      9
#define MERLIN_SYNTH1_MONITOR_FB_DIV2_MASK                                     0x200
#define MERLIN_SYNTH1_MONITOR_FB_DIV2_GET(x)                                   (((x) & MERLIN_SYNTH1_MONITOR_FB_DIV2_MASK) >> MERLIN_SYNTH1_MONITOR_FB_DIV2_LSB)
#define MERLIN_SYNTH1_MONITOR_FB_DIV2_SET(x)                                   (((0 | (x)) << MERLIN_SYNTH1_MONITOR_FB_DIV2_LSB) & MERLIN_SYNTH1_MONITOR_FB_DIV2_MASK)
#define MERLIN_SYNTH1_MONITOR_FB_DIV2_RESET                                    0x0
#define MERLIN_SYNTH1_MONITOR_VC2HIGH_LSB                                      8
#define MERLIN_SYNTH1_MONITOR_VC2HIGH_MSB                                      8
#define MERLIN_SYNTH1_MONITOR_VC2HIGH_MASK                                     0x100
#define MERLIN_SYNTH1_MONITOR_VC2HIGH_GET(x)                                   (((x) & MERLIN_SYNTH1_MONITOR_VC2HIGH_MASK) >> MERLIN_SYNTH1_MONITOR_VC2HIGH_LSB)
#define MERLIN_SYNTH1_MONITOR_VC2HIGH_SET(x)                                   (((0 | (x)) << MERLIN_SYNTH1_MONITOR_VC2HIGH_LSB) & MERLIN_SYNTH1_MONITOR_VC2HIGH_MASK)
#define MERLIN_SYNTH1_MONITOR_VC2HIGH_RESET                                    0x0
#define MERLIN_SYNTH1_MONITOR_VC2LOW_LSB                                       7
#define MERLIN_SYNTH1_MONITOR_VC2LOW_MSB                                       7
#define MERLIN_SYNTH1_MONITOR_VC2LOW_MASK                                      0x80
#define MERLIN_SYNTH1_MONITOR_VC2LOW_GET(x)                                    (((x) & MERLIN_SYNTH1_MONITOR_VC2LOW_MASK) >> MERLIN_SYNTH1_MONITOR_VC2LOW_LSB)
#define MERLIN_SYNTH1_MONITOR_VC2LOW_SET(x)                                    (((0 | (x)) << MERLIN_SYNTH1_MONITOR_VC2LOW_LSB) & MERLIN_SYNTH1_MONITOR_VC2LOW_MASK)
#define MERLIN_SYNTH1_MONITOR_VC2LOW_RESET                                     0x0
#define MERLIN_SYNTH1_MONITOR_SYNTHLOCKVCOK_LSB                                6
#define MERLIN_SYNTH1_MONITOR_SYNTHLOCKVCOK_MSB                                6
#define MERLIN_SYNTH1_MONITOR_SYNTHLOCKVCOK_MASK                               0x40
#define MERLIN_SYNTH1_MONITOR_SYNTHLOCKVCOK_GET(x)                             (((x) & MERLIN_SYNTH1_MONITOR_SYNTHLOCKVCOK_MASK) >> MERLIN_SYNTH1_MONITOR_SYNTHLOCKVCOK_LSB)
#define MERLIN_SYNTH1_MONITOR_SYNTHLOCKVCOK_SET(x)                             (((0 | (x)) << MERLIN_SYNTH1_MONITOR_SYNTHLOCKVCOK_LSB) & MERLIN_SYNTH1_MONITOR_SYNTHLOCKVCOK_MASK)
#define MERLIN_SYNTH1_MONITOR_SYNTHLOCKVCOK_RESET                              0x0
#define MERLIN_SYNTH1_CON_VDDVCOREG_LSB                                        5
#define MERLIN_SYNTH1_CON_VDDVCOREG_MSB                                        5
#define MERLIN_SYNTH1_CON_VDDVCOREG_MASK                                       0x20
#define MERLIN_SYNTH1_CON_VDDVCOREG_GET(x)                                     (((x) & MERLIN_SYNTH1_CON_VDDVCOREG_MASK) >> MERLIN_SYNTH1_CON_VDDVCOREG_LSB)
#define MERLIN_SYNTH1_CON_VDDVCOREG_SET(x)                                     (((0 | (x)) << MERLIN_SYNTH1_CON_VDDVCOREG_LSB) & MERLIN_SYNTH1_CON_VDDVCOREG_MASK)
#define MERLIN_SYNTH1_CON_VDDVCOREG_RESET                                      0x0
#define MERLIN_SYNTH1_CON_IVCOREG_LSB                                          4
#define MERLIN_SYNTH1_CON_IVCOREG_MSB                                          4
#define MERLIN_SYNTH1_CON_IVCOREG_MASK                                         0x10
#define MERLIN_SYNTH1_CON_IVCOREG_GET(x)                                       (((x) & MERLIN_SYNTH1_CON_IVCOREG_MASK) >> MERLIN_SYNTH1_CON_IVCOREG_LSB)
#define MERLIN_SYNTH1_CON_IVCOREG_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH1_CON_IVCOREG_LSB) & MERLIN_SYNTH1_CON_IVCOREG_MASK)
#define MERLIN_SYNTH1_CON_IVCOREG_RESET                                        0x0
#define MERLIN_SYNTH1_CON_IVCOBUF_LSB                                          3
#define MERLIN_SYNTH1_CON_IVCOBUF_MSB                                          3
#define MERLIN_SYNTH1_CON_IVCOBUF_MASK                                         0x8
#define MERLIN_SYNTH1_CON_IVCOBUF_GET(x)                                       (((x) & MERLIN_SYNTH1_CON_IVCOBUF_MASK) >> MERLIN_SYNTH1_CON_IVCOBUF_LSB)
#define MERLIN_SYNTH1_CON_IVCOBUF_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH1_CON_IVCOBUF_LSB) & MERLIN_SYNTH1_CON_IVCOBUF_MASK)
#define MERLIN_SYNTH1_CON_IVCOBUF_RESET                                        0x0
#define MERLIN_SYNTH1_SEL_VCMONABUS_LSB                                        0
#define MERLIN_SYNTH1_SEL_VCMONABUS_MSB                                        2
#define MERLIN_SYNTH1_SEL_VCMONABUS_MASK                                       0x7
#define MERLIN_SYNTH1_SEL_VCMONABUS_GET(x)                                     (((x) & MERLIN_SYNTH1_SEL_VCMONABUS_MASK) >> MERLIN_SYNTH1_SEL_VCMONABUS_LSB)
#define MERLIN_SYNTH1_SEL_VCMONABUS_SET(x)                                     (((0 | (x)) << MERLIN_SYNTH1_SEL_VCMONABUS_LSB) & MERLIN_SYNTH1_SEL_VCMONABUS_MASK)
#define MERLIN_SYNTH1_SEL_VCMONABUS_RESET                                      0x0
#define MERLIN_SYNTH1_ADDRESS                                                  (0x48 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH1_RSTMASK                                                  0xffffffff
#define MERLIN_SYNTH1_RESET                                                    0xa0000

// 0x4c (MERLIN_SYNTH2)
#define MERLIN_SYNTH2_VC_CAL_REF_LSB                                           29
#define MERLIN_SYNTH2_VC_CAL_REF_MSB                                           31
#define MERLIN_SYNTH2_VC_CAL_REF_MASK                                          0xe0000000
#define MERLIN_SYNTH2_VC_CAL_REF_GET(x)                                        (((x) & MERLIN_SYNTH2_VC_CAL_REF_MASK) >> MERLIN_SYNTH2_VC_CAL_REF_LSB)
#define MERLIN_SYNTH2_VC_CAL_REF_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH2_VC_CAL_REF_LSB) & MERLIN_SYNTH2_VC_CAL_REF_MASK)
#define MERLIN_SYNTH2_VC_CAL_REF_RESET                                         0x0
#define MERLIN_SYNTH2_VC_HI_REF_LSB                                            26
#define MERLIN_SYNTH2_VC_HI_REF_MSB                                            28
#define MERLIN_SYNTH2_VC_HI_REF_MASK                                           0x1c000000
#define MERLIN_SYNTH2_VC_HI_REF_GET(x)                                         (((x) & MERLIN_SYNTH2_VC_HI_REF_MASK) >> MERLIN_SYNTH2_VC_HI_REF_LSB)
#define MERLIN_SYNTH2_VC_HI_REF_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH2_VC_HI_REF_LSB) & MERLIN_SYNTH2_VC_HI_REF_MASK)
#define MERLIN_SYNTH2_VC_HI_REF_RESET                                          0x3
#define MERLIN_SYNTH2_VC_MID_REF_LSB                                           23
#define MERLIN_SYNTH2_VC_MID_REF_MSB                                           25
#define MERLIN_SYNTH2_VC_MID_REF_MASK                                          0x3800000
#define MERLIN_SYNTH2_VC_MID_REF_GET(x)                                        (((x) & MERLIN_SYNTH2_VC_MID_REF_MASK) >> MERLIN_SYNTH2_VC_MID_REF_LSB)
#define MERLIN_SYNTH2_VC_MID_REF_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH2_VC_MID_REF_LSB) & MERLIN_SYNTH2_VC_MID_REF_MASK)
#define MERLIN_SYNTH2_VC_MID_REF_RESET                                         0x4
#define MERLIN_SYNTH2_VC_LOW_REF_LSB                                           20
#define MERLIN_SYNTH2_VC_LOW_REF_MSB                                           22
#define MERLIN_SYNTH2_VC_LOW_REF_MASK                                          0x700000
#define MERLIN_SYNTH2_VC_LOW_REF_GET(x)                                        (((x) & MERLIN_SYNTH2_VC_LOW_REF_MASK) >> MERLIN_SYNTH2_VC_LOW_REF_LSB)
#define MERLIN_SYNTH2_VC_LOW_REF_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH2_VC_LOW_REF_LSB) & MERLIN_SYNTH2_VC_LOW_REF_MASK)
#define MERLIN_SYNTH2_VC_LOW_REF_RESET                                         0x4
#define MERLIN_SYNTH2_CPBIAS_LSB                                               18
#define MERLIN_SYNTH2_CPBIAS_MSB                                               19
#define MERLIN_SYNTH2_CPBIAS_MASK                                              0xc0000
#define MERLIN_SYNTH2_CPBIAS_GET(x)                                            (((x) & MERLIN_SYNTH2_CPBIAS_MASK) >> MERLIN_SYNTH2_CPBIAS_LSB)
#define MERLIN_SYNTH2_CPBIAS_SET(x)                                            (((0 | (x)) << MERLIN_SYNTH2_CPBIAS_LSB) & MERLIN_SYNTH2_CPBIAS_MASK)
#define MERLIN_SYNTH2_CPBIAS_RESET                                             0x3
#define MERLIN_SYNTH2_CPSTEERING_EN_INTN_LSB                                   17
#define MERLIN_SYNTH2_CPSTEERING_EN_INTN_MSB                                   17
#define MERLIN_SYNTH2_CPSTEERING_EN_INTN_MASK                                  0x20000
#define MERLIN_SYNTH2_CPSTEERING_EN_INTN_GET(x)                                (((x) & MERLIN_SYNTH2_CPSTEERING_EN_INTN_MASK) >> MERLIN_SYNTH2_CPSTEERING_EN_INTN_LSB)
#define MERLIN_SYNTH2_CPSTEERING_EN_INTN_SET(x)                                (((0 | (x)) << MERLIN_SYNTH2_CPSTEERING_EN_INTN_LSB) & MERLIN_SYNTH2_CPSTEERING_EN_INTN_MASK)
#define MERLIN_SYNTH2_CPSTEERING_EN_INTN_RESET                                 0x1
#define MERLIN_SYNTH2_CPLOWLK_LSB                                              16
#define MERLIN_SYNTH2_CPLOWLK_MSB                                              16
#define MERLIN_SYNTH2_CPLOWLK_MASK                                             0x10000
#define MERLIN_SYNTH2_CPLOWLK_GET(x)                                           (((x) & MERLIN_SYNTH2_CPLOWLK_MASK) >> MERLIN_SYNTH2_CPLOWLK_LSB)
#define MERLIN_SYNTH2_CPLOWLK_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH2_CPLOWLK_LSB) & MERLIN_SYNTH2_CPLOWLK_MASK)
#define MERLIN_SYNTH2_CPLOWLK_RESET                                            0x0
#define MERLIN_SYNTH2_LOOPLEAKCUR_LSB                                          12
#define MERLIN_SYNTH2_LOOPLEAKCUR_MSB                                          15
#define MERLIN_SYNTH2_LOOPLEAKCUR_MASK                                         0xf000
#define MERLIN_SYNTH2_LOOPLEAKCUR_GET(x)                                       (((x) & MERLIN_SYNTH2_LOOPLEAKCUR_MASK) >> MERLIN_SYNTH2_LOOPLEAKCUR_LSB)
#define MERLIN_SYNTH2_LOOPLEAKCUR_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH2_LOOPLEAKCUR_LSB) & MERLIN_SYNTH2_LOOPLEAKCUR_MASK)
#define MERLIN_SYNTH2_LOOPLEAKCUR_RESET                                        0x0
#define MERLIN_SYNTH2_CAPRANGE1_LSB                                            8
#define MERLIN_SYNTH2_CAPRANGE1_MSB                                            11
#define MERLIN_SYNTH2_CAPRANGE1_MASK                                           0xf00
#define MERLIN_SYNTH2_CAPRANGE1_GET(x)                                         (((x) & MERLIN_SYNTH2_CAPRANGE1_MASK) >> MERLIN_SYNTH2_CAPRANGE1_LSB)
#define MERLIN_SYNTH2_CAPRANGE1_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH2_CAPRANGE1_LSB) & MERLIN_SYNTH2_CAPRANGE1_MASK)
#define MERLIN_SYNTH2_CAPRANGE1_RESET                                          0x4
#define MERLIN_SYNTH2_CAPRANGE2_LSB                                            4
#define MERLIN_SYNTH2_CAPRANGE2_MSB                                            7
#define MERLIN_SYNTH2_CAPRANGE2_MASK                                           0xf0
#define MERLIN_SYNTH2_CAPRANGE2_GET(x)                                         (((x) & MERLIN_SYNTH2_CAPRANGE2_MASK) >> MERLIN_SYNTH2_CAPRANGE2_LSB)
#define MERLIN_SYNTH2_CAPRANGE2_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH2_CAPRANGE2_LSB) & MERLIN_SYNTH2_CAPRANGE2_MASK)
#define MERLIN_SYNTH2_CAPRANGE2_RESET                                          0x8
#define MERLIN_SYNTH2_CAPRANGE3_LSB                                            0
#define MERLIN_SYNTH2_CAPRANGE3_MSB                                            3
#define MERLIN_SYNTH2_CAPRANGE3_MASK                                           0xf
#define MERLIN_SYNTH2_CAPRANGE3_GET(x)                                         (((x) & MERLIN_SYNTH2_CAPRANGE3_MASK) >> MERLIN_SYNTH2_CAPRANGE3_LSB)
#define MERLIN_SYNTH2_CAPRANGE3_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH2_CAPRANGE3_LSB) & MERLIN_SYNTH2_CAPRANGE3_MASK)
#define MERLIN_SYNTH2_CAPRANGE3_RESET                                          0xc
#define MERLIN_SYNTH2_ADDRESS                                                  (0x4c + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH2_RSTMASK                                                  0xffffffff
#define MERLIN_SYNTH2_RESET                                                    0xe4e048c

// 0x50 (MERLIN_SYNTH3)
#define MERLIN_SYNTH3_DIS_CLK_XTAL_LSB                                         31
#define MERLIN_SYNTH3_DIS_CLK_XTAL_MSB                                         31
#define MERLIN_SYNTH3_DIS_CLK_XTAL_MASK                                        0x80000000
#define MERLIN_SYNTH3_DIS_CLK_XTAL_GET(x)                                      (((x) & MERLIN_SYNTH3_DIS_CLK_XTAL_MASK) >> MERLIN_SYNTH3_DIS_CLK_XTAL_LSB)
#define MERLIN_SYNTH3_DIS_CLK_XTAL_SET(x)                                      (((0 | (x)) << MERLIN_SYNTH3_DIS_CLK_XTAL_LSB) & MERLIN_SYNTH3_DIS_CLK_XTAL_MASK)
#define MERLIN_SYNTH3_DIS_CLK_XTAL_RESET                                       0x0
#define MERLIN_SYNTH3_SEL_CLK_DIV2_LSB                                         30
#define MERLIN_SYNTH3_SEL_CLK_DIV2_MSB                                         30
#define MERLIN_SYNTH3_SEL_CLK_DIV2_MASK                                        0x40000000
#define MERLIN_SYNTH3_SEL_CLK_DIV2_GET(x)                                      (((x) & MERLIN_SYNTH3_SEL_CLK_DIV2_MASK) >> MERLIN_SYNTH3_SEL_CLK_DIV2_LSB)
#define MERLIN_SYNTH3_SEL_CLK_DIV2_SET(x)                                      (((0 | (x)) << MERLIN_SYNTH3_SEL_CLK_DIV2_LSB) & MERLIN_SYNTH3_SEL_CLK_DIV2_MASK)
#define MERLIN_SYNTH3_SEL_CLK_DIV2_RESET                                       0x1
#define MERLIN_SYNTH3_WAIT_SHORTR_PWRUP_LSB                                    24
#define MERLIN_SYNTH3_WAIT_SHORTR_PWRUP_MSB                                    29
#define MERLIN_SYNTH3_WAIT_SHORTR_PWRUP_MASK                                   0x3f000000
#define MERLIN_SYNTH3_WAIT_SHORTR_PWRUP_GET(x)                                 (((x) & MERLIN_SYNTH3_WAIT_SHORTR_PWRUP_MASK) >> MERLIN_SYNTH3_WAIT_SHORTR_PWRUP_LSB)
#define MERLIN_SYNTH3_WAIT_SHORTR_PWRUP_SET(x)                                 (((0 | (x)) << MERLIN_SYNTH3_WAIT_SHORTR_PWRUP_LSB) & MERLIN_SYNTH3_WAIT_SHORTR_PWRUP_MASK)
#define MERLIN_SYNTH3_WAIT_SHORTR_PWRUP_RESET                                  0x14
#define MERLIN_SYNTH3_WAIT_PWRUP_LSB                                           18
#define MERLIN_SYNTH3_WAIT_PWRUP_MSB                                           23
#define MERLIN_SYNTH3_WAIT_PWRUP_MASK                                          0xfc0000
#define MERLIN_SYNTH3_WAIT_PWRUP_GET(x)                                        (((x) & MERLIN_SYNTH3_WAIT_PWRUP_MASK) >> MERLIN_SYNTH3_WAIT_PWRUP_LSB)
#define MERLIN_SYNTH3_WAIT_PWRUP_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH3_WAIT_PWRUP_LSB) & MERLIN_SYNTH3_WAIT_PWRUP_MASK)
#define MERLIN_SYNTH3_WAIT_PWRUP_RESET                                         0x8
#define MERLIN_SYNTH3_WAIT_CAL_BIN_LSB                                         12
#define MERLIN_SYNTH3_WAIT_CAL_BIN_MSB                                         17
#define MERLIN_SYNTH3_WAIT_CAL_BIN_MASK                                        0x3f000
#define MERLIN_SYNTH3_WAIT_CAL_BIN_GET(x)                                      (((x) & MERLIN_SYNTH3_WAIT_CAL_BIN_MASK) >> MERLIN_SYNTH3_WAIT_CAL_BIN_LSB)
#define MERLIN_SYNTH3_WAIT_CAL_BIN_SET(x)                                      (((0 | (x)) << MERLIN_SYNTH3_WAIT_CAL_BIN_LSB) & MERLIN_SYNTH3_WAIT_CAL_BIN_MASK)
#define MERLIN_SYNTH3_WAIT_CAL_BIN_RESET                                       0x14
#define MERLIN_SYNTH3_WAIT_CAL_LIN_LSB                                         6
#define MERLIN_SYNTH3_WAIT_CAL_LIN_MSB                                         11
#define MERLIN_SYNTH3_WAIT_CAL_LIN_MASK                                        0xfc0
#define MERLIN_SYNTH3_WAIT_CAL_LIN_GET(x)                                      (((x) & MERLIN_SYNTH3_WAIT_CAL_LIN_MASK) >> MERLIN_SYNTH3_WAIT_CAL_LIN_LSB)
#define MERLIN_SYNTH3_WAIT_CAL_LIN_SET(x)                                      (((0 | (x)) << MERLIN_SYNTH3_WAIT_CAL_LIN_LSB) & MERLIN_SYNTH3_WAIT_CAL_LIN_MASK)
#define MERLIN_SYNTH3_WAIT_CAL_LIN_RESET                                       0x14
#define MERLIN_SYNTH3_WAIT_VC_CHECK_LSB                                        0
#define MERLIN_SYNTH3_WAIT_VC_CHECK_MSB                                        5
#define MERLIN_SYNTH3_WAIT_VC_CHECK_MASK                                       0x3f
#define MERLIN_SYNTH3_WAIT_VC_CHECK_GET(x)                                     (((x) & MERLIN_SYNTH3_WAIT_VC_CHECK_MASK) >> MERLIN_SYNTH3_WAIT_VC_CHECK_LSB)
#define MERLIN_SYNTH3_WAIT_VC_CHECK_SET(x)                                     (((0 | (x)) << MERLIN_SYNTH3_WAIT_VC_CHECK_LSB) & MERLIN_SYNTH3_WAIT_VC_CHECK_MASK)
#define MERLIN_SYNTH3_WAIT_VC_CHECK_RESET                                      0x14
#define MERLIN_SYNTH3_ADDRESS                                                  (0x50 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH3_RSTMASK                                                  0xffffffff
#define MERLIN_SYNTH3_RESET                                                    0x54214514

// 0x54 (MERLIN_SYNTH4)
#define MERLIN_SYNTH4_DIS_LIN_CAPSEARCH_LSB                                    31
#define MERLIN_SYNTH4_DIS_LIN_CAPSEARCH_MSB                                    31
#define MERLIN_SYNTH4_DIS_LIN_CAPSEARCH_MASK                                   0x80000000
#define MERLIN_SYNTH4_DIS_LIN_CAPSEARCH_GET(x)                                 (((x) & MERLIN_SYNTH4_DIS_LIN_CAPSEARCH_MASK) >> MERLIN_SYNTH4_DIS_LIN_CAPSEARCH_LSB)
#define MERLIN_SYNTH4_DIS_LIN_CAPSEARCH_SET(x)                                 (((0 | (x)) << MERLIN_SYNTH4_DIS_LIN_CAPSEARCH_LSB) & MERLIN_SYNTH4_DIS_LIN_CAPSEARCH_MASK)
#define MERLIN_SYNTH4_DIS_LIN_CAPSEARCH_RESET                                  0x0
#define MERLIN_SYNTH4_DIS_LOSTVC_LSB                                           30
#define MERLIN_SYNTH4_DIS_LOSTVC_MSB                                           30
#define MERLIN_SYNTH4_DIS_LOSTVC_MASK                                          0x40000000
#define MERLIN_SYNTH4_DIS_LOSTVC_GET(x)                                        (((x) & MERLIN_SYNTH4_DIS_LOSTVC_MASK) >> MERLIN_SYNTH4_DIS_LOSTVC_LSB)
#define MERLIN_SYNTH4_DIS_LOSTVC_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH4_DIS_LOSTVC_LSB) & MERLIN_SYNTH4_DIS_LOSTVC_MASK)
#define MERLIN_SYNTH4_DIS_LOSTVC_RESET                                         0x0
#define MERLIN_SYNTH4_ALWAYS_SHORTR_LSB                                        29
#define MERLIN_SYNTH4_ALWAYS_SHORTR_MSB                                        29
#define MERLIN_SYNTH4_ALWAYS_SHORTR_MASK                                       0x20000000
#define MERLIN_SYNTH4_ALWAYS_SHORTR_GET(x)                                     (((x) & MERLIN_SYNTH4_ALWAYS_SHORTR_MASK) >> MERLIN_SYNTH4_ALWAYS_SHORTR_LSB)
#define MERLIN_SYNTH4_ALWAYS_SHORTR_SET(x)                                     (((0 | (x)) << MERLIN_SYNTH4_ALWAYS_SHORTR_LSB) & MERLIN_SYNTH4_ALWAYS_SHORTR_MASK)
#define MERLIN_SYNTH4_ALWAYS_SHORTR_RESET                                      0x0
#define MERLIN_SYNTH4_SHORTR_UNTIL_LOCKED_LSB                                  28
#define MERLIN_SYNTH4_SHORTR_UNTIL_LOCKED_MSB                                  28
#define MERLIN_SYNTH4_SHORTR_UNTIL_LOCKED_MASK                                 0x10000000
#define MERLIN_SYNTH4_SHORTR_UNTIL_LOCKED_GET(x)                               (((x) & MERLIN_SYNTH4_SHORTR_UNTIL_LOCKED_MASK) >> MERLIN_SYNTH4_SHORTR_UNTIL_LOCKED_LSB)
#define MERLIN_SYNTH4_SHORTR_UNTIL_LOCKED_SET(x)                               (((0 | (x)) << MERLIN_SYNTH4_SHORTR_UNTIL_LOCKED_LSB) & MERLIN_SYNTH4_SHORTR_UNTIL_LOCKED_MASK)
#define MERLIN_SYNTH4_SHORTR_UNTIL_LOCKED_RESET                                0x1
#define MERLIN_SYNTH4_FORCE_PINVC_LSB                                          27
#define MERLIN_SYNTH4_FORCE_PINVC_MSB                                          27
#define MERLIN_SYNTH4_FORCE_PINVC_MASK                                         0x8000000
#define MERLIN_SYNTH4_FORCE_PINVC_GET(x)                                       (((x) & MERLIN_SYNTH4_FORCE_PINVC_MASK) >> MERLIN_SYNTH4_FORCE_PINVC_LSB)
#define MERLIN_SYNTH4_FORCE_PINVC_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH4_FORCE_PINVC_LSB) & MERLIN_SYNTH4_FORCE_PINVC_MASK)
#define MERLIN_SYNTH4_FORCE_PINVC_RESET                                        0x0
#define MERLIN_SYNTH4_FORCE_VCOCAP_LSB                                         26
#define MERLIN_SYNTH4_FORCE_VCOCAP_MSB                                         26
#define MERLIN_SYNTH4_FORCE_VCOCAP_MASK                                        0x4000000
#define MERLIN_SYNTH4_FORCE_VCOCAP_GET(x)                                      (((x) & MERLIN_SYNTH4_FORCE_VCOCAP_MASK) >> MERLIN_SYNTH4_FORCE_VCOCAP_LSB)
#define MERLIN_SYNTH4_FORCE_VCOCAP_SET(x)                                      (((0 | (x)) << MERLIN_SYNTH4_FORCE_VCOCAP_LSB) & MERLIN_SYNTH4_FORCE_VCOCAP_MASK)
#define MERLIN_SYNTH4_FORCE_VCOCAP_RESET                                       0x0
#define MERLIN_SYNTH4_VCOCAP_OVR_LSB                                           18
#define MERLIN_SYNTH4_VCOCAP_OVR_MSB                                           25
#define MERLIN_SYNTH4_VCOCAP_OVR_MASK                                          0x3fc0000
#define MERLIN_SYNTH4_VCOCAP_OVR_GET(x)                                        (((x) & MERLIN_SYNTH4_VCOCAP_OVR_MASK) >> MERLIN_SYNTH4_VCOCAP_OVR_LSB)
#define MERLIN_SYNTH4_VCOCAP_OVR_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH4_VCOCAP_OVR_LSB) & MERLIN_SYNTH4_VCOCAP_OVR_MASK)
#define MERLIN_SYNTH4_VCOCAP_OVR_RESET                                         0x80
#define MERLIN_SYNTH4_VCOCAPPULLUP_LSB                                         17
#define MERLIN_SYNTH4_VCOCAPPULLUP_MSB                                         17
#define MERLIN_SYNTH4_VCOCAPPULLUP_MASK                                        0x20000
#define MERLIN_SYNTH4_VCOCAPPULLUP_GET(x)                                      (((x) & MERLIN_SYNTH4_VCOCAPPULLUP_MASK) >> MERLIN_SYNTH4_VCOCAPPULLUP_LSB)
#define MERLIN_SYNTH4_VCOCAPPULLUP_SET(x)                                      (((0 | (x)) << MERLIN_SYNTH4_VCOCAPPULLUP_LSB) & MERLIN_SYNTH4_VCOCAPPULLUP_MASK)
#define MERLIN_SYNTH4_VCOCAPPULLUP_RESET                                       0x1
#define MERLIN_SYNTH4_CLKXTAL_EDGE_SEL_LSB                                     16
#define MERLIN_SYNTH4_CLKXTAL_EDGE_SEL_MSB                                     16
#define MERLIN_SYNTH4_CLKXTAL_EDGE_SEL_MASK                                    0x10000
#define MERLIN_SYNTH4_CLKXTAL_EDGE_SEL_GET(x)                                  (((x) & MERLIN_SYNTH4_CLKXTAL_EDGE_SEL_MASK) >> MERLIN_SYNTH4_CLKXTAL_EDGE_SEL_LSB)
#define MERLIN_SYNTH4_CLKXTAL_EDGE_SEL_SET(x)                                  (((0 | (x)) << MERLIN_SYNTH4_CLKXTAL_EDGE_SEL_LSB) & MERLIN_SYNTH4_CLKXTAL_EDGE_SEL_MASK)
#define MERLIN_SYNTH4_CLKXTAL_EDGE_SEL_RESET                                   0x0
#define MERLIN_SYNTH4_FORCE_LO_ON_LSB                                          15
#define MERLIN_SYNTH4_FORCE_LO_ON_MSB                                          15
#define MERLIN_SYNTH4_FORCE_LO_ON_MASK                                         0x8000
#define MERLIN_SYNTH4_FORCE_LO_ON_GET(x)                                       (((x) & MERLIN_SYNTH4_FORCE_LO_ON_MASK) >> MERLIN_SYNTH4_FORCE_LO_ON_LSB)
#define MERLIN_SYNTH4_FORCE_LO_ON_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH4_FORCE_LO_ON_LSB) & MERLIN_SYNTH4_FORCE_LO_ON_MASK)
#define MERLIN_SYNTH4_FORCE_LO_ON_RESET                                        0x0
#define MERLIN_SYNTH4_PFDDELAY_FRACN_LSB                                       14
#define MERLIN_SYNTH4_PFDDELAY_FRACN_MSB                                       14
#define MERLIN_SYNTH4_PFDDELAY_FRACN_MASK                                      0x4000
#define MERLIN_SYNTH4_PFDDELAY_FRACN_GET(x)                                    (((x) & MERLIN_SYNTH4_PFDDELAY_FRACN_MASK) >> MERLIN_SYNTH4_PFDDELAY_FRACN_LSB)
#define MERLIN_SYNTH4_PFDDELAY_FRACN_SET(x)                                    (((0 | (x)) << MERLIN_SYNTH4_PFDDELAY_FRACN_LSB) & MERLIN_SYNTH4_PFDDELAY_FRACN_MASK)
#define MERLIN_SYNTH4_PFDDELAY_FRACN_RESET                                     0x1
#define MERLIN_SYNTH4_PFD_DISABLE_LSB                                          13
#define MERLIN_SYNTH4_PFD_DISABLE_MSB                                          13
#define MERLIN_SYNTH4_PFD_DISABLE_MASK                                         0x2000
#define MERLIN_SYNTH4_PFD_DISABLE_GET(x)                                       (((x) & MERLIN_SYNTH4_PFD_DISABLE_MASK) >> MERLIN_SYNTH4_PFD_DISABLE_LSB)
#define MERLIN_SYNTH4_PFD_DISABLE_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH4_PFD_DISABLE_LSB) & MERLIN_SYNTH4_PFD_DISABLE_MASK)
#define MERLIN_SYNTH4_PFD_DISABLE_RESET                                        0x0
#define MERLIN_SYNTH4_PRESCSEL_LSB                                             11
#define MERLIN_SYNTH4_PRESCSEL_MSB                                             12
#define MERLIN_SYNTH4_PRESCSEL_MASK                                            0x1800
#define MERLIN_SYNTH4_PRESCSEL_GET(x)                                          (((x) & MERLIN_SYNTH4_PRESCSEL_MASK) >> MERLIN_SYNTH4_PRESCSEL_LSB)
#define MERLIN_SYNTH4_PRESCSEL_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH4_PRESCSEL_LSB) & MERLIN_SYNTH4_PRESCSEL_MASK)
#define MERLIN_SYNTH4_PRESCSEL_RESET                                           0x3
#define MERLIN_SYNTH4_RESET_PRESC_LSB                                          10
#define MERLIN_SYNTH4_RESET_PRESC_MSB                                          10
#define MERLIN_SYNTH4_RESET_PRESC_MASK                                         0x400
#define MERLIN_SYNTH4_RESET_PRESC_GET(x)                                       (((x) & MERLIN_SYNTH4_RESET_PRESC_MASK) >> MERLIN_SYNTH4_RESET_PRESC_LSB)
#define MERLIN_SYNTH4_RESET_PRESC_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH4_RESET_PRESC_LSB) & MERLIN_SYNTH4_RESET_PRESC_MASK)
#define MERLIN_SYNTH4_RESET_PRESC_RESET                                        0x0
#define MERLIN_SYNTH4_SDM_DISABLE_LSB                                          9
#define MERLIN_SYNTH4_SDM_DISABLE_MSB                                          9
#define MERLIN_SYNTH4_SDM_DISABLE_MASK                                         0x200
#define MERLIN_SYNTH4_SDM_DISABLE_GET(x)                                       (((x) & MERLIN_SYNTH4_SDM_DISABLE_MASK) >> MERLIN_SYNTH4_SDM_DISABLE_LSB)
#define MERLIN_SYNTH4_SDM_DISABLE_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH4_SDM_DISABLE_LSB) & MERLIN_SYNTH4_SDM_DISABLE_MASK)
#define MERLIN_SYNTH4_SDM_DISABLE_RESET                                        0x0
#define MERLIN_SYNTH4_SDM_MODE_LSB                                             8
#define MERLIN_SYNTH4_SDM_MODE_MSB                                             8
#define MERLIN_SYNTH4_SDM_MODE_MASK                                            0x100
#define MERLIN_SYNTH4_SDM_MODE_GET(x)                                          (((x) & MERLIN_SYNTH4_SDM_MODE_MASK) >> MERLIN_SYNTH4_SDM_MODE_LSB)
#define MERLIN_SYNTH4_SDM_MODE_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH4_SDM_MODE_LSB) & MERLIN_SYNTH4_SDM_MODE_MASK)
#define MERLIN_SYNTH4_SDM_MODE_RESET                                           0x0
#define MERLIN_SYNTH4_SDM_DITHER_LSB                                           6
#define MERLIN_SYNTH4_SDM_DITHER_MSB                                           7
#define MERLIN_SYNTH4_SDM_DITHER_MASK                                          0xc0
#define MERLIN_SYNTH4_SDM_DITHER_GET(x)                                        (((x) & MERLIN_SYNTH4_SDM_DITHER_MASK) >> MERLIN_SYNTH4_SDM_DITHER_LSB)
#define MERLIN_SYNTH4_SDM_DITHER_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH4_SDM_DITHER_LSB) & MERLIN_SYNTH4_SDM_DITHER_MASK)
#define MERLIN_SYNTH4_SDM_DITHER_RESET                                         0x0
#define MERLIN_SYNTH4_PSCOUNT_FBSEL_LSB                                        5
#define MERLIN_SYNTH4_PSCOUNT_FBSEL_MSB                                        5
#define MERLIN_SYNTH4_PSCOUNT_FBSEL_MASK                                       0x20
#define MERLIN_SYNTH4_PSCOUNT_FBSEL_GET(x)                                     (((x) & MERLIN_SYNTH4_PSCOUNT_FBSEL_MASK) >> MERLIN_SYNTH4_PSCOUNT_FBSEL_LSB)
#define MERLIN_SYNTH4_PSCOUNT_FBSEL_SET(x)                                     (((0 | (x)) << MERLIN_SYNTH4_PSCOUNT_FBSEL_LSB) & MERLIN_SYNTH4_PSCOUNT_FBSEL_MASK)
#define MERLIN_SYNTH4_PSCOUNT_FBSEL_RESET                                      0x0
#define MERLIN_SYNTH4_FORCE_LOBUF5GTUNE_LSB                                    4
#define MERLIN_SYNTH4_FORCE_LOBUF5GTUNE_MSB                                    4
#define MERLIN_SYNTH4_FORCE_LOBUF5GTUNE_MASK                                   0x10
#define MERLIN_SYNTH4_FORCE_LOBUF5GTUNE_GET(x)                                 (((x) & MERLIN_SYNTH4_FORCE_LOBUF5GTUNE_MASK) >> MERLIN_SYNTH4_FORCE_LOBUF5GTUNE_LSB)
#define MERLIN_SYNTH4_FORCE_LOBUF5GTUNE_SET(x)                                 (((0 | (x)) << MERLIN_SYNTH4_FORCE_LOBUF5GTUNE_LSB) & MERLIN_SYNTH4_FORCE_LOBUF5GTUNE_MASK)
#define MERLIN_SYNTH4_FORCE_LOBUF5GTUNE_RESET                                  0x0
#define MERLIN_SYNTH4_LOBUF5GTUNE_OVR_LSB                                      2
#define MERLIN_SYNTH4_LOBUF5GTUNE_OVR_MSB                                      3
#define MERLIN_SYNTH4_LOBUF5GTUNE_OVR_MASK                                     0xc
#define MERLIN_SYNTH4_LOBUF5GTUNE_OVR_GET(x)                                   (((x) & MERLIN_SYNTH4_LOBUF5GTUNE_OVR_MASK) >> MERLIN_SYNTH4_LOBUF5GTUNE_OVR_LSB)
#define MERLIN_SYNTH4_LOBUF5GTUNE_OVR_SET(x)                                   (((0 | (x)) << MERLIN_SYNTH4_LOBUF5GTUNE_OVR_LSB) & MERLIN_SYNTH4_LOBUF5GTUNE_OVR_MASK)
#define MERLIN_SYNTH4_LOBUF5GTUNE_OVR_RESET                                    0x2
#define MERLIN_SYNTH4_LONGSHIFTSEL_LSB                                         1
#define MERLIN_SYNTH4_LONGSHIFTSEL_MSB                                         1
#define MERLIN_SYNTH4_LONGSHIFTSEL_MASK                                        0x2
#define MERLIN_SYNTH4_LONGSHIFTSEL_GET(x)                                      (((x) & MERLIN_SYNTH4_LONGSHIFTSEL_MASK) >> MERLIN_SYNTH4_LONGSHIFTSEL_LSB)
#define MERLIN_SYNTH4_LONGSHIFTSEL_SET(x)                                      (((0 | (x)) << MERLIN_SYNTH4_LONGSHIFTSEL_LSB) & MERLIN_SYNTH4_LONGSHIFTSEL_MASK)
#define MERLIN_SYNTH4_LONGSHIFTSEL_RESET                                       0x0
#define MERLIN_SYNTH4_FORCE_SHIFTREG_LSB                                       0
#define MERLIN_SYNTH4_FORCE_SHIFTREG_MSB                                       0
#define MERLIN_SYNTH4_FORCE_SHIFTREG_MASK                                      0x1
#define MERLIN_SYNTH4_FORCE_SHIFTREG_GET(x)                                    (((x) & MERLIN_SYNTH4_FORCE_SHIFTREG_MASK) >> MERLIN_SYNTH4_FORCE_SHIFTREG_LSB)
#define MERLIN_SYNTH4_FORCE_SHIFTREG_SET(x)                                    (((0 | (x)) << MERLIN_SYNTH4_FORCE_SHIFTREG_LSB) & MERLIN_SYNTH4_FORCE_SHIFTREG_MASK)
#define MERLIN_SYNTH4_FORCE_SHIFTREG_RESET                                     0x0
#define MERLIN_SYNTH4_ADDRESS                                                  (0x54 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH4_RSTMASK                                                  0xffffffff
#define MERLIN_SYNTH4_RESET                                                    0x12025808

// 0x58 (MERLIN_SYNTH5)
#define MERLIN_SYNTH5_IRCP_LSB                                                 29
#define MERLIN_SYNTH5_IRCP_MSB                                                 31
#define MERLIN_SYNTH5_IRCP_MASK                                                0xe0000000
#define MERLIN_SYNTH5_IRCP_GET(x)                                              (((x) & MERLIN_SYNTH5_IRCP_MASK) >> MERLIN_SYNTH5_IRCP_LSB)
#define MERLIN_SYNTH5_IRCP_SET(x)                                              (((0 | (x)) << MERLIN_SYNTH5_IRCP_LSB) & MERLIN_SYNTH5_IRCP_MASK)
#define MERLIN_SYNTH5_IRCP_RESET                                               0x4
#define MERLIN_SYNTH5_IRVCMON_LSB                                              26
#define MERLIN_SYNTH5_IRVCMON_MSB                                              28
#define MERLIN_SYNTH5_IRVCMON_MASK                                             0x1c000000
#define MERLIN_SYNTH5_IRVCMON_GET(x)                                           (((x) & MERLIN_SYNTH5_IRVCMON_MASK) >> MERLIN_SYNTH5_IRVCMON_LSB)
#define MERLIN_SYNTH5_IRVCMON_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH5_IRVCMON_LSB) & MERLIN_SYNTH5_IRVCMON_MASK)
#define MERLIN_SYNTH5_IRVCMON_RESET                                            0x4
#define MERLIN_SYNTH5_IRLOPKDET_LSB                                            23
#define MERLIN_SYNTH5_IRLOPKDET_MSB                                            25
#define MERLIN_SYNTH5_IRLOPKDET_MASK                                           0x3800000
#define MERLIN_SYNTH5_IRLOPKDET_GET(x)                                         (((x) & MERLIN_SYNTH5_IRLOPKDET_MASK) >> MERLIN_SYNTH5_IRLOPKDET_LSB)
#define MERLIN_SYNTH5_IRLOPKDET_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH5_IRLOPKDET_LSB) & MERLIN_SYNTH5_IRLOPKDET_MASK)
#define MERLIN_SYNTH5_IRLOPKDET_RESET                                          0x4
#define MERLIN_SYNTH5_ICPRESC_LSB                                              20
#define MERLIN_SYNTH5_ICPRESC_MSB                                              22
#define MERLIN_SYNTH5_ICPRESC_MASK                                             0x700000
#define MERLIN_SYNTH5_ICPRESC_GET(x)                                           (((x) & MERLIN_SYNTH5_ICPRESC_MASK) >> MERLIN_SYNTH5_ICPRESC_LSB)
#define MERLIN_SYNTH5_ICPRESC_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH5_ICPRESC_LSB) & MERLIN_SYNTH5_ICPRESC_MASK)
#define MERLIN_SYNTH5_ICPRESC_RESET                                            0x4
#define MERLIN_SYNTH5_ICLODIV_LSB                                              17
#define MERLIN_SYNTH5_ICLODIV_MSB                                              19
#define MERLIN_SYNTH5_ICLODIV_MASK                                             0xe0000
#define MERLIN_SYNTH5_ICLODIV_GET(x)                                           (((x) & MERLIN_SYNTH5_ICLODIV_MASK) >> MERLIN_SYNTH5_ICLODIV_LSB)
#define MERLIN_SYNTH5_ICLODIV_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH5_ICLODIV_LSB) & MERLIN_SYNTH5_ICLODIV_MASK)
#define MERLIN_SYNTH5_ICLODIV_RESET                                            0x4
#define MERLIN_SYNTH5_ICLOMIX_LSB                                              14
#define MERLIN_SYNTH5_ICLOMIX_MSB                                              16
#define MERLIN_SYNTH5_ICLOMIX_MASK                                             0x1c000
#define MERLIN_SYNTH5_ICLOMIX_GET(x)                                           (((x) & MERLIN_SYNTH5_ICLOMIX_MASK) >> MERLIN_SYNTH5_ICLOMIX_LSB)
#define MERLIN_SYNTH5_ICLOMIX_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH5_ICLOMIX_LSB) & MERLIN_SYNTH5_ICLOMIX_MASK)
#define MERLIN_SYNTH5_ICLOMIX_RESET                                            0x4
#define MERLIN_SYNTH5_ICVCOREG_LSB                                             11
#define MERLIN_SYNTH5_ICVCOREG_MSB                                             13
#define MERLIN_SYNTH5_ICVCOREG_MASK                                            0x3800
#define MERLIN_SYNTH5_ICVCOREG_GET(x)                                          (((x) & MERLIN_SYNTH5_ICVCOREG_MASK) >> MERLIN_SYNTH5_ICVCOREG_LSB)
#define MERLIN_SYNTH5_ICVCOREG_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH5_ICVCOREG_LSB) & MERLIN_SYNTH5_ICVCOREG_MASK)
#define MERLIN_SYNTH5_ICVCOREG_RESET                                           0x4
#define MERLIN_SYNTH5_ICVCO_LSB                                                8
#define MERLIN_SYNTH5_ICVCO_MSB                                                10
#define MERLIN_SYNTH5_ICVCO_MASK                                               0x700
#define MERLIN_SYNTH5_ICVCO_GET(x)                                             (((x) & MERLIN_SYNTH5_ICVCO_MASK) >> MERLIN_SYNTH5_ICVCO_LSB)
#define MERLIN_SYNTH5_ICVCO_SET(x)                                             (((0 | (x)) << MERLIN_SYNTH5_ICVCO_LSB) & MERLIN_SYNTH5_ICVCO_MASK)
#define MERLIN_SYNTH5_ICVCO_RESET                                              0x4
#define MERLIN_SYNTH5_ICLOBUF2G_LSB                                            5
#define MERLIN_SYNTH5_ICLOBUF2G_MSB                                            7
#define MERLIN_SYNTH5_ICLOBUF2G_MASK                                           0xe0
#define MERLIN_SYNTH5_ICLOBUF2G_GET(x)                                         (((x) & MERLIN_SYNTH5_ICLOBUF2G_MASK) >> MERLIN_SYNTH5_ICLOBUF2G_LSB)
#define MERLIN_SYNTH5_ICLOBUF2G_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH5_ICLOBUF2G_LSB) & MERLIN_SYNTH5_ICLOBUF2G_MASK)
#define MERLIN_SYNTH5_ICLOBUF2G_RESET                                          0x4
#define MERLIN_SYNTH5_ICLOBUF5G_LSB                                            2
#define MERLIN_SYNTH5_ICLOBUF5G_MSB                                            4
#define MERLIN_SYNTH5_ICLOBUF5G_MASK                                           0x1c
#define MERLIN_SYNTH5_ICLOBUF5G_GET(x)                                         (((x) & MERLIN_SYNTH5_ICLOBUF5G_MASK) >> MERLIN_SYNTH5_ICLOBUF5G_LSB)
#define MERLIN_SYNTH5_ICLOBUF5G_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH5_ICLOBUF5G_LSB) & MERLIN_SYNTH5_ICLOBUF5G_MASK)
#define MERLIN_SYNTH5_ICLOBUF5G_RESET                                          0x4
#define MERLIN_SYNTH5_ICPKCOMP_LSB                                             0
#define MERLIN_SYNTH5_ICPKCOMP_MSB                                             1
#define MERLIN_SYNTH5_ICPKCOMP_MASK                                            0x3
#define MERLIN_SYNTH5_ICPKCOMP_GET(x)                                          (((x) & MERLIN_SYNTH5_ICPKCOMP_MASK) >> MERLIN_SYNTH5_ICPKCOMP_LSB)
#define MERLIN_SYNTH5_ICPKCOMP_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH5_ICPKCOMP_LSB) & MERLIN_SYNTH5_ICPKCOMP_MASK)
#define MERLIN_SYNTH5_ICPKCOMP_RESET                                           0x2
#define MERLIN_SYNTH5_ADDRESS                                                  (0x58 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH5_RSTMASK                                                  0xffffffff
#define MERLIN_SYNTH5_RESET                                                    0x92492492

// 0x5c (MERLIN_SYNTH6)
#define MERLIN_SYNTH6_SYNTH_ON_LSB                                             31
#define MERLIN_SYNTH6_SYNTH_ON_MSB                                             31
#define MERLIN_SYNTH6_SYNTH_ON_MASK                                            0x80000000
#define MERLIN_SYNTH6_SYNTH_ON_GET(x)                                          (((x) & MERLIN_SYNTH6_SYNTH_ON_MASK) >> MERLIN_SYNTH6_SYNTH_ON_LSB)
#define MERLIN_SYNTH6_SYNTH_ON_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH6_SYNTH_ON_LSB) & MERLIN_SYNTH6_SYNTH_ON_MASK)
#define MERLIN_SYNTH6_SYNTH_ON_RESET                                           0x0
#define MERLIN_SYNTH6_SYNTH_SM_STATE_LSB                                       27
#define MERLIN_SYNTH6_SYNTH_SM_STATE_MSB                                       30
#define MERLIN_SYNTH6_SYNTH_SM_STATE_MASK                                      0x78000000
#define MERLIN_SYNTH6_SYNTH_SM_STATE_GET(x)                                    (((x) & MERLIN_SYNTH6_SYNTH_SM_STATE_MASK) >> MERLIN_SYNTH6_SYNTH_SM_STATE_LSB)
#define MERLIN_SYNTH6_SYNTH_SM_STATE_SET(x)                                    (((0 | (x)) << MERLIN_SYNTH6_SYNTH_SM_STATE_LSB) & MERLIN_SYNTH6_SYNTH_SM_STATE_MASK)
#define MERLIN_SYNTH6_SYNTH_SM_STATE_RESET                                     0x0
#define MERLIN_SYNTH6_CAP_SEARCH_LSB                                           26
#define MERLIN_SYNTH6_CAP_SEARCH_MSB                                           26
#define MERLIN_SYNTH6_CAP_SEARCH_MASK                                          0x4000000
#define MERLIN_SYNTH6_CAP_SEARCH_GET(x)                                        (((x) & MERLIN_SYNTH6_CAP_SEARCH_MASK) >> MERLIN_SYNTH6_CAP_SEARCH_LSB)
#define MERLIN_SYNTH6_CAP_SEARCH_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH6_CAP_SEARCH_LSB) & MERLIN_SYNTH6_CAP_SEARCH_MASK)
#define MERLIN_SYNTH6_CAP_SEARCH_RESET                                         0x0
#define MERLIN_SYNTH6_SYNTH_LOCK_VC_OK_LSB                                     25
#define MERLIN_SYNTH6_SYNTH_LOCK_VC_OK_MSB                                     25
#define MERLIN_SYNTH6_SYNTH_LOCK_VC_OK_MASK                                    0x2000000
#define MERLIN_SYNTH6_SYNTH_LOCK_VC_OK_GET(x)                                  (((x) & MERLIN_SYNTH6_SYNTH_LOCK_VC_OK_MASK) >> MERLIN_SYNTH6_SYNTH_LOCK_VC_OK_LSB)
#define MERLIN_SYNTH6_SYNTH_LOCK_VC_OK_SET(x)                                  (((0 | (x)) << MERLIN_SYNTH6_SYNTH_LOCK_VC_OK_LSB) & MERLIN_SYNTH6_SYNTH_LOCK_VC_OK_MASK)
#define MERLIN_SYNTH6_SYNTH_LOCK_VC_OK_RESET                                   0x0
#define MERLIN_SYNTH6_PIN_VC_LSB                                               24
#define MERLIN_SYNTH6_PIN_VC_MSB                                               24
#define MERLIN_SYNTH6_PIN_VC_MASK                                              0x1000000
#define MERLIN_SYNTH6_PIN_VC_GET(x)                                            (((x) & MERLIN_SYNTH6_PIN_VC_MASK) >> MERLIN_SYNTH6_PIN_VC_LSB)
#define MERLIN_SYNTH6_PIN_VC_SET(x)                                            (((0 | (x)) << MERLIN_SYNTH6_PIN_VC_LSB) & MERLIN_SYNTH6_PIN_VC_MASK)
#define MERLIN_SYNTH6_PIN_VC_RESET                                             0x0
#define MERLIN_SYNTH6_VCO_CAP_ST_LSB                                           16
#define MERLIN_SYNTH6_VCO_CAP_ST_MSB                                           23
#define MERLIN_SYNTH6_VCO_CAP_ST_MASK                                          0xff0000
#define MERLIN_SYNTH6_VCO_CAP_ST_GET(x)                                        (((x) & MERLIN_SYNTH6_VCO_CAP_ST_MASK) >> MERLIN_SYNTH6_VCO_CAP_ST_LSB)
#define MERLIN_SYNTH6_VCO_CAP_ST_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH6_VCO_CAP_ST_LSB) & MERLIN_SYNTH6_VCO_CAP_ST_MASK)
#define MERLIN_SYNTH6_VCO_CAP_ST_RESET                                         0x0
#define MERLIN_SYNTH6_SHORT_R_LSB                                              15
#define MERLIN_SYNTH6_SHORT_R_MSB                                              15
#define MERLIN_SYNTH6_SHORT_R_MASK                                             0x8000
#define MERLIN_SYNTH6_SHORT_R_GET(x)                                           (((x) & MERLIN_SYNTH6_SHORT_R_MASK) >> MERLIN_SYNTH6_SHORT_R_LSB)
#define MERLIN_SYNTH6_SHORT_R_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH6_SHORT_R_LSB) & MERLIN_SYNTH6_SHORT_R_MASK)
#define MERLIN_SYNTH6_SHORT_R_RESET                                            0x0
#define MERLIN_SYNTH6_RESET_RFD_LSB                                            14
#define MERLIN_SYNTH6_RESET_RFD_MSB                                            14
#define MERLIN_SYNTH6_RESET_RFD_MASK                                           0x4000
#define MERLIN_SYNTH6_RESET_RFD_GET(x)                                         (((x) & MERLIN_SYNTH6_RESET_RFD_MASK) >> MERLIN_SYNTH6_RESET_RFD_LSB)
#define MERLIN_SYNTH6_RESET_RFD_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH6_RESET_RFD_LSB) & MERLIN_SYNTH6_RESET_RFD_MASK)
#define MERLIN_SYNTH6_RESET_RFD_RESET                                          0x0
#define MERLIN_SYNTH6_RESET_PFD_LSB                                            13
#define MERLIN_SYNTH6_RESET_PFD_MSB                                            13
#define MERLIN_SYNTH6_RESET_PFD_MASK                                           0x2000
#define MERLIN_SYNTH6_RESET_PFD_GET(x)                                         (((x) & MERLIN_SYNTH6_RESET_PFD_MASK) >> MERLIN_SYNTH6_RESET_PFD_LSB)
#define MERLIN_SYNTH6_RESET_PFD_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH6_RESET_PFD_LSB) & MERLIN_SYNTH6_RESET_PFD_MASK)
#define MERLIN_SYNTH6_RESET_PFD_RESET                                          0x0
#define MERLIN_SYNTH6_RESET_PSCOUNTERS_LSB                                     12
#define MERLIN_SYNTH6_RESET_PSCOUNTERS_MSB                                     12
#define MERLIN_SYNTH6_RESET_PSCOUNTERS_MASK                                    0x1000
#define MERLIN_SYNTH6_RESET_PSCOUNTERS_GET(x)                                  (((x) & MERLIN_SYNTH6_RESET_PSCOUNTERS_MASK) >> MERLIN_SYNTH6_RESET_PSCOUNTERS_LSB)
#define MERLIN_SYNTH6_RESET_PSCOUNTERS_SET(x)                                  (((0 | (x)) << MERLIN_SYNTH6_RESET_PSCOUNTERS_LSB) & MERLIN_SYNTH6_RESET_PSCOUNTERS_MASK)
#define MERLIN_SYNTH6_RESET_PSCOUNTERS_RESET                                   0x0
#define MERLIN_SYNTH6_RESET_SDM_B_LSB                                          11
#define MERLIN_SYNTH6_RESET_SDM_B_MSB                                          11
#define MERLIN_SYNTH6_RESET_SDM_B_MASK                                         0x800
#define MERLIN_SYNTH6_RESET_SDM_B_GET(x)                                       (((x) & MERLIN_SYNTH6_RESET_SDM_B_MASK) >> MERLIN_SYNTH6_RESET_SDM_B_LSB)
#define MERLIN_SYNTH6_RESET_SDM_B_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH6_RESET_SDM_B_LSB) & MERLIN_SYNTH6_RESET_SDM_B_MASK)
#define MERLIN_SYNTH6_RESET_SDM_B_RESET                                        0x0
#define MERLIN_SYNTH6_VC2HIGH_LSB                                              10
#define MERLIN_SYNTH6_VC2HIGH_MSB                                              10
#define MERLIN_SYNTH6_VC2HIGH_MASK                                             0x400
#define MERLIN_SYNTH6_VC2HIGH_GET(x)                                           (((x) & MERLIN_SYNTH6_VC2HIGH_MASK) >> MERLIN_SYNTH6_VC2HIGH_LSB)
#define MERLIN_SYNTH6_VC2HIGH_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH6_VC2HIGH_LSB) & MERLIN_SYNTH6_VC2HIGH_MASK)
#define MERLIN_SYNTH6_VC2HIGH_RESET                                            0x0
#define MERLIN_SYNTH6_VC2LOW_LSB                                               9
#define MERLIN_SYNTH6_VC2LOW_MSB                                               9
#define MERLIN_SYNTH6_VC2LOW_MASK                                              0x200
#define MERLIN_SYNTH6_VC2LOW_GET(x)                                            (((x) & MERLIN_SYNTH6_VC2LOW_MASK) >> MERLIN_SYNTH6_VC2LOW_LSB)
#define MERLIN_SYNTH6_VC2LOW_SET(x)                                            (((0 | (x)) << MERLIN_SYNTH6_VC2LOW_LSB) & MERLIN_SYNTH6_VC2LOW_MASK)
#define MERLIN_SYNTH6_VC2LOW_RESET                                             0x0
#define MERLIN_SYNTH6_LOOP_IP_LSB                                              2
#define MERLIN_SYNTH6_LOOP_IP_MSB                                              8
#define MERLIN_SYNTH6_LOOP_IP_MASK                                             0x1fc
#define MERLIN_SYNTH6_LOOP_IP_GET(x)                                           (((x) & MERLIN_SYNTH6_LOOP_IP_MASK) >> MERLIN_SYNTH6_LOOP_IP_LSB)
#define MERLIN_SYNTH6_LOOP_IP_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH6_LOOP_IP_LSB) & MERLIN_SYNTH6_LOOP_IP_MASK)
#define MERLIN_SYNTH6_LOOP_IP_RESET                                            0x0
#define MERLIN_SYNTH6_LOBUF5GTUNE_LSB                                          0
#define MERLIN_SYNTH6_LOBUF5GTUNE_MSB                                          1
#define MERLIN_SYNTH6_LOBUF5GTUNE_MASK                                         0x3
#define MERLIN_SYNTH6_LOBUF5GTUNE_GET(x)                                       (((x) & MERLIN_SYNTH6_LOBUF5GTUNE_MASK) >> MERLIN_SYNTH6_LOBUF5GTUNE_LSB)
#define MERLIN_SYNTH6_LOBUF5GTUNE_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH6_LOBUF5GTUNE_LSB) & MERLIN_SYNTH6_LOBUF5GTUNE_MASK)
#define MERLIN_SYNTH6_LOBUF5GTUNE_RESET                                        0x0
#define MERLIN_SYNTH6_ADDRESS                                                  (0x5c + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH6_RSTMASK                                                  0xffffffff
#define MERLIN_SYNTH6_RESET                                                    0x0

// 0x60 (MERLIN_SYNTH7)
#define MERLIN_SYNTH7_LOADSYNTHCHANNEL_LSB                                     31
#define MERLIN_SYNTH7_LOADSYNTHCHANNEL_MSB                                     31
#define MERLIN_SYNTH7_LOADSYNTHCHANNEL_MASK                                    0x80000000
#define MERLIN_SYNTH7_LOADSYNTHCHANNEL_GET(x)                                  (((x) & MERLIN_SYNTH7_LOADSYNTHCHANNEL_MASK) >> MERLIN_SYNTH7_LOADSYNTHCHANNEL_LSB)
#define MERLIN_SYNTH7_LOADSYNTHCHANNEL_SET(x)                                  (((0 | (x)) << MERLIN_SYNTH7_LOADSYNTHCHANNEL_LSB) & MERLIN_SYNTH7_LOADSYNTHCHANNEL_MASK)
#define MERLIN_SYNTH7_LOADSYNTHCHANNEL_RESET                                   0x0
#define MERLIN_SYNTH7_FRACMODE_LSB                                             30
#define MERLIN_SYNTH7_FRACMODE_MSB                                             30
#define MERLIN_SYNTH7_FRACMODE_MASK                                            0x40000000
#define MERLIN_SYNTH7_FRACMODE_GET(x)                                          (((x) & MERLIN_SYNTH7_FRACMODE_MASK) >> MERLIN_SYNTH7_FRACMODE_LSB)
#define MERLIN_SYNTH7_FRACMODE_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH7_FRACMODE_LSB) & MERLIN_SYNTH7_FRACMODE_MASK)
#define MERLIN_SYNTH7_FRACMODE_RESET                                           0x0
#define MERLIN_SYNTH7_AMODEREFSEL_LSB                                          28
#define MERLIN_SYNTH7_AMODEREFSEL_MSB                                          29
#define MERLIN_SYNTH7_AMODEREFSEL_MASK                                         0x30000000
#define MERLIN_SYNTH7_AMODEREFSEL_GET(x)                                       (((x) & MERLIN_SYNTH7_AMODEREFSEL_MASK) >> MERLIN_SYNTH7_AMODEREFSEL_LSB)
#define MERLIN_SYNTH7_AMODEREFSEL_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH7_AMODEREFSEL_LSB) & MERLIN_SYNTH7_AMODEREFSEL_MASK)
#define MERLIN_SYNTH7_AMODEREFSEL_RESET                                        0x0
#define MERLIN_SYNTH7_CHANSEL_LSB                                              19
#define MERLIN_SYNTH7_CHANSEL_MSB                                              27
#define MERLIN_SYNTH7_CHANSEL_MASK                                             0xff80000
#define MERLIN_SYNTH7_CHANSEL_GET(x)                                           (((x) & MERLIN_SYNTH7_CHANSEL_MASK) >> MERLIN_SYNTH7_CHANSEL_LSB)
#define MERLIN_SYNTH7_CHANSEL_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH7_CHANSEL_LSB) & MERLIN_SYNTH7_CHANSEL_MASK)
#define MERLIN_SYNTH7_CHANSEL_RESET                                            0x0
#define MERLIN_SYNTH7_CHANFRAC_LSB                                             2
#define MERLIN_SYNTH7_CHANFRAC_MSB                                             18
#define MERLIN_SYNTH7_CHANFRAC_MASK                                            0x7fffc
#define MERLIN_SYNTH7_CHANFRAC_GET(x)                                          (((x) & MERLIN_SYNTH7_CHANFRAC_MASK) >> MERLIN_SYNTH7_CHANFRAC_LSB)
#define MERLIN_SYNTH7_CHANFRAC_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH7_CHANFRAC_LSB) & MERLIN_SYNTH7_CHANFRAC_MASK)
#define MERLIN_SYNTH7_CHANFRAC_RESET                                           0x0
#define MERLIN_SYNTH7_FORCE_FRACLSB_LSB                                        1
#define MERLIN_SYNTH7_FORCE_FRACLSB_MSB                                        1
#define MERLIN_SYNTH7_FORCE_FRACLSB_MASK                                       0x2
#define MERLIN_SYNTH7_FORCE_FRACLSB_GET(x)                                     (((x) & MERLIN_SYNTH7_FORCE_FRACLSB_MASK) >> MERLIN_SYNTH7_FORCE_FRACLSB_LSB)
#define MERLIN_SYNTH7_FORCE_FRACLSB_SET(x)                                     (((0 | (x)) << MERLIN_SYNTH7_FORCE_FRACLSB_LSB) & MERLIN_SYNTH7_FORCE_FRACLSB_MASK)
#define MERLIN_SYNTH7_FORCE_FRACLSB_RESET                                      0x0
#define MERLIN_SYNTH7_OVRCHANDECODER_LSB                                       0
#define MERLIN_SYNTH7_OVRCHANDECODER_MSB                                       0
#define MERLIN_SYNTH7_OVRCHANDECODER_MASK                                      0x1
#define MERLIN_SYNTH7_OVRCHANDECODER_GET(x)                                    (((x) & MERLIN_SYNTH7_OVRCHANDECODER_MASK) >> MERLIN_SYNTH7_OVRCHANDECODER_LSB)
#define MERLIN_SYNTH7_OVRCHANDECODER_SET(x)                                    (((0 | (x)) << MERLIN_SYNTH7_OVRCHANDECODER_LSB) & MERLIN_SYNTH7_OVRCHANDECODER_MASK)
#define MERLIN_SYNTH7_OVRCHANDECODER_RESET                                     0x0
#define MERLIN_SYNTH7_ADDRESS                                                  (0x60 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH7_RSTMASK                                                  0xffffffff
#define MERLIN_SYNTH7_RESET                                                    0x0

// 0x64 (MERLIN_SYNTH8)
#define MERLIN_SYNTH8_REFDIVB_LSB                                              27
#define MERLIN_SYNTH8_REFDIVB_MSB                                              31
#define MERLIN_SYNTH8_REFDIVB_MASK                                             0xf8000000
#define MERLIN_SYNTH8_REFDIVB_GET(x)                                           (((x) & MERLIN_SYNTH8_REFDIVB_MASK) >> MERLIN_SYNTH8_REFDIVB_LSB)
#define MERLIN_SYNTH8_REFDIVB_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH8_REFDIVB_LSB) & MERLIN_SYNTH8_REFDIVB_MASK)
#define MERLIN_SYNTH8_REFDIVB_RESET                                            0x1
#define MERLIN_SYNTH8_LOOP_3RD_ORDER_RB_LSB                                    22
#define MERLIN_SYNTH8_LOOP_3RD_ORDER_RB_MSB                                    26
#define MERLIN_SYNTH8_LOOP_3RD_ORDER_RB_MASK                                   0x7c00000
#define MERLIN_SYNTH8_LOOP_3RD_ORDER_RB_GET(x)                                 (((x) & MERLIN_SYNTH8_LOOP_3RD_ORDER_RB_MASK) >> MERLIN_SYNTH8_LOOP_3RD_ORDER_RB_LSB)
#define MERLIN_SYNTH8_LOOP_3RD_ORDER_RB_SET(x)                                 (((0 | (x)) << MERLIN_SYNTH8_LOOP_3RD_ORDER_RB_LSB) & MERLIN_SYNTH8_LOOP_3RD_ORDER_RB_MASK)
#define MERLIN_SYNTH8_LOOP_3RD_ORDER_RB_RESET                                  0x8
#define MERLIN_SYNTH8_LOOP_CPB_LSB                                             17
#define MERLIN_SYNTH8_LOOP_CPB_MSB                                             21
#define MERLIN_SYNTH8_LOOP_CPB_MASK                                            0x3e0000
#define MERLIN_SYNTH8_LOOP_CPB_GET(x)                                          (((x) & MERLIN_SYNTH8_LOOP_CPB_MASK) >> MERLIN_SYNTH8_LOOP_CPB_LSB)
#define MERLIN_SYNTH8_LOOP_CPB_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH8_LOOP_CPB_LSB) & MERLIN_SYNTH8_LOOP_CPB_MASK)
#define MERLIN_SYNTH8_LOOP_CPB_RESET                                           0x8
#define MERLIN_SYNTH8_LOOP_RSB_LSB                                             12
#define MERLIN_SYNTH8_LOOP_RSB_MSB                                             16
#define MERLIN_SYNTH8_LOOP_RSB_MASK                                            0x1f000
#define MERLIN_SYNTH8_LOOP_RSB_GET(x)                                          (((x) & MERLIN_SYNTH8_LOOP_RSB_MASK) >> MERLIN_SYNTH8_LOOP_RSB_LSB)
#define MERLIN_SYNTH8_LOOP_RSB_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH8_LOOP_RSB_LSB) & MERLIN_SYNTH8_LOOP_RSB_MASK)
#define MERLIN_SYNTH8_LOOP_RSB_RESET                                           0x5
#define MERLIN_SYNTH8_LOOP_CSB_LSB                                             8
#define MERLIN_SYNTH8_LOOP_CSB_MSB                                             11
#define MERLIN_SYNTH8_LOOP_CSB_MASK                                            0xf00
#define MERLIN_SYNTH8_LOOP_CSB_GET(x)                                          (((x) & MERLIN_SYNTH8_LOOP_CSB_MASK) >> MERLIN_SYNTH8_LOOP_CSB_LSB)
#define MERLIN_SYNTH8_LOOP_CSB_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH8_LOOP_CSB_LSB) & MERLIN_SYNTH8_LOOP_CSB_MASK)
#define MERLIN_SYNTH8_LOOP_CSB_RESET                                           0x3
#define MERLIN_SYNTH8_LOOP_ICPB_LSB                                            1
#define MERLIN_SYNTH8_LOOP_ICPB_MSB                                            7
#define MERLIN_SYNTH8_LOOP_ICPB_MASK                                           0xfe
#define MERLIN_SYNTH8_LOOP_ICPB_GET(x)                                         (((x) & MERLIN_SYNTH8_LOOP_ICPB_MASK) >> MERLIN_SYNTH8_LOOP_ICPB_LSB)
#define MERLIN_SYNTH8_LOOP_ICPB_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH8_LOOP_ICPB_LSB) & MERLIN_SYNTH8_LOOP_ICPB_MASK)
#define MERLIN_SYNTH8_LOOP_ICPB_RESET                                          0x7
#define MERLIN_SYNTH8_CPSTEERING_EN_FRACN_LSB                                  0
#define MERLIN_SYNTH8_CPSTEERING_EN_FRACN_MSB                                  0
#define MERLIN_SYNTH8_CPSTEERING_EN_FRACN_MASK                                 0x1
#define MERLIN_SYNTH8_CPSTEERING_EN_FRACN_GET(x)                               (((x) & MERLIN_SYNTH8_CPSTEERING_EN_FRACN_MASK) >> MERLIN_SYNTH8_CPSTEERING_EN_FRACN_LSB)
#define MERLIN_SYNTH8_CPSTEERING_EN_FRACN_SET(x)                               (((0 | (x)) << MERLIN_SYNTH8_CPSTEERING_EN_FRACN_LSB) & MERLIN_SYNTH8_CPSTEERING_EN_FRACN_MASK)
#define MERLIN_SYNTH8_CPSTEERING_EN_FRACN_RESET                                0x0
#define MERLIN_SYNTH8_ADDRESS                                                  (0x64 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH8_RSTMASK                                                  0xffffffff
#define MERLIN_SYNTH8_RESET                                                    0xa10530e

// 0x68 (MERLIN_SYNTH9)
#define MERLIN_SYNTH9_REFDIVA_LSB                                              27
#define MERLIN_SYNTH9_REFDIVA_MSB                                              31
#define MERLIN_SYNTH9_REFDIVA_MASK                                             0xf8000000
#define MERLIN_SYNTH9_REFDIVA_GET(x)                                           (((x) & MERLIN_SYNTH9_REFDIVA_MASK) >> MERLIN_SYNTH9_REFDIVA_LSB)
#define MERLIN_SYNTH9_REFDIVA_SET(x)                                           (((0 | (x)) << MERLIN_SYNTH9_REFDIVA_LSB) & MERLIN_SYNTH9_REFDIVA_MASK)
#define MERLIN_SYNTH9_REFDIVA_RESET                                            0x18
#define MERLIN_SYNTH9_LOOP_3RD_ORDER_RA_LSB                                    22
#define MERLIN_SYNTH9_LOOP_3RD_ORDER_RA_MSB                                    26
#define MERLIN_SYNTH9_LOOP_3RD_ORDER_RA_MASK                                   0x7c00000
#define MERLIN_SYNTH9_LOOP_3RD_ORDER_RA_GET(x)                                 (((x) & MERLIN_SYNTH9_LOOP_3RD_ORDER_RA_MASK) >> MERLIN_SYNTH9_LOOP_3RD_ORDER_RA_LSB)
#define MERLIN_SYNTH9_LOOP_3RD_ORDER_RA_SET(x)                                 (((0 | (x)) << MERLIN_SYNTH9_LOOP_3RD_ORDER_RA_LSB) & MERLIN_SYNTH9_LOOP_3RD_ORDER_RA_MASK)
#define MERLIN_SYNTH9_LOOP_3RD_ORDER_RA_RESET                                  0x0
#define MERLIN_SYNTH9_LOOP_CPA0_LSB                                            17
#define MERLIN_SYNTH9_LOOP_CPA0_MSB                                            21
#define MERLIN_SYNTH9_LOOP_CPA0_MASK                                           0x3e0000
#define MERLIN_SYNTH9_LOOP_CPA0_GET(x)                                         (((x) & MERLIN_SYNTH9_LOOP_CPA0_MASK) >> MERLIN_SYNTH9_LOOP_CPA0_LSB)
#define MERLIN_SYNTH9_LOOP_CPA0_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH9_LOOP_CPA0_LSB) & MERLIN_SYNTH9_LOOP_CPA0_MASK)
#define MERLIN_SYNTH9_LOOP_CPA0_RESET                                          0x10
#define MERLIN_SYNTH9_LOOP_RSA0_LSB                                            12
#define MERLIN_SYNTH9_LOOP_RSA0_MSB                                            16
#define MERLIN_SYNTH9_LOOP_RSA0_MASK                                           0x1f000
#define MERLIN_SYNTH9_LOOP_RSA0_GET(x)                                         (((x) & MERLIN_SYNTH9_LOOP_RSA0_MASK) >> MERLIN_SYNTH9_LOOP_RSA0_LSB)
#define MERLIN_SYNTH9_LOOP_RSA0_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH9_LOOP_RSA0_LSB) & MERLIN_SYNTH9_LOOP_RSA0_MASK)
#define MERLIN_SYNTH9_LOOP_RSA0_RESET                                          0x4
#define MERLIN_SYNTH9_LOOP_CSA0_LSB                                            8
#define MERLIN_SYNTH9_LOOP_CSA0_MSB                                            11
#define MERLIN_SYNTH9_LOOP_CSA0_MASK                                           0xf00
#define MERLIN_SYNTH9_LOOP_CSA0_GET(x)                                         (((x) & MERLIN_SYNTH9_LOOP_CSA0_MASK) >> MERLIN_SYNTH9_LOOP_CSA0_LSB)
#define MERLIN_SYNTH9_LOOP_CSA0_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH9_LOOP_CSA0_LSB) & MERLIN_SYNTH9_LOOP_CSA0_MASK)
#define MERLIN_SYNTH9_LOOP_CSA0_RESET                                          0xb
#define MERLIN_SYNTH9_LOOP_ICPA0_LSB                                           4
#define MERLIN_SYNTH9_LOOP_ICPA0_MSB                                           7
#define MERLIN_SYNTH9_LOOP_ICPA0_MASK                                          0xf0
#define MERLIN_SYNTH9_LOOP_ICPA0_GET(x)                                        (((x) & MERLIN_SYNTH9_LOOP_ICPA0_MASK) >> MERLIN_SYNTH9_LOOP_ICPA0_LSB)
#define MERLIN_SYNTH9_LOOP_ICPA0_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH9_LOOP_ICPA0_LSB) & MERLIN_SYNTH9_LOOP_ICPA0_MASK)
#define MERLIN_SYNTH9_LOOP_ICPA0_RESET                                         0x2
#define MERLIN_SYNTH9_SLOPE_ICPA0_LSB                                          1
#define MERLIN_SYNTH9_SLOPE_ICPA0_MSB                                          3
#define MERLIN_SYNTH9_SLOPE_ICPA0_MASK                                         0xe
#define MERLIN_SYNTH9_SLOPE_ICPA0_GET(x)                                       (((x) & MERLIN_SYNTH9_SLOPE_ICPA0_MASK) >> MERLIN_SYNTH9_SLOPE_ICPA0_LSB)
#define MERLIN_SYNTH9_SLOPE_ICPA0_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH9_SLOPE_ICPA0_LSB) & MERLIN_SYNTH9_SLOPE_ICPA0_MASK)
#define MERLIN_SYNTH9_SLOPE_ICPA0_RESET                                        0x0
#define MERLIN_SYNTH9_PFDDELAY_INTN_LSB                                        0
#define MERLIN_SYNTH9_PFDDELAY_INTN_MSB                                        0
#define MERLIN_SYNTH9_PFDDELAY_INTN_MASK                                       0x1
#define MERLIN_SYNTH9_PFDDELAY_INTN_GET(x)                                     (((x) & MERLIN_SYNTH9_PFDDELAY_INTN_MASK) >> MERLIN_SYNTH9_PFDDELAY_INTN_LSB)
#define MERLIN_SYNTH9_PFDDELAY_INTN_SET(x)                                     (((0 | (x)) << MERLIN_SYNTH9_PFDDELAY_INTN_LSB) & MERLIN_SYNTH9_PFDDELAY_INTN_MASK)
#define MERLIN_SYNTH9_PFDDELAY_INTN_RESET                                      0x0
#define MERLIN_SYNTH9_ADDRESS                                                  (0x68 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH9_RSTMASK                                                  0xffffffff
#define MERLIN_SYNTH9_RESET                                                    0xc0204b20

// 0x6c (MERLIN_SYNTH10)
#define MERLIN_SYNTH10_LOOP_CPA1_LSB                                           27
#define MERLIN_SYNTH10_LOOP_CPA1_MSB                                           31
#define MERLIN_SYNTH10_LOOP_CPA1_MASK                                          0xf8000000
#define MERLIN_SYNTH10_LOOP_CPA1_GET(x)                                        (((x) & MERLIN_SYNTH10_LOOP_CPA1_MASK) >> MERLIN_SYNTH10_LOOP_CPA1_LSB)
#define MERLIN_SYNTH10_LOOP_CPA1_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH10_LOOP_CPA1_LSB) & MERLIN_SYNTH10_LOOP_CPA1_MASK)
#define MERLIN_SYNTH10_LOOP_CPA1_RESET                                         0x10
#define MERLIN_SYNTH10_LOOP_RSA1_LSB                                           22
#define MERLIN_SYNTH10_LOOP_RSA1_MSB                                           26
#define MERLIN_SYNTH10_LOOP_RSA1_MASK                                          0x7c00000
#define MERLIN_SYNTH10_LOOP_RSA1_GET(x)                                        (((x) & MERLIN_SYNTH10_LOOP_RSA1_MASK) >> MERLIN_SYNTH10_LOOP_RSA1_LSB)
#define MERLIN_SYNTH10_LOOP_RSA1_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH10_LOOP_RSA1_LSB) & MERLIN_SYNTH10_LOOP_RSA1_MASK)
#define MERLIN_SYNTH10_LOOP_RSA1_RESET                                         0x4
#define MERLIN_SYNTH10_LOOP_CSA1_LSB                                           18
#define MERLIN_SYNTH10_LOOP_CSA1_MSB                                           21
#define MERLIN_SYNTH10_LOOP_CSA1_MASK                                          0x3c0000
#define MERLIN_SYNTH10_LOOP_CSA1_GET(x)                                        (((x) & MERLIN_SYNTH10_LOOP_CSA1_MASK) >> MERLIN_SYNTH10_LOOP_CSA1_LSB)
#define MERLIN_SYNTH10_LOOP_CSA1_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH10_LOOP_CSA1_LSB) & MERLIN_SYNTH10_LOOP_CSA1_MASK)
#define MERLIN_SYNTH10_LOOP_CSA1_RESET                                         0xb
#define MERLIN_SYNTH10_LOOP_ICPA1_LSB                                          14
#define MERLIN_SYNTH10_LOOP_ICPA1_MSB                                          17
#define MERLIN_SYNTH10_LOOP_ICPA1_MASK                                         0x3c000
#define MERLIN_SYNTH10_LOOP_ICPA1_GET(x)                                       (((x) & MERLIN_SYNTH10_LOOP_ICPA1_MASK) >> MERLIN_SYNTH10_LOOP_ICPA1_LSB)
#define MERLIN_SYNTH10_LOOP_ICPA1_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH10_LOOP_ICPA1_LSB) & MERLIN_SYNTH10_LOOP_ICPA1_MASK)
#define MERLIN_SYNTH10_LOOP_ICPA1_RESET                                        0x5
#define MERLIN_SYNTH10_SLOPE_ICPA1_LSB                                         11
#define MERLIN_SYNTH10_SLOPE_ICPA1_MSB                                         13
#define MERLIN_SYNTH10_SLOPE_ICPA1_MASK                                        0x3800
#define MERLIN_SYNTH10_SLOPE_ICPA1_GET(x)                                      (((x) & MERLIN_SYNTH10_SLOPE_ICPA1_MASK) >> MERLIN_SYNTH10_SLOPE_ICPA1_LSB)
#define MERLIN_SYNTH10_SLOPE_ICPA1_SET(x)                                      (((0 | (x)) << MERLIN_SYNTH10_SLOPE_ICPA1_LSB) & MERLIN_SYNTH10_SLOPE_ICPA1_MASK)
#define MERLIN_SYNTH10_SLOPE_ICPA1_RESET                                       0x0
#define MERLIN_SYNTH10_SPARE_LSB                                               0
#define MERLIN_SYNTH10_SPARE_MSB                                               10
#define MERLIN_SYNTH10_SPARE_MASK                                              0x7ff
#define MERLIN_SYNTH10_SPARE_GET(x)                                            (((x) & MERLIN_SYNTH10_SPARE_MASK) >> MERLIN_SYNTH10_SPARE_LSB)
#define MERLIN_SYNTH10_SPARE_SET(x)                                            (((0 | (x)) << MERLIN_SYNTH10_SPARE_LSB) & MERLIN_SYNTH10_SPARE_MASK)
#define MERLIN_SYNTH10_SPARE_RESET                                             0x0
#define MERLIN_SYNTH10_ADDRESS                                                 (0x6c + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH10_RSTMASK                                                 0xffffffff
#define MERLIN_SYNTH10_RESET                                                   0x812d4000

// 0x70 (MERLIN_SYNTH11)
#define MERLIN_SYNTH11_LOOP_CPA2_LSB                                           27
#define MERLIN_SYNTH11_LOOP_CPA2_MSB                                           31
#define MERLIN_SYNTH11_LOOP_CPA2_MASK                                          0xf8000000
#define MERLIN_SYNTH11_LOOP_CPA2_GET(x)                                        (((x) & MERLIN_SYNTH11_LOOP_CPA2_MASK) >> MERLIN_SYNTH11_LOOP_CPA2_LSB)
#define MERLIN_SYNTH11_LOOP_CPA2_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH11_LOOP_CPA2_LSB) & MERLIN_SYNTH11_LOOP_CPA2_MASK)
#define MERLIN_SYNTH11_LOOP_CPA2_RESET                                         0x10
#define MERLIN_SYNTH11_LOOP_RSA2_LSB                                           22
#define MERLIN_SYNTH11_LOOP_RSA2_MSB                                           26
#define MERLIN_SYNTH11_LOOP_RSA2_MASK                                          0x7c00000
#define MERLIN_SYNTH11_LOOP_RSA2_GET(x)                                        (((x) & MERLIN_SYNTH11_LOOP_RSA2_MASK) >> MERLIN_SYNTH11_LOOP_RSA2_LSB)
#define MERLIN_SYNTH11_LOOP_RSA2_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH11_LOOP_RSA2_LSB) & MERLIN_SYNTH11_LOOP_RSA2_MASK)
#define MERLIN_SYNTH11_LOOP_RSA2_RESET                                         0x4
#define MERLIN_SYNTH11_LOOP_CSA2_LSB                                           18
#define MERLIN_SYNTH11_LOOP_CSA2_MSB                                           21
#define MERLIN_SYNTH11_LOOP_CSA2_MASK                                          0x3c0000
#define MERLIN_SYNTH11_LOOP_CSA2_GET(x)                                        (((x) & MERLIN_SYNTH11_LOOP_CSA2_MASK) >> MERLIN_SYNTH11_LOOP_CSA2_LSB)
#define MERLIN_SYNTH11_LOOP_CSA2_SET(x)                                        (((0 | (x)) << MERLIN_SYNTH11_LOOP_CSA2_LSB) & MERLIN_SYNTH11_LOOP_CSA2_MASK)
#define MERLIN_SYNTH11_LOOP_CSA2_RESET                                         0xb
#define MERLIN_SYNTH11_LOOP_ICPA2_LSB                                          14
#define MERLIN_SYNTH11_LOOP_ICPA2_MSB                                          17
#define MERLIN_SYNTH11_LOOP_ICPA2_MASK                                         0x3c000
#define MERLIN_SYNTH11_LOOP_ICPA2_GET(x)                                       (((x) & MERLIN_SYNTH11_LOOP_ICPA2_MASK) >> MERLIN_SYNTH11_LOOP_ICPA2_LSB)
#define MERLIN_SYNTH11_LOOP_ICPA2_SET(x)                                       (((0 | (x)) << MERLIN_SYNTH11_LOOP_ICPA2_LSB) & MERLIN_SYNTH11_LOOP_ICPA2_MASK)
#define MERLIN_SYNTH11_LOOP_ICPA2_RESET                                        0xb
#define MERLIN_SYNTH11_SLOPE_ICPA2_LSB                                         11
#define MERLIN_SYNTH11_SLOPE_ICPA2_MSB                                         13
#define MERLIN_SYNTH11_SLOPE_ICPA2_MASK                                        0x3800
#define MERLIN_SYNTH11_SLOPE_ICPA2_GET(x)                                      (((x) & MERLIN_SYNTH11_SLOPE_ICPA2_MASK) >> MERLIN_SYNTH11_SLOPE_ICPA2_LSB)
#define MERLIN_SYNTH11_SLOPE_ICPA2_SET(x)                                      (((0 | (x)) << MERLIN_SYNTH11_SLOPE_ICPA2_LSB) & MERLIN_SYNTH11_SLOPE_ICPA2_MASK)
#define MERLIN_SYNTH11_SLOPE_ICPA2_RESET                                       0x0
#define MERLIN_SYNTH11_CPSTEERING_MODE_LSB                                     10
#define MERLIN_SYNTH11_CPSTEERING_MODE_MSB                                     10
#define MERLIN_SYNTH11_CPSTEERING_MODE_MASK                                    0x400
#define MERLIN_SYNTH11_CPSTEERING_MODE_GET(x)                                  (((x) & MERLIN_SYNTH11_CPSTEERING_MODE_MASK) >> MERLIN_SYNTH11_CPSTEERING_MODE_LSB)
#define MERLIN_SYNTH11_CPSTEERING_MODE_SET(x)                                  (((0 | (x)) << MERLIN_SYNTH11_CPSTEERING_MODE_LSB) & MERLIN_SYNTH11_CPSTEERING_MODE_MASK)
#define MERLIN_SYNTH11_CPSTEERING_MODE_RESET                                   0x1
#define MERLIN_SYNTH11_LO2GSEL_LSB                                             8
#define MERLIN_SYNTH11_LO2GSEL_MSB                                             9
#define MERLIN_SYNTH11_LO2GSEL_MASK                                            0x300
#define MERLIN_SYNTH11_LO2GSEL_GET(x)                                          (((x) & MERLIN_SYNTH11_LO2GSEL_MASK) >> MERLIN_SYNTH11_LO2GSEL_LSB)
#define MERLIN_SYNTH11_LO2GSEL_SET(x)                                          (((0 | (x)) << MERLIN_SYNTH11_LO2GSEL_LSB) & MERLIN_SYNTH11_LO2GSEL_MASK)
#define MERLIN_SYNTH11_LO2GSEL_RESET                                           0x0
#define MERLIN_SYNTH11_LOREFSEL_LSB                                            6
#define MERLIN_SYNTH11_LOREFSEL_MSB                                            7
#define MERLIN_SYNTH11_LOREFSEL_MASK                                           0xc0
#define MERLIN_SYNTH11_LOREFSEL_GET(x)                                         (((x) & MERLIN_SYNTH11_LOREFSEL_MASK) >> MERLIN_SYNTH11_LOREFSEL_LSB)
#define MERLIN_SYNTH11_LOREFSEL_SET(x)                                         (((0 | (x)) << MERLIN_SYNTH11_LOREFSEL_LSB) & MERLIN_SYNTH11_LOREFSEL_MASK)
#define MERLIN_SYNTH11_LOREFSEL_RESET                                          0x0
#define MERLIN_SYNTH11_FORCE_LOBUF5G_ON_LSB                                    5
#define MERLIN_SYNTH11_FORCE_LOBUF5G_ON_MSB                                    5
#define MERLIN_SYNTH11_FORCE_LOBUF5G_ON_MASK                                   0x20
#define MERLIN_SYNTH11_FORCE_LOBUF5G_ON_GET(x)                                 (((x) & MERLIN_SYNTH11_FORCE_LOBUF5G_ON_MASK) >> MERLIN_SYNTH11_FORCE_LOBUF5G_ON_LSB)
#define MERLIN_SYNTH11_FORCE_LOBUF5G_ON_SET(x)                                 (((0 | (x)) << MERLIN_SYNTH11_FORCE_LOBUF5G_ON_LSB) & MERLIN_SYNTH11_FORCE_LOBUF5G_ON_MASK)
#define MERLIN_SYNTH11_FORCE_LOBUF5G_ON_RESET                                  0x0
#define MERLIN_SYNTH11_SPARE_LSB                                               0
#define MERLIN_SYNTH11_SPARE_MSB                                               4
#define MERLIN_SYNTH11_SPARE_MASK                                              0x1f
#define MERLIN_SYNTH11_SPARE_GET(x)                                            (((x) & MERLIN_SYNTH11_SPARE_MASK) >> MERLIN_SYNTH11_SPARE_LSB)
#define MERLIN_SYNTH11_SPARE_SET(x)                                            (((0 | (x)) << MERLIN_SYNTH11_SPARE_LSB) & MERLIN_SYNTH11_SPARE_MASK)
#define MERLIN_SYNTH11_SPARE_RESET                                             0x0
#define MERLIN_SYNTH11_ADDRESS                                                 (0x70 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_SYNTH11_RSTMASK                                                 0xffffffff
#define MERLIN_SYNTH11_RESET                                                   0x812ec400

// 0x74 (MERLIN_BIAS1)
#define MERLIN_BIAS1_PADON_LSB                                                 31
#define MERLIN_BIAS1_PADON_MSB                                                 31
#define MERLIN_BIAS1_PADON_MASK                                                0x80000000
#define MERLIN_BIAS1_PADON_GET(x)                                              (((x) & MERLIN_BIAS1_PADON_MASK) >> MERLIN_BIAS1_PADON_LSB)
#define MERLIN_BIAS1_PADON_SET(x)                                              (((0 | (x)) << MERLIN_BIAS1_PADON_LSB) & MERLIN_BIAS1_PADON_MASK)
#define MERLIN_BIAS1_PADON_RESET                                               0x0
#define MERLIN_BIAS1_SEL_BIAS_LSB                                              25
#define MERLIN_BIAS1_SEL_BIAS_MSB                                              30
#define MERLIN_BIAS1_SEL_BIAS_MASK                                             0x7e000000
#define MERLIN_BIAS1_SEL_BIAS_GET(x)                                           (((x) & MERLIN_BIAS1_SEL_BIAS_MASK) >> MERLIN_BIAS1_SEL_BIAS_LSB)
#define MERLIN_BIAS1_SEL_BIAS_SET(x)                                           (((0 | (x)) << MERLIN_BIAS1_SEL_BIAS_LSB) & MERLIN_BIAS1_SEL_BIAS_MASK)
#define MERLIN_BIAS1_SEL_BIAS_RESET                                            0x0
#define MERLIN_BIAS1_BIAS1_SPARE_LSB                                           22
#define MERLIN_BIAS1_BIAS1_SPARE_MSB                                           24
#define MERLIN_BIAS1_BIAS1_SPARE_MASK                                          0x1c00000
#define MERLIN_BIAS1_BIAS1_SPARE_GET(x)                                        (((x) & MERLIN_BIAS1_BIAS1_SPARE_MASK) >> MERLIN_BIAS1_BIAS1_SPARE_LSB)
#define MERLIN_BIAS1_BIAS1_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_BIAS1_BIAS1_SPARE_LSB) & MERLIN_BIAS1_BIAS1_SPARE_MASK)
#define MERLIN_BIAS1_BIAS1_SPARE_RESET                                         0x0
#define MERLIN_BIAS1_PWD_ICXTAL25_LSB                                          19
#define MERLIN_BIAS1_PWD_ICXTAL25_MSB                                          21
#define MERLIN_BIAS1_PWD_ICXTAL25_MASK                                         0x380000
#define MERLIN_BIAS1_PWD_ICXTAL25_GET(x)                                       (((x) & MERLIN_BIAS1_PWD_ICXTAL25_MASK) >> MERLIN_BIAS1_PWD_ICXTAL25_LSB)
#define MERLIN_BIAS1_PWD_ICXTAL25_SET(x)                                       (((0 | (x)) << MERLIN_BIAS1_PWD_ICXTAL25_LSB) & MERLIN_BIAS1_PWD_ICXTAL25_MASK)
#define MERLIN_BIAS1_PWD_ICXTAL25_RESET                                        0x3
#define MERLIN_BIAS1_PWD_IRXTAL25_LSB                                          16
#define MERLIN_BIAS1_PWD_IRXTAL25_MSB                                          18
#define MERLIN_BIAS1_PWD_IRXTAL25_MASK                                         0x70000
#define MERLIN_BIAS1_PWD_IRXTAL25_GET(x)                                       (((x) & MERLIN_BIAS1_PWD_IRXTAL25_MASK) >> MERLIN_BIAS1_PWD_IRXTAL25_LSB)
#define MERLIN_BIAS1_PWD_IRXTAL25_SET(x)                                       (((0 | (x)) << MERLIN_BIAS1_PWD_IRXTAL25_LSB) & MERLIN_BIAS1_PWD_IRXTAL25_MASK)
#define MERLIN_BIAS1_PWD_IRXTAL25_RESET                                        0x3
#define MERLIN_BIAS1_PWD_ICXPALDO25_LSB                                        13
#define MERLIN_BIAS1_PWD_ICXPALDO25_MSB                                        15
#define MERLIN_BIAS1_PWD_ICXPALDO25_MASK                                       0xe000
#define MERLIN_BIAS1_PWD_ICXPALDO25_GET(x)                                     (((x) & MERLIN_BIAS1_PWD_ICXPALDO25_MASK) >> MERLIN_BIAS1_PWD_ICXPALDO25_LSB)
#define MERLIN_BIAS1_PWD_ICXPALDO25_SET(x)                                     (((0 | (x)) << MERLIN_BIAS1_PWD_ICXPALDO25_LSB) & MERLIN_BIAS1_PWD_ICXPALDO25_MASK)
#define MERLIN_BIAS1_PWD_ICXPALDO25_RESET                                      0x3
#define MERLIN_BIAS1_PWD_IRXPALDO25_LSB                                        10
#define MERLIN_BIAS1_PWD_IRXPALDO25_MSB                                        12
#define MERLIN_BIAS1_PWD_IRXPALDO25_MASK                                       0x1c00
#define MERLIN_BIAS1_PWD_IRXPALDO25_GET(x)                                     (((x) & MERLIN_BIAS1_PWD_IRXPALDO25_MASK) >> MERLIN_BIAS1_PWD_IRXPALDO25_LSB)
#define MERLIN_BIAS1_PWD_IRXPALDO25_SET(x)                                     (((0 | (x)) << MERLIN_BIAS1_PWD_IRXPALDO25_LSB) & MERLIN_BIAS1_PWD_IRXPALDO25_MASK)
#define MERLIN_BIAS1_PWD_IRXPALDO25_RESET                                      0x3
#define MERLIN_BIAS1_PWD_ICRXLDO25_LSB                                         7
#define MERLIN_BIAS1_PWD_ICRXLDO25_MSB                                         9
#define MERLIN_BIAS1_PWD_ICRXLDO25_MASK                                        0x380
#define MERLIN_BIAS1_PWD_ICRXLDO25_GET(x)                                      (((x) & MERLIN_BIAS1_PWD_ICRXLDO25_MASK) >> MERLIN_BIAS1_PWD_ICRXLDO25_LSB)
#define MERLIN_BIAS1_PWD_ICRXLDO25_SET(x)                                      (((0 | (x)) << MERLIN_BIAS1_PWD_ICRXLDO25_LSB) & MERLIN_BIAS1_PWD_ICRXLDO25_MASK)
#define MERLIN_BIAS1_PWD_ICRXLDO25_RESET                                       0x3
#define MERLIN_BIAS1_PWD_IRRXLDO25_LSB                                         4
#define MERLIN_BIAS1_PWD_IRRXLDO25_MSB                                         6
#define MERLIN_BIAS1_PWD_IRRXLDO25_MASK                                        0x70
#define MERLIN_BIAS1_PWD_IRRXLDO25_GET(x)                                      (((x) & MERLIN_BIAS1_PWD_IRRXLDO25_MASK) >> MERLIN_BIAS1_PWD_IRRXLDO25_LSB)
#define MERLIN_BIAS1_PWD_IRRXLDO25_SET(x)                                      (((0 | (x)) << MERLIN_BIAS1_PWD_IRRXLDO25_LSB) & MERLIN_BIAS1_PWD_IRRXLDO25_MASK)
#define MERLIN_BIAS1_PWD_IRRXLDO25_RESET                                       0x3
#define MERLIN_BIAS1_PWD_ICPLL25_LSB                                           3
#define MERLIN_BIAS1_PWD_ICPLL25_MSB                                           3
#define MERLIN_BIAS1_PWD_ICPLL25_MASK                                          0x8
#define MERLIN_BIAS1_PWD_ICPLL25_GET(x)                                        (((x) & MERLIN_BIAS1_PWD_ICPLL25_MASK) >> MERLIN_BIAS1_PWD_ICPLL25_LSB)
#define MERLIN_BIAS1_PWD_ICPLL25_SET(x)                                        (((0 | (x)) << MERLIN_BIAS1_PWD_ICPLL25_LSB) & MERLIN_BIAS1_PWD_ICPLL25_MASK)
#define MERLIN_BIAS1_PWD_ICPLL25_RESET                                         0x0
#define MERLIN_BIAS1_PWD_IRPLL25_LSB                                           2
#define MERLIN_BIAS1_PWD_IRPLL25_MSB                                           2
#define MERLIN_BIAS1_PWD_IRPLL25_MASK                                          0x4
#define MERLIN_BIAS1_PWD_IRPLL25_GET(x)                                        (((x) & MERLIN_BIAS1_PWD_IRPLL25_MASK) >> MERLIN_BIAS1_PWD_IRPLL25_LSB)
#define MERLIN_BIAS1_PWD_IRPLL25_SET(x)                                        (((0 | (x)) << MERLIN_BIAS1_PWD_IRPLL25_LSB) & MERLIN_BIAS1_PWD_IRPLL25_MASK)
#define MERLIN_BIAS1_PWD_IRPLL25_RESET                                         0x0
#define MERLIN_BIAS1_PWD_ICPCIE50_LSB                                          1
#define MERLIN_BIAS1_PWD_ICPCIE50_MSB                                          1
#define MERLIN_BIAS1_PWD_ICPCIE50_MASK                                         0x2
#define MERLIN_BIAS1_PWD_ICPCIE50_GET(x)                                       (((x) & MERLIN_BIAS1_PWD_ICPCIE50_MASK) >> MERLIN_BIAS1_PWD_ICPCIE50_LSB)
#define MERLIN_BIAS1_PWD_ICPCIE50_SET(x)                                       (((0 | (x)) << MERLIN_BIAS1_PWD_ICPCIE50_LSB) & MERLIN_BIAS1_PWD_ICPCIE50_MASK)
#define MERLIN_BIAS1_PWD_ICPCIE50_RESET                                        0x0
#define MERLIN_BIAS1_PWD_IRPCIE50_LSB                                          0
#define MERLIN_BIAS1_PWD_IRPCIE50_MSB                                          0
#define MERLIN_BIAS1_PWD_IRPCIE50_MASK                                         0x1
#define MERLIN_BIAS1_PWD_IRPCIE50_GET(x)                                       (((x) & MERLIN_BIAS1_PWD_IRPCIE50_MASK) >> MERLIN_BIAS1_PWD_IRPCIE50_LSB)
#define MERLIN_BIAS1_PWD_IRPCIE50_SET(x)                                       (((0 | (x)) << MERLIN_BIAS1_PWD_IRPCIE50_LSB) & MERLIN_BIAS1_PWD_IRPCIE50_MASK)
#define MERLIN_BIAS1_PWD_IRPCIE50_RESET                                        0x0
#define MERLIN_BIAS1_ADDRESS                                                   (0x74 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_BIAS1_RSTMASK                                                   0xffffffff
#define MERLIN_BIAS1_RESET                                                     0x1b6db0

// 0x78 (MERLIN_BIAS2)
#define MERLIN_BIAS2_PWD_ICSYNTH50_LSB                                         31
#define MERLIN_BIAS2_PWD_ICSYNTH50_MSB                                         31
#define MERLIN_BIAS2_PWD_ICSYNTH50_MASK                                        0x80000000
#define MERLIN_BIAS2_PWD_ICSYNTH50_GET(x)                                      (((x) & MERLIN_BIAS2_PWD_ICSYNTH50_MASK) >> MERLIN_BIAS2_PWD_ICSYNTH50_LSB)
#define MERLIN_BIAS2_PWD_ICSYNTH50_SET(x)                                      (((0 | (x)) << MERLIN_BIAS2_PWD_ICSYNTH50_LSB) & MERLIN_BIAS2_PWD_ICSYNTH50_MASK)
#define MERLIN_BIAS2_PWD_ICSYNTH50_RESET                                       0x0
#define MERLIN_BIAS2_PWD_IRSYNTH50_LSB                                         30
#define MERLIN_BIAS2_PWD_IRSYNTH50_MSB                                         30
#define MERLIN_BIAS2_PWD_IRSYNTH50_MASK                                        0x40000000
#define MERLIN_BIAS2_PWD_IRSYNTH50_GET(x)                                      (((x) & MERLIN_BIAS2_PWD_IRSYNTH50_MASK) >> MERLIN_BIAS2_PWD_IRSYNTH50_LSB)
#define MERLIN_BIAS2_PWD_IRSYNTH50_SET(x)                                      (((0 | (x)) << MERLIN_BIAS2_PWD_IRSYNTH50_LSB) & MERLIN_BIAS2_PWD_IRSYNTH50_MASK)
#define MERLIN_BIAS2_PWD_IRSYNTH50_RESET                                       0x0
#define MERLIN_BIAS2_PWD_ICRF5G50_LSB                                          29
#define MERLIN_BIAS2_PWD_ICRF5G50_MSB                                          29
#define MERLIN_BIAS2_PWD_ICRF5G50_MASK                                         0x20000000
#define MERLIN_BIAS2_PWD_ICRF5G50_GET(x)                                       (((x) & MERLIN_BIAS2_PWD_ICRF5G50_MASK) >> MERLIN_BIAS2_PWD_ICRF5G50_LSB)
#define MERLIN_BIAS2_PWD_ICRF5G50_SET(x)                                       (((0 | (x)) << MERLIN_BIAS2_PWD_ICRF5G50_LSB) & MERLIN_BIAS2_PWD_ICRF5G50_MASK)
#define MERLIN_BIAS2_PWD_ICRF5G50_RESET                                        0x0
#define MERLIN_BIAS2_PWD_ICRF2G50_LSB                                          28
#define MERLIN_BIAS2_PWD_ICRF2G50_MSB                                          28
#define MERLIN_BIAS2_PWD_ICRF2G50_MASK                                         0x10000000
#define MERLIN_BIAS2_PWD_ICRF2G50_GET(x)                                       (((x) & MERLIN_BIAS2_PWD_ICRF2G50_MASK) >> MERLIN_BIAS2_PWD_ICRF2G50_LSB)
#define MERLIN_BIAS2_PWD_ICRF2G50_SET(x)                                       (((0 | (x)) << MERLIN_BIAS2_PWD_ICRF2G50_LSB) & MERLIN_BIAS2_PWD_ICRF2G50_MASK)
#define MERLIN_BIAS2_PWD_ICRF2G50_RESET                                        0x0
#define MERLIN_BIAS2_PWD_IRRF5G50_LSB                                          27
#define MERLIN_BIAS2_PWD_IRRF5G50_MSB                                          27
#define MERLIN_BIAS2_PWD_IRRF5G50_MASK                                         0x8000000
#define MERLIN_BIAS2_PWD_IRRF5G50_GET(x)                                       (((x) & MERLIN_BIAS2_PWD_IRRF5G50_MASK) >> MERLIN_BIAS2_PWD_IRRF5G50_LSB)
#define MERLIN_BIAS2_PWD_IRRF5G50_SET(x)                                       (((0 | (x)) << MERLIN_BIAS2_PWD_IRRF5G50_LSB) & MERLIN_BIAS2_PWD_IRRF5G50_MASK)
#define MERLIN_BIAS2_PWD_IRRF5G50_RESET                                        0x0
#define MERLIN_BIAS2_PWD_IRRF2G50_LSB                                          26
#define MERLIN_BIAS2_PWD_IRRF2G50_MSB                                          26
#define MERLIN_BIAS2_PWD_IRRF2G50_MASK                                         0x4000000
#define MERLIN_BIAS2_PWD_IRRF2G50_GET(x)                                       (((x) & MERLIN_BIAS2_PWD_IRRF2G50_MASK) >> MERLIN_BIAS2_PWD_IRRF2G50_LSB)
#define MERLIN_BIAS2_PWD_IRRF2G50_SET(x)                                       (((0 | (x)) << MERLIN_BIAS2_PWD_IRRF2G50_LSB) & MERLIN_BIAS2_PWD_IRRF2G50_MASK)
#define MERLIN_BIAS2_PWD_IRRF2G50_RESET                                        0x0
#define MERLIN_BIAS2_PWD_ICBB50_LSB                                            25
#define MERLIN_BIAS2_PWD_ICBB50_MSB                                            25
#define MERLIN_BIAS2_PWD_ICBB50_MASK                                           0x2000000
#define MERLIN_BIAS2_PWD_ICBB50_GET(x)                                         (((x) & MERLIN_BIAS2_PWD_ICBB50_MASK) >> MERLIN_BIAS2_PWD_ICBB50_LSB)
#define MERLIN_BIAS2_PWD_ICBB50_SET(x)                                         (((0 | (x)) << MERLIN_BIAS2_PWD_ICBB50_LSB) & MERLIN_BIAS2_PWD_ICBB50_MASK)
#define MERLIN_BIAS2_PWD_ICBB50_RESET                                          0x0
#define MERLIN_BIAS2_PWD_IRBB50_LSB                                            24
#define MERLIN_BIAS2_PWD_IRBB50_MSB                                            24
#define MERLIN_BIAS2_PWD_IRBB50_MASK                                           0x1000000
#define MERLIN_BIAS2_PWD_IRBB50_GET(x)                                         (((x) & MERLIN_BIAS2_PWD_IRBB50_MASK) >> MERLIN_BIAS2_PWD_IRBB50_LSB)
#define MERLIN_BIAS2_PWD_IRBB50_SET(x)                                         (((0 | (x)) << MERLIN_BIAS2_PWD_IRBB50_LSB) & MERLIN_BIAS2_PWD_IRBB50_MASK)
#define MERLIN_BIAS2_PWD_IRBB50_RESET                                          0x0
#define MERLIN_BIAS2_PWD_ICDACINTFACE25_LSB                                    23
#define MERLIN_BIAS2_PWD_ICDACINTFACE25_MSB                                    23
#define MERLIN_BIAS2_PWD_ICDACINTFACE25_MASK                                   0x800000
#define MERLIN_BIAS2_PWD_ICDACINTFACE25_GET(x)                                 (((x) & MERLIN_BIAS2_PWD_ICDACINTFACE25_MASK) >> MERLIN_BIAS2_PWD_ICDACINTFACE25_LSB)
#define MERLIN_BIAS2_PWD_ICDACINTFACE25_SET(x)                                 (((0 | (x)) << MERLIN_BIAS2_PWD_ICDACINTFACE25_LSB) & MERLIN_BIAS2_PWD_ICDACINTFACE25_MASK)
#define MERLIN_BIAS2_PWD_ICDACINTFACE25_RESET                                  0x0
#define MERLIN_BIAS2_PWD_ICADCCOMPI25_LSB                                      20
#define MERLIN_BIAS2_PWD_ICADCCOMPI25_MSB                                      22
#define MERLIN_BIAS2_PWD_ICADCCOMPI25_MASK                                     0x700000
#define MERLIN_BIAS2_PWD_ICADCCOMPI25_GET(x)                                   (((x) & MERLIN_BIAS2_PWD_ICADCCOMPI25_MASK) >> MERLIN_BIAS2_PWD_ICADCCOMPI25_LSB)
#define MERLIN_BIAS2_PWD_ICADCCOMPI25_SET(x)                                   (((0 | (x)) << MERLIN_BIAS2_PWD_ICADCCOMPI25_LSB) & MERLIN_BIAS2_PWD_ICADCCOMPI25_MASK)
#define MERLIN_BIAS2_PWD_ICADCCOMPI25_RESET                                    0x3
#define MERLIN_BIAS2_PWD_ICADCCOMPQ25_LSB                                      17
#define MERLIN_BIAS2_PWD_ICADCCOMPQ25_MSB                                      19
#define MERLIN_BIAS2_PWD_ICADCCOMPQ25_MASK                                     0xe0000
#define MERLIN_BIAS2_PWD_ICADCCOMPQ25_GET(x)                                   (((x) & MERLIN_BIAS2_PWD_ICADCCOMPQ25_MASK) >> MERLIN_BIAS2_PWD_ICADCCOMPQ25_LSB)
#define MERLIN_BIAS2_PWD_ICADCCOMPQ25_SET(x)                                   (((0 | (x)) << MERLIN_BIAS2_PWD_ICADCCOMPQ25_LSB) & MERLIN_BIAS2_PWD_ICADCCOMPQ25_MASK)
#define MERLIN_BIAS2_PWD_ICADCCOMPQ25_RESET                                    0x3
#define MERLIN_BIAS2_PWD_ICADCREFBUFI12P5_LSB                                  14
#define MERLIN_BIAS2_PWD_ICADCREFBUFI12P5_MSB                                  16
#define MERLIN_BIAS2_PWD_ICADCREFBUFI12P5_MASK                                 0x1c000
#define MERLIN_BIAS2_PWD_ICADCREFBUFI12P5_GET(x)                               (((x) & MERLIN_BIAS2_PWD_ICADCREFBUFI12P5_MASK) >> MERLIN_BIAS2_PWD_ICADCREFBUFI12P5_LSB)
#define MERLIN_BIAS2_PWD_ICADCREFBUFI12P5_SET(x)                               (((0 | (x)) << MERLIN_BIAS2_PWD_ICADCREFBUFI12P5_LSB) & MERLIN_BIAS2_PWD_ICADCREFBUFI12P5_MASK)
#define MERLIN_BIAS2_PWD_ICADCREFBUFI12P5_RESET                                0x5
#define MERLIN_BIAS2_PWD_ICADCREFBUFQ12P5_LSB                                  11
#define MERLIN_BIAS2_PWD_ICADCREFBUFQ12P5_MSB                                  13
#define MERLIN_BIAS2_PWD_ICADCREFBUFQ12P5_MASK                                 0x3800
#define MERLIN_BIAS2_PWD_ICADCREFBUFQ12P5_GET(x)                               (((x) & MERLIN_BIAS2_PWD_ICADCREFBUFQ12P5_MASK) >> MERLIN_BIAS2_PWD_ICADCREFBUFQ12P5_LSB)
#define MERLIN_BIAS2_PWD_ICADCREFBUFQ12P5_SET(x)                               (((0 | (x)) << MERLIN_BIAS2_PWD_ICADCREFBUFQ12P5_LSB) & MERLIN_BIAS2_PWD_ICADCREFBUFQ12P5_MASK)
#define MERLIN_BIAS2_PWD_ICADCREFBUFQ12P5_RESET                                0x5
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPI25_LSB                                  8
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPI25_MSB                                  10
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPI25_MASK                                 0x700
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPI25_GET(x)                               (((x) & MERLIN_BIAS2_PWD_ICADCREFOPAMPI25_MASK) >> MERLIN_BIAS2_PWD_ICADCREFOPAMPI25_LSB)
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPI25_SET(x)                               (((0 | (x)) << MERLIN_BIAS2_PWD_ICADCREFOPAMPI25_LSB) & MERLIN_BIAS2_PWD_ICADCREFOPAMPI25_MASK)
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPI25_RESET                                0x3
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPQ25_LSB                                  5
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPQ25_MSB                                  7
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPQ25_MASK                                 0xe0
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPQ25_GET(x)                               (((x) & MERLIN_BIAS2_PWD_ICADCREFOPAMPQ25_MASK) >> MERLIN_BIAS2_PWD_ICADCREFOPAMPQ25_LSB)
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPQ25_SET(x)                               (((0 | (x)) << MERLIN_BIAS2_PWD_ICADCREFOPAMPQ25_LSB) & MERLIN_BIAS2_PWD_ICADCREFOPAMPQ25_MASK)
#define MERLIN_BIAS2_PWD_ICADCREFOPAMPQ25_RESET                                0x3
#define MERLIN_BIAS2_PWD_IRADCREFMSTRI12P5_LSB                                 4
#define MERLIN_BIAS2_PWD_IRADCREFMSTRI12P5_MSB                                 4
#define MERLIN_BIAS2_PWD_IRADCREFMSTRI12P5_MASK                                0x10
#define MERLIN_BIAS2_PWD_IRADCREFMSTRI12P5_GET(x)                              (((x) & MERLIN_BIAS2_PWD_IRADCREFMSTRI12P5_MASK) >> MERLIN_BIAS2_PWD_IRADCREFMSTRI12P5_LSB)
#define MERLIN_BIAS2_PWD_IRADCREFMSTRI12P5_SET(x)                              (((0 | (x)) << MERLIN_BIAS2_PWD_IRADCREFMSTRI12P5_LSB) & MERLIN_BIAS2_PWD_IRADCREFMSTRI12P5_MASK)
#define MERLIN_BIAS2_PWD_IRADCREFMSTRI12P5_RESET                               0x0
#define MERLIN_BIAS2_PWD_IRADCREFMSTRQ12P5_LSB                                 3
#define MERLIN_BIAS2_PWD_IRADCREFMSTRQ12P5_MSB                                 3
#define MERLIN_BIAS2_PWD_IRADCREFMSTRQ12P5_MASK                                0x8
#define MERLIN_BIAS2_PWD_IRADCREFMSTRQ12P5_GET(x)                              (((x) & MERLIN_BIAS2_PWD_IRADCREFMSTRQ12P5_MASK) >> MERLIN_BIAS2_PWD_IRADCREFMSTRQ12P5_LSB)
#define MERLIN_BIAS2_PWD_IRADCREFMSTRQ12P5_SET(x)                              (((0 | (x)) << MERLIN_BIAS2_PWD_IRADCREFMSTRQ12P5_LSB) & MERLIN_BIAS2_PWD_IRADCREFMSTRQ12P5_MASK)
#define MERLIN_BIAS2_PWD_IRADCREFMSTRQ12P5_RESET                               0x0
#define MERLIN_BIAS2_PWD_ICDAC50_LSB                                           0
#define MERLIN_BIAS2_PWD_ICDAC50_MSB                                           2
#define MERLIN_BIAS2_PWD_ICDAC50_MASK                                          0x7
#define MERLIN_BIAS2_PWD_ICDAC50_GET(x)                                        (((x) & MERLIN_BIAS2_PWD_ICDAC50_MASK) >> MERLIN_BIAS2_PWD_ICDAC50_LSB)
#define MERLIN_BIAS2_PWD_ICDAC50_SET(x)                                        (((0 | (x)) << MERLIN_BIAS2_PWD_ICDAC50_LSB) & MERLIN_BIAS2_PWD_ICDAC50_MASK)
#define MERLIN_BIAS2_PWD_ICDAC50_RESET                                         0x3
#define MERLIN_BIAS2_ADDRESS                                                   (0x78 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_BIAS2_RSTMASK                                                   0xffffffff
#define MERLIN_BIAS2_RESET                                                     0x376b63

// 0x7c (MERLIN_BIAS3)
#define MERLIN_BIAS3_PWD_ICTXPC25_LSB                                          31
#define MERLIN_BIAS3_PWD_ICTXPC25_MSB                                          31
#define MERLIN_BIAS3_PWD_ICTXPC25_MASK                                         0x80000000
#define MERLIN_BIAS3_PWD_ICTXPC25_GET(x)                                       (((x) & MERLIN_BIAS3_PWD_ICTXPC25_MASK) >> MERLIN_BIAS3_PWD_ICTXPC25_LSB)
#define MERLIN_BIAS3_PWD_ICTXPC25_SET(x)                                       (((0 | (x)) << MERLIN_BIAS3_PWD_ICTXPC25_LSB) & MERLIN_BIAS3_PWD_ICTXPC25_MASK)
#define MERLIN_BIAS3_PWD_ICTXPC25_RESET                                        0x0
#define MERLIN_BIAS3_PWD_IRTXPC25_LSB                                          30
#define MERLIN_BIAS3_PWD_IRTXPC25_MSB                                          30
#define MERLIN_BIAS3_PWD_IRTXPC25_MASK                                         0x40000000
#define MERLIN_BIAS3_PWD_IRTXPC25_GET(x)                                       (((x) & MERLIN_BIAS3_PWD_IRTXPC25_MASK) >> MERLIN_BIAS3_PWD_IRTXPC25_LSB)
#define MERLIN_BIAS3_PWD_IRTXPC25_SET(x)                                       (((0 | (x)) << MERLIN_BIAS3_PWD_IRTXPC25_LSB) & MERLIN_BIAS3_PWD_IRTXPC25_MASK)
#define MERLIN_BIAS3_PWD_IRTXPC25_RESET                                        0x0
#define MERLIN_BIAS3_PWD_ICTSENS25_LSB                                         29
#define MERLIN_BIAS3_PWD_ICTSENS25_MSB                                         29
#define MERLIN_BIAS3_PWD_ICTSENS25_MASK                                        0x20000000
#define MERLIN_BIAS3_PWD_ICTSENS25_GET(x)                                      (((x) & MERLIN_BIAS3_PWD_ICTSENS25_MASK) >> MERLIN_BIAS3_PWD_ICTSENS25_LSB)
#define MERLIN_BIAS3_PWD_ICTSENS25_SET(x)                                      (((0 | (x)) << MERLIN_BIAS3_PWD_ICTSENS25_LSB) & MERLIN_BIAS3_PWD_ICTSENS25_MASK)
#define MERLIN_BIAS3_PWD_ICTSENS25_RESET                                       0x0
#define MERLIN_BIAS3_PWD_IRTSENS25_LSB                                         28
#define MERLIN_BIAS3_PWD_IRTSENS25_MSB                                         28
#define MERLIN_BIAS3_PWD_IRTSENS25_MASK                                        0x10000000
#define MERLIN_BIAS3_PWD_IRTSENS25_GET(x)                                      (((x) & MERLIN_BIAS3_PWD_IRTSENS25_MASK) >> MERLIN_BIAS3_PWD_IRTSENS25_LSB)
#define MERLIN_BIAS3_PWD_IRTSENS25_SET(x)                                      (((0 | (x)) << MERLIN_BIAS3_PWD_IRTSENS25_LSB) & MERLIN_BIAS3_PWD_IRTSENS25_MASK)
#define MERLIN_BIAS3_PWD_IRTSENS25_RESET                                       0x0
#define MERLIN_BIAS3_PWD_IC25SPARE1_LSB                                        25
#define MERLIN_BIAS3_PWD_IC25SPARE1_MSB                                        27
#define MERLIN_BIAS3_PWD_IC25SPARE1_MASK                                       0xe000000
#define MERLIN_BIAS3_PWD_IC25SPARE1_GET(x)                                     (((x) & MERLIN_BIAS3_PWD_IC25SPARE1_MASK) >> MERLIN_BIAS3_PWD_IC25SPARE1_LSB)
#define MERLIN_BIAS3_PWD_IC25SPARE1_SET(x)                                     (((0 | (x)) << MERLIN_BIAS3_PWD_IC25SPARE1_LSB) & MERLIN_BIAS3_PWD_IC25SPARE1_MASK)
#define MERLIN_BIAS3_PWD_IC25SPARE1_RESET                                      0x3
#define MERLIN_BIAS3_PWD_IC25SPARE2_LSB                                        22
#define MERLIN_BIAS3_PWD_IC25SPARE2_MSB                                        24
#define MERLIN_BIAS3_PWD_IC25SPARE2_MASK                                       0x1c00000
#define MERLIN_BIAS3_PWD_IC25SPARE2_GET(x)                                     (((x) & MERLIN_BIAS3_PWD_IC25SPARE2_MASK) >> MERLIN_BIAS3_PWD_IC25SPARE2_LSB)
#define MERLIN_BIAS3_PWD_IC25SPARE2_SET(x)                                     (((0 | (x)) << MERLIN_BIAS3_PWD_IC25SPARE2_LSB) & MERLIN_BIAS3_PWD_IC25SPARE2_MASK)
#define MERLIN_BIAS3_PWD_IC25SPARE2_RESET                                      0x3
#define MERLIN_BIAS3_PWD_IC25SPARE3_LSB                                        19
#define MERLIN_BIAS3_PWD_IC25SPARE3_MSB                                        21
#define MERLIN_BIAS3_PWD_IC25SPARE3_MASK                                       0x380000
#define MERLIN_BIAS3_PWD_IC25SPARE3_GET(x)                                     (((x) & MERLIN_BIAS3_PWD_IC25SPARE3_MASK) >> MERLIN_BIAS3_PWD_IC25SPARE3_LSB)
#define MERLIN_BIAS3_PWD_IC25SPARE3_SET(x)                                     (((0 | (x)) << MERLIN_BIAS3_PWD_IC25SPARE3_LSB) & MERLIN_BIAS3_PWD_IC25SPARE3_MASK)
#define MERLIN_BIAS3_PWD_IC25SPARE3_RESET                                      0x3
#define MERLIN_BIAS3_PWD_IC25SPARE4_LSB                                        16
#define MERLIN_BIAS3_PWD_IC25SPARE4_MSB                                        18
#define MERLIN_BIAS3_PWD_IC25SPARE4_MASK                                       0x70000
#define MERLIN_BIAS3_PWD_IC25SPARE4_GET(x)                                     (((x) & MERLIN_BIAS3_PWD_IC25SPARE4_MASK) >> MERLIN_BIAS3_PWD_IC25SPARE4_LSB)
#define MERLIN_BIAS3_PWD_IC25SPARE4_SET(x)                                     (((0 | (x)) << MERLIN_BIAS3_PWD_IC25SPARE4_LSB) & MERLIN_BIAS3_PWD_IC25SPARE4_MASK)
#define MERLIN_BIAS3_PWD_IC25SPARE4_RESET                                      0x3
#define MERLIN_BIAS3_PWD_IR25SPARE1_LSB                                        13
#define MERLIN_BIAS3_PWD_IR25SPARE1_MSB                                        15
#define MERLIN_BIAS3_PWD_IR25SPARE1_MASK                                       0xe000
#define MERLIN_BIAS3_PWD_IR25SPARE1_GET(x)                                     (((x) & MERLIN_BIAS3_PWD_IR25SPARE1_MASK) >> MERLIN_BIAS3_PWD_IR25SPARE1_LSB)
#define MERLIN_BIAS3_PWD_IR25SPARE1_SET(x)                                     (((0 | (x)) << MERLIN_BIAS3_PWD_IR25SPARE1_LSB) & MERLIN_BIAS3_PWD_IR25SPARE1_MASK)
#define MERLIN_BIAS3_PWD_IR25SPARE1_RESET                                      0x3
#define MERLIN_BIAS3_PWD_IR25SPARE2_LSB                                        10
#define MERLIN_BIAS3_PWD_IR25SPARE2_MSB                                        12
#define MERLIN_BIAS3_PWD_IR25SPARE2_MASK                                       0x1c00
#define MERLIN_BIAS3_PWD_IR25SPARE2_GET(x)                                     (((x) & MERLIN_BIAS3_PWD_IR25SPARE2_MASK) >> MERLIN_BIAS3_PWD_IR25SPARE2_LSB)
#define MERLIN_BIAS3_PWD_IR25SPARE2_SET(x)                                     (((0 | (x)) << MERLIN_BIAS3_PWD_IR25SPARE2_LSB) & MERLIN_BIAS3_PWD_IR25SPARE2_MASK)
#define MERLIN_BIAS3_PWD_IR25SPARE2_RESET                                      0x3
#define MERLIN_BIAS3_PWD_IR25SPARE3_LSB                                        7
#define MERLIN_BIAS3_PWD_IR25SPARE3_MSB                                        9
#define MERLIN_BIAS3_PWD_IR25SPARE3_MASK                                       0x380
#define MERLIN_BIAS3_PWD_IR25SPARE3_GET(x)                                     (((x) & MERLIN_BIAS3_PWD_IR25SPARE3_MASK) >> MERLIN_BIAS3_PWD_IR25SPARE3_LSB)
#define MERLIN_BIAS3_PWD_IR25SPARE3_SET(x)                                     (((0 | (x)) << MERLIN_BIAS3_PWD_IR25SPARE3_LSB) & MERLIN_BIAS3_PWD_IR25SPARE3_MASK)
#define MERLIN_BIAS3_PWD_IR25SPARE3_RESET                                      0x3
#define MERLIN_BIAS3_PWD_IR25SPARE4_LSB                                        4
#define MERLIN_BIAS3_PWD_IR25SPARE4_MSB                                        6
#define MERLIN_BIAS3_PWD_IR25SPARE4_MASK                                       0x70
#define MERLIN_BIAS3_PWD_IR25SPARE4_GET(x)                                     (((x) & MERLIN_BIAS3_PWD_IR25SPARE4_MASK) >> MERLIN_BIAS3_PWD_IR25SPARE4_LSB)
#define MERLIN_BIAS3_PWD_IR25SPARE4_SET(x)                                     (((0 | (x)) << MERLIN_BIAS3_PWD_IR25SPARE4_LSB) & MERLIN_BIAS3_PWD_IR25SPARE4_MASK)
#define MERLIN_BIAS3_PWD_IR25SPARE4_RESET                                      0x3
#define MERLIN_BIAS3_PWD_ICLOLDO25_LSB                                         1
#define MERLIN_BIAS3_PWD_ICLOLDO25_MSB                                         3
#define MERLIN_BIAS3_PWD_ICLOLDO25_MASK                                        0xe
#define MERLIN_BIAS3_PWD_ICLOLDO25_GET(x)                                      (((x) & MERLIN_BIAS3_PWD_ICLOLDO25_MASK) >> MERLIN_BIAS3_PWD_ICLOLDO25_LSB)
#define MERLIN_BIAS3_PWD_ICLOLDO25_SET(x)                                      (((0 | (x)) << MERLIN_BIAS3_PWD_ICLOLDO25_LSB) & MERLIN_BIAS3_PWD_ICLOLDO25_MASK)
#define MERLIN_BIAS3_PWD_ICLOLDO25_RESET                                       0x3
#define MERLIN_BIAS3_BIAS3_SPARE_LSB                                           0
#define MERLIN_BIAS3_BIAS3_SPARE_MSB                                           0
#define MERLIN_BIAS3_BIAS3_SPARE_MASK                                          0x1
#define MERLIN_BIAS3_BIAS3_SPARE_GET(x)                                        (((x) & MERLIN_BIAS3_BIAS3_SPARE_MASK) >> MERLIN_BIAS3_BIAS3_SPARE_LSB)
#define MERLIN_BIAS3_BIAS3_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_BIAS3_BIAS3_SPARE_LSB) & MERLIN_BIAS3_BIAS3_SPARE_MASK)
#define MERLIN_BIAS3_BIAS3_SPARE_RESET                                         0x0
#define MERLIN_BIAS3_ADDRESS                                                   (0x7c + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_BIAS3_RSTMASK                                                   0xffffffff
#define MERLIN_BIAS3_RESET                                                     0x6db6db6

// 0x80 (MERLIN_BIAS4)
#define MERLIN_BIAS4_BIAS4_SEL_SPARE_LSB                                       24
#define MERLIN_BIAS4_BIAS4_SEL_SPARE_MSB                                       31
#define MERLIN_BIAS4_BIAS4_SEL_SPARE_MASK                                      0xff000000
#define MERLIN_BIAS4_BIAS4_SEL_SPARE_GET(x)                                    (((x) & MERLIN_BIAS4_BIAS4_SEL_SPARE_MASK) >> MERLIN_BIAS4_BIAS4_SEL_SPARE_LSB)
#define MERLIN_BIAS4_BIAS4_SEL_SPARE_SET(x)                                    (((0 | (x)) << MERLIN_BIAS4_BIAS4_SEL_SPARE_LSB) & MERLIN_BIAS4_BIAS4_SEL_SPARE_MASK)
#define MERLIN_BIAS4_BIAS4_SEL_SPARE_RESET                                     0x0
#define MERLIN_BIAS4_PWD_ICXLNA2G50_LSB                                        21
#define MERLIN_BIAS4_PWD_ICXLNA2G50_MSB                                        23
#define MERLIN_BIAS4_PWD_ICXLNA2G50_MASK                                       0xe00000
#define MERLIN_BIAS4_PWD_ICXLNA2G50_GET(x)                                     (((x) & MERLIN_BIAS4_PWD_ICXLNA2G50_MASK) >> MERLIN_BIAS4_PWD_ICXLNA2G50_LSB)
#define MERLIN_BIAS4_PWD_ICXLNA2G50_SET(x)                                     (((0 | (x)) << MERLIN_BIAS4_PWD_ICXLNA2G50_LSB) & MERLIN_BIAS4_PWD_ICXLNA2G50_MASK)
#define MERLIN_BIAS4_PWD_ICXLNA2G50_RESET                                      0x3
#define MERLIN_BIAS4_PWD_ICXLNA5G50_LSB                                        18
#define MERLIN_BIAS4_PWD_ICXLNA5G50_MSB                                        20
#define MERLIN_BIAS4_PWD_ICXLNA5G50_MASK                                       0x1c0000
#define MERLIN_BIAS4_PWD_ICXLNA5G50_GET(x)                                     (((x) & MERLIN_BIAS4_PWD_ICXLNA5G50_MASK) >> MERLIN_BIAS4_PWD_ICXLNA5G50_LSB)
#define MERLIN_BIAS4_PWD_ICXLNA5G50_SET(x)                                     (((0 | (x)) << MERLIN_BIAS4_PWD_ICXLNA5G50_LSB) & MERLIN_BIAS4_PWD_ICXLNA5G50_MASK)
#define MERLIN_BIAS4_PWD_ICXLNA5G50_RESET                                      0x3
#define MERLIN_BIAS4_PWD_IRLOLDO25_LSB                                         15
#define MERLIN_BIAS4_PWD_IRLOLDO25_MSB                                         17
#define MERLIN_BIAS4_PWD_IRLOLDO25_MASK                                        0x38000
#define MERLIN_BIAS4_PWD_IRLOLDO25_GET(x)                                      (((x) & MERLIN_BIAS4_PWD_IRLOLDO25_MASK) >> MERLIN_BIAS4_PWD_IRLOLDO25_LSB)
#define MERLIN_BIAS4_PWD_IRLOLDO25_SET(x)                                      (((0 | (x)) << MERLIN_BIAS4_PWD_IRLOLDO25_LSB) & MERLIN_BIAS4_PWD_IRLOLDO25_MASK)
#define MERLIN_BIAS4_PWD_IRLOLDO25_RESET                                       0x3
#define MERLIN_BIAS4_BIAS4_SPARE_LSB                                           0
#define MERLIN_BIAS4_BIAS4_SPARE_MSB                                           14
#define MERLIN_BIAS4_BIAS4_SPARE_MASK                                          0x7fff
#define MERLIN_BIAS4_BIAS4_SPARE_GET(x)                                        (((x) & MERLIN_BIAS4_BIAS4_SPARE_MASK) >> MERLIN_BIAS4_BIAS4_SPARE_LSB)
#define MERLIN_BIAS4_BIAS4_SPARE_SET(x)                                        (((0 | (x)) << MERLIN_BIAS4_BIAS4_SPARE_LSB) & MERLIN_BIAS4_BIAS4_SPARE_MASK)
#define MERLIN_BIAS4_BIAS4_SPARE_RESET                                         0x0
#define MERLIN_BIAS4_ADDRESS                                                   (0x80 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_BIAS4_RSTMASK                                                   0xffffffff
#define MERLIN_BIAS4_RESET                                                     0x6d8000

// 0x84 (MERLIN_GAIN0)
#define MERLIN_GAIN0_TX6DBLOQGAIN_LSB                                          30
#define MERLIN_GAIN0_TX6DBLOQGAIN_MSB                                          31
#define MERLIN_GAIN0_TX6DBLOQGAIN_MASK                                         0xc0000000
#define MERLIN_GAIN0_TX6DBLOQGAIN_GET(x)                                       (((x) & MERLIN_GAIN0_TX6DBLOQGAIN_MASK) >> MERLIN_GAIN0_TX6DBLOQGAIN_LSB)
#define MERLIN_GAIN0_TX6DBLOQGAIN_SET(x)                                       (((0 | (x)) << MERLIN_GAIN0_TX6DBLOQGAIN_LSB) & MERLIN_GAIN0_TX6DBLOQGAIN_MASK)
#define MERLIN_GAIN0_TX6DBLOQGAIN_RESET                                        0x3
#define MERLIN_GAIN0_TX1DBLOQGAIN_LSB                                          27
#define MERLIN_GAIN0_TX1DBLOQGAIN_MSB                                          29
#define MERLIN_GAIN0_TX1DBLOQGAIN_MASK                                         0x38000000
#define MERLIN_GAIN0_TX1DBLOQGAIN_GET(x)                                       (((x) & MERLIN_GAIN0_TX1DBLOQGAIN_MASK) >> MERLIN_GAIN0_TX1DBLOQGAIN_LSB)
#define MERLIN_GAIN0_TX1DBLOQGAIN_SET(x)                                       (((0 | (x)) << MERLIN_GAIN0_TX1DBLOQGAIN_LSB) & MERLIN_GAIN0_TX1DBLOQGAIN_MASK)
#define MERLIN_GAIN0_TX1DBLOQGAIN_RESET                                        0x6
#define MERLIN_GAIN0_TXV2IGAIN_LSB                                             25
#define MERLIN_GAIN0_TXV2IGAIN_MSB                                             26
#define MERLIN_GAIN0_TXV2IGAIN_MASK                                            0x6000000
#define MERLIN_GAIN0_TXV2IGAIN_GET(x)                                          (((x) & MERLIN_GAIN0_TXV2IGAIN_MASK) >> MERLIN_GAIN0_TXV2IGAIN_LSB)
#define MERLIN_GAIN0_TXV2IGAIN_SET(x)                                          (((0 | (x)) << MERLIN_GAIN0_TXV2IGAIN_LSB) & MERLIN_GAIN0_TXV2IGAIN_MASK)
#define MERLIN_GAIN0_TXV2IGAIN_RESET                                           0x3
#define MERLIN_GAIN0_PABUF5GN_LSB                                              24
#define MERLIN_GAIN0_PABUF5GN_MSB                                              24
#define MERLIN_GAIN0_PABUF5GN_MASK                                             0x1000000
#define MERLIN_GAIN0_PABUF5GN_GET(x)                                           (((x) & MERLIN_GAIN0_PABUF5GN_MASK) >> MERLIN_GAIN0_PABUF5GN_LSB)
#define MERLIN_GAIN0_PABUF5GN_SET(x)                                           (((0 | (x)) << MERLIN_GAIN0_PABUF5GN_LSB) & MERLIN_GAIN0_PABUF5GN_MASK)
#define MERLIN_GAIN0_PABUF5GN_RESET                                            0x1
#define MERLIN_GAIN0_PADRVGN_LSB                                               21
#define MERLIN_GAIN0_PADRVGN_MSB                                               23
#define MERLIN_GAIN0_PADRVGN_MASK                                              0xe00000
#define MERLIN_GAIN0_PADRVGN_GET(x)                                            (((x) & MERLIN_GAIN0_PADRVGN_MASK) >> MERLIN_GAIN0_PADRVGN_LSB)
#define MERLIN_GAIN0_PADRVGN_SET(x)                                            (((0 | (x)) << MERLIN_GAIN0_PADRVGN_LSB) & MERLIN_GAIN0_PADRVGN_MASK)
#define MERLIN_GAIN0_PADRVGN_RESET                                             0x7
#define MERLIN_GAIN0_PAOUT2GN_LSB                                              18
#define MERLIN_GAIN0_PAOUT2GN_MSB                                              20
#define MERLIN_GAIN0_PAOUT2GN_MASK                                             0x1c0000
#define MERLIN_GAIN0_PAOUT2GN_GET(x)                                           (((x) & MERLIN_GAIN0_PAOUT2GN_MASK) >> MERLIN_GAIN0_PAOUT2GN_LSB)
#define MERLIN_GAIN0_PAOUT2GN_SET(x)                                           (((0 | (x)) << MERLIN_GAIN0_PAOUT2GN_LSB) & MERLIN_GAIN0_PAOUT2GN_MASK)
#define MERLIN_GAIN0_PAOUT2GN_RESET                                            0x7
#define MERLIN_GAIN0_LNAON_LSB                                                 17
#define MERLIN_GAIN0_LNAON_MSB                                                 17
#define MERLIN_GAIN0_LNAON_MASK                                                0x20000
#define MERLIN_GAIN0_LNAON_GET(x)                                              (((x) & MERLIN_GAIN0_LNAON_MASK) >> MERLIN_GAIN0_LNAON_LSB)
#define MERLIN_GAIN0_LNAON_SET(x)                                              (((0 | (x)) << MERLIN_GAIN0_LNAON_LSB) & MERLIN_GAIN0_LNAON_MASK)
#define MERLIN_GAIN0_LNAON_RESET                                               0x1
#define MERLIN_GAIN0_LNAGAIN_LSB                                               13
#define MERLIN_GAIN0_LNAGAIN_MSB                                               16
#define MERLIN_GAIN0_LNAGAIN_MASK                                              0x1e000
#define MERLIN_GAIN0_LNAGAIN_GET(x)                                            (((x) & MERLIN_GAIN0_LNAGAIN_MASK) >> MERLIN_GAIN0_LNAGAIN_LSB)
#define MERLIN_GAIN0_LNAGAIN_SET(x)                                            (((0 | (x)) << MERLIN_GAIN0_LNAGAIN_LSB) & MERLIN_GAIN0_LNAGAIN_MASK)
#define MERLIN_GAIN0_LNAGAIN_RESET                                             0xf
#define MERLIN_GAIN0_RFVGA5GAIN_LSB                                            11
#define MERLIN_GAIN0_RFVGA5GAIN_MSB                                            12
#define MERLIN_GAIN0_RFVGA5GAIN_MASK                                           0x1800
#define MERLIN_GAIN0_RFVGA5GAIN_GET(x)                                         (((x) & MERLIN_GAIN0_RFVGA5GAIN_MASK) >> MERLIN_GAIN0_RFVGA5GAIN_LSB)
#define MERLIN_GAIN0_RFVGA5GAIN_SET(x)                                         (((0 | (x)) << MERLIN_GAIN0_RFVGA5GAIN_LSB) & MERLIN_GAIN0_RFVGA5GAIN_MASK)
#define MERLIN_GAIN0_RFVGA5GAIN_RESET                                          0x3
#define MERLIN_GAIN0_RFGMGN_LSB                                                8
#define MERLIN_GAIN0_RFGMGN_MSB                                                10
#define MERLIN_GAIN0_RFGMGN_MASK                                               0x700
#define MERLIN_GAIN0_RFGMGN_GET(x)                                             (((x) & MERLIN_GAIN0_RFGMGN_MASK) >> MERLIN_GAIN0_RFGMGN_LSB)
#define MERLIN_GAIN0_RFGMGN_SET(x)                                             (((0 | (x)) << MERLIN_GAIN0_RFGMGN_LSB) & MERLIN_GAIN0_RFGMGN_MASK)
#define MERLIN_GAIN0_RFGMGN_RESET                                              0x7
#define MERLIN_GAIN0_RX6DBLOQGAIN_LSB                                          6
#define MERLIN_GAIN0_RX6DBLOQGAIN_MSB                                          7
#define MERLIN_GAIN0_RX6DBLOQGAIN_MASK                                         0xc0
#define MERLIN_GAIN0_RX6DBLOQGAIN_GET(x)                                       (((x) & MERLIN_GAIN0_RX6DBLOQGAIN_MASK) >> MERLIN_GAIN0_RX6DBLOQGAIN_LSB)
#define MERLIN_GAIN0_RX6DBLOQGAIN_SET(x)                                       (((0 | (x)) << MERLIN_GAIN0_RX6DBLOQGAIN_LSB) & MERLIN_GAIN0_RX6DBLOQGAIN_MASK)
#define MERLIN_GAIN0_RX6DBLOQGAIN_RESET                                        0x3
#define MERLIN_GAIN0_RX1DBLOQGAIN_LSB                                          3
#define MERLIN_GAIN0_RX1DBLOQGAIN_MSB                                          5
#define MERLIN_GAIN0_RX1DBLOQGAIN_MASK                                         0x38
#define MERLIN_GAIN0_RX1DBLOQGAIN_GET(x)                                       (((x) & MERLIN_GAIN0_RX1DBLOQGAIN_MASK) >> MERLIN_GAIN0_RX1DBLOQGAIN_LSB)
#define MERLIN_GAIN0_RX1DBLOQGAIN_SET(x)                                       (((0 | (x)) << MERLIN_GAIN0_RX1DBLOQGAIN_LSB) & MERLIN_GAIN0_RX1DBLOQGAIN_MASK)
#define MERLIN_GAIN0_RX1DBLOQGAIN_RESET                                        0x6
#define MERLIN_GAIN0_RX6DBHIQGAIN_LSB                                          1
#define MERLIN_GAIN0_RX6DBHIQGAIN_MSB                                          2
#define MERLIN_GAIN0_RX6DBHIQGAIN_MASK                                         0x6
#define MERLIN_GAIN0_RX6DBHIQGAIN_GET(x)                                       (((x) & MERLIN_GAIN0_RX6DBHIQGAIN_MASK) >> MERLIN_GAIN0_RX6DBHIQGAIN_LSB)
#define MERLIN_GAIN0_RX6DBHIQGAIN_SET(x)                                       (((0 | (x)) << MERLIN_GAIN0_RX6DBHIQGAIN_LSB) & MERLIN_GAIN0_RX6DBHIQGAIN_MASK)
#define MERLIN_GAIN0_RX6DBHIQGAIN_RESET                                        0x3
#define MERLIN_GAIN0_SPARE_LSB                                                 0
#define MERLIN_GAIN0_SPARE_MSB                                                 0
#define MERLIN_GAIN0_SPARE_MASK                                                0x1
#define MERLIN_GAIN0_SPARE_GET(x)                                              (((x) & MERLIN_GAIN0_SPARE_MASK) >> MERLIN_GAIN0_SPARE_LSB)
#define MERLIN_GAIN0_SPARE_SET(x)                                              (((0 | (x)) << MERLIN_GAIN0_SPARE_LSB) & MERLIN_GAIN0_SPARE_MASK)
#define MERLIN_GAIN0_SPARE_RESET                                               0x0
#define MERLIN_GAIN0_ADDRESS                                                   (0x84 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_GAIN0_RSTMASK                                                   0xffffffff
#define MERLIN_GAIN0_RESET                                                     0xf7fffff6

// 0x88 (MERLIN_GAIN1)
#define MERLIN_GAIN1_TX6DBLOQGAIN_LSB                                          30
#define MERLIN_GAIN1_TX6DBLOQGAIN_MSB                                          31
#define MERLIN_GAIN1_TX6DBLOQGAIN_MASK                                         0xc0000000
#define MERLIN_GAIN1_TX6DBLOQGAIN_GET(x)                                       (((x) & MERLIN_GAIN1_TX6DBLOQGAIN_MASK) >> MERLIN_GAIN1_TX6DBLOQGAIN_LSB)
#define MERLIN_GAIN1_TX6DBLOQGAIN_SET(x)                                       (((0 | (x)) << MERLIN_GAIN1_TX6DBLOQGAIN_LSB) & MERLIN_GAIN1_TX6DBLOQGAIN_MASK)
#define MERLIN_GAIN1_TX6DBLOQGAIN_RESET                                        0x3
#define MERLIN_GAIN1_TX1DBLOQGAIN_LSB                                          27
#define MERLIN_GAIN1_TX1DBLOQGAIN_MSB                                          29
#define MERLIN_GAIN1_TX1DBLOQGAIN_MASK                                         0x38000000
#define MERLIN_GAIN1_TX1DBLOQGAIN_GET(x)                                       (((x) & MERLIN_GAIN1_TX1DBLOQGAIN_MASK) >> MERLIN_GAIN1_TX1DBLOQGAIN_LSB)
#define MERLIN_GAIN1_TX1DBLOQGAIN_SET(x)                                       (((0 | (x)) << MERLIN_GAIN1_TX1DBLOQGAIN_LSB) & MERLIN_GAIN1_TX1DBLOQGAIN_MASK)
#define MERLIN_GAIN1_TX1DBLOQGAIN_RESET                                        0x6
#define MERLIN_GAIN1_TXV2IGAIN_LSB                                             25
#define MERLIN_GAIN1_TXV2IGAIN_MSB                                             26
#define MERLIN_GAIN1_TXV2IGAIN_MASK                                            0x6000000
#define MERLIN_GAIN1_TXV2IGAIN_GET(x)                                          (((x) & MERLIN_GAIN1_TXV2IGAIN_MASK) >> MERLIN_GAIN1_TXV2IGAIN_LSB)
#define MERLIN_GAIN1_TXV2IGAIN_SET(x)                                          (((0 | (x)) << MERLIN_GAIN1_TXV2IGAIN_LSB) & MERLIN_GAIN1_TXV2IGAIN_MASK)
#define MERLIN_GAIN1_TXV2IGAIN_RESET                                           0x3
#define MERLIN_GAIN1_PABUF5GN_LSB                                              24
#define MERLIN_GAIN1_PABUF5GN_MSB                                              24
#define MERLIN_GAIN1_PABUF5GN_MASK                                             0x1000000
#define MERLIN_GAIN1_PABUF5GN_GET(x)                                           (((x) & MERLIN_GAIN1_PABUF5GN_MASK) >> MERLIN_GAIN1_PABUF5GN_LSB)
#define MERLIN_GAIN1_PABUF5GN_SET(x)                                           (((0 | (x)) << MERLIN_GAIN1_PABUF5GN_LSB) & MERLIN_GAIN1_PABUF5GN_MASK)
#define MERLIN_GAIN1_PABUF5GN_RESET                                            0x1
#define MERLIN_GAIN1_PADRVGN_LSB                                               21
#define MERLIN_GAIN1_PADRVGN_MSB                                               23
#define MERLIN_GAIN1_PADRVGN_MASK                                              0xe00000
#define MERLIN_GAIN1_PADRVGN_GET(x)                                            (((x) & MERLIN_GAIN1_PADRVGN_MASK) >> MERLIN_GAIN1_PADRVGN_LSB)
#define MERLIN_GAIN1_PADRVGN_SET(x)                                            (((0 | (x)) << MERLIN_GAIN1_PADRVGN_LSB) & MERLIN_GAIN1_PADRVGN_MASK)
#define MERLIN_GAIN1_PADRVGN_RESET                                             0x7
#define MERLIN_GAIN1_PAOUT2GN_LSB                                              18
#define MERLIN_GAIN1_PAOUT2GN_MSB                                              20
#define MERLIN_GAIN1_PAOUT2GN_MASK                                             0x1c0000
#define MERLIN_GAIN1_PAOUT2GN_GET(x)                                           (((x) & MERLIN_GAIN1_PAOUT2GN_MASK) >> MERLIN_GAIN1_PAOUT2GN_LSB)
#define MERLIN_GAIN1_PAOUT2GN_SET(x)                                           (((0 | (x)) << MERLIN_GAIN1_PAOUT2GN_LSB) & MERLIN_GAIN1_PAOUT2GN_MASK)
#define MERLIN_GAIN1_PAOUT2GN_RESET                                            0x7
#define MERLIN_GAIN1_LNAON_LSB                                                 17
#define MERLIN_GAIN1_LNAON_MSB                                                 17
#define MERLIN_GAIN1_LNAON_MASK                                                0x20000
#define MERLIN_GAIN1_LNAON_GET(x)                                              (((x) & MERLIN_GAIN1_LNAON_MASK) >> MERLIN_GAIN1_LNAON_LSB)
#define MERLIN_GAIN1_LNAON_SET(x)                                              (((0 | (x)) << MERLIN_GAIN1_LNAON_LSB) & MERLIN_GAIN1_LNAON_MASK)
#define MERLIN_GAIN1_LNAON_RESET                                               0x1
#define MERLIN_GAIN1_LNAGAIN_LSB                                               13
#define MERLIN_GAIN1_LNAGAIN_MSB                                               16
#define MERLIN_GAIN1_LNAGAIN_MASK                                              0x1e000
#define MERLIN_GAIN1_LNAGAIN_GET(x)                                            (((x) & MERLIN_GAIN1_LNAGAIN_MASK) >> MERLIN_GAIN1_LNAGAIN_LSB)
#define MERLIN_GAIN1_LNAGAIN_SET(x)                                            (((0 | (x)) << MERLIN_GAIN1_LNAGAIN_LSB) & MERLIN_GAIN1_LNAGAIN_MASK)
#define MERLIN_GAIN1_LNAGAIN_RESET                                             0xf
#define MERLIN_GAIN1_RFVGA5GAIN_LSB                                            11
#define MERLIN_GAIN1_RFVGA5GAIN_MSB                                            12
#define MERLIN_GAIN1_RFVGA5GAIN_MASK                                           0x1800
#define MERLIN_GAIN1_RFVGA5GAIN_GET(x)                                         (((x) & MERLIN_GAIN1_RFVGA5GAIN_MASK) >> MERLIN_GAIN1_RFVGA5GAIN_LSB)
#define MERLIN_GAIN1_RFVGA5GAIN_SET(x)                                         (((0 | (x)) << MERLIN_GAIN1_RFVGA5GAIN_LSB) & MERLIN_GAIN1_RFVGA5GAIN_MASK)
#define MERLIN_GAIN1_RFVGA5GAIN_RESET                                          0x3
#define MERLIN_GAIN1_RFGMGN_LSB                                                8
#define MERLIN_GAIN1_RFGMGN_MSB                                                10
#define MERLIN_GAIN1_RFGMGN_MASK                                               0x700
#define MERLIN_GAIN1_RFGMGN_GET(x)                                             (((x) & MERLIN_GAIN1_RFGMGN_MASK) >> MERLIN_GAIN1_RFGMGN_LSB)
#define MERLIN_GAIN1_RFGMGN_SET(x)                                             (((0 | (x)) << MERLIN_GAIN1_RFGMGN_LSB) & MERLIN_GAIN1_RFGMGN_MASK)
#define MERLIN_GAIN1_RFGMGN_RESET                                              0x7
#define MERLIN_GAIN1_RX6DBLOQGAIN_LSB                                          6
#define MERLIN_GAIN1_RX6DBLOQGAIN_MSB                                          7
#define MERLIN_GAIN1_RX6DBLOQGAIN_MASK                                         0xc0
#define MERLIN_GAIN1_RX6DBLOQGAIN_GET(x)                                       (((x) & MERLIN_GAIN1_RX6DBLOQGAIN_MASK) >> MERLIN_GAIN1_RX6DBLOQGAIN_LSB)
#define MERLIN_GAIN1_RX6DBLOQGAIN_SET(x)                                       (((0 | (x)) << MERLIN_GAIN1_RX6DBLOQGAIN_LSB) & MERLIN_GAIN1_RX6DBLOQGAIN_MASK)
#define MERLIN_GAIN1_RX6DBLOQGAIN_RESET                                        0x3
#define MERLIN_GAIN1_RX1DBLOQGAIN_LSB                                          3
#define MERLIN_GAIN1_RX1DBLOQGAIN_MSB                                          5
#define MERLIN_GAIN1_RX1DBLOQGAIN_MASK                                         0x38
#define MERLIN_GAIN1_RX1DBLOQGAIN_GET(x)                                       (((x) & MERLIN_GAIN1_RX1DBLOQGAIN_MASK) >> MERLIN_GAIN1_RX1DBLOQGAIN_LSB)
#define MERLIN_GAIN1_RX1DBLOQGAIN_SET(x)                                       (((0 | (x)) << MERLIN_GAIN1_RX1DBLOQGAIN_LSB) & MERLIN_GAIN1_RX1DBLOQGAIN_MASK)
#define MERLIN_GAIN1_RX1DBLOQGAIN_RESET                                        0x6
#define MERLIN_GAIN1_RX6DBHIQGAIN_LSB                                          1
#define MERLIN_GAIN1_RX6DBHIQGAIN_MSB                                          2
#define MERLIN_GAIN1_RX6DBHIQGAIN_MASK                                         0x6
#define MERLIN_GAIN1_RX6DBHIQGAIN_GET(x)                                       (((x) & MERLIN_GAIN1_RX6DBHIQGAIN_MASK) >> MERLIN_GAIN1_RX6DBHIQGAIN_LSB)
#define MERLIN_GAIN1_RX6DBHIQGAIN_SET(x)                                       (((0 | (x)) << MERLIN_GAIN1_RX6DBHIQGAIN_LSB) & MERLIN_GAIN1_RX6DBHIQGAIN_MASK)
#define MERLIN_GAIN1_RX6DBHIQGAIN_RESET                                        0x3
#define MERLIN_GAIN1_SPARE_LSB                                                 0
#define MERLIN_GAIN1_SPARE_MSB                                                 0
#define MERLIN_GAIN1_SPARE_MASK                                                0x1
#define MERLIN_GAIN1_SPARE_GET(x)                                              (((x) & MERLIN_GAIN1_SPARE_MASK) >> MERLIN_GAIN1_SPARE_LSB)
#define MERLIN_GAIN1_SPARE_SET(x)                                              (((0 | (x)) << MERLIN_GAIN1_SPARE_LSB) & MERLIN_GAIN1_SPARE_MASK)
#define MERLIN_GAIN1_SPARE_RESET                                               0x0
#define MERLIN_GAIN1_ADDRESS                                                   (0x88 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_GAIN1_RSTMASK                                                   0xffffffff
#define MERLIN_GAIN1_RESET                                                     0xf7fffff6

// 0x8c (MERLIN_TOP0)
#define MERLIN_TOP0_LOCALTXGAIN_LSB                                            31
#define MERLIN_TOP0_LOCALTXGAIN_MSB                                            31
#define MERLIN_TOP0_LOCALTXGAIN_MASK                                           0x80000000
#define MERLIN_TOP0_LOCALTXGAIN_GET(x)                                         (((x) & MERLIN_TOP0_LOCALTXGAIN_MASK) >> MERLIN_TOP0_LOCALTXGAIN_LSB)
#define MERLIN_TOP0_LOCALTXGAIN_SET(x)                                         (((0 | (x)) << MERLIN_TOP0_LOCALTXGAIN_LSB) & MERLIN_TOP0_LOCALTXGAIN_MASK)
#define MERLIN_TOP0_LOCALTXGAIN_RESET                                          0x0
#define MERLIN_TOP0_LOCALRXGAIN_LSB                                            30
#define MERLIN_TOP0_LOCALRXGAIN_MSB                                            30
#define MERLIN_TOP0_LOCALRXGAIN_MASK                                           0x40000000
#define MERLIN_TOP0_LOCALRXGAIN_GET(x)                                         (((x) & MERLIN_TOP0_LOCALRXGAIN_MASK) >> MERLIN_TOP0_LOCALRXGAIN_LSB)
#define MERLIN_TOP0_LOCALRXGAIN_SET(x)                                         (((0 | (x)) << MERLIN_TOP0_LOCALRXGAIN_LSB) & MERLIN_TOP0_LOCALRXGAIN_MASK)
#define MERLIN_TOP0_LOCALRXGAIN_RESET                                          0x0
#define MERLIN_TOP0_LOCALMODE_LSB                                              29
#define MERLIN_TOP0_LOCALMODE_MSB                                              29
#define MERLIN_TOP0_LOCALMODE_MASK                                             0x20000000
#define MERLIN_TOP0_LOCALMODE_GET(x)                                           (((x) & MERLIN_TOP0_LOCALMODE_MASK) >> MERLIN_TOP0_LOCALMODE_LSB)
#define MERLIN_TOP0_LOCALMODE_SET(x)                                           (((0 | (x)) << MERLIN_TOP0_LOCALMODE_LSB) & MERLIN_TOP0_LOCALMODE_MASK)
#define MERLIN_TOP0_LOCALMODE_RESET                                            0x0
#define MERLIN_TOP0_CALFC_LSB                                                  27
#define MERLIN_TOP0_CALFC_MSB                                                  28
#define MERLIN_TOP0_CALFC_MASK                                                 0x18000000
#define MERLIN_TOP0_CALFC_GET(x)                                               (((x) & MERLIN_TOP0_CALFC_MASK) >> MERLIN_TOP0_CALFC_LSB)
#define MERLIN_TOP0_CALFC_SET(x)                                               (((0 | (x)) << MERLIN_TOP0_CALFC_LSB) & MERLIN_TOP0_CALFC_MASK)
#define MERLIN_TOP0_CALFC_RESET                                                0x0
#define MERLIN_TOP0_CALDC_LSB                                                  25
#define MERLIN_TOP0_CALDC_MSB                                                  26
#define MERLIN_TOP0_CALDC_MASK                                                 0x6000000
#define MERLIN_TOP0_CALDC_GET(x)                                               (((x) & MERLIN_TOP0_CALDC_MASK) >> MERLIN_TOP0_CALDC_LSB)
#define MERLIN_TOP0_CALDC_SET(x)                                               (((0 | (x)) << MERLIN_TOP0_CALDC_LSB) & MERLIN_TOP0_CALDC_MASK)
#define MERLIN_TOP0_CALDC_RESET                                                0x0
#define MERLIN_TOP0_CAL_RESIDUE_LSB                                            23
#define MERLIN_TOP0_CAL_RESIDUE_MSB                                            24
#define MERLIN_TOP0_CAL_RESIDUE_MASK                                           0x1800000
#define MERLIN_TOP0_CAL_RESIDUE_GET(x)                                         (((x) & MERLIN_TOP0_CAL_RESIDUE_MASK) >> MERLIN_TOP0_CAL_RESIDUE_LSB)
#define MERLIN_TOP0_CAL_RESIDUE_SET(x)                                         (((0 | (x)) << MERLIN_TOP0_CAL_RESIDUE_LSB) & MERLIN_TOP0_CAL_RESIDUE_MASK)
#define MERLIN_TOP0_CAL_RESIDUE_RESET                                          0x0
#define MERLIN_TOP0_CALTX_LSB                                                  21
#define MERLIN_TOP0_CALTX_MSB                                                  22
#define MERLIN_TOP0_CALTX_MASK                                                 0x600000
#define MERLIN_TOP0_CALTX_GET(x)                                               (((x) & MERLIN_TOP0_CALTX_MASK) >> MERLIN_TOP0_CALTX_LSB)
#define MERLIN_TOP0_CALTX_SET(x)                                               (((0 | (x)) << MERLIN_TOP0_CALTX_LSB) & MERLIN_TOP0_CALTX_MASK)
#define MERLIN_TOP0_CALTX_RESET                                                0x0
#define MERLIN_TOP0_BMODE_LSB                                                  20
#define MERLIN_TOP0_BMODE_MSB                                                  20
#define MERLIN_TOP0_BMODE_MASK                                                 0x100000
#define MERLIN_TOP0_BMODE_GET(x)                                               (((x) & MERLIN_TOP0_BMODE_MASK) >> MERLIN_TOP0_BMODE_LSB)
#define MERLIN_TOP0_BMODE_SET(x)                                               (((0 | (x)) << MERLIN_TOP0_BMODE_LSB) & MERLIN_TOP0_BMODE_MASK)
#define MERLIN_TOP0_BMODE_RESET                                                0x1
#define MERLIN_TOP0_BMODERXTX_LSB                                              18
#define MERLIN_TOP0_BMODERXTX_MSB                                              19
#define MERLIN_TOP0_BMODERXTX_MASK                                             0xc0000
#define MERLIN_TOP0_BMODERXTX_GET(x)                                           (((x) & MERLIN_TOP0_BMODERXTX_MASK) >> MERLIN_TOP0_BMODERXTX_LSB)
#define MERLIN_TOP0_BMODERXTX_SET(x)                                           (((0 | (x)) << MERLIN_TOP0_BMODERXTX_LSB) & MERLIN_TOP0_BMODERXTX_MASK)
#define MERLIN_TOP0_BMODERXTX_RESET                                            0x0
#define MERLIN_TOP0_TURBOMODE_LSB                                              17
#define MERLIN_TOP0_TURBOMODE_MSB                                              17
#define MERLIN_TOP0_TURBOMODE_MASK                                             0x20000
#define MERLIN_TOP0_TURBOMODE_GET(x)                                           (((x) & MERLIN_TOP0_TURBOMODE_MASK) >> MERLIN_TOP0_TURBOMODE_LSB)
#define MERLIN_TOP0_TURBOMODE_SET(x)                                           (((0 | (x)) << MERLIN_TOP0_TURBOMODE_LSB) & MERLIN_TOP0_TURBOMODE_MASK)
#define MERLIN_TOP0_TURBOMODE_RESET                                            0x0
#define MERLIN_TOP0_SYNTHON_LSB                                                16
#define MERLIN_TOP0_SYNTHON_MSB                                                16
#define MERLIN_TOP0_SYNTHON_MASK                                               0x10000
#define MERLIN_TOP0_SYNTHON_GET(x)                                             (((x) & MERLIN_TOP0_SYNTHON_MASK) >> MERLIN_TOP0_SYNTHON_LSB)
#define MERLIN_TOP0_SYNTHON_SET(x)                                             (((0 | (x)) << MERLIN_TOP0_SYNTHON_LSB) & MERLIN_TOP0_SYNTHON_MASK)
#define MERLIN_TOP0_SYNTHON_RESET                                              0x0
#define MERLIN_TOP0_RXON_LSB                                                   14
#define MERLIN_TOP0_RXON_MSB                                                   15
#define MERLIN_TOP0_RXON_MASK                                                  0xc000
#define MERLIN_TOP0_RXON_GET(x)                                                (((x) & MERLIN_TOP0_RXON_MASK) >> MERLIN_TOP0_RXON_LSB)
#define MERLIN_TOP0_RXON_SET(x)                                                (((0 | (x)) << MERLIN_TOP0_RXON_LSB) & MERLIN_TOP0_RXON_MASK)
#define MERLIN_TOP0_RXON_RESET                                                 0x0
#define MERLIN_TOP0_TXON_LSB                                                   12
#define MERLIN_TOP0_TXON_MSB                                                   13
#define MERLIN_TOP0_TXON_MASK                                                  0x3000
#define MERLIN_TOP0_TXON_GET(x)                                                (((x) & MERLIN_TOP0_TXON_MASK) >> MERLIN_TOP0_TXON_LSB)
#define MERLIN_TOP0_TXON_SET(x)                                                (((0 | (x)) << MERLIN_TOP0_TXON_LSB) & MERLIN_TOP0_TXON_MASK)
#define MERLIN_TOP0_TXON_RESET                                                 0x0
#define MERLIN_TOP0_PAON_LSB                                                   10
#define MERLIN_TOP0_PAON_MSB                                                   11
#define MERLIN_TOP0_PAON_MASK                                                  0xc00
#define MERLIN_TOP0_PAON_GET(x)                                                (((x) & MERLIN_TOP0_PAON_MASK) >> MERLIN_TOP0_PAON_LSB)
#define MERLIN_TOP0_PAON_SET(x)                                                (((0 | (x)) << MERLIN_TOP0_PAON_LSB) & MERLIN_TOP0_PAON_MASK)
#define MERLIN_TOP0_PAON_RESET                                                 0x0
#define MERLIN_TOP0_XLNAON_LSB                                                 8
#define MERLIN_TOP0_XLNAON_MSB                                                 9
#define MERLIN_TOP0_XLNAON_MASK                                                0x300
#define MERLIN_TOP0_XLNAON_GET(x)                                              (((x) & MERLIN_TOP0_XLNAON_MASK) >> MERLIN_TOP0_XLNAON_LSB)
#define MERLIN_TOP0_XLNAON_SET(x)                                              (((0 | (x)) << MERLIN_TOP0_XLNAON_LSB) & MERLIN_TOP0_XLNAON_MASK)
#define MERLIN_TOP0_XLNAON_RESET                                               0x1
#define MERLIN_TOP0_XPAON_LSB                                                  7
#define MERLIN_TOP0_XPAON_MSB                                                  7
#define MERLIN_TOP0_XPAON_MASK                                                 0x80
#define MERLIN_TOP0_XPAON_GET(x)                                               (((x) & MERLIN_TOP0_XPAON_MASK) >> MERLIN_TOP0_XPAON_LSB)
#define MERLIN_TOP0_XPAON_SET(x)                                               (((0 | (x)) << MERLIN_TOP0_XPAON_LSB) & MERLIN_TOP0_XPAON_MASK)
#define MERLIN_TOP0_XPAON_RESET                                                0x0
#define MERLIN_TOP0_LOCALXTAL_LSB                                              6
#define MERLIN_TOP0_LOCALXTAL_MSB                                              6
#define MERLIN_TOP0_LOCALXTAL_MASK                                             0x40
#define MERLIN_TOP0_LOCALXTAL_GET(x)                                           (((x) & MERLIN_TOP0_LOCALXTAL_MASK) >> MERLIN_TOP0_LOCALXTAL_LSB)
#define MERLIN_TOP0_LOCALXTAL_SET(x)                                           (((0 | (x)) << MERLIN_TOP0_LOCALXTAL_LSB) & MERLIN_TOP0_LOCALXTAL_MASK)
#define MERLIN_TOP0_LOCALXTAL_RESET                                            0x0
#define MERLIN_TOP0_PWDCLKIN_LSB                                               5
#define MERLIN_TOP0_PWDCLKIN_MSB                                               5
#define MERLIN_TOP0_PWDCLKIN_MASK                                              0x20
#define MERLIN_TOP0_PWDCLKIN_GET(x)                                            (((x) & MERLIN_TOP0_PWDCLKIN_MASK) >> MERLIN_TOP0_PWDCLKIN_LSB)
#define MERLIN_TOP0_PWDCLKIN_SET(x)                                            (((0 | (x)) << MERLIN_TOP0_PWDCLKIN_LSB) & MERLIN_TOP0_PWDCLKIN_MASK)
#define MERLIN_TOP0_PWDCLKIN_RESET                                             0x0
#define MERLIN_TOP0_OSCON_LSB                                                  4
#define MERLIN_TOP0_OSCON_MSB                                                  4
#define MERLIN_TOP0_OSCON_MASK                                                 0x10
#define MERLIN_TOP0_OSCON_GET(x)                                               (((x) & MERLIN_TOP0_OSCON_MASK) >> MERLIN_TOP0_OSCON_LSB)
#define MERLIN_TOP0_OSCON_SET(x)                                               (((0 | (x)) << MERLIN_TOP0_OSCON_LSB) & MERLIN_TOP0_OSCON_MASK)
#define MERLIN_TOP0_OSCON_RESET                                                0x1
#define MERLIN_TOP0_SCLKEN_FORCE_LSB                                           3
#define MERLIN_TOP0_SCLKEN_FORCE_MSB                                           3
#define MERLIN_TOP0_SCLKEN_FORCE_MASK                                          0x8
#define MERLIN_TOP0_SCLKEN_FORCE_GET(x)                                        (((x) & MERLIN_TOP0_SCLKEN_FORCE_MASK) >> MERLIN_TOP0_SCLKEN_FORCE_LSB)
#define MERLIN_TOP0_SCLKEN_FORCE_SET(x)                                        (((0 | (x)) << MERLIN_TOP0_SCLKEN_FORCE_LSB) & MERLIN_TOP0_SCLKEN_FORCE_MASK)
#define MERLIN_TOP0_SCLKEN_FORCE_RESET                                         0x0
#define MERLIN_TOP0_SYNTHON_FORCE_LSB                                          2
#define MERLIN_TOP0_SYNTHON_FORCE_MSB                                          2
#define MERLIN_TOP0_SYNTHON_FORCE_MASK                                         0x4
#define MERLIN_TOP0_SYNTHON_FORCE_GET(x)                                       (((x) & MERLIN_TOP0_SYNTHON_FORCE_MASK) >> MERLIN_TOP0_SYNTHON_FORCE_LSB)
#define MERLIN_TOP0_SYNTHON_FORCE_SET(x)                                       (((0 | (x)) << MERLIN_TOP0_SYNTHON_FORCE_LSB) & MERLIN_TOP0_SYNTHON_FORCE_MASK)
#define MERLIN_TOP0_SYNTHON_FORCE_RESET                                        0x0
#define MERLIN_TOP0_PWDBIAS_LSB                                                1
#define MERLIN_TOP0_PWDBIAS_MSB                                                1
#define MERLIN_TOP0_PWDBIAS_MASK                                               0x2
#define MERLIN_TOP0_PWDBIAS_GET(x)                                             (((x) & MERLIN_TOP0_PWDBIAS_MASK) >> MERLIN_TOP0_PWDBIAS_LSB)
#define MERLIN_TOP0_PWDBIAS_SET(x)                                             (((0 | (x)) << MERLIN_TOP0_PWDBIAS_LSB) & MERLIN_TOP0_PWDBIAS_MASK)
#define MERLIN_TOP0_PWDBIAS_RESET                                              0x0
#define MERLIN_TOP0_FORCEMSBLOW_LSB                                            0
#define MERLIN_TOP0_FORCEMSBLOW_MSB                                            0
#define MERLIN_TOP0_FORCEMSBLOW_MASK                                           0x1
#define MERLIN_TOP0_FORCEMSBLOW_GET(x)                                         (((x) & MERLIN_TOP0_FORCEMSBLOW_MASK) >> MERLIN_TOP0_FORCEMSBLOW_LSB)
#define MERLIN_TOP0_FORCEMSBLOW_SET(x)                                         (((0 | (x)) << MERLIN_TOP0_FORCEMSBLOW_LSB) & MERLIN_TOP0_FORCEMSBLOW_MASK)
#define MERLIN_TOP0_FORCEMSBLOW_RESET                                          0x0
#define MERLIN_TOP0_ADDRESS                                                    (0x8c + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_TOP0_RSTMASK                                                    0xffffffff
#define MERLIN_TOP0_RESET                                                      0x100110

// 0x90 (MERLIN_TOP1)
#define MERLIN_TOP1_REVID_LSB                                                  29
#define MERLIN_TOP1_REVID_MSB                                                  31
#define MERLIN_TOP1_REVID_MASK                                                 0xe0000000
#define MERLIN_TOP1_REVID_GET(x)                                               (((x) & MERLIN_TOP1_REVID_MASK) >> MERLIN_TOP1_REVID_LSB)
#define MERLIN_TOP1_REVID_SET(x)                                               (((0 | (x)) << MERLIN_TOP1_REVID_LSB) & MERLIN_TOP1_REVID_MASK)
#define MERLIN_TOP1_REVID_RESET                                                0x0
#define MERLIN_TOP1_INT2PAD_LSB                                                28
#define MERLIN_TOP1_INT2PAD_MSB                                                28
#define MERLIN_TOP1_INT2PAD_MASK                                               0x10000000
#define MERLIN_TOP1_INT2PAD_GET(x)                                             (((x) & MERLIN_TOP1_INT2PAD_MASK) >> MERLIN_TOP1_INT2PAD_LSB)
#define MERLIN_TOP1_INT2PAD_SET(x)                                             (((0 | (x)) << MERLIN_TOP1_INT2PAD_LSB) & MERLIN_TOP1_INT2PAD_MASK)
#define MERLIN_TOP1_INT2PAD_RESET                                              0x0
#define MERLIN_TOP1_INTH2PAD_LSB                                               27
#define MERLIN_TOP1_INTH2PAD_MSB                                               27
#define MERLIN_TOP1_INTH2PAD_MASK                                              0x8000000
#define MERLIN_TOP1_INTH2PAD_GET(x)                                            (((x) & MERLIN_TOP1_INTH2PAD_MASK) >> MERLIN_TOP1_INTH2PAD_LSB)
#define MERLIN_TOP1_INTH2PAD_SET(x)                                            (((0 | (x)) << MERLIN_TOP1_INTH2PAD_LSB) & MERLIN_TOP1_INTH2PAD_MASK)
#define MERLIN_TOP1_INTH2PAD_RESET                                             0x0
#define MERLIN_TOP1_PAD2GND_LSB                                                26
#define MERLIN_TOP1_PAD2GND_MSB                                                26
#define MERLIN_TOP1_PAD2GND_MASK                                               0x4000000
#define MERLIN_TOP1_PAD2GND_GET(x)                                             (((x) & MERLIN_TOP1_PAD2GND_MASK) >> MERLIN_TOP1_PAD2GND_LSB)
#define MERLIN_TOP1_PAD2GND_SET(x)                                             (((0 | (x)) << MERLIN_TOP1_PAD2GND_LSB) & MERLIN_TOP1_PAD2GND_MASK)
#define MERLIN_TOP1_PAD2GND_RESET                                              0x0
#define MERLIN_TOP1_INT2GND_LSB                                                25
#define MERLIN_TOP1_INT2GND_MSB                                                25
#define MERLIN_TOP1_INT2GND_MASK                                               0x2000000
#define MERLIN_TOP1_INT2GND_GET(x)                                             (((x) & MERLIN_TOP1_INT2GND_MASK) >> MERLIN_TOP1_INT2GND_LSB)
#define MERLIN_TOP1_INT2GND_SET(x)                                             (((0 | (x)) << MERLIN_TOP1_INT2GND_LSB) & MERLIN_TOP1_INT2GND_MASK)
#define MERLIN_TOP1_INT2GND_RESET                                              0x0
#define MERLIN_TOP1_LOCALADDAC_LSB                                             24
#define MERLIN_TOP1_LOCALADDAC_MSB                                             24
#define MERLIN_TOP1_LOCALADDAC_MASK                                            0x1000000
#define MERLIN_TOP1_LOCALADDAC_GET(x)                                          (((x) & MERLIN_TOP1_LOCALADDAC_MASK) >> MERLIN_TOP1_LOCALADDAC_LSB)
#define MERLIN_TOP1_LOCALADDAC_SET(x)                                          (((0 | (x)) << MERLIN_TOP1_LOCALADDAC_LSB) & MERLIN_TOP1_LOCALADDAC_MASK)
#define MERLIN_TOP1_LOCALADDAC_RESET                                           0x0
#define MERLIN_TOP1_PWDPLL_LSB                                                 23
#define MERLIN_TOP1_PWDPLL_MSB                                                 23
#define MERLIN_TOP1_PWDPLL_MASK                                                0x800000
#define MERLIN_TOP1_PWDPLL_GET(x)                                              (((x) & MERLIN_TOP1_PWDPLL_MASK) >> MERLIN_TOP1_PWDPLL_LSB)
#define MERLIN_TOP1_PWDPLL_SET(x)                                              (((0 | (x)) << MERLIN_TOP1_PWDPLL_LSB) & MERLIN_TOP1_PWDPLL_MASK)
#define MERLIN_TOP1_PWDPLL_RESET                                               0x0
#define MERLIN_TOP1_PWDADC_LSB                                                 21
#define MERLIN_TOP1_PWDADC_MSB                                                 22
#define MERLIN_TOP1_PWDADC_MASK                                                0x600000
#define MERLIN_TOP1_PWDADC_GET(x)                                              (((x) & MERLIN_TOP1_PWDADC_MASK) >> MERLIN_TOP1_PWDADC_LSB)
#define MERLIN_TOP1_PWDADC_SET(x)                                              (((0 | (x)) << MERLIN_TOP1_PWDADC_LSB) & MERLIN_TOP1_PWDADC_MASK)
#define MERLIN_TOP1_PWDADC_RESET                                               0x0
#define MERLIN_TOP1_PWDDAC_LSB                                                 19
#define MERLIN_TOP1_PWDDAC_MSB                                                 20
#define MERLIN_TOP1_PWDDAC_MASK                                                0x180000
#define MERLIN_TOP1_PWDDAC_GET(x)                                              (((x) & MERLIN_TOP1_PWDDAC_MASK) >> MERLIN_TOP1_PWDDAC_LSB)
#define MERLIN_TOP1_PWDDAC_SET(x)                                              (((0 | (x)) << MERLIN_TOP1_PWDDAC_LSB) & MERLIN_TOP1_PWDDAC_MASK)
#define MERLIN_TOP1_PWDDAC_RESET                                               0x0
#define MERLIN_TOP1_DACLPMODE_LSB                                              18
#define MERLIN_TOP1_DACLPMODE_MSB                                              18
#define MERLIN_TOP1_DACLPMODE_MASK                                             0x40000
#define MERLIN_TOP1_DACLPMODE_GET(x)                                           (((x) & MERLIN_TOP1_DACLPMODE_MASK) >> MERLIN_TOP1_DACLPMODE_LSB)
#define MERLIN_TOP1_DACLPMODE_SET(x)                                           (((0 | (x)) << MERLIN_TOP1_DACLPMODE_LSB) & MERLIN_TOP1_DACLPMODE_MASK)
#define MERLIN_TOP1_DACLPMODE_RESET                                            0x0
#define MERLIN_TOP1_INV_CLK160_ADC_LSB                                         17
#define MERLIN_TOP1_INV_CLK160_ADC_MSB                                         17
#define MERLIN_TOP1_INV_CLK160_ADC_MASK                                        0x20000
#define MERLIN_TOP1_INV_CLK160_ADC_GET(x)                                      (((x) & MERLIN_TOP1_INV_CLK160_ADC_MASK) >> MERLIN_TOP1_INV_CLK160_ADC_LSB)
#define MERLIN_TOP1_INV_CLK160_ADC_SET(x)                                      (((0 | (x)) << MERLIN_TOP1_INV_CLK160_ADC_LSB) & MERLIN_TOP1_INV_CLK160_ADC_MASK)
#define MERLIN_TOP1_INV_CLK160_ADC_RESET                                       0x0
#define MERLIN_TOP1_PLL_ATB_LSB                                                15
#define MERLIN_TOP1_PLL_ATB_MSB                                                16
#define MERLIN_TOP1_PLL_ATB_MASK                                               0x18000
#define MERLIN_TOP1_PLL_ATB_GET(x)                                             (((x) & MERLIN_TOP1_PLL_ATB_MASK) >> MERLIN_TOP1_PLL_ATB_LSB)
#define MERLIN_TOP1_PLL_ATB_SET(x)                                             (((0 | (x)) << MERLIN_TOP1_PLL_ATB_LSB) & MERLIN_TOP1_PLL_ATB_MASK)
#define MERLIN_TOP1_PLL_ATB_RESET                                              0x0
#define MERLIN_TOP1_PLL_FILTER_LSB                                             7
#define MERLIN_TOP1_PLL_FILTER_MSB                                             14
#define MERLIN_TOP1_PLL_FILTER_MASK                                            0x7f80
#define MERLIN_TOP1_PLL_FILTER_GET(x)                                          (((x) & MERLIN_TOP1_PLL_FILTER_MASK) >> MERLIN_TOP1_PLL_FILTER_LSB)
#define MERLIN_TOP1_PLL_FILTER_SET(x)                                          (((0 | (x)) << MERLIN_TOP1_PLL_FILTER_LSB) & MERLIN_TOP1_PLL_FILTER_MASK)
#define MERLIN_TOP1_PLL_FILTER_RESET                                           0x34
#define MERLIN_TOP1_PLL_ICP_LSB                                                4
#define MERLIN_TOP1_PLL_ICP_MSB                                                6
#define MERLIN_TOP1_PLL_ICP_MASK                                               0x70
#define MERLIN_TOP1_PLL_ICP_GET(x)                                             (((x) & MERLIN_TOP1_PLL_ICP_MASK) >> MERLIN_TOP1_PLL_ICP_LSB)
#define MERLIN_TOP1_PLL_ICP_SET(x)                                             (((0 | (x)) << MERLIN_TOP1_PLL_ICP_LSB) & MERLIN_TOP1_PLL_ICP_MASK)
#define MERLIN_TOP1_PLL_ICP_RESET                                              0x5
#define MERLIN_TOP1_PLL_SCLAMP_LSB                                             1
#define MERLIN_TOP1_PLL_SCLAMP_MSB                                             3
#define MERLIN_TOP1_PLL_SCLAMP_MASK                                            0xe
#define MERLIN_TOP1_PLL_SCLAMP_GET(x)                                          (((x) & MERLIN_TOP1_PLL_SCLAMP_MASK) >> MERLIN_TOP1_PLL_SCLAMP_LSB)
#define MERLIN_TOP1_PLL_SCLAMP_SET(x)                                          (((0 | (x)) << MERLIN_TOP1_PLL_SCLAMP_LSB) & MERLIN_TOP1_PLL_SCLAMP_MASK)
#define MERLIN_TOP1_PLL_SCLAMP_RESET                                           0x5
#define MERLIN_TOP1_PLL_SVREG_LSB                                              0
#define MERLIN_TOP1_PLL_SVREG_MSB                                              0
#define MERLIN_TOP1_PLL_SVREG_MASK                                             0x1
#define MERLIN_TOP1_PLL_SVREG_GET(x)                                           (((x) & MERLIN_TOP1_PLL_SVREG_MASK) >> MERLIN_TOP1_PLL_SVREG_LSB)
#define MERLIN_TOP1_PLL_SVREG_SET(x)                                           (((0 | (x)) << MERLIN_TOP1_PLL_SVREG_LSB) & MERLIN_TOP1_PLL_SVREG_MASK)
#define MERLIN_TOP1_PLL_SVREG_RESET                                            0x1
#define MERLIN_TOP1_ADDRESS                                                    (0x90 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_TOP1_RSTMASK                                                    0xffffffff
#define MERLIN_TOP1_RESET                                                      0x1a5b

// 0x94 (MERLIN_TOP2)
#define MERLIN_TOP2_XPABIAS_LVL_LSB                                            30
#define MERLIN_TOP2_XPABIAS_LVL_MSB                                            31
#define MERLIN_TOP2_XPABIAS_LVL_MASK                                           0xc0000000
#define MERLIN_TOP2_XPABIAS_LVL_GET(x)                                         (((x) & MERLIN_TOP2_XPABIAS_LVL_MASK) >> MERLIN_TOP2_XPABIAS_LVL_LSB)
#define MERLIN_TOP2_XPABIAS_LVL_SET(x)                                         (((0 | (x)) << MERLIN_TOP2_XPABIAS_LVL_LSB) & MERLIN_TOP2_XPABIAS_LVL_MASK)
#define MERLIN_TOP2_XPABIAS_LVL_RESET                                          0x1
#define MERLIN_TOP2_FORCE_XLDO_ON_LSB                                          29
#define MERLIN_TOP2_FORCE_XLDO_ON_MSB                                          29
#define MERLIN_TOP2_FORCE_XLDO_ON_MASK                                         0x20000000
#define MERLIN_TOP2_FORCE_XLDO_ON_GET(x)                                       (((x) & MERLIN_TOP2_FORCE_XLDO_ON_MASK) >> MERLIN_TOP2_FORCE_XLDO_ON_LSB)
#define MERLIN_TOP2_FORCE_XLDO_ON_SET(x)                                       (((0 | (x)) << MERLIN_TOP2_FORCE_XLDO_ON_LSB) & MERLIN_TOP2_FORCE_XLDO_ON_MASK)
#define MERLIN_TOP2_FORCE_XLDO_ON_RESET                                        0x0
#define MERLIN_TOP2_XLNABUFMODE_LSB                                            28
#define MERLIN_TOP2_XLNABUFMODE_MSB                                            28
#define MERLIN_TOP2_XLNABUFMODE_MASK                                           0x10000000
#define MERLIN_TOP2_XLNABUFMODE_GET(x)                                         (((x) & MERLIN_TOP2_XLNABUFMODE_MASK) >> MERLIN_TOP2_XLNABUFMODE_LSB)
#define MERLIN_TOP2_XLNABUFMODE_SET(x)                                         (((0 | (x)) << MERLIN_TOP2_XLNABUFMODE_LSB) & MERLIN_TOP2_XLNABUFMODE_MASK)
#define MERLIN_TOP2_XLNABUFMODE_RESET                                          0x0
#define MERLIN_TOP2_XLNAISEL_LSB                                               26
#define MERLIN_TOP2_XLNAISEL_MSB                                               27
#define MERLIN_TOP2_XLNAISEL_MASK                                              0xc000000
#define MERLIN_TOP2_XLNAISEL_GET(x)                                            (((x) & MERLIN_TOP2_XLNAISEL_MASK) >> MERLIN_TOP2_XLNAISEL_LSB)
#define MERLIN_TOP2_XLNAISEL_SET(x)                                            (((0 | (x)) << MERLIN_TOP2_XLNAISEL_LSB) & MERLIN_TOP2_XLNAISEL_MASK)
#define MERLIN_TOP2_XLNAISEL_RESET                                             0x2
#define MERLIN_TOP2_XLNABUFIN_LSB                                              25
#define MERLIN_TOP2_XLNABUFIN_MSB                                              25
#define MERLIN_TOP2_XLNABUFIN_MASK                                             0x2000000
#define MERLIN_TOP2_XLNABUFIN_GET(x)                                           (((x) & MERLIN_TOP2_XLNABUFIN_MASK) >> MERLIN_TOP2_XLNABUFIN_LSB)
#define MERLIN_TOP2_XLNABUFIN_SET(x)                                           (((0 | (x)) << MERLIN_TOP2_XLNABUFIN_LSB) & MERLIN_TOP2_XLNABUFIN_MASK)
#define MERLIN_TOP2_XLNABUFIN_RESET                                            0x0
#define MERLIN_TOP2_NOTCXODET_LSB                                              24
#define MERLIN_TOP2_NOTCXODET_MSB                                              24
#define MERLIN_TOP2_NOTCXODET_MASK                                             0x1000000
#define MERLIN_TOP2_NOTCXODET_GET(x)                                           (((x) & MERLIN_TOP2_NOTCXODET_MASK) >> MERLIN_TOP2_NOTCXODET_LSB)
#define MERLIN_TOP2_NOTCXODET_SET(x)                                           (((0 | (x)) << MERLIN_TOP2_NOTCXODET_LSB) & MERLIN_TOP2_NOTCXODET_MASK)
#define MERLIN_TOP2_NOTCXODET_RESET                                            0x0
#define MERLIN_TOP2_PWDXINPAD_LSB                                              23
#define MERLIN_TOP2_PWDXINPAD_MSB                                              23
#define MERLIN_TOP2_PWDXINPAD_MASK                                             0x800000
#define MERLIN_TOP2_PWDXINPAD_GET(x)                                           (((x) & MERLIN_TOP2_PWDXINPAD_MASK) >> MERLIN_TOP2_PWDXINPAD_LSB)
#define MERLIN_TOP2_PWDXINPAD_SET(x)                                           (((0 | (x)) << MERLIN_TOP2_PWDXINPAD_LSB) & MERLIN_TOP2_PWDXINPAD_MASK)
#define MERLIN_TOP2_PWDXINPAD_RESET                                            0x0
#define MERLIN_TOP2_PWDCLKIND_LSB                                              22
#define MERLIN_TOP2_PWDCLKIND_MSB                                              22
#define MERLIN_TOP2_PWDCLKIND_MASK                                             0x400000
#define MERLIN_TOP2_PWDCLKIND_GET(x)                                           (((x) & MERLIN_TOP2_PWDCLKIND_MASK) >> MERLIN_TOP2_PWDCLKIND_LSB)
#define MERLIN_TOP2_PWDCLKIND_SET(x)                                           (((0 | (x)) << MERLIN_TOP2_PWDCLKIND_LSB) & MERLIN_TOP2_PWDCLKIND_MASK)
#define MERLIN_TOP2_PWDCLKIND_RESET                                            0x0
#define MERLIN_TOP2_LOCALBIAS_LSB                                              21
#define MERLIN_TOP2_LOCALBIAS_MSB                                              21
#define MERLIN_TOP2_LOCALBIAS_MASK                                             0x200000
#define MERLIN_TOP2_LOCALBIAS_GET(x)                                           (((x) & MERLIN_TOP2_LOCALBIAS_MASK) >> MERLIN_TOP2_LOCALBIAS_LSB)
#define MERLIN_TOP2_LOCALBIAS_SET(x)                                           (((0 | (x)) << MERLIN_TOP2_LOCALBIAS_LSB) & MERLIN_TOP2_LOCALBIAS_MASK)
#define MERLIN_TOP2_LOCALBIAS_RESET                                            0x0
#define MERLIN_TOP2_LOCALBIAS2X_LSB                                            20
#define MERLIN_TOP2_LOCALBIAS2X_MSB                                            20
#define MERLIN_TOP2_LOCALBIAS2X_MASK                                           0x100000
#define MERLIN_TOP2_LOCALBIAS2X_GET(x)                                         (((x) & MERLIN_TOP2_LOCALBIAS2X_MASK) >> MERLIN_TOP2_LOCALBIAS2X_LSB)
#define MERLIN_TOP2_LOCALBIAS2X_SET(x)                                         (((0 | (x)) << MERLIN_TOP2_LOCALBIAS2X_LSB) & MERLIN_TOP2_LOCALBIAS2X_MASK)
#define MERLIN_TOP2_LOCALBIAS2X_RESET                                          0x1
#define MERLIN_TOP2_XTALDIV_LSB                                                18
#define MERLIN_TOP2_XTALDIV_MSB                                                19
#define MERLIN_TOP2_XTALDIV_MASK                                               0xc0000
#define MERLIN_TOP2_XTALDIV_GET(x)                                             (((x) & MERLIN_TOP2_XTALDIV_MASK) >> MERLIN_TOP2_XTALDIV_LSB)
#define MERLIN_TOP2_XTALDIV_SET(x)                                             (((0 | (x)) << MERLIN_TOP2_XTALDIV_LSB) & MERLIN_TOP2_XTALDIV_MASK)
#define MERLIN_TOP2_XTALDIV_RESET                                              0x0
#define MERLIN_TOP2_TXPC_NEGOUT_LSB                                            17
#define MERLIN_TOP2_TXPC_NEGOUT_MSB                                            17
#define MERLIN_TOP2_TXPC_NEGOUT_MASK                                           0x20000
#define MERLIN_TOP2_TXPC_NEGOUT_GET(x)                                         (((x) & MERLIN_TOP2_TXPC_NEGOUT_MASK) >> MERLIN_TOP2_TXPC_NEGOUT_LSB)
#define MERLIN_TOP2_TXPC_NEGOUT_SET(x)                                         (((0 | (x)) << MERLIN_TOP2_TXPC_NEGOUT_LSB) & MERLIN_TOP2_TXPC_NEGOUT_MASK)
#define MERLIN_TOP2_TXPC_NEGOUT_RESET                                          0x0
#define MERLIN_TOP2_TXPC_TEST_LSB                                              16
#define MERLIN_TOP2_TXPC_TEST_MSB                                              16
#define MERLIN_TOP2_TXPC_TEST_MASK                                             0x10000
#define MERLIN_TOP2_TXPC_TEST_GET(x)                                           (((x) & MERLIN_TOP2_TXPC_TEST_MASK) >> MERLIN_TOP2_TXPC_TEST_LSB)
#define MERLIN_TOP2_TXPC_TEST_SET(x)                                           (((0 | (x)) << MERLIN_TOP2_TXPC_TEST_LSB) & MERLIN_TOP2_TXPC_TEST_MASK)
#define MERLIN_TOP2_TXPC_TEST_RESET                                            0x0
#define MERLIN_TOP2_TXPC_TESTDAC_LSB                                           10
#define MERLIN_TOP2_TXPC_TESTDAC_MSB                                           15
#define MERLIN_TOP2_TXPC_TESTDAC_MASK                                          0xfc00
#define MERLIN_TOP2_TXPC_TESTDAC_GET(x)                                        (((x) & MERLIN_TOP2_TXPC_TESTDAC_MASK) >> MERLIN_TOP2_TXPC_TESTDAC_LSB)
#define MERLIN_TOP2_TXPC_TESTDAC_SET(x)                                        (((0 | (x)) << MERLIN_TOP2_TXPC_TESTDAC_LSB) & MERLIN_TOP2_TXPC_TESTDAC_MASK)
#define MERLIN_TOP2_TXPC_TESTDAC_RESET                                         0x20
#define MERLIN_TOP2_TXPC_TESTGAIN_LSB                                          8
#define MERLIN_TOP2_TXPC_TESTGAIN_MSB                                          9
#define MERLIN_TOP2_TXPC_TESTGAIN_MASK                                         0x300
#define MERLIN_TOP2_TXPC_TESTGAIN_GET(x)                                       (((x) & MERLIN_TOP2_TXPC_TESTGAIN_MASK) >> MERLIN_TOP2_TXPC_TESTGAIN_LSB)
#define MERLIN_TOP2_TXPC_TESTGAIN_SET(x)                                       (((0 | (x)) << MERLIN_TOP2_TXPC_TESTGAIN_LSB) & MERLIN_TOP2_TXPC_TESTGAIN_MASK)
#define MERLIN_TOP2_TXPC_TESTGAIN_RESET                                        0x0
#define MERLIN_TOP2_TXPC_TESTPWD_LSB                                           7
#define MERLIN_TOP2_TXPC_TESTPWD_MSB                                           7
#define MERLIN_TOP2_TXPC_TESTPWD_MASK                                          0x80
#define MERLIN_TOP2_TXPC_TESTPWD_GET(x)                                        (((x) & MERLIN_TOP2_TXPC_TESTPWD_MASK) >> MERLIN_TOP2_TXPC_TESTPWD_LSB)
#define MERLIN_TOP2_TXPC_TESTPWD_SET(x)                                        (((0 | (x)) << MERLIN_TOP2_TXPC_TESTPWD_LSB) & MERLIN_TOP2_TXPC_TESTPWD_MASK)
#define MERLIN_TOP2_TXPC_TESTPWD_RESET                                         0x0
#define MERLIN_TOP2_TXPC_XPDBS_LSB                                             4
#define MERLIN_TOP2_TXPC_XPDBS_MSB                                             6
#define MERLIN_TOP2_TXPC_XPDBS_MASK                                            0x70
#define MERLIN_TOP2_TXPC_XPDBS_GET(x)                                          (((x) & MERLIN_TOP2_TXPC_XPDBS_MASK) >> MERLIN_TOP2_TXPC_XPDBS_LSB)
#define MERLIN_TOP2_TXPC_XPDBS_SET(x)                                          (((0 | (x)) << MERLIN_TOP2_TXPC_XPDBS_LSB) & MERLIN_TOP2_TXPC_XPDBS_MASK)
#define MERLIN_TOP2_TXPC_XPDBS_RESET                                           0x0
#define MERLIN_TOP2_TXPC_CLKDELAY_LSB                                          3
#define MERLIN_TOP2_TXPC_CLKDELAY_MSB                                          3
#define MERLIN_TOP2_TXPC_CLKDELAY_MASK                                         0x8
#define MERLIN_TOP2_TXPC_CLKDELAY_GET(x)                                       (((x) & MERLIN_TOP2_TXPC_CLKDELAY_MASK) >> MERLIN_TOP2_TXPC_CLKDELAY_LSB)
#define MERLIN_TOP2_TXPC_CLKDELAY_SET(x)                                       (((0 | (x)) << MERLIN_TOP2_TXPC_CLKDELAY_LSB) & MERLIN_TOP2_TXPC_CLKDELAY_MASK)
#define MERLIN_TOP2_TXPC_CLKDELAY_RESET                                        0x0
#define MERLIN_TOP2_DATAOUTSEL_LSB                                             1
#define MERLIN_TOP2_DATAOUTSEL_MSB                                             2
#define MERLIN_TOP2_DATAOUTSEL_MASK                                            0x6
#define MERLIN_TOP2_DATAOUTSEL_GET(x)                                          (((x) & MERLIN_TOP2_DATAOUTSEL_MASK) >> MERLIN_TOP2_DATAOUTSEL_LSB)
#define MERLIN_TOP2_DATAOUTSEL_SET(x)                                          (((0 | (x)) << MERLIN_TOP2_DATAOUTSEL_LSB) & MERLIN_TOP2_DATAOUTSEL_MASK)
#define MERLIN_TOP2_DATAOUTSEL_RESET                                           0x0
#define MERLIN_TOP2_BYPASSVREGLO_LSB                                           0
#define MERLIN_TOP2_BYPASSVREGLO_MSB                                           0
#define MERLIN_TOP2_BYPASSVREGLO_MASK                                          0x1
#define MERLIN_TOP2_BYPASSVREGLO_GET(x)                                        (((x) & MERLIN_TOP2_BYPASSVREGLO_MASK) >> MERLIN_TOP2_BYPASSVREGLO_LSB)
#define MERLIN_TOP2_BYPASSVREGLO_SET(x)                                        (((0 | (x)) << MERLIN_TOP2_BYPASSVREGLO_LSB) & MERLIN_TOP2_BYPASSVREGLO_MASK)
#define MERLIN_TOP2_BYPASSVREGLO_RESET                                         0x0
#define MERLIN_TOP2_ADDRESS                                                    (0x94 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_TOP2_RSTMASK                                                    0xffffffff
#define MERLIN_TOP2_RESET                                                      0x48108000

// 0x98 (MERLIN_TOP3)
#define MERLIN_TOP3_LOCALPLLDIV_LSB                                            31
#define MERLIN_TOP3_LOCALPLLDIV_MSB                                            31
#define MERLIN_TOP3_LOCALPLLDIV_MASK                                           0x80000000
#define MERLIN_TOP3_LOCALPLLDIV_GET(x)                                         (((x) & MERLIN_TOP3_LOCALPLLDIV_MASK) >> MERLIN_TOP3_LOCALPLLDIV_LSB)
#define MERLIN_TOP3_LOCALPLLDIV_SET(x)                                         (((0 | (x)) << MERLIN_TOP3_LOCALPLLDIV_LSB) & MERLIN_TOP3_LOCALPLLDIV_MASK)
#define MERLIN_TOP3_LOCALPLLDIV_RESET                                          0x0
#define MERLIN_TOP3_PLLREFDIVA_LSB                                             27
#define MERLIN_TOP3_PLLREFDIVA_MSB                                             30
#define MERLIN_TOP3_PLLREFDIVA_MASK                                            0x78000000
#define MERLIN_TOP3_PLLREFDIVA_GET(x)                                          (((x) & MERLIN_TOP3_PLLREFDIVA_MASK) >> MERLIN_TOP3_PLLREFDIVA_LSB)
#define MERLIN_TOP3_PLLREFDIVA_SET(x)                                          (((0 | (x)) << MERLIN_TOP3_PLLREFDIVA_LSB) & MERLIN_TOP3_PLLREFDIVA_MASK)
#define MERLIN_TOP3_PLLREFDIVA_RESET                                           0x5
#define MERLIN_TOP3_PLLREFDIVB_LSB                                             23
#define MERLIN_TOP3_PLLREFDIVB_MSB                                             26
#define MERLIN_TOP3_PLLREFDIVB_MASK                                            0x7800000
#define MERLIN_TOP3_PLLREFDIVB_GET(x)                                          (((x) & MERLIN_TOP3_PLLREFDIVB_MASK) >> MERLIN_TOP3_PLLREFDIVB_LSB)
#define MERLIN_TOP3_PLLREFDIVB_SET(x)                                          (((0 | (x)) << MERLIN_TOP3_PLLREFDIVB_LSB) & MERLIN_TOP3_PLLREFDIVB_MASK)
#define MERLIN_TOP3_PLLREFDIVB_RESET                                           0x5
#define MERLIN_TOP3_PLLFBDIVA_LSB                                              13
#define MERLIN_TOP3_PLLFBDIVA_MSB                                              22
#define MERLIN_TOP3_PLLFBDIVA_MASK                                             0x7fe000
#define MERLIN_TOP3_PLLFBDIVA_GET(x)                                           (((x) & MERLIN_TOP3_PLLFBDIVA_MASK) >> MERLIN_TOP3_PLLFBDIVA_LSB)
#define MERLIN_TOP3_PLLFBDIVA_SET(x)                                           (((0 | (x)) << MERLIN_TOP3_PLLFBDIVA_LSB) & MERLIN_TOP3_PLLFBDIVA_MASK)
#define MERLIN_TOP3_PLLFBDIVA_RESET                                            0x28
#define MERLIN_TOP3_PLLFBDIVB_LSB                                              3
#define MERLIN_TOP3_PLLFBDIVB_MSB                                              12
#define MERLIN_TOP3_PLLFBDIVB_MASK                                             0x1ff8
#define MERLIN_TOP3_PLLFBDIVB_GET(x)                                           (((x) & MERLIN_TOP3_PLLFBDIVB_MASK) >> MERLIN_TOP3_PLLFBDIVB_LSB)
#define MERLIN_TOP3_PLLFBDIVB_SET(x)                                           (((0 | (x)) << MERLIN_TOP3_PLLFBDIVB_LSB) & MERLIN_TOP3_PLLFBDIVB_MASK)
#define MERLIN_TOP3_PLLFBDIVB_RESET                                            0x2c
#define MERLIN_TOP3_VREGLO_ATBSEL_LSB                                          0
#define MERLIN_TOP3_VREGLO_ATBSEL_MSB                                          2
#define MERLIN_TOP3_VREGLO_ATBSEL_MASK                                         0x7
#define MERLIN_TOP3_VREGLO_ATBSEL_GET(x)                                       (((x) & MERLIN_TOP3_VREGLO_ATBSEL_MASK) >> MERLIN_TOP3_VREGLO_ATBSEL_LSB)
#define MERLIN_TOP3_VREGLO_ATBSEL_SET(x)                                       (((0 | (x)) << MERLIN_TOP3_VREGLO_ATBSEL_LSB) & MERLIN_TOP3_VREGLO_ATBSEL_MASK)
#define MERLIN_TOP3_VREGLO_ATBSEL_RESET                                        0x0
#define MERLIN_TOP3_ADDRESS                                                    (0x98 + __MERLIN2_0_RADIO_REG_BASE_ADDRESS)
#define MERLIN_TOP3_RSTMASK                                                    0xffffffff
#define MERLIN_TOP3_RESET                                                      0x2a850160



#endif /* _MERLIN2_0_RADIO_REG_H_ */
