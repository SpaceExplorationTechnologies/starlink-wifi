/*==============================================================================

FILE:      utf_cal.c

DESCRIPTION
  This module implements the API to cache calibration in the utf image.
  It is mainly used by the HALPHY calibration module.

REFERENCES

       Copyright (c) 2015 QUALCOMM Atheros Incorporated.
               All Rights Reserved.
            QUALCOMM Proprietary/GTDR
==============================================================================*/
/*===========================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header:  $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
1/14/2015   aratin  First draft created.
===========================================================================*/
#include <athdefs.h>
#include <osapi.h>
#include <qcache_api.h>
#include "utf_cal.h"
/*------------------------------------------------------------------------------
 Data Declarations.
------------------------------------------------------------------------------*/

/*
 * Fast Calibration data structure
 */
utf_cal_ctxt g_utf_cal_ctxt;
A_UINT32 ChainMaskToIdxLut[]=
{ 1, 2, 4 ,8 };

/*------------------------------------------------------------------------------
 Macro Declarations.
------------------------------------------------------------------------------*/

/*
 * Calibration data to be stored in HOST Memory.
 */
#define UTF_HOME_CHANNEL_CAL_HOST_MEM_REQ_ID 2

/*
 * The Copy Buffer is used to copy data to and from the host from the lower layers of halphy.
 * for Cascade the buffer size for storage is 6k.this is mainly due to increase in home channel
 * scan data.
 */
//#ifdef QCA9984
//#define CHANNEL_CAL_COPY_BUFF_SIZE (12*1024)
//#else
#define CHANNEL_CAL_COPY_BUFF_SIZE (6*1024)
//#endif
/*
 * Maximum number of channels the fw scans.
 */
#define MAX_SCAN_CHANNELS 255
/*
 * Maximum number of channels whose calibration data that will be stored in the HOST.
 */
#define MAX_CALIBRATION_CHANNELS 36
#define A_PRINTF_ONCE A_CMN(printf._printf)

#ifndef CONFIG_FAST_CALIBRATION_SUPPORT
#define CONFIG_FAST_CALIBRATION_SUPPORT
#endif
/*------------------------------------------------------------------------------
 Function Declarations.
------------------------------------------------------------------------------*/

A_UINT8 _utf_cal_get_chainmaskIdx(A_UINT32 chainmask);

/*------------------------------------------------------------------------------
Following functions are for Calibration Caching specific functionality
------------------------------------------------------------------------------*/

/*===============================================================================

FUNCTION : _utf_cal_clear_channel_data

Description:
    This function is used to clear the firmware references to the requested
    channel's calibration data.

Parameters:
    nChannelNumber : Channel whose data storage references needs to be cleared.

Return Value :
    None.

===============================================================================*/
void _utf_cal_clear_channel_data(A_UINT32 nChannelNumber)
{
#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)

    A_UINT8 nIdx, ModeIdx, ChainMskIdx;
    //A_PRINTF_ONCE("_utf_cal_clear_channel_data \n");
    if (nChannelNumber >= MAX_SCAN_CHANNELS ) {
        return;
    }
    else{
        nIdx = g_utf_cal_ctxt.pLUT[nChannelNumber];
        if (g_utf_cal_ctxt.pLUT[nChannelNumber] != INVALID_CHANNEL_NUMBER) {
            g_utf_cal_ctxt.pChannelData[nIdx].nChannelNumber = INVALID_CHANNEL_NUMBER;
            ChainMskIdx = 0;
            while (ChainMskIdx < MAX_NUMBER_OF_CHAINMASKIDX) {
                ModeIdx = 0;
                while (ModeIdx < MAX_NUMBER_OF_MODES) {
                    g_utf_cal_ctxt.pChannelData[nIdx].aChainMask[ChainMskIdx].aMode[ModeIdx].nSize = 0;
                    ModeIdx ++;
                }
                ChainMskIdx ++;
            }
        }

        g_utf_cal_ctxt.pLUT[nChannelNumber] = INVALID_CHANNEL_NUMBER;
    }
#endif

    return;

} /* END  _utf_cal_clear_channel_data */


