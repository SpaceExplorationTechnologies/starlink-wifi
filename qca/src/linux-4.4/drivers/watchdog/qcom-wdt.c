/* Copyright (c) 2014,2016 The Linux Foundation. All rights reserved.
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
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/reboot.h>
#include <linux/watchdog.h>
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/qcom_scm.h>
#include <linux/smp.h>
#include <linux/utsname.h>
#include <linux/sizes.h>

static int in_panic;

enum wdt_reg {
	WDT_RST,
	WDT_EN,
	WDT_BARK_TIME,
	WDT_BITE_TIME,
};

static const u32 reg_offset_data_apcs_tmr[] = {
	[WDT_RST] = 0x38,
	[WDT_EN] = 0x40,
	[WDT_BARK_TIME] = 0x4C,
	[WDT_BITE_TIME] = 0x5C,
};

static const u32 reg_offset_data_kpss[] = {
	[WDT_RST] = 0x4,
	[WDT_EN] = 0x8,
	[WDT_BARK_TIME] = 0x10,
	[WDT_BITE_TIME] = 0x14,
};

struct qcom_wdt_props {
	const u32 *layout;
	unsigned int tlv_msg_offset;
	unsigned int crashdump_page_size;
	bool secure_wdog;
};

struct qcom_wdt {
	struct watchdog_device	wdd;
	struct clk		*clk;
	unsigned long		rate;
	unsigned int		bite;
	struct notifier_block	restart_nb;
	void __iomem		*base;
	const struct qcom_wdt_props *dev_props;
	struct resource *tlv_res;
};

struct qcom_wdt_scm_tlv_msg {
	unsigned char *msg_buffer;
	unsigned char *cur_msg_buffer_pos;
	unsigned int len;
};

#define QCOM_WDT_SCM_TLV_TYPE_SIZE	1
#define QCOM_WDT_SCM_TLV_LEN_SIZE	2
#define QCOM_WDT_SCM_TLV_TYPE_LEN_SIZE	(QCOM_WDT_SCM_TLV_TYPE_SIZE +\
						QCOM_WDT_SCM_TLV_LEN_SIZE)
enum {
	QCOM_WDT_LOG_DUMP_TYPE_INVALID,
	QCOM_WDT_LOG_DUMP_TYPE_UNAME,
};

static void __iomem *wdt_addr(struct qcom_wdt *wdt, enum wdt_reg reg)
{
	return wdt->base + wdt->dev_props->layout[reg];
};

static int qcom_wdt_scm_add_tlv(struct qcom_wdt_scm_tlv_msg *scm_tlv_msg,
			unsigned char type, unsigned int size, const char *data)
{
	unsigned char *x = scm_tlv_msg->cur_msg_buffer_pos;
	unsigned char *y = scm_tlv_msg->msg_buffer + scm_tlv_msg->len;

	if ((x + QCOM_WDT_SCM_TLV_TYPE_LEN_SIZE + size) >= y)
		return -ENOBUFS;

	x[0] = type;
	x[1] = size;
	x[2] = size >> 8;

	memcpy(x + 3, data, size);

	scm_tlv_msg->cur_msg_buffer_pos +=
		(size + QCOM_WDT_SCM_TLV_TYPE_LEN_SIZE);

	return 0;
}

static int qcom_wdt_scm_fill_log_dump_tlv(
			struct qcom_wdt_scm_tlv_msg *scm_tlv_msg)
{
	struct new_utsname *uname;
	int ret_val;

	uname = utsname();

	ret_val = qcom_wdt_scm_add_tlv(scm_tlv_msg,
			QCOM_WDT_LOG_DUMP_TYPE_UNAME,
			sizeof(*uname),
			(unsigned char *)uname);

	if (ret_val)
		return ret_val;

	if (scm_tlv_msg->cur_msg_buffer_pos >=
		scm_tlv_msg->msg_buffer + scm_tlv_msg->len)
		return -ENOBUFS;

	*scm_tlv_msg->cur_msg_buffer_pos++ = QCOM_WDT_LOG_DUMP_TYPE_INVALID;

	return 0;
}

static inline
struct qcom_wdt *to_qcom_wdt(struct watchdog_device *wdd)
{
	return container_of(wdd, struct qcom_wdt, wdd);
}

static int panic_prep_restart(struct notifier_block *this,
				unsigned long event, void *ptr)
{
	in_panic = 1;
	return NOTIFY_DONE;
}

static struct notifier_block panic_blk = {
	.notifier_call  = panic_prep_restart,
};

static long qcom_wdt_configure_bark_dump(void *arg)
{
	void *scm_regsave;
	struct qcom_wdt_scm_tlv_msg tlv_msg;
	void *tlv_ptr;
	resource_size_t tlv_base;
	resource_size_t tlv_size;
	struct qcom_wdt *wdt = (struct qcom_wdt *) arg;
	const struct qcom_wdt_props *device_props = wdt->dev_props;
	long ret = -ENOMEM;
	struct resource *res = wdt->tlv_res;

	scm_regsave = (void *) __get_free_pages(GFP_KERNEL,
				get_order(device_props->crashdump_page_size));
	if (!scm_regsave)
		return -ENOMEM;

	ret = qcom_scm_regsave(SCM_SVC_UTIL, SCM_CMD_SET_REGSAVE,
			scm_regsave, device_props->crashdump_page_size);
	if (ret) {
		pr_err("Setting register save address failed.\n"
			"Registers won't be dumped on a dog bite\n");
		return ret;
	}

	/* Initialize the tlv and fill all the details */
	tlv_msg.msg_buffer = scm_regsave + device_props->tlv_msg_offset;
	tlv_msg.cur_msg_buffer_pos = tlv_msg.msg_buffer;
	tlv_msg.len = device_props->crashdump_page_size -
				 device_props->tlv_msg_offset;

	ret = qcom_wdt_scm_fill_log_dump_tlv(&tlv_msg);

	/* if failed, we still return 0 because it should not
	 * affect the boot flow. The return value 0 does not
	 * necessarily indicate success in this function.
	 */
	if (ret) {
		pr_err("log dump initialization failed\n");
		return 0;
	}

	if (res) {
		tlv_base = res->start;
		tlv_size = resource_size(res);
		res = request_mem_region(tlv_base, tlv_size, "tlv_dump");

		if (!res) {
			pr_err("requesting memory region failed\n");
			return 0;
		}

		tlv_ptr = ioremap(tlv_base, tlv_size);

		if (!tlv_ptr) {
			pr_err("mapping physical mem failed\n");
			release_mem_region(tlv_base, tlv_size);
			return 0;
		}

		memcpy_toio(tlv_ptr, tlv_msg.msg_buffer, tlv_msg.len);
		iounmap(tlv_ptr);
		release_mem_region(tlv_base, tlv_size);
	}

	return 0;
}

