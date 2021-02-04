/* Copyright (c) 2016, The Linux Foundation. All rights reserved.
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

#include <linux/acpi.h>
#include <linux/clk.h>
#include <linux/dma-mapping.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/hrtimer.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/phy/phy.h>
#include <linux/platform_device.h>
#include <linux/reset.h>
#include <linux/usb.h>
#include <linux/usb/hcd.h>
#include <linux/usb/ehci_pdriver.h>

#include <asm/mach-ath79/ath79.h>
#include <asm/mach-ath79/ar71xx_regs.h>
#include "ehci.h"

#define DRIVER_DESC "ATH79 EHCI platform driver"
#define EHCI_MAX_CLKS 3
#define hcd_to_ehci_priv(h) ((struct ehci_ath79_priv *)hcd_to_ehci(h)->priv)

struct ehci_ath79_priv {
	struct clk *clks[EHCI_MAX_CLKS];
	struct reset_control *rst;
	struct phy **phys;
	int num_phys;
	bool reset_on_resume;
};

static const char hcd_name[] = "ehci-ath79";

static void ehci_ath79_reset_notifier(struct usb_hcd *hcd)
{
	struct platform_device *pdev = to_platform_device(hcd->self.controller);
	struct usb_ehci_pdata *pdata = pdev->dev.platform_data;

	pdata->reset_notifier(pdev);
}

static void enable_tx_tx_idp_violation_fix(unsigned base)
{
	void __iomem *phy_reg;
	u32 t;

	phy_reg = ioremap(base, 4);
	if (!phy_reg)
		return;

	t = ioread32(phy_reg);
	t &= ~0xff;
	t |= 0x58;
	iowrite32(t, phy_reg);

	iounmap(phy_reg);
}

static void qca955x_usb_reset_notifier(struct platform_device *pdev)
{
	u32 base;

	switch (pdev->id) {
	case 0:
		base = 0x18116c94;
		break;

	case 1:
		base = 0x18116e54;
		break;

	default:
		return;
	}

	enable_tx_tx_idp_violation_fix(base);
	dev_info(&pdev->dev, "TX-TX IDP fix enabled\n");
}

static int ehci_ath79_reset(struct usb_hcd *hcd)
{
	struct platform_device *pdev = to_platform_device(hcd->self.controller);
	struct usb_ehci_pdata *pdata = dev_get_platdata(&pdev->dev);
	struct ehci_hcd *ehci = hcd_to_ehci(hcd);
	int retval;

	ehci->has_synopsys_hc_bug = pdata->has_synopsys_hc_bug;

	if (pdata->pre_setup) {
		retval = pdata->pre_setup(hcd);
		if (retval < 0)
			return retval;
	}

	ehci->caps = hcd->regs + pdata->caps_offset;
	retval = ehci_setup(hcd);
	if (retval)
		return retval;

	if (pdata->no_io_watchdog)
		ehci->need_io_watchdog = 0;
	return 0;
}

static int ehci_ath79_power_on(struct platform_device *dev)
{
	struct usb_hcd *hcd = platform_get_drvdata(dev);
	struct ehci_ath79_priv *priv = hcd_to_ehci_priv(hcd);
	int clk, ret, phy_num;

	for (clk = 0; clk < EHCI_MAX_CLKS && priv->clks[clk]; clk++) {
		ret = clk_prepare_enable(priv->clks[clk]);
		if (ret)
			goto err_disable_clks;
	}

	for (phy_num = 0; phy_num < priv->num_phys; phy_num++) {
		ret = phy_init(priv->phys[phy_num]);
		if (ret)
			goto err_exit_phy;
		ret = phy_power_on(priv->phys[phy_num]);
		if (ret) {
			phy_exit(priv->phys[phy_num]);
			goto err_exit_phy;
		}
	}

	return 0;

err_exit_phy:
	while (--phy_num >= 0) {
		phy_power_off(priv->phys[phy_num]);
		phy_exit(priv->phys[phy_num]);
	}
err_disable_clks:
	while (--clk >= 0)
		clk_disable_unprepare(priv->clks[clk]);

	return ret;
}

static void ehci_ath79_power_off(struct platform_device *dev)
{
	struct usb_hcd *hcd = platform_get_drvdata(dev);
	struct ehci_ath79_priv *priv = hcd_to_ehci_priv(hcd);
	int clk, phy_num;

	for (phy_num = 0; phy_num < priv->num_phys; phy_num++) {
		phy_power_off(priv->phys[phy_num]);
		phy_exit(priv->phys[phy_num]);
	}

	for (clk = EHCI_MAX_CLKS - 1; clk >= 0; clk--)
		if (priv->clks[clk])
			clk_disable_unprepare(priv->clks[clk]);
}

static struct hc_driver __read_mostly ehci_ath79_hc_driver;

static const struct ehci_driver_overrides platform_overrides __initconst = {
	.reset =		ehci_ath79_reset,
	.extra_priv_size =	sizeof(struct ehci_ath79_priv),
};

static struct usb_ehci_pdata ehci_ath79_defaults = {
	.power_on =		ehci_ath79_power_on,
	.power_suspend =	ehci_ath79_power_off,
	.power_off =		ehci_ath79_power_off,
};

static void qca953x_ehci_usb_setup(void)
{
	u32 bootstrap;

	bootstrap = ath79_reset_rr(QCA953X_RESET_REG_BOOTSTRAP);

	ath79_device_reset_set(QCA953X_RESET_USBSUS_OVERRIDE);
	udelay(1000);

	ath79_device_reset_clear(QCA953X_RESET_USB_PHY);
	udelay(1000);

	ath79_device_reset_clear(QCA953X_RESET_USB_PHY_ANALOG);
	udelay(1000);

	ath79_device_reset_clear(QCA953X_RESET_USB_HOST);
	udelay(1000);
}

static int ehci_ath79_probe(struct platform_device *dev)
{
	struct usb_hcd *hcd;
	struct resource *res_mem;
	struct usb_ehci_pdata *pdata = dev_get_platdata(&dev->dev);
	struct ehci_ath79_priv *priv;
	struct ehci_hcd *ehci;
	int err, irq, phy_num, clk = 0;
	u32 caps_offset;
	int ret = 0;

	if (usb_disabled())
		return -ENODEV;

	/*
	 * Use reasonable defaults so platforms don't have to provide these
	 * with DT probing on ARM.
	 */
	if (!pdata)
		pdata = &ehci_ath79_defaults;

	if (pdata == &ehci_ath79_defaults && dev->dev.of_node) {
		ret = of_alias_get_id(dev->dev.of_node, "ehci");
		if (ret >= 0)
			dev->id = ret;

		if (dev->id == -1)
			dev->id = 0;

		if (of_property_read_bool(dev->dev.of_node, "dma-bit-mask-64"))
			pdata->dma_mask_64 = 1;
		else
			pdata->dma_mask_64 = 0;
	}

	err = dma_coerce_mask_and_coherent(&dev->dev,
		pdata->dma_mask_64 ? DMA_BIT_MASK(64) : DMA_BIT_MASK(32));
	if (err) {
		dev_err(&dev->dev, "Error: DMA mask configuration failed\n");
		return err;
	}

	irq = platform_get_irq(dev, 0);
	if (irq < 0) {
		dev_err(&dev->dev, "no irq provided");
		return irq;
	}


	hcd = usb_create_hcd(&ehci_ath79_hc_driver, &dev->dev,
			     dev_name(&dev->dev));
	if (!hcd)
		return -ENOMEM;

	platform_set_drvdata(dev, hcd);
	dev->dev.platform_data = pdata;
	priv = hcd_to_ehci_priv(hcd);
	ehci = hcd_to_ehci(hcd);

	if (pdata == &ehci_ath79_defaults && dev->dev.of_node) {
		if (of_device_is_compatible(dev->dev.of_node,
					"qca,ap147-ehci")) {
			qca953x_ehci_usb_setup();
		}

		else if (of_device_is_compatible(dev->dev.of_node,
					"qca,ap135-ehci") ||
			of_device_is_compatible(dev->dev.of_node,
					"qca,ap137-ehci")) {
			pdata->reset_notifier = qca955x_usb_reset_notifier;
		}

		if (of_property_read_bool(dev->dev.of_node, "big-endian-regs"))
			ehci->big_endian_mmio = 1;

		if (of_property_read_bool(dev->dev.of_node, "big-endian-desc"))
			ehci->big_endian_desc = 1;

		if (of_property_read_bool(dev->dev.of_node, "big-endian"))
			ehci->big_endian_mmio = ehci->big_endian_desc = 1;

		if (of_property_read_bool(dev->dev.of_node,
					  "needs-reset-on-resume"))
			priv->reset_on_resume = true;

		if (of_property_read_bool(dev->dev.of_node,
					  "has-transaction-translator"))
			hcd->has_tt = 1;

		if (of_property_read_bool(dev->dev.of_node,
					  "qca_force_host_mode"))
			ehci->qca_force_host_mode = 1;

		if (of_property_read_bool(dev->dev.of_node,
					  "qca_force_16bit_ptw"))
			ehci->qca_force_16bit_ptw = 1;

		of_property_read_u32(dev->dev.of_node,
					  "caps-offset", &caps_offset);
		pdata->caps_offset = caps_offset;

		priv->num_phys = of_count_phandle_with_args(dev->dev.of_node,
				"phys", "#phy-cells");

		if (priv->num_phys > 0) {
			priv->phys = devm_kcalloc(&dev->dev, priv->num_phys,
					    sizeof(struct phy *), GFP_KERNEL);
			if (!priv->phys)
				return -ENOMEM;
		} else
			priv->num_phys = 0;

		for (phy_num = 0; phy_num < priv->num_phys; phy_num++) {
			priv->phys[phy_num] = devm_of_phy_get_by_index(
					&dev->dev, dev->dev.of_node, phy_num);
			if (IS_ERR(priv->phys[phy_num])) {
				err = PTR_ERR(priv->phys[phy_num]);
					goto err_put_hcd;
			}
		}

		for (clk = 0; clk < EHCI_MAX_CLKS; clk++) {
			priv->clks[clk] = of_clk_get(dev->dev.of_node, clk);
			if (IS_ERR(priv->clks[clk])) {
				err = PTR_ERR(priv->clks[clk]);
				if (err == -EPROBE_DEFER)
					goto err_put_clks;
				priv->clks[clk] = NULL;
				break;
			}
		}
	}

	priv->rst = devm_reset_control_get_optional(&dev->dev, NULL);
	if (IS_ERR(priv->rst)) {
		err = PTR_ERR(priv->rst);
		if (err == -EPROBE_DEFER)
			goto err_put_clks;
		priv->rst = NULL;
	} else {
		err = reset_control_deassert(priv->rst);
		if (err)
			goto err_put_clks;
	}

	if (pdata->big_endian_desc)
		ehci->big_endian_desc = 1;
	if (pdata->big_endian_mmio)
		ehci->big_endian_mmio = 1;
	if (pdata->has_tt)
		hcd->has_tt = 1;
	if (pdata->reset_on_resume)
		priv->reset_on_resume = true;
	if (pdata->ignore_oc)
		ehci->ignore_oc = 1;
	if (pdata->qca_force_host_mode)
		ehci->qca_force_host_mode = 1;
	if (pdata->qca_force_16bit_ptw)
		ehci->qca_force_16bit_ptw = 1;

	if (pdata->reset_notifier)
		ehci->reset_notifier = ehci_ath79_reset_notifier;

