/*====================================================================*
 *
 *   FILE:
 *     charlietalkError.h
 *
 *   DESCRIPTION:
 *     Define Error messages and convert error codes to error messages;
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

/*===========================================================================
 * Include files
 *=========================================================================*/

#include "charlietalkError.h"
#include "StdAfx.h"

/*====================================================================*
 *   program variables;
 *--------------------------------------------------------------------*/

const char * api_errmsg[] = {	"Success",			// eGOBI_ERR_NONE
				"General error",		// eGOBI_ERR_GENERAL
				"Internal error",		// eGOBI_ERR_INTERNAL
				"Memory error",			// eGOBI_ERR_MEMORY
				"Invalid argument",		// eGOBI_ERR_INVALID_ARG
				"Buffer too small",		// eGOBI_ERR_BUFFER_SZ
				"Unable to detect Gobi device",	// eGOBI_ERR_NO_DEVICE
				"Invalid Gobi device ID",	// eGOBI_ERR_INVALID_DEVID
				"No connection to Gobi device",	// eGOBI_ERR_NO_CONNECTION
				"Unable to obtain QMI interface",	// eGOBI_ERR_IFACE
				"Unable to connect to QMI interface",	// eGOBI_ERR_CONNECT
				"Unable to schedule QMI request",	// eGOBI_ERR_REQ_SCHEDULE
				"Error sending QMI request",		// eGOBI_ERR_REQUEST
				"Error receiving QMI response",		// eGOBI_ERR_RESPONSE
				"Timeout while sending QMI request",	// eGOBI_ERR_REQUEST_TO
				"Timeout while receiving QMI response",	// eGOBI_ERR_RESPONSE_TO
				"Malformed QMI response received",	// eGOBI_ERR_MALFORMED_RSP
				"QMI response insufficient or invalid",	// eGOBI_ERR_INVALID_RSP
				"Invalid file path",			// eGOBI_ERR_INVALID_FILE
				"Unable to open file",			// eGOBI_ERR_FILE_OPEN
				"Unable to move file",			// eGOBI_ERR_FILE_COPY
				"Unable to open service control mgr",	// eGOBI_ERR_QDL_SCM
				"Unable to detect QDL service",		// eGOBI_ERR_NO_QDL_SVC
				"Unable to obtain QDL service info",	// eGOBI_ERR_NO_QDL_SVC_INFO
				"Unable to locate QSL service",		// eGOBI_ERR_NO_QDL_SVC_PATH
				"Unable to reconfigure QDL service",	// eGOBI_ERR_QDL_SVC_CFG
				"Unable to interface to QDL service",	// eGOBI_ERR_QDL_SVC_IFACE
				"Unable to set Gobi device offline",	// eGOBI_ERR_OFFLINE
				"Unable to obtain QMI response for shutdown/reset request", // eGOBI_ERR_RESET
				"No available signal",			// eGOBI_ERR_NO_SIGNAL
				"Reserved",				// eGOBI_ERR_MULTIPLE_DEVICES
				"Unable to interface to device driver",	// eGOBI_ERR_DRIVER
				"No cancelable operation is pending",	// eGOBI_ERR_NO_CANCELABLE_OP
				"Error canceling outstanding operation",// eGOBI_ERR_CANCEL_OP
				"QDL image data CRC error",		// eGOBI_ERR_QDL_CRC
				"QDL image data parsing error",		// eGOBI_ERR_QDL_PARSING
				"QDL image authentication error",	// eGOBI_ERR_QDL_AUTH
				"QDL image write error",		// eGOBI_ERR_QDL_WRITE
				"QDL image size error",			// eGOBI_ERR_QDL_OPEN_SIZE
				"QDL image type error",			// eGOBI_ERR_QDL_OPEN_TYPE
				"QDL memory protection error",		// eGOBI_ERR_QDL_OPEN_PROT
				"QDL image not required",		// eGOBI_ERR_QDL_OPEN_SKIP
				"QDL general error",			// eGOBI_ERR_QDL_ERR_GENERAL
				"QDL BAR mode error",			// eGOBI_ERR_QDL_BAR_MODE
};