static int qcom_wdt_start_secure(struct watchdog_device *wdd)
{
	struct qcom_wdt *wdt = to_qcom_wdt(wdd);

	writel(0, wdt_addr(wdt, WDT_EN));
	writel(1, wdt_addr(wdt, WDT_RST));

	if (wdt->bite) {
		writel((wdd->timeout - 1) * wdt->rate,
			wdt_addr(wdt, WDT_BARK_TIME));
		writel(wdd->timeout * wdt->rate, wdt_addr(wdt, WDT_BITE_TIME));
	} else {
		writel(wdd->timeout * wdt->rate, wdt_addr(wdt, WDT_BARK_TIME));
		writel((wdd->timeout * wdt->rate) * 2, wdt_addr(wdt, WDT_BITE_TIME));
	}

	writel(1, wdt_addr(wdt, WDT_EN));
	return 0;
}

static int qcom_wdt_start_nonsecure(struct watchdog_device *wdd)
{
	struct qcom_wdt *wdt = to_qcom_wdt(wdd);

	writel(0, wdt_addr(wdt, WDT_EN));
	writel(1, wdt_addr(wdt, WDT_RST));
	writel(wdd->timeout * wdt->rate, wdt_addr(wdt, WDT_BARK_TIME));
	writel(0x0FFFFFFF, wdt_addr(wdt, WDT_BITE_TIME));
	writel(1, wdt_addr(wdt, WDT_EN));
	return 0;
}

