// ------------------------------------------------------------------
// Copyright (c) 2004-2012 Qualcomm Atheros.  All rights reserved.
// $ATH_LICENSE_TARGET_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Qualcomm Atheros"
//===================================================================



#ifndef _SM1_TABLE_MAP_H_
#define _SM1_TABLE_MAP_H_


/* macros for BB_aic_srams_b1 */
#define BB_SM1_TIER_AIC_SRAMS_B1_ADDRESS                                                           0x00000000
#define BB_SM1_TIER_AIC_SRAMS_B1_OFFSET                                                            0x00000000
#define BB_SM1_TIER_AIC_SRAMS_B1_AIC_WORD_MSB                                                              19
#define BB_SM1_TIER_AIC_SRAMS_B1_AIC_WORD_LSB                                                               0
#define BB_SM1_TIER_AIC_SRAMS_B1_AIC_WORD_MASK                                                     0x000fffff
#define BB_SM1_TIER_AIC_SRAMS_B1_AIC_WORD_GET(x)                                    (((x) & 0x000fffff) >> 0)
#define BB_SM1_TIER_AIC_SRAMS_B1_AIC_WORD_SET(x)                                    (((x) << 0) & 0x000fffff)

/* macros for BB_aic_cal_srams_b1 */
#define BB_SM1_TIER_AIC_CAL_SRAMS_B1_ADDRESS                                                       0x00000140
#define BB_SM1_TIER_AIC_CAL_SRAMS_B1_OFFSET                                                        0x00000140
#define BB_SM1_TIER_AIC_CAL_SRAMS_B1_AIC_WORD_MSB                                                          28
#define BB_SM1_TIER_AIC_CAL_SRAMS_B1_AIC_WORD_LSB                                                           0
#define BB_SM1_TIER_AIC_CAL_SRAMS_B1_AIC_WORD_MASK                                                 0x1fffffff
#define BB_SM1_TIER_AIC_CAL_SRAMS_B1_AIC_WORD_GET(x)                                (((x) & 0x1fffffff) >> 0)
#define BB_SM1_TIER_AIC_CAL_SRAMS_B1_AIC_WORD_SET(x)                                (((x) << 0) & 0x1fffffff)

/* macros for BB_aic_gain_tab_b1 */
#define BB_SM1_TIER_AIC_GAIN_TAB_B1_ADDRESS                                                        0x00000280
#define BB_SM1_TIER_AIC_GAIN_TAB_B1_OFFSET                                                         0x00000280
#define BB_SM1_TIER_AIC_GAIN_TAB_B1_AIC_ATTEN_MSB                                                          17
#define BB_SM1_TIER_AIC_GAIN_TAB_B1_AIC_ATTEN_LSB                                                           0
#define BB_SM1_TIER_AIC_GAIN_TAB_B1_AIC_ATTEN_MASK                                                 0x0003ffff
#define BB_SM1_TIER_AIC_GAIN_TAB_B1_AIC_ATTEN_GET(x)                                (((x) & 0x0003ffff) >> 0)
#define BB_SM1_TIER_AIC_GAIN_TAB_B1_AIC_ATTEN_SET(x)                                (((x) << 0) & 0x0003ffff)

/* macros for BB_dc_dac_mem_b1 */
#define BB_SM1_TIER_DC_DAC_MEM_B1_ADDRESS                                                          0x000003c0
#define BB_SM1_TIER_DC_DAC_MEM_B1_OFFSET                                                           0x000003c0
#define BB_SM1_TIER_DC_DAC_MEM_B1_DC_DAC_SETTING_MSB                                                       19
#define BB_SM1_TIER_DC_DAC_MEM_B1_DC_DAC_SETTING_LSB                                                        0
#define BB_SM1_TIER_DC_DAC_MEM_B1_DC_DAC_SETTING_MASK                                              0x000fffff
#define BB_SM1_TIER_DC_DAC_MEM_B1_DC_DAC_SETTING_GET(x)                             (((x) & 0x000fffff) >> 0)
#define BB_SM1_TIER_DC_DAC_MEM_B1_DC_DAC_SETTING_SET(x)                             (((x) << 0) & 0x000fffff)

/* macros for BB_sm1_tables_dummy2 */
#define BB_SM1_TIER_SM1_TABLES_DUMMY2_ADDRESS                                                      0x000005fc
#define BB_SM1_TIER_SM1_TABLES_DUMMY2_OFFSET                                                       0x000005fc
#define BB_SM1_TIER_SM1_TABLES_DUMMY2_DUMMY2_MSB                                                           31
#define BB_SM1_TIER_SM1_TABLES_DUMMY2_DUMMY2_LSB                                                            0
#define BB_SM1_TIER_SM1_TABLES_DUMMY2_DUMMY2_MASK                                                  0xffffffff
#define BB_SM1_TIER_SM1_TABLES_DUMMY2_DUMMY2_GET(x)                                 (((x) & 0xffffffff) >> 0)
#define BB_SM1_TIER_SM1_TABLES_DUMMY2_DUMMY2_SET(x)                                 (((x) << 0) & 0xffffffff)


#ifndef __ASSEMBLER__

typedef struct sm1_table_map_reg_s {
  volatile unsigned int BB_SM1_TIER_aic_srams_b1[80];                           /*        0x0 - 0x140      */
  volatile unsigned int BB_SM1_TIER_aic_cal_srams_b1[80];                       /*      0x140 - 0x280      */
  volatile unsigned int BB_SM1_TIER_aic_gain_tab_b1[19];                        /*      0x280 - 0x2cc      */
  volatile char pad__0[0xf4];                                          /*      0x2cc - 0x3c0      */
  volatile unsigned int BB_SM1_TIER_dc_dac_mem_b1[4];                           /*      0x3c0 - 0x3d0      */
  volatile char pad__1[0x22c];                                         /*      0x3d0 - 0x5fc      */
  volatile unsigned int BB_SM1_TIER_sm1_tables_dummy2;                          /*      0x5fc - 0x600      */
} sm1_table_map_reg_t;

#endif /* __ASSEMBLER__ */

#endif /* _SM1_TABLE_MAP_H_ */
