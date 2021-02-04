/* Copyright (c) 2015, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of The Linux Foundation. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
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

#include <adv7533.h>
#include <dev/pm8921.h>
#include <debug.h>
#include <reg.h>
#include <i2c_qup.h>
#include <gsbi.h>
#include <platform/timer.h>

static struct qup_i2c_dev *dev;

static struct adv7533_i2c_reg_cfg setup_cfg[] = {
	{ADV7533_MAIN, 0xd6, 0x48, 5},		/* HPD overriden */
	{ADV7533_MAIN, 0x41, 0x10, 5},		/* HDMI normal */
	{ADV7533_CEC_DSI, 0x03, 0x89, 0},	/* HDMI enabled */
	{ADV7533_MAIN, 0x16, 0x20, 0},
	{ADV7533_MAIN, 0x9A, 0xE0, 0},
	{ADV7533_MAIN, 0xBA, 0x70, 0},
	{ADV7533_MAIN, 0xDE, 0x82, 0},
	{ADV7533_MAIN, 0xE4, 0xC0, 0},
	{ADV7533_MAIN, 0xE5, 0x80, 0},
	{ADV7533_CEC_DSI, 0x15, 0xD0, 0},
	{ADV7533_CEC_DSI, 0x17, 0xD0, 0},
	{ADV7533_CEC_DSI, 0x24, 0x20, 0},
	{ADV7533_CEC_DSI, 0x57, 0x11, 0},
	/* hdmi or dvi mode: hdmi */
	{ADV7533_MAIN, 0xAF, 0x06, 0},
	{ADV7533_MAIN, 0x40, 0x80, 0},
	{ADV7533_MAIN, 0x4C, 0x04, 0},
	{ADV7533_MAIN, 0x49, 0x02, 0},
	{ADV7533_MAIN, 0x0D, 1 << 6, 0},
	{ADV7533_CEC_DSI, 0x1C, 0x30, 0},
};

void apq8064_adv7533_on(void)
{
	struct pm8921_gpio pdb_pin = {
		.direction = PM_GPIO_DIR_OUT,
		.output_buffer = 0,
		.output_value = 0,
		.pull = PM_GPIO_PULL_NO,
		.vin_sel = 2,
		.out_strength = PM_GPIO_STRENGTH_HIGH,
		.function = PM_GPIO_FUNC_1,
		.inv_int_pol = 0,
	};
	int rc = pm8921_gpio_config(PM_GPIO(23),&pdb_pin);
	if (rc)
		dprintf(CRITICAL, "FAIL adv7533 pm8921_gpio_config(): rc=%d.\n", rc);
	/* this delay is recommended by HW specs for powering up */
	udelay(5);
}

static int adv7533_i2c_read(uint8_t addr, uint8_t reg, uint8_t *buf, uint8_t len)
{
	int err = 0;
	if (!dev || !buf) {
		dprintf(INFO, "mipi_dsi_i2c_read() failed, " \
			"dev(0x%08x) or buf(0x%08x) is NULL\n",
			dev, buf);
		return -1;
	} else {
		struct i2c_msg rd_buf[] = {
			{addr, I2C_M_WR, 1, &reg},
			{addr, I2C_M_RD, len, buf}
		};

		err = qup_i2c_xfer(dev, rd_buf, 2);
		if (err < 0) {
			dprintf(INFO, "Read reg %x failed\n", reg);
			return -1;
		}
		return 0;
	}

}

static int adv7533_i2c_read_byte(uint8_t addr, uint8_t reg, uint8_t *buf)
{
	return adv7533_i2c_read(addr, reg, buf, 1);
}

static int adv7533_i2c_write_byte(uint8_t addr, uint8_t reg, uint8_t val)
{
	int err = 0;
	if (dev) {
		unsigned char buf[2] = {reg, val};
		struct i2c_msg msg_buf[] = {
			{addr, I2C_M_WR, 2, buf},
		};

		err = qup_i2c_xfer(dev, msg_buf, 1);
		if (err < 0) {
			dprintf(INFO, "Write reg %x failed\n", reg);
			return -1;
		}
		return 0;
	} else {
		dprintf(INFO, "mipi_dsi_i2c_write_byte() failed\n");
		return -1;
	}
}


