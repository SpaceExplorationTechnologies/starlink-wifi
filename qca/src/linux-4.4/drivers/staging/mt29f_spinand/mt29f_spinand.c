/*
 * Copyright (c) 2003-2013 Broadcom Corporation
 *
 * Copyright (c) 2009-2010 Micron Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/delay.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/mtd/nand.h>
#include <linux/spi/spi.h>
#include <linux/sizes.h>

#include "mt29f_spinand.h"
#include "giga_spinand.h"

#define BUFSIZE (10 * 64 * 4096)
#define CACHE_BUF 4352

static int spinand_disable_ecc(struct spi_device *spi_nand);
static int spinand_lock_block(struct spi_device *spi_nand, u8 lock);

struct spinand_ops spinand_dev[] = {
#ifdef CONFIG_MTD_SPINAND_GIGADEVICE
	{
		NAND_MFR_GIGA,
		1,
		0xb1,
		INT_MAX,
		0x10000,
		gigadevice_set_defaults,
		gigadevice_read_cmd,
		gigadevice_read_data,
		gigadevice_write_cmd,
		gigadevice_write_data,
		gigadevice_erase_blk,
		gigadevice_parse_id,
		gigadevice_verify_ecc,
		NULL,
	},
	{
		NAND_MFR_GIGA,
		1,
		0xb4,
		INT_MAX,
		0x20000,
		gigadevice_set_defaults_512mb,
		gigadevice_read_cmd,
		gigadevice_read_data,
		gigadevice_write_cmd,
		gigadevice_write_data,
		gigadevice_erase_blk,
		gigadevice_parse_id,
		gigadevice_verify_ecc,
		NULL,
	},
	{
		NAND_MFR_GIGA,
		1,
		0xa1,
		INT_MAX,
		0x10000,
		gigadevice_set_defaults,
		gigadevice_read_cmd,
		gigadevice_read_data,
		gigadevice_write_cmd,
		gigadevice_write_data,
		gigadevice_erase_blk,
		gigadevice_parse_id,
		gigadevice_verify_ecc,
		NULL,
	},
	{
		NAND_MFR_GIGA,
		1,
		0xd1,
		INT_MAX,
		0x10000,
		gigadevice_set_defaults_128mb,
		gigadevice_read_cmd,
		gigadevice_read_data_v2,
		gigadevice_write_cmd,
		gigadevice_write_data,
		gigadevice_erase_blk,
		gigadevice_parse_id_v2,
		gigadevice_verify_ecc,
		NULL,
	},
	{
		NAND_MFR_ATO,
		1,
		0x12,
		INT_MAX,
		0x10000,
		gigadevice_set_defaults,
		gigadevice_read_cmd,
		gigadevice_read_data,
		gigadevice_write_cmd,
		gigadevice_write_data,
		gigadevice_erase_blk,
		gigadevice_parse_id,
		dummy_verify_ecc,
		NULL,
	},
#endif
	{
		NAND_MFR_MACRONIX,
		1,
		0x12,
		INT_MAX,
		0x10000,
		macronix_set_defaults,
		gigadevice_read_cmd,
		macronix_read_data,
		gigadevice_write_cmd,
		macronix_write_data,
		gigadevice_erase_blk,
		macronix_parse_id,
		macronix_verify_ecc,
		NULL,
	},
	{
		NAND_MFR_WINBOND,
		1,
		0xaa,
		INT_MAX,
		0x10000,
		winbond_set_defaults,
		gigadevice_read_cmd,
		winbond_read_data,
		gigadevice_write_cmd,
		winbond_write_data,
		gigadevice_erase_blk,
		winbond_parse_id,
		macronix_verify_ecc,
		NULL,
	},
	{
		NAND_MFR_WINBOND,
		2,
		0xab,
		INT_MAX,
		0x10000,
		winbond_set_defaults,
		gigadevice_read_cmd,
		winbond_read_data,
		gigadevice_write_cmd,
		winbond_write_data,
		gigadevice_erase_blk,
		winbond_parse_id,
		macronix_verify_ecc,
		winbond_die_select,
	},
	{
		NAND_MFR_TOSHIBA,
		1,
		0xcd,
		INT_MAX,
		0x20000,
		gigadevice_set_defaults_512mb,
		toshiba_read_cmd,
		toshiba_read_data,
		toshiba_write_cmd,
		toshiba_write_data,
		toshiba_erase_blk,
		toshiba_parse_id,
		toshiba_verify_ecc,
		NULL,
	},
	{ },
};

void mt29f_read_page_to_cache(struct spinand_cmd *cmd, u32 page_id)
{
	cmd->addr[1] = (u8)((page_id & 0xff00) >> 8);
	cmd->addr[2] = (u8)(page_id & 0x00ff);
}

void mt29f_read_from_cache(struct spinand_cmd *cmd, u16 column, u32 page_id)
{
	cmd->addr[0] = (u8)((column & 0xff00) >> 8);
	cmd->addr[0] |= (u8)(((page_id >> 6) & 0x1) << 4);
	cmd->addr[1] = (u8)(column & 0x00ff);
	cmd->addr[2] = (u8)(0xff);
}

void mt29f_program_data_to_cache(struct spinand_cmd *cmd, u16 column,
				 u32 page_id)
{
	cmd->addr[0] = (u8)((column & 0xff00) >> 8);
	cmd->addr[0] |= (u8)(((page_id >> 6) & 0x1) << 4);
	cmd->addr[1] = (u8)(column & 0x00ff);
}

void mt29f_program_execute(struct spinand_cmd *cmd, u32 column)
{
	cmd->addr[1] = (u8)((column & 0xff00) >> 8);
	cmd->addr[2] = (u8)(column & 0x00ff);
}

void mt29f_erase_block_erase(struct spinand_cmd *cmd, u32 page_id)
{
	cmd->addr[1] = (u8)((page_id & 0xff00) >> 8);
	cmd->addr[2] = (u8)(page_id & 0x00ff);
}

int mt29f_verify_ecc(u8 status)
{
	int ecc_status = (status & STATUS_ECC_MASK);

	if (ecc_status == STATUS_ECC_ERROR)
		return SPINAND_ECC_ERROR;
	else if (ecc_status == STATUS_ECC_1BIT_CORRECTED)
		return SPINAND_ECC_CORRECTED;
	else
		return 0;
}

struct spinand_ops mt29f_spinand_ops = {
		NAND_MFR_MICRON,
		1,
		0x0,
		INT_MAX,
		0x0,
		NULL,
		mt29f_read_page_to_cache,
		mt29f_read_from_cache,
		mt29f_program_execute,
		mt29f_program_data_to_cache,
		mt29f_erase_block_erase,
		NULL,
		mt29f_verify_ecc,
		NULL,
};

static inline struct spinand_ops *get_dev_ops(struct spi_device *spi_nand)
{
	struct mtd_info *mtd = (struct mtd_info *)dev_get_drvdata
							(&spi_nand->dev);
	struct nand_chip *chip = (struct nand_chip *)mtd->priv;
	struct spinand_info *info = (struct spinand_info *)chip->priv;
	struct spinand_ops *dev_ops = info->dev_ops;

	return dev_ops;
}

void spinand_parse_id(struct spi_device *spi_nand, u8 *nand_id, u8 *id)
{
	int tmp;
	struct spinand_ops *tmp_ops;
	struct mtd_info *mtd = (struct mtd_info *)
					dev_get_drvdata(&spi_nand->dev);
	struct nand_chip *chip = (struct nand_chip *)mtd->priv;
	struct spinand_info *info = (struct spinand_info *)chip->priv;

	for (tmp = 0; tmp < ARRAY_SIZE(spinand_dev) - 1; tmp++) {
		tmp_ops = &spinand_dev[tmp];
			if (tmp_ops->spinand_parse_id(spi_nand, tmp_ops,
						      nand_id, id) == 0) {
				info->dev_ops = &spinand_dev[tmp];
				info->dev_ops->spinand_set_defaults(spi_nand);
				return;
			}
	}
	info->dev_ops = &mt29f_spinand_ops;
}

/*
 * OOB area specification layout:  Total 32 available free bytes.
 */

