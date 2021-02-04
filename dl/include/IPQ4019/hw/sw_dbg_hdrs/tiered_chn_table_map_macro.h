/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef __REG_TIERED_CHN_TABLE_MAP_MACRO_H__
#define __REG_TIERED_CHN_TABLE_MAP_MACRO_H__


/* macros for BlueprintGlobalNameSpace::paprd_power_at_am2am_cal_b0 */
#ifndef __PAPRD_POWER_AT_AM2AM_CAL_B0_MACRO__
#define __PAPRD_POWER_AT_AM2AM_CAL_B0_MACRO__

/* macros for field paprd_power_at_am2am_cal_0_b0 */
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__SHIFT     0
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__MASK \
                    0x0000003fU
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field paprd_power_at_am2am_cal_1_b0 */
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__SHIFT     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__MASK \
                    0x00000fc0U
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field paprd_power_at_am2am_cal_2_b0 */
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__SHIFT    12
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__MASK \
                    0x0003f000U
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field paprd_power_at_am2am_cal_3_b0 */
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__SHIFT    18
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__MASK \
                    0x00fc0000U
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))

/* macros for field paprd_power_at_am2am_cal_4_b0 */
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__SHIFT    24
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__MASK \
                    0x3f000000U
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3f000000U) >> 24)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x3f000000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((u_int32_t)(src) <<\
                    24) & 0x3f000000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define PAPRD_POWER_AT_AM2AM_CAL_B0__TYPE                             u_int32_t
#define PAPRD_POWER_AT_AM2AM_CAL_B0__READ                           0x3fffffffU
#define PAPRD_POWER_AT_AM2AM_CAL_B0__WRITE                          0x3fffffffU

#endif /* __PAPRD_POWER_AT_AM2AM_CAL_B0_MACRO__ */


/* macros for chn_table_map.BB_paprd_power_at_am2am_cal_b0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_POWER_AT_AM2AM_CAL_B0__NUM               1

/* macros for BlueprintGlobalNameSpace::paprd_valid_obdb_b0 */
#ifndef __PAPRD_VALID_OBDB_B0_MACRO__
#define __PAPRD_VALID_OBDB_B0_MACRO__

/* macros for field paprd_valid_obdb_0_b0 */
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__SHIFT                     0
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__WIDTH                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__MASK            0x0000003fU
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field paprd_valid_obdb_1_b0 */
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__SHIFT                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__WIDTH                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__MASK            0x00000fc0U
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field paprd_valid_obdb_2_b0 */
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__SHIFT                    12
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__WIDTH                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__MASK            0x0003f000U
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field paprd_valid_obdb_3_b0 */
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__SHIFT                    18
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__WIDTH                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__MASK            0x00fc0000U
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))

/* macros for field paprd_valid_obdb_4_b0 */
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__SHIFT                    24
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__WIDTH                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__MASK            0x3f000000U
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3f000000U) >> 24)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x3f000000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((u_int32_t)(src) <<\
                    24) & 0x3f000000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define PAPRD_VALID_OBDB_B0__TYPE                                     u_int32_t
#define PAPRD_VALID_OBDB_B0__READ                                   0x3fffffffU
#define PAPRD_VALID_OBDB_B0__WRITE                                  0x3fffffffU

#endif /* __PAPRD_VALID_OBDB_B0_MACRO__ */


/* macros for chn_table_map.BB_paprd_valid_obdb_b0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_VALID_OBDB_B0__NUM                       1

/* macros for BlueprintGlobalNameSpace::chn_tables_dummy_2 */
#ifndef __CHN_TABLES_DUMMY_2_MACRO__
#define __CHN_TABLES_DUMMY_2_MACRO__

/* macros for field dummy2 */
#define CHN_TABLES_DUMMY_2__DUMMY2__SHIFT                                     0
#define CHN_TABLES_DUMMY_2__DUMMY2__WIDTH                                    32
#define CHN_TABLES_DUMMY_2__DUMMY2__MASK                            0xffffffffU
#define CHN_TABLES_DUMMY_2__DUMMY2__READ(src)    (u_int32_t)(src) & 0xffffffffU
#define CHN_TABLES_DUMMY_2__DUMMY2__WRITE(src) ((u_int32_t)(src) & 0xffffffffU)
#define CHN_TABLES_DUMMY_2__DUMMY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((u_int32_t)(src) &\
                    0xffffffffU)
#define CHN_TABLES_DUMMY_2__DUMMY2__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0xffffffffU)))
#define CHN_TABLES_DUMMY_2__TYPE                                      u_int32_t
#define CHN_TABLES_DUMMY_2__READ                                    0xffffffffU
#define CHN_TABLES_DUMMY_2__WRITE                                   0xffffffffU

#endif /* __CHN_TABLES_DUMMY_2_MACRO__ */


/* macros for chn_table_map.BB_chn_tables_dummy_2 */
#define INST_CHN_TABLE_MAP__BB_CHN_TABLES_DUMMY_2__NUM                        1

/* macros for BlueprintGlobalNameSpace::txiqcorr_txpath_coef_b0 */
#ifndef __TXIQCORR_TXPATH_COEF_B0_MACRO__
#define __TXIQCORR_TXPATH_COEF_B0_MACRO__

/* macros for field txiqcorr_txpath_coef_chn0 */
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__SHIFT             0
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__WIDTH            18
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__MASK    0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0003ffffU)
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((u_int32_t)(src) &\
                    0x0003ffffU)
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0003ffffU)))
#define TXIQCORR_TXPATH_COEF_B0__TYPE                                 u_int32_t
#define TXIQCORR_TXPATH_COEF_B0__READ                               0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B0__WRITE                              0x0003ffffU

#endif /* __TXIQCORR_TXPATH_COEF_B0_MACRO__ */


/* macros for chn_table_map.BB_txiqcorr_txpath_coef_b0 */
#define INST_CHN_TABLE_MAP__BB_TXIQCORR_TXPATH_COEF_B0__NUM                  16

/* macros for BlueprintGlobalNameSpace::txiqcorr_rxpath_coef_b0 */
#ifndef __TXIQCORR_RXPATH_COEF_B0_MACRO__
#define __TXIQCORR_RXPATH_COEF_B0_MACRO__

/* macros for field txiqcorr_rxpath_coef_chn0 */
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__SHIFT             0
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__WIDTH            18
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__MASK    0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0003ffffU)
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((u_int32_t)(src) &\
                    0x0003ffffU)
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0003ffffU)))
#define TXIQCORR_RXPATH_COEF_B0__TYPE                                 u_int32_t
#define TXIQCORR_RXPATH_COEF_B0__READ                               0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B0__WRITE                              0x0003ffffU

#endif /* __TXIQCORR_RXPATH_COEF_B0_MACRO__ */


/* macros for chn_table_map.BB_txiqcorr_rxpath_coef_b0 */
#define INST_CHN_TABLE_MAP__BB_TXIQCORR_RXPATH_COEF_B0__NUM                  16

/* macros for BlueprintGlobalNameSpace::rxiqcorr_rxpath_coef_b0 */
#ifndef __RXIQCORR_RXPATH_COEF_B0_MACRO__
#define __RXIQCORR_RXPATH_COEF_B0_MACRO__

/* macros for field rxiqcorr_rxpath_coef_chn0 */
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__SHIFT             0
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__WIDTH            18
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__MASK    0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0003ffffU)
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((u_int32_t)(src) &\
                    0x0003ffffU)
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0003ffffU)))
#define RXIQCORR_RXPATH_COEF_B0__TYPE                                 u_int32_t
#define RXIQCORR_RXPATH_COEF_B0__READ                               0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B0__WRITE                              0x0003ffffU

#endif /* __RXIQCORR_RXPATH_COEF_B0_MACRO__ */


/* macros for chn_table_map.BB_rxiqcorr_rxpath_coef_b0 */
#define INST_CHN_TABLE_MAP__BB_RXIQCORR_RXPATH_COEF_B0__NUM                  16

/* macros for BlueprintGlobalNameSpace::rxiqcorr_txpath_coef_b0 */
#ifndef __RXIQCORR_TXPATH_COEF_B0_MACRO__
#define __RXIQCORR_TXPATH_COEF_B0_MACRO__

/* macros for field rxiqcorr_txpath_coef_chn0 */
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__SHIFT             0
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__WIDTH            18
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__MASK    0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0003ffffU)
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((u_int32_t)(src) &\
                    0x0003ffffU)
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0003ffffU)))
#define RXIQCORR_TXPATH_COEF_B0__TYPE                                 u_int32_t
#define RXIQCORR_TXPATH_COEF_B0__READ                               0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B0__WRITE                              0x0003ffffU

#endif /* __RXIQCORR_TXPATH_COEF_B0_MACRO__ */


/* macros for chn_table_map.BB_rxiqcorr_txpath_coef_b0 */
#define INST_CHN_TABLE_MAP__BB_RXIQCORR_TXPATH_COEF_B0__NUM                  16

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_7_0_b0 */
#ifndef __RXCAL_TX_IQCORR_IDX_7_0_B0_MACRO__
#define __RXCAL_TX_IQCORR_IDX_7_0_B0_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_0_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__SHIFT         0
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((u_int32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_1_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__SHIFT         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((u_int32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_2_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__SHIFT         8
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((u_int32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_3_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__SHIFT        12
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_4_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__SHIFT        16
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((u_int32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_5_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__SHIFT        20
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((u_int32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_6_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__SHIFT        24
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((u_int32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_7_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__SHIFT        28
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((u_int32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_7_0_B0__TYPE                              u_int32_t
#define RXCAL_TX_IQCORR_IDX_7_0_B0__READ                            0xffffffffU
#define RXCAL_TX_IQCORR_IDX_7_0_B0__WRITE                           0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_7_0_B0_MACRO__ */


/* macros for chn_table_map.BB_rxcal_tx_iqcorr_idx_7_0_b0 */
#define INST_CHN_TABLE_MAP__BB_RXCAL_TX_IQCORR_IDX_7_0_B0__NUM                1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_15_8_b0 */
#ifndef __RXCAL_TX_IQCORR_IDX_15_8_B0_MACRO__
#define __RXCAL_TX_IQCORR_IDX_15_8_B0_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_8_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__SHIFT        0
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__WIDTH        4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((u_int32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_9_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__SHIFT        4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__WIDTH        4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((u_int32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_10_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__SHIFT       8
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((u_int32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_11_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__SHIFT      12
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_12_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__SHIFT      16
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((u_int32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_13_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__SHIFT      20
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((u_int32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_14_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__SHIFT      24
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((u_int32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_15_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__SHIFT      28
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((u_int32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_15_8_B0__TYPE                             u_int32_t
#define RXCAL_TX_IQCORR_IDX_15_8_B0__READ                           0xffffffffU
#define RXCAL_TX_IQCORR_IDX_15_8_B0__WRITE                          0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_15_8_B0_MACRO__ */


/* macros for chn_table_map.BB_rxcal_tx_iqcorr_idx_15_8_b0 */
#define INST_CHN_TABLE_MAP__BB_RXCAL_TX_IQCORR_IDX_15_8_B0__NUM               1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_23_16_b0 */
#ifndef __RXCAL_TX_IQCORR_IDX_23_16_B0_MACRO__
#define __RXCAL_TX_IQCORR_IDX_23_16_B0_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_16_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__SHIFT      0
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((u_int32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_17_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__SHIFT      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((u_int32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_18_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__SHIFT      8
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((u_int32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_19_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__SHIFT     12
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_20_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__SHIFT     16
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((u_int32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_21_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__SHIFT     20
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((u_int32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_22_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__SHIFT     24
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((u_int32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_23_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__SHIFT     28
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((u_int32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_23_16_B0__TYPE                            u_int32_t
#define RXCAL_TX_IQCORR_IDX_23_16_B0__READ                          0xffffffffU
#define RXCAL_TX_IQCORR_IDX_23_16_B0__WRITE                         0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_23_16_B0_MACRO__ */


/* macros for chn_table_map.BB_rxcal_tx_iqcorr_idx_23_16_b0 */
#define INST_CHN_TABLE_MAP__BB_RXCAL_TX_IQCORR_IDX_23_16_B0__NUM              1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_31_24_b0 */
#ifndef __RXCAL_TX_IQCORR_IDX_31_24_B0_MACRO__
#define __RXCAL_TX_IQCORR_IDX_31_24_B0_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_24_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__SHIFT      0
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((u_int32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_25_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__SHIFT      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((u_int32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_26_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__SHIFT      8
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((u_int32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_27_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__SHIFT     12
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_28_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__SHIFT     16
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((u_int32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_29_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__SHIFT     20
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((u_int32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_30_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__SHIFT     24
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((u_int32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_31_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__SHIFT     28
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((u_int32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_31_24_B0__TYPE                            u_int32_t
#define RXCAL_TX_IQCORR_IDX_31_24_B0__READ                          0xffffffffU
#define RXCAL_TX_IQCORR_IDX_31_24_B0__WRITE                         0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_31_24_B0_MACRO__ */


/* macros for chn_table_map.BB_rxcal_tx_iqcorr_idx_31_24_b0 */
#define INST_CHN_TABLE_MAP__BB_RXCAL_TX_IQCORR_IDX_31_24_B0__NUM              1

/* macros for BlueprintGlobalNameSpace::txcal_rx_iqcorr_idx_7_0 */
#ifndef __TXCAL_RX_IQCORR_IDX_7_0_MACRO__
#define __TXCAL_RX_IQCORR_IDX_7_0_MACRO__

/* macros for field txcal_rx_iqcorr_idx_0 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__SHIFT                 0
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__MASK        0x0000000fU
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000000fU
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((u_int32_t)(src) &\
                    0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field txcal_rx_iqcorr_idx_1 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__SHIFT                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__MASK        0x000000f0U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000000f0U) >> 4)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((u_int32_t)(src) <<\
                    4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field txcal_rx_iqcorr_idx_2 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__SHIFT                 8
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__MASK        0x00000f00U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000f00U) >> 8)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((u_int32_t)(src) <<\
                    8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field txcal_rx_iqcorr_idx_3 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__SHIFT                12
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__MASK        0x0000f000U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000f000U) >> 12)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field txcal_rx_iqcorr_idx_4 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__SHIFT                16
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__MASK        0x000f0000U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000f0000U) >> 16)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((u_int32_t)(src) <<\
                    16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field txcal_rx_iqcorr_idx_5 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__SHIFT                20
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__MASK        0x00f00000U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00f00000U) >> 20)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((u_int32_t)(src) <<\
                    20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field txcal_rx_iqcorr_idx_6 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__SHIFT                24
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__MASK        0x0f000000U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0f000000U) >> 24)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((u_int32_t)(src) <<\
                    24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field txcal_rx_iqcorr_idx_7 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__SHIFT                28
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__MASK        0xf0000000U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__READ(src) \
                    (((u_int32_t)(src)\
                    & 0xf0000000U) >> 28)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((u_int32_t)(src) <<\
                    28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define TXCAL_RX_IQCORR_IDX_7_0__TYPE                                 u_int32_t
#define TXCAL_RX_IQCORR_IDX_7_0__READ                               0xffffffffU
#define TXCAL_RX_IQCORR_IDX_7_0__WRITE                              0xffffffffU

#endif /* __TXCAL_RX_IQCORR_IDX_7_0_MACRO__ */


/* macros for chn_table_map.BB_txcal_rx_iqcorr_idx_7_0 */
#define INST_CHN_TABLE_MAP__BB_TXCAL_RX_IQCORR_IDX_7_0__NUM                   1

/* macros for BlueprintGlobalNameSpace::txcal_rx_iqcorr_idx_15_8 */
#ifndef __TXCAL_RX_IQCORR_IDX_15_8_MACRO__
#define __TXCAL_RX_IQCORR_IDX_15_8_MACRO__

/* macros for field txcal_rx_iqcorr_idx_8 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__SHIFT                0
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__WIDTH                4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__MASK       0x0000000fU
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000000fU
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((u_int32_t)(src) &\
                    0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field txcal_rx_iqcorr_idx_9 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__SHIFT                4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__WIDTH                4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__MASK       0x000000f0U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000000f0U) >> 4)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((u_int32_t)(src) <<\
                    4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field txcal_rx_iqcorr_idx_10 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__SHIFT               8
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__MASK      0x00000f00U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000f00U) >> 8)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((u_int32_t)(src) <<\
                    8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field txcal_rx_iqcorr_idx_11 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__SHIFT              12
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__MASK      0x0000f000U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000f000U) >> 12)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field txcal_rx_iqcorr_idx_12 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__SHIFT              16
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__MASK      0x000f0000U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000f0000U) >> 16)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((u_int32_t)(src) <<\
                    16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field txcal_rx_iqcorr_idx_13 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__SHIFT              20
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__MASK      0x00f00000U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00f00000U) >> 20)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((u_int32_t)(src) <<\
                    20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field txcal_rx_iqcorr_idx_14 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__SHIFT              24
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__MASK      0x0f000000U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0f000000U) >> 24)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((u_int32_t)(src) <<\
                    24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field txcal_rx_iqcorr_idx_15 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__SHIFT              28
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__MASK      0xf0000000U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__READ(src) \
                    (((u_int32_t)(src)\
                    & 0xf0000000U) >> 28)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((u_int32_t)(src) <<\
                    28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define TXCAL_RX_IQCORR_IDX_15_8__TYPE                                u_int32_t
#define TXCAL_RX_IQCORR_IDX_15_8__READ                              0xffffffffU
#define TXCAL_RX_IQCORR_IDX_15_8__WRITE                             0xffffffffU

#endif /* __TXCAL_RX_IQCORR_IDX_15_8_MACRO__ */


/* macros for chn_table_map.BB_txcal_rx_iqcorr_idx_15_8 */
#define INST_CHN_TABLE_MAP__BB_TXCAL_RX_IQCORR_IDX_15_8__NUM                  1

/* macros for BlueprintGlobalNameSpace::txcal_rx_iqcorr_idx_23_16 */
#ifndef __TXCAL_RX_IQCORR_IDX_23_16_MACRO__
#define __TXCAL_RX_IQCORR_IDX_23_16_MACRO__

/* macros for field txcal_rx_iqcorr_idx_16 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__SHIFT              0
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__MASK     0x0000000fU
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000000fU
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((u_int32_t)(src) &\
                    0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field txcal_rx_iqcorr_idx_17 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__SHIFT              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__MASK     0x000000f0U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000000f0U) >> 4)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((u_int32_t)(src) <<\
                    4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field txcal_rx_iqcorr_idx_18 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__SHIFT              8
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__MASK     0x00000f00U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000f00U) >> 8)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((u_int32_t)(src) <<\
                    8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field txcal_rx_iqcorr_idx_19 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__SHIFT             12
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__MASK     0x0000f000U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000f000U) >> 12)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field txcal_rx_iqcorr_idx_20 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__SHIFT             16
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__MASK     0x000f0000U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000f0000U) >> 16)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((u_int32_t)(src) <<\
                    16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field txcal_rx_iqcorr_idx_21 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__SHIFT             20
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__MASK     0x00f00000U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00f00000U) >> 20)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((u_int32_t)(src) <<\
                    20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field txcal_rx_iqcorr_idx_22 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__SHIFT             24
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__MASK     0x0f000000U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0f000000U) >> 24)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((u_int32_t)(src) <<\
                    24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field txcal_rx_iqcorr_idx_23 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__SHIFT             28
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__MASK     0xf0000000U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__READ(src) \
                    (((u_int32_t)(src)\
                    & 0xf0000000U) >> 28)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((u_int32_t)(src) <<\
                    28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define TXCAL_RX_IQCORR_IDX_23_16__TYPE                               u_int32_t
#define TXCAL_RX_IQCORR_IDX_23_16__READ                             0xffffffffU
#define TXCAL_RX_IQCORR_IDX_23_16__WRITE                            0xffffffffU

#endif /* __TXCAL_RX_IQCORR_IDX_23_16_MACRO__ */


/* macros for chn_table_map.BB_txcal_rx_iqcorr_idx_23_16 */
#define INST_CHN_TABLE_MAP__BB_TXCAL_RX_IQCORR_IDX_23_16__NUM                 1

/* macros for BlueprintGlobalNameSpace::txcal_rx_iqcorr_idx_24 */
#ifndef __TXCAL_RX_IQCORR_IDX_24_MACRO__
#define __TXCAL_RX_IQCORR_IDX_24_MACRO__

/* macros for field txcal_rx_iqcorr_idx_24 */
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__SHIFT                 0
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__MASK        0x0000000fU
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000000fU
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((u_int32_t)(src) &\
                    0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000000fU)))
#define TXCAL_RX_IQCORR_IDX_24__TYPE                                  u_int32_t
#define TXCAL_RX_IQCORR_IDX_24__READ                                0x0000000fU
#define TXCAL_RX_IQCORR_IDX_24__WRITE                               0x0000000fU

#endif /* __TXCAL_RX_IQCORR_IDX_24_MACRO__ */


/* macros for chn_table_map.BB_txcal_rx_iqcorr_idx_24 */
#define INST_CHN_TABLE_MAP__BB_TXCAL_RX_IQCORR_IDX_24__NUM                    1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_0_2_b0 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_0_2_B0_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_0_2_B0_MACRO__

/* macros for field paprd_sm_sig_gain_0 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__SHIFT            0
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__MASK   0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_sm_sig_gain_1 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__SHIFT           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__MASK   0x000ffc00U
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_sm_sig_gain_2 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__SHIFT           20
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__MASK   0x3ff00000U
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__TYPE                          u_int32_t
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__READ                        0x3fffffffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__WRITE                       0x3fffffffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_0_2_B0_MACRO__ */


/* macros for chn_table_map.BB_paprd_sm_sig_gain_table_0_2_b0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__NUM            1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_3_5_b0 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_3_5_B0_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_3_5_B0_MACRO__

/* macros for field paprd_sm_sig_gain_3 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__SHIFT            0
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__MASK   0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_sm_sig_gain_4 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__SHIFT           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__MASK   0x000ffc00U
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_sm_sig_gain_5 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__SHIFT           20
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__MASK   0x3ff00000U
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__TYPE                          u_int32_t
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__READ                        0x3fffffffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__WRITE                       0x3fffffffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_3_5_B0_MACRO__ */


/* macros for chn_table_map.BB_paprd_sm_sig_gain_table_3_5_b0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__NUM            1

/* macros for BlueprintGlobalNameSpace::paprd_peftbl_sel_b0 */
#ifndef __PAPRD_PEFTBL_SEL_B0_MACRO__
#define __PAPRD_PEFTBL_SEL_B0_MACRO__

/* macros for field pef_table_sel_dpd0_b0 */
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD0_B0__SHIFT                     0
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD0_B0__WIDTH                     2
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD0_B0__MASK            0x00000003U
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD0_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000003U
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD0_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000003U)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD0_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((u_int32_t)(src) &\
                    0x00000003U)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD0_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000003U)))

/* macros for field pef_table_sel_dpd1_b0 */
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD1_B0__SHIFT                     2
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD1_B0__WIDTH                     2
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD1_B0__MASK            0x0000000cU
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD1_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000000cU) >> 2)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD1_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 2) & 0x0000000cU)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD1_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((u_int32_t)(src) <<\
                    2) & 0x0000000cU)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD1_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 2) & ~0x0000000cU)))

/* macros for field pef_table_sel_dpd2_b0 */
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD2_B0__SHIFT                     4
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD2_B0__WIDTH                     2
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD2_B0__MASK            0x00000030U
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD2_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000030U) >> 4)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD2_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 4) & 0x00000030U)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD2_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000030U) | (((u_int32_t)(src) <<\
                    4) & 0x00000030U)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD2_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 4) & ~0x00000030U)))

/* macros for field pef_table_sel_dpd3_b0 */
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD3_B0__SHIFT                     6
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD3_B0__WIDTH                     2
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD3_B0__MASK            0x000000c0U
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD3_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000000c0U) >> 6)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD3_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x000000c0U)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD3_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000c0U) | (((u_int32_t)(src) <<\
                    6) & 0x000000c0U)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD3_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x000000c0U)))

/* macros for field pef_table_sel_dpd4_b0 */
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD4_B0__SHIFT                     8
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD4_B0__WIDTH                     2
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD4_B0__MASK            0x00000300U
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD4_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000300U) >> 8)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD4_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x00000300U)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD4_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((u_int32_t)(src) <<\
                    8) & 0x00000300U)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD4_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x00000300U)))

/* macros for field pef_table_sel_dpd5_b0 */
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD5_B0__SHIFT                    10
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD5_B0__WIDTH                     2
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD5_B0__MASK            0x00000c00U
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD5_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000c00U) >> 10)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD5_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x00000c00U)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD5_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000c00U) | (((u_int32_t)(src) <<\
                    10) & 0x00000c00U)
#define PAPRD_PEFTBL_SEL_B0__PEF_TABLE_SEL_DPD5_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x00000c00U)))

/* macros for field pef_half_rate_tb0_0 */
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB0_0__SHIFT                      12
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB0_0__WIDTH                       1
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB0_0__MASK              0x00001000U
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB0_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00001000U) >> 12)
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB0_0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00001000U)
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB0_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((u_int32_t)(src) <<\
                    12) & 0x00001000U)
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB0_0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00001000U)))
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB0_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((u_int32_t)(1) << 12)
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB0_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((u_int32_t)(0) << 12)

/* macros for field pef_half_rate_tb1_0 */
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB1_0__SHIFT                      13
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB1_0__WIDTH                       1
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB1_0__MASK              0x00002000U
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB1_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00002000U) >> 13)
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB1_0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 13) & 0x00002000U)
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB1_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((u_int32_t)(src) <<\
                    13) & 0x00002000U)
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB1_0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 13) & ~0x00002000U)))
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB1_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((u_int32_t)(1) << 13)
#define PAPRD_PEFTBL_SEL_B0__PEF_HALF_RATE_TB1_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((u_int32_t)(0) << 13)
#define PAPRD_PEFTBL_SEL_B0__TYPE                                     u_int32_t
#define PAPRD_PEFTBL_SEL_B0__READ                                   0x00003fffU
#define PAPRD_PEFTBL_SEL_B0__WRITE                                  0x00003fffU