static int adv7533_read_device_rev(void)
{
	uint8_t rev = 0;
	int ret = 0;

	ret = adv7533_i2c_read_byte(ADV7533_MAIN,
		ADV7533_REG_CHIP_REVISION, &rev);

	if (!ret)
		dprintf(INFO, "adv7533 revision %x\n", rev);
	else
		dprintf(INFO, "adv7533 rev error\n");

	return ret;
}

static int adv7533_i2c_write_regs(struct adv7533_i2c_reg_cfg *cfg, int size)
{
	int ret = 0;
	int i;

	for (i = 0; i < size; i++) {
		ret = adv7533_i2c_write_byte(cfg[i].i2c_addr, cfg[i].reg,
			cfg[i].val);
		if (ret) {
			dprintf(INFO, "mipi_dsi reg writes failed\n");
			goto w_regs_fail;
		}
		if (cfg[i].sleep_in_us) {
			udelay(cfg[i].sleep_in_us);
		}
	}

w_regs_fail:
	return ret;
}

static int adv7533_config_common(void)
{
	return adv7533_i2c_write_regs(setup_cfg, ARRAY_SIZE(setup_cfg));
}

int adv7533_config_timing(struct msm_panel_info *pinfo)
{
	int ret = 0;

	if (pinfo != NULL) {
		uint32_t h_total = (pinfo->xres +
			pinfo->lcdc.h_back_porch  +
			pinfo->lcdc.h_pulse_width +
			pinfo->lcdc.h_front_porch);

		uint32_t v_total = (pinfo->yres +
			pinfo->lcdc.v_back_porch  +
			pinfo->lcdc.v_pulse_width +
			pinfo->lcdc.v_front_porch);

		uint32_t active_high =
		(pinfo->lcdc.is_sync_active_high == 0) ? 0x00 : 0x60;

		struct adv7533_i2c_reg_cfg tg_cfg[] = {
			/* hsync and vsync active low */ /*60 or 00*/
			{ADV7533_MAIN, 0x17, active_high, 0},
			/* h_width 0x672 1650*/
			{ADV7533_CEC_DSI, 0x28, ((h_total & 0xFF0) >> 4), 0},
			{ADV7533_CEC_DSI, 0x29, ((h_total & 0xF) << 4), 0},
			/* hsync_width 0x28 40*/
			{ADV7533_CEC_DSI, 0x2A,
				((pinfo->lcdc.h_pulse_width & 0xFF0) >> 4), 0},
			{ADV7533_CEC_DSI, 0x2B,
				((pinfo->lcdc.h_pulse_width & 0xF) << 4), 0},
			/* hfp 0x6e 110 */
			{ADV7533_CEC_DSI, 0x2C,
				((pinfo->lcdc.h_front_porch & 0xFF0) >> 4), 0},
			{ADV7533_CEC_DSI, 0x2D,
				((pinfo->lcdc.h_front_porch & 0xF) << 4), 0},
			/* hbp 0xdc 220 */
			{ADV7533_CEC_DSI, 0x2E,
				((pinfo->lcdc.h_back_porch & 0xFF0) >> 4), 0},
			{ADV7533_CEC_DSI, 0x2F,
				((pinfo->lcdc.h_back_porch & 0xF) << 4), 0},
			/* v_total 0x2ee 750 */
			{ADV7533_CEC_DSI, 0x30, ((v_total & 0xFF0) >> 4), 0},
			{ADV7533_CEC_DSI, 0x31, ((v_total & 0xF) << 4), 0},
			/* vsync_width 0x05 5*/
			{ADV7533_CEC_DSI, 0x32,
				((pinfo->lcdc.v_pulse_width & 0xFF0) >> 4), 0},
			{ADV7533_CEC_DSI, 0x33,
				((pinfo->lcdc.v_pulse_width & 0xF) << 4), 0},
			/* vfp 0x05 5 */
			{ADV7533_CEC_DSI, 0x34,
				((pinfo->lcdc.v_front_porch & 0xFF0) >> 4), 0},
			{ADV7533_CEC_DSI, 0x35,
				((pinfo->lcdc.v_front_porch & 0xF) << 4), 0},
			/* vbp 0x14 20 */
			{ADV7533_CEC_DSI, 0x36,
				((pinfo->lcdc.v_back_porch & 0xFF0) >> 4), 0},
			{ADV7533_CEC_DSI, 0x37,
				((pinfo->lcdc.v_back_porch & 0xF) << 4), 0},
			{ADV7533_CEC_DSI, 0x03, 0x09, 0},/* HDMI disabled */
			{ADV7533_CEC_DSI, 0x03, 0x89, 0},/* HDMI enabled */
		};

		ret = adv7533_config_common();
		if (ret) {
			dprintf(CRITICAL, "adv7533 config common failed\n");
			goto end;
		}

		ret = adv7533_i2c_write_regs(tg_cfg, ARRAY_SIZE(tg_cfg));
		if (ret)
			dprintf(CRITICAL, "adv7533 dsi i2c write regs failed\n");
	} else {
		dprintf(CRITICAL, "adv7533 pinfo is null\n");
		ret = -1;
	}

end:
	return ret;
}

