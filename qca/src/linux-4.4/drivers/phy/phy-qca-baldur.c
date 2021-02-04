/* Copyright (c) 2015, The Linux Foundation. All rights reserved.
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

#include <linux/clk.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/regulator/consumer.h>
#include <linux/phy/phy.h>
#include <linux/reset.h>
#include <linux/of_device.h>
#include <linux/delay.h>

/**
 *  USB Hardware registers
 */
#define PHY_CTRL0_ADDR	0x000
#define PHY_CTRL1_ADDR	0x004
#define PHY_CTRL2_ADDR	0x008
#define PHY_CTRL3_ADDR	0x00C
#define PHY_CTRL4_ADDR	0x010
#define PHY_MISC_ADDR	0x024
#define PHY_IPG_ADDR	0x030

#define PHY_CTRL0_VAL	0xA4600015
#define PHY_CTRL1_VAL	0x09500000
#define PHY_CTRL2_VAL	0x00058180
#define PHY_CTRL3_VAL	0x6DB6DCD6
#define PHY_CTRL4_VAL	0x836DB6DB
#define PHY_MISC_VAL	0x3803FB0C
#define PHY_IPG_VAL	0x47323232

#define USB30_HS_PHY_HOST_MODE	(0x01 << 21)
#define USB20_HS_PHY_HOST_MODE	(0x01 << 5)

#define USB30_HS_PHY_CTRL	0x10
#define SW_SESSVLD		(0x01 << 0x1C)
#define UTMI_OTG_VBUS_VALID	(0x01 << 0x14)
#define USB30_SS_PHY_CTRL	0x30
#define LANE0_PWR_PRESENT	(0x01 << 0x18)

struct qca_baldur_hs_phy {
	struct device *dev;
	struct phy phy;

	void __iomem *base;
	void __iomem *qscratch_base;

	struct reset_control *por_rst;
	struct reset_control *srif_rst;

	unsigned int host;
};

#define	phy_to_dw_phy(x)	container_of((x), struct qca_baldur_hs_phy, phy)

/**
 * Write register.
 *
 * @base - PHY base virtual address.
 * @offset - register offset.
 * @val - value to write.
 */
static inline void qca_baldur_hs_write(void __iomem *base, u32 offset, u32 val)
{
	writel(val, base + offset);
}

/**
 * Read register.
 *
 * @base - PHY base virtual address.
 * @offset - register offset.
 */
static inline u32 qca_baldur_hs_read(void __iomem *base, u32 offset)
{
	u32 val;

	val = readl(base + offset);
	return val;
}

static int qca_baldur_phy_read(struct phy *x, u32 reg)
{
	struct qca_baldur_hs_phy *phy = phy_get_drvdata(x);

	return qca_baldur_hs_read(phy->base, reg);
}

static int qca_baldur_phy_write(struct phy *x, u32 val, u32 reg)
{
	struct qca_baldur_hs_phy *phy = phy_get_drvdata(x);

	qca_baldur_hs_write(phy->base, reg, val);
	return 0;
}

static int qca_baldur_hs_phy_init(struct phy *x)
{
	struct qca_baldur_hs_phy	*phy = phy_get_drvdata(x);

	/* assert HS PHY POR reset */
	reset_control_assert(phy->por_rst);
	/* As per PHY design spec, the reset requires a minimum of 20us. */
	usleep_range(20, 50);

	/* assert HS PHY SRIF reset */
	reset_control_assert(phy->srif_rst);
	/* As per PHY design spec, the reset requires a minimum of 20us. */
	usleep_range(20, 50);

	/* deassert HS PHY SRIF reset and program HS PHY registers */
	reset_control_deassert(phy->srif_rst);
	/* As per PHY design spec, the reset requires a minimum of 20us. */
	usleep_range(20, 50);

	/* perform PHY register writes */
	qca_baldur_hs_write(phy->base, PHY_CTRL0_ADDR, PHY_CTRL0_VAL);
	qca_baldur_hs_write(phy->base, PHY_CTRL1_ADDR, PHY_CTRL1_VAL);
	qca_baldur_hs_write(phy->base, PHY_CTRL2_ADDR, PHY_CTRL2_VAL);
	qca_baldur_hs_write(phy->base, PHY_CTRL3_ADDR, PHY_CTRL3_VAL);
	qca_baldur_hs_write(phy->base, PHY_CTRL4_ADDR, PHY_CTRL4_VAL);
	qca_baldur_hs_write(phy->base, PHY_MISC_ADDR, PHY_MISC_VAL);
	qca_baldur_hs_write(phy->base, PHY_IPG_ADDR, PHY_IPG_VAL);

	usleep_range(20, 50);

	/* de-assert USB3 HS PHY POR reset */
	reset_control_deassert(phy->por_rst);

	return 0;
}

