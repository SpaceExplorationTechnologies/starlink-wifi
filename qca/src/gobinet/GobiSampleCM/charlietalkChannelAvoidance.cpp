/*====================================================================*
 *
 *   FILE:
 *     charlietalkChannelAvoidance.cpp
 *
 *   DESCRIPTION:
 *     calls ioctl's to block WiFi channels whenever co-existence with
 *   LTE channel;
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
 * system header files;
 *--------------------------------------------------------------------*/

#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <linux/wireless.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <endian.h>
#include <sys/types.h>

#if __BYTE_ORDER == __BIG_ENDIAN
#define _BYTE_ORDER _BIG_ENDIAN
#elif __BYTE_ORDER == __LITTLE_ENDIAN
#define _BYTE_ORDER _LITTLE_ENDIAN
#else
#error "__BYTE_ORDER undefined"
#endif

/*====================================================================*
 * custom header files;
 *--------------------------------------------------------------------*/

#include "charlietalk.h"
#include "ieee80211_external.h"

/*====================================================================*
 * program constants;
 *--------------------------------------------------------------------*/

#define MAX_CHANNEL 255
#define OL_ATH_PARAM_SHIFT 0x1000
#define OL_ATH_PARAM_ACS_BLOCK_MODE 205
#define BLOCK_MODE 0x03

/*====================================================================*
 * program variables;
 *--------------------------------------------------------------------*/

extern FILE *fp;

/*===========================================================================
METHOD:
   ConfigureWifiChannelList

DESCRIPTION:
   calls ioctl to block channel per VAP

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG ConfigureWifiChannelList(const char *ifname, UINT8 *channel, INT32 count)
{
   INT32 sock = 0, i;
   INT32 char_ptr = 0;
   struct iwreq iwr = { 0 };
   struct ieee80211req_athdbg req = { 0 };

   ieee80211_user_chanlist_t chanlist = { 0 };

   memset(&req, 0, sizeof(struct ieee80211req_athdbg));

   if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
   {
      TRACE_MSG(LOG_ERR, fp, "ChannelBlock: Socket creation failure\n");
      return -1;
   }

   memset(&iwr, 0, sizeof(iwr));
   snprintf(iwr.ifr_name, sizeof(iwr.ifr_name),"%s", ifname);
   iwr.u.data.pointer = (void *) &req;
   iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));

   req.cmd = IEEE80211_DBGREQ_BLOCK_ACS_CHANNEL;

   /* chan memeber of ieee80211_user_chanlist_t structure is of type character pointer
      in previous version and character array in later version. we need to allocate
      memory if chan is of type character type */
   if(chanlist.chan == NULL)
   {
      if((chanlist.chan = (UINT8 *) malloc(sizeof(UINT8) * (count))) == NULL)
      {
         TRACE_MSG(LOG_INFO, fp, "ChannelBlock: memory allocation failure\n");
         return -1;
      }
      char_ptr = 1;
   }

   memcpy(chanlist.chan,channel,sizeof(chanlist.chan));
   chanlist.n_chan = count;
   req.data.param[0] = (int )&chanlist;

   if(ioctl(sock, IEEE80211_IOCTL_DBGREQ, &iwr) < 0)
   {
      TRACE_MSG(LOG_INFO, fp, "ChannelBlock: Set block channel list  failed\n");

      if(char_ptr)
         free(chanlist.chan);

      return -1;
   }

   if(char_ptr)
      free(chanlist.chan);

   if(!channel[0])
   {
      TRACE_MSG(LOG_INFO, fp, "List Flushed\n");
   }
   else
   {
      TRACE_MSG(LOG_INFO, fp, "ChannelBlock: %d channels are blocked from Channel selection algorithm\n", count);
      for(i=0; i<count; i++)
      {
         TRACE_MSG(LOG_INFO, fp, "Channel %d\n", channel[i]);
      }
   }
   return 0;
}

/*===========================================================================
METHOD:
   SetWifiChannelBlockingMode

DESCRIPTION:
   calls ioctl to set block mode for WiFi channel

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/


ULONG SetWifiChannelBlockingMode(const char *wname)
{
   INT32 sock;
   struct iwreq iwr;
   UINT32 mode;

   if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
   {
      TRACE_MSG(LOG_ERR, fp, "ChannelBlockMode: Socket creation failure\n");
      return -1;
   }

   memset(&iwr, 0, sizeof(iwr));
   memset(&mode, 0, sizeof(mode));
   snprintf(iwr.ifr_name, IFNAMSIZ, "%s", wname);
   iwr.u.mode = OL_ATH_PARAM_ACS_BLOCK_MODE | OL_ATH_PARAM_SHIFT;
   mode = BLOCK_MODE;
   memcpy(iwr.u.name + sizeof(unsigned int), &mode, sizeof(mode));

   if(ioctl(sock, ATH_HAL_IOCTL_SETPARAM, &iwr) < 0)
   {
      TRACE_MSG(LOG_ERR, fp, "ChannelBlockMode: set block mode failed for %s\n", wname);
      return -1;
   }
   return 0;
}

/*===========================================================================
METHOD:
   TriggerAutomaticChannelSelection

DESCRIPTION:
   calls ioctl to trigger ACS

RETURN VALUE:
   int      -      Error code
===========================================================================*/

int TriggerAutomaticChannelSelection(const char *ath_interface)
{
   INT32 sock;
   struct iwreq iwr;

   if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
   {
      TRACE_MSG(LOG_ERR, fp, "TriggerAutomaticChannelSelection: Socket creation failure\n");
      return -1;
   }

   memset(&iwr, 0, sizeof(iwr));
   snprintf(iwr.ifr_name, sizeof(iwr.ifr_name), "%s", ath_interface);
   iwr.u.freq.e = 0;
   iwr.u.freq.m = 0; /* setting channel as 0 will trigger ACS */

   if (ioctl(sock, SIOCSIWFREQ, &iwr) < 0)
   {
      TRACE_MSG(LOG_ERR, fp, "Triggering ACS failed\n");
      return -1;
   }
   close(sock);
   return 0;
}
