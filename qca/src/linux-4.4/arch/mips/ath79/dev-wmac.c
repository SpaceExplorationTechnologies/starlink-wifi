/*
 *  Atheros AR913X/AR933X SoC built-in WMAC device support
 *
 *  Copyright (C) 2010-2011 Jaiganesh Narayanan <jnarayanan@atheros.com>
 *  Copyright (C) 2008-2011 Gabor Juhos <juhosg@openwrt.org>
 *  Copyright (C) 2008 Imre Kaloz <kaloz@openwrt.org>
 *
 *  Parts of this file are based on Atheros 2.6.15/2.6.31 BSP
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <linux/init.h>
#include <linux/delay.h>
#include <linux/irq.h>
#include <linux/etherdevice.h>
#include <linux/platform_device.h>
#include <linux/ath9k_platform.h>
#include <linux/gpio.h>

#include <asm/mach-ath79/ath79.h>
#include <asm/mach-ath79/ar71xx_regs.h>
#include "common.h"
#include "dev-wmac.h"

#include <linux/ath79_wlan.h>

#ifdef ATH79_WLAN_FW_DUMP
void *ath79_wlan_fw_dump_addr;
#endif
static u8 ath79_wmac_mac[ETH_ALEN];

static struct ath9k_platform_data ath79_wmac_data = {
	.led_pin = -1,
};

static struct resource ath79_wmac_resources[] = {
	{
		/* .start and .end fields are filled dynamically */
		.flags	= IORESOURCE_MEM,
	}, {
		/* .start and .end fields are filled dynamically */
		.flags	= IORESOURCE_IRQ,
	},
};

static struct platform_device ath79_wmac_device = {
	.name		= "ath9k",
	.id		= -1,
	.resource	= ath79_wmac_resources,
	.num_resources	= ARRAY_SIZE(ath79_wmac_resources),
	.dev = {
		.platform_data = &ath79_wmac_data,
	},
};

static int ar913x_wmac_reset(void)
{
	/* reset the WMAC */
	ath79_device_reset_set(AR913X_RESET_AMBA2WMAC);
	mdelay(10);

	ath79_device_reset_clear(AR913X_RESET_AMBA2WMAC);
	mdelay(10);

	return 0;
}

#ifdef ATH79_WLAN_FW_DUMP
int ath79_get_wlan_fw_dump_buffer(void **dump_buff, u32 *buff_size)
{
	int ret = 0;

	if (ath79_wlan_fw_dump_addr) {
		*dump_buff = ath79_wlan_fw_dump_addr;
		*buff_size = ATH79_FW_DUMP_MEM_SIZE;
	} else {
		*dump_buff = NULL;
		*buff_size = 0;
		ret = -1;
	}
	return ret;
}
EXPORT_SYMBOL(ath79_get_wlan_fw_dump_buffer);
EXPORT_SYMBOL(ath79_wlan_fw_dump_addr);

void ath79_init_wlan_fw_dump_buffer(void)
{
	ath79_wlan_fw_dump_addr = kmalloc(ATH79_FW_DUMP_MEM_SIZE, GFP_ATOMIC);
	if (ath79_wlan_fw_dump_addr)
		printk("\n WLAN firmware dump buffer allocation of %d bytes @ address 0x%p- SUCCESS !!!",
		ATH79_FW_DUMP_MEM_SIZE, (void *)ath79_wlan_fw_dump_addr);
	else
		printk("\n WLAN firmware dump buffer allocation-FAILED!!!");

}
#endif

static void __init ar913x_wmac_setup(void)
{
	ar913x_wmac_reset();

	ath79_wmac_resources[0].start = AR913X_WMAC_BASE;
	ath79_wmac_resources[0].end = AR913X_WMAC_BASE + AR913X_WMAC_SIZE - 1;
	ath79_wmac_resources[1].start = ATH79_CPU_IRQ(2);
	ath79_wmac_resources[1].end = ATH79_CPU_IRQ(2);

	ath79_wmac_data.external_reset = ar913x_wmac_reset;
}