/*===============================================================================

FUNCTION : _utf_cal_get_channel_index

Description:
    This function is used get the index of the channel calibration storage reference.
    On Everyband only a subset of the total available channels are scanned.
    Hence in order to save memory and only keep the calibration data of the channels
    scanned, a lookup table keeps stack of the indexes of the scanned channels.

Parameters:
    nChannelNumber : The Channel number whose index is being queried.

Return Value :
    A_UINT32 : Channel index.

===============================================================================*/
#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)
A_UINT32 _utf_cal_get_channel_index(A_UINT32 nChannelNumber)
{
    A_UINT32 nChannelIdx = INVALID_CHANNEL_NUMBER;

    if (nChannelNumber < MAX_SCAN_CHANNELS ) {
        nChannelIdx = g_utf_cal_ctxt.pLUT[nChannelNumber];
    }

    return nChannelIdx;

} /* END  _utf_cal_get_channel_index */
#endif


/*===============================================================================

FUNCTION : _utf_cal_assign_channel_index

Description:
    This function is used to assign a particular index to access the channel
    calibration data. On Everyband only a subset of the total available channels
    are scanned.Hence in order to save memory and only keep the calibration data
    of the channels scanned, a lookup table keeps stack of the indexes of the
    scanned channels.

Parameters:
    nChannelNumber : The channel number whose index needs to be assigned

Return Value :
    The Channel Index.

===============================================================================*/
#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)
A_UINT32 _utf_cal_assign_channel_index(A_UINT32 nChannelNumber)
{
    A_UINT32 nIdx = INVALID_CHANNEL_NUMBER;
    //A_PRINTF_ONCE("_utf_cal_assign_channel_index \n ");
    if ( nChannelNumber < MAX_SCAN_CHANNELS &&
         g_utf_cal_ctxt.pLUT[nChannelNumber] == INVALID_CHANNEL_NUMBER ) {

        for (nIdx = 0; nIdx < MAX_CALIBRATION_CHANNELS ;nIdx ++) {
            if (g_utf_cal_ctxt.pChannelData[nIdx].nChannelNumber == INVALID_CHANNEL_NUMBER ){
                g_utf_cal_ctxt.pChannelData[nIdx].nChannelNumber = nChannelNumber;
                g_utf_cal_ctxt.pLUT[nChannelNumber] = nIdx;
                //A_PRINTF_ONCE("_utf_cal_assign_channel_index nChannelNumber = %d nIdx = %d \n",nChannelNumber,nIdx);
                break;
            }
        }

    }

    return nIdx;

} /* END _utf_cal_assign_channel_index */
#endif


/*===============================================================================

FUNCTION : _utf_cal_init

Description:
    This function is called after HOST sends a wmi command back to the firmware
    to initialize WMI_INIT_CMDID.It is used to allocate the calibration context
    and find out which host memory chunks are allocated by the HOST to store
    the requested calibration data.

Parameters:
    pdev : Pointer to the Peer Data structure.
    num_chunks : Total number of chunks allocated by the HOST for all Firmware
    modules requesting HOST memory.
    p_chunks : Pointer to the HOST chunk array.
    HOST memory is allocated in chunks not contiquously. Each chunk
    is labeled for the module that is requesting a certain amount of memory.
    HOST memory is allocated in multiples of chunks to meet the total aggregate
    of the memory requirement of firmware module that has registered its needs in
    a prior api such as _utf_cal_register

Return Value :
    None.

===============================================================================*/
A_STATUS _utf_cal_init(void)
{
    A_STATUS nResult = A_ERROR;

#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)

    /*
     * Currently using DRAM. But should move to SRAM once we have memory freed up.
     */
    g_utf_cal_ctxt.pChannelData =
        (utf_cal_channel_data *) A_ALLOCRAM_BY_ARENA(
            ALLOCRAM_DEFAULT_ARENA,
            sizeof(utf_cal_channel_data) * g_utf_cal_ctxt.nTotalNumberOfChannels
            );
    A_ASSERT( g_utf_cal_ctxt.pChannelData != NULL );

    A_MEMZERO(g_utf_cal_ctxt.pChannelData,
              (sizeof(utf_cal_channel_data) * g_utf_cal_ctxt.nTotalNumberOfChannels));

    /*
     * We allocate a lookup table because only a subset of the spectrum channels
     * are going to be scanned and stored.
     */
    g_utf_cal_ctxt.pLUT =
        (A_UINT8 *) A_ALLOCRAM_BY_ARENA(
            ALLOCRAM_DEFAULT_ARENA,
            sizeof(A_UINT8) * g_utf_cal_ctxt.nMaxChannels);
    A_ASSERT( g_utf_cal_ctxt.pLUT != NULL );
    A_MEMZERO(g_utf_cal_ctxt.pLUT,(sizeof(A_UINT8) * g_utf_cal_ctxt.nMaxChannels));
    utf_cal_clear_data();
    nResult = A_OK;

#endif

    return nResult;

} /* END  _utf_cal_init */


