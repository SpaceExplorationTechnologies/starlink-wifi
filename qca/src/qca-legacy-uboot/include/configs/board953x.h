/*
 * Copyright (c) 2014 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef __BOARD_955X_H
#define __BOARD_955X_H

#include <config.h>

#undef MTDPARTS_DEFAULT

#undef CFG_HZ

#include <atheros.h>

#ifndef FLASH_SIZE
#define FLASH_SIZE 8
#endif

#if (FLASH_SIZE > 16)
#define ATH_DUAL_NOR		1
#endif

#define CONFIG_SYS_VSNPRINTF
/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CFG_MAX_FLASH_BANKS	1	/* max number of memory banks */
#if (FLASH_SIZE == 32)
#define CFG_MAX_FLASH_SECT	512	/* max number of sectors on one chip */
#define ATH_MTDPARTS_MIB0	"64k(mib0)"
#define ATH_ROOTFS_SIZE		"14528k(rootfs)"
#elif (FLASH_SIZE == 16)
#define CFG_MAX_FLASH_SECT	256	/* max number of sectors on one chip */
#define ATH_MTDPARTS_MIB0	"64k(mib0)"
#define ATH_ROOTFS_SIZE		"14528k(rootfs)"
#elif (FLASH_SIZE == 8)
#define CFG_MAX_FLASH_SECT	128	/* max number of sectors on one chip */
#define ATH_MTDPARTS_MIB0	"64k(mib0)"
#define ATH_ROOTFS_SIZE		"6336k(rootfs)"
#elif (FLASH_SIZE == 1/2)
#define CFG_MAX_FLASH_SECT	8	/* max number of sectors on one chip */
#else
#define CFG_MAX_FLASH_SECT	64	/* max number of sectors on one chip */
#define ATH_MTDPARTS_MIB0	"64k(mib0)"
#define ATH_ROOTFS_SIZE		"6336k(rootfs)"
#endif

#define CFG_FLASH_SECTOR_SIZE	(64*1024)
#if (FLASH_SIZE == 32)
#define CFG_FLASH_SIZE		0x02000000	/* Total flash size */
#elif (FLASH_SIZE == 16)
#define CFG_FLASH_SIZE		0x01000000	/* Total flash size */
#elif (FLASH_SIZE == 8)
#define CFG_FLASH_SIZE		0x00800000	/* max number of sectors on one chip */
#elif (FLASH_SIZE == 1/2)
#define CFG_FLASH_SIZE		0x00080000	/* Total flash size */
#else
#define CFG_FLASH_SIZE		0x00400000	/* Total flash size */
#endif

#ifndef COMPRESSED_UBOOT
#define ENABLE_DYNAMIC_CONF	1
#endif

#undef CFG_ATHRS26_PHY

#if (CFG_MAX_FLASH_SECT * CFG_FLASH_SECTOR_SIZE) != CFG_FLASH_SIZE
#	error "Invalid flash configuration"
#endif

#define CFG_FLASH_WORD_SIZE	unsigned short

#if defined(CONFIG_ATH_NAND_BR) && defined(COMPRESSED_UBOOT)
#define CFG_FLASH_BASE			0xa0100000
#else
/* NOR Flash start address */
#define CFG_FLASH_BASE			0x9f000000
#endif

#ifdef COMPRESSED_UBOOT
#define BOOTSTRAP_TEXT_BASE		CFG_FLASH_BASE
#define BOOTSTRAP_CFG_MONITOR_BASE	BOOTSTRAP_TEXT_BASE
#endif

#define CONFIG_PCI_CONFIG_DATA_IN_OTP

/*
 * Defines to change flash size on reboot
 */
#ifdef ENABLE_DYNAMIC_CONF
#define UBOOT_FLASH_SIZE		(256 * 1024)
#define UBOOT_ENV_SEC_START		(CFG_FLASH_BASE + UBOOT_FLASH_SIZE)

