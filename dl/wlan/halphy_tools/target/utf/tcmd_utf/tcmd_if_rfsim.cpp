/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
#ifdef UTFSIM
#include "rfsim_sock.h"
#include <athdefs.h>

//Used by legHostIF.c
#define MAX_UTF_EVENT_LENGTH 2048
A_UINT8 dataPayload[MAX_UTF_EVENT_LENGTH]; //MAX_PAYLOAD_LEN(256)*8 (2k buffer max we receive 8 segments.. 256 bytes each)

struct wlan_tcmd_dev_t;

extern "C" {
	void* wmiTcmdInit(wlan_tcmd_dev_t *dev);
	void wmi_tcmd_ready_event(void *tcmd_dev, A_UINT8 *macaddr);
	void wmi_tcmd_cont_rx_reply_event(void *tcmd_dev, A_UINT16 len, A_UINT8 *buf);
	void wmi_tc_cmds_reply_event(void *tcmd_dev, A_UINT16 len, A_UINT8 version, A_INT8* buf);

	extern A_STATUS tcmd_parse_cmd(wlan_tcmd_dev_t *dev, A_UINT8 *buf, A_UINT32 length);

	//Only support LE machine
	A_UINT32 swapEnable=0;
}



//Support only one dev now. Need change for DBDC.
static wlan_tcmd_dev_t *tcmd_dev;

static void proc_tcmd_pkt(void* buf, ssize_t len);

//Only one socket!!
static rfsim_sock	tcmd_sock(proc_tcmd_pkt);

void* wmiTcmdInit(wlan_tcmd_dev_t *dev)
{
	tcmd_dev = dev;

	if(tcmd_sock.start_server(5000) < 0)
		goto init_failed;

	return dev;

init_failed:
	return NULL;
}

void wmi_tcmd_ready_event(void *tcmd_dev, A_UINT8 *macaddr)
{
	//No need to do anything.
	return;
}

void wmi_tcmd_cont_rx_reply_event(void *tcmd_dev, A_UINT16 len, A_UINT8 *buf)
{
    wmi_tc_cmds_reply_event(tcmd_dev, len, 0, (A_INT8*)buf);
}

void wmi_tc_cmds_reply_event(void *tcmd_dev, A_UINT16 len, A_UINT8 version, A_INT8* buf)
{
    //TCMD hardcoded the first 4 bytes to be the len. If it is changed, we need to change it here.
    A_UINT8 reply[2048];

    if (len + 4 > 2048) {
        printf("Not enough reply buffer!!");
        len = 2048 - 4;
    }

    *((unsigned long*)reply) = (unsigned long) len;
    memcpy(reply+sizeof(unsigned long), buf, len);

	if (tcmd_dev) {
		tcmd_sock.rfsim_send(reply, len + sizeof(unsigned long));
	}
}

static void proc_tcmd_pkt(void* buf, ssize_t len)
{
	tcmd_parse_cmd(tcmd_dev, (A_UINT8 *)buf, (A_UINT32) len);
}
#endif