#endif /* __PAPRD_PEFTBL_SEL_B0_MACRO__ */


/* macros for chn_table_map.BB_paprd_peftbl_sel_b0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_PEFTBL_SEL_B0__NUM                       1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl0_set0_b0 */
#ifndef __PREEMP_COEF_TBL0_SET0_B0_MACRO__
#define __PREEMP_COEF_TBL0_SET0_B0_MACRO__

/* macros for field tx_preemp_coef_tbl0_i_0_b0 */
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_I_0_B0__SHIFT           0
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_I_0_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_I_0_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_I_0_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_I_0_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_I_0_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_I_0_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl0_q_0_b0 */
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_Q_0_B0__SHIFT          12
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_Q_0_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_Q_0_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_Q_0_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_Q_0_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_Q_0_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET0_B0__TX_PREEMP_COEF_TBL0_Q_0_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL0_SET0_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL0_SET0_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL0_SET0_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL0_SET0_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl0_set0_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL0_SET0_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl0_set1_b0 */
#ifndef __PREEMP_COEF_TBL0_SET1_B0_MACRO__
#define __PREEMP_COEF_TBL0_SET1_B0_MACRO__

/* macros for field tx_preemp_coef_tbl0_i_1_b0 */
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_I_1_B0__SHIFT           0
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_I_1_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_I_1_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_I_1_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_I_1_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_I_1_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_I_1_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl0_q_1_b0 */
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_Q_1_B0__SHIFT          12
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_Q_1_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_Q_1_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_Q_1_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_Q_1_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_Q_1_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET1_B0__TX_PREEMP_COEF_TBL0_Q_1_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL0_SET1_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL0_SET1_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL0_SET1_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL0_SET1_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl0_set1_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL0_SET1_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl0_set2_b0 */
#ifndef __PREEMP_COEF_TBL0_SET2_B0_MACRO__
#define __PREEMP_COEF_TBL0_SET2_B0_MACRO__

/* macros for field tx_preemp_coef_tbl0_i_2_b0 */
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_I_2_B0__SHIFT           0
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_I_2_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_I_2_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_I_2_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_I_2_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_I_2_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_I_2_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl0_q_2_b0 */
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_Q_2_B0__SHIFT          12
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_Q_2_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_Q_2_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_Q_2_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_Q_2_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_Q_2_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET2_B0__TX_PREEMP_COEF_TBL0_Q_2_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL0_SET2_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL0_SET2_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL0_SET2_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL0_SET2_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl0_set2_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL0_SET2_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl0_set3_b0 */
#ifndef __PREEMP_COEF_TBL0_SET3_B0_MACRO__
#define __PREEMP_COEF_TBL0_SET3_B0_MACRO__

/* macros for field tx_preemp_coef_tbl0_i_3_b0 */
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_I_3_B0__SHIFT           0
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_I_3_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_I_3_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_I_3_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_I_3_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_I_3_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_I_3_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl0_q_3_b0 */
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_Q_3_B0__SHIFT          12
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_Q_3_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_Q_3_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_Q_3_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_Q_3_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_Q_3_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET3_B0__TX_PREEMP_COEF_TBL0_Q_3_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL0_SET3_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL0_SET3_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL0_SET3_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL0_SET3_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl0_set3_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL0_SET3_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl0_set4_b0 */
#ifndef __PREEMP_COEF_TBL0_SET4_B0_MACRO__
#define __PREEMP_COEF_TBL0_SET4_B0_MACRO__

/* macros for field tx_preemp_coef_tbl0_i_4_b0 */
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_I_4_B0__SHIFT           0
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_I_4_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_I_4_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_I_4_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_I_4_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_I_4_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_I_4_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl0_q_4_b0 */
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_Q_4_B0__SHIFT          12
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_Q_4_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_Q_4_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_Q_4_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_Q_4_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_Q_4_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET4_B0__TX_PREEMP_COEF_TBL0_Q_4_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL0_SET4_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL0_SET4_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL0_SET4_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL0_SET4_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl0_set4_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL0_SET4_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl0_set5_b0 */
#ifndef __PREEMP_COEF_TBL0_SET5_B0_MACRO__
#define __PREEMP_COEF_TBL0_SET5_B0_MACRO__

/* macros for field tx_preemp_coef_tbl0_i_5_b0 */
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_I_5_B0__SHIFT           0
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_I_5_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_I_5_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_I_5_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_I_5_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_I_5_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_I_5_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl0_q_5_b0 */
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_Q_5_B0__SHIFT          12
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_Q_5_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_Q_5_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_Q_5_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_Q_5_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_Q_5_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET5_B0__TX_PREEMP_COEF_TBL0_Q_5_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL0_SET5_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL0_SET5_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL0_SET5_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL0_SET5_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl0_set5_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL0_SET5_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl0_set6_b0 */
#ifndef __PREEMP_COEF_TBL0_SET6_B0_MACRO__
#define __PREEMP_COEF_TBL0_SET6_B0_MACRO__

/* macros for field tx_preemp_coef_tbl0_i_6_b0 */
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_I_6_B0__SHIFT           0
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_I_6_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_I_6_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_I_6_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_I_6_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_I_6_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_I_6_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl0_q_6_b0 */
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_Q_6_B0__SHIFT          12
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_Q_6_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_Q_6_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_Q_6_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_Q_6_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_Q_6_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET6_B0__TX_PREEMP_COEF_TBL0_Q_6_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL0_SET6_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL0_SET6_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL0_SET6_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL0_SET6_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl0_set6_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL0_SET6_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl0_set7_b0 */
#ifndef __PREEMP_COEF_TBL0_SET7_B0_MACRO__
#define __PREEMP_COEF_TBL0_SET7_B0_MACRO__

/* macros for field tx_preemp_coef_tbl0_i_7_b0 */
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_I_7_B0__SHIFT           0
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_I_7_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_I_7_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_I_7_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_I_7_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_I_7_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_I_7_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl0_q_7_b0 */
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_Q_7_B0__SHIFT          12
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_Q_7_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_Q_7_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_Q_7_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_Q_7_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_Q_7_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET7_B0__TX_PREEMP_COEF_TBL0_Q_7_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL0_SET7_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL0_SET7_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL0_SET7_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL0_SET7_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl0_set7_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL0_SET7_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl0_set8_b0 */
#ifndef __PREEMP_COEF_TBL0_SET8_B0_MACRO__
#define __PREEMP_COEF_TBL0_SET8_B0_MACRO__

/* macros for field tx_preemp_coef_tbl0_i_8_b0 */
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_I_8_B0__SHIFT           0
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_I_8_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_I_8_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_I_8_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_I_8_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_I_8_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_I_8_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl0_q_8_b0 */
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_Q_8_B0__SHIFT          12
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_Q_8_B0__WIDTH          12
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_Q_8_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_Q_8_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_Q_8_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_Q_8_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL0_SET8_B0__TX_PREEMP_COEF_TBL0_Q_8_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL0_SET8_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL0_SET8_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL0_SET8_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL0_SET8_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl0_set8_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL0_SET8_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl1_set0_b0 */
#ifndef __PREEMP_COEF_TBL1_SET0_B0_MACRO__
#define __PREEMP_COEF_TBL1_SET0_B0_MACRO__

/* macros for field tx_preemp_coef_tbl1_i_0_b0 */
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_I_0_B0__SHIFT           0
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_I_0_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_I_0_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_I_0_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_I_0_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_I_0_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_I_0_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl1_q_0_b0 */
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_Q_0_B0__SHIFT          12
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_Q_0_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_Q_0_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_Q_0_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_Q_0_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_Q_0_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET0_B0__TX_PREEMP_COEF_TBL1_Q_0_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL1_SET0_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL1_SET0_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL1_SET0_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL1_SET0_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl1_set0_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL1_SET0_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl1_set1_b0 */
#ifndef __PREEMP_COEF_TBL1_SET1_B0_MACRO__
#define __PREEMP_COEF_TBL1_SET1_B0_MACRO__

/* macros for field tx_preemp_coef_tbl1_i_1_b0 */
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_I_1_B0__SHIFT           0
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_I_1_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_I_1_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_I_1_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_I_1_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_I_1_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_I_1_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl1_q_1_b0 */
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_Q_1_B0__SHIFT          12
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_Q_1_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_Q_1_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_Q_1_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_Q_1_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_Q_1_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET1_B0__TX_PREEMP_COEF_TBL1_Q_1_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL1_SET1_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL1_SET1_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL1_SET1_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL1_SET1_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl1_set1_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL1_SET1_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl1_set2_b0 */
#ifndef __PREEMP_COEF_TBL1_SET2_B0_MACRO__
#define __PREEMP_COEF_TBL1_SET2_B0_MACRO__

/* macros for field tx_preemp_coef_tbl1_i_2_b0 */
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_I_2_B0__SHIFT           0
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_I_2_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_I_2_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_I_2_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_I_2_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_I_2_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_I_2_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl1_q_2_b0 */
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_Q_2_B0__SHIFT          12
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_Q_2_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_Q_2_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_Q_2_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_Q_2_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_Q_2_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET2_B0__TX_PREEMP_COEF_TBL1_Q_2_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL1_SET2_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL1_SET2_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL1_SET2_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL1_SET2_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl1_set2_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL1_SET2_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl1_set3_b0 */
#ifndef __PREEMP_COEF_TBL1_SET3_B0_MACRO__
#define __PREEMP_COEF_TBL1_SET3_B0_MACRO__

/* macros for field tx_preemp_coef_tbl1_i_3_b0 */
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_I_3_B0__SHIFT           0
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_I_3_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_I_3_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_I_3_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_I_3_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_I_3_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_I_3_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl1_q_3_b0 */
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_Q_3_B0__SHIFT          12
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_Q_3_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_Q_3_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_Q_3_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_Q_3_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_Q_3_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET3_B0__TX_PREEMP_COEF_TBL1_Q_3_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL1_SET3_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL1_SET3_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL1_SET3_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL1_SET3_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl1_set3_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL1_SET3_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl1_set4_b0 */
#ifndef __PREEMP_COEF_TBL1_SET4_B0_MACRO__
#define __PREEMP_COEF_TBL1_SET4_B0_MACRO__

/* macros for field tx_preemp_coef_tbl1_i_4_b0 */
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_I_4_B0__SHIFT           0
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_I_4_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_I_4_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_I_4_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_I_4_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_I_4_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_I_4_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl1_q_4_b0 */
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_Q_4_B0__SHIFT          12
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_Q_4_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_Q_4_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_Q_4_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_Q_4_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_Q_4_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET4_B0__TX_PREEMP_COEF_TBL1_Q_4_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL1_SET4_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL1_SET4_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL1_SET4_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL1_SET4_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl1_set4_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL1_SET4_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl1_set5_b0 */
#ifndef __PREEMP_COEF_TBL1_SET5_B0_MACRO__
#define __PREEMP_COEF_TBL1_SET5_B0_MACRO__

/* macros for field tx_preemp_coef_tbl1_i_5_b0 */
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_I_5_B0__SHIFT           0
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_I_5_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_I_5_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_I_5_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_I_5_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_I_5_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_I_5_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl1_q_5_b0 */
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_Q_5_B0__SHIFT          12
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_Q_5_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_Q_5_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_Q_5_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_Q_5_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_Q_5_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET5_B0__TX_PREEMP_COEF_TBL1_Q_5_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL1_SET5_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL1_SET5_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL1_SET5_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL1_SET5_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl1_set5_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL1_SET5_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl1_set6_b0 */
#ifndef __PREEMP_COEF_TBL1_SET6_B0_MACRO__
#define __PREEMP_COEF_TBL1_SET6_B0_MACRO__

/* macros for field tx_preemp_coef_tbl1_i_6_b0 */
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_I_6_B0__SHIFT           0
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_I_6_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_I_6_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_I_6_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_I_6_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_I_6_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_I_6_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl1_q_6_b0 */
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_Q_6_B0__SHIFT          12
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_Q_6_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_Q_6_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_Q_6_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_Q_6_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_Q_6_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET6_B0__TX_PREEMP_COEF_TBL1_Q_6_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL1_SET6_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL1_SET6_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL1_SET6_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL1_SET6_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl1_set6_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL1_SET6_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl1_set7_b0 */
#ifndef __PREEMP_COEF_TBL1_SET7_B0_MACRO__
#define __PREEMP_COEF_TBL1_SET7_B0_MACRO__

/* macros for field tx_preemp_coef_tbl1_i_7_b0 */
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_I_7_B0__SHIFT           0
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_I_7_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_I_7_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_I_7_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_I_7_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_I_7_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_I_7_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl1_q_7_b0 */
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_Q_7_B0__SHIFT          12
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_Q_7_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_Q_7_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_Q_7_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_Q_7_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_Q_7_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET7_B0__TX_PREEMP_COEF_TBL1_Q_7_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL1_SET7_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL1_SET7_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL1_SET7_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL1_SET7_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl1_set7_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL1_SET7_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::preemp_coef_tbl1_set8_b0 */
#ifndef __PREEMP_COEF_TBL1_SET8_B0_MACRO__
#define __PREEMP_COEF_TBL1_SET8_B0_MACRO__

/* macros for field tx_preemp_coef_tbl1_i_8_b0 */
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_I_8_B0__SHIFT           0
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_I_8_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_I_8_B0__MASK  0x00000fffU
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_I_8_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_I_8_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_I_8_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_I_8_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field tx_preemp_coef_tbl1_q_8_b0 */
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_Q_8_B0__SHIFT          12
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_Q_8_B0__WIDTH          12
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_Q_8_B0__MASK  0x00fff000U
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_Q_8_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_Q_8_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_Q_8_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((u_int32_t)(src) <<\
                    12) & 0x00fff000U)
#define PREEMP_COEF_TBL1_SET8_B0__TX_PREEMP_COEF_TBL1_Q_8_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define PREEMP_COEF_TBL1_SET8_B0__TYPE                                u_int32_t
#define PREEMP_COEF_TBL1_SET8_B0__READ                              0x00ffffffU
#define PREEMP_COEF_TBL1_SET8_B0__WRITE                             0x00ffffffU

#endif /* __PREEMP_COEF_TBL1_SET8_B0_MACRO__ */


/* macros for chn_table_map.BB_preemp_coef_tbl1_set8_b0 */
#define INST_CHN_TABLE_MAP__BB_PREEMP_COEF_TBL1_SET8_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::paprd_bw_table_dpdoff_b0 */
#ifndef __PAPRD_BW_TABLE_DPDOFF_B0_MACRO__
#define __PAPRD_BW_TABLE_DPDOFF_B0_MACRO__

/* macros for field bw_table_dpdoff_bw05_b0 */
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW05_B0__SHIFT              0
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW05_B0__WIDTH              3
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW05_B0__MASK     0x00000007U
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW05_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000007U
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW05_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000007U)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW05_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((u_int32_t)(src) &\
                    0x00000007U)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW05_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000007U)))

/* macros for field bw_table_dpdoff_bw10_b0 */
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW10_B0__SHIFT              3
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW10_B0__WIDTH              3
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW10_B0__MASK     0x00000038U
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW10_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000038U) >> 3)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW10_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 3) & 0x00000038U)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW10_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((u_int32_t)(src) <<\
                    3) & 0x00000038U)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW10_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 3) & ~0x00000038U)))

