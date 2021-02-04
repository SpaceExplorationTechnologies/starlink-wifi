// ------------------------------------------------------------------
// Copyright (c) 2004-2012 Qualcomm Atheros.  All rights reserved.
// $ATH_LICENSE_TARGET_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Qualcomm Atheros"
//===================================================================



#ifndef _MERLIN2_0_RADIO_REG_H_
#define _MERLIN2_0_RADIO_REG_H_


/* macros for RXTXBB1_CH1 */
#define RXTXBB1_CH1_ADDRESS                                                               0x00000000
#define RXTXBB1_CH1_OFFSET                                                                0x00000000
#define RXTXBB1_CH1_PDHIQ_MSB                                                                      0
#define RXTXBB1_CH1_PDHIQ_LSB                                                                      0
#define RXTXBB1_CH1_PDHIQ_MASK                                                            0x00000001
#define RXTXBB1_CH1_PDHIQ_GET(x)                                           (((x) & 0x00000001) >> 0)
#define RXTXBB1_CH1_PDHIQ_SET(x)                                           (((x) << 0) & 0x00000001)
#define RXTXBB1_CH1_PDLOQ_MSB                                                                      1
#define RXTXBB1_CH1_PDLOQ_LSB                                                                      1
#define RXTXBB1_CH1_PDLOQ_MASK                                                            0x00000002
#define RXTXBB1_CH1_PDLOQ_GET(x)                                           (((x) & 0x00000002) >> 1)
#define RXTXBB1_CH1_PDLOQ_SET(x)                                           (((x) << 1) & 0x00000002)
#define RXTXBB1_CH1_PDOFFSETI2V_MSB                                                                2
#define RXTXBB1_CH1_PDOFFSETI2V_LSB                                                                2
#define RXTXBB1_CH1_PDOFFSETI2V_MASK                                                      0x00000004
#define RXTXBB1_CH1_PDOFFSETI2V_GET(x)                                     (((x) & 0x00000004) >> 2)
#define RXTXBB1_CH1_PDOFFSETI2V_SET(x)                                     (((x) << 2) & 0x00000004)
#define RXTXBB1_CH1_PDOFFSETHIQ_MSB                                                                3
#define RXTXBB1_CH1_PDOFFSETHIQ_LSB                                                                3
#define RXTXBB1_CH1_PDOFFSETHIQ_MASK                                                      0x00000008
#define RXTXBB1_CH1_PDOFFSETHIQ_GET(x)                                     (((x) & 0x00000008) >> 3)
#define RXTXBB1_CH1_PDOFFSETHIQ_SET(x)                                     (((x) << 3) & 0x00000008)
#define RXTXBB1_CH1_PDOFFSETLOQ_MSB                                                                4
#define RXTXBB1_CH1_PDOFFSETLOQ_LSB                                                                4
#define RXTXBB1_CH1_PDOFFSETLOQ_MASK                                                      0x00000010
#define RXTXBB1_CH1_PDOFFSETLOQ_GET(x)                                     (((x) & 0x00000010) >> 4)
#define RXTXBB1_CH1_PDOFFSETLOQ_SET(x)                                     (((x) << 4) & 0x00000010)
#define RXTXBB1_CH1_PDRXTXBB_MSB                                                                   5
#define RXTXBB1_CH1_PDRXTXBB_LSB                                                                   5
#define RXTXBB1_CH1_PDRXTXBB_MASK                                                         0x00000020
#define RXTXBB1_CH1_PDRXTXBB_GET(x)                                        (((x) & 0x00000020) >> 5)
#define RXTXBB1_CH1_PDRXTXBB_SET(x)                                        (((x) << 5) & 0x00000020)
#define RXTXBB1_CH1_PDI2V_MSB                                                                      6
#define RXTXBB1_CH1_PDI2V_LSB                                                                      6
#define RXTXBB1_CH1_PDI2V_MASK                                                            0x00000040
#define RXTXBB1_CH1_PDI2V_GET(x)                                           (((x) & 0x00000040) >> 6)
#define RXTXBB1_CH1_PDI2V_SET(x)                                           (((x) << 6) & 0x00000040)
#define RXTXBB1_CH1_PDV2I_MSB                                                                      7
#define RXTXBB1_CH1_PDV2I_LSB                                                                      7
#define RXTXBB1_CH1_PDV2I_MASK                                                            0x00000080
#define RXTXBB1_CH1_PDV2I_GET(x)                                           (((x) & 0x00000080) >> 7)
#define RXTXBB1_CH1_PDV2I_SET(x)                                           (((x) << 7) & 0x00000080)
#define RXTXBB1_CH1_PDDACINTERFACE_MSB                                                             8
#define RXTXBB1_CH1_PDDACINTERFACE_LSB                                                             8
#define RXTXBB1_CH1_PDDACINTERFACE_MASK                                                   0x00000100
#define RXTXBB1_CH1_PDDACINTERFACE_GET(x)                                  (((x) & 0x00000100) >> 8)
#define RXTXBB1_CH1_PDDACINTERFACE_SET(x)                                  (((x) << 8) & 0x00000100)
#define RXTXBB1_CH1_SEL_ATB_MSB                                                                   16
#define RXTXBB1_CH1_SEL_ATB_LSB                                                                    9
#define RXTXBB1_CH1_SEL_ATB_MASK                                                          0x0001fe00
#define RXTXBB1_CH1_SEL_ATB_GET(x)                                         (((x) & 0x0001fe00) >> 9)
#define RXTXBB1_CH1_SEL_ATB_SET(x)                                         (((x) << 9) & 0x0001fe00)
#define RXTXBB1_CH1_FNOTCH_MSB                                                                    18
#define RXTXBB1_CH1_FNOTCH_LSB                                                                    17
#define RXTXBB1_CH1_FNOTCH_MASK                                                           0x00060000
#define RXTXBB1_CH1_FNOTCH_GET(x)                                         (((x) & 0x00060000) >> 17)
#define RXTXBB1_CH1_FNOTCH_SET(x)                                         (((x) << 17) & 0x00060000)
#define RXTXBB1_CH1_SPARE_MSB                                                                     31
#define RXTXBB1_CH1_SPARE_LSB                                                                     19
#define RXTXBB1_CH1_SPARE_MASK                                                            0xfff80000
#define RXTXBB1_CH1_SPARE_GET(x)                                          (((x) & 0xfff80000) >> 19)
#define RXTXBB1_CH1_SPARE_SET(x)                                          (((x) << 19) & 0xfff80000)

/* macros for RXTXBB2_CH1 */
#define RXTXBB2_CH1_ADDRESS                                                               0x00000004
#define RXTXBB2_CH1_OFFSET                                                                0x00000004
#define RXTXBB2_CH1_PATH_OVERRIDE_MSB                                                              0
#define RXTXBB2_CH1_PATH_OVERRIDE_LSB                                                              0
#define RXTXBB2_CH1_PATH_OVERRIDE_MASK                                                    0x00000001
#define RXTXBB2_CH1_PATH_OVERRIDE_GET(x)                                   (((x) & 0x00000001) >> 0)
#define RXTXBB2_CH1_PATH_OVERRIDE_SET(x)                                   (((x) << 0) & 0x00000001)
#define RXTXBB2_CH1_PATH1LOQ_EN_MSB                                                                1
#define RXTXBB2_CH1_PATH1LOQ_EN_LSB                                                                1
#define RXTXBB2_CH1_PATH1LOQ_EN_MASK                                                      0x00000002
#define RXTXBB2_CH1_PATH1LOQ_EN_GET(x)                                     (((x) & 0x00000002) >> 1)
#define RXTXBB2_CH1_PATH1LOQ_EN_SET(x)                                     (((x) << 1) & 0x00000002)
#define RXTXBB2_CH1_PATH2LOQ_EN_MSB                                                                2
#define RXTXBB2_CH1_PATH2LOQ_EN_LSB                                                                2
#define RXTXBB2_CH1_PATH2LOQ_EN_MASK                                                      0x00000004
#define RXTXBB2_CH1_PATH2LOQ_EN_GET(x)                                     (((x) & 0x00000004) >> 2)
#define RXTXBB2_CH1_PATH2LOQ_EN_SET(x)                                     (((x) << 2) & 0x00000004)
#define RXTXBB2_CH1_PATH3LOQ_EN_MSB                                                                3
#define RXTXBB2_CH1_PATH3LOQ_EN_LSB                                                                3
#define RXTXBB2_CH1_PATH3LOQ_EN_MASK                                                      0x00000008
#define RXTXBB2_CH1_PATH3LOQ_EN_GET(x)                                     (((x) & 0x00000008) >> 3)
#define RXTXBB2_CH1_PATH3LOQ_EN_SET(x)                                     (((x) << 3) & 0x00000008)
#define RXTXBB2_CH1_PATH1HIQ_EN_MSB                                                                4
#define RXTXBB2_CH1_PATH1HIQ_EN_LSB                                                                4
#define RXTXBB2_CH1_PATH1HIQ_EN_MASK                                                      0x00000010
#define RXTXBB2_CH1_PATH1HIQ_EN_GET(x)                                     (((x) & 0x00000010) >> 4)
#define RXTXBB2_CH1_PATH1HIQ_EN_SET(x)                                     (((x) << 4) & 0x00000010)
#define RXTXBB2_CH1_PATH2HIQ_EN_MSB                                                                5
#define RXTXBB2_CH1_PATH2HIQ_EN_LSB                                                                5
#define RXTXBB2_CH1_PATH2HIQ_EN_MASK                                                      0x00000020
#define RXTXBB2_CH1_PATH2HIQ_EN_GET(x)                                     (((x) & 0x00000020) >> 5)
#define RXTXBB2_CH1_PATH2HIQ_EN_SET(x)                                     (((x) << 5) & 0x00000020)
#define RXTXBB2_CH1_FILTERDOUBLEBW_MSB                                                             6
#define RXTXBB2_CH1_FILTERDOUBLEBW_LSB                                                             6
#define RXTXBB2_CH1_FILTERDOUBLEBW_MASK                                                   0x00000040
#define RXTXBB2_CH1_FILTERDOUBLEBW_GET(x)                                  (((x) & 0x00000040) >> 6)
#define RXTXBB2_CH1_FILTERDOUBLEBW_SET(x)                                  (((x) << 6) & 0x00000040)
#define RXTXBB2_CH1_LOCALFILTERTUNING_MSB                                                          7
#define RXTXBB2_CH1_LOCALFILTERTUNING_LSB                                                          7
#define RXTXBB2_CH1_LOCALFILTERTUNING_MASK                                                0x00000080
#define RXTXBB2_CH1_LOCALFILTERTUNING_GET(x)                               (((x) & 0x00000080) >> 7)
#define RXTXBB2_CH1_LOCALFILTERTUNING_SET(x)                               (((x) << 7) & 0x00000080)
#define RXTXBB2_CH1_FILTERFC_MSB                                                                  12
#define RXTXBB2_CH1_FILTERFC_LSB                                                                   8
#define RXTXBB2_CH1_FILTERFC_MASK                                                         0x00001f00
#define RXTXBB2_CH1_FILTERFC_GET(x)                                        (((x) & 0x00001f00) >> 8)
#define RXTXBB2_CH1_FILTERFC_SET(x)                                        (((x) << 8) & 0x00001f00)
#define RXTXBB2_CH1_CMSEL_MSB                                                                     14
#define RXTXBB2_CH1_CMSEL_LSB                                                                     13
#define RXTXBB2_CH1_CMSEL_MASK                                                            0x00006000
#define RXTXBB2_CH1_CMSEL_GET(x)                                          (((x) & 0x00006000) >> 13)
#define RXTXBB2_CH1_CMSEL_SET(x)                                          (((x) << 13) & 0x00006000)
#define RXTXBB2_CH1_SEL_I2V_TEST_MSB                                                              15
#define RXTXBB2_CH1_SEL_I2V_TEST_LSB                                                              15
#define RXTXBB2_CH1_SEL_I2V_TEST_MASK                                                     0x00008000
#define RXTXBB2_CH1_SEL_I2V_TEST_GET(x)                                   (((x) & 0x00008000) >> 15)
#define RXTXBB2_CH1_SEL_I2V_TEST_SET(x)                                   (((x) << 15) & 0x00008000)
#define RXTXBB2_CH1_SEL_HIQ_TEST_MSB                                                              16
#define RXTXBB2_CH1_SEL_HIQ_TEST_LSB                                                              16
#define RXTXBB2_CH1_SEL_HIQ_TEST_MASK                                                     0x00010000
#define RXTXBB2_CH1_SEL_HIQ_TEST_GET(x)                                   (((x) & 0x00010000) >> 16)
#define RXTXBB2_CH1_SEL_HIQ_TEST_SET(x)                                   (((x) << 16) & 0x00010000)
#define RXTXBB2_CH1_SEL_LOQ_TEST_MSB                                                              17
#define RXTXBB2_CH1_SEL_LOQ_TEST_LSB                                                              17
#define RXTXBB2_CH1_SEL_LOQ_TEST_MASK                                                     0x00020000
#define RXTXBB2_CH1_SEL_LOQ_TEST_GET(x)                                   (((x) & 0x00020000) >> 17)
#define RXTXBB2_CH1_SEL_LOQ_TEST_SET(x)                                   (((x) << 17) & 0x00020000)
#define RXTXBB2_CH1_SEL_DAC_TEST_MSB                                                              18
#define RXTXBB2_CH1_SEL_DAC_TEST_LSB                                                              18
#define RXTXBB2_CH1_SEL_DAC_TEST_MASK                                                     0x00040000
#define RXTXBB2_CH1_SEL_DAC_TEST_GET(x)                                   (((x) & 0x00040000) >> 18)
#define RXTXBB2_CH1_SEL_DAC_TEST_SET(x)                                   (((x) << 18) & 0x00040000)
#define RXTXBB2_CH1_SELBUFFER_MSB                                                                 19
#define RXTXBB2_CH1_SELBUFFER_LSB                                                                 19
#define RXTXBB2_CH1_SELBUFFER_MASK                                                        0x00080000
#define RXTXBB2_CH1_SELBUFFER_GET(x)                                      (((x) & 0x00080000) >> 19)
#define RXTXBB2_CH1_SELBUFFER_SET(x)                                      (((x) << 19) & 0x00080000)
#define RXTXBB2_CH1_SHORTBUFFER_MSB                                                               20
#define RXTXBB2_CH1_SHORTBUFFER_LSB                                                               20
#define RXTXBB2_CH1_SHORTBUFFER_MASK                                                      0x00100000
#define RXTXBB2_CH1_SHORTBUFFER_GET(x)                                    (((x) & 0x00100000) >> 20)
#define RXTXBB2_CH1_SHORTBUFFER_SET(x)                                    (((x) << 20) & 0x00100000)
#define RXTXBB2_CH1_SPARE_MSB                                                                     22
#define RXTXBB2_CH1_SPARE_LSB                                                                     21
#define RXTXBB2_CH1_SPARE_MASK                                                            0x00600000
#define RXTXBB2_CH1_SPARE_GET(x)                                          (((x) & 0x00600000) >> 21)
#define RXTXBB2_CH1_SPARE_SET(x)                                          (((x) << 21) & 0x00600000)
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_MSB                                                       25
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_LSB                                                       23
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_MASK                                              0x03800000
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_GET(x)                            (((x) & 0x03800000) >> 23)
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_SET(x)                            (((x) << 23) & 0x03800000)
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_MSB                                                        28
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_LSB                                                        26
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_MASK                                               0x1c000000
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_GET(x)                             (((x) & 0x1c000000) >> 26)
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_SET(x)                             (((x) << 26) & 0x1c000000)
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_MSB                                                        31
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_LSB                                                        29
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_MASK                                               0xe0000000
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_GET(x)                             (((x) & 0xe0000000) >> 29)
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_SET(x)                             (((x) << 29) & 0xe0000000)

/* macros for RXTXBB3_CH1 */
#define RXTXBB3_CH1_ADDRESS                                                               0x00000008
#define RXTXBB3_CH1_OFFSET                                                                0x00000008
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_MSB                                                         2
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_LSB                                                         0
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_MASK                                               0x00000007
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_GET(x)                              (((x) & 0x00000007) >> 0)
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_SET(x)                              (((x) << 0) & 0x00000007)
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_MSB                                                          5
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_LSB                                                          3
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_MASK                                                0x00000038
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_GET(x)                               (((x) & 0x00000038) >> 3)
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_SET(x)                               (((x) << 3) & 0x00000038)
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_MSB                                                           8
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_LSB                                                           6
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_MASK                                                 0x000001c0
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_GET(x)                                (((x) & 0x000001c0) >> 6)
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_SET(x)                                (((x) << 6) & 0x000001c0)
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_MSB                                                          11
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_LSB                                                           9
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_MASK                                                 0x00000e00
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_GET(x)                                (((x) & 0x00000e00) >> 9)
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_SET(x)                                (((x) << 9) & 0x00000e00)
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_MSB                                                          14
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_LSB                                                          12
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_MASK                                                 0x00007000
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_GET(x)                               (((x) & 0x00007000) >> 12)
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_SET(x)                               (((x) << 12) & 0x00007000)
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_MSB                                                          17
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_LSB                                                          15
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_MASK                                                 0x00038000
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_GET(x)                               (((x) & 0x00038000) >> 15)
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_SET(x)                               (((x) << 15) & 0x00038000)
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_MSB                                                          20
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_LSB                                                          18
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_MASK                                                 0x001c0000
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_GET(x)                               (((x) & 0x001c0000) >> 18)
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_SET(x)                               (((x) << 18) & 0x001c0000)
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_MSB                                                        23
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_LSB                                                        21
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_MASK                                               0x00e00000
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_GET(x)                             (((x) & 0x00e00000) >> 21)
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_SET(x)                             (((x) << 21) & 0x00e00000)
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_MSB                                                    26
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_LSB                                                    24
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_MASK                                           0x07000000
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_GET(x)                         (((x) & 0x07000000) >> 24)
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_SET(x)                         (((x) << 24) & 0x07000000)
#define RXTXBB3_CH1_SPARE_MSB                                                                     31
#define RXTXBB3_CH1_SPARE_LSB                                                                     27
#define RXTXBB3_CH1_SPARE_MASK                                                            0xf8000000
#define RXTXBB3_CH1_SPARE_GET(x)                                          (((x) & 0xf8000000) >> 27)
#define RXTXBB3_CH1_SPARE_SET(x)                                          (((x) << 27) & 0xf8000000)

/* macros for RXTXBB4_CH1 */
#define RXTXBB4_CH1_ADDRESS                                                               0x0000000c
#define RXTXBB4_CH1_OFFSET                                                                0x0000000c
#define RXTXBB4_CH1_OFSTCORRI2VQ_MSB                                                               4
#define RXTXBB4_CH1_OFSTCORRI2VQ_LSB                                                               0
#define RXTXBB4_CH1_OFSTCORRI2VQ_MASK                                                     0x0000001f
#define RXTXBB4_CH1_OFSTCORRI2VQ_GET(x)                                    (((x) & 0x0000001f) >> 0)
#define RXTXBB4_CH1_OFSTCORRI2VQ_SET(x)                                    (((x) << 0) & 0x0000001f)
#define RXTXBB4_CH1_OFSTCORRI2VI_MSB                                                               9
#define RXTXBB4_CH1_OFSTCORRI2VI_LSB                                                               5
#define RXTXBB4_CH1_OFSTCORRI2VI_MASK                                                     0x000003e0
#define RXTXBB4_CH1_OFSTCORRI2VI_GET(x)                                    (((x) & 0x000003e0) >> 5)
#define RXTXBB4_CH1_OFSTCORRI2VI_SET(x)                                    (((x) << 5) & 0x000003e0)
#define RXTXBB4_CH1_OFSTCORRLOQ_MSB                                                               14
#define RXTXBB4_CH1_OFSTCORRLOQ_LSB                                                               10
#define RXTXBB4_CH1_OFSTCORRLOQ_MASK                                                      0x00007c00
#define RXTXBB4_CH1_OFSTCORRLOQ_GET(x)                                    (((x) & 0x00007c00) >> 10)
#define RXTXBB4_CH1_OFSTCORRLOQ_SET(x)                                    (((x) << 10) & 0x00007c00)
#define RXTXBB4_CH1_OFSTCORRLOI_MSB                                                               19
#define RXTXBB4_CH1_OFSTCORRLOI_LSB                                                               15
#define RXTXBB4_CH1_OFSTCORRLOI_MASK                                                      0x000f8000
#define RXTXBB4_CH1_OFSTCORRLOI_GET(x)                                    (((x) & 0x000f8000) >> 15)
#define RXTXBB4_CH1_OFSTCORRLOI_SET(x)                                    (((x) << 15) & 0x000f8000)
#define RXTXBB4_CH1_OFSTCORRHIQ_MSB                                                               24
#define RXTXBB4_CH1_OFSTCORRHIQ_LSB                                                               20
#define RXTXBB4_CH1_OFSTCORRHIQ_MASK                                                      0x01f00000
#define RXTXBB4_CH1_OFSTCORRHIQ_GET(x)                                    (((x) & 0x01f00000) >> 20)
#define RXTXBB4_CH1_OFSTCORRHIQ_SET(x)                                    (((x) << 20) & 0x01f00000)
#define RXTXBB4_CH1_OFSTCORRHII_MSB                                                               29
#define RXTXBB4_CH1_OFSTCORRHII_LSB                                                               25
#define RXTXBB4_CH1_OFSTCORRHII_MASK                                                      0x3e000000
#define RXTXBB4_CH1_OFSTCORRHII_GET(x)                                    (((x) & 0x3e000000) >> 25)
#define RXTXBB4_CH1_OFSTCORRHII_SET(x)                                    (((x) << 25) & 0x3e000000)
#define RXTXBB4_CH1_LOCALOFFSET_MSB                                                               30
#define RXTXBB4_CH1_LOCALOFFSET_LSB                                                               30
#define RXTXBB4_CH1_LOCALOFFSET_MASK                                                      0x40000000
#define RXTXBB4_CH1_LOCALOFFSET_GET(x)                                    (((x) & 0x40000000) >> 30)
#define RXTXBB4_CH1_LOCALOFFSET_SET(x)                                    (((x) << 30) & 0x40000000)
#define RXTXBB4_CH1_SPARE_MSB                                                                     31
#define RXTXBB4_CH1_SPARE_LSB                                                                     31
#define RXTXBB4_CH1_SPARE_MASK                                                            0x80000000
#define RXTXBB4_CH1_SPARE_GET(x)                                          (((x) & 0x80000000) >> 31)
#define RXTXBB4_CH1_SPARE_SET(x)                                          (((x) << 31) & 0x80000000)

/* macros for RF2G1_CH1 */
#define RF2G1_CH1_ADDRESS                                                                 0x00000010
#define RF2G1_CH1_OFFSET                                                                  0x00000010
#define RF2G1_CH1_SPARES_MSB                                                                       5
#define RF2G1_CH1_SPARES_LSB                                                                       0
#define RF2G1_CH1_SPARES_MASK                                                             0x0000003f
#define RF2G1_CH1_SPARES_GET(x)                                            (((x) & 0x0000003f) >> 0)
#define RF2G1_CH1_SPARES_SET(x)                                            (((x) << 0) & 0x0000003f)
#define RF2G1_CH1_REGLO_BYPASS_MSB                                                                 6
#define RF2G1_CH1_REGLO_BYPASS_LSB                                                                 6
#define RF2G1_CH1_REGLO_BYPASS_MASK                                                       0x00000040
#define RF2G1_CH1_REGLO_BYPASS_GET(x)                                      (((x) & 0x00000040) >> 6)
#define RF2G1_CH1_REGLO_BYPASS_SET(x)                                      (((x) << 6) & 0x00000040)
#define RF2G1_CH1_REGLNA_BYPASS_MSB                                                                7
#define RF2G1_CH1_REGLNA_BYPASS_LSB                                                                7
#define RF2G1_CH1_REGLNA_BYPASS_MASK                                                      0x00000080
#define RF2G1_CH1_REGLNA_BYPASS_GET(x)                                     (((x) & 0x00000080) >> 7)
#define RF2G1_CH1_REGLNA_BYPASS_SET(x)                                     (((x) << 7) & 0x00000080)
#define RF2G1_CH1_PDIC25U_VGM_MSB                                                                 10
#define RF2G1_CH1_PDIC25U_VGM_LSB                                                                  8
#define RF2G1_CH1_PDIC25U_VGM_MASK                                                        0x00000700
#define RF2G1_CH1_PDIC25U_VGM_GET(x)                                       (((x) & 0x00000700) >> 8)
#define RF2G1_CH1_PDIC25U_VGM_SET(x)                                       (((x) << 8) & 0x00000700)
#define RF2G1_CH1_PACA_SEL_MSB                                                                    12
#define RF2G1_CH1_PACA_SEL_LSB                                                                    11
#define RF2G1_CH1_PACA_SEL_MASK                                                           0x00001800
#define RF2G1_CH1_PACA_SEL_GET(x)                                         (((x) & 0x00001800) >> 11)
#define RF2G1_CH1_PACA_SEL_SET(x)                                         (((x) << 11) & 0x00001800)
#define RF2G1_CH1_LOCONTROL_MSB                                                                   13
#define RF2G1_CH1_LOCONTROL_LSB                                                                   13
#define RF2G1_CH1_LOCONTROL_MASK                                                          0x00002000
#define RF2G1_CH1_LOCONTROL_GET(x)                                        (((x) & 0x00002000) >> 13)
#define RF2G1_CH1_LOCONTROL_SET(x)                                        (((x) << 13) & 0x00002000)
#define RF2G1_CH1_TXATB_SEL_MSB                                                                   16
#define RF2G1_CH1_TXATB_SEL_LSB                                                                   14
#define RF2G1_CH1_TXATB_SEL_MASK                                                          0x0001c000
#define RF2G1_CH1_TXATB_SEL_GET(x)                                        (((x) & 0x0001c000) >> 14)
#define RF2G1_CH1_TXATB_SEL_SET(x)                                        (((x) << 14) & 0x0001c000)
#define RF2G1_CH1_RXATB_SEL_MSB                                                                   19
#define RF2G1_CH1_RXATB_SEL_LSB                                                                   17
#define RF2G1_CH1_RXATB_SEL_MASK                                                          0x000e0000
#define RF2G1_CH1_RXATB_SEL_GET(x)                                        (((x) & 0x000e0000) >> 17)
#define RF2G1_CH1_RXATB_SEL_SET(x)                                        (((x) << 17) & 0x000e0000)
#define RF2G1_CH1_LOATB_SEL_MSB                                                                   22
#define RF2G1_CH1_LOATB_SEL_LSB                                                                   20
#define RF2G1_CH1_LOATB_SEL_MASK                                                          0x00700000
#define RF2G1_CH1_LOATB_SEL_GET(x)                                        (((x) & 0x00700000) >> 20)
#define RF2G1_CH1_LOATB_SEL_SET(x)                                        (((x) << 20) & 0x00700000)
#define RF2G1_CH1_OB_MSB                                                                          25
#define RF2G1_CH1_OB_LSB                                                                          23
#define RF2G1_CH1_OB_MASK                                                                 0x03800000
#define RF2G1_CH1_OB_GET(x)                                               (((x) & 0x03800000) >> 23)
#define RF2G1_CH1_OB_SET(x)                                               (((x) << 23) & 0x03800000)
#define RF2G1_CH1_DB_MSB                                                                          28
#define RF2G1_CH1_DB_LSB                                                                          26
#define RF2G1_CH1_DB_MASK                                                                 0x1c000000
#define RF2G1_CH1_DB_GET(x)                                               (((x) & 0x1c000000) >> 26)
#define RF2G1_CH1_DB_SET(x)                                               (((x) << 26) & 0x1c000000)
#define RF2G1_CH1_PDIC25U_LNA_MSB                                                                 31
#define RF2G1_CH1_PDIC25U_LNA_LSB                                                                 29
#define RF2G1_CH1_PDIC25U_LNA_MASK                                                        0xe0000000
#define RF2G1_CH1_PDIC25U_LNA_GET(x)                                      (((x) & 0xe0000000) >> 29)
#define RF2G1_CH1_PDIC25U_LNA_SET(x)                                      (((x) << 29) & 0xe0000000)

