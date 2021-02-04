/*
 * Copyright (c) 2015-2018 The Linux Foundation. All rights reserved.

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <common.h>
#include <mmc.h>
#include <nand.h>
#include <spi.h>
#include <spi_flash.h>
#include <usb.h>
#include <fat.h>
#include <asm/errno.h>
#include <asm/io.h>
#include <asm/arch-qca-common/scm.h>
#include <asm/arch-qca-common/iomap.h>
#include <asm/arch-qca-common/qca_common.h>

#define MAX_TFTP_SIZE 0x40000000
#define MAX_SEARCH_PARTITIONS 16

#define MAX_UNAME_SIZE			1024
#define QCA_WDT_SCM_TLV_TYPE_SIZE	1
#define QCA_WDT_SCM_TLV_LEN_SIZE	2
#define QCA_WDT_SCM_TLV_TYPE_LEN_SIZE (QCA_WDT_SCM_TLV_TYPE_SIZE +\
						QCA_WDT_SCM_TLV_LEN_SIZE)
#define MAX_NAND_PAGE_SIZE		2048
#define MAX_EMMC_BLK_LEN		1024

#ifndef CONFIG_CRASHDUMP_SPI_SPEED
#define CONFIG_CRASHDUMP_SPI_SPEED	1000000
#endif

#ifndef CONFIG_CRASHDUMP_SPI_MODE
#define CONFIG_CRASHDUMP_SPI_MODE	SPI_MODE_3
#endif

#ifndef CONFIG_SYS_MMC_CRASHDUMP_DEV
#define CONFIG_SYS_MMC_CRASHDUMP_DEV	0
#endif

#define CONFIG_TZ_SIZE			0x400000
DECLARE_GLOBAL_DATA_PTR;
static qca_smem_flash_info_t *sfi = &qca_smem_flash_info;
/* USB device id and part index used by usbdump */
static int usb_dev_indx, usb_dev_part;
int crashdump_tlv_count=0;

enum {
    /*Basic DDR segments */
	QCA_WDT_LOG_DUMP_TYPE_INVALID,
	QCA_WDT_LOG_DUMP_TYPE_UNAME,
	QCA_WDT_LOG_DUMP_TYPE_DMESG,
	QCA_WDT_LOG_DUMP_TYPE_LEVEL1_PT,
	/* Module structures are in highmem zone*/
	QCA_WDT_LOG_DUMP_TYPE_WLAN_MOD,
	QCA_WDT_LOG_DUMP_TYPE_WLAN_MOD_INFO,
	QCA_WDT_LOG_DUMP_TYPE_EMPTY,
};
/* This will be used for parsing the TLV data */
struct qca_wdt_scm_tlv_msg {
      unsigned char *msg_buffer;
      unsigned char *cur_msg_buffer_pos;
      unsigned int len;
};

/* Structure to hold crashdump related pointers */
struct st_tlv_info {
    uint64_t start;
    uint64_t size;
};
/* Actual crashdump related data */
struct qca_wdt_crashdump_data {
	unsigned char uname[MAX_UNAME_SIZE];
	unsigned int uname_length;
	unsigned char *cpu_context;
	unsigned char *log_buf;
	unsigned int log_buf_len;
	unsigned char *pt_start;
	unsigned int pt_len;
};

/* Context for NAND Flash memory */
struct crashdump_flash_nand_cxt {
       loff_t start_crashdump_offset;
       loff_t cur_crashdump_offset;
       int cur_page_data_len;
       int write_size;
       unsigned char temp_data[MAX_NAND_PAGE_SIZE];
};

#ifdef CONFIG_QCA_SPI
/* Context for SPI NOR Flash memory */
struct crashdump_flash_spi_cxt {
       loff_t start_crashdump_offset;
       loff_t cur_crashdump_offset;
};
#endif

#ifdef CONFIG_QCA_MMC
/* Context for EMMC Flash memory */
struct crashdump_flash_emmc_cxt {
       loff_t start_crashdump_offset;
       loff_t cur_crashdump_offset;
       int cur_blk_data_len;
       int write_size;
       unsigned char temp_data[MAX_EMMC_BLK_LEN];
};
#endif


static struct crashdump_flash_nand_cxt crashdump_nand_cnxt;
#ifdef CONFIG_QCA_SPI
static struct spi_flash *crashdump_spi_flash;
static struct crashdump_flash_spi_cxt crashdump_flash_spi_cnxt;
#endif
#ifdef CONFIG_QCA_MMC
static struct mmc *mmc;
static struct crashdump_flash_emmc_cxt crashdump_emmc_cnxt;
#endif
static struct qca_wdt_crashdump_data g_crashdump_data;
struct qca_wdt_scm_tlv_msg tlv_msg ;
__weak int scm_set_boot_addr(bool enable_sec_core)
{
	return -1;
}

static int krait_release_secondary(void)
{
	writel(0xa4, CPU1_APCS_SAW2_VCTL);
	barrier();
	udelay(512);

	writel(0x109, CPU1_APCS_CPU_PWR_CTL);
	writel(0x101, CPU1_APCS_CPU_PWR_CTL);
	barrier();
	udelay(1);

	writel(0x121, CPU1_APCS_CPU_PWR_CTL);
	barrier();
	udelay(2);

	writel(0x120, CPU1_APCS_CPU_PWR_CTL);
	barrier();
	udelay(2);

	writel(0x100, CPU1_APCS_CPU_PWR_CTL);
	barrier();
	udelay(100);

	writel(0x180, CPU1_APCS_CPU_PWR_CTL);
	barrier();

	return 0;
}

