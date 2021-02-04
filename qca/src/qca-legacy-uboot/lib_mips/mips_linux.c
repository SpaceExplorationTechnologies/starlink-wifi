/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <common.h>
#include <command.h>
#include <image.h>
#include <zlib.h>
#include <asm/byteorder.h>
#include <asm/addrspace.h>

#ifdef CONFIG_AR7240
#include <ar7240_soc.h>
#endif
DECLARE_GLOBAL_DATA_PTR;

#define	LINUX_MAX_ENVS		256
#define	LINUX_MAX_ARGS		256

#ifdef CONFIG_SHOW_BOOT_PROGRESS
# include <status_led.h>
# define SHOW_BOOT_PROGRESS(arg)	show_boot_progress(arg)
#else
# define SHOW_BOOT_PROGRESS(arg)
#endif

extern image_header_t header;           /* from cmd_bootm.c */

extern int do_reset (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[]);

static int	linux_argc;
static char **	linux_argv;

static char **	linux_env;
static char *	linux_env_p;
static int	linux_env_idx;

static void linux_params_init (ulong start, char * commandline);
static void linux_env_set (char * env_name, char * env_val);

#ifdef CONFIG_WASP_SUPPORT
void wasp_set_cca(void)
{
	/* set cache coherency attribute */
	asm(	"mfc0	$t0,	$16\n"		/* CP0_CONFIG == 16 */
		"li	$t1,	~7\n"
		"and	$t0,	$t0,	$t1\n"
		"ori	$t0,	3\n"		/* CONF_CM_CACHABLE_NONCOHERENT */
		"mtc0	$t0,	$16\n"		/* CP0_CONFIG == 16 */
		"nop\n": : );
}
#endif

