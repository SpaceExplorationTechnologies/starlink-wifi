/* Copyright (c) 2014, The Linux Foundation. All rights reserved.
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

#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/notifier.h>
#include <linux/reboot.h>

#ifdef CONFIG_QCOM_DLOAD_MODE
#define DLOAD_MAGIC_NUM_1 0xE47B337D
#define DLOAD_MAGIC_NUM_2 0xCE14091A
#define DLOAD_MAGIC_NUM_3 0x0501CAB0
static u32 __iomem *dload_mode;

static void qcom_restart_dload_mode_enable(void)
{
	u32 cookie;

	writel_relaxed(DLOAD_MAGIC_NUM_1, dload_mode);
	if (IS_ENABLED(CONFIG_QCOM_DLOAD_MODE_APPSBL))
		cookie = DLOAD_MAGIC_NUM_3;
	else
		cookie = DLOAD_MAGIC_NUM_2;

	writel_relaxed(cookie, dload_mode + 1);
}

static void qcom_restart_dload_mode_disable(void)
{
	BUG_ON(!dload_mode);

	writel_relaxed(0, dload_mode);
	writel_relaxed(0, dload_mode + 1);
}

static int qcom_restart_panic(struct notifier_block *this,
	unsigned long event, void *data)
{
	qcom_restart_dload_mode_enable();

	return NOTIFY_DONE;
}

static struct notifier_block panic_nb = {
	.notifier_call = qcom_restart_panic,
};

static int qcom_restart_dload_mode_register(struct platform_device *pdev)
{
	struct device_node *np;

	np = of_find_compatible_node(NULL, NULL,
		"qcom,msm-imem-download_mode");
	if (!np) {
		dev_err(&pdev->dev, "unable to find DT imem download mode node\n");
		return -EINVAL;
	}

	dload_mode = of_iomap(np, 0);
	if (!dload_mode) {
		dev_err(&pdev->dev, "unable to map imem download mode offset\n");
		return -ENOMEM;
	}

	/* Start with download mode cookies set. This will ensure that kernel
	   panics lead to download mode. In normal reboot scenario, download
	   mode cookies will be reset.
	*/
	qcom_restart_dload_mode_enable();

	atomic_notifier_chain_register(&panic_notifier_list, &panic_nb);
	return 0;
}

static void qcom_restart_dload_mode_unregister(void)
{
	atomic_notifier_chain_unregister(&panic_notifier_list, &panic_nb);
	iounmap(dload_mode);
}
#else
static inline void qcom_restart_dload_mode_enable(void) { }
static inline void qcom_restart_dload_mode_disable(void) { }
static inline int qcom_restart_dload_mode_register
					(struct platform_device *pdev)
{
	return 0;
}
static inline void qcom_restart_dload_mode_unregister(void) {}
#endif

static int qcom_restart_reason_reboot(struct notifier_block *nb,
				unsigned long action, void *data);

static struct notifier_block reboot_nb = {
	.notifier_call = qcom_restart_reason_reboot,
};

static void *restart_reason;

static u32 qcom_restart_reason_oem_code(const char *cmd)
{
	u32 reason = 0x77665501;
	u8 code;

	if (!kstrtou8(cmd, 16, &code))
		reason = 0x6f656d00 | code;
	return reason;
}

static int qcom_restart_reason_reboot(struct notifier_block *nb,
				unsigned long action, void *data)
{
	const char *cmd = data;
	u32 reason;

	if (!cmd)
		reason = 0x77665501;
	else if (!strncmp(cmd, "bootloader", 10))
		reason = 0x77665500;
	else if (!strncmp(cmd, "recovery", 8))
		reason = 0x77665502;
	else if (!strncmp(cmd, "oem-", 4))
		reason = qcom_restart_reason_oem_code(&cmd[4]);
	else
		reason = 0x77665501;

	writel_relaxed(reason, restart_reason);

	qcom_restart_dload_mode_disable();

	return NOTIFY_DONE;
}

static int qcom_restart_reason_probe(struct platform_device *pdev)
{
	struct device_node *np;
	int ret = 0;

	np = of_find_compatible_node(NULL, NULL,
		"qcom,msm-imem-restart_reason");
	if (!np) {
		dev_err(&pdev->dev, "unable to find DT msm-imem-restart_reason node\n");
	} else {
		restart_reason = of_iomap(np, 0);
		if (!restart_reason) {
			dev_err(&pdev->dev, "unable to map imem restart reason offset\n");
			return -ENOMEM;
		}
	}

	ret = qcom_restart_dload_mode_register(pdev);
	if (ret) {
		dev_err(&pdev->dev, "failed to setup download mode\n");
		goto fail;
	}

	ret = register_reboot_notifier(&reboot_nb);
	if (ret) {
		dev_err(&pdev->dev, "failed to setup reboot handler\n");
		goto fail;
	}

	return ret;

fail:
	iounmap(restart_reason);
	return ret;
}

static int qcom_restart_reason_remove(struct platform_device *pdev)
{
	qcom_restart_dload_mode_unregister();
	unregister_reboot_notifier(&reboot_nb);
	iounmap(restart_reason);

	return 0;
}

static const struct of_device_id qcom_restart_reason_match_table[] = {
	{ .compatible = "qcom,restart_reason", },
	{}
};
MODULE_DEVICE_TABLE(of, qcom_restart_reason_match_table);

static struct platform_driver qcom_restart_reason_driver = {
	.probe      = qcom_restart_reason_probe,
	.remove     = qcom_restart_reason_remove,
	.driver     = {
		.name = "qcom_restart_reason",
		.of_match_table = qcom_restart_reason_match_table,
	},
};

module_platform_driver(qcom_restart_reason_driver);

MODULE_DESCRIPTION("QCOM Restart Reason Driver");
MODULE_LICENSE("GPL v2");