static inline struct spinand_state *mtd_to_state(struct mtd_info *mtd)
{
	struct nand_chip *chip = (struct nand_chip *)mtd->priv;
	struct spinand_info *info = (struct spinand_info *)chip->priv;
	struct spinand_state *state = (struct spinand_state *)info->priv;

	return state;
}

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
static int enable_hw_ecc;
static int enable_read_hw_ecc;

static struct nand_ecclayout spinand_oob_64 = {
	.eccbytes = 24,
	.eccpos = {
		1, 2, 3, 4, 5, 6,
		17, 18, 19, 20, 21, 22,
		33, 34, 35, 36, 37, 38,
		49, 50, 51, 52, 53, 54, },
	.oobavail = 32,
	.oobfree = {
		{.offset = 8,
			.length = 8},
		{.offset = 24,
			.length = 8},
		{.offset = 40,
			.length = 8},
		{.offset = 56,
			.length = 8},
	}
};
#endif

/*
 * spinand_cmd - to process a command to send to the SPI Nand
 * Description:
 *    Set up the command buffer to send to the SPI controller.
 *    The command buffer has to initialized to 0.
 */

static int spinand_cmd(struct spi_device *spi, struct spinand_cmd *cmd)
{
	struct spi_message message;
	struct spi_transfer x[4];
	u8 dummy = 0xff;

	spi_message_init(&message);
	memset(x, 0, sizeof(x));

	x[0].len = 1;
	x[0].tx_buf = &cmd->cmd;
	spi_message_add_tail(&x[0], &message);

	if (cmd->n_addr) {
		x[1].len = cmd->n_addr;
		x[1].tx_buf = cmd->addr;
		spi_message_add_tail(&x[1], &message);
	}

	if (cmd->n_dummy) {
		x[2].len = cmd->n_dummy;
		x[2].tx_buf = &dummy;
		spi_message_add_tail(&x[2], &message);
	}

	if (cmd->n_tx) {
		x[3].len = cmd->n_tx;
		x[3].tx_buf = cmd->tx_buf;
		spi_message_add_tail(&x[3], &message);
	}

	if (cmd->n_rx) {
		x[3].len = cmd->n_rx;
		x[3].rx_buf = cmd->rx_buf;
		spi_message_add_tail(&x[3], &message);
	}

	return spi_sync(spi, &message);
}

static int get_die_id(struct spinand_ops *dev_ops, u32 page_id)
{
	do_div(page_id, dev_ops->pages_per_die);
	if (page_id > dev_ops->no_of_dies) {
		pr_info("invalid die id : %d\n", page_id);
		return -EINVAL;
	}

	return page_id;
}

/*
 * winbond_die_select - send command 0xc2 to select die
 * Description:
 *   Die select function.
 *   Die ID is given as either 0 or 1 to select die 0 or 1
 *   respectively
 */