/* macros for field bw_table_dpdoff_bw20_b0 */
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW20_B0__SHIFT              6
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW20_B0__WIDTH              3
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW20_B0__MASK     0x000001c0U
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW20_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000001c0U) >> 6)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW20_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x000001c0U)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW20_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((u_int32_t)(src) <<\
                    6) & 0x000001c0U)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW20_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x000001c0U)))

/* macros for field bw_table_dpdoff_bw40_b0 */
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW40_B0__SHIFT              9
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW40_B0__WIDTH              3
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW40_B0__MASK     0x00000e00U
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW40_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000e00U) >> 9)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW40_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 9) & 0x00000e00U)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW40_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((u_int32_t)(src) <<\
                    9) & 0x00000e00U)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW40_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 9) & ~0x00000e00U)))

/* macros for field bw_table_dpdoff_bw80_b0 */
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW80_B0__SHIFT             12
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW80_B0__WIDTH              3
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW80_B0__MASK     0x00007000U
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW80_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00007000U) >> 12)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW80_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00007000U)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW80_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((u_int32_t)(src) <<\
                    12) & 0x00007000U)
#define PAPRD_BW_TABLE_DPDOFF_B0__BW_TABLE_DPDOFF_BW80_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00007000U)))
#define PAPRD_BW_TABLE_DPDOFF_B0__TYPE                                u_int32_t
#define PAPRD_BW_TABLE_DPDOFF_B0__READ                              0x00007fffU
#define PAPRD_BW_TABLE_DPDOFF_B0__WRITE                             0x00007fffU

#endif /* __PAPRD_BW_TABLE_DPDOFF_B0_MACRO__ */


/* macros for chn_table_map.BB_paprd_bw_table_dpdoff_b0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_BW_TABLE_DPDOFF_B0__NUM                  1

/* macros for BlueprintGlobalNameSpace::paprd_bw_table_1_0_b0 */
#ifndef __PAPRD_BW_TABLE_1_0_B0_MACRO__
#define __PAPRD_BW_TABLE_1_0_B0_MACRO__

/* macros for field bw_table_0_bw05_b0 */
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW05_B0__SHIFT                      0
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW05_B0__WIDTH                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW05_B0__MASK             0x00000007U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW05_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000007U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW05_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000007U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW05_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((u_int32_t)(src) &\
                    0x00000007U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW05_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000007U)))

/* macros for field bw_table_0_bw10_b0 */
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW10_B0__SHIFT                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW10_B0__WIDTH                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW10_B0__MASK             0x00000038U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW10_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000038U) >> 3)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW10_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 3) & 0x00000038U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW10_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((u_int32_t)(src) <<\
                    3) & 0x00000038U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW10_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 3) & ~0x00000038U)))

/* macros for field bw_table_0_bw20_b0 */
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW20_B0__SHIFT                      6
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW20_B0__WIDTH                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW20_B0__MASK             0x000001c0U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW20_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000001c0U) >> 6)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW20_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x000001c0U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW20_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((u_int32_t)(src) <<\
                    6) & 0x000001c0U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW20_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x000001c0U)))

/* macros for field bw_table_0_bw40_b0 */
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW40_B0__SHIFT                      9
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW40_B0__WIDTH                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW40_B0__MASK             0x00000e00U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW40_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000e00U) >> 9)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW40_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 9) & 0x00000e00U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW40_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((u_int32_t)(src) <<\
                    9) & 0x00000e00U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW40_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 9) & ~0x00000e00U)))

/* macros for field bw_table_0_bw80_b0 */
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW80_B0__SHIFT                     12
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW80_B0__WIDTH                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW80_B0__MASK             0x00007000U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW80_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00007000U) >> 12)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW80_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00007000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW80_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((u_int32_t)(src) <<\
                    12) & 0x00007000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_0_BW80_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00007000U)))

/* macros for field bw_table_1_bw05_b0 */
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW05_B0__SHIFT                     16
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW05_B0__WIDTH                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW05_B0__MASK             0x00070000U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW05_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00070000U) >> 16)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW05_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x00070000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW05_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((u_int32_t)(src) <<\
                    16) & 0x00070000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW05_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x00070000U)))

/* macros for field bw_table_1_bw10_b0 */
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW10_B0__SHIFT                     19
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW10_B0__WIDTH                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW10_B0__MASK             0x00380000U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW10_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00380000U) >> 19)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW10_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 19) & 0x00380000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW10_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((u_int32_t)(src) <<\
                    19) & 0x00380000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW10_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 19) & ~0x00380000U)))

/* macros for field bw_table_1_bw20_b0 */
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW20_B0__SHIFT                     22
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW20_B0__WIDTH                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW20_B0__MASK             0x01c00000U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW20_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x01c00000U) >> 22)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW20_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 22) & 0x01c00000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW20_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01c00000U) | (((u_int32_t)(src) <<\
                    22) & 0x01c00000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW20_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 22) & ~0x01c00000U)))

/* macros for field bw_table_1_bw40_b0 */
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW40_B0__SHIFT                     25
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW40_B0__WIDTH                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW40_B0__MASK             0x0e000000U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW40_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0e000000U) >> 25)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW40_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 25) & 0x0e000000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW40_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0e000000U) | (((u_int32_t)(src) <<\
                    25) & 0x0e000000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW40_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 25) & ~0x0e000000U)))

/* macros for field bw_table_1_bw80_b0 */
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW80_B0__SHIFT                     28
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW80_B0__WIDTH                      3
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW80_B0__MASK             0x70000000U
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW80_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x70000000U) >> 28)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW80_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0x70000000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW80_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x70000000U) | (((u_int32_t)(src) <<\
                    28) & 0x70000000U)
#define PAPRD_BW_TABLE_1_0_B0__BW_TABLE_1_BW80_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0x70000000U)))
#define PAPRD_BW_TABLE_1_0_B0__TYPE                                   u_int32_t
#define PAPRD_BW_TABLE_1_0_B0__READ                                 0x7fff7fffU
#define PAPRD_BW_TABLE_1_0_B0__WRITE                                0x7fff7fffU

#endif /* __PAPRD_BW_TABLE_1_0_B0_MACRO__ */


/* macros for chn_table_map.BB_paprd_bw_table_1_0_b0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_BW_TABLE_1_0_B0__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_bw_table_3_2_b0 */
#ifndef __PAPRD_BW_TABLE_3_2_B0_MACRO__
#define __PAPRD_BW_TABLE_3_2_B0_MACRO__

/* macros for field bw_table_2_bw05_b0 */
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW05_B0__SHIFT                      0
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW05_B0__WIDTH                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW05_B0__MASK             0x00000007U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW05_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000007U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW05_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000007U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW05_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((u_int32_t)(src) &\
                    0x00000007U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW05_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000007U)))

/* macros for field bw_table_2_bw10_b0 */
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW10_B0__SHIFT                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW10_B0__WIDTH                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW10_B0__MASK             0x00000038U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW10_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000038U) >> 3)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW10_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 3) & 0x00000038U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW10_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((u_int32_t)(src) <<\
                    3) & 0x00000038U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW10_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 3) & ~0x00000038U)))

/* macros for field bw_table_2_bw20_b0 */
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW20_B0__SHIFT                      6
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW20_B0__WIDTH                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW20_B0__MASK             0x000001c0U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW20_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000001c0U) >> 6)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW20_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x000001c0U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW20_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((u_int32_t)(src) <<\
                    6) & 0x000001c0U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW20_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x000001c0U)))

/* macros for field bw_table_2_bw40_b0 */
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW40_B0__SHIFT                      9
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW40_B0__WIDTH                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW40_B0__MASK             0x00000e00U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW40_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000e00U) >> 9)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW40_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 9) & 0x00000e00U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW40_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((u_int32_t)(src) <<\
                    9) & 0x00000e00U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW40_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 9) & ~0x00000e00U)))

/* macros for field bw_table_2_bw80_b0 */
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW80_B0__SHIFT                     12
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW80_B0__WIDTH                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW80_B0__MASK             0x00007000U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW80_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00007000U) >> 12)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW80_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00007000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW80_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((u_int32_t)(src) <<\
                    12) & 0x00007000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_2_BW80_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00007000U)))

/* macros for field bw_table_3_bw05_b0 */
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW05_B0__SHIFT                     16
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW05_B0__WIDTH                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW05_B0__MASK             0x00070000U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW05_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00070000U) >> 16)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW05_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x00070000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW05_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((u_int32_t)(src) <<\
                    16) & 0x00070000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW05_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x00070000U)))

/* macros for field bw_table_3_bw10_b0 */
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW10_B0__SHIFT                     19
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW10_B0__WIDTH                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW10_B0__MASK             0x00380000U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW10_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00380000U) >> 19)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW10_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 19) & 0x00380000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW10_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((u_int32_t)(src) <<\
                    19) & 0x00380000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW10_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 19) & ~0x00380000U)))

/* macros for field bw_table_3_bw20_b0 */
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW20_B0__SHIFT                     22
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW20_B0__WIDTH                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW20_B0__MASK             0x01c00000U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW20_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x01c00000U) >> 22)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW20_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 22) & 0x01c00000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW20_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01c00000U) | (((u_int32_t)(src) <<\
                    22) & 0x01c00000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW20_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 22) & ~0x01c00000U)))

/* macros for field bw_table_3_bw40_b0 */
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW40_B0__SHIFT                     25
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW40_B0__WIDTH                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW40_B0__MASK             0x0e000000U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW40_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0e000000U) >> 25)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW40_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 25) & 0x0e000000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW40_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0e000000U) | (((u_int32_t)(src) <<\
                    25) & 0x0e000000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW40_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 25) & ~0x0e000000U)))

/* macros for field bw_table_3_bw80_b0 */
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW80_B0__SHIFT                     28
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW80_B0__WIDTH                      3
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW80_B0__MASK             0x70000000U
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW80_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x70000000U) >> 28)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW80_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0x70000000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW80_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x70000000U) | (((u_int32_t)(src) <<\
                    28) & 0x70000000U)
#define PAPRD_BW_TABLE_3_2_B0__BW_TABLE_3_BW80_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0x70000000U)))
#define PAPRD_BW_TABLE_3_2_B0__TYPE                                   u_int32_t
#define PAPRD_BW_TABLE_3_2_B0__READ                                 0x7fff7fffU
#define PAPRD_BW_TABLE_3_2_B0__WRITE                                0x7fff7fffU

#endif /* __PAPRD_BW_TABLE_3_2_B0_MACRO__ */


/* macros for chn_table_map.BB_paprd_bw_table_3_2_b0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_BW_TABLE_3_2_B0__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_bw_table_5_4_b0 */
#ifndef __PAPRD_BW_TABLE_5_4_B0_MACRO__
#define __PAPRD_BW_TABLE_5_4_B0_MACRO__

/* macros for field bw_table_4_bw05_b0 */
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW05_B0__SHIFT                      0
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW05_B0__WIDTH                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW05_B0__MASK             0x00000007U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW05_B0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000007U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW05_B0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000007U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW05_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((u_int32_t)(src) &\
                    0x00000007U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW05_B0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000007U)))

/* macros for field bw_table_4_bw10_b0 */
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW10_B0__SHIFT                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW10_B0__WIDTH                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW10_B0__MASK             0x00000038U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW10_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000038U) >> 3)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW10_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 3) & 0x00000038U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW10_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((u_int32_t)(src) <<\
                    3) & 0x00000038U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW10_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 3) & ~0x00000038U)))

/* macros for field bw_table_4_bw20_b0 */
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW20_B0__SHIFT                      6
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW20_B0__WIDTH                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW20_B0__MASK             0x000001c0U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW20_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000001c0U) >> 6)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW20_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x000001c0U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW20_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((u_int32_t)(src) <<\
                    6) & 0x000001c0U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW20_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x000001c0U)))

/* macros for field bw_table_4_bw40_b0 */
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW40_B0__SHIFT                      9
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW40_B0__WIDTH                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW40_B0__MASK             0x00000e00U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW40_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000e00U) >> 9)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW40_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 9) & 0x00000e00U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW40_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((u_int32_t)(src) <<\
                    9) & 0x00000e00U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW40_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 9) & ~0x00000e00U)))

/* macros for field bw_table_4_bw80_b0 */
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW80_B0__SHIFT                     12
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW80_B0__WIDTH                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW80_B0__MASK             0x00007000U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW80_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00007000U) >> 12)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW80_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00007000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW80_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((u_int32_t)(src) <<\
                    12) & 0x00007000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_4_BW80_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00007000U)))

/* macros for field bw_table_5_bw05_b0 */
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW05_B0__SHIFT                     16
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW05_B0__WIDTH                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW05_B0__MASK             0x00070000U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW05_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00070000U) >> 16)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW05_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x00070000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW05_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((u_int32_t)(src) <<\
                    16) & 0x00070000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW05_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x00070000U)))

/* macros for field bw_table_5_bw10_b0 */
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW10_B0__SHIFT                     19
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW10_B0__WIDTH                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW10_B0__MASK             0x00380000U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW10_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00380000U) >> 19)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW10_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 19) & 0x00380000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW10_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((u_int32_t)(src) <<\
                    19) & 0x00380000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW10_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 19) & ~0x00380000U)))

/* macros for field bw_table_5_bw20_b0 */
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW20_B0__SHIFT                     22
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW20_B0__WIDTH                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW20_B0__MASK             0x01c00000U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW20_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x01c00000U) >> 22)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW20_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 22) & 0x01c00000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW20_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01c00000U) | (((u_int32_t)(src) <<\
                    22) & 0x01c00000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW20_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 22) & ~0x01c00000U)))

/* macros for field bw_table_5_bw40_b0 */
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW40_B0__SHIFT                     25
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW40_B0__WIDTH                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW40_B0__MASK             0x0e000000U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW40_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0e000000U) >> 25)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW40_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 25) & 0x0e000000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW40_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0e000000U) | (((u_int32_t)(src) <<\
                    25) & 0x0e000000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW40_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 25) & ~0x0e000000U)))

/* macros for field bw_table_5_bw80_b0 */
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW80_B0__SHIFT                     28
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW80_B0__WIDTH                      3
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW80_B0__MASK             0x70000000U
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW80_B0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x70000000U) >> 28)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW80_B0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0x70000000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW80_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x70000000U) | (((u_int32_t)(src) <<\
                    28) & 0x70000000U)
#define PAPRD_BW_TABLE_5_4_B0__BW_TABLE_5_BW80_B0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0x70000000U)))
#define PAPRD_BW_TABLE_5_4_B0__TYPE                                   u_int32_t
#define PAPRD_BW_TABLE_5_4_B0__READ                                 0x7fff7fffU
#define PAPRD_BW_TABLE_5_4_B0__WRITE                                0x7fff7fffU

#endif /* __PAPRD_BW_TABLE_5_4_B0_MACRO__ */


/* macros for chn_table_map.BB_paprd_bw_table_5_4_b0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_BW_TABLE_5_4_B0__NUM                     1

/* macros for BlueprintGlobalNameSpace::tx_notch_coef_b0 */
#ifndef __TX_NOTCH_COEF_B0_MACRO__
#define __TX_NOTCH_COEF_B0_MACRO__

/* macros for field tx_notch_coef_a1_0 */
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A1_0__SHIFT                           0
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A1_0__WIDTH                          10
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A1_0__MASK                  0x000003ffU
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A1_0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A1_0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A1_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A1_0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field tx_notch_coef_a2_0 */
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A2_0__SHIFT                          10
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A2_0__WIDTH                          10
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A2_0__MASK                  0x000ffc00U
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A2_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A2_0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A2_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_A2_0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field tx_notch_coef_b1_0 */
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_B1_0__SHIFT                          20
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_B1_0__WIDTH                          10
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_B1_0__MASK                  0x3ff00000U
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_B1_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_B1_0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_B1_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define TX_NOTCH_COEF_B0__TX_NOTCH_COEF_B1_0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define TX_NOTCH_COEF_B0__TYPE                                        u_int32_t
#define TX_NOTCH_COEF_B0__READ                                      0x3fffffffU
#define TX_NOTCH_COEF_B0__WRITE                                     0x3fffffffU

#endif /* __TX_NOTCH_COEF_B0_MACRO__ */


/* macros for chn_table_map.BB_tx_notch_coef_b0 */
#define INST_CHN_TABLE_MAP__BB_TX_NOTCH_COEF_B0__NUM                          1

/* macros for BlueprintGlobalNameSpace::tx_notch_dpd_en_b0 */
#ifndef __TX_NOTCH_DPD_EN_B0_MACRO__
#define __TX_NOTCH_DPD_EN_B0_MACRO__

/* macros for field paprd_notch_sel_dpd0_0 */
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD0_0__SHIFT                     0
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD0_0__WIDTH                     1
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD0_0__MASK            0x00000001U
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD0_0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000001U
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD0_0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000001U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD0_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((u_int32_t)(src) &\
                    0x00000001U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD0_0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000001U)))
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD0_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(1)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD0_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(0)

/* macros for field paprd_notch_sel_dpd1_0 */
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD1_0__SHIFT                     1
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD1_0__WIDTH                     1
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD1_0__MASK            0x00000002U
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD1_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000002U) >> 1)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD1_0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 1) & 0x00000002U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD1_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((u_int32_t)(src) <<\
                    1) & 0x00000002U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD1_0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 1) & ~0x00000002U)))
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD1_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((u_int32_t)(1) << 1)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD1_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((u_int32_t)(0) << 1)

/* macros for field paprd_notch_sel_dpd2_0 */
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD2_0__SHIFT                     2
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD2_0__WIDTH                     1
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD2_0__MASK            0x00000004U
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD2_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000004U) >> 2)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD2_0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 2) & 0x00000004U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD2_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((u_int32_t)(src) <<\
                    2) & 0x00000004U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD2_0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 2) & ~0x00000004U)))
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD2_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((u_int32_t)(1) << 2)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD2_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((u_int32_t)(0) << 2)

/* macros for field paprd_notch_sel_dpd3_0 */
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD3_0__SHIFT                     3
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD3_0__WIDTH                     1
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD3_0__MASK            0x00000008U
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD3_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000008U) >> 3)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD3_0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 3) & 0x00000008U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD3_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((u_int32_t)(src) <<\
                    3) & 0x00000008U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD3_0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 3) & ~0x00000008U)))
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD3_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((u_int32_t)(1) << 3)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD3_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((u_int32_t)(0) << 3)

/* macros for field paprd_notch_sel_dpd4_0 */
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD4_0__SHIFT                     4
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD4_0__WIDTH                     1
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD4_0__MASK            0x00000010U
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD4_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000010U) >> 4)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD4_0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 4) & 0x00000010U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD4_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((u_int32_t)(src) <<\
                    4) & 0x00000010U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD4_0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 4) & ~0x00000010U)))
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD4_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((u_int32_t)(1) << 4)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD4_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((u_int32_t)(0) << 4)

/* macros for field paprd_notch_sel_dpd5_0 */
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD5_0__SHIFT                     5
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD5_0__WIDTH                     1
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD5_0__MASK            0x00000020U
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD5_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000020U) >> 5)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD5_0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 5) & 0x00000020U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD5_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((u_int32_t)(src) <<\
                    5) & 0x00000020U)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD5_0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 5) & ~0x00000020U)))
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD5_0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((u_int32_t)(1) << 5)
#define TX_NOTCH_DPD_EN_B0__PAPRD_NOTCH_SEL_DPD5_0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((u_int32_t)(0) << 5)
#define TX_NOTCH_DPD_EN_B0__TYPE                                      u_int32_t
#define TX_NOTCH_DPD_EN_B0__READ                                    0x0000003fU
#define TX_NOTCH_DPD_EN_B0__WRITE                                   0x0000003fU

#endif /* __TX_NOTCH_DPD_EN_B0_MACRO__ */


/* macros for chn_table_map.BB_tx_notch_dpd_en_b0 */
#define INST_CHN_TABLE_MAP__BB_TX_NOTCH_DPD_EN_B0__NUM                        1

/* macros for BlueprintGlobalNameSpace::tx_plybck_ctrl_0_b0 */
#ifndef __TX_PLYBCK_CTRL_0_B0_MACRO__
#define __TX_PLYBCK_CTRL_0_B0_MACRO__

/* macros for field tx_plybck_enable */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__SHIFT                          0
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__WIDTH                          1
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__MASK                 0x00000001U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000001U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000001U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((u_int32_t)(src) &\
                    0x00000001U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000001U)))
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(1)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(0)

/* macros for field tx_plybck_s2_write */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_S2_WRITE__SHIFT                        1
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_S2_WRITE__WIDTH                        1
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_S2_WRITE__MASK               0x00000002U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_S2_WRITE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000002U) >> 1)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_S2_WRITE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 1) & 0x00000002U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_S2_WRITE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((u_int32_t)(src) <<\
                    1) & 0x00000002U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_S2_WRITE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 1) & ~0x00000002U)))
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_S2_WRITE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((u_int32_t)(1) << 1)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_S2_WRITE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((u_int32_t)(0) << 1)

