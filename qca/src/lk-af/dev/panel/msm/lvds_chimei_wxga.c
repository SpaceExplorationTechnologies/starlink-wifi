/* Copyright (c) 2012-2015, The Linux Foundation. All rights reserved.
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
 *
 */

#include <stdint.h>
#include <msm_panel.h>
#include <err.h>
#include <target/board.h>

extern int fpdlink3_init(void);
extern int fpdlink3_config_slave(void);

int lvds_chimei_wxga_config(void *pdata)
{
	int target_id = board_target_id();

	if ((target_id == LINUX_MACHTYPE_8064_ADP_2)||
		(target_id == LINUX_MACHTYPE_8064_ADP_2_ES2) ||
		(target_id == LINUX_MACHTYPE_8064_ADP_2_ES2P5)) {
		fpdlink3_init();
	}

	return NO_ERROR;
}

int lvds_chimei_wxga_on()
{
	return NO_ERROR;
}

int lvds_chimei_wxga_off()
{
	return NO_ERROR;
}

void lvds_chimei_wxga_init(struct msm_panel_info *pinfo)
{
	if (MPLATFORM()) {
		pinfo->xres = 1280;
		pinfo->yres = 720;
		pinfo->type = LVDS_PANEL;
		pinfo->wait_cycle = 0;
		pinfo->bpp = 24;
		pinfo->clk_rate = 79400000;

		pinfo->lcdc.h_back_porch = 43;
		pinfo->lcdc.h_front_porch = 43;
		pinfo->lcdc.h_pulse_width = 32;
		pinfo->lcdc.v_back_porch = 8;
		pinfo->lcdc.v_front_porch = 3;
		pinfo->lcdc.v_pulse_width = 5;
		pinfo->lcdc.underflow_clr = 0xff;
		pinfo->lcdc.hsync_skew = 0;
		pinfo->lvds.channel_mode = LVDS_SINGLE_CHANNEL_MODE;

		/* Set border color, padding only for reducing active display region */
		pinfo->lcdc.border_clr = 0x0;
		pinfo->lcdc.xres_pad = 0;
		pinfo->lcdc.yres_pad = 0;

		pinfo->on = lvds_chimei_wxga_on;
		pinfo->off = lvds_chimei_wxga_off;
	} else {
		pinfo->xres = 1366;
		pinfo->yres = 768;
		pinfo->type = LVDS_PANEL;
		pinfo->wait_cycle = 0;
		pinfo->bpp = 24;
		pinfo->clk_rate = 74958000;

		pinfo->lcdc.h_back_porch = 0;
		pinfo->lcdc.h_front_porch = 164;
		pinfo->lcdc.h_pulse_width = 20;
		pinfo->lcdc.v_back_porch = 0;
		pinfo->lcdc.v_front_porch = 28;
		pinfo->lcdc.v_pulse_width = 10;
		pinfo->lcdc.underflow_clr = 0xff;
		pinfo->lcdc.hsync_skew = 0;
		pinfo->lvds.channel_mode = LVDS_SINGLE_CHANNEL_MODE;

		/* Set border color, padding only for reducing active display region */
		pinfo->lcdc.border_clr = 0x0;
		pinfo->lcdc.xres_pad = 0;
		pinfo->lcdc.yres_pad = 0;

		pinfo->lcdc.is_den_active_high = true;
		pinfo->lcdc.is_sync_active_high = true;

		pinfo->on = lvds_chimei_wxga_on;
		pinfo->off = lvds_chimei_wxga_off;
		pinfo->config = lvds_chimei_wxga_config;
	}
}