/* macros for RF2G2_CH1 */
#define RF2G2_CH1_ADDRESS                                                                 0x00000014
#define RF2G2_CH1_OFFSET                                                                  0x00000014
#define RF2G2_CH1_PDIR25U_VREGLO_MSB                                                               2
#define RF2G2_CH1_PDIR25U_VREGLO_LSB                                                               0
#define RF2G2_CH1_PDIR25U_VREGLO_MASK                                                     0x00000007
#define RF2G2_CH1_PDIR25U_VREGLO_GET(x)                                    (((x) & 0x00000007) >> 0)
#define RF2G2_CH1_PDIR25U_VREGLO_SET(x)                                    (((x) << 0) & 0x00000007)
#define RF2G2_CH1_PDIC25U_VREGLO_MSB                                                               5
#define RF2G2_CH1_PDIC25U_VREGLO_LSB                                                               3
#define RF2G2_CH1_PDIC25U_VREGLO_MASK                                                     0x00000038
#define RF2G2_CH1_PDIC25U_VREGLO_GET(x)                                    (((x) & 0x00000038) >> 3)
#define RF2G2_CH1_PDIC25U_VREGLO_SET(x)                                    (((x) << 3) & 0x00000038)
#define RF2G2_CH1_PDIC50U_DIV_MSB                                                                  8
#define RF2G2_CH1_PDIC50U_DIV_LSB                                                                  6
#define RF2G2_CH1_PDIC50U_DIV_MASK                                                        0x000001c0
#define RF2G2_CH1_PDIC50U_DIV_GET(x)                                       (((x) & 0x000001c0) >> 6)
#define RF2G2_CH1_PDIC50U_DIV_SET(x)                                       (((x) << 6) & 0x000001c0)
#define RF2G2_CH1_PDIC25U_RXRF_MSB                                                                11
#define RF2G2_CH1_PDIC25U_RXRF_LSB                                                                 9
#define RF2G2_CH1_PDIC25U_RXRF_MASK                                                       0x00000e00
#define RF2G2_CH1_PDIC25U_RXRF_GET(x)                                      (((x) & 0x00000e00) >> 9)
#define RF2G2_CH1_PDIC25U_RXRF_SET(x)                                      (((x) << 9) & 0x00000e00)
#define RF2G2_CH1_PDIC25U_TXRF_MSB                                                                14
#define RF2G2_CH1_PDIC25U_TXRF_LSB                                                                12
#define RF2G2_CH1_PDIC25U_TXRF_MASK                                                       0x00007000
#define RF2G2_CH1_PDIC25U_TXRF_GET(x)                                     (((x) & 0x00007000) >> 12)
#define RF2G2_CH1_PDIC25U_TXRF_SET(x)                                     (((x) << 12) & 0x00007000)
#define RF2G2_CH1_PDIC25U_TXPA_MSB                                                                17
#define RF2G2_CH1_PDIC25U_TXPA_LSB                                                                15
#define RF2G2_CH1_PDIC25U_TXPA_MASK                                                       0x00038000
#define RF2G2_CH1_PDIC25U_TXPA_GET(x)                                     (((x) & 0x00038000) >> 15)
#define RF2G2_CH1_PDIC25U_TXPA_SET(x)                                     (((x) << 15) & 0x00038000)
#define RF2G2_CH1_PDIR25U_TXPA_MSB                                                                18
#define RF2G2_CH1_PDIR25U_TXPA_LSB                                                                18
#define RF2G2_CH1_PDIR25U_TXPA_MASK                                                       0x00040000
#define RF2G2_CH1_PDIR25U_TXPA_GET(x)                                     (((x) & 0x00040000) >> 18)
#define RF2G2_CH1_PDIR25U_TXPA_SET(x)                                     (((x) << 18) & 0x00040000)
#define RF2G2_CH1_PDIR25U_TXMIX_MSB                                                               21
#define RF2G2_CH1_PDIR25U_TXMIX_LSB                                                               19
#define RF2G2_CH1_PDIR25U_TXMIX_MASK                                                      0x00380000
#define RF2G2_CH1_PDIR25U_TXMIX_GET(x)                                    (((x) & 0x00380000) >> 19)
#define RF2G2_CH1_PDIR25U_TXMIX_SET(x)                                    (((x) << 19) & 0x00380000)
#define RF2G2_CH1_PDTXMIX_MSB                                                                     22
#define RF2G2_CH1_PDTXMIX_LSB                                                                     22
#define RF2G2_CH1_PDTXMIX_MASK                                                            0x00400000
#define RF2G2_CH1_PDTXMIX_GET(x)                                          (((x) & 0x00400000) >> 22)
#define RF2G2_CH1_PDTXMIX_SET(x)                                          (((x) << 22) & 0x00400000)
#define RF2G2_CH1_PDTXLO_MSB                                                                      23
#define RF2G2_CH1_PDTXLO_LSB                                                                      23
#define RF2G2_CH1_PDTXLO_MASK                                                             0x00800000
#define RF2G2_CH1_PDTXLO_GET(x)                                           (((x) & 0x00800000) >> 23)
#define RF2G2_CH1_PDTXLO_SET(x)                                           (((x) << 23) & 0x00800000)
#define RF2G2_CH1_PDRXLO_MSB                                                                      24
#define RF2G2_CH1_PDRXLO_LSB                                                                      24
#define RF2G2_CH1_PDRXLO_MASK                                                             0x01000000
#define RF2G2_CH1_PDRXLO_GET(x)                                           (((x) & 0x01000000) >> 24)
#define RF2G2_CH1_PDRXLO_SET(x)                                           (((x) << 24) & 0x01000000)
#define RF2G2_CH1_PDVGM_MSB                                                                       25
#define RF2G2_CH1_PDVGM_LSB                                                                       25
#define RF2G2_CH1_PDVGM_MASK                                                              0x02000000
#define RF2G2_CH1_PDVGM_GET(x)                                            (((x) & 0x02000000) >> 25)
#define RF2G2_CH1_PDVGM_SET(x)                                            (((x) << 25) & 0x02000000)
#define RF2G2_CH1_PDREGLO_MSB                                                                     26
#define RF2G2_CH1_PDREGLO_LSB                                                                     26
#define RF2G2_CH1_PDREGLO_MASK                                                            0x04000000
#define RF2G2_CH1_PDREGLO_GET(x)                                          (((x) & 0x04000000) >> 26)
#define RF2G2_CH1_PDREGLO_SET(x)                                          (((x) << 26) & 0x04000000)
#define RF2G2_CH1_PDREGLNA_MSB                                                                    27
#define RF2G2_CH1_PDREGLNA_LSB                                                                    27
#define RF2G2_CH1_PDREGLNA_MASK                                                           0x08000000
#define RF2G2_CH1_PDREGLNA_GET(x)                                         (((x) & 0x08000000) >> 27)
#define RF2G2_CH1_PDREGLNA_SET(x)                                         (((x) << 27) & 0x08000000)
#define RF2G2_CH1_PDPAOUT_MSB                                                                     28
#define RF2G2_CH1_PDPAOUT_LSB                                                                     28
#define RF2G2_CH1_PDPAOUT_MASK                                                            0x10000000
#define RF2G2_CH1_PDPAOUT_GET(x)                                          (((x) & 0x10000000) >> 28)
#define RF2G2_CH1_PDPAOUT_SET(x)                                          (((x) << 28) & 0x10000000)
#define RF2G2_CH1_PDPADRV_MSB                                                                     29
#define RF2G2_CH1_PDPADRV_LSB                                                                     29
#define RF2G2_CH1_PDPADRV_MASK                                                            0x20000000
#define RF2G2_CH1_PDPADRV_GET(x)                                          (((x) & 0x20000000) >> 29)
#define RF2G2_CH1_PDPADRV_SET(x)                                          (((x) << 29) & 0x20000000)
#define RF2G2_CH1_PDDIV_MSB                                                                       30
#define RF2G2_CH1_PDDIV_LSB                                                                       30
#define RF2G2_CH1_PDDIV_MASK                                                              0x40000000
#define RF2G2_CH1_PDDIV_GET(x)                                            (((x) & 0x40000000) >> 30)
#define RF2G2_CH1_PDDIV_SET(x)                                            (((x) << 30) & 0x40000000)
#define RF2G2_CH1_PDLNA_MSB                                                                       31
#define RF2G2_CH1_PDLNA_LSB                                                                       31
#define RF2G2_CH1_PDLNA_MASK                                                              0x80000000
#define RF2G2_CH1_PDLNA_GET(x)                                            (((x) & 0x80000000) >> 31)
#define RF2G2_CH1_PDLNA_SET(x)                                            (((x) << 31) & 0x80000000)

/* macros for RF5G1_CH1 */
#define RF5G1_CH1_ADDRESS                                                                 0x00000018
#define RF5G1_CH1_OFFSET                                                                  0x00000018
#define RF5G1_CH1_SPARE_MSB                                                                        9
#define RF5G1_CH1_SPARE_LSB                                                                        0
#define RF5G1_CH1_SPARE_MASK                                                              0x000003ff
#define RF5G1_CH1_SPARE_GET(x)                                             (((x) & 0x000003ff) >> 0)
#define RF5G1_CH1_SPARE_SET(x)                                             (((x) << 0) & 0x000003ff)
#define RF5G1_CH1_PDREGLO5_MSB                                                                    10
#define RF5G1_CH1_PDREGLO5_LSB                                                                    10
#define RF5G1_CH1_PDREGLO5_MASK                                                           0x00000400
#define RF5G1_CH1_PDREGLO5_GET(x)                                         (((x) & 0x00000400) >> 10)
#define RF5G1_CH1_PDREGLO5_SET(x)                                         (((x) << 10) & 0x00000400)
#define RF5G1_CH1_REGLO_BYPASS5_MSB                                                               11
#define RF5G1_CH1_REGLO_BYPASS5_LSB                                                               11
#define RF5G1_CH1_REGLO_BYPASS5_MASK                                                      0x00000800
#define RF5G1_CH1_REGLO_BYPASS5_GET(x)                                    (((x) & 0x00000800) >> 11)
#define RF5G1_CH1_REGLO_BYPASS5_SET(x)                                    (((x) << 11) & 0x00000800)
#define RF5G1_CH1_LO5CONTROL_MSB                                                                  12
#define RF5G1_CH1_LO5CONTROL_LSB                                                                  12
#define RF5G1_CH1_LO5CONTROL_MASK                                                         0x00001000
#define RF5G1_CH1_LO5CONTROL_GET(x)                                       (((x) & 0x00001000) >> 12)
#define RF5G1_CH1_LO5CONTROL_SET(x)                                       (((x) << 12) & 0x00001000)
#define RF5G1_CH1_TX5_ATB_SEL_MSB                                                                 15
#define RF5G1_CH1_TX5_ATB_SEL_LSB                                                                 13
#define RF5G1_CH1_TX5_ATB_SEL_MASK                                                        0x0000e000
#define RF5G1_CH1_TX5_ATB_SEL_GET(x)                                      (((x) & 0x0000e000) >> 13)
#define RF5G1_CH1_TX5_ATB_SEL_SET(x)                                      (((x) << 13) & 0x0000e000)
#define RF5G1_CH1_OB5_MSB                                                                         18
#define RF5G1_CH1_OB5_LSB                                                                         16
#define RF5G1_CH1_OB5_MASK                                                                0x00070000
#define RF5G1_CH1_OB5_GET(x)                                              (((x) & 0x00070000) >> 16)
#define RF5G1_CH1_OB5_SET(x)                                              (((x) << 16) & 0x00070000)
#define RF5G1_CH1_DB5_MSB                                                                         21
#define RF5G1_CH1_DB5_LSB                                                                         19
#define RF5G1_CH1_DB5_MASK                                                                0x00380000
#define RF5G1_CH1_DB5_GET(x)                                              (((x) & 0x00380000) >> 19)
#define RF5G1_CH1_DB5_SET(x)                                              (((x) << 19) & 0x00380000)
#define RF5G1_CH1_PWDTXPKD_MSB                                                                    24
#define RF5G1_CH1_PWDTXPKD_LSB                                                                    22
#define RF5G1_CH1_PWDTXPKD_MASK                                                           0x01c00000
#define RF5G1_CH1_PWDTXPKD_GET(x)                                         (((x) & 0x01c00000) >> 22)
#define RF5G1_CH1_PWDTXPKD_SET(x)                                         (((x) << 22) & 0x01c00000)
#define RF5G1_CH1_PACASCBIAS_MSB                                                                  26
#define RF5G1_CH1_PACASCBIAS_LSB                                                                  25
#define RF5G1_CH1_PACASCBIAS_MASK                                                         0x06000000
#define RF5G1_CH1_PACASCBIAS_GET(x)                                       (((x) & 0x06000000) >> 25)
#define RF5G1_CH1_PACASCBIAS_SET(x)                                       (((x) << 25) & 0x06000000)
#define RF5G1_CH1_PDPAOUT5_MSB                                                                    27
#define RF5G1_CH1_PDPAOUT5_LSB                                                                    27
#define RF5G1_CH1_PDPAOUT5_MASK                                                           0x08000000
#define RF5G1_CH1_PDPAOUT5_GET(x)                                         (((x) & 0x08000000) >> 27)
#define RF5G1_CH1_PDPAOUT5_SET(x)                                         (((x) << 27) & 0x08000000)
#define RF5G1_CH1_PDPADRV5_MSB                                                                    28
#define RF5G1_CH1_PDPADRV5_LSB                                                                    28
#define RF5G1_CH1_PDPADRV5_MASK                                                           0x10000000
#define RF5G1_CH1_PDPADRV5_GET(x)                                         (((x) & 0x10000000) >> 28)
#define RF5G1_CH1_PDPADRV5_SET(x)                                         (((x) << 28) & 0x10000000)
#define RF5G1_CH1_PDTXBUF5_MSB                                                                    29
#define RF5G1_CH1_PDTXBUF5_LSB                                                                    29
#define RF5G1_CH1_PDTXBUF5_MASK                                                           0x20000000
#define RF5G1_CH1_PDTXBUF5_GET(x)                                         (((x) & 0x20000000) >> 29)
#define RF5G1_CH1_PDTXBUF5_SET(x)                                         (((x) << 29) & 0x20000000)
#define RF5G1_CH1_PDTXMIX5_MSB                                                                    30
#define RF5G1_CH1_PDTXMIX5_LSB                                                                    30
#define RF5G1_CH1_PDTXMIX5_MASK                                                           0x40000000
#define RF5G1_CH1_PDTXMIX5_GET(x)                                         (((x) & 0x40000000) >> 30)
#define RF5G1_CH1_PDTXMIX5_SET(x)                                         (((x) << 30) & 0x40000000)
#define RF5G1_CH1_PDTXLO5_MSB                                                                     31
#define RF5G1_CH1_PDTXLO5_LSB                                                                     31
#define RF5G1_CH1_PDTXLO5_MASK                                                            0x80000000
#define RF5G1_CH1_PDTXLO5_GET(x)                                          (((x) & 0x80000000) >> 31)
#define RF5G1_CH1_PDTXLO5_SET(x)                                          (((x) << 31) & 0x80000000)

/* macros for RF5G2_CH1 */
#define RF5G2_CH1_ADDRESS                                                                 0x0000001c
#define RF5G2_CH1_OFFSET                                                                  0x0000001c
#define RF5G2_CH1_SPARE_MSB                                                                       10
#define RF5G2_CH1_SPARE_LSB                                                                        0
#define RF5G2_CH1_SPARE_MASK                                                              0x000007ff
#define RF5G2_CH1_SPARE_GET(x)                                             (((x) & 0x000007ff) >> 0)
#define RF5G2_CH1_SPARE_SET(x)                                             (((x) << 0) & 0x000007ff)
#define RF5G2_CH1_PDBIR2_MSB                                                                      13
#define RF5G2_CH1_PDBIR2_LSB                                                                      11
#define RF5G2_CH1_PDBIR2_MASK                                                             0x00003800
#define RF5G2_CH1_PDBIR2_GET(x)                                           (((x) & 0x00003800) >> 11)
#define RF5G2_CH1_PDBIR2_SET(x)                                           (((x) << 11) & 0x00003800)
#define RF5G2_CH1_PDBIR1_MSB                                                                      16
#define RF5G2_CH1_PDBIR1_LSB                                                                      14
#define RF5G2_CH1_PDBIR1_MASK                                                             0x0001c000
#define RF5G2_CH1_PDBIR1_GET(x)                                           (((x) & 0x0001c000) >> 14)
#define RF5G2_CH1_PDBIR1_SET(x)                                           (((x) << 14) & 0x0001c000)
#define RF5G2_CH1_PDBIRTXPA_MSB                                                                   19
#define RF5G2_CH1_PDBIRTXPA_LSB                                                                   17
#define RF5G2_CH1_PDBIRTXPA_MASK                                                          0x000e0000
#define RF5G2_CH1_PDBIRTXPA_GET(x)                                        (((x) & 0x000e0000) >> 17)
#define RF5G2_CH1_PDBIRTXPA_SET(x)                                        (((x) << 17) & 0x000e0000)
#define RF5G2_CH1_PDBIRTXMIX_MSB                                                                  22
#define RF5G2_CH1_PDBIRTXMIX_LSB                                                                  20
#define RF5G2_CH1_PDBIRTXMIX_MASK                                                         0x00700000
#define RF5G2_CH1_PDBIRTXMIX_GET(x)                                       (((x) & 0x00700000) >> 20)
#define RF5G2_CH1_PDBIRTXMIX_SET(x)                                       (((x) << 20) & 0x00700000)
#define RF5G2_CH1_RX5_ATB_SEL_MSB                                                                 25
#define RF5G2_CH1_RX5_ATB_SEL_LSB                                                                 23
#define RF5G2_CH1_RX5_ATB_SEL_MASK                                                        0x03800000
#define RF5G2_CH1_RX5_ATB_SEL_GET(x)                                      (((x) & 0x03800000) >> 23)
#define RF5G2_CH1_RX5_ATB_SEL_SET(x)                                      (((x) << 23) & 0x03800000)
#define RF5G2_CH1_PDRFVGA5_MSB                                                                    26
#define RF5G2_CH1_PDRFVGA5_LSB                                                                    26
#define RF5G2_CH1_PDRFVGA5_MASK                                                           0x04000000
#define RF5G2_CH1_PDRFVGA5_GET(x)                                         (((x) & 0x04000000) >> 26)
#define RF5G2_CH1_PDRFVGA5_SET(x)                                         (((x) << 26) & 0x04000000)
#define RF5G2_CH1_PDCSLNA5_MSB                                                                    27
#define RF5G2_CH1_PDCSLNA5_LSB                                                                    27
#define RF5G2_CH1_PDCSLNA5_MASK                                                           0x08000000
#define RF5G2_CH1_PDCSLNA5_GET(x)                                         (((x) & 0x08000000) >> 27)
#define RF5G2_CH1_PDCSLNA5_SET(x)                                         (((x) << 27) & 0x08000000)
#define RF5G2_CH1_PDVGM5_MSB                                                                      28
#define RF5G2_CH1_PDVGM5_LSB                                                                      28
#define RF5G2_CH1_PDVGM5_MASK                                                             0x10000000
#define RF5G2_CH1_PDVGM5_GET(x)                                           (((x) & 0x10000000) >> 28)
#define RF5G2_CH1_PDVGM5_SET(x)                                           (((x) << 28) & 0x10000000)
#define RF5G2_CH1_PDRXLO5_MSB                                                                     29
#define RF5G2_CH1_PDRXLO5_LSB                                                                     29
#define RF5G2_CH1_PDRXLO5_MASK                                                            0x20000000
#define RF5G2_CH1_PDRXLO5_GET(x)                                          (((x) & 0x20000000) >> 29)
#define RF5G2_CH1_PDRXLO5_SET(x)                                          (((x) << 29) & 0x20000000)
#define RF5G2_CH1_PDREGFE5_MSB                                                                    30
#define RF5G2_CH1_PDREGFE5_LSB                                                                    30
#define RF5G2_CH1_PDREGFE5_MASK                                                           0x40000000
#define RF5G2_CH1_PDREGFE5_GET(x)                                         (((x) & 0x40000000) >> 30)
#define RF5G2_CH1_PDREGFE5_SET(x)                                         (((x) << 30) & 0x40000000)
#define RF5G2_CH1_REGFE_BYPASS5_MSB                                                               31
#define RF5G2_CH1_REGFE_BYPASS5_LSB                                                               31
#define RF5G2_CH1_REGFE_BYPASS5_MASK                                                      0x80000000
#define RF5G2_CH1_REGFE_BYPASS5_GET(x)                                    (((x) & 0x80000000) >> 31)
#define RF5G2_CH1_REGFE_BYPASS5_SET(x)                                    (((x) << 31) & 0x80000000)

/* macros for RF5G3_CH1 */
#define RF5G3_CH1_ADDRESS                                                                 0x00000020
#define RF5G3_CH1_OFFSET                                                                  0x00000020
#define RF5G3_CH1_SPARE_MSB                                                                        4
#define RF5G3_CH1_SPARE_LSB                                                                        0
#define RF5G3_CH1_SPARE_MASK                                                              0x0000001f
#define RF5G3_CH1_SPARE_GET(x)                                             (((x) & 0x0000001f) >> 0)
#define RF5G3_CH1_SPARE_SET(x)                                             (((x) << 0) & 0x0000001f)
#define RF5G3_CH1_PDBIBCVGM_MSB                                                                    7
#define RF5G3_CH1_PDBIBCVGM_LSB                                                                    5
#define RF5G3_CH1_PDBIBCVGM_MASK                                                          0x000000e0
#define RF5G3_CH1_PDBIBCVGM_GET(x)                                         (((x) & 0x000000e0) >> 5)
#define RF5G3_CH1_PDBIBCVGM_SET(x)                                         (((x) << 5) & 0x000000e0)
#define RF5G3_CH1_PDBIBCRFVGA_MSB                                                                 10
#define RF5G3_CH1_PDBIBCRFVGA_LSB                                                                  8
#define RF5G3_CH1_PDBIBCRFVGA_MASK                                                        0x00000700
#define RF5G3_CH1_PDBIBCRFVGA_GET(x)                                       (((x) & 0x00000700) >> 8)
#define RF5G3_CH1_PDBIBCRFVGA_SET(x)                                       (((x) << 8) & 0x00000700)
#define RF5G3_CH1_PDBIBCLNA_MSB                                                                   13
#define RF5G3_CH1_PDBIBCLNA_LSB                                                                   11
#define RF5G3_CH1_PDBIBCLNA_MASK                                                          0x00003800
#define RF5G3_CH1_PDBIBCLNA_GET(x)                                        (((x) & 0x00003800) >> 11)
#define RF5G3_CH1_PDBIBCLNA_SET(x)                                        (((x) << 11) & 0x00003800)
#define RF5G3_CH1_PDBIC3_MSB                                                                      16
#define RF5G3_CH1_PDBIC3_LSB                                                                      14
#define RF5G3_CH1_PDBIC3_MASK                                                             0x0001c000
#define RF5G3_CH1_PDBIC3_GET(x)                                           (((x) & 0x0001c000) >> 14)
#define RF5G3_CH1_PDBIC3_SET(x)                                           (((x) << 14) & 0x0001c000)
#define RF5G3_CH1_PDBIC2_MSB                                                                      19
#define RF5G3_CH1_PDBIC2_LSB                                                                      17
#define RF5G3_CH1_PDBIC2_MASK                                                             0x000e0000
#define RF5G3_CH1_PDBIC2_GET(x)                                           (((x) & 0x000e0000) >> 17)
#define RF5G3_CH1_PDBIC2_SET(x)                                           (((x) << 17) & 0x000e0000)
#define RF5G3_CH1_PDBIC1_MSB                                                                      22
#define RF5G3_CH1_PDBIC1_LSB                                                                      20
#define RF5G3_CH1_PDBIC1_MASK                                                             0x00700000
#define RF5G3_CH1_PDBIC1_GET(x)                                           (((x) & 0x00700000) >> 20)
#define RF5G3_CH1_PDBIC1_SET(x)                                           (((x) << 20) & 0x00700000)
#define RF5G3_CH1_PDBICTXMIX_MSB                                                                  25
#define RF5G3_CH1_PDBICTXMIX_LSB                                                                  23
#define RF5G3_CH1_PDBICTXMIX_MASK                                                         0x03800000
#define RF5G3_CH1_PDBICTXMIX_GET(x)                                       (((x) & 0x03800000) >> 23)
#define RF5G3_CH1_PDBICTXMIX_SET(x)                                       (((x) << 23) & 0x03800000)
#define RF5G3_CH1_PDBICTXPA_MSB                                                                   28
#define RF5G3_CH1_PDBICTXPA_LSB                                                                   26
#define RF5G3_CH1_PDBICTXPA_MASK                                                          0x1c000000
#define RF5G3_CH1_PDBICTXPA_GET(x)                                        (((x) & 0x1c000000) >> 26)
#define RF5G3_CH1_PDBICTXPA_SET(x)                                        (((x) << 26) & 0x1c000000)
#define RF5G3_CH1_PDBICTXBUF_MSB                                                                  31
#define RF5G3_CH1_PDBICTXBUF_LSB                                                                  29
#define RF5G3_CH1_PDBICTXBUF_MASK                                                         0xe0000000
#define RF5G3_CH1_PDBICTXBUF_GET(x)                                       (((x) & 0xe0000000) >> 29)
#define RF5G3_CH1_PDBICTXBUF_SET(x)                                       (((x) << 29) & 0xe0000000)

/* macros for RXTXBB1_CH0 */
#define RXTXBB1_CH0_ADDRESS                                                               0x00000024
#define RXTXBB1_CH0_OFFSET                                                                0x00000024
#define RXTXBB1_CH0_PDHIQ_MSB                                                                      0
#define RXTXBB1_CH0_PDHIQ_LSB                                                                      0
#define RXTXBB1_CH0_PDHIQ_MASK                                                            0x00000001
#define RXTXBB1_CH0_PDHIQ_GET(x)                                           (((x) & 0x00000001) >> 0)
#define RXTXBB1_CH0_PDHIQ_SET(x)                                           (((x) << 0) & 0x00000001)
#define RXTXBB1_CH0_PDLOQ_MSB                                                                      1
#define RXTXBB1_CH0_PDLOQ_LSB                                                                      1
#define RXTXBB1_CH0_PDLOQ_MASK                                                            0x00000002
#define RXTXBB1_CH0_PDLOQ_GET(x)                                           (((x) & 0x00000002) >> 1)
#define RXTXBB1_CH0_PDLOQ_SET(x)                                           (((x) << 1) & 0x00000002)
#define RXTXBB1_CH0_PDOFFSETI2V_MSB                                                                2
#define RXTXBB1_CH0_PDOFFSETI2V_LSB                                                                2
#define RXTXBB1_CH0_PDOFFSETI2V_MASK                                                      0x00000004
#define RXTXBB1_CH0_PDOFFSETI2V_GET(x)                                     (((x) & 0x00000004) >> 2)
#define RXTXBB1_CH0_PDOFFSETI2V_SET(x)                                     (((x) << 2) & 0x00000004)
#define RXTXBB1_CH0_PDOFFSETHIQ_MSB                                                                3
#define RXTXBB1_CH0_PDOFFSETHIQ_LSB                                                                3
#define RXTXBB1_CH0_PDOFFSETHIQ_MASK                                                      0x00000008
#define RXTXBB1_CH0_PDOFFSETHIQ_GET(x)                                     (((x) & 0x00000008) >> 3)
#define RXTXBB1_CH0_PDOFFSETHIQ_SET(x)                                     (((x) << 3) & 0x00000008)
#define RXTXBB1_CH0_PDOFFSETLOQ_MSB                                                                4
#define RXTXBB1_CH0_PDOFFSETLOQ_LSB                                                                4
#define RXTXBB1_CH0_PDOFFSETLOQ_MASK                                                      0x00000010
#define RXTXBB1_CH0_PDOFFSETLOQ_GET(x)                                     (((x) & 0x00000010) >> 4)
#define RXTXBB1_CH0_PDOFFSETLOQ_SET(x)                                     (((x) << 4) & 0x00000010)
#define RXTXBB1_CH0_PDRXTXBB_MSB                                                                   5
#define RXTXBB1_CH0_PDRXTXBB_LSB                                                                   5
#define RXTXBB1_CH0_PDRXTXBB_MASK                                                         0x00000020
#define RXTXBB1_CH0_PDRXTXBB_GET(x)                                        (((x) & 0x00000020) >> 5)
#define RXTXBB1_CH0_PDRXTXBB_SET(x)                                        (((x) << 5) & 0x00000020)
#define RXTXBB1_CH0_PDI2V_MSB                                                                      6
#define RXTXBB1_CH0_PDI2V_LSB                                                                      6
#define RXTXBB1_CH0_PDI2V_MASK                                                            0x00000040
#define RXTXBB1_CH0_PDI2V_GET(x)                                           (((x) & 0x00000040) >> 6)
#define RXTXBB1_CH0_PDI2V_SET(x)                                           (((x) << 6) & 0x00000040)
#define RXTXBB1_CH0_PDV2I_MSB                                                                      7
#define RXTXBB1_CH0_PDV2I_LSB                                                                      7
#define RXTXBB1_CH0_PDV2I_MASK                                                            0x00000080
#define RXTXBB1_CH0_PDV2I_GET(x)                                           (((x) & 0x00000080) >> 7)
#define RXTXBB1_CH0_PDV2I_SET(x)                                           (((x) << 7) & 0x00000080)
#define RXTXBB1_CH0_PDDACINTERFACE_MSB                                                             8
#define RXTXBB1_CH0_PDDACINTERFACE_LSB                                                             8
#define RXTXBB1_CH0_PDDACINTERFACE_MASK                                                   0x00000100
#define RXTXBB1_CH0_PDDACINTERFACE_GET(x)                                  (((x) & 0x00000100) >> 8)
#define RXTXBB1_CH0_PDDACINTERFACE_SET(x)                                  (((x) << 8) & 0x00000100)
#define RXTXBB1_CH0_SEL_ATB_MSB                                                                   16
#define RXTXBB1_CH0_SEL_ATB_LSB                                                                    9
#define RXTXBB1_CH0_SEL_ATB_MASK                                                          0x0001fe00
#define RXTXBB1_CH0_SEL_ATB_GET(x)                                         (((x) & 0x0001fe00) >> 9)
#define RXTXBB1_CH0_SEL_ATB_SET(x)                                         (((x) << 9) & 0x0001fe00)
#define RXTXBB1_CH0_FNOTCH_MSB                                                                    18
#define RXTXBB1_CH0_FNOTCH_LSB                                                                    17
#define RXTXBB1_CH0_FNOTCH_MASK                                                           0x00060000
#define RXTXBB1_CH0_FNOTCH_GET(x)                                         (((x) & 0x00060000) >> 17)
#define RXTXBB1_CH0_FNOTCH_SET(x)                                         (((x) << 17) & 0x00060000)
#define RXTXBB1_CH0_SPARE_MSB                                                                     31
#define RXTXBB1_CH0_SPARE_LSB                                                                     19
#define RXTXBB1_CH0_SPARE_MASK                                                            0xfff80000
#define RXTXBB1_CH0_SPARE_GET(x)                                          (((x) & 0xfff80000) >> 19)
#define RXTXBB1_CH0_SPARE_SET(x)                                          (((x) << 19) & 0xfff80000)