/* macros for field tx_plybck_rd_mode */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_RD_MODE__SHIFT                         2
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_RD_MODE__WIDTH                         2
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_RD_MODE__MASK                0x0000000cU
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_RD_MODE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000000cU) >> 2)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_RD_MODE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 2) & 0x0000000cU)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_RD_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((u_int32_t)(src) <<\
                    2) & 0x0000000cU)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_RD_MODE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 2) & ~0x0000000cU)))

/* macros for field tx_plybck_dpd_train */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_DPD_TRAIN__SHIFT                       4
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_DPD_TRAIN__WIDTH                       1
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_DPD_TRAIN__MASK              0x00000010U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_DPD_TRAIN__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000010U) >> 4)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_DPD_TRAIN__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 4) & 0x00000010U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_DPD_TRAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((u_int32_t)(src) <<\
                    4) & 0x00000010U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_DPD_TRAIN__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 4) & ~0x00000010U)))
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_DPD_TRAIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((u_int32_t)(1) << 4)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_DPD_TRAIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((u_int32_t)(0) << 4)

/* macros for field tx_plybck_sw_start */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_START__SHIFT                        5
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_START__WIDTH                        1
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_START__MASK               0x00000020U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_START__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000020U) >> 5)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_START__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 5) & 0x00000020U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_START__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((u_int32_t)(src) <<\
                    5) & 0x00000020U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_START__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 5) & ~0x00000020U)))
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_START__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((u_int32_t)(1) << 5)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_START__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((u_int32_t)(0) << 5)

/* macros for field tx_plybck_mix_disable */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_MIX_DISABLE__SHIFT                     6
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_MIX_DISABLE__WIDTH                     1
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_MIX_DISABLE__MASK            0x00000040U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_MIX_DISABLE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000040U) >> 6)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_MIX_DISABLE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000040U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_MIX_DISABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((u_int32_t)(src) <<\
                    6) & 0x00000040U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_MIX_DISABLE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000040U)))
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_MIX_DISABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((u_int32_t)(1) << 6)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_MIX_DISABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((u_int32_t)(0) << 6)

/* macros for field tx_plybck_start_addr */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__SHIFT                      8
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__WIDTH                      8
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__MASK             0x0000ff00U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x0000ff00U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((u_int32_t)(src) <<\
                    8) & 0x0000ff00U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x0000ff00U)))

/* macros for field tx_plybck_nsamples */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__SHIFT                       16
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__WIDTH                       16
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__MASK               0xffff0000U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__READ(src) \
                    (((u_int32_t)(src)\
                    & 0xffff0000U) >> 16)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0xffff0000U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((u_int32_t)(src) <<\
                    16) & 0xffff0000U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define TX_PLYBCK_CTRL_0_B0__TYPE                                     u_int32_t
#define TX_PLYBCK_CTRL_0_B0__READ                                   0xffffff7fU
#define TX_PLYBCK_CTRL_0_B0__WRITE                                  0xffffff7fU

#endif /* __TX_PLYBCK_CTRL_0_B0_MACRO__ */


/* macros for chn_table_map.BB_tx_plybck_ctrl_0_b0 */
#define INST_CHN_TABLE_MAP__BB_TX_PLYBCK_CTRL_0_B0__NUM                       1

/* macros for BlueprintGlobalNameSpace::tx_plybck_ctrl_1_b0 */
#ifndef __TX_PLYBCK_CTRL_1_B0_MACRO__
#define __TX_PLYBCK_CTRL_1_B0_MACRO__

/* macros for field tx_plybck_start_delay */
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_START_DELAY__SHIFT                     0
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_START_DELAY__WIDTH                     8
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_START_DELAY__MASK            0x000000ffU
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_START_DELAY__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000000ffU
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_START_DELAY__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000000ffU)
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_START_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((u_int32_t)(src) &\
                    0x000000ffU)
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_START_DELAY__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000000ffU)))
#define TX_PLYBCK_CTRL_1_B0__TYPE                                     u_int32_t
#define TX_PLYBCK_CTRL_1_B0__READ                                   0x000000ffU
#define TX_PLYBCK_CTRL_1_B0__WRITE                                  0x000000ffU

#endif /* __TX_PLYBCK_CTRL_1_B0_MACRO__ */


/* macros for chn_table_map.BB_tx_plybck_ctrl_1_b0 */
#define INST_CHN_TABLE_MAP__BB_TX_PLYBCK_CTRL_1_B0__NUM                       1

/* macros for BlueprintGlobalNameSpace::ibfcal_cntl */
#ifndef __IBFCAL_CNTL_MACRO__
#define __IBFCAL_CNTL_MACRO__

/* macros for field cf_ibfcal_min_loopback_del */
#define IBFCAL_CNTL__CF_IBFCAL_MIN_LOOPBACK_DEL__SHIFT                        0
#define IBFCAL_CNTL__CF_IBFCAL_MIN_LOOPBACK_DEL__WIDTH                        5
#define IBFCAL_CNTL__CF_IBFCAL_MIN_LOOPBACK_DEL__MASK               0x0000001fU
#define IBFCAL_CNTL__CF_IBFCAL_MIN_LOOPBACK_DEL__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000001fU
#define IBFCAL_CNTL__CF_IBFCAL_MIN_LOOPBACK_DEL__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000001fU)
#define IBFCAL_CNTL__CF_IBFCAL_MIN_LOOPBACK_DEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((u_int32_t)(src) &\
                    0x0000001fU)
#define IBFCAL_CNTL__CF_IBFCAL_MIN_LOOPBACK_DEL__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000001fU)))

/* macros for field cf_ibfcal_num_corr_stages */
#define IBFCAL_CNTL__CF_IBFCAL_NUM_CORR_STAGES__SHIFT                         5
#define IBFCAL_CNTL__CF_IBFCAL_NUM_CORR_STAGES__WIDTH                         3
#define IBFCAL_CNTL__CF_IBFCAL_NUM_CORR_STAGES__MASK                0x000000e0U
#define IBFCAL_CNTL__CF_IBFCAL_NUM_CORR_STAGES__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000000e0U) >> 5)
#define IBFCAL_CNTL__CF_IBFCAL_NUM_CORR_STAGES__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 5) & 0x000000e0U)
#define IBFCAL_CNTL__CF_IBFCAL_NUM_CORR_STAGES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000e0U) | (((u_int32_t)(src) <<\
                    5) & 0x000000e0U)
#define IBFCAL_CNTL__CF_IBFCAL_NUM_CORR_STAGES__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 5) & ~0x000000e0U)))

/* macros for field cf_ibfcal_corr_len */
#define IBFCAL_CNTL__CF_IBFCAL_CORR_LEN__SHIFT                                8
#define IBFCAL_CNTL__CF_IBFCAL_CORR_LEN__WIDTH                                4
#define IBFCAL_CNTL__CF_IBFCAL_CORR_LEN__MASK                       0x00000f00U
#define IBFCAL_CNTL__CF_IBFCAL_CORR_LEN__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000f00U) >> 8)
#define IBFCAL_CNTL__CF_IBFCAL_CORR_LEN__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x00000f00U)
#define IBFCAL_CNTL__CF_IBFCAL_CORR_LEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((u_int32_t)(src) <<\
                    8) & 0x00000f00U)
#define IBFCAL_CNTL__CF_IBFCAL_CORR_LEN__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field cf_ibfcal_corr_start_idx */
#define IBFCAL_CNTL__CF_IBFCAL_CORR_START_IDX__SHIFT                         12
#define IBFCAL_CNTL__CF_IBFCAL_CORR_START_IDX__WIDTH                          7
#define IBFCAL_CNTL__CF_IBFCAL_CORR_START_IDX__MASK                 0x0007f000U
#define IBFCAL_CNTL__CF_IBFCAL_CORR_START_IDX__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0007f000U) >> 12)
#define IBFCAL_CNTL__CF_IBFCAL_CORR_START_IDX__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0007f000U)
#define IBFCAL_CNTL__CF_IBFCAL_CORR_START_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0007f000U)
#define IBFCAL_CNTL__CF_IBFCAL_CORR_START_IDX__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0007f000U)))

/* macros for field cf_ibfcal_force_idx_en */
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_EN__SHIFT                           19
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_EN__WIDTH                            1
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_EN__MASK                   0x00080000U
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_EN__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00080000U) >> 19)
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_EN__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 19) & 0x00080000U)
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((u_int32_t)(src) <<\
                    19) & 0x00080000U)
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_EN__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 19) & ~0x00080000U)))
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((u_int32_t)(1) << 19)
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((u_int32_t)(0) << 19)

/* macros for field cf_ibfcal_force_idx_val */
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_VAL__SHIFT                          20
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_VAL__WIDTH                           5
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_VAL__MASK                  0x01f00000U
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_VAL__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x01f00000U) >> 20)
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_VAL__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x01f00000U)
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((u_int32_t)(src) <<\
                    20) & 0x01f00000U)
#define IBFCAL_CNTL__CF_IBFCAL_FORCE_IDX_VAL__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x01f00000U)))
#define IBFCAL_CNTL__TYPE                                             u_int32_t
#define IBFCAL_CNTL__READ                                           0x01ffffffU
#define IBFCAL_CNTL__WRITE                                          0x01ffffffU

#endif /* __IBFCAL_CNTL_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_cntl */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_CNTL__NUM                               1

/* macros for BlueprintGlobalNameSpace::ibfcal_stat_step1 */
#ifndef __IBFCAL_STAT_STEP1_MACRO__
#define __IBFCAL_STAT_STEP1_MACRO__

/* macros for field ibfcal_step1_done */
#define IBFCAL_STAT_STEP1__IBFCAL_STEP1_DONE__SHIFT                           0
#define IBFCAL_STAT_STEP1__IBFCAL_STEP1_DONE__WIDTH                           1
#define IBFCAL_STAT_STEP1__IBFCAL_STEP1_DONE__MASK                  0x00000001U
#define IBFCAL_STAT_STEP1__IBFCAL_STEP1_DONE__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000001U
#define IBFCAL_STAT_STEP1__IBFCAL_STEP1_DONE__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000001U)
#define IBFCAL_STAT_STEP1__IBFCAL_STEP1_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((u_int32_t)(src) &\
                    0x00000001U)
#define IBFCAL_STAT_STEP1__IBFCAL_STEP1_DONE__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000001U)))
#define IBFCAL_STAT_STEP1__IBFCAL_STEP1_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(1)
#define IBFCAL_STAT_STEP1__IBFCAL_STEP1_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(0)

/* macros for field ibfcal_phase_meas_step1 */
#define IBFCAL_STAT_STEP1__IBFCAL_PHASE_MEAS_STEP1__SHIFT                     1
#define IBFCAL_STAT_STEP1__IBFCAL_PHASE_MEAS_STEP1__WIDTH                    11
#define IBFCAL_STAT_STEP1__IBFCAL_PHASE_MEAS_STEP1__MASK            0x00000ffeU
#define IBFCAL_STAT_STEP1__IBFCAL_PHASE_MEAS_STEP1__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000ffeU) >> 1)

/* macros for field ibfcal_rx_gain_setting_step1 */
#define IBFCAL_STAT_STEP1__IBFCAL_RX_GAIN_SETTING_STEP1__SHIFT               12
#define IBFCAL_STAT_STEP1__IBFCAL_RX_GAIN_SETTING_STEP1__WIDTH                8
#define IBFCAL_STAT_STEP1__IBFCAL_RX_GAIN_SETTING_STEP1__MASK       0x000ff000U
#define IBFCAL_STAT_STEP1__IBFCAL_RX_GAIN_SETTING_STEP1__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ff000U) >> 12)
#define IBFCAL_STAT_STEP1__TYPE                                       u_int32_t
#define IBFCAL_STAT_STEP1__READ                                     0x000fffffU
#define IBFCAL_STAT_STEP1__WRITE                                    0x000fffffU

#endif /* __IBFCAL_STAT_STEP1_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_stat_step1 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_STAT_STEP1__NUM                         1

/* macros for BlueprintGlobalNameSpace::ibfcal_stat_step2 */
#ifndef __IBFCAL_STAT_STEP2_MACRO__
#define __IBFCAL_STAT_STEP2_MACRO__

/* macros for field ibfcal_step2_done */
#define IBFCAL_STAT_STEP2__IBFCAL_STEP2_DONE__SHIFT                           0
#define IBFCAL_STAT_STEP2__IBFCAL_STEP2_DONE__WIDTH                           1
#define IBFCAL_STAT_STEP2__IBFCAL_STEP2_DONE__MASK                  0x00000001U
#define IBFCAL_STAT_STEP2__IBFCAL_STEP2_DONE__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000001U
#define IBFCAL_STAT_STEP2__IBFCAL_STEP2_DONE__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000001U)
#define IBFCAL_STAT_STEP2__IBFCAL_STEP2_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((u_int32_t)(src) &\
                    0x00000001U)
#define IBFCAL_STAT_STEP2__IBFCAL_STEP2_DONE__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000001U)))
#define IBFCAL_STAT_STEP2__IBFCAL_STEP2_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(1)
#define IBFCAL_STAT_STEP2__IBFCAL_STEP2_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(0)

/* macros for field ibfcal_phase_meas_step2 */
#define IBFCAL_STAT_STEP2__IBFCAL_PHASE_MEAS_STEP2__SHIFT                     1
#define IBFCAL_STAT_STEP2__IBFCAL_PHASE_MEAS_STEP2__WIDTH                    11
#define IBFCAL_STAT_STEP2__IBFCAL_PHASE_MEAS_STEP2__MASK            0x00000ffeU
#define IBFCAL_STAT_STEP2__IBFCAL_PHASE_MEAS_STEP2__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000ffeU) >> 1)

/* macros for field ibfcal_rx_gain_setting_step2 */
#define IBFCAL_STAT_STEP2__IBFCAL_RX_GAIN_SETTING_STEP2__SHIFT               12
#define IBFCAL_STAT_STEP2__IBFCAL_RX_GAIN_SETTING_STEP2__WIDTH                8
#define IBFCAL_STAT_STEP2__IBFCAL_RX_GAIN_SETTING_STEP2__MASK       0x000ff000U
#define IBFCAL_STAT_STEP2__IBFCAL_RX_GAIN_SETTING_STEP2__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ff000U) >> 12)
#define IBFCAL_STAT_STEP2__TYPE                                       u_int32_t
#define IBFCAL_STAT_STEP2__READ                                     0x000fffffU
#define IBFCAL_STAT_STEP2__WRITE                                    0x000fffffU

#endif /* __IBFCAL_STAT_STEP2_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_stat_step2 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_STAT_STEP2__NUM                         1

/* macros for BlueprintGlobalNameSpace::ibfcal_stat_step3 */
#ifndef __IBFCAL_STAT_STEP3_MACRO__
#define __IBFCAL_STAT_STEP3_MACRO__

/* macros for field ibfcal_step3_done */
#define IBFCAL_STAT_STEP3__IBFCAL_STEP3_DONE__SHIFT                           0
#define IBFCAL_STAT_STEP3__IBFCAL_STEP3_DONE__WIDTH                           1
#define IBFCAL_STAT_STEP3__IBFCAL_STEP3_DONE__MASK                  0x00000001U
#define IBFCAL_STAT_STEP3__IBFCAL_STEP3_DONE__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000001U
#define IBFCAL_STAT_STEP3__IBFCAL_STEP3_DONE__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000001U)
#define IBFCAL_STAT_STEP3__IBFCAL_STEP3_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((u_int32_t)(src) &\
                    0x00000001U)
#define IBFCAL_STAT_STEP3__IBFCAL_STEP3_DONE__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000001U)))
#define IBFCAL_STAT_STEP3__IBFCAL_STEP3_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(1)
#define IBFCAL_STAT_STEP3__IBFCAL_STEP3_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(0)

/* macros for field ibfcal_phase_meas_step3 */
#define IBFCAL_STAT_STEP3__IBFCAL_PHASE_MEAS_STEP3__SHIFT                     1
#define IBFCAL_STAT_STEP3__IBFCAL_PHASE_MEAS_STEP3__WIDTH                    11
#define IBFCAL_STAT_STEP3__IBFCAL_PHASE_MEAS_STEP3__MASK            0x00000ffeU
#define IBFCAL_STAT_STEP3__IBFCAL_PHASE_MEAS_STEP3__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000ffeU) >> 1)

/* macros for field ibfcal_rx_gain_setting_step3 */
#define IBFCAL_STAT_STEP3__IBFCAL_RX_GAIN_SETTING_STEP3__SHIFT               12
#define IBFCAL_STAT_STEP3__IBFCAL_RX_GAIN_SETTING_STEP3__WIDTH                8
#define IBFCAL_STAT_STEP3__IBFCAL_RX_GAIN_SETTING_STEP3__MASK       0x000ff000U
#define IBFCAL_STAT_STEP3__IBFCAL_RX_GAIN_SETTING_STEP3__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ff000U) >> 12)
#define IBFCAL_STAT_STEP3__TYPE                                       u_int32_t
#define IBFCAL_STAT_STEP3__READ                                     0x000fffffU
#define IBFCAL_STAT_STEP3__WRITE                                    0x000fffffU

#endif /* __IBFCAL_STAT_STEP3_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_stat_step3 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_STAT_STEP3__NUM                         1

/* macros for BlueprintGlobalNameSpace::ibfcal_stat_step4 */
#ifndef __IBFCAL_STAT_STEP4_MACRO__
#define __IBFCAL_STAT_STEP4_MACRO__

/* macros for field ibfcal_step4_done */
#define IBFCAL_STAT_STEP4__IBFCAL_STEP4_DONE__SHIFT                           0
#define IBFCAL_STAT_STEP4__IBFCAL_STEP4_DONE__WIDTH                           1
#define IBFCAL_STAT_STEP4__IBFCAL_STEP4_DONE__MASK                  0x00000001U
#define IBFCAL_STAT_STEP4__IBFCAL_STEP4_DONE__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000001U
#define IBFCAL_STAT_STEP4__IBFCAL_STEP4_DONE__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000001U)
#define IBFCAL_STAT_STEP4__IBFCAL_STEP4_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((u_int32_t)(src) &\
                    0x00000001U)
#define IBFCAL_STAT_STEP4__IBFCAL_STEP4_DONE__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000001U)))
#define IBFCAL_STAT_STEP4__IBFCAL_STEP4_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(1)
#define IBFCAL_STAT_STEP4__IBFCAL_STEP4_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(0)

/* macros for field ibfcal_phase_meas_step4 */
#define IBFCAL_STAT_STEP4__IBFCAL_PHASE_MEAS_STEP4__SHIFT                     1
#define IBFCAL_STAT_STEP4__IBFCAL_PHASE_MEAS_STEP4__WIDTH                    11
#define IBFCAL_STAT_STEP4__IBFCAL_PHASE_MEAS_STEP4__MASK            0x00000ffeU
#define IBFCAL_STAT_STEP4__IBFCAL_PHASE_MEAS_STEP4__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000ffeU) >> 1)

/* macros for field ibfcal_rx_gain_setting_step4 */
#define IBFCAL_STAT_STEP4__IBFCAL_RX_GAIN_SETTING_STEP4__SHIFT               12
#define IBFCAL_STAT_STEP4__IBFCAL_RX_GAIN_SETTING_STEP4__WIDTH                8
#define IBFCAL_STAT_STEP4__IBFCAL_RX_GAIN_SETTING_STEP4__MASK       0x000ff000U
#define IBFCAL_STAT_STEP4__IBFCAL_RX_GAIN_SETTING_STEP4__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ff000U) >> 12)
#define IBFCAL_STAT_STEP4__TYPE                                       u_int32_t
#define IBFCAL_STAT_STEP4__READ                                     0x000fffffU
#define IBFCAL_STAT_STEP4__WRITE                                    0x000fffffU

#endif /* __IBFCAL_STAT_STEP4_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_stat_step4 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_STAT_STEP4__NUM                         1

/* macros for BlueprintGlobalNameSpace::ibfcal_stat_step5 */
#ifndef __IBFCAL_STAT_STEP5_MACRO__
#define __IBFCAL_STAT_STEP5_MACRO__

/* macros for field ibfcal_step5_done */
#define IBFCAL_STAT_STEP5__IBFCAL_STEP5_DONE__SHIFT                           0
#define IBFCAL_STAT_STEP5__IBFCAL_STEP5_DONE__WIDTH                           1
#define IBFCAL_STAT_STEP5__IBFCAL_STEP5_DONE__MASK                  0x00000001U
#define IBFCAL_STAT_STEP5__IBFCAL_STEP5_DONE__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000001U
#define IBFCAL_STAT_STEP5__IBFCAL_STEP5_DONE__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000001U)
#define IBFCAL_STAT_STEP5__IBFCAL_STEP5_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((u_int32_t)(src) &\
                    0x00000001U)
