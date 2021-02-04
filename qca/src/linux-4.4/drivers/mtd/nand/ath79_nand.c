/*
 * Qualcomm Atheros AR71XX/AR724X/AR913X NAND controller driver
 *
 * Copyright (c) 2012 The Linux Foundation. All rights reserved.
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
 */

#include <linux/module.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/ioport.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/dma-mapping.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/bitops.h>
#include <linux/jiffies.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/nand.h>
#include <linux/mtd/nand_ecc.h>
#include <linux/mtd/partitions.h>
#include <asm/mach-ath79/ar71xx_regs.h>

/* module related macros */
#define DRV_NAME	"ath79-nand"
#define DRV_VERSION	"1.0"

/* misc macros */
#define AR934X_NAND_STATUS_RETRY	1000
#define DDR_WB_FLUSH_USB_ADDRESS	0x180000a4

/* static data for ath79_nand driver configuration */
static const char *ath79_nand_part_probes[] __initdata = { "cmdlinepart",
							"RedBoot",
							NULL };

static struct mtd_partition ath79_nand_partitions[] = {
	{
	 .name = "nand0",
	 .offset = 0,
	 .size = MTDPART_SIZ_FULL,
	 },
};

static struct nand_ecclayout ath79_nand_oob_64 = {
	.eccbytes = 28,
	.eccpos = {
		   20, 21, 22, 23, 24, 25, 26, 27,
		   28, 29, 30, 31, 32, 33, 34, 35,
		   36, 37, 38, 39, 40, 41, 42, 43,
		   44, 45, 46, 47},
	.oobfree = {
		    {.offset = 4,
		     .length = 16},
		    {.offset = 48,
		     .length = 16}
		    }
};

typedef struct {
	uint8_t		vid,
				did,
				b3,
				addrcyc,
				small,
				spare;	/* for small block */
	uint16_t	pgsz;	/* for small block */
	uint32_t	blk;	/* for small block */
} ath_nand_vend_data_t;

ath_nand_vend_data_t ath_nand_arr[] = {
	{ 0x20, 0xda, 0x10, 5, },	/* NU2g3B2D */
	{ 0x20, 0xf1, 0x00, 4, },	/* NU1g3B2C */
	{ 0x20, 0xdc, 0x10, 5, },	/* NU4g3B2D */
	{ 0x20, 0xd3, 0x10, 5, },	/* NU8g3F2A */
	{ 0x20, 0xd3, 0x14, 5, },	/* NU8g3C2B */
	{ 0xad, 0xf1, 0x00, 4, },	/* HY1g2b */
	{ 0xad, 0xda, 0x10, 5, },	/* HY2g2b */
	{ 0xec, 0xf1, 0x00, 4, },	/* Samsung 3,3V 8-bit [128MB] */
	{ 0x98, 0xd1, 0x90, 4, },	/* Toshiba */
	{ 0xad, 0x76, 0xad, 5, 1, 16, 512, 16 << 10 },	/* Hynix 64MB NAND Flash */
	{ 0xad, 0x36, 0xad, 5, 1, 16, 512, 16 << 10 },	/* Hynix 64MB NAND Flash */
	{ 0x20, 0x76, 0x20, 5, 1, 16, 512, 16 << 10 },	/* ST Micro 64MB NAND Flash */
};

#define NUM_ARRAY_ENTRIES(a)	(sizeof((a)) / sizeof((a)[0]))
#define NUM_ATH_NAND		NUM_ARRAY_ENTRIES(ath_nand_arr)

/* ath nand controller DMA descriptor */
typedef struct {
	uint32_t addr;
	uint32_t len;
} ath79_nand_dma_descr;

/* ath nand priv info */
typedef struct {
	struct nand_chip nand;
	uint32_t nf_ctrl;
	uint32_t command;
	uint32_t curr_data;
	uint32_t data_index;
	uint8_t *page_buf;
	void __iomem *io_base;
	void __iomem *ddr_io_addr;
	ath79_nand_dma_descr *dma_descr_virtaddr;
	dma_addr_t dma_descr_phyaddr;
	struct device *dev;
} ath79_nand_priv;

/****************************************/
/***** NAND chip internal functions *****/
/****************************************/
static int ath79_rw_oob(struct mtd_info *mtd, struct nand_chip *chip, int rw,
			int page);

static inline int ath79_oobbuf_is_dirty(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;
	uint8_t *p = chip->oob_poi;
	int i;

	for (i = 0; i < mtd->oobsize; i++) {
		if (p[i] != 0xff)
			return 1;
	}

	return 0;
}