#ifndef CONFIG_USB_EHCI_BIG_ENDIAN_MMIO
	if (ehci->big_endian_mmio) {
		dev_err(&dev->dev,
			"Error: CONFIG_USB_EHCI_BIG_ENDIAN_MMIO not set\n");
		err = -EINVAL;
		goto err_reset;
	}
#endif
#ifndef CONFIG_USB_EHCI_BIG_ENDIAN_DESC
	if (ehci->big_endian_desc) {
		dev_err(&dev->dev,
			"Error: CONFIG_USB_EHCI_BIG_ENDIAN_DESC not set\n");
		err = -EINVAL;
		goto err_reset;
	}
#endif

	if (pdata->power_on) {
		err = pdata->power_on(dev);
		if (err < 0)
			goto err_reset;
	}

	res_mem = platform_get_resource(dev, IORESOURCE_MEM, 0);
	hcd->regs = devm_ioremap_resource(&dev->dev, res_mem);
	if (IS_ERR(hcd->regs)) {
		err = PTR_ERR(hcd->regs);
		goto err_power;
	}
	hcd->rsrc_start = res_mem->start;
	hcd->rsrc_len = resource_size(res_mem);

	err = usb_add_hcd(hcd, irq, IRQF_SHARED);
	if (err)
		goto err_power;

	device_wakeup_enable(hcd->self.controller);
	platform_set_drvdata(dev, hcd);

	return err;