/*===============================================================================

FUNCTION : _utf_cal_store_data

Description:
    This function is used to store the specified channel's calibration data on
    the host.The data is stored and retrieved with an index which is a subset
    of the total number of channels since at a given instance there are maximum
    of 35 channels that are scanned.So calibration data is stored
    on a forst come first serve basis.

Parameters:
    nChannelNumber :  The Channel Number whose Calibration data is queried.
    nBufferAddr : Address of the Buffer allocated by the caller. The size of
    the buffer is 3KB for now due to memory constraints.
    nSegmentSize :  Size of the data buffer to be queried from the HOST.
    nTotalBufferSize :
    This is the total Calibration data size. IT only comes into focus when
    we are trying to extract the home channel data. This data is greater than
    the one shot 3KB buffer that is used for other scan channels . Hence
    the caller has to call this api multiple times to get the entire
    calibration data.
    nSegmentNumber :  This is again for the home channel calibration storage.

Return Value :
    A_STATUS :
    A_OK is returned if the data for the channel being queried is stored on
       the HOST memory.
    A_ERROR is returned if the Channel Calibration data is not stored or if
       its an invalid channel.

===============================================================================*/
A_STATUS _utf_cal_store_data(
             A_UINT32 nChannelNumber,
             A_UINT32 nBufferAddr,
             A_UINT32 nSize,
             A_UINT32 nTotalBufferSize,
             A_UINT32 nSegmentNumber,
             A_UINT32 nChainmask,
             A_UINT8 nMode)

{
    A_STATUS eResult = A_ERROR;
    //A_PRINTF_ONCE("_utf_cal_store_data nChainmask = %d,nMode = %d, nChannelNumber = %d \n",nChainmask,nMode,nChannelNumber);
#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)

    A_UINT32 nIdx,nOffset, nChainMskIdx, nSegmentSize;

    /*
     * For a Home channel store we need multiple iterations of store.
     * This is due to the limitation of the copy buffer size.
     */
    nChainMskIdx = _utf_cal_get_chainmaskIdx(nChainmask);
    if ((nMode >= MAX_NUMBER_OF_MODES) ||(nChainMskIdx >= MAX_NUMBER_OF_CHAINMASKIDX)) {
      A_PRINTF_ONCE("_utf_cal_store_data Error !!\n");
        return eResult;
    }
     //A_PRINTF_ONCE("_utf_cal_store_data nSize = %d, (nTotalBufferSize/2) = %d \n",nSize, (nTotalBufferSize/2));
    if ((( nSize <= (nTotalBufferSize/2)) &&( nTotalBufferSize == CHANNEL_CAL_COPY_BUFF_SIZE)) ||
        (nSize == nTotalBufferSize)) {
        nIdx = _utf_cal_assign_channel_index(nChannelNumber);
        if (nIdx == INVALID_CHANNEL_NUMBER ){
            return eResult;
        }

        if (nSize == nTotalBufferSize) {
            nSegmentSize = nTotalBufferSize;
            nOffset = 0;
        }
        else {
            nSegmentSize = CHANNEL_CAL_COPY_BUFF_SIZE/2;
            nOffset = nSegmentNumber * (CHANNEL_CAL_COPY_BUFF_SIZE/2);
        }

        /*
         * If this is the first segment, reset the size and offset.
         */
        if (nSegmentNumber == 0) {
                g_utf_cal_ctxt.pChannelData[nIdx].aChainMask[nChainMskIdx].aMode[nMode].nSize = 0;
        }

        eResult = wal_qcache_memcpy_from_target_to_host(
               (g_utf_cal_ctxt.pChannelData[nIdx].aChainMask[nChainMskIdx].aMode[nMode].nHostCalibrationBufAddr + nOffset),
               nBufferAddr, nSegmentSize);
        //A_PRINTF_ONCE("wal_qcache_memcpy_from_target_to_host-> eResult = %d,addr = %d,\n",eResult,(g_utf_cal_ctxt.pChannelData[nIdx].aChainMask[nChainMskIdx].aMode[nMode].nHostCalibrationBufAddr + nOffset));
        g_utf_cal_ctxt.pChannelData[nIdx].aChainMask[nChainmask -1].aMode[nMode].nSize += nSize;
    }
#endif
    //A_PRINTF_ONCE("_utf_cal_store_data nChainMskIdx = %d,eResult = %d,",nChainMskIdx,eResult);
    return eResult;


} /* END  _utf_cal_store_data */