static int ath79_page_no_ecc(struct mtd_info *mtd, int page)
{
	struct nand_chip *chip = mtd->priv;
	uint8_t *p = chip->oob_poi;
	int i;

	ath79_rw_oob(mtd, chip, 1 /*read */, page);

	for (i = 0; i < mtd->ecclayout->eccbytes; i++) {
		if (p[mtd->ecclayout->eccpos[i]] != 0xff)
			return 0;
	}

	return 1;
}

static int ath79_nand_hw_init(ath79_nand_priv *ath79_priv)
{
	unsigned rddata;
	void __iomem *tmp_io_addr;

	/* Put into reset */
	tmp_io_addr =
	    ioremap(AR71XX_RESET_BASE + AR934X_RESET_REG_RESET_MODULE, 4);
	if (tmp_io_addr == NULL)
		return EIO;
	rddata = ioread32(tmp_io_addr);
	iowrite32(rddata | AR934X_RESET_NANDF, tmp_io_addr);
	udelay(250);

	iowrite32(rddata & (~AR934X_RESET_NANDF), tmp_io_addr);
	udelay(100);

	iounmap(tmp_io_addr);

	iowrite32(AR934X_NAND_CMD_END_INT,
		  ath79_priv->io_base + AR934X_NAND_REG_INT_MASK);
	iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_INT_STATUS);

	/* TIMINGS_ASYN Reg Settings */
	iowrite32(AR934X_NAND_TIMING_ASYN_SETTING,
		  ath79_priv->io_base + AR934X_NAND_REG_TIMINGS_ASYN);
	iowrite32(AR934X_NAND_TIME_SEQ_SETTING,
		  ath79_priv->io_base + AR934X_NAND_REG_TIME_SEQ);

	/* NAND Mem Control Reg */
	iowrite32(0xff00, ath79_priv->io_base + AR934X_NAND_REG_MEM_CTRL);

	return 0;
}

static int ath79_rw_oob(struct mtd_info *mtd, struct nand_chip *chip, int rw,
			int page)
{
	ath79_nand_priv *ath79_priv = mtd->priv;
	int i, dmastatus, status = 0;
	int dir, dma_ctrl;
	dma_addr_t pa;

	dir = rw ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
	pa = dma_map_single(NULL, chip->oob_poi, mtd->oobsize, dir);

	iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_INT_STATUS);
	iowrite32((page << 16) | mtd->writesize,
		  ath79_priv->io_base + AR934X_NAND_REG_ADDR0_0);
	iowrite32((page >> 16) & 0x0ff,
		  ath79_priv->io_base + AR934X_NAND_REG_ADDR0_1);
	iowrite32(pa, ath79_priv->io_base + AR934X_NAND_REG_DMA_ADDR);
	iowrite32(mtd->oobsize,
		  ath79_priv->io_base + AR934X_NAND_REG_DMA_COUNT);

	iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_ECC_OFFSET);
	iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_ECC_CTRL);
	iowrite32(ath79_priv->nf_ctrl | AR934X_NAND_CTRL_CUSTOM_SIZE_EN,
		  ath79_priv->io_base + AR934X_NAND_REG_CTRL);
	iowrite32(mtd->oobsize, ath79_priv->io_base + AR934X_NAND_REG_PG_SIZE);

	dma_ctrl =
	    AR934X_NAND_DMA_CTRL_DMA_START | AR934X_NAND_DMA_CTRL_DMA_BURST_3;

	if (rw) {		/* read OOB */
		iowrite32(dma_ctrl | AR934X_NAND_DMA_CTRL_DMA_DIR_READ,
			  ath79_priv->io_base + AR934X_NAND_REG_DMA_CTRL);
		iowrite32(0x30006a,
			  ath79_priv->io_base + AR934X_NAND_REG_COMMAND);
		ath79_priv->data_index = 0;
	} else {		/* write OOB */
		iowrite32(0xff00, ath79_priv->io_base + AR934X_NAND_REG_MEM_CTRL);	/* Remove write protect */
		iowrite32(dma_ctrl | AR934X_NAND_DMA_CTRL_DMA_DIR_WRITE,
			  ath79_priv->io_base + AR934X_NAND_REG_DMA_CTRL);
		iowrite32(0x10804c,
			  ath79_priv->io_base + AR934X_NAND_REG_COMMAND);
	}

	while ((ioread32(ath79_priv->io_base + AR934X_NAND_REG_INT_STATUS) &
		AR934X_NAND_CMD_END_INT) == 0);

	status = ioread32(ath79_priv->io_base + AR934X_NAND_REG_STATUS);
	for (i = 0; i < AR934X_NAND_STATUS_RETRY && status != 0xff; i++) {
		udelay(2);
		status = ioread32(ath79_priv->io_base + AR934X_NAND_REG_STATUS);
	}
	if (status != 0xff) {
		dev_err(ath79_priv->dev,
			"%s: NAND status error. Status = 0x%x\n", __func__,
			status);
		status = -EIO;
	} else {
		status = 0;
	}

	if (rw) {
		nand_wait_ready(mtd);	/* wait for ready pin for read OOB */
	} else {
		status = chip->waitfunc(mtd, chip);	/* check device status for write OOB */
		if (status & NAND_STATUS_FAIL) {
			dev_err(ath79_priv->dev,
				"%s: Write Failed. status = 0x%x\n", __func__,
				status);
			status = -EIO;
		} else {
			status = 0;
		}
	}

	dmastatus = ioread32(ath79_priv->io_base + AR934X_NAND_REG_DMA_CTRL);
	for (i = 0; i < AR934X_NAND_STATUS_RETRY && !(dmastatus & 1); i++) {
		udelay(5);
		dmastatus =
		    ioread32(ath79_priv->io_base + AR934X_NAND_REG_DMA_CTRL);
	}
	if (!(dmastatus & 1)) {
		dev_err(ath79_priv->dev, "%s: unfinished DMA. status = 0x%x\n",
			__func__, dmastatus);
		if (ath79_nand_hw_init(ath79_priv)) {
			status = -EIO;
		}
		/* is this for killing unfinished DMA ??? */
		iowrite32(1, ath79_priv->ddr_io_addr);
		while (ioread32(ath79_priv->ddr_io_addr) & 1);
		udelay(2);
	}

	dma_unmap_single(NULL, pa, mtd->oobsize, dir);

	iowrite32(1, ath79_priv->io_base + AR934X_NAND_REG_FIFO_INIT);
	iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_FIFO_INIT);

	return status;
}