static int dump_to_dst (int is_aligned_access, uint32_t memaddr, uint32_t size, char *name)
{
	char runcmd[128];
	char *usb_dump = NULL;
	ulong is_usb_dump = 0;
	int ret = 0;

	usb_dump = getenv("dump_to_usb");
	if (usb_dump) {
		ret = str2long(usb_dump, &is_usb_dump);
		if (!ret) {
			printf("\nError: Failed to decode dump_to_usb value\n");
			return -EINVAL;
		}
	}

	if (is_aligned_access) {
		if (IPQ_TEMP_DUMP_ADDR) {
			snprintf(runcmd, sizeof(runcmd), "cp.l 0x%x 0x%x 0x%x", memaddr,
					IPQ_TEMP_DUMP_ADDR, size / 4);
			if (run_command(runcmd, 0) != CMD_RET_SUCCESS)
				return CMD_RET_FAILURE;

			memaddr = IPQ_TEMP_DUMP_ADDR;
		} else {
			printf("%s  needs aligned access and temp address is not defined. Skipping...", name);
			return CMD_RET_FAILURE;
		}
	}

	if (is_usb_dump == 1)
		snprintf(runcmd, sizeof(runcmd), "fatwrite usb %x:%x 0x%x %s 0x%x",
					usb_dev_indx, usb_dev_part, memaddr, name, size);
	else {
		char *dumpdir;
		dumpdir = getenv("dumpdir");
		if (dumpdir != NULL) {
			printf("Using directory %s in TFTP server\n", dumpdir);
		} else {
			dumpdir = "";
			printf("Env 'dumpdir' not set. Using / dir in TFTP server\n");
		}

		snprintf(runcmd, sizeof(runcmd), "tftpput 0x%x 0x%x %s/%s",
						memaddr, size, dumpdir, name);
	}

	if (run_command(runcmd, 0) != CMD_RET_SUCCESS)
		return CMD_RET_FAILURE;

	return CMD_RET_SUCCESS;

}

/* Extracts the type and length in TLV for current offset */
static int qca_wdt_scm_extract_tlv_info(
                struct qca_wdt_scm_tlv_msg *scm_tlv_msg,
                unsigned char *type,
                unsigned int *size)
{
	unsigned char *x = scm_tlv_msg->cur_msg_buffer_pos;
	unsigned char *y = scm_tlv_msg->msg_buffer +
                                scm_tlv_msg->len;

        if ((x + QCA_WDT_SCM_TLV_TYPE_LEN_SIZE) >= y)
                return -EINVAL;

        *type = x[0];
        *size = x[1] | (x[2] << 8);
        return 0;
}

/* Extracts the value from TLV for current offset */
static int qca_wdt_scm_extract_tlv_data(
		struct qca_wdt_scm_tlv_msg *scm_tlv_msg,
		unsigned char *data,
		unsigned int size)
{
	unsigned char *x = scm_tlv_msg->cur_msg_buffer_pos;
	unsigned char *y = scm_tlv_msg->msg_buffer + scm_tlv_msg->len;

	if ((x + QCA_WDT_SCM_TLV_TYPE_LEN_SIZE + size) >= y)
		return -EINVAL;

	memcpy(data, x + 3, size);

	scm_tlv_msg->cur_msg_buffer_pos +=
		(size + QCA_WDT_SCM_TLV_TYPE_LEN_SIZE);
	return 0;
}

/*
* This function parses the TLV message and stores the actual values
* in crashdump_data. For each TLV, It first determines the type and
* length, then it extracts the actual value and stores in the appropriate
* field in crashdump_data.
*/
static int qca_wdt_extract_crashdump_data(
		struct qca_wdt_scm_tlv_msg *scm_tlv_msg,
		struct qca_wdt_crashdump_data *crashdump_data)
{
	unsigned char cur_type = QCA_WDT_LOG_DUMP_TYPE_INVALID;
	unsigned int cur_size = 0;
	int ret_val = 0;
	struct st_tlv_info tlv_info;
	int static_enum_count = 0;
	int tlv_size = 0;

	while (static_enum_count < 3) {
		ret_val = qca_wdt_scm_extract_tlv_info(scm_tlv_msg,
			&cur_type, &cur_size);
		if (!ret_val && cur_type == QCA_WDT_LOG_DUMP_TYPE_UNAME ){
			crashdump_data->uname_length = cur_size;
			ret_val = qca_wdt_scm_extract_tlv_data(scm_tlv_msg,
					crashdump_data->uname, cur_size);
			crashdump_tlv_count++;
			static_enum_count++;
		}else if (!ret_val && cur_type == QCA_WDT_LOG_DUMP_TYPE_DMESG){
			ret_val = qca_wdt_scm_extract_tlv_data(scm_tlv_msg,
				(unsigned char *)&tlv_info,
				cur_size);
			if (!ret_val) {
				crashdump_data->log_buf =(unsigned char *)(uintptr_t)tlv_info.start;
				crashdump_data->log_buf_len = *(uint32_t *)(uintptr_t)tlv_info.size;
		         }
			crashdump_tlv_count++;
			static_enum_count++;
		}else if (!ret_val && cur_type == QCA_WDT_LOG_DUMP_TYPE_LEVEL1_PT){
			ret_val = qca_wdt_scm_extract_tlv_data(scm_tlv_msg,(unsigned char *)&tlv_info,cur_size);
			if (!ret_val) {
				crashdump_data->pt_start =(unsigned char *)(uintptr_t)tlv_info.start;
				crashdump_data->pt_len = tlv_info.size;
			}
			crashdump_tlv_count++;
			static_enum_count++;
		}
		else if(!ret_val && cur_type == QCA_WDT_LOG_DUMP_TYPE_WLAN_MOD) {
			tlv_size = (cur_size + QCA_WDT_SCM_TLV_TYPE_LEN_SIZE);
			scm_tlv_msg->cur_msg_buffer_pos += tlv_size;
		}
	}
	return ret_val;
}

