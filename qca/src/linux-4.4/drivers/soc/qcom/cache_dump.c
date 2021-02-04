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
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/notifier.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/qcom_scm.h>

#define SCM_CMD_L1C_BUFFER_SET		0x4
#define SCM_CMD_L2C_BUFFER_SET		0x7
#define SCM_CMD_QUERY_L1C_SIZE		0x6
#define SCM_CMD_QUERY_L2C_SIZE		0x8

static void *l2_dump_offset;
static int qcom_cache_dump_panic(struct notifier_block *this,
		unsigned long event, void *ptr)
{
#ifdef CONFIG_QCOM_CACHE_DUMP_ON_PANIC
	/*
	 * Clear the bootloader magic so the dumps aren't overwritten
	 */
	writel_relaxed(0, l2_dump_offset);
	qcom_scm_cache_dump(2);
	qcom_scm_cache_dump(1);

#endif
	return 0;
}

static struct notifier_block qcom_cache_dump_blk = {
	.notifier_call  = qcom_cache_dump_panic,
	/*
	* higher priority to ensure this runs before another panic handler
	* flushes the caches.
	*/
	.priority = 1,
};

static int qcom_cache_dump_probe(struct platform_device *pdev)
{
	int ret;
	struct {
		unsigned long buf;
		unsigned long size;
	} cache_data;

	u32 l1_size = 0, l2_size = 0;
	unsigned long total_size;
	void *qcom_cache_dump_vaddr;
	dma_addr_t qcom_cache_dump_addr;
	struct device_node *np;
	u32 *cache_size_p;

	np = of_find_compatible_node(NULL, NULL,
		"qcom,msm-imem-l2_dump_offset");
	if (!np) {
		dev_err(&pdev->dev, "unable to find DT imem l2 dump offset node\n");
	} else {
		l2_dump_offset = of_iomap(np, 0);
		if (!l2_dump_offset) {
			dev_err(&pdev->dev, "unable to map imem l2 dump offset\n");
			return -ENOMEM;
		}
	}

	cache_size_p = kzalloc(sizeof(uint32_t), GFP_KERNEL);

	if (!cache_size_p)
		goto of_read;

	/*
	 * Get L1 Dump Size from TZ
	 */
	ret = qcom_scm_get_cache_dump_size(SCM_CMD_QUERY_L1C_SIZE, cache_size_p,
						sizeof(*cache_size_p));
	if (ret == 0) {
		/*
		 * This should be page aligned since L2 dump address
		 * starts from "qcom_cache_dump_vaddr + l1_size" offset
		 * and TZ expects the dump addresses to be page aligned
		 */
		l1_size = PAGE_ALIGN(*cache_size_p);
	}
	/*
	 * Get L2 Dump Size from TZ
	 */
	ret = qcom_scm_get_cache_dump_size(SCM_CMD_QUERY_L2C_SIZE, cache_size_p,
						sizeof(*cache_size_p));

	if (ret == 0)
		l2_size = *cache_size_p;

of_read:
	if (!l1_size) {
		ret = of_property_read_u32(pdev->dev.of_node,
			"qcom,l1-dump-size", &l1_size);
	}
	if (!l2_size) {
		ret = of_property_read_u32(pdev->dev.of_node,
			"qcom,l2-dump-size", &l2_size);
	}
	total_size = l1_size + l2_size;
	/*
	 * Return If L1/L2 cache size are unavailable from both DT and TZ
	 */
	if (total_size == 0) {
		pr_err("\nL1/L2 dump size unavailable");
		ret = -EINVAL;
		goto err_free;
	}
	qcom_cache_dump_vaddr = dma_alloc_coherent(&pdev->dev,
		total_size, &qcom_cache_dump_addr,
		GFP_KERNEL);

	if (!qcom_cache_dump_vaddr) {
		pr_err("%s: Could not get memory for cache dumping\n",
			__func__);
		ret = -ENOMEM;
		goto err_free;
	}

	memset(qcom_cache_dump_vaddr, 0xFF, total_size);
	/*
	 * Send L1 dump address only if l1_size is not zero
	 */
	if (l1_size) {
		cache_data.buf = qcom_cache_dump_addr;
		cache_data.size = l1_size;
		ret = qcom_scm_send_cache_dump_addr(SCM_CMD_L1C_BUFFER_SET,
					&cache_data, sizeof(cache_data));

		if (ret)
			pr_err("%s: could not register L1 buffer ret = %d.\n",
				__func__, ret);
	}

#if defined(CONFIG_QCOM_CACHE_DUMP_ON_PANIC)
	/*
	 * Send L2 dump address only if l2_size is not zero
	 */
	if (l2_size) {
		cache_data.buf = qcom_cache_dump_addr + l1_size;
		cache_data.size = l2_size;
		ret = qcom_scm_send_cache_dump_addr(SCM_CMD_L2C_BUFFER_SET,
					&cache_data, sizeof(cache_data));

		if (ret)
			pr_err("%s: could not register L2 buffer ret = %d.\n",
				__func__, ret);
	}
#endif

	writel_relaxed(qcom_cache_dump_addr + l1_size, l2_dump_offset);
	atomic_notifier_chain_register(&panic_notifier_list,
		&qcom_cache_dump_blk);

err_free:
	kfree(cache_size_p);
	return ret;
}

static int qcom_cache_dump_remove(struct platform_device *pdev)
{
	atomic_notifier_chain_unregister(&panic_notifier_list,
		&qcom_cache_dump_blk);
	return 0;
}

static const struct of_device_id cache_dump_match_table[] = {
	{   .compatible = "qcom,cache_dump",    },
	{}
};
MODULE_DEVICE_TABLE(of, cache_dump_match_table);

static struct platform_driver qcom_cache_dump_driver = {
	.probe      = qcom_cache_dump_probe,
	.remove     = qcom_cache_dump_remove,
	.driver     = {
		.name = "qcom_cache_dump",
		.of_match_table = cache_dump_match_table,
	},
};

module_platform_driver(qcom_cache_dump_driver);

MODULE_DESCRIPTION("QCOM Cache Dump Driver");
MODULE_LICENSE("GPL v2");
