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
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <asm/mach-ath79/ar71xx_regs.h>
#include <asm/mach-ath79/ath79.h>
#include "common.h"

void __iomem *ath79_gpio_base;
EXPORT_SYMBOL_GPL(ath79_gpio_base);

static void __iomem *ath79_gpio_get_function_reg(void)
{
	u32 reg = 0;

	if (soc_is_ar71xx() ||
	    soc_is_ar724x() ||
	    soc_is_ar913x() ||
	    soc_is_ar933x())
		reg = AR71XX_GPIO_REG_FUNC;
	else if (soc_is_ar934x() ||
		 soc_is_qca953x() ||
		 soc_is_qca956x() ||
		 soc_is_qcn550x() ||
		 soc_is_tp9343())
		reg = AR934X_GPIO_REG_FUNC;
	else
		BUG();

	return ath79_gpio_base + reg;
}

static void __iomem *ath79_gpio_get_function2_reg(void)
{
	u32 reg = 0;

	if (soc_is_ar71xx() ||
	    soc_is_ar724x() ||
	    soc_is_ar913x() ||
	    soc_is_ar933x())
		reg = AR71XX_GPIO_REG_FUNC_2;
	else
		BUG();

	return ath79_gpio_base + reg;
}


void ath79_gpio_function2_setup(u32 set, u32 clear)
{
	void __iomem *reg = ath79_gpio_get_function2_reg();

	__raw_writel((__raw_readl(reg) & ~clear) | set, reg);
	/* flush write */
	__raw_readl(reg);
}

void ath79_gpio_function_setup(u32 set, u32 clear)
{
	void __iomem *reg = ath79_gpio_get_function_reg();

	__raw_writel((__raw_readl(reg) & ~clear) | set, reg);
	/* flush write */
	__raw_readl(reg);
}

void ath79_gpio_function_enable(u32 mask)
{
	ath79_gpio_function_setup(mask, 0);
}

void ath79_gpio_function_disable(u32 mask)
{
	ath79_gpio_function_setup(0, mask);
}

void __init ath79_gpio_output_select(unsigned gpio, u8 val)
{
	void __iomem *base = ath79_gpio_base;
	unsigned int reg, reg_base;
	u32 t, s;

	if (soc_is_ar934x())
		reg_base = AR934X_GPIO_REG_OUT_FUNC0;
	else if (soc_is_qca953x())
		reg_base = QCA953X_GPIO_REG_OUT_FUNC0;
	else if (soc_is_qca955x())
		reg_base = QCA955X_GPIO_REG_OUT_FUNC0;
	else if (soc_is_qca956x())
		reg_base = QCA956X_GPIO_REG_OUT_FUNC0;
	else if (soc_is_qcn550x())
		reg_base = QCN550X_GPIO_REG_OUT_FUNC0;
	else
		BUG();

	reg = reg_base + 4 * (gpio / 4);
	s = 8 * (gpio % 4);

	t = __raw_readl(base + reg);
	t &= ~(0xff << s);
	t |= val << s;
	__raw_writel(t, base + reg);

	/* flush write */
	(void) __raw_readl(base + reg);
}

int ath79_gpio_direction_select(unsigned gpio, bool oe)
{
	void __iomem *base = ath79_gpio_base;
	bool ieq_1 = (soc_is_ar934x() ||
			soc_is_qca953x());

	if ((ieq_1 && oe) || (!ieq_1 && !oe))
		__raw_writel(__raw_readl(base + AR71XX_GPIO_REG_OE) & ~(1 << gpio),
				base + AR71XX_GPIO_REG_OE);
	else
		__raw_writel(__raw_readl(base + AR71XX_GPIO_REG_OE) | (1 << gpio),
				base + AR71XX_GPIO_REG_OE);

	return 0;
}
