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

/*
 * This file contains the configuration parameters for the dbau1x00 board.
 */

#ifndef __AR7240_H
#define __AR7240_H

#define CONFIG_MIPS32		1  /* MIPS32 CPU core	*/

#define CONFIG_BOOTDELAY	4	/* autoboot after 4 seconds	*/

#define CONFIG_BAUDRATE		115200 
#define CFG_BAUDRATE_TABLE  { 	115200}

#define	CONFIG_TIMESTAMP		/* Print image info with timestamp */

#define CONFIG_ROOTFS_RD

#define	CONFIG_BOOTARGS_RD     "console=ttyS0,115200 root=01:00 rd_start=0x80600000 rd_size=5242880 init=/sbin/init mtdparts=ar7240-nor0:256k(u-boot),64k(u-boot-env),4096k(rootfs),2048k(uImage)"

/* XXX - putting rootfs in last partition results in jffs errors */
#define	CONFIG_BOOTARGS_FL     "console=ttyS0,115200 root=31:02 rootfstype=jffs2 init=/sbin/init mtdparts=ar7240-nor0:256k(u-boot),64k(u-boot-env),5120k(rootfs),2048k(uImage)"

#ifdef CONFIG_ROOTFS_FLASH
#define CONFIG_BOOTARGS CONFIG_BOOTARGS_FL
#else
#define CONFIG_BOOTARGS ""
#endif

/*
 * Miscellaneous configurable options
 */
#define	CFG_LONGHELP				/* undef to save memory      */
#define	CFG_PROMPT		"ar7240> "	/* Monitor Command Prompt    */
#define	CFG_CBSIZE		256		/* Console I/O Buffer Size   */
#define	CFG_PBSIZE (CFG_CBSIZE+sizeof(CFG_PROMPT)+16)  /* Print Buffer Size */
#define	CFG_MAXARGS		16		/* max number of command args*/

#define CFG_MALLOC_LEN		128*1024

#define CFG_BOOTPARAMS_LEN	128*1024

//#define CFG_SDRAM_BASE		0x80000000     /* Cached addr */
#define CFG_SDRAM_BASE		0xa0000000     /* Cached addr */

#define	CFG_LOAD_ADDR		0x81000000     /* default load address	*/
//#define	CFG_LOAD_ADDR		0xa1000000     /* default load address	*/

#define CFG_MEMTEST_START	0x80100000
#undef CFG_MEMTEST_START
#define CFG_MEMTEST_START       0x80200000
#define CFG_MEMTEST_END		0x83800000

/*------------------------------------------------------------------------
 * *  * JFFS2
 */
#define CFG_JFFS_CUSTOM_PART            /* board defined part   */
#define CONFIG_JFFS2_CMDLINE
#define MTDIDS_DEFAULT      "nor0=ar7240-nor0"

/* default mtd partition table */
#define MTDPARTS_DEFAULT    "mtdparts=ar7240-nor0:256k(u-boot),"\
                            "384k(experi-jffs2)"

#define CONFIG_MEMSIZE_IN_BYTES

#define CFG_RX_ETH_BUFFER   16

/*
** PLL Config for different CPU/DDR/AHB frequencies
*/

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
#define CFG_PLL_333_166_166		0x35
#define CFG_PLL_350_175_175		0x36
#define CFG_PLL_360_180_180		0x37
#define CFG_PLL_380_190_190		0x38
#define CFG_PLL_262_262_131		0x39
#define CFG_PLL_275_275_137		0x3a
#define CFG_PLL_200_200_200		0x3b
#define CFG_PLL_250_250_125		0x3c
#define CFG_PLL_225_225_112		0x3d
#define CFG_PLL_212_212_106		0x3e
#define CFG_PLL_187_187_93		0x3f
#define CFG_PLL_535_400_200		0x40
#define CFG_PLL_560_400_200		0x41
#define CFG_PLL_560_450_225		0x42
#define CFG_PLL_400_480_240		0x43
#define CFG_PLL_535_395_197		0x44
#define CFG_PLL_560_450_186		0x45
#define CFG_PLL_560_460_230		0x46
#define CFG_PLL_560_470_235		0x47
#define CFG_PLL_560_395_197		0x48
#define CFG_PLL_560_405_202		0x49
#define CFG_PLL_560_425_212		0x4a



/*-----------------------------------------------------------------------
 * Cache Configuration
 */
#define CFG_DCACHE_SIZE		32768
#define CFG_ICACHE_SIZE		65536
#define CFG_CACHELINE_SIZE	32

#endif	/* __CONFIG_H */
