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

#include <asm/types.h>
#include "rom.addrs.h"

bootrom_fn_t bootrom_fn[] = {
	{
		(void *)0xbfc012dc, /* void serial_puts (const char *s) */
		(void *)0xbfc00c2c, /* int printf (const char *fmt, ...) */
		(void *)0xbfc00ac8, /* void udelay (unsigned long usec) */
		(void *)0xbfc00730, /* void simple_mips_cache_reset(void) */
		(void *)0xbfc005d4, /* void call_fw(u32, u32) */
	},
};

void (*serial_puts)(const char *s);
int (*printf)(const char *fmt, ...);
void (*udelay)(unsigned long usec);
void (*simple_mips_cache_reset)(void);
void (*call_fw)(u32, u32);
