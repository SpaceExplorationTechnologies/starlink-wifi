/* Copyright (c) 2010-2012, The Linux Foundation. All rights reserved.
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

#ifndef _PLATFORM_MSM_SHARED_MIPI_DSI_H_
#define _PLATFORM_MSM_SHARED_MIPI_DSI_H_

#include <msm_panel.h>

#define PASS                        0
#define FAIL                        1

#define DSI_CLKOUT_TIMING_CTRL                REG_DSI(0x0C0)
#define DSI_SOFT_RESET                        REG_DSI(0x114)
#define DSI_CAL_CTRL                          REG_DSI(0x0F4)

#define DSIPHY_SW_RESET                       REG_DSI(0x128)
#define DSIPHY_PLL_RDY                        REG_DSI(0x280)
#define DSIPHY_REGULATOR_CAL_PWR_CFG          REG_DSI(0x518)

#define DSI_CLK_CTRL                          REG_DSI(0x118)
#define DSI_TRIG_CTRL                         REG_DSI(0x080)
#define DSI_CTRL                              REG_DSI(0x000)
#define DSI_COMMAND_MODE_DMA_CTRL             REG_DSI(0x038)
#define DSI_COMMAND_MODE_MDP_CTRL             REG_DSI(0x03C)
#define DSI_COMMAND_MODE_MDP_DCS_CMD_CTRL     REG_DSI(0x040)
#define DSI_DMA_CMD_OFFSET                    REG_DSI(0x044)
#define DSI_DMA_CMD_LENGTH                    REG_DSI(0x048)
#define DSI_COMMAND_MODE_MDP_STREAM0_CTRL     REG_DSI(0x054)
#define DSI_COMMAND_MODE_MDP_STREAM0_TOTAL    REG_DSI(0x058)
#define DSI_COMMAND_MODE_MDP_STREAM1_CTRL     REG_DSI(0x05C)
#define DSI_COMMAND_MODE_MDP_STREAM1_TOTAL    REG_DSI(0x060)
#define DSI_ERR_INT_MASK0                     REG_DSI(0x108)
#define DSI_INT_CTRL                          REG_DSI(0x10C)

#define DSI_VIDEO_MODE_ACTIVE_H               REG_DSI(0x020)
#define DSI_VIDEO_MODE_ACTIVE_V               REG_DSI(0x024)
#define DSI_VIDEO_MODE_TOTAL                  REG_DSI(0x028)
#define DSI_VIDEO_MODE_HSYNC                  REG_DSI(0x02C)
#define DSI_VIDEO_MODE_VSYNC                  REG_DSI(0x030)
#define DSI_VIDEO_MODE_VSYNC_VPOS             REG_DSI(0x034)

#define DSI_MISR_CMD_CTRL                     REG_DSI(0x09C)
#define DSI_MISR_VIDEO_CTRL                   REG_DSI(0x0A0)
#define DSI_EOT_PACKET_CTRL                   REG_DSI(0x0C8)
#define DSI_VIDEO_MODE_CTRL                   REG_DSI(0x00C)
#define DSI_CAL_STRENGTH_CTRL                 REG_DSI(0x100)
#define DSI_CMD_MODE_DMA_SW_TRIGGER           REG_DSI(0x08C)
#define DSI_CMD_MODE_MDP_SW_TRIGGER           REG_DSI(0x090)

#define DSI_LANE_CTRL                         REG_DSI(0x0A8)

#define MIPI_DSI_MRPS       0x04	/* Maximum Return Packet Size */
#define MIPI_DSI_REG_LEN    16	/* 4 x 4 bytes register */

#define DTYPE_GEN_WRITE2 0x23	/* 4th Byte is 0x80 */
#define DTYPE_GEN_LWRITE 0x29	/* 4th Byte is 0xc0 */
#define DTYPE_DCS_WRITE1 0x15	/* 4th Byte is 0x80 */

//BEGINNING OF Tochiba Config- video mode

static const unsigned char toshiba_panel_mcap_off[8] = {
	0x02, 0x00, 0x29, 0xc0,
	0xb2, 0x00, 0xff, 0xff
};

static const unsigned char toshiba_panel_ena_test_reg[8] = {
	0x03, 0x00, 0x29, 0xc0,
	0xEF, 0x01, 0x01, 0xff
};

static const unsigned char toshiba_panel_ena_test_reg_wvga[8] = {
	0x03, 0x00, 0x29, 0xc0,
	0xEF, 0x01, 0x01, 0xff
};