uint32_t dump_minimal(struct dumpinfo_t *dumpinfo, int indx) {

	if (g_crashdump_data.pt_start &&
		!strncmp(dumpinfo[indx].name,
			"PT.BIN", strlen("PT.BIN"))) {
		dumpinfo[indx].start =(uintptr_t) g_crashdump_data.pt_start;
		dumpinfo[indx].size = g_crashdump_data.pt_len;
	} else if (g_crashdump_data.log_buf &&
		!strncmp(dumpinfo[indx].name,
		"DMESG.BIN", strlen("DMESG.BIN"))) {
		dumpinfo[indx].start =(uintptr_t) g_crashdump_data.log_buf;
		dumpinfo[indx].size = g_crashdump_data.log_buf_len;
	} else if (!strncmp(dumpinfo[indx].name,
		"UNAME", strlen("UNAME"))) {
		dumpinfo[indx].start =(uintptr_t) g_crashdump_data.uname;
		dumpinfo[indx].size =
		g_crashdump_data.uname_length;
	} else if (!strncmp(dumpinfo[indx].name,
		"CPU_INFO", strlen("CPU_INFO"))) {
		dumpinfo[indx].start =
		(uintptr_t)g_crashdump_data.cpu_context;
		dumpinfo[indx].size =
		CONFIG_CPU_CONTEXT_DUMP_SIZE;
	}
	return dumpinfo[indx].start;
}

static int dump_wlan_segments(struct dumpinfo_t *dumpinfo, int indx)
{
	uint32_t memaddr;
	struct qca_wdt_scm_tlv_msg *scm_tlv_msg = &tlv_msg;
	unsigned char cur_type = QCA_WDT_LOG_DUMP_TYPE_WLAN_MOD;
	unsigned int cur_size = 0;
	int ret_val = 0;
	int tlv_size = 0;
	struct st_tlv_info tlv_info;
	uint32_t wlan_tlv_size;

	char wlan_segment_name[32];

	if(strncmp(dumpinfo[indx].name, "WLAN_MOD" ,strlen("WLAN_MOD"))) {
		return CMD_RET_FAILURE;
	}

	scm_tlv_msg->cur_msg_buffer_pos = scm_tlv_msg->msg_buffer;

	do {
		ret_val = qca_wdt_scm_extract_tlv_info(scm_tlv_msg,
			&cur_type, &cur_size);

		/* Each Dump segment is represented by a TLV tuple comprising of
		three TLVs representing the type,size and physical addresses of
		the data segments and corresponding PMD and PTE entries.
		QCA_WDT_LOG_DUMP_TYPE_EMPTY type indicates that the TLV tuple has
		been invalidated. When type QCA_WDT_LOG_DUMP_TYPE_EMPTY is encountered,
		we skip over the TLV touple by moving the current massage buffer pointer
		ahead by three TLVs */

		if(cur_type == QCA_WDT_LOG_DUMP_TYPE_EMPTY) {
			tlv_size = (cur_size + QCA_WDT_SCM_TLV_TYPE_LEN_SIZE);
			scm_tlv_msg->cur_msg_buffer_pos += (3 * tlv_size);
		}

		if (!ret_val && ( cur_type == QCA_WDT_LOG_DUMP_TYPE_WLAN_MOD ||
						cur_type == QCA_WDT_LOG_DUMP_TYPE_WLAN_MOD_INFO )) {
			ret_val = qca_wdt_scm_extract_tlv_data(scm_tlv_msg,
				(unsigned char *)&tlv_info,cur_size);
			memaddr = tlv_info.start;

			if (cur_type == QCA_WDT_LOG_DUMP_TYPE_WLAN_MOD_INFO) {
				snprintf(wlan_segment_name,	sizeof(wlan_segment_name),
							 "MOD_INFO.txt");
				wlan_tlv_size = *(uint32_t *)(uintptr_t)tlv_info.size;
			} else {
				snprintf(wlan_segment_name,
						 sizeof(wlan_segment_name), "%lx.BIN",(long unsigned int)memaddr);
				 wlan_tlv_size = tlv_info.size;
			}

			ret_val = dump_to_dst (dumpinfo[indx].is_aligned_access,memaddr,
						wlan_tlv_size, wlan_segment_name);
			crashdump_tlv_count++;
			udelay(10000); /* give some delay for server */
			if (ret_val == CMD_RET_FAILURE)
				return CMD_RET_FAILURE;
		} else {
            tlv_size = (cur_size + QCA_WDT_SCM_TLV_TYPE_LEN_SIZE);
            scm_tlv_msg->cur_msg_buffer_pos += tlv_size;
        }
	}while (cur_type != QCA_WDT_LOG_DUMP_TYPE_INVALID);

	printf("\nMinidump: Dumped %d TLVs\n",crashdump_tlv_count);
	return CMD_RET_SUCCESS;
};


