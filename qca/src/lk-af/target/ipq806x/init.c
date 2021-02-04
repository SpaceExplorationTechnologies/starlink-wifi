/*
 * Copyright (c) 2009, Google Inc.
 * All rights reserved.
 * Copyright (c) 2009-2016, The Linux Foundation. All rights reserved.
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

#include <debug.h>
#include <stdlib.h>
#include <lib/ptable.h>
#include <smem.h>
#include <baseband.h>
#include <platform/iomap.h>
#include <mmc.h>
#include <platform/timer.h>
#include <platform/gpio.h>
#include <reg.h>
#include <i2c_qup.h>
#include <gsbi.h>
#include <target.h>
#include <platform.h>
#include <uart_dm.h>
#include <crypto_hash.h>
#include <board.h>
#include <target/board.h>
#include <scm.h>
#include <string.h>

#define APPS_DLOAD_MAGIC1	0xE47B337D
#define APPS_DLOAD_MAGIC2	0x0501CAB0

extern void dmb(void);
static struct qup_i2c_dev *dev = NULL;
static int i2c_qup_initialized;

/* Setting this variable to different values defines the
 * behavior of CE engine:
 * platform_ce_type = CRYPTO_ENGINE_TYPE_NONE : No CE engine
 * platform_ce_type = CRYPTO_ENGINE_TYPE_SW : Software CE engine
 * platform_ce_type = CRYPTO_ENGINE_TYPE_HW : Hardware CE engine
 * Behavior is determined in the target code.
 */
static crypto_engine_type platform_ce_type = CRYPTO_ENGINE_TYPE_HW;

static void target_uart_init(void);
#define DELAY 1

int target_is_emmc_boot(void)
{
	return 1;
}

void target_early_init(void)
{
	target_uart_init();
}

void shutdown_device(void)
{
	dprintf(CRITICAL, "Shutdown system.\n");

	reboot_device(0);

	dprintf(CRITICAL, "Shutdown failed.\n");
}

void ipq_nss_init(void)
{
	writel(0, GMAC_CORE_RESET(0));
	writel(0, GMACSEC_CORE_RESET(0));

	writel(0, GMAC_CORE_RESET(1));
	writel(0, GMACSEC_CORE_RESET(1));

	writel(0, GMAC_CORE_RESET(2));
	writel(0, GMACSEC_CORE_RESET(2));

	writel(0, GMAC_CORE_RESET(3));
	writel(0, GMACSEC_CORE_RESET(3));

	writel(0, GMAC_AHB_RESET);
}

uint8_t i2c_read_reg(uint8_t addr, uint8_t reg, uint8_t *val, unsigned short len)
{
	uint8_t ret = 0;
	unsigned char buf[2];

	buf[0] = (reg & 0xFF00) >> 8;
	buf[1] = (reg & 0xFF);

	if (dev) {
		struct i2c_msg rd_buf[] = {
			{addr, I2C_M_WR, 2, buf},
			{addr, I2C_M_RD, len, val}
		};

		int err = qup_i2c_xfer(dev, rd_buf, 2);
		if (err < 0) {
			dprintf(INFO, "Read reg %x failed\n", err);
			return err;
		}
	} else {
		dprintf(INFO, "eeprom_read_reg: qup_i2c_init() failed\n");
		return -1;
	}

	return ret;
}

void i2c_write_reg(uint8_t addr, uint8_t reg, uint8_t *val, unsigned short len)
{
	if (dev) {
		unsigned char *buf;

		buf = malloc(len + 2);
		if (!buf)
			return;

		buf[0] = (reg & 0xFF00) >> 8;
		buf[1] = (reg & 0xFF);
		memcpy(buf+2, val, len);
		struct i2c_msg msg_buf[] = {
			{addr, I2C_M_WR, len+2, buf},
		};

		int err = qup_i2c_xfer(dev, msg_buf, 1);
		if (err < 0) {
			dprintf(INFO, "Write reg %x failed\n", reg);
			free(buf);
			return;
		}
		free(buf);
	} else
		dprintf(INFO, "eeprom_write_reg: qup_i2c_init() failed\n");
}

void i2c_ipq806x_init(uint8_t gsbi_id)
{
	dev = qup_i2c_init(gsbi_id, 200000, 25600000);
	if(!dev) {
		dprintf(INFO, "ipq806x qup_i2c_init() failed\n");
		return;
	}
	i2c_qup_initialized = 1;
}