static int qcom_wdt_stop(struct watchdog_device *wdd)
{
	struct qcom_wdt *wdt = to_qcom_wdt(wdd);

	writel(0, wdt_addr(wdt, WDT_EN));
	return 0;
}

static int qcom_wdt_ping(struct watchdog_device *wdd)
{
	struct qcom_wdt *wdt = to_qcom_wdt(wdd);

	writel(1, wdt_addr(wdt, WDT_RST));
	return 0;
}

static int qcom_wdt_set_timeout(struct watchdog_device *wdd,
				unsigned int timeout)
{
	wdd->timeout = timeout;
	return wdd->ops->start(wdd);
}

static const struct watchdog_ops qcom_wdt_ops_secure = {
	.start		= qcom_wdt_start_secure,
	.stop		= qcom_wdt_stop,
	.ping		= qcom_wdt_ping,
	.set_timeout	= qcom_wdt_set_timeout,
	.owner		= THIS_MODULE,
};

static const struct watchdog_ops qcom_wdt_ops_nonsecure = {
	.start		= qcom_wdt_start_nonsecure,
	.stop		= qcom_wdt_stop,
	.ping		= qcom_wdt_ping,
	.set_timeout	= qcom_wdt_set_timeout,
	.owner		= THIS_MODULE,
};

static const struct watchdog_info qcom_wdt_info = {
	.options	= WDIOF_KEEPALIVEPING
			| WDIOF_MAGICCLOSE
			| WDIOF_SETTIMEOUT,
	.identity	= KBUILD_MODNAME,
};

const struct qcom_wdt_props qcom_wdt_props_ipq8064 = {
	.layout = reg_offset_data_apcs_tmr,
	.tlv_msg_offset = SZ_2K,
	.crashdump_page_size = SZ_4K,
	.secure_wdog = false,
};

const struct qcom_wdt_props qcom_wdt_props_ipq807x = {
	.layout = reg_offset_data_kpss,
	.tlv_msg_offset = SZ_4K,
	/* As SBL overwrites the NSS IMEM, TZ has to copy it to some memory
	 * on crash before it restarts the system. Hence, reserving of 384K
	 * is required to copy the NSS IMEM before restart is done.
	 * So that TZ can dump NSS dump data after the first 8K.
	 * Additionally 8K memory is allocated which can be used by TZ
	 * to dump PMIC memory.
	 * get_order function returns the next higher order as output,
	 * so when we pass 400K as argument 512K will be allocated.
	 * 112K is unused currently and can be used based on future needs.
	 */
	/*
	 * The memory is allocated using alloc_pages, hence it will be in
	 * power of 2. The unused memory is the result of using alloc_pages.
	 * As we need contigous memory for > 256K we have to use alloc_pages.
	 *
	 *		 ---------------
	 *		|      8K	|
	 *		|    regsave	|
	 *		 ---------------
	 *		|		|
	 *		|     384K	|
	 *		|    NSS IMEM	|
	 *		|		|
	 *		|		|
	 *		 ---------------
	 *		|      8K	|
	 *		|    PMIC mem	|
	 *		 ---------------
	 *		|    3K - DCC	|
	 *		 ---------------
	 *		|		|
	 *		|     109K	|
	 *		|    Unused	|
	 *		|		|
	 *		 ---------------
	 */
	.crashdump_page_size = (SZ_8K + (384 * SZ_1K) + (SZ_8K) + (3 * SZ_1K) +
				(109 * SZ_1K)),
	.secure_wdog = true,
};

const struct qcom_wdt_props qcom_wdt_props_ipq40xx = {
	.layout = reg_offset_data_kpss,
	.tlv_msg_offset = SZ_2K,
	.crashdump_page_size = SZ_4K,
	.secure_wdog = true,
};

