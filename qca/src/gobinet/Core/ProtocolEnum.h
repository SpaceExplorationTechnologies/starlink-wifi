/*===========================================================================
FILE:
   ProtocolEnum.h

DESCRIPTION:
   Generic protocol enumerations and related methods

PUBLIC ENUMERATIONS AND METHODS:
   eProtocolType

   IsValid()
   IsQMIProtocol()
   IsQMIProtocolRX()
   IsQMIProtocolTX()
   IsDSEProtocol()
   IsDSEProtocolCmd()
   IsDSEProtocolRsp()
   IsDSEProtocolEvt()

Copyright (c) 2013, The Linux Foundation. All rights reserved.

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
// Definitions
//---------------------------------------------------------------------------

/*=========================================================================*/
// eProtocolType Enumeration
//
// NOTE: QMI protocol types need to be in the same order as eQMIService
// with RX added first then TX
/*=========================================================================*/
enum eProtocolType
{
   ePROTOCOL_ENUM_BEGIN = -1, 

   ePROTOCOL_COMMAND,            // 000 Protocol server command
   ePROTOCOL_AT,                 // 001 AT command protocol
   ePROTOCOL_NMEA,               // 002 NMEA (GPS) protocol
   ePROTOCOL_DIAG_RX,            // 003 DIAG protocol (incoming)
   ePROTOCOL_DIAG_TX,            // 004 DIAG protocol (outgoing)
   ePROTOCOL_DOWNLOAD_RX,        // 005 Download protocol (incoming)
   ePROTOCOL_DOWNLOAD_TX,        // 006 Download protocol (outgoing)
   ePROTOCOL_SDOWNLOAD_RX,       // 007 Streaming download protocol (incoming)
   ePROTOCOL_SDOWNLOAD_TX,       // 008 Streaming download protocol (outgoing)
   ePROTOCOL_QDL_RX,             // 009 QDL streaming protocol (incoming)
   ePROTOCOL_QDL_TX,             // 010 QDL streaming protocol (outgoing)

   ePROTOCOL_DSE_QDU_CMD = 30,   // 030 Device update protocol (command, TX)
   ePROTOCOL_DSE_QDU_RSP,        // 031 Device update protocol (response, RX)
   ePROTOCOL_DSE_QDU_EVT,        // 032 Device update protocol (event, RX)
   ePROTOCOL_DSE_QMBE_CMD,       // 033 MBB extensions protocol (command, TX)
   ePROTOCOL_DSE_QMBE_RSP,       // 034 MBB extensions protocol (response, RX)
   ePROTOCOL_DSE_QMBE_EVT,       // 035 MBB extensions protocol (event, RX)
   ePROTOCOL_DSE_QMUX_CMD,       // 036 Tunneled QMUX protocol (command, TX)
   ePROTOCOL_DSE_QMUX_RSP,       // 037 Tunneled QMUX protocol (response, RX)
   ePROTOCOL_DSE_QMUX_EVT,       // 038 Tunneled QMUX protocol (event, RX)

