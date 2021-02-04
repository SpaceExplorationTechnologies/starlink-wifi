/* Copyright (c) 2013-2014, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
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

#include <stdlib.h>
#include <stdint.h>
#include <mmc.h>
#include <mmc_wrapper.h>
#include <mmc_sdhci.h>
#include <sdhci.h>
#include <ufs.h>
#include <target.h>
#include <string.h>
#include <partition_parser.h>

/*
 * Weak function for UFS.
 * These are needed to avoid link errors for platforms which
 * do not support UFS. Its better to keep this inside the
 * mmc wrapper.
 */
__WEAK int ufs_write(struct ufs_dev *dev, uint64_t data_addr, addr_t in, uint32_t len)
{
	return 0;
}

__WEAK int ufs_read(struct ufs_dev *dev, uint64_t data_addr, addr_t in, uint32_t len)
{
	return 0;
}

__WEAK uint32_t ufs_get_page_size(struct ufs_dev *dev)
{
	return 0;
}

__WEAK uint32_t ufs_get_serial_num(struct ufs_dev *dev)
{
	return 0;
}

__WEAK uint64_t ufs_get_dev_capacity(struct ufs_dev *dev)
{
	return 0;
}

__WEAK uint32_t ufs_get_erase_blk_size(struct ufs_dev *dev)
{
	return 0;
}

__WEAK int ufs_erase(struct ufs_dev* dev, uint64_t start_lba, uint32_t num_blocks)
{
	return 0;
}

__WEAK uint8_t ufs_get_num_of_luns(struct ufs_dev* dev)
{
	return 0;
}

__WEAK uint32_t target_boot_device_emmc()
{
	return 1;
}

/*
 * Function: get mmc card
 * Arg     : None
 * Return  : Pointer to mmc card structure
 * Flow    : Get the card pointer from the device structure
 */
struct mmc_card *get_mmc_card()
{
	void *dev;
	struct mmc_card *card;

	dev = target_mmc_device();
	card = &((struct mmc_device*)dev)->card;

	return card;
}

/*
 * Function: mmc_write
 * Arg     : Data address on card, data length, i/p buffer
 * Return  : 0 on Success, non zero on failure
 * Flow    : Write the data from in to the card
 */
uint32_t mmc_write(uint64_t data_addr, uint32_t data_len, void *in)
{
	uint32_t val = 0;
	int ret = 0;
	uint32_t block_size = 0;
	uint32_t write_size = SDHCI_ADMA_MAX_TRANS_SZ;
	uint8_t *sptr = (uint8_t *)in;
	void *dev;

	dev = target_mmc_device();

	block_size = mmc_get_device_blocksize();

	ASSERT(!(data_addr % block_size));

	if (data_len % block_size)
		data_len = ROUNDUP(data_len, block_size);

	if (target_boot_device_emmc())
	{
		/* TODO: This function is aware of max data that can be
		 * tranferred using sdhci adma mode, need to have a cleaner
		 * implementation to keep this function independent of sdhci
		 * limitations
		 */
		while (data_len > write_size) {
			val = mmc_sdhci_write((struct mmc_device *)dev, (void *)sptr, (data_addr / block_size), (write_size / block_size));
			if (val)
			{
				dprintf(CRITICAL, "Failed Writing block @ %llx\n", (data_addr / block_size));
				return val;
			}
			sptr += write_size;
			data_addr += write_size;
			data_len -= write_size;
		}

		if (data_len)
			val = mmc_sdhci_write((struct mmc_device *)dev, (void *)sptr, (data_addr / block_size), (data_len / block_size));

		if (val)
			dprintf(CRITICAL, "Failed Writing block @ %llx\n", (data_addr / block_size));
	}
	else
	{
		arch_clean_invalidate_cache_range((addr_t)in, data_len);

		ret = ufs_write((struct ufs_dev *)dev, data_addr, (addr_t)in, (data_len / block_size));

		if (ret)
		{
			dprintf(CRITICAL, "Error: UFS write failed writing to block: %llu\n", data_addr);
			val = 1;
		}
	}

	return val;
}