static int do_dumpqca_data(unsigned int dump_level)
{
	uint32_t memaddr;
	uint32_t remaining;
	int indx;
	int ebi_indx = 0;
	int ret = CMD_RET_FAILURE;
	char buf = 1;
	struct dumpinfo_t *dumpinfo = dumpinfo_n;
	int dump_entries = dump_entries_n;
	char wlan_segment_name[32];
	char *usb_dump = NULL;
	ulong is_usb_dump = 0;

	usb_dump = getenv("dump_to_usb");
	if (usb_dump) {
		ret = str2long(usb_dump, &is_usb_dump);
		if (!ret) {
			printf("\nError: Failed to decode dump_to_usb value\n");
			return -EINVAL;
		}
	}

	if (is_usb_dump != 1) {
		char *serverip = NULL;
		/* dump to root of TFTP server if none specified */
		serverip = getenv("serverip");
		if (serverip != NULL) {
			printf("Using serverip from env %s\n", serverip);
		} else {
			printf("\nServer ip not found, run dhcp or configure\n");
			return CMD_RET_FAILURE;
		}
	}
	else {
#if defined(CONFIG_USB_STORAGE) && defined(CONFIG_FS_FAT)
		static block_dev_desc_t *stor_dev;
		disk_partition_t info;
		int dev_indx, max_dev_avail = 0;
		int part_indx = 0, part = -1;
		int fat_fs = 0;
		char dev_str[5]; /* dev:part */

		if(run_command("usb start", 0) != CMD_RET_SUCCESS) {
			printf("USB enumeration failed\n");
			return CMD_RET_FAILURE;
		}

		max_dev_avail = usb_max_dev_avail();
		for(dev_indx = 0; (fat_fs != 1) && (dev_indx < max_dev_avail); dev_indx++) {

			// get storage device
			stor_dev = usb_stor_get_dev(dev_indx);
			if(stor_dev == NULL) {
				printf("No storage device available\n");
				goto stop_dump;
			}

			// get valid partition
			for(part_indx = 1; part_indx <= MAX_SEARCH_PARTITIONS; part_indx++) {

				snprintf(dev_str, sizeof(dev_str)+1, "%x:%x", dev_indx, part_indx);
				part = get_device_and_partition("usb", dev_str, &stor_dev, &info, 1);

				if (fat_set_blk_dev(stor_dev, &info) == 0) {
					fat_fs = 1;
					printf("Selected Device for USBdump:\n");
					dev_print(stor_dev);
					break;
				}
			}

			if (part < 0)
				printf("No valid partition available for device %d\n", dev_indx);
		}

		if (fat_fs == 1)
			dev_indx = dev_indx - 1;
		if (dev_indx == max_dev_avail) {
			printf("No devices available for usbdump collection\n");
			goto stop_dump;
		}
		usb_dev_indx = dev_indx;
		usb_dev_part = part_indx;
		printf("Collecting crashdump on Partition %d of USB device %d\n", usb_dev_part, usb_dev_indx);
#else
		printf("\nWarning: Enable FAT FS configs for USBdump\n");
#endif
	}

	ret = qca_scm_call(SCM_SVC_FUSE,
			   QFPROM_IS_AUTHENTICATE_CMD, &buf, sizeof(char));
	if (ret == 0 && buf == 1) {
		dumpinfo = dumpinfo_s;
		dump_entries = dump_entries_s;
	}

	if (scm_set_boot_addr(false) == 0) {
		/* Pull Core-1 out of reset, iff scm call succeeds */
		krait_release_secondary();
	}

	for (indx = 0; indx < dump_entries; indx++) {
		if (dump_level != dumpinfo[indx].dump_level)
			continue;
		printf("\nProcessing %s:", dumpinfo[indx].name);

		if (dumpinfo[indx].is_redirected) {
			memaddr = *((uint32_t *)(dumpinfo[indx].start));
			if (!memaddr) {
				printf("Crashdump for %s is not available.\n",
					dumpinfo[indx].name);
				continue;
			}
		} else {
			memaddr = dumpinfo[indx].start;
		}

		if (dumpinfo[indx].offset)
			memaddr += dumpinfo[indx].offset;

		if (!strncmp(dumpinfo[indx].name, "EBICS", strlen("EBICS")))
		{
			if (!strncmp(dumpinfo[indx].name,
				     "EBICS0", strlen("EBICS0")))
				dumpinfo[indx].size = gd->ram_size;

			if (!strncmp(dumpinfo[indx].name,
				     "EBICS_S1", strlen("EBICS_S1")))
				dumpinfo[indx].size = gd->ram_size
						      - dumpinfo[indx - 1].size
						      - CONFIG_TZ_SIZE;

			if (is_usb_dump == 1) {
				ret = dump_to_dst (dumpinfo[indx].is_aligned_access, memaddr, dumpinfo[indx].size, dumpinfo[indx].name);
				if (ret == CMD_RET_FAILURE) {
					goto stop_dump;
				}
			}
			else {
				remaining = dumpinfo[indx].size;
				while (remaining > 0) {
					snprintf(dumpinfo[indx].name, sizeof(dumpinfo[indx].name), "EBICS%d.BIN", ebi_indx);

					if (remaining > MAX_TFTP_SIZE) {
						dumpinfo[indx].size = MAX_TFTP_SIZE;
					}
					else {
						dumpinfo[indx].size = remaining;
					}
					ret = dump_to_dst (dumpinfo[indx].is_aligned_access, memaddr, dumpinfo[indx].size, dumpinfo[indx].name);
					if (ret == CMD_RET_FAILURE)
						goto stop_dump;

					memaddr += dumpinfo[indx].size;
					remaining -= dumpinfo[indx].size;
					ebi_indx++;
				}
			}
		}
		else
		{
			if (dumpinfo[indx].dump_level == MINIMAL_DUMP )
				memaddr = dump_minimal(dumpinfo, indx);
			if (dumpinfo[indx].size && memaddr) {
				if(dumpinfo[indx].dump_level == MINIMAL_DUMP){
					snprintf(wlan_segment_name, sizeof(wlan_segment_name), "%lx.BIN",(long unsigned int)memaddr);
					ret = dump_to_dst (dumpinfo[indx].is_aligned_access, memaddr, dumpinfo[indx].size, wlan_segment_name);
					if (ret == CMD_RET_FAILURE)
						goto stop_dump;
				}
				else {
					ret = dump_to_dst (dumpinfo[indx].is_aligned_access, memaddr, dumpinfo[indx].size, dumpinfo[indx].name);
					if (ret == CMD_RET_FAILURE)
						goto stop_dump;
				}
			}
			else {
				ret = dump_wlan_segments(dumpinfo, indx);
				if (ret == CMD_RET_FAILURE)
					goto stop_dump;
			}
		}
	}

stop_dump:
#if defined(CONFIG_USB_STORAGE) && defined(CONFIG_FS_FAT)
	if (is_usb_dump == 1)
		run_command("usb stop", 0);
#endif
	return ret;
}