static const struct of_device_id qcom_wdt_of_table[] = {
	{	.compatible = "qcom,kpss-wdt-ipq8064",
		.data = (void *) &qcom_wdt_props_ipq8064,
	},
	{	.compatible = "qcom,kpss-wdt-ipq807x",
		.data = (void *) &qcom_wdt_props_ipq807x,
	},
	{	.compatible = "qcom,kpss-wdt-ipq40xx",
		.data = (void *) &qcom_wdt_props_ipq40xx,
	},
	{}
};
MODULE_DEVICE_TABLE(of, qcom_wdt_of_table);
static int qcom_wdt_restart(struct notifier_block *nb, unsigned long action,
			    void *data)
{
	struct qcom_wdt *wdt = container_of(nb, struct qcom_wdt, restart_nb);
	u32 timeout;

	/*
	 * Trigger watchdog bite:
	 *    Setup BITE_TIME to be 128ms, and enable WDT.
	 */
	timeout = 128 * wdt->rate / 1000;

	writel(0, wdt_addr(wdt, WDT_EN));
	writel(1, wdt_addr(wdt, WDT_RST));
	if (in_panic) {
		writel(timeout, wdt_addr(wdt, WDT_BARK_TIME));
		writel(2 * timeout, wdt_addr(wdt, WDT_BITE_TIME));
	} else {
		writel(5 * timeout, wdt_addr(wdt, WDT_BARK_TIME));
		writel(timeout, wdt_addr(wdt, WDT_BITE_TIME));
	}

	writel(1, wdt_addr(wdt, WDT_EN));
	/*
	 * Actually make sure the above sequence hits hardware before sleeping.
	 */
	wmb();

	mdelay(150);
	return NOTIFY_DONE;
}

static irqreturn_t wdt_bark_isr(int irq, void *wdd)
{
	struct qcom_wdt *wdt = to_qcom_wdt(wdd);
	unsigned long nanosec_rem;
	unsigned long long t = sched_clock();

	nanosec_rem = do_div(t, 1000000000);
	pr_info("Watchdog bark! Now = %lu.%06lu\n", (unsigned long) t,
							nanosec_rem / 1000);
	pr_info("Causing a watchdog bite!");
	writel(0, wdt_addr(wdt, WDT_EN));
	writel(1, wdt_addr(wdt, WDT_BITE_TIME));
	mb(); /* Avoid unpredictable behaviour in concurrent executions */
	pr_info("Configuring Watchdog Timer\n");
	writel(1, wdt_addr(wdt, WDT_RST));
	writel(1, wdt_addr(wdt, WDT_EN));
	mb(); /* Make sure the above sequence hits hardware before Reboot. */
	pr_info("Waiting for Reboot\n");

	mdelay(1);
	pr_err("Wdog - CTL: 0x%x, BARK TIME: 0x%x, BITE TIME: 0x%x",
		readl(wdt_addr(wdt, WDT_EN)),
		readl(wdt_addr(wdt, WDT_BARK_TIME)),
		readl(wdt_addr(wdt, WDT_BITE_TIME)));
	return IRQ_HANDLED;
}

void register_wdt_bark_irq(int irq, struct qcom_wdt *wdt)
{
	int ret;

	ret = request_irq(irq, wdt_bark_isr, IRQF_TRIGGER_HIGH,
						"watchdog bark", wdt);
	if (ret)
		pr_err("error request_irq(irq_num:%d ) ret:%d\n", irq, ret);
}

