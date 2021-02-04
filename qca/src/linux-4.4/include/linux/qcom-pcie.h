/* Copyright (c) 2012-2014,2018 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __QCOM_PCIE_H
#define __QCOM_PCIE_H

enum qcom_pcie_event {
	QCOM_PCIE_EVENT_INVALID = 0,
	QCOM_PCIE_EVENT_LINKDOWN = 0x1,
	QCOM_PCIE_EVENT_LINKUP = 0x2,
};

struct qcom_pcie_notify {
	enum qcom_pcie_event event;
	void *user;
	void *data;
	u32 options;
};

struct qcom_pcie_register_event {
	u32 events;
	void *user;
	void (*callback)(struct qcom_pcie_notify *notify);
	struct qcom_pcie_notify notify;
	u32 options;
};


/**
 * qcom_pcie_register_event - register an event with PCIe bus driver.
 * @reg:	event structure
 *
 * This function gives PCIe endpoint device drivers an option to register
 * events with PCIe bus driver.
 *
 * Return: 0 on success, negative value on error
 */
int qcom_pcie_register_event(struct qcom_pcie_register_event *reg);

/**
 * qcom_pcie_deregister_event - deregister an event with PCIe bus driver.
 * @reg:	event structure
 *
 * This function gives PCIe endpoint device drivers an option to deregister
 * events with PCIe bus driver.
 *
 * Return: 0 on success, negative value on error
 */
int qcom_pcie_deregister_event(struct qcom_pcie_register_event *reg);

#endif
