/*
 *  Atheros AR71XX/AR724X/AR913X GPIO API support
 *
 *  Copyright (C) 2010-2011 Jaiganesh Narayanan <jnarayanan@atheros.com>
 *  Copyright (C) 2008-2011 Gabor Juhos <juhosg@openwrt.org>
 *  Copyright (C) 2008 Imre Kaloz <kaloz@openwrt.org>
 *
 *  Parts of this file are based on Atheros' 2.6.15/2.6.31 BSP
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <linux/gpio/driver.h>
#include <linux/platform_data/gpio-ath79.h>
#include <linux/of_device.h>
#include <asm/prom.h>

#include <asm/mach-ath79/ar71xx_regs.h>
#include <asm/mach-ath79/ath79.h>

#define AP147_V2_ID			17
#define WMAC1_CALDATA_OFFSET		0x5000
#define BOARDID_OFFSET			0x20

void __iomem *ath79_gpio_base;
EXPORT_SYMBOL_GPL(ath79_gpio_base);

struct ath79_gpio_ctrl {
	struct gpio_chip chip;
	void __iomem *base;
	spinlock_t lock;
};

#define to_ath79_gpio_ctrl(c) container_of(c, struct ath79_gpio_ctrl, chip)

static void ath79_gpio_set_value(struct gpio_chip *chip,
				unsigned gpio, int value)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);

	if (value)
		__raw_writel(BIT(gpio), ctrl->base + AR71XX_GPIO_REG_SET);
	else
		__raw_writel(BIT(gpio), ctrl->base + AR71XX_GPIO_REG_CLEAR);
}

static int ath79_gpio_get_value(struct gpio_chip *chip, unsigned gpio)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);

	return (__raw_readl(ctrl->base + AR71XX_GPIO_REG_IN) >> gpio) & 1;
}

static int ath79_gpio_direction_input(struct gpio_chip *chip,
				       unsigned offset)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
	unsigned long flags;

	spin_lock_irqsave(&ctrl->lock, flags);

	__raw_writel(
		__raw_readl(ctrl->base + AR71XX_GPIO_REG_OE) & ~BIT(offset),
		ctrl->base + AR71XX_GPIO_REG_OE);

	spin_unlock_irqrestore(&ctrl->lock, flags);

	return 0;
}

static int ath79_gpio_direction_output(struct gpio_chip *chip,
					unsigned offset, int value)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
	unsigned long flags;

	spin_lock_irqsave(&ctrl->lock, flags);

	if (value)
		__raw_writel(BIT(offset), ctrl->base + AR71XX_GPIO_REG_SET);
	else
		__raw_writel(BIT(offset), ctrl->base + AR71XX_GPIO_REG_CLEAR);

	__raw_writel(
		__raw_readl(ctrl->base + AR71XX_GPIO_REG_OE) | BIT(offset),
		ctrl->base + AR71XX_GPIO_REG_OE);

	spin_unlock_irqrestore(&ctrl->lock, flags);

	return 0;
}

void ath79_gpio_input_select(struct gpio_chip *chip, unsigned gpio,
					u8 shift, u8 reg_off)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
	unsigned long flags;
	unsigned int reg;
	u32 t;

	WARN_ON(!soc_is_ar934x() && !soc_is_qca953x() && !soc_is_qca956x() &&
			!soc_is_qcn550x());

	if (gpio >= ctrl->chip.ngpio)
		return;

	reg = AR934X_GPIO_REG_IN_ENABLE0 + (4 * reg_off);

	spin_lock_irqsave(&ctrl->lock, flags);

	t = __raw_readl(ctrl->base + reg);
	t &= ~(0xff << shift);
	t |= gpio << shift;
	__raw_writel(t, (ctrl->base) + reg);

	/* flush write */
	(void) __raw_readl((ctrl->base) + reg);

	spin_unlock_irqrestore(&ctrl->lock, flags);
}

