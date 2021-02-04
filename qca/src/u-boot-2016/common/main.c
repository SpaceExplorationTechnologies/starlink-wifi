/*
 * (C) Copyright 2000
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

/* #define	DEBUG	*/

#include <common.h>
#include <autoboot.h>
#include <cli.h>
#include <console.h>
#include <version.h>

DECLARE_GLOBAL_DATA_PTR;

void setled (void);

/*
 * Board-specific Platform code can reimplement show_boot_progress () if needed
 */
__weak void show_boot_progress(int val) {}

static void modem_init(void)
{
#ifdef CONFIG_MODEM_SUPPORT
	debug("DEBUG: main_loop:   gd->do_mdm_init=%lu\n", gd->do_mdm_init);
	if (gd->do_mdm_init) {
		char *str = getenv("mdm_cmd");

		setenv("preboot", str);  /* set or delete definition */
		mdm_init(); /* wait for modem connection */
	}
#endif  /* CONFIG_MODEM_SUPPORT */
}

static void run_preboot_environment_command(void)
{
#ifdef CONFIG_PREBOOT
	char *p;

	p = getenv("preboot");
	if (p != NULL) {
# ifdef CONFIG_AUTOBOOT_KEYED
		int prev = disable_ctrlc(1);	/* disable Control C checking */
# endif

		run_command_list(p, -1, 0);

# ifdef CONFIG_AUTOBOOT_KEYED
		disable_ctrlc(prev);	/* restore Control C checking */
# endif
	}
#endif /* CONFIG_PREBOOT */
}

/* We come here after U-Boot is initialised and ready to process commands */
void main_loop(void)
{
	const char *s;

	bootstage_mark_name(BOOTSTAGE_ID_MAIN_LOOP, "main_loop");

#ifndef CONFIG_SYS_GENERIC_BOARD
	puts("Warning: Your board does not use generic board. Please read\n");
	puts("doc/README.generic-board and take action. Boards not\n");
	puts("upgraded by the late 2014 may break or be removed.\n");
#endif

	modem_init();
#ifdef CONFIG_VERSION_VARIABLE
	setenv("ver", version_string);  /* set version variable */
#endif /* CONFIG_VERSION_VARIABLE */

	cli_init();

	run_preboot_environment_command();

#if defined(CONFIG_UPDATE_TFTP)
	update_tftp(0UL, NULL, NULL);
#endif /* CONFIG_UPDATE_TFTP */

    // run fuse command
    //run_command("fuseipq 0x88000000", 0);

  setled();

	s = bootdelay_process();
	if (cli_process_fdt(&s))
		cli_secure_boot_cmd(s);

	autoboot_command(s);

	cli_loop();
}

void setled (void)
{
/* WNC add for set LED */
  run_command("i2c dev 0", 0);
	mdelay(10);
  run_command("i2c probe", 0);
	mdelay(1000);
/* clear RED/BLUE/WHITE LED first at boot time*/
	run_command("i2c mw 30 70 00", 0);
	mdelay(10);
	run_command("i2c mw 30 04 00", 0);
	mdelay(10);
	
	//disable White LED
	run_command("i2c mw 30 0e 00", 0);
	mdelay(10);
	//disable Red LED
	run_command("i2c mw 30 04 00", 0);
	mdelay(10);
	//disable Blue LED
	run_command("i2c mw 30 02 00", 0);
	mdelay(10);

	/* Start easing LED */
	run_command("i2c mw 30 00 40", 0);
	mdelay(10);
	run_command("i2c mw 30 08 01", 0);
	mdelay(10);
	run_command("i2c mw 30 01 10", 0);
	mdelay(10);
	run_command("i2c mw 30 70 40", 0);
	mdelay(10);
	run_command("i2c mw 30 10 13", 0);
	mdelay(10);
	run_command("i2c mw 30 11 7f", 0);
	mdelay(10);
	run_command("i2c mw 30 12 4d", 0);
	mdelay(10);
	run_command("i2c mw 30 13 00", 0);
	mdelay(10);
	run_command("i2c mw 30 14 13", 0);
	mdelay(10);
	run_command("i2c mw 30 15 ff", 0);
	mdelay(10);
	run_command("i2c mw 30 16 60", 0);
	mdelay(10);
	run_command("i2c mw 30 17 00", 0);
	mdelay(10);
	run_command("i2c mw 30 01 20", 0);
	mdelay(10);
	run_command("i2c mw 30 00 60", 0); 
	mdelay(1400); // wait for match cycle brughtness with Kernel reset white LED earing....
}	