static int ar933x_wmac_reset(void)
{
	int retries = 20;

	ath79_device_reset_set(AR933X_RESET_WMAC);
	ath79_device_reset_clear(AR933X_RESET_WMAC);

	while (1) {
		u32 bootstrap;

		bootstrap = ath79_reset_rr(AR933X_RESET_REG_BOOTSTRAP);
		if ((bootstrap & AR933X_BOOTSTRAP_EEPBUSY) == 0)
			return 0;

		if (retries-- == 0)
			break;

		udelay(10000);
		retries++;
	}

	pr_err("ar933x: WMAC reset timed out");
	return -ETIMEDOUT;
}

static int ar93xx_get_soc_revision(void)
{
	return ath79_soc_rev;
}

static void __init ar933x_wmac_setup(void)
{
	u32 t;

	ar933x_wmac_reset();

	ath79_wmac_device.name = "ar933x_wmac";

	ath79_wmac_resources[0].start = AR933X_WMAC_BASE;
	ath79_wmac_resources[0].end = AR933X_WMAC_BASE + AR933X_WMAC_SIZE - 1;
	ath79_wmac_resources[1].start = ATH79_CPU_IRQ(2);
	ath79_wmac_resources[1].end = ATH79_CPU_IRQ(2);

	t = ath79_reset_rr(AR933X_RESET_REG_BOOTSTRAP);
	if (t & AR933X_BOOTSTRAP_REF_CLK_40)
		ath79_wmac_data.is_clk_25mhz = false;
	else
		ath79_wmac_data.is_clk_25mhz = true;

	if (ath79_soc_rev == 1)
		ath79_wmac_data.get_mac_revision = ar93xx_get_soc_revision;

	ath79_wmac_data.external_reset = ar933x_wmac_reset;
}

static void ar934x_wmac_setup(void)
{
	u32 t;

	ath79_wmac_device.name = "ar934x_wmac";

	ath79_wmac_resources[0].start = AR934X_WMAC_BASE;
	ath79_wmac_resources[0].end = AR934X_WMAC_BASE + AR934X_WMAC_SIZE - 1;
	ath79_wmac_resources[1].start = ATH79_IP2_IRQ(1);
	ath79_wmac_resources[1].end = ATH79_IP2_IRQ(1);

	t = ath79_reset_rr(AR934X_RESET_REG_BOOTSTRAP);
	if (t & AR934X_BOOTSTRAP_REF_CLK_40)
		ath79_wmac_data.is_clk_25mhz = false;
	else
		ath79_wmac_data.is_clk_25mhz = true;

	ath79_wmac_data.get_mac_revision = ar93xx_get_soc_revision;
}

static void qca953x_wmac_setup(void)
{
	u32 t;

	ath79_wmac_device.name = "qca953x_wmac";

	ath79_wmac_resources[0].start = QCA953X_WMAC_BASE;
	ath79_wmac_resources[0].end = QCA953X_WMAC_BASE + QCA953X_WMAC_SIZE - 1;
	ath79_wmac_resources[1].start = ATH79_IP2_IRQ(1);
	ath79_wmac_resources[1].end = ATH79_IP2_IRQ(1);

	t = ath79_reset_rr(QCA953X_RESET_REG_BOOTSTRAP);
	if (t & QCA953X_BOOTSTRAP_REF_CLK_40)
		ath79_wmac_data.is_clk_25mhz = false;
	else
		ath79_wmac_data.is_clk_25mhz = true;

	ath79_wmac_data.get_mac_revision = ar93xx_get_soc_revision;
}

static void qca955x_wmac_setup(void)
{
	u32 t;

	ath79_wmac_device.name = "qca955x_wmac";

	ath79_wmac_resources[0].start = QCA955X_WMAC_BASE;
	ath79_wmac_resources[0].end = QCA955X_WMAC_BASE + QCA955X_WMAC_SIZE - 1;
	ath79_wmac_resources[1].start = ATH79_IP2_IRQ(1);
	ath79_wmac_resources[1].end = ATH79_IP2_IRQ(1);

	t = ath79_reset_rr(QCA955X_RESET_REG_BOOTSTRAP);
	if (t & QCA955X_BOOTSTRAP_REF_CLK_40)
		ath79_wmac_data.is_clk_25mhz = false;
	else
		ath79_wmac_data.is_clk_25mhz = true;
}