int winbond_die_select(struct spi_device *spi_nand,
		       struct spinand_ops *dev_ops, u8 die_id)
{
	int retval;
	struct spinand_cmd cmd = {0};

	if (die_id < 0)
		return -1;

	if (dev_ops->prev_die_id == die_id)
		return 0;

	cmd.cmd = CMD_DIE_SELECT,
	cmd.n_addr = 1,
	cmd.addr[0] = die_id,
	retval = spinand_cmd(spi_nand, &cmd);
	if (retval < 0)
		dev_err(&spi_nand->dev, "error %d in die select\n", retval);
	else
		dev_ops->prev_die_id = die_id;

	return retval;
}

static inline int select_die(struct spi_device *spi_nand,
			     struct spinand_ops *dev_ops, int die)
{
	if (!dev_ops->spinand_die_select)
		return 0;

	return dev_ops->spinand_die_select(spi_nand,
		dev_ops, die);
}

/*
 * spinand_read_id- Read SPI Nand ID
 * Description:
 *    Read ID: read two ID bytes from the SPI Nand device
 */
static int spinand_read_id(struct spi_device *spi_nand, u8 *id)
{
	int retval;
	int i;
	u8 nand_id[3];
	struct spinand_cmd cmd = {0};
	struct spinand_ops *dev_ops;

	cmd.cmd = CMD_READ_ID;
	cmd.n_rx = 3;
	cmd.rx_buf = &nand_id[0];

	retval = spinand_cmd(spi_nand, &cmd);
	if (retval < 0) {
		dev_err(&spi_nand->dev, "error %d reading id\n", retval);
		return retval;
	}
	id[0] = nand_id[1];
	id[1] = nand_id[2];
	spinand_parse_id(spi_nand, nand_id, id);
	dev_ops = get_dev_ops(spi_nand);
	if (dev_ops->spinand_die_select) {
		for (i = 0; i < dev_ops->no_of_dies; i++) {
			retval = dev_ops->spinand_die_select(spi_nand,
						dev_ops, i);
			if (retval < 0)
				return retval;
			spinand_lock_block(spi_nand, BL_ALL_UNLOCKED);
			if (spinand_disable_ecc(spi_nand) < 0)
				pr_info("%s: disable ecc failed!\n", __func__);
		}
	}

	return retval;
}

/*
 * spinand_read_status- send command 0xf to the SPI Nand status register
 * Description:
 *    After read, write, or erase, the Nand device is expected to set the
 *    busy status.
 *    This function is to allow reading the status of the command: read,
 *    write, and erase.
 *    Once the status turns to be ready, the other status bits also are
 *    valid status bits.
 */
static int spinand_read_status(struct spi_device *spi_nand, u8 *status)
{
	struct spinand_cmd cmd = {0};
	int ret;

	cmd.cmd = CMD_READ_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_STATUS;
	cmd.n_rx = 1;
	cmd.rx_buf = status;

	ret = spinand_cmd(spi_nand, &cmd);
	if (ret < 0)
		dev_err(&spi_nand->dev, "err: %d read status register\n", ret);

	return ret;
}

#define MAX_WAIT_JIFFIES  (40 * HZ)
static int wait_till_ready(struct spi_device *spi_nand)
{
	unsigned long deadline;
	int retval;
	u8 stat = 0;

	deadline = jiffies + MAX_WAIT_JIFFIES;
	do {
		retval = spinand_read_status(spi_nand, &stat);
		if (retval < 0)
			return -1;
		else if (!(stat & 0x1))
			break;

		cond_resched();
	} while (!time_after_eq(jiffies, deadline));

	if ((stat & 0x1) == 0)
		return 0;

	return -1;
}

/**
 * spinand_get_otp- send command 0xf to read the SPI Nand OTP register
 * Description:
 *   There is one bit( bit 0x10 ) to set or to clear the internal ECC.
 *   Enable chip internal ECC, set the bit to 1
 *   Disable chip internal ECC, clear the bit to 0
 */
static int spinand_get_otp(struct spi_device *spi_nand, u8 *otp)
{
	struct spinand_cmd cmd = {0};
	int retval;

	cmd.cmd = CMD_READ_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_OTP;
	cmd.n_rx = 1;
	cmd.rx_buf = otp;

	retval = spinand_cmd(spi_nand, &cmd);
	if (retval < 0)
		dev_err(&spi_nand->dev, "error %d get otp\n", retval);
	return retval;
}

/**
 * spinand_set_otp- send command 0x1f to write the SPI Nand OTP register
 * Description:
 *   There is one bit( bit 0x10 ) to set or to clear the internal ECC.
 *   Enable chip internal ECC, set the bit to 1
 *   Disable chip internal ECC, clear the bit to 0
 */
static int spinand_set_otp(struct spi_device *spi_nand, u8 *otp)
{
	int retval;
	struct spinand_cmd cmd = {0};

	cmd.cmd = CMD_WRITE_REG,
	cmd.n_addr = 1,
	cmd.addr[0] = REG_OTP,
	cmd.n_tx = 1,
	cmd.tx_buf = otp,

	retval = spinand_cmd(spi_nand, &cmd);
	if (retval < 0)
		dev_err(&spi_nand->dev, "error %d set otp\n", retval);

	return retval;
}

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
/**
 * spinand_enable_ecc- send command 0x1f to write the SPI Nand OTP register
 * Description:
 *   There is one bit( bit 0x10 ) to set or to clear the internal ECC.
 *   Enable chip internal ECC, set the bit to 1
 *   Disable chip internal ECC, clear the bit to 0
 */