void target_init(void)
{
	unsigned char slot;
	unsigned platform_id = board_platform_id();
	gpio_func_data_t *gmac_gpio;
	unsigned int i;

	dprintf(INFO, "target_init()\n");
	dprintf(INFO, "board platform id is 0x%x\n",  platform_id);
	dprintf(INFO, "board platform verson is 0x%x\n",  board_platform_ver());

	ipq_nss_init();
	get_board_param(board_machtype());
	ipq_configure_gpio(gboard_param->gmac_gpio,
			gboard_param->gmac_gpio_count);
	ipq_athrs17_init();
	gmac_gpio = gboard_param->gmac_gpio;
	for (i=0; i < gboard_param->gmac_gpio_count; i++) {
		gpio_tlmm_config(gmac_gpio->gpio, 0, 0, GPIO_PULL_DOWN, 0, 0);
		gmac_gpio++;
	}

	/* Need to initialize before splash screen init if splash is being read from emmc*/
	/* Trying Slot 1 first */
	slot = 1;
	if (mmc_boot_main(slot, MSM_SDC1_BASE)) {
		dprintf(CRITICAL, "mmc init failed!");
		ASSERT(0);
	}
}

unsigned board_machtype(void)
{
	return board_target_id();
}

crypto_engine_type board_ce_type(void)
{
	return platform_ce_type;
}

void reboot_device(unsigned reboot_reason)
{
	writel(reboot_reason, RESTART_REASON_ADDR);

	writel(1, MSM_WDT0_RST);
	writel(0, MSM_WDT0_EN);
	writel(0x31F3, MSM_WDT0_BT);
	writel(3, MSM_WDT0_EN);
	dmb();
	writel(3, MSM_TCSR_BASE + TCSR_WDOG_CFG);
	mdelay(10000);

	dprintf(CRITICAL, "Rebooting failed\n");
}

unsigned check_reboot_mode(void)
{
	unsigned restart_reason = 0;

	/*
	 * The kernel did not shutdown properly in the previous boot.
	 * The SBLs would not have loaded RPM firmware, proceeding with
	 * the boot is not possible. Reboot the system cleanly.
	 */
	if ((readl(MSM_APPS_DLOAD_MAGIC1_ADDR) == APPS_DLOAD_MAGIC1) &&
	    (readl(MSM_APPS_DLOAD_MAGIC2_ADDR) == APPS_DLOAD_MAGIC2)) {
		dprintf(CRITICAL, "Apps Dload Magic set. Rebooting...\n");
		writel(0, MSM_APPS_DLOAD_MAGIC1_ADDR);
		writel(0, MSM_APPS_DLOAD_MAGIC2_ADDR);
		reboot_device(0);
	}

	/* Read reboot reason and scrub it */
	restart_reason = readl(RESTART_REASON_ADDR);
	writel(0x00, RESTART_REASON_ADDR);

	return restart_reason;
}

void target_serialno(unsigned char *buf)
{
	unsigned int serialno;
	if (target_is_emmc_boot()) {
		serialno = mmc_get_psn();
		snprintf((char *)buf, 13, "%x", serialno);
	}
}

/* Do any target specific intialization needed before entering fastboot mode */
void target_fastboot_init(void)
{
}

void target_uart_init(void)
{
	uart_cfg_t *uart;

	get_board_param(board_machtype());

	uart = gboard_param->console_uart_cfg;

	uart_dm_init(uart->base, uart->gsbi_base, uart->uart_dm_base);
}

/* Detect the target type */
void target_detect(struct board_data *board)
{
	struct smem_machid_info machid;
	unsigned ret;

	ret = smem_read_alloc_entry_offset(SMEM_MACHID_INFO_LOCATION,
						   &machid, sizeof(machid), 0);
	if (ret)
		return;

	board->target = machid.machid;
}

/* Detect the modem type */
void target_baseband_detect(struct board_data *board)
{
	board->baseband = -1;
}

unsigned target_baseband()
{
	return -1;
}

/* Returns 1 if target supports continuous splash screen. */
int target_cont_splash_screen()
{
	return 0;
}