#define IBFCAL_STAT_STEP5__IBFCAL_STEP5_DONE__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000001U)))
#define IBFCAL_STAT_STEP5__IBFCAL_STEP5_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(1)
#define IBFCAL_STAT_STEP5__IBFCAL_STEP5_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(0)

/* macros for field ibfcal_phase_meas_step5 */
#define IBFCAL_STAT_STEP5__IBFCAL_PHASE_MEAS_STEP5__SHIFT                     1
#define IBFCAL_STAT_STEP5__IBFCAL_PHASE_MEAS_STEP5__WIDTH                    11
#define IBFCAL_STAT_STEP5__IBFCAL_PHASE_MEAS_STEP5__MASK            0x00000ffeU
#define IBFCAL_STAT_STEP5__IBFCAL_PHASE_MEAS_STEP5__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000ffeU) >> 1)

/* macros for field ibfcal_rx_gain_setting_step5 */
#define IBFCAL_STAT_STEP5__IBFCAL_RX_GAIN_SETTING_STEP5__SHIFT               12
#define IBFCAL_STAT_STEP5__IBFCAL_RX_GAIN_SETTING_STEP5__WIDTH                8
#define IBFCAL_STAT_STEP5__IBFCAL_RX_GAIN_SETTING_STEP5__MASK       0x000ff000U
#define IBFCAL_STAT_STEP5__IBFCAL_RX_GAIN_SETTING_STEP5__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ff000U) >> 12)
#define IBFCAL_STAT_STEP5__TYPE                                       u_int32_t
#define IBFCAL_STAT_STEP5__READ                                     0x000fffffU
#define IBFCAL_STAT_STEP5__WRITE                                    0x000fffffU

#endif /* __IBFCAL_STAT_STEP5_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_stat_step5 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_STAT_STEP5__NUM                         1

/* macros for BlueprintGlobalNameSpace::ibfcal_stat_step6 */
#ifndef __IBFCAL_STAT_STEP6_MACRO__
#define __IBFCAL_STAT_STEP6_MACRO__

/* macros for field ibfcal_step6_done */
#define IBFCAL_STAT_STEP6__IBFCAL_STEP6_DONE__SHIFT                           0
#define IBFCAL_STAT_STEP6__IBFCAL_STEP6_DONE__WIDTH                           1
#define IBFCAL_STAT_STEP6__IBFCAL_STEP6_DONE__MASK                  0x00000001U
#define IBFCAL_STAT_STEP6__IBFCAL_STEP6_DONE__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000001U
#define IBFCAL_STAT_STEP6__IBFCAL_STEP6_DONE__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000001U)
#define IBFCAL_STAT_STEP6__IBFCAL_STEP6_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((u_int32_t)(src) &\
                    0x00000001U)
#define IBFCAL_STAT_STEP6__IBFCAL_STEP6_DONE__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000001U)))
#define IBFCAL_STAT_STEP6__IBFCAL_STEP6_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(1)
#define IBFCAL_STAT_STEP6__IBFCAL_STEP6_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(0)

/* macros for field ibfcal_phase_meas_step6 */
#define IBFCAL_STAT_STEP6__IBFCAL_PHASE_MEAS_STEP6__SHIFT                     1
#define IBFCAL_STAT_STEP6__IBFCAL_PHASE_MEAS_STEP6__WIDTH                    11
#define IBFCAL_STAT_STEP6__IBFCAL_PHASE_MEAS_STEP6__MASK            0x00000ffeU
#define IBFCAL_STAT_STEP6__IBFCAL_PHASE_MEAS_STEP6__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000ffeU) >> 1)

/* macros for field ibfcal_rx_gain_setting_step6 */
#define IBFCAL_STAT_STEP6__IBFCAL_RX_GAIN_SETTING_STEP6__SHIFT               12
#define IBFCAL_STAT_STEP6__IBFCAL_RX_GAIN_SETTING_STEP6__WIDTH                8
#define IBFCAL_STAT_STEP6__IBFCAL_RX_GAIN_SETTING_STEP6__MASK       0x000ff000U
#define IBFCAL_STAT_STEP6__IBFCAL_RX_GAIN_SETTING_STEP6__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ff000U) >> 12)
#define IBFCAL_STAT_STEP6__TYPE                                       u_int32_t
#define IBFCAL_STAT_STEP6__READ                                     0x000fffffU
#define IBFCAL_STAT_STEP6__WRITE                                    0x000fffffU

#endif /* __IBFCAL_STAT_STEP6_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_stat_step6 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_STAT_STEP6__NUM                         1

/* macros for BlueprintGlobalNameSpace::ibfcal_phasecorrection_chn0 */
#ifndef __IBFCAL_PHASECORRECTION_CHN0_MACRO__
#define __IBFCAL_PHASECORRECTION_CHN0_MACRO__

/* macros for field ibfcal_phasecorr_pre_comp_i_0 */
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_I_0__SHIFT     0
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_I_0__WIDTH     8
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_I_0__MASK \
                    0x000000ffU
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_I_0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000000ffU
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_I_0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000000ffU)
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_I_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((u_int32_t)(src) &\
                    0x000000ffU)
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_I_0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000000ffU)))

/* macros for field ibfcal_phasecorr_pre_comp_q_0 */
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_Q_0__SHIFT     8
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_Q_0__WIDTH     8
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_Q_0__MASK \
                    0x0000ff00U
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_Q_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_Q_0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x0000ff00U)
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_Q_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((u_int32_t)(src) <<\
                    8) & 0x0000ff00U)
#define IBFCAL_PHASECORRECTION_CHN0__IBFCAL_PHASECORR_PRE_COMP_Q_0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define IBFCAL_PHASECORRECTION_CHN0__TYPE                             u_int32_t
#define IBFCAL_PHASECORRECTION_CHN0__READ                           0x0000ffffU
#define IBFCAL_PHASECORRECTION_CHN0__WRITE                          0x0000ffffU

#endif /* __IBFCAL_PHASECORRECTION_CHN0_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_phasecorrection_chn0 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_PHASECORRECTION_CHN0__NUM               1

/* macros for BlueprintGlobalNameSpace::ibfcal_rffe_comp_g0_chn0 */
#ifndef __IBFCAL_RFFE_COMP_G0_CHN0_MACRO__
#define __IBFCAL_RFFE_COMP_G0_CHN0_MACRO__

/* macros for field ibfcal_comp_rffe_i_g0_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA0_CHN0__SHIFT     0
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA0_CHN0__MASK \
                    0x0000003fU
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA0_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA0_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA0_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field ibfcal_comp_rffe_q_g0_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA0_CHN0__SHIFT     6
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA0_CHN0__MASK \
                    0x00000fc0U
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA0_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA0_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA0_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field ibfcal_comp_rffe_i_g0_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA1_CHN0__SHIFT    12
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA1_CHN0__MASK \
                    0x0003f000U
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_I_G0_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field ibfcal_comp_rffe_q_g0_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA1_CHN0__SHIFT    18
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA1_CHN0__MASK \
                    0x00fc0000U
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G0_CHN0__IBFCAL_COMP_RFFE_Q_G0_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define IBFCAL_RFFE_COMP_G0_CHN0__TYPE                                u_int32_t
#define IBFCAL_RFFE_COMP_G0_CHN0__READ                              0x00ffffffU
#define IBFCAL_RFFE_COMP_G0_CHN0__WRITE                             0x00ffffffU

#endif /* __IBFCAL_RFFE_COMP_G0_CHN0_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_rffe_comp_g0_chn0 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_RFFE_COMP_G0_CHN0__NUM                  1

/* macros for BlueprintGlobalNameSpace::ibfcal_rffe_comp_g1_chn0 */
#ifndef __IBFCAL_RFFE_COMP_G1_CHN0_MACRO__
#define __IBFCAL_RFFE_COMP_G1_CHN0_MACRO__

/* macros for field ibfcal_comp_rffe_i_g1_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA0_CHN0__SHIFT     0
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA0_CHN0__MASK \
                    0x0000003fU
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA0_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA0_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA0_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field ibfcal_comp_rffe_q_g1_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA0_CHN0__SHIFT     6
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA0_CHN0__MASK \
                    0x00000fc0U
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA0_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA0_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA0_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field ibfcal_comp_rffe_i_g1_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA1_CHN0__SHIFT    12
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA1_CHN0__MASK \
                    0x0003f000U
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_I_G1_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field ibfcal_comp_rffe_q_g1_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA1_CHN0__SHIFT    18
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA1_CHN0__MASK \
                    0x00fc0000U
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G1_CHN0__IBFCAL_COMP_RFFE_Q_G1_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define IBFCAL_RFFE_COMP_G1_CHN0__TYPE                                u_int32_t
#define IBFCAL_RFFE_COMP_G1_CHN0__READ                              0x00ffffffU
#define IBFCAL_RFFE_COMP_G1_CHN0__WRITE                             0x00ffffffU

#endif /* __IBFCAL_RFFE_COMP_G1_CHN0_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_rffe_comp_g1_chn0 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_RFFE_COMP_G1_CHN0__NUM                  1

/* macros for BlueprintGlobalNameSpace::ibfcal_rffe_comp_g2_chn0 */
#ifndef __IBFCAL_RFFE_COMP_G2_CHN0_MACRO__
#define __IBFCAL_RFFE_COMP_G2_CHN0_MACRO__

/* macros for field ibfcal_comp_rffe_i_g2_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA0_CHN0__SHIFT     0
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA0_CHN0__MASK \
                    0x0000003fU
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA0_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA0_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA0_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field ibfcal_comp_rffe_q_g2_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA0_CHN0__SHIFT     6
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA0_CHN0__MASK \
                    0x00000fc0U
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA0_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA0_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA0_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field ibfcal_comp_rffe_i_g2_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA1_CHN0__SHIFT    12
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA1_CHN0__MASK \
                    0x0003f000U
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_I_G2_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field ibfcal_comp_rffe_q_g2_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA1_CHN0__SHIFT    18
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA1_CHN0__MASK \
                    0x00fc0000U
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G2_CHN0__IBFCAL_COMP_RFFE_Q_G2_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define IBFCAL_RFFE_COMP_G2_CHN0__TYPE                                u_int32_t
#define IBFCAL_RFFE_COMP_G2_CHN0__READ                              0x00ffffffU
#define IBFCAL_RFFE_COMP_G2_CHN0__WRITE                             0x00ffffffU

#endif /* __IBFCAL_RFFE_COMP_G2_CHN0_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_rffe_comp_g2_chn0 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_RFFE_COMP_G2_CHN0__NUM                  1

/* macros for BlueprintGlobalNameSpace::ibfcal_rffe_comp_g3_chn0 */
#ifndef __IBFCAL_RFFE_COMP_G3_CHN0_MACRO__
#define __IBFCAL_RFFE_COMP_G3_CHN0_MACRO__

/* macros for field ibfcal_comp_rffe_i_g3_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA0_CHN0__SHIFT     0
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA0_CHN0__MASK \
                    0x0000003fU
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA0_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA0_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA0_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field ibfcal_comp_rffe_q_g3_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA0_CHN0__SHIFT     6
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA0_CHN0__MASK \
                    0x00000fc0U
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA0_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA0_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA0_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field ibfcal_comp_rffe_i_g3_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA1_CHN0__SHIFT    12
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA1_CHN0__MASK \
                    0x0003f000U
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_I_G3_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field ibfcal_comp_rffe_q_g3_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA1_CHN0__SHIFT    18
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA1_CHN0__MASK \
                    0x00fc0000U
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G3_CHN0__IBFCAL_COMP_RFFE_Q_G3_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define IBFCAL_RFFE_COMP_G3_CHN0__TYPE                                u_int32_t
#define IBFCAL_RFFE_COMP_G3_CHN0__READ                              0x00ffffffU
#define IBFCAL_RFFE_COMP_G3_CHN0__WRITE                             0x00ffffffU

#endif /* __IBFCAL_RFFE_COMP_G3_CHN0_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_rffe_comp_g3_chn0 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_RFFE_COMP_G3_CHN0__NUM                  1

/* macros for BlueprintGlobalNameSpace::ibfcal_rffe_comp_g4_chn0 */
#ifndef __IBFCAL_RFFE_COMP_G4_CHN0_MACRO__
#define __IBFCAL_RFFE_COMP_G4_CHN0_MACRO__

/* macros for field ibfcal_comp_rffe_i_g4_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA0_CHN0__SHIFT     0
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA0_CHN0__MASK \
                    0x0000003fU
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA0_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA0_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA0_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field ibfcal_comp_rffe_q_g4_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA0_CHN0__SHIFT     6
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA0_CHN0__MASK \
                    0x00000fc0U
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA0_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA0_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA0_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field ibfcal_comp_rffe_i_g4_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA1_CHN0__SHIFT    12
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA1_CHN0__MASK \
                    0x0003f000U
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_I_G4_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field ibfcal_comp_rffe_q_g4_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA1_CHN0__SHIFT    18
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA1_CHN0__MASK \
                    0x00fc0000U
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G4_CHN0__IBFCAL_COMP_RFFE_Q_G4_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define IBFCAL_RFFE_COMP_G4_CHN0__TYPE                                u_int32_t
#define IBFCAL_RFFE_COMP_G4_CHN0__READ                              0x00ffffffU
#define IBFCAL_RFFE_COMP_G4_CHN0__WRITE                             0x00ffffffU

#endif /* __IBFCAL_RFFE_COMP_G4_CHN0_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_rffe_comp_g4_chn0 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_RFFE_COMP_G4_CHN0__NUM                  1

/* macros for BlueprintGlobalNameSpace::ibfcal_rffe_comp_g5_chn0 */
#ifndef __IBFCAL_RFFE_COMP_G5_CHN0_MACRO__
#define __IBFCAL_RFFE_COMP_G5_CHN0_MACRO__

/* macros for field ibfcal_comp_rffe_i_g5_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA0_CHN0__SHIFT     0
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA0_CHN0__MASK \
                    0x0000003fU
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA0_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA0_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA0_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field ibfcal_comp_rffe_q_g5_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA0_CHN0__SHIFT     6
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA0_CHN0__MASK \
                    0x00000fc0U
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA0_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA0_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA0_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field ibfcal_comp_rffe_i_g5_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA1_CHN0__SHIFT    12
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA1_CHN0__MASK \
                    0x0003f000U
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_I_G5_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field ibfcal_comp_rffe_q_g5_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA1_CHN0__SHIFT    18
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA1_CHN0__MASK \
                    0x00fc0000U
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G5_CHN0__IBFCAL_COMP_RFFE_Q_G5_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define IBFCAL_RFFE_COMP_G5_CHN0__TYPE                                u_int32_t
#define IBFCAL_RFFE_COMP_G5_CHN0__READ                              0x00ffffffU
#define IBFCAL_RFFE_COMP_G5_CHN0__WRITE                             0x00ffffffU

#endif /* __IBFCAL_RFFE_COMP_G5_CHN0_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_rffe_comp_g5_chn0 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_RFFE_COMP_G5_CHN0__NUM                  1

/* macros for BlueprintGlobalNameSpace::ibfcal_rffe_comp_g6_chn0 */
#ifndef __IBFCAL_RFFE_COMP_G6_CHN0_MACRO__
#define __IBFCAL_RFFE_COMP_G6_CHN0_MACRO__

/* macros for field ibfcal_comp_rffe_i_g6_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA0_CHN0__SHIFT     0
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA0_CHN0__MASK \
                    0x0000003fU
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA0_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA0_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA0_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field ibfcal_comp_rffe_q_g6_xlna0_chn0 */
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA0_CHN0__SHIFT     6
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA0_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA0_CHN0__MASK \
                    0x00000fc0U
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA0_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA0_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA0_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field ibfcal_comp_rffe_i_g6_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA1_CHN0__SHIFT    12
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA1_CHN0__MASK \
                    0x0003f000U
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_I_G6_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field ibfcal_comp_rffe_q_g6_xlna1_chn0 */
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA1_CHN0__SHIFT    18
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA1_CHN0__WIDTH     6
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA1_CHN0__MASK \
                    0x00fc0000U
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA1_CHN0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA1_CHN0__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define IBFCAL_RFFE_COMP_G6_CHN0__IBFCAL_COMP_RFFE_Q_G6_XLNA1_CHN0__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define IBFCAL_RFFE_COMP_G6_CHN0__TYPE                                u_int32_t
#define IBFCAL_RFFE_COMP_G6_CHN0__READ                              0x00ffffffU
#define IBFCAL_RFFE_COMP_G6_CHN0__WRITE                             0x00ffffffU

#endif /* __IBFCAL_RFFE_COMP_G6_CHN0_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_rffe_comp_g6_chn0 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_RFFE_COMP_G6_CHN0__NUM                  1

/* macros for BlueprintGlobalNameSpace::ibfcal_gm_tia_comp_g1 */
#ifndef __IBFCAL_GM_TIA_COMP_G1_MACRO__
#define __IBFCAL_GM_TIA_COMP_G1_MACRO__

/* macros for field ibfcal_comp_gm_i_g1 */
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_I_G1__SHIFT                     0
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_I_G1__WIDTH                     6
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_I_G1__MASK            0x0000003fU
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_I_G1__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_I_G1__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_I_G1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_I_G1__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field ibfcal_comp_gm_q_g1 */
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_Q_G1__SHIFT                     6
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_Q_G1__WIDTH                     6
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_Q_G1__MASK            0x00000fc0U
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_Q_G1__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_Q_G1__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_Q_G1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_GM_Q_G1__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field ibfcal_comp_tia_i_g1 */
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_I_G1__SHIFT                   12
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_I_G1__WIDTH                    6
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_I_G1__MASK           0x0003f000U
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_I_G1__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_I_G1__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_I_G1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_I_G1__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field ibfcal_comp_tia_q_g1 */
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_Q_G1__SHIFT                   18
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_Q_G1__WIDTH                    6
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_Q_G1__MASK           0x00fc0000U
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_Q_G1__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_Q_G1__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_Q_G1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define IBFCAL_GM_TIA_COMP_G1__IBFCAL_COMP_TIA_Q_G1__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define IBFCAL_GM_TIA_COMP_G1__TYPE                                   u_int32_t
#define IBFCAL_GM_TIA_COMP_G1__READ                                 0x00ffffffU
#define IBFCAL_GM_TIA_COMP_G1__WRITE                                0x00ffffffU

#endif /* __IBFCAL_GM_TIA_COMP_G1_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_gm_tia_comp_g1 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_GM_TIA_COMP_G1__NUM                     1

/* macros for BlueprintGlobalNameSpace::ibfcal_gm_tia_comp_g2 */
#ifndef __IBFCAL_GM_TIA_COMP_G2_MACRO__
#define __IBFCAL_GM_TIA_COMP_G2_MACRO__

/* macros for field ibfcal_comp_gm_i_g2 */
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_I_G2__SHIFT                     0
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_I_G2__WIDTH                     6
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_I_G2__MASK            0x0000003fU
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_I_G2__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_I_G2__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_I_G2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_I_G2__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field ibfcal_comp_gm_q_g2 */
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_Q_G2__SHIFT                     6
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_Q_G2__WIDTH                     6
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_Q_G2__MASK            0x00000fc0U
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_Q_G2__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_Q_G2__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_Q_G2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_GM_Q_G2__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field ibfcal_comp_tia_i_g2 */
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_I_G2__SHIFT                   12
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_I_G2__WIDTH                    6
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_I_G2__MASK           0x0003f000U
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_I_G2__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_I_G2__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_I_G2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_I_G2__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field ibfcal_comp_tia_q_g2 */
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_Q_G2__SHIFT                   18
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_Q_G2__WIDTH                    6
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_Q_G2__MASK           0x00fc0000U
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_Q_G2__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_Q_G2__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_Q_G2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define IBFCAL_GM_TIA_COMP_G2__IBFCAL_COMP_TIA_Q_G2__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define IBFCAL_GM_TIA_COMP_G2__TYPE                                   u_int32_t
#define IBFCAL_GM_TIA_COMP_G2__READ                                 0x00ffffffU
#define IBFCAL_GM_TIA_COMP_G2__WRITE                                0x00ffffffU

#endif /* __IBFCAL_GM_TIA_COMP_G2_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_gm_tia_comp_g2 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_GM_TIA_COMP_G2__NUM                     1

/* macros for BlueprintGlobalNameSpace::ibfcal_gm_tia_comp_g3 */
#ifndef __IBFCAL_GM_TIA_COMP_G3_MACRO__
#define __IBFCAL_GM_TIA_COMP_G3_MACRO__