static int spinand_enable_ecc(struct spi_device *spi_nand)
{
	int retval;
	int i;
	struct spinand_ops *dev_ops = get_dev_ops(spi_nand);
	u8 otp = 0;

	for (i = 0; i < dev_ops->no_of_dies; i++) {
		retval = select_die(spi_nand, dev_ops, i);
		if (retval < 0)
			return retval;

		retval = spinand_get_otp(spi_nand, &otp);
		if (retval < 0)
			return retval;

		if ((otp & OTP_ECC_MASK) != OTP_ECC_MASK) {
			otp |= OTP_ECC_MASK;
			retval = spinand_set_otp(spi_nand, &otp);
			if (retval < 0)
				return retval;
			retval = spinand_get_otp(spi_nand, &otp);
			if (retval < 0)
				return retval;
		}
	}

	return 0;
}
#endif

static int spinand_disable_ecc(struct spi_device *spi_nand)
{
	int retval;
	u8 otp = 0;

	retval = spinand_get_otp(spi_nand, &otp);
	if (retval < 0)
		return retval;

	if ((otp & OTP_ECC_MASK) == OTP_ECC_MASK) {
		otp &= ~OTP_ECC_MASK;
		retval = spinand_set_otp(spi_nand, &otp);
		if (retval < 0)
			return retval;
		return spinand_get_otp(spi_nand, &otp);
	}
	return 0;
}

/**
 * spinand_write_config- send command 0x06 to enable write or erase the
 * Nand cells or send command 0x04 to disable write or erase the
 * Nand cells
 *
 * Description:
 *   Before write and erase the Nand cells, the write enable has to be set.
 *   After the write or erase, the write enable bit is automatically
 *   cleared (status register bit 2)
 *   Set the bit 2 of the status register has the same effect
 *   After write and erase the Nand cells, the write enable has to be disabled.
 */
static int spinand_write_config(struct spi_device *spi_nand, u8 opcode)
{
	int ret = 0;
	int i;
	struct spinand_ops *dev_ops = get_dev_ops(spi_nand);
	struct spinand_cmd cmd = {0};

	for (i = 0; i < dev_ops->no_of_dies; i++) {
		ret = select_die(spi_nand, dev_ops, i);
		if (ret < 0)
			return ret;
		cmd.cmd = opcode;
		ret = spinand_cmd(spi_nand, &cmd);
		if (ret < 0)
			return ret;
	}

	return ret;
}

static int spinand_read_page_to_cache(struct spi_device *spi_nand, u32 page_id)
{
	struct spinand_cmd cmd = {0};
	struct spinand_ops *dev_ops = get_dev_ops(spi_nand);

	select_die(spi_nand, dev_ops, get_die_id(dev_ops, page_id));

	cmd.cmd = CMD_READ;
	cmd.n_addr = 3;
	dev_ops->spinand_read_cmd(&cmd, page_id);

	return spinand_cmd(spi_nand, &cmd);
}

/*
 * spinand_read_from_cache- send command 0x03 to read out the data from the
 * cache register(2112 bytes max)
 * Description:
 *   The read can specify 1 to 2112 bytes of data read at the corresponding
 *   locations.
 *   No tRd delay.
 */
static int spinand_read_from_cache(struct spi_device *spi_nand, u32 page_id,
				   u16 byte_id, u16 len, u8 *rbuf)
{
	struct spinand_cmd cmd = {0};
	u16 column;
	struct spinand_ops *dev_ops = get_dev_ops(spi_nand);

	column = byte_id;
	cmd.cmd = CMD_READ_RDM;
	cmd.n_addr = 3;
	dev_ops->spinand_read_data(&cmd, column, page_id);
	cmd.n_dummy = 0;
	cmd.n_rx = len;
	cmd.rx_buf = rbuf;

	return spinand_cmd(spi_nand, &cmd);
}

/*
 * spinand_read_page-to read a page with:
 * @page_id: the physical page number
 * @offset:  the location from 0 to 2111
 * @len:     number of bytes to read
 * @rbuf:    read buffer to hold @len bytes
 *
 * Description:
 *   The read includes two commands to the Nand: 0x13 and 0x03 commands
 *   Poll to read status to wait for tRD time.
 */
static int spinand_read_page(struct spi_device *spi_nand, u32 page_id,
			     u32 offset, u32 len, u8 *rbuf)
{
	int ret, ecc_error = 0, ecc_corrected = 0;
	u8 status = 0;
	struct spinand_ops *dev_ops = get_dev_ops(spi_nand);
	struct mtd_info *mtd = (struct mtd_info *)
					dev_get_drvdata(&spi_nand->dev);

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
	if (enable_read_hw_ecc) {
		if (spinand_enable_ecc(spi_nand) < 0)
			dev_err(&spi_nand->dev, "enable HW ECC failed!");
	}
#endif
	ret = spinand_read_page_to_cache(spi_nand, page_id);
	if (ret < 0)
		return ret;

	if (wait_till_ready(spi_nand))
		dev_err(&spi_nand->dev, "WAIT timedout!!!\n");

	while (1) {
		ret = spinand_read_status(spi_nand, &status);
		if (ret < 0) {
			dev_err(&spi_nand->dev,
				"err %d read status register\n", ret);
			return ret;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			ret = dev_ops->spinand_verify_ecc(status);
			if (ret == SPINAND_ECC_ERROR) {
				dev_err(&spi_nand->dev, "ecc error, page=%d\n",
					page_id);
				mtd->ecc_stats.failed++;
				ecc_error = 1;
			} else if (ret == SPINAND_ECC_CORRECTED) {
				mtd->ecc_stats.corrected++;
				ecc_corrected = 1;
			}
			break;
		}
	}

	ret = spinand_read_from_cache(spi_nand, page_id, offset, len, rbuf);
	if (ret < 0) {
		dev_err(&spi_nand->dev, "read from cache failed!!\n");
		return ret;
	}

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
	if (enable_read_hw_ecc) {
		ret = spinand_disable_ecc(spi_nand);
		if (ret < 0) {
			dev_err(&spi_nand->dev, "disable ecc failed!!\n");
			return ret;
		}
		enable_read_hw_ecc = 0;
	}
#endif
	if (ecc_error)
		ret = -EBADMSG;
	else if (ecc_corrected)
		ret = -EUCLEAN;

	return ret;
}

