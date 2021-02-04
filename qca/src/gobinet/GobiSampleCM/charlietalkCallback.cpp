/*====================================================================*
 *
 *   FILE:
 *     charlietalkCallback.cpp
 *
 *   DESCRIPTION:
 *     contains the implementation of each charlietalk CM callback function;
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

#include <syslog.h>
#include <uci.h>

/*====================================================================*
 * custom header files;
 *--------------------------------------------------------------------*/
#include "charlietalkError.h"
#include "charlietalk.h"
#include "charlietalkCallback.h"
#include "Gobi3000Translation.h"
#include "GobiConnectionMgmtAPIEnums.h"

/*====================================================================*
 * program variables;
 *--------------------------------------------------------------------*/

int iface_count;
char *iface_names[MAX_LENGTH];
extern GOBIHANDLE handle;
extern FILE *fp;

void DeleteChannelBlockList()
{
   struct uci_context *context = NULL;
   struct uci_package *uci_wireless = NULL;
   struct uci_ptr ptr;
   char *errormessage[1], wifi_iface[MAX_LENGTH];

   context = uci_alloc_context();
   if(context == NULL)
   {
      uci_get_errorstr(context, errormessage, NULL);
      TRACE_MSG(LOG_INFO, fp, "%s\n", errormessage[0]);
      return;
   }

   if(uci_load(context, "wireless", &uci_wireless))
   {
      uci_get_errorstr(context, errormessage, NULL);
      TRACE_MSG(LOG_INFO, fp, "%s\n", errormessage[0]);
      uci_free_context(context);
      return;
   }
   for(int i = 0; i < iface_count; i++)
   {
      snprintf(wifi_iface, sizeof(wifi_iface), "wireless.%s.channel_block_list", iface_names[i]);
      if(uci_lookup_ptr(context, &ptr, wifi_iface, true) != UCI_OK)
      {
         uci_get_errorstr(context, errormessage, NULL);
         TRACE_MSG(LOG_INFO, fp, "%s\n", errormessage[0]);
         continue;
      }
      TRACE_MSG(LOG_INFO, fp, "Deleting channel_block_list from %s\n", iface_names[i]);
      if(uci_delete(context, &ptr) != UCI_OK)
      {
         uci_get_errorstr(context, errormessage, NULL);
         TRACE_MSG(LOG_INFO, fp, "%s", errormessage[0]);
         continue;
      }
      TRACE_MSG(LOG_INFO, fp, "Deleting channel_block_list from %s : success\n", iface_names[i]);
      TRACE_MSG(LOG_INFO, fp, "Saving uci changes\n");
      if(uci_save(context, ptr.p) != 0)
      {
         uci_get_errorstr(context, errormessage, NULL);
         TRACE_MSG(LOG_INFO, fp, "%s\n", errormessage[0]);
         continue;
      }
      TRACE_MSG(LOG_INFO, fp, "Saving uci changes : success\n");
   }
   if(iface_count)
   {
      if(uci_commit(context, &ptr.p, false) == UCI_OK)
      {
         TRACE_MSG(LOG_INFO, fp, "Commit changes : success\n");
      }
      else
      {
         TRACE_MSG(LOG_INFO, fp, "Commit changes : failed\n");
      }
   }

   for(int i = 0; i < iface_count; i++)
   {
      free(iface_names[i]);
   }
   uci_free_context(context);
}

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
   INT8 *                     pThresholds )
{
   /* Set NAS event report callback request? */
   ULONG status = eGOBI_ERR_GENERAL;
   if ( (handle == 0)
   ||   (thresholdsSize > 0 && pThresholds == 0) )
   {
      return status;
   }

   /* Configure the QMI service */
   UINT8 req[1024] = { 0 };
   UINT8 * pData = (UINT8 *)&req[0];

   sQMIRawContentHeader * pTLV = (sQMIRawContentHeader *)pData;
   pTLV->mTypeID = 0x10;
   pTLV->mLength = (UINT16)sizeof( sNASSetEventReportRequest_SignalIndicator );
   pTLV->mLength += (UINT16)thresholdsSize;
   pData += sizeof( sQMIRawContentHeader );

   sNASSetEventReportRequest_SignalIndicator * pSI =
      (sNASSetEventReportRequest_SignalIndicator *)pData;
   pSI->mReportSignalStrength = 0;
   pSI->mNumberOfThresholds = thresholdsSize;
   pData += sizeof( sNASSetEventReportRequest_SignalIndicator );

   for (UINT8 i = 0; i < thresholdsSize; i++)
   {
      INT8 * pThresh = (INT8 *)pData;
      *pThresh = pThresholds[i];
      pData++;
   }

   sQMIRawContentHeader * pTLV1 = (sQMIRawContentHeader *)pData;
   pTLV1->mTypeID = 0x11;
   pTLV1->mLength = (UINT16)sizeof( sNASSetEventReportRequest_RFIndicator );
   pData += sizeof( sQMIRawContentHeader );

   sNASSetEventReportRequest_RFIndicator * pRFI =
      (sNASSetEventReportRequest_RFIndicator *)pData;
   pRFI->mReportRFInfo = 1;
   pData += sizeof( sNASSetEventReportRequest_RFIndicator);

   ULONG li = (ULONG)pData - (ULONG)&req[0];
   status = NASSetEventReport( handle, 2000, li, &req[0], 0, 0 );
   if (status != 0)
   {
      return status;
   }

   /* Configure the callback with the API */
   status = SetGenericCallback( handle, 3, 2, pCallback );
   return status;
}


