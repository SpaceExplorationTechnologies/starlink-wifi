/*
 * tcmd_if_rfsim.h
 *
 *  Created on: Feb 11, 2014
 *      Author: sclee
 */

#ifndef TCMD_IF_RFSIM_H_
#define TCMD_IF_RFSIM_H_

#include <athdefs.h>

void* wmiTcmdInit(wlan_tcmd_dev_t *dev);
void wmi_tcmd_ready_event(void *tcmd_dev, A_UINT8 *macaddr);
void wmi_tcmd_cont_rx_reply_event(void *tcmd_dev, A_UINT16 len, A_UINT8 *buf);
void wmi_tc_cmds_reply_event(void *tcmd_dev, A_UINT16 len, A_UINT8 version, A_INT8* buf);

//Always return NULL since in sim there is no wmi
#define WMI_TCMD_INIT(dev)     \
	({wmiTcmdInit_sim(dev); NULL;})

#endif /* TCMD_IF_RFSIM_H_ */
