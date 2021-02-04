/*
 * Copyright (c) 2015, 2017 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/bitops.h>
#include <linux/regmap.h>
#include <linux/thermal.h>
#include <linux/io.h>
#include <linux/interrupt.h>
#include "tsens.h"

/* TSENS register data */
#define TSENS_CNTL_ADDR			0x4
#define TSENS_TRDY_TIMEOUT_US		20000
#define TSENS_THRESHOLD_MAX_CODE	0x3ff
#define TSENS_THRESHOLD_MIN_CODE	0x0
#define TSENS_SN_CTRL_EN		BIT(0)

#define TSENS_TM_TRDY			0x10e4
#define TSENS_TRDY_MASK			BIT(0)
#define TSENS_TM_CODE_BIT_MASK		0xfff
#define TSENS_TM_CODE_SIGN_BIT		0x800

#define TSENS_TM_INT_EN			0x1004
#define TSENS_TM_CRITICAL_INT_EN	BIT(2)
#define TSENS_TM_UPPER_INT_EN		BIT(1)
#define TSENS_TM_LOWER_INT_EN		BIT(0)

#define TSENS_TM_UPPER_INT_MASK(n)	(((n) & 0xffff0000) >> 16)
#define TSENS_TM_LOWER_INT_MASK(n)	((n) & 0xffff)
#define TSENS_TM_UPPER_LOWER_INT_STATUS		0x1008
#define TSENS_TM_UPPER_LOWER_INT_CLEAR		0x100c
#define TSENS_TM_UPPER_INT_CLEAR_SET(n)		(1 << (n + 16))
#define TSENS_TM_LOWER_INT_CLEAR_SET(n)		(1 << n)
#define TSENS_TM_UPPER_LOWER_INT_MASK		0x1010
#define TSENS_TM_UPPER_INT_SET(n)		(1 << (n + 16))
#define TSENS_TM_LOWER_INT_SET(n)               (1 << n)

#define TSENS_TM_CRITICAL_INT_STATUS		0x1014
#define TSENS_TM_CRITICAL_INT_CLEAR		0x1018
#define TSENS_TM_CRITICAL_INT_CLEAR_SET(n)	(1 << n)
#define TSENS_TM_CRITICAL_INT_MASK		0x101c

#define TSENS_TM_UPPER_LOWER_THRESHOLD(n)	((n * 4) + 0x1020)
#define TSENS_TM_UPPER_THRESHOLD_SET(n)		((n) << 12)
#define TSENS_TM_UPPER_THRESHOLD_VALUE_SHIFT(n)	((n) >> 12)
#define TSENS_TM_LOWER_THRESHOLD_VALUE(n)	((n) & 0xfff)
#define TSENS_TM_UPPER_THRESHOLD_VALUE(n)	(((n) & 0xfff000) >> 12)
#define TSENS_TM_UPPER_THRESHOLD_MASK		0xfff000
#define TSENS_TM_LOWER_THRESHOLD_MASK		0xfff
#define TSENS_TM_LOWER_THRESHOLD_CLEAR		0xfff000
#define TSENS_TM_UPPER_THRESHOLD_CLEAR		0xfff
#define TSENS_TM_UPPER_THRESHOLD_SHIFT		12

#define TSENS_TM_SN_CRITICAL_THRESHOLD_MASK	0xfff
#define TSENS_TM_SN_CRITICAL_THRESHOLD(n)	((n * 4) + 0x1060)
#define TSENS_TM_SN_STATUS			0x10a0
#define TSENS_TM_SN_STATUS_VALID_BIT		BIT(21)
#define TSENS_TM_SN_STATUS_CRITICAL_STATUS	BIT(19)
#define TSENS_TM_SN_STATUS_UPPER_STATUS		BIT(18)
#define TSENS_TM_SN_STATUS_LOWER_STATUS		BIT(17)
#define TSENS_TM_SN_LAST_TEMP_MASK		0xfff

