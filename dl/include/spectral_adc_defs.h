/*
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

/* Common dedfines for sharing spectral/ADC data from 11ac chipsets */

#ifndef __SPECTRAL_ADC_DEFS_H__
#define __SPECTRAL_ADC_DEFS_H__

#include "a_types.h"

#define SPECTRAL_ADC_LOG_TYPE_RX_PPDU_START     (0x0)
#define SPECTRAL_ADC_LOG_TYPE_RX_PPDU_END       (0x1)
#define SPECTRAL_ADC_LOG_TYPE_TLV               (0x2)

typedef struct _spectral_adc_log_desc
{
    A_UINT32 type;
    A_UINT32 serial_num;
} __attribute__((__packed__)) spectral_adc_log_desc;

/* TODO: Replace with OS independent define for packed */

#endif /* __SPECTRAL_ADC_DEFS_H__ */
