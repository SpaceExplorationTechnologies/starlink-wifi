/*
 * Copyright (c) 2008, Google Inc.
 * All rights reserved.
 *
 * Copyright (c) 2009-2011, 2015 The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the 
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <debug.h>
#include <err.h>
#include <stdlib.h>
#include <dev/fbcon.h>
#include <splash.h>
#include <platform.h>
#include <string.h>
#include <partition_parser.h>
#include <msm_panel.h>

#include "font5x12.h"

#define SPLASH_PARTITION_NAME 		"splash_image"
#define SPLASH_HEADER_META_PADDING	14
#define BLOCKSIZE			512
#define NAME_LENGTH 			10

#define MMC_READ_ALIGN(a) ((((a) + (BLOCKSIZE-1)) & (~(BLOCKSIZE-1))))

struct single_spl_header {
	uint32_t width;
	uint32_t height;
	uint32_t padding[SPLASH_HEADER_META_PADDING];
};

struct pos {
	int x;
	int y;
};

static struct fbcon_config *config = NULL;

#define RGB565_BLACK		0x0000
#define RGB565_WHITE		0xffff

#define RGB888_BLACK            0x000000
#define RGB888_WHITE            0xffffff

#define FONT_WIDTH		5
#define FONT_HEIGHT		12

static uint16_t			BGCOLOR;
static uint16_t			FGCOLOR;

static struct pos		cur_pos;
static struct pos		max_pos;

static void fbcon_drawglyph(uint16_t *pixels, uint16_t paint, unsigned stride,
			    unsigned *glyph)
{
	unsigned x, y, data;
	stride -= FONT_WIDTH;

	data = glyph[0];
	for (y = 0; y < (FONT_HEIGHT / 2); ++y) {
		for (x = 0; x < FONT_WIDTH; ++x) {
			if (data & 1)
				*pixels = paint;
			data >>= 1;
			pixels++;
		}
		pixels += stride;
	}

	data = glyph[1];
	for (y = 0; y < (FONT_HEIGHT / 2); y++) {
		for (x = 0; x < FONT_WIDTH; x++) {
			if (data & 1)
				*pixels = paint;
			data >>= 1;
			pixels++;
		}
		pixels += stride;
	}
}

static void fbcon_flush(void)
{
	if (config->update_start)
		config->update_start();
	if (config->update_done)
		while (!config->update_done());
}

/* TODO: Take stride into account */
static void fbcon_scroll_up(void)
{
	unsigned short *dst = config->base;
	unsigned short *src = dst + (config->width * FONT_HEIGHT);
	unsigned count = config->width * (config->height - FONT_HEIGHT);

	while(count--) {
		*dst++ = *src++;
	}

	count = config->width * FONT_HEIGHT;
	while(count--) {
		*dst++ = BGCOLOR;
	}

	fbcon_flush();
}

/* TODO: take stride into account */
void fbcon_clear(void)
{
	unsigned count = config->width * config->height;
	memset(config->base, BGCOLOR, count * ((config->bpp) / 8));
}


static void fbcon_set_colors(unsigned bg, unsigned fg)
{
	BGCOLOR = bg;
	FGCOLOR = fg;
}

void fbcon_putc(char c)
{
	uint16_t *pixels;

	/* ignore anything that happens before fbcon is initialized */
	if (!config)
		return;

	if((unsigned char)c > 127)
		return;
	if((unsigned char)c < 32) {
		if(c == '\n')
			goto newline;
		else if (c == '\r')
			cur_pos.x = 0;
		return;
	}

	pixels = config->base;
	pixels += cur_pos.y * FONT_HEIGHT * config->width;
	pixels += cur_pos.x * (FONT_WIDTH + 1);
	fbcon_drawglyph(pixels, FGCOLOR, config->stride,
			font5x12 + (c - 32) * 2);

	cur_pos.x++;
	if (cur_pos.x < max_pos.x)
		return;

newline:
	cur_pos.y++;
	cur_pos.x = 0;
	if(cur_pos.y >= max_pos.y) {
		cur_pos.y = max_pos.y - 1;
		fbcon_scroll_up();
	} else
		fbcon_flush();
}

void fbcon_setup(struct fbcon_config *_config)
{
	uint32_t bg;
	uint32_t fg;

	ASSERT(_config);

	config = _config;

	switch (config->format) {
	case FB_FORMAT_RGB565:
		fg = RGB565_WHITE;
		bg = RGB565_BLACK;
		break;
        case FB_FORMAT_RGB888:
                fg = RGB888_WHITE;
                bg = RGB888_BLACK;
                break;
	default:
		dprintf(CRITICAL, "unknown framebuffer pixel format\n");
		ASSERT(0);
		break;
	}

	fbcon_set_colors(bg, fg);

	cur_pos.x = 0;
	cur_pos.y = 0;
	max_pos.x = config->width / (FONT_WIDTH+1);
	max_pos.y = (config->height - 1) / FONT_HEIGHT;
#if !DISPLAY_SPLASH_SCREEN
	fbcon_clear();
#endif
}

struct fbcon_config* fbcon_display(void)
{
    return config;
}

