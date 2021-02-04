/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/of_address.h>
#include <linux/of_mdio.h>
#include <linux/phy.h>
#include <linux/platform_device.h>
#include <linux/of_gpio.h>

#define MDIO_CTRL_0_REG		0x40
#define MDIO_CTRL_1_REG		0x44
#define MDIO_CTRL_2_REG		0x48
#define MDIO_CTRL_3_REG		0x4c
#define MDIO_CTRL_4_REG		0x50
#define MDIO_CTRL_4_ACCESS_BUSY		BIT(16)
#define MDIO_CTRL_4_ACCESS_START	BIT(8)
#define MDIO_CTRL_4_ACCESS_CODE_READ	0
#define MDIO_CTRL_4_ACCESS_CODE_WRITE	1
#define MDIO_CTRL_4_ACCESS_CODE_C45_ADDR	0
#define MDIO_CTRL_4_ACCESS_CODE_C45_WRITE	1
#define MDIO_CTRL_4_ACCESS_CODE_C45_READ	2
#define CTRL_0_REG_DEFAULT_VALUE	0x1500F
#define CTRL_0_REG_C45_DEFAULT_VALUE	0x1510F

#define QCA_MDIO_RETRY	1000
#define QCA_MDIO_DELAY	10

#define QCA_MAX_PHY_RESET	3

struct qca_mdio_data {
	struct mii_bus *mii_bus;
	void __iomem *membase;
	int phy_irq[PHY_MAX_ADDR];
};

static int qca_mdio_wait_busy(struct qca_mdio_data *am)
{
	int i;

	for (i = 0; i < QCA_MDIO_RETRY; i++) {
		unsigned int busy;

		busy = readl(am->membase + MDIO_CTRL_4_REG);
		busy &= MDIO_CTRL_4_ACCESS_BUSY;
		if (!busy)
			return 0;

		udelay(QCA_MDIO_DELAY);
	}

	pr_err("%s: MDIO operation timed out\n", am->mii_bus->name);

	return -ETIMEDOUT;
}

static int qca_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
	struct qca_mdio_data *am = bus->priv;
	int value = 0;
	unsigned int cmd = 0;

	if (qca_mdio_wait_busy(am))
		return 0xffff;

	if (regnum & MII_ADDR_C45) {
		unsigned int mmd = (regnum >> 16) & 0x1F;
		unsigned int reg = regnum & 0xFFFF;

		writel(CTRL_0_REG_C45_DEFAULT_VALUE,
		       am->membase + MDIO_CTRL_0_REG);
		/* issue the phy address and mmd */
		writel((mii_id << 8) | mmd, am->membase + MDIO_CTRL_1_REG);
		/* issue reg */
		writel(reg, am->membase + MDIO_CTRL_2_REG);
		cmd = MDIO_CTRL_4_ACCESS_START |
			MDIO_CTRL_4_ACCESS_CODE_C45_ADDR;
	} else {
		writel(CTRL_0_REG_DEFAULT_VALUE, am->membase + MDIO_CTRL_0_REG);
		/* issue the phy address and reg */
		writel((mii_id << 8) | regnum, am->membase + MDIO_CTRL_1_REG);
		cmd = MDIO_CTRL_4_ACCESS_START | MDIO_CTRL_4_ACCESS_CODE_READ;
	}

	/* issue command */
	writel(cmd, am->membase + MDIO_CTRL_4_REG);

	/* Wait complete */
	if (qca_mdio_wait_busy(am))
		return 0xffff;

	if (regnum & MII_ADDR_C45) {
		cmd = MDIO_CTRL_4_ACCESS_START |
			MDIO_CTRL_4_ACCESS_CODE_C45_READ;
		writel(cmd, am->membase + MDIO_CTRL_4_REG);
		if (qca_mdio_wait_busy(am))
			return 0xffff;
	}

	/* Read data */
	value = readl(am->membase + MDIO_CTRL_3_REG);

	return value;
}

static int qca_mdio_write(struct mii_bus *bus, int mii_id, int regnum,
			  u16 value)
{
	struct qca_mdio_data *am = bus->priv;
	unsigned int cmd = 0;

	if (qca_mdio_wait_busy(am))
		return 0xffff;

	if (regnum & MII_ADDR_C45) {
		unsigned int mmd = (regnum >> 16) & 0x1F;
		unsigned int reg = regnum & 0xFFFF;

		writel(CTRL_0_REG_C45_DEFAULT_VALUE,
		       am->membase + MDIO_CTRL_0_REG);
		/* issue the phy address and mmd */
		writel((mii_id << 8) | mmd, am->membase + MDIO_CTRL_1_REG);
		/* issue reg */
		writel(reg, am->membase + MDIO_CTRL_2_REG);
		cmd = MDIO_CTRL_4_ACCESS_START |
			MDIO_CTRL_4_ACCESS_CODE_C45_ADDR;
		writel(cmd, am->membase + MDIO_CTRL_4_REG);
		if (qca_mdio_wait_busy(am))
			return -ETIMEDOUT;
	} else {
		writel(CTRL_0_REG_DEFAULT_VALUE, am->membase + MDIO_CTRL_0_REG);
		/* issue the phy address and reg */
		writel((mii_id << 8) | regnum, am->membase + MDIO_CTRL_1_REG);
	}

	/* issue write data */
	writel(value, am->membase + MDIO_CTRL_2_REG);

	/* issue write command */
	if (regnum & MII_ADDR_C45)
		cmd = MDIO_CTRL_4_ACCESS_START |
			MDIO_CTRL_4_ACCESS_CODE_C45_WRITE;
	else
		cmd = MDIO_CTRL_4_ACCESS_START | MDIO_CTRL_4_ACCESS_CODE_WRITE;
	writel(cmd, am->membase + MDIO_CTRL_4_REG);

	/* Wait write complete */
	if (qca_mdio_wait_busy(am))
		return -ETIMEDOUT;

	return 0;
}