#define MAX_SENSOR				16
#define VALID_SENSOR_START_IDX			4
#define MAX_TEMP				204 /* Celcius */
#define MIN_TEMP				0   /* Celcius */

/* Trips: from very hot to very cold */
enum tsens_trip_type {
	TSENS_TRIP_STAGE3 = 0,
	TSENS_TRIP_STAGE2,
	TSENS_TRIP_STAGE1,
	TSENS_TRIP_STAGE0,
	TSENS_TRIP_NUM,
};

static int get_temp_ipq807x(struct tsens_device *tmdev, int id, int *temp);

static void notify_uspace_tsens_fn(struct work_struct *work)
{
	struct tsens_sensor *s = container_of(work, struct tsens_sensor,
								notify_work);

	if (!s || !s->tzd)
		/* Do nothing. TSENS driver has not been registered yet */
		return;

	sysfs_notify(&s->tzd->device.kobj, NULL, "type");
}

static void tsens_scheduler_fn(struct work_struct *work)
{
	struct tsens_device *tmdev = container_of(work, struct tsens_device,
					tsens_work);
	int i, reg_thr, temp, th_upper = 0, th_lower = 0;
	u32 reg_val, reg_addr;

	/*Check whether TSENS is enabled */
	regmap_read(tmdev->map, TSENS_CNTL_ADDR, &reg_val);
	if (!(reg_val & TSENS_SN_CTRL_EN))
		return;

	/* Iterate through all sensors */
	for (i = 0; i < tmdev->num_sensors; i++) {

		/* Reset for each iteration */
		reg_thr = th_upper = th_lower = 0;

		regmap_read(tmdev->map, tmdev->sensor[i].status, &reg_val);

		/* Check whether the temp is valid */
		if (!(reg_val & TSENS_TM_SN_STATUS_VALID_BIT))
			continue;

		/* Check whether upper threshold is hit */
		if (reg_val & TSENS_TM_SN_STATUS_UPPER_STATUS) {
			reg_thr |= TSENS_TM_UPPER_INT_CLEAR_SET(i);
			reg_addr = TSENS_TM_UPPER_LOWER_INT_CLEAR;
			th_upper = 1;
		}
		/* Check whether lower threshold is hit */
		if (reg_val & TSENS_TM_SN_STATUS_LOWER_STATUS) {
			reg_thr |= TSENS_TM_LOWER_INT_CLEAR_SET(i);
			reg_addr = TSENS_TM_UPPER_LOWER_INT_CLEAR;
			th_lower = 1;
		}

		if (th_upper || th_lower) {
			regmap_write(tmdev->map, reg_addr, reg_thr);
			/* Notify user space */
			schedule_work(&tmdev->sensor[i].notify_work);

			if (!get_temp_ipq807x(tmdev, i, &temp))
				pr_info("Trigger (%d degrees) for sensor %d\n",
					temp, i);
		}
	}

	/* Sync registers */
	mb();
}

static irqreturn_t tsens_isr(int irq, void *data)
{
	struct tsens_device *tmdev = data;


	schedule_work(&tmdev->tsens_work);
	return IRQ_HANDLED;
}

static int init_ipq807x(struct tsens_device *tmdev)
{
	int ret, i;

	tmdev->iomem_base = init_common(tmdev);
	if (!tmdev->map)
		return -ENODEV;

	/* Store all sensor address for future use */
	for (i = 0; i < tmdev->num_sensors; i++) {
		tmdev->sensor[i].status = TSENS_TM_SN_STATUS + (i * 4);
		INIT_WORK(&tmdev->sensor[i].notify_work,
						notify_uspace_tsens_fn);
	}

	/* Enable interrupt registers */
	regmap_write(tmdev->map, TSENS_TM_INT_EN, TSENS_TM_CRITICAL_INT_EN
			| TSENS_TM_UPPER_INT_EN	| TSENS_TM_LOWER_INT_EN);

	/* Init tsens worker thread */
	INIT_WORK(&tmdev->tsens_work, tsens_scheduler_fn);

	/* Register and enable the ISR */
	ret = devm_request_irq(tmdev->dev, tmdev->tsens_irq, tsens_isr,
			IRQF_TRIGGER_RISING, "tsens_interrupt", tmdev);
	if (ret < 0) {
		pr_err("%s: request_irq FAIL: %d\n", __func__, ret);
		return ret;
	}

	enable_irq_wake(tmdev->tsens_irq);

	/* Sync registers */
	mb();
	return 0;
}