err_power:
	if (pdata->power_off)
		pdata->power_off(dev);
err_reset:
	if (priv->rst)
		reset_control_assert(priv->rst);
err_put_clks:
	while (--clk >= 0)
		clk_put(priv->clks[clk]);
err_put_hcd:
	if (pdata == &ehci_ath79_defaults)
		dev->dev.platform_data = NULL;

	usb_put_hcd(hcd);

	return err;
}

static int ehci_ath79_remove(struct platform_device *dev)
{
	struct usb_hcd *hcd = platform_get_drvdata(dev);
	struct usb_ehci_pdata *pdata = dev_get_platdata(&dev->dev);
	struct ehci_ath79_priv *priv = hcd_to_ehci_priv(hcd);
	int clk;

	usb_remove_hcd(hcd);

	if (pdata->power_off)
		pdata->power_off(dev);

	if (priv->rst)
		reset_control_assert(priv->rst);

	for (clk = 0; clk < EHCI_MAX_CLKS && priv->clks[clk]; clk++)
		clk_put(priv->clks[clk]);

	usb_put_hcd(hcd);

	if (pdata == &ehci_ath79_defaults)
		dev->dev.platform_data = NULL;

	return 0;
}

#ifdef CONFIG_PM_SLEEP
static int ehci_ath79_suspend(struct device *dev)
{
	struct usb_hcd *hcd = dev_get_drvdata(dev);
	struct usb_ehci_pdata *pdata = dev_get_platdata(dev);
	struct platform_device *pdev =
		container_of(dev, struct platform_device, dev);
	bool do_wakeup = device_may_wakeup(dev);
	int ret;

	ret = ehci_suspend(hcd, do_wakeup);
	if (ret)
		return ret;

	if (pdata->power_suspend)
		pdata->power_suspend(pdev);

	return ret;
}

