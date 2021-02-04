/*
 * (C) Copyright 2004
 * Jian Zhang, Texas Instruments, jzhang@ti.com.

 * (C) Copyright 2000-2004
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * (C) Copyright 2001 Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Andreas Heppel <aheppel@sysgo.de>

 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/* #define DEBUG */

#include <common.h>

#if defined(CONFIG_SYSINFO_IS_IN_SF) /* Environment is in Nand Flash */

#include <command.h>
#include <sysinfo.h>
#include <linux/stddef.h>
#include <malloc.h>
//#include <nand.h>
#include <spi_flash.h>

#if ((CONFIG_COMMANDS&(CFG_CMD_ENV|CFG_CMD_NAND)) == (CFG_CMD_ENV|CFG_CMD_NAND))
#define CMD_SAVESYSINFO
#elif defined(CONFIG_SYSINFO_OFFSET_REDUND)
#error Cannot use CONFIG_SYSINFO_OFFSET_REDUND without CFG_CMD_ENV & CFG_CMD_NAND
#endif

#if defined(CONFIG_SYSINFO_SIZE_REDUND) && (CONFIG_SYSINFO_SIZE_REDUND != CONFIG_SYSINFO_SIZE)
#error CONFIG_SYSINFO_SIZE_REDUND should be the same as CONFIG_SYSINFO_SIZE
#endif

#ifdef CONFIG_INFERNO
#error CONFIG_INFERNO not supported yet
#endif

//int nand_legacy_rw (struct nand_chip* nand, int cmd,
//	    size_t start, size_t len,
//	    size_t * retlen, u_char * buf);

/* references to names in env_common.c */
extern uchar default_sysinfo[];
extern int default_sysinfo_size;

char * sysinfo_name_spec = "SF";


//WNC0_Andrew
#ifdef ENV_IS_EMBEDDED
extern uchar sysinfo_environment[];
sysinfo_t *sysinfo_ptr = (sysinfo_t *)(&sysinfo_environment[0]);
#else /* ! ENV_IS_EMBEDDED */
sysinfo_t *sysinfo_ptr = 0;
#endif /* ENV_IS_EMBEDDED */
//WNC0


/* local functions */
static void use_sysinfo_default(char *str);

DECLARE_GLOBAL_DATA_PTR;

uchar sysinfo_get_char_spec (int index)
{
	return ( *((uchar *)(gd->sysinfo_addr + index)) );
}


/* this is called before nand_init()
 * so we can't read Nand to validate env data.
 * Mark it OK for now. env_relocate() in env_common.c
 * will call our relocate function which will does
 * the real validation.
 */
int sysinfo_init(void)
{
	gd->sysinfo_addr  = (ulong)&default_sysinfo[0];
	gd->sysinfo_valid = 1;

	return (0);
}

//WNC0_Andrew
static struct spi_flash *flash;

#ifndef CONFIG_SF_DEFAULT_SPEED
#define CONFIG_SF_DEFAULT_SPEED	1000000
#endif
#ifndef CONFIG_SF_DEFAULT_MODE
#define CONFIG_SF_DEFAULT_MODE		SPI_MODE_3
#endif
#ifndef CONFIG_SF_DEFAULT_CS
#define CONFIG_SF_DEFAULT_CS		0
#endif
#ifndef CONFIG_SF_DEFAULT_BUS
#define CONFIG_SF_DEFAULT_BUS		0
#endif

static int mfg_spi_flash_probe(void)
{
	unsigned int bus = CONFIG_SF_DEFAULT_BUS;
	unsigned int cs = CONFIG_SF_DEFAULT_CS;
	unsigned int speed = CONFIG_SF_DEFAULT_SPEED;
	unsigned int mode = CONFIG_SF_DEFAULT_MODE;
	char *endp;
	struct spi_flash *new;

	new = spi_flash_probe(bus, cs, speed, mode);
	if (!new) {
		printf("Failed to initialize SPI flash at %u:%u\n", bus, cs);
		return 1;
	}

	if (flash)
		spi_flash_free(flash);
	flash = new;

	return 0;
}
//WNC0

#ifdef CMD_SAVESYSINFO
int savesysinfo(void)
{
	int ret = 0;

	puts ("Erasing SYSINFO Nand...");

	wnc_sysinfo_debug("\n[savesysinfo] CONFIG_SYSINFO_OFFSET == %08lx\n", CONFIG_SYSINFO_OFFSET); //WNC_Logic
	wnc_sysinfo_debug("[savesysinfo] CONFIG_SYSINFO_SIZE   == %08lx\n", CONFIG_SYSINFO_SIZE); //WNC_Logic

	if ( mfg_spi_flash_probe() == 1 )
		return 1;

	if ( spi_flash_erase(flash, CONFIG_SYSINFO_OFFSET, CONFIG_SYSINFO_SIZE))
		return 1;

	puts ("Writing to SYSINFO Nor... ");
	ret = spi_flash_write(flash, CONFIG_SYSINFO_OFFSET, CONFIG_SYSINFO_SIZE, (u_char*)sysinfo_ptr);
	if (ret)
		return 1;

	puts ("done\n");
	return ret;
}
#endif /* CMD_SAVESYSINFO */

/*
 * The legacy NAND code saved the environment in the first NAND device i.e.,
 * nand_dev_desc + 0. This is also the behaviour using the new NAND code.
 */
void sysinfo_relocate_spec (void)
{
#if !defined(ENV_IS_EMBEDDED)
	int ret;

	if ( mfg_spi_flash_probe() == 1 )
		return 1;

	ret = spi_flash_read(flash, CONFIG_SYSINFO_OFFSET, CONFIG_SYSINFO_SIZE, (u_char*)sysinfo_ptr);

	wnc_sysinfo_debug("[sysinfo_relocate_spec] ret: %d , total: %d , CONFIG_SYSINFO_SIZE: %d\n", ret, CONFIG_SYSINFO_SIZE, CONFIG_SYSINFO_SIZE); //WNC_Logic

  	if (ret){
		return use_sysinfo_default("*** Warning - bad SIZE, using default SYSINFO\n\n");
  	}

// not need SYSINFO CRC --------------------------------
#if 0
	if (crc32(0, sysinfo_ptr->data, SYSINFO_SIZE) != sysinfo_ptr->crc){
		return use_sysinfo_default("*** Warning - bad CRC or NAND, using default SYSINFO\n\n");
	}
#endif
// not need SYSINFO CRC --------------------------------

	if(sysinfo_ptr->data[0] == 0xFF && sysinfo_ptr->data[1] == 0xFF){
		use_sysinfo_default("First booting, write default data (sysinfo) to flash...\n");
		savesysinfo();
	}


#endif /* ! ENV_IS_EMBEDDED */
}

static void use_sysinfo_default(char *str)
{
	puts (str);

	if (default_sysinfo_size > CONFIG_SYSINFO_SIZE){
		puts ("*** Error - default SYSINFO is too large\n\n");
		return;
	}

	memset (sysinfo_ptr, 0, sizeof(sysinfo_t));
	memcpy (sysinfo_ptr->data,
			default_sysinfo,
			default_sysinfo_size);

// not need SYSINFO CRC --------------------------------
#if 0
	sysinfo_ptr->crc = crc32(0, sysinfo_ptr->data, SYSINFO_SIZE);
#endif
// not need SYSINFO CRC --------------------------------

	gd->sysinfo_valid = 1;

}

#endif /* CFG_ENV_IS_IN_NAND */