/* macros for RXTXBB2_CH0 */
#define RXTXBB2_CH0_ADDRESS                                                               0x00000028
#define RXTXBB2_CH0_OFFSET                                                                0x00000028
#define RXTXBB2_CH0_PATH_OVERRIDE_MSB                                                              0
#define RXTXBB2_CH0_PATH_OVERRIDE_LSB                                                              0
#define RXTXBB2_CH0_PATH_OVERRIDE_MASK                                                    0x00000001
#define RXTXBB2_CH0_PATH_OVERRIDE_GET(x)                                   (((x) & 0x00000001) >> 0)
#define RXTXBB2_CH0_PATH_OVERRIDE_SET(x)                                   (((x) << 0) & 0x00000001)
#define RXTXBB2_CH0_PATH1LOQ_EN_MSB                                                                1
#define RXTXBB2_CH0_PATH1LOQ_EN_LSB                                                                1
#define RXTXBB2_CH0_PATH1LOQ_EN_MASK                                                      0x00000002
#define RXTXBB2_CH0_PATH1LOQ_EN_GET(x)                                     (((x) & 0x00000002) >> 1)
#define RXTXBB2_CH0_PATH1LOQ_EN_SET(x)                                     (((x) << 1) & 0x00000002)
#define RXTXBB2_CH0_PATH2LOQ_EN_MSB                                                                2
#define RXTXBB2_CH0_PATH2LOQ_EN_LSB                                                                2
#define RXTXBB2_CH0_PATH2LOQ_EN_MASK                                                      0x00000004
#define RXTXBB2_CH0_PATH2LOQ_EN_GET(x)                                     (((x) & 0x00000004) >> 2)
#define RXTXBB2_CH0_PATH2LOQ_EN_SET(x)                                     (((x) << 2) & 0x00000004)
#define RXTXBB2_CH0_PATH3LOQ_EN_MSB                                                                3
#define RXTXBB2_CH0_PATH3LOQ_EN_LSB                                                                3
#define RXTXBB2_CH0_PATH3LOQ_EN_MASK                                                      0x00000008
#define RXTXBB2_CH0_PATH3LOQ_EN_GET(x)                                     (((x) & 0x00000008) >> 3)
#define RXTXBB2_CH0_PATH3LOQ_EN_SET(x)                                     (((x) << 3) & 0x00000008)
#define RXTXBB2_CH0_PATH1HIQ_EN_MSB                                                                4
#define RXTXBB2_CH0_PATH1HIQ_EN_LSB                                                                4
#define RXTXBB2_CH0_PATH1HIQ_EN_MASK                                                      0x00000010
#define RXTXBB2_CH0_PATH1HIQ_EN_GET(x)                                     (((x) & 0x00000010) >> 4)
#define RXTXBB2_CH0_PATH1HIQ_EN_SET(x)                                     (((x) << 4) & 0x00000010)
#define RXTXBB2_CH0_PATH2HIQ_EN_MSB                                                                5
#define RXTXBB2_CH0_PATH2HIQ_EN_LSB                                                                5
#define RXTXBB2_CH0_PATH2HIQ_EN_MASK                                                      0x00000020
#define RXTXBB2_CH0_PATH2HIQ_EN_GET(x)                                     (((x) & 0x00000020) >> 5)
#define RXTXBB2_CH0_PATH2HIQ_EN_SET(x)                                     (((x) << 5) & 0x00000020)
#define RXTXBB2_CH0_FILTERDOUBLEBW_MSB                                                             6
#define RXTXBB2_CH0_FILTERDOUBLEBW_LSB                                                             6
#define RXTXBB2_CH0_FILTERDOUBLEBW_MASK                                                   0x00000040
#define RXTXBB2_CH0_FILTERDOUBLEBW_GET(x)                                  (((x) & 0x00000040) >> 6)
#define RXTXBB2_CH0_FILTERDOUBLEBW_SET(x)                                  (((x) << 6) & 0x00000040)
#define RXTXBB2_CH0_LOCALFILTERTUNING_MSB                                                          7
#define RXTXBB2_CH0_LOCALFILTERTUNING_LSB                                                          7
#define RXTXBB2_CH0_LOCALFILTERTUNING_MASK                                                0x00000080
#define RXTXBB2_CH0_LOCALFILTERTUNING_GET(x)                               (((x) & 0x00000080) >> 7)
#define RXTXBB2_CH0_LOCALFILTERTUNING_SET(x)                               (((x) << 7) & 0x00000080)
#define RXTXBB2_CH0_FILTERFC_MSB                                                                  12
#define RXTXBB2_CH0_FILTERFC_LSB                                                                   8
#define RXTXBB2_CH0_FILTERFC_MASK                                                         0x00001f00
#define RXTXBB2_CH0_FILTERFC_GET(x)                                        (((x) & 0x00001f00) >> 8)
#define RXTXBB2_CH0_FILTERFC_SET(x)                                        (((x) << 8) & 0x00001f00)
#define RXTXBB2_CH0_CMSEL_MSB                                                                     14
#define RXTXBB2_CH0_CMSEL_LSB                                                                     13
#define RXTXBB2_CH0_CMSEL_MASK                                                            0x00006000
#define RXTXBB2_CH0_CMSEL_GET(x)                                          (((x) & 0x00006000) >> 13)
#define RXTXBB2_CH0_CMSEL_SET(x)                                          (((x) << 13) & 0x00006000)
#define RXTXBB2_CH0_SEL_I2V_TEST_MSB                                                              15
#define RXTXBB2_CH0_SEL_I2V_TEST_LSB                                                              15
#define RXTXBB2_CH0_SEL_I2V_TEST_MASK                                                     0x00008000
#define RXTXBB2_CH0_SEL_I2V_TEST_GET(x)                                   (((x) & 0x00008000) >> 15)
#define RXTXBB2_CH0_SEL_I2V_TEST_SET(x)                                   (((x) << 15) & 0x00008000)
#define RXTXBB2_CH0_SEL_HIQ_TEST_MSB                                                              16
#define RXTXBB2_CH0_SEL_HIQ_TEST_LSB                                                              16
#define RXTXBB2_CH0_SEL_HIQ_TEST_MASK                                                     0x00010000
#define RXTXBB2_CH0_SEL_HIQ_TEST_GET(x)                                   (((x) & 0x00010000) >> 16)
#define RXTXBB2_CH0_SEL_HIQ_TEST_SET(x)                                   (((x) << 16) & 0x00010000)
#define RXTXBB2_CH0_SEL_LOQ_TEST_MSB                                                              17
#define RXTXBB2_CH0_SEL_LOQ_TEST_LSB                                                              17
#define RXTXBB2_CH0_SEL_LOQ_TEST_MASK                                                     0x00020000
#define RXTXBB2_CH0_SEL_LOQ_TEST_GET(x)                                   (((x) & 0x00020000) >> 17)
#define RXTXBB2_CH0_SEL_LOQ_TEST_SET(x)                                   (((x) << 17) & 0x00020000)
#define RXTXBB2_CH0_SEL_DAC_TEST_MSB                                                              18
#define RXTXBB2_CH0_SEL_DAC_TEST_LSB                                                              18
#define RXTXBB2_CH0_SEL_DAC_TEST_MASK                                                     0x00040000
#define RXTXBB2_CH0_SEL_DAC_TEST_GET(x)                                   (((x) & 0x00040000) >> 18)
#define RXTXBB2_CH0_SEL_DAC_TEST_SET(x)                                   (((x) << 18) & 0x00040000)
#define RXTXBB2_CH0_SELBUFFER_MSB                                                                 19
#define RXTXBB2_CH0_SELBUFFER_LSB                                                                 19
#define RXTXBB2_CH0_SELBUFFER_MASK                                                        0x00080000
#define RXTXBB2_CH0_SELBUFFER_GET(x)                                      (((x) & 0x00080000) >> 19)
#define RXTXBB2_CH0_SELBUFFER_SET(x)                                      (((x) << 19) & 0x00080000)
#define RXTXBB2_CH0_SHORTBUFFER_MSB                                                               20
#define RXTXBB2_CH0_SHORTBUFFER_LSB                                                               20
#define RXTXBB2_CH0_SHORTBUFFER_MASK                                                      0x00100000
#define RXTXBB2_CH0_SHORTBUFFER_GET(x)                                    (((x) & 0x00100000) >> 20)
#define RXTXBB2_CH0_SHORTBUFFER_SET(x)                                    (((x) << 20) & 0x00100000)
#define RXTXBB2_CH0_SPARE_MSB                                                                     22
#define RXTXBB2_CH0_SPARE_LSB                                                                     21
#define RXTXBB2_CH0_SPARE_MASK                                                            0x00600000
#define RXTXBB2_CH0_SPARE_GET(x)                                          (((x) & 0x00600000) >> 21)
#define RXTXBB2_CH0_SPARE_SET(x)                                          (((x) << 21) & 0x00600000)
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_MSB                                                       25
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_LSB                                                       23
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_MASK                                              0x03800000
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_GET(x)                            (((x) & 0x03800000) >> 23)
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_SET(x)                            (((x) << 23) & 0x03800000)
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_MSB                                                        28
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_LSB                                                        26
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_MASK                                               0x1c000000
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_GET(x)                             (((x) & 0x1c000000) >> 26)
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_SET(x)                             (((x) << 26) & 0x1c000000)
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_MSB                                                        31
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_LSB                                                        29
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_MASK                                               0xe0000000
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_GET(x)                             (((x) & 0xe0000000) >> 29)
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_SET(x)                             (((x) << 29) & 0xe0000000)

/* macros for RXTXBB3_CH0 */
#define RXTXBB3_CH0_ADDRESS                                                               0x0000002c
#define RXTXBB3_CH0_OFFSET                                                                0x0000002c
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_MSB                                                         2
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_LSB                                                         0
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_MASK                                               0x00000007
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_GET(x)                              (((x) & 0x00000007) >> 0)
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_SET(x)                              (((x) << 0) & 0x00000007)
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_MSB                                                          5
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_LSB                                                          3
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_MASK                                                0x00000038
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_GET(x)                               (((x) & 0x00000038) >> 3)
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_SET(x)                               (((x) << 3) & 0x00000038)
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_MSB                                                           8
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_LSB                                                           6
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_MASK                                                 0x000001c0
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_GET(x)                                (((x) & 0x000001c0) >> 6)
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_SET(x)                                (((x) << 6) & 0x000001c0)
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_MSB                                                          11
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_LSB                                                           9
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_MASK                                                 0x00000e00
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_GET(x)                                (((x) & 0x00000e00) >> 9)
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_SET(x)                                (((x) << 9) & 0x00000e00)
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_MSB                                                          14
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_LSB                                                          12
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_MASK                                                 0x00007000
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_GET(x)                               (((x) & 0x00007000) >> 12)
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_SET(x)                               (((x) << 12) & 0x00007000)
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_MSB                                                          17
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_LSB                                                          15
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_MASK                                                 0x00038000
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_GET(x)                               (((x) & 0x00038000) >> 15)
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_SET(x)                               (((x) << 15) & 0x00038000)
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_MSB                                                          20
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_LSB                                                          18
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_MASK                                                 0x001c0000
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_GET(x)                               (((x) & 0x001c0000) >> 18)
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_SET(x)                               (((x) << 18) & 0x001c0000)
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_MSB                                                        23
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_LSB                                                        21
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_MASK                                               0x00e00000
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_GET(x)                             (((x) & 0x00e00000) >> 21)
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_SET(x)                             (((x) << 21) & 0x00e00000)
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_MSB                                                    26
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_LSB                                                    24
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_MASK                                           0x07000000
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_GET(x)                         (((x) & 0x07000000) >> 24)
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_SET(x)                         (((x) << 24) & 0x07000000)
#define RXTXBB3_CH0_SPARE_MSB                                                                     31
#define RXTXBB3_CH0_SPARE_LSB                                                                     27
#define RXTXBB3_CH0_SPARE_MASK                                                            0xf8000000
#define RXTXBB3_CH0_SPARE_GET(x)                                          (((x) & 0xf8000000) >> 27)
#define RXTXBB3_CH0_SPARE_SET(x)                                          (((x) << 27) & 0xf8000000)

/* macros for RXTXBB4_CH0 */
#define RXTXBB4_CH0_ADDRESS                                                               0x00000030
#define RXTXBB4_CH0_OFFSET                                                                0x00000030
#define RXTXBB4_CH0_OFSTCORRI2VQ_MSB                                                               4
#define RXTXBB4_CH0_OFSTCORRI2VQ_LSB                                                               0
#define RXTXBB4_CH0_OFSTCORRI2VQ_MASK                                                     0x0000001f
#define RXTXBB4_CH0_OFSTCORRI2VQ_GET(x)                                    (((x) & 0x0000001f) >> 0)
#define RXTXBB4_CH0_OFSTCORRI2VQ_SET(x)                                    (((x) << 0) & 0x0000001f)
#define RXTXBB4_CH0_OFSTCORRI2VI_MSB                                                               9
#define RXTXBB4_CH0_OFSTCORRI2VI_LSB                                                               5
#define RXTXBB4_CH0_OFSTCORRI2VI_MASK                                                     0x000003e0
#define RXTXBB4_CH0_OFSTCORRI2VI_GET(x)                                    (((x) & 0x000003e0) >> 5)
#define RXTXBB4_CH0_OFSTCORRI2VI_SET(x)                                    (((x) << 5) & 0x000003e0)
#define RXTXBB4_CH0_OFSTCORRLOQ_MSB                                                               14
#define RXTXBB4_CH0_OFSTCORRLOQ_LSB                                                               10
#define RXTXBB4_CH0_OFSTCORRLOQ_MASK                                                      0x00007c00
#define RXTXBB4_CH0_OFSTCORRLOQ_GET(x)                                    (((x) & 0x00007c00) >> 10)
#define RXTXBB4_CH0_OFSTCORRLOQ_SET(x)                                    (((x) << 10) & 0x00007c00)
#define RXTXBB4_CH0_OFSTCORRLOI_MSB                                                               19
#define RXTXBB4_CH0_OFSTCORRLOI_LSB                                                               15
#define RXTXBB4_CH0_OFSTCORRLOI_MASK                                                      0x000f8000
#define RXTXBB4_CH0_OFSTCORRLOI_GET(x)                                    (((x) & 0x000f8000) >> 15)
#define RXTXBB4_CH0_OFSTCORRLOI_SET(x)                                    (((x) << 15) & 0x000f8000)
#define RXTXBB4_CH0_OFSTCORRHIQ_MSB                                                               24
#define RXTXBB4_CH0_OFSTCORRHIQ_LSB                                                               20
#define RXTXBB4_CH0_OFSTCORRHIQ_MASK                                                      0x01f00000
#define RXTXBB4_CH0_OFSTCORRHIQ_GET(x)                                    (((x) & 0x01f00000) >> 20)
#define RXTXBB4_CH0_OFSTCORRHIQ_SET(x)                                    (((x) << 20) & 0x01f00000)
#define RXTXBB4_CH0_OFSTCORRHII_MSB                                                               29
#define RXTXBB4_CH0_OFSTCORRHII_LSB                                                               25
#define RXTXBB4_CH0_OFSTCORRHII_MASK                                                      0x3e000000
#define RXTXBB4_CH0_OFSTCORRHII_GET(x)                                    (((x) & 0x3e000000) >> 25)
#define RXTXBB4_CH0_OFSTCORRHII_SET(x)                                    (((x) << 25) & 0x3e000000)
#define RXTXBB4_CH0_LOCALOFFSET_MSB                                                               30
#define RXTXBB4_CH0_LOCALOFFSET_LSB                                                               30
#define RXTXBB4_CH0_LOCALOFFSET_MASK                                                      0x40000000
#define RXTXBB4_CH0_LOCALOFFSET_GET(x)                                    (((x) & 0x40000000) >> 30)
#define RXTXBB4_CH0_LOCALOFFSET_SET(x)                                    (((x) << 30) & 0x40000000)
#define RXTXBB4_CH0_SPARE_MSB                                                                     31
#define RXTXBB4_CH0_SPARE_LSB                                                                     31
#define RXTXBB4_CH0_SPARE_MASK                                                            0x80000000
#define RXTXBB4_CH0_SPARE_GET(x)                                          (((x) & 0x80000000) >> 31)
#define RXTXBB4_CH0_SPARE_SET(x)                                          (((x) << 31) & 0x80000000)

/* macros for RF5G1_CH0 */
#define RF5G1_CH0_ADDRESS                                                                 0x00000034
#define RF5G1_CH0_OFFSET                                                                  0x00000034
#define RF5G1_CH0_SPARE_MSB                                                                        9
#define RF5G1_CH0_SPARE_LSB                                                                        0
#define RF5G1_CH0_SPARE_MASK                                                              0x000003ff
#define RF5G1_CH0_SPARE_GET(x)                                             (((x) & 0x000003ff) >> 0)
#define RF5G1_CH0_SPARE_SET(x)                                             (((x) << 0) & 0x000003ff)
#define RF5G1_CH0_PDREGLO5_MSB                                                                    10
#define RF5G1_CH0_PDREGLO5_LSB                                                                    10
#define RF5G1_CH0_PDREGLO5_MASK                                                           0x00000400
#define RF5G1_CH0_PDREGLO5_GET(x)                                         (((x) & 0x00000400) >> 10)
#define RF5G1_CH0_PDREGLO5_SET(x)                                         (((x) << 10) & 0x00000400)
#define RF5G1_CH0_REGLO_BYPASS5_MSB                                                               11
#define RF5G1_CH0_REGLO_BYPASS5_LSB                                                               11
#define RF5G1_CH0_REGLO_BYPASS5_MASK                                                      0x00000800
#define RF5G1_CH0_REGLO_BYPASS5_GET(x)                                    (((x) & 0x00000800) >> 11)
#define RF5G1_CH0_REGLO_BYPASS5_SET(x)                                    (((x) << 11) & 0x00000800)
#define RF5G1_CH0_LO5CONTROL_MSB                                                                  12
#define RF5G1_CH0_LO5CONTROL_LSB                                                                  12
#define RF5G1_CH0_LO5CONTROL_MASK                                                         0x00001000
#define RF5G1_CH0_LO5CONTROL_GET(x)                                       (((x) & 0x00001000) >> 12)
#define RF5G1_CH0_LO5CONTROL_SET(x)                                       (((x) << 12) & 0x00001000)
#define RF5G1_CH0_TX5_ATB_SEL_MSB                                                                 15
#define RF5G1_CH0_TX5_ATB_SEL_LSB                                                                 13
#define RF5G1_CH0_TX5_ATB_SEL_MASK                                                        0x0000e000
#define RF5G1_CH0_TX5_ATB_SEL_GET(x)                                      (((x) & 0x0000e000) >> 13)
#define RF5G1_CH0_TX5_ATB_SEL_SET(x)                                      (((x) << 13) & 0x0000e000)
#define RF5G1_CH0_OB5_MSB                                                                         18
#define RF5G1_CH0_OB5_LSB                                                                         16
#define RF5G1_CH0_OB5_MASK                                                                0x00070000
#define RF5G1_CH0_OB5_GET(x)                                              (((x) & 0x00070000) >> 16)
#define RF5G1_CH0_OB5_SET(x)                                              (((x) << 16) & 0x00070000)
#define RF5G1_CH0_DB5_MSB                                                                         21
#define RF5G1_CH0_DB5_LSB                                                                         19
#define RF5G1_CH0_DB5_MASK                                                                0x00380000
#define RF5G1_CH0_DB5_GET(x)                                              (((x) & 0x00380000) >> 19)
#define RF5G1_CH0_DB5_SET(x)                                              (((x) << 19) & 0x00380000)
#define RF5G1_CH0_PWDTXPKD_MSB                                                                    24
#define RF5G1_CH0_PWDTXPKD_LSB                                                                    22
#define RF5G1_CH0_PWDTXPKD_MASK                                                           0x01c00000
#define RF5G1_CH0_PWDTXPKD_GET(x)                                         (((x) & 0x01c00000) >> 22)
#define RF5G1_CH0_PWDTXPKD_SET(x)                                         (((x) << 22) & 0x01c00000)
#define RF5G1_CH0_PACASCBIAS_MSB                                                                  26
#define RF5G1_CH0_PACASCBIAS_LSB                                                                  25
#define RF5G1_CH0_PACASCBIAS_MASK                                                         0x06000000
#define RF5G1_CH0_PACASCBIAS_GET(x)                                       (((x) & 0x06000000) >> 25)
#define RF5G1_CH0_PACASCBIAS_SET(x)                                       (((x) << 25) & 0x06000000)
#define RF5G1_CH0_PDPAOUT5_MSB                                                                    27
#define RF5G1_CH0_PDPAOUT5_LSB                                                                    27
#define RF5G1_CH0_PDPAOUT5_MASK                                                           0x08000000
#define RF5G1_CH0_PDPAOUT5_GET(x)                                         (((x) & 0x08000000) >> 27)
#define RF5G1_CH0_PDPAOUT5_SET(x)                                         (((x) << 27) & 0x08000000)
#define RF5G1_CH0_PDPADRV5_MSB                                                                    28
#define RF5G1_CH0_PDPADRV5_LSB                                                                    28
#define RF5G1_CH0_PDPADRV5_MASK                                                           0x10000000
#define RF5G1_CH0_PDPADRV5_GET(x)                                         (((x) & 0x10000000) >> 28)
#define RF5G1_CH0_PDPADRV5_SET(x)                                         (((x) << 28) & 0x10000000)
#define RF5G1_CH0_PDTXBUF5_MSB                                                                    29
#define RF5G1_CH0_PDTXBUF5_LSB                                                                    29
#define RF5G1_CH0_PDTXBUF5_MASK                                                           0x20000000
#define RF5G1_CH0_PDTXBUF5_GET(x)                                         (((x) & 0x20000000) >> 29)
#define RF5G1_CH0_PDTXBUF5_SET(x)                                         (((x) << 29) & 0x20000000)
#define RF5G1_CH0_PDTXMIX5_MSB                                                                    30
#define RF5G1_CH0_PDTXMIX5_LSB                                                                    30
#define RF5G1_CH0_PDTXMIX5_MASK                                                           0x40000000
#define RF5G1_CH0_PDTXMIX5_GET(x)                                         (((x) & 0x40000000) >> 30)
#define RF5G1_CH0_PDTXMIX5_SET(x)                                         (((x) << 30) & 0x40000000)
#define RF5G1_CH0_PDTXLO5_MSB                                                                     31
#define RF5G1_CH0_PDTXLO5_LSB                                                                     31
#define RF5G1_CH0_PDTXLO5_MASK                                                            0x80000000
#define RF5G1_CH0_PDTXLO5_GET(x)                                          (((x) & 0x80000000) >> 31)
#define RF5G1_CH0_PDTXLO5_SET(x)                                          (((x) << 31) & 0x80000000)

/* macros for RF5G2_CH0 */
#define RF5G2_CH0_ADDRESS                                                                 0x00000038
#define RF5G2_CH0_OFFSET                                                                  0x00000038
#define RF5G2_CH0_SPARE_MSB                                                                       10
#define RF5G2_CH0_SPARE_LSB                                                                        0
#define RF5G2_CH0_SPARE_MASK                                                              0x000007ff
#define RF5G2_CH0_SPARE_GET(x)                                             (((x) & 0x000007ff) >> 0)
#define RF5G2_CH0_SPARE_SET(x)                                             (((x) << 0) & 0x000007ff)
#define RF5G2_CH0_PDBIR2_MSB                                                                      13
#define RF5G2_CH0_PDBIR2_LSB                                                                      11
#define RF5G2_CH0_PDBIR2_MASK                                                             0x00003800
#define RF5G2_CH0_PDBIR2_GET(x)                                           (((x) & 0x00003800) >> 11)
#define RF5G2_CH0_PDBIR2_SET(x)                                           (((x) << 11) & 0x00003800)
#define RF5G2_CH0_PDBIR1_MSB                                                                      16
#define RF5G2_CH0_PDBIR1_LSB                                                                      14
#define RF5G2_CH0_PDBIR1_MASK                                                             0x0001c000
#define RF5G2_CH0_PDBIR1_GET(x)                                           (((x) & 0x0001c000) >> 14)
#define RF5G2_CH0_PDBIR1_SET(x)                                           (((x) << 14) & 0x0001c000)
#define RF5G2_CH0_PDBIRTXPA_MSB                                                                   19
#define RF5G2_CH0_PDBIRTXPA_LSB                                                                   17
#define RF5G2_CH0_PDBIRTXPA_MASK                                                          0x000e0000
#define RF5G2_CH0_PDBIRTXPA_GET(x)                                        (((x) & 0x000e0000) >> 17)
#define RF5G2_CH0_PDBIRTXPA_SET(x)                                        (((x) << 17) & 0x000e0000)
#define RF5G2_CH0_PDBIRTXMIX_MSB                                                                  22
#define RF5G2_CH0_PDBIRTXMIX_LSB                                                                  20
#define RF5G2_CH0_PDBIRTXMIX_MASK                                                         0x00700000
#define RF5G2_CH0_PDBIRTXMIX_GET(x)                                       (((x) & 0x00700000) >> 20)
#define RF5G2_CH0_PDBIRTXMIX_SET(x)                                       (((x) << 20) & 0x00700000)
#define RF5G2_CH0_RX5_ATB_SEL_MSB                                                                 25
#define RF5G2_CH0_RX5_ATB_SEL_LSB                                                                 23
#define RF5G2_CH0_RX5_ATB_SEL_MASK                                                        0x03800000
#define RF5G2_CH0_RX5_ATB_SEL_GET(x)                                      (((x) & 0x03800000) >> 23)
#define RF5G2_CH0_RX5_ATB_SEL_SET(x)                                      (((x) << 23) & 0x03800000)
#define RF5G2_CH0_PDRFVGA5_MSB                                                                    26
#define RF5G2_CH0_PDRFVGA5_LSB                                                                    26
#define RF5G2_CH0_PDRFVGA5_MASK                                                           0x04000000
#define RF5G2_CH0_PDRFVGA5_GET(x)                                         (((x) & 0x04000000) >> 26)
#define RF5G2_CH0_PDRFVGA5_SET(x)                                         (((x) << 26) & 0x04000000)
#define RF5G2_CH0_PDCSLNA5_MSB                                                                    27
#define RF5G2_CH0_PDCSLNA5_LSB                                                                    27
#define RF5G2_CH0_PDCSLNA5_MASK                                                           0x08000000
#define RF5G2_CH0_PDCSLNA5_GET(x)                                         (((x) & 0x08000000) >> 27)
#define RF5G2_CH0_PDCSLNA5_SET(x)                                         (((x) << 27) & 0x08000000)
#define RF5G2_CH0_PDVGM5_MSB                                                                      28
#define RF5G2_CH0_PDVGM5_LSB                                                                      28
#define RF5G2_CH0_PDVGM5_MASK                                                             0x10000000
#define RF5G2_CH0_PDVGM5_GET(x)                                           (((x) & 0x10000000) >> 28)
#define RF5G2_CH0_PDVGM5_SET(x)                                           (((x) << 28) & 0x10000000)
#define RF5G2_CH0_PDRXLO5_MSB                                                                     29
#define RF5G2_CH0_PDRXLO5_LSB                                                                     29
#define RF5G2_CH0_PDRXLO5_MASK                                                            0x20000000
#define RF5G2_CH0_PDRXLO5_GET(x)                                          (((x) & 0x20000000) >> 29)
#define RF5G2_CH0_PDRXLO5_SET(x)                                          (((x) << 29) & 0x20000000)
#define RF5G2_CH0_PDREGFE5_MSB                                                                    30
#define RF5G2_CH0_PDREGFE5_LSB                                                                    30
#define RF5G2_CH0_PDREGFE5_MASK                                                           0x40000000
#define RF5G2_CH0_PDREGFE5_GET(x)                                         (((x) & 0x40000000) >> 30)
#define RF5G2_CH0_PDREGFE5_SET(x)                                         (((x) << 30) & 0x40000000)
#define RF5G2_CH0_REGFE_BYPASS5_MSB                                                               31
#define RF5G2_CH0_REGFE_BYPASS5_LSB                                                               31
#define RF5G2_CH0_REGFE_BYPASS5_MASK                                                      0x80000000
#define RF5G2_CH0_REGFE_BYPASS5_GET(x)                                    (((x) & 0x80000000) >> 31)
#define RF5G2_CH0_REGFE_BYPASS5_SET(x)                                    (((x) << 31) & 0x80000000)