/*
 * Function: mmc_read
 * Arg     : Data address on card, o/p buffer & data length
 * Return  : 0 on Success, non zero on failure
 * Flow    : Read data from the card to out
 */
uint32_t mmc_read(uint64_t data_addr, uint32_t *out, uint32_t data_len)
{
	uint32_t ret = 0;
	uint32_t block_size;
	uint32_t read_size = SDHCI_ADMA_MAX_TRANS_SZ;
	void *dev;
	uint8_t *sptr = (uint8_t *)out;

	dev = target_mmc_device();
	block_size = mmc_get_device_blocksize();

	ASSERT(!(data_addr % block_size));
	ASSERT(!(data_len % block_size));

	if (target_boot_device_emmc())
	{
		/* TODO: This function is aware of max data that can be
		 * tranferred using sdhci adma mode, need to have a cleaner
		 * implementation to keep this function independent of sdhci
		 * limitations
		 */
		while (data_len > read_size) {
			ret = mmc_sdhci_read((struct mmc_device *)dev, (void *)sptr, (data_addr / block_size), (read_size / block_size));
			if (ret)
			{
				dprintf(CRITICAL, "Failed Reading block @ %llx\n", (data_addr / block_size));
				return ret;
			}
			sptr += read_size;
			data_addr += read_size;
			data_len -= read_size;
		}

		if (data_len)
			ret = mmc_sdhci_read((struct mmc_device *)dev, (void *)sptr, (data_addr / block_size), (data_len / block_size));

		if (ret)
			dprintf(CRITICAL, "Failed Reading block @ %llx\n", (data_addr / block_size));
	}
	else
	{
		ret = ufs_read((struct ufs_dev *) dev, data_addr, (addr_t)out, (data_len / block_size));
		if (ret)
		{
			dprintf(CRITICAL, "Error: UFS read failed writing to block: %llu\n", data_addr);
		}

		arch_invalidate_cache_range((addr_t)out, data_len);
	}

	return ret;
}


/*
 * Function: mmc get erase unit size
 * Arg     : None
 * Return  : Returns the erase unit size of the storage
 * Flow    : Get the erase unit size from the card
 */

uint32_t mmc_get_eraseunit_size()
{
	uint32_t erase_unit_sz = 0;

	if (target_boot_device_emmc()) {
		struct mmc_device *dev;
		struct mmc_card *card;

		dev = target_mmc_device();
		card = &dev->card;
		/*
		 * Calculate the erase unit size,
		 * 1. Based on emmc 4.5 spec for emmc card
		 * 2. Use SD Card Status info for SD cards
		 */
		if (MMC_CARD_MMC(card))
		{
			/*
			 * Calculate the erase unit size as per the emmc specification v4.5
			 */
			if (dev->card.ext_csd[MMC_ERASE_GRP_DEF])
				erase_unit_sz = (MMC_HC_ERASE_MULT * dev->card.ext_csd[MMC_HC_ERASE_GRP_SIZE]) / MMC_BLK_SZ;
			else
				erase_unit_sz = (dev->card.csd.erase_grp_size + 1) * (dev->card.csd.erase_grp_mult + 1);
		}
		else
			erase_unit_sz = dev->card.ssr.au_size * dev->card.ssr.num_aus;
	}

	return erase_unit_sz;
}

/*
 * Function: Zero out blk_len blocks at the blk_addr by writing zeros. The
 *           function can be used when we want to erase the blocks not
 *           aligned with the mmc erase group.
 * Arg     : Block address & length
 * Return  : Returns 0
 * Flow    : Erase the card from specified addr
 */

