/* Copyright (c) 2015-2016, The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
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
#include "qcom_scm.h"

static int dload_dis;

static void scm_restart_dload_mode_enable(void)
{
	if (!dload_dis) {
		unsigned int magic_cookie = SET_MAGIC;
		qcom_scm_dload(QCOM_SCM_SVC_BOOT, SCM_CMD_TZ_FORCE_DLOAD_ID,
				&magic_cookie);
	}
}

static void scm_restart_dload_mode_disable(void)
{
	unsigned int magic_cookie = CLEAR_MAGIC;

	qcom_scm_dload(QCOM_SCM_SVC_BOOT, SCM_CMD_TZ_FORCE_DLOAD_ID,
			&magic_cookie);
};

static void scm_restart_sdi_disable(void)
{
	qcom_scm_sdi(QCOM_SCM_SVC_BOOT, SCM_CMD_TZ_CONFIG_HW_FOR_RAM_DUMP_ID);
}

static int scm_restart_panic(struct notifier_block *this,
	unsigned long event, void *data)
{
	scm_restart_dload_mode_enable();
	scm_restart_sdi_disable();

	return NOTIFY_DONE;
}

static struct notifier_block panic_nb = {
	.notifier_call = scm_restart_panic,
};

static int scm_restart_reason_reboot(struct notifier_block *nb,
				unsigned long action, void *data)
{
	scm_restart_sdi_disable();
	scm_restart_dload_mode_disable();

	return NOTIFY_DONE;
}

static struct notifier_block reboot_nb = {
	.notifier_call = scm_restart_reason_reboot,
	.priority = INT_MIN,
};

static int scm_restart_reason_probe(struct platform_device *pdev)
{
	int ret, dload_dis_sec;
	struct device_node *np;

	np = of_node_get(pdev->dev.of_node);
	if (!np)
		return 0;

	ret = of_property_read_u32(np, "dload_status", &dload_dis);
	if (ret)
		dload_dis = 0;

	ret = of_property_read_u32(np, "dload_sec_status", &dload_dis_sec);
	if (ret)
		dload_dis_sec = 0;

	if (dload_dis_sec) {
		qcom_scm_dload(QCOM_SCM_SVC_BOOT,
			SCM_CMD_TZ_SET_DLOAD_FOR_SECURE_BOOT, NULL);
	}

	/* Ensure Disable before enabling the dload and sdi bits
	 * to make sure they are disabled during boot */
	if (dload_dis) {
		scm_restart_dload_mode_disable();
		scm_restart_sdi_disable();
	} else {
		scm_restart_dload_mode_enable();
	}

	ret = atomic_notifier_chain_register(&panic_notifier_list, &panic_nb);
	if (ret) {
		dev_err(&pdev->dev, "failed to setup download mode\n");
		goto fail;
	}

	ret = register_reboot_notifier(&reboot_nb);
	if (ret) {
		dev_err(&pdev->dev, "failed to setup reboot handler\n");
		atomic_notifier_chain_unregister(&panic_notifier_list,
								&panic_nb);
		goto fail;
	}

fail:
	return ret;
}

static int scm_restart_reason_remove(struct platform_device *pdev)
{
	atomic_notifier_chain_unregister(&panic_notifier_list, &panic_nb);
	unregister_reboot_notifier(&reboot_nb);
	return 0;
}

static const struct of_device_id scm_restart_reason_match_table[] = {
	{ .compatible = "qca,scm_restart_reason", },
	{}
};
MODULE_DEVICE_TABLE(of, scm_restart_reason_match_table);

static struct platform_driver scm_restart_reason_driver = {
	.probe      = scm_restart_reason_probe,
	.remove     = scm_restart_reason_remove,
	.driver     = {
		.name = "qca_scm_restart_reason",
		.of_match_table = scm_restart_reason_match_table,
	},
};

module_platform_driver(scm_restart_reason_driver);

MODULE_DESCRIPTION("QCA SCM Restart Reason Driver");