/**
 * Inovke the dump routine and in case of failure, do not stop unless the user
 * requested to stop
 */
void dump_func(unsigned int dump_level)
{
	uint64_t etime;
	uint64_t ptime;
	int ping_status = 0;
	char *serverip = NULL, *forced_dump = NULL;
	char runcmd[50] = {0};

#ifdef CONFIG_IPQ_ETH_INIT_DEFER
	puts("\nNet:   ");
	eth_initialize();
#endif

	forced_dump = getenv("force_collect_dump");
	if (forced_dump) {
		serverip = getenv("serverip");
		if (serverip != NULL) {
			printf("Using serverip from env %s\n", serverip);
		} else {
			printf("\nServer ip not found, run dhcp or configure\n");
			goto reset;
		}
		printf("Trying to ping server.....\n");
		snprintf(runcmd, sizeof(runcmd), "ping %s", serverip);
		ptime = get_timer_masked() + (10 * CONFIG_SYS_HZ);
		while (get_timer_masked() <= ptime) {
			if (run_command(runcmd, 0) == CMD_RET_SUCCESS) {
				ping_status = 1;
				break;
			}
			mdelay(500);
		}
		if (ping_status != 1) {
			printf("Ping failed\n");
			goto reset;
		}
		if (do_dumpqca_data(dump_level) == CMD_RET_FAILURE)
			printf("Crashdump saving failed!\n");
		goto reset;
	} else {
		etime = get_timer_masked() + (10 * CONFIG_SYS_HZ);
		printf("\nHit any key within 10s to stop dump activity...");
		while (!tstc()) {       /* while no incoming data */
			if (get_timer_masked() >= etime) {
				if (do_dumpqca_data(dump_level) == CMD_RET_FAILURE)
					printf("Crashdump saving failed!\n");
				break;
			}
		}
	}
	/* reset the system, some images might not be loaded
	 * when crashmagic is found
	 */
reset:
	reset_board();
}

/*
* Init function for NAND flash writing. It intializes its own context
* and erases the required sectors
*/
int init_crashdump_nand_flash_write(void *cnxt, loff_t offset,
					unsigned int total_size)
{
	nand_erase_options_t nand_erase_options;
	struct crashdump_flash_nand_cxt *nand_cnxt = cnxt;
	int ret;

	nand_cnxt->start_crashdump_offset = offset;
	nand_cnxt->cur_crashdump_offset = offset;
	nand_cnxt->cur_page_data_len = 0;
	nand_cnxt->write_size = nand_info[0].writesize;

	if (nand_info[0].writesize > MAX_NAND_PAGE_SIZE) {
		printf("nand page write size is more than configured size\n");
		return -ENOMEM;
	}

	memset(&nand_erase_options, 0, sizeof(nand_erase_options));

	nand_erase_options.length = total_size;
	nand_erase_options.offset = offset;

	ret = nand_erase_opts(&nand_info[0],
			&nand_erase_options);
	if (ret)
		return ret;

	return 0;
}