void display_image_on_screen(struct msm_panel_info *pinfo)
{
	unsigned i = 0;
	unsigned total_x;
	unsigned total_y;
	unsigned bytes_per_bpp;
	unsigned image_base;

#if EMMC_SPLASH_ENABLED
	uint64_t ptn = 0;
	uint64_t size;
	uint32_t index = INVALID_PTN;
	uint32_t imageReadSize, headerSize, disp_index;
	uint32_t spl_height, spl_width;
	uint32_t disp_count = 0;
	uint32_t disp_off = 0;
	uint8_t *spl_img_buf;
	void * tmp_fheader;
	struct single_spl_header* s_header;

	if (pinfo == NULL) {
		dprintf(CRITICAL, "ERROR: pinfo is NULL\n");
		return;
	}

	if (!config) {
		dprintf(CRITICAL,"ERROR: NULL config, image cannot be displayed\n");
		return;
	}

	index = partition_get_index(SPLASH_PARTITION_NAME);
	if (index < 0) {
		dprintf(CRITICAL, "ERROR: splash ptn index: %d not found\n", index);
		return;
	}

	ptn = partition_get_offset(index);
	if (ptn < 0) {
		dprintf(CRITICAL,"ERROR: splash ptn offset: %d not correct\n", ptn);
		return;
	}

	size = partition_get_size(index);

	switch (pinfo->type) {
		case LVDS_PANEL:
		case LCDC_PANEL:
			disp_index = 0;
			break;
		case HDMI_PANEL:
			disp_index = 1;
			break;
		case MIPI_VIDEO_PANEL:
		case MIPI_CMD_PANEL:
			disp_index = 2;
			break;
		default:
			dprintf(CRITICAL,"ERROR: pinfo->type not supported: %d\n",
								pinfo->type);
			return;
	}

	headerSize = BLOCKSIZE;
	tmp_fheader = malloc(headerSize);
	if (tmp_fheader == NULL) {
		dprintf(CRITICAL,"ERROR: spl image header buffer malloc failed\n");
		return;
	}
	mmc_read(ptn, tmp_fheader, headerSize);

	s_header = (struct single_spl_header*)
			(tmp_fheader + disp_index * sizeof(struct single_spl_header));

	spl_width = s_header->width;
	spl_height = s_header->height;

	if ((spl_width == 0) || (spl_height == 0))
		goto ret_error;

	if ((spl_width > config->width) || (spl_height > config->height)) {
		dprintf(CRITICAL,"ERROR: DispID %d size is invalid, width: %d, height: %d\n",
			disp_index ,spl_width, spl_height);
		goto ret_error;
	}

	fbcon_clear();
	total_x = config->width;
	total_y = config->height;
	bytes_per_bpp = ((config->bpp) / 8);

	if (disp_index > 0) {
		struct single_spl_header* tmp_header;
		for (i = 0; i < disp_index; i++) {
			tmp_header = (struct single_spl_header*)
				(tmp_fheader + i * sizeof(struct single_spl_header));
			disp_off += MMC_READ_ALIGN(tmp_header->width *
					tmp_header->height * bytes_per_bpp);
		}
	}

	imageReadSize = MMC_READ_ALIGN(spl_height * spl_width * bytes_per_bpp);
	if (imageReadSize > (size - headerSize)) {
		dprintf(CRITICAL,"ERROR: DispID: %d img_readsize:%d larger than partition\n",
			disp_index, imageReadSize);
		goto ret_error;
	}

	if ((spl_height == total_y) && (spl_width == total_x)) {
		mmc_read(ptn + headerSize + disp_off, config->base, imageReadSize);
	} else {
		image_base = ((((total_y/2) - (spl_height / 2)) *
			(config->width)) + (total_x/2 - (spl_width / 2)));

		spl_img_buf = malloc(imageReadSize);
		if (spl_img_buf == NULL) {
			dprintf(CRITICAL,"ERROR: spl image buffer malloc failed\n");
			goto ret_error;
		}
		mmc_read(ptn + headerSize + disp_off, spl_img_buf, imageReadSize);

		for (i = 0; i < spl_height; i++) {
			memcpy (
			config->base + ((image_base + (i * (config->width))) * bytes_per_bpp),
			spl_img_buf + (i * spl_width * bytes_per_bpp),
			spl_width * bytes_per_bpp);
		}
		free(spl_img_buf);
	}
	fbcon_flush();

ret_error:
	if (tmp_fheader != NULL)
		free(tmp_fheader);
	return;

#else
	if (!config) {
		dprintf(CRITICAL,"NULL configuration, image cannot be displayed\n");
		return;
	}

	fbcon_clear();

	total_x = config->width;
	total_y = config->height;
	bytes_per_bpp = ((config->bpp) / 8);
	image_base = ((((total_y/2) - (SPLASH_IMAGE_WIDTH / 2) - 1) *
		(config->width)) + (total_x/2 - (SPLASH_IMAGE_HEIGHT / 2)));

#if DISPLAY_TYPE_MIPI
	if (bytes_per_bpp == 3)
	{
		for (i = 0; i < SPLASH_IMAGE_WIDTH; i++)
		{
		     memcpy (config->base + ((image_base + (i * (config->width))) * bytes_per_bpp),
			imageBuffer_rgb888 + (i * SPLASH_IMAGE_HEIGHT * bytes_per_bpp),
			SPLASH_IMAGE_HEIGHT * bytes_per_bpp);
		}
	}
	fbcon_flush();
#if DISPLAY_MIPI_PANEL_NOVATEK_BLUE
	if(is_cmd_mode_enabled())
		mipi_dsi_cmd_mode_trigger();
#endif

#else
	if (bytes_per_bpp == 2)
	{
		for (i = 0; i < SPLASH_IMAGE_WIDTH; i++)
		{
		     memcpy (config->base + ((image_base + (i * (config->width))) * bytes_per_bpp),
			imageBuffer + (i * SPLASH_IMAGE_HEIGHT * bytes_per_bpp),
			SPLASH_IMAGE_HEIGHT * bytes_per_bpp);
		}
	}
	fbcon_flush();
#endif
#endif /* EMMC_SPLASH_ENABLED */
}