const char * qmi_errmsg[] = {	"Success",
				"QMI message was not formulated correctly by the control point " \
				"or the message was corrupted during transmission", 		//eQMI_ERR_MALFORMED_MSG
				"Device could not allocate memory to formulate QMI response",	//eQMI_ERR_NO_MEMORY
				"Unexpected error occurred during processing",			//eQMI_ERR_INTERNAL
				"Processing aborted",			//eQMI_ERR_ABORTED
				"QMI client IDs have been exhausted",	//eQMI_ERR_CLIENT_IDS_EXHAUSTED
				"Unable to abort QMI transaction",	//eQMI_ERR_UNABORTABLE_TRANSACTION
				"Invalid QMI client ID",		//eQMI_ERR_INVALID_CLIENT_ID
				"No thresholds were provided",		//eQMI_ERR_NO_THRESHOLDS
				"Handle provided in the QMI request is not valid",		//eQMI_ERR_INVALID_HANDLE
				"Profile specified is invalid",		//eQMI_ERR_INVALID_PROFILE
				"Invalid PIN ID specified",		//eQMI_ERR_INVALID_PIN_ID
				"Incorrect PIN ID specified",		//eQMI_ERR_INCORRECT_PIN
				"No network found",			//eQMI_ERR_NO_NETWORK_FOUND
				"Call failed",				//eQMI_ERR_CALL_FAILED
				"Device is not in a call",		//eQMI_ERR_OUT_OF_CALL
				"Requested information element has not been provisioned "\
				"on the device",				//eQMI_ERR_NOT_PROVISIONED
				"Mandatory QMI TLV not provided",	//eQMI_ERR_MISSING_ARG
				"Unknown error",			//eQMI_ERR_18
				"Argument passed in a QMI TLV is larger than the available "\
				"storage in the device", 		//eQMI_ERR_ARG_TOO_LONG
				"Unknown error",			//eQMI_ERR_20
				"Unknown error",			//eQMI_ERR_21
				"Invalid Tx ID specified",		//eQMI_ERR_INVALID_TX_ID
				"Device currently in a call",		//eQMI_ERR_DEVICE_IN_USE
				"The selected operation is not supported by the network",	//eQMI_ERR_OP_NETWORK_UNSUPPORTED
				"The selected operation is not supported by the device",	//eQMI_ERR_OP_DEVICE_UNSUPPORTED
				"Requested operation would have no effect",			//eQMI_ERR_NO_EFFECT
				"No space for a profile is available",	//eQMI_ERR_NO_FREE_PROFILE
				"Invalid PDP type specified",		//eQMI_ERR_INVALID_PDP_TYPE
				"Invalid technology preference specified",			//eQMI_ERR_INVALID_TECH_PREF
				"Invalid profile type specified",	//eQMI_ERR_INVALID_PROFILE_TYPE
				"Invalid service type specified",	//eQMI_ERR_INVALID_SERVICE_TYPE
				"Invalid register action specified",	//eQMI_ERR_INVALID_REGISTER_ACTION
				"Invalid PS attach/detach action specified",			//eQMI_ERR_INVALID_PS_ATTACH_ACTION
				"Authentication of supplied information element failed",	//eQMI_ERR_AUTHENTICATION_FAILED
				"Indicates that the PIN is blocked; an unblock operation "\
				"needs to be issued",			//eQMI_ERR_PIN_BLOCKED
				"Indicates that the PIN is permanently blocked; the UIM is "\
				"unusable",				//eQMI_ERR_PIN_ALWAYS_BLOCKED
				"UIM initialized has not completed",	//eQMI_ERR_UIM_UNINITIALIZED
				"Maximum QOS requests in use",		//eQMI_ERR_MAX_QOS_REQUESTS_IN_USE
				"Incorrect flow filter",		//eQMI_ERR_INCORRECT_FLOW_FILTER
				"Unaware Network QOS",			//eQMI_ERR_NETWORK_QOS_UNAWARE
				"Invalid QOS ID",			//eQMI_ERR_INVALID_QOS_ID
				"Number not supported",			//eQMI_ERR_REQUESTED_NUM_UNSUPPORTED
				"Interface not found",			//eQMI_ERR_INTERFACE_NOT_FOUND
				"Flow suspended",			//eQMI_ERR_FLOW_SUSPENDED
				"Invalid data format",			//eQMI_ERR_INVALID_DATA_FORMAT
				"General error",			//eQMI_ERR_GENERAL
				"Unknown error",			//eQMI_ERR_UNKNOWN
				"A specified argument is invalid",	//eQMI_ERR_INVALID_ARG
				"A specified index is invalid",		//eQMI_ERR_INVALID_INDEX
				"No information element exists at the specified memory storage "\
				"designation",				//eQMI_ERR_NO_ENTRY
				"The memory storage specified in the request is full", //eQMI_ERR_DEVICE_STORAGE_FULL
				"Device not in a ready state",		//eQMI_ERR_DEVICE_NOT_READY
				"Network not in a ready state",		//eQMI_ERR_NETWORK_NOT_READY
				"Error provided in SMS cause code",	//eQMI_ERR_WMS_CAUSE_CODE
				"The message could not be sent",	//eQMI_ERR_WMS_MESSAGE_NOT_SENT
				"The message could not be delivered",	//eQMI_ERR_WMS_MESSAGE_DELIVERY_FAILURE
				"The message ID specified for the message is invalid", //eQMI_ERR_WMS_INVALID_MESSAGE_ID
				"The message is not encoded properly",	//eQMI_ERR_WMS_ENCODING
				"Maximum number of authentication failures has been reached", //eQMI_ERR_AUTHENTICATION_LOCK
				"The selected operating mode transition from the current operating "\
				"mode is invalid", 			//eQMI_ERR_INVALID_TRANSITION
				"Unknown error",			//eQMI_ERR_61
				"Unknown error",			//eQMI_ERR_62
				"Unknown error",			//eQMI_ERR_63
				"Unknown error",			//eQMI_ERR_64
				"No tracking session has been started",	//eQMI_ERR_SESSION_INACTIVE
				"Current session does not allow this operation", //eQMI_ERR_SESSION_INVALID
				"Current tracking session was not started by this QMI control point",	//eQMI_ERR_SESSION_OWNERSHIP
				"Device GPS service resources insufficient for request",		//eQMI_ERR_INSUFFICIENT_RESOURCES
				"Device GPS service disabled",		//eQMI_ERR_DISABLED
				"Invalid operation specified",		//eQMI_ERR_INVALID_OPERATION
				"Invalid/unknown QMI command specified",//eQMI_ERR_INVALID_QMI_CMD
				"Message in memory contains a TPDU type that cannot be read as a raw "\
				"message",				//eQMI_ERR_WMS_TPDU_TYPE
				"The SMSC address specified is invalid",//eQMI_ERR_WMS_SMSC_ADDR
				"information element is unavailable at this point", //eQMI_ERR_INFO_UNAVAILABLE
				"Segment size too large",		//eQMI_ERR_SEGMENT_TOO_LONG
				"Segment order is incorrect",		//eQMI_ERR_SEGMENT_ORDER
				"Bundling not supported",		//eQMI_ERR_BUNDLING_NOT_SUPPORTED
				"Unknown error",			//eQMI_ERR_78
				"Policy mismatch",			//eQMI_ERR_POLICY_MISMATCH
				"SIM file not found",			//eQMI_ERR_SIM_FILE_NOT_FOUND
				"Extended internal error",		//eQMI_ERR_EXTENDED_EXTERNAL
				"Access to a required entity is not available", //eQMI_ERR_ACCESS_DENIED
				"The selected operating mode is invalid "\
				"with the current hardware setting",	//eQMI_ERR_HARDWARE_RESTRICTED
				"ACK not sent",				//eQMI_ERR_ACK_NOT_SENT
				"Unknown error",			//eQMI_ERR_85
				"Unknown error",			//eQMI_ERR_86
				"Unknown error",			//eQMI_ERR_87
				"Unknown error",			//eQMI_ERR_88
				"Unknown error",			//eQMI_ERR_89
				"Incompatible state",			//eQMI_ERR_INCOMPATIBLE_STATE
				"FDN restrict",				//eQMI_ERR_FDN_RESTRICT
				"SUPS failure cause",			//eQMI_ERR_SUPS_FAILURE_CAUSE
				"No radio",				//eQMI_ERR_NO_RADIO
				"Not supported",			//eQMI_ERR_NOT_SUPPORTED
				"No subscription",			//eQMI_ERR_95
				"Card call control failed",		//eQMI_ERR_CARD_CALL_CONTROL_FAILED
				"Network aborted"			//eQMI_ERR_NETWORK_ABORTED
};

/*===========================================================================
METHOD:
   errorMessage (Public Method)

DESCRIPTION:
   Returns the error message based on error code

RETURN VALUE:
   const char * - error message
===========================================================================*/

const char * errorMessage(ULONG err_no)
{
        if ((err_no < GOBI_ERR_MAXCOUNT) && (api_errmsg[err_no] != NULL))
        {
                return api_errmsg[err_no];
        }
        else if ((err_no >= QMI_ERR_BASE) && (err_no < ( QMI_ERR_BASE + QMI_ERR_MAXCOUNT)) \
                && (qmi_errmsg[err_no - QMI_ERR_BASE] != NULL))
        {
                return qmi_errmsg[err_no - QMI_ERR_BASE];
        }
        else
                return "Unknown error";
}
