/*====================================================================*
 *
 *   FILE:
 *     charlietalk.cpp
 *
 *   DESCRIPTION:
 *     QTI QMI connection manager;
 *
 *
 *   Copyright (c) 2015, The Linux Foundation. All rights reserved.
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

#include <uci.h>

/*====================================================================*
 * Include files;
 *--------------------------------------------------------------------*/

#include "charlietalk.h"
#include "charlietalkError.h"
#include "Gobi3000Translation.h"
#include "charlietalkCallback.h"

/*====================================================================*
 *   program global variables;
 *--------------------------------------------------------------------*/

GOBIHANDLE handle;
ULONG SessionID = 0xFFFFFFFF; // Assume failure initially
ULONG FailureCode = 0xFFFFFFFF;
FILE *fp;

/*===========================================================================
METHOD:
   StartDataSession (Public Method)

DESCRIPTION:
   Starts network interface and parse valid session ID

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG StartDataSession(ULONG outputLength, BYTE * outputMessage)
{
   ULONG status;
   status = WDSStartNetworkInterface (handle, TIMEOUT, 0, 0, &outputLength, outputMessage);
   if(status != eGOBI_ERR_NONE)
   {
      return status;
   }

   // Parse data session and get session ID
   status = ParseStartDataSession( outputLength, outputMessage, &SessionID, &FailureCode);
   if(status != eGOBI_ERR_NONE)
   {
      return status;
   }
   TRACE_MSG(LOG_INFO, fp, "Session started with session id : %lu\n", SessionID);
   return eGOBI_ERR_NONE;
}

/*===========================================================================
METHOD:
   Disconnect (Public Method)

DESCRIPTION:
   Terminates the charlietalkd gracefully after proper clean up
===========================================================================*/

void Disconnect(int signal_number)
{
   ULONG status;
   BYTE inputMessage[MAX_LENGTH];
   ULONG inputLength = MAX_LENGTH;

   DeleteChannelBlockList();
   status = PackStopDataSession(&inputLength, inputMessage, SessionID);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
   }

   status = WDSStopNetworkInterface(handle, TIMEOUT, inputLength, inputMessage, 0, 0);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
   }

   TRACE_MSG(LOG_INFO, fp, "Session stopped with session id : %lu\n", SessionID);
   status = GobiDisconnect(handle);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
   }
   TRACE_MSG(LOG_INFO, fp, "Charlietalk stopped");
   fclose(fp);
   closelog();
   exit(0);
}

/*===========================================================================
METHOD:
   signal_setup (Public Method)

DESCRIPTION:
   Register function pointers for handling corresponding signals
===========================================================================*/

void signal_setup()
{
   signal(SIGTERM, Disconnect);
   signal(SIGINT, Disconnect);
}

/*===========================================================================
METHOD:
   qmux_fill_buffer (Public Method)

DESCRIPTION:
   Fills the buffer values before calling WDSMuxBinding

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG qmux_fill_buffer(ULONG *buffer_length, UINT8 *buffer, size_t buffer_size)
{
   if(buffer_size < MUX_BUFFER_SIZE)
      return eGOBI_ERR_BUFFER_SZ;

   *buffer_length = MUX_BUFFER_SIZE;
   *((UINT8  *)(buffer)) = PERIPHERAL_END_POINT_TYPE;
   *((UINT16 *)(buffer + 1)) = PERIPHERAL_END_POINT_LENGTH;
   *((UINT32 *)(buffer + 3)) = PERIPHERAL_END_POINT_VALUE;
   *((UINT32 *)(buffer + 7)) = PERIPHERAL_INTERFACE_NUM;
   *((UINT8  *)(buffer + 11)) = MUX_ID_TYPE;
   *((UINT16 *)(buffer + 12)) = MUX_ID_LENGTH;
   *((UINT8  *)(buffer + 14)) = MUX_ID_VALUE;
   *((UINT8  *)(buffer + 15)) = CLIENT_TYPE;
   *((UINT16 *)(buffer + 16)) = CLIENT_LENGTH;
   *((UINT32 *)(buffer + 18)) = CLIENT_VALUE;
   return eGOBI_ERR_NONE;
}

/*===========================================================================
METHOD:
   ParseGetNetworkDetails (Public Method)

DESCRIPTION:
   Parse Network details such as IP Address, Subnet Mask, Gateway, primary
   and secondary DNS

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG ParseGetNetworkDetails( ULONG outputLength, BYTE * outputMessage)
{
   ULONG ipAddress, subnetMask, gateway, primaryDNS, secondaryDNS, status;
   char command[MAX_LENGTH];
   //Parse IP Address
   status = ParseGetIPAddress(outputLength, outputMessage, &ipAddress);
   if(status != eGOBI_ERR_NONE)
   {
      return status;
   }
   snprintf(command, sizeof(command), "%lu.%lu.%lu.%lu", EXTRACT_BYTE(ipAddress,3), EXTRACT_BYTE(ipAddress,2), \
   EXTRACT_BYTE(ipAddress,1), EXTRACT_BYTE(ipAddress, 0));
   TRACE_MSG(LOG_INFO, fp, "IPAddress : %s\n", command);
   memset(command, 0, sizeof(command));

   //Parse Subnet mask
   status = ParseGetSubnetMask(outputLength, outputMessage, &subnetMask);
   if(status != eGOBI_ERR_NONE)
   {
      return status;
   }
   snprintf(command, sizeof(command), "%lu.%lu.%lu.%lu", EXTRACT_BYTE(subnetMask,3), EXTRACT_BYTE(subnetMask,2), \
   EXTRACT_BYTE(subnetMask,1), EXTRACT_BYTE(subnetMask,0));
   TRACE_MSG(LOG_INFO, fp, "SubnetMask : %s\n", command);
   memset(command, 0, sizeof(command));

   //Parse Gateway
   status = ParseGetGateway(outputLength, outputMessage, &gateway);
   if(status != eGOBI_ERR_NONE)
   {
      return status;
   }
   snprintf(command, sizeof(command), "%lu.%lu.%lu.%lu", EXTRACT_BYTE(gateway,3), EXTRACT_BYTE(gateway,2), \
   EXTRACT_BYTE(gateway,1), EXTRACT_BYTE(gateway,0));
   TRACE_MSG(LOG_INFO, fp, "Gateway : %s\n", command);
   memset(command, 0, sizeof(command));

   //Parse primary and secondary DNS
   status = ParseGetDNSSettings(outputLength, outputMessage, &primaryDNS, &secondaryDNS);
   if(status != eGOBI_ERR_NONE)
   {
      return status;
   }
   snprintf(command, sizeof(command), "%lu.%lu.%lu.%lu", EXTRACT_BYTE(primaryDNS,3), EXTRACT_BYTE(primaryDNS,2), \
   EXTRACT_BYTE(primaryDNS,1), EXTRACT_BYTE(primaryDNS,0));
   TRACE_MSG(LOG_INFO, fp, "Primary dns : %s\n", command);
   snprintf(command, sizeof(command), "%lu.%lu.%lu.%lu", EXTRACT_BYTE(secondaryDNS,3), EXTRACT_BYTE(secondaryDNS,2), \
   EXTRACT_BYTE(secondaryDNS,1), EXTRACT_BYTE(secondaryDNS,0));
   TRACE_MSG(LOG_INFO, fp, "Secondary dns : %s\n", command);
   memset(command, 0,sizeof(command));
   return eGOBI_ERR_NONE;
}
/*===========================================================================
METHOD:
   GetRFInfoDetails (Public Method)

DESCRIPTION:
   Retrieve and parse the RF Band details such as RF Interface, Band and Channel

RETURN VALUE:
   ULONG      -      Error code
===========================================================================*/

