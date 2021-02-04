/* Copyright (c) 2010-2014 The Linux Foundation. All rights reserved.
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

#include <linux/init.h>
#include <linux/dma-mapping.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/clocksource.h>
#include <linux/clk-provider.h>

#include <asm/mach/arch.h>

static const char * const qcom_dt_match[] __initconst = {
	"qcom,apq8064",
	"qcom,apq8074-dragonboard",
	"qcom,apq8084",
	"qcom,ipq8062",
	"qcom,ipq8064",
	"qcom,msm8660-surf",
	"qcom,msm8960-cdp",
	"qcom,ipq4019",
	NULL
};

DT_MACHINE_START(QCOM_DT, "Qualcomm (Flattened Device Tree)")
	.dt_compat = qcom_dt_match,
MACHINE_END

static int __init qcom_atomic_pool_size_set(void)
{
#define ATOMIC_DMA_COHERENT_POOL_SIZE	SZ_2M

	init_dma_coherent_pool_size(ATOMIC_DMA_COHERENT_POOL_SIZE);

	return 0;
}

/*
 * This should happen before atomic_pool_init(), which is a
 * postcore_initcall.
 */
core_initcall(qcom_atomic_pool_size_set);
static const char * const qcom_qca_dt_match[] __initconst = {
	"qcom,qca961x-r3pc",
	"qcom,ipq4019",
	NULL
};

static void __init global_counter_enable(void)
{
	struct device_node *node;
	void __iomem *base;

	node = of_find_compatible_node(NULL, NULL, "qcom,qca-gcnt");
	if (!node) {
		pr_err("%s:can't find node\n", __func__);
		return;
	}

	base = of_iomap(node, 0);
	of_node_put(node);
	if (!base) {
		pr_err("%s:no regs for global counter\n", __func__);
		return;
	}

	writel_relaxed(1, base);
	mb(); /* memory barrier */
	iounmap(base);

#ifdef CONFIG_COMMON_CLK
	of_clk_init(NULL);
#endif
	clocksource_probe();
}

DT_MACHINE_START(QCOM_QCA_DT, "Qualcomm (Flattened Device Tree)")
	.dt_compat = qcom_qca_dt_match,
	.init_time = global_counter_enable,
MACHINE_END