static int qca_baldur_hs_get_resources(struct qca_baldur_hs_phy *phy)
{
	struct platform_device *pdev = to_platform_device(phy->dev);
	struct resource *res;
	struct device_node *np = NULL;
	uint32_t write_val;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	phy->base = devm_ioremap_resource(phy->dev, res);
	if (IS_ERR(phy->base))
		return PTR_ERR(phy->base);

	phy->por_rst = devm_reset_control_get(phy->dev, "por_rst");
	if (IS_ERR(phy->por_rst))
		return PTR_ERR(phy->por_rst);

	phy->srif_rst = devm_reset_control_get(phy->dev, "srif_rst");
	if (IS_ERR(phy->srif_rst))
		return PTR_ERR(phy->srif_rst);

	np = of_node_get(pdev->dev.of_node);
	if (of_property_read_u32(np, "qca,host", &phy->host)) {
		pr_err("%s: error reading critical device node properties\n",
				np->name);
		return -EFAULT;
	} else {
		if (!phy->host) {
			res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
			if (!res) {
				dev_err(&pdev->dev, "%s: no mem resource\n",
						__func__);
				return -EINVAL;
			}
			phy->qscratch_base = devm_ioremap_nocache(phy->dev,
					res->start, resource_size(res));
			if (IS_ERR(phy->qscratch_base)) {
				pr_err("%s: error mapping QSCRATCH addr\n",
						np->name);
				return PTR_ERR(phy->qscratch_base );
			}

			/* Enable VBUS valid for HS PHY*/
			write_val = readl(phy->qscratch_base + USB30_HS_PHY_CTRL);
			write_val = write_val | SW_SESSVLD;
			writel(write_val, phy->qscratch_base + USB30_HS_PHY_CTRL);

			write_val = readl(phy->qscratch_base + USB30_HS_PHY_CTRL);
			write_val = write_val | UTMI_OTG_VBUS_VALID;
			writel(write_val, phy->qscratch_base + USB30_HS_PHY_CTRL);

			/* Enable VBUS valid for SS PHY*/
			write_val = readl(phy->qscratch_base + USB30_SS_PHY_CTRL);
			write_val = write_val | LANE0_PWR_PRESENT;
			writel(write_val, phy->qscratch_base + USB30_SS_PHY_CTRL);
		}
	}

	return 0;
}

static void qca_baldur_hs_put_resources(struct qca_baldur_hs_phy *phy)
{
	reset_control_assert(phy->srif_rst);
	reset_control_assert(phy->por_rst);
}

static int qca_baldur_hs_phy_shutdown(struct phy *x)
{
	struct qca_baldur_hs_phy   *phy = phy_get_drvdata(x);

	qca_baldur_hs_put_resources(phy);
	return 0;
}

static const struct of_device_id qca_baldur_hs_id_table[] = {
	{ .compatible = "qca,baldur-usb-hsphy" },
	{ /* Sentinel */ }
};
MODULE_DEVICE_TABLE(of, qca_baldur_hs_id_table);

static const struct phy_ops ops = {
	.init           = qca_baldur_hs_phy_init,
	.exit           = qca_baldur_hs_phy_shutdown,
	.read		= qca_baldur_phy_read,
	.write		= qca_baldur_phy_write,
	.owner          = THIS_MODULE,
};

static int qca_baldur_hs_probe(struct platform_device *pdev)
{
	const struct of_device_id *match;
	struct qca_baldur_hs_phy *phy;
	int err;
	struct phy *generic_phy;
	struct phy_provider *phy_provider;

	match = of_match_device(qca_baldur_hs_id_table, &pdev->dev);
	if (!match)
		return -ENODEV;

	phy = devm_kzalloc(&pdev->dev, sizeof(*phy), GFP_KERNEL);
	if (!phy)
		return -ENOMEM;

	platform_set_drvdata(pdev, phy);
	phy->dev = &pdev->dev;

	err = qca_baldur_hs_get_resources(phy);
	if (err < 0) {
		dev_err(&pdev->dev, "failed to request resources: %d\n", err);
		return err;
	}

	generic_phy = devm_phy_create(phy->dev, NULL, &ops);
	if (IS_ERR(generic_phy))
		return PTR_ERR(generic_phy);

	phy_set_drvdata(generic_phy, phy);
	phy_provider = devm_of_phy_provider_register(phy->dev,
				of_phy_simple_xlate);
	if (IS_ERR(phy_provider))
		return PTR_ERR(phy_provider);

	return 0;
}

static struct platform_driver qca_baldur_hs_driver = {
	.probe		= qca_baldur_hs_probe,
	.driver		= {
		.name	= "qca-baldur-hsphy",
		.owner	= THIS_MODULE,
		.of_match_table = qca_baldur_hs_id_table,
	},
};

module_platform_driver(qca_baldur_hs_driver);

MODULE_ALIAS("platform:qca-baldur-hsphy");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("USB3 QCA BALDUR HSPHY driver");