/*
* Deinit function for NAND flash writing. It writes the remaining data
* stored in temp buffer to NAND.
*/
int deinit_crashdump_nand_flash_write(void *cnxt)
{
	struct crashdump_flash_nand_cxt *nand_cnxt = cnxt;
	unsigned int cur_nand_write_len = nand_cnxt->cur_page_data_len;
	int ret_val = 0;
	int remaining_bytes = nand_cnxt->write_size -
			nand_cnxt->cur_page_data_len;

	if (cur_nand_write_len) {
		/*
		* Make the write data in multiple of page write size
		* and write remaining data in NAND flash
		*/
		memset(nand_cnxt->temp_data + nand_cnxt->cur_page_data_len,
			0xFF, remaining_bytes);

		cur_nand_write_len = nand_cnxt->write_size;
		ret_val = nand_write(&nand_info[0],
				nand_cnxt->cur_crashdump_offset,
				&cur_nand_write_len, nand_cnxt->temp_data);
	}

	return ret_val;
}

/*
* Write function for NAND flash. NAND writing works on page basis so
* this function writes the data in mulitple of page size and stores the
* remaining data in temp buffer. This temp buffer data will be appended
* with next write data.
*/
int crashdump_nand_flash_write_data(void *cnxt,
		unsigned char *data, unsigned int size)
{
	struct crashdump_flash_nand_cxt *nand_cnxt = cnxt;
	unsigned char *cur_data_pos = data;
	unsigned int remaining_bytes;
	unsigned int total_bytes;
	unsigned int cur_nand_write_len;
	unsigned int remaining_len_cur_page;
	int ret_val;

	remaining_bytes = total_bytes = nand_cnxt->cur_page_data_len + size;

	/*
	* Check for minimum write size and store the data in temp buffer if
	* the total size is less than it
	*/
	if (total_bytes < nand_cnxt->write_size) {
		memcpy(nand_cnxt->temp_data + nand_cnxt->cur_page_data_len,
					data, size);
		nand_cnxt->cur_page_data_len += size;

		return 0;
	}

	/*
	* Append the remaining length of data for complete nand page write in
	* currently stored data and do the nand write
	*/
	remaining_len_cur_page = nand_cnxt->write_size -
			nand_cnxt->cur_page_data_len;
	cur_nand_write_len = nand_cnxt->write_size;

	memcpy(nand_cnxt->temp_data + nand_cnxt->cur_page_data_len, data,
			remaining_len_cur_page);

	ret_val = nand_write(&nand_info[0], nand_cnxt->cur_crashdump_offset,
				&cur_nand_write_len,
				nand_cnxt->temp_data);

	if (ret_val)
		return ret_val;

	cur_data_pos += remaining_len_cur_page;
	nand_cnxt->cur_crashdump_offset += cur_nand_write_len;

	/*
	* Calculate the write length in multiple of page length and do the nand
	* write for same length
	*/
	cur_nand_write_len = ((data + size - cur_data_pos) /
				nand_cnxt->write_size) * nand_cnxt->write_size;

	if (cur_nand_write_len > 0) {
		ret_val = nand_write(&nand_info[0],
				nand_cnxt->cur_crashdump_offset,
				&cur_nand_write_len,
				cur_data_pos);

		if (ret_val)
			return ret_val;
	}

	cur_data_pos += cur_nand_write_len;
	nand_cnxt->cur_crashdump_offset += cur_nand_write_len;

	/* Store the remaining data in temp data */
	remaining_bytes = data + size - cur_data_pos;

	memcpy(nand_cnxt->temp_data, cur_data_pos, remaining_bytes);

	nand_cnxt->cur_page_data_len = remaining_bytes;

	return 0;
}

#ifdef CONFIG_QCA_SPI
/* Init function for SPI NOR flash writing. It erases the required sectors */
int init_crashdump_spi_flash_write(void *cnxt,
			loff_t offset,
			unsigned int total_size)
{
	int ret;
	unsigned int required_erase_size;
	struct crashdump_flash_spi_cxt *spi_flash_cnxt = cnxt;

	spi_flash_cnxt->start_crashdump_offset = offset;
	spi_flash_cnxt->cur_crashdump_offset = offset;

	if (total_size & (sfi->flash_block_size - 1))
		required_erase_size = (total_size &
					~(sfi->flash_block_size - 1)) +
					sfi->flash_block_size;
	else
		required_erase_size = total_size;

	ret = spi_flash_erase(crashdump_spi_flash,
				offset,
				required_erase_size);

	return ret;
}

/* Write function for SPI NOR flash */
int crashdump_spi_flash_write_data(void *cnxt,
		unsigned char *data, unsigned int size)
{
	struct crashdump_flash_spi_cxt *spi_flash_cnxt = cnxt;
	unsigned int cur_size = size;
	int ret;

	ret = spi_flash_write(crashdump_spi_flash,
			spi_flash_cnxt->cur_crashdump_offset,
			cur_size, data);

	if (!ret)
		spi_flash_cnxt->cur_crashdump_offset += cur_size;

	return ret;
}

/* Deinit function for SPI NOR flash writing. */
int deinit_crashdump_spi_flash_write(void *cnxt)
{
	return 0;
}
#endif

#ifdef CONFIG_QCA_MMC
/* Init function for EMMC. It initialzes the EMMC */
static int crashdump_init_mmc(struct mmc *mmc)
{
	int ret;

	if (!mmc) {
		puts("No MMC card found\n");
		return -EINVAL;
	}

	ret = mmc_init(mmc);

	if (ret)
		puts("MMC init failed\n");

	return ret;
}

