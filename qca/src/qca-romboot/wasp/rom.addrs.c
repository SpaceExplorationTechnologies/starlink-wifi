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
// Wasp 1.0
	{
		(void *)0xbfc01114, (void *)0xbfc04000, (void *)0xbfc045ac,
		(void *)0xbfc00720, (void *)0xbfc005d0, (void *)0xbd0008a8
	},
// Wasp 1.1
	{
		(void *)0xbfc0114c, (void *)0xbfc0421c, (void *)0xbfc047a8,
		(void *)0xbfc00730, (void *)0xbfc005d4, (void *)0xbd000898
	},
// Wasp 1.2, same as above
	{
		(void *)0xbfc0114c, (void *)0xbfc0421c, (void *)0xbfc047a8,
		(void *)0xbfc00730, (void *)0xbfc005d4, (void *)0xbd000898
	},
// Wasp 1.3
	{
		(void *)0xbfc00c7c, (void *)0xbfc00f2c, (void *)0xbfc00ac8,
		(void *)0xbfc00730, (void *)0xbfc005d4,
	},
};