/*===============================================================================

FUNCTION : _utf_cal_get_data

Description:
    This function is used to get the stored on the host. The data is stored and
    retreived with an index which is a subset of the total number of channels
    since at a given instance there are maximum of 35 channels that are scanned.

Parameters:
    nChannelNumber :  The Channel Number whose Calibration data is queried.
    nBufferAddr : Address of the Buffer allocated by the caller. The size of
    the buffer is 3KB for now due to memory constraints.
    nSegmentSize :  Size of the data buffer to be queried from the HOST.
    nTotalBufferSize :
    This is the total Calibration data size. It only comes into focus when
    we are trying to extract the home channel data. This data is greater than
    the one shot 3KB buffer that is used for other scan channels . Hence
    the caller has to call this api multiple times to get the entire calibration
    data.
    nSegmentNumber :  This is again for the home channel calibration storage.

Return Value :
    A_STATUS :
    A_OK is returned if the data for the channel being queried is retreived from
       the HOST memory.
    A_ERROR is returned if the Channel is not stored or if its an invalid channel.

===============================================================================*/
A_STATUS _utf_cal_get_data(
             A_UINT32 nChannelNumber,
             A_UINT32 nBufferAddr,
             A_UINT32 nSegmentSize,
             A_UINT32 nTotalBufferSize,
             A_UINT32 nSegmentNumber,
             A_UINT32 nChainmask,
             A_UINT8 nMode)
{
    A_STATUS eResult = A_ERROR;
    //A_PRINTF_ONCE("_utf_cal_get_data nChainmask = %d,nMode = %d, nChannelNumber = %d \n",nChainmask,nMode,nChannelNumber);
#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)
    A_UINT32 nIdx,nOffset,nChainMskIdx,nSize;

    nChainMskIdx = _utf_cal_get_chainmaskIdx(nChainmask);
    if ((nMode >= MAX_NUMBER_OF_MODES) ||(nChainMskIdx >= MAX_NUMBER_OF_CHAINMASKIDX)) {
      A_PRINTF_ONCE("_utf_cal_get_data Error !!\n");
        return eResult;
    }
    //A_PRINTF_ONCE("_utf_cal_store_data nSegmentSize = %d, (nTotalBufferSize/2) = %d \n",nSegmentSize, (nTotalBufferSize/2));
    if ((( nSegmentSize <= (nTotalBufferSize/2)) &&( nTotalBufferSize == CHANNEL_CAL_COPY_BUFF_SIZE)) ||
        (nSegmentSize == (nTotalBufferSize))) {
        nIdx = _utf_cal_get_channel_index(nChannelNumber);
        if (nIdx == INVALID_CHANNEL_NUMBER ){
            return eResult;
        }
        if (nSegmentSize == nTotalBufferSize) {
            nSize = nTotalBufferSize;
            nOffset = 0;
        }
        else {
            nSize = CHANNEL_CAL_COPY_BUFF_SIZE/2;
            nOffset = nSegmentNumber * (CHANNEL_CAL_COPY_BUFF_SIZE/2);
        }

        eResult = wal_qcache_memcpy_from_host_to_target((A_UINT32)nBufferAddr,
                  (g_utf_cal_ctxt.pChannelData[nIdx].aChainMask[nChainMskIdx].aMode[nMode].nHostCalibrationBufAddr + nOffset),
                                                            nSize,0);

     //   A_PRINTF_ONCE("wal_qcache_memcpy_from_host_to_target eResult = %d,addr = %d,\n",eResult,(g_utf_cal_ctxt.pChannelData[nIdx].aChainMask[nChainMskIdx].aMode[nMode].nHostCalibrationBufAddr + nOffset));

    }
#endif

    return eResult;

} /* END  _utf_cal_get_data */