#define CFG_FLASH_MAGIC			0xaabacada
#define CFG_FLASH_MAGIC_F		(UBOOT_ENV_SEC_START + CFG_FLASH_SECTOR_SIZE - 0x20)
#define CFG_FLASH_SECTOR_SIZE_F		*(volatile int *)(CFG_FLASH_MAGIC_F + 0x4)
#define CFG_FLASH_SIZE_F		*(volatile int *)(CFG_FLASH_MAGIC_F + 0x8) /* Total flash size */
#define CFG_MAX_FLASH_SECT_F		(CFG_FLASH_SIZE / CFG_FLASH_SECTOR_SIZE) /* max number of sectors on one chip */
#else
#define CFG_FLASH_SIZE_F		CFG_FLASH_SIZE
#define CFG_FLASH_SECTOR_SIZE_F		CFG_FLASH_SECTOR_SIZE
#endif


#define CFG_DDR_REFRESH_VAL		0x4138

/*
 * The following #defines are needed to get flash environment right
 */
#define	CFG_MONITOR_BASE	TEXT_BASE
#define	CFG_MONITOR_LEN		(192 << 10)

#undef CONFIG_BOOTARGS

#define __gen_cmd(n, a, f, ec, cc, el)		\
	#n "=tftp 0x80060000 ${dir}" #f "&&"	\
	#ec " " #a " " #el "&&"			\
	#cc " $fileaddr " #a " $filesize\0"

#if (FLASH_SIZE == 32)
#define __gen_cmd2(n, a1, a2, f, ec, cc, el)	\
	#n "=tftp 0x80060000 ${dir}" #f "&&"	\
	#ec " " #a1 " " #el "&&"		\
	#cc " $fileaddr " #a1 " $filesize &&"	\
	#ec " " #a2 " " #el "&&"		\
	#cc " $fileaddr " #a2 " $filesize\0"
#define gen_cmd2(n, a1, a2, f)			\
	__gen_cmd2(n, a1, a2, f, erase, cp.b, +$filesize)
#endif

#define gen_cmd(n, a, f)			\
	__gen_cmd(n, a, f, erase, cp.b, +$filesize)

#define gen_cmd_el(n, a, f, el)			\
	__gen_cmd(n, a, f, erase, cp.b, +el)

#define nand_gen_cmd(n, a, f, s)		\
	__gen_cmd(n, a, f, nand erase, nand write, s)

#define __fs_name(x, y)		x ## y
#define _fs_name(x, y)		__fs_name(x, y)
#define fs_name(y)		_fs_name(__CONFIG_BOARD_NAME, y)

#ifdef COMPRESSED_UBOOT
#	define ATH_U_FILE	tuboot.bin
#else
#	define ATH_U_FILE	u-boot.bin
#endif

#define ATH_UBI_ARGS	" "