/* macros for field ibfcal_comp_gm_i_g3 */
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_I_G3__SHIFT                     0
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_I_G3__WIDTH                     6
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_I_G3__MASK            0x0000003fU
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_I_G3__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_I_G3__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_I_G3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_I_G3__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field ibfcal_comp_gm_q_g3 */
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_Q_G3__SHIFT                     6
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_Q_G3__WIDTH                     6
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_Q_G3__MASK            0x00000fc0U
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_Q_G3__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_Q_G3__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_Q_G3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_GM_Q_G3__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field ibfcal_comp_tia_i_g3 */
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_I_G3__SHIFT                   12
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_I_G3__WIDTH                    6
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_I_G3__MASK           0x0003f000U
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_I_G3__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_I_G3__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_I_G3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_I_G3__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field ibfcal_comp_tia_q_g3 */
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_Q_G3__SHIFT                   18
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_Q_G3__WIDTH                    6
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_Q_G3__MASK           0x00fc0000U
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_Q_G3__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_Q_G3__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 18) & 0x00fc0000U)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_Q_G3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((u_int32_t)(src) <<\
                    18) & 0x00fc0000U)
#define IBFCAL_GM_TIA_COMP_G3__IBFCAL_COMP_TIA_Q_G3__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define IBFCAL_GM_TIA_COMP_G3__TYPE                                   u_int32_t
#define IBFCAL_GM_TIA_COMP_G3__READ                                 0x00ffffffU
#define IBFCAL_GM_TIA_COMP_G3__WRITE                                0x00ffffffU

#endif /* __IBFCAL_GM_TIA_COMP_G3_MACRO__ */


/* macros for chn_table_map.BB_ibfcal_gm_tia_comp_g3 */
#define INST_CHN_TABLE_MAP__BB_IBFCAL_GM_TIA_COMP_G3__NUM                     1

/* macros for BlueprintGlobalNameSpace::normrx_rxiq_corr_coeff_b0 */
#ifndef __NORMRX_RXIQ_CORR_COEFF_B0_MACRO__
#define __NORMRX_RXIQ_CORR_COEFF_B0_MACRO__

/* macros for field normrx_iqc_coeff_table_chn0 */
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__SHIFT         0
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__WIDTH        18
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__MASK \
                    0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0003ffffU)
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((u_int32_t)(src) &\
                    0x0003ffffU)
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0003ffffU)))
#define NORMRX_RXIQ_CORR_COEFF_B0__TYPE                               u_int32_t
#define NORMRX_RXIQ_CORR_COEFF_B0__READ                             0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B0__WRITE                            0x0003ffffU

#endif /* __NORMRX_RXIQ_CORR_COEFF_B0_MACRO__ */


/* macros for chn_table_map.BB_normrx_rxiq_corr_coeff_b0 */
#define INST_CHN_TABLE_MAP__BB_NORMRX_RXIQ_CORR_COEFF_B0__NUM               160

/* macros for BlueprintGlobalNameSpace::paprd_mem_tab_b0 */
#ifndef __PAPRD_MEM_TAB_B0_MACRO__
#define __PAPRD_MEM_TAB_B0_MACRO__

/* macros for field paprd_mem */
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__SHIFT                                    0
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__WIDTH                                   24
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__MASK                           0x00ffffffU
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__READ(src)   (u_int32_t)(src) & 0x00ffffffU
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00ffffffU)
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ffffffU) | ((u_int32_t)(src) &\
                    0x00ffffffU)
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00ffffffU)))
#define PAPRD_MEM_TAB_B0__TYPE                                        u_int32_t
#define PAPRD_MEM_TAB_B0__READ                                      0x00ffffffU
#define PAPRD_MEM_TAB_B0__WRITE                                     0x00ffffffU

#endif /* __PAPRD_MEM_TAB_B0_MACRO__ */


/* macros for chn_table_map.BB_paprd_mem_tab_b0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_MEM_TAB_B0__NUM                        768

/* macros for BlueprintGlobalNameSpace::paprd_train_adcsat */
#ifndef __PAPRD_TRAIN_ADCSAT_MACRO__
#define __PAPRD_TRAIN_ADCSAT_MACRO__

/* macros for field paprd_adcsat_num_thr */
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_NUM_THR__SHIFT                       0
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_NUM_THR__WIDTH                       6
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_NUM_THR__MASK              0x0000003fU
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_NUM_THR__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_NUM_THR__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_NUM_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_NUM_THR__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field paprd_adcsat_icount */
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_ICOUNT__SHIFT                        6
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_ICOUNT__WIDTH                        6
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_ICOUNT__MASK               0x00000fc0U
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_ICOUNT__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_ICOUNT__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_ICOUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_ICOUNT__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field paprd_adcsat_thrh */
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRH__SHIFT                         12
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRH__WIDTH                          9
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRH__MASK                 0x001ff000U
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRH__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x001ff000U) >> 12)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRH__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x001ff000U)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001ff000U) | (((u_int32_t)(src) <<\
                    12) & 0x001ff000U)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRH__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x001ff000U)))

/* macros for field paprd_adcsat_thrl */
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRL__SHIFT                         21
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRL__WIDTH                          9
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRL__MASK                 0x3fe00000U
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRL__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3fe00000U) >> 21)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRL__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 21) & 0x3fe00000U)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3fe00000U) | (((u_int32_t)(src) <<\
                    21) & 0x3fe00000U)
#define PAPRD_TRAIN_ADCSAT__PAPRD_ADCSAT_THRL__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 21) & ~0x3fe00000U)))
#define PAPRD_TRAIN_ADCSAT__TYPE                                      u_int32_t
#define PAPRD_TRAIN_ADCSAT__READ                                    0x3fffffffU
#define PAPRD_TRAIN_ADCSAT__WRITE                                   0x3fffffffU

#endif /* __PAPRD_TRAIN_ADCSAT_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_adcsat */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_ADCSAT__NUM                        1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_cntl1 */
#ifndef __PAPRD_TRAINER_CNTL1_MACRO__
#define __PAPRD_TRAINER_CNTL1_MACRO__

/* macros for field cf_paprd_train_enable */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__SHIFT                     0
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__WIDTH                     1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__MASK            0x00000001U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000001U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000001U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((u_int32_t)(src) &\
                    0x00000001U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000001U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(1)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(0)

/* macros for field cf_paprd_agc2_settling */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__SHIFT                    1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__WIDTH                    7
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__MASK           0x000000feU
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000000feU) >> 1)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 1) & 0x000000feU)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000feU) | (((u_int32_t)(src) <<\
                    1) & 0x000000feU)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 1) & ~0x000000feU)))

/* macros for field cf_paprd_iqcorr_enable */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__SHIFT                    8
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__WIDTH                    1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__MASK           0x00000100U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000100U) >> 8)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x00000100U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((u_int32_t)(src) <<\
                    8) & 0x00000100U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((u_int32_t)(1) << 8)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((u_int32_t)(0) << 8)

/* macros for field cf_paprd_rx_bb_gain_force */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__SHIFT                 9
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__WIDTH                 1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__MASK        0x00000200U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000200U) >> 9)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 9) & 0x00000200U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((u_int32_t)(src) <<\
                    9) & 0x00000200U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((u_int32_t)(1) << 9)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((u_int32_t)(0) << 9)

/* macros for field cf_paprd_tx_gain_force */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__SHIFT                   10
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__WIDTH                    1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__MASK           0x00000400U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000400U) >> 10)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x00000400U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((u_int32_t)(src) <<\
                    10) & 0x00000400U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((u_int32_t)(1) << 10)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((u_int32_t)(0) << 10)

/* macros for field cf_paprd_dc_corr_enable */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__SHIFT                  11
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__WIDTH                   1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__MASK          0x00000800U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000800U) >> 11)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 11) & 0x00000800U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((u_int32_t)(src) <<\
                    11) & 0x00000800U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((u_int32_t)(1) << 11)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((u_int32_t)(0) << 11)

/* macros for field cf_paprd_adc_shift */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ADC_SHIFT__SHIFT                       12
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ADC_SHIFT__WIDTH                        2
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ADC_SHIFT__MASK               0x00003000U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ADC_SHIFT__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00003000U) >> 12)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ADC_SHIFT__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x00003000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ADC_SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((u_int32_t)(src) <<\
                    12) & 0x00003000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ADC_SHIFT__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x00003000U)))

/* macros for field cf_paprd_corr_force */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__SHIFT                      19
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__WIDTH                       1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__MASK              0x00080000U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00080000U) >> 19)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 19) & 0x00080000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((u_int32_t)(src) <<\
                    19) & 0x00080000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((u_int32_t)(1) << 19)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((u_int32_t)(0) << 19)

/* macros for field cf_paprd_forced_coarse_idx */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__SHIFT               20
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__WIDTH                5
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__MASK       0x01f00000U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x01f00000U) >> 20)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x01f00000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((u_int32_t)(src) <<\
                    20) & 0x01f00000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x01f00000U)))

/* macros for field cf_paprd_forced_fine_idx */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__SHIFT                 25
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__WIDTH                  2
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__MASK         0x06000000U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x06000000U) >> 25)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 25) & 0x06000000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x06000000U) | (((u_int32_t)(src) <<\
                    25) & 0x06000000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 25) & ~0x06000000U)))

/* macros for field cf_paprd_enable_adc_fifo */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ENABLE_ADC_FIFO__SHIFT                 27
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ENABLE_ADC_FIFO__WIDTH                  1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ENABLE_ADC_FIFO__MASK         0x08000000U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ENABLE_ADC_FIFO__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x08000000U) >> 27)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ENABLE_ADC_FIFO__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 27) & 0x08000000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ENABLE_ADC_FIFO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((u_int32_t)(src) <<\
                    27) & 0x08000000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ENABLE_ADC_FIFO__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 27) & ~0x08000000U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ENABLE_ADC_FIFO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((u_int32_t)(1) << 27)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_ENABLE_ADC_FIFO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((u_int32_t)(0) << 27)

/* macros for field cf_paprd_train_mode */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__SHIFT                      31
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__WIDTH                       1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__MASK              0x80000000U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x80000000U) >> 31)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 31) & 0x80000000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((u_int32_t)(src) <<\
                    31) & 0x80000000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((u_int32_t)(1) << 31)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((u_int32_t)(0) << 31)
#define PAPRD_TRAINER_CNTL1__TYPE                                     u_int32_t
#define PAPRD_TRAINER_CNTL1__READ                                   0x8ff83fffU
#define PAPRD_TRAINER_CNTL1__WRITE                                  0x8ff83fffU

#endif /* __PAPRD_TRAINER_CNTL1_MACRO__ */


/* macros for chn_table_map.BB_paprd_trainer_cntl1 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAINER_CNTL1__NUM                       1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_cntl2 */
#ifndef __PAPRD_TRAINER_CNTL2_MACRO__
#define __PAPRD_TRAINER_CNTL2_MACRO__

/* macros for field cf_paprd_init_rx_bb_gain */
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__SHIFT                  0
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__WIDTH                 32
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__MASK         0xffffffffU
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__READ(src) \
                    (u_int32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0xffffffffU)
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((u_int32_t)(src) &\
                    0xffffffffU)
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0xffffffffU)))
#define PAPRD_TRAINER_CNTL2__TYPE                                     u_int32_t
#define PAPRD_TRAINER_CNTL2__READ                                   0xffffffffU
#define PAPRD_TRAINER_CNTL2__WRITE                                  0xffffffffU

#endif /* __PAPRD_TRAINER_CNTL2_MACRO__ */


/* macros for chn_table_map.BB_paprd_trainer_cntl2 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAINER_CNTL2__NUM                       1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_cntl3 */
#ifndef __PAPRD_TRAINER_CNTL3_MACRO__
#define __PAPRD_TRAINER_CNTL3_MACRO__

/* macros for field cf_paprd_quick_drop */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__SHIFT                       6
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__WIDTH                       6
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__MASK              0x00000fc0U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field cf_paprd_min_loopback_del */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__SHIFT                12
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__WIDTH                 5
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__MASK        0x0001f000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0001f000U) >> 12)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0001f000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0001f000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0001f000U)))

/* macros for field cf_paprd_num_corr_stages */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__SHIFT                 17
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__WIDTH                  3
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__MASK         0x000e0000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000e0000U) >> 17)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 17) & 0x000e0000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000e0000U) | (((u_int32_t)(src) <<\
                    17) & 0x000e0000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 17) & ~0x000e0000U)))

/* macros for field cf_paprd_coarse_corr_len */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__SHIFT                 20
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__WIDTH                  4
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__MASK         0x00f00000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00f00000U) >> 20)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x00f00000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((u_int32_t)(src) <<\
                    20) & 0x00f00000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field cf_paprd_fine_corr_len */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__SHIFT                   24
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__WIDTH                    4
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__MASK           0x0f000000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0f000000U) >> 24)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x0f000000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((u_int32_t)(src) <<\
                    24) & 0x0f000000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field cf_paprd_dbg_en */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_DBG_EN__SHIFT                          28
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_DBG_EN__WIDTH                           1
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_DBG_EN__MASK                  0x10000000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_DBG_EN__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x10000000U) >> 28)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_DBG_EN__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 28) & 0x10000000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_DBG_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((u_int32_t)(src) <<\
                    28) & 0x10000000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_DBG_EN__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 28) & ~0x10000000U)))
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_DBG_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((u_int32_t)(1) << 28)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_DBG_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((u_int32_t)(0) << 28)

/* macros for field cf_paprd_bbtxmix_disable */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__SHIFT                 29
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__WIDTH                  1
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__MASK         0x20000000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x20000000U) >> 29)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 29) & 0x20000000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((u_int32_t)(src) <<\
                    29) & 0x20000000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((u_int32_t)(1) << 29)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((u_int32_t)(0) << 29)
#define PAPRD_TRAINER_CNTL3__TYPE                                     u_int32_t
#define PAPRD_TRAINER_CNTL3__READ                                   0x3fffffc0U
#define PAPRD_TRAINER_CNTL3__WRITE                                  0x3fffffc0U

#endif /* __PAPRD_TRAINER_CNTL3_MACRO__ */


/* macros for chn_table_map.BB_paprd_trainer_cntl3 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAINER_CNTL3__NUM                       1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_cntl4 */
#ifndef __PAPRD_TRAINER_CNTL4_MACRO__
#define __PAPRD_TRAINER_CNTL4_MACRO__

/* macros for field cf_paprd_min_corr */
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__SHIFT                         0
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__WIDTH                        12
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__MASK                0x00000fffU
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field cf_paprd_safety_delta */
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__SHIFT                    12
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__WIDTH                     4
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__MASK            0x0000f000U
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000f000U) >> 12)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0000f000U)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0000f000U)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field cf_paprd_num_train_samples */
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__SHIFT               16
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__WIDTH               10
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__MASK       0x03ff0000U
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x03ff0000U)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((u_int32_t)(src) <<\
                    16) & 0x03ff0000U)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x03ff0000U)))

/* macros for field cf_paprd_agc2_max_gain */
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_AGC2_MAX_GAIN__SHIFT                   26
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_AGC2_MAX_GAIN__WIDTH                    6
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_AGC2_MAX_GAIN__MASK           0xfc000000U
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_AGC2_MAX_GAIN__READ(src) \
                    (((u_int32_t)(src)\
                    & 0xfc000000U) >> 26)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_AGC2_MAX_GAIN__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 26) & 0xfc000000U)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_AGC2_MAX_GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfc000000U) | (((u_int32_t)(src) <<\
                    26) & 0xfc000000U)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_AGC2_MAX_GAIN__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 26) & ~0xfc000000U)))
#define PAPRD_TRAINER_CNTL4__TYPE                                     u_int32_t
#define PAPRD_TRAINER_CNTL4__READ                                   0xffffffffU
#define PAPRD_TRAINER_CNTL4__WRITE                                  0xffffffffU

#endif /* __PAPRD_TRAINER_CNTL4_MACRO__ */


/* macros for chn_table_map.BB_paprd_trainer_cntl4 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAINER_CNTL4__NUM                       1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_stat1 */
#ifndef __PAPRD_TRAINER_STAT1_MACRO__
#define __PAPRD_TRAINER_STAT1_MACRO__

/* macros for field paprd_train_done */
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__SHIFT                          0
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__WIDTH                          1
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__MASK                 0x00000001U
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000001U
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000001U)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((u_int32_t)(src) &\
                    0x00000001U)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000001U)))
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(1)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (u_int32_t)(0)

/* macros for field paprd_train_incomplete */
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__SHIFT                    1
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__WIDTH                    1
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__MASK           0x00000002U
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000002U) >> 1)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((u_int32_t)(1) << 1)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((u_int32_t)(0) << 1)

/* macros for field paprd_corr_err */
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__SHIFT                            2
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__WIDTH                            1
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__MASK                   0x00000004U
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000004U) >> 2)
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((u_int32_t)(1) << 2)
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((u_int32_t)(0) << 2)

/* macros for field paprd_train_active */
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__SHIFT                        3
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__WIDTH                        1
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__MASK               0x00000008U
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000008U) >> 3)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((u_int32_t)(1) << 3)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((u_int32_t)(0) << 3)

/* macros for field paprd_rx_gain_idx */
#define PAPRD_TRAINER_STAT1__PAPRD_RX_GAIN_IDX__SHIFT                         4
#define PAPRD_TRAINER_STAT1__PAPRD_RX_GAIN_IDX__WIDTH                         6
#define PAPRD_TRAINER_STAT1__PAPRD_RX_GAIN_IDX__MASK                0x000003f0U
#define PAPRD_TRAINER_STAT1__PAPRD_RX_GAIN_IDX__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000003f0U) >> 4)

/* macros for field paprd_agc2_pwr */
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_PWR__SHIFT                           10
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_PWR__WIDTH                            8
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_PWR__MASK                   0x0003fc00U
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_PWR__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003fc00U) >> 10)

/* macros for field paprd_agc2_sized */
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_SIZED__SHIFT                         18
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_SIZED__WIDTH                          1
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_SIZED__MASK                 0x00040000U
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_SIZED__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00040000U) >> 18)
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_SIZED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((u_int32_t)(1) << 18)
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_SIZED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((u_int32_t)(0) << 18)
#define PAPRD_TRAINER_STAT1__TYPE                                     u_int32_t
#define PAPRD_TRAINER_STAT1__READ                                   0x0007ffffU
#define PAPRD_TRAINER_STAT1__WRITE                                  0x0007ffffU

#endif /* __PAPRD_TRAINER_STAT1_MACRO__ */


/* macros for chn_table_map.BB_paprd_trainer_stat1 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAINER_STAT1__NUM                       1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_stat2 */
#ifndef __PAPRD_TRAINER_STAT2_MACRO__
#define __PAPRD_TRAINER_STAT2_MACRO__

/* macros for field paprd_fine_val */
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_VAL__SHIFT                            0
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_VAL__WIDTH                           16
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_VAL__MASK                   0x0000ffffU
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_VAL__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000ffffU

/* macros for field paprd_coarse_val */
#define PAPRD_TRAINER_STAT2__PAPRD_COARSE_VAL__SHIFT                         16
#define PAPRD_TRAINER_STAT2__PAPRD_COARSE_VAL__WIDTH                         16
#define PAPRD_TRAINER_STAT2__PAPRD_COARSE_VAL__MASK                 0xffff0000U
#define PAPRD_TRAINER_STAT2__PAPRD_COARSE_VAL__READ(src) \
                    (((u_int32_t)(src)\
                    & 0xffff0000U) >> 16)
#define PAPRD_TRAINER_STAT2__TYPE                                     u_int32_t
#define PAPRD_TRAINER_STAT2__READ                                   0xffffffffU

#endif /* __PAPRD_TRAINER_STAT2_MACRO__ */


/* macros for chn_table_map.BB_paprd_trainer_stat2 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAINER_STAT2__NUM                       1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_stat3 */
#ifndef __PAPRD_TRAINER_STAT3_MACRO__
#define __PAPRD_TRAINER_STAT3_MACRO__

/* macros for field paprd_train_samples_cnt */
#define PAPRD_TRAINER_STAT3__PAPRD_TRAIN_SAMPLES_CNT__SHIFT                   0
#define PAPRD_TRAINER_STAT3__PAPRD_TRAIN_SAMPLES_CNT__WIDTH                  20
#define PAPRD_TRAINER_STAT3__PAPRD_TRAIN_SAMPLES_CNT__MASK          0x000fffffU
#define PAPRD_TRAINER_STAT3__PAPRD_TRAIN_SAMPLES_CNT__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000fffffU