/* macros for RF5G3_CH0 */
#define RF5G3_CH0_ADDRESS                                                                 0x0000003c
#define RF5G3_CH0_OFFSET                                                                  0x0000003c
#define RF5G3_CH0_SPARE_MSB                                                                        4
#define RF5G3_CH0_SPARE_LSB                                                                        0
#define RF5G3_CH0_SPARE_MASK                                                              0x0000001f
#define RF5G3_CH0_SPARE_GET(x)                                             (((x) & 0x0000001f) >> 0)
#define RF5G3_CH0_SPARE_SET(x)                                             (((x) << 0) & 0x0000001f)
#define RF5G3_CH0_PDBIBCVGM_MSB                                                                    7
#define RF5G3_CH0_PDBIBCVGM_LSB                                                                    5
#define RF5G3_CH0_PDBIBCVGM_MASK                                                          0x000000e0
#define RF5G3_CH0_PDBIBCVGM_GET(x)                                         (((x) & 0x000000e0) >> 5)
#define RF5G3_CH0_PDBIBCVGM_SET(x)                                         (((x) << 5) & 0x000000e0)
#define RF5G3_CH0_PDBIBCRFVGA_MSB                                                                 10
#define RF5G3_CH0_PDBIBCRFVGA_LSB                                                                  8
#define RF5G3_CH0_PDBIBCRFVGA_MASK                                                        0x00000700
#define RF5G3_CH0_PDBIBCRFVGA_GET(x)                                       (((x) & 0x00000700) >> 8)
#define RF5G3_CH0_PDBIBCRFVGA_SET(x)                                       (((x) << 8) & 0x00000700)
#define RF5G3_CH0_PDBIBCLNA_MSB                                                                   13
#define RF5G3_CH0_PDBIBCLNA_LSB                                                                   11
#define RF5G3_CH0_PDBIBCLNA_MASK                                                          0x00003800
#define RF5G3_CH0_PDBIBCLNA_GET(x)                                        (((x) & 0x00003800) >> 11)
#define RF5G3_CH0_PDBIBCLNA_SET(x)                                        (((x) << 11) & 0x00003800)
#define RF5G3_CH0_PDBIC3_MSB                                                                      16
#define RF5G3_CH0_PDBIC3_LSB                                                                      14
#define RF5G3_CH0_PDBIC3_MASK                                                             0x0001c000
#define RF5G3_CH0_PDBIC3_GET(x)                                           (((x) & 0x0001c000) >> 14)
#define RF5G3_CH0_PDBIC3_SET(x)                                           (((x) << 14) & 0x0001c000)
#define RF5G3_CH0_PDBIC2_MSB                                                                      19
#define RF5G3_CH0_PDBIC2_LSB                                                                      17
#define RF5G3_CH0_PDBIC2_MASK                                                             0x000e0000
#define RF5G3_CH0_PDBIC2_GET(x)                                           (((x) & 0x000e0000) >> 17)
#define RF5G3_CH0_PDBIC2_SET(x)                                           (((x) << 17) & 0x000e0000)
#define RF5G3_CH0_PDBIC1_MSB                                                                      22
#define RF5G3_CH0_PDBIC1_LSB                                                                      20
#define RF5G3_CH0_PDBIC1_MASK                                                             0x00700000
#define RF5G3_CH0_PDBIC1_GET(x)                                           (((x) & 0x00700000) >> 20)
#define RF5G3_CH0_PDBIC1_SET(x)                                           (((x) << 20) & 0x00700000)
#define RF5G3_CH0_PDBICTXMIX_MSB                                                                  25
#define RF5G3_CH0_PDBICTXMIX_LSB                                                                  23
#define RF5G3_CH0_PDBICTXMIX_MASK                                                         0x03800000
#define RF5G3_CH0_PDBICTXMIX_GET(x)                                       (((x) & 0x03800000) >> 23)
#define RF5G3_CH0_PDBICTXMIX_SET(x)                                       (((x) << 23) & 0x03800000)
#define RF5G3_CH0_PDBICTXPA_MSB                                                                   28
#define RF5G3_CH0_PDBICTXPA_LSB                                                                   26
#define RF5G3_CH0_PDBICTXPA_MASK                                                          0x1c000000
#define RF5G3_CH0_PDBICTXPA_GET(x)                                        (((x) & 0x1c000000) >> 26)
#define RF5G3_CH0_PDBICTXPA_SET(x)                                        (((x) << 26) & 0x1c000000)
#define RF5G3_CH0_PDBICTXBUF_MSB                                                                  31
#define RF5G3_CH0_PDBICTXBUF_LSB                                                                  29
#define RF5G3_CH0_PDBICTXBUF_MASK                                                         0xe0000000
#define RF5G3_CH0_PDBICTXBUF_GET(x)                                       (((x) & 0xe0000000) >> 29)
#define RF5G3_CH0_PDBICTXBUF_SET(x)                                       (((x) << 29) & 0xe0000000)

/* macros for RF2G1_CH0 */
#define RF2G1_CH0_ADDRESS                                                                 0x00000040
#define RF2G1_CH0_OFFSET                                                                  0x00000040
#define RF2G1_CH0_SPARES_MSB                                                                       5
#define RF2G1_CH0_SPARES_LSB                                                                       0
#define RF2G1_CH0_SPARES_MASK                                                             0x0000003f
#define RF2G1_CH0_SPARES_GET(x)                                            (((x) & 0x0000003f) >> 0)
#define RF2G1_CH0_SPARES_SET(x)                                            (((x) << 0) & 0x0000003f)
#define RF2G1_CH0_REGLO_BYPASS_MSB                                                                 6
#define RF2G1_CH0_REGLO_BYPASS_LSB                                                                 6
#define RF2G1_CH0_REGLO_BYPASS_MASK                                                       0x00000040
#define RF2G1_CH0_REGLO_BYPASS_GET(x)                                      (((x) & 0x00000040) >> 6)
#define RF2G1_CH0_REGLO_BYPASS_SET(x)                                      (((x) << 6) & 0x00000040)
#define RF2G1_CH0_REGLNA_BYPASS_MSB                                                                7
#define RF2G1_CH0_REGLNA_BYPASS_LSB                                                                7
#define RF2G1_CH0_REGLNA_BYPASS_MASK                                                      0x00000080
#define RF2G1_CH0_REGLNA_BYPASS_GET(x)                                     (((x) & 0x00000080) >> 7)
#define RF2G1_CH0_REGLNA_BYPASS_SET(x)                                     (((x) << 7) & 0x00000080)
#define RF2G1_CH0_PDIC25U_VGM_MSB                                                                 10
#define RF2G1_CH0_PDIC25U_VGM_LSB                                                                  8
#define RF2G1_CH0_PDIC25U_VGM_MASK                                                        0x00000700
#define RF2G1_CH0_PDIC25U_VGM_GET(x)                                       (((x) & 0x00000700) >> 8)
#define RF2G1_CH0_PDIC25U_VGM_SET(x)                                       (((x) << 8) & 0x00000700)
#define RF2G1_CH0_PACA_SEL_MSB                                                                    12
#define RF2G1_CH0_PACA_SEL_LSB                                                                    11
#define RF2G1_CH0_PACA_SEL_MASK                                                           0x00001800
#define RF2G1_CH0_PACA_SEL_GET(x)                                         (((x) & 0x00001800) >> 11)
#define RF2G1_CH0_PACA_SEL_SET(x)                                         (((x) << 11) & 0x00001800)
#define RF2G1_CH0_LOCONTROL_MSB                                                                   13
#define RF2G1_CH0_LOCONTROL_LSB                                                                   13
#define RF2G1_CH0_LOCONTROL_MASK                                                          0x00002000
#define RF2G1_CH0_LOCONTROL_GET(x)                                        (((x) & 0x00002000) >> 13)
#define RF2G1_CH0_LOCONTROL_SET(x)                                        (((x) << 13) & 0x00002000)
#define RF2G1_CH0_TXATB_SEL_MSB                                                                   16
#define RF2G1_CH0_TXATB_SEL_LSB                                                                   14
#define RF2G1_CH0_TXATB_SEL_MASK                                                          0x0001c000
#define RF2G1_CH0_TXATB_SEL_GET(x)                                        (((x) & 0x0001c000) >> 14)
#define RF2G1_CH0_TXATB_SEL_SET(x)                                        (((x) << 14) & 0x0001c000)
#define RF2G1_CH0_RXATB_SEL_MSB                                                                   19
#define RF2G1_CH0_RXATB_SEL_LSB                                                                   17
#define RF2G1_CH0_RXATB_SEL_MASK                                                          0x000e0000
#define RF2G1_CH0_RXATB_SEL_GET(x)                                        (((x) & 0x000e0000) >> 17)
#define RF2G1_CH0_RXATB_SEL_SET(x)                                        (((x) << 17) & 0x000e0000)
#define RF2G1_CH0_LOATB_SEL_MSB                                                                   22
#define RF2G1_CH0_LOATB_SEL_LSB                                                                   20
#define RF2G1_CH0_LOATB_SEL_MASK                                                          0x00700000
#define RF2G1_CH0_LOATB_SEL_GET(x)                                        (((x) & 0x00700000) >> 20)
#define RF2G1_CH0_LOATB_SEL_SET(x)                                        (((x) << 20) & 0x00700000)
#define RF2G1_CH0_OB_MSB                                                                          25
#define RF2G1_CH0_OB_LSB                                                                          23
#define RF2G1_CH0_OB_MASK                                                                 0x03800000
#define RF2G1_CH0_OB_GET(x)                                               (((x) & 0x03800000) >> 23)
#define RF2G1_CH0_OB_SET(x)                                               (((x) << 23) & 0x03800000)
#define RF2G1_CH0_DB_MSB                                                                          28
#define RF2G1_CH0_DB_LSB                                                                          26
#define RF2G1_CH0_DB_MASK                                                                 0x1c000000
#define RF2G1_CH0_DB_GET(x)                                               (((x) & 0x1c000000) >> 26)
#define RF2G1_CH0_DB_SET(x)                                               (((x) << 26) & 0x1c000000)
#define RF2G1_CH0_PDIC25U_LNA_MSB                                                                 31
#define RF2G1_CH0_PDIC25U_LNA_LSB                                                                 29
#define RF2G1_CH0_PDIC25U_LNA_MASK                                                        0xe0000000
#define RF2G1_CH0_PDIC25U_LNA_GET(x)                                      (((x) & 0xe0000000) >> 29)
#define RF2G1_CH0_PDIC25U_LNA_SET(x)                                      (((x) << 29) & 0xe0000000)

/* macros for RF2G2_CH0 */
#define RF2G2_CH0_ADDRESS                                                                 0x00000044
#define RF2G2_CH0_OFFSET                                                                  0x00000044
#define RF2G2_CH0_PDIR25U_VREGLO_MSB                                                               2
#define RF2G2_CH0_PDIR25U_VREGLO_LSB                                                               0
#define RF2G2_CH0_PDIR25U_VREGLO_MASK                                                     0x00000007
#define RF2G2_CH0_PDIR25U_VREGLO_GET(x)                                    (((x) & 0x00000007) >> 0)
#define RF2G2_CH0_PDIR25U_VREGLO_SET(x)                                    (((x) << 0) & 0x00000007)
#define RF2G2_CH0_PDIC25U_VREGLO_MSB                                                               5
#define RF2G2_CH0_PDIC25U_VREGLO_LSB                                                               3
#define RF2G2_CH0_PDIC25U_VREGLO_MASK                                                     0x00000038
#define RF2G2_CH0_PDIC25U_VREGLO_GET(x)                                    (((x) & 0x00000038) >> 3)
#define RF2G2_CH0_PDIC25U_VREGLO_SET(x)                                    (((x) << 3) & 0x00000038)
#define RF2G2_CH0_PDIC50U_DIV_MSB                                                                  8
#define RF2G2_CH0_PDIC50U_DIV_LSB                                                                  6
#define RF2G2_CH0_PDIC50U_DIV_MASK                                                        0x000001c0
#define RF2G2_CH0_PDIC50U_DIV_GET(x)                                       (((x) & 0x000001c0) >> 6)
#define RF2G2_CH0_PDIC50U_DIV_SET(x)                                       (((x) << 6) & 0x000001c0)
#define RF2G2_CH0_PDIC25U_RXRF_MSB                                                                11
#define RF2G2_CH0_PDIC25U_RXRF_LSB                                                                 9
#define RF2G2_CH0_PDIC25U_RXRF_MASK                                                       0x00000e00
#define RF2G2_CH0_PDIC25U_RXRF_GET(x)                                      (((x) & 0x00000e00) >> 9)
#define RF2G2_CH0_PDIC25U_RXRF_SET(x)                                      (((x) << 9) & 0x00000e00)
#define RF2G2_CH0_PDIC25U_TXRF_MSB                                                                14
#define RF2G2_CH0_PDIC25U_TXRF_LSB                                                                12
#define RF2G2_CH0_PDIC25U_TXRF_MASK                                                       0x00007000
#define RF2G2_CH0_PDIC25U_TXRF_GET(x)                                     (((x) & 0x00007000) >> 12)
#define RF2G2_CH0_PDIC25U_TXRF_SET(x)                                     (((x) << 12) & 0x00007000)
#define RF2G2_CH0_PDIC25U_TXPA_MSB                                                                17
#define RF2G2_CH0_PDIC25U_TXPA_LSB                                                                15
#define RF2G2_CH0_PDIC25U_TXPA_MASK                                                       0x00038000
#define RF2G2_CH0_PDIC25U_TXPA_GET(x)                                     (((x) & 0x00038000) >> 15)
#define RF2G2_CH0_PDIC25U_TXPA_SET(x)                                     (((x) << 15) & 0x00038000)
#define RF2G2_CH0_PDIR25U_TXPA_MSB                                                                18
#define RF2G2_CH0_PDIR25U_TXPA_LSB                                                                18
#define RF2G2_CH0_PDIR25U_TXPA_MASK                                                       0x00040000
#define RF2G2_CH0_PDIR25U_TXPA_GET(x)                                     (((x) & 0x00040000) >> 18)
#define RF2G2_CH0_PDIR25U_TXPA_SET(x)                                     (((x) << 18) & 0x00040000)
#define RF2G2_CH0_PDIR25U_TXMIX_MSB                                                               21
#define RF2G2_CH0_PDIR25U_TXMIX_LSB                                                               19
#define RF2G2_CH0_PDIR25U_TXMIX_MASK                                                      0x00380000
#define RF2G2_CH0_PDIR25U_TXMIX_GET(x)                                    (((x) & 0x00380000) >> 19)
#define RF2G2_CH0_PDIR25U_TXMIX_SET(x)                                    (((x) << 19) & 0x00380000)
#define RF2G2_CH0_PDTXMIX_MSB                                                                     22
#define RF2G2_CH0_PDTXMIX_LSB                                                                     22
#define RF2G2_CH0_PDTXMIX_MASK                                                            0x00400000
#define RF2G2_CH0_PDTXMIX_GET(x)                                          (((x) & 0x00400000) >> 22)
#define RF2G2_CH0_PDTXMIX_SET(x)                                          (((x) << 22) & 0x00400000)
#define RF2G2_CH0_PDTXLO_MSB                                                                      23
#define RF2G2_CH0_PDTXLO_LSB                                                                      23
#define RF2G2_CH0_PDTXLO_MASK                                                             0x00800000
#define RF2G2_CH0_PDTXLO_GET(x)                                           (((x) & 0x00800000) >> 23)
#define RF2G2_CH0_PDTXLO_SET(x)                                           (((x) << 23) & 0x00800000)
#define RF2G2_CH0_PDRXLO_MSB                                                                      24
#define RF2G2_CH0_PDRXLO_LSB                                                                      24
#define RF2G2_CH0_PDRXLO_MASK                                                             0x01000000
#define RF2G2_CH0_PDRXLO_GET(x)                                           (((x) & 0x01000000) >> 24)
#define RF2G2_CH0_PDRXLO_SET(x)                                           (((x) << 24) & 0x01000000)
#define RF2G2_CH0_PDVGM_MSB                                                                       25
#define RF2G2_CH0_PDVGM_LSB                                                                       25
#define RF2G2_CH0_PDVGM_MASK                                                              0x02000000
#define RF2G2_CH0_PDVGM_GET(x)                                            (((x) & 0x02000000) >> 25)
#define RF2G2_CH0_PDVGM_SET(x)                                            (((x) << 25) & 0x02000000)
#define RF2G2_CH0_PDREGLO_MSB                                                                     26
#define RF2G2_CH0_PDREGLO_LSB                                                                     26
#define RF2G2_CH0_PDREGLO_MASK                                                            0x04000000
#define RF2G2_CH0_PDREGLO_GET(x)                                          (((x) & 0x04000000) >> 26)
#define RF2G2_CH0_PDREGLO_SET(x)                                          (((x) << 26) & 0x04000000)
#define RF2G2_CH0_PDREGLNA_MSB                                                                    27
#define RF2G2_CH0_PDREGLNA_LSB                                                                    27
#define RF2G2_CH0_PDREGLNA_MASK                                                           0x08000000
#define RF2G2_CH0_PDREGLNA_GET(x)                                         (((x) & 0x08000000) >> 27)
#define RF2G2_CH0_PDREGLNA_SET(x)                                         (((x) << 27) & 0x08000000)
#define RF2G2_CH0_PDPAOUT_MSB                                                                     28
#define RF2G2_CH0_PDPAOUT_LSB                                                                     28
#define RF2G2_CH0_PDPAOUT_MASK                                                            0x10000000
#define RF2G2_CH0_PDPAOUT_GET(x)                                          (((x) & 0x10000000) >> 28)
#define RF2G2_CH0_PDPAOUT_SET(x)                                          (((x) << 28) & 0x10000000)
#define RF2G2_CH0_PDPADRV_MSB                                                                     29
#define RF2G2_CH0_PDPADRV_LSB                                                                     29
#define RF2G2_CH0_PDPADRV_MASK                                                            0x20000000
#define RF2G2_CH0_PDPADRV_GET(x)                                          (((x) & 0x20000000) >> 29)
#define RF2G2_CH0_PDPADRV_SET(x)                                          (((x) << 29) & 0x20000000)
#define RF2G2_CH0_PDDIV_MSB                                                                       30
#define RF2G2_CH0_PDDIV_LSB                                                                       30
#define RF2G2_CH0_PDDIV_MASK                                                              0x40000000
#define RF2G2_CH0_PDDIV_GET(x)                                            (((x) & 0x40000000) >> 30)
#define RF2G2_CH0_PDDIV_SET(x)                                            (((x) << 30) & 0x40000000)
#define RF2G2_CH0_PDLNA_MSB                                                                       31
#define RF2G2_CH0_PDLNA_LSB                                                                       31
#define RF2G2_CH0_PDLNA_MASK                                                              0x80000000
#define RF2G2_CH0_PDLNA_GET(x)                                            (((x) & 0x80000000) >> 31)
#define RF2G2_CH0_PDLNA_SET(x)                                            (((x) << 31) & 0x80000000)

/* macros for SYNTH1 */
#define SYNTH1_ADDRESS                                                                    0x00000048
#define SYNTH1_OFFSET                                                                     0x00000048
#define SYNTH1_SEL_VCMONABUS_MSB                                                                   2
#define SYNTH1_SEL_VCMONABUS_LSB                                                                   0
#define SYNTH1_SEL_VCMONABUS_MASK                                                         0x00000007
#define SYNTH1_SEL_VCMONABUS_GET(x)                                        (((x) & 0x00000007) >> 0)
#define SYNTH1_SEL_VCMONABUS_SET(x)                                        (((x) << 0) & 0x00000007)
#define SYNTH1_CON_IVCOBUF_MSB                                                                     3
#define SYNTH1_CON_IVCOBUF_LSB                                                                     3
#define SYNTH1_CON_IVCOBUF_MASK                                                           0x00000008
#define SYNTH1_CON_IVCOBUF_GET(x)                                          (((x) & 0x00000008) >> 3)
#define SYNTH1_CON_IVCOBUF_SET(x)                                          (((x) << 3) & 0x00000008)
#define SYNTH1_CON_IVCOREG_MSB                                                                     4
#define SYNTH1_CON_IVCOREG_LSB                                                                     4
#define SYNTH1_CON_IVCOREG_MASK                                                           0x00000010
#define SYNTH1_CON_IVCOREG_GET(x)                                          (((x) & 0x00000010) >> 4)
#define SYNTH1_CON_IVCOREG_SET(x)                                          (((x) << 4) & 0x00000010)
#define SYNTH1_CON_VDDVCOREG_MSB                                                                   5
#define SYNTH1_CON_VDDVCOREG_LSB                                                                   5
#define SYNTH1_CON_VDDVCOREG_MASK                                                         0x00000020
#define SYNTH1_CON_VDDVCOREG_GET(x)                                        (((x) & 0x00000020) >> 5)
#define SYNTH1_CON_VDDVCOREG_SET(x)                                        (((x) << 5) & 0x00000020)
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_MSB                                                           6
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_LSB                                                           6
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_MASK                                                 0x00000040
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_GET(x)                                (((x) & 0x00000040) >> 6)
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_SET(x)                                (((x) << 6) & 0x00000040)
#define SYNTH1_MONITOR_VC2LOW_MSB                                                                  7
#define SYNTH1_MONITOR_VC2LOW_LSB                                                                  7
#define SYNTH1_MONITOR_VC2LOW_MASK                                                        0x00000080
#define SYNTH1_MONITOR_VC2LOW_GET(x)                                       (((x) & 0x00000080) >> 7)
#define SYNTH1_MONITOR_VC2LOW_SET(x)                                       (((x) << 7) & 0x00000080)
#define SYNTH1_MONITOR_VC2HIGH_MSB                                                                 8
#define SYNTH1_MONITOR_VC2HIGH_LSB                                                                 8
#define SYNTH1_MONITOR_VC2HIGH_MASK                                                       0x00000100
#define SYNTH1_MONITOR_VC2HIGH_GET(x)                                      (((x) & 0x00000100) >> 8)
#define SYNTH1_MONITOR_VC2HIGH_SET(x)                                      (((x) << 8) & 0x00000100)
#define SYNTH1_MONITOR_FB_DIV2_MSB                                                                 9
#define SYNTH1_MONITOR_FB_DIV2_LSB                                                                 9
#define SYNTH1_MONITOR_FB_DIV2_MASK                                                       0x00000200
#define SYNTH1_MONITOR_FB_DIV2_GET(x)                                      (((x) & 0x00000200) >> 9)
#define SYNTH1_MONITOR_FB_DIV2_SET(x)                                      (((x) << 9) & 0x00000200)
#define SYNTH1_MONITOR_REF_MSB                                                                    10
#define SYNTH1_MONITOR_REF_LSB                                                                    10
#define SYNTH1_MONITOR_REF_MASK                                                           0x00000400
#define SYNTH1_MONITOR_REF_GET(x)                                         (((x) & 0x00000400) >> 10)
#define SYNTH1_MONITOR_REF_SET(x)                                         (((x) << 10) & 0x00000400)
#define SYNTH1_MONITOR_FB_MSB                                                                     11
#define SYNTH1_MONITOR_FB_LSB                                                                     11
#define SYNTH1_MONITOR_FB_MASK                                                            0x00000800
#define SYNTH1_MONITOR_FB_GET(x)                                          (((x) & 0x00000800) >> 11)
#define SYNTH1_MONITOR_FB_SET(x)                                          (((x) << 11) & 0x00000800)
#define SYNTH1_PWUP_LOMIX_PD_MSB                                                                  12
#define SYNTH1_PWUP_LOMIX_PD_LSB                                                                  12
#define SYNTH1_PWUP_LOMIX_PD_MASK                                                         0x00001000
#define SYNTH1_PWUP_LOMIX_PD_GET(x)                                       (((x) & 0x00001000) >> 12)
#define SYNTH1_PWUP_LOMIX_PD_SET(x)                                       (((x) << 12) & 0x00001000)
#define SYNTH1_PWUP_LODIV_PD_MSB                                                                  13
#define SYNTH1_PWUP_LODIV_PD_LSB                                                                  13
#define SYNTH1_PWUP_LODIV_PD_MASK                                                         0x00002000
#define SYNTH1_PWUP_LODIV_PD_GET(x)                                       (((x) & 0x00002000) >> 13)
#define SYNTH1_PWUP_LODIV_PD_SET(x)                                       (((x) << 13) & 0x00002000)
#define SYNTH1_PWUP_LOBUF5G_PD_MSB                                                                14
#define SYNTH1_PWUP_LOBUF5G_PD_LSB                                                                14
#define SYNTH1_PWUP_LOBUF5G_PD_MASK                                                       0x00004000
#define SYNTH1_PWUP_LOBUF5G_PD_GET(x)                                     (((x) & 0x00004000) >> 14)
#define SYNTH1_PWUP_LOBUF5G_PD_SET(x)                                     (((x) << 14) & 0x00004000)
#define SYNTH1_PWUP_LOBUF2G_PD_MSB                                                                15
#define SYNTH1_PWUP_LOBUF2G_PD_LSB                                                                15
#define SYNTH1_PWUP_LOBUF2G_PD_MASK                                                       0x00008000
#define SYNTH1_PWUP_LOBUF2G_PD_GET(x)                                     (((x) & 0x00008000) >> 15)
#define SYNTH1_PWUP_LOBUF2G_PD_SET(x)                                     (((x) << 15) & 0x00008000)
#define SYNTH1_PWUP_VCOBUF_PD_MSB                                                                 16
#define SYNTH1_PWUP_VCOBUF_PD_LSB                                                                 16
#define SYNTH1_PWUP_VCOBUF_PD_MASK                                                        0x00010000
#define SYNTH1_PWUP_VCOBUF_PD_GET(x)                                      (((x) & 0x00010000) >> 16)
#define SYNTH1_PWUP_VCOBUF_PD_SET(x)                                      (((x) << 16) & 0x00010000)
#define SYNTH1_VCOBUFBIAS_MSB                                                                     18
#define SYNTH1_VCOBUFBIAS_LSB                                                                     17
#define SYNTH1_VCOBUFBIAS_MASK                                                            0x00060000
#define SYNTH1_VCOBUFBIAS_GET(x)                                          (((x) & 0x00060000) >> 17)
#define SYNTH1_VCOBUFBIAS_SET(x)                                          (((x) << 17) & 0x00060000)
#define SYNTH1_VCOREGLEVEL_MSB                                                                    20
#define SYNTH1_VCOREGLEVEL_LSB                                                                    19
#define SYNTH1_VCOREGLEVEL_MASK                                                           0x00180000
#define SYNTH1_VCOREGLEVEL_GET(x)                                         (((x) & 0x00180000) >> 19)
#define SYNTH1_VCOREGLEVEL_SET(x)                                         (((x) << 19) & 0x00180000)
#define SYNTH1_VCOREGBYPASS_MSB                                                                   21
#define SYNTH1_VCOREGBYPASS_LSB                                                                   21
#define SYNTH1_VCOREGBYPASS_MASK                                                          0x00200000
#define SYNTH1_VCOREGBYPASS_GET(x)                                        (((x) & 0x00200000) >> 21)
#define SYNTH1_VCOREGBYPASS_SET(x)                                        (((x) << 21) & 0x00200000)
#define SYNTH1_PWUP_LOREF_MSB                                                                     22
#define SYNTH1_PWUP_LOREF_LSB                                                                     22
#define SYNTH1_PWUP_LOREF_MASK                                                            0x00400000
#define SYNTH1_PWUP_LOREF_GET(x)                                          (((x) & 0x00400000) >> 22)
#define SYNTH1_PWUP_LOREF_SET(x)                                          (((x) << 22) & 0x00400000)
#define SYNTH1_PWD_LOMIX_MSB                                                                      23
#define SYNTH1_PWD_LOMIX_LSB                                                                      23
#define SYNTH1_PWD_LOMIX_MASK                                                             0x00800000
#define SYNTH1_PWD_LOMIX_GET(x)                                           (((x) & 0x00800000) >> 23)
#define SYNTH1_PWD_LOMIX_SET(x)                                           (((x) << 23) & 0x00800000)
#define SYNTH1_PWD_LODIV_MSB                                                                      24
#define SYNTH1_PWD_LODIV_LSB                                                                      24
#define SYNTH1_PWD_LODIV_MASK                                                             0x01000000
#define SYNTH1_PWD_LODIV_GET(x)                                           (((x) & 0x01000000) >> 24)
#define SYNTH1_PWD_LODIV_SET(x)                                           (((x) << 24) & 0x01000000)
#define SYNTH1_PWD_LOBUF5G_MSB                                                                    25
#define SYNTH1_PWD_LOBUF5G_LSB                                                                    25
#define SYNTH1_PWD_LOBUF5G_MASK                                                           0x02000000
#define SYNTH1_PWD_LOBUF5G_GET(x)                                         (((x) & 0x02000000) >> 25)
#define SYNTH1_PWD_LOBUF5G_SET(x)                                         (((x) << 25) & 0x02000000)
#define SYNTH1_PWD_LOBUF2G_MSB                                                                    26
#define SYNTH1_PWD_LOBUF2G_LSB                                                                    26
#define SYNTH1_PWD_LOBUF2G_MASK                                                           0x04000000
#define SYNTH1_PWD_LOBUF2G_GET(x)                                         (((x) & 0x04000000) >> 26)
#define SYNTH1_PWD_LOBUF2G_SET(x)                                         (((x) << 26) & 0x04000000)
#define SYNTH1_PWD_PRESC_MSB                                                                      27
#define SYNTH1_PWD_PRESC_LSB                                                                      27
#define SYNTH1_PWD_PRESC_MASK                                                             0x08000000
#define SYNTH1_PWD_PRESC_GET(x)                                           (((x) & 0x08000000) >> 27)
#define SYNTH1_PWD_PRESC_SET(x)                                           (((x) << 27) & 0x08000000)
#define SYNTH1_PWD_VCO_MSB                                                                        28
#define SYNTH1_PWD_VCO_LSB                                                                        28
#define SYNTH1_PWD_VCO_MASK                                                               0x10000000
#define SYNTH1_PWD_VCO_GET(x)                                             (((x) & 0x10000000) >> 28)
#define SYNTH1_PWD_VCO_SET(x)                                             (((x) << 28) & 0x10000000)
#define SYNTH1_PWD_VCMON_MSB                                                                      29
#define SYNTH1_PWD_VCMON_LSB                                                                      29
#define SYNTH1_PWD_VCMON_MASK                                                             0x20000000
#define SYNTH1_PWD_VCMON_GET(x)                                           (((x) & 0x20000000) >> 29)
#define SYNTH1_PWD_VCMON_SET(x)                                           (((x) << 29) & 0x20000000)
#define SYNTH1_PWD_CP_MSB                                                                         30
#define SYNTH1_PWD_CP_LSB                                                                         30
#define SYNTH1_PWD_CP_MASK                                                                0x40000000
#define SYNTH1_PWD_CP_GET(x)                                              (((x) & 0x40000000) >> 30)
#define SYNTH1_PWD_CP_SET(x)                                              (((x) << 30) & 0x40000000)
#define SYNTH1_PWD_BIAS_MSB                                                                       31
#define SYNTH1_PWD_BIAS_LSB                                                                       31
#define SYNTH1_PWD_BIAS_MASK                                                              0x80000000
#define SYNTH1_PWD_BIAS_GET(x)                                            (((x) & 0x80000000) >> 31)
#define SYNTH1_PWD_BIAS_SET(x)                                            (((x) << 31) & 0x80000000)