#ifdef CONFIG_ATH_NAND_SUPPORT
#	ifdef CONFIG_ATH_NAND_BR	// nand boot rom
#		if defined(COMPRESSED_UBOOT)
#			define ATH_U_CMD	nand_gen_cmd(lu, 0x0, 2fw.bin, 0x20000)
#			define MTDPARTS_DEFAULT	"mtdparts=ath-nand:128k(u-boot),384k(free),1280k(uImage),7m(rootfs),128k(dummy),128k(caldata)"
#		else
#		define ATH_U_CMD	nand_gen_cmd(lu, 0x0, 2fw.bin, 0x40000)
#		define MTDPARTS_DEFAULT "mtdparts=ath-nand:256k(u-boot),256k(u-boot-env),1280k(uImage),7m(rootfs),128k(dummy),128k(caldata)"
#		endif
#		define ATH_ROOT_DEV	"31:03"
#		define CFG_ENV_ADDR	0x00040000
#		define ATH_F_LEN	0x700000
#		define ATH_F_ADDR	0x1c0000
#		define ATH_K_ADDR	0x80000
#		define ATH_K_LEN	0x140000
#	else //dual flash
#		ifdef ATH_SPI_NAND
#			if CONFIG_ATH_DUAL_IMAGE_SUPPORT
#                               define MTDPARTS_DEFAULT "mtdparts=spi0.0:256k(u-boot)ro,64k(u-boot-env),128k(reserved),64k(art);spi0.1:2m(kernel),20m(rootfs),2m(k-2),20m(r-2),84m(user),22m@0x0(firmware),22m@0x1600000(fw-2)"
#				define ATH_UBI_ARGS	" ubi.mtd=5,2048 root=/dev/mtdblock11 "
#                       else
#				define MTDPARTS_DEFAULT "mtdparts=spi0.0:256k(u-boot)ro,64k(u-boot-env),128k(reserved),64k(art);spi0.1:2m(kernel),20m(rootfs),106m(data),22m@0x0(firmware)"
#				define ATH_UBI_ARGS	" ubi.mtd=5,2048 root=/dev/mtdblock8 "
#			endif
#			define ATH_F_LEN        0x1400000
#			define ATH_F_ADDR       0x200000
#			define ATH_K_ADDR       0x0
#			define ATH_K_LEN        0x200000
#			define CFG_ENV_ADDR	0x9f040000
#		else
#			error "Invalid NAND flash configuration"
#		endif
#	endif
#	define ATH_F_FILE		fs_name(${bc}-nand-jffs2)
#	define ATH_K_FILE		vmlinux${bc}.lzma.uImage
#	define ATH_F_CMD		nand_gen_cmd(lf, ATH_F_ADDR, ATH_F_FILE, ATH_F_LEN)
#	define ATH_K_CMD		nand_gen_cmd(lk, ATH_K_ADDR, ATH_K_FILE, ATH_K_LEN)
#	define ATH_EXTRA_ENV		"bootdevice=0\0"
#else
#	if defined(COMPRESSED_UBOOT)
#		define ATH_U_FILE	tuboot.bin
#		define ATH_F_FILE	fs_name(${bc}-jffs2)
#		define ATH_F_LEN	$filesize
#		define ATH_F_ADDR	0x9f010000
#		define ATH_K_FILE	vmlinux${bc}.lzma.uImage
#		define ATH_K_ADDR	0x9f300000
		/*
		 * For compressed uboot, environment sector is not used.
		 * Hence the mtd partition indices get reduced by 1.
		 * This conflicts with
		 *	- minor no. for /dev/caldata in
		 *		build/scripts/{board}/dev.txt
		 *	- root=<rooot dev> kernel cmdline parameter
		 * Hence, doing a dummy split of the u-boot partition
		 * to maintain the same minor no. as in the normal u-boot.
		 */
#		define MTDPARTS_DEFAULT	"mtdparts=ath-nor0:32k(u-boot1),32k(u-boot2),3008k(rootfs),896k(uImage),64k(mib0),64k(ART)"
#	else
#		define ATH_F_FILE		fs_name(${bc}-jffs2)
#	if (FLASH_SIZE == 16 || FLASH_SIZE == 32)
#		define ATH_F_LEN		0xE30000
#		define ATH_K_ADDR		0x9fE80000
#	else
#		define ATH_F_LEN		0x630000
#		define ATH_K_ADDR		0x9f680000
# 	endif
#		define ATH_F_ADDR		0x9f050000
#		define ATH_K_FILE		vmlinux${bc}.lzma.uImage

#		if CONFIG_ATH_DUAL_IMAGE_SUPPORT
#			if (FLASH_SIZE == 32)
#				define MTDPARTS_DEFAULT	"mtdparts=spi0.0:256k(u-boot)ro,64k(u-boot-env)," ATH_ROOTFS_SIZE ",1472k(kernel),64k(art),256k(reserved),14528k(r-2),1472k(k-2),128k(reserved2),16000k@0x50000(firmware),16000k@0x1040000(fw-2)"
#			else
#				if defined(CONFIG_ATH_SPI_CS1_GPIO)
#					define MTDPARTS_DEFAULT	"mtdparts=spi0.0:256k(u-boot)ro,64k(u-boot-env)," ATH_ROOTFS_SIZE ",1472k(kernel),64k(art),16000k@0x50000(firmware);spi0.1:14528k(r-2),1472k(k-2),384k(reserved),16000k@0x0(fw-2)"
#				else /* FLASH_SIZE == 16 */
#					define ATH_F_LEN		0x660000
#					define ATH_K_ADDR		0x9f6B0000
#					define MTDPARTS_DEFAULT	"mtdparts=spi0.0:256k(u-boot),64k(u-boot-env),6528k(rootfs),1472k(kernel),6528k(r-2),1472k(k-2),64k(art),8000k@0x50000(firmware),8000k@0x820000(fw-2)"
#				endif
#			endif
#		else
#			if (FLASH_SIZE == 32)
#				define MTDPARTS_DEFAULT	"mtdparts=ath-nor0:256k(u-boot),64k(u-boot-env)," ATH_ROOTFS_SIZE ",1472k(uImage)," "64k(ART),256k(reserved),16128k(usr)"
#			else
#				define MTDPARTS_DEFAULT	"mtdparts=ath-nor0:256k(u-boot),64k(u-boot-env)," ATH_ROOTFS_SIZE ",1408k(uImage)," ATH_MTDPARTS_MIB0 ",64k(ART)"
#			endif
#		endif
#	endif
#endif /*CONFIG_MI124*/