/*===========================================================================
METHOD:
   BlockWifiChannels

DESCRIPTION:
   Finds available WiFi interfaces, call ConfigureWifiChannelList and set
blocked channel entries to wireless config file
=============================================================================*/

void BlockWifiChannels(char * channels)
{
   struct uci_context *context = NULL;
   struct uci_package *uci_wireless = NULL;
   struct uci_element *element, *iface_element;
   struct uci_ptr ptr;
   const char *wifi_interface = NULL, *wifi_hwmode = NULL, *wifi_disabled = NULL, *iface_device = NULL, *iface_name = NULL;
   char ath_interface[ATH_MAX_LENGTH], wifi_iface[MAX_LENGTH], *errormessage[MAX_LENGTH], *tmp = NULL;
   UINT8 channel_list[MAX_LENGTH];
   INT32 int_num, count = 0;

   tmp = channels;
   while(*tmp)
   {
      channel_list[count] = strtoul(tmp, &tmp, 10);
      if(!channel_list[count++] || (*tmp != ',') || (!*(tmp+1)))
      {
         break;
      }
      tmp++;
   }
   if(*tmp)
   {
      TRACE_MSG(LOG_ERR, fp, "lte_channel_table.txt: Invalid channel list\n");
      return;
   }

   context = uci_alloc_context();
   if(context == NULL)
   {
      uci_get_errorstr(context, errormessage, NULL);
      TRACE_MSG(LOG_INFO, fp, "%s\n", errormessage[0]);
      return;
   }

   if(uci_load(context, "wireless", &uci_wireless))
   {
      uci_get_errorstr(context, errormessage, NULL);
      TRACE_MSG(LOG_INFO, fp, "%s\n", errormessage[0]);
      uci_free_context(context);
      return;
   }

   DeleteChannelBlockList();
   iface_count = 0;
   uci_foreach_element(&uci_wireless->sections, element)
   {
      struct uci_section *section = uci_to_section(element);
      if(strcmp(section->type, "wifi-device") != 0)
      {
         continue;
      }

      wifi_interface = section->e.name;
      wifi_hwmode = uci_lookup_option_string(context, section, "hwmode");

      if( wifi_interface != NULL && (sscanf(wifi_interface, "wifi%d", &int_num) == 1) && wifi_hwmode != NULL
         && ((strstr(wifi_hwmode, "11n") != NULL) || (strstr(wifi_hwmode, "11b") != NULL) || (strstr(wifi_hwmode, "11g") != NULL)))
      {
         wifi_disabled = uci_lookup_option_string(context, section, "disabled");
         if((wifi_disabled == NULL) || (strcmp(wifi_disabled, "0") == 0))
         {
            TRACE_MSG(LOG_INFO, fp, "%s in enable state\n", wifi_interface);
            snprintf(ath_interface, sizeof(ath_interface),"ath%d", int_num);
            TRACE_MSG(LOG_INFO, fp, "Blocking channels on %s\n", ath_interface);
            ConfigureWifiChannelList(ath_interface, channel_list, count);
            TriggerAutomaticChannelSelection(ath_interface);
         }
         else
         {
            TRACE_MSG(LOG_INFO, fp, "%s in disable state\n", wifi_interface);
         }

         iface_device = iface_name = NULL;
         uci_foreach_element(&uci_wireless->sections, iface_element)
         {
            struct uci_section *iface_section = uci_to_section(iface_element);
            if(strcmp(iface_section->type, "wifi-iface") != 0)
            {
               continue;
            }
            iface_device = uci_lookup_option_string(context, iface_section, "device");
            if(iface_device != NULL && (strcmp(iface_device, wifi_interface) == 0))
            {
               iface_names[iface_count] = (char *) malloc(strlen(iface_section->e.name) + 1);
               memset(iface_names[iface_count], 0, strlen(iface_section->e.name) + 1);
               snprintf(iface_names[iface_count], strlen(iface_section->e.name), "%s", iface_section->e.name);
               iface_names[iface_count++][strlen(iface_section->e.name)] = '\0';
               iface_name = iface_section->e.name;
               break;
            }
         }

         if(!iface_name)
         {
            TRACE_MSG(LOG_INFO, fp, "No VAPs found for %s\n", wifi_interface);
            continue;
         }
         snprintf(wifi_iface, sizeof(wifi_iface), "wireless.%s.channel_block_list", iface_name);
         if(uci_lookup_ptr(context, &ptr, wifi_iface, true) != UCI_OK)
         {
            uci_get_errorstr(context, errormessage, NULL);
            TRACE_MSG(LOG_INFO, fp, "%s\n", errormessage[0]);
            continue;
         }
         if(ptr.o == NULL)
         {
            ptr.option = "channel_block_list";
         }
         ptr.value=channels;
         TRACE_MSG(LOG_INFO, fp, "Setting channel_block_list to %s\n", iface_name);
         if(uci_set(context, &ptr) != UCI_OK)
         {
            uci_get_errorstr(context, errormessage, NULL);
            TRACE_MSG(LOG_INFO, fp, "%s\n", errormessage[0]);
            continue;
         }
         TRACE_MSG(LOG_INFO, fp, "Setting channel_block_list to %s : success\n", iface_name);
         TRACE_MSG(LOG_INFO, fp, "Saving uci changes\n");
         if(uci_save(context, ptr.p) != 0)
         {
            uci_get_errorstr(context, errormessage, NULL);
            TRACE_MSG(LOG_INFO, fp, "%s\n", errormessage[0]);
            continue;
         }
         TRACE_MSG(LOG_INFO, fp, "Saving uci changes : success\n");
      }
   }
   if(iface_count)
   {
      if(uci_commit(context, &ptr.p, false) == UCI_OK)
      {
         TRACE_MSG(LOG_INFO, fp, "Commit changes : success\n");
      }
      else
      {
         TRACE_MSG(LOG_INFO, fp, "Commit changes : failed\n");
      }
      uci_free_context(context);
   }
}

