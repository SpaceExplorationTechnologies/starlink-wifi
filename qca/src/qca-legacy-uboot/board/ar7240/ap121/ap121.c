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
#include "ar7240_soc.h"

extern void ar7240_ddr_initial_config(uint32_t refresh);
extern int ar7240_ddr_find_size(void);
extern void hornet_ddr_tap_init(void);

#ifdef CONFIG_HORNET_EMU
extern void ar7240_ddr_initial_config_for_fpga(void);
#endif

void
ar7240_usb_initial_config(void)
{
#ifndef CONFIG_HORNET_EMU
    ar7240_reg_wr_nf(AR7240_USB_PLL_CONFIG, 0x0a04081e);
    ar7240_reg_wr_nf(AR7240_USB_PLL_CONFIG, 0x0804081e);
#endif
}

void
ar7240_usb_otp_config(void)
{
    unsigned int addr, reg_val, reg_usb = 0;
    int time_out, status, usb_valid;
    
    for (addr = 0xb8114014; ;addr -= 0x10) {
        status = 0;
        time_out = 20;
        
        reg_val = ar7240_reg_rd(addr);

        while ((time_out > 0) && (~status)) {
            if ((( ar7240_reg_rd(0xb8115f18)) & 0x7) == 0x4) {
                status = 1;
            } else {
                status = 0;
            }
            time_out--;
        }

        reg_val = ar7240_reg_rd(0xb8115f1c);
        if ((reg_val & 0x80) == 0x80){
            usb_valid = 1;
            reg_usb = reg_val & 0x000000ff;
        }

        if (addr == 0xb8114004) {
            break;
        }
    }

    if (usb_valid) {
        reg_val = ar7240_reg_rd(0xb8116c88);
        reg_val &= ~0x03f00000;
        reg_val |= (reg_usb & 0xf) << 22;
        ar7240_reg_wr(0xb8116c88, reg_val);
    }
}

void ar7240_gpio_config(void)
{
    /* Disable clock obs 
     * clk_obs1(gpio13/bit8),  clk_obs2(gpio14/bit9), clk_obs3(gpio15/bit10),
     * clk_obs4(gpio16/bit11), clk_obs5(gpio17/bit12)
     * clk_obs0(gpio1/bit19), 6(gpio11/bit20)
     */
    ar7240_reg_wr (AR7240_GPIO_FUNC, 
        (ar7240_reg_rd(AR7240_GPIO_FUNC) & ~((0x1f<<8)|(0x3<<19))));

    /* Enable eth Switch LEDs */
    ar7240_reg_wr (AR7240_GPIO_FUNC, (ar7240_reg_rd(AR7240_GPIO_FUNC) | (0x1f<<3)));
	
    /* Clear AR7240_GPIO_FUNC BIT2 to ensure that software can control LED5(GPIO16) and LED6(GPIO17)  */
    ar7240_reg_wr (AR7240_GPIO_FUNC, (ar7240_reg_rd(AR7240_GPIO_FUNC) & ~(0x1<<2)));
	
    /* Set HORNET_BOOTSTRAP_STATUS BIT18 to ensure that software can control GPIO26 and GPIO27 */
    //ar7240_reg_wr (HORNET_BOOTSTRAP_STATUS, (ar7240_reg_rd(HORNET_BOOTSTRAP_STATUS) | (0x1<<18)));
}

int
ar7240_mem_config(void)
{
#ifndef COMPRESSED_UBOOT
    unsigned int tap_val1, tap_val2;
#endif
#ifdef CONFIG_HORNET_EMU
    ar7240_ddr_initial_config_for_fpga();
#else
    //ar7240_ddr_initial_config(CFG_DDR_REFRESH_VAL);
#endif

/* Default tap values for starting the tap_init*/
    ar7240_reg_wr (AR7240_DDR_TAP_CONTROL0, CFG_DDR_TAP0_VAL);
    ar7240_reg_wr (AR7240_DDR_TAP_CONTROL1, CFG_DDR_TAP1_VAL);

    ar7240_gpio_config();

#ifndef COMPRESSED_UBOOT
#ifndef CONFIG_HORNET_EMU
    ar7240_ddr_tap_init();

    tap_val1 = ar7240_reg_rd(0xb800001c);
    tap_val2 = ar7240_reg_rd(0xb8000020);
    printf("#### TAP VALUE 1 = %x, 2 = %x\n",tap_val1, tap_val2);
#endif
#endif

    //ar7240_usb_initial_config();
    ar7240_usb_otp_config();
    
    hornet_ddr_tap_init();

    return (ar7240_ddr_find_size());
}

long int initdram(int board_type)
{
    return (ar7240_mem_config());
}

#ifdef COMPRESSED_UBOOT
int checkboard (char *board_string)
{
#if (BOARD_STRING == WAPI)
    strcpy(board_string, "AP121 (ar9331) U-boot");
#else
    strcpy(board_string, "AP121-2MB (ar9330) U-boot");
#endif
    return 0;
}
#else
int checkboard (void)
{
    printf("AP121 (ar9330) U-boot\n");
    return 0;
}
#endif /* #ifdef COMPRESSED_UBOOT */