/* macros for SYNTH2 */
#define SYNTH2_ADDRESS                                                                    0x0000004c
#define SYNTH2_OFFSET                                                                     0x0000004c
#define SYNTH2_CAPRANGE3_MSB                                                                       3
#define SYNTH2_CAPRANGE3_LSB                                                                       0
#define SYNTH2_CAPRANGE3_MASK                                                             0x0000000f
#define SYNTH2_CAPRANGE3_GET(x)                                            (((x) & 0x0000000f) >> 0)
#define SYNTH2_CAPRANGE3_SET(x)                                            (((x) << 0) & 0x0000000f)
#define SYNTH2_CAPRANGE2_MSB                                                                       7
#define SYNTH2_CAPRANGE2_LSB                                                                       4
#define SYNTH2_CAPRANGE2_MASK                                                             0x000000f0
#define SYNTH2_CAPRANGE2_GET(x)                                            (((x) & 0x000000f0) >> 4)
#define SYNTH2_CAPRANGE2_SET(x)                                            (((x) << 4) & 0x000000f0)
#define SYNTH2_CAPRANGE1_MSB                                                                      11
#define SYNTH2_CAPRANGE1_LSB                                                                       8
#define SYNTH2_CAPRANGE1_MASK                                                             0x00000f00
#define SYNTH2_CAPRANGE1_GET(x)                                            (((x) & 0x00000f00) >> 8)
#define SYNTH2_CAPRANGE1_SET(x)                                            (((x) << 8) & 0x00000f00)
#define SYNTH2_LOOPLEAKCUR_MSB                                                                    15
#define SYNTH2_LOOPLEAKCUR_LSB                                                                    12
#define SYNTH2_LOOPLEAKCUR_MASK                                                           0x0000f000
#define SYNTH2_LOOPLEAKCUR_GET(x)                                         (((x) & 0x0000f000) >> 12)
#define SYNTH2_LOOPLEAKCUR_SET(x)                                         (((x) << 12) & 0x0000f000)
#define SYNTH2_CPLOWLK_MSB                                                                        16
#define SYNTH2_CPLOWLK_LSB                                                                        16
#define SYNTH2_CPLOWLK_MASK                                                               0x00010000
#define SYNTH2_CPLOWLK_GET(x)                                             (((x) & 0x00010000) >> 16)
#define SYNTH2_CPLOWLK_SET(x)                                             (((x) << 16) & 0x00010000)
#define SYNTH2_CPSTEERING_EN_INTN_MSB                                                             17
#define SYNTH2_CPSTEERING_EN_INTN_LSB                                                             17
#define SYNTH2_CPSTEERING_EN_INTN_MASK                                                    0x00020000
#define SYNTH2_CPSTEERING_EN_INTN_GET(x)                                  (((x) & 0x00020000) >> 17)
#define SYNTH2_CPSTEERING_EN_INTN_SET(x)                                  (((x) << 17) & 0x00020000)
#define SYNTH2_CPBIAS_MSB                                                                         19
#define SYNTH2_CPBIAS_LSB                                                                         18
#define SYNTH2_CPBIAS_MASK                                                                0x000c0000
#define SYNTH2_CPBIAS_GET(x)                                              (((x) & 0x000c0000) >> 18)
#define SYNTH2_CPBIAS_SET(x)                                              (((x) << 18) & 0x000c0000)
#define SYNTH2_VC_LOW_REF_MSB                                                                     22
#define SYNTH2_VC_LOW_REF_LSB                                                                     20
#define SYNTH2_VC_LOW_REF_MASK                                                            0x00700000
#define SYNTH2_VC_LOW_REF_GET(x)                                          (((x) & 0x00700000) >> 20)
#define SYNTH2_VC_LOW_REF_SET(x)                                          (((x) << 20) & 0x00700000)
#define SYNTH2_VC_MID_REF_MSB                                                                     25
#define SYNTH2_VC_MID_REF_LSB                                                                     23
#define SYNTH2_VC_MID_REF_MASK                                                            0x03800000
#define SYNTH2_VC_MID_REF_GET(x)                                          (((x) & 0x03800000) >> 23)
#define SYNTH2_VC_MID_REF_SET(x)                                          (((x) << 23) & 0x03800000)
#define SYNTH2_VC_HI_REF_MSB                                                                      28
#define SYNTH2_VC_HI_REF_LSB                                                                      26
#define SYNTH2_VC_HI_REF_MASK                                                             0x1c000000
#define SYNTH2_VC_HI_REF_GET(x)                                           (((x) & 0x1c000000) >> 26)
#define SYNTH2_VC_HI_REF_SET(x)                                           (((x) << 26) & 0x1c000000)
#define SYNTH2_VC_CAL_REF_MSB                                                                     31
#define SYNTH2_VC_CAL_REF_LSB                                                                     29
#define SYNTH2_VC_CAL_REF_MASK                                                            0xe0000000
#define SYNTH2_VC_CAL_REF_GET(x)                                          (((x) & 0xe0000000) >> 29)
#define SYNTH2_VC_CAL_REF_SET(x)                                          (((x) << 29) & 0xe0000000)

/* macros for SYNTH3 */
#define SYNTH3_ADDRESS                                                                    0x00000050
#define SYNTH3_OFFSET                                                                     0x00000050
#define SYNTH3_WAIT_VC_CHECK_MSB                                                                   5
#define SYNTH3_WAIT_VC_CHECK_LSB                                                                   0
#define SYNTH3_WAIT_VC_CHECK_MASK                                                         0x0000003f
#define SYNTH3_WAIT_VC_CHECK_GET(x)                                        (((x) & 0x0000003f) >> 0)
#define SYNTH3_WAIT_VC_CHECK_SET(x)                                        (((x) << 0) & 0x0000003f)
#define SYNTH3_WAIT_CAL_LIN_MSB                                                                   11
#define SYNTH3_WAIT_CAL_LIN_LSB                                                                    6
#define SYNTH3_WAIT_CAL_LIN_MASK                                                          0x00000fc0
#define SYNTH3_WAIT_CAL_LIN_GET(x)                                         (((x) & 0x00000fc0) >> 6)
#define SYNTH3_WAIT_CAL_LIN_SET(x)                                         (((x) << 6) & 0x00000fc0)
#define SYNTH3_WAIT_CAL_BIN_MSB                                                                   17
#define SYNTH3_WAIT_CAL_BIN_LSB                                                                   12
#define SYNTH3_WAIT_CAL_BIN_MASK                                                          0x0003f000
#define SYNTH3_WAIT_CAL_BIN_GET(x)                                        (((x) & 0x0003f000) >> 12)
#define SYNTH3_WAIT_CAL_BIN_SET(x)                                        (((x) << 12) & 0x0003f000)
#define SYNTH3_WAIT_PWRUP_MSB                                                                     23
#define SYNTH3_WAIT_PWRUP_LSB                                                                     18
#define SYNTH3_WAIT_PWRUP_MASK                                                            0x00fc0000
#define SYNTH3_WAIT_PWRUP_GET(x)                                          (((x) & 0x00fc0000) >> 18)
#define SYNTH3_WAIT_PWRUP_SET(x)                                          (((x) << 18) & 0x00fc0000)
#define SYNTH3_WAIT_SHORTR_PWRUP_MSB                                                              29
#define SYNTH3_WAIT_SHORTR_PWRUP_LSB                                                              24
#define SYNTH3_WAIT_SHORTR_PWRUP_MASK                                                     0x3f000000
#define SYNTH3_WAIT_SHORTR_PWRUP_GET(x)                                   (((x) & 0x3f000000) >> 24)
#define SYNTH3_WAIT_SHORTR_PWRUP_SET(x)                                   (((x) << 24) & 0x3f000000)
#define SYNTH3_SEL_CLK_DIV2_MSB                                                                   30
#define SYNTH3_SEL_CLK_DIV2_LSB                                                                   30
#define SYNTH3_SEL_CLK_DIV2_MASK                                                          0x40000000
#define SYNTH3_SEL_CLK_DIV2_GET(x)                                        (((x) & 0x40000000) >> 30)
#define SYNTH3_SEL_CLK_DIV2_SET(x)                                        (((x) << 30) & 0x40000000)
#define SYNTH3_DIS_CLK_XTAL_MSB                                                                   31
#define SYNTH3_DIS_CLK_XTAL_LSB                                                                   31
#define SYNTH3_DIS_CLK_XTAL_MASK                                                          0x80000000
#define SYNTH3_DIS_CLK_XTAL_GET(x)                                        (((x) & 0x80000000) >> 31)
#define SYNTH3_DIS_CLK_XTAL_SET(x)                                        (((x) << 31) & 0x80000000)

/* macros for SYNTH4 */
#define SYNTH4_ADDRESS                                                                    0x00000054
#define SYNTH4_OFFSET                                                                     0x00000054
#define SYNTH4_FORCE_SHIFTREG_MSB                                                                  0
#define SYNTH4_FORCE_SHIFTREG_LSB                                                                  0
#define SYNTH4_FORCE_SHIFTREG_MASK                                                        0x00000001
#define SYNTH4_FORCE_SHIFTREG_GET(x)                                       (((x) & 0x00000001) >> 0)
#define SYNTH4_FORCE_SHIFTREG_SET(x)                                       (((x) << 0) & 0x00000001)
#define SYNTH4_LONGSHIFTSEL_MSB                                                                    1
#define SYNTH4_LONGSHIFTSEL_LSB                                                                    1
#define SYNTH4_LONGSHIFTSEL_MASK                                                          0x00000002
#define SYNTH4_LONGSHIFTSEL_GET(x)                                         (((x) & 0x00000002) >> 1)
#define SYNTH4_LONGSHIFTSEL_SET(x)                                         (((x) << 1) & 0x00000002)
#define SYNTH4_LOBUF5GTUNE_OVR_MSB                                                                 3
#define SYNTH4_LOBUF5GTUNE_OVR_LSB                                                                 2
#define SYNTH4_LOBUF5GTUNE_OVR_MASK                                                       0x0000000c
#define SYNTH4_LOBUF5GTUNE_OVR_GET(x)                                      (((x) & 0x0000000c) >> 2)
#define SYNTH4_LOBUF5GTUNE_OVR_SET(x)                                      (((x) << 2) & 0x0000000c)
#define SYNTH4_FORCE_LOBUF5GTUNE_MSB                                                               4
#define SYNTH4_FORCE_LOBUF5GTUNE_LSB                                                               4
#define SYNTH4_FORCE_LOBUF5GTUNE_MASK                                                     0x00000010
#define SYNTH4_FORCE_LOBUF5GTUNE_GET(x)                                    (((x) & 0x00000010) >> 4)
#define SYNTH4_FORCE_LOBUF5GTUNE_SET(x)                                    (((x) << 4) & 0x00000010)
#define SYNTH4_PSCOUNT_FBSEL_MSB                                                                   5
#define SYNTH4_PSCOUNT_FBSEL_LSB                                                                   5
#define SYNTH4_PSCOUNT_FBSEL_MASK                                                         0x00000020
#define SYNTH4_PSCOUNT_FBSEL_GET(x)                                        (((x) & 0x00000020) >> 5)
#define SYNTH4_PSCOUNT_FBSEL_SET(x)                                        (((x) << 5) & 0x00000020)
#define SYNTH4_SDM_DITHER_MSB                                                                      7
#define SYNTH4_SDM_DITHER_LSB                                                                      6
#define SYNTH4_SDM_DITHER_MASK                                                            0x000000c0
#define SYNTH4_SDM_DITHER_GET(x)                                           (((x) & 0x000000c0) >> 6)
#define SYNTH4_SDM_DITHER_SET(x)                                           (((x) << 6) & 0x000000c0)
#define SYNTH4_SDM_MODE_MSB                                                                        8
#define SYNTH4_SDM_MODE_LSB                                                                        8
#define SYNTH4_SDM_MODE_MASK                                                              0x00000100
#define SYNTH4_SDM_MODE_GET(x)                                             (((x) & 0x00000100) >> 8)
#define SYNTH4_SDM_MODE_SET(x)                                             (((x) << 8) & 0x00000100)
#define SYNTH4_SDM_DISABLE_MSB                                                                     9
#define SYNTH4_SDM_DISABLE_LSB                                                                     9
#define SYNTH4_SDM_DISABLE_MASK                                                           0x00000200
#define SYNTH4_SDM_DISABLE_GET(x)                                          (((x) & 0x00000200) >> 9)
#define SYNTH4_SDM_DISABLE_SET(x)                                          (((x) << 9) & 0x00000200)
#define SYNTH4_RESET_PRESC_MSB                                                                    10
#define SYNTH4_RESET_PRESC_LSB                                                                    10
#define SYNTH4_RESET_PRESC_MASK                                                           0x00000400
#define SYNTH4_RESET_PRESC_GET(x)                                         (((x) & 0x00000400) >> 10)
#define SYNTH4_RESET_PRESC_SET(x)                                         (((x) << 10) & 0x00000400)
#define SYNTH4_PRESCSEL_MSB                                                                       12
#define SYNTH4_PRESCSEL_LSB                                                                       11
#define SYNTH4_PRESCSEL_MASK                                                              0x00001800
#define SYNTH4_PRESCSEL_GET(x)                                            (((x) & 0x00001800) >> 11)
#define SYNTH4_PRESCSEL_SET(x)                                            (((x) << 11) & 0x00001800)
#define SYNTH4_PFD_DISABLE_MSB                                                                    13
#define SYNTH4_PFD_DISABLE_LSB                                                                    13
#define SYNTH4_PFD_DISABLE_MASK                                                           0x00002000
#define SYNTH4_PFD_DISABLE_GET(x)                                         (((x) & 0x00002000) >> 13)
#define SYNTH4_PFD_DISABLE_SET(x)                                         (((x) << 13) & 0x00002000)
#define SYNTH4_PFDDELAY_FRACN_MSB                                                                 14
#define SYNTH4_PFDDELAY_FRACN_LSB                                                                 14
#define SYNTH4_PFDDELAY_FRACN_MASK                                                        0x00004000
#define SYNTH4_PFDDELAY_FRACN_GET(x)                                      (((x) & 0x00004000) >> 14)
#define SYNTH4_PFDDELAY_FRACN_SET(x)                                      (((x) << 14) & 0x00004000)
#define SYNTH4_FORCE_LO_ON_MSB                                                                    15
#define SYNTH4_FORCE_LO_ON_LSB                                                                    15
#define SYNTH4_FORCE_LO_ON_MASK                                                           0x00008000
#define SYNTH4_FORCE_LO_ON_GET(x)                                         (((x) & 0x00008000) >> 15)
#define SYNTH4_FORCE_LO_ON_SET(x)                                         (((x) << 15) & 0x00008000)
#define SYNTH4_CLKXTAL_EDGE_SEL_MSB                                                               16
#define SYNTH4_CLKXTAL_EDGE_SEL_LSB                                                               16
#define SYNTH4_CLKXTAL_EDGE_SEL_MASK                                                      0x00010000
#define SYNTH4_CLKXTAL_EDGE_SEL_GET(x)                                    (((x) & 0x00010000) >> 16)
#define SYNTH4_CLKXTAL_EDGE_SEL_SET(x)                                    (((x) << 16) & 0x00010000)
#define SYNTH4_VCOCAPPULLUP_MSB                                                                   17
#define SYNTH4_VCOCAPPULLUP_LSB                                                                   17
#define SYNTH4_VCOCAPPULLUP_MASK                                                          0x00020000
#define SYNTH4_VCOCAPPULLUP_GET(x)                                        (((x) & 0x00020000) >> 17)
#define SYNTH4_VCOCAPPULLUP_SET(x)                                        (((x) << 17) & 0x00020000)
#define SYNTH4_VCOCAP_OVR_MSB                                                                     25
#define SYNTH4_VCOCAP_OVR_LSB                                                                     18
#define SYNTH4_VCOCAP_OVR_MASK                                                            0x03fc0000
#define SYNTH4_VCOCAP_OVR_GET(x)                                          (((x) & 0x03fc0000) >> 18)
#define SYNTH4_VCOCAP_OVR_SET(x)                                          (((x) << 18) & 0x03fc0000)
#define SYNTH4_FORCE_VCOCAP_MSB                                                                   26
#define SYNTH4_FORCE_VCOCAP_LSB                                                                   26
#define SYNTH4_FORCE_VCOCAP_MASK                                                          0x04000000
#define SYNTH4_FORCE_VCOCAP_GET(x)                                        (((x) & 0x04000000) >> 26)
#define SYNTH4_FORCE_VCOCAP_SET(x)                                        (((x) << 26) & 0x04000000)
#define SYNTH4_FORCE_PINVC_MSB                                                                    27
#define SYNTH4_FORCE_PINVC_LSB                                                                    27
#define SYNTH4_FORCE_PINVC_MASK                                                           0x08000000
#define SYNTH4_FORCE_PINVC_GET(x)                                         (((x) & 0x08000000) >> 27)
#define SYNTH4_FORCE_PINVC_SET(x)                                         (((x) << 27) & 0x08000000)
#define SYNTH4_SHORTR_UNTIL_LOCKED_MSB                                                            28
#define SYNTH4_SHORTR_UNTIL_LOCKED_LSB                                                            28
#define SYNTH4_SHORTR_UNTIL_LOCKED_MASK                                                   0x10000000
#define SYNTH4_SHORTR_UNTIL_LOCKED_GET(x)                                 (((x) & 0x10000000) >> 28)
#define SYNTH4_SHORTR_UNTIL_LOCKED_SET(x)                                 (((x) << 28) & 0x10000000)
#define SYNTH4_ALWAYS_SHORTR_MSB                                                                  29
#define SYNTH4_ALWAYS_SHORTR_LSB                                                                  29
#define SYNTH4_ALWAYS_SHORTR_MASK                                                         0x20000000
#define SYNTH4_ALWAYS_SHORTR_GET(x)                                       (((x) & 0x20000000) >> 29)
#define SYNTH4_ALWAYS_SHORTR_SET(x)                                       (((x) << 29) & 0x20000000)
#define SYNTH4_DIS_LOSTVC_MSB                                                                     30
#define SYNTH4_DIS_LOSTVC_LSB                                                                     30
#define SYNTH4_DIS_LOSTVC_MASK                                                            0x40000000
#define SYNTH4_DIS_LOSTVC_GET(x)                                          (((x) & 0x40000000) >> 30)
#define SYNTH4_DIS_LOSTVC_SET(x)                                          (((x) << 30) & 0x40000000)
#define SYNTH4_DIS_LIN_CAPSEARCH_MSB                                                              31
#define SYNTH4_DIS_LIN_CAPSEARCH_LSB                                                              31
#define SYNTH4_DIS_LIN_CAPSEARCH_MASK                                                     0x80000000
#define SYNTH4_DIS_LIN_CAPSEARCH_GET(x)                                   (((x) & 0x80000000) >> 31)
#define SYNTH4_DIS_LIN_CAPSEARCH_SET(x)                                   (((x) << 31) & 0x80000000)

/* macros for SYNTH5 */
#define SYNTH5_ADDRESS                                                                    0x00000058
#define SYNTH5_OFFSET                                                                     0x00000058
#define SYNTH5_ICPKCOMP_MSB                                                                        1
#define SYNTH5_ICPKCOMP_LSB                                                                        0
#define SYNTH5_ICPKCOMP_MASK                                                              0x00000003
#define SYNTH5_ICPKCOMP_GET(x)                                             (((x) & 0x00000003) >> 0)
#define SYNTH5_ICPKCOMP_SET(x)                                             (((x) << 0) & 0x00000003)
#define SYNTH5_ICLOBUF5G_MSB                                                                       4
#define SYNTH5_ICLOBUF5G_LSB                                                                       2
#define SYNTH5_ICLOBUF5G_MASK                                                             0x0000001c
#define SYNTH5_ICLOBUF5G_GET(x)                                            (((x) & 0x0000001c) >> 2)
#define SYNTH5_ICLOBUF5G_SET(x)                                            (((x) << 2) & 0x0000001c)
#define SYNTH5_ICLOBUF2G_MSB                                                                       7
#define SYNTH5_ICLOBUF2G_LSB                                                                       5
#define SYNTH5_ICLOBUF2G_MASK                                                             0x000000e0
#define SYNTH5_ICLOBUF2G_GET(x)                                            (((x) & 0x000000e0) >> 5)
#define SYNTH5_ICLOBUF2G_SET(x)                                            (((x) << 5) & 0x000000e0)
#define SYNTH5_ICVCO_MSB                                                                          10
#define SYNTH5_ICVCO_LSB                                                                           8
#define SYNTH5_ICVCO_MASK                                                                 0x00000700
#define SYNTH5_ICVCO_GET(x)                                                (((x) & 0x00000700) >> 8)
#define SYNTH5_ICVCO_SET(x)                                                (((x) << 8) & 0x00000700)
#define SYNTH5_ICVCOREG_MSB                                                                       13
#define SYNTH5_ICVCOREG_LSB                                                                       11
#define SYNTH5_ICVCOREG_MASK                                                              0x00003800
#define SYNTH5_ICVCOREG_GET(x)                                            (((x) & 0x00003800) >> 11)
#define SYNTH5_ICVCOREG_SET(x)                                            (((x) << 11) & 0x00003800)
#define SYNTH5_ICLOMIX_MSB                                                                        16
#define SYNTH5_ICLOMIX_LSB                                                                        14
#define SYNTH5_ICLOMIX_MASK                                                               0x0001c000
#define SYNTH5_ICLOMIX_GET(x)                                             (((x) & 0x0001c000) >> 14)
#define SYNTH5_ICLOMIX_SET(x)                                             (((x) << 14) & 0x0001c000)
#define SYNTH5_ICLODIV_MSB                                                                        19
#define SYNTH5_ICLODIV_LSB                                                                        17
#define SYNTH5_ICLODIV_MASK                                                               0x000e0000
#define SYNTH5_ICLODIV_GET(x)                                             (((x) & 0x000e0000) >> 17)
#define SYNTH5_ICLODIV_SET(x)                                             (((x) << 17) & 0x000e0000)
#define SYNTH5_ICPRESC_MSB                                                                        22
#define SYNTH5_ICPRESC_LSB                                                                        20
#define SYNTH5_ICPRESC_MASK                                                               0x00700000
#define SYNTH5_ICPRESC_GET(x)                                             (((x) & 0x00700000) >> 20)
#define SYNTH5_ICPRESC_SET(x)                                             (((x) << 20) & 0x00700000)
#define SYNTH5_IRLOPKDET_MSB                                                                      25
#define SYNTH5_IRLOPKDET_LSB                                                                      23
#define SYNTH5_IRLOPKDET_MASK                                                             0x03800000
#define SYNTH5_IRLOPKDET_GET(x)                                           (((x) & 0x03800000) >> 23)
#define SYNTH5_IRLOPKDET_SET(x)                                           (((x) << 23) & 0x03800000)
#define SYNTH5_IRVCMON_MSB                                                                        28
#define SYNTH5_IRVCMON_LSB                                                                        26
#define SYNTH5_IRVCMON_MASK                                                               0x1c000000
#define SYNTH5_IRVCMON_GET(x)                                             (((x) & 0x1c000000) >> 26)
#define SYNTH5_IRVCMON_SET(x)                                             (((x) << 26) & 0x1c000000)
#define SYNTH5_IRCP_MSB                                                                           31
#define SYNTH5_IRCP_LSB                                                                           29
#define SYNTH5_IRCP_MASK                                                                  0xe0000000
#define SYNTH5_IRCP_GET(x)                                                (((x) & 0xe0000000) >> 29)
#define SYNTH5_IRCP_SET(x)                                                (((x) << 29) & 0xe0000000)

