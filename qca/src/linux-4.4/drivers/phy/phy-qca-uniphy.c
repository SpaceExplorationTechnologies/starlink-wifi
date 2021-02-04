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
#include <linux/dma-mapping.h>
#include <linux/qcom_scm.h>
#include <linux/slab.h>

#define USB_CALIBRATION_CMD	0x10
#define USB3PHY_SPARE_1		0x7FC
#define RX_LOS_1		0x7C8
#define MISC_SOURCE_REG		0x21c
#define CDR_CONTROL_REG_1	0x80
#define PCS_INTERNAL_CONTROL14	0x364
#define MMD1_REG_REG_MASK	(0x7F << 8)
#define OTP_MASK		(0x7F << 5)
#define MMD1_REG_AUTOLOAD_MASK	(0x1 << 7)
#define SPARE_1_BIT14_MASK	(0x1 << 14)

struct qca_uni_ss_phy {
	struct phy phy;
	struct device *dev;

	void __iomem *base;

	struct reset_control *por_rst;

	unsigned int host;
};

struct qf_read {
	uint32_t value;
};

#define	phy_to_dw_phy(x)	container_of((x), struct qca_uni_ss_phy, phy)

/**
 * Write register
 *
 * @base - PHY base virtual address.
 * @offset - register offset.
 */
static u32 qca_uni_ss_read(void __iomem *base, u32 offset)
{
	u32 value;
	value = readl_relaxed(base + offset);
	return value;
}

/**
 * Write register
 *
 * @base - PHY base virtual address.
 * @offset - register offset.
 * @val - value to write.
 */
static void qca_uni_ss_write(void __iomem *base, u32 offset, u32 val)
{
	writel(val, base + offset);
	udelay(100);
}

static int qca_uni_ss_phy_shutdown(struct phy *x)
{
	struct qca_uni_ss_phy *phy = phy_get_drvdata(x);

	/* assert SS PHY POR reset */
	reset_control_assert(phy->por_rst);

	return 0;
}

/* Function to read the value from OTP through scm call */
int qca_uni_ss_read_otp(uint32_t *otp_read_data)
{
	int ret;
	uint32_t *otp_value = kzalloc(sizeof(uint32_t), GFP_KERNEL);
	struct qf_read rdip;

	if (!otp_value)
		return -ENOMEM;

	rdip.value = dma_map_single(NULL, otp_value,
			sizeof(uint32_t), DMA_FROM_DEVICE);

	ret = dma_mapping_error(NULL, rdip.value);
	if (ret != 0) {
		pr_err("DMA Mapping Error\n");
		goto err_write;
	}

	ret = qcom_los_scm_call(NULL, QCOM_SCM_SVC_FUSE, USB_CALIBRATION_CMD,
		&rdip, sizeof(struct qf_read));

	dma_unmap_single(NULL, rdip.value,
		sizeof(uint32_t), DMA_FROM_DEVICE);

	if (ret != 0) {
		pr_err("Error in reading value: %d\n", ret);
		goto err_write;
	}

	*otp_read_data = *otp_value;
err_write:
	kfree(otp_value);
	return ret;
}