/*===============================================================================

FUNCTION : _utf_cal_clear_data

Description:
    This function is used clear all calibration channel references that are
    populated on a first come first serve basis.

Parameters:
    None.

Return Value:
    None.

===============================================================================*/
void _utf_cal_clear_data(void)
{
#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)
    A_UINT32 nIdx;
    A_UINT8 ModeIdx,ChainMskIdx;

    for (nIdx=0;nIdx < MAX_CALIBRATION_CHANNELS;nIdx ++) {
        g_utf_cal_ctxt.pChannelData[nIdx].nChannelNumber = INVALID_CHANNEL_NUMBER;
        ChainMskIdx = 0;
        while (ChainMskIdx < MAX_NUMBER_OF_CHAINMASKIDX) {
            ModeIdx = 0;
            while (ModeIdx < MAX_NUMBER_OF_MODES) {
                g_utf_cal_ctxt.pChannelData[nIdx].aChainMask[ChainMskIdx].aMode[ModeIdx].nSize = 0;
                ModeIdx ++;
            }
        ChainMskIdx ++;
        }
    }

    for (nIdx=0;nIdx < MAX_SCAN_CHANNELS;nIdx ++) {
        g_utf_cal_ctxt.pLUT[nIdx] = INVALID_CHANNEL_NUMBER;
    }

#endif


} /* END  _utf_cal_clear_data */

/*===============================================================================

FUNCTION : _utf_cal_get_channel_data

Description:
    This function is used to obtain the channel specifics for calibration
    caching feature by the upper layers.

Parameters:


Return Value : None.

===============================================================================*/
utf_cal_ctxt * _utf_cal_get_ctxt(void)
{
#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)
    g_utf_cal_ctxt.nTotalNumberOfChannels = MAX_CALIBRATION_CHANNELS;
    g_utf_cal_ctxt.nHomeChannelRegistrationID = UTF_HOME_CHANNEL_CAL_HOST_MEM_REQ_ID;
    g_utf_cal_ctxt.nHomeChannelBufferSize = CHANNEL_CAL_COPY_BUFF_SIZE;
    g_utf_cal_ctxt.nMaxChannels = MAX_SCAN_CHANNELS;
    return &g_utf_cal_ctxt;
#else
    return NULL;
#endif


} /* END  wal_cal_get_ctxt */


/*===============================================================================

FUNCTION : _utf_cal_get_chainmaskIdx

Description:
    This function is used to obtain the chainmask index into the UTF cal storage
    structure.

Parameters:


Return Value : None.

===============================================================================*/
A_UINT8 _utf_cal_get_chainmaskIdx(A_UINT32 chainmask)
{
#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)
    A_UINT8 nIdx;

    for (nIdx = 0;nIdx < sizeof(ChainMaskToIdxLut) / sizeof(ChainMaskToIdxLut[0]); nIdx ++ ) {
        if (ChainMaskToIdxLut[nIdx] == chainmask ) {
          //A_PRINTF_ONCE("_utf_cal_get_chainmaskIdx nChainmaskIdx = %d \n",nIdx);
            return nIdx;
      }
    }
#endif
    return INVALID_CHAINMASK_IDX;


} /* END  wal_cal_get_ctxt */


#ifndef DISABLE_FUNCTION_INDIRECTION
WAL_CAL_API_FN _utf_cal_api = {
    _utf_cal_store_data,
    _utf_cal_get_data,
    _utf_cal_clear_data,
    _utf_cal_clear_channel_data,
    _utf_cal_init,
    _utf_cal_get_ctxt,
};
#endif