/* macros for SYNTH6 */
#define SYNTH6_ADDRESS                                                                    0x0000005c
#define SYNTH6_OFFSET                                                                     0x0000005c
#define SYNTH6_LOBUF5GTUNE_MSB                                                                     1
#define SYNTH6_LOBUF5GTUNE_LSB                                                                     0
#define SYNTH6_LOBUF5GTUNE_MASK                                                           0x00000003
#define SYNTH6_LOBUF5GTUNE_GET(x)                                          (((x) & 0x00000003) >> 0)
#define SYNTH6_LOOP_IP_MSB                                                                         8
#define SYNTH6_LOOP_IP_LSB                                                                         2
#define SYNTH6_LOOP_IP_MASK                                                               0x000001fc
#define SYNTH6_LOOP_IP_GET(x)                                              (((x) & 0x000001fc) >> 2)
#define SYNTH6_VC2LOW_MSB                                                                          9
#define SYNTH6_VC2LOW_LSB                                                                          9
#define SYNTH6_VC2LOW_MASK                                                                0x00000200
#define SYNTH6_VC2LOW_GET(x)                                               (((x) & 0x00000200) >> 9)
#define SYNTH6_VC2HIGH_MSB                                                                        10
#define SYNTH6_VC2HIGH_LSB                                                                        10
#define SYNTH6_VC2HIGH_MASK                                                               0x00000400
#define SYNTH6_VC2HIGH_GET(x)                                             (((x) & 0x00000400) >> 10)
#define SYNTH6_RESET_SDM_B_MSB                                                                    11
#define SYNTH6_RESET_SDM_B_LSB                                                                    11
#define SYNTH6_RESET_SDM_B_MASK                                                           0x00000800
#define SYNTH6_RESET_SDM_B_GET(x)                                         (((x) & 0x00000800) >> 11)
#define SYNTH6_RESET_PSCOUNTERS_MSB                                                               12
#define SYNTH6_RESET_PSCOUNTERS_LSB                                                               12
#define SYNTH6_RESET_PSCOUNTERS_MASK                                                      0x00001000
#define SYNTH6_RESET_PSCOUNTERS_GET(x)                                    (((x) & 0x00001000) >> 12)
#define SYNTH6_RESET_PFD_MSB                                                                      13
#define SYNTH6_RESET_PFD_LSB                                                                      13
#define SYNTH6_RESET_PFD_MASK                                                             0x00002000
#define SYNTH6_RESET_PFD_GET(x)                                           (((x) & 0x00002000) >> 13)
#define SYNTH6_RESET_RFD_MSB                                                                      14
#define SYNTH6_RESET_RFD_LSB                                                                      14
#define SYNTH6_RESET_RFD_MASK                                                             0x00004000
#define SYNTH6_RESET_RFD_GET(x)                                           (((x) & 0x00004000) >> 14)
#define SYNTH6_SHORT_R_MSB                                                                        15
#define SYNTH6_SHORT_R_LSB                                                                        15
#define SYNTH6_SHORT_R_MASK                                                               0x00008000
#define SYNTH6_SHORT_R_GET(x)                                             (((x) & 0x00008000) >> 15)
#define SYNTH6_VCO_CAP_ST_MSB                                                                     23
#define SYNTH6_VCO_CAP_ST_LSB                                                                     16
#define SYNTH6_VCO_CAP_ST_MASK                                                            0x00ff0000
#define SYNTH6_VCO_CAP_ST_GET(x)                                          (((x) & 0x00ff0000) >> 16)
#define SYNTH6_PIN_VC_MSB                                                                         24
#define SYNTH6_PIN_VC_LSB                                                                         24
#define SYNTH6_PIN_VC_MASK                                                                0x01000000
#define SYNTH6_PIN_VC_GET(x)                                              (((x) & 0x01000000) >> 24)
#define SYNTH6_SYNTH_LOCK_VC_OK_MSB                                                               25
#define SYNTH6_SYNTH_LOCK_VC_OK_LSB                                                               25
#define SYNTH6_SYNTH_LOCK_VC_OK_MASK                                                      0x02000000
#define SYNTH6_SYNTH_LOCK_VC_OK_GET(x)                                    (((x) & 0x02000000) >> 25)
#define SYNTH6_CAP_SEARCH_MSB                                                                     26
#define SYNTH6_CAP_SEARCH_LSB                                                                     26
#define SYNTH6_CAP_SEARCH_MASK                                                            0x04000000
#define SYNTH6_CAP_SEARCH_GET(x)                                          (((x) & 0x04000000) >> 26)
#define SYNTH6_SYNTH_SM_STATE_MSB                                                                 30
#define SYNTH6_SYNTH_SM_STATE_LSB                                                                 27
#define SYNTH6_SYNTH_SM_STATE_MASK                                                        0x78000000
#define SYNTH6_SYNTH_SM_STATE_GET(x)                                      (((x) & 0x78000000) >> 27)
#define SYNTH6_SYNTH_ON_MSB                                                                       31
#define SYNTH6_SYNTH_ON_LSB                                                                       31
#define SYNTH6_SYNTH_ON_MASK                                                              0x80000000
#define SYNTH6_SYNTH_ON_GET(x)                                            (((x) & 0x80000000) >> 31)

/* macros for SYNTH7 */
#define SYNTH7_ADDRESS                                                                    0x00000060
#define SYNTH7_OFFSET                                                                     0x00000060
#define SYNTH7_OVRCHANDECODER_MSB                                                                  0
#define SYNTH7_OVRCHANDECODER_LSB                                                                  0
#define SYNTH7_OVRCHANDECODER_MASK                                                        0x00000001
#define SYNTH7_OVRCHANDECODER_GET(x)                                       (((x) & 0x00000001) >> 0)
#define SYNTH7_OVRCHANDECODER_SET(x)                                       (((x) << 0) & 0x00000001)
#define SYNTH7_FORCE_FRACLSB_MSB                                                                   1
#define SYNTH7_FORCE_FRACLSB_LSB                                                                   1
#define SYNTH7_FORCE_FRACLSB_MASK                                                         0x00000002
#define SYNTH7_FORCE_FRACLSB_GET(x)                                        (((x) & 0x00000002) >> 1)
#define SYNTH7_FORCE_FRACLSB_SET(x)                                        (((x) << 1) & 0x00000002)
#define SYNTH7_CHANFRAC_MSB                                                                       18
#define SYNTH7_CHANFRAC_LSB                                                                        2
#define SYNTH7_CHANFRAC_MASK                                                              0x0007fffc
#define SYNTH7_CHANFRAC_GET(x)                                             (((x) & 0x0007fffc) >> 2)
#define SYNTH7_CHANFRAC_SET(x)                                             (((x) << 2) & 0x0007fffc)
#define SYNTH7_CHANSEL_MSB                                                                        27
#define SYNTH7_CHANSEL_LSB                                                                        19
#define SYNTH7_CHANSEL_MASK                                                               0x0ff80000
#define SYNTH7_CHANSEL_GET(x)                                             (((x) & 0x0ff80000) >> 19)
#define SYNTH7_CHANSEL_SET(x)                                             (((x) << 19) & 0x0ff80000)
#define SYNTH7_AMODEREFSEL_MSB                                                                    29
#define SYNTH7_AMODEREFSEL_LSB                                                                    28
#define SYNTH7_AMODEREFSEL_MASK                                                           0x30000000
#define SYNTH7_AMODEREFSEL_GET(x)                                         (((x) & 0x30000000) >> 28)
#define SYNTH7_AMODEREFSEL_SET(x)                                         (((x) << 28) & 0x30000000)
#define SYNTH7_FRACMODE_MSB                                                                       30
#define SYNTH7_FRACMODE_LSB                                                                       30
#define SYNTH7_FRACMODE_MASK                                                              0x40000000
#define SYNTH7_FRACMODE_GET(x)                                            (((x) & 0x40000000) >> 30)
#define SYNTH7_FRACMODE_SET(x)                                            (((x) << 30) & 0x40000000)
#define SYNTH7_LOADSYNTHCHANNEL_MSB                                                               31
#define SYNTH7_LOADSYNTHCHANNEL_LSB                                                               31
#define SYNTH7_LOADSYNTHCHANNEL_MASK                                                      0x80000000
#define SYNTH7_LOADSYNTHCHANNEL_GET(x)                                    (((x) & 0x80000000) >> 31)
#define SYNTH7_LOADSYNTHCHANNEL_SET(x)                                    (((x) << 31) & 0x80000000)

/* macros for SYNTH8 */
#define SYNTH8_ADDRESS                                                                    0x00000064
#define SYNTH8_OFFSET                                                                     0x00000064
#define SYNTH8_CPSTEERING_EN_FRACN_MSB                                                             0
#define SYNTH8_CPSTEERING_EN_FRACN_LSB                                                             0
#define SYNTH8_CPSTEERING_EN_FRACN_MASK                                                   0x00000001
#define SYNTH8_CPSTEERING_EN_FRACN_GET(x)                                  (((x) & 0x00000001) >> 0)
#define SYNTH8_CPSTEERING_EN_FRACN_SET(x)                                  (((x) << 0) & 0x00000001)
#define SYNTH8_LOOP_ICPB_MSB                                                                       7
#define SYNTH8_LOOP_ICPB_LSB                                                                       1
#define SYNTH8_LOOP_ICPB_MASK                                                             0x000000fe
#define SYNTH8_LOOP_ICPB_GET(x)                                            (((x) & 0x000000fe) >> 1)
#define SYNTH8_LOOP_ICPB_SET(x)                                            (((x) << 1) & 0x000000fe)
#define SYNTH8_LOOP_CSB_MSB                                                                       11
#define SYNTH8_LOOP_CSB_LSB                                                                        8
#define SYNTH8_LOOP_CSB_MASK                                                              0x00000f00
#define SYNTH8_LOOP_CSB_GET(x)                                             (((x) & 0x00000f00) >> 8)
#define SYNTH8_LOOP_CSB_SET(x)                                             (((x) << 8) & 0x00000f00)
#define SYNTH8_LOOP_RSB_MSB                                                                       16
#define SYNTH8_LOOP_RSB_LSB                                                                       12
#define SYNTH8_LOOP_RSB_MASK                                                              0x0001f000
#define SYNTH8_LOOP_RSB_GET(x)                                            (((x) & 0x0001f000) >> 12)
#define SYNTH8_LOOP_RSB_SET(x)                                            (((x) << 12) & 0x0001f000)
#define SYNTH8_LOOP_CPB_MSB                                                                       21
#define SYNTH8_LOOP_CPB_LSB                                                                       17
#define SYNTH8_LOOP_CPB_MASK                                                              0x003e0000
#define SYNTH8_LOOP_CPB_GET(x)                                            (((x) & 0x003e0000) >> 17)
#define SYNTH8_LOOP_CPB_SET(x)                                            (((x) << 17) & 0x003e0000)
#define SYNTH8_LOOP_3RD_ORDER_RB_MSB                                                              26
#define SYNTH8_LOOP_3RD_ORDER_RB_LSB                                                              22
#define SYNTH8_LOOP_3RD_ORDER_RB_MASK                                                     0x07c00000
#define SYNTH8_LOOP_3RD_ORDER_RB_GET(x)                                   (((x) & 0x07c00000) >> 22)
#define SYNTH8_LOOP_3RD_ORDER_RB_SET(x)                                   (((x) << 22) & 0x07c00000)
#define SYNTH8_REFDIVB_MSB                                                                        31
#define SYNTH8_REFDIVB_LSB                                                                        27
#define SYNTH8_REFDIVB_MASK                                                               0xf8000000
#define SYNTH8_REFDIVB_GET(x)                                             (((x) & 0xf8000000) >> 27)
#define SYNTH8_REFDIVB_SET(x)                                             (((x) << 27) & 0xf8000000)

/* macros for SYNTH9 */
#define SYNTH9_ADDRESS                                                                    0x00000068
#define SYNTH9_OFFSET                                                                     0x00000068
#define SYNTH9_PFDDELAY_INTN_MSB                                                                   0
#define SYNTH9_PFDDELAY_INTN_LSB                                                                   0
#define SYNTH9_PFDDELAY_INTN_MASK                                                         0x00000001
#define SYNTH9_PFDDELAY_INTN_GET(x)                                        (((x) & 0x00000001) >> 0)
#define SYNTH9_PFDDELAY_INTN_SET(x)                                        (((x) << 0) & 0x00000001)
#define SYNTH9_SLOPE_ICPA0_MSB                                                                     3
#define SYNTH9_SLOPE_ICPA0_LSB                                                                     1
#define SYNTH9_SLOPE_ICPA0_MASK                                                           0x0000000e
#define SYNTH9_SLOPE_ICPA0_GET(x)                                          (((x) & 0x0000000e) >> 1)
#define SYNTH9_SLOPE_ICPA0_SET(x)                                          (((x) << 1) & 0x0000000e)
#define SYNTH9_LOOP_ICPA0_MSB                                                                      7
#define SYNTH9_LOOP_ICPA0_LSB                                                                      4
#define SYNTH9_LOOP_ICPA0_MASK                                                            0x000000f0
#define SYNTH9_LOOP_ICPA0_GET(x)                                           (((x) & 0x000000f0) >> 4)
#define SYNTH9_LOOP_ICPA0_SET(x)                                           (((x) << 4) & 0x000000f0)
#define SYNTH9_LOOP_CSA0_MSB                                                                      11
#define SYNTH9_LOOP_CSA0_LSB                                                                       8
#define SYNTH9_LOOP_CSA0_MASK                                                             0x00000f00
#define SYNTH9_LOOP_CSA0_GET(x)                                            (((x) & 0x00000f00) >> 8)
#define SYNTH9_LOOP_CSA0_SET(x)                                            (((x) << 8) & 0x00000f00)
#define SYNTH9_LOOP_RSA0_MSB                                                                      16
#define SYNTH9_LOOP_RSA0_LSB                                                                      12
#define SYNTH9_LOOP_RSA0_MASK                                                             0x0001f000
#define SYNTH9_LOOP_RSA0_GET(x)                                           (((x) & 0x0001f000) >> 12)
#define SYNTH9_LOOP_RSA0_SET(x)                                           (((x) << 12) & 0x0001f000)
#define SYNTH9_LOOP_CPA0_MSB                                                                      21
#define SYNTH9_LOOP_CPA0_LSB                                                                      17
#define SYNTH9_LOOP_CPA0_MASK                                                             0x003e0000
#define SYNTH9_LOOP_CPA0_GET(x)                                           (((x) & 0x003e0000) >> 17)
#define SYNTH9_LOOP_CPA0_SET(x)                                           (((x) << 17) & 0x003e0000)
#define SYNTH9_LOOP_3RD_ORDER_RA_MSB                                                              26
#define SYNTH9_LOOP_3RD_ORDER_RA_LSB                                                              22
#define SYNTH9_LOOP_3RD_ORDER_RA_MASK                                                     0x07c00000
#define SYNTH9_LOOP_3RD_ORDER_RA_GET(x)                                   (((x) & 0x07c00000) >> 22)
#define SYNTH9_LOOP_3RD_ORDER_RA_SET(x)                                   (((x) << 22) & 0x07c00000)
#define SYNTH9_REFDIVA_MSB                                                                        31
#define SYNTH9_REFDIVA_LSB                                                                        27
#define SYNTH9_REFDIVA_MASK                                                               0xf8000000
#define SYNTH9_REFDIVA_GET(x)                                             (((x) & 0xf8000000) >> 27)
#define SYNTH9_REFDIVA_SET(x)                                             (((x) << 27) & 0xf8000000)

/* macros for SYNTH10 */
#define SYNTH10_ADDRESS                                                                   0x0000006c
#define SYNTH10_OFFSET                                                                    0x0000006c
#define SYNTH10_SPARE_MSB                                                                         10
#define SYNTH10_SPARE_LSB                                                                          0
#define SYNTH10_SPARE_MASK                                                                0x000007ff
#define SYNTH10_SPARE_GET(x)                                               (((x) & 0x000007ff) >> 0)
#define SYNTH10_SPARE_SET(x)                                               (((x) << 0) & 0x000007ff)
#define SYNTH10_SLOPE_ICPA1_MSB                                                                   13
#define SYNTH10_SLOPE_ICPA1_LSB                                                                   11
#define SYNTH10_SLOPE_ICPA1_MASK                                                          0x00003800
#define SYNTH10_SLOPE_ICPA1_GET(x)                                        (((x) & 0x00003800) >> 11)
#define SYNTH10_SLOPE_ICPA1_SET(x)                                        (((x) << 11) & 0x00003800)
#define SYNTH10_LOOP_ICPA1_MSB                                                                    17
#define SYNTH10_LOOP_ICPA1_LSB                                                                    14
#define SYNTH10_LOOP_ICPA1_MASK                                                           0x0003c000
#define SYNTH10_LOOP_ICPA1_GET(x)                                         (((x) & 0x0003c000) >> 14)
#define SYNTH10_LOOP_ICPA1_SET(x)                                         (((x) << 14) & 0x0003c000)
#define SYNTH10_LOOP_CSA1_MSB                                                                     21
#define SYNTH10_LOOP_CSA1_LSB                                                                     18
#define SYNTH10_LOOP_CSA1_MASK                                                            0x003c0000
#define SYNTH10_LOOP_CSA1_GET(x)                                          (((x) & 0x003c0000) >> 18)
#define SYNTH10_LOOP_CSA1_SET(x)                                          (((x) << 18) & 0x003c0000)
#define SYNTH10_LOOP_RSA1_MSB                                                                     26
#define SYNTH10_LOOP_RSA1_LSB                                                                     22
#define SYNTH10_LOOP_RSA1_MASK                                                            0x07c00000
#define SYNTH10_LOOP_RSA1_GET(x)                                          (((x) & 0x07c00000) >> 22)
#define SYNTH10_LOOP_RSA1_SET(x)                                          (((x) << 22) & 0x07c00000)
#define SYNTH10_LOOP_CPA1_MSB                                                                     31
#define SYNTH10_LOOP_CPA1_LSB                                                                     27
#define SYNTH10_LOOP_CPA1_MASK                                                            0xf8000000
#define SYNTH10_LOOP_CPA1_GET(x)                                          (((x) & 0xf8000000) >> 27)
#define SYNTH10_LOOP_CPA1_SET(x)                                          (((x) << 27) & 0xf8000000)

/* macros for SYNTH11 */
#define SYNTH11_ADDRESS                                                                   0x00000070
#define SYNTH11_OFFSET                                                                    0x00000070
#define SYNTH11_SPARE_MSB                                                                          4
#define SYNTH11_SPARE_LSB                                                                          0
#define SYNTH11_SPARE_MASK                                                                0x0000001f
#define SYNTH11_SPARE_GET(x)                                               (((x) & 0x0000001f) >> 0)
#define SYNTH11_SPARE_SET(x)                                               (((x) << 0) & 0x0000001f)
#define SYNTH11_FORCE_LOBUF5G_ON_MSB                                                               5
#define SYNTH11_FORCE_LOBUF5G_ON_LSB                                                               5
#define SYNTH11_FORCE_LOBUF5G_ON_MASK                                                     0x00000020
#define SYNTH11_FORCE_LOBUF5G_ON_GET(x)                                    (((x) & 0x00000020) >> 5)
#define SYNTH11_FORCE_LOBUF5G_ON_SET(x)                                    (((x) << 5) & 0x00000020)
#define SYNTH11_LOREFSEL_MSB                                                                       7
#define SYNTH11_LOREFSEL_LSB                                                                       6
#define SYNTH11_LOREFSEL_MASK                                                             0x000000c0
#define SYNTH11_LOREFSEL_GET(x)                                            (((x) & 0x000000c0) >> 6)
#define SYNTH11_LOREFSEL_SET(x)                                            (((x) << 6) & 0x000000c0)
#define SYNTH11_LO2GSEL_MSB                                                                        9
#define SYNTH11_LO2GSEL_LSB                                                                        8
#define SYNTH11_LO2GSEL_MASK                                                              0x00000300
#define SYNTH11_LO2GSEL_GET(x)                                             (((x) & 0x00000300) >> 8)
#define SYNTH11_LO2GSEL_SET(x)                                             (((x) << 8) & 0x00000300)
#define SYNTH11_CPSTEERING_MODE_MSB                                                               10
#define SYNTH11_CPSTEERING_MODE_LSB                                                               10
#define SYNTH11_CPSTEERING_MODE_MASK                                                      0x00000400
#define SYNTH11_CPSTEERING_MODE_GET(x)                                    (((x) & 0x00000400) >> 10)
#define SYNTH11_CPSTEERING_MODE_SET(x)                                    (((x) << 10) & 0x00000400)
#define SYNTH11_SLOPE_ICPA2_MSB                                                                   13
#define SYNTH11_SLOPE_ICPA2_LSB                                                                   11
#define SYNTH11_SLOPE_ICPA2_MASK                                                          0x00003800
#define SYNTH11_SLOPE_ICPA2_GET(x)                                        (((x) & 0x00003800) >> 11)
#define SYNTH11_SLOPE_ICPA2_SET(x)                                        (((x) << 11) & 0x00003800)
#define SYNTH11_LOOP_ICPA2_MSB                                                                    17
#define SYNTH11_LOOP_ICPA2_LSB                                                                    14
#define SYNTH11_LOOP_ICPA2_MASK                                                           0x0003c000
#define SYNTH11_LOOP_ICPA2_GET(x)                                         (((x) & 0x0003c000) >> 14)
#define SYNTH11_LOOP_ICPA2_SET(x)                                         (((x) << 14) & 0x0003c000)
#define SYNTH11_LOOP_CSA2_MSB                                                                     21
#define SYNTH11_LOOP_CSA2_LSB                                                                     18
#define SYNTH11_LOOP_CSA2_MASK                                                            0x003c0000
#define SYNTH11_LOOP_CSA2_GET(x)                                          (((x) & 0x003c0000) >> 18)
#define SYNTH11_LOOP_CSA2_SET(x)                                          (((x) << 18) & 0x003c0000)
#define SYNTH11_LOOP_RSA2_MSB                                                                     26
#define SYNTH11_LOOP_RSA2_LSB                                                                     22
#define SYNTH11_LOOP_RSA2_MASK                                                            0x07c00000
#define SYNTH11_LOOP_RSA2_GET(x)                                          (((x) & 0x07c00000) >> 22)
#define SYNTH11_LOOP_RSA2_SET(x)                                          (((x) << 22) & 0x07c00000)
#define SYNTH11_LOOP_CPA2_MSB                                                                     31
#define SYNTH11_LOOP_CPA2_LSB                                                                     27
#define SYNTH11_LOOP_CPA2_MASK                                                            0xf8000000
#define SYNTH11_LOOP_CPA2_GET(x)                                          (((x) & 0xf8000000) >> 27)
#define SYNTH11_LOOP_CPA2_SET(x)                                          (((x) << 27) & 0xf8000000)

/* macros for BIAS1 */
#define BIAS1_ADDRESS                                                                     0x00000074
#define BIAS1_OFFSET                                                                      0x00000074
#define BIAS1_PWD_IRPCIE50_MSB                                                                     0
#define BIAS1_PWD_IRPCIE50_LSB                                                                     0
#define BIAS1_PWD_IRPCIE50_MASK                                                           0x00000001
#define BIAS1_PWD_IRPCIE50_GET(x)                                          (((x) & 0x00000001) >> 0)
#define BIAS1_PWD_IRPCIE50_SET(x)                                          (((x) << 0) & 0x00000001)
#define BIAS1_PWD_ICPCIE50_MSB                                                                     1
#define BIAS1_PWD_ICPCIE50_LSB                                                                     1
#define BIAS1_PWD_ICPCIE50_MASK                                                           0x00000002
#define BIAS1_PWD_ICPCIE50_GET(x)                                          (((x) & 0x00000002) >> 1)
#define BIAS1_PWD_ICPCIE50_SET(x)                                          (((x) << 1) & 0x00000002)
#define BIAS1_PWD_IRPLL25_MSB                                                                      2
#define BIAS1_PWD_IRPLL25_LSB                                                                      2
#define BIAS1_PWD_IRPLL25_MASK                                                            0x00000004
#define BIAS1_PWD_IRPLL25_GET(x)                                           (((x) & 0x00000004) >> 2)
#define BIAS1_PWD_IRPLL25_SET(x)                                           (((x) << 2) & 0x00000004)
#define BIAS1_PWD_ICPLL25_MSB                                                                      3
#define BIAS1_PWD_ICPLL25_LSB                                                                      3
#define BIAS1_PWD_ICPLL25_MASK                                                            0x00000008
#define BIAS1_PWD_ICPLL25_GET(x)                                           (((x) & 0x00000008) >> 3)
#define BIAS1_PWD_ICPLL25_SET(x)                                           (((x) << 3) & 0x00000008)
#define BIAS1_PWD_IRRXLDO25_MSB                                                                    6
#define BIAS1_PWD_IRRXLDO25_LSB                                                                    4
#define BIAS1_PWD_IRRXLDO25_MASK                                                          0x00000070
#define BIAS1_PWD_IRRXLDO25_GET(x)                                         (((x) & 0x00000070) >> 4)
#define BIAS1_PWD_IRRXLDO25_SET(x)                                         (((x) << 4) & 0x00000070)
#define BIAS1_PWD_ICRXLDO25_MSB                                                                    9
#define BIAS1_PWD_ICRXLDO25_LSB                                                                    7
#define BIAS1_PWD_ICRXLDO25_MASK                                                          0x00000380
#define BIAS1_PWD_ICRXLDO25_GET(x)                                         (((x) & 0x00000380) >> 7)
#define BIAS1_PWD_ICRXLDO25_SET(x)                                         (((x) << 7) & 0x00000380)
#define BIAS1_PWD_IRXPALDO25_MSB                                                                  12
#define BIAS1_PWD_IRXPALDO25_LSB                                                                  10
#define BIAS1_PWD_IRXPALDO25_MASK                                                         0x00001c00
#define BIAS1_PWD_IRXPALDO25_GET(x)                                       (((x) & 0x00001c00) >> 10)
#define BIAS1_PWD_IRXPALDO25_SET(x)                                       (((x) << 10) & 0x00001c00)
#define BIAS1_PWD_ICXPALDO25_MSB                                                                  15
#define BIAS1_PWD_ICXPALDO25_LSB                                                                  13
#define BIAS1_PWD_ICXPALDO25_MASK                                                         0x0000e000
#define BIAS1_PWD_ICXPALDO25_GET(x)                                       (((x) & 0x0000e000) >> 13)
#define BIAS1_PWD_ICXPALDO25_SET(x)                                       (((x) << 13) & 0x0000e000)
#define BIAS1_PWD_IRXTAL25_MSB                                                                    18
#define BIAS1_PWD_IRXTAL25_LSB                                                                    16
#define BIAS1_PWD_IRXTAL25_MASK                                                           0x00070000
#define BIAS1_PWD_IRXTAL25_GET(x)                                         (((x) & 0x00070000) >> 16)
#define BIAS1_PWD_IRXTAL25_SET(x)                                         (((x) << 16) & 0x00070000)
#define BIAS1_PWD_ICXTAL25_MSB                                                                    21
#define BIAS1_PWD_ICXTAL25_LSB                                                                    19
#define BIAS1_PWD_ICXTAL25_MASK                                                           0x00380000
#define BIAS1_PWD_ICXTAL25_GET(x)                                         (((x) & 0x00380000) >> 19)
#define BIAS1_PWD_ICXTAL25_SET(x)                                         (((x) << 19) & 0x00380000)
#define BIAS1_BIAS1_SPARE_MSB                                                                     24
#define BIAS1_BIAS1_SPARE_LSB                                                                     22
#define BIAS1_BIAS1_SPARE_MASK                                                            0x01c00000
#define BIAS1_BIAS1_SPARE_GET(x)                                          (((x) & 0x01c00000) >> 22)
#define BIAS1_BIAS1_SPARE_SET(x)                                          (((x) << 22) & 0x01c00000)
#define BIAS1_SEL_BIAS_MSB                                                                        30
#define BIAS1_SEL_BIAS_LSB                                                                        25
#define BIAS1_SEL_BIAS_MASK                                                               0x7e000000
#define BIAS1_SEL_BIAS_GET(x)                                             (((x) & 0x7e000000) >> 25)
#define BIAS1_SEL_BIAS_SET(x)                                             (((x) << 25) & 0x7e000000)
#define BIAS1_PADON_MSB                                                                           31
#define BIAS1_PADON_LSB                                                                           31
#define BIAS1_PADON_MASK                                                                  0x80000000
#define BIAS1_PADON_GET(x)                                                (((x) & 0x80000000) >> 31)
#define BIAS1_PADON_SET(x)                                                (((x) << 31) & 0x80000000)

