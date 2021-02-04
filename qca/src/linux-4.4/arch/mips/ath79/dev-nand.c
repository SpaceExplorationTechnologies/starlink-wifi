/*
 *  Qualcomm Atheros AR71XX/AR724X/AR913X NAND controller device
 *
 *  Copyright (c) 2012 The Linux Foundation. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <linux/platform_device.h>
#include <asm/mach-ath79/ar71xx_regs.h>

static struct resource ath79_nand_resources[] = {
	{
		.start	= AR71XX_NAND_CTRL_BASE,
		.end	= AR71XX_NAND_CTRL_BASE + AR71XX_NAND_CTRL_SIZE - 1,
		.flags	= IORESOURCE_MEM,
	},
};

static struct platform_device ath79_nand_device = {
	.name		= "ath79-nand",
	.id		= -1,
	.resource	= ath79_nand_resources,
	.num_resources	= ARRAY_SIZE(ath79_nand_resources),
};

void __init ath79_register_nand(void)
{
	ath79_nand_device.dev.platform_data = NULL;
	platform_device_register(&ath79_nand_device);
}