/*
* Init function for EMMC flash writing. It initialzes its
* own context and EMMC
*/
int init_crashdump_emmc_flash_write(void *cnxt, loff_t offset,
						unsigned int total_size)
{
	struct crashdump_flash_emmc_cxt *emmc_cnxt = cnxt;

	emmc_cnxt->start_crashdump_offset = offset;
	emmc_cnxt->cur_crashdump_offset = offset;
	emmc_cnxt->cur_blk_data_len = 0;
	emmc_cnxt->write_size =  mmc->write_bl_len;

	if (mmc->write_bl_len > MAX_EMMC_BLK_LEN) {
		printf("mmc block length is more than configured size\n");
		return -ENOMEM;
	}

	return 0;
}

/*
* Deinit function for EMMC flash writing. It writes the remaining data
* stored in temp buffer to EMMC
*/
int deinit_crashdump_emmc_flash_write(void *cnxt)
{
	struct crashdump_flash_emmc_cxt *emmc_cnxt = cnxt;
	unsigned int cur_blk_write_len = emmc_cnxt->cur_blk_data_len;
	int ret_val = 0;
	int n;
	int remaining_bytes = emmc_cnxt->write_size -
			emmc_cnxt->cur_blk_data_len;

	if (cur_blk_write_len) {
		/*
		* Make the write data in multiple of block length size
		* and write remaining data in emmc
		*/
		memset(emmc_cnxt->temp_data + emmc_cnxt->cur_blk_data_len,
			0xFF, remaining_bytes);

		cur_blk_write_len = emmc_cnxt->write_size;
		n = mmc->block_dev.block_write(CONFIG_SYS_MMC_CRASHDUMP_DEV,
						emmc_cnxt->cur_crashdump_offset,
						1,
						(u_char *)emmc_cnxt->temp_data);

		ret_val = (n == 1) ? 0 : -ENOMEM;
	}

	return ret_val;
}

/*
* Write function for EMMC flash. EMMC writing works on block basis so
* this function writes the data in mulitple of block length and stores
* remaining data in temp buffer. This temp buffer data will be appended
* with next write data.
*/
int crashdump_emmc_flash_write_data(void *cnxt,
		unsigned char *data, unsigned int size)
{
	struct crashdump_flash_emmc_cxt *emmc_cnxt = cnxt;
	unsigned char *cur_data_pos = data;
	unsigned int remaining_bytes;
	unsigned int total_bytes;
	unsigned int cur_emmc_write_len;
	unsigned int cur_emmc_blk_len;
	unsigned int remaining_len_cur_page;
	int ret_val;
	int n;

	remaining_bytes = total_bytes = emmc_cnxt->cur_blk_data_len + size;

	/*
	* Check for block size and store the data in temp buffer if
	* the total size is less than it
	*/
	if (total_bytes < emmc_cnxt->write_size) {
		memcpy(emmc_cnxt->temp_data + emmc_cnxt->cur_blk_data_len,
				data, size);
		emmc_cnxt->cur_blk_data_len += size;

		return 0;
	}

	/*
	* Append the remaining length of data for complete emmc block write in
	* currently stored data and do the block write
	*/
	remaining_len_cur_page = emmc_cnxt->write_size -
			emmc_cnxt->cur_blk_data_len;
	cur_emmc_write_len = emmc_cnxt->write_size;

	memcpy(emmc_cnxt->temp_data + emmc_cnxt->cur_blk_data_len, data,
			remaining_len_cur_page);

	n = mmc->block_dev.block_write(CONFIG_SYS_MMC_CRASHDUMP_DEV,
					emmc_cnxt->cur_crashdump_offset,
					1,
					(u_char *)emmc_cnxt->temp_data);

	ret_val = (n == 1) ? 0 : -ENOMEM;

	if (ret_val)
		return ret_val;

	cur_data_pos += remaining_len_cur_page;
	emmc_cnxt->cur_crashdump_offset += 1;
	/*
	* Calculate the write length in multiple of block length and do the
	* emmc block write for same length
	*/
	cur_emmc_blk_len = ((data + size - cur_data_pos) /
				emmc_cnxt->write_size);
	cur_emmc_write_len = cur_emmc_blk_len * emmc_cnxt->write_size;

	if (cur_emmc_write_len > 0) {
		n = mmc->block_dev.block_write(CONFIG_SYS_MMC_CRASHDUMP_DEV,
						emmc_cnxt->cur_crashdump_offset,
						cur_emmc_blk_len,
						(u_char *)cur_data_pos);

		ret_val = (n == cur_emmc_blk_len) ? 0 : -1;

		if (ret_val)
			return ret_val;
	}

	cur_data_pos += cur_emmc_write_len;
	emmc_cnxt->cur_crashdump_offset += cur_emmc_blk_len;

	/* Store the remaining data in temp data */
	remaining_bytes = data + size - cur_data_pos;

	memcpy(emmc_cnxt->temp_data, cur_data_pos, remaining_bytes);

	emmc_cnxt->cur_blk_data_len = remaining_bytes;

	return 0;
}
#endif