int qca_uni_ss_phy_usb_los_calibration(void __iomem *base)
{
	uint32_t data, otp_val = 0;

	/* Get OTP value */
	if ((qca_uni_ss_read_otp(&otp_val) < 0) || (!(otp_val & OTP_MASK))) {
		pr_err("USB Calibration Falied with error %d\n", otp_val);
		return 0;
	}

	/*
	 * Read the USB3PHY_SPARE_1 register and
	 * set bit 14 to 0
	 */
	data = qca_uni_ss_read(base, USB3PHY_SPARE_1);
	data = data & (~SPARE_1_BIT14_MASK);
	qca_uni_ss_write(base, USB3PHY_SPARE_1, data);

	/*
	 * Get bit 11:5 value, add with 0x14 and set to the
	 * register USB3PHY_RX_LOS_1 bit MMD1_REG_REG
	 */
	data = qca_uni_ss_read(base, RX_LOS_1);
	otp_val = ((otp_val & OTP_MASK) >> 5) + 0x14;
	otp_val = otp_val << 8;
	data = data & (~MMD1_REG_REG_MASK);
	data = data | otp_val;
	qca_uni_ss_write(base, RX_LOS_1, data);

	/*
	 * Set bit MMD1_REG_AUTOLOAD_SEL_RX_LOS_THRES in
	 * USB3PHY_RX_LOS_1 to 1
	 */
	data = qca_uni_ss_read(base, RX_LOS_1);
	data = data | MMD1_REG_AUTOLOAD_MASK;
	qca_uni_ss_write(base, RX_LOS_1, data);

	qca_uni_ss_write(base, PCS_INTERNAL_CONTROL14, 0x4000);
	qca_uni_ss_write(base, MISC_SOURCE_REG, 0xaa0a);
	qca_uni_ss_write(base, CDR_CONTROL_REG_1, 0x0202);

	return 0;
}

static int qca_uni_ss_phy_init(struct phy *x)
{
	int ret;
	struct qca_uni_ss_phy *phy = phy_get_drvdata(x);

	/* assert SS PHY POR reset */
	reset_control_assert(phy->por_rst);

	msleep(100);

	/* deassert SS PHY POR reset */
	reset_control_deassert(phy->por_rst);

	/* USB LOS Calibration */
	ret = qca_uni_ss_phy_usb_los_calibration(phy->base);

	return ret;
}

static int qca_uni_ss_get_resources(struct platform_device *pdev,
		struct qca_uni_ss_phy *phy)
{
	struct resource *res;
	struct device_node *np = NULL;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	phy->base = devm_ioremap_resource(phy->dev, res);
	if (IS_ERR(phy->base))
		return PTR_ERR(phy->base);

	phy->por_rst = devm_reset_control_get(phy->dev, "por_rst");
	if (IS_ERR(phy->por_rst))
		return PTR_ERR(phy->por_rst);

	np = of_node_get(pdev->dev.of_node);
	if (of_property_read_u32(np, "qca,host", &phy->host)) {
		pr_err("%s: error reading critical device node properties\n",
				np->name);
		return -EFAULT;
	}

	return 0;
}

static const struct of_device_id qca_uni_ss_id_table[] = {
	{ .compatible = "qca,uni-ssphy" },
	{ /* Sentinel */ }
};
MODULE_DEVICE_TABLE(of, qca_uni_ss_id_table);

static const struct phy_ops ops = {
	.init           = qca_uni_ss_phy_init,
	.exit           = qca_uni_ss_phy_shutdown,
	.owner          = THIS_MODULE,
};
static int qca_uni_ss_probe(struct platform_device *pdev)
{
	const struct of_device_id *match;
	struct qca_uni_ss_phy  *phy;
	int ret;
	struct phy *generic_phy;
	struct phy_provider *phy_provider;

	match = of_match_device(qca_uni_ss_id_table, &pdev->dev);
	if (!match)
		return -ENODEV;

	phy = devm_kzalloc(&pdev->dev, sizeof(*phy), GFP_KERNEL);
	if (!phy)
		return -ENOMEM;

	platform_set_drvdata(pdev, phy);
	phy->dev = &pdev->dev;

	ret = qca_uni_ss_get_resources(pdev, phy);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to request resources: %d\n", ret);
		return ret;
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

static struct platform_driver qca_uni_ss_driver = {
	.probe		= qca_uni_ss_probe,
	.driver		= {
		.name	= "qca-uni-ssphy",
		.owner	= THIS_MODULE,
		.of_match_table = qca_uni_ss_id_table,
	},
};

module_platform_driver(qca_uni_ss_driver);

MODULE_ALIAS("platform:qca-uni-ssphy");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("USB3 QCA UNI SSPHY driver");
