/*
 *  Atheros AR7XXX/AR9XXX USB Host Controller device
 *
 *  Copyright (C) 2008-2011 Gabor Juhos <juhosg@openwrt.org>
 *  Copyright (C) 2008 Imre Kaloz <kaloz@openwrt.org>
 *
 *  Parts of this file are based on Atheros' 2.6.15 BSP
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/irq.h>
#include <linux/dma-mapping.h>
#include <linux/platform_device.h>
#include <linux/usb/ehci_pdriver.h>
#include <linux/usb/ohci_pdriver.h>

#include <asm/mach-ath79/ath79.h>
#include <asm/mach-ath79/ar71xx_regs.h>
#include "common.h"
#include "dev-usb.h"

static u64 ath79_usb_dmamask = DMA_BIT_MASK(32);

static struct usb_ohci_pdata ath79_ohci_pdata = {
};

static struct usb_ehci_pdata ath79_ehci_pdata_v1 = {
	.has_synopsys_hc_bug	= 1,
};

static struct usb_ehci_pdata ath79_ehci_pdata_v2 = {
	.caps_offset		= 0x100,
	.has_tt			= 1,
	.qca_force_host_mode	= 1,
	.qca_force_16bit_ptw	= 1,
};

static void __init ath79_usb_register(const char *name, int id,
				      unsigned long base, unsigned long size,
				      int irq, const void *data,
				      size_t data_size)
{
	struct resource res[2];
	struct platform_device *pdev;

	memset(res, 0, sizeof(res));

	res[0].flags = IORESOURCE_MEM;
	res[0].start = base;
	res[0].end = base + size - 1;

	res[1].flags = IORESOURCE_IRQ;
	res[1].start = irq;
	res[1].end = irq;

	pdev = platform_device_register_resndata(NULL, name, id,
						 res, ARRAY_SIZE(res),
						 data, data_size);

	if (IS_ERR(pdev)) {
		pr_err("ath79: unable to register USB at %08lx, err=%d\n",
		       base, (int) PTR_ERR(pdev));
		return;
	}

	pdev->dev.dma_mask = &ath79_usb_dmamask;
	pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
}

#define AR71XX_USB_RESET_MASK	(AR71XX_RESET_USB_HOST | \
				 AR71XX_RESET_USB_PHY | \
				 AR71XX_RESET_USB_OHCI_DLL)

static void __init ath79_usb_setup(void)
{
	void __iomem *usb_ctrl_base;

	ath79_device_reset_set(AR71XX_USB_RESET_MASK);
	mdelay(1000);
	ath79_device_reset_clear(AR71XX_USB_RESET_MASK);

	usb_ctrl_base = ioremap(AR71XX_USB_CTRL_BASE, AR71XX_USB_CTRL_SIZE);

	/* Turning on the Buff and Desc swap bits */
	__raw_writel(0xf0000, usb_ctrl_base + AR71XX_USB_CTRL_REG_CONFIG);

	/* WAR for HW bug. Here it adjusts the duration between two SOFS */
	__raw_writel(0x20c00, usb_ctrl_base + AR71XX_USB_CTRL_REG_FLADJ);

	iounmap(usb_ctrl_base);

	mdelay(900);

	ath79_usb_register("ohci-platform", -1,
			   AR71XX_OHCI_BASE, AR71XX_OHCI_SIZE,
			   ATH79_MISC_IRQ(6),
			   &ath79_ohci_pdata, sizeof(ath79_ohci_pdata));

	ath79_usb_register("ehci-platform", -1,
			   AR71XX_EHCI_BASE, AR71XX_EHCI_SIZE,
			   ATH79_CPU_IRQ(3),
			   &ath79_ehci_pdata_v1, sizeof(ath79_ehci_pdata_v1));
}

static void __init ar7240_usb_setup(void)
{
	void __iomem *usb_ctrl_base;

	ath79_device_reset_clear(AR7240_RESET_OHCI_DLL);
	ath79_device_reset_set(AR7240_RESET_USB_HOST);

	mdelay(1000);

	ath79_device_reset_set(AR7240_RESET_OHCI_DLL);
	ath79_device_reset_clear(AR7240_RESET_USB_HOST);

	usb_ctrl_base = ioremap(AR7240_USB_CTRL_BASE, AR7240_USB_CTRL_SIZE);

	/* WAR for HW bug. Here it adjusts the duration between two SOFS */
	__raw_writel(0x3, usb_ctrl_base + AR71XX_USB_CTRL_REG_FLADJ);

	iounmap(usb_ctrl_base);

	ath79_usb_register("ohci-platform", -1,
			   AR7240_OHCI_BASE, AR7240_OHCI_SIZE,
			   ATH79_CPU_IRQ(3),
			   &ath79_ohci_pdata, sizeof(ath79_ohci_pdata));
}

static void __init ar724x_usb_setup(void)
{
	ath79_device_reset_set(AR724X_RESET_USBSUS_OVERRIDE);
	mdelay(10);

	ath79_device_reset_clear(AR724X_RESET_USB_HOST);
	mdelay(10);

	ath79_device_reset_clear(AR724X_RESET_USB_PHY);
	mdelay(10);

	ath79_usb_register("ehci-platform", -1,
			   AR724X_EHCI_BASE, AR724X_EHCI_SIZE,
			   ATH79_CPU_IRQ(3),
			   &ath79_ehci_pdata_v2, sizeof(ath79_ehci_pdata_v2));
}