static int qca_phy_gpio_set(struct platform_device *pdev, int number)
{
	int ret;

	ret = gpio_request(number, "phy-reset-gpio");
	if (ret) {
		dev_err(&pdev->dev, "Can't get phy-reset-gpio %d\n", ret);
		return ret;
	}

	ret = gpio_direction_output(number, 0x0);
	if (ret) {
		dev_err(&pdev->dev,
			"Can't set direction for phy-reset-gpio %d\n", ret);
		goto phy_reset_out;
	}

	usleep_range(100000, 110000);

	gpio_set_value(number, 0x01);

	usleep_range(100000, 110000);

phy_reset_out:
	gpio_free(number);

	return ret;
}

static int qca_phy_reset(struct platform_device *pdev)
{
	struct device_node *mdio_node;
	int phy_reset_gpio_number;
	int ret, i;

	mdio_node = of_find_node_by_name(NULL, "mdio");
	if (!mdio_node) {
		dev_err(&pdev->dev, "Could not find mdio node\n");
		return -ENOENT;
	}

	for (i = 0; i < QCA_MAX_PHY_RESET; i++) {
		ret = of_get_named_gpio(mdio_node, "phy-reset-gpio", i);
		if (ret < 0) {
			dev_info(&pdev->dev, "Could not find phy-reset-gpio\n");
			return 0;
		}

		phy_reset_gpio_number = ret;
		ret = qca_phy_gpio_set(pdev, phy_reset_gpio_number);
		if (ret)
			return ret;
	}

	return 0;
}

static int qca_mdio_probe(struct platform_device *pdev)
{
	struct qca_mdio_data *am;
	struct resource *res;
	int ret, i;

	ret = qca_phy_reset(pdev);
	if (ret)
		dev_err(&pdev->dev, "Could not find qca8075 reset gpio\n");

	am = devm_kzalloc(&pdev->dev, sizeof(*am), GFP_KERNEL);
	if (!am)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(&pdev->dev, "no iomem resource found\n");
		ret = -ENXIO;
		goto err_free_mdio;
	}

	am->membase = devm_ioremap_resource(&pdev->dev, res);
	if (!am->membase) {
		dev_err(&pdev->dev, "unable to ioremap registers\n");
		ret = -ENOMEM;
		goto err_free_mdio;
	}

	am->mii_bus = mdiobus_alloc();
	if (!am->mii_bus) {
		ret = -ENOMEM;
		goto err_iounmap;
	}

	writel(CTRL_0_REG_DEFAULT_VALUE, am->membase + MDIO_CTRL_0_REG);

	am->mii_bus->name = "qca_mdio";
	am->mii_bus->read = &qca_mdio_read;
	am->mii_bus->write = &qca_mdio_write;
	am->mii_bus->irq = am->phy_irq;
	am->mii_bus->priv = am;
	am->mii_bus->parent = &pdev->dev;
	snprintf(am->mii_bus->id, MII_BUS_ID_SIZE, "%s", dev_name(&pdev->dev));

	for (i = 0; i < PHY_MAX_ADDR; i++)
		am->phy_irq[i] = PHY_POLL;

	platform_set_drvdata(pdev, am);

	ret = of_mdiobus_register(am->mii_bus, pdev->dev.of_node);
	if (ret)
		goto err_free_bus;

	dev_info(&pdev->dev, "qca-mdio driver was registered\n");

	return 0;

err_free_bus:
	mdiobus_free(am->mii_bus);
err_iounmap:
	iounmap(am->membase);
err_free_mdio:
	kfree(am);
err_out:
	return ret;
}

static int qca_mdio_remove(struct platform_device *pdev)
{
	struct qca_mdio_data *am = platform_get_drvdata(pdev);

	if (am) {
		mdiobus_unregister(am->mii_bus);
		mdiobus_free(am->mii_bus);
		iounmap(am->membase);
		kfree(am);
		platform_set_drvdata(pdev, NULL);
	}

	return 0;
}

static const struct of_device_id qca_mdio_dt_ids[] = {
	{ .compatible = "qcom,ipq40xx-mdio" },
	{ .compatible = "qcom,qca-mdio" },
	{ }
};
MODULE_DEVICE_TABLE(of, qca_mdio_dt_ids);

static struct platform_driver qca_mdio_driver = {
	.probe = qca_mdio_probe,
	.remove = qca_mdio_remove,
	.driver = {
		.name = "qca-mdio",
		.of_match_table = qca_mdio_dt_ids,
	},
};

module_platform_driver(qca_mdio_driver);

MODULE_DESCRIPTION("QCA MDIO interface driver");
MODULE_LICENSE("Dual BSD/GPL");