static int ath79_rw_page(struct mtd_info *mtd, struct nand_chip *chip, int rw,
			 uint8_t *buf, int len, int page)
{
	ath79_nand_priv *ath79_priv = mtd->priv;
	int status = 0;
	int i, dir, dmastatus, ecc_enable, ecc_status;
	int dma_ctrl, copy = 0;
	dma_addr_t pa1, pa2 = 0;

	dir = rw ? DMA_FROM_DEVICE : DMA_TO_DEVICE;

	iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_INT_STATUS);
	iowrite32(page << 16, ath79_priv->io_base + AR934X_NAND_REG_ADDR0_0);
	iowrite32((page >> 16) & 0x0ff,
		  ath79_priv->io_base + AR934X_NAND_REG_ADDR0_1);
	iowrite32(len, ath79_priv->io_base + AR934X_NAND_REG_DMA_COUNT);

	dma_ctrl =
	    AR934X_NAND_DMA_CTRL_DMA_START | AR934X_NAND_DMA_CTRL_DMA_BURST_3;

	if (is_vmalloc_addr(buf)) {
		if (!rw)
			memcpy(ath79_priv->page_buf, buf, mtd->writesize);
		pa1 =
		    dma_map_single(NULL, ath79_priv->page_buf, mtd->writesize,
				   dir);
		copy = 1;
	} else {
		pa1 = dma_map_single(NULL, buf, mtd->writesize, dir);
	}

	if (!rw)
		dev_dbg(ath79_priv->dev,
			"%s: read %d, page 0x%x, size=0x%x, virt buffer %d\n",
			__func__, rw, page, len, copy);

	if ((len & mtd->writesize_mask) == 0) {
		/* non-scatter-gather DMA mode */
		iowrite32(pa1, ath79_priv->io_base + AR934X_NAND_REG_DMA_ADDR);
		iowrite32(mtd->writesize + chip->ecc.layout->eccpos[0],
			  ath79_priv->io_base + AR934X_NAND_REG_ECC_OFFSET);
		iowrite32(AR934X_NAND_ECC_CORR_BITS(4),
			  ath79_priv->io_base + AR934X_NAND_REG_ECC_CTRL);
		iowrite32(ath79_priv->nf_ctrl | AR934X_NAND_CTRL_ECC_EN,
			  ath79_priv->io_base + AR934X_NAND_REG_CTRL);
		ecc_enable = 1;
	} else {
		/* scatter-gather DMA mode */
		ath79_priv->dma_descr_virtaddr[0].addr = pa1;
		ath79_priv->dma_descr_virtaddr[0].len = mtd->writesize << 16;
		pa2 =
		    dma_map_single(NULL, chip->oob_poi, len - mtd->writesize,
				   dir);
		ath79_priv->dma_descr_virtaddr[1].addr = pa2;
		ath79_priv->dma_descr_virtaddr[1].len =
		    ((len - mtd->writesize) << 16) | 0x01;
		iowrite32(ath79_priv->dma_descr_phyaddr,
			  ath79_priv->io_base + AR934X_NAND_REG_DMA_ADDR);
		iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_ECC_OFFSET);
		iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_ECC_CTRL);
		iowrite32(ath79_priv->nf_ctrl | AR934X_NAND_CTRL_CUSTOM_SIZE_EN,
			  ath79_priv->io_base + AR934X_NAND_REG_CTRL);
		iowrite32(len, ath79_priv->io_base + AR934X_NAND_REG_PG_SIZE);
		dma_ctrl |= AR934X_NAND_DMA_CTRL_DMA_MODE_SG;
		ecc_enable = 0;
	}

	if (rw) {		/* read page */
		iowrite32(dma_ctrl | AR934X_NAND_DMA_CTRL_DMA_DIR_READ,
			  ath79_priv->io_base + AR934X_NAND_REG_DMA_CTRL);
		iowrite32(0x30006a,
			  ath79_priv->io_base + AR934X_NAND_REG_COMMAND);
		ath79_priv->data_index = 0;
	} else {		/* write page */
		iowrite32(0xff00, ath79_priv->io_base + AR934X_NAND_REG_MEM_CTRL);	/* Remove write protect */
		iowrite32(dma_ctrl | AR934X_NAND_DMA_CTRL_DMA_DIR_WRITE,
			  ath79_priv->io_base + AR934X_NAND_REG_DMA_CTRL);
		iowrite32(0x10804c,
			  ath79_priv->io_base + AR934X_NAND_REG_COMMAND);
	}

	while ((ioread32(ath79_priv->io_base + AR934X_NAND_REG_INT_STATUS) &
		AR934X_NAND_CMD_END_INT) == 0) ;

	status = ioread32(ath79_priv->io_base + AR934X_NAND_REG_STATUS);
	for (i = 0; i < AR934X_NAND_STATUS_RETRY && status != 0xff; i++) {
		udelay(2);
		status = ioread32(ath79_priv->io_base + AR934X_NAND_REG_STATUS);
	}
	if (status != 0xff) {
		dev_err(ath79_priv->dev,
			"%s: NAND status error. Status = 0x%x\n", __func__,
			status);
		status = -EIO;
	} else {
		status = 0;
	}

	if (rw) {
		nand_wait_ready(mtd);	/* wait for ready pin for read transaction */
	} else {
		status = chip->waitfunc(mtd, chip);	/* check device status for write transaction */
		if (status & NAND_STATUS_FAIL) {
			dev_err(ath79_priv->dev,
				"%s: Write Failed. status = 0x%x\n", __func__,
				status);
			status = -EIO;
		} else {
			status = 0;
		}
	}

	dmastatus = ioread32(ath79_priv->io_base + AR934X_NAND_REG_DMA_CTRL);
	for (i = 0; i < AR934X_NAND_STATUS_RETRY && !(dmastatus & 1); i++) {
		udelay(5);
		dmastatus =
		    ioread32(ath79_priv->io_base + AR934X_NAND_REG_DMA_CTRL);
	}
	if (!(dmastatus & 1)) {
		dev_err(ath79_priv->dev, "%s: unfinished DMA. status = 0x%x\n",
			__func__, dmastatus);
		if (ath79_nand_hw_init(ath79_priv)) {
			status = -EIO;
		}
		/* is this for killing unfinished DMA ??? */
		iowrite32(1, ath79_priv->ddr_io_addr);
		while (ioread32(ath79_priv->ddr_io_addr) & 1) ;
		udelay(2);
	}

	if (rw && ecc_enable) {
		ecc_status =
		    ioread32(ath79_priv->io_base + AR934X_NAND_REG_ECC_CTRL);
		if (ecc_status & AR934X_NAND_ECC_ERROR) {
			if (!ath79_page_no_ecc(mtd, page)) {
				dev_err(ath79_priv->dev,
					"%s: Read [%d @ 0x%x] uncorrectable errors. status = 0x%x\n",
					__func__, len, page, ecc_status);
				mtd->ecc_stats.failed++;
			}
		} else if (ecc_status & AR934X_NAND_ECC_CTRL_ERR_CORR) {
			mtd->ecc_stats.corrected++;
		}
	}

	if (ecc_enable)
		dma_unmap_single(NULL, pa1, len, dir);
	else {
		dma_unmap_single(NULL, pa1, mtd->writesize, dir);
		dma_unmap_single(NULL, pa2, len - mtd->writesize, dir);
	}

	if (rw && copy)		/* read page */
		memcpy(buf, ath79_priv->page_buf, mtd->writesize);

	iowrite32(1, ath79_priv->io_base + AR934X_NAND_REG_FIFO_INIT);
	iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_FIFO_INIT);

	return status;
}