void adv7533_dump_regs(void)
{
	uint8_t rd = 0;
	mipi_dsi_i2c_read_byte(ADV7533_CEC_DSI, 0x3A,&rd);
	dprintf(CRITICAL, "adv7533: [0x%x] [0x%x]\n", 0x3A, rd);

	mipi_dsi_i2c_read_byte(ADV7533_CEC_DSI, 0x3B,&rd);
	dprintf(CRITICAL, "adv7533: [0x%x] [0x%x]\n", 0x3B, rd);

	mipi_dsi_i2c_read_byte(ADV7533_CEC_DSI, 0x40,&rd);
	dprintf(CRITICAL, "adv7533: [0x%x] [0x%x]\n", 0x40, rd);
	mipi_dsi_i2c_read_byte(ADV7533_CEC_DSI, 0x03,&rd);
	dprintf(CRITICAL, "adv7533: [0x%x] [0x%x]\n", 0x03, rd);
	mipi_dsi_i2c_read_byte(ADV7533_CEC_DSI, 0x39,&rd);
	dprintf(CRITICAL, "adv7533: [0x%x] [0x%x]\n", 0x39, rd);
	mipi_dsi_i2c_read_byte(ADV7533_MAIN, 0x42,&rd);
	dprintf(CRITICAL, "adv7533: MAIN [0x%x] [0x%x]\n", 0x42, rd);

	mipi_dsi_i2c_read_byte(ADV7533_MAIN, 0x9E,&rd);
	dprintf(CRITICAL, "adv7533: MAIN [0x%x] [0x%x]\n", 0x9E, rd);
	mipi_dsi_i2c_read_byte(ADV7533_MAIN, 0x16,&rd);
	dprintf(CRITICAL, "adv7533: MAIN [0x%x] [0x%x]\n", 0x16, rd);
	mipi_dsi_i2c_read_byte(ADV7533_MAIN, 0x18,&rd);
	dprintf(CRITICAL, "adv7533: MAIN [0x%x] [0x%x]\n", 0x18, rd);
	mipi_dsi_i2c_read_byte(ADV7533_MAIN, 0xd5,&rd);
	dprintf(CRITICAL, "adv7533: MAIN [0x%x] [0x%x]\n", 0xd5, rd);
}

int adv7533_init(void)
{
	int ret = 0;
	dev = qup_i2c_init(GSBI_ID_3, 384000, 24000000);
	if(!dev) {
		dprintf(INFO, "adv7533 qup_i2c_init() failed\n");
		return -1;
	}

	pm8921_ldo_set_voltage(LDO_9, LDO_VOLTAGE_2_85V);
	pm8921_low_voltage_switch_enable(lvs_4);
	/* this delay is recommended by HW specs for powering up */
	udelay(5);

	return ret;
}

