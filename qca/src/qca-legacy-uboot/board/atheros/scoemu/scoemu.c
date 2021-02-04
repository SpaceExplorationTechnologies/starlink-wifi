/* 
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 */

#include <common.h>
#include <command.h>
#include <asm/mipsregs.h>
#include <asm/addrspace.h>
#include <config.h>
#include <version.h>
#include <atheros.h>

extern int ath_ddr_initial_config(uint32_t refresh);
extern int ath_ddr_find_size(void);

#ifdef COMPRESSED_UBOOT
#	define prmsg(x)	strcpy(s, x)
#	define CHECKBOARD_PARAMS	char *s
#else
#	define prmsg	printf
#	define CHECKBOARD_PARAMS	void
#endif

void
ath_usb_initial_config(void)
{
#define unset(a)	(~(a))

	if (RST_BOOTSTRAP_REF_CLK_GET(ath_reg_rd(RST_BOOTSTRAP_ADDRESS)) == 0) {
		ath_reg_wr_nf(SWITCH_CLOCK_SPARE_ADDRESS,
			ath_reg_rd(SWITCH_CLOCK_SPARE_ADDRESS) |
			SWITCH_CLOCK_SPARE_USB_REFCLK_FREQ_SEL_SET(2));
	} else {
		ath_reg_wr_nf(SWITCH_CLOCK_SPARE_ADDRESS,
			ath_reg_rd(SWITCH_CLOCK_SPARE_ADDRESS) |
			SWITCH_CLOCK_SPARE_USB_REFCLK_FREQ_SEL_SET(5));
	}

	udelay(1000);
	ath_reg_wr(RST_RESET_ADDRESS,
		ath_reg_rd(RST_RESET_ADDRESS) |
		RST_RESET_USB_PHY_SUSPEND_OVERRIDE_SET(1));
	udelay(1000);
	ath_reg_wr(RST_RESET_ADDRESS,
		ath_reg_rd(RST_RESET_ADDRESS) &
		unset(RST_RESET_USB_PHY_RESET_SET(1)));
	udelay(1000);
	ath_reg_wr(RST_RESET_ADDRESS,
		ath_reg_rd(RST_RESET_ADDRESS) &
		unset(RST_RESET_USB_PHY_ARESET_SET(1)));
	udelay(1000);
	ath_reg_wr(RST_RESET_ADDRESS,
		ath_reg_rd(RST_RESET_ADDRESS) &
		unset(RST_RESET_USB_HOST_RESET_SET(1)));
	udelay(1000);
	if ((ath_reg_rd(RST_REVISION_ID_ADDRESS) & 0xf) == 0) {
		/* Only for WASP 1.0 */
		ath_reg_wr(0xb8116c84 ,
			ath_reg_rd(0xb8116c84) & unset(1<<20));
	}
}

void ath_gpio_config(void)
{
#if 0
	/* Disable clock obs */
	ath_reg_wr (AR7240_GPIO_FUNC, (ath_reg_rd(AR7240_GPIO_FUNC) & 0xffe7e0ff));
	/* Enable eth Switch LEDs */
#ifdef CONFIG_K31
	ath_reg_wr (AR7240_GPIO_FUNC, (ath_reg_rd(AR7240_GPIO_FUNC) | 0xd8));
#else
	ath_reg_wr (AR7240_GPIO_FUNC, (ath_reg_rd(AR7240_GPIO_FUNC) | 0xfa));
#endif
#endif
}

int
ath_mem_config(void)
{
	unsigned int type, reg32;

#if !defined(CONFIG_ATH_EMULATION)
	type = ath_ddr_initial_config(CFG_DDR_REFRESH_VAL);

	/* Take WMAC out of reset */
	reg32 = ath_reg_rd(RST_RESET_ADDRESS);
	reg32 = reg32 &  ~RST_RESET_RTC_RESET_SET(1);
	ath_reg_wr_nf(RST_RESET_ADDRESS, reg32);

	/* Switching regulator settings */
	ath_reg_wr_nf(0x18116c40, 0x633c8176); /* AR_PHY_PMU1 */
#if !defined(CONFIG_ATH_NAND_BR)
	if (ath_reg_rd(RST_REVISION_ID_ADDRESS) & 0xf) {
		if (type == 2) {
			// ddr1
			ath_reg_wr_nf(0x18116c44, 0x10000000); /* AR_PHY_PMU2 */
		} else {
			// ddr2 & sdram
			ath_reg_wr_nf(0x18116c44, 0x10380000); /* AR_PHY_PMU2 */
		}
	} else {
		ath_reg_wr_nf(0x18116c44, 0x10380000); /* AR_PHY_PMU2 */
	}
#endif

	ath_usb_initial_config();

	ath_gpio_config();
#endif /* !defined(CONFIG_ATH_EMULATION) */

	reg32 = ath_ddr_find_size();

	return reg32;
}

long int initdram(int board_type)
{
	return (ath_mem_config());
}

int	checkboard(CHECKBOARD_PARAMS)
{
	prmsg("U-boot Scorpion Emulation\n");
	return 0;
}
