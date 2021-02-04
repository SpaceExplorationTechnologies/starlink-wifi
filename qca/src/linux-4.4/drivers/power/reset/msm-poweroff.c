/* Copyright (c) 2013, The Linux Foundation. All rights reserved.
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

#include <linux/delay.h>
#include <linux/err.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/reboot.h>
#include <linux/pm.h>
#include <linux/qcom_scm.h>
#include <asm/system_misc.h>

static void __iomem *msm_ps_hold;
static int secure;
static int do_msm_restart(struct notifier_block *nb, unsigned long action,
			   void *data)
{

	int ret;
	if (secure) {
		ret = qcom_scm_pshold();
		printk("Resetting using secure PSHOLD : returned %d\n", ret);
	} else {
		writel(0, msm_ps_hold);
		mdelay(10000);
	}

	return NOTIFY_DONE;
}

static struct notifier_block restart_nb = {
	.notifier_call = do_msm_restart,
	.priority = 128,
};

static void do_msm_poweroff(void)
{
	/* TODO: Add poweroff capability */
	do_msm_restart(&restart_nb, 0, NULL);
}

static int do_msm_reboot_notifier(struct notifier_block *nb,
				unsigned long action, void *data)
{
	/* Normal Reboot Enable PS HOLD reset sequence */
	arm_pm_restart = do_msm_restart;
	return NOTIFY_DONE;
}

static struct notifier_block reboot_nb1 = {
	.notifier_call = do_msm_reboot_notifier,
};

static int msm_restart_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct resource *mem;

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	msm_ps_hold = devm_ioremap_resource(dev, mem);
	if (IS_ERR(msm_ps_hold))
		return PTR_ERR(msm_ps_hold);

	pm_power_off = do_msm_poweroff;

	secure = of_property_read_bool(pdev->dev.of_node, "qcom,secure");

	register_reboot_notifier(&reboot_nb1);

	return 0;
}

static const struct of_device_id of_msm_restart_match[] = {
	{ .compatible = "qcom,pshold", },
	{},
};
MODULE_DEVICE_TABLE(of, of_msm_restart_match);

static struct platform_driver msm_restart_driver = {
	.probe = msm_restart_probe,
	.driver = {
		.name = "msm-restart",
		.of_match_table = of_match_ptr(of_msm_restart_match),
	},
};

static int __init msm_restart_init(void)
{
	return platform_driver_register(&msm_restart_driver);
}
device_initcall(msm_restart_init);