static uint32_t mmc_zero_out(struct mmc_device* dev, uint32_t blk_addr, uint32_t num_blks)
{
	uint32_t *out;
	uint32_t block_size = mmc_get_device_blocksize();
	uint32_t erase_size = (block_size * num_blks);
	uint32_t scratch_size = target_get_max_flash_size();

	dprintf(INFO, "erasing 0x%x:0x%x\n", blk_addr, num_blks);

	if (erase_size <= scratch_size)
	{
		/* Use scratch address if the unaligned blocks */
		out = (uint32_t *) target_get_scratch_address();
	}
	else
	{
		dprintf(CRITICAL, "Erase Fail: Erase size: %u is bigger than scratch region:%u\n", erase_size, scratch_size);
		return 1;
	}

	memset((void *)out, 0, erase_size);

	if (mmc_sdhci_write(dev, out, blk_addr, num_blks))
	{
		dprintf(CRITICAL, "failed to erase the partition: %x\n", blk_addr);
		return 1;
	}

	return 0;
}

/*
 * Function: mmc erase card
 * Arg     : Block address & length
 * Return  : Returns 0
 * Flow    : Erase the card from specified addr
 */
uint32_t mmc_erase_card(uint64_t addr, uint64_t len)
{
	struct mmc_device *dev;
	uint32_t block_size;
	uint32_t unaligned_blks;
	uint32_t head_unit;
	uint32_t tail_unit;
	uint32_t erase_unit_sz;
	uint32_t blk_addr;
	uint32_t blk_count;
	uint64_t blks_to_erase;

	block_size = mmc_get_device_blocksize();

	dev = target_mmc_device();

	ASSERT(!(addr % block_size));
	ASSERT(!(len % block_size));

	if (target_boot_device_emmc())
	{
		erase_unit_sz = mmc_get_eraseunit_size();
		dprintf(SPEW, "erase_unit_sz:0x%x\n", erase_unit_sz);

		blk_addr = addr / block_size;
		blk_count = len / block_size;

		dprintf(INFO, "Erasing card: 0x%x:0x%x\n", blk_addr, blk_count);

		head_unit = blk_addr / erase_unit_sz;
		tail_unit = (blk_addr + blk_count - 1) / erase_unit_sz;

		if (tail_unit - head_unit <= 1)
		{
			dprintf(INFO, "SDHCI unit erase not required\n");
			return mmc_zero_out(dev, blk_addr, blk_count);
		}

		unaligned_blks = erase_unit_sz - (blk_addr % erase_unit_sz);

		if (unaligned_blks < erase_unit_sz)
		{
			dprintf(SPEW, "Handling unaligned head blocks\n");
			if (mmc_zero_out(dev, blk_addr, unaligned_blks))
				return 1;

			blk_addr += unaligned_blks;
			blk_count -= unaligned_blks;
		}

		unaligned_blks = blk_count % erase_unit_sz;
		blks_to_erase = blk_count - unaligned_blks;

		dprintf(SPEW, "Performing SDHCI erase: 0x%x:0x%llx\n", blk_addr, blks_to_erase);
		if (mmc_sdhci_erase((struct mmc_device *)dev, blk_addr, blks_to_erase * block_size))
		{
			dprintf(CRITICAL, "MMC erase failed\n");
			return 1;
		}

		blk_addr += blks_to_erase;

		if (unaligned_blks)
		{
			dprintf(SPEW, "Handling unaligned tail blocks\n");
			if (mmc_zero_out(dev, blk_addr, unaligned_blks))
				return 1;
		}

	}
	else
	{
		if(ufs_erase((struct ufs_dev *)dev, addr, (len / block_size)))
		{
			dprintf(CRITICAL, "mmc_erase_card: UFS erase failed\n");
			return 1;
		}
	}

	return 0;
}

/*
 * Function: mmc get psn
 * Arg     : None
 * Return  : Returns the product serial number
 * Flow    : Get the PSN from card
 */