void do_bootm_linux (cmd_tbl_t * cmdtp, int flag, int argc, char *argv[],
		     ulong addr, ulong * len_ptr, int verify)
{
	ulong len = 0, checksum;
	ulong initrd_start, initrd_end;
	ulong data;
#if defined(CONFIG_AR7100) || defined(CONFIG_AR7240) || defined(CONFIG_ATHEROS)
	int flash_size_mbytes;
	void (*theKernel) (int, char **, char **, int);
#else
	void (*theKernel) (int, char **, char **, int *);
#endif
	image_header_t *hdr = &header;
	char *commandline = getenv ("bootargs");
	char env_buf[12];

#if defined(CONFIG_AR7100) || defined(CONFIG_AR7240) || defined(CONFIG_ATHEROS)
	theKernel =
		(void (*)(int, char **, char **, int)) ntohl (hdr->ih_ep);
#else
	theKernel =
		(void (*)(int, char **, char **, int *)) ntohl (hdr->ih_ep);
#endif

	/*
	 * Check if there is an initrd image
	 */
	if (argc >= 3) {
		SHOW_BOOT_PROGRESS (9);

		addr = simple_strtoul (argv[2], NULL, 16);

		printf ("## Loading Ramdisk Image at %08lx ...\n", addr);

		/* Copy header so we can blank CRC field for re-calculation */
		memcpy (&header, (char *) addr, sizeof (image_header_t));

		if (ntohl (hdr->ih_magic) != IH_MAGIC) {
			printf ("Bad Magic Number\n");
			SHOW_BOOT_PROGRESS (-10);
			do_reset (cmdtp, flag, argc, argv);
		}

		data = (ulong) & header;
		len = sizeof (image_header_t);

		checksum = ntohl (hdr->ih_hcrc);
		hdr->ih_hcrc = 0;

		if (crc32 (0, (uchar *) data, len) != checksum) {
			printf ("Bad Header Checksum\n");
			SHOW_BOOT_PROGRESS (-11);
			do_reset (cmdtp, flag, argc, argv);
		}

		SHOW_BOOT_PROGRESS (10);

		print_image_hdr (hdr);

		data = addr + sizeof (image_header_t);
		len = ntohl (hdr->ih_size);

		if (verify) {
			ulong csum = 0;

			printf ("   Verifying Checksum ... ");
			csum = crc32 (0, (uchar *) data, len);
			if (csum != ntohl (hdr->ih_dcrc)) {
				printf ("Bad Data CRC\n");
				SHOW_BOOT_PROGRESS (-12);
				do_reset (cmdtp, flag, argc, argv);
			}
			printf ("OK\n");
		}

		SHOW_BOOT_PROGRESS (11);

		if ((hdr->ih_os != IH_OS_LINUX) ||
		    (hdr->ih_arch != IH_CPU_MIPS) ||
		    (hdr->ih_type != IH_TYPE_RAMDISK)) {
			printf ("No Linux MIPS Ramdisk Image\n");
			SHOW_BOOT_PROGRESS (-13);
			do_reset (cmdtp, flag, argc, argv);
		}

		/*
		 * Now check if we have a multifile image
		 */
	} else if ((hdr->ih_type == IH_TYPE_MULTI) && (len_ptr[1])) {
		ulong tail = ntohl (len_ptr[0]) % 4;
		int i;

		SHOW_BOOT_PROGRESS (13);

		/* skip kernel length and terminator */
		data = (ulong) (&len_ptr[2]);
		/* skip any additional image length fields */
		for (i = 1; len_ptr[i]; ++i)
			data += 4;
		/* add kernel length, and align */
		data += ntohl (len_ptr[0]);
		if (tail) {
			data += 4 - tail;
		}

		len = ntohl (len_ptr[1]);

	} else {
		/*
		 * no initrd image
		 */
		SHOW_BOOT_PROGRESS (14);

		data = 0;
	}

#ifdef	DEBUG
	if (!data) {
		printf ("No initrd\n");
	}
#endif

	if (data) {
		initrd_start = data;
		initrd_end = initrd_start + len;
	} else {
		initrd_start = 0;
		initrd_end = 0;
	}

	SHOW_BOOT_PROGRESS (15);

#ifdef DEBUG
	printf ("## Transferring control to Linux (at address %08lx) ...\n",
		(ulong) theKernel);
#endif

	linux_params_init (UNCACHED_SDRAM (gd->bd->bi_boot_params), commandline);

#ifdef CONFIG_MEMSIZE_IN_BYTES
	sprintf (env_buf, "%lu", gd->ram_size);
#ifdef DEBUG
	printf ("## Giving linux memsize in bytes, %lu\n", gd->ram_size);
#endif
#else
	sprintf (env_buf, "%lu", gd->ram_size >> 20);
#ifdef DEBUG
	printf ("## Giving linux memsize in MB, %lu\n", gd->ram_size >> 20);
#endif
#endif /* CONFIG_MEMSIZE_IN_BYTES */

	linux_env_set ("memsize", env_buf);

	sprintf (env_buf, "0x%08X", (uint) UNCACHED_SDRAM (initrd_start));
	linux_env_set ("initrd_start", env_buf);

	sprintf (env_buf, "0x%X", (uint) (initrd_end - initrd_start));
	linux_env_set ("initrd_size", env_buf);

	sprintf (env_buf, "0x%08X", (uint) (gd->bd->bi_flashstart));
	linux_env_set ("flash_start", env_buf);

	sprintf (env_buf, "0x%X", (uint) (gd->bd->bi_flashsize));
	linux_env_set ("flash_size", env_buf);

	/* we assume that the kernel is in place */
	printf ("\nStarting kernel ...\n\n");

#if defined(CONFIG_ATH_SPI_CS1_GPIO) || defined(ATH_DUAL_NOR)
	flash_select(0);
#endif

#if defined(CONFIG_AR7100) || defined(CONFIG_AR7240) || defined(CONFIG_ATHEROS)
#ifdef CONFIG_WASP_SUPPORT
	wasp_set_cca();
#endif
	/* Pass the flash size as expected by current Linux kernel for AR7100 */
	flash_size_mbytes = gd->bd->bi_flashsize/(1024 * 1024);
	theKernel (linux_argc, linux_argv, linux_env, flash_size_mbytes);
#else
	theKernel (linux_argc, linux_argv, linux_env, 0);
#endif
}

