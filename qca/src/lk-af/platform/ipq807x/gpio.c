/* Copyright (c) 2012-2015, 2017 The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of The Linux Foundation. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <debug.h>
#include <reg.h>
#include <platform/iomap.h>
#include <platform/gpio.h>
#include <gsbi.h>
#include <target/board.h>
#include <sys/types.h>
#include <smem.h>

void gpio_tlmm_config(unsigned int gpio, unsigned int func,
		unsigned int out, unsigned int pull,
		unsigned int drvstr, unsigned int oe,
		unsigned int gpio_vm, unsigned int gpio_od_en,
		unsigned int gpio_pu_res)
{
	unsigned int val = 0;
	val |= pull;
	val |= func << 2;
	val |= drvstr << 6;
	val |= oe << 9;
	val |= gpio_vm << 11;
	val |= gpio_od_en << 12;
	val |= gpio_pu_res << 13;

	unsigned int *addr = (unsigned int *)GPIO_CONFIG_ADDR(gpio);
	writel(val, addr);

	/* Output value is only relevant if GPIO has been configured for fixed
	 * output setting - i.e. func == 0 */
	if (func == 0) {
		addr = (unsigned int *)GPIO_IN_OUT_ADDR(gpio);
		val = readl(addr);
		val |= out << 1;
		writel(val, addr);
	}

	return;
}

void gpio_set_value(unsigned int gpio, unsigned int out)
{
	unsigned int *addr = (unsigned int *)GPIO_IN_OUT_ADDR(gpio);
	unsigned int val = 0;

	val = readl(addr);
	val &= ~(0x2);
	val |= out << 1;
	writel(val, addr);
}

void gpio_set(uint32_t gpio, uint32_t dir)
{
	unsigned int *addr = (unsigned int *)GPIO_IN_OUT_ADDR(gpio);
	writel(dir, addr);
	return;
}

uint32_t gpio_get(uint32_t gpio)
{
	unsigned int *addr = (unsigned int *)GPIO_IN_OUT_ADDR(gpio);
	return readl(addr);
}
void ipq_configure_gpio(gpio_func_data_t *gpio, int count)
{
	int i;

	for (i = 0; i < count; i++) {
                gpio_tlmm_config(gpio->gpio, gpio->func, gpio->out,
                        gpio->pull, gpio->drvstr, gpio->oe,
                        gpio->gpio_vm, gpio->gpio_od_en, gpio->gpio_pu_res);
                gpio++;
        }

}

/* Configure gpio for uart - based on gsbi id */
void gpio_config_uart_dm(uint8_t ignore)
{
	uart_cfg_t *uart = gboard_param->console_uart_cfg;

	ipq_configure_gpio(uart->dbg_uart_gpio, NO_OF_DBG_UART_GPIOS);
}