/****************************************/
/***** NAND chip private APIs ***********/
/****************************************/

static void ath79_cmdfunc(struct mtd_info *mtd, unsigned int command,
			  int column, int page_addr)
{
	ath79_nand_priv *ath79_priv = mtd->priv;
	int i, status;

	ath79_priv->command = command;

	switch (command) {

	case NAND_CMD_STATUS:

		iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_INT_STATUS);
		iowrite32(0,
			  ath79_priv->io_base +
			  AR934X_NAND_REG_GENERIC_SEQ_CTRL);
		iowrite32(0x07024, ath79_priv->io_base + AR934X_NAND_REG_COMMAND);	/* READ STATUS */
		while ((ioread32
			(ath79_priv->io_base +
			 AR934X_NAND_REG_INT_STATUS) & AR934X_NAND_CMD_END_INT)
		       == 0) ;
		break;

	case NAND_CMD_READID:

		iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_INT_STATUS);
		iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_ADDR0_0);
		iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_ADDR0_1);
		iowrite32(0x4, ath79_priv->io_base + AR934X_NAND_REG_PG_SIZE);
		iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_DMA_CTRL);	/* disable DMA */
		iowrite32(ath79_priv->nf_ctrl | AR934X_NAND_CTRL_CUSTOM_SIZE_EN,
			  ath79_priv->io_base + AR934X_NAND_REG_CTRL);
		iowrite32(0x9021, ath79_priv->io_base + AR934X_NAND_REG_COMMAND);	/* READ ID */
		while ((ioread32
			(ath79_priv->io_base +
			 AR934X_NAND_REG_INT_STATUS) & AR934X_NAND_CMD_END_INT)
		       == 0);
		udelay(10);
		break;

	case NAND_CMD_RESET:

		dev_dbg(ath79_priv->dev, "NAND %s: Reset\n", __func__);

		iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_INT_STATUS);
		iowrite32(0xff00, ath79_priv->io_base + AR934X_NAND_REG_COMMAND);	/* RESET */
		while ((ioread32
			(ath79_priv->io_base +
			 AR934X_NAND_REG_INT_STATUS) & AR934X_NAND_CMD_END_INT)
		       == 0);
		udelay(1000);
		status = ioread32(ath79_priv->io_base + AR934X_NAND_REG_STATUS);
		for (i = 0; i < AR934X_NAND_STATUS_RETRY && status != 0xff; i++) {
			udelay(2);
			status =
			    ioread32(ath79_priv->io_base +
				     AR934X_NAND_REG_STATUS);
		}
		break;

	default:
		break;
	}

	ath79_priv->data_index = 0;

	return;
}

