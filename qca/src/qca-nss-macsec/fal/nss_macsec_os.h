/*
 * Copyright (c) 2014, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __MACSEC_OS_H__
#define __MACSEC_OS_H__

/* Register access */

	/* 32 bits */

#define read_register32(addr)         readl(io_mapped_addr+addr)
#define write_register32(value,addr)  writel(value,(io_mapped_addr+addr))

	/* 16 bits */
#define read_register16(addr)         readw(io_mapped_addr+(addr<<2))
#define write_register16(value,addr)  writew(value,(io_mapped_addr+(addr<<2)))

	/* 8 bits */
#define read_register8(addr)          readb(io_mapped_addr+(addr<<2))
#define write_register8(value,addr)   writeb(value,(io_mapped_addr+(addr<<2)))

#include <asm/io.h>
#include <linux/delay.h>

/* Debug level macros */
#ifdef MACSEC_DEBUG

#define macsec_trace(fmt, ...)			printk(fmt, ##__VA_ARGS__)
#define macsec_info(fmt, ...)			printk(KERN_INFO fmt, ##__VA_ARGS__)
#define macsec_warning(fmt, ...)		printk(KERN_WARNING fmt, ##__VA_ARGS__)

#define macsec_assert(x, fmt, ...) \
{ \
	if (!(x)) { \
		printk(KERN_ERR "%s:%d " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
		BUG(); \
	} \
}

#else // PCI_DEBUG

#define macsec_trace(fmt, ...)
#define macsec_info(fmt, ...)		printk(fmt, ##__VA_ARGS__)
#define macsec_warning(fmt, ...)
#define macsec_asser(x, fmt, ...)

#endif // MACSEC_DEBUG

/**
 * @brief Events from the NSS GMAC
 */
#define NSS_GMAC_SPEED_SET		0x0001

/**
 * @brief GMAC speed context
 */
struct nss_gmac_speed_ctx {
	uint32_t mac_id;
	uint32_t speed;
};

extern void nss_macsec_pre_init(void);
extern void nss_macsec_pre_exit(void);
extern void nss_macsec_bypass_en_set(uint32_t gmac_id, bool enable);
extern void nss_gmac_link_state_change_notify_register(struct notifier_block *nb);
extern void nss_gmac_link_state_change_notify_unregister(struct notifier_block *nb);

unsigned int nss_macsec_device_exist(unsigned int dev_id);
#endif /* End of file */
