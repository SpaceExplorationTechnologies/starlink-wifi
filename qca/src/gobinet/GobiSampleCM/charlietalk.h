/*====================================================================*
 *
 *   FILE:
 *     charlietalk.h
 *
 *   DESCRIPTION:
 *     Contains function declarations, macros and variables needed for
 *     needed for charlietalk CM
 *
 *
 *   Copyright (c) 2016, The Linux Foundation. All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are met:
 *
 *   *  Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   *  Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   *  Neither the name of The Linux Foundation nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 *
 *--------------------------------------------------------------------*/

/*====================================================================*
 * pragmas;
 *--------------------------------------------------------------------*/

#pragma once

/*====================================================================*
 * system header files;
 *--------------------------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#if defined(__GLIBC__) || defined(__UCLIBC__)
#include <error.h>
#endif
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <syslog.h>

/*====================================================================*
 * program header files;
 *--------------------------------------------------------------------*/

#include "StdAfx.h"
#include "GobiConnectionMgmtAPI.h"

/*====================================================================*
 *   program constants;
 *--------------------------------------------------------------------*/

#define QMIWDS 1
#define QMIDMS 2
#define QMINAS 3
#define GOBI_DEVICENAME "/dev/qcqmi0";
#define TIMEOUT 300000
#define MAX_LENGTH 1024
#define MIN_LENGTH 8
#define ATH_MAX_LENGTH 14
#define EXTRACT_BYTE(value,position) \
        ((value & (0xFF << ( position * 8))) >> (position * 8))
#define MAX_INSTANCES 1

#define NAS_SERVICE_ID 3
#define NAS_EVENT_REPORT_MSG_ID 2

// qmux buffer values
#define MUX_BUFFER_SIZE 22
#define PERIPHERAL_END_POINT_TYPE 0x10
#define PERIPHERAL_END_POINT_LENGTH 0x08
#define PERIPHERAL_END_POINT_VALUE 0x02 // HSUSB
#define PERIPHERAL_INTERFACE_NUM 0x04
#define MUX_ID_TYPE 0x11
#define MUX_ID_LENGTH 0x01
#define MUX_ID_VALUE 0x81
#define CLIENT_TYPE 0x13
#define CLIENT_LENGTH 0x04
#define CLIENT_VALUE 0x01 //tethered type

//logging

#define TRACE_MSG(log_level, fp, format,...) { \
         fprintf(fp, format, ##__VA_ARGS__); \
         fflush(fp); \
         syslog(log_level, format, ##__VA_ARGS__); }
/*===========================================================================
METHOD:
   StartDataSession (Public Method)

DESCRIPTION:
   Starts network interface and parse valid session ID

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG StartDataSession(
      ULONG                         outputLength,
      BYTE *                        outputMessage);

/*===========================================================================
METHOD:
   Disconnect (Public Method)

DESCRIPTION:
   Terminates the charlietalkd gracefully after proper clean up
===========================================================================*/

void Disconnect(int signal_number);

/*===========================================================================
METHOD:
   signal_setup (Public Method)

DESCRIPTION:
   Register function pointers for handling corresponding signals
===========================================================================*/

void signal_setup(void);

/*===========================================================================
METHOD:
   qmux_fill_buffer (Public Method)

DESCRIPTION:
   Fills the buffer values before calling WDSMuxBinding

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG qmux_fill_buffer(
      ULONG *                       buffer_length,
      UINT8 *                       buffer,
      size_t                        buffer_size);

/*===========================================================================
METHOD:
   ParseGetNetworkDetails (Public Method)

DESCRIPTION:
   Parse Network details such as IP Address, Subnet Mask, Gateway, primary
   and secondary DNS

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG ParseGetNetworkDetails(
      ULONG                         outputLength,
      BYTE *                        outputMessage);
/*===========================================================================
METHOD:
   GetRFInfoDetails (Public Method)

DESCRIPTION:
   Retrieve and parse the RF Band details such as RF Interface, Band and Channel

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG GetRFInfoDetails(
      ULONG *                       rf_interface,
      ULONG *                       band,
      ULONG *                       channel);

/*===========================================================================
METHOD:
   ConfigureWifiChannelList

DESCRIPTION:
   calls ioctl to block channel per VAP

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG ConfigureWifiChannelList(
      const char *                  ifname,
      UINT8 *                       channel,
      INT32                         count);

/*===========================================================================
METHOD:
   SetWifiChannelBlockingMode

DESCRIPTION:
   calls ioctl to set block mode for WiFi channel

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG SetWifiChannelBlockingMode(
      const char *                  wname);

/*===========================================================================
METHOD:
   TriggerAutomaticChannelSelection

DESCRIPTION:
   calls ioctl to trigger ACS

RETURN VALUE:
   int      -      Error code
===========================================================================*/

int TriggerAutomaticChannelSelection(
      const char *                  ath_interface);
