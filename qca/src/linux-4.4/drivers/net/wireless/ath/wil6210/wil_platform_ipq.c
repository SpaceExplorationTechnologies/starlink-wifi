/*
 * Copyright (c) 2016, The Linux Foundation. All rights reserved.
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

#include <linux/moduleparam.h>
#include <linux/of.h>
#include <net/cfg80211.h>
#include "wil_platform.h"

static bool crash_on_fw_err = true;
module_param(crash_on_fw_err, bool, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(crash_on_fw_err, " Crash host on FW assertions in IPQ device.");

struct ipq11ad_ctx {
	struct wil_platform_rops rops;
	void *wil_handle;

	/* virtual addr and size for crash dump  */
	void __iomem *fw_io_mem_addr;
	u32 fw_io_mem_size;
};

static int ipq_11ad_notify_crash(struct ipq11ad_ctx *ctx)
{
	int rc;

	pr_info("%s: Fw error detected, crash_on_fw_err = %d.\n",
		__func__, crash_on_fw_err);

	if (!crash_on_fw_err) {
		if (ctx->rops.fw_recovery)
			ctx->rops.fw_recovery(ctx->wil_handle);

		return 0;
	}

	if (ctx->rops.ramdump && ctx->wil_handle && ctx->fw_io_mem_addr &&
	    ctx->fw_io_mem_size) {
		pr_info("%s: Copying fw dump\n", __func__);

		rc = ctx->rops.ramdump(ctx->wil_handle,
				       (void * __force)ctx->fw_io_mem_addr,
				       ctx->fw_io_mem_size);
		if (rc)
			pr_err("%s: Error, Ramdump failed : %d\n",
			       __func__, rc);
	}

	pr_err("WIGIG: Asserting Host...\n");

	BUG_ON(1);

	return 0;
}

static int ops_notify(void *handle, enum wil_platform_event evt)
{
	struct ipq11ad_ctx *ctx = (struct ipq11ad_ctx *)handle;
	int rc = 0;

	if (!ctx) {
		pr_err("%s: Context not found\n", __func__);
		return -ENODEV;
	}

	switch (evt) {
	case WIL_PLATFORM_EVT_FW_CRASH:
		rc = ipq_11ad_notify_crash(ctx);
		break;
	default:
		pr_debug("%s: Unhandled event %d\n", __func__, evt);
		break;
	}

	return rc;
}

static void ops_uninit(void *handle)
{
	struct ipq11ad_ctx *ctx = (struct ipq11ad_ctx *)handle;

	if (!ctx) {
		pr_err("%s: Error Getting Context", __func__);
		return;
	}

	pr_info("%s: IPQ platform device uninit.\n", __func__);

	if (ctx->fw_io_mem_addr)
		iounmap(ctx->fw_io_mem_addr);
	kfree(ctx);
}

void *ipq_11ad_dev_init(struct wil_platform_ops *ops,
			const struct wil_platform_rops *rops, void *wil_handle)
{
	struct ipq11ad_ctx *ctx;
	struct device_node *dev_node = NULL;
	unsigned int registerdetails[2];
	int ret = 0;

	memset(ops, 0, sizeof(*ops));

	pr_info("%s: IPQ platform device init.\n", __func__);

	ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return NULL;

	/* subsystem restart */
	if (rops) {
		ctx->rops = *rops;
		ctx->wil_handle = wil_handle;
	}

	/* fill ops */
	ops->notify = ops_notify;
	ops->uninit = ops_uninit;

	/* ramdump - address and size */
	dev_node = of_find_node_by_name(NULL, "wigig_dump");
	if (dev_node) {
		ret = of_property_read_u32_array(dev_node, "reg",
						 &registerdetails[0], 2);
		if (ret) {
			pr_err("%s: Error (%d) retrieving reg entry in wigig_dump\n",
			       __func__, ret);
			goto exit;
		}
		pr_info("%s: Physical address for fw dump: 0x%x, size: 0x%x\n",
			__func__, registerdetails[0], registerdetails[1]);
	} else {
		pr_warn("%s: Error, No wigig_dump dts node available in the dts entry file\n",
			__func__);
		goto exit;
	}
	ctx->fw_io_mem_addr = ioremap(registerdetails[0], registerdetails[1]);
	if (!ctx->fw_io_mem_addr) {
		pr_err("%s: Error, Fail to get virtual address\n", __func__);
		goto exit;
	}
	ctx->fw_io_mem_size = registerdetails[1];

exit:
	return ctx;
}
EXPORT_SYMBOL(ipq_11ad_dev_init);