void ath79_gpio_output_select(struct gpio_chip *chip,
					unsigned gpio, u8 val)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
	unsigned long flags;
	unsigned int reg;
	u32 t, s;

	WARN_ON(!soc_is_ar934x() && !soc_is_qca953x() && !soc_is_qca956x() &&
			!soc_is_qcn550x());

	if (gpio >= ctrl->chip.ngpio)
		return;

	reg = AR934X_GPIO_REG_OUT_FUNC0 + 4 * (gpio / 4);
	s = 8 * (gpio % 4);

	spin_lock_irqsave(&ctrl->lock, flags);

	t = __raw_readl(ctrl->base + reg);
	t &= ~(0xff << s);
	t |= val << s;
	__raw_writel(t, ctrl->base + reg);

	/* flush write */
	(void) __raw_readl(ctrl->base + reg);

	spin_unlock_irqrestore(&ctrl->lock, flags);
}

int ath79_gpio_direction_select(struct gpio_chip *chip,
					unsigned gpio, bool oe)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
	unsigned long flags;
	bool oe_inverted = (soc_is_ar934x() || soc_is_qca953x());

	spin_lock_irqsave(&ctrl->lock, flags);

	if ((oe_inverted && oe) || (!oe_inverted && !oe))
		__raw_writel(
			__raw_readl(
				ctrl->base + AR71XX_GPIO_REG_OE) & ~(1 << gpio),
				ctrl->base + AR71XX_GPIO_REG_OE);
	else
		__raw_writel(
			__raw_readl(
				ctrl->base + AR71XX_GPIO_REG_OE) | (1 << gpio),
				ctrl->base + AR71XX_GPIO_REG_OE);

	spin_unlock_irqrestore(&ctrl->lock, flags);

	return 0;
}

static void __iomem *ath79_gpio_get_function_reg(struct gpio_chip *chip)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
	u32 reg = 0;

	if (soc_is_ar71xx() ||
	    soc_is_ar724x() ||
	    soc_is_ar913x() ||
	    soc_is_ar933x())
		reg = AR71XX_GPIO_REG_FUNC;
	else if (soc_is_ar934x() || soc_is_qca953x() || soc_is_qca956x() ||
			soc_is_qcn550x())
		reg = AR934X_GPIO_REG_FUNC;
	else
		WARN(1, "Unsupported SOC");

	return ctrl->base + reg;
}

void ath79_gpio_function_enable(struct gpio_chip *chip, u32 mask)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
	void __iomem *reg = ath79_gpio_get_function_reg(chip);
	unsigned long flags;

	spin_lock_irqsave(&ctrl->lock, flags);

	__raw_writel(__raw_readl(reg) | mask, reg);
	/* flush write */
	__raw_readl(reg);

	spin_unlock_irqrestore(&ctrl->lock, flags);
}

static int ar934x_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
	unsigned long flags;

	spin_lock_irqsave(&ctrl->lock, flags);

	__raw_writel(
		__raw_readl(ctrl->base + AR71XX_GPIO_REG_OE) | BIT(offset),
		ctrl->base + AR71XX_GPIO_REG_OE);

	spin_unlock_irqrestore(&ctrl->lock, flags);

	return 0;
}

static int ar934x_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
					int value)
{
	struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
	unsigned long flags;

	spin_lock_irqsave(&ctrl->lock, flags);

	if (value)
		__raw_writel(BIT(offset), ctrl->base + AR71XX_GPIO_REG_SET);
	else
		__raw_writel(BIT(offset), ctrl->base + AR71XX_GPIO_REG_CLEAR);

	__raw_writel(
		__raw_readl(ctrl->base + AR71XX_GPIO_REG_OE) & ~BIT(offset),
		ctrl->base + AR71XX_GPIO_REG_OE);

	spin_unlock_irqrestore(&ctrl->lock, flags);

	return 0;
}

static const struct gpio_chip ath79_gpio_chip = {
	.label			= "ath79",
	.get			= ath79_gpio_get_value,
	.set			= ath79_gpio_set_value,
	.direction_input	= ath79_gpio_direction_input,
	.direction_output	= ath79_gpio_direction_output,
	.base			= 0,
};

static const struct of_device_id ath79_gpio_of_match[] = {
	{ .compatible = "qca,ar7100-gpio" },
	{ .compatible = "qca,ar9340-gpio" },
	{},
};