static void qca956x_wmac_setup(void)
{
	u32 t;

	ath79_wmac_device.name = "qca956x_wmac";

	ath79_wmac_resources[0].start = QCA956X_WMAC_BASE;
	ath79_wmac_resources[0].end = QCA956X_WMAC_BASE + QCA956X_WMAC_SIZE - 1;
	ath79_wmac_resources[1].start = ATH79_IP2_IRQ(1);
	ath79_wmac_resources[1].end = ATH79_IP2_IRQ(1);

	t = ath79_reset_rr(QCA956X_RESET_REG_BOOTSTRAP);
	if (t & QCA956X_BOOTSTRAP_REF_CLK_40)
		ath79_wmac_data.is_clk_25mhz = false;
	else
		ath79_wmac_data.is_clk_25mhz = true;

	ath79_wmac_data.get_mac_revision = ar93xx_get_soc_revision;
}

static void qcn550x_wmac_setup(void)
{
	u32 t;

	ath79_wmac_device.name = "qcn550x_wmac";

	ath79_wmac_resources[0].start = QCN550X_WMAC_BASE;
	ath79_wmac_resources[0].end = QCN550X_WMAC_BASE + QCN550X_WMAC_SIZE - 1;
	ath79_wmac_resources[1].start = ATH79_IP2_IRQ(1);
	ath79_wmac_resources[1].end = ATH79_IP2_IRQ(1);

	t = ath79_reset_rr(QCN550X_RESET_REG_BOOTSTRAP);
	if (t & QCN550X_BOOTSTRAP_REF_CLK_40)
		ath79_wmac_data.is_clk_25mhz = false;
	else
		ath79_wmac_data.is_clk_25mhz = true;

	ath79_wmac_data.get_mac_revision = ar93xx_get_soc_revision;
}

static bool __init
ar93xx_wmac_otp_read_word(void __iomem *base, int addr, u32 *data)
{
	int timeout = 1000;
	u32 val;

	__raw_readl(base + AR9300_OTP_BASE + (4 * addr));
	while (timeout--) {
		val = __raw_readl(base + AR9300_OTP_STATUS);
		if ((val & AR9300_OTP_STATUS_TYPE) == AR9300_OTP_STATUS_VALID)
			break;

		udelay(10);
	}

	if (!timeout)
		return false;

	*data = __raw_readl(base + AR9300_OTP_READ_DATA);
	return true;
}

static bool __init
ar93xx_wmac_otp_read(void __iomem *base, int addr, u8 *dest, int len)
{
	u32 data;
	int i;

	for (i = 0; i < len; i++) {
		int offset = 8 * ((addr - i) % 4);

		if (!ar93xx_wmac_otp_read_word(base, (addr - i) / 4, &data))
			return false;

		dest[i] = (data >> offset) & 0xff;
	}

	return true;
}

static bool __init
ar93xx_wmac_otp_uncompress(void __iomem *base, int addr, int len, u8 *dest,
			   int dest_start, int dest_len)
{
	int dest_bytes = 0;
	int offset = 0;
	int end = addr - len;
	u8 hdr[2];

	while (addr > end) {
		if (!ar93xx_wmac_otp_read(base, addr, hdr, 2))
			return false;

		addr -= 2;
		offset += hdr[0];

		if (offset <= dest_start + dest_len &&
		    offset + len >= dest_start) {
			int data_offset = 0;
			int dest_offset = 0;
			int copy_len;

			if (offset < dest_start)
				data_offset = dest_start - offset;
			else
				dest_offset = offset - dest_start;

			copy_len = len - data_offset;
			if (copy_len > dest_len - dest_offset)
				copy_len = dest_len - dest_offset;

			ar93xx_wmac_otp_read(base, addr - data_offset,
					     dest + dest_offset,
					     copy_len);

			dest_bytes += copy_len;
		}
		addr -= hdr[1];
	}
	return !!dest_bytes;
}

