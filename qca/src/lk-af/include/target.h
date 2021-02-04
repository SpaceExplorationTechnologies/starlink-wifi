/*
 * Copyright (c) 2008 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __TARGET_H
#define __TARGET_H

/* Target helper functions exposed to USB driver */
typedef struct {
	void (*mux_config)(void);
	void (*phy_reset)(void);
	void (*phy_init)(void);
	void (*clock_init)(void);
	uint8_t vbus_override;
} target_usb_iface_t;

/* super early platform initialization, before almost everything */
void target_early_init(void);

/* later init, after the kernel has come up */
void target_init(void);

/* get memory address for fastboot image loading */
void *target_get_scratch_address(void);

/* get the max allowed flash size */
unsigned target_get_max_flash_size(void);

/* if target is using eMMC bootup */
int target_is_emmc_boot(void);

unsigned* target_atag_mem(unsigned* ptr);
void *target_get_scratch_address(void);
unsigned target_get_max_flash_size(void);
void target_battery_charging_enable(unsigned enable, unsigned disconnect);
unsigned target_pause_for_battery_charge(void);
unsigned target_baseband(void);
void target_serialno(unsigned char *buf);
void target_fastboot_init(void);
void target_usb_init(void);
void target_usb_stop(void);
target_usb_iface_t *target_usb30_init();
const char *target_usb_controller(void);
void *target_mmc_device(void);
int target_mmc_bus_width(void);
bool target_use_signed_kernel(void);
int  target_get_key_status(uint32_t gpio);
#endif