static const unsigned char toshiba_panel_num_of_2lane[8] = {
	0x03, 0x00, 0x29, 0xc0,	// 63:2lane
	0xEF, 0x60, 0x63, 0xff
};

static const unsigned char toshiba_panel_num_of_1lane[8] = {
	0x03, 0x00, 0x29, 0xc0,	// 62:1lane
	0xEF, 0x60, 0x62, 0xff
};

static const unsigned char toshiba_panel_non_burst_sync_pulse[8] = {
	0x03, 0x00, 0x29, 0xc0,
	0xef, 0x61, 0x09, 0xff
};

static const unsigned char toshiba_panel_set_DMODE_WQVGA[8] = {
	0x02, 0x00, 0x29, 0xc0,
	0xB3, 0x01, 0xFF, 0xff
};

static const unsigned char toshiba_panel_set_DMODE_WVGA[8] = {
	0x02, 0x00, 0x29, 0xc0,
	0xB3, 0x00, 0xFF, 0xff
};

static const unsigned char toshiba_panel_set_intern_WR_clk1_wvga[8]
    = {

	0x03, 0x00, 0x29, 0xC0,	// 1 last packet
	0xef, 0x2f, 0xcc, 0xff,
};

static const unsigned char toshiba_panel_set_intern_WR_clk2_wvga[8]
    = {

	0x03, 0x00, 0x29, 0xC0,	// 1 last packet
	0xef, 0x6e, 0xdd, 0xff,
};

static const unsigned char
 toshiba_panel_set_intern_WR_clk1_wqvga[8] = {

	0x03, 0x00, 0x29, 0xC0,	// 1 last packet
	0xef, 0x2f, 0x22, 0xff,
};

static const unsigned char
 toshiba_panel_set_intern_WR_clk2_wqvga[8] = {

	0x03, 0x00, 0x29, 0xC0,	// 1 last packet
	0xef, 0x6e, 0x33, 0xff,
};

static const unsigned char toshiba_panel_set_hor_addr_2A_wvga[12] = {

	0x05, 0x00, 0x39, 0xC0,	// 1 last packet
	// 0x2A, 0x00, 0x08, 0x00,//100 = 64h
	// 0x6b, 0xFF, 0xFF, 0xFF,
	0x2A, 0x00, 0x00, 0x01,	// 0X1DF = 480-1 0X13F = 320-1
	0xdf, 0xFF, 0xFF, 0xFF,
};

static const unsigned char toshiba_panel_set_hor_addr_2B_wvga[12] = {

	0x05, 0x00, 0x39, 0xC0,	// 1 last packet
	// 0x2B, 0x00, 0x08, 0x00,//0X355 = 854-1; 0X1DF = 480-1
	// 0x6b, 0xFF, 0xFF, 0xFF,
	0x2B, 0x00, 0x00, 0x03,	// 0X355 = 854-1; 0X1DF = 480-1
	0x55, 0xFF, 0xFF, 0xFF,
};

static const unsigned char toshiba_panel_set_hor_addr_2A_wqvga[12]
    = {

	0x05, 0x00, 0x39, 0xC0,	// 1 last packet
	0x2A, 0x00, 0x00, 0x00,	// 0XEF = 240-1
	0xef, 0xFF, 0xFF, 0xFF,
};

static const unsigned char toshiba_panel_set_hor_addr_2B_wqvga[12]
    = {

	0x05, 0x00, 0x39, 0xC0,	// 1 last packet
	0x2B, 0x00, 0x00, 0x01,	// 0X1aa = 427-1;
	0xaa, 0xFF, 0xFF, 0xFF,
};

static const unsigned char toshiba_panel_IFSEL[8] = {
	0x02, 0x00, 0x29, 0xc0,
	0x53, 0x01, 0xff, 0xff
};

static const unsigned char toshiba_panel_IFSEL_cmd_mode[8] = {
	0x02, 0x00, 0x29, 0xc0,
	0x53, 0x00, 0xff, 0xff
};

static const unsigned char toshiba_panel_exit_sleep[4] = {
	0x11, 0x00, 0x05, 0x80,	// 25 Reg 0x29 < Display On>; generic write 1
	// params
};

static const unsigned char toshiba_panel_display_on[4] = {
	// 0x29, 0x00, 0x05, 0x80,//25 Reg 0x29 < Display On>; generic write 1
	// params
	0x29, 0x00, 0x05, 0x80,	// 25 Reg 0x29 < Display On>; generic write 1
	// params
};

//color mode off
static const unsigned char dsi_display_config_color_mode_off[4] = {
	0x00, 0x00, 0x02, 0x80,
};