uint32_t mmc_get_psn(void)
{
	if (target_boot_device_emmc())
	{
		struct mmc_card *card;

		card = get_mmc_card();

		return card->cid.psn;
	}
	else
	{
		void *dev;

		dev = target_mmc_device();

		return ufs_get_serial_num((struct ufs_dev *)dev);
	}
}

/*
 * Function: mmc get capacity
 * Arg     : None
 * Return  : Returns the density of the emmc card
 * Flow    : Get the density from card
 */
uint64_t mmc_get_device_capacity()
{
	if (target_boot_device_emmc())
	{
		struct mmc_card *card;

		card = get_mmc_card();

		return card->capacity;
	}
	else
	{
		void *dev;

		dev = target_mmc_device();

		return ufs_get_dev_capacity((struct ufs_dev *)dev);
	}
}

/*
 * Function: mmc get blocksize
 * Arg     : None
 * Return  : Returns the block size of the storage
 * Flow    : Get the block size form the card
 */
uint32_t mmc_get_device_blocksize()
{
	if (target_boot_device_emmc())
	{
		struct mmc_card *card;

		card = get_mmc_card();

		return card->block_size;
	}
	else
	{
		void *dev;

		dev = target_mmc_device();

		return ufs_get_page_size((struct ufs_dev *)dev);
	}
}

/*
 * Function: storage page size
 * Arg     : None
 * Return  : Returns the page size for the card
 * Flow    : Get the page size for storage
 */
uint32_t mmc_page_size()
{
	if (target_boot_device_emmc())
	{
		return BOARD_KERNEL_PAGESIZE;
	}
	else
	{
		void *dev;

		dev = target_mmc_device();

		return ufs_get_page_size((struct ufs_dev *)dev);
	}
}

/*
 * Function: mmc device sleep
 * Arg     : None
 * Return  : Clean up function for storage
 * Flow    : Put the mmc card to sleep
 */
void mmc_device_sleep()
{
	void *dev;
	dev = target_mmc_device();

	if (target_boot_device_emmc())
	{
		mmc_put_card_to_sleep((struct mmc_device *)dev);
	}
}

/*
 * Function     : mmc set LUN for ufs
 * Arg          : LUN number
 * Return type  : void
 */
void mmc_set_lun(uint8_t lun)
{
	void *dev;
	dev = target_mmc_device();

	if (!target_boot_device_emmc())
	{
		((struct ufs_dev*)dev)->current_lun = lun;
	}
}

/*
 * Function     : mmc get LUN from ufs
 * Arg          : LUN number
 * Return type  : lun number for UFS and 0 for emmc
 */
uint8_t mmc_get_lun(void)
{
	void *dev;
	uint8_t lun=0;

	dev = target_mmc_device();

	if (!target_boot_device_emmc())
	{
		lun = ((struct ufs_dev*)dev)->current_lun;
	}

	return lun;
}

void mmc_read_partition_table(uint8_t arg)
{
	void *dev;
	uint8_t lun = 0;
	uint8_t max_luns;
	struct mmc_boot_host *mmc_host = get_mmc_host();
	struct mmc_card *mmc_card = get_mmc_card();
	dev = target_mmc_device();

	if(!target_boot_device_emmc())
	{
		max_luns = ufs_get_num_of_luns((struct ufs_dev*)dev);

		ASSERT(max_luns);

		for(lun = arg; lun < max_luns; lun++)
		{
			mmc_set_lun(lun);
			if(partition_read_table(mmc_host, (struct mmc_boot_card *)mmc_card))
			{
				dprintf(CRITICAL, "Error reading the partition table info for lun %d\n", lun);
			}
		}
	}
	else
	{
		if(partition_read_table(mmc_host, (struct mmc_boot_card *)mmc_card))
		{
			dprintf(CRITICAL, "Error reading the partition table info\n");
		}
	}
}