/*
 * spinand_program_data_to_cache--to write a page to cache with:
 * @byte_id: the location to write to the cache
 * @len:     number of bytes to write
 * @rbuf:    read buffer to hold @len bytes
 *
 * Description:
 *   The write command used here is 0x84--indicating that the cache is
 *   not cleared first.
 *   Since it is writing the data to cache, there is no tPROG time.
 */
static int spinand_program_data_to_cache(struct spi_device *spi_nand,
					 u32 page_id, u16 byte_id,
					 u16 len, u8 *wbuf)
{
	struct spinand_cmd cmd = {0};
	u16 column;
	struct spinand_ops *dev_ops = get_dev_ops(spi_nand);

	select_die(spi_nand, dev_ops, get_die_id(dev_ops, page_id));

	column = byte_id;
	cmd.cmd = CMD_PROG_PAGE_CLRCACHE;
	cmd.n_addr = 2;
	dev_ops->spinand_write_data(&cmd, column, page_id);
	cmd.n_tx = len;
	cmd.tx_buf = wbuf + column;

	return spinand_cmd(spi_nand, &cmd);
}

/**
 * spinand_program_execute--to write a page from cache to the Nand array with
 * @page_id: the physical page location to write the page.
 *
 * Description:
 *   The write command used here is 0x10--indicating the cache is writing to
 *   the Nand array.
 *   Need to wait for tPROG time to finish the transaction.
 */
static int spinand_program_execute(struct spi_device *spi_nand, u32 page_id)
{
	struct spinand_cmd cmd = {0};
	struct spinand_ops *dev_ops = get_dev_ops(spi_nand);

	select_die(spi_nand, dev_ops, get_die_id(dev_ops, page_id));

	cmd.cmd = CMD_PROG_PAGE_EXC;
	cmd.n_addr = 3;
	dev_ops->spinand_write_cmd(&cmd, page_id);

	return spinand_cmd(spi_nand, &cmd);
}

/**
 * spinand_program_page--to write a page with:
 * @page_id: the physical page location to write the page.
 * @offset:  the location from the cache starting from 0 to 2111
 * @len:     the number of bytes to write
 * @wbuf:    the buffer to hold the number of bytes
 *
 * Description:
 *   The commands used here are 0x06, 0x84, and 0x10--indicating that
 *   the write enable is first sent, the write cache command, and the
 *   write execute command.
 *   Poll to wait for the tPROG time to finish the transaction.
 */
static int spinand_program_page(struct spi_device *spi_nand,
				u32 page_id, u16 offset, u16 len, u8 *buf)
{
	int retval = 0;
	u8 status = 0;
	u8 *wbuf;
#ifdef CONFIG_MTD_SPINAND_ONDIEECC

	enable_read_hw_ecc = 0;
	wbuf = kzalloc(CACHE_BUF, GFP_KERNEL);
	if (!wbuf)
		return -ENOMEM;

	spinand_read_page(spi_nand, page_id, 0, CACHE_BUF, wbuf);

	memcpy(wbuf + offset, buf, len);

	if (enable_hw_ecc) {
		retval = spinand_enable_ecc(spi_nand);
		if (retval < 0) {
			dev_err(&spi_nand->dev, "enable ecc failed!!\n");
			goto exit;
		}
	}
#else
	wbuf = buf;
#endif
	retval = spinand_write_config(spi_nand, CMD_WR_ENABLE);
	if (retval < 0) {
		dev_err(&spi_nand->dev, "write enable failed!!\n");
		goto exit;
	}
	if (wait_till_ready(spi_nand))
		dev_err(&spi_nand->dev, "wait timedout!!!\n");

	retval = spinand_program_data_to_cache(spi_nand, page_id,
					       offset, len, wbuf);
	if (retval < 0)
		goto exit;

	retval = spinand_program_execute(spi_nand, page_id);
	if (retval < 0)
		goto exit;

	while (1) {
		retval = spinand_read_status(spi_nand, &status);
		if (retval < 0) {
			dev_err(&spi_nand->dev,
				"error %d reading status register\n", retval);
			goto exit;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if ((status & STATUS_P_FAIL_MASK) == STATUS_P_FAIL) {
				dev_err(&spi_nand->dev,
					"program error, page %d\n", page_id);
				retval = -1;
				goto exit;
			}
			break;
		}
	}
#ifdef CONFIG_MTD_SPINAND_ONDIEECC
	if (enable_hw_ecc) {
		retval = spinand_disable_ecc(spi_nand);
		if (retval < 0) {
			dev_err(&spi_nand->dev, "disable ecc failed!!\n");
			goto exit;
		}
		enable_hw_ecc = 0;
	}
#endif
	retval = spinand_write_config(spi_nand, CMD_WR_DISABLE);
	if (retval < 0) {
		dev_err(&spi_nand->dev, "write disable failed!!\n");
		goto exit;
	}
	if (wait_till_ready(spi_nand))
		dev_err(&spi_nand->dev, "wait timedout!!!\n");

exit:
#ifdef CONFIG_MTD_SPINAND_ONDIEECC
	kfree(wbuf);
#endif
	return retval;
}

