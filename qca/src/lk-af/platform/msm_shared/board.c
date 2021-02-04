/* Copyright (c) 2012, The Linux Foundation. All rights reserved.
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

#include <debug.h>
#include <board.h>
#include <smem.h>
#include <baseband.h>

static struct board_data board = {UNKNOWN,
	0,
	HW_PLATFORM_UNKNOWN,
	HW_PLATFORM_SUBTYPE_UNKNOWN,
	HW_PLATFORM_VERSION_UNKNOWN,
	LINUX_MACHTYPE_UNKNOWN,
	BASEBAND_MSM,
	{{0}},
	0};

/*
 * The HW platform revision is specified as qcom,board_id in the dts file
 *  which is <variant_id, subtype_id>
 * This function returns the variant_id. Currently the variant_id is defined
 * as HW_PLATFORM_MTP.
 */
static unsigned get_hw_platform_variant()
{
	return HW_PLATFORM_MTP;
}

/*
 * The platform subtype is specified as qcom,board_id in the dts file
 *  which is <variant_id, subtype_id>
 * This function returns the subtype_id. Currently the subtype_id is defined
 * as 0.
 * Modify here to read the subtype id accordingly.
 */
static unsigned get_hw_platform_subtype()
{
	return 0;
}

static void platform_detect()
{
	struct smem_board_info_v6 board_info_v6;
	struct smem_board_info_v7 board_info_v7;
	struct smem_board_info_v8 board_info_v8;
	unsigned int board_info_len = 0;
	unsigned ret = 0;
	unsigned format = 0;
	unsigned pmic_type = 0;
	uint8_t i;

	ret = smem_read_alloc_entry_offset(SMEM_BOARD_INFO_LOCATION,
						   &format, sizeof(format), 0);
	if (ret)
		return;

	if (format == 6)
	{
			board_info_len = sizeof(board_info_v6);

		ret = smem_read_alloc_entry(SMEM_BOARD_INFO_LOCATION,
				&board_info_v6,
				board_info_len);
		if (ret)
			return;

		board.platform = board_info_v6.board_info_v3.msm_id;
		board.platform_version = board_info_v6.board_info_v3.msm_version;
		board.platform_subtype = board_info_v6.platform_subtype;
	}
	else if (format == 7)
	{
		board_info_len = sizeof(board_info_v7);

		ret = smem_read_alloc_entry(SMEM_BOARD_INFO_LOCATION,
				&board_info_v7,
				board_info_len);
		if (ret)
			return;

		board.platform = board_info_v7.board_info_v3.msm_id;
		board.platform_version = board_info_v7.board_info_v3.msm_version;
		board.platform_subtype = board_info_v7.platform_subtype;
		board.pmic_info[0].pmic_type = board_info_v7.pmic_type;
		board.pmic_info[0].pmic_version = board_info_v7.pmic_version;
	}
	else if (format >= 8)
		{

			board_info_len = sizeof(board_info_v8);

			ret = smem_read_alloc_entry(SMEM_BOARD_INFO_LOCATION,
					&board_info_v8,
					board_info_len);
			if (ret)
				return;

			board.platform = board_info_v8.board_info_v3.msm_id;
			board.platform_version =
				board_info_v8.board_info_v3.msm_version;
			board.platform_hw =
				board_info_v8.board_info_v3.hw_platform;
			board.platform_subtype = board_info_v8.platform_subtype;

			/*
			 * fill in board.target with variant_id information
			 * bit no  |31  24 | 23   16 | 15   8  |7    0|
			 * board.target = |hw_platform| plat_hw_ver major  |
			 *		  plat_hw_ver minor  |subtype|
			 *
			 */
			board.target = (((board_info_v8.board_info_v3.hw_platform
					& 0xff) << 24) |
					(((board_info_v8.platform_version >> 16)
					& 0xff) << 16) |
					((board_info_v8.platform_version & 0xff)
					<< 8) |
					(board_info_v8.platform_subtype & 0xff));

			for (i = 0; i < SMEM_MAX_PMIC_DEVICES; i++) {
				board.pmic_info[i].pmic_type =
					board_info_v8.pmic_info[i].pmic_type;
				board.pmic_info[i].pmic_version =
					board_info_v8.pmic_info[i].pmic_version;

				/*
				 * fill in pimc_board_info with pmic type and
				 * pmic version information
				 * bit no  |31  24 | 23  16 | 15   8 |7  0|
				 * pimc_board_info = |Unused | Major version |
				 * Minor version|PMIC_MODEL|
				 *
				 */
				pmic_type =
					board_info_v8.pmic_info[i].pmic_type ==
					PMIC_IS_INVALID?
					0 : board_info_v8.pmic_info[i].pmic_type;

				board.pmic_info[i].pmic_target =
					(((board_info_v8.pmic_info[i].pmic_version >> 16)
					& 0xff) << 16) |
					((board_info_v8.pmic_info[i].pmic_version
					& 0xff) << 8) | (pmic_type & 0xff);
			}

			if (format == 0x9)
				board.foundry_id = board_info_v8.foundry_id;
	}
	else
	{
		dprintf(CRITICAL, "Unsupported board info format\n");
		ASSERT(0);
	}

	if (get_hw_platform_variant())
		 board.platform_hw = get_hw_platform_variant();
}

void board_init()
{
	platform_detect();
	target_detect(&board);
	target_baseband_detect(&board);
}

uint32_t board_platform_id(void)
{
	return board.platform;
}

uint32_t board_target_id()
{
	return board.target;
}

uint32_t board_baseband()
{
	return board.baseband;
}

uint32_t board_hardware_id()
{
	return board.platform_hw;
}

uint32_t board_subtype_id()
{
	return get_hw_platform_subtype();
}

uint32_t board_platform_ver()
{
	unsigned version;
	version = board.platform_version;
	return ((version & 0xffff0000) >> 16);
}