/*
 * Reads a data of data_len from the address specified. data_len
 * should be multiple of block size for block data transfer.
 */
unsigned int
mmc_boot_read_from_card(struct mmc_boot_host *host,
			struct mmc_boot_card *card,
			unsigned long long data_addr,
			unsigned int data_len, unsigned int *out)
{
	if (data_len % MMC_BLK_SZ) {
		dprintf(CRITICAL, "ERROR: mmc read data length is not a multiple of %d bytes\n",
			MMC_BLK_SZ);
		return 0;
	}

	return mmc_read(data_addr, out, data_len);
}

struct mmc_boot_host *get_mmc_host(void)
{
	return NULL;
}

void set_sdc_power_ctrl(){}

void mmc_boot_mci_clk_disable(){}

void mmc_boot_mci_clk_enable(){}

__WEAK void clock_config_cdc(uint8_t slot){}

#if defined(WITH_LIB_CONSOLE)
#include <lib/console.h>

#define mmc_r_help	"read dest-addr start size\n"
#define mmc_w_help	"write src-addr start size\n"
#define mmc_e_help	"erase start size\n"
#define mmc_help	mmc_r_help mmc_w_help mmc_e_help

#define uarg(x)		(argv[x].u)
#define ullarg(x)	((unsigned long long)argv[x].u)

static int cmd_mmc(int argc, const cmd_args *argv)
{
	unsigned long long start;
	unsigned size;
	unsigned *ptr;

	int m = -1;	/* multiplier */

	/* size is in terms of bytes ... */
	if (!strcmp(argv[1].str, "bread") ||
	    !strcmp(argv[1].str, "bwrite") ||
	    !strcmp(argv[1].str, "berase")) {
		strlcpy((char *)argv[1].str, argv[1].str + 1,
				strlen(argv[1].str));
		m = 1;
	}

	if (strcmp(argv[1].str, "read") == 0) {
		if (argc != 5) {
			printf(mmc_r_help);
			return -1;
		}

		if (m == -1)
			m = 512;

		start = ullarg(3) * m;
		size = uarg(4) * m;
		ptr = (unsigned *)uarg(2);

		if (size % 512)
			printf("Warning: Will round-up size to 512\n");

		printf("mmc_read(0x%x, 0x%x, 0x%x)\n", uarg(3), uarg(2), uarg(4));

		if (mmc_read(start, ptr, size) != 0) {
			printf("Read failed\n");
			return -1;
		}
	} else if (strcmp(argv[1].str, "write") == 0) {
		if (argc != 5) {
			printf(mmc_w_help);
			return -1;
		}

		if (m == -1)
			m = 512;

		start = ullarg(3) * m;
		size = uarg(4) * m;
		ptr = (unsigned *)uarg(2);

		if (size % 512)
			printf("Warning: Will round-up size to 512\n");

		printf("mmc_write(0x%x, 0x%x, 0x%x)\n", uarg(3), uarg(4), uarg(2));

		if (mmc_write(start, size, ptr) != 0) {
			printf("Write failed\n");
			return -1;
		}
	} else if (strcmp(argv[1].str, "erase") == 0) {
		if (argc != 4) {
			printf(mmc_e_help);
			return -1;
		}

		if (m == -1)
			m = 512;

		start = ullarg(2) * m;
		size = uarg(3) * m;

		if (size % 512)
			printf("Warning: Will round-up size to 512\n");

		printf("mmc_erase_card(0x%x, 0x%x)\n", uarg(2), uarg(3));

		if (mmc_erase_card(start, size) != 0) {
			printf("Erase failed\n");
			return -1;
		}
	} else {
		printf("%.16s", argv[1].str);
		printf(mmc_help);
		return -1;
	}

	return 0;
}

STATIC_COMMAND_START
        { "mmc", mmc_help, &cmd_mmc },
STATIC_COMMAND_END(mmc);

#endif /* defined(WITH_LIB_CONSOLE) */