static void panic_notify_ipq807x(struct tsens_device *tmdev, int id)
{
	u32 code, trdy;
	const struct tsens_sensor *s = &tmdev->sensor[id];
	unsigned int try = 0;

	if (!s)
		return;

	if ((s->id < 0) || (s->id > (MAX_SENSOR - 1)))
		return;

	for(try = 0; try < 100; try++)
	{
		try++;
		trdy = readl(tmdev->iomem_base + TSENS_TM_TRDY);

		if (!(trdy & TSENS_TRDY_MASK))
			continue;

		code = readl(tmdev->iomem_base + s->status);

		/* Check whether the temp is valid */
		if (!(code & TSENS_TM_SN_STATUS_VALID_BIT))
			continue;

		pr_emerg("The reading for sensor %d is 0x%08x\n", s->id, code);
		return;
	}

	pr_emerg("Couldn't get reading for sensor %d\n", s->id);
	return;
}

static int get_temp_ipq807x(struct tsens_device *tmdev, int id, int *temp)
{
	int ret, last_temp;
	u32 code, trdy;
	const struct tsens_sensor *s = &tmdev->sensor[id];
	unsigned long timeout;

	if (!s)
		return -EINVAL;

	if ((s->id < 0) || (s->id > (MAX_SENSOR - 1)))
		return -EINVAL;

	timeout = jiffies + usecs_to_jiffies(TSENS_TRDY_TIMEOUT_US);
	do {
		ret = regmap_read(tmdev->map, TSENS_TM_TRDY, &trdy);
		if (ret)
			return ret;

		if (!(trdy & TSENS_TRDY_MASK))
			continue;

		ret = regmap_read(tmdev->map, s->status, &code);
		if (ret)
			return ret;

		/* Check whether the temp is valid */
		if (!(code & TSENS_TM_SN_STATUS_VALID_BIT))
			continue;

		last_temp = code & TSENS_TM_SN_LAST_TEMP_MASK;

		if (last_temp & TSENS_TM_CODE_SIGN_BIT)
			/* Sign extension for negative value */
			last_temp |= (~(TSENS_TM_CODE_BIT_MASK));

		*temp = last_temp/10;

		return 0;
	} while (time_before(jiffies, timeout));

	return -ETIMEDOUT;
}