/**
 * spinand_erase_block_erase--to erase a page with:
 * @block_id: the physical block location to erase.
 *
 * Description:
 *   The command used here is 0xd8--indicating an erase command to erase
 *   one block--64 pages
 *   Need to wait for tERS.
 */
static int spinand_erase_block_erase(struct spi_device *spi_nand, u32 block_id)
{
	struct spinand_cmd cmd = {0};
	struct spinand_ops *dev_ops = get_dev_ops(spi_nand);

	select_die(spi_nand, dev_ops, get_die_id(dev_ops, block_id));

	cmd.cmd = CMD_ERASE_BLK;
	cmd.n_addr = 3;
	dev_ops->spinand_erase_blk(&cmd, block_id);

	return spinand_cmd(spi_nand, &cmd);
}

/**
 * spinand_erase_block--to erase a page with:
 * @block_id: the physical block location to erase.
 *
 * Description:
 *   The commands used here are 0x06 and 0xd8--indicating an erase
 *   command to erase one block--64 pages
 *   It will first to enable the write enable bit (0x06 command),
 *   and then send the 0xd8 erase command
 *   Poll to wait for the tERS time to complete the tranaction.
 */
static int spinand_erase_block(struct spi_device *spi_nand, u32 block_id)
{
	int retval;
	u8 status = 0;

	retval = spinand_write_config(spi_nand, CMD_WR_ENABLE);
	if (retval < 0) {
		dev_err(&spi_nand->dev, "write enable failed!!\n");
		return retval;
	}
	if (wait_till_ready(spi_nand))
		dev_err(&spi_nand->dev, "wait timedout!!!\n");

	retval = spinand_erase_block_erase(spi_nand, block_id);
	while (1) {
		retval = spinand_read_status(spi_nand, &status);
		if (retval < 0) {
			dev_err(&spi_nand->dev,
				"error %d reading status register\n", retval);
			return retval;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if ((status & STATUS_E_FAIL_MASK) == STATUS_E_FAIL) {
				dev_err(&spi_nand->dev,
					"erase error, block %d\n", block_id);
				return -1;
			}
			break;
		}
	}
	retval = spinand_write_config(spi_nand, CMD_WR_DISABLE);
	if (retval < 0) {
		dev_err(&spi_nand->dev, "write disable failed!!\n");
		return retval;
	}
	if (wait_till_ready(spi_nand))
		dev_err(&spi_nand->dev, "wait timedout!!!\n");
	return 0;
}

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
static int spinand_write_page_hwecc(struct mtd_info *mtd,
				    struct nand_chip *chip,
				    const u8 *buf, int oob_required,
				    int page)
{
	const u8 *p = buf;
	int eccsize = chip->ecc.size;
	int eccsteps = chip->ecc.steps;

	enable_hw_ecc = 1;
	chip->write_buf(mtd, p, eccsize * eccsteps);
	return 0;
}

static int spinand_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
				   u8 *buf, int oob_required, int page)
{
	int retval;
	u8 status = 0;
	u8 *p = buf;
	int eccsize = chip->ecc.size;
	int eccsteps = chip->ecc.steps;
	struct spinand_info *info = (struct spinand_info *)chip->priv;
	struct spinand_ops *dev_ops = info->dev_ops;
	struct spinand_state *state = (struct spinand_state *)info->priv;

	enable_read_hw_ecc = 1;
	spinand_read_page(info->spi, page, state->col,
		(mtd->writesize + mtd->oobsize), state->buf);

	chip->read_buf(mtd, p, eccsize * eccsteps);
	if (oob_required)
		chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);

	while (1) {
		retval = spinand_read_status(info->spi, &status);
		if (retval < 0) {
			dev_err(&mtd->dev,
				"error %d reading status register\n", retval);
			return retval;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			retval = dev_ops->spinand_verify_ecc(status);
			if (retval == SPINAND_ECC_ERROR) {
				pr_info("spinand: ECC error\n");
				mtd->ecc_stats.failed++;
				retval = -EBADMSG;
			} else if (retval == SPINAND_ECC_CORRECTED) {
				mtd->ecc_stats.corrected++;
				retval = -EUCLEAN;
			}
			break;
		}
	}
	return retval;
}

static int spinand_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
			      uint8_t *buf, int oob_required, int page)
{
	struct spinand_info *info = (struct spinand_info *)chip->priv;
	struct spinand_state *state = (struct spinand_state *)info->priv;

	spinand_read_page(info->spi, page, state->col,
		(mtd->writesize + mtd->oobsize), state->buf);
	chip->read_buf(mtd, buf, mtd->writesize);
	if (oob_required)
		chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
	return 0;
}
#endif

static void spinand_select_chip(struct mtd_info *mtd, int dev)
{
}