bool __init ar93xx_wmac_read_mac_address(u8 *dest)
{
	void __iomem *base;
	bool ret = false;
	int addr = 0x1ff;
	unsigned int len;
	u32 hdr_u32;
	u8 *hdr = (u8 *) &hdr_u32;
	u8 mac[6] = { 0x00, 0x02, 0x03, 0x04, 0x05, 0x06 };
	int mac_start = 2, mac_end = 8;

	BUG_ON(!soc_is_ar933x() && !soc_is_ar934x());
	base = ioremap_nocache(AR933X_WMAC_BASE, AR933X_WMAC_SIZE);
	while (addr > sizeof(hdr)) {
		if (!ar93xx_wmac_otp_read(base, addr, hdr, sizeof(hdr)))
			break;

		if (hdr_u32 == 0 || hdr_u32 == ~0)
			break;

		len = (hdr[1] << 4) | (hdr[2] >> 4);
		addr -= 4;

		switch (hdr[0] >> 5) {
		case 0:
			if (len < mac_end)
				break;

			ar93xx_wmac_otp_read(base, addr - mac_start, mac, 6);
			ret = true;
			break;
		case 3:
			ret |= ar93xx_wmac_otp_uncompress(base, addr, len, mac,
							  mac_start, 6);
			break;
		default:
			break;
		}

		addr -= len + 2;
	}

	iounmap(base);
	if (ret)
		memcpy(dest, mac, 6);

	return ret;
}

void __init ath79_wmac_disable_2ghz(void)
{
	ath79_wmac_data.disable_2ghz = true;
}

void __init ath79_wmac_disable_5ghz(void)
{
	ath79_wmac_data.disable_5ghz = true;
}

void __init ath79_wmac_set_tx_gain_buffalo(void)
{
	ath79_wmac_data.tx_gain_buffalo = true;
}

static int ath79_request_ext_lna_gpio(unsigned chain, int gpio)
{
	char buf[32];
	char *label;
	int err;

	scnprintf(buf, sizeof(buf), "external LNA%u", chain);
	label = kstrdup(buf, GFP_KERNEL);

	err = gpio_request_one(gpio, GPIOF_DIR_OUT | GPIOF_INIT_LOW, label);
	if (err) {
		pr_err("unable to request GPIO%d for external LNA%u\n",
			gpio, chain);
		kfree(label);
	}

	return err;
}

static void ar934x_set_ext_lna_gpio(unsigned chain, int gpio)
{
	unsigned int sel;
	int err;

	if (WARN_ON(chain > 1))
		return;

	err = ath79_request_ext_lna_gpio(chain, gpio);
	if (err)
		return;

	if (chain == 0)
		sel = AR934X_GPIO_OUT_EXT_LNA0;
	else
		sel = AR934X_GPIO_OUT_EXT_LNA1;

	ath79_gpio_output_select(gpio, sel);
}

void __init ath79_wmac_set_ext_lna_gpio(unsigned chain, int gpio)
{
	if (soc_is_ar934x())
		ar934x_set_ext_lna_gpio(chain, gpio);
}

void __init ath79_wmac_set_led_pin(int gpio)
{
	ath79_wmac_data.led_pin = gpio;
}

void __init ath79_register_wmac(u8 *cal_data, u8 *mac_addr)
{
	if (soc_is_ar913x())
		ar913x_wmac_setup();
	else if (soc_is_ar933x())
		ar933x_wmac_setup();
	else if (soc_is_ar934x())
		ar934x_wmac_setup();
	else if (soc_is_qca953x())
		qca953x_wmac_setup();
	else if (soc_is_qca955x())
		qca955x_wmac_setup();
	else if (soc_is_qca956x() || soc_is_tp9343())
		qca956x_wmac_setup();
	else if (soc_is_qcn550x())
		qcn550x_wmac_setup();
	else
		BUG();

	if (cal_data)
		memcpy(ath79_wmac_data.eeprom_data, cal_data,
		       sizeof(ath79_wmac_data.eeprom_data));

	if (mac_addr) {
		memcpy(ath79_wmac_mac, mac_addr, sizeof(ath79_wmac_mac));
		ath79_wmac_data.macaddr = ath79_wmac_mac;
	}

	platform_device_register(&ath79_wmac_device);
#ifdef ATH79_WLAN_FW_DUMP
	ath79_init_wlan_fw_dump_buffer();
#endif
}

void __init ath79_register_wmac_simple(void)
{
	ath79_register_wmac(NULL, NULL);
	ath79_wmac_data.eeprom_name = "soc_wmac.eeprom";
}