static void __init ar913x_usb_setup(void)
{
	ath79_device_reset_set(AR913X_RESET_USBSUS_OVERRIDE);
	mdelay(10);

	ath79_device_reset_clear(AR913X_RESET_USB_HOST);
	mdelay(10);

	ath79_device_reset_clear(AR913X_RESET_USB_PHY);
	mdelay(10);

	ath79_ehci_pdata_v2.qca_force_host_mode	= 0;
	ath79_ehci_pdata_v2.qca_force_16bit_ptw	= 0;

	ath79_usb_register("ehci-platform", -1,
			   AR913X_EHCI_BASE, AR913X_EHCI_SIZE,
			   ATH79_CPU_IRQ(3),
			   &ath79_ehci_pdata_v2, sizeof(ath79_ehci_pdata_v2));
}

static void __init ar933x_usb_setup(void)
{
	ath79_device_reset_set(AR933X_RESET_USBSUS_OVERRIDE);
	mdelay(10);

	ath79_device_reset_clear(AR933X_RESET_USB_HOST);
	mdelay(10);

	ath79_device_reset_clear(AR933X_RESET_USB_PHY);
	mdelay(10);

	ath79_usb_register("ehci-platform", -1,
			   AR933X_EHCI_BASE, AR933X_EHCI_SIZE,
			   ATH79_CPU_IRQ(3),
			   &ath79_ehci_pdata_v2, sizeof(ath79_ehci_pdata_v2));
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

static void ar934x_usb_reset_notifier(struct platform_device *pdev)
{
	if (pdev->id != -1)
		return;

	enable_tx_tx_idp_violation_fix(0x18116c94);
	dev_info(&pdev->dev, "TX-TX IDP fix enabled\n");
}

static void __init ar934x_usb_setup(void)
{
	ath79_device_reset_set(AR934X_RESET_USBSUS_OVERRIDE);
	udelay(1000);

	ath79_device_reset_clear(AR934X_RESET_USB_PHY);
	udelay(1000);

	ath79_device_reset_clear(AR934X_RESET_USB_PHY_ANALOG);
	udelay(1000);

	ath79_device_reset_clear(AR934X_RESET_USB_HOST);
	udelay(1000);

	if (ath79_soc_rev >= 3)
		ath79_ehci_pdata_v2.reset_notifier = ar934x_usb_reset_notifier;

	ath79_usb_register("ehci-platform", -1,
			   AR934X_EHCI_BASE, AR934X_EHCI_SIZE,
			   ATH79_CPU_IRQ(3),
			   &ath79_ehci_pdata_v2, sizeof(ath79_ehci_pdata_v2));
}

static void __init qca953x_usb_setup(void)
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

	ath79_usb_register("ehci-platform", -1,
			   QCA953X_EHCI_BASE, QCA953X_EHCI_SIZE,
			   ATH79_CPU_IRQ(3),
			   &ath79_ehci_pdata_v2, sizeof(ath79_ehci_pdata_v2));
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

static void __init qca955x_usb_setup(void)
{
	ath79_ehci_pdata_v2.reset_notifier = qca955x_usb_reset_notifier;

	ath79_usb_register("ehci-platform", 0,
			   QCA955X_EHCI0_BASE, QCA955X_EHCI_SIZE,
			   ATH79_IP3_IRQ(0),
			   &ath79_ehci_pdata_v2, sizeof(ath79_ehci_pdata_v2));

	ath79_usb_register("ehci-platform", 1,
			   QCA955X_EHCI1_BASE, QCA955X_EHCI_SIZE,
			   ATH79_IP3_IRQ(1),
			   &ath79_ehci_pdata_v2, sizeof(ath79_ehci_pdata_v2));
}

static void __init qca956x_usb_setup(void)
{
	ath79_usb_register("ehci-platform", 0,
			   QCA956X_EHCI0_BASE, QCA956X_EHCI_SIZE,
			   ATH79_IP3_IRQ(0),
			   &ath79_ehci_pdata_v2, sizeof(ath79_ehci_pdata_v2));

	ath79_usb_register("ehci-platform", 1,
			   QCA956X_EHCI1_BASE, QCA956X_EHCI_SIZE,
			   ATH79_IP3_IRQ(1),
			   &ath79_ehci_pdata_v2, sizeof(ath79_ehci_pdata_v2));
}

static void __init qcn550x_usb_setup(void)
{
	ath79_usb_register("ehci-platform", 0,
			   QCN550X_EHCI0_BASE, QCN550X_EHCI_SIZE,
			   ATH79_IP3_IRQ(0),
			   &ath79_ehci_pdata_v2, sizeof(ath79_ehci_pdata_v2));
}

void __init ath79_register_usb(void)
{
	if (soc_is_ar71xx())
		ath79_usb_setup();
	else if (soc_is_ar7240())
		ar7240_usb_setup();
	else if (soc_is_ar7241() || soc_is_ar7242())
		ar724x_usb_setup();
	else if (soc_is_ar913x())
		ar913x_usb_setup();
	else if (soc_is_ar933x())
		ar933x_usb_setup();
	else if (soc_is_ar934x())
		ar934x_usb_setup();
	else if (soc_is_qca953x())
		qca953x_usb_setup();
	else if (soc_is_qca955x())
		qca955x_usb_setup();
	else if (soc_is_qca956x())
		qca956x_usb_setup();
	else if (soc_is_qcn550x())
		qcn550x_usb_setup();
	else
		BUG();
}