   ePROTOCOL_QMI_CTL_RX = 60,    // 060 QMI CTL protocol (incoming)
   ePROTOCOL_QMI_CTL_TX,         // 061 QMI CTL protocol (outgoing)
   ePROTOCOL_QMI_WDS_RX,         // 062 QMI WDS protocol (incoming)
   ePROTOCOL_QMI_WDS_TX,         // 063 QMI WDS protocol (outgoing)
   ePROTOCOL_QMI_DMS_RX,         // 064 QMI DMS protocol (incoming)
   ePROTOCOL_QMI_DMS_TX,         // 065 QMI DMS protocol (outgoing)
   ePROTOCOL_QMI_NAS_RX,         // 066 QMI NAS protocol (incoming)
   ePROTOCOL_QMI_NAS_TX,         // 067 QMI NAS protocol (outgoing)
   ePROTOCOL_QMI_QOS_RX,         // 068 QMI QOS protocol (incoming)
   ePROTOCOL_QMI_QOS_TX,         // 069 QMI QOS protocol (outgoing)
   ePROTOCOL_QMI_WMS_RX,         // 070 QMI WMS protocol (incoming)
   ePROTOCOL_QMI_WMS_TX,         // 071 QMI WMS protocol (outgoing)
   ePROTOCOL_QMI_PDS_RX,         // 072 QMI PDS protocol (incoming)
   ePROTOCOL_QMI_PDS_TX,         // 073 QMI PDS protocol (outgoing)
   ePROTOCOL_QMI_AUTH_RX,        // 074 QMI AUTH protocol (incoming)
   ePROTOCOL_QMI_AUTH_TX,        // 075 QMI AUTH protocol (outgoing)
   ePROTOCOL_QMI_AT_RX,          // 076 QMI AUTH protocol (incoming)
   ePROTOCOL_QMI_AT_TX,          // 077 QMI AUTH protocol (outgoing)
   ePROTOCOL_QMI_VOICE_RX,       // 078 QMI Voice protocol (incoming)
   ePROTOCOL_QMI_VOICE_TX,       // 079 QMI Voice protocol (outgoing)
   ePROTOCOL_QMI_CAT2_RX,        // 080 QMI CAT (new) protocol (incoming)
   ePROTOCOL_QMI_CAT2_TX,        // 081 QMI CAT (new) protocol (outgoing)
   ePROTOCOL_QMI_UIM_RX,         // 082 QMI UIM protocol (incoming)
   ePROTOCOL_QMI_UIM_TX,         // 083 QMI UIM protocol (outgoing)
   ePROTOCOL_QMI_PBM_RX,         // 084 QMI PBM protocol (incoming)
   ePROTOCOL_QMI_PBM_TX,         // 085 QMI PBM protocol (outgoing)
   ePROTOCOL_QMI_QCHAT_RX,       // 086 QMI QCHAT protocol (incoming)
   ePROTOCOL_QMI_QCHAT_TX,       // 087 QMI QCHAT protocol (outgoing)
   ePROTOCOL_QMI_RMTFS_RX,       // 088 QMI RMTFS protocol (incoming)
   ePROTOCOL_QMI_RMTFS_TX,       // 089 QMI RMTFS protocol (outgoing)
   ePROTOCOL_QMI_TEST_RX,        // 090 QMI Test protocol (incoming)
   ePROTOCOL_QMI_TEST_TX,        // 091 QMI Test protocol (outgoing)
   ePROTOCOL_QMI_LOC_RX,         // 092 QMI LOC protocol (incoming)
   ePROTOCOL_QMI_LOC_TX,         // 093 QMI LOC protocol (outgoing)
   ePROTOCOL_QMI_SAR_RX,         // 094 QMI PBM protocol (incoming)
   ePROTOCOL_QMI_SAR_TX,         // 095 QMI PBM protocol (outgoing)
   ePROTOCOL_QMI_IMSS_RX,        // 096 QMI IMSS protocol (incoming)
   ePROTOCOL_QMI_IMSS_TX,        // 097 QMI IMSS protocol (outgoing)
   ePROTOCOL_QMI_ADC_RX,         // 098 QMI ADC protocol (incoming)
   ePROTOCOL_QMI_ADC_TX,         // 099 QMI ADC protocol (outgoing)
   ePROTOCOL_QMI_CSD_RX,         // 100 QMI CSD protocol (incoming)
   ePROTOCOL_QMI_CSD_TX,         // 101 QMI CSD protocol (outgoing)
   ePROTOCOL_QMI_MFS_RX,         // 102 QMI MFS protocol (incoming)
   ePROTOCOL_QMI_MFS_TX,         // 103 QMI MFS protocol (outgoing)
   ePROTOCOL_QMI_TIME_RX,        // 104 QMI TIME protocol (incoming)
   ePROTOCOL_QMI_TIME_TX,        // 105 QMI TIME protocol (outgoing)
   ePROTOCOL_QMI_TS_RX,          // 106 QMI TS protocol (incoming)
   ePROTOCOL_QMI_TS_TX,          // 107 QMI TS protocol (outgoing)
   ePROTOCOL_QMI_TMD_RX,         // 108 QMI TMD protocol (incoming)
   ePROTOCOL_QMI_TMD_TX,         // 109 QMI TMD protocol (outgoing)
   ePROTOCOL_QMI_SAP_RX,         // 110 QMI SAP protocol (incoming)
   ePROTOCOL_QMI_SAP_TX,         // 111 QMI SAP protocol (outgoing)
   ePROTOCOL_QMI_WDA_RX,         // 112 QMI WDA protocol (incoming)
   ePROTOCOL_QMI_WDA_TX,         // 113 QMI WDA protocol (outgoing)
   ePROTOCOL_QMI_TSYNC_RX,       // 114 QMI TSYNC protocol (incoming)
   ePROTOCOL_QMI_TSYNC_TX,       // 115 QMI TSYNC protocol (outgoing)
   ePROTOCOL_QMI_RFSA_RX,        // 116 QMI RFSA protocol (incoming)
   ePROTOCOL_QMI_RFSA_TX,        // 117 QMI RFSA protocol (outgoing)
   ePROTOCOL_QMI_CSVT_RX,        // 118 QMI CSVT protocol (incoming)
   ePROTOCOL_QMI_CSVT_TX,        // 119 QMI CSVT protocol (outgoing)
   ePROTOCOL_QMI_QCMAP_RX,       // 120 QMI QCMAP protocol (incoming)
   ePROTOCOL_QMI_QCMAP_TX,       // 121 QMI QCMAP protocol (outgoing)
   ePROTOCOL_QMI_IMSP_RX,        // 122 QMI IMSP protocol (incoming)
   ePROTOCOL_QMI_IMSP_TX,        // 123 QMI IMSP protocol (outgoing)
   ePROTOCOL_QMI_IMSVT_RX,       // 124 QMI IMSVT protocol (incoming)
   ePROTOCOL_QMI_IMSVT_TX,       // 125 QMI IMSVT protocol (outgoing)
   ePROTOCOL_QMI_IMSA_RX,        // 126 QMI IMSA protocol (incoming)
   ePROTOCOL_QMI_IMSA_TX,        // 127 QMI IMSA protocol (outgoing)
   ePROTOCOL_QMI_COEX_RX,        // 128 QMI COEX protocol (incoming)
   ePROTOCOL_QMI_COEX_TX,        // 129 QMI COEX protocol (outgoing)
   ePROTOCOL_QMI_35_RX,          // 130 QMI service ID 35 protocol (incoming)
   ePROTOCOL_QMI_35_TX,          // 131 QMI service ID 35 protocol (outgoing)
   ePROTOCOL_QMI_PDC_RX,         // 132 QMI PDC protocol (incoming)
   ePROTOCOL_QMI_PDC_TX,         // 133 QMI PDC protocol (outgoing)
   ePROTOCOL_QMI_37_RX,          // 134 QMI service ID 37 protocol (incoming)
   ePROTOCOL_QMI_37_TX,          // 135 QMI service ID 37 protocol (outgoing)
   ePROTOCOL_QMI_STX_RX,         // 136 QMI STX protocol (incoming)
   ePROTOCOL_QMI_STX_TX,         // 137 QMI STX protocol (outgoing)
   ePROTOCOL_QMI_BIT_RX,         // 138 QMI BIT protocol (incoming)
   ePROTOCOL_QMI_BIT_TX,         // 139 QMI BIT protocol (outgoing)
   ePROTOCOL_QMI_IMSRTP_RX,      // 140 QMI IMSRTP protocol (incoming)
   ePROTOCOL_QMI_IMSRTP_TX,      // 141 QMI IMSRTP protocol (outgoing)
   ePROTOCOL_QMI_RFRPE_RX,       // 142 QMI RFRPE protocol (incoming)
   ePROTOCOL_QMI_RFRPE_TX,       // 143 QMI RFRPE protocol (outgoing)
   ePROTOCOL_QMI_DSD_RX,         // 144 QMI DSD protocol (incoming)
   ePROTOCOL_QMI_DSD_TX,         // 145 QMI DSD protocol (outgoing)
   ePROTOCOL_QMI_SSCTL_RX,       // 146 QMI SSCTL protocol (incoming)
   ePROTOCOL_QMI_SSCTL_TX,       // 147 QMI SSCTL protocol (outgoing)

