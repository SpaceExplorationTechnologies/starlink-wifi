/* Copyright (c) 2016, The Linux Foundation. All rights reserved.
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

#ifndef _ATH79_WLAN_H_
#define _ATH79_WLAN_H

#define ATH79_WLAN_FW_DUMP

#ifdef ATH79_WLAN_FW_DUMP
#include <linux/export.h>
#define ATH79_FW_DUMP_MEM_SIZE          ((2*1024*1024))

int ath79_get_wlan_fw_dump_buffer(void **dump_buff, u32 *buff_size);
void ath79_init_wlan_fw_dump_buffer(void);
#endif /* ATH79_WLAN_FW_DUMP */

#endif /* _ATH79_WLAN_H_ */
