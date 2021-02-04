#ifndef __UTF_CAL__
#define __UTF_CAL__
/*==============================================================================

FILE:      utf_cal.h

DESCRIPTION
  This module implements the API to cache calibration in the utf image.
  It is mainly used by the HALPHY calibration module.

REFERENCES

       Copyright (c) 2015 QUALCOMM Atheros Incorporated.
               All Rights Reserved.
            QUALCOMM Proprietary/GTDR
==============================================================================*/
#include <osapi.h>

/*===========================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header:  $

when         who     what, where, why
--------     ---     ----------------------------------------------------------
11/25/2015   aratin  First draft created for utf image.
===========================================================================*/
#ifndef CONFIG_FAST_CALIBRATION_SUPPORT
#define CONFIG_FAST_CALIBRATION_SUPPORT
#endif
#define INVALID_CHANNEL_NUMBER 0xFF
#define MAX_NUMBER_OF_MODES 4
#define MAX_NUMBER_OF_CHAINMASKIDX 4
#define INVALID_CHAINMASK_IDX 0xFF

#define A_PRINTF_ONCE A_CMN(printf._printf)

typedef struct {
    A_UINT8 nSize; /* this is in multiples of 3k default buffeer size */
    A_UINT32 nHostCalibrationBufAddr;
} utf_cal_mode_data;

typedef struct {
    utf_cal_mode_data aMode[MAX_NUMBER_OF_MODES];
} utf_cal_chainmask_data;

typedef struct {
    A_UINT8 nChannelNumber;
    utf_cal_chainmask_data aChainMask[MAX_NUMBER_OF_CHAINMASKIDX];
} utf_cal_channel_data;

typedef struct {
    utf_cal_channel_data  *pChannelData;
    A_UINT8               *pLUT;
    A_UINT8               nTotalNumberOfChannels;
    A_UINT8               nHomeChannelRegistrationID;
    A_UINT8               nMaxChannels;
    A_UINT32              nHomeChannelBufferSize;
   
} utf_cal_ctxt;

#ifndef DISABLE_FUNCTION_INDIRECTION
typedef struct _utf_cal_api_fn {
    A_STATUS      (*_utf_cal_store_data) (A_UINT32 nChannelNumber,A_UINT32 nBufferAddr, A_UINT32 nSize, A_UINT32 nTotalBufferSize, A_UINT32 nSegmentNumber,A_UINT8 nChainmask,
                   A_UINT8 nMode );
    A_STATUS      (*_utf_cal_get_data) (A_UINT32 nChannelNumber,A_UINT32 nBufferAddr, A_UINT32 nSize, A_UINT32 nTotalBufferSize, A_UINT32 nSegmentNumber, A_UINT8 nChainmask,
                   A_UINT8 nMode);
    void          (*_utf_cal_clear_data)(void);
    void          (*_utf_cal_clear_channel_data)(A_UINT32 nChannelNumber);
    A_STATUS      (*_utf_cal_init) (void);
    utf_cal_ctxt* (*_utf_cal_get_ctxt) (void);
    
} UTF_CAL_API_FN;


extern UTF_CAL_API_FN _utf_cal_api;
#define UTF_CAL_API_INDIR_FN(_x)   _utf_cal_api._x

#else /* DISABLE_FUNCTION_INDIRECTION */

    #define UTF_CAL_API_INDIR_FN(_x)   (_x)

    A_STATUS      _utf_cal_store_data(A_UINT32 nChannelNumber,A_UINT32 nBufferAddr, A_UINT32 nSize, A_UINT32 nTotalBufferSize, A_UINT32 nSegmentNumber,A_UINT32 nChainmask,
                  A_UINT8 nMode );
    A_STATUS      _utf_cal_get_data(A_UINT32 nChannelNumber,A_UINT32 nBufferAddr, A_UINT32 nSize, A_UINT32 nTotalBufferSize, A_UINT32 nSegmentNumber,A_UINT32 nChainmask,
                  A_UINT8 nMode);
    void          _utf_cal_clear_data(void);
    void          _utf_cal_clear_channel_data(A_UINT32 nChannelNumber);
    A_STATUS      _utf_cal_init(void);
    utf_cal_ctxt* _utf_cal_get_ctxt(void);

#endif /* DISABLE_FUNCTION_INDIRECTION */

#define utf_cal_clear_data(void) \
    UTF_CAL_API_INDIR_FN(_utf_cal_clear_data(void))

#define utf_cal_clear_channel_data(nChannelNumber) \
    UTF_CAL_API_INDIR_FN(_utf_cal_clear_channel_data(nChannelNumber))

#define utf_cal_init(void) \
    UTF_CAL_API_INDIR_FN(_utf_cal_init(void))

#define utf_cal_get_data(nChannelNumber, nBufferAddr, nSegmentSize, nTotalBufferSize, nSegmentNumber, nChainmask, nMode) \
    UTF_CAL_API_INDIR_FN(_utf_cal_get_data((nChannelNumber), (nBufferAddr), (nSegmentSize), (nTotalBufferSize), (nSegmentNumber), (nChainmask),(nMode)))

#define utf_cal_store_data(nChannelNumber,nBufferAddr, nSegmentSize, nTotalBufferSize, nSegmentNumber, nChainmask, nMode) \
    UTF_CAL_API_INDIR_FN(_utf_cal_store_data((nChannelNumber), (nBufferAddr), (nSegmentSize), (nTotalBufferSize), (nSegmentNumber),(nChainmask),(nMode)))

#define utf_cal_get_ctxt(void) \
    UTF_CAL_API_INDIR_FN(_utf_cal_get_ctxt(void))

#endif /* __UTF_CAL__ */