   ePROTOCOL_QMI_CAT_RX = 508,   // 508 QMI CAT protocol (incoming)
   ePROTOCOL_QMI_CAT_TX,         // 509 QMI CAT protocol (outgoing)
   ePROTOCOL_QMI_RMS_RX,         // 510 QMI RMS protocol (incoming)
   ePROTOCOL_QMI_RMS_TX,         // 511 QMI RMS protocol (outgoing)
   ePROTOCOL_QMI_OMA_RX,         // 512 QMI OMA protocol (incoming)
   ePROTOCOL_QMI_OMA_TX,         // 513 QMI OMA protocol (outgoing)

   ePROTOCOL_ENUM_END
};

/*===========================================================================
METHOD:
   IsValid (Inline Method)

DESCRIPTION:
   eProtocolType validity check

PARAMETERS:
   pt          [ I ] - Enum value being verified

RETURN VALUE:
   bool
===========================================================================*/
inline bool IsValid( eProtocolType pt )
{
   bool retVal = false;
   if ( (pt > ePROTOCOL_ENUM_BEGIN && pt <= ePROTOCOL_QDL_TX)
   ||   (pt >= ePROTOCOL_DSE_QDU_CMD && pt <= ePROTOCOL_DSE_QMUX_EVT)
   ||   (pt >= ePROTOCOL_QMI_CTL_RX && pt <= ePROTOCOL_QMI_RFRPE_TX)
   ||   (pt >= ePROTOCOL_QMI_CAT_RX && pt < ePROTOCOL_ENUM_END) )
   {
      retVal = true;
   }

   return retVal;
};

