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
#include <lib/console.h>
#include <lib/ptable.h>
#include <smem.h>
#include <baseband.h>
#include <platform/iomap.h>
#include <platform/clock.h>
#include <platform/timer.h>
#include <platform/gpio.h>
#include <platform/irqs.h>
#include <reg.h>
#include <gsbi.h>
#include <target.h>
#include <platform.h>
#include <uart_dm.h>
#include <crypto_hash.h>
#include <board.h>
#include <target/board.h>
#include <scm.h>
#include <mmc.h>
#include <mmc_sdhci.h>
#include <sdhci_msm.h>
#include <stdlib.h>
#include <mmc_wrapper.h>
#include <partition_parser.h>

#define APPS_DLOAD_MAGIC			0x10
#define CLEAR_MAGIC				0x0
#define SCM_CMD_TZ_CONFIG_HW_FOR_RAM_DUMP_ID 	0x9
#define SCM_CMD_TZ_FORCE_DLOAD_ID 		0x10

#define CE1_INSTANCE		1
#define CE_EE			0
#define CE_FIFO_SIZE		512
#define CE_READ_PIPE		3
#define CE_WRITE_PIPE		2
#define CE_READ_PIPE_LOCK_GRP	0
#define CE_WRITE_PIPE_LOCK_GRP	0
#define CE_ARRAY_SIZE		20
#define MSM_CE1_BAM_BASE	0x08E04000
#define MSM_CE1_BASE		0x08E3A000

extern struct mmc_card *get_mmc_card();

extern void dmb(void);

/* Setting this variable to different values defines the
 * behavior of CE engine:
 * platform_ce_type = CRYPTO_ENGINE_TYPE_NONE : No CE engine
 * platform_ce_type = CRYPTO_ENGINE_TYPE_SW : Software CE engine
 * platform_ce_type = CRYPTO_ENGINE_TYPE_HW : Hardware CE engine
 * Behavior is determined in the target code.
 */
static crypto_engine_type platform_ce_type = CRYPTO_ENGINE_TYPE_HW;

static void target_uart_init(void);
static void target_crypto_init_params();
#define DELAY 1

static void set_sdc_power_ctrl(void){}

static struct mmc_device *mmc_dev;

static uint32_t mmc_pwrctl_base[] =
	{ MSM_SDC1_BASE, MSM_SDC2_BASE };

static uint32_t mmc_sdhci_base[] =
	{ MSM_SDC1_SDHCI_BASE, MSM_SDC2_SDHCI_BASE };

static uint32_t  mmc_sdc_pwrctl_irq[] =
	{ SDCC1_PWRCTL_IRQ, SDCC2_PWRCTL_IRQ };

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
void target_sdc_init()
{
	struct mmc_config_data config;

	/* Set drive strength & pull ctrl values */
	set_sdc_power_ctrl();

	config.bus_width = DATA_BUS_WIDTH_8BIT;
	config.max_clk_rate = MMC_CLK_200MHZ;

	/* Try slot 1 */
	config.slot         = 1;
	config.sdhc_base    = mmc_sdhci_base[config.slot - 1];
	config.pwrctl_base  = mmc_pwrctl_base[config.slot - 1];
	config.pwr_irq      = mmc_sdc_pwrctl_irq[config.slot - 1];
	config.hs400_support = 0;
	config.hs200_support = 0;
	config.ddr_support = 0;

	if (!(mmc_dev = mmc_init(&config))) {
		dprintf(CRITICAL, "mmc init failed!");
		ASSERT(0);
	}
}

void *target_mmc_device()
{
	return (void *) mmc_dev;
}

void target_mmc_deinit()
{
	sdhci_mode_disable(&(mmc_dev->host));
}

void target_init(void)
{
	unsigned platform_id = board_platform_id();
	struct mmc_boot_host *mmc_host = get_mmc_host();
	struct mmc_card *mmc_card = get_mmc_card();

	dprintf(INFO, "target_init()\n");
	dprintf(INFO, "board platform id is 0x%x\n",  platform_id);
	dprintf(INFO, "board platform verson is 0x%x\n",  board_platform_ver());

	target_sdc_init();
	if (partition_read_table(mmc_host, (struct mmc_boot_card *)mmc_card))
	{
		dprintf(CRITICAL, "Error reading the partition table info\n");
		ASSERT(0);
	}
	target_crypto_init_params();
}

unsigned board_machtype(void)
{
	return board_target_id();
}

crypto_engine_type board_ce_type(void)
{
	return platform_ce_type;
}

static void reset_crashdump(void)
{
        unsigned int magic_cookie = CLEAR_MAGIC;
        unsigned int clear_info[] =
                { 1 /* Disable wdog debug */, 0 /* SDI enable*/, };
        scm_call(SCM_SVC_BOOT, SCM_CMD_TZ_CONFIG_HW_FOR_RAM_DUMP_ID,
                (const void *)&clear_info, sizeof(clear_info), NULL, 0);
        scm_call(SCM_SVC_BOOT, SCM_CMD_TZ_FORCE_DLOAD_ID, &magic_cookie,
                        sizeof(magic_cookie), NULL, 0);
}