ULONG GetRFInfoDetails(ULONG *rf_interface, ULONG *band, ULONG *channel)
{
   BYTE inputMessage [MAX_LENGTH];
   ULONG inputLength = MAX_LENGTH;
   ULONG instancelist [MAX_LENGTH];
   ULONG * instanceitem = instancelist;
   ULONG instances = MAX_INSTANCES;
   ULONG status;

   status = NASGetRFInfo (handle, TIMEOUT, 0, 0, &inputLength, inputMessage);
   if(status != eGOBI_ERR_NONE)
   {
      return status;
   }

   status = ParseGetRFInfo (inputLength, inputMessage, (BYTE *)(&instances), (BYTE *)(instancelist));
   if(status != eGOBI_ERR_NONE)
   {
      return status;
   }
   if(instances < 1)
   {
      TRACE_MSG(LOG_ERR, fp, "Invalid number of instances\n");
      return -1;
   }
   *rf_interface = *instanceitem++;
   *band = *instanceitem++;
   *channel = *instanceitem;

   return eGOBI_ERR_NONE;
}

/*====================================================================*
 *
 *   int main (int argc, char * argv []);
 *
 *
 *--------------------------------------------------------------------*/

int main (int argc, char * argv [])

{
   const char * device = GOBI_DEVICENAME;
   INT8 thresholds[MIN_LENGTH];
   BYTE inputMessage [MAX_LENGTH], outputMessage[MAX_LENGTH];
   ULONG inputLength = MAX_LENGTH, outputLength = MAX_LENGTH;
   ULONG status = 0;
   ULONG services_count = 3;
   ULONG services [] =
   {
      QMIWDS,
      QMIDMS,
      QMINAS
   };

   // Logging
   openlog("charlietalkd", LOG_PID, LOG_DAEMON);

   fp = fopen("/tmp/charlietalk", "a+");
   if(fp == NULL)
   {
      syslog(LOG_ERR, "/tmp/charlietalk: %s", strerror(errno));
      return -1;
   }

   TRACE_MSG(LOG_INFO, fp, "Charlietalkd started\n");
   // Register to handle signals
   signal_setup();

   // Connecting to Gobi device
   status = GobiConnect(device, &services_count, services, &handle);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
      return -1;
   }

   //Fill up qmux buffer
   status = qmux_fill_buffer(&inputLength, inputMessage, sizeof(inputMessage));
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
      return -1;
   }

   // Binding the qmux port
   status = WDSMuxBinding(handle, TIMEOUT, inputLength, &inputMessage[0], &outputLength, outputMessage);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
      return -1;
   }

   // Registering for NAS event (channel change)
   status = SetNASEventReportCB(ChannelChangeCallback, 1, &thresholds[0]);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
      return -1;
   }

   // Starting Data Session
   outputLength = sizeof(outputMessage);
   status = StartDataSession(outputLength, outputMessage);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
      return -1;
   }

   //Get IP Address
   outputLength = sizeof(outputMessage);
   status = PackGetIPAddress(&inputLength, inputMessage);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
      return -1;
   }

   //Get Current WDS Settings
   status = WDSGetCurrentSettings(handle, TIMEOUT, inputLength, &inputMessage[0], &outputLength, outputMessage);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
      return -1;
   }

   // Parse Network details
   status = ParseGetNetworkDetails(outputLength, outputMessage);
   if(status != eGOBI_ERR_NONE)
   {
      TRACE_MSG(LOG_ERR, fp, "%s : %lu\n", (char *) errorMessage(status), status);
      return -1;
   }

   // Parse RFInfo details
   ChannelChangeCallback(NAS_SERVICE_ID,  NAS_EVENT_REPORT_MSG_ID, handle, 0, 0);

   while (1)
   {
      sleep(1);
   }
}