static u8 spinand_read_byte(struct mtd_info *mtd)
{
	struct spinand_state *state = mtd_to_state(mtd);
	u8 data;

	data = state->buf[state->buf_ptr];
	state->buf_ptr++;
	return data;
}

static int spinand_wait(struct mtd_info *mtd, struct nand_chip *chip)
{
	struct spinand_info *info = (struct spinand_info *)chip->priv;

	unsigned long timeo = jiffies;
	int retval, state = chip->state;
	u8 status = 0;

	if (state == FL_ERASING)
		timeo += (HZ * 400) / 1000;
	else
		timeo += (HZ * 20) / 1000;

	while (time_before(jiffies, timeo)) {
		retval = spinand_read_status(info->spi, &status);
		if (retval < 0) {
			dev_err(&mtd->dev,
				"error %d reading status register\n", retval);
			return retval;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY)
			return 0;

		cond_resched();
	}
	return 0;
}

static void spinand_write_buf(struct mtd_info *mtd, const u8 *buf, int len)
{
	struct spinand_state *state = mtd_to_state(mtd);

	memcpy(state->buf + state->buf_ptr, buf, len);
	state->buf_ptr += len;
}

static void spinand_read_buf(struct mtd_info *mtd, u8 *buf, int len)
{
	struct spinand_state *state = mtd_to_state(mtd);

	memcpy(buf, state->buf + state->buf_ptr, len);
	state->buf_ptr += len;
}

/*
 * spinand_reset- send RESET command "0xff" to the Nand device.
 */
static void spinand_reset(struct spi_device *spi_nand)
{
	struct spinand_cmd cmd = {0};

	cmd.cmd = CMD_RESET;

	if (spinand_cmd(spi_nand, &cmd) < 0)
		pr_info("spinand reset failed!\n");

	/* elapse 1ms before issuing any other command */
	usleep_range(1000, 2000);

	if (wait_till_ready(spi_nand))
		dev_err(&spi_nand->dev, "wait timedout!\n");
}

static void spinand_cmdfunc(struct mtd_info *mtd, unsigned int command,
			    int column, int page)
{
	struct nand_chip *chip = (struct nand_chip *)mtd->priv;
	struct spinand_info *info = (struct spinand_info *)chip->priv;
	struct spinand_state *state = (struct spinand_state *)info->priv;

	switch (command) {
	/*
	 * READ0 - read in first  0x800 bytes
	 */
	case NAND_CMD_READ1:
	case NAND_CMD_READ0:
		state->col = column;
		state->row = page;
		state->buf_ptr = 0;
		break;
	/* READOOB reads only the OOB because no ECC is performed. */
	case NAND_CMD_READOOB:
		state->buf_ptr = 0;
		spinand_read_page(info->spi, page, (mtd->writesize + column),
				  mtd->oobsize, state->buf);
		break;
	case NAND_CMD_RNDOUT:
		state->buf_ptr = column;
		break;
	case NAND_CMD_READID:
		state->buf_ptr = 0;
		spinand_read_id(info->spi, state->buf);
		break;
	case NAND_CMD_PARAM:
		state->buf_ptr = 0;
		break;
	/* ERASE1 stores the block and page address */
	case NAND_CMD_ERASE1:
		spinand_erase_block(info->spi, page);
		break;
	/* ERASE2 uses the block and page address from ERASE1 */
	case NAND_CMD_ERASE2:
		break;
	/* SEQIN sets up the addr buffer and all registers except the length */
	case NAND_CMD_SEQIN:
		state->col = column;
		state->row = page;
		state->buf_ptr = 0;
		break;
	/* PAGEPROG reuses all of the setup from SEQIN and adds the length */
	case NAND_CMD_PAGEPROG:
		spinand_program_page(info->spi, state->row, state->col,
				     state->buf_ptr, state->buf);
		break;
	case NAND_CMD_STATUS:
		spinand_get_otp(info->spi, state->buf);
		if (!(state->buf[0] & 0x80))
			state->buf[0] = 0x80;
		state->buf_ptr = 0;
		break;
	/* RESET command */
	case NAND_CMD_RESET:
		if (wait_till_ready(info->spi))
			dev_err(&info->spi->dev, "WAIT timedout!!!\n");
		/* a minimum of 250us must elapse before issuing RESET cmd*/
		usleep_range(250, 1000);
		spinand_reset(info->spi);
		break;
	default:
		dev_err(&mtd->dev, "Unknown CMD: 0x%x\n", command);
	}
}

/**
 * spinand_lock_block- send write register 0x1f command to the Nand device
 *
 * Description:
 *    After power up, all the Nand blocks are locked.  This function allows
 *    one to unlock the blocks, and so it can be written or erased.
 */
static int spinand_lock_block(struct spi_device *spi_nand, u8 lock)
{
	struct spinand_cmd cmd = {0};
	int ret;
	u8 otp = 0;

	ret = spinand_get_otp(spi_nand, &otp);

	cmd.cmd = CMD_WRITE_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_BLOCK_LOCK;
	cmd.n_tx = 1;
	cmd.tx_buf = &lock;

	ret = spinand_cmd(spi_nand, &cmd);
	if (ret < 0)
		dev_err(&spi_nand->dev, "error %d lock block\n", ret);

	return ret;
}

/* SPI NAND ID Table */
struct nand_flash_dev spinand_flash_ids[] = {
	{"ATO25D1GA 128MiB 3.3V",
		{ .id = {0x9b, 0x12} }, SZ_2K, 128, SZ_128K, 0, 2, 64},