static int ehci_ath79_resume(struct device *dev)
{
	struct usb_hcd *hcd = dev_get_drvdata(dev);
	struct usb_ehci_pdata *pdata = dev_get_platdata(dev);
	struct platform_device *pdev =
		container_of(dev, struct platform_device, dev);
	struct ehci_ath79_priv *priv = hcd_to_ehci_priv(hcd);

	if (pdata->power_on) {
		int err = pdata->power_on(pdev);

		if (err < 0)
			return err;
	}

	ehci_resume(hcd, priv->reset_on_resume);
	return 0;
}
#endif /* CONFIG_PM_SLEEP */

static const struct of_device_id ehci_ath79_ids[] = {
	{ .compatible = "qca,ath79-ehci", },
	{ .compatible = "qca,ap147-ehci", },
};
MODULE_DEVICE_TABLE(of, ehci_ath79_ids);

MODULE_DEVICE_TABLE(acpi, ehci_acpi_match);

static const struct platform_device_id ehci_ath79_table[] = {
	{ "ehci-ath79", 0 },
	{ }
};
MODULE_DEVICE_TABLE(platform, ehci_ath79_table);

static SIMPLE_DEV_PM_OPS(ehci_ath79_pm_ops, ehci_ath79_suspend,
	ehci_ath79_resume);

static struct platform_driver ehci_ath79_driver = {
	.id_table	= ehci_ath79_table,
	.probe		= ehci_ath79_probe,
	.remove		= ehci_ath79_remove,
	.shutdown	= usb_hcd_platform_shutdown,
	.driver		= {
		.name	= "ehci-ath79",
		.pm	= &ehci_ath79_pm_ops,
		.of_match_table = ehci_ath79_ids,
	}
};

static int __init ehci_ath79_init(void)
{
	if (usb_disabled())
		return -ENODEV;

	ehci_init_driver(&ehci_ath79_hc_driver, &platform_overrides);
	return platform_driver_register(&ehci_ath79_driver);
}
module_init(ehci_ath79_init);

static void __exit ehci_ath79_cleanup(void)
{
	platform_driver_unregister(&ehci_ath79_driver);
}
module_exit(ehci_ath79_cleanup);

MODULE_LICENSE("Dual BSD/GPL");