static void ath79_null(struct mtd_info *mtd)
{
	return;
}

static int ath79_device_ready(struct mtd_info *mtd)
{
	ath79_nand_priv *ath79_priv = mtd->priv;
	int rddata;

	rddata = ioread32(ath79_priv->io_base + AR934X_NAND_REG_STATUS);

	return ((rddata == 0xff) ? 1 : 0);
}

static void ath79_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
	ath79_nand_priv *ath79_priv = mtd->priv;
	volatile int rddata, i;
	volatile uint8_t *p = (volatile uint8_t *)&rddata;

	for (i = 0; i < len; i++) {
		if (((ath79_priv->data_index + i) % 4) == 0) {
			rddata =
			    le32_to_cpu(ioread32
					(ath79_priv->io_base +
					 AR934X_NAND_REG_FIFO_DATA));
			if (ath79_priv->command == NAND_CMD_READID)
				dev_dbg(ath79_priv->dev, "NAND %s: ReadID %x\n",
					__func__, rddata);
			ath79_priv->curr_data = rddata;
		} else {
			rddata = ath79_priv->curr_data;
		}
		buf[i] = p[(ath79_priv->data_index + i) % 4];
		ath79_priv->data_index++;
	}
}

static uint8_t ath79_read_byte(struct mtd_info *mtd)
{
	ath79_nand_priv *ath79_priv = mtd->priv;
	uint8_t rdbyte;

	if (ath79_priv->command == NAND_CMD_STATUS) {
		rdbyte =
		    ioread32(ath79_priv->io_base + AR934X_NAND_REG_RD_STATUS);
		dev_dbg(ath79_priv->dev, "NAND: Read Status 0x%x\n", rdbyte);
	} else {
		ath79_read_buf(mtd, &rdbyte, 1);
	}

	return rdbyte;
}