/* Do target specific usb initialization */
void target_usb_init(void)
{
	int ret;
	/* Select USB 2.0 */
	ret = scm_call_atomic2(SCM_SVC_IO_ACCESS,SCM_IO_WRITE,
			TCSR_USB_CONTROLLER_TYPE_SEL, USB_CONT_TYPE_USB_20);
	if (ret) {
		dprintf(CRITICAL, "Failed to select USB controller type as USB2.0, scm call returned error (0x%x)\n", ret);
	}
}

void target_mmc_init(unsigned char slot, unsigned int base)
{
	get_board_param(board_machtype());
	ipq_configure_gpio(gboard_param->emmc_gpio,
                gboard_param->emmc_gpio_count);
}

int target_mmc_bus_width()
{
	return MMC_BOOT_BUS_WIDTH_8_BIT;
}

extern void hash_find(unsigned char *addr, unsigned int size,
		      unsigned char *digest, unsigned char auth_alg);
#define uarg(x)         (argv[x].u)
#define ullarg(x)       ((unsigned long long)argv[x].u)

#if WITH_LIB_CONSOLE

#include <lib/console.h>

static int cmd_hash_find(int argc, const cmd_args *argv);
static int cmd_i2c(int argc, const cmd_args *argv);

STATIC_COMMAND_START
	{ "i2c", "i2c probe/read/write commands", &cmd_i2c },
        { "hash", "Find Hash", &cmd_hash_find },
STATIC_COMMAND_END(i2c_hash);

static int cmd_hash_find(int argc, const cmd_args *argv)
{
	unsigned msg_len, alg, i;
	unsigned char digest_buf[32]={0};
	unsigned char *msg_buf;

	msg_buf = (unsigned char*)uarg(1);
	msg_len = (unsigned)uarg(2);
	alg = (unsigned)uarg(3);

	hash_find(msg_buf, msg_len, digest_buf,  alg);
	printf("\n");
	for(i=0; i<32; i++)
	{
		printf("%02x",digest_buf[i]);
	}
	printf("\n");

	return 0;
}

static int cmd_i2c(int argc, const cmd_args *argv)
{
	int err;

	if (strcmp(argv[1].str, "probe")) {
		if (argc < 5) {
			printf("not enough arguments\n");
usage:
			printf("%s read <ddr addr> <i2c address> <register> <reg_len>\n", argv[0].str);
			printf("%s write <ddr addr> <i2c address> <register> <reg_len>\n", argv[0].str);
			return -1;
		}
	}


	if (!strcmp(argv[1].str, "probe")) {
		unsigned int j;
		uint8_t val;

		if (!i2c_qup_initialized)
			i2c_ipq806x_init(GSBI_ID_2);

		for (j = 0; j < 128; j++) {
			if (i2c_read_reg(j, 0, &val, 1) == 0)
				printf(" %02X", j);
		}
		dprintf(INFO, "\n");
	} else if (!strcmp(argv[1].str, "read")) {
		unsigned *ptr = (unsigned *)argv[2].u;
		uint8_t i2c_address = argv[3].u;
		uint8_t reg = argv[4].u;
		unsigned int reg_len = argv[5].u;

		uint8_t *buf = NULL;

		memset(ptr, 0x0, reg_len);
		buf = malloc(reg_len);
		if (!buf)
			return -1;

		memset(buf, 0x0, reg_len);

		err = i2c_read_reg(i2c_address, reg, buf, reg_len);
		if (err) {
			dprintf(INFO, "error in read_reg %d\n", err);
		} else {
			memcpy(ptr, buf, reg_len);
		}
		free(buf);
		dprintf(INFO, "\n");
	} else if (!strcmp(argv[1].str, "write")) {
		unsigned *ptr = (unsigned *)argv[2].u;
		uint8_t i2c_address = argv[3].u;
		uint8_t reg = argv[4].u;
		unsigned int reg_len = argv[5].u;
		uint8_t *buf = NULL;

		if (reg_len > 32) {
			dprintf(INFO, "max write supported is 32\n");
			return -1;
		}
		buf = malloc(reg_len);
		if (!buf)
			return -1;

		memcpy(buf, ptr, reg_len);
		i2c_write_reg(i2c_address, reg, buf, reg_len);
		free(buf);
		dprintf(INFO, "\n");
	} else {
		dprintf(INFO, "unrecognized subcommand\n");
		goto usage;
	}

	return 0;
}
#endif
