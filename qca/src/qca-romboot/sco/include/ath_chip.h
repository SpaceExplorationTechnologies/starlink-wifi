/*
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef	_ATH_CHIP_H
#define	_ATH_CHIP_H

#define CFG_PLL_200_200_100		0x00
#define CFG_PLL_300_300_150		0x01
#define CFG_PLL_320_320_160		0x02
#define CFG_PLL_340_340_170		0x03
#define CFG_PLL_350_350_175		0x04
#define CFG_PLL_360_360_180		0x05
#define CFG_PLL_400_400_200		0x06
#define CFG_PLL_300_300_75		0x07
#define CFG_PLL_400_400_100		0x08
#define CFG_PLL_320_320_80		0x09
#define CFG_PLL_410_400_200		0x0a
#define CFG_PLL_420_400_200		0x0b
#define CFG_PLL_80_80_40		0x0c
#define CFG_PLL_64_64_32		0x0d
#define CFG_PLL_48_48_24		0x0e
#define CFG_PLL_32_32_16		0x0f
#define CFG_PLL_333_333_166		0x10
#define CFG_PLL_266_266_133		0x11
#define CFG_PLL_266_266_66		0x12
#define CFG_PLL_240_240_120		0x13
#define CFG_PLL_160_160_80		0x14
#define CFG_PLL_400_200_200		0x15
#define CFG_PLL_500_400_200		0x16
#define CFG_PLL_600_400_200		0x17
#define CFG_PLL_600_500_250		0x18
#define CFG_PLL_600_400_300		0x19
#define CFG_PLL_500_500_250		0x1a
#define CFG_PLL_600_350_175		0x1b
#define CFG_PLL_600_300_150		0x1c
#define CFG_PLL_600_550_1_1G_275	0x1d
#define CFG_PLL_600_500_1G_250		0x1e
#define CFG_PLL_533_400_200		0x1f
#define CFG_PLL_600_450_200		0x20
#define CFG_PLL_533_500_250		0x21
#define CFG_PLL_700_400_200		0x22
#define CFG_PLL_650_600_300		0x23
#define CFG_PLL_600_600_300		0x24
#define CFG_PLL_600_550_275		0x25
#define CFG_PLL_566_475_237		0x26
#define CFG_PLL_566_450_225		0x27
#define CFG_PLL_600_332_166		0x28
#define CFG_PLL_600_575_287		0x29
#define CFG_PLL_600_525_262		0x2a
#define CFG_PLL_566_550_275		0x2b
#define CFG_PLL_566_525_262		0x2c
#define CFG_PLL_600_332_200		0x2d
#define CFG_PLL_600_266_133		0x2e
#define CFG_PLL_600_266_200		0x2f
#define CFG_PLL_600_650_325		0x30
#define CFG_PLL_566_400_200		0x31
#define CFG_PLL_566_500_250		0x32
#define CFG_PLL_600_1_2G_400_200	0x33
#define CFG_PLL_560_480_240		0x34
#define CFG_PLL_720_600_200		0x35
#define CFG_PLL_720_680_240		0x36
#define CFG_PLL_720_600_240		0x37

#define ATH_MEM_SDRAM           1
#define ATH_MEM_DDR1            2
#define ATH_MEM_DDR2            3

#ifdef CONFIG_MACH_QCA955x
#include <955x.h>
#elif defined(CONFIG_MACH_AR934x)
#include <ar934x_soc.h>
#else
#error "Building 1st f/w for unknown chip"
#endif

#endif	/* _ATH_CHIP_H */