static int ath79_block_bad(struct mtd_info *mtd, loff_t ofs, int getchip)
{
	struct nand_chip *chip = mtd->priv;
	uint8_t *p = chip->oob_poi;

	ath79_rw_oob(mtd, chip, 1 /*read */, ofs >> chip->page_shift);

	if (*p == 0xff)
		return 0;
	else
		return 1;
}

static int ath79_read_oob(struct mtd_info *mtd, struct nand_chip *chip,
			  int page, int sndcmd)
{
	ath79_rw_oob(mtd, chip, 1 /*read */, page);

	return sndcmd;
}

static int ath79_write_oob(struct mtd_info *mtd, struct nand_chip *chip,
			   int page)
{
	return ath79_rw_oob(mtd, chip, 0 /*write */, page);
}

static int ath79_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
			       uint8_t *buf, int page)
{
	return ath79_rw_page(mtd, chip, 1 /*read */, buf,
			     mtd->writesize + mtd->oobsize, page);
}

static int ath79_read_page(struct mtd_info *mtd, struct nand_chip *chip,
			   uint8_t *buf, int page)
{
	return ath79_rw_page(mtd, chip, 1 /*read */, buf, mtd->writesize,
			     page);
}

static int ath79_write_page(struct mtd_info *mtd, struct nand_chip *chip,
			    const uint8_t *buf, int page, int cached, int raw)
{
	int status;

	if (unlikely(raw))
		ath79_rw_page(mtd, chip, 0 /*write */, (uint8_t *) buf,
			      mtd->writesize + mtd->oobsize, page);
	else {
		if (ath79_oobbuf_is_dirty(mtd))
			ath79_rw_oob(mtd, chip, 0 /*write */, page);
		ath79_rw_page(mtd, chip, 0 /*write */, (uint8_t *) buf,
			      mtd->writesize, page);
	}

	status = chip->waitfunc(mtd, chip);
	if (status & NAND_STATUS_FAIL)
		return -EIO;

#ifdef CONFIG_MTD_NAND_VERIFY_WRITE
	memset(ath79_priv->page_buf, 0, mtd->writesize);
	ath79_rw_page(mtd, chip, 1 /*read */, ath79_priv->page_buf,
		      mtd->writesize, page)
	    if (memcmp(page, ath79_priv->page_buf, mtd->writesize))
		return -EIO;
#endif
	return 0;
}

static void ath79_erase_cmd(struct mtd_info *mtd, int page)
{
	ath79_nand_priv *ath79_priv = mtd->priv;

	dev_dbg(ath79_priv->dev, "%s: page 0x%x\n", __func__, page);

	iowrite32(0, ath79_priv->io_base + AR934X_NAND_REG_INT_STATUS);
	iowrite32(page << 16, ath79_priv->io_base + AR934X_NAND_REG_ADDR0_0);
	iowrite32((page >> 16) & 0x0ff,
		  ath79_priv->io_base + AR934X_NAND_REG_ADDR0_1);
	iowrite32(0xff00, ath79_priv->io_base + AR934X_NAND_REG_MEM_CTRL);
	iowrite32(ath79_priv->nf_ctrl,
		  ath79_priv->io_base + AR934X_NAND_REG_CTRL);
	iowrite32(0xd0600e, ath79_priv->io_base + AR934X_NAND_REG_COMMAND);	/* block erase */

	while ((ioread32(ath79_priv->io_base + AR934X_NAND_REG_INT_STATUS) &
		AR934X_NAND_CMD_END_INT) == 0) ;

	return;
}