//color mode on
static const unsigned char dsi_display_config_color_mode_on[4] = {
	0x00, 0x00, 0x12, 0x80,
};

//the end OF Tochiba Config- video mode

/* Toshiba mdt61 panel cmds */
static const unsigned char toshiba_mdt61_mcap_start[4] = {
	0xB0, 0x04, DTYPE_GEN_WRITE2, 0x80,
};

static const unsigned char toshiba_mdt61_num_out_pixelform[8] = {
	0x03, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xB3, 0x00, 0x87, 0xFF
};

static const unsigned char toshiba_mdt61_dsi_ctrl[8] = {
	0x03, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xB6, 0x30, 0x83, 0xFF
};

static const unsigned char toshiba_mdt61_panel_driving[12] = {
	0x07, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xC0, 0x01, 0x00, 0x85,
	0x00, 0x00, 0x00, 0xFF
};

static const unsigned char toshiba_mdt61_dispV_timing[12] = {
	0x05, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xC1, 0x00, 0x10, 0x00,
	0x01, 0xFF, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_dispCtrl[8] = {
	0x03, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xC3, 0x00, 0x19, 0xFF
};

static const unsigned char toshiba_mdt61_test_mode_c4[4] = {
	0xC4, 0x03, DTYPE_GEN_WRITE2, 0x80,
};

static const unsigned char toshiba_mdt61_dispH_timing[20] = {
	0x0F, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xC5, 0x00, 0x01, 0x05,
	0x04, 0x5E, 0x00, 0x00,
	0x00, 0x00, 0x0B, 0x17,
	0x05, 0x00, 0x00, 0xFF
};

static const unsigned char toshiba_mdt61_test_mode_c6[4] = {
	0xC6, 0x00, DTYPE_GEN_WRITE2, 0x80,
};

static const unsigned char toshiba_mdt61_gamma_setA[20] = {
	0x0D, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xC8, 0x0A, 0x15, 0x18,
	0x1B, 0x1C, 0x0D, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_gamma_setB[20] = {
	0x0D, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xC9, 0x0D, 0x1D, 0x1F,
	0x1F, 0x1F, 0x10, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_gamma_setC[20] = {
	0x0D, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xCA, 0x1E, 0x1F, 0x1E,
	0x1D, 0x1D, 0x10, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_powerSet_ChrgPmp[12] = {
	0x05, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xD0, 0x02, 0x00, 0xA3,
	0xB8, 0xFF, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_testMode_d1[12] = {
	0x06, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xD1, 0x10, 0x14, 0x53,
	0x64, 0x00, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_powerSet_SrcAmp[8] = {
	0x03, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xD2, 0xB3, 0x00, 0xFF
};

static const unsigned char toshiba_mdt61_powerInt_PS[8] = {
	0x03, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xD3, 0x33, 0x03, 0xFF
};

static const unsigned char toshiba_mdt61_vreg[4] = {
	0xD5, 0x00, DTYPE_GEN_WRITE2, 0x80,
};

static const unsigned char toshiba_mdt61_test_mode_d6[4] = {
	0xD6, 0x01, DTYPE_GEN_WRITE2, 0x80,
};

static const unsigned char toshiba_mdt61_timingCtrl_d7[16] = {
	0x09, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xD7, 0x09, 0x00, 0x84,
	0x81, 0x61, 0xBC, 0xB5,
	0x05, 0xFF, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_timingCtrl_d8[12] = {
	0x07, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xD8, 0x04, 0x25, 0x90,
	0x4C, 0x92, 0x00, 0xFF
};

static const unsigned char toshiba_mdt61_timingCtrl_d9[8] = {
	0x04, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xD9, 0x5B, 0x7F, 0x05
};

static const unsigned char toshiba_mdt61_white_balance[12] = {
	0x06, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xCB, 0x00, 0x00, 0x00,
	0x1C, 0x00, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_vcs_settings[4] = {
	0xDD, 0x53, DTYPE_GEN_WRITE2, 0x80,
};

static const unsigned char toshiba_mdt61_vcom_dc_settings[4] = {
	0xDE, 0x43, DTYPE_GEN_WRITE2, 0x80,
};

static const unsigned char toshiba_mdt61_testMode_e3[12] = {
	0x05, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xE3, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_testMode_e4[12] = {
	0x06, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xE4, 0x00, 0x00, 0x22,
	0xAA, 0x00, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_testMode_e5[4] = {
	0xE5, 0x00, DTYPE_GEN_WRITE2, 0x80,
};

static const unsigned char toshiba_mdt61_testMode_fa[8] = {
	0x04, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xFA, 0x00, 0x00, 0x00
};

static const unsigned char toshiba_mdt61_testMode_fd[12] = {
	0x05, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xFD, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_testMode_fe[12] = {
	0x05, 0x00, DTYPE_GEN_LWRITE, 0xC0,
	0xFE, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xFF
};

static const unsigned char toshiba_mdt61_mcap_end[4] = {
	0xB0, 0x03, DTYPE_GEN_WRITE2, 0x80,
};

static const unsigned char toshiba_mdt61_set_add_mode[4] = {
	0x36, 0x00, DTYPE_DCS_WRITE1, 0x80,
};

static const unsigned char toshiba_mdt61_set_pixel_format[4] = {
	0x3A, 0x70, DTYPE_DCS_WRITE1, 0x80,
};

/* Done Toshiba MDT61 Panel Commands */
/* Toshiba MDT61 (R69320) End */

static const unsigned char dsi_display_exit_sleep[4] = {
	0x11, 0x00, 0x15, 0x80,
};

static const unsigned char dsi_display_display_on[4] = {
	0x29, 0x00, 0x15, 0x80,
};

#define MIPI_VIDEO_MODE	        1
#define MIPI_CMD_MODE           2

struct mipi_dsi_phy_ctrl {
	uint32_t regulator[5];
	uint32_t timing[12];
	uint32_t ctrl[4];
	uint32_t strength[4];
	uint32_t pll[21];
};

struct mipi_dsi_cmd {
	int size;
	char *payload;
};

struct mipi_dsi_panel_config {
	char mode;
	char num_of_lanes;
	char lane_swap;
	struct mipi_dsi_phy_ctrl *dsi_phy_config;
	struct mipi_dsi_cmd *panel_cmds;
	int num_of_panel_cmds;
};

enum {		/* mipi dsi panel */
	DSI_VIDEO_MODE,
	DSI_CMD_MODE,
};
#define DSI_NON_BURST_SYNCH_PULSE	0
#define DSI_NON_BURST_SYNCH_EVENT	1
#define DSI_BURST_MODE			2

#define DSI_RGB_SWAP_RGB	0
#define DSI_RGB_SWAP_RBG	1
#define DSI_RGB_SWAP_BGR	2
#define DSI_RGB_SWAP_BRG	3
#define DSI_RGB_SWAP_GRB	4
#define DSI_RGB_SWAP_GBR	5

#define DSI_VIDEO_DST_FORMAT_RGB565		0
#define DSI_VIDEO_DST_FORMAT_RGB666		1
#define DSI_VIDEO_DST_FORMAT_RGB666_LOOSE	2
#define DSI_VIDEO_DST_FORMAT_RGB888		3

#define DSI_CMD_DST_FORMAT_RGB111	0
#define DSI_CMD_DST_FORMAT_RGB332	3
#define DSI_CMD_DST_FORMAT_RGB444	4
#define DSI_CMD_DST_FORMAT_RGB565	6
#define DSI_CMD_DST_FORMAT_RGB666	7
#define DSI_CMD_DST_FORMAT_RGB888	8

#define DSI_CMD_TRIGGER_NONE		0x0	/* mdp trigger */
#define DSI_CMD_TRIGGER_TE		0x02
#define DSI_CMD_TRIGGER_SW		0x04
#define DSI_CMD_TRIGGER_SW_SEOF		0x05	/* cmd dma only */
#define DSI_CMD_TRIGGER_SW_TE		0x06

int mipi_config(struct msm_fb_panel_data *panel);
int mipi_dsi_video_mode_config(unsigned short disp_width,
		unsigned short disp_height,
		unsigned short img_width,
		unsigned short img_height,
		unsigned short hsync_porch0_fp,
		unsigned short hsync_porch0_bp,
		unsigned short vsync_porch0_fp,
		unsigned short vsync_porch0_bp,
		unsigned short hsync_width,
		unsigned short vsync_width,
		unsigned short dst_format,
		unsigned short traffic_mode,
		unsigned char lane_en,
		unsigned low_pwr_stop_mode,
		unsigned char eof_bllp_pwr,
		unsigned char interleav);
int mipi_dsi_on();
int mipi_dsi_off();
int mipi_cmd_trigger();
int mipi_dsi_cmds_tx(struct mipi_dsi_cmd *cmds, int count);
int mipi_dsi_cmds_rx(char **rp, int len);
#endif
