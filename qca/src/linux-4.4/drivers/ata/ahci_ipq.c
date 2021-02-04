/* Copyright (c) 2015 - 2017, The Linux Foundation. All rights reserved.
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

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pm.h>
#include <linux/device.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/libata.h>
#include <linux/ahci_platform.h>
#include <linux/acpi.h>
#include <linux/pci_ids.h>
#include "libata.h"
#include "ahci.h"

#define IPQ_DRV_NAME "ahci-ipq"

struct ipq_ahci_priv {
	struct platform_device *ahci_pdev;
	struct ahci_host_priv *hpriv;
	void *preg_reset;
	int pstate;
};
struct ipq_ahci_priv *ipqpriv;

static const struct ata_port_info ipq_ahci_port_info = {
	.flags		= AHCI_FLAG_COMMON,
	.pio_mask	= ATA_PIO4,
	.udma_mask	= ATA_UDMA6,
	.port_ops	= &ahci_platform_ops,
};

static struct scsi_host_template ahci_platform_sht = {
	AHCI_SHT(IPQ_DRV_NAME),
};

#define SATA_PWR_STATE_DOWN	0x1
#define SATA_PWR_STATE_UP	0x2
#define SATA_RESET		0x00902c1c

static void ipq_ahci_hard_reset(struct device *dev)
{
	u32 reg;

	reg = readl_relaxed(ipqpriv->preg_reset);
	writel_relaxed(reg | BIT(0), ipqpriv->preg_reset);
	/* To make sure the write is complete before we move on */
	mb();

	reg = readl_relaxed(ipqpriv->preg_reset);
	writel_relaxed(reg & (~BIT(0)), ipqpriv->preg_reset);
	/* To make sure the write is complete before we move on */
	mb();
}

static int ipq_ahci_suspend(struct device *dev)
{
	struct ata_host *host = dev_get_drvdata(dev);
	struct device_type *apt = &ata_port_type;
	const struct dev_pm_ops *pm = apt->pm;
	struct ata_port *ap;
	int ret = 0, i;

	if (ipqpriv->pstate == SATA_PWR_STATE_UP) {
		for (i = 0; i < host->n_ports; i++) {
			ap = host->ports[i];
			/* Issue Port PM Suspend */
			ret = pm->runtime_suspend(&ap->tdev);
			if (ret) {
				dev_err(dev, "SATA controller port suspend failed\n");
				return ret;
			}
		}

		/* Issue Contoller PM Suspend */
		ret = ahci_platform_suspend_host(dev);
		if (ret) {
			dev_err(dev, "SATA controller host suspend failed\n");
			return ret;
		}

		for (i = 0; i < ipqpriv->hpriv->nports; i++) {
			if (!ipqpriv->hpriv->phys[i])
				continue;

			phy_power_off(ipqpriv->hpriv->phys[i]);
			phy_exit(ipqpriv->hpriv->phys[i]);
		}

		ahci_platform_disable_clks(ipqpriv->hpriv);
		ipqpriv->pstate = SATA_PWR_STATE_DOWN;
	} else {
		dev_warn(dev, "SATA device already in suspended state");
	}

	return ret;
}

static int ipq_ahci_resume(struct device *dev)
{
	struct ata_host *host = dev_get_drvdata(dev);
	struct device_type *apt = &ata_port_type;
	const struct dev_pm_ops *pm = apt->pm;
	struct ata_port *ap;
	int ret = 0, i;

	if (ipqpriv->pstate == SATA_PWR_STATE_DOWN) {

		ahci_platform_enable_clks(ipqpriv->hpriv);

		/* Issue SATA clock hard reset */
		ipq_ahci_hard_reset(dev);

		for (i = 0; i < ipqpriv->hpriv->nports; i++) {
			if (!ipqpriv->hpriv->phys[i])
				continue;

			phy_init(ipqpriv->hpriv->phys[i]);
			phy_power_on(ipqpriv->hpriv->phys[i]);
		}

		/* Issue Contoller PM Resume */
		ret = ahci_platform_resume_host(dev);
		if (ret) {
			dev_err(dev, "SATA controller resume failed\n");
			return ret;
		}
		for (i = 0; i < host->n_ports; i++) {
			/* Issue Port PM Resume */
			ap = host->ports[i];
			ret = pm->runtime_resume(&ap->tdev);
			if (ret) {
				dev_err(dev, "SATA controller port resume failed\n");
				return ret;
			}
		}
		ipqpriv->pstate = SATA_PWR_STATE_UP;
	} else {
		dev_warn(dev, "SATA device already in resume state");
	}

	return ret;
}

