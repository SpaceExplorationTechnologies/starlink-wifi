/*
 * Copyright (c) 2018, The Linux Foundation. All rights reserved.
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
 */

#include <linux/delay.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/pm_wakeup.h>
#include <linux/rwsem.h>
#include <linux/suspend.h>
#include <soc/qcom/ramdump.h>
#include <soc/qcom/subsystem_notif.h>
#include <soc/qcom/subsystem_restart.h>
#include <linux/platform_device.h>

static void *subsys_handle;
static void *subsys_handle1;

static struct notifier_block nb;
static struct notifier_block atomic_nb;

static const char *action_to_string(enum subsys_notif_type action)
{
	switch (action) {

	case	SUBSYS_BEFORE_SHUTDOWN:
		return __stringify(SUBSYS_BEFORE_SHUTDOWN);

	case	SUBSYS_AFTER_SHUTDOWN:
		return __stringify(SUBSYS_AFTER_SHUTDOWN);

	case	SUBSYS_BEFORE_POWERUP:
		return __stringify(SUBSYS_BEFORE_POWERUP);

	case	SUBSYS_AFTER_POWERUP:
		return __stringify(SUBSYS_AFTER_POWERUP);

	case	SUBSYS_RAMDUMP_NOTIFICATION:
		return __stringify(SUBSYS_RAMDUMP_NOTIFICATION);

	case	SUBSYS_POWERUP_FAILURE:
		return __stringify(SUBSYS_POWERUP_FAILURE);

	case	SUBSYS_PROXY_VOTE:
		return __stringify(SUBSYS_PROXY_VOTE);

	case	SUBSYS_PROXY_UNVOTE:
		return __stringify(SUBSYS_PROXY_UNVOTE);

	case	SUBSYS_SOC_RESET:
		return __stringify(SUBSYS_SOC_RESET);

	case	SUBSYS_PREPARE_FOR_FATAL_SHUTDOWN:
		return __stringify(SUBSYS_PREPARE_FOR_FATAL_SHUTDOWN);

	default:
		return "unknown";
	}
}

static int tssr_notifier(struct notifier_block *nb, unsigned long action,
								void *data)
{
	struct notif_data *notif = (struct notif_data *)data;

	pr_emerg("%s:\tReceived [%s] notification from [%s]subsystem\n",
		THIS_MODULE->name, action_to_string(action), notif->pdev->name);

	return NOTIFY_DONE;
}

static int __init testssr_init(void)
{

	int ret;

	nb.notifier_call = tssr_notifier;
	atomic_nb.notifier_call = tssr_notifier;

	subsys_handle = subsys_notif_register_notifier("q6v5-wcss", &nb);
	if (IS_ERR_OR_NULL(subsys_handle)) {
		pr_emerg("Subsystem notif reg failed\n");
		return -EIO;
	}

	ret = subsys_notif_register_atomic_notifier(subsys_handle, &atomic_nb);
	if (ret < 0) {
		pr_emerg("Subsystem atomic notif reg failed\n");

		ret = subsys_notif_unregister_notifier(subsys_handle, &nb);
		if (ret < 0)
			pr_emerg("Can't unregister subsys notifier\n");

		return -EIO;
	}

	subsys_handle1 = subsystem_get("q6v5-wcss");
	if (IS_ERR_OR_NULL(subsys_handle1)) {
		pr_emerg("Subsystem get failed\n");

		ret = subsys_notif_unregister_notifier(subsys_handle, &nb);
		if (ret < 0)
			pr_emerg("Can't unregister subsys notifier\n");

		ret = subsys_notif_unregister_atomic_notifier(subsys_handle,
								&atomic_nb);
		if (ret < 0)
			pr_emerg("Can't unregister subsys notifier\n");

		return -EIO;
	}

        return 0;
}

static void __exit testssr_exit(void)
{
	int ret = 0;

	subsystem_put(subsys_handle1);

	ret = subsys_notif_unregister_notifier(subsys_handle, &nb);
	if (ret < 0)
		pr_emerg("Can't unregister subsys notifier\n");

	ret = subsys_notif_unregister_atomic_notifier(subsys_handle,
								&atomic_nb);
	if (ret < 0)
		pr_emerg("Can't unregister subsys notifier\n");
}

module_init(testssr_init);
module_exit(testssr_exit);
MODULE_LICENSE("Dual BSD/GPL");