/* macros for field paprd_fine_idx */
#define PAPRD_TRAINER_STAT3__PAPRD_FINE_IDX__SHIFT                           20
#define PAPRD_TRAINER_STAT3__PAPRD_FINE_IDX__WIDTH                            2
#define PAPRD_TRAINER_STAT3__PAPRD_FINE_IDX__MASK                   0x00300000U
#define PAPRD_TRAINER_STAT3__PAPRD_FINE_IDX__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00300000U) >> 20)

/* macros for field paprd_coarse_idx */
#define PAPRD_TRAINER_STAT3__PAPRD_COARSE_IDX__SHIFT                         22
#define PAPRD_TRAINER_STAT3__PAPRD_COARSE_IDX__WIDTH                          5
#define PAPRD_TRAINER_STAT3__PAPRD_COARSE_IDX__MASK                 0x07c00000U
#define PAPRD_TRAINER_STAT3__PAPRD_COARSE_IDX__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x07c00000U) >> 22)
#define PAPRD_TRAINER_STAT3__TYPE                                     u_int32_t
#define PAPRD_TRAINER_STAT3__READ                                   0x07ffffffU

#endif /* __PAPRD_TRAINER_STAT3_MACRO__ */


/* macros for chn_table_map.BB_paprd_trainer_stat3 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAINER_STAT3__NUM                       1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set0 */
#ifndef __PAPRD_TRAIN_GAIN_SET0_MACRO__
#define __PAPRD_TRAIN_GAIN_SET0_MACRO__

/* macros for field paprd_gain_tbl_0 */
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__SHIFT                        0
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__WIDTH                       10
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__MASK               0x000003ffU
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_1 */
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__SHIFT                       10
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__WIDTH                       10
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__MASK               0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_2 */
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__SHIFT                       20
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__WIDTH                       10
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__MASK               0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET0__TYPE                                   u_int32_t
#define PAPRD_TRAIN_GAIN_SET0__READ                                 0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET0__WRITE                                0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET0_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET0__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set1 */
#ifndef __PAPRD_TRAIN_GAIN_SET1_MACRO__
#define __PAPRD_TRAIN_GAIN_SET1_MACRO__

/* macros for field paprd_gain_tbl_3 */
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__SHIFT                        0
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__WIDTH                       10
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__MASK               0x000003ffU
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_4 */
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__SHIFT                       10
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__WIDTH                       10
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__MASK               0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_5 */
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__SHIFT                       20
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__WIDTH                       10
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__MASK               0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET1__TYPE                                   u_int32_t
#define PAPRD_TRAIN_GAIN_SET1__READ                                 0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET1__WRITE                                0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET1_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set1 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET1__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set2 */
#ifndef __PAPRD_TRAIN_GAIN_SET2_MACRO__
#define __PAPRD_TRAIN_GAIN_SET2_MACRO__

/* macros for field paprd_gain_tbl_6 */
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__SHIFT                        0
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__WIDTH                       10
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__MASK               0x000003ffU
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_7 */
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__SHIFT                       10
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__WIDTH                       10
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__MASK               0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_8 */
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__SHIFT                       20
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__WIDTH                       10
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__MASK               0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET2__TYPE                                   u_int32_t
#define PAPRD_TRAIN_GAIN_SET2__READ                                 0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET2__WRITE                                0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET2_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set2 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET2__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set3 */
#ifndef __PAPRD_TRAIN_GAIN_SET3_MACRO__
#define __PAPRD_TRAIN_GAIN_SET3_MACRO__

/* macros for field paprd_gain_tbl_9 */
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__SHIFT                        0
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__WIDTH                       10
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__MASK               0x000003ffU
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_10 */
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__SHIFT                      10
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__MASK              0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_11 */
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__SHIFT                      20
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__MASK              0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET3__TYPE                                   u_int32_t
#define PAPRD_TRAIN_GAIN_SET3__READ                                 0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET3__WRITE                                0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET3_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set3 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET3__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set4 */
#ifndef __PAPRD_TRAIN_GAIN_SET4_MACRO__
#define __PAPRD_TRAIN_GAIN_SET4_MACRO__

/* macros for field paprd_gain_tbl_12 */
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__MASK              0x000003ffU
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_13 */
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__SHIFT                      10
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__MASK              0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_14 */
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__SHIFT                      20
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__MASK              0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET4__TYPE                                   u_int32_t
#define PAPRD_TRAIN_GAIN_SET4__READ                                 0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET4__WRITE                                0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET4_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set4 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET4__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set5 */
#ifndef __PAPRD_TRAIN_GAIN_SET5_MACRO__
#define __PAPRD_TRAIN_GAIN_SET5_MACRO__

/* macros for field paprd_gain_tbl_15 */
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__MASK              0x000003ffU
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_16 */
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__SHIFT                      10
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__MASK              0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_17 */
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__SHIFT                      20
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__MASK              0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET5__TYPE                                   u_int32_t
#define PAPRD_TRAIN_GAIN_SET5__READ                                 0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET5__WRITE                                0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET5_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set5 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET5__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set6 */
#ifndef __PAPRD_TRAIN_GAIN_SET6_MACRO__
#define __PAPRD_TRAIN_GAIN_SET6_MACRO__

/* macros for field paprd_gain_tbl_18 */
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__MASK              0x000003ffU
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_19 */
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__SHIFT                      10
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__MASK              0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_20 */
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__SHIFT                      20
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__MASK              0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET6__TYPE                                   u_int32_t
#define PAPRD_TRAIN_GAIN_SET6__READ                                 0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET6__WRITE                                0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET6_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set6 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET6__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set7 */
#ifndef __PAPRD_TRAIN_GAIN_SET7_MACRO__
#define __PAPRD_TRAIN_GAIN_SET7_MACRO__

/* macros for field paprd_gain_tbl_21 */
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__MASK              0x000003ffU
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_22 */
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__SHIFT                      10
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__MASK              0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_23 */
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__SHIFT                      20
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__MASK              0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET7__TYPE                                   u_int32_t
#define PAPRD_TRAIN_GAIN_SET7__READ                                 0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET7__WRITE                                0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET7_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set7 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET7__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set8 */
#ifndef __PAPRD_TRAIN_GAIN_SET8_MACRO__
#define __PAPRD_TRAIN_GAIN_SET8_MACRO__

/* macros for field paprd_gain_tbl_24 */
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__MASK              0x000003ffU
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_25 */
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_25__SHIFT                      10
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_25__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_25__MASK              0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_25__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_25__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_25__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_25__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_26 */
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_26__SHIFT                      20
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_26__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_26__MASK              0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_26__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_26__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_26__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_26__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET8__TYPE                                   u_int32_t
#define PAPRD_TRAIN_GAIN_SET8__READ                                 0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET8__WRITE                                0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET8_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set8 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET8__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_idx_set0 */
#ifndef __PAPRD_TRAIN_GAIN_IDX_SET0_MACRO__
#define __PAPRD_TRAIN_GAIN_IDX_SET0_MACRO__

/* macros for field paprd_gain_idx_0 */
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__SHIFT                    0
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__WIDTH                   32
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__MASK           0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__READ(src) \
                    (u_int32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((u_int32_t)(src) &\
                    0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0xffffffffU)))
#define PAPRD_TRAIN_GAIN_IDX_SET0__TYPE                               u_int32_t
#define PAPRD_TRAIN_GAIN_IDX_SET0__READ                             0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET0__WRITE                            0xffffffffU

#endif /* __PAPRD_TRAIN_GAIN_IDX_SET0_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_idx_set0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_IDX_SET0__NUM                 1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_idx_set1 */
#ifndef __PAPRD_TRAIN_GAIN_IDX_SET1_MACRO__
#define __PAPRD_TRAIN_GAIN_IDX_SET1_MACRO__

/* macros for field paprd_gain_idx_1 */
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__SHIFT                    0
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__WIDTH                   32
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__MASK           0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__READ(src) \
                    (u_int32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((u_int32_t)(src) &\
                    0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0xffffffffU)))
#define PAPRD_TRAIN_GAIN_IDX_SET1__TYPE                               u_int32_t
#define PAPRD_TRAIN_GAIN_IDX_SET1__READ                             0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET1__WRITE                            0xffffffffU

#endif /* __PAPRD_TRAIN_GAIN_IDX_SET1_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_idx_set1 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_IDX_SET1__NUM                 1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_idx_set2 */
#ifndef __PAPRD_TRAIN_GAIN_IDX_SET2_MACRO__
#define __PAPRD_TRAIN_GAIN_IDX_SET2_MACRO__

/* macros for field paprd_gain_idx_2 */
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__SHIFT                    0
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__WIDTH                   32
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__MASK           0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__READ(src) \
                    (u_int32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((u_int32_t)(src) &\
                    0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0xffffffffU)))
#define PAPRD_TRAIN_GAIN_IDX_SET2__TYPE                               u_int32_t
#define PAPRD_TRAIN_GAIN_IDX_SET2__READ                             0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET2__WRITE                            0xffffffffU

#endif /* __PAPRD_TRAIN_GAIN_IDX_SET2_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_idx_set2 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_IDX_SET2__NUM                 1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_idx_set3 */
#ifndef __PAPRD_TRAIN_GAIN_IDX_SET3_MACRO__
#define __PAPRD_TRAIN_GAIN_IDX_SET3_MACRO__

/* macros for field paprd_gain_idx_3 */
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__SHIFT                    0
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__WIDTH                   32
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__MASK           0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__READ(src) \
                    (u_int32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((u_int32_t)(src) &\
                    0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0xffffffffU)))
#define PAPRD_TRAIN_GAIN_IDX_SET3__TYPE                               u_int32_t
#define PAPRD_TRAIN_GAIN_IDX_SET3__READ                             0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET3__WRITE                            0xffffffffU

#endif /* __PAPRD_TRAIN_GAIN_IDX_SET3_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_idx_set3 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_IDX_SET3__NUM                 1

/* macros for BlueprintGlobalNameSpace::paprd_train_agc0 */
#ifndef __PAPRD_TRAIN_AGC0_MACRO__
#define __PAPRD_TRAIN_AGC0_MACRO__

/* macros for field paprd_pwr_high */
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__SHIFT                               0
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__WIDTH                               8
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__MASK                      0x000000ffU
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000000ffU
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000000ffU)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((u_int32_t)(src) &\
                    0x000000ffU)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000000ffU)))

/* macros for field paprd_pwr_low */
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__SHIFT                                8
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__WIDTH                                8
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__MASK                       0x0000ff00U
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 8) & 0x0000ff00U)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((u_int32_t)(src) <<\
                    8) & 0x0000ff00U)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 8) & ~0x0000ff00U)))

/* macros for field paprd_pwr_weak */
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__SHIFT                              16
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__WIDTH                               8
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__MASK                      0x00ff0000U
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 16) & 0x00ff0000U)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((u_int32_t)(src) <<\
                    16) & 0x00ff0000U)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 16) & ~0x00ff0000U)))

/* macros for field consec_pwr_low_cnt */
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__SHIFT                          24
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__WIDTH                           2
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__MASK                  0x03000000U
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x03000000U) >> 24)
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 24) & 0x03000000U)
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((u_int32_t)(src) <<\
                    24) & 0x03000000U)
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 24) & ~0x03000000U)))

/* macros for field consec_gain_change */
#define PAPRD_TRAIN_AGC0__CONSEC_GAIN_CHANGE__SHIFT                          26
#define PAPRD_TRAIN_AGC0__CONSEC_GAIN_CHANGE__WIDTH                           4
#define PAPRD_TRAIN_AGC0__CONSEC_GAIN_CHANGE__MASK                  0x3c000000U
#define PAPRD_TRAIN_AGC0__CONSEC_GAIN_CHANGE__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3c000000U) >> 26)
#define PAPRD_TRAIN_AGC0__CONSEC_GAIN_CHANGE__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 26) & 0x3c000000U)
#define PAPRD_TRAIN_AGC0__CONSEC_GAIN_CHANGE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3c000000U) | (((u_int32_t)(src) <<\
                    26) & 0x3c000000U)
#define PAPRD_TRAIN_AGC0__CONSEC_GAIN_CHANGE__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 26) & ~0x3c000000U)))
#define PAPRD_TRAIN_AGC0__TYPE                                        u_int32_t
#define PAPRD_TRAIN_AGC0__READ                                      0x3fffffffU
#define PAPRD_TRAIN_AGC0__WRITE                                     0x3fffffffU

#endif /* __PAPRD_TRAIN_AGC0_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_agc0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_AGC0__NUM                          1

/* macros for BlueprintGlobalNameSpace::paprd_train_agc1 */
#ifndef __PAPRD_TRAIN_AGC1_MACRO__
#define __PAPRD_TRAIN_AGC1_MACRO__

/* macros for field target_lvl_hi_db */
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__SHIFT                             0
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__WIDTH                             6
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__MASK                    0x0000003fU
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0000003fU
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((u_int32_t)(src) &\
                    0x0000003fU)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field target_lvl_low_db */
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__SHIFT                            6
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__WIDTH                            6
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__MASK                   0x00000fc0U
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((u_int32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field target_lvl_weak_db */
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__SHIFT                          12
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__WIDTH                           6
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__MASK                  0x0003f000U
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 12) & 0x0003f000U)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((u_int32_t)(src) <<\
                    12) & 0x0003f000U)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define PAPRD_TRAIN_AGC1__TYPE                                        u_int32_t
#define PAPRD_TRAIN_AGC1__READ                                      0x0003ffffU
#define PAPRD_TRAIN_AGC1__WRITE                                     0x0003ffffU

#endif /* __PAPRD_TRAIN_AGC1_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_agc1 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_AGC1__NUM                          1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_acc_0 */
#ifndef __PAPRD_TRAIN_QCHK_ACC_0_MACRO__
#define __PAPRD_TRAIN_QCHK_ACC_0_MACRO__

/* macros for field paprd_qchk_acc_0 */
#define PAPRD_TRAIN_QCHK_ACC_0__PAPRD_QCHK_ACC_0__SHIFT                       0
#define PAPRD_TRAIN_QCHK_ACC_0__PAPRD_QCHK_ACC_0__WIDTH                      25
#define PAPRD_TRAIN_QCHK_ACC_0__PAPRD_QCHK_ACC_0__MASK              0x01ffffffU
#define PAPRD_TRAIN_QCHK_ACC_0__PAPRD_QCHK_ACC_0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x01ffffffU
#define PAPRD_TRAIN_QCHK_ACC_0__TYPE                                  u_int32_t
#define PAPRD_TRAIN_QCHK_ACC_0__READ                                0x01ffffffU

#endif /* __PAPRD_TRAIN_QCHK_ACC_0_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_qchk_acc_0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_QCHK_ACC_0__NUM                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_acc_1 */
#ifndef __PAPRD_TRAIN_QCHK_ACC_1_MACRO__
#define __PAPRD_TRAIN_QCHK_ACC_1_MACRO__

/* macros for field paprd_qchk_acc_1 */
#define PAPRD_TRAIN_QCHK_ACC_1__PAPRD_QCHK_ACC_1__SHIFT                       0
#define PAPRD_TRAIN_QCHK_ACC_1__PAPRD_QCHK_ACC_1__WIDTH                      25
#define PAPRD_TRAIN_QCHK_ACC_1__PAPRD_QCHK_ACC_1__MASK              0x01ffffffU
#define PAPRD_TRAIN_QCHK_ACC_1__PAPRD_QCHK_ACC_1__READ(src) \
                    (u_int32_t)(src)\
                    & 0x01ffffffU
#define PAPRD_TRAIN_QCHK_ACC_1__TYPE                                  u_int32_t
#define PAPRD_TRAIN_QCHK_ACC_1__READ                                0x01ffffffU

#endif /* __PAPRD_TRAIN_QCHK_ACC_1_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_qchk_acc_1 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_QCHK_ACC_1__NUM                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_acc_2 */
#ifndef __PAPRD_TRAIN_QCHK_ACC_2_MACRO__
#define __PAPRD_TRAIN_QCHK_ACC_2_MACRO__

/* macros for field paprd_qchk_acc_2 */
#define PAPRD_TRAIN_QCHK_ACC_2__PAPRD_QCHK_ACC_2__SHIFT                       0
#define PAPRD_TRAIN_QCHK_ACC_2__PAPRD_QCHK_ACC_2__WIDTH                      25
#define PAPRD_TRAIN_QCHK_ACC_2__PAPRD_QCHK_ACC_2__MASK              0x01ffffffU
#define PAPRD_TRAIN_QCHK_ACC_2__PAPRD_QCHK_ACC_2__READ(src) \
                    (u_int32_t)(src)\
                    & 0x01ffffffU
#define PAPRD_TRAIN_QCHK_ACC_2__TYPE                                  u_int32_t
#define PAPRD_TRAIN_QCHK_ACC_2__READ                                0x01ffffffU

#endif /* __PAPRD_TRAIN_QCHK_ACC_2_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_qchk_acc_2 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_QCHK_ACC_2__NUM                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_acc_3 */
#ifndef __PAPRD_TRAIN_QCHK_ACC_3_MACRO__
#define __PAPRD_TRAIN_QCHK_ACC_3_MACRO__

/* macros for field paprd_qchk_acc_3 */
#define PAPRD_TRAIN_QCHK_ACC_3__PAPRD_QCHK_ACC_3__SHIFT                       0
#define PAPRD_TRAIN_QCHK_ACC_3__PAPRD_QCHK_ACC_3__WIDTH                      25
#define PAPRD_TRAIN_QCHK_ACC_3__PAPRD_QCHK_ACC_3__MASK              0x01ffffffU
#define PAPRD_TRAIN_QCHK_ACC_3__PAPRD_QCHK_ACC_3__READ(src) \
                    (u_int32_t)(src)\
                    & 0x01ffffffU
#define PAPRD_TRAIN_QCHK_ACC_3__TYPE                                  u_int32_t
#define PAPRD_TRAIN_QCHK_ACC_3__READ                                0x01ffffffU

#endif /* __PAPRD_TRAIN_QCHK_ACC_3_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_qchk_acc_3 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_QCHK_ACC_3__NUM                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_data_0 */
#ifndef __PAPRD_TRAIN_QCHK_DATA_0_MACRO__
#define __PAPRD_TRAIN_QCHK_DATA_0_MACRO__

/* macros for field paprd_qchk_min_0 */
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MIN_0__SHIFT                      0
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MIN_0__WIDTH                     12
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MIN_0__MASK             0x00000fffU
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MIN_0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU

/* macros for field paprd_qchk_max_0 */
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MAX_0__SHIFT                     12
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MAX_0__WIDTH                     12
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MAX_0__MASK             0x00fff000U
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MAX_0__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PAPRD_TRAIN_QCHK_DATA_0__TYPE                                 u_int32_t
#define PAPRD_TRAIN_QCHK_DATA_0__READ                               0x00ffffffU

#endif /* __PAPRD_TRAIN_QCHK_DATA_0_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_qchk_data_0 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_QCHK_DATA_0__NUM                   1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_data_1 */
#ifndef __PAPRD_TRAIN_QCHK_DATA_1_MACRO__
#define __PAPRD_TRAIN_QCHK_DATA_1_MACRO__

/* macros for field paprd_qchk_min_1 */
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MIN_1__SHIFT                      0
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MIN_1__WIDTH                     12
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MIN_1__MASK             0x00000fffU
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MIN_1__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU

/* macros for field paprd_qchk_max_1 */
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MAX_1__SHIFT                     12
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MAX_1__WIDTH                     12
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MAX_1__MASK             0x00fff000U
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MAX_1__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PAPRD_TRAIN_QCHK_DATA_1__TYPE                                 u_int32_t
#define PAPRD_TRAIN_QCHK_DATA_1__READ                               0x00ffffffU

#endif /* __PAPRD_TRAIN_QCHK_DATA_1_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_qchk_data_1 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_QCHK_DATA_1__NUM                   1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_data_2 */
#ifndef __PAPRD_TRAIN_QCHK_DATA_2_MACRO__
#define __PAPRD_TRAIN_QCHK_DATA_2_MACRO__

/* macros for field paprd_qchk_min_2 */
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MIN_2__SHIFT                      0
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MIN_2__WIDTH                     12
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MIN_2__MASK             0x00000fffU
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MIN_2__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU

/* macros for field paprd_qchk_max_2 */
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MAX_2__SHIFT                     12
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MAX_2__WIDTH                     12
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MAX_2__MASK             0x00fff000U
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MAX_2__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PAPRD_TRAIN_QCHK_DATA_2__TYPE                                 u_int32_t
#define PAPRD_TRAIN_QCHK_DATA_2__READ                               0x00ffffffU

#endif /* __PAPRD_TRAIN_QCHK_DATA_2_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_qchk_data_2 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_QCHK_DATA_2__NUM                   1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_data_3 */
#ifndef __PAPRD_TRAIN_QCHK_DATA_3_MACRO__
#define __PAPRD_TRAIN_QCHK_DATA_3_MACRO__