static void linux_params_init (ulong start, char *line)
{
	char *next, *quote, *argp;
#if defined(CONFIG_AR9100) || defined(CONFIG_AR7240) || defined(CONFIG_ATHEROS)
	char memstr[32];
	int memsize = 0;
#endif
	linux_argc = 1;
	linux_argv = (char **) start;
	linux_argv[0] = 0;
	argp = (char *) (linux_argv + LINUX_MAX_ARGS);

	next = line;
#if defined(CONFIG_AR9100) || defined(CONFIG_AR7240) || defined(CONFIG_ATHEROS)
	if (line && strstr(line, "mem=")) {
		memstr[0] = 0;
		memsize = simple_strtoul((strstr(line, "mem=") + 4), NULL, 10);
	} else {
		memstr[0] = 1;
	}
#endif
	while (line && *line && linux_argc < LINUX_MAX_ARGS) {
		quote = strchr (line, '"');
		next = strchr (line, ' ');

		while (next != NULL && quote != NULL && quote < next) {
			/* we found a left quote before the next blank
			 * now we have to find the matching right quote
			 */
			next = strchr (quote + 1, '"');
			if (next != NULL) {
				quote = strchr (next + 1, '"');
				next = strchr (next + 1, ' ');
			}
		}

		if (next == NULL) {
			next = line + strlen (line);
		}

		linux_argv[linux_argc] = argp;
		memcpy (argp, line, next - line);
		argp[next - line] = 0;
#if defined(CONFIG_AR7240)
#define REVSTR	"REVISIONID"
#define PYTHON	"python"
#define VIRIAN	"virian"
		if (strcmp(argp, REVSTR) == 0) {
			if (is_ar7241() || is_ar7242()) {
				strcpy(argp, VIRIAN);
			} else {
				strcpy(argp, PYTHON);
			}
		}
#endif

		argp += next - line + 1;
		linux_argc++;

		if (*next)
			next++;

		line = next;
	}

#if defined(CONFIG_AR9100) || defined(CONFIG_AR7240) || defined(CONFIG_ATHEROS)
	/* Add mem size to command line */
	if (memstr[0]) {
		sprintf(memstr, "mem=%luM", gd->ram_size >> 20);
		memcpy (argp, memstr, strlen(memstr)+1);
		linux_argv[linux_argc] = argp;
		linux_argc++;
		argp += strlen(memstr) + 1;
		sprintf(memstr, "%luM", gd->ram_size >> 20);
	}
	else {
		if(memsize > (gd->ram_size >> 20)) {
			sprintf(memstr, "%luM" , gd->ram_size >> 20);
		} else {
			sprintf(memstr, "%luM" , memsize);
		}
	}
#endif

	linux_env = (char **) (((ulong) argp + 15) & ~15);
	linux_env[0] = 0;
	linux_env_p = (char *) (linux_env + LINUX_MAX_ENVS);
	linux_env_idx = 0;

#if defined(CONFIG_AR9100) || defined(CONFIG_AR7240) || defined(CONFIG_ATHEROS)
	linux_env_set ("mem", memstr);
#endif
}

static void linux_env_set (char *env_name, char *env_val)
{
	if (linux_env_idx < LINUX_MAX_ENVS - 1) {
		linux_env[linux_env_idx] = linux_env_p;

		strcpy (linux_env_p, env_name);
		linux_env_p += strlen (env_name);

		strcpy (linux_env_p, "=");
		linux_env_p += 1;

		strcpy (linux_env_p, env_val);
		linux_env_p += strlen (env_val);

		linux_env_p++;
		linux_env[++linux_env_idx] = 0;
	}
}
