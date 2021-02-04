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

/* This is an auto-generated file. Do not edit */
typedef struct {
	void (*serial_puts)(const char *s);
	void (*udelay)(unsigned long usec);
	void (*simple_mips_cache_reset)(void);
	void (*call_fw)(u32, u32);
} bootrom_fn_t;
extern void (*serial_puts)(const char *s);
extern void (*udelay)(unsigned long usec);
extern void (*simple_mips_cache_reset)(void);
extern void (*call_fw)(u32, u32);