/* macros for BIAS2 */
#define BIAS2_ADDRESS                                                                     0x00000078
#define BIAS2_OFFSET                                                                      0x00000078
#define BIAS2_PWD_ICDAC50_MSB                                                                      2
#define BIAS2_PWD_ICDAC50_LSB                                                                      0
#define BIAS2_PWD_ICDAC50_MASK                                                            0x00000007
#define BIAS2_PWD_ICDAC50_GET(x)                                           (((x) & 0x00000007) >> 0)
#define BIAS2_PWD_ICDAC50_SET(x)                                           (((x) << 0) & 0x00000007)
#define BIAS2_PWD_IRADCREFMSTRQ12P5_MSB                                                            3
#define BIAS2_PWD_IRADCREFMSTRQ12P5_LSB                                                            3
#define BIAS2_PWD_IRADCREFMSTRQ12P5_MASK                                                  0x00000008
#define BIAS2_PWD_IRADCREFMSTRQ12P5_GET(x)                                 (((x) & 0x00000008) >> 3)
#define BIAS2_PWD_IRADCREFMSTRQ12P5_SET(x)                                 (((x) << 3) & 0x00000008)
#define BIAS2_PWD_IRADCREFMSTRI12P5_MSB                                                            4
#define BIAS2_PWD_IRADCREFMSTRI12P5_LSB                                                            4
#define BIAS2_PWD_IRADCREFMSTRI12P5_MASK                                                  0x00000010
#define BIAS2_PWD_IRADCREFMSTRI12P5_GET(x)                                 (((x) & 0x00000010) >> 4)
#define BIAS2_PWD_IRADCREFMSTRI12P5_SET(x)                                 (((x) << 4) & 0x00000010)
#define BIAS2_PWD_ICADCREFOPAMPQ25_MSB                                                             7
#define BIAS2_PWD_ICADCREFOPAMPQ25_LSB                                                             5
#define BIAS2_PWD_ICADCREFOPAMPQ25_MASK                                                   0x000000e0
#define BIAS2_PWD_ICADCREFOPAMPQ25_GET(x)                                  (((x) & 0x000000e0) >> 5)
#define BIAS2_PWD_ICADCREFOPAMPQ25_SET(x)                                  (((x) << 5) & 0x000000e0)
#define BIAS2_PWD_ICADCREFOPAMPI25_MSB                                                            10
#define BIAS2_PWD_ICADCREFOPAMPI25_LSB                                                             8
#define BIAS2_PWD_ICADCREFOPAMPI25_MASK                                                   0x00000700
#define BIAS2_PWD_ICADCREFOPAMPI25_GET(x)                                  (((x) & 0x00000700) >> 8)
#define BIAS2_PWD_ICADCREFOPAMPI25_SET(x)                                  (((x) << 8) & 0x00000700)
#define BIAS2_PWD_ICADCREFBUFQ12P5_MSB                                                            13
#define BIAS2_PWD_ICADCREFBUFQ12P5_LSB                                                            11
#define BIAS2_PWD_ICADCREFBUFQ12P5_MASK                                                   0x00003800
#define BIAS2_PWD_ICADCREFBUFQ12P5_GET(x)                                 (((x) & 0x00003800) >> 11)
#define BIAS2_PWD_ICADCREFBUFQ12P5_SET(x)                                 (((x) << 11) & 0x00003800)
#define BIAS2_PWD_ICADCREFBUFI12P5_MSB                                                            16
#define BIAS2_PWD_ICADCREFBUFI12P5_LSB                                                            14
#define BIAS2_PWD_ICADCREFBUFI12P5_MASK                                                   0x0001c000
#define BIAS2_PWD_ICADCREFBUFI12P5_GET(x)                                 (((x) & 0x0001c000) >> 14)
#define BIAS2_PWD_ICADCREFBUFI12P5_SET(x)                                 (((x) << 14) & 0x0001c000)
#define BIAS2_PWD_ICADCCOMPQ25_MSB                                                                19
#define BIAS2_PWD_ICADCCOMPQ25_LSB                                                                17
#define BIAS2_PWD_ICADCCOMPQ25_MASK                                                       0x000e0000
#define BIAS2_PWD_ICADCCOMPQ25_GET(x)                                     (((x) & 0x000e0000) >> 17)
#define BIAS2_PWD_ICADCCOMPQ25_SET(x)                                     (((x) << 17) & 0x000e0000)
#define BIAS2_PWD_ICADCCOMPI25_MSB                                                                22
#define BIAS2_PWD_ICADCCOMPI25_LSB                                                                20
#define BIAS2_PWD_ICADCCOMPI25_MASK                                                       0x00700000
#define BIAS2_PWD_ICADCCOMPI25_GET(x)                                     (((x) & 0x00700000) >> 20)
#define BIAS2_PWD_ICADCCOMPI25_SET(x)                                     (((x) << 20) & 0x00700000)
#define BIAS2_PWD_ICDACINTFACE25_MSB                                                              23
#define BIAS2_PWD_ICDACINTFACE25_LSB                                                              23
#define BIAS2_PWD_ICDACINTFACE25_MASK                                                     0x00800000
#define BIAS2_PWD_ICDACINTFACE25_GET(x)                                   (((x) & 0x00800000) >> 23)
#define BIAS2_PWD_ICDACINTFACE25_SET(x)                                   (((x) << 23) & 0x00800000)
#define BIAS2_PWD_IRBB50_MSB                                                                      24
#define BIAS2_PWD_IRBB50_LSB                                                                      24
#define BIAS2_PWD_IRBB50_MASK                                                             0x01000000
#define BIAS2_PWD_IRBB50_GET(x)                                           (((x) & 0x01000000) >> 24)
#define BIAS2_PWD_IRBB50_SET(x)                                           (((x) << 24) & 0x01000000)
#define BIAS2_PWD_ICBB50_MSB                                                                      25
#define BIAS2_PWD_ICBB50_LSB                                                                      25
#define BIAS2_PWD_ICBB50_MASK                                                             0x02000000
#define BIAS2_PWD_ICBB50_GET(x)                                           (((x) & 0x02000000) >> 25)
#define BIAS2_PWD_ICBB50_SET(x)                                           (((x) << 25) & 0x02000000)
#define BIAS2_PWD_IRRF2G50_MSB                                                                    26
#define BIAS2_PWD_IRRF2G50_LSB                                                                    26
#define BIAS2_PWD_IRRF2G50_MASK                                                           0x04000000
#define BIAS2_PWD_IRRF2G50_GET(x)                                         (((x) & 0x04000000) >> 26)
#define BIAS2_PWD_IRRF2G50_SET(x)                                         (((x) << 26) & 0x04000000)
#define BIAS2_PWD_IRRF5G50_MSB                                                                    27
#define BIAS2_PWD_IRRF5G50_LSB                                                                    27
#define BIAS2_PWD_IRRF5G50_MASK                                                           0x08000000
#define BIAS2_PWD_IRRF5G50_GET(x)                                         (((x) & 0x08000000) >> 27)
#define BIAS2_PWD_IRRF5G50_SET(x)                                         (((x) << 27) & 0x08000000)
#define BIAS2_PWD_ICRF2G50_MSB                                                                    28
#define BIAS2_PWD_ICRF2G50_LSB                                                                    28
#define BIAS2_PWD_ICRF2G50_MASK                                                           0x10000000
#define BIAS2_PWD_ICRF2G50_GET(x)                                         (((x) & 0x10000000) >> 28)
#define BIAS2_PWD_ICRF2G50_SET(x)                                         (((x) << 28) & 0x10000000)
#define BIAS2_PWD_ICRF5G50_MSB                                                                    29
#define BIAS2_PWD_ICRF5G50_LSB                                                                    29
#define BIAS2_PWD_ICRF5G50_MASK                                                           0x20000000
#define BIAS2_PWD_ICRF5G50_GET(x)                                         (((x) & 0x20000000) >> 29)
#define BIAS2_PWD_ICRF5G50_SET(x)                                         (((x) << 29) & 0x20000000)
#define BIAS2_PWD_IRSYNTH50_MSB                                                                   30
#define BIAS2_PWD_IRSYNTH50_LSB                                                                   30
#define BIAS2_PWD_IRSYNTH50_MASK                                                          0x40000000
#define BIAS2_PWD_IRSYNTH50_GET(x)                                        (((x) & 0x40000000) >> 30)
#define BIAS2_PWD_IRSYNTH50_SET(x)                                        (((x) << 30) & 0x40000000)
#define BIAS2_PWD_ICSYNTH50_MSB                                                                   31
#define BIAS2_PWD_ICSYNTH50_LSB                                                                   31
#define BIAS2_PWD_ICSYNTH50_MASK                                                          0x80000000
#define BIAS2_PWD_ICSYNTH50_GET(x)                                        (((x) & 0x80000000) >> 31)
#define BIAS2_PWD_ICSYNTH50_SET(x)                                        (((x) << 31) & 0x80000000)

/* macros for BIAS3 */
#define BIAS3_ADDRESS                                                                     0x0000007c
#define BIAS3_OFFSET                                                                      0x0000007c
#define BIAS3_BIAS3_SPARE_MSB                                                                      0
#define BIAS3_BIAS3_SPARE_LSB                                                                      0
#define BIAS3_BIAS3_SPARE_MASK                                                            0x00000001
#define BIAS3_BIAS3_SPARE_GET(x)                                           (((x) & 0x00000001) >> 0)
#define BIAS3_BIAS3_SPARE_SET(x)                                           (((x) << 0) & 0x00000001)
#define BIAS3_PWD_ICLOLDO25_MSB                                                                    3
#define BIAS3_PWD_ICLOLDO25_LSB                                                                    1
#define BIAS3_PWD_ICLOLDO25_MASK                                                          0x0000000e
#define BIAS3_PWD_ICLOLDO25_GET(x)                                         (((x) & 0x0000000e) >> 1)
#define BIAS3_PWD_ICLOLDO25_SET(x)                                         (((x) << 1) & 0x0000000e)
#define BIAS3_PWD_IR25SPARE4_MSB                                                                   6
#define BIAS3_PWD_IR25SPARE4_LSB                                                                   4
#define BIAS3_PWD_IR25SPARE4_MASK                                                         0x00000070
#define BIAS3_PWD_IR25SPARE4_GET(x)                                        (((x) & 0x00000070) >> 4)
#define BIAS3_PWD_IR25SPARE4_SET(x)                                        (((x) << 4) & 0x00000070)
#define BIAS3_PWD_IR25SPARE3_MSB                                                                   9
#define BIAS3_PWD_IR25SPARE3_LSB                                                                   7
#define BIAS3_PWD_IR25SPARE3_MASK                                                         0x00000380
#define BIAS3_PWD_IR25SPARE3_GET(x)                                        (((x) & 0x00000380) >> 7)
#define BIAS3_PWD_IR25SPARE3_SET(x)                                        (((x) << 7) & 0x00000380)
#define BIAS3_PWD_IR25SPARE2_MSB                                                                  12
#define BIAS3_PWD_IR25SPARE2_LSB                                                                  10
#define BIAS3_PWD_IR25SPARE2_MASK                                                         0x00001c00
#define BIAS3_PWD_IR25SPARE2_GET(x)                                       (((x) & 0x00001c00) >> 10)
#define BIAS3_PWD_IR25SPARE2_SET(x)                                       (((x) << 10) & 0x00001c00)
#define BIAS3_PWD_IR25SPARE1_MSB                                                                  15
#define BIAS3_PWD_IR25SPARE1_LSB                                                                  13
#define BIAS3_PWD_IR25SPARE1_MASK                                                         0x0000e000
#define BIAS3_PWD_IR25SPARE1_GET(x)                                       (((x) & 0x0000e000) >> 13)
#define BIAS3_PWD_IR25SPARE1_SET(x)                                       (((x) << 13) & 0x0000e000)
#define BIAS3_PWD_IC25SPARE4_MSB                                                                  18
#define BIAS3_PWD_IC25SPARE4_LSB                                                                  16
#define BIAS3_PWD_IC25SPARE4_MASK                                                         0x00070000
#define BIAS3_PWD_IC25SPARE4_GET(x)                                       (((x) & 0x00070000) >> 16)
#define BIAS3_PWD_IC25SPARE4_SET(x)                                       (((x) << 16) & 0x00070000)
#define BIAS3_PWD_IC25SPARE3_MSB                                                                  21
#define BIAS3_PWD_IC25SPARE3_LSB                                                                  19
#define BIAS3_PWD_IC25SPARE3_MASK                                                         0x00380000
#define BIAS3_PWD_IC25SPARE3_GET(x)                                       (((x) & 0x00380000) >> 19)
#define BIAS3_PWD_IC25SPARE3_SET(x)                                       (((x) << 19) & 0x00380000)
#define BIAS3_PWD_IC25SPARE2_MSB                                                                  24
#define BIAS3_PWD_IC25SPARE2_LSB                                                                  22
#define BIAS3_PWD_IC25SPARE2_MASK                                                         0x01c00000
#define BIAS3_PWD_IC25SPARE2_GET(x)                                       (((x) & 0x01c00000) >> 22)
#define BIAS3_PWD_IC25SPARE2_SET(x)                                       (((x) << 22) & 0x01c00000)
#define BIAS3_PWD_IC25SPARE1_MSB                                                                  27
#define BIAS3_PWD_IC25SPARE1_LSB                                                                  25
#define BIAS3_PWD_IC25SPARE1_MASK                                                         0x0e000000
#define BIAS3_PWD_IC25SPARE1_GET(x)                                       (((x) & 0x0e000000) >> 25)
#define BIAS3_PWD_IC25SPARE1_SET(x)                                       (((x) << 25) & 0x0e000000)
#define BIAS3_PWD_IRTSENS25_MSB                                                                   28
#define BIAS3_PWD_IRTSENS25_LSB                                                                   28
#define BIAS3_PWD_IRTSENS25_MASK                                                          0x10000000
#define BIAS3_PWD_IRTSENS25_GET(x)                                        (((x) & 0x10000000) >> 28)
#define BIAS3_PWD_IRTSENS25_SET(x)                                        (((x) << 28) & 0x10000000)
#define BIAS3_PWD_ICTSENS25_MSB                                                                   29
#define BIAS3_PWD_ICTSENS25_LSB                                                                   29
#define BIAS3_PWD_ICTSENS25_MASK                                                          0x20000000
#define BIAS3_PWD_ICTSENS25_GET(x)                                        (((x) & 0x20000000) >> 29)
#define BIAS3_PWD_ICTSENS25_SET(x)                                        (((x) << 29) & 0x20000000)
#define BIAS3_PWD_IRTXPC25_MSB                                                                    30
#define BIAS3_PWD_IRTXPC25_LSB                                                                    30
#define BIAS3_PWD_IRTXPC25_MASK                                                           0x40000000
#define BIAS3_PWD_IRTXPC25_GET(x)                                         (((x) & 0x40000000) >> 30)
#define BIAS3_PWD_IRTXPC25_SET(x)                                         (((x) << 30) & 0x40000000)
#define BIAS3_PWD_ICTXPC25_MSB                                                                    31
#define BIAS3_PWD_ICTXPC25_LSB                                                                    31
#define BIAS3_PWD_ICTXPC25_MASK                                                           0x80000000
#define BIAS3_PWD_ICTXPC25_GET(x)                                         (((x) & 0x80000000) >> 31)
#define BIAS3_PWD_ICTXPC25_SET(x)                                         (((x) << 31) & 0x80000000)

/* macros for BIAS4 */
#define BIAS4_ADDRESS                                                                     0x00000080
#define BIAS4_OFFSET                                                                      0x00000080
#define BIAS4_BIAS4_SPARE_MSB                                                                     14
#define BIAS4_BIAS4_SPARE_LSB                                                                      0
#define BIAS4_BIAS4_SPARE_MASK                                                            0x00007fff
#define BIAS4_BIAS4_SPARE_GET(x)                                           (((x) & 0x00007fff) >> 0)
#define BIAS4_BIAS4_SPARE_SET(x)                                           (((x) << 0) & 0x00007fff)
#define BIAS4_PWD_IRLOLDO25_MSB                                                                   17
#define BIAS4_PWD_IRLOLDO25_LSB                                                                   15
#define BIAS4_PWD_IRLOLDO25_MASK                                                          0x00038000
#define BIAS4_PWD_IRLOLDO25_GET(x)                                        (((x) & 0x00038000) >> 15)
#define BIAS4_PWD_IRLOLDO25_SET(x)                                        (((x) << 15) & 0x00038000)
#define BIAS4_PWD_ICXLNA5G50_MSB                                                                  20
#define BIAS4_PWD_ICXLNA5G50_LSB                                                                  18
#define BIAS4_PWD_ICXLNA5G50_MASK                                                         0x001c0000
#define BIAS4_PWD_ICXLNA5G50_GET(x)                                       (((x) & 0x001c0000) >> 18)
#define BIAS4_PWD_ICXLNA5G50_SET(x)                                       (((x) << 18) & 0x001c0000)
#define BIAS4_PWD_ICXLNA2G50_MSB                                                                  23
#define BIAS4_PWD_ICXLNA2G50_LSB                                                                  21
#define BIAS4_PWD_ICXLNA2G50_MASK                                                         0x00e00000
#define BIAS4_PWD_ICXLNA2G50_GET(x)                                       (((x) & 0x00e00000) >> 21)
#define BIAS4_PWD_ICXLNA2G50_SET(x)                                       (((x) << 21) & 0x00e00000)
#define BIAS4_BIAS4_SEL_SPARE_MSB                                                                 31
#define BIAS4_BIAS4_SEL_SPARE_LSB                                                                 24
#define BIAS4_BIAS4_SEL_SPARE_MASK                                                        0xff000000
#define BIAS4_BIAS4_SEL_SPARE_GET(x)                                      (((x) & 0xff000000) >> 24)
#define BIAS4_BIAS4_SEL_SPARE_SET(x)                                      (((x) << 24) & 0xff000000)

/* macros for GAIN0 */
#define GAIN0_ADDRESS                                                                     0x00000084
#define GAIN0_OFFSET                                                                      0x00000084
#define GAIN0_SPARE_MSB                                                                            0
#define GAIN0_SPARE_LSB                                                                            0
#define GAIN0_SPARE_MASK                                                                  0x00000001
#define GAIN0_SPARE_GET(x)                                                 (((x) & 0x00000001) >> 0)
#define GAIN0_SPARE_SET(x)                                                 (((x) << 0) & 0x00000001)
#define GAIN0_RX6DBHIQGAIN_MSB                                                                     2
#define GAIN0_RX6DBHIQGAIN_LSB                                                                     1
#define GAIN0_RX6DBHIQGAIN_MASK                                                           0x00000006
#define GAIN0_RX6DBHIQGAIN_GET(x)                                          (((x) & 0x00000006) >> 1)
#define GAIN0_RX6DBHIQGAIN_SET(x)                                          (((x) << 1) & 0x00000006)
#define GAIN0_RX1DBLOQGAIN_MSB                                                                     5
#define GAIN0_RX1DBLOQGAIN_LSB                                                                     3
#define GAIN0_RX1DBLOQGAIN_MASK                                                           0x00000038
#define GAIN0_RX1DBLOQGAIN_GET(x)                                          (((x) & 0x00000038) >> 3)
#define GAIN0_RX1DBLOQGAIN_SET(x)                                          (((x) << 3) & 0x00000038)
#define GAIN0_RX6DBLOQGAIN_MSB                                                                     7
#define GAIN0_RX6DBLOQGAIN_LSB                                                                     6
#define GAIN0_RX6DBLOQGAIN_MASK                                                           0x000000c0
#define GAIN0_RX6DBLOQGAIN_GET(x)                                          (((x) & 0x000000c0) >> 6)
#define GAIN0_RX6DBLOQGAIN_SET(x)                                          (((x) << 6) & 0x000000c0)
#define GAIN0_RFGMGN_MSB                                                                          10
#define GAIN0_RFGMGN_LSB                                                                           8
#define GAIN0_RFGMGN_MASK                                                                 0x00000700
#define GAIN0_RFGMGN_GET(x)                                                (((x) & 0x00000700) >> 8)
#define GAIN0_RFGMGN_SET(x)                                                (((x) << 8) & 0x00000700)
#define GAIN0_RFVGA5GAIN_MSB                                                                      12
#define GAIN0_RFVGA5GAIN_LSB                                                                      11
#define GAIN0_RFVGA5GAIN_MASK                                                             0x00001800
#define GAIN0_RFVGA5GAIN_GET(x)                                           (((x) & 0x00001800) >> 11)
#define GAIN0_RFVGA5GAIN_SET(x)                                           (((x) << 11) & 0x00001800)
#define GAIN0_LNAGAIN_MSB                                                                         16
#define GAIN0_LNAGAIN_LSB                                                                         13
#define GAIN0_LNAGAIN_MASK                                                                0x0001e000
#define GAIN0_LNAGAIN_GET(x)                                              (((x) & 0x0001e000) >> 13)
#define GAIN0_LNAGAIN_SET(x)                                              (((x) << 13) & 0x0001e000)
#define GAIN0_LNAON_MSB                                                                           17
#define GAIN0_LNAON_LSB                                                                           17
#define GAIN0_LNAON_MASK                                                                  0x00020000
#define GAIN0_LNAON_GET(x)                                                (((x) & 0x00020000) >> 17)
#define GAIN0_LNAON_SET(x)                                                (((x) << 17) & 0x00020000)
#define GAIN0_PAOUT2GN_MSB                                                                        20
#define GAIN0_PAOUT2GN_LSB                                                                        18
#define GAIN0_PAOUT2GN_MASK                                                               0x001c0000
#define GAIN0_PAOUT2GN_GET(x)                                             (((x) & 0x001c0000) >> 18)
#define GAIN0_PAOUT2GN_SET(x)                                             (((x) << 18) & 0x001c0000)
#define GAIN0_PADRVGN_MSB                                                                         23
#define GAIN0_PADRVGN_LSB                                                                         21
#define GAIN0_PADRVGN_MASK                                                                0x00e00000
#define GAIN0_PADRVGN_GET(x)                                              (((x) & 0x00e00000) >> 21)
#define GAIN0_PADRVGN_SET(x)                                              (((x) << 21) & 0x00e00000)
#define GAIN0_PABUF5GN_MSB                                                                        24
#define GAIN0_PABUF5GN_LSB                                                                        24
#define GAIN0_PABUF5GN_MASK                                                               0x01000000
#define GAIN0_PABUF5GN_GET(x)                                             (((x) & 0x01000000) >> 24)
#define GAIN0_PABUF5GN_SET(x)                                             (((x) << 24) & 0x01000000)
#define GAIN0_TXV2IGAIN_MSB                                                                       26
#define GAIN0_TXV2IGAIN_LSB                                                                       25
#define GAIN0_TXV2IGAIN_MASK                                                              0x06000000
#define GAIN0_TXV2IGAIN_GET(x)                                            (((x) & 0x06000000) >> 25)
#define GAIN0_TXV2IGAIN_SET(x)                                            (((x) << 25) & 0x06000000)
#define GAIN0_TX1DBLOQGAIN_MSB                                                                    29
#define GAIN0_TX1DBLOQGAIN_LSB                                                                    27
#define GAIN0_TX1DBLOQGAIN_MASK                                                           0x38000000
#define GAIN0_TX1DBLOQGAIN_GET(x)                                         (((x) & 0x38000000) >> 27)
#define GAIN0_TX1DBLOQGAIN_SET(x)                                         (((x) << 27) & 0x38000000)
#define GAIN0_TX6DBLOQGAIN_MSB                                                                    31
#define GAIN0_TX6DBLOQGAIN_LSB                                                                    30
#define GAIN0_TX6DBLOQGAIN_MASK                                                           0xc0000000
#define GAIN0_TX6DBLOQGAIN_GET(x)                                         (((x) & 0xc0000000) >> 30)
#define GAIN0_TX6DBLOQGAIN_SET(x)                                         (((x) << 30) & 0xc0000000)

/* macros for GAIN1 */
#define GAIN1_ADDRESS                                                                     0x00000088
#define GAIN1_OFFSET                                                                      0x00000088
#define GAIN1_SPARE_MSB                                                                            0
#define GAIN1_SPARE_LSB                                                                            0
#define GAIN1_SPARE_MASK                                                                  0x00000001
#define GAIN1_SPARE_GET(x)                                                 (((x) & 0x00000001) >> 0)
#define GAIN1_SPARE_SET(x)                                                 (((x) << 0) & 0x00000001)
#define GAIN1_RX6DBHIQGAIN_MSB                                                                     2
#define GAIN1_RX6DBHIQGAIN_LSB                                                                     1
#define GAIN1_RX6DBHIQGAIN_MASK                                                           0x00000006
#define GAIN1_RX6DBHIQGAIN_GET(x)                                          (((x) & 0x00000006) >> 1)
#define GAIN1_RX6DBHIQGAIN_SET(x)                                          (((x) << 1) & 0x00000006)
#define GAIN1_RX1DBLOQGAIN_MSB                                                                     5
#define GAIN1_RX1DBLOQGAIN_LSB                                                                     3
#define GAIN1_RX1DBLOQGAIN_MASK                                                           0x00000038
#define GAIN1_RX1DBLOQGAIN_GET(x)                                          (((x) & 0x00000038) >> 3)
#define GAIN1_RX1DBLOQGAIN_SET(x)                                          (((x) << 3) & 0x00000038)
#define GAIN1_RX6DBLOQGAIN_MSB                                                                     7
#define GAIN1_RX6DBLOQGAIN_LSB                                                                     6
#define GAIN1_RX6DBLOQGAIN_MASK                                                           0x000000c0
#define GAIN1_RX6DBLOQGAIN_GET(x)                                          (((x) & 0x000000c0) >> 6)
#define GAIN1_RX6DBLOQGAIN_SET(x)                                          (((x) << 6) & 0x000000c0)
#define GAIN1_RFGMGN_MSB                                                                          10
#define GAIN1_RFGMGN_LSB                                                                           8
#define GAIN1_RFGMGN_MASK                                                                 0x00000700
#define GAIN1_RFGMGN_GET(x)                                                (((x) & 0x00000700) >> 8)
#define GAIN1_RFGMGN_SET(x)                                                (((x) << 8) & 0x00000700)
#define GAIN1_RFVGA5GAIN_MSB                                                                      12
#define GAIN1_RFVGA5GAIN_LSB                                                                      11
#define GAIN1_RFVGA5GAIN_MASK                                                             0x00001800
#define GAIN1_RFVGA5GAIN_GET(x)                                           (((x) & 0x00001800) >> 11)
#define GAIN1_RFVGA5GAIN_SET(x)                                           (((x) << 11) & 0x00001800)
#define GAIN1_LNAGAIN_MSB                                                                         16
#define GAIN1_LNAGAIN_LSB                                                                         13
#define GAIN1_LNAGAIN_MASK                                                                0x0001e000
#define GAIN1_LNAGAIN_GET(x)                                              (((x) & 0x0001e000) >> 13)
#define GAIN1_LNAGAIN_SET(x)                                              (((x) << 13) & 0x0001e000)
#define GAIN1_LNAON_MSB                                                                           17
#define GAIN1_LNAON_LSB                                                                           17
#define GAIN1_LNAON_MASK                                                                  0x00020000
#define GAIN1_LNAON_GET(x)                                                (((x) & 0x00020000) >> 17)
#define GAIN1_LNAON_SET(x)                                                (((x) << 17) & 0x00020000)
#define GAIN1_PAOUT2GN_MSB                                                                        20
#define GAIN1_PAOUT2GN_LSB                                                                        18
#define GAIN1_PAOUT2GN_MASK                                                               0x001c0000
#define GAIN1_PAOUT2GN_GET(x)                                             (((x) & 0x001c0000) >> 18)
#define GAIN1_PAOUT2GN_SET(x)                                             (((x) << 18) & 0x001c0000)
#define GAIN1_PADRVGN_MSB                                                                         23
#define GAIN1_PADRVGN_LSB                                                                         21
#define GAIN1_PADRVGN_MASK                                                                0x00e00000
#define GAIN1_PADRVGN_GET(x)                                              (((x) & 0x00e00000) >> 21)
#define GAIN1_PADRVGN_SET(x)                                              (((x) << 21) & 0x00e00000)
#define GAIN1_PABUF5GN_MSB                                                                        24
#define GAIN1_PABUF5GN_LSB                                                                        24
#define GAIN1_PABUF5GN_MASK                                                               0x01000000
#define GAIN1_PABUF5GN_GET(x)                                             (((x) & 0x01000000) >> 24)
#define GAIN1_PABUF5GN_SET(x)                                             (((x) << 24) & 0x01000000)
#define GAIN1_TXV2IGAIN_MSB                                                                       26
#define GAIN1_TXV2IGAIN_LSB                                                                       25
#define GAIN1_TXV2IGAIN_MASK                                                              0x06000000
#define GAIN1_TXV2IGAIN_GET(x)                                            (((x) & 0x06000000) >> 25)
#define GAIN1_TXV2IGAIN_SET(x)                                            (((x) << 25) & 0x06000000)
#define GAIN1_TX1DBLOQGAIN_MSB                                                                    29
#define GAIN1_TX1DBLOQGAIN_LSB                                                                    27
#define GAIN1_TX1DBLOQGAIN_MASK                                                           0x38000000
#define GAIN1_TX1DBLOQGAIN_GET(x)                                         (((x) & 0x38000000) >> 27)
#define GAIN1_TX1DBLOQGAIN_SET(x)                                         (((x) << 27) & 0x38000000)
#define GAIN1_TX6DBLOQGAIN_MSB                                                                    31
#define GAIN1_TX6DBLOQGAIN_LSB                                                                    30
#define GAIN1_TX6DBLOQGAIN_MASK                                                           0xc0000000
#define GAIN1_TX6DBLOQGAIN_GET(x)                                         (((x) & 0xc0000000) >> 30)
#define GAIN1_TX6DBLOQGAIN_SET(x)                                         (((x) << 30) & 0xc0000000)