static int qcom_wdt_probe(struct platform_device *pdev)
{
	const struct of_device_id *id;
	struct qcom_wdt *wdt;
	struct resource *res;
	struct device_node *np = pdev->dev.of_node;
	u32 percpu_offset;
	int ret, irq;
	uint32_t val;

	wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
	if (!wdt)
		return -ENOMEM;
	irq = platform_get_irq_byname(pdev, "bark_irq");
	res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "kpss_wdt");
	if (!res) {
		dev_err(&pdev->dev, "%s: no mem resource\n", __func__);
		return -EINVAL;
	}

	/* We use CPU0's DGT for the watchdog */
	if (of_property_read_u32(np, "cpu-offset", &percpu_offset))
		percpu_offset = 0;

	res->start += percpu_offset;
	res->end += percpu_offset;

	wdt->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(wdt->base))
		return PTR_ERR(wdt->base);

	wdt->tlv_res = platform_get_resource_byname
			(pdev, IORESOURCE_MEM, "tlv");

	id = of_match_device(qcom_wdt_of_table, &pdev->dev);
	if (!id)
		return -ENODEV;

	wdt->dev_props = (struct qcom_wdt_props *)id->data;

	if (wdt->dev_props->secure_wdog)
		wdt->bite = 1;

	if (irq > 0)
		register_wdt_bark_irq(irq, wdt);

	wdt->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(wdt->clk)) {
		dev_err(&pdev->dev, "failed to get input clock\n");
		return PTR_ERR(wdt->clk);
	}

	ret = clk_prepare_enable(wdt->clk);
	if (ret) {
		dev_err(&pdev->dev, "failed to setup clock\n");
		return ret;
	}

	/*
	 * We use the clock rate to calculate the max timeout, so ensure it's
	 * not zero to avoid a divide-by-zero exception.
	 *
	 * WATCHDOG_CORE assumes units of seconds, if the WDT is clocked such
	 * that it would bite before a second elapses it's usefulness is
	 * limited.  Bail if this is the case.
	 */
	wdt->rate = clk_get_rate(wdt->clk);
	if (wdt->rate == 0 ||
	    wdt->rate > 0x10000000U) {
		dev_err(&pdev->dev, "invalid clock rate\n");
		ret = -EINVAL;
		goto err_clk_unprepare;
	}

	ret = work_on_cpu(0, qcom_wdt_configure_bark_dump, wdt);
	if (ret)
		wdt->wdd.ops = &qcom_wdt_ops_nonsecure;
	else
		wdt->wdd.ops = &qcom_wdt_ops_secure;

	wdt->wdd.dev = &pdev->dev;
	wdt->wdd.info = &qcom_wdt_info;
	wdt->wdd.min_timeout = 1;
	if (!of_property_read_u32(np, "wdt-max-timeout", &val))
		wdt->wdd.max_timeout = val;
	else
		wdt->wdd.max_timeout = 0x10000000U / wdt->rate;
	wdt->wdd.parent = &pdev->dev;

	/*
	 * If 'timeout-sec' unspecified in devicetree, assume a 30 second
	 * default, unless the max timeout is less than 30 seconds, then use
	 * the max instead.
	 */
	wdt->wdd.timeout = min(wdt->wdd.max_timeout, 30U);
	watchdog_init_timeout(&wdt->wdd, 0, &pdev->dev);

	ret = watchdog_register_device(&wdt->wdd);
	if (ret) {
		dev_err(&pdev->dev, "failed to register watchdog\n");
		goto err_clk_unprepare;
	}

	/*
	 * WDT restart notifier has priority 0 (use as a last resort)
	 */
	wdt->restart_nb.notifier_call = qcom_wdt_restart;
	atomic_notifier_chain_register(&panic_notifier_list, &panic_blk);
	ret = register_restart_handler(&wdt->restart_nb);
	if (ret)
		dev_err(&pdev->dev, "failed to setup restart handler\n");

	platform_set_drvdata(pdev, wdt);
	return 0;

err_clk_unprepare:
	clk_disable_unprepare(wdt->clk);
	return ret;
}

static int qcom_wdt_remove(struct platform_device *pdev)
{
	struct qcom_wdt *wdt = platform_get_drvdata(pdev);

	unregister_restart_handler(&wdt->restart_nb);
	watchdog_unregister_device(&wdt->wdd);
	clk_disable_unprepare(wdt->clk);
	return 0;
}

static struct platform_driver qcom_watchdog_driver = {
	.probe	= qcom_wdt_probe,
	.remove	= qcom_wdt_remove,
	.driver	= {
		.name		= KBUILD_MODNAME,
		.of_match_table	= qcom_wdt_of_table,
	},
};
module_platform_driver(qcom_watchdog_driver);

MODULE_DESCRIPTION("QCOM KPSS Watchdog Driver");
MODULE_LICENSE("GPL v2");