/*===========================================================================
METHOD:
   ChannelChangeCallback (Public method)

DESCRIPTION:
   callback function gets called when there is RF band details changes
===========================================================================*/

void ChannelChangeCallback(
   ULONG                         svcID,
   ULONG                         msgID,
   GOBIHANDLE                    /* handle */,
   ULONG                         outLen,
   const BYTE *                  pOut )
{
   ULONG rf_interface, band, channel, status, low_channel, high_channel;
   FILE *inputFile = NULL;
   char wifi_buffer[MAX_LENGTH], wifi_channel[MAX_LENGTH];

   status = GetRFInfoDetails(&rf_interface, &band, &channel);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
      return;
   }

   TRACE_MSG(LOG_INFO, fp, "RF Interface : %lu\n", rf_interface);
   TRACE_MSG(LOG_INFO, fp, "Active Band : %lu\n", band);
   TRACE_MSG(LOG_INFO, fp, "Active Channel : %lu\n", channel);

   /* Check the LTE band which has chance to co-exist with WiFi */
   if(band != eQMINASBandClasses_EUTRABand7)
   {
      return;
   }

   inputFile = fopen ("/usr/lib/charlietalk/lte_channel_table.txt","r");
   if(inputFile == NULL)
   {
      TRACE_MSG(LOG_ERR, fp, "lte_channel_table.txt : %s\n", strerror(errno));
      return;
   }

   while(fgets(wifi_buffer, MAX_LENGTH, inputFile) != NULL)
   {
      if(*wifi_buffer == '#') /* Skip comment lines */
      {
         continue;
      }

      memset(wifi_channel, 0, MAX_LENGTH);
      if(sscanf(wifi_buffer,"%lu %lu %s", &low_channel, &high_channel, wifi_channel) != 3)
      {
         TRACE_MSG(LOG_ERR, fp, "lte_channel_table.txt: %s invalid table entry\n", wifi_buffer);
         return;
      }

      if(channel >= low_channel && channel <= high_channel)
      {
         BlockWifiChannels(wifi_channel);
      }
   }
   fclose(inputFile);
}
