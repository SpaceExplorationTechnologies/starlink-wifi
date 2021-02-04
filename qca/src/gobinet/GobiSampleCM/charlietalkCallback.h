/*===========================================================================
FILE:
  charlietalkCallback.h

DESCRIPTION:
   Contains the declaration of each charlietalk CM callback function,
   structures needed for these callbacks and message IDs for each callback.

Copyright (c) 2016, The Linux Foundation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.


THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
===========================================================================*/

//---------------------------------------------------------------------------
// Pragmas
//---------------------------------------------------------------------------
#pragma once

//---------------------------------------------------------------------------
// Include Files
//---------------------------------------------------------------------------
#include "GobiCMDLL.h"

/*===========================================================================
METHOD:
   SetNASEventReportCB (Public Method)

DESCRIPTION:
   Calls NASSetEventReport/SetGenericCallback

PARAMETERS:
   pCallback      [ I ] - Callback function pointer
   thresholdsSize [ I ] - Threshold size
   pThresholds    [ I ] - Array of thresholds

RETURN VALUE:
   ULONG
===========================================================================*/

ULONG SetNASEventReportCB(
   tFNGenericCallback         pCallback,
   BYTE                       thresholdsSize,
   INT8 *                     pThresholds );

/*===========================================================================
METHOD:
   ChannelChangeCallback (Public method)

DESCRIPTION:
   callback function gets called when there is RF band details changes
===========================================================================*/

// NAS Channel Change callback
void ChannelChangeCallback(
      ULONG                         svcID,
      ULONG                         msgID,
      GOBIHANDLE                    handle,
      ULONG                         outLen,
      const BYTE *                  pOut );
/*===========================================================================
METHOD:
   BlockWifiChannels

DESCRIPTION:
   Finds available WiFi interfaces, call ConfigureWifiChannelList and set
blocked channel entries to wireless config file
=============================================================================*/

void BlockWifiChannels(
      char *                        channels);

void DeleteChannelBlockList();
