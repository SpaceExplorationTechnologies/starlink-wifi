/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#if !defined(_GENERICUTFCMD_H)
#define _GENERICUTFCMD_H

void initGenericUtfCmd(void);

typedef enum {
	GENERICUTFCMD_ID_DEFAULT = 0,
	GENERICUTFCMD_ID_SECGLUTCAL,
} GENERICUTFCMDID;

typedef enum {
	GENERICUTFCMD_INCOMP,
	GENERICUTFCMD_DONE,
} GENERICUTFDONE;

typedef enum {
	GENERICUTFCMD_STATUS_SUCCESS = 0,
	GENERICUTFCMD_STATUS_FAILURE,
} GENERICUTFSTATUS;


#endif //#if !defined(_GENERICUTFCMD_H)

