/*
 **************************************************************************
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
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
 **************************************************************************
 */

/*
 * nss_ppe.h
 *      NSS PPE header file
 */

#include <net/sock.h>
#include "nss_tx_rx_common.h"

#define PPE_BASE_ADDR			0x3a000000
#define PPE_REG_SIZE			0x1000000

#define PPE_L3_DBG_WR_OFFSET		0x200c04
#define PPE_L3_DBG_RD_OFFSET		0x200c0c
#define PPE_L3_DBG0_OFFSET		0x10001
#define PPE_L3_DBG1_OFFSET		0x10002
#define PPE_L3_DBG2_OFFSET		0x10003
#define PPE_L3_DBG3_OFFSET		0x10004
#define PPE_L3_DBG4_OFFSET		0x10005
#define PPE_L3_DBG_PORT_OFFSET		0x11e80

#define PPE_PKT_CODE_WR_OFFSET		0x100080
#define PPE_PKT_CODE_RD_OFFSET		0x100084
#define PPE_PKT_CODE_DROP0_OFFSET	0xf000000
#define PPE_PKT_CODE_DROP1_OFFSET	0x10000000
#define PPE_PKT_CODE_CPU_OFFSET		0x40000000

#define PPE_PKT_CODE_DROP0_GET(x)	(((x) & 0xe0000000) >> 29)
#define PPE_PKT_CODE_DROP1_GET(x)	(((x) & 0x7) << 3)
#define PPE_PKT_CODE_DROP_GET(d0, d1)	(PPE_PKT_CODE_DROP0_GET(d0) | PPE_PKT_CODE_DROP1_GET(d1))

#define PPE_PKT_CODE_CPU_GET(x)		(((x) >> 3) & 0xff)

#define PPE_IPE_PC_REG 0x100000

/*
 * NSS_SYS_REG_DROP_CPU_CNT_TBL
 * 	Address map and access APIs for DROP_CPU_CNT table.
 */
#define PPE_DROP_CPU_CNT_TBL_OFFSET 0x60000
#define PPE_DROP_CPU_CNT_TBL_ENTRY_SIZE 0x10
#define PPE_DROP_CPU_CNT_TBL_BASE_OFFSET (PPE_IPE_PC_REG + PPE_DROP_CPU_CNT_TBL_OFFSET)
#define PPE_CPU_CODE_MAX_NUM 256

/*
 * CPU code offset
 */
#define PPE_CPU_CODE_OFFSET(n) (PPE_DROP_CPU_CNT_TBL_BASE_OFFSET + ((n) * PPE_DROP_CPU_CNT_TBL_ENTRY_SIZE))

/*
 * DROP code offset
 */
#define PPE_DROP_CODE_IDX(code, src_port) (PPE_CPU_CODE_MAX_NUM + (8 * (code)) + (src_port))
#define PPE_DROP_CODE_OFFSET(code, src_port) (PPE_DROP_CPU_CNT_TBL_BASE_OFFSET + ((PPE_DROP_CODE_IDX(code, src_port)) * PPE_DROP_CPU_CNT_TBL_ENTRY_SIZE))

#define NSS_PPE_TX_TIMEOUT 1000 /* 1 Second */

/*
 * ppe nss debug stats lock
 */
extern spinlock_t nss_ppe_stats_lock;

/*
 * Private data structure
 */
struct nss_ppe_pvt {
	void * __iomem ppe_base;
	struct semaphore sem;
	struct completion complete;
	int response;
	void *cb;
	void *app_data;
};

/*
 * Data structure to store to PPE private context
 */
extern struct nss_ppe_pvt ppe_pvt;

/*
 * nss_ppe_reg_read()
 */
static inline void nss_ppe_reg_read(u32 reg, u32 *val)
{
	*val = readl((ppe_pvt.ppe_base + reg));
}

/*
 * nss_ppe_reg_write()
 */
static inline void nss_ppe_reg_write(u32 reg, u32 val)
{
	writel(val, (ppe_pvt.ppe_base + reg));
}