static ath_nand_vend_data_t *
ath79_get_entry(int  *nand_id, ath_nand_vend_data_t *tbl, int count)
{
	int     i;

	for (i = 0; i < count; i++, tbl++) {
		if ((nand_id[0] == tbl->vid) &&
		    (nand_id[1] == tbl->did)) {
			return tbl;
		}
	}
	return NULL;
}

/****************************/
/****** ath79_nand_remove *****/
/****************************/
static int ath79_nand_remove(struct platform_device *pdev)
{
	ath79_nand_priv *ath79_priv;
	struct mtd_info *mtd;

	mtd = (struct mtd_info *)platform_get_drvdata(pdev);
	if (!mtd)
		return 0;

	ath79_priv = mtd->priv;
	nand_release(mtd);
	mtd_device_unregister(mtd);
	dma_free_coherent(NULL, AR934X_NAND_DMA_DESCR_SIZE * 2,
			  (void *)(ath79_priv->dma_descr_virtaddr),
			  ath79_priv->dma_descr_phyaddr);
	iounmap(ath79_priv->io_base);
	iounmap(ath79_priv->ddr_io_addr);
	kfree(ath79_priv->page_buf);
	kfree(mtd);
	platform_set_drvdata(pdev, NULL);

	return 0;
}

/***************************/
/****** ath79_nand_probe *****/
/***************************/
static int ath79_nand_probe(struct platform_device *pdev)
{
	struct resource *res;
	struct mtd_info *mtd = NULL;
	ath79_nand_priv *ath79_priv = NULL;
	ath_nand_vend_data_t *entry = NULL;
	int nandid[2];
	int err = 0;

	mtd = kzalloc(sizeof(*mtd) + sizeof(ath79_nand_priv), GFP_KERNEL);
	if (!mtd) {
		dev_err(&pdev->dev, "no memory for flash driver\n");
		err = -ENOMEM;
		goto out_err_kzalloc;
	}

	ath79_priv = (ath79_nand_priv *) (&mtd[1]);
	mtd->priv = ath79_priv;
	mtd->name = DRV_NAME;
	mtd->owner = THIS_MODULE;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(&pdev->dev, "resource missing\n");
		err = -EINVAL;
		goto out_err_ioremap1;
	}

	ath79_priv->dev = &(pdev->dev);

	ath79_priv->io_base = ioremap(res->start, resource_size(res));
	if (ath79_priv->io_base == NULL) {
		dev_err(&pdev->dev, "ioremap error\n");
		err = -EIO;
		goto out_err_ioremap1;
	}

	ath79_priv->ddr_io_addr = ioremap(DDR_WB_FLUSH_USB_ADDRESS, 4);
	if (ath79_priv->ddr_io_addr == NULL) {
		dev_err(&pdev->dev, "ioremap error\n");
		err = -EIO;
		goto out_err_ioremap2;
	}

	ath79_priv->dma_descr_virtaddr =
	    (void *)dma_alloc_coherent(NULL, sizeof(ath79_nand_dma_descr) * 2,
				       &(ath79_priv->dma_descr_phyaddr),
				       GFP_KERNEL);
	if (ath79_priv->dma_descr_virtaddr == NULL) {
		dev_err(&pdev->dev, "dma coherent memory alloc error\n");
		err = -ENOMEM;
		goto out_err_dma_alloc_coherent;
	}

	/* ath79_nand chip private functions */
	ath79_priv->nand.cmdfunc = ath79_cmdfunc;
	ath79_priv->nand.select_chip = (void *)ath79_null;
	ath79_priv->nand.dev_ready = ath79_device_ready;
	ath79_priv->nand.read_byte = ath79_read_byte;
	ath79_priv->nand.read_buf = ath79_read_buf;
	ath79_priv->nand.block_bad = ath79_block_bad;

	/* enable flash based bad block table */
	ath79_priv->nand.bbt_options =
	    NAND_BBT_USE_FLASH | NAND_BBT_NO_OOB | NAND_BBT_SCAN2NDPAGE;

	/* initialise the NAND controller hardware */
	if (ath79_nand_hw_init(ath79_priv)) {
		dev_err(&pdev->dev, "nand hardware init error\n");
		err = -EIO;
		goto out_err_hw_init;
	}

	err = nand_scan_ident(mtd, 1, NULL);
	if (err) {
		dev_err(&pdev->dev, "nand scan identify error\n");
		err = -ENXIO;
		goto out_err_hw_init;
	}

	ath79_priv->page_buf = kzalloc(mtd->writesize, GFP_KERNEL);
	if (!ath79_priv->page_buf) {
		dev_err(&pdev->dev, "page buffer alloc error\n");
		err = -ENOMEM;
		goto out_err_hw_init;
	}

	/* Send the command for reading device ID */
	ath79_priv->nand.cmdfunc(mtd, NAND_CMD_READID, 0x00, -1);
	/* Read manufacturer and device IDs */
	nandid[0] = ath79_priv->nand.read_byte(mtd);
	nandid[1] = ath79_priv->nand.read_byte(mtd);
	entry = ath79_get_entry(nandid, ath_nand_arr, NUM_ATH_NAND);
	if (entry) {
		ath79_priv->nf_ctrl = AR934X_NAND_CTRL_ADDR_CYCLE0(entry->addrcyc);
	} else
		ath79_priv->nf_ctrl = AR934X_NAND_CTRL_ADDR_CYCLE0(4);

	/* set nand controller page size */
	switch (mtd->writesize) {
	case 256:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_PAGE_SIZE_256;
		break;
	case 512:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_PAGE_SIZE_512;
		break;
	case 1024:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_PAGE_SIZE_1024;
		break;
	case 2048:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_PAGE_SIZE_2048;
		break;
	case 4096:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_PAGE_SIZE_4096;
		break;
	case 8192:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_PAGE_SIZE_8192;
		break;
	default:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_PAGE_SIZE_2048;
		break;
	}
	/* set nand controller block size */
	switch (mtd->erasesize / mtd->writesize) {
	case 32:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_BLOCK_SIZE_32;
		break;
	case 64:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_BLOCK_SIZE_64;
		break;
	case 128:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_BLOCK_SIZE_128;
		break;
	case 256:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_BLOCK_SIZE_256;
		break;
	default:
		ath79_priv->nf_ctrl |= AR934X_NAND_CTRL_BLOCK_SIZE_64;
		break;
	}

	/* ath79_nand chip private ECC functions */
	ath79_priv->nand.ecc.layout = &ath79_nand_oob_64;
	ath79_priv->nand.ecc.mode = NAND_ECC_HW;
	ath79_priv->nand.ecc.size = mtd->writesize;
	ath79_priv->nand.ecc.bytes = 28;
	ath79_priv->nand.ecc.hwctl = (void *)ath79_null;
	ath79_priv->nand.ecc.calculate = (void *)ath79_null;
	ath79_priv->nand.ecc.correct = (void *)ath79_null;
	ath79_priv->nand.write_page = ath79_write_page;
	ath79_priv->nand.ecc.write_oob = ath79_write_oob;
	ath79_priv->nand.ecc.read_page = ath79_read_page;
	ath79_priv->nand.ecc.read_page_raw = ath79_read_page_raw;
	ath79_priv->nand.ecc.read_oob = ath79_read_oob;
	ath79_priv->nand.erase = ath79_erase_cmd;

	err = nand_scan_tail(mtd);
	if (err) {
		dev_err(&pdev->dev, "nand scan tail error %d\n", err);
		err = -ENXIO;
		goto out_err_nand_scan;
	}

	/* create NAND partition */
	mtd_device_parse_register(mtd, ath79_nand_part_probes, 0,
				  ath79_nand_partitions,
				  ARRAY_SIZE(ath79_nand_partitions));

	dev_info(&pdev->dev,
		 "====== NAND Parameters ======\n total size = 0x%llx, page = 0x%x block = 0x%x oob = 0x%x\n",
		 mtd->size, mtd->writesize, mtd->erasesize, mtd->oobsize);

	/* save platform driver private data */
	platform_set_drvdata(pdev, mtd);

	return 0;

out_err_nand_scan:
	kfree(ath79_priv->page_buf);
out_err_hw_init:
	dma_free_coherent(NULL, AR934X_NAND_DMA_DESCR_SIZE * 2,
			  (void *)ath79_priv->dma_descr_virtaddr,
			  ath79_priv->dma_descr_phyaddr);
out_err_dma_alloc_coherent:
	iounmap(ath79_priv->ddr_io_addr);
out_err_ioremap2:
	iounmap(ath79_priv->io_base);
out_err_ioremap1:
	kfree(mtd);
out_err_kzalloc:

	return err;
}

static struct platform_driver ath79_nand_driver = {
	.probe = ath79_nand_probe,
	.remove = ath79_nand_remove,
	.driver = {
		   .name = DRV_NAME,
		   .owner = THIS_MODULE,
		   },
};

module_platform_driver(ath79_nand_driver);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_ALIAS("platform:" DRV_NAME);