/*
* This function writes the crashdump data in flash memory.
* It has function pointers for init, deinit and writing. These
* function pointers are being initialized with respective flash
* memory writing routines.
*/
static int qca_wdt_write_crashdump_data(
		struct qca_wdt_crashdump_data *crashdump_data,
		int flash_type, loff_t crashdump_offset)
{
	int ret = 0;
	void *crashdump_cnxt;
	int (*crashdump_flash_write)(void *cnxt, unsigned char *data,
					unsigned int size);
	int (*crashdump_flash_write_init)(void *cnxt, loff_t offset,
					unsigned int total_size);
	int (*crashdump_flash_write_deinit)(void *cnxt);
	unsigned int required_size;

	/*
	* Determine the flash type and initialize function pointer for flash
	* operations and its context which needs to be passed to these functions
	*/
	if (flash_type == SMEM_BOOT_NAND_FLASH) {
		crashdump_cnxt = (void *)&crashdump_nand_cnxt;
		crashdump_flash_write_init = init_crashdump_nand_flash_write;
		crashdump_flash_write = crashdump_nand_flash_write_data;
		crashdump_flash_write_deinit =
			deinit_crashdump_nand_flash_write;
#ifdef CONFIG_QCA_SPI
	} else if (flash_type == SMEM_BOOT_SPI_FLASH) {
		if (!crashdump_spi_flash) {
			crashdump_spi_flash = spi_flash_probe(sfi->flash_index,
				sfi->flash_chip_select,
				CONFIG_CRASHDUMP_SPI_SPEED,
				CONFIG_CRASHDUMP_SPI_MODE);

			if (!crashdump_spi_flash) {
				printf("spi_flash_probe() failed");
				return -EIO;
			}
		}

		crashdump_cnxt = (void *)&crashdump_flash_spi_cnxt;
		crashdump_flash_write = crashdump_spi_flash_write_data;
		crashdump_flash_write_init = init_crashdump_spi_flash_write;
		crashdump_flash_write_deinit =
			deinit_crashdump_spi_flash_write;
#endif
#ifdef CONFIG_QCA_MMC
	} else if (flash_type == SMEM_BOOT_MMC_FLASH) {
		mmc = find_mmc_device(CONFIG_SYS_MMC_CRASHDUMP_DEV);

		ret = crashdump_init_mmc(mmc);

		if (ret)
			return ret;

		crashdump_cnxt = (void *)&crashdump_emmc_cnxt;
		crashdump_flash_write_init = init_crashdump_emmc_flash_write;
		crashdump_flash_write = crashdump_emmc_flash_write_data;
		crashdump_flash_write_deinit =
			deinit_crashdump_emmc_flash_write;
#endif
	} else {
		return -EINVAL;
	}

	/* Start writing cpu context and uname in flash */
	required_size = CONFIG_CPU_CONTEXT_DUMP_SIZE +
				crashdump_data->uname_length;

	ret = crashdump_flash_write_init(crashdump_cnxt,
			crashdump_offset,
			required_size);

	if (ret)
		return ret;

	ret = crashdump_flash_write(crashdump_cnxt,
			crashdump_data->cpu_context,
			CONFIG_CPU_CONTEXT_DUMP_SIZE);

	if (!ret)
		ret = crashdump_flash_write(crashdump_cnxt,
			crashdump_data->uname,
			crashdump_data->uname_length);

	if (!ret)
		ret = crashdump_flash_write_deinit(crashdump_cnxt);

	return ret;
}



/*
* Function for collecting the crashdump data in flash. It extracts the
* crashdump TLV(Type Length Value) data and CPU context information from
* page allocated by kernel for crashdump data collection. It determines
* the type of boot flash memory and writes all these crashdump information
* in provided offset in flash memory.
*/
int do_dumpqca_minimal_data(const char *offset)
{
	unsigned char *kernel_crashdump_address =
		(unsigned char *) CONFIG_QCA_KERNEL_CRASHDUMP_ADDRESS;
	int flash_type;
	int ret_val;
	loff_t crashdump_offset;


	if (sfi->flash_type == SMEM_BOOT_NAND_FLASH) {
		flash_type = SMEM_BOOT_NAND_FLASH;
	} else if (sfi->flash_type == SMEM_BOOT_SPI_FLASH) {
		flash_type = SMEM_BOOT_SPI_FLASH;
#ifdef CONFIG_QCA_MMC
	} else if (sfi->flash_type == SMEM_BOOT_MMC_FLASH) {
		flash_type = SMEM_BOOT_MMC_FLASH;
#endif
	} else {
		printf("command not supported for this flash memory\n");
		return -EINVAL;
	}

	ret_val = str2off(offset, &crashdump_offset);

	if (!ret_val)
		return -EINVAL;

	g_crashdump_data.cpu_context = kernel_crashdump_address;
	tlv_msg.msg_buffer = kernel_crashdump_address + TLV_BUF_OFFSET;
	tlv_msg.cur_msg_buffer_pos = tlv_msg.msg_buffer;
	tlv_msg.len = CONFIG_TLV_DUMP_SIZE;

	ret_val = qca_wdt_extract_crashdump_data(&tlv_msg, &g_crashdump_data);

	if (!ret_val) {
		if (getenv("dump_to_flash")) {
			ret_val = qca_wdt_write_crashdump_data(&g_crashdump_data,
					flash_type, crashdump_offset);
		} else {
			dump_func(MINIMAL_DUMP);
		}
	}

	if (ret_val) {
		printf("crashdump data writing in flash failure\n");
		return -EPERM;
	}

	printf("crashdump data writing in flash successful\n");

	return 0;
}