void reboot_device(unsigned reboot_reason)
{
	writel(reboot_reason, RESTART_REASON_ADDR);

	reset_crashdump();
	writel(0, GCNT_PSHOLD);
	mdelay(10000);

	dprintf(CRITICAL, "Rebooting failed\n");
}

unsigned check_reboot_mode(void)
{
	unsigned restart_reason = 0;
	volatile uint32_t val;

	/*
	 * The kernel did not shutdown properly in the previous boot.
	 * The SBLs would not have loaded QSEE firmware, proceeding with
	 * the boot is not possible. Reboot the system cleanly.
	 */
	 scm_call(SCM_SVC_BOOT, SCM_SVC_RD, NULL,
                        0, (void *)&val, sizeof(val));
	if (val == APPS_DLOAD_MAGIC) {

		val = 0x0;
                scm_call(SCM_SVC_BOOT, SCM_SVC_WR,
                        (void *)&val, sizeof(val), NULL, 0);
		dprintf(CRITICAL, "Apps Dload Magic set. Rebooting...\n");
		mdelay(10000);
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
	/* machid is already determined */
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

/* identify the usb controller to be used for the target */
const char * target_usb_controller()
{
	return "dwc";
}

void target_usb_phy_init(void)
{
}

void target_usb_phy_reset(void)
{
	uint32_t val;

	val = readl(GCC_USB_RST_CTRL_1);
	val |= 0x14;
	writel(val, GCC_USB_RST_CTRL_1);

	mdelay(10);

	val = readl(GCC_USB_RST_CTRL_1);
	val &= ~(0x14);
	writel(val, GCC_USB_RST_CTRL_1);
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

/* Initialize target specific USB handlers */
target_usb_iface_t *target_usb30_init()
{
	target_usb_iface_t *t_usb_iface;

	t_usb_iface = calloc(1, sizeof(target_usb_iface_t));
	ASSERT(t_usb_iface);

	t_usb_iface->phy_reset = target_usb_phy_reset;
	t_usb_iface->phy_init = target_usb_phy_init;
	t_usb_iface->clock_init = clock_usb30_init;
	t_usb_iface->vbus_override = 1;

	return t_usb_iface;
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

struct crypto_bam_pipes
{
	uint8_t read_pipe;
	uint8_t write_pipe;
	uint8_t read_pipe_grp;
	uint8_t write_pipe_grp;
};

struct crypto_init_params
{
	uint32_t                crypto_base;
	uint32_t                crypto_instance;
	uint32_t                bam_base;
	uint32_t                bam_ee;
	uint32_t                num_ce;
	uint32_t                read_fifo_size;
	uint32_t                write_fifo_size;
	uint8_t                 do_bam_init;
	struct crypto_bam_pipes pipes;
};

extern void crypto_init_params(struct crypto_init_params * params);

/* Set up params for h/w CE. */
static void target_crypto_init_params()
{
	struct crypto_init_params ce_params;

	/* Set up base addresses and instance. */
	ce_params.crypto_instance  = CE1_INSTANCE;
	ce_params.crypto_base      = MSM_CE1_BASE;
	ce_params.bam_base         = MSM_CE1_BAM_BASE;

	/* Set up BAM config. */
	ce_params.bam_ee               = CE_EE;
	ce_params.pipes.read_pipe      = CE_READ_PIPE;
	ce_params.pipes.write_pipe     = CE_WRITE_PIPE;
	ce_params.pipes.read_pipe_grp  = CE_READ_PIPE_LOCK_GRP;
	ce_params.pipes.write_pipe_grp = CE_WRITE_PIPE_LOCK_GRP;

	/* Assign buffer sizes. */
	ce_params.num_ce           = CE_ARRAY_SIZE;
	ce_params.read_fifo_size   = CE_FIFO_SIZE;
	ce_params.write_fifo_size  = CE_FIFO_SIZE;

	/* BAM is initialized by TZ for this platform.
	 * Do not do it again as the initialization address space
	 * is locked.
	 */
	ce_params.do_bam_init      = 1;

	crypto_init_params(&ce_params);
}

#define uarg(x)		(argv[x].u)
#define ullarg(x)	((unsigned long long)argv[x].u)

static int cmd_hash_find(int argc, const cmd_args *argv)
{
	unsigned msg_len, alg, i;
	unsigned char digest_buf[32]={0};
	unsigned char *msg_buf;

	msg_buf = (unsigned char*)uarg(1);
	msg_len = (unsigned)uarg(2);
	alg = (unsigned)uarg(3);

	hash_find(msg_buf, msg_len, digest_buf, alg);
	printf("\n");
	for(i=0; i<32; i++)
	{
		printf("%02x",digest_buf[i]);
	}
	printf("\n");

	return 0;
}

STATIC_COMMAND_START
        { "hash", "Find Hash", &cmd_hash_find },
STATIC_COMMAND_END(hash);
