/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#if !defined(_DPD_TUNING_ATTN_H)
#define _DPD_TUNING_ATTN_H

typedef enum {
 DPD_SUCCESS = 0,
 DPD_FAILURE = 1,
 DPD_CALIBRATION_TIMEOUT = 2,
} DPD_PARM_STATUS;

void iniDpdTuningAtten(void);
void iniDpdTuningTimingIdx(void);
void iniDpdTuningtrainingQuality(void);
void iniDpdTuningAgc2Pwr(void);
void iniDpdTuning(void);
#endif //#if !defined(_DPD_TUNING_ATTN_H")