#ifndef ATH_ROOT_DEV
#	define ATH_ROOT_DEV	"31:02"
#endif

#ifndef ATH_EXTRA_ENV
#	define ATH_EXTRA_ENV
#endif

#ifndef ATH_U_CMD
#	if (FLASH_SIZE == 32)
#		define ATH_U_CMD	gen_cmd2(lu, 0x9f000000, 0xa0000000, ATH_U_FILE)
#	else
#		define ATH_U_CMD	gen_cmd(lu, 0x9f000000, ATH_U_FILE)
#	endif
#endif

#ifndef ATH_F_CMD
#	define ATH_F_CMD	gen_cmd_el(lf, ATH_F_ADDR, ATH_F_FILE, ATH_F_LEN)
#endif

#ifndef ATH_K_CMD
#	define ATH_K_CMD	gen_cmd(lk, ATH_K_ADDR, ATH_K_FILE)
#endif

#define CONFIG_EXTRA_ENV_SETTINGS	\
	"dir=\0" ATH_U_CMD ATH_F_CMD ATH_K_CMD ""

#ifdef BOARD_NAME
	#define CONFIG_BOOTARGS "board=" BOARD_NAME " console=ttyS0,115200 " ATH_UBI_ARGS MTDPARTS_DEFAULT " rootfstype=squashfs,jffs2 noinitrd"
#else
	#define	CONFIG_BOOTARGS	"console=ttyS0,115200 root=" ATH_ROOT_DEV " rootfstype=jffs2 init=/sbin/init " MTDPARTS_DEFAULT
#endif
//#define CFG_PLL_FREQ    CFG_PLL_720_600_200

/*
 * timeout values are in ticks
 */
#define CFG_FLASH_ERASE_TOUT	(2 * CFG_HZ) /* Timeout for Flash Erase */
#define CFG_FLASH_WRITE_TOUT	(2 * CFG_HZ) /* Timeout for Flash Write */

/*
 * Cache lock for stack
 */
#define CFG_INIT_SP_OFFSET	0x1000
#define CFG_INIT_SRAM_SP_OFFSET	0xbd001800

#ifdef CONFIG_ATH_NAND_SUPPORT
#ifdef ATH_SPI_NAND
#	define CONFIG_BOOTCOMMAND       "nboot 0x81000000 0 0"
#else
#	define CONFIG_BOOTCOMMAND	"nboot 0x81000000 0 0x80000"
#endif
#else
#	define CFG_ENV_ADDR		0x9f040000
#	ifdef COMPRESSED_UBOOT
#		define CONFIG_BOOTCOMMAND	"bootm 0x9f300000"
#	else
#		if (FLASH_SIZE == 16 || FLASH_SIZE == 32)
#			define CONFIG_BOOTCOMMAND	"bootm 0x9fE80000"
#		else
#			define CONFIG_BOOTCOMMAND	"bootm 0x9f680000"
#		endif
#	endif
#endif



#ifdef ENABLE_DYNAMIC_CONF
#define CFG_DDR_MAGIC		0xaabacada
#define CFG_DDR_MAGIC_F		(UBOOT_ENV_SEC_START + CFG_FLASH_SECTOR_SIZE - 0x30)
#define CFG_DDR_CONFIG_VAL_F	*(volatile int *)(CFG_DDR_MAGIC_F + 4)
#define CFG_DDR_CONFIG2_VAL_F	*(volatile int *)(CFG_DDR_MAGIC_F + 8)
#define CFG_DDR_EXT_MODE_VAL_F	*(volatile int *)(CFG_DDR_MAGIC_F + 12)
#endif

