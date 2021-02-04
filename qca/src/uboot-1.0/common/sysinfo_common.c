/*
 * (C) Copyright 2000-2002
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

#include <common.h>
#include <command.h>
#include <sysinfo.h>
#include <linux/stddef.h>
#include <malloc.h>


#ifdef CONFIG_SHOW_BOOT_PROGRESS
# include <status_led.h>
# define SHOW_BOOT_PROGRESS(arg)	show_boot_progress(arg)
#else
# define SHOW_BOOT_PROGRESS(arg)
#endif

#ifdef CONFIG_AMIGAONEG3SE
	extern void enable_nvram(void);
	extern void disable_nvram(void);
#endif

extern sysinfo_t *sysinfo_ptr;

extern void sysinfo_relocate_spec (void);
extern uchar sysinfo_get_char_spec(int);

static uchar sysinfo_get_char_init (int index);
uchar (*sysinfo_get_char)(int) = sysinfo_get_char_init;

/************************************************************************
 * Default settings to be used when no valid environment is found
 */

const uchar default_sysinfo[] = {
    "serial_number=" "WISNEW-200600011" "\n"
    "default_password=" "Starlink-pass-111" "\n"
    "default_ssid=" "Starlink_00000000" "\n"
    "eth_mac_addr=" "94:10:3E:E9:7F:D5" "\n"
    "wps_device_pin=" "28680758" "\n"
};

//#if defined(CFG_ENV_IS_IN_NAND)		/* Environment is in Nand Flash */
int default_sysinfo_size = sizeof(default_sysinfo);
//#endif

void sysinfo_crc_update (void)
{
// not need sysinfo CRC --------------------------------
#if 0
	sysinfo_ptr->crc = crc32(0, sysinfo_ptr->data, sysinfo_SIZE);
#endif
// not need sysinfo CRC --------------------------------
}


static uchar sysinfo_get_char_init (int index)
{
	DECLARE_GLOBAL_DATA_PTR;

	uchar c;

	/* if crc was bad, use the default sysinfo */
	if (gd->sysinfo_addr)
	{
		c = sysinfo_get_char_spec(index);
	} else {
		c = default_sysinfo[index];
	}

	return (c);
}

uchar sysinfo_get_char_memory (int index)
{
	DECLARE_GLOBAL_DATA_PTR;

	if (gd->sysinfo_addr) {
		return ( *((uchar *)(gd->sysinfo_addr + index)) );
	} else {
		return ( default_sysinfo[index] );
	}
}

uchar *sysinfo_get_addr (int index)
{
	DECLARE_GLOBAL_DATA_PTR;

	if (gd->sysinfo_addr) {
		return ( ((uchar *)(gd->sysinfo_addr + index)) );
	} else {
		return (&default_sysinfo[index]);
	}
}

void sysinfo_relocate (void)
{
	DECLARE_GLOBAL_DATA_PTR;
	
	/*
	* We must allocate a buffer for the environment
	*/
	sysinfo_ptr = (sysinfo_t *)malloc (CONFIG_SYSINFO_SIZE);
	wnc_sysinfo_debug ("[sysinfo_relocate] %s[%d] malloced sysinfo at %p\n", __FUNCTION__,__LINE__,sysinfo_ptr);//WNC_Logic

	/*
	 * After relocation to RAM, we can always use the "memory" functions
	 */
	//wnc_sysinfo_debug("[sysinfo_relocate] After relocation to RAM, we can always use the \"memory\" functions\n"); //WNC_Logic
	sysinfo_get_char = sysinfo_get_char_memory;

	sysinfo_relocate_spec ();
	gd->sysinfo_addr = (ulong)&(sysinfo_ptr->data);
}



#ifdef CONFIG_AUTO_COMPLETE
int sysinfo_complete(char *var, int maxv, char *cmdv[], int bufsz, char *buf)
{
	int i, nxt, len, vallen, found;
	const char *lval, *rval;

	found = 0;
	cmdv[0] = NULL;

	len = strlen(var);

	/* now iterate over the variables and select those that match */
	for (i=0; sysinfo_get_char(i) != '\0'; i=nxt+1) {

		for (nxt=i; sysinfo_get_char(nxt) != '\n'; ++nxt)
			;

		lval = (char *)sysinfo_get_addr(i);
		rval = strchr(lval, '=');

		if (rval != NULL) {
			vallen = rval - lval;
			rval++;

		} else
			vallen = strlen(lval);

		if (len > 0 && (vallen < len || memcmp(lval, var, len) != 0))
			continue;

		if (found >= maxv - 2 || bufsz < vallen + 1) {
			cmdv[found++] = "...";
			break;
		}
		cmdv[found++] = buf;
		memcpy(buf, lval, vallen); buf += vallen; bufsz -= vallen;
		*buf++ = '\0'; bufsz--;
	}

	cmdv[found] = NULL;
	return found;
}
#endif


