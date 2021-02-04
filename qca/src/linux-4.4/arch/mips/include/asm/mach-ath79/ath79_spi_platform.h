/*
 *  Platform data definition for Atheros AR71XX/AR724X/AR913X SPI controller
 *
 *  Copyright (C) 2008-2010 Gabor Juhos <juhosg@openwrt.org>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#ifndef _ATH79_SPI_PLATFORM_H
#define _ATH79_SPI_PLATFORM_H

struct ath79_spi_platform_data {
	unsigned	bus_num;
	unsigned	num_chipselect;
};

enum ath79_spi_cs_type {
	ATH79_SPI_CS_TYPE_INTERNAL,
	ATH79_SPI_CS_TYPE_GPIO,
};

struct ath79_spi_controller_data {
	enum ath79_spi_cs_type cs_type;
	unsigned cs_line;
	bool is_flash;
};

#endif /* _ATH79_SPI_PLATFORM_H */
