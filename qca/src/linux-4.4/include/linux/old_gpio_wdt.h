/*
 *  Definitions for the GPIO watchdog driver
 *
 *  Copyright (C) 2013 Mathias Adam <m.adam--linux@adamis.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#ifndef _GPIO_WDT_H_
#define _GPIO_WDT_H_

struct gpio_wdt_platform_data {
	int	gpio;		/* GPIO line number */
	int	interval;	/* watchdog reset interval in system ticks */
	int	first_interval;	/* first wd reset interval in system ticks */
};

#endif /* _GPIO_WDT_H_ */