/* macros for field paprd_qchk_min_3 */
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MIN_3__SHIFT                      0
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MIN_3__WIDTH                     12
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MIN_3__MASK             0x00000fffU
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MIN_3__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU

/* macros for field paprd_qchk_max_3 */
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MAX_3__SHIFT                     12
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MAX_3__WIDTH                     12
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MAX_3__MASK             0x00fff000U
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MAX_3__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x00fff000U) >> 12)
#define PAPRD_TRAIN_QCHK_DATA_3__TYPE                                 u_int32_t
#define PAPRD_TRAIN_QCHK_DATA_3__READ                               0x00ffffffU

#endif /* __PAPRD_TRAIN_QCHK_DATA_3_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_qchk_data_3 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_QCHK_DATA_3__NUM                   1

/* macros for BlueprintGlobalNameSpace::paprd_train_mem */
#ifndef __PAPRD_TRAIN_MEM_MACRO__
#define __PAPRD_TRAIN_MEM_MACRO__

/* macros for field paprd_trn_data */
#define PAPRD_TRAIN_MEM__PAPRD_TRN_DATA__SHIFT                                0
#define PAPRD_TRAIN_MEM__PAPRD_TRN_DATA__WIDTH                               32
#define PAPRD_TRAIN_MEM__PAPRD_TRN_DATA__MASK                       0xffffffffU
#define PAPRD_TRAIN_MEM__PAPRD_TRN_DATA__READ(src) \
                    (u_int32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAIN_MEM__TYPE                                         u_int32_t
#define PAPRD_TRAIN_MEM__READ                                       0xffffffffU

#endif /* __PAPRD_TRAIN_MEM_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_mem */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_MEM__NUM                         384

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set9 */
#ifndef __PAPRD_TRAIN_GAIN_SET9_MACRO__
#define __PAPRD_TRAIN_GAIN_SET9_MACRO__

/* macros for field paprd_gain_tbl_27 */
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_27__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_27__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_27__MASK              0x000003ffU
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_27__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_27__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_27__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_27__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_28 */
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_28__SHIFT                      10
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_28__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_28__MASK              0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_28__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_28__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_28__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_28__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_29 */
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_29__SHIFT                      20
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_29__WIDTH                      10
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_29__MASK              0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_29__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_29__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_29__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET9__PAPRD_GAIN_TBL_29__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET9__TYPE                                   u_int32_t
#define PAPRD_TRAIN_GAIN_SET9__READ                                 0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET9__WRITE                                0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET9_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set9 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET9__NUM                     1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set10 */
#ifndef __PAPRD_TRAIN_GAIN_SET10_MACRO__
#define __PAPRD_TRAIN_GAIN_SET10_MACRO__

/* macros for field paprd_gain_tbl_30 */
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_30__SHIFT                      0
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_30__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_30__MASK             0x000003ffU
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_30__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_30__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_30__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_30__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_31 */
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_31__SHIFT                     10
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_31__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_31__MASK             0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_31__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_31__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_31__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_31__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_32 */
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_32__SHIFT                     20
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_32__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_32__MASK             0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_32__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_32__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_32__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET10__PAPRD_GAIN_TBL_32__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET10__TYPE                                  u_int32_t
#define PAPRD_TRAIN_GAIN_SET10__READ                                0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET10__WRITE                               0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET10_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set10 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET10__NUM                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set11 */
#ifndef __PAPRD_TRAIN_GAIN_SET11_MACRO__
#define __PAPRD_TRAIN_GAIN_SET11_MACRO__

/* macros for field paprd_gain_tbl_33 */
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_33__SHIFT                      0
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_33__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_33__MASK             0x000003ffU
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_33__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_33__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_33__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_33__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_34 */
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_34__SHIFT                     10
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_34__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_34__MASK             0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_34__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_34__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_34__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_34__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_35 */
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_35__SHIFT                     20
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_35__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_35__MASK             0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_35__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_35__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_35__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET11__PAPRD_GAIN_TBL_35__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET11__TYPE                                  u_int32_t
#define PAPRD_TRAIN_GAIN_SET11__READ                                0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET11__WRITE                               0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET11_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set11 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET11__NUM                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set12 */
#ifndef __PAPRD_TRAIN_GAIN_SET12_MACRO__
#define __PAPRD_TRAIN_GAIN_SET12_MACRO__

/* macros for field paprd_gain_tbl_36 */
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_36__SHIFT                      0
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_36__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_36__MASK             0x000003ffU
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_36__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_36__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_36__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_36__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_37 */
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_37__SHIFT                     10
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_37__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_37__MASK             0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_37__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_37__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_37__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_37__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_38 */
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_38__SHIFT                     20
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_38__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_38__MASK             0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_38__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_38__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_38__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET12__PAPRD_GAIN_TBL_38__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET12__TYPE                                  u_int32_t
#define PAPRD_TRAIN_GAIN_SET12__READ                                0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET12__WRITE                               0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET12_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set12 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET12__NUM                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set13 */
#ifndef __PAPRD_TRAIN_GAIN_SET13_MACRO__
#define __PAPRD_TRAIN_GAIN_SET13_MACRO__

/* macros for field paprd_gain_tbl_39 */
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_39__SHIFT                      0
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_39__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_39__MASK             0x000003ffU
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_39__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_39__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_39__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_39__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_gain_tbl_40 */
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_40__SHIFT                     10
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_40__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_40__MASK             0x000ffc00U
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_40__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_40__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_40__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((u_int32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_40__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_gain_tbl_41 */
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_41__SHIFT                     20
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_41__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_41__MASK             0x3ff00000U
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_41__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_41__WRITE(src) \
                    (((u_int32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_41__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((u_int32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_TRAIN_GAIN_SET13__PAPRD_GAIN_TBL_41__VERIFY(src) \
                    (!((((u_int32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_TRAIN_GAIN_SET13__TYPE                                  u_int32_t
#define PAPRD_TRAIN_GAIN_SET13__READ                                0x3fffffffU
#define PAPRD_TRAIN_GAIN_SET13__WRITE                               0x3fffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET13_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set13 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET13__NUM                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set14 */
#ifndef __PAPRD_TRAIN_GAIN_SET14_MACRO__
#define __PAPRD_TRAIN_GAIN_SET14_MACRO__

/* macros for field paprd_gain_tbl_42 */
#define PAPRD_TRAIN_GAIN_SET14__PAPRD_GAIN_TBL_42__SHIFT                      0
#define PAPRD_TRAIN_GAIN_SET14__PAPRD_GAIN_TBL_42__WIDTH                     10
#define PAPRD_TRAIN_GAIN_SET14__PAPRD_GAIN_TBL_42__MASK             0x000003ffU
#define PAPRD_TRAIN_GAIN_SET14__PAPRD_GAIN_TBL_42__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000003ffU
#define PAPRD_TRAIN_GAIN_SET14__PAPRD_GAIN_TBL_42__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET14__PAPRD_GAIN_TBL_42__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((u_int32_t)(src) &\
                    0x000003ffU)
#define PAPRD_TRAIN_GAIN_SET14__PAPRD_GAIN_TBL_42__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x000003ffU)))
#define PAPRD_TRAIN_GAIN_SET14__TYPE                                  u_int32_t
#define PAPRD_TRAIN_GAIN_SET14__READ                                0x000003ffU
#define PAPRD_TRAIN_GAIN_SET14__WRITE                               0x000003ffU

#endif /* __PAPRD_TRAIN_GAIN_SET14_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_set14 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_SET14__NUM                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_idx_set4 */
#ifndef __PAPRD_TRAIN_GAIN_IDX_SET4_MACRO__
#define __PAPRD_TRAIN_GAIN_IDX_SET4_MACRO__

/* macros for field paprd_gain_idx_4 */
#define PAPRD_TRAIN_GAIN_IDX_SET4__PAPRD_GAIN_IDX_4__SHIFT                    0
#define PAPRD_TRAIN_GAIN_IDX_SET4__PAPRD_GAIN_IDX_4__WIDTH                   32
#define PAPRD_TRAIN_GAIN_IDX_SET4__PAPRD_GAIN_IDX_4__MASK           0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET4__PAPRD_GAIN_IDX_4__READ(src) \
                    (u_int32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET4__PAPRD_GAIN_IDX_4__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET4__PAPRD_GAIN_IDX_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((u_int32_t)(src) &\
                    0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET4__PAPRD_GAIN_IDX_4__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0xffffffffU)))
#define PAPRD_TRAIN_GAIN_IDX_SET4__TYPE                               u_int32_t
#define PAPRD_TRAIN_GAIN_IDX_SET4__READ                             0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET4__WRITE                            0xffffffffU

#endif /* __PAPRD_TRAIN_GAIN_IDX_SET4_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_idx_set4 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_IDX_SET4__NUM                 1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_idx_set5 */
#ifndef __PAPRD_TRAIN_GAIN_IDX_SET5_MACRO__
#define __PAPRD_TRAIN_GAIN_IDX_SET5_MACRO__

/* macros for field paprd_gain_idx_5 */
#define PAPRD_TRAIN_GAIN_IDX_SET5__PAPRD_GAIN_IDX_5__SHIFT                    0
#define PAPRD_TRAIN_GAIN_IDX_SET5__PAPRD_GAIN_IDX_5__WIDTH                   12
#define PAPRD_TRAIN_GAIN_IDX_SET5__PAPRD_GAIN_IDX_5__MASK           0x00000fffU
#define PAPRD_TRAIN_GAIN_IDX_SET5__PAPRD_GAIN_IDX_5__READ(src) \
                    (u_int32_t)(src)\
                    & 0x00000fffU
#define PAPRD_TRAIN_GAIN_IDX_SET5__PAPRD_GAIN_IDX_5__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x00000fffU)
#define PAPRD_TRAIN_GAIN_IDX_SET5__PAPRD_GAIN_IDX_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((u_int32_t)(src) &\
                    0x00000fffU)
#define PAPRD_TRAIN_GAIN_IDX_SET5__PAPRD_GAIN_IDX_5__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x00000fffU)))
#define PAPRD_TRAIN_GAIN_IDX_SET5__TYPE                               u_int32_t
#define PAPRD_TRAIN_GAIN_IDX_SET5__READ                             0x00000fffU
#define PAPRD_TRAIN_GAIN_IDX_SET5__WRITE                            0x00000fffU

#endif /* __PAPRD_TRAIN_GAIN_IDX_SET5_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_gain_idx_set5 */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_GAIN_IDX_SET5__NUM                 1

/* macros for BlueprintGlobalNameSpace::normtx_txiq_corr_coeff_b0 */
#ifndef __NORMTX_TXIQ_CORR_COEFF_B0_MACRO__
#define __NORMTX_TXIQ_CORR_COEFF_B0_MACRO__

/* macros for field normtx_iqc_coeff_table_chn0 */
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__SHIFT         0
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__WIDTH        18
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__MASK \
                    0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0003ffffU)
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((u_int32_t)(src) &\
                    0x0003ffffU)
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0003ffffU)))
#define NORMTX_TXIQ_CORR_COEFF_B0__TYPE                               u_int32_t
#define NORMTX_TXIQ_CORR_COEFF_B0__READ                             0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B0__WRITE                            0x0003ffffU

#endif /* __NORMTX_TXIQ_CORR_COEFF_B0_MACRO__ */


/* macros for chn_table_map.BB_normtx_txiq_corr_coeff_b0 */
#define INST_CHN_TABLE_MAP__BB_NORMTX_TXIQ_CORR_COEFF_B0__NUM               160

/* macros for BlueprintGlobalNameSpace::paprd_train_dc_est */
#ifndef __PAPRD_TRAIN_DC_EST_MACRO__
#define __PAPRD_TRAIN_DC_EST_MACRO__

/* macros for field paprd_dc_est_i */
#define PAPRD_TRAIN_DC_EST__PAPRD_DC_EST_I__SHIFT                             0
#define PAPRD_TRAIN_DC_EST__PAPRD_DC_EST_I__WIDTH                            11
#define PAPRD_TRAIN_DC_EST__PAPRD_DC_EST_I__MASK                    0x000007ffU
#define PAPRD_TRAIN_DC_EST__PAPRD_DC_EST_I__READ(src) \
                    (u_int32_t)(src)\
                    & 0x000007ffU

/* macros for field paprd_dc_est_q */
#define PAPRD_TRAIN_DC_EST__PAPRD_DC_EST_Q__SHIFT                            11
#define PAPRD_TRAIN_DC_EST__PAPRD_DC_EST_Q__WIDTH                            11
#define PAPRD_TRAIN_DC_EST__PAPRD_DC_EST_Q__MASK                    0x003ff800U
#define PAPRD_TRAIN_DC_EST__PAPRD_DC_EST_Q__READ(src) \
                    (((u_int32_t)(src)\
                    & 0x003ff800U) >> 11)
#define PAPRD_TRAIN_DC_EST__TYPE                                      u_int32_t
#define PAPRD_TRAIN_DC_EST__READ                                    0x003fffffU

#endif /* __PAPRD_TRAIN_DC_EST_MACRO__ */


/* macros for chn_table_map.BB_paprd_train_dc_est */
#define INST_CHN_TABLE_MAP__BB_PAPRD_TRAIN_DC_EST__NUM                        1

/* macros for BlueprintGlobalNameSpace::chaninfo_tab_b0 */
#ifndef __CHANINFO_TAB_B0_MACRO__
#define __CHANINFO_TAB_B0_MACRO__

/* macros for field chaninfo_word */
#define CHANINFO_TAB_B0__CHANINFO_WORD__SHIFT                                 0
#define CHANINFO_TAB_B0__CHANINFO_WORD__WIDTH                                32
#define CHANINFO_TAB_B0__CHANINFO_WORD__MASK                        0xffffffffU
#define CHANINFO_TAB_B0__CHANINFO_WORD__READ(src) \
                    (u_int32_t)(src)\
                    & 0xffffffffU
#define CHANINFO_TAB_B0__CHANINFO_WORD__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0xffffffffU)
#define CHANINFO_TAB_B0__CHANINFO_WORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((u_int32_t)(src) &\
                    0xffffffffU)
#define CHANINFO_TAB_B0__CHANINFO_WORD__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0xffffffffU)))
#define CHANINFO_TAB_B0__TYPE                                         u_int32_t
#define CHANINFO_TAB_B0__READ                                       0xffffffffU
#define CHANINFO_TAB_B0__WRITE                                      0xffffffffU

#endif /* __CHANINFO_TAB_B0_MACRO__ */


/* macros for chn_table_map.BB_chaninfo_tab_b0 */
#define INST_CHN_TABLE_MAP__BB_CHANINFO_TAB_B0__NUM                         256

/* macros for BlueprintGlobalNameSpace::tx_fir_coeff_mem */
#ifndef __TX_FIR_COEFF_MEM_MACRO__
#define __TX_FIR_COEFF_MEM_MACRO__

/* macros for field tx_fir_coeff */
#define TX_FIR_COEFF_MEM__TX_FIR_COEFF__SHIFT                                 0
#define TX_FIR_COEFF_MEM__TX_FIR_COEFF__WIDTH                                28
#define TX_FIR_COEFF_MEM__TX_FIR_COEFF__MASK                        0x0fffffffU
#define TX_FIR_COEFF_MEM__TX_FIR_COEFF__READ(src) \
                    (u_int32_t)(src)\
                    & 0x0fffffffU
#define TX_FIR_COEFF_MEM__TX_FIR_COEFF__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0fffffffU)
#define TX_FIR_COEFF_MEM__TX_FIR_COEFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fffffffU) | ((u_int32_t)(src) &\
                    0x0fffffffU)
#define TX_FIR_COEFF_MEM__TX_FIR_COEFF__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0fffffffU)))
#define TX_FIR_COEFF_MEM__TYPE                                        u_int32_t
#define TX_FIR_COEFF_MEM__READ                                      0x0fffffffU
#define TX_FIR_COEFF_MEM__WRITE                                     0x0fffffffU

#endif /* __TX_FIR_COEFF_MEM_MACRO__ */


/* macros for chn_table_map.BB_tx_fir_coeff_mem */
#define INST_CHN_TABLE_MAP__BB_TX_FIR_COEFF_MEM__NUM                        280

/* macros for BlueprintGlobalNameSpace::tx_fir_cntl */
#ifndef __TX_FIR_CNTL_MACRO__
#define __TX_FIR_CNTL_MACRO__

/* macros for field tx_fir_mcs_thr */
#define TX_FIR_CNTL__TX_FIR_MCS_THR__SHIFT                                    0
#define TX_FIR_CNTL__TX_FIR_MCS_THR__WIDTH                                    4
#define TX_FIR_CNTL__TX_FIR_MCS_THR__MASK                           0x0000000fU
#define TX_FIR_CNTL__TX_FIR_MCS_THR__READ(src)   (u_int32_t)(src) & 0x0000000fU
#define TX_FIR_CNTL__TX_FIR_MCS_THR__WRITE(src) \
                    ((u_int32_t)(src)\
                    & 0x0000000fU)
#define TX_FIR_CNTL__TX_FIR_MCS_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((u_int32_t)(src) &\
                    0x0000000fU)
#define TX_FIR_CNTL__TX_FIR_MCS_THR__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0x0000000fU)))
#define TX_FIR_CNTL__TYPE                                             u_int32_t
#define TX_FIR_CNTL__READ                                           0x0000000fU
#define TX_FIR_CNTL__WRITE                                          0x0000000fU

#endif /* __TX_FIR_CNTL_MACRO__ */


/* macros for chn_table_map.BB_tx_fir_cntl */
#define INST_CHN_TABLE_MAP__BB_TX_FIR_CNTL__NUM                               1

/* macros for BlueprintGlobalNameSpace::chn_tables_dummy_1 */
#ifndef __CHN_TABLES_DUMMY_1_MACRO__
#define __CHN_TABLES_DUMMY_1_MACRO__

/* macros for field dummy1 */
#define CHN_TABLES_DUMMY_1__DUMMY1__SHIFT                                     0
#define CHN_TABLES_DUMMY_1__DUMMY1__WIDTH                                    32
#define CHN_TABLES_DUMMY_1__DUMMY1__MASK                            0xffffffffU
#define CHN_TABLES_DUMMY_1__DUMMY1__READ(src)    (u_int32_t)(src) & 0xffffffffU
#define CHN_TABLES_DUMMY_1__DUMMY1__WRITE(src) ((u_int32_t)(src) & 0xffffffffU)
#define CHN_TABLES_DUMMY_1__DUMMY1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((u_int32_t)(src) &\
                    0xffffffffU)
#define CHN_TABLES_DUMMY_1__DUMMY1__VERIFY(src) \
                    (!(((u_int32_t)(src)\
                    & ~0xffffffffU)))
#define CHN_TABLES_DUMMY_1__TYPE                                      u_int32_t
#define CHN_TABLES_DUMMY_1__READ                                    0xffffffffU
#define CHN_TABLES_DUMMY_1__WRITE                                   0xffffffffU

#endif /* __CHN_TABLES_DUMMY_1_MACRO__ */


/* macros for chn_table_map.BB_chn_tables_dummy_1 */
#define INST_CHN_TABLE_MAP__BB_CHN_TABLES_DUMMY_1__NUM                        1
#define RFILE_INST_CHN_TABLE_MAP__NUM                                         1

#define TIERED_CHN_TABLE_MAP__VERSION \
                    "/prj/qca/chips/dakota/1.0/shanghai-qca/scratch_04/gcai/gcai_scr04_dev/ip/athr/wifi/dwc/shared/scripts/perllib/Pinfo.pm\n\
                    /prj/qca/chips/dakota/1.0/shanghai-qca/scratch_04/gcai/gcai_scr04_dev/ip/athr/wifi/dwc/shared/xml/bin/ath_ansic.pm\n\
                    /prj/qca/chips/dakota/1.0/shanghai-qca/scratch_04/gcai/gcai_scr04_dev/ip/athr/wifi/dwc/src/dwc_top/design/reg/dwc_top_reg.rdl\n\
                    /prj/qca/chips/dakota/1.0/shanghai-qca/scratch_04/gcai/gcai_scr04_dev/ip/athr/wifi/dwc/src/dwc_top/design/reg/dwc_top_reg_common_signals.rdl\n\
                    /prj/qca/chips/dakota/1.0/shanghai-qca/scratch_04/gcai/gcai_scr04_dev/ip/athr/wifi/dwc/src/dwc_top/design/reg/srcs/chn_table_map.rdl"
#endif /* __REG_TIERED_CHN_TABLE_MAP_MACRO_H__ */