/*===========================================================================
METHOD:
   IsQMIProtocol (Inline Method)

DESCRIPTION:
   Does the passed in value represent a QMI protocol?

PARAMETERS:
   pt          [ I ] - Enum value being checked

RETURN VALUE:
   bool
===========================================================================*/
inline bool IsQMIProtocol( eProtocolType pt )
{
   bool retVal = false;
   if ( (pt >= ePROTOCOL_QMI_CTL_RX && pt <= ePROTOCOL_QMI_RFRPE_TX)
   ||   (pt >= ePROTOCOL_QMI_CAT_RX && pt < ePROTOCOL_ENUM_END) )
   {
      retVal = true;
   }

   return retVal;
};

/*===========================================================================
METHOD:
   IsQMIProtocolRX (Inline Method)

DESCRIPTION:
   Does the passed in value represent a QMI protocol and if so in the
   incoming direction?

PARAMETERS:
   pt          [ I ] - Enum value being checked

RETURN VALUE:
   bool
===========================================================================*/
inline bool IsQMIProtocolRX( eProtocolType pt )
{
   bool retVal = false;

   // QMI protocol values that are even are RX
   if ( (IsQMIProtocol( pt ) == true)
   &&   ((DWORD)pt % 2 == 0) )
   {
      retVal = true;
   }

   return retVal;
};

/*===========================================================================
METHOD:
   IsQMIProtocolTX (Inline Method)

DESCRIPTION:
   Does the passed in value represent a QMI protocol and if so in the
   outgoing direction?

PARAMETERS:
   pt          [ I ] - Enum value being checked

RETURN VALUE:
   bool
===========================================================================*/
inline bool IsQMIProtocolTX( eProtocolType pt )
{
   bool retVal = false;

   // QMI protocol values that are odd are TX
   if ( (IsQMIProtocol( pt ) == true)
   &&   ((DWORD)pt % 2 == 1) )
   {
      retVal = true;
   }

   return retVal;
};

/*===========================================================================
METHOD:
   IsDSEProtocol (Inline Method)

DESCRIPTION:
   Does the passed in value represent a DSE protocol?

PARAMETERS:
   pt          [ I ] - Enum value being checked

RETURN VALUE:
   bool
===========================================================================*/
inline bool IsDSEProtocol( eProtocolType pt )
{
   bool retVal = false;
   if (pt >= ePROTOCOL_DSE_QDU_CMD && pt <= ePROTOCOL_DSE_QMUX_EVT)
   {
      retVal = true;
   }

   return retVal;
};

/*===========================================================================
METHOD:
   IsDSEProtocolCmd (Inline Method)

DESCRIPTION:
   Does the passed in value represent a DSE protocol and if so is it a
   command?

PARAMETERS:
   pt          [ I ] - Enum value being checked

RETURN VALUE:
   bool
===========================================================================*/
inline bool IsDSEProtocolCmd( eProtocolType pt )
{
   bool retVal = false;

   if ( (IsDSEProtocol( pt ) == true)
   &&   ((DWORD)pt % 3 == 0) )
   {
      retVal = true;
   }

   return retVal;
};

/*===========================================================================
METHOD:
   IsDSEProtocolRsp (Inline Method)

DESCRIPTION:
   Does the passed in value represent a DSE protocol and if so is it a
   response?

PARAMETERS:
   pt          [ I ] - Enum value being checked

RETURN VALUE:
   bool
===========================================================================*/
inline bool IsDSEProtocolRsp( eProtocolType pt )
{
   bool retVal = false;

   if ( (IsDSEProtocol( pt ) == true)
   &&   ((DWORD)pt % 3 == 1) )
   {
      retVal = true;
   }

   return retVal;
};

/*===========================================================================
METHOD:
   IsDSEProtocolEvt (Inline Method)

DESCRIPTION:
   Does the passed in value represent a DSE protocol and if so is it an
   event?

PARAMETERS:
   pt          [ I ] - Enum value being checked

RETURN VALUE:
   bool
===========================================================================*/
inline bool IsDSEProtocolEvt( eProtocolType pt )
{
   bool retVal = false;

   if ( (IsDSEProtocol( pt ) == true)
   &&   ((DWORD)pt % 3 == 2) )
   {
      retVal = true;
   }

   return retVal;
};