static int ath79_gpio_probe(struct platform_device *pdev)
{
	struct ath79_gpio_platform_data *pdata = pdev->dev.platform_data;
	struct device_node *np = pdev->dev.of_node;
	struct ath79_gpio_ctrl *ctrl;
	struct resource *res;
	u32 ath79_gpio_count;
	bool oe_inverted;
	int err;
	const __be32 *paddr;
	int len, i2c_sda, i2c_sck;
	int i;
	u8 *art = KSEG1ADDR(0x1fff0000);

	ctrl = devm_kzalloc(&pdev->dev, sizeof(*ctrl), GFP_KERNEL);
	if (!ctrl)
		return -ENOMEM;

	if (np) {
		err = of_property_read_u32(np, "ngpios", &ath79_gpio_count);
		if (err) {
			dev_err(&pdev->dev, "ngpios property is not valid\n");
			return err;
		}
		if (ath79_gpio_count >= 32) {
			dev_err(&pdev->dev, "ngpios must be less than 32\n");
			return -EINVAL;
		}
		oe_inverted = of_device_is_compatible(np, "qca,ar9340-gpio");
	} else if (pdata) {
		ath79_gpio_count = pdata->ngpios;
		oe_inverted = pdata->oe_inverted;
	} else {
		dev_err(&pdev->dev, "No DT node or platform data found\n");
		return -EINVAL;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res)
		return -EINVAL;

	ctrl->base = devm_ioremap_nocache(
		&pdev->dev, res->start, resource_size(res));
	if (!ctrl->base)
		return -ENOMEM;

	spin_lock_init(&ctrl->lock);
	memcpy(&ctrl->chip, &ath79_gpio_chip, sizeof(ctrl->chip));
	ctrl->chip.dev = &pdev->dev;
	ctrl->chip.ngpio = ath79_gpio_count;
	if (oe_inverted) {
		ctrl->chip.direction_input = ar934x_gpio_direction_input;
		ctrl->chip.direction_output = ar934x_gpio_direction_output;
	}

	err = gpiochip_add(&ctrl->chip);
	if (err) {
		dev_err(&pdev->dev,
			"cannot add AR71xx GPIO chip, error=%d", err);
		return err;
	}

	if (strncmp(mips_get_machine_name(), "QCA AP147 Board", 15) == 0) {
		u8 board_id = *(art + WMAC1_CALDATA_OFFSET + BOARDID_OFFSET);

		pr_info("AP147 Reference Board Id is %d\n", board_id);
		if (board_id == AP147_V2_ID)
			ath79_gpio_function_enable(&ctrl->chip,
						AR934X_GPIO_FUNC_JTAG_DISABLE);
	}

	if (strncmp(mips_get_machine_name(), "QCA AP152 Board", 15) == 0) {
		of_property_read_u32(np, "i2c-sda", &i2c_sda);
		of_property_read_u32(np, "i2c-sck", &i2c_sck);
		ar934x_gpio_direction_output(&ctrl->chip, i2c_sda, 0);
		ar934x_gpio_direction_output(&ctrl->chip, i2c_sck, 0);
		ath79_gpio_input_select(&ctrl->chip, i2c_sda,
					QCA956X_GPIO_IN_MUX_I2C_SDA, 4);
		ath79_gpio_input_select(&ctrl->chip, i2c_sck,
					QCA956X_GPIO_IN_MUX_I2C_SCK, 4);
	}

	paddr = of_get_property(np, "val,gpio", &len);

	if (paddr && len >= (2 * sizeof(*paddr))) {
		len /= sizeof(*paddr);
		for (i = 0; i < len - 1; i += 2) {
			u32 gpio;
			u32 val;

			val = be32_to_cpup(paddr + i);
			gpio = be32_to_cpup(paddr + i + 1);
			ath79_gpio_output_select(&ctrl->chip, gpio, val);
		}
	}

	return 0;
}

static struct platform_driver ath79_gpio_driver = {
	.driver = {
		.name = "ath79-gpio",
		.of_match_table	= ath79_gpio_of_match,
	},
	.probe = ath79_gpio_probe,
};

module_platform_driver(ath79_gpio_driver);