static int set_trip_temp_ipq807x(void *data, int trip, int temp)
{
	unsigned int reg_th, reg_th_offset, reg_cri_th_offset;
	int ret = 0, th_cri, th_hi, th_lo;
	const struct tsens_sensor *s = data;
	struct tsens_device *tmdev;

	if (!s)
		return -EINVAL;

	if ((s->id < 0) || (s->id > (MAX_SENSOR - 1)))
		return -EINVAL;

	if ((temp < MIN_TEMP) && (temp > MAX_TEMP))
		return -EINVAL;

	/* Convert temp to the required format */
	temp = temp * 10;

	tmdev = s->tmdev;
	reg_th_offset = TSENS_TM_UPPER_LOWER_THRESHOLD(s->id);
	reg_cri_th_offset = TSENS_TM_SN_CRITICAL_THRESHOLD(s->id);

	regmap_read(tmdev->map, reg_cri_th_offset, &th_cri);
	regmap_read(tmdev->map, reg_th_offset, &reg_th);

	th_hi = TSENS_TM_UPPER_THRESHOLD_VALUE(reg_th);
	th_lo = TSENS_TM_LOWER_THRESHOLD_VALUE(reg_th);

	switch (trip) {
	case TSENS_TRIP_STAGE3:
		if (temp < th_hi) {
			ret = -EINVAL;
			break;
		}
		reg_th_offset = reg_cri_th_offset;
		reg_th = temp;
		break;
	case TSENS_TRIP_STAGE2:
		if ((temp <= th_lo) || (temp >= th_cri)) {
			ret = -EINVAL;
			break;
		}
		temp = TSENS_TM_UPPER_THRESHOLD_SET(temp);
		reg_th &= TSENS_TM_UPPER_THRESHOLD_CLEAR;
		reg_th |= temp;
		break;
	case TSENS_TRIP_STAGE1:
		if (temp >= th_hi) {
			ret = -EINVAL;
			break;
		}
		reg_th &= TSENS_TM_LOWER_THRESHOLD_CLEAR;
		reg_th |= temp;
		break;
	case TSENS_TRIP_STAGE0:
		/* Cannot handle critical low temp */
		ret = -EINVAL;
		break;
	default:
		ret = -EINVAL;
	}

	regmap_write(tmdev->map, reg_th_offset, reg_th);

	/* Sync registers */
	mb();
	return ret;
}

static int set_trip_activate_ipq807x(void *data, int trip,
					enum thermal_trip_activation_mode mode)
{
	const struct tsens_sensor *s = data;
	struct tsens_device *tmdev;
	unsigned int reg_val, reg_offset, mask;

	if (!s)
		return -EINVAL;

	if ((s->id < 0) || (s->id > (MAX_SENSOR - 1)))
		return -EINVAL;

	tmdev = s->tmdev;
	if (!tmdev)
		return -EINVAL;

	mask = s->id;

	switch (trip) {
	case TSENS_TRIP_STAGE3:
		reg_offset = TSENS_TM_CRITICAL_INT_MASK;
		regmap_read(tmdev->map, reg_offset, &reg_val);
		if (mode == THERMAL_TRIP_ACTIVATION_DISABLED)
			reg_val = reg_val | (1 << mask);
		else
			reg_val = reg_val & ~(1 << mask);
		break;
	case TSENS_TRIP_STAGE2:
		reg_offset = TSENS_TM_UPPER_LOWER_INT_MASK;
		regmap_read(tmdev->map, reg_offset, &reg_val);
		if (mode == THERMAL_TRIP_ACTIVATION_DISABLED)
			reg_val = reg_val | (TSENS_TM_UPPER_INT_SET(mask));
		else
			reg_val = reg_val & ~(TSENS_TM_UPPER_INT_SET(mask));
		break;
	case TSENS_TRIP_STAGE1:
		reg_offset = TSENS_TM_UPPER_LOWER_INT_MASK;
		regmap_read(tmdev->map, reg_offset, &reg_val);
		if (mode == THERMAL_TRIP_ACTIVATION_DISABLED)
			reg_val = reg_val | (1 << mask);
		else
			reg_val = reg_val & ~(1 << mask);
		break;
	default:
		return -EINVAL;
	}

	regmap_write(tmdev->map, reg_offset, reg_val);

	/* Sync registers */
	mb();
	return 0;
}

const struct tsens_ops ops_ipq807x = {
	.init		= init_ipq807x,
	.get_temp	= get_temp_ipq807x,
	.set_trip_temp	= set_trip_temp_ipq807x,
	.set_trip_activate = set_trip_activate_ipq807x,
	.panic_notify = panic_notify_ipq807x,
};

const struct tsens_data data_ipq807x = {
	.num_sensors	= MAX_SENSOR,
	.ops		= &ops_ipq807x,
};