#define CONFIG_NET_MULTI
#define CONFIG_MEMSIZE_IN_BYTES
#define CONFIG_PCI 1

/*-----------------------------------------------------------------------
 * Cache Configuration
 */
#ifndef COMPRESSED_UBOOT
#define ATH_CFG_COMMANDS	((			\
				CONFIG_CMD_DFL	|	\
				CFG_CMD_DHCP	|	\
				CFG_CMD_ELF	|	\
				CFG_CMD_PCI	|	\
				CFG_CMD_FLS	|	\
				CFG_CMD_MII	|	\
				CFG_CMD_PING	|	\
				CFG_CMD_NET	|	\
				CFG_CMD_ENV	|	\
				CFG_CMD_PLL	|	\
				CFG_CMD_FLASH	|	\
				CFG_CMD_RUN	|	\
				CFG_CMD_ELF	|	\
				CFG_CMD_DDR	|	\
				CFG_CMD_ETHREG		\
				) & ~(			\
				CFG_CMD_IMLS	|	\
				CFG_CMD_FLASH		\
				))
#else
#	ifdef CONFIG_ATH_NAND_BR
#		define ATH_CFG_COMMANDS		((			\
						CONFIG_CMD_DFL	|	\
						CFG_CMD_PING	|	\
						CFG_CMD_NET) & ~(	\
						CFG_CMD_FLASH		\
						))
#	else
#		define ATH_CFG_COMMANDS		(CONFIG_CMD_DFL	|	\
				CFG_CMD_PING	|	\
				CFG_CMD_NET)
#	endif
#endif /* #ifndef COMPRESSED_UBOOT */

#ifdef CONFIG_ATH_NAND_SUPPORT
#	ifdef CONFIG_ATH_NAND_BR
#		define CFG_ENV_IS_IN_NAND	1
#		define CFG_ENV_OFFSET		0x40000u
#		define CFG_ENV_SIZE		0x40000u
#		define ATH_EXTRA_CMD		CFG_CMD_NAND
#	else
#		define CFG_ENV_IS_IN_FLASH	1
#		define CFG_ENV_SIZE		CFG_FLASH_SECTOR_SIZE
#		define ATH_EXTRA_CMD		(CFG_CMD_NAND | CFG_CMD_FLASH)
#	endif
#	define NAND_MAX_CHIPS			1
#	define CFG_MAX_NAND_DEVICE		1
#else
#	define ATH_EXTRA_CMD			CFG_CMD_FLASH
#	define CFG_ENV_IS_IN_FLASH		1
#	define CFG_ENV_SIZE			CFG_FLASH_SECTOR_SIZE
#endif

#define DEBUG

#ifdef COMPRESSED_UBOOT
#undef  CFG_ENV_IS_IN_FLASH
#undef  CFG_ENV_IS_IN_NAND
#define CFG_ENV_IS_NOWHERE		1
#endif

#define CONFIG_COMMANDS			(ATH_CFG_COMMANDS | ATH_EXTRA_CMD)

#define CONFIG_IPADDR			192.168.1.1
#define CONFIG_SERVERIP			192.168.1.10
#define CONFIG_ETHADDR			0x00:0xaa:0xbb:0xcc:0xdd:0xee
#define CFG_FAULT_ECHO_LINK_DOWN	1

#define CFG_PHY_ADDR			0
#define CFG_GMII			0
#define CFG_MII0_RMII			1
#define CFG_AG7100_GE0_RMII		1

#define CFG_BOOTM_LEN			(16 << 20) /* 16 MB */
#define CFG_HUSH_PARSER
#define CFG_PROMPT_HUSH_PS2		"hush>"

/*
** Parameters defining the location of the calibration/initialization
** information for the two Merlin devices.
** NOTE: **This will change with different flash configurations**
*/

#define BOARDCAL			(CFG_FLASH_BASE + CFG_FLASH_SIZE - 0x10000)
#define WLANCAL				(BOARDCAL + 0x1000)
#define ATHEROS_PRODUCT_ID		137
#define CAL_SECTOR			(CFG_MAX_FLASH_SECT - 1)

/* For Merlin, both PCI, PCI-E interfaces are valid */
#define ATH_ART_PCICFG_OFFSET		12

#include <cmd_confdefs.h>

#endif	/* __BOARD_955X_H */