	{"GD5F4GQ4UC 512MiB 3.3V",
		{ .id = {0xc8, 0xB4} }, SZ_4K, 512, SZ_256K, 0, 2, 256},

	{"GD5F1GQ1UC 128MiB 3.3V",
		{ .id = {0xc8, 0xB1} }, SZ_2K, 128, SZ_128K, 0, 2, 128},

	{"GD5F1GQ1RC 128MiB 1.8V",
		{ .id = {0xc8, 0xA1} }, SZ_2K, 128, SZ_128K, 0, 2, 128},

	{"MX35LFxGE4AB 128MiB 3.3V",
		{ .id = {0xc2, 0x12} }, SZ_2K, 128, SZ_128K, 0, 2, 64},

	{"W25N01GV 128MiB 3.3V",
		{ .id = {0xef, 0xaa} }, SZ_2K, 128, SZ_128K, 0, 2, 64},

	{"W25M02GV 256MiB 3.3V(Dual die)",
		{ .id = {0xef, 0xab} }, SZ_2K, 256, SZ_128K, 0, 2, 64},

	{"TC58CVG2S0F 4G 3.3V 8-bit",
		{ .id = {0x98, 0xcd} }, SZ_4K, 512, SZ_256K, 0, 2, 128},

	{"GD5F1GQ4UB 128MiB 3.3V",
		{ .id = {0xc8, 0xd1} }, SZ_2K, 128, SZ_128K, 0, 2, 128},

	{NULL}
};

/*
 * spinand_probe - [spinand Interface]
 * @spi_nand: registered device driver.
 *
 * Description:
 *   To set up the device driver parameters to make the device available.
 */
static int spinand_probe(struct spi_device *spi_nand)
{
	struct mtd_info *mtd;
	struct nand_chip *chip;
	struct spinand_info *info;
	struct spinand_state *state;
	struct mtd_part_parser_data ppdata;

	info  = devm_kzalloc(&spi_nand->dev, sizeof(struct spinand_info),
			     GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	info->spi = spi_nand;

	spinand_lock_block(spi_nand, BL_ALL_UNLOCKED);

	state = devm_kzalloc(&spi_nand->dev, sizeof(struct spinand_state),
			     GFP_KERNEL);
	if (!state)
		return -ENOMEM;

	info->priv	= state;
	state->buf_ptr	= 0;
	state->buf	= devm_kzalloc(&spi_nand->dev, BUFSIZE, GFP_KERNEL);
	if (!state->buf)
		return -ENOMEM;

	chip = devm_kzalloc(&spi_nand->dev, sizeof(struct nand_chip),
			    GFP_KERNEL);
	if (!chip)
		return -ENOMEM;

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
	chip->ecc.mode	= NAND_ECC_HW;
	chip->ecc.size	= 0x200;
	chip->ecc.bytes	= 0x6;
	chip->ecc.steps	= 0x4;

	chip->ecc.strength = 1;
	chip->ecc.total	= chip->ecc.steps * chip->ecc.bytes;
	chip->ecc.layout = &spinand_oob_64;
	chip->ecc.read_page = spinand_read_page_hwecc;
	chip->ecc.read_page_raw = spinand_read_page_raw;
	chip->ecc.write_page = spinand_write_page_hwecc;
#else
	chip->ecc.mode	= NAND_ECC_SOFT;
	if (spinand_disable_ecc(spi_nand) < 0)
		pr_info("%s: disable ecc failed!\n", __func__);
#endif

	chip->priv	= info;
	chip->read_buf	= spinand_read_buf;
	chip->write_buf	= spinand_write_buf;
	chip->read_byte	= spinand_read_byte;
	chip->cmdfunc	= spinand_cmdfunc;
	chip->waitfunc	= spinand_wait;
	chip->options	|= NAND_CACHEPRG;
	chip->select_chip = spinand_select_chip;

	mtd = &chip->mtd;

	dev_set_drvdata(&spi_nand->dev, mtd);

	mtd->priv = chip;
	mtd->dev.parent = &spi_nand->dev;
	mtd->oobsize = 64;

	if (nand_scan_ident(mtd, 1, spinand_flash_ids))
		return -ENXIO;

	if (nand_scan_tail(mtd))
		return -ENXIO;

	ppdata.of_node = spi_nand->dev.of_node;
	return mtd_device_parse_register(mtd, NULL, &ppdata, NULL, 0);
}

/*
 * spinand_remove: Remove the device driver
 * @spi: the spi device.
 *
 * Description:
 *   To remove the device driver parameters and free up allocated memories.
 */
static int spinand_remove(struct spi_device *spi)
{
	mtd_device_unregister(dev_get_drvdata(&spi->dev));

	return 0;
}

static const struct of_device_id spinand_dt[] = {
	{ .compatible = "spinand,mt29f", },
	{}
};
MODULE_DEVICE_TABLE(of, spinand_dt);

/*
 * Device name structure description
 */
static struct spi_driver spinand_driver = {
	.driver = {
		.name		= "mt29f",
		.of_match_table	= spinand_dt,
	},
	.probe		= spinand_probe,
	.remove		= spinand_remove,
};

module_spi_driver(spinand_driver);

MODULE_DESCRIPTION("SPI NAND driver for Micron");
MODULE_AUTHOR("Henry Pan <hspan@micron.com>, Kamlakant Patel <kamlakant.patel@broadcom.com>");
MODULE_LICENSE("GPL v2");