static ssize_t ipq_ahci_display_power_status(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	if (ipqpriv->pstate == SATA_PWR_STATE_UP)
		pr_info("\nSATA interface in full power state\n");
	else if (ipqpriv->pstate == SATA_PWR_STATE_DOWN)
		pr_info("\nSATA interface in suspended state\n");

	return 0;
}

static ssize_t ipq_ahci_process_power_request(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	if (buf[0] == '1')
		ipq_ahci_suspend(dev);
	else if (buf[0] == '0')
		ipq_ahci_resume(dev);

	return count;
}

static DEVICE_ATTR(ipq_ahci_suspend, S_IRUGO | S_IWUSR,
	ipq_ahci_display_power_status, ipq_ahci_process_power_request);

static int ipq_ahci_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct ahci_host_priv *hpriv;
	int rc;

	hpriv = ahci_platform_get_resources(pdev);
	if (IS_ERR(hpriv))
		return PTR_ERR(hpriv);

	rc = ahci_platform_enable_resources(hpriv);
	if (rc)
		return rc;

	of_property_read_u32(dev->of_node,
			     "ports-implemented", &hpriv->force_port_map);

	rc = ahci_platform_init_host(pdev, hpriv, &ipq_ahci_port_info,
				     &ahci_platform_sht);
	if (rc)
		goto disable_resources;

	ipqpriv = devm_kzalloc(dev, sizeof(*ipqpriv), GFP_KERNEL);
	if (!ipqpriv) {
		dev_err(dev, "can't alloc ahci_host_priv\n");
		rc =  -ENOMEM;
		goto disable_resources;
	}

	ipqpriv->ahci_pdev = pdev;
	ipqpriv->hpriv = hpriv;
	ipqpriv->pstate = SATA_PWR_STATE_UP;

	ipqpriv->preg_reset = devm_ioremap(dev, SATA_RESET,
					   sizeof(*(ipqpriv->preg_reset)));
	if (IS_ERR(ipqpriv->preg_reset)) {
		dev_err(dev, "can't ioremap for preg_reset\n");
		rc =  -ENOMEM;
		goto disable_resources;
	}

	rc = device_create_file(dev, &dev_attr_ipq_ahci_suspend);
	if (rc < 0) {
		dev_err(dev, "SATA failed to create suspend /sys endpoint err=%d\n", rc);
	}

	return 0;
disable_resources:
	ahci_platform_disable_resources(hpriv);
	return rc;
}

int ipq_ahci_remove(struct platform_device *pdev)
{
	ata_platform_remove_one(pdev);
	return 0;
}

static SIMPLE_DEV_PM_OPS(ipq_ahci_pm_ops, ahci_platform_suspend,
			 ahci_platform_resume);

static const struct of_device_id ipq_ahci_of_match[] = {
	{ .compatible = "qcom,ipq806x-ahci", },
	{},
};
MODULE_DEVICE_TABLE(of, ipq_ahci_of_match);

static const struct acpi_device_id ahci_acpi_match[] = {
	{ ACPI_DEVICE_CLASS(PCI_CLASS_STORAGE_SATA_AHCI, 0xffffff) },
	{},
};
MODULE_DEVICE_TABLE(acpi, ahci_acpi_match);

static struct platform_driver ipq_ahci_driver = {
	.probe = ipq_ahci_probe,
	.remove = ipq_ahci_remove,
	.driver = {
		.name = IPQ_DRV_NAME,
		.of_match_table = ipq_ahci_of_match,
		.acpi_match_table = ahci_acpi_match,
		.pm = &ipq_ahci_pm_ops,
	},
};
module_platform_driver(ipq_ahci_driver);

MODULE_DESCRIPTION("IPQ806x AHCI SATA platform driver");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_ALIAS("platform:ahci-ipq");