/* macros for TOP0 */
#define TOP0_ADDRESS                                                                      0x0000008c
#define TOP0_OFFSET                                                                       0x0000008c
#define TOP0_FORCEMSBLOW_MSB                                                                       0
#define TOP0_FORCEMSBLOW_LSB                                                                       0
#define TOP0_FORCEMSBLOW_MASK                                                             0x00000001
#define TOP0_FORCEMSBLOW_GET(x)                                            (((x) & 0x00000001) >> 0)
#define TOP0_FORCEMSBLOW_SET(x)                                            (((x) << 0) & 0x00000001)
#define TOP0_PWDBIAS_MSB                                                                           1
#define TOP0_PWDBIAS_LSB                                                                           1
#define TOP0_PWDBIAS_MASK                                                                 0x00000002
#define TOP0_PWDBIAS_GET(x)                                                (((x) & 0x00000002) >> 1)
#define TOP0_PWDBIAS_SET(x)                                                (((x) << 1) & 0x00000002)
#define TOP0_SYNTHON_FORCE_MSB                                                                     2
#define TOP0_SYNTHON_FORCE_LSB                                                                     2
#define TOP0_SYNTHON_FORCE_MASK                                                           0x00000004
#define TOP0_SYNTHON_FORCE_GET(x)                                          (((x) & 0x00000004) >> 2)
#define TOP0_SYNTHON_FORCE_SET(x)                                          (((x) << 2) & 0x00000004)
#define TOP0_SCLKEN_FORCE_MSB                                                                      3
#define TOP0_SCLKEN_FORCE_LSB                                                                      3
#define TOP0_SCLKEN_FORCE_MASK                                                            0x00000008
#define TOP0_SCLKEN_FORCE_GET(x)                                           (((x) & 0x00000008) >> 3)
#define TOP0_SCLKEN_FORCE_SET(x)                                           (((x) << 3) & 0x00000008)
#define TOP0_OSCON_MSB                                                                             4
#define TOP0_OSCON_LSB                                                                             4
#define TOP0_OSCON_MASK                                                                   0x00000010
#define TOP0_OSCON_GET(x)                                                  (((x) & 0x00000010) >> 4)
#define TOP0_OSCON_SET(x)                                                  (((x) << 4) & 0x00000010)
#define TOP0_PWDCLKIN_MSB                                                                          5
#define TOP0_PWDCLKIN_LSB                                                                          5
#define TOP0_PWDCLKIN_MASK                                                                0x00000020
#define TOP0_PWDCLKIN_GET(x)                                               (((x) & 0x00000020) >> 5)
#define TOP0_PWDCLKIN_SET(x)                                               (((x) << 5) & 0x00000020)
#define TOP0_LOCALXTAL_MSB                                                                         6
#define TOP0_LOCALXTAL_LSB                                                                         6
#define TOP0_LOCALXTAL_MASK                                                               0x00000040
#define TOP0_LOCALXTAL_GET(x)                                              (((x) & 0x00000040) >> 6)
#define TOP0_LOCALXTAL_SET(x)                                              (((x) << 6) & 0x00000040)
#define TOP0_XPAON_MSB                                                                             7
#define TOP0_XPAON_LSB                                                                             7
#define TOP0_XPAON_MASK                                                                   0x00000080
#define TOP0_XPAON_GET(x)                                                  (((x) & 0x00000080) >> 7)
#define TOP0_XPAON_SET(x)                                                  (((x) << 7) & 0x00000080)
#define TOP0_XLNAON_MSB                                                                            9
#define TOP0_XLNAON_LSB                                                                            8
#define TOP0_XLNAON_MASK                                                                  0x00000300
#define TOP0_XLNAON_GET(x)                                                 (((x) & 0x00000300) >> 8)
#define TOP0_XLNAON_SET(x)                                                 (((x) << 8) & 0x00000300)
#define TOP0_PAON_MSB                                                                             11
#define TOP0_PAON_LSB                                                                             10
#define TOP0_PAON_MASK                                                                    0x00000c00
#define TOP0_PAON_GET(x)                                                  (((x) & 0x00000c00) >> 10)
#define TOP0_PAON_SET(x)                                                  (((x) << 10) & 0x00000c00)
#define TOP0_TXON_MSB                                                                             13
#define TOP0_TXON_LSB                                                                             12
#define TOP0_TXON_MASK                                                                    0x00003000
#define TOP0_TXON_GET(x)                                                  (((x) & 0x00003000) >> 12)
#define TOP0_TXON_SET(x)                                                  (((x) << 12) & 0x00003000)
#define TOP0_RXON_MSB                                                                             15
#define TOP0_RXON_LSB                                                                             14
#define TOP0_RXON_MASK                                                                    0x0000c000
#define TOP0_RXON_GET(x)                                                  (((x) & 0x0000c000) >> 14)
#define TOP0_RXON_SET(x)                                                  (((x) << 14) & 0x0000c000)
#define TOP0_SYNTHON_MSB                                                                          16
#define TOP0_SYNTHON_LSB                                                                          16
#define TOP0_SYNTHON_MASK                                                                 0x00010000
#define TOP0_SYNTHON_GET(x)                                               (((x) & 0x00010000) >> 16)
#define TOP0_SYNTHON_SET(x)                                               (((x) << 16) & 0x00010000)
#define TOP0_TURBOMODE_MSB                                                                        17
#define TOP0_TURBOMODE_LSB                                                                        17
#define TOP0_TURBOMODE_MASK                                                               0x00020000
#define TOP0_TURBOMODE_GET(x)                                             (((x) & 0x00020000) >> 17)
#define TOP0_TURBOMODE_SET(x)                                             (((x) << 17) & 0x00020000)
#define TOP0_BMODERXTX_MSB                                                                        19
#define TOP0_BMODERXTX_LSB                                                                        18
#define TOP0_BMODERXTX_MASK                                                               0x000c0000
#define TOP0_BMODERXTX_GET(x)                                             (((x) & 0x000c0000) >> 18)
#define TOP0_BMODERXTX_SET(x)                                             (((x) << 18) & 0x000c0000)
#define TOP0_BMODE_MSB                                                                            20
#define TOP0_BMODE_LSB                                                                            20
#define TOP0_BMODE_MASK                                                                   0x00100000
#define TOP0_BMODE_GET(x)                                                 (((x) & 0x00100000) >> 20)
#define TOP0_BMODE_SET(x)                                                 (((x) << 20) & 0x00100000)
#define TOP0_CALTX_MSB                                                                            22
#define TOP0_CALTX_LSB                                                                            21
#define TOP0_CALTX_MASK                                                                   0x00600000
#define TOP0_CALTX_GET(x)                                                 (((x) & 0x00600000) >> 21)
#define TOP0_CALTX_SET(x)                                                 (((x) << 21) & 0x00600000)
#define TOP0_CAL_RESIDUE_MSB                                                                      24
#define TOP0_CAL_RESIDUE_LSB                                                                      23
#define TOP0_CAL_RESIDUE_MASK                                                             0x01800000
#define TOP0_CAL_RESIDUE_GET(x)                                           (((x) & 0x01800000) >> 23)
#define TOP0_CAL_RESIDUE_SET(x)                                           (((x) << 23) & 0x01800000)
#define TOP0_CALDC_MSB                                                                            26
#define TOP0_CALDC_LSB                                                                            25
#define TOP0_CALDC_MASK                                                                   0x06000000
#define TOP0_CALDC_GET(x)                                                 (((x) & 0x06000000) >> 25)
#define TOP0_CALDC_SET(x)                                                 (((x) << 25) & 0x06000000)
#define TOP0_CALFC_MSB                                                                            28
#define TOP0_CALFC_LSB                                                                            27
#define TOP0_CALFC_MASK                                                                   0x18000000
#define TOP0_CALFC_GET(x)                                                 (((x) & 0x18000000) >> 27)
#define TOP0_CALFC_SET(x)                                                 (((x) << 27) & 0x18000000)
#define TOP0_LOCALMODE_MSB                                                                        29
#define TOP0_LOCALMODE_LSB                                                                        29
#define TOP0_LOCALMODE_MASK                                                               0x20000000
#define TOP0_LOCALMODE_GET(x)                                             (((x) & 0x20000000) >> 29)
#define TOP0_LOCALMODE_SET(x)                                             (((x) << 29) & 0x20000000)
#define TOP0_LOCALRXGAIN_MSB                                                                      30
#define TOP0_LOCALRXGAIN_LSB                                                                      30
#define TOP0_LOCALRXGAIN_MASK                                                             0x40000000
#define TOP0_LOCALRXGAIN_GET(x)                                           (((x) & 0x40000000) >> 30)
#define TOP0_LOCALRXGAIN_SET(x)                                           (((x) << 30) & 0x40000000)
#define TOP0_LOCALTXGAIN_MSB                                                                      31
#define TOP0_LOCALTXGAIN_LSB                                                                      31
#define TOP0_LOCALTXGAIN_MASK                                                             0x80000000
#define TOP0_LOCALTXGAIN_GET(x)                                           (((x) & 0x80000000) >> 31)
#define TOP0_LOCALTXGAIN_SET(x)                                           (((x) << 31) & 0x80000000)

/* macros for TOP1 */
#define TOP1_ADDRESS                                                                      0x00000090
#define TOP1_OFFSET                                                                       0x00000090
#define TOP1_PLL_SVREG_MSB                                                                         0
#define TOP1_PLL_SVREG_LSB                                                                         0
#define TOP1_PLL_SVREG_MASK                                                               0x00000001
#define TOP1_PLL_SVREG_GET(x)                                              (((x) & 0x00000001) >> 0)
#define TOP1_PLL_SVREG_SET(x)                                              (((x) << 0) & 0x00000001)
#define TOP1_PLL_SCLAMP_MSB                                                                        3
#define TOP1_PLL_SCLAMP_LSB                                                                        1
#define TOP1_PLL_SCLAMP_MASK                                                              0x0000000e
#define TOP1_PLL_SCLAMP_GET(x)                                             (((x) & 0x0000000e) >> 1)
#define TOP1_PLL_SCLAMP_SET(x)                                             (((x) << 1) & 0x0000000e)
#define TOP1_PLL_ICP_MSB                                                                           6
#define TOP1_PLL_ICP_LSB                                                                           4
#define TOP1_PLL_ICP_MASK                                                                 0x00000070
#define TOP1_PLL_ICP_GET(x)                                                (((x) & 0x00000070) >> 4)
#define TOP1_PLL_ICP_SET(x)                                                (((x) << 4) & 0x00000070)
#define TOP1_PLL_FILTER_MSB                                                                       14
#define TOP1_PLL_FILTER_LSB                                                                        7
#define TOP1_PLL_FILTER_MASK                                                              0x00007f80
#define TOP1_PLL_FILTER_GET(x)                                             (((x) & 0x00007f80) >> 7)
#define TOP1_PLL_FILTER_SET(x)                                             (((x) << 7) & 0x00007f80)
#define TOP1_PLL_ATB_MSB                                                                          16
#define TOP1_PLL_ATB_LSB                                                                          15
#define TOP1_PLL_ATB_MASK                                                                 0x00018000
#define TOP1_PLL_ATB_GET(x)                                               (((x) & 0x00018000) >> 15)
#define TOP1_PLL_ATB_SET(x)                                               (((x) << 15) & 0x00018000)
#define TOP1_INV_CLK160_ADC_MSB                                                                   17
#define TOP1_INV_CLK160_ADC_LSB                                                                   17
#define TOP1_INV_CLK160_ADC_MASK                                                          0x00020000
#define TOP1_INV_CLK160_ADC_GET(x)                                        (((x) & 0x00020000) >> 17)
#define TOP1_INV_CLK160_ADC_SET(x)                                        (((x) << 17) & 0x00020000)
#define TOP1_DACLPMODE_MSB                                                                        18
#define TOP1_DACLPMODE_LSB                                                                        18
#define TOP1_DACLPMODE_MASK                                                               0x00040000
#define TOP1_DACLPMODE_GET(x)                                             (((x) & 0x00040000) >> 18)
#define TOP1_DACLPMODE_SET(x)                                             (((x) << 18) & 0x00040000)
#define TOP1_PWDDAC_MSB                                                                           20
#define TOP1_PWDDAC_LSB                                                                           19
#define TOP1_PWDDAC_MASK                                                                  0x00180000
#define TOP1_PWDDAC_GET(x)                                                (((x) & 0x00180000) >> 19)
#define TOP1_PWDDAC_SET(x)                                                (((x) << 19) & 0x00180000)
#define TOP1_PWDADC_MSB                                                                           22
#define TOP1_PWDADC_LSB                                                                           21
#define TOP1_PWDADC_MASK                                                                  0x00600000
#define TOP1_PWDADC_GET(x)                                                (((x) & 0x00600000) >> 21)
#define TOP1_PWDADC_SET(x)                                                (((x) << 21) & 0x00600000)
#define TOP1_PWDPLL_MSB                                                                           23
#define TOP1_PWDPLL_LSB                                                                           23
#define TOP1_PWDPLL_MASK                                                                  0x00800000
#define TOP1_PWDPLL_GET(x)                                                (((x) & 0x00800000) >> 23)
#define TOP1_PWDPLL_SET(x)                                                (((x) << 23) & 0x00800000)
#define TOP1_LOCALADDAC_MSB                                                                       24
#define TOP1_LOCALADDAC_LSB                                                                       24
#define TOP1_LOCALADDAC_MASK                                                              0x01000000
#define TOP1_LOCALADDAC_GET(x)                                            (((x) & 0x01000000) >> 24)
#define TOP1_LOCALADDAC_SET(x)                                            (((x) << 24) & 0x01000000)
#define TOP1_INT2GND_MSB                                                                          25
#define TOP1_INT2GND_LSB                                                                          25
#define TOP1_INT2GND_MASK                                                                 0x02000000
#define TOP1_INT2GND_GET(x)                                               (((x) & 0x02000000) >> 25)
#define TOP1_INT2GND_SET(x)                                               (((x) << 25) & 0x02000000)
#define TOP1_PAD2GND_MSB                                                                          26
#define TOP1_PAD2GND_LSB                                                                          26
#define TOP1_PAD2GND_MASK                                                                 0x04000000
#define TOP1_PAD2GND_GET(x)                                               (((x) & 0x04000000) >> 26)
#define TOP1_PAD2GND_SET(x)                                               (((x) << 26) & 0x04000000)
#define TOP1_INTH2PAD_MSB                                                                         27
#define TOP1_INTH2PAD_LSB                                                                         27
#define TOP1_INTH2PAD_MASK                                                                0x08000000
#define TOP1_INTH2PAD_GET(x)                                              (((x) & 0x08000000) >> 27)
#define TOP1_INTH2PAD_SET(x)                                              (((x) << 27) & 0x08000000)
#define TOP1_INT2PAD_MSB                                                                          28
#define TOP1_INT2PAD_LSB                                                                          28
#define TOP1_INT2PAD_MASK                                                                 0x10000000
#define TOP1_INT2PAD_GET(x)                                               (((x) & 0x10000000) >> 28)
#define TOP1_INT2PAD_SET(x)                                               (((x) << 28) & 0x10000000)
#define TOP1_REVID_MSB                                                                            31
#define TOP1_REVID_LSB                                                                            29
#define TOP1_REVID_MASK                                                                   0xe0000000
#define TOP1_REVID_GET(x)                                                 (((x) & 0xe0000000) >> 29)

/* macros for TOP2 */
#define TOP2_ADDRESS                                                                      0x00000094
#define TOP2_OFFSET                                                                       0x00000094
#define TOP2_BYPASSVREGLO_MSB                                                                      0
#define TOP2_BYPASSVREGLO_LSB                                                                      0
#define TOP2_BYPASSVREGLO_MASK                                                            0x00000001
#define TOP2_BYPASSVREGLO_GET(x)                                           (((x) & 0x00000001) >> 0)
#define TOP2_BYPASSVREGLO_SET(x)                                           (((x) << 0) & 0x00000001)
#define TOP2_DATAOUTSEL_MSB                                                                        2
#define TOP2_DATAOUTSEL_LSB                                                                        1
#define TOP2_DATAOUTSEL_MASK                                                              0x00000006
#define TOP2_DATAOUTSEL_GET(x)                                             (((x) & 0x00000006) >> 1)
#define TOP2_DATAOUTSEL_SET(x)                                             (((x) << 1) & 0x00000006)
#define TOP2_TXPC_CLKDELAY_MSB                                                                     3
#define TOP2_TXPC_CLKDELAY_LSB                                                                     3
#define TOP2_TXPC_CLKDELAY_MASK                                                           0x00000008
#define TOP2_TXPC_CLKDELAY_GET(x)                                          (((x) & 0x00000008) >> 3)
#define TOP2_TXPC_CLKDELAY_SET(x)                                          (((x) << 3) & 0x00000008)
#define TOP2_TXPC_XPDBS_MSB                                                                        6
#define TOP2_TXPC_XPDBS_LSB                                                                        4
#define TOP2_TXPC_XPDBS_MASK                                                              0x00000070
#define TOP2_TXPC_XPDBS_GET(x)                                             (((x) & 0x00000070) >> 4)
#define TOP2_TXPC_XPDBS_SET(x)                                             (((x) << 4) & 0x00000070)
#define TOP2_TXPC_TESTPWD_MSB                                                                      7
#define TOP2_TXPC_TESTPWD_LSB                                                                      7
#define TOP2_TXPC_TESTPWD_MASK                                                            0x00000080
#define TOP2_TXPC_TESTPWD_GET(x)                                           (((x) & 0x00000080) >> 7)
#define TOP2_TXPC_TESTPWD_SET(x)                                           (((x) << 7) & 0x00000080)
#define TOP2_TXPC_TESTGAIN_MSB                                                                     9
#define TOP2_TXPC_TESTGAIN_LSB                                                                     8
#define TOP2_TXPC_TESTGAIN_MASK                                                           0x00000300
#define TOP2_TXPC_TESTGAIN_GET(x)                                          (((x) & 0x00000300) >> 8)
#define TOP2_TXPC_TESTGAIN_SET(x)                                          (((x) << 8) & 0x00000300)
#define TOP2_TXPC_TESTDAC_MSB                                                                     15
#define TOP2_TXPC_TESTDAC_LSB                                                                     10
#define TOP2_TXPC_TESTDAC_MASK                                                            0x0000fc00
#define TOP2_TXPC_TESTDAC_GET(x)                                          (((x) & 0x0000fc00) >> 10)
#define TOP2_TXPC_TESTDAC_SET(x)                                          (((x) << 10) & 0x0000fc00)
#define TOP2_TXPC_TEST_MSB                                                                        16
#define TOP2_TXPC_TEST_LSB                                                                        16
#define TOP2_TXPC_TEST_MASK                                                               0x00010000
#define TOP2_TXPC_TEST_GET(x)                                             (((x) & 0x00010000) >> 16)
#define TOP2_TXPC_TEST_SET(x)                                             (((x) << 16) & 0x00010000)
#define TOP2_TXPC_NEGOUT_MSB                                                                      17
#define TOP2_TXPC_NEGOUT_LSB                                                                      17
#define TOP2_TXPC_NEGOUT_MASK                                                             0x00020000
#define TOP2_TXPC_NEGOUT_GET(x)                                           (((x) & 0x00020000) >> 17)
#define TOP2_TXPC_NEGOUT_SET(x)                                           (((x) << 17) & 0x00020000)
#define TOP2_XTALDIV_MSB                                                                          19
#define TOP2_XTALDIV_LSB                                                                          18
#define TOP2_XTALDIV_MASK                                                                 0x000c0000
#define TOP2_XTALDIV_GET(x)                                               (((x) & 0x000c0000) >> 18)
#define TOP2_XTALDIV_SET(x)                                               (((x) << 18) & 0x000c0000)
#define TOP2_LOCALBIAS2X_MSB                                                                      20
#define TOP2_LOCALBIAS2X_LSB                                                                      20
#define TOP2_LOCALBIAS2X_MASK                                                             0x00100000
#define TOP2_LOCALBIAS2X_GET(x)                                           (((x) & 0x00100000) >> 20)
#define TOP2_LOCALBIAS2X_SET(x)                                           (((x) << 20) & 0x00100000)
#define TOP2_LOCALBIAS_MSB                                                                        21
#define TOP2_LOCALBIAS_LSB                                                                        21
#define TOP2_LOCALBIAS_MASK                                                               0x00200000
#define TOP2_LOCALBIAS_GET(x)                                             (((x) & 0x00200000) >> 21)
#define TOP2_LOCALBIAS_SET(x)                                             (((x) << 21) & 0x00200000)
#define TOP2_PWDCLKIND_MSB                                                                        22
#define TOP2_PWDCLKIND_LSB                                                                        22
#define TOP2_PWDCLKIND_MASK                                                               0x00400000
#define TOP2_PWDCLKIND_GET(x)                                             (((x) & 0x00400000) >> 22)
#define TOP2_PWDCLKIND_SET(x)                                             (((x) << 22) & 0x00400000)
#define TOP2_PWDXINPAD_MSB                                                                        23
#define TOP2_PWDXINPAD_LSB                                                                        23
#define TOP2_PWDXINPAD_MASK                                                               0x00800000
#define TOP2_PWDXINPAD_GET(x)                                             (((x) & 0x00800000) >> 23)
#define TOP2_PWDXINPAD_SET(x)                                             (((x) << 23) & 0x00800000)
#define TOP2_NOTCXODET_MSB                                                                        24
#define TOP2_NOTCXODET_LSB                                                                        24
#define TOP2_NOTCXODET_MASK                                                               0x01000000
#define TOP2_NOTCXODET_GET(x)                                             (((x) & 0x01000000) >> 24)
#define TOP2_NOTCXODET_SET(x)                                             (((x) << 24) & 0x01000000)
#define TOP2_XLNABUFIN_MSB                                                                        25
#define TOP2_XLNABUFIN_LSB                                                                        25
#define TOP2_XLNABUFIN_MASK                                                               0x02000000
#define TOP2_XLNABUFIN_GET(x)                                             (((x) & 0x02000000) >> 25)
#define TOP2_XLNABUFIN_SET(x)                                             (((x) << 25) & 0x02000000)
#define TOP2_XLNAISEL_MSB                                                                         27
#define TOP2_XLNAISEL_LSB                                                                         26
#define TOP2_XLNAISEL_MASK                                                                0x0c000000
#define TOP2_XLNAISEL_GET(x)                                              (((x) & 0x0c000000) >> 26)
#define TOP2_XLNAISEL_SET(x)                                              (((x) << 26) & 0x0c000000)
#define TOP2_XLNABUFMODE_MSB                                                                      28
#define TOP2_XLNABUFMODE_LSB                                                                      28
#define TOP2_XLNABUFMODE_MASK                                                             0x10000000
#define TOP2_XLNABUFMODE_GET(x)                                           (((x) & 0x10000000) >> 28)
#define TOP2_XLNABUFMODE_SET(x)                                           (((x) << 28) & 0x10000000)
#define TOP2_FORCE_XLDO_ON_MSB                                                                    29
#define TOP2_FORCE_XLDO_ON_LSB                                                                    29
#define TOP2_FORCE_XLDO_ON_MASK                                                           0x20000000
#define TOP2_FORCE_XLDO_ON_GET(x)                                         (((x) & 0x20000000) >> 29)
#define TOP2_FORCE_XLDO_ON_SET(x)                                         (((x) << 29) & 0x20000000)
#define TOP2_XPABIAS_LVL_MSB                                                                      31
#define TOP2_XPABIAS_LVL_LSB                                                                      30
#define TOP2_XPABIAS_LVL_MASK                                                             0xc0000000
#define TOP2_XPABIAS_LVL_GET(x)                                           (((x) & 0xc0000000) >> 30)
#define TOP2_XPABIAS_LVL_SET(x)                                           (((x) << 30) & 0xc0000000)

/* macros for TOP3 */
#define TOP3_ADDRESS                                                                      0x00000098
#define TOP3_OFFSET                                                                       0x00000098
#define TOP3_VREGLO_ATBSEL_MSB                                                                     2
#define TOP3_VREGLO_ATBSEL_LSB                                                                     0
#define TOP3_VREGLO_ATBSEL_MASK                                                           0x00000007
#define TOP3_VREGLO_ATBSEL_GET(x)                                          (((x) & 0x00000007) >> 0)
#define TOP3_VREGLO_ATBSEL_SET(x)                                          (((x) << 0) & 0x00000007)
#define TOP3_PLLFBDIVB_MSB                                                                        12
#define TOP3_PLLFBDIVB_LSB                                                                         3
#define TOP3_PLLFBDIVB_MASK                                                               0x00001ff8
#define TOP3_PLLFBDIVB_GET(x)                                              (((x) & 0x00001ff8) >> 3)
#define TOP3_PLLFBDIVB_SET(x)                                              (((x) << 3) & 0x00001ff8)
#define TOP3_PLLFBDIVA_MSB                                                                        22
#define TOP3_PLLFBDIVA_LSB                                                                        13
#define TOP3_PLLFBDIVA_MASK                                                               0x007fe000
#define TOP3_PLLFBDIVA_GET(x)                                             (((x) & 0x007fe000) >> 13)
#define TOP3_PLLFBDIVA_SET(x)                                             (((x) << 13) & 0x007fe000)
#define TOP3_PLLREFDIVB_MSB                                                                       26
#define TOP3_PLLREFDIVB_LSB                                                                       23
#define TOP3_PLLREFDIVB_MASK                                                              0x07800000
#define TOP3_PLLREFDIVB_GET(x)                                            (((x) & 0x07800000) >> 23)
#define TOP3_PLLREFDIVB_SET(x)                                            (((x) << 23) & 0x07800000)
#define TOP3_PLLREFDIVA_MSB                                                                       30
#define TOP3_PLLREFDIVA_LSB                                                                       27
#define TOP3_PLLREFDIVA_MASK                                                              0x78000000
#define TOP3_PLLREFDIVA_GET(x)                                            (((x) & 0x78000000) >> 27)
#define TOP3_PLLREFDIVA_SET(x)                                            (((x) << 27) & 0x78000000)
#define TOP3_LOCALPLLDIV_MSB                                                                      31
#define TOP3_LOCALPLLDIV_LSB                                                                      31
#define TOP3_LOCALPLLDIV_MASK                                                             0x80000000
#define TOP3_LOCALPLLDIV_GET(x)                                           (((x) & 0x80000000) >> 31)
#define TOP3_LOCALPLLDIV_SET(x)                                           (((x) << 31) & 0x80000000)


#ifndef __ASSEMBLER__

typedef struct merlin2_0_radio_reg_reg_s {
  volatile unsigned int RXTXBB1_CH1;                                   /*        0x0 - 0x4        */
  volatile unsigned int RXTXBB2_CH1;                                   /*        0x4 - 0x8        */
  volatile unsigned int RXTXBB3_CH1;                                   /*        0x8 - 0xc        */
  volatile unsigned int RXTXBB4_CH1;                                   /*        0xc - 0x10       */
  volatile unsigned int RF2G1_CH1;                                     /*       0x10 - 0x14       */
  volatile unsigned int RF2G2_CH1;                                     /*       0x14 - 0x18       */
  volatile unsigned int RF5G1_CH1;                                     /*       0x18 - 0x1c       */
  volatile unsigned int RF5G2_CH1;                                     /*       0x1c - 0x20       */
  volatile unsigned int RF5G3_CH1;                                     /*       0x20 - 0x24       */
  volatile unsigned int RXTXBB1_CH0;                                   /*       0x24 - 0x28       */
  volatile unsigned int RXTXBB2_CH0;                                   /*       0x28 - 0x2c       */
  volatile unsigned int RXTXBB3_CH0;                                   /*       0x2c - 0x30       */
  volatile unsigned int RXTXBB4_CH0;                                   /*       0x30 - 0x34       */
  volatile unsigned int RF5G1_CH0;                                     /*       0x34 - 0x38       */
  volatile unsigned int RF5G2_CH0;                                     /*       0x38 - 0x3c       */
  volatile unsigned int RF5G3_CH0;                                     /*       0x3c - 0x40       */
  volatile unsigned int RF2G1_CH0;                                     /*       0x40 - 0x44       */
  volatile unsigned int RF2G2_CH0;                                     /*       0x44 - 0x48       */
  volatile unsigned int SYNTH1;                                        /*       0x48 - 0x4c       */
  volatile unsigned int SYNTH2;                                        /*       0x4c - 0x50       */
  volatile unsigned int SYNTH3;                                        /*       0x50 - 0x54       */
  volatile unsigned int SYNTH4;                                        /*       0x54 - 0x58       */
  volatile unsigned int SYNTH5;                                        /*       0x58 - 0x5c       */
  volatile unsigned int SYNTH6;                                        /*       0x5c - 0x60       */
  volatile unsigned int SYNTH7;                                        /*       0x60 - 0x64       */
  volatile unsigned int SYNTH8;                                        /*       0x64 - 0x68       */
  volatile unsigned int SYNTH9;                                        /*       0x68 - 0x6c       */
  volatile unsigned int SYNTH10;                                       /*       0x6c - 0x70       */
  volatile unsigned int SYNTH11;                                       /*       0x70 - 0x74       */
  volatile unsigned int BIAS1;                                         /*       0x74 - 0x78       */
  volatile unsigned int BIAS2;                                         /*       0x78 - 0x7c       */
  volatile unsigned int BIAS3;                                         /*       0x7c - 0x80       */
  volatile unsigned int BIAS4;                                         /*       0x80 - 0x84       */
  volatile unsigned int GAIN0;                                         /*       0x84 - 0x88       */
  volatile unsigned int GAIN1;                                         /*       0x88 - 0x8c       */
  volatile unsigned int TOP0;                                          /*       0x8c - 0x90       */
  volatile unsigned int TOP1;                                          /*       0x90 - 0x94       */
  volatile unsigned int TOP2;                                          /*       0x94 - 0x98       */
  volatile unsigned int TOP3;                                          /*       0x98 - 0x9c       */
} merlin2_0_radio_reg_reg_t;

#endif /* __ASSEMBLER__ */

#endif /* _MERLIN2_0_RADIO_REG_H_ */
